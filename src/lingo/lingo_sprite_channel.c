// Module: lingo
// Topic: Sprite channel frame data read/write
// Address range: 0x68098480 - 0x680997C0
// Functions (24):
//   lingo_getSpriteRect
//   Ordinal_482
//   Ordinal_400
//   Ordinal_401
//   Ordinal_402
//   Ordinal_425
//   Ordinal_426
//   Ordinal_403
//   Ordinal_481
//   Ordinal_480
//   Ordinal_470
//   Ordinal_471
//   Ordinal_404
//   Ordinal_405
//   Ordinal_406
//   Ordinal_407
//   Ordinal_486
//   Ordinal_487
//   Ordinal_408
//   Ordinal_409
//   Ordinal_410
//   Ordinal_411
//   lingo_getSpriteOpCount
//   Ordinal_412


// ============================================================
// Function: lingo_getSpriteRect (FUN_68098480)
// Address: 68098480
// Size: 221 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint lingo_getSpriteRect(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined3 extraout_var;
  uint uVar6;
  int local_8;
  
  uVar6 = 1;
  local_8 = 0;
  iVar3 = media_getScoreHandle(param_1);
  if (iVar3 != 0) {
    iVar3 = media_getScoreContext(param_1);
    iVar4 = media_applyScoreEdit((int)param_1,param_2,0,param_4,param_3);
    if (iVar4 != 0) {
      uVar5 = media_getVtableFunc(param_1);
      local_8 = Ordinal_1112(uVar5);
      if (iVar3 != 0) {
        piVar1 = *(int **)(iVar3 + 0x28);
        param_4 = media_getScoreState(piVar1);
        param_3 = media_getVtableFunc(piVar1);
        Ordinal_1113(&param_3);
        media_getPlaybackByte((int)piVar1,0,*(int *)(*(int *)(iVar3 + 0x20) + 0x500),0);
        uVar2 = media_getPlaybackByte((int)piVar1,local_8,*(int *)(*(int *)(iVar3 + 0x20) + 0x500),1);
        if (CONCAT31(extraout_var,uVar2) != 0) {
          local_8 = 0;
        }
        uVar6 = media_readPlaybackData((int)piVar1,param_4,0);
        uVar6 = CONCAT31(extraout_var,uVar2) & uVar6;
      }
      lingo_markFieldDirty();
    }
  }
  if (local_8 != 0) {
    Ordinal_1113(&local_8);
  }
  return uVar6;
}



// ============================================================
// Function: Ordinal_482
// Address: 68098560
// Size: 117 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_482(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x98560  482   */
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_400
// Address: 680985e0
// Size: 230 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_400(int param_1,int param_2)
{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x985e0  400   */
  piVar1 = *(int **)(param_1 + 0x20);
  uVar5 = 0;
  local_18 = (int *)0x0;
  iVar6 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    uVar5 = *(undefined4 *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar6 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar3 = media_getVtableFunc(*(int **)(iVar6 + 0x28));
  if (iVar3 != 0) {
    local_18 = (int *)media_writePlaybackData(uVar5,0,0);
    iVar3 = *(int *)(*(int *)(iVar6 + 0x20) + 0x500);
    iVar7 = 0;
    uVar5 = media_getVtableFunc(*(int **)(iVar6 + 0x28));
    iVar4 = Ordinal_1112(uVar5);
    uVar2 = media_getPlaybackByte((int)local_18,iVar4,iVar3,iVar7);
    if (CONCAT31(extraout_var,uVar2) != 0) {
      media_setScoreContext(local_18,iVar6);
      media_lockScoreData(local_18,(undefined4 *)0x0,(undefined4 *)0x0);
      goto LAB_6809869e;
    }
  }
  media_getScorePlayState((int *)&local_18);
LAB_6809869e:
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_401
// Address: 680986d0
// Size: 9 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_401(int *param_1)
{
                    /* 0x986d0  401   */
  media_isScoreLocked(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_402
// Address: 680986e0
// Size: 9 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_402(int *param_1)
{
                    /* 0x986e0  402   */
  media_getScoreState(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_425
// Address: 680986f0
// Size: 249 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_425(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *this;
  void *this_00;
  
                    /* 0x986f0  425   */
  iVar2 = media_isScoreLocked(param_1);
  if (param_2 < 0) {
    return 0;
  }
  iVar3 = media_getScoreState(param_1);
  if ((param_2 == iVar3) && (param_2 <= iVar2)) {
    iVar3 = 1;
  }
  else {
    media_refreshScoreVersion((int)param_1);
    if (param_2 < 1) {
      return 0;
    }
    iVar3 = media_getScoreHandle(param_1);
    if (iVar3 == 0) {
      if ((param_3 == 0) || (param_2 <= iVar2)) {
        bVar1 = false;
        iVar3 = param_2;
      }
      else {
        bVar1 = true;
        iVar3 = iVar2;
      }
      iVar3 = media_readPlaybackData((int)param_1,iVar3,0);
      if (iVar3 == 0) {
        return 0;
      }
      if (bVar1) {
        iVar3 = media_readPlaybackBlock(this,(int)param_1,0);
        if (iVar3 != 0) {
          lingo_getTextFieldState();
        }
        if (iVar2 == 0) {
          lingo_getSpriteRect(param_1,0,0,0);
          iVar3 = media_readPlaybackData((int)param_1,param_2,0);
        }
      }
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      lingo_getTextFieldState();
      iVar3 = 1;
    }
  }
  if ((param_3 != 0) && (iVar2 = media_getScoreHandle(param_1), iVar2 == 0)) {
    iVar2 = media_readPlaybackBlock(this_00,(int)param_1,0);
    return iVar2;
  }
  return iVar3;
}



// ============================================================
// Function: Ordinal_426
// Address: 680987f0
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_426(int param_1)
{
                    /* 0x987f0  426   */
  media_isPlaybackActive(param_1,0);
  return 0;
}



// ============================================================
// Function: Ordinal_403
// Address: 68098810
// Size: 9 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_403(int *param_1)
{
                    /* 0x98810  403   */
  media_getScoreHandle(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_481
// Address: 68098820
// Size: 35 bytes
// Params: int * param_1, int param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 Ordinal_481(int *param_1,int param_2)

{
  undefined1 uVar1;
  
                    /* 0x98820  481   */
  uVar1 = media_setScoreChannelCount(param_1,param_2);
  lingo_markFieldDirty();
  return uVar1;
}



// ============================================================
// Function: Ordinal_480
// Address: 68098850
// Size: 9 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_480(int *param_1)
{
                    /* 0x98850  480   */
  media_isScoreReady(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_470
// Address: 68098860
// Size: 703 bytes
// Params: int param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6, undefined4 * param_7, undefined4 * param_8, int param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_470(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5
                ,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,int param_9)
{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 *puVar5;
  int iVar6;
  ulonglong uVar7;
  undefined4 local_1b8;
  undefined4 local_1a4;
  int local_19c;
  ushort local_198;
  byte local_18e;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  int local_168;
  int local_144;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc [29];
  undefined2 local_58;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_1c;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x98860  470   */
  local_1a4 = local_1a4 & 0xffff0000;
  memset((void *)((int)&local_1a4 + 2),0,0x18e);
  piVar1 = *(int **)(param_1 + 0x20);
  iVar6 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar6 = param_2;
    if (param_2 == 0) {
      iVar6 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar6;
  }
  local_174 = *param_4;
  local_1a4 = param_4[1];
  local_18c = param_4[9];
  local_188 = param_4[10];
  local_19c = param_4[2];
  local_184 = param_4[0xb];
  local_180 = param_4[0xc];
  bVar2 = *(byte *)((int)param_4 + 0xd) & 0x3f;
  if (param_4[4] != 0) {
    bVar2 = bVar2 | 0x40;
  }
  if (param_4[5] != 0) {
    bVar2 = bVar2 | 0x80;
  }
  local_198 = (ushort)bVar2;
  local_168 = iVar6;
  uVar3 = playback_getSpriteProperty(iVar6,&local_1a4);
  local_144 = playback_resolveSpriteCastMember(uVar3);
  uVar7 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  local_170 = (undefined4)uVar7;
  uVar7 = strings_floatToUint64(extraout_ECX_00,(int)(uVar7 >> 0x20));
  local_16c = (undefined4)uVar7;
  if (param_4[0x18] != 0) {
    local_18e = local_18e | 0x20;
  }
  if (param_4[0x19] != 0) {
    local_18e = local_18e | 0x40;
  }
  iVar4 = scoreEngine_setChannelField(*(uint *)(iVar6 + 0x20),param_4[1]);
  if ((iVar4 != 0) || (local_144 == 2)) {
    local_58 = 0xffff;
    if (param_9 != 0) {
      local_1b8 = *(undefined4 *)(iVar6 + 300);
      *(undefined4 *)(iVar6 + 300) = 0;
    }
    if (param_8 != (undefined4 *)0x0) {
      local_24 = (int *)events_loadSpriteScripts(*(int *)(*(int *)(iVar6 + 0x20) + 8),param_2,param_3,local_19c)
      ;
    }
    playback_renderSprite((int)&local_1a4,iVar4,1);
    if ((param_8 != (undefined4 *)0x0) && (local_24 != (int *)0x0)) {
      events_updateMovieNav(*(int *)(*(int *)(iVar6 + 0x20) + 8),local_24);
      local_24 = (int *)0x0;
      local_1c = 0;
    }
    if (param_9 != 0) {
      *(undefined4 *)(iVar6 + 300) = local_1b8;
    }
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_17c;
    param_5[1] = local_178;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_dc;
    param_6[1] = local_d8;
    param_6[2] = local_d4;
    param_6[3] = local_d0;
  }
  if (param_7 != (undefined4 *)0x0) {
    puVar5 = local_cc;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *param_7 = *puVar5;
      puVar5 = puVar5 + 1;
      param_7 = param_7 + 1;
    }
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = local_34;
    param_8[1] = local_30;
    param_8[2] = local_2c;
    param_8[3] = local_28;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_471
// Address: 68098b20
// Size: 219 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_471(int param_1,int param_2,int param_3,int *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_1a4;
  int *local_1a0;
  undefined4 local_19c;
  undefined1 local_198 [332];
  undefined2 local_4c;
  uint local_8;
  
                    /* 0x98b20  471   */
  piVar1 = *(int **)(param_1 + 0x20);
  local_4c = 0xffff;
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_19c = 0;
    local_1a0 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_1a4;
    local_1a4 = param_2;
  }
  iVar2 = scoreEngine_setChannelField(*(uint *)(iVar3 + 0x20),*(undefined4 *)(param_3 + 4));
  playback_dispatchSpriteEvent(iVar3,(int)local_198,iVar2,param_4,(int *)(param_3 + 0x24),(int *)(param_3 + 0x28),
               (int *)(param_3 + 0x2c),(int *)(param_3 + 0x30),(double *)(param_3 + 0x50),
               (double *)(param_3 + 0x58),(int *)(param_3 + 0x60),(int *)(param_3 + 100));
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_1a0;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_404
// Address: 68098c00
// Size: 514 bytes
// Params: int * param_1, int param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_404(int *param_1,int param_2,int param_3,uint *param_4)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  undefined4 local_c;
  int local_8;
  
                    /* 0x98c00  404   */
  uVar5 = 0;
  local_8 = 0;
  local_c = 0;
  Ordinal_1130(param_4,0x68);
  if (param_3 - 1U < 1000) {
    iVar3 = Ordinal_425(param_1,param_2,0);
    if (iVar3 != 0) {
      iVar3 = media_lockScoreData(param_1,&local_8,&local_c);
      if (param_3 <= iVar3) {
        iVar3 = param_3 + 5;
        if ((iVar3 < 0) || (0x3ed < iVar3)) {
          pbVar6 = (byte *)0x0;
        }
        else {
          pbVar6 = (byte *)(iVar3 * 0x30 + local_8);
        }
        *param_4 = (uint)*pbVar6;
        uVar1 = xtra_readBE16(pbVar6 + 4);
        *(undefined2 *)(param_4 + 1) = uVar1;
        uVar1 = xtra_readBE16(pbVar6 + 6);
        *(undefined2 *)((int)param_4 + 6) = uVar1;
        *(byte *)(param_4 + 3) = (pbVar6[0x16] & 0xf) - 1;
        param_4[0x11] = pbVar6[0x16] >> 4 & 1;
        uVar4 = xtra_readBE32Ptr(pbVar6 + 8);
        param_4[2] = uVar4;
        *(byte *)((int)param_4 + 0xd) = pbVar6[1] & 0x3f;
        param_4[4] = pbVar6[1] >> 6 & 1;
        param_4[5] = (uint)(pbVar6[1] >> 7);
        *(byte *)(param_4 + 6) = pbVar6[0x15];
        *(byte *)((int)param_4 + 0x1d) = pbVar6[3];
        *(byte *)((int)param_4 + 0x1e) = pbVar6[0x19];
        *(byte *)((int)param_4 + 0x1f) = pbVar6[0x1b];
        *(byte *)(param_4 + 8) = pbVar6[0x14] >> 5 & 1;
        *(byte *)((int)param_4 + 0x19) = pbVar6[2];
        *(byte *)((int)param_4 + 0x1a) = pbVar6[0x18];
        *(byte *)((int)param_4 + 0x1b) = pbVar6[0x1a];
        *(byte *)(param_4 + 7) = pbVar6[0x14] >> 4 & 1;
        sVar2 = xtra_readBE16(pbVar6 + 0xe);
        param_4[9] = (int)sVar2;
        sVar2 = xtra_readBE16(pbVar6 + 0xc);
        param_4[10] = (int)sVar2;
        sVar2 = xtra_readBE16(pbVar6 + 0x12);
        param_4[0xb] = (int)sVar2;
        sVar2 = xtra_readBE16(pbVar6 + 0x10);
        param_4[0xc] = (int)sVar2;
        param_4[0xd] = (uint)(pbVar6[0x14] >> 7);
        param_4[0xe] = pbVar6[0x14] >> 6 & 1;
        param_4[0x10] = (uint)(pbVar6[0x16] >> 7);
        param_4[0xf] = 0;
        *(byte *)(param_4 + 0x12) = pbVar6[0x14] & 0xf;
        iVar3 = xtra_readBE32Ptr(pbVar6 + 0x1c);
        *(double *)(param_4 + 0x14) = (double)iVar3 / 100.0;
        iVar3 = xtra_readBE32Ptr(pbVar6 + 0x20);
        *(double *)(param_4 + 0x16) = (double)iVar3 / 100.0;
        param_4[0x18] = pbVar6[0x16] >> 5 & 1;
        param_4[0x19] = pbVar6[0x16] >> 6 & 1;
        uVar5 = 1;
      }
    }
  }
  if (local_8 != 0) {
    media_unlockScoreData(param_1,&local_8,&local_c);
  }
  return uVar5;
}



// ============================================================
// Function: Ordinal_405
// Address: 68098e10
// Size: 527 bytes
// Params: int * param_1, int param_2, int param_3, undefined1 * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_405(int *param_1,int param_2,int param_3,undefined1 *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int local_8;
  
                    /* 0x98e10  405   */
  uVar3 = 0;
  local_8 = 0;
  if (param_3 - 1U < 1000) {
    iVar2 = Ordinal_425(param_1,param_2,param_5);
    if (iVar2 != 0) {
      iVar2 = media_lockScoreData(param_1,&local_8,(undefined4 *)0x0);
      if (param_3 <= iVar2) {
        iVar2 = media_getScoreState(param_1);
        if (param_2 == iVar2) {
          iVar2 = param_3 + 5;
          if ((iVar2 < 0) || (0x3ed < iVar2)) {
            puVar4 = (undefined1 *)0x0;
          }
          else {
            puVar4 = (undefined1 *)(iVar2 * 0x30 + local_8);
          }
          *puVar4 = *param_4;
          xtra_readBE32(puVar4 + 6);
          xtra_readBE32(puVar4 + 4);
          xtra_skipBytes(puVar4 + 8);
          bVar1 = param_4[0xc] + 1 & 0xf;
          if (*(int *)(param_4 + 0x44) != 0) {
            bVar1 = bVar1 | 0x10;
          }
          if (*(int *)(param_4 + 0x40) != 0) {
            bVar1 = bVar1 | 0x80;
          }
          puVar4[0x16] = bVar1;
          bVar1 = param_4[0xd] & 0x3f;
          if (*(int *)(param_4 + 0x10) != 0) {
            bVar1 = bVar1 | 0x40;
          }
          if (*(int *)(param_4 + 0x14) != 0) {
            bVar1 = bVar1 | 0x80;
          }
          puVar4[1] = bVar1;
          puVar4[0x15] = param_4[0x18];
          puVar4[3] = param_4[0x1d];
          puVar4[0x19] = param_4[0x1e];
          puVar4[0x1b] = param_4[0x1f];
          puVar4[2] = param_4[0x19];
          puVar4[0x18] = param_4[0x1a];
          puVar4[0x1a] = param_4[0x1b];
          xtra_readBE32(puVar4 + 0xe);
          xtra_readBE32(puVar4 + 0xc);
          xtra_readBE32(puVar4 + 0x12);
          xtra_readBE32(puVar4 + 0x10);
          bVar1 = param_4[0x48] & 0xf;
          if (*(int *)(param_4 + 0x34) != 0) {
            bVar1 = bVar1 | 0x80;
          }
          if (*(int *)(param_4 + 0x38) != 0) {
            bVar1 = bVar1 | 0x40;
          }
          if (param_4[0x1c] == '\x01') {
            bVar1 = bVar1 | 0x10;
          }
          if (param_4[0x20] == '\x01') {
            bVar1 = bVar1 | 0x20;
          }
          puVar4[0x14] = bVar1;
          xtra_skipBytes(puVar4 + 0x1c);
          xtra_skipBytes(puVar4 + 0x20);
          if (*(int *)(param_4 + 0x60) == 0) {
            puVar4[0x16] = puVar4[0x16] & 0xdf;
          }
          else {
            puVar4[0x16] = puVar4[0x16] | 0x20;
          }
          if (*(int *)(param_4 + 100) == 0) {
            puVar4[0x16] = puVar4[0x16] & 0xbf;
          }
          else {
            puVar4[0x16] = puVar4[0x16] | 0x40;
          }
          uVar3 = 1;
        }
      }
    }
    if (local_8 != 0) {
      media_unlockScoreData(param_1,&local_8,(undefined4 *)0x0);
    }
  }
  return uVar3;
}



// ============================================================
// Function: Ordinal_406
// Address: 68099020
// Size: 472 bytes
// Params: int * param_1, int param_2, undefined1 * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_406(int *param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 local_c;
  undefined1 *local_8;
  
                    /* 0x99020  406   */
  local_8 = (undefined1 *)0x0;
  local_c = 0;
  Ordinal_1130(param_3,0x50);
  iVar8 = Ordinal_425(param_1,param_2,0);
  if (iVar8 != 0) {
    media_lockScoreData(param_1,&local_8,&local_c);
    puVar6 = local_8;
    puVar1 = local_8 + 0x60;
    puVar3 = local_8 + 0x90;
    puVar2 = local_8 + 0x30;
    puVar4 = local_8 + 0xc0;
    puVar5 = local_8 + 0xf0;
    *param_3 = local_8[0x36];
    uVar7 = xtra_readBE16(local_8 + 0x34);
    *(undefined2 *)(param_3 + 2) = uVar7;
    param_3[4] = puVar6[0x37];
    uVar9 = xtra_readBE32Ptr(puVar2);
    *(undefined4 *)(param_3 + 8) = uVar9;
    uVar7 = xtra_readBE16(puVar5);
    *(undefined2 *)(param_3 + 0xc) = uVar7;
    uVar7 = xtra_readBE16(puVar6 + 0xf2);
    *(undefined2 *)(param_3 + 0xe) = uVar7;
    param_3[0x10] = puVar6[0xf4] & 0x1f;
    param_3[0x11] = puVar6[0xf5];
    param_3[0x12] = puVar6[0xf6];
    param_3[0x13] = puVar6[0xf7];
    uVar7 = xtra_readBE16(puVar6 + 0xf8);
    *(undefined2 *)(param_3 + 0x14) = uVar7;
    uVar7 = xtra_readBE16(puVar6 + 0xfa);
    *(undefined2 *)(param_3 + 0x16) = uVar7;
    param_3[0x18] = 0;
    param_3[0x19] = puVar6[0xfd];
    param_3[0x1a] = 0;
    param_3[0x1b] = puVar6[0xff];
    uVar9 = xtra_readBE32Ptr(puVar6 + 0x100);
    *(undefined4 *)(param_3 + 0x1c) = uVar9;
    uVar7 = xtra_readBE16(puVar1);
    *(undefined2 *)(param_3 + 0x20) = uVar7;
    uVar7 = xtra_readBE16(puVar6 + 0x62);
    *(undefined2 *)(param_3 + 0x22) = uVar7;
    param_3[0x24] = puVar6[0x68];
    uVar9 = xtra_readBE32Ptr(puVar6 + 100);
    *(undefined4 *)(param_3 + 0x28) = uVar9;
    uVar7 = xtra_readBE16(puVar4);
    *(undefined2 *)(param_3 + 0x2c) = uVar7;
    uVar7 = xtra_readBE16(puVar6 + 0xc2);
    *(undefined2 *)(param_3 + 0x2e) = uVar7;
    param_3[0x30] = puVar6[200];
    uVar9 = xtra_readBE32Ptr(puVar6 + 0xc4);
    *(undefined4 *)(param_3 + 0x34) = uVar9;
    uVar7 = xtra_readBE16(puVar3);
    *(undefined2 *)(param_3 + 0x38) = uVar7;
    uVar7 = xtra_readBE16(puVar6 + 0x92);
    *(undefined2 *)(param_3 + 0x3a) = uVar7;
    param_3[0x3c] = puVar6[0x98];
    uVar9 = xtra_readBE32Ptr(puVar6 + 0x94);
    *(undefined4 *)(param_3 + 0x40) = uVar9;
    uVar7 = xtra_readBE16(puVar6);
    *(undefined2 *)(param_3 + 0x44) = uVar7;
    uVar7 = xtra_readBE16(puVar6 + 2);
    *(undefined2 *)(param_3 + 0x46) = uVar7;
    param_3[0x48] = puVar6[8];
    uVar9 = xtra_readBE32Ptr(puVar6 + 4);
    *(undefined4 *)(param_3 + 0x4c) = uVar9;
  }
  if (local_8 != (undefined1 *)0x0) {
    media_unlockScoreData(param_1,&local_8,&local_c);
  }
  return iVar8 != 0;
}



// ============================================================
// Function: Ordinal_407
// Address: 68099200
// Size: 484 bytes
// Params: int * param_1, int param_2, undefined1 * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_407(int *param_1,int param_2,undefined1 *param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 *local_8;
  
                    /* 0x99200  407   */
  uVar8 = 0;
  local_8 = (undefined1 *)0x0;
  iVar7 = Ordinal_425(param_1,param_2,param_4);
  if (iVar7 != 0) {
    media_lockScoreData(param_1,&local_8,(undefined4 *)0x0);
    iVar7 = media_getScoreState(param_1);
    puVar6 = local_8;
    if (param_2 == iVar7) {
      puVar1 = local_8 + 0x60;
      puVar3 = local_8 + 0x90;
      puVar2 = local_8 + 0x30;
      puVar4 = local_8 + 0xc0;
      puVar5 = local_8 + 0xf0;
      local_8[0x36] = *param_3;
      xtra_readBE32(local_8 + 0x34);
      puVar6[0x37] = param_3[4];
      xtra_skipBytes(puVar2);
      xtra_readBE32(puVar6 + 0xf2);
      xtra_readBE32(puVar5);
      puVar6[0xf4] = param_3[0x10] & 0x1f;
      puVar6[0xf5] = param_3[0x11];
      puVar6[0xf6] = param_3[0x12];
      puVar6[0xf7] = param_3[0x13];
      xtra_readBE32(puVar6 + 0xf8);
      xtra_readBE32(puVar6 + 0xfa);
      puVar6[0xfd] = param_3[0x19];
      puVar6[0xff] = param_3[0x1b];
      xtra_skipBytes(puVar6 + 0x100);
      xtra_readBE32(puVar6 + 0x62);
      xtra_readBE32(puVar1);
      puVar6[0x68] = param_3[0x24];
      xtra_skipBytes(puVar6 + 100);
      xtra_readBE32(puVar6 + 0xc2);
      xtra_readBE32(puVar4);
      puVar6[200] = param_3[0x30];
      xtra_skipBytes(puVar6 + 0xc4);
      xtra_readBE32(puVar6 + 0x92);
      xtra_readBE32(puVar3);
      puVar6[0x98] = param_3[0x3c];
      xtra_skipBytes(puVar6 + 0x94);
      xtra_readBE32(puVar6 + 2);
      xtra_readBE32(puVar6);
      puVar6[8] = param_3[0x48];
      xtra_skipBytes(puVar6 + 4);
      uVar8 = 1;
    }
  }
  if (local_8 != (undefined1 *)0x0) {
    media_unlockScoreData(param_1,&local_8,(undefined4 *)0x0);
  }
  return uVar8;
}



// ============================================================
// Function: Ordinal_486
// Address: 680993f0
// Size: 288 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_486(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 local_c;
  undefined1 *local_8;
  
                    /* 0x993f0  486   */
  local_8 = (undefined1 *)0x0;
  local_c = 0;
  media_lockScoreData(param_1,&local_8,&local_c);
  *param_4 = 0;
  if (param_2 <= param_3) {
    iVar2 = param_2 + 5;
    iVar3 = iVar2 * 0x30;
    do {
      puVar4 = local_8;
      if (*(short *)((int)param_4 + 2) != 0) break;
      if (0 < param_2) {
        if ((iVar2 < 0) || (0x3ed < iVar2)) {
          uVar1 = xtra_readBE16((undefined1 *)0x4);
          puVar4 = (undefined1 *)0x6;
        }
        else {
          uVar1 = xtra_readBE16(local_8 + iVar3 + 4);
          puVar4 = puVar4 + iVar3 + 6;
        }
        goto LAB_680994bf;
      }
      switch(iVar2) {
      case 0:
        break;
      case 1:
        *param_4 = 0;
        goto switchD_68099477_default;
      case 2:
        puVar4 = local_8 + 0x60;
        break;
      case 3:
        puVar4 = local_8 + 0x90;
        break;
      case 4:
        puVar4 = local_8 + 0xc0;
        break;
      case 5:
        puVar4 = local_8 + 0xf0;
        break;
      default:
        goto switchD_68099477_default;
      }
      uVar1 = xtra_readBE16(puVar4);
      puVar4 = puVar4 + 2;
LAB_680994bf:
      *(undefined2 *)param_4 = uVar1;
      uVar1 = xtra_readBE16(puVar4);
      *(undefined2 *)((int)param_4 + 2) = uVar1;
switchD_68099477_default:
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x30;
    } while (param_2 <= param_3);
  }
  if (*(short *)((int)param_4 + 2) != 0) {
    param_2 = param_2 + -1;
  }
  if (local_8 != (undefined1 *)0x0) {
    media_unlockScoreData(param_1,&local_8,&local_c);
  }
  return param_2;
}



// ============================================================
// Function: Ordinal_487
// Address: 68099530
// Size: 292 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_487(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 local_c;
  undefined1 *local_8;
  
                    /* 0x99530  487   */
  uVar2 = 0;
  local_8 = (undefined1 *)0x0;
  local_c = 0;
  media_lockScoreData(param_1,&local_8,&local_c);
  puVar3 = local_8;
  if (0 < param_2) {
    iVar1 = param_2 + 5;
    if ((iVar1 < 0) || (0x3ed < iVar1)) {
      puVar3 = (undefined1 *)0x0;
    }
    else {
      puVar3 = local_8 + iVar1 * 0x30;
    }
    xtra_readBE32(puVar3 + 6);
    xtra_readBE32(puVar3 + 4);
    if ((*(unsigned short *)((char *)&param_3 + 2)) == 0) {
      *puVar3 = 0;
    }
    goto switchD_680995ab_caseD_fffffffc;
  }
  switch(param_2) {
  case 0:
    puVar4 = local_8 + 0xf0;
    xtra_readBE32(local_8 + 0xf2);
    xtra_readBE32(puVar4);
    if ((*(unsigned short *)((char *)&param_3 + 2)) == 0) {
      puVar3[0xf4] = 0;
    }
    goto switchD_680995ab_caseD_fffffffc;
  case -5:
    puVar3 = local_8 + 2;
    puVar4 = local_8;
    break;
  case -4:
    goto switchD_680995ab_caseD_fffffffc;
  case -3:
    puVar3 = local_8 + 0x62;
    puVar4 = local_8 + 0x60;
    break;
  case -2:
    puVar3 = local_8 + 0x92;
    puVar4 = local_8 + 0x90;
    break;
  case -1:
    puVar3 = local_8 + 0xc2;
    puVar4 = local_8 + 0xc0;
    break;
  default:
    goto switchD_680995ab_default;
  }
  xtra_readBE32(puVar3);
  xtra_readBE32(puVar4);
switchD_680995ab_caseD_fffffffc:
  uVar2 = 1;
switchD_680995ab_default:
  if (local_8 != (undefined1 *)0x0) {
    media_unlockScoreData(param_1,&local_8,&local_c);
  }
  return uVar2;
}



// ============================================================
// Function: Ordinal_408
// Address: 68099670
// Size: 24 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_408(int *param_1,int param_2)
{
                    /* 0x99670  408   */
  lingo_getSpriteRect(param_1,1,-1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_409
// Address: 68099690
// Size: 50 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint Ordinal_409(int *param_1)

{
  uint uVar1;
  
                    /* 0x99690  409   */
  uVar1 = lingo_getSpriteRect((int *)*param_1,1,-1,1);
  media_unlockScoreData((int *)*param_1,(undefined4 *)0x0,(undefined4 *)0x0);
  media_getScorePlayState(param_1);
  return uVar1;
}



// ============================================================
// Function: Ordinal_410
// Address: 680996d0
// Size: 176 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_410(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x996d0  410   */
  piVar1 = *(int **)(param_1 + 0x20);
  local_18 = (int *)0x0;
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar2 = media_getVtableFunc(*(int **)(iVar3 + 0x28));
  if (iVar2 == 0) {
    if (local_18 != (int *)0x0) {
      media_getScorePlayState((int *)&local_18);
    }
  }
  else {
    local_18 = (int *)media_addScoreRef(*(undefined4 **)(iVar3 + 0x28));
    media_lockScoreData(local_18,(undefined4 *)0x0,(undefined4 *)0x0);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_411
// Address: 68099780
// Size: 18 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall Ordinal_411(void *this,int param_1)
{
                    /* 0x99780  411   */
  media_readPlaybackBlock(this,param_1,0);
  return 0;
}



// ============================================================
// Function: lingo_getSpriteOpCount (FUN_680997a0)
// Address: 680997a0
// Size: 18 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall lingo_getSpriteOpCount(void *this,int param_1)
{
  media_readPlaybackBlock(this,param_1,1);
  return 0;
}



// ============================================================
// Function: Ordinal_412
// Address: 680997c0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_412(int param_1)
{
                    /* 0x997c0  412   */
  media_loadScoreData(param_1);
  return 0;
}


