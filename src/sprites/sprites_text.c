// Module: sprites
// Topic: Text field operations, cursor handling, editing, cast tables, and menus
// Address range: 0x6807CFE0 - 0x6807FF80
// Functions (64):
//   sprites_resolveTextChannel
//   sprites_getTextMemberRef
//   sprites_getTextSelectionRange
//   sprites_setTextSelectionRange
//   sprites_getTextSelectionStart
//   sprites_setTextSelection
//   sprites_applyTextAction
//   sprites_processTextKey
//   sprites_getTextRange
//   sprites_getTextChannelData
//   sprites_isTextMember
//   sprites_handleTextClick
//   sprites_handleTextDrag
//   sprites_handleTextInput
//   sprites_handleTextKeyDown
//   sprites_processTextCommand
//   sprites_handleTextCopy
//   sprites_handleTextPaste
//   sprites_handleTextCut
//   sprites_handleTextSelectAll
//   sprites_handleTextUndo
//   sprites_handleTextDelete
//   sprites_handleTextClear
//   sprites_getTextEditState
//   sprites_setTextEditState
//   sprites_getTextScrollPos
//   sprites_setTextScrollPos
//   sprites_getTextState
//   sprites_getTextLineCount
//   sprites_setTextLineSpacing
//   sprites_getTextAlignment
//   sprites_setTextAlignment
//   sprites_getTextFont
//   sprites_setTextFont
//   sprites_getTextSize
//   sprites_setTextSize
//   sprites_getTextStyle
//   sprites_setTextStyle
//   sprites_initTextEditor
//   sprites_initTextState
//   sprites_destroyTextEditor
//   sprites_resetTextEditor
//   sprites_refreshTextDisplay
//   sprites_dispatchBehavior
//   sprites_handleTextEvent
//   sprites_handleTextScroll
//   sprites_processScrollInput
//   sprites_updateTextCursor
//   sprites_renderTextOverlay
//   sprites_getTextProperty
//   sprites_getTextPropertyEx
//   sprites_getTextInfo
//   sprites_getTextBounds
//   sprites_setTextBounds
//   sprites_getTextBoxSize
//   sprites_setTextBoxSize
//   sprites_handleEditCommand
//   sprites_processEditMenu
//   sprites_buildEditMenu
//   sprites_enableEditMenu
//   sprites_getEditMenuState
//   sprites_setCursorVisible
//   sprites_getTextCaretPos
//   sprites_setTextCaretPos


// ============================================================
// Function: sprites_resolveTextChannel (FUN_6807cfe0)
// Address: 6807cfe0
// Size: 392 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int sprites_resolveTextChannel(int param_1)

{
  int local_18;
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  local_8 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  iVar4 = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    piVar3 = *(int **)(*(int *)(param_1 + 8) + 4);
  }
  else {
    piVar3 = *(int **)(*(int *)(param_1 + 0xc) + 4);
  }
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  while( true ) {
    piVar3[0x1cb] = piVar3[0x1cb] + 1;
    if (piVar3[0x1cc] < piVar3[0x1cb]) {
      piVar3[0x1cb] = 0;
    }
    else if (0 < piVar3[0x1cb]) {
      return iVar4;
    }
    iVar1 = Ordinal_1541();
    uVar2 = iVar1 - _DAT_68196360;
    _DAT_68196360 = iVar1;
    if (uVar2 < 0x32) {
      if (piVar3[0x1cc] < 0x10) {
        piVar3[0x1cc] = piVar3[0x1cc] * 2 + 1;
        return iVar4;
      }
    }
    else if (100 < uVar2) {
      if (uVar2 < 0x1f5) {
        piVar3[0x1cc] = piVar3[0x1cc] / 2;
      }
      else {
        piVar3[0x1cc] = 0;
      }
    }
    if (piVar3[0x5b] == 0) {
      stage_handleEvent(local_8,9);
    }
    if (piVar3[0x69] == 0) {
      iVar1 = stage_forEachEvent(local_8,10,sprites_checkFileType);
      if (iVar1 != 0) {
        iVar4 = 1;
      }
      local_c = 0;
      Ordinal_54(piVar3[8],&local_c);
      if ((local_c != 0) && (iVar1 = Ordinal_1812(local_c), iVar1 == 0)) {
        return 1;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    iVar1 = events_getEditRef(local_8);
    if (iVar1 != 0) {
      iVar4 = 1;
    }
    if (piVar3[0x69] == 0) {
      if ((iVar4 != 0) && (*(int *)(**(int **)(*piVar3 + 4) + 0x8c) == 0)) {
        sprites_setCursorHand(param_1);
      }
    }
    else {
      iVar4 = 0;
    }
    iVar1 = *(int *)(*(int *)(local_8 + 8) + 0x18);
    if (iVar1 == 0) break;
    iVar1 = lingo_checkState(*(int *)(iVar1 + 0xc));
    if (iVar1 != 1) {
      return iVar4;
    }
  }
  return iVar4;
}



// ============================================================
// Function: sprites_getTextMemberRef (FUN_6807d170)
// Address: 6807d170
// Size: 208 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextMemberRef(int param_1,undefined1 *param_2)
{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined3 uVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  
  piVar3 = (int *)(*(int **)(param_1 + 8))[1];
  iVar4 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  events_getEditRef(*(int *)(*(int *)(piVar3[0xb] + 8) + 0x14));
  uVar8 = sprites_downloadNetFile(param_1);
  puVar6 = param_2;
  pcVar1 = param_2 + 1;
  if (uVar8 == 0) {
    *param_2 = 0;
    *pcVar1 = '\0';
  }
  else {
    Ordinal_1771(pcVar1);
    uVar7 = Ordinal_1201(pcVar1);
    *puVar6 = uVar7;
  }
  cVar2 = *pcVar1;
  if (cVar2 != '\0') {
    uVar5 = *(undefined3 *)(puVar6 + 2);
    param_2 = (undefined1 *)0x0;
    uVar9 = Ordinal_1201(pcVar1,&param_2,4);
    iVar10 = Ordinal_1265(pcVar1,uVar9);
    if ((iVar10 < 0) || (0xff < (ushort)param_2)) {
      param_2 = (undefined1 *)0x0;
    }
    events_initMouseState(piVar3,0,(ushort)(byte)(&DAT_6818e378)[(uint)param_2 & 0xffff],
                 CONCAT31(uVar5,cVar2));
  }
  uVar9 = Ordinal_1545();
  *(undefined4 *)(iVar4 + 0x28) = uVar9;
  return 0;
}



// ============================================================
// Function: sprites_getTextSelectionRange (FUN_6807d240)
// Address: 6807d240
// Size: 74 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getTextSelectionRange(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  uVar2 = sprites_downloadNetFile(param_1);
  if (uVar2 == 0) {
    uVar3 = Ordinal_1545();
    *(undefined4 *)(iVar1 + 0x28) = uVar3;
    return 0;
  }
  uVar3 = Ordinal_1770(param_2);
  uVar4 = Ordinal_1545();
  *(undefined4 *)(iVar1 + 0x28) = uVar4;
  return uVar3;
}



// ============================================================
// Function: sprites_setTextSelectionRange (FUN_6807d290)
// Address: 6807d290
// Size: 105 bytes
// Params: void * this, short param_1
// Return: char *
// Calling convention: __thiscall
// ============================================================

char * __thiscall sprites_setTextSelectionRange(void *this,short param_1)

{
  short in_AX;
  
  if (100 < in_AX) {
    *(char *)this = (char)(((int)in_AX / 100) % 10) + '0';
    this = (void *)((int)this + 1);
  }
  *(char *)this = (char)(((int)in_AX / 10) % 10) + '0';
  *(char *)((int)this + 1) = (char)((int)in_AX % 10) + '0';
  if (param_1 != 0) {
    *(char *)((int)this + 2) = (char)param_1;
    return (char *)((int)this + 3);
  }
  return (char *)((int)this + 2);
}



// ============================================================
// Function: sprites_getTextSelectionStart (FUN_6807d300)
// Address: 6807d300
// Size: 68 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_getTextSelectionStart(int param_1)

{
  int iVar1;
  short unaff_SI;
  int iVar2;
  int iVar3;
  
  if (param_1 == -0x80000000) {
    return -0x80000000;
  }
  iVar2 = (int)unaff_SI;
  iVar1 = iVar2 * 600 + -0x12;
  iVar3 = param_1 + (param_1 / iVar1) * 0x12;
  iVar1 = param_1 % iVar1 + iVar2 * -0x3c;
  if (-1 < iVar1) {
    iVar3 = iVar3 + 2 + (iVar1 / (iVar2 * 0x3c + -2)) * 2;
  }
  return iVar3;
}



// ============================================================
// Function: sprites_setTextSelection (FUN_6807d350)
// Address: 6807d350
// Size: 317 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, char * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setTextSelection(int param_1,undefined4 param_2,int param_3,int param_4,char *param_5)
{
  char *pcVar1;
  
  if (param_3 != 0) {
    param_1 = sprites_getTextSelectionStart(param_1);
  }
  param_5[1] = (-(param_1 < 0) & 0xdU) + 0x20;
  pcVar1 = sprites_setTextSelectionRange(param_5 + 2,0x3a);
  pcVar1 = sprites_setTextSelectionRange(pcVar1,0x3a);
  pcVar1 = sprites_setTextSelectionRange(pcVar1,0x2e);
  pcVar1 = sprites_setTextSelectionRange(pcVar1,0);
  *pcVar1 = (-(param_3 != 0) & 0x44U) + 0x20;
  pcVar1 = pcVar1 + 1;
  *pcVar1 = '\0';
  *pcVar1 = '\0';
  if ((int)(pcVar1 + (-1 - (int)param_5)) < 0xff) {
    *param_5 = ((char)pcVar1 - (char)param_5) + -1;
    return 0;
  }
  *param_5 = -1;
  return 0;
}



// ============================================================
// Function: sprites_applyTextAction (FUN_6807d490)
// Address: 6807d490
// Size: 90 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_applyTextAction(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  short unaff_DI;
  
  if (in_EAX == -0x80000000) {
    return -0x80000000;
  }
  iVar3 = unaff_DI * 600;
  iVar1 = unaff_DI * 0x3c;
  iVar2 = (in_EAX % iVar3) % iVar1;
  if ((in_EAX % iVar3) / iVar1 != 0) {
    if (iVar2 == 0) {
      in_EAX = in_EAX + 2;
    }
    else if (iVar2 == 1) {
      in_EAX = in_EAX + 1;
    }
  }
  return in_EAX + ((in_EAX % iVar3) / iVar1 + (in_EAX / iVar3) * 9) * -2;
}



// ============================================================
// Function: sprites_processTextKey (FUN_6807d4f0)
// Address: 6807d4f0
// Size: 501 bytes
// Params: byte * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_processTextKey(byte *param_1,undefined4 param_2,int *param_3)
{
  short sVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  short sVar5;
  short sVar6;
  byte *pbVar7;
  int aiStack_20018 [32762];
  int local_18 [5];
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  local_18[3] = 0;
  local_18[2] = 0;
  local_18[1] = 0;
  local_18[0] = 0;
  sVar6 = 1;
  pbVar3 = param_1;
  while( true ) {
    pbVar7 = pbVar3 + 1;
    if ((*pbVar7 != 0x20) && (*pbVar7 != 9)) break;
    if ((short)(ushort)*param_1 <= sVar6) goto LAB_6807d6d2;
    sVar6 = sVar6 + 1;
    pbVar3 = pbVar7;
  }
  for (pbVar4 = param_1 + (short)(ushort)*param_1; (*pbVar4 == 0x20 || (*pbVar4 == 9));
      pbVar4 = pbVar4 + -1) {
  }
  if ((*pbVar4 == 0x44) || (*pbVar4 == 100)) {
    *param_3 = 1;
    pbVar4 = pbVar4 + -1;
  }
  if (*pbVar7 == 0x2d) {
    pbVar7 = pbVar3 + 2;
  }
  sVar6 = 2;
  while( true ) {
    sVar1 = 0;
    sVar5 = 0;
    if (pbVar4 < pbVar7) break;
    do {
      if (sVar6 < 0) goto LAB_6807d673;
      bVar2 = *pbVar4;
      if ((bVar2 < 0x30) || (0x39 < bVar2)) {
        if ((bVar2 == 0x3a) || ((bVar2 == 0x20 || (bVar2 == 9)))) {
          pbVar4 = pbVar4 + -1;
        }
        else {
          if (bVar2 != 0x2e) goto LAB_6807d6d2;
          pbVar4 = pbVar4 + -1;
          sVar6 = 3;
          if (sVar5 == 1) {
            sVar1 = sVar1 * 10;
          }
        }
        break;
      }
      if (sVar5 == 2) break;
      sVar5 = sVar5 + 1;
      pbVar4 = pbVar4 + -1;
      sVar1 = sVar1 + (bVar2 - 0x30) * (((sVar5 != 2) - 1 & 9) + 1);
    } while (pbVar7 <= pbVar4);
    local_18[sVar6] = local_18[sVar6] + (int)sVar1;
    sVar6 = sVar6 + -1;
  }
LAB_6807d673:
  if (*param_3 != 0) {
    sprites_applyTextAction();
    return 0;
  }
LAB_6807d6d2:
  return 0;
}



// ============================================================
// Function: sprites_getTextRange (FUN_6807d6f0)
// Address: 6807d6f0
// Size: 86 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getTextRange(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    piVar1 = (int *)Ordinal_1114(*(int *)(param_1 + 0x48));
    if ((0 < param_2) && (param_2 <= *piVar1)) {
      iVar2 = piVar1[param_2 * 3 + -2];
      if (param_3 != (int *)0x0) {
        *param_3 = piVar1[param_2 * 3 + -1];
      }
    }
    if (piVar1 != (int *)0x0) {
      Ordinal_1115(*(undefined4 *)(param_1 + 0x48));
    }
  }
  return iVar2;
}



// ============================================================
// Function: sprites_getTextChannelData (FUN_6807d750)
// Address: 6807d750
// Size: 37 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getTextChannelData(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (((0 < param_2) && (param_2 <= *param_1)) && (-1 < param_1[param_2 * 3])) {
    iVar1 = param_1[param_2 * 3] + (int)param_1;
  }
  return iVar1;
}



// ============================================================
// Function: sprites_isTextMember (FUN_6807d780)
// Address: 6807d780
// Size: 21 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool sprites_isTextMember(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x2c) + 0x28) == 0;
}




// ============================================================
// Function: sprites_handleTextClick (FUN_6807d7a0)
// Address: 6807d7a0
// Size: 81 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextClick(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int *piVar4;
  int extraout_EDX;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  bVar3 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  if (CONCAT31(extraout_var,bVar3) != 0) {
    return extraout_EDX + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x48);
  if (iVar2 != 0) {
    piVar4 = (int *)Ordinal_1114(iVar2);
    iVar2 = *piVar4;
    Ordinal_1115(*(undefined4 *)(iVar1 + 0x48));
    return iVar2;
  }
  return extraout_EDX;
}



// ============================================================
// Function: sprites_handleTextDrag (FUN_6807d800)
// Address: 6807d800
// Size: 62 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextDrag(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int extraout_EDX;
  
  bVar1 = sprites_isTextMember(*(int *)(*(int *)(param_1 + 8) + 4));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return param_2;
  }
  if (0 < param_2) {
    iVar2 = sprites_handleTextClick(extraout_EDX);
    if (param_2 <= iVar2) {
      return param_2;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_handleTextInput (FUN_6807d840)
// Address: 6807d840
// Size: 239 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextInput(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  iVar4 = param_1;
  local_8 = 0;
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  local_c = 0;
  bVar2 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    Ordinal_1127(&local_8);
    return 1;
  }
  iVar6 = local_c;
  if (param_2 != 0) {
    iVar9 = param_2 + 1;
    if (*(byte *)(param_2 + 1) == 0xff) {
      iVar8 = param_2 + 2;
      param_2 = iVar9;
      uVar3 = Ordinal_1201(iVar8);
    }
    else {
      uVar3 = (uint)*(byte *)(param_2 + 1);
      param_2 = iVar9;
    }
    param_1 = uVar3 + 2;
    local_8 = Ordinal_1126(param_1,&param_1);
    if (local_8 != 0) {
      iVar4 = sprites_handleTextClick(iVar4);
      iVar8 = 1;
      if (0 < iVar4) {
        do {
          iVar6 = local_8;
          iVar7 = param_1;
          iVar5 = sprites_getTextRange(iVar1,iVar8,(int *)0x0);
          iVar6 = Ordinal_1856(iVar5,iVar6,iVar7);
          if (iVar6 != 0) {
            iVar6 = Ordinal_1255(local_8,iVar9);
            iVar7 = Ordinal_1042();
            iVar9 = param_2;
            if ((iVar6 == 0) && (iVar6 = iVar8, iVar7 == 0)) break;
          }
          iVar8 = iVar8 + 1;
          iVar6 = local_c;
        } while (iVar8 <= iVar4);
      }
    }
  }
  local_c = iVar6;
  Ordinal_1127(&local_8);
  return local_c;
}



// ============================================================
// Function: sprites_handleTextKeyDown (FUN_6807d930)
// Address: 6807d930
// Size: 72 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_handleTextKeyDown(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *extraout_EDX;
  int local_8;
  
  local_8 = 0;
  bVar1 = sprites_isTextMember(*(int *)(*(int *)(param_1 + 8) + 4));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 1;
  }
  sprites_getTextRange(*(int *)(*extraout_EDX + 0x51c),param_2,&local_8);
  return local_8;
}



// ============================================================
// Function: sprites_processTextCommand (FUN_6807d980)
// Address: 6807d980
// Size: 239 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_processTextCommand(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int local_c;
  char *local_8;
  
  iVar8 = param_1;
  local_8 = (char *)0x0;
  iVar4 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  local_c = 0;
  bVar2 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    if (*(byte *)(param_3 + 1) == 0xff) {
      iVar5 = param_3 + 2;
      param_3 = param_3 + 1;
      uVar3 = Ordinal_1201(iVar5);
    }
    else {
      uVar3 = (uint)*(byte *)(param_3 + 1);
      param_3 = param_3 + 1;
    }
    param_1 = uVar3 + 2;
    local_8 = (char *)Ordinal_1126(param_1,&param_1);
    iVar5 = param_2;
    iVar1 = local_c;
    if (local_8 != (char *)0x0) {
      param_2 = sprites_getTextRange(iVar4,param_2,(int *)0x0);
      iVar4 = sprites_handleTextKeyDown(iVar8,iVar5);
      iVar8 = 1;
      if (0 < iVar4) {
        do {
          iVar5 = Ordinal_1862(param_2,iVar8,local_8,param_1);
          pcVar6 = xtra_trimString(local_8);
          xtra_trimTrailingWhitespace(pcVar6);
          if (iVar5 != 0) {
            iVar5 = Ordinal_1255(pcVar6,param_3);
            iVar7 = Ordinal_1042();
            if ((iVar5 == 0) && (iVar1 = iVar8, iVar7 != 0)) break;
          }
          iVar8 = iVar8 + 1;
          iVar1 = local_c;
        } while (iVar8 <= iVar4);
      }
    }
  }
  else {
    local_c = 1;
    iVar1 = local_c;
  }
  local_c = iVar1;
  Ordinal_1127(&local_8);
  return local_c;
}



// ============================================================
// Function: sprites_handleTextCopy (FUN_6807da80)
// Address: 6807da80
// Size: 66 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextCopy(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int extraout_EDX;
  
  bVar1 = sprites_isTextMember(*(int *)(*(int *)(param_1 + 8) + 4));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return param_3;
  }
  if (0 < param_3) {
    iVar2 = sprites_handleTextKeyDown(extraout_EDX,param_2);
    if (param_3 <= iVar2) {
      return param_3;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_handleTextPaste (FUN_6807dad0)
// Address: 6807dad0
// Size: 100 bytes
// Params: int param_1, int param_2, undefined2 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextPaste(int param_1,int param_2,undefined2 *param_3)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int extraout_EDX;
  
  bVar1 = sprites_isTextMember(*(int *)(*(int *)(param_1 + 8) + 4));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    *param_3 = 0;
    return 0;
  }
  iVar2 = sprites_getTextRange(extraout_EDX,param_2,(int *)0x0);
  iVar2 = Ordinal_1856(iVar2,(int)param_3 + 1,0x3ff);
  *(undefined1 *)(iVar2 + 1 + (int)param_3) = 0;
  if (iVar2 < 0xff) {
    *(char *)param_3 = (char)iVar2;
    return 0;
  }
  *(undefined1 *)param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: sprites_handleTextCut (FUN_6807db40)
// Address: 6807db40
// Size: 116 bytes
// Params: int param_1, int param_2, int param_3, undefined2 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextCut(int param_1,int param_2,int param_3,undefined2 *param_4)
{
  undefined2 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int extraout_EDX;
  
  bVar2 = sprites_isTextMember(*(int *)(*(int *)(param_1 + 8) + 4));
  if (CONCAT31(extraout_var,bVar2) != 0) {
    *param_4 = 0;
    return 0;
  }
  iVar3 = sprites_getTextRange(extraout_EDX,param_2,&param_1);
  puVar1 = param_4;
  if ((0 < param_3) && (param_3 <= param_1)) {
    iVar3 = Ordinal_1862(iVar3,param_3,(int)param_4 + 1,0x3ff);
    *(undefined1 *)(iVar3 + 1 + (int)puVar1) = 0;
    if (iVar3 < 0xff) {
      *(char *)puVar1 = (char)iVar3;
      return 0;
    }
    *(undefined1 *)puVar1 = 0xff;
  }
  return 0;
}



// ============================================================
// Function: sprites_handleTextSelectAll (FUN_6807dbc0)
// Address: 6807dbc0
// Size: 160 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextSelectAll(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  bool bVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  uVar2 = 0;
  bVar4 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  if (((CONCAT31(extraout_var,bVar4) == 0) &&
      (iVar5 = sprites_getTextRange(iVar1,param_2,&param_1), iVar3 = param_3, 0 < param_3)) &&
     (param_3 <= param_1)) {
    if (*(int *)(iVar1 + 0x58) != 0) {
      iVar6 = Ordinal_1116(*(int *)(iVar1 + 0x58));
      piVar7 = (int *)Ordinal_1114(*(undefined4 *)(iVar1 + 0x58));
      if (piVar7 != (int *)0x0) {
        for (; 0 < iVar6; iVar6 = iVar6 + -0x14) {
          if ((*piVar7 == param_2) && (piVar7[1] == iVar3)) {
            uVar2 = (undefined1)piVar7[4];
            break;
          }
          piVar7 = piVar7 + 5;
        }
      }
    }
    Ordinal_1863(iVar5,iVar3,param_4 + 1,uVar2);
  }
  return 0;
}



// ============================================================
// Function: sprites_handleTextUndo (FUN_6807dc60)
// Address: 6807dc60
// Size: 87 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_handleTextUndo(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 extraout_EDX;
  
  iVar2 = (*(int **)(param_1 + 8))[1];
  sprites_getTextRange(*(int *)(**(int **)(param_1 + 8) + 0x51c),param_2,&param_1);
  bVar1 = sprites_isTextMember(iVar2);
  if (((CONCAT31(extraout_var,bVar1) == 0) && (0 < param_3)) && (param_3 <= param_1)) {
    iVar2 = Ordinal_1860(extraout_EDX,param_3);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_handleTextDelete (FUN_6807dcc0)
// Address: 6807dcc0
// Size: 72 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_handleTextDelete(int param_1,int param_2,int param_3,undefined4 param_4)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int extraout_EDX;
  
  bVar1 = sprites_isTextMember(*(int *)(*(int *)(param_1 + 8) + 4));
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = sprites_getTextRange(extraout_EDX,param_2,&param_1);
    if ((0 < param_3) && (param_3 <= param_1)) {
      Ordinal_1861(iVar2,param_3,param_4);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_handleTextClear (FUN_6807dd10)
// Address: 6807dd10
// Size: 87 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_handleTextClear(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 extraout_EDX;
  
  iVar2 = (*(int **)(param_1 + 8))[1];
  sprites_getTextRange(*(int *)(**(int **)(param_1 + 8) + 0x51c),param_2,&param_1);
  bVar1 = sprites_isTextMember(iVar2);
  if (((CONCAT31(extraout_var,bVar1) == 0) && (0 < param_3)) && (param_3 <= param_1)) {
    iVar2 = Ordinal_1858(extraout_EDX,param_3);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}




// ============================================================
// Function: sprites_getTextEditState (FUN_6807dd70)
// Address: 6807dd70
// Size: 149 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextEditState(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  bVar3 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  if (((CONCAT31(extraout_var,bVar3) == 0) &&
      (iVar4 = sprites_getTextRange(iVar1,param_2,&param_1), iVar2 = param_3, 0 < param_3)) &&
     (param_3 <= param_1)) {
    if (*(int *)(iVar1 + 0x58) != 0) {
      iVar5 = Ordinal_1116(*(int *)(iVar1 + 0x58));
      piVar6 = (int *)Ordinal_1114(*(undefined4 *)(iVar1 + 0x58));
      if (piVar6 != (int *)0x0) {
        for (; 0 < iVar5; iVar5 = iVar5 + -0x14) {
          if ((*piVar6 == param_2) && (piVar6[1] == iVar2)) {
            piVar6[3] = param_4;
            break;
          }
          piVar6 = piVar6 + 5;
        }
      }
    }
    Ordinal_1859(iVar4,iVar2,param_4);
  }
  return 0;
}



// ============================================================
// Function: sprites_setTextEditState (FUN_6807de10)
// Address: 6807de10
// Size: 164 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_setTextEditState(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  bVar2 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  iVar5 = param_2;
  if (CONCAT31(extraout_var,bVar2) != 0) {
    uVar3 = Ordinal_1111(0,0);
    return uVar3;
  }
  sprites_getTextRange(iVar1,param_2,&param_1);
  if ((0 < param_3) && (param_3 <= param_1)) {
    piVar4 = (int *)Ordinal_1114(*(undefined4 *)(iVar1 + 0x48));
    iVar5 = sprites_getTextChannelData(piVar4,iVar5);
    if ((iVar5 == 0) || (iVar5 = *(int *)(iVar5 + -4 + param_3 * 4), iVar5 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = Ordinal_1120(iVar5,0);
    }
    if (piVar4 != (int *)0x0) {
      Ordinal_1115(*(undefined4 *)(iVar1 + 0x48));
    }
    return uVar3;
  }
  return 0;
}



// ============================================================
// Function: sprites_getTextScrollPos (FUN_6807dec0)
// Address: 6807dec0
// Size: 138 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextScrollPos(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  
  iVar2 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  bVar3 = sprites_isTextMember((*(int **)(param_1 + 8))[1]);
  iVar5 = param_2;
  if ((((CONCAT31(extraout_var,bVar3) == 0) && (sprites_getTextRange(iVar2,param_2,&param_1), 0 < param_3))
      && (param_3 <= param_1)) && (param_4 = Ordinal_1120(param_4,0), param_4 != 0)) {
    piVar4 = (int *)Ordinal_1114(*(undefined4 *)(iVar2 + 0x48));
    iVar5 = sprites_getTextChannelData(piVar4,iVar5);
    if (iVar5 != 0) {
      piVar1 = (int *)(iVar5 + -4 + param_3 * 4);
      Ordinal_1113(piVar1);
      *piVar1 = param_4;
    }
    if (piVar4 != (int *)0x0) {
      Ordinal_1115(*(undefined4 *)(iVar2 + 0x48));
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setTextScrollPos (FUN_6807df50)
// Address: 6807df50
// Size: 34 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setTextScrollPos(undefined4 param_1)
{
  int unaff_ESI;
  
  Ordinal_1432(*(undefined4 *)(unaff_ESI + 4));
  Ordinal_1420(*(undefined4 *)(unaff_ESI + 4),param_1,0x14);
  return 0;
}



// ============================================================
// Function: sprites_getTextState (FUN_6807df80)
// Address: 6807df80
// Size: 34 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextState(undefined4 param_1)
{
  int unaff_ESI;
  
  Ordinal_1432(*(undefined4 *)(unaff_ESI + 4));
  Ordinal_1409(*(undefined4 *)(unaff_ESI + 4),param_1,0x14);
  return 0;
}



// ============================================================
// Function: sprites_getTextLineCount (FUN_6807dfb0)
// Address: 6807dfb0
// Size: 129 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool sprites_getTextLineCount(void)

{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  bool bVar2;
  int local_c;
  byte *local_8;
  
  bVar2 = false;
  local_8 = (byte *)Ordinal_1126(*(int *)(unaff_EBX + 0x20) + 2,0);
  if (local_8 != (byte *)0x0) {
    *local_8 = 0;
    if ((int)(uint)*local_8 < *(int *)(unaff_EBX + 0x20)) {
      do {
        iVar1 = Ordinal_1252(in_EAX,&local_c);
        if (iVar1 == 0) break;
        Ordinal_1246(local_8,iVar1);
        in_EAX = in_EAX + local_c;
      } while ((int)(uint)*local_8 < *(int *)(unaff_EBX + 0x20));
    }
    iVar1 = Ordinal_1255(local_8 + 1,*(undefined4 *)(unaff_EBX + 0x1c));
    bVar2 = iVar1 == 0;
    Ordinal_1042();
  }
  Ordinal_1127(&local_8);
  return bVar2;
}



// ============================================================
// Function: sprites_setTextLineSpacing (FUN_6807e040)
// Address: 6807e040
// Size: 208 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall sprites_setTextLineSpacing(int *param_1)

{
  char *in_EAX;
  char *pcVar1;
  int iVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  
  Ordinal_1130(&local_18,0x14);
  if (in_EAX == (char *)0x0) {
    local_c = " ";
  }
  else {
    pcVar1 = xtra_trimString(in_EAX);
    pcVar1 = xtra_trimString(pcVar1 + param_1[8]);
    local_c = pcVar1;
    iVar2 = xtra_parseTextFormat(pcVar1);
    while (iVar2 == 0) {
      pcVar1 = pcVar1 + 1;
      iVar2 = xtra_parseTextFormat(pcVar1);
    }
    local_10 = (int)pcVar1 - (int)local_c;
  }
  Ordinal_1432(param_1[1],0,2);
  iVar2 = Ordinal_1433(param_1[1]);
  iVar3 = Ordinal_1420(param_1[1],&local_18,0x14);
  if (iVar3 == 0) {
    return 0;
  }
  if (*param_1 == 0) {
    param_1[3] = iVar2;
    param_1[2] = iVar2;
  }
  else {
    sprites_getTextState(&local_18);
    local_14 = param_1[5];
    local_18 = iVar2;
    sprites_setTextScrollPos(&local_18);
  }
  *param_1 = *param_1 + 1;
  param_1[3] = iVar2;
  param_1[4] = 0;
  param_1[5] = 0;
  return 1;
}



// ============================================================
// Function: sprites_getTextAlignment (FUN_6807e110)
// Address: 6807e110
// Size: 76 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall sprites_getTextAlignment(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_8 [4];
  
  uVar1 = Ordinal_1252(param_1,local_8);
  iVar2 = Ordinal_1253(uVar1);
  if (((((char)iVar2 != '|') && (iVar2 != 0xc5)) && (iVar2 != 0xbc)) && (iVar2 != 0xac)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: sprites_setTextAlignment (FUN_6807e160)
// Address: 6807e160
// Size: 304 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall sprites_setTextAlignment(int param_1)

{
  char *in_EAX;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 local_30 [16];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  char *local_14;
  int local_10;
  char *local_c;
  int local_8;
  
  Ordinal_1130(&local_1c,0x14);
  local_14 = in_EAX;
  iVar1 = xtra_parseTextFormat(in_EAX);
  pcVar2 = in_EAX;
  while (iVar1 == 0) {
    Ordinal_1252(in_EAX,&local_8);
    if ((local_c == (char *)0x0) && (iVar1 = sprites_getTextAlignment(in_EAX), iVar1 != 0)) {
      local_18 = (int)in_EAX - (int)pcVar2;
      if (local_18 == 0) {
        local_14 = " ";
        local_18 = 1;
      }
      pcVar2 = xtra_trimString(in_EAX + local_8);
      local_c = pcVar2;
    }
    in_EAX = in_EAX + local_8;
    iVar1 = xtra_parseTextFormat(in_EAX);
  }
  if (local_c == (char *)0x0) {
    local_18 = (int)in_EAX - (int)pcVar2;
    if (local_18 == 0) {
      local_14 = " ";
      local_18 = 1;
    }
  }
  else {
    local_10 = (int)in_EAX - (int)pcVar2;
  }
  Ordinal_1432(*(undefined4 *)(param_1 + 4),0,2);
  uVar3 = Ordinal_1433(*(undefined4 *)(param_1 + 4));
  iVar1 = Ordinal_1420(*(undefined4 *)(param_1 + 4),&local_1c,0x14);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    sprites_getTextState(local_30);
    local_20 = uVar3;
    sprites_setTextScrollPos(local_30);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    *(undefined4 *)(param_1 + 0x10) = uVar3;
    return 1;
  }
  sprites_getTextState(&local_1c);
  local_1c = uVar3;
  sprites_setTextScrollPos(&local_1c);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  return 1;
}



// ============================================================
// Function: sprites_getTextFont (FUN_6807e290)
// Address: 6807e290
// Size: 97 bytes
// Params: int param_1, uint param_2, char * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_getTextFont(int param_1,uint param_2,char *param_3)
{
  uint uVar1;
  int in_EAX;
  undefined4 uVar2;
  char *pcVar3;
  int local_c;
  char *local_8;
  
  uVar1 = param_2 + in_EAX;
  local_8 = param_3 + param_1 + -1;
  pcVar3 = param_3;
  while ((param_2 < uVar1 && (pcVar3 < local_8))) {
    uVar2 = Ordinal_1252(param_2,&local_c);
    pcVar3 = (char *)Ordinal_1247(pcVar3,uVar2);
    param_2 = param_2 + local_c;
  }
  *pcVar3 = '\0';
  xtra_trimTrailingWhitespace(param_3);
  if (*param_3 == '\0') {
    param_3[0] = ' ';
    param_3[1] = '\0';
  }
  return 0;
}



// ============================================================
// Function: sprites_setTextFont (FUN_6807e300)
// Address: 6807e300
// Size: 108 bytes
// Params: void * this, byte param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall
sprites_setTextFont(void *this,byte param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined4 local_10;
  byte local_c;
  uint local_8;
  
  if ((byte)(param_1 + 0x9f) < 0x1a) {
    param_1 = param_1 - 0x20;
  }
  local_14 = (&DAT_6818e378)[param_1];
  local_18 = param_3;
  local_1c = param_2;
  local_10 = param_4;
  local_c = param_1;
  Ordinal_1121((int)this + 0x54,&local_1c,0x14);
  return 0;
}




// ============================================================
// Function: sprites_getTextSize (FUN_6807e370)
// Address: 6807e370
// Size: 397 bytes
// Params: void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined1 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
sprites_getTextSize(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 *param_5)

{
  undefined1 uVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  uint local_c;
  int local_8;
  
  iVar4 = *(int *)(in_EAX + 8);
  uVar5 = 0;
  local_10 = param_5;
  local_c = local_c & 0xffffff00;
  local_14 = 1;
  local_18 = 0;
  iVar6 = iVar4;
  if (0 < *(int *)(in_EAX + 4)) {
    do {
      uVar2 = Ordinal_1252(iVar6,&local_8);
      switch(uVar2) {
      case 0x21:
        iVar6 = iVar6 + local_8;
        Ordinal_1252(iVar6,&local_8);
        local_18 = 1;
        break;
      default:
        local_10 = (undefined1 *)Ordinal_1247(local_10,uVar2);
        break;
      case 0x28:
        local_14 = 0;
        iVar3 = Ordinal_1252(local_8 + iVar6,&local_1c);
        if ((local_1c + local_8 == *(int *)(in_EAX + 4)) && (iVar3 == 0x2d)) {
          uVar2 = Ordinal_1855(param_2,0xffffffff,0);
          return uVar2;
        }
        break;
      case 0x2f:
        iVar6 = iVar6 + local_8;
        uVar1 = Ordinal_1252(iVar6,&local_8);
        local_c = CONCAT31((*(unsigned int *)((char *)&local_c + 1)),uVar1);
        break;
      case 0x3c:
        iVar6 = iVar6 + local_8;
        uVar2 = Ordinal_1252(iVar6,&local_8);
        switch(uVar2) {
        case 0x42:
          uVar5 = uVar5 | 1;
          break;
        case 0x49:
          uVar5 = uVar5 | 2;
          break;
        case 0x4f:
          uVar5 = uVar5 | 8;
          break;
        case 0x53:
          uVar5 = uVar5 | 0x10;
          break;
        case 0x55:
          uVar5 = uVar5 | 4;
        }
      }
      iVar6 = iVar6 + local_8;
    } while (iVar6 - iVar4 < *(int *)(in_EAX + 4));
  }
  *local_10 = 0;
  iVar4 = Ordinal_1855(param_2,param_5,local_c);
  if ((iVar4 != 0) &&
     (((byte)local_c == 0 ||
      (iVar4 = sprites_setTextFont(param_1,(byte)local_c,param_3,param_4,local_14), iVar4 != 0)))) {
    Ordinal_1859(param_2,param_4,local_14);
    Ordinal_1861(param_2,param_4,local_18);
    if (uVar5 != 0) {
      Ordinal_1864(param_2,param_4,uVar5);
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: sprites_setTextSize (FUN_6807e560)
// Address: 6807e560
// Size: 124 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setTextSize(int *param_1)
{
  int param_4;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    piVar2 = (int *)Ordinal_1114(*param_1);
    iVar4 = *piVar2 + -1;
    if (-1 < iVar4) {
      piVar3 = piVar2 + iVar4 * 3 + 3;
      do {
        Ordinal_1857(piVar3 + -2);
        if (-1 < *piVar3) {
          iVar1 = piVar3[-1];
          iVar5 = *piVar3 + (int)piVar2;
          while (iVar1 = iVar1 + -1, -1 < iVar1) {
            Ordinal_1113(iVar5);
            iVar5 = iVar5 + 4;
          }
        }
        iVar4 = iVar4 + -1;
        piVar3 = piVar3 + -3;
      } while (-1 < iVar4);
    }
    Ordinal_1115(*param_1);
    Ordinal_1113(param_1);
  }
  return 0;
}



// ============================================================
// Function: sprites_getTextStyle (FUN_6807e5e0)
// Address: 6807e5e0
// Size: 292 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getTextStyle(void)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_44 [4];
  int local_40;
  undefined1 local_30 [12];
  int local_24;
  undefined4 local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  iVar2 = *in_EAX * 3 + 3 + in_EAX[6];
  local_8 = 0;
  local_18 = 0;
  local_8 = Ordinal_1111(iVar2 * 4,1);
  if (local_8 != 0) {
    piVar1 = (int *)Ordinal_1114(local_8);
    *piVar1 = *in_EAX;
    piVar3 = piVar1 + (iVar2 - in_EAX[6]);
    local_1c = piVar1;
    sprites_getTextState(local_44);
    local_14 = *piVar1 + -1;
    if (-1 < local_14) {
      piVar1 = piVar1 + 2;
      do {
        *piVar1 = local_40;
        piVar1[1] = (int)piVar3 - (int)local_1c;
        local_10 = piVar1;
        sprites_getTextState(local_30);
        local_c = *piVar1;
        while (local_c = local_c + -1, -1 < local_c) {
          iVar2 = Ordinal_1111(local_24 + 1,0);
          *piVar3 = iVar2;
          if (iVar2 == 0) goto LAB_6807e6e5;
          iVar2 = Ordinal_1114(iVar2);
          if (local_24 != 0) {
            Ordinal_1128(iVar2,local_20,local_24);
          }
          *(undefined1 *)(iVar2 + local_24) = 0;
          Ordinal_1115(*piVar3);
          sprites_getTextState(local_30);
          piVar3 = piVar3 + 1;
          piVar1 = local_10;
        }
        sprites_getTextState(local_44);
        piVar1 = piVar1 + 3;
        local_14 = local_14 + -1;
        local_10 = piVar1;
      } while (-1 < local_14);
    }
    local_18 = 1;
LAB_6807e6e5:
    Ordinal_1115(local_8);
    if (local_18 != 0) {
      return local_8;
    }
  }
  sprites_setTextSize(&local_8);
  return local_8;
}



// ============================================================
// Function: sprites_setTextStyle (FUN_6807e710)
// Address: 6807e710
// Size: 487 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_setTextStyle(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined1 local_4c [20];
  undefined1 local_38 [12];
  uint local_2c;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  void *local_c;
  char *local_8;
  
  pvVar4 = (void *)*param_1;
  local_8 = (char *)0x0;
  local_10 = (int *)0x0;
  local_20 = 0;
  local_c = pvVar4;
  if ((*(byte *)(*(int *)(param_1[0xb] + 8) + 0x1c) & 4) == 0) {
    local_18 = Ordinal_1850();
    if (*(int *)((int)pvVar4 + 0x58) != 0) {
      Ordinal_1113((int)pvVar4 + 0x58);
    }
    iVar1 = Ordinal_1111(0,0);
    *(int *)((int)pvVar4 + 0x54) = iVar1;
    if ((iVar1 != 0) && (local_8 = (char *)Ordinal_1126(0x200,0), local_8 != (char *)0x0)) {
      piVar2 = (int *)Ordinal_1114(param_2);
      local_10 = piVar2;
      sprites_getTextState(local_38);
      piVar2 = piVar2 + 1;
      local_14 = 1;
      if (0 < *local_10) {
        do {
          sprites_getTextFont(0x200,local_2c,local_8);
          iVar1 = Ordinal_1854(local_18,local_8);
          *piVar2 = iVar1;
          if (iVar1 == 0) goto LAB_6807e8bb;
          sprites_getTextState(local_4c);
          iVar1 = 1;
          if (0 < piVar2[1]) {
            do {
              iVar3 = sprites_getTextSize(local_c,*piVar2,local_14,iVar1,local_8);
              pvVar4 = local_c;
              if (iVar3 == 0) goto LAB_6807e8bb;
              sprites_getTextState(local_4c);
              iVar1 = iVar1 + 1;
            } while (iVar1 <= piVar2[1]);
          }
          sprites_getTextState(local_38);
          local_14 = local_14 + 1;
          piVar2 = piVar2 + 3;
          pvVar4 = local_c;
        } while (local_14 <= *local_10);
      }
      iVar1 = Ordinal_54(param_1[8],&local_1c);
      if (iVar1 != 0) {
        local_24 = Ordinal_1852(local_1c);
        iVar1 = Ordinal_1851(local_1c,local_18);
        if (iVar1 != 0) {
          if (*(code **)(DAT_681962f8 + 0x84) != (code *)0x0) {
            (**(code **)(DAT_681962f8 + 0x84))(1);
          }
          *(undefined4 *)((int)pvVar4 + 0x58) = *(undefined4 *)((int)pvVar4 + 0x54);
          *(undefined4 *)((int)pvVar4 + 0x54) = 0;
          sprites_setTextSize((int *)((int)pvVar4 + 0x48));
          *(undefined4 *)((int)pvVar4 + 0x50) = 0;
          *(undefined4 *)((int)pvVar4 + 0x4c) = 0;
          Ordinal_1853(&local_24);
          local_20 = 1;
        }
      }
    }
  }
LAB_6807e8bb:
  Ordinal_1127(&local_8);
  if (local_10 != (int *)0x0) {
    Ordinal_1115(param_2);
  }
  iVar1 = local_20;
  if (local_20 == 0) {
    Ordinal_1113((int)pvVar4 + 0x54);
    sprites_setTextSize(&param_2);
  }
  return iVar1;
}



// ============================================================
// Function: sprites_initTextEditor (FUN_6807e900)
// Address: 6807e900
// Size: 536 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_initTextEditor(int *param_1,undefined4 *param_2)
{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined3 extraout_var;
  char *pcVar6;
  undefined3 extraout_var_00;
  int iVar7;
  undefined1 local_64 [4];
  undefined4 local_60;
  int local_50;
  int local_4c;
  undefined4 local_48 [4];
  undefined4 local_38;
  int local_30;
  undefined4 local_2c;
  char *local_28;
  undefined4 local_24;
  uint local_20 [2];
  undefined4 local_18;
  uint local_8;
  
  local_50 = *param_1;
  local_24 = 0;
  Ordinal_1130(&local_4c,0x28);
  uVar3 = lingo_destroyLifecycleData(*(int *)(param_1[0xb] + 8));
  if ((uVar3 & 4) == 0) {
    if ((*(code **)(DAT_681962f8 + 0x88) == (code *)0x0) ||
       (iVar4 = (**(code **)(DAT_681962f8 + 0x88))(), iVar4 != 0)) {
      local_20[0] = 0;
      local_18 = 1;
      uVar5 = Ordinal_362(param_1[8],param_1[10],param_2);
      Ordinal_294(param_1[8],param_1[10],uVar5,0x31,local_20);
      if ((local_20[0] != 0) && (iVar4 = Ordinal_1116(local_20[0]), iVar4 != 0)) {
        bVar2 = sprites_isTextMember((int)param_1);
        if (CONCAT31(extraout_var,bVar2) == 0) {
          iVar4 = Ordinal_1403(local_48,0);
          if (((iVar4 != 0) && (iVar4 = Ordinal_1425(local_48[0],0), iVar4 != 0)) &&
             (local_30 = Ordinal_1126(0x100,0), local_30 != 0)) {
            local_2c = Ordinal_1517(DAT_681956e0,0x962,local_30,0x100);
            pcVar6 = (char *)Ordinal_1114(local_20[0]);
            cVar1 = *pcVar6;
            local_28 = pcVar6;
            while (cVar1 != '\0') {
              bVar2 = sprites_getTextLineCount();
              if (CONCAT31(extraout_var_00,bVar2) == 0) {
                if (local_4c != 0) {
                  iVar4 = sprites_setTextAlignment((int)&local_4c);
                  goto LAB_6807ea69;
                }
              }
              else {
                iVar4 = sprites_setTextLineSpacing(&local_4c);
LAB_6807ea69:
                if (iVar4 == 0) goto LAB_6807eade;
              }
              pcVar6 = xtra_trimStringRight(pcVar6);
              cVar1 = *pcVar6;
            }
            if ((local_4c != 0) || (iVar4 = sprites_setTextLineSpacing(&local_4c), iVar4 != 0)) {
              sprites_getTextState(local_64);
              local_60 = local_38;
              sprites_setTextScrollPos(local_64);
              iVar4 = sprites_getTextStyle();
              if ((iVar4 != 0) && (iVar7 = sprites_setTextStyle(param_1,iVar4), iVar7 != 0)) {
                *(int *)(local_50 + 0x48) = iVar4;
                *(undefined4 *)(local_50 + 0x50) = 1;
                *(int **)(local_50 + 0x4c) = param_1;
                local_24 = 1;
              }
            }
          }
        }
        else {
          Ordinal_1780("Must have either Full Screen or Show Title Bar set to show user menus.",0,2,
                       1,0,1);
          local_24 = 1;
        }
      }
    }
    else {
      local_24 = 1;
    }
  }
  else {
    local_24 = 1;
  }
LAB_6807eade:
  Ordinal_1407(local_48);
  if (local_28 != (char *)0x0) {
    local_28 = (char *)Ordinal_1115(local_20[0]);
  }
  Ordinal_1127(&local_30);
  return 0;
}



// ============================================================
// Function: sprites_initTextState (FUN_6807eb20)
// Address: 6807eb20
// Size: 168 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_initTextState(int *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_8;
  
  piVar2 = param_1;
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x50) != 0) {
    sprites_setTextSize((int *)(iVar1 + 0x48));
    *(undefined4 *)(iVar1 + 0x50) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    iVar3 = *(int *)(*(int *)(piVar2[0xb] + 8) + 0x18);
    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0xc), iVar3 != 0)) {
      iVar3 = Ordinal_54(iVar3,&param_1);
      if (iVar3 != 0) {
        local_8 = Ordinal_1852(param_1);
        Ordinal_1851(param_1,0);
        if (*(code **)(DAT_681962f8 + 0x84) != (code *)0x0) {
          (**(code **)(DAT_681962f8 + 0x84))(0);
        }
        Ordinal_1853(&local_8);
        if (*(int *)(iVar1 + 0x54) != 0) {
          Ordinal_1113(iVar1 + 0x54);
        }
        if (*(int *)(iVar1 + 0x58) != 0) {
          Ordinal_1113(iVar1 + 0x58);
        }
      }
    }
  }
  return 0;
}




// ============================================================
// Function: sprites_destroyTextEditor (FUN_6807ebd0)
// Address: 6807ebd0
// Size: 113 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_destroyTextEditor(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  
  local_8 = -1;
  piVar1 = (int *)Ordinal_1114(param_1);
  if (piVar1 == (int *)0x0) {
    return -1;
  }
  iVar4 = 0;
  if (0 < *piVar1) {
    piVar3 = piVar1 + 1;
    while( true ) {
      iVar2 = Ordinal_1866(*piVar3);
      iVar4 = iVar4 + 1;
      local_8 = iVar4;
      if (iVar2 == param_2) break;
      piVar3 = piVar3 + 3;
      if (*piVar1 <= iVar4) {
        Ordinal_1115(param_1);
        return -1;
      }
    }
  }
  Ordinal_1115(param_1);
  return local_8;
}



// ============================================================
// Function: sprites_resetTextEditor (FUN_6807ec50)
// Address: 6807ec50
// Size: 123 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resetTextEditor(void)
{
  uint uVar1;
  int iVar2;
  
  iVar2 = Ordinal_1856();
  if (iVar2 != 0) {
    iVar2 = Ordinal_1862();
    if (iVar2 != 0) {
      props_listNoOp();
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_refreshTextDisplay (FUN_6807ecd0)
// Address: 6807ecd0
// Size: 240 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_refreshTextDisplay(int *param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int local_20 [6];
  void *local_8;
  
  piVar8 = param_1;
  local_8 = (void *)param_1[3];
  iVar1 = *param_1;
  bVar3 = sprites_isTextMember((int)param_1);
  if (CONCAT31(extraout_var,bVar3) != 0) {
    return 1;
  }
  iVar4 = sprites_destroyTextEditor(*(undefined4 *)(iVar1 + 0x48),param_2);
  iVar5 = sprites_getTextRange(iVar1,iVar4,(int *)&param_1);
  if (iVar5 != 0) {
    if ((param_3 < 1) || ((int)param_1 < param_3)) {
      sprites_resetTextEditor();
    }
    else {
      piVar6 = (int *)Ordinal_1114(*(undefined4 *)(iVar1 + 0x48));
      iVar4 = sprites_getTextChannelData(piVar6,iVar4);
      if (iVar4 != 0) {
        iVar4 = *(int *)(iVar4 + -4 + param_3 * 4);
        Ordinal_1115(*(undefined4 *)(iVar1 + 0x48));
        if (iVar4 == 0) {
          return 1;
        }
        local_20[0] = 0;
        local_20[1] = 0;
        local_20[2] = 0;
        local_20[3] = 0;
        local_20[4] = 0;
        local_20[5] = 0;
        uVar7 = Ordinal_1120(iVar4,0);
        Ordinal_360((int *)piVar8[8],(undefined4 ***)piVar8[10],5,(double *)local_20);
        pvVar2 = local_8;
        piVar8 = (int *)cast_invokeHandlerEx(local_8,local_20[0],uVar7,0,0);
        if (piVar8 == (int *)0x0) {
          return 1;
        }
        cast_resolveHandler((int)pvVar2,piVar8,0);
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchBehavior (FUN_6807edc0)
// Address: 6807edc0
// Size: 150 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_dispatchBehavior(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x58) == 0) {
    return 0;
  }
  if (*param_2 != 10) {
    return 0;
  }
  iVar1 = Ordinal_1116(*(int *)(param_1 + 0x58));
  piVar2 = (int *)Ordinal_1114(*(undefined4 *)(param_1 + 0x58));
  if (piVar2 != (int *)0x0) {
    if (0 < iVar1) {
      do {
        if ((((char)piVar2[2] == (char)param_2[6]) && ((*(byte *)(param_2 + 5) & 0x10) != 0)) &&
           (piVar2[3] != 0)) {
          *param_2 = 0x18;
          param_2[6] = *piVar2;
          param_2[7] = piVar2[1];
          uVar3 = 1;
          break;
        }
        iVar1 = iVar1 + -0x14;
        piVar2 = piVar2 + 5;
      } while (0 < iVar1);
    }
    if (piVar2 != (int *)0x0) {
      Ordinal_1115(*(undefined4 *)(param_1 + 0x58));
    }
  }
  return uVar3;
}



// ============================================================
// Function: sprites_handleTextEvent (FUN_6807ee60)
// Address: 6807ee60
// Size: 151 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_handleTextEvent(int param_1,int param_2)
{
  int iVar1;
  undefined1 local_b8 [4];
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac [38];
  undefined4 local_14;
  uint local_8;
  
  local_b0 = Ordinal_1258();
  xtra_appendToBuffer(param_1,local_ac,param_2 + -1);
  Ordinal_1259(local_14);
  iVar1 = xtra_setBufferPos(param_1,0);
  if (iVar1 != 0) {
    local_b4 = Ordinal_1114(iVar1);
    Ordinal_1251(local_b4,param_2 + local_b4,local_b8);
    Ordinal_1115(iVar1);
  }
  Ordinal_1259(local_b0);
  return 0;
}



// ============================================================
// Function: sprites_handleTextScroll (FUN_6807ef00)
// Address: 6807ef00
// Size: 164 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_handleTextScroll(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_ac [38];
  undefined4 local_14;
  uint local_8;
  
  iVar1 = xtra_getBufferSize(param_1);
  uVar2 = Ordinal_1258();
  xtra_appendToBuffer(param_1,local_ac,param_2);
  Ordinal_1259(local_14);
  iVar3 = xtra_setBufferPos(param_1,0);
  if (iVar3 != 0) {
    iVar4 = Ordinal_1114(iVar3);
    Ordinal_1250(param_2 + iVar4,1,iVar4 + iVar1);
    Ordinal_1115(iVar3);
  }
  Ordinal_1259(uVar2);
  return 0;
}



// ============================================================
// Function: sprites_processScrollInput (FUN_6807efb0)
// Address: 6807efb0
// Size: 43 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_processScrollInput(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x78) != 0)) &&
     (*(code **)(param_1 + 0x84) != (code *)0x0)) {
    uVar1 = (**(code **)(param_1 + 0x84))(param_1,param_2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: sprites_updateTextCursor (FUN_6807efe0)
// Address: 6807efe0
// Size: 216 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_updateTextCursor(int param_1)
{
  int iVar1;
  int *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_18 [4];
  uint local_8;
  
  local_5c = Ordinal_1600();
  if (local_5c != 0) {
    media_resolveAsset(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),*(int *)(unaff_ESI + 0x7c),
                 param_1,1);
    Ordinal_374(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),*(int *)(unaff_ESI + 0x7c),0xd
                ,(double *)&local_58);
    xtra_processTextRun(local_5c,unaff_EBX,param_1,local_18);
    Ordinal_1064(local_18,local_58,local_54);
    iVar1 = Ordinal_1066(local_18,local_18,&local_58);
    if (iVar1 == 0) {
      Ordinal_1839(*(undefined4 *)(unaff_EDI + 4),0);
    }
    else {
      Ordinal_1839(*(undefined4 *)(unaff_EDI + 4),local_18);
      media_resolveAsset(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),*(int *)(unaff_ESI + 0x7c),
                   param_1,1);
    }
    Ordinal_1601(&local_5c);
  }
  return 0;
}



// ============================================================
// Function: sprites_renderTextOverlay (FUN_6807f0c0)
// Address: 6807f0c0
// Size: 200 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_renderTextOverlay(int param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_b0;
  undefined4 local_ac [38];
  undefined4 local_14;
  uint local_8;
  
  if (0 < param_2) {
    local_b0 = 0;
    uVar1 = Ordinal_1258();
    iVar2 = xtra_setBufferPos(param_1,0);
    xtra_appendToBuffer(param_1,local_ac,param_2 + -1);
    Ordinal_1259(local_14);
    iVar3 = Ordinal_1114(iVar2);
    Ordinal_1251(iVar3,param_2 + iVar3,&local_b0);
    uVar4 = Ordinal_1252((param_2 - local_b0) + iVar3,&local_b0);
    Ordinal_1253(uVar4);
    Ordinal_1115(iVar2);
    Ordinal_1259(uVar1);
  }
  return 0;
}



// ============================================================
// Function: sprites_getTextProperty (FUN_6807f190)
// Address: 6807f190
// Size: 406 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextProperty(undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBX;
  int *unaff_ESI;
  int unaff_EDI;
  uint local_7c;
  int local_78;
  int local_74;
  undefined8 local_70;
  int local_64;
  uint local_30 [6];
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar1 = Ordinal_294(*(int *)(unaff_EDI + 0x20),*(int *)(unaff_EDI + 0x80),param_1,0x65,local_30);
  if ((iVar1 != 0) && (local_30[0] == 1)) {
    iVar2 = xtra_drawTextBlock(unaff_EBX,(int)unaff_ESI,0,1,32000);
    local_74 = xtra_setTextProperty(unaff_EBX,(int)unaff_ESI,param_2);
    Ordinal_374(*(int *)(unaff_EDI + 0x20),*(int *)(unaff_EDI + 0x80),*(int *)(unaff_EDI + 0x7c),0xd
                ,(double *)&local_70);
    local_78 = local_64 - (*(unsigned int *)((char *)&local_70 + 4));
    xtra_processTextRun(unaff_EBX,unaff_ESI,param_2,&local_18);
    iVar1 = local_c;
    if (local_78 < local_c) {
      while( true ) {
        media_resolveAssetEx(*(int *)(unaff_EDI + 0x20),*(byte **)(unaff_EDI + 0x28),param_1,0,0,1);
        iVar3 = xtra_layoutTextBlock(unaff_EBX,(int)unaff_ESI,0,0,(int *)0x0,&local_7c);
        if (iVar3 == -1) {
          local_7c = 0;
        }
        iVar3 = local_7c + 1;
        if (((iVar3 < iVar2 + 1) || (iVar4 = iVar2, iVar3 <= (int)local_7c)) &&
           (iVar4 = iVar3, iVar3 < 0)) {
          iVar4 = 0;
        }
        xtra_getLineYOffset(unaff_EBX,(int)unaff_ESI,iVar4,&local_74);
        xtra_isTextFormat((int)unaff_ESI,local_74);
        xtra_processTextRun(unaff_EBX,unaff_ESI,param_2,&local_18);
        if (iVar1 == local_c) break;
        if (local_c <= local_78) {
          return 0;
        }
      }
    }
    else if (local_14 < 0) {
      media_resolveAssetEx(*(int *)(unaff_EDI + 0x20),*(byte **)(unaff_EDI + 0x28),param_1,3,0,local_74);
    }
    return 0;
  }
  return 0;
}




// ============================================================
// Function: sprites_getTextPropertyEx (FUN_6807f330)
// Address: 6807f330
// Size: 405 bytes
// Params: undefined4 param_1, int param_2, int param_3, int * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getTextPropertyEx(undefined4 param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  undefined4 uVar1;
  uint extraout_EDX;
  uint uVar2;
  uint extraout_EDX_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = 0;
  local_c = 1;
  uVar5 = 0;
  local_10 = xtra_getBufferSize(param_2);
  if ((param_4 != (int *)0x0) && (param_5 != (int *)0x0)) {
    *param_5 = param_3;
    local_18 = xtra_setBufferPos(param_2,0);
    local_8 = Ordinal_1114(local_18);
    if ((param_3 <= local_10) && (-1 < param_3)) {
      if (0 < local_10) {
        do {
          uVar1 = Ordinal_1252(local_8,&local_14);
          Ordinal_1253(uVar1);
          iVar4 = local_10;
          uVar2 = 0;
          if ((extraout_EDX & 0xb0200000) == 0) {
LAB_6807f3ea:
            if (local_c == 0) {
              if (param_3 <= iVar3) {
                *param_5 = iVar3;
              }
            }
            else {
              *param_4 = iVar3;
            }
            local_c = 0;
            iVar4 = local_10;
          }
          else {
            if (iVar3 == param_3) {
              if ((extraout_EDX & 0xc00000) != 0) goto LAB_6807f3ea;
              *param_4 = iVar3;
              *param_5 = iVar3;
              break;
            }
            if (param_3 < iVar3) {
              if (((uVar5 & 0x800000) != 0) || ((extraout_EDX & 0x400000) != 0)) goto LAB_6807f3ea;
              break;
            }
            if (local_14 + iVar3 < local_10) {
              uVar1 = Ordinal_1252(local_14 + local_8,local_1c);
              Ordinal_1253(uVar1);
              uVar2 = extraout_EDX_00;
            }
            if (((extraout_EDX & 0x800000) != 0) || ((uVar2 & 0x400000) != 0)) goto LAB_6807f3ea;
            local_c = 1;
          }
          if (iVar4 <= iVar3) break;
          local_8 = local_8 + local_14;
          iVar3 = iVar3 + local_14;
          uVar5 = extraout_EDX;
        } while (iVar3 < iVar4);
      }
      iVar3 = sprites_handleTextScroll(param_2,*param_5);
      *param_5 = iVar3;
      if (local_8 != 0) {
        Ordinal_1115(local_18);
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getTextInfo (FUN_6807f4d0)
// Address: 6807f4d0
// Size: 45 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextInfo(undefined4 param_1)
{
  int unaff_ESI;
  
  Ordinal_293(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),param_1,10,(uint *)0x0);
  Ordinal_104(*(int *)(unaff_ESI + 0x20),0x1000);
  return 0;
}



// ============================================================
// Function: sprites_getTextBounds (FUN_6807f500)
// Address: 6807f500
// Size: 154 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_getTextBounds(int param_1)
{
  int iVar1;
  undefined4 local_48 [16];
  uint local_8;
  
  Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),2,
              (double *)local_48);
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  media_registerAssetWithData(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),local_48[0],(void *)0x0,
               (void *)0x0);
  media_resolveAsset(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),0,0);
  iVar1 = scoreEngine_setPropertyFloat(*(int *)(param_1 + 0x20),(short)local_48[0]);
  if (iVar1 != 0) {
    sprites_getTextInfo(local_48[0]);
  }
  return 0;
}



// ============================================================
// Function: sprites_setTextBounds (FUN_6807f5a0)
// Address: 6807f5a0
// Size: 157 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setTextBounds(undefined4 param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  uint local_20 [6];
  uint local_8;
  
  uVar2 = Ordinal_363(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),(short)param_1);
  puVar1 = (undefined4 *)(unaff_ESI + 0x98);
  uVar3 = Ordinal_362(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),puVar1);
  if ((((short)uVar3 != (short)param_1) || ((short)((uint)uVar3 >> 0x10) != (*(unsigned short *)((char *)&param_1 + 2)))) &&
     (*puVar1 = uVar2, *(short *)(unaff_ESI + 0x9a) != -1)) {
    Ordinal_294(*(int *)(unaff_ESI + 0x20),param_2,param_1,2,local_20);
    if (local_20[0] != 3) {
      *(undefined2 *)puVar1 = 0xffff;
      *(undefined2 *)(unaff_ESI + 0x9a) = 0xffff;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getTextBoxSize (FUN_6807f640)
// Address: 6807f640
// Size: 131 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_getTextBoxSize(void *this,int param_1)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_8;
  
  xtra_getCharPosition(param_1,(int)this,*(int *)(unaff_EDI + 4) + *(int *)(unaff_ESI + 0x780),&local_50);
  Ordinal_374(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),*(int *)(unaff_ESI + 0x7c),0xd,
              (double *)&local_48);
  iVar1 = *(int *)(unaff_ESI + 0x7c8);
  *(int *)(unaff_EDI + 0x18) = local_4c + local_44 + 2;
  *(int *)(unaff_EDI + 0x10) = ((local_4c + local_44) - iVar1) + -2;
  *(int *)(unaff_EDI + 0x14) = local_50 + local_48;
  *(int *)(unaff_EDI + 0x1c) =
       *(int *)(unaff_EDI + 4) + local_50 + local_48 + *(int *)(unaff_ESI + 0x780);
  return 0;
}



// ============================================================
// Function: sprites_setTextBoxSize (FUN_6807f6d0)
// Address: 6807f6d0
// Size: 146 bytes
// Params: void * this, undefined4 param_1, undefined4 param_2, void * param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall
sprites_setTextBoxSize(void *this,undefined4 param_1,undefined4 param_2,void *param_3,int param_4,int param_5)
{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = in_EAX - (int)param_3;
  iVar1 = xtra_getBufferSize(param_4);
  if ((iVar1 != 0) && (0 < iVar2)) {
    media_registerAssetWithData(*(int *)((int)this + 0x20),*(byte **)((int)this + 0x80),param_2,param_3,param_3);
    xtra_deleteBufferRange(param_4,(int)param_3,iVar2);
    xtra_deleteBufferRange(param_5,(int)param_3,iVar2);
    Ordinal_293(*(int *)((int)this + 0x20),*(int *)((int)this + 0x80),param_2,10,(uint *)0x0);
    sprites_getTextProperty(param_2,(int)param_3);
    media_resolveAsset(*(int *)((int)this + 0x20),*(int *)((int)this + 0x80),*(int *)((int)this + 0x7c),
                 (int)param_3,1);
  }
  return 0;
}



// ============================================================
// Function: sprites_handleEditCommand (FUN_6807f770)
// Address: 6807f770
// Size: 870 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_handleEditCommand(int param_1,int *param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *local_94;
  void *local_90;
  int local_8c;
  int local_88;
  int local_84;
  void *local_80;
  void *local_7c;
  int local_78;
  int *local_74;
  uint local_70;
  int local_6c;
  undefined8 local_58;
  int local_50;
  int local_4c;
  int local_18 [4];
  uint local_8;
  
  local_74 = (int *)0x0;
  local_78 = 0;
  local_8c = 0;
  local_78 = Ordinal_1600();
  iVar2 = Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),2,
                      (double *)&local_58);
  iVar3 = (int)local_58;
  if (iVar2 == 0) goto LAB_6807faaa;
  local_88 = (int)local_58;
  iVar2 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),(int)local_58,0x70,&local_70
                     );
  uVar1 = local_70;
  if (iVar2 == 0) goto LAB_6807faaa;
  local_74 = (int *)local_6c;
  iVar2 = xtra_getBufferSize(local_6c);
  local_74 = (int *)xtra_insertIntoBuffer((int)local_74,0,iVar2);
  iVar2 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),iVar3,0x65,&local_70);
  if (iVar2 == 0) goto LAB_6807faaa;
  if (local_70 == 1) {
    local_8c = 1;
  }
  local_84 = media_lookupAsset(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),iVar3);
  iVar2 = *param_2;
  if ((iVar2 == 1) || (iVar2 == 5)) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    media_getAssetData(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),iVar3,&local_7c,&local_80);
    if (local_7c == (void *)0x0 && local_80 == (void *)0x0) {
      if (-1 < local_84) {
        xtra_processTextRun(local_78,local_74,local_84,local_18);
        Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),0xd,
                    (double *)&local_58);
        Ordinal_1064(local_18,(int)local_58,(*(unsigned int *)((char *)&local_58 + 4)));
        iVar2 = Ordinal_1066(local_18,local_18,&local_58);
        if (iVar2 != 0) {
          Ordinal_1839(param_2[1],local_18);
          media_resolveAsset(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),
                       local_84,1);
          *(code **)(param_1 + 0x84) = scoreEngine_stepPlayback;
          goto LAB_6807faa4;
        }
        Ordinal_1839(param_2[1],0);
      }
      *(code **)(param_1 + 0x84) = scoreEngine_stepPlayback;
    }
    else {
      if ((int)local_80 < local_84) {
        media_registerAsset(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),iVar3,(int)local_80);
      }
      *(code **)(param_1 + 0x84) = scoreEngine_initPlayback;
    }
  }
  else {
    if (iVar2 != 9) goto LAB_6807faaa;
    iVar3 = param_2[2];
    iVar2 = param_2[3];
    Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),0xd,
                (double *)&local_58);
    if (iVar3 < local_50) {
      if (iVar3 < (int)local_58) {
        iVar3 = (int)local_58 + 1;
      }
    }
    else {
      iVar3 = local_50 + -1;
    }
    if (iVar2 < local_4c) {
      if (iVar2 < (*(unsigned int *)((char *)&local_58 + 4))) {
        if (local_8c != 0) {
          media_resolveAssetEx(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x28),local_88,0,1,1);
        }
        iVar2 = (*(unsigned int *)((char *)&local_58 + 4)) + 1;
      }
    }
    else {
      if (local_8c != 0) {
        media_resolveAssetEx(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x28),local_88,0,0,1);
      }
      iVar2 = local_4c + -1;
    }
    iVar2 = xtra_layoutTextRun(local_78,(int)local_74,iVar3 - (int)local_58,iVar2 - (*(unsigned int *)((char *)&local_58 + 4)),
                         (uint *)0x0,0,0);
    iVar3 = local_88;
    iVar2 = sprites_getTextPropertyEx(local_88,uVar1,iVar2,(int *)&local_7c,(int *)&local_80);
    if (iVar2 == 0) goto LAB_6807faaa;
    if ((int)local_80 < (int)*(void **)(param_1 + 0x90)) {
      local_80 = *(void **)(param_1 + 0x90);
    }
    if ((int)*(void **)(param_1 + 0x8c) < (int)local_7c) {
      local_7c = *(void **)(param_1 + 0x8c);
    }
    media_getAssetData(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),iVar3,&local_90,&local_94);
    if ((local_7c == local_90) && (local_80 == local_94)) goto LAB_6807faaa;
    media_registerAssetWithData(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),iVar3,local_7c,local_80);
  }
LAB_6807faa4:
  sprites_getTextInfo(iVar3);
LAB_6807faaa:
  if (local_78 != 0) {
    Ordinal_1601(&local_78);
  }
  xtra_resetBuffer((int)local_74);
  return 0;
}



// ============================================================
// Function: sprites_processEditMenu (FUN_6807fae0)
// Address: 6807fae0
// Size: 604 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_processEditMenu(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9)
{
  int iVar1;
  int iVar2;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_20 [6];
  uint local_8;
  
  local_70 = param_2;
  local_64 = param_4;
  local_68 = param_5;
  local_78 = param_6;
  iVar1 = xtra_getBufferSize(param_4);
  local_6c = iVar1;
  iVar2 = Ordinal_1263(param_6,0xffffffff);
  if (-1 < iVar2) {
    local_74 = media_lookupAsset(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),param_3);
    iVar2 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),param_3,0x65,local_20);
    if (iVar2 != 0) {
      if (param_8 < 0) {
        param_8 = 0;
      }
      else if (iVar1 < param_8) {
        param_8 = iVar1;
      }
      xtra_insertBufferData(local_64,local_78,param_7,param_8);
      xtra_insertBufferData(local_68,local_78,param_7,param_8);
      if (*(int *)(param_1 + 0x9c) != 0) {
        xtra_copyBufferRange(local_64,(undefined4 *)(param_1 + 0xa0),param_8,param_7);
        xtra_copyBufferRange(local_68,(undefined4 *)(param_1 + 0xa0),param_8,param_7);
        *(undefined4 *)(param_1 + 0x9c) = 0;
      }
      Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),param_3,10,(uint *)0x0);
      local_6c = local_6c + param_7;
      if (local_20[0] == 3) {
        Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),0xd,
                    (double *)&local_60);
        local_78 = xtra_countVisibleLines(local_70,local_64,0,1,local_54 - local_5c);
        if (local_78 == 0) {
          local_78 = 1;
        }
        iVar1 = xtra_setTextProperty(local_70,local_64,local_6c);
        if ((local_78 < iVar1 + 1) ||
           (((iVar1 + 1 == local_78 &&
             (iVar1 = xtra_getCharPosition(local_70,local_68,local_6c,&local_7c), iVar1 != 0)) &&
            (local_58 - local_60 < local_7c)))) {
          xtra_deleteBufferRange(local_64,param_8,param_7);
          xtra_deleteBufferRange(local_68,param_8,param_7);
          Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),param_3,10,(uint *)0x0);
          goto LAB_6807fca8;
        }
      }
      local_64 = 1;
      if (((-1 < param_8) && (param_8 <= local_6c)) && (param_9 != 0)) {
        iVar1 = local_74 + param_7;
        local_74 = iVar1;
        media_registerAsset(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),param_3,iVar1);
        sprites_getTextProperty(param_3,iVar1);
        media_resolveAsset(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),
                     local_74,1);
        sprites_getTextInfo(param_3);
        return 0;
      }
    }
  }
LAB_6807fca8:
  return 0;
}




// ============================================================
// Function: sprites_buildEditMenu (FUN_6807fd40)
// Address: 6807fd40
// Size: 157 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_buildEditMenu(void)
{
  int param_4;
  int local_14;
  int unaff_ESI;
  int unaff_EDI;
  /* FIXUP(C2040: 'local_14': 'int): int local_14 [4]; */
  
  if (*(int *)(unaff_ESI + 0x78) != 0) {
    if (*(int *)(unaff_ESI + 0x78) == 3) {
      if (unaff_EDI == 0) {
        scoreEngine_readProperty(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),
                     *(int *)(unaff_ESI + 0x7c),0xc);
      }
      *(undefined4 *)(unaff_ESI + 0x88) = 0;
      *(undefined4 *)(unaff_ESI + 0x84) = 0;
    }
    else {
      sprites_getTextBounds(unaff_ESI);
    }
    ((int *)(size_t)local_14)[ /* FIXUP(C2109): cast to pointer for subscript */2] = 0;
    ((int *)(size_t)local_14)[ /* FIXUP(C2109): cast to pointer for subscript */1] = 0;
    ((int *)(size_t)local_14)[ /* FIXUP(C2109): cast to pointer for subscript */0] = 0;
    events_getWindowInfo(*(int *)(unaff_ESI + 0xc),*(int *)(unaff_ESI + 0x7c),local_14);
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
    if (unaff_EDI == 0xdead) {
      *(undefined4 *)(unaff_ESI + 0x7c) = 0;
    }
    *(undefined2 *)(unaff_ESI + 0x98) = 0xffff;
    *(undefined2 *)(unaff_ESI + 0x9a) = 0xffff;
  }
  return 0;
}



// ============================================================
// Function: sprites_enableEditMenu (FUN_6807fde0)
// Address: 6807fde0
// Size: 209 bytes
// Params: void * this, int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_enableEditMenu(void *this,int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_ac [41];
  uint local_8;
  
  iVar1 = xtra_getBufferSize(unaff_EDI);
  if (iVar1 == 0) {
    xtra_appendToBuffer(unaff_EDI,local_ac,0);
    xtra_replaceBufferRange(unaff_EDI,unaff_EBX,param_3,local_ac);
    xtra_replaceBufferRange((int)this,unaff_EBX,param_3,local_ac);
    Ordinal_293(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x80),param_2,10,(uint *)0x0);
    return 0;
  }
  iVar1 = media_lookupAsset(*(int *)(unaff_ESI + 0x20),*(byte **)(unaff_ESI + 0x80),param_2);
  sprites_processEditMenu(unaff_ESI,param_1,param_2,unaff_EDI,(int)this,unaff_EBX,param_3,iVar1,0);
  return 0;
}



// ============================================================
// Function: sprites_getEditMenuState (FUN_6807fec0)
// Address: 6807fec0
// Size: 92 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getEditMenuState(int param_1,undefined4 param_2)
{
  int in_EAX;
  int unaff_EBX;
  
  if (((*(int *)(in_EAX + 0x78) != 3) || (*(int *)(in_EAX + 0x7c) != param_1)) ||
     (*(int *)(in_EAX + 0x80) != unaff_EBX)) {
    if (*(int *)(in_EAX + 0x78) != 0) {
      sprites_buildEditMenu();
    }
    sprites_setTextBounds(param_2,unaff_EBX);
    *(int *)(in_EAX + 0x7c) = param_1;
    *(undefined4 *)(in_EAX + 0x78) = 3;
    *(int *)(in_EAX + 0x80) = unaff_EBX;
    scoreEngine_readProperty(*(int *)(in_EAX + 0x20),unaff_EBX,param_1,0xb);
  }
  return 0;
}



// ============================================================
// Function: sprites_setCursorVisible (FUN_6807ff20)
// Address: 6807ff20
// Size: 59 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setCursorVisible(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x78) != 0) {
    iVar1 = scoreEngine_writeProperty(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),
                         *(undefined4 *)(param_1 + 0x7c),0);
    if ((iVar1 == 0) || (param_2 != 0)) {
      sprites_buildEditMenu();
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getTextCaretPos (FUN_6807ff60)
// Address: 6807ff60
// Size: 24 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getTextCaretPos(void)
{
  sprites_buildEditMenu();
  return 0;
}



// ============================================================
// Function: sprites_setTextCaretPos (FUN_6807ff80)
// Address: 6807ff80
// Size: 1227 bytes
// Params: void * param_1, int param_2, undefined4 param_3, int param_4, void * param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setTextCaretPos(void *param_1,int param_2,undefined4 param_3,int param_4,void *param_5,int param_6
                 )
{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  void *pvVar7;
  bool bVar8;
  undefined4 local_ac [20];
  uint local_5c;
  uint local_8;
  
  if (*(int *)((int)param_1 + 0x77c) == 0) {
    if (*(int *)(param_6 + 0x24) == 0) {
LAB_680802b8:
      pcVar5 = *(char **)(param_6 + 0x20);
      if (pcVar5 != (char *)0x0) {
        pcVar1 = pcVar5 + 1;
        do {
          cVar3 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar3 != '\0');
        piVar2 = (int *)((int)param_1 + 0x780);
        media_getAssetData(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),param_3,piVar2,
                     (undefined4 *)((int)param_1 + 0x784));
        if ((*piVar2 == 0) && (*(int *)((int)param_1 + 0x784) == 0)) {
          iVar4 = media_lookupAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3
                              );
          *(int *)((int)param_1 + 0x784) = iVar4;
          *piVar2 = iVar4;
        }
        pvVar7 = (void *)(*piVar2 + ((int)pcVar5 - (int)pcVar1));
        sprites_enableEditMenu(param_5,param_2,param_3,(int)pcVar5 - (int)pcVar1);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3,pvVar7,
                     pvVar7);
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3,
                     (int)pvVar7);
        media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                     *(int *)((int)param_1 + 0x7c),(int)pvVar7,1);
        sprites_getTextProperty(param_3,(int)pvVar7);
        sprites_getTextInfo(param_3);
        return 0;
      }
    }
    else {
      piVar2 = (int *)((int)param_1 + 0x780);
      *(undefined4 *)((int)param_1 + 0x77c) = 1;
      media_getAssetData(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),param_3,piVar2,
                   (undefined4 *)((int)param_1 + 0x784));
      if ((*piVar2 == 0) && (*(int *)((int)param_1 + 0x784) == 0)) {
        iVar4 = media_lookupAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3);
        *(int *)((int)param_1 + 0x784) = iVar4;
        *piVar2 = iVar4;
      }
      xtra_appendToBuffer(param_4,(undefined4 *)((int)param_1 + 0x788),*piVar2);
    }
  }
  else {
    pcVar5 = *(char **)(param_6 + 0x20);
    if (pcVar5 != (char *)0x0) {
      pcVar1 = pcVar5 + 1;
      do {
        cVar3 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar3 != '\0');
      iVar4 = (int)pcVar5 - (int)pcVar1;
      pvVar7 = (void *)((int)*(void **)((int)param_1 + 0x780) + iVar4);
      sprites_setTextBoxSize(param_1,param_2,param_3,*(void **)((int)param_1 + 0x780),param_4,(int)param_5);
      sprites_enableEditMenu(param_5,param_2,param_3,iVar4);
      xtra_copyBufferRange(param_4,(undefined4 *)((int)param_1 + 0x788),*(int *)((int)param_1 + 0x780),iVar4
                  );
      xtra_copyBufferRange((int)param_5,(undefined4 *)((int)param_1 + 0x788),*(int *)((int)param_1 + 0x780),
                   iVar4);
      media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3,pvVar7,
                   pvVar7);
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3,(int)pvVar7
                  );
      media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                   *(int *)((int)param_1 + 0x7c),(int)pvVar7,1);
      sprites_getTextProperty(param_3,(int)pvVar7);
      sprites_getTextInfo(param_3);
      *(undefined4 *)((int)param_1 + 0x784) = 0;
      *(undefined4 *)((int)param_1 + 0x780) = 0;
      *(undefined4 *)((int)param_1 + 0x77c) = 0;
      if (*(int *)(param_6 + 0x24) != 0) {
        sprites_setTextCaretPos(param_1,param_2,param_3,param_4,param_5,param_6);
        return 0;
      }
      goto LAB_68080438;
    }
    if (*(int *)((int)param_1 + 0x77c) == 0) goto LAB_680802b8;
  }
  pcVar5 = *(char **)(param_6 + 0x24);
  if (pcVar5 != (char *)0x0) {
    pcVar1 = pcVar5 + 1;
    do {
      cVar3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar3 != '\0');
    iVar6 = (int)pcVar5 - (int)pcVar1;
    sprites_setTextBoxSize(param_1,param_2,param_3,*(void **)((int)param_1 + 0x780),param_4,(int)param_5);
    sprites_enableEditMenu(param_5,param_2,param_3,iVar6);
    xtra_appendToBuffer(param_4,local_ac,*(int *)((int)param_1 + 0x780));
    local_5c = local_5c | 0x100;
    xtra_copyBufferRange(param_4,local_ac,*(int *)((int)param_1 + 0x780),iVar6);
    xtra_copyBufferRange((int)param_5,local_ac,*(int *)((int)param_1 + 0x780),iVar6);
    media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3,
                 (void *)(*(int *)(param_6 + 8) + *(int *)((int)param_1 + 0x780)),
                 (void *)(*(int *)(param_6 + 0xc) + *(int *)((int)param_1 + 0x780)));
    iVar4 = *(int *)(param_6 + 8);
    bVar8 = iVar4 == *(int *)(param_6 + 0xc);
    if (!bVar8) {
      iVar4 = iVar6;
    }
    iVar4 = *(int *)((int)param_1 + 0x780) + iVar4;
    media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),param_3,iVar4);
    media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                 *(int *)((int)param_1 + 0x7c),iVar4,(uint)bVar8);
    sprites_getTextProperty(param_3,iVar4);
    sprites_getTextInfo(param_3);
    *(int *)((int)param_1 + 0x784) = *(int *)((int)param_1 + 0x780) + iVar6;
  }
LAB_68080438:
  return 0;
}



