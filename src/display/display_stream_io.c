// Module: display
// Topic: Stream I/O, file parsing, and cast member data loading
// Address range: 0x680f00d0 - 0x680f2670
// Functions (42):
//   display_getStreamRef
//   display_processStreamChunk
//   display_seekStreamPosition
//   display_checkStreamBounds
//   display_validateStreamHeader
//   display_loadFileBlock
//   display_writeEncryptedStream
//   display_formatStreamMessage
//   display_lookupHexChar
//   display_matchFormatType
//   display_findStreamEntry
//   display_readStreamRange
//   display_initStreamSecurity
//   display_createStreamConnection
//   display_releaseStreamRef
//   display_resetStreamFlag
//   display_getStreamGuid
//   display_loadCastDataEntry
//   display_readStream
//   display_writeCastMemberData
//   display_readScoreEntry
//   display_loadScoreCastMembers
//   display_serializeCastState
//   display_writeCastMemberStream
//   display_saveSpriteChannels
//   display_writeStreamString
//   display_checkStreamCapacity
//   display_validateStreamSize
//   display_getStreamState
//   display_readBlockHeader
//   display_readStreamBlock
//   display_copyStreamData
//   display_openRiffStream
//   display_readSignBlock
//   display_readFileListBlock
//   display_encodeStreamBlock
//   display_readFileBlock
//   display_encodeStreamData
//   display_readInfoBlock
//   display_readCertBlock
//   display_readStreamAttribs
//   display_writeStreamAttribs


// ============================================================
// Function: display_getStreamRef (FUN_680f00d0)
// Address: 680f00d0
// Size: 90 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_getStreamRef(int param_1)
{
  uint *in_EAX;
  int iVar1;
  int *unaff_ESI;
  uint local_8;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    if ((iVar1 == 0) && (iVar1 = (**(code **)(*unaff_ESI + 0x14))(), iVar1 == 0)) {
      *in_EAX = (((local_8 & 0xff) << 8 | local_8 >> 8 & 0xff) << 8 | local_8 >> 0x10 & 0xff) << 8 |
                local_8 >> 0x18;
      in_EAX = in_EAX + 1;
    }
  }
  return 0;
}



// ============================================================
// Function: display_processStreamChunk (FUN_680f0130)
// Address: 680f0130
// Size: 153 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_processStreamChunk(void)

{
  int iVar1;
  int *unaff_EBX;
  int *unaff_ESI;
  
  iVar1 = (**(code **)(*unaff_EBX + 0x20))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*unaff_ESI + 0xc))();
    while (iVar1 == 0) {
      iVar1 = (**(code **)(*unaff_ESI + 0x10))();
    }
    if (iVar1 == -0x7ffbfbb4) {
      iVar1 = (**(code **)(*unaff_ESI + 0x14))();
    }
    else {
      (**(code **)(*unaff_ESI + 0x18))();
    }
    if (iVar1 == -0x7ffbfbb3) {
      return -0x7ffbffec;
    }
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*unaff_EBX + 0x24))();
      return iVar1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_seekStreamPosition (FUN_680f01d0)
// Address: 680f01d0
// Size: 427 bytes
// Params: void * this, uint param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_seekStreamPosition(void *this,uint param_1)
{
  int iVar1;
  int *unaff_EDI;
  uint local_30;
  int *local_2c;
  char local_25;
  int local_24;
  int local_18;
  int local_14;
  uint local_8;
  
  local_2c = (int *)0x0;
  local_25 = '\0';
  iVar1 = display_getStreamRef(7);
  if ((((iVar1 != 0) || (local_24 != 0x1c)) ||
      (iVar1 = (**(code **)(*(int *)this + 0x20))(this,&local_30), iVar1 != 0)) ||
     (param_1 < local_30)) goto LAB_680f0358;
  if (local_18 < 1) {
LAB_680f029b:
    iVar1 = (**(code **)(*(int *)this + 0x20))(this,&local_30);
    if ((iVar1 == 0) && (local_30 <= param_1)) {
      if (0 < local_14) {
        if (local_25 != '\0') {
          (**(code **)(*local_2c + 0x10))(local_2c);
          (**(code **)(*local_2c + 8))(local_2c);
          local_25 = '\0';
        }
        iVar1 = (**(code **)(*unaff_EDI + 0x18))();
        if ((iVar1 != 0) || (iVar1 = (**(code **)(*local_2c + 0xc))(local_2c,0x8001,2), iVar1 != 0))
        goto LAB_680f0347;
        local_25 = '\x01';
        iVar1 = display_processStreamChunk();
        if (iVar1 != 0) goto LAB_680f034d;
      }
      (**(code **)(*(int *)this + 0x20))(this,&local_30);
    }
LAB_680f0347:
    if (local_25 == '\0') goto LAB_680f0358;
  }
  else {
    iVar1 = (**(code **)(*unaff_EDI + 0x18))();
    if ((iVar1 != 0) || (iVar1 = (**(code **)(*local_2c + 0xc))(local_2c,1,2), iVar1 != 0))
    goto LAB_680f0358;
    local_25 = '\x01';
    iVar1 = display_processStreamChunk();
    if (iVar1 == 0) goto LAB_680f029b;
  }
LAB_680f034d:
  (**(code **)(*local_2c + 0x10))(local_2c);
LAB_680f0358:
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
  return 0;
}



// ============================================================
// Function: display_checkStreamBounds (FUN_680f0380)
// Address: 680f0380
// Size: 101 bytes
// Params: int * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_checkStreamBounds(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int local_c;
  int *local_8;
  
  piVar1 = param_1;
  uVar2 = (**(code **)(*param_1 + 0x28))(param_1,&local_8);
  if (uVar2 == 0) {
    uVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,&param_1);
    if (uVar2 == 0) {
      if (local_8 <= param_1) {
        return 0;
      }
      uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,&local_c);
      if (uVar2 == 0) {
        uVar2 = -(uint)(param_1 < (int *)(*(int *)(param_2 + 4) + local_c)) & 0x800412e0;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: display_validateStreamHeader (FUN_680f03f0)
// Address: 680f03f0
// Size: 135 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_validateStreamHeader(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  piVar1 = param_1;
  iVar3 = (**(code **)(*param_1 + 0x20))(param_1,&param_1);
  if (iVar3 == 0) {
    if (((uint)param_1 & 1) != 0) {
      param_1 = (int *)((int)param_1 + 1);
      iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,param_1);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    iVar3 = (**(code **)(*piVar1 + 0x3c))(piVar1,&local_8);
    iVar2 = param_2;
    if (iVar3 == 0) {
      if (local_8 < param_1 + 2) {
        return -0x7ffbed20;
      }
      iVar3 = display_getStreamRef(2);
      if ((iVar3 == 0) && (param_3 < (uint)(*(int *)(iVar2 + 4) + 8 + (int)param_1))) {
        iVar3 = 0xd0;
      }
    }
  }
  return iVar3;
}



// ============================================================
// Function: display_loadFileBlock (FUN_680f0480)
// Address: 680f0480
// Size: 280 bytes
// Params: int * param_1, uint param_2, int * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_loadFileBlock(int *param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14 [2];
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  if ((param_1 == (int *)0x0) || (param_3 == (int *)0x0)) {
    return 0x80040004;
  }
  uVar1 = display_validateStreamHeader(param_1,(int)local_14,param_2);
  if (uVar1 == 0) {
    if (local_14[0] == FOURCC_FILE) {
      uVar1 = display_checkStreamBounds(param_1,(int)local_14);
      uVar2 = uVar1;
      if (((uVar1 != 0x800412e0) ||
          (uVar2 = (**(code **)(*param_1 + 0x34))(param_1,0xfffffff8,1), uVar2 != 0)) &&
         (uVar1 = uVar2, uVar1 == 0)) {
        iVar3 = (**(code **)(*param_3 + 0x40))(param_3);
        if (iVar3 == 0) {
          uVar1 = (**(code **)(*param_3 + 0x48))(param_3);
          if (uVar1 != 0) goto LAB_680f0571;
          local_c = 1;
        }
        else {
          iVar3 = (**(code **)(*param_3 + 0x3c))();
          if (iVar3 != 0) {
            uVar1 = 0x80040386;
            goto LAB_680f0571;
          }
        }
        uVar4 = Ordinal_1038(&DAT_68175dd8,&DAT_68175e08,&local_8);
        uVar1 = Ordinal_2063(uVar4);
        if (((uVar1 != 0) || (uVar1 = display_seekStreamPosition(param_1,param_2), uVar1 != 0)) && (local_c != 0))
        {
          (**(code **)(*param_3 + 0x50))(param_3);
        }
      }
    }
    else {
      uVar1 = 0xc9;
    }
  }
LAB_680f0571:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return uVar1;
}



// ============================================================
// Function: display_writeEncryptedStream (FUN_680f05a0)
// Address: 680f05a0
// Size: 474 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_writeEncryptedStream(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  local_8 = Ordinal_1126(0x1000,0);
  if (local_8 == 0) {
    iVar3 = 0x206;
  }
  else {
    Ordinal_1130(local_8,0x1000);
    iVar3 = display_getNetSecurityState(&local_c);
    if (((iVar3 == 0) && (iVar3 = display_loadFormatData(local_c,&LAB_680fc8b0,0), iVar3 == 0)) &&
       (iVar3 = display_freeNetSecurity(&local_10), iVar3 == 0)) {
      local_18 = param_4;
      local_14 = *(undefined4 *)(param_4 + 0x400);
      iVar3 = display_loadNetSecurityData(local_10,&LAB_680fc710,&local_18);
      if ((iVar3 == 0) && (iVar3 = xtra_initSecureFormat(local_c,local_10,&PTR_PTR_6818e7dc,0), iVar3 == 0))
      {
        iVar2 = 0;
        iVar3 = 0;
        do {
          iVar2 = iVar2 + 0x1000;
          if ((param_2 == (int *)0x0) || (iVar2 <= *param_2)) {
            iVar1 = Ordinal_1409(param_1,local_8,0x1000);
            if (iVar1 == 0) {
              iVar3 = Ordinal_1042();
            }
          }
          else {
            if ((*param_2 < 0x1000) && (param_2[1] < 0x1001)) {
              iVar1 = Ordinal_1409(param_1,local_8,param_2[1]);
              if (iVar1 == 0) {
                iVar3 = Ordinal_1042();
              }
              if ((iVar3 == 0) &&
                 (iVar1 = Ordinal_1409(param_1,*param_2 + -1 + local_8,0x1001 - *param_2),
                 iVar1 != 0)) {
                iVar3 = Ordinal_1042();
                param_2 = (int *)0x0;
                goto LAB_680f070b;
              }
            }
            else {
              iVar3 = 0x20c;
            }
            param_2 = (int *)0x0;
          }
LAB_680f070b:
          if (((iVar3 == 0) || (iVar3 == 0x68)) &&
             (iVar1 = display_dispatchCryptoOp(local_c,local_8,0x1000,0), iVar1 != 0)) {
            iVar3 = iVar1;
          }
        } while (iVar3 == 0);
        iVar3 = display_dispatchCryptoOpEx(local_c,param_3,*(undefined4 *)(param_3 + 0x400),0,0);
      }
    }
  }
  Ordinal_1127(&local_8);
  display_initNetworkSecurity(&local_c);
  display_releaseNetSecurity(&local_10);
  return iVar3;
}



// ============================================================
// Function: display_formatStreamMessage (FUN_680f0780)
// Address: 680f0780
// Size: 121 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_formatStreamMessage(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  undefined1 local_2c [36];
  uint local_8;
  
  if (param_2 == 0) {
    *unaff_ESI = param_1 + -0x7080;
    unaff_ESI[0x100] = 4;
  }
  else {
    Ordinal_1543(local_2c,param_1 + -0x7080,0);
    Ordinal_1256();
    piVar2 = unaff_ESI;
    do {
      iVar1 = *piVar2;
      piVar2 = (int *)((int)piVar2 + 1);
    } while ((char)iVar1 != '\0');
    unaff_ESI[0x100] = (int)piVar2 - (int)((int)unaff_ESI + 1);
  }
  unaff_ESI[0x101] = 1;
  return 0;
}



// ============================================================
// Function: display_lookupHexChar (FUN_680f0800)
// Address: 680f0800
// Size: 15 bytes
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 display_lookupHexChar(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x10) {
    return (&DAT_6818e810)[in_EAX];
  }
  return 0x3f;
}



// ============================================================
// Function: display_matchFormatType (FUN_680f0810)
// Address: 680f0810
// Size: 125 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_matchFormatType(void)

{
  uint uVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI[1] == 3) {
    uVar1 = display_decodeFormat((byte *)*unaff_ESI,&DAT_6818eb00,3);
    if (uVar1 == 0) {
      if (((unaff_EDI != 3) && (unaff_EDI != 4)) && (unaff_EDI != 2)) {
        return false;
      }
      return true;
    }
    if ((unaff_ESI[1] == 3) &&
       (uVar1 = display_decodeFormat((byte *)*unaff_ESI,&DAT_6818eb04,3), uVar1 == 0)) {
      if (unaff_EDI == 1) {
        return true;
      }
      if (unaff_EDI == 4) {
        return true;
      }
      return false;
    }
  }
  if ((unaff_ESI[1] == 9) && (uVar1 = display_decodeFormat((byte *)*unaff_ESI,&DAT_6818eb18,9), uVar1 == 0))
  {
    return unaff_EDI == 2;
  }
  return false;
}



// Function: display_findStreamEntry (FUN_680f0890)
// Address: 680f0890
// Size: 234 bytes
// Params: undefined4 * param_1, char * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_findStreamEntry(undefined4 *param_1,char *param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  undefined4 local_24;
  undefined4 local_20;
  char *local_1c;
  size_t local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = display_encryptBlock(&local_c,param_1,(undefined4 *)0x0);
  if (iVar1 == 0) {
    local_8 = 0;
    iVar1 = 0;
    if (local_c != 0) {
      do {
        uVar3 = local_8;
        iVar2 = display_decryptBlockEx(&local_24,&local_20,&local_10,&local_1c,&local_18,&local_14,param_1,
                             local_8,(undefined4 *)0x0);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = iVar1 + 1;
        if (((local_10 == 0x13) || (local_10 == 0x16)) || (local_10 == 0x14)) {
          if (in_EAX == 3) {
            bVar5 = SBORROW4(iVar2,3);
            bVar4 = iVar1 + -2 < 0;
LAB_680f0918:
            if (bVar5 != bVar4) goto LAB_680f0929;
          }
          else {
            if (in_EAX == 4) {
              bVar5 = SBORROW4(iVar2,4);
              bVar4 = iVar1 + -3 < 0;
              goto LAB_680f0918;
            }
            if (in_EAX == 2) {
              bVar5 = SBORROW4(iVar2,8);
              bVar4 = iVar1 + -7 < 0;
              goto LAB_680f0918;
            }
          }
          bVar4 = display_matchFormatType();
          uVar3 = local_8;
          if (CONCAT31(extraout_var,bVar4) != 0) {
            strncpy(param_2,local_1c,local_18);
            param_2[local_18] = '\0';
            *(size_t *)(param_2 + 0x400) = local_18;
            param_2[0x404] = '\x01';
            param_2[0x405] = '\0';
            param_2[0x406] = '\0';
            param_2[0x407] = '\0';
            return 0;
          }
        }
LAB_680f0929:
        local_8 = uVar3 + 1;
        iVar1 = iVar2;
      } while (local_8 < local_c);
    }
    iVar1 = 999;
  }
  return iVar1;
}



// ============================================================
// Function: display_readStreamRange (FUN_680f0980)
// Address: 680f0980
// Size: 530 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_readStreamRange(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  uint *puVar3;
  undefined1 *extraout_ECX;
  int extraout_ECX_00;
  uint *puVar4;
  int extraout_EDX;
  ushort local_54 [4];
  uint local_4c;
  uint local_48;
  undefined4 *local_44;
  int local_40;
  int local_3c;
  undefined4 *local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  param_3[0x101] = 0;
  if (param_1 == 0) {
    param_3 = (uint *)0x112;
    puVar3 = param_3;
    goto LAB_680f0b7d;
  }
  puVar3 = (uint *)display_resetFormatState((int *)&local_8);
  if (puVar3 != (uint *)0x0) goto LAB_680f0b7d;
  local_10 = Ordinal_1114(param_1);
  local_c = Ordinal_1116(param_1);
  puVar3 = (uint *)display_copyFormatData(local_8,&local_10,(undefined4 *)0x0);
  Ordinal_1115(param_1);
  if ((puVar3 != (uint *)0x0) ||
     (puVar3 = (uint *)display_initCryptoState((undefined4 *)local_54,local_8,(undefined4 *)0x0),
     puVar3 != (uint *)0x0)) goto LAB_680f0b7d;
  switch(param_2) {
  case 1:
  case 2:
    puVar3 = (uint *)display_findStreamEntry(local_38,(char *)param_3);
    break;
  case 3:
  case 4:
    puVar3 = (uint *)display_findStreamEntry(local_44,(char *)param_3);
    break;
  case 5:
  case 0xb:
    puVar3 = (uint *)display_formatStreamMessage(local_3c,(uint)(param_2 == 5));
    break;
  case 6:
    if (local_4c * 2 < 0x401) {
      puVar4 = param_3;
      if (local_4c != 0) {
        do {
          uVar2 = display_lookupHexChar();
          *extraout_ECX = uVar2;
          uVar2 = display_lookupHexChar();
          *(undefined1 *)(extraout_ECX_00 + 1) = uVar2;
          puVar4 = (uint *)(extraout_ECX_00 + 2);
        } while (extraout_EDX + 1U < local_4c);
      }
      *(undefined1 *)puVar4 = 0;
      puVar4 = param_3;
      do {
        uVar1 = *puVar4;
        puVar4 = (uint *)((int)puVar4 + 1);
      } while ((char)uVar1 != '\0');
      param_3[0x100] = (int)puVar4 - ((int)param_3 + 1);
      param_3[0x101] = 1;
      break;
    }
    goto LAB_680f0ae6;
  case 7:
    *param_3 = (uint)local_54[0];
    param_3[0x100] = 4;
    param_3[0x101] = 1;
    break;
  case 8:
    if (local_30 < 0x401) {
      Ordinal_1128(param_3,local_34,local_30);
      param_3[0x100] = local_30;
      param_3[0x101] = 1;
      break;
    }
LAB_680f0ae6:
    param_3 = (uint *)0x210;
    puVar3 = param_3;
    break;
  case 9:
    *param_3 = local_48;
    param_3[0x100] = 4;
    param_3[0x101] = 1;
    break;
  case 10:
  case 0xd:
    puVar3 = (uint *)display_formatStreamMessage(local_40,(uint)(param_2 == 0xd));
    break;
  case 0xc:
    param_3[0x100] = 0;
    param_3[0x101] = 1;
    break;
  default:
    param_3 = (uint *)0x3e7;
    puVar3 = param_3;
  }
LAB_680f0b7d:
  param_3 = puVar3;
  xtra_initCryptoContext((int *)&local_8);
  return (int)param_3;
}



// ============================================================
// Function: display_initStreamSecurity (FUN_680f0bd0)
// Address: 680f0bd0
// Size: 106 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_initStreamSecurity(int *param_1)

{
  int iVar1;
  int *unaff_EBX;
  int *unaff_EDI;
  
  *param_1 = 0;
  *unaff_EDI = 0;
  *unaff_EBX = 0;
  iVar1 = display_allocCertChain(unaff_EDI);
  if ((iVar1 == 0) &&
     (iVar1 = display_addCertChainData((undefined4 *)0x0,(undefined4 *)*unaff_EDI,&DAT_6818e820,0x61,
                           &DAT_6818e888,0xa2), iVar1 == 0)) {
    return 0;
  }
  display_releaseFormatData(param_1);
  display_releaseFormatData(unaff_EDI);
  display_releaseFormatData(unaff_EBX);
  return iVar1;
}



// ============================================================
// Function: display_createStreamConnection (FUN_680f0c40)
// Address: 680f0c40
// Size: 486 bytes
// Params: uint param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_createStreamConnection(uint param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 *local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_64 = 0;
  local_80 = 0;
  local_18 = 0;
  local_8 = 0;
  local_c = 0;
  local_48 = 0;
  local_10 = 0;
  local_1c = 0;
  local_14 = (undefined4 *)0x0;
  *param_2 = 0;
  iVar2 = Ordinal_1404(&local_10,param_1,1);
  if ((iVar2 == 0) || (iVar2 = Ordinal_1403(&local_1c,100), iVar2 == 0)) {
    iVar2 = Ordinal_1042();
  }
  else {
    display_initCryptoVtable(&local_64,local_10);
    display_initCryptoVtable(&local_80,local_1c);
    iVar2 = display_initContainerVtable(&local_48);
    if ((iVar2 == 0) && (iVar2 = display_initStreamSecurity(&local_18), iVar2 == 0)) {
      uVar3 = display_processPKCS7Envelope(&local_80,&local_8c,local_8,local_c,&local_88,&param_1,0,&local_84,0,0,
                           &local_64,0,local_18,&local_48,(undefined4 *)0x0,0);
      piVar1 = param_2;
      if ((uVar3 == 0) && (param_1 == 0x10)) {
        iVar2 = display_getListItemData((int)&local_48,0,param_2);
        if ((iVar2 == 0) && (iVar2 = display_resetFormatState((int *)&local_14), iVar2 == 0)) {
          local_24 = Ordinal_1114(*piVar1);
          local_20 = Ordinal_1116(*piVar1);
          iVar2 = display_copyFormatData(local_14,&local_24,(undefined4 *)0x0);
          Ordinal_1115(*piVar1);
        }
      }
      else {
        iVar2 = 0x144;
      }
    }
  }
  xtra_initCryptoContext((int *)&local_14);
  display_freeAllLists((int)&local_48);
  rendering_updateDisplay();
  rendering_updateDisplay();
  Ordinal_1407(&local_10);
  Ordinal_1407(&local_1c);
  display_releaseFormatData(&local_18);
  display_releaseFormatData(&local_8);
  display_releaseFormatData(&local_c);
  return iVar2;
}



// ============================================================
// Function: display_releaseStreamRef (FUN_680f0e30)
// Address: 680f0e30
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_releaseStreamRef(void)
{
  Ordinal_2066();
  return 0;
}



// ============================================================
// Function: display_resetStreamFlag (FUN_680f0e40)
// Address: 680f0e40
// Size: 30 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_resetStreamFlag(int param_1)
{
  if (*(int *)(param_1 + 0x4c) != 0) {
    Ordinal_37((int *)(param_1 + 0x4c),0xf,0,0);
  }
  return 0;
}



// ============================================================
// Function: display_getStreamGuid (FUN_680f0e60)
// Address: 680f0e60
// Size: 243 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_getStreamGuid(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    iVar1 = Ordinal_38(*(int *)(param_1 + 0x4c),0xf,param_2,0x10);
    if (iVar1 != 0) {
      iVar1 = Ordinal_2066(param_2,&DAT_68175b38);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_680f0eda;
    }
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
LAB_680f0eda:
  if (param_3 != 0) {
    xtra_generateUuid(&local_18,&local_1c);
    if (local_1c == 0) {
      iVar1 = rendering_getStateFlags(param_1);
      if (iVar1 != 0) {
        iVar1 = Ordinal_37((undefined4 *)(param_1 + 0x4c),0xf,&local_18,0x10);
        if (iVar1 != 0) {
          *param_2 = local_18;
          param_2[1] = local_14;
          param_2[2] = local_10;
          param_2[3] = local_c;
          return 0;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: display_loadCastDataEntry (FUN_680f0f60)
// Address: 680f0f60
// Size: 141 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_loadCastDataEntry(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  local_8 = cast_lookupDataEntry(*param_2,param_3,0);
  if (local_8 != 0) {
    iVar1 = Ordinal_1116(local_8);
    iVar1 = iVar1 - param_6;
    if (iVar1 != 0) {
      iVar2 = Ordinal_1114(local_8);
      if (param_5 == 0) {
        playback_updateSpriteChannelState(param_1,param_4,iVar2 + param_6,iVar1);
      }
      else {
        playback_renderSpriteEx(param_1,param_4,iVar2 + param_6,iVar1);
      }
      Ordinal_1115(local_8);
      cast_formatNumber(param_2,(short)param_3,local_8);
    }
  }
  Ordinal_1113(&local_8);
  return 0;
}



// ============================================================
// Function: display_readStream (FUN_680f0ff0)
// Address: 680f0ff0
// Size: 212 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_readStream(int param_1,int *param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int local_c;
  int local_8;
  
  bVar4 = false;
  local_8 = 0;
  local_c = 0;
  display_loadCastDataEntry(param_1,param_2,param_3,param_4,1,param_5);
  local_8 = cast_lookupDataEntry(*param_2,param_3,0);
  if (local_8 != 0) {
    iVar1 = Ordinal_1116(local_8);
    iVar2 = Ordinal_1114(local_8);
    if (0 < iVar1) {
      bVar4 = *(char *)(iVar1 + -1 + iVar2) == '\0';
    }
    local_c = playback_mapFont(0,iVar2,iVar1 - param_5,param_5);
    if (local_c != 0) {
      iVar1 = Ordinal_1114(local_c);
      iVar3 = Ordinal_1201(iVar1 + param_5);
      iVar3 = iVar3 + param_5;
      if (bVar4) {
        iVar3 = iVar3 + 1;
      }
      Ordinal_37(param_2,(short)param_3,iVar1,iVar3);
      if (iVar1 != 0) {
        Ordinal_1115(local_c);
        Ordinal_1113(&local_c);
      }
    }
    if (iVar2 != 0) {
      Ordinal_1115(local_8);
      Ordinal_1113(&local_8);
    }
  }
  return 0;
}



// ============================================================
// Function: display_writeCastMemberData (FUN_680f10d0)
// Address: 680f10d0
// Size: 226 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_writeCastMemberData(undefined4 param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *unaff_EBX;
  
  iVar2 = *unaff_EBX;
  piVar1 = unaff_EBX + 0x13;
  Ordinal_36(piVar1);
  iVar3 = cast_writeDataEntry(param_1,param_2,0);
  *piVar1 = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  unaff_EBX[4] = 0;
  uVar4 = rendering_getRawStateFlags((int)unaff_EBX);
  uVar4 = uVar4 & 0xc;
  if (uVar4 == 4) {
    unaff_EBX[4] = 3;
  }
  else if (uVar4 == 8) {
    unaff_EBX[4] = 2;
  }
  else {
    unaff_EBX[4] = (uint)(uVar4 == 0xc);
  }
  if ((uint)param_3[1] < 0x1100) {
    display_readStream(iVar2,piVar1,0,*param_3,0);
    display_readStream(iVar2,piVar1,1,*param_3,1);
    display_readStream(iVar2,piVar1,2,*param_3,1);
    display_readStream(iVar2,piVar1,3,*param_3,1);
    display_readStream(iVar2,piVar1,0x13,*param_3,0);
    display_readStream(iVar2,piVar1,0x14,*param_3,0);
  }
  rendering_getMemberType((int)unaff_EBX);
  return 1;
}



// ============================================================
// Function: display_readScoreEntry (FUN_680f11c0)
// Address: 680f11c0
// Size: 462 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_readScoreEntry(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5)
{
  char cVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
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
  
  *(int *)(param_2 + 0xc) = param_4;
  local_38 = 0;
  local_40 = 0;
  local_34 = 0;
  playback_readScoreChannelEntry(*(int *)(param_3 + 4),param_4,&local_44,&local_38);
  if (((local_38 == 0) || (local_40 = Ordinal_1439(local_38,local_44,0), local_40 == 0)) ||
     (iVar4 = Ordinal_1404(&local_34,local_40,1), iVar4 == 0)) goto LAB_680f12e3;
  Ordinal_1407(&local_38);
  if ((uint)param_5[1] < 0x500) {
    sVar3 = Ordinal_1412(local_34);
    local_3c = Ordinal_1414(local_34);
    if (0 < local_3c) {
      uVar5 = Ordinal_1433(local_34);
      iVar4 = Ordinal_1432(local_34,(int)sVar3,1);
      if ((iVar4 == 0) || (iVar4 = display_writeCastMemberData(local_34,local_3c,param_5), iVar4 == 0))
      goto LAB_680f12e3;
      iVar4 = Ordinal_1432(local_34,uVar5,0);
      goto LAB_680f12dd;
    }
LAB_680f1313:
    *(undefined4 *)(param_2 + 0x4c) = 0;
  }
  else {
    uVar5 = Ordinal_1414(local_34);
    *(undefined4 *)(param_2 + 8) = uVar5;
    local_3c = Ordinal_1414(local_34);
    Ordinal_1414(local_34);
    if (local_3c < 1) goto LAB_680f1313;
    iVar4 = display_writeCastMemberData(local_34,local_3c,param_5);
LAB_680f12dd:
    if (iVar4 == 0) goto LAB_680f12e3;
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if ((uint)param_5[1] < 0x500) {
    cVar1 = Ordinal_1410(local_34);
    *(int *)(param_2 + 8) = (int)cVar1;
    uVar2 = Ordinal_1410(local_34);
    *(undefined1 *)(param_2 + 0x2c) = uVar2;
  }
  local_20 = param_5[1];
  local_28 = 0x10;
  local_24 = local_34;
  local_30 = param_2;
  local_2c = param_1;
  rendering_initState(&local_30);
  Ordinal_1042();
LAB_680f12e3:
  Ordinal_1407(&local_38);
  Ordinal_1407(&local_34);
  Ordinal_1113(&local_40);
  return 0;
}



// ============================================================
// Function: display_loadScoreCastMembers (FUN_680f1390)
// Address: 680f1390
// Size: 850 bytes
// Params: int param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_loadScoreCastMembers(int param_1,int *param_2,int param_3,int *param_4)
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  uint local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  undefined4 local_ec;
  int local_d4;
  undefined local_48 [64];
  uint local_8;
  
  iVar6 = *param_2;
  local_104 = param_1;
  local_f8 = -0x7a;
  local_110 = 0;
  local_f4 = 0;
  local_108 = 0;
  local_10c = playback_openScore(param_3,FOURCC_CASx,param_2[0xf],&local_108,&local_110);
  if (local_110 == 0) {
    local_fc = Ordinal_1111(0,0);
    if (local_fc == 0) goto LAB_680f162c;
    Ordinal_1404(&local_f4,local_fc,1);
    Ordinal_1113(&local_fc);
    if (local_f4 != 0) goto LAB_680f147d;
LAB_680f1640:
    if (local_10c == 0) goto LAB_680f1676;
  }
  else {
    local_f4 = playback_getMediaFileInfo(&local_110,local_108);
    if (local_f4 != 0) {
LAB_680f147d:
      iVar1 = param_4[2];
      if (param_2[0x10] != 0) {
        Ordinal_1158(param_2[0x10],param_2[0x11]);
        param_2[0x11] = 0;
      }
      local_100 = (uint)*(ushort *)(param_2 + 0x1d);
      uVar3 = 0x14;
      if (param_4[3] != 0) {
        uVar3 = Ordinal_1154(param_4[3]);
      }
      iVar4 = Ordinal_1150(uVar3,0x14,0xa8);
      param_2[0x10] = iVar4;
      if (iVar4 != 0) {
        iVar4 = Ordinal_1157(iVar4);
        param_2[0x11] = iVar4;
        *(undefined2 *)(param_2 + 0x14) = 0;
        param_2[0x15] = 0;
        local_fc = local_108;
        if (local_108 < 1) {
LAB_680f1663:
          local_f8 = 0;
        }
        else {
          do {
            local_114 = 0;
            iVar4 = Ordinal_1414(local_f4);
            if (0 < iVar4) {
              Ordinal_1130(&local_f0,0xa8);
              local_ec = CONCAT22((short)local_100,(short)param_2[1]);
              local_f0 = *param_2;
              local_d4 = iVar1;
              iVar5 = Ordinal_1158(param_2[0x10],param_2[0x11]);
              if (iVar5 == 0) goto LAB_680f162c;
              param_2[0x11] = 0;
              iVar5 = Ordinal_1165(param_2[0x10],&local_114,&local_100,
                                   *(undefined4 *)(*param_2 + 0x36c),*param_2);
              if (iVar5 != 0) goto LAB_680f1663;
              iVar5 = Ordinal_1151(param_2[0x10],local_114,&local_f0);
              if (iVar5 == 0) goto LAB_680f162c;
              iVar5 = Ordinal_1157(param_2[0x10]);
              param_2[0x11] = iVar5;
              rendering_initChannelState(param_2);
              iVar5 = rendering_resolveState(iVar6,local_ec);
              iVar4 = display_readScoreEntry(local_104,iVar5,param_3,iVar4,param_4);
              if (iVar4 == 0) {
                local_f8 = -0x79;
                goto LAB_680f162c;
              }
            }
            local_100 = local_100 + 1;
            local_fc = local_fc + -4;
          } while (0 < local_fc);
          local_f8 = 0;
        }
      }
LAB_680f162c:
      if (local_f4 != 0) {
        Ordinal_1407(&local_f4);
      }
      goto LAB_680f1640;
    }
    local_10c = 3;
  }
  if (local_10c == 3) {
    iVar6 = -0x74;
  }
  else {
    if (local_10c != 6) goto LAB_680f1676;
    iVar6 = -0x7a;
  }
  lingo_formatDebugMsg(*(int **)(local_104 + 0x18),iVar6);
LAB_680f1676:
  if (local_f8 != 0) {
    piVar2 = *(int **)(local_104 + 0x18);
    if (local_f8 == -0x79) {
      rendering_writeStateData((int)&local_f0,local_48);
      lingo_formatDebugMsg(piVar2,-0x79);
    }
    else {
      lingo_formatDebugMsg(piVar2,local_f8);
    }
  }
  if ((param_2[0x10] != 0) && (param_2[0x11] == 0)) {
    iVar6 = Ordinal_1157(param_2[0x10]);
    param_2[0x11] = iVar6;
  }
  return 0;
}



// ============================================================
// Function: display_serializeCastState (FUN_680f16f0)
// Address: 680f16f0
// Size: 290 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_serializeCastState(int param_1,uint param_2)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    if (*(int *)(unaff_ESI + 0x4c) != 0) goto LAB_680f1716;
    iVar1 = Ordinal_35(0x14);
    *(int *)(unaff_ESI + 0x4c) = iVar1;
  }
  if (*(int *)(unaff_ESI + 0x4c) == 0) {
    return 0;
  }
LAB_680f1716:
  uVar2 = rendering_getRawStateFlags(unaff_ESI);
  iVar1 = *(int *)(unaff_ESI + 0x10);
  uVar2 = uVar2 & 0xfffffff3;
  if (iVar1 == 1) {
    uVar2 = uVar2 | 0xc;
  }
  else if (iVar1 == 2) {
    uVar2 = uVar2 | 8;
  }
  else if (iVar1 == 3) {
    uVar2 = uVar2 | 4;
  }
  rendering_setRawStateFlags(unaff_ESI,uVar2);
  local_8 = Ordinal_35(0x14);
  iVar1 = Ordinal_1114(local_8);
  uVar3 = rendering_getDispatchSize(unaff_ESI);
  *(undefined4 *)(iVar1 + 0x10) = uVar3;
  uVar3 = rendering_getRawStateFlags(unaff_ESI);
  *(undefined4 *)(iVar1 + 0xc) = uVar3;
  Ordinal_1115(local_8);
  iVar1 = 0;
  do {
    if ((param_2 & 1) == 0) {
switchD_680f1786_caseD_1:
      local_c = cast_lookupDataEntry(*(int *)(unaff_ESI + 0x4c),iVar1,0);
      if (((local_c != 0) && (local_8 != 0)) &&
         (iVar4 = cast_formatNumber(&local_8,(short)iVar1,local_c), iVar4 == 0)) {
        Ordinal_1113(&local_8);
      }
      Ordinal_1113(&local_c);
    }
    else {
      switch(iVar1) {
      case 0:
      case 5:
      case 6:
      case 7:
      case 8:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0x11:
      case 0x12:
      case 0x13:
        break;
      default:
        goto switchD_680f1786_caseD_1;
      case 0x14:
        if ((param_2 & 2) != 0) goto switchD_680f1786_caseD_1;
      }
    }
    iVar1 = iVar1 + 1;
    if (0x15 < iVar1) {
      if ((local_8 != 0) && (cast_readDataEntry(local_8,param_1,0), local_8 != 0)) {
        Ordinal_1113(&local_8);
        return 0;
      }
      cast_readDataEntry(*(int *)(unaff_ESI + 0x4c),param_1,0);
      return 0;
    }
  } while( true );
}




// ============================================================
// Function: display_writeCastMemberStream (FUN_680f1840)
// Address: 680f1840
// Size: 406 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_writeCastMemberStream(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar6 = 0;
  local_38 = 0;
  local_34 = 0;
  bVar1 = false;
  iVar5 = 0;
  local_38 = Ordinal_1111(0x1000,0);
  if (local_38 != 0) {
    iVar2 = Ordinal_1404(&local_34,local_38,3);
    if (iVar2 != 0) {
      Ordinal_1425(local_34,*(undefined4 *)(param_1 + 8));
      uVar3 = Ordinal_1433(local_34);
      Ordinal_1425(local_34,0);
      Ordinal_1425(local_34,0);
      if (*(int *)(param_1 + 0x4c) != 0) {
        iVar2 = Ordinal_1433(local_34);
        display_serializeCastState(local_34,param_4);
        iVar5 = Ordinal_1433(local_34);
        iVar5 = iVar5 - iVar2;
      }
      if (*(int *)(param_1 + 8) != 0) {
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        local_1c = 0;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_c = 0;
        iVar2 = Ordinal_1433(local_34);
        local_30 = param_1;
        local_28 = 0x11;
        local_2c = param_2;
        local_24 = local_34;
        rendering_initState(&local_30);
        iVar6 = Ordinal_1433(local_34);
        iVar6 = iVar6 - iVar2;
      }
      uVar4 = Ordinal_1433(local_34);
      Ordinal_1432(local_34,uVar3,0);
      Ordinal_1425(local_34,iVar5);
      Ordinal_1425(local_34,iVar6);
      Ordinal_1432(local_34,uVar4,0);
      uVar3 = Ordinal_1433(local_34);
      iVar5 = Ordinal_1434(local_34,uVar3);
      if (iVar5 != 0) {
        bVar1 = true;
      }
    }
  }
  if (local_34 != 0) {
    Ordinal_1407(&local_34);
  }
  if (!bVar1) {
    Ordinal_1113(&local_38);
  }
  return 0;
}



// ============================================================
// Function: display_saveSpriteChannels (FUN_680f19e0)
// Address: 680f19e0
// Size: 514 bytes
// Params: int * param_1, int param_2, undefined4 param_3, undefined4 param_4, uint param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_saveSpriteChannels(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 *local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined local_48 [64];
  uint local_8;
  
  local_5c = param_2;
  iVar6 = 0;
  local_60 = *param_1;
  iVar5 = 0;
  local_54 = 0;
  local_50 = 0;
  local_58 = (undefined4 *)0x0;
  local_4c = (uint)*(ushort *)(param_1 + 1);
  if (param_1[0x10] != 0) {
    local_58 = (undefined4 *)
               Ordinal_1111(((int)*(short *)((int)param_1 + 0x76) - (int)(short)param_1[0x1d]) * 4 +
                            4,0);
    if ((local_58 != (undefined4 *)0x0) && (iVar1 = Ordinal_1404(&local_50,local_58,3), iVar1 != 0))
    {
      sVar4 = (short)param_1[0x1d];
      local_4c = CONCAT22(sVar4,(undefined2)local_4c);
      if (sVar4 <= *(short *)((int)param_1 + 0x76)) {
        do {
          iVar5 = rendering_resolveState(local_60,local_4c);
          if ((iVar5 == 0) || (*(int *)(iVar5 + 8) == 0)) {
            uVar2 = 0;
          }
          else {
            uVar2 = *(undefined4 *)(iVar5 + 0x34);
          }
          Ordinal_1425(local_50,uVar2);
          sVar4 = sVar4 + 1;
          local_4c = CONCAT22(sVar4,(undefined2)local_4c);
        } while (sVar4 <= *(short *)((int)param_1 + 0x76));
      }
      iVar1 = local_5c;
      iVar3 = strings_readMediaBlock(*(int *)(local_5c + 4),FOURCC_CASx,param_1[0xf]);
      iVar5 = local_54;
      if (((iVar3 == 0) &&
          (iVar3 = strings_readMediaChunk(*(int *)(iVar1 + 4),FOURCC_CASx,param_1[0xf]), iVar5 = local_54,
          iVar3 != 0)) &&
         (iVar1 = strings_writeOrRemoveBlock(*(int *)(iVar1 + 4),FOURCC_CASx,param_1[0xf],local_58,0),
         iVar5 = local_54, iVar1 == 0)) {
        sVar4 = (short)param_1[0x1d];
        local_4c = CONCAT22(sVar4,(undefined2)local_4c);
        if (sVar4 <= *(short *)((int)param_1 + 0x76)) {
          do {
            local_64 = 0;
            iVar6 = rendering_resolveState(local_60,local_4c);
            if ((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) {
              local_64 = display_writeCastMemberStream(iVar6,param_3,param_4,param_5);
              iVar5 = local_54;
              if (local_64 == 0) goto LAB_680f1b87;
              iVar1 = Ordinal_20(*(int *)(local_5c + 4),*(int *)(iVar6 + 0x34),local_64);
              Ordinal_1113(&local_64);
              iVar5 = local_54;
              if (iVar1 != 0) goto LAB_680f1b87;
              sVar4 = (*(unsigned short *)((char *)&local_4c + 2));
            }
            sVar4 = sVar4 + 1;
            local_4c = CONCAT22(sVar4,(undefined2)local_4c);
          } while (sVar4 <= *(short *)((int)param_1 + 0x76));
        }
        local_54 = 1;
        iVar5 = local_54;
      }
    }
LAB_680f1b87:
    if (local_50 != 0) {
      Ordinal_1407(&local_50);
    }
  }
  Ordinal_1113(&local_58);
  if ((iVar5 == 0) && (iVar5 = lingo_getMovieRef(*param_1), iVar5 == 0)) {
    rendering_writeStateData(iVar6,local_48);
    lingo_formatDebugMsg((int *)*param_1,-0x1b9);
  }
  return 0;
}



// ============================================================
// Function: display_writeStreamString (FUN_680f1bf0)
// Address: 680f1bf0
// Size: 84 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_writeStreamString(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  undefined1 local_8 [4];
  
  bVar1 = false;
  iVar2 = *unaff_EDI;
  while( true ) {
    if (iVar2 < 1) {
      return -6;
    }
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1,*unaff_ESI,1,local_8);
    if (iVar2 != 0) break;
    if (*(char *)*unaff_ESI == '\0') {
      bVar1 = true;
    }
    *unaff_ESI = (char *)*unaff_ESI + 1;
    *unaff_EDI = *unaff_EDI + -1;
    if (bVar1) {
      return 0;
    }
    iVar2 = *unaff_EDI;
  }
  return iVar2;
}



// ============================================================
// Function: display_checkStreamCapacity (FUN_680f1c50)
// Address: 680f1c50
// Size: 91 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_checkStreamCapacity(void)

{
  uint uVar1;
  int unaff_ESI;
  uint local_c;
  uint local_8;
  
  uVar1 = (**(code **)(**(int **)(unaff_ESI + 0x14) + 0x28))(*(int **)(unaff_ESI + 0x14),&local_c);
  if ((uVar1 != 0x800412e0) && (uVar1 == 0)) {
    uVar1 = (**(code **)(**(int **)(unaff_ESI + 0x14) + 0x3c))(*(int **)(unaff_ESI + 0x14),&local_8)
    ;
    if ((uVar1 != 0x800412e0) && (uVar1 == 0)) {
      if (local_c <= local_8) {
        return 0;
      }
      uVar1 = -(uint)(local_8 < (uint)(*(int *)(unaff_ESI + 0xc) + *(int *)(unaff_ESI + 4))) &
              0x800412e0;
    }
  }
  return uVar1;
}



// ============================================================
// Function: display_validateStreamSize (FUN_680f1cb0)
// Address: 680f1cb0
// Size: 47 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_validateStreamSize(void)

{
  int iVar1;
  int unaff_ESI;
  uint local_8;
  
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x14) + 0x20))(*(int **)(unaff_ESI + 0x14),&local_8);
  if ((iVar1 == 0) && ((uint)(*(int *)(unaff_ESI + 0xc) + 8 + *(int *)(unaff_ESI + 4)) < local_8)) {
    iVar1 = -5;
  }
  return iVar1;
}



// ============================================================
// Function: display_getStreamState (FUN_680f1ce0)
// Address: 680f1ce0
// Size: 63 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getStreamState(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  uint local_8;
  
  iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x14) + 0x20))(*(int **)(unaff_ESI + 0x14),&local_8);
  if ((iVar2 == 0) &&
     (uVar1 = *(int *)(unaff_ESI + 0xc) + 8 + *(int *)(unaff_ESI + 4), local_8 <= uVar1)) {
    uVar3 = (**(code **)(**(int **)(unaff_ESI + 0x14) + 0x24))(*(int **)(unaff_ESI + 0x14),uVar1);
    return uVar3;
  }
  return 0xfffffffb;
}



// ============================================================
// Function: display_readBlockHeader (FUN_680f1d20)
// Address: 680f1d20
// Size: 165 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_readBlockHeader(void)

{
  int iVar1;
  uint *unaff_EDI;
  uint local_c;
  uint local_8;
  
  local_8 = unaff_EDI[1];
  if ((char)unaff_EDI[4] != '\0') {
    return 0;
  }
  iVar1 = (**(code **)(*(int *)unaff_EDI[5] + 0x3c))((int *)unaff_EDI[5],&local_c);
  if (iVar1 == 0) {
    if (local_c < local_8 + 8) {
      return -0x7ffbed20;
    }
    iVar1 = (**(code **)(*(int *)unaff_EDI[5] + 0x20))((int *)unaff_EDI[5],&local_8);
    if (iVar1 == 0) {
      unaff_EDI[1] = local_8;
      if ((local_8 & 1) != 0) {
        unaff_EDI[1] = local_8 + 1;
        iVar1 = (**(code **)(*(int *)unaff_EDI[5] + 0x24))((int *)unaff_EDI[5],local_8 + 1);
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      iVar1 = display_getStreamRef(2);
      if (iVar1 == 0) {
        if (*unaff_EDI < unaff_EDI[3] + 8 + unaff_EDI[1]) {
          return -3;
        }
        *(undefined1 *)(unaff_EDI + 4) = 1;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_readStreamBlock (FUN_680f1dd0)
// Address: 680f1dd0
// Size: 161 bytes
// Params: int param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_readStreamBlock(int param_1,int *param_2)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint unaff_EBX;
  int local_8;
  
  uVar2 = display_readBlockHeader();
  if (uVar2 != 0) {
    return uVar2;
  }
  uVar2 = display_checkStreamCapacity();
  if (uVar2 != 0) {
    return uVar2;
  }
  *(undefined1 *)(in_EAX + 0x10) = 0;
  if (*(int *)(in_EAX + 8) != param_1) {
    return 0xfffffffe;
  }
  if (0 < (int)unaff_EBX) {
    uVar2 = display_getStreamRef(unaff_EBX >> 2);
    if (uVar2 != 0) {
      return uVar2;
    }
    iVar1 = *param_2;
    if (iVar1 < (int)unaff_EBX) {
      return 0xfffffffd;
    }
    if ((int)unaff_EBX < iVar1) {
      uVar2 = (**(code **)(**(int **)(in_EAX + 0x14) + 0x20))(*(int **)(in_EAX + 0x14),&local_8);
      if (uVar2 != 0) {
        return uVar2;
      }
      uVar2 = (**(code **)(**(int **)(in_EAX + 0x14) + 0x24))
                        (*(int **)(in_EAX + 0x14),(local_8 - unaff_EBX) + iVar1);
      if (uVar2 != 0) {
        return uVar2;
      }
    }
  }
  uVar2 = display_validateStreamSize();
  return uVar2;
}



// ============================================================
// Function: display_copyStreamData (FUN_680f1e80)
// Address: 680f1e80
// Size: 77 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_copyStreamData(void)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  
  Ordinal_1116();
  iVar1 = (**(code **)(*unaff_ESI + 0xc))();
  if (iVar1 != 0) {
    Ordinal_1114();
    uVar2 = (**(code **)(*unaff_ESI + 0x20))();
    Ordinal_1128(uVar2);
    (**(code **)(*unaff_ESI + 0x24))();
    Ordinal_1115();
  }
  return iVar1;
}




// ============================================================
// Function: display_openRiffStream (FUN_680f1ed0)
// Address: 680f1ed0
// Size: 117 bytes
// Params: void * this, uint * param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall display_openRiffStream(void *this,uint *param_1)

{
  int local_18;
  uint *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  iVar2 = (**(code **)(*(int *)param_1[5] + 0x28))((int *)param_1[5],&param_1);
  if (iVar2 == 0) {
    if (*puVar1 == 0) {
      *puVar1 = (uint)param_1;
    }
    iVar2 = display_readBlockHeader();
    if (iVar2 == 0) {
      if (puVar1[2] != FOURCC_RIFF) {
        return -1;
      }
      if (puVar1[3] + 8 < *puVar1) {
        *puVar1 = puVar1[3] + 8;
      }
      iVar2 = display_getStreamRef(1);
      if (iVar2 == 0) {
        if (this != (void *)FOURCC_PCK2) {
          return -1;
        }
        *(undefined1 *)(puVar1 + 4) = 0;
      }
    }
  }
  return iVar2;
}



// ============================================================
// Function: display_readSignBlock (FUN_680f1f50)
// Address: 680f1f50
// Size: 177 bytes
// Params: int param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_readSignBlock(int param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = param_2;
  *param_2 = 0;
  uVar2 = display_readStreamBlock(FOURCC_SIGN,(int *)0x0);
  if (uVar2 == 0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 0xc))
                      (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0xc));
    *piVar1 = iVar3;
    if (iVar3 != 0) {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x20))(*(int **)(param_1 + 0x1c),iVar3);
      if (iVar3 != 0) {
        uVar2 = (**(code **)(**(int **)(param_1 + 0x14) + 0x14))
                          (*(int **)(param_1 + 0x14),iVar3,*(undefined4 *)(param_1 + 0xc),&param_2);
        if (uVar2 == 0) {
          uVar2 = display_getStreamState();
          if (uVar2 == 0) {
            (**(code **)(**(int **)(param_1 + 0x1c) + 0x24))(*(int **)(param_1 + 0x1c),*piVar1);
            return 0;
          }
        }
        goto LAB_680f1fc9;
      }
    }
    uVar2 = 0x80040002;
  }
LAB_680f1fc9:
  if (*piVar1 != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))(*(int **)(param_1 + 0x1c),*piVar1);
  }
  *piVar1 = 0;
  return uVar2;
}



// ============================================================
// Function: display_readFileListBlock (FUN_680f2010)
// Address: 680f2010
// Size: 285 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_readFileListBlock(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  *param_3 = 0;
  uVar1 = display_readStreamBlock(FOURCC_FLST,param_2);
  if (uVar1 == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x1c) + 0xc))
                      (*(int **)(param_1 + 0x1c),*(int *)(param_1 + 0xc) - *param_2);
    *param_3 = iVar2;
    if ((iVar2 == 0) ||
       (iVar2 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x20))(*(int **)(param_1 + 0x1c),iVar2),
       iVar2 == 0)) {
      uVar1 = 0x80040002;
    }
  }
  iVar2 = 0;
  if (0 < param_2[1]) {
    do {
      if (((uVar1 == 0) && (uVar1 = display_getStreamRef(1), uVar1 == 0)) &&
         (uVar1 = display_writeStreamString(*(int **)(param_1 + 0x14)), uVar1 == 0)) {
        uVar1 = display_writeStreamString(*(int **)(param_1 + 0x14));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2[1]);
  }
  if ((uVar1 == 0) && (uVar1 = display_getStreamState(), uVar1 == 0)) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x24))(*(int **)(param_1 + 0x1c),*param_3);
    return 0;
  }
  if (*param_3 != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))(*(int **)(param_1 + 0x1c),*param_3);
  }
  *param_3 = 0;
  return uVar1;
}



// ============================================================
// Function: display_encodeStreamBlock (FUN_680f2130)
// Address: 680f2130
// Size: 181 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_encodeStreamBlock(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = *(int **)(param_1 + 0x14);
  iVar3 = (**(code **)(*piVar2 + 0x20))(piVar2,&local_8);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,piVar2,0,param_2);
    while (iVar3 == 0) {
      iVar3 = (**(code **)(*piVar1 + 0x10))(piVar1,piVar2,param_2);
    }
    if (iVar3 == -0x7ffbfbb4) {
      iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1,piVar2,param_2);
    }
    else {
      (**(code **)(*piVar1 + 0x18))(piVar1);
    }
    if (iVar3 == -0x7ffbfbb3) {
      return -0x7ffbffec;
    }
    if (iVar3 == 0) {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 0x24))
                        (*(int **)(param_1 + 0x14),local_8 + param_3);
      return iVar3;
    }
  }
  return iVar3;
}



// ============================================================
// Function: display_readFileBlock (FUN_680f21f0)
// Address: 680f21f0
// Size: 430 bytes
// Params: int param_1, int * param_2, int * param_3, int * param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_readFileBlock(int param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int *local_c;
  char local_5;
  
  local_c = (int *)0x0;
  local_5 = '\0';
  uVar1 = display_readStreamBlock(FOURCC_FILE,param_2);
  if (uVar1 != 0) goto LAB_680f2384;
  uVar1 = display_validateStreamSize();
  if (uVar1 != 0) goto LAB_680f2384;
  if ((char)param_4 == '\0') {
LAB_680f2369:
    uVar1 = display_getStreamState();
LAB_680f2373:
    if (local_5 == '\0') goto LAB_680f2384;
  }
  else {
    if (param_2[3] < 1) {
LAB_680f2295:
      if (param_2[4] < 1) {
LAB_680f230d:
        if (param_2[1] != 0) {
          param_4 = (int *)0x0;
          (**(code **)(*param_3 + 0x44))(param_3,&param_4);
          if (param_4 != (int *)0x0) {
            iVar2 = (**(code **)(*param_4 + 0x18))(param_4,3,param_2 + 1,4,"MIOKey_FileType");
            if (iVar2 == 0) {
              (**(code **)(*param_4 + 0x18))(param_4,3,param_2 + 2,4,"MIOKey_FileCreator");
            }
            (**(code **)(*param_4 + 8))(param_4);
          }
        }
        goto LAB_680f2369;
      }
      if (local_5 != '\0') {
        (**(code **)(*local_c + 0x10))(local_c);
        (**(code **)(*local_c + 8))(local_c);
        local_5 = '\0';
      }
      uVar1 = (**(code **)(*param_3 + 0x18))(param_3,0x2000,&local_c);
      if (uVar1 == 0) {
        uVar1 = (**(code **)(*local_c + 0xc))(local_c,0x8001,2);
        if (uVar1 == 0) {
          local_5 = '\x01';
          uVar1 = display_encodeStreamBlock(param_1,local_c,param_2[6]);
          if (uVar1 != 0) goto LAB_680f2379;
          goto LAB_680f230d;
        }
      }
      goto LAB_680f2373;
    }
    uVar1 = (**(code **)(*param_3 + 0x18))(param_3,0x2000,&local_c);
    if (uVar1 != 0) goto LAB_680f2384;
    uVar1 = (**(code **)(*local_c + 0xc))(local_c,1,2);
    if (uVar1 != 0) goto LAB_680f2384;
    local_5 = '\x01';
    uVar1 = display_encodeStreamBlock(param_1,local_c,param_2[5]);
    if (uVar1 == 0) goto LAB_680f2295;
  }
LAB_680f2379:
  (**(code **)(*local_c + 0x10))(local_c);
LAB_680f2384:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return uVar1;
}



// ============================================================
// Function: display_encodeStreamData (FUN_680f23a0)
// Address: 680f23a0
// Size: 373 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_encodeStreamData(int param_1,undefined4 param_2,int *param_3)

{
  int in_EAX;
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = 0;
  local_14 = 0;
  *param_3 = 0;
  local_10 = Ordinal_1111(param_1,0);
  if (local_10 == 0) {
    iVar4 = -0x7ffbfffe;
  }
  else {
    local_14 = Ordinal_1111(param_2,0);
    if (local_14 == 0) {
      iVar4 = -0x7ffbfffe;
    }
    else {
      uVar1 = Ordinal_1114(local_10);
      iVar4 = (**(code **)(**(int **)(in_EAX + 0x14) + 0x14))
                        (*(int **)(in_EAX + 0x14),uVar1,param_1,local_18);
      Ordinal_1115(local_10);
      if (iVar4 == 0) {
        iVar4 = Ordinal_1446(local_10,0xffffffff,1,&local_8);
        if (iVar4 == 0) {
          iVar4 = -0x7ffbfffe;
        }
        else {
          iVar4 = Ordinal_1446(local_14,0xffffffff,2,&local_c);
          if (iVar4 == 0) {
            iVar4 = -0x7ffbfffe;
          }
          else {
            iVar4 = (**(code **)(*local_8 + 0xc))(local_8,0,2);
            if (iVar4 == 0) {
              iVar4 = (**(code **)(*local_c + 0xc))(local_c,2,2);
              piVar2 = local_8;
              if (iVar4 == 0) {
                uVar1 = *(undefined4 *)(in_EAX + 0x14);
                *(int **)(in_EAX + 0x14) = local_8;
                iVar4 = display_encodeStreamBlock(in_EAX,local_c,param_1);
                *(undefined4 *)(in_EAX + 0x14) = uVar1;
                (**(code **)(*local_8 + 0x10))(local_8);
                piVar2 = local_c;
              }
              (**(code **)(*piVar2 + 0x10))(piVar2);
            }
          }
        }
      }
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  Ordinal_1113(&local_10);
  if (iVar4 == 0) {
    iVar3 = display_copyStreamData();
    *param_3 = iVar3;
  }
  Ordinal_1113(&local_14);
  if ((*param_3 != 0) || (iVar3 = -0x7ffbfffe, iVar4 != 0)) {
    iVar3 = iVar4;
  }
  return iVar3;
}



// ============================================================
// Function: display_readInfoBlock (FUN_680f2520)
// Address: 680f2520
// Size: 134 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_readInfoBlock(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  *param_3 = 0;
  uVar1 = display_readStreamBlock(FOURCC_INFO,param_2);
  if (uVar1 == 0) {
    if (param_2[1] == 3) {
      if (((param_2[4] < 1) || (uVar1 = display_encodeStreamData(param_2[5],param_2[4],param_3), uVar1 == 0)) &&
         (uVar1 = display_getStreamState(), uVar1 == 0)) {
        return 0;
      }
    }
    else {
      uVar1 = 0xfffffffc;
    }
  }
  if (*param_3 != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))(*(int **)(param_1 + 0x1c),*param_3);
  }
  *param_3 = 0;
  return uVar1;
}



// ============================================================
// Function: display_readCertBlock (FUN_680f25b0)
// Address: 680f25b0
// Size: 123 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_readCertBlock(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  *param_3 = 0;
  uVar1 = display_readStreamBlock(FOURCC_CERT,param_2);
  if ((uVar1 == 0) &&
     (((param_2[1] < 1 || (uVar1 = display_encodeStreamData(param_2[2],param_2[1],param_3), uVar1 == 0)) &&
      (uVar1 = display_getStreamState(), uVar1 == 0)))) {
    return 0;
  }
  if (*param_3 != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))(*(int **)(param_1 + 0x1c),*param_3);
  }
  *param_3 = 0;
  return uVar1;
}



// ============================================================
// Function: display_readStreamAttribs (FUN_680f2630)
// Address: 680f2630
// Size: 62 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_readStreamAttribs(void)
{
  undefined1 uVar1;
  undefined2 uVar2;
  int unaff_EDI;
  
  uVar1 = Ordinal_1410();
  *(undefined1 *)(unaff_EDI + 0x80) = uVar1;
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_EDI + 0x81) = uVar1;
  uVar1 = Ordinal_1410();
  *(undefined1 *)(unaff_EDI + 0x82) = uVar1;
  uVar1 = Ordinal_1410();
  *(undefined1 *)(unaff_EDI + 0x83) = uVar1;
  uVar2 = Ordinal_1412();
  *(undefined2 *)(unaff_EDI + 0x84) = uVar2;
  return 0;
}



// ============================================================
// Function: display_writeStreamAttribs (FUN_680f2670)
// Address: 680f2670
// Size: 71 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_writeStreamAttribs(void)
{
  Ordinal_1421();
  Ordinal_1422();
  Ordinal_1421();
  Ordinal_1421();
  Ordinal_1423();
  return 0;
}



