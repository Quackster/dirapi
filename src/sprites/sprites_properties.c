// Module: sprites
// Topic: Sprite property getters/setters, flags, attributes, and ink effects
// Address range: 0x68073100 - 0x68075140
// Functions (74):
//   sprites_checkMemberExists
//   sprites_moveMemberToCast
//   sprites_importMemberFile
//   sprites_getMemberPropertyEx
//   sprites_getMemberCastIndex
//   sprites_setProperty
//   sprites_setPropertyDirect
//   sprites_setMemberLocked
//   sprites_updateMemberScriptDirect
//   sprites_createDefaultKeyframe
//   sprites_getKeyframeData
//   sprites_setKeyframeData
//   sprites_mergeKeyframeData
//   sprites_getInkEffect
//   sprites_getMemberTrails
//   sprites_setMemberTrails
//   sprites_getMemberPalette
//   sprites_toggleMemberExport
//   sprites_getMemberRect
//   sprites_setMemberRect
//   sprites_getMemberFrameRate
//   sprites_getMemberMediaRef
//   sprites_setMemberMediaRef
//   sprites_getMemberRegPointPair
//   sprites_setMemberRegPoint
//   sprites_findMemberInCastLib
//   sprites_resolveMemberCast
//   sprites_getMemberMediaData
//   sprites_setMemberMediaData
//   sprites_getMemberLoopData
//   sprites_setMemberLoopData
//   sprites_getMemberCenterCrop
//   sprites_setMemberCenterCrop
//   sprites_getMemberFlags
//   sprites_setMemberFlags
//   sprites_getMemberString
//   sprites_setMemberString
//   sprites_setPropertyValue
//   sprites_getPropertyValue
//   sprites_setMemberBlendValue
//   sprites_getMemberBlendValue
//   sprites_setMemberEditable
//   sprites_getMemberEditable
//   sprites_setMemberMoveable
//   sprites_getMemberMoveable
//   sprites_setMemberForeColor
//   sprites_getMemberForeColor
//   sprites_setMemberBackColor
//   sprites_getMemberBackColor
//   sprites_setMemberAutoTab
//   sprites_getMemberAutoTab
//   sprites_setMemberEditing
//   sprites_getMemberEditing
//   sprites_getMemberLineHeight
//   sprites_setMemberImmovable
//   sprites_getMemberImmovable
//   sprites_setMemberInk
//   sprites_getMemberInk
//   sprites_setMemberStretch
//   sprites_getMemberStretch
//   sprites_setMemberAntiAlias
//   sprites_getMemberAntiAlias
//   sprites_getMemberWidth
//   sprites_getMemberDepth
//   sprites_getMemberCompression
//   sprites_getMemberDuration
//   sprites_getMemberSampleRate
//   sprites_getMemberSampleSize
//   sprites_checkBounds
//   sprites_copyMemberToCast
//   sprites_lookupMemberCastData
//   sprites_importMemberFromFile
//   sprites_exportMemberToFile
//   sprites_deleteMemberFromCast


// ============================================================
// Function: sprites_checkMemberExists (FUN_68073100)
// Address: 68073100
// Size: 56 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_checkMemberExists(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar1 = Ordinal_362(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2);
  iVar2 = Ordinal_271(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28),uVar1);
  return (iVar2 != 0) - 1;
}



// ============================================================
// Function: sprites_moveMemberToCast (FUN_68073140)
// Address: 68073140
// Size: 139 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_moveMemberToCast(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_362(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),param_2);
  iVar2 = Ordinal_362(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),param_3);
  if ((short)((uint)iVar2 >> 0x10) == -1) {
    param_1 = CONCAT22(1,(short)iVar2);
    iVar2 = Ordinal_277(*(int *)(iVar3 + 0x20),param_1);
  }
  sVar4 = (short)((uint)iVar2 >> 0x10);
  if (sVar4 != 0) {
    iVar3 = Ordinal_343(*(int *)(iVar3 + 0x20),*(byte **)(iVar3 + 0x28),iVar1,iVar2);
    if (iVar3 != 0) {
      return (int)sVar4;
    }
  }
  return -1;
}



// ============================================================
// Function: sprites_importMemberFile (FUN_680731d0)
// Address: 680731d0
// Size: 230 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 * param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_importMemberFile(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_460 [1048];
  undefined4 local_48;
  undefined2 local_44;
  undefined1 local_42;
  undefined1 local_41 [57];
  uint local_8;
  
  local_48 = FOURCC_mmud;
  local_44 = 0x2e79;
  local_42 = 0;
  memset(local_41,0,0x39);
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_1204(&local_48,param_3);
  Ordinal_1309(local_460,0x400,&local_48,2);
  scoreEngine_setScoreContext(*(int *)(iVar1 + 0x20),param_2);
  uVar2 = Ordinal_1322(local_460);
  uVar3 = Ordinal_1330(local_460);
  iVar4 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_4);
  scoreEngine_readPropertyData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),iVar4,param_5,uVar2,uVar3);
  return 0;
}



// ============================================================
// Function: sprites_getMemberPropertyEx (FUN_680732c0)
// Address: 680732c0
// Size: 65 bytes
// Params: int param_1, undefined4 * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberPropertyEx(int param_1,undefined4 *param_2,int param_3,int *param_4)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  scoreEngine_getPropertyExData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),iVar2,param_3 + 1,
               (uint)param_4 >> 3 & 1,param_4);
  return 0;
}



// ============================================================
// Function: sprites_getMemberCastIndex (FUN_68073310)
// Address: 68073310
// Size: 67 bytes
// Params: uint param_1, undefined4 * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_getMemberCastIndex(uint param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
    uVar3 = Ordinal_277(*(int *)(iVar1 + 0x20),uVar2);
    return uVar3 >> 0x10;
  }
  return param_1 >> 0x10;
}



// ============================================================
// Function: sprites_setProperty (FUN_68073360)
// Address: 68073360
// Size: 93 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setProperty(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,2,local_20);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setPropertyDirect (FUN_680733c0)
// Address: 680733c0
// Size: 87 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setPropertyDirect(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x26,local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberLocked (FUN_68073420)
// Address: 68073420
// Size: 75 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberLocked(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = (uint)(param_3 != 0);
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x28,local_20);
  return 0;
}



// ============================================================
// Function: sprites_updateMemberScriptDirect (FUN_68073470)
// Address: 68073470
// Size: 27 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_updateMemberScriptDirect(undefined4 param_1,undefined4 param_2,int *param_3)
{
  sprites_updateMemberScript(param_2,1,param_3);
  return 0;
}



// ============================================================
// Function: sprites_createDefaultKeyframe (FUN_68073490)
// Address: 68073490
// Size: 62 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_createDefaultKeyframe(void)
{
  undefined2 local_14;
  undefined1 local_12;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_14 = 0;
  local_12 = 0;
  local_10 = 0xc;
  local_c = 0;
  scoreEngine_createKeyframe(&local_14,0xe,10);
  return 0;
}



// ============================================================
// Function: sprites_getKeyframeData (FUN_680734d0)
// Address: 680734d0
// Size: 131 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getKeyframeData(int param_1,undefined4 param_2)
{
  int iVar1;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_20 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x27,(uint *)&local_20);
  if (local_20 != (int *)0x0) {
    scoreEngine_swapKeyframeBytes(local_20,1);
    return 0;
  }
  sprites_createDefaultKeyframe();
  return 0;
}



// ============================================================
// Function: sprites_setKeyframeData (FUN_68073560)
// Address: 68073560
// Size: 86 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setKeyframeData(int param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  int *local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 != (int *)0x0) {
    scoreEngine_swapKeyframeBytes(param_3,0);
  }
  local_20[0] = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x27,(uint *)local_20);
  return 0;
}



// ============================================================
// Function: sprites_mergeKeyframeData (FUN_680735c0)
// Address: 680735c0
// Size: 64 bytes
// Params: undefined4 param_1, byte param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_mergeKeyframeData(undefined4 param_1,byte param_2,undefined4 param_3,int param_4,int param_5)
{
  int *piVar1;
  int unaff_EDI;
  
  piVar1 = (int *)sprites_getKeyframeData(unaff_EDI,param_1);
  if (piVar1 != (int *)0x0) {
    scoreEngine_mergeKeyframes(piVar1,param_4,param_5,param_2);
    sprites_setKeyframeData(unaff_EDI,param_1,piVar1);
    cast_freeHandle(piVar1);
  }
  return 0;
}



// ============================================================
// Function: sprites_getInkEffect (FUN_68073600)
// Address: 68073600
// Size: 87 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getInkEffect(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,10,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberTrails (FUN_68073660)
// Address: 68073660
// Size: 165 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberTrails(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [7];
  
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[0] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,4,local_20);
  if (local_20[0] == 1) {
    return 0;
  }
  if (local_20[0] != 2) {
    if (local_20[0] != 3) {
      return 0;
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberTrails (FUN_68073710)
// Address: 68073710
// Size: 112 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberTrails(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 == 0) {
    local_20[0] = 3;
  }
  else if (param_3 == 1) {
    local_20[0] = 2;
  }
  else if (param_3 == 2) {
    local_20[0] = 1;
  }
  else {
    local_20[0] = 0;
  }
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,4,local_20);
  return 0;
}




// ============================================================
// Function: sprites_getMemberPalette (FUN_68073780)
// Address: 68073780
// Size: 91 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberPalette(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,3,local_20);
  return 0;
}



// ============================================================
// Function: sprites_toggleMemberExport (FUN_680737e0)
// Address: 680737e0
// Size: 97 bytes
// Params: int param_1, short param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_toggleMemberExport(int param_1,short param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 != 0) {
    uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
    Ordinal_279(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,(short)uVar2,0);
    return 0;
  }
  uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_278(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,(short)uVar2,0);
  return 0;
}



// ============================================================
// Function: sprites_getMemberRect (FUN_68073850)
// Address: 68073850
// Size: 112 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberRect(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,5,&local_20);
  param_3[3] = local_18;
  param_3[1] = local_20;
  *param_3 = local_1c;
  param_3[2] = local_14;
  return 0;
}



// ============================================================
// Function: sprites_setMemberRect (FUN_680738c0)
// Address: 680738c0
// Size: 90 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberRect(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  
  local_20 = param_3[1];
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_18 = param_3[3];
  local_1c = *param_3;
  local_14 = param_3[2];
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,5,&local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberFrameRate (FUN_68073920)
// Address: 68073920
// Size: 87 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberFrameRate(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x3f,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberMediaRef (FUN_68073980)
// Address: 68073980
// Size: 110 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberMediaRef(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x40,local_20);
  uVar2 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(short)local_20[0]);
  *param_3 = uVar2;
  return 0;
}



// ============================================================
// Function: sprites_setMemberMediaRef (FUN_680739f0)
// Address: 680739f0
// Size: 86 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberMediaRef(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3);
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x40,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberRegPointPair (FUN_68073a50)
// Address: 68073a50
// Size: 80 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberRegPointPair(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x3c,&local_20);
  *param_3 = local_1c;
  param_3[1] = local_20;
  return 0;
}



// ============================================================
// Function: sprites_setMemberRegPoint (FUN_68073aa0)
// Address: 68073aa0
// Size: 76 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberRegPoint(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20 = param_4;
  local_1c = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x3c,&local_20);
  return 0;
}



// ============================================================
// Function: sprites_findMemberInCastLib (FUN_68073af0)
// Address: 68073af0
// Size: 145 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_findMemberInCastLib(int param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)
{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  int local_2c;
  uint *local_28;
  undefined4 local_24;
  uint local_20 [2];
  undefined4 local_18;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_28 = param_2;
  lingo_loadMovieData(*(int *)(iVar1 + 0x20),&local_30);
  uVar2 = media_handleTextHitTest(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x24),local_30,local_2c,&local_24,
                       param_4);
  *param_3 = uVar2;
  if (0 < (*(unsigned short *)((char *)&local_24 + 2))) {
    local_20[0] = 0;
    local_18 = 0;
    Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_24,0x31,local_20);
    *local_28 = local_20[0];
  }
  return 0;
}



// ============================================================
// Function: sprites_resolveMemberCast (FUN_68073b90)
// Address: 68073b90
// Size: 99 bytes
// Params: int param_1, int param_2, short * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_resolveMemberCast(int param_1,int param_2,short *param_3)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  
  psVar2 = param_3;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar3 = Ordinal_312(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*param_3,param_2 + 1,4,&param_1)
  ;
  if (iVar3 != 0) {
    uVar4 = Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(short)param_1);
    *(undefined4 *)psVar2 = uVar4;
    return iVar3;
  }
  *psVar2 = 0;
  psVar2[1] = -1;
  return 0;
}



// ============================================================
// Function: sprites_getMemberMediaData (FUN_68073c00)
// Address: 68073c00
// Size: 80 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberMediaData(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = param_3;
  local_20 = 0;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6a,&local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberMediaData (FUN_68073c50)
// Address: 68073c50
// Size: 139 bytes
// Params: int param_1, undefined4 param_2, uint param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberMediaData(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6a,&local_20);
  if (iVar2 != 0) {
    uVar3 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)(iVar1 + 0x98));
    if (((short)param_2 == (short)uVar3) && ((*(unsigned short *)((char *)&param_2 + 2)) == (short)((uint)uVar3 >> 0x10))) {
      media_getAssetState(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberLoopData (FUN_68073ce0)
// Address: 68073ce0
// Size: 80 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberLoopData(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = param_3;
  local_20 = 0;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6e,&local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberLoopData (FUN_68073d30)
// Address: 68073d30
// Size: 127 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberLoopData(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6e,local_20);
  if (iVar2 != 0) {
    uVar3 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)(iVar1 + 0x98));
    if (((short)param_2 == (short)uVar3) && ((*(unsigned short *)((char *)&param_2 + 2)) == (short)((uint)uVar3 >> 0x10))) {
      media_getAssetState(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2);
    }
  }
  return 0;
}




// ============================================================
// Function: sprites_getMemberCenterCrop (FUN_68073db0)
// Address: 68073db0
// Size: 127 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCenterCrop(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x60,local_20);
  if (iVar1 != 0) {
    if (local_20[0] == 0xffffffff) {
      return 0;
    }
    if (local_20[0] != 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberCenterCrop (FUN_68073e30)
// Address: 68073e30
// Size: 162 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberCenterCrop(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 == -1) {
    local_20[0] = 0xffffffff;
  }
  else if (param_3 == 0) {
    local_20[0] = 0;
  }
  else {
    local_20[0] = (uint)(param_3 == 1);
  }
  iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x60,local_20);
  if (iVar2 != 0) {
    uVar3 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)(iVar1 + 0x98));
    if (((short)param_2 == (short)uVar3) && ((*(unsigned short *)((char *)&param_2 + 2)) == (short)((uint)uVar3 >> 0x10))) {
      media_getAssetState(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberFlags (FUN_68073ee0)
// Address: 68073ee0
// Size: 143 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberFlags(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = param_3;
  local_20 = 0;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6b,&local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberFlags (FUN_68073f70)
// Address: 68073f70
// Size: 208 bytes
// Params: int param_1, undefined4 param_2, byte param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberFlags(int param_1,undefined4 param_2,byte param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = param_4;
  local_18 = param_5;
  local_20 = (uint)((param_3 & 1) != 0);
  if ((param_3 & 2) != 0) {
    local_20 = local_20 | 2;
  }
  if ((param_3 & 4) != 0) {
    local_20 = local_20 | 4;
  }
  if ((param_3 & 8) != 0) {
    local_20 = local_20 | 0x10;
  }
  if ((param_3 & 0x10) != 0) {
    local_20 = local_20 | 8;
  }
  if ((param_3 & 0x20) != 0) {
    local_20 = local_20 | 0x4000;
  }
  if ((param_3 & 0x40) != 0) {
    local_20 = local_20 | 0x8000;
  }
  iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6b,&local_20);
  if (((iVar2 != 0) &&
      (uVar3 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),
                           (undefined4 *)(iVar1 + 0x98)), (short)param_2 == (short)uVar3)) &&
     ((*(unsigned short *)((char *)&param_2 + 2)) == (short)((uint)uVar3 >> 0x10))) {
    media_getAssetState(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2);
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberString (FUN_68074040)
// Address: 68074040
// Size: 159 bytes
// Params: int param_1, undefined4 param_2, undefined1 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberString(int param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4)
{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_18 = param_4;
  puVar1 = param_3 + 1;
  local_1c = 0x3ff;
  local_20 = puVar1;
  iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2,0x69,(uint *)&local_20);
  if (iVar2 == 0) {
    *puVar1 = 0;
    *param_3 = 0;
    return 0;
  }
  iVar2 = Ordinal_1201(puVar1);
  param_3[iVar2 + 1] = 0;
  if (iVar2 < 0xff) {
    *param_3 = (char)iVar2;
    return 0;
  }
  *param_3 = 0xff;
  return 0;
}



// ============================================================
// Function: sprites_setMemberString (FUN_680740e0)
// Address: 680740e0
// Size: 140 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberString(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3 + 1;
  local_18 = param_4;
  local_14 = param_5;
  iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x69,local_20);
  if (iVar2 != 0) {
    uVar3 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)(iVar1 + 0x98));
    if (((short)param_2 == (short)uVar3) && ((*(unsigned short *)((char *)&param_2 + 2)) == (short)((uint)uVar3 >> 0x10))) {
      media_getAssetState(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setPropertyValue (FUN_68074170)
// Address: 68074170
// Size: 84 bytes
// Params: int param_1, undefined4 param_2, uint * param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setPropertyValue(int param_1,undefined4 param_2,uint *param_3,undefined4 param_4,undefined4 param_5
                 )
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20 = *param_3;
  local_1c = param_4;
  local_18 = param_5;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6c,&local_20);
  return 0;
}



// ============================================================
// Function: sprites_getPropertyValue (FUN_680741d0)
// Address: 680741d0
// Size: 80 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getPropertyValue(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_1c = param_3;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x6c,&local_20);
  *param_4 = local_20;
  return 0;
}



// ============================================================
// Function: sprites_setMemberBlendValue (FUN_68074220)
// Address: 68074220
// Size: 72 bytes
// Params: int param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberBlendValue(int param_1,undefined4 param_2,uint *param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = *param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x62,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberBlendValue (FUN_68074270)
// Address: 68074270
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberBlendValue(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x62,local_20);
  *param_3 = local_20[0];
  return 0;
}



// ============================================================
// Function: sprites_setMemberEditable (FUN_680742c0)
// Address: 680742c0
// Size: 70 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberEditable(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x4a,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberEditable (FUN_68074310)
// Address: 68074310
// Size: 77 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberEditable(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x4a,local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberMoveable (FUN_68074360)
// Address: 68074360
// Size: 70 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberMoveable(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x2f,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberMoveable (FUN_680743b0)
// Address: 680743b0
// Size: 77 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberMoveable(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x2f,local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberForeColor (FUN_68074400)
// Address: 68074400
// Size: 67 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberForeColor(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x48,local_20);
  return 0;
}




// ============================================================
// Function: sprites_getMemberForeColor (FUN_68074450)
// Address: 68074450
// Size: 77 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberForeColor(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x48,local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberBackColor (FUN_680744a0)
// Address: 680744a0
// Size: 67 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberBackColor(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x49,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberBackColor (FUN_680744f0)
// Address: 680744f0
// Size: 77 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberBackColor(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x49,local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberAutoTab (FUN_68074540)
// Address: 68074540
// Size: 126 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberAutoTab(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_38);
  if (iVar2 != 0) {
    if ((local_38[0] >> 6 & 1) != param_3) {
      if (param_3 == 0) {
        local_20[0] = local_38[0] & 0xffffffbf;
      }
      else {
        local_20[0] = local_38[0] | 0x40;
      }
      Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberAutoTab (FUN_680745c0)
// Address: 680745c0
// Size: 100 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberAutoTab(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberEditing (FUN_68074630)
// Address: 68074630
// Size: 126 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberEditing(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_38);
  if (iVar2 != 0) {
    if ((local_38[0] >> 5 & 1) != param_3) {
      if (param_3 == 0) {
        local_20[0] = local_38[0] & 0xffffffdf;
      }
      else {
        local_20[0] = local_38[0] | 0x20;
      }
      Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberEditing (FUN_680746b0)
// Address: 680746b0
// Size: 100 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberEditing(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberLineHeight (FUN_68074720)
// Address: 68074720
// Size: 77 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberLineHeight(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x30,local_20);
  return 0;
}



// ============================================================
// Function: sprites_setMemberImmovable (FUN_68074770)
// Address: 68074770
// Size: 130 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberImmovable(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_38);
  if (iVar2 != 0) {
    if ((local_38[0] >> 8 & 1) != param_3) {
      if (param_3 == 0) {
        local_20[0] = local_38[0] & 0xfffffeff;
      }
      else {
        local_20[0] = local_38[0] | 0x100;
      }
      Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberImmovable (FUN_68074800)
// Address: 68074800
// Size: 100 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberImmovable(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberInk (FUN_68074870)
// Address: 68074870
// Size: 222 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberInk(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  uint local_50 [6];
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if (iVar2 != 0) {
    if (param_3 == 0xfffffffe) {
      local_50[0] = local_20[0] & 0xffffdfff | 0x1800;
    }
    else if (param_3 == 0xffffffff) {
      local_50[0] = local_20[0] & 0xffffcfff | 0x800;
    }
    else if (param_3 == 0) {
      local_50[0] = local_20[0] & 0xffffc7ff;
    }
    else {
      local_38[0] = param_3;
      Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x58,local_38);
      Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
      local_50[0] = local_20[0] & 0xffffefff | 0x2800;
    }
    local_20[0] = local_50[0];
    Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_50);
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberInk (FUN_68074950)
// Address: 68074950
// Size: 202 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberInk(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if ((iVar2 != 0) && ((local_20[0] & 0x800) != 0)) {
    if (((local_20[0] & 0x2000) == 0) && ((local_20[0] & 0x1000) == 0)) {
      return 0;
    }
    if ((local_20[0] & 0x2000) == 0) {
      if ((local_20[0] & 0x1000) != 0) {
        return 0;
      }
    }
    else if ((local_20[0] & 0x1000) == 0) {
      Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x58,local_20);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberStretch (FUN_68074a20)
// Address: 68074a20
// Size: 130 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberStretch(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_38);
  if (iVar2 != 0) {
    if ((local_38[0] >> 10 & 1) != param_3) {
      if (param_3 == 0) {
        local_20[0] = local_38[0] & 0xfffffbff;
      }
      else {
        local_20[0] = local_38[0] | 0x400;
      }
      Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberStretch (FUN_68074ab0)
// Address: 68074ab0
// Size: 100 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberStretch(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_setMemberAntiAlias (FUN_68074b20)
// Address: 68074b20
// Size: 129 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setMemberAntiAlias(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  uint unaff_EDI;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_38);
  if ((iVar2 != 0) && ((~(local_38[0] >> 9) & 1) != unaff_EDI)) {
    if (unaff_EDI == 0) {
      local_20[0] = local_38[0] | 0x200;
    }
    else {
      local_20[0] = local_38[0] & 0xfffffdff;
    }
    Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  }
  return 0;
}




// ============================================================
// Function: sprites_getMemberAntiAlias (FUN_68074bb0)
// Address: 68074bb0
// Size: 102 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberAntiAlias(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x56,local_20);
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberWidth (FUN_68074c20)
// Address: 68074c20
// Size: 71 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberWidth(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x59,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberDepth (FUN_68074c70)
// Address: 68074c70
// Size: 121 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberDepth(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x5a,local_20);
  if (iVar1 != 0) {
    if (local_20[0] == 1) {
      return 0;
    }
    if (local_20[0] == 2) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberCompression (FUN_68074cf0)
// Address: 68074cf0
// Size: 197 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberCompression(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20;
  undefined4 local_1c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20 = param_3;
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x5c,&local_20);
  if (iVar1 != 0) {
    switch(local_1c) {
    case 1:
      return 0;
    case 2:
      return 0;
    case 3:
      return 0;
    case 4:
      return 0;
    case 5:
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_getMemberDuration (FUN_68074dd0)
// Address: 68074dd0
// Size: 71 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberDuration(int param_1,undefined4 param_2)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x5b,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberSampleRate (FUN_68074e20)
// Address: 68074e20
// Size: 77 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberSampleRate(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x5d,local_20);
  return 0;
}



// ============================================================
// Function: sprites_getMemberSampleSize (FUN_68074e70)
// Address: 68074e70
// Size: 77 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getMemberSampleSize(int param_1,undefined4 param_2,uint param_3)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20[0] = param_3;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x5e,local_20);
  return 0;
}



// ============================================================
// Function: sprites_checkBounds (FUN_68074ec0)
// Address: 68074ec0
// Size: 43 bytes
// Params: int param_1, short * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_checkBounds(int param_1,short *param_2)
{
  if (((*param_2 == 0) && (param_2[1] != 0)) && (*(int *)(*(int *)(param_1 + 8) + 4) != 0)) {
    *param_2 = 1;
  }
  return 0;
}



// ============================================================
// Function: sprites_copyMemberToCast (FUN_68074ef0)
// Address: 68074ef0
// Size: 196 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_copyMemberToCast(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short extraout_var;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  iVar3 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3);
  param_1 = iVar3;
  if ((short)((uint)iVar3 >> 0x10) == -1) {
    param_1 = CONCAT22(1,(short)iVar3);
    iVar3 = Ordinal_277(*(int *)(iVar1 + 0x20),param_1);
  }
  if ((short)((uint)iVar3 >> 0x10) != 0) {
    param_1 = Ordinal_273(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),iVar2);
    iVar2 = Ordinal_274(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),iVar3,&param_1,(int *)0x1);
    Ordinal_275(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),&param_1);
    if (iVar2 != 0) {
      Ordinal_363(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(short)iVar3);
      return (int)extraout_var;
    }
  }
  return -1;
}



// ============================================================
// Function: sprites_lookupMemberCastData (FUN_68074fc0)
// Address: 68074fc0
// Size: 89 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_lookupMemberCastData(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar2,2,local_20);
  return 0;
}



// ============================================================
// Function: sprites_importMemberFromFile (FUN_68075020)
// Address: 68075020
// Size: 152 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_importMemberFromFile(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x20) == 0)) {
    return param_2;
  }
  iVar1 = sprites_validateMemberRef(param_1,param_2);
  if (iVar1 == 0) {
    return -0x7ffbf828;
  }
  if ((short)param_2 < 1) {
    iVar2 = -0x7ffbf43c;
  }
  else {
    iVar1 = scoreEngine_setScoreContext(extraout_EDX,param_3);
    if (iVar1 == 0) {
      return -0x7ffbf828;
    }
    iVar1 = Ordinal_341(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28),param_2,iVar1,0,0,0,0,
                        (int *)0x0);
    if (iVar1 != 0) {
      return 0;
    }
    iVar2 = lingo_setupPlaybackContext(*(int *)(iVar2 + 0x20));
    if (iVar2 == 0) {
      return -0x7ffbfffe;
    }
  }
  return iVar2;
}



// ============================================================
// Function: sprites_exportMemberToFile (FUN_680750c0)
// Address: 680750c0
// Size: 114 bytes
// Params: undefined4 param_1, int param_2, uint param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_exportMemberToFile(undefined4 param_1,int param_2,uint param_3)

{
  uint *unaff_EBX;
  int unaff_ESI;
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(*(int *)(unaff_ESI + 8) + 4) == 0) {
    return -0x7ffbf82e;
  }
  if (param_3 != 0xa9) {
    return -0x7ffbf82b;
  }
  if (param_2 == 0) {
    sprites_getMemberField(unaff_ESI,param_1,&param_3);
    props_storeSymbolValue(unaff_ESI,param_3,unaff_EBX);
  }
  else {
    iVar1 = props_coerceToShort(unaff_ESI,unaff_EBX,(int *)&param_3);
    if (iVar1 == 0) {
      sprites_setMemberField(unaff_ESI,param_1,param_3);
      return 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: sprites_deleteMemberFromCast (FUN_68075140)
// Address: 68075140
// Size: 233 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_deleteMemberFromCast(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  uint *unaff_EBX;
  int unaff_ESI;
  uint local_40;
  int local_3c;
  uint local_38 [6];
  uint local_20 [6];
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  local_3c = 0;
  if (iVar1 == 0) {
    return 0;
  }
  if (param_3 == 0x27a) {
    if (param_2 == 0) {
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x4c,local_38);
      if (iVar1 == 0) {
        local_38[0] = 0;
      }
      props_storeIntValue(unaff_ESI,local_38[0],unaff_EBX);
    }
    else {
      local_3c = props_coerceAndReturnInt(unaff_ESI,unaff_EBX,(int *)&local_40);
      if (local_3c == 0) {
        local_20[0] = local_40;
        iVar1 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x4c,local_20);
        if (iVar1 == 0) {
          local_3c = 0x800407d6;
          return 0;
        }
      }
    }
    return 0;
  }
  return 0;
}



