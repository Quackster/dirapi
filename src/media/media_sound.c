// Module: media
// Topic: Sound and audio operations, sprite cue points, and stream handling
// Address range: 0x680a5310 - 0x680a61f0
// Functions (11):
//   media_openSoundStream
//   media_getSoundData
//   media_writeSoundStream
//   media_delegateSoundChannel
//   media_delegateSoundPlayback
//   media_initScoreReader
//   media_destroyScoreReader
//   media_delegateSoundCallback
//   media_initCuePoint
//   media_getSoundProperty
//   media_getSoundChannelProperty

// ============================================================
// Function: media_openSoundStream (FUN_680a5310)
// Address: 680a5310
// Size: 436 bytes
// Params: int * param_1, undefined2 * param_2, undefined4 param_3, int param_4, undefined4 * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_openSoundStream(int *param_1,undefined2 *param_2,undefined4 param_3,int param_4,
                 undefined4 *param_5,undefined4 *param_6)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = *param_1;
  piVar3 = (int *)0x0;
  local_24 = 0;
  local_18 = 0;
  local_20 = (int *)0x0;
  if (iVar2 == 0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = *(int **)(iVar2 + 0x20);
  }
  iVar4 = 0;
  if ((local_1c != (int *)0x0) && (local_1c[1] != 0)) {
    if (iVar2 == 0) {
      iVar2 = *local_1c;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = iVar2;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  if (param_2 != (undefined2 *)0x0) {
    local_28 = CONCAT22(param_2[2],*param_2);
    piVar3 = (int *)scoreEngine_setChannelField((uint)local_1c,local_28);
    if ((((piVar3 != (int *)0x0) && (local_24 = rendering_getMemberData(iVar4,piVar3), local_24 != 0)) &&
        (uVar1 = rendering_getMediaState((int)piVar3), piVar3[2] == 6)) &&
       (local_18 = Ordinal_1938(uVar1,piVar3[0x15],piVar3[0x18],piVar3[0x17],FOURCC_snd),
       local_18 != 0)) {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = FOURCC_snd;
      }
      if (param_6 != (undefined4 *)0x0) {
        uVar1 = Ordinal_1116(local_18);
        *param_6 = uVar1;
      }
      if (param_4 != 0) {
        uVar1 = Ordinal_1038(&DAT_68176518,&DAT_68176538,&local_20);
        iVar2 = Ordinal_2063(uVar1);
        if ((iVar2 == 0) &&
           (iVar2 = (**(code **)(*local_20 + 0x10))(local_20,local_18,1,1,0,0,param_4), iVar2 == 0))
        {
          local_18 = 0;
        }
      }
    }
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_18 != 0) {
    Ordinal_1113(&local_18);
  }
  if (local_24 != 0) {
    rendering_isStateValid((int)piVar3);
  }
  if (local_1c != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getSoundData (FUN_680a54d0)
// Address: 680a54d0
// Size: 644 bytes
// Params: int * param_1, undefined2 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getSoundData(int *param_1,undefined2 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_44c;
  undefined4 local_444;
  int local_43c [2];
  int *local_434;
  int local_430;
  int local_42c;
  int *local_428;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar2 = *param_1;
  local_43c[1] = 0x80040014;
  local_444 = 0;
  local_430 = 0;
  local_43c[0] = 0;
  if (iVar2 == 0) {
    local_434 = (int *)0x0;
  }
  else {
    local_434 = *(int **)(iVar2 + 0x20);
  }
  piVar4 = local_434;
  iVar7 = 0;
  if ((local_434 != (int *)0x0) && (local_434[1] != 0)) {
    if (iVar2 == 0) {
      iVar2 = *local_434;
    }
    Ordinal_2330();
    local_424 = 0;
    local_428 = DAT_68196374;
    iVar7 = iVar2;
    DAT_68196374 = &local_42c;
    local_42c = iVar2;
  }
  if (param_2 != (undefined2 *)0x0) {
    local_44c = CONCAT22(param_2[2],*param_2);
    piVar1 = (int *)scoreEngine_setChannelField((uint)piVar4,local_44c);
    piVar4 = local_434;
    if (piVar1 != (int *)0x0) {
      iVar2 = rendering_getMemberData(iVar7,piVar1);
      piVar4 = local_434;
      if (iVar2 == 0) goto LAB_680a5700;
      if (piVar1[2] == 6) {
        iVar2 = rendering_getFrameCount((int)piVar1);
        if (iVar2 == 0) {
          if (piVar1[0x18] != 0) {
            puVar3 = (undefined4 *)Ordinal_1114(piVar1[0x18]);
            if (param_3 != (undefined4 *)0x0) {
              puVar6 = puVar3;
              puVar8 = param_3;
              for (iVar2 = 0x59; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
              }
            }
            iVar2 = Ordinal_2066(puVar3 + 0xd,&DAT_68175b38);
            if ((iVar2 != 0) && (local_444 = FOURCC_raw, param_5 != (undefined4 *)0x0)) {
              uVar5 = Ordinal_1112(piVar1[0x17]);
              *param_5 = uVar5;
            }
            Ordinal_1115(piVar1[0x18]);
          }
          iVar2 = Ordinal_1404(&local_430,piVar1[0x15],1);
LAB_680a568f:
          if (iVar2 == 0) goto LAB_680a56f4;
        }
        else {
          iVar2 = rendering_dispatchUpdate((int)local_434,piVar1,local_420,1);
          if (iVar2 != 0) {
            iVar2 = Ordinal_1402(&local_430,local_420,1);
            goto LAB_680a568f;
          }
        }
        piVar4 = (int *)Ordinal_1445(local_430,2);
        local_43c[0] = Ordinal_1907(local_430,local_444,param_3,param_5);
        if (param_4 != (undefined4 *)0x0) {
          uVar5 = Ordinal_1445(local_43c[0],2);
          *param_4 = uVar5;
        }
        local_43c[1] = 0;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
        }
      }
      else {
        local_43c[1] = 0x80040001;
      }
LAB_680a56f4:
      rendering_isStateValid((int)piVar1);
      piVar4 = local_434;
      goto LAB_680a5700;
    }
  }
  local_43c[1] = 0x80040001;
LAB_680a5700:
  if (local_430 != local_43c[0]) {
    Ordinal_1407(local_43c);
  }
  Ordinal_1407(&local_430);
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_428;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_writeSoundStream (FUN_680a5760)
// Address: 680a5760
// Size: 299 bytes
// Params: int * param_1, undefined2 * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeSoundStream(int *param_1,undefined2 *param_2,int *param_3)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_3;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  iVar1 = *param_1;
  local_18 = 0;
  local_38 = (int *)0x0;
  local_20 = 1;
  if (iVar1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x20);
  }
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar5 = iVar1;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (param_2 != (undefined2 *)0x0) {
    local_28 = CONCAT22(param_2[2],*param_2);
    iVar1 = scoreEngine_setChannelField((uint)piVar4,local_28);
    if (iVar1 != 0) {
      local_38 = piVar4 + 0x143;
      uVar3 = 3;
      if (piVar4[0x1a2] == 0) {
        uVar3 = local_20;
      }
      local_1c = display_writeCastMemberStream(iVar1,iVar5,&local_38,uVar3);
      if (local_1c != 0) {
        iVar1 = Ordinal_1114(local_1c);
        if (iVar1 != 0) {
          iVar5 = *local_24;
          uVar2 = Ordinal_1116(local_1c,&local_20);
          local_18 = (**(code **)(iVar5 + 0x1c))(local_24,iVar1,uVar2);
        }
        Ordinal_1113(&local_1c);
      }
      goto LAB_680a5864;
    }
  }
  local_18 = 0x80040001;
LAB_680a5864:
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_delegateSoundChannel (FUN_680a5890)
// Address: 680a5890
// Size: 138 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_delegateSoundChannel(int *param_1,int *param_2,int param_3)
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
  media_allocCastNode(iVar2,param_2,param_3);
  if (iVar2 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_delegateSoundPlayback (FUN_680a5920)
// Address: 680a5920
// Size: 131 bytes
// Params: void * this, int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_delegateSoundPlayback(void *this,int *param_1,int param_2,int param_3)
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
      this = &local_14;
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = this;
      local_14 = iVar1;
    }
  }
  media_assignCastData(this,iVar2,param_2,param_3);
  if (iVar2 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_initScoreReader (FUN_680a59b0)
// Address: 680a59b0
// Size: 71 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4, byte * param_5, int * param_6, char param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initScoreReader(int *param_1,int param_2,uint param_3,int param_4,byte *param_5,int *param_6,
                 char param_7)
{
  if (param_7 != '\0') {
    media_loadXtraBlock(param_1,param_2,1,param_3,param_4,param_5,(int *)0x0);
    return 0;
  }
  media_loadXtraBlock(param_1,param_2,0,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: media_destroyScoreReader (FUN_680a5a00)
// Address: 680a5a00
// Size: 42 bytes
// Params: int * param_1, int * param_2, char param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_destroyScoreReader(int *param_1,int *param_2,char param_3)
{
  if (param_3 != '\0') {
    media_processXtraLoadEx(param_1,param_2);
    return 0;
  }
  media_getCastMemberRef(param_1,*param_2);
  return 0;
}



// ============================================================
// Function: media_delegateSoundCallback (FUN_680a5a30)
// Address: 680a5a30
// Size: 9 bytes
// Params: uint * param_1, int param_2, int * param_3, uint param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_delegateSoundCallback(uint *param_1,int param_2,int *param_3,uint param_4,int *param_5)
{
  media_openScoreStream(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: media_initCuePoint (FUN_680a5a40)
// Address: 680a5a40
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_initCuePoint(undefined4 param_1,undefined4 *param_2)
{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0xc) = *param_2;
  if (*(short *)((int)param_2 + 2) == 0) {
    *(undefined1 *)(in_EAX + 0x10) = 0;
  }
  else {
    *(undefined1 *)(in_EAX + 0x10) = 0x1e;
    if (*(short *)(in_EAX + 0xe) < 1) {
      *(undefined2 *)(in_EAX + 0xc) = 0xffff;
    }
  }
  *(undefined2 *)(in_EAX + 0x14) = 1;
  *(undefined4 *)(in_EAX + 0x16) = 1;
  *(undefined1 *)(in_EAX + 0x1a) = 0;
  *(undefined2 *)(in_EAX + 0x11) = 0;
  *(undefined1 *)(in_EAX + 0x13) = 0;
  return 0;
}



// ============================================================
// Function: media_getSoundProperty (FUN_680a5a80)
// Address: 680a5a80
// Size: 1538 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getSoundProperty(int param_1,int param_2,int param_3,uint *param_4)
{
  int iVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined4 uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar7;
  int *local_6c;
  uint local_68;
  int local_64;
  int local_60;
  uint local_5c;
  byte local_58 [2];
  short local_56;
  int local_4c;
  char local_48;
  byte local_47;
  short local_44;
  undefined1 local_3f;
  int local_38;
  int local_14;
  int local_c;
  uint local_8;
  
  local_64 = param_1;
  iVar4 = Ordinal_402(*(int **)(param_1 + 4));
  local_6c = (int *)0x0;
  if ((param_2 != 0) && ((-(uint)(*(int *)(param_1 + 8) != 0) & 0x7ffbf43f) != 0x7ffbf43f))
  goto LAB_680a606d;
  iVar7 = 0;
  bVar2 = Ordinal_406(*(int **)(param_1 + 4),iVar4,local_58);
  if (CONCAT31(extraout_var,bVar2) == 0) goto LAB_680a606d;
  media_setScorePositionEx(*(int **)(param_1 + 4),&local_6c,(undefined4 *)0x0);
  iVar1 = *(int *)(*(int *)(*local_6c + 0x14) + 0x14);
  if (param_3 < 0x2a5) {
    if (param_3 == 0x2a4) {
      if (param_2 == 0) {
        if (local_58[0] == 0xf7) {
          local_5c = (uint)local_56;
          props_storeIntValue(iVar1,local_5c,param_4);
          goto LAB_680a606d;
        }
LAB_680a5b90:
        local_5c = 0;
        props_storeIntValue(iVar1,0,param_4);
        goto LAB_680a606d;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if (iVar7 == 0) {
        if (0x7fff < local_5c) goto LAB_680a5b6a;
        local_58[0] = 0xf7;
LAB_680a5b53:
        local_56 = (short)local_5c;
        media_setScorePosition(*(int *)(local_64 + 4),1);
        bVar3 = local_47;
      }
    }
    else {
      switch(param_3) {
      case 0x7b:
        if (param_2 == 0) {
          local_60 = local_14;
          cast_getScoreXtraData(iVar1,(short *)&local_60);
          goto LAB_680a606d;
        }
        iVar7 = cast_getXtraProperty(iVar1,param_4,&local_60);
        bVar3 = local_47;
        if (iVar7 == 0) {
          local_14 = local_60;
          if (local_c == 0) {
            media_setScorePosition(*(int *)(local_64 + 4),0);
            bVar3 = local_47;
          }
          else {
            media_readPlaybackBlockEx(*(int *)(local_64 + 4),0,local_60);
            bVar3 = local_47;
          }
        }
        break;
      default:
        goto switchD_680a5b26_caseD_7c;
      case 0x170:
        if (param_2 == 0) {
          if (local_48 < '\x01') {
            local_60 = 0;
          }
          else {
            local_60 = local_4c;
          }
          uVar5 = sprites_getPropertyId(iVar1,local_60);
          props_storeIntValue(iVar1,uVar5,param_4);
          goto LAB_680a606d;
        }
        iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
        bVar3 = local_47;
        if (iVar7 == 0) {
          local_60 = sprites_dispatchProperty(iVar1,local_5c);
          media_initCuePoint(extraout_ECX,&local_60);
          media_setScorePosition(*(int *)(local_64 + 4),5);
          bVar3 = local_47;
        }
        break;
      case 0x171:
        if (param_2 == 0) {
          local_60 = local_38;
          cast_getScoreXtraData(iVar1,(short *)&local_60);
          goto LAB_680a606d;
        }
        iVar7 = cast_getXtraProperty(iVar1,param_4,&local_60);
        bVar3 = local_47;
        if (iVar7 == 0) {
          local_38 = local_60;
          media_setScorePosition(*(int *)(local_64 + 4),2);
          bVar3 = local_47;
        }
        break;
      case 0x172:
        if (param_2 == 0) {
          if (local_58[0] == 0xf6) {
            local_5c = (uint)local_56;
            props_storeIntValue(iVar1,local_5c,param_4);
            goto LAB_680a606d;
          }
          goto LAB_680a5b90;
        }
        iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
        bVar3 = local_47;
        if (iVar7 == 0) {
          if ((int)local_5c < 0) goto LAB_680a5b6a;
          local_58[0] = 0xf6;
          goto LAB_680a5b53;
        }
      }
    }
  }
  else {
    switch(param_3) {
    case 0x2a5:
      if (param_2 == 0) {
        uVar6 = 0;
        local_5c = 0;
        if (local_58[0] == 0xf8) {
LAB_680a5d70:
          uVar6 = 1;
          local_5c = 1;
        }
LAB_680a5d78:
        props_storeIntValue(iVar1,uVar6,param_4);
        goto LAB_680a606d;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if (iVar7 == 0) {
        local_58[0] = -(local_5c != 0) & 0xf8;
        media_setScorePosition(*(int *)(local_64 + 4),1);
        bVar3 = local_47;
      }
      break;
    case 0x2a6:
      if (param_2 == 0) {
        uVar6 = 0;
        local_5c = 0;
        if (local_58[0] == 0xff) {
          local_5c = 1;
          props_storeIntValue(iVar1,1,param_4);
        }
        else {
          if (local_58[0] == 0xfe) {
            uVar6 = 2;
            local_5c = 2;
          }
          props_storeIntValue(iVar1,uVar6,param_4);
        }
        goto LAB_680a606d;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if (iVar7 == 0) {
        if (local_5c < 3) {
          local_58[0] = -(char)local_5c;
          local_56 = -2;
          media_setScorePosition(*(int *)(local_64 + 4),1);
          bVar3 = local_47;
        }
        else {
LAB_680a5b6a:
          iVar7 = -0x7ffbf828;
          bVar3 = local_47;
        }
      }
      break;
    case 0x2a7:
      if (param_2 == 0) {
        local_5c = 0;
        if ('\0' < (char)local_58[0]) {
          local_5c = (uint)(char)local_58[0];
        }
        props_storeIntValue(iVar1,local_5c,param_4);
        goto LAB_680a606d;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if (iVar7 == 0) {
        if (1000 < local_5c) goto LAB_680a5b6a;
        local_58[0] = (char)local_5c + 1;
        local_56 = -2;
        media_setScorePosition(*(int *)(local_64 + 4),1);
        bVar3 = local_47;
      }
      break;
    default:
switchD_680a5b26_caseD_7c:
      iVar7 = -0x7ffbf82b;
      bVar3 = local_47;
      break;
    case 0x2a9:
      if (param_2 == 0) {
        local_68 = 0x2ad;
        if ((local_47 & 0x40) != 0) {
          local_68 = ((int)(char)~local_47 & 0x20U | 0x55c0) >> 5;
        }
        props_storeObjectRef(iVar1,local_68,param_4);
        goto LAB_680a606d;
      }
      props_coerceAndReturnFloat(iVar1,param_4,&local_68);
      bVar3 = 0;
      if (local_68 != 0x2ad) {
        if (local_68 == 0x2ae) {
          bVar3 = 0x60;
        }
        else if (local_68 == 0x2af) {
          local_47 = 0x40;
          bVar3 = local_47;
        }
        else {
          iVar7 = -0x7ffbffff;
          bVar3 = local_47;
        }
      }
      break;
    case 0x2aa:
      if (param_2 == 0) {
        uVar6 = 0;
        local_5c = 0;
        if ((local_47 & 4) != 0) goto LAB_680a5d70;
        goto LAB_680a5d78;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if ((iVar7 == 0) && (bVar3 = local_47 & 0x20, local_5c != 0)) {
        bVar3 = local_47 & 0x20 | 4;
      }
      break;
    case 0x2ab:
      if (param_2 == 0) {
        local_5c = (uint)local_48;
        props_storeIntValue(iVar1,local_5c,param_4);
        goto LAB_680a606d;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if (iVar7 == 0) {
        if (0x3c < local_5c) goto LAB_680a5b6a;
        local_48 = (char)local_5c;
        local_3f = 0;
      }
      break;
    case 0x2ac:
      if (param_2 == 0) {
        uVar6 = 0;
        local_5c = 0;
        if ((local_47 & 4) != 0) {
          local_5c = (uint)local_44;
          props_storeIntValue(iVar1,local_5c,param_4);
          goto LAB_680a606d;
        }
        goto LAB_680a5d78;
      }
      iVar7 = props_coerceAndReturnInt(iVar1,param_4,(int *)&local_5c);
      bVar3 = local_47;
      if (iVar7 == 0) {
        bVar3 = local_47 & 0x24;
        if (((int)local_5c < 1) || (0x7fff < (int)local_5c)) {
          local_5c = 0;
          bVar3 = local_47 & 0x20;
        }
        local_44 = (short)local_5c;
      }
      break;
    case 0x2da:
      if (param_2 == 0) {
        if (local_48 < '\x01') {
          local_60 = 0;
          cast_getScoreXtraData(iVar1,(short *)&local_60);
        }
        else {
          local_60 = local_4c;
          cast_getScoreXtraData(iVar1,(short *)&local_60);
        }
        goto LAB_680a606d;
      }
      iVar7 = cast_getXtraProperty(iVar1,param_4,&local_60);
      bVar3 = local_47;
      if (iVar7 == 0) {
        media_initCuePoint(extraout_ECX_00,&local_60);
        media_setScorePosition(*(int *)(local_64 + 4),5);
        bVar3 = local_47;
      }
    }
  }
  local_47 = bVar3;
  if ((param_2 != 0) && (iVar7 == 0)) {
    Ordinal_407(*(int **)(local_64 + 4),iVar4,local_58,0);
  }
LAB_680a606d:
  return 0;
}



// ============================================================
// Function: media_getSoundChannelProperty (FUN_680a61f0)
// Address: 680a61f0
// Size: 459 bytes
// Params: int param_1, int param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getSoundChannelProperty(int param_1,int param_2,int param_3,int param_4,uint *param_5)
{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  int *local_68;
  uint local_64;
  uint *local_60;
  int local_5c;
  undefined1 local_58 [44];
  int local_2c;
  char local_28;
  int local_20;
  char local_1c;
  
  local_60 = param_5;
  iVar3 = Ordinal_402(*(int **)(param_1 + 4));
  local_68 = (int *)0x0;
  if ((param_3 == 0) || ((-(uint)(*(int *)(param_1 + 8) != 0) & 0x7ffbf43f) == 0x7ffbf43f)) {
    bVar2 = Ordinal_406(*(int **)(param_1 + 4),iVar3,local_58);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return 0;
    }
    media_setScorePositionEx(*(int **)(param_1 + 4),&local_68,(undefined4 *)0x0);
    iVar4 = *(int *)(*(int *)(*local_68 + 0x14) + 0x14);
    if (param_2 - 1U < 2) {
      if (param_4 == 0x58) {
        if (param_3 == 0) {
          cast_getScoreXtraData(iVar4,(short *)&local_5c);
          goto LAB_680a63a7;
        }
        iVar4 = cast_getXtraProperty(iVar4,local_60,&local_5c);
        cVar1 = local_1c;
        if (iVar4 == 0) {
          if (param_2 == 1) {
            local_2c = local_5c;
          }
          else {
            local_20 = local_5c;
          }
          media_setScorePosition(*(int *)(param_1 + 4),4 - (uint)(param_2 != 1));
          cVar1 = local_1c;
        }
      }
      else if (param_4 == 0x236) {
        if (param_3 == 0) {
          cVar1 = local_28;
          if (param_2 != 1) {
            cVar1 = local_1c;
          }
          local_64 = (uint)cVar1;
          props_storeIntValue(iVar4,local_64,local_60);
          goto LAB_680a63a7;
        }
        iVar4 = props_coerceAndReturnInt(iVar4,local_60,(int *)&local_64);
        cVar1 = local_1c;
        if (iVar4 == 0) {
          if (local_64 < 0x100) {
            cVar1 = (char)local_64;
            if (param_2 == 1) {
              local_28 = (char)local_64;
              cVar1 = local_1c;
            }
          }
          else {
            iVar4 = -0x7ffbf828;
          }
        }
      }
      else {
        iVar4 = -0x7ffbf82b;
        cVar1 = local_1c;
      }
      local_1c = cVar1;
      if ((param_3 != 0) && (iVar4 == 0)) {
        Ordinal_407(*(int **)(param_1 + 4),iVar3,local_58,0);
      }
    }
  }
LAB_680a63a7:
  return 0;
}
