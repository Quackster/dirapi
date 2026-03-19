// Module: bitmap
// Topic: Text drawing, bitmap blitting, cursor rendering, serialization callbacks
// Address range: 0x680e2170 - 0x680e3a00
// Functions (19):
//   bitmap_drawScrollbarRect
//   bitmap_setTextContent
//   bitmap_scaleByAspect
//   bitmap_getSpritePropertyData
//   bitmap_computeTextLayout
//   bitmap_validateAndDraw
//   bitmap_drawSelection
//   bitmap_drawFocusRing
//   bitmap_drawBackground
//   bitmap_dispatchDraw
//   bitmap_serializeSpriteName
//   bitmap_deserializeSprite
//   bitmap_saveToScore
//   bitmap_beginCapture
//   bitmap_sendSpriteData
//   bitmap_receiveSpriteData
//   bitmap_createFromDC
//   bitmap_exportLinkedMedia
//   bitmap_dispatchRenderUpdate

// ============================================================
// Function: bitmap_drawScrollbarRect (FUN_680e2170)
// Address: 680e2170
// Size: 108 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawScrollbarRect(undefined4 param_1,int param_2)
{
  int local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = *(undefined4 *)(param_2 + 200);
  local_14 = *(undefined4 *)(param_2 + 0xcc);
  local_10 = *(int *)(param_2 + 0xd0);
  local_c = *(undefined4 *)(param_2 + 0xd4);
  if (*(int *)(param_2 + 0x158) != 0) {
    Ordinal_1870(local_20);
    local_10 = local_10 - local_20[0];
  }
  Ordinal_1070(&local_18,&stack0x0000000c);
  return 0;
}



// ============================================================
// Function: bitmap_setTextContent (FUN_680e21e0)
// Address: 680e21e0
// Size: 553 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_setTextContent(int param_1,int *param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_d4;
  int local_d0 [41];
  int local_2c [9];
  uint local_8;
  
  local_d4 = param_3;
  if (((param_3 == 0) || (param_2 == (int *)0x0)) || (param_2[0x15] == 0)) goto LAB_680e23f8;
  iVar2 = Ordinal_1116(param_3);
  if (0 < iVar2) {
    iVar3 = Ordinal_1114(local_d4);
    if (*(char *)(iVar3 + -1 + iVar2) != '\0') {
      Ordinal_1115(local_d4);
      Ordinal_1117(&local_d4,iVar2 + 1,0);
      iVar3 = Ordinal_1114(local_d4);
      *(undefined1 *)(iVar3 + iVar2) = 0;
    }
    Ordinal_1115(local_d4);
  }
  uVar4 = Ordinal_1114(local_d4);
  iVar2 = Ordinal_1201(uVar4);
  iVar3 = xtra_getBufferSize(param_2[0x15]);
  if (iVar2 == iVar3) {
    iVar3 = xtra_setBufferPos(param_2[0x15],1);
    if (iVar3 != 0) {
      uVar5 = Ordinal_1114(iVar3);
      sVar1 = Ordinal_1207(uVar4,uVar5,iVar2);
      Ordinal_1115(iVar3);
      if (sVar1 != 0) goto LAB_680e22e7;
    }
    Ordinal_1115(local_d4);
  }
  else {
LAB_680e22e7:
    Ordinal_1115(local_d4);
    iVar2 = xtra_appendToBuffer(param_2[0x15],local_d0,0);
    if (iVar2 != 0) {
      xtra_readBufferValue(param_2[0x15],local_2c);
      iVar2 = Ordinal_1114(local_d4);
      iVar2 = xtra_getBufferRange(iVar2,0,local_d0,local_2c);
      Ordinal_1115(local_d4);
      if (iVar2 != 0) {
        xtra_resetBuffer(param_2[0x15]);
        param_2[0x15] = 0;
        bitmap_getTextFieldSize((int)param_2,iVar2);
        if (*(char *)((int)param_2 + 0x5b) != '\0') {
          iVar2 = lingo_isValidObject(*(int *)(*(int *)(param_1 + 0x20) + 4));
          iVar2 = xtra_drawTextLine(iVar2,param_2[0x15],0,-1);
          if ((iVar2 < param_2[0x1e]) || (iVar2 < param_2[0x19])) {
            param_2[0x19] = 0;
            xtra_isTextFormat(param_2[0x15],0);
          }
        }
        iVar2 = xtra_getBufferSize(param_2[0x15]);
        if (iVar2 < param_2[0x24]) {
          param_2[0x24] = iVar2;
        }
        bitmap_setTextSelection(param_1,param_2,(void *)param_2[0x21],(void *)param_2[0x22]);
        rendering_updateMemberMedia(param_1,param_2);
        return 0;
      }
    }
  }
LAB_680e23f8:
  return 0;
}



// ============================================================
// Function: bitmap_scaleByAspect (FUN_680e2410)
// Address: 680e2410
// Size: 119 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_scaleByAspect(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = playback_walkLifecycleChain(param_1);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 300) == 0)) {
    return param_2;
  }
  if (*(int *)(iVar1 + 0x144) < *(int *)(iVar1 + 0x14c)) {
    iVar2 = *(int *)(iVar1 + 0x14c) - *(int *)(iVar1 + 0x144);
  }
  else {
    iVar2 = 1;
  }
  if (*(int *)(iVar1 + 0x134) < *(int *)(iVar1 + 0x13c)) {
    iVar1 = *(int *)(iVar1 + 0x13c) - *(int *)(iVar1 + 0x134);
  }
  else {
    iVar1 = 1;
  }
  if (param_3 != 0) {
    return (iVar2 * param_2) / iVar1;
  }
  return (iVar1 * param_2) / iVar2;
}



// ============================================================
// Function: bitmap_getSpritePropertyData (FUN_680e2490)
// Address: 680e2490
// Size: 504 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_getSpritePropertyData(undefined4 *param_1,int param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_54;
  uint local_50;
  undefined4 local_4c;
  byte local_45;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_44 = param_3;
  local_50 = (uint)(*(ushort *)(param_1 + 3) & 0x3f);
  local_4c = 0;
  local_40 = param_2;
  iVar2 = bitmap_updateTextField(param_2,param_1[0xf]);
  if (iVar2 == 0) goto LAB_680e2660;
  bitmap_getSpriteRect(param_1,1,&local_3c);
  iVar3 = Ordinal_1602(local_44);
  if (iVar3 == 0) goto LAB_680e2660;
  local_45 = *(byte *)(param_2 + 0x7c);
  local_c = local_38;
  iVar6 = local_30 - local_38;
  local_10 = local_3c;
  iVar3 = Ordinal_1608(local_44,&local_3c);
  if (iVar3 == 0) {
LAB_680e2650:
    local_4c = 1;
  }
  else if ((local_45 == 0) ||
          ((((sVar1 = (short)local_50, sVar1 != 0 && (sVar1 != 1)) && (sVar1 != 0x24)) &&
           ((sVar1 != 8 || (*(char *)(local_40 + 0x59) == '\0')))))) {
    puVar5 = param_1 + 0x4b;
LAB_680e25a4:
    iVar2 = xtra_paintTextLayout(local_44,iVar2,&local_10,iVar6,0,(int)puVar5);
    if (iVar2 != 0) {
      local_40 = bitmap_getScaledStyleRun(local_40,param_1[0xf]);
      if (local_40 != 0) {
        iVar2 = Ordinal_1154(local_40);
        uVar4 = Ordinal_1157(local_40);
        iVar3 = 0;
        if (0 < iVar2) {
          do {
            puVar5 = (undefined4 *)Ordinal_1156(local_40,uVar4,iVar3);
            if (puVar5 != (undefined4 *)0x0) {
              local_18 = *puVar5;
              local_14 = puVar5[1];
              local_10 = puVar5[2];
              local_c = puVar5[3];
              Ordinal_1064(&local_18,local_3c,local_38);
              iVar6 = Ordinal_1621(local_44,&local_18);
              if (iVar6 == 0) {
                Ordinal_1158(local_40,uVar4);
                Ordinal_1163(&local_40);
                goto LAB_680e2657;
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar2);
        }
        Ordinal_1158(local_40,uVar4);
        Ordinal_1163(&local_40);
      }
      goto LAB_680e2650;
    }
  }
  else {
    local_54 = (uint)local_45 + local_10;
    local_50 = (uint)local_45 + local_c;
    local_2c = 2;
    local_28 = 0x100;
    local_24 = 0x1ffffff;
    iVar3 = xtra_paintTextLayout(local_44,iVar2,&local_54,iVar6,1,(int)&local_2c);
    if (iVar3 != 0) {
      local_24 = param_1[0x4d];
      puVar5 = &local_2c;
      goto LAB_680e25a4;
    }
  }
LAB_680e2657:
  Ordinal_1603(local_44);
LAB_680e2660:
  return 0;
}



// ============================================================
// Function: bitmap_computeTextLayout (FUN_680e2690)
// Address: 680e2690
// Size: 498 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_computeTextLayout(int param_1,int param_2)
{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar3 = *(int *)(param_1 + 0xcc);
  local_28 = iVar3;
  iVar4 = bitmap_scaleByAspect(*(int *)(param_1 + 0x3c),*(int *)(param_1 + 0xd4) - iVar3,1);
  *(int *)(param_1 + 0xd4) = iVar4 + iVar3;
  local_20 = (iVar4 + iVar3) - local_28;
  piVar1 = (int *)(param_1 + 200);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0xd0);
  local_30 = *piVar1;
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0xd4);
  local_1c = *(int *)(param_1 + 0xd0) - local_30;
  if (0 < *(int *)(param_2 + 0x78)) {
    local_20 = bitmap_scaleByAspect(*(int *)(param_1 + 0x3c),*(int *)(param_2 + 0x78),1);
  }
  if (*(int *)(param_2 + 8) == 3) {
    if (*(char *)(param_2 + 0x5b) == '\x01') {
      Ordinal_1870(&local_3c);
      *(undefined4 *)(param_1 + 0x160) = local_3c;
      *(undefined4 *)(param_1 + 0x158) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x158) = 0;
    }
  }
  local_1c = local_1c + *(int *)(param_1 + 0x160);
  bitmap_getTextFieldData(param_2,&local_18);
  local_24 = local_14;
  local_38 = local_10;
  local_2c = local_18;
  local_34 = local_c;
  Ordinal_1060(param_1 + 0x148,0,0,local_1c,local_20);
  Ordinal_1064(param_1 + 0x148,local_2c,local_24);
  Ordinal_1060(piVar1,0,0,local_1c + local_38 + local_2c,local_20 + local_34 + local_24);
  Ordinal_1064(param_1 + 0x148,local_30,local_28);
  Ordinal_1064(piVar1,local_30,local_28);
  *(uint *)(param_1 + 0x168) =
       ((((uint)*(byte *)(param_2 + 0x59) - (uint)*(byte *)(param_2 + 0x5a)) -
        *(int *)(param_1 + 0x160)) - local_2c) + *(int *)(param_1 + 0xd0);
  *(uint *)(param_1 + 0x16c) =
       (*(int *)(param_1 + 0xcc) - (uint)(*(byte *)(param_2 + 0x59) >> 1)) + local_24;
  bVar2 = *(byte *)(param_2 + 0x59);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0xd0) - *piVar1;
  *(uint *)(param_1 + 0x164) = (uint)bVar2 + local_20;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0xd4) - *(int *)(param_1 + 0xcc);
  Ordinal_1080(param_1 + 0xd8,piVar1);
  *(undefined4 *)(param_1 + 0x118) = 1;
  return 0;
}



// ============================================================
// Function: bitmap_validateAndDraw (FUN_680e2890)
// Address: 680e2890
// Size: 288 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_validateAndDraw(int param_1)
{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  uVar1 = *(ushort *)(unaff_ESI + 3);
  if ((((*(char *)(unaff_EDI + 0x5a) == '\0') || (iVar3 = Ordinal_1619(), iVar3 != 0)) &&
      ((((uVar1 & 0x3f) != 0 && (*(char *)(unaff_EDI + 0x58) == '\0')) ||
       (((((uVar1 & 0x3f) == 8 && (*(char *)(unaff_EDI + 0x59) == '\0')) || (param_1 == 0)) ||
        (iVar3 = Ordinal_1619(), iVar3 != 0)))))) &&
     ((*(char *)(unaff_EDI + 0x58) == '\0' || (iVar3 = Ordinal_1620(), iVar3 != 0)))) {
    bitmap_getSpritePropertyData(unaff_ESI,unaff_EDI,unaff_EBX);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_drawSelection (FUN_680e29b0)
// Address: 680e29b0
// Size: 271 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawSelection(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (param_2 == 0) {
    Ordinal_1623();
  }
  else {
    Ordinal_1622();
  }
  uVar1 = unaff_ESI[0x4c];
  uVar2 = unaff_ESI[0x4e];
  uVar3 = unaff_ESI[0x4d];
  uVar4 = unaff_ESI[0x4f];
  uVar5 = unaff_ESI[0x4b];
  unaff_ESI[0x4b] = 4;
  bitmap_getSpritePropertyData(unaff_ESI,param_1,unaff_EDI);
  unaff_ESI[0x4b] = uVar5;
  unaff_ESI[0x4c] = uVar1;
  unaff_ESI[0x4d] = uVar3;
  unaff_ESI[0x4e] = uVar2;
  unaff_ESI[0x4f] = uVar4;
  return 0;
}



// ============================================================
// Function: bitmap_drawFocusRing (FUN_680e2ac0)
// Address: 680e2ac0
// Size: 350 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawFocusRing(int param_1,int param_2,short param_3)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = unaff_ESI[0x33];
  iVar2 = unaff_ESI[0x32];
  if (param_2 != 0) {
    Ordinal_1619();
  }
  local_10 = iVar2 + 0xc;
  local_14 = iVar1 + 2;
  local_c = iVar1 + 0xe;
  local_18 = iVar2;
  Ordinal_1620();
  if ((*(uint *)(param_1 + 0x2c) & 0x100) != 0) {
    if (param_3 == 0) {
      Ordinal_1623();
      Ordinal_1623();
    }
    else if (param_3 == 1) {
      Ordinal_1065(&local_18,2,2);
      Ordinal_1619();
    }
    else if (param_3 == 2) {
      Ordinal_1619();
    }
  }
  bitmap_getSpritePropertyData(unaff_ESI,param_1,unaff_EDI);
  return 0;
}



// ============================================================
// Function: bitmap_drawBackground (FUN_680e2c20)
// Address: 680e2c20
// Size: 233 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawBackground(int param_1,int param_2)
{
  int local_18;
  uint uVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (param_2 != 0) {
    Ordinal_1619();
  }
  Ordinal_1623();
  if ((*(uint *)(param_1 + 0x2c) & 0x100) != 0) {
    Ordinal_1622();
  }
  bitmap_getSpritePropertyData(unaff_ESI,param_1,unaff_EDI);
  return 0;
}



// ============================================================
// Function: bitmap_dispatchDraw (FUN_680e2d10)
// Address: 680e2d10
// Size: 469 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_dispatchDraw(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int local_38;
  undefined4 local_28;
  undefined4 local_24;
  int local_18 [4];
  uint local_8;
  
  local_38 = 0;
  piVar3 = (int *)playback_getSpriteData(param_1,param_3);
  if ((piVar3 == (int *)0x0) ||
     (((piVar3[2] != 3 && (piVar3[2] != 7)) || (iVar4 = rendering_getMemberData(param_1,piVar3), iVar4 == 0))))
  goto LAB_680e2ebd;
  local_38 = Ordinal_1602(param_2);
  if (local_38 != 0) {
    switch(*(ushort *)(param_3 + 3) & 0x3f) {
    case 0:
    case 4:
    case 8:
    case 9:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x25:
    case 0x26:
    case 0x27:
      iVar4 = (int)piVar3 + 0x5e;
      break;
    default:
      iVar4 = 0;
    }
    uVar5 = playback_getSpriteProperty(param_1,param_3);
    switch(uVar5) {
    case 7:
      iVar4 = bitmap_validateAndDraw(iVar4);
      break;
    case 8:
      iVar4 = bitmap_drawSelection((int)piVar3,iVar4);
      break;
    case 9:
      sVar2 = scoreEngine_getCastDirtyFlag(*(int *)(param_1 + 0x20));
      iVar4 = bitmap_drawFocusRing((int)piVar3,iVar4,sVar2);
      break;
    case 10:
      iVar4 = bitmap_drawBackground((int)piVar3,iVar4);
      break;
    default:
      goto switchD_680e2db1_default;
    }
    if (iVar4 != 0) {
switchD_680e2db1_default:
      iVar4 = *(int *)(param_1 + 0x20);
      if (((*(int *)(iVar4 + 0x638) != 0) && (*(int *)(iVar4 + 0x644) == param_3[0x10])) &&
         ((*(int *)(iVar4 + 0x640) == param_3[0xf] &&
          (iVar1 = *(int *)(*(int *)(iVar4 + 4) + 0x28), iVar1 != 0)))) {
        if (*(int *)(iVar4 + 0x63c) == 0) {
LAB_680e2e9f:
          piVar7 = (int *)0x0;
        }
        else {
          bitmap_getSpriteRect(param_3,0,&local_28);
          iVar4 = piVar3[0x24];
          piVar7 = local_18;
          piVar6 = (int *)bitmap_updateTextField((int)piVar3,param_3[0xf]);
          iVar4 = xtra_processTextRun(param_2,piVar6,iVar4,piVar7);
          if (iVar4 == 0) goto LAB_680e2e9f;
          Ordinal_1064(local_18,local_28,local_24);
          iVar4 = Ordinal_1066(local_18,local_18,&local_28);
          if (iVar4 == 0) goto LAB_680e2e9f;
          piVar7 = local_18;
        }
        Ordinal_1839(iVar1,piVar7);
        *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x638) = 0;
      }
    }
  }
  rendering_isStateValid((int)piVar3);
LAB_680e2ebd:
  rendering_releaseMemberData(piVar3);
  if (local_38 != 0) {
    Ordinal_1603(param_2);
  }
  return 0;
}



// ============================================================
// Function: bitmap_serializeSpriteName (FUN_680e2f30)
// Address: 680e2f30
// Size: 367 bytes
// Params: undefined4 param_1, short param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_serializeSpriteName(undefined4 param_1,short param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  undefined2 local_408;
  uint local_8;
  
  iVar1 = rendering_getChannelSprite(param_3,param_2);
  if (*(int *)(iVar1 + 0x14) == 0) {
    uVar2 = Ordinal_1114(*(undefined4 *)(iVar1 + 0x30));
    Ordinal_1310(uVar2,&local_408,0x3ff);
    Ordinal_1115(*(undefined4 *)(iVar1 + 0x30));
    Ordinal_1233(&local_408,&local_408);
  }
  else {
    scoreEngine_getChannelRange(*(int *)(iVar1 + 0x1c),param_2,0);
    local_408 = 0;
  }
  Ordinal_1420();
  if ((char)local_408 == -1) {
    Ordinal_1201((int)&local_408 + 1);
  }
  Ordinal_1420();
  Ordinal_1433();
  Ordinal_1432();
  iVar3 = rendering_getChannelLock(iVar1);
  if (iVar3 != 0) {
    iVar1 = rendering_getChannelLock(iVar1);
    iVar1 = rendering_writeChannelScoreData(param_3,unaff_ESI,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  Ordinal_1433();
  Ordinal_1432();
  Ordinal_1420();
  Ordinal_1432();
  return 0;
}



// ============================================================
// Function: bitmap_deserializeSprite (FUN_680e30a0)
// Address: 680e30a0
// Size: 585 bytes
// Params: void * this, int * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_deserializeSprite(void *this,int *param_1)
{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  char *pcVar6;
  int unaff_EDI;
  short local_834;
  int local_830;
  undefined4 local_820 [262];
  byte local_408;
  undefined1 local_407 [255];
  char local_308 [768];
  uint local_8;
  
  iVar3 = Ordinal_1409();
  if (iVar3 == 0) {
    return 0;
  }
  bVar1 = Ordinal_1411();
  uVar5 = (uint)bVar1;
  iVar3 = Ordinal_1409();
  if (iVar3 == 0) {
    return 0;
  }
  if (uVar5 == 0xff) {
    pcVar6 = local_308;
    do {
      cVar2 = Ordinal_1411();
      *pcVar6 = cVar2;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
  }
  else {
    Ordinal_1411();
  }
  local_407[uVar5] = 0;
  local_408 = bVar1;
  if (0xfe < uVar5) {
    local_408 = 0xff;
  }
  if (local_834 == 0) {
    Ordinal_1232(&local_408,&local_408);
    Ordinal_1309(local_820,0x400,&local_408,2);
    piVar4 = (int *)rendering_getChannelRect((int)param_1,local_820);
    if (piVar4 == (int *)0x0) {
      iVar3 = scoreEngine_writeChannelData((int)this,0,local_820,0x16,1,1,1);
      if ((iVar3 == 0) ||
         (piVar4 = (int *)rendering_getChannelDataEx((int)param_1,1,local_820,0), piVar4 == (int *)0x0))
      goto LAB_680e32aa;
      iVar3 = playback_loadMediaData(this,piVar4,(void *)0x2);
      if ((iVar3 != 1) || (iVar3 = rendering_writeChannelBlock(piVar4,this,(void *)0x0), iVar3 == 0))
      goto LAB_680e3293;
    }
LAB_680e3225:
    iVar3 = Ordinal_1409();
    if (iVar3 != 0) {
      if (local_830 == 0) {
        rendering_getChannelSize((short)piVar4[1]);
      }
      else {
        iVar3 = rendering_refreshChannel((int)(piVar4 + 0x1a));
        *(undefined2 *)(piVar4 + 0x28) = 2;
        playback_importChannelSprites(param_1,unaff_EDI,local_830,(uint)*(ushort *)(piVar4 + 1),this,(void *)0x0);
        *(short *)(piVar4 + 0x28) = (short)iVar3;
      }
    }
  }
  else {
    piVar4 = (int *)scoreEngine_getChannelField((int)this,local_834);
    if (piVar4 == (int *)0x0) goto LAB_680e32aa;
    if (piVar4[5] != 0) {
      rendering_addChannelSpriteRef((int)param_1,(short)piVar4[1]);
      goto LAB_680e3225;
    }
  }
LAB_680e3293:
  if (piVar4 != (int *)0x0) {
    rendering_setChannelProperty(param_1,(uint)*(ushort *)(piVar4 + 1),0);
  }
LAB_680e32aa:
  return 0;
}



// ============================================================
// Function: bitmap_saveToScore (FUN_680e32f0)
// Address: 680e32f0
// Size: 134 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_saveToScore(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  undefined4 local_8;
  
  iVar3 = 0;
  local_8 = 0;
  pcVar1 = *(code **)(**(int **)(*unaff_ESI + 4) + 0x188);
  if ((pcVar1 != (code *)0x0) && (*(int *)(**(int **)(*unaff_ESI + 4) + 0x18c) != 0)) {
    iVar3 = (*pcVar1)(unaff_ESI[1],unaff_ESI[0x11],&local_8);
  }
  iVar2 = Ordinal_1444(param_1,iVar3);
  if (iVar2 != 0) {
    if (iVar3 == 0) {
      return 1;
    }
    iVar3 = (**(code **)(**(int **)(*unaff_ESI + 4) + 0x18c))
                      (unaff_ESI[1],param_1,unaff_ESI[0x11],iVar3,local_8);
    if (iVar3 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_beginCapture (FUN_680e3380)
// Address: 680e3380
// Size: 68 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_beginCapture(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  
  iVar2 = Ordinal_1442();
  if (iVar2 == 0) {
    unaff_ESI[0x11] = 0;
    return 1;
  }
  pcVar1 = *(code **)(**(int **)(*unaff_ESI + 4) + 400);
  if (pcVar1 == (code *)0x0) {
    uVar3 = Ordinal_1432();
    unaff_ESI[0x11] = 0;
    return uVar3;
  }
  iVar2 = (*pcVar1)();
  unaff_ESI[0x11] = iVar2;
  return 1;
}



// ============================================================
// Function: bitmap_sendSpriteData (FUN_680e33d0)
// Address: 680e33d0
// Size: 652 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_sendSpriteData(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_EBX;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b4;
  int local_b0 [21];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_10;
  uint local_8;
  
  iVar6 = 0;
  local_bc = 0;
  local_b4 = 0;
  local_b8 = 0;
  local_bc = Ordinal_1111(0xa8,0);
  iVar1 = Ordinal_1404(&local_b4,local_bc,2);
  if (iVar1 == 0) goto LAB_680e361f;
  iVar6 = Ordinal_1042();
  uVar2 = rendering_updateMemberRef(param_1,unaff_EBX);
  Ordinal_1443(local_b4,unaff_EBX[2]);
  Ordinal_1443(local_b4,unaff_EBX[4]);
  Ordinal_1443(local_b4,uVar2);
  Ordinal_1443(local_b4,(uint)unaff_EBX[0xb] >> 9 & 1);
  Ordinal_1443(local_b4,(uint)unaff_EBX[0xb] >> 8 & 1);
  iVar1 = unaff_EBX[2];
  piVar5 = unaff_EBX;
  piVar7 = local_b0;
  for (iVar4 = 0x2a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar7 = piVar7 + 1;
  }
  switch(iVar1) {
  case 1:
  case 0xd:
    local_3c = 0;
    local_1c = 0;
    goto LAB_680e34fe;
  case 2:
  case 4:
  case 5:
    local_5c = 0;
    break;
  case 3:
  case 7:
    local_24 = 0;
    local_1c = 0;
    goto LAB_680e3504;
  case 6:
    local_54 = 0;
    local_50 = 0;
    goto LAB_680e3504;
  case 9:
    local_40 = 0;
    goto LAB_680e3504;
  case 10:
    local_48 = 0;
    break;
  case 0xc:
    local_24 = 0;
    local_20 = 0;
    local_10 = 0;
    break;
  case 0xe:
  case 0xf:
    local_34 = 0;
LAB_680e34fe:
    local_58 = 0;
    local_38 = 0;
LAB_680e3504:
    local_5c = 0;
  }
  Ordinal_1420(local_b4,&local_5c,0x50);
  if (unaff_EBX[0x13] == 0) {
    local_c0 = 0;
    Ordinal_1420(local_b4,&local_c0,4);
  }
  else {
    uVar2 = Ordinal_1433(local_b4);
    Ordinal_1432(local_b4,4,1);
    local_c0 = cast_readDataEntry(unaff_EBX[0x13],local_b4,0);
    uVar3 = Ordinal_1433(local_b4);
    Ordinal_1432(local_b4,uVar2,0);
    Ordinal_1420(local_b4,&local_c0,4);
    Ordinal_1432(local_b4,uVar3,0);
  }
  iVar1 = bitmap_serializeSpriteName(param_1,(short)unaff_EBX[1],*unaff_EBX);
  if (((iVar1 != 0) && (iVar1 = bitmap_saveToScore(local_b4), iVar1 != 0)) &&
     (iVar1 = Ordinal_1042(), iVar1 == 0)) {
    Ordinal_1407(&local_b4);
    iVar1 = Ordinal_2008(local_bc,1000);
    if (iVar1 != 0) {
      local_b8 = 1;
    }
  }
LAB_680e361f:
  Ordinal_1407(&local_b4);
  Ordinal_1113(&local_bc);
  Ordinal_1042();
  if (iVar6 != 0) {
    Ordinal_1040(iVar6);
  }
  return 0;
}



// ============================================================
// Function: bitmap_receiveSpriteData (FUN_680e36a0)
// Address: 680e36a0
// Size: 339 bytes
// Params: void * this, void * param_1, undefined4 param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_receiveSpriteData(void *this,void *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  iVar5 = 0;
  local_8 = 0;
  local_10 = 0;
  local_14 = 0;
  iVar4 = 0;
  local_c = 0;
  iVar2 = Ordinal_1404(&local_8);
  if (iVar2 != 0) {
    iVar4 = Ordinal_1042();
    uVar3 = Ordinal_1441(local_8);
    *(undefined4 *)((int)this + 8) = uVar3;
    uVar3 = Ordinal_1441(local_8);
    *(undefined4 *)((int)this + 0x10) = uVar3;
    uVar3 = Ordinal_1441(local_8);
    *(undefined4 *)((int)this + 0x1c) = uVar3;
    iVar2 = Ordinal_1441(local_8);
    *(uint *)((int)this + 0x2c) =
         *(uint *)((int)this + 0x2c) ^ (iVar2 << 9 ^ *(uint *)((int)this + 0x2c)) & 0x200;
    iVar2 = Ordinal_1441(local_8);
    *(uint *)((int)this + 0x2c) =
         *(uint *)((int)this + 0x2c) ^ (iVar2 << 8 ^ *(uint *)((int)this + 0x2c)) & 0x100;
    Ordinal_1409(local_8,(int)this + 0x54,0x50);
    Ordinal_1409(local_8,&local_10,4);
    iVar2 = Ordinal_1042();
    if (iVar2 == 0) {
      if (local_10 != 0) {
        iVar2 = cast_writeDataEntry(local_8,local_10,0);
        *(int *)((int)this + 0x4c) = iVar2;
        if (iVar2 == 0) goto LAB_680e37af;
        rendering_setDispatchRef((int)this,0);
        rendering_getDispatchDataRef((int)this,0);
      }
      local_14 = bitmap_deserializeSprite(param_1,*(int **)this);
      iVar5 = local_c;
      if (((local_14 != 0) &&
          (bVar1 = rendering_updateDispatchScore(param_2,local_14), iVar5 = local_c,
          CONCAT31(extraout_var,bVar1) != 0)) &&
         (iVar2 = bitmap_beginCapture(), iVar5 = local_c, iVar2 != 0)) {
        local_c = 1;
        iVar5 = local_c;
      }
    }
  }
LAB_680e37af:
  Ordinal_1407(&local_8);
  if (iVar5 == 0) {
    Ordinal_36((int *)((int)this + 0x4c));
    Ordinal_1130((int)this + 0x54,0x50);
  }
  playback_initScore(&local_14);
  Ordinal_1042();
  if (iVar4 != 0) {
    Ordinal_1040(iVar4);
  }
  return iVar5;
}



// ============================================================
// Function: bitmap_createFromDC (FUN_680e3800)
// Address: 680e3800
// Size: 126 bytes
// Params: byte * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_createFromDC(byte *param_1)

{
  int iVar1;
  int *unaff_ESI;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_8 = Ordinal_2003(&local_c,0);
  if (local_8 != 0) {
    iVar1 = Ordinal_1663(&local_8,local_c,0);
    if (iVar1 != 0) {
      iVar1 = rendering_setMemberPropertyEx(param_1,unaff_ESI,(undefined4 *)0x0,local_8,local_c,0,5,1);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  Ordinal_1653(&local_8);
  Ordinal_1733(&local_c);
  Ordinal_1130();
  return 0;
}



// ============================================================
// Function: bitmap_exportLinkedMedia (FUN_680e3880)
// Address: 680e3880
// Size: 382 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_exportLinkedMedia(void *this,int param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int local_3c [2];
  char *local_34;
  int local_30;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_34 = (char *)0x0;
  local_3c[1] = 0;
  iVar1 = Ordinal_2007(0,0);
  if (((iVar1 != 0) && (local_34 = (char *)Ordinal_1126(iVar1,0), local_34 != (char *)0x0)) &&
     (iVar1 = Ordinal_2007(local_34,iVar1), iVar1 != 0)) {
    iVar1 = rendering_resolveState(*(int *)((int)this + 0x18),param_1);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 8) != 3)) {
      uVar8 = 0;
      puVar7 = (undefined4 *)0x0;
      iVar1 = rendering_getDispatchFlags(0xfb);
      piVar2 = (int *)lingo_getGlobalRef(*(int *)((int)this + 0x18));
      iVar1 = media_getAssetGuid(piVar2,iVar1,puVar7,uVar8);
      if (iVar1 != -0x7ffbf82d) {
        iVar9 = 0;
        piVar2 = (int *)0x0;
        iVar6 = 0;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = 0;
        iVar1 = rendering_getDispatchFlags(0xfb);
        iVar1 = rendering_blitMedia(this,*(int *)((int)this + 0x18),param_1,iVar1,uVar3,uVar4,uVar5,iVar6,
                             piVar2,iVar9);
        if (iVar1 != 0) {
          local_2c = (void *)0x0;
          local_28 = 0;
          local_24 = 0;
          local_20 = 0;
          local_1c = (int *)0x0;
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          local_30 = 0;
          props_loadStringValue(0,local_34,local_3c);
          local_30 = rendering_resolveState(*(int *)((int)this + 0x18),param_1);
          local_1c = local_3c;
          local_28 = 0x14;
          local_24 = 1;
          local_20 = 0xfb;
          local_2c = this;
          rendering_initState(&local_30);
          props_releaseAndClear(0,local_3c);
        }
        goto LAB_680e39e0;
      }
    }
    rendering_blitMedia(this,*(int *)((int)this + 0x18),param_1,3,0,local_34,0,0,(int *)0x0,0);
  }
LAB_680e39e0:
  Ordinal_1127(&local_34);
  return 0;
}



// ============================================================
// Function: bitmap_dispatchRenderUpdate (FUN_680e3a00)
// Address: 680e3a00
// Size: 274 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_dispatchRenderUpdate(int param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_4c;
  int local_48;
  int local_44 [4];
  undefined4 local_34;
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
  
  local_30 = (int *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_34 = 0;
  iVar3 = 0;
  Ordinal_1130(&local_4c,0x18);
  piVar1 = (int *)rendering_resolveState(*(int *)(param_1 + 0x18),param_2);
  if (piVar1 == (int *)0x0) goto LAB_680e3aee;
  iVar2 = rendering_getFrameCount((int)piVar1);
  if (iVar2 == 0) {
    iVar3 = rendering_getMemberData(param_1,piVar1);
    if (iVar3 == 0) goto LAB_680e3aee;
  }
  iVar2 = Ordinal_2000();
  if (iVar2 != 0) {
    iVar2 = bitmap_sendSpriteData(*(int *)(param_1 + 0x20));
    if (iVar2 != 0) {
      local_2c = param_1;
      local_28 = 0xb;
      local_30 = piVar1;
      iVar2 = rendering_initState((int *)&local_30);
      if (iVar2 != 0) {
        iVar2 = rendering_getFrameCount((int)piVar1);
        if ((iVar2 == 0) && (piVar1[2] != 2)) {
          local_4c = iVar2;
          local_48 = iVar2;
          local_44[0] = iVar2;
          iVar2 = rendering_resolveMemberData(*(undefined4 **)(param_1 + 0x20),piVar1,&local_4c,0);
          if (iVar2 != 0) goto LAB_680e3ae4;
          Ordinal_2008(local_44[0],0x3ef);
        }
        local_34 = 1;
      }
    }
  }
LAB_680e3ae4:
  if (iVar3 != 0) {
    rendering_isStateValid((int)piVar1);
  }
LAB_680e3aee:
  Ordinal_1113(local_44);
  Ordinal_2001();
  return 0;
}



