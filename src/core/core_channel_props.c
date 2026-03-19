// Module: core
// Topic: Channel property access - score channel data read/write, cursor management
// Address range: 0x6801C070 - 0x6801C870
// Functions (11):
//   core_mapChannelPropId (0x6801C070)
//   core_accessChannelMember (0x6801C0F0)
//   core_accessChannelName (0x6801C1B0)
//   core_accessChannelRect (0x6801C260)
//   core_accessChannelWindow (0x6801C2C0)
//   core_accessChannelColor (0x6801C340)
//   core_accessChannelScript (0x6801C3C0)
//   core_dispatchChannelProp (0x6801C430)
//   core_accessChannelCursor (0x6801C730)
//   core_dispatchChannelAccess (0x6801C790)
//   core_accessChannelData (0x6801C870)

// ============================================================
// Function: core_mapChannelPropId (core_mapChannelPropId)
// Address: 6801c070
// Size: 61 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_mapChannelPropId(void)

{
  int local_14;
  int local_c;
  int local_18;
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0xf:
    return 0x1e8;
  case 0x10:
    return 0x1e9;
  default:
    return 0;
  case 0x14:
    return 0x1ea;
  case 0x15:
    return 0x1eb;
  case 0x27:
    return 0x325;
  case 0x28:
    return 0x324;
  }
}



// ============================================================
// Function: core_accessChannelMember (core_accessChannelMember)
// Address: 6801c0f0
// Size: 183 bytes
// Params: uint param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelMember(uint param_1,int param_2,int param_3,int *param_4)
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = param_4;
  uVar2 = param_1;
  if (param_3 == 0) {
    puVar1 = (uint *)(param_4 + 1);
    sprites_getChannelBounds(param_1,param_2,0,4,puVar1);
    param_4 = (int *)sprites_dispatchProperty(uVar2,*puVar1);
    core_getFieldValue(uVar2,&param_4,piVar3);
    return 0;
  }
  iVar4 = props_coerceToInt(param_1,param_4,(int *)&param_1);
  if (iVar4 == 0) {
    if ((*piVar3 != 0x40) && (*piVar3 != 0x43)) {
      props_setErrorAndReturn(uVar2,0x10);
      return 0;
    }
    param_4 = (int *)((uint)param_4 & 0xffff0000);
    iVar4 = crt_executePlatformCmd(uVar2,piVar3,sprites_resetMember,(short *)&param_4,0x24);
    if (iVar4 == 0) {
      return 0;
    }
    param_1 = CONCAT22((*(unsigned short *)((char *)&param_4 + 0)),(*(unsigned short *)((char *)&param_4 + 2)));
  }
  sprites_getChannelBounds(uVar2,param_2,1,4,&param_1);
  return 0;
}



// ============================================================
// Function: core_accessChannelName (core_accessChannelName)
// Address: 6801c1b0
// Size: 161 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelName(int param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  byte local_408 [1024];
  uint local_8;
  
  if (param_3 == 0) {
    local_408[0] = 0;
    events_getMiawCursorRef(param_1,param_2,local_408);
    props_readPascalString(param_1,local_408,param_4);
  }
  else {
    iVar1 = crt_getPlatformData(param_1,param_4,local_408);
    if (iVar1 != 0) {
      iVar1 = events_setMiawSpriteRef(param_1,param_2,local_408);
      if (iVar1 == 0) {
        props_setErrorAndReturn(param_1,0x6c);
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessChannelRect (core_accessChannelRect)
// Address: 6801c260
// Size: 90 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelRect(int param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  undefined4 local_c [2];
  
  if (param_3 == 0) {
    events_getMiawSpriteRef(param_1,param_2,local_c);
    props_transformRect(param_1,local_c,param_4);
  }
  else {
    iVar1 = props_getRectField(param_1,param_4);
    if (iVar1 != 0) {
      events_setMiawMediaRef(param_1,param_2,local_c);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessChannelWindow (core_accessChannelWindow)
// Address: 6801c2c0
// Size: 116 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelWindow(int param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  int local_18 [4];
  uint local_8;
  
  if (param_3 == 0) {
    events_getWindowData(param_1,param_2,local_18);
    props_computeRectOp(param_1,local_18,param_4);
  }
  else {
    iVar1 = props_createRect(param_1,param_4);
    if (iVar1 != 0) {
      events_setWindowData(param_1,param_2,local_18);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessChannelColor (core_accessChannelColor)
// Address: 6801c340
// Size: 127 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelColor(int param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  int local_14 [4];
  
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  if (param_3 == 0) {
    events_getMiawStageInfo(param_1,param_2,local_14);
    core_packColorComponents(param_4);
  }
  else {
    iVar1 = core_parseColorValue(param_1,param_4,local_14);
    if (iVar1 != 0) {
      events_getWindowInfo(param_1,param_2,local_14);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessChannelScript (core_accessChannelScript)
// Address: 6801c3c0
// Size: 110 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelScript(int param_1,int param_2,int param_3,uint *param_4)
{
  int iVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    uVar2 = sprites_getOrInitChannelData(param_1,param_2);
    param_4[1] = uVar2;
    if (uVar2 != 0) {
      *param_4 = 3;
      props_retainValue(param_1,param_4);
      return 0;
    }
  }
  else {
    iVar1 = props_setRectField(param_1,(int *)param_4);
    if (iVar1 != 0) {
      sprites_assignMember(param_1,param_2,(int *)param_4[1]);
      return 0;
    }
    props_setErrorAndReturn(param_1,0xd);
  }
  return 0;
}



// ============================================================
// Function: core_dispatchChannelProp (core_dispatchChannelProp)
// Address: 6801c430
// Size: 690 bytes
// Params: double * param_1, int * param_2, int param_3, uint param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchChannelProp(double *param_1,int *param_2,int param_3,uint param_4,uint *param_5)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint local_410;
  int local_40c;
  undefined1 local_408 [1024];
  
  iVar1 = props_coerceToInt((int)param_1,param_2,&local_40c);
  if (iVar1 == 0) {
    if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
      props_setErrorAndReturn((int)param_1,7);
      return 0;
    }
    iVar1 = crt_getPlatformData((int)param_1,param_2,local_408);
    if (iVar1 == 0) goto LAB_6801c6cf;
    local_40c = sprites_processEvent((int)param_1,(int)local_408,1);
    if (local_40c == 0) {
      props_setError((int)param_1,0x2a);
      return 0;
    }
  }
  iVar1 = crt_validateFrameIndex((int)param_1,local_40c);
  if (iVar1 != 0) {
    switch(param_3) {
    case 6:
      core_accessChannelColor((int)param_1,local_40c,param_4,(int *)param_5);
      return 0;
    case 0xf:
    case 0x10:
    case 0x14:
    case 0x15:
    case 0x27:
    case 0x28:
      iVar1 = events_getMiawVideoRef((int)param_1,(int)(short)local_40c);
      if (iVar1 != 0) {
        uVar2 = core_mapChannelPropId();
        sprites_resolveChannelProperty(param_1,local_40c,param_4,uVar2,param_5);
        return 0;
      }
      iVar1 = events_getWindowProperty((int)param_1,(int)(short)local_40c);
      if (iVar1 == 0) {
        props_setErrorAndReturn((int)param_1,0x34);
        return 0;
      }
      if (param_3 == 0xf) {
        core_accessChannelBounds((int)param_1,(short)local_40c,0xf,param_4,(int *)param_5);
        return 0;
      }
      break;
    case 0x21:
      core_accessChannelRect((int)param_1,local_40c,param_4,(int *)param_5);
      return 0;
    case 0x22:
      core_accessChannelWindow((int)param_1,local_40c,param_4,(int *)param_5);
      return 0;
    case 0x25:
      core_accessChannelMember((uint)param_1,local_40c,param_4,(int *)param_5);
      return 0;
    case 0x26:
      core_accessChannelScript((int)param_1,local_40c,param_4,param_5);
      return 0;
    case 0x2a:
      core_accessChannelName((int)param_1,local_40c,param_4,(int *)param_5);
      return 0;
    }
    if (param_4 == 0) {
      puVar3 = param_5 + 1;
      iVar1 = 0;
    }
    else {
      iVar1 = props_requireInt((int)param_1,(int *)param_5,(int *)&local_410);
      if (iVar1 == 0) goto LAB_6801c6cf;
      puVar3 = &local_410;
      iVar1 = 1;
    }
    sprites_getChannelBounds((int)param_1,(int)(short)local_40c,iVar1,param_3,puVar3);
  }
LAB_6801c6cf:
  return 0;
}



// ============================================================
// Function: core_accessChannelCursor (core_accessChannelCursor)
// Address: 6801c730
// Size: 95 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelCursor(int param_1)
{
  int in_EAX;
  int iVar1;
  int *unaff_ESI;
  
  if (param_1 == 0) {
    iVar1 = events_getStageTimeout(in_EAX);
    unaff_ESI[1] = iVar1;
    if (iVar1 != 0) {
      *unaff_ESI = 6;
    }
  }
  else {
    if (*unaff_ESI == 4) {
      if (unaff_ESI[1] == 0) {
        events_setStageTimeout(in_EAX,0);
        return 0;
      }
      props_setErrorAndReturn(in_EAX,0xc);
      return 0;
    }
    if (*unaff_ESI == 6) {
      events_setStageTimeout(in_EAX,unaff_ESI[1]);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_dispatchChannelAccess (core_dispatchChannelAccess)
// Address: 6801c790
// Size: 191 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, undefined4 param_4, int param_5, int param_6, int param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
core_dispatchChannelAccess(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,int param_5,
            int param_6,int param_7)
{
  int *piVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  switch(param_4) {
  case 1:
    core_accessChannelCursor(param_5);
    return 0;
  case 2:
    sVar2 = 1;
    if (param_7 == 0) {
      sVar2 = cast_bridgeXtraCall(param_3 + 0x1c,param_2,param_3,(int *)(param_3 + 0x1c));
      if (*(int *)(param_3 + 0x7c) != 0) {
        return 0;
      }
      props_popValue(param_3);
    }
    iVar3 = sprites_getMemberByChannel(param_3,sVar2);
    *(int *)(param_6 + 4) = iVar3;
    break;
  case 3:
    iVar3 = sprites_handleTextClick(param_3);
    *(int *)(param_6 + 4) = iVar3;
    return 0;
  case 4:
    uVar4 = sprites_getMemberCount(param_3);
    *(int *)(param_6 + 4) = (int)(short)uVar4;
    return 0;
  case 5:
    piVar1 = *(int **)(**(int **)(param_3 + 8) + 0x514);
    if (piVar1 != (int *)0x0) {
      uVar5 = props_getListLength(param_3,piVar1);
      *(undefined4 *)(param_6 + 4) = uVar5;
      return 0;
    }
    *(undefined4 *)(param_6 + 4) = 0;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: core_accessChannelData (core_accessChannelData)
// Address: 6801c870
// Size: 39 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelData(uint param_1,int param_2,int param_3,uint *param_4)
{
  if (param_3 != 0) {
    events_getMiawActiveFlag(param_1,param_2,param_4);
    return 0;
  }
  events_setMiawActiveFlag(param_1,param_2,param_4);
  return 0;
}


