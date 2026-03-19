// Module: strings
// Topic: Lingo bytecode command handlers - sprite, movie, sound, text operations
// Address range: 0x6816af40 - 0x6816dd60
// Functions (73):
//   strings_cmdGetChannel
//   strings_cmdSetChannel
//   strings_cmdAlert
//   strings_cmdSetSprite
//   strings_initLingoCommands
//   strings_cmdPlayDone
//   strings_cmdUnloadCast
//   strings_cmdSetStageParam
//   strings_cmdOpenWindow
//   strings_cmdMoveWindow
//   strings_cmdResizeWindow
//   strings_cmdSetWindowParam
//   strings_cmdHalt
//   strings_cmdBeep
//   strings_cmdSetPreference
//   strings_cmdDoPlatformOp
//   strings_cmdCursor
//   strings_cmdPuppetTransition
//   strings_cmdPuppetPalette
//   strings_cmdPuppetSound
//   strings_cmdShutdown
//   strings_cmdOpenFile
//   strings_cmdIdle
//   strings_cmdSound
//   strings_cmdSoundHelper
//   strings_cmdSelectChannel
//   strings_cmdRepeatLoop
//   strings_cmdPlay
//   strings_cmdGoFrame
//   strings_cmdGoMovie
//   strings_cmdGoUrl
//   strings_cmdPlayMovie
//   strings_cmdDoMenu
//   strings_cmdPreloadCast
//   strings_cmdUpdateStage
//   strings_cmdPutValue
//   strings_cmdDebugPrint
//   strings_executeLingo
//   strings_cmdInsertBefore
//   strings_cmdInsertAfter
//   strings_cmdReplace
//   strings_cmdDeleteItem
//   strings_cmdDeleteLine
//   strings_cmdDeleteChar
//   strings_cmdHilite
//   strings_cmdSetProp
//   strings_cmdGetProp
//   strings_cmdSetAt
//   strings_cmdAddAt
//   strings_cmdDeleteAt
//   strings_cmdSort
//   strings_cmdCallHandler
//   strings_cmdCallMethod
//   strings_cmdTell
//   strings_cmdCase
//   strings_registerCommands
//   strings_compileIf
//   strings_compileRepeat
//   strings_compileRepeatWith
//   strings_compileReturn
//   strings_compileTell
//   strings_compileExit
//   strings_compileHandlerArgs

// ============================================================
// Function: strings_cmdGetChannel (FUN_6816af40)
// Address: 6816af40
// Size: 69 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdGetChannel(uint param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = param_1;
  iVar2 = sprites_getChannelRef(param_1);
  param_1 = 0x7fffffff - iVar2;
  iVar3 = props_getTypedProperty(uVar1,1,4,&param_1);
  if (iVar3 != 0) {
    events_configureMiawStage(uVar1,iVar2,param_1);
    props_popArgs(uVar1,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdSetChannel (FUN_6816af90)
// Address: 6816af90
// Size: 222 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdSetChannel(int param_1)
{
  int iVar1;
  int local_10;
  int local_c;
  short local_8;
  short local_6;
  
  local_8 = 0;
  iVar1 = props_getInt(param_1);
  if (0 < iVar1) {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_10 != 4) || (local_c != 0)) {
      local_8 = 0;
      crt_executePlatformSet(param_1,&local_10,sprites_resetMember,&local_8,0x23);
      if ((local_6 != 0) && (iVar1 = sprites_getMemberData(param_1,(undefined4 *)&local_8), iVar1 == 0)) {
        props_setError(param_1,0x5e);
        return 0;
      }
      goto LAB_6816b042;
    }
  }
  local_6 = 0;
LAB_6816b042:
  iVar1 = sprites_initTextForMember(param_1,(undefined4 *)&local_8);
  if (iVar1 != 0) {
    props_popArgs(param_1,(undefined4 *)0x0);
    return 0;
  }
  props_setError(param_1,0x23);
  return 0;
}



// ============================================================
// Function: strings_cmdAlert (FUN_6816b070)
// Address: 6816b070
// Size: 30 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdAlert(uint param_1)
{
  crt_setMiawProperty(param_1,0x15,1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdSetSprite (FUN_6816b090)
// Address: 6816b090
// Size: 148 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSetSprite(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint local_c;
  uint local_8;
  
  uVar1 = param_1;
  iVar2 = sprites_getStageRef(param_1);
  if (iVar2 != 0) {
    props_reportError(uVar1,0x66);
    return 0;
  }
  local_c = sprites_getEventRef(uVar1);
  param_1 = 1;
  local_8 = local_c;
  iVar2 = props_getTypedProperty(uVar1,1,4,&local_c);
  if (iVar2 != 0) {
    iVar2 = props_getTypedProperty(uVar1,2,4,&local_8);
    if (iVar2 != 0) {
      iVar2 = props_getTypedProperty(uVar1,3,4,&param_1);
      if (iVar2 != 0) {
        sprites_setPropertyExData(uVar1,local_c,local_8,param_1);
        props_popArgs(uVar1,(undefined4 *)0x0);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_initLingoCommands (FUN_6816b130)
// Address: 6816b130
// Size: 22 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_initLingoCommands(void)
{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x74) = 9;
  props_popArgs(unaff_ESI,(undefined4 *)0x0);
  props_unwindStack(unaff_ESI);
  return 0;
}



// ============================================================
// Function: strings_cmdPlayDone (FUN_6816b150)
// Address: 6816b150
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdPlayDone(int param_1)
{
  sprites_setCursorHand(param_1);
  strings_initLingoCommands();
  return 0;
}



// ============================================================
// Function: strings_cmdUnloadCast (FUN_6816b170)
// Address: 6816b170
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdUnloadCast(int param_1)
{
  sprites_setCursorCrosshair(param_1);
  *(undefined4 *)(param_1 + 0x74) = 9;
  props_popArgs(param_1,(undefined4 *)0x0);
  props_unwindStack(param_1);
  return 0;
}



// ============================================================
// Function: strings_cmdSetStageParam (FUN_6816b1a0)
// Address: 6816b1a0
// Size: 169 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSetStageParam(uint param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_8;
  
  uVar1 = param_1;
  iVar5 = props_getTypedValue(param_1,1,4,&local_8);
  if ((((iVar5 != 0) && (iVar5 = crt_setPlatformParam(uVar1,local_8), iVar5 != 0)) &&
      (iVar5 = props_getTypedValue(uVar1,2,4,&param_1), uVar2 = param_1, iVar5 != 0)) &&
     (((iVar5 = props_getTypedValue(uVar1,3,4,&param_1), uVar3 = param_1, iVar5 != 0 &&
       (iVar5 = props_getTypedValue(uVar1,4,4,&param_1), uVar4 = param_1, iVar5 != 0)) &&
      (iVar5 = props_getTypedValue(uVar1,5,4,&param_1), iVar5 != 0)))) {
    events_setMiawChannelData(uVar1,local_8,uVar3,uVar2,param_1,uVar4);
    props_popArgs(uVar1,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdOpenWindow (FUN_6816b250)
// Address: 6816b250
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdOpenWindow(int param_1)
{
  events_getMiawStageColor(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdMoveWindow (FUN_6816b270)
// Address: 6816b270
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdMoveWindow(int param_1)
{
  int iVar1;
  
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  sprites_setCursorArrow(param_1);
  strings_initLingoCommands();
  return 0;
}



// ============================================================
// Function: strings_cmdResizeWindow (FUN_6816b2b0)
// Address: 6816b2b0
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdResizeWindow(int param_1)
{
  int iVar1;
  
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  sprites_setCursorWait(param_1);
  strings_initLingoCommands();
  return 0;
}



// ============================================================
// Function: strings_cmdSetWindowParam (FUN_6816b2f0)
// Address: 6816b2f0
// Size: 132 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSetWindowParam(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint local_c;
  uint local_8;
  
  uVar1 = param_1;
  iVar2 = props_getTypedValue(param_1,1,4,&local_c);
  if (iVar2 != 0) {
    iVar2 = crt_setPlatformParam(uVar1,local_c);
    if (iVar2 != 0) {
      iVar2 = props_getTypedValue(uVar1,2,4,&local_8);
      if (iVar2 != 0) {
        iVar2 = crt_setPlatformParam(uVar1,local_8);
        if (iVar2 != 0) {
          param_1 = 0;
          iVar2 = props_getTypedProperty(uVar1,3,4,&param_1);
          if (iVar2 != 0) {
            events_setMiawCursorRef(uVar1,local_c,local_8,param_1);
            props_popArgs(uVar1,(undefined4 *)0x0);
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_cmdHalt (FUN_6816b380)
// Address: 6816b380
// Size: 30 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdHalt(uint param_1)
{
  crt_setMiawProperty(param_1,0x1c,1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdBeep (FUN_6816b3a0)
// Address: 6816b3a0
// Size: 151 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdBeep(int param_1)
{
  int iVar1;
  int local_20;
  int local_1c;
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (0 < iVar1) {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_1c = DAT_6819776c;
    local_20 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_1c = ((int *)(size_t)_DAT_68197764)[1];
      local_20 = *(int *)(size_t)_DAT_68197764;
    }
    props_createRect(param_1,&local_20);
  }
  events_resetMiawChannel(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdSetPreference (FUN_6816b440)
// Address: 6816b440
// Size: 94 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSetPreference(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint local_8;
  
  uVar1 = param_1;
  iVar2 = props_getTypedValue(param_1,1,4,&param_1);
  if (iVar2 != 0) {
    iVar2 = crt_setPlatformParam(uVar1,param_1);
    if (iVar2 != 0) {
      iVar2 = props_getTypedValue(uVar1,2,4,&local_8);
      if (iVar2 != 0) {
        crt_dispatchPlatformOp(uVar1,param_1,9);
        props_popArgs(uVar1,(undefined4 *)0x0);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_cmdDoPlatformOp (FUN_6816b4a0)
// Address: 6816b4a0
// Size: 94 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDoPlatformOp(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint local_8;
  
  uVar1 = param_1;
  iVar2 = props_getTypedValue(param_1,1,4,&param_1);
  if (iVar2 != 0) {
    iVar2 = crt_validateFrameIndex(uVar1,param_1);
    if (iVar2 != 0) {
      iVar2 = props_getTypedValue(uVar1,2,4,&local_8);
      if (iVar2 != 0) {
        crt_dispatchPlatformOp(uVar1,param_1,0x12);
        props_popArgs(uVar1,(undefined4 *)0x0);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_cmdCursor (FUN_6816b500)
// Address: 6816b500
// Size: 48 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdCursor(uint param_1)
{
  int local_18;
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  iVar2 = props_getTypedValue(param_1,1,4,&param_1);
  if (iVar2 != 0) {
    events_getMiawStageRect(uVar1,(short)param_1);
    props_popArgs(uVar1,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdPuppetTransition (FUN_6816b530)
// Address: 6816b530
// Size: 421 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdPuppetTransition(int param_1)
{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  short local_18 [2];
  uint local_14 [4];
  
  iVar1 = param_1;
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_1c = DAT_6819776c;
  local_20 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_1c = ((int *)(size_t)_DAT_68197764)[1];
    local_20 = *(int *)(size_t)_DAT_68197764;
  }
  if ((local_20 == 0x40) || (local_20 == 0x43)) {
    local_18[0] = 0;
    iVar2 = crt_executePlatformCmd(param_1,&local_20,sprites_findMemberByBitmap,local_18,0x5d);
    if (iVar2 != 0) {
      sprites_dispatchPropertyByName(iVar1,(undefined4 *)local_18);
    }
  }
  else {
    iVar2 = core_setFieldValue(param_1,&local_20,&param_1);
    if (iVar2 != 0) {
      iVar2 = crt_getPlatformValue(iVar1,(short *)&param_1);
      if (iVar2 == 0) {
        props_setError(iVar1,0x23);
        return 0;
      }
      iVar2 = sprites_lookupMemberCastData(iVar1,&param_1);
      if (iVar2 != 0) {
        sprites_dispatchPropertyByName(iVar1,&param_1);
        props_popArgs(iVar1,(undefined4 *)0x0);
        return 0;
      }
      props_setError(iVar1,0x5d);
      return 0;
    }
    iVar2 = props_getTypedValue(iVar1,1,4,local_14);
    if (iVar2 != 0) {
      if (local_14[0] == 0) {
        events_setMiawStageRect(iVar1,0,0,0,0);
        props_popArgs(iVar1,(undefined4 *)0x0);
        return 0;
      }
      local_14[1] = 1;
      iVar2 = props_getTypedProperty(iVar1,2,4,local_14 + 1);
      if (iVar2 != 0) {
        local_14[2] = 1;
        iVar2 = props_getTypedProperty(iVar1,3,4,local_14 + 2);
        if (iVar2 != 0) {
          local_14[3] = 1;
          iVar2 = props_getTypedProperty(iVar1,4,4,local_14 + 3);
          if (iVar2 != 0) {
            events_setMiawStageRect(iVar1,local_14[0],(char)local_14[1],(char)local_14[2],local_14[3]);
            props_popArgs(iVar1,(undefined4 *)0x0);
            return 0;
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_cmdPuppetPalette (FUN_6816b6e0)
// Address: 6816b6e0
// Size: 451 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdPuppetPalette(uint param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_41c;
  int local_418;
  uint local_414;
  uint local_410;
  short local_40c;
  short local_40a;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = crt_getMiawProperty(param_1,7);
  if (iVar1 != 0) {
    iVar1 = props_getInt(param_1);
    if (iVar1 < 1) {
      props_setError(param_1,0x15);
      return 0;
    }
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_418 = DAT_6819776c;
    local_41c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_418 = ((int *)(size_t)_DAT_68197764)[1];
      local_41c = *(int *)(size_t)_DAT_68197764;
    }
    if (local_41c == 4) {
      local_40c = (short)((uint)local_418 >> 0x10);
      if (local_40c == 0) {
        local_40c = 1;
      }
      local_40a = (short)local_418;
      if (local_40a != 0) goto LAB_6816b831;
      local_40c = 0;
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      if ((local_41c != 0x40) && (local_41c != 0x43)) {
        props_setError(param_1,0x13);
        return 0;
      }
      props_toPascalString(&local_41c,local_408);
      local_40c = 0;
      iVar1 = sprites_resolveMemberCast(param_1,(int)local_408,&local_40c);
      if (iVar1 == 0) {
        props_setError(param_1,0x2c);
        return 0;
      }
LAB_6816b831:
      local_414 = 1;
      local_410 = 0x1c;
      iVar1 = props_getTypedProperty(param_1,2,4,&local_410);
      if ((iVar1 == 0) ||
         (iVar1 = props_getTypedProperty(param_1,3,4,&local_414), uVar2 = local_410, uVar3 = local_414,
         iVar1 == 0)) goto LAB_6816b892;
    }
    sprites_setScorePropertyData(param_1,(undefined4 *)&local_40c,(char)uVar2,uVar3);
  }
  props_popArgs(param_1,(undefined4 *)0x0);
LAB_6816b892:
  return 0;
}



// ============================================================
// Function: strings_cmdPuppetSound (FUN_6816b8b0)
// Address: 6816b8b0
// Size: 588 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdPuppetSound(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined4 local_418;
  int local_414;
  undefined4 *local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = CONCAT22((*(unsigned short *)((char *)&local_40c + 2)),1);
  iVar2 = props_getInt(param_1);
  if (iVar2 < 1) {
    props_setError(param_1,0x15);
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x10);
  _DAT_68197764 = (int *)(*piVar1 + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  local_410 = DAT_6819776c;
  local_414 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = (undefined4 *)0x0;
    DAT_68197768 = 0;
    local_410 = (undefined4 *)((int *)(size_t)_DAT_68197764)[1];
    local_414 = *(int *)(size_t)_DAT_68197764;
  }
  uVar5 = CONCAT44(piVar1,local_410);
  if (*(int *)(param_1 + 0x7c) != 0) goto LAB_6816baea;
  if (local_414 == 4) {
LAB_6816ba22:
    iVar2 = (int)uVar5;
    if (iVar2 == 0) {
      local_40c = local_40c & 0xffff;
LAB_6816ba31:
      iVar2 = 0;
    }
    else {
      local_418 = 0;
      iVar3 = props_getInt(param_1);
      if (1 < iVar3) {
        _DAT_68197764 =
             (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                    *(int *)(param_1 + 0x18));
        local_410 = DAT_6819776c;
        local_414 = DAT_68197768;
        if (_DAT_68197764 != (int *)0x0) {
          DAT_6819776c = (undefined4 *)0x0;
          DAT_68197768 = 0;
          local_410 = (undefined4 *)((int *)(size_t)_DAT_68197764)[1];
          local_414 = *(int *)(size_t)_DAT_68197764;
        }
        if ((local_414 != 4) || (local_410 != (undefined4 *)0x0)) {
          local_40c = local_40c & 0xffff0000;
          iVar3 = crt_executePlatformSet(param_1,&local_414,sprites_resetMember,(short *)&local_40c,0x2d);
          if (iVar3 == 0) goto LAB_6816baea;
          goto LAB_6816badc;
        }
      }
      local_40c = 0;
    }
LAB_6816badc:
    stage_updateScoreProperty(param_1,iVar2,&local_40c);
  }
  else {
    if (local_414 == 0x20) {
      uVar4 = 0x20;
LAB_6816ba1d:
      uVar5 = strings_floatToUint64(uVar4,piVar1);
      goto LAB_6816ba22;
    }
    if (local_414 == 0x23) {
      uVar4 = *local_410;
      goto LAB_6816ba1d;
    }
    if (local_414 != 3) {
      if ((local_414 != 0x40) && (local_414 != 0x43)) goto LAB_6816b9bd;
      props_toPascalString(&local_414,local_408);
      local_40c = local_40c & 0xffff0000;
      sprites_findMemberByField(param_1,(int)local_408);
      if ((*(unsigned short *)((char *)&local_40c + 2)) < 1) goto LAB_6816b9a6;
      iVar2 = 0;
      goto LAB_6816badc;
    }
    iVar2 = (**(code **)(*(int *)*local_410 + 0x14))(param_1,local_410,&local_418);
    if (iVar2 != 0) {
      local_40c = sprites_dispatchProperty(param_1,local_418);
      if ((int)local_40c < 0) {
LAB_6816b9a6:
        props_setError(param_1,0x2d);
        goto LAB_6816bae2;
      }
      goto LAB_6816ba31;
    }
LAB_6816b9bd:
    props_setError(param_1,0x13);
  }
LAB_6816bae2:
  props_popArgs(param_1,(undefined4 *)0x0);
LAB_6816baea:
  return 0;
}



// ============================================================
// Function: strings_cmdShutdown (FUN_6816bb00)
// Address: 6816bb00
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdShutdown(int param_1)
{
  events_getMiawNetRef(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdOpenFile (FUN_6816bb20)
// Address: 6816bb20
// Size: 101 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdOpenFile(int param_1)
{
  int iVar1;
  uint local_410 [2];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = props_getValueDirect(param_1,1,1,local_410);
  if (iVar1 != 0) {
    props_toPascalString((int *)local_410,local_408);
    sprites_getPlatformInfo(param_1,(int)local_408);
    props_popArgs(param_1,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdIdle (FUN_6816bb90)
// Address: 6816bb90
// Size: 79 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdIdle(int param_1)
{
  int iVar1;
  short sVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  iVar1 = param_1;
  sVar2 = crt_resolveSpriteRange(param_1,&local_8,&param_1,1);
  if (sVar2 == 0) {
    local_10 = 4;
    events_getScorePropertyState();
    local_c = events_getMovieLoopMode(iVar1,local_8,param_1);
    props_popArgs(iVar1,&local_10);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdSound (FUN_6816bbe0)
// Address: 6816bbe0
// Size: 193 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdSound(uint param_1)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = param_1;
  piVar3 = (int *)0x0;
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    _DAT_68197764 =
         (int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    iVar2 = props_setRectField(uVar1,&local_14);
    if (iVar2 != 0) {
      (*(unsigned short *)((char *)&local_8 + 2)) = 0;
      param_1 = param_1 & 0xffff;
      piVar3 = local_10;
      goto LAB_6816bc67;
    }
  }
  iVar2 = strings_debugResolveRange(&local_8,(int *)&param_1);
  if (iVar2 != 0) {
    return 0;
  }
LAB_6816bc67:
  iVar2 = events_getScorePropertyState();
  sprites_dispatchBitmapMedia(uVar1,piVar3,&local_8,&param_1,&local_c,iVar2);
  local_10 = (int *)(int)(*(unsigned short *)((char *)&local_c + 2));
  local_14 = 4;
  props_popArgs(uVar1,&local_14);
  return 0;
}



// ============================================================
// Function: strings_cmdSoundHelper (FUN_6816bcb0)
// Address: 6816bcb0
// Size: 211 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSoundHelper(int param_1)
{
  int iVar1;
  int unaff_ESI;
  uint local_41c [2];
  undefined4 local_414;
  undefined4 local_410;
  uint local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 + -1 < 1) {
    props_setError(unaff_ESI,0x15);
    return 0;
  }
  if (iVar1 + -1 == 1) {
    local_40c = 1;
    iVar1 = 2;
  }
  else {
    iVar1 = props_getTypedValue(unaff_ESI,2,4,&local_40c);
    if (iVar1 == 0) goto LAB_6816bd73;
    iVar1 = 3;
  }
  iVar1 = props_getValueDirect(unaff_ESI,iVar1,1,local_41c);
  if (iVar1 != 0) {
    props_toPascalString((int *)local_41c,local_408);
    local_410 = 0;
    if (param_1 != 0) {
      local_410 = stage_loadScoreMember(unaff_ESI,local_40c);
    }
    local_414 = 4;
    props_popArgs(unaff_ESI,&local_414);
  }
LAB_6816bd73:
  return 0;
}



// ============================================================
// Function: strings_cmdSelectChannel (FUN_6816bd90)
// Address: 6816bd90
// Size: 79 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSelectChannel(int param_1)
{
  int iVar1;
  int unaff_ESI;
  uint local_8;
  
  iVar1 = props_getTypedValue(unaff_ESI,2,4,&local_8);
  if (iVar1 != 0) {
    if (param_1 == 0x176) {
      stage_selectScoreChannel(unaff_ESI,local_8);
      props_popArgs(unaff_ESI,(undefined4 *)0x0);
      return 0;
    }
    stage_getScoreSelection(unaff_ESI,local_8);
    props_popArgs(unaff_ESI,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdRepeatLoop (FUN_6816bde0)
// Address: 6816bde0
// Size: 316 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdRepeatLoop(uint param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_8;
  
  uVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if (iVar2 < 1) {
    props_setError(uVar1,0x2e);
    return 0;
  }
  if (-1 < *(int *)(uVar1 + 0x20)) {
    _DAT_68197764 =
         (int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18));
    iVar2 = DAT_68197768;
    iVar3 = DAT_6819776c;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      iVar2 = *(int *)(size_t)_DAT_68197764;
      iVar3 = ((int *)(size_t)_DAT_68197764)[1];
    }
    if (iVar2 == 8) {
      switch(iVar3) {
      case 0x14e:
      case 0x176:
        strings_cmdSelectChannel(iVar3);
        return 0;
      case 0x174:
      case 0x175:
        iVar2 = props_getTypedValue(uVar1,2,4,&local_8);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = props_getInt(uVar1);
        if (iVar2 < 3) {
          iVar2 = events_getTransitionRef(uVar1);
          param_1 = iVar2 * 0xf;
        }
        else {
          iVar2 = props_getTypedValue(uVar1,3,4,&param_1);
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((int)param_1 < 1) {
          param_1 = 1;
        }
        crt_setScoreChannelRate(uVar1,local_8,param_1,(uint)(iVar3 == 0x175));
        return 0;
      case 0x177:
        strings_cmdSoundHelper(1);
        return 0;
      }
    }
    props_setError(uVar1,0x2e);
    return 0;
  }
  crt_resolveSoundArg(uVar1);
  return 0;
}



// ============================================================
// Function: strings_cmdPlay (FUN_6816bf60)
// Address: 6816bf60
// Size: 105 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdPlay(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_c [2];
  
  puVar1 = param_1;
  iVar2 = strings_debugGetArgValue(&param_1,0);
  puVar3 = param_1;
  if (0 < iVar2) {
    if (param_1 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)puVar1[0x33];
    }
    else {
      cast_freeHandle(puVar1[0x33]);
    }
    puVar1[0x33] = 0;
    puVar1[0x34] = 0xffffffff;
    props_popArgs((int)puVar1,(undefined4 *)0x0);
    crt_dispatchGoTo((int)puVar1,0,local_c,puVar3);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdGoFrame (FUN_6816bfd0)
// Address: 6816bfd0
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdGoFrame(int param_1)
{
  int iVar1;
  
  props_popArgs(param_1,(undefined4 *)0x0);
  iVar1 = events_navigateMovie(param_1,0);
  events_navigateToMovieFrame(param_1,1,0,iVar1);
  return 0;
}



// ============================================================
// Function: strings_cmdGoMovie (FUN_6816c000)
// Address: 6816c000
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdGoMovie(int param_1)
{
  int iVar1;
  
  props_popArgs(param_1,(undefined4 *)0x0);
  iVar1 = events_navigateMovie(param_1,1);
  events_navigateToMovieFrame(param_1,1,0,iVar1);
  return 0;
}



// ============================================================
// Function: strings_cmdGoUrl (FUN_6816c030)
// Address: 6816c030
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdGoUrl(int param_1)
{
  int iVar1;
  
  props_popArgs(param_1,(undefined4 *)0x0);
  iVar1 = events_navigateMovie(param_1,-1);
  events_navigateToMovieFrame(param_1,1,0,iVar1);
  return 0;
}



// ============================================================
// Function: strings_cmdPlayMovie (FUN_6816c060)
// Address: 6816c060
// Size: 159 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdPlayMovie(undefined4 *param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_c [2];
  
  puVar1 = param_1;
  iVar4 = strings_debugGetArgValue(&param_1,1);
  if (iVar4 < 1) {
    if (iVar4 == 0) {
      bVar3 = events_getMiawBgColor((int)puVar1);
      if (CONCAT31(extraout_var,bVar3) != 0) {
        crt_advanceUndo((uint)puVar1);
        return 0;
      }
    }
  }
  else {
    props_popArgs((int)puVar1,(undefined4 *)0x0);
    if (puVar1[0x22] == 0) {
      bVar3 = events_getMiawBgColor((int)puVar1);
      puVar2 = param_1;
      if (CONCAT31(extraout_var_00,bVar3) != 0) {
        crt_pushUndoEntry((uint)puVar1,(uint)(param_1 != (undefined4 *)0x0),1);
        crt_dispatchGoTo((int)puVar1,0,local_c,puVar2);
        return 0;
      }
    }
    crt_dispatchGoTo((int)puVar1,0,local_c,param_1);
    puVar1[0x1d] = 9;
    props_unwindStack((int)puVar1);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdDoMenu (FUN_6816c100)
// Address: 6816c100
// Size: 358 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDoMenu(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint local_810 [2];
  undefined1 local_808 [1024];
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  iVar1 = props_getInt(param_1);
  if (iVar1 < 1) {
    props_setError(param_1,0x19);
    return 0;
  }
  if (iVar1 == 1) {
    Ordinal_1233(local_408,"");
    iVar1 = props_getValueDirect(param_1,1,1,local_810);
    if (iVar1 == 0) goto LAB_6816c253;
    puVar2 = props_copyString((int *)local_810);
    puVar3 = (undefined4 *)events_resolveChannelPath(param_1,puVar2);
    props_freeStringCallback(local_810,puVar2);
  }
  else {
    iVar1 = props_getValueDirect(param_1,1,1,local_810);
    if (iVar1 == 0) goto LAB_6816c253;
    props_toPascalString((int *)local_810,local_408);
    iVar1 = props_getValueDirect(param_1,2,1,local_810);
    if (iVar1 == 0) goto LAB_6816c253;
    puVar2 = props_copyString((int *)local_810);
    puVar3 = (undefined4 *)events_resolveChannelPath(param_1,puVar2);
    props_freeStringCallback(local_810,puVar2);
  }
  props_cStringToPascal(puVar3,local_808);
  cast_freeHandle(puVar3);
  props_popArgs(param_1,(undefined4 *)0x0);
  sprites_resolveFilePath(param_1,(int)local_808,local_408);
LAB_6816c253:
  return 0;
}



// ============================================================
// Function: strings_cmdPreloadCast (FUN_6816c270)
// Address: 6816c270
// Size: 58 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdPreloadCast(int param_1)
{
  int iVar1;
  short sVar2;
  int local_8;
  
  iVar1 = param_1;
  sVar2 = crt_resolveSpriteRange(param_1,&local_8,&param_1,0);
  if (sVar2 == 0) {
    events_setMoviePauseState(iVar1,local_8,param_1);
    props_popArgs(iVar1,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdUpdateStage (FUN_6816c2b0)
// Address: 6816c2b0
// Size: 166 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdUpdateStage(uint param_1)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int local_10;
  int *local_c;
  undefined4 local_8;
  
  uVar1 = param_1;
  piVar3 = (int *)0x0;
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    _DAT_68197764 =
         (int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_c = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    iVar2 = props_setRectField(uVar1,&local_10);
    if (iVar2 != 0) {
      (*(unsigned short *)((char *)&local_8 + 2)) = 0;
      param_1 = param_1 & 0xffff;
      piVar3 = local_c;
      goto LAB_6816c337;
    }
  }
  iVar2 = strings_debugResolveRange(&local_8,(int *)&param_1);
  if (iVar2 != 0) {
    return 0;
  }
LAB_6816c337:
  sprites_dispatchBitmapRect(uVar1,piVar3,&local_8,&param_1);
  props_popArgs(uVar1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdPutValue (FUN_6816c360)
// Address: 6816c360
// Size: 184 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdPutValue(int param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 local_418 [2];
  uint local_410 [2];
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  iVar1 = props_getValueDirect(param_1,1,1,local_410);
  if (iVar1 != 0) {
    local_408[0] = 0;
    local_408[1] = 0;
    piVar2 = props_getStringData((int *)local_410,(int *)0x0);
    globals_sendMciCommand(param_1,(char *)piVar2,local_408);
    props_unlockString((int *)local_410);
    props_readPascalString(param_1,local_408,local_418);
    props_popArgs(param_1,local_418);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdDebugPrint (FUN_6816c420)
// Address: 6816c420
// Size: 175 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDebugPrint(int param_1)
{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  uint local_410 [2];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar3 = 0;
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 != 0) {
    props_reportError(param_1,0x66);
    return 0;
  }
  iVar1 = props_getOptionalValue(param_1,1,1,local_410);
  if (iVar1 != 0) {
    if ((local_410[0] == 0x40) || (local_410[0] == 0x43)) {
      props_toPascalString((int *)local_410,local_408);
      puVar2 = local_408;
    }
    else {
      puVar2 = (undefined1 *)0x0;
    }
    iVar3 = events_getChannelDataRef(param_1,(int)puVar2);
  }
  props_normalizeType(param_1,4,iVar3);
  return 0;
}



// ============================================================
// Function: strings_executeLingo (FUN_6816c4d0)
// Address: 6816c4d0
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_executeLingo(int param_1)
{
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdInsertBefore (FUN_6816c4f0)
// Address: 6816c4f0
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdInsertBefore(int param_1)
{
  sprites_initSpriteOp(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdInsertAfter (FUN_6816c510)
// Address: 6816c510
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdInsertAfter(int param_1)
{
  sprites_executeSpriteOp(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdReplace (FUN_6816c530)
// Address: 6816c530
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdReplace(int param_1)
{
  sprites_suspendSpriteOp(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdDeleteItem (FUN_6816c550)
// Address: 6816c550
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDeleteItem(int param_1)
{
  sprites_pauseSpriteOp(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdDeleteLine (FUN_6816c570)
// Address: 6816c570
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDeleteLine(int param_1)
{
  sprites_resumeSpriteOp(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdDeleteChar (FUN_6816c590)
// Address: 6816c590
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDeleteChar(int param_1)
{
  sprites_cancelSpriteOp(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdHilite (FUN_6816c5b0)
// Address: 6816c5b0
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdHilite(int param_1)
{
  sprites_finalizeSpriteOps(param_1);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdSetProp (FUN_6816c5d0)
// Address: 6816c5d0
// Size: 74 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSetProp(int param_1)
{
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = 0;
  props_getTypedProperty(param_1,1,4,&local_8);
  if (*(int *)(param_1 + 0x7c) == 0) {
    local_10 = 4;
    local_c = events_setStageColorDepth(param_1,local_8);
    props_popArgs(param_1,&local_10);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdGetProp (FUN_6816c620)
// Address: 6816c620
// Size: 74 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdGetProp(int param_1)
{
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = 0;
  props_getTypedProperty(param_1,1,4,&local_8);
  if (*(int *)(param_1 + 0x7c) == 0) {
    local_10 = 4;
    local_c = events_setStageResolution(param_1,local_8);
    props_popArgs(param_1,&local_10);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdSetAt (FUN_6816c670)
// Address: 6816c670
// Size: 9 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdSetAt(int param_1,int param_2)
{
  events_setStageMonitorRef(param_1,param_2);
  return 0;
}



// ============================================================
// Function: strings_cmdAddAt (FUN_6816c680)
// Address: 6816c680
// Size: 242 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdAddAt(int param_1)
{
  int iVar1;
  uint local_420 [2];
  undefined4 local_418;
  undefined4 local_414;
  uint local_410;
  uint local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 < 1) {
    props_setError(param_1,0x15);
    return 0;
  }
  props_getValueDirect(param_1,1,1,local_420);
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_toPascalString((int *)local_420,local_408);
    local_40c = 1;
    iVar1 = props_getTypedProperty(param_1,2,4,&local_40c);
    if (iVar1 != 0) {
      local_410 = local_40c;
      iVar1 = props_getTypedProperty(param_1,3,4,&local_410);
      if (iVar1 != 0) {
        local_418 = 4;
        local_414 = events_openMovieFile(param_1,(int)local_408,local_40c,local_410);
        props_popArgs(param_1,&local_418);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_cmdDeleteAt (FUN_6816c780)
// Address: 6816c780
// Size: 160 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdDeleteAt(int param_1)
{
  int iVar1;
  uint local_418 [2];
  undefined4 local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 1) {
    props_setError(param_1,0x15);
    return 0;
  }
  props_getValueDirect(param_1,1,1,local_418);
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_toPascalString((int *)local_418,local_408);
    local_410 = 4;
    local_40c = events_compileMovieScript(param_1,(int)local_408);
    props_popArgs(param_1,&local_410);
  }
  return 0;
}



// ============================================================
// Function: strings_cmdSort (FUN_6816c820)
// Address: 6816c820
// Size: 759 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int strings_cmdSort(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint local_554 [2];
  uint local_54c [2];
  undefined4 local_544;
  undefined4 local_540;
  int local_53c;
  undefined4 *local_538;
  undefined4 *local_534;
  int local_530;
  int local_52c;
  int local_528;
  int local_524 [2];
  undefined1 local_51c [1044];
  undefined1 local_108 [256];
  uint local_8;
  
  local_524[1] = 0;
  memset(local_51c,0,0x414);
  local_524[0] = 0;
  local_528 = 0;
  local_544 = 0;
  local_540 = 0;
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    goto LAB_6816cae4;
  }
  iVar1 = props_getValueDirect(param_1,1,1,local_554);
  if ((iVar1 == 0) || (iVar1 = props_getValueDirect(param_1,2,1,local_54c), iVar1 == 0)) goto LAB_6816cae4;
  puVar2 = props_copyString((int *)local_554);
  local_534 = puVar2;
  puVar3 = props_copyString((int *)local_54c);
  local_538 = puVar3;
  if ((puVar2 == (undefined4 *)0x0) || (puVar3 == (undefined4 *)0x0)) {
    iVar1 = 10;
LAB_6816ca9e:
    props_setError(param_1,iVar1);
  }
  else {
    iVar1 = scoreEngine_resolveFilePath(param_1,(int)puVar2,local_524 + 1);
    if (iVar1 == 0) goto LAB_6816caa4;
    iVar1 = Ordinal_1114(puVar3);
    local_528 = iVar1;
    if (iVar1 == 0) {
      iVar1 = 2;
      goto LAB_6816ca9e;
    }
    local_530 = Ordinal_1201(iVar1);
    iVar5 = 0;
    local_53c = Ordinal_1351(local_524 + 1);
    if (local_53c != 0) {
      iVar5 = Ordinal_1402(local_524,local_524 + 1,3);
      if (iVar5 == 0) goto LAB_6816caa4;
      iVar5 = Ordinal_1435(local_524[0]);
      Ordinal_1407(local_524);
    }
    iVar4 = sprites_getStageRef(param_1);
    if (iVar4 != 0) {
      iVar1 = **(int **)(param_1 + 8);
      local_52c = *(int *)(iVar1 + 0x534);
      iVar1 = (*(int *)(iVar1 + 0x530) - iVar5) + local_530;
      if (iVar5 == 0) {
        local_52c = local_52c + 1;
      }
      else if (local_530 == 0) {
        local_52c = local_52c + -1;
      }
      if ((((0x10000 < iVar1) || (0x14 < local_52c)) && (iVar5 < local_530)) &&
         (*(int *)(**(int **)(param_1 + 8) + 0x538) == 0)) {
        Ordinal_1517(DAT_681956e0,0x1390,local_108,0x100);
        iVar5 = Ordinal_1780(local_108,"",2,2,4,1,0);
        if (iVar5 == 4) goto LAB_6816caa4;
        *(undefined4 *)(**(int **)(param_1 + 8) + 0x538) = 1;
      }
      *(int *)(**(int **)(param_1 + 8) + 0x530) = iVar1;
      *(int *)(**(int **)(param_1 + 8) + 0x534) = local_52c;
      iVar1 = local_528;
    }
    iVar5 = local_530;
    if (local_530 == 0) {
      if ((local_53c != 0) && (iVar1 = Ordinal_1352(local_524 + 1), iVar1 == 0)) {
        iVar1 = 0x67;
        goto LAB_6816ca9e;
      }
    }
    else {
      iVar4 = Ordinal_1401(local_524,local_524 + 1,7);
      if (iVar4 == 0) {
        iVar1 = 0x67;
        goto LAB_6816ca9e;
      }
      Ordinal_1420(local_524[0],iVar1,iVar5);
    }
  }
LAB_6816caa4:
  if (local_534 != (undefined4 *)0x0) {
    props_freeStringCallback(local_554,local_534);
  }
  puVar2 = local_538;
  if (local_538 != (undefined4 *)0x0) {
    if (local_528 != 0) {
      Ordinal_1115(local_538);
    }
    props_freeStringCallback(local_54c,puVar2);
  }
LAB_6816cae4:
  if (local_524[0] != 0) {
    Ordinal_1407(local_524);
  }
  props_popArgs(param_1,&local_544);
  return 0;
}



// ============================================================
// Function: strings_cmdCallHandler (FUN_6816cb20)
// Address: 6816cb20
// Size: 469 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdCallHandler(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint local_43c [2];
  undefined4 *local_434;
  undefined4 local_430;
  undefined4 local_42c;
  int local_428;
  int local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  puVar3 = (undefined4 *)0x0;
  local_424 = 0;
  iVar2 = 0;
  local_430 = 0;
  local_42c = 0;
  iVar1 = props_getInt(param_1);
  if (iVar1 != 1) {
    props_setError(param_1,0x16);
    goto LAB_6816ccc0;
  }
  iVar1 = props_getValueDirect(param_1,1,1,local_43c);
  if (iVar1 == 0) goto LAB_6816ccc0;
  local_434 = props_copyString((int *)local_43c);
  local_430 = 2;
  iVar1 = scoreEngine_resolveFilePath(param_1,(int)local_434,local_420);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1351(local_420);
    if (iVar1 == 0) {
      iVar1 = scoreEngine_syncPrefsData(0x1100000,local_420);
      if (iVar1 == 0) {
        iVar1 = scoreEngine_syncPrefsData(0x1000000,local_420);
        if (iVar1 == 0) goto LAB_6816cc9b;
      }
    }
    iVar1 = Ordinal_1402(&local_424,local_420,1);
    if (iVar1 == 0) {
      props_setError(param_1,0x67);
    }
    else {
      local_428 = Ordinal_1435(local_424);
      puVar3 = (undefined4 *)Ordinal_1111(local_428 + 1,0);
      if (puVar3 == (undefined4 *)0x0) {
        props_setError(param_1,3);
      }
      else {
        iVar2 = Ordinal_1114(puVar3);
        if (iVar2 == 0) {
          props_setError(param_1,2);
        }
        else {
          iVar1 = Ordinal_1409(local_424,iVar2,local_428);
          if (iVar1 == 0) {
            props_setError(param_1,2);
          }
          else {
            *(undefined1 *)(local_428 + iVar2) = 0;
            Ordinal_1115(puVar3);
            iVar2 = 0;
            props_getValuePair(param_1,puVar3,&local_430);
            puVar3 = (undefined4 *)0x0;
          }
        }
      }
    }
  }
LAB_6816cc9b:
  if (local_434 != (undefined4 *)0x0) {
    props_freeStringCallback(local_43c,local_434);
  }
  if ((puVar3 != (undefined4 *)0x0) && (iVar2 != 0)) {
    Ordinal_1115(puVar3);
  }
LAB_6816ccc0:
  if (local_424 != 0) {
    Ordinal_1407(&local_424);
  }
  props_popArgs(param_1,&local_430);
  return 0;
}



// ============================================================
// Function: strings_cmdCallMethod (FUN_6816cd00)
// Address: 6816cd00
// Size: 65 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cmdCallMethod(int param_1)
{
  int iVar1;
  uint local_8;
  
  local_8 = 1;
  iVar1 = props_getInt(param_1);
  if (0 < iVar1) {
    props_getTypedValue(param_1,1,4,&local_8);
  }
  sprites_getChannelRefById(param_1,local_8);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_cmdTell (FUN_6816cd50)
// Address: 6816cd50
// Size: 804 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdTell(void *param_1)
{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint local_470 [4];
  undefined4 local_460;
  undefined4 local_45c;
  int local_458;
  uint *local_454;
  uint local_450 [18];
  undefined1 local_408 [1024];
  uint local_8;
  
  bVar1 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    props_setError((int)param_1,0x70);
    return 0;
  }
  piVar2 = (int *)(**(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8 +
                  *(int *)((int)param_1 + 0x18));
  iVar3 = *piVar2;
  if ((iVar3 == 0x40) || (iVar3 == 0x43)) {
    props_toPascalString(piVar2,local_408);
    local_450[1] = sprites_processEvent((int)param_1,(int)local_408,1);
  }
  else {
    iVar3 = props_getTypedValue((int)param_1,1,4,local_450 + 1);
    if (iVar3 == 0) goto LAB_6816d063;
  }
  if (((int)local_450[1] < 1) || (*(int *)((int)param_1 + 0xf4) < (int)local_450[1])) {
    local_450[1] = 0;
  }
  iVar3 = props_getTypedValue((int)param_1,2,8,local_470);
  if (iVar3 == 0) goto LAB_6816d063;
  iVar3 = **(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8;
  props_releaseValue(param_1,(byte)*(undefined4 *)(iVar3 + *(int *)((int)param_1 + 0x18)),
               *(int **)(iVar3 + 4 + *(int *)((int)param_1 + 0x18)));
  iVar7 = **(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8 +
          *(int *)((int)param_1 + 0x18);
  iVar3 = props_getInt((int)param_1);
  uVar4 = *(uint *)((int)param_1 + 0x20);
  *(int *)((int)param_1 + 0x18) = *(int *)((int)param_1 + 0x18) + -8;
  local_450[0] = iVar3 - 1;
  Ordinal_1129(iVar7,iVar7 + 8,local_450[0] * 8);
  *(uint *)((int)param_1 + 0x20) = uVar4 & 0x80000000 | local_450[0];
  local_458 = props_getInt((int)param_1);
  if (local_458 < 9) {
    iVar3 = 1;
    local_454 = local_450 + 2;
    local_450[0] = 0;
    if (0 < local_458) {
      do {
        _DAT_68197764 =
             (uint *)(**(int **)((int)param_1 + 0x10) + -8 +
                      (iVar3 - *(int *)((int)param_1 + 0x20)) * 8 + *(int *)((int)param_1 + 0x18));
        uVar4 = DAT_6819776c;
        uVar6 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          uVar4 = ((int *)(size_t)_DAT_68197764)[1];
          uVar6 = *(int *)(size_t)_DAT_68197764;
        }
        local_450[iVar3 * 2] = uVar6;
        local_450[iVar3 * 2 + 1] = uVar4;
        iVar3 = iVar3 + 1;
      } while (iVar3 <= local_458);
      goto LAB_6816cfad;
    }
  }
  else {
    local_450[0] = cast_allocHandle(local_458 * 8,0);
    if (local_450[0] == 0) goto LAB_6816d063;
    local_454 = (uint *)Ordinal_1114(local_450[0]);
    iVar3 = 1;
    if (0 < local_458) {
      do {
        _DAT_68197764 =
             (uint *)(**(int **)((int)param_1 + 0x10) + -8 +
                      (iVar3 - *(int *)((int)param_1 + 0x20)) * 8 + *(int *)((int)param_1 + 0x18));
        uVar4 = DAT_6819776c;
        uVar6 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          uVar4 = ((int *)(size_t)_DAT_68197764)[1];
          uVar6 = *(int *)(size_t)_DAT_68197764;
        }
        local_454[iVar3 * 2 + -2] = uVar6;
        local_454[iVar3 * 2 + -1] = uVar4;
        iVar3 = iVar3 + 1;
      } while (iVar3 <= local_458);
    }
LAB_6816cfad:
    if (local_454 == (uint *)0x0) goto LAB_6816d063;
  }
  iVar3 = *(int *)((int)param_1 + 0x18);
  local_470[1] = 0;
  local_470[2] = 0;
  local_470[3] = local_470[0];
  local_460 = 2;
  local_45c = 0;
  iVar7 = sprites_dispatchChannelEvent(param_1,local_450[1],local_470 + 1,0);
  if (local_450[0] != 0) {
    cast_freeHandle(local_450[0]);
  }
  if (iVar3 != *(int *)((int)param_1 + 0x18)) {
    *(undefined4 *)((int)param_1 + 0x74) = 9;
    return 0;
  }
  if (iVar7 == 0) {
    props_popArgs((int)param_1,&local_460);
    return 0;
  }
  uVar5 = props_translateError(iVar7);
  props_reportError((int)param_1,(int)(short)uVar5);
LAB_6816d063:
  return 0;
}



// ============================================================
// Function: strings_cmdCase (FUN_6816d080)
// Address: 6816d080
// Size: 479 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_cmdCase(void *param_1)
{
  int local_14;
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int **ppiVar6;
  uint local_6c [4];
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int **local_50;
  int local_4c;
  int *local_48;
  int local_44 [15];
  uint local_8;
  
  bVar1 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    props_setError((int)param_1,0x70);
    return 0;
  }
  iVar2 = props_getTypedValue((int)param_1,1,8,local_6c);
  if (iVar2 == 0) goto LAB_6816d24e;
  local_54 = props_getInt((int)param_1);
  if (local_54 < 9) {
    local_50 = &local_48;
    iVar2 = 1;
    local_4c = 0;
    if (0 < local_54) {
      do {
        _DAT_68197764 =
             (undefined4 *)
             (**(int **)((int)param_1 + 0x10) + -8 + (iVar2 - *(int *)((int)param_1 + 0x20)) * 8 +
             *(int *)((int)param_1 + 0x18));
        piVar3 = DAT_6819776c;
        ppiVar6 = DAT_68197768;
        if (_DAT_68197764 != (undefined4 *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = (int **)0x0;
          piVar3 = (int *)((int *)(size_t)_DAT_68197764)[1];
          ppiVar6 = (int **)*(int *)(size_t)_DAT_68197764 /* FIXUP(C2100): cast for dereference */;
        }
        (&local_50)[iVar2 * 2] = ppiVar6;
        (&local_4c)[iVar2 * 2] = (int)piVar3;
        iVar2 = iVar2 + 1;
      } while (iVar2 <= local_54);
      goto LAB_6816d1c0;
    }
  }
  else {
    local_4c = cast_allocHandle(local_54 * 8,0);
    if (local_4c == 0) goto LAB_6816d24e;
    local_50 = (int **)Ordinal_1114(local_4c);
    iVar2 = 1;
    if (0 < local_54) {
      do {
        _DAT_68197764 =
             (undefined4 *)
             (**(int **)((int)param_1 + 0x10) + -8 + (iVar2 - *(int *)((int)param_1 + 0x20)) * 8 +
             *(int *)((int)param_1 + 0x18));
        piVar3 = DAT_6819776c;
        ppiVar6 = DAT_68197768;
        if (_DAT_68197764 != (undefined4 *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = (int **)0x0;
          piVar3 = (int *)((int *)(size_t)_DAT_68197764)[1];
          ppiVar6 = (int **)*(int *)(size_t)_DAT_68197764 /* FIXUP(C2100): cast for dereference */;
        }
        local_50[iVar2 * 2 + -2] = (int *)ppiVar6;
        local_50[iVar2 * 2 + -1] = piVar3;
        iVar2 = iVar2 + 1;
      } while (iVar2 <= local_54);
    }
LAB_6816d1c0:
    if (local_50 == (int **)0x0) goto LAB_6816d24e;
  }
  iVar2 = *(int *)((int)param_1 + 0x18);
  local_6c[1] = 0;
  local_6c[2] = 0;
  local_6c[3] = local_6c[0];
  local_5c = 2;
  local_58 = 0;
  iVar4 = sprites_broadcastEvent(param_1,local_6c + 1);
  if (local_4c != 0) {
    cast_freeHandle(local_4c);
  }
  if (iVar2 != *(int *)((int)param_1 + 0x18)) {
    *(undefined4 *)((int)param_1 + 0x74) = 9;
    return 0;
  }
  if (iVar4 == 0) {
    props_popArgs((int)param_1,&local_5c);
    return 0;
  }
  uVar5 = props_translateError(iVar4);
  props_reportError((int)param_1,(int)(short)uVar5);
LAB_6816d24e:
  return 0;
}



// ============================================================
// Function: strings_registerCommands (FUN_6816d260)
// Address: 6816d260
// Size: 1432 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_registerCommands(int param_1)
{
  score_registerHandler(param_1,0x1c7,strings_debugDispatchCommand,0,"-0");
  score_registerHandler(param_1,0x166,strings_debugSetColor,0,"-");
  score_registerHandler(param_1,0x1c8,strings_cmdGetChannel,0,"-");
  score_registerHandler(param_1,0x1c9,strings_cmdSetChannel,0,"-");
  score_registerHandler(param_1,0x55,strings_cmdAlert,0,"-");
  score_registerHandler(param_1,0x1cb,strings_cmdSetSprite,0,"-");
  score_registerHandler(param_1,0x1cc,strings_cmdPlayDone,0,"-");
  score_registerHandler(param_1,0x22c,strings_cmdUnloadCast,0,"-");
  score_registerHandler(param_1,0x1cd,strings_cmdSetStageParam,0,"-");
  score_registerHandler(param_1,0x1ce,strings_cmdOpenWindow,0,"-");
  score_registerHandler(param_1,0x1cf,strings_cmdMoveWindow,0,"-");
  score_registerHandler(param_1,0x1d0,strings_cmdResizeWindow,0,"-");
  score_registerHandler(param_1,0x1d1,strings_cmdSetWindowParam,0,"-");
  score_registerHandler(param_1,0x1d2,strings_cmdHalt,0,"-");
  score_registerHandler(param_1,0x1d3,rendering_updateDisplay,0,"-");
  score_registerHandler(param_1,0x1d4,rendering_updateDisplay,0,"-");
  score_registerHandler(param_1,0x1d5,strings_cmdBeep,0,"-");
  score_registerHandler(param_1,0x1d6,strings_cmdSetPreference,0,"-");
  score_registerHandler(param_1,0x1d7,strings_cmdDoPlatformOp,0,"-");
  score_registerHandler(param_1,0x1d8,strings_cmdCursor,0,"-");
  score_registerHandler(param_1,0x1d9,strings_cmdPuppetTransition,0,"-");
  score_registerHandler(param_1,0x1da,strings_cmdPuppetPalette,0,"-");
  score_registerHandler(param_1,0x1a2,strings_cmdPuppetSound,0,"-");
  score_registerHandler(param_1,0x16f,strings_cmdShutdown,0,"-");
  score_registerHandler(param_1,0x1db,strings_cmdOpenFile,0,"-");
  score_registerHandler(param_1,0x16e,strings_executeLingo,0,"-");
  score_registerHandler(param_1,0x1dc,strings_cmdIdle,0,"-");
  score_registerHandler(param_1,0x1dd,strings_cmdSound,0,"-");
  score_registerHandler(param_1,0x2f4,strings_cmdSound,0,"-");
  score_registerHandler(param_1,0x54,strings_cmdRepeatLoop,0,"*");
  score_registerHandler(param_1,0x161,strings_cmdPlay,0,"-");
  score_registerHandler(param_1,0x60f,strings_cmdGoFrame,0,"-");
  score_registerHandler(param_1,0x610,strings_cmdGoMovie,0,"-");
  score_registerHandler(param_1,0x611,strings_cmdGoUrl,0,"-");
  score_registerHandler(param_1,0x162,strings_cmdPlayMovie,0,"-");
  score_registerHandler(param_1,0x14b,strings_cmdDoMenu,0,"-");
  score_registerHandler(param_1,0x1e0,strings_cmdPreloadCast,0,"-");
  score_registerHandler(param_1,0x1e1,strings_cmdUpdateStage,0,"-");
  score_registerHandler(param_1,0x2f3,strings_cmdUpdateStage,0,"-");
  score_registerHandler(param_1,0x1de,strings_cmdPutValue,0,"-");
  score_registerHandler(param_1,0x20a,score_traceArgs,0,"-");
  score_registerHandler(param_1,0x20b,strings_cmdDebugPrint,0,"-");
  score_registerHandler(param_1,0x246,strings_executeLingo,0,"-");
  score_registerHandler(param_1,0x24c,strings_cmdInsertBefore,0,"-");
  score_registerHandler(param_1,0x24d,strings_cmdHilite,0,"-");
  score_registerHandler(param_1,0x24f,strings_cmdInsertAfter,0,"-");
  score_registerHandler(param_1,0x250,strings_cmdReplace,0,"-");
  score_registerHandler(param_1,0x252,strings_cmdDeleteItem,0,"-");
  score_registerHandler(param_1,0x251,strings_cmdDeleteLine,0,"-");
  score_registerHandler(param_1,0x24e,strings_cmdDeleteChar,0,"-");
  score_registerHandler(param_1,0x25f,strings_cmdSetProp,0,"-");
  score_registerHandler(param_1,0x260,strings_cmdGetProp,0,"-");
  score_registerHandler(param_1,0x261,strings_cmdSetAt,0,"d1d");
  score_registerHandler(param_1,0x2de,strings_cmdAddAt,0,"-");
  score_registerHandler(param_1,0x2df,strings_cmdDeleteAt,0,"-");
  score_registerHandler(param_1,0x313,strings_cmdHalt,0,"-");
  score_registerHandler(param_1,0x331,strings_cmdTell,0,"*");
  score_registerHandler(param_1,0x332,strings_cmdCase,0,"*");
  score_registerHandler(param_1,0x2f7,strings_cmdSort,0,"-2");
  score_registerHandler(param_1,0x312,strings_cmdCallHandler,0,"x1");
  score_registerHandler(param_1,0x382,strings_cmdCallMethod,0,"-");
  score_registerHandler(param_1,0x225,core_invokeHandlers,0,"-");
  return 0;
}



// ============================================================
// Function: strings_compileIf (FUN_6816d800)
// Address: 6816d800
// Size: 373 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_compileIf(void *param_1)
{
  bool bVar1;
  undefined3 extraout_var;
  int local_c;
  uint local_8;
  
  stage_pushCurrentScope((int)param_1);
  if ((local_c == 8) && ((local_8 != 0x30 || (stage_pushCurrentScope((int)param_1), local_c == 8)))) {
    if (local_8 == 0x3c) goto LAB_6816d8b2;
    if (local_8 == 0x15f) {
      stage_emitBranch((int)param_1,1);
      stage_compileHandler(param_1,lingo_noop);
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
        return 0;
      }
      stage_emitReturn();
      return 0;
    }
    if (((local_8 == 0x207) || (local_8 == 0x60)) || (local_8 == 0x160)) {
      stage_emitBranchCond((int)param_1,local_8);
      stage_emitReturn();
      return 0;
    }
  }
  stage_resolveSymbol((int)param_1,&local_c);
LAB_6816d8b2:
  stage_compileHandler(param_1,stage_checkIsEndToken);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_pushCurrentScope((int)param_1);
    if ((local_c != 8) || (local_8 != 0x3e)) {
      stage_resolveSymbol((int)param_1,&local_c);
      stage_emitReturn();
      return 0;
    }
    bVar1 = stage_parseAssignment((int)param_1,&local_c,(int *)0x15f);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      stage_emitPushLiteral((int)param_1,0x20);
    }
    stage_compileHandler(param_1,lingo_noop);
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
      stage_emitReturn();
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: strings_compileRepeat (FUN_6816d980)
// Address: 6816d980
// Size: 312 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_compileRepeat(void *param_1)
{
  bool bVar1;
  undefined3 extraout_var;
  int local_c;
  int local_8;
  
  stage_pushCurrentScope((int)param_1);
  if (local_c == 8) {
    if (local_8 == 0x3b) {
      stage_emitReturn();
      return 0;
    }
    if (local_8 == 0x3c) goto LAB_6816da0d;
    if (local_8 == 0x15f) {
      stage_emitBranch((int)param_1,1);
      stage_compileHandler(param_1,lingo_noop);
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
        return 0;
      }
      stage_emitReturn();
      return 0;
    }
  }
  stage_resolveSymbol((int)param_1,&local_c);
LAB_6816da0d:
  stage_compileHandler(param_1,stage_checkIsEndToken);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_pushCurrentScope((int)param_1);
    if ((local_c == 8) && (local_8 == 0x3e)) {
      bVar1 = stage_parseAssignment((int)param_1,&local_c,(int *)0x15f);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        stage_emitPushLiteral((int)param_1,0x20);
        return 0;
      }
      stage_compileHandler(param_1,lingo_noop);
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
        stage_emitReturn();
        return 0;
      }
    }
    else {
      stage_resolveSymbol((int)param_1,&local_c);
      stage_emitReturn();
    }
  }
  return 0;
}



// ============================================================
// Function: strings_compileRepeatWith (FUN_6816dac0)
// Address: 6816dac0
// Size: 446 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_compileRepeatWith(void *param_1)
{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int local_14 [2];
  int local_c;
  int local_8;
  
  pvVar1 = param_1;
  bVar2 = stage_parseCondition((int)param_1,local_14,(int *)&param_1);
  if (CONCAT31(extraout_var,bVar2) == 0) goto switchD_6816daee_caseD_24;
  switch ((int)(size_t)param_1) { /* FIXUP(C2050): cast non-integral switch to int */
  case (void *)0x1f:
    iVar4 = stage_compileRepeatHeader((int)pvVar1);
    if (iVar4 != 0) goto LAB_6816dc13;
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
      return 0;
    }
  default:
switchD_6816daee_caseD_24:
    stage_resolveSymbol((int)pvVar1,local_14);
    stage_emitReturn();
    break;
  case (void *)0x20:
  case (void *)0x21:
  case (void *)0x22:
  case (void *)0x23:
    stage_compileBinaryExpr(pvVar1,(int)param_1);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
      return 0;
    }
LAB_6816dc13:
    stage_parseCondition((int)pvVar1,local_14,(int *)&param_1);
    goto LAB_6816dc19;
  case (void *)0x58:
    stage_pushCurrentScope((int)pvVar1);
    if ((local_c == 8) && (local_8 == 4)) {
      stage_resolveSymbol((int)pvVar1,&local_c);
      stage_resolveSymbol((int)pvVar1,local_14);
      stage_compileExpression(pvVar1,lingo_noop,1);
      if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
        return 0;
      }
      stage_emitInstruction((int)pvVar1,0x43,1,1);
      iVar4 = -2;
      uVar3 = props_resolveSymbol((int)pvVar1,0x118);
      stage_emitInstruction((int)pvVar1,0x67,uVar3,iVar4);
      return 0;
    }
    stage_resolveSymbol((int)pvVar1,&local_c);
  case (void *)0x2d:
  case (void *)0x59:
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
    stage_emitBranch((int)pvVar1,0);
LAB_6816dc19:
    if ((param_1 != (void *)0x2d) && (((int)param_1 < 0x58 || (0x59 < (int)param_1)))) {
      stage_emitPushLiteral((int)pvVar1,0x1b);
      return 0;
    }
    stage_compileHandler(pvVar1,lingo_noop);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
      iVar4 = stage_compileUnaryExpr((int)pvVar1,lingo_noop);
      if (iVar4 == 0) {
        stage_emitBranch((int)pvVar1,0);
      }
      stage_emitOpcode((int)pvVar1,0x18,-10);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: strings_compileReturn (FUN_6816dcd0)
// Address: 6816dcd0
// Size: 23 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_compileReturn(void)
{
  stage_emitReturn();
  return 0;
}



// ============================================================
// Function: strings_compileTell (FUN_6816dcf0)
// Address: 6816dcf0
// Size: 78 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_compileTell(void)

{
  int unaff_ESI;
  int local_c;
  uint local_8;
  
  stage_pushCurrentScope(unaff_ESI);
  if ((local_c == 8) && ((local_8 == 0x14e || ((0x173 < (int)local_8 && ((int)local_8 < 0x178))))))
  {
    stage_emitBranchCond(unaff_ESI,local_8);
    return 1;
  }
  stage_resolveSymbol(unaff_ESI,&local_c);
  return 0;
}



// ============================================================
// Function: strings_compileExit (FUN_6816dd40)
// Address: 6816dd40
// Size: 26 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_compileExit(void)
{
  strings_compileTell();
  stage_emitReturn();
  return 0;
}



// ============================================================
// Function: strings_compileHandlerArgs (FUN_6816dd60)
// Address: 6816dd60
// Size: 32 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_compileHandlerArgs(int *param_1)

{
  if ((*param_1 == 8) && (param_1[1] == 0x45)) {
    return 1;
  }
  return 0;
}



