// Module: sprites
// Topic: Runtime operations, environment, platform, file access, error handling, and networking
// Address range: 0x6807AD00 - 0x6807CF40
// Functions (65):
//   sprites_exitApplication
//   sprites_checkFileType
//   sprites_shutdownApp
//   sprites_restartApp
//   sprites_quitApp
//   sprites_haltApp
//   sprites_collectStageEvents
//   sprites_resolveFilePath
//   sprites_initTextForMember
//   sprites_setPropertyExData
//   sprites_setCursorWait
//   sprites_setCursorArrow
//   sprites_setCursorHand
//   sprites_setCursorCrosshair
//   sprites_beep
//   sprites_delay
//   sprites_getSystemPath
//   sprites_openUrl
//   sprites_launchExternalApp
//   sprites_getEnvironmentInfo
//   sprites_getSystemInfo
//   sprites_getPlatformInfo
//   sprites_getMediaPlayerVersion
//   sprites_getQuickTimeVersion
//   sprites_getColorDepth
//   sprites_getDisplayRect
//   sprites_getDesktopRect
//   sprites_getFreeMemory
//   sprites_getLastError
//   sprites_setLastError
//   sprites_getNetworkError
//   sprites_getNetworkErrorString
//   sprites_setAlertHook
//   sprites_showAlert
//   sprites_openFileDialog
//   sprites_getStageHandle
//   sprites_getWindowHandle
//   sprites_getStageRef
//   sprites_getChannelRefById
//   sprites_getChannelRef
//   sprites_getMovieRef
//   sprites_getMovieRefByPath
//   sprites_getCastRef
//   sprites_getCastRefByName
//   sprites_allocMemory
//   sprites_freeMemory
//   sprites_lockMemory
//   sprites_unlockMemory
//   sprites_getMemorySize
//   sprites_resizeMemory
//   sprites_sendMessage
//   sprites_sendNetMessage
//   sprites_readNetData
//   sprites_getNetStatus
//   sprites_cancelNetOp
//   sprites_getNetProgress
//   sprites_getNetResult
//   sprites_getNetResultString
//   sprites_getNetErrorCode
//   sprites_getNetDoneFlag
//   sprites_getNetState
//   sprites_getNetUrl
//   sprites_getNetLocalPath
//   sprites_getNetMimeType
//   sprites_downloadNetFile


// ============================================================
// Function: sprites_exitApplication (FUN_6807ad00)
// Address: 6807ad00
// Size: 7 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_exitApplication(void)
{
  Ordinal_1770();
  return 0;
}



// ============================================================
// Function: sprites_checkFileType (FUN_6807ad10)
// Address: 6807ad10
// Size: 41 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_checkFileType(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(char *)(param_2 + 0x18) == '/') && ((*(byte *)(param_2 + 0x14) & 0x10) != 0)) {
    uVar1 = 1;
  }
  if (*(char *)(param_2 + 0x18) == '5') {
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: sprites_shutdownApp (FUN_6807ad40)
// Address: 6807ad40
// Size: 10 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_shutdownApp(void)
{
  sprites_exitApplication();
  return 0;
}



// ============================================================
// Function: sprites_restartApp (FUN_6807ad50)
// Address: 6807ad50
// Size: 10 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_restartApp(void)
{
  sprites_exitApplication();
  return 0;
}



// ============================================================
// Function: sprites_quitApp (FUN_6807ad60)
// Address: 6807ad60
// Size: 10 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_quitApp(void)
{
  sprites_exitApplication();
  return 0;
}



// ============================================================
// Function: sprites_haltApp (FUN_6807ad70)
// Address: 6807ad70
// Size: 10 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_haltApp(void)
{
  sprites_exitApplication();
  return 0;
}



// ============================================================
// Function: sprites_collectStageEvents (FUN_6807ad80)
// Address: 6807ad80
// Size: 144 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_collectStageEvents(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x2c) + 8) + 0x14);
  Ordinal_1803();
  uVar2 = stage_handleEvent(iVar1,1);
  uVar3 = stage_handleEvent(iVar1,4);
  uVar4 = stage_handleEvent(iVar1,3);
  uVar5 = stage_handleEvent(iVar1,2);
  uVar6 = stage_handleEvent(iVar1,5);
  uVar7 = stage_handleEvent(iVar1,6);
  uVar8 = stage_handleEvent(iVar1,7);
  uVar9 = stage_handleEvent(iVar1,8);
  uVar10 = stage_handleEvent(iVar1,9);
  uVar11 = stage_handleEvent(iVar1,10);
  uVar12 = stage_handleEvent(iVar1,0xb);
  return uVar12 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11;
}



// ============================================================
// Function: sprites_resolveFilePath (FUN_6807ae10)
// Address: 6807ae10
// Size: 290 bytes
// Params: int param_1, int param_2, byte * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resolveFilePath(int param_1,int param_2,byte *param_3)
{
  int iVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  byte *pbVar5;
  int local_8;
  
  local_8 = 0;
  if (param_3 == (byte *)0x0) {
LAB_6807ae42:
    bVar4 = false;
  }
  else {
    if (*param_3 == 0xff) {
      uVar2 = Ordinal_1201(param_3 + 1);
    }
    else {
      uVar2 = (ushort)*param_3;
    }
    if (uVar2 == 0) goto LAB_6807ae42;
    bVar4 = true;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_8 = Ordinal_1126(0x418,0);
  if (local_8 == 0) goto LAB_6807af21;
  pbVar5 = (byte *)(param_2 + 1);
  Ordinal_1309(local_8,0x400,pbVar5,2);
  iVar3 = scoreEngine_setPropertyEx(*(int *)(iVar1 + 0x20),local_8,0x1e,0,0);
  if (iVar3 == 0) {
    if (bVar4) {
      param_1 = Ordinal_1126(0x3ff,0);
      if (param_1 == 0) goto LAB_6807af21;
      Ordinal_1309(local_8,0x400,pbVar5,2);
      iVar3 = Ordinal_1314(local_8,param_1,0x3ff);
      if (iVar3 == 0) {
        Ordinal_1127(&param_1);
        Ordinal_1127(&local_8);
        return 0;
      }
      Ordinal_1309(local_8,0x400,param_1,2);
      Ordinal_1127(&param_1);
      goto LAB_6807af08;
    }
    iVar3 = 0;
  }
  else {
LAB_6807af08:
    pbVar5 = param_3 + 1;
    iVar3 = local_8;
  }
  Ordinal_1550(iVar3,pbVar5);
  *(undefined4 *)(iVar1 + 0x170) = 0;
LAB_6807af21:
  Ordinal_1127(&local_8);
  return 0;
}



// ============================================================
// Function: sprites_initTextForMember (FUN_6807af40)
// Address: 6807af40
// Size: 72 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_initTextForMember(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  sprites_initTextState(piVar1);
  if ((*(short *)((int)param_2 + 2) != 0) && (piVar1[0x5f] != 0)) {
    iVar2 = sprites_initTextEditor(piVar1,param_2);
    if (iVar2 == 0) {
      sprites_initTextState(piVar1);
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: sprites_setPropertyExData (FUN_6807af90)
// Address: 6807af90
// Size: 41 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setPropertyExData(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_setPropertyExData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: sprites_setCursorWait (FUN_6807afc0)
// Address: 6807afc0
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setCursorWait(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  *(undefined4 *)(*(int *)((*(int **)(param_1 + 8))[1] + 0x2c) + 0x18) = 5;
  iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x18);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 5;
  }
  return 0;
}



// ============================================================
// Function: sprites_setCursorArrow (FUN_6807aff0)
// Address: 6807aff0
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setCursorArrow(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  *(undefined4 *)(*(int *)((*(int **)(param_1 + 8))[1] + 0x2c) + 0x18) = 4;
  iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x18);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 4;
  }
  return 0;
}



// ============================================================
// Function: sprites_setCursorHand (FUN_6807b020)
// Address: 6807b020
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setCursorHand(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  *(undefined4 *)(*(int *)((*(int **)(param_1 + 8))[1] + 0x2c) + 0x18) = 3;
  iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x18);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 3;
  }
  return 0;
}



// ============================================================
// Function: sprites_setCursorCrosshair (FUN_6807b050)
// Address: 6807b050
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setCursorCrosshair(int param_1)
{
  *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x2c) + 0x18) = 2;
  return 0;
}



// ============================================================
// Function: sprites_beep (FUN_6807b070)
// Address: 6807b070
// Size: 8 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_beep(void)
{
  Ordinal_1015();
  return 0;
}



// ============================================================
// Function: sprites_delay (FUN_6807b080)
// Address: 6807b080
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_delay(undefined4 param_1,undefined4 param_2)
{
  Ordinal_1044(param_2);
  return 0;
}



// ============================================================
// Function: sprites_getSystemPath (FUN_6807b090)
// Address: 6807b090
// Size: 81 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getSystemPath(undefined4 param_1,undefined4 param_2,int param_3)
{
  undefined4 uVar1;
  undefined1 local_408 [1024];
  uint local_8;
  
  uVar1 = Ordinal_1017(local_408);
  Ordinal_1233(param_2,uVar1);
  if (param_3 != 0) {
    Ordinal_1233(param_3,local_408);
  }
  return 0;
}




// ============================================================
// Function: sprites_openUrl (FUN_6807b0f0)
// Address: 6807b0f0
// Size: 302 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_openUrl(int param_1,undefined1 *param_2)
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  undefined4 local_508;
  undefined2 local_504;
  undefined1 local_502;
  undefined1 local_501 [1017];
  byte local_108 [256];
  uint local_8;
  
  local_508 = 0x656e2004;
  local_504 = 0x74;
  local_502 = 0;
  memset(local_501,0,0x3f9);
  iVar4 = *(int *)(param_1 + 0x51c);
  iVar7 = 0;
  Ordinal_59(param_2 + 1);
  iVar3 = Ordinal_1201(param_2 + 1);
  param_2[iVar3 + 1] = 0;
  if (iVar3 < 0xff) {
    *param_2 = (char)iVar3;
  }
  else {
    *param_2 = 0xff;
  }
  if ((iVar4 != 0) && (piVar2 = *(int **)(iVar4 + 4), piVar2 != (int *)0x0)) {
    iVar7 = *piVar2;
  }
  iVar4 = media_applyPixelOp(iVar7,1,local_108,0x100);
  if (iVar4 == 0) {
    pbVar6 = local_108;
    pcVar5 = "Plugin";
    do {
      bVar1 = *pcVar5;
      bVar8 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_6807b1c8:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_6807b1cd;
      }
      if (bVar1 == 0) break;
      bVar1 = pcVar5[1];
      bVar8 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_6807b1c8;
      pcVar5 = pcVar5 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_6807b1cd:
    if (iVar4 == 0) {
      Ordinal_1231(param_2,&local_508);
      iVar4 = Ordinal_1201(param_2 + 1);
      param_2[iVar4 + 1] = 0;
      if (iVar4 < 0xff) {
        *param_2 = (char)iVar4;
        return 0;
      }
      *param_2 = 0xff;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_launchExternalApp (FUN_6807b220)
// Address: 6807b220
// Size: 538 bytes
// Params: int param_1, short param_2, int param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_launchExternalApp(int param_1,short param_2,int param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_44c;
  int local_448;
  int *local_444;
  undefined4 local_440;
  int *local_43c;
  int *local_438;
  undefined4 *local_434;
  uint local_430;
  undefined4 local_42c;
  int local_428 [2];
  int local_420;
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  byte local_408 [1024];
  uint local_8;
  
  local_438 = (int *)0x0;
  local_434 = (undefined4 *)0x0;
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  local_428[0] = 0;
  local_420 = 0;
  local_43c = (int *)0x0;
  if ((*(int *)(iVar1 + 0x658) != 0) && (DAT_68196364 == 0)) {
    DAT_68196364 = 1;
    if (((param_2 == 100) || (((param_2 == 0x62 || (param_2 == 99)) || (param_2 == 0x65)))) ||
       (param_2 == 0x71)) {
      cast_loadPascalString(local_408,2000,(int)param_2);
      local_438 = props_pascalToHandle(local_408);
      if (param_3 == 0) {
        local_420 = 8;
        local_41c = param_4;
      }
      else {
        iVar2 = Ordinal_1201(param_3,1);
        local_434 = (undefined4 *)Ordinal_1111(iVar2 + 1);
        if (local_434 == (undefined4 *)0x0) goto LAB_6807b3ef;
        local_440 = Ordinal_1114(local_434);
        uVar3 = Ordinal_1201(param_3);
        Ordinal_1128(local_440,param_3,uVar3);
        Ordinal_1115(local_434);
        props_getValuePair(param_1,local_434,&local_420);
        local_434 = (undefined4 *)0x0;
      }
      local_414 = param_5;
      local_418 = 8;
      local_430 = 3;
      local_42c = *(undefined4 *)(iVar1 + 0x658);
      props_getValuePair(param_1,local_438,local_428);
      local_438 = (int *)0x0;
      cast_executeHandler((int *)param_1,*(undefined4 **)(iVar1 + 0x658),0x317,4,&local_430,&local_448,
                   &local_44c);
      if (local_448 == 4) {
        local_43c = local_444;
      }
      else {
        props_releaseValue(param_1,(byte)local_448,local_444);
      }
      DAT_68196364 = 0;
    }
  }
LAB_6807b3ef:
  Ordinal_1113(&local_434);
  Ordinal_1113(&local_438);
  props_releaseAndClear(param_1,local_428);
  props_releaseAndClear(param_1,&local_420);
  return 0;
}



// ============================================================
// Function: sprites_getEnvironmentInfo (FUN_6807b440)
// Address: 6807b440
// Size: 247 bytes
// Params: void * this, int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_getEnvironmentInfo(void *this,int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  undefined1 local_208 [512];
  uint local_8;
  
  iVar1 = Ordinal_1201(param_3 + 1);
  iVar2 = Ordinal_1201(param_4 + 1);
  iVar4 = (int)this + 1;
  iVar3 = Ordinal_1201(iVar4);
  if ((uint)(iVar3 + 3 + iVar1 + iVar2) < 0x201) {
    Ordinal_1219(local_208,"%s\n%s\n%s",iVar4,param_3 + 1,param_4 + 1);
  }
  else {
    Ordinal_1517(DAT_681956e0,0x138f,local_208,0x200);
  }
  if (param_2 == 0) {
    sVar5 = 100;
  }
  else {
    sVar5 = 0x65;
  }
  iVar1 = sprites_launchExternalApp(param_1,sVar5,iVar4,0,0x7b);
  if (iVar1 == 0) {
    events_resetMiawState(param_1,local_208,(undefined1 *)0x0,2,(uint)(param_5 != 0),1,1,0);
  }
  return 0;
}



// ============================================================
// Function: sprites_getSystemInfo (FUN_6807b540)
// Address: 6807b540
// Size: 376 bytes
// Params: int param_1, int param_2, void * param_3, int param_4, int param_5, int param_6, int param_7, undefined4 param_8
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
sprites_getSystemInfo(int param_1,int param_2,void *param_3,int param_4,int param_5,int param_6,int param_7,
            undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  int iVar6;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  iVar2 = *(int *)(param_1 + 0xc);
  bVar5 = param_7 == 0x66;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
  }
  param_7 = *(int *)(iVar2 + 4);
  if (((*(int *)(*piVar1 + 0x658) == 0) && (DAT_6819630c != (code *)0x0)) && (bVar5 == 0)) {
    uVar3 = lingo_initLifecycle(piVar1[8]);
    iVar2 = param_2;
    iVar6 = param_5;
    uVar4 = events_getMoviePauseState(param_1);
    param_5 = ((code *)(size_t)DAT_6819630c)(uVar3,uVar4,iVar2,param_3,param_4,iVar6);
  }
  else {
    param_5 = sprites_getEnvironmentInfo(param_3,param_1,param_2,param_4,param_5,(uint)bVar5);
  }
  if (param_6 != 0) {
    uVar3 = lingo_initLifecycle(piVar1[8]);
    uVar4 = lingo_initLifecycle(*(int *)(param_7 + 0x20));
    switch(param_5) {
    case 0:
      if (DAT_68196310 != (code *)0x0) {
        ((code *)(size_t)DAT_68196310)(uVar3,param_2,0,param_8);
      }
      break;
    case 1:
      break;
    case 2:
      return 0;
    case 3:
      if ((DAT_68196314 != (code *)0x0) && (DAT_68196318 != (code *)0x0)) {
        ((code *)(size_t)DAT_68196314)(uVar3,uVar4,param_2,*(undefined4 *)(param_1 + 0x54),param_8,1);
        ((code *)(size_t)DAT_68196318)(uVar3,uVar4,param_2,0,param_8,&param_5);
        return 1;
      }
      break;
    case 4:
      sprites_setCursorCrosshair(param_1);
      return 1;
    case 5:
      sprites_setCursorHand(param_1);
    default:
      return 1;
    }
    return 1;
  }
  return 1;
}



// ============================================================
// Function: sprites_getPlatformInfo (FUN_6807b6d0)
// Address: 6807b6d0
// Size: 181 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getPlatformInfo(int param_1,int param_2)
{
  int iVar1;
  char *pcVar2;
  char local_408 [1024];
  uint local_8;
  
  if (DAT_68196368 == 0) {
    DAT_68196368 = 1;
    Ordinal_1203(local_408,param_2 + 1,0x400);
    iVar1 = sprites_launchExternalApp(param_1,0x65,(int)local_408,0,0x1db);
    if (iVar1 == 0) {
      pcVar2 = local_408;
      while (local_408[0] != '\0') {
        if (*pcVar2 == '\r') {
          *pcVar2 = '\n';
        }
        pcVar2 = pcVar2 + 1;
        local_408[0] = *pcVar2;
      }
      events_resetMiawState(param_1,local_408,&DAT_6817c624,2,1,1,1,1);
    }
    DAT_68196368 = 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_getMediaPlayerVersion (FUN_6807b790)
// Address: 6807b790
// Size: 8 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getMediaPlayerVersion(void)

{
  return DAT_6818e374;
}



// ============================================================
// Function: sprites_getQuickTimeVersion (FUN_6807b7a0)
// Address: 6807b7a0
// Size: 15 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getQuickTimeVersion(undefined4 param_1,undefined4 param_2)
{
  DAT_6818e374 = param_2;
  return 0;
}



// ============================================================
// Function: sprites_getColorDepth (FUN_6807b7b0)
// Address: 6807b7b0
// Size: 95 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 sprites_getColorDepth(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint local_8;
  
  local_8 = 0;
  uVar1 = Ordinal_1201(param_2 + 1,&local_8,4);
  iVar2 = Ordinal_1265(param_2 + 1,uVar1);
  if (iVar2 < 0) {
    return DAT_6818e378;
  }
  if ((ushort)local_8 < 0x100) {
    return (&DAT_6818e378)[local_8 & 0xffff];
  }
  return 0;
}



// ============================================================
// Function: sprites_getDisplayRect (FUN_6807b810)
// Address: 6807b810
// Size: 174 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getDisplayRect(int param_1,uint *param_2)
{
  int iVar1;
  int local_44 [2];
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_3c = Ordinal_2030();
  iVar1 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  props_getContextRef(param_1,(int *)param_2);
  if (0 < local_3c) {
    do {
      Ordinal_2031(iVar1,&local_28);
      local_30 = local_18;
      local_34 = local_24;
      local_38 = local_20;
      local_2c = local_1c;
      props_storeRectOp(param_1,&local_38,local_44);
      props_dispatchMethod(param_1,param_2,local_44);
      props_releaseAndClear(param_1,local_44);
      iVar1 = iVar1 + 1;
    } while (iVar1 < local_3c);
  }
  return 0;
}




// ============================================================
// Function: sprites_getDesktopRect (FUN_6807b8c0)
// Address: 6807b8c0
// Size: 414 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getDesktopRect(int param_1,int *param_2)
{
  int param_4;
  int local_14;
  int local_18;
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  short local_3c [8];
  uint local_2c;
  int local_28;
  undefined4 local_24;
  int *local_20 [6];
  uint local_8;
  
  local_24 = 0;
  iVar1 = (*(int **)(param_1 + 8))[1];
  local_28 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  if (iVar1 == 0) {
    return 0;
  }
  uVar3 = cast_getHandlerOffset(param_1,param_2);
  sVar5 = (short)((uint)uVar3 >> 0x10);
  sVar2 = (short)uVar3;
  local_24 = CONCAT22(sVar2,sVar5);
  local_2c = local_24;
  if (sVar2 == 0) {
    if (sVar5 != 0) {
LAB_6807b9e0:
      return 0;
    }
  }
  else {
    if (sVar2 < 1) goto LAB_6807b9e0;
    iVar4 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_24,0x25,(uint *)local_20
                       );
    if ((iVar4 != 0) && (local_20[0] == param_2)) {
      return 0;
    }
  }
  local_24 = local_24 & 0xffff0000;
  iVar4 = Ordinal_354(*(int *)(local_28 + 8),(short *)&local_24);
  do {
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = Ordinal_347(*(int *)(local_28 + 8),(short)local_24,3,(uint *)local_3c);
    if (iVar4 != 0) {
      local_24 = CONCAT22(1,(short)local_24);
      if (0 < local_3c[0]) {
        do {
          iVar4 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_24,0x25,
                              (uint *)local_20);
          if ((iVar4 != 0) && (local_20[0] == param_2)) {
            cast_setHandlerOffset(param_1,param_2,(int)(short)local_24 << 0x10 | (int)(*(unsigned short *)((char *)&local_24 + 2)));
            return 0;
          }
          (*(unsigned short *)((char *)&local_24 + 2)) = (*(unsigned short *)((char *)&local_24 + 2)) + 1;
        } while ((*(unsigned short *)((char *)&local_24 + 2)) <= local_3c[0]);
      }
    }
    iVar4 = Ordinal_354(*(int *)(local_28 + 8),(short *)&local_24);
  } while( true );
}



// ============================================================
// Function: sprites_getFreeMemory (FUN_6807ba60)
// Address: 6807ba60
// Size: 198 bytes
// Params: uint * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getFreeMemory(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  int unaff_ESI;
  uint local_14 [2];
  int local_c [2];
  
  props_getContextRef(unaff_ESI,(int *)local_14);
  props_storeIntValue(unaff_ESI,param_2,local_c);
  props_dispatchMethod(unaff_ESI,local_14,local_c);
  props_releaseAndClear(unaff_ESI,local_c);
  props_storeIntValue(unaff_ESI,param_3,local_c);
  props_dispatchMethod(unaff_ESI,local_14,local_c);
  props_releaseAndClear(unaff_ESI,local_c);
  props_storeIntValue(unaff_ESI,param_4,local_c);
  props_dispatchMethod(unaff_ESI,local_14,local_c);
  props_releaseAndClear(unaff_ESI,local_c);
  props_storeIntValue(unaff_ESI,param_5,local_c);
  props_dispatchMethod(unaff_ESI,local_14,local_c);
  props_releaseAndClear(unaff_ESI,local_c);
  props_dispatchMethod(unaff_ESI,param_1,local_14);
  props_releaseAndClear(unaff_ESI,(int *)local_14);
  return 0;
}



// ============================================================
// Function: sprites_getLastError (FUN_6807bb30)
// Address: 6807bb30
// Size: 105 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getLastError(int param_1,uint *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  props_getContextRef(param_1,(int *)param_2);
  if ((DAT_6819633c != (code *)0x0) && (DAT_68196340 != (code *)0x0)) {
    iVar1 = ((code *)(size_t)DAT_6819633c)();
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        ((code *)(size_t)DAT_68196340)(iVar2,&local_c,&local_8,&param_1);
        sprites_getFreeMemory(param_2,local_c,local_c,local_8,param_1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setLastError (FUN_6807bba0)
// Address: 6807bba0
// Size: 268 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setLastError(int param_1,uint *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20 [7];
  
  iVar1 = param_1;
  iVar2 = props_resolveRef(param_1,param_2);
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[6] = 0;
  param_1 = 0;
  if ((DAT_68196334 != (code *)0x0) && (DAT_68196338 != (code *)0x0)) {
    ((code *)(size_t)DAT_68196334)();
    iVar3 = 1;
    if (0 < iVar2) {
      do {
        props_callMethodDirect(iVar1,param_2,iVar3,(int *)local_20);
        props_callMethodDirect(iVar1,local_20,1,(int *)(local_20 + 2));
        props_coerceAndReturnInt(iVar1,local_20 + 2,(int *)(local_20 + 4));
        props_callMethodDirect(iVar1,local_20,2,(int *)(local_20 + 2));
        props_coerceAndReturnInt(iVar1,local_20 + 2,(int *)(local_20 + 5));
        props_callMethodDirect(iVar1,local_20,3,(int *)(local_20 + 2));
        props_coerceAndReturnInt(iVar1,local_20 + 2,(int *)(local_20 + 6));
        props_callMethodDirect(iVar1,local_20,4,(int *)(local_20 + 2));
        props_coerceAndReturnInt(iVar1,local_20 + 2,&param_1);
        ((code *)(size_t)DAT_68196338)(local_20[4],local_20[5],local_20[6],param_1);
        iVar3 = iVar3 + 1;
      } while (iVar3 <= iVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getNetworkError (FUN_6807bcb0)
// Address: 6807bcb0
// Size: 124 bytes
// Params: uint * param_1, short param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetworkError(uint *param_1,short param_2,short param_3)
{
  int unaff_ESI;
  uint local_14 [2];
  int local_c [2];
  
  props_getContextRef(unaff_ESI,(int *)local_14);
  props_storeIntValue(unaff_ESI,(int)param_2,local_c);
  props_dispatchMethod(unaff_ESI,local_14,local_c);
  props_releaseAndClear(unaff_ESI,local_c);
  props_storeIntValue(unaff_ESI,(int)param_3,local_c);
  props_dispatchMethod(unaff_ESI,local_14,local_c);
  props_releaseAndClear(unaff_ESI,local_c);
  props_dispatchMethod(unaff_ESI,param_1,local_14);
  props_releaseAndClear(unaff_ESI,(int *)local_14);
  return 0;
}



// ============================================================
// Function: sprites_getNetworkErrorString (FUN_6807bd30)
// Address: 6807bd30
// Size: 102 bytes
// Params: int param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetworkErrorString(int param_1,undefined4 param_2,uint *param_3)
{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  props_getContextRef(param_1,(int *)param_3);
  if ((DAT_6819634c != (code *)0x0) && (DAT_68196350 != (code *)0x0)) {
    iVar1 = ((code *)(size_t)DAT_6819634c)(param_2);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        ((code *)(size_t)DAT_68196350)(param_2,iVar2,&local_8,&param_1);
        sprites_getNetworkError(param_3,(short)local_8,(short)param_1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setAlertHook (FUN_6807bda0)
// Address: 6807bda0
// Size: 187 bytes
// Params: int param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setAlertHook(int param_1,undefined4 param_2,uint *param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_18 [5];
  
  iVar1 = param_1;
  iVar2 = props_resolveRef(param_1,param_3);
  local_18[4] = 0;
  param_1 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  if ((DAT_68196344 != (code *)0x0) && (DAT_68196348 != (code *)0x0)) {
    ((code *)(size_t)DAT_68196344)(param_2);
    iVar3 = 1;
    if (0 < iVar2) {
      do {
        props_callMethodDirect(iVar1,param_3,iVar3,(int *)local_18);
        props_callMethodDirect(iVar1,local_18,1,(int *)(local_18 + 2));
        props_coerceAndReturnInt(iVar1,local_18 + 2,(int *)(local_18 + 4));
        props_callMethodDirect(iVar1,local_18,2,(int *)(local_18 + 2));
        props_coerceAndReturnInt(iVar1,local_18 + 2,&param_1);
        ((code *)(size_t)DAT_68196348)(param_2,local_18[4],param_1);
        iVar3 = iVar3 + 1;
      } while (iVar3 <= iVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_showAlert (FUN_6807be60)
// Address: 6807be60
// Size: 1372 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_showAlert(int param_1,uint *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_1d4;
  undefined4 local_1d0;
  int local_1cc;
  int local_1c8;
  uint local_1c4;
  int local_1c0;
  int local_1bc;
  int local_1b8;
  int local_1b4;
  uint local_1b0;
  int local_1ac;
  uint local_1a8;
  int *local_1a4;
  uint local_1a0;
  int local_19c;
  byte local_198 [400];
  uint local_8;
  
  local_1a4 = (int *)0x0;
  local_1b4 = crt_getPlatformId();
  iVar1 = *(int *)(param_1 + 0xe0);
  local_1bc = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = props_lookupSymbol(param_1,"packageFiles",0xc);
  iVar3 = props_lookupSymbol(param_1,"packageUrl",10);
  props_getContextRef(param_1,(int *)param_2);
  iVar5 = local_1bc;
  if (((*param_2 != 2) &&
      (iVar4 = media_allocCastNodeLocked(*(int *)(local_1bc + 0x20),*(int *)(local_1bc + 0x28),(int *)&local_1a4,
                            (int)&local_1c4), iVar4 == 0)) && (local_1a8 = 0, local_1c4 != 0)) {
    do {
      iVar4 = score_dispatchProplist(param_1);
      iVar5 = local_1bc;
      local_1c0 = iVar4;
      if (iVar4 == 0) break;
      iVar5 = media_loadXtraBlock(local_1a4,local_1a8,0,0x20,0,local_198,(int *)0x0);
      if ((iVar5 == 0) && (local_198[0] == 0)) {
        iVar5 = media_loadXtraBlock(local_1a4,local_1a8,0,6,local_1b4,local_198,(int *)0x0);
        if (iVar5 == 0) {
          local_1b0 = 8;
          local_1ac = (-(uint)(iVar1 != 0) & 0xfffffff9) + 0x103;
          props_loadStringValue(param_1,(char *)(local_198 + 1),&local_1a0);
          score_setPropertyValue(param_1,iVar4,&local_1b0,&local_1a0,1);
          props_releaseAndClear(param_1,(int *)&local_1a0);
        }
        iVar5 = media_loadXtraBlock(local_1a4,local_1a8,0,2,0,local_198,(int *)0x0);
        if (((iVar5 == 0) && (local_198[0] != 0)) &&
           (iVar5 = media_loadXtraBlock(local_1a4,local_1a8,0,0xb,local_1b4,local_198,(int *)0x0),
           iVar5 == 0)) {
          local_1c8 = (int)(char)local_198[0];
          if (local_1c8 != 0) {
            iVar5 = media_loadXtraBlock(local_1a4,local_1a8,0,1,0,local_198,(int *)0x0);
            if (iVar5 == 0) {
              local_1b0 = 8;
              local_1ac = iVar3;
              props_loadStringValue(param_1,(char *)(local_198 + 1),&local_1a0);
              score_setPropertyValue(param_1,iVar4,&local_1b0,&local_1a0,1);
              props_releaseAndClear(param_1,(int *)&local_1a0);
            }
            if (local_1b4 == 2) {
              local_1b8 = 0x21;
              uVar6 = 0x22;
            }
            else {
              if (local_1b4 != 5) goto LAB_6807c33f;
              local_1b8 = 0x41;
              uVar6 = 0x42;
            }
            props_getContextRef(param_1,(int *)&local_1d4);
            iVar4 = local_1c0;
            if (local_1d4 != 2) {
              local_1cc = 0;
              if (0 < local_1c8) {
                local_1b8 = local_1b8 - uVar6;
                do {
                  iVar5 = score_dispatchProplist(param_1);
                  if (iVar5 != 0) {
                    iVar4 = media_loadXtraBlock(local_1a4,local_1a8,0,local_1b8 + uVar6,local_1b4,local_198
                                         ,(int *)0x0);
                    if (iVar4 == 0) {
                      local_1b0 = 8;
                      local_1ac = 0xfc;
                      props_loadStringValue(param_1,(char *)(local_198 + 1),&local_1a0);
                      if (local_1a0 != 2) {
                        score_setPropertyValue(param_1,iVar5,&local_1b0,&local_1a0,1);
                        props_releaseAndClear(param_1,(int *)&local_1a0);
                        iVar4 = media_loadXtraBlock(local_1a4,local_1a8,0,uVar6,local_1b4,local_198,
                                             (int *)0x0);
                        if (iVar4 != 0) {
                          local_198[0] = 0;
                          local_198[1] = 0;
                        }
                        local_1b0 = 8;
                        local_1ac = 300;
                        media_skipScoreVersion((char *)(local_198 + 1));
                        props_loadStringValue(param_1,(char *)(local_198 + 1),&local_1a0);
                        if ((local_1a0 == 0x40) || (local_1a0 == 0x43)) {
                          score_setPropertyValue(param_1,iVar5,&local_1b0,&local_1a0,1);
                        }
                        props_releaseAndClear(param_1,(int *)&local_1a0);
                      }
                    }
                    local_1a0 = 3;
                    local_19c = iVar5;
                    iVar5 = props_dispatchMethod(param_1,&local_1d4,&local_1a0);
                    if (iVar5 != 0) break;
                    props_releaseAndClear(param_1,(int *)&local_1a0);
                  }
                  local_1cc = local_1cc + 1;
                  uVar6 = uVar6 + 2;
                } while (local_1cc < local_1c8);
              }
              local_1a0 = local_1d4;
              local_19c = local_1d0;
              local_1b0 = 8;
              local_1ac = iVar2;
              score_setPropertyValue(param_1,local_1c0,&local_1b0,&local_1a0,1);
              props_releaseAndClear(param_1,(int *)&local_1a0);
              iVar4 = local_1c0;
            }
          }
        }
LAB_6807c33f:
        local_1a0 = 3;
        local_19c = iVar4;
        props_dispatchMethod(param_1,param_2,&local_1a0);
        props_releaseAndClear(param_1,(int *)&local_1a0);
      }
      local_1a8 = local_1a8 + 1;
      iVar5 = local_1bc;
    } while (local_1a8 < local_1c4);
  }
  if (local_1a4 != (int *)0x0) {
    media_assignCastDataLocked(*(int *)(iVar5 + 0x20),*(undefined4 ****)(iVar5 + 0x28),(int)local_1a4,0);
  }
  return 0;
}




// ============================================================
// Function: sprites_openFileDialog (FUN_6807c3c0)
// Address: 6807c3c0
// Size: 586 bytes
// Params: int param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_openFileDialog(int param_1,undefined4 param_2,uint *param_3)
{
  int param_4;
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_844;
  int local_840;
  int local_83c;
  uint local_838;
  uint local_834;
  int local_830;
  int local_82c;
  int local_828;
  undefined1 local_824 [1048];
  int local_40c;
  char local_408 [1024];
  uint local_8;
  
  local_83c = 0;
  if (*(int *)(param_1 + 0xe0) == 0) {
    local_844 = 0x103;
    local_840 = 0;
  }
  else {
    local_844 = 0xfc;
    local_840 = 0x103;
  }
  props_getContextRef(param_1,(int *)param_3);
  local_83c = media_processResourceDispatch(param_1,param_2);
  if (local_83c != 0) {
    uVar1 = Ordinal_1154(local_83c);
    local_838 = 0;
    if (uVar1 != 0) {
      do {
        iVar2 = score_dispatchProplist(param_1);
        if (iVar2 == 0) break;
        iVar3 = Ordinal_1155(local_83c,local_838,local_824);
        if ((iVar3 != 0) && (iVar3 = Ordinal_1314(local_824,local_408,0x400), iVar3 != 0)) {
          local_834 = 8;
          local_830 = local_844;
          props_loadStringValue(param_1,local_408,&local_82c);
          score_setPropertyValue(param_1,iVar2,&local_834,&local_82c,1);
          props_releaseAndClear(param_1,&local_82c);
          if ((0 < local_40c) && (local_840 != 0)) {
            local_828 = local_40c;
            local_834 = 8;
            local_830 = local_840;
            local_82c = 8;
            score_setPropertyValue(param_1,iVar2,&local_834,&local_82c,1);
          }
          crt_getFileVersion(local_824,local_408,0x400);
          media_skipScoreVersion(local_408);
          local_834 = 8;
          local_830 = 300;
          props_loadStringValue(param_1,local_408,&local_82c);
          score_setPropertyValue(param_1,iVar2,&local_834,&local_82c,1);
          props_releaseAndClear(param_1,&local_82c);
          local_82c = 3;
          local_828 = iVar2;
          props_dispatchMethod(param_1,param_3,&local_82c);
          props_releaseAndClear(param_1,&local_82c);
        }
        local_838 = local_838 + 1;
      } while (local_838 < uVar1);
    }
  }
  Ordinal_1163(&local_83c);
  return 0;
}



// ============================================================
// Function: sprites_getStageHandle (FUN_6807c610)
// Address: 6807c610
// Size: 28 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getStageHandle(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = scoreEngine_checkMediaFile(param_2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: sprites_getWindowHandle (FUN_6807c630)
// Address: 6807c630
// Size: 98 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getWindowHandle(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  if (param_2 != 0) {
    if (*(int *)(*(int *)(iVar1 + 8) + 0x20) == 0) {
      Ordinal_108(*(int *)((*(int **)(param_1 + 8))[1] + 0x20),0x22,(undefined4 *)0x0);
    }
    *(undefined4 *)(*(int *)(iVar1 + 8) + 0x20) = 1;
    Ordinal_1305(2);
    Ordinal_1302(sprites_getStageHandle);
    return *(undefined4 *)(*(int *)(iVar1 + 8) + 0x20);
  }
  return *(undefined4 *)(*(int *)(iVar1 + 8) + 0x20);
}



// ============================================================
// Function: sprites_getStageRef (FUN_6807c6a0)
// Address: 6807c6a0
// Size: 27 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getStageRef(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 8) + 0x20);
}



// ============================================================
// Function: sprites_getChannelRefById (FUN_6807c6c0)
// Address: 6807c6c0
// Size: 41 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getChannelRefById(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(code **)(**(int **)(**(int **)(*(int *)(param_1 + 8) + 4) + 4) + 0x1ac);
  uVar2 = 0;
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)(param_2);
  }
  return uVar2;
}



// ============================================================
// Function: sprites_getChannelRef (FUN_6807c6f0)
// Address: 6807c6f0
// Size: 116 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getChannelRef(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x764) == 0) {
    return *(int *)(iVar1 + 0x76c) + *(int *)(iVar1 + 0x770);
  }
  if (*(int *)(iVar1 + 0x768) != 1) {
    if (*(int *)(iVar1 + 0x768) == 2) {
      iVar2 = Ordinal_1546();
      return *(int *)(iVar1 + 0x76c) + (iVar2 * 2 - *(int *)(iVar1 + 0x770));
    }
    return *(int *)(iVar1 + 0x76c) + param_1;
  }
  iVar2 = Ordinal_1546();
  return *(int *)(iVar1 + 0x76c) + iVar2;
}



// ============================================================
// Function: sprites_getMovieRef (FUN_6807c770)
// Address: 6807c770
// Size: 116 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getMovieRef(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x764) == 0) {
    return *(int *)(iVar1 + 0x774) + *(int *)(iVar1 + 0x778);
  }
  if (*(int *)(iVar1 + 0x768) != 1) {
    if (*(int *)(iVar1 + 0x768) == 2) {
      iVar2 = Ordinal_1541();
      return *(int *)(iVar1 + 0x774) + (iVar2 * 2 - *(int *)(iVar1 + 0x778));
    }
    return *(int *)(iVar1 + 0x774) + param_1;
  }
  iVar2 = Ordinal_1541();
  return *(int *)(iVar1 + 0x774) + iVar2;
}



// ============================================================
// Function: sprites_getMovieRefByPath (FUN_6807c7f0)
// Address: 6807c7f0
// Size: 109 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMovieRefByPath(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  
  if (DAT_68196318 != (code *)0x0) {
    local_8 = 0xffffffff;
    if (*(int *)(param_1 + 0xc) == 0) {
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 4);
    }
    uVar1 = lingo_initLifecycle(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20));
    uVar2 = lingo_initLifecycle(*(int *)(iVar3 + 0x20));
    ((code *)(size_t)DAT_68196318)(uVar1,uVar2,param_2,param_3,param_4,&local_8);
    *param_5 = local_8;
  }
  return 0;
}



// ============================================================
// Function: sprites_getCastRef (FUN_6807c860)
// Address: 6807c860
// Size: 95 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getCastRef(int param_1,undefined1 *param_2)
{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = sprites_getStageRef(param_1);
  if (iVar3 != 0) {
    puVar1 = param_2 + 1;
    scoreEngine_writePropertyEx(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),puVar1,0x3ff);
    iVar3 = Ordinal_1201(puVar1);
    param_2[iVar3 + 1] = 0;
    iVar3 = Ordinal_1201(puVar1);
    if (iVar3 < 0xff) {
      uVar2 = Ordinal_1201(puVar1);
      *param_2 = uVar2;
      return 0;
    }
    *param_2 = 0xff;
  }
  return 0;
}



// ============================================================
// Function: sprites_getCastRefByName (FUN_6807c8c0)
// Address: 6807c8c0
// Size: 146 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getCastRefByName(int param_1,int *param_2)
{
  int iVar1;
  byte local_408 [1024];
  uint local_8;
  
  if (*param_2 == 0x40) {
    iVar1 = (uint)(*(char *)((int)param_2 + 6) != '\0') +
            (uint)(*(char *)((int)param_2 + 5) != '\0') + (uint)((char)param_2[1] != '\0');
  }
  else {
    iVar1 = Ordinal_1116(param_2[1]);
    iVar1 = iVar1 + -9;
  }
  if (iVar1 < 0x3ff) {
    props_toPascalString(param_2,local_408);
    props_releaseAndClear(param_1,param_2);
    sprites_getCastRef(param_1,local_408);
    props_readPascalString(param_1,local_408,param_2);
  }
  return 0;
}



// ============================================================
// Function: sprites_allocMemory (FUN_6807c960)
// Address: 6807c960
// Size: 24 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_allocMemory(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = events_getScoreProperty2(param_1);
  *(undefined4 *)(param_1 + 0xf4) = uVar1;
  return 0;
}



// ============================================================
// Function: sprites_freeMemory (FUN_6807c980)
// Address: 6807c980
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_freeMemory(int param_1)
{
  if (*(int *)(param_1 + 0x7c) == 0) {
    crt_dispatchPendingGoTo(param_1);
  }
  return 0;
}



// ============================================================
// Function: sprites_lockMemory (FUN_6807c9a0)
// Address: 6807c9a0
// Size: 16 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_lockMemory(void)
{
  lingo_getGlobalCount();
  return 0;
}



// ============================================================
// Function: sprites_unlockMemory (FUN_6807c9b0)
// Address: 6807c9b0
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_unlockMemory(undefined4 param_1,undefined4 param_2)
{
  lingo_getGlobalValue(param_2);
  return 0;
}



// ============================================================
// Function: sprites_getMemorySize (FUN_6807c9c0)
// Address: 6807c9c0
// Size: 8 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemorySize(void)
{
  Ordinal_1038();
  return 0;
}



// ============================================================
// Function: sprites_resizeMemory (FUN_6807c9d0)
// Address: 6807c9d0
// Size: 60 bytes
// Params: int param_1, int * param_2, undefined1 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_resizeMemory(int param_1,int *param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_5;
  
  iVar2 = 0;
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 != 0) {
    iVar2 = media_applyPixelFilterEx(param_2,&local_5);
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 1;
  }
  return iVar2;
}




// ============================================================
// Function: sprites_sendMessage (FUN_6807ca10)
// Address: 6807ca10
// Size: 166 bytes
// Params: int param_1, undefined * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_sendMessage(int param_1,undefined *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0x28), iVar1 == 0)) {
    Ordinal_2330();
    local_14 = param_1;
    local_c = 3;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    (*(code *)param_2)(param_3);
  }
  else {
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
    (*(code *)param_2)(param_3);
  }
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: sprites_sendNetMessage (FUN_6807cac0)
// Address: 6807cac0
// Size: 115 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_sendNetMessage(int param_1,int *param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x28);
  Ordinal_2330();
  local_c = 0;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  local_14 = uVar1;
  (**(code **)(*param_2 + 0xc))(param_2,param_3);
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: sprites_readNetData (FUN_6807cb40)
// Address: 6807cb40
// Size: 264 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_readNetData(int param_1,int *param_2)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *local_20;
  undefined4 local_1c;
  char local_15;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = (int *)0x0;
  local_1c = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_1038();
  piVar3 = (int *)Ordinal_2068(uVar2);
  if (piVar3 != (int *)0x0) {
    iVar1 = *(int *)(iVar1 + 0x28);
    iVar4 = sprites_getStageRef(param_1);
    if (iVar4 != 0) {
      iVar4 = media_applyPixelFilterEx(param_2,&local_15);
      if ((iVar4 != 0) || (local_15 == '\0')) goto LAB_6807cc2e;
    }
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar1 + 0x20);
      if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) {
        Ordinal_2330();
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
        local_14 = iVar1;
      }
    }
    (**(code **)(*piVar3 + 0x24))(piVar3,param_2,0,&local_20);
    if (local_20 != (int *)0x0) {
      (**(code **)*local_20)(local_20,&DAT_68176138,&local_1c);
      (**(code **)(*local_20 + 8))(local_20);
    }
    (**(code **)(*piVar3 + 8))(piVar3);
    if (iVar4 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
LAB_6807cc2e:
  return 0;
}



// ============================================================
// Function: sprites_getNetStatus (FUN_6807cc50)
// Address: 6807cc50
// Size: 120 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetStatus(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x28);
    if (iVar1 != 0) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  (**(code **)(*param_2 + 8))(param_2);
  if (iVar1 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: sprites_cancelNetOp (FUN_6807ccd0)
// Address: 6807ccd0
// Size: 186 bytes
// Params: int * param_1, byte * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool sprites_cancelNetOp(int *param_1,byte *param_2)

{
  int iVar1;
  byte *pbVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  
  iVar5 = *param_1;
  iVar1 = *(int *)(**(int **)(iVar5 + 8) + 0x51c);
  pbVar2 = (byte *)param_1[1];
  if (param_2 != (byte *)0x0) {
    if (*param_2 == 0xff) {
      uVar3 = Ordinal_1201(param_2 + 1);
    }
    else {
      uVar3 = (ushort)*param_2;
    }
    if (*pbVar2 == 0xff) {
      uVar4 = Ordinal_1201(pbVar2 + 1);
    }
    else {
      uVar4 = (ushort)*pbVar2;
    }
    if ((int)(short)uVar4 + (int)(short)uVar3 < 0x1000) {
      Ordinal_1237(pbVar2,param_2,0x1000);
    }
    else {
      events_closeMiawMovie(*(int **)(*(int *)(*(int *)(iVar1 + 8) + 0xc) + 0x14),(int)pbVar2);
      events_closeMiawMovie(*(int **)(*(int *)(*(int *)(iVar1 + 8) + 0xc) + 0x14),(int)param_2);
      *(undefined1 *)(param_1[1] + 1) = 0;
      *(undefined1 *)param_1[1] = 0;
    }
  }
  iVar5 = cast_getRuntimeRef(iVar5);
  return (bool)('\x01' - (iVar5 != 0));
}



// ============================================================
// Function: sprites_getNetProgress (FUN_6807cd90)
// Address: 6807cd90
// Size: 57 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool sprites_getNetProgress(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    events_closeMiawMovie(*(int **)(*(int *)(*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 8) + 0xc) +
                          0x14),param_2);
  }
  iVar1 = cast_getRuntimeRef(param_1);
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: sprites_getNetResult (FUN_6807cdd0)
// Address: 6807cdd0
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetResult(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)
{
  *param_2 = sprites_cancelNetOp;
  *param_4 = param_1;
  param_4[1] = param_3;
  return 0;
}



// ============================================================
// Function: sprites_getNetResultString (FUN_6807cdf0)
// Address: 6807cdf0
// Size: 24 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetResultString(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = sprites_getNetProgress;
  *param_3 = param_1;
  return 0;
}



// ============================================================
// Function: sprites_getNetErrorCode (FUN_6807ce10)
// Address: 6807ce10
// Size: 36 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetErrorCode(int param_1,undefined4 param_2)
{
  sprites_setPropertyDirect(param_1,CONCAT22((short)param_2,(short)((uint)param_2 >> 0x10)));
  return 0;
}



// ============================================================
// Function: sprites_getNetDoneFlag (FUN_6807ce40)
// Address: 6807ce40
// Size: 46 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getNetDoneFlag(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_1510(DAT_681956e0,0,0x582);
  *param_2 = iVar1;
  if (iVar1 != 0) {
    uVar2 = Ordinal_1512(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: sprites_getNetState (FUN_6807ce70)
// Address: 6807ce70
// Size: 26 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetState(undefined4 param_1,undefined4 *param_2)
{
  Ordinal_1513(*param_2);
  Ordinal_1514(param_2);
  return 0;
}



// ============================================================
// Function: sprites_getNetUrl (FUN_6807ce90)
// Address: 6807ce90
// Size: 20 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetUrl(undefined4 param_1,int param_2,int param_3)
{
  crt_mergeChunks(param_2,param_3);
  return 0;
}



// ============================================================
// Function: sprites_getNetLocalPath (FUN_6807ceb0)
// Address: 6807ceb0
// Size: 75 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNetLocalPath(int param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int **)(iVar1 + 0x71c) != (int *)0x0) {
    crt_getScriptPropertyEx(param_1,*(int **)(iVar1 + 0x71c));
    cast_releaseObject(param_1,*(int **)(iVar1 + 0x71c));
  }
  crt_getScriptProperty(param_1,param_2);
  *(int **)(iVar1 + 0x71c) = param_2;
  cast_retainObject(param_1,param_2);
  return 0;
}



// ============================================================
// Function: sprites_getNetMimeType (FUN_6807cf00)
// Address: 6807cf00
// Size: 54 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getNetMimeType(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x71c) == 0) {
    piVar2 = (int *)cast_getContextRef(param_1);
    *(int **)(iVar1 + 0x71c) = piVar2;
    crt_getScriptProperty(param_1,piVar2);
  }
  return *(undefined4 *)(iVar1 + 0x71c);
}



// ============================================================
// Function: sprites_downloadNetFile (FUN_6807cf40)
// Address: 6807cf40
// Size: 146 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_downloadNetFile(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = sprites_getStageRef(param_1);
  if (iVar2 != 0) {
    if (*(int *)(DAT_681962f8 + 0x24) != 0) {
      return (uint)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x2c) + 8) + 0xc) + 0xc) == 0);
    }
    if (*(int *)(DAT_681962f8 + 0xe0) == 0) {
      iVar2 = Ordinal_54(*(int *)(iVar1 + 0x20),&param_1);
      if (iVar2 != 0) {
        if (*(code **)(DAT_681962f8 + 0x1b0) != (code *)0x0) {
          uVar3 = (**(code **)(DAT_681962f8 + 0x1b0))
                            (*(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x2c) + 8) + 0x24));
          return uVar3;
        }
        uVar3 = Ordinal_1808(param_1);
        return uVar3;
      }
    }
  }
  return 1;
}



