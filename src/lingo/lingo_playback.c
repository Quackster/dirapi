// Module: lingo
// Topic: Playback control, movie loading, and frame stepping
// Address range: 0x68091030 - 0x68096CB0
// Functions (35):
//   Ordinal_107
//   Ordinal_138
//   Ordinal_139
//   lingo_enablePlaybackFlag
//   lingo_setPlaybackProperty
//   lingo_setupPlaybackContext
//   Ordinal_121
//   lingo_getPlaybackRef
//   lingo_getPlaybackValue
//   lingo_teardownPlaybackContext
//   lingo_resetCastOrdinal
//   Ordinal_137
//   lingo_setPropertyWrapped
//   Ordinal_46
//   lingo_checkState (FUN_68092d10)
//   Ordinal_142
//   Ordinal_135
//   Ordinal_136
//   Ordinal_143
//   lingo_destroyPlaybackState
//   Ordinal_145
//   Ordinal_147
//   lingo_setPlaybackData
//   Ordinal_48
//   lingo_dispatchSpriteEvents
//   lingo_flushSortList
//   score_onPaused (FUN_68096240)
//   lingo_updateStageDisplay
//   Ordinal_392
//   lingo_destroyBitmapData
//   lingo_mergeStageRegion
//   lingo_getStageLayout
//   lingo_loadAndPlayMovie
//   score_loadMovie (FUN_68096b00)
//   Ordinal_74


// ============================================================
// Function: Ordinal_107
// Address: 68091030
// Size: 351 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_107(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x91030  107   */
  if (param_1 == 0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = *(int **)(param_1 + 0x20);
  }
  piVar4 = local_20;
  local_18 = 0;
  local_1c = 0;
  if ((local_20 != (int *)0x0) && (local_20[1] != 0)) {
    local_1c = *(int *)(local_20[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (local_18 = **(int **)(param_1 + 0x20), local_18 == 0)))) {
      local_18 = *local_20;
    }
    Ordinal_2330();
    local_c = 0;
    local_14 = local_18;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  puVar5 = (undefined4 *)(local_1c + 0x358);
  if (*(int *)(local_1c + 0x358) != 0) {
    iVar1 = Ordinal_1154(*(int *)(local_1c + 0x358));
    iVar1 = iVar1 + -1;
    for (iVar3 = iVar1; -1 < iVar3; iVar3 = iVar3 + -1) {
      iVar2 = Ordinal_1155(*puVar5,iVar3,&local_28);
      if ((iVar2 != 0) && (local_24 != 0)) {
        stage_invalidateSpriteScript(local_28,&local_24);
      }
    }
    for (; -1 < iVar1; iVar1 = iVar1 + -1) {
      iVar3 = Ordinal_1155(*puVar5,iVar1,&local_28);
      if ((iVar3 != 0) && (local_24 == 0)) {
        stage_releaseSpriteRef(&local_28);
      }
    }
    Ordinal_1163(puVar5);
    piVar4 = local_20;
  }
  iVar1 = local_18;
  rendering_flushChannelEvents(piVar4[1]);
  media_fireAllXtraEvents(piVar4[1]);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) &&
     (*(int *)(*(int *)(iVar1 + 0x20) + 0x63c) != 0)) {
    Ordinal_1840(*(undefined4 *)(*(int *)(iVar1 + 0x24) + 4));
  }
  lingo_resolveRef(local_1c,1,(undefined4 *)0x0);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_138
// Address: 68091190
// Size: 469 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_138(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *local_41c;
  int *local_418;
  int local_414;
  int *local_410;
  undefined4 local_40c;
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
                    /* 0x91190  138   */
  iVar4 = 0;
  local_418 = (int *)0x0;
  local_41c = (int *)0x0;
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      if ((piVar3 == (int *)0x0) || (iVar1 = *piVar3, iVar1 == 0)) {
        iVar1 = *piVar3;
      }
      Ordinal_2330();
      local_40c = 0;
      local_410 = DAT_68196374;
      DAT_68196374 = &local_414;
      local_414 = iVar1;
    }
  }
  iVar1 = Ordinal_1313(param_2);
  if (iVar1 == 4) {
    uVar2 = Ordinal_1038(&DAT_681761b8,&DAT_68176198,&local_41c);
    iVar4 = Ordinal_2063(uVar2);
    if (iVar4 == 0) {
      iVar1 = Ordinal_1310(param_2,local_407,0x3ff);
      if (iVar1 != 0) {
        iVar4 = Ordinal_1201(local_407);
        local_407[iVar4] = 0;
        iVar4 = Ordinal_1201(local_407);
        if (iVar4 < 0xff) {
          local_408 = Ordinal_1201(local_407);
        }
        else {
          local_408 = 0xff;
        }
        iVar4 = (**(code **)(*local_41c + 0xc))(local_41c,local_407);
        if (iVar4 == 0) {
          iVar4 = (**(code **)(*local_41c + 0x38))(local_41c,4);
          if (iVar4 == 0) {
            iVar4 = (**(code **)(*local_41c + 0x18))(local_41c,0,&local_418);
            if (iVar4 == 0) {
              iVar4 = (**(code **)(*local_418 + 0xc))(local_418,0,1);
            }
          }
        }
      }
    }
  }
  if (local_41c != (int *)0x0) {
    (**(code **)(*local_41c + 8))(local_41c);
  }
  if ((iVar4 != 0) && (local_418 != (int *)0x0)) {
    (**(code **)(*local_418 + 8))(local_418);
    local_418 = (int *)0x0;
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_410;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_139
// Address: 68091370
// Size: 160 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_139(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x91370  139   */
  local_18 = 0;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  lingo_resolveRef(iVar1,0,&local_18);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_enablePlaybackFlag (FUN_68091410)
// Address: 68091410
// Size: 149 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_enablePlaybackFlag(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  *(undefined4 *)(iVar1 + 900) = 1;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_setPlaybackProperty (FUN_680914b0)
// Address: 680914b0
// Size: 454 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int lingo_setPlaybackProperty(int param_1,undefined4 param_2,undefined4 *param_3)
{
  undefined1 uVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar4;
  int *piVar5;
  int local_3c [3];
  undefined4 *local_30;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_2;
  local_30 = param_3;
  local_20 = (int *)0x0;
  local_18 = 0;
  local_1c = 0;
  if (param_1 == 0) {
    local_28 = (int *)0x0;
  }
  else {
    local_28 = *(int **)(param_1 + 0x20);
  }
  piVar4 = (int *)0x0;
  if ((local_28 != (int *)0x0) && (local_28[1] != 0)) {
    piVar4 = *(int **)(local_28[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *local_28;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  iVar3 = Ordinal_1313(local_24);
  if (iVar3 == 4) {
    local_20 = (int *)Ordinal_138(param_1,local_24);
    if (local_20 == (int *)0x0) goto LAB_68091635;
    local_2c = 0;
    local_3c[1] = 0;
    local_3c[2] = 0;
    piVar4[0xe1] = 0;
    do {
      piVar5 = local_20;
      local_1c = rendering_resolveMemberProperty(local_20,(int *)0x0,1,local_3c);
      if (local_3c[0] != 0) {
        local_18 = 1;
        goto LAB_680915e8;
      }
      if (local_1c != 0) goto LAB_680915e5;
      local_18 = 2;
      if (local_2c == 0) {
        uVar1 = lingo_resolveRef((int)piVar4,0,&local_1c);
        iVar3 = CONCAT31(extraout_var,uVar1);
        if (iVar3 == 0) goto LAB_68091601;
        local_2c = 1;
      }
      else {
        iVar3 = lingo_callMethod((int)piVar4,&local_1c,local_24,piVar5,(int)(local_3c + 1),0);
      }
      if (iVar3 == 0) goto LAB_680915e8;
    } while ((piVar4[0xe1] == 0) &&
            (bVar2 = lingo_isMovieLoaded(piVar4), CONCAT31(extraout_var_00,bVar2) == 0));
    local_1c = -0x7ffbadf8;
LAB_680915e5:
    local_18 = 0;
LAB_680915e8:
    if (local_2c != 0) {
      lingo_callMethod((int)piVar4,local_3c + 2,local_24,0,(int)(local_3c + 1),0);
    }
LAB_68091601:
    if (local_1c == 0) {
      if (local_3c[2] != 0) {
        local_1c = local_3c[2];
        goto LAB_68091610;
      }
    }
    else {
LAB_68091610:
      local_18 = 0;
    }
    (**(code **)(*piVar5 + 0x10))(piVar5);
    if ((local_18 == 0) || (piVar5 = local_20, local_30 == (undefined4 *)0x0)) {
      (**(code **)(*piVar5 + 8))(piVar5);
      local_20 = (int *)0x0;
      goto LAB_68091635;
    }
  }
  else {
    local_18 = 1;
LAB_68091635:
    if (local_30 == (undefined4 *)0x0) goto LAB_68091641;
  }
  *local_30 = local_20;
LAB_68091641:
  if (local_28 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_setupPlaybackContext (FUN_68091950)
// Address: 68091950
// Size: 147 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setupPlaybackContext(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_121
// Address: 680919f0
// Size: 185 bytes
// Params: int param_1, undefined4 * param_2, int param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_121(int param_1,undefined4 *param_2,int param_3,void *param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x919f0  121   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  rendering_saveCastMember(*(int *)(iVar2 + 0x20),param_2,param_3,param_4);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getPlaybackRef (FUN_68091ab0)
// Address: 68091ab0
// Size: 41 bytes
// Params: uint param_1, uint * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_getPlaybackRef(uint param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *param_2 = param_1;
  while ((param_1 != 0 && (iVar1 = Ordinal_1124(*param_2), iVar1 == 0))) {
    *param_2 = *param_2 >> 1;
    param_1 = *param_2;
  }
  return iVar1;
}



// ============================================================
// Function: lingo_getPlaybackValue (FUN_68091ae0)
// Address: 68091ae0
// Size: 274 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getPlaybackValue(int param_1,undefined4 *param_2)

{
  int param_4;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_1c;
  uint local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  local_1c = 0;
  local_10 = 0;
  local_8 = (int *)0x0;
  local_c = 0;
  local_14 = 0;
  bVar1 = false;
  iVar3 = crt_streamGetPos(param_1);
  iVar4 = crt_streamReadAt(param_1,&local_10);
  if ((iVar4 == 0) && (iVar4 = crt_streamRead(param_1,0), iVar4 == 0)) {
    iVar4 = crt_openStreamForRead(param_2,&local_8);
    if (iVar4 == 0) {
      iVar4 = crt_flushStream(local_8);
      if (iVar4 == 0) {
        bVar1 = true;
        local_c = lingo_getPlaybackRef(0x10000,&local_14);
        uVar2 = local_14;
        if (local_c == 0) goto LAB_68091bc2;
        for (; local_10 != 0; local_10 = local_10 - uVar5) {
          uVar5 = uVar2;
          if (local_10 <= uVar2) {
            uVar5 = local_10;
          }
          iVar4 = crt_writeStreamData(param_1,local_c,uVar5);
          if ((iVar4 != 0) || (iVar4 = crt_streamWrite((int)local_8,local_c,uVar5), iVar4 != 0))
          goto LAB_68091bb4;
        }
        local_1c = 1;
      }
    }
    else {
      local_8 = (int *)0x0;
    }
  }
LAB_68091bb4:
  if (local_c != 0) {
    Ordinal_1125(&local_c);
  }
LAB_68091bc2:
  if (local_8 != (int *)0x0) {
    if (bVar1) {
      crt_resetStreamState((int)local_8);
    }
    crt_streamClose((int)local_8);
  }
  crt_streamRead(param_1,iVar3);
  return local_1c;
}



// ============================================================
// Function: lingo_teardownPlaybackContext (FUN_68091eb0)
// Address: 68091eb0
// Size: 150 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_teardownPlaybackContext(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_resetCastOrdinal (FUN_68091f50)
// Address: 68091f50
// Size: 168 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_resetCastOrdinal(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      if ((piVar2 == (int *)0x0) || (iVar3 = *piVar2, iVar3 == 0)) {
        iVar3 = *piVar2;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar3;
    }
  }
  if (piVar2[0x2e5] != 0) {
    piVar1 = *(int **)(piVar2[1] + 4);
    Ordinal_96(piVar1);
    Ordinal_89((int)piVar1,piVar2[0x2e4]);
    piVar2[0x2e5] = 0;
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_137
// Address: 68092000
// Size: 684 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int param_5, undefined4 param_6, void * param_7, int param_8, int param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_137(int param_1,int *param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                void *param_7,int param_8,int param_9)
{
  void *pvVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *local_10c;
  int local_104;
  int local_100;
  undefined4 local_fc;
  undefined1 local_f8 [228];
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92000  137   */
  bVar2 = false;
  local_100 = 0;
  local_fc = 0;
  memset(local_f8,0,0xe4);
  if (param_1 == 0) {
    local_10c = (int *)0x0;
  }
  else {
    local_10c = *(int **)(param_1 + 0x20);
  }
  if ((local_10c != (int *)0x0) && (local_10c[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *local_10c;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  iVar3 = lingo_initMutateData(param_2);
  if (iVar3 == 0) {
    local_100 = Ordinal_1111(0xbb0,1);
    if (local_100 != 0) {
      piVar5 = (int *)Ordinal_1114(local_100);
      iVar3 = scoreEngine_initScoreChannel(local_10c[1],piVar5,0);
      if (iVar3 != 0) {
        stage_swapSpriteIdleMode(piVar5[2],1);
        piVar5[0x2e4] = param_9;
        if (param_8 == 0) {
          *(undefined1 *)(piVar5 + 0x2a4) = 0;
        }
        else {
          Ordinal_1203(piVar5 + 0x2a4,param_8,0x100);
        }
        goto LAB_68092206;
      }
LAB_6809227e:
      if (local_100 != 0) goto LAB_68092149;
    }
    iVar3 = lingo_setPropertyValue(param_2,1);
    if (iVar3 == 0) goto LAB_68092154;
  }
  else {
    if (((uint)param_7 & 1) != 0) {
      bVar2 = true;
      uVar4 = lingo_setPropertyValue(param_2,0);
      piVar5 = (int *)Ordinal_1114(uVar4);
      Ordinal_1115(uVar4);
      local_100 = 0;
LAB_68092206:
      pvVar1 = (void *)*piVar5;
      *(undefined4 **)((int)pvVar1 + 0x24) = &local_fc;
      local_104 = playback_loadMediaChunk(pvVar1,param_2,param_5,0,param_7);
      if (local_104 != 0) {
        if (local_104 == 2) {
          if (((uint)param_7 & 0x40) != 0) {
            local_104 = 0;
          }
        }
        else {
          scoreEngine_duplicateFrames(piVar5,param_3,param_4);
          local_104 = 1;
        }
      }
      *(undefined4 *)((int)pvVar1 + 0x24) = 0;
      if (local_104 == 0) goto LAB_6809227e;
    }
    if (((local_100 == 0) || (bVar2)) || (iVar3 = lingo_getMutateRef(local_100), iVar3 != 0))
    goto LAB_68092154;
  }
LAB_68092149:
  lingo_getMutateState();
LAB_68092154:
  if (local_10c != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_setPropertyWrapped (FUN_680922b0)
// Address: 680922b0
// Size: 102 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setPropertyWrapped(undefined4 *param_1,undefined4 param_2)
{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  lingo_setPropertyValue(param_2,1);
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_46
// Address: 68092c10
// Size: 248 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_46(int param_1,int param_2)
{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint *local_14;
  uint **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92c10  46   */
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_1 + 0x20);
  }
  puVar3 = (uint *)0x0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (puVar3 = (uint *)**(int **)(param_1 + 0x20), puVar3 == (uint *)0x0)))) {
      puVar3 = (uint *)*piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = puVar3;
  }
  if ((*puVar3 & 8) != 0) {
    iVar2 = scoreEngine_validateCastMember(puVar3[8]);
    if (iVar2 != 0) {
      if (param_2 == 0) {
        if ((*puVar3 & 4) != 0) {
          playback_toggleSoundPause(puVar3,0);
          uVar1 = playback_getLifecycleSize((int)puVar3);
          rendering_onPause((int)puVar3,uVar1);
          scoreEngine_onPause((int *)puVar3[8]);
          *puVar3 = *puVar3 & 0xfffffffb;
        }
      }
      else if ((*puVar3 & 4) == 0) {
        playback_toggleSoundPause(puVar3,1);
        rendering_onPause((int)puVar3,0);
        scoreEngine_onResume((int *)puVar3[8]);
        *puVar3 = *puVar3 | 4;
      }
      Ordinal_1042();
      rendering_updateDisplay();
    }
  }
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_142
// Address: 68092da0
// Size: 136 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_142(int param_1,byte *param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92da0  142   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    scoreEngine_validateCastMember(*(int *)(pbVar2 + 0x20));
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_135
// Address: 68092e30
// Size: 147 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_135(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92e30  135   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_resetThumbnails(*(int **)(iVar1 + 0x20),(void *)0x0);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_136
// Address: 68092ed0
// Size: 145 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_136(int param_1,undefined1 param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92ed0  136   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_setCastXtraFlag(*(int *)(iVar1 + 0x20),param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_143
// Address: 68092f70
// Size: 144 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_143(int param_1,byte *param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92f70  143   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    playback_executeControlStep(pbVar2);
    playback_getControlFlags((int *)pbVar2,0);
    pbVar2[0x5c] = 0;
    pbVar2[0x5d] = 0;
    pbVar2[0x5e] = 0;
    pbVar2[0x5f] = 0;
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_destroyPlaybackState (FUN_68093000)
// Address: 68093000
// Size: 154 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_destroyPlaybackState(int param_1,byte *param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    playback_getControlFlags((int *)pbVar2,1);
    pbVar2[0x5c] = 0;
    pbVar2[0x5d] = 0;
    pbVar2[0x5e] = 0;
    pbVar2[0x5f] = 0;
    playback_reinitScore();
    playback_destroyLifecycle((int)pbVar2);
    playback_downgradeTransitionMode((int)pbVar2);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_145
// Address: 680930a0
// Size: 285 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_145(int param_1,int param_2,undefined4 param_3)
{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  byte *pbVar3;
  bool bVar4;
  int iVar5;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x930a0  145   */
  pbVar3 = (byte *)0x0;
  iVar5 = 0;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar3 = (byte *)**(int **)(param_1 + 0x20), pbVar3 == (byte *)0x0)))) {
      pbVar3 = (byte *)*piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar3;
  }
  if ((*pbVar3 & 8) == 0) goto LAB_68093197;
  bVar4 = true;
  if (*(int *)(pbVar3 + 0x5c) == 0) {
    iVar5 = playback_processControl((int *)pbVar3,param_2);
    Ordinal_1013();
    bVar4 = *(int *)(*(int *)(pbVar3 + 0x20) + 0x63c) == 0;
    if (!bVar4) {
      Ordinal_1840(*(undefined4 *)(*(int *)(pbVar3 + 0x24) + 4));
    }
    if (iVar5 == 2) goto LAB_68093197;
    bVar1 = playback_isStepPastTransition((int)pbVar3);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      if (iVar5 != 0) goto LAB_68093174;
    }
    else {
      iVar5 = 0;
    }
    pbVar3[0x5c] = 1;
    pbVar3[0x5d] = 0;
    pbVar3[0x5e] = 0;
    pbVar3[0x5f] = 0;
  }
LAB_68093174:
  playback_initLifecycleEx(pbVar3);
  if ((bVar4) && (*(int *)(*(int *)(pbVar3 + 0x20) + 0x63c) != 0)) {
    Ordinal_1840(*(undefined4 *)(*(int *)(pbVar3 + 0x24) + 4));
  }
LAB_68093197:
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_3,iVar5);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_147
// Address: 680931c0
// Size: 314 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_147(int param_1,uint *param_2)
{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  byte *pbVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x931c0  147   */
  pbVar2 = (byte *)0x0;
  iVar5 = 0;
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_1 + 0x20);
  }
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  if ((*pbVar2 & 8) == 0) goto LAB_680932d1;
  bVar3 = true;
  if (*(int *)(pbVar2 + 0x5c) < 1) {
    iVar5 = 1;
  }
  else if (*(int *)(pbVar2 + 0x5c) == 1) {
    bVar1 = playback_isStepActive((int)pbVar2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar5 = playback_processControl((int *)pbVar2,-1);
      bVar1 = playback_isStepActive((int)pbVar2);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        Ordinal_1013();
        bVar3 = *(int *)(*(int *)(pbVar2 + 0x20) + 0x63c) == 0;
        if (!bVar3) {
          Ordinal_1840(*(undefined4 *)(*(int *)(pbVar2 + 0x24) + 4));
        }
        if ((param_2 != (uint *)0x0) && (100 < *param_2)) {
          *param_2 = 100;
        }
        if (iVar5 != 0) goto LAB_680932ae;
      }
      else {
        iVar5 = 0;
      }
    }
    pbVar2[0x5c] = 2;
    pbVar2[0x5d] = 0;
    pbVar2[0x5e] = 0;
    pbVar2[0x5f] = 0;
  }
LAB_680932ae:
  playback_initLifecycleEx(pbVar2);
  if ((bVar3) && (*(int *)(*(int *)(pbVar2 + 0x20) + 0x63c) != 0)) {
    Ordinal_1840(*(undefined4 *)(*(int *)(pbVar2 + 0x24) + 4));
  }
LAB_680932d1:
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(piVar4,iVar5);
  }
  return 0;
}



// ============================================================
// Function: lingo_setPlaybackData (FUN_68093300)
// Address: 68093300
// Size: 298 bytes
// Params: int param_1, byte * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setPlaybackData(int param_1,byte *param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int local_24;
  int local_1c;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  local_24 = 0;
  pbVar5 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    local_24 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar5 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (((*pbVar5 & 8) != 0) && (param_3 != (undefined4 *)0x0)) {
    playback_getStepFrameInfo(pbVar5,param_3);
    iVar6 = *(int *)(pbVar5 + 0x4c);
    if ((-1 < iVar6) && ((local_1c = *(int *)(pbVar5 + 0x48), iVar6 < local_1c || (local_1c == -1)))
       ) {
      iVar2 = *(int *)(pbVar5 + 0x124);
      if (local_1c == -1) {
        local_1c = iVar2 + 1;
      }
      if (iVar6 < local_1c) {
        iVar4 = iVar6 * 400;
        do {
          if ((*(char *)(iVar6 + *(int *)(pbVar5 + 0x30)) != '\0') &&
             (((*(byte *)(*(int *)(pbVar5 + 0x34) + iVar4 + 0x58) & 0x10) != 0 ||
              ((*(char *)(iVar6 + *(int *)(pbVar5 + 0x30)) == '\n' &&
               (uVar3 = bitmap_getSpriteEditability(pbVar5,*(int *)(pbVar5 + 0x34) + iVar4,(uint *)0x0), uVar3 != 0
               )))))) break;
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + 400;
        } while (iVar6 < local_1c);
      }
      if (iVar6 < iVar2 + 1) {
        param_3[3] = iVar6;
      }
    }
  }
  lingo_getMovieRef(local_24);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_48
// Address: 68093430
// Size: 120 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_48(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93430  48   */
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_updateDisplay();
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_dispatchSpriteEvents (FUN_680934b0)
// Address: 680934b0
// Size: 340 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_dispatchSpriteEvents(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar6 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar6 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar7 = *(int *)(iVar6 + 0x120);
  if (iVar7 <= *(int *)(iVar6 + 0x124)) {
    local_18 = iVar7 * 400;
    piVar3 = (int *)(iVar7 * 0x34 + 0x44 + *(int *)(iVar6 + 0x38));
    iVar5 = iVar7;
    do {
      iVar5 = iVar5 + 1;
      if (((((piVar3[-1] & (1 << ((byte)param_3 & 0x1f)) >> 1) == 0) ||
           (((*piVar3 == 0 && (piVar3[-4] != 0)) && (iVar4 = events_forwardDispatch(), iVar4 == 0)))) &&
          ((((*(char *)(iVar7 + *(int *)(iVar6 + 0x30)) != '\0' &&
             (iVar4 = playback_getSpriteData(iVar6,(undefined4 *)(*(int *)(iVar6 + 0x34) + local_18)),
             iVar4 != 0)) && (*(int **)(iVar4 + 0x4c) != (int *)0x0)) &&
           ((iVar2 = *(int *)(**(int **)(iVar4 + 0x4c) + 4), -1 < iVar2 && (iVar2 != 0)))))) &&
         ((*(int *)(iVar4 + 8) != 0xb && ((*(int *)(iVar4 + 8) != 0 && (*piVar3 == 0)))))) {
        stage_dispatchEvent(*(int *)(*(int *)(iVar6 + 0x20) + 8),*(undefined4 *)(iVar4 + 4),param_3,iVar5);
      }
      local_18 = local_18 + 400;
      iVar7 = iVar7 + 1;
      piVar3 = piVar3 + 0xd;
    } while (iVar7 <= *(int *)(iVar6 + 0x124));
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_flushSortList (FUN_68093610)
// Address: 68093610
// Size: 132 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_flushSortList(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (*(int *)(iVar2 + 0x3c) != 0) {
    Ordinal_1162(*(int *)(iVar2 + 0x3c));
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_updateStageDisplay (FUN_680962f0)
// Address: 680962f0
// Size: 191 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_updateStageDisplay(int param_1)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  piVar1 = (int *)0x0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    piVar1 = *(int **)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  if ((*(byte *)(*piVar1 + 0x1c) & 0x80) != 0) {
    Ordinal_1759(*(undefined4 *)(piVar3[1] + 0x28),2);
  }
  if (*(int *)(iVar2 + 0xb8) == 1) {
    rendering_updateStageRect(iVar2,*(int *)(iVar2 + 0x24));
    *(undefined4 *)(iVar2 + 0xb8) = 0;
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_392
// Address: 680963b0
// Size: 184 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_392(int param_1,int param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x963b0  392   */
  iVar3 = 0;
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    iVar2 = *(int *)(piVar4[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  piVar1 = (int *)lingo_getGlobalRef(iVar2);
  media_getAssetCaps(iVar3,piVar1,param_2,param_3);
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_destroyBitmapData (FUN_68096470)
// Address: 68096470
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_destroyBitmapData(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  if (piVar1[1] != -0x24) {
    Ordinal_1651(*(undefined4 *)(piVar1[1] + 0xd4));
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_mergeStageRegion (FUN_68096500)
// Address: 68096500
// Size: 157 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mergeStageRegion(int param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  if ((piVar1[1] + 0x24 != 0) && (param_2 != (int *)0x0)) {
    rendering_mergeStageRegion(piVar1[1] + 0x24,param_2);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_getStageLayout (FUN_680965a0)
// Address: 680965a0
// Size: 153 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getStageLayout(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if ((piVar2[1] + 0x24 != 0) && (param_2 != (int *)0x0)) {
    rendering_getStageLayout(iVar1,piVar2[1] + 0x24,param_2);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_loadAndPlayMovie (FUN_68096640)
// Address: 68096640
// Size: 774 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall lingo_loadAndPlayMovie(void *this,int param_1,int param_2)
{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint *local_28;
  uint local_24;
  uint local_20;
  uint *local_1c;
  undefined4 local_18;
  uint local_14;
  uint *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_38 = param_1;
  local_34 = 0;
  if (param_1 == 0) {
    local_28 = (uint *)0x0;
  }
  else {
    local_28 = *(uint **)(param_1 + 0x20);
  }
  puVar9 = local_28;
  local_3c = 0;
  if ((local_28 != (uint *)0x0) && (local_28[1] != 0)) {
    local_3c = *(undefined4 *)(local_28[1] + 8);
    if ((param_1 == 0) ||
       ((*(uint **)(param_1 + 0x20) == (uint *)0x0 ||
        (uVar7 = **(uint **)(param_1 + 0x20), uVar7 == 0)))) {
      uVar7 = *local_28;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = uVar7;
  }
  local_30 = lingo_setPropertyValue(this,1);
  if (local_30 != 0) {
    iVar3 = Ordinal_1114(local_30);
    local_2c = iVar3;
    if (((*(int *)(iVar3 + 0x44c) == 0) && (local_24 = puVar9[1] + 0x24, local_24 != 0)) &&
       ((puVar9[0x111] == 0 ||
        ((puVar9[0x110] == 0 ||
         (bVar2 = rendering_saveCastMember((int)puVar9,(undefined4 *)0x0,1,(void *)0x0),
         CONCAT31(extraout_var,bVar2) != 0)))))) {
      iVar6 = local_38;
      puVar9 = puVar9 + 0x196;
      puVar10 = (uint *)(iVar3 + 0x658);
      for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 *)(iVar3 + 0x668) = 0;
      uVar4 = Ordinal_178(local_38);
      Ordinal_53(iVar6,1);
      puVar9 = local_28;
      piVar1 = *(int **)(local_28[1] + 4);
      if (piVar1[9] == 0) {
        piVar5 = (int *)Ordinal_118(piVar1[3]);
        Ordinal_167(piVar5);
      }
      *(uint *)(local_2c + 4) = puVar9[1];
      local_2c = Ordinal_1115(local_30);
      scoreEngine_swapScoreData((int *)puVar9,&local_30);
      puVar10 = (uint *)*puVar9;
      stage_bindMovie(puVar9[2],(int)piVar1);
      playback_dispatchLifecycle(puVar10,local_24);
      rendering_getStageRefById(local_24);
      playback_setSoundProperty((byte *)puVar10,0);
      scoreEngine_readCastXtraBlock((int)puVar9,(undefined1 *)&local_40);
      rendering_getStageData((int *)puVar9,puVar10[9],&local_40);
      playback_setSoundProperty((byte *)puVar10,
                   (uint)(*(int *)(*(int *)(puVar10[8] + 4) + 4) ==
                         *(int *)(*(int *)puVar10[6] + 0x18)));
      iVar6 = lingo_getMutateContext();
      puVar9 = local_28;
      iVar3 = local_2c;
      if (iVar6 != 0) {
        if ((char)local_28[0x2a4] == '\0') {
          uVar7 = local_28[0x2e4];
        }
        else {
          uVar7 = stage_updateSpriteRegion(local_28[2],(int)(local_28 + 0x2a4));
        }
        if ((int)uVar7 < 1) {
          uVar7 = 1;
        }
        stage_renderFrame(puVar9[2],puVar9 + 10);
        stage_getSpriteApiRef(puVar9[2],1);
        Ordinal_152(local_38,0x2400,uVar7);
        Ordinal_86((int)piVar1,*(undefined4 *)(local_24 + 4),1);
        if (param_2 == 0) {
          Ordinal_96(piVar1);
          if (local_38 == 0) {
            puVar9 = (uint *)0x0;
          }
          else {
            puVar9 = *(uint **)(local_38 + 0x20);
            if ((puVar9 != (uint *)0x0) && (puVar9[1] != 0)) {
              if ((puVar9 == (uint *)0x0) || (local_24 = *puVar9, local_24 == 0)) {
                local_24 = *puVar9;
              }
              Ordinal_2330();
              local_20 = local_24;
              local_18 = 0;
              local_1c = DAT_68196374;
              DAT_68196374 = &local_20;
            }
          }
          Ordinal_89((int)piVar1,uVar7);
          if (puVar9 != (uint *)0x0) {
            DAT_68196374 = local_1c;
            Ordinal_2331();
          }
        }
        else {
          puVar9[0x2e4] = uVar7;
          puVar9[0x2e5] = 1;
        }
        Ordinal_53(local_38,uVar4);
        local_34 = 1;
        iVar3 = local_2c;
        puVar9 = local_28;
      }
    }
    if (iVar3 != 0) {
      Ordinal_1115(local_30);
    }
    if ((local_34 == 0) && (local_30 != 0)) {
      lingo_getMutateRef(local_30);
    }
  }
  if (puVar9 != (uint *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_74
// Address: 68096cb0
// Size: 158 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_74(int param_1,uint param_2)
{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x96cb0  74   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  pbVar3 = (byte *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar3 = (byte *)**(int **)(param_1 + 0x20), pbVar3 == (byte *)0x0)))) {
      pbVar3 = (byte *)*piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar3;
  }
  playback_resetAllState(pbVar3);
  iVar1 = Ordinal_58(param_1,(byte *)0x0);
  Ordinal_152(param_1,param_2,iVar1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


