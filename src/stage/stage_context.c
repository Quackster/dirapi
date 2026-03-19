// Module: stage
// Topic: Context and scope management
// Address range: 0x68057660 - 0x68057CA0
// Functions (12):
//   stage_getScopeEntry (FUN_68057660)
//   stage_getScopeInfo (FUN_680576F0)
//   stage_resolveContextVar (stage_resolveContextVar)
//   stage_resolveContextSlot (FUN_680577F0)
//   stage_getContextValue (FUN_680578E0)
//   stage_collectContextRefs (FUN_680579A0)
//   stage_checkContextVar (FUN_68057A20)
//   stage_markContextDirty (FUN_68057AB0)
//   stage_formatContextError (FUN_68057AE0)
//   stage_accessProperty (FUN_68057B60)
//   stage_invalidateContext (FUN_68057C70)
//   stage_destroyContextData (FUN_68057CA0)

// ============================================================
// Function: stage_getScopeEntry (FUN_68057660)
// Address: 68057660
// Size: 134 bytes
// Params: int param_1, int param_2, undefined2 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getScopeEntry(int param_1,int param_2,undefined2 *param_3,int *param_4)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int aiStack_78 [8];
  undefined4 uStack_58;
  int local_38 [4];
  int *local_28;
  int local_24;
  int local_20;
  
  piVar1 = stage_getScopeAtIndex(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    piVar3 = local_38;
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar3 = *piVar1;
      piVar1 = piVar1 + 1;
      piVar3 = piVar3 + 1;
    }
    if (local_28 == (int *)0x0) {
      *param_3 = 0;
      *param_4 = 0;
      return 0;
    }
    piVar1 = (int *)props_getContextSlot(param_1,local_28,local_24);
    uStack_58 = 0x680576c3;
    props_storeTableEntry(param_1,local_20,*piVar1,(int)param_3);
    piVar1 = local_38;
    piVar3 = aiStack_78;
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar3 = *piVar1;
      piVar1 = piVar1 + 1;
      piVar3 = piVar3 + 1;
    }
    iVar2 = stage_computeSlotCount(param_1);
    *param_4 = iVar2;
  }
  return 0;
}



// ============================================================
// Function: stage_getScopeInfo (FUN_680576F0)
// Address: 680576f0
// Size: 134 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getScopeInfo(int param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = stage_getScopeAtIndex(param_1,param_2);
  piVar1 = param_3;
  if ((piVar2 == (int *)0x0) || (piVar2[4] == 0)) {
    *param_3 = 0;
    *param_4 = -1;
    *param_5 = 0xffffffff;
  }
  else {
    *param_3 = piVar2[4];
    iVar3 = stage_resolveLineOffset(param_1,1,(int)piVar2);
    *param_4 = iVar3;
    crt_executePlatformOp(param_1,(int *)*piVar1,(short)piVar2[5],iVar3,(int *)&param_4,&param_3,param_5,
                 (undefined1 *)0x0);
    if (param_3 != (int *)0x0) {
      cast_freeHandle(param_4);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_resolveContextVar (FUN_68057780)
// Address: 68057780
// Size: 110 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * stage_resolveContextVar(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = props_getTableEntry(unaff_EDI,*(int *)(unaff_ESI + 0x18),
                       *(int *)(**(int **)(unaff_ESI + 0x10) + unaff_EBX * 4 + param_2));
  *param_3 = uVar1;
  if (param_1 == 2) {
    puVar2 = score_lookupProperty(*(int **)(**(int **)(unaff_EDI + 8) + 0x4e4),uVar1,1,(uint *)0x0);
    return puVar2;
  }
  if (param_1 != 4) {
    if (param_1 != 5) {
      return (uint *)0x0;
    }
    return (uint *)(**(int **)(unaff_EDI + 0x10) + *(int *)(unaff_ESI + 8) + unaff_EBX * 8);
  }
  return (uint *)(**(int **)(unaff_EDI + 0x10) + *(int *)(unaff_ESI + 4) + unaff_EBX * 8);
}



// ============================================================
// Function: stage_resolveContextSlot (FUN_680577F0)
// Address: 680577f0
// Size: 235 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4, uint * param_5
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * stage_resolveContextSlot(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = props_getContextSlot(param_1,*(int **)(param_2 + 0x10),*(int *)(param_2 + 0x14));
  *param_4 = 4;
  if (param_3 < *(int *)(iVar1 + 0x10)) {
    puVar2 = stage_resolveContextVar(4,*(int *)(iVar1 + 0x14),param_5);
    return puVar2;
  }
  iVar4 = param_3 - *(int *)(iVar1 + 0x10);
  *param_4 = 5;
  if (iVar4 < *(int *)(iVar1 + 0x18)) {
    puVar2 = stage_resolveContextVar(5,*(int *)(iVar1 + 0x1c),param_5);
    return puVar2;
  }
  iVar4 = iVar4 - *(int *)(iVar1 + 0x18);
  *param_4 = 2;
  if (iVar4 < *(int *)(iVar1 + 0x20)) {
    puVar2 = stage_resolveContextVar(2,*(int *)(iVar1 + 0x24),param_5);
    return puVar2;
  }
  iVar4 = iVar4 - *(int *)(iVar1 + 0x20);
  if (iVar4 < *(int *)(**(int **)(param_2 + 0x10) + 0x78)) {
    puVar2 = stage_resolveContextVar(2,*(int *)(**(int **)(param_2 + 0x10) + 0x7c),param_5);
    return puVar2;
  }
  iVar1 = *(int *)(**(int **)(param_2 + 0x10) + 0x78);
  *param_4 = 3;
  iVar3 = stage_hasClosureScope();
  if ((iVar3 != 0) && (*(int **)(param_2 + 0x20) != (int *)0x0)) {
    puVar2 = (uint *)score_getValueByIndex(*(int **)(param_2 + 0x20),iVar4 - iVar1,(int *)param_5);
    return puVar2;
  }
  return (uint *)0x0;
}



// ============================================================
// Function: stage_getContextValue (FUN_680578E0)
// Address: 680578e0
// Size: 189 bytes
// Params: undefined * param_1, int param_2, int param_3, undefined1 * param_4, undefined2 * param_5, undefined4 * param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getContextValue(undefined *param_1,int param_2,int param_3,undefined1 *param_4,undefined2 *param_5
                 ,undefined4 *param_6,int *param_7)
{
  undefined *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int local_40 [13];
  uint local_c;
  uint local_8;
  
  puVar1 = param_1;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  *param_4 = 0;
  *(undefined1 *)param_5 = 0;
  piVar3 = stage_getScopeAtIndex((int)param_1,param_2);
  if (piVar3 != (int *)0x0) {
    piVar7 = local_40;
    for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar7 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar7 = piVar7 + 1;
    }
    puVar4 = stage_resolveContextSlot(puVar1,(int)local_40,param_3,&param_2,(uint *)&param_1);
    puVar2 = param_6;
    if (puVar4 != (uint *)0x0) {
      local_c = *puVar4;
      local_8 = puVar4[1];
      if (param_6 == (undefined4 *)0x0) {
        props_setupCallback(puVar1,(int *)&local_c,param_5);
      }
      else {
        puVar5 = (undefined4 *)props_serializeValue((int)puVar1,(int *)&local_c,0);
        *puVar2 = puVar5;
        props_cStringToPascal(puVar5,(undefined1 *)param_5);
      }
      if (param_7 != (int *)0x0) {
        *param_7 = param_2;
      }
      score_lookupSymbol(DAT_68196304,(int)param_1,(int)param_4);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_collectContextRefs (FUN_680579A0)
// Address: 680579a0
// Size: 126 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_collectContextRefs(int *param_1)
{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  int iVar3;
  uint local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  piVar1 = (int *)props_getRectCount(unaff_ESI);
  if (piVar1 != (int *)0x0) {
    local_8 = *(int *)(*param_1 + 0x20);
    local_c = *(int *)(*param_1 + 0x80);
    if (0 < local_c) {
      iVar3 = 0;
      do {
        piVar2 = (int *)props_getContextSlot(unaff_ESI,param_1,iVar3);
        if (-1 < *piVar2) {
          local_10 = props_getTableEntry(unaff_ESI,local_8,*piVar2);
          local_14 = 8;
          props_setListEntry(unaff_ESI,piVar1,&local_14);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_c);
    }
    stage_emitPopVar(piVar1);
    props_normalizeType(unaff_ESI,3,(int)piVar1);
  }
  return 0;
}



// ============================================================
// Function: stage_checkContextVar (FUN_68057A20)
// Address: 68057a20
// Size: 141 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stage_checkContextVar(int *param_1)
{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 == 2) {
    _DAT_68197764 =
         (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                *(int *)(unaff_ESI + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    iVar1 = props_requireSymbolId(unaff_ESI,&local_10,(int *)&local_8);
    if (iVar1 != 0) {
      uVar2 = props_lookupVariable(unaff_ESI,param_1,local_8);
      props_normalizeType(unaff_ESI,4,(uint)(-1 < (int)uVar2));
    }
  }
  return 0;
}



// ============================================================
// Function: stage_markContextDirty (FUN_68057AB0)
// Address: 68057ab0
// Size: 35 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_markContextDirty(uint param_1,int *param_2)
{
  if (-1 < *(int *)(*param_2 + 4)) {
    *(undefined4 *)(*param_2 + 4) = 1;
  }
  props_releaseContext(param_1,param_2);
  return 0;
}



// ============================================================
// Function: stage_formatContextError (FUN_68057AE0)
// Address: 68057ae0
// Size: 116 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatContextError(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  undefined2 local_408 [512];
  uint local_8;
  
  events_getWindowStyle(param_1,*(int *)(*param_2 + 0x20) + 1,param_2,(undefined2 *)0x0,(undefined2 *)0x0,
               local_408);
  cast_loadPascalString(&DAT_68197780,0x898,0x29);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: stage_accessProperty (FUN_68057B60)
// Address: 68057b60
// Size: 255 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_accessProperty(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *in_EAX;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  uint *unaff_ESI;
  
  if ((unaff_EBX != 0) && (param_2 == 0xfd)) {
    sprites_resetChannel();
  }
  puVar2 = score_lookupProperty(in_EAX,param_2,0,(uint *)0x0);
  if (puVar2 != (uint *)0x0) {
    uVar4 = *puVar2;
    if (unaff_EBX == 0) {
      *unaff_ESI = uVar4;
      unaff_ESI[1] = puVar2[1];
      props_retainValue(param_1,unaff_ESI);
      return 1;
    }
    piVar1 = (int *)puVar2[1];
    *puVar2 = *unaff_ESI;
    puVar2[1] = unaff_ESI[1];
    *unaff_ESI = 0;
    props_releaseValue(param_1,(byte)uVar4,piVar1);
    return 1;
  }
  puVar2 = score_lookupProperty(in_EAX,0xfd,0,(uint *)0x0);
  if (((puVar2 != (uint *)0x0) && (*puVar2 == 3)) &&
     (iVar3 = (**(code **)(**(int **)puVar2[1] + 0x18))(param_1,(undefined4 *)puVar2[1]), iVar3 != 0
     )) {
    return 1;
  }
  if (unaff_EBX == 0) {
    if (param_2 == 0x7b) {
      *unaff_ESI = 3;
      unaff_ESI[1] = *(uint *)(*in_EAX + 0x10);
      piVar1 = (int *)(**(int **)(*in_EAX + 0x10) + 4);
      *piVar1 = *piVar1 + 1;
      return 1;
    }
    if (param_2 == 0xdd) {
      *unaff_ESI = 4;
      uVar4 = score_clearPropertyTable(in_EAX);
      unaff_ESI[1] = uVar4;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_invalidateContext (FUN_68057C70)
// Address: 68057c70
// Size: 42 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_invalidateContext(undefined4 param_1,int *param_2)
{
  undefined4 *puVar1;
  
  *(uint *)(*param_2 + 4) = *(uint *)(*param_2 + 4) | 0x80000000;
  puVar1 = *(undefined4 **)(*param_2 + 0x34);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)(*(int *)*puVar1 + 0x34))(param_1,puVar1);
  }
  return 0;
}



// ============================================================
// Function: stage_destroyContextData (FUN_68057CA0)
// Address: 68057ca0
// Size: 62 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_destroyContextData(uint param_1,int *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*param_2 + 0x34);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
  }
  props_releaseLocals(param_1,param_2);
  score_freePropertyHandle(*(undefined4 *)(*param_2 + 0x30));
  props_unregisterContext(param_1,param_2);
  return 0;
}



