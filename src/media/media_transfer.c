// Module: media
// Topic: Data transfer, import/export, clipboard, ink effects, and sound channel management
// Address range: 0x680aab80 - 0x680ac520
// Functions (30):
//   media_getFontMapData
//   media_lookupFontRef
//   media_lookupFontName
//   media_readScoreSlot
//   media_getScoreSlotRef
//   media_getSymbolName
//   media_registerScriptThread
//   media_loadScriptData
//   media_getClipboardFormatId
//   media_createPalette
//   media_getChannelCount
//   media_removeChannel
//   media_findAvailableChannel
//   media_getScorePropertyRef
//   media_getScorePropertyData
//   media_resetChannel
//   media_getChannelInfo
//   media_commitChannel
//   media_setChannelVolume
//   media_setPlaybackMode
//   media_setPlaybackTempo
//   media_getScoreProperty
//   media_getInkEffect
//   media_getTransformMatrix
//   media_getTransitionData
//   media_renderTransfer
//   media_processScoreCallback
//   media_resolveScoreRef
//   media_resolveScoreSlot
//   media_getMovieProperty

// ============================================================
// Function: media_getFontMapData (FUN_680aab80)
// Address: 680aab80
// Size: 176 bytes
// Params: int * param_1, undefined2 param_2, undefined4 param_3, undefined4 param_4, short param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getFontMapData(int *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 short param_5)
{
  int iVar1;
  undefined1 local_c0 [164];
  undefined1 local_1c [8];
  undefined2 local_14;
  uint local_8;
  
  Ordinal_1130(local_c0,0xa4);
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x20);
  }
  iVar1 = scoreEngine_getFrameData(iVar1,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  Ordinal_1130(local_1c,0x14);
  local_14 = param_2;
  playback_getFontMapData(iVar1 + 0x14,(int)local_1c,(int)local_c0,0,0);
  Ordinal_1203(param_3,local_c0,param_4);
  return 0;
}



// ============================================================
// Function: media_lookupFontRef (FUN_680aac30)
// Address: 680aac30
// Size: 119 bytes
// Params: int * param_1, short param_2, undefined1 * param_3, undefined4 param_4, int * param_5, int param_6, int param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_lookupFontRef(int *param_1,short param_2,undefined1 *param_3,undefined4 param_4,int *param_5,
            int param_6,int param_7)

{
  int iVar1;
  int extraout_EAX;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x20);
  }
  iVar1 = scoreEngine_getFrameData(iVar1,param_2);
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*param_1 + 0x20);
    }
    iVar1 = scoreEngine_getFrameData(iVar1,1);
    if (iVar1 == 0) {
      return 0x80040002;
    }
  }
  playback_lookupFontRefByName(iVar1 + 0x14,param_3,param_4,param_5,param_6,param_7);
  uVar2 = 0x80040002;
  if (extraout_EAX != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: media_lookupFontName (FUN_680aacb0)
// Address: 680aacb0
// Size: 154 bytes
// Params: int * param_1, short param_2, uint param_3, int * param_4, int param_5, undefined4 param_6, int param_7, void * param_8
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_lookupFontName(int *param_1,short param_2,uint param_3,int *param_4,int param_5,undefined4 param_6,
            int param_7,void *param_8)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x20);
  }
  iVar1 = scoreEngine_getFrameData(iVar1,param_2);
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*param_1 + 0x20);
    }
    iVar1 = scoreEngine_getFrameData(iVar1,1);
    if (iVar1 == 0) {
      return 0x80040002;
    }
  }
  iVar1 = playback_lookupFontNameById(iVar1 + 0x14,param_3,param_4,param_5,param_6,param_7,param_8);
  if (iVar1 == 0) {
    return 0x80040002;
  }
  iVar1 = Ordinal_1255(param_5,"_DEFAULT_");
  if (iVar1 == 0) {
    Ordinal_1701(param_5,param_6);
  }
  return 0;
}



// ============================================================
// Function: media_readScoreSlot (FUN_680aad50)
// Address: 680aad50
// Size: 107 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_readScoreSlot(int param_1)

{
  HGLOBAL pvVar1;
  
  pvVar1 = *(HGLOBAL *)(param_1 + 8);
  if (pvVar1 != (HGLOBAL)0x0) {
    switch(*(undefined4 *)(param_1 + 4)) {
    case 0x293:
    case 0x294:
    case 0x295:
    case 0x2ed:
      cast_freeHandle(pvVar1);
      *(undefined4 *)(param_1 + 8) = 0;
      break;
    default:
      return 0x80040bbc;
    case 0x29b:
    case 0x29c:
    case 0x29d:
      crt_freeGlobalHandle(pvVar1);
      *(undefined4 *)(param_1 + 8) = 0;
      return 0;
    case 0x29e:
      crt_deleteGdiObject(pvVar1);
      *(undefined4 *)(param_1 + 8) = 0;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: media_getScoreSlotRef (FUN_680aae30)
// Address: 680aae30
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreSlotRef(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = Ordinal_1201(param_2);
  iVar1 = cast_lookupSymbolValue(param_1,param_2,iVar1);
  if (iVar1 < 0) {
    return 0x80040001;
  }
  *param_3 = iVar1;
  return 0;
}



// ============================================================
// Function: media_getSymbolName (FUN_680aae70)
// Address: 680aae70
// Size: 9 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getSymbolName(int param_1,int param_2,int param_3)
{
  cast_getSymbolName(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: media_registerScriptThread (FUN_680aae80)
// Address: 680aae80
// Size: 9 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_registerScriptThread(undefined4 param_1)
{
  stage_registerScriptThread(param_1);
  return 0;
}



// ============================================================
// Function: media_loadScriptData (FUN_680aae90)
// Address: 680aae90
// Size: 9 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_loadScriptData(undefined4 param_1,undefined4 param_2,undefined4 param_3,void *param_4)
{
  stage_loadScriptFromDataWrapper(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: media_getClipboardFormatId (FUN_680aaea0)
// Address: 680aaea0
// Size: 301 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getClipboardFormatId(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = cast_getFormatId(0xff9a);
    *param_2 = uVar1;
    return 0;
  case 1:
    uVar1 = cast_getFormatId(0xff9b);
    *param_2 = uVar1;
    return 0;
  case 2:
    uVar1 = cast_getFormatId(0xffff);
    *param_2 = uVar1;
    return 0;
  case 3:
    uVar1 = cast_getFormatId(0xfffe);
    *param_2 = uVar1;
    return 0;
  case 4:
    uVar1 = cast_getFormatId(0xfffd);
    *param_2 = uVar1;
    return 0;
  case 5:
    uVar1 = cast_getFormatId(0xfffc);
    *param_2 = uVar1;
    return 0;
  case 6:
    uVar1 = cast_getFormatId(0xfffb);
    *param_2 = uVar1;
    return 0;
  case 7:
    uVar1 = cast_getFormatId(0xfffa);
    *param_2 = uVar1;
    return 0;
  case 8:
    uVar1 = cast_getFormatId(0xfff9);
    *param_2 = uVar1;
    return 0;
  case 9:
    uVar1 = cast_getFormatId(0xfff8);
    *param_2 = uVar1;
    return 0;
  case 10:
    uVar1 = cast_getFormatId(0xfff7);
    *param_2 = uVar1;
    return 0;
  default:
    uVar1 = cast_getFormatId(0);
    *param_2 = uVar1;
    return 0x80040001;
  }
}



// ============================================================
// Function: media_createPalette (FUN_680ab000)
// Address: 680ab000
// Size: 371 bytes
// Params: int * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createPalette(int *param_1,undefined4 param_2,int *param_3)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_82c;
  int local_828;
  int local_824;
  int local_820;
  int *local_81c;
  undefined4 local_818;
  int local_814 [3];
  undefined1 local_808 [2048];
  uint local_8;
  
  iVar2 = *param_1;
  local_824 = -0x7ffbffec;
  local_828 = 0;
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(iVar2 + 0x20);
    if ((puVar3 != (undefined4 *)0x0) && (puVar3[1] != 0)) {
      Ordinal_2330();
      local_818 = 0;
      local_81c = DAT_68196374;
      DAT_68196374 = &local_820;
      local_820 = iVar2;
    }
  }
  *param_3 = 0;
  uVar1 = cast_convertFormatCode(param_2);
  local_82c = CONCAT22((short)uVar1,0xffff);
  if ((short)uVar1 == -200) {
    local_824 = -0x7ffbffff;
  }
  else {
    local_828 = Ordinal_1730(0x100);
    if (local_828 != 0) {
      iVar2 = rendering_transformPaletteData((int *)*puVar3,local_82c,local_814);
      if (iVar2 == 0) {
        local_824 = -0x7ffbffff;
      }
      else {
        iVar2 = Ordinal_1737(local_828,0,local_808,0x100);
        if (iVar2 != 0) {
          Ordinal_1735(local_828,local_814[0]);
          iVar2 = Ordinal_1744(local_828);
          *param_3 = iVar2;
          local_824 = (-(uint)(iVar2 != 0) & 0x7ffbffff) + 0x80040001;
        }
      }
    }
  }
  Ordinal_1733(&local_828);
  if (puVar3 != (undefined4 *)0x0) {
    DAT_68196374 = local_81c;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelCount (FUN_680ab180)
// Address: 680ab180
// Size: 29 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getChannelCount(undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_8;
  
  Ordinal_1900(&local_8);
  *param_2 = local_8;
  return 0;
}



// ============================================================
// Function: media_removeChannel (FUN_680ab1a0)
// Address: 680ab1a0
// Size: 120 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_removeChannel(int *param_1,int param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    if (*(int *)(*(int *)(iVar1 + 0x20) + 4) != 0) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
    Ordinal_1913(param_2 + -1);
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_findAvailableChannel (FUN_680ab220)
// Address: 680ab220
// Size: 235 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findAvailableChannel(int *param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = *param_1;
  local_1c = param_2;
  if (iVar3 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar3 + 0x20);
  }
  local_18 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    local_18 = *(int *)(piVar2[1] + 8);
    if (iVar3 == 0) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  *local_1c = 0;
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  Ordinal_1900(&local_20);
  do {
    iVar3 = local_20;
    if (iVar3 == 0) goto LAB_680ab2b8;
    iVar1 = Ordinal_1913(iVar3 + -1);
    local_20 = iVar3 + -1;
  } while (iVar1 != 0);
  *local_1c = iVar3;
  *(undefined4 *)(*(int *)(local_18 + 4) + 0x1c + iVar3 * 4) = *(undefined4 *)(piVar2[1] + 4);
LAB_680ab2b8:
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_getScorePropertyRef (FUN_680ab310)
// Address: 680ab310
// Size: 646 bytes
// Params: int * param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScorePropertyRef(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_198;
  uint local_194;
  undefined1 local_190 [4];
  int *local_18c;
  ushort local_188 [2];
  int *local_184;
  int local_180;
  uint local_17c;
  int local_178;
  int *local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined1 local_168 [352];
  uint local_8;
  
  iVar4 = -0x7ffbffec;
  local_17c = 0;
  local_16c = 0;
  memset(local_168,0,0x160);
  iVar1 = *param_1;
  local_184 = (int *)0x0;
  if (iVar1 == 0) {
    local_18c = (int *)0x0;
  }
  else {
    local_18c = *(int **)(iVar1 + 0x20);
  }
  iVar3 = 0;
  local_180 = 0;
  if ((local_18c != (int *)0x0) && (local_18c[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *local_18c;
    }
    if (local_18c[2] == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(local_18c[2] + 0xc);
    }
    local_180 = iVar1;
    Ordinal_2330();
    local_178 = local_180;
    local_170 = 0;
    local_174 = DAT_68196374;
    DAT_68196374 = &local_178;
  }
  Ordinal_1900(&local_194);
  if ((param_2 == 0) || (local_194 < param_2)) {
    iVar4 = -0x7ffbf432;
    goto LAB_680ab540;
  }
  if (param_5 != (uint *)0x0) {
    iVar1 = cast_setXtraPropertyEx(iVar3,param_5,(undefined2 *)&local_17c);
    if (iVar1 != 0) {
      iVar4 = cast_getFormatProperty(iVar3,param_5,(undefined2 *)&local_17c);
      if (iVar4 != 0) goto LAB_680ab540;
      local_17c = -local_17c & 0xffff;
    }
  }
  iVar3 = param_2 - 1;
  iVar1 = Ordinal_1913(iVar3);
  if (iVar1 != 0) {
    Ordinal_1915(iVar3);
  }
  iVar1 = Ordinal_1405(local_190,param_3,1,1);
  if (iVar1 == 0) goto LAB_680ab540;
  uVar2 = Ordinal_1038(&DAT_68176518,&DAT_68176528,&local_184);
  iVar4 = Ordinal_2063(uVar2);
  if (iVar4 == 0) {
    iVar4 = (**(code **)(*local_184 + 0xc))(local_184,param_4,local_188);
    if (iVar4 != 0) goto LAB_680ab4ca;
  }
  else {
LAB_680ab4ca:
    local_188[0] = 0;
  }
  iVar1 = Ordinal_1923(&local_16c,local_190,local_188[0],&local_198);
  if (iVar1 == 0) {
    Ordinal_1042();
  }
  else {
    iVar1 = Ordinal_1910(iVar3,&local_16c,local_190,local_188[0],3);
    if (iVar1 != 0) {
      iVar1 = Ordinal_1908(iVar3,local_198,(int)(short)local_17c,local_180);
      if (iVar1 != 0) {
        Ordinal_1912(iVar3);
        iVar4 = 0;
      }
    }
  }
LAB_680ab540:
  if (local_184 != (int *)0x0) {
    (**(code **)(*local_184 + 8))(local_184);
  }
  if (iVar4 != 0) {
    Ordinal_1407(local_190);
  }
  Ordinal_1042();
  if (local_18c != (int *)0x0) {
    DAT_68196374 = local_174;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getScorePropertyData (FUN_680ab5a0)
// Address: 680ab5a0
// Size: 829 bytes
// Params: int * param_1, uint param_2, undefined4 param_3, int * param_4, undefined4 * param_5, int param_6, uint * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int media_getScorePropertyData(int *param_1,uint param_2,undefined4 param_3,int *param_4,undefined4 *param_5,
                 int param_6,uint *param_7)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_198 [4];
  uint local_194;
  uint *local_190;
  int *local_18c;
  undefined4 local_188;
  int local_184;
  uint local_180;
  int local_17c;
  int local_178;
  int *local_174;
  undefined4 local_170;
  int local_16c [4];
  int local_15c;
  int local_154;
  int local_14c;
  int local_144;
  int local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  uint local_8;
  
  local_190 = param_7;
  local_17c = -0x7ffbffec;
  local_180 = 0;
  local_188 = 0;
  local_16c[0] = 0;
  memset(local_16c + 1,0,0x160);
  iVar1 = *param_1;
  if (iVar1 == 0) {
    local_18c = (int *)0x0;
  }
  else {
    local_18c = *(int **)(iVar1 + 0x20);
  }
  iVar3 = 0;
  local_184 = 0;
  if ((local_18c != (int *)0x0) && (local_18c[1] != 0)) {
    local_184 = iVar1;
    if (iVar1 == 0) {
      local_184 = *local_18c;
    }
    if (local_18c[2] == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(local_18c[2] + 0xc);
    }
    Ordinal_2330();
    local_178 = local_184;
    local_170 = 0;
    local_174 = DAT_68196374;
    DAT_68196374 = &local_178;
  }
  Ordinal_1900(&local_194);
  if ((param_2 == 0) || (local_194 < param_2)) {
    local_17c = -0x7ffbf432;
  }
  else {
    if ((local_190 != (uint *)0x0) &&
       (iVar1 = cast_setXtraPropertyEx(iVar3,local_190,(undefined2 *)&local_180), iVar1 != 0)) {
      local_17c = cast_getFormatProperty(iVar3,local_190,(undefined2 *)&local_180);
      if (local_17c != 0) goto LAB_680ab8a7;
      local_180 = -local_180 & 0xffff;
    }
    if (param_6 != 0) {
      uVar2 = Ordinal_1111(param_6 * 0x28 + 0x24,1);
      local_188 = uVar2;
      iVar1 = Ordinal_1114(uVar2);
      if (iVar1 == 0) goto LAB_680ab8a7;
      *(int *)(iVar1 + 0x1c) = param_6;
      for (; param_6 != 0; param_6 = param_6 + -1) {
        *(undefined4 *)(iVar1 + 0x24) = *param_5;
        Ordinal_1233(iVar1 + 0x28,param_5 + 1);
        param_5 = param_5 + 9;
        uVar2 = local_188;
        iVar1 = iVar1 + 0x28;
      }
      Ordinal_1115(uVar2);
    }
    iVar3 = param_2 - 1;
    iVar1 = Ordinal_1913(iVar3);
    if (iVar1 != 0) {
      Ordinal_1915(iVar3);
    }
    iVar1 = Ordinal_1405(local_198,param_3,1,0);
    if (iVar1 != 0) {
      piVar4 = local_16c;
      for (iVar1 = 0x59; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *param_4;
        param_4 = param_4 + 1;
        piVar4 = piVar4 + 1;
      }
      local_118 = 0x8f584c70;
      local_10c = 0xf59f8bc9;
      local_11c = local_11c * local_144;
      local_114 = 0x11d1a892;
      local_110 = 0xa000c0a6;
      if (local_11c - local_16c[1] != 0 && local_16c[1] <= local_11c) {
        local_16c[1] = local_11c;
      }
      if (local_11c - local_14c != 0 && local_14c <= local_11c) {
        local_14c = local_11c;
      }
      if (local_15c < 0) {
        local_15c = 0;
      }
      else if (local_14c < local_15c) {
        local_15c = local_14c;
      }
      if (local_154 < 0) {
        local_154 = 0;
      }
      else if (local_14c < local_154) {
        local_154 = local_14c;
      }
      iVar1 = Ordinal_1910(iVar3,local_16c,local_198,FOURCC_raw,3);
      if (iVar1 != 0) {
        iVar1 = Ordinal_1908(iVar3,local_188,(int)(short)local_180,local_184);
        if (iVar1 != 0) {
          Ordinal_1912(iVar3);
          local_17c = 0;
          goto LAB_680ab8a7;
        }
      }
      local_17c = -0x7ffbffec;
    }
  }
LAB_680ab8a7:
  Ordinal_1042();
  if (local_18c != (int *)0x0) {
    DAT_68196374 = local_174;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_resetChannel (FUN_680ab8e0)
// Address: 680ab8e0
// Size: 146 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resetChannel(int *param_1,uint param_2)
{
  int iVar1;
  uint local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    if (*(int *)(*(int *)(iVar1 + 0x20) + 4) != 0) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
    Ordinal_1900(&local_18);
    if ((param_2 != 0) && (param_2 <= local_18)) {
      Ordinal_1915(param_2 - 1);
    }
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelInfo (FUN_680ab980)
// Address: 680ab980
// Size: 159 bytes
// Params: int * param_1, uint param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelInfo(int *param_1,uint param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    if (*(int *)(*(int *)(iVar1 + 0x20) + 4) != 0) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
    Ordinal_1900(&local_18);
    if (((param_2 != 0) && (param_2 <= local_18)) && (param_3 != (undefined4 *)0x0)) {
      uVar2 = Ordinal_1933(param_2 - 1,0);
      *param_3 = uVar2;
    }
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_commitChannel (FUN_680aba20)
// Address: 680aba20
// Size: 161 bytes
// Params: int * param_1, uint param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_commitChannel(int *param_1,uint param_2,int param_3)
{
  int iVar1;
  uint local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    if (*(int *)(*(int *)(iVar1 + 0x20) + 4) != 0) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
    Ordinal_1900(&local_18);
    if ((param_2 != 0) && (param_2 <= local_18)) {
      if (param_3 == 0) {
        Ordinal_1912(param_2 - 1);
      }
      else {
        Ordinal_1916();
      }
    }
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_setChannelVolume (FUN_680abad0)
// Address: 680abad0
// Size: 182 bytes
// Params: int * param_1, uint param_2, ushort param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setChannelVolume(int *param_1,uint param_2,ushort param_3)
{
  int param_4;
  int iVar1;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    if (*(int *)(*(int *)(iVar1 + 0x20) + 4) != 0) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
    Ordinal_1900(&local_18);
    if ((param_2 != 0) && (param_2 <= local_18)) {
      local_20 = (int)((uint)param_3 * 0xffff) / 0xff;
      local_1c = local_20;
      Ordinal_1918(param_2 - 1,&local_20);
    }
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_setPlaybackMode (FUN_680abb90)
// Address: 680abb90
// Size: 125 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setPlaybackMode(int *param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  Ordinal_2334(param_2);
  if (iVar2 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_setPlaybackTempo (FUN_680abc10)
// Address: 680abc10
// Size: 125 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setPlaybackTempo(int *param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  Ordinal_2335(param_2);
  if (iVar2 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getScoreProperty (FUN_680abc90)
// Address: 680abc90
// Size: 38 bytes
// Params: undefined1 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_getScoreProperty(undefined1 *param_1)
{
  undefined1 *in_EAX;
  
  if (param_1[3] == '\0') {
    in_EAX[3] = 0;
    *in_EAX = *param_1;
    return 0;
  }
  in_EAX[3] = 1;
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  return 0;
}



// ============================================================
// Function: media_getInkEffect (FUN_680abcc0)
// Address: 680abcc0
// Size: 249 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_getInkEffect(int *param_1,int param_2)
{
  int iVar1;
  undefined4 in_EAX;
  
  switch(in_EAX) {
  default:
    *param_1 = 0;
    break;
  case 1:
    *param_1 = 4;
    break;
  case 2:
    *param_1 = 6;
    break;
  case 3:
    *param_1 = 8;
    break;
  case 4:
    *param_1 = 1;
    break;
  case 5:
    *param_1 = 5;
    break;
  case 6:
    *param_1 = 7;
    break;
  case 7:
    *param_1 = 9;
    break;
  case 0x20:
    *param_1 = 10;
    break;
  case 0x21:
    *param_1 = 0x12;
    break;
  case 0x22:
    *param_1 = 0xe;
    break;
  case 0x23:
    *param_1 = 0x14;
    break;
  case 0x24:
    *param_1 = 2;
    break;
  case 0x25:
    *param_1 = 0x18;
    break;
  case 0x26:
    *param_1 = 0x10;
    break;
  case 0x27:
    *param_1 = 0x16;
    break;
  case 0x28:
    *param_1 = 0x1a;
    break;
  case 0x29:
    *param_1 = 0x1c;
  }
  if (*(char *)(param_2 + 0xc) == '\0') {
    param_1[1] = 0x100;
  }
  else {
    iVar1 = ((0xff - *(int *)(param_2 + 8)) * 0x100) / 0xff;
    param_1[1] = iVar1;
    if (iVar1 != 0x100) {
      if (*param_1 == 2) {
        *param_1 = 0xc;
        return 0;
      }
      if (*param_1 == 0) {
        *param_1 = 10;
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: media_getTransformMatrix (FUN_680abe40)
// Address: 680abe40
// Size: 74 bytes
// Params: double * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_getTransformMatrix(double *param_1)

{
  int in_EAX;
  
  if ((in_EAX != 0) && ((*(byte *)(in_EAX + 0x2a) & 1) != 0)) {
    *param_1 = (double)*(float *)(in_EAX + 10);
    param_1[1] = (double)*(float *)(in_EAX + 0xe);
    param_1[2] = (double)*(float *)(in_EAX + 0x12);
    param_1[3] = (double)*(float *)(in_EAX + 0x16);
    param_1[4] = (double)*(float *)(in_EAX + 0x1a);
    param_1[5] = (double)*(float *)(in_EAX + 0x1e);
    param_1[6] = (double)*(float *)(in_EAX + 0x22);
    param_1[7] = (double)*(float *)(in_EAX + 0x26);
    return 1;
  }
  Ordinal_1130(param_1,0x40);
  return 0;
}



// ============================================================
// Function: media_getTransitionData (FUN_680abe90)
// Address: 680abe90
// Size: 198 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_getTransitionData(undefined4 *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (in_EAX != (undefined4 *)0x0)) {
    Ordinal_1130();
    if ((*(byte *)(param_1 + 5) & 4) == 0) {
      switch(*param_1) {
      case 1:
        *in_EAX = 1;
        in_EAX[4] = param_1[1];
        in_EAX[3] = param_1[2];
        return 1;
      case 2:
        *in_EAX = 2;
        in_EAX[4] = param_1[1];
        in_EAX[7] = param_1[2];
        in_EAX[6] = param_1[3];
        if ((param_1[4] | 1) != 0) {
          in_EAX[1] = 1;
        }
        in_EAX[1] = in_EAX[1] | param_1[4] & 2;
        return 1;
      case 3:
        *in_EAX = 3;
        in_EAX[4] = param_1[1];
        in_EAX[5] = param_1[2];
        return 1;
      case 7:
        *in_EAX = 4;
        in_EAX[2] = param_1[1];
      }
      return 1;
    }
    puVar2 = (undefined4 *)param_1[6];
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *in_EAX = *puVar2;
      puVar2 = puVar2 + 1;
      in_EAX = in_EAX + 1;
    }
  }
  return 0;
}



// ============================================================
// Function: media_renderTransfer (FUN_680abf80)
// Address: 680abf80
// Size: 723 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 param_5, undefined4 * param_6, undefined4 param_7, int * param_8, undefined4 param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_renderTransfer(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 param_7,int *param_8,
                 undefined4 param_9)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_110 [32];
  undefined1 local_f0 [32];
  undefined1 local_d0 [8];
  undefined4 local_c8;
  undefined4 local_b0;
  int *local_ac;
  int local_a8;
  int *local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  double local_8c [8];
  int local_4c [5];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_b0 = param_7;
  local_a4 = param_8;
  local_9c = param_9;
  local_ac = param_1;
  local_98 = 0;
  local_a8 = 0;
  if ((((param_2 == (undefined4 *)0x0) || (param_1 == (int *)0x0)) || (param_3 == (undefined4 *)0x0)
      ) || (param_4 == (undefined4 *)0x0)) {
    return 0;
  }
  if (param_6 == (undefined4 *)0x0) {
    local_18 = 0x1000000;
    local_14 = 0x1ffffff;
    local_10 = 0;
    local_c = 0;
    param_6 = &local_18;
  }
  local_38 = param_3[1];
  local_34 = *param_3;
  local_30 = param_3[3];
  local_2c = param_3[2];
  local_28 = param_4[1];
  local_24 = *param_4;
  local_20 = param_4[3];
  local_1c = param_4[2];
  media_getInkEffect(local_4c,(int)param_6);
  media_getScoreProperty((undefined1 *)(param_6 + 1));
  if ((local_4c[0] == 0x1a) || (local_4c[0] == 0x1c)) {
    media_getScoreProperty((undefined1 *)param_6);
    media_getScoreProperty((undefined1 *)(param_6 + 1));
    local_94 = 0x1000000;
    local_90 = 0x1ffffff;
  }
  else {
    media_getScoreProperty((undefined1 *)param_6);
    media_getScoreProperty((undefined1 *)(param_6 + 1));
  }
  media_getTransitionData(param_1);
  media_getTransitionData(param_2);
  iVar2 = media_getTransitionData(local_a4);
  iVar3 = media_getTransformMatrix(local_8c);
  if ((*(byte *)(param_2 + 5) & 4) != 0) {
    local_a8 = Ordinal_1602(local_c8);
    Ordinal_1608(local_c8,&local_28);
    piVar1 = local_ac;
    if (*local_ac == 7) {
      uVar4 = 0;
      if ((local_a4 == (int *)0x0) || (*local_a4 == 7)) {
        local_a0 = 0;
        local_9c = 0;
        if (local_a4 != (int *)0x0) {
          uVar4 = Ordinal_1605(local_a4[1]);
        }
        if (iVar3 == 0) {
          Ordinal_1616(local_c8,&local_28,piVar1[1],&local_38,uVar4,&local_a0,local_4c,&local_94);
        }
        else {
          Ordinal_1634(local_c8,local_8c,piVar1[1],&local_38,uVar4,&local_a0,local_4c,&local_94,0,0)
          ;
        }
        goto LAB_680ac210;
      }
    }
  }
  iVar2 = Ordinal_2044(local_f0,local_d0,-(uint)(iVar2 != 0) & (uint)local_110,&local_38,&local_28,
                       -(uint)(iVar3 != 0) & (uint)local_8c,local_4c,&local_94,local_9c,0);
  if (iVar2 == 0) {
    local_98 = 0x80040014;
  }
LAB_680ac210:
  if (local_a8 != 0) {
    Ordinal_1603(local_c8);
  }
  return 0;
}



// ============================================================
// Function: media_processScoreCallback (FUN_680ac260)
// Address: 680ac260
// Size: 494 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_processScoreCallback(int param_1,int param_2,int param_3,int *param_4)
{
  uint uVar1;
  float10 fVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint local_824;
  undefined1 local_820 [1048];
  char local_408 [1024];
  uint local_8;
  
  if (param_3 < 0x2d3) {
    if (param_3 == 0x2d2) {
      if (param_2 != 0) goto LAB_680ac439;
      puVar3 = local_820;
      uVar4 = DAT_681956e0;
      Ordinal_1320();
      Ordinal_1316(local_820,puVar3,uVar4);
      Ordinal_1310(local_820,local_408,0x3ff);
    }
    else {
      if (param_3 != 0x103) {
        if (param_3 == 0x1b2) {
          if (param_2 == 0) {
            puVar3 = local_820;
            uVar4 = DAT_681956e0;
            Ordinal_1320();
            Ordinal_1310(local_820,local_408,0x3ff,puVar3,uVar4);
            props_loadStringValue(param_1,local_408,param_4);
          }
          goto LAB_680ac439;
        }
        if ((param_3 != 0x2c6) || (param_2 != 0)) goto LAB_680ac439;
        uVar1 = media_applyPixelFilter(param_1);
        goto LAB_680ac431;
      }
      if (param_2 != 0) goto LAB_680ac439;
      puVar3 = local_820;
      uVar4 = DAT_681956e0;
      Ordinal_1320();
      Ordinal_1314(local_820,local_408,0x3ff,puVar3,uVar4);
    }
    props_loadStringValue(param_1,local_408,param_4);
  }
  else {
    if (param_3 == 0x361) {
      if (param_2 != 0) goto LAB_680ac439;
      local_824 = 0;
      Ordinal_2202(&local_824);
      uVar1 = local_824;
    }
    else {
      if (param_3 != 0x65e) {
        if ((param_3 == 0x679) && (param_2 == 0)) {
          fVar2 = (float10)Ordinal_2038();
          props_storeFloatDirect(param_1,(double)fVar2,param_4);
        }
        goto LAB_680ac439;
      }
      if (param_2 != 0) goto LAB_680ac439;
      uVar1 = media_hasCastScript(param_1);
      uVar1 = uVar1 & 0xff;
    }
LAB_680ac431:
    props_storeIntValue(param_1,uVar1,param_4);
  }
LAB_680ac439:
  return 0;
}



// ============================================================
// Function: media_resolveScoreRef (FUN_680ac450)
// Address: 680ac450
// Size: 175 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveScoreRef(int *param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int local_28 [4];
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = *(int *)(iVar1 + 0x20);
    if ((local_18 != 0) && (*(int *)(local_18 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  Ordinal_1130(param_3,0x14);
  iVar1 = param_2[1];
  iVar2 = media_getCastMemberByNum(param_1,*param_2,local_28);
  if (iVar2 == 0) {
    media_readScoreBlock2(local_28,iVar1,param_3);
  }
  if (local_18 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_resolveScoreSlot (FUN_680ac500)
// Address: 680ac500
// Size: 32 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveScoreSlot(int *param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = media_setCastSoundRef(param_1,param_2);
  if (iVar1 == 0) {
    media_readScoreSlot((int)param_2);
  }
  return 0;
}



// ============================================================
// Function: media_getMovieProperty (FUN_680ac520)
// Address: 680ac520
// Size: 3552 bytes
// Params: int * param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getMovieProperty(int *param_1,int param_2,int param_3,uint *param_4)
{
  undefined3 uVar1;
  double dVar2;
  undefined4 ***pppuVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  short sVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined2 in_FPUControlWord;
  undefined4 *puVar14;
  undefined4 **ppuVar15;
  undefined4 *local_454;
  undefined4 local_450;
  int *local_44c;
  undefined4 local_448;
  undefined4 *local_444;
  undefined4 **local_440;
  undefined4 ***local_43c;
  undefined4 ****local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined8 local_428;
  undefined4 *local_420;
  undefined4 uStack_41c;
  undefined8 local_418;
  undefined4 local_410;
  undefined4 local_40c;
  char local_408;
  char local_407 [1023];
  uint local_8;
  
  local_448 = (undefined4 ***)*param_1;
  iVar12 = 0;
  iVar11 = 0;
  if (local_448 == (undefined4 ***)0x0) {
    local_440 = (undefined4 **)0x0;
    goto LAB_680acc95;
  }
  local_440 = ((int *)(size_t)local_448)[ /* FIXUP(C2109): cast to pointer for subscript */8];
  if ((local_440 == (undefined4 **)0x0) || (local_440[1] == (undefined4 *)0x0)) goto LAB_680acc95;
  local_450 = local_440[2];
  local_44c = (int *)local_440[1][2];
  if (local_450 != (undefined4 *)0x0) {
    iVar12 = ((int *)(size_t)local_450)[ /* FIXUP(C2109): cast to pointer for subscript */3];
  }
  Ordinal_2330();
  local_43c = local_448;
  local_434 = 0;
  local_438 = DAT_68196374;
  DAT_68196374 = &local_43c;
  if (local_450 == (undefined4 *)0x0) {
    if (local_44c == (int *)0x0) goto LAB_680acc95;
    iVar12 = *(int *)(*(int *)(*local_44c + 0x14) + 0x14);
  }
  if (param_3 < 0x2d8) {
    if (param_3 == 0x2d7) {
      if (param_2 == 0) {
        sprites_getLastError(iVar12,param_4);
        goto LAB_680acc95;
      }
      sprites_setLastError(iVar12,param_4);
      goto LAB_680acc7b;
    }
    if (param_3 < 0x173) {
      if (param_3 != 0x172) {
        if (param_3 < 0x104) {
          if (param_3 == 0x103) {
            if (param_2 == 0) {
              Ordinal_1314(local_440 + 10,&local_408,0x3ff);
              props_loadStringValue(iVar12,&local_408,param_4);
              goto LAB_680acc95;
            }
          }
          else {
            if (param_3 == 0x3c) {
              if (param_2 == 0) {
                local_444 = (undefined4 *)playback_getCurrentFrame((byte *)local_448);
                props_storeIntValue(iVar12,local_444,param_4);
                goto LAB_680acc95;
              }
              iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
              if (iVar11 == 0) {
                iVar12 = events_navigateToMovieFrame(((int *)(size_t)local_450)[ /* FIXUP(C2109): cast to pointer for subscript */3],1,0,(int)local_444);
                rendering_getChannelProperty((int)local_448,5,(undefined4 *)0x0);
                if (iVar12 == 0) {
                  iVar11 = -0x7ffbf439;
                }
              }
              goto LAB_680acc7b;
            }
            if (param_3 != 0xeb) goto switchD_680ac869_caseD_198;
            if (param_2 == 0) {
              props_storeIntValue(iVar12,local_440[1],param_4);
              goto LAB_680acc95;
            }
          }
        }
        else {
          if (param_3 != 300) {
            if (param_3 != 0x15c) goto switchD_680ac869_caseD_198;
            if (param_2 == 0) {
              piVar9 = local_440[1];
              uVar10 = 0x31;
              goto LAB_680ac78a;
            }
            iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
            if (iVar11 == 0) {
              local_418 = (double)CONCAT44((*(unsigned int *)((char *)&local_418 + 4)),local_444);
              Ordinal_361(local_440[1],(int *)local_448,0x31,(double *)&local_418);
            }
            goto LAB_680acc7b;
          }
          if (param_2 == 0) {
            uVar6 = rendering_getChannelType((int)(local_440 + 0x123));
            props_storeIntValue(iVar12,(uint)uVar6,param_4);
            goto LAB_680acc95;
          }
        }
        goto LAB_680acc76;
      }
      if (param_2 == 0) {
        uVar8 = scoreEngine_getFrameRate((int *)local_440);
        local_444 = (undefined4 *)(int)(short)uVar8;
        props_storeIntValue(iVar12,local_444,param_4);
        goto LAB_680acc95;
      }
      iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
      if (iVar11 == 0) {
        if ((int)local_444 < 1) {
          iVar11 = props_returnWithValue(iVar12,0x800407d8,param_4);
        }
        else {
          scoreEngine_setPlaybackFrame((int *)local_440,(short)local_444);
          rendering_getChannelProperty((int)local_448,5,(undefined4 *)0x0);
        }
      }
      goto LAB_680acc7b;
    }
    switch(param_3) {
    case 0x197:
      if (param_2 == 0) {
        scoreEngine_readCastXtraBlock((int)local_440,(undefined1 *)&local_450);
        if ((*(unsigned char *)((char *)&local_450 + 3)) != '\0') {
          events_manageCastMember(iVar12,(undefined2 *)&local_450,0);
        }
        props_storeIntValue(iVar12,(uint)local_450 & 0xff,param_4);
        goto LAB_680acc95;
      }
      iVar11 = props_coerceAndReturnBool(iVar12,param_4,(undefined1 *)&local_450);
      if (iVar11 == 0) {
        ppuVar15 = ((int *)(size_t)local_448)[ /* FIXUP(C2109): cast to pointer for subscript */8];
        goto LAB_680acb3e;
      }
      goto LAB_680acc7b;
    default:
      goto switchD_680ac869_caseD_198;
    case 0x1b2:
      if (param_2 == 0) {
        Ordinal_1310(local_440 + 10,&local_408,0x3ff);
        props_loadStringValue(iVar12,&local_408,param_4);
        goto LAB_680acc95;
      }
      break;
    case 0x1fd:
      if (param_2 == 0) {
        props_storeIntValue(iVar12,local_440[0x116],param_4);
        goto LAB_680acc95;
      }
      break;
    case 0x253:
      if (param_2 == 0) {
        media_getMediaTypeRef((int)local_440,(int *)param_4);
        goto LAB_680acc95;
      }
      iVar11 = -0x7ffbf824;
      piVar9 = props_getApiContext((int *)param_4);
      if (piVar9 != (int *)0x0) {
        sVar7 = 1;
LAB_680ac8d9:
        iVar11 = media_setCastDataEntry(local_440,sVar7,piVar9);
        props_getApiState((int *)param_4);
      }
      goto LAB_680acc7b;
    case 0x254:
      if (param_2 == 0) {
        media_getMediaTypeRef((int)local_440,(int *)param_4);
        goto LAB_680acc95;
      }
      iVar11 = -0x7ffbf824;
      piVar9 = props_getApiContext((int *)param_4);
      if (piVar9 != (int *)0x0) {
        sVar7 = 2;
        goto LAB_680ac8d9;
      }
      goto LAB_680acc7b;
    case 0x255:
      if (param_2 == 0) {
        iVar11 = playback_getLifecycleState((int)local_448);
        local_444 = (undefined4 *)(uint)(iVar11 != 0);
        props_storeIntValue(iVar12,local_444,param_4);
        goto LAB_680acc95;
      }
      break;
    case 0x256:
      if (param_2 == 0) {
        sVar7 = scoreEngine_getCastVersion((int)local_440);
        local_444 = (undefined4 *)(int)sVar7;
        props_storeIntValue(iVar12,local_444,param_4);
        goto LAB_680acc95;
      }
      break;
    case 599:
      if (param_2 == 0) {
        playback_setTempo((byte *)local_448,(int)&local_430);
        local_418 = (double)CONCAT44(local_430,local_42c);
        local_40c = (undefined4)local_428;
        local_410 = (*(unsigned int *)((char *)&local_428 + 4));
        props_storeRectOp(iVar12,(undefined4 *)&local_418,param_4);
        goto LAB_680acc95;
      }
      break;
    case 600:
      if (param_2 == 0) {
        local_450 = (undefined4 *)scoreEngine_getChannelState((int)local_440);
        cast_getScoreXtraData(iVar12,(short *)&local_450);
        goto LAB_680acc95;
      }
      iVar11 = cast_applyXtraFormatCode();
      if (iVar11 == 0) {
        iVar11 = media_setCastChannelField((uint)local_440,(int)local_448,(short *)&local_450);
      }
      goto LAB_680acc7b;
    case 0x25a:
      if (param_2 == 0) {
        local_444 = local_440[0x199];
        props_storeIntValue(iVar12,local_444,param_4);
        goto LAB_680acc95;
      }
      iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
      if (iVar11 == 0) {
        local_440[0x199] = (undefined4 *)(uint)(local_444 != (undefined4 *)0x0);
        rendering_getChannelProperty((int)local_448,5,(undefined4 *)0x0);
      }
      goto LAB_680acc7b;
    case 0x25b:
      if (param_2 == 0) {
        local_444 = (undefined4 *)(int)*(short *)(local_440 + 0x11e);
        props_storeIntValue(iVar12,local_444,param_4);
        goto LAB_680acc95;
      }
    }
    goto LAB_680acc76;
  }
  if (0x550 < param_3) {
    if (param_3 < 0x657) {
      if (param_3 != 0x656) {
        if (param_3 == 0x551) {
          if (param_2 == 0) {
            uVar10 = 0x25;
            goto LAB_680ad125;
          }
        }
        else {
          if (param_3 != 0x555) {
            if (param_3 != 0x556) goto switchD_680ac869_caseD_198;
            if (param_2 == 0) {
              local_444 = (undefined4 *)events_getChannelEditMode(iVar12);
              props_storeIntValue(iVar12,local_444,param_4);
              goto LAB_680acc95;
            }
            iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
            if (iVar11 == 0) {
              events_setChannelEditMode(iVar12,(uint)(local_444 != (undefined4 *)0x0));
            }
            goto LAB_680acc7b;
          }
          if (param_2 == 0) {
            local_444 = (undefined4 *)sprites_downloadNetFile(iVar12);
            props_storeIntValue(iVar12,local_444,param_4);
            goto LAB_680acc95;
          }
        }
        goto LAB_680acc76;
      }
      if (param_2 == 0) {
        local_444 = (undefined4 *)events_getChannelSelection(iVar12);
        props_storeIntValue(iVar12,local_444,param_4);
        goto LAB_680acc95;
      }
      iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
      if (iVar11 == 0) {
        events_setChannelSelection(iVar12,(uint)(local_444 != (undefined4 *)0x0));
      }
    }
    else {
      if (param_3 == 0x676) {
        if (param_2 == 0) {
          props_loadStringValue(iVar12," ",param_4);
          goto LAB_680acc95;
        }
        goto LAB_680acc76;
      }
      if (param_3 != 0x677) goto switchD_680ac869_caseD_198;
      if (param_2 == 0) {
        Ordinal_360(local_440[1],local_448,0x35,(double *)&local_420);
        props_storeFloatDirect(iVar12,(double)CONCAT44(uStack_41c,local_420),(int *)param_4);
        goto LAB_680acc95;
      }
      iVar11 = props_coerceAndReturnDouble(iVar12,param_4,(double *)&local_428);
      if (iVar11 == 0) {
        local_418 = local_428;
        puVar14 = local_440[1];
        iVar12 = 0x35;
        goto LAB_680ad105;
      }
    }
    goto LAB_680acc7b;
  }
  if (param_3 == 0x550) {
    if (param_2 == 0) {
      uVar10 = 0x24;
LAB_680ad125:
      Ordinal_360(local_440[1],local_448,uVar10,(double *)&local_420);
      local_454 = local_420;
      props_storeObjectRef(iVar12,(int)local_420,param_4);
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnFloat(iVar12,param_4,(uint *)&local_454);
    if (iVar11 == 0) {
      local_418 = (double)CONCAT44((*(unsigned int *)((char *)&local_418 + 4)),local_454);
      puVar14 = local_440[1];
      iVar12 = 0x24;
LAB_680ad105:
      iVar12 = Ordinal_361(puVar14,(int *)local_448,iVar12,(double *)&local_418);
      if (iVar12 == 0) {
        iVar11 = -0x7ffbffec;
      }
    }
    goto LAB_680acc7b;
  }
  switch(param_3) {
  case 0x2e3:
  case 0x2e4:
    if (param_2 == 0) {
      props_storeIntValue(iVar12,(int)*(short *)(local_440 + 0x122),param_4);
      goto LAB_680acc95;
    }
    goto LAB_680acc76;
  default:
switchD_680ac869_caseD_198:
    iVar11 = -0x7ffbf82b;
    break;
  case 0x33b:
    if (param_2 == 0) {
      uVar10 = sprites_getStageRef(iVar12);
      props_storeIntValue(iVar12,uVar10,param_4);
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
    if ((iVar11 == 0) &&
       (bVar13 = local_444 != (undefined4 *)0x0, uVar8 = sprites_getWindowHandle(iVar12,(uint)bVar13),
       uVar8 != bVar13)) goto LAB_680acc76;
    break;
  case 0x346:
    if (param_2 == 0) {
      iVar11 = lingo_getGlobalState((int)local_44c);
      props_storeIntValue(iVar12,iVar11,param_4);
      goto LAB_680acc95;
    }
    goto LAB_680acc76;
  case 0x35a:
    if (param_2 == 0) {
      scoreEngine_readCastXtraBlock((int)local_440,(undefined1 *)&local_450);
      props_storeFloatValue(iVar12,&local_450,param_4);
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndStore(iVar12,param_4,&local_450);
    if (iVar11 == 0) {
      ppuVar15 = ((int *)(size_t)local_448)[ /* FIXUP(C2109): cast to pointer for subscript */8];
LAB_680acb3e:
      pppuVar3 = local_448;
      scoreEngine_writeCastXtraBlock((int *)ppuVar15,&local_450);
      rendering_getChannelProperty((int)pppuVar3,5,(undefined4 *)0x0);
      playback_getLifecycleInfo((byte *)pppuVar3);
    }
    break;
  case 0x362:
    if (param_2 == 0) {
      media_getMediaTypeRef((int)local_440,(int *)param_4);
      goto LAB_680acc95;
    }
    goto LAB_680acc76;
  case 0x363:
    if (param_2 == 0) {
      media_getMediaTypeRef((int)local_440,(int *)param_4);
      goto LAB_680acc95;
    }
    goto LAB_680acc76;
  case 0x375:
    if (param_2 == 0) {
      piVar9 = (int *)Ordinal_482(((int *)(size_t)local_450)[ /* FIXUP(C2109): cast to pointer for subscript */8],((int *)(size_t)local_450)[ /* FIXUP(C2109): cast to pointer for subscript */10]);
      if (piVar9 == (int *)0x0) {
        local_444 = (undefined4 *)0x3e8;
        props_storeIntValue(iVar12,1000,param_4);
      }
      else {
        local_444 = (undefined4 *)Ordinal_480(piVar9);
        props_storeIntValue(iVar12,local_444,param_4);
      }
      goto LAB_680acc95;
    }
    goto LAB_680acc76;
  case 899:
    if (param_2 == 0) {
      uVar8 = lingo_getPlaybackSize(((int *)(size_t)local_450)[ /* FIXUP(C2109): cast to pointer for subscript */8]);
      local_44c = (int *)(uVar8 >> 8 & 0xff);
      dVar2 = (double)(int)local_44c + (double)(uVar8 & 0xff) * 0.00390625;
      if (dVar2 != 0.0) {
        dVar2 = 1.0 / dVar2;
      }
      props_storeFloatDirect(iVar12,dVar2,(int *)param_4);
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnDouble(iVar12,param_4,(double *)&local_428);
    if (iVar11 == 0) {
      if (local_428 != 0.0) {
        local_428 = 1.0 / local_428;
      }
      (*(unsigned short *)((char *)&local_44c + 0)) = (undefined2)(int)ROUND(local_428);
      local_448 = (undefined4 ***)CONCAT22(in_FPUControlWord,(undefined2)local_448);
      local_428 = local_428 - (double)((int)ROUND(local_428) & 0xffff);
      uVar1 = CONCAT21((*(unsigned short *)((char *)&local_44c + 0)),(char)(int *)(int)ROUND(local_428 * 256.0));
      local_44c = (int *)(int)ROUND(local_428 * 256.0);
      iVar12 = Ordinal_159(((int *)(size_t)local_450)[ /* FIXUP(C2109): cast to pointer for subscript */8],(ushort)uVar1);
      if (iVar12 == 0) {
        iVar11 = -0x7ffbffec;
      }
    }
    break;
  case 0x39e:
    if (param_2 == 0) {
      cVar4 = events_getScoreTrailFlag(iVar12);
      if (cVar4 == -2) {
        local_44c = (int *)0x39b;
        props_storeObjectRef(iVar12,0x39b,param_4);
      }
      else if (cVar4 == -3) {
        local_44c = (int *)0x39c;
        props_storeObjectRef(iVar12,0x39c,param_4);
      }
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnFloat(iVar12,param_4,(uint *)&local_44c);
    if (iVar11 == 0) {
      if (local_44c == (int *)0x39b) {
        local_450 = (undefined4 *)CONCAT31((*(unsigned int *)((char *)&local_450 + 1)),0xfe);
        events_setScoreTrailFlag(iVar12,0xfe);
      }
      else {
        if (local_44c != (int *)0x39c) goto LAB_680acf1f;
        local_450 = (undefined4 *)CONCAT31((*(unsigned int *)((char *)&local_450 + 1)),0xfd);
        events_setScoreTrailFlag(iVar12,0xfd);
      }
    }
    break;
  case 0x39f:
    if (param_2 == 0) {
      bVar5 = events_getScoreMovableFlag(iVar12);
      local_44c = (int *)(uint)bVar5;
      if (local_44c == (int *)0xfc) {
        props_storeObjectRef(iVar12,0x7e,param_4);
      }
      else if (local_44c < (int *)0x65) {
        props_storeIntValue(iVar12,local_44c,param_4);
      }
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_44c);
    if (iVar11 == 0) {
      if (local_44c < (int *)0x65) {
        events_setScoreMovableFlag(iVar12,(char)local_44c);
      }
      else {
LAB_680acf1f:
        iVar11 = -0x7ffbf828;
      }
    }
    break;
  case 0x3b5:
    if (param_2 == 0) {
      events_formatScoreVersion(iVar12,&local_408);
      props_loadStringValue(iVar12,local_407,param_4);
      goto LAB_680acc95;
    }
LAB_680acc76:
    iVar11 = -0x7ffbf82a;
    break;
  case 0x3b6:
    if (param_2 == 0) {
      local_444 = (undefined4 *)events_getScoreAnnotation(iVar12);
      props_storeIntValue(iVar12,local_444,param_4);
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
    if (iVar11 == 0) {
      events_setScoreAnnotation(iVar12,(uint)(local_444 != (undefined4 *)0x0));
    }
    break;
  case 0x3c4:
    if (param_2 == 0) {
      piVar9 = local_440[1];
      uVar10 = 0x1a;
LAB_680ac78a:
      Ordinal_360(piVar9,local_448,uVar10,(double *)&local_420);
      local_444 = local_420;
      props_storeIntValue(iVar12,local_420,param_4);
      goto LAB_680acc95;
    }
    iVar11 = props_coerceAndReturnInt(iVar12,param_4,(int *)&local_444);
    if (iVar11 == 0) {
      local_418 = (double)CONCAT44((*(unsigned int *)((char *)&local_418 + 4)),local_444);
      Ordinal_361(local_440[1],(int *)local_448,0x1a,(double *)&local_418);
    }
  }
LAB_680acc7b:
  if ((param_2 != 0) && (iVar11 == 0)) {
    local_440[0x116] = (undefined4 *)0x1;
  }
LAB_680acc95:
  if (local_440 != (undefined4 **)0x0) {
    DAT_68196374 = local_438;
    Ordinal_2331();
  }
  return 0;
}
