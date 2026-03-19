int xtra_getCryptoBlockSize(); /* FIXUP(C2065): missing forward declaration */
// Module: xtra_runtime
// Topic: Text engine, layout, glyph rendering, UUID generation, line measurement
// Address range: 0x681168a0 - 0x6811a2e0
// Functions (65):
//   xtra_createTextEngine
//   xtra_createTextObject
//   xtra_freeRandomState
//   xtra_compareTimestamp
//   xtra_getTextEngineFlags
//   xtra_advanceRandomCounter
//   xtra_generateRandomNode
//   xtra_getTimestamp
//   xtra_seedRandomState
//   xtra_resolveNodeId
//   xtra_initRandomState
//   xtra_generateUuid
//   xtra_getTextLineHeight
//   xtra_setTextRunAttr
//   xtra_renderTextBlock
//   xtra_measureTextWidth
//   xtra_wrapTextLine
//   xtra_getTextRunCount
//   xtra_compareLayoutPos
//   xtra_drawTextRun
//   xtra_updateTextLayout
//   xtra_countTextChars
//   xtra_charToByteOffset
//   xtra_measureTextExtent
//   xtra_isTextFormat
//   xtra_getTextFormatFlag
//   xtra_compareTextBlocks
//   xtra_getTextBlockRef
//   xtra_getTextBlockSize
//   xtra_findCharBoundary
//   xtra_fitTextToWidth
//   xtra_layoutSingleLine
//   xtra_layoutAllLines
//   xtra_updateLayoutIncremental
//   xtra_performLayout
//   xtra_isTextEngineReady
//   xtra_paintTextLayout
//   xtra_drawTextLine
//   xtra_drawTextBlock
//   xtra_countVisibleLines
//   xtra_setTextProperty
//   xtra_setTextPropertyByChar
//   xtra_hitTestTextPosition
//   xtra_layoutTextBlock
//   xtra_getCharPosition
//   xtra_getCharPositionByIndex
//   xtra_getLineYOffset
//   xtra_layoutTextRun
//   xtra_buildSelectionRects
//   xtra_processTextRun
//   xtra_getVisibleLineCount
//   xtra_trimString
//   xtra_trimStringRight
//   xtra_parseTextFormat
//   xtra_setTextFormat
//   xtra_scanTextDelimiters
//   xtra_trimTrailingWhitespace
//   xtra_comparePositions
//   xtra_compareFontPriority
//   xtra_renderTextLine
//   xtra_getTextData
//   xtra_lookupFontEntry
//   xtra_addFontRef
//   xtra_releaseFontRef
//   xtra_resolveFontData

// ============================================================
// Function: xtra_createTextEngine (xtra_createTextEngine)
// Address: 681168a0
// Size: 82 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_createTextEngine(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x24);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_finalizeCryptoKey(param_1);
  xtra_clearCryptoState(param_1 + 6);
  param_1[5] = xtra_getCryptoBlockSize;
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[1] = &PTR_FUN_68191eb0;
  return param_1;
}



// ============================================================
// Function: xtra_createTextObject (xtra_createTextObject)
// Address: 68116930
// Size: 49 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_createTextObject(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 8))
                    (*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4);
  if (iVar1 != 0) {
    uVar2 = xtra_getCryptoKeySize(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_freeRandomState (xtra_freeRandomState)
// Address: 681169b0
// Size: 11 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_freeRandomState(void)
{
  Ordinal_1113(&DAT_68196948);
  return 0;
}



// ============================================================
// Function: xtra_compareTimestamp (xtra_compareTimestamp)
// Address: 681169c0
// Size: 35 bytes
// Params: undefined4 param_1, uint * param_2
// Return: char
// Calling convention: __fastcall
// ============================================================

char __fastcall xtra_compareTimestamp(undefined4 param_1,uint *param_2)

{
  uint *unaff_ESI;
  
  if (param_2[1] <= unaff_ESI[1]) {
    if (param_2[1] < unaff_ESI[1]) {
      return '\x02';
    }
    if (*param_2 <= *unaff_ESI) {
      return (*param_2 < *unaff_ESI) + '\x01';
    }
  }
  return '\0';
}



// ============================================================
// Function: xtra_getTextEngineFlags (FUN_681169f0)
// Address: 681169f0
// Size: 159 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_getTextEngineFlags(void)

{
  int *piVar1;
  int iVar2;
  
  *(int *)(*(int *)(size_t)DAT_68196948 + 0x30) = *(int *)(*(int *)(size_t)DAT_68196948 + 0x30) + 7;
  *(int *)(*(int *)(size_t)DAT_68196948 + 0x34) = *(int *)(*(int *)(size_t)DAT_68196948 + 0x34) + 0x773;
  *(int *)(*(int *)(size_t)DAT_68196948 + 0x38) = *(int *)(*(int *)(size_t)DAT_68196948 + 0x38) + 0x120d3;
  if (0x26f4 < *(uint *)(*(int *)(size_t)DAT_68196948 + 0x30)) {
    piVar1 = (int *)(*(int *)(size_t)DAT_68196948 + 0x30);
    *piVar1 = *piVar1 + -0x268f;
  }
  if (0x18696 < *(uint *)(*(int *)(size_t)DAT_68196948 + 0x34)) {
    piVar1 = (int *)(*(int *)(size_t)DAT_68196948 + 0x34);
    *piVar1 = *piVar1 + -0x15f85;
  }
  if (0x36dd8 < *(uint *)(*(int *)(size_t)DAT_68196948 + 0x38)) {
    piVar1 = (int *)(*(int *)(size_t)DAT_68196948 + 0x38);
    *piVar1 = *piVar1 + -0x177e9;
  }
  iVar2 = *(int *)(size_t)DAT_68196948;
  *(int *)(iVar2 + 0x3c) =
       *(int *)(iVar2 + 0x30) * *(int *)(iVar2 + 0x3c) + *(int *)(iVar2 + 0x38) +
       *(int *)(iVar2 + 0x34);
  return *(uint *)(*(int *)(size_t)DAT_68196948 + 0x3c) & 0x3fff ^ *(uint *)(*(int *)(size_t)DAT_68196948 + 0x3c) >> 0x10;
}



// ============================================================
// Function: xtra_advanceRandomCounter (xtra_advanceRandomCounter)
// Address: 68116a90
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_advanceRandomCounter(void)
{
  ushort uVar1;
  uint uVar2;
  ushort *unaff_ESI;
  
  if (*unaff_ESI == 0) {
    uVar2 = xtra_getTextEngineFlags();
    *unaff_ESI = (ushort)uVar2;
  }
  uVar1 = *unaff_ESI + 1 & 0x3fff;
  *unaff_ESI = uVar1;
  if (uVar1 == 0) {
    *unaff_ESI = 1;
  }
  return 0;
}



// ============================================================
// Function: xtra_generateRandomNode (xtra_generateRandomNode)
// Address: 68116ac0
// Size: 42 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_generateRandomNode(undefined4 *param_1)
{
  uint uVar1;
  undefined2 *unaff_ESI;
  
  uVar1 = xtra_getTextEngineFlags();
  *unaff_ESI = (short)uVar1;
  uVar1 = xtra_getTextEngineFlags();
  unaff_ESI[1] = (short)uVar1;
  uVar1 = xtra_getTextEngineFlags();
  unaff_ESI[2] = (short)uVar1;
  *param_1 = 0;
  return 0;
}



// ============================================================
// Function: xtra_getTimestamp (xtra_getTimestamp)
// Address: 68116af0
// Size: 294 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int xtra_getTimestamp(undefined4 *param_1)
{
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float10 fVar1;
  longlong lVar2;
  double dVar3;
  undefined8 uVar4;
  longlong local_10;
  
  if (DAT_6819694c == '\0') {
    uVar4 = CONCAT44(unaff_ESI,unaff_EDI);
    lVar2 = Ordinal_1542();
    do {
      local_10 = Ordinal_1542(uVar4);
      if ((lVar2 != local_10) || (local_10 == 0xffffffff)) break;
    } while (local_10 != 0);
    if ((local_10 < 0) ||
       ((local_10 < 0x100000000 &&
        (((uint)local_10 < 0x7080 || ((local_10 < 0x100000000 && (local_10 < 0)))))))) {
      local_10 = 0x7080;
    }
    fVar1 = xtra_getTickMicroseconds();
    DAT_6819694c = '\x01';
    _DAT_68196950 =
         (double)(((float10)((double)local_10 * 1000000.0) - fVar1) -
                 (float10)0x7080 * (float10)1000000.0);
    _DAT_68196958 = 1.22192928e+17;
  }
  fVar1 = xtra_getTickMicroseconds();
  fVar1 = (fVar1 + (float10)_DAT_68196950) * (float10)10.0 + (float10)_DAT_68196958;
  dVar3 = floor((double)(fVar1 * (float10)2.3283064365386963e-10));
  (*(unsigned int *)((char *)&local_10 + 0)) = (undefined4)(longlong)ROUND((double)fVar1 - dVar3 * 4294967296.0);
  *param_1 = (undefined4)local_10;
  (*(unsigned int *)((char *)&local_10 + 0)) = (undefined4)(longlong)ROUND(dVar3);
  param_1[1] = (undefined4)local_10;
  return 0;
}



// ============================================================
// Function: xtra_seedRandomState (xtra_seedRandomState)
// Address: 68116c20
// Size: 126 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_seedRandomState(void)
{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  undefined2 local_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  ushort uStack_6;
  
  *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x30) = DAT_68191ec0;
  *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x34) = DAT_68191ec4;
  *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x38) = DAT_68191ec8;
  *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x3c) = DAT_68191ecc;
  xtra_getTimestamp((undefined4 *)&local_c);
  iVar1 = *(int *)(size_t)DAT_68196948;
  uVar2 = CONCAT22(uStack_6,uStack_8);
  DVar3 = GetCurrentProcessId();
  *(int *)(iVar1 + 0x3c) =
       *(int *)(iVar1 + 0x3c) +
       DVar3 + ((uint)uStack_6 ^
               ((CONCAT22(uStack_8,uStack_a) ^ CONCAT22(uStack_a,local_c)) & 0xffff ^ uVar2) &
               0xffff);
  return 0;
}



// ============================================================
// Function: xtra_resolveNodeId (xtra_resolveNodeId)
// Address: 68116ca0
// Size: 125 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_resolveNodeId(undefined4 *param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(size_t)DAT_68196948;
  if (*(int *)(iVar1 + 0x40) != 0) {
    *param_1 = *(undefined4 *)(iVar1 + 0x10);
    *(undefined2 *)(param_1 + 1) = *(undefined2 *)(iVar1 + 0x14);
    *param_2 = *(int *)(*(int *)(size_t)DAT_68196948 + 0x18);
    return 0;
  }
  xtra_generateRandomNode(param_2);
  if (*param_2 == 0) {
    *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x40) = 1;
    iVar1 = *(int *)(size_t)DAT_68196948;
    *(undefined4 *)(iVar1 + 0x10) = *param_1;
    *(undefined2 *)(iVar1 + 0x14) = *(undefined2 *)(param_1 + 1);
    return 0;
  }
  *param_2 = 5;
  return 0;
}



// ============================================================
// Function: xtra_initRandomState (xtra_initRandomState)
// Address: 68116d20
// Size: 94 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_initRandomState(void)
{
  uint uVar1;
  undefined4 *unaff_ESI;
  
  if (DAT_68196948 == (int *)0x0) {
    DAT_68196948 = (int *)Ordinal_1111(0x48,1);
    if (DAT_68196948 == (int *)0x0) {
      *unaff_ESI = 2;
      return 0;
    }
  }
  xtra_seedRandomState();
  xtra_getTimestamp((undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x24));
  uVar1 = xtra_getTextEngineFlags();
  *(short *)(*(int *)(size_t)DAT_68196948 + 0x2e) = (short)uVar1;
  *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x44) = 1;
  *unaff_ESI = 0;
  return 0;
}



// ============================================================
// Function: xtra_generateUuid (xtra_generateUuid)
// Address: 68116d80
// Size: 454 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_generateUuid(undefined4 *param_1,int *param_2)
{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  undefined3 extraout_var;
  undefined4 local_10;
  undefined2 local_c;
  uint local_8;
  int iVar6;
  
  bVar4 = false;
  if (((((DAT_68196948 != (int *)0x0) && (*(int *)(size_t)DAT_68196948 != 0)) &&
       (*(int *)(*(int *)(size_t)DAT_68196948 + 0x44) != 0)) || (xtra_initRandomState(), *param_2 == 0)) &&
     (xtra_resolveNodeId(&local_10,param_2), *param_2 == 0)) {
LAB_68116de0:
    do {
      xtra_getTimestamp((undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x1c));
      iVar3 = *(int *)(size_t)DAT_68196948;
      cVar5 = xtra_compareTimestamp(DAT_68196948,(uint *)(iVar3 + 0x24));
      iVar6 = CONCAT31(extraout_var,cVar5);
      if (iVar6 == 0) {
        xtra_advanceRandomCounter();
        *(undefined2 *)(*(int *)(size_t)DAT_68196948 + 0x2c) = 0;
      }
      else if (iVar6 == 1) {
        if (*(short *)(iVar3 + 0x2c) == 0x7fff) {
          bVar4 = true;
          goto LAB_68116de0;
        }
        *(short *)(iVar3 + 0x2c) = *(short *)(iVar3 + 0x2c) + 1;
      }
      else {
        if (iVar6 != 2) {
          *param_2 = 1;
          return 0;
        }
        *(undefined2 *)(iVar3 + 0x2c) = 0;
      }
    } while (bVar4);
    *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x24) = *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x1c);
    *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x28) = *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x20);
    iVar3 = *(int *)(size_t)DAT_68196948;
    uVar2 = *(ushort *)(iVar3 + 0x2c);
    if (uVar2 != 0) {
      if ((*(uint *)(iVar3 + 0x1c) & 0x80000000) == 0) {
        *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + (uint)uVar2;
      }
      else {
        *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + (uint)uVar2;
        if ((*(uint *)(*(int *)(size_t)DAT_68196948 + 0x1c) & 0x80000000) == 0) {
          piVar1 = (int *)(*(int *)(size_t)DAT_68196948 + 0x20);
          *piVar1 = *piVar1 + 1;
        }
      }
    }
    *param_1 = *(undefined4 *)(*(int *)(size_t)DAT_68196948 + 0x1c);
    *(undefined2 *)(param_1 + 1) = *(undefined2 *)(*(int *)(size_t)DAT_68196948 + 0x20);
    *(ushort *)((int)param_1 + 6) = *(ushort *)(*(int *)(size_t)DAT_68196948 + 0x22) & 0xfff | 0x1000;
    *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)(*(int *)(size_t)DAT_68196948 + 0x2e);
    *(byte *)(param_1 + 2) = *(byte *)(*(int *)(size_t)DAT_68196948 + 0x2f) & 0x3f | 0x80;
    *(undefined4 *)((int)param_1 + 10) = local_10;
    *(undefined2 *)((int)param_1 + 0xe) = local_c;
    *param_2 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_getTextLineHeight (FUN_68116f50)
// Address: 68116f50
// Size: 126 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_getTextLineHeight(int param_1,int param_2)
{
  undefined4 local_ac [41];
  uint local_8;
  
  Ordinal_1258();
  if (((DAT_681962c8 != 0) && (*(int *)(param_1 + 0x38) != 0)) && (*(int *)(param_1 + 0x34) != 0)) {
    if ((param_2 < 0) || (*(int *)(param_1 + 4) <= param_2)) {
      param_2 = *(int *)(param_1 + 4) + -1;
    }
    if (param_2 < 0) {
      return 0;
    }
    xtra_getBufferFlags(param_1,local_ac,param_2);
  }
  return 0;
}



// ============================================================
// Function: xtra_setTextRunAttr (FUN_68116fd0)
// Address: 68116fd0
// Size: 61 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_setTextRunAttr(int param_1,int param_2,undefined4 param_3)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Ordinal_1258();
  uVar2 = xtra_getTextLineHeight(param_1,in_EAX);
  Ordinal_1259(uVar2);
  uVar2 = Ordinal_1252(param_2 + in_EAX,param_3);
  Ordinal_1259(uVar1);
  return uVar2;
}



// ============================================================
// Function: xtra_renderTextBlock (FUN_68117010)
// Address: 68117010
// Size: 520 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, int * param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
xtra_renderTextBlock(int *param_1,int *param_2,undefined4 param_3,int *param_4,int param_5,int param_6)
{
  int iVar1;
  int iVar2;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int *local_e4;
  int local_e0;
  int local_dc;
  int *local_d8;
  undefined4 local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  undefined4 local_c4;
  int *local_c0;
  int local_bc;
  undefined4 local_b8 [37];
  undefined4 local_24;
  int local_14;
  int local_10;
  uint local_8;
  
  local_d4 = param_3;
  local_c0 = param_4;
  local_c8 = 0;
  local_bc = 0;
  local_d0 = 0;
  local_c4 = 0;
  if (param_4[1] - param_5 <= param_6) {
    param_6 = param_4[1] - param_5;
  }
  local_e4 = param_1;
  local_d8 = param_2;
  if (((param_5 < 0) || (param_4[1] - param_5 < 1)) || (*param_4 == 0)) {
    return 0;
  }
  local_cc = Ordinal_1114(*param_4);
  for (; 0 < param_6; param_6 = param_6 - iVar1) {
    iVar1 = xtra_getBufferRef((int)param_4,param_5,local_b8,(int)&local_14);
    if (iVar1 < 0) goto LAB_681171d9;
    iVar1 = (local_10 - param_5) + local_14;
    if (param_6 <= iVar1) {
      iVar1 = param_6;
    }
    param_4 = local_c0;
    if ((iVar1 < 1) ||
       (Ordinal_1252(param_5 + local_cc,&local_ec), param_4 = local_c0, iVar1 < local_ec)) break;
    iVar2 = Ordinal_1705(local_d4,local_24,local_cc + param_5,iVar1,&local_f4,&local_e8,&local_dc,
                         &local_e0);
    param_4 = local_c0;
    if (iVar2 == 0) goto LAB_681171d9;
    local_e0 = ((local_f0 - local_e8) - local_dc) + 1;
    if (local_c8 <= local_e0) {
      local_c8 = local_e0;
    }
    if (local_bc <= local_f0) {
      local_bc = local_f0;
    }
    local_d0 = local_d0 + local_f4;
    param_5 = param_5 + iVar1;
  }
  if (0 < param_4[9]) {
    local_bc = param_4[9];
  }
  if (local_e4 != (int *)0x0) {
    *local_e4 = local_d0;
    local_e4[1] = local_bc;
  }
  if (local_d8 != (int *)0x0) {
    *local_d8 = local_c8;
  }
  local_c4 = 1;
LAB_681171d9:
  if (local_cc != 0) {
    Ordinal_1115(*param_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_measureTextWidth (xtra_measureTextWidth)
// Address: 68117220
// Size: 83 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_measureTextWidth(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_ESI;
  
  uVar1 = Ordinal_1258();
  if (in_EAX == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = in_EAX + -1;
  }
  uVar2 = xtra_getTextLineHeight(param_1,iVar3);
  Ordinal_1259(uVar2);
  iVar3 = Ordinal_1251(unaff_ESI + unaff_EBX,unaff_ESI + in_EAX,param_2);
  Ordinal_1259(uVar1);
  return (iVar3 - unaff_ESI) - unaff_EBX;
}



// ============================================================
// Function: xtra_wrapTextLine (xtra_wrapTextLine)
// Address: 68117280
// Size: 138 bytes
// Params: void * this, int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall xtra_wrapTextLine(void *this,int param_1,int param_2,int *param_3)
{
  int iVar1;
  undefined4 uVar2;
  uint extraout_EDX;
  int unaff_EBX;
  int *unaff_ESI;
  int unaff_EDI;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  if ((int)this < param_2 - unaff_EDI) {
    this = (void *)((int)this + 1);
  }
  iVar1 = xtra_measureSimdTransfer(param_1,unaff_EBX,unaff_EDI,(int)this,&local_8,&local_c);
  if (local_8 == 0) {
    *unaff_ESI = *param_3;
  }
  else {
    *unaff_ESI = local_8;
    *param_3 = local_c;
  }
  if (iVar1 == 0) {
    iVar1 = *unaff_ESI;
    while (iVar1 < param_2 - unaff_EDI) {
      uVar2 = xtra_setTextRunAttr(param_1,unaff_EBX,&param_3);
      Ordinal_1253(uVar2);
      if ((extraout_EDX & 0x20000000) == 0) {
        return 0;
      }
      *unaff_ESI = *unaff_ESI + (int)param_3;
      iVar1 = *unaff_ESI;
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_getTextRunCount (FUN_68117310)
// Address: 68117310
// Size: 28 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_getTextRunCount(int param_1)
{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
    Ordinal_1163((int *)(param_1 + 0x2c));
  }
  return 0;
}



// ============================================================
// Function: xtra_compareLayoutPos (xtra_compareLayoutPos)
// Address: 68117330
// Size: 43 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_compareLayoutPos(int param_1,int *param_2)

{
  if (*param_2 < *(int *)(param_1 + 0x10)) {
    return 1;
  }
  return (int)(short)((*param_2 <= *(int *)(param_1 + 0x10)) - 1);
}



// ============================================================
// Function: xtra_drawTextRun (xtra_drawTextRun)
// Address: 68117360
// Size: 800 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int * param_5, int param_6, int * param_7, byte param_8
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
xtra_drawTextRun(int param_1,int param_2,undefined4 param_3,int param_4,int *param_5,int param_6,
            int *param_7,byte param_8)
{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_EDI;
  int local_120 [2];
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int *local_104;
  int local_100;
  int local_fc;
  undefined4 local_f8;
  int local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4 [19];
  ushort local_98;
  undefined1 local_96;
  undefined1 local_94 [68];
  undefined4 local_50;
  int local_40;
  int local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_f8 = param_3;
  local_100 = *param_5;
  local_fc = param_5[1];
  local_104 = param_7;
  local_f0 = 0;
  local_110 = param_1;
  local_f4 = param_2;
  if (param_1 != 0) {
    if (param_4 == 0) {
      return 0;
    }
    if (((-1 < param_2) && (unaff_EDI[1] != param_2 && -1 < unaff_EDI[1] - param_2)) &&
       (*unaff_EDI != 0)) {
      local_108 = Ordinal_1114(*unaff_EDI);
      if (param_7 != (int *)0x0) {
        for (; 0 < param_4; param_4 = param_4 - iVar3) {
          local_34 = 0;
          local_30 = 0;
          local_2c = 0;
          local_28 = 0;
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          iVar3 = xtra_getBufferRef((int)unaff_EDI,param_2,local_e4,(int)&local_40);
          uVar1 = local_f8;
          if ((iVar3 < 0) || (iVar3 = Ordinal_1606(local_f8,&local_34), iVar3 == 0))
          goto LAB_68117660;
          iVar3 = Ordinal_1610(uVar1);
          if (((uint)(local_20 - local_1c) < 9) && (iVar3 != 0)) {
            uVar2 = Ordinal_1738(iVar3,(local_98 & 0xff) << 8 | local_98 & 0xff,
                                 (uint)(local_98 >> 8) << 8 | (uint)(local_98 >> 8),
                                 CONCAT11(local_96,local_96));
            local_ec = CONCAT31((*(unsigned int *)((char *)&local_ec + 1)),uVar2);
            local_ec = local_ec & 0xffffff;
            uVar2 = Ordinal_1738(iVar3,CONCAT11((char)unaff_EDI[10],(char)unaff_EDI[10]),
                                 CONCAT11(*(undefined1 *)((int)unaff_EDI + 0x29),
                                          *(undefined1 *)((int)unaff_EDI + 0x29)),
                                 CONCAT11(*(undefined1 *)((int)unaff_EDI + 0x2a),
                                          *(undefined1 *)((int)unaff_EDI + 0x2a)));
            local_e8 = CONCAT31((*(unsigned int *)((char *)&local_e8 + 1)),uVar2);
            local_e8 = local_e8 & 0xffffff;
            param_2 = local_f4;
          }
          else {
            local_ec = CONCAT13(1,CONCAT12(local_96,local_98));
            local_e8 = CONCAT13(1,(int3)unaff_EDI[10]);
          }
          if ((param_8 & 1) != 0) {
            local_ec = 0x1000000;
            local_e8 = 0x1ffffff;
          }
          iVar3 = (local_3c - param_2) + local_40;
          if (param_4 <= iVar3) {
            iVar3 = param_4;
          }
          param_7 = local_104;
          if (iVar3 < 1) break;
          iVar5 = param_2 + local_108;
          Ordinal_1252(iVar5,&local_10c);
          param_7 = local_104;
          if (iVar3 < local_10c) break;
          iVar4 = Ordinal_1705(local_f8,local_50,iVar5,iVar3,local_120,0,0,0);
          if (iVar4 == 0) goto LAB_68117660;
          local_114 = local_fc + param_6;
          local_118 = local_100;
          iVar5 = Ordinal_1704(local_f8,&local_118,local_50,local_94,iVar5,iVar3,&local_ec,&local_e8
                               ,local_110);
          if (iVar5 == 0) goto LAB_68117660;
          param_2 = local_f4 + iVar3;
          local_100 = local_100 + local_120[0];
          param_7 = local_104;
          local_f4 = param_2;
        }
        *param_7 = local_100;
        param_7[1] = local_fc;
        local_f0 = 1;
      }
LAB_68117660:
      if (local_108 != 0) {
        Ordinal_1115(*unaff_EDI);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_updateTextLayout (xtra_updateTextLayout)
// Address: 68117690
// Size: 750 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_updateTextLayout(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int local_c;
  int local_8;
  
  if ((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x2c), iVar1 == 0)) {
    return 0;
  }
  local_c = Ordinal_1154(iVar1);
  if (((param_5 == 0) && (3 < local_c)) && ((param_2 != 0 || (param_3 != *(int *)(param_1 + 4))))) {
    if (param_3 != 0) {
      iVar2 = Ordinal_1165(iVar1,&local_8,&param_2,xtra_compareLayoutPos,0);
      if (iVar2 == 0) {
        local_8 = local_8 + -1;
      }
      if (local_c < 1) {
        return 0;
      }
      if (local_8 < 0) {
        return 0;
      }
      iVar3 = Ordinal_1157(iVar1);
      iVar2 = Ordinal_1156(iVar1,iVar3,local_8);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x1c) = 1;
      }
      if (param_4 == 0) {
        iVar4 = Ordinal_1156(iVar1,iVar3,local_8 + -1);
        if (iVar4 != 0) {
          *(undefined4 *)(iVar4 + 0x1c) = 1;
          iVar5 = *(int *)(iVar4 + 0x10);
          if (*(int *)(param_1 + 0xe4) <= *(int *)(iVar4 + 0x10)) {
            iVar5 = *(int *)(param_1 + 0xe4);
          }
          *(int *)(param_1 + 0xe4) = iVar5;
        }
        if (param_3 < 0) {
          param_5 = *(int *)(iVar2 + 0x10);
          iVar2 = param_3;
          if (local_8 < local_c) {
            do {
              iVar4 = Ordinal_1156(iVar1,iVar3,local_8);
              if (iVar2 < 1) {
                iVar2 = iVar2 + *(int *)(iVar4 + 0x18);
                param_4 = iVar2;
                if (iVar2 < 1) {
                  Ordinal_1160(iVar1,local_8);
                  iVar4 = local_8 + -1;
                  local_c = local_c + -1;
                  bVar6 = local_c == local_8;
                  local_8 = iVar4;
                  if ((bVar6) && (-1 < iVar4)) {
                    Ordinal_1158(iVar1,iVar3);
                    iVar3 = Ordinal_1157(iVar1);
                    if (iVar3 == 0) {
                      return 0;
                    }
                    iVar4 = Ordinal_1156(iVar1,iVar3,local_8);
                    iVar2 = *(int *)(iVar4 + 0x10);
                    if (*(int *)(param_1 + 0xe4) <= *(int *)(iVar4 + 0x10)) {
                      iVar2 = *(int *)(param_1 + 0xe4);
                    }
                    *(int *)(param_1 + 0xe4) = iVar2;
                    *(undefined4 *)(iVar4 + 0x1c) = 1;
                    iVar2 = param_4;
                  }
                }
                else {
                  *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + param_3;
                  *(int *)(iVar4 + 0x18) = iVar2;
                  *(undefined4 *)(iVar4 + 0x1c) = 1;
                  if (*(int *)(iVar4 + 0x10) < param_5) {
                    *(int *)(iVar4 + 0x10) = param_5;
                  }
                  iVar5 = *(int *)(iVar4 + 0x10);
                  if (*(int *)(param_1 + 0xe4) <= *(int *)(iVar4 + 0x10)) {
                    iVar5 = *(int *)(param_1 + 0xe4);
                  }
                  *(int *)(param_1 + 0xe4) = iVar5;
                }
              }
              else {
                *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + param_3;
              }
              local_8 = local_8 + 1;
            } while (local_8 < local_c);
          }
          if (1 < local_c) {
            iVar2 = Ordinal_1156(iVar1,iVar3,local_c + -1);
            if (*(int *)(iVar2 + 0x18) == 0) {
              iVar4 = Ordinal_1156(iVar1,iVar3,local_c + -2);
              *(undefined4 *)(iVar4 + 0x1c) = 1;
              iVar2 = *(int *)(iVar4 + 0x10);
              if (*(int *)(param_1 + 0xe4) <= *(int *)(iVar4 + 0x10)) {
                iVar2 = *(int *)(param_1 + 0xe4);
              }
              *(int *)(param_1 + 0xe4) = iVar2;
              Ordinal_1160(iVar1,local_c + -1);
            }
          }
        }
        else {
          *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + param_3;
          while (local_8 = local_8 + 1, local_8 < local_c) {
            iVar2 = Ordinal_1156(iVar1,iVar3,local_8);
            *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + param_3;
          }
        }
      }
      else {
        iVar2 = param_3 - *(int *)(iVar2 + 0x18);
        while ((param_3 = iVar2, local_8 = local_8 + 1, local_8 < local_c && (-1 < param_3))) {
          iVar4 = Ordinal_1156(iVar1,iVar3,local_8);
          if ((param_3 != 0) || (iVar2 = 0, *(int *)(iVar4 + 0x18) == 0)) {
            *(undefined4 *)(iVar4 + 0x1c) = 1;
            iVar2 = param_3 - *(int *)(iVar4 + 0x18);
          }
        }
      }
      if (iVar3 == 0) {
        return 1;
      }
      Ordinal_1158(*(undefined4 *)(param_1 + 0x2c),iVar3);
      return 1;
    }
  }
  else {
    xtra_getTextRunCount(param_1);
  }
  return 1;
}



// ============================================================
// Function: xtra_countTextChars (xtra_countTextChars)
// Address: 68117980
// Size: 214 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_countTextChars(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  int iVar4;
  int unaff_EDI;
  int local_c0;
  int local_bc;
  undefined4 local_b8 [38];
  undefined4 local_20;
  int local_14;
  int local_10;
  uint local_8;
  
  uVar1 = Ordinal_1258();
  iVar4 = 0;
  local_bc = 0;
  if (0 < unaff_EBX) {
    while (iVar4 < *(int *)(unaff_EDI + 4)) {
      iVar2 = xtra_writeToBuffer(*(undefined4 *)(unaff_EDI + 0x34),iVar4);
      if (iVar2 == -1) {
        uVar3 = *(undefined4 *)(unaff_EDI + 0xd8);
      }
      else {
        Ordinal_1155(*(undefined4 *)(unaff_EDI + 0x34),iVar2,&local_14);
        xtra_getBufferFlags(unaff_EDI,local_b8,iVar4);
        uVar3 = local_20;
      }
      Ordinal_1259(uVar3);
      if (iVar4 < local_10 + local_14) {
        do {
          Ordinal_1252(param_1 + iVar4,&local_c0);
          iVar4 = iVar4 + local_c0;
          local_bc = local_bc + 1;
          if (unaff_EBX <= iVar4) goto LAB_68117a33;
        } while (iVar4 < local_10 + local_14);
      }
      if (unaff_EBX <= iVar4) break;
    }
  }
LAB_68117a33:
  Ordinal_1259(uVar1);
  return 0;
}



// ============================================================
// Function: xtra_charToByteOffset (xtra_charToByteOffset)
// Address: 68117a60
// Size: 208 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_charToByteOffset(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int iVar3;
  int iVar4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8 [38];
  undefined4 local_20;
  int local_14;
  int local_10;
  uint local_8;
  
  local_bc = Ordinal_1258();
  iVar3 = 0;
  iVar4 = 0;
  if (0 < param_2) {
    while (iVar3 < *(int *)(unaff_EBX + 4)) {
      iVar1 = xtra_writeToBuffer(*(undefined4 *)(unaff_EBX + 0x34),iVar3);
      if (iVar1 == -1) {
        uVar2 = *(undefined4 *)(unaff_EBX + 0xd8);
      }
      else {
        Ordinal_1155(*(undefined4 *)(unaff_EBX + 0x34),iVar1,&local_14);
        xtra_getBufferFlags(unaff_EBX,local_b8,iVar3);
        uVar2 = local_20;
      }
      Ordinal_1259(uVar2);
      if (iVar3 < local_10 + local_14) {
        do {
          Ordinal_1252(param_1 + iVar3,&local_c0);
          iVar3 = iVar3 + local_c0;
          iVar4 = iVar4 + 1;
          if (param_2 <= iVar4) goto LAB_68117b10;
        } while (iVar3 < local_10 + local_14);
      }
      if (param_2 <= iVar4) break;
    }
  }
LAB_68117b10:
  Ordinal_1259(local_bc);
  return 0;
}



// ============================================================
// Function: xtra_measureTextExtent (xtra_measureTextExtent)
// Address: 68117b30
// Size: 152 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_measureTextExtent(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if (in_EAX == 0) {
    return 0;
  }
  iVar1 = Ordinal_1114(*unaff_EDI);
  uVar2 = Ordinal_1258();
  uVar3 = xtra_getTextLineHeight((int)unaff_EDI,param_1 + -1 + in_EAX);
  Ordinal_1259(uVar3);
  Ordinal_1251(param_1 + iVar1,param_1 + iVar1 + in_EAX,&local_8);
  uVar3 = xtra_setTextRunAttr((int)unaff_EDI,iVar1,&local_8);
  Ordinal_1253(uVar3);
  if ((extraout_EDX & 0x20000000) != 0) {
    in_EAX = in_EAX - local_8;
  }
  Ordinal_1259(uVar2);
  Ordinal_1115(*unaff_EDI);
  return in_EAX;
}



// ============================================================
// Function: xtra_isTextFormat (FUN_68117bd0)
// Address: 68117bd0
// Size: 48 bytes
// Params: int param_1, undefined4 param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool xtra_isTextFormat(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    *(undefined4 *)(iVar1 + 0xec) = param_2;
    Ordinal_1115(param_1);
  }
  return param_1 != 0;
}



// ============================================================
// Function: xtra_getTextFormatFlag (xtra_getTextFormatFlag)
// Address: 68117c00
// Size: 40 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getTextFormatFlag(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    uVar1 = *(undefined4 *)(iVar2 + 0xec);
    Ordinal_1115(param_1);
  }
  return uVar1;
}



// ============================================================
// Function: xtra_compareTextBlocks (xtra_compareTextBlocks)
// Address: 68117c30
// Size: 771 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_compareTextBlocks(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 local_14;
  int local_8;
  
  uVar11 = 0;
  local_14 = 0;
  puVar2 = (undefined4 *)Ordinal_1114(param_1);
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)Ordinal_1114(param_2);
    if ((((puVar3 != (undefined4 *)0x0) && (puVar2[1] == puVar3[1])) && (puVar2[0xc] == puVar3[0xc])
        ) && (iVar4 = Ordinal_1122(*puVar2,*puVar3), iVar4 != 0)) {
      iVar4 = Ordinal_1154(puVar3[0xb]);
      iVar5 = Ordinal_1154(puVar2[0xb]);
      uVar11 = local_14;
      if (iVar5 == iVar4) {
        iVar4 = Ordinal_1154(puVar2[0xb]);
        uVar6 = Ordinal_1157(puVar2[0xb]);
        uVar7 = Ordinal_1157(puVar3[0xb]);
        local_8 = 0;
        if (0 < iVar4) {
          do {
            piVar8 = (int *)Ordinal_1156(puVar2[0xb],uVar6,local_8);
            piVar9 = (int *)Ordinal_1156(puVar3[0xb],uVar7,local_8);
            if (((((*piVar8 != *piVar9) || (piVar8[1] != piVar9[1])) ||
                 ((piVar8[2] != piVar9[2] || ((piVar8[3] != piVar9[3] || (piVar8[4] != piVar9[4]))))
                 )) || (piVar8[5] != piVar9[5])) || (piVar8[6] != piVar9[6])) goto LAB_68117f12;
            local_8 = local_8 + 1;
          } while (local_8 < iVar4);
        }
        Ordinal_1158(puVar2[0xb],uVar6);
        Ordinal_1158(puVar3[0xb],uVar7);
        iVar4 = Ordinal_1154(puVar2[0xe]);
        iVar5 = Ordinal_1154(puVar3[0xe]);
        if (iVar4 == iVar5) {
          iVar4 = Ordinal_1154(puVar2[0xe]);
          uVar6 = Ordinal_1157(puVar2[0xe]);
          uVar7 = Ordinal_1157(puVar3[0xe]);
          local_8 = 0;
          if (0 < iVar4) {
            do {
              iVar5 = Ordinal_1156(puVar2[0xe],uVar6,local_8);
              iVar10 = Ordinal_1156(puVar3[0xe],uVar7,local_8);
              if ((((*(int *)(iVar5 + 0x50) != *(int *)(iVar10 + 0x50)) ||
                   (*(int *)(iVar5 + 0x40) != *(int *)(iVar10 + 0x40))) ||
                  (*(char *)(iVar5 + 0x4c) != *(char *)(iVar10 + 0x4c))) ||
                 (((*(char *)(iVar5 + 0x4d) != *(char *)(iVar10 + 0x4d) ||
                   (*(char *)(iVar5 + 0x4e) != *(char *)(iVar10 + 0x4e))) ||
                  (sVar1 = Ordinal_1208(iVar5,iVar10), sVar1 != 0)))) goto LAB_68117f12;
              local_8 = local_8 + 1;
            } while (local_8 < iVar4);
          }
          Ordinal_1158(puVar2[0xe],uVar6);
          Ordinal_1158(puVar3[0xe],uVar7);
          iVar4 = Ordinal_1154(puVar2[0xd]);
          iVar5 = Ordinal_1154(puVar3[0xd]);
          if (iVar4 == iVar5) {
            iVar4 = Ordinal_1154(puVar2[0xd]);
            uVar6 = Ordinal_1157(puVar2[0xd]);
            uVar7 = Ordinal_1157(puVar3[0xd]);
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                piVar8 = (int *)Ordinal_1156(puVar2[0xd],uVar6,iVar5);
                piVar9 = (int *)Ordinal_1156(puVar3[0xd],uVar7,iVar5);
                if (((*piVar8 != *piVar9) || (piVar8[1] != piVar9[1])) || (piVar8[2] != piVar9[2]))
                goto LAB_68117f12;
                iVar5 = iVar5 + 1;
              } while (iVar5 < iVar4);
            }
            Ordinal_1158(puVar2[0xd],uVar6);
            Ordinal_1158(puVar3[0xd],uVar7);
            uVar11 = 1;
          }
        }
      }
    }
LAB_68117f12:
    Ordinal_1115(param_1);
    if (puVar3 != (undefined4 *)0x0) {
      Ordinal_1115(param_2);
    }
  }
  return uVar11;
}



// ============================================================
// Function: xtra_getTextBlockRef (FUN_68117f40)
// Address: 68117f40
// Size: 82 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getTextBlockRef(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)Ordinal_1114(param_1);
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = Ordinal_1114(*puVar1);
      if (iVar2 != 0) {
        uVar3 = xtra_countTextChars(iVar2);
        Ordinal_1115(*puVar1);
      }
      Ordinal_1115(param_1);
    }
    return uVar3;
  }
  return 0xffffffff;
}



// ============================================================
// Function: xtra_getTextBlockSize (FUN_68117fa0)
// Address: 68117fa0
// Size: 83 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getTextBlockSize(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)Ordinal_1114(param_1);
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = Ordinal_1114(*puVar1);
      if (iVar2 != 0) {
        uVar3 = xtra_charToByteOffset(iVar2,param_2);
        Ordinal_1115(*puVar1);
      }
      Ordinal_1115(param_1);
    }
    return uVar3;
  }
  return 0xffffffff;
}



// ============================================================
// Function: xtra_findCharBoundary (xtra_findCharBoundary)
// Address: 68118000
// Size: 96 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_findCharBoundary(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_ESI;
  int local_8;
  
  uVar1 = 0;
  if (param_1 <= param_3) {
    *unaff_EBX = 0;
    iVar2 = Ordinal_1251();
    *unaff_EBX = iVar2 - unaff_ESI;
    if (iVar2 + local_8 == unaff_ESI + param_1) {
      *unaff_EBX = (iVar2 - unaff_ESI) + local_8;
      if (param_1 < param_3) {
        Ordinal_1252(unaff_ESI + param_1,&local_8);
      }
      else {
        local_8 = 0;
      }
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_8;
    }
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_fitTextToWidth (xtra_fitTextToWidth)
// Address: 68118060
// Size: 431 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_fitTextToWidth(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_2c [3];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = 0;
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_c = Ordinal_1114(*param_2);
  iVar2 = param_2[1] - param_3;
  iVar3 = iVar2;
  if (in_EAX < iVar2) {
    iVar3 = in_EAX;
  }
  if (0 < iVar3) {
    iVar1 = (param_4 * 4) / 3;
    local_8 = iVar3;
    if (iVar1 < iVar3) {
      local_8 = iVar1;
    }
    local_1c = 0;
    local_14 = 0;
    if (in_EAX < iVar2) {
      iVar2 = in_EAX;
    }
    iVar2 = xtra_findCharBoundary(local_8,&local_18,iVar2);
    iVar3 = local_8;
    if (iVar2 != 0) {
      iVar2 = local_18 + local_14;
      local_10 = iVar2;
      xtra_renderTextBlock(local_2c,(int *)0x0,param_1,param_2,param_3,iVar2);
      local_18 = local_2c[0];
      iVar3 = local_8;
      if ((param_4 <= local_2c[0]) &&
         (xtra_setTextRunAttr((int)param_2,local_c,&local_14), iVar3 = iVar4, local_14 < iVar2)) {
        do {
          iVar2 = xtra_measureTextWidth((int)param_2,local_2c + 2);
          if (iVar2 <= iVar4) {
            xtra_setTextRunAttr((int)param_2,local_c,&local_20);
            iVar2 = iVar2 + local_20;
            if ((iVar2 <= iVar4) &&
               (iVar2 = iVar2 + (local_2c[2] - local_20), iVar3 = local_8, iVar2 <= iVar4)) break;
          }
          xtra_renderTextBlock(local_2c,(int *)0x0,param_1,param_2,param_3,iVar2);
          if (param_4 < local_2c[0]) {
            local_18 = local_2c[0];
            local_10 = iVar2;
          }
          else {
            local_1c = local_2c[0];
            iVar4 = iVar2;
          }
          xtra_setTextRunAttr((int)param_2,local_c,&local_14);
          iVar3 = iVar4;
        } while (local_14 < local_10 - iVar4);
      }
    }
  }
  local_8 = iVar3;
  iVar2 = local_8;
  if (local_c != 0) {
    Ordinal_1115(*param_2);
  }
  return iVar2;
}



// ============================================================
// Function: xtra_layoutSingleLine (xtra_layoutSingleLine)
// Address: 68118210
// Size: 395 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int * param_4, int * param_5, int * param_6, int * param_7
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * xtra_layoutSingleLine(undefined4 param_1,int *param_2,int param_3,int *param_4,int *param_5,
                   int *param_6,int *param_7)

{
  int in_EAX;
  undefined4 uVar1;
  uint extraout_EDX;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int local_24;
  int local_20;
  void *local_1c;
  void *local_18;
  void *local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = 0;
  local_18 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_10 = Ordinal_1114(*param_2);
  local_8 = (void *)(param_2[1] - in_EAX);
  if (0 < (int)local_8) {
    iVar3 = 0;
    local_14 = local_8;
    while( true ) {
      iVar2 = iVar3;
      uVar1 = xtra_setTextRunAttr((int)param_2,local_10,&local_1c);
      Ordinal_1253(uVar1);
      if (((extraout_EDX & 0x10000000) != 0) && (local_18 = local_1c, local_1c != (void *)0x0))
      break;
      local_14 = (void *)((int)local_14 - (int)local_1c);
      iVar3 = iVar2 + (int)local_1c;
      if ((param_3 * 4 < iVar3) || ((int)local_14 < 1)) break;
    }
    pvVar4 = (void *)(iVar2 + (int)local_1c);
    local_1c = (void *)((int)pvVar4 - (int)local_18);
    local_14 = pvVar4;
    if ((int)local_1c < 1) {
      xtra_renderTextBlock(&local_24,param_5,param_1,param_2,in_EAX,(int)local_18);
      local_24 = 1;
    }
    else {
      xtra_renderTextBlock(&local_24,param_5,param_1,param_2,in_EAX,(int)local_1c);
    }
    if (param_3 < local_24) {
      local_8 = (void *)xtra_fitTextToWidth(param_1,param_2,in_EAX,param_3);
      if (local_8 == (void *)0x0) {
        xtra_setTextRunAttr((int)param_2,local_10,&local_8);
      }
      if (param_2[5] != 0) {
        xtra_wrapTextLine(local_8,(int)param_2,param_2[1],(int *)&local_8);
        pvVar4 = local_14;
      }
      if (0 < (int)local_8) {
        xtra_renderTextBlock(&local_24,param_5,param_1,param_2,in_EAX,(int)local_8);
      }
      if (param_2[6] != 0) goto LAB_68118357;
    }
    else {
      local_8 = local_1c;
    }
    local_c = (int)pvVar4;
  }
LAB_68118357:
  if (param_6 != (int *)0x0) {
    *param_6 = local_c;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = (int)local_18;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = local_24;
    param_4[1] = local_20;
  }
  if (local_10 != 0) {
    Ordinal_1115(*param_2);
  }
  return local_8;
}



// ============================================================
// Function: xtra_layoutAllLines (xtra_layoutAllLines)
// Address: 681183a0
// Size: 359 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_layoutAllLines(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  int *unaff_ESI;
  void *pvVar2;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  void *local_38;
  void *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_40 = param_1;
  iVar1 = Ordinal_1150(0x10,0x10,0x20);
  unaff_ESI[0xb] = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  local_2c = 0;
  pvVar2 = (void *)unaff_ESI[1];
  do {
    if ((int)pvVar2 < 1) break;
    local_30 = 0;
    local_34 = xtra_layoutSingleLine(local_40,unaff_ESI,param_3,&local_48,&local_3c,(int *)&local_38,
                            &local_30);
    if ((int)pvVar2 < (int)local_34) {
      local_34 = pvVar2;
    }
    if ((int)pvVar2 < (int)local_38) {
      local_38 = pvVar2;
    }
    if ((int)local_38 < 1) {
LAB_681184f3:
      return 0;
    }
    local_28 = param_2;
    if ((short)unaff_ESI[3] != 1) {
      if ((short)unaff_ESI[3] == 3) {
        local_28 = (param_2 - local_48) + param_3;
      }
      else {
        local_28 = (param_3 - local_48) / 2 + param_2;
      }
    }
    local_1c = local_3c;
    local_18 = local_2c;
    local_2c = local_2c + (int)local_38;
    pvVar2 = (void *)((int)pvVar2 - (int)local_38);
    local_24 = local_48;
    local_20 = local_44;
    local_c = 0;
    local_14 = local_34;
    local_10 = local_38;
    iVar1 = Ordinal_1152(unaff_ESI[0xb],&local_28);
    if (iVar1 == 0) goto LAB_681184f3;
    if ((pvVar2 == (void *)0x0) && (local_30 != 0)) {
      local_18 = unaff_ESI[1];
      local_14 = (void *)0x0;
      local_10 = (void *)0x0;
      local_24 = 1;
      iVar1 = Ordinal_1152(unaff_ESI[0xb],&local_28);
      if (iVar1 == 0) goto LAB_681184f3;
    }
  } while (unaff_ESI[4] != 0);
  return 0;
}



// ============================================================
// Function: xtra_updateLayoutIncremental (xtra_updateLayoutIncremental)
// Address: 68118510
// Size: 868 bytes
// Params: void * this, undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall xtra_updateLayoutIncremental(void *this,undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [9];
  
  local_40 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_48 = this;
  iVar1 = Ordinal_1157(*(undefined4 *)((int)this + 0x2c));
  local_38 = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)((int)this + 0x10) == 0) {
    local_30 = 0;
    local_2c = 0;
    piVar2 = (int *)Ordinal_1156(*(undefined4 *)((int)this + 0x2c),iVar1);
    if (piVar2 == (int *)0x0) goto LAB_6811883b;
  }
  else {
    local_30 = *(int *)((int)this + 0xe4);
    iVar6 = Ordinal_1165(*(undefined4 *)((int)this + 0x2c),&local_2c,&local_30,xtra_compareLayoutPos,0);
    if (iVar6 == 0) {
      local_2c = local_2c + -1;
    }
    piVar2 = (int *)Ordinal_1156(*(undefined4 *)((int)this + 0x2c),iVar1,local_2c);
    if (piVar2 == (int *)0x0) goto LAB_6811883b;
    local_30 = piVar2[4];
  }
  iVar6 = *(int *)((int)this + 4) - local_30;
  local_4c = iVar6;
  local_3c = Ordinal_1154(*(undefined4 *)((int)this + 0x2c));
  local_34 = local_3c - local_2c;
  iVar1 = local_4c;
  do {
    local_4c = iVar6;
    if (local_4c < 1) break;
    local_54 = 0;
    local_50 = 0;
    iVar4 = 0;
    if (piVar2[7] != 0) {
      local_4c = iVar1;
      pvVar3 = xtra_layoutSingleLine(param_1,this,param_3,&local_64,&local_68,&local_58,&local_54);
      iVar1 = local_38;
      if (local_58 < 1) goto LAB_6811883b;
      iVar6 = piVar2[6] - local_58;
      local_5c = iVar6;
      if (iVar6 < 1) {
        if ((iVar6 < 0) && (local_44 = local_2c + 1, local_44 < local_3c)) {
          do {
            iVar4 = Ordinal_1156(*(int *)((int)this + 0x2c),local_38,local_44);
            iVar1 = local_38;
            if (iVar4 == 0) goto LAB_6811883b;
            iVar6 = iVar6 + *(int *)(iVar4 + 0x18);
            local_5c = iVar6;
            if (iVar6 < 1) {
              Ordinal_1160(*(int *)((int)this + 0x2c),local_44);
              local_3c = local_3c + -1;
              local_34 = local_34 + -1;
              local_50 = 1;
            }
            else {
              *(undefined4 *)(iVar4 + 0x1c) = 1;
              *(int *)(iVar4 + 0x18) = iVar6;
            }
          } while ((iVar6 < 0) && (local_44 = local_44 + 1, local_44 < local_3c));
        }
      }
      else {
        local_28[4] = local_58 + local_30;
        local_3c = local_3c + 1;
        local_34 = local_34 + 1;
        local_28[7] = 1;
        local_28[6] = iVar6;
        iVar6 = Ordinal_1151(*(int *)((int)this + 0x2c),local_2c + 1,local_28);
        iVar1 = local_38;
        if (iVar6 == 0) goto LAB_6811883b;
        local_50 = 1;
      }
      iVar1 = param_2;
      if ((short)*(int *)((int)this + 0xc) != 1) {
        if ((short)*(int *)((int)this + 0xc) == 3) {
          iVar1 = (param_2 - local_64) + param_3;
        }
        else {
          iVar1 = (param_3 - local_64) / 2 + param_2;
        }
      }
      if (local_50 != 0) {
        Ordinal_1158(*(int *)((int)this + 0x2c),local_38);
        local_38 = Ordinal_1157(*(int *)((int)this + 0x2c));
        if (local_38 == 0) goto LAB_68118849;
        piVar2 = (int *)Ordinal_1156(*(int *)((int)this + 0x2c),local_38,local_2c);
      }
      piVar2[2] = local_60;
      *piVar2 = iVar1;
      piVar2[3] = local_68;
      piVar2[1] = local_64;
      piVar2[7] = 0;
      piVar2[5] = (int)pvVar3;
      piVar2[4] = local_30;
      piVar2[6] = local_58;
      iVar4 = local_5c;
    }
    local_30 = local_30 + piVar2[6];
    iVar6 = local_4c - piVar2[6];
    local_34 = local_34 + -1;
    local_2c = local_2c + 1;
    local_4c = iVar6;
    if (0 < iVar6) {
      if (local_34 < 1) {
        local_28[7] = 1;
        local_28[4] = local_30;
        local_28[6] = iVar4;
        iVar4 = Ordinal_1152(*(int *)((int)this + 0x2c),local_28);
        iVar1 = local_38;
        if (iVar4 == 0) goto LAB_6811883b;
      }
      piVar2 = (int *)Ordinal_1156(*(int *)((int)this + 0x2c),local_38,local_2c);
    }
    if ((iVar6 == 0) && (local_54 != 0)) {
      piVar5 = piVar2;
      piVar7 = local_28;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar7 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      }
      local_28[4] = local_48[1];
      local_28[5] = 0;
      local_28[6] = 0;
      local_28[1] = 1;
      if (local_34 < 1) {
        iVar4 = Ordinal_1152(local_48[0xb],local_28);
      }
      else {
        iVar4 = Ordinal_1159(local_48[0xb],local_2c,local_28);
      }
      this = local_48;
      iVar6 = local_4c;
      iVar1 = local_38;
      if (iVar4 == 0) goto LAB_6811883b;
    }
    iVar1 = local_4c;
  } while (*(int *)((int)this + 0x10) != 0);
  local_4c = iVar1;
  local_40 = 1;
  iVar1 = local_38;
LAB_6811883b:
  if (iVar1 != 0) {
    Ordinal_1158(*(int *)((int)this + 0x2c),iVar1);
  }
LAB_68118849:
  return 0;
}



// ============================================================
// Function: xtra_performLayout (xtra_performLayout)
// Address: 68118880
// Size: 172 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_performLayout(void)

{
  bool bVar1;
  int *in_EAX;
  int iVar2;
  int unaff_EDI;
  int local_8;
  
  bVar1 = false;
  local_8 = 0;
  if (in_EAX != (int *)0x0) {
    if ((in_EAX[0xb] == 0) || (in_EAX[0x3a] != 0)) {
      if (unaff_EDI == 0) goto LAB_6811891d;
      Ordinal_1602();
      iVar2 = in_EAX[2];
      bVar1 = true;
      if ((((0 < iVar2) && (*in_EAX != 0)) && (in_EAX[0xd] != 0)) &&
         ((in_EAX[0xe] != 0 && (0 < in_EAX[1])))) {
        if (in_EAX[0xb] == 0) {
          iVar2 = xtra_layoutAllLines(unaff_EDI,0,iVar2);
        }
        else {
          iVar2 = xtra_updateLayoutIncremental(in_EAX,unaff_EDI,0,iVar2);
        }
        if (iVar2 != 0) {
          iVar2 = Ordinal_1154(in_EAX[0xb]);
          in_EAX[0xc] = iVar2;
          if (iVar2 != 0) {
            in_EAX[0x3a] = 0;
            goto LAB_68118901;
          }
        }
      }
    }
    else {
LAB_68118901:
      local_8 = 1;
    }
  }
  if ((unaff_EDI != 0) && (bVar1)) {
    Ordinal_1603();
  }
  if (local_8 != 0) {
    return local_8;
  }
LAB_6811891d:
  xtra_getTextRunCount((int)in_EAX);
  return local_8;
}



// ============================================================
// Function: xtra_isTextEngineReady (FUN_68118930)
// Address: 68118930
// Size: 19 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool xtra_isTextEngineReady(void)

{
  int iVar1;
  
  iVar1 = xtra_performLayout();
  return iVar1 != 0;
}



// ============================================================
// Function: xtra_paintTextLayout (xtra_paintTextLayout)
// Address: 68118950
// Size: 472 bytes
// Params: int param_1, int param_2, int * param_3, int param_4, byte param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_paintTextLayout(int param_1,int param_2,int *param_3,int param_4,byte param_5,int param_6)
{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_58 [2];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int *local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_50 = param_6;
  local_38 = param_1;
  local_4c = param_2;
  local_40 = param_3;
  local_34 = 0;
  if (param_1 == 0) goto LAB_68118b18;
  Ordinal_1602(param_1);
  if (param_2 != 0) {
    piVar2 = (int *)Ordinal_1114(param_2);
    if (((*piVar2 != 0) && (piVar2[0xd] != 0)) && (piVar2[0xe] != 0)) {
      Ordinal_1607(param_1,local_28);
      if (piVar2[1] < 1) {
        local_34 = 1;
      }
      else {
        bVar1 = xtra_isTextEngineReady();
        if (CONCAT31(extraout_var,bVar1) != 0) {
          local_14 = param_3[1];
          local_18 = *param_3;
          local_c = local_14 + param_4;
          local_10 = piVar2[2] + local_18;
          if (piVar2[8] == 0) {
            local_2c = CONCAT13(1,(int3)piVar2[10]);
            iVar3 = Ordinal_1619(param_1,&local_18,&local_2c);
            if (iVar3 == 0) goto LAB_68118b06;
          }
          local_2c = -piVar2[0x3b];
          local_30 = 0;
          local_3c = Ordinal_1157(piVar2[0xb]);
          while( true ) {
            iVar3 = *param_3;
            iVar5 = param_3[1];
            piVar4 = (int *)Ordinal_1156(piVar2[0xb],local_3c,local_30);
            if ((piVar4 == (int *)0x0) || ((piVar2[7] != 0 && (param_4 < local_2c)))) break;
            local_2c = local_2c + piVar4[2];
            iVar5 = iVar5 + local_2c;
            if (local_1c < iVar5 - piVar4[2]) break;
            if ((local_24 < iVar5) || (local_30 + 1 == piVar2[0xc])) {
              local_44 = iVar5 - piVar4[2];
              local_48 = iVar3 + *piVar4;
              iVar3 = xtra_drawTextRun(local_50,piVar4[4],local_38,piVar4[5],&local_48,piVar4[3],
                                   local_58,param_5);
              if (iVar3 == 0) goto LAB_68118af2;
            }
            if ((piVar2[4] == 0) ||
               (local_30 = local_30 + 1, param_3 = local_40, param_4 < local_2c)) break;
          }
          local_34 = 1;
LAB_68118af2:
          param_1 = local_38;
          if (local_3c != 0) {
            Ordinal_1158(piVar2[0xb],local_3c);
            param_1 = local_38;
          }
        }
      }
    }
LAB_68118b06:
    Ordinal_1115(local_4c);
  }
  Ordinal_1603(param_1);
LAB_68118b18:
  return 0;
}



// ============================================================
// Function: xtra_drawTextLine (FUN_68118b30)
// Address: 68118b30
// Size: 259 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_drawTextLine(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (param_1 == 0) {
    return 0;
  }
  Ordinal_1602(param_1);
  iVar5 = 0;
  if (param_2 == 0) goto LAB_68118c29;
  piVar2 = (int *)Ordinal_1114(param_2);
  if (((*piVar2 != 0) && (piVar2[0xd] != 0)) && (piVar2[0xe] != 0)) {
    bVar1 = xtra_isTextEngineReady();
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar5 = param_3 + -1 + param_4;
      if (param_4 < 0) {
        iVar5 = 0x7fff;
      }
      iVar3 = Ordinal_1157(piVar2[0xb]);
      while ((param_3 <= iVar5 && (iVar4 = Ordinal_1156(piVar2[0xb],iVar3,param_3), iVar4 != 0))) {
        local_8 = local_8 + *(int *)(iVar4 + 8);
        param_3 = param_3 + 1;
      }
      if (1 < param_4) {
        local_8 = local_8 + -1;
      }
      if (iVar3 != 0) {
        Ordinal_1158(piVar2[0xb],iVar3);
      }
      if (local_8 != 0) goto LAB_68118c1c;
    }
    iVar5 = Ordinal_1705(param_1,piVar2[0x35],&DAT_6817d220,1,local_10,0,0,0);
    if (iVar5 != 0) {
      local_8 = local_c;
    }
  }
LAB_68118c1c:
  Ordinal_1115(param_2);
  iVar5 = local_8;
LAB_68118c29:
  Ordinal_1603(param_1);
  return iVar5;
}



// ============================================================
// Function: xtra_drawTextBlock (FUN_68118c40)
// Address: 68118c40
// Size: 218 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_drawTextBlock(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  iVar6 = 0;
  local_8 = 0;
  if (param_1 != 0) {
    Ordinal_1602(param_1);
    if (param_2 != 0) {
      piVar3 = (int *)Ordinal_1114(param_2);
      if ((((*piVar3 != 0) && (piVar3[0xd] != 0)) && (piVar3[0xe] != 0)) &&
         (bVar2 = xtra_isTextEngineReady(), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar4 = Ordinal_1157(piVar3[0xb]);
        iVar5 = Ordinal_1156(piVar3[0xb],iVar4,param_3);
        iVar1 = local_8;
        while (local_8 = iVar1, iVar5 != 0) {
          iVar6 = iVar6 + *(int *)(iVar5 + 8);
          if (param_4 == 0) {
            param_3 = param_3 + -1;
          }
          else {
            param_3 = param_3 + 1;
          }
          if (param_5 < iVar6) {
            local_8 = iVar1 + 1;
            if (piVar3[7] != 0) {
              local_8 = iVar1;
            }
            break;
          }
          iVar5 = Ordinal_1156(piVar3[0xb],iVar4,param_3);
          iVar1 = iVar1 + 1;
        }
        if (iVar4 != 0) {
          Ordinal_1158(piVar3[0xb],iVar4);
        }
      }
      Ordinal_1115(param_2);
      iVar6 = local_8;
    }
    Ordinal_1603(param_1);
  }
  return iVar6;
}



// ============================================================
// Function: xtra_countVisibleLines (xtra_countVisibleLines)
// Address: 68118d20
// Size: 200 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_countVisibleLines(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  iVar4 = 0;
  local_8 = 0;
  if (param_1 != 0) {
    Ordinal_1602(param_1);
    if (param_2 != 0) {
      piVar2 = (int *)Ordinal_1114(param_2);
      if ((((*piVar2 != 0) && (piVar2[0xd] != 0)) && (piVar2[0xe] != 0)) &&
         (bVar1 = xtra_isTextEngineReady(), CONCAT31(extraout_var,bVar1) != 0)) {
        local_c = 0;
        iVar3 = Ordinal_1157(piVar2[0xb]);
        iVar4 = Ordinal_1156(piVar2[0xb],iVar3,param_3);
        while ((iVar4 != 0 && (local_c = local_c + *(int *)(iVar4 + 8), local_c <= param_5))) {
          local_8 = local_8 + 1;
          if (param_4 == 0) {
            param_3 = param_3 + -1;
          }
          else {
            param_3 = param_3 + 1;
          }
          iVar4 = Ordinal_1156(piVar2[0xb],iVar3,param_3);
        }
        if (iVar3 != 0) {
          Ordinal_1158(piVar2[0xb],iVar3);
        }
      }
      Ordinal_1115(param_2);
      iVar4 = local_8;
    }
    Ordinal_1603(param_1);
  }
  return iVar4;
}



// ============================================================
// Function: xtra_setTextProperty (FUN_68118df0)
// Address: 68118df0
// Size: 215 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_setTextProperty(int param_1,int param_2,undefined4 param_3)
{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int local_2c;
  undefined1 local_28 [32];
  uint local_8;
  
  if (param_1 != 0) {
    if (param_2 != 0) {
      Ordinal_1602(param_1);
      piVar2 = (int *)Ordinal_1114(param_2);
      if ((((*piVar2 != 0) && (piVar2[0xd] != 0)) && (piVar2[0xe] != 0)) &&
         (bVar1 = xtra_isTextEngineReady(), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = Ordinal_1154(piVar2[0xb]);
        iVar4 = Ordinal_1165(piVar2[0xb],&local_2c,&param_3,xtra_compareLayoutPos,0);
        if (((iVar4 == 0) && (local_2c != 0)) && (local_2c == iVar3)) {
          Ordinal_1155(piVar2[0xb],local_2c + -1,local_28);
        }
      }
      Ordinal_1115(param_2);
    }
    Ordinal_1603(param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_setTextPropertyByChar (xtra_setTextPropertyByChar)
// Address: 68118ed0
// Size: 86 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_setTextPropertyByChar(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    puVar2 = (undefined4 *)Ordinal_1114(param_2);
    iVar3 = Ordinal_1114(*puVar2);
    uVar1 = xtra_charToByteOffset(iVar3,param_3);
    Ordinal_1115(*puVar2);
    uVar1 = xtra_setTextProperty(param_1,param_2,uVar1);
    Ordinal_1115(param_2);
  }
  return uVar1;
}



// ============================================================
// Function: xtra_hitTestTextPosition (xtra_hitTestTextPosition)
// Address: 68118f30
// Size: 684 bytes
// Params: int param_1, int param_2, int param_3, int param_4, uint * param_5, uint param_6, int param_7, int param_8
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_hitTestTextPosition(int param_1,int param_2,int param_3,int param_4,uint *param_5,uint param_6,
                int param_7,int param_8)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_24 [2];
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = -1;
  if (param_1 == 0) {
    return -1;
  }
  if (param_2 == 0) {
    return -1;
  }
  local_1c = Ordinal_1602(param_1);
  piVar2 = (int *)Ordinal_1114(param_2);
  if (((*piVar2 == 0) || (piVar2[0xd] == 0)) || (piVar2[0xe] == 0)) goto LAB_681191bc;
  if (param_7 == 0) {
    if (piVar2[0x3b] + param_4 < 0) {
      local_8 = 0;
      if (param_5 != (uint *)0x0) {
        *param_5 = 0;
      }
      goto LAB_681191bc;
    }
  }
  else if (((piVar2[0x3b] + param_4 < 0) || (param_3 < 0)) || (piVar2[2] < param_3))
  goto LAB_681191bc;
  bVar1 = xtra_isTextEngineReady();
  if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_681191bc;
  uVar5 = -(uint)(param_8 != 0) & param_6;
  local_10 = -piVar2[0x3b];
  local_14 = Ordinal_1157(piVar2[0xb]);
  piVar3 = (int *)Ordinal_1156(piVar2[0xb],local_14,uVar5);
  if (piVar3 == (int *)0x0) {
LAB_6811916b:
    if ((param_8 == 0) && (local_8 == -1)) goto LAB_68119177;
  }
  else {
    do {
      local_10 = local_10 + piVar3[2];
      if ((param_4 < local_10) || (param_8 != 0)) {
        local_c = uVar5;
        if (*piVar3 < param_3) {
          uVar5 = xtra_measureTextExtent(piVar3[4]);
          local_18 = uVar5;
          param_6 = xtra_fitTextToWidth(param_1,piVar2,piVar3[4],param_3 - *piVar3);
          if ((int)uVar5 < (int)param_6) {
            param_6 = uVar5;
          }
          if ((param_7 != 0) && ((int)(piVar3[4] + param_6) < piVar2[1])) {
            param_7 = 0;
            iVar4 = xtra_renderTextBlock(local_24,(int *)0x0,param_1,piVar2,piVar3[4],param_6);
            if (iVar4 == 0) goto LAB_681191bc;
            iVar6 = param_3 - local_24[0];
            iVar4 = Ordinal_1114(*piVar2);
            xtra_setTextRunAttr((int)piVar2,iVar4,&param_7);
            Ordinal_1115(*piVar2);
            iVar4 = xtra_renderTextBlock(local_24,(int *)0x0,param_1,piVar2,piVar3[4] + param_6,param_7);
            if (iVar4 == 0) goto LAB_681191bc;
            if ((local_24[0] / 2 < iVar6) &&
               (param_6 = param_6 + param_7, (int)local_18 < (int)param_6)) {
              param_6 = local_18;
            }
          }
        }
        else {
          param_6 = 0;
        }
        iVar4 = piVar3[4] + param_6;
        local_8 = piVar2[1];
        uVar5 = local_c;
        if ((iVar4 <= local_8) && (local_8 = iVar4, iVar4 < 0)) {
          local_8 = 0;
        }
        goto LAB_6811916b;
      }
      uVar5 = uVar5 + 1;
    } while ((piVar2[4] != 0) &&
            (piVar3 = (int *)Ordinal_1156(piVar2[0xb],local_14,uVar5), piVar3 != (int *)0x0));
LAB_68119177:
    if (local_10 <= param_4) {
      uVar5 = uVar5 - 1;
      iVar4 = Ordinal_1156(piVar2[0xb],local_14,uVar5);
      if (iVar4 != 0) {
        local_8 = piVar2[1];
      }
    }
  }
  if (local_14 != 0) {
    Ordinal_1158(piVar2[0xb],local_14);
  }
  if ((local_8 != -1) && (param_5 != (uint *)0x0)) {
    *param_5 = uVar5;
  }
LAB_681191bc:
  Ordinal_1115(param_2);
  if (local_1c != 0) {
    Ordinal_1603(param_1);
  }
  return local_8;
}



// ============================================================
// Function: xtra_layoutTextBlock (FUN_681191e0)
// Address: 681191e0
// Size: 115 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int * param_5, uint * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_layoutTextBlock(int param_1,int param_2,int param_3,int param_4,int *param_5,uint *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  iVar1 = xtra_hitTestTextPosition(param_1,param_2,param_3,param_4,param_6,0,0,0);
  if ((-1 < iVar1) && (puVar2 = (undefined4 *)Ordinal_1114(param_2), puVar2 != (undefined4 *)0x0)) {
    iVar3 = Ordinal_1114(*puVar2);
    local_8 = xtra_countTextChars(iVar3);
    Ordinal_1115(*puVar2);
    Ordinal_1115(param_2);
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar1;
  }
  return local_8;
}



// ============================================================
// Function: xtra_getCharPosition (xtra_getCharPosition)
// Address: 68119260
// Size: 432 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getCharPosition(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  uVar7 = 0;
  local_18 = 0;
  local_8 = 0;
  local_14 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = Ordinal_1602(param_1);
    piVar3 = (int *)Ordinal_1114(param_2);
    if (((*piVar3 != 0) && (((piVar3[0xd] != 0 && (piVar3[0xe] != 0)) && (param_3 <= piVar3[1]))))
       && (bVar1 = xtra_isTextEngineReady(), CONCAT31(extraout_var,bVar1) != 0)) {
      iVar8 = 0;
      local_10 = Ordinal_1157(piVar3[0xb]);
      iVar4 = Ordinal_1156(piVar3[0xb],local_10,0);
      iVar5 = local_18;
      while (local_18 = iVar5, iVar4 != 0) {
        iVar8 = iVar8 + *(int *)(iVar4 + 8);
        iVar6 = *(int *)(iVar4 + 0x18) + iVar5;
        if ((param_3 < iVar6) ||
           (((param_3 == iVar6 && (param_3 == piVar3[1])) &&
            (iVar6 = Ordinal_1156(piVar3[0xb],local_10,local_8 + 1), iVar6 == 0)))) {
          if (param_3 - iVar5 < 1) {
            param_3 = 1;
            iVar5 = Ordinal_1114(*piVar3);
            Ordinal_1252(*(int *)(iVar4 + 0x10) + iVar5,&param_3);
            if (iVar5 != 0) {
              Ordinal_1115(*piVar3);
            }
            iVar5 = xtra_renderTextBlock(&local_c,&local_18,param_1,piVar3,*(int *)(iVar4 + 0x10),param_3);
            if (iVar5 == 0) goto LAB_681193d9;
            local_c = 0;
          }
          else {
            iVar5 = xtra_renderTextBlock(&local_c,&local_18,param_1,piVar3,*(int *)(iVar4 + 0x10),
                                 param_3 - iVar5);
            if (iVar5 == 0) goto LAB_681193d9;
          }
          *param_4 = local_c;
          param_4[1] = (local_18 - *(int *)(iVar4 + 8)) + iVar8;
          break;
        }
        local_18 = iVar5 + *(int *)(iVar4 + 0x18);
        local_8 = local_8 + 1;
        iVar4 = Ordinal_1156(piVar3[0xb],local_10,local_8);
        iVar5 = local_18;
      }
      local_14 = 1;
LAB_681193d9:
      uVar7 = local_14;
      if (local_10 != 0) {
        Ordinal_1158(piVar3[0xb],local_10);
        uVar7 = local_14;
      }
    }
    Ordinal_1115(param_2);
    if (iVar2 != 0) {
      Ordinal_1603(param_1);
    }
  }
  return uVar7;
}



// ============================================================
// Function: xtra_getCharPositionByIndex (xtra_getCharPositionByIndex)
// Address: 68119410
// Size: 88 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getCharPositionByIndex(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    puVar2 = (undefined4 *)Ordinal_1114(param_2);
    iVar3 = Ordinal_1114(*puVar2);
    iVar3 = xtra_charToByteOffset(iVar3,param_3);
    Ordinal_1115(*puVar2);
    uVar1 = xtra_getCharPosition(param_1,param_2,iVar3,param_4);
    Ordinal_1115(param_2);
  }
  return uVar1;
}



// ============================================================
// Function: xtra_getLineYOffset (xtra_getLineYOffset)
// Address: 68119470
// Size: 208 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

int * xtra_getLineYOffset(int param_1,int param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_8;
  
  piVar6 = (int *)0x0;
  local_8 = 0;
  *param_4 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = Ordinal_1602(param_1);
    piVar3 = (int *)Ordinal_1114(param_2);
    if ((*piVar3 != 0) &&
       (((piVar3[0xd] != 0 && (piVar3[0xe] != 0)) &&
        (bVar1 = xtra_isTextEngineReady(), CONCAT31(extraout_var,bVar1) != 0)))) {
      iVar7 = 0;
      iVar4 = Ordinal_1157(piVar3[0xb]);
      iVar5 = Ordinal_1156(piVar3[0xb],iVar4,0);
      while (iVar5 != 0) {
        if (local_8 == param_3) {
          *param_4 = iVar7;
          break;
        }
        iVar7 = iVar7 + *(int *)(iVar5 + 8);
        local_8 = local_8 + 1;
        iVar5 = Ordinal_1156(piVar3[0xb],iVar4,local_8);
      }
      param_4 = (int *)0x1;
      piVar6 = param_4;
      if (iVar4 != 0) {
        Ordinal_1158(piVar3[0xb],iVar4);
      }
    }
    Ordinal_1115(param_2);
    if (iVar2 != 0) {
      Ordinal_1603(param_1);
    }
  }
  return piVar6;
}



// ============================================================
// Function: xtra_layoutTextRun (FUN_68119540)
// Address: 68119540
// Size: 42 bytes
// Params: int param_1, int param_2, int param_3, int param_4, uint * param_5, uint param_6, int param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_layoutTextRun(int param_1,int param_2,int param_3,int param_4,uint *param_5,uint param_6,
                 int param_7)
{
  xtra_hitTestTextPosition(param_1,param_2,param_3,param_4,param_5,param_6,1,param_7);
  return 0;
}



// ============================================================
// Function: xtra_buildSelectionRects (xtra_buildSelectionRects)
// Address: 68119570
// Size: 1239 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_buildSelectionRects(int param_1,int *param_2,int param_3,int param_4,int *param_5,int param_6)
{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_88 [2];
  int local_80 [2];
  int local_78;
  int local_74;
  int *local_70;
  int *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  uint local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
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
  
  local_54 = param_1;
  local_6c = param_2;
  local_70 = param_5;
  local_40 = 0;
  local_5c = 0;
  local_48 = 0;
  local_4c = 0;
  if (param_1 != 0) {
    Ordinal_1602(param_1);
    if (param_2 != (int *)0x0) {
      piVar2 = (int *)Ordinal_1114(param_2);
      local_3c = piVar2;
      if (((*piVar2 != 0) && (piVar2[0xd] != 0)) && (piVar2[0xe] != 0)) {
        if ((param_4 < 0) || (piVar2[1] < param_3 + param_4)) {
          param_4 = piVar2[1] - param_3;
        }
        if ((-1 < param_4) && (local_70 != (int *)0x0)) {
          local_48 = Ordinal_1150(10,10,0x10);
          bVar1 = xtra_isTextEngineReady();
          param_1 = local_54;
          if (CONCAT31(extraout_var,bVar1) != 0) {
            if (param_3 < piVar2[1]) {
              local_44 = 0;
              iVar3 = Ordinal_1154(piVar2[0xb]);
              local_64 = -piVar2[0x3b];
              local_68 = 0;
              local_74 = 0;
              local_78 = iVar3;
              local_50 = Ordinal_1157(piVar2[0xb]);
              if (0 < iVar3) {
                while (piVar4 = (int *)Ordinal_1156(piVar2[0xb],local_50,local_44),
                      piVar2 = local_3c, piVar4 != (int *)0x0) {
                  local_60 = piVar4[6];
                  iVar3 = piVar4[4];
                  local_58 = (uint)(iVar3 + local_60 == local_3c[1]);
                  if ((local_60 == 0) && (piVar4[5] == 0)) {
                    local_44 = local_44 + -1;
                    if ((local_44 < 0) ||
                       (piVar4 = (int *)Ordinal_1156(local_3c[0xb],local_50,local_44),
                       piVar4 == (int *)0x0)) break;
                    if (param_3 < 0) {
                      local_44 = local_44 + 1;
                    }
                    local_60 = piVar4[5];
                    iVar3 = piVar4[4];
                    local_64 = local_64 - piVar4[2];
                    param_3 = local_60 + iVar3;
                  }
                  iVar5 = local_64 + piVar4[2];
                  local_64 = iVar5;
                  if (local_4c == 0) {
                    if ((iVar3 <= param_3) && ((param_3 < iVar3 + local_60 || (local_58 != 0)))) {
                      iVar3 = xtra_renderTextBlock(local_80,(int *)0x0,local_54,local_3c,piVar4[4],
                                           param_3 - piVar4[4]);
                      piVar2 = local_3c;
                      if (iVar3 == 0) break;
                      local_28 = *piVar4 + local_80[0];
                      local_20 = piVar4[1] + *piVar4;
                      local_24 = iVar5 - piVar4[2];
                      if (param_6 != 0) {
                        if (param_3 <= piVar4[4]) {
                          local_28 = 0;
                        }
                        local_20 = local_3c[2];
                      }
                      local_68 = local_44;
                      local_4c = 1;
                      local_1c = iVar5;
LAB_68119880:
                      iVar3 = param_3 + param_4;
                      if ((iVar3 < piVar4[4]) || ((piVar4[4] + local_60 < iVar3 && (local_58 == 0)))
                         ) {
                        if (local_68 != local_44) {
                          if (param_6 == 0) {
                            local_18 = *piVar4;
                            local_10 = piVar4[1] + local_18;
                          }
                          else {
                            local_10 = local_3c[2];
                            local_18 = 0;
                          }
                          local_14 = iVar5 - piVar4[2];
                          local_c = iVar5;
                          iVar3 = Ordinal_1152(local_48,&local_18);
                          piVar2 = local_3c;
                          if (iVar3 == 0) break;
                          local_40 = local_40 + 1;
                        }
                      }
                      else {
                        iVar6 = xtra_renderTextBlock(local_88,(int *)0x0,local_54,local_3c,piVar4[4],
                                             iVar3 - piVar4[4]);
                        piVar2 = local_3c;
                        if (iVar6 == 0) break;
                        local_38 = *piVar4;
                        local_30 = *piVar4 + local_88[0];
                        local_34 = iVar5 - piVar4[2];
                        if (param_6 != 0) {
                          if (piVar4[5] + piVar4[4] < iVar3) {
                            local_30 = local_3c[2];
                          }
                          local_38 = 0;
                        }
                        local_74 = local_44;
                        local_4c = 2;
                        local_2c = iVar5;
                      }
                    }
                  }
                  else if (local_4c == 1) goto LAB_68119880;
                  piVar2 = local_3c;
                  if (local_3c[4] == 0) {
                    if (local_4c != 0) {
                      if (local_4c != 1) goto LAB_681199a8;
                      local_38 = local_28;
                      local_34 = local_24;
                      local_30 = local_20;
                      local_2c = local_1c;
LAB_681199b0:
                      iVar3 = Ordinal_1066(&local_18,&local_28,&local_38);
                      if (iVar3 == 0) {
                        local_10 = local_10 + 1;
                      }
                      iVar3 = Ordinal_1152(local_48,&local_18);
                      piVar2 = local_3c;
                      if (iVar3 != 0) {
                        local_40 = local_40 + 1;
                        goto LAB_681196b9;
                      }
                    }
                    break;
                  }
                  if (local_4c == 2) {
LAB_681199a8:
                    if (local_68 == local_74) goto LAB_681199b0;
                    iVar3 = Ordinal_1152(local_48,&local_28);
                    piVar2 = local_3c;
                    if ((iVar3 != 0) &&
                       (iVar3 = Ordinal_1152(local_48,&local_38), piVar2 = local_3c, iVar3 != 0)) {
                      local_40 = local_40 + 2;
                      goto LAB_681196b9;
                    }
                    break;
                  }
                  local_44 = local_44 + 1;
                  if (local_78 <= local_44) break;
                }
              }
            }
            else {
              iVar3 = Ordinal_1154(piVar2[0xb]);
              iVar5 = -piVar2[0x3b];
              local_50 = Ordinal_1157(local_3c[0xb]);
              piVar4 = local_6c;
              if (0 < iVar3) {
                iVar6 = 0;
                do {
                  piVar4 = (int *)Ordinal_1156(local_3c[0xb],local_50,iVar6);
                  piVar2 = local_3c;
                  if (piVar4 == (int *)0x0) goto LAB_681196c3;
                  iVar5 = iVar5 + piVar4[2];
                  iVar6 = iVar6 + 1;
                } while (iVar6 < iVar3);
              }
              if (iVar5 < 1) {
                local_40 = 0;
              }
              else {
                local_18 = piVar4[1] + *piVar4;
                local_10 = local_18 + 1;
                local_14 = iVar5 - piVar4[2];
                local_c = iVar5;
                iVar3 = Ordinal_1152(local_48,&local_18);
                piVar2 = local_3c;
                if (iVar3 == 0) goto LAB_681196c3;
                local_40 = 1;
              }
LAB_681196b9:
              local_5c = 1;
              piVar2 = local_3c;
            }
LAB_681196c3:
            param_1 = local_54;
            if (local_50 != 0) {
              Ordinal_1158(piVar2[0xb],local_50);
              param_1 = local_54;
            }
          }
        }
      }
      Ordinal_1115(local_6c);
      param_5 = local_70;
    }
    Ordinal_1603(param_1);
    if (local_5c != 0) goto LAB_68119a28;
    if (local_48 != 0) {
      Ordinal_1163(&local_48);
    }
  }
  local_40 = 0;
LAB_68119a28:
  if (param_5 != (int *)0x0) {
    *param_5 = local_48;
  }
  return 0;
}



// ============================================================
// Function: xtra_processTextRun (FUN_68119a50)
// Address: 68119a50
// Size: 383 bytes
// Params: int param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_processTextRun(int param_1,int *param_2,int param_3,int *param_4)
{
  int iVar1;
  int *piVar2;
  int local_bc;
  int *local_b8;
  int local_b4;
  int local_b0;
  undefined4 local_ac [41];
  uint local_8;
  
  local_b4 = 0;
  local_b0 = 0;
  local_b8 = (int *)0x0;
  local_bc = 0;
  iVar1 = xtra_getBufferSize((int)param_2);
  if (iVar1 == 0) {
    local_bc = CONCAT22((*(unsigned short *)((char *)&local_bc + 2)),0x20);
    xtra_appendToBuffer((int)param_2,local_ac,0);
    xtra_replaceBufferRange((int)param_2,(int)&local_bc,1,local_ac);
    local_bc = 1;
  }
  iVar1 = xtra_buildSelectionRects(param_1,param_2,param_3,0,&local_b0,0);
  piVar2 = local_b8;
  if (((iVar1 == 1) &&
      (local_b8 = (int *)Ordinal_1157(local_b0), piVar2 = (int *)0x0, local_b8 != (int *)0x0)) &&
     (piVar2 = (int *)Ordinal_1156(local_b0,local_b8,0), piVar2 != (int *)0x0)) {
    if (piVar2[2] <= *piVar2) {
      piVar2[2] = *piVar2 + 1;
    }
    iVar1 = *(int *)(*param_2 + 8);
    if (iVar1 < piVar2[2]) {
      piVar2[2] = iVar1;
      *piVar2 = iVar1 + -1;
    }
    local_b4 = 1;
  }
  if (local_bc != 0) {
    xtra_deleteBufferRange((int)param_2,0,1);
  }
  if (local_b4 == 0) {
    if (param_4 == (int *)0x0) goto LAB_68119b8a;
    iVar1 = -1;
    *param_4 = -1;
    param_4[1] = -1;
    param_4[2] = -1;
  }
  else {
    if (param_4 == (int *)0x0) goto LAB_68119b8a;
    *param_4 = *piVar2;
    param_4[1] = piVar2[1];
    param_4[2] = piVar2[2];
    iVar1 = piVar2[3];
  }
  param_4[3] = iVar1;
LAB_68119b8a:
  if (local_b8 != (int *)0x0) {
    Ordinal_1158(local_b0,local_b8);
  }
  if (local_b0 != 0) {
    Ordinal_1163(&local_b0);
  }
  return 0;
}



// ============================================================
// Function: xtra_getVisibleLineCount (xtra_getVisibleLineCount)
// Address: 68119bd0
// Size: 130 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_getVisibleLineCount(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_2 != 0) {
    iVar2 = Ordinal_1114(param_2);
    bVar1 = xtra_isTextEngineReady();
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (iVar2 == 0) {
        return 0;
      }
      if (((*(int *)(iVar2 + 0x2c) != 0) &&
          (iVar5 = Ordinal_1154(*(int *)(iVar2 + 0x2c)), iVar5 != 0)) &&
         (iVar3 = Ordinal_1157(*(undefined4 *)(iVar2 + 0x2c)), iVar3 != 0)) {
        iVar4 = Ordinal_1156(*(undefined4 *)(iVar2 + 0x2c),iVar3,iVar5 + -1);
        if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) == 0)) {
          iVar5 = iVar5 + -1;
        }
        Ordinal_1158(*(undefined4 *)(iVar2 + 0x2c),iVar3);
      }
    }
    if (iVar2 != 0) {
      Ordinal_1115(param_2);
    }
  }
  return iVar5;
}



// ============================================================
// Function: xtra_trimString (FUN_68119c60)
// Address: 68119c60
// Size: 64 bytes
// Params: char * param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * xtra_trimString(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint extraout_EDX;
  char *pcVar3;
  
  cVar1 = *param_1;
  pcVar3 = param_1;
  while ((cVar1 != '\0' && (cVar1 != '\r'))) {
    uVar2 = Ordinal_1252(pcVar3,&param_1);
    Ordinal_1253(uVar2);
    if ((extraout_EDX & 0x20000000) == 0) {
      return pcVar3;
    }
    pcVar3 = pcVar3 + (int)param_1;
    cVar1 = *pcVar3;
  }
  return pcVar3;
}



// ============================================================
// Function: xtra_trimStringRight (FUN_68119ca0)
// Address: 68119ca0
// Size: 89 bytes
// Params: char * param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * xtra_trimStringRight(char *param_1)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  if (*param_1 != '\0') {
    while (iVar1 = Ordinal_1252(pcVar2,&param_1), iVar1 != 0xd) {
      iVar1 = Ordinal_1252(pcVar2,&param_1);
      pcVar2 = pcVar2 + (int)param_1;
      if (iVar1 == 10) {
        return pcVar2;
      }
      if (*pcVar2 == '\0') {
        return pcVar2;
      }
    }
    pcVar2 = pcVar2 + (int)param_1;
    iVar1 = Ordinal_1252(pcVar2,&param_1);
    if (iVar1 == 10) {
      pcVar2 = pcVar2 + (int)param_1;
    }
  }
  return pcVar2;
}



// ============================================================
// Function: xtra_parseTextFormat (FUN_68119d00)
// Address: 68119d00
// Size: 35 bytes
// Params: char * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_parseTextFormat(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (((cVar1 != '\0') && (cVar1 != '\r')) && (cVar1 != '\n')) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: xtra_setTextFormat (FUN_68119d30)
// Address: 68119d30
// Size: 89 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_setTextFormat(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1;
  iVar3 = 0;
  iVar2 = Ordinal_1252(param_1,&param_1);
  if (iVar2 != 0) {
    iVar3 = Ordinal_1252(iVar1 + param_1,&param_1);
  }
  if ((((param_2 == 0) || (iVar2 != 0x2d)) || (iVar3 != 0x2d)) &&
     ((param_3 == 0 || (iVar2 != 0x3b)))) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: xtra_scanTextDelimiters (xtra_scanTextDelimiters)
// Address: 68119d90
// Size: 219 bytes
// Params: char * param_1, int param_2, int param_3
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * xtra_scanTextDelimiters(char *param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  uint extraout_EDX;
  char *pcVar6;
  
  pcVar5 = param_1;
  do {
    iVar2 = Ordinal_1252(pcVar5,&param_1);
    pcVar6 = pcVar5;
    while (((iVar2 != 0 && (iVar2 != 0xd)) &&
           (Ordinal_1253(iVar2), (extraout_EDX & 0x20000000) != 0))) {
      pcVar6 = pcVar6 + (int)param_1;
      iVar2 = Ordinal_1252(pcVar6,&param_1);
    }
    uVar3 = Ordinal_1201(";$!$:");
    sVar1 = Ordinal_1207(pcVar6,";$!$:",uVar3);
    if (sVar1 == 0) {
      iVar2 = Ordinal_1201(";$!$:");
      pcVar5 = xtra_trimString(pcVar6 + iVar2);
      return pcVar5;
    }
    if ((iVar2 == 0xd) || (iVar2 == 0)) {
      iVar4 = 0;
    }
    else {
      pcVar6 = pcVar6 + (int)param_1;
      iVar4 = Ordinal_1252(pcVar6,&param_1);
    }
    if (((param_2 == 0) || (iVar2 != 0x2d)) || (iVar4 != 0x2d)) {
      if (((param_3 == 0) || (iVar2 != 0x3b)) && (iVar2 != 0xd)) {
        return pcVar5;
      }
      if ((iVar2 == 0x2d) && (iVar4 == 0x2d)) goto LAB_68119e39;
    }
    else {
LAB_68119e39:
      pcVar6 = pcVar6 + (int)param_1;
    }
    pcVar5 = xtra_trimStringRight(pcVar6);
  } while( true );
}



// ============================================================
// Function: xtra_trimTrailingWhitespace (xtra_trimTrailingWhitespace)
// Address: 68119e70
// Size: 113 bytes
// Params: char * param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * xtra_trimTrailingWhitespace(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint extraout_EDX;
  char *pcVar5;
  
  pcVar2 = param_1;
  pcVar4 = param_1;
  pcVar5 = param_1;
  if (*param_1 != '\0') {
    do {
      uVar3 = Ordinal_1252(pcVar4,&param_1);
      Ordinal_1253(uVar3);
      if ((extraout_EDX & 0x20000000) == 0) {
        pcVar4 = pcVar4 + (int)param_1;
        pcVar5 = pcVar4;
      }
      else {
        pcVar4 = xtra_trimString(pcVar4);
        cVar1 = *pcVar4;
        while (cVar1 == '\r') {
          pcVar4 = xtra_trimString(pcVar4 + 1);
          cVar1 = *pcVar4;
        }
      }
    } while (*pcVar4 != '\0');
    if (pcVar5 != pcVar2) {
      *pcVar5 = '\0';
      return pcVar5 + 1;
    }
  }
  return pcVar5;
}



// ============================================================
// Function: xtra_comparePositions (xtra_comparePositions)
// Address: 68119ef0
// Size: 42 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_comparePositions(int *param_1,int *param_2)

{
  if (*param_2 < *param_1) {
    return 1;
  }
  return (int)(short)((*param_2 <= *param_1) - 1);
}



// ============================================================
// Function: xtra_compareFontPriority (xtra_compareFontPriority)
// Address: 68119f20
// Size: 50 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_compareFontPriority(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x9c) < *(int *)(param_1 + 0x9c)) {
    return 1;
  }
  return (int)(short)((*(int *)(param_2 + 0x9c) <= *(int *)(param_1 + 0x9c)) - 1);
}



// ============================================================
// Function: xtra_renderTextLine (FUN_68119f60)
// Address: 68119f60
// Size: 132 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_renderTextLine(undefined4 param_1,int param_2,int param_3,int param_4)
{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    if (param_4 != 0) {
      xtra_updateTextLayout(unaff_ESI,0,0,0,1);
      return 0;
    }
    if (param_2 != 0) {
      if (*(int *)(unaff_ESI + 4) < in_EAX) {
        in_EAX = *(int *)(unaff_ESI + 4);
      }
      if (*(int *)(unaff_ESI + 0xe8) == 0) {
        *(int *)(unaff_ESI + 0xe4) = in_EAX;
        *(undefined4 *)(unaff_ESI + 0xe8) = 1;
      }
      else {
        iVar1 = *(int *)(unaff_ESI + 0xe4);
        if (in_EAX < *(int *)(unaff_ESI + 0xe4)) {
          iVar1 = in_EAX;
        }
        *(int *)(unaff_ESI + 0xe4) = iVar1;
      }
      iVar1 = xtra_updateTextLayout(unaff_ESI,in_EAX,param_2,param_3,0);
      if (iVar1 == 0) {
        xtra_updateTextLayout(unaff_ESI,0,0,0,1);
        *(undefined4 *)(unaff_ESI + 0xe8) = 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_getTextData (FUN_68119ff0)
// Address: 68119ff0
// Size: 301 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_getTextData(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_8;
  
  local_8 = -1;
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar2 = Ordinal_1150(10,10,0xa4);
    *(int *)(param_1 + 0x38) = iVar2;
    if (iVar2 == 0) {
      return -1;
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  Ordinal_1702(param_2);
  iVar3 = Ordinal_1154(*(undefined4 *)(param_1 + 0x38));
  uVar4 = Ordinal_1157(*(undefined4 *)(param_1 + 0x38));
  iVar2 = iVar3;
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) goto LAB_6811a0b4;
    iVar5 = Ordinal_1156(*(undefined4 *)(param_1 + 0x38),uVar4,iVar2);
  } while ((((*(int *)(iVar5 + 0x50) != param_2[0x14]) || (*(int *)(iVar5 + 0x40) != param_2[0x10]))
           || (*(char *)(iVar5 + 0x4c) != *(char *)(param_2 + 0x13))) ||
          (((*(char *)(iVar5 + 0x4d) != *(char *)((int)param_2 + 0x4d) ||
            (*(char *)(iVar5 + 0x4e) != *(char *)((int)param_2 + 0x4e))) ||
           (sVar1 = Ordinal_1208(iVar5,param_2), sVar1 != 0))));
  local_8 = *(int *)(iVar5 + 0x9c);
  *(int *)(iVar5 + 0xa0) = *(int *)(iVar5 + 0xa0) + 1;
LAB_6811a0b4:
  Ordinal_1158(*(undefined4 *)(param_1 + 0x38),uVar4);
  if (local_8 == -1) {
    param_2[0x28] = 1;
    param_2[0x27] = *(int *)(param_1 + 0x3c) + 1;
    iVar2 = Ordinal_1152(*(undefined4 *)(param_1 + 0x38),param_2);
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      local_8 = param_2[0x27];
    }
  }
  if (iVar3 == 0) {
    puVar6 = (undefined4 *)(param_1 + 0x40);
    for (iVar2 = 0x29; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *param_2;
      param_2 = param_2 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  return local_8;
}



// ============================================================
// Function: xtra_lookupFontEntry (xtra_lookupFontEntry)
// Address: 6811a120
// Size: 81 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_lookupFontEntry(undefined4 *param_1,int param_2)
{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_8;
  
  if (param_1 != (undefined4 *)0x0) {
    param_1[0x27] = in_EAX;
    local_8 = param_1;
    iVar1 = Ordinal_1165(*(undefined4 *)(param_2 + 0x38),&local_8,param_1,xtra_compareFontPriority,0);
    if (iVar1 != 0) {
      Ordinal_1155(*(undefined4 *)(param_2 + 0x38),local_8,param_1);
      return 0;
    }
    puVar2 = (undefined4 *)(param_2 + 0x40);
    for (iVar1 = 0x29; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_addFontRef (xtra_addFontRef)
// Address: 6811a180
// Size: 121 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_addFontRef(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 local_b0;
  undefined1 local_ac [156];
  undefined4 local_10;
  uint local_8;
  
  local_10 = param_1;
  iVar1 = Ordinal_1165(*(undefined4 *)(unaff_ESI + 0x38),&local_b0,local_ac,xtra_compareFontPriority,0);
  if (iVar1 != 0) {
    uVar2 = Ordinal_1157(*(undefined4 *)(unaff_ESI + 0x38));
    iVar1 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x38),uVar2,local_b0);
    *(int *)(iVar1 + 0xa0) = *(int *)(iVar1 + 0xa0) + 1;
    Ordinal_1158(*(undefined4 *)(unaff_ESI + 0x38),uVar2);
  }
  return 0;
}



// ============================================================
// Function: xtra_releaseFontRef (xtra_releaseFontRef)
// Address: 6811a200
// Size: 218 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_releaseFontRef(undefined4 param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  undefined4 local_b0;
  undefined1 local_ac [156];
  undefined4 local_10;
  uint local_8;
  
  local_10 = param_1;
  iVar2 = Ordinal_1165(*(undefined4 *)(unaff_ESI + 0x38),&local_b0,local_ac,xtra_compareFontPriority,0);
  if (iVar2 != 0) {
    uVar3 = Ordinal_1157(*(undefined4 *)(unaff_ESI + 0x38));
    iVar2 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x38),uVar3,local_b0);
    piVar1 = (int *)(iVar2 + 0xa0);
    *piVar1 = *piVar1 + -1;
    iVar2 = *piVar1;
    Ordinal_1158(*(undefined4 *)(unaff_ESI + 0x38),uVar3);
    if (iVar2 == 0) {
      Ordinal_1160(*(undefined4 *)(unaff_ESI + 0x38),local_b0);
      iVar2 = Ordinal_1154(*(undefined4 *)(unaff_ESI + 0x38));
      if (iVar2 == 1) {
        Ordinal_1155(*(undefined4 *)(unaff_ESI + 0x38),0,unaff_ESI + 0x40);
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_resolveFontData (xtra_resolveFontData)
// Address: 6811a2e0
// Size: 62 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_resolveFontData(undefined4 param_1,int param_2)
{
  int unaff_ESI;
  undefined4 local_ac [41];
  uint local_8;
  
  xtra_lookupFontEntry(local_ac,param_2);
  xtra_getTextData(unaff_ESI,local_ac);
  return 0;
}



