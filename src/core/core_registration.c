// Module: core
// Topic: Built-in function/handler registration and string query support
// Address range: 0x68019830 - 0x68019F60
// Functions (8):
//   core_countRegisteredEntries (0x68019830)
//   core_seekRegisteredEntry (0x680198A0)
//   core_getRegisteredKey (0x680199C0)
//   core_getRegisteredValue (0x68019A30)
//   core_resolveRegisteredHandler (0x68019AB0)
//   core_returnEmptyString (0x68019BB0)
//   core_checkIsAuthor (0x68019BE0)
//   core_registerAllHandlers (0x68019F60)

// ============================================================
// Function: core_countRegisteredEntries (FUN_68019830)
// Address: 68019830
// Size: 109 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_countRegisteredEntries(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_68196328 == (code *)0x0) {
    return 0;
  }
  uVar2 = events_getMoviePauseState(param_1);
  iVar3 = ((code *)(size_t)DAT_68196328)(uVar2);
  if (iVar3 == 0) {
    return 0;
  }
  pcVar4 = (char *)Ordinal_1114(iVar3);
  iVar7 = 0;
  cVar1 = *pcVar4;
  while (cVar1 != '\0') {
    iVar5 = Ordinal_1201(pcVar4);
    iVar6 = Ordinal_1201(pcVar4 + iVar5 + 1);
    pcVar4 = pcVar4 + iVar5 + 1 + iVar6 + 1;
    iVar7 = iVar7 + 1;
    cVar1 = *pcVar4;
  }
  Ordinal_1115(iVar3);
  return iVar7;
}



// ============================================================
// Function: core_seekRegisteredEntry (FUN_680198a0)
// Address: 680198a0
// Size: 276 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall core_seekRegisteredEntry(undefined4 param_1,int param_2)
{
  char cVar1;
  short sVar2;
  char *in_EAX;
  int *piVar3;
  char *pcVar4;
  int local_c;
  int local_8;
  
  _DAT_68197764 =
       (int *)(**(int **)(param_2 + 0x10) + *(int *)(param_2 + 0x20) * -8 + *(int *)(param_2 + 0x18)
              );
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  if (local_c == 4) {
    local_8 = local_8 + -1;
    if (0 < local_8) {
      while (*in_EAX != '\0') {
        do {
          cVar1 = *in_EAX;
          in_EAX = in_EAX + 1;
        } while (cVar1 != '\0');
        do {
          cVar1 = *in_EAX;
          in_EAX = in_EAX + 1;
        } while (cVar1 != '\0');
        local_8 = local_8 + -1;
        if (local_8 < 1) {
          return 0;
        }
      }
    }
  }
  else if ((local_c == 0x40) || (local_c == 0x43)) {
    piVar3 = props_getStringData(&local_c,(int *)0x0);
    cVar1 = *in_EAX;
    while ((cVar1 != '\0' && (sVar2 = Ordinal_1208(piVar3,in_EAX), sVar2 != 0))) {
      do {
        pcVar4 = in_EAX;
        in_EAX = pcVar4 + 1;
      } while (*pcVar4 != '\0');
      do {
        cVar1 = *in_EAX;
        in_EAX = in_EAX + 1;
      } while (cVar1 != '\0');
      cVar1 = pcVar4[(int)(in_EAX + (2 - (int)(pcVar4 + 2)))];
      in_EAX = pcVar4 + (int)(in_EAX + (2 - (int)(pcVar4 + 2)));
    }
    props_unlockString(&local_c);
  }
  return 0;
}



// ============================================================
// Function: core_getRegisteredKey (FUN_680199c0)
// Address: 680199c0
// Size: 106 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getRegisteredKey(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 extraout_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 2;
  local_8 = 0;
  if (DAT_68196328 != (code *)0x0) {
    uVar1 = events_getMoviePauseState(param_1);
    iVar2 = ((code *)(size_t)DAT_68196328)(uVar1);
    if (iVar2 != 0) {
      Ordinal_1114(iVar2);
      pcVar3 = (char *)core_seekRegisteredEntry(extraout_ECX,param_1);
      if (*pcVar3 != '\0') {
        props_loadCString(param_1,pcVar3,&local_c);
      }
      Ordinal_1115(iVar2);
    }
  }
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: core_getRegisteredValue (FUN_68019a30)
// Address: 68019a30
// Size: 120 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getRegisteredValue(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 2;
  local_8 = 0;
  if (DAT_68196328 != (code *)0x0) {
    uVar1 = events_getMoviePauseState(param_1);
    iVar2 = ((code *)(size_t)DAT_68196328)(uVar1);
    if (iVar2 != 0) {
      Ordinal_1114(iVar2);
      pcVar3 = (char *)core_seekRegisteredEntry(extraout_ECX,param_1);
      if (*pcVar3 != '\0') {
        iVar4 = Ordinal_1201(pcVar3);
        props_loadCString(param_1,pcVar3 + iVar4 + 1,&local_c);
      }
      Ordinal_1115(iVar2);
    }
  }
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: core_resolveRegisteredHandler (FUN_68019ab0)
// Address: 68019ab0
// Size: 252 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveRegisteredHandler(int param_1)
{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined4 local_410;
  undefined4 local_40c;
  byte local_408 [1024];
  uint local_8;
  
  iVar2 = props_getInt(param_1);
  if (iVar2 == 0) {
    sprites_getTextMemberRef(param_1,local_408);
    props_readPascalString(param_1,local_408,&local_410);
  }
  else {
    if (iVar2 != 1) {
      props_setError(param_1,0x19);
      return 0;
    }
    piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                    *(int *)(param_1 + 0x18));
    iVar2 = *piVar3;
    if (iVar2 == 4) {
      iVar2 = piVar3[1];
      local_410 = 4;
    }
    else {
      if ((iVar2 != 0x40) && (iVar2 != 0x43)) {
        props_setError(param_1,0x13);
        return 0;
      }
      props_toPascalString(piVar3,local_408);
      local_410 = 4;
      uVar1 = sprites_getColorDepth(param_1,(int)local_408);
      iVar2 = CONCAT31(extraout_var,uVar1);
    }
    local_40c = sprites_getTextSelectionRange(param_1,iVar2);
  }
  props_popArgs(param_1,&local_410);
  return 0;
}



// ============================================================
// Function: core_returnEmptyString (FUN_68019bb0)
// Address: 68019bb0
// Size: 42 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_returnEmptyString(int param_1)
{
  undefined4 local_c [2];
  
  props_loadCString(param_1,"",local_c);
  props_popArgs(param_1,local_c);
  return 0;
}



// ============================================================
// Function: core_checkIsAuthor (FUN_68019be0)
// Address: 68019be0
// Size: 95 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkIsAuthor(void)

{
  short sVar1;
  int *piVar2;
  uint unaff_EDI;
  bool bVar3;
  uint local_c [2];
  
  bVar3 = false;
  local_c[0] = 2;
  local_c[1] = 0;
  core_accessGlobalAll(unaff_EDI,0,0x2e9,local_c);
  piVar2 = props_getApiContext((int *)local_c);
  if (piVar2 != (int *)0x0) {
    sVar1 = Ordinal_1206(piVar2,"Author");
    bVar3 = sVar1 == 0;
  }
  props_getApiState((int *)local_c);
  props_clearValue(unaff_EDI,local_c);
  return bVar3;
}



// ============================================================
// Function: core_registerAllHandlers (FUN_68019f60)
// Address: 68019f60
// Size: 1885 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_registerAllHandlers(int param_1)
{
  score_registerHandler(param_1,0x1a3,core_checkRuntimeFlag1,0,"d0");
  score_registerHandler(param_1,0x1a4,core_checkRuntimeFlag2,0,"d0");
  score_registerHandler(param_1,0x1a5,&LAB_68018bb0,0,"d0");
  score_registerHandler(param_1,0x1a6,core_checkRuntimeFlag3,0,"d0");
  score_registerHandler(param_1,0x1a7,core_checkRuntimeFlag4,0,"d0");
  score_registerHandler(param_1,0x39,&LAB_68018bc0,0,"d0");
  score_registerHandler(param_1,0x3a,&LAB_68018bb0,0,"d0");
  score_registerHandler(param_1,0x1a8,core_getWindowCount,0,"d0");
  score_registerHandler(param_1,0x3c,core_getEventRef,0,"d0");
  score_registerHandler(param_1,0x1a9,core_getPlatformName,0,"x0");
  score_registerHandler(param_1,0x1aa,core_getEventInfoLeft,0,"d0");
  score_registerHandler(param_1,0x1ab,core_getEventInfoTop,0,"d0");
  score_registerHandler(param_1,0x1ac,core_getEventInfoRight,0,"d0");
  score_registerHandler(param_1,0x1ad,core_getEventInfoBottom,0,"d0");
  score_registerHandler(param_1,0x1ae,core_resetSprites,0,"d0");
  score_registerHandler(param_1,0x1af,core_getEventDataSecond,0,"d0");
  score_registerHandler(param_1,0x1b0,core_getEventDataFirst,0,"d0");
  score_registerHandler(param_1,0x1b1,core_getObjectName,0,"x0");
  score_registerHandler(param_1,0x15f,core_getMoviePathShort,0,"x0");
  score_registerHandler(param_1,0x1b2,core_getMoviePathLong,0,"x0");
  score_registerHandler(param_1,0x1b3,core_getObjectText,0,"x0");
  score_registerHandler(param_1,0x3c3,core_getObjectValue,0,"x0");
  score_registerHandler(param_1,0x1b4,core_getBuiltinFunc,0x15,"d0");
  score_registerHandler(param_1,0x1b5,core_invokeBuiltin,3,"d0");
  score_registerHandler(param_1,0x1b6,core_invokeBuiltin,2,"d0");
  score_registerHandler(param_1,0x1b7,core_invokeBuiltin,1,"d0");
  score_registerHandler(param_1,0x1b8,core_invokeBuiltin,0,"d0");
  score_registerHandler(param_1,0x1b9,core_getMemberNum,0,"d0");
  score_registerHandler(param_1,0x338,core_getFieldRef,0,"x0");
  score_registerHandler(param_1,0x1ba,core_getBuiltinFunc,7,"d0");
  score_registerHandler(param_1,0x1bb,core_getBuiltinFunc,0xc,"d0");
  score_registerHandler(param_1,0x1bc,core_getBuiltinFunc,0x10,"d0");
  score_registerHandler(param_1,0x1bd,core_getBuiltinFunc,0xe,"d0");
  score_registerHandler(param_1,0x1be,core_getBuiltinFunc,0x11,"d0");
  score_registerHandler(param_1,0x1bf,core_getBuiltinFunc,0x12,"d0");
  score_registerHandler(param_1,0x1c0,core_getBuiltinFunc,0xf,"d0");
  score_registerHandler(param_1,0x196,core_getBuiltinFunc,0x14,"d0");
  score_registerHandler(param_1,0x1ec,core_getBuiltinFunc,0x16,"d0");
  score_registerHandler(param_1,0x646,core_getFontList,0,"x0");
  score_registerHandler(param_1,0x647,core_getUserName,0,"x0");
  score_registerHandler(param_1,0x3b9,core_getEventMask,0,"*0");
  score_registerHandler(param_1,0x1c1,core_resolveCastMember,0,"x1");
  score_registerHandler(param_1,0x163,core_resolveCastMember,0,"x1");
  score_registerHandler(param_1,0x1c2,core_resolveMemberRef,0,"x");
  score_registerHandler(param_1,0x335,core_lookupCastMember,0,"x");
  score_registerHandler(param_1,0x1c3,core_getChannelCount,0,"d1d");
  score_registerHandler(param_1,0x1c4,core_returnEmptyString,0,"x1");
  score_registerHandler(param_1,0x648,core_checkEnvironment,0,"x1");
  score_registerHandler(param_1,0x655,core_openUrl,0,"-1");
  score_registerHandler(param_1,0x1c5,core_validateChannelHigh,0,"d2dd");
  score_registerHandler(param_1,0x1c6,core_validateChannelLow,0,"d2dd");
  score_registerHandler(param_1,0x1e7,core_intersectCastRefs,0,"x2");
  score_registerHandler(param_1,0x1ee,core_formatTimeString,0,"x4");
  score_registerHandler(param_1,0x1ef,core_parseTimeString,0,"x4");
  score_registerHandler(param_1,0x99,core_getStageRect,0,"x0");
  score_registerHandler(param_1,0x23a,core_openScriptWindow,0,"d0");
  score_registerHandler(param_1,0x23b,core_closeScriptWindow,0,"d0");
  score_registerHandler(param_1,0x23c,core_convertScriptText,0,"x2");
  score_registerHandler(param_1,0xff,crt_createSprite,0,"x");
  score_registerHandler(param_1,0x59,core_handleGetField,0,"x");
  score_registerHandler(param_1,0x58,core_handleGetField,0,"x");
  score_registerHandler(param_1,0x7b,crt_accessMemberField,0,"x");
  score_registerHandler(param_1,0x7c,core_handleNewTypedRef,0,"x");
  score_registerHandler(param_1,0x248,core_getBuiltinFunc,0x24,"d0");
  score_registerHandler(param_1,0x7d,score_getOrCreateInstance,0,"x1");
  score_registerHandler(param_1,0x68,core_resolveMemberByNumber,0,"x1");
  score_registerHandler(param_1,0x82,core_handleFieldOfMember,0,"*");
  score_registerHandler(param_1,0x2e,crt_resolveChannelArg,0,"x1");
  score_registerHandler(param_1,0x2d5,crt_checkBehaviorExists,0,"x1");
  score_registerHandler(param_1,0x79,&LAB_68018bd0,0,"d0");
  score_registerHandler(param_1,0x78,&LAB_68018be0,0,"d0");
  score_registerHandler(param_1,0x291,cast_createBitmap,0,"x");
  score_registerHandler(param_1,0x30f,core_countRegisteredEntries,0,"d0");
  score_registerHandler(param_1,0x310,core_getRegisteredKey,0,"x1");
  score_registerHandler(param_1,0x311,core_getRegisteredValue,0,"x1");
  score_registerHandler(param_1,0x2db,core_resolveRegisteredHandler,0,"x");
  score_registerHandler(param_1,0x63a,cast_newXtraInstance,0,"x");
  score_registerHandler(param_1,0x132,cast_buildRgbVector,0,"x");
  score_registerHandler(param_1,0x3d1,cast_buildColorVector,0,"x");
  score_registerHandler(param_1,0x138,core_createFileRef,0,"*");
  score_registerHandler(param_1,0x5fd,core_handleNewSpriteRef,0,"x1");
  score_registerHandler(param_1,0x662,core_handleNewColorRef,0,"x1");
  score_registerHandler(param_1,0x663,core_handleNewColorRefEnabled,0,"x1");
  return 0;
}


