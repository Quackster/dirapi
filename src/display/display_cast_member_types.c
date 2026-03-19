// Module: display
// Topic: Cast member type handlers for OLE, bitmap, and media types
// Address range: 0x680f26c0 - 0x680f55b0
// Functions (47):
//   display_getOleCastProperty
//   display_setOleCastProperty
//   display_dispatchOleCastOp
//   display_getOleData
//   display_storeOleHandle
//   display_loadOleData
//   display_dispatchOleMemberOp
//   display_initBitmapDefaults
//   display_validateBitmapResource
//   display_loadBitmapResource
//   display_resolveBitmapResource
//   display_loadAllBitmapResources
//   display_readBitmapStream
//   display_writeBitmapStream
//   display_calcBitmapResourceSize
//   display_renderBitmapToSurface
//   display_convertBitmapData
//   display_createBitmapThumbnail
//   display_getBitmapMemberProperty
//   display_setBitmapMemberProperty
//   display_scrollBitmapMember
//   display_dispatchBitmapCastOp
//   display_reportMediaFormatError
//   display_isMediaDataChanged
//   display_applyMediaDataChange
//   display_invokeMediaCallback
//   display_loadMediaContent
//   display_storeMediaMemberData
//   display_getSoundMemberProperty
//   display_setSoundMemberProperty
//   display_handleSoundCueEvent
//   display_dispatchSoundCastOp
//   display_initShapeMemberBounds
//   display_invalidateShapeSprites
//   display_previewShapeMember
//   display_readShapeStream
//   display_writeShapeStream
//   display_resolveShapeSpriteImage
//   display_getShapeMemberProperty
//   display_setShapeMemberProperty
//   display_dispatchShapeCastOp
//   display_initMovieMember
//   display_releaseMovieMember
//   display_resetMovieMemberFields
//   display_writeMovieStream
//   display_getPaletteMemberProperty
//   display_setPaletteMemberProperty


// ============================================================
// Function: display_getOleCastProperty (FUN_680f26c0)
// Address: 680f26c0
// Size: 141 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_getOleCastProperty(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = *param_2;
  puVar2 = (uint *)param_2[4];
  if (*(int *)(iVar1 + 8) == 0xe) {
    switch(param_2[3]) {
    case 0x30:
      *puVar2 = (int)*(short *)(iVar1 + 0x84);
      return 1;
    case 0x4d:
      *puVar2 = (int)*(char *)(iVar1 + 0x82);
      return 1;
    case 0x4e:
      *puVar2 = ~(int)*(char *)(iVar1 + 0x83) & 1;
      return 1;
    case 0x4f:
      *puVar2 = (uint)*(byte *)(iVar1 + 0x81);
      return 1;
    case 0x50:
      *puVar2 = ((int)*(char *)(iVar1 + 0x83) & 2U) >> 1;
      return 1;
    }
  }
  Ordinal_1130(puVar2,0x18);
  return 0;
}



// ============================================================
// Function: display_setOleCastProperty (FUN_680f2790)
// Address: 680f2790
// Size: 244 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_setOleCastProperty(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar1 = (int *)*param_2;
  piVar2 = (int *)param_2[4];
  uVar5 = 0;
  iVar3 = param_2[1];
  if (piVar1[2] == 0xe) {
    switch(param_2[3]) {
    case 0x30:
      iVar4 = *piVar2;
      *(short *)(piVar1 + 0x21) = (short)iVar4;
      if ((short)iVar4 < 0) {
        *(undefined2 *)(piVar1 + 0x21) = 0;
      }
      if (32000 < (short)piVar1[0x21]) {
        *(undefined2 *)(piVar1 + 0x21) = 32000;
        rendering_setMemberData(iVar3,piVar1,1);
        return 1;
      }
      break;
    default:
      goto switchD_680f27bc_caseD_31;
    case 0x4d:
      *(char *)((int)piVar1 + 0x82) = (char)*piVar2;
      rendering_setMemberData(iVar3,piVar1,1);
      return 1;
    case 0x4e:
      if (*piVar2 != 0) {
        *(byte *)((int)piVar1 + 0x83) = *(byte *)((int)piVar1 + 0x83) & 0xfe;
        rendering_setMemberData(iVar3,piVar1,1);
        return 1;
      }
      *(byte *)((int)piVar1 + 0x83) = *(byte *)((int)piVar1 + 0x83) | 1;
      break;
    case 0x4f:
      iVar4 = *piVar2;
      *(char *)((int)piVar1 + 0x81) = (char)iVar4;
      if ((char)iVar4 == '\0') {
        *(undefined1 *)((int)piVar1 + 0x81) = 1;
      }
      if (0x80 < *(byte *)((int)piVar1 + 0x81)) {
        *(undefined1 *)((int)piVar1 + 0x81) = 0x80;
        rendering_setMemberData(iVar3,piVar1,1);
        return 1;
      }
    }
    rendering_setMemberData(iVar3,piVar1,1);
    uVar5 = 1;
  }
switchD_680f27bc_caseD_31:
  return uVar5;
}



// ============================================================
// Function: display_dispatchOleCastOp (FUN_680f28c0)
// Address: 680f28c0
// Size: 382 bytes
// Params: void * this, int * param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall display_dispatchOleCastOp(void *this,int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar3 = *param_1;
  bVar1 = *(byte *)(iVar3 + 0x83);
  uVar4 = CONCAT31((int3)((uint)this >> 8),bVar1);
  bVar5 = (bVar1 & 2) != 0;
  switch(param_1[2]) {
  case 0:
    if (param_1[3] == 0) {
      *(undefined2 *)(iVar3 + 0x82) = 0x301;
      iVar3 = rendering_validateState(param_1);
      goto LAB_680f2958;
    }
    break;
  default:
    goto switchD_680f28f0_caseD_1;
  case CMTYPE_TEXT_FIELD:
  case CMTYPE_PICTURE:
  case CMTYPE_SOUND:
  case CMTYPE_BUTTON:
  case CMTYPE_SHAPE:
  case CMTYPE_MOVIE:
  case CMTYPE_DIGITAL_VIDEO:
  case CMTYPE_SCRIPT:
  case CMTYPE_TEXT_RICH:
    if (bVar5) {
      if (param_1[2] != 10) {
        return 1;
      }
      param_1[3] = 0;
      return 1;
    }
    break;
  case CMTYPE_XTRA:
    display_readStreamAttribs();
    if ((*(byte *)(iVar3 + 0x83) & 2) != 0) {
      return 1;
    }
    if (bVar5) {
      return 1;
    }
    break;
  case CMTYPE_SWA:
    display_writeStreamAttribs();
    if (bVar5) {
      return 1;
    }
    break;
  case CMTYPE_VECTOR:
    if (bVar5) {
      param_1[3] = 0;
      return 1;
    }
    break;
  case CMTYPE_FLASH:
  case 0x1e:
    if (bVar5) {
      return 1;
    }
    break;
  case 0x19:
    iVar3 = display_getOleCastProperty(uVar4,param_1);
    if (iVar3 != 0) {
      return 1;
    }
switchD_680f28f0_caseD_1:
    if (bVar5) {
LAB_680f2993:
      iVar3 = rendering_validateState(param_1);
      goto LAB_680f2958;
    }
    break;
  case 0x1a:
    iVar3 = display_setOleCastProperty(uVar4,param_1);
    if (iVar3 != 0) {
      return 1;
    }
    goto LAB_680f2993;
  case 0x1d:
    iVar2 = param_1[3];
    if (bVar5) {
      if (*(char *)(iVar3 + 0x80) != *(char *)(iVar2 + 0x80)) {
        return 1;
      }
      if (*(char *)(iVar3 + 0x81) != *(char *)(iVar2 + 0x81)) {
        return 1;
      }
      if (*(char *)(iVar3 + 0x82) != *(char *)(iVar2 + 0x82)) {
        return 1;
      }
      if (bVar1 != *(byte *)(iVar2 + 0x83)) {
        return 1;
      }
      if (*(short *)(iVar3 + 0x84) != *(short *)(iVar2 + 0x84)) {
        return 1;
      }
      param_1[4] = 1;
      return 1;
    }
  }
  iVar3 = playback_dispatchMemberOp(param_1);
LAB_680f2958:
  if (iVar3 != 0) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_getOleData (FUN_680f2a90)
// Address: 680f2a90
// Size: 100 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getOleData(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 *unaff_EDI;
  
  if (unaff_EDI[0x25] != 0) {
    uVar1 = Ordinal_1116(unaff_EDI[0x25]);
    if (unaff_EBX == 0) {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = uVar1;
      }
    }
    else {
      Ordinal_1114(unaff_EDI[0x25]);
      iVar2 = Ordinal_1420();
      Ordinal_1115(unaff_EDI[0x25]);
      if (iVar2 == 0) goto LAB_680f2ad2;
    }
    return 1;
  }
LAB_680f2ad2:
  rendering_initMemberSlot(unaff_EDI,-0x79);
  return 0;
}



// ============================================================
// Function: display_storeOleHandle (FUN_680f2b00)
// Address: 680f2b00
// Size: 38 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_storeOleHandle(undefined4 param_1)

{
  int iVar1;
  undefined4 *unaff_EDI;
  
  iVar1 = Ordinal_1439(param_1);
  if (iVar1 != 0) {
    unaff_EDI[0x25] = iVar1;
    return 1;
  }
  rendering_initMemberSlot(unaff_EDI,-0x7b);
  return 0;
}



// ============================================================
// Function: display_loadOleData (FUN_680f2b30)
// Address: 680f2b30
// Size: 95 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_loadOleData(void)

{
  int *in_EAX;
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (in_EAX[0x25] != 0) {
    return 1;
  }
  local_8 = 0;
  iVar1 = rendering_updateMemberState(in_EAX,FOURCC_OLED,&local_c,&local_8,(int *)0x0);
  if (iVar1 == 1) {
    display_storeOleHandle(local_8);
    Ordinal_1407(&local_8);
    if (in_EAX[0x25] != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: display_dispatchOleMemberOp (FUN_680f2b90)
// Address: 680f2b90
// Size: 330 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

int * display_dispatchOleMemberOp(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  piVar4 = param_1;
  iVar2 = *param_1;
  uVar3 = *(undefined4 *)(iVar2 + 8);
  piVar1 = param_1 + 2;
  param_1 = (int *)0x0;
  switch(*piVar1) {
  case 3:
    if (*(int *)(iVar2 + 0x94) != 0) {
      iVar5 = Ordinal_1120(*(int *)(iVar2 + 0x94),0);
      *(int *)(iVar2 + 0x94) = iVar5;
      goto LAB_680f2bd9;
    }
    break;
  case 6:
    if (piVar4[5] == FOURCC_BITD) break;
    iVar5 = display_storeOleHandle(piVar4[4]);
    goto LAB_680f2bea;
  case 7:
    if (piVar4[5] != FOURCC_OLED) break;
    iVar5 = display_loadOleData();
    if (iVar5 == 0) goto LAB_680f2bf5;
    iVar5 = display_getOleData((undefined4 *)piVar4[6]);
    goto LAB_680f2bea;
  case 8:
    Ordinal_1113(iVar2 + 0x94);
    break;
  case 0xb:
    iVar5 = display_loadOleData();
    if (iVar5 == 0) goto LAB_680f2bf5;
    iVar5 = Ordinal_2008(*(undefined4 *)(iVar2 + 0x94),0x3ee);
LAB_680f2bd9:
    if (iVar5 == 0) goto LAB_680f2bf5;
    break;
  case 0xc:
    uVar6 = Ordinal_2002(0x3ee);
    *(undefined4 *)(iVar2 + 0x94) = uVar6;
    break;
  case 0x12:
    piVar4[3] = 2;
    iVar5 = rendering_validateState(piVar4);
    goto LAB_680f2bea;
  case 0x13:
    piVar1 = piVar4 + 4;
    iVar5 = crt_negotiateFormat(piVar1,piVar4[3],FOURCC_BITD);
    piVar4[3] = iVar5;
    iVar5 = crt_findInSortedArray((undefined4 *)*piVar1,iVar5,FOURCC_ediM);
    if (iVar5 == 0) {
      iVar5 = crt_negotiateFormat(piVar1,piVar4[3],FOURCC_OLED);
      piVar4[3] = iVar5;
    }
    iVar5 = rendering_validateState(piVar4);
    goto LAB_680f2bea;
  case 0x18:
    goto switchD_680f2bba_caseD_18;
  }
  *(undefined4 *)(iVar2 + 8) = 1;
  iVar5 = rendering_dispatchMemberProperty(piVar4);
LAB_680f2bea:
  if (iVar5 != 0) {
switchD_680f2bba_caseD_18:
    param_1 = (int *)0x1;
  }
LAB_680f2bf5:
  *(undefined4 *)(iVar2 + 8) = uVar3;
  return param_1;
}



// ============================================================
// Function: display_initBitmapDefaults (FUN_680f2d20)
// Address: 680f2d20
// Size: 134 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_initBitmapDefaults(void)
{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(undefined4 *)(unaff_ESI + 0xa0) = 0;
  Ordinal_1060(unaff_ESI + 0x54,0,0,0x168,0x14);
  Ordinal_1060(unaff_ESI + 100,0,0,0x168,0x14);
  *(undefined1 *)(unaff_ESI + 0x74) = 1;
  *(undefined4 *)(unaff_ESI + 0x7c) = 0xc;
  *(undefined4 *)(unaff_ESI + 0x80) = 0x14;
  *(undefined4 *)(unaff_ESI + 0x94) = 0x168;
  *(undefined4 *)(unaff_ESI + 0x98) = 0x14;
  *(undefined4 *)(unaff_ESI + 0x9c) = 4;
  *(undefined4 *)(unaff_ESI + 0x84) = 0x1000000;
  *(undefined4 *)(unaff_ESI + 0x88) = 0x1ffffff;
  return 0;
}




// ============================================================
// Function: display_validateBitmapResource (FUN_680f2db0)
// Address: 680f2db0
// Size: 166 bytes
// Params: undefined4 * param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_validateBitmapResource(undefined4 *param_1,int param_2,int *param_3)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  if ((param_1 == (undefined4 *)0x0) || (param_1[2] != 0xc)) {
LAB_680f2e23:
    local_8 = 0;
    puVar3 = (undefined4 *)0xffffff87;
  }
  else {
    if (in_EAX == FOURCC_RTE0) {
      uVar4 = param_1[0x23];
LAB_680f2dee:
      iVar5 = Ordinal_1116(uVar4);
      if ((param_2 != 0) && (iVar5 != 0)) {
        uVar1 = Ordinal_1114(uVar4);
        iVar2 = Ordinal_1420(param_2,uVar1,iVar5);
        Ordinal_1115(uVar4);
        if (iVar2 == 0) goto LAB_680f2e23;
      }
    }
    else {
      if (in_EAX == FOURCC_RTE1) {
        uVar4 = param_1[0x24];
        goto LAB_680f2dee;
      }
      if (in_EAX == FOURCC_RTE2) {
        uVar4 = param_1[0x28];
        goto LAB_680f2dee;
      }
    }
    local_8 = 1;
    puVar3 = param_1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar5;
  }
  if (local_8 == 0) {
    rendering_initMemberSlot(param_1,(int)puVar3);
  }
  return local_8;
}



// ============================================================
// Function: display_loadBitmapResource (FUN_680f2e60)
// Address: 680f2e60
// Size: 278 bytes
// Params: void * this, int param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall display_loadBitmapResource(void *this,int param_1)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 *unaff_ESI;
  int iVar3;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (unaff_ESI == (undefined4 *)0x0) goto LAB_680f2f29;
  if (unaff_ESI[2] != 0xc) goto LAB_680f2f29;
  if (param_1 == FOURCC_RTE2) {
    unaff_ESI[0x25] = 0;
    unaff_ESI[0x26] = 0;
    unaff_ESI[0x27] = 0;
  }
  if (this == (void *)0x0) {
    local_8 = 0;
  }
  else {
    local_8 = Ordinal_1439();
    if (local_8 == 0) {
      iVar3 = -0x7b;
      while( true ) {
        Ordinal_1113(&local_8);
        rendering_initMemberSlot(unaff_ESI,iVar3);
LAB_680f2f18:
        if (param_1 == FOURCC_RTE0) {
          unaff_ESI[0x23] = local_8;
          return local_c;
        }
        if (param_1 == FOURCC_RTE1) {
          unaff_ESI[0x24] = local_8;
          return local_c;
        }
        if (param_1 == FOURCC_RTE2) break;
LAB_680f2f29:
        iVar3 = -0x79;
      }
      unaff_ESI[0x28] = local_8;
      return local_c;
    }
    if (param_1 == FOURCC_RTE2) {
      if (this < (void *)0x6) goto LAB_680f2f29;
      puVar2 = (undefined1 *)Ordinal_1114(local_8);
      sVar1 = xtra_readBE16(puVar2);
      unaff_ESI[0x25] = (int)sVar1;
      sVar1 = xtra_readBE16(puVar2 + 2);
      unaff_ESI[0x26] = (int)sVar1;
      sVar1 = xtra_readBE16(puVar2 + 4);
      unaff_ESI[0x27] = (int)sVar1;
      Ordinal_1115(local_8);
    }
  }
  local_c = 1;
  goto LAB_680f2f18;
}



// ============================================================
// Function: display_resolveBitmapResource (FUN_680f2f80)
// Address: 680f2f80
// Size: 92 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_resolveBitmapResource(int param_1)

{
  int *in_EAX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_EDI;
  
  iVar3 = 0;
  uVar2 = 0;
  if ((unaff_EDI != (undefined4 *)0x0) && (unaff_EDI[2] == 0xc)) {
    iVar1 = display_validateBitmapResource(unaff_EDI,param_1,in_EAX);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_680f2fac;
    }
  }
  iVar3 = -0x1c2;
LAB_680f2fac:
  iVar1 = Ordinal_1042();
  if (iVar1 != 0) {
    rendering_initMemberSlot(unaff_EDI,-0x7b);
    return uVar2;
  }
  if (iVar3 != 0) {
    rendering_initMemberSlot(unaff_EDI,iVar3);
  }
  return uVar2;
}



// ============================================================
// Function: display_loadAllBitmapResources (FUN_680f2fe0)
// Address: 680f2fe0
// Size: 231 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_loadAllBitmapResources(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  void *local_c;
  int local_8;
  
  if ((in_EAX != (int *)0x0) && (in_EAX[2] == 0xc)) {
    if ((in_EAX[0x23] != 0) || ((in_EAX[0x24] != 0 || (in_EAX[0x28] != 0)))) {
LAB_680f30b5:
      in_EAX[0xb] = in_EAX[0xb] | 0x200;
      return 1;
    }
    iVar2 = FOURCC_RTE0;
    while( true ) {
      local_8 = 0;
      iVar1 = rendering_updateMemberState(in_EAX,iVar2,(int *)&local_c,&local_8,(int *)0x0);
      if (iVar1 != 1) break;
      if (local_8 == 0) goto LAB_680f30b5;
      iVar1 = display_loadBitmapResource(local_c,iVar2);
      if (iVar1 == 0) {
        Ordinal_1407(&local_8);
        break;
      }
      Ordinal_1407(&local_8);
      if (iVar2 == FOURCC_RTE0) {
        iVar2 = FOURCC_RTE1;
      }
      else {
        if (iVar2 != FOURCC_RTE1) goto LAB_680f30b5;
        iVar2 = FOURCC_RTE2;
      }
    }
  }
  Ordinal_1113(in_EAX + 0x23);
  Ordinal_1113(in_EAX + 0x24);
  Ordinal_1113(in_EAX + 0x28);
  return 0;
}



// ============================================================
// Function: display_readBitmapStream (FUN_680f30d0)
// Address: 680f30d0
// Size: 279 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_readBitmapStream(void)
{
  undefined1 uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  uint uVar6;
  undefined4 uVar7;
  int unaff_EDI;
  
  sVar2 = Ordinal_1412();
  sVar3 = Ordinal_1412();
  sVar4 = Ordinal_1412();
  sVar5 = Ordinal_1412();
  Ordinal_1060(unaff_EDI + 0x54,(int)sVar3,(int)sVar2,(int)sVar5,(int)sVar4);
  sVar2 = Ordinal_1412();
  sVar3 = Ordinal_1412();
  sVar4 = Ordinal_1412();
  sVar5 = Ordinal_1412();
  Ordinal_1060(unaff_EDI + 100,(int)sVar3,(int)sVar2,(int)sVar5,(int)sVar4);
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_EDI + 0x74) = uVar1;
  uVar1 = Ordinal_1411();
  *(undefined1 *)(unaff_EDI + 0x75) = uVar1;
  uVar6 = Ordinal_1413();
  *(uint *)(unaff_EDI + 0x78) = uVar6 & 0xffff;
  uVar6 = Ordinal_1413();
  *(uint *)(unaff_EDI + 0x7c) = uVar6 & 0xffff;
  uVar6 = Ordinal_1413();
  *(uint *)(unaff_EDI + 0x80) = uVar6 & 0xffff;
  *(undefined1 *)(unaff_EDI + 0x87) = 1;
  uVar7 = Ordinal_1415();
  *(char *)(unaff_EDI + 0x84) = (char)((uint)uVar7 >> 0x10);
  *(char *)(unaff_EDI + 0x85) = (char)((uint)uVar7 >> 8);
  *(char *)(unaff_EDI + 0x86) = (char)uVar7;
  *(undefined1 *)(unaff_EDI + 0x8b) = 1;
  Ordinal_1413();
  *(undefined1 *)(unaff_EDI + 0x88) = extraout_AH;
  Ordinal_1413();
  *(undefined1 *)(unaff_EDI + 0x89) = extraout_AH_00;
  Ordinal_1413();
  *(undefined1 *)(unaff_EDI + 0x8a) = extraout_AH_01;
  return 0;
}



// ============================================================
// Function: display_writeBitmapStream (FUN_680f31f0)
// Address: 680f31f0
// Size: 277 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_writeBitmapStream(void)
{
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1422();
  Ordinal_1422();
  Ordinal_1424();
  Ordinal_1424();
  Ordinal_1424();
  Ordinal_1426();
  Ordinal_1424();
  Ordinal_1424();
  Ordinal_1424();
  return 0;
}



// ============================================================
// Function: display_calcBitmapResourceSize (FUN_680f3310)
// Address: 680f3310
// Size: 137 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_calcBitmapResourceSize(void)

{
  int iVar1;
  int *unaff_ESI;
  int local_c;
  int local_8;
  
  if ((unaff_ESI[0xb] & 0x200U) != 0) {
    local_8 = Ordinal_1116(unaff_ESI[0x23]);
    iVar1 = Ordinal_1116(unaff_ESI[0x24]);
    local_8 = local_8 + iVar1;
    iVar1 = Ordinal_1116(unaff_ESI[0x28]);
    return iVar1 + local_8;
  }
  rendering_updateMemberState(unaff_ESI,FOURCC_RTE0,&local_8,(undefined4 *)0x0,(int *)0x0);
  rendering_updateMemberState(unaff_ESI,FOURCC_RTE1,&local_c,(undefined4 *)0x0,(int *)0x0);
  local_8 = local_8 + local_c;
  rendering_updateMemberState(unaff_ESI,FOURCC_RTE2,&local_c,(undefined4 *)0x0,(int *)0x0);
  return local_8 + local_c;
}



// ============================================================
// Function: display_renderBitmapToSurface (FUN_680f33a0)
// Address: 680f33a0
// Size: 474 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_renderBitmapToSurface(int param_1,int param_2,int *param_3)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_6c [6];
  int local_54;
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
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  *param_3 = 0;
  local_6c[0] = 0;
  local_44 = 0;
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xb8);
  iVar4 = 0;
  bVar1 = false;
  if (iVar3 == 0) {
    return 0;
  }
  iVar2 = Ordinal_1606(iVar3,&local_44);
  if (iVar2 == 0) {
    bVar1 = false;
  }
  else {
    local_6c[0] = Ordinal_1600();
    if (local_6c[0] == 0) goto LAB_680f3567;
    iVar4 = Ordinal_1650(local_30,local_2c,local_28,*(undefined4 *)(param_2 + 0x94),
                         *(undefined4 *)(param_2 + 0x98),1);
    if (((iVar4 != 0) && (iVar2 = Ordinal_1604(local_6c[0],iVar4), iVar2 != 0)) &&
       (iVar3 = Ordinal_1613(local_6c[0],0,iVar3), iVar3 != 0)) {
      Ordinal_1060(&local_18,0,0,*(undefined4 *)(param_2 + 0x94),*(undefined4 *)(param_2 + 0x98));
      local_54 = local_18;
      local_50 = local_14;
      local_4c = local_10;
      local_48 = local_c;
      Ordinal_1619(local_6c[0],&local_18,param_2 + 0x88);
      local_6c[1] = 4;
      local_6c[2] = 0x100;
      iVar3 = media_executeBlitOp(local_6c[0],&local_18,(undefined1 *)0x0,&local_54,
                           *(undefined4 *)(param_2 + 0xa0),local_6c + 1,
                           (undefined4 *)(param_2 + 0x84));
      if (iVar3 != 0) {
        bVar1 = true;
      }
    }
  }
  if (local_6c[0] != 0) {
    Ordinal_1604(local_6c[0],0);
    Ordinal_1609(local_6c[0],0);
    Ordinal_1611(local_6c[0],0);
    Ordinal_1601(local_6c);
  }
  if (bVar1) {
    *param_3 = iVar4;
    return 0;
  }
LAB_680f3567:
  return 0;
}



// ============================================================
// Function: display_convertBitmapData (FUN_680f3580)
// Address: 680f3580
// Size: 299 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_convertBitmapData(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  int local_c;
  int local_8;
  
  iVar2 = *unaff_EDI;
  piVar1 = (int *)unaff_EDI[3];
  local_c = 0;
  if (*piVar1 == 2) {
    if ((piVar1[1] == 2) || (piVar1[1] == 6)) {
      local_8 = Ordinal_1610(*(undefined4 *)(*(int *)(*(int *)(unaff_EDI[1] + 0x20) + 4) + 0xb8));
      iVar2 = display_renderBitmapToSurface(*(int *)(unaff_EDI[1] + 0x20),iVar2,&local_c);
      if (iVar2 != 0) {
        iVar2 = Ordinal_1668(local_c,local_8);
        piVar1[2] = iVar2;
        piVar1[3] = 1;
        piVar1[4] = 0;
      }
      Ordinal_1653(&local_c);
      unaff_EDI[4] = 0;
      return 1;
    }
  }
  else {
    if (*piVar1 != 6) {
      unaff_EDI[4] = 2;
      return 0;
    }
    if (piVar1[1] == 0) {
      local_8 = Ordinal_1120(*(undefined4 *)(iVar2 + 0x90),0);
      if (local_8 == 0) {
        iVar2 = Ordinal_1111(1,1);
        piVar1[2] = iVar2;
        unaff_EDI[4] = 0;
        return 1;
      }
      iVar2 = Ordinal_1116(local_8);
      Ordinal_1117(&local_8,iVar2 + 1,0);
      iVar3 = Ordinal_1114(local_8);
      *(undefined1 *)(iVar3 + iVar2) = 0;
      Ordinal_1115(local_8);
      piVar1[2] = local_8;
      unaff_EDI[4] = 0;
      return 1;
    }
  }
  unaff_EDI[4] = 3;
  return 0;
}



// ============================================================
// Function: display_createBitmapThumbnail (FUN_680f36b0)
// Address: 680f36b0
// Size: 132 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall display_createBitmapThumbnail(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  int local_c;
  int local_8;
  
  iVar3 = 0;
  local_c = 0;
  local_8 = 0;
  iVar1 = display_renderBitmapToSurface(unaff_EDI,param_2,&local_c);
  if (iVar1 != 0) {
    iVar3 = Ordinal_1111(0,0);
    if (iVar3 != 0) {
      iVar1 = Ordinal_1404(&local_8,iVar3,3);
      if (iVar1 != 0) {
        uVar2 = Ordinal_1610(*(undefined4 *)(*(int *)(unaff_EDI + 4) + 0xb8),FOURCC_PICH,0);
        Ordinal_1660(local_8,local_c,uVar2);
      }
    }
  }
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  if (local_c != 0) {
    Ordinal_1653(&local_c);
  }
  return iVar3;
}



// ============================================================
// Function: display_getBitmapMemberProperty (FUN_680f3740)
// Address: 680f3740
// Size: 270 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getBitmapMemberProperty(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_EAX;
  int iVar3;
  undefined4 extraout_ECX;
  
  piVar1 = (int *)in_EAX[4];
  piVar2 = (int *)*in_EAX;
  if (piVar2[2] != 0xc) {
switchD_680f376b_caseD_6:
    Ordinal_1130(piVar1,0x18);
    return 0;
  }
  switch(in_EAX[3]) {
  case CMTYPE_PICTURE:
    Ordinal_1060(piVar1,0,0,piVar2[0x25],piVar2[0x26]);
    return 1;
  default:
    goto switchD_680f376b_caseD_6;
  case CMTYPE_TRANSITION:
    iVar3 = rendering_getMemberData(in_EAX[1],piVar2);
    if (iVar3 != 0) {
      iVar3 = display_createBitmapThumbnail(extraout_ECX,(int)piVar2);
      *piVar1 = iVar3;
      rendering_isStateValid((int)piVar2);
      if (*piVar1 == 0) goto switchD_680f376b_caseD_6;
    }
    break;
  case 0x31:
    iVar3 = rendering_getMemberData(in_EAX[1],piVar2);
    if ((iVar3 != 0) && (iVar3 = piVar2[0x24], iVar3 != 0)) {
      *piVar1 = iVar3;
      iVar3 = Ordinal_1116(iVar3);
      piVar1[1] = iVar3;
      rendering_isStateValid((int)piVar2);
      return 1;
    }
    iVar3 = Ordinal_1111(1,1);
    *piVar1 = iVar3;
    piVar1[1] = 0;
    return 1;
  case 0x32:
    *piVar1 = piVar2[0x1e];
    return 1;
  case 0x33:
    *piVar1 = piVar2[0x20];
    return 1;
  case 0x62:
    *piVar1 = piVar2[0x22];
    return 1;
  case 0x6c:
    *piVar1 = piVar2[0x21];
  }
  return 1;
}



// ============================================================
// Function: display_setBitmapMemberProperty (FUN_680f38e0)
// Address: 680f38e0
// Size: 51 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_setBitmapMemberProperty(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)*param_1;
  uVar3 = 0;
  iVar2 = param_1[1];
  if (piVar1[2] == 0xc) {
    if (param_1[3] != 0x31) {
      if (param_1[3] != 0x32) {
        return 0;
      }
      piVar1[0x1e] = *(int *)param_1[4];
    }
    rendering_setMemberData(iVar2,piVar1,1);
    uVar3 = 1;
  }
  return uVar3;
}



// ============================================================
// Function: display_scrollBitmapMember (FUN_680f3920)
// Address: 680f3920
// Size: 201 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_scrollBitmapMember(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int *unaff_EDI;
  
  iVar3 = 0;
  if ((unaff_EDI[2] == 0xc) && (iVar1 = rendering_getMemberData(param_1,unaff_EDI), iVar1 != 0)) {
    iVar2 = unaff_EDI[0x18] - unaff_EDI[0x16];
    iVar1 = unaff_EDI[0x1e];
    switch(param_2) {
    case 0:
      if (param_3 == 1) {
        iVar3 = unaff_EBX * -0xc;
      }
      else {
        iVar3 = unaff_EBX * 0xc;
      }
      break;
    case 1:
      iVar3 = unaff_EDI[0x20] * unaff_EBX;
      if (param_3 == 1) {
        iVar3 = -iVar3;
        if (iVar3 < -1) {
          iVar3 = iVar3 + 1;
        }
      }
      else if (1 < iVar3) {
        iVar3 = iVar3 + -1;
      }
      break;
    case 2:
      if (param_3 == 1) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar2 + -1;
      }
      break;
    default:
      goto switchD_680f3961_caseD_3;
    case 5:
      iVar1 = unaff_EBX;
    }
    iVar1 = iVar1 + iVar3;
    if (iVar1 < iVar2) {
      if (iVar1 < 0) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = iVar2 + -1;
    }
    unaff_EDI[0x1e] = iVar1;
    rendering_setMemberData(param_1,unaff_EDI,0x10);
    rendering_isStateValid((int)unaff_EDI);
  }
switchD_680f3961_caseD_3:
  return 0;
}



// ============================================================
// Function: display_dispatchBitmapCastOp (FUN_680f3a10)
// Address: 680f3a10
// Size: 1128 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

int * display_dispatchBitmapCastOp(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = param_1;
  piVar1 = param_1 + 2;
  iVar3 = *param_1;
  param_1 = (int *)0x0;
  switch(*piVar1) {
  case 0:
    iVar3 = display_initBitmapDefaults();
    if (iVar3 == 0) {
      return (int *)0;
    }
    break;
  case 3:
    piVar1 = (int *)(iVar3 + 0x8c);
    if (*(int *)(iVar3 + 0x8c) != 0) {
      iVar4 = Ordinal_1120(*(int *)(iVar3 + 0x8c),0);
      *piVar1 = iVar4;
      if (iVar4 == 0) {
        return (int *)0;
      }
    }
    if (*(int *)(iVar3 + 0x90) != 0) {
      iVar4 = Ordinal_1120(*(int *)(iVar3 + 0x90),0);
      *(int *)(iVar3 + 0x90) = iVar4;
      if (iVar4 == 0) {
        Ordinal_1113(piVar1);
        return (int *)0;
      }
    }
    if (*(int *)(iVar3 + 0xa0) != 0) {
      iVar4 = Ordinal_1120(*(int *)(iVar3 + 0xa0),0);
      *(int *)(iVar3 + 0xa0) = iVar4;
      if (iVar4 == 0) {
        Ordinal_1113(piVar1);
        Ordinal_1113((int *)(iVar3 + 0x90));
        return (int *)0;
      }
    }
    goto switchD_680f3a2e_caseD_b;
  case 5:
    iVar3 = display_loadAllBitmapResources();
    goto LAB_680f3a46;
  case 6:
    iVar3 = display_loadBitmapResource((void *)piVar2[6],piVar2[5]);
    goto LAB_680f3a46;
  case 7:
    iVar3 = piVar2[5];
    if (((iVar3 != FOURCC_RTE0) && (iVar3 != FOURCC_RTE1)) && (iVar3 != FOURCC_RTE2)) break;
    iVar3 = display_resolveBitmapResource(piVar2[4]);
    goto LAB_680f3a46;
  case 8:
    Ordinal_1113(iVar3 + 0x8c);
    Ordinal_1113(iVar3 + 0x90);
    Ordinal_1113(iVar3 + 0xa0);
    *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) & 0xfffffdff;
    return (int *)1;
  case 9:
    iVar4 = Ordinal_1116(*(undefined4 *)(iVar3 + 0xa0));
    iVar5 = Ordinal_1116(*(undefined4 *)(iVar3 + 0x90));
    iVar3 = Ordinal_1116(*(undefined4 *)(iVar3 + 0x8c));
    piVar2[3] = iVar3 + iVar4 + iVar5;
    break;
  case 10:
    iVar3 = display_calcBitmapResourceSize();
    piVar2[3] = iVar3;
    return (int *)1;
  case 0xb:
  case 0xc:
    goto switchD_680f3a2e_caseD_b;
  case 0xf:
    piVar2[3] = 0x14;
    return (int *)1;
  case 0x10:
    display_readBitmapStream();
    return (int *)1;
  case 0x11:
    display_writeBitmapStream();
    return (int *)1;
  case 0x12:
    piVar2[3] = 3;
    return (int *)1;
  case 0x13:
    piVar1 = piVar2 + 4;
    iVar3 = crt_negotiateFormat(piVar1,piVar2[3],FOURCC_RTE0);
    piVar2[3] = iVar3;
    iVar3 = crt_negotiateFormat(piVar1,iVar3,FOURCC_RTE1);
    piVar2[3] = iVar3;
    iVar3 = crt_negotiateFormat(piVar1,iVar3,FOURCC_RTE2);
    piVar2[3] = iVar3;
    return (int *)1;
  case 0x17:
    iVar3 = display_convertBitmapData();
    goto LAB_680f3a46;
  case 0x18:
    piVar2[4] = 2;
    return (int *)0;
  case 0x19:
    iVar3 = display_getBitmapMemberProperty();
    if (iVar3 != 0) {
      return (int *)1;
    }
    break;
  case 0x1a:
    iVar3 = display_setBitmapMemberProperty(piVar2);
    if (iVar3 != 0) {
      return (int *)1;
    }
    break;
  case 0x1b:
    display_scrollBitmapMember(piVar2[1],piVar2[3],piVar2[4]);
    return (int *)1;
  case 0x1d:
    iVar4 = piVar2[3];
    iVar5 = Ordinal_1063(iVar3 + 0x54,iVar4 + 0x54);
    if (((((((iVar5 != 0) && (iVar5 = Ordinal_1063(iVar3 + 100,iVar4 + 100), iVar5 != 0)) &&
           (*(char *)(iVar3 + 0x74) == *(char *)(iVar4 + 0x74))) &&
          (((*(char *)(iVar3 + 0x75) == *(char *)(iVar4 + 0x75) &&
            (*(int *)(iVar3 + 0x78) == *(int *)(iVar4 + 0x78))) &&
           ((*(int *)(iVar3 + 0x7c) == *(int *)(iVar4 + 0x7c) &&
            ((*(int *)(iVar3 + 0x80) == *(int *)(iVar4 + 0x80) &&
             (*(int *)(iVar3 + 0x94) == *(int *)(iVar4 + 0x94))))))))) &&
         ((*(int *)(iVar3 + 0x98) == *(int *)(iVar4 + 0x98) &&
          (((*(int *)(iVar3 + 0x9c) == *(int *)(iVar4 + 0x9c) &&
            (*(char *)(iVar3 + 0x84) == *(char *)(iVar4 + 0x84))) &&
           (*(char *)(iVar3 + 0x85) == *(char *)(iVar4 + 0x85))))))) &&
        (((*(char *)(iVar3 + 0x86) == *(char *)(iVar4 + 0x86) &&
          (*(char *)(iVar3 + 0x88) == *(char *)(iVar4 + 0x88))) &&
         (((*(char *)(iVar3 + 0x89) == *(char *)(iVar4 + 0x89) &&
           ((*(char *)(iVar3 + 0x8a) == *(char *)(iVar4 + 0x8a) &&
            (iVar5 = Ordinal_1122(*(undefined4 *)(iVar3 + 0x8c),*(undefined4 *)(iVar4 + 0x8c)),
            iVar5 != 0)))) &&
          (iVar5 = Ordinal_1122(*(undefined4 *)(iVar3 + 0x90),*(undefined4 *)(iVar4 + 0x90)),
          iVar5 != 0)))))) &&
       (iVar3 = Ordinal_1122(*(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(iVar4 + 0xa0)),
       iVar3 != 0)) {
      piVar2[4] = 1;
      return (int *)1;
    }
    goto switchD_680f3a2e_caseD_b;
  }
  iVar3 = rendering_validateState(piVar2);
LAB_680f3a46:
  if (iVar3 != 0) {
switchD_680f3a2e_caseD_b:
    param_1 = (int *)0x1;
  }
  return param_1;
}




// ============================================================
// Function: display_reportMediaFormatError (FUN_680f3ef0)
// Address: 680f3ef0
// Size: 226 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_reportMediaFormatError(void)
{
  undefined4 uVar1;
  int unaff_EBX;
  int iVar2;
  int unaff_EDI;
  undefined1 local_134 [100];
  undefined1 local_d0 [100];
  undefined1 local_6c [100];
  uint local_8;
  
  uVar1 = Ordinal_1261();
  switch(uVar1) {
  default:
    iVar2 = 0;
    break;
  case 1:
    iVar2 = 300;
    break;
  case 2:
    iVar2 = 400;
    break;
  case 3:
    iVar2 = 500;
    break;
  case 9:
    iVar2 = 600;
  }
  local_d0[0] = 0;
  Ordinal_1517(DAT_681956e0,iVar2 + 0x1520,local_d0,100);
  local_6c[0] = 0;
  Ordinal_1517(DAT_681956e0,iVar2 + 0x151f,local_134,100);
  Ordinal_1219(local_6c,local_134,(int)*(short *)(unaff_EDI + 6),(int)*(short *)(unaff_EDI + 4));
  Ordinal_1780(local_6c,local_d0,3,1,0,1,0);
  lingo_formatDebugMsg(*(int **)(unaff_EBX + 0x18),-0x1c3);
  return 0;
}



// ============================================================
// Function: display_isMediaDataChanged (FUN_680f4000)
// Address: 680f4000
// Size: 75 bytes
// Params: undefined4 param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_isMediaDataChanged(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (*(int *)(in_EAX + 0x4c) != 0) {
    local_8 = cast_lookupDataEntry(*(int *)(in_EAX + 0x4c),0,0);
    iVar1 = Ordinal_1122(local_8,param_1);
    Ordinal_1113(&local_8);
    return iVar1 == 0;
  }
  return true;
}



// ============================================================
// Function: display_applyMediaDataChange (FUN_680f4050)
// Address: 680f4050
// Size: 74 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_applyMediaDataChange(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int unaff_EBX;
  int *unaff_ESI;
  
  bVar2 = display_isMediaDataChanged(param_1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    rendering_setMemberData(unaff_EBX,unaff_ESI,5);
    iVar1 = unaff_ESI[0x17];
    unaff_ESI[0x17] = 0;
    rendering_getDispatchInfo((int)unaff_ESI,param_1);
    unaff_ESI[0x17] = iVar1;
    stage_clearSpriteEventProps(*(int *)(*(int *)(unaff_EBX + 0x20) + 8),unaff_ESI[1]);
  }
  return 0;
}



// ============================================================
// Function: display_invokeMediaCallback (FUN_680f40a0)
// Address: 680f40a0
// Size: 50 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_invokeMediaCallback(void *this,undefined4 param_1)
{
  int *piVar1;
  code *pcVar2;
  
  if ((((this != (void *)0x0) && (piVar1 = *(int **)((int)this + 0x18), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) &&
     ((*(int *)(*piVar1 + 0xc) != 0 &&
      (pcVar2 = *(code **)(*(int *)(*piVar1 + 0xc) + 0x180), pcVar2 != (code *)0x0)))) {
    (*pcVar2)(piVar1,param_1);
  }
  return 0;
}



// ============================================================
// Function: display_loadMediaContent (FUN_680f40e0)
// Address: 680f40e0
// Size: 468 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_loadMediaContent(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  int local_430 [5];
  undefined1 local_41c [1044];
  uint local_8;
  
  local_430[1] = 0;
  if ((param_1 != 0) &&
     (iVar1 = rendering_blendMedia(*(int **)(param_1 + 0x20),param_2,local_430 + 1), iVar1 != 0)) {
    local_430[4] = 0;
    memset(local_41c,0,0x414);
    local_430[3] = 0;
    if ((*(int *)(param_1 + 0x20) != 0) &&
       (iVar2 = rendering_dispatchUpdate(*(int *)(param_1 + 0x20),param_2,local_430 + 4,1), iVar2 != 0)) {
      if (param_2[8] == 0) {
        iVar1 = Ordinal_1402(local_430 + 3,local_430 + 4,1);
      }
      else {
        iVar2 = Ordinal_1405(local_430 + 3,param_2[8],1);
        if (iVar2 == 0) {
          Ordinal_1407(local_430 + 3);
          Ordinal_1405(local_430 + 3,param_2[8],1,0);
        }
      }
      bVar5 = iVar1 != 0;
      iVar1 = 0;
      if (bVar5) {
        local_430[2] = 0;
        uVar3 = Ordinal_1435(local_430[3]);
        local_430[2] = Ordinal_1111(uVar3,0);
        uVar4 = Ordinal_1114(local_430[2]);
        iVar1 = Ordinal_1409(local_430[3],uVar4,uVar3);
        Ordinal_1115(local_430[2]);
        if (iVar1 != 0) {
          param_2[0x16] = 0;
          Ordinal_1708(local_430 + 2,1,param_2 + 0x16,0,0);
          display_applyMediaDataChange(local_430[2]);
          param_2[0xb] = param_2[0xb] | 0x200;
        }
        Ordinal_1359(local_430 + 4,1,local_430);
        param_2[0x17] = local_430[0];
        iVar2 = Ordinal_1313(local_430 + 4);
        if (iVar2 == 4) {
          param_2[0x17] = 1;
        }
        Ordinal_1113(local_430 + 2);
      }
      Ordinal_1407(local_430 + 3);
    }
    if (iVar1 != 0) {
      param_2[0xb] = param_2[0xb] | 0x200;
    }
  }
  return 0;
}



// ============================================================
// Function: display_storeMediaMemberData (FUN_680f42c0)
// Address: 680f42c0
// Size: 331 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall display_storeMediaMemberData(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_42c;
  undefined4 local_428;
  int local_424 [2];
  undefined1 local_41c [1044];
  uint local_8;
  
  local_424[1] = 0;
  memset(local_41c,0,0x414);
  local_428 = 0;
  if (param_1 != 0) {
    if (param_2[2] != 0xb) {
      rendering_initMemberSlot(param_2,-0x79);
      return 0;
    }
    rendering_dispatchUpdate(*(int *)(param_1 + 0x20),param_2,local_424 + 1,0);
    if (param_2[0x17] == 0) {
      local_424[0] = 0;
      local_424[0] = cast_lookupDataEntry(param_2[0x13],0,0);
      if (local_424[0] != 0) {
        iVar1 = Ordinal_1401(&local_428,local_424 + 1,0x22);
        if (iVar1 == 0) {
          display_reportMediaFormatError();
        }
        else {
          local_42c = 1;
          Ordinal_1708(local_424,param_2[0x16],&local_42c,2,1);
          uVar2 = Ordinal_1116(local_424[0]);
          uVar3 = Ordinal_1114(local_424[0]);
          Ordinal_1420(local_428,uVar3,uVar2);
          Ordinal_1115(local_424[0]);
        }
        Ordinal_1407(&local_428);
        Ordinal_1113(local_424);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: display_getSoundMemberProperty (FUN_680f4410)
// Address: 680f4410
// Size: 108 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_getSoundMemberProperty(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  piVar1 = (int *)param_1[4];
  if (*(int *)(iVar2 + 8) == 0xb) {
    switch(param_1[3]) {
    case 0x21:
      *piVar1 = *(int *)(iVar2 + 0x54);
      return 1;
    case 0x38:
      *piVar1 = *(int *)(iVar2 + 0x58);
      return 1;
    case 0x39:
      *piVar1 = *(int *)(iVar2 + 0x5c);
      return 1;
    case 0x3a:
      iVar2 = rendering_getFrameCount(iVar2);
      *piVar1 = iVar2;
      return 1;
    }
  }
  Ordinal_1130(piVar1,0x18);
  return 0;
}



// ============================================================
// Function: display_setSoundMemberProperty (FUN_680f44b0)
// Address: 680f44b0
// Size: 188 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setSoundMemberProperty(void)

{
  void *this;
  int *piVar1;
  int *piVar2;
  undefined4 *in_EAX;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  this = (void *)in_EAX[1];
  piVar1 = (int *)*in_EAX;
  piVar2 = (int *)in_EAX[4];
  local_8 = 0;
  if (piVar1[2] == 0xb) {
    switch(in_EAX[3]) {
    case 0x21:
      piVar1[0x15] = *piVar2;
      Ordinal_890(*(int *)(*(int *)((int)this + 0x20) + 8),piVar1[1]);
      break;
    default:
      goto switchD_680f44e6_caseD_22;
    case 0x38:
      piVar1[0x16] = *piVar2;
      break;
    case 0x39:
      piVar1[0x17] = *piVar2;
      break;
    case 0x3a:
      iVar3 = display_invokeMediaCallback(this,piVar1[1]);
      if (iVar3 != 0) {
        iVar3 = *piVar2;
        iVar4 = rendering_getFrameCount((int)piVar1);
        if (iVar4 != iVar3) {
          if (iVar3 == 1) {
            rendering_getDispatchRef((int)piVar1,0);
            rendering_setStateFlag((int)piVar1,0);
          }
          else {
            if (iVar3 != 0) {
              return 0;
            }
            rendering_clearStateFlag((int)piVar1,0);
            piVar1[0x17] = 0;
          }
        }
      }
    }
    rendering_setMemberData((int)this,piVar1,1);
    local_8 = 1;
  }
switchD_680f44e6_caseD_22:
  return local_8;
}



// ============================================================
// Function: display_handleSoundCueEvent (FUN_680f45a0)
// Address: 680f45a0
// Size: 535 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall display_handleSoundCueEvent(undefined4 *param_1)
{
  int *piVar1;
  void *this;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_428;
  int local_424 [2];
  undefined1 local_41c [1044];
  uint local_8;
  
  piVar1 = (int *)*param_1;
  this = (void *)param_1[1];
  if ((((piVar1[2] == 0xb) && (*(int *)(param_1[3] + 8) == 0x3b8)) &&
      (iVar3 = display_invokeMediaCallback(this,piVar1[1]), iVar3 != 0)) &&
     (iVar3 = rendering_getFrameCount((int)piVar1), iVar3 == 0)) {
    iVar3 = param_1[3];
    iVar2 = *(int *)(iVar3 + 0x14);
    if (iVar2 == 1) {
      local_424[1] = 0;
      memset(local_41c,0,0x414);
      local_424[0] = 0;
      local_424[0] = rendering_getDispatchData((int)piVar1);
      rendering_getDispatchRef((int)piVar1,0);
      rendering_setStateFlag((int)piVar1,0);
      rendering_dispatchUpdate(*(int *)((int)this + 0x20),piVar1,local_424 + 1,0);
      iVar3 = scoreEngine_getScoreLibraryId(*(int *)((int)this + 0x20));
      if ((iVar3 == 0) || (*(code **)(iVar3 + 0x17c) == (code *)0x0)) {
        rendering_clearStateFlag((int)piVar1,0);
        rendering_getDispatchRef((int)piVar1,local_424[0]);
        Ordinal_1113(local_424);
      }
      else {
        iVar3 = (**(code **)(iVar3 + 0x17c))(local_424 + 1);
        if (iVar3 == 0) {
          rendering_clearStateFlag((int)piVar1,0);
          rendering_getDispatchRef((int)piVar1,local_424[0]);
          Ordinal_1113(local_424);
        }
        else {
          rendering_getStatePair((int)piVar1,local_424 + 1);
          iVar3 = Ordinal_1709();
          piVar1[0x16] = iVar3;
          display_storeMediaMemberData((int)this,piVar1);
          rendering_setMemberData((int)this,piVar1,1);
          Ordinal_1113(local_424);
        }
      }
    }
    else if (iVar2 == 2) {
      local_424[1] = 0;
      memset(local_41c,0,0x414);
      iVar3 = *(int *)(iVar3 + 0x18);
      local_428 = *(int *)(iVar3 + 8);
      local_424[0] = *(int *)(iVar3 + 0xc);
      piVar4 = props_getStringData(&local_428,(int *)0x0);
      Ordinal_1309(local_424 + 1,0x400,piVar4,2);
      props_unlockString(&local_428);
      rendering_getDispatchRef((int)piVar1,0);
      rendering_setStateFlag((int)piVar1,0);
      rendering_getStatePair((int)piVar1,local_424 + 1);
      iVar3 = Ordinal_1709();
      piVar1[0x16] = iVar3;
      display_storeMediaMemberData((int)this,piVar1);
      rendering_setMemberData((int)this,piVar1,1);
    }
  }
  return 0;
}




// ============================================================
// Function: display_dispatchSoundCastOp (FUN_680f47c0)
// Address: 680f47c0
// Size: 426 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_dispatchSoundCastOp(int *param_1)

{
  int *piVar1;
  int *piVar2;
  void *this;
  short sVar3;
  int iVar4;
  
  piVar2 = (int *)*param_1;
  this = (void *)param_1[1];
  switch(param_1[2]) {
  case 0:
    piVar1 = piVar2 + 0x13;
    if (piVar2[0x13] == 0) {
      iVar4 = Ordinal_35(0x14);
      *piVar1 = iVar4;
      if (iVar4 == 0) {
        return 0;
      }
    }
    iVar4 = Ordinal_37(piVar1,0,&DAT_6817a910,1);
    if (iVar4 == 0) {
      Ordinal_36(piVar1);
      return 0;
    }
    piVar2[0x15] = 3;
    piVar2[0x17] = 0;
    piVar2[0x16] = 0;
    break;
  case 3:
    rendering_clearStateFlag((int)piVar2,0);
    piVar2[0x17] = 0;
    return 1;
  case 8:
  case 0xb:
  case 0xc:
  case 0x13:
    goto switchD_680f47df_caseD_8;
  case 9:
  case 10:
  case 0x12:
    param_1[3] = 0;
    break;
  case 0xe:
    param_1[3] = 0x22;
    return 1;
  case 0x10:
    sVar3 = Ordinal_1412(param_1[3]);
    piVar2[0x15] = (int)sVar3;
  case 5:
    iVar4 = display_invokeMediaCallback(this,piVar2[1]);
    if (iVar4 == 0) {
      return 1;
    }
    iVar4 = rendering_getFrameCount((int)piVar2);
    if (iVar4 != 0) {
      iVar4 = display_loadMediaContent((int)this,piVar2);
      if (iVar4 == 0) {
        return 0;
      }
      return 1;
    }
    return 1;
  case 0x11:
    Ordinal_1423(param_1[3],(short)piVar2[0x15]);
    iVar4 = rendering_getFrameCount((int)piVar2);
    if (iVar4 == 0) {
      return 1;
    }
    if ((*(byte *)(piVar2 + 0xe) & 0xc) == 0) {
      return 1;
    }
    iVar4 = display_storeMediaMemberData((int)this,piVar2);
    if (iVar4 == 0) {
      return 0;
    }
    return 1;
  case 0x15:
    iVar4 = display_handleSoundCueEvent(param_1);
    if (iVar4 != 0) {
      return 1;
    }
    break;
  case 0x19:
    iVar4 = display_getSoundMemberProperty(param_1);
    if (iVar4 != 0) {
      return 1;
    }
    break;
  case 0x1a:
    iVar4 = display_setSoundMemberProperty();
    if (iVar4 != 0) {
      return 1;
    }
    break;
  case 0x1d:
    if (piVar2[0x15] != *(int *)(param_1[3] + 0x54)) {
      return 1;
    }
    param_1[4] = 1;
    return 1;
  }
  iVar4 = rendering_validateState(param_1);
  if (iVar4 == 0) {
    return 0;
  }
switchD_680f47df_caseD_8:
  return 1;
}



// ============================================================
// Function: display_initShapeMemberBounds (FUN_680f49c0)
// Address: 680f49c0
// Size: 211 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_initShapeMemberBounds(int param_1)
{
  int iVar1;
  uint uVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  int local_78;
  undefined1 local_74 [20];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_8;
  
  local_78 = 0;
  if (param_1 == 0) {
LAB_680f4a25:
    unaff_ESI[0x15] = 0;
    unaff_ESI[0x16] = 0;
    unaff_ESI[0x17] = 0xa0;
    unaff_ESI[0x18] = 0x78;
  }
  else {
    unaff_ESI[0x19] = 0x2a;
    display_compositeSprite(unaff_EDI,unaff_ESI,param_1,&local_78);
    if (local_78 == 0) goto LAB_680f4a25;
    Ordinal_1952(local_78,local_74);
    unaff_ESI[0x15] = local_60;
    unaff_ESI[0x16] = local_5c;
    unaff_ESI[0x17] = local_58;
    unaff_ESI[0x18] = local_54;
    Ordinal_1951(&local_78);
  }
  iVar1 = rendering_getFrameCount((int)unaff_ESI);
  if (iVar1 != 0) {
    iVar1 = rendering_updateMemberRef((int)unaff_EDI,unaff_ESI);
    if (iVar1 == 4) {
      unaff_ESI[0xb] = unaff_ESI[0xb] & 0xfffffdff;
      uVar2 = scoreEngine_readChannelBlock(unaff_EDI,unaff_ESI,1);
      unaff_ESI[0xb] = unaff_ESI[0xb] ^ (uVar2 << 9 ^ unaff_ESI[0xb]) & 0x200;
      goto LAB_680f4a7e;
    }
  }
  unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
LAB_680f4a7e:
  return 0;
}



// ============================================================
// Function: display_invalidateShapeSprites (FUN_680f4aa0)
// Address: 680f4aa0
// Size: 89 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_invalidateShapeSprites(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) &&
     (iVar3 = *(int *)(unaff_EDI + 0x120), iVar3 <= *(int *)(unaff_EDI + 0x124))) {
    iVar1 = iVar3 * 400;
    do {
      puVar4 = (undefined4 *)(*(int *)(unaff_EDI + 0x34) + iVar1);
      if (puVar4 == (undefined4 *)0x0) {
        return 0;
      }
      iVar2 = playback_getSpriteData(unaff_EDI,puVar4);
      if (param_1 == iVar2) {
        display_destroyVideoOverlay((int)puVar4);
      }
      iVar1 = iVar1 + 400;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(unaff_EDI + 0x124));
  }
  return 0;
}



// ============================================================
// Function: display_previewShapeMember (FUN_680f4b00)
// Address: 680f4b00
// Size: 147 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_previewShapeMember(int *param_1)
{
  int iVar1;
  int *unaff_EDI;
  int local_490;
  undefined4 local_48c [262];
  undefined1 local_74 [108];
  uint local_8;
  
  if ((param_1 != (int *)0x0) && (param_1[2] == 10)) {
    iVar1 = rendering_dispatchUpdate((int)unaff_EDI,param_1,local_48c,1);
    if (iVar1 != 0) {
      display_compositeSprite(unaff_EDI,param_1,local_48c,&local_490);
      if (local_490 != 0) {
        Ordinal_1952(local_490,local_74);
        Ordinal_1951(&local_490);
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: display_readShapeStream (FUN_680f4ba0)
// Address: 680f4ba0
// Size: 58 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_readShapeStream(void)
{
  short sVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x58) = (int)sVar1;
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x54) = (int)sVar1;
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x60) = (int)sVar1;
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x5c) = (int)sVar1;
  uVar2 = Ordinal_1414();
  *(undefined4 *)(unaff_EDI + 100) = uVar2;
  Ordinal_1979();
  return 0;
}



// ============================================================
// Function: display_writeShapeStream (FUN_680f4be0)
// Address: 680f4be0
// Size: 55 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_writeShapeStream(void)
{
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1425();
  return 0;
}



// ============================================================
// Function: display_resolveShapeSpriteImage (FUN_680f4c20)
// Address: 680f4c20
// Size: 370 bytes
// Params: undefined4 * param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_resolveShapeSpriteImage(undefined4 *param_1,int *param_2,int param_3,int param_4)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  undefined4 *puVar5;
  int local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  local_424 = 0;
  *param_1 = 0;
  if ((param_3 != 0) && (iVar4 = *(int *)(unaff_ESI + 0x120), iVar4 <= *(int *)(unaff_ESI + 0x124)))
  {
    iVar3 = iVar4 * 400;
    do {
      puVar5 = (undefined4 *)(*(int *)(unaff_ESI + 0x34) + iVar3);
      if (puVar5 == (undefined4 *)0x0) goto LAB_680f4d80;
      piVar2 = (int *)playback_getSpriteData(unaff_ESI,puVar5);
      if ((param_2 == piVar2) && (puVar5[0x53] != 0)) {
        local_424 = puVar5[0x53];
      }
      iVar3 = iVar3 + 400;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(unaff_ESI + 0x124));
    if (local_424 != 0) goto LAB_680f4d80;
  }
  iVar4 = rendering_dispatchUpdate(*(int *)(unaff_ESI + 0x20),param_2,local_420,1);
  if (iVar4 != 0) {
    if (param_4 == 0) {
      display_compositeSprite(*(int **)(unaff_ESI + 0x20),param_2,local_420,&local_424);
    }
    else {
      uVar1 = param_2[0x19];
      param_2[0x19] = uVar1 & 0xfffffbff | 0x20;
      display_compositeSprite(*(int **)(unaff_ESI + 0x20),param_2,local_420,&local_424);
      if ((uVar1 >> 10 & 1) != 0) {
        param_2[0x19] = param_2[0x19] | 0x400;
      }
      if ((uVar1 >> 5 & 1) == 0) {
        param_2[0x19] = param_2[0x19] & 0xffffffdf;
      }
    }
    if (local_424 != 0) {
      *param_1 = 1;
      return 0;
    }
  }
LAB_680f4d80:
  return 0;
}




// ============================================================
// Function: display_getShapeMemberProperty (FUN_680f4da0)
// Address: 680f4da0
// Size: 554 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_getShapeMemberProperty(undefined4 *param_1)
{
  int *piVar1;
  uint *puVar2;
  uint local_a4 [12];
  undefined1 local_74 [40];
  uint local_4c;
  uint local_44;
  uint local_28;
  uint local_24;
  undefined4 local_1c;
  uint local_8;
  
  local_a4[0xb] = param_1[1];
  piVar1 = (int *)*param_1;
  local_a4[0] = 0;
  local_a4[1] = 0;
  local_a4[2] = 0;
  local_a4[3] = 0;
  local_a4[4] = 0;
  local_a4[5] = 0;
  local_a4[6] = 0;
  local_a4[7] = 0;
  local_a4[8] = 0;
  puVar2 = (uint *)param_1[4];
  local_a4[10] = 0;
  local_a4[9] = 0;
  if (piVar1[2] != 10) goto LAB_680f4fae;
  switch(param_1[3]) {
  case CMTYPE_PICTURE:
    *puVar2 = piVar1[0x15];
    puVar2[1] = piVar1[0x16];
    puVar2[2] = piVar1[0x17];
    puVar2[3] = piVar1[0x18];
    break;
  default:
    local_a4[0xb] = display_resolveShapeSpriteImage(local_a4 + 9,piVar1,1,0);
    if (local_a4[0xb] == 0) goto LAB_680f4f95;
    Ordinal_1952(local_a4[0xb],local_74);
    switch(param_1[3]) {
    case 0x30:
      local_28 = local_44;
      goto LAB_680f4f89;
    default:
      goto switchD_680f4f01_caseD_31;
    case 0x59:
      goto LAB_680f4f89;
    case 0x5a:
      *puVar2 = local_4c;
      break;
    case 0x5b:
      *puVar2 = local_24;
    case 0x5c:
      Ordinal_1983(local_a4[0xb],*puVar2,1,local_a4);
      puVar2[1] = local_a4[0];
      break;
    case 0x5d:
      Ordinal_1983(local_a4[0xb],*puVar2,2,local_a4);
      puVar2[2] = local_a4[2];
      break;
    case 0x5e:
      Ordinal_1983(local_a4[0xb],*puVar2,3,local_a4);
      puVar2[3] = local_a4[3];
      break;
    case 0x79:
      local_28 = Ordinal_1120(local_1c,1);
      goto LAB_680f4f89;
    }
    break;
  case 0x2f:
    local_28 = (uint)piVar1[0x19] >> 4 & 1;
    goto LAB_680f4f89;
  case 0x3c:
    puVar2[1] = (piVar1[0x18] - piVar1[0x16]) / 2;
    local_28 = (piVar1[0x17] - piVar1[0x15]) / 2;
    goto LAB_680f4f89;
  case 0x48:
    *puVar2 = piVar1[0x19] & 1;
    break;
  case 0x49:
    *puVar2 = ~((uint)piVar1[0x19] >> 1) & 1;
    break;
  case 0x4a:
    local_28 = (uint)piVar1[0x19] >> 3 & 1;
    goto LAB_680f4f89;
  case 0x56:
    *puVar2 = piVar1[0x19];
    break;
  case 0x58:
    *puVar2 = (uint)*(byte *)((int)piVar1 + 0x67);
    break;
  case 0x5f:
    local_28 = display_resolveShapeSpriteImage(puVar2 + 1,piVar1,0,1);
LAB_680f4f89:
    *puVar2 = local_28;
  }
  local_a4[10] = 1;
switchD_680f4f01_caseD_31:
LAB_680f4f95:
  if ((local_a4[9] != 0) && (local_a4[0xb] != 0)) {
    Ordinal_1951(local_a4 + 0xb);
  }
  if (local_a4[10] == 0) {
LAB_680f4fae:
    Ordinal_1130(puVar2,0x18);
  }
  return 0;
}



// ============================================================
// Function: display_setShapeMemberProperty (FUN_680f50c0)
// Address: 680f50c0
// Size: 359 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setShapeMemberProperty(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 local_10;
  int local_c;
  
  piVar1 = (int *)param_1[4];
  iVar2 = param_1[1];
  piVar3 = (int *)*param_1;
  local_10 = 0;
  if (piVar3[2] == 10) {
    switch(param_1[3]) {
    case CMTYPE_PICTURE:
      piVar3[0x15] = *piVar1;
      piVar3[0x16] = piVar1[1];
      piVar3[0x17] = piVar1[2];
      piVar3[0x18] = piVar1[3];
      break;
    default:
      goto switchD_680f50fd_caseD_6;
    case 0x2f:
      if (*piVar1 == 0) {
        piVar3[0x19] = piVar3[0x19] & 0xffffffef;
      }
      else {
        piVar3[0x19] = piVar3[0x19] | 0x10;
      }
      break;
    case 0x48:
      if (*piVar1 == 0) {
        piVar3[0x19] = piVar3[0x19] & 0xfffffffe;
      }
      else {
        piVar3[0x19] = piVar3[0x19] | 1;
      }
      break;
    case 0x49:
      if (*piVar1 == 0) {
        piVar3[0x19] = piVar3[0x19] | 2;
      }
      else {
        piVar3[0x19] = piVar3[0x19] & 0xfffffffd;
      }
      break;
    case 0x4a:
      if (*piVar1 == 0) {
        piVar3[0x19] = piVar3[0x19] & 0xfffffff7;
      }
      else {
        piVar3[0x19] = piVar3[0x19] | 8;
      }
      break;
    case 0x56:
      piVar3[0x19] = *piVar1;
      break;
    case 0x58:
      piVar3[0x19] = *piVar1 << 0x18 | piVar3[0x19] & 0xffffffU;
    }
    local_c = *(int *)(iVar2 + 0x120);
    if (local_c <= *(int *)(iVar2 + 0x124)) {
      iVar4 = local_c * 400;
      do {
        puVar6 = (undefined4 *)(*(int *)(iVar2 + 0x34) + iVar4);
        if (puVar6 == (undefined4 *)0x0) goto switchD_680f51c2_caseD_30;
        piVar5 = (int *)playback_getSpriteData(iVar2,puVar6);
        if (piVar3 == piVar5) {
          switch(param_1[3]) {
          case 0x2f:
          case 0x48:
          case 0x49:
          case 0x4a:
          case 0x56:
            if (puVar6[0x53] != 0) {
              Ordinal_1957(puVar6[0x53],piVar3[0x19]);
            }
            break;
          default:
            goto switchD_680f51c2_caseD_30;
          case 0x58:
            if (puVar6[0x53] != 0) {
              Ordinal_1961(puVar6[0x53],*piVar1);
            }
          }
        }
        iVar4 = iVar4 + 400;
        local_c = local_c + 1;
      } while (local_c <= *(int *)(iVar2 + 0x124));
    }
    rendering_setMemberData(iVar2,piVar3,1);
    local_10 = 1;
switchD_680f51c2_caseD_30:
  ; /* FIXUP */ }
switchD_680f50fd_caseD_6:
  return local_10;
}



// ============================================================
// Function: display_dispatchShapeCastOp (FUN_680f52e0)
// Address: 680f52e0
// Size: 287 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_dispatchShapeCastOp(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  switch(param_1[2]) {
  case 0:
    param_1[6] = 1;
    iVar3 = display_initShapeMemberBounds(param_1[5]);
    if (iVar3 == 0) {
      return 0;
    }
    break;
  case 3:
  case 5:
  case 6:
  case 7:
  case 0xb:
  case 0xc:
    goto switchD_680f52fe_caseD_3;
  case 8:
    display_invalidateShapeSprites((int)piVar1);
    return 1;
  case 9:
    if ((piVar1[0xb] & 0x200U) != 0) goto switchD_680f52fe_caseD_a;
    param_1[3] = 0;
    break;
  case 10:
switchD_680f52fe_caseD_a:
    uVar2 = display_previewShapeMember(piVar1);
    param_1[3] = uVar2;
    return 1;
  case 0xe:
    param_1[3] = 0xb;
    return 1;
  case 0xf:
    param_1[3] = 0x13;
    return 1;
  case 0x10:
    display_readShapeStream();
    return 1;
  case 0x11:
    display_writeShapeStream();
    return 1;
  case 0x19:
    iVar3 = display_getShapeMemberProperty(param_1);
    if (iVar3 != 0) {
      return 1;
    }
    break;
  case 0x1a:
    iVar3 = display_setShapeMemberProperty(param_1);
    if (iVar3 != 0) {
      return 1;
    }
  }
  iVar3 = rendering_validateState(param_1);
  if (iVar3 == 0) {
    return 0;
  }
switchD_680f52fe_caseD_3:
  return 1;
}



// ============================================================
// Function: display_initMovieMember (FUN_680f5450)
// Address: 680f5450
// Size: 135 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int display_initMovieMember(undefined4 *param_1)
{
  int iVar1;
  int *unaff_ESI;
  undefined4 local_146c [5];
  int local_1458;
  int local_1454;
  int local_1450;
  int local_144c;
  uint local_8;
  
  unaff_ESI[0x1a] = 0xe;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = lingo_mutateData(*(undefined4 **)(*unaff_ESI + 4),param_1,local_146c);
    if (iVar1 != 0) {
      unaff_ESI[0x18] = local_1450 - local_1458;
      unaff_ESI[0x19] = local_144c - local_1454;
      goto LAB_680f54c2;
    }
  }
  unaff_ESI[0x18] = 0x280;
  unaff_ESI[0x19] = 0x1e0;
LAB_680f54c2:
  return 0;
}



// ============================================================
// Function: display_releaseMovieMember (FUN_680f54e0)
// Address: 680f54e0
// Size: 51 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_releaseMovieMember(void)
{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    scoreEngine_updateScore(*(int **)(unaff_ESI + 0x70),0);
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x54));
    Ordinal_1113((undefined4 *)(unaff_ESI + 0x54));
    *(undefined4 *)(unaff_ESI + 0x70) = 0;
  }
  *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffff9ff;
  return 0;
}



// ============================================================
// Function: display_resetMovieMemberFields (FUN_680f5520)
// Address: 680f5520
// Size: 12 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_resetMovieMemberFields(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x70) = 0;
  return 1;
}



// ============================================================
// Function: display_writeMovieStream (FUN_680f5530)
// Address: 680f5530
// Size: 66 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_writeMovieStream(void)
{
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1425();
  Ordinal_1423();
  return 0;
}



// ============================================================
// Function: display_getPaletteMemberProperty (FUN_680f5580)
// Address: 680f5580
// Size: 48 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_getPaletteMemberProperty(undefined4 param_1,int *param_2)

{
  if ((*(int *)(*param_2 + 8) == 9) && (param_2[3] == 0x4c)) {
    *(uint *)param_2[4] = *(uint *)(*param_2 + 0x68) >> 4 & 1;
    return 1;
  }
  Ordinal_1130((uint *)param_2[4],0x18);
  return 0;
}



// ============================================================
// Function: display_setPaletteMemberProperty (FUN_680f55b0)
// Address: 680f55b0
// Size: 68 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_setPaletteMemberProperty(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)*param_2;
  uVar3 = 0;
  iVar2 = param_2[1];
  if ((piVar1[2] == 9) && (param_2[3] == 0x4c)) {
    if (*(int *)param_2[4] != 0) {
      piVar1[0x1a] = piVar1[0x1a] | 0x10;
      rendering_setMemberData(iVar2,piVar1,1);
      return 1;
    }
    piVar1[0x1a] = piVar1[0x1a] & 0xffffffef;
    rendering_setMemberData(iVar2,piVar1,1);
    uVar3 = 1;
  }
  return uVar3;
}



