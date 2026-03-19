// Module: events
// Topic: Movie-in-a-window (MIAW) lifecycle, projector management, window creation/destruction
// Address range: 0x68066cb0 - 0x6806a690
// Functions (54):
//   events_handleScrollEvent
//   events_processTimerTick
//   events_executeFrameLoop
//   events_createMovieContext
//   events_destroyMovieInstance
//   events_loadLingoIni
//   events_allocateSessionBlock
//   events_cleanupMovieInstance
//   events_initWindowContext
//   events_handleWindowResize
//   events_updateWindowState
//   events_notifyWindowClose
//   events_processMovieEvent
//   events_requestMovieAction
//   events_postMovieNotify
//   events_handleMovieCallback
//   events_createEventContext
//   events_getLifecycleState
//   events_addRefEvent
//   events_processEvent
//   events_releaseLifecycle
//   events_createLifecycle
//   events_resetLifecycleState
//   events_retainEvent
//   events_releaseEvent
//   events_releaseMovieRef
//   events_dispatchMovieEvent
//   events_getLifecycleRef
//   events_getMovieWindowRef
//   events_initPlaybackSession
//   events_startPlaybackLoop
//   events_runMoviePlayback
//   events_getEventState
//   events_checkWindowActive
//   events_activateWindow
//   events_shutdownPlayback
//   events_finalizeSession
//   events_releaseSessionData
//   events_requestWindowClose
//   events_checkStageActive
//   events_getStageActiveState
//   events_dispatchGlobalEvent
//   sprites_getNextUpdateTime
//   events_handleMovieOpen
//   events_handleMovieClose
//   events_handleProjectorStart
//   events_handleProjectorExit
//   events_dispatchHandler
//   events_getEventParam
//   events_notifyScoreChange
//   events_initScoreCallbacks
//   events_registerScoreHandler
//   events_unregisterScoreHandler
//   events_broadcastScoreEvent
//   events_processScoreNotify
//   events_getProjectorRef
//   events_setProjectorRef
//   events_getProjectorMode
//   events_handleWindowMessage
//   events_getWindowMessageData
//   events_setWindowMessageData
//   events_getWindowVisible
//   events_setWindowVisible
//   events_getWindowTitle
//   events_setWindowTitle
//   events_checkPermission
//   events_getWindowBounds
//   events_setWindowBounds
//   events_resolveWindowPath
//   events_getWindowAspect
//   events_setWindowAspect
//   events_getWindowStyle
//   events_setWindowStyle
//   events_getWindowFlags
//   events_setWindowFlags
//   events_resolveWindowRef
//   events_configureWindow
//   events_findSpriteAtPoint
//   sprites_hitTest
//   events_findTopSpriteAtPoint
//   events_processHitTestResult
//   events_invokeCallback

// ============================================================
// Function: events_handleScrollEvent (events_handleScrollEvent)
// Address: 68066cb0
// Size: 230 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_handleScrollEvent(int param_1,int param_2)

{
  int local_14;
  char *pcVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  int local_8;
  
  piVar3 = *(int **)(param_2 + 0x20);
  local_8 = 0;
  if ((*(int *)(param_1 + 0x78) != 0) &&
     (local_8 = events_dispatchEventEx(*(int *)(param_1 + 0x7c),param_1,0x1e,0,1,0), local_8 == 0)) {
    local_8 = sprites_processScrollInput(param_1,param_2);
  }
  if (*piVar3 == 1) {
    if (piVar3[8] == 0) {
      if (DAT_681962d8 != 0) {
        events_captureKeyPress();
        events_enableKeyCapture();
        return local_8;
      }
    }
    else if (DAT_681962d8 != 0) {
      events_captureKeyPress();
      pcVar4 = (char *)piVar3[8];
      cVar2 = *pcVar4;
      while (cVar2 != '\0') {
        events_captureKeyPress();
        pcVar1 = pcVar4 + 1;
        pcVar4 = pcVar4 + 1;
        cVar2 = *pcVar1;
      }
      DAT_681962d8 = 0;
    }
    if ((piVar3[9] != 0) && (DAT_681962d8 == 0)) {
      DAT_681962d8 = 1;
      events_enableKeyCapture();
      return local_8;
    }
    DAT_681962d8 = 0;
  }
  return local_8;
}



// ============================================================
// Function: events_processTimerTick (events_processTimerTick)
// Address: 68066da0
// Size: 334 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_processTimerTick(int *param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_34;
  int local_30 [2];
  undefined4 local_28 [8];
  uint local_8;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x68) == 0) {
    *(undefined4 *)(iVar1 + 0x68) = 1;
    uVar2 = Ordinal_1541();
    if ((int *)param_1[0x1c7] != (int *)0x0) {
      cast_fireTimerEvents(param_1[3],(int *)param_1[0x1c7]);
    }
    scoreEngine_writePropertyBlock(param_1[8],param_1[9],0,0);
    if ((param_1[0x14] < 1) || ((uint)param_1[0x15] <= uVar2)) {
      param_1[0x15] = param_1[0x14] * 0x10 + uVar2;
      events_dispatchEvent((int)param_1,0xb,0);
      local_34 = 0;
      Ordinal_54(param_1[8],&local_34);
      iVar3 = Ordinal_1878(local_34);
      if (iVar3 == 0) {
        iVar3 = Ordinal_1819(local_34);
        if (iVar3 != 0) {
          events_processScrollInput();
        }
      }
      Ordinal_1474(param_1[10]);
      Ordinal_108(param_1[8],0x15,(undefined4 *)0x0);
    }
    if ((param_1[0x1d4] == 2) && (param_1[0x5c] != 0)) {
      iVar3 = cast_waitForSync();
      if (iVar3 == 0) {
        *(undefined4 *)(**(int **)(*param_1 + 4) + 0x1c4) = 1;
        if (*(int *)(param_1[0xb] + 0x24) == 0) {
          Ordinal_1130(local_30,0x28);
          lingo_loadMovieData(param_1[8],local_28);
          local_30[0] = 9;
          events_executeMovieCommand(param_1,local_30,(int)param_1);
        }
        events_commitMouseState((undefined4 *)0x0);
        *(undefined4 *)(**(int **)(*param_1 + 4) + 0x1c4) = 0;
      }
    }
    *(undefined4 *)(iVar1 + 0x68) = 0;
  }
  return 0;
}



// ============================================================
// Function: events_executeFrameLoop (events_executeFrameLoop)
// Address: 68066ef0
// Size: 598 bytes
// Params: int * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_executeFrameLoop(int *param_1,uint *param_2)
{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c [5];
  uint local_8;
  
  puVar1 = (undefined4 *)*param_1;
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  if (DAT_681962e0 == 0) {
    events_handleFrameIdle();
  }
  DAT_681962e0 = DAT_681962e0 + 1 & 0xf;
  param_1[0x1cb] = -1;
  if ((param_1[0x13] == 0) || (iVar3 = sprites_getChannelRef(param_1[3]), param_1[0x13] <= iVar3)) {
    param_1[0x12] = 0;
    sVar2 = Ordinal_58(param_1[8],(byte *)param_1[10]);
    if (param_1[0x18] != (int)sVar2) {
      iVar3 = Ordinal_145(param_1[8],0,param_2);
      uVar4 = events_getScorePropertyState();
      if ((uVar4 & 2) != 0) {
        strings_updateMediaTimer((undefined4 *)*puVar1);
      }
      if (iVar3 == 0) {
        if ((uVar4 & 1) != 0) {
          strings_updateMediaTimer((undefined4 *)*puVar1);
        }
        if (param_1[0x75] == 0) {
          events_handleKeyEventWrapper();
        }
        param_1[0x75] = 1;
      }
      events_processTimerTick(param_1);
      sVar2 = Ordinal_58(param_1[8],(byte *)param_1[10]);
      if ((param_1[0x18] != (int)sVar2) && (iVar3 = Ordinal_147(param_1[8],param_2), iVar3 == 0)) {
        param_1[0x1d2] = 0;
        if (param_1[0x1c9] == 0) {
          param_1[0x75] = 0;
          param_1[0x6d] = 0;
          if (param_1[0x18] == -1) {
            param_1[0x18] = -2;
          }
          else {
            lingo_setPlaybackData(param_1[8],(byte *)param_1[10],local_1c);
            param_1[0x77] = 1;
            events_processFrameStep(param_1);
            param_1[0x77] = 0;
          }
          if (param_1[0x6d] == 0) {
            iVar3 = Ordinal_76(param_1[8],(byte *)param_1[10]);
            if (0 < iVar3) {
              events_removeOutOfRangeSlots((int)param_1,param_1[10],iVar3);
            }
            sVar2 = Ordinal_143(param_1[8],(byte *)param_1[10]);
            if (sVar2 == 0) {
              events_resetFrameState((int)param_1);
            }
          }
          else {
            param_1[0x75] = 1;
          }
        }
        else {
          param_1[0x1c9] = 0;
        }
      }
      if ((param_2 != (uint *)0x0) && (*param_2 != 0)) {
        uVar4 = Ordinal_1541();
        if ((param_1[0x14] < 1) || ((uint)param_1[0x15] <= uVar4)) {
          *param_2 = 0;
        }
        else {
          uVar4 = param_1[0x15] - uVar4;
          if (uVar4 < *param_2) {
            *param_2 = uVar4;
          }
        }
      }
      return 0;
    }
    lingo_setPlaybackData(param_1[8],(byte *)param_1[10],local_1c);
    events_initFrameDisplay((int)local_1c);
    Ordinal_104(param_1[8],0x1000);
    events_processTimerTick(param_1);
    param_1[0x1d2] = 0;
  }
  return 0;
}



// ============================================================
// Function: events_createMovieContext (events_createMovieContext)
// Address: 68067150
// Size: 183 bytes
// Params: int param_1
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * events_createMovieContext(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint local_14 [3];
  undefined4 local_8;
  
  puVar1 = (undefined4 *)Ordinal_1124(0x680);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = *(undefined4 *)(param_1 + 0x10);
  puVar1[2] = param_1;
  puVar1[1] = &DAT_681962f8;
  puVar1[0x163] = puVar1;
  if (DAT_681956e0 == 0) {
    DAT_681956e0 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  stage_initDateGlobals();
  uVar4 = Ordinal_1542();
  local_8 = (undefined4)((ulonglong)uVar4 >> 0x20);
  iVar2 = Ordinal_1546();
  cast_seedRandom((int)uVar4 + iVar2);
  crt_initRuntime(puVar1 + 0x1c);
  cast_createThreadContext(puVar1 + 3,(int)(puVar1 + 0x1c),0);
  puVar1[0x167] = ((int)*(char *)(param_1 + 0x1c) & 0x10U) >> 4;
  uVar3 = Ordinal_1545();
  puVar1[10] = uVar3;
  core_setMovieScript(puVar1[5]);
  crt_getScriptInstance(puVar1[5],local_14);
  return puVar1;
}



// ============================================================
// Function: events_destroyMovieInstance (events_destroyMovieInstance)
// Address: 68067210
// Size: 106 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_destroyMovieInstance(int *param_1)
{
  uint uVar1;
  int *piVar2;
  
  uVar1 = *(uint *)(*param_1 + 0x14);
  piVar2 = *(int **)(*param_1 + 0x658);
  if (piVar2 != (int *)0x0) {
    cast_releaseObject(uVar1,piVar2);
  }
  crt_removeCurrentBehavior(uVar1);
  events_releaseSessionData(*param_1);
  core_destroyAsyncNetwork(uVar1);
  cast_destroyContext(uVar1);
  cast_destroyThreadContext(*param_1 + 0xc);
  cast_freeContextHandles(*param_1 + 0x70);
  if (*(int *)(*param_1 + 0x6c) != 0) {
    Ordinal_1163((int *)(*param_1 + 0x6c));
  }
  Ordinal_1125(param_1);
  return 0;
}



// ============================================================
// Function: events_loadLingoIni (events_loadLingoIni)
// Address: 68067280
// Size: 358 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_loadLingoIni(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *unaff_EBX;
  undefined4 local_428;
  int local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  local_424 = 0;
  local_428 = 0;
  Ordinal_1320(local_420,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 8));
  Ordinal_1316(local_420);
  Ordinal_1317(local_420,"LINGO.INI");
  iVar1 = Ordinal_1402(&local_428,local_420,1);
  if ((((iVar1 != 0) && (iVar1 = Ordinal_1435(local_428), iVar1 != 0)) &&
      (local_424 = Ordinal_1111(iVar1,0), local_424 != 0)) &&
     ((iVar2 = Ordinal_1114(local_424), iVar2 != 0 &&
      (iVar3 = Ordinal_1409(local_428,iVar2,iVar1), iVar3 != 0)))) {
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        if (*(char *)(iVar3 + iVar2) == '\r') break;
        if (*(char *)(iVar3 + iVar2) == '\n') {
          *(undefined1 *)(iVar3 + iVar2) = 0xd;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    Ordinal_1115(local_424);
    iVar1 = cast_getScriptCount((int)unaff_EBX);
    if (iVar1 != 0) {
      piVar4 = (int *)cast_invokeHandlerEx(unaff_EBX,iVar1,local_424,5,0);
      if (piVar4 == (int *)0x0) {
        cast_invalidateScript((uint)unaff_EBX,iVar1);
      }
      else {
        local_424 = 0;
        iVar1 = cast_isContextEmpty(unaff_EBX,piVar4);
        if (iVar1 == 0) {
          cast_resolveHandler((int)unaff_EBX,piVar4,0);
        }
      }
    }
  }
  Ordinal_1113(&local_424);
  Ordinal_1407(&local_428);
  return 0;
}



// ============================================================
// Function: events_allocateSessionBlock (events_allocateSessionBlock)
// Address: 680673f0
// Size: 30 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_allocateSessionBlock(undefined4 param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)Ordinal_1124(0x82c);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar1 = param_1;
  return 0;
}



// ============================================================
// Function: events_cleanupMovieInstance (events_cleanupMovieInstance)
// Address: 68067410
// Size: 65 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_cleanupMovieInstance(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (*(int **)(*piVar1 + 0x4c) == piVar1) {
    sprites_initTextState(piVar1);
  }
  iVar2 = ((int *)*param_1)[8];
  if (iVar2 == *(int *)(*(int *)*param_1 + 0x648)) {
    lingo_getMiscState(iVar2);
  }
  cast_destroyThreadContext(*param_1 + 4);
  Ordinal_1125(param_1);
  return 0;
}



// ============================================================
// Function: events_initWindowContext (events_initWindowContext)
// Address: 68067460
// Size: 67 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_initWindowContext(int *param_1)
{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (DAT_681962e8 == 0)) {
    DAT_681962e8 = 1;
    iVar1 = Ordinal_1303();
    if (iVar1 == 0) {
      events_setGlobalRef(param_1[3],(int *)0x0);
    }
    events_loadLingoIni(*param_1);
  }
  return 0;
}



// ============================================================
// Function: events_handleWindowResize (events_handleWindowResize)
// Address: 680674b0
// Size: 118 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int events_handleWindowResize(int param_1)
{
  int iVar1;
  int iVar2;
  uint local_146c [1305];
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0xc);
  Ordinal_56(*(int *)(param_1 + 0x20),(byte *)0x0,local_146c);
  *(uint *)(param_1 + 500) = local_146c[0];
  *(uint *)(param_1 + 0x760) = (-(uint)(local_146c[0] < 0x700) & 0xfffffffe) + 2;
  iVar2 = events_getScoreFrameRate(iVar1);
  *(uint *)(iVar1 + 0xe0) = (uint)(9 < iVar2);
  return 0;
}




// ============================================================
// Function: events_updateWindowState (events_updateWindowState)
// Address: 68067530
// Size: 65 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_updateWindowState(int *param_1)
{
  if ((param_1[0x7d] != 0) && ((uint)param_1[0x7d] < 0x700)) {
    if (*param_1 != 0) {
      param_1[0x14] = *(int *)(*param_1 + 0x664);
      return 0;
    }
    param_1[0x14] = 0;
    return 0;
  }
  param_1[0x14] = 1;
  return 0;
}



// ============================================================
// Function: events_notifyWindowClose (events_notifyWindowClose)
// Address: 68067580
// Size: 152 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_notifyWindowClose(int *param_1)
{
  int iVar1;
  
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x19] = 0;
  param_1[0x69] = 0;
  iVar1 = sprites_getChannelRef(param_1[3]);
  param_1[0x1b] = iVar1;
  param_1[0x1c] = 0x2a30;
  param_1[100] = 1;
  param_1[0x65] = 1;
  param_1[0x66] = 0;
  param_1[0x5c] = 0;
  param_1[0x5b] = 0;
  param_1[0x5e] = 0;
  param_1[99] = 0;
  param_1[0x68] = 0;
  param_1[0x1d] = -1;
  param_1[0x1d3] = 0;
  param_1[0x15] = 0;
  events_updateWindowState(param_1);
  return 0;
}



// ============================================================
// Function: events_processMovieEvent (events_processMovieEvent)
// Address: 68067620
// Size: 215 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_processMovieEvent(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0xfffffffe;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1e8) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 1;
  *(undefined4 *)(param_1 + 0x1bc) = 1;
  *(undefined4 *)(param_1 + 0x1b8) = 1;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0x7fff;
  iVar1 = sprites_getChannelRef(*(int *)(param_1 + 0xc));
  *(int *)(param_1 + 0x68) = iVar1;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined2 *)(param_1 + 0x98) = 0xffff;
  *(undefined2 *)(param_1 + 0x9a) = 0xffff;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x754) = 1;
  *(undefined4 *)(param_1 + 0x758) = 1;
  *(undefined4 *)(param_1 + 0x1cc) = 1;
  uVar2 = events_getScoreProperty2(*(int *)(param_1 + 0xc));
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xf4) = uVar2;
  events_handleWindowResize(param_1);
  return 1;
}



// ============================================================
// Function: events_requestMovieAction (events_requestMovieAction)
// Address: 68067700
// Size: 27 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_requestMovieAction(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = Ordinal_270(*(int *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x1e0) = uVar1;
  return 0;
}



// ============================================================
// Function: events_postMovieNotify (events_postMovieNotify)
// Address: 68067720
// Size: 28 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_postMovieNotify(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x1d0) = param_2;
  scoreEngine_setPropertyAccess(*(int *)(param_1 + 0x20));
  return 0;
}



// ============================================================
// Function: events_handleMovieCallback (events_handleMovieCallback)
// Address: 68067740
// Size: 186 bytes
// Params: int param_1, int param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * events_handleMovieCallback(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x14);
  piVar2 = (int *)events_allocateSessionBlock(iVar1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_2 == 0) {
    param_2 = scoreEngine_setPropertyAccess(*(int *)(param_1 + 0xc));
  }
  iVar3 = *(int *)(param_1 + 0xc);
  piVar2[8] = iVar3;
  iVar3 = scoreEngine_accessProperty(iVar3,param_2);
  piVar2[9] = iVar3;
  piVar2[10] = iVar3;
  piVar2[0xb] = param_1;
  cast_createThreadContext(piVar2 + 1,iVar1 + 0x70,(int)piVar2);
  piVar2[0x60] = 0;
  piVar2[0x6a] = 1;
  piVar2[0x5f] = 1;
  piVar2[0x7d] = 0x700;
  events_processMovieEvent((int)piVar2);
  events_notifyWindowClose(piVar2);
  piVar2[0x1d9] = 1;
  piVar2[0x1da] = 1;
  piVar2[0x1db] = 0;
  piVar2[0x1dc] = 0;
  piVar2[0x1dd] = 0;
  piVar2[0x1de] = 0;
  return piVar2;
}



// ============================================================
// Function: events_createEventContext (FUN_68067800)
// Address: 68067800
// Size: 10 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_createEventContext(void)

{
  int in_EAX;
  
  return *(undefined4 *)(*(int *)(*(int *)(in_EAX + 8) + 0x18) + 0xc);
}



// ============================================================
// Function: events_getLifecycleState (FUN_68067810)
// Address: 68067810
// Size: 38 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getLifecycleState(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  
  puVar2 = &local_8;
  local_8 = 0;
  iVar1 = events_createEventContext();
  Ordinal_54(iVar1,puVar2);
  return local_8;
}



// ============================================================
// Function: events_addRefEvent (FUN_68067840)
// Address: 68067840
// Size: 25 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall events_addRefEvent(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*param_1 != 0) {
    uVar1 = events_createEventContext();
    return uVar1;
  }
  if (param_1[0x10] != 0) {
    uVar1 = *(undefined4 *)(param_1[0x10] + 0xc);
  }
  return uVar1;
}



// ============================================================
// Function: events_processEvent (FUN_68067860)
// Address: 68067860
// Size: 57 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall events_processEvent(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  if (*param_1 != 0) {
    uVar2 = events_getLifecycleState();
    return uVar2;
  }
  uVar2 = 0;
  if ((param_1[0x10] != 0) && (iVar1 = *(int *)(param_1[0x10] + 0xc), iVar1 != 0)) {
    Ordinal_54(iVar1,&local_8);
    uVar2 = local_8;
  }
  return uVar2;
}



// ============================================================
// Function: events_releaseLifecycle (FUN_680678a0)
// Address: 680678a0
// Size: 41 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_releaseLifecycle(undefined4 param_1,undefined4 param_2)
{
  int *in_EAX;
  undefined4 unaff_ESI;
  
  if (*in_EAX != 0) {
    Ordinal_86(*(int *)(*(int *)(in_EAX[1] + 8) + 0x18),unaff_ESI,param_2);
    return 0;
  }
  if (in_EAX[0x10] != 0) {
    Ordinal_86(in_EAX[0x10],unaff_ESI,param_2);
  }
  return 0;
}



// ============================================================
// Function: events_createLifecycle (FUN_680678d0)
// Address: 680678d0
// Size: 240 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_createLifecycle(undefined4 param_1)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *local_8;
  
  piVar1 = (int *)Ordinal_1114(param_1);
  local_8 = (int *)0x0;
  if (((piVar1 != (int *)0x0) && (piVar1[1] != 0)) &&
     (iVar2 = *(int *)(piVar1[1] + 0x668), iVar2 != 0)) {
    uVar4 = 0;
    iVar2 = Ordinal_1154(iVar2);
    if (iVar2 != 0) {
      do {
        iVar2 = Ordinal_1155(*(undefined4 *)(piVar1[1] + 0x668),uVar4,&local_8);
        if ((iVar2 != 0) && (local_8 != (int *)0x0)) {
          *(undefined4 *)(*local_8 + 0xc7c) = 0;
        }
        uVar4 = uVar4 + 1;
        uVar3 = Ordinal_1154(*(undefined4 *)(piVar1[1] + 0x668));
      } while (uVar4 < uVar3);
    }
    piVar1[799] = 1;
    *(int *)(piVar1[1] + 0x670) = *(int *)(piVar1[1] + 0x670) + 1;
    iVar2 = piVar1[1];
    if (*piVar1 == 0) {
      piVar1[0x31d] = *(int *)(iVar2 + 0x670);
      *(undefined4 *)(iVar2 + 0x674) = 0;
      Ordinal_1115(param_1);
      return 0;
    }
    piVar1[0x31d] = *(int *)(iVar2 + 0x670);
    *(undefined4 *)(iVar2 + 0x678) = *(undefined4 *)(iVar2 + 0x670);
    *(undefined4 *)(piVar1[1] + 0x674) = 1;
  }
  Ordinal_1115(param_1);
  return 0;
}



// ============================================================
// Function: events_resetLifecycleState (events_resetLifecycleState)
// Address: 680679c0
// Size: 52 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resetLifecycleState(void)
{
  code *pcVar1;
  int unaff_ESI;
  
  pcVar1 = *(code **)(*(int *)(*(int *)(unaff_ESI + 8) + 0xc) + 0x128);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(*(undefined4 *)(unaff_ESI + 0x67c),0);
  }
  Ordinal_2217(*(undefined4 *)(unaff_ESI + 0x67c),0);
  *(undefined4 *)(unaff_ESI + 0x67c) = 0;
  return 0;
}



// ============================================================
// Function: events_retainEvent (FUN_68067a00)
// Address: 68067a00
// Size: 24 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_retainEvent(void)
{
  int *unaff_ESI;
  
  cast_retainObject(*(undefined4 *)(*(int *)(*unaff_ESI + 4) + 0x14),*(int **)(*unaff_ESI + 0x44));
  *(int *)(*unaff_ESI + 0x48) = *(int *)(*unaff_ESI + 0x48) + 1;
  return 0;
}



// ============================================================
// Function: events_releaseEvent (FUN_68067a20)
// Address: 68067a20
// Size: 24 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_releaseEvent(int *param_1)
{
  *(int *)(*param_1 + 0x48) = *(int *)(*param_1 + 0x48) + -1;
  cast_releaseObject(*(undefined4 *)(*(int *)(*param_1 + 4) + 0x14),*(int **)(*param_1 + 0x44));
  return 0;
}



// ============================================================
// Function: events_releaseMovieRef (events_releaseMovieRef)
// Address: 68067a40
// Size: 138 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_releaseMovieRef(void)
{
  int *unaff_ESI;
  uint local_1c [6];
  
  unaff_ESI[0x31c] = 1;
  unaff_ESI[0x31e] = 0;
  unaff_ESI[799] = 0;
  if ((unaff_ESI[0x10] != 0) && (*unaff_ESI == 0)) {
    local_1c[1] = 0;
    local_1c[2] = 0;
    local_1c[3] = 0;
    local_1c[4] = 0;
    local_1c[5] = 0;
    local_1c[0] = 0;
    Ordinal_360(*(int **)(unaff_ESI[0x10] + 0xc),(undefined4 ***)0x0,1,(double *)local_1c);
    Ordinal_85((int *)unaff_ESI[0x10],(uint)(0x6ff < local_1c[0]));
  }
  if (unaff_ESI[0x10] != 0) {
    if (unaff_ESI[0xf] != 0) {
      Ordinal_1115(unaff_ESI[0xf]);
    }
    unaff_ESI[0x10] = 0;
  }
  if (unaff_ESI[0xf] != 0) {
    Ordinal_1113(unaff_ESI + 0xf);
  }
  return 0;
}




// ============================================================
// Function: events_dispatchMovieEvent (events_dispatchMovieEvent)
// Address: 68067ad0
// Size: 49 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_dispatchMovieEvent(int param_1)
{
  int iVar1;
  
  iVar1 = Ordinal_1114();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    iVar1 = Ordinal_118(*(int *)(*(int *)(iVar1 + 0x40) + 0xc));
    sprites_handleEditCommand(iVar1,param_1);
    Ordinal_1115();
  }
  return 0;
}



// ============================================================
// Function: events_getLifecycleRef (FUN_68067b10)
// Address: 68067b10
// Size: 95 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getLifecycleRef(int param_1)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_EBX;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  piVar1 = (int *)Ordinal_1114();
  if ((piVar1 != (int *)0x0) && (piVar1[0x10] != 0)) {
    if (param_1 == 0) {
      uVar2 = 0x13;
      uVar4 = 0x25;
    }
    else {
      uVar2 = 0x12;
      uVar4 = 0x24;
    }
    scoreEngine_writePropertyBlock(*(int *)(piVar1[0x10] + 0xc),0,uVar2,0);
    if (*piVar1 != 0) {
      puVar5 = (undefined4 *)0x0;
      iVar3 = events_addRefEvent((int *)*unaff_EBX);
      Ordinal_108(iVar3,uVar4,puVar5);
    }
    Ordinal_1115();
  }
  return 0;
}



// ============================================================
// Function: events_getMovieWindowRef (events_getMovieWindowRef)
// Address: 68067b70
// Size: 47 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMovieWindowRef(void)
{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = Ordinal_1114();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    Ordinal_55(*(int *)(*(int *)(iVar1 + 0x40) + 0xc));
    if (unaff_EDI != 0) {
      events_dispatchMovieEvent(unaff_EDI);
    }
    Ordinal_1115();
  }
  return 0;
}



// ============================================================
// Function: events_initPlaybackSession (events_initPlaybackSession)
// Address: 68067ba0
// Size: 400 bytes
// Params: undefined4 param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_initPlaybackSession(undefined4 param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
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
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_78 = param_3;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_84 = 0;
  local_80 = 0;
  local_70 = 0x1ffffff;
  local_6c = 0x1000000;
  local_7c = param_1;
  local_68 = Ordinal_1600();
  if (local_68 == 0) {
    return 0;
  }
  Ordinal_1613(local_68,local_7c,0);
  Ordinal_1604(local_68);
  Ordinal_51(*(int *)(*(int *)(local_78 + 0x40) + 0xc),(int)&local_38);
  Ordinal_1656();
  iVar1 = Ordinal_1650(local_50,local_4c,local_48,local_30 - local_38,local_2c - local_34,5);
  if (iVar1 != 0) {
    Ordinal_1604(*param_2,iVar1);
    Ordinal_1064(&local_38,-local_38,-local_34);
    Ordinal_1619(*param_2,&local_38,&local_70);
    local_c = local_64;
    local_10 = local_60;
    Ordinal_1614(*param_2,&local_84,local_68,&local_18);
    lingo_getStageLayout(*(int *)(*(int *)(local_78 + 0x40) + 0xc),local_28);
    Ordinal_1619(*param_2,local_28,&local_6c);
  }
  if (local_68 != 0) {
    Ordinal_1604(local_68,0);
    Ordinal_1601(&local_68);
  }
  return 0;
}



// ============================================================
// Function: events_startPlaybackLoop (events_startPlaybackLoop)
// Address: 68067d30
// Size: 519 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __thiscall events_startPlaybackLoop(void *this,undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  uint local_1494;
  undefined4 local_1490;
  int local_148c;
  int local_1488;
  uint local_1484 [6];
  undefined4 local_146c [1304];
  int local_c;
  uint local_8;
  
  if ((short)((uint)param_1 >> 0x10) == 0) {
LAB_68067f23:
    return 0;
  }
  local_1494 = 0;
  iVar1 = Ordinal_294(*(int *)((int)this + 0x20),*(int *)((int)this + 0x28),param_1,0x3f,local_1484)
  ;
  if (iVar1 != 0) {
    local_1494 = local_1484[0];
  }
  iVar1 = Ordinal_294(*(int *)((int)this + 0x20),*(int *)((int)this + 0x28),param_1,0x3b,local_1484)
  ;
  if (iVar1 == 0) goto LAB_68067f23;
  local_1490 = 0x1ffffff;
  iVar1 = Ordinal_70(*(int *)(*(int *)(unaff_ESI + 0x40) + 0xc));
  uVar2 = Ordinal_366(*(int *)(*(int *)(unaff_ESI + 0x40) + 0xc),iVar1,(int *)0x100);
  local_1488 = Ordinal_1600();
  if (local_1488 == 0) goto LAB_68067ef3;
  Ordinal_1613(local_1488,uVar2,0);
  if (*(int *)(unaff_ESI + 0x40) != 0) {
    local_148c = 0;
    Ordinal_56(*(int *)(*(int *)(unaff_ESI + 0x40) + 0xc),(byte *)0x0,local_146c);
    if (local_c == 0) {
LAB_68067e4a:
      Ordinal_1604(local_1488,local_1484[0]);
    }
    else {
      iVar1 = events_initPlaybackSession(uVar2,&local_1488,unaff_ESI);
      if (iVar1 == 0) goto LAB_68067e4a;
      local_148c = 1;
    }
    Ordinal_1670(local_1488,local_1494 != 1,&local_1490,0);
    if ((local_c != 0) && (local_148c != 0)) {
      local_148c = Ordinal_1605(local_1488);
      Ordinal_1604(local_1488,0);
      if (local_148c != 0) {
        Ordinal_1653(&local_148c);
      }
    }
  }
  Ordinal_1604(local_1488,0);
  Ordinal_1609(local_1488,0);
  Ordinal_1611(local_1488,0);
LAB_68067ef3:
  Ordinal_1653(local_1484);
  Ordinal_1601(&local_1488);
  return 0;
}



// ============================================================
// Function: events_runMoviePlayback (events_runMoviePlayback)
// Address: 68067f40
// Size: 418 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __fastcall events_runMoviePlayback(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_146c;
  short local_1468;
  uint local_824;
  undefined4 local_820;
  undefined4 local_81c;
  undefined4 local_818;
  undefined4 local_814;
  undefined4 local_810;
  char local_80c [1023];
  char local_40d [1029];
  uint local_8;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    Ordinal_56(*(int *)(*(int *)(param_1 + 0x40) + 0xc),(byte *)0x0,&local_146c);
    iVar1 = *(int *)(param_1 + 0xc88);
    if ((iVar1 == 0) && (*(uint *)(param_1 + 0xc8c) != 0)) {
      local_824 = ~(~(~*(uint *)(param_1 + 0xc8c) & local_824) & ~*(uint *)(param_1 + 0xc64));
    }
    *(uint *)(param_1 + 0xc64) = local_824;
    if ((iVar1 != 0) || ((*(byte *)(param_1 + 0xc90) & 0x20) == 0)) {
      *(undefined4 *)(param_1 + 0xc50) = local_820;
    }
    if ((iVar1 != 0) || ((*(byte *)(param_1 + 0xc90) & 0x10) == 0)) {
      *(undefined4 *)(param_1 + 0xc5c) = local_81c;
    }
    if ((iVar1 != 0) || ((*(byte *)(param_1 + 0xc90) & 4) == 0)) {
      uVar2 = Ordinal_362(*(int *)(*(int *)(param_1 + 0x40) + 0xc),0,&local_818);
      *(undefined4 *)(param_1 + 0xc54) = uVar2;
    }
    if ((*(int *)(param_1 + 0xc88) != 0) || ((*(byte *)(param_1 + 0xc90) & 2) == 0)) {
      uVar2 = Ordinal_362(*(int *)(*(int *)(param_1 + 0x40) + 0xc),0,&local_814);
      *(undefined4 *)(param_1 + 0xc58) = uVar2;
    }
    if ((*(int *)(param_1 + 0xc88) != 0) || ((*(byte *)(param_1 + 0xc90) & 8) == 0)) {
      uVar2 = Ordinal_362(*(int *)(*(int *)(param_1 + 0x40) + 0xc),0,&local_810);
      *(undefined4 *)(param_1 + 0xc60) = uVar2;
    }
    if (0x73c < local_1468) {
      if (((*(int *)(param_1 + 0xc88) != 0) || ((*(byte *)(param_1 + 0xc90) & 1) == 0)) &&
         (((*(byte *)(param_1 + 0xc64) & 4) == 0 || (local_80c[0] != '\0')))) {
        Ordinal_1232(param_1 + 0x50,local_80c);
      }
      if (((*(int *)(param_1 + 0xc88) != 0) || ((*(byte *)(param_1 + 0xc90) & 0x40) == 0)) &&
         (local_40d[0] != '\0')) {
        Ordinal_1232(param_1 + 0x84e,local_40d);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: events_getEventState (FUN_680680f0)
// Address: 680680f0
// Size: 100 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getEventState(int param_1)
{
  short sVar1;
  int iVar2;
  undefined1 local_28 [32];
  uint local_8;
  
  iVar2 = media_applyPixelOp(**(int **)(param_1 + 4),1,local_28,0x20);
  if (iVar2 == 0) {
    sVar1 = Ordinal_1206("Author",local_28);
    if (sVar1 == 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_checkWindowActive (events_checkWindowActive)
// Address: 68068160
// Size: 100 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_checkWindowActive(int param_1)
{
  short sVar1;
  int iVar2;
  undefined1 local_28 [32];
  uint local_8;
  
  iVar2 = media_applyPixelOp(**(int **)(param_1 + 4),1,local_28,0x20);
  if (iVar2 == 0) {
    sVar1 = Ordinal_1206("Plugin",local_28);
    if (sVar1 == 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_activateWindow (events_activateWindow)
// Address: 680681d0
// Size: 123 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_activateWindow(int param_1)
{
  code *pcVar1;
  int *unaff_EDI;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_408[0] = 0;
  Ordinal_1880(*unaff_EDI,0,local_408);
  if (*unaff_EDI == *(int *)(param_1 + 0x67c)) {
    events_resetLifecycleState();
  }
  pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x110);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(*unaff_EDI);
    *unaff_EDI = 0;
    return 0;
  }
  Ordinal_1811();
  return 0;
}




// ============================================================
// Function: events_shutdownPlayback (events_shutdownPlayback)
// Address: 68068250
// Size: 379 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_shutdownPlayback(undefined4 *param_1)
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *local_ca8;
  undefined4 *local_ca4;
  int local_ca0 [806];
  uint local_8;
  
  uVar6 = 0;
  local_ca8 = param_1;
  bVar1 = false;
  piVar2 = (int *)Ordinal_1114(param_1);
  if ((piVar2 != (int *)0x0) && (piVar2[0x31c] == 1)) {
    Ordinal_1115(local_ca8);
    return 0;
  }
  iVar5 = piVar2[1];
  if (local_ca8 == *(undefined4 **)(iVar5 + 0x66c)) {
    *(undefined4 *)(iVar5 + 0x66c) = 0;
  }
  else {
    iVar3 = Ordinal_1154(*(undefined4 *)(iVar5 + 0x668));
    if (iVar3 != 0) {
      do {
        iVar3 = Ordinal_1155(*(undefined4 *)(iVar5 + 0x668),uVar6,&local_ca4);
        if (((iVar3 != 0) && (local_ca4 != (undefined4 *)0x0)) && (local_ca4 == local_ca8)) {
          local_ca4 = (undefined4 *)0x0;
          Ordinal_1159(*(undefined4 *)(iVar5 + 0x668),uVar6,&local_ca4);
          break;
        }
        uVar6 = uVar6 + 1;
        uVar4 = Ordinal_1154(*(undefined4 *)(iVar5 + 0x668));
      } while (uVar6 < uVar4);
    }
  }
  if (*piVar2 == 0) {
    local_ca4 = (undefined4 *)events_processEvent((int *)*local_ca8);
    stage_removeEventsByChannel(piVar2[1],(int)local_ca4);
    events_releaseMovieRef();
    bVar1 = true;
    events_releaseLifecycle(1,0);
    if (local_ca4 != (undefined4 *)0x0) {
      events_activateWindow(piVar2[1]);
    }
  }
  piVar7 = local_ca0;
  for (iVar5 = 0x326; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar7 = piVar7 + 1;
  }
  Ordinal_1113(&local_ca8);
  if (!bVar1) {
    events_releaseMovieRef();
  }
  return 0;
}



// ============================================================
// Function: events_finalizeSession (events_finalizeSession)
// Address: 680683d0
// Size: 129 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_finalizeSession(void)
{
  int *piVar1;
  int iVar2;
  undefined4 local_8;
  
  piVar1 = (int *)Ordinal_1114();
  if (((piVar1 != (int *)0x0) && ((int *)piVar1[0x10] != (int *)0x0)) && (*piVar1 == 0)) {
    local_8 = 0;
    piVar1[0x31e] = 1;
    Ordinal_96((int *)piVar1[0x10]);
    Ordinal_89(piVar1[0x10],1);
    iVar2 = events_getEventState(piVar1[1]);
    if (iVar2 != 0) {
      iVar2 = Ordinal_118(*(int *)(piVar1[0x10] + 0xc));
      crt_setMiawProperty(*(uint *)(iVar2 + 0xc),8,1);
    }
    Ordinal_90(piVar1[0x10],&local_8,(undefined1 *)0x0,0);
  }
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: events_releaseSessionData (events_releaseSessionData)
// Address: 68068460
// Size: 192 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_releaseSessionData(int param_1)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_10;
  undefined4 *local_8;
  
  if (*(int *)(param_1 + 0x668) != 0) {
    local_10 = 0;
    iVar1 = Ordinal_1154(*(int *)(param_1 + 0x668));
    if (iVar1 != 0) {
      do {
        iVar1 = Ordinal_1155(*(undefined4 *)(param_1 + 0x668),local_10,&local_8);
        if ((iVar1 != 0) && (local_8 != (undefined4 *)0x0)) {
          piVar2 = (int *)Ordinal_1114(local_8);
          if (*piVar2 == 0) {
            iVar1 = events_processEvent((int *)*local_8);
            events_releaseLifecycle(1,0);
            if (iVar1 != 0) {
              events_activateWindow(param_1);
            }
          }
          events_releaseMovieRef();
          Ordinal_1115(local_8);
        }
        local_10 = local_10 + 1;
        uVar3 = Ordinal_1154(*(undefined4 *)(param_1 + 0x668));
      } while (local_10 < uVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: events_requestWindowClose (events_requestWindowClose)
// Address: 68068520
// Size: 335 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_requestWindowClose(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint local_14;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_c = (undefined4 *)0x0;
  iVar6 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  local_8 = 0;
  if (((param_2 != 0) && (*(int *)(iVar6 + 0x668) != 0)) &&
     (iVar2 = sprites_getStageRef(param_1), iVar2 != 0)) {
    iVar2 = Ordinal_1114(param_2);
    if (param_3 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(int *)(iVar6 + 0x670) + 1;
    }
    local_14 = 0;
    iVar3 = Ordinal_1154(*(undefined4 *)(iVar6 + 0x668));
    if (iVar3 != 0) {
      do {
        iVar3 = Ordinal_1155(*(undefined4 *)(iVar6 + 0x668),local_14,&local_c);
        if ((iVar3 != 0) && (local_c != (undefined4 *)0x0)) {
          piVar1 = (int *)*local_c;
          uVar4 = piVar1[0x31d];
          if (param_3 == 0) {
            if ((uVar4 < *(uint *)(iVar2 + 0xc74)) && (uVar7 < uVar4)) goto LAB_680685ea;
          }
          else if ((*(uint *)(iVar2 + 0xc74) < uVar4) && (uVar4 < uVar7)) {
LAB_680685ea:
            uVar5 = events_processEvent(piVar1);
            iVar3 = Ordinal_1819(uVar5);
            if (iVar3 != 0) {
              uVar7 = piVar1[0x31d];
              local_8 = uVar5;
            }
          }
        }
        local_14 = local_14 + 1;
        uVar4 = Ordinal_1154(*(undefined4 *)(iVar6 + 0x668));
      } while (local_14 < uVar4);
    }
    uVar4 = *(uint *)(iVar6 + 0x678);
    if (param_3 == 0) {
      if ((*(uint *)(iVar2 + 0xc74) <= uVar4) || (uVar4 <= uVar7)) goto LAB_68068661;
    }
    else if ((uVar4 <= *(uint *)(iVar2 + 0xc74)) || (uVar7 <= uVar4)) goto LAB_68068661;
    uVar5 = events_getLifecycleState();
    iVar6 = Ordinal_1819(uVar5);
    if (iVar6 != 0) {
      local_8 = uVar5;
    }
  }
LAB_68068661:
  Ordinal_1115(param_2);
  return local_8;
}



// ============================================================
// Function: events_checkStageActive (events_checkStageActive)
// Address: 68068680
// Size: 169 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_checkStageActive(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_10;
  uint local_c;
  undefined4 *local_8;
  
  uVar5 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = (undefined4 *)0x0;
  if ((*(int *)(param_1 + 0x674) == 0) && (*(int *)(param_1 + 0x668) != 0)) {
    iVar2 = Ordinal_1154(*(int *)(param_1 + 0x668));
    if (iVar2 != 0) {
      do {
        iVar2 = Ordinal_1155(*(undefined4 *)(param_1 + 0x668),uVar5,&local_8);
        if (((iVar2 != 0) && (local_8 != (undefined4 *)0x0)) &&
           (piVar1 = (int *)*local_8, local_c < (uint)piVar1[0x31d])) {
          uVar3 = events_processEvent(piVar1);
          iVar2 = Ordinal_1819(uVar3);
          if (iVar2 != 0) {
            local_c = piVar1[0x31d];
            local_10 = uVar3;
          }
        }
        uVar5 = uVar5 + 1;
        uVar4 = Ordinal_1154(*(undefined4 *)(param_1 + 0x668));
      } while (uVar5 < uVar4);
    }
    return local_10;
  }
  uVar3 = events_getLifecycleState();
  return uVar3;
}



// ============================================================
// Function: events_getStageActiveState (events_getStageActiveState)
// Address: 68068730
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getStageActiveState(int param_1)

{
  return *(undefined4 *)(param_1 + 0x67c);
}



// ============================================================
// Function: events_dispatchGlobalEvent (events_dispatchGlobalEvent)
// Address: 68068740
// Size: 214 bytes
// Params: int param_1, uint param_2, uint param_3, uint * param_4, int * param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_dispatchGlobalEvent(int param_1,uint param_2,uint param_3,uint *param_4,int *param_5,int *param_6)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_c;
  int *local_8;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x668) != 0)) {
    local_c = 0;
    iVar1 = Ordinal_1154(*(int *)(param_1 + 0x668));
    if (iVar1 != 0) {
      do {
        local_8 = (int *)0x0;
        iVar1 = Ordinal_1155(*(undefined4 *)(param_1 + 0x668),local_c,&local_8);
        if ((iVar1 != 0) && (local_8 != (int *)0x0)) {
          events_retainEvent();
          if ((*local_8 != 0) && (iVar1 = *(int *)(*local_8 + 0x40), iVar1 != 0)) {
            piVar2 = (int *)Ordinal_118(*(int *)(iVar1 + 0xc));
            iVar1 = piVar2[3];
            events_dispatchSpriteHandlers(piVar2,(byte *)0x0,0,param_2,param_3,param_4,param_5,param_6);
            if (param_5 != (int *)0x0) {
              props_releaseAndClear(iVar1,param_5);
            }
          }
          events_releaseEvent(local_8);
        }
        local_c = local_c + 1;
        uVar3 = Ordinal_1154(*(undefined4 *)(param_1 + 0x668));
      } while (local_c < uVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getNextUpdateTime (FUN_68068820)
// Address: 68068820
// Size: 499 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getNextUpdateTime(int param_1,uint *param_2)
{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint local_220;
  int local_21c;
  uint local_218;
  int local_214;
  uint local_210;
  int *local_20c;
  undefined1 local_208 [256];
  undefined1 local_108;
  undefined1 local_107 [255];
  uint local_8;
  
  local_21c = param_1;
  local_210 = 0xffffffff;
  if (*(int *)(param_1 + 0x668) != 0) {
    uVar6 = 0;
    local_218 = 0;
    iVar2 = Ordinal_1154(*(int *)(param_1 + 0x668));
    if (iVar2 != 0) {
      do {
        local_214 = 0;
        iVar2 = Ordinal_1155(*(undefined4 *)(param_1 + 0x668),uVar6,&local_20c);
        if ((iVar2 != 0) && (local_20c != (int *)0x0)) {
          piVar3 = (int *)Ordinal_1114(local_20c);
          events_retainEvent();
          if (piVar3[0x321] == 0) {
            if (piVar3[0x31e] == 0) {
              events_finalizeSession();
              param_1 = local_21c;
            }
            if ((int *)piVar3[0x10] != (int *)0x0) {
              iVar2 = Ordinal_94((int *)piVar3[0x10]);
              if (iVar2 == 0) {
                uVar4 = events_processEvent(piVar3);
                pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x130);
                if (pcVar1 != (code *)0x0) {
                  (*pcVar1)(uVar4);
                }
                Ordinal_97((int *)piVar3[0x10],0,&local_220,&local_214,local_208,0x100);
                pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 8) + 0xc) + 0x134);
                if (pcVar1 != (code *)0x0) {
                  (*pcVar1)(uVar4);
                }
                if (local_220 < local_210) {
                  local_210 = local_220;
                }
              }
              else {
                Ordinal_98((int *)piVar3[0x10],0);
              }
            }
            if (local_214 != 0) {
              local_108 = 0;
              Ordinal_1203(local_107,local_208,0xff);
              local_108 = Ordinal_1201(local_107);
              sprites_getPlatformInfo(*(int *)(param_1 + 0x14),(int)&local_108);
            }
          }
          Ordinal_1115(local_20c);
          events_releaseEvent(local_20c);
          uVar6 = local_218;
        }
        uVar6 = uVar6 + 1;
        local_218 = uVar6;
        uVar5 = Ordinal_1154(*(undefined4 *)(param_1 + 0x668));
      } while (uVar6 < uVar5);
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = local_210;
    }
  }
  return 0;
}



// ============================================================
// Function: events_handleMovieOpen (events_handleMovieOpen)
// Address: 68068a20
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleMovieOpen(undefined4 param_1,undefined4 *param_2)
{
  events_shutdownPlayback(param_2);
  return 0;
}



// ============================================================
// Function: events_handleMovieClose (events_handleMovieClose)
// Address: 68068b30
// Size: 188 bytes
// Params: undefined4 * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_handleMovieClose(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar3 = events_getLifecycleState();
  iVar4 = param_2;
  if (param_2 == iVar3) {
    param_1 = (undefined4 *)puVar2[0x19b];
    if (param_1 == (undefined4 *)0x0) {
      return 0;
    }
    piVar1 = (int *)*param_1;
    iVar3 = events_processEvent(piVar1);
    if (iVar3 == iVar4) {
      return piVar1[0x319];
    }
  }
  else {
    uVar6 = 0;
    iVar4 = Ordinal_1154(puVar2[0x19a]);
    if (iVar4 != 0) {
      do {
        param_1 = (undefined4 *)0x0;
        iVar4 = Ordinal_1155(puVar2[0x19a],uVar6,&param_1);
        if ((iVar4 != 0) && (param_1 != (undefined4 *)0x0)) {
          piVar1 = (int *)*param_1;
          iVar4 = events_processEvent(piVar1);
          if (iVar4 == param_2) {
            return piVar1[0x319];
          }
        }
        uVar6 = uVar6 + 1;
        uVar5 = Ordinal_1154(puVar2[0x19a]);
      } while (uVar6 < uVar5);
    }
  }
  return param_2;
}



// ============================================================
// Function: events_handleProjectorStart (events_handleProjectorStart)
// Address: 68068bf0
// Size: 190 bytes
// Params: undefined4 * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_handleProjectorStart(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return 1;
  }
  iVar3 = events_getLifecycleState();
  iVar4 = param_2;
  if (param_2 == iVar3) {
    param_1 = (undefined4 *)puVar2[0x19b];
    if (param_1 == (undefined4 *)0x0) {
      return 1;
    }
    piVar1 = (int *)*param_1;
    iVar3 = events_processEvent(piVar1);
    if (iVar3 == iVar4) {
      return piVar1[0x314];
    }
  }
  else {
    uVar6 = 0;
    iVar4 = Ordinal_1154(puVar2[0x19a]);
    if (iVar4 != 0) {
      do {
        param_1 = (undefined4 *)0x0;
        iVar4 = Ordinal_1155(puVar2[0x19a],uVar6,&param_1);
        if ((iVar4 != 0) && (param_1 != (undefined4 *)0x0)) {
          piVar1 = (int *)*param_1;
          iVar4 = events_processEvent(piVar1);
          if (iVar4 == param_2) {
            return piVar1[0x314];
          }
        }
        uVar6 = uVar6 + 1;
        uVar5 = Ordinal_1154(puVar2[0x19a]);
      } while (uVar6 < uVar5);
    }
  }
  return param_2;
}



// ============================================================
// Function: events_handleProjectorExit (events_handleProjectorExit)
// Address: 68068cb0
// Size: 193 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleProjectorExit(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *local_8;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  if (*(int *)(iVar1 + 0x668) != 0) {
    uVar4 = 0;
    iVar2 = Ordinal_1154(*(int *)(iVar1 + 0x668));
    if (iVar2 != 0) {
      do {
        local_8 = (int *)0x0;
        iVar2 = Ordinal_1155(*(undefined4 *)(iVar1 + 0x668),uVar4,&local_8);
        if ((iVar2 != 0) && (local_8 != (int *)0x0)) {
          iVar2 = Ordinal_1114(local_8);
          events_retainEvent();
          if ((iVar2 != 0) && (*(int *)(iVar2 + 0x40) != 0)) {
            iVar2 = Ordinal_118(*(int *)(*(int *)(iVar2 + 0x40) + 0xc));
            if (*(int *)(iVar2 + 0xc) != param_1) {
              props_setTraceMode(*(int *)(iVar2 + 0xc),param_2);
            }
          }
          Ordinal_1115(local_8);
          events_releaseEvent(local_8);
        }
        uVar4 = uVar4 + 1;
        uVar3 = Ordinal_1154(*(undefined4 *)(iVar1 + 0x668));
      } while (uVar4 < uVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: events_dispatchHandler (FUN_68068d80)
// Address: 68068d80
// Size: 38 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_dispatchHandler(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = events_processEvent((int *)*param_2);
  if (iVar1 != 0) {
    uVar2 = Ordinal_1819(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_getEventParam (events_getEventParam)
// Address: 68068db0
// Size: 39 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getEventParam(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = Ordinal_1114(param_2);
  Ordinal_1233(param_3,iVar1 + 0x44f);
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: events_notifyScoreChange (events_notifyScoreChange)
// Address: 68068de0
// Size: 102 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_notifyScoreChange(undefined4 param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1114(param_2);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == 0) {
      if (piVar2[0x10] != 0) {
        Ordinal_250(*(int *)(piVar2[0x10] + 0xc),param_3);
      }
    }
    else if ((((piVar2[1] != 0) && (iVar1 = *(int *)(piVar2[1] + 8), iVar1 != 0)) &&
             (iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0)) &&
            (iVar1 = *(int *)(iVar1 + 0xc), iVar1 != 0)) {
      Ordinal_250(iVar1,param_3);
      Ordinal_1115(param_2);
      return 0;
    }
  }
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: events_initScoreCallbacks (events_initScoreCallbacks)
// Address: 68068e50
// Size: 102 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_initScoreCallbacks(undefined4 param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1114(param_2);
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == 0) {
      if (piVar2[0x10] != 0) {
        Ordinal_251(*(int *)(piVar2[0x10] + 0xc),param_3);
      }
    }
    else if ((((piVar2[1] != 0) && (iVar1 = *(int *)(piVar2[1] + 8), iVar1 != 0)) &&
             (iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0)) &&
            (iVar1 = *(int *)(iVar1 + 0xc), iVar1 != 0)) {
      Ordinal_251(iVar1,param_3);
      Ordinal_1115(param_2);
      return 0;
    }
  }
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: events_registerScoreHandler (events_registerScoreHandler)
// Address: 68068ec0
// Size: 37 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_registerScoreHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = Ordinal_1114(param_2);
  Ordinal_1233(param_3,iVar1 + 0x50);
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: events_unregisterScoreHandler (events_unregisterScoreHandler)
// Address: 68068ef0
// Size: 39 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_unregisterScoreHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = Ordinal_1114(param_2);
  Ordinal_1233(param_3,iVar1 + 0x84e);
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: events_broadcastScoreEvent (events_broadcastScoreEvent)
// Address: 68068f20
// Size: 178 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_broadcastScoreEvent(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_808 [1024];
  undefined1 local_408 [1024];
  uint local_8;
  
  events_retainEvent();
  iVar1 = Ordinal_1114(param_2);
  if ((*(uint *)(iVar1 + 0xc64) & 0x1000) != 0) {
    uVar2 = events_processEvent((int *)*param_2);
    Ordinal_1232(local_408,param_3);
    Ordinal_1232(local_808,param_4);
    Ordinal_1882(uVar2,local_408,local_808,param_5,iVar1 + 0x84e);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_processScoreNotify (events_processScoreNotify)
// Address: 68068fe0
// Size: 82 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_processScoreNotify(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  int iVar1;
  undefined4 uVar2;
  
  events_retainEvent();
  iVar1 = Ordinal_1114(param_2);
  uVar2 = events_processEvent((int *)*param_2);
  iVar1 = events_getEventState(*(int *)(iVar1 + 4));
  if (iVar1 == 0) {
    Ordinal_1883(uVar2,param_3,param_4,param_5);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getProjectorRef (events_getProjectorRef)
// Address: 68069040
// Size: 75 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getProjectorRef(undefined4 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  events_retainEvent();
  iVar1 = Ordinal_1114(param_2);
  iVar2 = events_getEventState(*(int *)(iVar1 + 4));
  if ((iVar2 == 0) || ((*(byte *)(iVar1 + 0xc64) & 4) == 0)) {
    uVar3 = events_processEvent((int *)*param_2);
    Ordinal_1868(uVar3);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}




// ============================================================
// Function: events_setProjectorRef (events_setProjectorRef)
// Address: 68069090
// Size: 75 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setProjectorRef(undefined4 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  events_retainEvent();
  iVar1 = Ordinal_1114(param_2);
  iVar2 = events_getEventState(*(int *)(iVar1 + 4));
  if ((iVar2 == 0) || ((*(byte *)(iVar1 + 0xc64) & 4) == 0)) {
    uVar3 = events_processEvent((int *)*param_2);
    Ordinal_1869(uVar3);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getProjectorMode (events_getProjectorMode)
// Address: 680690e0
// Size: 75 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getProjectorMode(undefined4 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  events_retainEvent();
  iVar1 = Ordinal_1114(param_2);
  iVar2 = events_getEventState(*(int *)(iVar1 + 4));
  if ((iVar2 == 0) || ((*(byte *)(iVar1 + 0xc64) & 4) == 0)) {
    uVar3 = events_processEvent((int *)*param_2);
    Ordinal_1877(uVar3);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_handleWindowMessage (events_handleWindowMessage)
// Address: 68069130
// Size: 91 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_handleWindowMessage(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  events_retainEvent();
  uVar1 = events_processEvent((int *)*param_2);
  iVar2 = Ordinal_1878(uVar1);
  if (iVar2 != 0) {
    events_releaseEvent(param_2);
    return 0x215;
  }
  iVar2 = Ordinal_1879(uVar1);
  events_releaseEvent(param_2);
  return (-(uint)(iVar2 != 0) & 0xffffff69) + 0x2ad;
}



// ============================================================
// Function: events_getWindowMessageData (events_getWindowMessageData)
// Address: 68069190
// Size: 59 bytes
// Params: undefined4 param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * events_getWindowMessageData(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_2 + 0xc50);
  if (iVar1 == 1) {
    return (int *)0x217;
  }
  if (iVar1 != 2) {
    if (iVar1 == 4) {
      return (int *)0x21a;
    }
    return param_2;
  }
  return (int *)0x218;
}



// ============================================================
// Function: events_setWindowMessageData (events_setWindowMessageData)
// Address: 680691d0
// Size: 50 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowMessageData(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),
                        (short)*(undefined4 *)(*param_2 + 0xc54));
    *param_3 = uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_getWindowVisible (events_getWindowVisible)
// Address: 68069210
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * events_getWindowVisible(undefined4 param_1,int *param_2)

{
  if (*(int *)(*param_2 + 0xc5c) == 0) {
    return (int *)0x4a5;
  }
  if (*(int *)(*param_2 + 0xc5c) == 1) {
    return (int *)0x23;
  }
  return param_2;
}



// ============================================================
// Function: events_setWindowVisible (events_setWindowVisible)
// Address: 68069240
// Size: 50 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowVisible(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),
                        (short)*(undefined4 *)(*param_2 + 0xc58));
    *param_3 = uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_getWindowTitle (events_getWindowTitle)
// Address: 68069280
// Size: 50 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowTitle(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),
                        (short)*(undefined4 *)(*param_2 + 0xc60));
    *param_3 = uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_setWindowTitle (events_setWindowTitle)
// Address: 680692c0
// Size: 19 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 events_setWindowTitle(undefined4 param_1,int *param_2)

{
  return *(undefined2 *)(*param_2 + 0xc6c);
}



// ============================================================
// Function: events_checkPermission (FUN_680692e0)
// Address: 680692e0
// Size: 28 bytes
// Params: undefined4 param_1, int * param_2, uint param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool events_checkPermission(undefined4 param_1,int *param_2,uint param_3)

{
  return ((int)*(short *)(*param_2 + 0xc64) & param_3) != 0;
}



// ============================================================
// Function: events_getWindowBounds (events_getWindowBounds)
// Address: 68069300
// Size: 101 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowBounds(undefined4 param_1,undefined4 *param_2)
{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = events_processEvent((int *)*param_2);
  if (iVar2 != 0) {
    Ordinal_1816(iVar2);
  }
  piVar3 = (int *)Ordinal_1114(param_2);
  piVar3[0x31d] = 0;
  if (*piVar3 != 0) {
    *(undefined4 *)(piVar3[1] + 0x674) = 0;
  }
  if ((piVar3[0x10] != 0) &&
     (pcVar1 = *(code **)(*(int *)(*(int *)(piVar3[0x10] + 8) + 0xc) + 300), pcVar1 != (code *)0x0))
  {
    (*pcVar1)(iVar2,0);
  }
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: events_setWindowBounds (events_setWindowBounds)
// Address: 68069370
// Size: 164 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowBounds(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int *unaff_EBX;
  int *unaff_ESI;
  int *piVar5;
  int iVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = *(int *)(unaff_EBX[0xb] + 0xc);
  iVar2 = **(int **)(*unaff_EBX + 4);
  Ordinal_163(iVar1,(undefined2 *)unaff_ESI);
  local_18 = *unaff_ESI;
  local_14 = unaff_ESI[1];
  local_10 = unaff_ESI[2];
  local_c = unaff_ESI[3];
  pcVar3 = *(code **)(iVar2 + 0x1b4);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(iVar1,param_1,1,&local_18);
  }
  iVar6 = 1;
  piVar5 = &local_18;
  iVar4 = events_createEventContext();
  Ordinal_50(iVar4,piVar5,iVar6);
  pcVar3 = *(code **)(iVar2 + 0xfc);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(unaff_EBX[0xb],0);
  }
  Ordinal_104(iVar1,0x3000);
  return 0;
}



// ============================================================
// Function: events_resolveWindowPath (events_resolveWindowPath)
// Address: 68069420
// Size: 281 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resolveWindowPath(undefined4 param_1,int *param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  
  iVar7 = *param_3;
  iVar2 = param_3[1];
  iVar3 = param_3[3];
  iVar4 = param_3[2];
  piVar6 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  piVar1 = piVar6 + 3;
  piVar6[5] = iVar3;
  *piVar1 = iVar2;
  piVar6[4] = iVar7;
  piVar6[6] = iVar4;
  if (iVar3 - iVar2 < 0) {
    piVar6[5] = iVar2;
  }
  if (iVar4 - iVar7 < 0) {
    piVar6[6] = iVar7;
  }
  iVar7 = events_processEvent((int *)*param_2);
  if (iVar7 != 0) {
    if (*piVar6 == 0) {
      if (piVar6[0x10] != 0) {
        iVar2 = *(int *)(piVar6[0x10] + 0xc);
        if ((*(byte *)(*(int *)(piVar6[1] + 8) + 0x1c) & 2) == 0) {
          Ordinal_50(iVar2,piVar1,0);
          Ordinal_104(*(int *)(piVar6[0x10] + 0xc),0x3000);
          Ordinal_2218(iVar7,piVar1);
        }
        else {
          Ordinal_50(iVar2,piVar1,0);
          Ordinal_104(*(int *)(piVar6[0x10] + 0xc),0x3000);
          Ordinal_1820(iVar7,0);
        }
      }
    }
    else {
      events_setWindowBounds(iVar7);
    }
  }
  puVar9 = (undefined4 *)0x0;
  uVar8 = 5;
  iVar7 = events_addRefEvent((int *)*param_2);
  Ordinal_108(iVar7,uVar8,puVar9);
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getWindowAspect (events_getWindowAspect)
// Address: 68069540
// Size: 21 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowAspect(undefined4 param_1,int *param_2,int param_3)
{
  if (param_3 != 0) {
    events_releaseEvent(param_2);
  }
  return 0;
}




// ============================================================
// Function: events_setWindowAspect (events_setWindowAspect)
// Address: 68069560
// Size: 285 bytes
// Params: int * param_1, undefined2 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowAspect(int *param_1,undefined2 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  undefined1 *unaff_ESI;
  undefined1 *unaff_EDI;
  undefined1 *local_438;
  int local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar1 = *(int *)(unaff_EBX + 0x20);
  if ((unaff_ESI != (undefined1 *)0x0) && (iVar2 = Ordinal_45(iVar1,local_420), iVar2 != 0)) {
    Ordinal_1314(local_420,unaff_ESI + 1,0x3ff);
    iVar2 = Ordinal_1201(unaff_ESI + 1);
    unaff_ESI[iVar2 + 1] = 0;
    if (iVar2 < 0xff) {
      *unaff_ESI = (char)iVar2;
    }
    else {
      *unaff_ESI = 0xff;
    }
  }
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = 0;
  }
  uVar3 = sprites_getDesktopRect(*(int *)(unaff_EBX + 0xc),param_1);
  if (((short)((uint)uVar3 >> 0x10) != 0) && (unaff_EDI != (undefined1 *)0x0)) {
    local_430 = 0;
    local_42c = 0;
    local_428 = 0;
    local_424 = 0;
    local_438 = unaff_EDI + 1;
    local_434 = 0x3ff;
    Ordinal_294(iVar1,0,uVar3,1,(uint *)&local_438);
    unaff_EDI[local_434 + 1] = 0;
    if (local_434 < 0xff) {
      *unaff_EDI = (char)local_434;
      return 0;
    }
    *unaff_EDI = 0xff;
  }
  return 0;
}



// ============================================================
// Function: events_getWindowStyle (events_getWindowStyle)
// Address: 68069680
// Size: 244 bytes
// Params: int * param_1, uint param_2, int * param_3, undefined2 * param_4, undefined2 * param_5, undefined2 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowStyle(int *param_1,uint param_2,int *param_3,undefined2 *param_4,undefined2 *param_5,
                 undefined2 *param_6)
{
  int iVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar4;
  uint uVar5;
  
  iVar3 = ((int *)param_1[2])[1];
  iVar1 = *(int *)(*(int *)param_1[2] + 0x51c);
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined2 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined2 *)0x0) {
    *param_6 = 0;
  }
  uVar2 = stage_findSpriteHandlerFrame(iVar3,param_2);
  if (CONCAT31(extraout_var,uVar2) == 0) {
    iVar3 = events_createEventContext();
    iVar3 = Ordinal_118(iVar3);
    uVar2 = stage_findSpriteHandlerFrame(iVar3,param_2);
    if (CONCAT31(extraout_var_00,uVar2) == 0) {
      if (*(int *)(iVar1 + 0x668) == 0) {
        return 0;
      }
      uVar5 = 0;
      iVar3 = Ordinal_1154(*(int *)(iVar1 + 0x668));
      if (iVar3 == 0) {
        return 0;
      }
      do {
        iVar3 = Ordinal_1155(*(undefined4 *)(iVar1 + 0x668),uVar5,&param_1);
        if ((((iVar3 != 0) && (param_1 != (int *)0x0)) && (*(int *)(*param_1 + 0x40) != 0)) &&
           (iVar3 = *(int *)(*(int *)(*param_1 + 0x40) + 0xc), iVar3 != 0)) {
          iVar3 = Ordinal_118(iVar3);
          uVar2 = stage_findSpriteHandlerFrame(iVar3,param_2);
          if (CONCAT31(extraout_var_01,uVar2) != 0) break;
        }
        uVar5 = uVar5 + 1;
        uVar4 = Ordinal_1154(*(undefined4 *)(iVar1 + 0x668));
        if (uVar4 <= uVar5) {
          return 0;
        }
      } while( true );
    }
  }
  events_setWindowAspect(param_3,param_5);
  return 0;
}



// ============================================================
// Function: events_setWindowStyle (events_setWindowStyle)
// Address: 68069780
// Size: 68 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowStyle(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)
{
  undefined4 local_8;
  
  local_8 = 0;
  sprites_resetMember(param_1,param_4);
  if ((short)local_8 == 0) {
    local_8 = CONCAT22((short)param_5,(short)((uint)param_5 >> 0x10));
  }
  sprites_getMemberRegPoint(param_1,&local_8);
  return 0;
}



// ============================================================
// Function: events_getWindowFlags (events_getWindowFlags)
// Address: 680697d0
// Size: 96 bytes
// Params: undefined4 param_1, int * param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowFlags(undefined4 param_1,int *param_2,undefined1 *param_3)
{
  cast_getHandlerOffset(param_1,param_2);
  cast_getHandlerOffset(param_1,param_2);
  *param_3 = 0;
  cast_loadPascalString(&DAT_68197780,0x898,0x28);
  props_formatString(param_1,props_checkBufferSpace,param_3,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: events_setWindowFlags (events_setWindowFlags)
// Address: 68069830
// Size: 17 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowFlags(undefined4 param_1,undefined4 *param_2)
{
  events_processEvent((int *)*param_2);
  return 0;
}



// ============================================================
// Function: events_resolveWindowRef (events_resolveWindowRef)
// Address: 68069850
// Size: 114 bytes
// Params: undefined4 * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_resolveWindowRef(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = param_1;
  iVar4 = 0;
  if ((param_1 != (undefined4 *)0x0) && (param_1[0x19a] != 0)) {
    uVar5 = 0;
    iVar2 = Ordinal_1154(param_1[0x19a]);
    if (iVar2 != 0) {
      do {
        param_1 = (undefined4 *)0x0;
        iVar2 = Ordinal_1155(puVar1[0x19a],uVar5,&param_1);
        if (((iVar2 != 0) && (param_1 != (undefined4 *)0x0)) && (*(int *)*param_1 == 0)) {
          iVar4 = iVar4 + 1;
        }
        uVar5 = uVar5 + 1;
        uVar3 = Ordinal_1154(puVar1[0x19a]);
      } while (uVar5 < uVar3);
    }
    return iVar4;
  }
  return 0;
}



// ============================================================
// Function: events_configureWindow (events_configureWindow)
// Address: 680698d0
// Size: 113 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_configureWindow(void)
{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *unaff_EBX;
  
  iVar1 = ((int *)*unaff_EBX)[1];
  iVar3 = events_processEvent((int *)*unaff_EBX);
  if (iVar3 != 0) {
    if (*(int *)(*unaff_EBX + 0xc68) != 0) {
      iVar4 = events_dispatchHandler(0,unaff_EBX);
      if (iVar4 != 0) {
        *(int *)(iVar1 + 0x67c) = iVar3;
        Ordinal_1815(iVar3);
        Ordinal_2217(*(undefined4 *)(iVar1 + 0x67c),1);
        pcVar2 = *(code **)(*(int *)(*(int *)(iVar1 + 8) + 0xc) + 0x128);
        if (pcVar2 != (code *)0x0) {
          (*pcVar2)(iVar3,1);
        }
        events_createLifecycle(unaff_EBX);
        return 0;
      }
    }
    if (iVar3 == *(int *)(iVar1 + 0x67c)) {
      events_resetLifecycleState();
    }
  }
  return 0;
}



// ============================================================
// Function: events_findSpriteAtPoint (events_findSpriteAtPoint)
// Address: 68069950
// Size: 472 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_findSpriteAtPoint(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(*in_EAX + 4);
  iVar2 = Ordinal_118(*(int *)(*(int *)(*in_EAX + 0x40) + 0xc));
  if (*(int *)(*in_EAX + 0xc78) == 0) {
    events_finalizeSession();
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  switch(*param_2) {
  case 2:
    if (*(int *)(iVar1 + 0x67c) == 0) {
      if (*(int *)(*in_EAX + 0xc7c) == 0) {
        Ordinal_1815(param_2[1]);
        events_createLifecycle(in_EAX);
      }
      iVar2 = *(int *)(*(int *)(iVar1 + 8) + 0xc);
      if (*(int *)(iVar2 + 300) != 0) {
        uVar4 = 1;
        uVar3 = events_processEvent((int *)*in_EAX);
        (**(code **)(iVar2 + 300))(uVar3,uVar4);
      }
    }
    break;
  case 10:
  case 0xb:
    if (*(int *)(*in_EAX + 0xc7c) == 0) {
      return 0;
    }
    break;
  case 0xd:
    if (*(int *)(iVar1 + 0x67c) == param_2[1]) {
      events_resetLifecycleState();
    }
    uVar4 = 0;
    uVar3 = events_processEvent((int *)*in_EAX);
    Ordinal_1818(uVar3,uVar4);
    *(undefined4 *)(*in_EAX + 0xc7c) = 0;
    if (*(int *)(iVar1 + 0x67c) == param_2[1]) {
      events_resetLifecycleState();
    }
    events_getLifecycleRef(0);
    if (*(int *)(*in_EAX + 0xc94) != 0) {
      return 1;
    }
    events_dispatchMovieEvent(0x13);
    return 1;
  case 0x12:
  case 0x22:
    return 1;
  case 0x13:
    if (param_2[6] == 0) {
      *(undefined4 *)(iVar2 + 0x754) = 0;
      *(undefined4 *)(*in_EAX + 0xc7c) = 0;
      sprites_setCursorVisible(iVar2,1);
    }
    else {
      events_createLifecycle(in_EAX);
      events_configureWindow();
      *(undefined4 *)(iVar2 + 0x754) = 1;
    }
    break;
  case 0x23:
    *(undefined4 *)(iVar2 + 0x754) = 0;
    *(undefined4 *)(*in_EAX + 0xc7c) = 0;
    sprites_setCursorVisible(iVar2,1);
    return 1;
  }
  iVar2 = Ordinal_91(param_1,param_2,param_3);
  if ((iVar2 == 0) && ((*param_2 == 10 || (*param_2 == 0xb)))) {
    iVar2 = Ordinal_91(*(int **)(*(int *)(iVar1 + 8) + 0x18),param_2,param_3);
  }
  return iVar2;
}



// ============================================================
// Function: sprites_hitTest (FUN_68069b70)
// Address: 68069b70
// Size: 228 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool sprites_hitTest(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int *local_8;
  
  bVar6 = false;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x668) != 0)) {
    bVar2 = false;
    uVar5 = 0;
    iVar3 = Ordinal_1154(*(int *)(param_1 + 0x668));
    if (iVar3 != 0) {
      do {
        if (bVar2) {
          return bVar6;
        }
        local_8 = (int *)0x0;
        iVar3 = Ordinal_1155(*(undefined4 *)(param_1 + 0x668),uVar5,&local_8);
        if ((iVar3 != 0) && (local_8 != (int *)0x0)) {
          piVar1 = (int *)*local_8;
          iVar3 = events_processEvent(piVar1);
          if (iVar3 == param_2[1]) {
            events_retainEvent();
            piVar1 = (int *)piVar1[0x10];
            bVar6 = piVar1 != (int *)0x0;
            if (bVar6) {
              events_findSpriteAtPoint(piVar1,param_2,param_3);
            }
            bVar2 = true;
            events_releaseEvent(local_8);
          }
        }
        uVar5 = uVar5 + 1;
        uVar4 = Ordinal_1154(*(undefined4 *)(param_1 + 0x668));
      } while (uVar5 < uVar4);
    }
    return bVar6;
  }
  return false;
}




// ============================================================
// Function: events_findTopSpriteAtPoint (events_findTopSpriteAtPoint)
// Address: 68069c60
// Size: 375 bytes
// Params: int param_1, int param_2, undefined4 param_3, uint param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_findTopSpriteAtPoint(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_8;
  
  local_8 = 0;
  uVar1 = *(uint *)(**(int **)(param_1 + 8) + 0x51c);
  uVar6 = (uint)(param_2 == 0);
  local_8 = Ordinal_1111(0xc98,1);
  if (local_8 != 0) {
    puVar2 = (uint *)Ordinal_1114(local_8);
    iVar4 = param_2;
    puVar2[0x11] = param_4;
    puVar2[0x12] = 0;
    puVar2[0x313] = 0xffffffff;
    *puVar2 = uVar6;
    puVar2[1] = uVar1;
    puVar2[0x31c] = 0;
    puVar2[0x314] = 1;
    puVar2[0x317] = 0;
    *(undefined2 *)(puVar2 + 0x31b) = 0xff;
    puVar2[0x31e] = uVar6;
    if (uVar6 == 0) {
      Ordinal_1232(puVar2 + 0x14,param_2);
      Ordinal_1232((int)puVar2 + 0x84e,iVar4);
      Ordinal_1232((int)puVar2 + 0x44f,iVar4);
      puVar2[0x322] = 0;
      if (*(int *)(uVar1 + 0x668) == 0) {
        uVar3 = Ordinal_1150(4,4,4);
        *(undefined4 *)(uVar1 + 0x668) = uVar3;
      }
      uVar6 = 0;
      iVar4 = Ordinal_1154(*(undefined4 *)(uVar1 + 0x668));
      if (iVar4 != 0) {
        do {
          param_2 = 0;
          Ordinal_1155(*(undefined4 *)(uVar1 + 0x668),uVar6,&param_2);
          uVar6 = uVar6 + 1;
          uVar5 = Ordinal_1154(*(undefined4 *)(uVar1 + 0x668));
        } while (uVar6 < uVar5);
      }
      Ordinal_1152(*(undefined4 *)(uVar1 + 0x668),&local_8);
    }
    else {
      iVar4 = events_getEventState(uVar1);
      if (iVar4 == 0) {
        puVar2[0x319] = 0x69;
        puVar2[0x322] = 1;
      }
      else {
        puVar2[0x319] = DAT_6818e36c | 1;
        puVar2[0x322] = 1;
      }
      *(int *)(uVar1 + 0x66c) = local_8;
    }
    Ordinal_1115(local_8);
  }
  return local_8;
}



// ============================================================
// Function: events_processHitTestResult (events_processHitTestResult)
// Address: 68069de0
// Size: 45 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_processHitTestResult(undefined4 param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(*param_2 + 0xc68) = param_3;
  events_configureWindow();
  puVar3 = (undefined4 *)0x0;
  uVar2 = 5;
  iVar1 = events_addRefEvent((int *)*param_2);
  Ordinal_108(iVar1,uVar2,puVar3);
  return 0;
}



// ============================================================
// Function: events_invokeCallback (FUN_68069e10)
// Address: 68069e10
// Size: 2171 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __fastcall events_invokeCallback(int param_1,int *param_2,int param_3,int param_4,int param_5)
{
  code *pcVar1;
  void *this;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_21f0;
  int local_21ec;
  int local_21e8;
  int local_21e4;
  int local_21e0;
  int local_21dc;
  int *local_21d8;
  int local_21d4;
  uint local_21d0;
  int local_21cc;
  int local_21c8;
  uint local_21c4;
  void *local_21c0;
  int *local_21bc;
  undefined4 *local_21b8;
  uint local_21b4;
  undefined4 local_21b0;
  uint local_21ac;
  int local_21a8 [3];
  uint local_219c [2];
  int local_2194;
  int local_2190;
  int local_218c;
  int local_2188;
  undefined4 local_2184 [5];
  int local_2170;
  int local_216c;
  int local_2168;
  int local_2164;
  int local_d20 [262];
  undefined1 local_908 [1024];
  undefined1 local_508;
  char local_507;
  undefined1 local_108 [256];
  uint local_8;
  
  local_21d4 = param_3;
  local_21cc = 0;
  local_21c8 = 0;
  local_21c4 = 0;
  local_21d0 = 0;
  local_21f0 = 0;
  local_21c0 = (void *)(*(int **)(param_3 + 8))[1];
  local_21b8 = *(undefined4 **)(**(int **)(param_3 + 8) + 0x51c);
  local_21b4 = 1;
  local_21e8 = 0;
  local_21ec = 0;
  local_21bc = param_2;
  piVar2 = (int *)Ordinal_1114(param_2);
  local_21d8 = piVar2;
  local_21e0 = events_getLifecycleState();
  if (piVar2[0x31c] == 0) {
    iVar3 = events_processEvent((int *)*param_2);
    local_21dc = iVar3;
    if ((*piVar2 != 0) || ((*(byte *)(local_21b8[2] + 0x1c) & 1) == 0)) {
      if (piVar2[0x10] == 0) {
        if (*piVar2 == 0) {
          iVar4 = Ordinal_1111(0x50,2);
          piVar2[0xf] = iVar4;
          if (iVar4 == 0) goto LAB_6806a424;
          iVar4 = Ordinal_1114(iVar4);
          piVar2[0x10] = iVar4;
        }
        else {
          piVar2[0x10] = *(int *)(local_21b8[2] + 0x18);
        }
        if (*piVar2 == 0) {
          local_21b4 = Ordinal_84((int *)piVar2[0x10],local_21b8[2],iVar3,1,(undefined4 *)0x0,
                                  (undefined1 *)0x0,0);
          if (local_21b4 == 0) {
            props_setError(local_21d4,0x36);
            iVar3 = Ordinal_1115(piVar2[0xf]);
            piVar2[0x10] = iVar3;
            Ordinal_1113(piVar2 + 0xf);
            goto LAB_6806a424;
          }
        }
        else {
          local_21b4 = 1;
        }
      }
      iVar4 = Ordinal_45(*(int *)(piVar2[0x10] + 0xc),(undefined4 *)0x0);
      if ((iVar4 != 0) || (*piVar2 != 0)) {
LAB_6806a0c0:
        if (((iVar3 == 0) || (param_5 != 0)) && (piVar2[0x13] == 0)) {
          local_21dc = piVar2[0x318];
          local_21b0 = piVar2[0x315];
          iVar3 = piVar2[0x316];
          iVar4 = Ordinal_1062(piVar2 + 3);
          if (iVar4 != 0) {
            Ordinal_56(*(int *)(piVar2[0x10] + 0xc),(byte *)0x0,local_2184);
            piVar2[3] = local_2170;
            piVar2[4] = local_216c;
            piVar2[5] = local_2168;
            piVar2[6] = local_2164;
          }
          this = local_21c0;
          local_21cc = events_startPlaybackLoop(local_21c0,iVar3);
          local_21c8 = events_startPlaybackLoop(this,local_21dc);
          iVar3 = local_21b0;
          if ((*(unsigned short *)((char *)&local_21b0 + 2)) != 0) {
            iVar4 = Ordinal_294(*(int *)((int)this + 0x20),*(int *)((int)this + 0x28),local_21b0,
                                0x2e,local_219c);
            if (iVar4 != 0) {
              local_21d0 = local_219c[0];
            }
            iVar3 = Ordinal_294(*(int *)((int)this + 0x20),*(int *)((int)this + 0x28),iVar3,0x3b,
                                local_219c);
            if (iVar3 != 0) {
              local_21c4 = local_219c[0];
            }
          }
          local_21ac = *(uint *)(*local_21bc + 0xc64);
          uVar5 = *(undefined4 *)(*local_21bc + 0xc5c);
          local_21c0 = (void *)0x0;
          local_21b0 = 0;
          iVar3 = Ordinal_1062(piVar2 + 7);
          if (iVar3 == 0) {
            piVar2[3] = piVar2[7];
            piVar2[4] = piVar2[8];
            piVar2[5] = piVar2[9];
            piVar2[6] = piVar2[10];
          }
          local_2194 = piVar2[3];
          local_2190 = piVar2[4];
          local_218c = piVar2[5];
          local_2188 = piVar2[6];
          if (param_4 != 0) {
            local_21ac = local_21ac | 1;
          }
          if (local_21cc != 0) {
            local_21ac = local_21ac & 0xffffffbd;
            uVar5 = 0;
          }
          if (local_21c8 != 0) {
            local_21ac = local_21ac | 0x2000;
          }
          if ((local_21ac & 0xc000) != 0) {
            local_2194 = piVar2[0xb];
            local_2190 = piVar2[0xc];
            local_218c = piVar2[0xd];
            local_2188 = piVar2[0xe];
          }
          if (*(int *)(*(int *)(local_21b8[2] + 0xc) + 0x10c) == 0) {
            param_1 = Ordinal_1810(piVar2[0x314],uVar5,piVar2 + 0x14,&local_2194,local_21e0,
                                   local_21ac,1);
            if (local_21cc != 0) {
              Ordinal_1809(param_1,local_21cc);
            }
            if (local_21c8 != 0) {
              Ordinal_18881(param_1,local_21c8);
            }
            if ((local_21d0 != 0) && (local_21c4 != 0)) {
              Ordinal_1867(param_1,local_21c4,local_21d0);
              Ordinal_1880(param_1,local_21ac & 0x1000,(int)piVar2 + 0x84e);
            }
            Ordinal_1884(param_1,(short)piVar2[0x31b]);
LAB_6806a41c:
            if (param_1 == 0) goto LAB_6806a424;
          }
          else {
            local_21b0 = 1;
            if (param_1 == 0) {
              if ((int *)piVar2[0x11] != (int *)0x0) {
                iVar3 = *(int *)piVar2[0x11];
                local_21e4 = *(int *)(iVar3 + 0x14);
                local_21e0 = *(int *)(iVar3 + 0x18);
                props_toPascalString(&local_21e4,local_908);
                Ordinal_1232(&local_508,local_908);
              }
              param_1 = (**(code **)(*(int *)(local_21b8[2] + 0xc) + 0x10c))
                                  (4,piVar2 + 0x314,uVar5,&local_508,piVar2 + 0x14,
                                   (int)piVar2 + 0x44f,&local_2194,0,&local_21ac,1,piVar2[0x10]);
              piVar2[0x319] = local_21ac;
              if ((local_21ac & 4) != 0) {
                local_21c0 = (void *)0x1;
              }
              if ((local_21d0 != 0) && (local_21c4 != 0)) {
                Ordinal_1867(param_1,local_21c4,local_21d0);
              }
              goto LAB_6806a41c;
            }
          }
          iVar3 = Ordinal_372(*(int *)(piVar2[0x10] + 0xc),(byte *)0x0,3,local_21a8);
          if ((iVar3 != 0) &&
             (local_21e0 = Ordinal_366(*(int *)(piVar2[0x10] + 0xc),local_21a8[0],(int *)0x8),
             local_21e0 != 0)) {
            Ordinal_1836(param_1,local_21e0);
            Ordinal_1733(&local_21e0);
          }
          if (param_4 != 0) {
            events_createLifecycle(local_21bc);
          }
          if ((((*(byte *)(local_21b8[2] + 0x1c) & 2) == 0) && (local_21c0 == (void *)0x0)) &&
             ((*piVar2 == 0 || ((DAT_681962ec == 0 || (local_21b0 == 0)))))) {
            Ordinal_2218(param_1,piVar2 + 3);
          }
          events_releaseLifecycle(param_4,0);
          if (local_21c0 == (void *)0x0) {
            if (((*piVar2 == 0) || (DAT_681962ec == 0)) || (local_21b0 == 0)) {
              Ordinal_50(*(int *)(piVar2[0x10] + 0xc),piVar2 + 3,0);
            }
            if (local_21ec == 0) goto LAB_6806a5a0;
            events_processHitTestResult(local_21d4,local_21bc,1);
          }
          else {
LAB_6806a5a0:
            events_configureWindow();
          }
          if ((param_4 != 0) && (piVar2[0x325] == 0)) {
            events_getMovieWindowRef();
            piVar2 = local_21d8;
          }
        }
        if ((local_21b4 != 0) && (local_21e8 != 0)) {
          local_21d8 = (int *)0x0;
          Ordinal_104(*(int *)(piVar2[0x10] + 0xc),0x3000);
          Ordinal_90(piVar2[0x10],&local_21d8,(undefined1 *)0x0,0);
        }
        goto LAB_6806a612;
      }
      local_21b0 = 0;
      local_21ac = Ordinal_1886();
      Ordinal_92((int *)piVar2[0x10],1);
      Ordinal_1309(local_d20,0x400,(int)piVar2 + 0x44f,2);
      pcVar1 = *(code **)(*(int *)(*(int *)(piVar2[0x10] + 8) + 0xc) + 0x24);
      if (((pcVar1 != (code *)0x0) &&
          (iVar3 = (*pcVar1)(local_d20,local_d20,&local_21b0,0,0), iVar3 != 0)) ||
         (iVar3 = scoreEngine_setPropertyEx(*(int *)((int)local_21c0 + 0x20),local_d20,0x15,1,1), iVar3 != 0)) {
        Ordinal_1310(local_d20,(int)piVar2 + 0x44f,0x3ff);
        iVar3 = Ordinal_88((int *)piVar2[0x10],local_d20,local_21b0,&local_21f0,(undefined1 *)0x0,0,
                           1,(void *)0x0);
        local_21b4 = (uint)(iVar3 != 0);
        if (local_21b4 != 0) {
          local_21e8 = 1;
          if (piVar2[0x10] != 0) {
            Ordinal_47(*(int *)(piVar2[0x10] + 0xc),1);
          }
          events_runMoviePlayback((int)piVar2);
          if ((local_21ac == 0) && ((*(byte *)(piVar2 + 0x319) & 0x40) == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = 1;
          }
          Ordinal_87((int *)piVar2[0x10],iVar3);
          if (piVar2[0x314] == 4) {
            local_21ec = 1;
          }
          piVar2[0x322] = 1;
          iVar3 = local_21dc;
          goto LAB_6806a0c0;
        }
      }
    }
  }
LAB_6806a424:
  iVar3 = Ordinal_120((undefined4 *)*local_21b8,local_108,0x100);
  if (((iVar3 != 0) && (Ordinal_1233(&local_508,local_108), local_507 != '\0')) && (iVar3 != -0x1c9)
     ) {
    sprites_getPlatformInfo(local_21d4,(int)&local_508);
  }
  crt_removeBehavior(local_21d4,(int *)piVar2[0x11]);
  piVar2[0x321] = 1;
  local_21b4 = 0;
LAB_6806a612:
  Ordinal_1115(local_21bc);
  if (local_21cc != 0) {
    Ordinal_1671(&local_21cc);
  }
  if (local_21c8 != 0) {
    Ordinal_1671(&local_21c8);
  }
  if (local_21d0 != 0) {
    Ordinal_1733(&local_21d0);
  }
  if (local_21c4 != 0) {
    Ordinal_1653(&local_21c4);
  }
  return 0;
}




