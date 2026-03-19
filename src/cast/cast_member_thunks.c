// Module: cast
// Topic: cast_resolveMember thunk wrappers and movie type registration
// Address range: 0x6802D010 - 0x6802D490
// Functions (22):
//   cast_dispatchPlayerOp
//   cast_resolveCastMemberOp
//   cast_resolveActorList
//   cast_resolveScriptList
//   cast_resolveTimeoutList
//   cast_resolveGoFrame
//   cast_resolvePause
//   cast_resolveDoCommand
//   cast_resolvePreload
//   cast_resolveTell
//   cast_resolveScriptNum
//   cast_resolveTimeout
//   cast_resolveHilite
//   cast_writeScoreXtraThunk
//   cast_readScoreXtraThunk
//   cast_registerPlayerScope
//   cast_dispatchObjectTag
//   cast_loadThunkResource
//   cast_getMemberThunk
//   cast_createAccessObject
//   cast_lookupTableEntry
//   Ordinal_35

// ============================================================
// Function: cast_dispatchPlayerOp (FUN_6802d010)
// Address: 6802d010
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchPlayerOp(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  cast_dispatchScoreOp(param_1,param_3,param_4,param_5,"_player");
  return 0;
}



// ============================================================
// Function: cast_resolveCastMemberOp (FUN_6802d040)
// Address: 6802d040
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveCastMemberOp(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2d5,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveActorList (FUN_6802d070)
// Address: 6802d070
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveActorList(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x310,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveScriptList (FUN_6802d0a0)
// Address: 6802d0a0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveScriptList(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x311,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveTimeoutList (FUN_6802d0d0)
// Address: 6802d0d0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveTimeoutList(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x3b9,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveGoFrame (FUN_6802d100)
// Address: 6802d100
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveGoFrame(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1c9,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolvePause (FUN_6802d130)
// Address: 6802d130
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolvePause(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1cc,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveDoCommand (FUN_6802d160)
// Address: 6802d160
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveDoCommand(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1db,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolvePreload (FUN_6802d190)
// Address: 6802d190
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolvePreload(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x14b,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveTell (FUN_6802d1c0)
// Address: 6802d1c0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveTell(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x2f7,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveScriptNum (FUN_6802d1f0)
// Address: 6802d1f0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveScriptNum(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x312,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveTimeout (FUN_6802d220)
// Address: 6802d220
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveTimeout(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x382,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveHilite (FUN_6802d250)
// Address: 6802d250
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveHilite(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x166,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_writeScoreXtraThunk (FUN_6802d280)
// Address: 6802d280
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_writeScoreXtraThunk(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_writeScoreXtra(param_1,param_3,param_4,0x23,0x6818d040);
  return 0;
}



// ============================================================
// Function: cast_readScoreXtraThunk (FUN_6802d2a0)
// Address: 6802d2a0
// Size: 31 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_readScoreXtraThunk(int param_1,undefined4 param_2,uint param_3,uint *param_4)
{
  cast_readScoreXtraEx(param_1,param_3,param_4,0x23,0x6818d040);
  return 0;
}



// ============================================================
// Function: cast_registerPlayerScope (FUN_6802d2c0)
// Address: 6802d2c0
// Size: 157 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerPlayerScope(int param_1,uint param_2)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  piVar1 = events_createScope(param_1,param_2,"_player",&PTR_s__player_6818d160,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_DAT_6818cd58);
    if (iVar2 != 0) {
      iVar2 = xtra_queryPlatform(param_1,piVar1,(int *)&PTR_s_activeWindow_6818ce00);
      if (iVar2 != 0) {
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x54);
        events_registerProperty(param_1,piVar1,"sound",uVar3,uVar4,uVar5);
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x7c);
        events_registerProperty(param_1,piVar1,"window",uVar3,uVar4,uVar5);
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = cast_getMemberThunk(param_1,0x7d);
        events_registerProperty(param_1,piVar1,"xtra",uVar3,uVar4,uVar5);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchObjectTag (FUN_6802d360)
// Address: 6802d360
// Size: 60 bytes
// Params: uint param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_dispatchObjectTag(uint param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*param_4 == 0x80000001) {
    uVar1 = xtra_getObjectTag(param_1,param_2);
    uVar2 = cast_resolveMemberProperty((int)uVar1 >> 2,param_1,param_3,param_4);
    return uVar2;
  }
  return 1;
}



// ============================================================
// Function: cast_loadThunkResource (FUN_6802d3a0)
// Address: 6802d3a0
// Size: 76 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_loadThunkResource(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = xtra_getPlatformData(param_1);
  puVar1 = *(undefined4 **)(**(int **)(iVar2 + 8) + 0x5a0);
  uVar3 = xtra_getPlatformFlags(param_1);
  iVar2 = xtra_loadResource(param_1,&PTR_s_access_6818d1a8,puVar1,uVar3);
  if (iVar2 != 0) {
    xtra_getResourceById(param_1,iVar2,param_2 * 4);
  }
  return iVar2;
}



// ============================================================
// Function: cast_getMemberThunk (FUN_6802d3f0)
// Address: 6802d3f0
// Size: 9 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMemberThunk(int param_1,int param_2)
{
  cast_loadThunkResource(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_createAccessObject (FUN_6802d400)
// Address: 6802d400
// Size: 64 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_createAccessObject(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = xtra_getPlatformData(param_1);
  piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_access_6818d1a8,0,1,(int *)0x0,
                        (int *)0x0,(int *)0x0,(int *)0x0);
  *(int **)(**(int **)(iVar1 + 8) + 0x5a8) = piVar2;
  return 0;
}



// ============================================================
// Function: cast_lookupTableEntry (FUN_6802d440)
// Address: 6802d440
// Size: 74 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_lookupTableEntry(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  int *unaff_EDI;
  
  piVar3 = (int *)(*param_2 + (int)param_2);
  if ((param_1 < *piVar3) &&
     ((*piVar3 + -1 <= param_1 || (piVar3[param_1 + 2] <= piVar3[param_1 + 3])))) {
    iVar1 = piVar3[param_1 + 2];
    iVar2 = piVar3[param_1 + 1];
    *unaff_ESI = iVar1 - iVar2;
    if ((-1 < piVar3[param_1 + 1]) && (-1 < iVar1 - iVar2)) {
      *unaff_EDI = piVar3[param_1 + 1] + 8 + *piVar3 * 4 + (int)piVar3;
      return 0;
    }
  }
  *unaff_EDI = 0;
  *unaff_ESI = 0;
  return 0;
}



// ============================================================
// Function: Ordinal_35
// Address: 6802d490
// Size: 47 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_35(int param_1)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x2d490  35   */
  iVar1 = Ordinal_1111(param_1 + 8,1);
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_1114(iVar1);
    *piVar2 = param_1;
    Ordinal_1115(iVar1);
  }
  return iVar1;
}



