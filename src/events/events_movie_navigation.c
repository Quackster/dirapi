// Module: events
// Topic: Movie loading, navigation, file operations, and score line management
// Address range: 0x68061150 - 0x680630b0
// Functions (35):
//   events_loadSpriteScripts
//   events_updateMovieNav
//   events_computeSpriteTransform
//   events_querySpriteCapability
//   events_switchChannel
//   events_loadChannelSprites
//   Ordinal_101
//   events_handleSoundChange
//   events_processMovieLoop
//   events_updateNavigation
//   events_loadMovieFromPath
//   events_navigateToMovieFrame
//   events_closeCurrentMovie
//   events_destroyMovieContext
//   events_shutdownMovie
//   events_restoreMovieState
//   events_initMoviePlayback
//   events_openMovieChannel
//   events_handleMovieTransition
//   events_getMoviePauseState
//   events_setMoviePauseState
//   events_getMovieLoopMode
//   events_setMovieLoopMode
//   events_navigateMovie
//   events_handleStageResize
//   events_syncChannelState
//   events_getPlaybackSpeed
//   events_setPlaybackSpeed
//   events_getPlaybackState
//   events_navigateToFrameEx
//   events_navigateToFrame
//   events_getChannelBounds
//   events_setChannelBounds
//   events_resetPlaybackTimers
//   events_getChannelDataRef

// ============================================================
// Function: events_loadSpriteScripts (events_loadSpriteScripts)
// Address: 68061150
// Size: 320 bytes
// Params: int param_1, int param_2, undefined4 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_loadSpriteScripts(int param_1,int param_2,undefined4 *param_3,int param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_34;
  int local_30;
  int *local_2c;
  undefined4 local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0xc);
  local_24 = param_4;
  if (param_3 == (undefined4 *)0x0) {
    local_20 = (int *)Ordinal_482(*(int *)(param_1 + 0x20),param_2);
  }
  else {
    local_20 = (int *)*param_3;
  }
  local_30 = Ordinal_488(local_20,param_4);
  if (local_30 < 1) {
    return 0;
  }
  local_1c = (int *)cast_resetAndSort(iVar1);
  piVar2 = (int *)lingo_getGlobalRef(*(int *)(*(int *)(param_1 + 0x20) + 8));
  local_2c = piVar2;
  if ((piVar2 != (int *)0x0) && (iVar5 = 0, 0 < local_30)) {
    do {
      local_28 = 0;
      iVar3 = lingo_writeSpriteBlock(local_20,local_24,iVar5,&local_28,local_18);
      if ((iVar3 != 0) &&
         (((iVar3 = media_findSpriteEntry(piVar2,local_18), 0 < iVar3 &&
           (iVar3 = mediaPlayback_getSlotValue(piVar2,iVar3,&local_34), iVar3 == 0)) &&
          (piVar4 = cast_createXtraProperty(iVar1,local_34,local_28,local_24), piVar2 = local_2c,
          piVar4 != (int *)0x0)))) {
        cast_setContextEntry(iVar1,local_1c,piVar4);
        *(int *)(*piVar4 + 4) = *(int *)(*piVar4 + 4) + -1;
        iVar3 = cast_findXtraPropertyRef(iVar1,local_1c,iVar5);
        piVar2 = local_2c;
        if (iVar3 != 0) {
          lingo_readSpriteBlock(local_20,local_24,iVar5,*(int **)(iVar3 + 8));
          piVar2 = local_2c;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < local_30);
  }
  return 0;
}



// ============================================================
// Function: events_updateMovieNav (FUN_68061290)
// Address: 68061290
// Size: 23 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_updateMovieNav(int param_1,int *param_2)
{
  cast_releaseObject(*(undefined4 *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: events_computeSpriteTransform (events_computeSpriteTransform)
// Address: 680612b0
// Size: 503 bytes
// Params: int param_1, int * param_2, undefined4 param_3, int param_4, int param_5, int param_6, int param_7, int param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_computeSpriteTransform(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)
{
  undefined4 uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_5c;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  local_4c = param_5;
  bVar2 = false;
  local_44 = param_7;
  local_5c = param_7;
  local_50 = param_4;
  local_48 = param_6;
  iVar7 = param_6;
  iVar5 = param_5;
  iVar6 = param_4;
  if ((param_2 != (int *)0x0) && (uVar3 = props_getListLength(uVar1,param_2), uVar3 != 0)) {
    cast_retainObject(uVar1,param_2);
    local_40 = 0;
    if (uVar3 != 0) {
      do {
        iVar4 = cast_findXtraPropertyRef(uVar1,param_2,local_40);
        if (((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) && (*(int **)(iVar4 + 8) != (int *)0x0)) {
          local_30 = param_3;
          local_18 = local_50;
          local_1c = param_3;
          local_14 = local_4c;
          local_10 = local_48;
          local_c = local_44;
          local_20 = local_5c;
          bVar2 = true;
          local_2c = iVar6;
          local_28 = iVar5;
          local_24 = iVar7;
          iVar5 = media_invokeXtraMethod(*(int **)(iVar4 + 8),&local_1c,&local_30);
          local_5c = local_20;
          iVar7 = local_24;
          if (iVar5 != 0) {
            local_2c = local_18;
            local_28 = local_14;
            local_5c = local_c;
            iVar7 = local_10;
          }
          local_44 = local_c;
          local_48 = local_10;
          iVar5 = param_6 - param_4;
          local_50 = local_18;
          local_4c = local_14;
          if (iVar5 < 0) {
            iVar5 = -iVar5;
          }
          iVar6 = iVar7 - local_2c;
          if (iVar6 < 0) {
            iVar6 = -iVar6;
          }
          if ((local_5c - local_28 < param_7 - param_5) || (iVar6 < iVar5)) {
            local_5c = local_c;
            iVar7 = local_10;
            iVar5 = local_14;
            iVar6 = local_18;
          }
          else {
            local_50 = local_2c;
            local_4c = local_28;
            iVar5 = local_28;
            iVar6 = local_2c;
            local_48 = iVar7;
            local_44 = local_5c;
          }
        }
        local_40 = local_40 + 1;
      } while (local_40 < uVar3);
    }
    cast_releaseObject(uVar1,param_2);
  }
  *(int *)(param_8 + 4) = iVar6;
  *(int *)(param_8 + 8) = iVar5;
  *(int *)(param_8 + 0xc) = iVar7;
  *(int *)(param_8 + 0x10) = local_5c;
  if (bVar2) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: events_querySpriteCapability (events_querySpriteCapability)
// Address: 680614b0
// Size: 148 bytes
// Params: int param_1, int * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_querySpriteCapability(int param_1,int *param_2,uint *param_3)
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (((param_1 != 0) && (uVar1 = *(undefined4 *)(param_1 + 0xc), param_2 != (int *)0x0)) &&
     (uVar2 = props_getListLength(uVar1,param_2), uVar2 != 0)) {
    cast_retainObject(uVar1,param_2);
    uVar4 = 0;
    if (uVar2 != 0) {
      while (((iVar3 = cast_findXtraPropertyRef(uVar1,param_2,uVar4), iVar3 == 0 || (*(int *)(iVar3 + 4) == 0))
             || ((*(int **)(iVar3 + 8) == (int *)0x0 ||
                 ((iVar3 = media_invokeXtraNotify(*(int **)(iVar3 + 8),param_3), iVar3 == 0 ||
                  ((*param_3 & 1) == 0))))))) {
        uVar4 = uVar4 + 1;
        if (uVar2 <= uVar4) {
          cast_releaseObject(uVar1,param_2);
          return 0;
        }
      }
      *param_3 = *param_3 | 0x40;
    }
    cast_releaseObject(uVar1,param_2);
  }
  return 0;
}



// ============================================================
// Function: events_switchChannel (events_switchChannel)
// Address: 68061550
// Size: 86 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_switchChannel(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = param_1[10];
  iVar2 = param_1[9];
  param_1[9] = param_2;
  iVar4 = scoreEngine_accessProperty(param_1[8],param_2);
  param_1[10] = iVar4;
  iVar4 = param_1[3];
  uVar3 = *(undefined4 *)(iVar4 + 8);
  *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0xc);
  if (param_1[0x5f] != 0) {
    stage_notifySpriteIdle(param_1);
  }
  param_1[9] = iVar2;
  param_1[10] = iVar1;
  *(undefined4 *)(param_1[3] + 8) = uVar3;
  return 0;
}



// ============================================================
// Function: events_loadChannelSprites (events_loadChannelSprites)
// Address: 680615b0
// Size: 523 bytes
// Params: int param_1, void * param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_loadChannelSprites(int param_1,void *param_2,int param_3,int param_4,int param_5)
{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  int local_c;
  undefined4 *local_8;
  
  pvVar1 = *(void **)(param_1 + 0xc);
  local_14 = 0;
  iVar2 = scoreEngine_getPropertyRange(*(int *)(param_1 + 0x20),(int)param_2);
  if (iVar2 != 0) {
    local_1c = *(undefined4 *)(param_1 + 0x24);
    local_20 = *(undefined4 *)(param_1 + 0x28);
    local_14 = 1;
    *(void **)(param_1 + 0x24) = param_2;
    uVar3 = scoreEngine_accessProperty(*(int *)(param_1 + 0x20),(int)param_2);
    *(undefined4 *)(param_1 + 0x28) = uVar3;
    iVar2 = *(int *)(param_1 + 0xc);
    local_24 = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0xc);
  }
  local_8 = (undefined4 *)Ordinal_165(*(int *)(param_1 + 0x20),(int)param_2,&local_28);
  events_removeSpriteSlot(param_1,(int)param_2,param_3,0,param_5);
  if ((param_5 != 0) && (*(int *)(param_1 + 0x17c) != 0)) {
    piVar4 = (int *)Ordinal_482(*(int *)(param_1 + 0x20),(int)param_2);
    local_c = Ordinal_430(piVar4,param_4);
    if (local_c == 0) {
      *(undefined4 *)(param_3 * 0x34 + (int)local_8) = 0;
      *(undefined4 *)(param_3 * 0x34 + 0xc + (int)local_8) = 0;
    }
    else {
      piVar5 = (int *)cast_resetAndCountRects((int)pvVar1);
      if (piVar5 != (int *)0x0) {
        local_8 = (undefined4 *)(param_3 * 0x34 + (int)local_8);
        local_10 = piVar5;
        uVar3 = Ordinal_433(piVar4,param_4);
        local_8[1] = uVar3;
        uVar3 = Ordinal_434(piVar4,param_4);
        local_8[2] = uVar3;
        *local_8 = piVar5;
        crt_getScriptProperty((int)pvVar1,piVar5);
        cast_retainObject(pvVar1,piVar5);
        param_5 = 0;
        if (0 < local_c) {
          do {
            Ordinal_431(piVar4,param_4,param_5,(short *)local_30);
            piVar5 = (int *)events_resolveCastScript(param_2,local_30[0],param_3);
            if (piVar5 != (int *)0x0) {
              local_18 = (undefined4 *)Ordinal_432(piVar4,param_4,param_5);
              if (local_18 != (undefined4 *)0x0) {
                props_parseSymbolTable(pvVar1,piVar5,local_18);
                Ordinal_1113(&local_18);
              }
              cast_setContextEntry((int)pvVar1,local_10,piVar5);
              cast_releaseObject(pvVar1,piVar5);
            }
            param_5 = param_5 + 1;
            piVar5 = local_10;
          } while (param_5 < local_c);
        }
        uVar6 = events_collectHandlerFlags(piVar5);
        local_8[3] = uVar6;
        uVar3 = *(undefined4 *)(param_1 + 0x1c4);
        *(undefined4 *)(param_1 + 0x1c4) = 1;
        events_processDispatch(param_1,piVar5,0x1b,param_3);
        *(undefined4 *)(param_1 + 0x1c4) = uVar3;
        cast_releaseObject(pvVar1,piVar5);
      }
    }
  }
  if (local_14 != 0) {
    *(undefined4 *)(param_1 + 0x24) = local_1c;
    *(undefined4 *)(param_1 + 0x28) = local_20;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = local_24;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_101
// Address: 680617c0
// Size: 203 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_101(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
                    /* 0x617c0  101   */
  if (DAT_681962d0 == (int *)0x0) {
    return 0;
  }
  if ((((param_3 != -1) && (param_3 != 0)) && (*(int *)(param_3 + 0x20) != 0)) &&
     (iVar1 = *(int *)(*(int *)(param_3 + 0x20) + 8), iVar1 != 0)) {
    iVar2 = cast_getMemberData(*(undefined4 *)(iVar1 + 0xc),DAT_681962d0);
    if (param_1 + 1 <= iVar2) {
      Ordinal_1130(&local_408,0x400);
      cast_getMemberDataAlt(*(int *)(iVar1 + 0xc),DAT_681962d0,param_1 + 1,&local_408);
      Ordinal_1309(param_2,0x400,local_407,2);
      return 0;
    }
  }
  return 0;
}




// ============================================================
// Function: events_handleSoundChange (events_handleSoundChange)
// Address: 68061890
// Size: 392 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_handleSoundChange(int param_1,undefined4 param_2)

{
  int local_18;
  int iVar1;
  bool bVar2;
  bool bVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  
  iVar4 = Ordinal_58(unaff_ESI[8],(byte *)0x0);
  if ((0 < in_EAX) && (in_EAX == iVar4)) {
    unaff_ESI[0x1ca] = 1;
  }
  iVar1 = unaff_ESI[10];
  iVar5 = scoreEngine_setPropertyAccess(unaff_ESI[8]);
  if (iVar1 == iVar5) {
    bVar3 = false;
    bVar2 = true;
    if (unaff_ESI[0x1cd] != 0) {
      if (in_EAX == iVar4) {
        bVar2 = false;
      }
      else if (in_EAX == iVar4 + 1) {
        sprites_executeSpriteOp(unaff_ESI[3]);
        bVar2 = false;
      }
      else {
        sprites_finalizeSpriteOps(unaff_ESI[3]);
        bVar3 = true;
      }
    }
    events_removeOutOfRangeSlots((int)unaff_ESI,unaff_ESI[10],in_EAX);
    if (bVar2) {
      if (param_1 != 0) {
        lingo_readPlaybackMember(unaff_ESI[8],in_EAX);
        events_notifyFocusChange(unaff_ESI);
      }
      Ordinal_75(unaff_ESI[8],(byte *)unaff_ESI[10],in_EAX);
      iVar4 = Ordinal_143(unaff_ESI[8],(byte *)unaff_ESI[10]);
      if (iVar4 == 0) {
        unaff_ESI[0x1c9] = 1;
      }
      events_setMiawStageDepth((int)unaff_ESI,param_2);
      if (param_1 != 0) {
        if ((int *)unaff_ESI[0x1c7] != (int *)0x0) {
          cast_wrapApiCall(unaff_ESI[3],(int *)unaff_ESI[0x1c7],0x36);
        }
        sprites_handleEditCommand((int)unaff_ESI,0xc);
      }
    }
    if (bVar3) {
      sprites_initSpriteOp(unaff_ESI[3]);
    }
  }
  else {
    events_removeOutOfRangeSlots((int)unaff_ESI,iVar1,in_EAX);
    lingo_mutateMember(unaff_ESI[8],(byte *)unaff_ESI[10],in_EAX);
  }
  Ordinal_108(unaff_ESI[8],0x13,(undefined4 *)0x0);
  unaff_ESI[0x6d] = 1;
  if (unaff_ESI[0x1e] != 1) {
    sprites_setCursorVisible((int)unaff_ESI,0);
  }
  if (-1 < unaff_ESI[0x18]) {
    Ordinal_48(unaff_ESI[8],unaff_ESI[10]);
    Ordinal_1903();
    scoreEngine_dispatchExitFrame(unaff_ESI[8],unaff_ESI[10]);
    Ordinal_1042();
  }
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x68] = 0;
  unaff_ESI[0x18] = -2;
  return 1;
}



// ============================================================
// Function: events_processMovieLoop (events_processMovieLoop)
// Address: 68061a20
// Size: 386 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int events_processMovieLoop(int *param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  uint uVar5;
  undefined4 local_147c [272];
  int local_103c;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  Ordinal_1130(&local_14,0xc);
  local_14 = 1;
  local_10 = 4;
  Ordinal_1763(&local_14,0);
  sprites_initTextState((int *)*unaff_ESI);
  iVar1 = *(int *)(*unaff_ESI + 0x20);
  uVar2 = lingo_destroyLifecycle(iVar1);
  uVar5 = uVar2 & 0xfffffffe;
  iVar3 = Ordinal_56(iVar1,(byte *)0x0,local_147c);
  if ((iVar3 != 0) && (0 < local_103c)) {
    uVar5 = uVar2 & 0xfffffffc;
  }
  events_processMovieEvent(*unaff_ESI);
  iVar3 = score_loadMovie(iVar1,param_1,param_2,(void *)(uVar5 | 0x20));
  iVar4 = Ordinal_118(iVar1);
  *unaff_ESI = iVar4;
  events_handleWindowResize(iVar4);
  events_requestMovieAction(*unaff_ESI);
  iVar4 = media_getDataPtr(*(int **)(**(int **)(*(int *)*unaff_ESI + 4) + 0x14));
  if (*(code **)(iVar4 + 0x20) != (code *)0x0) {
    (**(code **)(iVar4 + 0x20))(*(undefined4 *)(*(int *)(*(int *)*unaff_ESI + 8) + 0x24));
  }
  lingo_resetCastOrdinal(iVar1);
  if ((iVar3 == 1) != 0) {
    Ordinal_136(*(int *)(*unaff_ESI + 0x20),1);
    Ordinal_51(*(int *)(*unaff_ESI + 0x20),(int)local_18);
    events_postMovieNotify(*unaff_ESI,*(undefined4 *)(*unaff_ESI + 0x1d0));
    Ordinal_1763(*unaff_ESI + 0x1e8,0);
    *(uint *)(*unaff_ESI + 0x1b0) = (uint)(iVar3 == 1);
    *(undefined4 *)(*unaff_ESI + 0x738) = 0;
    return 0;
  }
  Ordinal_1130(&local_14,0xc);
  local_14 = 1;
  local_10 = 1;
  Ordinal_1763(&local_14,0);
  return 0;
}



// ============================================================
// Function: events_updateNavigation (events_updateNavigation)
// Address: 68061bb0
// Size: 62 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_updateNavigation(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  iVar2 = media_getDataPtr(*(int **)(**(int **)(*piVar1 + 4) + 0x14));
  if (*(code **)(iVar2 + 0x3c) != (code *)0x0) {
    uVar3 = (**(code **)(iVar2 + 0x3c))(piVar1[8]);
    return uVar3;
  }
  return 1;
}



// ============================================================
// Function: events_loadMovieFromPath (events_loadMovieFromPath)
// Address: 68061bf0
// Size: 586 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall events_loadMovieFromPath(void *this,int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_EDI;
  undefined1 local_608 [1024];
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  uint local_8;
  
  puVar1 = *(undefined4 **)(**(int **)(*unaff_EDI + 8) + 0x51c);
  iVar2 = (*(int **)(*unaff_EDI + 8))[1];
  iVar3 = Ordinal_1306();
  if (iVar3 == 2) {
    Ordinal_1305(0);
  }
  iVar4 = scoreEngine_setPropertyEx(*(int *)(iVar2 + 0x20),this,0x15,(uint)(puVar1[0x196] == 0),
                       (uint)(puVar1[0x196] == 0));
  if (iVar4 == 0) {
    if (puVar1[0x196] == 0) goto LAB_68061e12;
    Ordinal_1310(this,local_608,0x3ff);
    iVar4 = sprites_launchExternalApp(*unaff_EDI,99,(int)local_608,0,0x15f);
    if (iVar4 != 0) goto LAB_68061e12;
  }
  iVar4 = events_updateNavigation(*unaff_EDI);
  if (iVar4 != 0) {
    Ordinal_1128((int *)(iVar2 + 0x1fc),this,0x418);
    events_handleIdleEvent(iVar2);
    if (*(int *)(iVar2 + 0x734) != 0) {
      Ordinal_414(*(int *)(iVar2 + 0x734));
      Ordinal_409((int *)(iVar2 + 0x734));
    }
    iVar4 = *(int *)(iVar2 + 0x20);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {
      if (*(int **)(iVar4 + 0x20) == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = **(int **)(iVar4 + 0x20);
      }
      media_clearXtraSlot(*(int *)(iVar4 + 8),iVar5);
    }
    events_processMovieLoop((int *)(iVar2 + 0x1fc),param_1);
    *unaff_EDI = *(int *)(iVar2 + 0xc);
    iVar4 = Ordinal_120((undefined4 *)*puVar1,local_108,0x100);
    if (iVar4 == 0) {
      if (*(int *)(iVar2 + 0x1b0) != 0) goto LAB_68061e12;
      Ordinal_1517(DAT_681956e0,0xffffff8e,local_208,0x100);
      Ordinal_1310(iVar2 + 0x1fc,local_608,0x3ff);
      Ordinal_1219(local_108,local_208,local_608);
    }
    iVar4 = Ordinal_1201(local_108);
    if (iVar4 != 0) {
      events_resetMiawState(*unaff_EDI,local_108,(undefined1 *)0x0,2,1,1,1,0);
    }
    score_saveMovie(*(int *)(iVar2 + 0x20));
  }
LAB_68061e12:
  if (iVar3 == 2) {
    Ordinal_1305(2);
  }
  return 0;
}



// ============================================================
// Function: events_navigateToMovieFrame (FUN_68061e40)
// Address: 68061e40
// Size: 729 bytes
// Params: int param_1, uint param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_navigateToMovieFrame(int param_1,uint param_2,int param_3,int param_4)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  byte *pbVar8;
  int *piVar9;
  bool bVar10;
  int local_52c;
  int local_528;
  int local_524;
  undefined1 local_520 [1048];
  byte local_108 [256];
  uint local_8;
  
  local_52c = 0;
  piVar9 = (int *)(*(int **)(param_1 + 8))[1];
  local_524 = param_3;
  local_528 = param_4;
  if (((piVar9 == (int *)0x0) || (piVar9[0x71] != 0)) ||
     (*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 100) != 0)) goto LAB_68062101;
  iVar2 = Ordinal_58(piVar9[8],(byte *)piVar9[10]);
  iVar3 = Ordinal_1546();
  if (local_524 != 0) {
    Ordinal_1130(local_520,0x418);
    if ((piVar9[10] != 0) && (piVar4 = (int *)Ordinal_118(piVar9[8]), piVar4 != piVar9))
    goto LAB_68062101;
    events_removeAllSpriteSlots((int)piVar9,piVar9[10]);
    if (piVar9[8] == *(int *)(*piVar9 + 0x648)) {
      lingo_getMiscState(piVar9[8]);
    }
    events_resetPuppetSprites((int)piVar9,piVar9[10]);
    Ordinal_1309(local_520,0x400,local_524 + 1,2);
    if (*(code **)(DAT_681962f8 + 0x24) != (code *)0x0) {
      (**(code **)(DAT_681962f8 + 0x24))(local_520,local_520,&local_52c,0,1);
    }
    iVar5 = events_loadMovieFromPath(local_520,local_52c);
    piVar9 = *(int **)(*(int *)(param_1 + 8) + 4);
    iVar6 = media_applyPixelOp(DAT_681962f8,1,local_108,0x100);
    if (iVar6 == 0) {
      pbVar8 = local_108;
      pcVar7 = "Plugin";
      do {
        bVar1 = *pcVar7;
        bVar10 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_68061fd8:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_68061fdd;
        }
        if (bVar1 == 0) break;
        bVar1 = pcVar7[1];
        bVar10 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_68061fd8;
        pcVar7 = pcVar7 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_68061fdd:
      if (iVar6 == 0) {
        Ordinal_47(piVar9[8],1);
      }
    }
    param_4 = local_528;
    if (iVar5 == 0) goto LAB_68062101;
  }
  if ((param_2 & 2) == 0) {
    iVar5 = Ordinal_154(piVar9[8],(byte *)piVar9[10]);
    if ((iVar5 < local_528) && (iVar5 + 8000 < local_528)) {
      param_4 = iVar5 + 8000;
    }
  }
  else {
    param_4 = Ordinal_603(piVar9[8],piVar9[10],param_4 + 1);
    if (param_4 < 1) goto LAB_68062015;
  }
  iVar5 = local_524;
  if (((param_2 >> 0xf & 1) != 0) || (iVar6 = events_handleSoundChange((uint)(local_524 != 0),0), iVar6 != 0)) {
    if (((iVar5 == 0) || (piVar9[0x1c8] != 0)) || (piVar9[0x77] != 0)) {
      iVar5 = piVar9[0x77];
      piVar9[0x77] = 0;
      events_handleKeyEventWrapper();
      piVar9[0x77] = iVar5;
      iVar5 = local_524;
    }
    if ((iVar5 != 0) || (iVar2 != param_4)) {
      iVar2 = Ordinal_1546();
      if (300 < iVar2 - iVar3) {
        iVar2 = *(int *)(*(int *)(piVar9[0xb] + 8) + 0x14);
        stage_handleEvent(iVar2,1);
        stage_handleEvent(iVar2,4);
        stage_handleEvent(iVar2,3);
        stage_handleEvent(iVar2,2);
        stage_handleEvent(iVar2,9);
      }
      if (iVar5 != 0) {
        lingo_enterScriptMode(piVar9[8],1);
      }
    }
LAB_68062101:
    return 0;
  }
LAB_68062015:
  return 0;
}




// ============================================================
// Function: events_closeCurrentMovie (events_closeCurrentMovie)
// Address: 68062120
// Size: 676 bytes
// Params: int param_1, int param_2, int param_3, short param_4, undefined4 * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_closeCurrentMovie(int param_1,int param_2,int param_3,short param_4,undefined4 *param_5,
                 undefined4 *param_6)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  undefined4 local_828;
  int local_820 [262];
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar5 = (*(int **)(param_1 + 8))[1];
  puVar1 = *(undefined4 **)(**(int **)(param_1 + 8) + 0x51c);
  local_828 = 0;
  bVar9 = false;
  if (iVar5 == 0) goto LAB_68062389;
  if ((param_5 == (undefined4 *)0x0) || ((undefined4 *)*param_5 == (undefined4 *)0x0)) {
    Ordinal_1130(local_820,0x418);
    Ordinal_1309(local_820,0x400,param_2 + 1,2);
    iVar4 = Ordinal_1306();
    bVar9 = iVar4 == 2;
    if (bVar9) {
      Ordinal_1305(0);
    }
    iVar4 = scoreEngine_setPropertyEx(*(int *)(iVar5 + 0x20),local_820,0x15,0,0);
    if (iVar4 == 0) goto LAB_68062389;
  }
  else {
    piVar7 = *(int **)*param_5;
    piVar8 = local_820;
    for (iVar4 = 0x106; piVar7 = piVar7 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar8 = *piVar7;
      piVar8 = piVar8 + 1;
    }
  }
  if (param_5 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*param_5;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)Ordinal_1111(0x41c,1);
      if (puVar2 != (undefined4 *)0x0) {
        *(undefined4 *)*puVar2 = *puVar1;
        piVar7 = (int *)*puVar2;
        piVar8 = local_820;
        for (iVar5 = 0x106; piVar7 = piVar7 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar7 = *piVar8;
          piVar8 = piVar8 + 1;
        }
        *param_5 = puVar2;
      }
      goto LAB_68062389;
    }
    uVar3 = lingo_destroyLifecycle(*(int *)(iVar5 + 0x20));
    if (param_3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = param_3 + 1;
    }
    iVar4 = Ordinal_137(*(int *)(iVar5 + 0x20),local_820,0,0,0,1,(void *)(uVar3 | 1),iVar4,
                        (int)param_4);
    piVar7 = (int *)*puVar2;
    piVar8 = local_820;
    for (iVar6 = 0x106; piVar7 = piVar7 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar7 = *piVar8;
      piVar8 = piVar8 + 1;
    }
    if (iVar4 != 1) {
      if (iVar4 != 2) {
        local_828 = 1;
        Ordinal_120((undefined4 *)*puVar1,(undefined1 *)0x0,0);
      }
      goto LAB_68062389;
    }
  }
  Ordinal_1310(local_820,local_407,0x3fe);
  iVar4 = Ordinal_1201(local_407);
  local_407[iVar4] = 0;
  iVar4 = Ordinal_1201(local_407);
  if (iVar4 < 0xff) {
    local_408 = Ordinal_1201(local_407);
  }
  else {
    local_408 = 0xff;
  }
  events_navigateToMovieFrame(*(int *)(iVar5 + 0xc),0x8000,(int)&local_408,0);
  Ordinal_1113(param_5);
  local_828 = 1;
LAB_68062389:
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_828;
  }
  if (bVar9) {
    Ordinal_1305(2);
  }
  return 0;
}



// ============================================================
// Function: events_destroyMovieContext (events_destroyMovieContext)
// Address: 680623d0
// Size: 50 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_destroyMovieContext(undefined4 param_1,int *param_2)

{
  int param_4;
  int *piVar1;
  
  piVar1 = (int *)*param_2;
  *param_2 = 0;
  if (piVar1 != (int *)0x0) {
    param_2 = piVar1;
    lingo_compileScript(*(undefined4 **)*piVar1,(int)((undefined4 *)*piVar1 + 1));
    Ordinal_1113(&param_2);
  }
  return 0;
}



// ============================================================
// Function: events_shutdownMovie (events_shutdownMovie)
// Address: 68062410
// Size: 173 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int events_shutdownMovie(int param_1,undefined1 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_146c [10];
  undefined1 local_1444 [1048];
  int local_102c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = 0;
  if (iVar1 != 0) {
    Ordinal_56(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),local_146c);
    if ((local_102c != 0) && (*(code **)(DAT_681962f8 + 0x2c) != (code *)0x0)) {
      (**(code **)(DAT_681962f8 + 0x2c))(local_1444);
    }
    Ordinal_1310(local_1444,param_2 + 1,0x3ff);
    iVar2 = Ordinal_1201(param_2 + 1);
  }
  param_2[iVar2 + 1] = 0;
  if (iVar2 < 0xff) {
    *param_2 = (char)iVar2;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: events_restoreMovieState (events_restoreMovieState)
// Address: 680624c0
// Size: 173 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int events_restoreMovieState(int param_1,undefined1 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_146c [10];
  undefined1 local_1444 [1048];
  int local_102c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = 0;
  if (iVar1 != 0) {
    Ordinal_56(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),local_146c);
    if ((local_102c != 0) && (*(code **)(DAT_681962f8 + 0x2c) != (code *)0x0)) {
      (**(code **)(DAT_681962f8 + 0x2c))(local_1444);
    }
    Ordinal_1314(local_1444,param_2 + 1,0x3ff);
    iVar2 = Ordinal_1201(param_2 + 1);
  }
  param_2[iVar2 + 1] = 0;
  if (iVar2 < 0xff) {
    *param_2 = (char)iVar2;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: events_initMoviePlayback (events_initMoviePlayback)
// Address: 68062570
// Size: 242 bytes
// Params: int param_1, undefined2 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int events_initMoviePlayback(int param_1,undefined2 *param_2)
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 local_1470;
  undefined4 local_146c [10];
  undefined1 local_1444 [5180];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar4 = 0;
  if (iVar2 != 0) {
    Ordinal_56(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28),local_146c);
    iVar4 = Ordinal_1316(local_1444);
    if (iVar4 == 0) {
      *param_2 = 0;
      return 0;
    }
    iVar1 = (int)param_2 + 1;
    scoreEngine_accessPropertyEx(*(int *)(iVar2 + 0x20),local_1444,iVar1,0x3ff,&local_1470);
    iVar4 = Ordinal_1201(iVar1);
    if (iVar4 - 1U < 0x3fd) {
      uVar3 = Ordinal_1321(local_1470);
      *(undefined1 *)(iVar1 + iVar4) = uVar3;
      iVar4 = iVar4 + 1;
      *(undefined1 *)(iVar1 + iVar4) = 0;
    }
  }
  *(undefined1 *)((int)param_2 + iVar4 + 1) = 0;
  if (0xfe < iVar4) {
    *(undefined1 *)param_2 = 0xff;
    return 0;
  }
  *(char *)param_2 = (char)iVar4;
  return 0;
}



// ============================================================
// Function: events_openMovieChannel (events_openMovieChannel)
// Address: 68062670
// Size: 388 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_openMovieChannel(int param_1,undefined1 *param_2)
{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_820 [1048];
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar4 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  puVar1 = param_2 + 1;
  *puVar1 = 0;
  *param_2 = 0;
  iVar3 = sprites_getStageRef(param_1);
  if (iVar3 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  iVar4 = Ordinal_1320(local_820,*(undefined4 *)(**(int **)(iVar4 + 4) + 8));
  if (iVar4 != 0) {
    iVar4 = Ordinal_1316(local_820);
    if (iVar4 != 0) {
      iVar4 = Ordinal_1310(local_820,puVar1,0x3ff);
      if (iVar4 != 0) {
        iVar4 = Ordinal_1201(puVar1);
        param_2[iVar4 + 1] = 0;
        iVar4 = Ordinal_1201(puVar1);
        if (iVar4 < 0xff) {
          uVar2 = Ordinal_1201(puVar1);
          *param_2 = uVar2;
        }
        else {
          *param_2 = 0xff;
        }
        local_407[0] = Ordinal_1321(2);
        local_407[1] = 0;
        iVar4 = Ordinal_1201(local_407);
        local_407[iVar4] = 0;
        iVar4 = Ordinal_1201(local_407);
        if (iVar4 < 0xff) {
          local_408 = Ordinal_1201(local_407);
        }
        else {
          local_408 = 0xff;
        }
        Ordinal_1231(param_2,&local_408);
        iVar4 = Ordinal_1201(puVar1);
        param_2[iVar4 + 1] = 0;
        iVar4 = Ordinal_1201(puVar1);
        if (iVar4 < 0xff) {
          uVar2 = Ordinal_1201(puVar1);
          *param_2 = uVar2;
          return 0;
        }
        *param_2 = 0xff;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: events_handleMovieTransition (events_handleMovieTransition)
// Address: 68062800
// Size: 224 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleMovieTransition(int param_1,undefined1 *param_2)
{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_420 [1048];
  uint local_8;
  
  iVar4 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  puVar1 = param_2 + 1;
  *puVar1 = 0;
  *param_2 = 0;
  iVar3 = sprites_getStageRef(param_1);
  if (iVar3 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  iVar4 = Ordinal_1320(local_420,*(undefined4 *)(**(int **)(iVar4 + 4) + 8));
  if (iVar4 != 0) {
    iVar4 = Ordinal_1314(local_420,puVar1,0x3ff);
    if (iVar4 != 0) {
      iVar4 = Ordinal_1201(puVar1);
      param_2[iVar4 + 1] = 0;
      iVar4 = Ordinal_1201(puVar1);
      if (iVar4 < 0xff) {
        uVar2 = Ordinal_1201(puVar1);
        *param_2 = uVar2;
        return 0;
      }
      *param_2 = 0xff;
    }
  }
  return 0;
}



// ============================================================
// Function: events_getMoviePauseState (events_getMoviePauseState)
// Address: 680628e0
// Size: 27 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMoviePauseState(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 8) + 0x24);
}



// ============================================================
// Function: events_setMoviePauseState (events_setMoviePauseState)
// Address: 68062900
// Size: 37 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMoviePauseState(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_setPropertyInt(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,param_3);
  return 0;
}



// ============================================================
// Function: events_getMovieLoopMode (events_getMovieLoopMode)
// Address: 68062930
// Size: 46 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMovieLoopMode(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_getPropertyInt(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,param_3);
  return 0;
}




// ============================================================
// Function: events_setMovieLoopMode (events_setMovieLoopMode)
// Address: 68062960
// Size: 34 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMovieLoopMode(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_603(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2 + 1);
  return 0;
}



// ============================================================
// Function: events_navigateMovie (FUN_68062990)
// Address: 68062990
// Size: 156 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_navigateMovie(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  int *local_8;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_58(*(int *)(iVar3 + 0x20),*(byte **)(iVar3 + 0x28));
  iVar2 = Ordinal_601(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),(undefined2 *)&param_1,&local_8,
                      &local_c);
  if ((iVar2 != 0) && ((short)param_1 != 0)) {
    iVar3 = Ordinal_605(*(undefined4 **)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),iVar1);
    iVar2 = (int)(short)param_1;
    if ((iVar2 < iVar3) || (*(short *)(*local_8 + -4 + iVar3 * 4) != iVar1)) {
      iVar3 = iVar3 + -1;
    }
    iVar3 = param_2 + iVar3;
    if (iVar3 < 1) {
      iVar3 = 1;
    }
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
    return (int)*(short *)(*local_8 + -4 + iVar3 * 4);
  }
  return 1;
}



// ============================================================
// Function: events_handleStageResize (events_handleStageResize)
// Address: 68062a30
// Size: 375 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleStageResize(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_420;
  int local_41c;
  int local_418;
  int local_414;
  short local_410 [2];
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_414 = iVar2;
  Ordinal_601(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),local_410,&local_420,&local_418);
  if (local_418 == 0) {
    local_40c = (int *)Ordinal_1111(1,0);
    *(undefined1 *)*local_40c = 0;
    return 0;
  }
  iVar3 = (int)local_410[0];
  local_41c = iVar3;
  iVar1 = Ordinal_1116(local_418,0);
  local_40c = (int *)Ordinal_1111(iVar1 + 1 + iVar3);
  if (local_40c != (int *)0x0) {
    iVar4 = 0;
    iVar1 = 0;
    if (0 < iVar3) {
      do {
        iVar1 = iVar1 + 1;
        Ordinal_604(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),iVar1,local_408,0x3fe);
        iVar2 = Ordinal_1201(local_408);
        iVar3 = Ordinal_1205(local_408,0xd);
        if (iVar3 != 0) {
          iVar2 = iVar3 - (int)local_408;
        }
        Ordinal_1129(*local_40c + iVar4,local_408,iVar2);
        *(undefined1 *)(iVar4 + iVar2 + *local_40c) = 0xd;
        iVar4 = iVar4 + iVar2 + 1;
        iVar2 = local_414;
      } while (iVar1 < local_41c);
    }
    *(undefined1 *)(iVar4 + *local_40c) = 0;
    Ordinal_1117(&local_40c,iVar4 + 1,0);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: events_syncChannelState (events_syncChannelState)
// Address: 68062bc0
// Size: 452 bytes
// Params: int param_1, uint * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_syncChannelState(int param_1,uint *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int local_42c [2];
  uint local_424;
  int local_420;
  uint local_41c;
  undefined4 local_418;
  int local_414;
  undefined4 local_410;
  uint local_40c;
  char local_408 [1024];
  uint local_8;
  
  local_410 = 0;
  local_418 = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_41c = score_dispatchProplist(param_1);
  param_2[1] = local_41c;
  *param_2 = -(uint)(local_41c != 0) & 3;
  local_424 = 4;
  if (param_3 == 0) {
    local_40c = Ordinal_610(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
    local_40c = local_40c & 0xffff;
    iVar2 = Ordinal_601(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined2 *)&local_40c,
                        &local_410,&local_418);
  }
  else {
    local_40c = media_acquireLock(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
    local_40c = local_40c & 0xffff;
    iVar2 = media_dispatchAssetEvent(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined2 *)&local_40c,
                         &local_410,&local_418);
  }
  if ((iVar2 != 0) && (local_414 = Ordinal_1114(local_410), local_414 != 0)) {
    iVar2 = 0;
    if (0 < (short)local_40c) {
      do {
        if (param_3 == 0) {
          Ordinal_604(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),iVar2 + 1,local_408,0x3fe);
        }
        else {
          media_dispatchScoredEvent(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),
                       (int)*(short *)(local_414 + iVar2 * 4),(int)local_408,0x3fe);
        }
        local_420 = (int)*(short *)(local_414 + iVar2 * 4);
        if (0 < local_420) {
          props_loadCString(param_1,local_408,local_42c);
          score_setPropertyValue(param_1,local_41c,&local_424,local_42c,1);
          props_releaseAndClear(param_1,local_42c);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (short)local_40c);
    }
  }
  Ordinal_1115(local_410);
  return 0;
}



// ============================================================
// Function: events_getPlaybackSpeed (events_getPlaybackSpeed)
// Address: 68062d90
// Size: 76 bytes
// Params: int param_1, int param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getPlaybackSpeed(int param_1,int param_2,undefined1 *param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = media_dispatchScoredEvent(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,(int)(param_3 + 1),
                       0x3fd);
  if (iVar1 == -1) {
    iVar1 = 0;
  }
  param_3[iVar1 + 1] = 0;
  if (iVar1 < 0xff) {
    *param_3 = (char)iVar1;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: events_setPlaybackSpeed (events_setPlaybackSpeed)
// Address: 68062de0
// Size: 106 bytes
// Params: int param_1, int param_2, byte * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setPlaybackSpeed(int param_1,int param_2,byte *param_3)

{
  int iVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  piVar3 = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24));
  iVar4 = Ordinal_403(piVar3);
  if (iVar4 != 0) {
    if (*param_3 == 0xff) {
      uVar2 = Ordinal_1201(param_3 + 1);
    }
    else {
      uVar2 = (ushort)*param_3;
    }
    media_dispatchChannelRender(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),param_2,(int)(param_3 + 1),
                 (int)(short)uVar2);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: events_getPlaybackState (events_getPlaybackState)
// Address: 68062e50
// Size: 37 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getPlaybackState(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_getPropertyStr(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,param_3);
  return 0;
}



// ============================================================
// Function: events_navigateToFrameEx (FUN_68062e80)
// Address: 68062e80
// Size: 78 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_navigateToFrameEx(int param_1)

{
  int iVar1;
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
  local_1c = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 == 0) {
    return 0;
  }
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),2,(double *)&local_1c);
  return (int)(short)local_1c;
}



// ============================================================
// Function: events_navigateToFrame (FUN_68062ed0)
// Address: 68062ed0
// Size: 71 bytes
// Params: int param_1, ushort param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint events_navigateToFrame(int param_1,ushort param_2)

{
  int iVar1;
  uint local_1c [6];
  
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_1c[3] = 0;
  local_1c[4] = 0;
  local_1c[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c[0] = (uint)param_2;
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),6,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_getChannelBounds (events_getChannelBounds)
// Address: 68062f20
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getChannelBounds(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  piVar2 = (int *)lingo_executeScriptOp(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  crt_getFileEndOffset(piVar2);
  return 0;
}



// ============================================================
// Function: events_setChannelBounds (events_setChannelBounds)
// Address: 68062f50
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelBounds(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  piVar2 = (int *)lingo_executeScriptOp(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  crt_getJunkTotalSize(piVar2);
  return 0;
}



// ============================================================
// Function: events_resetPlaybackTimers (events_resetPlaybackTimers)
// Address: 68062f80
// Size: 298 bytes
// Params: int param_1, int param_2, int param_3, undefined1 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resetPlaybackTimers(int param_1,int param_2,int param_3,undefined1 *param_4)
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 local_838;
  undefined1 local_834 [1044];
  undefined4 local_420;
  undefined1 local_41c [1044];
  uint local_8;
  
  local_838 = 0;
  memset(local_834,0,0x414);
  local_420 = 0;
  memset(local_41c,0,0x414);
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  puVar1 = param_4 + 1;
  *puVar1 = 0;
  *param_4 = 0;
  Ordinal_1309(&local_420,0x400,param_2 + 1,2);
  scoreEngine_setPropertyEx(*(int *)(iVar2 + 0x20),&local_420,1,0,0);
  iVar2 = Ordinal_1355(&local_838,&local_420,param_3 + -1);
  if (iVar2 != 0) {
    iVar2 = Ordinal_1314(&local_838,puVar1,0x3ff);
    if (iVar2 != 0) {
      iVar2 = Ordinal_1201(puVar1);
      param_4[iVar2 + 1] = 0;
      if (iVar2 < 0xff) {
        *param_4 = (char)iVar2;
        return 0;
      }
      *param_4 = 0xff;
      return 0;
    }
    *puVar1 = 0;
    *param_4 = 0;
  }
  return 0;
}



// ============================================================
// Function: events_getChannelDataRef (events_getChannelDataRef)
// Address: 680630b0
// Size: 103 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getChannelDataRef(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    Ordinal_1309(local_420,0x400,param_2 + 1,2);
    puVar2 = local_420;
  }
  Ordinal_121(*(int *)(iVar1 + 0x20),puVar2,1,(void *)0x0);
  return 0;
}




