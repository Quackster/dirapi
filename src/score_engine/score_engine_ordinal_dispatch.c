// Module: score_engine
// Topic: Ordinal dispatch - score query handlers, event dispatch, frame ordinals
// Address range: 0x6808d8c0 - 0x6808fd60
// Functions (26):
//   scoreEngine_dispatchPrepareFrame
//   scoreEngine_dispatchExitFrame
//   Ordinal_613
//   scoreEngine_renderSpritePair
//   scoreEngine_checkChannelFlag
//   scoreEngine_setChannelFlag
//   Ordinal_361
//   Ordinal_390
//   Ordinal_391
//   Ordinal_362
//   Ordinal_363
//   Ordinal_364
//   Ordinal_365
//   scoreEngine_dispatchPropertyGet
//   scoreEngine_dispatchPropertySet
//   Ordinal_108
//   Ordinal_59
//   Ordinal_73
//   Ordinal_219
//   Ordinal_218
//   scoreEngine_registerCallback
//   scoreEngine_unregisterCallback
//   scoreEngine_invokeCallback
//   scoreEngine_checkCallbackState
//   scoreEngine_clearCallbackState
//   Ordinal_373

// ============================================================
// Function: scoreEngine_dispatchPrepareFrame (FUN_6808d8c0)
// Address: 6808d8c0
// Size: 206 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_dispatchPrepareFrame(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar2 = *(int **)(param_1 + 0x20);
  uVar7 = 0;
  iVar4 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar5 = *(int *)(iVar4 + 0x120);
  piVar6 = piVar2;
  if (iVar5 <= *(int *)(iVar4 + 0x124)) {
    iVar3 = iVar5 * 400;
    do {
      iVar1 = *(int *)(iVar4 + 0x34) + iVar3;
      if (iVar1 == 0) goto LAB_6808d966;
      if ((*(int *)(iVar1 + 0x60) == 6) && (*(int *)(iVar1 + 0x14c) != 0)) {
        piVar2 = piVar6;
        Ordinal_1972(*(int *)(iVar1 + 0x14c));
        piVar6 = piVar2;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 400;
    } while (iVar5 <= *(int *)(iVar4 + 0x124));
  }
  uVar7 = 1;
LAB_6808d966:
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(piVar6,uVar7);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_dispatchExitFrame (FUN_6808d990)
// Address: 6808d990
// Size: 206 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_dispatchExitFrame(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar2 = *(int **)(param_1 + 0x20);
  uVar7 = 0;
  iVar4 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar5 = *(int *)(iVar4 + 0x120);
  piVar6 = piVar2;
  if (iVar5 <= *(int *)(iVar4 + 0x124)) {
    iVar3 = iVar5 * 400;
    do {
      iVar1 = *(int *)(iVar4 + 0x34) + iVar3;
      if (iVar1 == 0) goto LAB_6808da36;
      if ((*(int *)(iVar1 + 0x60) == 6) && (*(int *)(iVar1 + 0x14c) != 0)) {
        piVar2 = piVar6;
        Ordinal_1973(*(int *)(iVar1 + 0x14c));
        piVar6 = piVar2;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 400;
    } while (iVar5 <= *(int *)(iVar4 + 0x124));
  }
  uVar7 = 1;
LAB_6808da36:
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(piVar6,uVar7);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_613
// Address: 6808da60
// Size: 200 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_613(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8da60  613   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar4 = 0;
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar4 = *(int *)(piVar1[1] + 8);
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
  uVar2 = rendering_updateChannelState(*(int *)(iVar3 + 0x20) + 0x48c);
  if (uVar2 < 0x1100) {
    iVar3 = *(int *)(iVar3 + 0x20) + 0x50c;
    if (param_5 == 0) {
      playback_updateSpriteChannelState(iVar4,iVar3,param_3,param_4);
    }
    else {
      playback_renderSpriteEx(iVar4,iVar3,param_3,param_4);
    }
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_renderSpritePair (FUN_6808db30)
// Address: 6808db30
// Size: 200 bytes
// Params: int param_1, int param_2, ushort * param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_renderSpritePair(int param_1,int param_2,ushort *param_3,undefined4 param_4,int param_5)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar4 = 0;
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar4 = *(int *)(piVar1[1] + 8);
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
  uVar2 = rendering_updateChannelState(*(int *)(iVar3 + 0x20) + 0x48c);
  if (uVar2 < 0x1100) {
    iVar3 = *(int *)(iVar3 + 0x20) + 0x50c;
    if (param_5 == 0) {
      playback_setupSpriteTransform(iVar4,iVar3,param_3);
    }
    else {
      playback_initSpriteChannelState(iVar4,iVar3,param_3);
    }
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_checkChannelFlag (FUN_6808dc00)
// Address: 6808dc00
// Size: 69 bytes
// Params: byte param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool scoreEngine_checkChannelFlag(byte param_1)

{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x46c) == 0) {
    bitmap_createCastEntry(unaff_EDI);
  }
  iVar2 = Ordinal_1114(*(undefined4 *)(unaff_EDI + 0x46c));
  uVar1 = *(uint *)(iVar2 + 0xc);
  Ordinal_1115(*(undefined4 *)(unaff_EDI + 0x46c));
  return (1 << (param_1 & 0x1f) & uVar1) != 0;
}



// ============================================================
// Function: scoreEngine_setChannelFlag (FUN_6808e980)
// Address: 6808e980
// Size: 89 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setChannelFlag(int param_1)
{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  byte unaff_DI;
  
  if (*(int *)(unaff_ESI + 0x46c) == 0) {
    bitmap_createCastEntry(unaff_ESI);
  }
  iVar1 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x46c));
  if (iVar1 != 0) {
    uVar2 = 1 << (unaff_DI & 0x1f);
    if (param_1 != 0) {
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | uVar2;
      Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x46c));
      return 0;
    }
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & ~uVar2;
  }
  Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x46c));
  return 0;
}



// ============================================================
// Function: Ordinal_361
// Address: 6808e9e0
// Size: 1939 bytes
// Params: undefined4 * param_1, int * param_2, int param_3, double * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_361(undefined4 *param_1,int *param_2,int param_3,double *param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *local_424;
  int *local_41c;
  int *local_418;
  int *local_414;
  int **local_410;
  undefined4 local_40c;
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
                    /* 0x8e9e0  361   */
  piVar1 = (int *)param_1[8];
  local_41c = param_2;
  local_424 = (int *)0x0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == (int *)0x0) {
      param_2 = (int *)*piVar1;
    }
    Ordinal_2330();
    local_40c = 0;
    local_410 = DAT_68196374;
    DAT_68196374 = &local_414;
    local_424 = param_2;
    local_414 = param_2;
  }
  puVar2 = (undefined4 *)local_424[8];
  switch(param_3) {
  case MPROP_CAST_DATA_199:
    puVar2[0x199] = *(undefined4 *)param_4;
    break;
  case MPROP_DIMENSION_B:
    *(undefined2 *)(puVar2 + 0x122) = *(undefined2 *)param_4;
    goto LAB_6808f153;
  default:
switchD_6808ea7f_caseD_5:
    Ordinal_1130(param_4,0x10);
    goto LAB_6808ef07;
  case MPROP_CAST_DATA_2E6:
    puVar2[0x2e6] = *(undefined4 *)param_4;
    goto LAB_6808f153;
  case MPROP_SCORE_CHANNEL_MAX:
    scoreEngine_loadScoreData(puVar2,*(undefined4 *)param_4);
    break;
  case MPROP_TYPE_BYTE:
    *(undefined1 *)(puVar2 + 0x137) = *(undefined1 *)param_4;
    break;
  case MPROP_EXT_FLAG_A:
    *(undefined1 *)((int)puVar2 + 0x4dd) = *(undefined1 *)param_4;
    break;
  case MPROP_EXT_FLAG_B:
    *(undefined2 *)((int)puVar2 + 0x4de) = *(undefined2 *)param_4;
    break;
  case MPROP_RESERVED_C:
    break;
  case MPROP_DISPLAY_CAPABILITY:
    scoreEngine_setChannelFlag(*(int *)param_4);
    break;
  case MPROP_CAST_DATA_116:
    puVar2[0x116] = *(undefined4 *)param_4;
    goto LAB_6808f153;
  case MPROP_LOAD_RESOURCE:
  case MPROP_MEDIA_CONVERSION:
    playback_reloadFontMapFromStream(*(int **)(puVar2[1] + 8),puVar2 + 0x143,*(undefined4 *)param_4,0);
    if (param_3 != 0x10) break;
    goto LAB_6808f153;
  case MPROP_FRAME_COUNT:
    scoreEngine_setChannelState((int)puVar2,*(int *)param_4);
    break;
  case MPROP_CAST_DATA_19B:
    puVar2[0x19b] = *(undefined4 *)param_4;
    break;
  case MPROP_GOTO_FRAME_FIRST:
    puVar2[0x17f] = *(undefined4 *)param_4;
    if (*(int *)param_4 != 0) {
      local_424[0x1c] = 0;
      scoreEngine_loadCastXtra(piVar1,0);
    }
    break;
  case MPROP_GOTO_FRAME_SECOND:
    puVar2[0x180] = *(undefined4 *)param_4;
    if (*(int *)param_4 != 0) {
      local_424[0x1d] = 0;
      scoreEngine_loadCastXtra(piVar1,1);
    }
    break;
  case MPROP_CAST_DATA_197:
    puVar2[0x197] = *(undefined4 *)param_4;
    break;
  case MPROP_CAST_DATA_196:
    puVar2[0x196] = *(undefined4 *)param_4;
    break;
  case MPROP_CAST_DATA_198:
    puVar2[0x198] = *(undefined4 *)param_4;
    break;
  case MPROP_EXT_COMPAT:
    *(undefined1 *)((int)puVar2 + 0x49d) = *(undefined1 *)param_4;
    break;
  case MPROP_MEMBER_FLAG_BIT0:
    if (*(int *)param_4 == 0) {
      *(byte *)(puVar2 + 0x127) = *(byte *)(puVar2 + 0x127) & 0xfe;
    }
    else {
      *(byte *)(puVar2 + 0x127) = *(byte *)(puVar2 + 0x127) | 1;
    }
    break;
  case MPROP_PROPERTY_STORE:
    if ((*(int *)param_4 != 0) && (puVar2[0x11b] != 0)) {
      iVar7 = Ordinal_1116(*(int *)param_4);
      local_418 = (int *)0x0;
      if (0xff < iVar7) {
        local_41c = (int *)Ordinal_1114(*(undefined4 *)param_4);
        iVar3 = Ordinal_1285((int)local_41c + 1,0x100);
        iVar3 = iVar3 - (int)local_41c;
        iVar8 = iVar3 + -1;
        piVar9 = local_418;
        if (iVar8 < iVar7 + -2) {
          local_418 = (int *)0x0;
          local_418 = (int *)Ordinal_1111(iVar3 + 1,1);
          if (local_418 != (int *)0x0) {
            puVar4 = (undefined1 *)Ordinal_1114(local_418);
            Ordinal_1128(puVar4 + 1,(int)local_41c + 1,iVar8);
            puVar4[iVar3] = 0;
            if (iVar8 < 0xff) {
              *puVar4 = (char)iVar8;
            }
            else {
              *puVar4 = 0xff;
            }
            cast_formatNumber(puVar2 + 0x11b,*(short *)((int)param_4 + 4),(int)local_418);
            Ordinal_1115(local_418);
            Ordinal_1113(&local_418);
          }
          piVar9 = (int *)0x1;
        }
        if (local_41c != (int *)0x0) {
          Ordinal_1115(*(undefined4 *)param_4);
        }
        if (piVar9 != (int *)0x0) break;
      }
      cast_formatNumber(puVar2 + 0x11b,*(short *)((int)param_4 + 4),*(int *)param_4);
    }
    break;
  case MPROP_CAST_DATA_1A1:
    puVar2[0x1a1] = *(undefined4 *)param_4;
    break;
  case MPROP_EXT_QUALITY:
    if (*(char *)param_4 != *(char *)((int)puVar2 + 0x4aa)) {
      *(char *)((int)puVar2 + 0x4aa) = *(char *)param_4;
      puVar2[0x2e9] = 1;
    }
    break;
  case MPROP_EXT_RATE:
    if (*(byte *)param_4 < 0x65) {
      *(byte *)((int)puVar2 + 0x4c1) = *(byte *)param_4;
    }
    else {
      *(undefined1 *)((int)puVar2 + 0x4c1) = 0x50;
    }
    break;
  case MPROP_CAST_DATA_1A2:
    puVar2[0x1a2] = *(undefined4 *)param_4;
    break;
  case MPROP_CAST_DATA_1A3:
    puVar2[0x1a3] = *(undefined4 *)param_4;
    break;
  case MPROP_PALETTE_MODE:
    iVar7 = puVar2[0x12d];
    switch(*(undefined4 *)param_4) {
    case 0x547:
      puVar2[0x12d] = 1;
      break;
    default:
      puVar2[0x12d] = 0;
      break;
    case 0x549:
      puVar2[0x12d] = 5;
      break;
    case 0x54a:
      puVar2[0x12d] = 3;
      break;
    case 0x54b:
      puVar2[0x12d] = 2;
      break;
    case 0x54f:
      puVar2[0x12d] = 4;
    }
    local_418 = (int *)0x0;
    uVar5 = Ordinal_1038(&DAT_681765b8,&DAT_681765c8,&local_418);
    Ordinal_2063(uVar5);
    if (local_418 != (int *)0x0) {
      (**(code **)(*local_418 + 0xc))(local_418);
      (**(code **)(*local_418 + 0x18))(local_418,puVar2[0x12d]);
      (**(code **)(*local_418 + 8))(local_418);
    }
    if (puVar2[0x12d] == iVar7) goto switchD_6808ea7f_caseD_5;
    break;
  case MPROP_LINKED_FILE_DATA:
    if (0 < *(int *)param_4) {
      media_dispatchChannelRender(param_1,local_41c,*(int *)param_4,*(int *)((int)param_4 + 4),
                   *(int *)(param_4 + 1));
    }
    break;
  case MPROP_STRING_PROP_A:
    uVar6 = Ordinal_1201(*(undefined4 *)param_4);
    if (0x3fe < uVar6) {
      local_41c = (int *)0x0;
      iVar7 = Ordinal_1251(*(int *)param_4,*(int *)param_4 + 0x3fe,&local_41c);
      uVar6 = iVar7 - *(int *)param_4;
    }
    Ordinal_1128(local_407,*(undefined4 *)param_4,uVar6);
    local_408 = (char)uVar6;
    if (local_408 == -1) {
      local_408 = -1;
    }
    if (puVar2[0x11b] != 0) {
      Ordinal_37(puVar2 + 0x11b,9,&local_408,uVar6 + 1);
    }
    break;
  case MPROP_STRING_PROP_B:
    uVar6 = Ordinal_1201(*(undefined4 *)param_4);
    if (0x3fe < uVar6) {
      local_41c = (int *)0x0;
      iVar7 = Ordinal_1251(*(int *)param_4,*(int *)param_4 + 0x3fe,&local_41c);
      uVar6 = iVar7 - *(int *)param_4;
    }
    Ordinal_1128(local_407,*(undefined4 *)param_4,uVar6);
    local_408 = (char)uVar6;
    if (local_408 == -1) {
      local_408 = -1;
    }
    if (puVar2[0x11b] != 0) {
      Ordinal_37(puVar2 + 0x11b,10,&local_408,uVar6 + 1);
    }
    break;
  case MPROP_SOUND_FORMAT:
    iVar7 = *(int *)param_4;
    if (iVar7 == 0x217) {
LAB_6808f0c6:
      puVar2[0x12e] = 1;
    }
    else if (iVar7 == 0x218) {
      puVar2[0x12e] = 2;
    }
    else {
      if (iVar7 != 0x21a) goto LAB_6808f0c6;
      puVar2[0x12e] = 4;
    }
    break;
  case MPROP_CAST_DATA_139:
    puVar2[0x139] = *(undefined4 *)param_4;
    break;
  case MPROP_CAST_DATA_13A:
    puVar2[0x13a] = *(undefined4 *)param_4;
    break;
  case MPROP_ENCODING_TYPE:
    if (*(int *)param_4 == 0x23) {
      puVar2[0x12f] = 1;
    }
    else {
      puVar2[0x12f] = 0;
    }
    break;
  case MPROP_CAST_DATA_13B:
    puVar2[0x13b] = *(undefined4 *)param_4;
    break;
  case MPROP_BITMASK_PROP:
    uVar6 = *(uint *)param_4;
    if (uVar6 == 0) {
      puVar2[0x138] = 0;
    }
    else if (*(int *)((int)param_4 + 4) == 0) {
      puVar2[0x138] = puVar2[0x138] & ~uVar6;
    }
    else {
      puVar2[0x138] = puVar2[0x138] | uVar6;
    }
    break;
  case MPROP_DISPLAY_MODE:
    scoreEngine_setChannelFlag((uint)(9 < *(int *)param_4));
    break;
  case MPROP_CHANNEL_COUNT:
    scoreEngine_setChannelType((int)puVar2,(char)*(undefined4 *)param_4);
    break;
  case MPROP_TEMPO_DOUBLE:
    *(double *)(puVar2 + 0x2ea) = *param_4;
    local_418 = (int *)0x0;
    uVar5 = Ordinal_1038(&DAT_681765b8,&DAT_681765c8,&local_418);
    Ordinal_2063(uVar5);
    if (local_418 != (int *)0x0) {
      (**(code **)(*local_418 + 0xc))(local_418);
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_41c = (int *)(float)*(double *)(puVar2 + 0x2ea); */
      (**(code **)(*local_418 + 0x84))(local_418,local_41c);
      (**(code **)(*local_418 + 8))(local_418);
    }
    break;
  case MPROP_TEMPO_FLOAT:
    local_41c = (int *)0x0;
    uVar5 = Ordinal_1038(&DAT_681765b8,&DAT_681765c8,&local_41c);
    Ordinal_2063(uVar5);
    if (local_41c != (int *)0x0) {
      (**(code **)(*local_41c + 0x8c))(local_41c,(float)*param_4);
    }
  }
  puVar2[0x116] = 1;
LAB_6808f153:
  rendering_getChannelProperty((int)local_424,5,(undefined4 *)0x0);
LAB_6808ef07:
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_410;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_390
// Address: 6808f270
// Size: 210 bytes
// Params: int param_1, uint param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_390(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f270  390   */
  iVar3 = 0;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
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
  puVar1 = (undefined4 *)scoreEngine_getSoundChannel(*(int *)(iVar3 + 0x20),param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *param_3 = *puVar1;
    *param_4 = puVar1[1];
    param_4[1] = puVar1[2];
    param_4[2] = puVar1[3];
    param_4[3] = puVar1[4];
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_391
// Address: 6808f350
// Size: 228 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_391(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f350  391   */
  iVar2 = 0;
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
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
  puVar1 = (undefined4 *)scoreEngine_getSoundChannel(*(int *)(iVar2 + 0x20),param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_3;
    if ((int)*(char *)(*(int *)(iVar2 + 0x20) + 0x5d0) < (int)(param_2 + 1)) {
      *(char *)(*(int *)(iVar2 + 0x20) + 0x5d0) = (char)(param_2 + 1);
    }
    puVar1[1] = *param_4;
    puVar1[2] = param_4[1];
    puVar1[3] = param_4[2];
    puVar1[4] = param_4[3];
    piVar3[0x116] = 1;
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_362
// Address: 6808f440
// Size: 135 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_362(int param_1,int param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f440  362   */
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
  scoreEngine_getChannelData(*(int *)(iVar2 + 0x20),(short)*param_3);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_363
// Address: 6808f4d0
// Size: 131 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_363(int param_1,int param_2,short param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f4d0  363   */
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
  scoreEngine_getChannelCount(*(int *)(iVar2 + 0x20),param_3);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_364
// Address: 6808f560
// Size: 147 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_364(int param_1,int param_2,short param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f560  364   */
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
  scoreEngine_getFrameData(*(int *)(iVar2 + 0x20),param_3);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_365
// Address: 6808f600
// Size: 137 bytes
// Params: int param_1, int param_2, short param_3, short param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_365(int param_1,int param_2,short param_3,short param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f600  365   */
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
  scoreEngine_getChannelRange(*(int *)(iVar2 + 0x20),param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_dispatchPropertyGet (FUN_6808f690)
// Address: 6808f690
// Size: 178 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_dispatchPropertyGet(int param_1,int param_2,int param_3,int param_4,int *param_5)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
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
  iVar2 = param_3 + -1;
  if (((-1 < iVar2) && (iVar2 < *(int *)(iVar3 + 0x2c))) &&
     (iVar3 = iVar2 * 400 + *(int *)(iVar3 + 0x34), iVar3 != 0)) {
    if (*(int *)(iVar3 + 0x60) == 10) {
      bitmap_callXtraMethod(iVar3,param_4,param_5);
    }
    else {
      *param_5 = -0x7ffbf821;
    }
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_dispatchPropertySet (FUN_6808f750)
// Address: 6808f750
// Size: 161 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_dispatchPropertySet(int param_1,int param_2,int param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
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
  iVar2 = param_3 + -1;
  if ((((-1 < iVar2) && (iVar2 < *(int *)(iVar3 + 0x2c))) &&
      (iVar3 = iVar2 * 400 + *(int *)(iVar3 + 0x34), iVar3 != 0)) && (*(int *)(iVar3 + 0x60) == 10))
  {
    bitmap_enumXtraProps(iVar3,param_4);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_108
// Address: 6808f800
// Size: 164 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_108(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f800  108   */
  iVar1 = 0;
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
  rendering_getChannelProperty(iVar1,param_2,param_3);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_59
// Address: 6808f8b0
// Size: 29 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_59(undefined4 param_1)
{
                    /* 0x8f8b0  59   */
  Ordinal_1202(param_1,"12.3.5");
  Ordinal_1201(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_73
// Address: 6808f8d0
// Size: 179 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_73(int param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f8d0  73   */
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
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
  if (iVar3 != 0) {
    rendering_getChannelDepth(iVar3);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_219
// Address: 6808f990
// Size: 147 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_219(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8f990  219   */
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
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
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_218
// Address: 6808fa30
// Size: 147 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_218(int param_1,undefined4 param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8fa30  218   */
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
  *(undefined4 *)(iVar1 + 0x378) = param_2;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_registerCallback (FUN_6808fad0)
// Address: 6808fad0
// Size: 140 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_registerCallback(int param_1)
{
  int iVar1;
  int *piVar2;
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
  playback_notifyRecursiveChannels(iVar1,1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_unregisterCallback (FUN_6808fb60)
// Address: 6808fb60
// Size: 133 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_unregisterCallback(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  Ordinal_1937();
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_invokeCallback (FUN_6808fbf0)
// Address: 6808fbf0
// Size: 132 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_invokeCallback(int param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  Ordinal_1936(param_2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_checkCallbackState (FUN_6808fc80)
// Address: 6808fc80
// Size: 92 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_checkCallbackState(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int extraout_EDX;
  
  iVar2 = param_2;
  Ordinal_377(param_1,param_2,&param_2,&param_1);
  iVar3 = param_3;
  iVar1 = param_1;
  iVar4 = param_2;
  while( true ) {
    if (iVar1 < iVar4) {
      return 0xffffffff;
    }
    iVar4 = scoreEngine_getPropertyBool(iVar2);
    if (iVar3 == *(int *)(iVar4 + 0x180)) break;
    iVar4 = extraout_EDX + 1;
  }
  *(uint *)(iVar4 + 0x4c) = *(uint *)(iVar4 + 0x4c) | 0x1000;
  return *(undefined4 *)(iVar4 + 8);
}



// ============================================================
// Function: scoreEngine_clearCallbackState (FUN_6808fcf0)
// Address: 6808fcf0
// Size: 98 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_clearCallbackState(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  int iVar4;
  char *pcVar5;
  
  iVar2 = param_2;
  Ordinal_377(param_1,param_2,&param_2,&param_1);
  iVar1 = param_1;
  if (param_1 < param_2) {
    return 0;
  }
  pcVar5 = (char *)(*(int *)(iVar2 + 0x30) + -1 + param_2);
  iVar4 = param_2;
  while ((*pcVar5 == '\0' ||
         (iVar3 = scoreEngine_getPropertyBool(iVar2), iVar4 = extraout_EDX, param_3 != *(int *)(iVar3 + 8)))) {
    iVar4 = iVar4 + 1;
    pcVar5 = pcVar5 + 1;
    if (iVar1 < iVar4) {
      return 0;
    }
  }
  *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) | 0x1000;
  return 0;
}



// ============================================================
// Function: Ordinal_373
// Address: 6808fd60
// Size: 2815 bytes
// Params: uint param_1, int param_2, int param_3, int param_4, double * param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_373(uint param_1,int param_2,int param_3,int param_4,double *param_5,int param_6)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 uVar1;
  undefined2 uVar2;
  byte bVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  undefined2 extraout_var_00;
  undefined3 extraout_var;
  undefined2 extraout_var_01;
  byte bVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  ushort in_FPUControlWord;
  double local_b8;
  uint local_b0;
  int *local_ac;
  double local_a8;
  short local_a0;
  int local_98;
  int local_94 [3];
  int local_88;
  double local_84;
  int local_7c;
  int *local_78;
  uint local_74;
  uint local_70;
  undefined8 local_6c;
  undefined4 *local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int *local_50;
  undefined4 local_4c;
  undefined4 local_48 [16];
  uint local_8;
  
                    /* 0x8fd60  373   */
  local_70 = param_1;
  local_ac = *(int **)(param_1 + 0x20);
  local_94[1] = 0;
  local_7c = 0;
  local_5c = 0;
  iVar6 = 0;
  if ((local_ac != (int *)0x0) && (local_ac[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *local_ac;
    }
    local_5c = param_2;
    Ordinal_2330();
    local_4c = 0;
    local_50 = DAT_68196374;
    iVar6 = param_2;
    DAT_68196374 = &local_54;
    local_54 = param_2;
  }
  local_78 = *(int **)(iVar6 + 0x28);
  iVar9 = param_3 + -1;
  local_58 = iVar9;
  iVar6 = media_lockScoreData(local_78,&local_7c,(undefined4 *)0x0);
  if ((((iVar9 < iVar6) && (-1 < iVar9)) && (iVar9 < *(int *)(local_5c + 0x2c))) &&
     (local_64 = (undefined4 *)(iVar9 * 400 + *(int *)(local_5c + 0x34)),
     local_64 != (undefined4 *)0x0)) {
    iVar6 = param_3 + 5;
    if ((iVar6 < 0) || (0x3ed < iVar6)) {
      pcVar11 = (char *)0x0;
    }
    else {
      pcVar11 = (char *)(iVar6 * 0x30 + local_7c);
    }
    uVar7 = param_4 - 1;
    piVar10 = local_78;
    if (uVar7 < 0x27) {
switchD_6808fe50_switchD:
      iVar6 = local_58;
      uVar2 = (undefined2)local_60;
      /* FIXUP(missing paren - Ghidra artifact): switch((&switchD_6808fe50::switchdataD_68090860)[uVar7]) { */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6808fe57: */
        local_a0 = scoreEngine_getChannelCount(*(int *)(local_5c + 0x20),(short)*(undefined4 *)param_5);
        local_60 = scoreEngine_setChannelField(*(uint *)(local_5c + 0x20),CONCAT22(extraout_var_00,local_a0));
        local_6c = (double)(ulonglong)CONCAT14(*(short *)(pcVar11 + 6) == 0,(undefined4)local_6c);
        xtra_readBE32(pcVar11 + 4);
        xtra_readBE32(pcVar11 + 6);
        media_setScorePosition((int)piVar10,local_58 + 6);
        if (param_6 != 0) {
          media_copyScoreData(piVar10,local_58,4,4);
        }
        iVar6 = local_5c;
        if (((*(unsigned int *)((char *)&local_6c + 4)) != 0) && (*pcVar11 == '\0')) {
          if (local_60 != 0) {
            if (*(int *)(local_60 + 8) == 0) goto LAB_6808ff31;
            if (0x700 < *(uint *)(*(int *)(local_5c + 0x20) + 0x500)) {
              if ((int)local_64[0x10] < *(int *)(local_5c + 0x120)) {
                *(undefined4 *)(local_5c + 0x120) = local_64[0x10];
              }
              if (*(int *)(local_5c + 0x124) < (int)local_64[0x10]) {
                *(undefined4 *)(local_5c + 0x124) = local_64[0x10];
              }
            }
            rendering_initSpriteDefault(local_5c,pcVar11);
            *(undefined4 *)(iVar6 + 0x180) = 1;
          }
          /* FIXUP(illegal break - outside switch/loop scope): break; */
        }
LAB_6808ff31:
        /* FIXUP(illegal break - outside switch/loop scope): if (local_60 == 0) break; */
        /* FIXUP(C2224: left of '._1_3_' must have struct/union type): local_48[0] = CONCAT31(local_48[0]._1_3_,0x10); */
        param_4 = 4;
        param_6 = 0;
        goto LAB_680901ba;
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6808ff50: */
        local_60 = rendering_writeSpriteData(*(uint *)(local_5c + 0x20),pcVar11);
        sVar5 = xtra_readBE16(pcVar11 + 0xe);
        local_94[2] = (int)sVar5;
        sVar5 = xtra_readBE16(pcVar11 + 0xc);
        local_88 = (int)sVar5;
        sVar5 = xtra_readBE16(pcVar11 + 0x12);
        local_98 = (int)sVar5;
        sVar5 = xtra_readBE16(pcVar11 + 0x10);
        local_94[0] = (int)sVar5;
        iVar6 = xtra_readBE32Ptr(pcVar11 + 0x1c);
        local_6c = (double)CONCAT44(iVar6,(undefined4)local_6c);
        local_a8 = (double)iVar6 / 100.0;
        iVar6 = xtra_readBE32Ptr(pcVar11 + 0x20);
        local_b8 = (double)iVar6 / 100.0;
        local_b0 = (byte)pcVar11[0x16] >> 6 & 1;
        local_74 = (byte)pcVar11[0x16] >> 5 & 1;
        local_6c = local_a8;
        local_84 = local_b8;
        playback_dispatchSpriteEvent(local_5c,(int)local_64,local_60,(int *)param_5,local_94 + 2,&local_88,&local_98
                     ,local_94,&local_a8,&local_b8,(int *)&local_74,(int *)&local_b0);
        xtra_readBE32(pcVar11 + 0xe);
        xtra_readBE32(pcVar11 + 0xc);
        xtra_readBE32(pcVar11 + 0x12);
        xtra_readBE32(pcVar11 + 0x10);
        if (local_6c != local_a8) {
          local_60 = CONCAT22(in_FPUControlWord,(undefined2)local_60);
          local_6c = (double)(longlong)ROUND(local_a8 * 100.0);
          xtra_skipBytes(pcVar11 + 0x1c);
          *(undefined4 *)(local_5c + 0x180) = 1;
        }
        if (local_84 != local_b8) {
          local_60 = CONCAT22(in_FPUControlWord,(undefined2)local_60);
          local_6c = (double)((ulonglong)CONCAT24(in_FPUControlWord,(undefined4)local_6c) |
                             0xc0000000000);
          local_84 = (double)(longlong)ROUND(local_b8 * 100.0);
          xtra_skipBytes(pcVar11 + 0x20);
          *(undefined4 *)(local_5c + 0x180) = 1;
        }
        piVar10 = local_78;
        if (param_6 != 0) {
          media_copyScoreData(local_78,local_58,0xc,4);
          media_copyScoreData(piVar10,local_58,0x10,4);
        }
        if ((*(byte *)(local_64 + 0x16) & 0x20) != 0) {
          local_64[0x1c] = local_94[2];
          local_64[0x1d] = local_88;
        }
        local_48[0] = 1;
        piVar10 = local_78;
        goto LAB_680901b3;
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090171: */
        xtra_readBE32(pcVar11 + 0x12);
        if (param_6 != 0) {
          iVar6 = 0x12;
LAB_680901a2:
          media_copyScoreData(piVar10,local_58,iVar6,2);
        }
        goto LAB_680901ac;
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6809018a: */
        xtra_readBE32(pcVar11 + 0x10);
        if (param_6 != 0) {
          iVar6 = 0x10;
          goto LAB_680901a2;
        }
LAB_680901ac:
        local_48[0] = 1;
LAB_680901b3:
        local_48[0] = 1;
        param_4 = 0x13;
LAB_680901ba:
        uVar7 = param_4 - 1;
        param_5 = (double *)local_48;
        /* FIXUP(C2094: label 'switchD_6808fe50_caseD_6809081a' was undefined): if (0x26 < uVar7) goto switchD_6808fe50_caseD_6809081a; */
        goto switchD_6808fe50_switchD;
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680901cf: */
        media_writeScoreBlockEx(piVar10,local_58,*(int *)param_5);
        if (*(int *)param_5 == 0) {
          local_64[0x11] = local_58 + 1;
          local_64[0x13] = local_64[0x13] & 0xfffffdff | 0x800;
          *(undefined4 *)(local_5c + 0x180) = 1;
        }
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090213: */
        *pcVar11 = *(char *)param_5;
        if (param_6 != 0) {
          media_copyScoreData(piVar10,local_58,0,1);
        }
        if (*(char *)param_5 == '\0') {
          media_setScorePosition((int)piVar10,local_58 + 6);
        }
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090246: */
        pcVar11[1] = pcVar11[1] ^ (*(byte *)param_5 ^ pcVar11[1]) & 0x3f;
        if (param_6 != 0) {
          media_writeScoreBlock(piVar10,local_58,1,0x3f);
          /* FIXUP(illegal break - outside switch/loop scope): break; */
        }
        goto LAB_680907d4;
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6809026e: */
        local_a0 = scoreEngine_getChannelCount(*(int *)(local_5c + 0x20),(short)*(undefined4 *)param_5);
        xtra_readBE32(pcVar11 + 4);
        xtra_readBE32(pcVar11 + 6);
        media_setScorePosition((int)piVar10,local_58 + 6);
        if (param_6 == 0) goto LAB_680907d4;
        media_copyScoreData(piVar10,local_58,4,4);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680902c7: */
        pcVar11[3] = *(char *)param_5;
        pcVar11[0x19] = *(char *)((int)param_5 + 1);
        pcVar11[0x1b] = *(char *)((int)param_5 + 2);
        if (*(char *)((int)param_5 + 3) == '\x01') {
          pcVar11[0x14] = pcVar11[0x14] | 0x20;
        }
        else {
          pcVar11[0x14] = pcVar11[0x14] & 0xdf;
        }
        if (param_6 == 0) goto LAB_680907d4;
        media_copyScoreData(piVar10,local_58,3,1);
        media_copyScoreData(piVar10,iVar6,0x19,1);
        media_copyScoreData(piVar10,iVar6,0x1b,1);
        media_writeScoreBlock(piVar10,iVar6,0x14,0x20);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090326: */
        pcVar11[2] = *(char *)param_5;
        pcVar11[0x18] = *(char *)((int)param_5 + 1);
        pcVar11[0x1a] = *(char *)((int)param_5 + 2);
        if (*(char *)((int)param_5 + 3) == '\x01') {
          pcVar11[0x14] = pcVar11[0x14] | 0x10;
        }
        else {
          pcVar11[0x14] = pcVar11[0x14] & 0xef;
        }
        if (param_6 == 0) goto LAB_680907d4;
        media_copyScoreData(piVar10,local_58,2,1);
        media_copyScoreData(piVar10,iVar6,0x18,1);
        media_copyScoreData(piVar10,iVar6,0x1a,1);
        media_writeScoreBlock(piVar10,iVar6,0x14,0x10);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090385: */
        pcVar11[0x16] = pcVar11[0x16] ^ (*(char *)param_5 + 1U ^ pcVar11[0x16]) & 0xf;
        if (param_6 == 0) goto LAB_680907d4;
        media_writeScoreBlock(piVar10,local_58,0x16,0xf);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680903ae: */
        sVar5 = xtra_readBE16(pcVar11 + 0xe);
        local_74 = (uint)sVar5;
        xtra_readBE32(pcVar11 + 0xe);
        if (param_6 != 0) {
          media_copyScoreData(piVar10,local_58,0xe,2);
        }
        if ((*(byte *)(local_64 + 0x16) & 0x20) != 0) {
          local_64[0x1c] = *(undefined4 *)param_5;
        }
        playback_clearSpriteRectState((int)local_64,*(int *)param_5 - local_74,0);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680903fc: */
        sVar5 = xtra_readBE16(pcVar11 + 0xc);
        local_74 = (uint)sVar5;
        xtra_readBE32(pcVar11 + 0xc);
        if (param_6 != 0) {
          media_copyScoreData(piVar10,local_58,0xc,2);
        }
        if ((*(byte *)(local_64 + 0x16) & 0x20) != 0) {
          local_64[0x1d] = *(undefined4 *)((int)param_5 + 4);
        }
        playback_clearSpriteRectState((int)local_64,0,*(int *)((int)param_5 + 4) - local_74);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6809044d: */
        uVar1 = *(undefined4 *)param_5;
        local_64[0x13] = local_64[0x13] | 0x800;
        local_64[0x11] = uVar1;
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090461: */
        pcVar11[1] = -(*(int *)param_5 != 0) & 0x80U | pcVar11[1] & 0x7fU;
        if (param_6 == 0) goto LAB_680907d4;
        media_writeScoreBlock(piVar10,local_58,1,0x80);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090494: */
        pcVar11[1] = -(*(int *)param_5 != 0) & 0x40U | pcVar11[1] & 0xbfU;
        if (param_6 == 0) goto LAB_680907d4;
        media_writeScoreBlock(piVar10,local_58,1,0x40);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680904c4: */
        uVar7 = local_64[0x14];
        if (*(uint *)param_5 != (~(uVar7 >> 1) & 1)) {
          if (*(uint *)param_5 == 0) {
            uVar7 = uVar7 | 2;
          }
          else {
            uVar7 = uVar7 & 0xfffffffd;
          }
          local_64[0x14] = uVar7;
          local_84 = (double)CONCAT44((*(unsigned int *)((char *)&local_84 + 4)),param_3);
          Ordinal_108(local_70,0x1e,(undefined4 *)&local_84);
        }
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090506: */
        pcVar11[0x15] = *(char *)param_5;
        if (*(char *)param_5 == '\0') {
          pcVar11[0x16] = pcVar11[0x16] & 0xef;
        }
        else {
          pcVar11[0x16] = pcVar11[0x16] | 0x10;
        }
        if (param_6 == 0) goto LAB_680907d4;
        media_copyScoreData(piVar10,local_58,0x15,1);
        media_writeScoreBlock(piVar10,iVar6,0x16,0x10);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090542: */
        bVar3 = -(*(int *)param_5 != 0) & 0x80;
        local_60 = CONCAT13(-(*(int *)param_5 != 0),(undefined3)local_60) & 0x80ffffff;
        pcVar11[0x14] = bVar3 | pcVar11[0x14] & 0x7fU;
        if (param_6 != 0) {
          media_writeScoreBlock(piVar10,local_58,0x14,0x80);
          bVar3 = (*(unsigned char *)((char *)&local_60 + 3));
        }
        bVar8 = *(byte *)((int)local_64 + 0x15) & 0x7f;
        goto LAB_6809057d;
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090592: */
        bVar3 = -(*(int *)param_5 != 0) & 0x40;
        local_60 = CONCAT13(-(*(int *)param_5 != 0),(undefined3)local_60) & 0x40ffffff;
        pcVar11[0x14] = bVar3 | pcVar11[0x14] & 0xbfU;
        if (param_6 != 0) {
          media_writeScoreBlock(piVar10,local_58,0x14,0x40);
          bVar3 = (*(unsigned char *)((char *)&local_60 + 3));
        }
        bVar8 = *(byte *)((int)local_64 + 0x15) & 0xbf;
LAB_6809057d:
        *(byte *)((int)local_64 + 0x15) = bVar8 | bVar3;
        rendering_registerSpriteChannel(local_5c,local_64);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680905cc: */
        pcVar11[0x14] = pcVar11[0x14] ^ (pcVar11[0x14] ^ *(byte *)param_5) & 0xf;
        if (param_6 == 0) goto LAB_680907d4;
        media_writeScoreBlock(piVar10,local_58,0x14,0xf);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680905f4: */
        if ((local_64[0x18] != 10) ||
           (bVar4 = bitmap_getXtraProperty((int)local_64,1,*(int *)param_5,*(uint **)((int)param_5 + 4)),
           /* FIXUP(C2094: label 'switchD_6808fe50_caseD_6809081a' was undefined): CONCAT31(extraout_var,bVar4) == 0)) goto switchD_6808fe50_caseD_6809081a; */
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6809061d: */
        /* FIXUP(missing paren - Ghidra artifact): pcVar11[0x16] = -(*(int *)param_5 != 0) & 0x80U | pcVar11[0x16] & 0x7fU; */
        /* FIXUP(C2059): if (param_6 == 0) goto LAB_680907d4; */
        /* FIXUP(C2143): media_writeScoreBlock(piVar10,local_58,0x16,0x80); */
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090650: */
        /* FIXUP(C2143): sVar5 = scoreEngine_getChannelCount(*(int *)(local_5c + 0x20),(short)*(undefined4 *)param_5); */
        /* FIXUP(C2143): media_readPlaybackBlockEx((int)piVar10,local_58 + 6,CONCAT22(extraout_var_01,sVar5)); */
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090672: */
        /* FIXUP(C2143): iVar6 = rendering_writeSpriteData(*(uint *)(local_5c + 0x20),pcVar11); */
        /* FIXUP(C2143): playback_initSpriteRectState((int)local_64,iVar6,(undefined4 *)param_5); */
        /* FIXUP(C2143): iVar6 = local_58; */
        /* FIXUP(C2059): if (param_6 == 0) goto LAB_680907d4; */
        /* FIXUP(C2143): media_copyScoreData(piVar10,local_58,0xc,4); */
        /* FIXUP(C2143): media_copyScoreData(piVar10,iVar6,0x10,4); */
        /* FIXUP(C2143): media_copyScoreData(piVar10,iVar6,0x1c,4); */
        /* FIXUP(C2143): media_copyScoreData(piVar10,iVar6,0x20,4); */
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680906c8: */
        /* FIXUP(C2143): local_60 = CONCAT22(in_FPUControlWord,uVar2); */
        /* FIXUP(C2143): local_70 = in_FPUControlWord | 0xc00; */
        /* FIXUP(C2143): local_84 = (double)(longlong)ROUND(*param_5 * 100.0); */
        /* FIXUP(C2143): xtra_skipBytes(pcVar11 + 0x1c); */
        /* FIXUP(C2059): if (param_6 == 0) goto LAB_680907d4; */
        /* FIXUP(C2143): media_copyScoreData(piVar10,local_58,0x1c,4); */
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090712: */
        local_60 = CONCAT22(in_FPUControlWord,uVar2);
        local_70 = in_FPUControlWord | 0xc00;
        local_84 = (double)(longlong)ROUND(*param_5 * 100.0);
        xtra_skipBytes(pcVar11 + 0x20);
        if (param_6 == 0) goto LAB_680907d4;
        media_copyScoreData(piVar10,local_58,0x20,4);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090759: */
        pcVar11[0x16] = -(*(int *)param_5 != 0) & 0x20U | pcVar11[0x16] & 0xdfU;
        if (param_6 == 0) goto LAB_680907d4;
        media_writeScoreBlock(piVar10,local_58,0x16,0x20);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x68090782: */
        pcVar11[0x16] = -(*(int *)param_5 != 0) & 0x40U | pcVar11[0x16] & 0xbfU;
        if (param_6 == 0) goto LAB_680907d4;
        media_writeScoreBlock(piVar10,local_58,0x16,0x40);
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x680907ab: */
        if (*(int *)param_5 == 0) {
          local_64[0x14] = local_64[0x14] | 4;
        }
        else {
          local_64[0x14] = local_64[0x14] & 0xfffffffb;
          if (*(int *)param_5 == 2) {
            local_64[0x14] = local_64[0x14] | 0x10;
          }
        }
        /* FIXUP(illegal break - outside switch/loop scope): break; */
      /* FIXUP(illegal case - Ghidra switch decompilation error): case (undefined *)0x6809081a: */
        goto switchD_6808fe50_caseD_6809081a;
      }
      if (param_6 == 0) {
LAB_680907d4:
        if (param_4 != 0x27) {
          *(undefined4 *)(local_5c + 0x180) = 1;
        }
      }
      local_94[1] = 1;
      if ((param_4 != 0x27) && ((*(int *)(local_5c + 0x16c) != 0 || (0 < (int)local_64[0x4a])))) {
        scoreEngine_setPropertyBool();
      }
    }
  }
/* FIXUP(missing brace - Ghidra artifact): switchD_6808fe50_caseD_6809081a: */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'if'): if (local_7c != 0) { */
    /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '&'): media_unlockScoreData(local_78,&local_7c,(undefined4 *)0x0); */
#endif
  return 0; /* FIXUP(STUB): zero return */
}
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'if'): if (local_ac != (int *)0x0) { */
    /* FIXUP(C2065: undeclared 'local_50'): DAT_68196374 = local_50; */
    Ordinal_2331();
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */
  /* FIXUP(missing paren - Ghidra artifact): __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return 0; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



