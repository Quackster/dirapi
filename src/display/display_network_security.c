// Module: display
// Topic: Network security, URL validation, and content format handling
// Address range: 0x680fbc00 - 0x680fc570
// Functions (13):
//   display_updateSecurityState (display_updateSecurityState)
//   display_extractUrlHost (display_extractUrlHost)
//   display_compareStrings (display_compareStrings)
//   display_validateUrlSecurity (display_validateUrlSecurity)
//   display_checkUrlAccess (display_checkUrlAccess)
//   display_freeSecurityHandles (display_freeSecurityHandles)
//   display_freeNetSecurity
//   display_releaseNetSecurity
//   display_loadNetSecurityData
//   display_loadCertChainData (display_loadCertChainData)
//   display_checkNetSecurity
//   display_getNetSecurityState
//   display_initNetworkSecurity


// ============================================================
// Function: display_updateSecurityState (display_updateSecurityState)
// Address: 680fbc00
// Size: 61 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_updateSecurityState(undefined4 param_1,int param_2)
{
  int iVar1;
  int unaff_ESI;
  
  display_openFontResource(&DAT_6819693c);
  if (((param_2 != 0) || (unaff_ESI != 0)) && (iVar1 = display_openFontResource(&DAT_68196938), iVar1 != 0)) {
    display_saveFontData();
  }
  return 0;
}



// ============================================================
// Function: display_extractUrlHost (display_extractUrlHost)
// Address: 680fbc40
// Size: 76 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_extractUrlHost(void)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  iVar2 = Ordinal_1205();
  if (iVar2 != 0) {
    pcVar6 = (char *)(iVar2 + 1);
    cVar1 = *pcVar6;
    while (cVar1 == '/') {
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar6;
    }
    uVar3 = Ordinal_1205(pcVar6,0x40);
    if ((uVar3 != 0) && ((uVar4 = Ordinal_1205(pcVar6,0x2f), uVar4 == 0 || (uVar3 <= uVar4)))) {
      uVar5 = Ordinal_1201(uVar3);
      Ordinal_1129(pcVar6,uVar3 + 1,uVar5);
    }
  }
  return 0;
}



// ============================================================
// Function: display_compareStrings (display_compareStrings)
// Address: 680fbc90
// Size: 46 bytes
// Params: char * param_1, char * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_compareStrings(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 == *param_2) {
    do {
      if ((cVar1 == '\0') || (*param_2 == '\0')) break;
      cVar1 = param_1[1];
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (cVar1 == *param_2);
  }
  return (int)*param_1 - (int)*param_2;
}



// ============================================================
// Function: display_validateUrlSecurity (display_validateUrlSecurity)
// Address: 680fbcc0
// Size: 770 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_validateUrlSecurity(void *this,undefined4 *param_1)
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int unaff_EDI;
  undefined4 uVar4;
  undefined4 local_d54;
  int local_d50;
  int local_d4c;
  undefined4 *local_d48;
  int local_d44;
  char *local_d40;
  undefined1 local_d3c [4];
  short local_d38;
  undefined1 local_924 [4];
  short local_920;
  undefined2 local_50c;
  undefined1 local_50a [254];
  int local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined1 local_400 [1016];
  uint local_8;
  
  local_d48 = param_1;
  local_d44 = 0;
  local_d40 = (char *)0x0;
  local_50c = 0;
  memset(local_50a,0,0x102);
  local_d50 = 0;
  Ordinal_1130(local_924,0x418);
  iVar1 = Ordinal_1311(this,4);
  if (iVar1 == 0) {
    local_408 = FOURCC_ptth;
    local_404 = 0x2f2f3a;
    memset(local_400,0,0x3f8);
    Ordinal_1203((int)&local_404 + 3,this,0x3f9);
    this = &local_408;
    uVar4 = 0x400;
  }
  else {
    uVar4 = 0x100;
  }
  Ordinal_1309(local_924,uVar4,this,4);
  if (1 < local_920) {
    Ordinal_1316(local_924);
  }
  uVar4 = Ordinal_1324(local_924);
  local_d40 = (char *)Ordinal_1126(uVar4,0);
  Ordinal_1310(local_924,local_d40,uVar4);
  Ordinal_1217(local_d40,uVar4);
  iVar1 = Ordinal_1168(*(undefined4 *)(unaff_EDI + 0x120));
  if (iVar1 != 0) {
    uVar4 = Ordinal_1157(*(undefined4 *)(unaff_EDI + 0x120));
    local_d4c = 0;
    do {
      pcVar2 = strstr(local_d40,"://");
      pcVar3 = local_d40;
      if (pcVar2 != (char *)0x0) {
        pcVar3 = pcVar2 + 3;
      }
      while( true ) {
        pcVar3 = strchr(pcVar3,0x2f);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        iVar1 = Ordinal_1165(*(undefined4 *)(unaff_EDI + 0x120),&local_d54,local_d40,display_compareStrings,0)
        ;
        if (iVar1 != 0) {
          memset(&local_50c,0,0x104);
          Ordinal_1155(*(undefined4 *)(unaff_EDI + 0x120),local_d54,&local_50c);
          local_d50 = 1;
        }
        if (pcVar3 == (char *)0x0) break;
        *pcVar3 = '/';
        pcVar3 = pcVar3 + 1;
      }
      if (local_d50 != 0) {
        if (local_40c == 1) {
          local_d44 = local_40c;
        }
        else if (local_40c == 0) {
          *local_d48 = 1;
          local_d44 = 0;
        }
        else {
          *local_d48 = 0;
        }
        break;
      }
      if (0x114f < *(uint *)(*(int *)(unaff_EDI + 0x20) + 0x500)) {
        Ordinal_1326(local_d3c,0x418,local_924);
        while (1 < local_d38) {
          Ordinal_1316(local_d3c);
        }
        Ordinal_1317(local_d3c,"crossdomain.xml");
        Ordinal_1310(local_d3c,&local_408,0x400);
        scoreEngine_importScoreData((char *)&local_408);
      }
      local_d4c = local_d4c + 1;
    } while (local_d4c < 2);
    Ordinal_1158(*(undefined4 *)(unaff_EDI + 0x120),uVar4);
  }
  if (local_d40 != (char *)0x0) {
    Ordinal_1127(&local_d40);
  }
  return 0;
}



// ============================================================
// Function: display_checkUrlAccess (display_checkUrlAccess)
// Address: 680fbfd0
// Size: 399 bytes
// Params: char * param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_checkUrlAccess(char *param_1,void *param_2)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_41c;
  char *local_418;
  int local_414;
  int local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  
  iVar3 = 0;
  local_418 = param_1;
  local_410 = 0;
  local_40c = 0;
  local_414 = 0;
  lingo_resolveContext(&local_41c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  if ((local_41c != 0) && (*(int *)(local_41c + 0x20) != 0)) {
    iVar3 = *(int *)(*(int *)(local_41c + 0x20) + 4);
  }
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) goto LAB_680fc146;
  if ((DAT_68196940 == 0) && (iVar2 = display_validateUrlSecurity(param_2,&local_414), iVar2 == 0)) {
    if ((local_414 != 0) && (*(int *)(iVar3 + 0x124) == 0)) {
      local_40c = 0;
      goto LAB_680fc146;
    }
    iVar2 = display_lookupFont(param_1);
    if (iVar2 != 0) {
      if (local_410 != 0) {
        DAT_68196940 = 1;
      }
      local_40c = 1;
      goto LAB_680fc146;
    }
    if (*(int *)(**(int **)(*(int *)(iVar3 + 8) + 4) + 0x30) != 0) {
      Ordinal_1203(local_408,param_2,0x3ff);
      display_extractUrlHost();
      if (DAT_68196944 == 0) {
        DAT_68196944 = 1;
        bVar1 = (**(code **)(*(int *)(*(int **)(iVar3 + 8))[1] + 0x30))
                          (*(undefined4 *)(**(int **)(iVar3 + 8) + 0x24),local_408);
        DAT_68196944 = 0;
        if ((bVar1 & 1) != 0) {
          local_40c = 1;
          if ((bVar1 & 4) != 0) {
            DAT_68196940 = 1;
          }
          display_updateSecurityState(local_418,(uint)((bVar1 & 2) != 0));
        }
      }
      goto LAB_680fc146;
    }
  }
  local_40c = 1;
LAB_680fc146:
  return 0;
}



// ============================================================
// Function: display_freeSecurityHandles (display_freeSecurityHandles)
// Address: 680fc160
// Size: 21 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_freeSecurityHandles(void)
{
  Ordinal_1113(&DAT_68196938);
  Ordinal_1113(&DAT_6819693c);
  return 0;
}



// ============================================================
// Function: display_freeNetSecurity (FUN_680fc3e0)
// Address: 680fc3e0
// Size: 53 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_freeNetSecurity(undefined4 *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)display_allocBlock(0x1c);
  *param_1 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    return 0x206;
  }
  xtra_clearBERHeader(pvVar1);
  *(undefined **)((int)pvVar1 + 0x14) = &DAT_6818ea10;
  *(void **)((int)pvVar1 + 0x18) = pvVar1;
  return 0;
}



// ============================================================
// Function: display_releaseNetSecurity (FUN_680fc420)
// Address: 680fc420
// Size: 59 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_releaseNetSecurity(undefined4 *param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    iVar2 = display_checkNetSecurity((int)piVar1);
    if (iVar2 == 0) {
      piVar1[6] = 0;
      xtra_readCertBlockData(piVar1);
      display_freeIfNonNull((int)piVar1);
    }
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: display_loadNetSecurityData (FUN_680fc460)
// Address: 680fc460
// Size: 71 bytes
// Params: int param_1, undefined * param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_loadNetSecurityData(int param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = display_checkNetSecurity(param_1);
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_2)(&local_4);
    if (iVar1 == 0) {
      return 0x205;
    }
    iVar1 = xtra_invokeCertHandler(param_1,local_4,param_3);
  }
  return iVar1;
}



// ============================================================
// Function: display_loadCertChainData (display_loadCertChainData)
// Address: 680fc4b0
// Size: 71 bytes
// Params: int * param_1, int * param_2, undefined * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_loadCertChainData(int *param_1,int *param_2,undefined *param_3)

{
  int iVar1;
  int local_4;
  
  iVar1 = display_checkNetSecurity((int)param_2);
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_3)(&local_4);
    if (iVar1 == 0) {
      return 0x205;
    }
    iVar1 = xtra_readCertChain(param_2,param_1,local_4);
  }
  return iVar1;
}



// ============================================================
// Function: display_checkNetSecurity (FUN_680fc500)
// Address: 680fc500
// Size: 34 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_checkNetSecurity(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x18) == param_1) && (*(undefined **)(param_1 + 0x14) == &DAT_6818ea10)) {
    return 0;
  }
  return 0x212;
}



// ============================================================
// Function: display_getNetSecurityState (FUN_680fc530)
// Address: 680fc530
// Size: 53 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_getNetSecurityState(undefined4 *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)display_allocBlock(0x24);
  *param_1 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    return 0x206;
  }
  xtra_clearBERHeaderEx(pvVar1);
  *(undefined **)((int)pvVar1 + 0x1c) = &DAT_6818ea14;
  *(void **)((int)pvVar1 + 0x20) = pvVar1;
  return 0;
}



// ============================================================
// Function: display_initNetworkSecurity (FUN_680fc570)
// Address: 680fc570
// Size: 55 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_initNetworkSecurity(undefined4 *param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  iVar2 = display_initFormatContext((int)piVar1);
  if (iVar2 == 0) {
    piVar1[8] = 0;
    xtra_freeCertBlockFull(piVar1);
    display_freeIfNonNull((int)piVar1);
  }
  *param_1 = 0;
  return 0;
}



