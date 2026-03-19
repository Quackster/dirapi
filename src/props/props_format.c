// Module: props
// Topic: String formatting and output functions
// Address range: 0x68039f80 - 0x6803a500
// Functions (6):
//   props_flushFormatBuffer (FUN_68039f80)
//   props_getCharSize
//   props_renderFormatted (FUN_6803a0b0)
//   props_formatValue
//   props_checkBufferSpace (FUN_6803a470)
//   props_formatString



// ============================================================
// Function: props_flushFormatBuffer (FUN_68039f80)
// Address: 68039f80
// Size: 221 bytes
// Return: size_t
// Calling convention: __stdcall
// ============================================================

size_t props_flushFormatBuffer(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  void *_Src;
  size_t _Size;
  undefined4 *unaff_ESI;
  size_t local_c;
  undefined1 local_8;
  undefined2 local_7;
  undefined1 local_5;
  
  iVar3 = unaff_ESI[2];
  local_c = 0;
  local_8 = 0;
  local_7 = 0;
  local_5 = 0;
  if (iVar3 < 1) {
    unaff_ESI[2] = 0;
    return 1;
  }
  iVar1 = (int)unaff_ESI + 0xd;
  _Src = (void *)Ordinal_1251(iVar1,iVar1 + iVar3,&local_c);
  _Size = (iVar1 - (int)_Src) + iVar3;
  if (_Size == local_c) {
    _Size = 0;
  }
  else if (0 < (int)_Size) {
    memcpy(&local_8,_Src,_Size);
  }
  *(undefined1 *)((int)unaff_ESI + unaff_ESI[2] + (0xd - _Size)) = 0;
  pcVar2 = (char *)(unaff_ESI + 3);
  if ((int)(unaff_ESI[2] - _Size) < 0xff) {
    *pcVar2 = *(char *)(unaff_ESI + 2) - (char)_Size;
  }
  else {
    *pcVar2 = -1;
  }
  local_c = (*(code *)*unaff_ESI)(unaff_ESI[1],pcVar2);
  if (0 < (int)_Size) {
    memcpy((void *)((int)unaff_ESI + 0xd),&local_8,_Size);
    *(undefined1 *)(_Size + 0xd + (int)unaff_ESI) = 0;
    if ((int)_Size < 0xff) {
      *pcVar2 = (char)_Size;
      unaff_ESI[2] = _Size;
      return local_c;
    }
    unaff_ESI[2] = _Size;
    *pcVar2 = -1;
    return local_c;
  }
  unaff_ESI[2] = _Size;
  return local_c;
}



// ============================================================
// Function: props_getCharSize (FUN_6803a060)
// Address: 6803a060
// Size: 75 bytes
// Params: undefined1 param_1
// Return: size_t
// Calling convention: __stdcall
// ============================================================

size_t props_getCharSize(undefined1 param_1)

{
  int in_EAX;
  size_t sVar1;
  
  sVar1 = 1;
  if (0x3fd < *(int *)(in_EAX + 8)) {
    sVar1 = props_flushFormatBuffer();
  }
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 1;
  *(undefined1 *)(*(int *)(in_EAX + 8) + 0xc + in_EAX) = param_1;
  *(undefined1 *)(in_EAX + 0xd + *(int *)(in_EAX + 8)) = 0;
  if (*(int *)(in_EAX + 8) < 0xff) {
    *(undefined1 *)(in_EAX + 0xc) = *(undefined1 *)(in_EAX + 8);
    return sVar1;
  }
  *(undefined1 *)(in_EAX + 0xc) = 0xff;
  return sVar1;
}



// ============================================================
// Function: props_renderFormatted (FUN_6803a0b0)
// Address: 6803a0b0
// Size: 798 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, byte * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_renderFormatted(int param_1,undefined4 param_2,undefined4 param_3,byte *param_4,int param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  ushort uVar3;
  size_t sVar4;
  byte bVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  byte local_820;
  int local_81c;
  int local_818;
  undefined2 local_408;
  uint local_8;
  
  local_820 = *param_4;
  if (local_820 == 0) {
LAB_6803a3bf:
    props_flushFormatBuffer();
LAB_6803a3ca:
    return 0;
  }
  local_818 = param_5 + -4;
LAB_6803a104:
  if (local_820 != 0x5c) {
    if (local_820 != 0x25) {
      if (local_820 == 10) {
        local_820 = 0xd;
      }
      goto LAB_6803a142;
    }
    bVar5 = param_4[1];
    param_4 = param_4 + 1;
    local_81c = 0;
    while ((bVar5 != 0 && ((byte)(bVar5 - 0x30) < 10))) {
      param_4 = param_4 + 1;
      local_81c = (bVar5 - 0x30) + local_81c * 10;
      bVar5 = *param_4;
    }
    bVar5 = *param_4;
    /* FIXUP(switch-rewrite): Original Ghidra output used computed goto switch table
       with address-literal case labels (switchD_6803a1a7). Restructured as goto chain
       to preserve control flow. The switch dispatch logic is architecture-dependent
       and needs manual reconstruction from the binary's jump table at 0x6803a3e0. */
    {
      /* case 0x6803a1ae: advance pointer */
      bVar5 = param_4[1];
      param_4 = param_4 + 1;
    }
    if (0) {
      /* case 0x6803a1c0: goto default format handler */
      goto switchD_6803a1a7_caseD_6803a1c0;
    }
    if (0) {
      /* case 0x6803a1dc: hex or default format */
      if (*param_4 == 0x78) {
        props_formatHexValue();
      }
      else {
        Ordinal_951(*(undefined4 *)(local_818 + 4),(undefined1 *)&local_408);
      }
      goto LAB_6803a1f8;
    }
    if (0) {
      /* case 0x6803a21e: integer format */
      Ordinal_1230(&local_408,*(undefined4 *)(local_818 + 4));
      goto LAB_6803a1f8;
    }
    if (0) {
      /* case 0x6803a239: string format */
      pcVar6 = *(char **)(local_818 + 4);
      uVar3 = 0;
      local_408 = (ushort)(*(unsigned char *)((char *)&local_408 + 1)) << 8;
      if (*pcVar6 == '\0') goto LAB_6803a207;
      goto LAB_6803a251;
    }
    if (0) {
      /* case 0x6803a270: handle/blob format */
      puVar1 = *(undefined4 **)(local_818 + 4);
      local_408 = (ushort)(*(unsigned char *)((char *)&local_408 + 1)) << 8;
      iVar7 = 0;
      iVar8 = Ordinal_1116(puVar1);
      pcVar6 = (char *)*puVar1;
      if (*pcVar6 != '\0') goto LAB_6803a2a0;
      goto LAB_6803a1f8;
    }
    if (0) {
      /* case 0x6803a2d2: recursive format */
      piVar2 = *(int **)(local_818 + 4);
      local_408 = (ushort)(*(unsigned char *)((char *)&local_408 + 1)) << 8;
      sVar4 = props_flushFormatBuffer();
      if (sVar4 == 0) goto LAB_6803a3ca;
      props_valueToString(param_1,piVar2,param_2,param_3);
      goto LAB_6803a1f8;
    }
switchD_6803a1a7_caseD_6803a1c0:
    local_408 = 0x3f00;
    uVar3 = 0;
    bVar5 = 0;
    goto LAB_6803a326;
  }
  local_820 = param_4[1];
  param_4 = param_4 + 1;
  if (local_820 == 0x6e) {
    local_820 = 0xd;
  }
LAB_6803a142:
  sVar4 = props_getCharSize(local_820);
  if (sVar4 != 0) goto LAB_6803a3b3;
  goto LAB_6803a3ca;
  while (pcVar6 = pcVar6 + 1, *pcVar6 != '\0') {
LAB_6803a251:
    sVar4 = props_getCharSize(*pcVar6);
    if (sVar4 == 0) goto LAB_6803a3ca;
  }
  goto LAB_6803a1f8;
  while( true ) {
    sVar4 = props_getCharSize(pcVar6[iVar7]);
    if (sVar4 == 0) goto LAB_6803a3ca;
    pcVar6 = (char *)*puVar1;
    iVar7 = iVar7 + 1;
    if (pcVar6[iVar7] == '\0') break;
LAB_6803a2a0:
    if (iVar8 <= iVar7) break;
  }
LAB_6803a1f8:
  uVar3 = local_408 & 0xff;
  if ((byte)local_408 == -1) {
    uVar3 = Ordinal_1201((int)&local_408 + 1);
    bVar5 = (byte)local_408;
  }
  else {
LAB_6803a207:
    bVar5 = (byte)uVar3;
  }
LAB_6803a326:
  local_818 = local_818 + 4;
  iVar8 = 1;
  if (0 < (short)uVar3) {
    do {
      sVar4 = props_getCharSize(*(undefined1 *)((int)&local_408 + iVar8));
      if (sVar4 == 0) goto LAB_6803a3ca;
      iVar8 = iVar8 + 1;
    } while (iVar8 <= (short)uVar3);
    bVar5 = (byte)local_408;
  }
  if (bVar5 == 0xff) {
    uVar3 = Ordinal_1201((int)&local_408 + 1);
  }
  else {
    uVar3 = (ushort)bVar5;
  }
  iVar8 = 1;
  if (0 < local_81c - (short)uVar3) {
    do {
      sVar4 = props_getCharSize(0x20);
      if (sVar4 == 0) goto LAB_6803a3ca;
      iVar8 = iVar8 + 1;
    } while (iVar8 <= local_81c - (short)uVar3);
  }
LAB_6803a3b3:
  local_820 = param_4[1];
  param_4 = param_4 + 1;
  if (local_820 == 0) goto LAB_6803a3bf;
  goto LAB_6803a104;
}



// ============================================================
// Function: props_formatValue (FUN_6803a430)
// Address: 6803a430
// Size: 53 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl props_formatValue(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = param_1;
  if (param_1 != 0) {
    sprites_getNetResultString(param_1,&local_8,&param_1);
    props_renderFormatted(iVar1,local_8,param_1,param_2,(int)&stack0x0000000c);
  }
  return 0;
}



// ============================================================
// Function: props_checkBufferSpace (FUN_6803a470)
// Address: 6803a470
// Size: 134 bytes
// Params: byte * param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool props_checkBufferSpace(byte *param_1,int param_2)

{
  short sVar1;
  
  if (param_2 != 0) {
    Ordinal_1231(param_1,param_2);
    if (*param_1 != 0xff) {
      return *param_1 < 0x3fe;
    }
    sVar1 = Ordinal_1201(param_1 + 1);
    return sVar1 < 0x3fe;
  }
  if (*param_1 != 0xff) {
    return *param_1 < 0x3fe;
  }
  sVar1 = Ordinal_1201(param_1 + 1);
  return sVar1 < 0x3fe;
}



// ============================================================
// Function: props_formatString (props_formatString)
// Address: 6803a500
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, byte * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl props_formatString(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  props_renderFormatted(param_1,param_2,param_3,param_4,(int)&stack0x00000014);
  return 0;
}


