// Module: rendering
// Topic: Member iteration, linked list management, change notification, and member lookup
// Address range: 0x680c3D80 - 0x680c5BF0
// Functions (41):
//   rendering_getMemberCache
//   rendering_resolveSlotState
//   rendering_updateMemberState
//   rendering_updateMemberDataEx
//   rendering_initMemberUpdate
//   rendering_processMemberBatch
//   rendering_attachMemberSprite
//   rendering_initMemberSlot
//   rendering_setMemberSlot
//   rendering_extractMemberSlot
//   rendering_checkThumbnailData
//   rendering_getMemberType
//   rendering_getMemberFlags
//   rendering_getMemberCount
//   rendering_getMemberInfo
//   rendering_cloneMemberSprite
//   rendering_stampMemberTimestamp
//   rendering_getMemberProperty
//   rendering_getMemberPropertyRef
//   rendering_queryMemberDataSize
//   rendering_loadMemberChannel
//   rendering_getMemberData
//   rendering_releaseMemberData
//   rendering_getMemberSlot
//   rendering_moveMemberSlot
//   rendering_setMemberData
//   rendering_getMemberDataRef
//   rendering_updateMemberRef
//   rendering_bindMemberRef
//   rendering_openMemberMedia
//   rendering_copyMemberData
//   rendering_extractMemberData
//   rendering_getMemberRefCount
//   rendering_findMemberByName
//   rendering_lookupMemberByName
//   rendering_getMemberDataBlock
//   rendering_deleteMemberProperty
//   rendering_writeMemberBatch
//   rendering_resolveMemberData
//   rendering_importMemberStream
//   rendering_importMemberData

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c3d80 - 0x680c43f0
// Functions (13):
//   rendering_getMemberCache
//   rendering_resolveSlotState
//   rendering_updateMemberState
//   rendering_updateMemberDataEx
//   rendering_initMemberUpdate
//   rendering_processMemberBatch
//   rendering_attachMemberSprite
//   rendering_initMemberSlot
//   rendering_setMemberSlot
//   rendering_extractMemberSlot
//   rendering_checkThumbnailData
//   rendering_getMemberType
//   rendering_getMemberFlags

// ============================================================
// Function: rendering_getMemberCache (FUN_680c3d80)
// Address: 680c3d80
// Size: 53 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberCache(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 4), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x40) != 0)) {
    iVar2 = Ordinal_1156(*(int *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x44),
                         *(undefined4 *)(param_1 + 8));
    if (iVar2 != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
  }
  return iVar2;
}



// ============================================================
// Function: rendering_resolveSlotState (FUN_680c3dc0)
// Address: 680c3dc0
// Size: 44 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resolveSlotState(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    if ((short)param_2 == (short)(*(int **)(param_1 + 4))[1]) {
      iVar1 = rendering_resolveStateEx(**(int **)(param_1 + 4),param_2,(uint *)0x0,(int *)0x0);
      *(int *)(param_1 + 8) = iVar1;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_updateMemberState (FUN_680c3df0)
// Address: 680c3df0
// Size: 238 bytes
// Params: int * param_1, int param_2, int * param_3, undefined4 * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_updateMemberState(int *param_1,int param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  local_14 = 0;
  local_10 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = rendering_validateState(param_1);
    piVar1 = *(int **)(iVar2 + 4);
    iVar3 = strings_openMediaStream((int)piVar1,param_2,param_1[3]);
    if (iVar3 != -1) {
      uVar4 = crt_getChunkSize(*(int **)(iVar2 + 4),iVar3);
      if (uVar4 == 0) {
        local_8 = 2;
        goto LAB_680c3eb0;
      }
      if (param_5 == (int *)0x0) {
        if (param_4 == (undefined4 *)0x0) {
          playback_loadScoreDataDirect(iVar2,param_2,param_1[3],&local_c);
        }
        else {
          iVar2 = playback_openScore(iVar2,param_2,param_1[3],&local_c,&local_10);
          if (iVar2 != 0) {
            playback_readMediaHeader((int *)*param_1,iVar2);
          }
        }
      }
      else {
        local_14 = Ordinal_16(piVar1,iVar3);
        if (local_14 == 0) goto LAB_680c3eb0;
      }
    }
    local_8 = 1;
  }
LAB_680c3eb0:
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = local_10;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = local_14;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_c;
  }
  return local_8;
}



// ============================================================
// Function: rendering_updateMemberDataEx (FUN_680c3ee0)
// Address: 680c3ee0
// Size: 202 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5, undefined4 param_6, undefined4 param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateMemberDataEx(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5,undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = (int *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = (undefined4 *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  lingo_updateState(*param_2);
  local_2c = *param_1;
  local_30 = param_2;
  local_28 = 7;
  local_20 = param_4;
  local_1c = param_3;
  local_18 = param_5;
  local_14 = param_6;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  local_24 = param_7;
  iVar1 = rendering_initState((int *)&local_30);
  if (iVar1 != 0) {
    iVar1 = lingo_getMovieRef(*param_2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_initMemberUpdate (FUN_680c3fb0)
// Address: 680c3fb0
// Size: 132 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_initMemberUpdate(void)
{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  
  iVar2 = rendering_initState((int *)&stack0xffffffd0);
  if (iVar2 != 0) {
    lingo_getMovieRef(*unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: rendering_processMemberBatch (FUN_680c4040)
// Address: 680c4040
// Size: 189 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_processMemberBatch(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1418();
  if (iVar1 != 0) {
    Ordinal_1435();
    local_c = 0;
    if (0 < iVar1) {
      do {
        Ordinal_1418();
        iVar2 = Ordinal_1418();
        Ordinal_1433();
        iVar3 = Ordinal_1434();
        if (iVar3 == 0) {
          return local_8;
        }
        if ((iVar2 != 0) && (iVar2 = rendering_initMemberUpdate(), iVar2 == 0)) {
          return 0;
        }
        local_8 = 1;
        iVar2 = Ordinal_1434();
        if (iVar2 == 0) {
          return 1;
        }
        local_c = local_c + 1;
      } while (local_c < iVar1);
      return 1;
    }
  }
  return 1;
}



// ============================================================
// Function: rendering_attachMemberSprite (FUN_680c4100)
// Address: 680c4100
// Size: 199 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_attachMemberSprite(void *this,undefined4 param_1)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint local_b8;
  int local_b4;
  void *local_b0;
  undefined4 local_ac;
  uint local_8;
  
  puVar1 = (undefined4 *)rendering_getChannelSprite((int)this,(short)param_1);
  local_b4 = rendering_resolveStateEx((int)this,param_1,&local_b8,&local_b4);
  if (local_b8 == 0) {
    Ordinal_1130(&local_b0,0xa8);
    local_ac = param_1;
    Ordinal_1158(puVar1[0x10],puVar1[0x11]);
    local_b0 = this;
    Ordinal_1151(puVar1[0x10],local_b4,&local_b0);
    uVar2 = Ordinal_1157(puVar1[0x10]);
    puVar1[0x11] = uVar2;
    rendering_initChannelState(puVar1);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_initMemberSlot (FUN_680c41d0)
// Address: 680c41d0
// Size: 71 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_initMemberSlot(undefined4 *param_1,int param_2)
{
  undefined local_48 [64];
  uint local_8;
  
  rendering_writeStateData((int)param_1,local_48);
  lingo_formatDebugMsg((int *)*param_1,param_2);
  return 0;
}



// ============================================================
// Function: rendering_setMemberSlot (FUN_680c4220)
// Address: 680c4220
// Size: 64 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_setMemberSlot(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = rendering_getStateFlags(param_1);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1201(param_2);
    iVar1 = Ordinal_37((undefined4 *)(param_1 + 0x4c),0x10,param_2,iVar1);
    if (iVar1 != 0) {
      *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 1;
      return iVar1;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_extractMemberSlot (FUN_680c4260)
// Address: 680c4260
// Size: 85 bytes
// Params: int param_1, int param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_extractMemberSlot(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Ordinal_38(*(int *)(param_1 + 0x4c),0x10,param_3,param_2);
  *(undefined1 *)(uVar1 + param_3) = 0;
  if (1 < uVar1) {
    iVar2 = Ordinal_1201(param_3 + 1);
    if (iVar2 + 2U == uVar1) {
      Ordinal_1129(param_3,param_3 + 1,uVar1 - 1);
      return uVar1 - 2;
    }
  }
  return uVar1;
}



// ============================================================
// Function: rendering_checkThumbnailData (FUN_680c42c0)
// Address: 680c42c0
// Size: 50 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_checkThumbnailData(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = FOURCC_Thum;
  iVar1 = rendering_getDispatchMode();
  iVar2 = strings_readMediaBlock(iVar1,iVar3,iVar2);
  if (iVar2 != 0) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: rendering_getMemberType (FUN_680c4300)
// Address: 680c4300
// Size: 226 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberType(int param_1)
{
  int cchWideChar;
  int iVar1;
  LPWSTR lpWideCharStr;
  int *piVar2;
  undefined1 local_408;
  CHAR local_407 [1023];
  uint local_8;
  
  local_408 = 0;
  memset(local_407,0,0x3ff);
  Ordinal_38(*(int *)(param_1 + 0x4c),1,&local_408,0x3ff);
  cchWideChar = MultiByteToWideChar(0xfde9,0,local_407,-1,(LPWSTR)0x0,0);
  if (0 < cchWideChar) {
    iVar1 = Ordinal_1111(cchWideChar * 2,1);
    lpWideCharStr = (LPWSTR)Ordinal_1114(iVar1);
    MultiByteToWideChar(0xfde9,0,local_407,-1,lpWideCharStr,cchWideChar);
    Ordinal_1115(iVar1);
    if (iVar1 != 0) goto LAB_680c43b1;
  }
  iVar1 = Ordinal_1111(2,1);
LAB_680c43b1:
  piVar2 = (int *)(param_1 + 0xa4);
  if (*piVar2 != 0) {
    Ordinal_1113(piVar2);
  }
  *piVar2 = iVar1;
  return 0;
}



// ============================================================
// Function: rendering_getMemberFlags (FUN_680c43f0)
// Address: 680c43f0
// Size: 33 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberFlags(int param_1)

{
  if (*(int *)(param_1 + 0xa4) == 0) {
    rendering_getMemberType(param_1);
  }
  return *(undefined4 *)(param_1 + 0xa4);
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c4420 - 0x680c4a70
// Functions (11):
//   rendering_getMemberCount
//   rendering_getMemberInfo
//   rendering_cloneMemberSprite
//   rendering_stampMemberTimestamp
//   rendering_getMemberProperty
//   rendering_getMemberPropertyRef
//   rendering_queryMemberDataSize
//   rendering_loadMemberChannel
//   rendering_getMemberData
//   rendering_releaseMemberData
//   rendering_getMemberSlot

// ============================================================
// Function: rendering_getMemberCount (FUN_680c4420)
// Address: 680c4420
// Size: 181 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberCount(void)
{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  
  piVar1 = (int *)(*unaff_ESI + 0x324 + unaff_ESI[4] * 8);
  if (*(short *)((int)unaff_ESI + 0x1a) == 0) {
    if (*(short *)((int)unaff_ESI + 0x16) == 0) {
      if ((short)*piVar1 != (short)unaff_ESI[1]) {
        return 0;
      }
      if (*(short *)((int)piVar1 + 2) != *(short *)((int)unaff_ESI + 6)) {
        return 0;
      }
      if ((short)piVar1[1] != (short)unaff_ESI[1]) {
        return 0;
      }
      if (*(short *)((int)piVar1 + 6) != *(short *)((int)unaff_ESI + 6)) {
        return 0;
      }
    }
  }
  else {
    iVar2 = rendering_resolveState(*unaff_ESI,unaff_ESI[6]);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x14) = unaff_ESI[5];
    }
  }
  if ((*(short *)((int)unaff_ESI + 0x16) != 0) &&
     (iVar2 = rendering_resolveState(*unaff_ESI,unaff_ESI[5]), iVar2 != 0)) {
    *(int *)(iVar2 + 0x18) = unaff_ESI[6];
  }
  if (((short)*piVar1 == (short)unaff_ESI[1]) &&
     (*(short *)((int)piVar1 + 2) == *(short *)((int)unaff_ESI + 6))) {
    *piVar1 = unaff_ESI[5];
  }
  if (((short)piVar1[1] == (short)unaff_ESI[1]) &&
     (*(short *)((int)piVar1 + 6) == *(short *)((int)unaff_ESI + 6))) {
    piVar1[1] = unaff_ESI[6];
  }
  unaff_ESI[6] = 0;
  unaff_ESI[5] = 0;
  return 0;
}



// ============================================================
// Function: rendering_getMemberInfo (FUN_680c44e0)
// Address: 680c44e0
// Size: 123 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberInfo(void)
{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  
  if (((((unaff_ESI[0xb] & 0x200U) != 0) &&
       ((((unaff_ESI[2] != 1 || (unaff_ESI[0x1e] == 0)) || (unaff_ESI[0x15] == 0)) ||
        ((*(short *)((int)unaff_ESI + 0x1a) == 0 && (*(short *)((int)unaff_ESI + 0x16) == 0)))))) &&
      (*(short *)((int)unaff_ESI + 0x1a) == 0)) && (*(short *)((int)unaff_ESI + 0x16) == 0)) {
    iVar2 = *unaff_ESI;
    piVar1 = (int *)(iVar2 + 0x324 + unaff_ESI[4] * 8);
    if ((*(short *)(iVar2 + 0x326 + unaff_ESI[4] * 8) != 0) &&
       (iVar2 = rendering_resolveState(iVar2,*piVar1), iVar2 != 0)) {
      *(int *)(iVar2 + 0x18) = unaff_ESI[1];
      unaff_ESI[5] = *piVar1;
    }
    *piVar1 = unaff_ESI[1];
    if (*(short *)((int)piVar1 + 6) == 0) {
      piVar1[1] = unaff_ESI[1];
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_cloneMemberSprite (FUN_680c4560)
// Address: 680c4560
// Size: 284 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_cloneMemberSprite(int param_1)
{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *unaff_ESI;
  int local_34;
  
  local_34 = 0;
  if (unaff_ESI[0x13] != 0) {
    local_34 = Ordinal_1120(unaff_ESI[0x13],0);
    unaff_ESI[0x13] = local_34;
    if (local_34 == 0) goto LAB_680c4641;
    rendering_setDispatchRef((int)unaff_ESI,0);
    rendering_getDispatchDataRef((int)unaff_ESI,0);
  }
  if (unaff_ESI[0x29] != 0) {
    uVar4 = Ordinal_1120(unaff_ESI[0x29],0);
    unaff_ESI[0x29] = uVar4;
  }
  if (unaff_ESI[10] != 0) {
    uVar4 = Ordinal_1120(unaff_ESI[10],0);
    unaff_ESI[10] = uVar4;
  }
  if (unaff_ESI[2] != 0) {
    iVar5 = rendering_initState((int *)&stack0xffffffd0);
    if (iVar5 == 0) {
LAB_680c4641:
      piVar2 = (int *)*unaff_ESI;
      Ordinal_1113(&local_34);
      uVar4 = unaff_ESI[1];
      Ordinal_1130();
      unaff_ESI[1] = uVar4;
      *unaff_ESI = piVar2;
      lingo_formatDebugMsg(piVar2,-0x7a);
      return 0;
    }
  }
  pcVar1 = *(code **)(**(int **)(*(int *)(param_1 + 0x18) + 4) + 0x184);
  if (pcVar1 != (code *)0x0) {
    uVar4 = (*pcVar1)(unaff_ESI[1],unaff_ESI[0x11]);
    unaff_ESI[0x11] = uVar4;
  }
  unaff_ESI[3] = 0;
  return 0;
}



// ============================================================
// Function: rendering_stampMemberTimestamp (FUN_680c4680)
// Address: 680c4680
// Size: 117 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_stampMemberTimestamp(int param_1)
{
  int in_EAX;
  int iVar1;
  undefined4 local_8;
  
  iVar1 = rendering_getStateFlags(in_EAX);
  if (iVar1 != 0) {
    local_8 = rendering_getTimestamp();
    Ordinal_37((undefined4 *)(in_EAX + 0x4c),0x12,&local_8,4);
    iVar1 = **(int **)(*(int *)(param_1 + 0x18) + 4);
    if (*(int *)(iVar1 + 0x178) != 0) {
      param_1 = 0;
      iVar1 = (**(code **)(iVar1 + 0x178))(&param_1);
      if ((iVar1 != 0) && (param_1 != 0)) {
        cast_formatNumber((undefined4 *)(in_EAX + 0x4c),0x13,param_1);
        Ordinal_1113(&param_1);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getMemberProperty (FUN_680c4700)
// Address: 680c4700
// Size: 218 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberProperty(int *param_1,int param_2,int *param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20 [7];
  
  local_2c = 0;
  local_24 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_30 = param_1;
  local_28 = 0x12;
  rendering_initState((int *)&local_30);
  iVar1 = local_24;
  if (local_24 < 2) {
    iVar1 = 1;
  }
  local_20[0] = Ordinal_1111(iVar1 * 4 + 4,1);
  local_24 = 0;
  if (param_2 != 0) goto LAB_680c47b0;
  if (param_1[10] == 0) {
    iVar1 = param_1[3];
    if (iVar1 < 1) goto LAB_680c47b0;
    iVar3 = FOURCC_ediM;
    iVar2 = rendering_validateState(param_1);
    iVar1 = strings_openMediaStream(*(int *)(iVar2 + 4),iVar3,iVar1);
    if (iVar1 == -1) goto LAB_680c47b0;
  }
  local_24 = crt_negotiateFormat(local_20,local_24,FOURCC_ediM);
LAB_680c47b0:
  local_28 = 0x13;
  rendering_initState((int *)&local_30);
  *param_3 = local_20[0];
  return 0;
}



// ============================================================
// Function: rendering_getMemberPropertyRef (FUN_680c47e0)
// Address: 680c47e0
// Size: 161 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberPropertyRef(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = param_1;
  iVar1 = *(int *)*param_1;
  iVar4 = 0;
  *param_2 = 0;
  iVar3 = rendering_getFrameCount((int)param_1);
  if (iVar3 == 0) {
    iVar4 = rendering_getMemberProperty(param_1,param_3,param_2);
  }
  if ((param_3 == 0) && (*(int *)(*(int *)(iVar1 + 0xc) + 0xd4) != 0)) {
    param_3 = 0;
    param_1 = (int *)0x0;
    iVar3 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xd4))(iVar1,piVar2[1],0,&param_3,0,0);
    while ((iVar3 != 0 && (iVar4 = crt_negotiateFormat(param_2,iVar4,param_3), iVar4 != 0))) {
      param_1 = (int *)((int)param_1 + 1);
      iVar3 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xd4))(iVar1,piVar2[1],param_1,&param_3,0,0);
    }
  }
  return iVar4;
}



// ============================================================
// Function: rendering_queryMemberDataSize (FUN_680c4890)
// Address: 680c4890
// Size: 150 bytes
// Params: undefined4 param_1, int * param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_queryMemberDataSize(undefined4 param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_c;
  int *local_8;
  
  iVar5 = 0;
  local_8 = (int *)0x0;
  local_c = 0;
  *param_3 = 0;
  iVar1 = rendering_validateState(param_2);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 4), iVar1 != 0)) {
    iVar2 = rendering_getMemberProperty(param_2,0,(int *)&local_8);
    if (0 < iVar2) {
      do {
        iVar3 = strings_openMediaStream(iVar1,*(int *)(*local_8 + iVar5 * 4),param_2[3]);
        if ((iVar3 != -1) && (uVar4 = crt_getSlotDirtyFlag(iVar1,iVar3), uVar4 == 0)) {
          uVar4 = crt_getSlotModifiedFlag(iVar1,iVar3);
          *param_3 = uVar4;
          goto LAB_680c48d4;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
    }
    local_c = 1;
  }
LAB_680c48d4:
  Ordinal_1113(&local_8);
  return local_c;
}



// ============================================================
// Function: rendering_loadMemberChannel (FUN_680c4930)
// Address: 680c4930
// Size: 219 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_loadMemberChannel(int *param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *unaff_EDI;
  undefined4 uVar4;
  int *local_30;
  
  local_30 = (int *)0x0;
  if ((param_1[0xb] & 0x200U) != 0) {
    return 0;
  }
  if ((param_1[0xb] & 0x400U) == 0) {
    uVar2 = scoreEngine_readChannelBlock(*(int **)(unaff_EDI + 0x20),param_1,0);
    if (uVar2 == 0) goto LAB_680c49f9;
  }
  bitmap_recordFilePos((int)unaff_EDI,param_1);
  local_30 = param_1;
  iVar3 = rendering_initState((int *)&local_30);
  uVar2 = param_1[0xb];
  if ((uVar2 & 0x400) != 0) {
    iVar3 = 0;
  }
  param_1[0xb] = (iVar3 << 9 ^ uVar2) & 0x200 ^ uVar2;
  rendering_getMemberInfo();
  if ((param_1[0xb] & 0x400U) == 0) {
    if (iVar3 == 0) {
      uVar4 = 4;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 3;
  }
  bitmap_writeTraceEntry(unaff_EDI,param_1,uVar4);
LAB_680c49f9:
  return 0;
}



// ============================================================
// Function: rendering_getMemberData (FUN_680c4a10)
// Address: 680c4a10
// Size: 31 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberData(undefined4 param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = rendering_loadMemberChannel(param_2);
  if (iVar1 != 0) {
    param_2[0x12] = param_2[0x12] + 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_releaseMemberData (FUN_680c4a30)
// Address: 680c4a30
// Size: 62 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_releaseMemberData(int *param_1)
{
  if ((param_1 != (int *)0x0) &&
     ((*(short *)(*param_1 + 0x324 + param_1[4] * 8) != (short)param_1[1] ||
      (*(short *)(*param_1 + param_1[4] * 8 + 0x326) != *(short *)((int)param_1 + 6))))) {
    rendering_getMemberCount();
    rendering_getMemberInfo();
  }
  return 0;
}



// ============================================================
// Function: rendering_getMemberSlot (FUN_680c4a70)
// Address: 680c4a70
// Size: 170 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberSlot(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *local_c;
  undefined4 local_8;
  
  iVar5 = 0;
  local_8 = 0;
  local_c = (int *)0x0;
  iVar1 = rendering_getMemberProperty(param_1,0,(int *)&local_c);
  if (iVar1 == 0) {
    local_8 = 1;
    Ordinal_1113(&local_c);
    return local_8;
  }
  if (0 < iVar1) {
    do {
      iVar3 = *(int *)(*local_c + iVar5 * 4);
      iVar2 = rendering_validateState(param_1);
      if (iVar2 == 0) goto LAB_680c4afc;
      iVar3 = strings_openMediaStream(*(int *)(iVar2 + 4),iVar3,param_1[3]);
      if (iVar3 != -1) {
        uVar4 = crt_getChunkSize(*(int **)(iVar2 + 4),iVar3);
        if (uVar4 == 0) {
          local_8 = 0;
          goto LAB_680c4afc;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  local_8 = 1;
LAB_680c4afc:
  Ordinal_1113(&local_c);
  return local_8;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c4b20 - 0x680c5090
// Functions (11):
//   rendering_moveMemberSlot
//   rendering_setMemberData
//   rendering_getMemberDataRef
//   rendering_updateMemberRef
//   rendering_bindMemberRef
//   rendering_openMemberMedia
//   rendering_copyMemberData
//   rendering_extractMemberData
//   rendering_getMemberRefCount
//   rendering_findMemberByName
//   rendering_lookupMemberByName

// ============================================================
// Function: rendering_moveMemberSlot (FUN_680c4b20)
// Address: 680c4b20
// Size: 42 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_moveMemberSlot(int param_1,undefined4 param_2)

{
  rendering_getMemberCount();
  *(undefined4 *)(param_1 + 0x10) = param_2;
  if ((*(uint *)(param_1 + 0x2c) & 0x200) != 0) {
    rendering_getMemberInfo();
  }
  return 1;
}



// ============================================================
// Function: rendering_setMemberData (FUN_680c4b50)
// Address: 680c4b50
// Size: 262 bytes
// Params: int param_1, int * param_2, byte param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setMemberData(int param_1,int *param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if ((param_3 & 0x18) == 0) {
    iVar2 = rendering_getChannelState(param_2);
    if ((iVar2 != 0) && (*(undefined4 *)(iVar2 + 0x18) = 1, *(int *)(iVar2 + 0x14) != 0)) {
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x458) = 1;
    }
    if ((param_3 & 2) != 0) {
      param_2[0xf] = param_2[0xf] + 1;
    }
  }
  (*(unsigned char *)((char *)&param_2 + 3)) = param_3 & 2;
  if ((param_3 & 2) != 0) {
    *(byte *)(piVar1 + 0xe) = *(byte *)(piVar1 + 0xe) | 2;
  }
  if ((param_3 & 1) == 0) {
    if ((param_3 & 2) == 0) goto LAB_680c4bc9;
  }
  else {
    *(byte *)(piVar1 + 0xe) = *(byte *)(piVar1 + 0xe) | 1;
  }
  rendering_stampMemberTimestamp(param_1);
LAB_680c4bc9:
  if ((param_3 & 8) != 0) {
    *(byte *)(piVar1 + 0xe) = *(byte *)(piVar1 + 0xe) | 8;
  }
  iVar2 = rendering_fetchChannelProperty();
  if (iVar2 == 0) {
    return 0;
  }
  if ((piVar1[2] == 0xb) && ((param_3 & 4) != 0)) {
    *(byte *)(piVar1 + 0xe) = *(byte *)(piVar1 + 0xe) | 4;
  }
  if (param_3 != 8) {
    switch(piVar1[2]) {
    case 1:
    case 0xd:
      if ((*(unsigned char *)((char *)&param_2 + 3)) != 0) {
        Ordinal_1671(piVar1 + 0x1d);
        Ordinal_1671(piVar1 + 0x1e);
      }
      break;
    case 3:
    case 7:
      bitmap_computeTextHeight(param_1,(int)piVar1);
      bitmap_getTextFieldState((int)piVar1);
    }
    playback_renderSpriteBlock(**(int **)(param_1 + 0x20),(int)piVar1,param_3);
  }
  return 1;
}



// ============================================================
// Function: rendering_getMemberDataRef (FUN_680c4c80)
// Address: 680c4c80
// Size: 121 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberDataRef(int param_1,int *param_2)
{
  int iVar1;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar1 = rendering_dispatchUpdate(*(int *)(param_1 + 0x20),param_2,local_420,1);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1402(&local_424,local_420,1);
    if (iVar1 != 0) {
      Ordinal_1435(local_424);
      Ordinal_1407(&local_424);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_updateMemberRef (FUN_680c4d00)
// Address: 680c4d00
// Size: 153 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateMemberRef(int param_1,int *param_2)
{
  int iVar1;
  undefined4 local_420 [262];
  uint local_8;
  
  Ordinal_1130(local_420,0x418);
  iVar1 = rendering_getFrameCount((int)param_2);
  if ((iVar1 != 0) && ((param_2[0xb] & 0x3000U) == 0)) {
    iVar1 = rendering_dispatchUpdate(param_1,param_2,local_420,2);
    if (iVar1 == 0) {
      param_2[0xb] = param_2[0xb] & 0xffffefff;
      rendering_dispatchUpdate(param_1,param_2,local_420,1);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_bindMemberRef (FUN_680c4da0)
// Address: 680c4da0
// Size: 84 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_bindMemberRef(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = rendering_getFrameCount(param_2);
  if (iVar1 != 0) {
    iVar1 = rendering_updateMemberRef(param_1,(int *)param_2);
    if (iVar1 == 4) {
      if (*(int *)(param_2 + 0x20) != 0) {
        rendering_setStateIndex(param_2,0);
      }
      *(int **)(param_2 + 0x20) = param_3;
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 4))(param_3);
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_openMemberMedia (FUN_680c4e00)
// Address: 680c4e00
// Size: 59 bytes
// Params: int * param_1, undefined4 * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_openMemberMedia(int *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (param_1[10] != 0) {
    Ordinal_1404(param_2,param_1[10],1);
    return 1;
  }
  uVar1 = rendering_updateMemberState(param_1,FOURCC_ediM,param_3,param_2,(int *)0x0);
  return uVar1;
}



// ============================================================
// Function: rendering_copyMemberData (FUN_680c4e40)
// Address: 680c4e40
// Size: 89 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_copyMemberData(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 10;
  if (param_1[10] == 0) {
    iVar2 = rendering_updateMemberState(param_1,FOURCC_ediM,(int *)0x0,(undefined4 *)0x0,piVar1);
    if (((iVar2 == 1) && (*piVar1 == 0)) && (param_1[2] == 0xd)) {
      iVar2 = rendering_updateMemberState(param_1,FOURCC_OLED,(int *)0x0,(undefined4 *)0x0,piVar1);
    }
  }
  else {
    iVar2 = 1;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = *piVar1;
  }
  return iVar2;
}



// ============================================================
// Function: rendering_extractMemberData (FUN_680c4ea0)
// Address: 680c4ea0
// Size: 170 bytes
// Params: int * param_1, int param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * rendering_extractMemberData(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  if (param_1[10] == 0) {
    iVar4 = rendering_openMemberMedia(param_1,&local_8,(int *)&param_1);
    iVar5 = param_2;
    piVar1 = param_1;
    piVar2 = (int *)0x0;
    if (iVar4 == 1) {
      if ((param_1 != (int *)0x0) && (param_2 != 0)) {
        uVar3 = Ordinal_1433(local_8,param_1);
        uVar3 = Ordinal_1433(iVar5,local_8,uVar3);
        iVar5 = Ordinal_1431(iVar5,uVar3);
        if (iVar5 == 0) goto LAB_680c4f36;
      }
      piVar2 = piVar1;
    }
  }
  else {
    piVar2 = (int *)Ordinal_1116(param_1[10]);
    iVar5 = param_2;
    if (param_2 != 0) {
      uVar3 = Ordinal_1114(piVar1[10]);
      Ordinal_1420(iVar5,uVar3,piVar2);
      Ordinal_1115(piVar1[10]);
      Ordinal_1407(&local_8);
      return piVar2;
    }
  }
LAB_680c4f36:
  Ordinal_1407(&local_8);
  return piVar2;
}



// ============================================================
// Function: rendering_getMemberRefCount (FUN_680c4f50)
// Address: 680c4f50
// Size: 99 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberRefCount(int *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = param_1;
  iVar3 = rendering_getChannelState(param_1);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x5c) != 0)) {
    uVar4 = rendering_getMemberFlags((int)piVar2);
    iVar5 = Ordinal_1114(uVar4);
    if (iVar5 != 0) {
      iVar1 = *piVar2;
      iVar5 = Ordinal_1165(*(undefined4 *)(iVar3 + 0x5c),&param_1,iVar5,
                           *(undefined4 *)(iVar1 + 0x370),iVar1);
      if (iVar5 != 0) {
        Ordinal_1160(*(undefined4 *)(iVar3 + 0x5c),param_1);
      }
      Ordinal_1115(uVar4);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_findMemberByName (FUN_680c4fc0)
// Address: 680c4fc0
// Size: 202 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_findMemberByName(int param_1)

{
  int iVar1;
  int iVar2;
  LPCSTR unaff_EBX;
  int *unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  LPWSTR local_c;
  int local_8;
  
  iVar1 = 0;
  local_8 = 0;
  local_c = (LPWSTR)0x0;
  if (((unaff_EDI != (int *)0x0) && (unaff_EBX != (LPCSTR)0x0)) && (unaff_EDI[0x17] != 0)) {
    iVar2 = MultiByteToWideChar(0xfde9,0,unaff_EBX,-1,(LPWSTR)0x0,0);
    iVar1 = local_8;
    if (0 < iVar2) {
      local_c = (LPWSTR)Ordinal_1124(iVar2 * 2);
      MultiByteToWideChar(0xfde9,0,unaff_EBX,-1,local_c,iVar2);
      iVar2 = Ordinal_1165(unaff_EDI[0x17],&local_10,local_c,*(undefined4 *)(*unaff_EDI + 0x370),
                           *unaff_EDI);
      iVar1 = local_8;
      if (iVar2 != 0) {
        Ordinal_1155(unaff_EDI[0x17],local_10,&local_14);
        iVar1 = rendering_resolveState(*unaff_EDI,local_14);
        if ((param_1 != -1) && (*(int *)(iVar1 + 8) != param_1)) {
          local_8 = 0;
          iVar1 = local_8;
        }
      }
    }
    if (local_c != (LPWSTR)0x0) {
      Ordinal_1125(&local_c);
    }
  }
  return iVar1;
}



// ============================================================
// Function: rendering_lookupMemberByName (FUN_680c5090)
// Address: 680c5090
// Size: 317 bytes
// Params: void * this, undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_lookupMemberByName(void *this,undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *local_40c;
  char local_408 [1024];
  uint local_8;
  
  uVar1 = Ordinal_1201(param_1);
  piVar2 = rendering_getDispatchByChannel(*(int *)this,*(short *)((int)this + 4));
  local_40c = piVar2;
  if (piVar2 != (int *)0x0) {
    iVar3 = rendering_getMemberCache((int)piVar2);
    while (iVar3 != 0) {
      iVar4 = Ordinal_38(*(int *)(iVar3 + 0x4c),1,local_408,0x3ff);
      if (iVar4 != 0) {
        local_408[iVar4] = '\0';
        if (iVar4 + -1 < 0xff) {
          local_408[0] = (char)iVar4 + -1;
        }
        else {
          local_408[0] = -1;
        }
        uVar5 = rendering_getMemberFlags(iVar3);
        iVar4 = Ordinal_1114(uVar5);
        if (iVar4 != 0) {
          rendering_addDispatchMapping();
          Ordinal_1115(uVar5);
          piVar2 = local_40c;
        }
        if ((param_2 == -1) || (param_2 == *(int *)(iVar3 + 8))) {
          uVar5 = Ordinal_1201(local_408 + 1,param_1,uVar1);
          iVar3 = Ordinal_1260(local_408 + 1,uVar5);
          if (iVar3 != 0) break;
        }
      }
      iVar3 = rendering_getMemberCache((int)piVar2);
    }
  }
  rendering_getDispatchState((int *)&local_40c);
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c51d0 - 0x680c5bc0
// Functions (6):
//   rendering_getMemberDataBlock
//   rendering_deleteMemberProperty
//   rendering_writeMemberBatch
//   rendering_resolveMemberData
//   rendering_importMemberStream
//   rendering_importMemberData

// ============================================================
// Function: rendering_getMemberDataBlock (FUN_680c51d0)
// Address: 680c51d0
// Size: 259 bytes
// Params: int param_1, short param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberDataBlock(int param_1,short param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  void *this;
  int iVar2;
  undefined4 local_c;
  int local_8;
  
  iVar1 = param_3;
  iVar2 = 0;
  local_8 = 0;
  local_c = 0;
  if ((param_1 == 0) || (param_3 == 0)) {
LAB_680c529b:
    if (param_5 != (undefined4 *)0x0) {
      if (iVar2 == 0) {
        *param_5 = 1;
        goto LAB_680c52b6;
      }
      *param_5 = *(undefined4 *)(iVar2 + 4);
    }
    if (iVar2 == 0) goto LAB_680c52b6;
  }
  else if ((param_4 != 4) || (iVar2 = rendering_findSystemCastLib(param_3,(undefined2 *)param_5), iVar2 == 0)) {
    param_3 = 1;
    iVar2 = 0;
    while (local_8 = scoreEngine_allocFrameDataPtr(*(int *)(param_1 + 0x20)), local_8 != 0) {
      if (param_2 != 0) {
        scoreEngine_resetChannelData(local_8,param_2);
      }
      this = (void *)scoreEngine_getFrameLayout(local_8);
      while (this != (void *)0x0) {
        if (param_3 == 1) {
          iVar2 = rendering_findMemberByName(param_4);
        }
        else {
          iVar2 = rendering_lookupMemberByName(this,iVar1,param_4);
        }
        if (iVar2 != 0) goto LAB_680c529b;
        if (param_2 != 0) break;
        this = (void *)scoreEngine_getFrameLayout(local_8);
      }
      scoreEngine_initCastXtra(&local_8);
      param_3 = param_3 + 1;
      if (2 < param_3) break;
    }
    goto LAB_680c529b;
  }
  local_c = 1;
LAB_680c52b6:
  scoreEngine_initCastXtra(&local_8);
  return local_c;
}



// ============================================================
// Function: rendering_deleteMemberProperty (FUN_680c52e0)
// Address: 680c52e0
// Size: 149 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_deleteMemberProperty(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c;
  int *local_8;
  
  iVar4 = 0;
  local_c = 1;
  local_8 = (int *)0x0;
  iVar1 = rendering_validateState(in_EAX);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 4), iVar1 != 0)) {
    iVar2 = rendering_getMemberPropertyRef(in_EAX,(int *)&local_8,0);
    if (0 < iVar2) {
      do {
        iVar3 = strings_readMediaBlock(iVar1,*(int *)(*local_8 + iVar4 * 4),in_EAX[3]);
        if (iVar3 != 0) {
          local_c = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    if ((in_EAX[3] != 0) && (iVar1 = crt_mergeChunks(iVar1,in_EAX[3]), iVar1 != 0)) {
      local_c = 0;
    }
  }
  Ordinal_1113(&local_8);
  return local_c;
}



// ============================================================
// Function: rendering_writeMemberBatch (FUN_680c5380)
// Address: 680c5380
// Size: 205 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_writeMemberBatch(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = (int *)0x0;
  local_14 = 0;
  iVar2 = rendering_getMemberProperty(unaff_EBX,1,(int *)&local_10);
  Ordinal_1429();
  if ((iVar2 != 0) && (local_c = 0, 0 < iVar2)) {
    do {
      uVar1 = *(undefined4 *)(*local_10 + local_c * 4);
      iVar3 = rendering_updateMemberDataEx(param_1,unaff_EBX,uVar1,0,&local_18,&local_14,1);
      if (iVar3 == 0) goto LAB_680c5420;
      Ordinal_1429();
      Ordinal_1429();
      iVar3 = rendering_updateMemberDataEx(param_1,unaff_EBX,uVar1,unaff_EDI,(undefined4 *)0x0,&local_14,1);
      if (iVar3 == 0) {
        local_8 = 0;
        Ordinal_1113(&local_10);
        return local_8;
      }
      local_c = local_c + 1;
      local_8 = 1;
    } while (local_c < iVar2);
  }
  local_8 = 1;
LAB_680c5420:
  Ordinal_1113(&local_10);
  return local_8;
}



// ============================================================
// Function: rendering_resolveMemberData (FUN_680c5450)
// Address: 680c5450
// Size: 1383 bytes
// Params: undefined4 * param_1, int * param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resolveMemberData(undefined4 *param_1,int *param_2,int *param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_460;
  int local_45c;
  int local_458;
  undefined4 local_454;
  int local_450;
  int *local_44c;
  int *local_448;
  undefined4 local_444;
  undefined4 local_440;
  int *local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined1 local_41c [20];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_454 = 0;
  local_448 = (int *)0x0;
  local_444 = 0;
  local_440 = 0;
  local_43c = (int *)0x0;
  local_438 = 0;
  local_434 = 0;
  local_430 = 0;
  local_42c = 0;
  local_428 = 0;
  local_424 = 0;
  local_44c = (int *)0x0;
  local_458 = 0;
  local_470 = 0;
  local_46c = 0;
  local_468 = 0;
  local_464 = 0;
  local_460 = 0;
  iVar1 = rendering_getMemberData(*param_1,param_2);
  if (iVar1 == 0) goto LAB_680c5986;
  iVar1 = rendering_getFrameCount((int)param_2);
  if (((iVar1 == 0) || (param_2[2] == 1)) || (param_2[2] == 0xb)) {
    iVar1 = *param_3;
    if ((iVar1 == 0) && (param_3[1] == 0)) {
      iVar1 = Ordinal_1111(0x14,0);
      param_3[2] = iVar1;
      iVar1 = Ordinal_1404(&local_44c,iVar1,3);
      if (iVar1 == 0) {
        local_454 = 5;
      }
      else {
        Ordinal_1420(local_44c,&local_470,0x14);
        Ordinal_1429(local_44c,param_2[2]);
        uVar2 = rendering_extractMemberSlot((int)param_2,0x3ff,(int)local_408);
        Ordinal_1430(local_44c,uVar2);
        Ordinal_1420(local_44c,local_408,uVar2);
        local_444 = *param_1;
        local_448 = param_2;
        local_440 = 0x11;
        local_43c = local_44c;
        rendering_initState((int *)&local_448);
        if (param_2[2] == 0xb) {
          local_458 = cast_lookupDataEntry(param_2[0x13],0,0);
          uVar3 = Ordinal_1114(local_458);
          uVar4 = Ordinal_1116(local_458);
          Ordinal_1420(local_44c,uVar3,uVar4);
        }
        else if (param_2[2] == 1) {
          if ((param_4 == 0) || ((*(byte *)(param_2 + 0xe) & 2) != 0)) {
            iVar1 = rendering_getFrameCount((int)param_2);
            if (iVar1 == 0) goto LAB_680c58dd;
            local_450 = 0;
            Ordinal_1429(local_44c,1);
            iVar1 = rendering_updateMemberDataEx(param_1,param_2,FOURCC_BITD,0,&local_45c,&local_450,1);
            if (iVar1 != 0) {
              Ordinal_1429(local_44c,FOURCC_BITD);
              Ordinal_1429(local_44c,local_45c);
              iVar1 = rendering_updateMemberDataEx(param_1,param_2,FOURCC_BITD,local_44c,(undefined4 *)0x0,&local_450
                                   ,1);
              if (iVar1 == 0) {
                local_454 = 1;
              }
            }
          }
          else {
            iVar1 = rendering_getFrameCount((int)param_2);
            if (iVar1 == 0) {
              local_450 = 0;
              iVar1 = rendering_updateMemberState(param_2,FOURCC_ediM,&local_45c,&local_450,(int *)0x0);
              if ((iVar1 == 1) && (local_450 != 0)) {
                Ordinal_1429(local_44c,1);
                Ordinal_1429(local_44c,FOURCC_ediM);
                Ordinal_1429(local_44c,local_45c);
                uVar3 = Ordinal_1433(local_450,local_45c);
                uVar3 = Ordinal_1433(local_44c,local_450,uVar3);
                iVar1 = Ordinal_1431(local_44c,uVar3);
              }
              else {
                iVar1 = rendering_writeMemberBatch(param_1);
              }
              if (iVar1 == 0) {
                local_454 = 1;
              }
              Ordinal_1407(&local_450);
            }
            else {
              local_420 = 0;
              memset(local_41c,0,0x414);
              local_450 = 0;
              iVar1 = rendering_dispatchUpdate((int)param_1,param_2,&local_420,2);
              if (iVar1 != 0) {
                iVar1 = Ordinal_1377(0xe,&local_420);
                if (iVar1 == 0) {
                  iVar1 = Ordinal_1377(0xd,&local_420);
                  if (iVar1 == 0) goto LAB_680c5980;
                }
                if (param_2[8] == 0) {
                  iVar1 = Ordinal_1402(&local_450,&local_420,1);
LAB_680c56fa:
                  if (iVar1 != 0) goto LAB_680c56fe;
                }
                else {
                  iVar1 = Ordinal_1405(&local_450,param_2[8],1);
                  if (iVar1 == 0) {
                    Ordinal_1407(&local_450);
                    iVar1 = Ordinal_1405(&local_450,param_2[8],1,0);
                    goto LAB_680c56fa;
                  }
LAB_680c56fe:
                  Ordinal_1429(local_44c,1);
                  Ordinal_1429(local_44c,FOURCC_ediM);
                  uVar3 = Ordinal_1435(local_450);
                  Ordinal_1429(local_44c,uVar3);
                  uVar3 = Ordinal_1433(local_450,uVar3);
                  uVar3 = Ordinal_1433(local_44c,local_450,uVar3);
                  iVar1 = Ordinal_1431(local_44c,uVar3);
                  if (iVar1 == 0) {
                    local_454 = 1;
                  }
                }
                Ordinal_1407(&local_450);
              }
            }
          }
        }
        else {
LAB_680c58dd:
          iVar1 = rendering_writeMemberBatch(param_1);
          if (iVar1 == 0) {
            local_454 = 1;
          }
        }
      }
    }
    else if ((iVar1 == 1) && (param_3[1] == 0)) {
      iVar1 = rendering_copyMemberData(param_2,param_3 + 2);
      if (iVar1 != 1) {
        local_454 = 6;
      }
    }
    else if ((iVar1 == 8) && (param_3[1] == 1)) {
      piVar5 = (int *)rendering_getDispatchData((int)param_2);
      if (piVar5 != (int *)0x0) {
        scoreEngine_swapKeyframeBytes(piVar5,1);
      }
      param_3[2] = (int)piVar5;
    }
    else {
      local_444 = *param_1;
      local_448 = param_2;
      local_440 = 0x17;
      local_43c = param_3;
      rendering_initState((int *)&local_448);
      local_454 = local_438;
    }
  }
  else {
    param_3[2] = 0;
  }
LAB_680c5980:
  rendering_isStateValid((int)param_2);
LAB_680c5986:
  Ordinal_1113(&local_458);
  Ordinal_1407(&local_44c);
  return 0;
}



// ============================================================
// Function: rendering_importMemberStream (FUN_680c59c0)
// Address: 680c59c0
// Size: 498 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_importMemberStream(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  int local_43c;
  int local_438;
  undefined4 local_434;
  int local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_42c = 0;
  local_428 = 0;
  local_424 = 0;
  local_420 = 0;
  local_41c = 0;
  local_418 = 0;
  local_414 = 0;
  local_410 = 0;
  local_40c = 0;
  local_450 = 0;
  local_44c = 0;
  local_448 = 0;
  local_444 = 0;
  local_430 = 0;
  local_434 = 0;
  local_43c = 0;
  local_454 = 0;
  iVar1 = Ordinal_1404(&local_434,*(undefined4 *)(param_1 + 8),1);
  if (iVar1 != 0) {
    Ordinal_1409(local_434,&local_454,0x14);
    uVar2 = Ordinal_1418(local_434);
    *(undefined4 *)(param_3 + 8) = uVar2;
    local_438 = Ordinal_1419(local_434);
    iVar1 = Ordinal_1409(local_434,local_408,local_438);
    if (iVar1 != 0) {
      local_408[local_438] = 0;
      iVar1 = rendering_setMemberSlot(param_3,local_408);
      if (iVar1 != 0) {
        local_42c = *param_2;
        local_430 = param_3;
        local_428 = 0x10;
        local_424 = local_434;
        local_420 = rendering_updateChannelState((int)(param_2 + 0x123));
        rendering_initState(&local_430);
        local_438 = Ordinal_1435(local_434);
        iVar1 = Ordinal_1433(local_434);
        if (*(int *)(param_3 + 8) == 0xb) {
          local_43c = Ordinal_1439(local_434,local_438 - iVar1,0);
          if (local_43c != 0) {
            rendering_getDispatchInfo(param_3,local_43c);
          }
        }
        else {
          rendering_processMemberBatch();
        }
      }
    }
  }
  Ordinal_1113(&local_43c);
  Ordinal_1407(&local_434);
  return 0;
}



// ============================================================
// Function: rendering_importMemberData (FUN_680c5bc0)
// Address: 680c5bc0
// Size: 33 bytes
// Params: undefined4 * param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_importMemberData(undefined4 *param_1,int param_2,undefined4 param_3)
{
  undefined1 local_1c [8];
  undefined4 local_14;
  
  local_14 = param_3;
  rendering_importMemberStream((int)local_1c,param_1,param_2);
  return 0;
}



