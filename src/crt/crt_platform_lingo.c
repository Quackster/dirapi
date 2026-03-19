// Module: crt
// Topic: Platform helpers, Win32 dialogs, internet, Lingo script execution, sprite properties
// Address range: 0x6800AF20 - 0x6800D090
// Functions (42):
//   crt_getImageRect - crt_getPlatformId (image rect/depth, GDI, dialog boxes, callbacks, constants)
//   crt_getFileVersion - crt_advanceUndo (file version, internet check, script dispatch, code hints)
//   crt_pushUndoEntry - crt_formatScriptError (undo buffer, script call, sprite channel, handler dispatch)
//   crt_dispatchSpriteProperty - crt_dispatchSpriteOp (sprite property get/set, sprite create, iterate behaviors)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800af20 - 0x6800b4e0
// Functions (12):
//   crt_getImageRect
//   crt_getImageDepth
//   crt_freeGlobalHandle
//   crt_deleteGdiObject
//   crt_showDialogW
//   crt_showDialogA
//   crt_invokeMediaCallback
//   crt_invokeMediaCallbackEx
//   crt_getDialogOwner
//   crt_getMaxChannels
//   crt_getConstantDataRef
//   crt_getPlatformId

// ============================================================
// Function: crt_getImageRect (crt_getImageRect)
// Address: 6800af20
// Size: 362 bytes
// Params: undefined4 * param_1, LONG * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getImageRect(undefined4 *param_1,LONG *param_2)
{
  LONG LVar1;
  int iVar2;
  LONG local_34;
  LONG local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  LONG local_1c;
  RECT local_18;
  uint local_8;
  
  switch(*param_1) {
  case 1:
    GetClientRect((HWND)param_1[2],&local_18);
    *param_2 = (*((int *)&local_18 + 1));
    param_2[2] = (*((int *)&local_18 + 3));
    param_2[3] = (*((int *)&local_18 + 2));
    param_2[1] = (*((int *)&local_18));
    return 0;
  case 2:
    iVar2 = *(int *)(param_1[2] + 4);
    LVar1 = *(LONG *)(param_1[2] + 8);
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    param_2[3] = iVar2;
    param_2[1] = 0;
    *param_2 = 0;
    param_2[2] = LVar1;
    return 0;
  case 3:
    GetObjectA((HANDLE)param_1[2],0x18,&local_20);
    param_2[3] = local_1c;
    param_2[1] = 0;
    *param_2 = 0;
    param_2[2] = (*((int *)&local_18));
    return 0;
  default:
    return 0;
  case 7:
    break;
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  (*((int *)&local_18)) = 0;
  (*((int *)&local_18 + 1)) = 0;
  (*((int *)&local_18 + 2)) = 0;
  (*((int *)&local_18 + 3)) = 0;
  local_34 = 0;
  iVar2 = Ordinal_1606(param_1[1],&local_34);
  if (iVar2 != 0) {
    param_2[2] = local_34;
    param_2[1] = 0;
    *param_2 = 0;
    param_2[3] = local_30;
    return 0;
  }
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  param_2[3] = 0;
  return 0;
}



// ============================================================
// Function: crt_getImageDepth (crt_getImageDepth)
// Address: 6800b0b0
// Size: 309 bytes
// Params: undefined4 * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getImageDepth(undefined4 *param_1,uint *param_2)
{
  int iVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20 [7];
  
  switch(*param_1) {
  case 1:
    local_24 = 0;
    local_20[0] = 0;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    local_20[4] = 0;
    local_20[5] = 0;
    local_28 = 0;
    Ordinal_2031(0,&local_28);
    *param_2 = local_20[3];
    return 0;
  case 2:
    *param_2 = (uint)*(ushort *)(param_1[2] + 0xe);
    return 0;
  case 3:
    GetObjectA((HANDLE)param_1[2],0x18,local_20);
    *param_2 = (local_20[4] & 0xffff) * (local_20[4] >> 0x10);
    return 0;
  default:
    return 0;
  case 7:
    break;
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_34 = 0;
  iVar1 = Ordinal_1606(param_1[1],&local_34);
  if (iVar1 != 0) {
    *param_2 = local_20[0];
    return 0;
  }
  *param_2 = 0;
  return 0;
}



// ============================================================
// Function: crt_freeGlobalHandle (crt_freeGlobalHandle)
// Address: 6800b210
// Size: 23 bytes
// Params: HGLOBAL param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_freeGlobalHandle(HGLOBAL param_1)

{
  if (param_1 != (HGLOBAL)0x0) {
    GlobalFree(param_1);
  }
  return 0;
}



// ============================================================
// Function: crt_deleteGdiObject (crt_deleteGdiObject)
// Address: 6800b230
// Size: 10 bytes
// Params: HGDIOBJ param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_deleteGdiObject(HGDIOBJ param_1)
{
                    /* WARNING: Could not recover jumptable at 0x6800b234. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteObject(param_1);
  return 0;
}



// ============================================================
// Function: crt_showDialogW (crt_showDialogW)
// Address: 6800b240
// Size: 152 bytes
// Params: int * param_1, HINSTANCE param_2, LPCWSTR param_3, DLGPROC param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_showDialogW(int *param_1,HINSTANCE param_2,LPCWSTR param_3,DLGPROC param_4)
{
  int iVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  DialogBoxParamW(param_2,param_3,*(HWND *)(*(int *)(iVar2 + 4) + 0x28),param_4,0);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_showDialogA (crt_showDialogA)
// Address: 6800b2e0
// Size: 155 bytes
// Params: int * param_1, HINSTANCE param_2, LPCSTR param_3, DLGPROC param_4, LPARAM param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_showDialogA(int *param_1,HINSTANCE param_2,LPCSTR param_3,DLGPROC param_4,LPARAM param_5)
{
  int iVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  DialogBoxParamA(param_2,param_3,*(HWND *)(*(int *)(iVar2 + 4) + 0x28),param_4,param_5);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_invokeMediaCallback (crt_invokeMediaCallback)
// Address: 6800b380
// Size: 41 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_invokeMediaCallback(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = media_getDataPtr(*(int **)(param_1 + 4));
    if (*(code **)(iVar1 + 0x11c) != (code *)0x0) {
      (**(code **)(iVar1 + 0x11c))(param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: crt_invokeMediaCallbackEx (crt_invokeMediaCallbackEx)
// Address: 6800b3b0
// Size: 41 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_invokeMediaCallbackEx(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = media_getDataPtr(*(int **)(param_1 + 4));
    if (*(code **)(iVar1 + 0x120) != (code *)0x0) {
      (**(code **)(iVar1 + 0x120))(&stack0x00000008);
    }
  }
  return 0;
}



// ============================================================
// Function: crt_getDialogOwner (crt_getDialogOwner)
// Address: 6800b3e0
// Size: 213 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getDialogOwner(int *param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar1 + 0x20);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) {
      piVar2 = *(int **)(*(int *)(iVar4 + 4) + 8);
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
      if ((piVar2 != (int *)0x0) &&
         ((iVar1 = *(int *)(*piVar2 + 0xc), iVar1 != -0x1c &&
          (pcVar3 = *(code **)(iVar1 + 0x1a4), pcVar3 != (code *)0x0)))) {
        (*pcVar3)(param_2,param_3);
        goto LAB_6800b48e;
      }
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = DAT_681956e0;
  }
  if (param_3 != (undefined4 *)0x0) {
    if ((iVar4 == 0) || (*(int *)(iVar4 + 4) == 0)) {
      *param_3 = 0;
    }
    else {
      *param_3 = *(undefined4 *)(*(int *)(iVar4 + 4) + 0x28);
    }
  }
LAB_6800b48e:
  if (iVar4 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================





/* Restored functions that were incorrectly removed during thunk cleanup */

// ============================================================

undefined4 crt_getMaxChannels(void)

{
  return 0x1e;
}


// ============================================================

undefined * crt_getConstantDataRef(void)

{
  return &DAT_681766d0;
}


// ============================================================

undefined4 crt_getPlatformId(void)

{
  return 5;
}


// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800b4f0 - 0x6800ba60
// Functions (14):
//   crt_getFileVersion
//   crt_checkUrlSuffix
//   crt_checkInternetState
//   crt_freeInternetLib
//   crt_initRuntime
//   crt_stepScriptOnce
//   crt_stepScriptForced
//   crt_getHandlerEntry
//   crt_dispatchHandler
//   crt_triggerBehaviors
//   crt_loadCodeHints
//   crt_resolveMovieTarget
//   crt_isUndoComplete
//   crt_advanceUndo

// ============================================================
// Function: crt_getFileVersion (crt_getFileVersion)
// Address: 6800b4f0
// Size: 339 bytes
// Params: undefined4 param_1, LPCSTR param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getFileVersion(undefined4 param_1,LPCSTR param_2,int param_3)
{
  char cVar1;
  int iVar2;
  DWORD dwLen;
  BOOL BVar3;
  char *pcVar4;
  DWORD local_220;
  char *local_21c;
  uint local_218;
  LPVOID local_214;
  WCHAR local_210 [260];
  uint local_8;
  
  local_214 = (LPVOID)0x0;
  iVar2 = Ordinal_1323(param_1,param_2);
  if ((((((iVar2 != 0) &&
         (iVar2 = MultiByteToWideChar(0xfde9,0,param_2,-1,local_210,0x104), 0 < iVar2)) &&
        (dwLen = GetFileVersionInfoSizeW(local_210,&local_220), dwLen != 0)) &&
       ((local_214 = (LPVOID)Ordinal_1124(dwLen), local_214 != (LPVOID)0x0 &&
        (BVar3 = GetFileVersionInfoW(local_210,local_220,dwLen,local_214), BVar3 != 0)))) &&
      ((BVar3 = VerQueryValueA(local_214,"\\StringFileInfo\\040904E4\\FileVersion",&local_21c,
                               &local_218), BVar3 != 0 ||
       (BVar3 = VerQueryValueA(local_214,"\\StringFileInfo\\040904b0\\FileVersion",&local_21c,
                               &local_218), BVar3 != 0)))) &&
     ((local_21c != (char *)0x0 && (local_218 != 0)))) {
    pcVar4 = local_21c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((int)pcVar4 - (int)(local_21c + 1) < param_3) {
      iVar2 = (int)param_2 - (int)local_21c;
      do {
        cVar1 = *local_21c;
        local_21c[iVar2] = cVar1;
        local_21c = local_21c + 1;
      } while (cVar1 != '\0');
      goto LAB_6800b621;
    }
  }
  *(char *)(size_t)param_2 = '\0'; /* FIXUP: cast away const */
LAB_6800b621:
  if (local_214 != (LPVOID)0x0) {
    Ordinal_1125(&local_214);
  }
  return 0;
}



// ============================================================
// Function: crt_checkUrlSuffix (crt_checkUrlSuffix)
// Address: 6800b650
// Size: 55 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_checkUrlSuffix(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = Ordinal_1201(param_1);
  if (3 < iVar2) {
    sVar1 = Ordinal_1208(&DAT_68176728,iVar2 + -4 + param_1);
    if (sVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: crt_checkInternetState (crt_checkInternetState)
// Address: 6800b690
// Size: 224 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_checkInternetState(int *param_1)
{
  FARPROC pFVar1;
  UINT UVar2;
  int iVar3;
  undefined1 local_120 [4];
  CHAR local_11c;
  undefined1 local_11b [275];
  uint local_8;
  
  if (DAT_68195a74 == (HMODULE)0x0) {
    local_11c = '\0';
    memset(local_11b,0,0x110);
    UVar2 = GetSystemDirectoryA(&local_11c,0x104);
    if (UVar2 != 0) {
      lstrcatA(&local_11c,"\\");
      lstrcatA(&local_11c,"wininet.dll");
      DAT_68195a74 = LoadLibraryA(&local_11c);
    }
  }
  if ((DAT_68195a78 == (FARPROC)0x0) && (DAT_68195a74 != (HMODULE)0x0)) {
    DAT_68195a78 = GetProcAddress(DAT_68195a74,"InternetGetConnectedState");
  }
  pFVar1 = DAT_68195a78;
  *param_1 = 0;
  if (pFVar1 != (FARPROC)0x0) {
    iVar3 = (*pFVar1)(local_120,0);
    *param_1 = 2 - (uint)(iVar3 != 0);
  }
  return 0;
}



// ============================================================
// Function: crt_freeInternetLib (crt_freeInternetLib)
// Address: 6800b770
// Size: 37 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_freeInternetLib(void)
{
  DAT_68195a78 = 0;
  if (DAT_68195a74 != (HMODULE)0x0) {
    FreeLibrary(DAT_68195a74);
    DAT_68195a74 = (HMODULE)0x0;
  }
  return 0;
}



// ============================================================
// Function: crt_initRuntime (crt_initRuntime)
// Address: 6800b7a0
// Size: 21 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_initRuntime(undefined4 *param_1)
{
  cast_initRuntime(param_1);
  return 0;
}



// ============================================================
// Function: crt_stepScriptOnce (crt_stepScriptOnce)
// Address: 6800b7c0
// Size: 30 bytes
// Params: uint param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crt_stepScriptOnce(uint param_1,int param_2)

{
  bool bVar1;
  
  if (param_2 == 0) {
    return false;
  }
  bVar1 = crt_executeStep(param_1,0);
  return bVar1;
}



// ============================================================
// Function: crt_stepScriptForced (crt_stepScriptForced)
// Address: 6800b7e0
// Size: 18 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_stepScriptForced(uint param_1)
{
  crt_executeStep(param_1,1);
  return 0;
}



// ============================================================
// Function: crt_getHandlerEntry (crt_getHandlerEntry)
// Address: 6800b800
// Size: 40 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getHandlerEntry(int param_1)

{
  int in_EAX;
  int unaff_ESI;
  
  if (in_EAX == 0) {
    return 0;
  }
  if (in_EAX + -1 != *(int *)(unaff_ESI + 0x3c)) {
    props_selectScript(unaff_ESI,in_EAX + -1);
  }
  return *(undefined4 *)(**(int **)(unaff_ESI + 0x34) + -4 + param_1 * 4);
}



// ============================================================
// Function: crt_dispatchHandler (crt_dispatchHandler)
// Address: 6800b830
// Size: 61 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchHandler(int *param_1,int param_2,int param_3)
{
  int iVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = crt_getHandlerEntry(param_3);
  if (iVar1 == 0) {
    return 0;
  }
  props_executeHandler(param_1,(int *)param_1[0x3a],iVar1,0,&param_2);
  return 0;
}



// ============================================================
// Function: crt_triggerBehaviors (crt_triggerBehaviors)
// Address: 6800b870
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_triggerBehaviors(void)
{
  crt_dispatchBehaviors();
  return 0;
}



// ============================================================
// Function: crt_loadCodeHints (crt_loadCodeHints)
// Address: 6800b880
// Size: 369 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_loadCodeHints(void)
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *local_42c;
  char *local_428;
  undefined4 local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  if (DAT_68195a7c == 0) {
    local_424 = 0;
    iVar3 = Ordinal_1320(local_420,0);
    if (iVar3 != 0) {
      Ordinal_1316(local_420);
      Ordinal_1317(local_420,"Configuration");
      Ordinal_1317(local_420,"CodeHinting.txt");
      iVar3 = Ordinal_1402(&local_424,local_420,1);
      if (iVar3 == 0) {
        Ordinal_2348(&PTR_DAT_68189740,0xffffffff);
      }
      else {
        iVar3 = Ordinal_1435(local_424);
        local_428 = (char *)Ordinal_1124(iVar3 + 1);
        iVar4 = Ordinal_1409(local_424,local_428,iVar3);
        if ((iVar4 != 0) && (local_428[iVar3] = '\0', pcVar5 = local_428, *local_428 != '\0')) {
LAB_6800b950:
          cVar2 = *pcVar5;
          pcVar6 = pcVar5;
          while (cVar2 != '\0') {
            if ((((cVar2 == '\n') || (cVar2 == '\r')) || (cVar2 == ' ')) ||
               ((cVar2 == '\t' || (cVar2 == ',')))) {
              if (cVar2 != '\0') goto LAB_6800b982;
              break;
            }
            pcVar1 = pcVar6 + 1;
            pcVar6 = pcVar6 + 1;
            cVar2 = *pcVar1;
          }
          goto LAB_6800b9a1;
        }
LAB_6800b9b5:
        Ordinal_1125(&local_428);
        Ordinal_1407(&local_424);
      }
      DAT_68195a7c = 1;
    }
  }
  return 0;
  while( true ) {
    *pcVar6 = '\0';
    cVar2 = pcVar6[1];
    pcVar6 = pcVar6 + 1;
    if (cVar2 == '\0') break;
LAB_6800b982:
    if (((cVar2 != '\n') && (cVar2 != '\r')) &&
       ((cVar2 != ' ' && ((cVar2 != '\t' && (cVar2 != ',')))))) break;
  }
LAB_6800b9a1:
  local_42c = pcVar5;
  Ordinal_2348(&local_42c,1);
  pcVar5 = pcVar6;
  if (*pcVar6 == '\0') goto LAB_6800b9b5;
  goto LAB_6800b950;
}



// ============================================================
// Function: crt_resolveMovieTarget (crt_resolveMovieTarget)
// Address: 6800ba00
// Size: 50 bytes
// Params: int param_1, int * param_2, undefined4 param_3, int * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_resolveMovieTarget(int param_1,int *param_2,undefined4 param_3,int *param_4,undefined4 *param_5)
{
  *param_4 = *(int *)(*param_2 + 0x2c);
  *param_5 = 0;
  if (*param_4 == 0) {
    events_setMiawName(param_1,param_2,param_3,param_4,param_5);
  }
  return 0;
}



// ============================================================
// Function: crt_isUndoComplete (crt_isUndoComplete)
// Address: 6800ba40
// Size: 29 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crt_isUndoComplete(int param_1)

{
  return *(int *)(param_1 + 0xc0) == *(int *)(param_1 + 0xc4);
}



// ============================================================
// Function: crt_advanceUndo (crt_advanceUndo)
// Address: 6800ba60
// Size: 198 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_advanceUndo(uint param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined3 extraout_var;
  
  if (*(int *)(**(int **)(param_1 + 8) + 0x504) < 1) {
    bVar7 = crt_isUndoComplete(param_1);
    if (CONCAT31(extraout_var,bVar7) != 0) {
      props_unwindToFrame(param_1,-1);
      *(undefined4 *)(param_1 + 0xd0) = 1;
      return 0;
    }
    piVar1 = (int *)(param_1 + 0xc4);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xbc) + -1;
    }
    iVar2 = *(int *)(param_1 + 0xc4);
    iVar3 = **(int **)(param_1 + 200);
    uVar4 = *(undefined4 *)(iVar3 + 0x28 + iVar2 * 0xc);
    iVar5 = *(int *)(iVar3 + 0x20 + iVar2 * 0xc);
    uVar6 = *(undefined4 *)(iVar3 + iVar2 * 0xc + 0x24);
    cast_freeHandle(*(undefined4 *)(param_1 + 0xcc));
    *(undefined4 *)(param_1 + 0xcc) = uVar6;
    *(undefined4 *)(param_1 + 0xd0) = uVar4;
    if (-1 < iVar5) {
      props_unwindToFrame(param_1,iVar5);
      return 0;
    }
  }
  *(undefined4 *)(param_1 + 0x74) = 9;
  props_popArgs(param_1,(undefined4 *)0x0);
  props_unwindStack(param_1);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800bb30 - 0x6800c100
// Functions (11):
//   crt_pushUndoEntry
//   crt_dispatchGoTo
//   crt_getPlatformRef
//   crt_getMiawProperty
//   crt_setMiawProperty
//   crt_dispatchPlatformOp
//   crt_setPlatformParam
//   crt_validateFrameIndex
//   crt_getPlatformData
//   crt_getPlatformValue
//   crt_executePlatformQuery

// ============================================================
// Function: crt_pushUndoEntry (crt_pushUndoEntry)
// Address: 6800bb30
// Size: 369 bytes
// Params: uint param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_pushUndoEntry(uint param_1,int param_2,int param_3)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  byte local_408 [1024];
  uint local_8;
  
  iVar4 = events_getDebugOffset(param_1);
  iVar5 = *(int *)(param_1 + 0xd0);
  if (iVar5 < 0) {
    iVar5 = sprites_getEventRef(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
  }
  piVar6 = *(int **)(param_1 + 0xcc);
  if ((piVar6 == (int *)0x0) && (param_2 != 0)) {
    events_shutdownMovie(param_1,local_408);
    piVar6 = props_pascalToHandle(local_408);
  }
  else {
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  iVar3 = *(int *)(param_1 + 0xc4);
  iVar7 = iVar3 + 1;
  *(int *)(param_1 + 0xc4) = iVar7;
  if (*(int *)(param_1 + 0xbc) <= iVar7) {
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  iVar7 = *(int *)(param_1 + 0xc0);
  if (*(int *)(param_1 + 0xc4) == iVar7) {
    iVar9 = *(int *)(**(int **)(param_1 + 200) + 0x20 + iVar7 * 0xc);
    cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 200) + iVar7 * 0xc + 0x24));
    if (-1 < iVar9) {
      iVar7 = props_trimFrames(param_1,iVar9);
      iVar9 = 0;
      if (0 < *(int *)(param_1 + 0xbc)) {
        iVar10 = 0;
        do {
          piVar1 = (int *)(**(int **)(param_1 + 200) + 0x20 + iVar10);
          *piVar1 = *piVar1 - iVar7;
          iVar9 = iVar9 + 1;
          iVar10 = iVar10 + 0xc;
        } while (iVar9 < *(int *)(param_1 + 0xbc));
      }
    }
    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
    if (*(int *)(param_1 + 0xbc) <= *(int *)(param_1 + 0xc0)) {
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
  }
  if (param_3 == 0) {
    uVar8 = 0xffffffff;
  }
  else {
    uVar8 = props_getReturnTarget(param_1);
  }
  puVar2 = (undefined4 *)(**(int **)(param_1 + 200) + 0x20 + iVar3 * 0xc);
  *puVar2 = uVar8;
  puVar2[1] = piVar6;
  puVar2[2] = iVar4 + iVar5;
  return 0;
}



// ============================================================
// Function: crt_dispatchGoTo (crt_dispatchGoTo)
// Address: 6800bcb0
// Size: 400 bytes
// Params: int param_1, uint param_2, int * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchGoTo(int param_1,uint param_2,int *param_3,undefined4 *param_4)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  int local_810;
  int *local_80c;
  int local_808 [256];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_810 = *param_3;
  local_80c = (int *)param_3[1];
  if (param_4 == (undefined4 *)0x0) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    props_cStringToPascal(param_4,local_408);
    puVar4 = local_408;
  }
  if (local_810 - 1U < 0x43) {
    switch(local_810) {
    case 1:
    case 0x40:
    case 0x43:
      props_toPascalString(&local_810,(undefined1 *)local_808);
      piVar3 = local_808;
      uVar1 = param_2 | 2;
      break;
    default:
      goto switchD_6800bd1a_caseD_2;
    case 8:
      if (local_80c == (int *)0x60) {
        piVar3 = (int *)events_navigateMovie(param_1,1);
        uVar1 = param_2 | 1;
      }
      else if (local_80c == (int *)0x160) {
        piVar3 = (int *)events_navigateMovie(param_1,0);
        uVar1 = param_2 | 1;
      }
      else {
        if (local_80c != (int *)0x207) {
          props_setErrorAndReturn(param_1,0x29);
          return 0;
        }
        piVar3 = (int *)events_navigateMovie(param_1,-1);
        uVar1 = param_2 | 1;
      }
      break;
    case 9:
    case 0x20:
    case 0x23:
      if (local_810 == 0x20) {
        iVar2 = 0x20;
      }
      else {
        iVar2 = *local_80c;
      }
      uVar5 = strings_floatToUint64(iVar2,(uint)*(byte *)((int)&PTR_caseD_2_6800be50 + local_810 + 3));
      local_80c = (int *)(size_t)uVar5;
      local_810 = 4;
    case 4:
      uVar1 = param_2 | 1;
      piVar3 = local_80c;
    }
    iVar2 = events_navigateToMovieFrame(param_1,uVar1,(int)puVar4,(int)piVar3);
    if (iVar2 == 0) {
      props_setError(param_1,0x29);
    }
  }
  else {
switchD_6800bd1a_caseD_2:
    props_setErrorAndReturn(param_1,0x29);
  }
  cast_freeHandle(param_4);
  props_releaseValue(param_1,(byte)local_810,local_80c);
  props_restoreScript(param_1);
  return 0;
}



// ============================================================
// Function: crt_getPlatformRef (FUN_6800bea0)
// Address: 6800bea0
// Size: 136 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getPlatformRef(int param_1,int *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = *param_2;
  if (iVar1 - 1U < 0x43) {
    puVar2 = (undefined4 *)(uint)*(byte *)((int)&PTR_caseD_2_6800bf34 + iVar1 + 3);
    switch(iVar1) {
    case 1:
    case 0x40:
    case 0x43:
      props_toPascalString(param_2,local_408);
      iVar1 = events_setMovieLoopMode(param_1,(int)local_408);
      break;
    default:
      goto switchD_6800becb_caseD_2;
    case 4:
      iVar1 = param_2[1];
      break;
    case 9:
    case 0x20:
    case 0x23:
      if (iVar1 == 0x20) {
        uVar3 = 0x20;
      }
      else {
        puVar2 = (undefined4 *)param_2[1];
        uVar3 = *puVar2;
      }
      uVar4 = strings_floatToUint64(puVar2,uVar3);
      iVar1 = (int)uVar4;
    }
    if ((iVar1 < 0x8000) && (0 < iVar1)) goto LAB_6800bf17;
  }
switchD_6800becb_caseD_2:
LAB_6800bf17:
  return 0;
}



// ============================================================
// Function: crt_getMiawProperty (crt_getMiawProperty)
// Address: 6800bf80
// Size: 32 bytes
// Params: uint param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getMiawProperty(uint param_1,int param_2)

{
  uint local_c;
  undefined4 local_8;
  
  events_setMiawActiveFlag(param_1,param_2,&local_c);
  return local_8;
}



// ============================================================
// Function: crt_setMiawProperty (crt_setMiawProperty)
// Address: 6800bfa0
// Size: 42 bytes
// Params: uint param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setMiawProperty(uint param_1,int param_2,undefined4 param_3)
{
  uint local_c;
  undefined4 local_8;
  
  local_8 = param_3;
  local_c = 4;
  events_getMiawActiveFlag(param_1,param_2,&local_c);
  return 0;
}



// ============================================================
// Function: crt_dispatchPlatformOp (FUN_6800bfd0)
// Address: 6800bfd0
// Size: 30 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchPlatformOp(int param_1,int param_2,int param_3)
{
  sprites_getChannelBounds(param_1,param_2,1,param_3,(uint *)&stack0x00000010);
  return 0;
}



// ============================================================
// Function: crt_setPlatformParam (FUN_6800bff0)
// Address: 6800bff0
// Size: 51 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_setPlatformParam(int param_1,int param_2)

{
  if (((*(int *)(param_1 + 0x7c) == 0) && (0 < param_2)) && (param_2 <= *(int *)(param_1 + 0xf4))) {
    return 1;
  }
  props_setError(param_1,0x2a);
  return 0;
}



// ============================================================
// Function: crt_validateFrameIndex (crt_validateFrameIndex)
// Address: 6800c030
// Size: 50 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_validateFrameIndex(int param_1,int param_2)

{
  if (((*(int *)(param_1 + 0x7c) == 0) && (-1 < param_2)) && (param_2 <= *(int *)(param_1 + 0xf4)))
  {
    return 1;
  }
  props_setError(param_1,0x2a);
  return 0;
}



// ============================================================
// Function: crt_getPlatformData (FUN_6800c070)
// Address: 6800c070
// Size: 61 bytes
// Params: int param_1, int * param_2, undefined1 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getPlatformData(int param_1,int *param_2,undefined1 *param_3)

{
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    props_setErrorAndReturn(param_1,10);
    return 0;
  }
  props_toPascalString(param_2,param_3);
  return 1;
}



// ============================================================
// Function: crt_getPlatformValue (FUN_6800c0b0)
// Address: 6800c0b0
// Size: 75 bytes
// Params: int param_1, short * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getPlatformValue(int param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  if (0 < *param_2) {
    sVar1 = *param_2;
    uVar2 = sprites_getMemberCount(param_1);
    if ((sVar1 <= (short)uVar2) && (0 < param_2[1])) {
      iVar3 = sprites_getMemberByChannel(param_1,sVar1);
      if (param_2[1] <= iVar3) {
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: crt_executePlatformQuery (FUN_6800c100)
// Address: 6800c100
// Size: 259 bytes
// Params: int param_1, int * param_2, undefined * param_3, short * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_executePlatformQuery(int param_1,int *param_2,undefined *param_3,short *param_4)
{
  int iVar1;
  ulonglong uVar2;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = *param_2;
  if (0x42 < iVar1 - 1U) goto switchD_6800c13d_caseD_2;
  switch(iVar1) {
  case 1:
  case 0x40:
  case 0x43:
    props_toPascalString(param_2,local_408);
    (*(code *)param_3)(param_1,local_408,param_4);
    return 0;
  case 3:
    iVar1 = (**(code **)(**(int **)param_2[1] + 0x14))(param_1,(undefined4 *)param_2[1],&local_40c);
    if (iVar1 != 0) break;
  default:
switchD_6800c13d_caseD_2:
    props_setErrorAndReturn(param_1,0x24);
    param_4[1] = -1;
    return 0;
  case 4:
    local_40c = param_2[1];
    break;
  case 9:
  case 0x20:
  case 0x23:
    if (iVar1 == 0x20) {
      uVar2 = strings_floatToUint64(0x20,(uint)*(byte *)((int)&PTR_caseD_2_6800c214 + iVar1 + 3));
      local_40c = (int)uVar2;
    }
    else {
      uVar2 = strings_floatToUint64(iVar1,param_2[1]);
      local_40c = (int)uVar2;
    }
  }
  if (*param_4 == 0) {
    *param_4 = (short)((uint)local_40c >> 0x10);
  }
  param_4[1] = (short)local_40c;
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800c260 - 0x6800c950
// Functions (14):
//   crt_resolvePlatformChannel
//   crt_executePlatformCmd
//   crt_executePlatformSet
//   crt_executePlatformSetEx
//   crt_getMemberCursor
//   crt_resolveSpriteRange
//   crt_invokeHandlerCallback
//   crt_executePlatformOp
//   crt_dispatchPendingGoTo
//   crt_executeLingoOp
//   crt_executeStep
//   crt_getPlatformState
//   crt_destroyBehavior
//   crt_formatScriptError

// ============================================================
// Function: crt_resolvePlatformChannel (crt_resolvePlatformChannel)
// Address: 6800c260
// Size: 252 bytes
// Params: int param_1, int * param_2, undefined * param_3, short * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_resolvePlatformChannel(int param_1,int *param_2,undefined *param_3,short *param_4)
{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  short local_40c [2];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar2 = *param_2;
  if (0x42 < iVar2 - 1U) goto switchD_6800c29d_caseD_2;
  switch(iVar2) {
  case 1:
  case 0x40:
  case 0x43:
    props_toPascalString(param_2,local_408);
    sVar1 = (*(code *)param_3)(param_1,local_408);
    *param_4 = sVar1;
    return 0;
  case 3:
    iVar2 = (**(code **)(**(int **)param_2[1] + 0x14))(param_1,(undefined4 *)param_2[1],local_40c);
    if (iVar2 != 0) goto LAB_6800c317;
  default:
switchD_6800c29d_caseD_2:
    props_setErrorAndReturn(param_1,0x24);
    param_4[1] = -1;
    break;
  case 4:
    local_40c[0] = (short)param_2[1];
    goto LAB_6800c317;
  case 9:
  case 0x20:
  case 0x23:
    if (iVar2 == 0x20) {
      uVar3 = strings_floatToUint64(0x20,(uint)*(byte *)((int)&PTR_caseD_2_6800c36c + iVar2 + 3));
      local_40c[0] = (short)uVar3;
    }
    else {
      uVar3 = strings_floatToUint64(iVar2,param_2[1]);
      local_40c[0] = (short)uVar3;
    }
LAB_6800c317:
    if (*param_4 == 0) {
      *param_4 = local_40c[0];
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: crt_executePlatformCmd (FUN_6800c3c0)
// Address: 6800c3c0
// Size: 89 bytes
// Params: int param_1, int * param_2, undefined * param_3, short * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_executePlatformCmd(int param_1,int *param_2,undefined *param_3,short *param_4,int param_5)

{
  int iVar1;
  
  crt_executePlatformQuery(param_1,param_2,param_3,param_4);
  sprites_checkBounds(param_1,param_4);
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar1 = crt_getPlatformValue(param_1,param_4);
    if (iVar1 == 0) {
      props_setErrorAndReturn(param_1,param_5);
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: crt_executePlatformSet (FUN_6800c420)
// Address: 6800c420
// Size: 96 bytes
// Params: int param_1, int * param_2, undefined * param_3, short * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_executePlatformSet(int param_1,int *param_2,undefined *param_3,short *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  crt_executePlatformQuery(param_1,param_2,param_3,param_4);
  sprites_checkBounds(param_1,param_4);
  if (*(int *)(param_1 + 0x7c) == 0) {
    uVar1 = sprites_getMemberInfo(param_1,(undefined4 *)param_4);
    iVar2 = sprites_validateMemberRef(param_1,uVar1);
    if (iVar2 == 0) {
      props_setErrorAndReturn(param_1,param_5);
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: crt_executePlatformSetEx (crt_executePlatformSetEx)
// Address: 6800c480
// Size: 102 bytes
// Params: int param_1, int * param_2, undefined * param_3, short * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_executePlatformSetEx(int param_1,int *param_2,undefined *param_3,short *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  crt_resolvePlatformChannel(param_1,param_2,param_3,param_4);
  if (*param_4 < 0) {
    return 0;
  }
  sprites_checkBounds(param_1,param_4);
  if (*(int *)(param_1 + 0x7c) == 0) {
    uVar1 = sprites_getMemberInfo(param_1,(undefined4 *)param_4);
    iVar2 = sprites_validateMemberRef(param_1,uVar1);
    if (iVar2 == 0) {
      props_setErrorAndReturn(param_1,param_5);
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: crt_getMemberCursor (crt_getMemberCursor)
// Address: 6800c4f0
// Size: 53 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getMemberCursor(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  
  ppuVar3 = &param_2;
  iVar1 = sprites_getMemberInfo(param_1,param_2);
  uVar2 = sprites_dispatchCursorProperty(param_1,iVar1,ppuVar3);
  if (param_2 == (undefined4 *)0x0) {
    props_setError(param_1,0x25);
  }
  return uVar2;
}



// ============================================================
// Function: crt_resolveSpriteRange (crt_resolveSpriteRange)
// Address: 6800c530
// Size: 278 bytes
// Params: int param_1, int * param_2, int * param_3, int param_4
// Return: short
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short crt_resolveSpriteRange(int param_1,int *param_2,int *param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  iVar3 = props_getInt(param_1);
  if ((short)iVar3 < 1) {
    sVar2 = 1;
    sVar1 = 0x7fff;
  }
  else {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    sVar1 = crt_getPlatformRef(param_1,&local_c);
    if (*(short *)(param_1 + 0x7c) != 0) {
      return *(short *)(param_1 + 0x7c);
    }
    sVar2 = sVar1;
    if ((short)iVar3 < 2) {
      if (param_4 != 0) {
        sVar2 = sprites_getEventRef(param_1);
      }
    }
    else {
      _DAT_68197764 =
           (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                  *(int *)(param_1 + 0x18));
      local_8 = DAT_6819776c;
      local_c = DAT_68197768;
      if (_DAT_68197764 != (int *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        local_8 = ((int *)(size_t)_DAT_68197764)[1];
        local_c = *(int *)(size_t)_DAT_68197764;
      }
      sVar1 = crt_getPlatformRef(param_1,&local_c);
    }
  }
  *param_2 = (int)sVar2;
  *param_3 = (int)sVar1;
  return 0;
}



// ============================================================
// Function: crt_invokeHandlerCallback (crt_invokeHandlerCallback)
// Address: 6800c650
// Size: 146 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_invokeHandlerCallback(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)
{
  bool bVar1;
  undefined3 extraout_var;
  int local_30 [2];
  int local_28 [3];
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28[1] = 1;
  props_clearValue(param_1,local_30);
  local_14 = param_4;
  local_c = param_3;
  local_28[2] = 3;
  local_1c = param_2;
  local_18 = 8;
  local_10 = 4;
  bVar1 = cast_executeHandler(param_1,param_2,0x3bb,3,(uint *)(local_28 + 2),local_30,local_28);
  if ((CONCAT31(extraout_var,bVar1) != 0) && (local_28[0] == 0)) {
    props_requireInt((int)param_1,local_30,local_28 + 1);
  }
  return 0;
}



// ============================================================
// Function: crt_executePlatformOp (FUN_6800c6f0)
// Address: 6800c6f0
// Size: 180 bytes
// Params: int param_1, int * param_2, short param_3, int param_4, int * param_5, undefined4 * param_6, undefined4 * param_7, undefined1 * param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_executePlatformOp(int param_1,int *param_2,short param_3,int param_4,int *param_5,
                 undefined4 *param_6,undefined4 *param_7,undefined1 *param_8)
{
  undefined4 local_470;
  undefined4 local_46c;
  undefined1 *local_468;
  undefined4 local_464 [279];
  uint local_8;
  
  *param_7 = 0;
  *param_6 = 0;
  local_468 = param_8;
  *param_5 = 0;
  crt_resolveMovieTarget(param_1,param_2,(int)param_3,param_5,param_6);
  if (*param_5 != 0) {
    props_parseToken(local_464,*param_5);
    props_parseBlock(param_1,(int)local_464,param_4 + -1,&local_470,&local_46c);
    *param_7 = local_46c;
    if (local_468 != (undefined1 *)0x0) {
      props_extractWordToken(param_1,local_464,local_468);
    }
  }
  return 0;
}



// ============================================================
// Function: crt_dispatchPendingGoTo (crt_dispatchPendingGoTo)
// Address: 6800c7b0
// Size: 82 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchPendingGoTo(int param_1)
{
  undefined4 *puVar1;
  int local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0xcc);
  if ((puVar1 != (undefined4 *)0x0) || (0 < *(int *)(param_1 + 0xd0))) {
    local_8 = *(undefined4 *)(param_1 + 0xd0);
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
    local_c = 4;
    crt_dispatchGoTo(param_1,4,&local_c,puVar1);
  }
  return 0;
}



// ============================================================
// Function: crt_executeLingoOp (crt_executeLingoOp)
// Address: 6800c810
// Size: 76 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crt_executeLingoOp(int param_1,int *param_2,undefined4 param_3,uint param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  
  uVar3 = events_getScoreProperty2(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0xf4) = uVar3;
  bVar2 = props_dispatchOpcode((int *)param_1,param_2,param_3,param_4);
  if (*(int *)(param_1 + 0x7c) == 0) {
    crt_dispatchPendingGoTo(param_1);
  }
  *param_5 = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  return CONCAT31(extraout_var,bVar2);
}



// ============================================================
// Function: crt_executeStep (crt_executeStep)
// Address: 6800c860
// Size: 65 bytes
// Params: uint param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crt_executeStep(uint param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  
  uVar1 = param_1;
  bVar2 = crt_isUndoComplete(param_1);
  bVar2 = CONCAT31(extraout_var,bVar2) == 0;
  if (bVar2) {
    crt_advanceUndo(uVar1);
    if ((param_2 != 0) && (-1 < *(int *)(uVar1 + 0x40))) {
      crt_executeLingoOp(uVar1,7,0,0,&param_1);
    }
  }
  return bVar2;
}



// ============================================================
// Function: crt_getPlatformState (FUN_6800c8b0)
// Address: 6800c8b0
// Size: 46 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getPlatformState(void)

{
  undefined4 uVar1;
  
  Ordinal_1114();
  uVar1 = sprites_getEventContext();
  Ordinal_1115();
  return uVar1;
}



// ============================================================
// Function: crt_destroyBehavior (crt_destroyBehavior)
// Address: 6800c8e0
// Size: 104 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_destroyBehavior(int param_1,int *param_2)
{
  uint uVar1;
  
  crt_getPlatformState();
  if ((*(byte *)(*param_2 + 9) & 0x40) == 0) {
    sprites_initEventContext();
  }
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: crt_formatScriptError (crt_formatScriptError)
// Address: 6800c950
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_formatScriptError(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x2b);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800c990 - 0x6800d090
// Functions (5):
//   crt_dispatchSpriteProperty
//   crt_createSprite
//   crt_iterateBehaviors
//   crt_dispatchBehaviors
//   crt_dispatchSpriteOp

// ============================================================
// Function: crt_dispatchSpriteProperty (crt_dispatchSpriteProperty)
// Address: 6800c990
// Size: 895 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchSpriteProperty(int param_1,int *param_2,int param_3,int param_4,int *param_5)
{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_4 < 0x168) {
    if (param_4 == 0x167) {
switchD_6800c9d5_caseD_58:
      if (param_3 == 0) {
        uVar4 = sprites_getPropertyId(param_1,*(undefined4 *)(*param_2 + 10));
        param_5[1] = uVar4;
        goto LAB_6800ca02;
      }
      iVar2 = props_requireInt(param_1,param_5,&local_1c);
      if (iVar2 == 0) goto LAB_6800ca02;
      if (*(short *)(*param_2 + 0xc) != 0) {
        crt_getPlatformState();
      }
      uVar3 = sprites_dispatchProperty(param_1,local_1c);
      *(undefined4 *)(*param_2 + 10) = uVar3;
      crt_getPlatformState();
    }
    else {
      switch(param_4) {
      case 0x48:
        if (param_3 == 0) {
          param_5[1] = *(int *)(*param_2 + 0x20);
          goto LAB_6800ca02;
        }
        iVar2 = props_requireInt(param_1,param_5,&local_1c);
        if (iVar2 == 0) goto LAB_6800ca02;
        *(int *)(*param_2 + 0x20) = local_1c;
        break;
      case 0x49:
        if (param_3 == 0) {
          param_5[1] = *(int *)(*param_2 + 0x24);
          goto LAB_6800ca02;
        }
        iVar2 = props_requireInt(param_1,param_5,&local_1c);
        if (iVar2 == 0) goto LAB_6800ca02;
        *(int *)(*param_2 + 0x24) = local_1c;
        break;
      default:
        goto switchD_6800c9d5_caseD_4a;
      case 0x52:
        if (param_3 == 0) {
          param_5[1] = *(int *)(*param_2 + 0x1c);
          goto LAB_6800ca02;
        }
        iVar2 = props_requireInt(param_1,param_5,&local_1c);
        if (iVar2 == 0) goto LAB_6800ca02;
        *(int *)(*param_2 + 0x1c) = local_1c;
        break;
      case 0x53:
        if (param_3 == 0) {
          param_5[1] = *(int *)(*param_2 + 0x18);
          goto LAB_6800ca02;
        }
        iVar2 = props_requireInt(param_1,param_5,&local_1c);
        if (iVar2 == 0) goto LAB_6800ca02;
        *(int *)(*param_2 + 0x18) = local_1c;
        break;
      case 0x58:
        goto switchD_6800c9d5_caseD_58;
      case 0xbc:
        if (param_3 == 0) {
          iVar2 = *param_2;
          local_18 = *(undefined4 *)(iVar2 + 0x4c);
          local_14 = *(undefined4 *)(iVar2 + 0x50);
          local_10 = *(undefined4 *)(iVar2 + 0x54);
          local_c = *(undefined4 *)(iVar2 + 0x58);
          props_computeRectOp(param_1,&local_18,param_5);
          goto LAB_6800ca02;
        }
        break;
      case 0x139:
        if (param_3 == 0) {
          param_5[1] = (uint)*(byte *)(*param_2 + 8);
          goto LAB_6800ca02;
        }
        iVar2 = props_requireInt(param_1,param_5,&local_1c);
        if (iVar2 == 0) goto LAB_6800ca02;
        *(byte *)(*param_2 + 8) = (byte)local_1c;
      }
    }
  }
  else {
    switch(param_4) {
    case 0x168:
      if (param_3 == 0) {
        param_5[1] = (uint)*(byte *)(*param_2 + 0x14);
        goto LAB_6800ca02;
      }
      iVar2 = props_requireInt(param_1,param_5,&local_1c);
      if (iVar2 == 0) goto LAB_6800ca02;
      *(byte *)(*param_2 + 0x14) = (byte)local_1c;
      break;
    case 0x169:
      if (param_3 == 0) {
        param_5[1] = (uint)*(byte *)(*param_2 + 0x15);
        goto LAB_6800ca02;
      }
      iVar2 = props_requireInt(param_1,param_5,&local_1c);
      if (iVar2 == 0) goto LAB_6800ca02;
      *(byte *)(*param_2 + 0x15) = (byte)local_1c;
      break;
    default:
switchD_6800c9d5_caseD_4a:
      return 0;
    case 0x16b:
switchD_6800cb82_caseD_16b:
      if (param_3 == 0) goto LAB_6800cc92;
      iVar2 = props_requireInt(param_1,param_5,&local_1c);
      if (iVar2 == 0) goto LAB_6800ca02;
      if (local_1c == 0) {
        pbVar1 = (byte *)(*param_2 + 9);
        *pbVar1 = *pbVar1 & 0x7f;
      }
      else {
        pbVar1 = (byte *)(*param_2 + 9);
        *pbVar1 = *pbVar1 | 0x80;
      }
      break;
    case 0x16c:
      if (param_3 == 0) {
        param_5[1] = *(byte *)(*param_2 + 9) & 0x3f;
        goto LAB_6800ca02;
      }
      iVar2 = props_requireInt(param_1,param_5,&local_1c);
      if (iVar2 == 0) goto LAB_6800ca02;
      pbVar1 = (byte *)(*param_2 + 9);
      *pbVar1 = *pbVar1 ^ (*(byte *)(*param_2 + 9) ^ (byte)local_1c) & 0x3f;
      break;
    case 0x1e2:
      if (param_3 != 0) {
        iVar2 = props_requireInt(param_1,param_5,&local_1c);
        if (iVar2 == 0) goto LAB_6800ca02;
        if (local_1c == 0) {
          pbVar1 = (byte *)(*param_2 + 9);
          *pbVar1 = *pbVar1 & 0xbf;
        }
        else {
          pbVar1 = (byte *)(*param_2 + 9);
          *pbVar1 = *pbVar1 | 0x40;
        }
        goto switchD_6800cb82_caseD_16b;
      }
      param_5[1] = *(byte *)(*param_2 + 9) >> 6 & 1;
LAB_6800cc92:
      param_5[1] = (uint)(*(byte *)(*param_2 + 9) >> 7);
      goto LAB_6800ca02;
    case 0x1f5:
      if (param_3 == 0) {
        local_20 = *(undefined4 *)(*param_2 + 0x18);
        local_24 = *(undefined4 *)(*param_2 + 0x1c);
        props_transformRect(param_1,&local_24,param_5);
        goto LAB_6800ca02;
      }
      iVar2 = props_getRectField(param_1,param_5);
      if (iVar2 != 0) {
        *(int *)(*param_2 + 0x18) = (int)(short)local_20;
        *(int *)(*param_2 + 0x1c) = (int)(short)local_24;
      }
    }
  }
  *(undefined4 *)(*param_2 + 0x5c) = 1;
LAB_6800ca02:
  return 0;
}



// ============================================================
// Function: crt_createSprite (crt_createSprite)
// Address: 6800cee0
// Size: 133 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_createSprite(int param_1)
{
  undefined4 *puVar1;
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)cast_allocHandle(0x60,1);
  if (local_8 == (int *)0x0) {
    props_setError(param_1,2);
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  puVar1 = (undefined4 *)*local_8;
  *(undefined2 *)((int)puVar1 + 10) = 1;
  *(undefined2 *)(puVar1 + 3) = 1;
  *puVar1 = &PTR_LAB_68189510;
  puVar1[1] = 1;
  *(undefined1 *)(puVar1 + 2) = 0x10;
  *(undefined1 *)(puVar1 + 5) = 0xff;
  puVar1[6] = 100;
  puVar1[7] = 100;
  puVar1[8] = 100;
  puVar1[9] = 100;
  puVar1[0x17] = 1;
  local_c = 3;
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: crt_iterateBehaviors (crt_iterateBehaviors)
// Address: 6800cf70
// Size: 242 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_iterateBehaviors(void)
{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  uint local_10;
  int *local_c;
  uint local_8;
  
  if (unaff_EDI != (int *)0x0) {
    *(int *)(*unaff_EDI + 4) = *(int *)(*unaff_EDI + 4) + 1;
    iVar2 = 0;
    iVar1 = props_getListLength(unaff_ESI,unaff_EDI);
    if (0 < iVar1) {
      do {
        if (*(int *)(*unaff_EDI + 4) < 2) break;
        props_getListEntry(unaff_ESI,unaff_EDI,iVar2,&local_10);
        if (local_10 == 3) {
          props_pushValue((int)unaff_ESI);
          unaff_ESI[7] = local_10;
          unaff_ESI[8] = (int)local_c;
          props_pushValue((int)unaff_ESI);
          local_8 = (uint)*(ushort *)(unaff_ESI + 0x1d);
          unaff_ESI[8] = 1;
          iVar1 = (**(code **)(*(int *)*local_c + 4))();
          if (iVar1 == 0) {
            unaff_ESI[6] = unaff_ESI[6] + -8;
            iVar1 = *(int *)unaff_ESI[4];
            unaff_ESI[7] = *(int *)(iVar1 + unaff_ESI[6]);
            unaff_ESI[8] = *(int *)(iVar1 + 4 + unaff_ESI[6]);
            props_popValue((int)unaff_ESI);
          }
          else {
            if ((unaff_ESI[0x1d] == 2) &&
               (props_dispatchOpcode(unaff_ESI,(int *)0x2,0,0), unaff_ESI[0x1d] == 8)) break;
            unaff_ESI[0x1d] = (int)(short)local_8;
          }
        }
        else {
          props_releaseValue(unaff_ESI,(byte)local_10,local_c);
        }
        iVar2 = iVar2 + 1;
        iVar1 = props_getListLength(unaff_ESI,unaff_EDI);
      } while (iVar2 < iVar1);
    }
    props_releaseObject(unaff_ESI,unaff_EDI);
  }
  return 0;
}



// ============================================================
// Function: crt_dispatchBehaviors (crt_dispatchBehaviors)
// Address: 6800d070
// Size: 27 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchBehaviors(void)
{
  crt_iterateBehaviors();
  return 0;
}



// ============================================================
// Function: crt_dispatchSpriteOp (crt_dispatchSpriteOp)
// Address: 6800d090
// Size: 999 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_dispatchSpriteOp(uint param_1,int *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int *local_c;
  uint local_8;
  
  iVar1 = *param_2;
  local_c = param_2;
  local_34 = (int *)0x0;
  if (param_3 < 0x23f) {
    if (param_3 == 0x23e) {
      if (*(int *)(iVar1 + 0x5c) != 0) {
        iVar1 = Ordinal_1114(param_2);
        sprites_clearEventContext();
        if ((*(byte *)(iVar1 + 9) & 0x40) == 0) {
          sprites_initEventContext();
        }
        sprites_initEventContext();
        *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar1 + 0x4c);
        *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x50);
        *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar1 + 0x54);
        *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar1 + 0x58);
        *(undefined4 *)(iVar1 + 0x5c) = 0;
        Ordinal_1115(local_c);
        props_popArgs(param_1,(undefined4 *)0x0);
        return 0;
      }
      iVar1 = crt_getPlatformState();
      if (iVar1 != 0) {
        *(undefined4 *)(*param_2 + 0x5c) = 1;
        props_popArgs(param_1,(undefined4 *)0x0);
        return 0;
      }
      goto switchD_6800d2de_caseD_241;
    }
    switch(param_3) {
    case 0x39:
    case 0x3a:
      local_2c = 0;
      goto LAB_6800d439;
    default:
      goto switchD_6800d0dc_caseD_3b;
    case 0xd5:
      iVar1 = props_getTypedValue(param_1,2,8,(uint *)&local_c);
      if (iVar1 != 0) {
        local_30 = 4;
        crt_dispatchSpriteProperty(param_1,param_2,0,(int)local_c,&local_30);
        props_popArgs(param_1,&local_30);
        return 0;
      }
      break;
    case 0xdc:
      iVar1 = props_getInt(param_1);
      if (iVar1 != 3) {
        props_setError(param_1,0x17);
        return 0;
      }
      iVar1 = props_getTypedValue(param_1,2,8,(uint *)&local_c);
      if (iVar1 != 0) {
        _DAT_68197764 =
             (int *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                    *(int *)(param_1 + 0x18));
        local_2c = DAT_6819776c;
        local_30 = DAT_68197768;
        if (_DAT_68197764 != (int *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_2c = ((int *)(size_t)_DAT_68197764)[1];
          local_30 = *(int *)(size_t)_DAT_68197764;
        }
        crt_dispatchSpriteProperty(param_1,param_2,1,(int)local_c,&local_30);
        props_popArgs(param_1,(undefined4 *)0x0);
        return 0;
      }
      break;
    case 0xe3:
      score_resolveType(param_1);
      return 0;
    }
  }
  else {
    switch(param_3) {
    case 0x23f:
      iVar2 = props_getInt(param_1);
      if (1 < iVar2) {
        local_14 = *(undefined4 *)(iVar1 + 0x50);
        local_18 = *(undefined4 *)(iVar1 + 0x4c);
        local_10 = *(undefined4 *)(iVar1 + 0x54);
        local_c = *(int **)(iVar1 + 0x58);
        iVar1 = **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                *(int *)(param_1 + 0x18);
        if ((iVar1 != 0) &&
           (iVar1 = props_intersectTwoRects(param_1,&local_18,*(undefined4 **)(iVar1 + 4),&local_18),
           iVar1 != 0)) {
          crt_getPlatformState();
          props_popArgs(param_1,(undefined4 *)0x0);
          return 0;
        }
      }
      break;
    case 0x240:
      crt_getPlatformState();
      props_popArgs(param_1,(undefined4 *)0x0);
      return 0;
    case 0x241:
      break;
    case 0x242:
      iVar2 = props_getInt(param_1);
      if (iVar2 < 3) break;
      local_28 = *(undefined4 *)(iVar1 + 0x4c);
      local_20 = *(undefined4 *)(iVar1 + 0x54);
      local_24 = *(undefined4 *)(iVar1 + 0x50);
      local_1c = *(undefined4 *)(iVar1 + 0x58);
      iVar1 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20) * -8 + 8 +
              **(int **)(param_1 + 0x10);
      if (iVar1 != 0) {
        local_c = *(int **)(iVar1 + 4);
      }
      iVar1 = *(int *)(param_1 + 0x18) + (2 - *(int *)(param_1 + 0x20)) * 8 +
              **(int **)(param_1 + 0x10);
      if (iVar1 != 0) {
        local_10 = *(undefined4 *)(iVar1 + 4);
      }
      iVar1 = props_intersectRect(param_1,&local_10,&local_28);
      local_2c = 0;
      if (iVar1 != 0) {
        Ordinal_1114(param_2);
        uVar3 = xtra_getPlatformVersion();
        Ordinal_1115(param_2);
        local_2c = uVar3;
      }
LAB_6800d439:
      local_34 = &local_30;
      local_30 = 4;
      break;
    default:
switchD_6800d0dc_caseD_3b:
      return 0;
    }
  }
switchD_6800d2de_caseD_241:
  props_popArgs(param_1,local_34);
  return 0;
}



