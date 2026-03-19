// Module: lingo
// Topic: Score property setters and modification functions
// Address range: 0x68090900 - 0x6809B520
// Functions (43):
//   lingo_getMutateContext
//   lingo_getMutateRef
//   lingo_getMutateState
//   lingo_initMutateData
//   lingo_setPropertyValue
//   Ordinal_134
//   score_saveMovie (FUN_68091db0)
//   Ordinal_49
//   lingo_mutateMember
//   lingo_readPlaybackMember
//   Ordinal_75
//   Ordinal_76
//   Ordinal_152
//   Ordinal_58
//   Ordinal_154
//   Ordinal_47
//   Ordinal_156
//   Ordinal_157
//   Ordinal_158
//   Ordinal_159
//   Ordinal_104
//   Ordinal_55
//   Ordinal_50
//   Ordinal_51
//   Ordinal_189
//   Ordinal_52
//   Ordinal_176
//   Ordinal_161
//   Ordinal_162
//   Ordinal_53
//   Ordinal_178
//   lingo_mutateChannel
//   lingo_mutateChannelEx
//   score_setProperty (FUN_68094890)
//   Ordinal_183
//   Ordinal_184
//   lingo_mutateData
//   lingo_getMediaDataOffset
//   lingo_checkMovieLoaded
//   lingo_mutateScoreData
//   lingo_mutateProperty
//   lingo_updateState
//   lingo_flushState


// ============================================================
// Function: lingo_getMutateContext (FUN_68090900)
// Address: 68090900
// Size: 60 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getMutateContext(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = playback_setLifecycleState(unaff_ESI,0);
  if (iVar1 != 0) {
    playback_getLifecycleCount(unaff_ESI);
    scoreEngine_markDirty(*(int *)(unaff_ESI + 0x20),1);
    scoreEngine_setCastXtraFlag(*(int *)(unaff_ESI + 0x20),0);
    *(undefined4 *)(unaff_ESI + 0x70) = 0;
    *(undefined4 *)(unaff_ESI + 0x74) = 0;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: lingo_getMutateRef (FUN_68090940)
// Address: 68090940
// Size: 68 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getMutateRef(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0x34c) == 0) {
    iVar1 = Ordinal_1150(0x10,0x10,4);
    *(int *)(unaff_ESI + 0x34c) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = Ordinal_1152(*(undefined4 *)(unaff_ESI + 0x34c),&param_1);
  return uVar2;
}



// ============================================================
// Function: lingo_getMutateState (FUN_68090990)
// Address: 68090990
// Size: 98 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getMutateState(void)
{
  int *piVar1;
  undefined4 *unaff_ESI;
  undefined4 local_f0;
  undefined1 local_ec [228];
  uint local_8;
  
  local_f0 = 0;
  memset(local_ec,0,0xe4);
  piVar1 = (int *)Ordinal_1114(*unaff_ESI);
  *(undefined4 **)(*piVar1 + 0x24) = &local_f0;
  scoreEngine_updateScore(piVar1,0);
  Ordinal_1113();
  return 0;
}



// ============================================================
// Function: lingo_initMutateData (FUN_68090a00)
// Address: 68090a00
// Size: 142 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_initMutateData(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(unaff_EDI + 0x34c) == 0) {
    return 0;
  }
  iVar1 = Ordinal_1154(*(int *)(unaff_EDI + 0x34c));
  do {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = Ordinal_1155(*(undefined4 *)(unaff_EDI + 0x34c),iVar1 + -1,&local_8);
    if (iVar2 != 0) {
      iVar2 = Ordinal_1114(local_8);
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = Ordinal_1319(param_1,iVar2 + 0x28);
      if (iVar2 != 0) {
        Ordinal_1115(local_8);
        return 1;
      }
      Ordinal_1115(local_8);
    }
    iVar1 = iVar1 + -1;
  } while( true );
}



// ============================================================
// Function: lingo_setPropertyValue (FUN_68090a90)
// Address: 68090a90
// Size: 151 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_setPropertyValue(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  undefined4 local_8;
  
  local_8 = 0;
  if ((*(int *)(unaff_EBX + 0x34c) == 0) ||
     (iVar2 = Ordinal_1154(*(int *)(unaff_EBX + 0x34c)), iVar2 == 0)) {
    return 0;
  }
  do {
    iVar3 = Ordinal_1155(*(undefined4 *)(unaff_EBX + 0x34c),iVar2 + -1,&local_8);
    if (iVar3 != 0) {
      iVar3 = Ordinal_1114(local_8);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = Ordinal_1319(param_1,iVar3 + 0x28);
      uVar1 = local_8;
      if (iVar3 != 0) {
        if (param_2 != 0) {
          Ordinal_1160(*(undefined4 *)(unaff_EBX + 0x34c),iVar2 + -1);
        }
        Ordinal_1115(local_8);
        return uVar1;
      }
      Ordinal_1115(local_8);
    }
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return 0;
    }
  } while( true );
}



// ============================================================
// Function: Ordinal_134
// Address: 68091c00
// Size: 424 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_134(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *local_434;
  undefined4 *local_430;
  int local_42c;
  int *local_428;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
                    /* 0x91c00  134   */
  local_430 = param_2;
  uVar5 = 0;
  if (param_1 == 0) {
    local_434 = (int *)0x0;
  }
  else {
    local_434 = *(int **)(param_1 + 0x20);
  }
  iVar3 = 0;
  if ((local_434 != (int *)0x0) && (local_434[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *local_434;
    }
    Ordinal_2330();
    local_424 = 0;
    local_428 = DAT_68196374;
    DAT_68196374 = &local_42c;
    local_42c = iVar3;
  }
  if ((*(int *)(*(int *)(iVar3 + 0x20) + 0x444) == 0) ||
     (iVar3 = xtra_getScriptContext(*(int *)(*(int *)(iVar3 + 0x20) + 0x10)), iVar3 == 0)) goto LAB_68091d7a;
  puVar4 = local_430;
  puVar1 = local_420;
  for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
  }
  iVar2 = Ordinal_1316(local_420);
  if ((iVar2 == 0) || (iVar2 = Ordinal_1356(local_420,0,1), iVar2 == 0)) goto LAB_68091d7a;
  iVar3 = lingo_getPlaybackValue(iVar3,local_420);
  puVar4 = local_430;
  if (iVar3 != 0) {
    puVar1 = (undefined4 *)Ordinal_1351(local_430);
    if (puVar1 == (undefined4 *)0x0) {
      local_430 = puVar1;
      iVar3 = Ordinal_1401(&local_430,puVar4,0xffffffff);
      if (iVar3 == 0) goto LAB_68091d68;
      Ordinal_1407(&local_430);
    }
    iVar3 = Ordinal_1354(puVar4,local_420);
    if ((iVar3 != 0) && (iVar3 = crt_openStreamForRead(puVar4,&local_430), iVar3 == 0)) {
      crt_streamClose((int)local_430);
      uVar5 = 1;
    }
  }
LAB_68091d68:
  Ordinal_1352(local_420);
LAB_68091d7a:
  if (local_434 != (int *)0x0) {
    DAT_68196374 = local_428;
    Ordinal_2331(uVar5);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_49
// Address: 680936a0
// Size: 186 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_49(int param_1,int param_2,uint param_3)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x936a0  49   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  if ((*pbVar2 & 8) != 0) {
    playback_setFrameInternal(pbVar2,param_2,param_3);
    scoreEngine_markDirty(*(int *)(pbVar2 + 0x20),1);
  }
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_mutateMember (FUN_68093760)
// Address: 68093760
// Size: 197 bytes
// Params: int param_1, byte * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mutateMember(int param_1,byte *param_2,int param_3)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  if (param_2 != (byte *)0x0) {
    pbVar2 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    playback_setFlagsAndDestroy(pbVar2,param_3);
    scoreEngine_markDirty(*(int *)(pbVar2 + 0x20),1);
  }
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_readPlaybackMember (FUN_68093830)
// Address: 68093830
// Size: 156 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_readPlaybackMember(int param_1,undefined4 param_2)
{
  byte *pbVar1;
  undefined4 *puVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0x20);
  }
  pbVar1 = (byte *)0x0;
  if ((puVar2 != (undefined4 *)0x0) && (puVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(undefined4 **)(param_1 + 0x20) == (undefined4 *)0x0 ||
        (pbVar1 = (byte *)**(undefined4 **)(param_1 + 0x20), pbVar1 == (byte *)0x0)))) {
      pbVar1 = (byte *)*puVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar1;
  }
  if ((*pbVar1 & 8) != 0) {
    media_readPlaybackData(*(int *)(pbVar1 + 0x28),param_2,1);
  }
  if (puVar2 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_75
// Address: 680938d0
// Size: 161 bytes
// Params: int param_1, byte * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_75(int param_1,byte *param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x938d0  75   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar2 = 0;
  pbVar3 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    iVar2 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar3 & 8) != 0) {
    playback_setSpriteFrame(pbVar3,param_3);
  }
  lingo_getMovieRef(iVar2);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_76
// Address: 68093980
// Size: 124 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_76(int param_1,byte *param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93980  76   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  playback_invalidateSpriteRegion(pbVar2);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_152
// Address: 68093a00
// Size: 194 bytes
// Params: int param_1, uint param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_152(int param_1,uint param_2,int param_3)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93a00  152   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  if ((*pbVar2 & 8) != 0) {
    playback_updateFrameProperty(pbVar2,param_2,param_3);
    scoreEngine_writePropertyFlags(*(int **)(pbVar2 + 0x20));
    scoreEngine_markDirty(*(int *)(pbVar2 + 0x20),1);
  }
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_58
// Address: 68093ad0
// Size: 163 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_58(int param_1,byte *param_2)
{
  byte *pbVar1;
  int *piVar2;
  undefined4 uVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93ad0  58   */
  pbVar1 = (byte *)0x0;
  uVar3 = 0;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar1 = (byte *)**(int **)(param_1 + 0x20), pbVar1 == (byte *)0x0)))) {
      pbVar1 = (byte *)*piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar1;
  }
  if (param_2 != (byte *)0x0) {
    pbVar1 = param_2;
  }
  if ((*pbVar1 & 8) != 0) {
    uVar3 = playback_getCurrentFrame(pbVar1);
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(uVar3);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_154
// Address: 68093b80
// Size: 131 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_154(int param_1,byte *param_2)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93b80  154   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    media_isScoreLocked(*(int **)(pbVar2 + 0x28));
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_47
// Address: 68093c10
// Size: 165 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_47(int param_1,int param_2)
{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  uint *local_14;
  uint **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93c10  47   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  puVar2 = (uint *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (puVar2 = (uint *)**(int **)(param_1 + 0x20), puVar2 == (uint *)0x0)))) {
      puVar2 = (uint *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = puVar2;
  }
  playback_getLifecycleBlock(puVar2,param_2);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_156
// Address: 68093cc0
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_156(int param_1)
{
  uint *puVar1;
  int *piVar2;
  uint *local_14;
  uint **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93cc0  156   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  puVar1 = (uint *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (puVar1 = (uint *)**(int **)(param_1 + 0x20), puVar1 == (uint *)0x0)))) {
      puVar1 = (uint *)*piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = puVar1;
  }
  playback_getBlockFlag(puVar1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_157
// Address: 68093d50
// Size: 197 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_157(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93d50  157   */
  piVar1 = *(int **)(param_1 + 0x20);
  local_18 = 0;
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    local_18 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  *(int *)(*(int *)(iVar2 + 0x20) + 0x5fc) = param_3;
  *(int *)(*(int *)(iVar2 + 0x20) + 0x600) = param_3;
  if (param_3 != 0) {
    *(undefined4 *)(iVar2 + 0x70) = 0;
    *(undefined4 *)(iVar2 + 0x74) = 0;
  }
  playback_clearSpriteDisplayState(iVar2);
  if (param_3 != 0) {
    Ordinal_1904();
  }
  lingo_getMovieRef(local_18);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_158
// Address: 68093e20
// Size: 181 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_158(int param_1,int param_2,undefined4 *param_3)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93e20  158   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  iVar4 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (param_3 != (undefined4 *)0x0) {
    if ((*(int *)(*(int *)(iVar4 + 0x20) + 0x5fc) == 0) &&
       (*(int *)(*(int *)(iVar4 + 0x20) + 0x600) == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    *param_3 = uVar2;
  }
  lingo_getMovieRef(iVar3);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_159
// Address: 68093ee0
// Size: 179 bytes
// Params: int param_1, ushort param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_159(int param_1,ushort param_2)
{
  int *piVar1;
  int iVar2;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x93ee0  159   */
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  local_18 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    local_18 = *(int *)(piVar1[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  playback_setScaleRatio(iVar2,param_2);
  rendering_onPause(iVar2,param_2);
  lingo_getMovieRef(local_18);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_104
// Address: 68094090
// Size: 165 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_104(int param_1,uint param_2)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94090  104   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  playback_applyFrameFlags(pbVar2,param_2);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_55
// Address: 68094140
// Size: 162 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_55(int param_1)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94140  55   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  playback_getLifecycleInfo(pbVar2);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_50
// Address: 680941f0
// Size: 175 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_50(int param_1,int *param_2,int param_3)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x941f0  50   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  playback_setFrameRange(pbVar2,param_2,param_3);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_51
// Address: 680942a0
// Size: 172 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_51(int param_1,int param_2)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x942a0  51   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  playback_setTempo(pbVar2,param_2);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_189
// Address: 68094350
// Size: 172 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_189(int param_1,undefined4 *param_2)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94350  189   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  playback_getStageRect(pbVar2,param_2);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_52
// Address: 68094400
// Size: 150 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_52(int param_1,int param_2)
{
  byte *pbVar1;
  int *piVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94400  52   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  pbVar1 = (byte *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar1 = (byte *)**(int **)(param_1 + 0x20), pbVar1 == (byte *)0x0)))) {
      pbVar1 = (byte *)*piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar1;
  }
  *(int *)(*(int *)(pbVar1 + 0x20) + 0x670) = param_2;
  playback_setSoundProperty(pbVar1,param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_176
// Address: 680944a0
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_176(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x944a0  176   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_161
// Address: 68094530
// Size: 139 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_161(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94530  161   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  *(int *)(*(int *)(iVar2 + 0x20) + 0x674) = param_3;
  if (param_3 != 0) {
    scoreEngine_updateMonitorRegions(*(int *)(iVar2 + 0x20));
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_162
// Address: 680945c0
// Size: 124 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_162(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x945c0  162   */
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
// Function: Ordinal_53
// Address: 68094640
// Size: 144 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_53(int param_1,undefined4 param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94640  53   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x678) = param_2;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_178
// Address: 680946d0
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_178(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x946d0  178   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_mutateChannel (FUN_68094760)
// Address: 68094760
// Size: 153 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mutateChannel(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*(uint *)(*(int *)(iVar2 + 0x20) + 0x67c) != (uint)(param_3 == 0)) &&
     (*(uint *)(*(int *)(iVar2 + 0x20) + 0x67c) = (uint)(param_3 == 0), param_3 != 0)) {
    rendering_updateStageDisplay(*(int *)(iVar2 + 0x24));
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_mutateChannelEx (FUN_68094800)
// Address: 68094800
// Size: 131 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mutateChannelEx(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
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
// Function: Ordinal_183
// Address: 68094a20
// Size: 182 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_183(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94a20  183   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  playback_initLifecycleBlock(iVar2,param_2,param_3);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_184
// Address: 68094ae0
// Size: 139 bytes
// Params: int param_1, int param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_184(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94ae0  184   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  playback_initLifecycle(iVar2,param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_mutateData (FUN_68094b70)
// Address: 68094b70
// Size: 312 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mutateData(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  int *piVar2;
  int local_94;
  undefined1 local_90 [8];
  int local_88;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = param_2;
  local_18 = param_3;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = (int *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_94 = 0;
  memset(local_90,0,0x4c);
  if (local_18 != (undefined4 *)0x0) {
    iVar1 = Ordinal_82(&local_44,*param_1,0);
    if (iVar1 != 0) {
      local_2c = &local_94;
      iVar1 = Ordinal_84(local_2c,(int)&local_44,0,1,(undefined4 *)0x0,(undefined1 *)0x0,0);
      if (iVar1 != 0) {
        if (local_88 == 0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = *(int **)(local_88 + 0x20);
        }
        iVar1 = 0;
        if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
          if ((local_88 == 0) ||
             ((*(int **)(local_88 + 0x20) == (int *)0x0 ||
              (iVar1 = **(int **)(local_88 + 0x20), iVar1 == 0)))) {
            iVar1 = *piVar2;
          }
          Ordinal_2330();
          local_c = 0;
          local_10 = DAT_68196374;
          DAT_68196374 = &local_14;
          local_14 = iVar1;
        }
        playback_initMediaLoadState(iVar1,local_1c,local_18);
        if (piVar2 != (int *)0x0) {
          DAT_68196374 = local_10;
          Ordinal_2331();
        }
      }
    }
  }
  Ordinal_85(&local_94,0);
  Ordinal_83();
  return 0;
}



// ============================================================
// Function: lingo_getMediaDataOffset (FUN_68095030)
// Address: 68095030
// Size: 151 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getMediaDataOffset(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  media_getDataOffset(*(int *)(iVar1 + 4));
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_checkMovieLoaded (FUN_680950d0)
// Address: 680950d0
// Size: 95 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_checkMovieLoaded(int *param_1)
{
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  lingo_isMovieLoaded(param_1);
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_mutateScoreData (FUN_68095510)
// Address: 68095510
// Size: 141 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mutateScoreData(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  scoreEngine_editFrameRange(*(int **)(iVar2 + 0x20),param_3,param_4,0,0,(int *)0x0);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_mutateProperty (FUN_6809b350)
// Address: 6809b350
// Size: 19 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_mutateProperty(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x314) = param_2;
  return 0;
}



// ============================================================
// Function: lingo_updateState (FUN_6809b500)
// Address: 6809b500
// Size: 24 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_updateState(int param_1)
{
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined1 *)(param_1 + 0x110) = 0;
  return 0;
}



// ============================================================
// Function: lingo_flushState (FUN_6809b520)
// Address: 6809b520
// Size: 30 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_flushState(int param_1)
{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  *(undefined1 *)(param_1 + 0x214) = 0;
  return 0;
}


