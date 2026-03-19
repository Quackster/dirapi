// Module: lingo
// Topic: Lingo context resolution and COM interface helpers
// Address range: 0x6809A600 - 0x6809ADE0
// Functions (24):
//   lingo_getGlobalCount
//   lingo_getGlobalValue
//   lingo_resolveGlobalPair
//   lingo_resolveGlobalPairEx
//   lingo_getGlobalRef
//   lingo_setGlobalRef
//   lingo_setGlobalValue
//   lingo_setGlobalProperty
//   lingo_getGlobalProperty
//   lingo_getGlobalState
//   lingo_releaseGlobalState
//   lingo_getGlobalType
//   lingo_getGlobalFlags
//   lingo_resolveRef
//   lingo_getRefData
//   lingo_resolveRefEx
//   lingo_resolveContext (FUN_6809ab60)
//   lingo_cleanupContext
//   lingo_cleanupDisplayEx
//   lingo_checkState
//   lingo_enterScriptMode
//   lingo_runScript
//   lingo_runScriptWithResult
//   lingo_cleanupDisplay


// ============================================================
// Function: lingo_getGlobalCount (FUN_6809a600)
// Address: 6809a600
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getGlobalCount(void)
{
  Ordinal_2060();
  return 0;
}



// ============================================================
// Function: lingo_getGlobalValue (FUN_6809a610)
// Address: 6809a610
// Size: 31 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getGlobalValue(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Ordinal_2064(param_1,0,0);
  Ordinal_1039();
  return uVar1;
}



// ============================================================
// Function: lingo_resolveGlobalPair (FUN_6809a630)
// Address: 6809a630
// Size: 74 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_resolveGlobalPair(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = Ordinal_2066(param_3,&DAT_68175d38);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_4 + 0x20))(param_4,param_1,0,&param_3);
    if (iVar1 == 0) {
      (**(code **)(*param_3 + 0xc))(param_3);
      (**(code **)(*param_3 + 8))(param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_resolveGlobalPairEx (FUN_6809a680)
// Address: 6809a680
// Size: 74 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_resolveGlobalPairEx(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = Ordinal_2066(param_3,&DAT_68175d48);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_4 + 0x20))(param_4,param_1,0,&param_3);
    if (iVar1 == 0) {
      (**(code **)(*param_3 + 0xc))(param_3);
      (**(code **)(*param_3 + 8))(param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_getGlobalRef (FUN_6809a6e0)
// Address: 6809a6e0
// Size: 18 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getGlobalRef(int param_1)

{
  return **(undefined4 **)(param_1 + 0x35c);
}



// ============================================================
// Function: lingo_setGlobalRef (FUN_6809a700)
// Address: 6809a700
// Size: 42 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_setGlobalRef(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x35c) + 4);
  (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
  return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 8);
}



// ============================================================
// Function: lingo_setGlobalValue (FUN_6809a730)
// Address: 6809a730
// Size: 42 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_setGlobalValue(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x35c) + 0xc);
  (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
  return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 0x10);
}



// ============================================================
// Function: lingo_setGlobalProperty (FUN_6809a760)
// Address: 6809a760
// Size: 61 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_setGlobalProperty(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x35c) + 0x14);
  (**(code **)(*piVar1 + 0xc))(piVar1,param_2);
  piVar1 = *(int **)(*(int *)(param_1 + 0x35c) + 0x14);
  (**(code **)(*piVar1 + 0x14))(piVar1,0);
  return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 0x18);
}



// ============================================================
// Function: lingo_getGlobalProperty (FUN_6809a7a0)
// Address: 6809a7a0
// Size: 74 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint lingo_getGlobalProperty(uint param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1;
  piVar1 = *(int **)(*(int *)(param_1 + 0x35c) + 0x14);
  (**(code **)(*piVar1 + 0x18))(piVar1,(int)&param_1 + 3);
  piVar1 = *(int **)(*(int *)(uVar2 + 0x35c) + 0x14);
  (**(code **)(*piVar1 + 0xc))(piVar1,0);
  piVar1 = *(int **)(*(int *)(uVar2 + 0x35c) + 0x14);
  uVar3 = (**(code **)(*piVar1 + 0x14))(piVar1,0);
  return CONCAT31((int3)((uint)uVar3 >> 8),(*(unsigned char *)((char *)&param_1 + 3)));
}



// ============================================================
// Function: lingo_getGlobalState (FUN_6809a7f0)
// Address: 6809a7f0
// Size: 74 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_getGlobalState(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  piVar1 = (int *)(param_1 + 0x360);
  if (*(int *)(param_1 + 0x360) == 0) {
    uVar2 = Ordinal_1038(&DAT_681761d8,&DAT_681761e8,piVar1);
    Ordinal_2063(uVar2);
    if (*piVar1 == 0) goto LAB_6809a833;
  }
  (**(code **)(*(int *)*piVar1 + 4))((int *)*piVar1);
LAB_6809a833:
  return *piVar1;
}



// ============================================================
// Function: lingo_releaseGlobalState (FUN_6809a840)
// Address: 6809a840
// Size: 40 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_releaseGlobalState(int param_1)
{
  int param_4;
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x360);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x360) = 0;
  }
  return 0;
}



// ============================================================
// Function: lingo_getGlobalType (FUN_6809a870)
// Address: 6809a870
// Size: 71 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getGlobalType(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x35c) + 0x20);
  if (*piVar1 == 0) {
    uVar2 = Ordinal_1038(&DAT_68176158,&DAT_68176148,piVar1);
    Ordinal_2063(uVar2);
    return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 0x20);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 0x20);
}



// ============================================================
// Function: lingo_getGlobalFlags (FUN_6809a8c0)
// Address: 6809a8c0
// Size: 71 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getGlobalFlags(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x35c) + 0x24);
  if (*piVar1 == 0) {
    uVar2 = Ordinal_1038(&DAT_68176178,&DAT_68176168,piVar1);
    Ordinal_2063(uVar2);
    return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 0x24);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x35c) + 0x24);
}



// ============================================================
// Function: lingo_resolveRef (FUN_6809a910)
// Address: 6809a910
// Size: 143 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 lingo_resolveRef(int param_1,int param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = Ordinal_1541();
  if ((param_2 != 0) && ((uint)(iVar2 - *(int *)(param_1 + 0x37c)) <= *(uint *)(param_1 + 0x378))) {
    return 1;
  }
  uVar1 = 0;
  piVar3 = (int *)lingo_getGlobalState(param_1);
  if (piVar3 == (int *)0x0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0x80041090;
      *(int *)(param_1 + 0x37c) = iVar2;
      return 0;
    }
  }
  else {
    uVar1 = (**(code **)(*piVar3 + 0x3c))(piVar3,param_3);
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  *(int *)(param_1 + 0x37c) = iVar2;
  return uVar1;
}



// ============================================================
// Function: lingo_getRefData (FUN_6809a9a0)
// Address: 6809a9a0
// Size: 104 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getRefData(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_stack_0000001c;
  int *in_stack_00000020;
  int *in_stack_00000024;
  undefined4 *in_stack_00000028;
  
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2068(uVar1);
  lingo_resolveGlobalPair(in_stack_0000001c,in_stack_00000020,in_stack_00000024,piVar2);
  (**(code **)(*piVar2 + 8))(piVar2);
  iVar3 = Ordinal_2066(&DAT_68176138,in_stack_00000024);
  if (iVar3 != 0) {
    media_loadScriptData(in_stack_0000001c,in_stack_00000020,in_stack_00000024,(void *)*in_stack_00000028);
  }
  media_registerCastAssetSimple(in_stack_0000001c,in_stack_00000020,in_stack_00000024,in_stack_00000028[1],
               *in_stack_00000028);
  return 0;
}



// ============================================================
// Function: lingo_resolveRefEx (FUN_6809aa10)
// Address: 6809aa10
// Size: 324 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_resolveRefEx(int *param_1,int param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_418;
  int local_414;
  int *local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_414 = param_2;
  uVar1 = Ordinal_1038();
  local_410 = (int *)Ordinal_2068(uVar1);
  if (local_410 != (int *)0x0) {
    uVar5 = uVar1;
    local_40c = lingo_getGlobalCount();
    if (local_40c == 0) {
      local_40c = 0;
      iVar3 = param_3;
      iVar4 = param_2;
      if (0 < param_3) {
        do {
          iVar2 = Ordinal_1323(iVar4,local_408,uVar5);
          if (iVar2 != 0) {
            Ordinal_2070(uVar1,local_408,1);
          }
          iVar3 = iVar3 + -1;
          param_2 = local_414;
          iVar4 = iVar4 + 0x418;
        } while (iVar3 != 0);
      }
      local_40c = lingo_getGlobalValue(uVar1);
      if (local_40c == 0) {
        local_414 = lingo_getGlobalRef((int)param_1);
        local_418 = *(undefined4 *)(*(int *)(*param_1 + 0x14) + 0x14);
        if (0 < param_3) {
          do {
            iVar3 = Ordinal_1323(param_2,local_408);
            if (iVar3 != 0) {
              (**(code **)(*local_410 + 0x28))(local_410,local_408,1,lingo_getRefData,&local_418);
            }
            param_2 = param_2 + 0x418;
            param_3 = param_3 + -1;
          } while (param_3 != 0);
        }
      }
    }
    (**(code **)(*local_410 + 8))(local_410);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: lingo_cleanupContext (FUN_6809ad90)
// Address: 6809ad90
// Size: 75 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_cleanupContext(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_68196374 == (int *)0x0) {
    iVar2 = crt_getGlobalState();
    return iVar2;
  }
  iVar1 = ((int *)(size_t)DAT_68196374)[2];
  if (iVar1 == 0) {
    if ((*(int *)(size_t)DAT_68196374 != 0) && (*(int *)(*(int *)(size_t)DAT_68196374 + 0x20) != 0)) {
      return *(int *)(**(int **)(*(int *)(*(int *)(*(int *)(size_t)DAT_68196374 + 0x20) + 4) + 8) + 0xc);
    }
    iVar2 = *(int *)(*(int *)(size_t)piRam00000008 /* FIXUP(C2100): cast for dereference */ + 0xc);
  }
  else {
    if (iVar1 == 1) {
      return *(int *)(*(int *)(size_t)DAT_68196374 + 0xc);
    }
    if (iVar1 == 2) {
      return *(int *)(size_t)DAT_68196374;
    }
  }
  return iVar2;
}



// ============================================================
// Function: lingo_cleanupDisplayEx (FUN_6809ade0)
// Address: 6809ade0
// Size: 46 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cleanupDisplayEx(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)lingo_getGlobalState(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x38))(piVar1,&param_1);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}


// ============================================================
// Function: lingo_checkState (FUN_68092d10)
// Address: 68092d10
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_checkState(int param_1)
{
  uint uVar1;
  undefined4 local_10;

  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    if (*(int *)(*(int *)(param_1 + 0x20) + 4) != 0) {
      Ordinal_2330();
      local_10 = DAT_68196374;
    }
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


// ============================================================
// Function: lingo_enterScriptMode (FUN_680924b0)
// Address: 680924b0
// Size: 165 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_enterScriptMode(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  playback_createMediaBuffer(iVar2,param_2);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


// ============================================================
// Function: lingo_runScript (FUN_68092a20)
// Address: 68092a20
// Size: 154 bytes
// Params: int param_1, char * param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_runScript(int param_1,char *param_2,byte param_3)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  stage_setSpriteEvalMode(*(int *)(*(int *)(iVar1 + 0x20) + 8),param_2,param_3);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


// ============================================================
// Function: lingo_runScriptWithResult (FUN_68092ac0)
// Address: 68092ac0
// Size: 164 bytes
// Params: int param_1, char * param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_runScriptWithResult(int param_1,char *param_2,byte param_3)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  stage_setSpriteEvalModeEx(*(int *)(*(int *)(iVar1 + 0x20) + 8),param_2,param_3);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


// ============================================================
// Function: lingo_cleanupDisplay (FUN_6809ae10)
// Address: 6809ae10
// Size: 368 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cleanupDisplay(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;

  uVar4 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  lingo_cleanupDisplayEx(param_1);
  lingo_releaseGlobalState(param_1);
  piVar5 = (int *)(param_1 + 0x35c);
  media_freeSpriteEntries(*(undefined4 **)(param_1 + 0x35c));
  iVar1 = *piVar5;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != 0) {
      (**(code **)(**(int **)(iVar1 + 8) + 8))(*(int **)(iVar1 + 8));
      *(undefined4 *)(*piVar5 + 8) = 0;
    }
    if (*(int *)(*piVar5 + 4) != 0) {
      piVar3 = *(int **)(*piVar5 + 4);
      (**(code **)(*piVar3 + 0x10))(piVar3,&local_24);
      (**(code **)(**(int **)(*piVar5 + 4) + 8))(*(int **)(*piVar5 + 4));
      *(undefined4 *)(*piVar5 + 4) = 0;
    }
    if (*(int *)(*piVar5 + 0x10) != 0) {
      piVar3 = *(int **)(*piVar5 + 0x10);
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(*piVar5 + 0x10) = 0;
    }
    if (*(int *)(*piVar5 + 0xc) != 0) {
      piVar3 = *(int **)(*piVar5 + 0xc);
      (**(code **)(*piVar3 + 0x10))(piVar3,&local_24);
      (**(code **)(**(int **)(*piVar5 + 0xc) + 8))(*(int **)(*piVar5 + 0xc));
      *(undefined4 *)(*piVar5 + 0xc) = 0;
    }
    if (*(int *)(*piVar5 + 0x18) != 0) {
      piVar3 = *(int **)(*piVar5 + 0x18);
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(*piVar5 + 0x18) = 0;
    }
    if (*(int *)(*piVar5 + 0x14) != 0) {
      piVar3 = *(int **)(*piVar5 + 0x14);
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(*piVar5 + 0x14) = 0;
    }
    if (*(int *)(*piVar5 + 0x20) != 0) {
      piVar3 = *(int **)(*piVar5 + 0x20);
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(*piVar5 + 0x20) = 0;
    }
    if (*(int *)(*piVar5 + 0x24) != 0) {
      piVar3 = *(int **)(*piVar5 + 0x24);
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(*piVar5 + 0x24) = 0;
    }
  }
  media_destroyXtraDispatchWrapper(param_1);
  if (param_2 != 0) {
    uVar2 = Ordinal_1038();
    piVar3 = (int *)Ordinal_2068(uVar2);
    if (piVar3 != (int *)0x0) {
      uVar4 = (**(code **)(*piVar3 + 0x14))(piVar3,lingo_resolveGlobalPairEx,piVar3);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  Ordinal_1125(piVar5);
  return uVar4;
}


// ============================================================
// Function: lingo_resolveContext (FUN_6809ab60)
// Address: 6809ab60
// Size: 546 bytes
// Params: int *outMovie, int *outCastLib, int *outCastMember, int *outScore, int *outStage, int *outVtable, int *outMovieDesc
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_resolveContext(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;

  piVar7 = (int *)0x0;
  iVar6 = 0;
  local_18 = 0;
  local_20 = 0;
  piVar4 = DAT_68196374;
  if (DAT_68196374 == (int *)0x0) {
    iVar3 = crt_getGlobalState();
    if ((*(code **)(iVar3 + 0x70) != (code *)0x0) &&
       (iVar3 = (**(code **)(iVar3 + 0x70))(), iVar3 != 0)) {
      iVar6 = *(int *)(iVar3 + 0xc);
      if (iVar6 != 0) {
        piVar7 = *(int **)(iVar6 + 0x20);
      }
      piVar4 = (int *)0x0;
      if ((piVar7 != (int *)0x0) && (piVar7[1] != 0)) {
        piVar4 = *(int **)(piVar7[1] + 8);
        if ((iVar6 == 0) ||
           ((*(int **)(iVar6 + 0x20) == (int *)0x0 || (iVar6 = **(int **)(iVar6 + 0x20), iVar6 == 0)
            ))) {
          iVar6 = *piVar7;
        }
        Ordinal_2330();
        local_10 = DAT_68196374;
        local_c = 0;
        DAT_68196374 = &local_14;
        local_14 = iVar6;
      }
      local_18 = 0;
      if ((*(int *)(iVar3 + 0xc) != 0) &&
         (piVar1 = *(int **)(*(int *)(iVar3 + 0xc) + 0x20), piVar1 != (int *)0x0)) {
        local_18 = *piVar1;
      }
      iVar6 = *piVar4;
      if (piVar7 != (int *)0x0) {
        DAT_68196374 = local_10;
        Ordinal_2331();
      }
    }
  }
  else {
    do {
      iVar3 = piVar4[2];
      if (iVar3 == 0) {
        iVar3 = *piVar4;
        if ((((iVar3 == 0) || (*(int *)(iVar3 + 0x20) == 0)) ||
            (iVar5 = *(int *)(*(int *)(iVar3 + 0x20) + 4), iVar5 == 0)) ||
           (piVar7 = *(int **)(iVar5 + 8), piVar7 == (int *)0x0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *piVar7;
        }
        iVar2 = iVar5;
        if ((iVar6 == 0) || (iVar2 = iVar6, iVar6 == iVar5)) {
          iVar6 = iVar2;
          local_18 = iVar3;
        }
        break;
      }
      iVar5 = iVar6;
      if (iVar3 == 1) {
        iVar5 = *piVar4;
        if ((iVar6 != 0) && (iVar5 = iVar6, *piVar4 != iVar6)) break;
      }
      else if (iVar3 == 3) {
        local_20 = *piVar4;
      }
      iVar6 = iVar5;
      piVar4 = (int *)piVar4[1];
    } while (piVar4 != (int *)0x0);
  }
  iVar3 = 0;
  piVar7 = (int *)0x0;
  local_1c = 0;
  if (local_18 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(local_18 + 0x20);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 4) != 0)) {
      piVar7 = *(int **)(*(int *)(iVar5 + 4) + 8);
      if ((piVar7 == (int *)0x0) || (*piVar7 == 0)) {
        local_1c = *(int *)(iVar5 + 8);
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piVar7 + 0x14);
        local_1c = *(int *)(iVar5 + 8);
      }
      goto LAB_6809acf5;
    }
  }
  if (iVar6 != 0) {
    piVar7 = *(int **)(iVar6 + 0x10);
    iVar3 = *(int *)(iVar6 + 0x14);
  }
LAB_6809acf5:
  if (param_1 != (int *)0x0) {
    *param_1 = local_18;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar6;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = iVar5;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = (int)piVar7;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = iVar3;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = local_1c;
  }
  if (param_3 != (int *)0x0) {
    if (((local_1c != 0) && (iVar6 = *(int *)(local_1c + 0xc), iVar6 != 0)) ||
       ((iVar3 != 0 && (iVar6 = *(int *)(iVar3 + 0x14), iVar6 != 0)))) {
      *param_3 = iVar6;
      return 0;
    }
    *param_3 = local_20;
  }
  return 0;
}


