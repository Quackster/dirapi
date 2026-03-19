// Module: bitmap
// Topic: Text field data, font operations, text member get/set, scrolling, property dispatch
// Address range: 0x680e9760 - 0x680ece00
// Functions (50):
//   bitmap_parseFontStream
//   bitmap_serializeFontData
//   bitmap_readFontRunData
//   bitmap_writeFontRunData
//   bitmap_loadTextMemberData
//   bitmap_writeStyleRunData
//   bitmap_getTextFieldRef
//   bitmap_renderTextMember
//   bitmap_captureTextImage
//   bitmap_buildFontRunMap
//   bitmap_findSpriteByMember
//   bitmap_syncTextSelection
//   bitmap_setTextSelection
//   bitmap_setTextScrollPos
//   bitmap_getTextScrollPos
//   bitmap_getTextFieldData
//   bitmap_scaleTextRuns
//   bitmap_getTextFieldState
//   bitmap_clearAltStyleRun
//   bitmap_writeAltStyleRun
//   bitmap_mapFontWidths
//   bitmap_setTextFieldRect
//   bitmap_setTextFontById
//   bitmap_setTextFontByTag
//   bitmap_setTextAlignment
//   bitmap_applyTextStyleFlags
//   bitmap_applyDefaultFont
//   bitmap_setTextForeColor
//   bitmap_setTextBackColor
//   bitmap_resizeTextField
//   bitmap_clearTextField
//   bitmap_readStyleRunStream
//   bitmap_initStyleRunBuffers
//   bitmap_updateTextField
//   bitmap_getTextFieldSize
//   bitmap_getScaledStyleRun
//   bitmap_readAltStyleRunStream
//   bitmap_recalcTextLayout
//   bitmap_serializeTextChunk
//   bitmap_deserializeTextChunk
//   bitmap_writeTextChunkData
//   bitmap_readTextChunkData
//   bitmap_processTextEvent
//   bitmap_importTextData
//   bitmap_getTextProperty
//   bitmap_setTextProperty
//   bitmap_updateTextMember
//   bitmap_applyTextImport
//   bitmap_notifyTextChange
//   bitmap_dispatchTextMsg

// ============================================================
// Function: bitmap_parseFontStream (FUN_680e9760)
// Address: 680e9760
// Size: 1157 bytes
// Params: undefined4 * param_1, undefined4 param_2, int * param_3, int param_4, int param_5, int param_6, int param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
bitmap_parseFontStream(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4,int param_5,int param_6
            ,int param_7)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar9;
  void *pvVar10;
  int local_ec;
  undefined4 *local_e8;
  undefined4 local_e4;
  int local_e0;
  int local_dc;
  undefined4 local_d8;
  void *local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0 [16];
  undefined4 local_80;
  short local_74;
  undefined1 local_72;
  undefined4 local_70;
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_dc = 0;
  local_ec = 0;
  local_d8 = 0;
  bVar1 = false;
  local_d4 = (void *)0x0;
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_e4 = param_2;
  if (((param_5 == 0) || (param_3 == (int *)0x0)) || (iVar5 = Ordinal_1041(), iVar5 != 0))
  goto LAB_680e981e;
  iVar5 = Ordinal_1415(param_2);
  pvVar6 = (void *)Ordinal_1415(param_2);
  iVar7 = Ordinal_1415(param_2);
  iVar8 = Ordinal_1042();
  if (iVar8 == 0) {
    if (iVar5 == 0xc) {
      if (iVar7 + 0xc + (int)pvVar6 == param_4) {
LAB_680e988f:
        local_ec = Ordinal_1439(local_e4,pvVar6,1);
        if (local_ec == 0) {
          local_d8 = 0xffffff85;
          goto LAB_680e981e;
        }
        local_e0 = Ordinal_1114(local_ec);
        *(undefined1 *)((int)pvVar6 + local_e0) = 0;
        if (pvVar6 == (void *)0x0) {
          Ordinal_1130(local_c0,0xa4);
          if ((iVar7 == 0) || (sVar4 = Ordinal_1412(local_e4), sVar4 == 0)) {
            Ordinal_1203(local_c0,"_DEFAULT_",0x40);
            local_80 = 0xc;
            local_74 = 0;
            local_72 = 0;
            local_70 = 0;
LAB_680e9923:
            local_dc = xtra_getBufferRange(0,0,local_c0,param_3);
            if (local_dc == 0) {
              local_d8 = 0xffffff85;
              goto LAB_680e981e;
            }
            goto LAB_680e9bd6;
          }
          if (sVar4 == 1) {
            bVar2 = bitmap_readFontMapEntry();
            if (CONCAT31(extraout_var,bVar2) != 0) {
              iVar5 = playback_getFontMapData(param_6,(int)&local_1c,(int)local_c0,0,0);
              if (iVar5 == 0) {
LAB_680e998f:
                local_d8 = 0xffffff89;
                goto LAB_680e981e;
              }
              goto LAB_680e9923;
            }
          }
        }
        else {
          iVar5 = xtra_getBufferRange(0,0,(int *)0x0,param_3);
          local_dc = iVar5;
          if (iVar5 == 0) {
LAB_680e99b6:
            local_d8 = 0xffffff85;
            goto LAB_680e981e;
          }
          sVar4 = Ordinal_1412(local_e4);
          if (sVar4 == 0) {
            Ordinal_1130(local_c0,0xa4);
            Ordinal_1203(local_c0,"_DEFAULT_",0x40);
            local_80 = 0xc;
            local_72 = 0;
            local_70 = 0;
            local_74 = sVar4;
            iVar5 = xtra_replaceBufferRange(iVar5,local_e0,(int)pvVar6,local_c0);
            if (iVar5 != 0) {
LAB_680e9bd6:
              bVar1 = true;
              goto LAB_680e981e;
            }
          }
          else if (0 < sVar4) {
            bVar2 = true;
            for (; -1 < sVar4; sVar4 = sVar4 + -1) {
              pvVar10 = pvVar6;
              if ((0 < sVar4) &&
                 (bVar3 = bitmap_readFontMapEntry(), pvVar10 = local_1c, CONCAT31(extraout_var_00,bVar3) == 0))
              goto LAB_680e9813;
              local_1c = pvVar10;
              if (bVar2) {
                bVar2 = false;
              }
              else {
                pvVar10 = (void *)((int)local_1c - (int)local_d4);
                Ordinal_1130(local_c0,0xa4);
                if (((int)pvVar10 < 1) || (pvVar6 < pvVar10)) goto LAB_680e9813;
                iVar5 = playback_getFontMapData(param_6,(int)&local_d4,(int)local_c0,0,0);
                if (iVar5 == 0) goto LAB_680e998f;
                if (param_7 == 0) {
                  iVar5 = xtra_replaceBufferRange(local_dc,local_e0,(int)pvVar10,local_c0);
                }
                else {
                  local_e8 = (undefined4 *)0x0;
                  puVar9 = (undefined4 *)playback_computeSpriteRect(param_6,(ushort)local_cc,local_e0,pvVar10);
                  local_e8 = puVar9;
                  if (puVar9 == (undefined4 *)0x0) goto LAB_680e981e;
                  iVar7 = Ordinal_1114();
                  iVar5 = Ordinal_1201(iVar7,local_c0);
                  iVar5 = xtra_replaceBufferRange(local_dc,iVar7,iVar5,puVar9);
                  if (iVar7 != 0) {
                    Ordinal_1115(local_e8);
                    Ordinal_1113(&local_e8);
                  }
                }
                if (iVar5 == 0) goto LAB_680e99b6;
                local_e0 = local_e0 + (int)pvVar10;
              }
              local_d4 = local_1c;
              local_d0 = local_18;
              local_cc = local_14;
              local_c8 = local_10;
              local_c4 = local_c;
            }
            goto LAB_680e9bd6;
          }
        }
      }
    }
    else if (((iVar5 == 0) && (pvVar6 == (void *)0x0)) && (iVar7 == 0)) goto LAB_680e988f;
  }
LAB_680e9813:
  local_d8 = 0xffffff8b;
LAB_680e981e:
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = local_d8;
  }
  if (local_ec != 0) {
    Ordinal_1115(local_ec);
    Ordinal_1113(&local_ec);
  }
  if ((!bVar1) && (local_dc != 0)) {
    xtra_resetBuffer(local_dc);
  }
  return 0;
}



// ============================================================
// Function: bitmap_serializeFontData (FUN_680e9bf0)
// Address: 680e9bf0
// Size: 935 bytes
// Params: undefined4 * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_serializeFontData(undefined4 *param_1,int param_2,int param_3,int param_4)
{
  int local_2c;
  bool bVar1;
  int iVar2;
  int iVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_f4;
  undefined4 local_f0;
  int local_e0;
  int local_dc;
  undefined4 local_d8;
  int local_d4;
  int local_d0;
  undefined4 local_cc [41];
  undefined4 local_28 [5];
  int local_14;
  int local_10;
  uint local_8;
  
  iVar5 = 0;
  local_e0 = 0;
  local_d4 = 0;
  local_d8 = 0;
  local_dc = 0;
  bVar1 = false;
  local_d0 = 0;
  if ((((param_3 == 0) || (param_4 == 0)) || (iVar2 = Ordinal_1041(), iVar2 != 0)) ||
     ((param_2 != 0 && (iVar2 = Ordinal_1403(&local_d0,0), iVar2 == 0)))) goto LAB_680e9f41;
  iVar2 = xtra_getBufferSize(param_3);
  if (local_d0 != 0) {
    Ordinal_1426(local_d0,0xc);
    Ordinal_1426(local_d0,iVar2);
    local_f0 = Ordinal_1433(local_d0);
    Ordinal_1426(local_d0,0);
  }
  local_d4 = 0xc;
  if ((local_d0 == 0) || (iVar2 == 0)) {
LAB_680e9d22:
    local_d4 = iVar2 + 0xc;
    if (local_d0 != 0) {
      local_f4 = Ordinal_1433(local_d0);
      Ordinal_1423(local_d0,0);
    }
    local_d4 = local_d4 + 2;
    if (0 < iVar2) {
      do {
        xtra_readBufferRange(param_3,(int)&local_14,iVar5);
        xtra_appendToBuffer(param_3,local_cc,local_14);
        if (local_d0 != 0) {
          uVar6 = playback_getFontMapRef(param_4,(int)local_cc,(int)local_28);
          if (extraout_EAX == 0) goto LAB_680e9e09;
          local_28[0] = uVar6;
          bitmap_writeFontMapEntry();
        }
        iVar5 = local_10 + local_14;
        local_d4 = local_d4 + 0x14;
        local_dc = local_dc + 1;
      } while (iVar5 < iVar2);
    }
    iVar5 = local_dc;
    if ((iVar2 == 0) && (iVar2 = xtra_appendToBuffer(param_3,local_cc,0), iVar5 = local_dc, iVar2 != 0)) {
      if (local_d0 != 0) {
        playback_getFontMapRef(param_4,(int)local_cc,(int)local_28);
        if (extraout_EAX_00 == 0) goto LAB_680e9e09;
        local_28[0] = 0;
        bitmap_writeFontMapEntry();
      }
      local_d4 = local_d4 + 0x14;
      iVar5 = local_dc + 1;
    }
    sVar4 = (short)iVar5;
    if (local_d0 == 0) {
      if (sVar4 == 0) {
        local_d4 = local_d4 + -2;
      }
    }
    else {
      uVar6 = Ordinal_1433(local_d0);
      if (sVar4 != 0) {
        Ordinal_1432(local_d0,local_f0,0);
        Ordinal_1426(local_d0,sVar4 * 0x14 + 2);
      }
      Ordinal_1432(local_d0,local_f4,0);
      if (sVar4 == 0) {
        uVar6 = Ordinal_1433(local_d0);
        Ordinal_1434(local_d0,uVar6);
      }
      else {
        Ordinal_1423(local_d0,iVar5);
        Ordinal_1432(local_d0,uVar6,0);
      }
    }
    iVar5 = Ordinal_1042();
    if (iVar5 == 0) {
      if ((param_2 != 0) && (local_d0 != 0)) {
        uVar6 = Ordinal_1435(local_d0);
        uVar6 = Ordinal_1433(param_2,local_d0,0,uVar6);
        iVar5 = Ordinal_1431(param_2,uVar6);
        if (iVar5 == 0) goto LAB_680e9f41;
      }
      bVar1 = true;
    }
    else {
      local_d8 = bitmap_returnOutOfMemory();
    }
  }
  else {
    local_e0 = Ordinal_1126(iVar2 + 1,0);
    if ((local_e0 != 0) && (iVar3 = xtra_extractBufferBytes(param_3,0,iVar2,local_e0,iVar2 + 1), iVar3 != 0)) {
      Ordinal_1420(local_d0,local_e0,iVar2);
      goto LAB_680e9d22;
    }
LAB_680e9e09:
    local_d8 = 0xffffff86;
  }
LAB_680e9f41:
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = local_d8;
  }
  Ordinal_1127(&local_e0);
  if (!bVar1) {
    local_d4 = 0;
  }
  Ordinal_1407(&local_d0);
  return 0;
}



// ============================================================
// Function: bitmap_readFontRunData (FUN_680e9fa0)
// Address: 680e9fa0
// Size: 287 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readFontRunData(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_ESI;
  int iVar4;
  undefined4 local_dc [41];
  undefined4 local_38 [9];
  int local_14;
  int local_10;
  uint local_8;
  
  iVar4 = 0;
  xtra_readBufferValue(unaff_ESI,local_38);
  iVar1 = xtra_getBufferSize(unaff_ESI);
  iVar2 = xtra_setBufferPos(unaff_ESI,1);
  iVar3 = Ordinal_1114(iVar2);
  if (iVar3 != 0) {
    if (unaff_EBX != 0) {
      Ordinal_1429();
      Ordinal_1420();
      Ordinal_1420();
    }
    if (0 < iVar1) {
      do {
        xtra_readBufferRange(unaff_ESI,(int)&local_14,iVar4);
        xtra_appendToBuffer(unaff_ESI,local_dc,local_14);
        if (unaff_EBX != 0) {
          Ordinal_1429();
          Ordinal_1420();
        }
        iVar4 = local_10 + local_14;
      } while ((local_10 != 0) && (iVar4 < iVar1));
    }
    Ordinal_1115(iVar2);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeFontRunData (FUN_680ea0c0)
// Address: 680ea0c0
// Size: 288 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeFontRunData(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_d8;
  int local_d4;
  undefined4 local_d0 [41];
  int local_2c [9];
  uint local_8;
  
  iVar5 = 0;
  local_d8 = 0;
  local_d4 = 0;
  iVar1 = Ordinal_1418();
  local_d8 = Ordinal_1111(iVar1,0);
  iVar2 = Ordinal_1114(local_d8);
  iVar6 = iVar1;
  iVar3 = Ordinal_1409();
  if (((iVar3 != 0) && (iVar3 = Ordinal_1409(), iVar3 != 0)) &&
     (local_d4 = xtra_getBufferRange(0,0,(int *)0x0,local_2c), 0 < iVar1)) {
    do {
      iVar3 = Ordinal_1418();
      iVar4 = Ordinal_1409();
      if ((iVar4 == 0) || (iVar4 = xtra_replaceBufferRange(local_d4,iVar5 + iVar2,iVar3,local_d0), iVar4 == 0))
      {
        if (local_d4 != 0) {
          xtra_resetBuffer(local_d4);
          local_d4 = 0;
        }
        break;
      }
      iVar5 = iVar5 + iVar3;
    } while (iVar5 < iVar1);
  }
  if (local_d8 != 0) {
    Ordinal_1113(&local_d8,iVar6);
  }
  return 0;
}



// ============================================================
// Function: bitmap_loadTextMemberData (FUN_680ea1e0)
// Address: 680ea1e0
// Size: 214 bytes
// Params: int param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_loadTextMemberData(int param_1,int *param_2,int param_3)

{
  int local_2c;
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 *unaff_EDI;
  bool bVar3;
  undefined4 local_c;
  int local_8;
  
  bVar3 = false;
  local_c = 0;
  local_8 = 0;
  if ((unaff_EDI == (undefined4 *)0x0) || ((unaff_EDI[2] != 3 && (unaff_EDI[2] != 7)))) {
    local_8 = -0x79;
  }
  else {
    if (param_1 != 0) {
      local_c = Ordinal_1433(param_1);
    }
    if (param_3 == 0) {
      uVar2 = scoreEngine_getChannelRange(*(int *)(in_EAX + 0x20),*(short *)(unaff_EDI + 1),0);
      iVar1 = scoreEngine_getFrameData(*(int *)(in_EAX + 0x20),(short)uVar2);
      if (iVar1 == 0) {
        iVar1 = scoreEngine_getFrameData(*(int *)(in_EAX + 0x20),1);
      }
      iVar1 = bitmap_serializeFontData(&local_8,param_1,unaff_EDI[0x15],iVar1 + 0x14);
    }
    else {
      iVar1 = bitmap_readFontRunData();
    }
    bVar3 = iVar1 != 0;
    if (bVar3) goto LAB_680ea29a;
  }
  iVar1 = 0;
  if (param_1 != 0) {
    Ordinal_1432(param_1,local_c,0);
  }
  if (local_8 != 0) {
    rendering_initMemberSlot(unaff_EDI,local_8);
  }
LAB_680ea29a:
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
  }
  return bVar3;
}



// ============================================================
// Function: bitmap_writeStyleRunData (FUN_680ea2c0)
// Address: 680ea2c0
// Size: 353 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_writeStyleRunData(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_2;
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 8);
  puVar5 = (undefined2 *)0x0;
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  if ((*(int *)(param_1 + 0x51c) == 0) || (*(int *)(param_1 + 0x520) == 0)) {
LAB_680ea3d5:
    local_c = 1;
LAB_680ea3dc:
    if (puVar5 != (undefined2 *)0x0) {
      Ordinal_1115(*(undefined4 *)(param_1 + 0x51c));
    }
    if (local_c != 0) goto LAB_680ea409;
  }
  else {
    iVar3 = Ordinal_1041();
    if (iVar3 == 0) {
      if (iVar2 != 0) {
        local_10 = Ordinal_1433(iVar2);
        Ordinal_1423(iVar2,*(undefined2 *)(param_1 + 0x524));
      }
      puVar5 = (undefined2 *)Ordinal_1114(*(undefined4 *)(param_1 + 0x51c));
      iVar3 = (int)*(short *)(param_1 + 0x524);
      local_8 = (iVar3 + 1) * 4 + 2;
      if (iVar2 != 0) {
        for (; -1 < iVar3; iVar3 = iVar3 + -1) {
          Ordinal_1423(iVar2,*puVar5);
          Ordinal_1423(iVar2,puVar5[1]);
          puVar5 = puVar5 + 2;
        }
      }
      if (*(int *)(param_1 + 0x520) != 0) {
        iVar3 = Ordinal_1116(*(int *)(param_1 + 0x520));
        local_8 = local_8 + iVar3;
        if (iVar2 != 0) {
          param_2 = Ordinal_1120(*(undefined4 *)(param_1 + 0x520),0);
          uVar4 = Ordinal_1114(param_2);
          Ordinal_1420(iVar2,uVar4,iVar3);
          Ordinal_1113(&param_2);
        }
      }
      iVar3 = Ordinal_1042();
      if (iVar3 == 0) goto LAB_680ea3d5;
      iVar3 = bitmap_returnOutOfMemory();
      lingo_formatDebugMsg(piVar1,iVar3);
      goto LAB_680ea3dc;
    }
  }
  local_8 = 0;
  if (iVar2 != 0) {
    Ordinal_1432(iVar2,local_10,0);
  }
LAB_680ea409:
  if (param_3 != (int *)0x0) {
    *param_3 = local_8;
  }
  return local_c;
}



// ============================================================
// Function: bitmap_getTextFieldRef (FUN_680ea430)
// Address: 680ea430
// Size: 45 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextFieldRef(int param_1)
{
  Ordinal_1113(param_1 + 0x51c);
  Ordinal_1113(param_1 + 0x520);
  *(undefined2 *)(param_1 + 0x524) = 0;
  return 0;
}



// ============================================================
// Function: bitmap_renderTextMember (FUN_680ea460)
// Address: 680ea460
// Size: 555 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_renderTextMember(void)
{
  short sVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBX;
  int *unaff_ESI;
  undefined4 local_1ac;
  int local_1a8;
  undefined4 local_1a4;
  undefined2 local_198;
  undefined1 local_195;
  undefined4 local_174;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1a8 = 0;
  iVar2 = rendering_getMemberData(unaff_EBX,unaff_ESI);
  if (iVar2 == 0) goto LAB_680ea660;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_1a4 = local_1a4 & 0xffff0000;
  memset((void *)((int)&local_1a4 + 2),0,0x18e);
  sVar1 = scoreEngine_getChannelCount(*(int *)(unaff_EBX + 0x20),(short)unaff_ESI[1]);
  local_1a4 = CONCAT22(extraout_var,sVar1);
  local_198 = 0;
  local_195 = 0xff;
  if (unaff_ESI[2] == 3) {
    local_174 = 7;
  }
  else if (unaff_ESI[2] == 7) {
    sVar1 = (short)unaff_ESI[0x20];
    if (sVar1 == 1) {
LAB_680ea50a:
      local_174 = 8;
    }
    else if (sVar1 == 2) {
      local_174 = 9;
    }
    else {
      if (sVar1 != 3) goto LAB_680ea50a;
      local_174 = 10;
    }
  }
  iVar2 = bitmap_setupSpriteText(unaff_EBX,&local_1a4,4);
  if (iVar2 != 0) {
    iVar2 = display_getRenderFormat(&local_14,0);
    if (iVar2 != 0) {
      if (local_14 == 0x18) {
        local_14 = 0x20;
      }
      local_d4 = local_d4 - local_dc;
      local_d0 = local_d0 - local_d8;
      local_dc = 0;
      local_d8 = 0;
      local_54 = local_54 - local_5c;
      local_50 = local_50 - local_58;
      local_5c = (uint)*(byte *)(unaff_ESI + 0x16);
      local_58 = local_5c;
      iVar2 = Ordinal_1650(local_14,local_10,local_c,local_d4,local_d0,0);
      if (iVar2 != 0) {
        local_1a8 = Ordinal_1600();
        if (local_1a8 != 0) {
          uVar3 = lingo_isValidObject(*(int *)(*(int *)(unaff_EBX + 0x20) + 4));
          iVar4 = Ordinal_1613(local_1a8,0,uVar3);
          if (iVar4 != 0) {
            iVar4 = Ordinal_1604(local_1a8,iVar2);
            if (iVar4 != 0) {
              local_1ac = 0x1ffffff;
              iVar4 = Ordinal_1619(local_1a8,&local_dc,&local_1ac);
              if (iVar4 != 0) {
                bitmap_dispatchDraw(unaff_EBX,local_1a8,&local_1a4);
                if (local_14 == 0x20) {
                  Ordinal_1684(iVar2,0xff);
                }
              }
            }
          }
        }
      }
    }
  }
  rendering_isStateValid((int)unaff_ESI);
LAB_680ea660:
  Ordinal_1604(local_1a8,0);
  Ordinal_1601(&local_1a8);
  return 0;
}



// ============================================================
// Function: bitmap_captureTextImage (FUN_680ea690)
// Address: 680ea690
// Size: 154 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_captureTextImage(void)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  local_c = bitmap_renderTextMember();
  if (local_c != 0) {
    local_10 = Ordinal_1111(0,0);
    if (local_10 != 0) {
      iVar2 = Ordinal_1404(&local_8,local_10,3);
      if (iVar2 != 0) {
        uVar3 = lingo_isValidObject(*(int *)(*(int *)(in_EAX + 0x20) + 4));
        uVar3 = Ordinal_1610(uVar3);
        iVar2 = Ordinal_1660(local_8,local_c,uVar3,FOURCC_PICH,0);
        bVar1 = true;
        if (iVar2 != 0) goto LAB_680ea701;
      }
    }
  }
  bVar1 = false;
LAB_680ea701:
  Ordinal_1407(&local_8);
  if (!bVar1) {
    Ordinal_1113(&local_10);
  }
  Ordinal_1653(&local_c);
  return local_10;
}



// ============================================================
// Function: bitmap_buildFontRunMap (FUN_680ea730)
// Address: 680ea730
// Size: 382 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_buildFontRunMap(void *this,int param_1,int param_2)
{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int extraout_EAX;
  int iVar6;
  int *piVar7;
  short sVar8;
  int local_bc;
  undefined4 local_b8 [41];
  int local_14;
  int local_10;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x54);
  sVar8 = 0;
  iVar6 = 0;
  local_bc = 0;
  if ((iVar1 != 0) && (param_2 != 0)) {
    local_bc = Ordinal_1111(4,0);
    puVar2 = (undefined2 *)Ordinal_1114(local_bc);
    *puVar2 = 0;
    iVar3 = xtra_getBufferSize(iVar1);
    if (0 < iVar3) {
      do {
        sVar8 = sVar8 + 1;
        Ordinal_1115(local_bc);
        iVar4 = Ordinal_1117(&local_bc,sVar8 * 0x14 + 4,4);
        psVar5 = (short *)Ordinal_1114(local_bc);
        if (iVar4 == 0) {
LAB_680ea87d:
          if (local_bc != 0) {
            Ordinal_1115(local_bc);
            Ordinal_1113(&local_bc);
          }
          goto LAB_680ea899;
        }
        *psVar5 = sVar8;
        xtra_readBufferRange(iVar1,(int)&local_14,iVar6);
        xtra_appendToBuffer(iVar1,local_b8,local_14);
        piVar7 = (int *)playback_getFontMapRef(param_2,(int)local_b8,(int)(psVar5 + sVar8 * 10 + -9));
        if (extraout_EAX == 0) goto LAB_680ea87d;
        *piVar7 = iVar6;
        iVar6 = local_10 + local_14;
      } while (iVar6 < iVar3);
    }
    Ordinal_1115(local_bc);
    *(int *)this = local_bc;
    return 0;
  }
LAB_680ea899:
  return 0;
}



// ============================================================
// Function: bitmap_findSpriteByMember (FUN_680ea8b0)
// Address: 680ea8b0
// Size: 131 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_findSpriteByMember(int param_1,undefined4 *param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_8;
  
  local_8 = -1;
  iVar1 = playback_getLifecycleRef(in_EAX);
  iVar5 = *(int *)(iVar1 + 0x120);
  if (iVar5 <= *(int *)(iVar1 + 0x124)) {
    iVar2 = iVar5 * 400;
    do {
      puVar4 = (undefined4 *)(*(int *)(iVar1 + 0x34) + iVar2);
      iVar3 = playback_getSpriteData(iVar1,puVar4);
      if (iVar3 == param_1) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = puVar4;
        }
        local_8 = iVar5;
        if (iVar5 != -1) {
          return iVar5;
        }
        break;
      }
      iVar2 = iVar2 + 400;
      iVar5 = iVar5 + 1;
    } while (iVar5 <= *(int *)(iVar1 + 0x124));
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  return local_8;
}



// ============================================================
// Function: bitmap_syncTextSelection (FUN_680ea940)
// Address: 680ea940
// Size: 175 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_syncTextSelection(void *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int *unaff_ESI;
  undefined4 local_2c [9];
  uint local_8;
  
  iVar1 = xtra_getBufferSize((int)unaff_ESI);
  if ((int)this < param_2) {
    xtra_buildSelectionRects(param_1,unaff_ESI,(int)this,param_2 - (int)this,unaff_EBX,1);
  }
  if ((((int *)*unaff_EBX != (int *)0x0) && (param_2 == iVar1)) &&
     (iVar1 = *(int *)(*(int *)*unaff_EBX + 8), 0 < iVar1)) {
    iVar2 = xtra_readBufferValue((int)unaff_ESI,local_2c);
    if (iVar2 != 0) {
      *(undefined4 *)
       (*(int *)(*(int *)(*(undefined4 **)*unaff_EBX)[9] + -4 + iVar1 * 4) + 8 +
       *(int *)**(undefined4 **)*unaff_EBX) = local_2c[0];
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_setTextSelection (FUN_680ea9f0)
// Address: 680ea9f0
// Size: 229 bytes
// Params: int param_1, int * param_2, void * param_3, void * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setTextSelection(int param_1,int *param_2,void *param_3,void *param_4)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  void *this;
  int *piVar5;
  int **ppiVar6;
  undefined4 local_c;
  
  piVar1 = param_2;
  local_c = 0;
  iVar2 = rendering_getMemberData(param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  if ((piVar1[2] == 3) || (piVar1[2] == 7)) {
    this = param_3;
    if ((int)param_3 < 0) {
      this = (void *)0x0;
    }
    pvVar4 = param_4;
    if ((int)param_4 < (int)this) {
      pvVar4 = this;
    }
    pvVar3 = (void *)xtra_getBufferSize(piVar1[0x15]);
    if (((int)pvVar3 <= (int)pvVar4) && (pvVar4 = pvVar3, (int)pvVar3 < (int)this)) {
      this = pvVar3;
    }
    piVar1[0x21] = (int)this;
    piVar1[0x22] = (int)pvVar4;
    if (piVar1[0x15] != 0) {
      bitmap_getMovieStageRef(param_1,(int)piVar1);
      ppiVar6 = &param_2;
      piVar5 = piVar1;
      playback_getLifecycleRef(param_1);
      bitmap_findSpriteByMember((int)piVar5,ppiVar6);
      if (param_2 != (int *)0x0) {
        iVar2 = lingo_isValidObject(*(int *)(*(int *)(param_1 + 0x20) + 4));
        local_c = bitmap_syncTextSelection(this,iVar2,(int)pvVar4);
      }
      piVar1[0x23] = 0;
      rendering_setMemberData(param_1,piVar1,1);
    }
  }
  rendering_isStateValid((int)piVar1);
  return local_c;
}



// ============================================================
// Function: bitmap_setTextScrollPos (FUN_680eaae0)
// Address: 680eaae0
// Size: 96 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setTextScrollPos(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = rendering_getMemberData(param_1,param_2);
  if (iVar1 != 0) {
    if (((param_2[2] == 3) || (param_2[2] == 7)) && (param_2[0x15] != 0)) {
      iVar1 = xtra_getBufferSize(param_2[0x15]);
      if (iVar1 <= param_3) {
        param_3 = (int)(short)iVar1;
      }
      param_2[0x24] = param_3;
      rendering_setMemberData(param_1,param_2,1);
      uVar2 = 1;
    }
    rendering_isStateValid((int)param_2);
  }
  return uVar2;
}



// ============================================================
// Function: bitmap_getTextScrollPos (FUN_680eab40)
// Address: 680eab40
// Size: 64 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextScrollPos(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  iVar1 = rendering_getMemberData(param_1,param_2);
  if (iVar1 != 0) {
    if (((param_2[2] == 3) || (param_2[2] == 7)) && (param_2[0x15] != 0)) {
      iVar2 = param_2[0x24];
    }
    rendering_isStateValid((int)param_2);
  }
  return iVar2;
}



// ============================================================
// Function: bitmap_getTextFieldData (FUN_680eab80)
// Address: 680eab80
// Size: 149 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextFieldData(int param_1,int *param_2)
{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) == 3) {
    bVar1 = *(byte *)(param_1 + 0x59);
    *param_2 = (uint)*(byte *)(param_1 + 0x58) + (uint)bVar1;
    iVar3 = (int)(short)(ushort)(bVar1 >> 1);
    param_2[1] = (uint)*(byte *)(param_1 + 0x58) + iVar3;
    param_2[2] = (uint)*(byte *)(param_1 + 0x5a) + *param_2;
    param_2[3] = (uint)*(byte *)(param_1 + 0x5a) + (uint)*(byte *)(param_1 + 0x58) + iVar3;
    return 0;
  }
  sVar2 = *(short *)(param_1 + 0x80);
  if (sVar2 == 1) {
    *param_2 = 2;
    param_2[1] = 2;
    param_2[2] = 2;
    param_2[3] = 2;
  }
  else if ((sVar2 == 2) || (sVar2 == 3)) {
    param_2[1] = 1;
    *param_2 = 0x10;
    param_2[2] = 0;
    param_2[3] = 0;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_scaleTextRuns (FUN_680eac20)
// Address: 680eac20
// Size: 400 bytes
// Params: void * this, int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_scaleTextRuns(void *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int iVar4;
  undefined4 local_dc [16];
  int local_9c;
  int local_98;
  int local_94;
  int local_38 [7];
  int local_1c;
  int local_14;
  int local_10;
  uint local_8;
  
  iVar4 = 0;
  if (this != (void *)0x0) {
    iVar1 = xtra_getBufferSize((int)this);
    iVar2 = xtra_getTextFormatFlag((int)this);
    iVar4 = xtra_insertIntoBuffer((int)this,0,iVar1);
    iVar3 = xtra_readBufferValue(iVar4,local_38);
    if (iVar3 != 0) {
      local_38[0] = (local_38[0] * param_1) / param_2;
      if ((0 < local_1c) && (local_1c = (local_1c * param_3) / unaff_EBX, local_1c < 1)) {
        local_1c = 1;
      }
      iVar3 = xtra_writeBufferMetrics(iVar4,local_38);
      if (iVar3 != 0) {
        iVar3 = 0;
        if (0 < iVar1) {
          do {
            xtra_readBufferRange(iVar4,(int)&local_14,iVar3);
            xtra_appendToBuffer(iVar4,local_dc,local_14);
            local_9c = (local_9c * param_3) / unaff_EBX;
            if ((0 < local_98) && (local_98 = (local_98 * param_3) / unaff_EBX, local_98 < 1)) {
              local_98 = 1;
            }
            if ((0 < local_94) && (local_94 = (local_94 * param_3) / unaff_EBX, local_94 < 1)) {
              local_94 = 1;
            }
            iVar3 = xtra_copyBufferRange(iVar4,local_dc,local_14,local_10);
            if (iVar3 == 0) goto LAB_680ead96;
            iVar3 = local_10 + local_14;
          } while ((local_10 != 0) && (iVar3 < iVar1));
        }
        xtra_isTextFormat(iVar4,(iVar2 * param_3) / unaff_EBX);
        return 0;
      }
    }
  }
LAB_680ead96:
  xtra_resetBuffer(iVar4);
  return 0;
}



// ============================================================
// Function: bitmap_getTextFieldState (FUN_680eadb0)
// Address: 680eadb0
// Size: 38 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextFieldState(int param_1)
{
  xtra_resetBuffer(*(int *)(param_1 + 0x94));
  Ordinal_1130(param_1 + 0x94,0xc);
  return 0;
}



// ============================================================
// Function: bitmap_clearAltStyleRun (FUN_680eade0)
// Address: 680eade0
// Size: 45 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_clearAltStyleRun(int param_1)
{
  Ordinal_1113(param_1 + 0x64c);
  Ordinal_1113(param_1 + 0x650);
  *(undefined2 *)(param_1 + 0x654) = 0;
  return 0;
}



// ============================================================
// Function: bitmap_writeAltStyleRun (FUN_680eae10)
// Address: 680eae10
// Size: 113 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeAltStyleRun(int param_1,int param_2,int *param_3)
{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined2 *)(param_1 + 0x524);
  uVar2 = *(undefined4 *)(param_1 + 0x520);
  uVar3 = *(undefined4 *)(param_1 + 0x51c);
  *(undefined4 *)(param_1 + 0x51c) = *(undefined4 *)(param_1 + 0x64c);
  *(undefined4 *)(param_1 + 0x520) = *(undefined4 *)(param_1 + 0x650);
  *(undefined2 *)(param_1 + 0x524) = *(undefined2 *)(param_1 + 0x654);
  bitmap_writeStyleRunData(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x51c) = uVar3;
  *(undefined4 *)(param_1 + 0x520) = uVar2;
  *(undefined2 *)(param_1 + 0x524) = uVar1;
  return 0;
}



// ============================================================
// Function: bitmap_mapFontWidths (FUN_680eae90)
// Address: 680eae90
// Size: 137 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_mapFontWidths(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  short sVar8;
  
  sVar8 = 0;
  iVar3 = playback_mapFont(param_1,0,param_2,0);
  if (iVar3 != 0) {
    iVar4 = Ordinal_1114(param_1);
    iVar6 = 0;
    if (0 < param_4) {
      psVar7 = (short *)(param_3 + 2);
      do {
        sVar1 = *psVar7;
        iVar5 = param_2;
        if (iVar6 != param_4 + -1) {
          iVar5 = (int)psVar7[2];
        }
        iVar5 = iVar5 - sVar1;
        sVar2 = 0;
        *psVar7 = sVar8;
        if (0 < iVar5) {
          sVar2 = Ordinal_1274(sVar1 + iVar4,iVar5,0,0);
        }
        iVar6 = iVar6 + 1;
        sVar8 = *psVar7 + sVar2;
        psVar7 = psVar7 + 2;
      } while (iVar6 < param_4);
    }
    if (iVar4 != 0) {
      Ordinal_1115(param_1);
    }
  }
  return iVar3;
}



// ============================================================
// Function: bitmap_setTextFieldRect (FUN_680eaf20)
// Address: 680eaf20
// Size: 99 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setTextFieldRect(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  
  uVar2 = 0;
  iVar1 = rendering_getMemberData(param_1,unaff_ESI);
  if (iVar1 != 0) {
    if (((unaff_ESI[2] == 3) || (unaff_ESI[2] == 7)) && (unaff_ESI[0x15] != 0)) {
      xtra_applyBufferStyle(unaff_ESI[0x15],param_4,in_EAX - param_4,param_2,param_3);
      rendering_updateMemberMedia(param_1,unaff_ESI);
      bitmap_getTextFieldState((int)unaff_ESI);
      uVar2 = 1;
    }
    rendering_isStateValid((int)unaff_ESI);
  }
  return uVar2;
}



// ============================================================
// Function: bitmap_setTextFontById (FUN_680eaf90)
// Address: 680eaf90
// Size: 41 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_setTextFontById(void *this,undefined4 param_1)
{
  undefined4 local_c [2];
  
  local_c[0] = 1;
  bitmap_setTextFieldRect(param_1,(int)local_c,1,(int)this);
  return 0;
}



// ============================================================
// Function: bitmap_setTextFontByTag (FUN_680eafc0)
// Address: 680eafc0
// Size: 40 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_setTextFontByTag(undefined4 param_1,undefined4 param_2)
{
  short in_AX;
  undefined4 local_c;
  int local_8;
  
  local_8 = (int)in_AX;
  local_c = 0x87;
  bitmap_setTextFieldRect(param_2,(int)&local_c,1,0);
  return 0;
}



// ============================================================
// Function: bitmap_setTextAlignment (FUN_680eaff0)
// Address: 680eaff0
// Size: 93 bytes
// Params: short param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall bitmap_setTextAlignment(short param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  *(short *)(in_EAX + 0x5c) = param_1;
  if (param_1 == -1) {
    local_8 = 3;
  }
  else if (param_1 == 0) {
    local_8 = 1;
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    local_8 = 2;
  }
  local_c = 0x81;
  uVar1 = bitmap_setTextFieldRect(param_2,(int)&local_c,1,0);
  return uVar1;
}



// ============================================================
// Function: bitmap_applyTextStyleFlags (FUN_680eb050)
// Address: 680eb050
// Size: 236 bytes
// Params: ushort param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_applyTextStyleFlags(ushort param_1,int param_2)
{
  uint uVar1;
  undefined4 unaff_EDI;
  bool bVar2;
  uint local_48 [17];
  
  uVar1 = 1;
  if (param_1 == 0) {
    local_48[0] = 3;
    local_48[1] = 1;
  }
  else {
    bVar2 = (param_1 & 2) != 0;
    if (bVar2) {
      local_48[0] = 5;
      local_48[1] = 1;
    }
    uVar1 = (uint)bVar2;
    if ((param_1 & 1) != 0) {
      local_48[uVar1 * 2] = 4;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
    if ((param_1 & 4) != 0) {
      local_48[uVar1 * 2] = 6;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
    if ((param_1 & 0x10) != 0) {
      local_48[uVar1 * 2] = 7;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
    if ((param_1 & 8) != 0) {
      local_48[uVar1 * 2] = 8;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
    if ((param_1 & 0x20) != 0) {
      local_48[uVar1 * 2] = 9;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
    if ((param_1 & 0x4000) != 0) {
      local_48[uVar1 * 2] = 0xb;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
    if ((param_1 & 0x8000) != 0) {
      local_48[uVar1 * 2] = 10;
      local_48[uVar1 * 2 + 1] = 1;
      uVar1 = uVar1 + 1;
    }
  }
  bitmap_setTextFieldRect(unaff_EDI,(int)local_48,uVar1,param_2);
  return 0;
}



// ============================================================
// Function: bitmap_applyDefaultFont (FUN_680eb140)
// Address: 680eb140
// Size: 202 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_applyDefaultFont(undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  undefined4 local_54;
  undefined1 *local_50;
  undefined4 local_4c;
  undefined1 local_48 [64];
  uint local_8;
  
  local_4c = param_1;
  iVar2 = *(int *)(unaff_EDI + 0x18);
  if ((unaff_EBX != 0) &&
     ((Ordinal_1130(local_48,0x40), DAT_681968e8 != '\0' ||
      (iVar1 = Ordinal_1517(DAT_681956e0,0x1518,&DAT_681968e8,0x40), iVar1 != 0)))) {
    Ordinal_1203(local_48);
    iVar2 = playback_resolveFontMapping(iVar2,(int *)(*(int *)(unaff_EDI + 0x20) + 0x50c),0x681968e8,(int)local_48,
                         0x40,(int *)0x0,0);
    if (iVar2 != 0) {
      local_50 = local_48;
      local_54 = 0;
      bitmap_setTextFieldRect(unaff_EDI,(int)&local_54,1,param_2);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_setTextForeColor (FUN_680eb210)
// Address: 680eb210
// Size: 74 bytes
// Params: undefined2 * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall bitmap_setTextForeColor(undefined2 *param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_EDI;
  undefined4 local_10;
  undefined2 *local_c;
  undefined2 local_8 [2];
  
  uVar1 = 0;
  if ((-1 < in_EAX) && (-1 < unaff_EBX)) {
    lingo_checkColorSpace(*(int *)(*(int *)(unaff_EDI + 0x20) + 4),param_1,local_8);
    local_c = local_8;
    local_10 = 2;
    uVar1 = bitmap_setTextFieldRect(unaff_EDI,(int)&local_10,1,in_EAX);
  }
  return uVar1;
}



// ============================================================
// Function: bitmap_setTextBackColor (FUN_680eb260)
// Address: 680eb260
// Size: 93 bytes
// Params: undefined2 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_setTextBackColor(undefined2 *param_1)
{
  int in_EAX;
  int unaff_EDI;
  undefined4 local_10;
  undefined2 *local_c;
  undefined2 local_8;
  undefined1 local_6;
  
  rendering_updateMemberMedia(unaff_EDI,in_EAX);
  lingo_checkColorSpace(*(int *)(*(int *)(unaff_EDI + 0x20) + 4),param_1,&local_8);
  local_c = &local_8;
  *(undefined2 *)(in_EAX + 0x5e) = local_8;
  *(undefined1 *)(in_EAX + 0x60) = local_6;
  local_10 = 0x88;
  *(undefined1 *)(in_EAX + 0x61) = 1;
  bitmap_setTextFieldRect(unaff_EDI,(int)&local_10,1,0);
  return 0;
}



// ============================================================
// Function: bitmap_resizeTextField (FUN_680eb2c0)
// Address: 680eb2c0
// Size: 102 bytes
// Params: void * this, undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_resizeTextField(void *this,undefined4 param_1,int param_2)
{
  int *in_EAX;
  undefined4 local_c;
  int local_8;
  
  local_8 = in_EAX[2] - *in_EAX;
  local_c = 0x80;
  *(int *)((int)this + 0x70) = (*(int *)((int)this + 0x68) - *in_EAX) + in_EAX[2];
  if ((param_2 != 0) || (*(int *)((int)this + 0x78) == 0)) {
    *(int *)((int)this + 0x78) = in_EAX[3] - in_EAX[1];
  }
  *(int *)((int)this + 0x74) = (*(int *)((int)this + 0x6c) - in_EAX[1]) + in_EAX[3];
  bitmap_setTextFieldRect(param_1,(int)&local_c,1,0);
  return 0;
}



// ============================================================
// Function: bitmap_clearTextField (FUN_680eb330)
// Address: 680eb330
// Size: 50 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_clearTextField(int param_1)
{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    xtra_resetBuffer(*(int *)(unaff_ESI + 0x54));
    *(undefined4 *)(unaff_ESI + 0x54) = 0;
    bitmap_getTextFieldState(unaff_ESI);
  }
  bitmap_getMovieStageRef(param_1,unaff_ESI);
  *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffffdff;
  return 0;
}



// ============================================================
// Function: bitmap_readStyleRunStream (FUN_680eb370)
// Address: 680eb370
// Size: 500 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_readStyleRunStream(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  piVar2 = *(int **)(*(int *)(param_1 + 4) + 8);
  local_8 = 0;
  local_c = 0;
  if (*(int *)(param_1 + 0x51c) != 0) {
    Ordinal_1113((int *)(param_1 + 0x51c));
  }
  piVar1 = (int *)(param_1 + 0x520);
  if (*(int *)(param_1 + 0x520) != 0) {
    Ordinal_1113(piVar1);
  }
  *(undefined2 *)(param_1 + 0x524) = 0;
  iVar5 = Ordinal_1041();
  if (iVar5 != 0) goto LAB_680eb53e;
  if (param_3 == 0) {
    return 1;
  }
  local_8 = -0x78;
  if (param_3 < 2) goto LAB_680eb53e;
  sVar3 = Ordinal_1412(param_2);
  *(short *)(param_1 + 0x524) = sVar3;
  if (sVar3 < 1) {
    if (sVar3 == 0) {
      return 1;
    }
    goto LAB_680eb53e;
  }
  iVar5 = sVar3 * 4 + 4;
  iVar9 = (param_3 - iVar5) + -2;
  if (iVar9 < 0) goto LAB_680eb53e;
  iVar5 = Ordinal_1111(iVar5,0);
  *(int *)(param_1 + 0x51c) = iVar5;
  if (iVar5 == 0) {
    local_8 = -0x7a;
    goto LAB_680eb53e;
  }
  puVar6 = (undefined2 *)Ordinal_1114(iVar5);
  for (iVar5 = (int)*(short *)(param_1 + 0x524); -1 < iVar5; iVar5 = iVar5 + -1) {
    uVar4 = Ordinal_1412(param_2);
    *puVar6 = uVar4;
    sVar3 = Ordinal_1412(param_2);
    puVar6[1] = sVar3;
    if (iVar9 < sVar3) goto LAB_680eb522;
    puVar6 = puVar6 + 2;
  }
  iVar5 = Ordinal_1439(param_2,iVar9,0);
  *piVar1 = iVar5;
  if (iVar5 == 0) {
    local_8 = -0x7a;
  }
  else {
    uVar7 = rendering_updateChannelState(param_1 + 0x48c);
    if ((uVar7 < 0x1100) && (0 < iVar9)) {
      uVar8 = Ordinal_1114(*piVar1);
      playback_renderSpriteEx((int)piVar2,param_1 + 0x50c,uVar8,iVar9);
      Ordinal_1115(*piVar1);
      iVar5 = *(short *)(param_1 + 0x524) + 1;
      puVar6 = puVar6 + iVar5 * -2;
      iVar5 = bitmap_mapFontWidths(*piVar1,iVar9,(int)puVar6,iVar5);
      if (iVar5 == 0) goto LAB_680eb522;
      if (*piVar1 != 0) {
        Ordinal_1113(piVar1);
      }
      *piVar1 = iVar5;
    }
    iVar5 = Ordinal_1042();
    if (iVar5 == 0) {
      local_c = 1;
    }
    else {
      local_8 = -0x74;
    }
  }
LAB_680eb522:
  if (puVar6 != (undefined2 *)0x0) {
    Ordinal_1115(*(undefined4 *)(param_1 + 0x51c));
  }
  if (local_c != 0) {
    return local_c;
  }
LAB_680eb53e:
  bitmap_getTextFieldRef(param_1);
  if (local_8 != 0) {
    lingo_formatDebugMsg(piVar2,local_8);
  }
  return local_c;
}



// ============================================================
// Function: bitmap_initStyleRunBuffers (FUN_680eb570)
// Address: 680eb570
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_initStyleRunBuffers(int param_1)
{
  undefined4 uVar1;
  
  bitmap_getTextFieldRef(param_1);
  uVar1 = Ordinal_1111(4,1);
  *(undefined4 *)(param_1 + 0x51c) = uVar1;
  uVar1 = Ordinal_1111(0,0);
  *(undefined4 *)(param_1 + 0x520) = uVar1;
  return 0;
}



// ============================================================
// Function: bitmap_updateTextField (FUN_680eb5a0)
// Address: 680eb5a0
// Size: 255 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_updateTextField(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = playback_walkLifecycleChain(param_2);
  if (*(int *)(iVar1 + 300) != 0) {
    iVar3 = 1;
    if (*(int *)(iVar1 + 0x140) < *(int *)(iVar1 + 0x148)) {
      local_c = *(int *)(iVar1 + 0x148) - *(int *)(iVar1 + 0x140);
    }
    else {
      local_c = 1;
    }
    if (*(int *)(iVar1 + 0x130) < *(int *)(iVar1 + 0x138)) {
      local_8 = *(int *)(iVar1 + 0x138) - *(int *)(iVar1 + 0x130);
    }
    else {
      local_8 = 1;
    }
    if (*(int *)(iVar1 + 0x144) < *(int *)(iVar1 + 0x14c)) {
      param_2 = *(int *)(iVar1 + 0x14c) - *(int *)(iVar1 + 0x144);
    }
    else {
      param_2 = 1;
    }
    if (*(int *)(iVar1 + 0x134) < *(int *)(iVar1 + 0x13c)) {
      iVar3 = *(int *)(iVar1 + 0x13c) - *(int *)(iVar1 + 0x134);
    }
    iVar1 = (local_c << 0x10) / local_8;
    iVar3 = (param_2 << 0x10) / iVar3;
    if (((*(int *)(param_1 + 0x98) != iVar1) || (*(int *)(param_1 + 0x9c) != iVar3)) ||
       (iVar2 = *(int *)(param_1 + 0x94), iVar2 == 0)) {
      bitmap_getTextFieldState(param_1);
      *(int *)(param_1 + 0x9c) = iVar3;
      *(int *)(param_1 + 0x98) = iVar1;
      iVar2 = bitmap_scaleTextRuns(*(void **)(param_1 + 0x54),local_c,local_8,param_2);
      *(int *)(param_1 + 0x94) = iVar2;
    }
    return iVar2;
  }
  return *(int *)(param_1 + 0x54);
}



// ============================================================
// Function: bitmap_getTextFieldSize (FUN_680eb6a0)
// Address: 680eb6a0
// Size: 59 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextFieldSize(int param_1,int param_2)
{
  *(int *)(param_1 + 0x54) = param_2;
  if (*(char *)(param_1 + 0x5b) != '\0') {
    xtra_isTextFormat(param_2,*(undefined4 *)(param_1 + 100));
    bitmap_getTextFieldState(param_1);
    return 0;
  }
  xtra_isTextFormat(param_2,0);
  bitmap_getTextFieldState(param_1);
  return 0;
}



// ============================================================
// Function: bitmap_getScaledStyleRun (FUN_680eb6e0)
// Address: 680eb6e0
// Size: 111 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getScaledStyleRun(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = bitmap_updateTextField(param_1,param_2);
  if (iVar1 == *(int *)(param_1 + 0x54)) {
    Ordinal_1162(*(undefined4 *)(param_1 + 0x8c));
    return *(undefined4 *)(param_1 + 0x8c);
  }
  iVar1 = lingo_isValidObject(*(int *)(*(int *)(param_2 + 0x20) + 4));
  if (*(int *)(param_1 + 0x8c) != 0) {
    bitmap_syncTextSelection(*(void **)(param_1 + 0x84),iVar1,*(int *)(param_1 + 0x88));
  }
  return 0;
}



// ============================================================
// Function: bitmap_readAltStyleRunStream (FUN_680eb750)
// Address: 680eb750
// Size: 151 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readAltStyleRunStream(int param_1,undefined4 param_2,int param_3)
{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined2 *)(param_1 + 0x524);
  uVar2 = *(undefined4 *)(param_1 + 0x520);
  uVar3 = *(undefined4 *)(param_1 + 0x51c);
  *(undefined4 *)(param_1 + 0x51c) = *(undefined4 *)(param_1 + 0x64c);
  *(undefined4 *)(param_1 + 0x520) = *(undefined4 *)(param_1 + 0x650);
  *(undefined2 *)(param_1 + 0x524) = *(undefined2 *)(param_1 + 0x654);
  bitmap_readStyleRunStream(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x64c) = *(undefined4 *)(param_1 + 0x51c);
  *(undefined4 *)(param_1 + 0x650) = *(undefined4 *)(param_1 + 0x520);
  *(undefined4 *)(param_1 + 0x51c) = uVar3;
  *(undefined4 *)(param_1 + 0x520) = uVar2;
  *(undefined2 *)(param_1 + 0x654) = *(undefined2 *)(param_1 + 0x524);
  *(undefined2 *)(param_1 + 0x524) = uVar1;
  return 0;
}



// ============================================================
// Function: bitmap_recalcTextLayout (FUN_680eb7f0)
// Address: 680eb7f0
// Size: 240 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_recalcTextLayout(void)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  int local_48;
  int local_44;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_18;
  int local_14;
  uint local_8;
  
  iVar4 = *unaff_ESI;
  piVar1 = (int *)unaff_ESI[4];
  local_34 = lingo_isValidObject(*(int *)(*(int *)(unaff_ESI[1] + 0x20) + 4));
  bitmap_getTextFieldData(iVar4,&local_48);
  local_2c = piVar1[1] - local_44;
  local_30 = *piVar1 - local_48;
  iVar2 = playback_initLifecycle(unaff_ESI[1],&local_18,&local_28);
  if (iVar2 != 0) {
    Ordinal_1064(&local_18,-local_18,-local_14);
    Ordinal_1064(&local_28,-local_28,-local_24);
    Ordinal_1072(&local_30,&local_18,&local_28);
  }
  puVar7 = &local_38;
  piVar6 = (int *)0x0;
  iVar2 = local_30;
  iVar5 = local_2c;
  iVar3 = bitmap_updateTextField(iVar4,unaff_ESI[1]);
  iVar2 = xtra_layoutTextBlock(local_34,iVar3,iVar2,iVar5,piVar6,puVar7);
  piVar1[3] = iVar2 + 1;
  iVar4 = bitmap_updateTextField(iVar4,unaff_ESI[1]);
  iVar4 = xtra_setTextPropertyByChar(local_34,iVar4,iVar2);
  if ((int)local_38 < iVar4) {
    piVar1[3] = piVar1[3] + -1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_serializeTextChunk (FUN_680eb8e0)
// Address: 680eb8e0
// Size: 218 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_serializeTextChunk(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_18;
  int local_14;
  uint local_8;
  
  iVar3 = *unaff_ESI;
  iVar5 = unaff_ESI[4];
  iVar1 = lingo_isValidObject(*(int *)(*(int *)(unaff_ESI[1] + 0x20) + 4));
  local_30 = 0;
  local_2c = *(int *)(iVar5 + 8);
  iVar2 = playback_initLifecycle(unaff_ESI[1],&local_18,&local_28);
  if (iVar2 != 0) {
    Ordinal_1064(&local_18,-local_18,-local_14);
    Ordinal_1064(&local_28,-local_28,-local_24);
    Ordinal_1072(&local_30,&local_18,&local_28);
  }
  puVar4 = (uint *)(iVar5 + 0x10);
  piVar6 = (int *)0x0;
  iVar5 = local_30;
  iVar2 = local_2c;
  puVar7 = puVar4;
  iVar3 = bitmap_updateTextField(iVar3,unaff_ESI[1]);
  iVar3 = xtra_layoutTextBlock(iVar1,iVar3,iVar5,iVar2,piVar6,puVar7);
  if (iVar3 == -1) {
    *puVar4 = 0;
    return 0;
  }
  *puVar4 = *puVar4 + 1;
  return 0;
}



// ============================================================
// Function: bitmap_deserializeTextChunk (FUN_680eb9c0)
// Address: 680eb9c0
// Size: 164 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_deserializeTextChunk(void)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  undefined4 *puVar5;
  int local_28;
  int local_24;
  int local_18;
  int local_14;
  uint local_8;
  
  iVar4 = *unaff_ESI;
  puVar1 = (undefined4 *)unaff_ESI[4];
  iVar2 = lingo_isValidObject(*(int *)(*(int *)(unaff_ESI[1] + 0x20) + 4));
  iVar3 = puVar1[3] + -1;
  puVar5 = puVar1;
  iVar4 = bitmap_updateTextField(iVar4,unaff_ESI[1]);
  xtra_getCharPositionByIndex(iVar2,iVar4,iVar3,puVar5);
  iVar4 = playback_initLifecycle(unaff_ESI[1],&local_18,&local_28);
  if (iVar4 != 0) {
    Ordinal_1064(&local_18,-local_18,-local_14);
    Ordinal_1064(&local_28,-local_28,-local_24);
    Ordinal_1072(puVar1,&local_28,&local_18);
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeTextChunkData (FUN_680eba70)
// Address: 680eba70
// Size: 193 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeTextChunkData(void)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int *piVar4;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_18;
  int local_14;
  uint local_8;
  
  iVar2 = *unaff_ESI;
  iVar3 = unaff_ESI[4];
  local_2c = lingo_isValidObject(*(int *)(*(int *)(unaff_ESI[1] + 0x20) + 4));
  piVar1 = (int *)(iVar3 + 8);
  iVar3 = *(int *)(iVar3 + 0x10) + -1;
  piVar4 = piVar1;
  iVar2 = bitmap_updateTextField(iVar2,unaff_ESI[1]);
  xtra_getLineYOffset(local_2c,iVar2,iVar3,piVar4);
  iVar2 = playback_initLifecycle(unaff_ESI[1],&local_28,&local_18);
  if (iVar2 != 0) {
    local_2c = *piVar1;
    local_30 = 0;
    Ordinal_1064(&local_28,-local_28,-local_24);
    Ordinal_1064(&local_18,-local_18,-local_14);
    Ordinal_1072(&local_30,&local_18,&local_28);
    *piVar1 = local_2c;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readTextChunkData (FUN_680ebb40)
// Address: 680ebb40
// Size: 172 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readTextChunkData(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 100) - in_EAX;
  if (iVar1 != 0) {
    param_1 = bitmap_getScaledStyleRun(unaff_EDI,param_1);
    *(int *)(unaff_EDI + 100) = in_EAX;
    if (*(char *)(unaff_EDI + 0x5b) != '\0') {
      xtra_isTextFormat(*(int *)(unaff_EDI + 0x54),in_EAX);
      if (param_1 != 0) {
        iVar2 = Ordinal_1154(param_1);
        uVar3 = Ordinal_1157(param_1);
        iVar5 = 0;
        if (0 < iVar2) {
          do {
            iVar4 = Ordinal_1156(param_1,uVar3,iVar5);
            if (iVar4 != 0) {
              Ordinal_1064(iVar4,0,iVar1);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar2);
        }
        Ordinal_1158(param_1,uVar3);
      }
      bitmap_getTextFieldState(unaff_EDI);
    }
    Ordinal_1163(&param_1);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_processTextEvent (FUN_680ebbf0)
// Address: 680ebbf0
// Size: 261 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_processTextEvent(void)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  int local_d0 [16];
  undefined4 local_90;
  undefined2 local_84;
  undefined1 local_82;
  undefined4 local_80;
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
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_2c = 0;
  Ordinal_1060(unaff_ESI + 0x68,0,0,200,0x14);
  *(undefined2 *)(unaff_ESI + 0x5c) = 1;
  *(undefined4 *)(unaff_ESI + 0x5e) = 0x1ffffff;
  *(undefined1 *)(unaff_ESI + 0x5b) = 0;
  *(undefined2 *)(unaff_ESI + 0x7e) = 0;
  *(undefined4 *)(unaff_ESI + 100) = 0;
  if (*(int *)(unaff_ESI + 8) == 7) {
    *(undefined2 *)(unaff_ESI + 0x80) = 1;
  }
  local_c = CONCAT13((*(unsigned char *)((char *)&local_c + 3)),0xffffff);
  local_2c = 200;
  local_28 = CONCAT22((*(unsigned short *)((char *)&local_28 + 2)),1);
  local_24 = 1;
  local_20 = 1;
  local_1c = 1;
  local_18 = 0;
  local_14 = 1;
  local_10 = 0;
  Ordinal_1203(local_d0,"_DEFAULT_",0x40);
  local_90 = 0xc;
  local_84 = 0;
  local_82 = 0;
  local_80 = 0;
  iVar1 = xtra_getBufferRange(unaff_EDI,0,local_d0,&local_2c);
  bitmap_getTextFieldSize(unaff_ESI,iVar1);
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_importTextData (FUN_680ebd00)
// Address: 680ebd00
// Size: 389 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_importTextData(void *this,int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_EBX;
  int *unaff_EDI;
  int local_30;
  int local_2c;
  undefined2 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined1 local_a;
  uint local_8;
  
  local_30 = 0;
  if ((unaff_EDI == (int *)0x0) || ((unaff_EDI[2] != 3 && (unaff_EDI[2] != 7)))) {
    iVar1 = -0x79;
  }
  else {
    if (param_2 == 0) {
      iVar1 = rendering_getChannelState(unaff_EDI);
      Ordinal_1130(&local_2c,0x24);
      local_2c = unaff_EDI[0x1c] - unaff_EDI[0x1a];
      if ((short)unaff_EDI[0x17] == -1) {
        local_28 = 3;
      }
      else if ((short)unaff_EDI[0x17] == 1) {
        local_28 = 2;
      }
      else {
        local_28 = 1;
      }
      local_a = (undefined1)unaff_EDI[0x18];
      local_24 = 1;
      local_20 = 1;
      local_1c = 1;
      local_14 = 1;
      local_c = *(undefined2 *)((int)unaff_EDI + 0x5e);
      local_18 = 0;
      local_10 = 0;
      if ((unaff_EDI[2] == 3) && ((*(byte *)((int)unaff_EDI + 0x7d) & 4) != 0)) {
        local_20 = 0;
        local_1c = 0;
      }
      uVar2 = scoreEngine_getChannelRange(*(int *)(unaff_EBX + 0x20),(short)unaff_EDI[1],0);
      iVar3 = scoreEngine_getFrameData(*(int *)(unaff_EBX + 0x20),(short)uVar2);
      if (iVar3 == 0) {
        iVar3 = scoreEngine_getFrameData(*(int *)(unaff_EBX + 0x20),1);
      }
      if ((iVar1 == 0) || (uVar2 = rendering_updateChannelState(iVar1 + 0x68), 0x10ff < uVar2)) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
      iVar1 = bitmap_parseFontStream(&local_30,this,&local_2c,param_1,unaff_EBX,iVar3 + 0x14,iVar1);
    }
    else {
      iVar1 = bitmap_writeFontRunData();
    }
    if (iVar1 != 0) {
      bitmap_getTextFieldSize((int)unaff_EDI,iVar1);
      bitmap_computeTextHeight(unaff_EBX,(int)unaff_EDI);
      return 0;
    }
    iVar1 = local_30;
    if (local_30 == 0) goto LAB_680ebe72;
  }
  rendering_initMemberSlot(unaff_EDI,iVar1);
LAB_680ebe72:
  return 0;
}



// ============================================================
// Function: bitmap_getTextProperty (FUN_680ebe90)
// Address: 680ebe90
// Size: 1002 bytes
// Params: undefined4 * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextProperty(undefined4 *param_1)

{
  int local_2c;
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int local_14;
  uint *local_10;
  int local_c;
  int *local_8;
  
  puVar8 = (uint *)param_1[4];
  piVar9 = (int *)*param_1;
  iVar7 = param_1[1];
  local_14 = 0;
  local_10 = puVar8;
  local_c = iVar7;
  local_8 = piVar9;
  uVar2 = lingo_isValidObject(*(int *)(*(int *)(iVar7 + 0x20) + 4));
  if (((piVar9[2] != 3) && (piVar9[2] != 7)) ||
     ((iVar3 = rendering_getMemberData(iVar7,piVar9), iVar3 == 0 && (param_1[3] != 0x31)))) {
    Ordinal_1130(puVar8,0x18);
    return 0;
  }
  switch(param_1[3]) {
  case 5:
    *puVar8 = piVar9[0x1a];
    puVar8[1] = piVar9[0x1b];
    puVar8[2] = piVar9[0x1c];
    puVar8[3] = piVar9[0x1d];
    Ordinal_1064(puVar8,-piVar9[0x1b],-piVar9[0x1a]);
    iVar7 = piVar9[0x15];
    iVar11 = -1;
    iVar10 = 0;
    iVar4 = lingo_isValidObject(*(int *)(*(int *)(param_1[1] + 0x20) + 4));
    uVar6 = xtra_drawTextLine(iVar4,iVar7,iVar10,iVar11);
    puVar8[3] = uVar6;
    break;
  default:
    if (piVar9[2] != 3) goto switchD_680ec15d_caseD_34;
    switch(param_1[3]) {
    case 0x32:
      *puVar8 = piVar9[0x19];
      break;
    case 0x33:
      *puVar8 = piVar9[0x1e];
      break;
    default:
      goto switchD_680ec15d_caseD_34;
    case 0x61:
      *puVar8 = *(byte *)((int)piVar9 + 0x7d) >> 1 & 1;
      break;
    case 99:
      *puVar8 = (uint)*(byte *)(piVar9 + 0x16);
      break;
    case 100:
      *puVar8 = (uint)*(byte *)((int)piVar9 + 0x5a);
      break;
    case 0x65:
      switch(*(undefined1 *)((int)piVar9 + 0x5b)) {
      case 0:
        *puVar8 = 0;
        break;
      case 1:
        *puVar8 = 1;
        break;
      case 2:
        *puVar8 = 2;
        break;
      case 3:
        *puVar8 = 3;
        break;
      default:
        goto switchD_680ec15d_caseD_34;
      }
      break;
    case 0x67:
      *puVar8 = (uint)*(byte *)(piVar9 + 0x1f);
      break;
    case 0x68:
      *puVar8 = *(byte *)((int)piVar9 + 0x7d) & 1;
      break;
    case 0x6d:
      uVar6 = xtra_getVisibleLineCount(uVar2,piVar9[0x15]);
      *puVar8 = uVar6;
      break;
    case 0x6f:
      *puVar8 = (uint)*(byte *)((int)piVar9 + 0x59);
      break;
    case 0x71:
      *puVar8 = ~(uint)(*(byte *)((int)piVar9 + 0x7d) >> 2) & 1;
      break;
    case 0x74:
      iVar7 = bitmap_recalcTextLayout();
      piVar9 = local_8;
      goto LAB_680ec233;
    case 0x75:
      iVar7 = bitmap_serializeTextChunk();
      piVar9 = local_8;
      goto LAB_680ec233;
    case 0x76:
      iVar7 = bitmap_deserializeTextChunk();
      piVar9 = local_8;
      goto LAB_680ec233;
    case 0x77:
      iVar7 = bitmap_writeTextChunkData();
      piVar9 = local_8;
LAB_680ec233:
      if (iVar7 == 0) goto switchD_680ec15d_caseD_34;
    }
    break;
  case 0xf:
    uVar6 = bitmap_captureTextImage();
    *puVar8 = uVar6;
    break;
  case 0x31:
    uVar6 = xtra_setBufferPos(piVar9[0x15],puVar8[2]);
    *puVar8 = uVar6;
    uVar6 = xtra_getBufferSize(piVar9[0x15]);
    puVar8[1] = uVar6;
    if (((puVar8[2] == 0) && (uVar5 = Ordinal_1116(*puVar8), uVar5 != uVar6)) && (-1 < (int)uVar6))
    {
      Ordinal_1117(puVar8,uVar6,0);
    }
    break;
  case 0x3b:
    uVar6 = bitmap_renderTextMember();
    *local_10 = uVar6;
    puVar8 = local_10;
    break;
  case 0x60:
    sVar1 = bitmap_getTextAlignment(iVar7);
    *puVar8 = (int)sVar1;
    break;
  case 0x62:
    *puVar8 = *(uint *)((int)piVar9 + 0x5e);
    break;
  case 0x66:
    if (piVar9[2] != 7) goto switchD_680ec15d_caseD_34;
    *puVar8 = (uint)*(ushort *)(piVar9 + 0x20);
    break;
  case 0x69:
    iVar7 = bitmap_resolveTextFont(local_c,(int)piVar9,puVar8[1],puVar8[2]);
    goto LAB_680ec233;
  case 0x6a:
    uVar6 = bitmap_getTextStyleData((void *)puVar8[1],iVar7);
    *puVar8 = uVar6;
    break;
  case 0x6b:
    sVar1 = bitmap_setTextStyle((void *)puVar8[1],iVar7);
    *puVar8 = (int)sVar1;
    break;
  case 0x6c:
    bitmap_getTextRunFormat(iVar7);
    break;
  case 0x6e:
    uVar2 = bitmap_getTextLineHeight(puVar8[1]);
    *puVar8 = (int)(short)uVar2;
    break;
  case 0x70:
    *puVar8 = piVar9[0x15];
    uVar6 = bitmap_updateTextField((int)piVar9,iVar7);
    puVar8[1] = uVar6;
    break;
  case 0x72:
    param_1 = (undefined4 *)0x0;
    local_10 = (uint *)0x0;
    uVar6 = Ordinal_1111(0,4);
    *puVar8 = uVar6;
    if (uVar6 != 0) {
      uVar6 = scoreEngine_getChannelRange(*(int *)(iVar7 + 0x20),(short)piVar9[1],0);
      local_14 = scoreEngine_getFrameData(*(int *)(iVar7 + 0x20),(short)uVar6);
      if (((local_14 != 0) || (local_14 = scoreEngine_getFrameData(*(int *)(iVar7 + 0x20),1), local_14 != 0)) &&
         (iVar7 = Ordinal_1404(&param_1,*puVar8,3), iVar7 != 0)) {
        bitmap_serializeFontData(&local_10,(int)param_1,piVar9[0x15],local_14 + 0x14);
        Ordinal_1407(&param_1);
        break;
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      Ordinal_1407(&param_1);
    }
    if (*puVar8 != 0) {
      Ordinal_1113(puVar8);
    }
    break;
  case 0x73:
    bitmap_getTextFieldData((int)piVar9,(int *)puVar8);
    break;
  case 0x78:
    *puVar8 = (uint)piVar9[0xb] >> 8 & 1;
  }
  local_14 = 1;
switchD_680ec15d_caseD_34:
  if (iVar3 != 0) {
    rendering_isStateValid((int)piVar9);
  }
  if (local_14 != 0) {
    return local_14;
  }
  Ordinal_1130(puVar8,0x18);
  return 0;
}



// ============================================================
// Function: bitmap_setTextProperty (FUN_680ec3d0)
// Address: 680ec3d0
// Size: 945 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_setTextProperty(undefined4 *param_1)
{
  int *this;
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  uint local_44;
  byte local_40;
  undefined3 uStack_3f;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c [10];
  
  local_30 = param_1[1];
  this = (int *)*param_1;
  puVar1 = (uint *)param_1[4];
  local_40 = 1;
  if (((this[2] != 3) && (this[2] != 7)) ||
     (iVar2 = rendering_getMemberData(local_30,this), iVar4 = local_30, iVar2 == 0)) {
    return 0;
  }
  iVar2 = param_1[3];
  switch(iVar2) {
  case 5:
  case 0x7c:
    bitmap_resizeTextField(this,local_30,(uint)(iVar2 == 5));
    break;
  default:
    if (this[2] != 3) goto switchD_680ec42e_caseD_33;
    switch(iVar2) {
    case 0x32:
      iVar4 = bitmap_readTextChunkData(local_30);
      if (iVar4 == 0) goto LAB_680ec6ee;
      break;
    default:
      goto switchD_680ec42e_caseD_33;
    case 0x61:
      if (*puVar1 == 0) {
        *(byte *)((int)this + 0x7d) = *(byte *)((int)this + 0x7d) & 0xfd;
      }
      else {
        *(byte *)((int)this + 0x7d) = *(byte *)((int)this + 0x7d) | 2;
      }
      break;
    case 99:
      *(char *)(this + 0x16) = (char)*puVar1;
      break;
    case 100:
      *(char *)((int)this + 0x5a) = (char)*puVar1;
      break;
    case 0x65:
      switch(*puVar1) {
      case 0:
        *(undefined1 *)((int)this + 0x5b) = 0;
        xtra_isTextFormat(this[0x15],0);
        break;
      case 1:
        *(undefined1 *)((int)this + 0x5b) = 1;
        break;
      case 2:
        *(undefined1 *)((int)this + 0x5b) = 2;
        break;
      case 3:
        *(undefined1 *)((int)this + 0x5b) = 3;
        break;
      default:
        goto switchD_680ec42e_caseD_33;
      }
      break;
    case 0x67:
      *(char *)(this + 0x1f) = (char)*puVar1;
      break;
    case 0x68:
      if (*puVar1 == 0) {
        *(byte *)((int)this + 0x7d) = *(byte *)((int)this + 0x7d) & 0xfe;
      }
      else {
        *(byte *)((int)this + 0x7d) = *(byte *)((int)this + 0x7d) | 1;
      }
      break;
    case 0x6f:
      *(char *)((int)this + 0x59) = (char)*puVar1;
      break;
    case 0x71:
      if (*puVar1 == 0) {
        *(byte *)((int)this + 0x7d) = *(byte *)((int)this + 0x7d) | 4;
      }
      else {
        *(byte *)((int)this + 0x7d) = *(byte *)((int)this + 0x7d) & 0xfb;
      }
      local_50 = 0x83;
      local_4c = *puVar1;
      local_48 = 0x84;
      local_44 = *puVar1;
      xtra_applyBufferStyle(this[0x15],0,0x7fffffff,(int)&local_50,2);
      local_40 = 3;
    }
    break;
  case 0x31:
    bitmap_setTextContent(local_30,this,*puVar1);
    break;
  case 0x33:
  case 0x6d:
  case 0x70:
switchD_680ec42e_caseD_33:
    rendering_isStateValid((int)this);
    return 0;
  case 0x60:
    bitmap_setTextAlignment((ushort)*puVar1,local_30);
    break;
  case 0x62:
    bitmap_setTextBackColor((undefined2 *)puVar1);
    break;
  case 0x66:
    if (this[2] != 7) goto switchD_680ec42e_caseD_33;
    if (*puVar1 - 1 < 3) {
      *(ushort *)(this + 0x20) = (ushort)*puVar1;
    }
    break;
  case 0x69:
    bitmap_applyDefaultFont(this,puVar1[2]);
    break;
  case 0x6a:
    bitmap_setTextFontById((void *)puVar1[1],local_30);
    break;
  case 0x6b:
    bitmap_applyTextStyleFlags((ushort)*puVar1,puVar1[1]);
    break;
  case 0x6c:
    bitmap_setTextForeColor((undefined2 *)puVar1);
    break;
  case 0x6e:
    bitmap_setTextFontByTag(0,local_30);
    break;
  case 0x72:
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_2c[3] = 0;
    local_2c[4] = 0;
    local_2c[5] = 0;
    local_2c[6] = 0;
    local_2c[7] = 0;
    local_2c[8] = 0;
    local_2c[0] = 0;
    local_38 = 0;
    local_3c = 0;
    local_34 = 0;
    uVar3 = scoreEngine_getChannelRange(*(int *)(local_30 + 0x20),(short)this[1],0);
    iVar4 = scoreEngine_getFrameData(*(int *)(iVar4 + 0x20),(short)uVar3);
    if (((iVar4 == 0) && (iVar4 = scoreEngine_getFrameData(*(int *)(local_30 + 0x20),1), iVar4 == 0)) ||
       (iVar2 = Ordinal_1404(&local_3c,*puVar1,1), iVar2 == 0)) {
LAB_680ec610:
      if (local_38 != 0) {
        Ordinal_1113(&local_38);
      }
    }
    else {
      xtra_readBufferValue(this[0x15],local_2c);
      iVar6 = 0;
      iVar4 = iVar4 + 0x14;
      iVar2 = local_30;
      iVar5 = Ordinal_1116(*puVar1);
      local_38 = bitmap_parseFontStream(&local_34,local_3c,local_2c,iVar5,iVar2,iVar4,iVar6);
      if (local_34 != 0) goto LAB_680ec610;
      xtra_resetBuffer(this[0x15]);
      this[0x15] = 0;
      bitmap_getTextFieldSize((int)this,local_38);
      local_38 = 0;
    }
    if (local_3c != 0) {
      Ordinal_1407(&local_3c);
    }
    break;
  case 0x78:
    uVar3 = this[0xb];
    if (*puVar1 == (uVar3 >> 8 & 1)) goto LAB_680ec6ee;
    this[0xb] = (*puVar1 << 8 ^ uVar3) & 0x100 ^ uVar3;
  }
  rendering_setMemberData(local_30,this,local_40);
LAB_680ec6ee:
  bitmap_getTextFieldState((int)this);
  rendering_isStateValid((int)this);
  return 0;
}



// ============================================================
// Function: bitmap_updateTextMember (FUN_680ec8b0)
// Address: 680ec8b0
// Size: 508 bytes
// Params: int param_1, int param_2, int param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_updateTextMember(int param_1,int param_2,int param_3,uint param_4)
{
  int local_2c;
  uint uVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar2 = lingo_isValidObject(*(int *)(*(int *)(param_1 + 0x20) + 4));
  iVar3 = rendering_getMemberData(param_1,in_EAX);
  if (iVar3 == 0) {
    return 0;
  }
  if (in_EAX[2] != 3) goto LAB_680eca9d;
  iVar3 = xtra_drawTextLine(iVar2,in_EAX[0x15],0,-1);
  iVar4 = in_EAX[0x1d] - in_EAX[0x1b];
  local_18 = iVar4;
  if (in_EAX[0x1e] < iVar3) {
    local_c = xtra_drawTextBlock(iVar2,in_EAX[0x15],0,1,iVar3 - in_EAX[0x1e]);
    local_c = local_c + 1;
  }
  else {
    local_c = 0;
  }
  iVar3 = xtra_layoutTextBlock(iVar2,in_EAX[0x15],0,0,(int *)0x0,&local_10);
  if (iVar3 == -1) {
    local_10 = 0;
  }
  local_8 = local_10;
  local_14 = xtra_countVisibleLines(iVar2,in_EAX[0x15],local_10,1,iVar4);
  if (param_2 == 2) {
    if (param_3 == 1) {
LAB_680ec9df:
      uVar1 = 0;
    }
    else {
      uVar1 = local_c - 1;
    }
  }
  else {
    uVar1 = param_4;
    if (param_2 != 3) {
      if (param_2 == 4) {
        iVar3 = xtra_setTextPropertyByChar(iVar2,in_EAX[0x15],param_4);
        uVar1 = local_8;
        if ((iVar3 != -1) && ((iVar3 < (int)local_8 || ((int)(local_14 + -1 + local_8) <= iVar3))))
        {
          iVar4 = xtra_drawTextLine(iVar2,in_EAX[0x15],iVar3,1);
          iVar4 = xtra_countVisibleLines(iVar2,in_EAX[0x15],iVar3,0,local_18 - iVar4);
          uVar1 = (iVar3 - iVar4) + 1;
          if (param_4 == 0) goto LAB_680ec9df;
        }
      }
      else if (param_2 == 5) {
        xtra_layoutTextBlock(iVar2,in_EAX[0x15],0,param_4 - in_EAX[0x19],(int *)0x0,&local_8);
        uVar1 = local_8;
      }
      else {
        if (param_2 == 1) {
          if (param_3 == 1) {
            iVar3 = xtra_drawTextBlock(iVar2,in_EAX[0x15],local_8,0,iVar4);
            param_4 = -(iVar3 * param_4);
            if ((int)param_4 < -1) {
              param_4 = param_4 + 1;
            }
          }
          else {
            iVar3 = xtra_drawTextBlock(iVar2,in_EAX[0x15],local_8,1,iVar4);
            param_4 = iVar3 * param_4;
            if (1 < (int)param_4) {
              param_4 = param_4 - 1;
            }
          }
        }
        else if (param_3 == 1) {
          param_4 = -param_4;
        }
        uVar1 = local_8 + param_4;
      }
    }
  }
  local_8 = uVar1;
  if (((int)local_8 < local_c) || ((int)local_8 <= (int)local_10)) {
    if ((int)local_8 < 0) {
      local_8 = 0;
    }
  }
  else {
    local_8 = local_c - 1;
  }
  xtra_getLineYOffset(iVar2,in_EAX[0x15],local_8,&local_1c);
  iVar2 = bitmap_readTextChunkData(param_1);
  if (iVar2 == 1) {
    rendering_setMemberData(param_1,in_EAX,0x10);
  }
LAB_680eca9d:
  rendering_isStateValid((int)in_EAX);
  return 0;
}



// ============================================================
// Function: bitmap_applyTextImport (FUN_680ecab0)
// Address: 680ecab0
// Size: 455 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_applyTextImport(int param_1,int param_2,undefined4 param_3)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_ec;
  int local_e8;
  int local_d4;
  undefined4 local_d0 [41];
  int local_2c [9];
  uint local_8;
  
  uVar1 = scoreEngine_getChannelRange(*(int *)(param_1 + 0x20),*(short *)(param_2 + 4),0);
  local_e8 = scoreEngine_getFrameData(*(int *)(param_1 + 0x20),(short)uVar1);
  if (local_e8 == 0) {
    local_e8 = scoreEngine_getFrameData(*(int *)(param_1 + 0x20),1);
  }
  iVar2 = xtra_setBufferPos(*(int *)(param_2 + 0x54),0);
  iVar3 = Ordinal_1114(iVar2);
  psVar4 = (short *)Ordinal_1114(param_3);
  xtra_readBufferValue(*(int *)(param_2 + 0x54),local_2c);
  iVar5 = xtra_getBufferRange(0,0,(int *)0x0,local_2c);
  iVar6 = Ordinal_1116(iVar2);
  iVar6 = iVar6 + -1;
  iVar7 = (int)*psVar4;
  local_d4 = 0;
  local_ec = 0;
  if (0 < iVar7) {
    piVar8 = (int *)(psVar4 + 1);
    do {
      iVar9 = iVar6;
      if (local_ec != iVar7 + -1) {
        iVar9 = piVar8[5];
      }
      iVar9 = iVar9 - *piVar8;
      if (iVar6 < iVar9 + local_d4) {
        iVar9 = iVar6 - local_d4;
      }
      if (0 < iVar9) {
        playback_getFontMapData(local_e8 + 0x14,(int)piVar8,(int)local_d0,0,0);
        iVar7 = xtra_replaceBufferRange(iVar5,local_d4 + iVar3,iVar9,local_d0);
        if (iVar7 == 0) goto LAB_680ecc56;
        local_d4 = local_d4 + iVar9;
      }
      iVar7 = (int)*psVar4;
      local_ec = local_ec + 1;
      piVar8 = piVar8 + 5;
    } while (local_ec < iVar7);
  }
  if (iVar3 != 0) {
    Ordinal_1115(iVar2);
  }
  xtra_resetBuffer(*(int *)(param_2 + 0x54));
  bitmap_getTextFieldSize(param_2,iVar5);
LAB_680ecc56:
  Ordinal_1115(param_3);
  return 0;
}



// ============================================================
// Function: bitmap_notifyTextChange (FUN_680ecc80)
// Address: 680ecc80
// Size: 383 bytes
// Params: int param_1, int * param_2, int param_3, uint param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_notifyTextChange(int param_1,int *param_2,int param_3,uint param_4,int param_5)
{
  int iVar1;
  uint uVar2;
  undefined4 local_ac [41];
  uint local_8;
  
  iVar1 = rendering_getMemberData(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (((param_2[2] == 3) || (param_2[2] == 7)) && (param_2[0x15] != 0)) {
    if (param_3 == 0) {
      if (param_5 - param_4 != 0) {
        xtra_deleteBufferRange(param_2[0x15],param_4,param_5 - param_4);
      }
    }
    else {
      uVar2 = Ordinal_1201(param_3);
      if (param_5 - param_4 != 0) {
        xtra_deleteBufferRange(param_2[0x15],param_4,param_5 - param_4);
      }
      iVar1 = xtra_getBufferSize(param_2[0x15]);
      if (iVar1 < 1) {
        iVar1 = xtra_appendToBuffer(param_2[0x15],local_ac,0);
        param_4 = 0;
        if (iVar1 != 0) {
          xtra_replaceBufferRange(param_2[0x15],param_3,uVar2,local_ac);
          param_4 = uVar2;
        }
      }
      else {
        xtra_insertBufferData(param_2[0x15],param_3,uVar2,param_4);
        param_4 = param_4 + uVar2;
      }
    }
    uVar2 = xtra_getBufferSize(param_2[0x15]);
    if ((int)uVar2 < (int)param_4) {
      param_4 = uVar2;
    }
    if (*(char *)((int)param_2 + 0x5b) != '\x01') {
      param_4 = 0;
    }
    bitmap_updateTextMember(param_1,4,0,param_4);
    bitmap_getMovieStageRef(param_1,(int)param_2);
    rendering_updateMemberMedia(param_1,param_2);
    bitmap_getTextFieldState((int)param_2);
    rendering_isStateValid((int)param_2);
    return 0;
  }
  rendering_isStateValid((int)param_2);
  return 0;
}



// ============================================================
// Function: bitmap_dispatchTextMsg (FUN_680ece00)
// Address: 680ece00
// Size: 114 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_dispatchTextMsg(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 uVar2;
  int local_c;
  void *local_8;
  
  uVar2 = 0;
  local_8 = (void *)0x0;
  if ((in_EAX == (int *)0x0) || ((in_EAX[2] != 3 && (in_EAX[2] != 7)))) goto LAB_680ece61;
  if (in_EAX[0x15] == 0) {
    iVar1 = rendering_updateMemberState(in_EAX,FOURCC_STXT,&local_c,&local_8,(int *)0x0);
    if (iVar1 != 1) goto LAB_680ece61;
    iVar1 = bitmap_importTextData(local_8,local_c,0);
    if (iVar1 == 0) goto LAB_680ece61;
    bitmap_getTextFieldState((int)in_EAX);
    in_EAX[0xb] = in_EAX[0xb] | 0x200;
  }
  uVar2 = 1;
LAB_680ece61:
  Ordinal_1407(&local_8);
  return uVar2;
}



