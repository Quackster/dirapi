// Module: sprites
// Topic: Member data access, string properties, and cast member operations
// Address range: 0x68071DE0 - 0x68073020
// Functions (49):
//   sprites_navigateToMember
//   sprites_getMemberType
//   sprites_getMemberByIndex
//   sprites_getMemberCount
//   sprites_getMemberByChannel
//   sprites_getMemberName
//   sprites_setMemberName
//   sprites_getMemberComment
//   sprites_setMemberComment
//   sprites_getMemberFlag
//   sprites_setMemberFlag
//   sprites_setMemberScript
//   sprites_getMemberInfo
//   sprites_validateMemberRef
//   sprites_dispatchMemberOp
//   sprites_convertToString
//   sprites_setMemberHilite
//   sprites_registerMemberAsset
//   sprites_getMemberData
//   sprites_getMemberPurge
//   sprites_getMemberCastType1
//   sprites_getMemberCastType2
//   sprites_getMemberCastType3
//   sprites_getMemberCastType4
//   sprites_getMemberCastType5
//   sprites_getMemberCastType6
//   sprites_getMemberCastType7
//   sprites_resolveMemberByType
//   sprites_resetMember
//   sprites_findMemberByScript
//   sprites_findMemberByBitmap
//   sprites_findMemberByField
//   sprites_getMemberRegPoint
//   sprites_clearMemberRef
//   sprites_setMemberFrameIndex
//   sprites_getMemberNameById
//   sprites_getMemberFileName
//   sprites_registerMemberMedia
//   sprites_extractMemberData
//   sprites_setMemberPurge
//   sprites_getMemberPurgeFlag
//   sprites_findMemberByName
//   sprites_getMemberField
//   sprites_setMemberField
//   sprites_getMemberModified
//   sprites_setMemberModified
//   sprites_updateMemberScript
//   sprites_isMemberLoaded
//   sprites_deleteMember


// ============================================================
// Function: sprites_navigateToMember (FUN_68071de0)
// Address: 68071de0
// Size: 162 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_navigateToMember(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  sprites_getEventData(param_1,&local_38);
  if (*(int *)(DAT_681962f8 + 0xc) != 0) {
    return 0;
  }
  local_30 = local_34;
  local_2c = local_38;
  iVar2 = Ordinal_184(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_28,local_18);
  if (iVar2 != 0) {
    Ordinal_1072(&local_30,local_28,local_18);
  }
  Ordinal_382(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),local_30,local_2c,param_2);
  return 0;
}



// ============================================================
// Function: sprites_getMemberType (FUN_68071e90)
// Address: 68071e90
// Size: 44 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 sprites_getMemberType(int param_1)

{
  int iVar1;
  undefined2 local_1c [12];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),4,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: sprites_getMemberByIndex (FUN_68071ec0)
// Address: 68071ec0
// Size: 53 bytes
// Params: uint param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_getMemberByIndex(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_353(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2 + 1,
                      (undefined2 *)&param_1);
  if (iVar1 != 0) {
    return CONCAT22((short)((uint)iVar1 >> 0x10),(undefined2)param_1);
  }
  return 0xffffffff;
}



// ============================================================
// Function: sprites_getMemberCount (FUN_68071f00)
// Address: 68071f00
// Size: 70 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_getMemberCount(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 extraout_var;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  uVar2 = 0;
  local_1c = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),2,(double *)&local_1c);
    uVar2 = CONCAT22(extraout_var,(undefined2)local_1c);
  }
  return uVar2;
}



// ============================================================
// Function: sprites_getMemberByChannel (FUN_68071f50)
// Address: 68071f50
// Size: 81 bytes
// Params: int param_1, short param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberByChannel(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short local_14 [8];
  
  iVar1 = (*(int **)(param_1 + 8))[1];
  iVar2 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  if (param_2 == 0) {
    param_2 = 1;
  }
  sVar3 = Ordinal_364(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_347(*(int *)(iVar2 + 8),sVar3,3,(uint *)local_14);
  return (int)local_14[0];
}



// ============================================================
// Function: sprites_getMemberName (FUN_68071fb0)
// Address: 68071fb0
// Size: 113 bytes
// Params: int param_1, short param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberName(int param_1,short param_2,undefined1 *param_3)
{
  int iVar1;
  undefined1 *local_c;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_8 = 0x3ff;
  local_c = param_3 + 1;
  iVar1 = Ordinal_351(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,1,&local_c);
  if (iVar1 == 0) {
    param_3[1] = 0;
    *param_3 = 0;
    return 0;
  }
  param_3[local_8 + 1] = 0;
  if (local_8 < 0xff) {
    *param_3 = (char)local_8;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: sprites_setMemberName (FUN_68072030)
// Address: 68072030
// Size: 79 bytes
// Params: int param_1, short param_2, byte * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberName(int param_1,short param_2,byte *param_3)
{
  int iVar1;
  ushort uVar2;
  byte *local_c;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_c = param_3 + 1;
  if (*param_3 == 0xff) {
    uVar2 = Ordinal_1201(local_c);
  }
  else {
    uVar2 = (ushort)*param_3;
  }
  local_8 = (int)(short)uVar2;
  Ordinal_352(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,1,(int *)&local_c);
  return 0;
}



// ============================================================
// Function: sprites_getMemberComment (FUN_68072080)
// Address: 68072080
// Size: 113 bytes
// Params: int param_1, short param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberComment(int param_1,short param_2,undefined1 *param_3)
{
  int iVar1;
  undefined1 *local_c;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_8 = 0x3ff;
  local_c = param_3 + 1;
  iVar1 = Ordinal_351(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,2,&local_c);
  if (iVar1 == 0) {
    param_3[1] = 0;
    *param_3 = 0;
    return 0;
  }
  param_3[local_8 + 1] = 0;
  if (local_8 < 0xff) {
    *param_3 = (char)local_8;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: sprites_setMemberComment (FUN_68072100)
// Address: 68072100
// Size: 99 bytes
// Params: int param_1, short param_2, byte * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_setMemberComment(int param_1,short param_2,byte *param_3)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  byte *local_c;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_c = param_3 + 1;
  if (*param_3 == 0xff) {
    uVar2 = Ordinal_1201(local_c);
  }
  else {
    uVar2 = (ushort)*param_3;
  }
  local_8 = (int)(short)uVar2;
  uVar3 = Ordinal_352(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,2,(int *)&local_c);
  Ordinal_104(*(int *)(iVar1 + 0x20),0x1000);
  return uVar3;
}



// ============================================================
// Function: sprites_getMemberFlag (FUN_68072170)
// Address: 68072170
// Size: 51 bytes
// Params: int param_1, short param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_getMemberFlag(int param_1,short param_2)

{
  int iVar1;
  uint local_c [2];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_351(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,3,local_c);
  return -(uint)(iVar1 != 0) & local_c[0];
}



// ============================================================
// Function: sprites_setMemberFlag (FUN_680721b0)
// Address: 680721b0
// Size: 50 bytes
// Params: int param_1, short param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberFlag(int param_1,short param_2,int param_3)
{
  int iVar1;
  int local_c [2];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_c[0] = param_3;
  Ordinal_352(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,3,local_c);
  return 0;
}



// ============================================================
// Function: sprites_setMemberScript (FUN_680721f0)
// Address: 680721f0
// Size: 128 bytes
// Params: int param_1, short param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberScript(int param_1,short param_2,int param_3)
{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  sVar1 = Ordinal_364(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2);
  if (param_3 == 0) {
    iVar2 = *(int *)(iVar2 + 0x20);
    puVar3 = (undefined4 *)0x0;
  }
  else {
    Ordinal_1309(local_420,0x400,param_3 + 1,2);
    iVar2 = *(int *)(iVar2 + 0x20);
    puVar3 = local_420;
  }
  Ordinal_346(iVar2,sVar1,puVar3,(void *)0x0);
  return 0;
}



// ============================================================
// Function: sprites_getMemberInfo (sprites_getMemberInfo)
// Address: 68072270
// Size: 58 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getMemberInfo(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: sprites_validateMemberRef (FUN_680722b0)
// Address: 680722b0
// Size: 39 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_validateMemberRef(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  
  sVar1 = (short)((uint)param_2 >> 0x10);
  if ((0 < sVar1) && (sVar1 < 0x7d01)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchMemberOp (FUN_680722e0)
// Address: 680722e0
// Size: 30 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMemberOp(int param_1,undefined4 param_2)
{
  Ordinal_291(*(undefined4 **)**(undefined4 **)(*(int *)(param_1 + 8) + 4),param_2);
  return 0;
}



// ============================================================
// Function: sprites_convertToString (FUN_68072300)
// Address: 68072300
// Size: 163 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_convertToString(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int local_8;
  
  local_8 = 0;
  iVar3 = 0;
  if (param_1 != 0) {
    Ordinal_1112(param_1);
    local_8 = Ordinal_1120(param_1,0);
    Ordinal_1113(&param_1);
    iVar3 = local_8;
    if (local_8 != 0) {
      iVar1 = Ordinal_1116(local_8);
      iVar2 = Ordinal_1114(local_8);
      iVar3 = local_8;
      if (iVar2 != 0) {
        if (iVar1 < 1) {
          bVar4 = false;
        }
        else {
          bVar4 = *(char *)(iVar2 + -1 + iVar1) == '\0';
        }
        Ordinal_1115(local_8);
        iVar3 = local_8;
        if ((!bVar4) && (iVar2 = Ordinal_1117(&local_8,iVar1 + 1,0), iVar3 = local_8, iVar2 != 0)) {
          iVar3 = Ordinal_1114(local_8);
          *(undefined1 *)(iVar3 + iVar1) = 0;
          Ordinal_1115(local_8);
          iVar3 = local_8;
        }
      }
    }
  }
  return iVar3;
}




// ============================================================
// Function: sprites_setMemberHilite (FUN_680723b0)
// Address: 680723b0
// Size: 70 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberHilite(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x31,local_20);
  return 0;
}



// ============================================================
// Function: sprites_registerMemberAsset (FUN_68072400)
// Address: 68072400
// Size: 57 bytes
// Params: int param_1, undefined4 * param_2, uint param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_registerMemberAsset(int param_1,undefined4 *param_2,uint param_3,int param_4,int param_5)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  media_notifyTextChange(*(int *)(iVar1 + 0x20),uVar2,param_5,param_3,param_4);
  return 0;
}



// ============================================================
// Function: sprites_getMemberData (FUN_68072440)
// Address: 68072440
// Size: 116 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberData(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  if ((local_20[0] != 3) && (local_20[0] != 7)) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberPurge (FUN_680724c0)
// Address: 680724c0
// Size: 74 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberPurge(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = 0;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x7a,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType1 (FUN_68072510)
// Address: 68072510
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType1(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType2 (FUN_68072570)
// Address: 68072570
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType2(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType3 (FUN_680725d0)
// Address: 680725d0
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType3(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType4 (FUN_68072630)
// Address: 68072630
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType4(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType5 (FUN_68072690)
// Address: 68072690
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType5(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType6 (FUN_680726f0)
// Address: 680726f0
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType6(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastType7 (FUN_68072750)
// Address: 68072750
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCastType7(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_resolveMemberByType (FUN_680727b0)
// Address: 680727b0
// Size: 85 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resolveMemberByType(int param_1,int param_2)
{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  short *unaff_EDI;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 8) + 4);
  iVar2 = Ordinal_312(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*unaff_EDI,param_1 + 1,param_2,
                      &param_2);
  if (iVar2 != 0) {
    uVar3 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(short)param_2);
    *(undefined4 *)unaff_EDI = uVar3;
    return 0;
  }
  *unaff_EDI = 0;
  unaff_EDI[1] = -1;
  return 0;
}



// ============================================================
// Function: sprites_resetMember (FUN_68072810)
// Address: 68072810
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resetMember(undefined4 param_1,int param_2)
{
  sprites_resolveMemberByType(param_2,-1);
  return 0;
}



// ============================================================
// Function: sprites_findMemberByScript (FUN_68072830)
// Address: 68072830
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_findMemberByScript(undefined4 param_1,int param_2)
{
  sprites_resolveMemberByType(param_2,3);
  return 0;
}



// ============================================================
// Function: sprites_findMemberByBitmap (FUN_68072850)
// Address: 68072850
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_findMemberByBitmap(undefined4 param_1,int param_2)
{
  sprites_resolveMemberByType(param_2,0xe);
  return 0;
}



// ============================================================
// Function: sprites_findMemberByField (FUN_68072870)
// Address: 68072870
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_findMemberByField(undefined4 param_1,int param_2)
{
  sprites_resolveMemberByType(param_2,6);
  return 0;
}



// ============================================================
// Function: sprites_getMemberRegPoint (FUN_68072890)
// Address: 68072890
// Size: 83 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberRegPoint(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,0x25,local_20);
  return 0;
}



// ============================================================
// Function: sprites_clearMemberRef (FUN_680728f0)
// Address: 680728f0
// Size: 9 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_clearMemberRef(undefined4 param_1,int param_2)
{
  sprites_resetMember(param_1,param_2);
  return 0;
}



// ============================================================
// Function: sprites_setMemberFrameIndex (FUN_68072900)
// Address: 68072900
// Size: 71 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberFrameIndex(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3 + 1;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,1,local_20);
  return 0;
}




// ============================================================
// Function: sprites_getMemberNameById (FUN_68072950)
// Address: 68072950
// Size: 128 bytes
// Params: int param_1, undefined4 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberNameById(int param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  undefined1 *local_20;
  int local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = 0x3ff;
  local_20 = param_3 + 1;
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,1,(uint *)&local_20);
  if (iVar1 == 0) {
    param_3[1] = 0;
    *param_3 = 0;
  }
  else {
    param_3[local_1c + 1] = 0;
    if (local_1c < 0xff) {
      *param_3 = (char)local_1c;
    }
    else {
      *param_3 = 0xff;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberFileName (FUN_680729d0)
// Address: 680729d0
// Size: 160 bytes
// Params: int param_1, undefined4 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberFileName(int param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  undefined1 *local_20;
  int local_1c;
  undefined4 local_18;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = 0x3ff;
  local_18 = 2;
  local_20 = param_3 + 1;
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,8,(uint *)&local_20);
  if (iVar1 == 0) {
    param_3[1] = 0;
    *param_3 = 0;
    return 0;
  }
  param_3[local_1c + 1] = 0;
  if (local_1c < 0xff) {
    *param_3 = (char)local_1c;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: sprites_registerMemberMedia (FUN_68072a70)
// Address: 68072a70
// Size: 57 bytes
// Params: int param_1, undefined4 * param_2, void * param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_registerMemberMedia(int param_1,undefined4 *param_2,void *param_3,void *param_4)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  media_registerAssetWithData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),uVar2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: sprites_extractMemberData (FUN_68072ab0)
// Address: 68072ab0
// Size: 252 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_extractMemberData(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_28;
  int local_24;
  uint local_20 [2];
  undefined4 local_18;
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(short *)(iVar2 + 0x9a) == 0) {
    return 0;
  }
  uVar1 = Ordinal_362(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),(undefined4 *)(iVar2 + 0x98));
  local_20[0] = 0;
  local_18 = 1;
  Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),uVar1,0x31,local_20);
  iVar2 = media_getAssetData(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),uVar1,&local_24,&local_28);
  if ((iVar2 != 0) && (0 < local_28 - local_24)) {
    iVar2 = (local_28 - local_24) + 1;
    iVar3 = Ordinal_1111(iVar2,0);
    uVar1 = Ordinal_1114(iVar3);
    iVar4 = Ordinal_1114(local_20[0]);
    if (iVar3 != 0) {
      Ordinal_1203(uVar1,iVar4 + local_24,iVar2);
    }
    Ordinal_1115(local_20[0]);
    Ordinal_1115(iVar3);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberPurge (FUN_68072bb0)
// Address: 68072bb0
// Size: 70 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberPurge(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x78,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberPurgeFlag (FUN_68072c00)
// Address: 68072c00
// Size: 67 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberPurgeFlag(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x78,local_20);
  return 0;
}



// ============================================================
// Function: sprites_findMemberByName (FUN_68072c50)
// Address: 68072c50
// Size: 137 bytes
// Params: int param_1, undefined4 * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_findMemberByName(int param_1,undefined4 *param_2,int *param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(DAT_681962f8 + 0xc) == 0) {
    lingo_loadMovieData(*(int *)(iVar1 + 0x20),&local_c);
    uVar2 = scoreEngine_setPropertyStr(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x24),local_c,local_8,&param_1);
    if (0 < (short)((uint)uVar2 >> 0x10)) {
      uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24),(short)uVar2);
      *param_2 = uVar2;
      if (param_3 == (int *)0x0) {
        return 0;
      }
      *param_3 = param_1;
      return 0;
    }
  }
  *param_2 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberField (FUN_68072ce0)
// Address: 68072ce0
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberField(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xf,local_20);
  *param_3 = local_20[0];
  return 0;
}



// ============================================================
// Function: sprites_setMemberField (FUN_68072d30)
// Address: 68072d30
// Size: 116 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberField(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xf,local_20);
  local_20[0] = 0;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x12,local_20);
  Ordinal_104(*(int *)(iVar1 + 0x20),0x1000);
  return 0;
}



// ============================================================
// Function: sprites_getMemberModified (FUN_68072db0)
// Address: 68072db0
// Size: 69 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberModified(int param_1,undefined4 param_2)
{
  int iVar1;
  uint *unaff_ESI;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x18,local_20);
  *unaff_ESI = local_20[0];
  return 0;
}



// ============================================================
// Function: sprites_setMemberModified (FUN_68072e00)
// Address: 68072e00
// Size: 67 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberModified(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x18,local_20);
  return 0;
}



// ============================================================
// Function: sprites_updateMemberScript (FUN_68072e50)
// Address: 68072e50
// Size: 400 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_updateMemberScript(undefined4 param_1,int param_2,int *param_3)
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  void *unaff_EDI;
  uint local_54 [4];
  int *local_44;
  uint local_40;
  int *local_3c;
  int *local_38 [6];
  int *local_20 [6];
  uint local_8;
  
  puVar1 = *(uint **)(*(int *)((int)unaff_EDI + 8) + 4);
  local_40 = *puVar1;
  local_3c = param_3;
  piVar3 = (int *)0x0;
  local_44 = (int *)0x0;
  Ordinal_294(puVar1[8],puVar1[10],param_1,0x25,(uint *)local_20);
  cast_teardownHandler((uint)unaff_EDI,local_20[0]);
  if (param_2 == 0) {
    Ordinal_294(puVar1[8],puVar1[10],param_1,0x26,(uint *)local_20);
    local_44 = local_20[0];
    local_3c = local_20[0];
  }
  else {
    local_38[0] = local_3c;
    Ordinal_293(puVar1[8],puVar1[10],param_1,0x26,(uint *)local_38);
  }
  if (local_3c != (int *)0x0) {
    iVar2 = Ordinal_1116(local_3c);
    if (0 < iVar2) {
      local_54[0] = 0;
      local_54[1] = 0;
      local_54[2] = 0;
      local_54[3] = 0;
      Ordinal_347(*(int *)(local_40 + 8),(short)param_1,4,local_54);
      local_40 = local_54[0];
      Ordinal_294(puVar1[8],puVar1[10],param_1,0x21,(uint *)local_20);
      piVar3 = local_20[0];
      if (local_20[0] == (int *)0x1) {
        piVar3 = (int *)0x4;
      }
      Ordinal_294(puVar1[8],puVar1[10],param_1,0x22,(uint *)local_20);
      if (local_20[0] == (int *)0x1) {
        piVar3 = (int *)((uint)piVar3 | 0x200);
      }
      piVar3 = (int *)cast_invokeHandlerEx(unaff_EDI,local_40,local_3c,(uint)piVar3,
                                   (int)(short)param_1 << 0x10 | (int)(*(unsigned short *)((char *)&param_1 + 2)));
    }
  }
  local_38[0] = piVar3;
  Ordinal_293(puVar1[8],puVar1[10],param_1,0x25,(uint *)local_38);
  local_38[0] = (int *)cast_getSlotCount(unaff_EDI,piVar3);
  Ordinal_293(puVar1[8],puVar1[10],param_1,0x24,(uint *)local_38);
  if (local_44 != (int *)0x0) {
    cast_freeHandle(local_44);
  }
  return 0;
}



// ============================================================
// Function: sprites_isMemberLoaded (FUN_68072fe0)
// Address: 68072fe0
// Size: 54 bytes
// Params: int param_1, undefined4 * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool sprites_isMemberLoaded(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar1 = Ordinal_362(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2);
  iVar2 = Ordinal_332(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28),uVar1);
  return (bool)('\x01' - (iVar2 != 0));
}



// ============================================================
// Function: sprites_deleteMember (FUN_68073020)
// Address: 68073020
// Size: 221 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_deleteMember(int param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = sprites_getStageRef(param_1);
  if (iVar2 != 0) {
    local_108[0] = 0;
    Ordinal_1517(DAT_681956e0,0x1392,local_108,0xff);
    local_208[0] = 0;
    Ordinal_1517(DAT_681956e0,0x1391,local_208,0xff);
    iVar2 = Ordinal_1780(local_208,local_108,2,0,1,1,1);
    if (iVar2 == 2) {
      return 0;
    }
  }
  iVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_333(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),iVar2);
  return 0;
}



