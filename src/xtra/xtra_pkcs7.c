// Module: xtra
// Topic: PKCS7 signing, verification, message processing, certificate chain building
// Address range: 0x68108400 - 0x6810B754
// Functions (34):
//   xtra_initPKCS7Defaults
//   xtra_freePKCS7State
//   xtra_initPKCS7Digest
//   xtra_processPKCS7Message
//   xtra_initPKCS7Context
//   xtra_freePKCS7Buffer
//   xtra_allocPKCS7Buffer
//   xtra_bindPKCS7SignerInfo
//   xtra_bindPKCS7RecipientInfo
//   xtra_addPKCS7AuthAttribute
//   xtra_lookupPKCS7ContentType
//   xtra_findPKCS7ContentTypeById
//   xtra_readPKCS7ContentInfo
//   xtra_processPKCS7SignedData
//   xtra_writePKCS7Signature
//   xtra_buildPKCS7SignerInfo
//   xtra_verifyPKCS7SignedData
//   xtra_processPKCS7EnvelopedData
//   xtra_buildPKCS7RecipientInfo
//   xtra_finalizePKCS7Processing
//   xtra_parsePKCS7OID
//   xtra_buildPKCS7EncryptedContent
//   xtra_updatePKCS7Buffer
//   xtra_resetPKCS7State
//   xtra_clearPKCS7State
//   xtra_createPKCS7Session
//   xtra_openPKCS7Session
//   xtra_closePKCS7Session
//   xtra_verifyPKCS7CertChain
//   xtra_signPKCS7Data
//   xtra_updatePKCS7Digest
//   xtra_finalizePKCS7Digest
//   xtra_encodePKCS7Attributes
//   xtra_decodePKCS7Attributes

// ============================================================
// Function: xtra_initPKCS7Defaults (FUN_68108400)
// Address: 68108400
// Size: 60 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initPKCS7Defaults(void *param_1)
{
  int param_4;
  xtra_resetPKCS7State(param_1);
  display_fillMemory((void *)((int)param_1 + 0x54),0,8);
  *(undefined4 *)((int)param_1 + 0x44) = 1;
  *(undefined4 *)((int)param_1 + 0x48) = 1;
  *(undefined4 *)((int)param_1 + 0x40) = 2;
  *(undefined4 *)((int)param_1 + 0x4c) = 0;
  *(undefined4 *)((int)param_1 + 0x14) = 1;
  return 0;
}



// ============================================================
// Function: xtra_freePKCS7State (FUN_68108440)
// Address: 68108440
// Size: 34 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freePKCS7State(undefined4 *param_1)
{
  if (param_1[0x16] != 0) {
    display_releaseFormatData(param_1 + 0x15);
  }
  xtra_clearPKCS7State(param_1);
  return 0;
}



// ============================================================
// Function: xtra_initPKCS7Digest (FUN_68108470)
// Address: 68108470
// Size: 32 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_initPKCS7Digest(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 1;
  uVar1 = xtra_resetAttributeIterator((int *)(param_1 + 0x54));
  return uVar1;
}



// ============================================================
// Function: xtra_processPKCS7Message (FUN_68108490)
// Address: 68108490
// Size: 748 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 * param_6, undefined4 * param_7, undefined4 param_8
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
xtra_processPKCS7Message(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6,undefined4 *param_7,undefined4 param_8)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_368 [3];
  int local_35c;
  undefined4 *local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 *local_33c;
  undefined4 *local_338;
  undefined4 local_334;
  undefined4 *local_330;
  undefined1 local_32c [8];
  undefined1 *local_324;
  undefined1 *local_320;
  undefined4 **local_31c;
  undefined1 *local_318;
  undefined1 **local_314;
  undefined1 *local_310;
  undefined1 local_30c [4];
  undefined1 *local_308;
  undefined4 **local_304;
  undefined1 local_300 [4];
  undefined4 **local_2fc;
  undefined1 local_2e4 [4];
  undefined4 **local_2e0;
  undefined *local_2dc;
  undefined4 **local_2d8;
  undefined1 local_2d4 [4];
  int *local_2d0;
  int *local_2cc;
  int *local_2c8;
  int *local_2c4 [2];
  undefined4 **local_2bc;
  undefined4 **local_2b4;
  undefined1 local_2b0 [4];
  undefined4 **local_2ac;
  undefined4 **local_288 [2];
  undefined4 local_280;
  undefined4 **local_150;
  int *local_14c;
  int local_148;
  undefined4 local_128;
  undefined4 local_110;
  
  local_350 = param_1;
  local_34c = param_2;
  local_348 = param_5;
  local_344 = param_3;
  local_33c = param_6;
  local_338 = param_7;
  local_334 = param_8;
  xtra_initPKCS7Context(local_368,&local_350);
  uVar1 = xtra_allocPKCS7Buffer((int)local_368);
  if (uVar1 == 0) {
    display_fillMemory(local_30c,0,0x84);
    local_324 = local_300;
    local_320 = local_2e4;
    local_31c = &local_2d8;
    local_330 = param_1;
    local_318 = local_2d4;
    local_314 = (undefined1 **)local_2c4;
    local_310 = local_2b0;
    local_308 = local_32c;
    local_304 = &local_330;
    local_288[0] = &local_350;
    local_2fc = local_288;
    local_280 = 0;
    xtra_bindPKCS7SignerInfo((int)local_30c,(int)local_2fc);
    local_2e0 = &local_350;
    param_1[0x12] = 1;
    local_2d8 = local_288;
    local_2d0 = local_368;
    local_2ac = &local_150;
    param_1[0x13] = 0;
    local_2dc = &DAT_6818fb98;
    local_148 = 0;
    local_2cc = local_2d0;
    local_2c8 = local_2d0;
    local_2c4[0] = local_2d0;
    local_2bc = local_2e0;
    local_2b4 = local_2e0;
    local_150 = local_2e0;
    local_14c = local_2d0;
    xtra_bindPKCS7RecipientInfo((int)local_30c,(int)local_2ac);
    local_128 = 0;
    local_110 = 0;
    uVar1 = xtra_lookupCipherOID((uint *)&DAT_6818f800,(int)local_30c,param_4);
    if (uVar1 == 0) {
      if (local_35c == 0) {
        uVar1 = xtra_finalizePKCS7Processing(local_368);
        if (uVar1 != 0) goto LAB_6810874e;
      }
      if (local_148 == 0) {
        uVar1 = xtra_closePKCS7Session((int)param_1,param_6,param_7,param_8);
        if (uVar1 != 0) goto LAB_6810874e;
        display_initNetworkSecurity(param_1);
      }
    }
    else if (uVar1 == 0x122) {
      uVar1 = 0x138;
    }
    if (uVar1 == 0) {
      if (param_1[6] == 0) {
        if (param_1[7] == 0) {
          if (param_1[8] == 0) goto LAB_6810874e;
          goto LAB_681086eb;
        }
LAB_681086f1:
        uVar3 = param_1[4];
      }
      else {
LAB_681086eb:
        if (param_1[7] != 0) goto LAB_681086f1;
        uVar3 = 0;
      }
      if ((param_1[6] != 0) || (uVar2 = 0, param_1[8] != 0)) {
        uVar2 = param_1[3];
      }
      display_setCertExtensions((undefined4 *)param_1[0xd],uVar2,uVar3,param_1[8],param_1[9]);
      if ((param_1[6] != 0) || (param_1[8] != 0)) {
        param_1[3] = 0;
      }
      if (param_1[7] != 0) {
        param_1[4] = 0;
      }
      uVar1 = (param_1[8] == 0) + 0x143;
      goto LAB_68108762;
    }
  }
LAB_6810874e:
  display_setCertExtensions((undefined4 *)param_1[0xd],0,0,0,0);
LAB_68108762:
  xtra_freePKCS7Buffer((int)local_368);
  return uVar1;
}



// ============================================================
// Function: xtra_initPKCS7Context (FUN_68108780)
// Address: 68108780
// Size: 28 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initPKCS7Context(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  display_fillMemory(param_1 + 3,0,0xc);
  return 0;
}



// ============================================================
// Function: xtra_freePKCS7Buffer (FUN_681087a0)
// Address: 681087a0
// Size: 41 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freePKCS7Buffer(int param_1)
{
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    display_fillMemory(*(void **)(param_1 + 0x10),0,*(size_t *)(param_1 + 0x14));
    display_freeIfNonNull(*(int *)(param_1 + 0x10));
  }
  return 0;
}



// ============================================================
// Function: xtra_allocPKCS7Buffer (FUN_681087d0)
// Address: 681087d0
// Size: 47 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_allocPKCS7Buffer(int param_1)

{
  int iVar1;
  
  iVar1 = display_freeFormatBlock(*(int *)(param_1 + 0x10),0x400);
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 == 0) {
    return 0x100;
  }
  *(undefined4 *)(param_1 + 0x14) = 0x400;
  return 0;
}



// ============================================================
// Function: xtra_bindPKCS7SignerInfo (FUN_68108800)
// Address: 68108800
// Size: 40 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_bindPKCS7SignerInfo(int param_1,int param_2)
{
  *(undefined **)(param_1 + 0x14) = &DAT_6818fb90;
  *(int *)(param_1 + 0x18) = param_2 + 0xc;
  *(int *)(param_1 + 0x24) = param_2 + 0x24;
  *(int *)(param_1 + 0x1c) = param_2 + 0x14;
  *(int *)(param_1 + 0x20) = param_2 + 0x1c;
  return 0;
}



// ============================================================
// Function: xtra_bindPKCS7RecipientInfo (FUN_68108830)
// Address: 68108830
// Size: 61 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_bindPKCS7RecipientInfo(int param_1,int param_2)
{
  *(undefined **)(param_1 + 100) = &DAT_6818fb94;
  *(int *)(param_1 + 0x68) = param_2 + 0x10;
  *(int *)(param_1 + 0x6c) = param_2 + 0x18;
  *(int *)(param_1 + 0x70) = param_2 + 0x20;
  *(int *)(param_1 + 0x74) = param_2 + 0x28;
  *(int *)(param_1 + 0x80) = param_2 + 0x40;
  *(int *)(param_1 + 0x78) = param_2 + 0x30;
  *(int *)(param_1 + 0x7c) = param_2 + 0x38;
  return 0;
}



// ============================================================
// Function: xtra_addPKCS7AuthAttribute (FUN_68108870)
// Address: 68108870
// Size: 93 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addPKCS7AuthAttribute(undefined4 *param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_findPKCS7ContentTypeById(&local_4,param_2);
  if (iVar1 == 0) {
    iVar1 = xtra_addCRLEntryToList(param_1,&DAT_6818f7e0,9,param_3);
    if (iVar1 == 0) {
      xtra_decodeCRLAttributes(param_1,&DAT_6818f7e0,9,6,*(int *)(local_4 + 4),*(uint *)(local_4 + 8),param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_lookupPKCS7ContentType (FUN_681088d0)
// Address: 681088d0
// Size: 77 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_lookupPKCS7ContentType(int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = &DAT_6818fbf0;
  iVar1 = DAT_6818fbf0;
  while( true ) {
    if (iVar1 == 0) {
      return 0x10a;
    }
    if ((piVar3[2] == param_2[1]) &&
       (uVar2 = display_decodeFormat((byte *)*param_2,(byte *)piVar3[1],param_2[1]), uVar2 == 0)) break;
    piVar3 = piVar3 + 3;
    iVar1 = *piVar3;
  }
  *param_1 = *piVar3;
  return 0;
}



// ============================================================
// Function: xtra_findPKCS7ContentTypeById (FUN_68108920)
// Address: 68108920
// Size: 48 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_findPKCS7ContentTypeById(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  *param_1 = (int)&DAT_6818fbf0;
  iVar1 = DAT_6818fbf0;
  while( true ) {
    if (iVar1 == 0) {
      return 0x112;
    }
    if (*(int *)*param_1 == param_2) break;
    piVar2 = (int *)*param_1 + 3;
    *param_1 = (int)piVar2;
    iVar1 = *piVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_readPKCS7ContentInfo (FUN_68108950)
// Address: 68108950
// Size: 51 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readPKCS7ContentInfo(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  if (*param_2 == 0) {
    iVar1 = xtra_copyBERContent(param_1,&PTR_DAT_6818fc40,param_3);
    return iVar1;
  }
  iVar1 = xtra_readBEREnvelopedData(param_1,param_2,param_3);
  return iVar1;
}



// ============================================================
// Function: xtra_processPKCS7SignedData (FUN_68108b30)
// Address: 68108b30
// Size: 449 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_processPKCS7SignedData(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int local_18;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8 [2];
  
  iVar4 = 0;
  piVar1 = (int *)*param_4;
  if (param_4[3] == 0) {
    iVar2 = param_4[4];
    if (*(int *)(*piVar1 + 8) == 0) {
      iVar2 = iVar2 + 0x18;
    }
    param_4[1] = iVar2;
    iVar2 = (**(code **)(piVar1[3] + 8))
                      (param_4[4] + 0x18,local_8,param_4[5] + -0x18,
                       *(undefined4 *)(piVar1[3] + 0x14));
    if (iVar2 == 0) {
      if ((*(int *)*piVar1 != 0) &&
         (iVar4 = xtra_decryptData(*(int *)*piVar1,param_4[4] + 0x18,local_8[0],piVar1[7]), iVar4 != 0))
      goto LAB_68108cc8;
      iVar2 = 0;
      if (*(int *)(*piVar1 + 8) == 0) {
        param_4[2] = local_8[0];
      }
      else {
        iVar4 = xtra_dispatchEncrypt8(*(int *)(*piVar1 + 8),param_4[4],param_4 + 2,param_4[5],
                             param_4[4] + 0x18,local_8[0],0,piVar1[7]);
        if (iVar4 != 0) goto LAB_68108cc4;
      }
      iVar3 = piVar1[2];
      if ((iVar3 != 0) &&
         (iVar3 = (**(code **)(iVar3 + 0x10))(param_4[1],param_4[2],*(undefined4 *)(iVar3 + 0x14)),
         iVar3 != 0)) {
LAB_68108cbf:
        iVar2 = 0x130;
      }
    }
    else if (iVar2 == 0x118) {
      param_4[3] = 1;
      if (*(int *)(*piVar1 + 8) != 0) {
        iVar4 = xtra_dispatchEncrypt6(*(int *)(*piVar1 + 8),param_4[4],param_4 + 2,param_4[5],0,piVar1[7]);
        if (iVar4 != 0) goto LAB_68108cc8;
        iVar2 = piVar1[2];
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(iVar2 + 0x10))(param_4[1],param_4[2],*(undefined4 *)(iVar2 + 0x14));
        if (iVar2 == 0) {
          return 0;
        }
        goto LAB_68108cbf;
      }
      if ((param_1 == (int *)0x0) || (iVar2 = xtra_processCommand(param_1,0,0,0x1e,0), iVar2 == 0)) {
        return 0;
      }
    }
    else {
      iVar2 = 0x141;
    }
  }
  else if ((param_1 == (int *)0x0) || (iVar2 = xtra_processCommand(param_1,0,0,0x1e,0), iVar2 == 0)) {
    return 0;
  }
LAB_68108cc4:
  if (iVar4 == 0) {
    return iVar2;
  }
LAB_68108cc8:
  iVar4 = xtra_decodeBERDirect("processing input text stream",iVar4,0x112,(undefined4 *)piVar1[6]);
  return iVar4;
}



// ============================================================
// Function: xtra_writePKCS7Signature (FUN_68108d00)
// Address: 68108d00
// Size: 184 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writePKCS7Signature(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)
{
  uint uVar1;
  int iVar2;
  uint local_8;
  undefined4 *local_4;
  
  if ((param_4 == (int *)0x0) || (*(undefined4 **)(*(int *)*param_4 + 0xc) == (undefined4 *)0x0)) {
    local_8 = 0;
  }
  else {
    iVar2 = xtra_parseCertificate(&local_8,*(undefined4 **)(*(int *)*param_4 + 0xc));
    if (iVar2 != 0) {
      return 0;
    }
  }
  if (local_8 == 0) {
    xtra_processCommand(param_1,0,0,0x1b,0);
    return 0;
  }
  uVar1 = param_4[1];
  if (local_8 <= uVar1) {
    xtra_processCommand(param_1,0,0,0x1e,0);
    return 0;
  }
  param_4[1] = uVar1 + 1;
  iVar2 = strftime(&local_4,(undefined4 *)0x0,*(undefined4 **)(*(int *)*param_4 + 0xc),uVar1);
  if (iVar2 == 0) {
    display_buildObjectBlock(param_4 + 2,local_4,*(undefined4 **)(*param_4 + 0x18));
  }
  return 0;
}



// ============================================================
// Function: xtra_buildPKCS7SignerInfo (FUN_68108dc0)
// Address: 68108dc0
// Size: 184 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_buildPKCS7SignerInfo(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)
{
  uint uVar1;
  int iVar2;
  uint local_8;
  undefined4 *local_4;
  
  if ((param_4 == (int *)0x0) || (*(undefined4 **)(*(int *)*param_4 + 0x10) == (undefined4 *)0x0)) {
    local_8 = 0;
  }
  else {
    iVar2 = xtra_parseCertificate(&local_8,*(undefined4 **)(*(int *)*param_4 + 0x10));
    if (iVar2 != 0) {
      return 0;
    }
  }
  if (local_8 == 0) {
    xtra_processCommand(param_1,0,0,0x1b,0);
    return 0;
  }
  uVar1 = param_4[1];
  if (local_8 <= uVar1) {
    xtra_processCommand(param_1,0,0,0x1e,0);
    return 0;
  }
  param_4[1] = uVar1 + 1;
  iVar2 = strftime(&local_4,(undefined4 *)0x0,*(undefined4 **)(*(int *)*param_4 + 0x10),uVar1);
  if (iVar2 == 0) {
    xtra_extractSignatureData(param_4 + 2,local_4,*(undefined4 **)(*param_4 + 0x18));
  }
  return 0;
}



// ============================================================
// Function: xtra_verifyPKCS7SignedData (FUN_68108e80)
// Address: 68108e80
// Size: 933 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, int * param_4
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_verifyPKCS7SignedData(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_30;
  undefined4 *local_2c;
  int local_28;
  int *piStack_24;
  int local_20;
  int iStack_1c;
  uint local_18 [6];
  
  uVar4 = 0;
  if (param_4 == (int *)0x0) {
    uVar4 = xtra_processCommand(param_1,0,0,0x1b,0);
    return uVar4;
  }
  if (param_4[2] != 0) {
    uVar4 = xtra_processCommand(param_1,0,0,0x1e,0);
    return uVar4;
  }
  piVar1 = (int *)((int *)*param_4)[1];
  if (piVar1 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1,param_4);
    return uVar4;
  }
  piVar1 = *(int **)*param_4;
  display_initNetworkSecurity(param_4 + 3);
  local_2c = *(undefined4 **)(*param_4 + 0x18);
  if (piVar1[0x13] == 0) {
    uVar4 = xtra_encryptDataEx(*piVar1,local_18,&local_30,0x15,*(undefined4 *)(*param_4 + 0x1c));
    uVar5 = local_18[0];
    uVar2 = uVar4;
  }
  else {
    local_30 = 0;
    do {
      iVar3 = (**(code **)(*(int *)(*param_4 + 0xc) + 8))
                        ((int)local_18 + local_30,&local_28,0x15 - local_30,
                         *(undefined4 *)(*(int *)(*param_4 + 0xc) + 0x14));
      if (iVar3 != 0) {
        uVar5 = (iVar3 == 0x118) - 1 & 0x141;
        uVar2 = uVar5;
        goto joined_r0x68108f9a;
      }
      local_30 = local_30 + local_28;
    } while (local_30 < 0x15);
    uVar5 = 0x141;
    uVar2 = uVar5;
  }
joined_r0x68108f9a:
  if ((uVar2 != 0) ||
     (((undefined4 *)piVar1[0x15] != (undefined4 *)0x0 &&
      (uVar5 = xtra_extractBERSignedData(&local_20,(undefined4 *)piVar1[0x15],local_2c), uVar5 != 0))))
  goto LAB_681091e6;
  if (((undefined4 *)piVar1[0x15] == (undefined4 *)0x0) || (iStack_1c == 0)) {
    param_4[10] = 0;
  }
  else {
    if (piVar1[0x10] == 4) {
      uVar5 = 0x102;
      goto LAB_681091e6;
    }
    uVar4 = xtra_addCRLEntryToList((undefined4 *)piVar1[0x15],&DAT_6818f7f0,9,local_2c);
    if (uVar4 != 0) {
      return uVar4;
    }
    uVar4 = xtra_decodeCRLAttributes((undefined4 *)piVar1[0x15],&DAT_6818f7f0,9,4,(int)local_18,local_30,
                         local_2c);
    if (uVar4 != 0) {
      return uVar4;
    }
    uVar4 = xtra_addPKCS7AuthAttribute((undefined4 *)piVar1[0x15],1,local_2c);
    if (uVar4 != 0) {
      return uVar4;
    }
    uVar4 = xtra_writeBEREnvelopedData(&local_20,&iStack_1c,(undefined4 *)piVar1[0x15],local_2c);
    if (uVar4 != 0) {
      return uVar4;
    }
    uVar4 = xtra_decryptData(*piVar1,local_20,iStack_1c,*(undefined4 *)(*param_4 + 0x1c));
    uVar5 = 0;
    if (((uVar4 != 0) ||
        (uVar4 = xtra_encryptDataEx(*piVar1,local_18,&local_30,0x15,*(undefined4 *)(*param_4 + 0x1c)),
        uVar4 != 0)) ||
       (uVar5 = xtra_extractBERSignedData(param_4 + 10,(undefined4 *)piVar1[0x15],local_2c), uVar5 != 0))
    goto LAB_681091e6;
  }
  uVar4 = xtra_updatePKCS7Digest((int *)&piStack_24,(int *)*piVar1,(int *)&PTR_LAB_6818fc48);
  if (uVar4 == 0) {
    iVar3 = piStack_24[1];
    param_4[8] = *piStack_24;
    param_4[9] = iVar3;
    uVar4 = display_getNetSecurityState(param_4 + 3);
    if (((uVar4 == 0) &&
        (uVar5 = (**(code **)piVar1[0xf])
                           (piVar1,param_4 + 4,param_4 + 6,param_4[3],param_4 + 0x12,param_4 + 0xf,
                            0x108,local_18,local_30,local_2c,*(undefined4 *)(*param_4 + 0x1c)),
        uVar5 == 0)) &&
       (uVar4 = xtra_updatePKCS7Digest((int *)&piStack_24,(int *)param_4[3],(int *)&PTR_LAB_6818fc78),
       uVar4 == 0)) {
      iVar3 = piStack_24[1];
      param_4[0xc] = *piStack_24;
      param_4[0xd] = iVar3;
      param_4[0xe] = (int)(param_4 + 0x12);
      if (((undefined4 *)piVar1[0x14] == (undefined4 *)0x0) ||
         (uVar5 = xtra_extractBERSignedData(param_4 + 0x10,(undefined4 *)piVar1[0x14],local_2c), uVar5 == 0)) {
        if ((piVar1[0x14] == 0) || (param_4[0x11] == 0)) {
          param_4[0x10] = 0;
        }
        else if (piVar1[0x10] == 4) {
          uVar5 = 0x102;
          goto LAB_681091e6;
        }
        param_4[2] = param_4[2] + 1;
      }
    }
  }
LAB_681091e6:
  display_fillMemory(local_18,0,0x15);
  if (uVar4 == 0) {
    return uVar5;
  }
  uVar4 = xtra_decodeBERDirect("encoding signer info",uVar4,0x112,local_2c);
  return uVar4;
}



// ============================================================
// Function: xtra_processPKCS7EnvelopedData (FUN_68109230)
// Address: 68109230
// Size: 453 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_processPKCS7EnvelopedData(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint local_8;
  int *piStack_4;
  
  if (param_4 == (int *)0x0) {
    xtra_processCommand(param_1,0,0,0x1b,0);
    return 0;
  }
  puVar2 = (undefined4 *)((int *)*param_4)[6];
  uVar4 = display_getCertChainCount(&local_8,*(undefined4 **)(*(int *)*param_4 + 0x34));
  if (uVar4 == 0) {
    if ((param_4[2] == local_8) && (param_4[0x4c] != 0)) {
      display_removeAllCertEntries(*(undefined4 **)(*(int *)*param_4 + 0x34),0);
      param_4[2] = 0;
      iVar5 = (*(code *)param_4[0x4b])
                        (*(undefined4 *)(*(int *)*param_4 + 0x34),param_4[0x4d],puVar2,
                         ((int *)*param_4)[7]);
      if (iVar5 != 0) {
        xtra_decodeBER("calling you set add function",iVar5,0x10c,puVar2);
        return 0;
      }
      uVar4 = display_getCertChainCount(&local_8,*(undefined4 **)(*(int *)*param_4 + 0x34));
      if (uVar4 != 0) {
        return 0;
      }
      if (local_8 == 0) {
        param_4[0x4c] = 0;
      }
    }
    if (local_8 < (uint)param_4[2]) {
      xtra_processCommand(param_1,0,0,0x1e,0);
      return 0;
    }
    piVar1 = param_4 + 1;
    display_initNetworkSecurity(piVar1);
    iVar5 = display_getNetSecurityState(piVar1);
    if (iVar5 == 0) {
      piVar3 = (int *)*param_4;
      uVar4 = xtra_openPKCS7Session(*piVar3,param_4 + 3,param_4 + 5,*piVar1,(int)(param_4 + 0xb),
                           (uint *)(param_4 + 10),0x100,param_4[2],piVar3[4],puVar2,piVar3[7]);
      if (uVar4 == 0) {
        if (param_4[3] == 0) {
          iVar5 = xtra_processCommand(param_1,0,0,0x1e,0);
          if (iVar5 != 0) {
            return 0;
          }
        }
        else {
          iVar5 = xtra_updatePKCS7Digest((int *)&piStack_4,(int *)*piVar1,(int *)&PTR_LAB_6818fc70);
          if (iVar5 != 0) {
            return 0;
          }
          iVar5 = piStack_4[1];
          param_4[7] = *piStack_4;
          param_4[8] = iVar5;
          param_4[9] = (int)(param_4 + 0xb);
        }
        param_4[2] = param_4[2] + 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_buildPKCS7RecipientInfo (FUN_68109790)
// Address: 68109790
// Size: 926 bytes
// Params: undefined4 param_1, int * param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_buildPKCS7RecipientInfo(undefined4 param_1,int *param_2)

{
  int param_4;
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_50;
  uint local_4c;
  int local_48;
  uint uStack_44;
  int local_40;
  uint local_3c;
  byte *local_38;
  uint local_34;
  int iStack_30;
  int iStack_2c;
  byte local_28 [20];
  byte abStack_14 [20];
  
  local_48 = 0;
  local_50 = 0;
  if (param_2[2] != 0) {
    return 0x10a;
  }
  piVar1 = *(int **)*param_2;
  puVar2 = (undefined4 *)((int *)*param_2)[6];
  if (((int *)param_2[1])[3] == 0) {
    uVar4 = xtra_finalizePKCS7Processing((int *)param_2[1]);
    if (uVar4 != 0) goto LAB_68109ace;
  }
  piVar3 = *(int **)(*param_2 + 4);
  if (piVar3 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar3 + 4))(piVar3,param_2);
    goto LAB_68109ace;
  }
  if ((piVar1[0x12] != 0) && (*(int *)(*param_2 + 8) == 0)) {
    if (piVar1[0x10] == 0) {
      uVar4 = 0x121;
      goto LAB_68109ace;
    }
    piVar1[0x13] = 1;
  }
  uVar4 = xtra_verifyPKCS7CertChain((int)piVar1,*(undefined4 **)(*param_2 + 0x14),puVar2,
                       *(undefined4 *)(*param_2 + 0x1c));
  if (uVar4 != 0) goto LAB_68109ace;
  if (param_2[10] != 0) {
    uVar4 = xtra_initPKCS7Digest((int)piVar1);
    if (uVar4 != 0) goto LAB_68109ace;
  }
  uVar4 = xtra_readPKCS7ContentInfo((undefined4 *)piVar1[0x15],param_2 + 10,puVar2);
  if (uVar4 != 0) goto LAB_68109ace;
  if (param_2[10] != 0) {
    uVar4 = xtra_buildCRLDistributionPoint(&local_3c,&local_38,&local_34,(undefined4 *)piVar1[0x15],&DAT_6818f7f0,9,0,
                         puVar2);
    if (uVar4 != 0) goto LAB_68109ace;
    if (local_3c != 4) {
      uVar4 = 0x10a;
      goto LAB_68109ace;
    }
    if (piVar1[0x13] == 0) {
      local_50 = xtra_encryptDataEx(*piVar1,local_28,&local_4c,0x14,*(undefined4 *)(*param_2 + 0x1c));
      if (local_50 != 0) goto LAB_68109ace;
      if (local_4c == local_34) {
        uVar4 = display_decodeFormat(local_38,local_28,local_4c);
        if (uVar4 == 0) goto LAB_68109938;
      }
    }
    else {
      iVar5 = *(int *)(*param_2 + 0xc);
      iVar5 = (**(code **)(iVar5 + 0x10))(local_38,local_34,*(undefined4 *)(iVar5 + 0x14));
      if (iVar5 != 0) {
        uVar4 = 0x141;
        goto LAB_68109ace;
      }
LAB_68109938:
      uVar4 = xtra_parsePKCS7OID(&local_40,(undefined4 *)piVar1[0x15],puVar2);
      if (uVar4 != 0) goto LAB_68109ace;
      if (local_40 == 1) {
        uVar4 = xtra_writeBEREnvelopedData(&iStack_30,&iStack_2c,(undefined4 *)piVar1[0x15],puVar2);
        if (uVar4 != 0) goto LAB_68109ace;
        local_50 = xtra_decryptData(*piVar1,iStack_30,iStack_2c,*(undefined4 *)(*param_2 + 0x1c));
        if (local_50 != 0) goto LAB_68109ace;
        goto LAB_681099a7;
      }
    }
    goto LAB_68109ac9;
  }
LAB_681099a7:
  uVar4 = display_getNetSecurityState(&local_48);
  if (uVar4 != 0) goto LAB_68109ace;
  iVar5 = xtra_signPKCS7Data(local_48,param_2 + 0xc,(int *)&PTR_LAB_6818fc70);
  if (iVar5 != 0) {
    uVar4 = xtra_decodeBER("reading digest encryption algorithm",iVar5,0x10a,puVar2);
    goto LAB_68109ace;
  }
  uVar4 = (**(code **)(piVar1[0xf] + 4))
                    (piVar1,abStack_14,&uStack_44,0x14,param_2 + 4,param_2 + 6,local_48,param_2[0xe]
                     ,param_2[0xf],*(undefined4 *)(*param_2 + 0x14),puVar2,
                     *(undefined4 *)(*param_2 + 0x1c));
  if (uVar4 != 0) goto LAB_68109ace;
  if ((piVar1[0x13] == 0) || (param_2[10] != 0)) {
    local_50 = xtra_encryptDataEx(*piVar1,local_28,&local_4c,0x14,*(undefined4 *)(*param_2 + 0x1c));
    if (local_50 != 0) goto LAB_68109ace;
    if (local_4c == uStack_44) {
      uVar4 = display_decodeFormat(abStack_14,local_28,local_4c);
      if (uVar4 == 0) goto LAB_68109aad;
    }
LAB_68109ac9:
    uVar4 = 0x125;
  }
  else {
    iVar5 = (**(code **)(*(int *)(*param_2 + 0xc) + 0x10))
                      (abStack_14,uStack_44,*(undefined4 *)(*(int *)(*param_2 + 0xc) + 0x14));
    if (iVar5 != 0) {
      uVar4 = 0x141;
      goto LAB_68109ace;
    }
LAB_68109aad:
    uVar4 = xtra_readPKCS7ContentInfo((undefined4 *)piVar1[0x14],param_2 + 0x10,puVar2);
    if (uVar4 == 0) {
      param_2[2] = param_2[2] + 1;
    }
  }
LAB_68109ace:
  display_initNetworkSecurity(&local_48);
  display_fillMemory(local_28,0,0x14);
  display_fillMemory(abStack_14,0,0x14);
  if (local_50 != 0) {
    uVar4 = xtra_decodeBERDirect("decoding signer info",local_50,0x112,puVar2);
    return uVar4;
  }
  return uVar4;
}



// ============================================================
// Function: xtra_finalizePKCS7Processing (FUN_68109b30)
// Address: 68109b30
// Size: 163 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_finalizePKCS7Processing(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint local_4;
  
  piVar1 = (int *)*param_1;
  param_1[3] = 1;
  if (*(int *)(*piVar1 + 0x48) == 0) {
    return 0;
  }
  if (piVar1[2] == 0) {
    return 0;
  }
  do {
    iVar2 = (**(code **)(piVar1[2] + 8))
                      (param_1[4] + 0x18,&local_4,param_1[5] + -0x18,
                       *(undefined4 *)(piVar1[2] + 0x14));
    if (iVar2 != 0) {
      if (iVar2 != 0x118) {
        return 0x121;
      }
      uVar3 = xtra_updatePKCS7Buffer(param_1);
      return (uVar3 == 0) - 1 & uVar3;
    }
    uVar3 = xtra_buildPKCS7EncryptedContent(param_1,param_1[4] + 0x18,local_4);
  } while (uVar3 == 0);
  return uVar3;
}



// ============================================================
// Function: xtra_parsePKCS7OID (FUN_68109be0)
// Address: 68109be0
// Size: 115 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_parsePKCS7OID(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = xtra_buildCRLDistributionPoint(&local_c,&local_8,&local_4,param_2,&DAT_6818f7e0,9,0,param_3);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER("getting content type attribute",iVar1,0x10a,param_3);
    return iVar1;
  }
  if (local_c != 6) {
    return 0x10a;
  }
  iVar1 = xtra_lookupPKCS7ContentType(param_1,&local_8);
  return iVar1;
}



// ============================================================
// Function: xtra_buildPKCS7EncryptedContent (FUN_68109c60)
// Address: 68109c60
// Size: 289 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_buildPKCS7EncryptedContent(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_c;
  uint local_8;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  piVar2 = (int *)*param_1;
  do {
    if (param_3 == 0) {
LAB_68109d52:
      if (iVar5 == 0) {
        return local_4;
      }
LAB_68109d56:
      iVar5 = xtra_decodeBERDirect("processing enhanced text stream",iVar5,0x112,
                           (undefined4 *)piVar2[6]);
      return iVar5;
    }
    iVar6 = param_2;
    local_c = param_3;
    uVar1 = param_3;
    if (*(int *)(*piVar2 + 8) != 0) {
      uVar1 = param_1[5] - 0x18;
      if (uVar1 < param_3) {
        local_c = uVar1;
      }
      iVar5 = xtra_dispatchDecrypt8(*(int *)(*piVar2 + 8),param_1[4],&local_8,param_1[5],param_2,local_c,0,
                           piVar2[7]);
      if (iVar5 != 0) goto LAB_68109d56;
      iVar6 = param_1[4];
      uVar1 = local_8;
    }
    local_8 = uVar1;
    if ((*(int *)*piVar2 != 0) &&
       (iVar5 = xtra_decryptData(*(int *)*piVar2,iVar6,local_8,piVar2[7]), iVar5 != 0))
    goto LAB_68109d56;
    iVar4 = piVar2[3];
    if ((iVar4 != 0) &&
       (iVar4 = (**(code **)(iVar4 + 0x10))(iVar6,local_8,*(undefined4 *)(iVar4 + 0x14)), iVar4 != 0
       )) {
      local_4 = 0x141;
      goto LAB_68109d52;
    }
    puVar3 = (undefined4 *)piVar2[1];
    if ((puVar3 != (undefined4 *)0x0) &&
       (local_4 = (**(code **)*puVar3)(puVar3,iVar6,local_8,piVar2), local_4 != 0))
    goto LAB_68109d52;
    param_2 = param_2 + local_c;
    param_3 = param_3 - local_c;
  } while( true );
}



// ============================================================
// Function: xtra_updatePKCS7Buffer (FUN_68109d90)
// Address: 68109d90
// Size: 208 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_updatePKCS7Buffer(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_4;
  
  iVar5 = 0;
  uVar4 = 0;
  piVar1 = (int *)*param_1;
  if (*(int *)(*piVar1 + 8) != 0) {
    iVar5 = xtra_dispatchDecrypt6(*(int *)(*piVar1 + 8),param_1[4],&local_4,param_1[5],0,piVar1[7]);
    if (iVar5 == 0) {
      if (*(int *)*piVar1 != 0) {
        iVar5 = xtra_decryptData(*(int *)*piVar1,param_1[4],local_4,piVar1[7]);
        if (iVar5 != 0) goto LAB_68109e33;
      }
      iVar3 = piVar1[3];
      if (iVar3 != 0) {
        iVar3 = (**(code **)(iVar3 + 0x10))(param_1[4],local_4,*(undefined4 *)(iVar3 + 0x14));
        if (iVar3 != 0) {
          uVar4 = 0x141;
          goto LAB_68109e33;
        }
      }
      puVar2 = (undefined4 *)piVar1[1];
      if (puVar2 != (undefined4 *)0x0) {
        uVar4 = (**(code **)*puVar2)(puVar2,param_1[4],local_4,piVar1);
      }
    }
  }
LAB_68109e33:
  if (iVar5 != 0) {
    uVar4 = xtra_decodeBERDirect("finalizing enhanced text stream",iVar5,0x112,
                         (undefined4 *)piVar1[6]);
    return uVar4;
  }
  return uVar4;
}



// ============================================================
// Function: xtra_resetPKCS7State (FUN_68109e60)
// Address: 68109e60
// Size: 27 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetPKCS7State(void *param_1)
{
  display_fillMemory(param_1,0,0x2c);
  *(undefined ***)((int)param_1 + 0x3c) = &PTR_FUN_6818fdd8;
  return 0;
}



// ============================================================
// Function: xtra_clearPKCS7State (FUN_68109e80)
// Address: 68109e80
// Size: 76 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearPKCS7State(undefined4 *param_1)
{
  display_initNetworkSecurity(param_1);
  display_releaseNetSecurity(param_1 + 1);
  display_initNetworkSecurity(param_1 + 2);
  xtra_initCryptoContext(param_1 + 3);
  xtra_initCryptoContext(param_1 + 4);
  display_releaseFormatData(param_1 + 10);
  return 0;
}



// ============================================================
// Function: xtra_createPKCS7Session (FUN_68109f30)
// Address: 68109f30
// Size: 272 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 * param_3, int param_4, int param_5, int * param_6, int param_7, undefined4 param_8, undefined4 param_9, undefined4 * param_10, undefined4 param_11
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_createPKCS7Session(undefined4 *param_1,int *param_2,undefined4 *param_3,int param_4,int param_5,
            int *param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 *param_10,
            undefined4 param_11)
{
  int iVar1;
  undefined4 *local_8;
  undefined4 *local_4;
  
  iVar1 = display_getEncodedEntry(&local_8,(undefined4 *)param_1[0xb],param_1[0xc]);
  if (iVar1 == 0) {
    iVar1 = display_loadFormatData(param_4,*(undefined **)(local_8[4] + 0x10),0);
    if (iVar1 != 0) {
      xtra_decodeBERDirect("setting private algorithm",iVar1,0x112,param_10);
      return 0;
    }
    iVar1 = xtra_verifyCertSignature(param_4,param_5,param_6,param_7,param_8,param_9,(int *)*param_1,local_8[8],
                         param_10,param_11);
    if (iVar1 == 0) {
      if ((param_1[2] != 0) &&
         (iVar1 = xtra_computeDigestValue(param_1[2],param_5,param_6,param_7,param_5,*param_6,0,param_10,
                               param_11), iVar1 != 0)) {
        return 0;
      }
      iVar1 = xtra_getCertEntry(&local_4,param_3,param_3 + 1,(undefined4 *)*local_8,0,param_10);
      if (iVar1 == 0) {
        display_resolveEncoder(param_2,param_2 + 1,local_4,param_10);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_openPKCS7Session (FUN_6810a280)
// Address: 6810a280
// Size: 580 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3, int param_4, int param_5, uint * param_6, int param_7, uint param_8, int param_9, undefined4 * param_10, undefined4 param_11
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
xtra_openPKCS7Session(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,int param_5,
            uint *param_6,int param_7,uint param_8,int param_9,undefined4 *param_10,
            undefined4 param_11)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *local_24;
  int local_20;
  undefined4 *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  uint local_4;
  
  iVar3 = 0;
  uVar2 = display_getCertChainCount(&local_4,*(undefined4 **)(param_1 + 0x34));
  if (uVar2 == 0) {
    if (param_8 < local_4) {
      uVar2 = display_getCertChainEntry(&local_24,*(undefined4 **)(param_1 + 0x34),param_8);
      if (uVar2 != 0) {
        return uVar2;
      }
    }
    else {
      *param_2 = 0;
      if (*(undefined4 **)(param_1 + 0x2c) == (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = display_getEncodedEntry(&local_c,*(undefined4 **)(param_1 + 0x2c),*(uint *)(param_1 + 0x30));
      if (uVar2 != 0) {
        return uVar2;
      }
      if (local_c[7] == 0) {
        return 0;
      }
      local_24 = local_c;
    }
    uVar2 = xtra_getCertListEntry(&local_8,(undefined4 *)*local_24,0);
    if ((uVar2 == 0) && (uVar2 = display_decryptFormatData(&local_10,local_8,param_10), uVar2 == 0)) {
      uVar1 = *(undefined4 *)(local_10 + 0x18);
      *param_2 = *(undefined4 *)(local_10 + 0x14);
      param_2[1] = uVar1;
      uVar1 = *(undefined4 *)(local_10 + 8);
      *param_3 = *(undefined4 *)(local_10 + 4);
      param_3[1] = uVar1;
      iVar3 = display_loadFormatData(param_4,*(undefined **)(local_24[4] + 0xc),0);
      if (iVar3 != 0) goto LAB_6810a49a;
      uVar2 = xtra_encodePKCS7Attributes(&local_20,&local_18,&local_14,(int *)local_24[3],
                           *(undefined4 **)(param_1 + 0x28));
      if (uVar2 == 0) {
        if (local_14 == 0) {
          iVar3 = display_loadCertChainData((int *)&local_1c,*(int **)(param_1 + 4),&LAB_6810d0b0);
          if (iVar3 != 0) goto LAB_6810a49a;
          uVar2 = xtra_verifyDigestSignature(param_4,local_24[3],param_5,(int *)param_6,param_7,*local_1c,
                               local_1c[1],param_9,param_10,param_11);
          if ((uVar2 == 0) && (local_20 != 0)) {
            uVar2 = xtra_decodePKCS7Attributes((int *)(param_1 + 0x28),local_20,param_5,*param_6);
          }
        }
        else {
          display_checkAndFree(param_5,local_14,local_18);
          *param_6 = local_18;
        }
      }
    }
    if (iVar3 != 0) {
LAB_6810a49a:
      uVar2 = xtra_decodeBERDirect("computing recipient info",iVar3,0x112,param_10);
      return uVar2;
    }
  }
  return uVar2;
}



// ============================================================
// Function: xtra_closePKCS7Session (FUN_6810a4d0)
// Address: 6810a4d0
// Size: 1500 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_closePKCS7Session(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *local_48;
  undefined4 *local_44;
  int local_40;
  undefined4 *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  uint *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8 [2];
  
  local_18 = (int *)0x0;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  display_freeFormatState((int *)&local_24);
  iVar1 = display_parseFormatBlock((int *)&local_20,*(undefined4 **)(param_1 + 0x34));
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(undefined4 **)(param_1 + 0xc) == (undefined4 *)0x0) {
    local_28 = (int *)0x0;
  }
  else {
    iVar1 = xtra_parseCertificate(&local_28,*(undefined4 **)(param_1 + 0xc));
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if (*(undefined4 **)(param_1 + 0x10) == (undefined4 *)0x0) {
    local_2c = 0;
  }
  else {
    iVar1 = xtra_parseCertificate(&local_2c,*(undefined4 **)(param_1 + 0x10));
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = 0;
  local_14 = (int *)display_allocBlock((int)local_28 << 2);
  if (local_14 == (int *)0x0) {
    iVar1 = 0x100;
  }
  else {
    piVar4 = (int *)0x0;
    piVar3 = local_14;
    if (local_28 != (int *)0x0) {
      do {
        *piVar3 = 0;
        piVar4 = (int *)((int)piVar4 + 1);
        piVar3 = piVar3 + 1;
      } while (piVar4 < local_28);
    }
    local_18 = (int *)display_allocBlock(local_2c << 2);
    if (local_18 == (int *)0x0) {
      iVar1 = 0x100;
    }
    else {
      uVar5 = 0;
      piVar3 = local_18;
      if (local_2c != 0) {
        do {
          *piVar3 = 0;
          uVar5 = uVar5 + 1;
          piVar3 = piVar3 + 1;
        } while (uVar5 < local_2c);
      }
      do {
        local_40 = 0;
        local_38 = (int *)0x0;
        piVar3 = local_14;
        if (local_28 != (int *)0x0) {
LAB_6810a624:
          if (*piVar3 != 0) goto LAB_6810a85d;
          iVar1 = strftime(&local_48,(undefined4 *)0x0,*(undefined4 **)(param_1 + 0xc),
                           (int)local_28 + (-1 - (int)local_38));
          if (iVar1 != 0) break;
          iVar1 = xtra_verifySelfSignedCert(&local_1c,local_48,param_3,param_4);
          if (iVar1 == 0) {
            if (local_1c != 0) {
              *piVar3 = 1;
              local_40 = 1;
              iVar1 = xtra_createContainerEx(local_48,0,param_2,param_3);
              if (iVar1 != 0) {
                iVar1 = xtra_readBERValue("inserting self-signed certificate from message",iVar1,param_3);
                goto joined_r0x6810a840;
              }
              goto LAB_6810a85d;
            }
            iVar1 = xtra_decodeCertPublicKey(&local_c,&local_10,local_48,local_24,local_20,param_2,param_3,
                                 param_4);
            if (iVar1 == 0) {
              local_40 = 1;
              *piVar3 = 1;
              iVar1 = 0;
              goto LAB_6810a85d;
            }
            iVar1 = xtra_readBERValue("selecting certificate status",iVar1,param_3);
            if (iVar1 != 0) break;
            iVar1 = display_decryptFormatData(&local_30,local_48,param_3);
            if (iVar1 == 0) {
              iVar1 = display_getObjectBlockData(local_8,local_48,param_3);
              if (iVar1 == 0) {
                iVar1 = display_getObjectExtension(&local_3c,local_48,param_3);
                if (iVar1 != 0) {
                  iVar1 = xtra_readBERValue("getting certificate signature",iVar1,param_3);
                  goto joined_r0x6810a840;
                }
                iVar1 = xtra_finalizePKCS7Digest((undefined4 *)(local_30 + 0x14),local_8,local_30 + 0xc,local_3c
                                     ,(int)param_2,param_3,param_4);
                if (iVar1 == 0) {
                  *piVar3 = 1;
                  local_40 = 1;
                  iVar1 = xtra_createContainerEx(local_48,0,param_2,param_3);
                  if (iVar1 != 0) {
                    iVar1 = xtra_readBERValue("inserting certificate from message",iVar1,param_3);
                    goto joined_r0x6810a840;
                  }
                  goto LAB_6810a85d;
                }
                iVar1 = xtra_readBERValue("verifying cert in message by issuer self-signed cert",iVar1,param_3);
                if (iVar1 != 0) break;
                goto LAB_6810a85d;
              }
              iVar1 = xtra_readBERValue("getting certificate info DER",iVar1,param_3);
            }
            else {
              iVar1 = xtra_readBERValue("getting certificate information",iVar1,param_3);
            }
          }
          else {
            iVar1 = xtra_readBERValue("checking self signed certificate",iVar1,param_3);
          }
joined_r0x6810a840:
          if (iVar1 != 0) goto LAB_6810a872;
LAB_6810a85d:
          local_38 = (int *)((int)local_38 + 1);
          piVar3 = piVar3 + 1;
          if (local_28 <= local_38) goto LAB_6810a872;
          goto LAB_6810a624;
        }
LAB_6810a872:
        if (iVar1 != 0) break;
        uVar5 = 0;
        if (local_2c != 0) {
          do {
            iVar1 = strftime(&local_44,(undefined4 *)0x0,*(undefined4 **)(param_1 + 0x10),
                             (local_2c - uVar5) - 1);
            if (iVar1 != 0) break;
            local_38 = local_18 + uVar5;
            if (*local_38 == 0) {
              iVar1 = xtra_verifyCRLSignature(local_44,local_24,local_20,(int)param_2,param_3,param_4);
              if (iVar1 == 0) {
LAB_6810a9e0:
                local_40 = 1;
                *local_38 = 1;
                iVar2 = xtra_insertCRLEntry(local_44,0,(int)param_2,param_3);
                iVar1 = 0;
                if (iVar2 == 0) goto LAB_6810aa1e;
                iVar1 = xtra_readBERValue("inserting CRL from message",iVar2,param_3);
              }
              else {
                iVar1 = xtra_readBERValue("checking status of CRL in message",iVar1,param_3);
                if (iVar1 != 0) break;
                iVar1 = xtra_finalizeCrypto(&local_34,local_44,param_3);
                if (iVar1 == 0) {
                  iVar1 = xtra_extractPublicKeyData(local_8,local_44,param_3);
                  if (iVar1 == 0) {
                    iVar1 = xtra_extractCertPublicKey(&local_3c,local_44,param_3);
                    if (iVar1 != 0) {
                      iVar1 = xtra_readBERValue("getting crl signature",iVar1,param_3);
                      if (iVar1 == 0) goto LAB_6810aa1e;
                      break;
                    }
                    iVar1 = xtra_finalizePKCS7Digest((undefined4 *)(local_34 + 8),local_8,local_34,local_3c,
                                         (int)param_2,param_3,param_4);
                    if (iVar1 == 0) goto LAB_6810a9e0;
                    iVar1 = xtra_readBERValue("verifying CRL in message by issuer self-signed cert",iVar1,param_3);
                  }
                  else {
                    iVar1 = xtra_readBERValue("getting CRL inner DER",iVar1,param_3);
                  }
                }
                else {
                  iVar1 = xtra_readBERValue("getting CRL info",iVar1,param_3);
                }
              }
              if (iVar1 != 0) break;
            }
LAB_6810aa1e:
            uVar5 = uVar5 + 1;
          } while (uVar5 < local_2c);
        }
      } while (local_40 != 0);
    }
  }
  piVar4 = (int *)0x0;
  piVar3 = local_14;
  if (local_28 != (int *)0x0) {
    do {
      if (*piVar3 == 0) {
        *(undefined4 *)(param_1 + 0x18) = 1;
        break;
      }
      piVar4 = (int *)((int)piVar4 + 1);
      piVar3 = piVar3 + 1;
    } while (piVar4 < local_28);
  }
  if ((iVar1 == 0) && (uVar5 = 0, piVar3 = local_18, local_2c != 0)) {
    do {
      if (*piVar3 == 0) {
        *(undefined4 *)(param_1 + 0x1c) = 1;
        break;
      }
      uVar5 = uVar5 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar5 < local_2c);
  }
  display_freeIfNonNull((int)local_18);
  display_freeIfNonNull((int)local_14);
  return iVar1;
}



// ============================================================
// Function: xtra_verifyPKCS7CertChain (FUN_6810aab0)
// Address: 6810aab0
// Size: 871 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_verifyPKCS7CertChain(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *local_34;
  int local_30;
  undefined4 *local_2c;
  int *local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint *local_18;
  int local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  int local_4;
  
  local_10 = (undefined4 *)0x0;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  display_freeFormatState((int *)&local_1c);
  iVar1 = display_parseFormatBlock((int *)&local_18,*(undefined4 **)(param_1 + 0x34));
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(undefined4 **)(param_1 + 0xc) == (undefined4 *)0x0) {
    local_20 = 0;
  }
  else {
    iVar1 = xtra_parseCertificate(&local_20,*(undefined4 **)(param_1 + 0xc));
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if (*(undefined4 **)(param_1 + 0x10) == (undefined4 *)0x0) {
    local_24 = 0;
  }
  else {
    iVar1 = xtra_parseCertificate(&local_24,*(undefined4 **)(param_1 + 0x10));
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = 0;
  local_c = (undefined4 *)display_allocBlock(local_20 << 2);
  if (local_c == (undefined4 *)0x0) {
    iVar1 = 0x100;
  }
  else {
    uVar2 = 0;
    puVar4 = local_c;
    if (local_20 != 0) {
      do {
        *puVar4 = 0;
        uVar2 = uVar2 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar2 < local_20);
    }
    local_10 = (undefined4 *)display_allocBlock(local_24 << 2);
    if (local_10 == (undefined4 *)0x0) {
      iVar1 = 0x100;
    }
    else {
      uVar2 = 0;
      puVar4 = local_10;
      if (local_24 != 0) {
        do {
          *puVar4 = 0;
          uVar2 = uVar2 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar2 < local_24);
      }
      do {
        local_30 = 0;
        uVar2 = 0;
        if (local_20 != 0) {
          do {
            local_28 = local_c + uVar2;
            if (*local_28 != 0) goto LAB_6810ad0e;
            iVar1 = strftime(&local_34,(undefined4 *)0x0,*(undefined4 **)(param_1 + 0xc),
                             (local_20 - uVar2) - 1);
            if (iVar1 != 0) goto LAB_6810adf3;
            iVar1 = xtra_verifySelfSignedCert(&local_14,local_34,param_3,param_4);
            if (iVar1 == 0) {
              if (local_14 == 0) {
                iVar1 = xtra_decodeCertPublicKey(&local_4,&local_8,local_34,local_1c,local_18,param_2,param_3,
                                     param_4);
                if (iVar1 != 0) {
                  iVar1 = xtra_readBERValue("selecting certificate status",iVar1,param_3);
                  goto joined_r0x6810acf8;
                }
                local_30 = 1;
                *local_28 = 1;
                iVar1 = 0;
              }
              else {
                local_30 = 1;
                *local_28 = 1;
                iVar1 = xtra_createContainerEx(local_34,0,param_2,param_3);
                if (iVar1 != 0) {
                  iVar1 = xtra_readBERValue("inserting self-signed certificate from message",iVar1,param_3);
                  goto joined_r0x6810acf8;
                }
              }
            }
            else {
              iVar1 = xtra_readBERValue("checking self signed certificate",iVar1,param_3);
joined_r0x6810acf8:
              if (iVar1 != 0) break;
            }
LAB_6810ad0e:
            uVar2 = uVar2 + 1;
          } while (uVar2 < local_20);
        }
        if (iVar1 != 0) break;
        uVar2 = 0;
        if (local_24 != 0) {
          do {
            iVar1 = strftime(&local_2c,(undefined4 *)0x0,*(undefined4 **)(param_1 + 0x10),
                             (local_24 - uVar2) - 1);
            if (iVar1 != 0) break;
            local_28 = local_10 + uVar2;
            if (*local_28 == 0) {
              iVar1 = xtra_verifyCRLSignature(local_2c,local_1c,local_18,(int)param_2,param_3,param_4);
              if (iVar1 == 0) {
                local_30 = 1;
                *local_28 = 1;
                iVar3 = xtra_insertCRLEntry(local_2c,0,(int)param_2,param_3);
                iVar1 = 0;
                if (iVar3 == 0) goto LAB_6810addd;
                iVar1 = xtra_readBERValue("inserting CRL from message",iVar3,param_3);
              }
              else {
                iVar1 = xtra_readBERValue("checking status of CRL in message",iVar1,param_3);
              }
              if (iVar1 != 0) break;
            }
LAB_6810addd:
            uVar2 = uVar2 + 1;
          } while (uVar2 < local_24);
        }
      } while (local_30 != 0);
    }
  }
LAB_6810adf3:
  display_freeIfNonNull((int)local_10);
  display_freeIfNonNull((int)local_c);
  return iVar1;
}



// ============================================================
// Function: xtra_signPKCS7Data (FUN_6810b2c0)
// Address: 6810b2c0
// Size: 67 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_signPKCS7Data(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  while( true ) {
    if (iVar1 == 0) {
      return 0x21d;
    }
    iVar1 = display_loadFormatData(param_1,(undefined *)*param_3,param_2);
    if (iVar1 == 0) break;
    if (iVar1 != 0x21d) {
      return iVar1;
    }
    param_3 = param_3 + 1;
    iVar1 = *param_3;
  }
  return 0;
}



// ============================================================
// Function: xtra_updatePKCS7Digest (FUN_6810b310)
// Address: 6810b310
// Size: 67 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_updatePKCS7Digest(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  while( true ) {
    if (iVar1 == 0) {
      return 0x21d;
    }
    iVar1 = display_processNetSecurityOp(param_1,param_2,(undefined *)*param_3);
    if (iVar1 == 0) break;
    if (iVar1 != 0x21d) {
      return iVar1;
    }
    param_3 = param_3 + 1;
    iVar1 = *param_3;
  }
  return 0;
}



// ============================================================
// Function: xtra_finalizePKCS7Digest (FUN_6810b360)
// Address: 6810b360
// Size: 551 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 param_3, undefined4 * param_4, int param_5, undefined4 * param_6, undefined4 param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_finalizePKCS7Digest(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
            int param_5,undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  uint local_8;
  int local_4;
  
  local_14 = (undefined4 *)0x0;
  local_1c = 0;
  local_4 = 0;
  iVar1 = xtra_clearCertList((int *)&local_14);
  if ((iVar1 == 0) && (iVar1 = xtra_addCertsFromStore(local_14,param_1,param_5,param_6), iVar1 == 0)) {
    iVar1 = xtra_parseCertificate(&local_8,local_14);
    if (iVar1 == 0) {
      if (local_8 == 0) {
        iVar1 = xtra_decodeBER("selecting self signed certificate",0,300,param_6);
      }
      else {
        uVar3 = 0;
        iVar1 = 0;
        if (local_8 != 0) {
          do {
            iVar1 = strftime(&local_18,(undefined4 *)0x0,local_14,uVar3);
            if (iVar1 == 0) {
              iVar1 = xtra_verifySelfSignedCert(&local_c,local_18,param_6,param_7);
              if (iVar1 != 0) {
                iVar1 = xtra_readBERValue("checking self signed certificate",iVar1,param_6);
                goto joined_r0x6810b47b;
              }
              iVar1 = 0;
              if (local_c != 0) {
                iVar1 = display_freeNetSecurity(&local_1c);
                if (iVar1 != 0) {
                  iVar1 = 0x100;
                  break;
                }
                iVar1 = display_decryptFormatData(&local_10,local_18,param_6);
                if (iVar1 != 0) {
                  iVar1 = xtra_readBERValue("getting certificate information",iVar1,param_6);
                  goto joined_r0x6810b47b;
                }
                iVar2 = xtra_verifyCertExt(local_1c,(int *)0x0,local_10 + 0x2c,param_6);
                iVar1 = 0;
                if (iVar2 != 0) {
                  iVar1 = xtra_setupCryptoMode(param_2,param_4,param_3,local_1c,param_6,param_7);
                  if (iVar1 == 0) {
                    local_4 = 1;
                    iVar1 = 0;
                    break;
                  }
                  iVar1 = xtra_readBERValue("checking certificate using self signed certificate",iVar1,param_6);
                  if (iVar1 != 0) goto LAB_6810b563;
                }
                display_releaseNetSecurity(&local_1c);
              }
            }
            else {
              iVar1 = xtra_readBERValue("reading certificate list object",iVar1,param_6);
joined_r0x6810b47b:
              if (iVar1 != 0) break;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < local_8);
        }
      }
    }
    else {
      iVar1 = xtra_decodeBER("reading certificate list object",iVar1,0x123,param_6);
    }
  }
  if ((iVar1 == 0) && (local_4 == 0)) {
    iVar1 = 300;
  }
LAB_6810b563:
  display_releaseNetSecurity(&local_1c);
  xtra_initCryptoContext((int *)&local_14);
  return iVar1;
}



// ============================================================
// Function: xtra_encodePKCS7Attributes (FUN_6810b590)
// Address: 6810b590
// Size: 275 bytes
// Params: undefined4 * param_1, uint * param_2, int * param_3, int * param_4, undefined4 * param_5
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
xtra_encodePKCS7Attributes(undefined4 *param_1,uint *param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_14;
  undefined4 *local_10;
  undefined4 local_c;
  uint *local_8 [2];
  
  *param_3 = 0;
  *param_1 = 0;
  iVar1 = display_loadCertChainData((int *)&local_10,param_4,&LAB_681009b0);
  if (iVar1 != 0) {
    return -(uint)(iVar1 == 0x206) & 0x100;
  }
  if ((local_10[3] == 1) && (uVar2 = display_decodeFormat(&DAT_6818fde0,(byte *)local_10[2],1), uVar2 == 0))
  {
    uVar3 = 0;
    uVar4 = 0;
    *param_1 = *local_10;
    uVar2 = local_10[1];
    *param_2 = uVar2;
    if ((param_5 != (undefined4 *)0x0) &&
       ((uVar4 = xtra_getContainerRef(&local_14,param_5), uVar4 == 0 && (local_14 != 0)))) {
      do {
        uVar4 = xtra_queryContainerEx(local_8,&local_c,uVar3,param_5);
        if (uVar4 != 0) {
          return uVar4;
        }
        if ((*local_8[0] == uVar2) &&
           (uVar4 = display_decodeFormat((byte *)*param_1,(byte *)(local_8[0] + 1),uVar2), uVar4 == 0)) {
          *param_3 = (int)local_8[0] + uVar2 + 4;
        }
        uVar3 = uVar3 + 1;
        uVar4 = 0;
      } while (uVar3 < local_14);
    }
    return uVar4;
  }
  return 0;
}



// ============================================================
// Function: xtra_decodePKCS7Attributes (FUN_6810b6b0)
// Address: 6810b6b0
// Size: 138 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decodePKCS7Attributes(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *local_4;
  
  if ((*param_1 == 0) && (iVar1 = xtra_destroyContainer(param_1), iVar1 != 0)) {
    return 0;
  }
  iVar1 = param_4 * 2 + 4;
  iVar2 = xtra_writeBERTagEx((int *)&local_4,iVar1,*param_1);
  if (iVar2 == 0) {
    *local_4 = param_4;
    display_checkAndFree(local_4 + 1,param_2,param_4);
    display_checkAndFree((int)local_4 + param_4 + 4,param_3,param_4);
    xtra_getContainerData((undefined4 *)*param_1,local_4,iVar1,0);
  }
  return 0;
}



