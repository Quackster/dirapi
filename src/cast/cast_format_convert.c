// Module: cast
// Topic: Format and type conversion, error code mapping
// Address range: 0x68028270 - 0x680288E0
// Functions (13):
//   cast_getScriptFormatProperty
//   cast_getFormatProperty
//   cast_resolveScriptProperty
//   cast_resolveFormatProperty
//   cast_resolveMediaProperty
//   cast_convertFormatCode
//   cast_getFormatId
//   cast_getFieldValue
//   cast_parseNextToken
//   cast_parseFormatFlags
//   cast_setFormatFlag
//   cast_buildFormatString
//   cast_convertTypeToString

// ============================================================
// Function: cast_getScriptFormatProperty (FUN_68028270)
// Address: 68028270
// Size: 52 bytes
// Params: int param_1, uint * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getScriptFormatProperty(int param_1,uint *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = core_getMemberRefNumber(param_1,(int *)param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x80040bcc,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: cast_getFormatProperty (FUN_680282b0)
// Address: 680282b0
// Size: 52 bytes
// Params: int param_1, uint * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getFormatProperty(int param_1,uint *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = crt_extractSoundRef(param_1,(int *)param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x80040bcd,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: cast_resolveScriptProperty (FUN_680282f0)
// Address: 680282f0
// Size: 48 bytes
// Params: int param_1, short param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_resolveScriptProperty(int param_1,short param_2,int *param_3)

{
  *param_3 = 0;
  crt_setScriptPropertyEx(param_1,param_2,param_3);
  return (-(uint)(*param_3 != 0) & 0x7ffbfffe) + 0x80040002;
}



// ============================================================
// Function: cast_resolveFormatProperty (FUN_68028320)
// Address: 68028320
// Size: 48 bytes
// Params: int param_1, short param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_resolveFormatProperty(int param_1,short param_2,int *param_3)

{
  *param_3 = 0;
  core_createMemberRef(param_1,param_2,param_3);
  return (-(uint)(*param_3 != 0) & 0x7ffbffff) + 0x80040001;
}



// ============================================================
// Function: cast_resolveMediaProperty (FUN_68028350)
// Address: 68028350
// Size: 48 bytes
// Params: int param_1, undefined2 param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_resolveMediaProperty(int param_1,undefined2 param_2,int *param_3)

{
  *param_3 = 0;
  crt_createSoundRef(param_1,param_2,param_3);
  return (-(uint)(*param_3 != 0) & 0x7ffbffff) + 0x80040001;
}



// ============================================================
// Function: cast_convertFormatCode (FUN_68028380)
// Address: 68028380
// Size: 136 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_convertFormatCode(undefined4 param_1)

{
  switch(param_1) {
  case 0x2bd:
    return 0xffffffff;
  case 0x2be:
    return 0xffffff9a;
  case 0x2bf:
    return 0xfffffff8;
  case 0x2c0:
    return 0xfffffffe;
  case 0x2c1:
    return 0xfffffffd;
  case 0x2c2:
    return 0xfffffffc;
  case 0x2c3:
    return 0xfffffffb;
  case 0x2c4:
    return 0xfffffffa;
  case 0x2c5:
    return 0xfffffff9;
  default:
    return 0xffffff38;
  case 0x2f5:
    return 0xffffff9b;
  case 0x2f6:
    return 0xfffffff7;
  }
}



// ============================================================
// Function: cast_getFormatId (FUN_68028480)
// Address: 68028480
// Size: 137 bytes
// Params: undefined2 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getFormatId(undefined2 param_1)

{
  switch(param_1) {
  case 0xff9a:
    return 0x2be;
  case 0xff9b:
    return 0x2f5;
  default:
    return 0xab;
  case 0xfff7:
    return 0x2f6;
  case 0xfff8:
    return 0x2bf;
  case 0xfff9:
    return 0x2c5;
  case 0xfffa:
    return 0x2c4;
  case 0xfffb:
    return 0x2c3;
  case 0xfffc:
    return 0x2c2;
  case 0xfffd:
    return 0x2c1;
  case 0xfffe:
    return 0x2c0;
  case 0xffff:
    return 0x2bd;
  }
}



// ============================================================
// Function: cast_getFieldValue (FUN_680285b0)
// Address: 680285b0
// Size: 11 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_getFieldValue(undefined4 *param_1,int param_2)

{
  undefined4 *in_EAX;
  
  core_getFieldValue(param_2,param_1,in_EAX);
  return 0;
}



// ============================================================
// Function: cast_parseNextToken (FUN_680285f0)
// Address: 680285f0
// Size: 52 bytes
// Params: undefined4 param_1
// Return: int *
// Calling convention: __fastcall
// ============================================================

int * __fastcall cast_parseNextToken(undefined4 param_1)

{
  undefined4 unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  props_setParserState(unaff_ESI,param_1,0);
  if (local_c == 8) {
    return local_8;
  }
  props_releaseValue(unaff_ESI,(byte)local_c,local_8);
  return (int *)0xffffffff;
}



// ============================================================
// Function: cast_parseFormatFlags (FUN_68028630)
// Address: 68028630
// Size: 213 bytes
// Params: int param_1, uint * param_2, short * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_parseFormatFlags(int param_1,uint *param_2,short *param_3)
{
  int *piVar1;
  short sVar2;
  int local_864 [279];
  byte local_408 [1024];
  uint local_8;
  
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    props_returnWithValue(param_1,0x800407dc,param_2);
    return 0;
  }
  props_toPascalString((int *)param_2,local_408);
  props_parseIdentifier(local_864,local_408);
switchD_680286be_caseD_17f:
  sVar2 = 0;
LAB_680286a0:
  do {
    piVar1 = cast_parseNextToken(local_864);
  } while (piVar1 == (int *)0x3);
  if ((int)piVar1 < 0) {
    *param_3 = sVar2;
LAB_680286f3:
    return 0;
  }
  switch((int)(size_t)piVar1) {
  case (int *)0x17f:
    goto switchD_680286be_caseD_17f;
  case (int *)0x180:
    sVar2 = sVar2 + 1;
    goto LAB_680286a0;
  case (int *)0x181:
    sVar2 = sVar2 + 2;
    goto LAB_680286a0;
  case (int *)0x182:
    sVar2 = sVar2 + 4;
    goto LAB_680286a0;
  case (int *)0x183:
    sVar2 = sVar2 + 8;
    goto LAB_680286a0;
  case (int *)0x184:
    sVar2 = sVar2 + 0x10;
    goto LAB_680286a0;
  case (int *)0x185:
    sVar2 = sVar2 + 0x20;
    goto LAB_680286a0;
  case (int *)0x186:
    sVar2 = sVar2 + 0x40;
    goto LAB_680286a0;
  default:
    props_setError(param_1,0x26);
    goto LAB_680286f3;
  }
}



// ============================================================
// Function: cast_setFormatFlag (FUN_68028730)
// Address: 68028730
// Size: 150 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_setFormatFlag(int param_1)
{
  ushort uVar1;
  byte *unaff_ESI;
  undefined1 local_808 [1024];
  undefined1 local_408 [1024];
  uint local_8;
  
  score_lookupSymbol(DAT_68196304,param_1,(int)local_408);
  if (*unaff_ESI == 0xff) {
    uVar1 = Ordinal_1201(unaff_ESI + 1);
  }
  else {
    uVar1 = (ushort)*unaff_ESI;
  }
  if (uVar1 == 0) {
    Ordinal_1230();
    return 0;
  }
  cast_loadPascalString(local_808,0x960,8);
  Ordinal_1231();
  Ordinal_1231();
  return 0;
}



// ============================================================
// Function: cast_buildFormatString (FUN_680287d0)
// Address: 680287d0
// Size: 269 bytes
// Params: int param_1, ushort param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_buildFormatString(int param_1,ushort param_2,undefined4 *param_3)
{
  byte local_408 [1024];
  uint local_8;
  
  local_408[0] = 0;
  local_408[1] = 0;
  if (param_2 == 0) {
    score_lookupSymbol(DAT_68196304,0x17f,(int)local_408);
  }
  else {
    if ((param_2 & 1) != 0) {
      cast_setFormatFlag(0x180);
    }
    if ((param_2 & 2) != 0) {
      cast_setFormatFlag(0x181);
    }
    if ((param_2 & 4) != 0) {
      cast_setFormatFlag(0x182);
    }
    if ((param_2 & 8) != 0) {
      cast_setFormatFlag(0x183);
    }
    if ((param_2 & 0x10) != 0) {
      cast_setFormatFlag(0x184);
    }
    if ((param_2 & 0x20) != 0) {
      cast_setFormatFlag(0x185);
    }
    if ((param_2 & 0x40) != 0) {
      cast_setFormatFlag(0x186);
    }
  }
  props_readPascalString(param_1,local_408,param_3);
  return 0;
}



// ============================================================
// Function: cast_convertTypeToString (FUN_680288e0)
// Address: 680288e0
// Size: 123 bytes
// Params: int param_1, short param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_convertTypeToString(int param_1,short param_2,undefined4 *param_3)
{
  int iVar1;
  byte local_408 [1024];
  uint local_8;
  
  if (param_2 == -1) {
    iVar1 = 0x50;
  }
  else if (param_2 == 0) {
    iVar1 = 0x47;
  }
  else {
    iVar1 = (-(uint)(param_2 != 1) & 0xfffffec9) + 0x17e;
  }
  score_lookupSymbol(DAT_68196304,iVar1,(int)local_408);
  props_readPascalString(param_1,local_408,param_3);
  return 0;
}
