// Module: cast
// Topic: Scope registration - system, sound, mouse, key, movie, player subsystems
// Address range: 0x6802C070 - 0x6802CF20
// Functions (75):
//   cast_resolveTimeBuiltin
//   cast_resolveFontList
//   cast_resolveUserName
//   cast_resolveEnvironment
//   cast_writeSystemXtra
//   cast_readSystemXtra
//   cast_registerSystemTypes
//   cast_dispatchSoundOp
//   cast_resolveRetryOnSync
//   cast_resolveSoundProp1a2
//   cast_resolveChannelCount
//   cast_writeSoundXtra
//   cast_readSoundXtra
//   cast_registerSoundTypes
//   cast_dispatchMouseOp
//   cast_writeMouseXtra
//   cast_readMouseXtra
//   cast_registerMouseTypes
//   cast_dispatchKeyOp
//   cast_resolveRegisteredHandler
//   cast_writeKeyXtra
//   cast_readKeyXtra
//   cast_registerKeyTypes
//   cast_dispatchMovieOp
//   cast_resolveChannelHigh
//   cast_resolveChannelLow
//   cast_resolveCastLookup
//   cast_resolveCastMember
//   cast_resolveProp161
//   cast_resolveProp60f
//   cast_resolveProp610
//   cast_resolveProp611
//   cast_resolveIntersectCast
//   cast_resolveMemberRefOp
//   cast_resolveProp1d5
//   cast_resolveProp1c8
//   cast_resolveProp1cb
//   cast_resolveProp1ce
//   cast_resolveProp1d7
//   cast_resolveProp1d8
//   cast_resolveProp1d9
//   cast_resolveProp1da
//   cast_resolveProp1dc
//   cast_resolveProp2f4
//   cast_resolveProp1e0
//   cast_resolveProp2f3
//   cast_resolveProp20b
//   cast_resolveProp24c
//   cast_resolveProp24d
//   cast_resolveProp24f
//   cast_resolveProp250
//   cast_resolveProp252
//   cast_resolveProp251
//   cast_resolveProp24e
//   cast_resolveProp25f
//   cast_resolveProp260
//   cast_resolveProp261
//   cast_resolveProp2de
//   cast_resolveProp2df
//   cast_resolveProp313
//   cast_resolveProp331
//   cast_resolveProp332
//   cast_resolveFieldOfMember
//   cast_resolveConvertScript
//   cast_resolveInvokeHandlers
//   cast_resolveProp22c
//   cast_resolveIterateForward
//   cast_resolveIterateReverse
//   cast_resolveOpenUrl
//   cast_checkPropertyInFrame
//   cast_scanFramesForProperty
//   cast_tryResolveXtra
//   cast_writeMovieXtra
//   cast_readMovieXtra
//   cast_registerMovieTypes

// ============================================================
// Function: cast_resolveTimeBuiltin (FUN_6802c070)
// Address: 6802c070
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveTimeBuiltin(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x84,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveFontList (FUN_6802c0a0)
// Address: 6802c0a0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveFontList(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x646,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveUserName (FUN_6802c0d0)
// Address: 6802c0d0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveUserName(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x647,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveEnvironment (FUN_6802c100)
// Address: 6802c100
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveEnvironment(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x648,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_writeSystemXtra (FUN_6802c130)
// Address: 6802c130
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_writeSystemXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_writeScoreXtra(param_1,param_3,param_4,8,0x6818bf58);
  return 0;
}



// ============================================================
// Function: cast_readSystemXtra (FUN_6802c150)
// Address: 6802c150
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_readSystemXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_readScoreXtraEx(param_1,param_3,param_4,8,0x6818bf58);
  return 0;
}



// ============================================================
// Function: cast_registerSystemTypes (FUN_6802c170)
// Address: 6802c170
// Size: 72 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerSystemTypes(int param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = events_createScope(param_1,param_2,"_system",&PTR_s__system_6818bfa0,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_s_version_6818bdf8);
    if (iVar2 != 0) {
      xtra_queryPlatform(param_1,piVar1,(int *)&PTR_s_colorDepth_6818bec8);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchSoundOp (FUN_6802c1c0)
// Address: 6802c1c0
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchSoundOp(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  cast_dispatchScoreOp(param_1,param_3,param_4,param_5,"_sound");
  return 0;
}



// ============================================================
// Function: cast_resolveRetryOnSync (FUN_6802c1f0)
// Address: 6802c1f0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveRetryOnSync(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x124,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveSoundProp1a2 (FUN_6802c220)
// Address: 6802c220
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveSoundProp1a2(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1a2,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveChannelCount (FUN_6802c250)
// Address: 6802c250
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveChannelCount(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c3,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_writeSoundXtra (FUN_6802c280)
// Address: 6802c280
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_writeSoundXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_writeScoreXtra(param_1,param_3,param_4,6,0x6818c0a0);
  return 0;
}



// ============================================================
// Function: cast_readSoundXtra (FUN_6802c2a0)
// Address: 6802c2a0
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_readSoundXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_readScoreXtraEx(param_1,param_3,param_4,6,0x6818c0a0);
  return 0;
}



// ============================================================
// Function: cast_registerSoundTypes (FUN_6802c2c0)
// Address: 6802c2c0
// Size: 72 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerSoundTypes(int param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = events_createScope(param_1,param_2,"_sound",&PTR_s__sound_6818c0d8,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_DAT_6818bfe8);
    if (iVar2 != 0) {
      xtra_queryPlatform(param_1,piVar1,(int *)&PTR_s_soundDevice_6818c030);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchMouseOp (FUN_6802c310)
// Address: 6802c310
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchMouseOp(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  cast_dispatchScoreOp(param_1,param_3,param_4,param_5,"_mouse");
  return 0;
}



// ============================================================
// Function: cast_writeMouseXtra (FUN_6802c340)
// Address: 6802c340
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_writeMouseXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_writeScoreXtra(param_1,param_3,param_4,0x10,0x6818c248);
  return 0;
}



// ============================================================
// Function: cast_readMouseXtra (FUN_6802c360)
// Address: 6802c360
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_readMouseXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_readScoreXtraEx(param_1,param_3,param_4,0x10,0x6818c248);
  return 0;
}



// ============================================================
// Function: cast_registerMouseTypes (FUN_6802c380)
// Address: 6802c380
// Size: 72 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerMouseTypes(int param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = events_createScope(param_1,param_2,"_mouse",&PTR_s__mouse_6818c2d0,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_DAT_6818c120);
    if (iVar2 != 0) {
      xtra_queryPlatform(param_1,piVar1,(int *)&PTR_s_clickLoc_6818c138);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchKeyOp (FUN_6802c3d0)
// Address: 6802c3d0
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchKeyOp(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  cast_dispatchScoreOp(param_1,param_3,param_4,param_5,"_key");
  return 0;
}



// ============================================================
// Function: cast_resolveRegisteredHandler (FUN_6802c400)
// Address: 6802c400
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveRegisteredHandler(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2db,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_writeKeyXtra (FUN_6802c430)
// Address: 6802c430
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_writeKeyXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_writeScoreXtra(param_1,param_3,param_4,6,0x6818c3b0);
  return 0;
}



// ============================================================
// Function: cast_readKeyXtra (FUN_6802c450)
// Address: 6802c450
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_readKeyXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_readScoreXtraEx(param_1,param_3,param_4,6,0x6818c3b0);
  return 0;
}



// ============================================================
// Function: cast_registerKeyTypes (FUN_6802c470)
// Address: 6802c470
// Size: 72 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerKeyTypes(int param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = events_createScope(param_1,param_2,"_key",&PTR_DAT_6818c3e8,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_DAT_6818c318);
    if (iVar2 != 0) {
      xtra_queryPlatform(param_1,piVar1,(int *)&PTR_s_commandDown_6818c340);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchMovieOp (FUN_6802c4c0)
// Address: 6802c4c0
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchMovieOp(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  cast_dispatchScoreOp(param_1,param_3,param_4,param_5,"_movie");
  return 0;
}



// ============================================================
// Function: cast_resolveChannelHigh (FUN_6802c4f0)
// Address: 6802c4f0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveChannelHigh(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c5,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveChannelLow (FUN_6802c520)
// Address: 6802c520
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveChannelLow(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c6,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveCastLookup (FUN_6802c550)
// Address: 6802c550
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveCastLookup(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x335,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveCastMember (FUN_6802c580)
// Address: 6802c580
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveCastMember(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c1,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp161 (FUN_6802c5b0)
// Address: 6802c5b0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp161(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x161,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp60f (FUN_6802c5e0)
// Address: 6802c5e0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp60f(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x60f,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp610 (FUN_6802c610)
// Address: 6802c610
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp610(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x610,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp611 (FUN_6802c640)
// Address: 6802c640
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp611(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x611,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveIntersectCast (FUN_6802c670)
// Address: 6802c670
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveIntersectCast(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1e7,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveMemberRefOp (FUN_6802c6a0)
// Address: 6802c6a0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveMemberRefOp(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c2,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1d5 (FUN_6802c6d0)
// Address: 6802c6d0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1d5(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1d5,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1c8 (FUN_6802c700)
// Address: 6802c700
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1c8(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c8,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1cb (FUN_6802c730)
// Address: 6802c730
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1cb(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1cb,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1ce (FUN_6802c760)
// Address: 6802c760
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1ce(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1ce,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1d7 (FUN_6802c790)
// Address: 6802c790
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1d7(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1d7,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1d8 (FUN_6802c7c0)
// Address: 6802c7c0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1d8(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1d8,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1d9 (FUN_6802c7f0)
// Address: 6802c7f0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1d9(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1d9,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1da (FUN_6802c820)
// Address: 6802c820
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1da(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1da,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1dc (FUN_6802c850)
// Address: 6802c850
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1dc(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1dc,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp2f4 (FUN_6802c880)
// Address: 6802c880
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp2f4(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2f4,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp1e0 (FUN_6802c8b0)
// Address: 6802c8b0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp1e0(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1e0,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp2f3 (FUN_6802c8e0)
// Address: 6802c8e0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp2f3(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2f3,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp20b (FUN_6802c910)
// Address: 6802c910
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp20b(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x20b,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp24c (FUN_6802c940)
// Address: 6802c940
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp24c(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x24c,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp24d (FUN_6802c970)
// Address: 6802c970
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp24d(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x24d,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp24f (FUN_6802c9a0)
// Address: 6802c9a0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp24f(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x24f,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp250 (FUN_6802c9d0)
// Address: 6802c9d0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp250(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x250,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp252 (FUN_6802ca00)
// Address: 6802ca00
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp252(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x252,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp251 (FUN_6802ca30)
// Address: 6802ca30
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp251(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x251,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp24e (FUN_6802ca60)
// Address: 6802ca60
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp24e(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x24e,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp25f (FUN_6802ca90)
// Address: 6802ca90
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp25f(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x25f,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp260 (FUN_6802cac0)
// Address: 6802cac0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp260(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x260,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp261 (FUN_6802caf0)
// Address: 6802caf0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp261(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x261,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp2de (FUN_6802cb20)
// Address: 6802cb20
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp2de(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2de,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp2df (FUN_6802cb50)
// Address: 6802cb50
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp2df(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2df,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp313 (FUN_6802cb80)
// Address: 6802cb80
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp313(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x313,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp331 (FUN_6802cbb0)
// Address: 6802cbb0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp331(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x331,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp332 (FUN_6802cbe0)
// Address: 6802cbe0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp332(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x332,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveFieldOfMember (FUN_6802cc10)
// Address: 6802cc10
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveFieldOfMember(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x82,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveConvertScript (FUN_6802cc40)
// Address: 6802cc40
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveConvertScript(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x23c,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveInvokeHandlers (FUN_6802cc70)
// Address: 6802cc70
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveInvokeHandlers(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x225,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveProp22c (FUN_6802cca0)
// Address: 6802cca0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveProp22c(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x22c,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveIterateForward (FUN_6802ccd0)
// Address: 6802ccd0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveIterateForward(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0xc1,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveIterateReverse (FUN_6802cd00)
// Address: 6802cd00
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveIterateReverse(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0xc2,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveOpenUrl (FUN_6802cd30)
// Address: 6802cd30
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveOpenUrl(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x655,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_checkPropertyInFrame (FUN_6802cd60)
// Address: 6802cd60
// Size: 100 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_checkPropertyInFrame(uint param_1)

{
  int in_EAX;
  uint *puVar1;
  int unaff_EDI;
  
  puVar1 = score_lookupProperty(*(int **)(**(int **)(**(int **)(unaff_EDI + 8) + 0x4f4) + 0x24 +
                                 in_EAX * 0x18),param_1,0,(uint *)0x0);
  if ((puVar1 != (uint *)0x0) &&
     (*(code **)(**(int **)(**(int **)(**(int **)(unaff_EDI + 8) + 0x4f4) + 0x28 + in_EAX * 0x18) +
                 0x20 + puVar1[1] * 0x18) == props_getStackDepth)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_scanFramesForProperty (FUN_6802cdd0)
// Address: 6802cdd0
// Size: 81 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_scanFramesForProperty(uint param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = events_navigateToFrameEx(in_EAX);
  iVar4 = 1;
  if (0 < iVar1) {
    do {
      uVar2 = events_navigateToFrame(in_EAX,(ushort)iVar4);
      if ((-1 < (int)(uVar2 - 1)) && (iVar3 = cast_checkPropertyInFrame(param_1), iVar3 != 0)) {
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar1);
  }
  return 0;
}



// ============================================================
// Function: cast_tryResolveXtra (FUN_6802ce30)
// Address: 6802ce30
// Size: 138 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_tryResolveXtra(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint unaff_EBX;
  int unaff_ESI;
  char *local_c;
  undefined4 local_8;
  
  local_8 = xtra_getPlatformData(unaff_ESI);
  if (((((unaff_EBX & 1) == 0) || (unaff_EBX == 0x80000001)) && (*param_1 == -0x7fffffff)) &&
     ((uVar1 = cast_getScoreXtraValue(local_8,unaff_ESI,unaff_EBX,&local_c), -1 < (int)uVar1 &&
      (iVar2 = cast_scanFramesForProperty(uVar1), iVar2 != 0)))) {
    uVar3 = xtra_getPlatformFlags(unaff_ESI);
    iVar2 = cast_registerXtraSymbol(unaff_ESI,0x6801cea0,0,0,uVar3,local_c,uVar1);
    if (iVar2 != 0) {
      iVar2 = xtra_getScriptContext(iVar2);
      *param_1 = iVar2;
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_writeMovieXtra (FUN_6802cec0)
// Address: 6802cec0
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_writeMovieXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_writeScoreXtra(param_1,param_3,param_4,0x46,0x6818cad8);
  return 0;
}



// ============================================================
// Function: cast_readMovieXtra (FUN_6802cee0)
// Address: 6802cee0
// Size: 59 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_readMovieXtra(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = cast_tryResolveXtra((int *)param_4);
  if (iVar1 != 0) {
    return 1;
  }
  uVar2 = cast_readScoreXtraEx(param_1,param_3,param_4,0x46,0x6818cad8);
  return uVar2;
}



// ============================================================
// Function: cast_registerMovieTypes (FUN_6802cf20)
// Address: 6802cf20
// Size: 226 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerMovieTypes(int param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  piVar1 = events_createScope(param_1,param_2,"_movie",&PTR_s__movie_6818cd10,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_DAT_6818c430);
    if (iVar2 != 0) {
      iVar2 = xtra_queryPlatform(param_1,piVar1,(int *)&PTR_s_aboutInfo_6818c668);
      if (iVar2 != 0) {
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x58);
        events_registerProperty(param_1,piVar1,"member",uVar3,uVar4,uVar5);
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x68);
        events_registerProperty(param_1,piVar1,"castLib",uVar3,uVar4,uVar5);
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x7b);
        events_registerProperty(param_1,piVar1,"script",uVar3,uVar4,uVar5);
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x2e);
        events_registerProperty(param_1,piVar1,"sprite",uVar3,uVar4,uVar5);
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x5fd);
        events_registerProperty(param_1,piVar1,"channel",uVar3,uVar4,uVar5);
      }
    }
  }
  return 0;
}



