// Module: bitmap
// Topic: Sprite properties, state validation, event dispatch, rendering state setup
// Address range: 0x680e0150 - 0x680e2090
// Functions (41):
//   bitmap_renderSpriteOverlay
//   bitmap_readSpriteProps
//   bitmap_writeSpriteProps
//   bitmap_getSpritePropertyValue
//   bitmap_setSpritePropertyValue
//   bitmap_dispatchSpriteMsg
//   bitmap_setupSpriteInk
//   bitmap_renderSpriteInk
//   bitmap_validateSpriteData
//   bitmap_applySpriteRegPoint
//   bitmap_buildSpriteTransform
//   bitmap_collectSpriteGeometry
//   bitmap_decodeSpriteFlags
//   bitmap_getSpriteState
//   bitmap_updateCursorState
//   bitmap_processSpriteUpdate
//   bitmap_releaseSpriteXtra
//   bitmap_setSpriteEditMode
//   bitmap_initSpriteXtra
//   bitmap_cleanupSpriteXtra
//   bitmap_drawSpriteXtra
//   bitmap_hitTestSpriteXtra
//   bitmap_handleSpriteIdle
//   bitmap_setSpriteProperty
//   bitmap_getSpriteEditability
//   bitmap_getDirectToStage
//   bitmap_getXtraProperty
//   bitmap_callXtraMethod
//   bitmap_enumXtraProps
//   bitmap_handleModifierKey
//   bitmap_checkXtraAutoTab
//   bitmap_checkXtraPropertyMatch
//   bitmap_invokeXtraScript
//   bitmap_drawSpriteRect
//   bitmap_drawSpriteBorder
//   bitmap_drawSpriteOutline
//   bitmap_getSpriteRect
//   bitmap_updateSpriteScroll
//   bitmap_setupSpriteText
//   bitmap_teardownSpriteText
//   bitmap_drawSpriteOverlay

// ============================================================
// Function: bitmap_renderSpriteOverlay (FUN_680e0150)
// Address: 680e0150
// Size: 46 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_renderSpriteOverlay(int param_1,undefined4 param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  
  playback_getSpriteProperty(param_1,param_3);
  uVar1 = playback_verifySpriteCallbackTarget();
  Ordinal_1624(param_2,uVar1,param_3 + 0x32,0xc);
  return 0;
}



// ============================================================
// Function: bitmap_readSpriteProps (FUN_680e0180)
// Address: 680e0180
// Size: 119 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readSpriteProps(void)
{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  int unaff_ESI;
  
  uVar1 = Ordinal_1412();
  *(undefined1 *)(unaff_ESI + 0x54) = uVar1;
  sVar3 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x5c) = (int)sVar3;
  sVar3 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x58) = (int)sVar3;
  sVar3 = Ordinal_1412();
  *(int *)(unaff_ESI + 100) = (int)sVar3;
  sVar3 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x60) = (int)sVar3;
  uVar1 = Ordinal_1412();
  *(undefined1 *)(unaff_ESI + 0x68) = uVar1;
  *(undefined1 *)(unaff_ESI + 0x6c) = 0;
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_ESI + 0x69) = uVar1;
  *(undefined1 *)(unaff_ESI + 0x70) = 0;
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_ESI + 0x6d) = uVar1;
  cVar2 = Ordinal_1410();
  *(int *)(unaff_ESI + 0x74) = (int)cVar2;
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_ESI + 0x78) = uVar1;
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_ESI + 0x79) = uVar1;
  return 0;
}



// ============================================================
// Function: bitmap_writeSpriteProps (FUN_680e0200)
// Address: 680e0200
// Size: 159 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeSpriteProps(void)
{
  int unaff_EBX;
  int unaff_EDI;
  
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  lingo_writeValue(unaff_EBX,(undefined1 *)(unaff_EDI + 0x69));
  Ordinal_1422();
  lingo_writeValue(unaff_EBX,(undefined1 *)(unaff_EDI + 0x6d));
  Ordinal_1422();
  Ordinal_1421();
  Ordinal_1422();
  Ordinal_1422();
  return 0;
}



// ============================================================
// Function: bitmap_getSpritePropertyValue (FUN_680e02a0)
// Address: 680e02a0
// Size: 178 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall bitmap_getSpritePropertyValue(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = *param_2;
  puVar2 = (uint *)param_2[4];
  if (*(int *)(iVar1 + 8) == 8) {
    switch(param_2[3]) {
    case 5:
      *puVar2 = *(uint *)(iVar1 + 0x58);
      puVar2[1] = *(uint *)(iVar1 + 0x5c);
      puVar2[2] = *(uint *)(iVar1 + 0x60);
      puVar2[3] = *(uint *)(iVar1 + 100);
      return 1;
    case 0x51:
      *puVar2 = (int)*(char *)(iVar1 + 0x54);
      return 1;
    case 0x52:
      *puVar2 = (uint)*(byte *)(iVar1 + 0x79);
      return 1;
    case 0x53:
      *puVar2 = *(byte *)(iVar1 + 0x78) - 1;
      return 1;
    case 0x54:
      *puVar2 = (int)*(char *)(iVar1 + 0x68);
      return 1;
    case 0x55:
      *puVar2 = *(uint *)(iVar1 + 0x74);
      return 1;
    case 0x62:
      *puVar2 = *(uint *)(iVar1 + 0x6d);
      return 1;
    case 0x6c:
      *puVar2 = *(uint *)(iVar1 + 0x69);
      return 1;
    }
  }
  Ordinal_1130(puVar2,0x18);
  return 0;
}



// ============================================================
// Function: bitmap_setSpritePropertyValue (FUN_680e03e0)
// Address: 680e03e0
// Size: 249 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setSpritePropertyValue(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_EAX;
  undefined4 uVar4;
  
  piVar1 = (int *)*in_EAX;
  piVar2 = (int *)in_EAX[4];
  uVar4 = 0;
  iVar3 = in_EAX[1];
  if (piVar1[2] == 8) {
    switch(in_EAX[3]) {
    case 5:
      piVar1[0x16] = *piVar2;
      piVar1[0x17] = piVar2[1];
      piVar1[0x18] = piVar2[2];
      piVar1[0x19] = piVar2[3];
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    case 0x51:
      *(char *)(piVar1 + 0x15) = (char)*piVar2;
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    case 0x52:
      *(char *)((int)piVar1 + 0x79) = (char)*piVar2;
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    case 0x53:
      *(char *)(piVar1 + 0x1e) = (char)*piVar2 + '\x01';
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    case 0x54:
      *(char *)(piVar1 + 0x1a) = (char)*piVar2;
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    case 0x55:
      piVar1[0x1d] = *piVar2;
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    case 0x62:
      *(int *)((int)piVar1 + 0x6d) = *piVar2;
      rendering_setMemberData(iVar3,piVar1,3);
      uVar4 = 1;
      break;
    case 0x6c:
      *(int *)((int)piVar1 + 0x69) = *piVar2;
      rendering_setMemberData(iVar3,piVar1,3);
      return 1;
    }
  }
  return uVar4;
}



// ============================================================
// Function: bitmap_dispatchSpriteMsg (FUN_680e0570)
// Address: 680e0570
// Size: 411 bytes
// Params: void * this, int * param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall bitmap_dispatchSpriteMsg(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  switch(param_1[2]) {
  case 0:
    *(undefined1 *)(iVar1 + 0x54) = 1;
    *(undefined1 *)(iVar1 + 0x79) = 5;
    break;
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xb:
  case 0xc:
  case 0x13:
    goto switchD_680e058f_caseD_3;
  case 9:
    param_1[3] = 0;
    break;
  case 10:
  case 0x12:
    param_1[3] = 0;
    return 1;
  case 0xf:
    iVar2 = (int)*(char *)(iVar1 + 0x54);
    param_1[3] = iVar2;
    if (*(char *)(iVar1 + 0x54) == '\x04') {
      param_1[3] = (uint)*(byte *)(iVar1 + 0x79);
      return 1;
    }
    param_1[3] = iVar2 + 1;
    if (*(int *)(iVar1 + 0x74) != 0) {
      return 1;
    }
    param_1[3] = iVar2 + 0xb;
    return 1;
  case 0x10:
    bitmap_readSpriteProps();
    return 1;
  case 0x11:
    bitmap_writeSpriteProps();
    return 1;
  case 0x19:
    iVar1 = bitmap_getSpritePropertyValue(this,param_1);
    if (iVar1 != 0) {
      return 1;
    }
    break;
  case 0x1a:
    iVar1 = bitmap_setSpritePropertyValue();
    if (iVar1 != 0) {
      return 1;
    }
    break;
  case 0x1d:
    iVar2 = param_1[3];
    if (((((*(char *)(iVar1 + 0x54) == *(char *)(iVar2 + 0x54)) &&
          (iVar3 = Ordinal_1063(iVar1 + 0x58,iVar2 + 0x58), iVar3 != 0)) &&
         (*(char *)(iVar1 + 0x68) == *(char *)(iVar2 + 0x68))) &&
        ((iVar3 = Ordinal_1079(iVar1 + 0x69,iVar2 + 0x69), iVar3 != 0 &&
         (iVar3 = Ordinal_1079(iVar1 + 0x6d,iVar2 + 0x6d), iVar3 != 0)))) &&
       ((*(int *)(iVar1 + 0x74) == *(int *)(iVar2 + 0x74) &&
        ((*(char *)(iVar1 + 0x78) == *(char *)(iVar2 + 0x78) &&
         (*(char *)(iVar1 + 0x79) == *(char *)(iVar2 + 0x79))))))) {
      param_1[4] = 1;
      return 1;
    }
    goto switchD_680e058f_caseD_3;
  }
  iVar1 = rendering_validateState(param_1);
  if (iVar1 == 0) {
    return 0;
  }
switchD_680e058f_caseD_3:
  return 1;
}



// ============================================================
// Function: bitmap_setupSpriteInk (FUN_680e0760)
// Address: 680e0760
// Size: 179 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_setupSpriteInk(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)
{
  int iVar1;
  short sVar2;
  undefined2 local_198;
  undefined2 local_196;
  char local_182;
  undefined4 local_168;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_6c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_8;
  
  local_196 = 0;
  local_198 = 0;
  local_182 = *(char *)(param_2 + 0x78) + -1;
  local_d0 = *param_4;
  local_cc = param_4[1];
  local_c8 = param_4[2];
  local_c4 = param_4[3];
  local_58 = *(undefined4 *)(param_2 + 0x69);
  local_54 = *(undefined4 *)(param_2 + 0x6d);
  sVar2 = (short)*(char *)(param_2 + 0x68);
  local_168 = 0x10;
  local_6c = 0;
  iVar1 = playback_processSpriteChannelUpdate(0x10,param_2);
  playback_unregisterSpriteCallback(param_3,(int)&local_198,param_1,iVar1,sVar2);
  return 0;
}



// ============================================================
// Function: bitmap_renderSpriteInk (FUN_680e0820)
// Address: 680e0820
// Size: 101 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_renderSpriteInk(int param_1,undefined4 param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = param_3;
  puVar4 = (undefined4 *)param_3[0xc];
  sVar2 = playback_processSpriteVisibility(param_1,param_3);
  if ((((param_3[0xc] == 0x10) && (iVar3 = playback_getSpriteData(param_1,param_3), iVar3 != 0)) &&
      (puVar4 = (undefined4 *)playback_processSpriteChannelUpdate((int)puVar4,iVar3), *(char *)(iVar3 + 0x54) == '\x04'))
     && (*(int *)(iVar3 + 0x74) == 0)) {
    return 0;
  }
  param_3 = puVar4;
  playback_unregisterSpriteCallback(param_2,(int)puVar1,param_1,(int)param_3,sVar2);
  return 0;
}



// ============================================================
// Function: bitmap_validateSpriteData (FUN_680e0890)
// Address: 680e0890
// Size: 41 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_validateSpriteData(void)

{
  undefined4 *in_EAX;
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  piVar1 = (int *)playback_getSpriteData(unaff_ESI,in_EAX);
  if (piVar1 == (int *)0x0) {
    return true;
  }
  iVar2 = rendering_getMemberData(unaff_ESI,piVar1);
  return iVar2 != 0;
}



// ============================================================
// Function: bitmap_applySpriteRegPoint (FUN_680e08c0)
// Address: 680e08c0
// Size: 64 bytes
// Params: undefined1 * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_applySpriteRegPoint(undefined1 *param_1,int param_2)
{
  undefined1 *in_EAX;
  int local_8;
  
  if (param_1[3] == '\0') {
    local_8 = *(int *)(param_2 + 0x3c);
    in_EAX[3] = 1;
    media_convertPaletteToRgb(&local_8,*param_1,in_EAX);
    return 0;
  }
  in_EAX[3] = 1;
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  in_EAX[2] = param_1[2];
  return 0;
}



// ============================================================
// Function: bitmap_buildSpriteTransform (FUN_680e0900)
// Address: 680e0900
// Size: 92 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_buildSpriteTransform(undefined4 param_1)
{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *unaff_ESI;
  int local_8;
  
  local_8 = in_EAX[0xf];
  if ((*(ushort *)(in_EAX + 0x53) & 0x8000) != 0) {
    crt_resolveImageData(&local_8,unaff_ESI);
    return 0;
  }
  if (in_EAX[0x61] != 0) {
    iVar1 = playback_getSpriteInfo(local_8,in_EAX);
    if (iVar1 != 0) {
      crt_resolveImageDataDirect(param_1,unaff_ESI);
      return 0;
    }
  }
  crt_resolveLinkedImageData(&local_8,unaff_ESI);
  return 0;
}



// ============================================================
// Function: bitmap_collectSpriteGeometry (FUN_680e0960)
// Address: 680e0960
// Size: 612 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_collectSpriteGeometry(int param_1)
{
  double dVar1;
  short sVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *unaff_EBX;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = unaff_EDI[0x33];
  unaff_ESI[2] = unaff_EDI[0x35];
  unaff_ESI[1] = unaff_EDI[0x32];
  unaff_ESI[3] = unaff_EDI[0x34];
  sVar2 = *(short *)(unaff_EDI + 3);
  unaff_ESI[6] = (int)sVar2 & 0x3fU;
  if (((*(ushort *)(unaff_EDI + 0x53) & 0x100) == 0) && (((int)sVar2 & 0x3fU) == 0x20)) {
    unaff_ESI[6] = 0;
  }
  unaff_ESI[5] = 0x20;
  uVar7 = *(byte *)((int)unaff_EDI + 0x15) >> 5 & 4 | 0x20;
  unaff_ESI[5] = uVar7;
  uVar7 = *(byte *)((int)unaff_EDI + 0x15) >> 3 & 8 | uVar7;
  unaff_ESI[5] = uVar7;
  if (param_1 != 0) {
    unaff_ESI[5] = uVar7 | 0x40;
  }
  unaff_ESI[4] = ((*(ushort *)(unaff_EDI + 0x53) & 0x8000) != 0) + 1;
  *(byte *)(unaff_ESI + 10) = *(byte *)((int)unaff_EDI + 0x16) >> 4 & 1;
  unaff_ESI[9] = (uint)*(byte *)((int)unaff_EDI + 0xe);
  if ((unaff_ESI[6] == 0x28) || (unaff_ESI[6] == 0x29)) {
    bitmap_applySpriteRegPoint((undefined1 *)(unaff_EDI + 0x4f),(int)unaff_EDI);
    puVar8 = unaff_EDI + 0x4e;
  }
  else {
    bitmap_applySpriteRegPoint((undefined1 *)(unaff_EDI + 0x50),(int)unaff_EDI);
    puVar8 = unaff_EDI + 0x51;
  }
  bitmap_applySpriteRegPoint((undefined1 *)puVar8,(int)unaff_EDI);
  *(float *)((int)unaff_ESI + 0x2a) = (float)(int)unaff_EDI[0xd] / 100.0;
  *(float *)((int)unaff_ESI + 0x2e) = (float)(int)unaff_EDI[0xe] / 100.0;
  *(byte *)((int)unaff_ESI + 0x32) = *(byte *)((int)unaff_EDI + 0x16) & 0x20;
  *(byte *)((int)unaff_ESI + 0x33) = *(byte *)((int)unaff_EDI + 0x16) & 0x40;
  unaff_ESI[0xd] = (int)(float)*(double *)(unaff_EDI + 0x36);
  unaff_ESI[0xe] = (int)(float)*(double *)(unaff_EDI + 0x38);
  unaff_ESI[0xf] = (int)(float)*(double *)(unaff_EDI + 0x3a);
  unaff_ESI[0x10] = (int)(float)*(double *)(unaff_EDI + 0x3c);
  unaff_ESI[0x11] = (int)(float)*(double *)(unaff_EDI + 0x3e);
  unaff_ESI[0x12] = (int)(float)*(double *)(unaff_EDI + 0x40);
  unaff_ESI[0x13] = (int)(float)*(double *)(unaff_EDI + 0x42);
  dVar1 = *(double *)(unaff_EDI + 0x44);
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x14] = (int)(float)dVar1;
  iVar6 = playback_getSpriteInfo(unaff_EDI[0xf],unaff_EDI);
  if (iVar6 != 0) {
    iVar6 = unaff_EDI[0x5c];
    iVar3 = unaff_EDI[0x5d];
    *unaff_EBX = 1;
    *(int *)(unaff_EBX + 2) = unaff_ESI[6];
    *(int *)(unaff_EBX + 6) = *unaff_ESI;
    *(int *)(unaff_EBX + 10) = unaff_ESI[1];
    *(int *)(unaff_EBX + 0xe) = unaff_ESI[2];
    *(int *)(unaff_EBX + 0x12) = unaff_ESI[3];
    *(undefined4 *)(unaff_EBX + 0x1a) = unaff_EDI[0x5c];
    *(undefined4 *)(unaff_EBX + 0x16) = unaff_EDI[0x5d];
    *(undefined4 *)(unaff_EBX + 0x22) = unaff_EDI[0x5e];
    *(undefined4 *)(unaff_EBX + 0x1e) = unaff_EDI[0x5f];
    fVar4 = (float)iVar6;
    *unaff_ESI = *unaff_ESI - iVar3;
    unaff_ESI[2] = unaff_ESI[2] - iVar3;
    unaff_ESI[1] = unaff_ESI[1] - iVar6;
    unaff_ESI[3] = unaff_ESI[3] - iVar6;
    unaff_ESI[6] = 0;
    unaff_ESI[0x16] = (int)unaff_EBX;
    unaff_ESI[0xd] = (int)((float)unaff_ESI[0xd] - fVar4);
    fVar5 = (float)iVar3;
    unaff_ESI[0xe] = (int)((float)unaff_ESI[0xe] - fVar5);
    unaff_ESI[0xf] = (int)((float)unaff_ESI[0xf] - fVar4);
    unaff_ESI[0x10] = (int)((float)unaff_ESI[0x10] - fVar5);
    unaff_ESI[0x11] = (int)((float)unaff_ESI[0x11] - fVar4);
    unaff_ESI[0x12] = (int)((float)unaff_ESI[0x12] - fVar5);
    unaff_ESI[0x13] = (int)((float)unaff_ESI[0x13] - fVar4);
    unaff_ESI[0x14] = (int)((float)unaff_ESI[0x14] - fVar5);
  }
  if (unaff_EDI[0x46] == 0) {
    unaff_ESI[0x15] = 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_decodeSpriteFlags (FUN_680e0bd0)
// Address: 680e0bd0
// Size: 51 bytes
// Params: byte param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_decodeSpriteFlags(byte param_1)
{
  uint *in_EAX;
  
  *in_EAX = 0;
  if ((param_1 & 1) != 0) {
    *in_EAX = 1;
  }
  if ((param_1 & 4) != 0) {
    *in_EAX = *in_EAX | 8;
  }
  if ((param_1 & 8) != 0) {
    *in_EAX = *in_EAX | 4;
  }
  if ((param_1 & 0x10) != 0) {
    *in_EAX = *in_EAX | 2;
  }
  return 0;
}



// ============================================================
// Function: bitmap_getSpriteState (FUN_680e0c10)
// Address: 680e0c10
// Size: 302 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getSpriteState(int param_1)
{
  uint uVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  uint local_40 [5];
  
  local_40[2] = 0;
  Ordinal_1130(local_40,8);
  Ordinal_1130(&stack0xffffffd4,0x24);
  if (unaff_ESI[0x52] != 0) {
    iVar2 = scoreEngine_isXtraEditable(*(undefined4 **)(*(int *)(*(int *)(unaff_ESI[0xf] + 0x20) + 4) + 0x20));
    local_40[0] = (uint)(iVar2 != 0);
    local_40[1] = 1;
    if (param_1 != 0) {
      lingo_getDebugContext(*(int *)(*(int *)(unaff_ESI[0xf] + 0x20) + 4),local_40 + 3);
      playback_getSpriteInfo(unaff_ESI[0xf],unaff_ESI);
      if (unaff_EDI != 0) {
        bitmap_decodeSpriteFlags((byte)*(undefined4 *)(unaff_EDI + 0x14));
      }
    }
    if (((unaff_ESI[0x14] & 2) == 0) ||
       (((*(ushort *)(unaff_ESI + 0x53) & 0x4000) != 0 &&
        ((unaff_EBX == 0xf || (unaff_EBX == 0x11)))))) {
      media_dispatchCheckHit(unaff_ESI[0xf],(int *)unaff_ESI[0x52],local_40,&stack0xffffffd4,local_40 + 2);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_updateCursorState (FUN_680e0d40)
// Address: 680e0d40
// Size: 144 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_updateCursorState(void)
{
  int unaff_ESI;
  undefined4 local_18;
  ushort local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (*(int **)(unaff_ESI + 0x148) == (int *)0x0) {
    local_14 = 0;
    local_18 = 0;
    local_10 = 0;
    local_c = 0;
  }
  else {
    media_dispatchGetRectDirect(*(int *)(unaff_ESI + 0x3c),*(int **)(unaff_ESI + 0x148),&local_18);
  }
  local_14 = local_14 & 0x7ff;
  if ((local_10 == 2) || ((local_10 == 0 && (local_c == 2)))) {
    local_14 = local_14 | 0x8000;
  }
  *(ushort *)(unaff_ESI + 0x14c) = local_14 | *(ushort *)(unaff_ESI + 0x14c) & 0x5800;
  *(undefined4 *)(unaff_ESI + 0x150) = local_18;
  return 0;
}



// ============================================================
// Function: bitmap_processSpriteUpdate (FUN_680e0dd0)
// Address: 680e0dd0
// Size: 262 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_processSpriteUpdate(undefined4 *param_1)
{
  undefined1 local_9d;
  undefined4 local_9c;
  undefined1 local_98 [88];
  undefined1 local_40;
  undefined4 local_3e;
  undefined4 local_3a;
  undefined4 local_36;
  undefined4 local_32;
  undefined4 local_2e;
  undefined4 local_2a;
  undefined4 local_26;
  undefined4 local_22;
  undefined4 local_1e;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_9c = 0;
  memset(local_98,0,0x58);
  local_3e = 0;
  local_3a = 0;
  local_36 = 0;
  local_32 = 0;
  local_2e = 0;
  local_2a = 0;
  local_26 = 0;
  local_22 = 0;
  local_1e = 0;
  local_40 = 0;
  local_9d = 0;
  if ((*(ushort *)(param_1 + 0x53) & 0x1000) != 0) {
    local_18 = param_1[0x33];
    local_14 = param_1[0x32];
    local_c = param_1[0x34];
    local_10 = param_1[0x35];
    media_updateSpriteStage(&local_18,param_1);
    *(ushort *)(param_1 + 0x53) = *(ushort *)(param_1 + 0x53) & 0xefff;
    return 0;
  }
  if (((*(ushort *)(param_1 + 0x53) & 1) == 0) && (param_1[0x52] != 0)) {
    bitmap_collectSpriteGeometry(0);
    media_dispatchSetProperty(param_1[0xf],(int *)param_1[0x52],&local_9c,param_1,&local_9d);
  }
  return 0;
}



// ============================================================
// Function: bitmap_releaseSpriteXtra (FUN_680e0ee0)
// Address: 680e0ee0
// Size: 248 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_releaseSpriteXtra(void)
{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x148);
  if (piVar1 != (int *)0x0) {
    bVar3 = false;
    if (((*(byte *)(in_EAX + 0x150) & 4) != 0) && ((*(ushort *)(in_EAX + 0x14c) & 0x800) != 0)) {
      iVar2 = *(int *)(*(int *)(*(int *)(in_EAX + 0x3c) + 0x20) + 8);
      if ((iVar2 != 0) &&
         ((*(int *)(iVar2 + 0x7c) == *(int *)(in_EAX + 0x40) + 1 && (*(int *)(iVar2 + 0x78) == 3))))
      {
        bVar3 = true;
      }
      bitmap_getSpriteState(0);
      *(ushort *)(in_EAX + 0x14c) = *(ushort *)(in_EAX + 0x14c) & 0xf7ff;
    }
    if (*(int **)(in_EAX + 0x148) == piVar1) {
      if (((*(byte *)(in_EAX + 0x150) & 0x40) != 0) && ((*(ushort *)(in_EAX + 0x14c) & 0x4000) != 0)
         ) {
        bitmap_getSpriteState(0);
        *(ushort *)(in_EAX + 0x14c) = *(ushort *)(in_EAX + 0x14c) & 0xbfff;
      }
      if (*(int **)(in_EAX + 0x148) == piVar1) {
        *(undefined4 *)(in_EAX + 0x148) = 0;
        *(undefined2 *)(in_EAX + 0x14c) = 0;
        *(undefined4 *)(in_EAX + 0x150) = 0;
        media_dispatchRelease(*(int *)(in_EAX + 0x3c),piVar1);
        if (bVar3) {
          sprites_getTextCaretPos();
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_setSpriteEditMode (FUN_680e0fe0)
// Address: 680e0fe0
// Size: 18 bytes
// Params: byte param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_setSpriteEditMode(byte param_1)
{
  int in_EAX;
  
  media_dispatchRenderByte(*(int *)(in_EAX + 0x3c),*(int **)(in_EAX + 0x148),param_1);
  return 0;
}



// ============================================================
// Function: bitmap_initSpriteXtra (FUN_680e1000)
// Address: 680e1000
// Size: 377 bytes
// Params: int param_1, undefined4 * param_2, byte param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_initSpriteXtra(int param_1,undefined4 *param_2,byte param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar1 == (int *)0x0) || (piVar1[2] != 0xf)) {
    return 0;
  }
  param_2[0x18] = 10;
  uVar2 = scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),piVar1,0);
  if (uVar2 == 0) {
    param_2[0x48] = 1;
    return 1;
  }
  param_2[0x48] = 0;
  iVar3 = rendering_getMemberData(param_1,piVar1);
  if (iVar3 == 0) {
    return 0;
  }
  if (((param_3 & 4) != 0) || (param_2[0x52] == 0)) {
    if (param_2[0x52] != 0) {
      bitmap_releaseSpriteXtra();
    }
    iVar3 = media_dispatchGetStatus(param_1,(int *)piVar1[0x15],param_2 + 0x52);
    if (iVar3 != 0) {
      param_2[0x52] = 0;
      goto LAB_680e112b;
    }
    *(undefined2 *)(param_2 + 0x53) = 0;
    media_dispatchNotify(param_1,(int *)param_2[0x52],param_2[0x10] + 1);
    bitmap_setSpriteEditMode(~(byte)((uint)param_2[0x14] >> 1) & 1);
    bitmap_updateCursorState();
  }
  if ((*(ushort *)(param_2 + 0x53) & 0x2000) != 0) {
    bitmap_updateCursorState();
  }
  if ((((*(byte *)(param_2 + 0x54) & 0x40) != 0) && ((*(ushort *)(param_2 + 0x53) & 0x4000) == 0))
     && ((*(byte *)(param_2 + 0x14) & 2) == 0)) {
    *(ushort *)(param_2 + 0x53) = *(ushort *)(param_2 + 0x53) | 0x4000;
    bitmap_getSpriteState(0);
  }
LAB_680e112b:
  playback_renderSprite((int)param_2,(int)piVar1,0);
  playback_renderSpriteData(param_1,param_2,1);
  param_2[0x13] = param_2[0x13] | 3;
  param_2[0x17] = param_2[0x17] & 0xfffffffe;
  if ((*(ushort *)(param_2 + 0x53) & 0x8000) != 0) {
    param_2[0x13] = param_2[0x13] | 8;
  }
  rendering_isStateValid((int)piVar1);
  return 1;
}



// ============================================================
// Function: bitmap_cleanupSpriteXtra (FUN_680e1180)
// Address: 680e1180
// Size: 15 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_cleanupSpriteXtra(void)
{
  bitmap_releaseSpriteXtra();
  return 0;
}



// ============================================================
// Function: bitmap_drawSpriteXtra (FUN_680e1190)
// Address: 680e1190
// Size: 674 bytes
// Params: uint param_1, undefined4 param_2, undefined4 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawSpriteXtra(uint param_1,undefined4 param_2,undefined4 *param_3,int param_4)
{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 local_108 [7];
  uint local_ec [4];
  int *local_dc;
  int local_d8;
  undefined4 local_d4;
  undefined1 local_d0 [88];
  undefined1 local_78;
  undefined4 local_76;
  undefined4 local_72;
  undefined4 local_6e;
  undefined4 local_6a;
  undefined4 local_66;
  undefined4 local_62;
  undefined4 local_5e;
  undefined4 local_5a;
  undefined4 local_56;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
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
  undefined4 local_c;
  uint local_8;
  
  local_d8 = 0;
  local_d4 = 0;
  local_ec[3] = param_1;
  memset(local_d0,0,0x58);
  local_ec[0] = 0;
  local_ec[1] = 0;
  local_78 = 0;
  local_76 = 0;
  local_72 = 0;
  local_6e = 0;
  local_6a = 0;
  local_66 = 0;
  local_62 = 0;
  local_5e = 0;
  local_5a = 0;
  local_56 = 0;
  local_ec[2] = 0;
  Ordinal_1130(local_108,0x1c);
  Ordinal_1130(&local_d4,0x5c);
  local_dc = (int *)playback_getSpriteData(param_1,param_3);
  if ((local_dc != (int *)0x0) && (local_dc[2] == 0xf)) {
    bVar2 = bitmap_validateSpriteData();
    if (CONCAT31(extraout_var,bVar2) == 0) goto LAB_680e13b5;
    local_ec[2] = 1;
    if (param_3[0x52] == 0) {
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_d8 = Ordinal_1602(param_2);
      puVar1 = param_3 + 0x32;
      Ordinal_1608(param_2,puVar1);
      local_40 = 0;
      local_2c = 0;
      local_24 = 0x1ffffff;
      local_28 = 0x10000ff;
      Ordinal_1623(param_2,0,puVar1,0xc,2,&local_2c,&local_40);
      local_44 = param_3[0x35];
      local_50 = param_3[0x34];
      local_4c = param_3[0x33];
      local_48 = *puVar1;
      Ordinal_1623(param_2,3,puVar1,0xc,2,&local_2c,&local_40);
      Ordinal_1623(param_2,3,&local_50,0xc,2,&local_2c,&local_40);
      param_1 = local_ec[3];
      if (local_d8 != 0) {
        Ordinal_1603(param_2);
        param_1 = local_ec[3];
      }
    }
    else {
      iVar3 = scoreEngine_isXtraEditable(*(undefined4 **)(*(int *)(*(int *)(param_3[0xf] + 0x20) + 4) + 0x20));
      local_ec[0] = (uint)(iVar3 != 0);
      local_ec[1] = 1;
      bitmap_buildSpriteTransform(param_2);
      bitmap_collectSpriteGeometry(param_4);
      media_dispatchSetImageRef(param_3[0xf],(int *)param_3[0x52],&local_d4,local_ec,local_108);
      crt_getMovieApiState(local_108);
      param_1 = local_ec[3];
    }
  }
  local_d8 = 1;
LAB_680e13b5:
  iVar3 = lingo_getMovieRef(*(int *)(param_1 + 0x18));
  if (((iVar3 == 0) && (local_d8 == 0)) || (iVar3 = Ordinal_1041(), iVar3 != 0)) {
    iVar3 = Ordinal_1042();
    if (iVar3 == 0x66) {
      lingo_formatDebugMsg(*(int **)(param_1 + 0x18),-0x7d);
    }
    else {
      rendering_initMemberSlot(local_dc,-0x1b7);
    }
  }
  if (local_ec[2] != 0) {
    rendering_isStateValid((int)local_dc);
  }
  rendering_releaseMemberData(local_dc);
  return 0;
}



// ============================================================
// Function: bitmap_hitTestSpriteXtra (FUN_680e1440)
// Address: 680e1440
// Size: 361 bytes
// Params: int param_1, undefined4 * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_hitTestSpriteXtra(int param_1,undefined4 *param_2,int param_3,int param_4)
{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 local_98;
  int local_94;
  int local_90;
  undefined4 local_8c;
  undefined1 local_88 [88];
  undefined1 local_30;
  undefined4 local_2e;
  undefined4 local_2a;
  undefined4 local_26;
  undefined4 local_22;
  undefined4 local_1e;
  undefined4 local_1a;
  undefined4 local_16;
  undefined4 local_12;
  undefined4 local_e;
  uint local_8;
  
  local_8c = 0;
  memset(local_88,0,0x58);
  local_30 = 0;
  local_2e = 0;
  local_2a = 0;
  local_26 = 0;
  local_22 = 0;
  local_1e = 0;
  local_1a = 0;
  local_16 = 0;
  local_12 = 0;
  local_e = 0;
  local_98 = 0;
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if (piVar2 != (int *)0x0) {
    uVar3 = scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),piVar2,0);
    if (uVar3 != 0) {
      bVar1 = bitmap_validateSpriteData();
      if (CONCAT31(extraout_var,bVar1) != 0) {
        iVar4 = Ordinal_1070(param_2 + 0x32,&param_3);
        if ((iVar4 != 0) && (param_2[0x52] != 0)) {
          bitmap_collectSpriteGeometry(0);
          local_90 = param_3;
          local_94 = param_4;
          iVar4 = playback_getSpriteInfo(param_2[0xf],param_2);
          if (iVar4 != 0) {
            local_94 = local_94 - param_2[0x5d];
            local_90 = local_90 - param_2[0x5c];
          }
          media_dispatchSetSound(param_2[0xf],(int *)param_2[0x52],&local_8c,&local_94,&local_98);
        }
        rendering_isStateValid((int)piVar2);
        return 0;
      }
      rendering_initMemberSlot(piVar2,-0x7b);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_handleSpriteIdle (FUN_680e15b0)
// Address: 680e15b0
// Size: 40 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_handleSpriteIdle(int param_1)
{
  if ((*(byte *)(param_1 + 0x150) & 0x10) != 0) {
    bitmap_getSpriteState(0);
  }
  return 0;
}



// ============================================================
// Function: bitmap_setSpriteProperty (FUN_680e15e0)
// Address: 680e15e0
// Size: 301 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setSpriteProperty(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 1;
  switch(param_3) {
  case 0:
    if ((*(byte *)(param_2 + 0x150) & 1) == 0) {
      return 0;
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    if ((*(byte *)(param_2 + 0x150) & 2) == 0) {
      return 0;
    }
    break;
  case 0xb:
    if ((*(byte *)(param_2 + 0x150) & 4) == 0) {
      return 0;
    }
    if ((*(ushort *)(param_2 + 0x14c) & 0x800) != 0) {
      return 0;
    }
    *(ushort *)(param_2 + 0x14c) = *(ushort *)(param_2 + 0x14c) | 0x800;
    uVar2 = bitmap_getSpriteState(1);
    return uVar2;
  case 0xc:
    if ((*(byte *)(param_2 + 0x150) & 4) == 0) {
      return 0;
    }
    if ((*(ushort *)(param_2 + 0x14c) & 0x800) == 0) {
      return 0;
    }
    *(ushort *)(param_2 + 0x14c) = *(ushort *)(param_2 + 0x14c) & 0xf7ff;
    uVar2 = bitmap_getSpriteState(1);
    return uVar2;
  case 0xd:
    if ((*(byte *)(param_2 + 0x150) & 0x80) == 0) {
      return 0;
    }
    break;
  case 0x10:
  case 0x11:
    if ((*(byte *)(param_2 + 0x150) & 0x20) == 0) {
      return 0;
    }
    break;
  case 0x12:
  case 0x13:
    iVar3 = 0;
    if ((*(byte *)(param_2 + 0x150) & 0x10) == 0) {
      return 0;
    }
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    if ((*(byte *)(param_2 + 0x150) & 8) == 0) {
      return 0;
    }
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
    uVar1 = *(uint *)(param_2 + 0x150) & 0x100;
    goto LAB_680e16f4;
  case 0x21:
    uVar1 = *(uint *)(param_2 + 0x150) & 0x200;
LAB_680e16f4:
    if (uVar1 == 0) {
      return 0;
    }
    iVar3 = 0;
  }
  uVar2 = bitmap_getSpriteState(iVar3);
  return uVar2;
}



// ============================================================
// Function: bitmap_getSpriteEditability (FUN_680e1760)
// Address: 680e1760
// Size: 43 bytes
// Params: undefined4 param_1, int param_2, uint * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_getSpriteEditability(undefined4 param_1,int param_2,uint *param_3)

{
  if (param_3 != (uint *)0x0) {
    *param_3 = ((int)*(short *)(param_2 + 0x14c) & 2U) >> 1;
  }
  return *(uint *)(param_2 + 0x150) >> 2 & 1;
}



// ============================================================
// Function: bitmap_getDirectToStage (FUN_680e1790)
// Address: 680e1790
// Size: 70 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_getDirectToStage(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  iVar3 = 0;
  if (((param_1 != 0) &&
      (iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc), iVar1 != 0)) &&
     (iVar2 = props_resolvePropertyId(iVar1,"directToStage"), iVar3 = local_8, param_2 == iVar2)) {
    props_coerceAndReturnInt(iVar1,param_3,&local_8);
    iVar3 = local_8;
  }
  return iVar3;
}



// ============================================================
// Function: bitmap_getXtraProperty (FUN_680e17e0)
// Address: 680e17e0
// Size: 137 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_getXtraProperty(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = media_getVtableData(*(int *)(param_1 + 0x3c),*(int **)(param_1 + 0x148),param_3,param_4);
  }
  else {
    iVar1 = bitmap_getDirectToStage(*(int *)(param_1 + 0x3c),param_3,param_4);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x124) = 1;
    }
    iVar2 = media_dispatchRenderAt(*(int *)(param_1 + 0x3c),*(int **)(param_1 + 0x148),param_3,param_4);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x124) = 0;
      return iVar2 == 0;
    }
  }
  return iVar2 == 0;
}



// ============================================================
// Function: bitmap_callXtraMethod (FUN_680e1870)
// Address: 680e1870
// Size: 64 bytes
// Params: int param_1, int param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_callXtraMethod(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x148) != (int *)0x0) {
    iVar1 = media_initVtable(*(int *)(param_1 + 0x3c),*(int **)(param_1 + 0x148),param_2);
    if (iVar1 != -0x7ffbf830) goto LAB_680e189a;
  }
  iVar1 = -0x7ffbf821;
LAB_680e189a:
  if (param_3 != (int *)0x0) {
    *param_3 = iVar1;
  }
  return iVar1 == 0;
}



// ============================================================
// Function: bitmap_enumXtraProps (FUN_680e18b0)
// Address: 680e18b0
// Size: 61 bytes
// Params: int param_1, undefined4 * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_enumXtraProps(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (*(undefined4 **)(param_1 + 0x148) != (undefined4 *)0x0) {
    iVar1 = media_queryDrawInterface(*(int *)(param_1 + 0x3c),*(undefined4 **)(param_1 + 0x148),param_2);
    return iVar1 == 0;
  }
  return false;
}



// ============================================================
// Function: bitmap_handleModifierKey (FUN_680e18f0)
// Address: 680e18f0
// Size: 68 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_handleModifierKey(int param_1,uint param_2)
{
  byte bVar1;
  
  bVar1 = (param_2 & 0x20000) != 0;
  if ((param_2 & 0x10000) != 0) {
    bVar1 = bVar1 | 2;
  }
  if ((bVar1 != 0) && ((*(byte *)(param_1 + 0x150) & 0x10) != 0)) {
    bitmap_getSpriteState(0);
  }
  return 0;
}



// ============================================================
// Function: bitmap_checkXtraAutoTab (FUN_680e1940)
// Address: 680e1940
// Size: 103 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_checkXtraAutoTab(int param_1,int param_2)

{
  int iVar1;
  uint local_10 [2];
  int local_8;
  
  local_8 = 0;
  iVar1 = media_getVtableData(param_1,*(int **)(param_2 + 0x148),0x323,local_10);
  if (iVar1 == 0) {
    iVar1 = props_coerceAndReturnInt(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_10,&local_8);
    if (iVar1 == 0) {
      return local_8 == 0;
    }
  }
  return true;
}



// ============================================================
// Function: bitmap_checkXtraPropertyMatch (FUN_680e19b0)
// Address: 680e19b0
// Size: 102 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_checkXtraPropertyMatch(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint local_10 [2];
  int local_8;
  
  local_8 = 0;
  iVar1 = media_getVtableData(param_1,*(int **)(param_2 + 0x148),0x364,local_10);
  if (iVar1 == 0) {
    iVar1 = props_coerceAndReturnInt(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_10,&local_8);
    if ((iVar1 == 0) && (local_8 == param_3)) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_invokeXtraScript (FUN_680e1a20)
// Address: 680e1a20
// Size: 287 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_invokeXtraScript(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24 [2];
  undefined4 local_1c;
  int *local_18;
  int local_14 [2];
  int local_c [2];
  
  iVar2 = param_2;
  local_30 = *(undefined4 *)(param_2 + 0x148);
  local_18 = local_14;
  local_2c = 0;
  local_28 = 0x327;
  local_1c = 2;
  iVar3 = 1;
  props_clearValue(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_24);
  props_clearValue(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_14);
  props_clearValue(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_c);
  iVar1 = cast_resolveScriptProperty(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),
                       *(short *)(iVar2 + 0x40),local_14);
  if (iVar1 == 0) {
    iVar1 = props_storeIntValue(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),param_3,
                         local_c);
    if (iVar1 == 0) {
      iVar2 = media_initVtable(param_1,*(int **)(iVar2 + 0x148),(int)&local_30);
      if (iVar2 == 0) {
        iVar2 = props_coerceAndReturnInt(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_24,
                             &param_2);
        if (iVar2 == 0) {
          iVar3 = param_2;
        }
      }
    }
  }
  props_releaseAndClear(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),(int *)local_24);
  props_releaseAndClear(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_14);
  props_releaseAndClear(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_c);
  return iVar3;
}



// ============================================================
// Function: bitmap_drawSpriteRect (FUN_680e1b40)
// Address: 680e1b40
// Size: 79 bytes
// Params: void * this, undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_drawSpriteRect(void *this,undefined4 *param_1,int param_2)
{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_c = param_1[3];
  Ordinal_1624(this,param_2 == 0,&local_18,5);
  return 0;
}



// ============================================================
// Function: bitmap_drawSpriteBorder (FUN_680e1b90)
// Address: 680e1b90
// Size: 97 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawSpriteBorder(int *param_1)
{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = *param_1;
  local_14 = param_1[1] + 2;
  local_c = param_1[1] + 0xe;
  local_10 = local_18 + 0xc;
  Ordinal_1065(&local_18,1,1);
  Ordinal_1620();
  return 0;
}



// ============================================================
// Function: bitmap_drawSpriteOutline (FUN_680e1c00)
// Address: 680e1c00
// Size: 148 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawSpriteOutline(int param_1)
{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = *(int *)(param_1 + 200);
  local_10 = local_18 + 0xc;
  local_14 = *(int *)(param_1 + 0xcc) + 2;
  local_c = *(int *)(param_1 + 0xcc) + 0xe;
  Ordinal_1065(&local_18,1,1);
  Ordinal_1623();
  return 0;
}



// ============================================================
// Function: bitmap_getSpriteRect (FUN_680e1ca0)
// Address: 680e1ca0
// Size: 105 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getSpriteRect(undefined4 *param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  
  *param_3 = param_1[0x52];
  param_3[1] = param_1[0x53];
  param_3[2] = param_1[0x54];
  param_3[3] = param_1[0x55];
  param_3[2] = param_3[2] - param_1[0x58];
  if (param_2 != 0) {
    iVar1 = playback_getSpriteInfo(param_1[0xf],param_1);
    if (iVar1 != 0) {
      Ordinal_1064(param_3,-param_1[0x5c],-param_1[0x5d]);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_updateSpriteScroll (FUN_680e1d10)
// Address: 680e1d10
// Size: 376 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_updateSpriteScroll(int param_1,undefined4 *param_2,uint param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = lingo_isValidRef(*(int *)(*(int *)(param_1 + 0x20) + 4));
  if ((*(byte *)(param_2 + 0x13) & 0xc0) == 0) {
    return 0;
  }
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = rendering_getMemberData(param_1,piVar2);
  if (iVar3 == 0) {
    return 0;
  }
  if ((*(byte *)(param_2 + 0x13) & 0x40) != 0) {
    if (param_2[0x57] == 0) {
      uVar4 = Ordinal_1871(DAT_681956e0,param_3,0,param_2[0x5a],param_2[0x5b],param_2[0x59],100,0,0)
      ;
      param_2[0x57] = uVar4;
    }
    else {
      Ordinal_1876(param_2[0x57],param_3,param_2[0x5a],param_2[0x5b],param_2[0x59]);
    }
  }
  if (((*(byte *)(param_2 + 0x13) & 0xc0) == 0) || (param_2[0x57] == 0)) {
LAB_680e1e5d:
    if (param_2[0x56] != 0) goto LAB_680e1e74;
  }
  else {
    iVar5 = xtra_drawTextLine(iVar1,piVar2[0x15],0,0x7fff);
    iVar3 = piVar2[0x1e];
    if (iVar3 < iVar5) {
      param_3 = 0;
      xtra_layoutTextBlock(iVar1,piVar2[0x15],0,iVar5 + -1,(int *)0x0,&param_3);
      iVar1 = xtra_drawTextLine(iVar1,piVar2[0x15],param_3,1);
      iVar3 = piVar2[0x1e];
      uVar4 = param_2[0x57];
      iVar5 = (iVar1 - iVar3) + iVar5;
    }
    else {
      uVar4 = param_2[0x57];
      iVar5 = 0;
    }
    Ordinal_1874(uVar4,iVar5,iVar3);
    Ordinal_1875(param_2[0x57],piVar2[0x19]);
    if (param_2[0x56] != 0) {
      Ordinal_1873(param_2[0x57],1);
      goto LAB_680e1e5d;
    }
  }
  Ordinal_1873(param_2[0x57],0);
LAB_680e1e74:
  param_2[0x13] = param_2[0x13] & 0xffffff3f;
  rendering_isStateValid((int)piVar2);
  return 0;
}



// ============================================================
// Function: bitmap_setupSpriteText (FUN_680e1e90)
// Address: 680e1e90
// Size: 305 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setupSpriteText(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar2 == (int *)0x0) || ((piVar2[2] != 3 && (piVar2[2] != 7)))) {
    return 0;
  }
  param_2[0x18] = 3;
  iVar3 = rendering_getMemberData(param_1,piVar2);
  if (iVar3 == 0) {
    scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),piVar2,1);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (((*(int *)(iVar1 + 0x63c) != 0) && (*(int *)(iVar1 + 0x644) == param_2[0x10])) &&
     (*(int *)(iVar1 + 0x640) == param_2[0xf])) {
    if ((*(byte *)(param_2 + 0x16) & 0x10) == 0) {
      Ordinal_1839(*(undefined4 *)(*(int *)(iVar1 + 4) + 0x28),0);
      Ordinal_1130(*(int *)(param_1 + 0x20) + 0x638,0x10);
    }
    else {
      *(undefined4 *)(iVar1 + 0x638) = 1;
    }
  }
  playback_renderSpriteData(param_1,param_2,1);
  param_2[0x17] = param_2[0x17] & 0xfffffffe;
  param_2[0x4d] = 0x1ffffff;
  playback_renderSprite((int)param_2,(int)piVar2,0);
  if ((*(byte *)(param_2 + 0x14) & 2) == 0) {
    iVar1 = param_2[0x58];
    if (iVar1 < 1) goto LAB_680e1f88;
    if ((param_3 & 0xffffffa7) != 0) {
      param_2[0x13] = param_2[0x13] | 0x40;
      param_2[0x13] = param_2[0x13] | 0x80;
    }
  }
  else {
    playback_getSpriteBounds(param_1,param_2);
  }
  iVar1 = param_2[0x58];
LAB_680e1f88:
  if ((iVar1 == 0) && (param_2[0x57] != 0)) {
    playback_getSpriteBounds(param_1,param_2);
  }
  param_2[0x13] = param_2[0x13] | 3;
  if (iVar3 != 0) {
    rendering_isStateValid((int)piVar2);
  }
  return 1;
}



// ============================================================
// Function: bitmap_teardownSpriteText (FUN_680e1fd0)
// Address: 680e1fd0
// Size: 190 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_teardownSpriteText(int param_1,undefined4 *param_2)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  iVar1 = *(int *)(param_1 + 0x20);
  if (((*(int *)(iVar1 + 0x63c) != 0) && (*(int *)(iVar1 + 0x644) == param_2[0x10])) &&
     (*(int *)(iVar1 + 0x640) == param_2[0xf])) {
    Ordinal_1839(*(undefined4 *)(*(int *)(iVar1 + 4) + 0x28),0);
    Ordinal_1130(*(int *)(param_1 + 0x20) + 0x638,0x10);
    Ordinal_66(*(int *)(*(int *)(param_1 + 0x20) + 8),1);
    rendering_setMemberData(param_1,piVar2,0x10);
  }
  if (((piVar2 != (int *)0x0) && (piVar2[2] == 3)) &&
     ((piVar2[0x23] != 0 && ((-1 < piVar2[0x21] && (-1 < piVar2[0x22])))))) {
    Ordinal_66(*(int *)(*(int *)(param_1 + 0x20) + 8),1);
    rendering_setMemberData(param_1,piVar2,0x10);
  }
  bitmap_getMovieStageRef(param_1,(int)piVar2);
  playback_getSpriteBounds(param_1,param_2);
  return 0;
}



// ============================================================
// Function: bitmap_drawSpriteOverlay (FUN_680e2090)
// Address: 680e2090
// Size: 197 bytes
// Params: int param_1, void * param_2, undefined4 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_drawSpriteOverlay(int param_1,void *param_2,undefined4 *param_3,int param_4)
{
  undefined4 uVar1;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_3[0x32];
  local_14 = param_3[0x33];
  local_10 = param_3[0x34];
  local_c = param_3[0x35];
  uVar1 = playback_getSpriteProperty(param_1,param_3);
  switch(uVar1) {
  case 7:
    Ordinal_1621(param_2,&local_18);
    return 0;
  case 8:
    bitmap_drawSpriteRect(param_2,&local_18,param_4);
    return 0;
  case 9:
    bitmap_drawSpriteBorder(&local_18);
    return 0;
  case 10:
    bitmap_drawSpriteOutline((int)param_3);
  }
  return 0;
}



