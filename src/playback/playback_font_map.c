// Module: playback
// Topic: Font mapping, text encoding, character tables, font data serialization
// Address range: 0x680d9bd0 - 0x680dc1c0
// Functions (30):
//   playback_getControlData, playback_parseFontMapQuotedName, playback_parseFontMapValue, playback_skipFontMapSeparator, playback_parseFontMapNumber
//   playback_parseFontMapRange, playback_parseFontMapEntry, playback_parseFontMapMapping, playback_parseFontMapBlock, playback_loadFontMapResource
//   playback_compareFontNames, playback_writeFontMapBlock, playback_serializeFontMap, playback_allocateFontMapEntries, playback_releaseFontMapEntries
//   playback_getFontMapState, playback_getFontMapRef, playback_scanMemberFontRefs, playback_isFontMapEmpty, playback_loadFontMapFromScore
//   playback_destroyFontMapData, playback_resolveFontMapping, playback_initFontMapEx, playback_saveFontMapToScore, playback_getFontMapRawData
//   playback_mapFont, playback_convertFontName, playback_isMultiByteCodePage, playback_initFontMap, playback_remapFontCharacters
//   playback_buildFontMappingEntry, playback_deserializeFontMap, playback_getFontMapData, playback_lookupFontRefByName, playback_lookupFontNameById
//   playback_reloadFontMapFromStream

// ============================================================
// Function: playback_getControlData (FUN_680d9bd0)
// Address: 680d9bd0
// Size: 141 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getControlData(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int local_8;
  
  pcVar3 = (char *)*param_1;
  if (param_2 == (undefined4 *)0x0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    puVar2 = (undefined1 *)*param_2;
  }
  iVar1 = xtra_parseTextFormat(pcVar3);
  while( true ) {
    if ((iVar1 != 0) || (iVar1 = xtra_setTextFormat((int)pcVar3,1,1), iVar1 != 0)) {
      return 0;
    }
    iVar1 = Ordinal_1252(pcVar3,&local_8);
    if (iVar1 == 0x3a) break;
    if (puVar2 != (undefined1 *)0x0) {
      puVar2 = (undefined1 *)Ordinal_1247(puVar2,iVar1);
    }
    pcVar3 = pcVar3 + local_8;
    iVar1 = xtra_parseTextFormat(pcVar3);
  }
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *param_1 = pcVar3 + local_8;
  if (puVar2 == (undefined1 *)0x0) {
    return 1;
  }
  *param_2 = puVar2;
  return 1;
}



// ============================================================
// Function: playback_parseFontMapQuotedName (playback_parseFontMapQuotedName)
// Address: 680d9c60
// Size: 254 bytes
// Params: int * param_1, undefined4 * param_2, int * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_parseFontMapQuotedName(int *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int local_c;
  int local_8;
  
  iVar5 = *param_1;
  puVar3 = (undefined1 *)*param_2;
  iVar4 = 0;
  local_c = 0;
  iVar1 = Ordinal_1252(iVar5,&local_8);
  if ((iVar1 == 0x22) || (iVar2 = iVar1, iVar1 == 0x27)) {
    iVar5 = iVar5 + local_8;
    iVar4 = 1;
    iVar2 = Ordinal_1252(iVar5,&local_8);
    local_c = iVar1;
  }
  if (iVar2 != 0x28) {
    iVar5 = Ordinal_1201(puVar3);
    *param_2 = puVar3 + iVar5 + 1;
    return 1;
  }
  pcVar6 = (char *)(iVar5 + local_8);
  iVar5 = xtra_parseTextFormat(pcVar6);
  do {
    if ((iVar5 != 0) || (iVar5 = xtra_setTextFormat((int)pcVar6,1,1), iVar5 != 0)) {
      return 0;
    }
    iVar5 = Ordinal_1252(pcVar6,&local_8);
    if (iVar5 == 0x29) {
      *puVar3 = 0;
      *param_1 = (int)(pcVar6 + local_8);
      *param_2 = puVar3 + 1;
      *param_3 = iVar4;
      *param_4 = local_c;
      return 1;
    }
    if (iVar4 == 0) {
      if ((iVar5 == 0x22) || (iVar5 == 0x27)) {
        iVar4 = 1;
        local_c = iVar5;
      }
      else {
LAB_680d9d11:
        puVar3 = (undefined1 *)Ordinal_1247(puVar3,iVar5);
      }
    }
    else {
      if (iVar5 != local_c) goto LAB_680d9d11;
      iVar4 = 0;
      local_c = 0;
    }
    pcVar6 = pcVar6 + local_8;
    iVar5 = xtra_parseTextFormat(pcVar6);
  } while( true );
}



// ============================================================
// Function: playback_parseFontMapValue (playback_parseFontMapValue)
// Address: 680d9d60
// Size: 259 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_parseFontMapValue(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint extraout_EDX;
  char *pcVar3;
  int local_18;
  char *local_14;
  int local_10;
  int local_c;
  undefined1 *local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    local_8 = (undefined1 *)0x0;
  }
  else {
    local_8 = (undefined1 *)*param_2;
  }
  pcVar3 = (char *)*param_1;
  local_10 = 0;
  local_c = 0;
  iVar1 = xtra_parseTextFormat(pcVar3);
  while (iVar1 == 0) {
    iVar1 = Ordinal_1252(pcVar3,&local_18);
    if (param_3 == 0) {
      if (local_c == 0) {
        iVar2 = xtra_setTextFormat((int)pcVar3,1,1);
        if (iVar2 == 0) {
          local_14 = pcVar3;
          Ordinal_1253(iVar1);
          if (((extraout_EDX & 0x20000000) != 0) || (iVar2 = playback_getControlRef2(), iVar2 != 0))
          goto LAB_680d9e3e;
          if ((iVar1 != 0x22) && (iVar1 != 0x27)) goto LAB_680d9e03;
          param_3 = 1;
          param_4 = iVar1;
        }
        else {
          local_c = 1;
        }
      }
    }
    else if (iVar1 == param_4) {
      param_3 = 0;
    }
    else {
LAB_680d9e03:
      if (local_8 != (undefined1 *)0x0) {
        local_8 = (undefined1 *)Ordinal_1247(local_8,iVar1);
      }
      local_10 = 1;
    }
    pcVar3 = pcVar3 + local_18;
    iVar1 = xtra_parseTextFormat(pcVar3);
  }
  if (param_3 != 0) {
    return 0;
  }
LAB_680d9e3e:
  if ((local_10 != 0) && (*param_1 = pcVar3, local_8 != (undefined1 *)0x0)) {
    *local_8 = 0;
    *param_2 = local_8 + 1;
  }
  return local_10;
}



// ============================================================
// Function: playback_skipFontMapSeparator (playback_skipFontMapSeparator)
// Address: 680d9e70
// Size: 231 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_skipFontMapSeparator(undefined4 *param_1)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined1 local_18 [16];
  uint local_8;
  
  pcVar1 = xtra_trimString((char *)*param_1);
  if (DAT_68196484 == '\0') {
    iVar2 = Ordinal_1517(DAT_681956e0,0x1519,&DAT_68196484,0x10);
  }
  else {
    iVar2 = Ordinal_1201(&DAT_68196484);
  }
  iVar2 = iVar2 + 1;
  Ordinal_1203(local_18,pcVar1,iVar2);
  iVar3 = playback_getControlState(local_18);
  if (iVar3 != 0) {
    if (DAT_68196484 == '\0') {
      iVar2 = Ordinal_1517(DAT_681956e0,0x151a,&DAT_68196484,0x10);
    }
    else {
      iVar2 = Ordinal_1201(&DAT_68196494);
    }
    iVar2 = iVar2 + 1;
    Ordinal_1203(local_18,pcVar1,iVar2);
    iVar3 = playback_getControlState(local_18);
    if (iVar3 != 0) goto LAB_680d9f42;
  }
  pcVar1 = xtra_trimString(pcVar1 + iVar2 + -1);
  *param_1 = pcVar1;
LAB_680d9f42:
  return 0;
}



// ============================================================
// Function: playback_parseFontMapNumber (playback_parseFontMapNumber)
// Address: 680d9f60
// Size: 122 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_parseFontMapNumber(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  int local_8;
  
  iVar4 = *unaff_EBX;
  iVar5 = -1;
  uVar1 = Ordinal_1252(iVar4,&local_8);
  uVar6 = Ordinal_1253(uVar1);
  iVar2 = (int)uVar6;
  if ((uVar6 & 0x4000000000000000) == 0) {
    iVar5 = -1;
  }
  else {
    do {
      if (iVar5 < 1) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar5 * 10;
        if (iVar3 < iVar5) {
          return -1;
        }
      }
      iVar4 = iVar4 + local_8;
      iVar5 = iVar3 + -0x30 + iVar2;
      uVar1 = Ordinal_1252(iVar4,&local_8);
      uVar6 = Ordinal_1253(uVar1);
      iVar2 = (int)uVar6;
    } while ((uVar6 & 0x4000000000000000) != 0);
    if (0 < iVar5) {
      *unaff_EBX = iVar4;
      return iVar5;
    }
  }
  return iVar5;
}



// ============================================================
// Function: playback_parseFontMapRange (playback_parseFontMapRange)
// Address: 680d9fe0
// Size: 127 bytes
// Params: undefined4 * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_parseFontMapRange(undefined4 *param_1,int *param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  pcVar1 = xtra_trimString((char *)*param_1);
  iVar2 = playback_parseFontMapNumber();
  if (iVar2 < 0) {
    return 0;
  }
  iVar3 = playback_getControlRef2();
  if (iVar3 != 0) {
    iVar3 = playback_parseFontMapNumber();
    if (-1 < iVar3) {
      pcVar1 = xtra_trimString(pcVar1);
      if (param_2 != (int *)0x0) {
        *param_2 = iVar2;
      }
      if (param_3 != (int *)0x0) {
        *param_3 = iVar3;
      }
      *param_1 = pcVar1;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_parseFontMapEntry (playback_parseFontMapEntry)
// Address: 680da060
// Size: 439 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_parseFontMapEntry(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int unaff_EBX;
  int *unaff_ESI;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  char *local_8;
  
  iVar3 = *unaff_ESI;
  local_c = 0;
  local_18 = 0;
  local_10 = 0;
  local_14 = iVar3;
  local_8 = xtra_trimString((char *)*param_1);
  local_1c = *unaff_ESI;
  iVar1 = playback_getControlData(&local_8,unaff_ESI);
  if (iVar1 != 0) {
    local_8 = xtra_trimString(local_8);
    *unaff_ESI = local_1c;
    iVar1 = playback_parseFontMapQuotedName((int *)&local_8,unaff_ESI,&local_10,&local_c);
    if (iVar1 != 0) {
      *(int *)(unaff_EBX + 4) = *(int *)(unaff_EBX + 4) + (*unaff_ESI - iVar3);
      iVar1 = playback_parseFontMapValue(&local_8,unaff_ESI,local_10,local_c);
      if ((iVar1 != 0) && (iVar1 = playback_getControlRef2(), iVar3 = local_14, iVar1 != 0)) {
        iVar1 = *unaff_ESI;
        iVar2 = playback_getControlData(&local_8,unaff_ESI);
        iVar3 = local_14;
        if (iVar2 != 0) {
          Ordinal_1016();
          iVar3 = playback_getControlState(iVar1);
          if (iVar3 == 0) {
            *(undefined4 *)(unaff_EBX + 0x18) = 1;
          }
          *unaff_ESI = iVar1;
          iVar2 = playback_parseFontMapQuotedName((int *)&local_8,unaff_ESI,&local_10,&local_c);
          iVar3 = local_14;
          if (iVar2 != 0) {
            Ordinal_1016();
            iVar3 = playback_getControlState(iVar1);
            if (iVar3 == 0) {
              *(undefined4 *)(unaff_EBX + 0x18) = 1;
            }
            *unaff_ESI = iVar1;
            *(int *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) + (iVar1 - local_14);
            iVar1 = playback_parseFontMapValue(&local_8,unaff_ESI,local_10,local_c);
            iVar3 = local_14;
            if (iVar1 != 0) {
              local_8 = xtra_trimString(local_8);
              uVar4 = playback_skipFontMapSeparator(&local_8);
              pcVar5 = local_8;
              *(undefined4 *)(unaff_EBX + 0x14) = uVar4;
              *(int *)(unaff_EBX + 0x10) = *(int *)(unaff_EBX + 0x10) + (*unaff_ESI - local_14);
              iVar3 = xtra_parseTextFormat(local_8);
              while ((iVar3 == 0 && (iVar3 = xtra_setTextFormat((int)pcVar5,1,1), iVar3 == 0))) {
                iVar1 = playback_parseFontMapRange(&local_8,&local_1c,&local_10);
                pcVar5 = local_8;
                iVar3 = local_14;
                if (iVar1 == 0) goto LAB_680da20b;
                *(undefined2 *)*unaff_ESI = (undefined2)local_1c;
                *unaff_ESI = *unaff_ESI + 2;
                *(undefined2 *)*unaff_ESI = (undefined2)local_10;
                *unaff_ESI = *unaff_ESI + 2;
                *(int *)(unaff_EBX + 0xc) = *(int *)(unaff_EBX + 0xc) + 1;
                iVar3 = xtra_parseTextFormat(local_8);
              }
              pcVar5 = xtra_trimStringRight(pcVar5);
              *param_1 = pcVar5;
              local_18 = 1;
              iVar3 = local_14;
              if (*(int *)(unaff_EBX + 0x18) != 0) {
                return 1;
              }
            }
          }
        }
      }
    }
  }
LAB_680da20b:
  *unaff_ESI = iVar3;
  return local_18;
}



// ============================================================
// Function: playback_parseFontMapMapping (playback_parseFontMapMapping)
// Address: 680da220
// Size: 297 bytes
// Params: undefined4 * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_parseFontMapMapping(undefined4 *param_1,int param_2)

{
  int *in_EAX;
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int local_14;
  int local_10;
  int local_c;
  char *local_8;
  
  local_c = 0;
  local_10 = 0;
  local_8 = xtra_trimString((char *)*param_1);
  iVar4 = *in_EAX;
  iVar1 = playback_getControlData(&local_8,in_EAX);
  pcVar2 = local_8;
  if (iVar1 != 0) {
    iVar1 = playback_getControlRef2();
    pcVar2 = local_8;
    if (iVar1 != 0) {
      local_14 = *in_EAX;
      iVar1 = playback_getControlData(&local_8,in_EAX);
      pcVar2 = local_8;
      if (iVar1 != 0) {
        pcVar2 = xtra_trimString(local_8);
        local_8 = pcVar2;
        piVar3 = (int *)playback_setControlProperty(param_2,iVar4,local_14,&local_c);
        if (piVar3 == (int *)0x0) {
          piVar3 = playback_createControlProperty(iVar4,local_14,&local_c);
        }
        iVar4 = xtra_parseTextFormat(pcVar2);
        if (iVar4 == 0) {
          do {
            iVar4 = playback_parseFontMapRange(&local_8,&param_2,&local_14);
            pcVar2 = local_8;
            if (iVar4 == 0) goto LAB_680da31a;
            if (piVar3 != (int *)0x0) {
              if (((param_2 < *piVar3) || (piVar3[1] < param_2)) || (0x7f < local_14 - 0x80U))
              goto LAB_680da31a;
              *(char *)((param_2 - *piVar3) + 0x48 + (int)piVar3) = (char)local_14;
            }
            iVar4 = xtra_setTextFormat((int)local_8,1,1);
          } while ((iVar4 == 0) && (iVar4 = xtra_parseTextFormat(pcVar2), iVar4 == 0));
          local_10 = 1;
        }
LAB_680da31a:
        if (piVar3 != (int *)0x0) {
          Ordinal_1115(local_c);
        }
      }
    }
  }
  pcVar2 = xtra_trimStringRight(pcVar2);
  if (local_10 != 0) {
    *param_1 = pcVar2;
  }
  return local_10;
}



// ============================================================
// Function: playback_parseFontMapBlock (playback_parseFontMapBlock)
// Address: 680da350
// Size: 645 bytes
// Params: int * param_1, undefined4 param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_parseFontMapBlock(int *param_1,undefined4 param_2,int *param_3,int param_4)
{
  char cVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  int local_34;
  char *local_30;
  undefined1 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_34 = 0;
  local_28 = 0;
  bVar2 = false;
  local_34 = Ordinal_1150(0x20,0x10,0x1c);
  if (local_34 == 0) {
    lingo_formatDebugMsg(param_3,-0x7a);
  }
  else {
    local_28 = Ordinal_1111(param_4 + 1,0);
    if (local_28 == 0) {
      lingo_formatDebugMsg(param_3,-0x7a);
    }
    else {
      puVar4 = (undefined1 *)Ordinal_1114(local_28);
      *puVar4 = 0;
      iVar5 = Ordinal_1409(param_2,puVar4,param_4);
      if (iVar5 == 0) {
        Ordinal_1113(&local_28);
        lingo_formatDebugMsg(param_3,-0x74);
      }
      else {
        puVar4[param_4] = 0;
        local_2c = (undefined1 *)0x0;
        Ordinal_1115(local_28);
        iVar5 = Ordinal_1708(&local_28,1,&local_2c,0,0);
        if (iVar5 == 0) {
          Ordinal_1117(&local_28,0,0);
        }
        iVar5 = Ordinal_1116(local_28);
        iVar6 = Ordinal_1111(iVar5 + 2,0);
        puVar4 = (undefined1 *)Ordinal_1114(iVar6);
        *puVar4 = 0;
        uVar7 = Ordinal_1114(local_28);
        Ordinal_1128(puVar4 + 1,uVar7,iVar5);
        puVar4[iVar5 + 1] = 0;
        Ordinal_1115(local_28);
        Ordinal_1113(&local_28);
        local_28 = iVar6;
        Ordinal_1113(param_1 + 3);
        iVar5 = Ordinal_1120(local_28,0);
        param_1[3] = iVar5;
        pcVar8 = puVar4 + 1;
        cVar1 = puVar4[1];
        puVar3 = puVar4;
        while (local_2c = puVar3, cVar1 != '\0') {
          local_30 = xtra_scanTextDelimiters(pcVar8,1,1);
          local_24 = (int)puVar3 - (int)puVar4;
          local_18 = 0;
          local_10 = 1;
          local_c = 0;
          local_20 = local_24;
          local_1c = local_24;
          local_14 = local_24;
          iVar5 = playback_parseFontMapEntry(&local_30);
          if (iVar5 == 0) {
            iVar5 = playback_parseFontMapMapping(&local_30,(int)param_1);
            pcVar8 = local_30;
            if (iVar5 == 0) {
              if (!bVar2) {
                bVar2 = true;
              }
              pcVar8 = xtra_trimStringRight(local_30);
            }
          }
          else {
            pcVar8 = local_30;
            if ((local_c != 0) &&
               (iVar5 = Ordinal_1152(local_34,&local_24), pcVar8 = local_30, iVar5 == 0)) {
              lingo_formatDebugMsg(param_3,-0x7a);
              goto LAB_680da55b;
            }
          }
          puVar3 = local_2c;
          cVar1 = *pcVar8;
        }
        iVar5 = (int)puVar3 - (int)puVar4;
        puVar4 = (undefined1 *)Ordinal_1115(local_28);
        iVar5 = Ordinal_1117(&local_28,iVar5,1);
        if (*param_1 != 0) {
          Ordinal_1163(param_1);
        }
        Ordinal_1113(param_1 + 1);
        *param_1 = local_34;
        param_1[1] = local_28;
        if (iVar5 != 0) goto LAB_680da57a;
      }
LAB_680da55b:
      if (puVar4 != (undefined1 *)0x0) {
        Ordinal_1115(local_28);
      }
    }
  }
  Ordinal_1113(&local_28);
  Ordinal_1163(&local_34);
LAB_680da57a:
  return 0;
}



// ============================================================
// Function: playback_loadFontMapResource (playback_loadFontMapResource)
// Address: 680da5e0
// Size: 253 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_loadFontMapResource(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  uVar5 = 0;
  local_c = Ordinal_1510(DAT_681956e0,0,0x1f8);
  if (local_c != 0) {
    iVar1 = Ordinal_1515(DAT_681956e0,0,0x1f8);
    local_8 = Ordinal_1111(iVar1,0);
    if (local_8 == 0) {
      Ordinal_1514(&local_c);
      lingo_formatDebugMsg(param_1,-0x7a);
    }
    else {
      uVar2 = Ordinal_1512(local_c);
      uVar3 = Ordinal_1114(local_8);
      Ordinal_1128(uVar3,uVar2,iVar1);
      Ordinal_1115(local_8);
      Ordinal_1513(local_c);
      Ordinal_1514(&local_c);
      iVar4 = Ordinal_1404(&local_10,local_8,1);
      if (iVar4 == 0) {
        lingo_formatDebugMsg(param_1,-0x7a);
      }
      else {
        iVar1 = playback_parseFontMapBlock((int *)(param_1[1] + 8),local_10,param_1,iVar1);
        if (iVar1 != 0) {
          uVar5 = 1;
        }
      }
    }
  }
  Ordinal_1407(&local_10);
  Ordinal_1113(&local_8);
  return uVar5;
}



// ============================================================
// Function: playback_compareFontNames (playback_compareFontNames)
// Address: 680da6e0
// Size: 104 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_compareFontNames(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  
  Ordinal_1201(*unaff_ESI);
  Ordinal_1201(unaff_ESI[1]);
  Ordinal_1423();
  Ordinal_1422();
  Ordinal_1420();
  Ordinal_1422();
  Ordinal_1420();
  iVar1 = Ordinal_1042();
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: playback_writeFontMapBlock (playback_writeFontMapBlock)
// Address: 680da750
// Size: 817 bytes
// Params: void * this, int * param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_writeFontMapBlock(void *this,int *param_1,int param_2,uint param_3)
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined **ppuVar7;
  uint local_bc;
  int local_b0;
  undefined1 *local_78;
  undefined *local_74;
  undefined2 local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined **local_5c;
  undefined4 local_58;
  int local_54;
  void *local_50;
  int local_4c;
  undefined1 local_48 [64];
  uint local_8;
  
  local_64 = 0;
  local_58 = 0;
  local_4c = -0x7a;
  local_68 = 0;
  local_50 = this;
  Ordinal_1130(&local_78,0xc);
  local_78 = local_48;
  local_6c = Ordinal_1433(this);
  iVar2 = Ordinal_1425(this,0);
  if (iVar2 == 0) goto LAB_680daa36;
  if (param_2 == 0) {
    local_b0 = 0;
  }
  else {
    iVar2 = Ordinal_1415();
    local_bc = Ordinal_1415();
    local_5c = (undefined **)Ordinal_1433();
    Ordinal_1432();
    local_b0 = Ordinal_1414();
    iVar3 = Ordinal_1414();
    Ordinal_1432();
    if ((((iVar2 == 0) || (local_bc == 0)) || (local_b0 < 1)) ||
       (((iVar3 < local_b0 || (iVar2 != iVar3 * 8 + 0x1c)) || (local_bc + 8 + iVar2 != param_2)))) {
LAB_680daa2f:
      local_4c = -0x78;
      goto LAB_680daa36;
    }
    local_54 = Ordinal_1433();
    Ordinal_1432();
    local_64 = Ordinal_1439();
    if ((local_64 == 0) || (iVar2 = Ordinal_1404(&local_58,local_64,1), iVar2 == 0))
    goto LAB_680daa36;
    Ordinal_1432();
  }
  local_60 = local_b0;
  if (param_3 < 0x700) {
    local_60 = local_b0 + 4;
  }
  local_54 = 0;
  if (0 < local_60) {
    ppuVar7 = &PTR_s_Chicago_6818e7b0 + local_b0 * -3;
    do {
      local_5c = ppuVar7;
      if (local_54 < local_b0) {
        uVar4 = Ordinal_1414();
        Ordinal_1412();
        local_70 = Ordinal_1412();
        if (local_bc <= uVar4) goto LAB_680daa2f;
        local_74 = (undefined *)playback_lookupControlByChannel();
        if (local_74 == (undefined *)0x0) {
          local_74 = (undefined *)Ordinal_1016();
        }
        Ordinal_1432(local_58,uVar4,0);
        uVar5 = Ordinal_1414(local_58);
        if (((((int)uVar5 < 1) || (0x3f < uVar5)) || (local_bc < uVar5 + 4 + uVar4)) ||
           (iVar2 = Ordinal_1409(local_58,local_48,uVar5), iVar2 == 0)) goto LAB_680daa2f;
        local_48[uVar5] = 0;
        ppuVar7 = local_5c;
      }
      else {
        local_70 = *(undefined2 *)(ppuVar7 + -1);
        Ordinal_1203(local_48,*ppuVar7,0x40);
        local_74 = ppuVar7[1];
      }
      if ((param_3 < 0x1100) && (iVar2 = Ordinal_1264(local_48,0xffffffff,0), iVar2 == 0)) {
        iVar2 = Ordinal_1274(local_48,0,local_48,0x3f);
        if (-1 < iVar2) {
          local_48[iVar2] = 0;
          goto LAB_680da9c5;
        }
      }
      else {
LAB_680da9c5:
        iVar2 = playback_compareFontNames();
        ppuVar7 = local_5c;
        if (iVar2 == 0) goto LAB_680daa36;
      }
      local_54 = local_54 + 1;
      ppuVar7 = ppuVar7 + 3;
      local_5c = ppuVar7;
    } while (local_54 < local_60);
  }
  uVar6 = Ordinal_1433(local_50);
  pvVar1 = local_50;
  Ordinal_1432(local_50,local_6c,0);
  iVar2 = Ordinal_1425(pvVar1,local_60);
  if (iVar2 != 0) {
    Ordinal_1432(pvVar1,uVar6,0);
    local_68 = 1;
  }
LAB_680daa36:
  Ordinal_1407(&local_58);
  Ordinal_1113(&local_64);
  if (local_68 == 0) {
    Ordinal_1432(local_50,local_6c,0);
    lingo_formatDebugMsg(param_1,local_4c);
  }
  return 0;
}



// ============================================================
// Function: playback_serializeFontMap (playback_serializeFontMap)
// Address: 680daa90
// Size: 947 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_serializeFontMap(int *param_1,undefined4 param_2,int *param_3,int param_4)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_1bc;
  uint local_1b8;
  int *local_1b4;
  int *local_1b0;
  undefined4 local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  int local_198;
  undefined4 local_194;
  undefined4 local_190;
  int local_18c;
  uint local_188;
  undefined1 local_184 [8];
  int local_17c;
  int local_178;
  undefined1 local_174 [20];
  undefined1 local_160 [8];
  uint local_158;
  uint local_154;
  undefined1 local_150 [264];
  undefined1 local_48 [64];
  uint local_8;
  
  local_1b0 = param_3;
  local_19c = -0x7a;
  local_190 = 0;
  local_194 = 0;
  local_1bc = 0;
  local_1a0 = 0;
  local_1a4 = 0;
  local_198 = 0;
  local_1b4 = param_1;
  local_1ac = param_2;
  iVar1 = Ordinal_1414(param_2);
  if (iVar1 == 0) {
LAB_680dadda:
    local_1a4 = 1;
  }
  else if (iVar1 < 0) {
LAB_680dab02:
    local_19c = -0x78;
  }
  else {
    iVar2 = Ordinal_1403(&local_190,0);
    if ((iVar2 != 0) && (iVar2 = Ordinal_1403(&local_194,0), iVar2 != 0)) {
      Ordinal_1130(&local_18c,0x43);
      local_18c = iVar1 * 8 + 0x1c;
      local_17c = iVar1;
      local_178 = iVar1;
      local_1a8 = iVar1;
      do {
        local_1a8 = local_1a8 + -1;
        if (local_1a8 < 0) {
          local_188 = local_1a0 + 0x12;
          local_158 = local_188;
          local_154 = local_188;
          if (param_4 != 0) {
            Ordinal_1426(param_4,local_18c);
            Ordinal_1426(param_4,local_188);
            Ordinal_1420(param_4,local_184,8);
            Ordinal_1425(param_4,local_17c);
            Ordinal_1425(param_4,local_178);
            Ordinal_1420(param_4,local_174,0xc);
          }
          local_198 = 0x24;
          if (param_4 != 0) {
            uVar4 = Ordinal_1433(param_4,local_190,0,local_17c * 8);
            iVar1 = Ordinal_1431(param_4,uVar4);
            if ((iVar1 == 0) || (iVar1 = Ordinal_1042(), iVar1 != 0)) break;
          }
          iVar1 = local_17c * 8;
          if (param_4 != 0) {
            Ordinal_1420(param_4,local_160,8);
            Ordinal_1425(param_4,local_158);
            Ordinal_1425(param_4,local_154);
            Ordinal_1420(param_4,local_150,2);
            if (0x12 < local_154) {
              local_198 = iVar1 + 0x36;
              uVar4 = Ordinal_1433(param_4,local_194,0,local_154 - 0x12);
              iVar2 = Ordinal_1431(param_4,uVar4);
              if ((iVar2 == 0) || (iVar2 = Ordinal_1042(), iVar2 != 0)) break;
            }
          }
          local_198 = iVar1 + 0x24 + local_154;
          iVar1 = Ordinal_1042();
          if (iVar1 == 0) goto LAB_680dadda;
          break;
        }
        local_1b8 = Ordinal_1412(param_2);
        local_1b8 = local_1b8 & 0xffff;
        iVar1 = playback_setControlState(param_2);
        if (iVar1 == 0) goto LAB_680dab02;
        iVar1 = playback_setControlState(local_1ac);
        if (iVar1 == 0) goto LAB_680dab02;
        uVar3 = Ordinal_1201(local_48);
        iVar1 = 0;
        if ((uVar3 & 3) != 0) {
          iVar1 = 4 - (uVar3 & 3);
        }
        Ordinal_1425(local_190,local_1a0 + 0x12);
        iVar2 = playback_findFirstControlState();
        Ordinal_1423(local_190,iVar2);
        Ordinal_1423(local_190,local_1b8);
        Ordinal_1425(local_194,uVar3);
        Ordinal_1420(local_194,local_48,uVar3);
        if (iVar1 != 0) {
          Ordinal_1420(local_194,&local_1bc,iVar1);
        }
        local_1a0 = local_1a0 + 4 + iVar1 + uVar3;
        iVar1 = Ordinal_1042();
        param_2 = local_1ac;
      } while (iVar1 == 0);
    }
  }
  Ordinal_1407(&local_194);
  Ordinal_1407(&local_190);
  if (local_1b4 != (int *)0x0) {
    *local_1b4 = local_198;
  }
  if (local_1a4 == 0) {
    lingo_formatDebugMsg(local_1b0,local_19c);
  }
  return 0;
}



// ============================================================
// Function: playback_allocateFontMapEntries (playback_allocateFontMapEntries)
// Address: 680dae50
// Size: 113 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_allocateFontMapEntries(void)

{
  int *in_EAX;
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  uVar1 = Ordinal_1111(unaff_EDI * 0x1c + 8,1);
  *(undefined4 *)(*in_EAX + 4) = uVar1;
  if (*(int *)(*in_EAX + 4) != 0) {
    piVar2 = (int *)Ordinal_1114(*(int *)(*in_EAX + 4));
    in_EAX[1] = (int)piVar2;
    *piVar2 = unaff_EDI;
    in_EAX[2] = in_EAX[1] + 8;
    uVar1 = Ordinal_1111(4,1);
    *(undefined4 *)(in_EAX[1] + 4) = uVar1;
    if ((*(int *)(in_EAX[1] + 4) != 0) &&
       (iVar3 = Ordinal_1404(in_EAX + 3,*(int *)(in_EAX[1] + 4),3), iVar3 != 0)) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_releaseFontMapEntries (playback_releaseFontMapEntries)
// Address: 680daed0
// Size: 60 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_releaseFontMapEntries(int param_1)
{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[1] != 0) {
    iVar1 = Ordinal_1115(*(undefined4 *)(*unaff_ESI + 4));
    unaff_ESI[1] = iVar1;
  }
  if (unaff_ESI[3] != 0) {
    Ordinal_1407(unaff_ESI + 3);
  }
  if (param_1 == 0) {
    playback_destroyAllControlRefs();
  }
  return 0;
}



// ============================================================
// Function: playback_getFontMapState (FUN_680daf10)
// Address: 680daf10
// Size: 32 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getFontMapState(undefined4 *param_1)
{
  *param_1 = 0;
  playback_destroyAllControlRefs();
  param_1[1] = 0;
  return 0;
}



// ============================================================
// Function: playback_getFontMapRef (FUN_680daf30)
// Address: 680daf30
// Size: 352 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getFontMapRef(int param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *this;
  undefined4 unaff_ESI;
  int local_8;
  
  local_8 = 0;
  if (param_1 == 0) {
    return unaff_ESI;
  }
  if (param_2 == 0) {
    return unaff_ESI;
  }
  if (param_3 == 0) {
    return unaff_ESI;
  }
  Ordinal_1130(param_3,0x14);
  this = (undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined2 *)(param_3 + 0xc) = 0xc;
  }
  else {
    local_8 = Ordinal_1114(*(int *)(param_1 + 4));
    puVar1 = (undefined2 *)playback_getControlRef((undefined1 *)(param_2 + 0x54));
    if (puVar1 == (undefined2 *)0x0) {
      local_8 = Ordinal_1115(*this);
      iVar2 = playback_addControlRef(this,(undefined1 *)(param_2 + 0x54));
      if (iVar2 == 0) goto LAB_680db074;
      local_8 = Ordinal_1114(*this);
      puVar1 = (undefined2 *)playback_getControlRef((undefined1 *)(param_2 + 0x54));
    }
    *(undefined2 *)(param_3 + 8) = *puVar1;
    *(undefined2 *)(param_3 + 0xc) = *(undefined2 *)(param_2 + 0x40);
    *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_2 + 0x44);
    *(undefined2 *)(param_3 + 6) = *(undefined2 *)(param_2 + 0x48);
    *(ushort *)(param_3 + 0xe) =
         CONCAT11(*(undefined1 *)(param_2 + 0x4c),*(undefined1 *)(param_2 + 0x4c));
    *(ushort *)(param_3 + 0x10) =
         CONCAT11(*(undefined1 *)(param_2 + 0x4d),*(undefined1 *)(param_2 + 0x4d));
    *(ushort *)(param_3 + 0x12) =
         CONCAT11(*(undefined1 *)(param_2 + 0x4e),*(undefined1 *)(param_2 + 0x4e));
    if ((*(byte *)(param_2 + 0x50) & 1) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 1;
    }
    if ((*(byte *)(param_2 + 0x50) & 2) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 2;
    }
    if ((*(byte *)(param_2 + 0x50) & 4) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 4;
    }
    if ((*(byte *)(param_2 + 0x50) & 8) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 8;
    }
    if ((*(byte *)(param_2 + 0x50) & 0x10) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 0x10;
    }
    if ((*(byte *)(param_2 + 0x50) & 0x80) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 0x20;
    }
    if ((*(byte *)(param_2 + 0x50) & 0x40) != 0) {
      *(byte *)(param_3 + 10) = *(byte *)(param_3 + 10) | 0x40;
    }
  }
LAB_680db074:
  if (local_8 != 0) {
    Ordinal_1115(*this);
  }
  return unaff_ESI;
}



// ============================================================
// Function: playback_scanMemberFontRefs (playback_scanMemberFontRefs)
// Address: 680db090
// Size: 358 bytes
// Params: short param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_scanMemberFontRefs(short param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *this;
  int *local_bc;
  undefined4 local_b8 [21];
  undefined1 local_64 [80];
  int local_14;
  int local_10;
  uint local_8;
  
  local_bc = (int *)0x0;
  iVar4 = 0;
  local_bc = rendering_getDispatchByChannel(param_3,param_1);
  if (local_bc != (int *)0x0) {
    this = (undefined4 *)(param_2 + 4);
    if (*(int *)(param_2 + 4) != 0) {
      iVar4 = Ordinal_1114(*(int *)(param_2 + 4));
    }
    iVar1 = rendering_getMemberCache((int)local_bc);
    while (iVar1 != 0) {
      if (((*(byte *)(iVar1 + 0x38) & 0xf7) != 0) &&
         ((*(int *)(iVar1 + 8) == 3 || (*(int *)(iVar1 + 8) == 7)))) {
        iVar2 = xtra_getBufferSize(*(int *)(iVar1 + 0x54));
        iVar3 = 0;
        if (0 < iVar2) {
          do {
            xtra_readBufferRange(*(int *)(iVar1 + 0x54),(int)&local_14,iVar3);
            xtra_appendToBuffer(*(int *)(iVar1 + 0x54),local_b8,local_14);
            iVar3 = playback_getControlRef(local_64);
            if (iVar3 == 0) {
              if (iVar4 != 0) {
                iVar4 = Ordinal_1115(*this);
              }
              iVar3 = playback_addControlRef(this,local_64);
              if (iVar3 == 0) goto LAB_680db1bf;
              iVar4 = Ordinal_1114(*this);
            }
            iVar3 = local_10 + local_14;
          } while (iVar3 < iVar2);
        }
      }
      iVar1 = rendering_getMemberCache((int)local_bc);
    }
LAB_680db1bf:
    if (iVar4 != 0) {
      Ordinal_1115(*this);
    }
  }
  rendering_getDispatchState((int *)&local_bc);
  return 0;
}



// ============================================================
// Function: playback_isFontMapEmpty (playback_isFontMapEmpty)
// Address: 680db200
// Size: 17 bytes
// Params: int * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_isFontMapEmpty(int *param_1)

{
  return *param_1 == 0;
}



// ============================================================
// Function: playback_loadFontMapFromScore (playback_loadFontMapFromScore)
// Address: 680db220
// Size: 150 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_loadFontMapFromScore(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  int local_8;
  
  piVar1 = param_1;
  uVar4 = 0;
  local_8 = 0;
  bVar2 = playback_isFontMapEmpty((int *)(param_1[1] + 8));
  if (CONCAT31(extraout_var,bVar2) != 0) {
    iVar3 = playback_loadFontMapResource(piVar1);
    if (iVar3 == 0) goto LAB_680db2a3;
  }
  iVar3 = playback_openScore(param_3,FOURCC_FXmp,0x400,&param_1,&local_8);
  if (iVar3 == 0xc) {
    Ordinal_1407(&local_8);
    return 2;
  }
  if (((local_8 != 0) && (iVar3 == 0)) && (param_1 != (int *)0x0)) {
    iVar3 = playback_parseFontMapBlock(param_2,local_8,piVar1,(int)param_1);
    if (iVar3 == 0) goto LAB_680db2a3;
  }
  uVar4 = 1;
LAB_680db2a3:
  Ordinal_1407(&local_8);
  return uVar4;
}



// ============================================================
// Function: playback_destroyFontMapData (playback_destroyFontMapData)
// Address: 680db2c0
// Size: 132 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_destroyFontMapData(int *param_1)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      Ordinal_1163(param_1);
    }
    Ordinal_1113(param_1 + 1);
    piVar1 = param_1 + 2;
    if (param_1[2] != 0) {
      uVar2 = Ordinal_1157(param_1[2]);
      iVar3 = Ordinal_1154(*piVar1);
      iVar5 = 0;
      if (0 < iVar3) {
        do {
          uVar4 = Ordinal_1156(*piVar1,uVar2,iVar5);
          Ordinal_1113(uVar4);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar3);
      }
      Ordinal_1158(*piVar1,uVar2);
      Ordinal_1163(piVar1);
    }
    Ordinal_1113(param_1 + 3);
  }
  return 0;
}



// ============================================================
// Function: playback_resolveFontMapping (playback_resolveFontMapping)
// Address: 680db350
// Size: 728 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined4 param_5, int * param_6, int param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
playback_resolveFontMapping(int param_1,int *param_2,int param_3,int param_4,undefined4 param_5,int *param_6,
            int param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 0;
  local_24 = 0;
  local_8 = 0;
  local_14 = 0;
  local_34 = 0;
  local_20 = 1;
  local_10 = 0;
  if (((param_2 == (int *)0x0) || (param_3 == 0)) || (param_4 == 0)) goto switchD_680db53a_default;
  bVar1 = playback_isFontMapEmpty(param_2);
  if ((CONCAT31(extraout_var,bVar1) != 0) &&
     (bVar1 = playback_isFontMapEmpty((int *)(*(int *)(param_1 + 4) + 8)), CONCAT31(extraout_var_00,bVar1) != 0
     )) goto LAB_680db606;
  iVar6 = *param_2;
  local_1c = param_2[1];
  local_30 = 0;
  local_c = iVar6;
  do {
    if (local_30 == 1) {
      iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);
      local_1c = *(int *)(*(int *)(param_1 + 4) + 0xc);
      local_c = iVar6;
    }
    if (iVar6 != 0) {
      iVar2 = Ordinal_1114(local_1c);
      uVar3 = Ordinal_1157(iVar6);
      iVar4 = Ordinal_1154(iVar6);
      local_28 = 0;
      if (0 < iVar4) {
        do {
          if (2 < local_10) break;
          iVar5 = Ordinal_1156(iVar6,uVar3,local_28);
          iVar6 = playback_getControlState(param_3);
          iVar8 = local_10;
          if (iVar6 == 0) {
            if (((local_10 < 2) && (iVar6 = playback_getControlState("_DEFAULT_"), iVar6 == 0)) &&
               (iVar6 = Ordinal_1700(*(int *)(iVar5 + 8) + iVar2), iVar6 != 0)) {
              iVar8 = 2;
            }
            else {
              iVar6 = playback_getControlState(param_4);
              iVar8 = local_10;
              if (iVar6 != 0) goto LAB_680db4f6;
              iVar6 = Ordinal_1700(*(int *)(iVar5 + 8) + iVar2);
              if (iVar6 == 0) {
                iVar8 = local_10;
                if (0 < local_10) goto LAB_680db4f6;
                iVar8 = 1;
              }
              else {
                iVar8 = 3;
              }
            }
            if ((local_18 == 0) &&
               (local_18 = Ordinal_1126(param_5,0), iVar6 = local_c, local_18 == 0)) break;
            Ordinal_1203(local_18,*(int *)(iVar5 + 8) + iVar2,param_5);
            local_20 = *(int *)(iVar5 + 0x14);
            local_14 = *(int *)(iVar5 + 0xc);
            if (local_14 != 0) {
              Ordinal_1113(&local_8);
              local_8 = playback_createControlPairs((short *)(*(int *)(iVar5 + 0x10) + iVar2));
            }
          }
LAB_680db4f6:
          local_10 = iVar8;
          local_28 = local_28 + 1;
          iVar6 = local_c;
        } while (local_28 < iVar4);
      }
      Ordinal_1158(iVar6,uVar3);
      Ordinal_1115(local_1c);
    }
    local_30 = local_30 + 1;
  } while (local_30 < 2);
  switch(local_10) {
  case 0:
    break;
  case 1:
    local_20 = 1;
    local_14 = 0;
    Ordinal_1113(&local_8);
  case 3:
switchD_680db53a_caseD_3:
    Ordinal_1203(param_4,local_18,param_5);
    break;
  case 2:
    iVar6 = Ordinal_1700(param_4);
    if (iVar6 == 0) goto switchD_680db53a_caseD_3;
    break;
  default:
    goto switchD_680db53a_default;
  }
  if (local_20 != 0) {
    piVar7 = &local_24;
    uVar3 = Ordinal_1016();
    iVar6 = playback_setControlProperty((int)param_2,param_3,uVar3,piVar7);
    if (iVar6 != 0) {
      Ordinal_1115(local_24);
    }
  }
  iVar6 = local_14;
  if ((local_14 == 0) || (local_8 != 0)) {
    if ((param_6 != (int *)0x0) && (local_14 != 0)) {
      piVar7 = (int *)Ordinal_1114(local_8);
      iVar6 = iVar6 + -1;
      if (-1 < iVar6) {
        do {
          if (*param_6 == *piVar7) {
            *param_6 = piVar7[1];
            break;
          }
          iVar6 = iVar6 + -1;
        } while (-1 < iVar6);
      }
      Ordinal_1115(local_8);
    }
    if (param_7 != 0) {
      *(int *)(param_7 + 8) = local_14;
      *(int *)(param_7 + 0xc) = local_8;
      local_8 = 0;
      if (local_24 != 0) {
        uVar3 = Ordinal_1112(local_24);
        *(undefined4 *)(param_7 + 0x10) = uVar3;
      }
    }
LAB_680db606:
    local_34 = 1;
  }
switchD_680db53a_default:
  Ordinal_1127(&local_18);
  Ordinal_1113(&local_8);
  return local_34;
}



// ============================================================
// Function: playback_initFontMapEx (FUN_680db640)
// Address: 680db640
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initFontMapEx(void)
{
  Ordinal_1113();
  return 0;
}



// ============================================================
// Function: playback_saveFontMapToScore (playback_saveFontMapToScore)
// Address: 680db650
// Size: 432 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_saveFontMapToScore(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_24;
  int local_18;
  int local_14;
  int local_c;
  undefined4 local_8;
  
  piVar7 = (int *)0x0;
  local_14 = 0;
  local_8 = 0;
  local_18 = 0;
  local_24 = Ordinal_1116(param_1);
  iVar1 = Ordinal_1404(&local_8,param_1,3);
  iVar5 = 0;
  if (iVar1 != 0) {
    if (local_24 == 0) {
      local_c = 0;
      Ordinal_1425(local_8,0);
      local_24 = Ordinal_1433(local_8);
    }
    else {
      local_c = Ordinal_1414(local_8);
    }
    Ordinal_1432(local_8,0,2);
    if (*(int *)(param_2 + 4) != 0) {
      piVar7 = (int *)Ordinal_1114(*(int *)(param_2 + 4));
      local_14 = Ordinal_1114(piVar7[1]);
      piVar6 = piVar7 + 2;
      iVar5 = *piVar7;
      while (iVar5 = iVar5 + -1, -1 < iVar5) {
        if (piVar6[6] != 0) {
          iVar1 = piVar6[1];
          uVar2 = Ordinal_1016();
          uVar3 = Ordinal_1201(iVar1 + local_14);
          uVar4 = Ordinal_1201(uVar2);
          Ordinal_1423(local_8,(short)*piVar6);
          Ordinal_1422(local_8,uVar4);
          Ordinal_1420(local_8,uVar2,uVar4);
          Ordinal_1422(local_8,uVar3);
          Ordinal_1420(local_8,iVar1 + local_14,uVar3);
          iVar1 = Ordinal_1042();
          if (iVar1 != 0) goto LAB_680db7b1;
          local_c = local_c + 1;
        }
        piVar6 = piVar6 + 7;
      }
    }
    Ordinal_1432(local_8,0,0);
    iVar5 = Ordinal_1425(local_8,local_c);
    if (((iVar5 != 0) && (local_18 = 1, piVar7 != (int *)0x0)) && (iVar5 = *piVar7 + -1, -1 < iVar5)
       ) {
      piVar6 = piVar7 + 8;
      do {
        *piVar6 = 0;
        piVar6 = piVar6 + 7;
        iVar5 = iVar5 + -1;
      } while (-1 < iVar5);
    }
LAB_680db7b1:
    if (local_14 != 0) {
      Ordinal_1115(piVar7[1]);
    }
    iVar5 = local_18;
    if (piVar7 != (int *)0x0) {
      Ordinal_1115(*(undefined4 *)(param_2 + 4));
    }
  }
  Ordinal_1407(&local_8);
  if ((iVar5 == 0) || (local_c == 0)) {
    Ordinal_1117(&param_1,local_24,0);
  }
  return iVar5;
}



// ============================================================
// Function: playback_getFontMapRawData (playback_getFontMapRawData)
// Address: 680db800
// Size: 153 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getFontMapRawData(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  if (param_1 == (int *)0x0) {
LAB_680db873:
    lingo_formatDebugMsg(param_1,-0x7b);
  }
  else {
    piVar1 = *(int **)(param_1[1] + 8);
    if (param_1[0x146] != 0) {
      iVar2 = Ordinal_1116(param_1[0x146]);
      iVar3 = Ordinal_1114(param_1[0x146]);
      if (param_2 != 0) {
        iVar3 = Ordinal_1420(param_2,iVar3 + 1,iVar2 + -2);
        Ordinal_1115(param_1[0x146]);
        param_1 = piVar1;
        if (iVar3 == 0) goto LAB_680db873;
      }
      local_c = iVar2 + -2;
    }
    local_8 = 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_c;
  }
  return local_8;
}



// ============================================================
// Function: playback_mapFont (FUN_680db8a0)
// Address: 680db8a0
// Size: 231 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_mapFont(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  bool bVar5;
  int local_8;
  
  local_8 = 0;
  bVar5 = false;
  if ((param_1 != 0) || (iVar2 = 0, param_2 != 0)) {
    if (param_3 != 0) {
      bVar5 = param_1 != 0;
      if (bVar5) {
        param_2 = Ordinal_1114(param_1);
      }
      param_2 = param_2 + param_4;
      iVar2 = Ordinal_1274(param_2,param_3,0,0);
      iVar2 = iVar2 + 1;
      if ((0 < iVar2) && (local_8 = Ordinal_1111(iVar2 + param_4,1), local_8 != 0)) {
        puVar3 = (undefined1 *)Ordinal_1114(local_8);
        puVar4 = puVar3 + param_4;
        iVar2 = Ordinal_1274(param_2,param_3,puVar4,iVar2);
        if ((0 < iVar2) && (param_4 != 0)) {
          iVar2 = Ordinal_1201(puVar4);
          puVar3[iVar2 + 1] = 0;
          iVar2 = Ordinal_1201(puVar4);
          if (iVar2 < 0xff) {
            uVar1 = Ordinal_1201(puVar4);
            *puVar3 = uVar1;
          }
          else {
            *puVar3 = 0xff;
          }
        }
        if (puVar3 != (undefined1 *)0x0) {
          Ordinal_1115(local_8);
        }
      }
    }
    iVar2 = local_8;
    if ((param_2 != 0) && (bVar5)) {
      Ordinal_1115(param_1);
    }
  }
  return iVar2;
}



// ============================================================
// Function: playback_convertFontName (playback_convertFontName)
// Address: 680db990
// Size: 215 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_convertFontName(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  iVar6 = 0;
  local_8 = 0;
  iVar1 = Ordinal_1114(param_1);
  local_8 = Ordinal_1111(0x3ff,1);
  if (local_8 != 0) {
    uVar2 = Ordinal_1114(local_8);
    Ordinal_1310(iVar1,uVar2,0x3ff);
    iVar3 = Ordinal_1201(uVar2);
    Ordinal_1115(local_8);
    iVar3 = playback_mapFont(local_8,0,iVar3,0);
    if (iVar3 != 0) {
      iVar4 = Ordinal_1114(iVar3);
      iVar6 = Ordinal_1111(0x418,1);
      if (iVar6 != 0) {
        iVar5 = Ordinal_1114(iVar6);
        Ordinal_1309(iVar5,0x400,iVar4,2);
        if (iVar5 != 0) {
          Ordinal_1115(iVar6);
        }
      }
      if (iVar4 != 0) {
        Ordinal_1115(iVar3);
      }
    }
  }
  Ordinal_1113(&local_8);
  if (iVar1 != 0) {
    Ordinal_1115(param_1);
  }
  return iVar6;
}



// ============================================================
// Function: playback_isMultiByteCodePage (playback_isMultiByteCodePage)
// Address: 680dba70
// Size: 41 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_isMultiByteCodePage(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = Ordinal_1282();
  switch(uVar1) {
  case 0x3a4:
  case 0x3a8:
  case 0x3b5:
  case 0x3b6:
    break;
  default:
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_initFontMap (FUN_680dbac0)
// Address: 680dbac0
// Size: 81 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_initFontMap(void *this,int param_1)
{
  ushort uVar1;
  undefined1 *in_EAX;
  int iVar2;
  undefined2 extraout_var;
  int *unaff_EBX;
  
  iVar2 = playback_isMultiByteCodePage();
  if (iVar2 != 0) {
    for (; 0 < param_1; param_1 = param_1 - (int)this) {
      uVar1 = playback_readDoubleByteChar();
      if ((*unaff_EBX <= CONCAT22(extraout_var,uVar1)) &&
         (CONCAT22(extraout_var,uVar1) <= unaff_EBX[1])) {
        playback_writeDoubleByteChar(in_EAX);
      }
      in_EAX = in_EAX + (int)this;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_remapFontCharacters (playback_remapFontCharacters)
// Address: 680dbb20
// Size: 54 bytes
// Params: ushort * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_remapFontCharacters(ushort *param_1)
{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int *unaff_EDI;
  
  iVar1 = playback_isMultiByteCodePage();
  if (iVar1 != 0) {
    for (; 0 < in_EAX; in_EAX = in_EAX + -1) {
      uVar2 = (uint)*param_1;
      if ((*unaff_EDI <= (int)uVar2) && ((int)uVar2 <= unaff_EDI[1])) {
        *param_1 = (ushort)*(byte *)((uVar2 - *unaff_EDI) + 0x48 + (int)unaff_EDI);
      }
      param_1 = param_1 + 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_buildFontMappingEntry (playback_buildFontMappingEntry)
// Address: 680dbb60
// Size: 127 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_buildFontMappingEntry(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  
  puVar1 = (undefined2 *)unaff_EDI[2];
  *puVar1 = (short)unaff_ESI[2];
  Ordinal_1016();
  iVar2 = playback_getControlState(unaff_ESI[1]);
  if (iVar2 == 0) {
    *(undefined4 *)(puVar1 + 10) = 1;
  }
  iVar2 = playback_resolveFontMapping(param_1,*(int **)*unaff_EDI,unaff_ESI[1],*unaff_ESI,0x40,(int *)0x0,
                       (int)puVar1);
  if (iVar2 != 0) {
    uVar3 = Ordinal_1433(unaff_EDI[3]);
    *(undefined4 *)(puVar1 + 2) = uVar3;
    iVar2 = Ordinal_1201(*unaff_ESI);
    iVar2 = Ordinal_1420(unaff_EDI[3],*unaff_ESI,iVar2 + 1);
    if (iVar2 != 0) {
      unaff_EDI[2] = unaff_EDI[2] + 0x1c;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_deserializeFontMap (playback_deserializeFontMap)
// Address: 680dbbe0
// Size: 453 bytes
// Params: int * param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_deserializeFontMap(int *param_1,int *param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *local_17c [4];
  undefined1 *local_16c;
  undefined1 *local_168;
  undefined2 local_164;
  int *local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  undefined4 local_14c;
  undefined1 local_148 [256];
  undefined1 local_48 [64];
  uint local_8;
  
  local_160 = param_1;
  local_14c = 0;
  local_150 = -0x7a;
  local_158 = 0;
  Ordinal_1130(local_17c,0x10);
  local_17c[0] = param_2;
  if (((param_2 != (int *)0x0) && (param_3 != 0)) && (param_4 != 0)) {
    *param_2 = param_4;
    iVar1 = Ordinal_1404(&local_14c,param_3,1);
    if (iVar1 != 0) {
      iVar1 = Ordinal_1116(param_3);
      if (iVar1 == 0) {
        local_154 = 0;
      }
      else {
        local_154 = Ordinal_1414(local_14c);
      }
      iVar1 = local_154;
      iVar2 = playback_allocateFontMapEntries();
      if (iVar2 != 0) {
        local_168 = local_148;
        local_16c = local_48;
        local_15c = 0;
        if (0 < iVar1) {
          do {
            local_164 = Ordinal_1412(local_14c);
            iVar1 = playback_setControlState(local_14c);
            if (iVar1 == 0) {
LAB_680dbd99:
              local_150 = -0x78;
              goto LAB_680dbd4c;
            }
            iVar1 = playback_setControlState(local_14c);
            if (iVar1 == 0) goto LAB_680dbd99;
            iVar1 = playback_buildFontMappingEntry((int)local_160);
            if (iVar1 == 0) goto LAB_680dbd4c;
            local_15c = local_15c + 1;
          } while (local_15c < local_154);
        }
        local_158 = 1;
      }
    }
  }
LAB_680dbd4c:
  iVar1 = local_158;
  playback_releaseFontMapEntries(local_158);
  Ordinal_1407(&local_14c);
  if (iVar1 == 0) {
    lingo_formatDebugMsg(local_160,local_150);
  }
  return 0;
}



// ============================================================
// Function: playback_getFontMapData (FUN_680dbdb0)
// Address: 680dbdb0
// Size: 453 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getFontMapData(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  void *this;
  int *piVar4;
  int local_24 [7];
  int *local_8;
  
  local_8 = (int *)0x0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (param_4 == 0) {
    param_5 = 0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    piVar2 = (int *)Ordinal_1114(*(int *)(param_1 + 4));
    piVar4 = piVar2 + 2;
    iVar3 = *piVar2;
    local_8 = piVar2;
    if (iVar3 != 0) {
      sVar1 = (short)*piVar4;
      while ((sVar1 != *(short *)(param_2 + 8) && (iVar3 = iVar3 + -1, 0 < iVar3))) {
        piVar4 = piVar4 + 7;
        sVar1 = (short)*piVar4;
      }
      if (iVar3 != 0) {
        iVar3 = Ordinal_1114(piVar2[1]);
        Ordinal_1203(param_3,piVar4[1] + iVar3,0x40);
        Ordinal_1115(piVar2[1]);
        goto LAB_680dbe5a;
      }
    }
  }
  Ordinal_1130(local_24,0x1c);
  piVar4 = local_24;
  Ordinal_1203(param_3,"_DEFAULT_",0x40);
LAB_680dbe5a:
  sVar1 = *(short *)(param_2 + 0xc);
  *(int *)(param_3 + 0x40) = (int)sVar1;
  if (sVar1 == 0) {
    *(undefined4 *)(param_3 + 0x40) = 0xc;
  }
  iVar3 = piVar4[2];
  if (iVar3 != 0) {
    piVar2 = (int *)Ordinal_1114(piVar4[3]);
    iVar3 = iVar3 + -1;
    if (-1 < iVar3) {
      do {
        if (*(int *)(param_3 + 0x40) == *piVar2) {
          *(int *)(param_3 + 0x40) = piVar2[1];
          break;
        }
        piVar2 = piVar2 + 2;
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
    }
    Ordinal_1115(piVar4[3]);
  }
  if ((piVar4[4] != 0) && ((*(ushort *)(param_2 + 8) & 0x4000) == 0)) {
    Ordinal_1114(piVar4[4]);
    playback_initFontMap(this,param_5);
    Ordinal_1115(piVar4[4]);
  }
  *(int *)(param_3 + 0x44) = (int)*(short *)(param_2 + 4);
  *(int *)(param_3 + 0x48) = (int)*(short *)(param_2 + 6);
  *(undefined1 *)(param_3 + 0x4c) = *(undefined1 *)(param_2 + 0xf);
  *(undefined1 *)(param_3 + 0x4d) = *(undefined1 *)(param_2 + 0x11);
  *(undefined1 *)(param_3 + 0x4e) = *(undefined1 *)(param_2 + 0x13);
  *(undefined4 *)(param_3 + 0x50) = 0;
  if ((*(byte *)(param_2 + 10) & 1) != 0) {
    *(undefined4 *)(param_3 + 0x50) = 1;
  }
  if ((*(byte *)(param_2 + 10) & 2) != 0) {
    *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 2;
  }
  if ((*(byte *)(param_2 + 10) & 4) != 0) {
    *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 4;
  }
  if ((*(byte *)(param_2 + 10) & 8) != 0) {
    *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 8;
  }
  if ((*(byte *)(param_2 + 10) & 0x10) != 0) {
    *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 0x10;
  }
  if ((*(byte *)(param_2 + 10) & 0x20) != 0) {
    *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 0x80;
  }
  if ((*(byte *)(param_2 + 10) & 0x40) != 0) {
    *(uint *)(param_3 + 0x50) = *(uint *)(param_3 + 0x50) | 0x40;
  }
  if (local_8 != (int *)0x0) {
    Ordinal_1115(*(undefined4 *)(param_1 + 4));
  }
  return 1;
}



// ============================================================
// Function: playback_lookupFontRefByName (playback_lookupFontRefByName)
// Address: 680dbf80
// Size: 232 bytes
// Params: int param_1, undefined1 * param_2, undefined4 param_3, int * param_4, int param_5, int param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
playback_lookupFontRefByName(int param_1,undefined1 *param_2,undefined4 param_3,int *param_4,int param_5,int param_6
            )

{
  short *psVar1;
  int iVar2;
  void *this;
  undefined4 *this_00;
  undefined4 unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    return unaff_ESI;
  }
  if (param_2 == (undefined1 *)0x0) {
    return unaff_ESI;
  }
  this_00 = (undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == 0) {
    *param_4 = 1;
  }
  else {
    iVar3 = Ordinal_1114(*(int *)(param_1 + 4));
    psVar1 = (short *)playback_getControlRef(param_2);
    if (psVar1 == (short *)0x0) {
      iVar3 = Ordinal_1115(*this_00);
      iVar2 = playback_addControlRef(this_00,param_2);
      if (iVar2 == 0) goto LAB_680dc04e;
      iVar3 = Ordinal_1114(*this_00);
      psVar1 = (short *)playback_getControlRef(param_2);
    }
    *param_4 = (int)*psVar1;
    if (((*(int *)(psVar1 + 8) != 0) && (param_5 != 0)) && (param_6 != 0)) {
      this = (void *)Ordinal_1114(*(int *)(psVar1 + 8));
      playback_initFontMap(this,param_6);
      Ordinal_1115(*(undefined4 *)(psVar1 + 8));
    }
  }
LAB_680dc04e:
  if (iVar3 != 0) {
    Ordinal_1115(*this_00);
  }
  return unaff_ESI;
}



// ============================================================
// Function: playback_lookupFontNameById (playback_lookupFontNameById)
// Address: 680dc070
// Size: 325 bytes
// Params: int param_1, uint param_2, int * param_3, int param_4, undefined4 param_5, int param_6, void * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
playback_lookupFontNameById(int param_1,uint param_2,int *param_3,int param_4,undefined4 param_5,int param_6,
            void *param_7)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_24 [7];
  int *local_8;
  
  local_8 = (int *)0x0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_4 == 0) {
    return 0;
  }
  if (param_6 == 0) {
    param_7 = (void *)0x0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    piVar2 = (int *)Ordinal_1114(*(int *)(param_1 + 4));
    piVar4 = piVar2 + 2;
    iVar3 = *piVar2;
    local_8 = piVar2;
    if (iVar3 != 0) {
      sVar1 = (short)*piVar4;
      while (((int)sVar1 != param_2 && (iVar3 = iVar3 + -1, 0 < iVar3))) {
        sVar1 = (short)piVar4[7];
        piVar4 = piVar4 + 7;
      }
      if (iVar3 != 0) {
        iVar3 = Ordinal_1114(piVar2[1]);
        Ordinal_1203(param_4,piVar4[1] + iVar3,param_5);
        Ordinal_1115(piVar2[1]);
        goto LAB_680dc119;
      }
    }
  }
  Ordinal_1130(local_24,0x1c);
  piVar4 = local_24;
  Ordinal_1203(param_4,"_DEFAULT_",param_5);
LAB_680dc119:
  if (param_3 != (int *)0x0) {
    if (*param_3 == 0) {
      *param_3 = 0xc;
    }
    iVar3 = piVar4[2];
    if (iVar3 != 0) {
      piVar2 = (int *)Ordinal_1114(piVar4[3]);
      iVar3 = iVar3 + -1;
      if (-1 < iVar3) {
        do {
          if (*param_3 == *piVar2) {
            *param_3 = piVar2[1];
            break;
          }
          piVar2 = piVar2 + 2;
          iVar3 = iVar3 + -1;
        } while (-1 < iVar3);
      }
      Ordinal_1115(piVar4[3]);
    }
  }
  if ((((piVar4[4] != 0) && ((param_2 & 0x4000) == 0)) && (param_6 != 0)) &&
     (param_7 != (void *)0x0)) {
    Ordinal_1114(piVar4[4]);
    playback_initFontMap(param_7,(int)param_7);
    Ordinal_1115(piVar4[4]);
  }
  if (local_8 != (int *)0x0) {
    Ordinal_1115(*(undefined4 *)(param_1 + 4));
  }
  return 1;
}



// ============================================================
// Function: playback_reloadFontMapFromStream (playback_reloadFontMapFromStream)
// Address: 680dc1c0
// Size: 112 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_reloadFontMapFromStream(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  playback_destroyFontMapData(param_2);
  iVar1 = Ordinal_1433(param_3);
  if (param_4 == 0) {
    iVar2 = Ordinal_1435(param_3);
    param_4 = iVar2 - iVar1;
  }
  iVar2 = Ordinal_1439(param_3,param_4,0);
  param_2[3] = iVar2;
  if (iVar2 != 0) {
    Ordinal_1432(param_3,iVar1,0);
    iVar1 = playback_parseFontMapBlock(param_2,param_3,param_1,param_4);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



