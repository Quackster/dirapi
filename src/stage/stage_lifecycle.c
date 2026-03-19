// Module: stage
// Topic: Stage create, dispose, and API wrappers
// Address range: 0x6805DF10 - 0x6805E450
// Functions (17):
//   stage_setTitleString (FUN_6805DF10)
//   Ordinal_103 (FUN_6805DFB0)
//   stage_create (FUN_6805e110)
//   stage_dispose (FUN_6805e230)
//   stage_createContext (FUN_6805E290)
//   stage_destroyContext (FUN_6805E2B0)
//   stage_suspendContext (FUN_6805E340)
//   Ordinal_63 (FUN_6805E3B0)
//   Ordinal_64 (FUN_6805E3D0)
//   Ordinal_169 (FUN_6805E3E0)
//   Ordinal_65 (FUN_6805E3F0)
//   Ordinal_944 (FUN_6805E400)
//   stage_getActiveMovie (FUN_6805E410)
//   Ordinal_230 (FUN_6805E420)
//   Ordinal_232 (FUN_6805E430)
//   stage_findSpriteRef (FUN_6805E440)
//   stage_findSpriteState (FUN_6805E450)

// ============================================================
// Function: stage_setTitleString (FUN_6805DF10)
// Address: 6805df10
// Size: 152 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_setTitleString(int param_1,int param_2)

{
  int local_2c;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *local_c;
  int local_8;
  
  uVar3 = 0;
  local_8 = 0;
  local_c = (uint *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 == 0) {
    iVar2 = -2;
  }
  else {
    iVar2 = Ordinal_2200(0,&local_8);
    if (iVar2 == 0) goto LAB_6805df67;
    iVar2 = Ordinal_1166(local_8,param_2 + 1,stage_matchScoreHandler,0xffffffff,0xfffffffe,0);
    if (iVar2 == 0) goto LAB_6805df67;
    iVar2 = iVar2 + -1;
  }
  uVar3 = Ordinal_2201(iVar2);
LAB_6805df67:
  if (local_8 != 0) {
    Ordinal_1163(&local_8);
  }
  Ordinal_2202(&local_c);
  media_queryXtraProperty(*(undefined4 *)(iVar1 + 0x20),0xf,local_c);
  if (local_c != (uint *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return uVar3;
}



// ============================================================
// Function: Ordinal_103
// Address: 6805dfb0
// Size: 344 bytes
// Params: uint * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_103(uint *param_1)
{
  short sVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint local_6c [6];
  undefined4 *local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34 [2];
  char local_2c [36];
  uint local_8;
  
                    /* 0x5dfb0  103   */
  if (((param_1 != (uint *)0x0) && (param_1[3] != 0)) &&
     (iVar3 = lingo_getLifecycleRef(param_1[3]), iVar3 != 0)) {
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34[0] = 0;
    local_34[1] = 0;
    local_6c[0] = 0;
    local_6c[1] = 0;
    local_6c[2] = 0;
    local_6c[3] = 0;
    local_6c[4] = 0;
    local_6c[5] = 0;
    local_54 = (undefined4 *)0x0;
    sVar1 = (short)*param_1;
    pvVar2 = *(void **)(iVar3 + 0xc);
    if (sVar1 < 1) {
      local_50 = -5;
    }
    else {
      local_50 = (int)sVar1;
    }
    local_4c = 0;
    local_48 = 0;
    if (sVar1 < 1) {
      if (sVar1 < -8) {
        if (sVar1 < -0x10) {
          iVar4 = 0x328;
        }
        else {
          iVar4 = 0x644 - sVar1;
        }
      }
      else {
        iVar4 = 0x327 - sVar1;
      }
      props_storeObjectRef(pvVar2,iVar4,&local_44);
    }
    else {
      props_storeIntValue(pvVar2,(int)sVar1,&local_44);
    }
    props_storeIntValue(pvVar2,param_1[1],&local_3c);
    Ordinal_1232(local_2c,param_1[2]);
    props_loadStringValue((int)pvVar2,local_2c,local_34);
    param_1[2] = (uint)local_2c;
    local_54 = &local_4c;
    local_6c[0] = 0;
    local_6c[2] = 0x326;
    local_6c[5] = 4;
    sprites_dispatchChannelEvent(pvVar2,local_50,local_6c,1);
    props_releaseAndClear(pvVar2,local_34);
    media_queryXtraProperty(*(undefined4 *)(iVar3 + 0x20),9,param_1);
  }
  return 0;
}



// ============================================================
// Function: stage_create (FUN_6805e110)
// Address: 6805e110
// Size: 283 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 stage_create(int param_1)

{
  DAT_681962f8 = param_1;
  _DAT_681962fc = Ordinal_103;
  Ordinal_1471(Ordinal_103);
  DAT_68196300 = 0;
  _DAT_68196308 = *(undefined4 *)(param_1 + 0x8c);
  DAT_6819630c = *(undefined4 *)(param_1 + 0x90);
  DAT_68196310 = *(undefined4 *)(param_1 + 0x94);
  DAT_68196314 = *(undefined4 *)(param_1 + 0x78);
  DAT_68196318 = *(undefined4 *)(param_1 + 0x7c);
  _DAT_6819631c = *(undefined4 *)(param_1 + 0x80);
  _DAT_68196320 = *(undefined4 *)(param_1 + 0x84);
  _DAT_68196324 = *(undefined4 *)(param_1 + 0x88);
  DAT_68196328 = *(undefined4 *)(param_1 + 0x48);
  DAT_6819632c = *(undefined4 *)(param_1 + 0x4c);
  DAT_68196330 = *(undefined4 *)(param_1 + 0x50);
  DAT_68196334 = *(undefined4 *)(param_1 + 0x9c);
  DAT_68196338 = *(undefined4 *)(param_1 + 0xa0);
  DAT_6819633c = *(undefined4 *)(param_1 + 0xa4);
  DAT_68196340 = *(undefined4 *)(param_1 + 0xa8);
  DAT_68196344 = *(undefined4 *)(param_1 + 0xac);
  DAT_68196348 = *(undefined4 *)(param_1 + 0xb0);
  DAT_6819634c = *(undefined4 *)(param_1 + 0xb4);
  DAT_68196350 = *(undefined4 *)(param_1 + 0xb8);
  DAT_68196354 = *(undefined4 *)(param_1 + 0xbc);
  DAT_68196358 = *(undefined4 *)(param_1 + 0x1c0);
  return 1;
}



// ============================================================
// Function: stage_dispose (FUN_6805e230)
// Address: 6805e230
// Size: 81 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispose(void)
{
  if (DAT_68196300 != 0) {
    Ordinal_1163(&DAT_68196300);
  }
  Ordinal_1471(0);
  DAT_681962f8 = 0;
  score_freeSymbolTable(&DAT_68196304);
  DAT_68196304 = 0;
  Ordinal_1130(&DAT_681962f8,0xc);
  Ordinal_1130(&DAT_68196308,0x54);
  return 0;
}



// ============================================================
// Function: stage_createContext (FUN_6805E290)
// Address: 6805e290
// Size: 26 bytes
// Params: int param_1
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * stage_createContext(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = events_createMovieContext(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



// ============================================================
// Function: stage_destroyContext (FUN_6805E2B0)
// Address: 6805e2b0
// Size: 135 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_destroyContext(int *param_1)
{
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = *param_1;
  if (local_18 == 0) {
    return 0;
  }
  Ordinal_2330();
  local_14 = *(undefined4 *)(local_18 + 8);
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  events_destroyMovieInstance(&local_18);
  *param_1 = 0;
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: stage_suspendContext (FUN_6805E340)
// Address: 6805e340
// Size: 102 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_suspendContext(int *param_1)
{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    Ordinal_2330();
    local_14 = *(undefined4 *)(iVar1 + 8);
    local_c = 1;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    core_pollAsyncNetwork(*(int *)(iVar1 + 0x14));
    DAT_68196374 = (undefined4 *)local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_63
// Address: 6805e3b0
// Size: 30 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_63(int param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  
                    /* 0x5e3b0  63   */
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = sprites_hitTest(param_1,param_2,param_3);
  }
  return bVar1;
}



// ============================================================
// Function: Ordinal_64
// Address: 6805e3d0
// Size: 9 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_64(int param_1,uint *param_2)
{
                    /* 0x5e3d0  64   */
  sprites_getNextUpdateTime(param_1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_169
// Address: 6805e3e0
// Size: 9 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_169(undefined4 *param_1)
{
                    /* 0x5e3e0  169   */
  events_resolveWindowRef(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_65
// Address: 6805e3f0
// Size: 9 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_65(int param_1,int param_2)
{
                    /* 0x5e3f0  65   */
  sprites_setProperty(param_1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_944
// Address: 6805e400
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_944(int param_1)
{
                    /* 0x5e400  944   */
  events_releaseSessionData(param_1);
  return 0;
}



// ============================================================
// Function: stage_getActiveMovie (FUN_6805E410)
// Address: 6805e410
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getActiveMovie(int param_1)
{
  events_getStageActiveState(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_230
// Address: 6805e420
// Size: 9 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_230(int param_1,int param_2,int param_3)
{
                    /* 0x5e420  230   */
  events_dispatchWindowAction(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_232
// Address: 6805e430
// Size: 9 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_232(int *param_1,int param_2,uint param_3,int param_4)
{
                    /* 0x5e430  232   */
  events_getMiawSizeState(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: stage_findSpriteRef (FUN_6805E440)
// Address: 6805e440
// Size: 9 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_findSpriteRef(undefined4 *param_1,int param_2)
{
  events_handleMovieClose(param_1,param_2);
  return 0;
}



// ============================================================
// Function: stage_findSpriteState (FUN_6805E450)
// Address: 6805e450
// Size: 9 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_findSpriteState(undefined4 *param_1,int param_2)
{
  events_handleProjectorStart(param_1,param_2);
  return 0;
}



