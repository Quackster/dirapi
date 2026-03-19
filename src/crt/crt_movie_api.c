// Module: crt
// Topic: Movie control API exports (open/close, pause/resume, events, linked movies)
// Address range: 0x680098C0 - 0x6800AF20
// Functions (30):
//   Ordinal_1111 - Ordinal_83 (movie tick, open/close, script exec, frame step)
//   Ordinal_85 - Ordinal_97 (dispose, save, load, dispatch event, idle tick)
//   Ordinal_81 - crt_copyMovieFields (session teardown, create, image data helpers)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x680098c0 - 0x68009fe0
// Functions (12):
//   Ordinal_1111
//   Ordinal_921
//   Ordinal_922
//   Ordinal_93
//   Ordinal_100
//   Ordinal_94
//   Ordinal_95
//   Ordinal_79
//   Ordinal_96
//   Ordinal_98
//   core_openMovie
//   Ordinal_83

// ============================================================
// Function: dirapi_Ordinal_1111 (exported as Ordinal_1111)
// Address: 680098c0
// Size: 42 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Validates a player and dispatches an edit command to its stage.
 *
 * @param param_1  Player context pointer.
 * @return Always returns 0.
 */
int dirapi_Ordinal_1111(int param_1)
{
  Player *player = (Player *)param_1;

                    /* 0x98c0  1111   */
  int valid = Ordinal_1110(param_1);
  if (valid != 0) {
    int *stage = (int *)Ordinal_118(player->scoreHandle);
    sprites_handleEditCommand2(stage, 0x15d);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_921
// Address: 680098f0
// Size: 95 bytes
// Params: int * param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Toggles the player's input lock state and updates stage input accordingly.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  If zero, locks input; if nonzero, unlocks input.
 * @return True if input was previously locked (pausedFlag was 0), false otherwise.
 */
bool Ordinal_921(int *param_1, int param_2)
{
  Player *player = (Player *)param_1;

                    /* 0x98f0  921   */
  if (player == NULL) return true;

  bool wasLocked = (player->pausedFlag == 0);
  uint newLockState = (uint)(param_2 == 0);

  if (newLockState != player->pausedFlag) {
    uint inputEnabled = (uint)(newLockState == 0);
    int *stage = (int *)Ordinal_118(player->scoreHandle);
    stage_setInputEnabled(stage, inputEnabled);
    if (player->valid) {
      player->pausedFlag = newLockState;
    }
    Ordinal_108(player->scoreHandle, 0x1f, NULL);
  }
  return wasLocked;
}



// ============================================================
// Function: Ordinal_922
// Address: 68009950
// Size: 30 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Checks whether the player's input is currently unlocked (not paused).
 *
 * @param param_1  Pointer to the Player object.
 * @return True if input is unlocked (pausedFlag is 0), false if NULL or locked.
 */
bool Ordinal_922(int param_1)
{
  Player *player = (Player *)param_1;

                    /* 0x9950  922   */
  if (player == NULL) return false;
  return player->pausedFlag == 0;
}



// ============================================================
// Function: Ordinal_93
// Address: 68009970
// Size: 98 bytes
// Params: int * param_1, int param_2, char * param_3, undefined4 * param_4, byte param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Executes a Lingo script on the player's score, optionally returning a result.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  If nonzero, allows execution even when paused.
 * @param param_3  Script text to execute.
 * @param param_4  If non-NULL, receives the script return value.
 * @param param_5  Script execution flags.
 * @return Always returns 0.
 */
int Ordinal_93(int *param_1,int param_2,char *param_3,undefined4 *param_4,byte param_5)
{
  Player *player = (Player *)param_1;
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;

                    /* 0x9970  93   */
  if (player == NULL || !player->valid) return 0;

  if (param_4 == NULL) {
    if (player->pausedFlag == 0 && param_2 == 0) return 0;
    lingo_runScript(player->scoreHandle,param_3,param_5);
    return 0;
  }

  bVar1 = stage_checkPlugins(*(int *)((int)player->hostContext + 0x14));
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = lingo_runScriptWithResult(player->scoreHandle,param_3,param_5);
    *param_4 = uVar2;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_100
// Address: 680099e0
// Size: 38 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Queries the player's score for its current state.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Receives the score state value.
 * @return The score state, or 0 if the player is inactive.
 */
undefined4 Ordinal_100(int *param_1,undefined4 *param_2)

{
  Player *player = (Player *)param_1;

                    /* 0x99e0  100   */
  if (player == NULL || !player->valid) return 0;
  return Ordinal_45(player->scoreHandle,param_2);
}



// ============================================================
// Function: Ordinal_94
// Address: 68009a10
// Size: 30 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Returns and clears the player's exit code.
 *
 * @param param_1  Pointer to the Player object.
 * @return The exit code that was set, or 0 if the player is inactive.
 */
int Ordinal_94(int *param_1)

{
  Player *player = (Player *)param_1;
  int exitCode;

                    /* 0x9a10  94   */
  if (player == NULL || !player->valid) return 0;

  exitCode = player->exitCode;
  player->exitCode = 0;
  return exitCode;
}



// ============================================================
// Function: Ordinal_95
// Address: 68009a30
// Size: 52 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Forces a stage refresh by updating the score and redrawing the display.
 *
 * @param param_1  Pointer to the Player object.
 * @return Always returns 0.
 */
int Ordinal_95(int *param_1)
{
  Player *player = (Player *)param_1;
  int stageRef;

                    /* 0x9a30  95   */
  if (player == NULL || !player->valid) return 0;

  Ordinal_152(player->scoreHandle,0x3400,1);
  stageRef = Ordinal_118(player->scoreHandle);
  stage_refreshDisplay(stageRef);
  return 0;
}



// ============================================================
// Function: Ordinal_79
// Address: 68009a70
// Size: 98 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Seeks the player's score by a relative frame offset, clamping to valid range.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Relative frame offset (positive = forward, negative = backward).
 * @return Always returns 0.
 */
int Ordinal_79(int *param_1,int param_2)
{
  Player *player = (Player *)param_1;
  bool bVar1;
  int iVar2;
  int currentFrame;

                    /* 0x9a70  79   */
  if (player == NULL || !player->valid) return 0;

  iVar2 = Ordinal_45(player->scoreHandle,NULL);
  if (iVar2 == 0) return 0;

  currentFrame = Ordinal_58(player->scoreHandle,(byte *)NULL);
  iVar2 = Ordinal_154(player->scoreHandle,(byte *)NULL);
  currentFrame = currentFrame + param_2;
  if (currentFrame > 0) {
    if (iVar2 < currentFrame) {
      currentFrame = 1;
    }
  }
  else {
    currentFrame = iVar2;
  }
  Ordinal_49(player->scoreHandle,currentFrame,0x1000);
  return 0;
}



// ============================================================
// Function: Ordinal_96
// Address: 68009ae0
// Size: 79 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Pauses playback if the player is active and not already paused or in error state.
 *
 * @param param_1  Pointer to the Player object.
 * @return Always returns 0.
 */
int Ordinal_96(int *param_1)
{
  Player *player = (Player *)param_1;

                    /* 0x9ae0  96   */
  if (player == NULL || !player->valid) return 0;
  if ((short)player->playerState == 2) return 0;
  if ((short)player->playerState == 1) return 0;

  Ordinal_46(player->scoreHandle,0);
  *(undefined2 *)&player->playerState = 1;
  score_onPaused(player->scoreHandle);
  Ordinal_108(player->scoreHandle,0,NULL);
  return 0;
}



// ============================================================
// Function: Ordinal_98
// Address: 68009b30
// Size: 199 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Resumes playback from a paused state, re-enabling score callbacks and stage updates.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  If nonzero, also updates stage channels before resuming.
 * @return Always returns 0.
 */
int Ordinal_98(int *param_1,int param_2)
{
  Player *player = (Player *)param_1;
  int stageRef;
  undefined4 local_c [2];

                    /* 0x9b30  98   */
  if (player == NULL || !player->valid) return 0;
  if ((short)player->playerState != 1) return 0;

  if (player->pausedFlag == 0) {
    stageRef = Ordinal_118(player->scoreHandle);
    Ordinal_66(stageRef,1);
    if (param_2 != 0) {
      stageRef = Ordinal_118(player->scoreHandle);
      stage_updateChannels(stageRef);
    }
    scoreEngine_registerCallback(player->scoreHandle);
  }
  lingo_enablePlaybackFlag(player->scoreHandle);
  Ordinal_46(player->scoreHandle,1);
  *(undefined2 *)&player->playerState = 0xffff;
  Ordinal_108(player->scoreHandle,0,NULL);
  local_c[0] = Ordinal_70(player->scoreHandle);
  Ordinal_108(player->scoreHandle,0x11,local_c);
  Ordinal_136(player->scoreHandle,0);
  Ordinal_1845();
  lingo_updateStageDisplay(player->scoreHandle);
  lingo_getMiscState(player->scoreHandle);
  return 0;
}



// ============================================================
// Function: core_openMovie (FUN_68009c00)
// Address: 68009c00
// Size: 978 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Opens a movie: initializes the Lingo runtime, loads cast libraries,
 *        sets up the codec factory, and prepares the global playback state.
 *
 * @param param_1  Movie open flags (bit 5 controls linked mode).
 * @return Always returns 0.
 */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
int core_openMovie(uint param_1)
{
  byte bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined4 *unaff_EBX;
  int unaff_EDI;
  bool bVar9;
  undefined4 local_10bc;
  int local_10b8;
  uint local_10b4;
  int local_10b0;
  int local_10ac;
  undefined1 *local_10a4;
  undefined4 local_109c;
  undefined1 local_1098 [1044];
  undefined4 local_c84;
  undefined1 local_c80 [1044];
  undefined1 local_86c [1024];
  undefined1 local_46c;
  undefined1 local_46b [1023];
  byte local_6c [100];
  uint local_8;
  
  local_10ac = 0;
  local_10b8 = 0;
  local_c84 = 0;
  memset(local_c80,0,0x414);
  local_10b0 = 0;
  local_10b4 = (uint)(*(int *)(unaff_EDI + 0x10) == 0);
  if (unaff_EBX != (undefined4 *)0x0) {
    Ordinal_1130();
    unaff_EBX[3] = unaff_EDI;
    unaff_EBX[7] = param_1;
    if ((param_1 & 0x20) != 0) {
      unaff_EBX[8] = 1;
    }
    piVar2 = Ordinal_112((int)unaff_EBX);
    if (piVar2 != (int *)0x0) {
      puVar3 = stage_createContext((int)unaff_EBX);
      unaff_EBX[5] = puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        if (local_10b4 == 0) {
LAB_68009f01:
          iVar4 = lingo_initLifecycleWrapped((int)unaff_EBX,local_10b4);
          if (iVar4 != 0) {
            local_6c[0] = 0;
            memset(local_6c + 1,0,99);
            (**(code **)(unaff_EDI + 0x74))(local_6c,100);
            pcVar8 = "Author";
            pbVar7 = local_6c;
            do {
              bVar1 = *pbVar7;
              bVar9 = bVar1 < (byte)*pcVar8;
              if (bVar1 != *pcVar8) {
LAB_68009f60:
                iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                goto LAB_68009f65;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar7[1];
              bVar9 = bVar1 < (byte)pcVar8[1];
              if (bVar1 != pcVar8[1]) goto LAB_68009f60;
              pbVar7 = pbVar7 + 2;
              pcVar8 = pcVar8 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_68009f65:
            if (iVar4 == 0) {
              crt_loadCodeHints();
            }
            *unaff_EBX = 1;
            local_10ac = 1;
          }
          if (local_10b8 != 0) goto LAB_68009f87;
        }
        else {
          local_10b8 = 1;
          Ordinal_2330();
          local_10a4 = DAT_68196374;
          local_46c = 0;
          DAT_68196374 = &stack0xffffef58;
          memset(local_46b,0,0x3fe);
          *(undefined4 *)(unaff_EDI + 0x18) = 0;
          iVar4 = Ordinal_1517(DAT_681956e0,4000,&local_46c,0x3ff);
          if (iVar4 != 0) {
            if (*(int *)(unaff_EDI + 0xe0) == 0) {
              if (*(int *)(unaff_EDI + 0x24) == 0) {
                Ordinal_1334(&local_c84,3);
                iVar4 = Ordinal_1351(&local_c84);
                if (iVar4 != 0) goto LAB_68009d84;
              }
LAB_68009d69:
              crt_writeFormatData(unaff_EDI,&local_c84,0);
              Ordinal_1316(&local_c84);
            }
            else {
              Ordinal_1334(&local_c84,2);
              iVar4 = Ordinal_1351(&local_c84);
              if (iVar4 == 0) goto LAB_68009d69;
            }
LAB_68009d84:
            Ordinal_1317(&local_c84,&local_46c);
            Ordinal_1323(&local_c84,local_86c);
            puVar3 = media_createResourceObject();
            *(undefined4 **)(unaff_EDI + 0x18) = puVar3;
            if ((puVar3 != (undefined4 *)0x0) &&
               (iVar4 = Ordinal_2076(puVar3,local_86c,&DAT_68176358,param_1 >> 5 & 2,&local_10bc),
               iVar4 == 0)) {
              Ordinal_1019(local_10bc);
              uVar5 = Ordinal_1038();
              iVar4 = lingo_getGlobalCount();
              if (iVar4 == 0) {
                local_10b0 = 1;
                uVar5 = Ordinal_1038(&LAB_6811d1e0,media_unregisterPixelOpState,media_registerPixelOpState,&LAB_6809ec80,
                                     media_allocPixelOpState,uVar5);
                iVar4 = Ordinal_2071(uVar5);
                if (iVar4 == 0) {
                  uVar5 = Ordinal_1038();
                  iVar4 = Ordinal_1012(uVar5);
                  if ((iVar4 == 0) && (iVar4 = lingo_initGlobalState(), iVar4 != 0)) {
                    iVar4 = 0;
                    local_109c = 0;
                    memset(local_1098,0,0x414);
                    iVar6 = crt_writeFormatData(unaff_EDI,&local_109c,0);
                    while (iVar6 != 0) {
                      Ordinal_1323(&local_109c,&local_46c);
                      uVar5 = Ordinal_1038(&local_46c,5);
                      Ordinal_2070(uVar5);
                      iVar4 = iVar4 + 1;
                      iVar6 = crt_writeFormatData(unaff_EDI,&local_109c,iVar4);
                    }
                    local_10b0 = 0;
                    uVar5 = Ordinal_1038();
                    iVar4 = lingo_getGlobalValue(uVar5);
                    if (iVar4 == 0) {
                      uVar5 = Ordinal_1038();
                      iVar4 = crt_initCodecFactory(uVar5);
                      if (iVar4 == 0) {
                        *(undefined4 *)(unaff_EDI + 0x10) = 1;
                        goto LAB_68009f01;
                      }
                    }
                  }
                }
              }
            }
          }
LAB_68009f87:
          DAT_68196374 = local_10a4;
          Ordinal_2331();
        }
        if (local_10ac != 0) goto LAB_68009fc9;
        if (local_10b0 != 0) {
          uVar5 = Ordinal_1038();
          lingo_getGlobalValue(uVar5);
        }
      }
    }
  }
  core_closeMovie(local_10b4);
LAB_68009fc9:
  return 0;
}



// ============================================================
// Function: Ordinal_83
// Address: 68009fe0
// Size: 19 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Closes the current movie without preserving state.
 *
 * @return Always returns 0.
 */
int Ordinal_83(void)
{
                    /* 0x9fe0  83   */
  core_closeMovie(0);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800a000 - 0x6800a730
// Functions (6):
//   Ordinal_85
//   Ordinal_105
//   Ordinal_88
//   core_dispatchEvent
//   Ordinal_91
//   Ordinal_97

// ============================================================
// Function: Ordinal_85
// Address: 6800a000
// Size: 82 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Disposes the player, releasing its score handle and clearing all state.
 *
 * @param param_1  Pointer to the Player object to dispose.
 * @param param_2  If nonzero, triggers a full teardown including callbacks.
 * @return Always returns 0.
 */
int Ordinal_85(int *param_1,int param_2)
{
  Player *player = (Player *)param_1;
  int scoreHandle;

                    /* 0xa000  85   */
  if (player == NULL) return 0;

  if (player->valid) {
    Ordinal_98(param_1,param_2);
    if (*(int **)((int)player->hostContext + 0x18) == param_1) {
      Ordinal_944(*(int *)((int)player->hostContext + 0x14));
    }
    scoreHandle = player->scoreHandle;
    player->valid = 0;
    if (scoreHandle != 0) {
      player->scoreHandle = 0;
      score_dispose(scoreHandle);
    }
  }
  Ordinal_1130(param_1,0x3c);
  return 0;
}



// ============================================================
// Function: Ordinal_105
// Address: 6800a060
// Size: 78 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Saves the current movie, then refreshes the score and renders the stage.
 *
 * @param param_1  Pointer to the Player object.
 * @return Nonzero on success, 0 if the player is NULL or save failed.
 */
int Ordinal_105(int *param_1)

{
  Player *player = (Player *)param_1;
  int saveResult;
  int stageRef;

                    /* 0xa060  105   */
  if (player == NULL) return 0;

  Ordinal_98(param_1,1);
  saveResult = score_saveMovie(player->scoreHandle);
  if (saveResult != 0) {
    Ordinal_152(player->scoreHandle,0x3400,1);
    stageRef = Ordinal_118(player->scoreHandle);
    stage_renderFrame(stageRef,NULL);
  }
  return saveResult;
}



// ============================================================
// Function: Ordinal_88
// Address: 6800a0b0
// Size: 273 bytes
// Params: int * param_1, int * param_2, int param_3, undefined4 * param_4, undefined1 * param_5, short param_6, int param_7, void * param_8
// Return: int
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Loads a movie into the player, optionally tearing down the current playback context first.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Movie data/path to load.
 * @param param_3  Movie load options.
 * @param param_4  Receives error description on failure, or NULL.
 * @param param_5  Error message buffer, or NULL.
 * @param param_6  Error message buffer length.
 * @param param_7  If nonzero, save current state before loading.
 * @param param_8  Additional context for the load operation.
 * @return Load result code (nonzero on success), or 0 on failure.
 */
int Ordinal_88(int *param_1,int *param_2,int param_3,undefined4 *param_4,undefined1 *param_5,
              short param_6,int param_7,void *param_8)

{
  Player *player = (Player *)param_1;
  int iVar3;
  int stageRef;
  undefined4 uVar5;
  int *movieData;
  undefined4 local_10;
  undefined4 local_c;

                    /* 0xa0b0  88   */
  if (player == NULL) {
    crt_resetPlaybackTimer();
    return 0;
  }

  iVar3 = lingo_teardownPlaybackContext(player->scoreHandle);
  if (iVar3 == 0) {
    Ordinal_98(param_1,1);
    if (param_7 != 0) {
      player->busyFlag = 1;
      Ordinal_1130(&local_10,0xc);
      local_10 = 1;
      local_c = 4;
      Ordinal_1763(&local_10,(int *)((int)player + 0x30));
      Ordinal_1764(1);
    }
  }
  movieData = param_2;
  iVar3 = score_loadMovie(player->scoreHandle,param_2,param_3,param_8);
  if (iVar3 != 0 && iVar3 != 2) {
    Ordinal_152(player->scoreHandle,0x2400,1);
    Ordinal_251(player->scoreHandle,(undefined1 *)&param_1);
    Ordinal_250(player->scoreHandle,(int *)&param_1);
    stageRef = Ordinal_118(player->scoreHandle);
    stage_renderFrame(stageRef,movieData);
    stageRef = Ordinal_118(player->scoreHandle);
    stage_getSpriteApiRef(stageRef,(uint)(iVar3 == 1));
  }
  if (param_5 != NULL && param_4 != NULL && param_6 != 0) {
    uVar5 = Ordinal_120(*(undefined4 **)((int)player->hostContext + 0x10),param_5,(int)param_6);
    *param_4 = uVar5;
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  crt_resetPlaybackTimer();
  return 0;
}



// ============================================================
// Function: core_dispatchEvent (FUN_6800a1d0)
// Address: 6800a1d0
// Size: 936 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/**
 * @brief Dispatches a core event (mouse, keyboard, idle, resize) to the player's
 *        sprite and score subsystems. Handles event type routing via switch.
 *
 * @param param_1  Player context pointer (fastcall: ECX).
 * @param param_2  Event descriptor array (type in [0], data in [1..7]).
 * @return Always returns 0.
 */
int __fastcall core_dispatchEvent(int *param_1, int *param_2)
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *unaff_EBX;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  Ordinal_2330();
  if ((param_1[3] == 0) ||
     (puVar2 = *(undefined4 **)(param_1[3] + 0x20), puVar2 == (undefined4 *)0x0)) {
    local_14 = 0;
  }
  else {
    local_14 = *puVar2;
  }
  local_c = 0;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar3 = lingo_checkState(param_1[3]);
  if (iVar3 != 0) {
    switch(*param_2) {
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 0xb:
      goto switchD_6800a23d_caseD_1;
    default:
      break;
    }
  }
  switch(*param_2) {
  case 1:
  case 5:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 1;
LAB_6800a3f4:
    stage_dispatchSpriteLifecycle(unaff_EBX,param_2);
    goto LAB_6800a3fb;
  case 2:
  case 6:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 1;
    if (param_1[9] == 0) {
      iVar3 = stage_getActiveMovie(*(int *)(param_1[2] + 0x14));
      if ((iVar3 == 0) || (param_2[1] == iVar3)) {
        if ((param_2[1] != 0) && (iVar3 = Ordinal_1808(param_2[1]), iVar3 == 0)) {
          Ordinal_2215(param_2[1]);
        }
        stage_setSpriteTrailMode((int)unaff_EBX,0);
        stage_dispatchSpriteLifecycle(unaff_EBX,param_2);
        stage_setSpriteClickOffset(unaff_EBX,param_2[2],param_2[3]);
      }
      else {
LAB_6800a2d1:
        local_18 = 1;
      }
    }
    goto LAB_6800a2fe;
  case 3:
  case 7:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 1;
    if (param_1[9] == 0) {
      iVar3 = stage_getActiveMovie(*(int *)(param_1[2] + 0x14));
      if ((iVar3 == 0) || (param_2[1] == iVar3)) {
        stage_setSpriteTrailMode((int)unaff_EBX,1);
        goto LAB_6800a3f4;
      }
      local_18 = 1;
    }
LAB_6800a3fb:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 0;
    break;
  case 9:
    if (param_1[9] != 0) break;
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 1;
    stage_setSpriteClickOffset(unaff_EBX,param_2[2],param_2[3]);
    stage_dispatchSpriteLifecycle(unaff_EBX,param_2);
    iVar3 = lingo_getMediaDataOffset(param_1[3]);
    if (iVar3 == 0) {
      stage_syncPalette((int)unaff_EBX);
    }
    local_18 = 1;
    goto LAB_6800a2fe;
  case 10:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 1;
    cVar1 = (char)param_2[6];
    if ((((cVar1 == '5') || ((cVar1 == '/' && ((*(byte *)(param_2 + 5) & 0x10) != 0)))) ||
        (((param_2[7] == 0x51 || (param_2[7] == 0x71)) && ((*(byte *)(param_2 + 5) & 0x10) != 0))))
       || ((cVar1 == 'v' && ((*(byte *)(param_2 + 5) & 8) != 0)))) {
      iVar3 = crt_getMovieState();
      if (iVar3 == 0) {
        Ordinal_98(param_1,1);
        if (((char)param_2[6] != 'v') || ((*(byte *)(param_2 + 5) & 8) == 0)) {
          param_1[6] = 2;
          goto LAB_6800a2d1;
        }
        param_1[6] = 1;
        local_18 = 1;
        goto LAB_6800a2fe;
      }
      sprites_handleEditCommand2(unaff_EBX,0x15d);
    }
    if (param_1[9] == 0) {
      local_18 = stage_updateSpriteEvent(unaff_EBX,param_2,(ushort)*(byte *)(param_2 + 6),param_2[7]);
    }
    goto LAB_6800a2fe;
  case 0xb:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 1;
    if (param_1[9] == 0) {
      local_18 = Ordinal_62((int)unaff_EBX,param_2);
      *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 0;
      break;
    }
LAB_6800a2fe:
    *(undefined4 *)(**(int **)(*unaff_EBX + 4) + 0x1c4) = 0;
    break;
  case 0xd:
    iVar3 = param_2[1];
    iVar4 = crt_getMovieFrameCount((int)param_1);
    if ((iVar3 == iVar4) || (iVar3 = Ordinal_1885(iVar3), iVar3 != 0)) {
      iVar3 = crt_getMovieState();
      if (iVar3 == 0) {
        param_1[6] = 1;
        Ordinal_98(param_1,1);
        local_18 = 1;
      }
      else {
        sprites_handleEditCommand2(unaff_EBX,0x15d);
switchD_6800a23d_caseD_1:
        local_18 = 1;
      }
    }
    break;
  case 0x12:
    iVar3 = stage_getActiveMovie(*(int *)(param_1[2] + 0x14));
    if (iVar3 == 0) {
      if (*(int *)(*(int *)(param_1[2] + 0x18) + 0xc) == param_1[3]) {
        local_18 = 0;
        Ordinal_54(param_1[3],&local_18);
        Ordinal_1815(local_18);
        local_18 = 1;
      }
    }
    else {
      Ordinal_1815(iVar3);
      local_18 = 1;
    }
    break;
  case 0x17:
    if (*(int *)(*(int *)(param_1[2] + 0x18) + 0xc) == param_1[3]) {
      iVar3 = *(int *)(param_1[2] + 0xc);
      uVar5 = (uint)(param_2[6] == 0);
      if (uVar5 != *(uint *)(iVar3 + 0xc)) {
        *(uint *)(iVar3 + 0xc) = uVar5;
        Ordinal_946(unaff_EBX,(uint)(uVar5 == 0));
      }
    }
    break;
  case 0x1e:
    if (param_1[9] == 0) {
      local_18 = stage_handleSpriteResize((int)unaff_EBX,(int)param_2);
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_91
// Address: 6800a5e0
// Size: 325 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Dispatches an event through the player's sprite behavior chain and score engine.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Event descriptor to dispatch.
 * @param param_3  If non-NULL, receives script data context from the event.
 * @return Always returns 0.
 */
int Ordinal_91(int *param_1, int *param_2, undefined4 *param_3)
{
  Player *player = (Player *)param_1;
  bool done;
  bool pluginsActive;
  bool hasBehaviors;
  int result;
  int *stage;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *eventSource;
  int *behaviorTarget;
  int enqueued;
  undefined4 scriptCtx;
  int *savedPlayer;
  undefined4 dispatchResult;
  int eventBuf[10];

                    /* 0xa5e0  91   */
  done = false;
  savedPlayer = param_1;
  dispatchResult = 0;
  enqueued = 0;
  scriptCtx = 0;
  if (player == NULL || player->scoreHandle == 0) goto LAB_6800a631;

  result = lingo_getScriptData(player->scoreHandle, param_2, &scriptCtx);
  if (result != 0) {
    dispatchResult = 1;
    goto LAB_6800a631;
  }

  do {
    stage = (int *)Ordinal_118(player->scoreHandle);
    Ordinal_1130(eventBuf, 0x28);
    if (((Player *)savedPlayer)->pausedFlag == 0 && stage != NULL) {
      pluginsActive = stage_checkPlugins(*(int *)((int)((Player *)savedPlayer)->hostContext + 0x14));
      if (CONCAT31(extraout_var, pluginsActive) != 0) {
        result = stage_enqueueEvent(param_2, stage);
        if (result == 0) goto LAB_6800a6d6;
        break;
      }
      hasBehaviors = stage_dispatchSpriteBehaviors(*(int *)((int)((Player *)savedPlayer)->hostContext + 0x14), eventBuf, &behaviorTarget);
      if (CONCAT31(extraout_var_00, hasBehaviors) == 0) {
        if (enqueued == 0) goto LAB_6800a6d6;
        goto LAB_6800a631;
      }
      if (enqueued == 0) {
        enqueued = stage_enqueueEvent(param_2, stage);
      }
      eventSource = eventBuf;
      stage = behaviorTarget;
    }
    else {
LAB_6800a6d6:
      done = true;
      eventSource = param_2;
    }
    if (((Player *)savedPlayer)->pausedFlag == 0 && stage != NULL &&
       (result = stage_handleBehaviorEvent(stage, eventSource), result != 0)) break;
    if (((short)((Player *)savedPlayer)->playerState != 1 && *eventSource != 0x17) ||
       (dispatchResult = core_dispatchEvent(savedPlayer, eventSource), param_1 = savedPlayer, done)) goto LAB_6800a631;
  } while (true);
  dispatchResult = 1;

LAB_6800a631:
  if (param_3 != NULL) {
    *param_3 = scriptCtx;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_97
// Address: 6800a730
// Size: 452 bytes
// Params: int * param_1, undefined4 param_2, uint * param_3, undefined4 * param_4, undefined1 * param_5, short param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Advances playback by one step: processes idle events, sprite context, and score timing.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Unused.
 * @param param_3  Receives idle time remaining (milliseconds), or NULL.
 * @param param_4  Receives error description, or NULL.
 * @param param_5  Error message buffer, or NULL.
 * @param param_6  Error message buffer length.
 * @return Always returns 0.
 */
int Ordinal_97(int *param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,
               undefined1 *param_5,short param_6)
{
  Player *player = (Player *)param_1;
  undefined3 extraout_var;
  int tickInterval;
  int eventBuf[10];

  if (param_3 != NULL) {
    *param_3 = 0;
  }
  if (player == NULL || !player->valid || (short)player->playerState != 1) {
    if (param_5 != NULL && param_4 != NULL && param_6 != 0) {
      *param_4 = 0;
      *param_5 = 0;
      return 0;
    }
    return 0;
  }

  if (DAT_68195a70 == 0) {
    DAT_68195a70 = 1;
    Ordinal_107(player->scoreHandle);
    DAT_68195a70 = 0;
  }
  int stateResult = lingo_checkState(player->scoreHandle);
  if (stateResult != 0) {
    if (param_3 != NULL) {
      *param_3 = 0x11;
    }
    if (param_5 != NULL && param_4 != NULL && param_6 != 0) {
      *param_4 = 0;
      *param_5 = 0;
      return 0;
    }
    return 0;
  }

  xtra_certNoOp();
  Ordinal_108(player->scoreHandle,0x14,NULL);
  if (player->pausedFlag == 0) {
    int *scoreCtx = (int *)Ordinal_118(player->scoreHandle);
    short spriteResult = stage_initSpriteContext(scoreCtx,param_3);
    bool queueEmpty = stage_isEventQueueEmpty(*(int *)((int)player->hostContext + 0x14));
    if (CONCAT31(extraout_var,queueEmpty) == 0) {
      Ordinal_1130(eventBuf,0x28);
      eventBuf[0] = 0;
      Ordinal_91(param_1,eventBuf,NULL);
    }
    if ((int)spriteResult == 0) {
      Ordinal_98(param_1,1);
    }
  }
  else if (player->idleState == 1) {
    int idleResult = Ordinal_147(player->scoreHandle,param_3);
    if (idleResult == 0) {
      player->idleState = 2;
    }
  }
  else if (player->idleState == 2) {
    int resumeResult = Ordinal_143(player->scoreHandle,(byte *)NULL);
    player->idleState = 0;
    if (resumeResult == 0) {
      Ordinal_98(param_1,1);
    }
  }
  else {
    Ordinal_1540(&tickInterval);
    int tempoResult = Ordinal_145(player->scoreHandle,tickInterval * 2,param_3);
    if (tempoResult == 0) {
      player->idleState = 1;
    }
  }
  if (param_5 != NULL && param_4 != NULL && param_6 != 0) {
    undefined4 errDesc = Ordinal_120(*(undefined4 **)((int)player->hostContext + 0x10),param_5,(int)param_6);
    *param_4 = errDesc;
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800a900 - 0x6800aef0
// Functions (12):
//   Ordinal_81
//   Ordinal_82
//   Ordinal_78
//   Ordinal_84
//   Ordinal_80
//   crt_resolveImageData
//   crt_resolveLinkedImageData
//   crt_resolveImageDataDirect
//   crt_getMovieApiState
//   crt_copyMovieState
//   crt_updateMovieState
//   crt_copyMovieFields

// ============================================================
// Function: Ordinal_81
// Address: 6800a900
// Size: 319 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Tears down the entire runtime context: closes the movie, disposes the stage,
 *        frees codecs, resources, and clears the global context pointer.
 *
 * @param param_1  Pointer to the runtime context to tear down.
 * @return Always returns 0.
 */
int Ordinal_81(int param_1)
{
  if (param_1 == 0) return 0;

  int *ctx = (int *)param_1;

  Ordinal_2330();
  int *savedContext = DAT_68196374;
  int contextFrame[3];
  contextFrame[0] = param_1;
  contextFrame[1] = (int)savedContext;
  contextFrame[2] = 2;
  DAT_68196374 = contextFrame;

  /* Clear runtime state fields */
  ctx[0xe0 / 4] = 0;                       /* +0xE0  field_0xe0 */
  Ordinal_1130(param_1 + 0x10c, 0x3c);     /* +0x10C  zero 0x3c bytes */
  Ordinal_1130(param_1 + 0x78, 0x48);      /* +0x78   zero 0x48 bytes */
  ctx[0xd8 / 4] = 0;                       /* +0xD8  field_0xd8 */
  ctx[0xdc / 4] = 0;                       /* +0xDC  field_0xdc */
  ctx[0x108 / 4] = 0;                      /* +0x108 field_0x108 */
  ctx[0xf0 / 4] = 0;                       /* +0xF0  field_0xf0 */
  ctx[0xe8 / 4] = 0;                       /* +0xE8  field_0xe8 */
  ctx[0xe4 / 4] = 0;                       /* +0xE4  field_0xe4 */
  ctx[0xc4 / 4] = 0;                       /* +0xC4  field_0xc4 */
  ctx[0x19c / 4] = 0;                      /* +0x19C field_0x19c */
  ctx[0x1a0 / 4] = 0;                      /* +0x1A0 field_0x1a0 */

  undefined1 eventBuf[40];
  Ordinal_1130(eventBuf, 0x28);
  int openResult = core_openMovie(0x27);
  if (openResult != 0) {
    core_closeMovie(1);
  }

  lingo_getMutateData(param_1);
  int resourceHandle = Ordinal_1038();
  if (resourceHandle != 0) {
    crt_releaseCodecFactory();
    Ordinal_1904();
    Ordinal_1019(0);
    Ordinal_1039();
    Ordinal_2072(&resourceHandle);
  }

  int *callbackObj = *(int **)(param_1 + 0x18);  /* +0x18 COM callback */
  if (callbackObj != NULL) {
    (**(code **)(*callbackObj + 8))(callbackObj); /* callbackObj->vtable->Release() */
  }

  stage_dispose();
  crt_freeInternetLib();
  media_organizeResources(param_1);
  xtra_freeRandomState();
  Ordinal_1130(param_1, 0x1c8);            /* zero entire 0x1c8-byte context */
  DAT_68195a6c = 0;
  DAT_68196374 = savedContext;
  Ordinal_2331();

  return 0;
}



// ============================================================
// Function: Ordinal_82
// Address: 6800aa40
// Size: 26 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Opens a movie with the specified flags (wrapper around core_openMovie).
 *
 * @param param_1  Unused.
 * @param param_2  Unused.
 * @param param_3  Movie open flags.
 * @return Always returns 0.
 */
int Ordinal_82(undefined4 param_1, undefined4 param_2, uint param_3)
{
                    /* 0xaa40  82   */
  core_openMovie(param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_78
// Address: 6800aa60
// Size: 171 bytes
// Params: int param_1, undefined4 param_2, uint * param_3, uint param_4, undefined4 * param_5, undefined1 * param_6, short param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Main playback loop: repeatedly steps the player until idle or timeout expires.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Unused.
 * @param param_3  Receives minimum idle time across iterations, or NULL.
 * @param param_4  Timeout in milliseconds (0 = single step, no timeout).
 * @param param_5  Receives error description, or NULL.
 * @param param_6  Error message buffer, or NULL.
 * @param param_7  Error message buffer length.
 * @return Result from the last Ordinal_97 step call.
 */
int Ordinal_78(int param_1,undefined4 param_2,uint *param_3,uint param_4,undefined4 *param_5,
              undefined1 *param_6,short param_7)

{
  Player *player = (Player *)param_1;
  int startTime = (param_4 == 0) ? 0 : Ordinal_1541();
  uint minIdleTime = 0xffffffff;
  uint stepIdleTime = 0xffffffff;
  int stepResult;
  int elapsed;

  do {
    int stateCheck = lingo_checkState(*(int *)(*(int *)player->exitCode + 0xc));
    if (stateCheck == 0) {
LAB_6800aaad:
      Ordinal_64(player->idleState, &minIdleTime);
    }
    else {
      int movieCheck = lingo_getMovieInfoWrapped(*(undefined4 **)&player->playerState);
      if (movieCheck != 0) goto LAB_6800aaad;
    }
    stepResult = Ordinal_97((int *)player->exitCode, 0, &stepIdleTime, param_5, param_6, param_7);
    if ((stepResult == 0) || (param_4 == 0)) break;
    elapsed = Ordinal_1541();
  } while ((uint)(elapsed - startTime) < param_4);

  if (param_3 != NULL) {
    *param_3 = (minIdleTime <= stepIdleTime) ? minIdleTime : stepIdleTime;
  }
  return stepResult;
}



// ============================================================
// Function: Ordinal_84
// Address: 6800ab10
// Size: 154 bytes
// Params: int * param_1, int param_2, int param_3, uint param_4, undefined4 * param_5, undefined1 * param_6, short param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Creates a linked score for the player, initializing stage and window context.
 *
 * @param param_1  Pointer to the Player object to initialize.
 * @param param_2  Host context handle.
 * @param param_3  Score data source.
 * @param param_4  Creation flags.
 * @param param_5  Receives error description on failure.
 * @param param_6  Error message buffer.
 * @param param_7  Error message buffer length.
 * @return 1 on success, 0 on failure (player is disposed on failure).
 */
undefined4
Ordinal_84(int *param_1,int param_2,int param_3,uint param_4,undefined4 *param_5,undefined1 *param_6
          ,short param_7)

{
  Player *player = (Player *)param_1;
  uint *puVar1;
  if (player == NULL) {
    Ordinal_85(param_1, 0);
    return 0;
  }

  Ordinal_1130(param_1, 0x50);
  player->hostContext = (void *)param_2;
  undefined4 *scoreHandle = score_createLinked((uint)param_1, param_2, param_3, param_4);
  player->scoreHandle = (int)scoreHandle;
  if (scoreHandle != NULL) {
    int scoreCtx = Ordinal_118((int)scoreHandle);
    stage_swapSpriteIdleMode(scoreCtx, 1);
    int *windowCtx = (int *)Ordinal_118(player->scoreHandle);
    events_initWindowContext(windowCtx);
    player->valid = 1;
    return 1;
  }

  if (param_6 != NULL && param_5 != NULL && param_7 != 0) {
    undefined4 errDesc = Ordinal_120(*(undefined4 **)((int)player->hostContext + 0x10), param_6, (int)param_7);
    *param_5 = errDesc;
  }
  Ordinal_85(param_1, 0);
  return 0;
}



// ============================================================
// Function: Ordinal_80
// Address: 6800abb0
// Size: 131 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Initializes the runtime context: sets up the global player, copies options,
 *        creates score and stage. On failure, tears everything down via Ordinal_81.
 *
 * @param param_1  Pointer to the runtime context (0x1c8 bytes) to initialize.
 * @param param_2  Host application handle (stored as hostContext).
 * @param param_3  Array of 0x6a option values to copy into the context.
 * @return 1 on success, 0 on failure or if a context already exists.
 */
undefined4 Ordinal_80(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  Player *player = (Player *)param_1;

  if (DAT_681956e0 == 0) {
    DAT_681956e0 = param_2;
  }
  if (player == NULL) {
    Ordinal_81((int)param_1);
    return 0;
  }
  if (DAT_68195a6c != NULL) {
    return 0;
  }

  DAT_68195a6c = param_1;
  Ordinal_1130(param_1, 0x1c8);
  player->hostContext = (void *)param_2;

  /* Copy 0x6a option values into context at offset +0x1C (param_1[7]) */
  undefined4 *dest = param_1 + 7;
  for (int i = 0x6a; i != 0; i--) {
    *dest = *param_3;
    param_3 = param_3 + 1;
    dest = dest + 1;
  }

  media_organizeResources((int)param_1);
  int scoreResult = score_create((int)param_1);
  if (scoreResult != 0) {
    int stageResult = stage_create((int)param_1);
    if (stageResult != 0) {
      player->valid = 1;
      return 1;
    }
  }
  Ordinal_81((int)param_1);
  return 0;
}



// ============================================================
// Function: crt_resolveImageData (FUN_6800ac40)
// Address: 6800ac40
// Size: 175 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Resolves image data from the score context's movie descriptor.
 *
 * @param param_1  Score context pointer.
 * @param param_2  Output buffer for resolved image info (type, dimensions, handle).
 * @return Always returns 0.
 */
int crt_resolveImageData(int *param_1, undefined4 *param_2)
{
  int ctx = *param_1;
  int movieDesc = 0;
  int contextBuf;
  int *savedContext;

  if (ctx != 0) {
    movieDesc = *(int *)(ctx + 0x20);           /* ctx->movieDescriptor */
    if ((movieDesc != 0) && (*(int *)(movieDesc + 4) != 0)) {
      Ordinal_2330();
      savedContext = DAT_68196374;
      DAT_68196374 = &contextBuf;
      contextBuf = ctx;
    }
  }

  int soundSys = *(int *)(movieDesc + 4);       /* movieDesc->soundSubsystem */
  param_2[5] = 2;
  int resolveResult = Ordinal_2042(*(undefined4 *)(soundSys + 0x28), param_2 + 6);
  if (resolveResult != 0) {
    int imageHandle = param_2[6];
    *param_2 = 1;
    param_2[1] = *(undefined4 *)(imageHandle + 0x10);  /* TODO: imageData->field_0x10 */
    param_2[2] = *(undefined4 *)(imageHandle + 0xc);   /* TODO: imageData->field_0x0c */
  }

  DAT_68196374 = savedContext;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_resolveLinkedImageData (FUN_6800acf0)
// Address: 6800acf0
// Size: 199 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Resolves linked image data from the score context's movie descriptor.
 *
 * @param param_1  Score context pointer.
 * @param param_2  Output buffer for resolved linked image info.
 * @return Always returns 0.
 */
int crt_resolveLinkedImageData(int *param_1, undefined4 *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  iVar2 = Ordinal_2040(*(undefined4 *)(*(int *)(iVar3 + 4) + 0xb8),param_2 + 6);
  if (iVar2 != 0) {
    piVar1 = (int *)param_2[6];
    param_2[5] = 4;
    if (*piVar1 == 2) {
      *param_2 = 2;
      param_2[1] = piVar1[4];
      param_2[2] = piVar1[7];
      param_2[3] = piVar1[6];
      param_2[4] = 0;
    }
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_resolveImageDataDirect (FUN_6800adc0)
// Address: 6800adc0
// Size: 92 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Resolves image data directly from a media handle, without score context.
 *
 * @param param_1  Media handle to resolve.
 * @param param_2  Output buffer for resolved image info.
 * @return 0 on success, 0x80040014 if the media type is unsupported.
 */
undefined4 crt_resolveImageDataDirect(undefined4 param_1, undefined4 *param_2)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = Ordinal_2040(param_1,param_2 + 6);
  if (iVar2 != 0) {
    piVar1 = (int *)param_2[6];
    param_2[5] = 4;
    if (*piVar1 == 2) {
      *param_2 = 2;
      param_2[1] = piVar1[4];
      param_2[2] = piVar1[7];
      param_2[3] = piVar1[6];
      param_2[4] = 0;
      return 0;
    }
  }
  return 0x80040014;
}



// ============================================================
// Function: crt_getMovieApiState (FUN_6800ae20)
// Address: 6800ae20
// Size: 73 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Releases the current image data handle and resets the API state buffer.
 *
 * @param param_1  API state buffer (7 int-sized slots).
 * @return 0 on success, 0x80040014 if the state type is unrecognized.
 */
undefined4 crt_getMovieApiState(undefined4 *param_1)
{
  uint uVar1;
  
  uVar1 = param_1[5];
  if ((uVar1 & 0x10) == 0) {
    if (uVar1 == 2) {
      Ordinal_2043(param_1 + 6);
    }
    else {
      if (uVar1 != 4) {
        return 0x80040014;
      }
      Ordinal_2041(param_1 + 6);
    }
  }
  Ordinal_1130(param_1,0x14);
  *param_1 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return 0;
}



// ============================================================
// Function: crt_copyMovieState (FUN_6800ae70)
// Address: 6800ae70
// Size: 76 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Copies movie state from source to destination, marking as snapshot.
 *
 * @param param_1  Source movie state buffer.
 * @param param_2  Destination movie state buffer.
 * @return 0 on success, 0x800407d4 if the movie type is unsupported.
 */
undefined4 crt_copyMovieState(int *param_1, int *param_2)
{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = 0x10;       /* mark as snapshot */
  param_2[6] = 0;

  int movieType = *param_1;
  if ((movieType < 1) || ((3 < movieType && (movieType != 7)))) {
    return 0x800407d4;
  }
  return 0;
}



// ============================================================
// Function: crt_updateMovieState (FUN_6800aec0)
// Address: 6800aec0
// Size: 44 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Updates movie state by releasing the current handle and copying new state.
 *
 * @param param_1  Current movie state buffer to update.
 * @param param_2  New movie state to copy from.
 * @return 0 on success, 0x800407eb if the state is not a snapshot.
 */
undefined4 crt_updateMovieState(int *param_1, int *param_2)
{
  if ((*(byte *)(param_1 + 5) & 0x10) != 0) {
    crt_getMovieApiState(param_1);
    return crt_copyMovieState(param_2, param_1);
  }
  return 0x800407eb;
}



// ============================================================
// Function: crt_copyMovieFields (FUN_6800aef0)
// Address: 6800aef0
// Size: 43 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Copies the first five fields of a movie state buffer.
 *
 * @param param_1  Source buffer.
 * @param param_2  Destination buffer.
 * @return Always returns 0.
 */
undefined4 crt_copyMovieFields(undefined4 *param_1, undefined4 *param_2)
{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  return 0;
}



