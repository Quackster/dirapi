// Module: events
// Topic: Channel data access, edit commands, and extended score property operations
// Address range: 0x68064610 - 0x680650a0
// Functions (32):
//   events_getChannelProp2D
//   events_setChannelProp2D
//   events_getChannelProp2E
//   events_setChannelProp2E
//   events_getChannelProp2F
//   events_setChannelProp2F
//   events_editChannel
//   events_editChannelData
//   events_resolveChannelPath
//   events_writeChannelProperty
//   events_renderChannelSprite
//   events_setEditProperty
//   events_getChannelProp1B
//   events_getChannelEditMode
//   events_setChannelEditMode
//   events_getChannelSelection
//   events_setChannelSelection
//   events_getEditRef
//   events_dispatchFrameEvent
//   events_resolveScriptHandler
//   sprites_handleEditCommand
//   sprites_handleEditCommand2
//   events_notifyFocusChange
//   events_handleIdleEvent
//   events_resetFrameState
//   events_editChannelEx
//   events_readChannelProperty
//   events_evaluateFrameScript
//   events_initMouseState
//   events_clampToSpriteRect
//   events_findSortedSprite
//   events_getEditState

// ============================================================
// Function: events_getChannelProp2D (events_getChannelProp2D)
// Address: 68064610
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getChannelProp2D(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x2d,(double *)local_1c);
  *param_2 = local_1c[0];
  return 0;
}



// ============================================================
// Function: events_setChannelProp2D (events_setChannelProp2D)
// Address: 68064640
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelProp2D(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = *param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x2d,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getChannelProp2E (events_getChannelProp2E)
// Address: 68064670
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getChannelProp2E(int param_1)

{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x2e,(double *)local_1c);
  return local_1c[0];
}



// ============================================================
// Function: events_setChannelProp2E (events_setChannelProp2E)
// Address: 680646a0
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelProp2E(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x2e,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_getChannelProp2F (events_getChannelProp2F)
// Address: 680646d0
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getChannelProp2F(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_1c [6];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x2f,(double *)local_1c);
  *param_2 = local_1c[0];
  return 0;
}



// ============================================================
// Function: events_setChannelProp2F (events_setChannelProp2F)
// Address: 68064700
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelProp2F(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_14 [4];
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = *param_2;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x2f,(double *)local_14);
  return 0;
}



// ============================================================
// Function: events_editChannel (FUN_68064730)
// Address: 68064730
// Size: 49 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_editChannel(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = param_2;
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x30,(double *)&local_1c);
  return local_18;
}



// ============================================================
// Function: events_editChannelData (FUN_68064770)
// Address: 68064770
// Size: 52 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_editChannelData(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14 = param_2;
  local_10 = param_3;
  Ordinal_361(*(undefined4 **)(iVar1 + 0x20),*(int **)(iVar1 + 0x28),0x30,(double *)&local_14);
  return 0;
}



// ============================================================
// Function: events_resolveChannelPath (events_resolveChannelPath)
// Address: 680647b0
// Size: 371 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resolveChannelPath(int param_1,undefined4 *param_2)
{
  int iVar1;
  int *piVar2;
  int local_82c;
  int *local_828;
  undefined4 local_824;
  undefined1 local_820 [1048];
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20);
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      if ((piVar2 == (int *)0x0) || (iVar1 = *piVar2, iVar1 == 0)) {
        iVar1 = *piVar2;
      }
      Ordinal_2330();
      local_824 = 0;
      local_828 = DAT_68196374;
      DAT_68196374 = &local_82c;
      local_82c = iVar1;
    }
  }
  props_cStringToPascal(param_2,&local_408);
  iVar1 = Ordinal_1309(local_820,0x400,local_407,2);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1307(local_820,piVar2 + 10,0x1e,0);
    if (iVar1 != 0) {
      Ordinal_1310(local_820,local_407,0x3ff);
      iVar1 = Ordinal_1201(local_407);
      local_407[iVar1] = 0;
      iVar1 = Ordinal_1201(local_407);
      if (iVar1 < 0xff) {
        local_408 = Ordinal_1201(local_407);
        props_pascalToHandle(&local_408);
      }
      else {
        local_408 = 0xff;
        props_pascalToHandle(&local_408);
      }
      goto LAB_680648f9;
    }
  }
  Ordinal_1120(param_2,0);
LAB_680648f9:
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_828;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: events_writeChannelProperty (events_writeChannelProperty)
// Address: 68064930
// Size: 56 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_writeChannelProperty(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = events_getScoreProperty(param_1);
  if (uVar2 < 0x1100) {
    Ordinal_613(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: events_renderChannelSprite (events_renderChannelSprite)
// Address: 68064970
// Size: 56 bytes
// Params: int param_1, ushort * param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_renderChannelSprite(int param_1,ushort *param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = events_getScoreProperty(param_1);
  if (uVar2 < 0x1100) {
    scoreEngine_renderSpritePair(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: events_setEditProperty (FUN_680649b0)
// Address: 680649b0
// Size: 39 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_setEditProperty(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = Ordinal_73(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),(short)param_2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: events_getChannelProp1B (events_getChannelProp1B)
// Address: 680649e0
// Size: 54 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getChannelProp1B(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_18 = param_2;
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x1b,(double *)&local_1c);
  *param_3 = local_1c;
  return 0;
}



// ============================================================
// Function: events_getChannelEditMode (events_getChannelEditMode)
// Address: 68064a20
// Size: 22 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getChannelEditMode(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x1cc);
}



// ============================================================
// Function: events_setChannelEditMode (events_setChannelEditMode)
// Address: 68064a40
// Size: 25 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelEditMode(int param_1,undefined4 param_2)
{
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x1cc) = param_2;
  return 0;
}



// ============================================================
// Function: events_getChannelSelection (events_getChannelSelection)
// Address: 68064a60
// Size: 25 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getChannelSelection(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20) + 0x124);
}



// ============================================================
// Function: events_setChannelSelection (events_setChannelSelection)
// Address: 68064a80
// Size: 28 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setChannelSelection(int param_1,undefined4 param_2)
{
  *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20) + 0x124) = param_2;
  return 0;
}



// ============================================================
// Function: events_getEditRef (FUN_68064aa0)
// Address: 68064aa0
// Size: 60 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getEditRef(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = stage_checkPlugins(param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    stage_updatePluginCount(param_1,1);
    if (*(code **)(DAT_681962f8 + 0x20) != (code *)0x0) {
      uVar2 = (**(code **)(DAT_681962f8 + 0x20))();
    }
    stage_updatePluginCount(param_1,0);
  }
  return uVar2;
}



// ============================================================
// Function: events_dispatchFrameEvent (events_dispatchFrameEvent)
// Address: 68064ae0
// Size: 87 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_dispatchFrameEvent(void)

{
  int *piVar1;
  int unaff_ESI;
  int unaff_EDI;
  int local_1c [6];
  
  piVar1 = *(int **)(unaff_ESI + 0xc);
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_1c[3] = 0;
  local_1c[4] = 0;
  local_1c[5] = 0;
  if (5 < unaff_EDI) {
    return 0;
  }
  *(undefined4 *)(unaff_ESI + 0x18c) = 0;
  Ordinal_360(*(int **)(unaff_ESI + 0x20),*(undefined4 ****)(unaff_ESI + 0x28),5,(double *)local_1c)
  ;
  crt_dispatchHandler(piVar1,local_1c[0],unaff_EDI);
  return *(undefined4 *)(unaff_ESI + 0x18c);
}




// ============================================================
// Function: events_resolveScriptHandler (events_resolveScriptHandler)
// Address: 68064b40
// Size: 132 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resolveScriptHandler(int param_1,undefined4 param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x148) = param_4;
  if (((0 < (short)((uint)param_2 >> 0x10)) &&
      (iVar3 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x24),param_2,0x25,
                           (uint *)local_20), iVar3 != 0)) && (local_20[0] != (int *)0x0)) {
    cast_resolveHandler(iVar1,local_20[0],param_3);
  }
  *(undefined4 *)(param_1 + 0x148) = uVar2;
  return 0;
}



// ============================================================
// Function: sprites_handleEditCommand (FUN_68064bd0)
// Address: 68064bd0
// Size: 90 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_handleEditCommand(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = events_navigateToFrameEx(iVar1);
  iVar5 = 1;
  if (0 < iVar2) {
    do {
      uVar3 = events_navigateToFrame(*(int *)(param_1 + 0xc),(ushort)iVar5);
      if ((uVar3 != 0) && (iVar4 = cast_dispatchEvent(iVar1,uVar3,param_2), iVar4 != 0)) {
        return 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar2);
  }
  return 0;
}



// ============================================================
// Function: sprites_handleEditCommand2 (FUN_68064c30)
// Address: 68064c30
// Size: 220 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_handleEditCommand2(int *param_1,uint param_2)
{
  uint uVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24 [6];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = param_1[3];
  iVar2 = *param_1;
  local_8 = 0;
  *(int *)(iVar2 + 0x65c) = *(int *)(iVar2 + 0x65c) + 1;
  iVar4 = Ordinal_355(param_1[8],param_1[10],(short *)&local_8);
  do {
    if (iVar4 == 0) {
      return 0;
    }
    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_24[3] = 0;
    sVar3 = Ordinal_364(param_1[8],param_1[10],(short)local_8);
    Ordinal_347(*(int *)(iVar2 + 8),sVar3,7,local_24);
    if (local_24[0] != 0) {
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      Ordinal_347(*(int *)(iVar2 + 8),sVar3,4,&local_34);
      if ((local_34 != 0) &&
         (iVar4 = cast_invokeHandler(uVar1,local_34,param_2,0,local_24 + 4,(undefined4 *)0x0,&local_c),
         iVar4 != 0)) {
        return 0;
      }
    }
    iVar4 = Ordinal_355(param_1[8],param_1[10],(short *)&local_8);
  } while( true );
}



// ============================================================
// Function: events_notifyFocusChange (events_notifyFocusChange)
// Address: 68064d10
// Size: 96 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_notifyFocusChange(int *param_1)
{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x60) == 0) {
    *(undefined4 *)(*param_1 + 0x60) = 1;
    if ((int *)param_1[0x1c7] != (int *)0x0) {
      cast_wrapApiCall(param_1[3],(int *)param_1[0x1c7],0x33c);
    }
    iVar1 = param_1[0x71];
    param_1[0x71] = 1;
    sprites_handleEditCommand2(param_1,0x33c);
    param_1[0x71] = iVar1;
    *(undefined4 *)(*param_1 + 0x60) = 0;
  }
  return 0;
}



// ============================================================
// Function: events_handleIdleEvent (events_handleIdleEvent)
// Address: 68064d70
// Size: 125 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleIdleEvent(int param_1)
{
  if ((*(int *)(param_1 + 0x75c) == 0) && (*(int *)(param_1 + 0x17c) != 0)) {
    *(undefined4 *)(param_1 + 0x75c) = 1;
    sprites_setCursorVisible(param_1,1);
    if (*(int **)(param_1 + 0x71c) != (int *)0x0) {
      cast_wrapApiCall(*(undefined4 *)(param_1 + 0xc),*(int **)(param_1 + 0x71c),0x37);
    }
    if (*(int **)(param_1 + 0x71c) != (int *)0x0) {
      cast_removeInactiveTimers(*(undefined4 *)(param_1 + 0xc),*(int **)(param_1 + 0x71c));
    }
    sprites_handleEditCommand(param_1,0xd);
    scoreEngine_writePropertyBlock(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x24),0x11,0);
    *(undefined4 *)(param_1 + 0x75c) = 0;
  }
  return 0;
}



// ============================================================
// Function: events_resetFrameState (events_resetFrameState)
// Address: 68064df0
// Size: 64 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_resetFrameState(int param_1)
{
  uint uVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  Ordinal_360(*(int **)(param_1 + 0x20),*(undefined4 ****)(param_1 + 0x28),5,(double *)&local_1c);
  crt_stepScriptForced(uVar1);
  return 0;
}



// ============================================================
// Function: events_editChannelEx (FUN_68064e30)
// Address: 68064e30
// Size: 52 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int * param_4, undefined4 param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_editChannelEx(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = scoreEngine_readPropertyBlock(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x24),param_2,param_3,param_4,
                       param_5,(int *)0x0);
  if (-1 < iVar1) {
    return iVar1 + 1;
  }
  return 0;
}



// ============================================================
// Function: events_readChannelProperty (events_readChannelProperty)
// Address: 68064e70
// Size: 47 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_readChannelProperty(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = scoreEngine_readPropertyBlock(*(int *)(param_1 + 0x20),param_2,param_3,param_4,(int *)0x0,in_EAX,(int *)0x0
                      );
  if (-1 < iVar1) {
    return iVar1 + 1;
  }
  return 0;
}



// ============================================================
// Function: events_evaluateFrameScript (events_evaluateFrameScript)
// Address: 68064ea0
// Size: 130 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_evaluateFrameScript(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 local_8;
  
  in_EAX[0x7e] = 0;
  in_EAX[0x6c] = 0;
  if (*(int *)(*in_EAX + 0x660) == 0) {
    Ordinal_54(in_EAX[8],&local_8);
    Ordinal_1844(local_8);
  }
  if (in_EAX[0x65] != 0) {
    iVar1 = sprites_getChannelRef(in_EAX[3]);
    in_EAX[0x1a] = iVar1;
  }
  in_EAX[0x6d] = 0;
  iVar1 = events_dispatchFrameEvent();
  if ((iVar1 == 0) && (in_EAX[0x6d] == 0)) {
    return 1;
  }
  Ordinal_1845();
  return 0;
}



// ============================================================
// Function: events_initMouseState (events_initMouseState)
// Address: 68064f30
// Size: 64 bytes
// Params: int * param_1, undefined4 param_2, short param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_initMouseState(int *param_1,undefined4 param_2,short param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = sprites_getChannelRef(param_1[3]);
  *(int *)(*param_1 + 0x38) = iVar1;
  if (param_1[100] != 0) {
    iVar1 = sprites_getChannelRef(param_1[3]);
    param_1[0x1a] = iVar1;
  }
  *(undefined4 *)(*param_1 + 0x2c) = param_4;
  *(int *)(*param_1 + 0x30) = (int)param_3;
  return 0;
}



// ============================================================
// Function: events_clampToSpriteRect (events_clampToSpriteRect)
// Address: 68064f70
// Size: 123 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_clampToSpriteRect(int param_1,int param_2,int *param_3)
{
  int iVar1;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_8;
  
  iVar1 = events_copyCastMember(param_1,*(int *)(param_1 + 0x24),param_2,2);
  if (0 < iVar1) {
    Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x24),iVar1,0xb,(double *)&local_48);
    if (*param_3 < local_48) {
      *param_3 = local_48;
    }
    if (local_40 < *param_3) {
      *param_3 = local_40;
    }
    if (param_3[1] < local_44) {
      param_3[1] = local_44;
    }
    if (local_3c < param_3[1]) {
      param_3[1] = local_3c;
    }
  }
  return 0;
}



// ============================================================
// Function: events_findSortedSprite (events_findSortedSprite)
// Address: 68064ff0
// Size: 162 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_findSortedSprite(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  local_8 = (int *)lingo_flushSortList(*(int *)(unaff_EDI + 0x20),*(int *)(unaff_EDI + 0x28));
  if (local_8 != (int *)0x0) {
    iVar2 = Ordinal_1154(local_8);
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      while( true ) {
        local_c = *(int *)(*(int *)(*(int *)((undefined4 *)*local_8)[9] + iVar2 * 4) + 4 +
                          **(int **)*local_8) + 1;
        iVar3 = events_copyCastMember(unaff_EDI,*(int *)(unaff_EDI + 0x28),local_c,param_3);
        if ((iVar3 != 0) &&
           (sVar1 = Ordinal_383(*(int *)(unaff_EDI + 0x20),*(byte **)(unaff_EDI + 0x24),param_1,
                                param_2,local_c), sVar1 != 0)) break;
        iVar2 = iVar2 + -1;
        if (iVar2 < 0) {
          Ordinal_1163(&local_8);
          return 0;
        }
      }
    }
  }
  Ordinal_1163(&local_8);
  return local_c;
}



// ============================================================
// Function: events_getEditState (FUN_680650a0)
// Address: 680650a0
// Size: 208 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getEditState(int param_1)
{
  bool bVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_60 [16];
  uint local_20 [6];
  uint local_8;
  
  bVar1 = false;
  iVar2 = events_copyCastMember(unaff_ESI,*(int *)(unaff_ESI + 0x24),unaff_EDI,1);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = Ordinal_374(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x24),unaff_EDI,2,
                      (double *)local_60);
  if (iVar2 != 0) {
    iVar2 = Ordinal_294(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),local_60[0],9,local_20
                       );
    if ((iVar2 != 0) && (local_20[0] != 0)) {
      bVar1 = true;
    }
    iVar2 = Ordinal_374(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x24),unaff_EDI,4,
                        (double *)local_60);
    if (((iVar2 != 0) && ((char)local_60[0] == '\b')) || (bVar1)) {
      scoreEngine_setPropertyRange(*(int *)(unaff_ESI + 0x20),*(byte **)(unaff_ESI + 0x24),unaff_EDI,param_1);
      return 0;
    }
  }
  return 0;
}




