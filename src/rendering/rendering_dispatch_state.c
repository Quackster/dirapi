// Module: rendering
// Topic: Dispatch, state flags, member metadata, and cast library lookups
// Address range: 0x680c2C70 - 0x680c3D50
// Functions (43):
//   rendering_fetchChannelProperty (FUN_680c2c70)
//   rendering_getDispatchProperty
//   rendering_getTimestamp (FUN_680c2d30)
//   rendering_initState (FUN_680c2db0)
//   rendering_resolveDispatchFlags (FUN_680c2ea0)
//   rendering_getDispatchFlags
//   rendering_formatMemberDescription (FUN_680c2ef0)
//   rendering_writeStateData
//   rendering_isStateValid (FUN_680c2fc0)
//   rendering_validateState
//   rendering_getStateCount
//   rendering_setStateIndex
//   rendering_resolveStateMember (FUN_680c3080)
//   rendering_getStateFlags
//   rendering_getRawStateFlags
//   rendering_setRawStateFlags (FUN_680c3160)
//   rendering_setStateFlag
//   rendering_toggleStateFlag
//   rendering_clearStateFlag
//   rendering_getFrameCount
//   rendering_getStatePair
//   rendering_dispatchUpdate
//   rendering_getDispatchMode
//   rendering_openMediaStream (FUN_680c3600)
//   rendering_createDispatchEntry
//   rendering_getDispatchEntry
//   rendering_getDispatchCount
//   rendering_updateDispatchScore (FUN_680c3710)
//   rendering_initStateFromProperty (FUN_680c3750)
//   rendering_updateStateFromProperty (FUN_680c37d0)
//   rendering_addDispatchMapping (FUN_680c3870)
//   rendering_findSystemCastLib (FUN_680c38d0)
//   rendering_getDispatchInfo
//   rendering_getDispatchData
//   rendering_getDispatchRef
//   rendering_setDispatchRef
//   rendering_getDispatchSize
//   rendering_getDispatchDataRef
//   rendering_isSpriteEmpty (FUN_680c3b90)
//   rendering_resolveStateEx
//   rendering_resolveState (rendering_resolveState)
//   rendering_getDispatchByChannel
//   rendering_getDispatchMode

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c2c70 - 0x680c3140
// Functions (15):
//   rendering_fetchChannelProperty (FUN_680c2c70)
//   rendering_getDispatchProperty
//   rendering_getTimestamp (FUN_680c2d30)
//   rendering_initState (FUN_680c2db0)
//   rendering_resolveDispatchFlags (FUN_680c2ea0)
//   rendering_getDispatchFlags
//   rendering_formatMemberDescription (FUN_680c2ef0)
//   rendering_writeStateData
//   rendering_isStateValid (FUN_680c2fc0)
//   rendering_validateState
//   rendering_getStateCount
//   rendering_setStateIndex
//   rendering_resolveStateMember (FUN_680c3080)
//   rendering_getStateFlags
//   rendering_getRawStateFlags

// ============================================================
// Function: rendering_fetchChannelProperty (FUN_680c2c70)
// Address: 680c2c70
// Size: 96 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_fetchChannelProperty(void)

{
  int local_18;
  undefined4 uVar1;
  int iVar2;
  byte unaff_BL;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((unaff_BL & 7) != 0) {
    if ((unaff_BL & 2) == 0) {
      uVar1 = 0xd;
      if ((unaff_BL & 1) == 0) {
        uVar1 = local_8;
      }
    }
    else {
      uVar1 = 0xc;
    }
    local_c = *(undefined4 *)(unaff_ESI + 4);
    iVar2 = rendering_getChannelProperty(unaff_EDI,uVar1,&local_c);
    if (iVar2 == 0) {
      return 0;
    }
    if ((unaff_BL & 4) != 0) {
      *(int *)(unaff_ESI + 0x40) = *(int *)(unaff_ESI + 0x40) + 1;
      iVar2 = rendering_getChannelProperty(unaff_EDI,0xe,&local_c);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ============================================================
// Function: rendering_getDispatchProperty (FUN_680c2cd0)
// Address: 680c2cd0
// Size: 84 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchProperty(void)
{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  int local_c [2];
  
  iVar1 = rendering_getChannelSprite(*unaff_ESI,(short)unaff_ESI[1]);
  if ((iVar1 != 0) && (*(undefined4 *)(iVar1 + 0x18) = 1, *(int *)(iVar1 + 0x14) != 0)) {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x20) + 0x458) = 1;
  }
  local_c[0] = unaff_ESI[1];
  iVar1 = rendering_getChannelProperty(unaff_EDI,0xc,local_c);
  if (iVar1 != 0) {
    rendering_getChannelProperty(unaff_EDI,0xd,local_c);
  }
  return 0;
}



// ============================================================
// Function: rendering_getTimestamp (FUN_680c2d30)
// Address: 680c2d30
// Size: 116 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getTimestamp(void)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  undefined1 local_24 [4];
  uint local_20;
  int local_1c;
  undefined1 local_18 [10];
  short local_e;
  short local_c;
  uint local_8;
  
  _time64((__time64_t *)&local_20);
  ftime64(local_18);
  uVar2 = local_c * 0xe10;
  uVar1 = local_e * 0x3c;
  uVar3 = uVar2 + local_e * -0x3c;
  bVar4 = CARRY4(local_20,uVar3);
  local_20 = local_20 + uVar3;
  local_1c = local_1c + ((((int)uVar2 >> 0x1f) - ((int)uVar1 >> 0x1f)) - (uint)(uVar2 < uVar1)) +
             (uint)bVar4;
  xtra_skipBytes(local_24);
  return 0;
}



// ============================================================
// Function: rendering_initState (FUN_680c2db0)
// Address: 680c2db0
// Size: 172 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_initState(int *param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  
  iVar1 = *param_1;
  iVar2 = 0;
  if (iVar1 != 0) {
    this = (void *)(*(int *)(iVar1 + 8) + -1);
    switch ((int)(size_t)this) { /* FIXUP(C2050): cast non-integral switch to int */
    case (void *)0x0:
      iVar2 = rendering_dispatchMemberProperty(param_1);
      break;
    case (void *)0x1:
      iVar2 = display_dispatchSpriteMessage(param_1);
      break;
    case (void *)0x2:
    case (void *)0x6:
      iVar2 = bitmap_dispatchRtfEvent(this,param_1);
      break;
    case (void *)0x3:
      iVar2 = display_dispatchPaletteHandler(param_1);
      break;
    case (void *)0x4:
      iVar2 = display_dispatchPictureHandler(param_1);
      break;
    case (void *)0x5:
      iVar2 = display_dispatchSoundHandler(param_1);
      break;
    case (void *)0x7:
      iVar2 = bitmap_dispatchSpriteMsg(this,param_1);
      break;
    case (void *)0x8:
      iVar2 = display_dispatchSoundEvent(this,param_1);
      break;
    case (void *)0x9:
      iVar2 = display_dispatchShapeCastOp(param_1);
      break;
    case (void *)0xa:
      iVar2 = display_dispatchSoundCastOp(param_1);
      break;
    case (void *)0xb:
      iVar2 = display_dispatchBitmapCastOp(param_1);
      break;
    case (void *)0xc:
      iVar2 = display_dispatchOleMemberOp(param_1);
      break;
    case (void *)0xd:
      iVar2 = display_dispatchOleCastOp(this,param_1);
      break;
    case (void *)0xe:
      iVar2 = playback_dispatchMemberOp(param_1);
    }
    if (param_1[2] == 3) {
      *(undefined4 *)(iVar1 + 0x20) = 0;
      *(undefined4 *)(iVar1 + 0x24) = 0;
    }
  }
  return iVar2;
}



// ============================================================
// Function: rendering_resolveDispatchFlags (FUN_680c2ea0)
// Address: 680c2ea0
// Size: 31 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_resolveDispatchFlags(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  iVar1 = media_getCastTypeById(param_1,&param_1);
  if (iVar1 == 0) {
    iVar2 = param_1;
  }
  return iVar2;
}



// ============================================================
// Function: rendering_getDispatchFlags (FUN_680c2ec0)
// Address: 680c2ec0
// Size: 33 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchFlags(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  iVar1 = media_findCastTypeIndex(param_1,&param_1);
  if (iVar1 == 0) {
    iVar2 = param_1;
  }
  return iVar2;
}



// ============================================================
// Function: rendering_formatMemberDescription (FUN_680c2ef0)
// Address: 680c2ef0
// Size: 129 bytes
// Params: undefined4 param_1, int param_2, undefined * param_3
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

undefined * rendering_formatMemberDescription(int param_1,int param_2,undefined *param_3)

{
  short sVar1;
  short extraout_var;
  char *pcVar2;
  
  if (param_3 == (undefined *)0x0) {
    param_3 = &DAT_68196418;
  }
  if ((param_1 < 0x10000) || (pcVar2 = "", 0x7d00ffff < param_1)) {
    pcVar2 = " (invalid)";
  }
  if (param_2 != 0) {
    sVar1 = scoreEngine_getChannelCount(param_2,(short)param_1);
    Ordinal_1219(param_3,"member %ld of castLib %ld%s",(int)extraout_var,(int)sVar1,pcVar2);
    return param_3;
  }
  Ordinal_1219(param_3,"member %ld of PLAYER-CAST %ld%s",(int)(short)((uint)param_1 >> 0x10),
               (int)(short)param_1,pcVar2);
  return param_3;
}



// ============================================================
// Function: rendering_writeStateData (FUN_680c2f80)
// Address: 680c2f80
// Size: 49 bytes
// Params: int param_1, undefined * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeStateData(int param_1,undefined *param_2)
{
  if (param_1 != 0) {
    rendering_formatMemberDescription(*(undefined4 *)(param_1 + 4),0,param_2);
    return 0;
  }
  rendering_formatMemberDescription(0,0,param_2);
  return 0;
}



// ============================================================
// Function: rendering_isStateValid (FUN_680c2fc0)
// Address: 680c2fc0
// Size: 28 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_isStateValid(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x48);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x48) = iVar1 + -1;
  }
  return iVar1 != 0;
}



// ============================================================
// Function: rendering_validateState (FUN_680c2fe0)
// Address: 680c2fe0
// Size: 32 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_validateState(int *param_1)

{
  int iVar1;
  
  iVar1 = rendering_getChannelState(param_1);
  if (iVar1 != 0) {
    iVar1 = rendering_getChannelDepth(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getStateCount (FUN_680c3000)
// Address: 680c3000
// Size: 40 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_getStateCount(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 8) {
      return *(uint *)(param_1 + 0x2c) >> 9 & 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: rendering_setStateIndex (FUN_680c3030)
// Address: 680c3030
// Size: 69 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setStateIndex(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    piVar1 = *(int **)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x1000;
  }
  return 0;
}



// ============================================================
// Function: rendering_resolveStateMember (FUN_680c3080)
// Address: 680c3080
// Size: 132 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_resolveStateMember(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_8;
  
  iVar2 = param_2;
  piVar1 = *(int **)(param_2 + 0x20);
  iVar5 = 0;
  local_8 = 0;
  uVar4 = 0;
  if (piVar1 != (int *)0x0) {
    if ((*(int *)(param_2 + 8) == 10) || (*(int *)(param_2 + 8) == 0xf)) {
      iVar5 = 1;
    }
    iVar3 = Ordinal_1333(piVar1,0,0,0,0,&param_2);
    if ((iVar3 != 0) && (param_2 == 0)) {
      rendering_setStateIndex(iVar2,-0x7ffbfffa);
      return local_8;
    }
    iVar5 = rendering_resolveMemberProperty(piVar1,(int *)(iVar2 + 0x24),iVar5,&local_8);
    uVar4 = local_8;
    if (iVar5 != 0) {
      rendering_setStateIndex(iVar2,iVar5);
      uVar4 = local_8;
    }
  }
  return uVar4;
}



// ============================================================
// Function: rendering_getStateFlags (FUN_680c3110)
// Address: 680c3110
// Size: 47 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getStateFlags(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = Ordinal_35(0x14);
    *(int *)(param_1 + 0x4c) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: rendering_getRawStateFlags (FUN_680c3140)
// Address: 680c3140
// Size: 28 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getRawStateFlags(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (*(int **)(param_1 + 0x4c) != (int *)0x0)) {
    uVar1 = *(undefined4 *)(**(int **)(param_1 + 0x4c) + 0xc);
  }
  return uVar1;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c3160 - 0x680c3750
// Functions (14):
//   rendering_setRawStateFlags (FUN_680c3160)
//   rendering_setStateFlag
//   rendering_toggleStateFlag
//   rendering_clearStateFlag
//   rendering_getFrameCount
//   rendering_getStatePair
//   rendering_dispatchUpdate
//   rendering_getDispatchMode
//   rendering_openMediaStream (FUN_680c3600)
//   rendering_createDispatchEntry
//   rendering_getDispatchEntry
//   rendering_getDispatchCount
//   rendering_updateDispatchScore (FUN_680c3710)
//   rendering_initStateFromProperty (FUN_680c3750)

// ============================================================
// Function: rendering_setRawStateFlags (FUN_680c3160)
// Address: 680c3160
// Size: 48 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setRawStateFlags(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = rendering_getStateFlags(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(**(int **)(param_1 + 0x4c) + 0xc) = param_2;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_setStateFlag (FUN_680c3190)
// Address: 680c3190
// Size: 55 bytes
// Params: int param_1, byte param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setStateFlag(int param_1,byte param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = rendering_getStateFlags(param_1);
  if (iVar2 != 0) {
    puVar1 = (uint *)(**(int **)(param_1 + 0x4c) + 0xc);
    *puVar1 = *puVar1 | 1 << (param_2 & 0x1f);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_toggleStateFlag (FUN_680c31d0)
// Address: 680c31d0
// Size: 51 bytes
// Params: int param_1, byte param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_toggleStateFlag(int param_1,byte param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = rendering_getStateFlags(param_1);
  if ((iVar1 == 0) ||
     (uVar2 = 1, (*(uint *)(**(int **)(param_1 + 0x4c) + 0xc) & 1 << (param_2 & 0x1f)) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: rendering_clearStateFlag (FUN_680c3210)
// Address: 680c3210
// Size: 57 bytes
// Params: int param_1, byte param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_clearStateFlag(int param_1,byte param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = rendering_getStateFlags(param_1);
  if (iVar2 != 0) {
    puVar1 = (uint *)(**(int **)(param_1 + 0x4c) + 0xc);
    *puVar1 = *puVar1 & ~(1 << (param_2 & 0x1f));
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getFrameCount (rendering_getFrameCount)
// Address: 680c3250
// Size: 27 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getFrameCount(int param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_EDX;
  
  uVar1 = rendering_getRawStateFlags(param_1);
  iVar2 = extraout_EDX + 1;
  if ((uVar1 & 1) == 0) {
    iVar2 = extraout_EDX;
  }
  return iVar2;
}



// ============================================================
// Function: rendering_getStatePair (FUN_680c3270)
// Address: 680c3270
// Size: 353 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStatePair(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_c20 [262];
  undefined2 local_808;
  undefined2 local_408;
  uint local_8;
  
  iVar1 = rendering_getFrameCount(param_1);
  if (iVar1 != 0) {
    iVar1 = rendering_getStateFlags(param_1);
    if (iVar1 != 0) {
      puVar3 = local_c20;
      for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      local_408 = 0;
      local_808 = 0;
      Ordinal_1314(local_c20,(int)&local_808 + 1,0x3ff);
      iVar1 = Ordinal_1201((int)&local_808 + 1);
      *(undefined1 *)((int)&local_808 + iVar1 + 1) = 0;
      (*(unsigned char *)((char *)&local_808 + 0)) = (char)iVar1;
      if (0xfe < iVar1) {
        (*(unsigned char *)((char *)&local_808 + 0)) = 0xff;
      }
      Ordinal_1316(local_c20);
      uVar2 = Ordinal_1313(local_c20);
      Ordinal_1310(local_c20,(int)&local_408 + 1,0x3ff);
      iVar1 = Ordinal_1201((int)&local_408 + 1);
      *(undefined1 *)((int)&local_408 + iVar1 + 1) = 0;
      (*(unsigned char *)((char *)&local_408 + 0)) = (char)iVar1;
      if (0xfe < iVar1) {
        (*(unsigned char *)((char *)&local_408 + 0)) = 0xff;
      }
      iVar1 = Ordinal_1201((int)&local_408 + 1);
      Ordinal_37((undefined4 *)(param_1 + 0x4c),2,&local_408,iVar1 + 2);
      iVar1 = Ordinal_1201((int)&local_808 + 1);
      Ordinal_37((undefined4 *)(param_1 + 0x4c),3,&local_808,iVar1 + 2);
      *(undefined4 *)(param_1 + 0x1c) = uVar2;
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffefff;
  }
  return 0;
}



// ============================================================
// Function: rendering_dispatchUpdate (FUN_680c33e0)
// Address: 680c33e0
// Size: 510 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_dispatchUpdate(int param_1,int *param_2,undefined4 *param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  int *local_830;
  undefined4 local_82c;
  undefined4 local_828;
  undefined4 local_824;
  undefined4 local_820;
  undefined4 local_81c;
  undefined4 local_818;
  undefined4 local_814;
  undefined4 local_810;
  undefined4 local_80c;
  undefined2 local_808;
  undefined2 local_408;
  uint local_8;
  
  Ordinal_1309(param_3,0x400,"",param_2[7]);
  iVar1 = rendering_getFrameCount((int)param_2);
  if ((iVar1 != 0) && (param_2[0x13] != 0)) {
    local_808 = 0;
    local_408 = 0;
    uVar2 = Ordinal_38(param_2[0x13],2,&local_808,0x400);
    *(undefined1 *)((int)&local_808 + uVar2 + 1) = 0;
    (*(unsigned char *)((char *)&local_808 + 0)) = (char)uVar2;
    if (0xfe < uVar2) {
      (*(unsigned char *)((char *)&local_808 + 0)) = 0xff;
    }
    uVar2 = Ordinal_38(param_2[0x13],3,&local_408,0x400);
    *(undefined1 *)((int)&local_408 + uVar2 + 1) = 0;
    (*(unsigned char *)((char *)&local_408 + 0)) = (char)uVar2;
    if (0xfe < uVar2) {
      (*(unsigned char *)((char *)&local_408 + 0)) = 0xff;
    }
    if (uVar2 != 0) {
      Ordinal_1309(param_3,0x400,(int)&local_808 + 1,param_2[7]);
      Ordinal_1318(param_3,(int)&local_408 + 1);
      if (param_4 != 0) {
        local_830 = (int *)0x0;
        local_82c = 0;
        local_828 = 0;
        local_824 = 0;
        local_820 = 0;
        local_81c = 0;
        local_818 = 0;
        local_814 = 0;
        local_810 = 0;
        local_80c = 0;
        if ((param_2[0xb] & 0x1000U) != 0) {
          return 0;
        }
        if ((param_2[0xb] & 0x2000U) == 0) {
          local_830 = param_2;
          local_828 = 0xe;
          rendering_initState((int *)&local_830);
          iVar1 = rendering_getChannelState(param_2);
          iVar1 = scoreEngine_writeChannelData(param_1,iVar1,param_3,local_824,(uint)(param_4 == 1),0,1);
          if (iVar1 == 0) {
            param_2[0xb] = param_2[0xb] | 0x1000;
            return 0;
          }
          rendering_getStatePair((int)param_2,param_3);
          param_2[0xb] = param_2[0xb] | 0x2000;
          goto LAB_680c359a;
        }
      }
      return 0;
    }
  }
LAB_680c359a:
  return 0;
}



// ============================================================
// Function: rendering_getDispatchMode (FUN_680c35e0)
// Address: 680c35e0
// Size: 22 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getDispatchMode(void)

{
  int *in_EAX;
  int iVar1;
  
  iVar1 = rendering_validateState(in_EAX);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 4);
  }
  return 0;
}



// ============================================================
// Function: rendering_openMediaStream (FUN_680c3600)
// Address: 680c3600
// Size: 36 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_openMediaStream(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = rendering_getDispatchMode();
  if (iVar1 != 0) {
    iVar1 = strings_openMediaStream(iVar1,FOURCC_ediM,*(int *)(unaff_ESI + 0xc));
    return iVar1;
  }
  return -1;
}



// ============================================================
// Function: rendering_createDispatchEntry (FUN_680c3630)
// Address: 680c3630
// Size: 88 bytes
// Params: int param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_createDispatchEntry(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    iVar1 = rendering_openMediaStream();
    bVar3 = iVar1 != -1;
    if (!bVar3) goto LAB_680c3676;
    iVar2 = rendering_getDispatchMode();
    iVar2 = crt_searchChunkByType(iVar2,iVar1);
  }
  else {
    bVar3 = true;
    iVar2 = Ordinal_1116(*(int *)(param_1 + 0x28));
  }
  if (iVar2 == 0) {
    bVar3 = false;
  }
LAB_680c3676:
  if (param_2 != (int *)0x0) {
    *param_2 = iVar2;
  }
  return bVar3;
}



// ============================================================
// Function: rendering_getDispatchEntry (FUN_680c3690)
// Address: 680c3690
// Size: 102 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * rendering_getDispatchEntry(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  iVar1 = Ordinal_1111(0xb0,1);
  *param_3 = iVar1;
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_1114(iVar1);
    iVar1 = rendering_getChannelSprite(param_1,(short)param_2);
    rendering_getChannelLock(iVar1);
    iVar1 = rendering_releaseChannelHandle();
    piVar2[0x2a] = iVar1;
    if (iVar1 == 0) {
      iVar1 = rendering_getChannelSize((short)param_2);
      piVar2[0x2a] = iVar1;
    }
    *piVar2 = param_1;
    piVar2[1] = param_2;
  }
  return piVar2;
}



// ============================================================
// Function: rendering_getDispatchCount (FUN_680c3700)
// Address: 680c3700
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchCount(void)
{
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: rendering_updateDispatchScore (FUN_680c3710)
// Address: 680c3710
// Size: 62 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_updateDispatchScore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_1114(param_1);
  if (iVar1 != 0) {
    playback_initScore((undefined4 *)(iVar1 + 0xa8));
    uVar2 = rendering_releaseChannelHandle();
    *(undefined4 *)(iVar1 + 0xa8) = uVar2;
    Ordinal_1115(param_1,param_2);
  }
  return iVar1 != 0;
}



// ============================================================
// Function: rendering_initStateFromProperty (FUN_680c3750)
// Address: 680c3750
// Size: 121 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_initStateFromProperty(undefined4 *param_1)
{
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = (undefined4 *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (param_1 != (undefined4 *)0x0) {
    local_30 = param_1;
    local_2c = **(undefined4 **)(*(int *)(*(int *)(*(int *)*param_1 + 0x18) + 0xc) + 0x20);
    local_28 = 9;
    rendering_initState((int *)&local_30);
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c37d0 - 0x680c3d50
// Functions (14):
//   rendering_updateStateFromProperty (FUN_680c37d0)
//   rendering_addDispatchMapping (FUN_680c3870)
//   rendering_findSystemCastLib (FUN_680c38d0)
//   rendering_getDispatchInfo
//   rendering_getDispatchData
//   rendering_getDispatchRef
//   rendering_setDispatchRef
//   rendering_getDispatchSize
//   rendering_getDispatchDataRef
//   rendering_isSpriteEmpty (FUN_680c3b90)
//   rendering_resolveStateEx
//   rendering_resolveState (rendering_resolveState)
//   rendering_getDispatchByChannel
//   rendering_getDispatchMode

// ============================================================
// Function: rendering_updateStateFromProperty (FUN_680c37d0)
// Address: 680c37d0
// Size: 154 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateStateFromProperty(int param_1)
{
  uint uVar1;
  undefined4 *extraout_EDX;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = (undefined4 *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (param_1 != 0) {
    uVar1 = rendering_getStateCount(param_1);
    if (uVar1 != 0) {
      rendering_initStateFromProperty(extraout_EDX);
      return 0;
    }
    local_2c = **(undefined4 **)(*(int *)(*(int *)(*(int *)*extraout_EDX + 0x18) + 0xc) + 0x20);
    local_28 = 10;
    local_30 = extraout_EDX;
    rendering_initState((int *)&local_30);
  }
  return 0;
}



// ============================================================
// Function: rendering_addDispatchMapping (FUN_680c3870)
// Address: 680c3870
// Size: 93 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_addDispatchMapping(void)
{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_8;
  
  if (((unaff_ESI != 0) && (in_EAX != 0)) && (unaff_EDI != 0)) {
    if (*(int *)(unaff_ESI + 0x5c) == 0) {
      iVar1 = Ordinal_1150(0x40,0x40,4);
      *(int *)(unaff_ESI + 0x5c) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    iVar1 = Ordinal_1165(*(undefined4 *)(unaff_ESI + 0x5c),&local_8);
    if (iVar1 == 0) {
      Ordinal_1151(*(undefined4 *)(unaff_ESI + 0x5c),local_8,in_EAX + 4);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_findSystemCastLib (FUN_680c38d0)
// Address: 680c38d0
// Size: 314 bytes
// Params: int param_1, undefined2 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_findSystemCastLib(int param_1,undefined2 *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = 0;
  local_14 = 0;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  if (param_1 != 0) {
    iVar5 = 0;
    puVar1 = PTR_s_System_6818e540;
    while ((puVar1 != (undefined *)0x0 &&
           (iVar2 = Ordinal_1111(0x400,1), local_8 = iVar2, iVar2 != 0))) {
      iVar4 = Ordinal_1114();
      Ordinal_1202(iVar4,(&PTR_s_System_6818e540)[iVar5 * 2]);
      iVar3 = Ordinal_1201(iVar4);
      playback_renderSpriteEx(*(int *)(*(int *)(unaff_EBX + 4) + 8),unaff_EBX + 0x50c,iVar4,iVar3);
      iVar3 = Ordinal_1201(iVar4,0);
      local_c = playback_mapFont(local_8,0,iVar3,iVar2);
      if (local_c == 0) break;
      local_10 = Ordinal_1114(local_c);
      iVar2 = Ordinal_1255(local_10,param_1);
      if (iVar2 == 0) {
        if (param_2 != (undefined2 *)0x0) {
          *param_2 = 0xffff;
          param_2[1] = (&DAT_6818e544)[iVar5 * 4];
        }
        local_14 = 1;
        goto LAB_680c39a7;
      }
      iVar5 = iVar5 + 1;
      puVar1 = (&PTR_s_System_6818e540)[iVar5 * 2];
    }
  }
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = 1;
    param_2[1] = 0;
  }
LAB_680c39a7:
  if (local_10 != 0) {
    Ordinal_1115(local_c);
  }
  if (iVar4 != 0) {
    Ordinal_1115(local_8);
  }
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_8);
  return local_14;
}



// ============================================================
// Function: rendering_getDispatchInfo (FUN_680c3a10)
// Address: 680c3a10
// Size: 116 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchInfo(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  if ((((*(int *)(param_1 + 8) != 0xb) || (*(int *)(param_1 + 0x5c) == 0)) &&
      ((*(int *)(param_1 + 0x4c) != 0 || (param_2 != 0)))) &&
     (iVar1 = rendering_getStateFlags(param_1), iVar1 != 0)) {
    if (param_2 != 0) {
      iVar1 = Ordinal_1114(param_2);
      iVar2 = Ordinal_1116(param_2);
      if ((iVar2 != 0) && (*(char *)(iVar2 + -1 + iVar1) == '\0')) {
        iVar2 = iVar2 + -1;
      }
      Ordinal_37((undefined4 *)(param_1 + 0x4c),0,iVar1,iVar2);
      Ordinal_1115(param_2);
      return 0;
    }
    cast_formatNumber((undefined4 *)(param_1 + 0x4c),0,0);
  }
  return 0;
}



// ============================================================
// Function: rendering_getDispatchData (FUN_680c3a90)
// Address: 680c3a90
// Size: 33 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchData(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    iVar1 = cast_lookupDataEntry(*(int *)(param_1 + 0x4c),6,0);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getDispatchRef (FUN_680c3ac0)
// Address: 680c3ac0
// Size: 67 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchRef(int param_1,int param_2)
{
  int iVar1;
  
  if ((((*(int *)(param_1 + 8) != 0xb) || (iVar1 = rendering_getFrameCount(param_1), iVar1 == 0)) &&
      ((*(int *)(param_1 + 0x4c) != 0 || (param_2 != 0)))) &&
     (iVar1 = rendering_getStateFlags(param_1), iVar1 != 0)) {
    cast_formatNumber((undefined4 *)(param_1 + 0x4c),6,param_2);
  }
  return 0;
}



// ============================================================
// Function: rendering_setDispatchRef (FUN_680c3b10)
// Address: 680c3b10
// Size: 48 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setDispatchRef(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = rendering_getStateFlags(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(**(int **)(param_1 + 0x4c) + 4) = param_2;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getDispatchSize (FUN_680c3b40)
// Address: 680c3b40
// Size: 24 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getDispatchSize(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int **)(param_1 + 0x4c) != (int *)0x0) {
    uVar1 = *(undefined4 *)(**(int **)(param_1 + 0x4c) + 0x10);
  }
  return uVar1;
}



// ============================================================
// Function: rendering_getDispatchDataRef (FUN_680c3b60)
// Address: 680c3b60
// Size: 33 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchDataRef(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = rendering_getStateFlags(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(**(int **)(param_1 + 0x4c) + 0x10) = param_2;
  }
  return 0;
}



// ============================================================
// Function: rendering_isSpriteEmpty (FUN_680c3b90)
// Address: 680c3b90
// Size: 45 bytes
// Params: int param_1, short param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_isSpriteEmpty(int param_1,short param_2)

{
  int iVar1;
  
  iVar1 = rendering_getChannelSprite(param_1,param_2);
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x14) == 0;
  }
  return false;
}



// ============================================================
// Function: rendering_resolveStateEx (FUN_680c3bc0)
// Address: 680c3bc0
// Size: 244 bytes
// Params: int param_1, undefined4 param_2, uint * param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_resolveStateEx(int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_8;
  
  uVar3 = 0;
  iVar4 = 0;
  local_8 = 0;
  piVar1 = (int *)rendering_getChannelSprite(param_1,(short)param_2);
  if (((piVar1 != (int *)0x0) && (piVar1[0x10] != 0)) && (*(int *)(piVar1[0x11] + 4) != 0)) {
    if ((short)piVar1[0x14] == (*(unsigned short *)((char *)&param_2 + 2))) {
      iVar4 = piVar1[0x15];
      local_8 = piVar1[0x16];
      uVar3 = (uint)(iVar4 != 0);
    }
    else {
      uVar2 = rendering_getFirstChannelFrame((uint)piVar1);
      local_8 = (int)(*(unsigned short *)((char *)&param_2 + 2)) - (int)(short)uVar2;
      if (piVar1[0x11] != 0) {
        iVar4 = Ordinal_1156(piVar1[0x10],piVar1[0x11],local_8);
        if ((iVar4 == 0) || (*(short *)(iVar4 + 6) != (*(unsigned short *)((char *)&param_2 + 2)))) {
          iVar4 = 0;
          uVar3 = Ordinal_1165(piVar1[0x10],&local_8,(int)&param_2 + 2,
                               *(undefined4 *)(*piVar1 + 0x36c),*piVar1);
          if (uVar3 == 0) goto LAB_680c3c99;
          iVar4 = Ordinal_1156(piVar1[0x10],piVar1[0x11],local_8);
        }
        else {
          uVar3 = 1;
        }
        piVar1[0x15] = iVar4;
        *(short *)(piVar1 + 0x14) = (*(unsigned short *)((char *)&param_2 + 2));
        piVar1[0x16] = local_8;
      }
    }
  }
LAB_680c3c99:
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar3;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar4;
  }
  return local_8;
}



// ============================================================
// Function: rendering_resolveState (rendering_resolveState)
// Address: 680c3cc0
// Size: 29 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_resolveState(int param_1,undefined4 param_2)

{
  rendering_resolveStateEx(param_1,param_2,(uint *)0x0,&param_1);
  return param_1;
}



// ============================================================
// Function: rendering_getDispatchByChannel (FUN_680c3ce0)
// Address: 680c3ce0
// Size: 105 bytes
// Params: int param_1, short param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * rendering_getDispatchByChannel(int param_1,short param_2)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  local_8 = Ordinal_1111(0xc,0);
  if (local_8 != 0) {
    piVar1 = (int *)Ordinal_1114(local_8);
    *piVar1 = local_8;
    iVar2 = rendering_getChannelSprite(param_1,param_2);
    piVar1[1] = iVar2;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x40) != 0)) {
      piVar1[2] = 0;
      return piVar1;
    }
    Ordinal_1115(local_8);
  }
  Ordinal_1113(&local_8);
  return (int *)0x0;
}



// ============================================================
// Function: rendering_getDispatchState (FUN_680c3d50)
// Address: 680c3d50
// Size: 48 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getDispatchState(int *param_1)
{
  int *piVar1;
  
  piVar1 = param_1;
  if ((param_1 != (int *)0x0) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    param_1 = *(int **)*param_1;
    Ordinal_1115(param_1);
    Ordinal_1113(&param_1);
    *piVar1 = 0;
  }
  return 0;
}



