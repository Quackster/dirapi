// Module: strings
// Topic: Import thunks, intrinsic math, CRT library functions
// Address range: 0x68166a70 - 0x68166dee
// Functions (39):
//   strings_compareRange
//   VerQueryValueA
//   GetFileVersionInfoW
//   GetFileVersionInfoSizeW
//   __alloca_probe
//   memset
//   strings_floatToUint64
//   strings_roundToUint64 (strings_roundToUint64)
//   _CIsqrt
//   _CIcos
//   _CIsin
//   _CIacos
//   floor
//   memcpy
//   __aulldvrm
//   _CIfmod
//   _CIasin
//   _CIatan
//   _CIexp
//   _CIlog
//   __alldiv
//   __aullshr
//   __allmul
//   _CItan
//   strlen
//   fmod
//   Ordinal_1130
//   Ordinal_1115
//   Ordinal_1114
//   Ordinal_1116
//   Ordinal_2331
//   Ordinal_1125
//   Ordinal_1111
//   Ordinal_1124
//   Ordinal_2330
//   Ordinal_1129
//   Ordinal_2045
//   Ordinal_1313
//   Ordinal_1113

// ============================================================
// Function: strings_compareRange (FUN_68166a70)
// Address: 68166a70
// Size: 43 bytes
// Params: uint * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool strings_compareRange(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = strings_parseExpression(param_1,param_2);
  if (iVar1 != param_3) {
    strings_resetScanner(param_2);
  }
  return iVar1 == param_3;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: __alloca_probe
// Address: 68166ab0
// Size: 43 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: This is an inlined function */

void __alloca_probe(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)((int)&stack0x00000000 - (int)in_EAX & ~-(uint)(&stack0x00000000 < in_EAX))
  ;
  for (puVar1 = (undefined4 *)((uint)auStack_4 & 0xfffff000); puVar2 < puVar1;
      puVar1 = puVar1 + -0x400) {
  }
  *puVar2 = unaff_retaddr;
  return;
}



// ============================================================
// Function: memset
// Address: 68166adc
// Size: 6 bytes
// THUNK -> memset
// Params: void * _Dst, int _Val, size_t _Size
// Return: void *
// Calling convention: __cdecl
// ============================================================

/* FIXUP(C2169: 'memset': intrinsic function, cannot be defined): void * __cdecl memset(void *_Dst,int _Val,size_t _Size) */

/* FIXUP(C2449: found '{' at file scope (missing function header?)): { */
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x68166adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  /* FIXUP(C2040: 'pvVar1': 'int' differs in levels of indirection from 'void *'): pvVar1 = memset(_Dst,_Val,_Size); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return pvVar1; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: strings_floatToUint64 (FUN_68166af0)
// Address: 68166af0
// Size: 28 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: ulonglong
// Calling convention: __fastcall
// ============================================================

ulonglong __fastcall strings_floatToUint64(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint uStack_20;
  float fStack_1c;
  
  if (DAT_68197254 == 0) {
    uVar1 = (ulonglong)ROUND(in_ST0);
    uStack_20 = (uint)uVar1;
    fStack_1c = (float)(uVar1 >> 0x20);
    fVar3 = (float)in_ST0;
    if ((uStack_20 != 0) || (fVar3 = fStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
      if ((int)fVar3 < 0) {
        uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
      }
      else {
        uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
        uVar1 = CONCAT44((int)fStack_1c - (uint)(uStack_20 < uVar2),uStack_20 - uVar2);
      }
    }
    return uVar1;
  }
  return CONCAT44(param_2,(int)in_ST0);
}



// ============================================================
// Function: strings_roundToUint64 (strings_roundToUint64)
// Address: 68166b26
// Size: 117 bytes
// Return: ulonglong
// Calling convention: __stdcall
// ============================================================

ulonglong strings_roundToUint64(void)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  uVar1 = (ulonglong)ROUND(in_ST0);
  local_20 = (uint)uVar1;
  uStack_1c = (float)(uVar1 >> 0x20);
  fVar3 = (float)in_ST0;
  if ((local_20 != 0) || (fVar3 = uStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
    if ((int)fVar3 < 0) {
      uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
    }
    else {
      uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
      uVar1 = CONCAT44((int)uStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);
    }
  }
  return uVar1;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: memcpy
// Address: 68166bba
// Size: 6 bytes
// THUNK -> memcpy
// Params: void * _Dst, void * _Src, size_t _Size
// Return: void *
// Calling convention: __cdecl
// ============================================================

/* FIXUP(C2169: 'memcpy': intrinsic function, cannot be defined): void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size) */

/* FIXUP(C2449: found '{' at file scope (missing function header?)): { */
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x68166bba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  /* FIXUP(C2040: 'pvVar1': 'int' differs in levels of indirection from 'void *'): pvVar1 = memcpy(_Dst,_Src,_Size); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return pvVar1; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: __aulldvrm
// Address: 68166bc0
// Size: 149 bytes
// Params: uint param_1, uint param_2, uint param_3, uint param_4
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

/* Library Function - Single Match
    __aulldvrm
   
   Library: Visual Studio */

undefined8 __aulldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: __alldiv
// Address: 68166c80
// Size: 170 bytes
// Params: uint param_1, uint param_2, uint param_3, uint param_4
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

/* Library Function - Single Match
    __alldiv
   
   Library: Visual Studio */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}



// ============================================================
// Function: __aullshr
// Address: 68166d30
// Size: 31 bytes
// Params: byte param_1, uint param_2
// Return: ulonglong
// Calling convention: __fastcall
// ============================================================

/* Library Function - Single Match
    __aullshr
   
   Library: Visual Studio */

ulonglong __fastcall __aullshr(byte param_1,uint param_2)

{
  uint in_EAX;
  
  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 >> (param_1 & 0x1f),
                    in_EAX >> (param_1 & 0x1f) | param_2 << 0x20 - (param_1 & 0x1f));
  }
  return (ulonglong)(param_2 >> (param_1 & 0x1f));
}



// ============================================================
// Function: __allmul
// Address: 68166d50
// Size: 52 bytes
// Params: uint param_1, int param_2, uint param_3, int param_4
// Return: longlong
// Calling convention: __stdcall
// ============================================================

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




