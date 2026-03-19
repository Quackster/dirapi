// Module: props
// Topic: Tokenizer, lexer, and parser functions
// Address range: 0x68039320 - 0x68039f10
// Functions (22):
//   props_consumeLine
//   props_parseTokenList
//   props_parseQuotedString
//   props_resetParserPosition
//   props_isParserReady
//   props_parseToken
//   props_parseIdentifier
//   props_saveParserState
//   props_restoreParserState
//   props_getCurrentToken
//   props_extractWordToken
//   props_parseExpression
//   props_parseQuotedValue
//   props_resolveTokenValue
//   props_resolveTokenSafe
//   props_setParserState
//   props_pushTokenEntry
//   props_parseBlock
//   props_peekNextToken
//   props_skipMatchingBlock
//   props_peekNextOffset
//   props_formatHexValue



// ============================================================
// Function: props_consumeLine (FUN_68039320)
// Address: 68039320
// Size: 128 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_consumeLine(void)
{
  undefined4 *in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_EBX;
  int local_8;
  
  iVar1 = props_getExtValue(&local_8);
  if (iVar1 == 0) {
LAB_68039391:
    in_EAX[0x10d] = 0;
    return 0;
  }
  do {
    iVar1 = local_8;
    if (((((local_8 == 0xc2) || (local_8 == 0xac)) &&
         (uVar2 = events_getScoreProperty(unaff_EBX), uVar2 < 0x850)) || (iVar1 == *(int *)(unaff_EBX + 0xd8)))
       && (iVar3 = props_dispatchExtMethod(unaff_EBX,in_EAX,0xd), iVar3 != 0)) {
      in_EAX[5] = in_EAX[5] + 1;
    }
    else if (iVar1 == 0xd) {
      in_EAX[5] = in_EAX[5] + 1;
      goto LAB_68039391;
    }
    iVar1 = props_getExtValue(&local_8);
    if (iVar1 == 0) {
      in_EAX[0x10d] = 0;
      return 0;
    }
  } while( true );
}



// ============================================================
// Function: props_parseTokenList (FUN_680393a0)
// Address: 680393a0
// Size: 700 bytes
// Params: int param_1, undefined4 * param_2, byte * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseTokenList(int param_1,undefined4 *param_2,byte *param_3,int *param_4)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_EDX;
  uint uVar5;
  undefined8 uVar6;
  int local_10;
  int local_c;
  int local_8;
  
  uVar5 = 0;
  param_3[0] = 0;
  param_3[1] = 0;
  local_10 = 0;
  *param_4 = 0;
  local_c = 0;
  iVar2 = props_getExtValue(&local_8);
  iVar4 = local_8;
  while (local_8 = iVar4, iVar2 != 0) {
    if (((((iVar4 == 0xc2) || (iVar4 == 0xac)) && (uVar3 = events_getScoreProperty(param_1), uVar3 < 0x850)) ||
        (iVar4 == *(int *)(param_1 + 0xd8))) &&
       (iVar2 = props_dispatchExtMethod(param_1,param_2,0xd), iVar2 != 0)) {
      param_2[5] = param_2[5] + 1;
    }
    else {
      uVar6 = stage_endParseScope();
      local_10 = (int)uVar6;
      uVar5 = (uint)((longlong)uVar6 >> 0x30);
      if ((uVar5 & 0x2000) == 0) goto LAB_68039450;
    }
    iVar2 = props_getExtValue(&local_8);
    iVar4 = local_8;
  }
  if ((int)param_2[3] < 1) goto LAB_6803947b;
LAB_68039450:
  if (iVar4 != 0xd) {
    if ((iVar4 != 0x2d) || (iVar4 = props_dispatchExtMethod(param_1,param_2,0x2d), iVar4 == 0)) {
      if ((uVar5 & 0x4000) != 0) {
        *param_4 = *param_4 + 1;
        local_c = 1;
      }
      stage_endDateScope();
      if ((uVar5 & 0x8000) != 0) goto LAB_6803947b;
      if (local_10 == *(int *)(param_1 + 0xd4)) {
        iVar4 = props_getExtValue(&local_8);
        if (iVar4 == 0) goto LAB_6803947b;
        uVar6 = stage_endParseScope();
        if (((int)uVar6 == *(int *)(param_1 + 0xd4)) && (-1 < *(int *)(param_1 + 0xd4))) {
          stage_endDateScope();
          goto LAB_6803947b;
        }
        props_advanceParserOffset();
        if (((uint)((longlong)uVar6 >> 0x30) & 0x4000) == 0) goto LAB_6803947b;
      }
      iVar2 = props_getExtValue(&local_8);
      iVar4 = local_8;
      while (iVar2 != 0) {
        local_8 = iVar4;
        if (((((iVar4 == 0xc2) || (iVar4 == 0xac)) && (uVar5 = events_getScoreProperty(param_1), uVar5 < 0x850)
             ) || (iVar4 == *(int *)(param_1 + 0xd8))) &&
           (iVar2 = props_dispatchExtMethod(param_1,param_2,0xd), iVar2 != 0)) {
          param_2[5] = param_2[5] + 1;
        }
        else {
          stage_endParseScope();
          if ((extraout_EDX >> 0x10 & 0xb000U) == 0) {
            if (iVar4 == *(int *)(param_1 + 0xd4)) {
              if (local_c == 0) goto LAB_68039476;
              iVar4 = props_getExtValue(&local_10);
              if (iVar4 != 0) {
                if (local_10 == *(int *)(param_1 + 0xd4)) goto LAB_68039471;
                props_advanceParserOffset();
              }
            }
          }
          else {
            if (((iVar4 != 0x2d) && (iVar4 != 0x2b)) || (local_c == 0)) goto LAB_68039476;
            if (*param_3 == 0xff) {
              uVar1 = Ordinal_1201(param_3 + 1);
            }
            else {
              uVar1 = (ushort)*param_3;
            }
            if (param_3[(short)uVar1] != 0x65) goto LAB_68039476;
          }
          if ((extraout_EDX >> 0x10 & 0x4000U) != 0) {
            *param_4 = *param_4 + 1;
          }
          stage_endDateScope();
        }
        iVar2 = props_getExtValue(&local_8);
        iVar4 = local_8;
      }
      goto LAB_6803947b;
    }
LAB_68039471:
    props_advanceParserOffset();
  }
LAB_68039476:
  props_advanceParserOffset();
LAB_6803947b:
  if (*param_3 != 0xff) {
    param_3[*param_3 + 1] = 0;
    return 0;
  }
  iVar4 = Ordinal_1201(param_3 + 1);
  param_3[iVar4 + 1] = 0;
  return 0;
}



// ============================================================
// Function: props_parseQuotedString (FUN_68039670)
// Address: 68039670
// Size: 280 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseQuotedString(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *in_EAX;
  int iVar2;
  uint uVar3;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)cast_allocHandle(0,0);
  iVar2 = props_getExtValue(&local_10);
  iVar1 = local_10;
  while (iVar2 != 0) {
    if (iVar1 == 0x22) {
      local_c = *(int *)*in_EAX + -1 + in_EAX[1];
      props_appendStringRange(&local_c,(int *)*in_EAX,1);
      goto LAB_6803974d;
    }
    local_10 = iVar1;
    if (((((iVar1 == 0xc2) || (iVar1 == 0xac)) && (uVar3 = events_getScoreProperty(param_1), uVar3 < 0x850)) ||
        (iVar1 == *(int *)(param_1 + 0xd8))) &&
       (iVar2 = props_dispatchExtMethod(param_1,in_EAX,0xd), iVar2 != 0)) {
      in_EAX[5] = in_EAX[5] + 1;
      local_c = *(int *)*in_EAX + -2 + in_EAX[1];
      props_appendStringRange(&local_c,(int *)*in_EAX,0);
    }
    else if ((*(int *)(**(int **)(param_1 + 8) + 0x4d8) == 0) && (iVar1 == 0xd)) break;
    iVar2 = props_getExtValue(&local_10);
    iVar1 = local_10;
  }
  stage_emitPushLiteral(param_1,0x1e);
  Ordinal_1113(&local_8);
LAB_6803974d:
  props_getValuePair(param_1,local_8,param_2);
  return 0;
}



// ============================================================
// Function: props_resetParserPosition (FUN_68039790)
// Address: 68039790
// Size: 39 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resetParserPosition(int param_1,int param_2)
{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + (*(int *)(param_1 + 4) - param_2);
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0x434) = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return 0;
}



// ============================================================
// Function: props_isParserReady (FUN_680397c0)
// Address: 680397c0
// Size: 18 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool props_isParserReady(int param_1)

{
  return *(int *)(param_1 + 0xc) < 1;
}



// ============================================================
// Function: props_parseToken (FUN_680397e0)
// Address: 680397e0
// Size: 50 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseToken(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  param_1[0x10d] = 0;
  *param_1 = param_2;
  uVar1 = Ordinal_1116(param_2);
  param_1[3] = uVar1;
  param_1[1] = 0;
  param_1[5] = 0;
  return 0;
}



// ============================================================
// Function: props_parseIdentifier (FUN_68039850)
// Address: 68039850
// Size: 70 bytes
// Params: int * param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseIdentifier(int *param_1,byte *param_2)
{
  ushort uVar1;
  
  param_1[0x10d] = 0;
  *param_1 = (int)(param_1 + 2);
  param_1[2] = (int)(param_2 + 1);
  if (*param_2 == 0xff) {
    uVar1 = Ordinal_1201(param_2 + 1);
  }
  else {
    uVar1 = (ushort)*param_2;
  }
  param_1[3] = (int)(short)uVar1;
  param_1[1] = 0;
  param_1[5] = 0;
  return 0;
}



// ============================================================
// Function: props_saveParserState (FUN_680398a0)
// Address: 680398a0
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_saveParserState(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  *(int *)(param_1 + 0x458) = *(int *)(param_1 + 0x434);
  if (0 < *(int *)(param_1 + 0x434)) {
    puVar1 = (undefined4 *)(param_1 + 0x440);
    do {
      *puVar1 = puVar1[-9];
      puVar1[1] = puVar1[-8];
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 2;
    } while (iVar2 < *(int *)(param_1 + 0x434));
  }
  *(undefined4 *)(param_1 + 0x438) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x43c) = *(undefined4 *)(param_1 + 0x14);
  return 0;
}



// ============================================================
// Function: props_restoreParserState (FUN_680398f0)
// Address: 680398f0
// Size: 92 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_restoreParserState(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  *(int *)(param_1 + 4) =
       *(int *)(param_1 + 4) + (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x438));
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0x438);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x43c);
  iVar2 = 0;
  *(int *)(param_1 + 0x434) = *(int *)(param_1 + 0x458);
  if (0 < *(int *)(param_1 + 0x458)) {
    puVar1 = (undefined4 *)(param_1 + 0x41c);
    do {
      *puVar1 = puVar1[9];
      puVar1[1] = puVar1[10];
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 2;
    } while (iVar2 < *(int *)(param_1 + 0x434));
  }
  return 0;
}



// ============================================================
// Function: props_getCurrentToken (FUN_68039950)
// Address: 68039950
// Size: 20 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getCurrentToken(void)
{
  props_consumeLine();
  return 0;
}



// ============================================================
// Function: props_extractWordToken (FUN_68039970)
// Address: 68039970
// Size: 259 bytes
// Params: int param_1, undefined4 * param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_extractWordToken(int param_1,undefined4 *param_2,undefined1 *param_3)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int local_8;
  
  pbVar5 = (byte *)(*(int *)*param_2 + param_2[1]);
  iVar6 = param_2[3];
  local_8 = 0;
  if (0 < iVar6) {
    do {
      if ((*(uint *)(**(int **)(param_1 + 8) + 0x14 + (uint)*pbVar5 * 4) & 0x2000) == 0)
      goto joined_r0x680399ba;
      iVar6 = iVar6 + -1;
      pbVar5 = pbVar5 + 1;
    } while (0 < iVar6);
  }
LAB_68039a38:
  param_3[local_8 + 1] = 0;
  if (0xfe < local_8) {
    *param_3 = 0xff;
    iVar3 = *(int *)*param_2;
    param_2[3] = iVar6;
    param_2[1] = (int)pbVar5 - iVar3;
    return 0;
  }
  *param_3 = (char)local_8;
  iVar3 = *(int *)*param_2;
  param_2[3] = iVar6;
  param_2[1] = (int)pbVar5 - iVar3;
  return 0;
joined_r0x680399ba:
  if (iVar6 < 1) goto LAB_68039a38;
  bVar1 = *pbVar5;
  uVar2 = *(uint *)(**(int **)(param_1 + 8) + 0x14 + (uint)bVar1 * 4);
  if ((((bVar1 == 0xc2) || (bVar1 == 0xac)) && (uVar4 = events_getScoreProperty(param_1), uVar4 < 0x850)) ||
     ((((uint)*pbVar5 == *(uint *)(param_1 + 0xd8) && (0 < iVar6)) && (pbVar5[1] == 0xd)))) {
    param_2[5] = param_2[5] + 1;
    iVar6 = iVar6 + -1;
    pbVar5 = pbVar5 + 1;
    if (iVar6 < 1) goto LAB_68039a38;
  }
  else {
    if (((uVar2 & 0x1000) != 0) || (0x3fd < local_8)) goto LAB_68039a38;
    local_8 = local_8 + 1;
    param_3[local_8] = *pbVar5;
  }
  iVar6 = iVar6 + -1;
  pbVar5 = pbVar5 + 1;
  goto joined_r0x680399ba;
}



// ============================================================
// Function: props_parseExpression (FUN_68039a80)
// Address: 68039a80
// Size: 28 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseExpression(int param_1,undefined4 *param_2)
{
  int param_4;
  props_parseTokenList(param_1,param_2,(byte *)(param_2 + 7),param_2 + 4);
  return 0;
}



// ============================================================
// Function: props_parseQuotedValue (FUN_68039aa0)
// Address: 68039aa0
// Size: 23 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseQuotedValue(int param_1,undefined4 param_2,undefined4 *param_3)
{
  props_parseQuotedString(param_1,param_3);
  return 0;
}



// ============================================================
// Function: props_resolveTokenValue (FUN_68039ac0)
// Address: 68039ac0
// Size: 669 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resolveTokenValue(int param_1,int param_2)
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  byte *in_EAX;
  int iVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int unaff_EBX;
  undefined4 *unaff_EDI;
  ulonglong uVar7;
  uint local_14;
  int local_10;
  undefined8 local_c;
  
  if (0 < (int)unaff_EDI[0x10d]) {
    iVar6 = unaff_EDI[0x10d] + -1;
    unaff_EDI[0x10d] = iVar6;
    *(undefined4 *)in_EAX = unaff_EDI[iVar6 * 2 + 0x107];
    *(undefined4 *)(in_EAX + 4) = unaff_EDI[iVar6 * 2 + 0x108];
    return 0;
  }
  props_parseExpression(unaff_EBX,unaff_EDI);
  (*(unsigned int *)((char *)&local_c + 4)) = (byte *)(unaff_EDI + 7);
  if (*(byte *)(unaff_EDI + 7) == 0xff) {
    uVar5 = Ordinal_1201((int)unaff_EDI + 0x1d);
  }
  else {
    uVar5 = (ushort)*(byte *)(unaff_EDI + 7);
  }
  local_10 = (int)(short)uVar5;
  if (local_10 < 1) {
    in_EAX[0] = 0;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
    in_EAX[3] = 0;
    in_EAX[4] = 0;
    in_EAX[5] = 0;
    in_EAX[6] = 0;
    in_EAX[7] = 0;
    return 0;
  }
  cVar1 = *(char *)((int)unaff_EDI + 0x1d);
  if (((cVar1 < '0') || ('9' < cVar1)) &&
     ((cVar1 != '.' || ((local_10 < 2 || (*(char *)((int)unaff_EDI + 0x1e) == '.')))))) {
    iVar6 = **(int **)(unaff_EBX + 8);
    if ((*(int *)(iVar6 + 0x4d0) != 0) &&
       (((local_10 == 3 && (unaff_EDI[4] == 2)) &&
        (bVar2 = *(byte *)(iVar6 + 0x14 + *(char *)((int)unaff_EDI + 0x1d) * 4),
        (byte)(bVar2 + 0x9f) < 8)))) {
      bVar3 = *(byte *)((int)unaff_EDI + 0x1e);
      bVar4 = *(byte *)((int)unaff_EDI + 0x1f);
      in_EAX[0] = 4;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      in_EAX[3] = 0;
      *(uint *)(in_EAX + 4) = (bVar4 - 0x19f8) + ((uint)bVar3 + (uint)bVar2 * 8) * 8;
      return 0;
    }
    if (*(char *)((int)unaff_EDI + 0x1d) == '\"') {
      props_parseQuotedValue(unaff_EBX,unaff_EDI,(undefined4 *)in_EAX);
      return 0;
    }
    iVar6 = score_resolveSymbolName(iVar6,DAT_68196304,(*(unsigned int *)((char *)&local_c + 4)),&local_14,param_2 == 0);
    *(int *)(**(int **)(unaff_EBX + 8) + 0x414) = iVar6;
    if (iVar6 < 0) {
      if (param_2 == 0) {
        in_EAX[0] = 0;
        in_EAX[1] = 0;
        in_EAX[2] = 0;
        in_EAX[3] = 0;
        return 0;
      }
    }
    else if ((param_1 == 0) || (0x2e < iVar6)) {
      in_EAX[0] = 8;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      in_EAX[3] = 0;
      *(int *)(in_EAX + 4) = iVar6;
    }
    else {
      in_EAX[0] = 8;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      in_EAX[3] = 0;
      *(int *)(in_EAX + 4) = iVar6;
      if (0 < (int)unaff_EDI[3]) {
        if (iVar6 == 0x16) {
          iVar6 = props_dispatchExtMethod(unaff_EBX,unaff_EDI,0x3e);
          if (iVar6 != 0) {
            in_EAX[4] = 0x17;
            in_EAX[5] = 0;
            in_EAX[6] = 0;
            in_EAX[7] = 0;
            return 0;
          }
          iVar6 = props_dispatchExtMethod(unaff_EBX,unaff_EDI,0x3d);
          if (iVar6 != 0) {
            in_EAX[4] = 0x18;
            in_EAX[5] = 0;
            in_EAX[6] = 0;
            in_EAX[7] = 0;
            return 0;
          }
        }
        else if (iVar6 == 0x19) {
          iVar6 = props_dispatchExtMethod(unaff_EBX,unaff_EDI,0x3d);
          if (iVar6 != 0) {
            in_EAX[4] = 0x1a;
            in_EAX[5] = 0;
            in_EAX[6] = 0;
            in_EAX[7] = 0;
            return 0;
          }
        }
        else if (iVar6 == 0x1b) {
          iVar6 = props_dispatchExtMethod(unaff_EBX,unaff_EDI,0x26);
          if (iVar6 != 0) {
            in_EAX[4] = 0x1c;
            in_EAX[5] = 0;
            in_EAX[6] = 0;
            in_EAX[7] = 0;
            return 0;
          }
        }
      }
    }
  }
  else {
    if ((unaff_EDI[4] == local_10) && ((int)unaff_EDI[4] < 10)) {
      in_EAX[0] = 4;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      in_EAX[3] = 0;
      Ordinal_950((int)(*(unsigned int *)((char *)&local_c + 4)),(undefined4 *)(in_EAX + 4));
      return 0;
    }
    in_EAX[0] = 0;
    in_EAX[1] = 0;
    in_EAX[2] = 0;
    in_EAX[3] = 0;
    in_EAX[4] = 0;
    in_EAX[5] = 0;
    in_EAX[6] = 0;
    in_EAX[7] = 0;
    props_parseConstant(unaff_EBX,(*(unsigned int *)((char *)&local_c + 4)),in_EAX);
    if (*(int *)in_EAX == 0x20) {
      local_c = (double)*(float *)(in_EAX + 4);
    }
    else {
      if (*(int *)in_EAX != 0x23) {
        stage_emitPushLiteral(unaff_EBX,0x1d);
        return 0;
      }
      local_c = *(double *)(**(int **)(in_EAX + 4) + 8);
    }
    if ((local_c < 2147483647.0 != (local_c == 2147483647.0)) && (unaff_EDI[4] == local_10)) {
      props_releaseValue(unaff_EBX,(byte)*(undefined4 *)in_EAX,*(int **)(in_EAX + 4));
      in_EAX[0] = 4;
      in_EAX[1] = 0;
      in_EAX[2] = 0;
      in_EAX[3] = 0;
      uVar7 = strings_floatToUint64(extraout_ECX,extraout_EDX);
      *(int *)(in_EAX + 4) = (int)uVar7;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: props_resolveTokenSafe (FUN_68039d60)
// Address: 68039d60
// Size: 46 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resolveTokenSafe(int param_1,undefined4 param_2,int param_3)
{
  props_resolveTokenValue(param_3,0);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x41c) = 0;
  return 0;
}



// ============================================================
// Function: props_setParserState (FUN_68039d90)
// Address: 68039d90
// Size: 31 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setParserState(undefined4 param_1,undefined4 param_2,int param_3)
{
  props_resolveTokenValue(param_3,1);
  return 0;
}



// ============================================================
// Function: props_pushTokenEntry (FUN_68039db0)
// Address: 68039db0
// Size: 46 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_pushTokenEntry(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x434);
  *(undefined4 *)(param_1 + 0x41c + iVar1 * 8) = *param_2;
  *(undefined4 *)(param_1 + 0x420 + iVar1 * 8) = param_2[1];
  *(int *)(param_1 + 0x434) = *(int *)(param_1 + 0x434) + 1;
  return 0;
}



// ============================================================
// Function: props_parseBlock (FUN_68039de0)
// Address: 68039de0
// Size: 80 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseBlock(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5
                 )
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 != *(int *)(param_2 + 0x14)) {
    props_resetParserPosition(param_2,0);
  }
  if (0 < *(int *)(param_2 + 0xc)) {
    while (-1 < param_3) {
      uVar1 = *(undefined4 *)(param_2 + 4);
      props_getCurrentToken();
      if ((param_3 < *(int *)(param_2 + 0x14)) || (*(int *)(param_2 + 0xc) < 1)) break;
    }
  }
  *param_4 = uVar1;
  *param_5 = *(undefined4 *)(param_2 + 4);
  return 0;
}



// ============================================================
// Function: props_peekNextToken (FUN_68039e30)
// Address: 68039e30
// Size: 27 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_peekNextToken(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  props_saveParserState(unaff_ESI);
  props_consumeLine();
  uVar1 = *(undefined4 *)(unaff_ESI + 4);
  props_restoreParserState(unaff_ESI);
  return uVar1;
}



// ============================================================
// Function: props_skipMatchingBlock (FUN_68039e50)
// Address: 68039e50
// Size: 160 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x68039ec1) */

undefined4 props_skipMatchingBlock(undefined4 param_1,int param_2,int *param_3)

{
  int local_8;
  
  local_8 = 1;
  props_saveParserState(param_2);
  *param_3 = 0;
  do {
    props_releaseValue(param_1,(byte)*param_3,(int *)param_3[1]);
    props_setParserState(param_1,param_2,1);
    if (*param_3 == 8) {
      if (param_3[1] == 4) {
        local_8 = local_8 + 1;
      }
      else if ((param_3[1] == 5) && (local_8 = local_8 + -1, local_8 == 0)) {
        props_setParserState(param_1,param_2,0);
        props_restoreParserState(param_2);
        return 1;
      }
    }
    if (*param_3 == 0) {
      props_restoreParserState(param_2);
      return 0;
    }
  } while( true );
}



// ============================================================
// Function: props_peekNextOffset (FUN_68039ef0)
// Address: 68039ef0
// Size: 22 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_peekNextOffset(void)
{
  props_peekNextToken();
  return 0;
}



// ============================================================
// Function: props_formatHexValue (FUN_68039f10)
// Address: 68039f10
// Size: 101 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_formatHexValue(void)
{
  char cVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *unaff_EDI;
  
  iVar2 = 0;
  do {
    if ((in_EAX & 0xf0000000) != 0) break;
    iVar2 = iVar2 + 1;
    in_EAX = in_EAX << 4;
  } while (iVar2 < 8);
  iVar2 = 8 - iVar2;
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  iVar4 = 1;
  if (0 < iVar2) {
    do {
      uVar3 = (int)in_EAX >> 0x1c & 0xf;
      in_EAX = in_EAX << 4;
      cVar1 = (char)uVar3;
      if (uVar3 < 10) {
        cVar1 = cVar1 + '0';
      }
      else {
        cVar1 = cVar1 + 'W';
      }
      unaff_EDI[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar2);
  }
  unaff_EDI[iVar2 + 1] = 0;
  if (iVar2 < 0xff) {
    *unaff_EDI = (char)iVar2;
    return 0;
  }
  *unaff_EDI = 0xff;
  return 0;
}


