// Module: stage
// Topic: Script loading and thread management
// Address range: 0x68059430 - 0x68059A70
// Functions (15):
//   stage_initScriptConfig (FUN_68059430)
//   stage_initScriptCallback (FUN_680594A0)
//   stage_loadScriptFromData (FUN_680594E0)
//   stage_loadScriptFromDataWrapper (FUN_68059520)
//   stage_destroyScriptThread (FUN_68059530)
//   stage_destroyScriptByPath (FUN_680595A0)
//   stage_registerScriptThread (FUN_68059610)
//   stage_attachScript (FUN_68059650)
//   stage_unloadScriptThread (FUN_68059770)
//   stage_removeScriptInstance (FUN_680597A0)
//   stage_detachScript (FUN_68059860)
//   stage_dumpScriptList (FUN_68059930)
//   stage_logScriptError (FUN_68059A20)
//   stage_compareScriptRef (FUN_68059A40)
//   stage_compareScriptRefByIndex (FUN_68059A70)

// ============================================================
// Function: stage_initScriptConfig (FUN_68059430)
// Address: 68059430
// Size: 112 bytes
// Params: void * this, undefined4 param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall stage_initScriptConfig(void *this,undefined4 param_1)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  char local_5;
  
  sprites_getMemorySize();
  iVar1 = sprites_resizeMemory((int)this,in_EAX,&local_5);
  if (((iVar1 == 0) && (local_5 != '\0')) && (iVar1 = stage_loadHandlerScript(), iVar1 == 0)) {
    piVar2 = score_createXtraConfig((int)this,in_EAX,0,param_1);
    if (piVar2 == (int *)0x0) {
      return -0x7ffbffff;
    }
    stage_stripComments();
  }
  return iVar1;
}



// ============================================================
// Function: stage_initScriptCallback (FUN_680594a0)
// Address: 680594a0
// Size: 53 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_initScriptCallback(void)

{
  int iVar1;
  undefined4 *in_stack_00000028;
  
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    iVar1 = stage_initScriptConfig((void *)*in_stack_00000028,in_stack_00000028[1]);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: stage_loadScriptFromData (FUN_680594e0)
// Address: 680594e0
// Size: 49 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, void * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_loadScriptFromData(undefined4 param_1,undefined4 param_2,undefined4 param_3,void *param_4)

{
  int iVar1;
  
  iVar1 = Ordinal_2066(param_3,&DAT_68176138);
  if (iVar1 != 0) {
    iVar1 = stage_initScriptConfig(param_4,0xffffffff);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: stage_loadScriptFromDataWrapper (FUN_68059520)
// Address: 68059520
// Size: 9 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_loadScriptFromDataWrapper(undefined4 param_1,undefined4 param_2,undefined4 param_3,void *param_4)
{
  stage_loadScriptFromData(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: stage_destroyScriptThread (FUN_68059530)
// Address: 68059530
// Size: 102 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_destroyScriptThread(void)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_EDI;
  
  iVar1 = sprites_getMemorySize();
  if (iVar1 != 0) {
    iVar2 = sprites_lockMemory();
    if (iVar2 == 0) {
      Ordinal_2070(iVar1);
    }
    sprites_unlockMemory(unaff_EDI,iVar1);
    piVar3 = (int *)Ordinal_2068(iVar1);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x28))(piVar3);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_destroyScriptByPath (FUN_680595a0)
// Address: 680595a0
// Size: 100 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_destroyScriptByPath(undefined4 *param_1)
{
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  Ordinal_1309(local_820,0x400,*param_1,2);
  Ordinal_1323(local_820,local_408);
  stage_destroyScriptThread();
  return 0;
}



// ============================================================
// Function: stage_registerScriptThread (FUN_68059610)
// Address: 68059610
// Size: 56 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_registerScriptThread(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = sprites_getMemorySize();
  piVar2 = (int *)Ordinal_2068(uVar1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))(piVar2,stage_loadScriptFromData,param_1);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_attachScript (FUN_68059650)
// Address: 68059650
// Size: 284 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stage_attachScript(int param_1)
{
  int iVar1;
  uint local_18;
  int *local_14;
  uint local_10;
  undefined4 *local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  iVar1 = props_getInt(param_1);
  if (0 < iVar1) {
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                 *(int *)(param_1 + 0x18));
    local_14 = DAT_6819776c;
    local_18 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_14 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_18 = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_18 == 0x40) || (local_18 == 0x43)) {
      props_retainValue(param_1,&local_18);
      iVar1 = stage_findMatchingHandler(param_1);
      if (iVar1 < 0) {
        local_8 = props_detachString(param_1,(int *)&local_18);
        local_c = (undefined4 *)events_resolveFilePath(param_1,local_8,&local_10);
        if (local_c == (undefined4 *)0x0) {
          if (local_10 == 0) {
            props_setError(param_1,0x22);
          }
          else {
            props_normalizeType(param_1,4,-1);
          }
          Ordinal_1113(&local_8);
          Ordinal_1113(&local_c);
          return 0;
        }
        stage_registerHandler(local_8,(int)local_c);
        stage_destroyScriptByPath(local_c);
      }
      else {
        props_releaseValue(param_1,(byte)local_18,local_14);
      }
      if (*(int *)(param_1 + 0x7c) == 0) {
        props_popArgs(param_1,(undefined4 *)0x0);
      }
      return 0;
    }
  }
  props_setError(param_1,10);
  return 0;
}



// ============================================================
// Function: stage_unloadScriptThread (FUN_68059770)
// Address: 68059770
// Size: 47 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_unloadScriptThread(undefined4 param_1)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_EDI;
  
  uVar1 = sprites_getMemorySize();
  iVar2 = sprites_lockMemory();
  if (iVar2 == 0) {
    Ordinal_2074(uVar1,param_1,1);
  }
  sprites_unlockMemory(unaff_EDI,uVar1);
  return 0;
}



// ============================================================
// Function: stage_removeScriptInstance (FUN_680597a0)
// Address: 680597a0
// Size: 191 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_removeScriptInstance(int param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *local_824;
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar4 = score_removeInstance(param_1,param_2);
  if (iVar4 != 0) {
    iVar4 = **(int **)(**(int **)(param_1 + 8) + 0x50c);
    local_824 = *(undefined4 **)(iVar4 + 0x28 + param_2 * 0xc);
    uVar2 = *(undefined4 *)(iVar4 + 0x20 + param_2 * 0xc);
    puVar1 = (undefined4 *)(iVar4 + 0x20 + param_2 * 0xc);
    piVar3 = (int *)puVar1[1];
    *puVar1 = 0;
    puVar1[2] = 0;
    if (local_824 != (undefined4 *)0x0) {
      Ordinal_1309(local_820,0x400,*local_824,2);
      Ordinal_1323(local_820,local_408);
      stage_unloadScriptThread(local_408);
      Ordinal_1113(&local_824);
    }
    props_releaseValue(param_1,(byte)uVar2,piVar3);
  }
  return 0;
}



// ============================================================
// Function: stage_detachScript (FUN_68059860)
// Address: 68059860
// Size: 203 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stage_detachScript(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 < 1) {
    iVar1 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x50c) + 0x10);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        stage_removeScriptInstance(param_1,iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  else {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    iVar1 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      iVar1 = *(int *)(size_t)_DAT_68197764;
    }
    if ((iVar1 == 0x40) || (iVar1 == 0x43)) {
      iVar1 = stage_findMatchingHandler(param_1);
      if (iVar1 < 0) {
        props_normalizeType(param_1,4,-1);
      }
      else {
        stage_removeScriptInstance(param_1,iVar1);
      }
    }
    else {
      props_setError(param_1,10);
    }
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_popArgs(param_1,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: stage_dumpScriptList (FUN_68059930)
// Address: 68059930
// Size: 226 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dumpScriptList(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_814;
  int local_810;
  int local_80c;
  undefined1 local_808 [1024];
  undefined1 local_408;
  byte local_407 [1023];
  uint local_8;
  
  cast_loadPascalString(&local_408,0x898,0x10);
  props_formatValue(param_1,local_407);
  score_dumpXtraList(param_1,-1);
  iVar3 = (int)*(short *)(**(int **)(**(int **)(param_1 + 8) + 0x50c) + 0x10);
  iVar5 = 0;
  local_80c = iVar3;
  if (0 < iVar3) {
    iVar4 = 0;
    do {
      piVar1 = (int *)(**(int **)(**(int **)(param_1 + 8) + 0x50c) + 0x20 + iVar4);
      local_814 = *piVar1;
      local_810 = piVar1[1];
      if (local_814 != 0) {
        props_toPascalString(&local_814,local_808);
        props_formatValue(param_1,(byte *)"-- \"%p\"\n");
        score_dumpXtraList(param_1,iVar5);
        iVar2 = cast_waitForSync();
        iVar3 = local_80c;
        if (iVar2 != 0) break;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar5 < iVar3);
  }
  return 0;
}



// ============================================================
// Function: stage_logScriptError (FUN_68059a20)
// Address: 68059a20
// Size: 18 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl stage_logScriptError(undefined4 param_1)
{
  events_getMiawState(param_1,&stack0x00000008);
  return 0;
}



// ============================================================
// Function: stage_compareScriptRef (FUN_68059a40)
// Address: 68059a40
// Size: 34 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_compareScriptRef(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = Ordinal_1409(*(undefined4 *)(param_1 + 4),param_2,param_3);
  return iVar1 != 1;
}



// ============================================================
// Function: stage_compareScriptRefByIndex (FUN_68059a70)
// Address: 68059a70
// Size: 34 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_compareScriptRefByIndex(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = Ordinal_1420(*(undefined4 *)(param_1 + 4),param_2,param_3);
  return iVar1 != 1;
}



