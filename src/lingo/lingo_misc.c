// Module: lingo
// Topic: Miscellaneous utilities and helpers
// Address range: 0x68090FA0 - 0x6809B8C0
// Functions (21):
//   Ordinal_133
//   Ordinal_71
//   Ordinal_185
//   Ordinal_186
//   Ordinal_187
//   Ordinal_188
//   Ordinal_980
//   lingo_getMiscState
//   Ordinal_215
//   Ordinal_216
//   lingo_formatDebugMsg (lingo_formatDebugMsg)
//   lingo_formatDebugMsgEx
//   lingo_showErrorDialog
//   lingo_checkMovieState
//   lingo_isMovieLoaded
//   lingo_resetCastXtra
//   lingo_getDebugContext
//   lingo_getDebugData
//   lingo_callMethod
//   lingo_getDebugState
//   lingo_callMethodEx


// ============================================================
// Function: Ordinal_133
// Address: 68090fa0
// Size: 134 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_133(int param_1)
{
  uint uVar1;
  undefined4 local_10;
  
                    /* 0x90fa0  133   */
  if (((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x20) + 4) != 0)) {
    Ordinal_2330();
    local_10 = DAT_68196374;
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_71
// Address: 68095c60
// Size: 145 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_71(int param_1,undefined4 param_2)
{
  int *piVar1;
  int *piVar2;
  int *local_14;
  int **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95c60  71   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  piVar1 = (int *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (piVar1 = (int *)**(int **)(param_1 + 0x20), piVar1 == (int *)0x0)))) {
      piVar1 = (int *)*piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = piVar1;
  }
  rendering_setChannelProperty(piVar1,piVar2[1] + 0x24,param_2);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_185
// Address: 68095d00
// Size: 166 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_185(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95d00  185   */
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
  if (param_2 == (int *)0x0) {
    playback_getLifecycleCount(iVar1);
  }
  else {
    bitmap_updateMovieStage(*(int *)(iVar1 + 0x24) + 0x90,param_2,0);
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_186
// Address: 68095db0
// Size: 27 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_186(void)

{
  undefined4 uVar1;
  undefined4 local_8;
  
                    /* 0x95db0  186   */
  uVar1 = strings_getDefaultCastType();
  local_8 = CONCAT22((short)uVar1,0xffff);
  return local_8;
}



// ============================================================
// Function: Ordinal_187
// Address: 68095dd0
// Size: 140 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_187(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95dd0  187   */
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
// Function: Ordinal_188
// Address: 68095e60
// Size: 157 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_188(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95e60  188   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
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
  Ordinal_1113((undefined4 *)(iVar2 + 0x128));
  uVar1 = Ordinal_1112(param_2);
  *(undefined4 *)(iVar2 + 0x128) = uVar1;
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_980
// Address: 68095f00
// Size: 159 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_980(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95f00  980   */
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
  *(int *)(iVar1 + 0xf4) = *(int *)(iVar1 + 0xf4) + param_2;
  *(int *)(iVar1 + 0x100) = *(int *)(iVar1 + 0x100) + param_2;
  *(int *)(iVar1 + 0x10c) = *(int *)(iVar1 + 0x10c) + param_2;
  *(int *)(iVar1 + 0x118) = *(int *)(iVar1 + 0x118) + param_2;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getMiscState (FUN_68095fa0)
// Address: 68095fa0
// Size: 175 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getMiscState(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x20), piVar1 != (int *)0x0)) {
    if (piVar1[1] != 0) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      piVar1 = (int *)piVar1[2];
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      local_14 = iVar2;
      if ((piVar1 != (int *)0x0) && (piVar1[0x7a] == 4)) {
        DAT_68196374 = &local_14;
        media_dispatchRender(param_1,(int *)piVar1[0x7b]);
        *(undefined4 *)(*piVar1 + 0x648) = 0;
      }
    }
    DAT_68196374 = (int *)local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_215
// Address: 68096050
// Size: 293 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_215(int param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int *piVar2;
  int local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x96050  215   */
  piVar2 = (int *)0x0;
  local_1c = 1;
  if (param_1 == 0) {
    local_18 = (int *)0x0;
  }
  else {
    local_18 = *(int **)(param_1 + 0x20);
  }
  if ((local_18 != (int *)0x0) && (local_18[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *local_18;
    }
    piVar2 = (int *)local_18[2];
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (param_4 == 1) {
    iVar1 = *(int *)(*piVar2 + 0x648);
    if ((iVar1 != param_1) && (iVar1 != 0)) {
      local_1c = lingo_getMiscState(iVar1);
    }
    if (((piVar2[0x7a] == 4) && (*(int *)(*piVar2 + 0x648) != param_1)) && (local_1c != 0)) {
      if ((param_1 == 0) || (*(int **)(param_1 + 0x20) == (int *)0x0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = **(int **)(param_1 + 0x20);
      }
      media_dispatchUpdate(iVar1,(int *)piVar2[0x7b]);
      *(int *)(*piVar2 + 0x648) = param_1;
    }
  }
  else if (param_4 == 0) {
    lingo_getMiscState(*(int *)(*piVar2 + 0x648));
  }
  Ordinal_1763(param_2,param_3);
  if (local_18 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_216
// Address: 68096180
// Size: 177 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_216(int param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x96180  216   */
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
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
  iVar3 = rendering_getChannelSprite(iVar3,param_2);
  if (iVar3 == 0) {
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x458) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 0x18) = 0;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_formatDebugMsg (lingo_formatDebugMsg)
// Address: 6809b380
// Size: 224 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl lingo_formatDebugMsg(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined1 local_414 [256];
  int local_314;
  undefined1 local_310 [256];
  int local_210 [66];
  undefined1 local_108 [256];
  uint local_8;
  
  memset(local_414,0,0x30c);
  if (param_2 != 0) {
    Ordinal_1517(DAT_681956e0,param_2,local_108,0x100);
    local_314 = param_2;
    Ordinal_1213(local_310,0xff,local_108,&stack0x0000000c);
    piVar2 = &local_314;
    piVar3 = local_210;
    for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar2 = &local_314;
    piVar3 = param_1 + 0x84;
    for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar2 = &local_314;
    piVar3 = param_1 + 0x43;
    for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    if (param_2 == -0x78) {
      *(undefined2 *)(*(int *)(*param_1 + 0x18) + 0x10) = 2;
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_formatDebugMsgEx (FUN_6809b460)
// Address: 6809b460
// Size: 157 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl lingo_formatDebugMsgEx(int param_1,int param_2)
{
  int param_4;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_418;
  undefined1 local_414 [780];
  undefined1 local_108 [256];
  uint local_8;
  
  local_418 = 0;
  memset(local_414,0,0x30c);
  if (param_2 != 0) {
    Ordinal_1517(DAT_681956e0,param_2,local_108,0x100);
    local_418 = param_2;
    Ordinal_1213(local_414,0xff,local_108,&stack0x0000000c);
    piVar2 = &local_418;
    piVar3 = (int *)(param_1 + 8);
    for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_showErrorDialog (FUN_6809b580)
// Address: 6809b580
// Size: 180 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_showErrorDialog(undefined4 param_1)
{
  undefined1 local_120 [12];
  undefined4 local_114;
  undefined4 local_110;
  undefined1 local_108 [256];
  uint local_8;
  
  local_108[0] = 0;
  Ordinal_1517(DAT_681956e0,0x57a,local_108,0x100);
  Ordinal_1130(&local_114,0xc);
  local_114 = 1;
  local_110 = 1;
  Ordinal_1763(&local_114,local_120);
  Ordinal_1764(1);
  Ordinal_1780(param_1,local_108,2,1,1,1,0);
  Ordinal_1764(0);
  Ordinal_1763(local_120,0);
  return 0;
}



// ============================================================
// Function: lingo_checkMovieState (FUN_6809b640)
// Address: 6809b640
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_checkMovieState(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_2;
  uVar2 = 0;
  if ((((iVar1 == 10) || (iVar1 == 2)) || (iVar1 == 3)) || (iVar1 == 4)) {
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: lingo_isMovieLoaded (FUN_6809b670)
// Address: 6809b670
// Size: 88 bytes
// Params: int * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool lingo_isMovieLoaded(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  iVar1 = Ordinal_1541();
  if (0x32 < (uint)(iVar1 - _DAT_68196378)) {
    _DAT_68196378 = iVar1;
    iVar1 = stage_forEachEvent(*(int *)(*param_1 + 0x14),-1,lingo_checkMovieState);
    bVar2 = iVar1 != 0;
    iVar1 = events_getEditRef(*(int *)(*param_1 + 0x14));
    if (iVar1 != 0) {
      return true;
    }
  }
  return bVar2;
}



// ============================================================
// Function: lingo_resetCastXtra (FUN_6809b6d0)
// Address: 6809b6d0
// Size: 83 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_resetCastXtra(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  uVar3 = 0;
  local_8 = 0;
  local_8 = scoreEngine_createLifecycleNode(param_1);
  if (local_8 != 0) {
    piVar1 = (int *)scoreEngine_getCastXtraState(local_8);
    while (piVar1 != (int *)0x0) {
      iVar2 = scoreEngine_resetThumbnails(piVar1,(void *)0x0);
      if (iVar2 == 0) goto LAB_6809b711;
      piVar1 = (int *)scoreEngine_getCastXtraState(local_8);
    }
    uVar3 = 1;
  }
LAB_6809b711:
  scoreEngine_initCastXtra(&local_8);
  return uVar3;
}



// ============================================================
// Function: lingo_getDebugContext (FUN_6809b730)
// Address: 6809b730
// Size: 78 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * lingo_getDebugContext(int param_1,undefined4 *param_2)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x28) != 0)) &&
     (*(int *)(*(int *)(param_1 + 8) + 0x388) != 0)) {
    Ordinal_1766(param_2);
    Ordinal_1837(*(undefined4 *)(param_1 + 0x28),param_2);
    return param_2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  return param_2;
}



// ============================================================
// Function: lingo_getDebugData (FUN_6809b780)
// Address: 6809b780
// Size: 95 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * lingo_getDebugData(int param_1,undefined4 *param_2)

{
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x28) != 0)) &&
      (*(int *)(*(int *)(param_1 + 8) + 0x388) != 0)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x754) != 0)) {
    Ordinal_1838(*(int *)(param_1 + 0x28),param_2);
    Ordinal_1768(*(undefined4 *)(param_1 + 0x28),param_2);
    return param_2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  return param_2;
}



// ============================================================
// Function: lingo_callMethod (FUN_6809b800)
// Address: 6809b800
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_callMethod(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                int param_6)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  int iVar2;
  
  uVar1 = lingo_resolveRef(param_1,param_6,param_2);
  if ((((CONCAT31(extraout_var,uVar1) != 0) && (param_5 != 0)) &&
      (iVar2 = media_getDataPtr(*(int **)(param_1 + 4)), iVar2 != 0)) &&
     (*(code **)(iVar2 + 0x154) != (code *)0x0)) {
    iVar2 = (**(code **)(iVar2 + 0x154))(param_3,param_4,param_2,param_5);
    return iVar2;
  }
  return CONCAT31(extraout_var,uVar1);
}



// ============================================================
// Function: lingo_getDebugState (FUN_6809b860)
// Address: 6809b860
// Size: 80 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getDebugState(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int local_8;
  
  uVar2 = 0;
  local_8 = 0;
  local_8 = scoreEngine_createLifecycleNode(param_1);
  if (local_8 != 0) {
    piVar1 = (int *)scoreEngine_getCastXtraState(local_8);
    while (piVar1 != (int *)0x0) {
      playback_querySpriteInkProperty(*piVar1);
      piVar1 = (int *)scoreEngine_getCastXtraState(local_8);
    }
    uVar2 = 1;
  }
  scoreEngine_initCastXtra(&local_8);
  return uVar2;
}



// ============================================================
// Function: lingo_callMethodEx (FUN_6809b8c0)
// Address: 6809b8c0
// Size: 112 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_callMethodEx(int *param_1,int param_2,undefined4 param_3)
{
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_408 = 0;
  memset(local_407,0,0x3fe);
  Ordinal_1310(param_3,&local_408,0x3ff);
  lingo_formatDebugMsg(param_1,param_2);
  return 0;
}


