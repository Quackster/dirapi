// Module: cast
// Topic: Script context management and event dispatch
// Address range: 0x6802E700 - 0x6802ECA0
// Functions (12):
//   cast_releaseLocals
//   cast_destroyContext
//   cast_freeContextHandles
//   cast_isContextValid
//   cast_assignVariable
//   cast_setReturnValue
//   cast_getScriptCount
//   cast_invalidateScript
//   cast_invalidateScriptByIndex
//   cast_dispatchEvent
//   cast_invokeHandler
//   cast_resolveHandlerByName

// ============================================================
// Function: cast_releaseLocals (FUN_6802e700)
// Address: 6802e700
// Size: 88 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_releaseLocals(undefined4 param_1)
{
  int param_4;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int *unaff_EBX;
  int iVar5;
  
  if ((unaff_EBX != (int *)0x0) &&
     (uVar4 = (uint)*(ushort *)(*unaff_EBX + 0x14), 0 < (short)*(ushort *)(*unaff_EBX + 0x14))) {
    iVar5 = 0;
    do {
      iVar1 = iVar5 + 0x24 + *unaff_EBX;
      if (*(int *)(iVar5 + 0x24 + *unaff_EBX) != -1) {
        piVar2 = *(int **)(iVar1 + 0xc);
        uVar3 = *(undefined4 *)(iVar1 + 8);
        *(undefined4 *)(iVar1 + 8) = 2;
        *(undefined4 *)(iVar1 + 0xc) = 0;
        props_releaseValue(param_1,(byte)uVar3,piVar2);
      }
      iVar5 = iVar5 + 0x10;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return 0;
}



// ============================================================
// Function: cast_destroyContext (FUN_6802e760)
// Address: 6802e760
// Size: 217 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_destroyContext(uint param_1)
{
  int iVar1;
  void *this;
  
  props_releaseObject(param_1,*(int **)(**(int **)(param_1 + 8) + 0x524));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x524) = 0;
  props_releaseObject(param_1,*(int **)(**(int **)(param_1 + 8) + 0x528));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x528) = 0;
  stage_freeObjectDispatch(this,param_1);
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4e4);
  *(undefined4 *)(**(int **)(iVar1 + 8) + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4e4);
  *(undefined4 *)(**(int **)(iVar1 + 0xc) + 8) = *(undefined4 *)(iVar1 + 8);
  props_freeTable(param_1,*(int **)(**(int **)(param_1 + 8) + 0x4e4));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4e4) = 0;
  core_clearSymbolLookups();
  props_destroyTable(param_1,*(int **)(**(int **)(param_1 + 8) + 0x4f4));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4f4) = 0;
  cast_releaseLocals(param_1);
  stage_releaseObjectHandler(param_1);
  return 0;
}



// ============================================================
// Function: cast_freeContextHandles (FUN_6802e840)
// Address: 6802e840
// Size: 105 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_freeContextHandles(int param_1)
{
  stage_destroyParseContext(param_1);
  cast_freeHandle(*(undefined4 *)(param_1 + 0x560));
  *(undefined4 *)(param_1 + 0x560) = 0;
  cast_freeHandle(*(undefined4 *)(param_1 + 0x564));
  *(undefined4 *)(param_1 + 0x564) = 0;
  cast_freeHandle(*(undefined4 *)(param_1 + 0x558));
  *(undefined4 *)(param_1 + 0x558) = 0;
  cast_freeHandle(*(undefined4 *)(param_1 + 0x55c));
  *(undefined4 *)(param_1 + 0x55c) = 0;
  Ordinal_1130(param_1,0x5d8);
  return 0;
}



// ============================================================
// Function: cast_isContextValid (FUN_6802e8b0)
// Address: 6802e8b0
// Size: 27 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_isContextValid(int param_1)

{
  return *(int *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0xe8) != 0;
}



// ============================================================
// Function: cast_assignVariable (FUN_6802e8d0)
// Address: 6802e8d0
// Size: 301 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_assignVariable(int *param_1,undefined4 param_2,undefined4 param_3)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int local_46c;
  int *local_468;
  undefined4 local_464 [279];
  uint local_8;
  
  props_parseToken(local_464,param_2);
  props_setParserState(param_1,local_464,0);
  if (local_46c == 8) {
    uVar2 = props_resolveSymbol((int)param_1,(uint)local_468);
    iVar3 = score_resolveExpression(param_1,0x40,param_3);
    if ((iVar3 == 0) || (param_1[0x1d] != 2)) {
      param_1[0x1f] = 0;
    }
    else {
      props_pushValue((int)param_1);
      param_1[7] = 4;
      param_1[8] = -0x80000000;
      props_dispatchOpcode(param_1,(int *)0x2,0,0);
      if (param_1[0x1d] != 8) {
        puVar4 = props_resolveVariable((int)param_1,uVar2,0,1);
        if (puVar4 != (uint *)0x0) {
          piVar1 = (int *)puVar4[1];
          uVar2 = *puVar4;
          *puVar4 = param_1[7];
          puVar4[1] = param_1[8];
          props_releaseValue(param_1,(byte)uVar2,piVar1);
        }
        param_1[6] = param_1[6] + -8;
        iVar3 = *(int *)param_1[4];
        param_1[7] = *(int *)(iVar3 + param_1[6]);
        param_1[8] = *(int *)(iVar3 + 4 + param_1[6]);
        return 0;
      }
    }
  }
  else {
    props_releaseValue(param_1,(byte)local_46c,local_468);
  }
  return 0;
}



// ============================================================
// Function: cast_setReturnValue (FUN_6802ea00)
// Address: 6802ea00
// Size: 50 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setReturnValue(int param_1,undefined4 param_2,undefined4 param_3)
{
  props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0xac),*(int **)(param_1 + 0xb0));
  *(undefined4 *)(param_1 + 0xac) = param_2;
  *(undefined4 *)(param_1 + 0xb0) = param_3;
  return 0;
}



// ============================================================
// Function: cast_getScriptCount (FUN_6802ea40)
// Address: 6802ea40
// Size: 29 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_getScriptCount(int param_1)

{
  int iVar1;
  
  iVar1 = props_allocScriptEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x4f4));
  return iVar1 + 1;
}



// ============================================================
// Function: cast_invalidateScript (FUN_6802ea60)
// Address: 6802ea60
// Size: 51 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_invalidateScript(uint param_1,int param_2)
{
  int *piVar1;
  
  if (param_2 != 0) {
    if ((**(int **)(param_1 + 8) != 0) &&
       (piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x4f4), piVar1 != (int *)0x0)) {
      props_invalidateTableEntry(param_1,piVar1,(int)(short)((short)param_2 + -1),0);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_invalidateScriptByIndex (FUN_6802eaa0)
// Address: 6802eaa0
// Size: 39 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_invalidateScriptByIndex(uint param_1,int param_2)
{
  if (param_2 != 0) {
    props_invalidateTableEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x4f4),param_2 + -1,1);
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchEvent (FUN_6802ead0)
// Address: 6802ead0
// Size: 165 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_dispatchEvent(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4f4);
  iVar4 = iVar1 + 0xc + param_2 * 0x18;
  if (param_3 < 0x1a) {
    iVar5 = **(int **)(iVar4 + 8);
    iVar3 = *(int *)(iVar5 + 0x40 + param_3 * 4);
    if (-1 < iVar3) goto LAB_6802eb2e;
  }
  iVar4 = *(int *)(**(int **)(iVar4 + 8) + 0x40);
  if (iVar4 < 0) {
    return 0;
  }
  iVar5 = **(int **)(iVar1 + 0x2c + iVar4 * 0x18);
  iVar4 = iVar1 + 0x24 + iVar4 * 0x18;
  iVar3 = *(int *)(iVar5 + 0x40 + param_3 * 4);
  if (iVar3 < 0) {
    return 0;
  }
LAB_6802eb2e:
  iVar4 = **(int **)(iVar4 + 4) + 0x20 + iVar3 * 0x18;
  iVar1 = *(int *)(iVar4 + 0xc);
  if ((-1 < iVar1) && (iVar1 < *(int *)(iVar5 + 0x14))) {
    bVar2 = props_executeHandler((int *)param_1,*(int **)(param_1 + 0xe8),
                         *(undefined4 *)(iVar5 + 0xa8 + iVar1 * 0x10),*(uint *)(iVar4 + 0x10),
                         &param_2);
    return CONCAT31(extraout_var,bVar2);
  }
  return 0;
}



// ============================================================
// Function: cast_invokeHandler (FUN_6802eb80)
// Address: 6802eb80
// Size: 281 bytes
// Params: uint param_1, int param_2, uint param_3, uint param_4, uint * param_5, undefined4 * param_6, undefined4 * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
cast_invokeHandler(uint param_1,int param_2,uint param_3,uint param_4,uint *param_5,undefined4 *param_6,
            undefined4 *param_7)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  int iVar7;
  undefined3 extraout_var;
  uint *puVar8;
  undefined4 local_8;
  
  uVar4 = param_1;
  local_8 = 0;
  *param_7 = 0;
  if (param_2 == 0) {
    return 0;
  }
  if (0 < (int)param_4) {
    puVar1 = (uint *)(param_1 + 0x1c);
    param_1 = param_4;
    puVar8 = param_5;
    do {
      props_pushValue(uVar4);
      *puVar1 = *puVar8;
      *(uint *)(uVar4 + 0x20) = puVar8[1];
      props_retainValue(uVar4,puVar1);
      puVar8 = puVar8 + 2;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  props_pushValue(uVar4);
  puVar5 = param_6;
  *(uint *)(uVar4 + 0x20) = param_4;
  if (param_6 != (undefined4 *)0x0) {
    *(uint *)(uVar4 + 0x20) = param_4 | 0x80000000;
  }
  iVar2 = *(int *)(uVar4 + 0x3c);
  uVar3 = *(undefined4 *)(uVar4 + 0x74);
  iVar7 = props_tryCallHandler(uVar4,param_2 + -1,param_3);
  if (iVar7 == 0) {
    if (-1 < (int)param_4) {
      iVar7 = param_4 + 1;
      do {
        props_popValue(uVar4);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else {
    local_8 = 1;
    if (*(int *)(uVar4 + 0x74) == 2) {
      bVar6 = props_executeHandler((int *)(size_t)uVar4,(int *)0x2,0,0,(int *)&param_5);
      local_8 = CONCAT31(extraout_var,bVar6);
      if (param_5 == (uint *)0x8) {
        *param_7 = *(undefined4 *)(uVar4 + 0x7c);
      }
    }
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = *(undefined4 *)(uVar4 + 0x1c);
      puVar5[1] = *(undefined4 *)(uVar4 + 0x20);
      *(int *)(uVar4 + 0x18) = *(int *)(uVar4 + 0x18) + -8;
      iVar7 = **(int **)(uVar4 + 0x10);
      *(undefined4 *)(uVar4 + 0x1c) = *(undefined4 *)(iVar7 + *(int *)(uVar4 + 0x18));
      *(undefined4 *)(uVar4 + 0x20) = *(undefined4 *)(iVar7 + 4 + *(int *)(uVar4 + 0x18));
    }
  }
  *(undefined4 *)(uVar4 + 0x74) = uVar3;
  props_selectScript(uVar4,iVar2);
  return local_8;
}



// ============================================================
// Function: cast_resolveHandlerByName (FUN_6802eca0)
// Address: 6802eca0
// Size: 241 bytes
// Params: int param_1, int param_2, byte * param_3, undefined4 * param_4, int * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveHandlerByName(int param_1,int param_2,byte *param_3,undefined4 *param_4,int *param_5,
                 undefined4 *param_6)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int local_474;
  uint local_470;
  int local_464 [279];
  uint local_8;
  
  if (param_2 != 0) {
    props_selectScript(param_1,param_2 + -1);
    props_parseIdentifier(local_464,param_3);
    props_setParserState(param_1,local_464,0);
    if (local_474 == 8) {
      uVar1 = props_resolveHandler(param_1,local_470,0);
      if (-1 < (int)uVar1) {
        iVar3 = *(int *)(**(int **)(param_1 + 0x28) + 0x2c + uVar1 * 0x18);
        *param_5 = *(int *)(**(int **)(param_1 + 0x28) + uVar1 * 0x18 + 0x30);
        if (-1 < iVar3) {
          piVar2 = (int *)props_getHandlerValue(param_1,iVar3);
          *param_4 = piVar2;
          if (piVar2 != (int *)0x0) {
            iVar3 = props_getContextSlot(param_1,piVar2,*param_5);
            *param_6 = *(undefined4 *)(iVar3 + 0x28);
            return 0;
          }
        }
      }
    }
  }
  return 0;
}



