// Module: rendering
// Topic: Cast member save, file serialization, and resource persistence
// Address range: 0x680c9DD0 - 0x680cBE60
// Functions (24):
//   rendering_saveMemberProperties
//   rendering_processCastSave
//   rendering_iterateSaveCast
//   rendering_markSaveFlags
//   rendering_writeMediaChunks
//   rendering_saveCastResources
//   rendering_prepareSaveSprites
//   rendering_restoreSpriteState
//   rendering_writeCastData
//   rendering_serializeMemberData
//   rendering_saveCastData
//   rendering_initCastSave
//   rendering_persistCastMember
//   rendering_saveCastEntry
//   rendering_saveMovieData
//   rendering_saveMovieCast
//   rendering_readCastData
//   rendering_saveCastMember
//   rendering_initSaveBuffer
//   rendering_growSaveBuffer
//   rendering_appendSaveBuffer
//   rendering_freeSaveBuffer
//   rendering_getStageRef
//   rendering_checkSaveVersion

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c9dd0 - 0x680ca450
// Functions (6):
//   rendering_saveMemberProperties
//   rendering_processCastSave
//   rendering_iterateSaveCast
//   rendering_markSaveFlags
//   rendering_writeMediaChunks
//   rendering_saveCastResources

// ============================================================
// Function: rendering_saveMemberProperties (FUN_680c9dd0)
// Address: 680c9dd0
// Size: 487 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_saveMemberProperties(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_1c = 0;
  local_10 = (int *)0x0;
  local_c = 0;
  local_8 = 0;
  iVar1 = rendering_getFrameCount((int)unaff_ESI);
  if (iVar1 == 0) {
    local_c = rendering_getMemberProperty(unaff_ESI,param_3,(int *)&local_10);
    local_18 = 0;
    if (0 < local_c) {
      do {
        iVar1 = *(int *)(*local_10 + local_18 * 4);
        iVar2 = rendering_updateSpriteScore(unaff_ESI[0xd],param_2,1);
        if ((iVar2 == -1) ||
           (iVar3 = rendering_updateMemberDataEx(param_1,unaff_ESI,iVar1,0,&local_24,&local_1c,0), iVar3 == 0))
        goto LAB_680c9fa3;
        if ((local_24 == 0) && (iVar1 != FOURCC_snd)) {
          local_8 = 1;
        }
        else {
          playback_processScoreEntry(*(undefined4 *)(param_2 + 4),iVar2,local_24,&local_14);
          iVar1 = rendering_updateMemberDataEx(param_1,unaff_ESI,iVar1,local_14,(undefined4 *)0x0,&local_1c,0);
          if (iVar1 != 0) {
            local_8 = 1;
          }
          iVar1 = Ordinal_1407(&local_14);
          if (iVar1 == 0) goto LAB_680c9fa3;
        }
        local_18 = local_18 + 1;
      } while (local_18 < local_c);
    }
    if (local_c == 0) goto LAB_680c9ecd;
  }
  else {
LAB_680c9ecd:
    local_8 = 1;
  }
  if (param_3 == 0) {
    iVar1 = *(int *)*unaff_ESI;
    if (*(int *)(*(int *)(iVar1 + 0xc) + 0xd4) == 0) goto LAB_680c9f9a;
    param_3 = 0;
    param_1 = (undefined4 *)0x0;
    local_20 = 0;
    local_18 = 0;
    iVar2 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xd4))
                      (iVar1,unaff_ESI[1],0,&param_3,&param_1,&local_20);
    while (iVar2 != 0) {
      iVar3 = crt_findInSortedArray(local_10,local_c,param_3);
      iVar2 = param_2;
      if (iVar3 == 0) {
        iVar3 = rendering_updateSpriteScore(unaff_ESI[0xd],param_2,1);
        if (iVar3 == -1) goto LAB_680c9fa3;
        iVar2 = Ordinal_20(*(int *)(iVar2 + 4),iVar3,param_1);
        Ordinal_1113(&param_1);
        if (iVar2 != 0) goto LAB_680c9fa3;
      }
      local_18 = local_18 + 1;
      iVar2 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xd4))
                        (iVar1,unaff_ESI[1],local_18,&param_3,&param_1,&local_20);
    }
    local_8 = 1;
  }
  else {
LAB_680c9f9a:
    if (local_8 == 0) goto LAB_680c9fa3;
  }
  unaff_ESI[0xc] = unaff_ESI[0xc] & 0xfffffffe;
LAB_680c9fa3:
  Ordinal_1113(&local_10);
  return local_8;
}



// ============================================================
// Function: rendering_processCastSave (FUN_680c9fc0)
// Address: 680c9fc0
// Size: 456 bytes
// Params: void * this, int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_processCastSave(void *this,int param_1,undefined4 param_2,int param_3)
{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined3 extraout_var;
  int local_888;
  int *local_884;
  undefined1 local_87c [1076];
  undefined2 local_448;
  undefined1 local_48 [64];
  uint local_8;
  
  local_884 = *(int **)(*(int *)((int)this + 4) + 8);
  local_888 = 0;
  piVar3 = (int *)rendering_resolveState((int)local_884,param_2);
  if ((((piVar3 != (int *)0x0) && (piVar3[2] != 0)) && (piVar3[2] != 0xd)) &&
     (local_884 = (int *)*piVar3, (*(byte *)(piVar3 + 0xc) & 1) != 0)) {
    iVar4 = rendering_submitSpriteScore();
    if (iVar4 == 0) {
      iVar4 = rendering_validateState(piVar3);
      rendering_transferSpriteScore(param_1,iVar4);
    }
    else {
      iVar4 = rendering_getFrameCount((int)piVar3);
      if (((iVar4 == 0) && (uVar5 = rendering_getStateCount((int)piVar3), uVar5 == 0)) &&
         (local_888 = rendering_getMemberData(*(undefined4 *)this,piVar3), local_888 == 0)) {
        Ordinal_1130(&local_448,0x400);
        iVar4 = Ordinal_38(piVar3[0x13],1,&local_448,0x3ff);
        if (iVar4 == 0) {
          local_448 = 0;
        }
        Ordinal_1517(DAT_681956e0,0x151d,local_48,0x40);
        Ordinal_1219(local_87c,local_48,(int)*(short *)((int)piVar3 + 6),(int)&local_448 + 1);
        lingo_showErrorDialog(local_87c);
      }
      else {
        iVar4 = rendering_validateState(piVar3);
        if (((param_1 != iVar4) ||
            (bVar2 = rendering_createDispatchEntry((int)piVar3,(int *)0x0), CONCAT31(extraout_var,bVar2) == 0)) ||
           ((piVar3[10] != 0 || (iVar4 = rendering_copyMemberData(piVar3,(int *)0x0), iVar4 == 1)))) {
          rendering_saveMemberProperties(this,param_1,param_3);
        }
        if (local_888 != 0) {
          rendering_isStateValid((int)piVar3);
        }
      }
    }
  }
  pcVar1 = *(code **)(*(int *)(*local_884 + 0xc) + 0x16c);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(local_884,param_2);
  }
  return 0;
}



// ============================================================
// Function: rendering_iterateSaveCast (FUN_680ca190)
// Address: 680ca190
// Size: 102 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_iterateSaveCast(int param_1,int param_2)

{
  short sVar1;
  undefined4 in_EAX;
  short extraout_var;
  int iVar3;
  int iVar4;
  short extraout_var_00;
  void *unaff_EDI;
  undefined4 uVar2;
  
  rendering_getSpriteCount(in_EAX);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while( true ) {
    if (sVar1 == 0) {
      return 1;
    }
    iVar4 = *(int *)(*(int *)((int)unaff_EDI + 4) + 8);
    iVar3 = rendering_processCastSave(unaff_EDI,param_1,uVar2,param_2);
    if ((iVar3 == 0) || (iVar4 = lingo_getMovieRef(iVar4), iVar4 != 0)) break;
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  return 0;
}



// ============================================================
// Function: rendering_markSaveFlags (FUN_680ca200)
// Address: 680ca200
// Size: 277 bytes
// Params: void * this, int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_markSaveFlags(void *this,int param_1,undefined4 param_2,int param_3)
{
  short sVar1;
  short extraout_var;
  int iVar3;
  uint uVar4;
  int iVar5;
  short extraout_var_00;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [6];
  uint local_8;
  undefined4 uVar2;
  
  rendering_getSpriteCount(param_2);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while (sVar1 != 0) {
    iVar3 = rendering_resolveState(*(int *)((int)this + 0xc),uVar2);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {
      if (((*(byte *)(iVar3 + 0x38) & 10) == 0) && (param_3 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
      *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) ^ (*(uint *)(iVar3 + 0x30) ^ uVar4) & 1;
      if (((((*(byte *)(iVar3 + 0x30) & 1) == 0) && (*(int *)(param_1 + 0xba4) != 0)) &&
          (*(int *)(iVar3 + 8) == 1)) && (*(int *)(iVar3 + 0x60) == 0x20)) {
        local_38 = local_20;
        local_44 = 0;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        local_40 = 0x19;
        local_3c = 0x1f;
        local_48 = iVar3;
        iVar5 = rendering_initState(&local_48);
        if ((iVar5 != 0) &&
           ((local_20[0] == 0xfd || ((local_20[0] == 0xfb && (*(char *)(param_1 + 0x4aa) == -3))))))
        {
          *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) | 1;
        }
      }
    }
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  return 0;
}



// ============================================================
// Function: rendering_writeMediaChunks (FUN_680ca320)
// Address: 680ca320
// Size: 290 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_writeMediaChunks(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int unaff_EBX;
  int iVar5;
  int local_24;
  code *local_20;
  code *local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_c = 0;
  local_24 = -1;
  local_1c = (code *)0x0;
  local_20 = (code *)0x0;
  if (unaff_EBX == 0) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    piVar1 = (int *)*param_2;
    iVar2 = *piVar1;
    local_20 = *(code **)(*(int *)(iVar2 + 0xc) + 0xd0);
    local_14 = param_2[0xf];
    pcVar3 = local_20;
  }
  else {
    piVar1 = *(int **)(*(int *)(unaff_EBX + 4) + 8);
    iVar2 = *piVar1;
    local_1c = *(code **)(*(int *)(iVar2 + 0xc) + 0xcc);
    local_14 = 0x400;
    pcVar3 = local_1c;
  }
  if (pcVar3 != (code *)0x0) {
    iVar5 = 0;
    local_8 = local_14;
    while( true ) {
      if (unaff_EBX == 0) {
        iVar4 = (*local_20)(iVar2,*(undefined2 *)(param_2 + 1),iVar5,&local_c,0,0,&local_10);
      }
      else {
        iVar4 = (*local_1c)(iVar2,*(undefined4 *)(*(int *)(unaff_EBX + 4) + 4),iVar5,&local_c,0,0,
                            &local_10);
      }
      if (iVar4 == 0) {
        return 1;
      }
      if ((local_10 != 0) && (iVar4 = lingo_getMovieRef((int)piVar1), iVar4 != 0)) {
        lingo_formatDebugMsg(piVar1,local_10);
        return 0;
      }
      iVar4 = local_14;
      if (local_c == local_24) {
        iVar4 = local_8 + 1;
      }
      local_8 = iVar4;
      iVar4 = strings_readMediaChunk(*(int *)(param_1 + 4),local_c,local_8);
      if (iVar4 == -1) break;
      local_24 = local_c;
      iVar5 = iVar5 + 1;
    }
    return 0;
  }
  return 1;
}



// ============================================================
// Function: rendering_saveCastResources (FUN_680ca450)
// Address: 680ca450
// Size: 330 bytes
// Params: int param_1, int param_2, int param_3, void * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_saveCastResources(int param_1,int param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  short sVar4;
  int local_c;
  undefined4 local_8;
  
  iVar1 = *in_EAX;
  iVar2 = *(int *)(param_1 + 4);
  local_8 = 0;
  local_c = 0;
  iVar3 = strings_readMediaChunk(iVar2,FOURCC_CASx,in_EAX[0xf]);
  if (iVar3 == -1) {
    return 0;
  }
  iVar3 = strings_readMediaChunk(iVar2,FOURCC_LctX,in_EAX[0xf]);
  if (iVar3 == -1) {
    return 0;
  }
  iVar3 = strings_readMediaChunk(iVar2,FOURCC_Fmap,in_EAX[0xf]);
  if (iVar3 == -1) {
    return 0;
  }
  iVar3 = strings_readMediaChunk(iVar2,FOURCC_ccl,in_EAX[0xf]);
  if (iVar3 == -1) {
    return 0;
  }
  iVar3 = strings_readMediaChunk(iVar2,FOURCC_Cinf,in_EAX[0xf]);
  if (iVar3 == -1) {
    return 0;
  }
  iVar3 = rendering_writeMediaChunks(param_1,in_EAX);
  if (iVar3 == 0) {
    return 0;
  }
  if (((in_EAX[0x12] == 0) || (param_2 == 0)) ||
     (local_c = stage_dispatchSpriteReturn(param_2,in_EAX[0x12],*(int *)(param_1 + 4),param_3), local_c == 0)) {
    sVar4 = (short)in_EAX[0x1d];
    param_1 = CONCAT22(sVar4,(short)in_EAX[1]);
    if (sVar4 <= *(short *)((int)in_EAX + 0x76)) {
      do {
        iVar3 = rendering_resolveState(iVar1,param_1);
        if (((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) &&
           (((*(byte *)(iVar3 + 0x30) & 1) != 0 && (iVar3 = rendering_copySpriteBlock(param_4,iVar2), iVar3 == 0)
            ))) goto LAB_680ca572;
        sVar4 = sVar4 + 1;
        param_1 = CONCAT22(sVar4,(undefined2)param_1);
      } while (sVar4 <= *(short *)((int)in_EAX + 0x76));
    }
    local_8 = 1;
LAB_680ca572:
    if (local_c == 0) {
      return local_8;
    }
  }
  rendering_getSpriteScoreState();
  return local_8;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680ca5a0 - 0x680cac80
// Functions (7):
//   rendering_prepareSaveSprites
//   rendering_restoreSpriteState
//   rendering_writeCastData
//   rendering_serializeMemberData
//   rendering_saveCastData
//   rendering_initCastSave
//   rendering_persistCastMember

// ============================================================
// Function: rendering_prepareSaveSprites (FUN_680ca5a0)
// Address: 680ca5a0
// Size: 721 bytes
// Params: int param_1, int param_2, int param_3, int param_4, undefined4 param_5, void * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
rendering_prepareSaveSprites(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,void *param_6)

{
  short sVar1;
  short extraout_var;
  int iVar3;
  int iVar4;
  short extraout_var_00;
  int iVar5;
  int local_8;
  undefined4 uVar2;
  
  iVar5 = *(int *)(param_3 + 4);
  local_8 = 1;
  do {
    rendering_getSpriteCount(param_5);
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var,sVar1);
    sVar1 = extraout_var;
    while (sVar1 != 0) {
      iVar3 = rendering_resolveState(param_1,uVar2);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {
        iVar4 = *(int *)(iVar3 + 0xc);
        *(uint *)(iVar3 + 0x30) =
             *(uint *)(iVar3 + 0x30) ^ ((uint)(iVar4 < 1) * 2 ^ *(uint *)(iVar3 + 0x30)) & 2;
        if ((*(uint *)(iVar3 + 0x30) & 2) != 0) {
          *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) | 1;
        }
        if ((*(uint *)(iVar3 + 0x30) & 1) == 0) {
          *(int *)(iVar3 + 0x34) = iVar4;
        }
        else {
          if ((*(uint *)(iVar3 + 0x30) & 2) == 0) {
            if (local_8 == 1) {
              if (param_4 == 1) {
                *(int *)(iVar3 + 0x34) = iVar4;
              }
              else {
                iVar4 = crt_ensureSlot(iVar5,iVar4,FOURCC_CASt);
                if (iVar4 == 0) goto LAB_680ca631;
                *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0xc);
              }
            }
          }
          else if (local_8 == 2) {
LAB_680ca631:
            iVar4 = Ordinal_19(iVar5,FOURCC_CASt);
            *(int *)(iVar3 + 0x34) = iVar4;
          }
          iVar3 = Ordinal_15(iVar5);
          if (iVar3 != 0) {
            rendering_getSpriteScoreState();
            return 0;
          }
        }
      }
      sVar1 = rendering_getCurrentSprite();
      uVar2 = CONCAT22(extraout_var_00,sVar1);
      sVar1 = extraout_var_00;
    }
    local_8 = local_8 + 1;
    if (2 < local_8) {
      if ((param_2 != 0) && (sVar1 = 1, 0 < *(short *)(param_2 + 0x478))) {
        do {
          iVar3 = scoreEngine_getChannelField(param_2,sVar1);
          if ((iVar3 != 0) &&
             ((*(int *)(iVar3 + 0x14) != 0 &&
              (iVar3 = rendering_saveCastResources(param_3,*(int *)(param_2 + 8),param_4,param_6), iVar3 == 0)))) {
            return 0;
          }
          sVar1 = sVar1 + 1;
        } while (sVar1 <= *(short *)(param_2 + 0x478));
      }
      iVar3 = strings_readMediaChunk(iVar5,FOURCC_DRCF,0x400);
      if (((iVar3 != -1) && (iVar3 = strings_readMediaChunk(iVar5,FOURCC_FXmp,0x400), iVar3 != -1)) &&
         ((param_2 == 0 ||
          (((((iVar3 = strings_readMediaChunk(iVar5,FOURCC_MCsL,0x400), iVar3 != -1 &&
              (iVar3 = strings_readMediaChunk(iVar5,FOURCC_Sord,0x400), iVar3 != -1)) &&
             (iVar3 = strings_readMediaChunk(iVar5,FOURCC_VWFI,0x400), iVar3 != -1)) &&
            ((((iVar3 = strings_readMediaChunk(iVar5,FOURCC_VWSC,0x400), iVar3 != -1 &&
               (iVar3 = strings_readMediaChunk(iVar5,FOURCC_VWTL,0x400), iVar3 != -1)) &&
              ((iVar3 = strings_readMediaChunk(iVar5,FOURCC_VWLB,0x400), iVar3 != -1 &&
               ((iVar3 = strings_readMediaChunk(iVar5,FOURCC_VWtc,0x400), iVar3 != -1 &&
                (iVar3 = strings_readMediaChunk(iVar5,FOURCC_Chan,0x400), iVar3 != -1)))))) &&
             (iVar3 = strings_readMediaChunk(iVar5,FOURCC_XTRl,0x400), iVar3 != -1)))) &&
           (((iVar3 = strings_readMediaChunk(iVar5,FOURCC_Cinf,0x400), iVar3 != -1 &&
             (iVar5 = strings_readMediaChunk(iVar5,FOURCC_VWTC,0x400), iVar5 != -1)) &&
            (iVar5 = rendering_writeMediaChunks(param_3,(undefined4 *)0x0), iVar5 != 0)))))))) {
        return 1;
      }
      return 0;
    }
  } while( true );
}



// ============================================================
// Function: rendering_restoreSpriteState (FUN_680ca880)
// Address: 680ca880
// Size: 80 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall rendering_restoreSpriteState(int param_1)

{
  short sVar1;
  undefined4 in_EAX;
  short extraout_var;
  int iVar3;
  short extraout_var_00;
  undefined4 uVar2;
  
  rendering_getSpriteCount(in_EAX);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while (sVar1 != 0) {
    iVar3 = rendering_resolveState(*(int *)(param_1 + 0xc),uVar2);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x34);
    }
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  return 1;
}



// ============================================================
// Function: rendering_writeCastData (FUN_680ca8d0)
// Address: 680ca8d0
// Size: 105 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeCastData(undefined4 param_1,int param_2)
{
  short sVar1;
  int in_EAX;
  short extraout_var;
  int *piVar3;
  short extraout_var_00;
  undefined4 *unaff_EDI;
  undefined4 uVar2;
  
  rendering_getSpriteCount(param_1);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while (sVar1 != 0) {
    piVar3 = (int *)rendering_resolveState(*(int *)(in_EAX + 0xc),uVar2);
    if ((((piVar3 != (int *)0x0) && (piVar3[2] != 0)) && (param_2 != 0)) &&
       (*(undefined1 *)(piVar3 + 0xe) = 0, unaff_EDI != (undefined4 *)0x0)) {
      rendering_getMediaFormat((byte *)*unaff_EDI,piVar3);
    }
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  rendering_clearSpriteFields(in_EAX);
  return 0;
}



// ============================================================
// Function: rendering_serializeMemberData (FUN_680ca940)
// Address: 680ca940
// Size: 441 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_serializeMemberData(int param_1,int param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30;
  code *local_2c;
  code *local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 *local_c;
  int local_8;
  
  iVar5 = 0;
  local_1c = 0;
  local_c = (undefined4 *)0x0;
  local_18 = 0;
  local_24 = 0;
  local_8 = 0;
  local_30 = -1;
  local_28 = (code *)0x0;
  local_2c = (code *)0x0;
  if (param_2 == 0) {
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
    local_10 = (int *)*param_3;
    iVar4 = *local_10;
    local_20 = param_3[0xf];
    pcVar1 = *(code **)(*(int *)(iVar4 + 0xc) + 0xd0);
    local_2c = pcVar1;
  }
  else {
    local_10 = *(int **)(*(int *)(param_2 + 4) + 8);
    iVar4 = *local_10;
    pcVar1 = *(code **)(*(int *)(iVar4 + 0xc) + 0xcc);
    local_20 = 0x400;
    local_28 = pcVar1;
  }
  if (pcVar1 == (code *)0x0) {
    return 1;
  }
  local_14 = local_20;
  while( true ) {
    if (param_2 == 0) {
      iVar2 = (*local_2c)(iVar4,*(undefined2 *)(param_3 + 1),iVar5,&local_8,&local_24,0,&local_18);
    }
    else {
      iVar2 = (*local_28)(iVar4,*(undefined4 *)(*(int *)(param_2 + 4) + 4),iVar5,&local_8,&local_24,
                          0,&local_18);
    }
    if (iVar2 == 0) break;
    if ((local_18 != 0) && (iVar2 = lingo_getMovieRef((int)local_10), iVar2 != 0)) {
      lingo_formatDebugMsg(local_10,local_18);
      goto LAB_680caade;
    }
    if (local_8 == local_30) {
      local_14 = local_14 + 1;
    }
    else {
      local_14 = local_20;
    }
    local_c = (undefined4 *)rendering_applyScoreData(param_3,iVar5,local_24);
    iVar2 = local_14;
    if (local_c == (undefined4 *)0x0) {
      return local_1c;
    }
    iVar3 = strings_readMediaChunk(*(int *)(param_1 + 4),local_8,local_14);
    if (iVar3 == -1) goto LAB_680caade;
    iVar2 = strings_writeOrRemoveBlock(*(int *)(param_1 + 4),local_8,iVar2,local_c,0);
    if (iVar2 != 0) {
      rendering_getSpriteScoreState();
      goto LAB_680caade;
    }
    iVar2 = lingo_getMovieRef((int)local_10);
    local_30 = local_8;
    if (iVar2 != 0) goto LAB_680caade;
    iVar5 = iVar5 + 1;
    if (local_c != (undefined4 *)0x0) {
      Ordinal_1113(&local_c);
    }
  }
  local_1c = 1;
LAB_680caade:
  if (local_c != (undefined4 *)0x0) {
    Ordinal_1113(&local_c);
  }
  return local_1c;
}



// ============================================================
// Function: rendering_saveCastData (FUN_680cab00)
// Address: 680cab00
// Size: 177 bytes
// Params: undefined * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_saveCastData(undefined *param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  undefined4 local_14;
  undefined4 local_8;
  
  iVar3 = *(int *)(*(int *)(in_EAX + 4) + 8);
  local_14 = 0;
  local_8 = 0;
  iVar1 = rendering_updateSpriteScore(0x400,unaff_EBX,0);
  if (iVar1 != -1) {
    iVar2 = (*(code *)param_1)();
    if (iVar2 != 0) {
      iVar1 = playback_processScoreEntry(*(undefined4 *)(unaff_EBX + 4),iVar1,0xffffffff,&local_8);
      if (iVar1 != 0) {
        rendering_getSpriteScoreCount();
        Ordinal_1407(&local_8);
        return 0;
      }
      iVar1 = (*(code *)param_1)();
      if (iVar1 != 0) {
        iVar3 = lingo_getMovieRef(iVar3);
        if (iVar3 == 0) {
          local_14 = 1;
        }
      }
    }
  }
  Ordinal_1407(&local_8);
  return local_14;
}



// ============================================================
// Function: rendering_initCastSave (FUN_680cabc0)
// Address: 680cabc0
// Size: 179 bytes
// Params: undefined * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_initCastSave(undefined *param_1)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  undefined4 local_14;
  undefined4 local_8;
  
  iVar3 = *in_EAX;
  local_14 = 0;
  local_8 = 0;
  iVar1 = rendering_updateSpriteScore(in_EAX[0xf],unaff_EBX,0);
  if (iVar1 != -1) {
    iVar2 = (*(code *)param_1)();
    if (iVar2 != 0) {
      iVar1 = playback_processScoreEntry(*(undefined4 *)(unaff_EBX + 4),iVar1,0xffffffff,&local_8);
      if (iVar1 != 0) {
        rendering_getSpriteScoreCount();
        Ordinal_1407(&local_8);
        return 0;
      }
      iVar1 = (*(code *)param_1)();
      if (iVar1 != 0) {
        iVar3 = lingo_getMovieRef(iVar3);
        if (iVar3 == 0) {
          local_14 = 1;
        }
      }
    }
  }
  Ordinal_1407(&local_8);
  return local_14;
}



// ============================================================
// Function: rendering_persistCastMember (FUN_680cac80)
// Address: 680cac80
// Size: 383 bytes
// Params: void * this, undefined4 param_1, int param_2, int param_3, int param_4, uint param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall
rendering_persistCastMember(void *this,undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,
            undefined4 param_6)

{
  int *piVar1;
  code *pcVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)this;
  local_8 = 0;
  local_c = 0;
  iVar3 = media_getDataPtr((int *)piVar1[1]);
  if (*(code **)(iVar3 + 0xac) != (code *)0x0) {
    (**(code **)(iVar3 + 0xac))(*(undefined2 *)((int)this + 4),1);
  }
  iVar4 = rendering_initCastSave(bitmap_writeLinkedFileData);
  if ((((iVar4 != 0) && (iVar4 = display_saveSpriteChannels(this,in_EAX,param_1,param_4,param_5), iVar4 != 0)) &&
      (iVar4 = lingo_getMovieRef((int)piVar1), iVar4 == 0)) &&
     (((*(int *)((int)this + 0x48) == 0 ||
       (((iVar4 = strings_openMediaStream(*(int *)(in_EAX + 4),FOURCC_LctX,*(int *)((int)this + 0x3c)),
         iVar4 != -1 &&
         (local_c = stage_dispatchSpritePrev(param_2,*(int *)((int)this + 0x48),*(int *)(in_EAX + 4),iVar4,
                                 param_3), local_c == 0)) &&
        (iVar4 = lingo_getMovieRef((int)piVar1), iVar4 == 0)))) &&
      (((iVar4 = rendering_initCastSave(bitmap_writeChannelScore), iVar4 != 0 &&
        (iVar4 = rendering_initCastSave(playback_processSpriteRegion), iVar4 != 0)) &&
       (iVar4 = rendering_serializeMemberData(in_EAX,0,this), iVar4 != 0)))))) {
    local_8 = 1;
  }
  pcVar2 = *(code **)(iVar3 + 0xb4);
  while (pcVar2 != (code *)0x0) {
    param_4 = 0;
    (*pcVar2)(*piVar1,*(undefined2 *)((int)this + 4),0xfffffffe,0,0,0,&param_4);
    if ((param_4 == 0) || (iVar4 = lingo_getMovieRef((int)piVar1), iVar4 == 0)) break;
    lingo_formatDebugMsg(piVar1,param_4);
    pcVar2 = *(code **)(iVar3 + 0xb4);
  }
  if (*(code **)(iVar3 + 0xac) != (code *)0x0) {
    (**(code **)(iVar3 + 0xac))(*(undefined2 *)((int)this + 4),0);
  }
  if (local_c != 0) {
    rendering_getSpriteScoreState();
  }
  return local_8;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cae00 - 0x680cb150
// Functions (3):
//   rendering_saveCastEntry
//   rendering_saveMovieData
//   rendering_saveMovieCast

// ============================================================
// Function: rendering_saveCastEntry (FUN_680cae00)
// Address: 680cae00
// Size: 616 bytes
// Params: uint param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_saveCastEntry(uint param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = *param_2;
  local_14 = (uint)(param_4 != 1);
  pvVar4 = (void *)(param_1 & 1);
  local_10 = 0;
  local_8 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_18 = pvVar4;
  if (((0x79e < (short)param_2[0x23]) || (local_14 != 0)) &&
     (iVar1 = rendering_restoreScoreState(param_2,in_EAX,param_5), iVar1 != 0)) {
    local_30 = CONCAT22((*(unsigned short *)((char *)&local_30 + 2)),(short)param_2[1]);
    local_48 = local_c;
    rendering_markSaveFlags(&local_54,(int)in_EAX,2,local_14);
    iVar1 = rendering_prepareSaveSprites(local_c,0,param_3,param_4,2,pvVar4);
    if (iVar1 != 0) {
      if (in_EAX == (undefined4 *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = in_EAX[2];
      }
      iVar1 = rendering_saveCastResources(param_3,iVar1,param_4,pvVar4);
      if ((((iVar1 != 0) &&
           ((local_14 == 0 || (local_8 = Ordinal_21(*(int *)(param_3 + 4)), local_8 == 0)))) &&
          (local_8 = strings_readKeyTable(*(int *)(param_3 + 4)), local_8 == 0)) &&
         (iVar1 = rendering_initCastSave(bitmap_writeScoreHeaderAlt), iVar1 != 0)) {
        uVar2 = 0;
        iVar1 = 0;
        local_28 = (undefined4 *)0x0;
        local_24 = 0;
        local_20 = 0;
        local_1c = 0;
        if (in_EAX == (undefined4 *)0x0) {
          iVar5 = 0;
        }
        else {
          local_28 = in_EAX + 0x143;
          uVar3 = scoreEngine_getChannelRange((int)in_EAX,(short)param_2[1],0);
          if ((short)uVar3 != -1) {
            iVar1 = scoreEngine_getFrameData((int)in_EAX,(short)uVar3);
          }
          iVar5 = in_EAX[2];
          uVar2 = *in_EAX;
        }
        iVar1 = rendering_persistCastMember(param_2,uVar2,iVar5,param_4,(int)&local_28,(uint)local_18,iVar1);
        if (iVar1 != 0) {
          iVar1 = rendering_iterateSaveCast(param_3,(int)local_18);
          if ((iVar1 != 0) && (iVar1 = rendering_restoreSpriteState((int)&local_54), iVar1 != 0)) {
            rendering_writeCastData(2,1);
            param_2[6] = 0;
            local_10 = 1;
            goto LAB_680cafea;
          }
        }
      }
    }
  }
  rendering_writeCastData(2,0);
  if (local_8 == 0) {
    local_8 = -1;
  }
LAB_680cafea:
  if (param_2[0x12] != 0) {
    if (in_EAX == (undefined4 *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = in_EAX[2];
    }
    stage_dispatchSpriteNext(iVar1,param_2[0x12],*(undefined4 *)(param_3 + 4),param_4,local_8);
  }
  iVar1 = local_10;
  if (local_10 != 0) {
    param_3 = playback_loadScoreData(param_3);
    Ordinal_1105();
  }
  if (param_3 == 0) {
    if (local_8 == 0) {
      return iVar1;
    }
    rendering_getSpriteScoreState();
    return local_10;
  }
  rendering_getSpriteScoreCount();
  return local_10;
}



// ============================================================
// Function: rendering_saveMovieData (FUN_680cb070)
// Address: 680cb070
// Size: 221 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_saveMovieData(undefined4 *param_1,int param_2)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_28 = *(undefined4 *)(*(int *)(in_EAX + 4) + 8);
  sVar3 = 1;
  uVar4 = 0;
  local_8 = 0;
  if (0 < *(short *)(in_EAX + 0x478)) {
    do {
      piVar1 = (int *)scoreEngine_getChannelField(in_EAX,sVar3);
      if (piVar1 != (int *)0x0) {
        if (piVar1[5] == 0) {
          rendering_initSpriteScore();
          uVar4 = local_8;
        }
        else {
          iVar2 = rendering_restoreScoreState(piVar1,in_EAX,(undefined4 *)0x0);
          if (iVar2 == 0) {
            return uVar4;
          }
        }
      }
      sVar3 = sVar3 + 1;
    } while (sVar3 <= *(short *)(in_EAX + 0x478));
  }
  iVar2 = rendering_resolveAllSprites((int)&local_34);
  if ((((iVar2 != 0) && (iVar2 = rendering_iterateSpriteDispatch(&local_34,1), iVar2 != 0)) &&
      (iVar2 = rendering_configureScoreLayout(param_2), iVar2 != 0)) &&
     ((iVar2 = rendering_serializeScoreData(in_EAX,param_1), iVar2 != 0 && (iVar2 = rendering_validateAllSprites(), iVar2 != 0)))) {
    return 1;
  }
  return uVar4;
}



// ============================================================
// Function: rendering_saveMovieCast (FUN_680cb150)
// Address: 680cb150
// Size: 1129 bytes
// Params: void * this, int param_1, int param_2, undefined4 * param_3
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_saveMovieCast(void *this,int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *this_00;
  uint uVar4;
  int *piVar5;
  short sVar6;
  undefined4 *puVar7;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int *local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  code *local_20;
  void *local_1c;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  uint local_c;
  int local_8;
  
  local_14 = 0;
  uVar4 = (uint)(param_2 != 1);
  local_8 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = (int *)0x0;
  local_50 = (undefined4 *)0x0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  piVar5 = *(int **)(in_EAX[1] + 8);
  local_1c = (void *)((uint)this & 1);
  local_24 = *piVar5;
  local_20 = *(code **)(*(int *)(local_24 + 0xc) + 0xcc);
  local_c = (uint)(local_1c != (void *)0x0);
  if (in_EAX[0x1a2] != 0) {
    local_c = local_c | 2;
  }
  local_10 = piVar5;
  if ((0x79e < *(short *)(in_EAX + 300)) || (uVar4 != 0)) {
    if (local_20 == (code *)0x0) {
LAB_680cb2d4:
      iVar1 = rendering_saveMovieData(param_3,(int)local_1c);
      if (iVar1 != 0) {
        if (uVar4 != 0) {
          local_4c = in_EAX[0x120];
        }
        param_3 = (undefined4 *)(uint)(uVar4 == 0);
        local_54 = piVar5;
        local_50 = in_EAX;
        rendering_markSaveFlags(&local_60,(int)in_EAX,1,uVar4);
        iVar1 = rendering_prepareSaveSprites((int)local_10,(int)in_EAX,param_1,param_2,1,local_1c);
        if (((((iVar1 != 0) &&
              (((uVar4 == 0 || (local_8 = Ordinal_21(*(int *)(param_1 + 4)), local_8 == 0)) &&
               (local_8 = strings_readKeyTable(*(int *)(param_1 + 4)), local_8 == 0)))) &&
             (((iVar1 = rendering_saveCastData(bitmap_writeScoreHeaderEx), iVar1 != 0 &&
               (iVar1 = rendering_saveCastData(bitmap_writePaletteData), iVar1 != 0)) &&
              (iVar1 = rendering_saveCastData(playback_getFontMapRawData), iVar1 != 0)))) &&
            ((iVar1 = rendering_saveCastData(media_serializeCastLib), iVar1 != 0 &&
             (iVar1 = rendering_saveCastData(bitmap_writeCastLibData), iVar1 != 0)))) &&
           (iVar1 = rendering_serializeMemberData(param_1,(int)in_EAX,(undefined4 *)0x0), iVar1 != 0)) {
          sVar6 = 1;
          local_34 = in_EAX + 0x143;
          local_30 = 0;
          local_2c = 0;
          local_28 = 0;
          if (0 < *(short *)(in_EAX + 0x11e)) {
            do {
              this_00 = (void *)scoreEngine_getChannelField((int)in_EAX,sVar6);
              iVar1 = scoreEngine_getFrameData((int)in_EAX,sVar6);
              if (((this_00 != (void *)0x0) && (*(int *)((int)this_00 + 0x14) != 0)) &&
                 (iVar1 = rendering_persistCastMember(this_00,*in_EAX,in_EAX[2],param_2,(int)&local_34,local_c,
                                       iVar1), iVar1 == 0)) goto LAB_680cb22b;
              sVar6 = sVar6 + 1;
            } while (sVar6 <= *(short *)(in_EAX + 0x11e));
          }
          iVar1 = rendering_saveCastData(bitmap_writeCastFlags);
          if ((((iVar1 != 0) && (iVar1 = rendering_saveCastData(bitmap_applyScoreLayout), iVar1 != 0)) &&
              ((iVar1 = rendering_saveCastData(bitmap_writeMemberBuffer), iVar1 != 0 &&
               ((iVar1 = rendering_saveCastData(bitmap_writeStyleRunData), iVar1 != 0 &&
                (iVar1 = rendering_saveCastData(bitmap_writeRegPoints), iVar1 != 0)))))) &&
             (iVar1 = rendering_saveCastData(bitmap_writeAltStyleRun), iVar1 != 0)) {
            iVar1 = rendering_iterateSaveCast(param_1,(int)local_1c);
            if ((iVar1 != 0) && (iVar1 = rendering_restoreSpriteState((int)&local_60), iVar1 != 0)) {
              rendering_writeCastData(1,1);
              if (local_20 != (code *)0x0) {
                param_3 = (undefined4 *)0x0;
                (*local_20)(local_24,*(undefined4 *)(in_EAX[1] + 4),0xfffffffe,0,0,0,&param_3);
                piVar5 = local_10;
                if ((param_3 != (undefined4 *)0x0) &&
                   (iVar1 = lingo_getMovieRef((int)local_10), puVar7 = param_3, iVar1 != 0))
                goto LAB_680cb21f;
              }
              in_EAX[0x2e9] = 0;
              in_EAX[0x116] = 0;
              local_14 = 1;
              goto LAB_680cb244;
            }
          }
        }
      }
    }
    else {
      local_18 = (undefined4 *)0x0;
      (*local_20)(local_24,*(undefined4 *)(in_EAX[1] + 4),0xffffffff,0,0,0,&local_18);
      if ((local_18 == (undefined4 *)0x0) ||
         (iVar1 = lingo_getMovieRef((int)piVar5), puVar7 = local_18, iVar1 == 0)) goto LAB_680cb2d4;
LAB_680cb21f:
      lingo_formatDebugMsg(piVar5,(int)puVar7);
    }
  }
LAB_680cb22b:
  rendering_writeCastData(1,0);
  if (local_8 == 0) {
    local_8 = -1;
  }
LAB_680cb244:
  sVar6 = 1;
  if (0 < *(short *)(in_EAX + 0x11e)) {
    do {
      iVar1 = scoreEngine_getChannelField((int)in_EAX,sVar6);
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) && (*(int *)(iVar1 + 0x48) != 0)) {
        stage_dispatchSpriteNext(in_EAX[2],*(int *)(iVar1 + 0x48),*(undefined4 *)(param_1 + 4),param_2,local_8);
      }
      sVar6 = sVar6 + 1;
    } while (sVar6 <= *(short *)(in_EAX + 0x11e));
  }
  iVar1 = local_14;
  if (local_14 != 0) {
    iVar2 = playback_loadScoreData(param_1);
    Ordinal_1105();
    uVar3 = rendering_updateChannelState((int)(in_EAX + 0x123));
    in_EAX[0x140] = uVar3;
    if (iVar2 != 0) {
      rendering_getSpriteScoreCount();
      return local_14;
    }
  }
  if (local_8 != 0) {
    rendering_getSpriteScoreState();
    return local_14;
  }
  return iVar1;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cb5c0 - 0x680cbe30
// Functions (8):
//   rendering_readCastData
//   rendering_saveCastMember
//   rendering_initSaveBuffer
//   rendering_growSaveBuffer
//   rendering_appendSaveBuffer
//   rendering_freeSaveBuffer
//   rendering_getStageRef
//   rendering_checkSaveVersion

// ============================================================
// Function: rendering_readCastData (FUN_680cb5c0)
// Address: 680cb5c0
// Size: 1761 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_readCastData(int param_1,int *param_2,undefined4 *param_3,void *param_4)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_c80 [7];
  uint local_c64;
  uint local_c60;
  int *local_c5c;
  int *local_c58;
  int local_c54;
  uint local_c50;
  int *local_c4c;
  undefined4 *local_c48;
  int *local_c44;
  int *local_c40;
  undefined4 *local_c3c;
  undefined4 local_c38;
  undefined1 local_c34 [1044];
  undefined4 local_820;
  undefined1 local_81c [1044];
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar5 = 0;
  local_c54 = param_1;
  local_c58 = param_2;
  local_c3c = param_3;
  local_c80[5] = 0;
  local_c38 = 0;
  memset(local_c34,0,0x414);
  local_820 = 0;
  memset(local_81c,0,0x414);
  local_c80[0] = 0;
  local_c64 = (uint)(local_c58 != (int *)0x0);
  local_c80[1] = 0;
  local_c80[2] = 0;
  local_c80[3] = 0;
  local_c5c = (int *)0x0;
  local_c60 = 0;
  local_c80[4] = 0;
  local_c80[6] = (uint)param_4 & 4;
  local_c50 = (uint)param_4 & 2;
  local_c48 = (undefined4 *)0x0;
  local_c44 = (int *)0x0;
  local_c40 = (int *)0x0;
  if (local_c64 == 0) {
    Ordinal_4102(*(int *)(param_1 + 8));
    local_c4c = *(int **)(*(int *)(param_1 + 4) + 8);
    local_c48 = (undefined4 *)(param_1 + 0x28);
    local_c44 = (int *)(param_1 + 0xc);
    local_c40 = (int *)(param_1 + 0x1c);
LAB_680cb6cc:
    piVar6 = local_c4c;
    iVar2 = lingo_getMovieRef((int)local_c4c);
    if (iVar2 != 0) {
      lingo_updateState((int)piVar6);
    }
    if (param_3 != (undefined4 *)0x0) {
      local_408 = 0;
      memset(local_407,0,0x3fe);
      Ordinal_1310(param_3,&local_408,0x3ff);
      uVar3 = Ordinal_1313(param_3);
      iVar2 = Ordinal_1311(&local_408,uVar3);
      iVar4 = 0x106;
      puVar7 = &local_820;
      if (iVar2 == 0) {
        puVar7 = local_c48;
        puVar8 = &local_820;
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        Ordinal_1316(&local_820);
        Ordinal_1318(&local_820,&local_408);
      }
      else {
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *param_3;
          param_3 = param_3 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      iVar2 = Ordinal_1319(&local_820,local_c48);
      param_3 = (undefined4 *)0x0;
      if (iVar2 == 0) {
        param_3 = local_c3c;
      }
    }
    local_c60 = (uint)(param_3 != (undefined4 *)0x0);
    if ((param_3 != (undefined4 *)0x0) == 0) {
      if (local_c44[2] == 1) {
        iVar2 = -0x1c4;
        goto LAB_680cb7f0;
      }
      puVar7 = local_c48;
      puVar8 = &local_820;
      for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      if ((*local_c40 != 0) || (local_c5c = local_c44, local_c44[1] == 0)) goto LAB_680cb7ff;
      iVar5 = 1;
      piVar6 = local_c44;
LAB_680cb9a2:
      iVar2 = 0;
      local_c5c = piVar6;
      if (((int *)piVar6[1] == (int *)0x0) ||
         ((iVar4 = *(int *)piVar6[1], iVar4 != FOURCC_FGDM && (iVar4 != FOURCC_FGDC)))) {
        iVar4 = local_c4c[1];
        piVar1 = (int *)(iVar4 + 0x1c);
        *piVar1 = *piVar1 + 1;
        if (local_c64 == 0) {
          iVar2 = rendering_saveMovieCast(param_4,(int)piVar6,iVar5,&local_820);
        }
        else {
          iVar2 = rendering_saveCastEntry((uint)param_4,local_c58,(int)piVar6,iVar5,&local_820);
        }
        piVar1 = (int *)(iVar4 + 0x1c);
        *piVar1 = *piVar1 + -1;
      }
      iVar5 = playback_openScoreEx(piVar6);
      if (iVar5 == 0) {
        if (iVar2 != 0) {
          if (local_c60 == 0) {
            if (local_c50 == 0) {
LAB_680cbb48:
              if (local_c64 == 0) {
                local_c3c = (undefined4 *)
                            ((-(uint)(((uint)param_4 & 1) != 0) & 0xf6cb0000) + FOURCC_MV12);
              }
              else {
                local_c3c = (undefined4 *)
                            ((-(uint)(((uint)param_4 & 1) != 0) & 0xffe70000) + FOURCC_DC12);
              }
              Ordinal_1360(&local_820,2,&local_c3c);
              local_c3c = (undefined4 *)FOURCC_MD08;
              Ordinal_1360(&local_820,3,&local_c3c);
              iVar5 = playback_createScoreContext((int)local_c4c,local_c44,local_c48,*local_c40,(void *)0x0);
              if (iVar5 != 0) goto LAB_680cb7ff;
            }
          }
          else if (local_c50 == 0) {
            if (local_c80[6] != 0) {
              iVar5 = playback_openScoreEx(local_c44);
              if (iVar5 != 0) goto LAB_680cb7ff;
              puVar7 = local_c48;
              puVar8 = &local_820;
              for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar8 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar8 = puVar8 + 1;
              }
            }
            iVar2 = Ordinal_1351(&local_820);
            if (iVar2 == 0) {
              local_c54 = iVar2;
              iVar2 = Ordinal_1401(&local_c54,&local_820,0xffffffff);
              if (iVar2 == 0) goto LAB_680cb7ff;
              Ordinal_1407(&local_c54);
            }
            iVar2 = Ordinal_1354(&local_820,&local_c38);
            if ((iVar2 != 0) && (iVar2 = Ordinal_1352(&local_c38), iVar2 != 0)) {
              if (local_c80[6] == 0) {
                iVar5 = playback_openScoreEx(local_c44);
                puVar7 = &local_820;
                puVar8 = local_c48;
                for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
                  *puVar8 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar8 = puVar8 + 1;
                }
              }
              *local_c40 = 0;
              if (iVar5 == 0) goto LAB_680cbb48;
            }
            goto LAB_680cb7ff;
          }
          local_c80[5] = 1;
          goto LAB_680cbc2d;
        }
        if (local_c60 != 0) {
          Ordinal_1352(&local_c38);
        }
      }
    }
    else {
      iVar2 = Ordinal_1402(&local_c3c,&local_820,3);
      if (iVar2 == 0) {
        if (local_c50 == 0) {
          iVar2 = Ordinal_1401(&local_c3c,&local_820,0xffffffff);
          if (iVar2 != 0) {
            Ordinal_1407(&local_c3c);
            Ordinal_1352(&local_820);
            goto LAB_680cb90e;
          }
          iVar2 = -0x1c3;
        }
        else {
          iVar2 = -0x1c2;
        }
LAB_680cb7f0:
        lingo_formatDebugMsg(local_c4c,iVar2);
      }
      else {
LAB_680cb90e:
        Ordinal_1407(&local_c3c);
        puVar7 = &local_820;
        puVar8 = &local_c38;
        for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        if (((local_c50 != 0) ||
            ((iVar2 = Ordinal_1316(&local_c38), iVar2 != 0 &&
             (iVar2 = Ordinal_1356(&local_c38,0,0), iVar2 != 0)))) &&
           (iVar5 = playback_applyScoreDefaults(local_c4c,local_c80,&local_c38,(uint)param_4 & 1,local_c50),
           iVar5 == 0)) {
          piVar6 = local_c80;
          local_c5c = piVar6;
          iVar5 = 2;
          goto LAB_680cb9a2;
        }
      }
    }
  }
  else {
    local_c4c = (int *)*local_c58;
    if (local_c58[5] == 0) {
      local_c48 = (undefined4 *)Ordinal_1114(local_c58[0xc]);
      local_c44 = local_c58 + 8;
      local_c40 = local_c80 + 4;
      goto LAB_680cb6cc;
    }
  }
LAB_680cb7ff:
  if (local_c44 != (int *)0x0) {
    if (local_c60 == 0) {
      playback_openScoreEx(local_c44);
      iVar5 = playback_createScoreContext((int)local_c4c,local_c44,local_c48,*local_c40,(void *)0x0);
    }
    else {
      if ((local_c5c != (int *)0x0) && (local_c5c[1] != 0)) {
        playback_openScoreEx(local_c5c);
      }
      iVar2 = Ordinal_1351(&local_c38);
      if ((iVar2 != 0) && (local_c50 == 0)) {
        Ordinal_1352(&local_c38);
      }
    }
  }
LAB_680cbc2d:
  if (iVar5 != 0) {
    rendering_getSpriteScoreCount();
  }
  piVar6 = local_c4c;
  if ((local_c80[5] == 0) && (iVar5 = lingo_getMovieRef((int)local_c4c), iVar5 == 0)) {
    lingo_formatDebugMsg(piVar6,-0x1c2);
  }
  Ordinal_1042();
  if ((local_c64 != 0) && (local_c48 != (undefined4 *)0x0)) {
    Ordinal_1115(local_c58[0xc]);
  }
  return 0;
}



// ============================================================
// Function: rendering_saveCastMember (FUN_680cbcb0)
// Address: 680cbcb0
// Size: 127 bytes
// Params: int param_1, undefined4 * param_2, int param_3, void * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_saveCastMember(int param_1,undefined4 *param_2,int param_3,void *param_4)

{
  int iVar1;
  int *piVar2;
  short sVar3;
  bool bVar4;
  
  iVar1 = rendering_readCastData(param_1,(int *)0x0,param_2,param_4);
  bVar4 = iVar1 != 0;
  if (param_3 != 0) {
    sVar3 = 1;
    if (0 < *(short *)(param_1 + 0x478)) {
      do {
        piVar2 = (int *)scoreEngine_getChannelField(param_1,sVar3);
        if (((piVar2 != (int *)0x0) && (piVar2[5] == 0)) &&
           (iVar1 = rendering_readCastData(param_1,piVar2,(undefined4 *)0x0,param_4), iVar1 == 0)) {
          bVar4 = false;
        }
        sVar3 = sVar3 + 1;
      } while (sVar3 <= *(short *)(param_1 + 0x478));
    }
    return bVar4;
  }
  return bVar4;
}



// ============================================================
// Function: rendering_initSaveBuffer (FUN_680cbd30)
// Address: 680cbd30
// Size: 49 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_initSaveBuffer(void)

{
  int iVar1;
  int *unaff_ESI;
  
  unaff_ESI[3] = 0;
  unaff_ESI[2] = 100;
  iVar1 = Ordinal_1111(0x640,1);
  *unaff_ESI = iVar1;
  if (iVar1 != 0) {
    iVar1 = Ordinal_1114(iVar1);
    unaff_ESI[1] = iVar1;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_growSaveBuffer (FUN_680cbd70)
// Address: 680cbd70
// Size: 64 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_growSaveBuffer(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  if ((int)unaff_ESI[2] <= in_EAX) {
    uVar1 = Ordinal_1115(*unaff_ESI);
    unaff_ESI[2] = in_EAX;
    unaff_ESI[1] = uVar1;
    iVar2 = Ordinal_1117();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = Ordinal_1114(*unaff_ESI);
    unaff_ESI[1] = uVar1;
  }
  return 1;
}



// ============================================================
// Function: rendering_appendSaveBuffer (FUN_680cbdb0)
// Address: 680cbdb0
// Size: 79 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_appendSaveBuffer(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if ((*in_EAX == 0) && (iVar1 = rendering_initSaveBuffer(), iVar1 == 0)) {
    return 0;
  }
  iVar1 = rendering_growSaveBuffer();
  if (iVar1 == 0) {
    return 0;
  }
  Ordinal_1129(in_EAX[3] * 0x10 + in_EAX[1],*(undefined4 *)(unaff_EDI + 4),
               *(int *)(unaff_EDI + 0xc) << 4);
  in_EAX[3] = in_EAX[3] + *(int *)(unaff_EDI + 0xc);
  return 1;
}



// ============================================================
// Function: rendering_freeSaveBuffer (FUN_680cbe00)
// Address: 680cbe00
// Size: 26 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_freeSaveBuffer(void)
{
  int *unaff_ESI;
  
  if (*unaff_ESI != 0) {
    Ordinal_1115(*unaff_ESI);
    unaff_ESI[1] = 0;
    Ordinal_1113();
  }
  return 0;
}



// ============================================================
// Function: rendering_getStageRefById (FUN_680cbe20)
// Address: 680cbe20
// Size: 8 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageRef(void)
{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xc) = 0;
  return 0;
}



// ============================================================
// Function: rendering_checkSaveVersion (FUN_680cbe30)
// Address: 680cbe30
// Size: 48 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_checkSaveVersion(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  
  lingo_getObjectField114(unaff_EBX);
  iVar1 = Ordinal_1609();
  lingo_getObjectField118(unaff_EBX);
  iVar2 = Ordinal_1611();
  if (iVar2 == 0) {
    return false;
  }
  return iVar1 != 0;
}



