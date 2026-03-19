// Module: cast
// Topic: Context slot access and script property management
// Address range: 0x6802F390 - 0x6802FD50
// Functions (36):
//   cast_getSlotCount
//   cast_getPropertyCount
//   cast_getSlotTypeAndValue
//   cast_getSlotInfo
//   cast_checkSlotBounds
//   cast_findSlotByPosition
//   cast_isContextEmpty
//   cast_hasChildren
//   cast_dispatchContext
//   cast_setPropertyValue
//   cast_checkHandlerExists
//   cast_invokeHandlerDirect
//   cast_handlePropertyAccess
//   cast_handleGetProperty
//   cast_getHandlerString
//   cast_dispatchVtableCall
//   cast_initContextAccess
//   cast_findContextRange
//   cast_accessCharByte
//   cast_getMemberDataAlt
//   cast_getMemberRef
//   cast_getContextRef
//   cast_resetAndCountRects
//   cast_dispatchMemberUpdate
//   cast_resetAndSort
//   cast_resolveContext
//   cast_setContextEntry
//   cast_retainObject
//   cast_releaseObject
//   cast_getSymbolName
//   cast_lookupSymbolValue
//   cast_getPropertyPair
//   cast_getContextData
//   cast_updateProplist
//   cast_setPropertyFromProplist
//   cast_getMemberData

// ============================================================
// Function: cast_getSlotCount (FUN_6802f390)
// Address: 6802f390
// Size: 24 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_getSlotCount(undefined4 param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0;
  }
  return *(int *)(*param_2 + 0x1c) + 1;
}



// ============================================================
// Function: cast_getPropertyCount (FUN_6802f3b0)
// Address: 6802f3b0
// Size: 26 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getPropertyCount(undefined4 param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*param_2 + 0x80);
}



// ============================================================
// Function: cast_getSlotTypeAndValue (FUN_6802f3d0)
// Address: 6802f3d0
// Size: 58 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getSlotTypeAndValue(undefined4 param_1,int *param_2,int param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  int iVar1;
  
  if (((param_2 != (int *)0x0) && (-1 < param_3)) && (param_3 < *(int *)(*param_2 + 0x80))) {
    iVar1 = props_getContextSlot(param_1,param_2,param_3);
    *param_5 = *(undefined4 *)(iVar1 + 0x18);
    *param_4 = *(undefined4 *)(iVar1 + 0x20);
  }
  return 0;
}



// ============================================================
// Function: cast_getSlotInfo (FUN_6802f410)
// Address: 6802f410
// Size: 103 bytes
// Params: int param_1, int * param_2, int param_3, undefined2 * param_4, int * param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getSlotInfo(int param_1,int *param_2,int param_3,undefined2 *param_4,int *param_5,int *param_6
                 )
{
  int *piVar1;
  
  if (((param_2 != (int *)0x0) && (-1 < param_3)) && (param_3 < *(int *)(*param_2 + 0x80))) {
    piVar1 = (int *)props_getContextSlot(param_1,param_2,param_3);
    *param_5 = piVar1[10];
    *param_6 = piVar1[0xb];
    props_storeTableEntry(param_1,*(int *)(*param_2 + 0x20),*piVar1,(int)param_4);
    return 0;
  }
  *param_4 = 0;
  *param_5 = 0;
  return 0;
}



// ============================================================
// Function: cast_checkSlotBounds (FUN_6802f480)
// Address: 6802f480
// Size: 66 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4, short param_5, undefined2 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_checkSlotBounds(undefined4 param_1,int *param_2,int param_3,int param_4,short param_5,
                 undefined2 *param_6)
{
  int iVar1;
  
  iVar1 = props_getContextSlot(param_1,param_2,param_3);
  if ((param_2 != (int *)0x0) && (-1 < param_4)) {
    if (param_5 == 0) {
      if (param_4 < *(int *)(iVar1 + 0x20)) {
        return 0;
      }
    }
    else if (param_4 < *(int *)(iVar1 + 0x18)) {
      return 0;
    }
  }
  *param_6 = 0;
  return 0;
}



// ============================================================
// Function: cast_findSlotByPosition (FUN_6802f4d0)
// Address: 6802f4d0
// Size: 254 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_findSlotByPosition(int param_1,int *param_2,int param_3,undefined4 param_4,int *param_5)
{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int local_820;
  int *local_81c;
  int local_818;
  undefined4 local_814;
  int local_810;
  int local_80c;
  undefined1 local_808 [1024];
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_814 = param_4;
  local_81c = param_5;
  iVar3 = 0;
  local_818 = param_1;
  cast_getSlotInfo(param_1,param_2,0,(undefined2 *)&local_408,&local_820,&local_80c);
  iVar1 = local_80c;
  while (iVar1 <= param_3) {
    local_80c = iVar1;
    if (local_408 == 0xff) {
      uVar2 = Ordinal_1201(local_407);
    }
    else {
      uVar2 = (ushort)local_408;
    }
    if (uVar2 == 0) break;
    Ordinal_1230(local_808,&local_408);
    iVar3 = iVar3 + 1;
    local_810 = iVar1;
    cast_getSlotInfo(local_818,param_2,iVar3,(undefined2 *)&local_408,&local_820,&local_80c);
    iVar1 = local_80c;
  }
  *local_81c = param_3 - local_810;
  Ordinal_1230(local_814,local_808);
  return 0;
}



// ============================================================
// Function: cast_isContextEmpty (FUN_6802f5d0)
// Address: 6802f5d0
// Size: 45 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_isContextEmpty(undefined4 param_1,int *param_2)

{
  if ((param_2 != (int *)0x0) &&
     ((0 < *(int *)(*param_2 + 0x80) || ((*(uint *)(*param_2 + 0x54) & 0x100) != 0)))) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: cast_hasChildren (FUN_6802f600)
// Address: 6802f600
// Size: 31 bytes
// Params: undefined4 param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_hasChildren(undefined4 param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return false;
  }
  return 0 < *(int *)(*param_2 + 0x70);
}



// ============================================================
// Function: cast_dispatchContext (FUN_6802f620)
// Address: 6802f620
// Size: 9 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchContext(int param_1,int *param_2)
{
  stage_initObjectAndRetain(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_setPropertyValue (FUN_6802f630)
// Address: 6802f630
// Size: 150 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setPropertyValue(undefined4 param_1,int *param_2,uint param_3,uint *param_4)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint local_c;
  int *local_8;
  
  iVar3 = stage_isDataNode(param_1,param_2);
  if (iVar3 == 0) {
    (**(code **)(*(int *)*param_2 + 0x18))(param_1,param_2,2,param_3,param_4);
    return 0;
  }
  local_c = *param_4;
  local_8 = (int *)param_4[1];
  props_retainValue(param_1,&local_c);
  puVar4 = score_lookupProperty(param_2,param_3,1,(uint *)0x0);
  if (puVar4 != (uint *)0x0) {
    piVar1 = (int *)puVar4[1];
    uVar2 = *puVar4;
    *puVar4 = local_c;
    puVar4[1] = (uint)local_8;
    props_releaseValue(param_1,(byte)uVar2,piVar1);
    return 0;
  }
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: cast_checkHandlerExists (FUN_6802f6d0)
// Address: 6802f6d0
// Size: 78 bytes
// Params: int * param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_checkHandlerExists(int *param_1,undefined4 *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint local_c;
  undefined4 *local_8;
  
  local_8 = param_2;
  local_c = 3;
  bVar1 = cast_executeHandler(param_1,param_2,*(undefined4 *)(&DAT_6818d1f0 + param_3 * 4),1,&local_c,
                       (int *)0x0,(int *)&param_2);
  if ((CONCAT31(extraout_var,bVar1) == 0) && (param_2 == (undefined4 *)0x0)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: cast_invokeHandlerDirect (FUN_6802f720)
// Address: 6802f720
// Size: 100 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, int * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_invokeHandlerDirect(int *param_1,undefined4 *param_2,int param_3,int *param_4,int *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  
  **(undefined4 **)(param_3 + 0x18) = 3;
  *(undefined4 **)(*(int *)(param_3 + 0x18) + 4) = param_2;
  bVar1 = cast_executeHandler(param_1,param_2,*(undefined4 *)(param_3 + 8),*(uint *)(param_3 + 0x14),
                       *(uint **)(param_3 + 0x18),param_4,param_5);
  **(undefined4 **)(param_3 + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_3 + 0x18) + 4) = 0;
  if ((CONCAT31(extraout_var,bVar1) == 0) && (*param_5 == 0)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: cast_handlePropertyAccess (FUN_6802f790)
// Address: 6802f790
// Size: 130 bytes
// Params: int * param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_handlePropertyAccess(int *param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined3 extraout_var;
  uint local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int iVar4;
  
  piVar1 = param_1;
  props_clearValue(param_1,&local_c);
  piVar2 = param_3;
  local_14 = *param_3;
  local_10 = param_3[1];
  local_1c = 3;
  local_18 = param_2;
  bVar3 = cast_executeHandler(piVar1,param_2,0x107,2,&local_1c,&local_c,(int *)&param_1);
  iVar4 = CONCAT31(extraout_var,bVar3);
  if ((iVar4 != 0) && (param_1 == (int *)0x0)) {
    piVar2[1] = local_8;
    *piVar2 = local_c;
    return iVar4;
  }
  props_releaseAndClear(piVar1,&local_c);
  return iVar4;
}



// ============================================================
// Function: cast_handleGetProperty (FUN_6802f820)
// Address: 6802f820
// Size: 72 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 cast_handleGetProperty(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint local_14;
  undefined4 *local_10;
  undefined8 local_c;
  
  piVar1 = param_1;
  props_clearValue(param_1,(undefined4 *)&local_c);
  local_14 = 3;
  local_10 = param_2;
  cast_executeHandler(piVar1,param_2,0x108,1,&local_14,(int *)&local_c,(int *)&param_1);
  return local_c;
}



// ============================================================
// Function: cast_getHandlerString (FUN_6802f870)
// Address: 6802f870
// Size: 132 bytes
// Params: int * param_1, undefined4 * param_2, int param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * cast_getHandlerString(int *param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  uint local_14;
  undefined4 *local_10;
  int local_c [2];
  
  piVar1 = param_1;
  props_clearValue(param_1,local_c);
  local_14 = 3;
  local_10 = param_2;
  bVar2 = cast_executeHandler(piVar1,param_2,0x10a - (uint)(param_3 != 0),1,&local_14,local_c,
                       (int *)&param_1);
  if ((CONCAT31(extraout_var,bVar2) != 0) && (param_1 == (int *)0x0)) {
    iVar3 = props_validateString((int)piVar1,local_c);
    if (iVar3 != 0) {
      puVar4 = props_detachString((int)piVar1,local_c);
      return puVar4;
    }
    props_releaseAndClear(piVar1,local_c);
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: cast_dispatchVtableCall (FUN_6802f900)
// Address: 6802f900
// Size: 36 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchVtableCall(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  (**(code **)(*(int *)*param_2 + 0x18))(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_initContextAccess (FUN_6802f930)
// Address: 6802f930
// Size: 249 bytes
// Params: void * this, undefined4 * param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_initContextAccess(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_8;
  
  *param_1 = 0;
  iVar1 = *in_EAX;
  iVar4 = *(int *)(iVar1 + 0x80);
  if (iVar4 == 0) {
    *param_1 = 1;
    return -1;
  }
  iVar7 = *(int *)(iVar1 + 0x84) + 0x3c + iVar1;
  iVar5 = 1;
  local_8 = 1;
  if (1 < iVar4) {
    do {
      local_8 = iVar5;
      if ((int)this < *(int *)(iVar7 + 0x2c) + -1) break;
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 0x3c;
      local_8 = iVar5;
    } while (iVar5 < iVar4);
  }
  iVar4 = *(int *)(iVar7 + -0x30);
  iVar2 = *(int *)(iVar7 + -0xc);
  pbVar3 = (byte *)(*(int *)(iVar7 + -8) + iVar1);
  for (iVar5 = (int)this - *(int *)(iVar7 + -0x10); 0 < iVar5; iVar5 = iVar5 + -1) {
    if (iVar2 < 1) goto LAB_6802f9d9;
    uVar8 = (uint)*pbVar3;
    pbVar6 = pbVar3 + 1;
    iVar9 = iVar2 + -1;
    if ((char)*pbVar3 < '\0') {
      uVar8 = (uVar8 & 0xffffff7f) << 8 | (uint)*pbVar6;
      pbVar6 = pbVar3 + 2;
      iVar9 = iVar2 + -2;
    }
    iVar4 = iVar4 + uVar8;
    iVar2 = iVar9;
    pbVar3 = pbVar6;
  }
  if (iVar2 < 1) {
LAB_6802f9d9:
    *param_1 = 1;
    if (0 < iVar5) {
      iVar4 = -1;
    }
  }
  if (*(int *)(iVar7 + -0x30) + *(int *)(iVar7 + -0x34) <= iVar4) {
    *param_1 = 1;
    iVar4 = *(int *)(iVar7 + -0x30) + -1 + *(int *)(iVar7 + -0x34);
  }
  if ((0 < iVar5) && (*param_1 = 1, local_8 == *(int *)(iVar1 + 0x80))) {
    iVar4 = -1;
  }
  return iVar4;
}



// ============================================================
// Function: cast_findContextRange (FUN_6802fa30)
// Address: 6802fa30
// Size: 110 bytes
// Params: undefined4 param_1, undefined4 param_2, void * param_3
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * cast_findContextRange(undefined4 param_1,undefined4 param_2,void *param_3)

{
  void *this;
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  pvVar4 = param_3;
  iVar2 = cast_initContextAccess(param_3,&param_3);
  if (param_3 != (void *)0x0) {
    return (void *)0xffffffff;
  }
  this = (void *)((int)pvVar4 + 1);
  iVar3 = cast_initContextAccess(this,&param_3);
  while( true ) {
    pvVar1 = this;
    if (param_3 != (void *)0x0) {
      if (iVar3 == -1) {
        pvVar4 = (void *)0xffffffff;
      }
      return pvVar4;
    }
    if (iVar2 < iVar3) break;
    this = (void *)((int)pvVar1 + 1);
    iVar3 = cast_initContextAccess(this,&param_3);
    pvVar4 = pvVar1;
  }
  return pvVar4;
}



// ============================================================
// Function: cast_accessCharByte (FUN_6802faa0)
// Address: 6802faa0
// Size: 85 bytes
// Params: undefined4 param_1, int * param_2, int param_3, void * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_accessCharByte(undefined4 param_1,int *param_2,int param_3,void *param_4,uint *param_5)
{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = cast_initContextAccess(param_4,&param_4);
  if (iVar1 < 0) {
    if (param_3 != 0) {
      *param_5 = 0xffffffff;
      return 0;
    }
  }
  else {
    pbVar2 = (byte *)(*param_2 + iVar1);
    if (param_3 != 0) {
      *param_5 = (uint)*pbVar2;
      *pbVar2 = 0x20;
      return 0;
    }
    if (-1 < (int)*param_5) {
      *pbVar2 = (byte)*param_5;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_getMemberDataAlt (FUN_6802fb00)
// Address: 6802fb00
// Size: 102 bytes
// Params: int param_1, int * param_2, int param_3, undefined1 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMemberDataAlt(int param_1,int *param_2,int param_3,undefined1 *param_4)
{
  uint local_c;
  int *local_8;
  
  props_getListEntry(param_1,param_2,param_3 + -1,&local_c);
  props_getStringLength(param_1,(int *)&local_c);
  if ((local_c == 0x40) || (local_c == 0x43)) {
    props_toPascalString((int *)&local_c,param_4);
  }
  else {
    Ordinal_1230(param_4,&DAT_6817c2f4);
  }
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: cast_getMemberRef (FUN_6802fb70)
// Address: 6802fb70
// Size: 44 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMemberRef(int param_1,int *param_2,int param_3,undefined4 *param_4)
{
  undefined4 local_c;
  undefined4 local_8;
  
  props_getListEntryAsInt(param_1,param_2,param_3 + -1,&local_c,0);
  *param_4 = local_8;
  return 0;
}



// ============================================================
// Function: cast_getContextRef (FUN_6802fba0)
// Address: 6802fba0
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getContextRef(int param_1)
{
  *(undefined4 *)(param_1 + 0x7c) = 0;
  props_getRectCount(param_1);
  return 0;
}



// ============================================================
// Function: cast_resetAndCountRects (FUN_6802fbc0)
// Address: 6802fbc0
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resetAndCountRects(int param_1)
{
  *(undefined4 *)(param_1 + 0x7c) = 0;
  props_assignRectVtable(param_1);
  return 0;
}



// ============================================================
// Function: cast_dispatchMemberUpdate (FUN_6802fbe0)
// Address: 6802fbe0
// Size: 9 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchMemberUpdate(undefined4 param_1,undefined4 *param_2)
{
  props_setListVtable(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_resetAndSort (FUN_6802fbf0)
// Address: 6802fbf0
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resetAndSort(int param_1)
{
  *(undefined4 *)(param_1 + 0x7c) = 0;
  props_assignPointVtable(param_1);
  return 0;
}



// ============================================================
// Function: cast_resolveContext (FUN_6802fc10)
// Address: 6802fc10
// Size: 67 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * cast_resolveContext(undefined4 param_1,int *param_2,int param_3)

{
  uint local_c;
  int *local_8;
  
  props_getListEntry(param_1,param_2,param_3 + -1,&local_c);
  if (local_c == 3) {
    return local_8;
  }
  props_releaseValue(param_1,(byte)local_c,local_8);
  return (int *)0x0;
}



// ============================================================
// Function: cast_setContextEntry (FUN_6802fc60)
// Address: 6802fc60
// Size: 42 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setContextEntry(int param_1,int *param_2,undefined4 param_3)
{
  uint local_c;
  undefined4 local_8;
  
  local_8 = param_3;
  local_c = 3;
  props_setListEntry(param_1,param_2,&local_c);
  return 0;
}



// ============================================================
// Function: cast_retainObject (FUN_6802fc90)
// Address: 6802fc90
// Size: 19 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_retainObject(undefined4 param_1,int *param_2)
{
  if (param_2 != (int *)0x0) {
    *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  }
  return 0;
}



// ============================================================
// Function: cast_releaseObject (FUN_6802fcb0)
// Address: 6802fcb0
// Size: 9 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_releaseObject(undefined4 param_1,int *param_2)
{
  props_releaseObject(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_getSymbolName (FUN_6802fcc0)
// Address: 6802fcc0
// Size: 26 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getSymbolName(int param_1,int param_2,int param_3)

{
  props_getSymbolString(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: cast_lookupSymbolValue (FUN_6802fce0)
// Address: 6802fce0
// Size: 9 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_lookupSymbolValue(undefined4 param_1,undefined4 param_2,int param_3)
{
  props_lookupSymbol(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: cast_getPropertyPair (FUN_6802fcf0)
// Address: 6802fcf0
// Size: 9 bytes
// Params: undefined4 param_1, uint param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getPropertyPair(undefined4 param_1,uint param_2,uint param_3,uint *param_4,int *param_5)
{
  score_getPropertyPair(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_getContextData (FUN_6802fd00)
// Address: 6802fd00
// Size: 33 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getContextData(undefined4 param_1,int *param_2,int param_3,uint *param_4,uint *param_5)
{
  score_setProplistValue(param_1,param_2,param_3 + -1,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_updateProplist (FUN_6802fd30)
// Address: 6802fd30
// Size: 9 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_updateProplist(int param_1,int *param_2,undefined4 *param_3,uint *param_4)
{
  score_updateProplist(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: cast_setPropertyFromProplist (FUN_6802fd40)
// Address: 6802fd40
// Size: 9 bytes
// Params: undefined4 param_1, undefined4 param_2, uint * param_3, void * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setPropertyFromProplist(undefined4 param_1,undefined4 param_2,uint *param_3,void *param_4,int param_5)
{
  score_setPropertyValue(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_getMemberData (FUN_6802fd50)
// Address: 6802fd50
// Size: 9 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMemberData(undefined4 param_1,int *param_2)
{
  props_getListLength(param_1,param_2);
  return 0;
}



