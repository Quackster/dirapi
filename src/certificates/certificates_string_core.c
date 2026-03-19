// Module: certificates
// Topic: String object core - constructor, creation, lifecycle, conversion, hash, compare, wchar utilities, caching
// Address range: 0x68151F20 - 0x68152D90
// Functions (29):
//   certificates_wrapHtmlSub
//   certificates_convertToString
//   certificates_initStringTable
//   certificates_destroyStringTable
//   certificates_initStringPool
//   certificates_freeStringPool
//   certificates_createStringPrototype
//   certificates_constructString
//   certs_allocHashEntry
//   certs_concatStrings
//   certs_allocFromPool
//   certificates_createFromWchar
//   certificates_removeFromCache
//   certificates_freeStringContext
//   certificates_freeStringNode
//   certificates_createStringObject
//   certs_hashLookup (FUN_681525c0)
//   certs_resizeString
//   certificates_computeStringHash
//   certs_compareStrings
//   certs_getStringLength
//   certs_findChar
//   certs_findCharInString
//   certs_duplicateString
//   certificates_convertMultibyte
//   certs_createSubstring
//   certs_formatString
//   certificates_cacheString
//   certificates_getStringCache

// ============================================================
// Function: certificates_wrapHtmlSub (FUN_68151f20)
// Address: 68151f20
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlSub(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"sub",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_convertToString (FUN_68151f50)
// Address: 68151f50
// Size: 204 bytes
// Params: ushort * param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_convertToString(ushort *param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  undefined2 local_c [2];
  uint local_8;

  uVar1 = xtra_getPropertyById((int)param_1,param_3 * 2 + 2);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    for (local_8 = 0; local_8 < param_3; local_8 = local_8 + 1) {
      iVar3 = runtime_parseNumberToInt(param_1,*(uint *)(param_4 + local_8 * 4),local_c);
      if (iVar3 == 0) {
        xtra_checkAndFlush(param_1,uVar1);
        return 0;
      }
      *(undefined2 *)(uVar1 + local_8 * 2) = local_c[0];
    }
    *(undefined2 *)(uVar1 + local_8 * 2) = 0;
    puVar4 = certs_allocHashEntry((int)param_1,uVar1,param_3,0);
    if (puVar4 == (uint *)0x0) {
      xtra_checkAndFlush(param_1,uVar1);
      uVar2 = 0;
    }
    else {
      *param_5 = (uint)puVar4 | 4;
      uVar2 = 1;
    }
  }
  return uVar2;
}



// ============================================================
// Function: certificates_initStringTable (FUN_68152020)
// Address: 68152020
// Size: 10 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_initStringTable(void)

{
  return 1;
}



// ============================================================
// Function: certificates_destroyStringTable (FUN_68152030)
// Address: 68152030
// Size: 35 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_destroyStringTable(void)
{
  if (DAT_68196a30 != (int *)0x0) {
    crypto_getHashTableSize(DAT_68196a30);
    DAT_68196a30 = (int *)0x0;
  }
  return 0;
}



// ============================================================
// Function: certificates_initStringPool (FUN_68152060)
// Address: 68152060
// Size: 69 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool certificates_initStringPool(int param_1)

{
  int iVar1;
  uint *puVar2;

  iVar1 = *(int *)(param_1 + 0x14);
  puVar2 = certs_allocFromPool(param_1,&DAT_68196a34,0,0x20);
  if (puVar2 != (uint *)0x0) {
    *(uint **)(iVar1 + 0x1dc) = puVar2;
  }
  return puVar2 != (uint *)0x0;
}



// ============================================================
// Function: certificates_freeStringPool (FUN_681520b0)
// Address: 681520b0
// Size: 51 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_freeStringPool(int param_1)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x14);
  js_freeAtom(iVar1,*(uint *)(iVar1 + 0x1dc));
  *(undefined4 *)(iVar1 + 0x1dc) = 0;
  return 0;
}



// ============================================================
// Function: certificates_createStringPrototype (FUN_681520f0)
// Address: 681520f0
// Size: 120 bytes
// Params: int param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * certificates_createStringPrototype(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;

  iVar1 = events_attachVtable(param_1,param_2,(int *)&PTR_s_escape_68194898);
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_String_68194920,0x68152170,1,
                          (int *)&PTR_s_length_68194900,(int *)&PTR_s_quote_68194968,(int *)0x0,
                          (int *)&PTR_s_fromCharCode_68194b0c);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *(uint *)(piVar2[1] + 0xc) = *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc) | 4;
    }
  }
  return piVar2;
}



// ============================================================
// Function: certificates_constructString (FUN_68152170)
// Address: 68152170
// Size: 113 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_constructString(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  uint local_8;

  if (param_3 == 0) {
    local_8 = *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc);
  }
  else {
    local_8 = certs_hashLookup(param_1,*param_4);
    if (local_8 == 0) {
      return 0;
    }
  }
  if ((*(uint *)(*(int *)(param_1 + 0x34) + 0x4c) & 1) == 0) {
    *param_5 = local_8 | 4;
  }
  else {
    *(uint *)(*(int *)(param_2 + 4) + 0xc) = local_8 | 4;
  }
  return 1;
}



// ============================================================
// Function: certs_allocHashEntry (FUN_681521f0)
// Address: 681521f0
// Size: 81 bytes
// Params: int param_1, uint param_2, uint param_3, uint param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * certs_allocHashEntry(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;

  if (param_3 < 0x40000000) {
    puVar1 = js_bignumFree(param_1,param_4 | 1);
    if (puVar1 == (uint *)0x0) {
      puVar1 = (uint *)0x0;
    }
    else {
      *puVar1 = param_3;
      puVar1[1] = param_2;
    }
  }
  else {
    xtra_reportError(param_1);
    puVar1 = (uint *)0x0;
  }
  return puVar1;
}



// ============================================================
// Function: certs_concatStrings (FUN_68152250)
// Address: 68152250
// Size: 302 bytes
// Params: int param_1, uint * param_2, uint param_3, uint param_4, uint param_5
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * certs_concatStrings(int param_1,uint *param_2,uint param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;

  if (param_4 == 0) {
    puVar1 = *(uint **)(*(int *)(param_1 + 0x14) + 0x1dc);
  }
  else if ((param_3 < 0x8000) && ((param_3 == 0 || (param_4 < 0x8000)))) {
    puVar1 = js_bignumFree(param_1,param_5 | 3);
    if (puVar1 == (uint *)0x0) {
      puVar1 = (uint *)0x0;
    }
    else if (param_3 == 0) {
      *puVar1 = param_4 | 0xc0000000;
      puVar1[1] = (uint)param_2;
    }
    else {
      *puVar1 = param_3 << 0xf | 0x40000000 | param_4;
      puVar1[1] = (uint)param_2;
    }
  }
  else {
    if ((*param_2 & 0x40000000) == 0) {
      local_14 = param_2[1];
    }
    else {
      if ((*(uint *)param_2[1] & 0x40000000) == 0) {
        if ((*param_2 & 0x80000000) == 0) {
          local_10 = *param_2 >> 0xf & 0x7fff;
        }
        else {
          local_10 = 0;
        }
        local_c = *(int *)(param_2[1] + 4) + local_10 * 2;
      }
      else {
        local_c = crypto_getStringLen(param_2);
      }
      local_14 = local_c;
    }
    puVar1 = certs_allocFromPool(param_1,(void *)(local_14 + param_3 * 2),param_4,param_5);
  }
  return puVar1;
}



// ============================================================
// Function: certs_allocFromPool (FUN_68152380)
// Address: 68152380
// Size: 122 bytes
// Params: int param_1, void * param_2, uint param_3, uint param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * certs_allocFromPool(int param_1,void *param_2,uint param_3,uint param_4)

{
  void *_Dst;
  uint *puVar1;

  _Dst = (void *)xtra_getPropertyById(param_1,param_3 * 2 + 2);
  if (_Dst == (void *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    memcpy(_Dst,param_2,param_3 << 1);
    *(undefined2 *)((int)_Dst + param_3 * 2) = 0;
    puVar1 = certs_allocHashEntry(param_1,(uint)_Dst,param_3,param_4);
    if (puVar1 == (uint *)0x0) {
      xtra_checkAndFlush(param_1,(int)_Dst);
    }
  }
  return puVar1;
}



// ============================================================
// Function: certificates_createFromWchar (FUN_68152400)
// Address: 68152400
// Size: 126 bytes
// Params: int param_1, short * param_2, uint param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * certificates_createFromWchar(int param_1,short *param_2,uint param_3)

{
  size_t _Size;
  uint uVar1;
  void *_Dst;
  uint *puVar2;

  uVar1 = certs_getStringLength(param_2);
  _Size = uVar1 * 2 + 2;
  _Dst = (void *)xtra_getPropertyById(param_1,_Size);
  if (_Dst == (void *)0x0) {
    puVar2 = (uint *)0x0;
  }
  else {
    memcpy(_Dst,param_2,_Size);
    puVar2 = certs_allocHashEntry(param_1,(uint)_Dst,uVar1,param_3);
    if (puVar2 == (uint *)0x0) {
      xtra_checkAndFlush(param_1,(int)_Dst);
    }
  }
  return puVar2;
}



// ============================================================
// Function: certificates_removeFromCache (FUN_68152480)
// Address: 68152480
// Size: 103 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_removeFromCache(uint param_1)
{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;

  if (DAT_68196a30 != (int *)0x0) {
    uVar2 = runtime_getCharType(param_1);
    puVar3 = crypto_findHashEntry(DAT_68196a30,uVar2,param_1);
    puVar1 = (undefined4 *)*puVar3;
    if (puVar1 != (undefined4 *)0x0) {
      js_freeHandle();
      crypto_removeHashEntry(DAT_68196a30,puVar3,puVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: certificates_freeStringContext (FUN_681524f0)
// Address: 681524f0
// Size: 23 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_freeStringContext(int param_1,uint *param_2)
{
  certificates_freeStringNode(*(undefined4 *)(param_1 + 0x14),param_2);
  return 0;
}



// ============================================================
// Function: certificates_freeStringNode (FUN_68152510)
// Address: 68152510
// Size: 99 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_freeStringNode(undefined4 param_1,uint *param_2)
{
  bool bVar1;

  if ((*param_2 & 0x40000000) == 0) {
    bVar1 = param_2[1] != 0;
    if (bVar1) {
      js_freeHandle();
    }
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    certificates_removeFromCache((uint)param_2);
    param_2[1] = 0;
  }
  *param_2 = 0;
  return 0;
}



// ============================================================
// Function: certificates_createStringObject (FUN_68152580)
// Address: 68152580
// Size: 59 bytes
// Params: int param_1, uint param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * certificates_createStringObject(int param_1,uint param_2)

{
  int *piVar1;

  piVar1 = runtime_setProperty(param_1,&PTR_s_String_68194920,(undefined4 *)0x0,0);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *(uint *)(piVar1[1] + 0xc) = param_2 | 4;
  }
  return piVar1;
}



// ============================================================
// Function: certs_hashLookup (FUN_681525c0)
// Address: 681525c0
// Size: 257 bytes
// Params: int param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certs_hashLookup(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;

  if ((param_2 & 7) == 0) {
    piVar2 = (int *)(param_2 & 0xfffffff8);
    if (piVar2 == (int *)0x0) {
      return *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + 0x9c) + 8) & 0xfffffff8;
    }
    iVar1 = (**(code **)(*(int *)(*piVar2 + 4) + 0x24))(param_1,piVar2,3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  if ((param_2 & 7) == 4) {
    uVar3 = param_2 & 0xfffffff8;
  }
  else if (((param_2 & 1) == 0) || (param_2 == 0x80000001)) {
    if ((param_2 & 7) == 2) {
      uVar3 = runtime_divideFloat(param_1,2,param_1,*(double *)(param_2 & 0xfffffff8));
    }
    else if ((param_2 & 7) == 6) {
      uVar3 = javascript_initNumberClass(param_1,(int)param_2 >> 3);
    }
    else {
      uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + 0x7c) + 8) & 0xfffffff8;
    }
  }
  else {
    uVar3 = runtime_divideFloat(param_1,param_2 & 1,param_1,(double)((int)param_2 >> 1));
  }
  return uVar3;
}



// ============================================================
// Function: certs_resizeString (FUN_681526d0)
// Address: 681526d0
// Size: 110 bytes
// Params: uint * param_1, uint param_2
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * certs_resizeString(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;

  if ((param_2 & 7) == 4) {
    puVar1 = crypto_createUnaryOp(param_1,param_2 & 0xfffffff8,0x22);
  }
  else {
    if ((((param_2 & 7) == 0) && (param_2 != 0)) &&
       (uVar2 = runtime_defineProperty((uint)param_1,(int *)(param_2 & 0xfffffff8),
                             *(undefined4 *)(param_1[5] + 0x124),0,0,(int *)&param_2), uVar2 == 0))
    {
      return (uint *)0x0;
    }
    puVar1 = (uint *)certs_hashLookup((int)param_1,param_2);
  }
  return puVar1;
}



// ============================================================
// Function: certificates_computeStringHash (FUN_68152740)
// Address: 68152740
// Size: 261 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certificates_computeStringHash(uint *param_1)

{
  uint local_20;
  ushort *local_1c;
  uint local_18;
  ushort *local_14;
  ushort *local_10;
  uint local_c;
  uint local_8;

  local_8 = 0;
  if ((*param_1 & 0x40000000) == 0) {
    local_1c = (ushort *)param_1[1];
  }
  else {
    if ((*(uint *)param_1[1] & 0x40000000) == 0) {
      if ((*param_1 & 0x80000000) == 0) {
        local_18 = *param_1 >> 0xf & 0x7fff;
      }
      else {
        local_18 = 0;
      }
      local_14 = (ushort *)(*(int *)(param_1[1] + 4) + local_18 * 2);
    }
    else {
      local_14 = (ushort *)crypto_getStringLen(param_1);
    }
    local_1c = local_14;
  }
  local_10 = local_1c;
  if ((*param_1 & 0x40000000) == 0) {
    local_20 = *param_1;
  }
  else {
    local_20 = (-(uint)((*param_1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_1;
  }
  for (local_c = local_20; local_c != 0; local_c = local_c - 1) {
    local_8 = local_8 >> 0x1c ^ local_8 << 4 ^ (uint)*local_10;
    local_10 = local_10 + 1;
  }
  return local_8;
}



// ============================================================
// Function: certs_compareStrings (FUN_68152850)
// Address: 68152850
// Size: 473 bytes
// Params: uint * param_1, uint * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int certs_compareStrings(uint *param_1,uint *param_2)

{
  int iVar1;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_c;

  if ((*param_1 & 0x40000000) == 0) {
    local_24 = *param_1;
  }
  else {
    local_24 = (-(uint)((*param_1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_1;
  }
  if ((*param_2 & 0x40000000) == 0) {
    local_28 = *param_2;
  }
  else {
    local_28 = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
  }
  if ((*param_1 & 0x40000000) == 0) {
    local_34 = param_1[1];
  }
  else {
    if ((*(uint *)param_1[1] & 0x40000000) == 0) {
      if ((*param_1 & 0x80000000) == 0) {
        local_30 = *param_1 >> 0xf & 0x7fff;
      }
      else {
        local_30 = 0;
      }
      local_2c = *(int *)(param_1[1] + 4) + local_30 * 2;
    }
    else {
      local_2c = crypto_getStringLen(param_1);
    }
    local_34 = local_2c;
  }
  if ((*param_2 & 0x40000000) == 0) {
    local_40 = param_2[1];
  }
  else {
    if ((*(uint *)param_2[1] & 0x40000000) == 0) {
      if ((*param_2 & 0x80000000) == 0) {
        local_3c = *param_2 >> 0xf & 0x7fff;
      }
      else {
        local_3c = 0;
      }
      local_38 = *(int *)(param_2[1] + 4) + local_3c * 2;
    }
    else {
      local_38 = crypto_getStringLen(param_2);
    }
    local_40 = local_38;
  }
  if (local_24 < local_28) {
    local_44 = local_24;
  }
  else {
    local_44 = local_28;
  }
  local_c = 0;
  while( true ) {
    if (local_44 <= local_c) {
      return local_24 - local_28;
    }
    iVar1 = (uint)*(ushort *)(local_34 + local_c * 2) - (uint)*(ushort *)(local_40 + local_c * 2);
    if (iVar1 != 0) break;
    local_c = local_c + 1;
  }
  return iVar1;
}



// ============================================================
// Function: certs_getStringLength (FUN_68152a30)
// Address: 68152a30
// Size: 47 bytes
// Params: short * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int certs_getStringLength(short *param_1)

{
  short *local_8;

  for (local_8 = param_1; *local_8 != 0; local_8 = local_8 + 1) {
  }
  return (int)local_8 - (int)param_1 >> 1;
}



// ============================================================
// Function: certs_findChar (FUN_68152a70)
// Address: 68152a70
// Size: 49 bytes
// Params: short * param_1, short param_2
// Return: short *
// Calling convention: __stdcall
// ============================================================

short * certs_findChar(short *param_1,short param_2)

{
  while( true ) {
    if (*param_1 == 0) {
      return (short *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



// ============================================================
// Function: certs_findCharInString (FUN_68152ab0)
// Address: 68152ab0
// Size: 47 bytes
// Params: short * param_1, short param_2, short * param_3
// Return: short *
// Calling convention: __stdcall
// ============================================================

short * certs_findCharInString(short *param_1,short param_2,short *param_3)

{
  while( true ) {
    if (param_3 <= param_1) {
      return (short *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



// ============================================================
// Function: certs_duplicateString (FUN_68152ae0)
// Address: 68152ae0
// Size: 45 bytes
// Params: ushort * param_1
// Return: ushort *
// Calling convention: __stdcall
// ============================================================

ushort * certs_duplicateString(ushort *param_1)

{
  uint uVar1;

  while( true ) {
    uVar1 = crypto_allocString((uint)*param_1);
    if ((uVar1 & 0x70000) != 0x40000) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



// ============================================================
// Function: certificates_convertMultibyte (FUN_68152b10)
// Address: 68152b10
// Size: 144 bytes
// Params: short * param_1, char * param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certificates_convertMultibyte(short *param_1,char *param_2,int param_3)

{
  uint uVar1;

  if (param_1 == (short *)0x0) {
    uVar1 = Ordinal_1265(param_2,param_3,0,0);
    if (0 < (int)uVar1) {
      uVar1 = -(uint)(*param_2 != '\0') & uVar1 >> 1;
    }
  }
  else {
    uVar1 = Ordinal_1265(param_2,param_3,param_1,param_3 << 1);
    if (-1 < (int)uVar1) {
      param_1[uVar1 >> 1] = 0;
      uVar1 = -(uint)(*param_1 != 0) & uVar1 >> 1;
    }
  }
  return uVar1;
}



// ============================================================
// Function: certs_createSubstring (FUN_68152bb0)
// Address: 68152bb0
// Size: 184 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint * param_4
// Return: short *
// Calling convention: __stdcall
// ============================================================

short * certs_createSubstring(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  short *psVar2;

  *param_4 = 0;
  uVar1 = Ordinal_1265(param_2,param_3,0,0);
  if ((int)uVar1 < 0) {
    psVar2 = (short *)0x0;
  }
  else {
    psVar2 = (short *)xtra_getPropertyById(param_1,(uVar1 >> 1) * 2 + 2);
    if (psVar2 == (short *)0x0) {
      psVar2 = (short *)0x0;
    }
    else {
      uVar1 = Ordinal_1265(param_2,param_3,psVar2,(uVar1 >> 1) * 2 + 2);
      if ((int)uVar1 < 0) {
        xtra_checkAndFlush(param_1,(int)psVar2);
        psVar2 = (short *)0x0;
      }
      else {
        psVar2[uVar1 >> 1] = 0;
        *param_4 = -(uint)(*psVar2 != 0) & uVar1 >> 1;
      }
    }
  }
  return psVar2;
}



// ============================================================
// Function: certs_formatString (FUN_68152c70)
// Address: 68152c70
// Size: 171 bytes
// Params: int param_1, undefined4 param_2, int param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int certs_formatString(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_14;
  int local_10;

  local_10 = 0;
  *param_4 = 0;
  iVar1 = Ordinal_1266(param_2,param_3 << 1,0,0);
  if (-1 < iVar1) {
    if (param_1 == 0) {
      local_14 = js_runGC();
    }
    else {
      local_14 = xtra_getPropertyById(param_1,iVar1 + 1);
    }
    local_10 = local_14;
    if ((local_14 != 0) &&
       (iVar1 = Ordinal_1266(param_2,param_3 << 1,local_14,iVar1 + 1), -1 < iVar1)) {
      *(undefined1 *)(local_14 + iVar1) = 0;
      *param_4 = iVar1;
    }
  }
  return local_10;
}



// ============================================================
// Function: certificates_cacheString (FUN_68152d20)
// Address: 68152d20
// Size: 104 bytes
// Params: uint param_1, undefined4 param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool certificates_cacheString(uint param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  bool bVar4;

  piVar1 = certificates_getStringCache();
  if (piVar1 == (int *)0x0) {
    bVar4 = false;
  }
  else {
    uVar2 = runtime_getCharType(param_1);
    puVar3 = crypto_findHashEntry(piVar1,uVar2,param_1);
    puVar3 = crypto_decompileBlock(piVar1,puVar3,uVar2,param_1,param_2);
    bVar4 = puVar3 != (undefined4 *)0x0;
  }
  return bVar4;
}



// ============================================================
// Function: certificates_getStringCache (FUN_68152d90)
// Address: 68152d90
// Size: 63 bytes
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * certificates_getStringCache(void)

{
  if (DAT_68196a30 == (undefined4 *)0x0) {
    DAT_68196a30 = crypto_insertHashEntry(8,runtime_getCharType,crypto_isDecompileReady,crypto_isDecompileReady,(undefined **)0x0,0);
  }
  return DAT_68196a30;
}



