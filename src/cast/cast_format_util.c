// Module: cast
// Topic: String/number formatting, random, and miscellaneous utilities
// Address range: 0x6802DCE0 - 0x6802E040
// Functions (12):
//   cast_formatNumber
//   cast_formatDate
//   cast_formatTime
//   cast_formatDouble
//   cast_formatFloat
//   cast_parseDouble
//   Ordinal_950
//   Ordinal_951
//   cast_waitForAlert
//   cast_waitForSync
//   Ordinal_965
//   cast_getRandomValue

// ============================================================
// Function: cast_formatNumber (FUN_6802dce0)
// Address: 6802dce0
// Size: 84 bytes
// Params: undefined4 * param_1, short param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_formatNumber(undefined4 *param_1,short param_2,int param_3)

{
  int local_2c;
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (-1 < param_2) {
    if (param_3 == 0) {
      uVar1 = Ordinal_37(param_1,param_2,0,0);
      return uVar1;
    }
    uVar1 = Ordinal_1114(param_3);
    iVar2 = Ordinal_1116(param_3);
    uVar1 = Ordinal_37(param_1,param_2,uVar1,iVar2);
    Ordinal_1115(param_3);
  }
  return uVar1;
}



// ============================================================
// Function: cast_formatDate (FUN_6802dd40)
// Address: 6802dd40
// Size: 134 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatDate(int param_1,undefined1 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 local_2c [36];
  uint local_8;
  
  if (param_1 == 1) {
    uVar2 = 1;
  }
  else if (param_1 == 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  uVar3 = Ordinal_1542();
  Ordinal_1543(local_2c,uVar3);
  iVar1 = Ordinal_1256(param_2 + 1,0x3fd,local_2c,uVar2);
  param_2[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_2 = (char)iVar1;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: cast_formatTime (FUN_6802ddd0)
// Address: 6802ddd0
// Size: 126 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatTime(int param_1,undefined1 *param_2)
{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_2c [36];
  
  uVar2 = Ordinal_1542();
  Ordinal_1543(local_2c,uVar2);
  iVar1 = Ordinal_1257(param_2 + 1,0x3fd,local_2c,param_1 == 2);
  param_2[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_2 = (char)iVar1;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: cast_formatDouble (FUN_6802de50)
// Address: 6802de50
// Size: 61 bytes
// Params: undefined8 param_1, undefined4 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatDouble(undefined8 param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  
  iVar1 = Ordinal_1534(param_1,param_2,param_3 + 1,0x3ff);
  param_3[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_3 = (char)iVar1;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: cast_formatFloat (FUN_6802de90)
// Address: 6802de90
// Size: 61 bytes
// Params: float param_1, undefined4 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatFloat(float param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  
  iVar1 = Ordinal_1539((double)param_1,param_2,param_3 + 1,0x3ff);
  param_3[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_3 = (char)iVar1;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: cast_parseDouble (FUN_6802ded0)
// Address: 6802ded0
// Size: 66 bytes
// Params: byte * param_1, double * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_parseDouble(byte *param_1,double *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  ushort uVar4;
  float10 fVar5;
  
  pbVar3 = param_1;
  pbVar1 = param_1 + 1;
  fVar5 = (float10)Ordinal_1533(pbVar1,&param_1);
  *param_2 = (double)fVar5;
  bVar2 = *pbVar3;
  if (bVar2 == 0xff) {
    uVar4 = Ordinal_1201(pbVar1);
  }
  else {
    uVar4 = (ushort)bVar2;
  }
  return pbVar3 + (short)uVar4 + 1 == param_1;
}



// ============================================================
// Function: Ordinal_950
// Address: 6802df20
// Size: 22 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_950(int param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  
                    /* 0x2df20  950   */
  uVar1 = Ordinal_1215(param_1 + 1);
  *param_2 = uVar1;
  return 0;
}



// ============================================================
// Function: Ordinal_951
// Address: 6802df40
// Size: 58 bytes
// Params: undefined4 param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_951(undefined4 param_1,undefined1 *param_2)
{
  int iVar1;
  
                    /* 0x2df40  951   */
  Ordinal_1216(param_1,param_2 + 1,10);
  iVar1 = Ordinal_1201(param_2 + 1);
  param_2[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_2 = (char)iVar1;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: cast_waitForAlert (FUN_6802dfd0)
// Address: 6802dfd0
// Size: 11 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_waitForAlert(void)
{
  Ordinal_1770(0x81);
  return 0;
}



// ============================================================
// Function: cast_waitForSync (FUN_6802dfe0)
// Address: 6802dfe0
// Size: 11 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_waitForSync(void)
{
  Ordinal_1770(0x80);
  return 0;
}



// ============================================================
// Function: Ordinal_965
// Address: 6802dff0
// Size: 30 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

void Ordinal_965(void)

{
  int iVar1;
  uint uVar2;

                    /* 0x2dff0  965   */
  iVar1 = Ordinal_1541();
  Ordinal_1781(4);
  do {
    uVar2 = Ordinal_1541();
  } while (uVar2 < iVar1 + 0xa7U);
  return;
}



// ============================================================
// Function: cast_getRandomValue (FUN_6802e040)
// Address: 6802e040
// Size: 80 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint cast_getRandomValue(int param_1)

{
  uint uVar1;
  
  if (DAT_68195a80 == 0) {
    Ordinal_1050(&DAT_68195a80,0x20);
  }
  if ((DAT_68195a80 & 1) == 0) {
    DAT_68195a80 = DAT_68195a80 >> 1;
  }
  else {
    DAT_68195a80 = DAT_68195a80 >> 1 ^ _DAT_68195a84;
  }
  uVar1 = Ordinal_1051(DAT_68195a80 * 0x47);
  if (0 < param_1) {
    uVar1 = (uint)((longlong)(ulonglong)(uVar1 & 0x7fffffff) % (longlong)param_1);
  }
  return uVar1;
}






// ============================================================
// Function: cast_loadPascalString (FUN_6802df80)
// Address: 6802df80
// Size: 61 bytes
// Params: undefined1 * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

void cast_loadPascalString(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = Ordinal_1517(DAT_681956e0,param_2 + param_3,param_1 + 1,0x3fd);
  param_1[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_1 = (char)iVar1;
    return;
  }
  *param_1 = 0xff;
  return;
}



// ============================================================
// Function: cast_seedRandom (FUN_6802e090)
// Address: 6802e090
// Size: 41 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

void cast_seedRandom(int param_1)

{
  Ordinal_1050(&DAT_68195a80,0x20);
  DAT_68195a80 = 1;
  if (param_1 != 0) {
    DAT_68195a80 = param_1;
  }
  return;
}
