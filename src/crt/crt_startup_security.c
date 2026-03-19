// Module: crt
// Topic: CRT startup, DLL entry, SEH prolog/epilog, security cookies, atexit
// Address range: 0x68001000 - 0x680018a0
// Functions (30):
//   crt_dllMain
//   __CRT_INIT@12
//   ___DllMainCRTStartup
//   crt_clearStartupReason
//   entry
//   __onexit
//   crt_unlockOnexit
//   _atexit
//   __ValidateImageBase
//   __FindPESection
//   __IsNonwritableInCurrentImage
//   initterm
//   initterm_e
//   _amsg_exit
//   __SEH_prolog4
//   __SEH_epilog4
//   crt_sehExceptionHandler
//   ___security_init_cookie
//   _unlock
//   __dllonexit
//   _lock
//   __security_check_cookie
//   except_handler4_common
//   ___report_gsfailure
//   _crt_debugger_hook
//   Ordinal_982
//   Ordinal_983
//   Ordinal_981
//   Ordinal_984
//   crt_writeRifxHeader

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68001000 - 0x68001618
// Functions (14):
//   crt_dllMain
//   __CRT_INIT@12
//   ___DllMainCRTStartup
//   crt_clearStartupReason
//   entry
//   __onexit
//   crt_unlockOnexit
//   _atexit
//   __ValidateImageBase
//   __FindPESection
//   __IsNonwritableInCurrentImage
//   initterm
//   initterm_e
//   _amsg_exit

int crt_sehExceptionHandler(); /* FIXUP: forward declaration */

// ============================================================
// Function: crt_dllMain (FUN_68001000)
// Address: 68001000
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_dllMain(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_681956e0 = param_1;
  }
  return 1;
}



// ============================================================
// Function: __CRT_INIT@12
// Address: 68001068
// Size: 522 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 2010 Release */

undefined4 __CRT_INIT_12(int *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  void *Exchange;
  BOOL BVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int *piVar8;
  
  Exchange = StackBase;
  if (param_2 == (int *)0x0) {
    if (DAT_681956e4 < 1) {
      return 0;
    }
    DAT_681956e4 = DAT_681956e4 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_6819725c,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_68197258 == 2) {
      param_2 = DecodePointer(DAT_68197264);
      if (param_2 != (int *)0x0) {
        piVar4 = DecodePointer(DAT_68197260);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = DecodePointer(DAT_68197264);
            piVar8 = DecodePointer(DAT_68197260);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_68197260 = (PVOID)encoded_null();
        DAT_68197264 = DAT_68197260;
      }
      DAT_68197258 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_6819725c,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_6819725c,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_68197258 == 0) {
      DAT_68197258 = 1;
      iVar5 = initterm_e(&DAT_68175b28,&DAT_68175b34);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_68175b20,&DAT_68175b24);
      DAT_68197258 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_6819725c,0);
    }
    if ((DAT_68197268 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_68197268), BVar2 != 0)) {
      ((code *)(size_t)DAT_68197268)(param_1,2,param_3);
    }
    DAT_681956e4 = DAT_681956e4 + 1;
  }
  return 1;
}



// ============================================================
// Function: ___DllMainCRTStartup
// Address: 68001272
// Size: 240 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __fastcall
// ============================================================

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x68001312) */
/* WARNING: Removing unreachable block (ram,0x680012bf) */
/* WARNING: Removing unreachable block (ram,0x6800133f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_68188038 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_681956e4 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(param_3,param_2,param_1), local_20 != 0)) {
    local_20 = crt_dllMain(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      crt_dllMain(param_3,0);
      __CRT_INIT_12(param_3,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(param_3,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  crt_clearStartupReason();
  return local_20;
}



// ============================================================
// Function: crt_clearStartupReason (FUN_6800137d)
// Address: 6800137d
// Size: 11 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_clearStartupReason(void)
{
  _DAT_68188038 = 0xffffffff;
  return 0;
}



// ============================================================
// Function: entry
// Address: 68001388
// Size: 35 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

void entry(int *param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return 0;
}



// ============================================================
// Function: __onexit
// Address: 680013b7
// Size: 152 bytes
// Params: _onexit_t param_1
// Return: _onexit_t
// Calling convention: __cdecl
// ============================================================

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2010 Release */

_onexit_t __cdecl __onexit(_onexit_t param_1)

{
  _onexit_t p_Var1;
  PVOID pvVar2;
  PVOID *ppvVar3;
  PVOID *ppvVar4;
  PVOID local_24;
  PVOID local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_681827a0;
  uStack_c = 0x680013c3;
  local_20[0] = DecodePointer(DAT_68197264);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_68197264);
    local_24 = DecodePointer(DAT_68197260);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_68197264 = EncodePointer(local_20[0]);
    DAT_68197260 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    crt_unlockOnexit();
  }
  return p_Var1;
}



// ============================================================
// Function: crt_unlockOnexit (FUN_6800144f)
// Address: 6800144f
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_unlockOnexit(void)
{
  _unlock(8);
  return 0;
}



// ============================================================
// Function: _atexit
// Address: 68001458
// Size: 23 bytes
// Params: _func_4879 * param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// ============================================================
// Function: __ValidateImageBase
// Address: 680014c0
// Size: 53 bytes
// Params: PBYTE pImageBase
// Return: BOOL
// Calling convention: __cdecl
// ============================================================

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b);
  }
  return 0;
}



// ============================================================
// Function: __FindPESection
// Address: 68001500
// Size: 68 bytes
// Params: PBYTE pImageBase, DWORD_PTR rva
// Return: PIMAGE_SECTION_HEADER
// Calling convention: __cdecl
// ============================================================

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2010 Release */

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14) + 0x18 + iVar1);
  if (*(ushort *)(pImageBase + iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



// ============================================================
// Function: __IsNonwritableInCurrentImage
// Address: 68001550
// Size: 166 bytes
// Params: PBYTE pTarget
// Return: BOOL
// Calling convention: __cdecl
// ============================================================

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = crt_sehExceptionHandler;
  local_14 = ExceptionList;
  local_c = DAT_68188040 ^ 0x681827c0;
  /* FIXUP: ExceptionList = &local_14; */ /* ExceptionList is a macro */
  local_8 = 0;
  BVar1 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_68000000);
  if (BVar1 != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_68000000,(DWORD_PTR)(pTarget + -0x68000000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      /* FIXUP: ExceptionList = local_14; */
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  /* FIXUP: ExceptionList = local_14; */
  return 0;
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





// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68001630 - 0x680018a0
// Functions (16):
//   __SEH_prolog4
//   __SEH_epilog4
//   crt_sehExceptionHandler
//   ___security_init_cookie
//   _unlock
//   __dllonexit
//   _lock
//   __security_check_cookie
//   except_handler4_common
//   ___report_gsfailure
//   _crt_debugger_hook
//   Ordinal_982
//   Ordinal_983
//   Ordinal_981
//   Ordinal_984
//   crt_writeRifxHeader

// ============================================================
// Function: __SEH_prolog4
// Address: 68001630
// Size: 69 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_2 */
/* Library Function - Single Match
    __SEH_prolog4
   
   Library: Visual Studio */

void __cdecl __SEH_prolog4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  iVar1 = -param_2;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_68188040 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  /* FIXUP: ExceptionList = local_8; */
  return 0;
}



// ============================================================
// Function: __SEH_epilog4
// Address: 68001675
// Size: 20 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __SEH_epilog4
   
   Library: Visual Studio */

void __SEH_epilog4(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  /* FIXUP: ExceptionList = (void *)unaff_EBP[-4]; */
  *unaff_EBP = unaff_retaddr;
  return 0;
}



// ============================================================
// Function: crt_sehExceptionHandler (FUN_68001689)
// Address: 68001689
// Size: 37 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
crt_sehExceptionHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  except_handler4_common(&DAT_68188040,__security_check_cookie,param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: ___security_init_cookie
// Address: 680016ae
// Size: 155 bytes
// Return: void
// Calling convention: __cdecl
// ============================================================

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2010 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  LARGE_INTEGER local_14;
  FILETIME local_c;
  
  (*((unsigned int *)&local_c)) = 0;
  (*((unsigned int *)&local_c + 1)) = 0;
  if ((DAT_68188040 == 0xbb40e64e) || ((DAT_68188040 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = (*((unsigned int *)&local_c + 1)) ^ (*((unsigned int *)&local_c));
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_68188040 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ (local_14).HighPart ^ (local_14).LowPart;
    if (DAT_68188040 == 0xbb40e64e) {
      DAT_68188040 = 0xbb40e64f;
    }
    else if ((DAT_68188040 & 0xffff0000) == 0) {
      DAT_68188040 = DAT_68188040 | (DAT_68188040 | 0x4711) << 0x10;
    }
  }
  DAT_68188044 = ~DAT_68188040;
  return 0;
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
// Function: __security_check_cookie
// Address: 68001762
// Size: 15 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_68188040) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: ___report_gsfailure
// Address: 68001778
// Size: 262 bytes
// Return: void
// Calling convention: __cdecl
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___report_gsfailure(void)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 unaff_retaddr;
  UINT uExitCode;
  undefined4 local_32c;
  undefined4 local_328;
  
  _DAT_68195808 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_6819580c = &stack0x00000004;
  _DAT_68195748 = 0x10001;
  _DAT_681956f0 = 0xc0000409;
  _DAT_681956f4 = 1;
  local_32c = DAT_68188040;
  local_328 = DAT_68188044;
  _DAT_681956fc = unaff_retaddr;
  _DAT_681957d4 = in_GS;
  _DAT_681957d8 = in_FS;
  _DAT_681957dc = in_ES;
  _DAT_681957e0 = in_DS;
  _DAT_681957e4 = unaff_EDI;
  _DAT_681957e8 = unaff_ESI;
  _DAT_681957ec = unaff_EBX;
  _DAT_681957f0 = in_EDX;
  _DAT_681957f4 = in_ECX;
  _DAT_681957f8 = in_EAX;
  _DAT_681957fc = unaff_EBP;
  DAT_68195800 = unaff_retaddr;
  _DAT_68195804 = in_CS;
  _DAT_68195810 = in_SS;
  DAT_68195740 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((EXCEPTION_POINTERS *)&PTR_DAT_6817661c);
  if (DAT_68195740 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return 0;
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
// Function: crt_writeRifxHeader (FUN_680018a0)
// Address: 680018a0
// Size: 137 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeRifxHeader(void)
{
  int iVar1;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20 [4];
  undefined4 local_1c;
  uint local_8;
  
  if (unaff_ESI[0x11] == 0) {
    iVar1 = crt_commitStream(unaff_EDI);
  }
  else {
    iVar1 = crt_flushStream(unaff_EDI);
    if (iVar1 != 0) goto LAB_6800191b;
    iVar1 = crt_streamRead((int)unaff_EDI,unaff_ESI[0x11]);
  }
  if (iVar1 == 0) {
    local_2c = *unaff_ESI;
    unaff_ESI[4] = 1;
    local_34 = FOURCC_RIFX;
    local_30 = 0x60;
    local_28 = FOURCC_imap;
    local_24 = 0x18;
    Ordinal_1130(local_20,0x18);
    local_1c = 0xffffffff;
    crt_streamWrite((int)unaff_EDI,&local_34,0x2c);
  }
LAB_6800191b:
  return 0;
}



