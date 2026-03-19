// Module: core
// Topic: Built-in Lingo functions - system queries, rect/string operations
// Address range: 0x68018B30 - 0x68018EF0
// Functions (19):
//   core_checkRuntimeFlag1 (0x68018B30)
//   core_checkRuntimeFlag2 (0x68018B50)
//   core_checkRuntimeFlag3 (0x68018B70)
//   core_checkRuntimeFlag4 (0x68018B90)
//   core_getWindowCount (0x68018BF0)
//   core_getEventRef (0x68018C00)
//   core_getPlatformName (0x68018C10)
//   core_getEventInfoLeft (0x68018C80)
//   core_getEventInfoTop (0x68018CB0)
//   core_getEventInfoRight (0x68018CE0)
//   core_getEventInfoBottom (0x68018D10)
//   core_resetSprites (0x68018D40)
//   core_getEventDataSecond (0x68018D50)
//   core_getEventDataFirst (0x68018D70)
//   core_getObjectName (0x68018D90)
//   core_getMoviePathShort (0x68018DF0)
//   core_getMoviePathLong (0x68018E50)
//   core_getObjectText (0x68018EB0)
//   core_getObjectValue (0x68018EF0)

// ============================================================
// Function: core_checkRuntimeFlag1 (FUN_68018b30)
// Address: 68018b30
// Size: 22 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkRuntimeFlag1(void)

{
  int iVar1;

  iVar1 = sprites_restartApp();
  return iVar1 != 0;
}



// ============================================================
// Function: core_checkRuntimeFlag2 (FUN_68018b50)
// Address: 68018b50
// Size: 22 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkRuntimeFlag2(void)

{
  int iVar1;

  iVar1 = sprites_haltApp();
  return iVar1 != 0;
}



// ============================================================
// Function: core_checkRuntimeFlag3 (FUN_68018b70)
// Address: 68018b70
// Size: 22 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkRuntimeFlag3(void)

{
  int iVar1;

  iVar1 = sprites_quitApp();
  return iVar1 != 0;
}



// ============================================================
// Function: core_checkRuntimeFlag4 (FUN_68018b90)
// Address: 68018b90
// Size: 22 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkRuntimeFlag4(void)

{
  int iVar1;

  iVar1 = sprites_shutdownApp();
  return iVar1 != 0;
}



// ============================================================
// Function: core_getWindowCount (FUN_68018bf0)
// Address: 68018bf0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getWindowCount(int param_1)
{
  events_getMiawSoundRef(param_1);
  return 0;
}



// ============================================================
// Function: core_getEventRef (FUN_68018c00)
// Address: 68018c00
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getEventRef(int param_1)
{
  sprites_getEventRef(param_1);
  return 0;
}



// ============================================================
// Function: core_getPlatformName (FUN_68018c10)
// Address: 68018c10
// Size: 98 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getPlatformName(uint param_1)
{
  undefined4 uVar1;
  undefined4 local_18 [2];
  char local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  uint local_8;

  uVar1 = crt_getMiawProperty(param_1,0xd);
  local_10 = (char)uVar1;
  local_d = (undefined1)((uint)uVar1 >> 0x18);
  local_f = (undefined1)((uint)uVar1 >> 8);
  local_e = (undefined1)((uint)uVar1 >> 0x10);
  local_c = 0;
  props_loadCString(param_1,&local_10,local_18);
  props_popArgs(param_1,local_18);
  return 0;
}



// ============================================================
// Function: core_getEventInfoLeft (FUN_68018c80)
// Address: 68018c80
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getEventInfoLeft(int param_1)
{
  int local_18 [4];
  uint local_8;

  sprites_getEventInfo(param_1,local_18);
  return 0;
}



// ============================================================
// Function: core_getEventInfoTop (FUN_68018cb0)
// Address: 68018cb0
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getEventInfoTop(int param_1)
{
  int local_18 [4];
  uint local_8;

  sprites_getEventInfo(param_1,local_18);
  return 0;
}



// ============================================================
// Function: core_getEventInfoRight (FUN_68018ce0)
// Address: 68018ce0
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getEventInfoRight(int param_1)
{
  int local_18 [4];
  uint local_8;

  sprites_getEventInfo(param_1,local_18);
  return 0;
}



// ============================================================
// Function: core_getEventInfoBottom (FUN_68018d10)
// Address: 68018d10
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getEventInfoBottom(int param_1)
{
  int local_18 [4];
  uint local_8;

  sprites_getEventInfo(param_1,local_18);
  return 0;
}



// ============================================================
// Function: core_resetSprites (FUN_68018d40)
// Address: 68018d40
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resetSprites(void)
{
  sprites_beep();
  return 0;
}



// ============================================================
// Function: core_getEventDataSecond (FUN_68018d50)
// Address: 68018d50
// Size: 28 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getEventDataSecond(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;

  sprites_getEventData(param_1,&local_c);
  return local_8;
}



// ============================================================
// Function: core_getEventDataFirst (FUN_68018d70)
// Address: 68018d70
// Size: 28 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getEventDataFirst(int param_1)

{
  undefined4 local_c [2];

  sprites_getEventData(param_1,local_c);
  return local_c[0];
}



// ============================================================
// Function: core_getObjectName (FUN_68018d90)
// Address: 68018d90
// Size: 94 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getObjectName(int param_1)
{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;

  local_c = 4;
  local_8 = 0;
  puVar1 = (undefined4 *)sprites_extractMemberData(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    props_getValuePair(param_1,puVar1,&local_c);
    props_popArgs(param_1,&local_c);
    return 0;
  }
  props_readPascalString(param_1,&DAT_6817a914,&local_c);
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: core_getMoviePathShort (FUN_68018df0)
// Address: 68018df0
// Size: 86 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getMoviePathShort(int param_1)
{
  undefined4 local_410 [2];
  byte local_408 [1024];
  uint local_8;

  events_restoreMovieState(param_1,local_408);
  props_readPascalString(param_1,local_408,local_410);
  props_popArgs(param_1,local_410);
  return 0;
}



// ============================================================
// Function: core_getMoviePathLong (FUN_68018e50)
// Address: 68018e50
// Size: 86 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getMoviePathLong(int param_1)
{
  undefined4 local_410 [2];
  byte local_408 [1024];
  uint local_8;

  events_initMoviePlayback(param_1,(undefined2 *)local_408);
  props_readPascalString(param_1,local_408,local_410);
  props_popArgs(param_1,local_410);
  return 0;
}



// ============================================================
// Function: core_getObjectText (FUN_68018eb0)
// Address: 68018eb0
// Size: 63 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getObjectText(int param_1)
{
  undefined4 *puVar1;
  undefined4 local_c [2];

  puVar1 = (undefined4 *)events_handleStageResize(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    props_getValuePair(param_1,puVar1,local_c);
    props_popArgs(param_1,local_c);
    return 0;
  }
  props_setError(param_1,3);
  return 0;
}



// ============================================================
// Function: core_getObjectValue (FUN_68018ef0)
// Address: 68018ef0
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getObjectValue(int param_1)
{
  uint local_c [2];

  events_syncChannelState(param_1,local_c,0);
  props_popArgs(param_1,local_c);
  return 0;
}


