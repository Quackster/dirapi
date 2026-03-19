// Module: events
// Topic: MIAW property setting, sprite channel data dispatch, Lingo property access
// Address range: 0x6806a690 - 0x6806ffa0
// Functions (84):
//   events_setWindowRect
//   events_dispatchWindowAction
//   events_configureProjector
//   events_handleWindowDispatch
//   events_handleWindowEvent
//   events_getMiawProperty
//   events_setMiawProperty
//   events_getMiawTitle
//   events_setMiawTitle
//   events_getMiawRect
//   events_setMiawRect
//   events_getMiawDrawRect
//   events_setMiawDrawRect
//   events_getMiawVisible
//   events_setMiawVisible
//   events_processWindowEvent
//   events_getMiawModal
//   events_setMiawModal
//   events_getMiawFileName
//   events_setMiawFileName
//   events_getMiawWindowType
//   events_setMiawWindowType
//   events_getMiawTitleVisible
//   events_setMiawTitleVisible
//   events_getMiawSizeState
//   events_setMiawSizeState
//   events_getMiawPaletteRef
//   events_setMiawPaletteRef
//   events_getMiawSourceRect
//   events_setMiawSourceRect
//   events_getMiawName
//   events_setMiawName
//   events_getMiawMoviePath
//   events_setMiawMoviePath
//   events_openMiawMovie
//   events_closeMiawMovie
//   events_getMiawState
//   events_resetMiawState
//   events_getMiawBgColor
//   events_setMiawBgColor
//   events_getMiawRuntimeData
//   events_setMiawRuntimeData
//   events_getMiawPropertyList
//   events_setMiawPropertyList
//   events_getMiawExtendedProp
//   events_setMiawExtendedProp
//   events_resolveMiawPath
//   events_handleMiawNavigation
//   events_getMiawScriptData
//   events_setMiawScriptData
//   events_getMiawChannelData
//   events_setMiawChannelData
//   events_getWindowData
//   events_setWindowData
//   events_getMiawMediaRef
//   events_setMiawMediaRef
//   events_getMiawSpriteRef
//   events_setMiawSpriteRef
//   events_getMiawCursorRef
//   events_setMiawCursorRef
//   events_getMiawSoundRef
//   events_setMiawSoundRef
//   events_getMiawTimerRef
//   events_setMiawTimerRef
//   events_getWindowProperty
//   events_getMiawVideoRef
//   events_setMiawVideoRef
//   events_getMiawNetRef
//   events_setMiawNetRef
//   events_getMiawRenderRef
//   events_setMiawRenderRef
//   events_getMiawXtraRef
//   events_setMiawXtraRef
//   events_setWindowProperty
//   events_getMiawActiveFlag
//   events_setMiawActiveFlag
//   events_getMiawDisplayMode
//   events_setMiawDisplayMode
//   events_getMiawStageInfo
//   events_getWindowInfo
//   events_configureMiawStage
//   events_getMiawStageColor
//   events_setMiawStageColor
//   events_getMiawStageDepth
//   events_setMiawStageDepth
//   events_resetMiawChannel
//   events_getMiawStageRect
//   events_setMiawStageRect

// ============================================================
// Function: events_setWindowRect (FUN_6806a690)
// Address: 6806a690
// Size: 571 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowRect(int param_1,int param_2,int param_3,int param_4)
{
  bool bVar1;
  int *in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  bVar1 = false;
  piVar2 = (int *)Ordinal_1114();
  iVar3 = events_checkWindowActive(piVar2[1]);
  if (iVar3 != 0) goto LAB_6806a87c;
  iVar3 = events_processEvent((int *)*in_EAX);
  iVar4 = events_getEventState(piVar2[1]);
  if ((iVar3 == 0) ||
     ((iVar4 != 0 &&
      (((((*(byte *)(piVar2 + 0x319) & 4) != 0 || (DAT_681962ec != 0)) && (DAT_681962f0 == 0)) &&
       (param_4 == 0)))))) goto LAB_6806a87c;
  Ordinal_1833(iVar3,piVar2 + 7);
  iVar5 = Ordinal_1819(iVar3);
  iVar6 = events_handleWindowMessage(param_1,in_EAX);
  if (iVar6 == 0x216) {
    piVar2[0x319] = piVar2[0x319] | 0x4000;
LAB_6806a737:
    piVar2[0x319] = piVar2[0x319] & 0xffff7fff;
  }
  else {
    piVar2[0x319] = piVar2[0x319] & 0xffffbfff;
    if (iVar6 != 0x215) goto LAB_6806a737;
    piVar2[0x319] = piVar2[0x319] | 0x8000;
  }
  Ordinal_1881(iVar3,piVar2 + 0xb);
  events_getLifecycleRef(0);
  piVar2[0x325] = 1;
  if ((param_3 != 0) && (iVar4 != 0)) {
    if (piVar2[0x10] != 0) {
      iVar3 = Ordinal_118(*(int *)(piVar2[0x10] + 0xc));
      sprites_setCursorVisible(iVar3,1);
    }
    events_activateWindow(piVar2[1]);
    bVar1 = true;
  }
  events_invokeCallback(param_2,in_EAX,param_1,iVar5,1);
  if ((!bVar1) && (param_3 != 0)) {
    events_activateWindow(piVar2[1]);
  }
  piVar2[0x325] = 0;
  events_getLifecycleRef(1);
  if ((*piVar2 != 0) &&
     (iVar3 = *(int *)(*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 8) + 0xc),
     *(int *)(iVar3 + 0x28) != 0)) {
    uVar7 = events_processEvent((int *)*in_EAX);
    (**(code **)(iVar3 + 0x28))(uVar7);
  }
  if (iVar4 == 0) {
    iVar3 = Ordinal_1886();
    if (iVar3 != 0) {
      if (*piVar2 != 0) {
        uVar7 = events_processEvent((int *)*in_EAX);
        Ordinal_2215(uVar7);
      }
      goto LAB_6806a820;
    }
    if ((*(byte *)(piVar2 + 0x319) & 0x40) != 0) goto LAB_6806a820;
    iVar3 = 0;
  }
  else {
LAB_6806a820:
    iVar3 = 1;
  }
  Ordinal_87((int *)piVar2[0x10],iVar3);
  if ((((iVar5 != 0) || (param_3 == 0)) || ((*piVar2 != 0 && (iVar4 != 0)))) &&
     (iVar3 = *(int *)(*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 8) + 0xc),
     *(int *)(iVar3 + 300) != 0)) {
    uVar8 = 1;
    uVar7 = events_processEvent((int *)*in_EAX);
    (**(code **)(iVar3 + 300))(uVar7,uVar8);
  }
  Ordinal_1061(piVar2 + 7);
LAB_6806a87c:
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: events_dispatchWindowAction (events_dispatchWindowAction)
// Address: 6806a8d0
// Size: 217 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_dispatchWindowAction(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *local_8;
  
  local_8 = (int *)0x0;
  if (*(int *)(param_1 + 0x668) != 0) {
    uVar3 = 0;
    iVar1 = Ordinal_1154(*(int *)(param_1 + 0x668));
    if (iVar1 != 0) {
      while( true ) {
        local_8 = (int *)0x0;
        iVar1 = Ordinal_1155(*(undefined4 *)(param_1 + 0x668),uVar3,&local_8);
        if (((iVar1 != 0) && (local_8 != (int *)0x0)) && (param_2 == *(int *)(*local_8 + 0x40)))
        break;
        uVar3 = uVar3 + 1;
        uVar2 = Ordinal_1154(*(undefined4 *)(param_1 + 0x668));
        if (uVar2 <= uVar3) {
          return 0;
        }
      }
      Ordinal_1114(local_8);
      events_retainEvent();
      iVar1 = events_addRefEvent((int *)*local_8);
      iVar1 = Ordinal_118(iVar1);
      events_setWindowRect(*(int *)(iVar1 + 0xc),param_3,0,1);
      puVar5 = (undefined4 *)0x0;
      uVar4 = 5;
      iVar1 = events_addRefEvent((int *)*local_8);
      Ordinal_108(iVar1,uVar4,puVar5);
      Ordinal_1115(local_8);
      events_releaseEvent(local_8);
    }
  }
  return 0;
}



// ============================================================
// Function: events_configureProjector (events_configureProjector)
// Address: 6806a9b0
// Size: 737 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int events_configureProjector(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 local_1c84 [262];
  undefined4 local_186c;
  short local_1868;
  undefined4 local_1844 [776];
  undefined4 local_c24;
  undefined4 local_c20;
  undefined4 local_c1c;
  undefined4 local_c18;
  undefined4 local_c14;
  undefined4 local_c10;
  char local_c0c [1023];
  char local_80d [1029];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar5 = *(int *)(param_1 + 0x14);
  iVar4 = events_getEventState(*(int *)(**(int **)(iVar5 + 8) + 0x51c));
  piVar1 = *(int **)(**(int **)(iVar5 + 8) + 0x518);
  if ((piVar1 != (int *)0x0) &&
     (puVar2 = *(undefined4 **)(*piVar1 + 8), puVar2 != (undefined4 *)0x0)) {
    iVar5 = Ordinal_1114(puVar2);
    DAT_681962f0 = 1;
    if (param_2 == 0) {
      if (DAT_681962ec != 0) {
        *(undefined4 *)(iVar5 + 0xc54) = 0;
        *(undefined4 *)(iVar5 + 0xc58) = 0;
        *(undefined4 *)(iVar5 + 0xc60) = 0;
        uVar3 = DAT_6818e36c;
        *(uint *)(iVar5 + 0xc64) = DAT_6818e36c;
        if (param_4 != 0) {
          *(uint *)(iVar5 + 0xc64) = uVar3 | 1;
        }
        *(undefined4 *)(iVar5 + 0xc5c) = 0;
        *(undefined4 *)(iVar5 + 0xc50) = 1;
        iVar5 = events_addRefEvent((int *)*puVar2);
        iVar5 = Ordinal_118(iVar5);
        events_setWindowRect(*(int *)(iVar5 + 0xc),0,1,0);
        DAT_681962ec = 0;
      }
    }
    else if (DAT_681962ec == 0) {
      DAT_681962ec = 1;
      if (param_3 == 0) {
        iVar6 = events_createEventContext();
        if (iVar6 != 0) {
          puVar8 = &local_186c;
          pbVar10 = (byte *)0x0;
          iVar6 = events_createEventContext();
          Ordinal_56(iVar6,pbVar10,puVar8);
          puVar8 = &local_c18;
          iVar11 = 0;
          iVar6 = events_createEventContext();
          uVar7 = Ordinal_362(iVar6,iVar11,puVar8);
          *(undefined4 *)(iVar5 + 0xc54) = uVar7;
          puVar8 = &local_c14;
          iVar11 = 0;
          iVar6 = events_createEventContext();
          uVar7 = Ordinal_362(iVar6,iVar11,puVar8);
          puVar8 = &local_c10;
          *(undefined4 *)(iVar5 + 0xc58) = uVar7;
          iVar11 = 0;
          iVar6 = events_createEventContext();
          uVar7 = Ordinal_362(iVar6,iVar11,puVar8);
          *(undefined4 *)(iVar5 + 0xc60) = uVar7;
          *(undefined4 *)(iVar5 + 0xc64) = local_c24;
          *(undefined4 *)(iVar5 + 0xc5c) = local_c1c;
          *(undefined4 *)(iVar5 + 0xc50) = local_c20;
          if ((iVar4 == 0) && (0x73c < local_1868)) {
            if (local_c0c[0] == '\0') {
              puVar8 = local_1844;
              puVar9 = local_1c84;
              for (iVar4 = 0x106; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar9 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              }
              uVar7 = Ordinal_1378(local_1c84,local_1c84,local_408);
              Ordinal_1379(uVar7);
              Ordinal_1128(iVar5 + 0x50,local_408,0x3ff);
            }
            else {
              Ordinal_1232(iVar5 + 0x50,local_c0c);
            }
            if (local_80d[0] != '\0') {
              Ordinal_1232(iVar5 + 0x84e,local_80d);
            }
          }
          if ((*(int *)(iVar5 + 0xc50) != 1) && ((*(uint *)(iVar5 + 0xc64) & 4) != 0)) {
            *(uint *)(iVar5 + 0xc64) = *(uint *)(iVar5 + 0xc64) & 0xfffffffb;
          }
        }
      }
      else {
        *(undefined4 *)(iVar5 + 0xc54) = 0;
        *(undefined4 *)(iVar5 + 0xc58) = 0;
        *(undefined4 *)(iVar5 + 0xc64) = 0;
        *(undefined4 *)(iVar5 + 0xc5c) = 1;
        *(undefined4 *)(iVar5 + 0xc50) = 3;
      }
      iVar5 = events_addRefEvent((int *)*puVar2);
      iVar5 = Ordinal_118(iVar5);
      events_setWindowRect(*(int *)(iVar5 + 0xc),0,1,1);
    }
    DAT_681962f0 = 0;
  }
  return 0;
}



// ============================================================
// Function: events_handleWindowDispatch (events_handleWindowDispatch)
// Address: 6806aca0
// Size: 185 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleWindowDispatch(int param_1,int *param_2,int *param_3)
{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar4 = events_dispatchHandler(param_1,param_2);
  piVar2 = *(int **)(*(int *)(param_1 + 8) + 4);
  pcVar3 = *(code **)(**(int **)(*piVar2 + 4) + 0x1b4);
  iVar4 = events_invokeCallback(0,param_2,param_1,iVar4,0);
  if (iVar4 != 0) {
    piVar5 = (int *)Ordinal_1114(param_2);
    uVar6 = events_processEvent((int *)*param_2);
    piVar1 = piVar5 + 3;
    Ordinal_1833(uVar6,piVar1);
    if ((*piVar5 != 0) && (pcVar3 != (code *)0x0)) {
      (*pcVar3)(*(undefined4 *)(piVar2[0xb] + 0xc),uVar6,0,piVar1);
    }
    param_3[1] = *piVar1;
    *param_3 = piVar5[4];
    param_3[3] = piVar5[5];
    param_3[2] = piVar5[6];
    Ordinal_1115(param_2);
    return 0;
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[3] = 0;
  param_3[2] = 0;
  return 0;
}



// ============================================================
// Function: events_handleWindowEvent (FUN_6806ad60)
// Address: 6806ad60
// Size: 578 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleWindowEvent(int param_1,int *param_2,int param_3)
{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int local_20 [7];
  
  local_20[6] = events_dispatchHandler(param_1,param_2);
  piVar3 = (int *)Ordinal_1114(param_2);
  iVar8 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  uVar4 = lingo_destroyLifecycleData(*(int *)(*(int *)((*(int **)(param_1 + 8))[1] + 0x2c) + 8));
  if ((uVar4 & 1) == 0) {
    events_retainEvent();
    iVar6 = local_20[6];
    iVar5 = events_invokeCallback(0,param_2,param_1,local_20[6],0);
    if (iVar5 != 0) {
      iVar5 = events_processEvent((int *)*param_2);
      if (param_3 == 0) {
        if (iVar5 != 0) {
          events_getLifecycleRef(0);
          if ((((*(byte *)(piVar3 + 0x319) & 4) == 0) && (*piVar3 == 0)) ||
             (pcVar1 = *(code **)(*(int *)(*(int *)(iVar8 + 8) + 0xc) + 0x140),
             pcVar1 == (code *)0x0)) {
            Ordinal_1818(iVar5,0);
          }
          else {
            (*pcVar1)(iVar5);
          }
          *(undefined4 *)(*param_2 + 0xc7c) = 0;
          iVar5 = Ordinal_118(*(int *)(*(int *)(*param_2 + 0x40) + 0xc));
          *(undefined4 *)(iVar5 + 0x758) = 0;
          if (iVar6 != 0) {
            events_dispatchMovieEvent(0x12);
            if (((*(byte *)(piVar3 + 0x319) & 4) == 0) ||
               (*(int *)(*(int *)(*(int *)(iVar8 + 8) + 0xc) + 0x140) == 0)) {
              events_dispatchMovieEvent(0x13);
            }
          }
        }
      }
      else {
        if ((((*(byte *)(piVar3 + 0x319) & 4) == 0) && (*piVar3 == 0)) ||
           (*(int *)(*(int *)(*(int *)(iVar8 + 8) + 0xc) + 0x140) == 0)) {
          bVar2 = false;
          Ordinal_1818(iVar5,1);
        }
        else {
          bVar2 = true;
        }
        iVar6 = Ordinal_118(*(int *)(*(int *)(*param_2 + 0x40) + 0xc));
        *(undefined4 *)(iVar6 + 0x758) = 1;
        local_20[0] = 0;
        local_20[1] = 0;
        local_20[2] = 0;
        local_20[3] = 0;
        local_20[4] = 0;
        local_20[5] = 0;
        Ordinal_360(*(int **)(piVar3[0x10] + 0xc),(undefined4 ***)0x0,0x31,(double *)local_20);
        if ((9 < local_20[0]) && (*(int *)(*param_2 + 0xc78) == 0)) {
          events_finalizeSession();
        }
        if ((local_20[6] == 0) && (piVar3[0x325] == 0)) {
          events_getLifecycleRef(1);
          events_getMovieWindowRef();
        }
        uVar7 = events_processEvent((int *)*param_2);
        if (*(int *)(iVar8 + 0x67c) == 0) {
          Ordinal_1815(uVar7);
          events_createLifecycle(param_2);
        }
        if (bVar2) {
          (**(code **)(*(int *)(*(int *)(iVar8 + 8) + 0xc) + 0x144))(uVar7);
        }
        pcVar1 = *(code **)(*(int *)(*(int *)(iVar8 + 8) + 0xc) + 300);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)(uVar7,1);
        }
      }
      events_configureWindow();
      puVar9 = (undefined4 *)0x0;
      uVar7 = 5;
      iVar8 = events_addRefEvent((int *)*param_2);
      Ordinal_108(iVar8,uVar7,puVar9);
    }
    if (piVar3 != (int *)0x0) {
      Ordinal_1115(param_2);
    }
    events_releaseEvent(param_2);
  }
  return 0;
}




// ============================================================
// Function: events_getMiawProperty (events_getMiawProperty)
// Address: 6806afb0
// Size: 569 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawProperty(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_834;
  undefined1 local_830 [1048];
  int local_418 [4];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = Ordinal_1114(param_2);
  events_retainEvent();
  if (*(int *)(iVar1 + 0x48) < 2) {
    Ordinal_1232(local_408,param_3);
    Ordinal_1309(local_830,0x400,local_408,2);
    iVar2 = scoreEngine_setPropertyEx(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),local_830,0x15,0,0);
    Ordinal_1310(local_830,local_408,0x3ff);
    if ((iVar2 != 0) &&
       (((*(int *)(iVar1 + 0x40) == 0 ||
         (iVar2 = Ordinal_45(*(int *)(*(int *)(iVar1 + 0x40) + 0xc),(undefined4 *)0x0), iVar2 == 0))
        || (iVar2 = Ordinal_1254(iVar1 + 0x44f,local_408), iVar2 != 0)))) {
      local_834 = 0;
      iVar2 = events_processEvent((int *)*param_2);
      if (iVar2 != 0) {
        local_834 = Ordinal_1819(iVar2);
      }
      if (*(int *)(iVar1 + 0x40) != 0) {
        lingo_reloadScriptMedia(*(int *)(*(int *)(iVar1 + 0x40) + 0xc));
        *(undefined4 *)(iVar1 + 0xc78) = 0;
      }
      Ordinal_1232(iVar1 + 0x44f,param_3);
      if (iVar2 == 0) {
        events_invokeCallback(0,param_2,param_1,local_834,0);
      }
      else {
        Ordinal_1833(iVar2,local_418);
        events_releaseLifecycle(1,0);
        *(undefined4 *)(iVar1 + 0x4c) = 1;
        iVar3 = events_invokeCallback(0,param_2,param_1,local_834,0);
        if (iVar3 != 0) {
          *(undefined4 *)(iVar1 + 0x4c) = 0;
          events_releaseLifecycle(local_834,0);
          events_setWindowRect(param_1,0,1,0);
          if (*(int *)(iVar1 + 0x40) != 0) {
            Ordinal_50(*(int *)(*(int *)(iVar1 + 0x40) + 0xc),local_418,0);
          }
          Ordinal_1820(iVar2,0);
        }
      }
    }
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_setMiawProperty (events_setMiawProperty)
// Address: 6806b1f0
// Size: 209 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawProperty(int param_1,int *param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  piVar1 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  if (piVar1[0x322] == 0) {
    piVar1[0x324] = piVar1[0x324] | 1;
  }
  Ordinal_1232(piVar1 + 0x14,param_3);
  iVar2 = events_processEvent((int *)*param_2);
  if (iVar2 != 0) {
    Ordinal_1828(iVar2,param_3 + 1);
  }
  iVar2 = events_getEventState(piVar1[1]);
  if (((*piVar1 == 0) && (iVar2 != 0)) && ((*(byte *)(piVar1 + 0x319) & 4) != 0)) {
    iVar2 = events_dispatchHandler(param_1,param_2);
    events_setWindowRect(param_1,0,1,1);
    if (iVar2 != 0) {
      iVar3 = events_dispatchHandler(param_1,param_2);
      if (iVar3 == 0) {
        piVar1[0x325] = 1;
        events_handleWindowEvent(param_1,param_2,iVar2);
        piVar1[0x325] = 0;
      }
    }
  }
  puVar5 = (undefined4 *)0x0;
  uVar4 = 5;
  iVar2 = events_addRefEvent((int *)*param_2);
  Ordinal_108(iVar2,uVar4,puVar5);
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getMiawTitle (events_getMiawTitle)
// Address: 6806b2d0
// Size: 89 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawTitle(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = Ordinal_1114(param_2);
  events_retainEvent();
  if (*(int *)(iVar1 + 0xc88) == 0) {
    *(uint *)(iVar1 + 0xc90) = *(uint *)(iVar1 + 0xc90) | 0x40;
  }
  Ordinal_1232(iVar1 + 0x84e,param_3);
  events_setWindowRect(param_1,0,1,0);
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_setMiawTitle (events_setMiawTitle)
// Address: 6806b330
// Size: 46 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawTitle(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  events_setWindowRect(param_1,0,1,0);
  puVar3 = (undefined4 *)0x0;
  uVar2 = 5;
  iVar1 = events_addRefEvent((int *)*param_2);
  Ordinal_108(iVar1,uVar2,puVar3);
  return 0;
}



// ============================================================
// Function: events_getMiawRect (events_getMiawRect)
// Address: 6806b360
// Size: 323 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMiawRect(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_c;
  
  piVar2 = param_2;
  local_c = 1;
  piVar3 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar4 = events_getEventState(piVar3[1]);
  if (piVar3[0x322] == 0) {
    piVar3[0x324] = piVar3[0x324] | 0x20;
  }
  if ((((iVar4 == 0) || ((piVar3[0x319] & 4U) == 0)) || (*piVar3 == 0)) || (DAT_681962ec != 0)) {
    piVar1 = (int *)piVar3[0x314];
    if (param_3 == 0x217) {
      param_2 = (int *)0x1;
    }
    else if (param_3 == 0x218) {
      param_2 = (int *)0x2;
    }
    else {
      if (param_3 != 0x21a) {
        local_c = 0;
        goto LAB_6806b48b;
      }
      param_2 = (int *)0x4;
      if ((iVar4 == 0) || ((piVar3[0x319] & 4U) == 0)) {
        events_processHitTestResult(param_1,piVar2,1);
      }
    }
    if (piVar1 != param_2) {
      iVar4 = events_dispatchHandler(param_1,piVar2);
      if (piVar1 == (int *)0x4) {
        events_processHitTestResult(param_1,piVar2,0);
      }
      piVar3[0x314] = (int)param_2;
      events_setWindowRect(param_1,0,1,1);
      if ((iVar4 != 0) && (iVar5 = events_dispatchHandler(param_1,piVar2), iVar5 == 0)) {
        piVar3[0x325] = 1;
        events_handleWindowEvent(param_1,piVar2,iVar4);
        piVar3[0x325] = 0;
      }
    }
    puVar7 = (undefined4 *)0x0;
    uVar6 = 5;
    iVar4 = events_addRefEvent((int *)*piVar2);
    Ordinal_108(iVar4,uVar6,puVar7);
  }
LAB_6806b48b:
  Ordinal_1115(piVar2);
  events_releaseEvent(piVar2);
  return local_c;
}



// ============================================================
// Function: events_setMiawRect (events_setMiawRect)
// Address: 6806b4b0
// Size: 184 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawRect(int param_1,int *param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar2 = events_getEventState(piVar1[1]);
  if (piVar1[0x322] == 0) {
    piVar1[0x324] = piVar1[0x324] | 4;
  }
  if ((((iVar2 == 0) || ((piVar1[0x319] & 4U) == 0)) || (*piVar1 == 0)) || (DAT_681962ec != 0)) {
    iVar2 = sprites_getMemberCastType2(param_1,param_3);
    if ((iVar2 != 0) || (*(short *)((int)param_3 + 2) == 0)) {
      iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
      iVar2 = Ordinal_362(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3);
      piVar1[0x315] = iVar2;
      events_setWindowRect(param_1,0,1,0);
    }
    puVar4 = (undefined4 *)0x0;
    uVar3 = 5;
    iVar2 = events_addRefEvent((int *)*param_2);
    Ordinal_108(iVar2,uVar3,puVar4);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getMiawDrawRect (events_getMiawDrawRect)
// Address: 6806b570
// Size: 180 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMiawDrawRect(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar3 = 1;
  piVar1 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar2 = events_getEventState(piVar1[1]);
  if (piVar1[0x322] == 0) {
    piVar1[0x324] = piVar1[0x324] | 0x10;
  }
  if ((((iVar2 == 0) || ((piVar1[0x319] & 4U) == 0)) || (*piVar1 == 0)) || (DAT_681962ec != 0)) {
    if (param_3 == 0x23) {
      iVar2 = 1;
    }
    else {
      if (param_3 != 0x4a5) {
        uVar3 = 0;
        goto LAB_6806b60e;
      }
      iVar2 = 0;
    }
    if (piVar1[0x317] != iVar2) {
      piVar1[0x317] = iVar2;
      events_setWindowRect(param_1,0,1,0);
    }
    puVar5 = (undefined4 *)0x0;
    uVar4 = 5;
    iVar2 = events_addRefEvent((int *)*param_2);
    Ordinal_108(iVar2,uVar4,puVar5);
  }
LAB_6806b60e:
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return uVar3;
}



// ============================================================
// Function: events_setMiawDrawRect (events_setMiawDrawRect)
// Address: 6806b630
// Size: 304 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawDrawRect(int param_1,int *param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  piVar1 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar2 = events_getEventState(piVar1[1]);
  puVar4 = param_3;
  if (piVar1[0x322] == 0) {
    piVar1[0x324] = piVar1[0x324] | 2;
  }
  if ((((iVar2 == 0) || ((piVar1[0x319] & 4U) == 0)) || (*piVar1 == 0)) || (DAT_681962ec != 0)) {
    iVar3 = sprites_getMemberCastType2(param_1,param_3);
    if ((iVar3 != 0) || (*(short *)((int)puVar4 + 2) == 0)) {
      param_3 = (undefined4 *)piVar1[0x316];
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
      iVar3 = Ordinal_362(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),puVar4);
      piVar1[0x316] = iVar3;
      if (((*(unsigned short *)((char *)&param_3 + 2)) == 0) || (*(short *)((int)piVar1 + 0xc5a) == 0)) {
        events_setWindowRect(param_1,0,1,0);
      }
      else if (iVar2 == 0) {
        puVar4 = (undefined4 *)events_checkWindowActive(piVar1[1]);
        if (puVar4 == (undefined4 *)0x0) {
          param_3 = puVar4;
          param_3 = (undefined4 *)events_startPlaybackLoop(*(void **)(*(int *)(param_1 + 8) + 4),piVar1[0x316]);
          if (param_3 != (undefined4 *)0x0) {
            puVar4 = param_3;
            uVar5 = events_processEvent((int *)*param_2);
            Ordinal_1809(uVar5,puVar4);
            Ordinal_1671(&param_3);
          }
        }
      }
    }
    puVar4 = (undefined4 *)0x0;
    uVar5 = 5;
    iVar2 = events_addRefEvent((int *)*param_2);
    Ordinal_108(iVar2,uVar5,puVar4);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getMiawVisible (events_getMiawVisible)
// Address: 6806b760
// Size: 304 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawVisible(int param_1,int *param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  piVar1 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar2 = events_getEventState(piVar1[1]);
  puVar4 = param_3;
  if (piVar1[0x322] == 0) {
    piVar1[0x324] = piVar1[0x324] | 8;
  }
  if ((((iVar2 == 0) || ((piVar1[0x319] & 4U) == 0)) || (*piVar1 == 0)) || (DAT_681962ec != 0)) {
    iVar3 = sprites_getMemberCastType2(param_1,param_3);
    if ((iVar3 != 0) || (*(short *)((int)puVar4 + 2) == 0)) {
      param_3 = (undefined4 *)piVar1[0x318];
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
      iVar3 = Ordinal_362(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),puVar4);
      piVar1[0x318] = iVar3;
      if (((*(unsigned short *)((char *)&param_3 + 2)) == 0) || (*(short *)((int)piVar1 + 0xc62) == 0)) {
        events_setWindowRect(param_1,0,1,0);
      }
      else if (iVar2 == 0) {
        puVar4 = (undefined4 *)events_checkWindowActive(piVar1[1]);
        if (puVar4 == (undefined4 *)0x0) {
          param_3 = puVar4;
          param_3 = (undefined4 *)events_startPlaybackLoop(*(void **)(*(int *)(param_1 + 8) + 4),piVar1[0x318]);
          if (param_3 != (undefined4 *)0x0) {
            puVar4 = param_3;
            uVar5 = events_processEvent((int *)*param_2);
            Ordinal_18881(uVar5,puVar4);
            Ordinal_1671(&param_3);
          }
        }
      }
    }
    puVar4 = (undefined4 *)0x0;
    uVar5 = 5;
    iVar2 = events_addRefEvent((int *)*param_2);
    Ordinal_108(iVar2,uVar5,puVar4);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}




// ============================================================
// Function: events_setMiawVisible (events_setMiawVisible)
// Address: 6806b890
// Size: 216 bytes
// Params: int param_1, int * param_2, short param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawVisible(int param_1,int *param_2,short param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  piVar2 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar3 = events_getEventState(piVar2[1]);
  if ((((iVar3 == 0) || ((*(byte *)(piVar2 + 0x319) & 4) == 0)) || (*piVar2 == 0)) ||
     (DAT_681962ec != 0)) {
    iVar1 = piVar2[0x31b];
    if (param_3 < 0x100) {
      if (param_3 < 0) {
        param_3 = 0;
      }
    }
    else {
      param_3 = 0xff;
    }
    if ((short)iVar1 != param_3) {
      *(short *)(piVar2 + 0x31b) = param_3;
      if (((short)iVar1 == 0xff) || (param_3 == 0xff)) {
        events_setWindowRect(param_1,0,1,0);
      }
      else if (iVar3 == 0) {
        iVar3 = events_checkWindowActive(piVar2[1]);
        if (iVar3 == 0) {
          uVar5 = (uint)*(ushort *)(piVar2 + 0x31b);
          uVar4 = events_processEvent((int *)*param_2);
          Ordinal_1884(uVar4,uVar5);
        }
      }
    }
    puVar6 = (undefined4 *)0x0;
    uVar4 = 5;
    iVar3 = events_addRefEvent((int *)*param_2);
    Ordinal_108(iVar3,uVar4,puVar6);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 1;
}



// ============================================================
// Function: events_processWindowEvent (FUN_6806b970)
// Address: 6806b970
// Size: 296 bytes
// Params: int param_1, int * param_2, uint param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_processWindowEvent(int param_1,int *param_2,uint param_3,int param_4)
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  uint extraout_EDX;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  piVar2 = (int *)Ordinal_1114(param_2);
  events_retainEvent();
  iVar3 = events_getEventState(piVar2[1]);
  if (piVar2[0x322] == 0) {
    piVar2[0x323] = piVar2[0x323] | param_3;
  }
  if ((((iVar3 == 0) || ((piVar2[0x319] & 4U) == 0)) || (*piVar2 == 0)) || (DAT_681962ec != 0)) {
    bVar1 = events_checkPermission(param_1,param_2,param_3);
    if (CONCAT31(extraout_var,bVar1) != param_4) {
      if (param_4 == 0) {
        piVar2[0x319] = ~param_3 & extraout_EDX;
      }
      else {
        piVar2[0x319] = extraout_EDX | param_3;
      }
      if ((param_3 != 0x4000) && (param_3 != 0x8000)) {
        iVar3 = events_dispatchHandler(param_1,param_2);
        if ((param_3 == 4) || (param_3 == 2)) {
          iVar4 = 1;
        }
        else {
          iVar4 = 0;
        }
        events_setWindowRect(param_1,0,1,iVar4);
        if (iVar3 != 0) {
          iVar4 = events_dispatchHandler(param_1,param_2);
          if (iVar4 == 0) {
            piVar2[0x325] = 1;
            events_handleWindowEvent(param_1,param_2,iVar3);
            piVar2[0x325] = 0;
          }
        }
      }
    }
    puVar6 = (undefined4 *)0x0;
    uVar5 = 5;
    iVar3 = events_addRefEvent((int *)*param_2);
    Ordinal_108(iVar3,uVar5,puVar6);
  }
  Ordinal_1115(param_2);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_getMiawModal (events_getMiawModal)
// Address: 6806baa0
// Size: 171 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawModal(int param_1,int *param_2)
{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  events_retainEvent();
  iVar2 = events_invokeCallback(0,param_2,param_1,1,0);
  if (iVar2 != 0) {
    uVar3 = events_processEvent((int *)*param_2);
    iVar2 = events_dispatchHandler(param_1,param_2);
    if (iVar2 == 0) {
      Ordinal_1818(uVar3,1);
      *(undefined4 *)(*param_2 + 0xc7c) = 1;
      events_getLifecycleRef(1);
      events_getMovieWindowRef();
    }
    Ordinal_1815(uVar3);
    Ordinal_55(*(int *)(*(int *)(*param_2 + 0x40) + 0xc));
    events_createLifecycle(param_2);
    pcVar1 = *(code **)(*(int *)(*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 8) + 0xc) +
                       300);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(uVar3,1);
    }
  }
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_setMiawModal (events_setMiawModal)
// Address: 6806bb50
// Size: 186 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawModal(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  Ordinal_1130(param_3,0x10);
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 != 0) {
    iVar1 = Ordinal_189(*(int *)(*(int *)(*param_2 + 0x40) + 0xc),&local_18);
    if (iVar1 != 0) {
      *param_3 = local_14;
      param_3[1] = local_18;
      param_3[3] = local_10;
      param_3[2] = local_c;
    }
    if ((param_3[3] <= param_3[1]) || (param_3[2] <= *param_3)) {
      Ordinal_164(*(int *)(*(int *)(*param_2 + 0x40) + 0xc),&local_28);
      *param_3 = local_24;
      param_3[1] = local_28;
      param_3[3] = local_20;
      param_3[2] = local_1c;
    }
  }
  return 0;
}



// ============================================================
// Function: events_getMiawFileName (events_getMiawFileName)
// Address: 6806bc10
// Size: 90 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_getMiawFileName(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = events_invokeCallback(0,param_2,param_1,0,0);
  if (iVar1 != 0) {
    iVar1 = Ordinal_118(*(int *)(*(int *)(*param_2 + 0x40) + 0xc));
    if (iVar1 != 0) {
      events_retainEvent();
      if (*(int *)(*param_2 + 0xc78) == 0) {
        events_finalizeSession();
      }
      return iVar1 + 4;
    }
  }
  return 0;
}



// ============================================================
// Function: events_setMiawFileName (events_setMiawFileName)
// Address: 6806bc70
// Size: 162 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawFileName(int param_1,int *param_2,int param_3,undefined4 *param_4)
{
  uint uVar1;
  int iVar2;
  
  iVar2 = events_dispatchHandler(param_1,param_2);
  iVar2 = events_invokeCallback(0,param_2,param_1,iVar2,0);
  if ((iVar2 != 0) && (iVar2 = lingo_copyToClipboard(*(int *)(*(int *)(*param_2 + 0x40) + 0xc)), iVar2 != 0))
  {
    props_storeSymbolValue(param_1,iVar2,param_4);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: events_getMiawWindowType (events_getMiawWindowType)
// Address: 6806bd20
// Size: 67 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMiawWindowType(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 != 0) {
    uVar2 = lingo_destroyBitmapData(*(int *)(*(int *)(*param_2 + 0x40) + 0xc));
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_setMiawWindowType (events_setMiawWindowType)
// Address: 6806bd70
// Size: 66 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawWindowType(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 != 0) {
    uVar2 = Ordinal_70(*(int *)(*(int *)(*param_2 + 0x40) + 0xc));
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_getMiawTitleVisible (events_getMiawTitleVisible)
// Address: 6806bdc0
// Size: 71 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMiawTitleVisible(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 != 0) {
    uVar2 = lingo_mergeStageRegion(*(int *)(*(int *)(*param_2 + 0x40) + 0xc),param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_setMiawTitleVisible (events_setMiawTitleVisible)
// Address: 6806be10
// Size: 76 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawTitleVisible(int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 != 0) {
    uVar2 = Ordinal_184(*(int *)(*(int *)(*param_2 + 0x40) + 0xc),0,param_3,param_4);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: events_getMiawSizeState (events_getMiawSizeState)
// Address: 6806be60
// Size: 182 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawSizeState(int *param_1,int param_2,uint param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    iVar2 = events_getLifecycleState();
    if (param_2 == iVar2) {
      param_1 = (int *)piVar1[0x19b];
      if (param_1 != (int *)0x0) {
        events_processWindowEvent(piVar1[5],param_1,param_3,param_4);
        return 0;
      }
    }
    else {
      uVar4 = 0;
      iVar2 = Ordinal_1154(piVar1[0x19a]);
      if (iVar2 != 0) {
        while( true ) {
          param_1 = (int *)0x0;
          iVar2 = Ordinal_1155(piVar1[0x19a],uVar4,&param_1);
          if (((iVar2 != 0) && (param_1 != (int *)0x0)) &&
             (iVar2 = events_processEvent((int *)*param_1), iVar2 == param_2)) break;
          uVar4 = uVar4 + 1;
          uVar3 = Ordinal_1154(piVar1[0x19a]);
          if (uVar3 <= uVar4) {
            return 0;
          }
        }
        events_processWindowEvent(piVar1[5],param_1,param_3,param_4);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: events_setMiawSizeState (events_setMiawSizeState)
// Address: 6806bf20
// Size: 186 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawSizeState(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  undefined4 local_28 [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 == 0) {
    local_14 = 0;
    param_3[1] = 0;
    param_3[3] = 0;
    param_3[2] = 0;
  }
  else {
    iVar1 = Ordinal_184(*(int *)(*(int *)(*param_2 + 0x40) + 0xc),0,local_28,&local_18);
    if (iVar1 == 0) {
      events_setMiawModal(param_1,param_2,param_3);
      param_3[3] = param_3[3] - param_3[1];
      param_3[2] = param_3[2] - *param_3;
      *param_3 = 0;
      param_3[1] = 0;
      return 0;
    }
    param_3[1] = local_18;
    param_3[3] = local_10;
    param_3[2] = local_c;
  }
  *param_3 = local_14;
  return 0;
}




// ============================================================
// Function: events_getMiawPaletteRef (events_getMiawPaletteRef)
// Address: 6806bfe0
// Size: 208 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawPaletteRef(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = events_dispatchHandler(param_1,param_2);
  events_retainEvent();
  iVar1 = events_invokeCallback(0,param_2,param_1,iVar1,0);
  if (iVar1 != 0) {
    events_setMiawModal(param_1,param_2,&local_18);
    local_30 = local_c - local_14;
    local_2c = local_10 - local_18;
    local_28 = param_3[1];
    local_24 = *param_3;
    local_1c = param_3[2];
    local_20 = param_3[3];
    local_34 = 0;
    local_38 = 0;
    iVar1 = *(int *)(*(int *)(*param_2 + 0x40) + 0xc);
    Ordinal_183(iVar1,&local_38,&local_28);
    Ordinal_108(iVar1,0x21,(undefined4 *)0x0);
    Ordinal_104(iVar1,0x1000);
  }
  puVar3 = (undefined4 *)0x0;
  uVar2 = 5;
  iVar1 = events_addRefEvent((int *)*param_2);
  Ordinal_108(iVar1,uVar2,puVar3);
  events_releaseEvent(param_2);
  return 0;
}



// ============================================================
// Function: events_setMiawPaletteRef (events_setMiawPaletteRef)
// Address: 6806c0b0
// Size: 27 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawPaletteRef(int param_1)

{
  return *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x650);
}



// ============================================================
// Function: events_getMiawSourceRect (events_getMiawSourceRect)
// Address: 6806c0d0
// Size: 30 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawSourceRect(int param_1,undefined4 param_2)
{
  *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x650) = param_2;
  return 0;
}



// ============================================================
// Function: events_setMiawSourceRect (events_setMiawSourceRect)
// Address: 6806c0f0
// Size: 27 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawSourceRect(int param_1)

{
  return *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x654);
}



// ============================================================
// Function: events_getMiawName (events_getMiawName)
// Address: 6806c110
// Size: 30 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawName(int param_1,undefined4 param_2)
{
  *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x654) = param_2;
  return 0;
}



// ============================================================
// Function: events_setMiawName (events_setMiawName)
// Address: 6806c130
// Size: 72 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawName(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = cast_getHandlerOffset(param_1,param_2);
  param_1 = CONCAT22((short)uVar2,(short)((uint)uVar2 >> 0x10));
  uVar2 = Ordinal_297(*(int *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x28),param_1);
  *param_4 = uVar2;
  *param_5 = 1;
  return 0;
}



// ============================================================
// Function: events_getMiawMoviePath (events_getMiawMoviePath)
// Address: 6806c180
// Size: 85 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMiawMoviePath(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_4 = 0xffffffff;
  if (*(int *)(DAT_681962f8 + 0x80) != 0) {
    uVar1 = lingo_initLifecycle(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20));
    iVar2 = (**(code **)(DAT_681962f8 + 0x80))(uVar1,param_2,param_3,param_4);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: events_setMiawMoviePath (events_setMiawMoviePath)
// Address: 6806c1e0
// Size: 308 bytes
// Params: undefined4 * param_1, char * param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawMoviePath(undefined4 *param_1,char *param_2,byte param_3)
{
  undefined4 *puVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int local_24 [7];
  int local_8;
  
  puVar3 = param_1;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = 0;
  local_24[5] = 0;
  local_24[0] = 0;
  local_24[6] = *(int *)(param_1[2] + 4);
  uVar8 = 0;
  local_8 = 0;
  if ((param_3 & 1) == 0) {
    iVar5 = props_isSingleStep((int)param_1);
    if (iVar5 != 0) {
      uVar8 = 6;
      props_setSingleStep((int)puVar3,0);
      local_8 = 1;
    }
    uVar6 = Ordinal_1201(param_2);
    param_1 = (undefined4 *)Ordinal_1111(uVar6,0);
    Ordinal_1129(*param_1,param_2,uVar6);
    Ordinal_360(*(int **)(local_24[6] + 0x20),(undefined4 ***)0x0,5,(double *)local_24);
    piVar7 = (int *)cast_invokeHandlerEx(puVar3,local_24[0],param_1,uVar8,0);
    if (piVar7 != (int *)0x0) {
      cast_resolveHandler((int)puVar3,piVar7,0);
    }
    if (local_8 != 0) {
      props_setSingleStep((int)puVar3,1);
    }
  }
  else {
    if ((param_3 & 2) == 0) {
      pcVar4 = param_2;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      core_invokeAsyncScript((int)param_1,param_2,(int)pcVar4 - (int)(param_2 + 1),(int *)0x0);
      return 0;
    }
    puVar1 = param_1 + 0x2b;
    props_clearValue(param_1,puVar1);
    pcVar4 = param_2;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    core_invokeAsyncScript((int)puVar3,param_2,(int)pcVar4 - (int)(param_2 + 1),(int *)&param_1);
    if (param_1 != (undefined4 *)0x0) {
      props_getValuePair((int)puVar3,param_1,puVar1);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_openMiawMovie (events_openMiawMovie)
// Address: 6806c320
// Size: 127 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_openMiawMovie(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    if (param_2 != 0) {
      if (*(code **)(DAT_681962f8 + 0x8c) == (code *)0x0) {
        if ((param_3 == 0x33) || (*(int *)(param_1 + 0x7c) == 0x33)) {
          *(undefined4 *)(*(int *)(iVar1 + 0x2c) + 0x18) = 3;
          *(undefined2 *)(*(int *)(iVar1 + 0x2c) + 0x10) = 2;
        }
      }
      else {
        iVar2 = (**(code **)(DAT_681962f8 + 0x8c))(param_2,param_3);
        if (iVar2 == 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0x2c) + 0x18) = 2;
          *(undefined4 *)(iVar1 + 0x1b4) = 1;
          return 0;
        }
      }
    }
    *(undefined4 *)(iVar1 + 0x1b4) = 1;
  }
  return 0;
}



// ============================================================
// Function: events_closeMiawMovie (events_closeMiawMovie)
// Address: 6806c3a0
// Size: 21 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_closeMiawMovie(int *param_1,int param_2)
{
  scoreEngine_setPropertyHandler(param_1,(char *)(param_2 + 1));
  return 0;
}



// ============================================================
// Function: events_getMiawState (events_getMiawState)
// Address: 6806c3c0
// Size: 82 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawState(undefined4 param_1,undefined4 param_2)
{
  undefined1 local_108 [256];
  uint local_8;
  
  Ordinal_1213(local_108,0xff,param_1,param_2);
  if (*(code **)(DAT_681962f8 + 0x1c) != (code *)0x0) {
    (**(code **)(DAT_681962f8 + 0x1c))(local_108);
  }
  return 0;
}



// ============================================================
// Function: events_resetMiawState (events_resetMiawState)
// Address: 6806c420
// Size: 238 bytes
// Params: int param_1, undefined4 param_2, undefined1 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resetMiawState(int param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  int *piVar1;
  undefined1 local_120 [12];
  undefined4 local_114;
  undefined4 local_110;
  undefined1 local_108 [256];
  uint local_8;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  if (param_3 == (undefined1 *)0x0) {
    param_3 = local_108;
    Ordinal_1517(DAT_681956e0,0x57a,param_3,0x100);
  }
  Ordinal_1130(&local_114,0xc);
  local_114 = 1;
  local_110 = 1;
  Ordinal_1763(&local_114,local_120);
  Ordinal_1764(1);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(*piVar1 + 0x660) = 1;
  }
  Ordinal_1780(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(*piVar1 + 0x660) = 0;
  }
  Ordinal_1764(0);
  Ordinal_1763(local_120,0);
  if (piVar1 != (int *)0x0) {
    piVar1[0x5c] = 0;
  }
  return 0;
}



// ============================================================
// Function: events_getMiawBgColor (events_getMiawBgColor)
// Address: 6806c510
// Size: 32 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool events_getMiawBgColor(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x2c);
  return iVar1 == *(int *)(*(int *)(iVar1 + 8) + 0x18);
}



// ============================================================
// Function: events_setMiawBgColor (events_setMiawBgColor)
// Address: 6806c530
// Size: 8 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawBgColor(void)

{
  return 1;
}



// ============================================================
// Function: events_getMiawRuntimeData (events_getMiawRuntimeData)
// Address: 6806c540
// Size: 102 bytes
// Params: undefined4 param_1, undefined2 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMiawRuntimeData(undefined4 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  undefined4 extraout_EDX;
  float10 fVar2;
  ulonglong uVar3;
  undefined2 in_stack_0000000a;
  undefined1 local_10 [8];
  int local_8;
  
  fVar2 = (float10)Ordinal_1521(CONCAT26(in_stack_0000000a,CONCAT24(param_2,param_1)),local_10);
  local_8 = (int)ROUND((float10)65536.0 * fVar2);
  uVar1 = (undefined2)local_8;
  uVar3 = strings_floatToUint64(CONCAT22(extraout_var,(undefined2)local_8),extraout_EDX);
  return CONCAT22((short)uVar3,uVar1);
}



// ============================================================
// Function: events_setMiawRuntimeData (events_setMiawRuntimeData)
// Address: 6806c5b0
// Size: 42 bytes
// Params: double * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawRuntimeData(double *param_1)
{
  ushort *in_EAX;
  
  *param_1 = (double)(int)(short)in_EAX[1] + (double)*in_EAX * 1.52587890625e-05;
  return 0;
}




// ============================================================
// Function: events_getMiawPropertyList (events_getMiawPropertyList)
// Address: 6806c5e0
// Size: 1001 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawPropertyList(int param_1,undefined4 param_2)
{
  int iVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int unaff_EBX;
  uint *unaff_EDI;
  undefined4 uVar5;
  undefined4 local_50 [2];
  undefined8 local_48;
  uint local_40;
  uint local_3c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(unaff_EBX + 8) + 4);
  *unaff_EDI = 0;
  if ((param_1 < 1) || (iVar1 == 0)) goto switchD_6806c61d_caseD_6;
  switch(param_2) {
  case 1:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,4,(double *)&local_48);
    *unaff_EDI = (uint)local_48 & 0xff;
    return 0;
  case 2:
    uVar5 = 8;
    goto LAB_6806c7d2;
  case 3:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0xb,(double *)&local_48);
    *unaff_EDI = local_3c;
    return 0;
  case 4:
    uVar5 = 2;
    goto LAB_6806c655;
  case 5:
    uVar3 = events_copyCastMember(iVar1,*(int *)(iVar1 + 0x28),param_1,2);
    *unaff_EDI = uVar3;
    return 0;
  default:
    goto switchD_6806c61d_caseD_6;
  case 7:
    uVar5 = 9;
LAB_6806c7d2:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,uVar5,(double *)&local_48);
    if ((*(unsigned char *)((char *)&local_48 + 3)) != '\0') {
      Ordinal_72(*(int *)(iVar1 + 0x20),(undefined2 *)&local_48,0);
    }
    *unaff_EDI = (uint)local_48 & 0xff;
    return 0;
  case 8:
    uVar5 = 0x11;
    goto LAB_6806c6a7;
  case 9:
    uVar3 = events_copyCastMember(iVar1,*(int *)(iVar1 + 0x28),param_1,1);
    *unaff_EDI = uVar3;
    return 0;
  case 10:
    uVar5 = 6;
    goto LAB_6806c77c;
  case 0xb:
    uVar5 = 0xb;
    break;
  case 0xc:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,10,(double *)&local_48);
    *unaff_EDI = (int)(char)local_48;
    return 0;
  case 0xd:
    uVar5 = 0xe;
    break;
  case 0xe:
    uVar5 = 0xf;
    goto LAB_6806c6a7;
  case 0x11:
    uVar5 = 7;
LAB_6806c655:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,uVar5,(double *)&local_48);
    local_50[0] = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(short)(uint)local_48);
LAB_6806c675:
    uVar3 = sprites_getPropertyId(unaff_EBX,local_50[0]);
    *unaff_EDI = uVar3;
    return 0;
  case 0x12:
    uVar5 = 1;
    break;
  case 0x13:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0xb,(double *)&local_48);
    *unaff_EDI = local_40;
    return 0;
  case 0x16:
    uVar5 = 0x13;
    break;
  case 0x17:
    uVar5 = 0xb;
LAB_6806c6a7:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,uVar5,(double *)&local_48);
    *unaff_EDI = (*(unsigned int *)((char *)&local_48 + 4));
    return 0;
  case 0x18:
    uVar5 = 0x14;
    break;
  case 0x19:
    uVar5 = 0x15;
    goto LAB_6806c850;
  case 0x1b:
    uVar5 = 0x10;
    break;
  case 0x1c:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x16,(double *)&local_48);
    *unaff_EDI = 100 - (((uint)local_48 & 0xff) * 100 + 0x7f) / 0xff;
    return 0;
  case 0x1d:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,5,(double *)&local_48);
    if ((uint)local_48 == 0) goto switchD_6806c61d_caseD_6;
    piVar4 = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24));
    Ordinal_1130(local_50,8);
    Ordinal_431(piVar4,(uint)local_48,0,(short *)local_50);
    goto LAB_6806c675;
  case 0x1e:
    uVar5 = 0x17;
    break;
  case 0x1f:
    uVar5 = 0x18;
LAB_6806c850:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,uVar5,(double *)&local_48);
    *unaff_EDI = (uint)local_48;
    return 0;
  case 0x20:
    uVar5 = 0x19;
LAB_6806c77c:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,uVar5,(double *)&local_48);
    *unaff_EDI = (uint)local_48 & 0xff;
    return 0;
  case 0x23:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,2,(double *)&local_48);
    *unaff_EDI = (int)(*(unsigned short *)((char *)&local_48 + 2));
    return 0;
  case 0x24:
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,2,(double *)&local_48);
    sVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(short)(uint)local_48);
    *unaff_EDI = (int)sVar2;
    return 0;
  case 0x29:
    uVar5 = 0x1d;
    break;
  case 0x2b:
    uVar5 = 0x2a;
  }
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,uVar5,(double *)&local_48);
  *unaff_EDI = (uint)local_48;
switchD_6806c61d_caseD_6:
  return 0;
}



// ============================================================
// Function: events_setMiawPropertyList (events_setMiawPropertyList)
// Address: 6806ca80
// Size: 230 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_setMiawPropertyList(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  local_8 = 0;
  iVar3 = Ordinal_165(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_10);
  if ((param_1 < 1) || (local_10 < param_1)) {
    return 0;
  }
  piVar4 = *(int **)(param_1 * 0x34 + iVar3);
  if (piVar4 != (int *)0x0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x148);
    *(int *)(iVar1 + 0x148) = param_1;
    local_c = piVar4;
    cast_retainObject(unaff_ESI,piVar4);
    iVar3 = cast_getMemberData(unaff_ESI,piVar4);
    param_1 = 1;
    if (0 < iVar3) {
      do {
        piVar4 = cast_resolveContext(unaff_ESI,piVar4,param_1);
        if (piVar4 != (int *)0x0) {
          local_8 = cast_dispatchVtableCall(unaff_ESI,piVar4,param_2,param_3,param_4);
          cast_releaseObject(unaff_ESI,piVar4);
          piVar4 = local_c;
          if (local_8 != 0) break;
        }
        param_1 = param_1 + 1;
        piVar4 = local_c;
      } while (param_1 <= iVar3);
    }
    cast_releaseObject(unaff_ESI,piVar4);
    *(undefined4 *)(iVar1 + 0x148) = uVar2;
  }
  return local_8;
}



// ============================================================
// Function: events_getMiawExtendedProp (events_getMiawExtendedProp)
// Address: 6806cb70
// Size: 695 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawExtendedProp(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_94 [4];
  int local_84;
  int local_80;
  int *local_7c;
  uint *local_78;
  uint local_74 [2];
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c [2];
  int local_54;
  int *local_50;
  int local_4c;
  int local_48 [16];
  uint local_8;
  
  iVar4 = 0;
  local_68 = 0;
  local_6c = 0;
  local_50 = (int *)0x0;
  local_4c = 0;
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x19);
    return 0;
  }
  local_78 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                     *(int *)(param_1 + 0x18));
  local_54 = props_resolveRef(param_1,local_78);
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_80 = iVar1;
  if (*(int *)(iVar1 + 0x734) != 0) {
    props_setError(param_1,0x71);
    goto LAB_6806cde4;
  }
  local_4c = Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,5,(double *)local_48)
  ;
  if (local_4c == 0) goto LAB_6806cde4;
  local_60 = local_48[0];
  local_7c = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  if (local_54 < 1) {
    Ordinal_447(local_7c,local_60);
LAB_6806cd84:
    local_94[0] = 1;
    local_4c = 1;
    Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0xe,(double *)local_94);
    piVar2 = local_50;
  }
  else {
    iVar1 = local_54 * 4;
    local_68 = cast_allocHandle(iVar1,0);
    local_64 = Ordinal_1114(local_68);
    local_6c = cast_allocHandle(iVar1,0);
    piVar2 = (int *)Ordinal_1114(local_6c);
    local_50 = piVar2;
    if ((local_64 == 0) || (piVar2 == (int *)0x0)) {
      props_setError(param_1,2);
    }
    else {
      iVar4 = 0;
      if (0 < local_54) {
        local_4c = local_64 - (int)piVar2;
        do {
          local_84 = iVar4 + 1;
          iVar1 = props_callMethodDirect(param_1,local_78,local_84,(int *)local_74);
          piVar5 = local_50;
          if ((((iVar1 != 0) ||
               (iVar1 = props_resolveRef(param_1,local_74), piVar5 = local_50, iVar1 != 2)) ||
              (iVar1 = props_callMethodDirect(param_1,local_74,1,(int *)local_5c), piVar5 = local_50,
              iVar1 != 0)) ||
             (iVar1 = core_setFieldValue(param_1,(int *)local_5c,(int *)(local_4c + (int)piVar2)),
             piVar5 = local_50, iVar1 == 0)) goto LAB_6806cdfd;
          props_releaseAndClear(param_1,(int *)local_5c);
          iVar1 = props_callMethodDirect(param_1,local_74,2,(int *)local_5c);
          piVar5 = local_50;
          if (iVar1 != 0) goto LAB_6806cdfd;
          if ((local_5c[0] == 0x40) || (local_5c[0] == 0x43)) {
            iVar1 = props_coerceAndReturnSymbol(param_1,local_5c,piVar2);
            piVar5 = local_50;
            if (iVar1 != 0) goto LAB_6806cdfd;
          }
          else {
            *piVar2 = 0;
          }
          props_releaseAndClear(param_1,(int *)local_5c);
          props_releaseAndClear(param_1,(int *)local_74);
          piVar2 = piVar2 + 1;
          iVar4 = local_84;
        } while (local_84 < local_54);
      }
      piVar5 = local_50;
      iVar3 = lingo_dispatchSpriteOp(local_7c,local_60,local_54,local_64,local_50);
      iVar1 = local_80;
      if (iVar3 != 0) goto LAB_6806cd84;
LAB_6806cdfd:
      props_setError(param_1,0x6e);
      local_4c = 0;
      piVar2 = piVar5;
    }
  }
  iVar1 = local_68;
  if (local_68 != 0) {
    Ordinal_1115(local_68);
    cast_freeHandle(iVar1);
  }
  iVar1 = local_6c;
  if (local_6c != 0) {
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      if (piVar2[iVar4] != 0) {
        cast_freeHandle(piVar2[iVar4]);
      }
    }
    Ordinal_1115(iVar1);
    cast_freeHandle(iVar1);
  }
LAB_6806cde4:
  return 0;
}



// ============================================================
// Function: events_setMiawExtendedProp (events_setMiawExtendedProp)
// Address: 6806ce30
// Size: 263 bytes
// Params: int * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawExtendedProp(int *param_1,uint *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  int unaff_ESI;
  int local_24 [2];
  uint local_1c [2];
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = Ordinal_430(param_1,unaff_EBX);
  iVar1 = props_getContextRef(unaff_ESI,(int *)param_2);
  if ((iVar1 == 0) && (iVar1 = 0, 0 < local_8)) {
    while ((iVar2 = Ordinal_446(param_1,unaff_EBX,iVar1,&local_c), iVar2 != 0 &&
           ((iVar2 = props_getContextRef(unaff_ESI,(int *)local_1c), iVar2 == 0 &&
            (local_10 = props_dispatchMethod(unaff_ESI,param_2,local_1c), local_10 == 0))))) {
      local_14 = 2;
      core_getFieldValue(unaff_ESI,&local_c,&local_14);
      iVar2 = props_dispatchMethod(unaff_ESI,local_1c,&local_14);
      if (iVar2 != 0) {
        return 0;
      }
      props_releaseAndClear(unaff_ESI,&local_14);
      puVar3 = (undefined4 *)Ordinal_432(param_1,unaff_EBX,iVar1);
      if (puVar3 == (undefined4 *)0x0) {
        iVar2 = props_storeIntValue(unaff_ESI,0,local_24);
      }
      else {
        iVar2 = props_getExtPair(unaff_ESI,puVar3,local_24);
      }
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = props_dispatchMethod(unaff_ESI,local_1c,local_24);
      if (iVar2 != 0) {
        return 0;
      }
      props_releaseAndClear(unaff_ESI,local_24);
      props_releaseAndClear(unaff_ESI,(int *)local_1c);
      iVar1 = iVar1 + 1;
      if (local_8 <= iVar1) {
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: events_resolveMiawPath (events_resolveMiawPath)
// Address: 6806cf40
// Size: 250 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resolveMiawPath(int param_1,int param_2,int param_3,uint *param_4)
{
  int iVar1;
  int iVar2;
  int local_8c;
  uint local_88 [16];
  uint local_48 [16];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 == 0) {
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x15,(double *)local_88);
    props_storeIntValue(param_1,local_88[0],param_4);
  }
  else {
    iVar2 = props_coerceAndReturnInt(param_1,param_4,&local_8c);
    if (iVar2 == 0) {
      Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x15,(double *)local_88);
      local_48[0] = (uint)(local_8c != 0);
      Ordinal_373(*(uint *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x15,(double *)local_48,1);
      if ((*(int *)(iVar1 + 0x7c) == param_2) && (local_48[0] == 0)) {
        sprites_setCursorVisible(iVar1,1);
      }
      if (local_88[0] != local_48[0]) {
        scoreEngine_dispatchPropertyOp(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
        return 0;
      }
    }
  }
  return 0;
}




// ============================================================
// Function: events_handleMiawNavigation (events_handleMiawNavigation)
// Address: 6806d040
// Size: 2238 bytes
// Params: void * this, double * param_1, int param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall
events_handleMiawNavigation(void *this,double *param_1,int param_2,int param_3,int param_4,uint *param_5)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined2 uVar7;
  undefined8 local_c4;
  uint *local_bc;
  int *local_b8;
  undefined1 local_b4 [60];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined8 local_48;
  uint local_8;
  
  iVar5 = *(int *)(*(int *)(param_1 + 1) + 4);
  uVar2 = 0;
  local_bc = this;
  if (param_4 < 0x326) {
    if (param_4 < 0x324) {
      if (param_4 < 0x1a0) {
        if (param_4 != 0x19f) {
          if (param_4 == 0xbe) {
            if (param_3 == 0) {
              Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,9,
                          (double *)&local_48);
              uVar2 = props_storeFloatValue((int)param_1,(undefined4 *)&local_48,local_bc);
              goto switchD_6806d1a5_caseD_1a0;
            }
            uVar2 = props_coerceAndStore((int)param_1,this,(int *)&local_48);
            if (uVar2 != 0) goto switchD_6806d1a5_caseD_1a0;
            iVar1 = *(int *)(iVar5 + 0x28);
            uVar4 = *(uint *)(iVar5 + 0x20);
            iVar5 = 9;
            goto LAB_6806d0f3;
          }
          if (param_4 != 0x150) goto switchD_6806d4ae_caseD_331;
LAB_6806d1ac:
          events_resolveMiawPath((int)param_1,param_2,param_3,this);
          goto switchD_6806d1a5_caseD_1a0;
        }
      }
      else {
        if (param_4 == 0x1e6) goto LAB_6806d1ac;
        if ((param_4 < 0x1e8) || (0x1eb < param_4)) goto switchD_6806d4ae_caseD_331;
      }
    }
    if (param_3 != 0) {
      iVar5 = Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,0x1a,
                          (double *)&local_48);
      if ((iVar5 != 0) && ((int)local_48 != 0)) {
        switch(param_4) {
        case 0x19f:
          iVar5 = props_coerceAndReturnInt((int)param_1,local_bc,(int *)&local_b8);
          if (iVar5 == 0) {
            if ((int)local_b8 < 0) {
              local_b8 = (int *)0x0;
              Ordinal_1955((int)local_48,0);
            }
            else {
              if (0xff < (int)local_b8) {
                local_b8 = (int *)0xff;
              }
              Ordinal_1955((int)local_48,(short)local_b8);
            }
          }
          break;
        case 0x1e8:
          iVar5 = props_coerceAndReturnDouble((int)param_1,local_bc,(double *)&local_c4);
          if (iVar5 == 0) {
            uVar3 = events_getMiawRuntimeData(SUB84(local_c4,0),(short)((ulonglong)local_c4 >> 0x20));
            Ordinal_1959((int)local_48,(short)uVar3);
          }
          break;
        case 0x1e9:
          iVar5 = props_coerceAndReturnInt((int)param_1,local_bc,(int *)&local_b8);
          if (iVar5 == 0) {
            if ((int)local_b8 < 0) {
              local_b8 = (int *)0x0;
            }
            Ordinal_1963((int)local_48,(short)local_b8);
          }
          break;
        case 0x1ea:
          iVar5 = props_coerceAndReturnInt((int)param_1,local_bc,(int *)&local_b8);
          if (iVar5 == 0) {
            if ((int)local_b8 < 0) {
              local_b8 = (int *)0x0;
            }
            Ordinal_1965((int)local_48,(short)local_b8);
          }
          break;
        case 0x1eb:
          iVar5 = props_coerceAndReturnInt((int)param_1,local_bc,(int *)&local_b8);
          if (iVar5 == 0) {
            Ordinal_1966((int)local_48,(short)local_b8);
          }
        }
      }
      goto switchD_6806d1a5_caseD_1a0;
    }
    uVar3 = 0;
    local_c4 = 0.0;
    iVar5 = Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,0x1a,
                        (double *)&local_48);
    if ((iVar5 == 0) || ((int)local_48 == 0)) {
LAB_6806d46d:
      if (param_4 != 0x1e8) {
LAB_6806d3f0:
        uVar2 = props_storeIntValue(param_1,uVar3,local_bc);
        goto switchD_6806d1a5_caseD_1a0;
      }
    }
    else {
      Ordinal_1952((int)local_48,(short)local_b4);
      uVar7 = SUB82(local_48,0);
      if (0x1e8 < param_4) {
        if (0x1eb < param_4) {
          if (param_4 == 0x324) {
            uVar3 = Ordinal_1988(uVar7);
            uVar2 = props_storeIntValue(param_1,uVar3,local_bc);
            goto switchD_6806d1a5_caseD_1a0;
          }
          if (param_4 == 0x325) {
            uVar3 = Ordinal_1962(uVar7);
            uVar2 = props_storeIntValue(param_1,uVar3,local_bc);
            goto switchD_6806d1a5_caseD_1a0;
          }
          goto LAB_6806d46d;
        }
        if (param_4 == 0x1eb) {
          uVar2 = props_storeIntValue(param_1,local_70,local_bc);
          goto switchD_6806d1a5_caseD_1a0;
        }
        if (param_4 != 0x1e9) {
          if (param_4 == 0x1ea) {
            uVar2 = props_storeIntValue(param_1,local_74,local_bc);
            goto switchD_6806d1a5_caseD_1a0;
          }
          goto LAB_6806d46d;
        }
        uVar3 = Ordinal_1987(uVar7);
        goto LAB_6806d3f0;
      }
      if (param_4 != 0x1e8) {
        if (param_4 == 0x19f) {
          uVar2 = props_storeIntValue(param_1,local_78,local_bc);
          goto switchD_6806d1a5_caseD_1a0;
        }
        goto LAB_6806d46d;
      }
      local_b8 = (int *)Ordinal_1958(uVar7);
      events_setMiawRuntimeData((double *)&local_c4);
    }
    uVar2 = props_storeFloatDirect((int)param_1,local_c4,(int *)local_bc);
    goto switchD_6806d1a5_caseD_1a0;
  }
  switch(param_4) {
  case 0x330:
    local_48 = (double)((ulonglong)(*(unsigned int *)((char *)&local_48 + 4)) << 0x20);
    memset((void *)((int)&local_48 + 4),0,0x3c);
    if (param_3 == 0) {
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,0x26,(double *)&local_48);
      uVar2 = props_storeIntValue(param_1,(int)local_48,local_bc);
    }
    break;
  default:
switchD_6806d4ae_caseD_331:
    return 0;
  case 0x349:
  case 0x34a:
    local_b8 = (int *)0x0;
    if (param_4 == 0x349) {
      local_b8 = (int *)0x22;
    }
    else if (param_4 == 0x34a) {
      local_b8 = (int *)0x23;
    }
    local_48 = (double)((ulonglong)(*(unsigned int *)((char *)&local_48 + 4)) << 0x20);
    if (param_3 == 0) {
      memset((void *)((int)&local_48 + 4),0,0x3c);
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,local_b8,(double *)&local_48
                 );
      local_c4 = local_48;
      uVar2 = props_storeFloatDirect((int)param_1,local_48,(int *)local_bc);
    }
    else {
      memset((void *)((int)&local_48 + 4),0,0x3c);
      iVar1 = props_coerceAndReturnDouble((int)param_1,local_bc,(double *)&local_c4);
      if (iVar1 == 0) {
        local_48 = local_c4;
        iVar5 = Ordinal_373(*(uint *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,(int)local_b8,
                            (double *)&local_48,1);
        uVar2 = (uint)(iVar5 == 0);
      }
    }
    break;
  case 0x34b:
  case 0x34c:
    local_b8 = (int *)0x0;
    if (param_4 == 0x34b) {
      local_b8 = (int *)0x24;
    }
    else if (param_4 == 0x34c) {
      local_b8 = (int *)0x25;
    }
    local_48 = (double)((ulonglong)(*(unsigned int *)((char *)&local_48 + 4)) << 0x20);
    if (param_3 == 0) {
      memset((void *)((int)&local_48 + 4),0,0x3c);
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,local_b8,(double *)&local_48
                 );
      local_c4 = (double)CONCAT44((int)local_48,(undefined4)local_c4);
      uVar2 = props_storeIntValue(param_1,(int)local_48,local_bc);
      break;
    }
    memset((void *)((int)&local_48 + 4),0,0x3c);
    iVar1 = props_coerceAndReturnInt((int)param_1,local_bc,(int *)((int)&local_c4 + 4));
    if (iVar1 != 0) break;
    local_48 = (double)CONCAT44((*(unsigned int *)((char *)&local_48 + 4)),(*(unsigned int *)((char *)&local_c4 + 4)));
    piVar6 = local_b8;
    goto LAB_6806d68a;
  case 0x353:
    if (param_3 == 0) {
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,0x21,(double *)&local_48);
      uVar2 = props_createPolygonObject(param_1,(double *)&local_48,local_bc);
      break;
    }
    uVar2 = props_getPointsFromObject((int)param_1,this,(undefined4 *)&local_48);
    if (uVar2 != 0) break;
    piVar6 = (int *)0x21;
    goto LAB_6806d68a;
  case 0x355:
  case 0x356:
  case 0x376:
    local_b8 = (int *)Ordinal_482(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28));
    iVar5 = Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,5,(double *)&local_48)
    ;
    uVar2 = (uint)(iVar5 == 0);
    if (uVar2 == 0) {
      if (param_4 == 0x355) {
        if (param_3 == 0) {
          uVar3 = Ordinal_433(local_b8,(int)local_48);
          uVar2 = props_storeIntValue(param_1,uVar3,local_bc);
          break;
        }
      }
      else if (param_4 == 0x356) {
        if (param_3 == 0) {
          uVar3 = Ordinal_434(local_b8,(int)local_48);
          uVar2 = props_storeIntValue(param_1,uVar3,local_bc);
          break;
        }
      }
      else {
        if (param_4 != 0x376) break;
        if (param_3 == 0) {
          events_setMiawExtendedProp(local_b8,local_bc);
          break;
        }
      }
      uVar2 = 0x800407d6;
    }
    break;
  case 0x359:
    if (param_3 == 0) {
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,8,(double *)&local_48);
      uVar2 = props_storeFloatValue((int)param_1,(undefined4 *)&local_48,local_bc);
      break;
    }
    uVar2 = props_coerceAndStore((int)param_1,this,(int *)&local_48);
    if (uVar2 != 0) break;
    iVar1 = *(int *)(iVar5 + 0x28);
    uVar4 = *(uint *)(iVar5 + 0x20);
    iVar5 = 8;
    goto LAB_6806d0f3;
  case 0x367:
    if (param_3 == 0) {
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,0x16,(double *)&local_48);
      uVar2 = props_storeIntValue(param_1,0xff - (uint)(byte)local_48,local_bc);
      break;
    }
    uVar2 = props_coerceAndReturnInt((int)param_1,this,(int *)((int)&local_c4 + 4));
    local_48 = (double)CONCAT71((*(unsigned long long *)((char *)&local_48 + 1)),-1 - (*(unsigned char *)((char *)&local_c4 + 4)));
    if (uVar2 != 0) break;
    iVar1 = *(int *)(iVar5 + 0x28);
    uVar4 = *(uint *)(iVar5 + 0x20);
    iVar5 = 0x16;
LAB_6806d0f3:
    Ordinal_373(uVar4,iVar1,param_2,iVar5,(double *)&local_48,1);
    break;
  case 0x36e:
    if (param_3 == 0) {
      Ordinal_374(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,0x12,(double *)&local_48);
      uVar2 = props_storeIntValue(param_1,(int)local_48,local_bc);
      break;
    }
    uVar2 = props_coerceAndReturnInt((int)param_1,this,(int *)&local_48);
    if (uVar2 != 0) break;
    piVar6 = (int *)0x12;
LAB_6806d68a:
    iVar5 = Ordinal_373(*(uint *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),param_2,(int)piVar6,
                        (double *)&local_48,1);
    uVar2 = (uint)(iVar5 == 0);
  }
switchD_6806d1a5_caseD_1a0:
  *param_5 = uVar2;
  return 0;
}



// ============================================================
// Function: events_getMiawScriptData (events_getMiawScriptData)
// Address: 6806d9e0
// Size: 345 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_getMiawScriptData(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int *unaff_EBX;
  int unaff_EDI;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar1 = *(int *)(unaff_EBX[2] + 4);
  local_8 = 0;
  iVar3 = Ordinal_165(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_10);
  if (param_1 <= local_10) {
    local_c = *(int **)(param_1 * 0x34 + iVar3);
    if (local_c != (int *)0x0) {
      local_20 = *(undefined4 *)(iVar1 + 0x148);
      *(int *)(iVar1 + 0x148) = param_1;
      *(undefined4 *)(unaff_EDI + 0xc) = *(undefined4 *)(iVar1 + 0x760);
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      local_28 = *(int *)(iVar1 + 0x760);
      local_24 = 0;
      cast_retainObject(unaff_EBX,local_c);
      local_1c = cast_getMemberData(unaff_EBX,local_c);
      param_1 = 1;
      if (0 < local_1c) {
        do {
          local_14 = cast_resolveContext(unaff_EBX,local_c,param_1);
          if (local_14 != (int *)0x0) {
            *(undefined4 *)(iVar1 + 0x18c) = 0;
            bVar2 = cast_executeHandler(unaff_EBX,local_14,*(undefined4 *)(unaff_EDI + 8),
                                 *(uint *)(unaff_EDI + 0x14),*(uint **)(unaff_EDI + 0x18),&local_28,
                                 &local_18);
            if ((CONCAT31(extraout_var,bVar2) != 0) || (bVar2 = local_8 != 0, local_8 = 0, bVar2)) {
              local_8 = 1;
            }
            cast_releaseObject(unaff_EBX,local_14);
            if ((*(int *)(iVar1 + 0x18c) != 0) || (local_18 != 0)) break;
          }
          if (local_28 != *(int *)(iVar1 + 0x760)) {
            props_releaseValue(unaff_EBX,(byte)*(undefined4 *)(unaff_EDI + 0xc),
                         *(int **)(unaff_EDI + 0x10));
            *(int *)(unaff_EDI + 0xc) = local_28;
            *(undefined4 *)(unaff_EDI + 0x10) = local_24;
            local_28 = *(int *)(iVar1 + 0x760);
            local_24 = 0;
          }
          param_1 = param_1 + 1;
        } while (param_1 <= local_1c);
      }
      cast_releaseObject(unaff_EBX,local_c);
      *(undefined4 *)(iVar1 + 0x148) = local_20;
    }
  }
  return local_8;
}



// ============================================================
// Function: events_setMiawScriptData (events_setMiawScriptData)
// Address: 6806db40
// Size: 396 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_setMiawScriptData(int param_1,int param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined1 local_78 [4];
  undefined4 local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_8;
  
  local_68 = param_3;
  iVar2 = *(int *)(*(int *)(param_3 + 8) + 4);
  Ordinal_374(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2,0xb,(double *)&local_48);
  if (4 < *(int *)(param_1 + 8) - 0x3bdU) {
    return 0;
  }
  uVar4 = 0xffffffff;
  iVar1 = props_coerceToContextState(local_68,param_1,2);
  if (iVar1 == 0) {
    if ((((local_48 <= local_6c) && (local_6c <= local_40)) && (local_44 <= local_70)) &&
       (local_70 <= local_3c)) {
      local_60 = local_6c - local_48;
      local_5c = local_70 - local_44;
      Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_4,0x74,&local_60);
      switch(*(int *)(param_1 + 8)) {
      case 0x3bd:
        local_64 = 1;
        break;
      case 0x3be:
        local_64 = 2;
        break;
      case 0x3bf:
      case 0x3c1:
        local_64 = 4;
        break;
      case 0x3c0:
        local_64 = 3;
      }
      uVar4 = local_54;
      if (*(int *)(param_1 + 8) != 0x3bd) {
        local_60 = 0;
        local_58 = 0;
        iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_4,0x31,&local_60);
        if ((iVar2 != 0) && (pbVar3 = (byte *)Ordinal_1114(local_60), pbVar3 != (byte *)0x0)) {
          uVar4 = Ordinal_1116(local_60,local_54);
          iVar2 = Ordinal_1249(pbVar3,uVar4);
          props_invokeBuiltin(local_68,local_64,(int)local_78,pbVar3,iVar2 + -1);
          Ordinal_1115(local_60);
          uVar4 = local_74;
        }
      }
    }
    props_storeIntValue(local_68,uVar4,(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}




// ============================================================
// Function: events_getMiawChannelData (events_getMiawChannelData)
// Address: 6806dce0
// Size: 2032 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawChannelData(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_158;
  undefined4 local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  undefined4 local_130;
  int local_12c;
  undefined4 local_128;
  uint local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 *local_110;
  undefined1 local_10c [76];
  undefined4 local_c0;
  int local_a0 [16];
  uint local_60 [6];
  int local_48 [16];
  uint local_8;
  
  local_134 = *(int *)(*(int *)(param_1 + 8) + 4);
  if ((param_2 < 1) || (*(int *)(param_1 + 0xf4) < param_2)) goto LAB_6806dea8;
  if (*(int *)(param_3 + 8) - 0x368U < 2) {
    local_120 = 0;
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    local_110 = (undefined4 *)0x0;
    local_124 = 0;
    iVar1 = Ordinal_374(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x24),param_2,2,
                        (double *)local_48);
    if ((((iVar1 == 0) ||
         (iVar1 = Ordinal_294(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x28),local_48[0],5,
                              &local_124), iVar1 == 0)) ||
        (iVar1 = Ordinal_374(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x28),param_2,0x21,
                             (double *)local_48), iVar1 == 0)) ||
       (iVar1 = props_coerceToContextState(param_1,param_3,2), iVar1 != 0)) goto LAB_6806dea8;
    local_144 = local_14c;
    local_140 = local_150;
    if (*(int *)(param_3 + 8) == 0x368) {
      iVar1 = Ordinal_1070(&local_124);
      if (iVar1 != 0) {
        Ordinal_1089(&local_124,local_48,&local_144,&local_13c);
LAB_6806de65:
        local_14c = local_13c;
        local_150 = local_138;
        props_storeSymbolRef(param_1,&local_150,(undefined4 *)(param_3 + 0xc));
        goto LAB_6806dea8;
      }
    }
    else {
      iVar1 = Ordinal_1084(local_48,&local_144);
      if (iVar1 != 0) {
        Ordinal_1090(local_48,&local_124,&local_144,&local_13c);
        goto LAB_6806de65;
      }
    }
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(local_134 + 0x760);
    *(undefined4 *)(param_3 + 0x10) = 0;
    goto LAB_6806dea8;
  }
  Ordinal_374(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x28),param_2,2,(double *)local_a0);
  local_140 = local_a0[0];
  Ordinal_294(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x28),local_a0[0],2,local_60);
  if (local_60[0] == 3) {
    iVar1 = events_setMiawScriptData(param_3,param_2,param_1,local_140);
LAB_6806e49e:
    if (iVar1 != -0x7ffbf821) goto LAB_6806dea8;
  }
  else {
    if (local_60[0] == 10) {
      local_130 = 0;
      local_12c = 0;
      local_128 = 0;
      local_124 = 0;
      local_120 = 0;
      local_11c = 0;
      local_118 = 0;
      local_114 = 0;
      local_110 = (undefined4 *)0x0;
      iVar1 = Ordinal_374(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x28),param_2,0x1a,
                          (double *)local_48);
      if (iVar1 == 0) goto LAB_6806dea8;
      if (local_48[0] == 0) {
        props_storeIntValue(param_1,0,(undefined4 *)(param_3 + 0xc));
        goto LAB_6806dea8;
      }
      Ordinal_1952(local_48[0],local_10c);
      switch(*(undefined4 *)(param_3 + 8)) {
      case 0x2c7:
        iVar1 = props_storeIntValue(param_1,local_c0,(undefined4 *)(param_3 + 0xc));
        break;
      case 0x2c8:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,1,&local_130);
          switch(local_130) {
          case 1:
            local_134 = 0x234;
            iVar1 = props_storeObjectRef(param_1,0x234,(undefined4 *)(param_3 + 0xc));
            break;
          case 2:
            local_134 = 0x54;
            iVar1 = props_storeObjectRef(param_1,0x54,(undefined4 *)(param_3 + 0xc));
            break;
          case 3:
            local_134 = 0xfb;
            iVar1 = props_storeObjectRef(param_1,0xfb,(undefined4 *)(param_3 + 0xc));
            break;
          case 4:
            local_134 = 0x27e;
            iVar1 = props_storeObjectRef(param_1,0x27e,(undefined4 *)(param_3 + 0xc));
            break;
          case 5:
            local_134 = 0x27f;
            iVar1 = props_storeObjectRef(param_1,0x27f,(undefined4 *)(param_3 + 0xc));
            break;
          default:
            local_134 = 0;
            iVar1 = props_storeObjectRef(param_1,0,(undefined4 *)(param_3 + 0xc));
          }
        }
        break;
      case 0x2c9:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,2,&local_130);
          iVar1 = props_storeIntValue(param_1,local_128,(undefined4 *)(param_3 + 0xc));
        }
        break;
      case 0x2ca:
        props_coerceToType(param_1,param_3,2,&local_138);
        Ordinal_1983(local_48[0],local_138,3,&local_130);
        iVar1 = props_storeIntValue(param_1,local_124,(undefined4 *)(param_3 + 0xc));
        break;
      case 0x2cb:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,4,&local_130);
          iVar1 = props_storeIntValue(param_1,local_12c,(undefined4 *)(param_3 + 0xc));
        }
        break;
      case 0x2cc:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if ((iVar1 == 0) && (iVar1 = props_coerceToType(param_1,param_3,3,&local_134), iVar1 == 0)) {
          local_12c = local_134;
          Ordinal_1984(local_48[0],local_138,4,&local_130);
          goto LAB_6806dea8;
        }
        break;
      case 0x2cd:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,7,&local_130);
          iVar1 = props_storeIntValue(param_1,local_120,(undefined4 *)(param_3 + 0xc));
        }
        break;
      case 0x2ce:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,8,&local_130);
          iVar1 = props_storeIntValue(param_1,local_11c,(undefined4 *)(param_3 + 0xc));
        }
        break;
      case 0x2cf:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,5,&local_130);
          iVar1 = props_storeIntValue(param_1,local_118,(undefined4 *)(param_3 + 0xc));
        }
        break;
      case 0x2d0:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,6,&local_130);
          iVar1 = props_storeIntValue(param_1,local_114,(undefined4 *)(param_3 + 0xc));
        }
        break;
      case 0x2d1:
        iVar1 = props_coerceToType(param_1,param_3,2,&local_138);
        if (iVar1 == 0) {
          Ordinal_1983(local_48[0],local_138,9,&local_130);
          iVar1 = props_getExtPair(param_1,local_110,(undefined4 *)(param_3 + 0xc));
        }
        break;
      default:
        goto switchD_6806e02e_caseD_2d2;
      case 0x327:
        if (*(int *)(param_3 + 0x14) != 2) goto LAB_6806dea8;
        local_158 = *(uint *)(*(int *)(param_3 + 0x18) + 8);
        local_154 = *(undefined4 *)(*(int *)(param_3 + 0x18) + 0xc);
        local_14c = 0;
        iVar1 = props_coerceAndReturnSymbol(param_1,&local_158,&local_140);
        if (iVar1 == -0x7ffbf824) {
          iVar1 = props_coerceToType(param_1,param_3,2,&local_140);
        }
        else {
          local_14c = 1;
        }
        if (iVar1 == 0) {
          uVar3 = stage_setScoreChannelPosition(param_1,param_2,local_140,local_14c);
          *(undefined4 *)(param_3 + 0x10) = uVar3;
          *(undefined4 *)(param_3 + 0xc) = 4;
          if (local_14c != 0) {
            props_freeStringAndReturn(param_1,&local_158,local_140);
          }
          goto LAB_6806dea8;
        }
      }
      goto LAB_6806e49e;
    }
    if (local_60[0] == 0xf) {
      local_148 = -0x7ffbf82e;
      iVar2 = scoreEngine_dispatchPropertyGet(*(int *)(local_134 + 0x20),*(int *)(local_134 + 0x28),param_2,param_3,
                           &local_148);
      iVar1 = local_148;
      if (iVar2 == 0) {
        if (local_148 == -0x7ffbf821) goto switchD_6806e02e_caseD_2d2;
        uVar3 = props_translateError(local_148);
        iVar1 = local_148;
        if ((short)uVar3 == 0x61) {
          props_reportError(param_1,0x61);
        }
        else {
          props_setError(param_1,(int)(short)uVar3);
        }
      }
      goto LAB_6806e49e;
    }
  }
switchD_6806e02e_caseD_2d2:
  iVar1 = events_getMiawScriptData(param_2);
  if (iVar1 != 0) {
    return 0;
  }
LAB_6806dea8:
  return 0;
}



// ============================================================
// Function: events_setMiawChannelData (events_setMiawChannelData)
// Address: 6806e580
// Size: 275 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawChannelData(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  char local_88 [64];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,4,(double *)local_88);
  local_44 = param_3;
  local_3c = param_5;
  if (param_5 <= param_3) {
    local_44 = param_5;
    local_3c = param_3;
  }
  local_40 = param_6;
  local_48 = param_4;
  if (param_6 <= param_4) {
    local_48 = param_6;
    local_40 = param_4;
  }
  Ordinal_373(*(uint *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xb,(double *)&local_48,1);
  if (local_88[0] == '\x05') {
    if (((param_4 < param_6) && (param_3 < param_5)) || ((param_6 < param_4 && (param_5 < param_3)))
       ) goto LAB_6806e680;
    local_48 = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),6);
  }
  else {
    if (((local_88[0] != '\x06') || ((param_4 < param_6 && (param_5 < param_3)))) ||
       ((param_6 < param_4 && (param_3 < param_5)))) goto LAB_6806e680;
    local_48 = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),5);
  }
  Ordinal_373(*(uint *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,4,(double *)&local_48,1);
LAB_6806e680:
  return 0;
}



// ============================================================
// Function: events_getWindowData (FUN_6806e6a0)
// Address: 6806e6a0
// Size: 94 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowData(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xb,(double *)&local_48);
  *param_3 = local_44;
  param_3[1] = local_48;
  param_3[2] = local_3c;
  param_3[3] = local_40;
  return 0;
}



// ============================================================
// Function: events_setWindowData (FUN_6806e700)
// Address: 6806e700
// Size: 40 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowData(int param_1,int param_2,int *param_3)
{
  events_setMiawChannelData(param_1,param_2,*param_3,param_3[1],param_3[2],param_3[3]);
  return 0;
}



// ============================================================
// Function: events_getMiawMediaRef (events_getMiawMediaRef)
// Address: 6806e730
// Size: 94 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawMediaRef(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x2b,(double *)&local_48);
  *param_3 = local_44;
  param_3[1] = local_48;
  param_3[2] = local_3c;
  param_3[3] = local_40;
  return 0;
}



// ============================================================
// Function: events_setMiawMediaRef (events_setMiawMediaRef)
// Address: 6806e790
// Size: 120 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawMediaRef(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined8 local_48;
  uint local_8;
  
  (*(unsigned int *)((char *)&local_48 + 0)) = param_3[1];
  (*(unsigned int *)((char *)&local_48 + 4)) = *param_3;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  events_clampToSpriteRect(iVar1,(int)(short)param_2,(int *)&local_48);
  Ordinal_373(*(uint *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xe,(double *)&local_48,1);
  Ordinal_373(*(uint *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xf,(double *)&local_48,1);
  return 0;
}



// ============================================================
// Function: events_getMiawSpriteRef (events_getMiawSpriteRef)
// Address: 6806e810
// Size: 104 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawSpriteRef(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xe,(double *)&local_48);
  param_3[1] = local_48;
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xf,(double *)&local_48);
  *param_3 = local_44;
  return 0;
}



// ============================================================
// Function: events_setMiawSpriteRef (events_setMiawSpriteRef)
// Address: 6806e880
// Size: 141 bytes
// Params: int param_1, int param_2, byte * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawSpriteRef(int param_1,int param_2,byte *param_3)
{
  int *piVar1;
  int iVar2;
  int local_48 [16];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2,5,(double *)local_48);
  piVar1 = (int *)Ordinal_482(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x24));
  iVar2 = Ordinal_403(piVar1);
  if (iVar2 != 0) {
    if (local_48[0] != 0) {
      Ordinal_462(piVar1,local_48[0],param_3);
    }
    return 0;
  }
  return 0;
}




// ============================================================
// Function: events_getMiawCursorRef (events_getMiawCursorRef)
// Address: 6806e910
// Size: 99 bytes
// Params: int param_1, int param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawCursorRef(int param_1,int param_2,undefined1 *param_3)
{
  int local_18;
  int iVar1;
  int *piVar2;
  int local_48 [16];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,5,(double *)local_48);
  piVar2 = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24));
  if (local_48[0] != 0) {
    Ordinal_463(piVar2,local_48[0],param_3);
  }
  return 0;
}



// ============================================================
// Function: events_setMiawCursorRef (events_setMiawCursorRef)
// Address: 6806e980
// Size: 202 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawCursorRef(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int local_ac;
  double local_a8 [8];
  double local_68 [8];
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_184(*(int *)(iVar1 + 0x20),0,local_18,local_28);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0xb,local_68);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0xb,local_a8);
  if (iVar2 != 0) {
    Ordinal_1071(local_68,local_18,local_28);
    Ordinal_1071(local_a8,local_18,local_28);
  }
  Ordinal_54(*(int *)(iVar1 + 0x20),&local_ac);
  scoreEngine_animateTransition(local_ac,(int *)local_68,(int *)local_a8,param_4);
  return 0;
}



// ============================================================
// Function: events_getMiawSoundRef (events_getMiawSoundRef)
// Address: 6806ea50
// Size: 29 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint events_getMiawSoundRef(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x40);
  return uVar1 & ((int)uVar1 < 1) - 1;
}



// ============================================================
// Function: events_setMiawSoundRef (events_setMiawSoundRef)
// Address: 6806ea70
// Size: 145 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawSoundRef(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_30 = *(undefined4 *)(iVar1 + 0x164);
  local_2c = *(undefined4 *)(iVar1 + 0x168);
  iVar1 = Ordinal_184(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_18,local_28);
  if (iVar1 != 0) {
    Ordinal_1072(&local_30,local_28,local_18);
    param_2[1] = local_30;
    *param_2 = local_2c;
    return 0;
  }
  param_2[1] = local_30;
  *param_2 = local_2c;
  return 0;
}



// ============================================================
// Function: events_getMiawTimerRef (events_getMiawTimerRef)
// Address: 6806eb10
// Size: 37 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawTimerRef(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_mapPropertyIndex(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2,param_3);
  return 0;
}



// ============================================================
// Function: events_setMiawTimerRef (events_setMiawTimerRef)
// Address: 6806eb40
// Size: 37 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawTimerRef(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_unmapPropertyIndex(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2,param_3);
  return 0;
}



// ============================================================
// Function: events_getWindowProperty (FUN_6806eb70)
// Address: 6806eb70
// Size: 98 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowProperty(int param_1,int param_2)
{
  int iVar1;
  undefined4 local_60 [16];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,2,(double *)local_60);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_60[0],2,local_20);
  return 0;
}



// ============================================================
// Function: events_getMiawVideoRef (events_getMiawVideoRef)
// Address: 6806ebe0
// Size: 98 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawVideoRef(int param_1,int param_2)
{
  int iVar1;
  undefined4 local_60 [16];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,2,(double *)local_60);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_60[0],2,local_20);
  return 0;
}



// ============================================================
// Function: events_setMiawVideoRef (events_setMiawVideoRef)
// Address: 6806ec50
// Size: 22 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawVideoRef(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x148);
}



// ============================================================
// Function: events_getMiawNetRef (events_getMiawNetRef)
// Address: 6806ec70
// Size: 38 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawNetRef(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  if (piVar1[0xe] != 0) {
    scoreEngine_writeNotation(piVar1,piVar1[0xf],piVar1[0xe],1,2);
  }
  return 0;
}



// ============================================================
// Function: events_setMiawNetRef (events_setMiawNetRef)
// Address: 6806eca0
// Size: 117 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall events_setMiawNetRef(int param_1)
{
  undefined4 uVar1;
  int local_2c [10];
  
  uVar1 = 0;
  local_2c[1] = 0;
  local_2c[2] = 0;
  local_2c[3] = 0;
  local_2c[4] = 0;
  local_2c[5] = 0;
  local_2c[6] = 0;
  local_2c[7] = 0;
  local_2c[8] = 0;
  if ((param_1 != 0) && (Ordinal_54(*(int *)(param_1 + 0x20),local_2c), local_2c[0] != 0)) {
    uVar1 = Ordinal_2032(local_2c[0],0);
  }
  Ordinal_2031(uVar1,local_2c + 1);
  return 0;
}



// ============================================================
// Function: events_getMiawRenderRef (events_getMiawRenderRef)
// Address: 6806ed20
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_getMiawRenderRef(int param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 unaff_EDI;
  int local_8;
  
  uVar3 = 0;
  local_8 = param_1;
  Ordinal_54(*(int *)(param_1 + 0x20),&local_8);
  if (local_8 != 0) {
    uVar3 = Ordinal_2032(local_8,0);
  }
  uVar1 = Ordinal_2034(uVar3);
  switch(unaff_EDI) {
  case 1:
    uVar2 = 1;
    break;
  case 2:
    uVar2 = 2;
    break;
  default:
    uVar2 = 0;
    break;
  case 4:
    uVar2 = 4;
    break;
  case 8:
    uVar2 = 8;
    break;
  case 0x10:
    uVar2 = 0x10;
    break;
  case 0x18:
    uVar2 = 0x20;
    break;
  case 0x20:
    uVar2 = 0x40;
  }
  if ((uVar1 & uVar2) != 0) {
    Ordinal_2035(uVar3);
  }
  return 0;
}



// ============================================================
// Function: events_setMiawRenderRef (events_setMiawRenderRef)
// Address: 6806edf0
// Size: 57 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawRenderRef(undefined4 param_1)
{
  int iVar1;
  int *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  media_getAssetData(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),param_1,unaff_EDI,unaff_EBX);
  if ((*unaff_EDI == 0) && (*unaff_EBX == 0)) {
    iVar1 = media_lookupAsset(*(int *)(unaff_ESI + 0x20),*(byte **)(unaff_ESI + 0x28),param_1);
    *unaff_EBX = iVar1;
    *unaff_EDI = iVar1;
  }
  return 0;
}



// ============================================================
// Function: events_getMiawXtraRef (events_getMiawXtraRef)
// Address: 6806ee30
// Size: 55 bytes
// Params: int param_1, uint * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_getMiawXtraRef(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = props_coerceAndStore(param_1,param_2,&param_1);
  if (iVar2 == 0) {
    Ordinal_250(*(int *)(iVar1 + 0x20),&param_1);
  }
  return iVar2;
}



// ============================================================
// Function: events_setMiawXtraRef (events_setMiawXtraRef)
// Address: 6806ee70
// Size: 45 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawXtraRef(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = param_1;
  Ordinal_251(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),(undefined1 *)&param_1);
  props_storeFloatValue(iVar1,&param_1,param_2);
  return 0;
}




// ============================================================
// Function: events_setWindowProperty (FUN_6806eea0)
// Address: 6806eea0
// Size: 1999 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setWindowProperty(uint param_1,int param_2,int param_3,uint *param_4)
{
  void *pvVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  int iVar8;
  byte local_74 [3];
  char local_71;
  void *local_70;
  void *local_6c;
  char local_65;
  void *local_64;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [16];
  uint local_8;
  
  local_64 = (void *)0x0;
  iVar8 = (*(int **)(param_1 + 8))[1];
  iVar5 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  if (((iVar8 == 0) || (*(int *)(iVar8 + 0x20) == 0)) ||
     ((param_3 != 0 &&
      ((param_2 != 0x1b &&
       (iVar3 = props_requireInt(param_1,(int *)param_4,(int *)&local_64), iVar3 == 0))))))
  goto LAB_6806f46a;
  pvVar6 = local_64;
  pvVar1 = DAT_6818e370;
  switch(param_2) {
  case 1:
    if (param_3 != 0) {
      *(uint *)(iVar8 + 0x1c0) = (uint)(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 0x1c0);
    break;
  case 2:
    if (param_3 != 0) {
      *(void **)(iVar8 + 100) = local_64;
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 100);
    break;
  case 3:
    if (param_3 != 0) {
      Ordinal_52(*(int *)(iVar8 + 0x20),(uint)(local_64 != (void *)0x0));
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)Ordinal_176(*(int *)(iVar8 + 0x20));
    break;
  case 4:
    if (param_3 != 0) {
      *(void **)(iVar8 + 0x30) = local_64;
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 0x30);
    break;
  case 5:
    if (param_3 != 0) {
      local_65 = (char)local_64;
      lingo_setDisplayFlag(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),&local_65,2);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    lingo_getDisplayFlag(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),&local_65,2);
    local_6c = (void *)(int)local_65;
    break;
  case 6:
    local_6c = (void *)events_setMiawNetRef(iVar8);
    if (param_3 != 0) {
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      if (local_64 != local_6c) {
        events_getMiawRenderRef(iVar8);
        pvVar6 = local_64;
        pvVar1 = DAT_6818e370;
      }
      goto switchD_6806ef11_caseD_23;
    }
    break;
  case 7:
    iVar8 = events_setMiawNetRef(iVar8);
    pvVar6 = (void *)(uint)(1 < iVar8);
    pvVar1 = DAT_6818e370;
    goto switchD_6806ef11_caseD_23;
  case 8:
    if (param_3 != 0) {
      *(uint *)(iVar8 + 0x1a4) = (uint)(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 0x1a4);
    break;
  case 9:
    if (param_3 != 0) {
      Ordinal_53(*(int *)(iVar8 + 0x20),(uint)(local_64 != (void *)0x0));
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)Ordinal_178(*(int *)(iVar8 + 0x20));
    break;
  case 10:
    local_6c = DAT_6818e370;
    pvVar6 = local_64;
    pvVar1 = local_64;
    if (param_3 != 0) goto switchD_6806ef11_caseD_23;
    break;
  case 0xb:
    pvVar6 = (void *)0x0;
    goto switchD_6806ef11_caseD_23;
  case 0xc:
    pvVar6 = (void *)(uint)(*(int *)(iVar8 + 0x188) != 0);
    goto switchD_6806ef11_caseD_23;
  case 0xd:
    pvVar6 = *(void **)(iVar5 + 0x2c);
    goto switchD_6806ef11_caseD_23;
  case 0xe:
    iVar8 = sprites_getChannelRef(param_1);
    pvVar6 = (void *)(iVar8 - *(int *)(iVar5 + 0x34));
    pvVar1 = DAT_6818e370;
    goto switchD_6806ef11_caseD_23;
  case 0xf:
    iVar8 = *(int *)(iVar5 + 0x34);
    if (*(int *)(iVar5 + 0x34) < *(int *)(iVar5 + 0x38)) {
      iVar8 = *(int *)(iVar5 + 0x38);
    }
    if (iVar8 < *(int *)(iVar5 + 0x3c)) {
      iVar8 = *(int *)(iVar5 + 0x3c);
    }
    iVar5 = sprites_getChannelRef(param_1);
    pvVar6 = (void *)(iVar5 - iVar8);
    pvVar1 = DAT_6818e370;
    goto switchD_6806ef11_caseD_23;
  case 0x10:
    pvVar6 = *(void **)(iVar5 + 0x30);
    goto switchD_6806ef11_caseD_23;
  case 0x11:
    iVar8 = sprites_getChannelRef(param_1);
    pvVar6 = (void *)(iVar8 - *(int *)(iVar5 + 0x38));
    pvVar1 = DAT_6818e370;
    goto switchD_6806ef11_caseD_23;
  case 0x12:
    iVar8 = sprites_getChannelRef(param_1);
    pvVar6 = (void *)(iVar8 - *(int *)(iVar5 + 0x3c));
    pvVar1 = DAT_6818e370;
    goto switchD_6806ef11_caseD_23;
  case 0x13:
    iVar5 = sprites_getChannelRef(param_1);
    if (param_3 != 0) {
      iVar5 = iVar5 - (int)local_64;
LAB_6806f0de:
      *(int *)(iVar8 + 0x68) = iVar5;
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)(iVar5 - *(int *)(iVar8 + 0x68));
    break;
  case 0x14:
    pvVar6 = (void *)0x1;
    goto switchD_6806ef11_caseD_23;
  case 0x15:
    if (param_3 != 0) {
      if (local_64 == (void *)0x0) {
        iVar5 = Ordinal_142(*(int *)(iVar8 + 0x20),*(byte **)(iVar8 + 0x28));
        if (iVar5 != 0) {
          (*(unsigned int *)((char *)&local_60 + 0)) = 0;
          (*(unsigned int *)((char *)&local_60 + 4)) = 0;
          local_58 = 0;
          local_54 = 0;
          local_50 = 0;
          local_4c = 0;
          Ordinal_360(*(int **)(iVar8 + 0x20),*(undefined4 ****)(iVar8 + 0x28),5,(double *)&local_60
                     );
          crt_stepScriptOnce(param_1,(uint)local_60);
        }
        *(uint *)(iVar8 + 0x60) = (*(int *)(iVar8 + 0x1d8) != 0) - 2;
        Ordinal_48(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28));
        Ordinal_1903();
        scoreEngine_dispatchExitFrame(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28));
        Ordinal_1042();
        pvVar6 = local_64;
        pvVar1 = DAT_6818e370;
      }
      else {
        uVar4 = Ordinal_58(*(int *)(iVar8 + 0x20),*(byte **)(iVar8 + 0x28));
        *(undefined4 *)(iVar8 + 0x60) = uVar4;
        *(undefined4 *)(iVar8 + 0x1d8) = *(undefined4 *)(iVar8 + 0x1dc);
        *(undefined4 *)(iVar8 + 0x1b4) = 1;
        Ordinal_1905();
        scoreEngine_dispatchPrepareFrame(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28));
        Ordinal_1042();
        pvVar6 = local_64;
        pvVar1 = DAT_6818e370;
      }
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)(uint)(-1 < *(int *)(iVar8 + 0x60));
    break;
  case 0x16:
    bVar2 = media_queryXtraService();
    pvVar6 = (void *)(uint)bVar2;
    pvVar1 = DAT_6818e370;
    goto switchD_6806ef11_caseD_23;
  case 0x17:
    if (param_3 == 0) {
      local_64 = (void *)0x0;
    }
    pvVar6 = local_64;
    if ((*(int *)(iVar8 + 0x78) == 2) &&
       (iVar5 = Ordinal_374(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),*(int *)(iVar8 + 0x7c),2,
                            (double *)local_48), pvVar6 = local_64, pvVar1 = DAT_6818e370,
       iVar5 != 0)) {
      events_setMiawRenderRef(local_48[0]);
      if (param_3 == 0) {
        local_64 = local_6c;
        iVar8 = Ordinal_294(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),local_48[0],0x70,
                            (uint *)&local_60);
        local_6c = local_64;
        if (iVar8 != 0) {
          local_6c = (void *)xtra_getTextBlockRef((uint)local_60);
        }
        break;
      }
      iVar5 = Ordinal_294(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),local_48[0],0x70,
                          (uint *)&local_60);
      if (iVar5 != 0) {
        local_64 = (void *)xtra_getTextBlockSize((uint)local_60,(int)local_64);
      }
      if ((int)local_64 < (int)local_70) {
        local_64 = local_70;
      }
      media_registerAsset(*(int *)(iVar8 + 0x20),*(byte **)(iVar8 + 0x28),local_48[0],(int)local_64);
      media_registerAssetWithData(*(int *)(iVar8 + 0x20),*(byte **)(iVar8 + 0x28),local_48[0],local_70,local_64);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
    }
    goto switchD_6806ef11_caseD_23;
  case 0x18:
    if (param_3 == 0) {
      local_64 = (void *)0x0;
    }
    pvVar6 = local_64;
    if ((*(int *)(iVar8 + 0x78) == 2) &&
       (iVar5 = Ordinal_374(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),*(int *)(iVar8 + 0x7c),2,
                            (double *)local_48), pvVar6 = local_64, pvVar1 = DAT_6818e370,
       iVar5 != 0)) {
      events_setMiawRenderRef(local_48[0]);
      if (param_3 == 0) {
        local_64 = local_6c;
        iVar8 = Ordinal_294(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),local_48[0],0x70,
                            (uint *)&local_60);
        local_6c = local_64;
        if (iVar8 != 0) {
          local_6c = (void *)xtra_getTextBlockRef((uint)local_60);
        }
        break;
      }
      iVar5 = Ordinal_294(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),local_48[0],0x70,
                          (uint *)&local_60);
      if (iVar5 != 0) {
        local_64 = (void *)xtra_getTextBlockSize((uint)local_60,(int)local_64);
      }
      if ((int)local_70 < (int)local_64) {
        local_70 = local_64;
        media_registerAsset(*(int *)(iVar8 + 0x20),*(byte **)(iVar8 + 0x28),local_48[0],(int)local_64);
      }
      media_registerAssetWithData(*(int *)(iVar8 + 0x20),*(byte **)(iVar8 + 0x28),local_48[0],local_64,local_70);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
    }
    goto switchD_6806ef11_caseD_23;
  case 0x19:
    if (param_3 != 0) {
      Ordinal_157(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),(uint)(local_64 == (void *)0x0));
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    Ordinal_158(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),&local_6c);
    local_6c = (void *)(uint)(local_6c == (void *)0x0);
    break;
  case 0x1a:
    if (param_3 != 0) {
      Ordinal_1902(local_64);
      Ordinal_108(*(int *)(iVar8 + 0x20),0x16,(undefined4 *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    Ordinal_1901(&local_6c);
    break;
  case 0x1b:
    if (param_3 != 0) {
      iVar5 = props_coerceAndReturnBool(param_1,param_4,local_74);
      if (iVar5 == 0) {
        Ordinal_250(*(int *)(iVar8 + 0x20),(int *)local_74);
        Ordinal_104(*(int *)(iVar8 + 0x20),0x1000);
        pvVar6 = local_64;
        pvVar1 = DAT_6818e370;
      }
      else {
        props_setErrorAndReturn(param_1,7);
        pvVar6 = local_64;
        pvVar1 = DAT_6818e370;
      }
      goto switchD_6806ef11_caseD_23;
    }
    Ordinal_251(*(int *)(iVar8 + 0x20),local_74);
    if (local_71 != '\0') {
      Ordinal_72(*(int *)(iVar8 + 0x20),(undefined2 *)local_74,0);
    }
    *param_4 = 4;
    param_4[1] = (uint)local_74[0];
    local_6c = local_64;
    break;
  case 0x1c:
    if (param_3 != 0) {
      *(uint *)(iVar8 + 0x18c) = (uint)(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 0x18c);
    break;
  case 0x1d:
    if (param_3 != 0) {
      Ordinal_161(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28),(int)local_64);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)Ordinal_162(*(int *)(iVar8 + 0x20),*(int *)(iVar8 + 0x28));
    break;
  case 0x1e:
    if (param_3 != 0) {
      *(uint *)(iVar8 + 400) = (uint)(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 400);
    break;
  case 0x1f:
    if (param_3 != 0) {
      *(void **)(iVar8 + 0x70) = local_64;
      iVar5 = sprites_getChannelRef(param_1);
      goto LAB_6806f0de;
    }
    local_6c = *(void **)(iVar8 + 0x70);
    break;
  case 0x20:
    if (param_3 != 0) {
      *(uint *)(iVar8 + 0x194) = (uint)(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 0x194);
    break;
  case 0x21:
    if (param_3 != 0) {
      *(uint *)(iVar8 + 0x198) = (uint)(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = *(void **)(iVar8 + 0x198);
    break;
  case 0x22:
    iVar5 = sprites_getChannelRef(param_1);
    if (param_3 != 0) {
      *(int *)(iVar8 + 0x6c) = iVar5 - (int)local_64;
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)(iVar5 - *(int *)(iVar8 + 0x6c));
    break;
  default:
    goto switchD_6806ef11_caseD_23;
  case 0x24:
    pvVar6 = (void *)Ordinal_1979();
    pvVar1 = DAT_6818e370;
switchD_6806ef11_caseD_23:
    DAT_6818e370 = pvVar1;
    local_6c = pvVar6;
    if (param_3 != 0) goto LAB_6806f46a;
    break;
  case 0x25:
    if (param_3 != 0) goto LAB_6806f46a;
    piVar7 = (int *)Ordinal_555(*(int *)(iVar8 + 0x20));
    local_6c = (void *)0x0;
    local_64 = (void *)0x0;
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7);
      iVar8 = media_iterateSpriteCallbacks((undefined4 *)&DAT_681761c8);
      local_6c = local_64;
      if (iVar8 != 0) {
        local_6c = (void *)0x1;
      }
    }
    break;
  case 0x26:
    if (param_3 != 0) {
      sprites_getWindowHandle(param_1,(uint)(local_64 != (void *)0x0));
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)sprites_getStageRef(param_1);
    break;
  case 0x27:
    if (param_3 != 0) {
      Ordinal_1936(local_64 != (void *)0x0);
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)Ordinal_1937();
    break;
  case 0x28:
    if (param_3 != 0) {
      scoreEngine_invokeCallback(*(int *)(iVar8 + 0x20),(uint)(local_64 != (void *)0x0));
      pvVar6 = local_64;
      pvVar1 = DAT_6818e370;
      goto switchD_6806ef11_caseD_23;
    }
    local_6c = (void *)scoreEngine_unregisterCallback(*(int *)(iVar8 + 0x20));
  }
  if (param_2 != 0x1b) {
    *param_4 = 4;
    param_4[1] = (uint)local_6c;
  }
LAB_6806f46a:
  return 0;
}



// ============================================================
// Function: events_getMiawActiveFlag (events_getMiawActiveFlag)
// Address: 6806f710
// Size: 26 bytes
// Params: uint param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawActiveFlag(uint param_1,int param_2,uint *param_3)
{
  events_setWindowProperty(param_1,param_2,1,param_3);
  return 0;
}




// ============================================================
// Function: events_setMiawActiveFlag (events_setMiawActiveFlag)
// Address: 6806f730
// Size: 26 bytes
// Params: uint param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawActiveFlag(uint param_1,int param_2,uint *param_3)
{
  int local_c;
  events_setWindowProperty(param_1,param_2,0,param_3);
  return 0;
}



// ============================================================
// Function: events_getMiawDisplayMode (events_getMiawDisplayMode)
// Address: 6806f750
// Size: 467 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_getMiawDisplayMode(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  uint local_80 [6];
  uint local_68 [6];
  uint local_50;
  int local_4c;
  uint local_38 [6];
  uint local_20;
  int local_1c;
  uint local_8;
  
  Ordinal_1130(local_68,0x18);
  Ordinal_1130(local_80,0x18);
  local_1c = 0;
  local_20 = 0;
  local_80[0] = 0;
  local_68[0] = 0;
  if (*(short *)(param_1 + 6) != 0) {
    uVar1 = Ordinal_362(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),
                        (undefined4 *)(param_1 + 4));
    iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,2,local_38);
    if ((iVar2 != 0) && ((local_38[0] == 1 || (local_38[0] == 0xd)))) {
      iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,0x3f,local_38)
      ;
      if ((iVar2 != 0) && (local_38[0] == 1)) {
        iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,0x3c,
                            &local_20);
        if (iVar2 != 0) {
          iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,0x3b,
                              local_68);
          if (iVar2 != 0) {
            iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,5,
                                &local_50);
            if (iVar2 != 0) {
              local_20 = local_20 - local_50;
              local_1c = local_1c - local_4c;
              if ((0x10 < (int)local_20) || (0x10 < local_1c)) {
                local_20 = 8;
                local_1c = 8;
              }
              if (*(short *)(param_1 + 10) != 0) {
                uVar1 = Ordinal_362(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),
                                    (undefined4 *)(param_1 + 8));
                iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,2,
                                    local_38);
                if ((iVar2 != 0) && ((local_38[0] == 1 || (local_38[0] == 0xd)))) {
                  iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,
                                      0x3f,local_38);
                  if ((iVar2 != 0) && (local_38[0] == 1)) {
                    Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,0x3b,
                                local_80);
                  }
                }
              }
              Ordinal_1761(&local_20,local_68[0],local_80[0]);
            }
          }
        }
      }
    }
  }
  Ordinal_1653(local_68);
  Ordinal_1653(local_80);
  return 0;
}



// ============================================================
// Function: events_setMiawDisplayMode (events_setMiawDisplayMode)
// Address: 6806f930
// Size: 151 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_setMiawDisplayMode(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 local_24;
  int *local_20 [6];
  uint local_8;
  
  local_24 = 0;
  if (*(short *)(param_1 + 6) != 0) {
    uVar1 = Ordinal_362(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),
                        (undefined4 *)(param_1 + 4));
    iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,2,
                        (uint *)local_20);
    if ((((iVar2 != 0) && (local_20[0] == (int *)0xf)) &&
        (iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),uVar1,0x35,
                             (uint *)local_20), iVar2 != 0)) && (local_20[0] != (int *)0x0)) {
      media_queryAudioInterface(*(int *)(unaff_ESI + 0x20),local_20[0],&local_24);
      (**(code **)(*local_20[0] + 8))(local_20[0]);
    }
  }
  return 0;
}



// ============================================================
// Function: events_getMiawStageInfo (events_getMiawStageInfo)
// Address: 6806f9d0
// Size: 96 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawStageInfo(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_165(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)0x0);
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0xf4))) {
    iVar2 = iVar1 + param_2 * 0x34;
    *param_3 = *(undefined4 *)(iVar1 + 0x14 + param_2 * 0x34);
    param_3[1] = *(undefined4 *)(iVar2 + 0x18);
    param_3[2] = *(undefined4 *)(iVar2 + 0x1c);
    return 0;
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  return 0;
}



// ============================================================
// Function: events_getWindowInfo (FUN_6806fa30)
// Address: 6806fa30
// Size: 638 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getWindowInfo(int param_1,int param_2,int *param_3)
{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int *local_c [2];
  
  iVar5 = param_2;
  local_c[0] = (int *)0x0;
  local_10 = 1;
  piVar2 = *(int **)(*(int *)(param_1 + 8) + 4);
  if (param_2 < 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0xf4) < param_2) {
    return 0;
  }
  iVar4 = Ordinal_165(piVar2[8],piVar2[10],(undefined4 *)0x0);
  piVar1 = (int *)(iVar4 + 0x14 + iVar5 * 0x34);
  if (*(int *)(*piVar2 + 0x648) != 0) {
    lingo_getMiscState(*(int *)(*piVar2 + 0x648));
  }
  piVar3 = param_3;
  if (*(short *)((int)param_3 + 6) < 1) {
    if (((piVar1[3] == 2) || (piVar1[3] == 4)) && ((int *)piVar1[4] != (int *)0x0)) {
      local_10 = piVar1[3];
      local_c[0] = (int *)piVar1[4];
    }
    *piVar1 = *param_3;
    piVar1[1] = param_3[1];
    piVar1[2] = param_3[2];
  }
  else if (piVar1[3] == 2) {
    if ((((piVar1[4] != 0) || ((short)param_3[1] != (short)piVar1[1])) ||
        (*(short *)((int)param_3 + 6) != *(short *)((int)piVar1 + 6))) ||
       (((short)param_3[2] != (short)piVar1[2] ||
        (*(short *)((int)param_3 + 10) != *(short *)((int)piVar1 + 10))))) goto LAB_6806fadf;
  }
  else {
    if (piVar1[3] == 4) {
LAB_6806fadf:
      local_c[0] = (int *)piVar1[4];
      local_10 = piVar1[3];
    }
    iVar5 = events_getMiawDisplayMode((int)param_3);
    piVar1[4] = iVar5;
    piVar1[3] = 2;
    if (iVar5 == 0) {
      iVar5 = events_setMiawDisplayMode((int)piVar3);
      piVar1[4] = iVar5;
      piVar1[3] = 4;
    }
    if (piVar1[4] != 0) {
      *piVar1 = *piVar3;
      piVar1[1] = piVar3[1];
      piVar1[2] = piVar3[2];
      *piVar1 = -100;
      goto LAB_6806fbfc;
    }
    *piVar1 = -1;
    piVar1[1] = 0;
    piVar1[2] = 0;
  }
  switch(*piVar1) {
  case 1:
    piVar1[4] = 3;
    piVar1[3] = 1;
    break;
  case 2:
    piVar1[4] = 2;
    piVar1[3] = 1;
    break;
  case 3:
    piVar1[4] = 7;
    piVar1[3] = 1;
    break;
  case 4:
    piVar1[4] = 4;
    piVar1[3] = 1;
    break;
  default:
    piVar1[4] = DAT_681956e0;
    piVar1[5] = *piVar1;
    piVar1[3] = 3;
    break;
  case 200:
    piVar1[4] = 6;
    piVar1[3] = 1;
    break;
  case -1:
  case 0:
    piVar1[4] = 1;
    piVar1[3] = 1;
  }
LAB_6806fbfc:
  if (0 < param_2) {
    iVar5 = 1;
    if ((*piVar3 == 0) && (*(short *)((int)piVar3 + 6) == 0)) {
      iVar5 = 0;
    }
    events_setCastSlotData((int)piVar2,piVar2[10],param_2,3,iVar5);
    if (iVar5 == 0) {
      piVar2[0x6b] = 0;
      Ordinal_377(piVar2[8],piVar2[10],&param_1,&param_2);
      iVar5 = param_1;
      if (param_1 <= param_2) {
        do {
          iVar4 = events_copyCastMember((int)piVar2,piVar2[10],iVar5,3);
          if (iVar4 != 0) goto LAB_6806fc69;
          iVar5 = iVar5 + 1;
        } while (iVar5 <= param_2);
      }
    }
    else {
LAB_6806fc69:
      piVar2[0x6b] = 1;
    }
  }
  events_updateCursorShape(piVar2);
  if (local_10 != 2) {
    if ((local_10 == 4) && (local_c[0] != (int *)0x0)) {
      media_dispatchDestroy(piVar2[8],local_c[0]);
    }
    return 0;
  }
  Ordinal_1762(local_c);
  return 0;
}



// ============================================================
// Function: events_configureMiawStage (events_configureMiawStage)
// Address: 6806fda0
// Size: 55 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_configureMiawStage(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x4c) <= param_2) {
    iVar2 = Ordinal_58(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28));
    if (*(int *)(iVar1 + 0x48) != iVar2) {
      *(int *)(iVar1 + 0x48) = iVar2;
      *(int *)(iVar1 + 0x4c) = param_2 + param_3;
    }
  }
  return 0;
}



// ============================================================
// Function: events_getMiawStageColor (events_getMiawStageColor)
// Address: 6806fde0
// Size: 46 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawStageColor(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (*(int **)(param_1 + 8))[1];
  iVar2 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  iVar3 = sprites_getChannelRef(param_1);
  *(int *)(iVar2 + 0x34) = iVar3;
  *(int *)(iVar2 + 0x38) = iVar3;
  *(int *)(iVar2 + 0x3c) = iVar3;
  *(int *)(iVar1 + 0x6c) = iVar3;
  return 0;
}



// ============================================================
// Function: events_setMiawStageColor (events_setMiawStageColor)
// Address: 6806fe10
// Size: 68 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setMiawStageColor(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_2;
  uVar2 = 0;
  if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) {
    uVar2 = 1;
  }
  if (iVar1 == 10) {
    if (((char)param_2[6] == '/') && ((*(byte *)(param_2 + 5) & 0x10) != 0)) {
      uVar2 = 1;
    }
    if ((char)param_2[6] == '5') {
      uVar2 = 1;
    }
  }
  return uVar2;
}



// ============================================================
// Function: events_getMiawStageDepth (events_getMiawStageDepth)
// Address: 6806fe60
// Size: 34 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool events_getMiawStageDepth(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = stage_forEachEvent(in_EAX,-1,events_setMiawStageColor);
  return iVar1 != 0;
}



// ============================================================
// Function: events_setMiawStageDepth (events_setMiawStageDepth)
// Address: 6806fe90
// Size: 92 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int events_setMiawStageDepth(int param_1,undefined4 param_2)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  
  while( true ) {
    do {
      iVar2 = Ordinal_145(*(int *)(param_1 + 0x20),0,param_2);
      if (iVar2 != 1) {
        return 0;
      }
      iVar2 = Ordinal_1541();
    } while ((uint)(iVar2 - _DAT_6819635c) < 0x65);
    _DAT_6819635c = iVar2;
    bVar1 = events_getMiawStageDepth();
    if (CONCAT31(extraout_var,bVar1) != 0) break;
    iVar2 = events_getEditRef(*(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 8) + 0x14));
    if (iVar2 != 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_resetMiawChannel (events_resetMiawChannel)
// Address: 6806fef0
// Size: 90 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resetMiawChannel(int param_1)
{
  int iVar1;
  
  iVar1 = (*(int **)(param_1 + 8))[1];
  if ((*(int *)(iVar1 + 0x1c4) == 0) &&
     (*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 100) == 0)) {
    Ordinal_108(*(int *)(iVar1 + 0x20),0x13,(undefined4 *)0x0);
    lingo_mutateChannel(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),1);
    lingo_destroyPlaybackState(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28));
    events_setMiawStageDepth(iVar1,0);
  }
  return 0;
}




// ============================================================
// Function: events_getMiawStageRect (events_getMiawStageRect)
// Address: 6806ff50
// Size: 68 bytes
// Params: int param_1, undefined2 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getMiawStageRect(int param_1,undefined2 param_2)
{
  int iVar1;
  undefined2 local_14 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  scoreEngine_getPropertyData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),4,(byte *)local_14);
  return 0;
}



// ============================================================
// Function: events_setMiawStageRect (events_setMiawStageRect)
// Address: 6806ffa0
// Size: 102 bytes
// Params: int param_1, int param_2, undefined1 param_3, undefined1 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMiawStageRect(int param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)
{
  int iVar1;
  byte local_14;
  undefined1 local_13;
  undefined1 local_12;
  uint local_10;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 != 0) {
    local_14 = (byte)param_2;
    local_13 = param_3;
    local_12 = param_4;
    local_10 = (uint)(param_5 != 0);
    scoreEngine_getPropertyData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),1,&local_14);
  }
  return 0;
}




