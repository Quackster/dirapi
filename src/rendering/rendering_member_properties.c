// Module: rendering
// Topic: Member properties, bitmap management, and image loading
// Address range: 0x680c0040 - 0x680c2C70
// Functions (32):
//   rendering_setMemberPropertyDirect
//   rendering_getMemberForeColor
//   rendering_getMemberPropertyDirect
//   rendering_getMemberBackColor
//   rendering_getMemberPropertyData
//   rendering_getMemberPropertyCount
//   rendering_getMemberPropertyState
//   rendering_getMemberPropertyEx
//   rendering_syncMemberProperty
//   rendering_processMemberProperty
//   rendering_applyMemberProperty
//   rendering_updateMemberPropertyData
//   rendering_getMemberBitmapSize
//   rendering_loadMemberImage
//   rendering_readMemberProperties
//   rendering_writeMemberProperties
//   rendering_initMemberStorage
//   rendering_getMemberPropertyInfo
//   rendering_getMemberPropertyRef
//   rendering_setMemberProperty
//   rendering_createMemberPicture
//   rendering_getMemberPropertyValue
//   rendering_setMemberPropertyValue
//   rendering_exportMemberMedia
//   rendering_getMemberPropertyBlock
//   rendering_getMemberPropertyRange
//   rendering_transferMemberBitmap
//   rendering_setMemberPropertyEx
//   rendering_loadMemberBitmap
//   rendering_importMemberMedia
//   rendering_dispatchMemberProperty
//   rendering_resolveMemberProperty

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c0040 - 0x680c05a0
// Functions (11):
//   rendering_setMemberPropertyDirect
//   rendering_getMemberForeColor
//   rendering_getMemberPropertyDirect
//   rendering_getMemberBackColor
//   rendering_getMemberPropertyData
//   rendering_getMemberPropertyCount
//   rendering_getMemberPropertyState
//   rendering_getMemberPropertyEx
//   rendering_syncMemberProperty
//   rendering_processMemberProperty
//   rendering_applyMemberProperty

// ============================================================
// Function: rendering_setMemberPropertyDirect (FUN_680c0040)
// Address: 680c0040
// Size: 129 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setMemberPropertyDirect(uint param_1)

{
  int in_EAX;
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  iVar1 = rendering_getStateFlags(in_EAX);
  if (iVar1 != 0) {
    iVar1 = Ordinal_38(*(int *)(in_EAX + 0x4c),0x15,&local_8,4);
    if (iVar1 == 0) {
      local_8 = 0x500000;
    }
    else {
      local_8 = xtra_readBE32Ptr((undefined1 *)&local_8);
    }
    local_8 = local_8 & 0xffffff;
    param_1 = param_1 << 0x18 | local_8;
    xtra_skipBytes((undefined1 *)&param_1);
    Ordinal_37((undefined4 *)(in_EAX + 0x4c),0x15,&param_1,4);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getMemberForeColor (FUN_680c00d0)
// Address: 680c00d0
// Size: 60 bytes
// Params: int param_1
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall rendering_getMemberForeColor(int param_1)

{
  int iVar1;
  uint uVar2;
  uint local_8;
  
  local_8 = 0xfb;
  uVar2 = 0xfb;
  if ((*(int *)(param_1 + 0x4c) != 0) &&
     (iVar1 = Ordinal_38(*(int *)(param_1 + 0x4c),0x15,&local_8,4), uVar2 = local_8, iVar1 != 0)) {
    uVar2 = xtra_readBE32Ptr((undefined1 *)&local_8);
    return uVar2 >> 0x18;
  }
  return uVar2;
}



// ============================================================
// Function: rendering_getMemberPropertyDirect (FUN_680c0110)
// Address: 680c0110
// Size: 129 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberPropertyDirect(uint param_1)

{
  int in_EAX;
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  iVar1 = rendering_getStateFlags(in_EAX);
  if (iVar1 != 0) {
    iVar1 = Ordinal_38(*(int *)(in_EAX + 0x4c),0x15,&local_8,4);
    if (iVar1 == 0) {
      local_8 = 0xfb000000;
    }
    else {
      local_8 = xtra_readBE32Ptr((undefined1 *)&local_8);
    }
    local_8 = local_8 & 0xff00ffff;
    param_1 = param_1 << 0x10 | local_8;
    xtra_skipBytes((undefined1 *)&param_1);
    Ordinal_37((undefined4 *)(in_EAX + 0x4c),0x15,&param_1,4);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getMemberBackColor (FUN_680c01a0)
// Address: 680c01a0
// Size: 67 bytes
// Params: int param_1
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall rendering_getMemberBackColor(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_8;
  
  local_8 = 0x50;
  if ((*(int *)(param_1 + 0x4c) != 0) &&
     (iVar1 = Ordinal_38(*(int *)(param_1 + 0x4c),0x15,&local_8,4), iVar1 != 0)) {
    uVar2 = xtra_readBE32Ptr((undefined1 *)&local_8);
    return uVar2 >> 0x10 & 0xff;
  }
  return 0x50;
}



// ============================================================
// Function: rendering_getMemberPropertyData (FUN_680c01f0)
// Address: 680c01f0
// Size: 129 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberPropertyData(void)

{
  int iVar1;
  int *piVar2;
  int *in_EAX;
  uint uVar3;
  int unaff_EDI;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = rendering_getMemberForeColor((int)in_EAX);
  if (uVar3 != 0xfd) {
    if (uVar3 != 0xfb) {
      return 0;
    }
    if (unaff_EDI == 0) {
      if (in_EAX == (int *)0x0) {
        return 0;
      }
      if ((int *)*in_EAX == (int *)0x0) {
        return 0;
      }
      iVar1 = *(int *)*in_EAX;
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 + 0x18);
      if (iVar1 == 0) {
        return 0;
      }
      piVar2 = *(int **)(iVar1 + 0xc);
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      local_8 = 0;
      local_1c = 0;
      Ordinal_360(piVar2,(undefined4 ***)0x0,0x20,(double *)&local_1c);
    }
    else {
      (*(unsigned char *)((char *)&local_1c + 0)) = *(char *)(unaff_EDI + 0x4aa);
    }
    if ((char)local_1c != -3) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: rendering_getMemberPropertyCount (FUN_680c0280)
// Address: 680c0280
// Size: 135 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberPropertyCount(void)

{
  int iVar1;
  short sVar2;
  undefined4 *puVar3;
  int *unaff_EDI;
  int iVar4;
  int iVar5;
  undefined2 *local_c;
  undefined4 local_8;
  
  (*(unsigned short *)((char *)&local_8 + 0)) = 0;
  sVar2 = 0;
  local_c = (undefined2 *)0x0;
  local_8 = 0;
  if (unaff_EDI == (int *)0x0) goto LAB_680c02e4;
  iVar1 = unaff_EDI[0x24];
  if (((short)iVar1 == -1) && (*(short *)((int)unaff_EDI + 0x92) < 1)) {
    sVar2 = -1;
LAB_680c02d6:
    local_8 = (uint)*(ushort *)((int)unaff_EDI + 0x92);
  }
  else {
    iVar5 = 0;
    iVar4 = 2;
    puVar3 = (undefined4 *)rendering_getChannelState(unaff_EDI);
    local_c = rendering_getChannelSlot(puVar3,iVar4,iVar5);
    sVar2 = 0;
    if (local_c != (undefined2 *)0x0) {
      sVar2 = rendering_getChannelHeight((int)local_c,(short)iVar1);
      if (sVar2 != 0) goto LAB_680c02d6;
    }
  }
LAB_680c02e4:
  if ((short)local_8 < 1) {
    (*(unsigned short *)((char *)&local_8 + 0)) = (short)local_8 + -1;
  }
  local_8 = CONCAT22((short)local_8,sVar2);
  rendering_processChannelEvent((int *)&local_c);
  return local_8;
}



// ============================================================
// Function: rendering_getMemberPropertyState (FUN_680c0310)
// Address: 680c0310
// Size: 48 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberPropertyState(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = rendering_getMemberPropertyCount();
  if ((0 < (short)uVar1) && (0 < (short)((uint)uVar1 >> 0x10))) {
    *param_2 = uVar1;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getMemberPropertyEx (FUN_680c0340)
// Address: 680c0340
// Size: 160 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberPropertyEx(int *param_1,int param_2)
{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined2 *local_8;
  
  local_8 = (undefined2 *)0x0;
  sVar1 = -2;
  if (param_2 < 0) {
    param_2 = CONCAT22((short)((uint)param_2 >> 0x10) + 1,(short)param_2);
  }
  if ((short)param_2 == -1) {
    sVar1 = -1;
    goto LAB_680c03bd;
  }
  puVar2 = (undefined4 *)rendering_getChannelState(param_1);
  local_8 = rendering_getChannelSlot(puVar2,1,0);
  if (local_8 != (undefined2 *)0x0) {
    sVar1 = rendering_getChannelHeight((int)local_8,(short)param_2);
    if (sVar1 != -2) goto LAB_680c03bd;
    uVar3 = rendering_getChannelIndex((int)puVar2,(short)param_2);
    sVar1 = (short)uVar3;
    if (sVar1 != -2) goto LAB_680c03bd;
  }
  (*(unsigned short *)((char *)&param_2 + 2)) = 0;
LAB_680c03bd:
  *(undefined2 *)((int)param_1 + 0x92) = (*(unsigned short *)((char *)&param_2 + 2));
  *(short *)(param_1 + 0x24) = sVar1;
  rendering_processChannelEvent((int *)&local_8);
  return 0;
}



// ============================================================
// Function: rendering_syncMemberProperty (FUN_680c03e0)
// Address: 680c03e0
// Size: 196 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_syncMemberProperty(void)
{
  undefined2 uVar1;
  short sVar2;
  short sVar3;
  void *in_EAX;
  undefined4 *puVar4;
  uint uVar5;
  int *unaff_EDI;
  undefined2 *local_c;
  undefined2 *local_8;
  
  local_8 = (undefined2 *)0x0;
  local_c = (undefined2 *)0x0;
  uVar1 = 0;
  local_8 = playback_buildChannelMapByType((void *)*unaff_EDI,(void *)*unaff_EDI,in_EAX,2,0);
  sVar3 = -2;
  if (local_8 != (undefined2 *)0x0) {
    puVar4 = (undefined4 *)rendering_getChannelState(unaff_EDI);
    local_c = rendering_getChannelSlot(puVar4,1,0);
    sVar3 = -2;
    if (local_c != (undefined2 *)0x0) {
      if (((short)unaff_EDI[0x24] != -1) || (sVar3 = -1, 0 < *(short *)((int)unaff_EDI + 0x92))) {
        sVar2 = rendering_getChannelHeight((int)local_8,(short)unaff_EDI[0x24]);
        sVar3 = rendering_getChannelHeight((int)local_c,sVar2);
        if ((sVar2 != 0) && (sVar3 == -2)) {
          uVar5 = rendering_getChannelIndex((int)puVar4,sVar2);
          sVar3 = (short)uVar5;
          if (sVar3 == -2) goto LAB_680c047a;
        }
      }
      uVar1 = *(undefined2 *)((int)unaff_EDI + 0x92);
    }
  }
LAB_680c047a:
  rendering_processChannelEvent((int *)&local_8);
  rendering_processChannelEvent((int *)&local_c);
  *(short *)(unaff_EDI + 0x24) = sVar3;
  *(undefined2 *)((int)unaff_EDI + 0x92) = uVar1;
  return 0;
}



// ============================================================
// Function: rendering_processMemberProperty (FUN_680c04b0)
// Address: 680c04b0
// Size: 227 bytes
// Params: int param_1, int param_2, int * param_3, int param_4, undefined4 param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
rendering_processMemberProperty(int param_1,int param_2,int *param_3,int param_4,undefined4 param_5,undefined4 *param_6
            )
{
  int *piVar1;
  int iVar2;
  int local_814 [3];
  undefined1 local_808 [2048];
  uint local_8;
  
  if (param_2 == 2) {
    piVar1 = (int *)0x1;
  }
  else if (param_2 == 4) {
    piVar1 = (int *)0x2;
  }
  else if (param_2 == 0x10) {
    piVar1 = (int *)0x4;
  }
  else {
    piVar1 = (int *)0x8;
  }
  iVar2 = rendering_processStagePalette(param_1,param_4,local_814,piVar1);
  if (iVar2 == 0) {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0;
      return 0;
    }
  }
  else {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 1;
    }
    iVar2 = media_compareScoreChannelData((int)local_808);
    if (iVar2 != 0) {
      rendering_getMemberPropertyEx(param_3,param_4);
      Ordinal_1733(param_3 + 0x16);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_applyMemberProperty (FUN_680c05a0)
// Address: 680c05a0
// Size: 184 bytes
// Params: short param_1, int * param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall rendering_applyMemberProperty(short param_1,int *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  byte *unaff_EBX;
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_c = 0;
  local_8 = rendering_getDispatchByChannel(*param_2,param_1);
  if ((local_8 != (int *)0x0) && (piVar2 = (int *)rendering_getMemberCache((int)local_8), piVar2 != (int *)0x0))
  {
    do {
      if (piVar2[2] == 4) {
        uVar1 = piVar2[0xb];
        iVar3 = rendering_getMemberData(unaff_EBX,piVar2);
        if (iVar3 != 0) {
          iVar3 = rendering_processMemberProperty((int)unaff_EBX,param_4,param_2,piVar2[1],param_3,(undefined4 *)0x0);
          if (iVar3 != 0) {
            local_c = 1;
            break;
          }
          rendering_isStateValid((int)piVar2);
          if ((uVar1 >> 9 & 1) == 0) {
            rendering_getMediaFormat(unaff_EBX,piVar2);
          }
        }
      }
      piVar2 = (int *)rendering_getMemberCache((int)local_8);
      if (piVar2 == (int *)0x0) {
        rendering_getDispatchState((int *)&local_8);
        return 0;
      }
    } while( true );
  }
  rendering_getDispatchState((int *)&local_8);
  return local_c;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c0660 - 0x680c0df0
// Functions (10):
//   rendering_updateMemberPropertyData
//   rendering_getMemberBitmapSize
//   rendering_loadMemberImage
//   rendering_readMemberProperties
//   rendering_writeMemberProperties
//   rendering_initMemberStorage
//   rendering_getMemberPropertyInfo
//   rendering_getMemberPropertyRef
//   rendering_setMemberProperty
//   rendering_createMemberPicture

// ============================================================
// Function: rendering_updateMemberPropertyData (FUN_680c0660)
// Address: 680c0660
// Size: 485 bytes
// Params: byte * param_1, int * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_updateMemberPropertyData(byte *param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 local_818;
  int local_810;
  int *local_80c;
  undefined1 local_808 [2048];
  uint local_8;
  
  local_80c = (int *)0x0;
  if (((param_1 == (byte *)0x0) || (param_2 == (int *)0x0)) || (param_2[0x16] == 0))
  goto LAB_680c07cb;
  iVar2 = Ordinal_1734(param_2[0x16]);
  iVar3 = Ordinal_1736(param_2[0x16],0,local_808,iVar2);
  if (iVar3 == 0) goto LAB_680c07cb;
  puVar6 = (undefined4 *)0x0;
  puVar5 = local_808;
  iVar3 = rendering_getMemberPropertyCount();
  iVar3 = rendering_processMemberProperty((int)param_1,iVar2,param_2,iVar3,puVar5,puVar6);
  if (iVar3 != 0) goto LAB_680c07cb;
  iVar3 = param_2[0x18];
  if (iVar3 < 1) {
LAB_680c0708:
    psVar4 = (short *)&DAT_6818e524;
  }
  else if (iVar3 < 3) {
    psVar4 = (short *)&DAT_6818e508;
  }
  else {
    if (iVar3 != 4) goto LAB_680c0708;
    psVar4 = &DAT_6818e50c;
  }
  local_818 = 0xffff;
  do {
    local_818 = CONCAT22(*psVar4,(undefined2)local_818);
    iVar3 = rendering_processMemberProperty((int)param_1,iVar2,param_2,local_818,local_808,&local_810);
    if (iVar3 != 0) goto LAB_680c07cb;
    psVar4 = psVar4 + 1;
  } while ((local_810 != 0) && (*psVar4 != 0));
  iVar3 = rendering_applyMemberProperty((short)param_2[1],param_2,local_808,iVar2);
  if ((iVar3 == 0) && (local_80c = scoreEngine_getFrameDataPtr(*(int *)(param_1 + 0x20)), local_80c != (int *)0x0))
  {
    psVar4 = (short *)scoreEngine_getFrameSize((int)local_80c);
    while ((psVar4 != (short *)0x0 &&
           ((*psVar4 == (short)param_2[1] ||
            (iVar3 = rendering_applyMemberProperty(*psVar4,param_2,local_808,iVar2), iVar3 == 0))))) {
      psVar4 = (short *)scoreEngine_getFrameSize((int)local_80c);
    }
  }
LAB_680c07cb:
  rendering_getDispatchState((int *)&local_80c);
  piVar1 = param_2 + 0x16;
  if (param_2[0x16] != 0) {
    local_810 = rendering_insertChannelEvent(*(int *)(param_1 + 0x18),param_2[1]);
    iVar2 = rendering_blitMedia(param_1,*(int *)(param_1 + 0x18),local_810,4,0,*piVar1,0,0,(int *)0x0,0);
    if (iVar2 != 0) {
      *piVar1 = 0;
      rendering_getMemberPropertyEx(param_2,local_810);
      return 0;
    }
    Ordinal_1733(piVar1);
  }
  return 0;
}



// ============================================================
// Function: rendering_getMemberBitmapSize (FUN_680c0850)
// Address: 680c0850
// Size: 35 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_getMemberBitmapSize(int param_1)

{
  uint uVar1;
  
  uVar1 = (*(int *)(param_1 + 0x6c) - *(int *)(param_1 + 100)) * *(int *)(param_1 + 0x60) + 0x1f;
  return ((int)((uVar1 & 0xffffffe0) + ((int)uVar1 >> 0x1f & 7U)) >> 3) *
         (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x68));
}



// ============================================================
// Function: rendering_loadMemberImage (FUN_680c0880)
// Address: 680c0880
// Size: 118 bytes
// Params: byte * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_loadMemberImage(byte *param_1)

{
  int *piVar1;
  int *piVar2;
  int *in_EAX;
  int iVar3;
  
  piVar1 = in_EAX + 0x15;
  piVar2 = in_EAX + 0x16;
  *piVar1 = 0;
  *piVar2 = 0;
  in_EAX[0x1d] = 0;
  in_EAX[0x1e] = 0;
  iVar3 = rendering_getFrameCount((int)in_EAX);
  if (iVar3 == 0) {
    iVar3 = Ordinal_2003(piVar2,0);
    *piVar1 = iVar3;
    if (iVar3 == 0) {
      Ordinal_1733(piVar2);
      Ordinal_1653(piVar1);
      return 0;
    }
    if (*piVar2 != 0) {
      if (*(short *)((int)in_EAX + 0x92) < 1) {
        Ordinal_1733(piVar2);
      }
      rendering_updateMemberPropertyData(param_1,in_EAX);
    }
    media_readPlaybackEntry();
  }
  return 1;
}



// ============================================================
// Function: rendering_readMemberProperties (FUN_680c0900)
// Address: 680c0900
// Size: 479 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_readMemberProperties(uint param_1)
{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 *unaff_ESI;
  
  sVar4 = Ordinal_1412();
  unaff_ESI[0x17] = (int)sVar4;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x1a] = (int)sVar4;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x19] = (int)sVar4;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x1c] = (int)sVar4;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x1b] = (int)sVar4;
  if (param_1 < 0x700) {
    Ordinal_1412();
  }
  else {
    uVar1 = Ordinal_1411();
    *(undefined1 *)(unaff_ESI + 0x26) = uVar1;
    Ordinal_1411();
  }
  uVar5 = Ordinal_1412();
  *(undefined2 *)(unaff_ESI + 0x1f) = uVar5;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x21] = (int)sVar4;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x20] = (int)sVar4;
  sVar4 = Ordinal_1412();
  unaff_ESI[0x23] = (int)sVar4 - unaff_ESI[0x1a];
  sVar4 = Ordinal_1412();
  unaff_ESI[0x22] = (int)sVar4 - unaff_ESI[0x19];
  bVar2 = Ordinal_1411();
  if ((unaff_ESI[0x17] & 0x8000) == 0) {
    unaff_ESI[0x18] = 1;
    *(undefined2 *)(unaff_ESI + 0x24) = 0xffff;
    *(undefined2 *)((int)unaff_ESI + 0x92) = 0;
  }
  else {
    unaff_ESI[0x17] = unaff_ESI[0x17] & 0x3fff;
    cVar3 = Ordinal_1410();
    iVar6 = events_setMiawBgColor();
    if (iVar6 == 0) {
      lingo_formatDebugMsg((int *)*unaff_ESI,-0x1b3);
    }
    unaff_ESI[0x18] = (int)cVar3;
    if (param_1 < 0x500) {
      *(undefined2 *)(unaff_ESI + 0x24) = 0xffff;
      uVar5 = Ordinal_1412();
      *(undefined2 *)((int)unaff_ESI + 0x92) = uVar5;
    }
    else {
      uVar5 = Ordinal_1412();
      *(undefined2 *)(unaff_ESI + 0x24) = uVar5;
      uVar5 = Ordinal_1412();
      *(undefined2 *)((int)unaff_ESI + 0x92) = uVar5;
    }
  }
  if ((bVar2 & 1) != 0) {
    unaff_ESI[0x27] = unaff_ESI[0x27] | 1;
  }
  if ((bVar2 & 2) != 0) {
    unaff_ESI[0x27] = unaff_ESI[0x27] | 2;
  }
  if ((bVar2 & 4) != 0) {
    unaff_ESI[0x27] = unaff_ESI[0x27] | 4;
  }
  if ((bVar2 & 8) != 0) {
    unaff_ESI[0x27] = unaff_ESI[0x27] | 8;
  }
  if (param_1 < 0x700) {
    if ((unaff_ESI[0xb] & 1) != 0) {
      unaff_ESI[0x27] = unaff_ESI[0x27] | 0x20;
    }
    if ((unaff_ESI[0xb] & 0x20) != 0) {
      unaff_ESI[0x27] = unaff_ESI[0x27] | 0x40;
    }
  }
  else {
    if ((bVar2 & 0x10) != 0) {
      unaff_ESI[0x27] = unaff_ESI[0x27] | 0x10;
    }
    if ((bVar2 & 0x20) != 0) {
      unaff_ESI[0x27] = unaff_ESI[0x27] | 0x20;
    }
    if ((bVar2 & 0x40) != 0) {
      unaff_ESI[0x27] = unaff_ESI[0x27] | 0x40;
    }
    if ((char)bVar2 < '\0') {
      unaff_ESI[0x27] = unaff_ESI[0x27] | 0x80;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_writeMemberProperties (FUN_680c0ae0)
// Address: 680c0ae0
// Size: 336 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeMemberProperties(void)
{
  int unaff_ESI;
  
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1422();
  Ordinal_1422();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1422();
  if ((*(int *)(unaff_ESI + 0x60) != 1) || (*(short *)(unaff_ESI + 0x92) != 0)) {
    Ordinal_1421();
    Ordinal_1423();
    Ordinal_1423();
  }
  return 0;
}



// ============================================================
// Function: rendering_initMemberStorage (FUN_680c0c30)
// Address: 680c0c30
// Size: 76 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_initMemberStorage(void)

{
  int iVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    iVar1 = Ordinal_1652(*(int *)(unaff_ESI + 0x54),0);
    *(int *)(unaff_ESI + 0x54) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (*(int *)(unaff_ESI + 0x58) != 0) {
    iVar1 = Ordinal_1732(*(int *)(unaff_ESI + 0x58));
    *(int *)(unaff_ESI + 0x58) = iVar1;
    if (iVar1 == 0) {
      Ordinal_1653((int *)(unaff_ESI + 0x54));
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: rendering_getMemberPropertyInfo (FUN_680c0c80)
// Address: 680c0c80
// Size: 67 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getMemberPropertyInfo(int param_1,int param_2)
{
  Ordinal_1653(param_1 + 0x54);
  Ordinal_1733(param_1 + 0x58);
  Ordinal_1671(param_1 + 0x74);
  if ((param_2 != 0) && (*(int *)(param_1 + 0x78) != 0)) {
    Ordinal_1671(param_1 + 0x78);
  }
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffdff;
  return 0;
}



// ============================================================
// Function: rendering_getMemberPropRefSimple (FUN_680c0cd0)
// Address: 680c0cd0
// Size: 124 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberPropRefSimple(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_2;
  if (((*(byte *)(param_2 + 0x9c) & 0x40) == 0) || (*(int *)(param_2 + 0x74) != 0)) {
    return 1;
  }
  uVar1 = lingo_isValidObject(param_1);
  param_2 = 0x1ffffff;
  uVar2 = Ordinal_1605(uVar1);
  Ordinal_1604(uVar1,*(undefined4 *)(iVar4 + 0x54));
  uVar3 = Ordinal_1670(uVar1,3,&param_2,*(undefined1 *)(iVar4 + 0x98));
  *(undefined4 *)(iVar4 + 0x74) = uVar3;
  Ordinal_1604(uVar1,uVar2);
  if ((*(int *)(iVar4 + 0x74) != 0) && (iVar4 = Ordinal_1042(), iVar4 == 0)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_setMemberProperty (FUN_680c0d50)
// Address: 680c0d50
// Size: 146 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setMemberProperty(int param_1,int param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(iVar3 + 4);
  if (*(int *)(param_2 + 0x58) != 0) {
    return 0;
  }
  piVar2 = *(int **)(param_2 + 0x60);
  if ((((((param_3 != 0) || ((*(byte *)(param_2 + 0x9c) & 2) != 0)) ||
        (*(int *)(param_1 + 0x150) != 0)) ||
       ((*(int *)(iVar3 + 0x664) != 0 || (*(int *)(iVar3 + 0x658) != 0)))) ||
      ((*(int *)(iVar3 + 0x668) != 0 || (piVar2 != *(int **)(iVar1 + 0xd8))))) &&
     (((iVar3 = rendering_getMemberPropertyCount(), piVar2 != (int *)0x8 || ((short)iVar3 != *(short *)(iVar1 + 0x54)))
      || ((short)((uint)iVar3 >> 0x10) != *(short *)(iVar1 + 0x56))))) {
    rendering_dispatchChannelOp(param_1,iVar3,piVar2);
    return 0;
  }
  uVar4 = lingo_isValidObject(iVar1);
  Ordinal_1610(uVar4);
  return 0;
}



// ============================================================
// Function: rendering_createMemberPicture (FUN_680c0df0)
// Address: 680c0df0
// Size: 134 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_createMemberPicture(void)

{
  bool bVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  undefined4 local_c;
  int local_8;
  
  bVar1 = false;
  local_8 = 0;
  local_c = 0;
  iVar2 = rendering_getMemberData(unaff_EDI,unaff_ESI);
  if (iVar2 != 0) {
    local_8 = Ordinal_1111(0,0);
    if (local_8 != 0) {
      iVar2 = Ordinal_1404(&local_c,local_8,3);
      if (iVar2 != 0) {
        iVar2 = rendering_setMemberProperty(unaff_EDI,(int)unaff_ESI,1);
        if (iVar2 != 0) {
          iVar2 = Ordinal_1660(local_c,unaff_ESI[0x15],iVar2,FOURCC_PICH,0);
          if (iVar2 != 0) {
            bVar1 = true;
          }
        }
      }
    }
    rendering_isStateValid((int)unaff_ESI);
  }
  Ordinal_1407(&local_c);
  if (!bVar1) {
    Ordinal_1113(&local_8);
  }
  return local_8;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c0e80 - 0x680c1480
// Functions (5):
//   rendering_getMemberPropertyValue
//   rendering_setMemberPropertyValue
//   rendering_exportMemberMedia
//   rendering_getMemberPropertyBlock
//   rendering_getMemberPropertyRange

// ============================================================
// Function: rendering_getMemberPropertyValue (FUN_680c0e80)
// Address: 680c0e80
// Size: 576 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getMemberPropertyValue(void)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *in_EAX;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = (uint *)in_EAX[4];
  iVar4 = in_EAX[1];
  piVar2 = (int *)*in_EAX;
  if (piVar2[2] == 1) {
    switch(in_EAX[3]) {
    case 5:
      *puVar1 = piVar2[0x19];
      puVar1[1] = piVar2[0x1a];
      puVar1[2] = piVar2[0x1b];
      puVar1[3] = piVar2[0x1c];
      Ordinal_1064(puVar1,-*puVar1,-puVar1[1]);
      return 1;
    case 0xf:
      uVar3 = rendering_createMemberPicture();
      *puVar1 = uVar3;
      if (uVar3 != 0) {
        return 1;
      }
      break;
    case 0x1f:
      uVar3 = rendering_getMemberForeColor((int)piVar2);
      *puVar1 = uVar3;
      return 1;
    case 0x20:
      uVar3 = rendering_getMemberBackColor((int)piVar2);
      *puVar1 = uVar3;
      return 1;
    case 0x2e:
      iVar5 = rendering_getMemberPropertyCount();
      uVar3 = rendering_dispatchChannelOp(iVar4,iVar5,(int *)piVar2[0x18]);
      *puVar1 = uVar3;
      Ordinal_1731(uVar3);
      return 1;
    case 0x3b:
      iVar4 = rendering_getMemberData(iVar4,piVar2);
      if (iVar4 == 0) {
        *puVar1 = 0;
        return 1;
      }
      uVar3 = Ordinal_1651(piVar2[0x15]);
      *puVar1 = uVar3;
      rendering_isStateValid((int)piVar2);
      return 1;
    case 0x3c:
      if ((*(byte *)(piVar2 + 0x27) & 0x20) == 0) {
        uVar3 = piVar2[0x22];
      }
      else {
        uVar3 = (piVar2[0x1b] - piVar2[0x19]) / 2;
      }
      *puVar1 = uVar3;
      if ((*(byte *)(piVar2 + 0x27) & 0x20) == 0) {
        puVar1[1] = piVar2[0x23];
        return 1;
      }
      puVar1[1] = (piVar2[0x1c] - piVar2[0x1a]) / 2;
      return 1;
    case 0x3d:
      *puVar1 = (uint)piVar2[0x27] >> 5 & 1;
      return 1;
    case 0x3e:
      *puVar1 = piVar2[0x20];
      puVar1[1] = piVar2[0x21];
      return 1;
    case 0x3f:
      *puVar1 = piVar2[0x18];
      return 1;
    case 0x40:
      uVar3 = rendering_getMemberPropertyCount();
      *puVar1 = uVar3;
      return 1;
    case 0x41:
      puVar1[1] = (uint)piVar2[0x27] >> 1 & 1;
      *puVar1 = piVar2[0x27] & 1;
      puVar1[3] = (uint)piVar2[0x27] >> 3 & 1;
      puVar1[2] = (uint)piVar2[0x27] >> 2 & 1;
      puVar1[4] = (uint)piVar2[0x27] >> 4 & 1;
      puVar1[5] = (uint)piVar2[0x27] >> 7 & 1;
      return 1;
    case 0x42:
      *(char *)puVar1 = (char)piVar2[0x26];
      return 1;
    }
  }
  Ordinal_1130(puVar1,0x18);
  return 0;
}



// ============================================================
// Function: rendering_setMemberPropertyValue (FUN_680c1140)
// Address: 680c1140
// Size: 463 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall rendering_setMemberPropertyValue(undefined4 *param_1)

{
  byte *pbVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  byte local_8;
  
  pbVar1 = (byte *)param_1[1];
  piVar2 = (int *)*param_1;
  uVar4 = 0;
  puVar3 = (uint *)param_1[4];
  local_8 = 1;
  if (piVar2[2] == 1) {
    switch(param_1[3]) {
    case 0xf:
      rendering_processMediaBlock(pbVar1,piVar2,*puVar3,(undefined4 *)0x0);
      break;
    default:
      goto switchD_680c1175_caseD_10;
    case 0x1f:
      iVar6 = rendering_toggleStateFlag((int)piVar2,0);
      if ((iVar6 == 0) && (8 < piVar2[0x18])) {
        rendering_setMemberPropertyDirect(*puVar3);
        local_8 = 3;
      }
      break;
    case 0x20:
      iVar6 = rendering_toggleStateFlag((int)piVar2,0);
      if ((iVar6 == 0) && (8 < piVar2[0x18])) {
        rendering_getMemberPropertyDirect(*puVar3);
      }
      break;
    case 0x3b:
      rendering_setMemberMediaProperty(pbVar1,piVar2,*puVar3);
      break;
    case 0x3c:
      piVar2[0x23] = puVar3[1];
      uVar5 = *puVar3;
      piVar2[0x27] = piVar2[0x27] & 0xffffffdf;
      piVar2[0x22] = uVar5;
      break;
    case 0x3d:
      piVar2[0x27] = piVar2[0x27] ^ ((uint)(*puVar3 != 0) << 5 ^ piVar2[0x27]) & 0x20;
      break;
    case 0x3e:
      piVar2[0x21] = puVar3[1];
      piVar2[0x20] = *puVar3;
      return 1;
    case 0x40:
      local_8 = 3;
      rendering_getMemberPropertyEx(piVar2,*puVar3);
      break;
    case 0x41:
      piVar2[0x27] = piVar2[0x27] ^ ((uint)(puVar3[1] != 0) * 2 ^ piVar2[0x27]) & 2;
      uVar5 = ((uint)(*puVar3 != 0) ^ piVar2[0x27]) & 1 ^ piVar2[0x27];
      piVar2[0x27] = uVar5;
      uVar5 = ((uint)(puVar3[3] != 0) * 8 ^ uVar5) & 8 ^ uVar5;
      piVar2[0x27] = uVar5;
      uVar5 = ((uint)(puVar3[2] != 0) * 4 ^ uVar5) & 4 ^ uVar5;
      piVar2[0x27] = uVar5;
      uVar5 = ((uint)(puVar3[4] != 0) << 4 ^ uVar5) & 0x10 ^ uVar5;
      piVar2[0x27] = uVar5;
      piVar2[0x27] = ((uint)(puVar3[5] != 0) << 7 ^ uVar5) & 0x80 ^ uVar5;
      media_readPlaybackEntry();
      break;
    case 0x42:
      *(char *)(piVar2 + 0x26) = (char)*puVar3;
      Ordinal_1671(piVar2 + 0x1d);
    }
    rendering_setMemberData((int)pbVar1,piVar2,local_8);
    uVar4 = 1;
  }
switchD_680c1175_caseD_10:
  return uVar4;
}



// ============================================================
// Function: rendering_exportMemberMedia (FUN_680c1370)
// Address: 680c1370
// Size: 205 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_exportMemberMedia(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  iVar3 = *param_1;
  iVar2 = param_1[1];
  piVar1 = (int *)param_1[3];
  if (*piVar1 != 2) {
    param_1[4] = 2;
    return 0;
  }
  if (piVar1[1] != 6) {
    param_1[4] = 3;
    return 0;
  }
  if (*(int *)(iVar3 + 0x60) == 2) {
    local_c = rendering_setMemberProperty(iVar2,iVar3,1);
    local_8 = *(int *)(*(int *)(iVar2 + 0x20) + 4);
    iVar2 = rendering_dispatchChannelOp(iVar2,*(int *)(local_8 + 0x54),(int *)0x8);
    local_10 = media_readPlaybackField(local_c,iVar2,local_8,*(undefined4 *)(iVar3 + 0x54),8,0);
    iVar3 = Ordinal_1668(local_10,iVar2);
    piVar1[2] = iVar3;
    Ordinal_1653(&local_10);
  }
  else {
    uVar4 = rendering_setMemberProperty(iVar2,iVar3,1);
    iVar3 = Ordinal_1668(*(undefined4 *)(iVar3 + 0x54),uVar4);
    piVar1[2] = iVar3;
  }
  param_1[4] = 0;
  piVar1[4] = 0;
  piVar1[3] = 1;
  return 1;
}



// ============================================================
// Function: rendering_getMemberPropertyBlock (FUN_680c1440)
// Address: 680c1440
// Size: 59 bytes
// Params: void * this, byte * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_getMemberPropertyBlock(void *this,byte *param_1)
{
  int iVar1;
  int in_EAX;
  uint uVar2;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  *(int *)((int)this + 0x60) = iVar1;
  uVar2 = (*(int *)((int)this + 0x6c) - *(int *)((int)this + 100)) * iVar1 + 0xf;
  *(int *)((int)this + 0x5c) = (int)((uVar2 & 0xfffffff0) + ((int)uVar2 >> 0x1f & 7U)) >> 3;
  rendering_updateMemberPropertyData(param_1,this);
  media_readPlaybackEntry();
  return 0;
}



// ============================================================
// Function: rendering_getMemberPropertyRange (FUN_680c1480)
// Address: 680c1480
// Size: 1336 bytes
// Params: byte * param_1, int param_2, undefined4 * param_3, int param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __fastcall
rendering_getMemberPropertyRange(byte *param_1,int param_2,undefined4 *param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_105c;
  int local_1054;
  int *local_1044;
  int local_1034;
  int local_1030;
  undefined4 local_102c;
  undefined4 local_1028;
  undefined4 local_1024;
  int *local_1020;
  undefined4 local_101c;
  undefined4 local_1018;
  undefined4 local_1014;
  undefined4 local_1010;
  undefined4 local_100c;
  undefined1 local_1008 [2048];
  undefined1 local_808 [1000];
  undefined4 local_420 [262];
  uint local_8;
  
  local_105c = param_6;
  iVar12 = *(int *)(*(int *)(param_1 + 0x20) + 4);
  local_1054 = -0x7b;
  bVar13 = false;
  bVar4 = false;
  if ((param_3[2] == 1) || (param_3[2] == 0xd)) {
    iVar11 = rendering_setMemberProperty((int)param_1,(int)param_3,1);
    if (iVar11 != 0) {
      local_1044 = (int *)param_3[0x18];
      iVar9 = param_3[0x1c];
      iVar1 = param_3[0x1a];
      uVar5 = (param_3[0x1b] - param_3[0x19]) * (int)local_1044 + 0xf;
      iVar6 = rendering_getFrameCount((int)param_3);
      if (iVar6 == 0) {
        bVar13 = param_6 != FOURCC_BITD;
        bVar3 = false;
      }
      else {
        rendering_dispatchUpdate(*(int *)(param_1 + 0x20),param_3,local_420,0);
        local_105c = Ordinal_1330(local_420);
        bVar3 = false;
      }
LAB_680c15c2:
      if (param_4 == 0) {
        uVar8 = Ordinal_1650(local_1044,0,0,0,0,0);
        param_3[0x15] = uVar8;
      }
      else {
        if ((iVar6 != 0) || (bVar13)) {
          puVar7 = param_3 + 0x16;
        }
        else {
          puVar7 = (undefined4 *)0x0;
        }
        uVar8 = Ordinal_1658(param_4,param_2,local_105c,0,iVar11,puVar7,
                             param_3[0x1b] - param_3[0x19],param_3[0x1c] - param_3[0x1a],local_1044,
                             param_2 !=
                             ((int)((uVar5 & 0xfffffff0) + ((int)uVar5 >> 0x1f & 7U)) >> 3) *
                             (iVar9 - iVar1),0);
        param_3[0x15] = uVar8;
        if (param_5 != 0) {
          Ordinal_1687(uVar8,param_5);
        }
      }
      uVar8 = Ordinal_1042();
      switch(uVar8) {
      case 0x68:
      case 0x6b:
        rendering_initMemberSlot(param_3,-0x76);
        break;
      case 0x6c:
        local_1054 = 0;
        break;
      case 0x73:
        if ((param_3[0x15] != 0) || (bVar3)) break;
        local_1044 = *(int **)(iVar12 + 0xd8);
        iVar11 = 0;
        bVar3 = true;
        if ((8 < (int)local_1044) ||
           (iVar11 = rendering_dispatchChannelOp((int)param_1,*(int *)(iVar12 + 0x54),local_1044), iVar11 != 0))
        goto LAB_680c15c2;
        goto LAB_680c1959;
      }
      if (param_3[0x15] == 0) goto LAB_680c1959;
      bVar3 = false;
      if ((iVar6 == 0) && (!bVar13)) goto LAB_680c193d;
      local_1034 = 0;
      local_1030 = 0;
      local_102c = 0;
      local_1028 = 0;
      local_1024 = 0;
      local_1020 = (int *)0x0;
      local_101c = 0;
      local_1018 = 0;
      local_1014 = 0;
      local_1010 = 0;
      local_100c = 0;
      iVar9 = Ordinal_1656(param_3[0x15],&local_1034);
      if (iVar9 == 0) goto LAB_680c1959;
      iVar9 = param_3[0x1a];
      iVar1 = param_3[0x19];
      Ordinal_1060(param_3 + 0x19,iVar1,iVar9,local_1030 + iVar1,local_1034 + iVar9);
      if (local_1044 == local_1020) {
        if ((param_3[0x16] == 0) || (iVar11 == 0)) goto LAB_680c18cb;
        uVar8 = Ordinal_1734(iVar11);
        iVar6 = Ordinal_1736(iVar11,0,local_1008,uVar8);
        if ((iVar6 == 0) || (iVar6 = Ordinal_1736(param_3[0x16],0,local_808,uVar8), iVar6 == 0))
        goto LAB_680c1959;
        iVar6 = media_compareScoreChannelData((int)local_808);
        if (iVar6 != 0) goto LAB_680c18c2;
      }
      iVar6 = media_readPlaybackField(param_3[0x16],iVar11,iVar12,param_3[0x15],(uint)local_1044,
                           (uint)param_3[0x27] >> 3 & 1);
      iVar10 = Ordinal_1042();
      if (iVar10 == 0x73) goto LAB_680c1831;
      goto LAB_680c18ae;
    }
  }
  else {
    local_1054 = -0x79;
  }
  goto LAB_680c1959;
  while( true ) {
    if (bVar3) goto LAB_680c1959;
    piVar2 = *(int **)(iVar12 + 0xd8);
    iVar11 = 0;
    bVar3 = true;
    if (((int)piVar2 < 9) &&
       (iVar11 = rendering_dispatchChannelOp((int)param_1,*(int *)(iVar12 + 0x54),piVar2), iVar11 == 0))
    goto LAB_680c1959;
    iVar6 = media_readPlaybackField(param_3[0x16],iVar11,iVar12,param_3[0x15],(uint)piVar2,
                         (uint)param_3[0x27] >> 3 & 1);
    iVar10 = Ordinal_1042();
    if (iVar10 != 0x73) break;
LAB_680c1831:
    if (iVar6 != 0) goto LAB_680c18b6;
  }
LAB_680c18ae:
  if (iVar6 != 0) {
LAB_680c18b6:
    Ordinal_1653(param_3 + 0x15);
    param_3[0x15] = iVar6;
LAB_680c18c2:
    Ordinal_1733(param_3 + 0x16);
LAB_680c18cb:
    if ((*(byte *)(param_3 + 0x27) & 0x80) == 0) {
      puVar7 = param_3 + 0x15;
      iVar11 = Ordinal_1663(puVar7,iVar11,0);
      if (iVar11 == 0) {
        Ordinal_1653(puVar7);
        goto LAB_680c1959;
      }
      iVar11 = Ordinal_1656(*puVar7,&local_1034);
      if (iVar11 == 0) goto LAB_680c1959;
      Ordinal_1060(param_3 + 0x19,iVar1,iVar9,local_1030 + iVar1,iVar9 + local_1034);
    }
    rendering_getMemberPropertyBlock(param_3,param_1);
LAB_680c193d:
    media_readPlaybackEntry();
    rendering_getMemberPropRefSimple(iVar12,(int)param_3);
    bVar4 = true;
  }
LAB_680c1959:
  iVar11 = Ordinal_1042();
  if ((iVar11 != 0) || (!bVar4)) {
    rendering_getMemberPropertyInfo((int)param_3,1);
    iVar12 = lingo_getMovieRef(*(int *)(iVar12 + 8));
    if ((iVar12 == 0) && (local_1054 != 0)) {
      rendering_initMemberSlot(param_3,local_1054);
    }
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c19e0 - 0x680c1eb0
// Functions (3):
//   rendering_transferMemberBitmap
//   rendering_setMemberPropertyEx
//   rendering_loadMemberBitmap

// ============================================================
// Function: rendering_transferMemberBitmap (FUN_680c19e0)
// Address: 680c19e0
// Size: 248 bytes
// Params: int param_1, int param_2, int * param_3, undefined4 * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_transferMemberBitmap(int param_1,int param_2,int *param_3,undefined4 *param_4,int param_5)

{
  undefined4 *unaff_EBX;
  int iVar1;
  bool bVar2;
  int local_c;
  undefined4 local_8;
  
  bVar2 = false;
  iVar1 = 0;
  local_8 = 0;
  local_c = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_5 == 0) {
    if ((unaff_EBX[2] != 1) && (unaff_EBX[2] != 0xd)) {
      rendering_initMemberSlot(unaff_EBX,-0x79);
      return 0;
    }
    iVar1 = rendering_setMemberProperty(param_1,(int)unaff_EBX,1);
    if (iVar1 != 0) {
      local_c = unaff_EBX[0x15];
      goto LAB_680c1a60;
    }
  }
  else {
    if (unaff_EBX[2] != 1) {
      rendering_initMemberSlot(unaff_EBX,-0x79);
      goto LAB_680c1abe;
    }
    local_c = Ordinal_1688(unaff_EBX[0x15]);
    if (local_c == 0) goto LAB_680c1abe;
LAB_680c1a60:
    if (param_2 == 0) {
      iVar1 = Ordinal_1659(local_c,iVar1,FOURCC_BITD,param_4);
      if (iVar1 == -1) {
        iVar1 = 0;
      }
      if (param_3 != (int *)0x0) {
        *param_3 = iVar1;
      }
    }
    else {
      iVar1 = Ordinal_1660(param_2,local_c,iVar1,FOURCC_BITD,*param_4);
      bVar2 = iVar1 == 0;
    }
    iVar1 = Ordinal_1042();
    if ((iVar1 == 0) && (!bVar2)) {
      local_8 = 1;
      goto LAB_680c1abe;
    }
  }
  rendering_initMemberSlot(unaff_EBX,-0x7c);
LAB_680c1abe:
  if (param_5 != 0) {
    Ordinal_1653(&local_c);
  }
  return local_8;
}



// ============================================================
// Function: rendering_setMemberPropertyEx (FUN_680c1ae0)
// Address: 680c1ae0
// Size: 969 bytes
// Params: byte * param_1, int * param_2, undefined4 * param_3, int param_4, int param_5, int param_6, uint param_7, int param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setMemberPropertyEx(byte *param_1,int *param_2,undefined4 *param_3,int param_4,int param_5,int param_6
                 ,uint param_7,int param_8)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int local_44c;
  int local_448;
  int local_444;
  undefined4 *local_440;
  byte *local_43c;
  int local_438;
  int local_434;
  int local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  int *local_420;
  int local_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_438 = param_4;
  local_43c = param_1;
  local_44c = param_5;
  local_448 = 0;
  local_434 = 0;
  local_430 = 0;
  local_42c = 0;
  local_428 = 0;
  local_424 = 0;
  local_420 = (int *)0x0;
  local_41c = 0;
  local_418 = 0;
  local_414 = 0;
  local_410 = 0;
  local_40c = 0;
  local_444 = *(int *)(*(int *)(param_1 + 0x20) + 4);
  local_440 = param_3;
  if (param_2 == (int *)0x0) goto LAB_680c1bbc;
  iVar3 = *(int *)(local_444 + 0x54);
  if (param_6 == 0) {
    rendering_clearStateFlag((int)param_2,0);
  }
  else {
    rendering_setStateFlag((int)param_2,0);
    if (param_3 != (undefined4 *)0x0) {
      rendering_getStatePair((int)param_2,param_3);
    }
  }
  if (local_438 == 0) {
    Ordinal_1130(&local_434,0x2c);
    local_420 = (int *)rendering_updateStageLayout(local_444 + 0x24);
    local_41c = 0;
  }
  else {
    iVar2 = Ordinal_1656(local_438,&local_434);
    if (iVar2 == 0) goto LAB_680c1bbc;
  }
  if ((param_7 & 1) != 0) {
    iVar2 = rendering_resolveState(*param_2,param_2[1]);
    if (((iVar2 == 0) || (*(int *)(iVar2 + 8) != 1)) || (param_8 == 0)) {
      piVar4 = *(int **)(local_444 + 0xd8);
      iVar2 = rendering_dispatchChannelOp((int)local_43c,*(int *)(local_444 + 0x54),piVar4);
    }
    else {
      piVar4 = *(int **)(iVar2 + 0x60);
      iVar2 = rendering_setMemberProperty((int)local_43c,iVar2,1);
    }
    param_3 = local_440;
    if (((local_44c != 0) || (local_420 != piVar4)) && (((int *)0x8 < piVar4 || (iVar2 != 0)))) {
      local_448 = media_readPlaybackField(local_44c,iVar2,local_444,local_438,(uint)piVar4,param_7 >> 1 & 1);
      if (local_448 == 0) goto LAB_680c1bbc;
      Ordinal_1653(&local_438);
      local_438 = local_448;
      Ordinal_1733(&local_44c);
      iVar2 = Ordinal_1656(local_438,&local_434);
      param_3 = local_440;
      if (iVar2 == 0) goto LAB_680c1bbc;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar2 = Ordinal_1314(param_3,local_408,0x3ff);
    if (iVar2 == 0) {
LAB_680c1bbc:
      Ordinal_1653(&local_448);
      return 0;
    }
    rendering_blendMediaEx(param_2,(int)local_408,0);
  }
  param_2[2] = 1;
  param_2[0x15] = local_438;
  param_2[0x16] = local_44c;
  rendering_getMemberPropertyEx(param_2,iVar3);
  param_2[0x1c] = local_434;
  param_2[0x27] = (local_41c != 0 | 2) << 4 | ~(param_7 << 5) & 0x80 | param_2[0x27] & 0xffffff20U;
  param_2[0x23] = local_434 / 2;
  param_2[0x1b] = local_430;
  *(undefined1 *)(param_2 + 0x26) = 1;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  param_2[0x22] = local_430 / 2;
  param_2[0xb] = param_2[0xb] & 0xfffffeffU | 0x200;
  if (param_3 == (undefined4 *)0x0) {
    rendering_updateMemberMedia(local_43c,param_2);
  }
  else {
    rendering_setMemberData((int)local_43c,param_2,1);
  }
  rendering_getMemberPropertyBlock(param_2,local_43c);
  if (param_6 == 0) {
    if (8 < param_2[0x18]) {
      uVar5 = 0xfb;
      goto LAB_680c1e81;
    }
  }
  else if (((param_3 != (undefined4 *)0x0) && (iVar3 = Ordinal_1377(0xe,param_3), iVar3 != 0)) &&
          (iVar3 = Ordinal_1402(&local_440,param_3,1), iVar3 != 0)) {
    bVar1 = Ordinal_1495(local_440);
    uVar5 = (uint)bVar1;
    Ordinal_1407(&local_440);
    if (100 < bVar1) {
      uVar5 = 0xfc;
    }
    rendering_setMemberPropertyDirect(0xfd);
    rendering_getMemberPropertyDirect(uVar5);
    return 0;
  }
  uVar5 = 0xfe;
LAB_680c1e81:
  rendering_setMemberPropertyDirect(uVar5);
  rendering_getMemberPropertyDirect(0x50);
  return 0;
}



// ============================================================
// Function: rendering_loadMemberBitmap (FUN_680c1eb0)
// Address: 680c1eb0
// Size: 696 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall rendering_loadMemberBitmap(byte *param_1)
{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  bool bVar4;
  int iVar5;
  int local_438;
  int local_434;
  int local_430;
  byte *local_42c;
  int local_428;
  int local_424 [2];
  undefined1 local_41c [1044];
  uint local_8;
  
  local_42c = param_1;
  if (unaff_ESI[0x15] == 0) {
    iVar3 = 0;
    rendering_setMemberProperty((int)param_1,(int)unaff_ESI,1);
    iVar2 = rendering_getFrameCount((int)unaff_ESI);
    if (iVar2 == 0) {
      local_424[0] = 0;
      local_434 = FOURCC_BITD;
      local_428 = 0;
      if (((unaff_ESI[0x18] == 0x20) && (iVar3 = rendering_getMemberPropertyData(), iVar3 != 0)) &&
         (rendering_updateMemberState(unaff_ESI,FOURCC_ALFA,&local_438,local_424,(int *)0x0), param_1 = local_42c,
         local_424[0] != 0)) {
        uVar1 = (unaff_ESI[0x1b] - unaff_ESI[0x19]) * 8 + 0xf;
        local_428 = Ordinal_1658(local_424[0],local_438,FOURCC_BITD,0,0,0,
                                 unaff_ESI[0x1b] - unaff_ESI[0x19],unaff_ESI[0x1c] - unaff_ESI[0x1a]
                                 ,8,local_438 !=
                                    ((int)((uVar1 & 0xfffffff0) + ((int)uVar1 >> 0x1f & 7U)) >> 3) *
                                    (unaff_ESI[0x1c] - unaff_ESI[0x1a]),0);
        iVar3 = Ordinal_1042();
        if (iVar3 == 0x6b) {
          Ordinal_1653(&local_428);
        }
        Ordinal_1407(local_424);
        param_1 = local_42c;
      }
      iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_BITD,&local_430,local_424,(int *)0x0);
      bVar4 = iVar3 == 1;
      if (bVar4) {
        if (local_424[0] == 0) {
          iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_ediM,&local_430,local_424,(int *)0x0);
          bVar4 = iVar3 == 1;
          local_434 = rendering_getMediaState((int)unaff_ESI);
          goto LAB_680c20e1;
        }
LAB_680c20e5:
        iVar3 = rendering_getMemberPropertyRange(param_1,local_430,unaff_ESI,local_424[0],local_428,local_434);
      }
      else {
LAB_680c20e1:
        iVar3 = 0;
        if (bVar4) goto LAB_680c20e5;
      }
      Ordinal_1653(&local_428);
    }
    else {
      local_424[1] = 0;
      memset(local_41c,0,0x414);
      local_424[0] = 0;
      iVar2 = rendering_dispatchUpdate(*(int *)(param_1 + 0x20),unaff_ESI,local_424 + 1,1);
      if (iVar2 == 0) goto LAB_680c2128;
      if (unaff_ESI[8] == 0) {
        iVar2 = Ordinal_1402(local_424,local_424 + 1,1);
LAB_680c1f7c:
        if (iVar2 != 0) goto LAB_680c1f84;
      }
      else {
        iVar2 = Ordinal_1405(local_424,unaff_ESI[8],1);
        if (iVar2 == 0) {
          Ordinal_1407(local_424);
          iVar2 = Ordinal_1405(local_424,unaff_ESI[8],1,0);
          goto LAB_680c1f7c;
        }
LAB_680c1f84:
        iVar5 = 0;
        iVar2 = 0;
        iVar3 = Ordinal_1435(local_424[0]);
        iVar3 = rendering_getMemberPropertyRange(param_1,iVar3,unaff_ESI,local_424[0],iVar2,iVar5);
      }
    }
    Ordinal_1407(local_424);
    if (iVar3 == 0) goto LAB_680c2128;
  }
  else {
    rendering_getMemberPropRefSimple(*(int *)(*(int *)(param_1 + 0x20) + 4),(int)unaff_ESI);
  }
  if (unaff_ESI[0x15] != 0) {
    unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
    return 0;
  }
LAB_680c2128:
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c2170 - 0x680c2b10
// Functions (3):
//   rendering_importMemberMedia
//   rendering_dispatchMemberProperty
//   rendering_resolveMemberProperty

// ============================================================
// Function: rendering_importMemberMedia (FUN_680c2170)
// Address: 680c2170
// Size: 945 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_importMemberMedia(void)
{
  int *this;
  int *piVar1;
  uint *puVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 extraout_var;
  int iVar6;
  undefined4 *unaff_EBX;
  uint local_74;
  int *local_6c;
  int *local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  byte *local_58;
  int local_54;
  int *local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_58 = (byte *)unaff_EBX[1];
  local_4c = 0;
  local_54 = 0;
  this = (int *)*unaff_EBX;
  piVar1 = (int *)unaff_EBX[3];
  local_48 = 0;
  iVar6 = *(int *)(*(int *)(local_58 + 0x20) + 4);
  local_64 = 0;
  local_74 = 0;
  local_60 = 0;
  local_68 = (int *)0x0;
  local_6c = (int *)0x0;
  local_5c = 0;
  if (*piVar1 == 2) {
    if (piVar1[1] != 6) {
      unaff_EBX[4] = 3;
      goto LAB_680c24d5;
    }
    local_4c = Ordinal_1667(piVar1[2],&local_54);
  }
  else {
    if (*piVar1 != 1) {
      unaff_EBX[4] = 2;
      goto LAB_680c24d5;
    }
    uVar4 = Ordinal_1038();
    local_68 = (int *)Ordinal_2075(uVar4);
    if ((((local_68 == (int *)0x0) ||
         (iVar5 = (**(code **)*local_68)(local_68,&DAT_68175d78,&local_6c), iVar5 != 0)) ||
        (iVar5 = rendering_replaceMediaData(local_58,this,piVar1 + 2), iVar5 == 0)) ||
       ((iVar5 = rendering_getMediaRef((int)this,piVar1[1]), iVar5 == 0 ||
        (iVar5 = Ordinal_1404(&local_5c,this[10],1), iVar5 == 0)))) goto LAB_680c24d5;
    uVar4 = Ordinal_1435(local_5c,piVar1[1],0,0,&local_54,0,0,0,0,0);
    local_4c = Ordinal_1658(local_5c,uVar4);
  }
  if (local_4c == 0) goto LAB_680c24d5;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = (int *)0x0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_50 = (int *)(piVar1[3] & 0xffff);
  if ((piVar1[3] & 0x10000U) == 0) {
    Ordinal_1663(&local_4c,local_54,&local_44);
  }
  switch ((int)(size_t)local_50) { /* FIXUP(C2050): cast non-integral switch to int */
  case (int *)0x1:
switchD_680c22f1_caseD_1:
    Ordinal_1733(this + 0x16);
    this[0x16] = local_54;
    local_54 = 0;
    goto LAB_680c23c9;
  default:
    local_50 = (int *)this[0x18];
    if (((int)local_50 < 9) && (local_60 = rendering_setMemberProperty((int)local_58,(int)this,1), local_60 == 0))
    {
LAB_680c2460:
      if ((int)local_50 < 9) goto LAB_680c2466;
    }
    break;
  case (int *)0x3:
    local_50 = *(int **)(iVar6 + 0xd8);
    if ((int)local_50 < 9) {
      local_48 = *(int *)(iVar6 + 0x54);
      goto LAB_680c2460;
    }
    break;
  case (int *)0x4:
    unaff_EBX[4] = 1;
    goto LAB_680c24d5;
  case (int *)0x5:
    puVar2 = (uint *)piVar1[4];
    if (puVar2 == (uint *)0x0) goto LAB_680c24d5;
    local_50 = (int *)*puVar2;
    if ((int)local_50 < 9) {
      if (puVar2[1] == 0) {
        local_48 = CONCAT22((short)puVar2[3],(short)puVar2[2]);
        sVar3 = scoreEngine_getChannelData(*(int *)(local_58 + 0x20),(short)puVar2[2]);
        local_48 = CONCAT22(extraout_var,sVar3);
      }
      else {
        uVar4 = cast_convertFormatCode(puVar2[1]);
        if ((short)uVar4 != -200) {
          local_48 = CONCAT22((short)uVar4,0xffff);
        }
      }
    }
    local_74 = puVar2[4];
    iVar5 = Ordinal_1656(local_4c,&local_34);
    if (iVar5 == 0) goto LAB_680c24d5;
    if (8 < (int)local_50) {
      if (local_20 != local_50) goto LAB_680c2460;
      goto switchD_680c22f1_caseD_1;
    }
LAB_680c2466:
    local_60 = rendering_dispatchChannelOp((int)local_58,local_48,local_50);
    if (local_60 == 0) goto LAB_680c24d5;
  }
  iVar6 = media_readPlaybackField(local_54,local_60,iVar6,local_4c,(uint)local_50,local_74);
  if (iVar6 != 0) {
    Ordinal_1653(&local_4c);
    local_4c = iVar6;
    Ordinal_1733(&local_54);
    if ((*(unsigned short *)((char *)&local_48 + 2)) != 0) {
      rendering_getMemberPropertyEx(this,local_48);
    }
LAB_680c23c9:
    piVar1 = this + 0x15;
    Ordinal_1653(piVar1);
    *piVar1 = local_4c;
    local_4c = 0;
    iVar6 = Ordinal_1656(*piVar1,&local_34);
    if (iVar6 != 0) {
      this[0x1c] = local_34;
      this[0x27] = this[0x27] & 0xffffffdf;
      this[0x23] = local_34 / 2;
      this[0x22] = local_30 / 2;
      this[0x1b] = local_30;
      this[0x19] = 0;
      this[0x1a] = 0;
      rendering_getMemberPropertyBlock(this,local_58);
      unaff_EBX[4] = 0;
      local_64 = 1;
    }
  }
LAB_680c24d5:
  Ordinal_1653(&local_4c);
  Ordinal_1733(&local_54);
  Ordinal_1407(&local_5c);
  if (local_68 != (int *)0x0) {
    (**(code **)(*local_68 + 8))(local_68);
  }
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))(local_6c);
  }
  return 0;
}



// ============================================================
// Function: rendering_dispatchMemberProperty (FUN_680c2540)
// Address: 680c2540
// Size: 1341 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

int * rendering_dispatchMemberProperty(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  
  piVar2 = param_1;
  piVar8 = param_1 + 2;
  piVar1 = (int *)*param_1;
  param_1 = (int *)0x0;
  switch(*piVar8) {
  case 0:
    iVar6 = rendering_setMemberPropertyEx((byte *)piVar2[1],piVar1,(undefined4 *)piVar2[5],piVar2[4],piVar2[7],
                         piVar2[6],piVar2[8],0);
    if (iVar6 == 0) {
      return param_1;
    }
    break;
  case 3:
    iVar6 = rendering_initMemberStorage();
    goto LAB_680c276a;
  case 5:
    iVar6 = rendering_loadMemberBitmap((byte *)piVar2[1]);
    goto LAB_680c276a;
  case 6:
    if (piVar2[5] == FOURCC_ALFA) {
      param_1 = (int *)0x0;
      uVar9 = (piVar1[0x1b] - piVar1[0x19]) * 8 + 0xf;
      param_1 = (int *)Ordinal_1658(piVar2[4],piVar2[6],FOURCC_BITD,0,0,0,piVar1[0x1b] - piVar1[0x19]
                                    ,piVar1[0x1c] - piVar1[0x1a],8,
                                    piVar2[6] !=
                                    ((int)((uVar9 & 0xfffffff0) + ((int)uVar9 >> 0x1f & 7U)) >> 3) *
                                    (piVar1[0x1c] - piVar1[0x1a]),0);
      if ((piVar1[0x15] != 0) && (param_1 != (int *)0x0)) {
        Ordinal_1687(piVar1[0x15],param_1);
      }
      Ordinal_1653(&param_1);
      return (int *)1;
    }
    if (piVar2[5] == FOURCC_ediM) {
      iVar6 = rendering_getMemberPropertyRange((byte *)piVar2[1],piVar2[6],piVar1,piVar2[4],0,0);
    }
    else {
      iVar6 = rendering_getMemberPropertyRange((byte *)piVar2[1],piVar2[6],piVar1,piVar2[4],0,FOURCC_BITD);
    }
    goto LAB_680c276a;
  case 7:
    if (piVar2[5] == FOURCC_BITD) {
      iVar6 = rendering_transferMemberBitmap(piVar2[1],piVar2[4],(int *)piVar2[6],(undefined4 *)piVar2[7],0);
    }
    else {
      if (piVar2[5] != FOURCC_ALFA) break;
      iVar6 = rendering_transferMemberBitmap(piVar2[1],piVar2[4],(int *)piVar2[6],(undefined4 *)piVar2[7],1);
    }
    goto LAB_680c276a;
  case 8:
    rendering_getMemberPropertyInfo((int)piVar1,piVar2[3]);
    return (int *)1;
  case 9:
    iVar10 = Ordinal_1116(piVar1[0x25]);
    iVar3 = Ordinal_1677(piVar1[0x1e]);
    iVar4 = Ordinal_1677(piVar1[0x1d]);
    iVar5 = Ordinal_1747(piVar1[0x16]);
    iVar6 = Ordinal_1662(piVar1[0x15]);
    iVar6 = iVar6 + iVar10 + iVar3 + iVar4 + iVar5;
LAB_680c2761:
    piVar2[3] = iVar6;
    break;
  case 10:
    iVar6 = rendering_getFrameCount((int)piVar1);
    if (iVar6 == 0) {
      iVar6 = rendering_getMemberBitmapSize((int)piVar1);
      piVar2[3] = iVar6;
      return (int *)1;
    }
    iVar6 = rendering_getMemberDataRef(piVar2[1],piVar1);
    piVar2[3] = iVar6;
    return (int *)1;
  case 0xb:
    uVar7 = rendering_setMemberProperty(piVar2[1],(int)piVar1,1);
    iVar6 = Ordinal_2009(piVar1[0x15],uVar7);
    goto LAB_680c276a;
  case 0xc:
    iVar6 = rendering_loadMemberImage((byte *)piVar2[1]);
    goto LAB_680c276a;
  case 0xe:
    piVar2[3] = 2;
    return (int *)1;
  case 0xf:
    piVar2[3] = 1;
    return (int *)1;
  case 0x10:
    rendering_readMemberProperties(piVar2[4]);
    return (int *)1;
  case 0x11:
    rendering_writeMemberProperties();
    return (int *)1;
  case 0x12:
    if ((piVar1[0x18] == 0x20) && (iVar6 = rendering_getMemberPropertyData(), iVar6 != 0)) {
      piVar2[3] = 2;
    }
    else {
      piVar2[3] = 1;
    }
    break;
  case 0x13:
    iVar6 = crt_negotiateFormat(piVar2 + 4,piVar2[3],FOURCC_BITD);
    piVar2[3] = iVar6;
    if ((piVar1[0x18] == 0x20) && (iVar6 = rendering_getMemberPropertyData(), iVar6 != 0)) {
      iVar6 = crt_negotiateFormat(piVar2 + 4,piVar2[3],FOURCC_ALFA);
      goto LAB_680c2761;
    }
    break;
  case 0x16:
    rendering_syncMemberProperty();
    return (int *)1;
  case 0x17:
    iVar6 = rendering_exportMemberMedia(piVar2);
    if (iVar6 == 0) {
      piVar2[4] = 6;
      return param_1;
    }
    goto LAB_680c276e;
  case 0x18:
    iVar6 = rendering_importMemberMedia();
    if (iVar6 == 0) {
      piVar2[4] = 5;
      return param_1;
    }
    goto LAB_680c276e;
  case 0x19:
    iVar6 = rendering_getMemberPropertyValue();
    if (iVar6 != 0) {
      return (int *)1;
    }
    break;
  case 0x1a:
    iVar6 = rendering_setMemberPropertyValue(piVar2);
    if (iVar6 != 0) {
      return (int *)1;
    }
    break;
  case 0x1c:
    piVar2[3] = 1;
    iVar6 = rendering_getMemberPropertyState(piVar1,&param_1);
    if ((iVar6 != 0) &&
       (piVar8 = (int *)rendering_resolveState(*(int *)(piVar2[1] + 0x18),param_1), piVar8 != (int *)0x0)) {
      uVar9 = scoreEngine_readChannelBlock(*(int **)(piVar2[1] + 0x20),piVar8,0);
      piVar2[3] = uVar9;
      return (int *)1;
    }
    goto LAB_680c276e;
  case 0x1d:
    iVar6 = piVar2[3];
    if (((((piVar1[0x17] == *(int *)(iVar6 + 0x5c)) && (piVar1[0x18] == *(int *)(iVar6 + 0x60))) &&
         ((iVar10 = Ordinal_1063(piVar1 + 0x19,iVar6 + 100), iVar10 != 0 &&
          (((short)piVar1[0x24] == *(short *)(iVar6 + 0x90) &&
           (*(short *)((int)piVar1 + 0x92) == *(short *)(iVar6 + 0x92))))))) &&
        (((*(uint *)(iVar6 + 0x9c) ^ piVar1[0x27]) & 0x20) == 0)) &&
       ((piVar1[0x25] == *(int *)(iVar6 + 0x94) &&
        (iVar6 = Ordinal_1664(piVar1[0x15],*(undefined4 *)(iVar6 + 0x54)), iVar6 != 0)))) {
      piVar2[4] = 1;
      return (int *)1;
    }
    goto LAB_680c276e;
  case 0x20:
    iVar6 = rendering_getMemberPropertyState(piVar1,&param_1);
    if (((iVar6 != 0) && (iVar6 = rendering_resolveState(*(int *)(piVar2[1] + 0x18),param_1), iVar6 != 0)) &&
       ((*(byte *)(iVar6 + 0x30) & 4) == 0)) {
      iVar6 = rendering_lookupSpriteChannel(piVar2[3],iVar6);
      piVar2[4] = iVar6;
      return (int *)1;
    }
    goto LAB_680c276e;
  }
  iVar6 = rendering_validateState(piVar2);
LAB_680c276a:
  if (iVar6 != 0) {
LAB_680c276e:
    param_1 = (int *)0x1;
  }
  return param_1;
}



// ============================================================
// Function: rendering_resolveMemberProperty (FUN_680c2b10)
// Address: 680c2b10
// Size: 349 bytes
// Params: int * param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resolveMemberProperty(int *param_1,int *param_2,int param_3,undefined4 *param_4)
{
  int *piVar1;
  int local_418;
  int local_414;
  undefined4 *local_410;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  *param_4 = 0;
  local_410 = param_4;
  piVar1 = (int *)(**(code **)(*param_1 + 0x28))(param_1,&local_418);
  if ((piVar1 == (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 0x3c))(param_1,&local_414), piVar1 == (int *)0x0)) {
    if (local_414 != local_418) goto LAB_680c2c2d;
    if (param_3 == 0) {
      *local_410 = 1;
      goto LAB_680c2c2d;
    }
    if ((param_2 == (int *)0x0) || (local_40c = (int *)*param_2, local_40c == (int *)0x0)) {
      local_40c = piVar1;
      piVar1 = (int *)(**(code **)(*param_1 + 0x44))(param_1,&local_40c);
      if (piVar1 == (int *)0x0) {
        if (local_40c == (int *)0x0) {
          return 0;
        }
        if (param_2 != (int *)0x0) {
          *param_2 = (int)local_40c;
        }
        goto LAB_680c2bdd;
      }
    }
    else {
LAB_680c2bdd:
      piVar1 = (int *)(**(code **)(*local_40c + 0x14))
                                (local_40c,9,local_408,0x400,"MIOKey_NetStreamCacheFile");
      if (piVar1 == (int *)0x8004002a) {
        piVar1 = (int *)0x800412e0;
      }
    }
    if ((local_40c != (int *)0x0) && (param_2 == (int *)0x0)) {
      (**(code **)(*local_40c + 8))(local_40c);
    }
    if (piVar1 == (int *)0x0) {
      *local_410 = 1;
      goto LAB_680c2c2d;
    }
  }
  if (piVar1 == (int *)0x800412e0) {
    return 0;
  }
LAB_680c2c2d:
  return 0;
}



