// Module: lingo
// Topic: Cast member and marker operations
// Address range: 0x68095130 - 0x68097A10
// Functions (20):
//   Ordinal_366
//   Ordinal_72
//   Ordinal_57
//   Ordinal_165
//   Ordinal_166
//   Ordinal_345
//   Ordinal_346
//   lingo_getPlaybackContext
//   Ordinal_347
//   Ordinal_348
//   Ordinal_356
//   Ordinal_357
//   Ordinal_349
//   Ordinal_350
//   Ordinal_351
//   Ordinal_352
//   Ordinal_353
//   Ordinal_354
//   Ordinal_355
//   Ordinal_344


// ============================================================
// Function: Ordinal_366
// Address: 68095130
// Size: 168 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_366(int param_1,int param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95130  366   */
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
  iVar1 = rendering_dispatchChannelOp(iVar1,param_2,param_3);
  if (iVar1 != 0) {
    Ordinal_1731(iVar1);
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_72
// Address: 680951e0
// Size: 239 bytes
// Params: int param_1, undefined2 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_72(int param_1,undefined2 *param_2,uint param_3)
{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined2 local_18;
  undefined1 local_16;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x951e0  72   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
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
  if (*(byte *)((int)param_2 + 3) == param_3) {
    return 0;
  }
  iVar3 = *(int *)(*(int *)(iVar3 + 0x20) + 4);
  if (param_3 == 0) {
    uVar1 = lingo_writeValue(iVar3,(undefined1 *)param_2);
    *(undefined1 *)((int)param_2 + 3) = 0;
    *(undefined1 *)param_2 = uVar1;
  }
  else {
    lingo_checkColorSpace(iVar3,param_2,&local_18);
    *param_2 = local_18;
    *(undefined1 *)((int)param_2 + 3) = 1;
    *(undefined1 *)(param_2 + 1) = local_16;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_57
// Address: 680952d0
// Size: 248 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_57(int *param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x952d0  57   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  if (param_2 == 0) {
    local_1c = (int *)lingo_getGlobalState((int)param_1);
    *(undefined4 *)(*param_1 + 0x24) = param_3;
    if (local_1c != (int *)0x0) {
      local_18 = (int *)0x0;
      iVar1 = (**(code **)*local_1c)(local_1c,&DAT_681765a8,&local_18);
      if (iVar1 == 0) {
        local_24 = *(undefined4 *)(*(int *)param_1[1] + 0x38);
        local_20 = param_3;
        iVar1 = (**(code **)(*local_18 + 0xc))(local_18,&local_24);
        if (iVar1 == 0) {
          (**(code **)(*local_18 + 0x10))(local_18,&DAT_6819636c);
        }
        (**(code **)(*local_18 + 8))(local_18);
      }
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  else if (DAT_6819636c != (code *)0x0) {
    ((code *)(size_t)DAT_6819636c)(param_2,param_3);
  }
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_165
// Address: 680953d0
// Size: 149 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_165(int param_1,int param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x953d0  165   */
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
  if (param_3 != (undefined4 *)0x0) {
    if (*(int *)(iVar2 + 0x38) == 0) {
      *param_3 = 0xffffffff;
    }
    else {
      *param_3 = *(undefined4 *)(iVar2 + 0x2c);
    }
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_166
// Address: 68095470
// Size: 155 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_166(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95470  166   */
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
  *(undefined4 *)(param_2 * 0x34 + 0x10 + *(int *)(iVar1 + 0x38)) = param_3;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_345
// Address: 68096d50
// Size: 116 bytes
// Params: int * param_1, ushort * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_345(int *param_1,ushort *param_2)
{
  int iVar1;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x96d50  345   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar1 = rendering_setChannelProperty(param_1,(uint)*param_2,0);
  if (iVar1 != 0) {
    *param_2 = 0;
  }
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_346
// Address: 68096dd0
// Size: 211 bytes
// Params: int param_1, short param_2, undefined4 * param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_346(int param_1,short param_2,undefined4 *param_3,void *param_4)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x96dd0  346   */
  iVar3 = 0;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar4 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar4 = *(int *)(piVar2[1] + 8);
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
  piVar1 = (int *)rendering_getChannelSprite(iVar4,param_2);
  if (piVar1 != (int *)0x0) {
    rendering_readCastData(*(int *)(iVar3 + 0x20),piVar1,param_3,param_4);
    lingo_getMovieRef(iVar4);
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getPlaybackContext (FUN_68096eb0)
// Address: 68096eb0
// Size: 77 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getPlaybackContext(void)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
  *unaff_EDI = 0;
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    Ordinal_1310(*(int *)(unaff_ESI + 0x1c) + 0x28);
    uVar1 = Ordinal_1201();
    *unaff_EBX = uVar1;
    return 0;
  }
  iVar2 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x30));
  if (iVar2 != 0) {
    Ordinal_1310(iVar2);
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x30));
  }
  uVar1 = Ordinal_1201();
  *unaff_EBX = uVar1;
  return 0;
}



// ============================================================
// Function: Ordinal_347
// Address: 68096f00
// Size: 613 bytes
// Params: int param_1, short param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_347(int param_1,short param_2,undefined4 param_3,uint *param_4)
{
  int *piVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x96f00  347   */
  piVar1 = *(int **)(param_1 + 0x10);
  Ordinal_2330();
  local_14 = *piVar1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar4 = rendering_getChannelSprite((int)piVar1,param_2);
  if (iVar4 == 0) goto switchD_68096f68_default;
  switch(param_3) {
  case 1:
    uVar7 = rendering_updateChannelState(iVar4 + 0x68);
    *param_4 = uVar7;
    break;
  case 2:
    uVar3 = rendering_getChannelType(iVar4 + 0x68);
    *param_4 = (uint)uVar3;
    break;
  case 3:
    uVar2 = rendering_getChannelMode(iVar4);
    *(undefined2 *)param_4 = uVar2;
    break;
  case 4:
    if ((*(int *)(iVar4 + 0x48) == 0) && (*(int *)(iVar4 + 0xc) != 0)) {
      uVar5 = stage_getSpriteScriptCount(*(int *)(*piVar1 + 0x14));
      *(undefined4 *)(iVar4 + 0x48) = uVar5;
    }
    *param_4 = *(uint *)(iVar4 + 0x48);
    break;
  case 5:
    *param_4 = *(uint *)(iVar4 + 0xd4);
    break;
  case 6:
    if (*(int *)(iVar4 + 0xd0) != 0) {
      uVar7 = cast_lookupDataEntry(*(int *)(iVar4 + 0xd0),(uint)(ushort)param_4[1],0);
      *param_4 = uVar7;
      goto joined_r0x68097119;
    }
  default:
switchD_68096f68_default:
    Ordinal_1130(param_4,0x10);
    break;
  case 7:
    *param_4 = *(uint *)(iVar4 + 0xc);
    break;
  case 8:
    *param_4 = *(uint *)(iVar4 + 0x14);
    break;
  case 9:
    lingo_getPlaybackContext();
    break;
  case 10:
    *param_4 = *(uint *)(iVar4 + 0x18);
    break;
  case 0xb:
    *param_4 = 0;
    if (*(int *)(iVar4 + 0x14) == 0) {
      if (*(int *)(iVar4 + 0x24) == 0) {
        *param_4 = 1;
      }
      if (*(int *)(iVar4 + 0x28) == 1) {
        *param_4 = *param_4 | 4;
      }
      if (*(int *)(iVar4 + 0x38) != 0) {
        *param_4 = *param_4 | 2;
      }
      uVar3 = rendering_getChannelType(iVar4 + 0x68);
      if (uVar3 < 0x79f) {
        *param_4 = *param_4 | 0x10;
      }
    }
    else {
      *param_4 = 8;
    }
    break;
  case 0xc:
    iVar6 = rendering_getChannelDepth(iVar4);
    uVar7 = playback_loadScoreOrFontMap(piVar1,iVar6,*param_4,param_4[1] + *(int *)(iVar4 + 0x3c),
                         (int *)(param_4 + 3),(undefined4 *)param_4[2]);
joined_r0x68097119:
    if (uVar7 != 0) break;
    goto switchD_68096f68_default;
  case 0xd:
    if (*(int *)(iVar4 + 0x14) == 0) {
      *param_4 = *(uint *)(iVar4 + 0xcc);
    }
    else {
      *param_4 = *(uint *)(*(int *)(iVar4 + 0x1c) + 0x680);
    }
  }
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_348
// Address: 680971a0
// Size: 219 bytes
// Params: int param_1, short param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_348(int param_1,short param_2,int param_3,int *param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x971a0  348   */
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  Ordinal_2330();
  local_14 = *puVar1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar2 = rendering_getChannelSprite((int)puVar1,param_2);
  if (iVar2 != 0) {
    if (param_3 == 5) {
      *(int *)(iVar2 + 0xd4) = *param_4;
      goto LAB_6809724a;
    }
    if (param_3 == 6) {
      if (*(int *)(iVar2 + 0xd0) == 0) {
        iVar3 = Ordinal_35(4);
        *(int *)(iVar2 + 0xd0) = iVar3;
        if (iVar3 == 0) goto LAB_6809723f;
      }
      iVar2 = cast_formatNumber((int *)(iVar2 + 0xd0),(short)param_4[1],*param_4);
      if (iVar2 != 0) goto LAB_6809724a;
    }
    else if (param_3 == 10) {
      *(undefined4 *)(iVar2 + 0x18) = 1;
      goto LAB_6809724a;
    }
  }
LAB_6809723f:
  Ordinal_1130(param_4,8);
LAB_6809724a:
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_356
// Address: 68097280
// Size: 119 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_356(int param_1,short param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97280  356   */
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  Ordinal_2330();
  local_14 = *puVar1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  piVar2 = (int *)rendering_getChannelSprite((int)puVar1,param_2);
  if (piVar2 != (int *)0x0) {
    rendering_getChannelBlock(piVar2);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_357
// Address: 68097300
// Size: 167 bytes
// Params: int param_1, short param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_357(int param_1,short param_2,short param_3)
{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97300  357   */
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  Ordinal_2330();
  local_14 = *puVar1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar3 = rendering_getChannelSprite((int)puVar1,param_2);
  if (iVar3 != 0) {
    iVar4 = rendering_getChannelVisibility(*(int *)(iVar3 + 0x60));
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        sVar2 = rendering_getChannelFlags(*(int *)(iVar3 + 0x60),iVar5);
        if (sVar2 == param_3) break;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_349
// Address: 680973b0
// Size: 263 bytes
// Params: int param_1, undefined1 * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_349(int param_1,undefined1 *param_2,int param_3,undefined4 *param_4)
{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x973b0  349   */
  iVar4 = 0;
  pvVar5 = (void *)0x0;
  if (param_1 == 0) {
    local_18 = (int *)0x0;
  }
  else {
    local_18 = *(int **)(param_1 + 0x20);
  }
  if ((local_18 != (int *)0x0) && (local_18[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar4 = **(int **)(param_1 + 0x20), iVar4 == 0)
        ))) {
      iVar4 = *local_18;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar4;
  }
  piVar1 = *(int **)(iVar4 + 0x20);
  if ((*(byte *)(piVar1 + 8) & 0x10) != 0) {
    pvVar5 = (void *)0x10;
  }
  if (param_3 == 0) {
    sVar2 = scoreEngine_createThumbnail((int)piVar1,param_2);
  }
  else {
    sVar2 = scoreEngine_loadMemberData(piVar1,param_4,pvVar5);
  }
  if ((((sVar2 != 0) && (iVar3 = scoreEngine_getFrameData(*(int *)(iVar4 + 0x20),sVar2), iVar3 != 0)) &&
      (*(undefined4 *)(*(int *)(iVar4 + 0x20) + 0x458) = 1, param_3 != 0)) &&
     (param_2 != (undefined1 *)0x0)) {
    iVar4 = Ordinal_1201(param_2);
    scoreEngine_setFrameName(iVar3,(int)param_2,iVar4);
  }
  if (local_18 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_350
// Address: 680974c0
// Size: 163 bytes
// Params: int param_1, ushort * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_350(int param_1,ushort *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x974c0  350   */
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
  iVar1 = scoreEngine_deleteFrame(*(int **)(iVar1 + 0x20),(uint)*param_2);
  if (iVar1 != 0) {
    *param_2 = 0;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_351
// Address: 68097570
// Size: 313 bytes
// Params: int param_1, int param_2, short param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_351(int param_1,int param_2,short param_3,int param_4,undefined4 *param_5)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97570  351   */
  piVar1 = *(int **)(param_1 + 0x20);
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
  iVar2 = scoreEngine_getFrameData(*(int *)(iVar3 + 0x20),param_3);
  iVar3 = scoreEngine_getChannelField(*(int *)(iVar3 + 0x20),param_3);
  if ((iVar3 != 0) && (iVar2 != 0)) {
    if (param_4 == 1) {
      *(undefined1 *)*param_5 = 0;
      if ((*(int *)(iVar2 + 4) != 0) && (iVar3 = Ordinal_1114(*(int *)(iVar2 + 4)), iVar3 != 0)) {
        Ordinal_1203(*param_5,iVar3,param_5[1]);
        Ordinal_1115(*(undefined4 *)(iVar2 + 4));
      }
      uVar4 = Ordinal_1201(*param_5);
      param_5[1] = uVar4;
      goto LAB_68097680;
    }
    if (param_4 == 2) {
      lingo_getPlaybackContext();
      goto LAB_68097680;
    }
    if (param_4 == 3) {
      *param_5 = *(undefined4 *)(iVar2 + 8);
      goto LAB_68097680;
    }
  }
  if ((param_4 == 1) || (param_4 == 2)) {
    if ((undefined1 *)*param_5 != (undefined1 *)0x0) {
      *(undefined1 *)*param_5 = 0;
    }
    param_5[1] = 0;
  }
  else {
    Ordinal_1130(param_5,8);
  }
LAB_68097680:
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_352
// Address: 680976b0
// Size: 348 bytes
// Params: int param_1, int param_2, short param_3, undefined4 param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_352(int param_1,int param_2,short param_3,undefined4 param_4,int *param_5)
{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  ushort local_24 [2];
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x976b0  352   */
  local_1c = *(int **)(param_1 + 0x20);
  local_18 = param_5;
  local_20 = 0;
  iVar3 = 0;
  if ((local_1c != (int *)0x0) && (local_1c[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *local_1c;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar1 = scoreEngine_getChannelField(*(int *)(iVar3 + 0x20),param_3);
  puVar2 = (ushort *)scoreEngine_getFrameData(*(int *)(iVar3 + 0x20),param_3);
  if ((iVar1 == 0) || (puVar2 == (ushort *)0x0)) goto switchD_68097740_default;
  switch(param_4) {
  case 1:
    scoreEngine_setFrameName((int)puVar2,*local_18,local_18[1]);
    *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x458) = 1;
    break;
  case 2:
    if (*(int *)(iVar1 + 0x14) == 0) {
      playback_resolveExternalMedia(iVar3,puVar2,*local_18);
      *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x458) = 1;
      break;
    }
  default:
switchD_68097740_default:
    Ordinal_1130(local_18,8);
    break;
  case 3:
    local_24[0] = puVar2[6];
    *(int *)(puVar2 + 4) = *local_18;
    rendering_getChannelProperty(**(int **)(puVar2 + 0xe),0x1b,(undefined4 *)local_24);
    *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x458) = 1;
    break;
  case 4:
    rendering_validateChannelScript((int)local_1c,iVar1);
    *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x458) = 1;
  }
  if (local_1c != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_353
// Address: 68097820
// Size: 164 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined2 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_353(int param_1,int param_2,undefined4 param_3,undefined2 *param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97820  353   */
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
  iVar2 = scoreEngine_findFrameByName(*(int *)(iVar2 + 0x20),param_3);
  if ((iVar2 != 0) && (param_4 != (undefined2 *)0x0)) {
    *param_4 = *(undefined2 *)(iVar2 + 0xc);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_354
// Address: 680978d0
// Size: 140 bytes
// Params: int param_1, short * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_354(int param_1,short *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x978d0  354   */
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  Ordinal_2330();
  local_14 = *puVar1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar2 = rendering_getChannelSprite((int)puVar1,*param_2);
  iVar2 = rendering_findNextChannelSprite((int)puVar1,iVar2);
  if (iVar2 == 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = *(short *)(iVar2 + 4);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_355
// Address: 68097960
// Size: 166 bytes
// Params: int param_1, int param_2, short * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_355(int param_1,int param_2,short *param_3)
{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97960  355   */
  piVar1 = *(int **)(param_1 + 0x20);
  uVar4 = 0;
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
  if (((param_3 != (short *)0x0) && (-1 < *param_3)) &&
     (sVar2 = *param_3 + 1, sVar2 <= *(short *)(*(int *)(iVar3 + 0x20) + 0x478))) {
    uVar4 = 1;
    *param_3 = sVar2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(uVar4);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_344
// Address: 68097a10
// Size: 235 bytes
// Params: int * param_1, undefined4 param_2, undefined4 * param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_344(int *param_1,undefined4 param_2,undefined4 *param_3,void *param_4)
{
  int *piVar1;
  int iVar2;
  int *local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x97a10  344   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  local_18 = *(int **)(*(int *)(*(int *)(*param_1 + 0x18) + 0xc) + 0x20);
  DAT_68196374 = &local_14;
  if (param_3 != (undefined4 *)0x0) {
    piVar1 = (int *)rendering_getChannelRect((int)param_1,param_3);
    if (piVar1 != (int *)0x0) goto LAB_68097abd;
  }
  piVar1 = (int *)rendering_getChannelDataEx((int)param_1,1,param_3,0);
  if (piVar1 != (int *)0x0) {
    if (param_3 == (undefined4 *)0x0) {
      iVar2 = rendering_getChannelFormat((int)piVar1);
      if (iVar2 == 0) goto LAB_68097abd;
    }
    else {
      iVar2 = playback_loadMediaData(local_18,piVar1,param_4);
      if (iVar2 != 1) {
        local_18 = (int *)(uint)*(ushort *)(piVar1 + 1);
        Ordinal_345(param_1,(ushort *)&local_18);
        piVar1 = (int *)0x0;
        goto LAB_68097abd;
      }
    }
    rendering_writeChannelBlock(piVar1,local_18,param_4);
  }
LAB_68097abd:
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  if (piVar1 != (int *)0x0) {
    return 0;
  }
  return 0;
}


