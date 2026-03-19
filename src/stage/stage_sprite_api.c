// Module: stage
// Topic: Sprite API and stage properties
// Address range: 0x6805E460 - 0x6805ECF0
// Functions (38):
//   Ordinal_231 (FUN_6805E460)
//   Ordinal_945 (FUN_6805E470)
//   stage_createSpriteFromChannel (FUN_6805E590)
//   stage_releaseSpriteRef (FUN_6805E5D0)
//   stage_getSpriteDataOffset (FUN_6805E600)
//   stage_updateSpriteChannel (FUN_6805E610)
//   stage_updateSpriteMapping (FUN_6805E660)
//   stage_notifySpriteIdle (FUN_6805E6B0)
//   stage_getSpriteScriptCount (FUN_6805E740)
//   stage_compileSpriteHandler (FUN_6805E760)
//   stage_invalidateSpriteScript (FUN_6805E7C0)
//   stage_invalidateSpriteScriptByIndex (FUN_6805E7F0)
//   stage_findSpriteHandlerFrame (FUN_6805E820)
//   stage_getSpriteHandlerArg (FUN_6805E870)
//   stage_dispatchSpriteReturn (FUN_6805E890)
//   stage_dispatchSpritePrev (FUN_6805E8B0)
//   stage_dispatchSpriteNext (FUN_6805E8E0)
//   stage_updateSpriteRegion (FUN_6805E910)
//   Ordinal_167 (FUN_6805E930)
//   Ordinal_66 (FUN_6805E950)
//   Ordinal_67 (FUN_6805E970)
//   Ordinal_68 (FUN_6805E990)
//   stage_setSpriteTrailMode (FUN_6805E9B0)
//   stage_getSpriteConstraint (FUN_6805E9D0)
//   stage_setInputEnabled (FUN_6805e9f0)
//   stage_setSpriteClickOffset (FUN_6805EA20)
//   stage_getSpriteApiRef (FUN_6805EA50)
//   stage_updateProperty (FUN_6805ea70)
//   stage_swapSpriteIdleMode (FUN_6805EA90)
//   stage_setSpriteEvalMode (FUN_6805EAC0)
//   stage_setSpriteEvalModeEx (FUN_6805EAE0)
//   stage_offsetSpriteRects (FUN_6805EB10)
//   Ordinal_801 (FUN_6805EBA0)
//   stage_initSpriteContext (FUN_6805EBB0)
//   stage_dispatchSpriteLifecycle (FUN_6805EC50)
//   stage_updateSpriteEvent (FUN_6805EC90)
//   Ordinal_62 (FUN_6805ECC0)
//   stage_handleSpriteResize (FUN_6805ECF0)

// ============================================================
// Function: Ordinal_231
// Address: 6805e460
// Size: 9 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_231(int param_1,int param_2,int param_3,int param_4)
{
                    /* 0x5e460  231   */
  events_configureProjector(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: Ordinal_945
// Address: 6805e470
// Size: 201 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_945(int *param_1,undefined4 param_2)
{
                    /* 0x5e470  945   */
  if (*(short *)(param_1[0xb] + 0x10) == 1) {
    switch(param_2) {
    case 0xc:
      sprites_handleEditCommand((int)param_1,0x14);
      return 0;
    case 0xd:
      sprites_handleEditCommand((int)param_1,0x13);
      return 0;
    case 0xe:
      sprites_handleEditCommand((int)param_1,0x15);
      return 0;
    case 0xf:
      sprites_handleEditCommand((int)param_1,0x17);
      return 0;
    case 0x10:
    case 0x11:
      sprites_handleEditCommand((int)param_1,0x16);
      return 0;
    case 0x1f:
      sprites_handleEditCommand2(param_1,0x157);
      break;
    case 0x20:
      sprites_handleEditCommand2(param_1,0x158);
      return 0;
    case 0x21:
      sprites_handleEditCommand2(param_1,0x159);
      return 0;
    case 0x24:
      sprites_handleEditCommand2(param_1,0x15a);
      return 0;
    case 0x25:
      sprites_handleEditCommand2(param_1,0x15b);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_createSpriteFromChannel (FUN_6805e590)
// Address: 6805e590
// Size: 49 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_createSpriteFromChannel(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if ((param_2 != 0) && (*(int *)(param_2 + 0xc) != 0)) {
    piVar1 = events_handleMovieCallback(param_2,param_3);
    events_handleWindowResize((int)piVar1);
    events_updateWindowState(piVar1);
  }
  return piVar1;
}



// ============================================================
// Function: stage_releaseSpriteRef (FUN_6805e5d0)
// Address: 6805e5d0
// Size: 46 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_releaseSpriteRef(int *param_1)

{
  int *piVar1;
  
  piVar1 = param_1;
  param_1 = (int *)*param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  events_cleanupMovieInstance((int *)&param_1);
  *piVar1 = 0;
  return 1;
}



// ============================================================
// Function: stage_getSpriteDataOffset (FUN_6805e600)
// Address: 6805e600
// Size: 13 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_getSpriteDataOffset(int param_1)

{
  return param_1 + 4;
}



// ============================================================
// Function: stage_updateSpriteChannel (FUN_6805e610)
// Address: 6805e610
// Size: 77 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateSpriteChannel(int *param_1,int param_2)
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
  events_advancePlayhead(param_1);
  param_1[9] = iVar2;
  param_1[10] = iVar1;
  *(undefined4 *)(param_1[3] + 8) = uVar3;
  return 0;
}



// ============================================================
// Function: stage_updateSpriteMapping (FUN_6805e660)
// Address: 6805e660
// Size: 77 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateSpriteMapping(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  *(int *)(param_1 + 0x24) = param_2;
  uVar4 = scoreEngine_accessProperty(*(int *)(param_1 + 0x20),param_2);
  *(undefined4 *)(param_1 + 0x28) = uVar4;
  iVar3 = *(int *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0xc);
  events_handleKeyEventWrapper();
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = uVar4;
  return 0;
}



// ============================================================
// Function: stage_notifySpriteIdle (FUN_6805e6b0)
// Address: 6805e6b0
// Size: 134 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_notifySpriteIdle(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  if ((DAT_681962cc == 0) && (param_1[0x5f] != 0)) {
    DAT_681962cc = 1;
    if ((int *)param_1[0x1c7] != (int *)0x0) {
      cast_wrapApiCall(param_1[3],(int *)param_1[0x1c7],0x7a);
    }
    if (param_1[0x1c5] != 0) {
      crt_triggerBehaviors();
    }
    DAT_681962cc = 0;
  }
  if ((*(int *)(iVar1 + 100) == 0) && (param_1[0x5f] != 0)) {
    *(undefined4 *)(iVar1 + 100) = 1;
    events_dispatchEvent((int)param_1,6,1);
    *(undefined4 *)(iVar1 + 100) = 0;
  }
  return 0;
}



// ============================================================
// Function: stage_getSpriteScriptCount (FUN_6805e740)
// Address: 6805e740
// Size: 19 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getSpriteScriptCount(int param_1)
{
  cast_getScriptCount(*(int *)(param_1 + 0x14));
  return 0;
}



// ============================================================
// Function: stage_compileSpriteHandler (FUN_6805e760)
// Address: 6805e760
// Size: 89 bytes
// Params: int param_1, uint param_2, uint param_3, int * param_4, uint * param_5, void * param_6
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_compileSpriteHandler(int param_1,uint param_2,uint param_3,int *param_4,uint *param_5,void *param_6)

{
  uint uVar1;
  bool bVar2;
  int local_8;
  
  uVar1 = 0;
  bVar2 = true;
  local_8 = 0;
  if (param_1 != 0) {
    if (param_3 != 0xffffffff) {
      uVar1 = cast_compileHandler(*(int **)(param_1 + 0xc),param_2,param_3,&local_8,param_6);
      bVar2 = uVar1 == 0;
    }
    *param_4 = local_8;
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar1;
    }
  }
  return bVar2;
}



// ============================================================
// Function: stage_invalidateSpriteScript (FUN_6805e7c0)
// Address: 6805e7c0
// Size: 46 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_invalidateSpriteScript(int param_1,int *param_2)

{
  if (param_1 == 0) {
    return 0;
  }
  cast_invalidateScript(*(uint *)(param_1 + 0xc),*param_2);
  *param_2 = 0;
  return 1;
}



// ============================================================
// Function: stage_invalidateSpriteScriptByIndex (FUN_6805e7f0)
// Address: 6805e7f0
// Size: 46 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_invalidateSpriteScriptByIndex(int param_1,int *param_2)

{
  if (param_1 == 0) {
    return 0;
  }
  cast_invalidateScriptByIndex(*(uint *)(param_1 + 0xc),*param_2);
  *param_2 = 0;
  return 1;
}



// ============================================================
// Function: stage_findSpriteHandlerFrame (FUN_6805e820)
// Address: 6805e820
// Size: 74 bytes
// Params: int param_1, uint param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 stage_findSpriteHandlerFrame(int param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar3 = events_navigateToFrameEx(iVar1);
  iVar5 = 1;
  if (iVar3 < 1) {
    uVar2 = 0;
  }
  else {
    while( true ) {
      uVar4 = events_navigateToFrame(iVar1,(ushort)iVar5);
      uVar2 = 1;
      if (uVar4 == param_2) break;
      iVar5 = iVar5 + 1;
      if (iVar3 < iVar5) {
        return 0;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: stage_getSpriteHandlerArg (FUN_6805e870)
// Address: 6805e870
// Size: 27 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getSpriteHandlerArg(int param_1,int param_2,int param_3)
{
  cast_getHandlerArgValue(*(int *)(param_1 + 0xc),param_2,param_3);
  return 0;
}



// ============================================================
// Function: stage_dispatchSpriteReturn (FUN_6805e890)
// Address: 6805e890
// Size: 31 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchSpriteReturn(int param_1,int param_2,int param_3,int param_4)
{
  cast_dispatchReturn(*(int *)(param_1 + 0xc),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: stage_dispatchSpritePrev (FUN_6805e8b0)
// Address: 6805e8b0
// Size: 35 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchSpritePrev(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  cast_dispatchPrev(*(int *)(param_1 + 0xc),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: stage_dispatchSpriteNext (FUN_6805e8e0)
// Address: 6805e8e0
// Size: 35 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchSpriteNext(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  cast_dispatchNext(*(int *)(param_1 + 0xc),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: stage_updateSpriteRegion (FUN_6805e910)
// Address: 6805e910
// Size: 27 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateSpriteRegion(int param_1,int param_2)
{
  Ordinal_603(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_167
// Address: 6805e930
// Size: 29 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_167(int *param_1)

{
                    /* 0x5e930  167   */
  if (param_1 == (int *)0x0) {
    return 0;
  }
  sprites_initTextState(param_1);
  return 1;
}



// ============================================================
// Function: Ordinal_66
// Address: 6805e950
// Size: 24 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_66(int param_1,int param_2)
{
                    /* 0x5e950  66   */
  if (param_1 != 0) {
    sprites_setCursorVisible(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_67
// Address: 6805e970
// Size: 23 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_67(int param_1,undefined4 param_2)
{
                    /* 0x5e970  67   */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x1a8) = param_2;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_68
// Address: 6805e990
// Size: 24 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_68(int param_1)

{
                    /* 0x5e990  68   */
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x1a8);
}



// ============================================================
// Function: stage_setSpriteTrailMode (FUN_6805e9b0)
// Address: 6805e9b0
// Size: 23 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setSpriteTrailMode(int param_1,undefined4 param_2)
{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x188) = param_2;
  }
  return 0;
}



// ============================================================
// Function: stage_getSpriteConstraint (FUN_6805e9d0)
// Address: 6805e9d0
// Size: 24 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_getSpriteConstraint(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x1a4);
}



// ============================================================
// Function: stage_setInputEnabled (FUN_6805e9f0)
// Address: 6805e9f0
// Size: 43 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setInputEnabled(int *param_1,int param_2)
{
  if ((param_1 != (int *)0x0) && (param_1[0x5f] = param_2, param_2 == 0)) {
    Ordinal_167(param_1);
    Ordinal_66((int)param_1,1);
  }
  return 0;
}



// ============================================================
// Function: stage_setSpriteClickOffset (FUN_6805ea20)
// Address: 6805ea20
// Size: 42 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setSpriteClickOffset(int *param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x40) = param_2;
    *(undefined4 *)(iVar1 + 0x44) = param_3;
    iVar2 = sprites_getChannelRef(param_1[3]);
    *(int *)(iVar1 + 0x3c) = iVar2;
  }
  return 0;
}



// ============================================================
// Function: stage_getSpriteApiRef (FUN_6805ea50)
// Address: 6805ea50
// Size: 23 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getSpriteApiRef(int param_1,undefined4 param_2)
{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x1b0) = param_2;
  }
  return 0;
}



// ============================================================
// Function: stage_updateProperty (FUN_6805ea70)
// Address: 6805ea70
// Size: 28 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateProperty(int param_1,undefined4 param_2)
{
  if (param_1 != 0) {
    events_postMovieNotify(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: stage_swapSpriteIdleMode (FUN_6805ea90)
// Address: 6805ea90
// Size: 35 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_swapSpriteIdleMode(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x180);
  *(undefined4 *)(param_1 + 0x180) = param_2;
  return uVar1;
}



// ============================================================
// Function: stage_setSpriteEvalMode (FUN_6805eac0)
// Address: 6805eac0
// Size: 31 bytes
// Params: int param_1, char * param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setSpriteEvalMode(int param_1,char *param_2,byte param_3)
{
  if (param_1 != 0) {
    events_setMiawMoviePath(*(undefined4 **)(param_1 + 0xc),param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: stage_setSpriteEvalModeEx (FUN_6805eae0)
// Address: 6805eae0
// Size: 43 bytes
// Params: int param_1, char * param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setSpriteEvalModeEx(int param_1,char *param_2,byte param_3)
{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  events_setMiawMoviePath(puVar1,param_2,param_3);
  cast_getResultString((int)puVar1);
  return 0;
}



// ============================================================
// Function: stage_offsetSpriteRects (FUN_6805eb10)
// Address: 6805eb10
// Size: 143 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_offsetSpriteRects(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar2 = *(int *)(param_1 + 0x24);
  do {
    iVar1 = Ordinal_184(*(int *)(param_1 + 0x20),iVar2,&local_18,&local_28);
    if (iVar1 != 0) {
      local_20 = local_20 - local_28;
      local_1c = local_1c - local_24;
      local_10 = local_10 - local_18;
      local_c = local_c - local_14;
      local_28 = 0;
      local_24 = 0;
      local_18 = 0;
      local_14 = 0;
      Ordinal_1072(param_2,&local_28,&local_18);
    }
    iVar2 = scoreEngine_getPropertyAccess(*(int *)(param_1 + 0x20),iVar2);
  } while (iVar2 != 0);
  return 0;
}



// ============================================================
// Function: Ordinal_801
// Address: 6805eba0
// Size: 8 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_801(void)
{
                    /* 0x5eba0  801   */
  sprites_getMediaPlayerVersion();
  return 0;
}



// ============================================================
// Function: stage_initSpriteContext (FUN_6805ebb0)
// Address: 6805ebb0
// Size: 160 bytes
// Params: int * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initSpriteContext(int *param_1,uint *param_2)
{
  undefined4 *puVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  Ordinal_2330();
  if ((param_1[8] == 0) ||
     (puVar1 = *(undefined4 **)(param_1[8] + 0x20), puVar1 == (undefined4 *)0x0)) {
    local_14 = 0;
  }
  else {
    local_14 = *puVar1;
  }
  local_c = 0;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  events_executeFrameLoop(param_1,param_2);
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: stage_dispatchSpriteLifecycle (FUN_6805ec50)
// Address: 6805ec50
// Size: 49 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchSpriteLifecycle(int *param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    piVar2 = param_1;
    if (param_1[0xf] != 0) {
      iVar1 = param_1[0xf];
      piVar2 = (int *)lingo_getLifecycleRef(iVar1);
      piVar2[9] = iVar1;
    }
    events_executeMovieCommand(piVar2,param_2,(int)param_1);
  }
  return 0;
}



// ============================================================
// Function: stage_updateSpriteEvent (FUN_6805ec90)
// Address: 6805ec90
// Size: 36 bytes
// Params: int * param_1, undefined4 param_2, short param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateSpriteEvent(int *param_1,undefined4 param_2,short param_3,undefined4 param_4)
{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  events_handleMouseDown(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: Ordinal_62
// Address: 6805ecc0
// Size: 48 bytes
// Params: int param_1, undefined4 param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint Ordinal_62(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x5ecc0  62   */
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = sprites_processInput(param_1);
  uVar2 = sprites_processScrollInput(param_1,param_2);
  return uVar2 | uVar1;
}



// ============================================================
// Function: stage_handleSpriteResize (FUN_6805ecf0)
// Address: 6805ecf0
// Size: 28 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_handleSpriteResize(int param_1,int param_2)
{
  if (param_1 == 0) {
    return 0;
  }
  events_handleScrollEvent(param_1,param_2);
  return 0;
}



