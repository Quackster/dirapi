// Module: stage
// Topic: Value serialization and encoding
// Address range: 0x68059AA0 - 0x6805A0D0
// Functions (14):
//   stage_formatFactory (FUN_68059AA0)
//   stage_allocStringLoop (FUN_68059AF0)
//   stage_getSerializeState (FUN_68059B40)
//   stage_writeSmallInt (FUN_68059B90)
//   stage_writeLargeInt (FUN_68059BF0)
//   stage_writeShortValue (FUN_68059C50)
//   stage_serializeSymbol (FUN_68059C90)
//   stage_serializeString (FUN_68059D00)
//   stage_writeDouble (FUN_68059D40)
//   stage_writeFloat (FUN_68059D80)
//   stage_writeCompact (FUN_68059E10)
//   stage_serializeFloat (FUN_68059E50)
//   stage_writeFactoryEntry (FUN_6805A050)
//   stage_serializeData (FUN_6805A0D0)

// ============================================================
// Function: stage_formatFactory (FUN_68059AA0)
// Address: 68059aa0
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatFactory(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x3f);
  props_formatString(param_1,param_3,param_4,(byte *)"<factory %ld %lx>");
  return 0;
}



// ============================================================
// Function: stage_allocStringLoop (FUN_68059AF0)
// Address: 68059af0
// Size: 66 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_allocStringLoop(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  uint local_c [2];
  
  iVar1 = param_4;
  while( true ) {
    if (param_4 < 1) {
      *param_5 = 0;
      param_5[1] = 0;
      return iVar1;
    }
    uVar2 = stage_allocString(param_1,local_c);
    if (uVar2 != 0) break;
    param_4 = param_4 + -1;
    iVar1 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: stage_getSerializeState (FUN_68059b40)
// Address: 68059b40
// Size: 78 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getSerializeState(void)
{
  int *in_EAX;
  uint *unaff_EBX;
  undefined4 *unaff_ESI;
  uint local_10;
  int local_c;
  int local_8;
  
  if (in_EAX == (int *)0x0) {
    in_EAX = &local_8;
    score_lookupProplistEntry(*unaff_ESI,(int *)unaff_ESI[5],unaff_EBX,&local_10,in_EAX);
  }
  local_c = unaff_ESI[7];
  unaff_ESI[7] = local_c + 1;
  local_10 = 4;
  score_storeProplistProperty(*unaff_ESI,(int *)unaff_ESI[5],*in_EAX,unaff_EBX,&local_10);
  return 0;
}



// ============================================================
// Function: stage_writeSmallInt (FUN_68059B90)
// Address: 68059b90
// Size: 92 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_writeSmallInt(void)

{
  uint in_EAX;
  int iVar1;
  int unaff_ESI;
  uint unaff_EDI;
  bool bVar2;
  
  if ((int)unaff_EDI < 0x80) {
    iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),(unaff_EDI | 0x80) << 6 | in_EAX);
  }
  else {
    iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),in_EAX | 0x700);
    if (iVar1 != 1) {
      return true;
    }
    iVar1 = Ordinal_1425(*(undefined4 *)(unaff_ESI + 4));
  }
  bVar2 = iVar1 != 1;
  if (!bVar2) {
    iVar1 = Ordinal_1420(*(undefined4 *)(unaff_ESI + 4));
    bVar2 = iVar1 != 1;
  }
  return bVar2;
}



// ============================================================
// Function: stage_writeLargeInt (FUN_68059BF0)
// Address: 68059bf0
// Size: 91 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_writeLargeInt(void)

{
  uint in_EAX;
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  bool bVar2;
  
  if (unaff_EDI == (short)unaff_EDI) {
    iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),in_EAX | 0x2080);
    bVar2 = iVar1 != 1;
    if (!bVar2) {
      iVar1 = Ordinal_1423(*(undefined4 *)(unaff_ESI + 4));
      return iVar1 != 1;
    }
  }
  else {
    iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),in_EAX | 0x2100);
    bVar2 = iVar1 != 1;
    if (!bVar2) {
      iVar1 = Ordinal_1425(*(undefined4 *)(unaff_ESI + 4));
      bVar2 = iVar1 != 1;
    }
  }
  return bVar2;
}



// ============================================================
// Function: stage_writeShortValue (FUN_68059C50)
// Address: 68059c50
// Size: 64 bytes
// Params: int param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall stage_writeShortValue(int param_1)

{
  bool bVar1;
  uint in_EAX;
  int iVar2;
  
  if (in_EAX + 0x800 < 0x1000) {
    iVar2 = Ordinal_1424(*(undefined4 *)(param_1 + 4),in_EAX & 0xfff | 0x1000);
    return iVar2 != 1;
  }
  bVar1 = stage_writeLargeInt();
  return bVar1;
}



// ============================================================
// Function: stage_serializeSymbol (FUN_68059C90)
// Address: 68059c90
// Size: 107 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_serializeSymbol(int param_1)
{
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;

  score_lookupSymbol(DAT_68196304,param_1,(int)&local_408);
  if (local_408 == -1) {
    Ordinal_1201(local_407);
  }
  stage_writeSmallInt();
  return 0;
}



// ============================================================
// Function: stage_serializeString (FUN_68059D00)
// Address: 68059d00
// Size: 60 bytes
// Params: undefined4 param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_serializeString(undefined4 param_1,int *param_2)

{
  bool bVar1;
  int local_8;

  props_getStringData(param_2,&local_8);
  bVar1 = stage_writeSmallInt();
  props_unlockString(param_2);
  return bVar1;
}



// ============================================================
// Function: stage_writeDouble (FUN_68059D40)
// Address: 68059d40
// Size: 55 bytes
// Params: undefined8 param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_writeDouble(undefined8 param_1)

{
  int iVar1;
  int unaff_ESI;
  bool bVar2;
  
  iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),0x2204);
  bVar2 = iVar1 != 1;
  if (!bVar2) {
    iVar1 = Ordinal_1448(*(undefined4 *)(unaff_ESI + 4),param_1);
    bVar2 = iVar1 != 1;
  }
  return bVar2;
}



// ============================================================
// Function: stage_writeFloat (FUN_68059D80)
// Address: 68059d80
// Size: 129 bytes
// Params: float param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_writeFloat(float param_1)

{
  int iVar1;
  int unaff_ESI;
  bool bVar2;
  
  if (param_1 == 0.0) {
    iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),0x104);
    return iVar1 != 1;
  }
  if (param_1 == 1.0) {
    iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),0x105);
    return iVar1 != 1;
  }
  iVar1 = Ordinal_1424(*(undefined4 *)(unaff_ESI + 4),0x2105);
  bVar2 = iVar1 != 1;
  if (!bVar2) {
    iVar1 = Ordinal_1425(*(undefined4 *)(unaff_ESI + 4),param_1);
    bVar2 = iVar1 != 1;
  }
  return bVar2;
}



// ============================================================
// Function: stage_writeCompact (FUN_68059E10)
// Address: 68059e10
// Size: 50 bytes
// Params: int param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall stage_writeCompact(int param_1)

{
  bool bVar1;
  uint in_EAX;
  int iVar2;
  
  if ((int)in_EAX < 0x800) {
    iVar2 = Ordinal_1424(*(undefined4 *)(param_1 + 4),in_EAX | 0x800);
    return iVar2 != 1;
  }
  bVar1 = stage_writeLargeInt();
  return bVar1;
}



// ============================================================
// Function: stage_serializeFloat (FUN_68059e50)
// Address: 68059e50
// Size: 355 bytes
// Params: undefined4 * param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_serializeFloat(undefined4 *param_1,int *param_2)

{
  float fVar1;
  undefined4 *puVar2;
  int *piVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 local_c [2];
  
  piVar3 = param_2;
  puVar2 = param_1;
  switch(*param_2) {
  case 0:
    iVar6 = Ordinal_1424();
    return iVar6 != 1;
  case 2:
    iVar6 = Ordinal_1424();
    return iVar6 != 1;
  case 4:
    bVar4 = stage_writeShortValue((int)param_1);
    return bVar4;
  case 0x20:
    param_1 = (undefined4 *)param_2[1];
    bVar4 = stage_writeFloat((float)(size_t)param_1);
    return bVar4;
  }
  iVar6 = score_lookupProplistEntry(*param_1,(int *)param_1[5],param_2,local_c,(int *)&param_1);
  if (iVar6 != 0) {
    bVar4 = stage_writeCompact((int)puVar2);
    return bVar4;
  }
  switch(*piVar3) {
  case 1:
  case 0x40:
  case 0x43:
    bVar4 = stage_serializeString(puVar2,piVar3);
    stage_getSerializeState();
    return bVar4;
  default:
    return true;
  case 3:
    uVar5 = (**(code **)(**(int **)piVar3[1] + 0x40))(puVar2,(undefined4 *)piVar3[1]);
    return (bool)uVar5;
  case 8:
    uVar5 = stage_serializeSymbol(piVar3[1]);
    stage_getSerializeState();
    return (bool)uVar5;
  case 9:
  case 0x23:
    break;
  }
  if (*piVar3 == 0x20) {
    fVar1 = (float)(size_t)piVar3[1];
  }
  else {
    fVar1 = (float)*(double *)(*(int *)piVar3[1] + 8);
  }
  bVar4 = stage_writeDouble((double)fVar1);
  stage_getSerializeState();
  return bVar4;
}



// ============================================================
// Function: stage_writeFactoryEntry (FUN_6805A050)
// Address: 6805a050
// Size: 122 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_writeFactoryEntry(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  if (((int)param_4 < 0x80) && ((int)param_3 < 0x40)) {
    iVar1 = Ordinal_1424(*(undefined4 *)(param_1 + 4),(param_4 | 0x80) << 6 | param_3);
  }
  else {
    Ordinal_1424(*(undefined4 *)(param_1 + 4),param_3 | 0x700);
    iVar1 = Ordinal_1425(*(undefined4 *)(param_1 + 4),param_4);
  }
  stage_getSerializeState();
  return iVar1 != 1;
}



// ============================================================
// Function: stage_serializeData (FUN_6805a0d0)
// Address: 6805a0d0
// Size: 235 bytes
// Params: undefined4 * param_1, undefined4 param_2, int param_3, uint param_4, uint param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint stage_serializeData(undefined4 *param_1,undefined4 param_2,int param_3,uint param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = param_1;
  uVar1 = *param_1;
  uVar6 = param_4;
  if (param_3 != 0) {
    local_10 = param_3;
    local_14 = 3;
    iVar5 = score_lookupProplistEntry(uVar1,(int *)param_1[2],&local_14,&local_c,(int *)&param_1);
    uVar6 = local_8;
    if (iVar5 == 0) {
      local_8 = puVar2[4];
      puVar2[4] = local_8 + 1;
      local_c = 4;
      score_storeProplistProperty(uVar1,(int *)puVar2[2],(int)param_1,&local_14,&local_c);
      Ordinal_1424(puVar2[1],0x100);
      bVar4 = stage_serializeFloat(puVar2,(int *)&local_14);
      uVar6 = local_8;
      if (CONCAT31(extraout_var,bVar4) != 0) {
        return CONCAT31(extraout_var,bVar4);
      }
    }
  }
  uVar3 = param_5;
  if (((int)param_5 < 0x80) && ((int)uVar6 < 0x100)) {
    iVar5 = Ordinal_1424(puVar2[1],(param_5 | 0xff80) << 8 | uVar6);
  }
  else {
    Ordinal_1424(puVar2[1],uVar6 | 0x4000);
    iVar5 = Ordinal_1425(puVar2[1],uVar3);
  }
  local_c = 3;
  local_8 = param_2;
  stage_getSerializeState();
  return (uint)(iVar5 != 1);
}



