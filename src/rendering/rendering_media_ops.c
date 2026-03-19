// Module: rendering
// Topic: Media loading, streaming, member creation/deletion, and cast operations
// Address range: 0x680c5BF0 - 0x680c7AF0
// Functions (27):
//   rendering_getMediaRef
//   rendering_getMediaState
//   rendering_openMediaStreams
//   rendering_closeMediaStreams
//   rendering_writeMediaBlock
//   rendering_readMediaBlock
//   rendering_resolveMediaSource
//   rendering_compositeMedia
//   rendering_blendMedia
//   rendering_blendMediaEx
//   rendering_updateMemberMedia
//   rendering_updateMemberMediaEx
//   rendering_replaceMediaData
//   rendering_processMediaOp
//   rendering_updateMediaRef
//   rendering_loadMediaData
//   rendering_addSpriteMedia
//   rendering_removeSpriteMedia
//   rendering_loadMediaBlock
//   rendering_processMediaBlock
//   rendering_setMemberMediaProperty
//   rendering_getMediaInfo
//   rendering_swapSpriteMedia
//   rendering_getMediaFormat
//   rendering_scanMediaFormat
//   rendering_blitMedia
//   rendering_checkMediaOverlay

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c5bf0 - 0x680c6120
// Functions (8):
//   rendering_getMediaRef
//   rendering_getMediaState
//   rendering_openMediaStreams
//   rendering_closeMediaStreams
//   rendering_writeMediaBlock
//   rendering_readMediaBlock
//   rendering_resolveMediaSource
//   rendering_compositeMedia

// ============================================================
// Function: rendering_getMediaRef (FUN_680c5bf0)
// Address: 680c5bf0
// Size: 165 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMediaRef(int param_1,uint param_2)
{
  undefined4 uVar1;
  int iVar2;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = (int *)0x0;
  if ((*(int *)(param_1 + 0x28) != 0) && ((param_2 & 0xffff) == param_2)) {
    uVar1 = Ordinal_1038(&DAT_68176518,&DAT_68176528,&local_40c);
    iVar2 = Ordinal_2063(uVar1);
    if ((iVar2 == 0) &&
       (iVar2 = (**(code **)(*local_40c + 0x10))(local_40c,param_2 & 0xffff,0x3ff,local_408),
       iVar2 == 0)) {
      rendering_setMemberSlot(param_1,local_408);
    }
    if (local_40c != (int *)0x0) {
      (**(code **)(*local_40c + 8))(local_40c);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getMediaState (FUN_680c5ca0)
// Address: 680c5ca0
// Size: 175 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMediaState(int param_1)
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_410;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = (int *)0x0;
  local_410 = 0;
  uVar1 = rendering_extractMemberSlot(param_1,0x3ff,(int)local_408);
  if (uVar1 != 0) {
    uVar2 = Ordinal_1038(&DAT_68176518,&DAT_68176528,&local_40c);
    iVar3 = Ordinal_2063(uVar2);
    if (iVar3 == 0) {
      (**(code **)(*local_40c + 0xc))(local_40c,local_408,&local_410);
    }
  }
  if (local_40c != (int *)0x0) {
    (**(code **)(*local_40c + 8))(local_40c);
  }
  return 0;
}



// ============================================================
// Function: rendering_openMediaStreams (FUN_680c5d50)
// Address: 680c5d50
// Size: 155 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_openMediaStreams(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  int iVar5;
  undefined4 local_c;
  int *local_8;
  
  iVar5 = 0;
  local_8 = (int *)0x0;
  local_c = 0;
  uVar1 = rendering_getStateCount((int)unaff_ESI);
  if ((uVar1 == 0) && ((unaff_ESI[0xb] & 0x800U) == 0)) {
    iVar2 = rendering_validateState(unaff_ESI);
    if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) goto LAB_680c5dd9;
    iVar3 = rendering_getMemberProperty(unaff_ESI,0,(int *)&local_8);
    if (0 < iVar3) {
      do {
        iVar4 = strings_openMediaStream(iVar2,*(int *)(*local_8 + iVar5 * 4),unaff_ESI[3]);
        if (iVar4 != -1) {
          iVar4 = crt_queueChunkCallback(iVar2,iVar4,*(undefined4 *)(*(int *)(*unaff_ESI + 0x350) + 0x20));
          if (iVar4 != 0) goto LAB_680c5dd9;
          unaff_ESI[0xb] = unaff_ESI[0xb] | 0x800;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
  }
  local_c = 1;
LAB_680c5dd9:
  Ordinal_1113(&local_8);
  return local_c;
}



// ============================================================
// Function: rendering_closeMediaStreams (FUN_680c5df0)
// Address: 680c5df0
// Size: 125 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_closeMediaStreams(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  int iVar4;
  int *local_8;
  
  iVar4 = 0;
  local_8 = (int *)0x0;
  if (((*(int *)(*(int *)*unaff_EBX + 0x10) != 0) && (unaff_EBX[2] != 0)) &&
     (iVar1 = rendering_getMemberProperty(unaff_EBX,0,(int *)&local_8), iVar1 != 0)) {
    if (0 < iVar1) {
      do {
        iVar2 = rendering_validateState(unaff_EBX);
        if ((iVar2 != 0) &&
           (iVar3 = strings_openMediaStream(*(int *)(iVar2 + 4),*(int *)(*local_8 + iVar4 * 4),unaff_EBX[3]),
           iVar3 != -1)) {
          crt_insertAndClearSlot(*(int *)(iVar2 + 4),iVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    unaff_EBX[0xb] = unaff_EBX[0xb] & 0xfffff7ff;
  }
  Ordinal_1113(&local_8);
  return 0;
}



// ============================================================
// Function: rendering_writeMediaBlock (FUN_680c5e70)
// Address: 680c5e70
// Size: 190 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeMediaBlock(undefined4 param_1,int *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_318 [196];
  uint local_8;
  
  iVar1 = *param_2;
  lingo_executeMethod(iVar1,local_318);
  uVar3 = Ordinal_1140(0);
  uVar2 = *(undefined4 *)(iVar1 + 0x368);
  *(undefined4 *)(iVar1 + 0x368) = 1;
  if (((param_3 == 0) || (iVar4 = rendering_openMediaStreams(), iVar4 == 0)) &&
     (iVar4 = rendering_getMemberData(param_1,param_2), iVar4 != 0)) {
    rendering_isStateValid((int)param_2);
  }
  *(undefined4 *)(iVar1 + 0x368) = uVar2;
  Ordinal_1140(uVar3);
  lingo_dispatchMethod(*param_2,local_318);
  return 0;
}



// ============================================================
// Function: rendering_readMediaBlock (FUN_680c5f30)
// Address: 680c5f30
// Size: 225 bytes
// Params: byte * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_readMediaBlock(byte *param_1,int *param_2,int param_3)
{
  uint uVar1;
  int *local_30;
  byte *local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  uVar1 = param_2[0xb];
  local_30 = (int *)0x0;
  local_2c = (byte *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  bitmap_recordFilePos((int)param_1,param_2);
  local_30 = param_2;
  local_2c = param_1;
  local_28 = 8;
  local_24 = (uint)(param_2[2] == 1);
  rendering_initState((int *)&local_30);
  Ordinal_1113(param_2 + 10);
  rendering_closeMediaStreams();
  param_2[0xb] = param_2[0xb] & 0xfffff9ff;
  param_2[0x12] = 0;
  rendering_getMemberCount();
  if ((uVar1 >> 9 & 1) != 0) {
    bitmap_writeTraceEntry(param_1,param_2,1);
  }
  if ((param_2[2] == 0xb) && (param_3 == 0)) {
    local_30 = param_2;
    local_2c = param_1;
    local_28 = 5;
    rendering_initState((int *)&local_30);
  }
  return 0;
}



// ============================================================
// Function: rendering_resolveMediaSource (FUN_680c6020)
// Address: 680c6020
// Size: 255 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_resolveMediaSource(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  int local_828;
  int *local_824;
  undefined4 local_820 [262];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_828 = 0;
  if (unaff_ESI[8] == 0) {
    iVar1 = rendering_dispatchUpdate(param_1,unaff_ESI,local_820,1);
    if ((iVar1 != 0) && (iVar1 = rendering_updateMemberRef(param_1,unaff_ESI), iVar1 == 4)) {
      uVar2 = Ordinal_1038(&DAT_681761b8,&DAT_68176198,&local_824);
      iVar1 = Ordinal_2063(uVar2);
      if (iVar1 == 0) {
        Ordinal_1310(local_820,local_408,0x3ff);
        iVar1 = (**(code **)(*local_824 + 0xc))(local_824,local_408);
        if (iVar1 == 0) {
          (**(code **)(*local_824 + 0x18))(local_824,0,&local_828);
        }
        (**(code **)(*local_824 + 8))(local_824);
        unaff_ESI[8] = local_828;
        unaff_ESI[9] = 0;
      }
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_compositeMedia (FUN_680c6120)
// Address: 680c6120
// Size: 224 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_compositeMedia(int *param_1,int *param_2,int param_3)
{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  piVar2 = param_2;
  piVar5 = (int *)param_2[8];
  bVar1 = false;
  if (piVar5 == (int *)0x0) {
    uVar3 = rendering_getStateCount((int)param_2);
    if (uVar3 != 0) {
      return 0;
    }
    iVar4 = rendering_getFrameCount((int)piVar2);
    if (iVar4 == 0) {
      return 0;
    }
    if ((piVar2[0xb] & 0x1000U) != 0) {
      return 0;
    }
    if (((piVar2[2] == 0xf) && ((piVar2[0x18] & 0x4000U) != 0)) && ((piVar2[0x18] & 0x8000U) != 0))
    {
      return 0;
    }
    iVar4 = rendering_resolveMediaSource(param_1);
    if (iVar4 == 0) {
      return 0;
    }
    piVar5 = (int *)piVar2[8];
    bVar1 = true;
  }
  if (param_3 == 0) {
    return 0;
  }
  if ((!bVar1) &&
     (iVar4 = (**(code **)(*piVar5 + 0x18))(piVar5,(int)&param_2 + 3,1,0), iVar4 != -0x7ffbffb0)) {
    return 0;
  }
  iVar4 = (**(code **)(*piVar5 + 0xc))(piVar5,0,1);
  if ((iVar4 == 0) && (iVar4 = rendering_resolveMemberProperty(piVar5,piVar2 + 9,1,&param_2), iVar4 == 0)) {
    if (param_2 != (int *)0x0) {
      return 0;
    }
    bitmap_recordFilePos(*param_1,piVar2);
    bitmap_writeTraceEntry((byte *)*param_1,piVar2,3);
    return 0;
  }
  rendering_setStateIndex((int)piVar2,iVar4);
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c6200 - 0x680c69f0
// Functions (8):
//   rendering_blendMedia
//   rendering_blendMediaEx
//   rendering_updateMemberMedia
//   rendering_updateMemberMediaEx
//   rendering_replaceMediaData
//   rendering_processMediaOp
//   rendering_updateMediaRef
//   rendering_loadMediaData

// ============================================================
// Function: rendering_blendMedia (FUN_680c6200)
// Address: 680c6200
// Size: 1138 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_blendMedia(int *param_1,int *param_2,int *param_3)
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  int local_43c;
  int *local_438;
  int local_434;
  int local_430;
  int *local_42c;
  int local_428;
  uint local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  local_438 = param_3;
  local_428 = 0;
  local_424 = 2;
  uVar4 = rendering_getStateCount((int)param_2);
  if (uVar4 == 0) {
    iVar5 = rendering_getFrameCount((int)param_2);
    if (iVar5 == 0) {
      local_42c = (int *)0x0;
      if (param_1[4] != 0) {
        iVar5 = crt_getChunkRef(param_1[4]);
        if (iVar5 != 0) {
          if (param_1[4] != 0) {
            iVar5 = xtra_getScriptContext(param_1[4]);
            if (iVar5 != 0) {
              crt_getStreamRef(iVar5,(int *)&local_42c);
            }
          }
          local_434 = 0;
          local_430 = 0;
          *(undefined4 *)(*(int *)(param_1[1] + 8) + 900) = 0;
          local_424 = 2;
          bVar1 = false;
          do {
            iVar5 = rendering_getMemberSlot(param_2);
            if (iVar5 != 0) {
              local_424 = 1;
              goto LAB_680c659d;
            }
            if (bVar1) {
              iVar5 = lingo_callMethod(*(int *)(param_1[1] + 8),&local_428,param_1 + 10,local_42c,
                                   (int)&local_434,0);
            }
            else {
              uVar3 = lingo_resolveRef(*(int *)(param_1[1] + 8),0,&local_428);
              iVar5 = CONCAT31(extraout_var_03,uVar3);
              if (iVar5 == 0) goto LAB_680c65c3;
              bVar1 = true;
            }
            if (iVar5 == 0) goto LAB_680c659d;
            if ((*(int **)(param_1[1] + 8))[0xe1] != 0) break;
            bVar2 = lingo_isMovieLoaded(*(int **)(param_1[1] + 8));
          } while (CONCAT31(extraout_var_04,bVar2) == 0);
          local_428 = -0x7ffbadf8;
          local_424 = 0;
LAB_680c659d:
          if (bVar1) {
            lingo_callMethod(*(int *)(param_1[1] + 8),&local_430,param_1 + 10,0,(int)&local_434,0);
          }
LAB_680c65c3:
          if ((local_428 == 0) && (local_430 != 0)) {
            local_428 = local_430;
          }
          if (local_42c != (int *)0x0) {
            (**(code **)(*local_42c + 8))(local_42c);
          }
          goto LAB_680c6606;
        }
      }
      goto LAB_680c65fc;
    }
    iVar5 = rendering_updateMemberRef((int)param_1,param_2);
    if (iVar5 != 4) goto LAB_680c65fc;
    if ((param_2[0xb] & 0x1000U) != 0) {
      local_424 = 0;
      local_428 = -0x7ffbffec;
    }
    if (((param_2[2] == 0xf) && ((param_2[0x18] & 0x4000U) != 0)) &&
       ((param_2[0x18] & 0x8000U) != 0)) {
      iVar5 = rendering_getMemberData(*param_1,param_2);
      if (iVar5 != 0) {
        bVar1 = rendering_isStateValid((int)param_2);
        local_424 = (uint)(CONCAT31(extraout_var,bVar1) != 0);
      }
    }
    else {
      rendering_compositeMedia(param_1,param_2,1);
      if (param_2[8] != 0) {
        iVar5 = rendering_dispatchUpdate((int)param_1,param_2,local_420,2);
        if (iVar5 != 0) {
          iVar5 = Ordinal_1313(local_420);
          if (iVar5 != 4) goto LAB_680c65fc;
          local_430 = 0;
          local_434 = 0;
          local_42c = (int *)0x0;
          *(undefined4 *)(*(int *)(param_1[1] + 8) + 900) = 0;
          bVar1 = false;
          do {
            if (param_2[2] != 9) {
              if ((param_2[2] == 0xf) && ((param_2[0x18] & 0x4000U) != 0)) {
                bVar1 = true;
                goto LAB_680c6344;
              }
              if (bVar1) goto LAB_680c6344;
              local_428 = rendering_resolveMemberProperty((int *)param_2[8],param_2 + 9,1,&local_43c);
              if (local_43c == 0) {
                if (local_428 == 0) goto LAB_680c63af;
                rendering_setStateIndex((int)param_2,local_428);
                goto LAB_680c6440;
              }
LAB_680c6373:
              local_424 = 1;
              goto LAB_680c644a;
            }
            bVar1 = true;
LAB_680c6344:
            if ((param_2[0xb] & 0x400U) == 0) goto LAB_680c6373;
            iVar5 = rendering_getMemberData(*param_1,param_2);
            if (iVar5 != 0) {
              bVar2 = rendering_isStateValid((int)param_2);
              if (CONCAT31(extraout_var_00,bVar2) == 0) {
                local_424 = 0;
              }
            }
            if ((param_2[0xb] & 0x400U) == 0) goto LAB_680c6373;
LAB_680c63af:
            if (local_424 != 2) goto LAB_680c644a;
            if (local_42c == (int *)0x0) {
              uVar3 = lingo_resolveRef(*(int *)(param_1[1] + 8),0,&local_428);
              iVar5 = CONCAT31(extraout_var_01,uVar3);
              if (iVar5 == 0) goto LAB_680c6478;
              local_42c = (int *)0x1;
            }
            else {
              iVar5 = lingo_callMethod(*(int *)(param_1[1] + 8),&local_428,local_420,param_2[8],
                                   (int)&local_430,0);
            }
            if (iVar5 == 0) goto LAB_680c644a;
            if ((*(int **)(param_1[1] + 8))[0xe1] != 0) break;
            bVar2 = lingo_isMovieLoaded(*(int **)(param_1[1] + 8));
          } while (CONCAT31(extraout_var_02,bVar2) == 0);
          local_428 = -0x7ffbadf8;
LAB_680c6440:
          local_424 = 0;
LAB_680c644a:
          if (local_42c != (int *)0x0) {
            lingo_callMethod(*(int *)(param_1[1] + 8),&local_434,local_420,0,(int)&local_430,0);
          }
LAB_680c6478:
          if ((local_428 == 0) && (local_434 != 0)) {
            local_428 = local_434;
          }
        }
      }
    }
  }
  else {
LAB_680c65fc:
    local_424 = 1;
  }
LAB_680c6606:
  if (local_438 != (int *)0x0) {
    if (local_424 == 1) goto LAB_680c664b;
    if (local_428 == 0) {
      local_428 = (-(uint)(local_424 != 2) & 0xffffed34) + 0x800412e0;
    }
    *local_438 = local_428;
  }
  if (local_424 != 1) {
    return 0;
  }
LAB_680c664b:
  return 0;
}



// ============================================================
// Function: rendering_blendMediaEx (FUN_680c6680)
// Address: 680c6680
// Size: 257 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_blendMediaEx(int *param_1,int param_2,int param_3)
{
  int iVar1;
  uint uVar2;
  int local_40c;
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_40c = param_3;
  if (param_1 != (int *)0x0) {
    rendering_getMemberRefCount(param_1);
    iVar1 = rendering_getStateFlags((int)param_1);
    if (iVar1 != 0) {
      if (local_40c == 0) {
        if (param_2 != 0) {
          uVar2 = Ordinal_1201(param_2);
          iVar1 = Ordinal_1285(param_2,0x100);
          if (iVar1 - param_2 <= (int)uVar2) {
            uVar2 = iVar1 - param_2;
          }
          if (0x3fe < uVar2) {
            local_40c = 0;
            iVar1 = Ordinal_1251(param_2,param_2 + 0x3fe,&local_40c);
            uVar2 = iVar1 - param_2;
          }
          Ordinal_1128(local_407,param_2,uVar2);
          local_408 = (undefined1)uVar2;
          if (0xfe < (int)uVar2) {
            local_408 = 0xff;
          }
          Ordinal_37(param_1 + 0x13,1,&local_408,uVar2 + 1);
        }
      }
      else {
        cast_formatNumber(param_1 + 0x13,1,local_40c);
      }
      rendering_getMemberType((int)param_1);
      rendering_getMemberRefCount(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_updateMemberMedia (FUN_680c6790)
// Address: 680c6790
// Size: 22 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateMemberMedia(int param_1,int *param_2)
{
  rendering_setMemberData(param_1,param_2,2);
  return 0;
}



// ============================================================
// Function: rendering_updateMemberMediaEx (FUN_680c67b0)
// Address: 680c67b0
// Size: 108 bytes
// Params: int * param_1, int * param_2, int * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_updateMemberMediaEx(int *param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = rendering_getFrameCount((int)param_2);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = rendering_updateMemberRef((int)param_1,param_2);
  if (iVar2 == 4) {
    if ((param_2[8] == 0) && (param_4 != 0)) {
      rendering_compositeMedia(param_1,param_2,1);
    }
    if (param_3 != (int *)0x0) {
      piVar1 = (int *)param_2[8];
      *param_3 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_replaceMediaData (FUN_680c6820)
// Address: 680c6820
// Size: 109 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_replaceMediaData(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = rendering_writeMediaBlock(param_1,param_2,0);
  if (iVar1 != 0) {
    Ordinal_1113(param_2 + 10);
    param_2[10] = *param_3;
    if (*param_3 == 0) {
      rendering_setMemberSlot((int)param_2,"");
      iVar1 = param_2[3];
      iVar3 = FOURCC_ediM;
      iVar2 = rendering_getDispatchMode();
      strings_readMediaBlock(iVar2,iVar3,iVar1);
    }
    *param_3 = 0;
    rendering_setMemberData(param_1,param_2,2);
  }
  return 1;
}



// ============================================================
// Function: rendering_processMediaOp (FUN_680c6890)
// Address: 680c6890
// Size: 218 bytes
// Params: byte * param_1, int param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_processMediaOp(byte *param_1,int param_2,int *param_3,int param_4)
{
  int iVar1;
  int *local_30;
  byte *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = (int *)0x0;
  local_2c = (byte *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (param_3 != (int *)0x0) {
    rendering_setStateIndex((int)param_3,0);
    rendering_readMediaBlock(param_1,param_3,1);
    local_30 = param_3;
    local_2c = param_1;
    local_28 = 2;
    rendering_initState((int *)&local_30);
    if (param_4 != 0) {
      iVar1 = media_getDataPtr(*(int **)(param_2 + 4));
      if (*(code **)(iVar1 + 0xd4) != (code *)0x0) {
        iVar1 = (**(code **)(iVar1 + 0xd4))(param_2,param_3[1],param_3[0x11]);
        param_3[0x11] = iVar1;
      }
      rendering_getMemberRefCount(param_3);
      if (param_3[0x29] != 0) {
        Ordinal_1113(param_3 + 0x29);
      }
      Ordinal_36(param_3 + 0x13);
    }
    Ordinal_1130(param_3 + 0x15,0x50);
    param_3[2] = 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_updateMediaRef (FUN_680c6970)
// Address: 680c6970
// Size: 120 bytes
// Params: byte * param_1, undefined4 param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_updateMediaRef(byte *param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint local_8;
  
  pbVar3 = param_1;
  iVar2 = *(int *)(param_1 + 0x18);
  local_8 = 0;
  playback_renderSpriteAt((int)param_1,param_2,0x80008000);
  rendering_resolveStateEx(iVar2,param_2,&local_8,(int *)&param_1);
  pbVar4 = param_1;
  if (local_8 != 0) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000;
    stage_clearSpriteEventProps(*(int *)(*(int *)(pbVar3 + 0x20) + 8),param_2);
    rendering_processMediaOp(pbVar3,iVar2,(int *)pbVar4,1);
    rendering_getDispatchProperty();
    puVar1 = (uint *)(pbVar4 + 0x2c);
    *puVar1 = *puVar1 & 0xffffbfff;
  }
  return local_8;
}



// ============================================================
// Function: rendering_loadMediaData (FUN_680c69f0)
// Address: 680c69f0
// Size: 90 bytes
// Params: byte * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_loadMediaData(byte *param_1,int *param_2)
{
  int *piVar1;
  
  if (*param_2 != 0) {
    piVar1 = (int *)Ordinal_1114(*param_2);
    if (piVar1[0x2b] != 0) {
      rendering_deleteMemberProperty();
    }
    if (piVar1[2] != 0) {
      rendering_processMediaOp(param_1,*(int *)(param_1 + 0x18),piVar1,1);
    }
    playback_initScore(piVar1 + 0x2a);
    Ordinal_1115(*param_2);
    Ordinal_1113(param_2);
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c6a50 - 0x680c70a0
// Functions (5):
//   rendering_addSpriteMedia
//   rendering_removeSpriteMedia
//   rendering_loadMediaBlock
//   rendering_processMediaBlock
//   rendering_setMemberMediaProperty

// ============================================================
// Function: rendering_addSpriteMedia (FUN_680c6a50)
// Address: 680c6a50
// Size: 308 bytes
// Params: byte * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_addSpriteMedia(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined3 extraout_var;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x18);
  local_8 = 0;
  piVar3 = rendering_getDispatchEntry(iVar1,param_2,&local_8);
  if (piVar3 != (int *)0x0) {
    piVar3[0x2b] = 1;
    piVar4 = (int *)rendering_resolveState(iVar1,param_2);
    if (piVar4 != (int *)0x0) {
      iVar5 = media_getDataPtr(*(int **)(iVar1 + 4));
      piVar4[0xb] = piVar4[0xb] | 0x4000;
      if (param_3 != 0) {
        rendering_getMemberData(param_1,piVar4);
        bVar2 = rendering_createDispatchEntry((int)piVar4,(int *)0x0);
        if ((CONCAT31(extraout_var,bVar2) != 0) && (piVar4[10] == 0)) {
          rendering_copyMemberData(piVar4,(int *)0x0);
        }
      }
      if (*(int *)(iVar5 + 0xd4) == 0) {
        uVar8 = 0x80008000;
      }
      else {
        uVar8 = 0x80088000;
      }
      playback_renderSpriteAt((int)param_1,param_2,uVar8);
      rendering_getMemberCount();
      stage_clearSpriteEventProps(*(int *)(*(int *)(param_1 + 0x20) + 8),param_2);
      piVar6 = piVar4;
      piVar7 = piVar3;
      for (iVar5 = 0x2a; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      piVar3[0x12] = 0;
      rendering_getMemberRefCount(piVar4);
      iVar5 = piVar4[1];
      Ordinal_1130(piVar4,0xa8);
      piVar4[1] = iVar5;
      *piVar4 = iVar1;
      rendering_getDispatchProperty();
    }
    rendering_getDispatchCount();
    return local_8;
  }
  rendering_loadMediaData(param_1,&local_8);
  return local_8;
}



// ============================================================
// Function: rendering_removeSpriteMedia (FUN_680c6b90)
// Address: 680c6b90
// Size: 213 bytes
// Params: byte * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_removeSpriteMedia(byte *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_8;
  
  iVar4 = *(int *)(param_1 + 0x18);
  local_8 = 0;
  piVar2 = rendering_getDispatchEntry(iVar4,param_2,&local_8);
  if (piVar2 == (int *)0x0) goto LAB_680c6c4f;
  piVar3 = (int *)rendering_resolveState(iVar4,param_2);
  if (piVar3 == (int *)0x0) {
LAB_680c6c35:
    bVar1 = true;
  }
  else {
    iVar4 = rendering_getMemberData(param_1,piVar3);
    bVar1 = rendering_createDispatchEntry((int)piVar3,(int *)0x0);
    if ((CONCAT31(extraout_var,bVar1) != 0) && (piVar3[10] == 0)) {
      rendering_copyMemberData(piVar3,(int *)0x0);
    }
    piVar6 = piVar3;
    piVar7 = piVar2;
    for (iVar5 = 0x2a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar7 = piVar7 + 1;
    }
    piVar2[5] = 0;
    piVar2[6] = 0;
    iVar5 = rendering_cloneMemberSprite((int)param_1);
    if (iVar4 != 0) {
      rendering_isStateValid((int)piVar3);
    }
    piVar2[0x12] = 0;
    if (iVar5 != 0) {
      display_resetStreamFlag((int)piVar2);
      goto LAB_680c6c35;
    }
    bVar1 = false;
  }
  rendering_getDispatchCount();
  if (bVar1) {
    return local_8;
  }
LAB_680c6c4f:
  rendering_loadMediaData(param_1,&local_8);
  return local_8;
}



// ============================================================
// Function: rendering_loadMediaBlock (FUN_680c6c70)
// Address: 680c6c70
// Size: 747 bytes
// Params: byte * param_1, int param_2, undefined4 * param_3, int * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_loadMediaBlock(byte *param_1,int param_2,undefined4 *param_3,int *param_4,int param_5)
{
  undefined4 *puVar1;
  byte *pbVar2;
  short sVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  uint local_58;
  int *local_54;
  undefined4 *local_50;
  int local_4c;
  int *local_48;
  byte *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  undefined1 local_31;
  int *local_30;
  byte *local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar5 = *(int **)(param_1 + 0x18);
  local_44 = param_1;
  local_4c = param_2;
  local_50 = param_3;
  local_38 = (int *)0x0;
  local_48 = piVar5;
  piVar4 = (int *)Ordinal_1114(*param_3);
  local_54 = piVar4;
  if (piVar4 == (int *)0x0) goto LAB_680c6f46;
  piVar5 = (int *)rendering_getChannelSprite((int)piVar5,(short)param_2);
  local_40 = piVar5;
  if (piVar5 != (undefined4 *)0x0) {
    local_3c = (int *)rendering_resolveStateEx((int)local_48,param_2,&local_58,(int *)&local_38);
    if (local_58 == 0) {
      Ordinal_1158(piVar5[0x10],piVar5[0x11]);
      iVar8 = Ordinal_1151(piVar5[0x10],local_3c,piVar4);
      uVar6 = Ordinal_1157(piVar5[0x10]);
      piVar5[0x11] = uVar6;
      if (iVar8 == 0) goto LAB_680c6f3b;
      piVar7 = (int *)Ordinal_1156(piVar5[0x10],uVar6,local_3c);
    }
    else {
      rendering_updateMediaRef(local_44,param_2);
      piVar9 = piVar4;
      piVar10 = local_38;
      for (iVar8 = 0x2a; piVar7 = local_38, piVar5 = local_40, piVar4 = local_54, iVar8 != 0;
          iVar8 = iVar8 + -1) {
        *piVar10 = *piVar9;
        piVar9 = piVar9 + 1;
        piVar10 = piVar10 + 1;
      }
    }
    *piVar7 = (int)local_48;
    piVar7[1] = local_4c;
    rendering_initChannelState(piVar5);
    local_38 = (int *)rendering_validateState(piVar7);
    local_40 = (int *)rendering_validateState(piVar4);
    if ((piVar4[0x2b] != 0) && (local_40 != local_38)) {
      rendering_deleteMemberProperty();
    }
    if (((local_38 == (int *)0x0) || (local_40 != local_38)) || (*piVar4 != *piVar7)) {
      piVar7[3] = 0;
    }
    if (((*(byte *)(piVar4 + 0xe) & 2) != 0) || (local_31 = 1, piVar7[3] == 0)) {
      local_31 = 3;
    }
    *(undefined1 *)(piVar7 + 0xe) = local_31;
    piVar7[0xb] = piVar7[0xb] & 0xffffbfff;
    if (piVar7[0x11] != 0) {
      *(byte *)(piVar7 + 0xe) = *(byte *)(piVar7 + 0xe) | *(byte *)(piVar4 + 0xe) & 8;
    }
    piVar7[0x12] = 0;
    local_38 = param_4;
    local_40 = (int *)rendering_getChannelLock((int)piVar5);
    local_3c = piVar4 + 0x2a;
    iVar8 = rendering_compareChannelData(piVar4[0x2a],(int)local_40);
    if ((iVar8 != 0) ||
       (((local_40 == (undefined4 *)0x0 && (iVar8 = rendering_getChannelVisibility(*local_3c), iVar8 == 0)) &&
        (sVar3 = rendering_getChannelWidth(*local_3c), sVar3 == *(short *)(piVar5 + 1))))) {
      local_38 = (int *)0x0;
    }
    pbVar2 = local_44;
    if (((param_4 != (int *)0x0) && (local_38 != (int *)0x0)) && (piVar7[2] != 0)) {
      local_24 = (int *)*local_3c;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      local_2c = local_44;
      local_28 = 0x16;
      local_30 = piVar7;
      iVar8 = rendering_initState((int *)&local_30);
      if (iVar8 == 0) goto LAB_680c6f3b;
      lingo_resetCastXtra(local_48);
    }
    rendering_getMemberRefCount(piVar7);
    piVar7[5] = 0;
    piVar7[6] = 0;
    if (piVar7[2] == 0) {
LAB_680c6ed8:
      if (param_5 != 0) {
        playback_renderSpriteBlock((int)pbVar2,(int)piVar7,3);
        Ordinal_890(*(int *)(*(int *)(pbVar2 + 0x20) + 8),local_4c);
      }
      rendering_getDispatchProperty();
      *(undefined1 *)(piVar7 + 0xe) = local_31;
      playback_initScore(local_3c);
      puVar1 = local_50;
      Ordinal_1115(*local_50);
      Ordinal_1113(puVar1);
      return 0;
    }
    rendering_releaseMemberData(piVar7);
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_2c = pbVar2;
    local_28 = 4;
    local_30 = piVar7;
    local_24 = piVar4;
    iVar8 = rendering_initState((int *)&local_30);
    if (iVar8 != 0) goto LAB_680c6ed8;
  }
LAB_680c6f3b:
  Ordinal_1115(*local_50);
LAB_680c6f46:
  return 0;
}



// ============================================================
// Function: rendering_processMediaBlock (FUN_680c6f60)
// Address: 680c6f60
// Size: 309 bytes
// Params: byte * param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_processMediaBlock(byte *param_1,int *param_2,int param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  
  iVar5 = 0;
  local_24 = 0;
  local_1c = 0;
  local_20 = 0;
  local_28 = 0;
  iVar4 = 0;
  if ((param_3 != 0) && (iVar2 = Ordinal_1404(&local_24,param_3,1), iVar2 != 0)) {
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0xd8);
    iVar4 = local_28;
    if ((8 < (int)piVar1) ||
       (iVar5 = rendering_dispatchChannelOp((int)param_1,*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x54),
                             piVar1), iVar5 != 0)) {
      uVar3 = Ordinal_1116(param_3,FOURCC_PICH,0,iVar5,&local_20,0,0,piVar1,0,0);
      local_1c = Ordinal_1658(local_24,uVar3);
      if ((local_1c != 0) && (iVar5 = Ordinal_1663(&local_1c,iVar5,&local_18), iVar5 != 0)) {
        if (param_4 != (undefined4 *)0x0) {
          param_4[1] = local_14;
          *param_4 = local_18;
        }
        rendering_processMediaOp(param_1,*(int *)(param_1 + 0x18),param_2,0);
        iVar4 = rendering_setMemberPropertyEx(param_1,param_2,(undefined4 *)0x0,local_1c,local_20,0,5,0);
        rendering_updateMemberMedia(param_1,param_2);
      }
    }
  }
  Ordinal_1407(&local_24);
  if (iVar4 == 0) {
    Ordinal_1653(&local_1c);
    Ordinal_1733(&local_20);
  }
  return 0;
}



// ============================================================
// Function: rendering_setMemberMediaProperty (FUN_680c70a0)
// Address: 680c70a0
// Size: 599 bytes
// Params: byte * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setMemberMediaProperty(byte *param_1,int *param_2,int param_3)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_478;
  undefined4 local_470;
  undefined4 local_468;
  undefined1 local_461;
  int *local_460;
  byte *local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438 [262];
  undefined4 local_20 [6];
  uint local_8;
  
  iVar3 = 0;
  bVar1 = false;
  local_470 = 0xfb;
  local_468 = 0x50;
  if (param_3 != 0) {
    if ((param_2[2] == 1) || (param_2[2] == 0xd)) {
      local_461 = (undefined1)param_2[0x26];
      local_478 = param_2[0x27];
      local_45c = (byte *)0x0;
      local_44c = 0;
      local_448 = 0;
      local_444 = 0;
      local_440 = 0;
      local_43c = 0;
      local_450 = local_20;
      local_460 = param_2;
      local_458 = 0x19;
      local_454 = 0x1f;
      iVar2 = rendering_initState((int *)&local_460);
      if (iVar2 != 0) {
        local_470 = local_20[0];
      }
      local_454 = 0x20;
      iVar2 = rendering_initState((int *)&local_460);
      if (iVar2 != 0) {
        local_468 = local_20[0];
      }
      bVar1 = true;
    }
    iVar2 = rendering_getFrameCount((int)param_2);
    if (iVar2 != 0) {
      iVar3 = rendering_dispatchUpdate(*(int *)(param_1 + 0x20),param_2,local_438,1);
    }
    rendering_processMediaOp(param_1,*(int *)(param_1 + 0x18),param_2,0);
    iVar3 = rendering_setMemberPropertyEx(param_1,param_2,(undefined4 *)(-(uint)(iVar3 != 0) & (uint)local_438),
                         param_3,0,iVar3,0,0);
    if (iVar3 != 0) {
      if (bVar1) {
        *(undefined1 *)(param_2 + 0x26) = local_461;
        param_2[0x27] = local_478;
        local_44c = 0;
        local_448 = 0;
        local_444 = 0;
        local_440 = 0;
        local_43c = 0;
        local_450 = local_20;
        local_20[0] = local_470;
        local_460 = param_2;
        local_45c = param_1;
        local_458 = 0x1a;
        local_454 = 0x1f;
        rendering_initState((int *)&local_460);
        local_20[0] = local_468;
        local_454 = 0x20;
        rendering_initState((int *)&local_460);
      }
      rendering_updateMemberMedia(param_1,param_2);
      return 0;
    }
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c7300 - 0x680c7ac0
// Functions (6):
//   rendering_getMediaInfo
//   rendering_swapSpriteMedia
//   rendering_getMediaFormat
//   rendering_scanMediaFormat
//   rendering_blitMedia
//   rendering_checkMediaOverlay

// ============================================================
// Function: rendering_getMediaInfo (FUN_680c7300)
// Address: 680c7300
// Size: 359 bytes
// Params: undefined4 * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMediaInfo(undefined4 *param_1,undefined4 param_2,int *param_3)
{
  int param_4;
  void *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = (int *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = (int *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  this = *(void **)(param_1[1] + 8);
  piVar2 = (int *)rendering_resolveState((int)this,param_2);
  piVar1 = (int *)param_3[2];
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if ((*param_3 == 0) && (param_3[1] == 0)) {
    if (piVar2 == (int *)0x0) {
      rendering_attachMemberSprite(this,param_2);
      piVar2 = (int *)rendering_resolveState((int)this,param_2);
    }
    else {
      rendering_clearStateFlag((int)piVar2,0);
      rendering_processMediaOp((byte *)*param_1,(int)this,piVar2,0);
    }
    iVar3 = rendering_importMemberStream((int)param_3,param_1,(int)piVar2);
    if (piVar2[2] == 0xb) {
      Ordinal_890(param_1[2],param_2);
    }
LAB_680c743e:
    if (iVar3 != 0) goto LAB_680c7452;
  }
  else {
    if ((*param_3 != 8) || (param_3[1] != 1)) {
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      local_2c = *param_1;
      local_28 = 0x18;
      local_24 = param_3;
      local_30 = piVar2;
      rendering_initState((int *)&local_30);
      iVar3 = local_20;
      goto LAB_680c743e;
    }
    scoreEngine_swapKeyframeBytes(piVar1,0);
    rendering_getDispatchRef((int)piVar2,(int)piVar1);
    rendering_setMemberData(*param_1,piVar2,4);
  }
  piVar2[0xb] = piVar2[0xb] | 0x200;
  rendering_updateMemberMedia(*param_1,piVar2);
LAB_680c7452:
  return 0;
}



// ============================================================
// Function: rendering_swapSpriteMedia (FUN_680c7470)
// Address: 680c7470
// Size: 61 bytes
// Params: byte * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_swapSpriteMedia(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = param_1;
  param_1 = (byte *)rendering_addSpriteMedia(param_1,param_2,1);
  uVar2 = rendering_loadMediaBlock(pbVar1,param_3,&param_1,(int *)0x1,1);
  rendering_loadMediaData(pbVar1,(int *)&param_1);
  return uVar2;
}



// ============================================================
// Function: rendering_getMediaFormat (FUN_680c77f0)
// Address: 680c77f0
// Size: 92 bytes
// Params: byte * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMediaFormat(byte *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_2[2] == 1) {
    if ((param_2[0xb] & 0x200U) == 0) {
      if ((param_2[0x1e] != 0) && (param_2[0x15] == 0)) goto LAB_680c7835;
      goto LAB_680c7818;
    }
  }
  else {
LAB_680c7818:
    if ((param_2[0xb] & 0x200U) == 0) goto LAB_680c7828;
  }
  if ((param_2[0x12] == 0) && ((*(byte *)(param_2 + 0xe) & 2) == 0)) {
LAB_680c7835:
    rendering_readMediaBlock(param_1,param_2,0);
    return 1;
  }
LAB_680c7828:
  rendering_closeMediaStreams();
  return 0;
}



// ============================================================
// Function: rendering_scanMediaFormat (FUN_680c7850)
// Address: 680c7850
// Size: 121 bytes
// Params: byte * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_scanMediaFormat(byte *param_1)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  int *local_8;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (*(int *)(iVar1 + 0x368) == 0) {
    local_8 = (int *)(iVar1 + 0x328);
    local_c = 0;
    do {
      iVar4 = *local_8;
      sVar2 = (short)((uint)iVar4 >> 0x10);
      while (sVar2 != 0) {
        piVar3 = (int *)rendering_resolveState(iVar1,iVar4);
        if (piVar3 == (int *)0x0) {
          return 0;
        }
        iVar4 = rendering_getMediaFormat(param_1,piVar3);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = piVar3[6];
        sVar2 = (short)((uint)iVar4 >> 0x10);
      }
      local_8 = local_8 + 2;
      local_c = local_c + 1;
    } while (local_c < 3);
  }
  return 0;
}



// ============================================================
// Function: rendering_blitMedia (FUN_680c78d0)
// Address: 680c78d0
// Size: 491 bytes
// Params: byte * param_1, int param_2, int param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, int param_8, int * param_9, int param_10
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_blitMedia(byte *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,int *param_9,int param_10)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_5c [2];
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int *local_30;
  byte *local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_54 = param_6;
  local_50 = param_5;
  local_3c = param_9;
  local_40 = param_8;
  local_4c = param_10;
  local_38 = param_2;
  local_34 = 0;
  local_30 = (int *)0x0;
  local_2c = (byte *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = (int *)0x0;
  local_c = 0;
  local_48 = 0;
  local_44 = 0;
  piVar1 = rendering_getDispatchEntry(param_2,param_3,&local_34);
  iVar2 = local_48;
  if (piVar1 == (int *)0x0) goto LAB_680c7a8a;
  *piVar1 = local_38;
  piVar1[2] = param_4;
  if (local_4c == 0) {
    iVar4 = rendering_getStateFlags((int)piVar1);
    iVar2 = local_48;
    if (iVar4 != 0) goto LAB_680c7976;
  }
  else {
    iVar2 = Ordinal_1112(local_4c);
    piVar1[0x13] = iVar2;
LAB_680c7976:
    local_44 = rendering_getTimestamp();
    Ordinal_37(piVar1 + 0x13,0x11,&local_44,4);
    rendering_stampMemberTimestamp((int)param_1);
    local_18 = param_7;
    local_20 = local_54;
    local_1c = local_50;
    local_2c = param_1;
    local_28 = 0;
    local_14 = local_40;
    local_10 = local_3c;
    local_30 = piVar1;
    if (0x10 < param_4) {
      iVar2 = rendering_resolveDispatchFlags(param_4);
      local_24 = iVar2;
      piVar3 = (int *)lingo_getGlobalRef(local_38);
      iVar2 = media_checkActorType(piVar3,iVar2);
      piVar1[2] = 0xf - (uint)(iVar2 != 0);
    }
    iVar4 = rendering_initState((int *)&local_30);
    iVar2 = local_48;
    if (iVar4 != 0) {
      piVar1 = (int *)rendering_getDispatchCount();
      iVar4 = rendering_loadMediaBlock(param_1,param_3,&local_34,(int *)0x1,0);
      iVar2 = local_48;
      if (iVar4 != 0) {
        local_3c = (int *)rendering_resolveState(local_38,param_3);
        if ((local_3c != (int *)0x0) && ((local_3c[2] == 0xf || (local_3c[2] == 0xe)))) {
          local_28 = 0x1e;
          local_24 = local_40;
          local_30 = local_3c;
          iVar4 = rendering_initState((int *)&local_30);
          iVar2 = local_48;
          if (iVar4 == 0) goto LAB_680c7a78;
        }
        playback_renderSpriteBlock((int)param_1,(int)local_3c,3);
        local_5c[0] = param_3;
        rendering_getChannelProperty((int)param_1,10,local_5c);
        iVar2 = 1;
      }
    }
  }
LAB_680c7a78:
  if (piVar1 != (int *)0x0) {
    rendering_getDispatchCount();
  }
LAB_680c7a8a:
  rendering_loadMediaData(param_1,&local_34);
  if (iVar2 == 0) {
    lingo_mutateProperty(local_38,0x80040002);
  }
  return 0;
}



// ============================================================
// Function: rendering_checkMediaOverlay (FUN_680c7ac0)
// Address: 680c7ac0
// Size: 34 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall rendering_checkMediaOverlay(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_2 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 8) == 3)) &&
     (((*(byte *)(param_2 + 0x14) & 0x40) != 0 || ((*(byte *)(param_1 + 0x7d) & 1) != 0)))) {
    uVar1 = 1;
  }
  return uVar1;
}



