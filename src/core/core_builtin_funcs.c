// Module: core
// Topic: Built-in functions - number conversion, cast member lookup, printing
// Address range: 0x68019020 - 0x68019800
// Functions (18):
//   core_invokeBuiltin (0x68019020)
//   core_getMemberNum (0x680190F0)
//   core_getFieldRef (0x68019120)
//   core_getBuiltinFunc (0x68019170)
//   core_resolveCastMember (0x68019190)
//   core_resolveMemberRef (0x68019270)
//   core_lookupCastMember (0x68019300)
//   core_getChannelCount (0x68019350)
//   core_validateChannelHigh (0x68019360)
//   core_validateChannelLow (0x680193D0)
//   core_formatTimeString (0x68019440)
//   core_parseTimeString (0x68019510)
//   core_intersectCastRefs (0x680195F0)
//   core_openScriptWindow (0x680196D0)
//   core_closeScriptWindow (0x680196E0)
//   core_convertScriptText (0x680196F0)
//   core_getStageRect (0x680197C0)
//   core_getEventMask (0x68019800)

// ============================================================
// Function: core_invokeBuiltin (FUN_68019020)
// Address: 68019020
// Size: 208 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_invokeBuiltin(int param_1)
{
  int iVar1;
  int local_2c [3];
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14 [4];
  
  sprites_findMemberInCastLib(param_1,&local_18,&local_1c,local_2c + 2);
  if (local_1c < 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0xb4) == 0) {
    return 0;
  }
  iVar1 = Ordinal_1114(local_18);
  local_20 = local_1c;
  local_2c[1] = 0;
  local_14[0] = 0x7fff;
  local_14[1] = 0;
  local_14[2] = 0;
  props_splitString(param_1,*(int *)(param_1 + 0xb4),local_14,local_2c + 1,&local_20,iVar1,local_2c);
  Ordinal_1115(local_18);
  return 0;
}



// ============================================================
// Function: core_getMemberNum (FUN_680190f0)
// Address: 680190f0
// Size: 41 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint core_getMemberNum(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1;
  sprites_findMemberByName(param_1,&param_1,(int *)0x0);
  uVar2 = sprites_getPropertyId(iVar1,param_1);
  if (uVar2 == 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// ============================================================
// Function: core_getFieldRef (FUN_68019120)
// Address: 68019120
// Size: 67 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getFieldRef(int param_1)
{
  int iVar1;
  undefined4 local_c [2];
  
  iVar1 = param_1;
  sprites_findMemberByName(param_1,&param_1,(int *)0x0);
  local_c[0] = 2;
  if ((*(unsigned short *)((char *)&param_1 + 2)) != 0) {
    core_getFieldValue(iVar1,&param_1,local_c);
  }
  props_popArgs(iVar1,local_c);
  return 0;
}



// ============================================================
// Function: core_getBuiltinFunc (FUN_68019170)
// Address: 68019170
// Size: 23 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getBuiltinFunc(uint param_1)
{
  crt_getMiawProperty(param_1,*(int *)(param_1 + 0xb4));
  return 0;
}



// ============================================================
// Function: core_resolveCastMember (FUN_68019190)
// Address: 68019190
// Size: 136 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveCastMember(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  switch(*piVar1) {
  case 1:
  case 0x40:
  case 0x43:
    local_c = *piVar1;
    local_8 = piVar1[1];
    iVar2 = crt_getPlatformRef(param_1,&local_c);
    if (*(int *)(param_1 + 0x7c) == 0) {
      props_normalizeType(param_1,4,iVar2);
      return 0;
    }
    break;
  default:
    props_setError(param_1,0x13);
    break;
  case 4:
    iVar2 = events_navigateMovie(param_1,piVar1[1]);
    props_normalizeType(param_1,4,iVar2);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: core_resolveMemberRef (FUN_68019270)
// Address: 68019270
// Size: 129 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveMemberRef(int param_1)
{
  int iVar1;
  int iVar2;
  uint local_8;
  
  iVar1 = param_1;
  local_8 = 0;
  iVar2 = props_getTypedProperty(param_1,1,4,&local_8);
  if (iVar2 != 0) {
    if (local_8 == 0) {
      sprites_findMemberByName(iVar1,&param_1,(int *)&local_8);
      props_normalizeType(iVar1,4,local_8);
      return 0;
    }
    iVar2 = crt_setPlatformParam(iVar1,local_8);
    if (iVar2 != 0) {
      iVar2 = sprites_navigateToMember(iVar1,local_8);
      props_normalizeType(iVar1,4,iVar2);
      return 0;
    }
    props_normalizeType(iVar1,4,param_1);
  }
  return 0;
}



// ============================================================
// Function: core_lookupCastMember (FUN_68019300)
// Address: 68019300
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_lookupCastMember(int param_1)
{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  iVar1 = param_1;
  sVar2 = crt_resolveSpriteRange(param_1,&local_c,&local_8,0);
  iVar4 = 0;
  if ((sVar2 == 0) &&
     (iVar3 = sprites_mutateScoreData(iVar1,local_c,local_8,&param_1), iVar4 = param_1, iVar3 != 0)) {
    param_1 = 0;
    iVar4 = param_1;
  }
  props_normalizeType(iVar1,4,iVar4);
  return 0;
}



// ============================================================
// Function: core_getChannelCount (FUN_68019350)
// Address: 68019350
// Size: 9 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getChannelCount(int param_1,int param_2)
{
  stage_getScoreChannelCount(param_1,param_2);
  return 0;
}



// ============================================================
// Function: core_validateChannelHigh (FUN_68019360)
// Address: 68019360
// Size: 103 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_validateChannelHigh(int param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 local_18;
  int local_14;
  int local_c;
  uint local_8;

  iVar1 = crt_setPlatformParam(param_1,param_2);
  if (((iVar1 != 0) && (events_getWindowData(param_1,param_2,&local_18), local_14 <= param_3)) &&
     (param_3 <= local_c)) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: core_validateChannelLow (FUN_680193d0)
// Address: 680193d0
// Size: 103 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_validateChannelLow(int param_1,int param_2,int param_3)
{
  int iVar1;
  int local_18 [2];
  int local_10;
  uint local_8;

  iVar1 = crt_setPlatformParam(param_1,param_2);
  if (((iVar1 != 0) && (events_getWindowData(param_1,param_2,local_18), local_18[0] <= param_3)) &&
     (param_3 <= local_10)) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: core_formatTimeString (FUN_68019440)
// Address: 68019440
// Size: 201 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatTimeString(int param_1)
{
  int iVar1;
  undefined4 local_420 [2];
  uint local_418;
  uint local_414;
  uint local_410;
  uint local_40c;
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = props_getTypedValue(param_1,1,4,&local_410);
  if (iVar1 != 0) {
    iVar1 = props_getTypedValue(param_1,2,4,&local_40c);
    if (iVar1 != 0) {
      iVar1 = props_getTypedValue(param_1,3,4,&local_414);
      if (iVar1 != 0) {
        iVar1 = props_getTypedValue(param_1,4,4,&local_418);
        if (iVar1 != 0) {
          sprites_setTextSelection(local_410,local_40c,local_414,local_418,(char *)local_408);
          props_readPascalString(param_1,local_408,local_420);
          props_popArgs(param_1,local_420);
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_parseTimeString (FUN_68019510)
// Address: 68019510
// Size: 211 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_parseTimeString(int param_1)
{
  int iVar1;
  uint local_420 [2];
  uint local_418;
  uint local_414;
  uint local_410;
  uint local_40c;
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = props_getValueDirect(param_1,1,1,local_420);
  if (iVar1 != 0) {
    iVar1 = props_getTypedValue(param_1,2,4,&local_410);
    if (iVar1 != 0) {
      iVar1 = props_getTypedValue(param_1,3,4,&local_418);
      if (iVar1 != 0) {
        iVar1 = props_getTypedValue(param_1,4,4,&local_414);
        if (iVar1 != 0) {
          props_toPascalString((int *)local_420,local_408);
          local_40c = (uint)(local_418 != 0);
          iVar1 = sprites_processTextKey(local_408,local_410,(int *)&local_40c);
          props_normalizeType(param_1,4,iVar1);
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_intersectCastRefs (FUN_680195f0)
// Address: 680195f0
// Size: 211 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_intersectCastRefs(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (piVar1 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = piVar1[1];
    local_c = *piVar1;
  }
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
              *(int *)(param_1 + 0x18));
  local_10 = DAT_6819776c;
  local_14 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_10 = ((int *)(size_t)_DAT_68197764)[1];
    local_14 = *(int *)(size_t)_DAT_68197764;
  }
  iVar2 = crt_getPlatformRef(param_1,&local_c);
  if ((*(int *)(param_1 + 0x7c) == 0) &&
     (iVar3 = crt_getPlatformRef(param_1,&local_14), *(int *)(param_1 + 0x7c) == 0)) {
    iVar2 = events_getPlaybackState(param_1,iVar2,iVar3);
    props_normalizeType(param_1,4,iVar2);
  }
  return 0;
}



// ============================================================
// Function: core_openScriptWindow (FUN_680196d0)
// Address: 680196d0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_openScriptWindow(int param_1)
{
  events_getChannelBounds(param_1);
  return 0;
}



// ============================================================
// Function: core_closeScriptWindow (FUN_680196e0)
// Address: 680196e0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_closeScriptWindow(int param_1)
{
  events_setChannelBounds(param_1);
  return 0;
}



// ============================================================
// Function: core_convertScriptText (FUN_680196f0)
// Address: 680196f0
// Size: 199 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_convertScriptText(int param_1)
{
  int iVar1;
  uint local_81c [2];
  undefined4 local_814 [2];
  uint local_80c;
  undefined1 local_808 [1024];
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = props_getValueDirect(param_1,1,1,local_81c);
  if (iVar1 != 0) {
    iVar1 = props_getTypedValue(param_1,2,4,&local_80c);
    if (iVar1 != 0) {
      iVar1 = sprites_getStageRef(param_1);
      if (iVar1 == 0) {
        props_toPascalString((int *)local_81c,local_808);
        events_resetPlaybackTimers(param_1,(int)local_808,local_80c,local_408);
      }
      else {
        props_reportError(param_1,0x66);
        local_408[0] = 0;
      }
      props_readPascalString(param_1,local_408,local_814);
      props_popArgs(param_1,local_814);
    }
  }
  return 0;
}



// ============================================================
// Function: core_getStageRect (FUN_680197c0)
// Address: 680197c0
// Size: 57 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getStageRect(int param_1)
{
  undefined4 local_14 [2];
  undefined4 local_c [2];
  
  events_setMiawSoundRef(param_1,local_c);
  props_transformRect(param_1,local_c,local_14);
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_popArgs(param_1,local_14);
  }
  return 0;
}



// ============================================================
// Function: core_getEventMask (FUN_68019800)
// Address: 68019800
// Size: 43 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getEventMask(int param_1)
{
  undefined4 local_c;
  uint local_8;
  
  local_8 = sprites_collectStageEvents(param_1);
  local_c = 4;
  props_popArgs(param_1,&local_c);
  return 0;
}


