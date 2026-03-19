// Module: events
// Topic: Score property getters and setters using Ordinal_360/361/362/371/372 pairs
// Address range: 0x68063120 - 0x680645e0
// Functions (57):
//   events_invalidateScoreLine
//   events_getScoreProperty2
//   events_getFrameLabel
//   events_setFrameLabel
//   events_getScriptRef
//   events_setScriptRef
//   events_getTransitionRef
//   events_setTransitionRef
//   events_getScoreChannelRef
//   events_setScoreChannelRef
//   events_getScoreMemberRef
//   events_setScoreMemberRef
//   events_getScoreColorRef
//   events_setScoreColorRef
//   events_setScriptProperty
//   events_enterScriptContext
//   events_setScriptMode
//   events_resolveScriptRef
//   events_getDebugOffset
//   events_getOrCreateContextRef
//   events_setContextRef
//   events_getStageTimeout
//   events_setStageTimeout
//   events_getOrCreateGlobalRef
//   events_setGlobalRef
//   events_isTraceEnabled
//   events_setTraceEnabled
//   events_resolveFilePath
//   events_getScorePropertyState
//   events_setScorePropertyState
//   events_setStageColorDepth
//   events_setStageResolution
//   events_setStageMonitorRef
//   events_resetStageMonitor
//   events_setStageOverlay
//   events_getMediaStreamRef
//   events_setMediaStreamRef
//   events_getMediaStreamOffset
//   events_setMediaStreamOffset
//   events_getIdleTimeout
//   events_setIdleTimeout
//   events_isChannelMutable
//   events_setChannelMutability
//   events_getScoreInkType
//   events_setScoreInkType
//   events_getScoreSoundRef
//   events_setScoreSoundRef
//   events_getScoreBlendAmount
//   events_setScoreBlendAmount
//   events_getScoreColorValue
//   events_setScoreColorValue
//   events_getScoreTrailFlag
//   events_setScoreTrailFlag
//   events_getScoreFrameRate
//   events_setScoreFrameRate
//   events_getScoreMovableFlag
//   events_setScoreMovableFlag
//   events_getScoreFlag
//   events_setScoreFlag
//   events_getStageWindowRef
//   events_getParentStageRef
//   events_openMovieFile
//   events_compileMovieScript
//   events_getScoreProperty
//   events_formatScoreVersion
//   events_getScoreAnnotation
//   events_setScoreAnnotation
//   events_getScoreSpacing
//   events_setScoreSpacing
//   events_getScoreDuration
//   events_setScoreDuration
//   events_getScoreChannelCount
//   events_getScoreMarkerName
//   events_setScoreMarkerIndex
//   events_getScoreMarkerLabel
//   events_getScoreMarkerCount
//   events_setScoreMarkerCount
//   events_getScoreLoopStart
//   events_getScoreLoopEnd

// ============================================================
// Function: events_invalidateScoreLine (events_invalidateScoreLine)
// Address: 68063120
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_invalidateScoreLine(int param_1)
{
  int local_14;
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_154(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28));
  return 0;
}



// ============================================================
// Function: events_getScoreProperty2 (FUN_68063140)
// Address: 68063140
// Size: 52 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreProperty2(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
    if (piVar2 != (int *)0x0) {
      uVar3 = Ordinal_480(piVar2);
      return uVar3;
    }
  }
  return 1000;
}



// ============================================================
// Function: events_getFrameLabel (events_getFrameLabel)
// Address: 68063180
// Size: 136 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getFrameLabel(int param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar6 = 0x3ff;
  puVar5 = param_2 + 1;
  puVar3 = puVar5;
  iVar1 = Ordinal_58(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28));
  iVar2 = Ordinal_606(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),iVar1,(int)puVar3,iVar6);
  if (iVar2 == -1) {
    iVar2 = 0;
    *puVar5 = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    puVar3 = (undefined1 *)Ordinal_1205(puVar5,0xd);
    if (puVar3 != (undefined1 *)0x0) {
      iVar2 = (int)puVar3 - (int)puVar5;
      *puVar3 = 0;
    }
  }
  param_2[iVar2 + 1] = 0;
  if (iVar2 < 0xff) {
    *param_2 = (char)iVar2;
    return uVar4;
  }
  *param_2 = 0xff;
  return uVar4;
}



// ============================================================
// Function: events_setFrameLabel (events_setFrameLabel)
// Address: 68063210
// Size: 123 bytes
// Params: int param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setFrameLabel(int param_1,byte *param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar3 = Ordinal_58(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28));
  if (param_2 != (byte *)0x0) {
    iVar3 = Ordinal_609(*(undefined4 **)(iVar1 + 0x20),(int)*(int **)(iVar1 + 0x28),iVar3);
    if (*param_2 == 0xff) {
      uVar2 = Ordinal_1201(param_2 + 1);
    }
    else {
      uVar2 = (ushort)*param_2;
    }
    Ordinal_608(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),iVar3,(int)(param_2 + 1),
                (int)(short)uVar2);
    return 1;
  }
  Ordinal_607(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),iVar3,iVar3);
  return 1;
}



// ============================================================
// Function: events_getScriptRef (events_getScriptRef)
// Address: 68063290
// Size: 86 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScriptRef(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  short local_14 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_372(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),3,(undefined4 *)local_14);
  uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_14[0]);
  *param_2 = uVar2;
  return 0;
}



// ============================================================
// Function: events_setScriptRef (events_setScriptRef)
// Address: 680632f0
// Size: 73 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setScriptRef(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) == 0) {
    return 0;
  }
  param_1 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  uVar2 = Ordinal_371(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),3,(short *)&param_1);
  return uVar2;
}



// ============================================================
// Function: events_getTransitionRef (events_getTransitionRef)
// Address: 68063340
// Size: 64 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getTransitionRef(int param_1)
{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_372(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),4,local_14);
  return 0;
}



// ============================================================
// Function: events_setTransitionRef (events_setTransitionRef)
// Address: 68063380
// Size: 58 bytes
// Params: int param_1, undefined2 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setTransitionRef(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) == 0) {
    return 0;
  }
  param_1 = CONCAT22((*(unsigned short *)((char *)&param_1 + 2)),param_2);
  uVar2 = Ordinal_371(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),4,(short *)&param_1);
  return uVar2;
}



// ============================================================
// Function: events_getScoreChannelRef (events_getScoreChannelRef)
// Address: 680633c0
// Size: 114 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreChannelRef(int param_1,undefined4 *param_2)
{
  int iVar1;
  int *piVar2;
  undefined4 local_1c [2];
  int local_14 [3];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_372(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),8,local_14);
  piVar2 = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  Ordinal_1130(local_1c,8);
  Ordinal_431(piVar2,local_14[0],0,(short *)local_1c);
  *param_2 = local_1c[0];
  return 0;
}



// ============================================================
// Function: events_setScoreChannelRef (events_setScoreChannelRef)
// Address: 68063440
// Size: 73 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setScoreChannelRef(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) == 0) {
    return 0;
  }
  param_1 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  uVar2 = Ordinal_371(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),9,(short *)&param_1);
  return uVar2;
}



// ============================================================
// Function: events_getScoreMemberRef (events_getScoreMemberRef)
// Address: 68063490
// Size: 86 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreMemberRef(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  short local_14 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_372(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),2,(undefined4 *)local_14);
  uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_14[0]);
  *param_2 = uVar2;
  return 0;
}



// ============================================================
// Function: events_setScoreMemberRef (events_setScoreMemberRef)
// Address: 680634f0
// Size: 73 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setScoreMemberRef(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) == 0) {
    return 0;
  }
  param_1 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  uVar2 = Ordinal_371(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),2,(short *)&param_1);
  return uVar2;
}



// ============================================================
// Function: events_getScoreColorRef (events_getScoreColorRef)
// Address: 68063540
// Size: 103 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreColorRef(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  short local_14 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 == 1) {
    uVar2 = 6;
  }
  else {
    if (param_2 != 2) goto LAB_68063595;
    uVar2 = 7;
  }
  Ordinal_372(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),uVar2,(undefined4 *)local_14);
  uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_14[0]);
  *param_3 = uVar2;
LAB_68063595:
  return 0;
}



// ============================================================
// Function: events_setScoreColorRef (events_setScoreColorRef)
// Address: 680635b0
// Size: 100 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setScoreColorRef(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) == 0) {
    return 0;
  }
  param_1 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3);
  if (param_2 == 1) {
    uVar2 = 6;
  }
  else {
    if (param_2 != 2) {
      return 1;
    }
    uVar2 = 7;
  }
  uVar2 = Ordinal_371(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),uVar2,(short *)&param_1);
  return uVar2;
}



// ============================================================
// Function: events_setScriptProperty (events_setScriptProperty)
// Address: 68063620
// Size: 33 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScriptProperty(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  lingo_setScriptProperty(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  return 0;
}



// ============================================================
// Function: events_enterScriptContext (events_enterScriptContext)
// Address: 68063650
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_enterScriptContext(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  lingo_enterScriptContext(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  return 0;
}



// ============================================================
// Function: events_setScriptMode (events_setScriptMode)
// Address: 68063670
// Size: 33 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScriptMode(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  lingo_setScriptMode(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  return 0;
}




// ============================================================
// Function: events_resolveScriptRef (events_resolveScriptRef)
// Address: 680636a0
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resolveScriptRef(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  lingo_resolveScriptRef(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  return 0;
}



// ============================================================
// Function: events_getDebugOffset (events_getDebugOffset)
// Address: 680636c0
// Size: 22 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getDebugOffset(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x1dc);
}



// ============================================================
// Function: events_getOrCreateContextRef (events_getOrCreateContextRef)
// Address: 680636e0
// Size: 54 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getOrCreateContextRef(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x714) == 0) {
    piVar2 = (int *)cast_getContextRef(param_1);
    *(int **)(iVar1 + 0x714) = piVar2;
    crt_getScriptProperty(param_1,piVar2);
  }
  return *(undefined4 *)(iVar1 + 0x714);
}



// ============================================================
// Function: events_setContextRef (events_setContextRef)
// Address: 68063720
// Size: 75 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setContextRef(int param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int **)(iVar1 + 0x714) != (int *)0x0) {
    crt_getScriptPropertyEx(param_1,*(int **)(iVar1 + 0x714));
    cast_releaseObject(param_1,*(int **)(iVar1 + 0x714));
  }
  crt_getScriptProperty(param_1,param_2);
  *(int **)(iVar1 + 0x714) = param_2;
  cast_retainObject(param_1,param_2);
  return 0;
}



// ============================================================
// Function: events_getStageTimeout (events_getStageTimeout)
// Address: 68063770
// Size: 22 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getStageTimeout(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x718);
}



// ============================================================
// Function: events_setStageTimeout (events_setStageTimeout)
// Address: 68063790
// Size: 25 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setStageTimeout(int param_1,undefined4 param_2)
{
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x718) = param_2;
  return 0;
}



// ============================================================
// Function: events_getOrCreateGlobalRef (events_getOrCreateGlobalRef)
// Address: 680637b0
// Size: 44 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * events_getOrCreateGlobalRef(int param_1)

{
  if (DAT_681962d0 == (int *)0x0) {
    DAT_681962d0 = (int *)cast_getContextRef(param_1);
    crt_getScriptProperty(param_1,DAT_681962d0);
  }
  return DAT_681962d0;
}



// ============================================================
// Function: events_setGlobalRef (events_setGlobalRef)
// Address: 680637e0
// Size: 84 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setGlobalRef(int param_1,int *param_2)
{
  crt_getScriptPropertyEx(param_1,DAT_681962d0);
  cast_releaseObject(param_1,DAT_681962d0);
  crt_getScriptProperty(param_1,param_2);
  DAT_681962d0 = param_2;
  if (DAT_681962d4 == (code *)0x0) {
    DAT_681962d4 = Ordinal_101;
    Ordinal_1302(Ordinal_101);
  }
  return 0;
}



// ============================================================
// Function: events_isTraceEnabled (events_isTraceEnabled)
// Address: 68063840
// Size: 13 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool events_isTraceEnabled(void)

{
  int iVar1;
  
  iVar1 = Ordinal_1306();
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: events_setTraceEnabled (events_setTraceEnabled)
// Address: 68063850
// Size: 21 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setTraceEnabled(undefined4 param_1,int param_2)
{
  Ordinal_1305(param_2 == 0);
  return 0;
}



// ============================================================
// Function: events_resolveFilePath (events_resolveFilePath)
// Address: 68063870
// Size: 419 bytes
// Params: int param_1, int * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resolveFilePath(int param_1,int *param_2,uint *param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 local_c38 [1048];
  undefined1 local_820 [1048];
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_1116(param_2);
  if (*(char *)(*param_2 + -1 + iVar1) == '\0') {
    iVar1 = iVar1 + -1;
  }
  Ordinal_1234(&local_408,param_2,0,iVar1);
  Ordinal_1309(local_820,0x400,local_407,2);
  if (iVar2 == 0) {
LAB_6806390c:
    Ordinal_1320(local_820,DAT_681956e0);
    Ordinal_1316(local_820);
    Ordinal_1309(local_c38,0x400,local_407,2);
    Ordinal_1314(local_c38,local_407,0x3ff);
    Ordinal_1317(local_820,local_407);
    if (iVar2 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(iVar2 + 0x20);
    }
    iVar2 = Ordinal_1307(local_820,0,0x1c,uVar4);
    if (iVar2 != 0) goto LAB_68063990;
  }
  else {
    iVar1 = sprites_getStageRef(param_1);
    if (iVar1 != 0) goto LAB_6806390c;
    iVar1 = scoreEngine_setPropertyEx(*(int *)(iVar2 + 0x20),local_820,0x1c,0,0);
    if (iVar1 == 0) goto LAB_6806390c;
LAB_68063990:
    Ordinal_1310(local_820,local_407,0x3ff);
    iVar2 = Ordinal_1201(local_407);
    local_407[iVar2] = 0;
    local_408 = (byte)iVar2;
    if (0xfe < iVar2) {
      local_408 = 0xff;
    }
    piVar3 = props_pascalToHandle(&local_408);
    if (piVar3 != (int *)0x0) goto LAB_680639fe;
  }
  if (param_3 != (uint *)0x0) {
    iVar2 = sprites_getStageRef(param_1);
    *param_3 = (uint)(iVar2 == 0);
  }
LAB_680639fe:
  return 0;
}



// ============================================================
// Function: events_getScorePropertyState (FUN_68063a20)
// Address: 68063a20
// Size: 33 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_getScorePropertyState(void)

{
  int iVar1;
  
  iVar1 = strings_getMediaStreamState();
  return (int)*(short *)(iVar1 + 0xc);
}



// ============================================================
// Function: events_setScorePropertyState (events_setScorePropertyState)
// Address: 68063a50
// Size: 37 bytes
// Params: undefined4 param_1, undefined2 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScorePropertyState(undefined4 param_1,undefined2 param_2)
{
  int iVar1;
  
  iVar1 = strings_getMediaStreamState();
  *(undefined2 *)(iVar1 + 0xc) = param_2;
  return 0;
}



// ============================================================
// Function: events_setStageColorDepth (events_setStageColorDepth)
// Address: 68063a80
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setStageColorDepth(int param_1,int param_2)
{
  crt_loadFormatChunk((undefined4 *)**(undefined4 **)(**(int **)(param_1 + 8) + 0x51c),param_2);
  return 0;
}



// ============================================================
// Function: events_setStageResolution (events_setStageResolution)
// Address: 68063ab0
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setStageResolution(int param_1,int param_2)
{
  crt_flushFormatEntries((undefined4 *)**(undefined4 **)(**(int **)(param_1 + 8) + 0x51c),param_2);
  return 0;
}



// ============================================================
// Function: events_setStageMonitorRef (events_setStageMonitorRef)
// Address: 68063ae0
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setStageMonitorRef(int param_1,int param_2)
{
  crt_seekFormatEntry((undefined4 *)**(undefined4 **)(**(int **)(param_1 + 8) + 0x51c),param_2);
  return 0;
}



// ============================================================
// Function: events_resetStageMonitor (events_resetStageMonitor)
// Address: 68063b10
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resetStageMonitor(void)
{
  crt_chunkNoop();
  return 0;
}



// ============================================================
// Function: events_setStageOverlay (events_setStageOverlay)
// Address: 68063b30
// Size: 33 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setStageOverlay(int param_1,undefined4 param_2)
{
  crt_setChunkCallback(**(int **)(**(int **)(param_1 + 8) + 0x51c),param_2);
  return 0;
}



// ============================================================
// Function: events_getMediaStreamRef (events_getMediaStreamRef)
// Address: 68063b60
// Size: 31 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMediaStreamRef(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)strings_getMediaStreamState();
  return *puVar1;
}



// ============================================================
// Function: events_setMediaStreamRef (events_setMediaStreamRef)
// Address: 68063b80
// Size: 34 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMediaStreamRef(undefined4 param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)strings_getMediaStreamState();
  *puVar1 = param_2;
  return 0;
}



// ============================================================
// Function: events_getMediaStreamOffset (events_getMediaStreamOffset)
// Address: 68063bb0
// Size: 32 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getMediaStreamOffset(void)

{
  int iVar1;
  
  iVar1 = strings_getMediaStreamState();
  return *(undefined4 *)(iVar1 + 4);
}



// ============================================================
// Function: events_setMediaStreamOffset (events_setMediaStreamOffset)
// Address: 68063bd0
// Size: 35 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setMediaStreamOffset(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = strings_getMediaStreamState();
  *(undefined4 *)(iVar1 + 4) = param_2;
  return 0;
}




// ============================================================
// Function: events_getIdleTimeout (events_getIdleTimeout)
// Address: 68063c00
// Size: 19 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getIdleTimeout(int param_1)

{
  int local_14;
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x50);
}



// ============================================================
// Function: events_setIdleTimeout (events_setIdleTimeout)
// Address: 68063c20
// Size: 29 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setIdleTimeout(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  *(undefined4 *)(iVar1 + 0x50) = param_2;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  return 0;
}



// ============================================================
// Function: events_isChannelMutable (events_isChannelMutable)
// Address: 68063c40
// Size: 34 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool events_isChannelMutable(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = lingo_mutateChannelEx(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: events_setChannelMutability (events_setChannelMutability)
// Address: 68063c70
// Size: 47 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelMutability(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 == 0) {
    events_resetMiawChannel(param_1);
    return 0;
  }
  lingo_mutateChannel(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),0);
  return 0;
}



// ============================================================
// Function: events_getScoreInkType (events_getScoreInkType)
// Address: 68063ca0
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreInkType(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),3,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreInkType (events_setScoreInkType)
// Address: 68063cd0
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreInkType(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),3,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreSoundRef (events_getScoreSoundRef)
// Address: 68063d00
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreSoundRef(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),8,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreSoundRef (events_setScoreSoundRef)
// Address: 68063d30
// Size: 70 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreSoundRef(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),8,(double *)local_14);
  uVar3 = 0;
  iVar2 = 0;
  Ordinal_58(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28));
  events_handleSoundChange(iVar2,uVar3);
  return 0;
}



// ============================================================
// Function: events_getScoreBlendAmount (events_getScoreBlendAmount)
// Address: 68063d80
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreBlendAmount(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x1e,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreBlendAmount (events_setScoreBlendAmount)
// Address: 68063db0
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreBlendAmount(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x1e,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreColorValue (events_getScoreColorValue)
// Address: 68063de0
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreColorValue(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x1a,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreColorValue (events_setScoreColorValue)
// Address: 68063e10
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreColorValue(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x1a,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreTrailFlag (events_getScoreTrailFlag)
// Address: 68063e40
// Size: 43 bytes
// Params: int param_1
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 events_getScoreTrailFlag(int param_1)

{
  int iVar1;
  undefined1 local_1c [24];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x20,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreTrailFlag (events_setScoreTrailFlag)
// Address: 68063e70
// Size: 46 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreTrailFlag(int param_1,undefined1 param_2)
{
  int iVar1;
  undefined1 local_14 [16];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x20,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreFrameRate (events_getScoreFrameRate)
// Address: 68063ea0
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreFrameRate(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x31,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreFrameRate (events_setScoreFrameRate)
// Address: 68063ed0
// Size: 64 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreFrameRate(int param_1,int param_2)
{
  int iVar1;
  int local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x31,(double *)local_14);
  *(uint *)(param_1 + 0xe0) = (uint)(9 < param_2);
  return 0;
}



// ============================================================
// Function: events_getScoreMovableFlag (events_getScoreMovableFlag)
// Address: 68063f10
// Size: 43 bytes
// Params: int param_1
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 events_getScoreMovableFlag(int param_1)

{
  int iVar1;
  undefined1 local_1c [24];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x21,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreMovableFlag (events_setScoreMovableFlag)
// Address: 68063f40
// Size: 46 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreMovableFlag(int param_1,undefined1 param_2)
{
  int iVar1;
  undefined1 local_14 [16];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x21,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreFlag (FUN_68063f70)
// Address: 68063f70
// Size: 43 bytes
// Params: int param_1
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 events_getScoreFlag(int param_1)

{
  int iVar1;
  undefined1 local_1c [24];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x19,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreFlag (FUN_68063fa0)
// Address: 68063fa0
// Size: 46 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreFlag(int param_1,undefined1 param_2)
{
  int iVar1;
  undefined1 local_14 [16];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x19,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getStageWindowRef (events_getStageWindowRef)
// Address: 68063fd0
// Size: 42 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getStageWindowRef(int param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  Ordinal_54(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),&local_8);
  return local_8;
}



// ============================================================
// Function: events_getParentStageRef (events_getParentStageRef)
// Address: 68064000
// Size: 72 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_getParentStageRef(int param_1)

{
  int iVar1;
  
  iVar1 = (*(int **)(param_1 + 8))[1];
  param_1 = events_checkStageActive(*(int *)(**(int **)(param_1 + 8) + 0x51c));
  if (((param_1 == 0) && (iVar1 = *(int *)(iVar1 + 0x2c), iVar1 != 0)) &&
     (iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x18), iVar1 != 0)) {
    Ordinal_54(*(int *)(iVar1 + 0xc),&param_1);
  }
  return param_1;
}




// ============================================================
// Function: events_openMovieFile (events_openMovieFile)
// Address: 68064050
// Size: 300 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_openMovieFile(int param_1,int param_2,int param_3,int param_4)
{
  int local_14;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_424;
  int local_420 [262];
  uint local_8;
  
  local_424 = 0;
  iVar4 = (*(int **)(param_1 + 8))[1];
  puVar1 = *(undefined4 **)(**(int **)(param_1 + 8) + 0x51c);
  Ordinal_1130(local_420,0x418);
  Ordinal_1309(local_420,0x400,param_2 + 1,2);
  if (*(code **)(DAT_681962f8 + 0x24) != (code *)0x0) {
    (**(code **)(DAT_681962f8 + 0x24))(local_420,local_420,&local_424,0,1);
  }
  iVar2 = scoreEngine_setPropertyEx(*(int *)(iVar4 + 0x20),local_420,0x15,0,0);
  if (iVar2 != 0) {
    iVar2 = events_getScorePropertyState();
    uVar3 = lingo_destroyLifecycle(*(int *)(iVar4 + 0x20));
    iVar4 = Ordinal_137(*(int *)(iVar4 + 0x20),local_420,param_3,param_4,local_424,
                        (uint)(iVar2 != 0),(void *)(uVar3 & 0xfffffffe),0,1);
    if (iVar4 == 1) {
      return 0;
    }
    Ordinal_120((undefined4 *)*puVar1,(undefined1 *)0x0,0);
  }
  return 0;
}



// ============================================================
// Function: events_compileMovieScript (events_compileMovieScript)
// Address: 68064180
// Size: 201 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_compileMovieScript(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  local_424 = 0;
  iVar2 = (*(int **)(param_1 + 8))[1];
  puVar1 = *(undefined4 **)(**(int **)(param_1 + 8) + 0x51c);
  Ordinal_1309(local_420,0x400,param_2 + 1,2);
  if (*(code **)(DAT_681962f8 + 0x24) != (code *)0x0) {
    (**(code **)(DAT_681962f8 + 0x24))(local_420,local_420,&local_424,0,1);
  }
  iVar2 = scoreEngine_setPropertyEx(*(int *)(iVar2 + 0x20),local_420,0x15,0,0);
  if (iVar2 != 0) {
    iVar2 = lingo_compileScript((undefined4 *)*puVar1,(int)local_420);
    if (iVar2 != 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_getScoreProperty (FUN_68064250)
// Address: 68064250
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreProperty(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),1,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_formatScoreVersion (events_formatScoreVersion)
// Address: 68064280
// Size: 104 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_formatScoreVersion(int param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar1 = events_getScoreProperty(param_1);
  iVar2 = 1;
  uVar3 = 3;
  if ((uVar1 & 0xf000) != 0) {
    param_2[1] = ((byte)(uVar1 >> 0xc) & 0xf) + 0x30;
    iVar2 = 2;
    uVar3 = 4;
  }
  param_2[iVar2] = ((byte)(uVar1 >> 8) & 0xf) + 0x30;
  param_2[iVar2 + 1] = ((byte)(uVar1 >> 4) & 0xf) + 0x30;
  param_2[iVar2 + 2] = ((byte)uVar1 & 0xf) + 0x30;
  param_2[iVar2 + 3] = 0;
  *param_2 = uVar3;
  return 0;
}



// ============================================================
// Function: events_getScoreAnnotation (events_getScoreAnnotation)
// Address: 680642f0
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreAnnotation(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x23,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreAnnotation (events_setScoreAnnotation)
// Address: 68064320
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreAnnotation(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x23,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreSpacing (events_getScoreSpacing)
// Address: 68064350
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreSpacing(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x24,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreSpacing (events_setScoreSpacing)
// Address: 68064380
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreSpacing(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x24,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreDuration (events_getScoreDuration)
// Address: 680643b0
// Size: 43 bytes
// Params: int param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 events_getScoreDuration(int param_1)

{
  int iVar1;
  double local_1c [3];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x35,local_1c);
  return (float10)local_1c[0];
}



// ============================================================
// Function: events_setScoreDuration (events_setScoreDuration)
// Address: 680643e0
// Size: 46 bytes
// Params: int param_1, double param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreDuration(int param_1,double param_2)
{
  int iVar1;
  double local_14 [2];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x35,local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreChannelCount (events_getScoreChannelCount)
// Address: 68064410
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreChannelCount(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x25,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_getScoreMarkerName (events_getScoreMarkerName)
// Address: 68064440
// Size: 109 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreMarkerName(int param_1,undefined1 *param_2)
{
  int iVar1;
  undefined1 *local_1c;
  int local_18;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_18 = 0x3ff;
  local_1c = param_2 + 1;
  iVar1 = Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x29,
                      (double *)&local_1c);
  if (iVar1 == 0) {
    param_2[1] = 0;
    *param_2 = 0;
    return 0;
  }
  param_2[local_18 + 1] = 0;
  if (local_18 < 0xff) {
    *param_2 = (char)local_18;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: events_setScoreMarkerIndex (events_setScoreMarkerIndex)
// Address: 680644b0
// Size: 47 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreMarkerIndex(int param_1,int param_2)
{
  int iVar1;
  int local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2 + 1;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x2a,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreMarkerLabel (events_getScoreMarkerLabel)
// Address: 680644e0
// Size: 109 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreMarkerLabel(int param_1,undefined1 *param_2)
{
  int iVar1;
  undefined1 *local_1c;
  int local_18;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_18 = 0x3ff;
  local_1c = param_2 + 1;
  iVar1 = Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x2a,
                      (double *)&local_1c);
  if (iVar1 == 0) {
    param_2[1] = 0;
    *param_2 = 0;
    return 0;
  }
  param_2[local_18 + 1] = 0;
  if (local_18 < 0xff) {
    *param_2 = (char)local_18;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: events_getScoreMarkerCount (events_getScoreMarkerCount)
// Address: 68064550
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getScoreMarkerCount(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x2b,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setScoreMarkerCount (events_setScoreMarkerCount)
// Address: 68064580
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setScoreMarkerCount(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x2b,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getScoreLoopStart (events_getScoreLoopStart)
// Address: 680645b0
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreLoopStart(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x2c,(double *)local_1c);
  *param_2 = local_1c[0];
  return 0;
}



// ============================================================
// Function: events_getScoreLoopEnd (events_getScoreLoopEnd)
// Address: 680645e0
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScoreLoopEnd(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = *param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x2c,(double *)local_14);
  return 0;
}




