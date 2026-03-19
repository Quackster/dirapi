// Module: cast
// Topic: Runtime initialization, destruction, and error handling
// Address range: 0x6802E0D0 - 0x6802E6D0
// Functions (16):
//   Ordinal_966
//   Ordinal_967
//   cast_allocHandle (FUN_6802e170)
//   cast_freeHandle
//   cast_resizeHandle
//   cast_freeIfNonNull
//   cast_allocSmallBlock
//   cast_copyPascalString
//   cast_setErrorCallback (FUN_6802e2c0)
//   cast_reportError (FUN_6802e2d0)
//   cast_runScript (FUN_6802e500)
//   cast_delegateHandler (FUN_6802e550)
//   cast_getRuntimeRef
//   cast_initRuntime (FUN_6802e5a0)
//   cast_createThreadContext (FUN_6802e660)
//   cast_destroyThreadContext (FUN_6802e6d0)

// ============================================================
// Function: Ordinal_966
// Address: 6802e0d0
// Size: 33 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_966(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int _param_1;
  int iVar1;
  
                    /* 0x2e0d0  966   */
  iVar1 = Ordinal_1260(param_1,param_3,param_2,param_4);
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: Ordinal_967
// Address: 6802e100
// Size: 111 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_967(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  
                    /* 0x2e100  967   */
  iVar3 = param_2;
  uVar1 = *(undefined1 *)(param_1 + param_3);
  uVar2 = *(undefined1 *)(param_2 + param_4);
  *(undefined1 *)(param_1 + param_3) = 0;
  *(undefined1 *)(param_2 + param_4) = 0;
  param_2 = Ordinal_1254(param_1,param_2);
  if (param_2 < 0) {
    param_2 = -1;
  }
  else if (0 < param_2) {
    param_2 = 1;
  }
  *(undefined1 *)(param_1 + param_3) = uVar1;
  *(undefined1 *)(iVar3 + param_4) = uVar2;
  iVar3 = Ordinal_1042();
  if (iVar3 != 0) {
    return -1;
  }
  return param_2;
}



// ============================================================
// Function: cast_allocHandle (FUN_6802e170)
// Address: 6802e170
// Size: 33 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_allocHandle(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = Ordinal_1111(param_1,param_2);
  DAT_68195a8c = (uint)(iVar1 == 0);
  return 0;
}



// ============================================================
// Function: cast_freeHandle (FUN_6802e1a0)
// Address: 6802e1a0
// Size: 24 bytes
// Params: undefined4 handle
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_freeHandle(undefined4 handle)
{
  Ordinal_1113(&handle);
  return 0;
}



// ============================================================
// Function: cast_resizeHandle (FUN_6802e1c0)
// Address: 6802e1c0
// Size: 49 bytes
// Params: uint param_1, undefined4 param_2, undefined4 param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint cast_resizeHandle(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = Ordinal_1117(&param_1,param_2,param_3);
  DAT_68195a8c = (uint)(iVar1 == 0);
  return ~-(uint)(iVar1 == 0) & param_1;
}



// ============================================================
// Function: cast_freeIfNonNull (FUN_6802e200)
// Address: 6802e200
// Size: 39 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_freeIfNonNull(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1 >> 0x18;
  uVar1 = CONCAT11((char)param_1,(*(unsigned char *)((char *)&param_1 + 1)));
  param_1 = CONCAT22(uVar1,CONCAT11((*(unsigned char *)((char *)&param_1 + 2)),(char)uVar2));
  return param_1;
}



// ============================================================
// Function: cast_allocSmallBlock (FUN_6802e230)
// Address: 6802e230
// Size: 29 bytes
// Params: undefined3 param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint cast_allocSmallBlock(undefined3 param_1)

{
  undefined1 in_stack_00000007;
  
  int _param_1 = 0; /* FIXUP: undeclared identifier */
  return CONCAT22((short)((uint)_param_1 >> 0x10),
                  (short)CONCAT31(param_1,(char)((uint3)param_1 >> 8)));
}



// ============================================================
// Function: cast_copyPascalString (FUN_6802e250)
// Address: 6802e250
// Size: 101 bytes
// Params: ushort * param_1, char * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_copyPascalString(ushort *param_1,char *param_2,int param_3,int param_4)
{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  
  for (; (0 < param_4 && (param_3 <= param_4)); param_4 = param_4 - param_3) {
    cVar1 = *param_2;
    pcVar4 = param_2;
    while (cVar1 != '\0') {
      cVar1 = *pcVar4;
      if (cVar1 == '1') {
        param_1 = (ushort *)((int)param_1 + 1);
      }
      else if (cVar1 == '2') {
        uVar3 = cast_allocSmallBlock((uint3)*param_1);
        *param_1 = (ushort)uVar3;
        param_1 = param_1 + 1;
      }
      else if (cVar1 == '4') {
        uVar2 = cast_freeIfNonNull(*(undefined4 *)param_1);
        *(undefined4 *)param_1 = uVar2;
        param_1 = param_1 + 2;
      }
      pcVar4 = pcVar4 + 1;
      cVar1 = *pcVar4;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_setErrorCallback (FUN_6802e2c0)
// Address: 6802e2c0
// Size: 15 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_setErrorCallback(undefined4 param_1,undefined4 param_2)
{
  _DAT_68195a90 = param_2;
  return 0;
}



// ============================================================
// Function: cast_reportError (FUN_6802e2d0)
// Address: 6802e2d0
// Size: 556 bytes
// Params: undefined * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int cast_reportError(undefined *param_1)
{
  int *piVar1;
  int iVar2;
  int local_c78;
  int local_c74;
  int local_c70;
  int local_c6c;
  int local_c68;
  undefined4 local_c64 [279];
  undefined2 local_808;
  undefined1 local_408;
  undefined1 local_407 [1023];
  
  local_c6c = 0;
  local_c70 = 0;
  local_408 = 0;
  memset(local_407,0,0x3ff);
  (*(unsigned char *)((char *)&local_808 + 0)) = 0;
  memset((undefined1 *)((int)&local_808 + 1),0,0x3ff);
  iVar2 = *(int *)(param_1 + 0x7c);
  if (iVar2 == 0) {
    events_openMiawMovie((int)param_1,0,0);
  }
  else {
    piVar1 = (int *)(param_1 + 0x80);
    if (*(int *)(param_1 + 0x80) == 0) {
      Ordinal_1233(&local_808,"");
    }
    else {
      props_setupCallback(param_1,piVar1,&local_808);
    }
    if ((*(int **)(param_1 + 0x50) == (int *)0x0) ||
       ((*(uint *)(**(int **)(param_1 + 0x50) + 0x54) & 0x800) == 0)) {
      events_openMiawMovie((int)param_1,2000,iVar2);
      *(undefined4 *)(param_1 + 0x7c) = 0;
      if ((iVar2 != 2) && ((iVar2 != 1 && (iVar2 != 0x70)))) {
        if (*(int *)(param_1 + 0x50) == 0) {
          if (*(int *)(param_1 + 0xe0) == 0) {
            return 0;
          }
          Ordinal_1233(&local_408,"");
        }
        else {
          local_c74 = stage_compileHandlerBody((int)param_1,1);
          crt_resolveMovieTarget((int)param_1,*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                       &local_c68,&local_c78);
          if (local_c68 == 0) {
            Ordinal_1233(&local_408,"");
          }
          else {
            props_parseToken(local_c64,local_c68);
            props_parseBlock(param_1,(int)local_c64,local_c74,&local_c6c,&local_c70);
            Ordinal_1234(&local_408,local_c68,local_c6c,local_c70 - local_c6c);
          }
          if (local_c78 != 0) {
            cast_freeHandle(local_c68);
          }
        }
        props_releaseValue(param_1,(byte)*piVar1,*(int **)(param_1 + 0x84));
        *piVar1 = 0;
        props_formatError((int)param_1,*(int *)(param_1 + 0x50),2000,iVar2,(int)&local_408,-1,
                     (int)&local_808,1,local_c6c);
        return 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x7c) = 0;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_runScript (FUN_6802e500)
// Address: 6802e500
// Size: 78 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 * param_4, int param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_runScript(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_5;
  piVar1 = param_2;
  if ((*(uint *)(*param_2 + 0x54) & 0x800) != 0) {
    return false;
  }
  events_openMiawMovie(param_1,0xa28,param_5);
  iVar2 = stage_reportBytecodeError(param_1,(int)piVar1,param_4,iVar2,(int *)&param_2);
  return iVar2 != 2;
}



// ============================================================
// Function: cast_delegateHandler (FUN_6802e550)
// Address: 6802e550
// Size: 9 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_delegateHandler(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  events_setMiawName(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_getRuntimeRef (FUN_6802e560)
// Address: 6802e560
// Size: 56 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_getRuntimeRef(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = sprites_resolveTextChannel(param_1);
  if (iVar2 == 1) {
    *(undefined4 *)(param_1 + 0x74) = 8;
    *(undefined4 *)(param_1 + 0x7c) = 1;
  }
  if (iVar1 != *(int *)(param_1 + 0x3c)) {
    props_selectScript(param_1,iVar1);
  }
  return iVar2;
}



// ============================================================
// Function: cast_initRuntime (FUN_6802e5a0)
// Address: 6802e5a0
// Size: 188 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_initRuntime(undefined4 *param_1)
{
  undefined4 uVar1;
  
  stage_initParserModule(param_1);
  param_1[1] = cast_delegateHandler;
  *param_1 = cast_runScript;
  param_1[0x13e] = cast_reportError;
  uVar1 = cast_allocHandle(0x10,1);
  param_1[0x158] = uVar1;
  uVar1 = cast_allocHandle(0x10,1);
  param_1[0x159] = uVar1;
  *(undefined4 *)(*(int *)param_1[0x158] + 0xc) = uVar1;
  *(undefined4 *)(*(int *)param_1[0x159] + 8) = param_1[0x158];
  uVar1 = cast_allocHandle(0x10,1);
  param_1[0x156] = uVar1;
  uVar1 = cast_allocHandle(0x10,1);
  param_1[0x157] = uVar1;
  *(undefined4 *)(*(int *)param_1[0x156] + 0xc) = uVar1;
  *(undefined4 *)(*(int *)param_1[0x157] + 8) = param_1[0x156];
  param_1[0x15a] = 0;
  param_1[0x15b] = param_1 + 0x15c;
  param_1[0x15c] = param_1 + 0x15a;
  param_1[0x15d] = 0;
  return 0;
}



// ============================================================
// Function: cast_createThreadContext (FUN_6802e660)
// Address: 6802e660
// Size: 109 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createThreadContext(int *param_1,int param_2,int param_3)
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_2;
  iVar1 = Ordinal_1124(0x13c);
  param_1[2] = iVar1;
  Ordinal_1130(iVar1,0x13c);
  *(int **)(param_1[2] + 8) = param_1;
  *(int **)(param_1[2] + 0xc) = param_1;
  props_initThread((undefined4 *)param_1[2],4000);
  if (*(int *)**(int **)(param_2 + 0x4e4) == 0) {
    stage_initDataNode(param_1[2],*(int **)(param_2 + 0x4e4),0);
    core_initSymbolLookups(param_1[2]);
  }
  return 0;
}



// ============================================================
// Function: cast_destroyThreadContext (FUN_6802e6d0)
// Address: 6802e6d0
// Size: 45 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_destroyThreadContext(int param_1)
{
  if (*(int *)(param_1 + 0x10) != 0) {
    core_releaseMovieResource(*(int *)(param_1 + 8));
  }
  props_destroyThread(*(int **)(param_1 + 8));
  Ordinal_1125(param_1 + 8);
  return 0;
}



