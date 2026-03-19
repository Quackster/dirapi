// Module: lingo
// Topic: Color space, encoding, and string conversion
// Address range: 0x6809B230 - 0x6809D1F0
// Functions (18):
//   lingo_setColorValue
//   lingo_getColorValue
//   lingo_checkColorSpace (FUN_6809b2f0)
//   lingo_writeValue (FUN_6809b330)
//   lingo_apiGetVersion
//   lingo_apiGetValue
//   lingo_apiTranscodeStrEx
//   lingo_apiTranscodeStr
//   lingo_apiConvertMulti
//   lingo_apiConvertWide
//   lingo_apiMultiToWide
//   lingo_apiWideToMulti
//   lingo_apiIsType
//   lingo_apiCreateObject
//   lingo_cmdCompare
//   lingo_cmdContains2
//   lingo_cmdGetType
//   lingo_cmdIlk


// ============================================================
// Function: lingo_setColorValue (FUN_6809b230)
// Address: 6809b230
// Size: 70 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setColorValue(int param_1,undefined1 *param_2)
{
  undefined4 uVar1;
  
  uVar1 = Ordinal_1610(*(undefined4 *)(param_1 + 0xb8));
  Ordinal_1738(uVar1,CONCAT11(*param_2,*param_2),CONCAT11(param_2[1],param_2[1]),
               CONCAT11(param_2[2],param_2[2]));
  return 0;
}



// ============================================================
// Function: lingo_getColorValue (FUN_6809b280)
// Address: 6809b280
// Size: 98 bytes
// Params: int param_1, undefined1 param_2, undefined1 * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool lingo_getColorValue(int param_1,undefined1 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_10 [3];
  undefined1 uStack_d;
  undefined2 uStack_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  undefined1 uStack_9;
  
  uVar1 = Ordinal_1610(*(undefined4 *)(param_1 + 0xb8));
  iVar2 = Ordinal_1736(uVar1,param_2,local_10,1);
  if (iVar2 == 0) {
    uStack_b = 0;
    uStack_9 = 0;
    uStack_d = 0;
  }
  *param_3 = uStack_d;
  param_3[1] = uStack_b;
  param_3[2] = uStack_9;
  return iVar2 != 0;
}



// ============================================================
// Function: lingo_apiGetVersion (FUN_6809cd50)
// Address: 6809cd50
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetVersion(void)
{
  char cVar1;
  char *in_EAX;
  int iVar2;
  
  cVar1 = *in_EAX;
  while (cVar1 != '\0') {
    iVar2 = tolower((int)*in_EAX);
    *in_EAX = (char)iVar2;
    in_EAX = in_EAX + 1;
    cVar1 = *in_EAX;
  }
  return 0;
}



// ============================================================
// Function: lingo_apiGetValue (FUN_6809cd80)
// Address: 6809cd80
// Size: 24 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiGetValue(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  Ordinal_1287(param_2,*param_3);
  return 0;
}



// ============================================================
// Function: lingo_apiTranscodeStrEx (FUN_6809cda0)
// Address: 6809cda0
// Size: 77 bytes
// Params: undefined4 param_1, undefined4 param_2, LPCSTR param_3, int param_4, LPSTR param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_apiTranscodeStrEx(undefined4 param_1,undefined4 param_2,LPCSTR param_3,int param_4,LPSTR param_5,
            int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1289(param_2,&local_8);
  if (iVar1 == 0) {
    return 0x80040001;
  }
  uVar2 = strings_convertEncoding((ushort)local_8,0xfde9,param_3,param_4,param_5,param_6,(LPCSTR)0x0);
  return uVar2;
}



// ============================================================
// Function: lingo_apiTranscodeStr (FUN_6809cdf0)
// Address: 6809cdf0
// Size: 79 bytes
// Params: undefined4 param_1, undefined4 param_2, LPCSTR param_3, int param_4, LPSTR param_5, int * param_6, LPCSTR param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_apiTranscodeStr(undefined4 param_1,undefined4 param_2,LPCSTR param_3,int param_4,LPSTR param_5,
            int *param_6,LPCSTR param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1289(param_2,&local_8);
  if (iVar1 == 0) {
    return 0x80040001;
  }
  uVar2 = strings_convertEncoding(0xfde9,(ushort)local_8,param_3,param_4,param_5,param_6,param_7);
  return uVar2;
}



// ============================================================
// Function: lingo_apiConvertMulti (FUN_6809ce40)
// Address: 6809ce40
// Size: 70 bytes
// Params: undefined4 param_1, undefined4 param_2, LPCSTR param_3, int param_4, LPWSTR param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_apiConvertMulti(undefined4 param_1,undefined4 param_2,LPCSTR param_3,int param_4,LPWSTR param_5,
            int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1289(param_2,&local_8);
  if (iVar1 == 0) {
    return 0x80040001;
  }
  uVar2 = strings_multiToWide((ushort)local_8,param_3,param_4,param_5,param_6);
  return uVar2;
}



// ============================================================
// Function: lingo_apiConvertWide (FUN_6809ce90)
// Address: 6809ce90
// Size: 74 bytes
// Params: undefined4 param_1, undefined4 param_2, LPCWSTR param_3, int param_4, LPSTR param_5, int * param_6, LPCSTR param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_apiConvertWide(undefined4 param_1,undefined4 param_2,LPCWSTR param_3,int param_4,LPSTR param_5,
            int *param_6,LPCSTR param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1289(param_2,&local_8);
  if (iVar1 == 0) {
    return 0x80040001;
  }
  uVar2 = strings_wideToMulti((ushort)local_8,param_3,param_4,param_5,param_6,param_7);
  return uVar2;
}



// ============================================================
// Function: lingo_apiMultiToWide (FUN_6809cee0)
// Address: 6809cee0
// Size: 33 bytes
// Params: undefined4 param_1, LPCSTR param_2, int param_3, LPWSTR param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiMultiToWide(undefined4 param_1,LPCSTR param_2,int param_3,LPWSTR param_4,int *param_5)
{
  strings_multiToWide(0xfde9,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: lingo_apiWideToMulti (FUN_6809cf10)
// Address: 6809cf10
// Size: 35 bytes
// Params: undefined4 param_1, LPCWSTR param_2, int param_3, LPSTR param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiWideToMulti(undefined4 param_1,LPCWSTR param_2,int param_3,LPSTR param_4,int *param_5)
{
  strings_wideToMulti(0xfde9,param_2,param_3,param_4,param_5,(LPCSTR)0x0);
  return 0;
}



// ============================================================
// Function: lingo_apiIsType (FUN_6809cf40)
// Address: 6809cf40
// Size: 36 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool lingo_apiIsType(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = Ordinal_1264(param_2,param_3,param_4);
  return iVar1 != 0;
}



// ============================================================
// Function: lingo_apiCreateObject (FUN_6809cf70)
// Address: 6809cf70
// Size: 35 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiCreateObject(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_1289(param_2,param_3);
  uVar2 = 0x80040001;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: lingo_cmdCompare (FUN_6809cfa0)
// Address: 6809cfa0
// Size: 39 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdCompare(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_1290(param_2,param_3,param_4);
  uVar2 = 0x80040001;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: lingo_cmdContains2 (FUN_6809cfd0)
// Address: 6809cfd0
// Size: 458 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdContains2(void)
{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  char *unaff_ESI;
  bool bVar8;
  char local_3c [52];
  uint local_8;
  
  local_3c[0] = '\0';
  memset(local_3c + 1,0,0x31);
  iVar5 = -(int)unaff_ESI;
  do {
    cVar1 = *unaff_ESI;
    unaff_ESI[(int)(local_3c + iVar5)] = cVar1;
    unaff_ESI = unaff_ESI + 1;
  } while (cVar1 != '\0');
  pbVar3 = (byte *)lingo_apiGetVersion();
  pbVar6 = &DAT_6817c7a0;
  pbVar4 = pbVar3;
  do {
    bVar2 = *pbVar4;
    bVar8 = bVar2 < *pbVar6;
    if (bVar2 != *pbVar6) {
LAB_6809d040:
      iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_6809d045;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar4[1];
    bVar8 = bVar2 < pbVar6[1];
    if (bVar2 != pbVar6[1]) goto LAB_6809d040;
    pbVar4 = pbVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_6809d045:
  if (iVar5 != 0) {
    pcVar7 = "unicode";
    pbVar4 = pbVar3;
    do {
      bVar2 = *pbVar4;
      bVar8 = bVar2 < (byte)*pcVar7;
      if (bVar2 != *pcVar7) {
LAB_6809d074:
        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_6809d079;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar8 = bVar2 < (byte)pcVar7[1];
      if (bVar2 != pcVar7[1]) goto LAB_6809d074;
      pbVar4 = pbVar4 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_6809d079:
    if (iVar5 != 0) {
      pbVar6 = &DAT_6817c788;
      pbVar4 = pbVar3;
      do {
        bVar2 = *pbVar4;
        bVar8 = bVar2 < *pbVar6;
        if (bVar2 != *pbVar6) {
LAB_6809d0a8:
          iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_6809d0ad;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar8 = bVar2 < pbVar6[1];
        if (bVar2 != pbVar6[1]) goto LAB_6809d0a8;
        pbVar4 = pbVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_6809d0ad:
      if (iVar5 != 0) {
        pcVar7 = "csunicode";
        pbVar4 = pbVar3;
        do {
          bVar2 = *pbVar4;
          bVar8 = bVar2 < (byte)*pcVar7;
          if (bVar2 != *pcVar7) {
LAB_6809d0e0:
            iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_6809d0e5;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar4[1];
          bVar8 = bVar2 < (byte)pcVar7[1];
          if (bVar2 != pcVar7[1]) goto LAB_6809d0e0;
          pbVar4 = pbVar4 + 2;
          pcVar7 = pcVar7 + 2;
        } while (bVar2 != 0);
        iVar5 = 0;
LAB_6809d0e5:
        if (iVar5 != 0) {
          pcVar7 = "utf-16le";
          pbVar4 = pbVar3;
          do {
            bVar2 = *pbVar4;
            bVar8 = bVar2 < (byte)*pcVar7;
            if (bVar2 != *pcVar7) {
LAB_6809d114:
              iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_6809d119;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar4[1];
            bVar8 = bVar2 < (byte)pcVar7[1];
            if (bVar2 != pcVar7[1]) goto LAB_6809d114;
            pbVar4 = pbVar4 + 2;
            pcVar7 = pcVar7 + 2;
          } while (bVar2 != 0);
          iVar5 = 0;
LAB_6809d119:
          if (iVar5 != 0) {
            pcVar7 = "unicodefffe";
            pbVar4 = pbVar3;
            do {
              bVar2 = *pbVar4;
              bVar8 = bVar2 < (byte)*pcVar7;
              if (bVar2 != *pcVar7) {
LAB_6809d144:
                iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_6809d149;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar4[1];
              bVar8 = bVar2 < (byte)pcVar7[1];
              if (bVar2 != pcVar7[1]) goto LAB_6809d144;
              pbVar4 = pbVar4 + 2;
              pcVar7 = pcVar7 + 2;
            } while (bVar2 != 0);
            iVar5 = 0;
LAB_6809d149:
            if (iVar5 != 0) {
              pcVar7 = "utf-16be";
              do {
                bVar2 = *pbVar3;
                bVar8 = bVar2 < (byte)*pcVar7;
                if (bVar2 != *pcVar7) {
LAB_6809d172:
                  iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                  goto LAB_6809d177;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar3[1];
                bVar8 = bVar2 < (byte)pcVar7[1];
                if (bVar2 != pcVar7[1]) goto LAB_6809d172;
                pbVar3 = pbVar3 + 2;
                pcVar7 = pcVar7 + 2;
              } while (bVar2 != 0);
              iVar5 = 0;
LAB_6809d177:
              if (iVar5 != 0) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdGetType (FUN_6809d1a0)
// Address: 6809d1a0
// Size: 74 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdGetType(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  uVar1 = lingo_cmdContains2();
  if ((char)uVar1 != '\0') {
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  iVar2 = Ordinal_1289(param_2,&local_8);
  if (iVar2 != 0) {
    uVar1 = strings_validateCodePage((ushort)local_8);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdIlk (FUN_6809d1f0)
// Address: 6809d1f0
// Size: 20 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdIlk(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  Ordinal_1288(param_2,param_3);
  return 0;
}


// ============================================================
// Function: lingo_checkColorSpace (FUN_6809b2f0)
// Address: 6809b2f0
// Size: 54 bytes
// Params: int param_1, undefined2 * param_2, undefined2 * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool lingo_checkColorSpace(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  bool bVar1;

  if (*(char *)((int)param_2 + 3) == '\0') {
    bVar1 = lingo_getColorValue(param_1,*(undefined1 *)param_2,(undefined1 *)param_3);
    return bVar1;
  }
  *param_3 = *param_2;
  *(undefined1 *)(param_3 + 1) = *(undefined1 *)(param_2 + 1);
  return true;
}


// ============================================================
// Function: lingo_writeValue (FUN_6809b330)
// Address: 6809b330
// Size: 32 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 lingo_writeValue(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;

  if (param_2[3] == '\0') {
    return *param_2;
  }
  uVar1 = lingo_setColorValue(param_1,param_2);
  return uVar1;
}


