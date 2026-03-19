// Module: score_engine
// Topic: Channel data - channel lookup, cast iteration, sprite display, score data read/write
// Address range: 0x68084bf0 - 0x680861a0
// Functions (36):
//   scoreEngine_updateMonitorRegions
//   scoreEngine_getChannelFlags
//   scoreEngine_getChannelRect
//   scoreEngine_setChannelRect
//   scoreEngine_getChannelState
//   scoreEngine_setChannelState
//   scoreEngine_readChannelWord
//   scoreEngine_getChannelType
//   scoreEngine_setChannelType
//   scoreEngine_readChannelName
//   scoreEngine_writeChannelData
//   scoreEngine_compareFrameKey
//   scoreEngine_getFrameData
//   scoreEngine_getChannelField
//   scoreEngine_findFrameByName
//   scoreEngine_getChannelRange
//   scoreEngine_setFrameName
//   scoreEngine_getChannelValue
//   scoreEngine_getFrameDataPtr
//   scoreEngine_getFrameSize
//   scoreEngine_setChannelData
//   scoreEngine_allocFrameDataPtr
//   scoreEngine_getFrameLayout
//   scoreEngine_resetChannelData
//   scoreEngine_writeScoreFile
//   scoreEngine_readScoreFile
//   scoreEngine_createNewScore
//   scoreEngine_loadScoreData
//   scoreEngine_readChannelBlock
//   scoreEngine_initChannelBlock
//   scoreEngine_getScoreLibraryId
//   scoreEngine_cleanupMembers
//   scoreEngine_getScoreFlag
//   scoreEngine_compareStrings
//   scoreEngine_importScoreData
//   scoreEngine_processMediaBlock

// ============================================================
// Function: scoreEngine_updateMonitorRegions (FUN_68084bf0)
// Address: 68084bf0
// Size: 178 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_updateMonitorRegions(int param_1)
{
  int param_4;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_38 [16];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = Ordinal_2030();
  iVar3 = *(int *)(param_1 + 4);
  if ((*(int *)(iVar3 + 0x28) != 0) && (0 < *(short *)(param_1 + 0x4b2))) {
    Ordinal_1060(local_38,*(int *)(iVar3 + 0x2c),*(int *)(iVar3 + 0x30),
                 *(int *)(iVar3 + 0x34) + *(int *)(iVar3 + 0x2c),
                 *(int *)(iVar3 + 0x38) + *(int *)(iVar3 + 0x30));
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        local_1c = 0;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_c = 0;
        iVar2 = Ordinal_2031(iVar3,&local_28);
        if ((iVar2 != 0) && (iVar2 = Ordinal_1068(&local_24,local_38), iVar2 != 0)) {
          Ordinal_2035(iVar3,(int)*(short *)(param_1 + 0x4b2));
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getChannelFlags (FUN_68084cb0)
// Address: 68084cb0
// Size: 17 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 scoreEngine_getChannelFlags(int param_1)

{
  return *(undefined2 *)(param_1 + 0x4c2);
}



// ============================================================
// Function: scoreEngine_getChannelRect (FUN_68084cd0)
// Address: 68084cd0
// Size: 57 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getChannelRect(int param_1,int *param_2)

{
  *param_2 = (int)*(short *)(param_1 + 0x492);
  param_2[1] = (int)*(short *)(param_1 + 0x490);
  param_2[2] = (int)*(short *)(param_1 + 0x496);
  param_2[3] = (int)*(short *)(param_1 + 0x494);
  return 1;
}



// ============================================================
// Function: scoreEngine_setChannelRect (FUN_68084d10)
// Address: 68084d10
// Size: 56 bytes
// Params: int param_1, undefined2 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setChannelRect(int param_1,undefined2 *param_2)
{
  *(undefined2 *)(param_1 + 0x492) = *param_2;
  *(undefined2 *)(param_1 + 0x490) = param_2[2];
  *(undefined2 *)(param_1 + 0x496) = param_2[4];
  *(undefined2 *)(param_1 + 0x494) = param_2[6];
  return 0;
}



// ============================================================
// Function: scoreEngine_getChannelState (FUN_68084d50)
// Address: 68084d50
// Size: 54 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getChannelState(int param_1)

{
  short sVar1;
  
  param_1 = *(int *)(param_1 + 0x4d8);
  sVar1 = (short)((uint)param_1 >> 0x10);
  if (sVar1 < 1) {
    param_1 = CONCAT22(sVar1 + -1,(short)param_1);
  }
  if ((short)param_1 < 1) {
    param_1 = CONCAT22((*(unsigned short *)((char *)&param_1 + 2)),0xffff);
  }
  return param_1;
}



// ============================================================
// Function: scoreEngine_setChannelState (FUN_68084d90)
// Address: 68084d90
// Size: 50 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setChannelState(int param_1,int param_2)
{
  if (param_2 < 0) {
    param_2 = CONCAT22((short)((uint)param_2 >> 0x10) + 1,(undefined2)param_2);
    *(int *)(param_1 + 0x4d8) = param_2;
    return 0;
  }
  *(int *)(param_1 + 0x4d8) = param_2;
  return 0;
}



// ============================================================
// Function: scoreEngine_readChannelWord (FUN_68084dd0)
// Address: 68084dd0
// Size: 56 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 scoreEngine_readChannelWord(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = Ordinal_38(*(int *)(param_1 + 0x46c),4,&param_1,2);
  if (iVar2 != 2) {
    return 1;
  }
  uVar1 = xtra_readBE16((undefined1 *)&param_1);
  return uVar1;
}



// ============================================================
// Function: scoreEngine_getChannelType (FUN_68084e10)
// Address: 68084e10
// Size: 17 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getChannelType(int param_1)

{
  return (int)*(char *)(param_1 + 0x4c0);
}



// ============================================================
// Function: scoreEngine_setChannelType (FUN_68084e30)
// Address: 68084e30
// Size: 19 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setChannelType(int param_1,undefined1 param_2)
{
  *(undefined1 *)(param_1 + 0x4c0) = param_2;
  return 0;
}



// ============================================================
// Function: scoreEngine_readChannelName (FUN_68084e50)
// Address: 68084e50
// Size: 192 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readChannelName(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *local_8;
  
  iVar2 = 0;
  local_8 = (undefined1 *)0x0;
  iVar4 = 0;
  local_8 = (undefined1 *)Ordinal_1126(0x400,0);
  if (local_8 != (undefined1 *)0x0) {
    local_8[1] = 0;
    *local_8 = 0;
    if (in_EAX != 0) {
      iVar2 = Ordinal_38(*(int *)(in_EAX + 0x46c),3,local_8,0x400);
      if (iVar2 == 0) goto LAB_68084efe;
    }
    uVar3 = iVar2 - 1;
    local_8[iVar2] = 0;
    if (uVar3 < 0xff) {
      *local_8 = (char)uVar3;
    }
    else {
      *local_8 = 0xff;
    }
    if (uVar3 != 0) {
      iVar4 = Ordinal_1111(0x418,0);
      if (iVar4 != 0) {
        uVar1 = Ordinal_1114(iVar4);
        iVar2 = rendering_refreshChannel(in_EAX + 0x48c);
        Ordinal_1309(uVar1,0x400,local_8 + 1,iVar2);
        Ordinal_1115(iVar4);
      }
    }
  }
LAB_68084efe:
  Ordinal_1127(&local_8);
  return iVar4;
}



// ============================================================
// Function: scoreEngine_writeChannelData (FUN_68084f10)
// Address: 68084f10
// Size: 1199 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6, int param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writeChannelData(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7)
{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_f54;
  int local_f48;
  int local_f44;
  int *local_f40;
  char *local_f3c;
  undefined1 local_f38 [1048];
  undefined1 local_b20 [1044];
  undefined1 auStack_70c [4];
  undefined1 local_708 [1024];
  undefined1 local_308 [256];
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  uint local_8;
  
  local_f48 = 0;
  local_f54 = 0;
  local_f40 = (int *)0x0;
  local_f3c = (char *)0x0;
  bVar1 = false;
  if (param_1 != 0) {
    local_f40 = *(int **)(*(int *)(param_1 + 4) + 8);
  }
  iVar3 = media_applyPixelOp(*(int *)(*local_f40 + 0xc),1,local_208,0x100);
  if (iVar3 == 0) {
    sVar2 = Ordinal_1208(local_208,"Plugin");
    if (sVar2 == 0) {
      local_f3c = (char *)0x1;
    }
    else {
      sVar2 = Ordinal_1208(local_208,"Projector");
      if (sVar2 == 0) {
        bVar1 = true;
      }
    }
  }
  if ((param_2 == 0) || (*(int *)(param_2 + 0x14) != 0)) {
    if (param_1 != 0) {
      iVar3 = param_1 + 0x28;
      if (param_7 != 0) {
        local_f48 = scoreEngine_readChannelName();
      }
      goto LAB_6808500c;
    }
  }
  else {
    local_f54 = *(int *)(param_2 + 0x30);
    iVar3 = Ordinal_1114(local_f54);
    if (param_7 != 0) {
      local_f48 = Ordinal_1112(*(undefined4 *)(param_2 + 0x34));
    }
LAB_6808500c:
    if (iVar3 != 0) {
      Ordinal_1326(local_b20,0x400,iVar3);
      iVar3 = Ordinal_1316(local_b20);
      if (iVar3 != 0) {
        Ordinal_1300(local_b20);
      }
    }
  }
  iVar3 = Ordinal_1114(local_f48);
  local_f44 = iVar3;
  if ((param_5 == 0) || (*(int *)(*local_f40 + 0x20) != 0)) {
    Ordinal_1326(local_f38,0x400,param_3);
    iVar4 = Ordinal_1307(param_3,iVar3,param_4,*(undefined4 *)(param_1 + 4));
    if ((iVar4 == 0) && (((local_f3c != (char *)0x0 || (bVar1)) && (iVar3 != 0)))) {
      local_f40 = (int *)0x0;
      iVar5 = Ordinal_1314(local_f38,local_708,0x3ff);
      if (iVar5 != 0) {
        iVar3 = Ordinal_1201(local_708);
        if ((local_f3c != (char *)0x0) &&
           (sVar2 = Ordinal_1208(auStack_70c + iVar3,&DAT_6817c72c), sVar2 == 0)) {
          local_f40 = (int *)0x1;
        }
        if (((bVar1) && (sVar2 = Ordinal_1208(auStack_70c + iVar3,&DAT_6817c724), sVar2 == 0)) ||
           (iVar3 = local_f44, local_f40 != (int *)0x0)) {
          iVar3 = local_f44;
          Ordinal_1326(local_b20,0x400,local_f44);
          if (local_f3c != (char *)0x0) {
            Ordinal_1318(local_b20,"dswMedia");
          }
          Ordinal_1318(local_b20,local_708);
          iVar4 = Ordinal_1307(local_b20,iVar3,param_4,*(undefined4 *)(param_1 + 4));
          iVar3 = local_f44;
          if (iVar4 != 0) {
            Ordinal_1326(param_3,0x400,local_b20);
            iVar3 = local_f44;
          }
        }
      }
    }
  }
  else {
    local_f3c = (char *)0x0;
    iVar4 = Ordinal_1517(DAT_681956e0,0x151b,local_108,0xff);
    if ((iVar4 != 0) && (local_f40 = (int *)Ordinal_1126(0x3ff,0), local_f40 != (int *)0x0)) {
      Ordinal_1310(param_3,local_f40,0x3ff);
      iVar5 = Ordinal_1201(local_f40,0);
      local_f3c = (char *)Ordinal_1126(iVar5 + 1 + iVar4);
      if (local_f3c != (char *)0x0) {
        Ordinal_1219(local_f3c,local_108,local_f40);
      }
    }
    iVar4 = Ordinal_1308(param_3,iVar3,param_4,local_f3c,0,*(undefined4 *)(param_1 + 4));
    Ordinal_1127(&local_f3c);
    Ordinal_1127(&local_f40);
  }
  if ((param_6 == 0) || (iVar4 != 0)) goto LAB_6808537e;
  iVar4 = Ordinal_1517(DAT_681956e0,0x151c,local_308,0xff);
  if (iVar4 == 0) {
LAB_6808531c:
    local_f3c = "File not found!";
  }
  else {
    local_f3c = (char *)Ordinal_1126(iVar4 + 0x400,0);
    local_f44 = Ordinal_1126(0x3ff,0);
    if ((local_f3c == (char *)0x0) || (local_f44 == 0)) goto LAB_6808531c;
    Ordinal_1310(param_3,local_f44,0x3ff);
    Ordinal_1219(local_f3c,local_308,local_f44);
  }
  local_108[0] = 0;
  Ordinal_1517(DAT_681956e0,0x57a,local_108,0xff);
  Ordinal_1780(local_f3c,local_108,2,1,1,1,0);
  Ordinal_1127(&local_f44);
  Ordinal_1127(&local_f3c);
LAB_6808537e:
  if (iVar3 != 0) {
    Ordinal_1115(local_f48);
  }
  Ordinal_1113(&local_f48);
  if (local_f54 != 0) {
    Ordinal_1115(local_f54);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_compareFrameKey (FUN_680853c0)
// Address: 680853c0
// Size: 50 bytes
// Params: int param_1, short * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_compareFrameKey(int param_1,short *param_2)

{
  if (*param_2 < *(short *)(param_1 + 0xc)) {
    return 1;
  }
  if (*(short *)(param_1 + 0xc) < *param_2) {
    return 0xffffffff;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getFrameData (FUN_68085400)
// Address: 68085400
// Size: 187 bytes
// Params: int param_1, short param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getFrameData(int param_1,short param_2)

{
  int local_c;
  int local_2c;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1;
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar3 = 0;
  if (*(int *)(param_1 + 0x470) == 0) {
    return 0;
  }
  if (*(short *)(param_1 + 0x47a) != param_2) {
    if ((((param_2 < 0) || (*(short *)(param_1 + 0x478) < param_2)) ||
        (iVar3 = Ordinal_1156(*(int *)(param_1 + 0x470),*(undefined4 *)(param_1 + 0x474),
                              (int)param_2), iVar3 == 0)) || (*(short *)(iVar3 + 0xc) != param_2)) {
      iVar2 = Ordinal_1165(*(undefined4 *)(iVar1 + 0x470),&param_1,&param_2,
                           *(undefined4 *)(iVar2 + 0x374),iVar2);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = Ordinal_1156(*(undefined4 *)(iVar1 + 0x470),*(undefined4 *)(iVar1 + 0x474),param_1);
    }
    *(short *)(iVar1 + 0x47a) = param_2;
    *(int *)(iVar1 + 0x47c) = iVar3;
    return iVar3;
  }
  return *(int *)(param_1 + 0x47c);
}



// ============================================================
// Function: scoreEngine_getChannelField (FUN_680854c0)
// Address: 680854c0
// Size: 91 bytes
// Params: int param_1, short param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getChannelField(int param_1,short param_2)

{
  int iVar1;
  short *psVar2;
  
  if (0x4000 < param_2) {
    iVar1 = rendering_getChannelSprite(*(int *)(*(int *)(param_1 + 4) + 8),param_2 + -0x4000);
    return iVar1;
  }
  psVar2 = (short *)scoreEngine_getFrameData(param_1,param_2);
  if (psVar2 != (short *)0x0) {
    iVar1 = rendering_getChannelSprite(*(int *)(*(int *)(param_1 + 4) + 8),*psVar2);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_findFrameByName (FUN_68085520)
// Address: 68085520
// Size: 138 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_findFrameByName(int param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 1;
  if (0 < *(short *)(param_1 + 0x478)) {
    do {
      iVar2 = Ordinal_1156(*(undefined4 *)(param_1 + 0x470),*(undefined4 *)(param_1 + 0x474),iVar4);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
        iVar3 = Ordinal_1114(*(int *)(iVar2 + 4));
        if ((iVar3 != 0) && (sVar1 = Ordinal_1208(param_2,iVar3), sVar1 == 0)) {
          Ordinal_1115(*(undefined4 *)(iVar2 + 4));
          return iVar2;
        }
        Ordinal_1115(*(undefined4 *)(iVar2 + 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(short *)(param_1 + 0x478));
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getChannelRange (FUN_680855b0)
// Address: 680855b0
// Size: 78 bytes
// Params: int param_1, short param_2, short param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint scoreEngine_getChannelRange(int param_1,short param_2,short param_3)

{
  uint uVar1;
  short *psVar2;
  ushort uVar3;
  
  uVar3 = param_3 + 1;
  uVar1 = 0xffffffff;
  if ((short)(param_3 + 1) <= *(short *)(param_1 + 0x478)) {
    while ((psVar2 = (short *)scoreEngine_getFrameData(param_1,uVar3), psVar2 == (short *)0x0 ||
           (*psVar2 != param_2))) {
      uVar3 = uVar3 + 1;
      if (*(short *)(param_1 + 0x478) < (short)uVar3) {
        return 0xffffffff;
      }
    }
    uVar1 = (uint)uVar3;
  }
  return uVar1;
}



// ============================================================
// Function: scoreEngine_setFrameName (FUN_68085600)
// Address: 68085600
// Size: 160 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_setFrameName(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined2 local_c [4];
  
  piVar2 = (int *)(param_1 + 4);
  Ordinal_1113(piVar2);
  if (0xff < param_3) {
    iVar1 = Ordinal_1285(param_2,0x100);
    if (iVar1 - param_2 <= param_3) {
      param_3 = iVar1 - param_2;
    }
  }
  iVar1 = Ordinal_1111(param_3 + 1,0);
  *piVar2 = iVar1;
  if (iVar1 != 0) {
    iVar1 = Ordinal_1114(iVar1);
    Ordinal_1203(iVar1,param_2,param_3 + 1);
    *(undefined1 *)(iVar1 + param_3) = 0;
    Ordinal_1115(*piVar2);
    local_c[0] = *(undefined2 *)(param_1 + 0xc);
    rendering_getChannelProperty(**(int **)(param_1 + 0x1c),0x1a,(undefined4 *)local_c);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getChannelValue (FUN_680856a0)
// Address: 680856a0
// Size: 262 bytes
// Params: int param_1, int param_2
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 scoreEngine_getChannelValue(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 local_2c [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  short local_c [4];
  
  *(undefined2 *)(param_2 + 0xc) = 0;
  if (*(int *)(param_1 + 0x470) == 0) {
    local_2c[0] = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    iVar2 = Ordinal_1150(1,1,0x20);
    *(int *)(param_1 + 0x470) = iVar2;
    if (iVar2 == 0) goto LAB_6808578b;
    uVar3 = Ordinal_1157(iVar2);
    *(undefined4 *)(param_1 + 0x474) = uVar3;
    scoreEngine_getChannelValue(param_1,(int)local_2c);
  }
  sVar1 = Ordinal_1154(*(undefined4 *)(param_1 + 0x470));
  *(short *)(param_2 + 0xc) = sVar1;
  *(int *)(param_2 + 0x1c) = param_1;
  Ordinal_1158(*(undefined4 *)(param_1 + 0x470),*(undefined4 *)(param_1 + 0x474));
  iVar2 = Ordinal_1151(*(undefined4 *)(param_1 + 0x470),(int)sVar1,param_2);
  if (iVar2 == 0) {
    *(undefined2 *)(param_2 + 0xc) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x478) = *(undefined2 *)(param_2 + 0xc);
    if (*(int *)(param_1 + 0x470) != 0) {
      uVar3 = Ordinal_1157(*(int *)(param_1 + 0x470));
      *(undefined4 *)(param_1 + 0x474) = uVar3;
    }
    playback_resetPaletteState();
    local_c[0] = sVar1;
    rendering_getChannelProperty(**(int **)(param_2 + 0x1c),0x18,(undefined4 *)local_c);
  }
LAB_6808578b:
  *(undefined2 *)(param_1 + 0x47a) = 0;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  return *(undefined2 *)(param_2 + 0xc);
}



// ============================================================
// Function: scoreEngine_getFrameDataPtr (FUN_680857b0)
// Address: 680857b0
// Size: 56 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * scoreEngine_getFrameDataPtr(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = Ordinal_1111(0xc,0);
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_1114(iVar1);
    *piVar2 = iVar1;
    piVar2[1] = param_1;
    piVar2[2] = 1;
    return piVar2;
  }
  return (int *)0x0;
}



// ============================================================
// Function: scoreEngine_getFrameSize (FUN_680857f0)
// Address: 680857f0
// Size: 55 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getFrameSize(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x470);
    if (iVar1 != 0) {
      iVar2 = Ordinal_1156(iVar1,*(undefined4 *)(*(int *)(param_1 + 4) + 0x474),
                           *(undefined4 *)(param_1 + 8));
      if (iVar2 != 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
    }
  }
  return iVar2;
}



// ============================================================
// Function: scoreEngine_setChannelData (FUN_68085830)
// Address: 68085830
// Size: 21 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setChannelData(int param_1,short param_2)
{
  if (param_1 != 0) {
    *(int *)(param_1 + 8) = (int)param_2;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_allocFrameDataPtr (FUN_68085850)
// Address: 68085850
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_allocFrameDataPtr(int param_1)
{
  scoreEngine_getFrameDataPtr(param_1);
  return 0;
}



// ============================================================
// Function: scoreEngine_getFrameLayout (FUN_68085860)
// Address: 68085860
// Size: 50 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getFrameLayout(int param_1)

{
  short *psVar1;
  int iVar2;
  
  psVar1 = (short *)scoreEngine_getFrameSize(param_1);
  if (psVar1 != (short *)0x0) {
    iVar2 = rendering_getChannelSprite(*(int *)(*(int *)(*(int *)(psVar1 + 0xe) + 4) + 8),*psVar1);
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_resetChannelData (FUN_680858a0)
// Address: 680858a0
// Size: 9 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resetChannelData(int param_1,short param_2)
{
  scoreEngine_setChannelData(param_1,param_2);
  return 0;
}



// ============================================================
// Function: scoreEngine_writeScoreFile (FUN_680858b0)
// Address: 680858b0
// Size: 379 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writeScoreFile(int *param_1,int *param_2,int param_3)
{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int local_30 [11];
  
  local_3c = param_1;
  local_38 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  local_30[8] = 0;
  local_30[9] = 0;
  local_34 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_40 = media_getScoreLayoutData(param_2);
  uVar3 = Ordinal_1116(param_2,1);
  local_38 = Ordinal_1111(uVar3);
  if (local_38 != 0) {
    iVar4 = Ordinal_1404(&local_34,local_38,3);
    if (iVar4 != 0) {
      Ordinal_1420(local_34,&local_58,0x14);
      Ordinal_1429(local_34,2);
      Ordinal_1429(local_34,0);
      *(undefined4 *)(param_3 + 8) = 2;
      Ordinal_1130(local_30,0x28);
      local_30[0] = param_3;
      local_30[2] = 0x11;
      local_30[3] = local_34;
      rendering_initState(local_30);
      uVar3 = Ordinal_1116(param_2);
      Ordinal_1429(local_34,1);
      Ordinal_1429(local_34,FOURCC_SCVW);
      Ordinal_1429(local_34,uVar3);
      iVar4 = media_mergeScoreEntries(param_2,local_34,(undefined4 *)0x0,(int *)0x0,0);
      piVar2 = local_3c;
      if (iVar4 != 0) {
        if ((local_40 != 0) && (local_3c != (int *)0x0)) {
          media_getPlaybackByte(*(int *)(*local_3c + 0x28),(int)param_2,local_3c[0x140],1);
          media_getScoreReadState(*(int **)(*piVar2 + 0x28),0xf);
        }
        bVar1 = true;
        goto LAB_680859ff;
      }
    }
  }
  bVar1 = false;
LAB_680859ff:
  Ordinal_1407(&local_34);
  if (!bVar1) {
    Ordinal_1113(&local_38);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_readScoreFile (FUN_68085a30)
// Address: 68085a30
// Size: 355 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readScoreFile(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_448 [20];
  undefined4 local_434;
  int local_430 [10];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_430[1] = 0;
  local_430[2] = 0;
  local_430[3] = 0;
  local_430[4] = 0;
  local_430[5] = 0;
  local_430[6] = 0;
  local_430[7] = 0;
  local_430[8] = 0;
  local_430[9] = 0;
  local_430[0] = 0;
  local_434 = 0;
  iVar1 = Ordinal_1404(&local_434,param_1,1);
  if (iVar1 != 0) {
    Ordinal_1409(local_434,local_448,0x14);
    iVar1 = Ordinal_1418(local_434);
    *(int *)(param_2 + 8) = iVar1;
    if (iVar1 == 2) {
      uVar2 = Ordinal_1419(local_434);
      iVar1 = Ordinal_1409(local_434,local_408,uVar2);
      if (iVar1 != 0) {
        local_430[0] = param_2;
        local_430[2] = 0x10;
        local_430[3] = local_434;
        rendering_initState(local_430);
        Ordinal_1418(local_434);
        Ordinal_1418(local_434);
        Ordinal_1418(local_434);
        iVar1 = Ordinal_1435(local_434);
        iVar3 = Ordinal_1433(local_434);
        media_loadScoreResource(local_434,iVar1 - iVar3,(int *)0x0,0,(short *)0x0);
      }
    }
  }
  Ordinal_1407(&local_434);
  return 0;
}



// ============================================================
// Function: scoreEngine_createNewScore (FUN_68085ba0)
// Address: 68085ba0
// Size: 163 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_createNewScore(int *param_1)
{
  int *piVar1;
  undefined1 local_b0 [8];
  undefined4 local_a8;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined2 local_44;
  uint local_8;
  
  Ordinal_1130(local_b0,0xa8);
  local_a8 = 2;
  playback_setTempo((byte *)*param_1,(int)&local_58);
  local_50 = local_50 - local_58;
  local_4c = local_4c - local_54;
  local_58 = 0;
  local_54 = 0;
  local_48 = 0xe;
  local_44 = 0;
  piVar1 = (int *)media_getVtableFunc(*(int **)(*param_1 + 0x28));
  if (piVar1 != (int *)0x0) {
    scoreEngine_writeScoreFile(param_1,piVar1,(int)local_b0);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_loadScoreData (FUN_68085c50)
// Address: 68085c50
// Size: 213 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_loadScoreData(undefined4 *param_1,undefined4 param_2)
{
  uint *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  void *this;
  int iVar5;
  undefined4 local_b0;
  undefined1 local_ac [164];
  uint local_8;
  
  local_b0 = 0;
  memset(local_ac,0,0xa4);
  iVar3 = scoreEngine_readScoreFile(param_2,(int)&local_b0);
  if (iVar3 != 0) {
    puVar1 = (uint *)*param_1;
    uVar4 = media_getScoreState((int *)puVar1[10]);
    iVar5 = 1;
    uVar2 = scoreEngine_getChannelFlags((int)param_1);
    playback_goToFrame(this,puVar1,iVar3,uVar2,iVar5);
    media_readPlaybackData(puVar1[10],uVar4,1);
    iVar3 = playback_getLifecycleData((int)puVar1);
    if ((iVar3 != 0) &&
       (*(int *)(*(int *)(puVar1[8] + 4) + 4) == *(int *)(*(int *)puVar1[6] + 0x18))) {
      rendering_getChannelProperty((int)puVar1,0xf,(undefined4 *)0x0);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_readChannelBlock (FUN_68085d30)
// Address: 68085d30
// Size: 178 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint scoreEngine_readChannelBlock(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  uVar1 = rendering_getStateCount((int)param_2);
  uVar3 = 1;
  if (uVar1 == 0) {
    iVar2 = rendering_getFrameCount((int)param_2);
    if (iVar2 == 0) {
      uVar3 = rendering_getMemberSlot(param_2);
    }
    else {
      iVar2 = rendering_updateMemberRef((int)param_1,param_2);
      uVar3 = 1;
      if ((iVar2 != 4) || ((param_2[2] == 0xf && ((param_2[0x18] & 0x4000U) != 0))))
      goto LAB_68085dc3;
      if ((param_2[8] == 0) || (param_3 != 0)) {
        rendering_compositeMedia(param_1,param_2,param_3);
      }
      if (param_2[8] == 0) {
        return 0;
      }
      if (param_2[2] == 9) {
        uVar3 = ~((uint)param_2[0xb] >> 10) & 1;
      }
      else {
        uVar3 = rendering_resolveStateMember(param_1,(int)param_2);
      }
    }
    if (uVar3 == 0) {
      return 0;
    }
  }
LAB_68085dc3:
  if (param_2[2] != 0xf) {
    return uVar3;
  }
  uVar3 = playback_getMemberInkMode(*param_1,(int)param_2);
  return uVar3;
}



// ============================================================
// Function: scoreEngine_initChannelBlock (FUN_68085df0)
// Address: 68085df0
// Size: 111 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_initChannelBlock(int *param_1,int *param_2)
{
  uint uVar1;
  int *local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  uVar1 = scoreEngine_readChannelBlock(param_1,param_2,0);
  if (uVar1 != 0) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_2c = *param_1;
    local_30 = param_2;
    local_28 = 0x1c;
    rendering_initState((int *)&local_30);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getScoreLibraryId (FUN_68085e60)
// Address: 68085e60
// Size: 39 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getScoreLibraryId(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) &&
      (piVar1 = *(int **)(*(int *)(param_1 + 4) + 8), piVar1 != (int *)0x0)) && (*piVar1 != 0)) {
    uVar2 = *(undefined4 *)(*piVar1 + 0xc);
  }
  return uVar2;
}



// ============================================================
// Function: scoreEngine_cleanupMembers (FUN_68085e90)
// Address: 68085e90
// Size: 135 bytes
// Params: undefined4 * param_1, short * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_cleanupMembers(undefined4 *param_1,short *param_2)
{
  int iVar1;
  int iVar2;
  int *local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_8;
  
  Ordinal_1130(&local_30,0x28);
  local_2c = *param_1;
  local_34 = rendering_getDispatchByChannel(*(int *)(param_1[1] + 8),*param_2);
  iVar2 = rendering_getMemberCache((int)local_34);
  iVar1 = local_30;
  while (local_30 = iVar2, local_30 != 0) {
    local_28 = 0x1f;
    rendering_initState(&local_30);
    iVar2 = rendering_getMemberCache((int)local_34);
    iVar1 = local_30;
  }
  local_30 = iVar1;
  rendering_getDispatchState((int *)&local_34);
  return 0;
}



// ============================================================
// Function: scoreEngine_getScoreFlag (FUN_68085f20)
// Address: 68085f20
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getScoreFlag(int param_1)

{
  return *(undefined4 *)(param_1 + 0x680);
}



// ============================================================
// Function: scoreEngine_compareStrings (FUN_68085f30)
// Address: 68085f30
// Size: 21 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_compareStrings(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  
  sVar1 = Ordinal_1206(param_1,param_2);
  return (int)sVar1;
}



// ============================================================
// Function: scoreEngine_importScoreData (FUN_68085f50)
// Address: 68085f50
// Size: 591 bytes
// Params: char * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_importScoreData(char *param_1)
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_950;
  int local_94c;
  uint local_948;
  char *local_944;
  undefined4 local_940;
  undefined1 local_93c [1048];
  undefined1 local_524 [1048];
  undefined2 local_10c;
  undefined1 local_10a [254];
  uint local_c;
  uint local_8;
  
  local_940 = 0;
  local_948 = 3;
  local_944 = (char *)0x0;
  local_10c = 0;
  memset(local_10a,0,0x102);
  lingo_resolveContext(&local_94c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  if (local_94c == 0) {
    local_940 = 0x800407f7;
  }
  else {
    if (*(int *)(local_94c + 0x20) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(*(int *)(local_94c + 0x20) + 4);
    }
    iVar2 = Ordinal_1313(*(int *)(iVar5 + 0x20) + 0x28);
    if (iVar2 == 4) {
      Ordinal_1130(local_93c,0x418);
      Ordinal_1326(local_93c,0x400,*(int *)(iVar5 + 0x20) + 0x28);
      Ordinal_1316(local_93c);
      uVar3 = Ordinal_1324(local_93c);
      local_944 = (char *)Ordinal_1126(uVar3,0);
      iVar2 = Ordinal_1310(local_93c,local_944,uVar3);
      if (iVar2 == 0) {
        local_940 = 0x80040014;
      }
      else {
        Ordinal_1130(local_524,0x418);
        iVar2 = Ordinal_1309(local_524,0x100,param_1,2);
        if ((iVar2 == 0) || (iVar2 = Ordinal_1313(local_524), iVar2 == 4)) {
          pcVar4 = local_944;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          Ordinal_1217(local_944,(int)pcVar4 - (int)(local_944 + 1));
          strings_loadCrossDomainPolicy(param_1,local_944,&local_948);
          Ordinal_1316(local_524);
          Ordinal_1310(local_524,&local_10c,0x100);
          Ordinal_1217(&local_10c,0x100);
          local_c = local_948;
          iVar2 = Ordinal_1168(*(undefined4 *)(iVar5 + 0x120));
          if ((iVar2 != 0) &&
             (iVar2 = Ordinal_1165(*(undefined4 *)(iVar5 + 0x120),&local_950,&local_10c,scoreEngine_compareStrings
                                   ,0), iVar2 == 0)) {
            Ordinal_1151(*(undefined4 *)(iVar5 + 0x120),local_950,&local_10c);
          }
        }
        else {
          local_940 = 0x80040001;
        }
      }
    }
    else {
      local_940 = 0;
    }
  }
  if (local_944 != (char *)0x0) {
    Ordinal_1127(&local_944);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_processMediaBlock (FUN_680861a0)
// Address: 680861a0
// Size: 89 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_processMediaBlock(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  undefined3 extraout_var;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  piVar1 = param_1;
  uVar7 = 0;
  bVar4 = scoreEngine_isScoreActive();
  piVar2 = param_2;
  if (CONCAT31(extraout_var,bVar4) == 0) {
    uVar5 = scoreEngine_readChannelBlock(piVar1,param_2,1);
    piVar3 = param_3;
    if ((uVar5 == 0) && (*param_3 == 0)) {
      iVar6 = rendering_blendMedia(piVar1,piVar2,(int *)&param_1);
      if (iVar6 == 0) {
        return 0;
      }
    }
    uVar7 = rendering_writeMediaBlock(*piVar1,piVar2,*piVar3);
  }
  return uVar7;
}



