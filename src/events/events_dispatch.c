// Module: events
// Topic: Event dispatch, input processing, mouse/keyboard handling, scroll events
// Address range: 0x68065170 - 0x68066c40
// Functions (25):
//   events_findNextScoreEntry
//   events_dispatchPropertyOp
//   events_dispatchSpriteHandlers
//   events_processDispatch
//   events_dispatchSlotEvent
//   events_dispatchSpriteEvents
//   events_dispatchEvent
//   events_dispatchEventEx
//   events_handleKeyEvent
//   events_handleKeyEventWrapper
//   events_dispatchToChannel
//   events_processScrollInput
//   events_dispatchInputEvent
//   events_processMouseEvent
//   sprites_processInput
//   events_handleMouseDown
//   events_updateCursorShape
//   events_handleFrameIdle
//   events_initFrameDisplay
//   events_processFrameStep
//   events_advancePlayhead
//   events_commitMouseState
//   events_executeMovieCommand
//   events_enableKeyCapture
//   events_captureKeyPress

// ============================================================
// Function: events_findNextScoreEntry (events_findNextScoreEntry)
// Address: 68065170
// Size: 117 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_findNextScoreEntry(void)
{
  int local_14;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int *unaff_EDI;
  int local_8;
  
  iVar2 = scoreEngine_writeProperty(unaff_EDI[8],(byte *)unaff_EDI[9],unaff_EBX,&local_8);
  if ((iVar2 != 0) && (local_8 != 0)) {
    iVar1 = unaff_EDI[3];
    iVar2 = unaff_EBX + 1;
    if (iVar2 != unaff_EBX) {
      while (iVar3 = scoreEngine_writeProperty(unaff_EDI[8],(byte *)unaff_EDI[9],iVar2,&local_8), iVar3 == 0) {
        if (*(int *)(iVar1 + 0xf4) < iVar2) {
          iVar2 = 0;
        }
        iVar2 = iVar2 + 1;
        if (iVar2 == unaff_EBX) {
          return 0;
        }
      }
      scoreEngine_writeNotation(unaff_EDI,unaff_EDI[9],iVar2,local_8,iVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: events_dispatchPropertyOp (FUN_680651f0)
// Address: 680651f0
// Size: 148 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint param_4, uint * param_5, int * param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_dispatchPropertyOp(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint *param_5,
                 int *param_6,int *param_7)
{
  int *piVar1;
  int iVar2;
  undefined4 *local_20 [6];
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0xc);
  *param_7 = 0;
  if (0 < (short)((uint)param_2 >> 0x10)) {
    iVar2 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x25,
                        (uint *)local_20);
    if ((iVar2 != 0) && (local_20[0] != (undefined4 *)0x0)) {
      cast_executeHandler(piVar1,local_20[0],param_3,param_4,param_5,param_6,param_7);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_dispatchSpriteHandlers (events_dispatchSpriteHandlers)
// Address: 68065290
// Size: 576 bytes
// Params: int * param_1, byte * param_2, short param_3, uint param_4, uint param_5, uint * param_6, int * param_7, int * param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_dispatchSpriteHandlers(int *param_1,byte *param_2,short param_3,uint param_4,uint param_5,uint *param_6,
                 int *param_7,int *param_8)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  short local_74;
  short local_72;
  int local_6c;
  int local_68;
  int *local_64;
  uint *local_60;
  int *local_5c;
  undefined4 local_58;
  uint local_18;
  int local_14 [3];
  uint local_8;
  
  iVar1 = *param_1;
  local_60 = param_6;
  uVar2 = param_1[3];
  local_64 = param_7;
  *param_8 = 0;
  if (0 < param_3) {
    Ordinal_374(param_1[8],(int)param_2,(int)param_3,5,(double *)&local_58);
    local_6c = local_58;
    local_5c = (int *)Ordinal_482(param_1[8],(int)param_2);
    iVar5 = Ordinal_430(local_5c,local_6c);
    local_68 = 0;
    if (0 < iVar5) {
      do {
        Ordinal_431(local_5c,local_6c,local_68,&local_74);
        uVar6 = Ordinal_362(param_1[8],(int)param_2,(undefined4 *)&local_74);
        if ((0 < (short)((uint)uVar6 >> 0x10)) &&
           (iVar7 = events_dispatchPropertyOp((int)param_1,uVar6,param_4,param_5,local_60,local_64,param_8),
           iVar7 != 0)) goto LAB_680654b8;
        local_68 = local_68 + 1;
      } while (local_68 < iVar5);
    }
    Ordinal_374(param_1[8],(int)param_2,(int)param_3,2,(double *)&local_58);
    if ((0 < (*(unsigned short *)((char *)&local_58 + 2))) &&
       (iVar5 = events_dispatchPropertyOp((int)param_1,local_58,param_4,param_5,local_60,local_64,param_8),
       iVar5 != 0)) goto LAB_680654b8;
  }
  local_5c = (int *)Ordinal_482(param_1[8],(int)param_2);
  Ordinal_372(param_1[8],param_2,8,local_14);
  iVar5 = Ordinal_431(local_5c,local_14[0],0,&local_74);
  if ((iVar5 != 0) && (0 < local_72)) {
    uVar6 = Ordinal_362(param_1[8],(int)param_2,(undefined4 *)&local_74);
    iVar5 = events_dispatchPropertyOp((int)param_1,uVar6,param_4,param_5,local_60,local_64,param_8);
    if (iVar5 != 0) goto LAB_680654b8;
  }
  local_5c = (int *)0x0;
  iVar5 = Ordinal_355(param_1[8],param_1[10],(short *)&local_5c);
  puVar3 = local_60;
  while( true ) {
    if (iVar5 == 0) {
      return 0;
    }
    sVar4 = Ordinal_364(param_1[8],param_1[10],(short)local_5c);
    iVar5 = Ordinal_347(*(int *)(iVar1 + 8),sVar4,4,&local_18);
    if (((iVar5 != 0) && (local_18 != 0)) &&
       (iVar5 = cast_invokeHandler(uVar2,local_18,param_4,param_5,puVar3,local_64,param_8), iVar5 != 0))
    break;
    iVar5 = Ordinal_355(param_1[8],param_1[10],(short *)&local_5c);
  }
LAB_680654b8:
  return 0;
}



// ============================================================
// Function: events_processDispatch (FUN_680654d0)
// Address: 680654d0
// Size: 261 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_processDispatch(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  int local_8;
  
  iVar4 = param_1;
  uVar1 = *(undefined4 *)(param_1 + 0x148);
  piVar2 = *(int **)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 0x1b4);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x148) = param_4;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  cast_retainObject(piVar2,param_2);
  iVar5 = cast_getMemberData(piVar2,param_2);
  param_1 = 1;
  if (0 < iVar5) {
    do {
      piVar6 = cast_resolveContext(piVar2,param_2,param_1);
      if (piVar6 != (int *)0x0) {
        *(undefined4 *)(iVar4 + 0x18c) = 0;
        iVar7 = cast_checkHandlerExists(piVar2,piVar6,param_3);
        if ((iVar7 != 0) || (bVar8 = local_8 != 0, local_8 = 0, bVar8)) {
          local_8 = 1;
        }
        cast_releaseObject(piVar2,piVar6);
        if ((*(int *)(iVar4 + 0x18c) != 0) || (*(int *)(iVar4 + 0x1b4) != 0)) break;
      }
      param_1 = param_1 + 1;
    } while (param_1 <= iVar5);
  }
  cast_releaseObject(piVar2,param_2);
  *(undefined4 *)(iVar4 + 0x148) = uVar1;
  if ((*(int *)(iVar4 + 0x1b4) == 0) && (iVar3 == 0)) {
    *(undefined4 *)(iVar4 + 0x1b4) = 0;
    return local_8;
  }
  *(undefined4 *)(iVar4 + 0x1b4) = 1;
  return local_8;
}



// ============================================================
// Function: events_dispatchSlotEvent (events_dispatchSlotEvent)
// Address: 680655e0
// Size: 70 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_dispatchSlotEvent(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_8;
  
  iVar2 = Ordinal_165(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x24),&local_8);
  puVar3 = (undefined4 *)(iVar2 + unaff_EDI * 0x34);
  piVar1 = (int *)*puVar3;
  if ((puVar3[4] == 0) && (piVar1 != (int *)0x0)) {
    iVar2 = events_processDispatch(unaff_ESI,piVar1,param_1,unaff_EDI);
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: events_dispatchSpriteEvents (events_dispatchSpriteEvents)
// Address: 68065630
// Size: 46 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_dispatchSpriteEvents(int param_1)
{
  int in_EAX;
  
  if (((*(int *)(in_EAX + 0x1e0) == 0) && (0x5ff < *(uint *)(in_EAX + 500))) ||
     ((param_1 != 0xf && (param_1 != 0x10)))) {
    lingo_dispatchSpriteEvents(*(int *)(in_EAX + 0x20),*(int *)(in_EAX + 0x28),param_1);
  }
  return 0;
}



// ============================================================
// Function: events_dispatchEvent (FUN_68065660)
// Address: 68065660
// Size: 126 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_dispatchEvent(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_3 != 0) && ((param_2 == 6 || ((0xe < param_2 && (param_2 < 0x11)))))) {
    events_dispatchSpriteEvents(param_2);
  }
  if ((*(int *)(param_1 + 0x1e0) == 0) || (param_2 != 2)) {
    puVar1 = (undefined4 *)Ordinal_165(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),&param_3);
    if ((puVar1 != (undefined4 *)0x0) && (((int *)*puVar1 != (int *)0x0 && (puVar1[4] == 0)))) {
      iVar2 = events_processDispatch(param_1,(int *)*puVar1,param_2,0);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  uVar3 = sprites_handleEditCommand(param_1,param_2);
  return uVar3;
}



// ============================================================
// Function: events_dispatchEventEx (FUN_680656e0)
// Address: 680656e0
// Size: 387 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
events_dispatchEventEx(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_48;
  uint local_8;
  
  iVar2 = 0;
  bVar3 = false;
  if (0 < param_1) {
    switch(param_3) {
    case 2:
      iVar2 = 1;
      break;
    case 3:
      iVar2 = 2;
      break;
    case 6:
      iVar2 = 5;
      break;
    case 7:
      iVar2 = 6;
      break;
    case 10:
      iVar2 = 9;
      break;
    case 0xb:
      iVar2 = 10;
      break;
    case 0x1e:
      iVar2 = 0x21;
    }
    if (param_4 == 8) {
      iVar2 = 0x17;
LAB_68065777:
      Ordinal_374(*(int *)(param_2 + 0x20),*(int *)(param_2 + 0x24),param_1,0x1c,(double *)&local_48
                 );
      bVar3 = (local_48 & 0x200) != 0;
      if (((param_6 == 0) && (!bVar3)) &&
         (iVar1 = scoreEngine_readProperty(*(int *)(param_2 + 0x20),*(int *)(param_2 + 0x24),param_1,iVar2),
         iVar1 != 0)) goto LAB_680657be;
    }
    else {
      if (param_4 == 9) {
        iVar2 = 0x18;
        goto LAB_68065777;
      }
      if (param_4 == 10) {
        iVar2 = 0x19;
        goto LAB_68065777;
      }
      if (iVar2 != 0) goto LAB_68065777;
    }
    iVar1 = events_dispatchSlotEvent(param_4);
    if (iVar1 != 0) goto LAB_680657be;
    Ordinal_374(*(int *)(param_2 + 0x20),*(int *)(param_2 + 0x24),param_1,2,(double *)&local_48);
    if (((0 < (*(unsigned short *)((char *)&local_48 + 2))) &&
        (iVar1 = events_resolveScriptHandler(param_2,local_48,param_4,param_1), iVar1 != 0)) ||
       ((param_6 == 0 &&
        ((bVar3 && (iVar2 = scoreEngine_readProperty(*(int *)(param_2 + 0x20),*(int *)(param_2 + 0x24),param_1,
                                         iVar2), iVar2 != 0)))))) goto LAB_680657be;
  }
  if ((param_5 == 0) || (iVar2 = events_dispatchEvent(param_2,param_4,0), iVar2 == 0)) {
    return 0;
  }
LAB_680657be:
  return 0;
}



// ============================================================
// Function: events_handleKeyEvent (events_handleKeyEvent)
// Address: 680658b0
// Size: 52 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleKeyEvent(void)
{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x720) < 2) {
    *(int *)(unaff_ESI + 0x720) = *(int *)(unaff_ESI + 0x720) + 1;
    if (*(int *)(unaff_ESI + 0x1e0) != 0) {
      sprites_handleEditCommand(unaff_ESI,0xe);
    }
    events_dispatchEvent(unaff_ESI,0xf,1);
    *(int *)(unaff_ESI + 0x720) = *(int *)(unaff_ESI + 0x720) + -1;
  }
  return 0;
}



// ============================================================
// Function: events_handleKeyEventWrapper (events_handleKeyEventWrapper)
// Address: 680658f0
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleKeyEventWrapper(void)
{
  events_handleKeyEvent();
  return 0;
}



// ============================================================
// Function: events_dispatchToChannel (events_dispatchToChannel)
// Address: 68065910
// Size: 37 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall events_dispatchToChannel(void *this,int param_1)
{
  undefined4 uVar1;
  undefined4 in_EAX;
  int unaff_ESI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x24);
  *(undefined4 *)(unaff_ESI + 0x24) = in_EAX;
  events_dispatchEventEx(param_1,unaff_ESI,0,(int)this,0,0);
  *(undefined4 *)(unaff_ESI + 0x24) = uVar1;
  return 0;
}




// ============================================================
// Function: events_processScrollInput (events_processScrollInput)
// Address: 68065940
// Size: 380 bytes
// Return: byte *
// Calling convention: __stdcall
// ============================================================

byte * events_processScrollInput(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int local_14;
  int local_10;
  int local_c;
  byte *local_8;
  
  local_8 = (byte *)0x0;
  pbVar4 = DAT_681962f8;
  if ((*(int *)(DAT_681962f8 + 0xc) == 0) && (in_EAX[0x1d6] != 0)) {
    lingo_loadMovieData(in_EAX[8],&local_14);
    iVar2 = events_editChannelEx((int)in_EAX,local_14,local_10,(int *)&local_8,2);
    if (*(int *)(*in_EAX + 0x67c) != 0) {
      local_c = 0;
      Ordinal_54(in_EAX[8],&local_c);
      if (local_c != *(int *)((byte *)*in_EAX + 0x67c)) {
        return (byte *)*in_EAX;
      }
    }
    iVar3 = in_EAX[0x1ce];
    iVar1 = in_EAX[0x6c];
    if ((iVar2 != iVar3) || (local_8 != (byte *)in_EAX[0x1cf])) {
      if (0 < iVar3) {
        if ((((local_8 == (byte *)0x0) || ((byte *)in_EAX[0x1cf] == local_8)) ||
            (iVar3 = events_editChannelEx((int)in_EAX,in_EAX[0x1d0],in_EAX[0x1d1],&local_c,2),
            iVar3 == in_EAX[0x1ce])) &&
           ((pbVar4 = (byte *)events_dispatchToChannel((void *)0x9,iVar3), iVar1 == 0 && (in_EAX[0x6c] != 0))))
        {
          return pbVar4;
        }
        in_EAX[0x1ce] = 0;
      }
      if (iVar2 < 1) {
        return local_8;
      }
      pbVar4 = (byte *)events_dispatchToChannel((void *)0x8,iVar2);
      if ((iVar1 == 0) && (in_EAX[0x6c] != 0)) {
        return pbVar4;
      }
      in_EAX[0x1d1] = local_10;
      in_EAX[0x1ce] = iVar2;
      in_EAX[0x1d0] = local_14;
      in_EAX[0x1cf] = (int)local_8;
    }
    pbVar4 = local_8;
    if ((0 < iVar2) &&
       (pbVar4 = (byte *)Ordinal_58(in_EAX[8],local_8), (byte *)in_EAX[0x1d2] != pbVar4)) {
      in_EAX[0x1d2] = (int)pbVar4;
      in_EAX[0x1d1] = local_10;
      in_EAX[0x1d0] = local_14;
      pbVar4 = (byte *)events_dispatchToChannel((void *)0xa,iVar2);
    }
  }
  return pbVar4;
}



// ============================================================
// Function: events_dispatchInputEvent (events_dispatchInputEvent)
// Address: 68065ac0
// Size: 423 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall events_dispatchInputEvent(void *this,undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  uint local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  local_80 = param_1;
  *(undefined4 *)((int)this + 0x74) = 0xffffffff;
  iVar1 = events_getEditState(0);
  if (iVar1 != 0) {
    Ordinal_104(*(int *)((int)this + 0x20),0x1000);
  }
  if (*(int *)((int)this + 0x30) != 2) {
    iVar1 = scoreEngine_writePropertyData(*(int *)((int)this + 0x20),*(byte **)((int)this + 0x24),
                         *(undefined4 *)((int)this + 0x38),&local_7c,&local_84);
    if (iVar1 != 0) {
      Ordinal_294(*(int *)((int)this + 0x20),*(int *)((int)this + 0x24),local_7c,0x78,local_38);
      if ((local_38[0] == 0) || (local_20[0] = 0, *(int *)((int)this + 0x30) == 1)) {
        local_20[0] = 1;
      }
      Ordinal_293(*(int *)((int)this + 0x20),*(int *)((int)this + 0x24),local_7c,0x78,local_20);
      Ordinal_104(*(int *)((int)this + 0x20),0x1000);
    }
  }
  iVar1 = events_dispatchFrameEvent();
  *(int *)((int)this + 0x1f8) = iVar1;
  if (*(int *)((int)this + 0x1b0) != 0) goto LAB_68065c4b;
  if (iVar1 == 0) {
    if (unaff_EBX == 2) {
      uVar2 = 3;
    }
    else {
      if (unaff_EBX != 0x19) goto LAB_68065bcb;
      uVar2 = 7;
    }
    uVar2 = scoreEngine_readProperty(*(int *)((int)this + 0x20),*(int *)((int)this + 0x24),
                         *(int *)((int)this + 0x38),uVar2);
    *(undefined4 *)((int)this + 0x1f8) = uVar2;
  }
LAB_68065bcb:
  if (*(int *)((int)this + 0x1f8) == 0) {
    iVar1 = events_dispatchSlotEvent(unaff_EBX);
    *(int *)((int)this + 0x1f8) = iVar1;
    if ((*(int *)((int)this + 0x1b0) == 0) && (iVar1 == 0)) {
      iVar1 = Ordinal_374(*(int *)((int)this + 0x20),*(int *)((int)this + 0x24),
                          *(int *)((int)this + 0x38),2,(double *)&local_78);
      if ((iVar1 != 0) && (0 < (*(unsigned short *)((char *)&local_78 + 2)))) {
        uVar2 = events_resolveScriptHandler((int)this,local_78,unaff_EBX,*(undefined4 *)((int)this + 0x38));
        *(undefined4 *)((int)this + 0x1f8) = uVar2;
        if (*(int *)((int)this + 0x1b0) != 0) goto LAB_68065c4b;
      }
      if ((*(int *)((int)this + 0x1f8) == 0) && (*(int *)((int)this + 0x1e0) == 0)) {
        events_dispatchEvent((int)this,unaff_EBX,0);
      }
    }
  }
LAB_68065c4b:
  *(undefined4 *)((int)this + 0x1f8) = 1;
  return 0;
}



// ============================================================
// Function: events_processMouseEvent (events_processMouseEvent)
// Address: 68065c70
// Size: 423 bytes
// Params: void * param_1, undefined4 * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_processMouseEvent(void *param_1,undefined4 *param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_1c [2];
  int local_14;
  uint local_8;
  
  if (DAT_681962e4 == 1) goto LAB_68065e05;
  DAT_681962e4 = 1;
  Ordinal_1845();
  if (*(int *)((int)param_1 + 0x78) == 0) {
LAB_68065cbe:
    if (*(int *)((int)param_1 + 0x170) != 0) {
      if ((*(int *)((int)param_1 + 0x16c) != 0) &&
         (*(undefined4 *)((int)param_1 + 0x16c) = 0,
         *(int *)(*(int *)((int)param_1 + 0x2c) + 0x24) == 0)) {
        Ordinal_104(*(int *)((int)param_1 + 0x20),0x1000);
      }
      if (*(int *)(*(int *)((int)param_1 + 0x2c) + 0x24) == 0) {
        if (*(int *)((int)param_1 + 0x148) != *(int *)((int)param_1 + 0x38)) {
          if (param_4 == 2) {
            uVar2 = 4;
LAB_68065d1e:
            uVar2 = scoreEngine_readProperty(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x24),
                                 *(int *)((int)param_1 + 0x38),uVar2);
            *(undefined4 *)((int)param_1 + 0x1f8) = uVar2;
          }
          else if (param_4 == 0x19) {
            uVar2 = 8;
            goto LAB_68065d1e;
          }
          if (*(int *)((int)param_1 + 0x1f8) == 0) {
            events_dispatchEventEx(*(int *)((int)param_1 + 0x38),(int)param_1,*param_2,0x1a,0,0);
          }
        }
        iVar1 = *(int *)((int)param_1 + 100);
        if (((iVar1 == 0) && (iVar3 = *(int *)((int)param_1 + 0x148), iVar3 != 0)) ||
           ((iVar1 == 1 &&
            (iVar3 = *(int *)((int)param_1 + 0x148), iVar3 == *(int *)((int)param_1 + 0x38))))) {
          if (iVar1 == 0) {
            *(int *)((int)param_1 + 0x38) = iVar3;
          }
          events_dispatchInputEvent(param_1,param_2);
        }
      }
      *(undefined4 *)((int)param_1 + 0x148) = 0;
      *(undefined4 *)((int)param_1 + 0x170) = 0;
    }
  }
  else {
    iVar1 = sprites_processScrollInput((int)param_1,param_2);
    if (iVar1 == 0) goto LAB_68065cbe;
  }
  if (*(int *)(*(int *)((int)param_1 + 0x2c) + 0x24) == 0) {
    if (*(int *)((int)param_1 + 0x1f8) == 0) {
      iVar1 = events_dispatchFrameEvent();
      *(int *)((int)param_1 + 0x1f8) = iVar1;
      if ((iVar1 == 0) && (*(int *)((int)param_1 + 0x1e0) == 0)) {
        uVar2 = events_dispatchEvent((int)param_1,param_4,0);
        *(undefined4 *)((int)param_1 + 0x1f8) = uVar2;
      }
    }
    lingo_setPlaybackData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x24),local_1c);
    *(uint *)((int)param_1 + 0x184) = (uint)(-1 < local_14);
    if (-1 < local_14 == 0) {
      *(undefined4 *)((int)param_1 + 0x16c) = 0;
    }
  }
  *(undefined4 *)((int)param_1 + 0x24) = *(undefined4 *)((int)param_1 + 0x28);
  *(undefined4 *)(param_3 + 0x3c) = 0;
  DAT_681962e4 = 0;
LAB_68065e05:
  return 0;
}



// ============================================================
// Function: sprites_processInput (FUN_68065e20)
// Address: 68065e20
// Size: 105 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_processInput(int param_1)

{
  int iVar1;
  
  if ((DAT_681962d8 != 0) && (DAT_681962dc == 0)) {
    return 1;
  }
  iVar1 = events_dispatchFrameEvent();
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x78) != 0) {
      iVar1 = events_dispatchEventEx(*(int *)(param_1 + 0x7c),param_1,0xb,4,1,0);
      return iVar1;
    }
    iVar1 = events_dispatchEventEx(0,param_1,0xb,4,1,0);
  }
  return iVar1;
}



// ============================================================
// Function: events_handleMouseDown (events_handleMouseDown)
// Address: 68065e90
// Size: 373 bytes
// Params: int * param_1, undefined4 param_2, short param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_handleMouseDown(int *param_1,undefined4 param_2,short param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int local_20 [7];
  
  piVar1 = (int *)param_1[3];
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[6] = 0;
  if ((DAT_681962d8 == 0) || (DAT_681962dc != 0)) {
    events_initMouseState(param_1,param_2,param_3,param_4);
    param_1[0x67] = 0;
    param_1[99] = 0;
    Ordinal_360((int *)param_1[8],(undefined4 ***)param_1[10],5,(double *)local_20);
    iVar2 = crt_dispatchHandler(piVar1,local_20[0],3);
    if (param_1[99] != 0) {
      param_1[0x67] = 1;
    }
    uVar3 = (uint)(param_1[99] != 0);
    if (param_1[0x67] == 0) {
      if ((param_1[0x1e] == 3) && (*(int *)(*param_1 + 0x30) == 0x30)) {
        scoreEngine_writeProperty(param_1[8],(byte *)param_1[9],param_1[0x1f],local_20 + 6);
      }
      if ((local_20[6] == 0) && (param_1[0x1e] != 0)) {
        uVar3 = events_dispatchEventEx(param_1[0x1f],(int)param_1,10,3,0,DAT_681962dc);
        param_1[0x67] = uVar3;
      }
      if (param_1[0x67] == 0) {
        if ((param_1[0x1e] != 0) && (DAT_681962dc == 0)) {
          if (*(int *)(*param_1 + 0x30) == 0x30) {
            events_findNextScoreEntry();
            uVar3 = 1;
          }
          else {
            uVar3 = sprites_processScrollInput((int)param_1,param_2);
          }
          param_1[0x67] = 1;
        }
        if (param_1[0x67] == 0) {
          uVar3 = events_dispatchEvent((int)param_1,3,0);
          param_1[0x67] = uVar3;
        }
      }
    }
    if ((uVar3 == 0) && (iVar2 == 0)) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: events_updateCursorShape (events_updateCursorShape)
// Address: 68066010
// Size: 309 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_updateCursorShape(int *param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_8;
  
  iVar1 = Ordinal_165(param_1[8],param_1[10],(undefined4 *)0x0);
  if (iVar1 == 0) goto LAB_68066133;
  piVar3 = (int *)(iVar1 + 0x20);
  if (param_1[0x6b] != 0) {
    lingo_loadMovieData(param_1[8],&local_20);
    iVar2 = events_findSortedSprite(local_20,local_1c,3);
    if (iVar2 != 0) {
      piVar3 = (int *)(iVar2 * 0x34 + 0x20 + iVar1);
    }
  }
  if (param_1[0x7a] == *piVar3) {
    if (param_1[0x7a] == 3) {
      if ((param_1[0x7b] == piVar3[1]) && (param_1[0x7c] == piVar3[2])) goto LAB_68066133;
    }
    else if (param_1[0x7b] == piVar3[1]) goto LAB_68066133;
  }
  if (*(int *)(*param_1 + 0x648) != 0) {
    lingo_getMiscState(*(int *)(*param_1 + 0x648));
  }
  param_1[0x7a] = *piVar3;
  param_1[0x7b] = piVar3[1];
  param_1[0x7c] = piVar3[2];
  lingo_loadMovieData(param_1[8],&local_20);
  Ordinal_54(param_1[8],&local_24);
  Ordinal_1833(local_24,&local_18);
  Ordinal_1064(&local_18,-local_18,-local_14);
  iVar1 = Ordinal_1070(&local_18,&local_20);
  if (iVar1 != 0) {
    Ordinal_215(param_1[8],param_1 + 0x7a,0,1);
  }
LAB_68066133:
  return 0;
}



// ============================================================
// Function: events_handleFrameIdle (events_handleFrameIdle)
// Address: 68066150
// Size: 114 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_handleFrameIdle(void)
{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  int local_1c [6];
  
  piVar1 = *(int **)(unaff_ESI + 0xc);
  iVar2 = sprites_getChannelRef((int)piVar1);
  if (*(int *)(unaff_ESI + 0x70) + *(int *)(unaff_ESI + 0x68) < iVar2) {
    *(int *)(unaff_ESI + 0x68) = iVar2;
    local_1c[1] = 0;
    local_1c[2] = 0;
    local_1c[3] = 0;
    local_1c[4] = 0;
    local_1c[5] = 0;
    *(undefined4 *)(unaff_ESI + 0x4c) = 0;
    local_1c[0] = 0;
    Ordinal_360(*(int **)(unaff_ESI + 0x20),*(undefined4 ****)(unaff_ESI + 0x28),5,
                (double *)local_1c);
    crt_dispatchHandler(piVar1,local_1c[0],5);
    events_dispatchEvent(unaff_ESI,5,0);
    iVar2 = sprites_getChannelRef(*(int *)(unaff_ESI + 0xc));
    *(int *)(unaff_ESI + 0x68) = iVar2;
  }
  return 0;
}



// ============================================================
// Function: events_initFrameDisplay (events_initFrameDisplay)
// Address: 680661d0
// Size: 70 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_initFrameDisplay(int param_1)
{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[0x6a] == 0) {
    if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(*unaff_ESI + 0x50) == 0)) {
      iVar1 = events_checkStageActive(*unaff_ESI);
      if ((iVar1 == 0) && ((*(byte *)(*(int *)(unaff_ESI[0xb] + 8) + 0x1c) & 8) == 0))
      goto LAB_6806620f;
    }
    Ordinal_1764(1);
    unaff_ESI[0x6a] = 1;
    return 0;
  }
LAB_6806620f:
  events_updateCursorShape(unaff_ESI);
  return 0;
}




// ============================================================
// Function: events_processFrameStep (events_processFrameStep)
// Address: 68066220
// Size: 170 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_processFrameStep(int *param_1)
{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *local_8;
  
  param_1[0x6c] = 0;
  local_8 = param_1;
  events_initFrameDisplay(in_EAX);
  param_1[0x61] = (uint)(-1 < *(int *)(in_EAX + 8));
  if (((param_1[0x1d5] != 0) && (param_1[0x1e] == 0)) && (-1 < *(int *)(in_EAX + 0xc))) {
    iVar2 = *(int *)(in_EAX + 0xc) + 1;
    if (param_1[0x1f] != 0) {
      iVar1 = scoreEngine_writeProperty(param_1[8],(byte *)param_1[9],param_1[0x1f],&local_8);
      if (iVar1 != 0) {
        iVar2 = param_1[0x1f];
      }
    }
    iVar1 = scoreEngine_writeProperty(param_1[8],(byte *)param_1[10],iVar2,&local_8);
    scoreEngine_writeNotation(param_1,param_1[10],iVar2,(int)local_8,iVar1);
  }
  if ((int *)param_1[0x1c7] != (int *)0x0) {
    cast_wrapApiCall(param_1[3],(int *)param_1[0x1c7],0x6c);
  }
  events_dispatchEvent((int)param_1,0x10,1);
  return 0;
}



// ============================================================
// Function: events_advancePlayhead (events_advancePlayhead)
// Address: 680662d0
// Size: 207 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_advancePlayhead(int *param_1)
{
  short sVar1;
  int iVar2;
  undefined4 local_1c [5];
  uint local_8;
  
  iVar2 = param_1[0x18];
  sVar1 = Ordinal_58(param_1[8],(byte *)param_1[10]);
  if (iVar2 == sVar1) {
    return 0;
  }
  param_1[0x75] = 0;
  param_1[0x6d] = 0;
  if (iVar2 == -1) {
    param_1[0x18] = -2;
  }
  else {
    lingo_setPlaybackData(param_1[8],(byte *)param_1[10],local_1c);
    param_1[0x77] = 1;
    events_processFrameStep(param_1);
    param_1[0x77] = 0;
  }
  if (param_1[0x6d] == 0) {
    iVar2 = Ordinal_58(param_1[8],(byte *)param_1[10]);
    events_removeOutOfRangeSlots((int)param_1,param_1[10],iVar2 + 1);
  }
  else {
    param_1[0x75] = 1;
  }
  return 0;
}



// ============================================================
// Function: events_commitMouseState (events_commitMouseState)
// Address: 680663a0
// Size: 88 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall events_commitMouseState(undefined4 *param_1)
{
  int iVar1;
  void *unaff_EBX;
  undefined4 *puVar2;
  undefined4 local_30 [10];
  uint local_8;
  
  if (param_1 == (undefined4 *)0x0) {
    Ordinal_1130(local_30,0x28);
  }
  else {
    puVar2 = local_30;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_1;
      param_1 = param_1 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  local_30[0] = 1;
  events_processMouseEvent(unaff_EBX,local_30,(int)unaff_EBX,*(int *)((int)unaff_EBX + 0x750));
  return 0;
}



// ============================================================
// Function: events_executeMovieCommand (events_executeMovieCommand)
// Address: 68066400
// Size: 1974 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_executeMovieCommand(int *param_1,int *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_98;
  int local_94;
  int *local_90;
  int *local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  byte *local_74;
  undefined8 local_70;
  int local_30 [4];
  uint local_20;
  undefined4 local_1c [2];
  int local_14;
  uint local_8;
  
  local_74 = (byte *)*param_1;
  local_84 = param_2[3];
  local_7c = param_3;
  iVar2 = param_2[2];
  local_8c = param_1;
  local_90 = param_2;
  local_98 = 0;
  local_88 = iVar2;
  switch(*param_2) {
  case 1:
  case 5:
    param_1[0x10] = param_1[0x11];
    if ((*param_2 == 5) ||
       (((*(int *)(local_74 + 0x650) != 0 && (*param_2 == 1)) && ((*(byte *)(param_2 + 5) & 4) != 0)
        ))) {
      local_78 = 0x19;
    }
    else {
      local_78 = 2;
    }
    if (*(int *)(param_1[0xb] + 0x24) == 0) {
      piVar3 = local_30;
      for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar3 = *param_2;
        param_2 = param_2 + 1;
        piVar3 = piVar3 + 1;
      }
      local_30[0] = 9;
      events_executeMovieCommand(param_1,local_30,param_3);
    }
    events_processMouseEvent(param_1,local_90,local_7c,local_78);
    break;
  case 2:
  case 3:
  case 6:
  case 7:
    param_1[0x1d5] = 1;
    iVar2 = *param_2;
    if (((iVar2 == 6) || (iVar2 == 7)) ||
       ((*(int *)(local_74 + 0x650) != 0 &&
        (((iVar2 == 2 && ((*(byte *)(param_2 + 5) & 4) != 0)) ||
         ((*(int *)(local_74 + 0x650) != 0 && ((iVar2 == 3 && ((*(byte *)(param_2 + 5) & 4) != 0))))
         )))))) {
      local_78 = 0x18;
      param_1[0x1d4] = 0x19;
    }
    else {
      local_78 = 1;
      param_1[0x1d4] = 2;
    }
    if (param_1[0x5c] != 0) break;
    iVar2 = sprites_getChannelRef(param_1[3]);
    *(int *)(local_74 + 0x34) = iVar2;
    piVar3 = param_1 + 0xf;
    param_1[0x59] = local_88;
    param_1[0x5a] = local_84;
    local_94 = events_editChannelEx((int)param_1,local_88,local_84,piVar3,1);
    local_74 = (byte *)*piVar3;
    param_1[0xe] = local_94;
    local_7c = 0;
    if (local_94 == 0) {
      local_74 = (byte *)param_1[10];
      local_94 = events_readChannelProperty((int)param_1,local_74,local_88,local_84);
    }
    else {
      do {
        iVar2 = scoreEngine_resolvePropertyName(param_1[8],(int *)&local_74,&local_94);
      } while (iVar2 != 0);
    }
    Ordinal_208(param_1[8],local_74,local_94,(undefined4 *)0x0,&local_7c);
    if ((local_7c == 2) || (local_7c == 9)) {
      iVar2 = param_1[0xe];
      iVar1 = local_94;
      local_7c = iVar2;
      if (iVar2 == 0) goto LAB_680665a7;
      param_1[0x10] = local_94;
    }
    else {
      iVar1 = param_1[0xe];
      local_7c = param_1[0xe];
LAB_680665a7:
      param_1[0x10] = iVar1;
      iVar2 = iVar1;
    }
    iVar1 = *piVar3;
    param_1[0x11] = iVar2;
    if (iVar1 != 0) {
      local_74 = (byte *)param_1[0x1d4];
      param_1[0xe] = 0;
      param_1 = (int *)lingo_getLifecycleRef(iVar1);
      param_1[9] = iVar1;
      param_1[0x1d4] = (int)local_74;
      local_8c = param_1;
      iVar2 = scoreEngine_accessProperty(param_1[8],iVar1);
      param_1[10] = iVar2;
      param_1[0xe] = local_7c;
    }
    if ((param_1[0xe] == 0) && (param_1[0x70] != 0)) {
      Ordinal_1781(1);
    }
    iVar2 = events_evaluateFrameScript();
    param_1[0x5c] = iVar2;
    if (iVar2 != 0) {
      if (param_1[0xe] == 0) {
        param_1[0x5c] = 0;
        events_dispatchEvent((int)param_1,local_78,0);
      }
      else {
        events_dispatchEventEx(param_1[0xe],(int)param_1,*param_2,local_78,1,0);
        if (param_1[0x6c] != 0) {
          param_1[0x5c] = 0;
          return 0;
        }
        if (param_1[0x6d] != 0) {
          iVar2 = events_editChannelEx((int)param_1,local_88,local_84,(int *)0x0,1);
          param_1[0xe] = iVar2;
        }
        lingo_setPlaybackData(param_1[8],(byte *)param_1[9],local_1c);
        param_1[0x61] = (uint)(-1 < local_14);
        if ((-1 < local_14 != 0) &&
           (iVar2 = scoreEngine_resolvePropertyId(param_1[8],(byte *)param_1[9]), iVar2 != 0)) {
          if (param_1[0x1e] == 3) {
            Ordinal_374(param_1[8],param_1[9],param_1[0xe],2,(double *)&local_70);
            Ordinal_294(param_1[8],param_1[9],(int)local_70,0x34,&local_20);
            if ((local_20 == 0x36c) || (local_20 == 0x131)) {
              param_1[0x1e] = 0;
            }
          }
          if (((param_1[0x1e] == 0) || (param_1[0x1f] != param_1[0xe])) ||
             (param_1[0x20] != param_1[9])) {
            param_1[0x52] = param_1[0xe];
            param_1[0x5b] = 1;
            iVar2 = events_copyCastMember((int)param_1,param_1[9],param_1[0xe],2);
            param_1[0x53] = -1;
            param_1[0x54] = -1;
            param_1[0x55] = local_88;
            param_1[0x5d] = (uint)(0 < iVar2);
            param_1[0x56] = local_84;
            Ordinal_374(param_1[8],param_1[9],param_1[0xe],0xe,(double *)&local_70);
            Ordinal_374(param_1[8],param_1[9],param_1[0xe],0xf,(double *)&local_70);
            param_1[0x57] = (int)local_70;
            param_1[0x58] = (*(unsigned int *)((char *)&local_70 + 4));
            return 0;
          }
        }
        param_1[0x5e] = 0;
        iVar2 = events_copyCastMember((int)param_1,param_1[10],param_1[0xe],1);
        piVar3 = local_8c;
        if (iVar2 != 0) {
          if (local_78 == 1) {
            events_dispatchInputEvent(local_8c,param_2);
            piVar3[0x52] = 0;
            piVar3[0x5c] = 0;
            return 0;
          }
          events_dispatchInputEvent(local_8c,param_2);
          local_8c[0x52] = 0;
          local_8c[0x5c] = 0;
          return 0;
        }
        if (param_1[0x19] == 1) {
          param_1[0x5e] = 1;
        }
        iVar2 = scoreEngine_writeProperty(param_1[8],(byte *)param_1[9],param_1[0xe],&local_98);
        if ((iVar2 == 0) && (iVar2 = events_getEditState(1), param_2 = local_90, iVar2 != 0)) {
          Ordinal_104(param_1[8],0x1000);
          param_2 = local_90;
        }
        param_1[0x1d] = param_1[0xe];
        param_1[0x52] = param_1[0xe];
        if ((local_78 == 1) && (iVar2 = cast_waitForSync(), iVar2 == 0)) {
          events_commitMouseState(param_2);
          param_1 = local_8c;
          param_2 = local_90;
        }
      }
      iVar2 = scoreEngine_writeProperty(param_1[8],(byte *)param_1[9],param_1[0xe],&local_98);
      if (iVar2 != 0) {
        scoreEngine_writeNotation(param_1,param_1[9],param_1[0xe],0,iVar2);
        sprites_processScrollInput((int)param_1,param_2);
        return 0;
      }
    }
    break;
  case 9:
    if ((((param_1[0x1e] != 0) && (param_1[0x5b] == 0)) &&
        ((iVar1 = sprites_processScrollInput((int)param_1,param_2), iVar1 != 0 || (param_1[0x1f] == param_1[0xe]))
        )) || (iVar1 = local_84, param_1[0x5c] == 0)) break;
    if (param_1[0x5b] != 0) {
      if ((iVar2 != param_1[0x53]) || (local_84 != param_1[0x54])) {
        local_80 = iVar2 - param_1[0x55];
        local_7c = local_84 - param_1[0x56];
        stage_offsetSpriteRects((int)param_1,&local_80);
        (*(unsigned int *)((char *)&local_70 + 0)) = param_1[0x57] + local_80;
        (*(unsigned int *)((char *)&local_70 + 4)) = param_1[0x58] + local_7c;
        if (param_1[0x5d] != 0) {
          events_clampToSpriteRect((int)param_1,param_1[0xe],(int *)&local_70);
        }
        Ordinal_373(param_1[8],param_1[9],param_1[0xe],0xe,(double *)&local_70,0);
        Ordinal_373(param_1[8],param_1[9],param_1[0xe],0xf,(double *)&local_70,0);
        param_1[0x53] = iVar2;
        param_1[0x54] = iVar1;
      }
      Ordinal_104(param_1[8],0x1000);
      return 0;
    }
    local_74 = (byte *)events_editChannelEx((int)param_1,iVar2,local_84,(int *)0x0,1);
    if (param_1[0x19] == 0) {
      if (local_74 != (byte *)param_1[0x52]) {
        local_7c = events_getEditState(0);
        iVar2 = events_getEditState(1);
        if (iVar2 != 0 || local_7c != 0) {
          Ordinal_104(param_1[8],0x1000);
        }
        param_1[0x1d] = (int)local_74;
        param_1[0x52] = (int)local_74;
        return 0;
      }
      break;
    }
    if ((param_1[0x19] != 1) || (local_74 == (byte *)param_1[0x52])) break;
    if (local_74 == (byte *)param_1[0xe]) {
      if (param_1[0x5e] != 0) {
        if (local_74 == (byte *)param_1[0xe]) goto LAB_68066b1a;
        goto LAB_68066ae5;
      }
      iVar2 = events_getEditState(1);
      param_1[0x5e] = 1;
      param_1[0x1d] = param_1[0xe];
    }
    else {
LAB_68066ae5:
      if (param_1[0x5e] == 0) goto LAB_68066b1a;
      iVar2 = events_getEditState(0);
      param_1[0x5e] = 0;
      param_1[0x1d] = -1;
    }
    if (iVar2 != 0) {
      Ordinal_104(param_1[8],0x1000);
    }
LAB_68066b1a:
    param_1[0x52] = (int)local_74;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: events_enableKeyCapture (events_enableKeyCapture)
// Address: 68066be0
// Size: 96 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_enableKeyCapture(void)
{
  int unaff_ESI;
  undefined4 local_30 [6];
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  Ordinal_1130(local_30,0x28);
  local_30[0] = 0xb;
  local_18 = 0x7f;
  local_14 = 0;
  local_10 = 0;
  DAT_681962dc = 1;
  sprites_processInput(unaff_ESI);
  DAT_681962dc = 0;
  return 0;
}



// ============================================================
// Function: events_captureKeyPress (events_captureKeyPress)
// Address: 68066c40
// Size: 105 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_captureKeyPress(void)
{
  int unaff_ESI;
  int *unaff_EDI;
  bool bVar1;
  undefined4 local_30 [6];
  undefined1 local_18;
  int local_14;
  uint local_10;
  uint local_8;
  
  Ordinal_1130(local_30,0x28);
  local_30[0] = 0xb;
  local_18 = 0x7f;
  bVar1 = unaff_ESI != 0;
  if (!bVar1) {
    unaff_ESI = 0;
  }
  local_10 = (uint)bVar1;
  DAT_681962dc = 1;
  local_14 = unaff_ESI;
  events_handleMouseDown(unaff_EDI,local_30,0x7f,unaff_ESI);
  DAT_681962dc = 0;
  return 0;
}




