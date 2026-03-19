// Module: core
// Topic: Property accessor implementations - get/set for various data types on scriptable objects
// Address range: 0x6801A8F0 - 0x6801B0D0
// Functions (17):
//   core_accessFloatProperty (0x6801A8F0)
//   core_getMemberValuePair (0x6801A940)
//   core_accessSpriteProperty (0x6801A9C0)
//   core_accessProperty (0x6801AAD0)
//   core_accessMemberType (0x6801ABC0)
//   core_accessMemberLoaded (0x6801AC30)
//   core_accessMemberName (0x6801AC80)
//   core_accessMemberData (0x6801AD20)
//   core_getMemberFieldCount (0x6801AD90)
//   core_accessMemberHandle (0x6801ADB0)
//   core_accessMemberPurgeable (0x6801AE20)
//   core_accessMemberStreaming (0x6801AE70)
//   core_accessMemberPreload (0x6801AEC0)
//   core_accessMemberUnload (0x6801AF10)
//   core_accessMemberColor (0x6801AF60)
//   core_dispatchMemberProperty (0x6801B020)
//   core_dispatchPropertyHandler (0x6801B0D0)

// ============================================================
// Function: core_accessFloatProperty (FUN_6801a8f0)
// Address: 6801a8f0
// Size: 71 bytes
// Params: uint param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessFloatProperty(uint param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar2 = param_2;
    uVar3 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberLoopData(unaff_ESI,uVar3,uVar2);
    unaff_EDI[1] = iVar1;
  }
  else {
    iVar1 = props_requireInt(unaff_ESI,unaff_EDI,(int *)&param_1);
    if (iVar1 != 0) {
      uVar4 = param_1;
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberLoopData(unaff_ESI,uVar2,uVar4);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_getMemberValuePair (FUN_6801a940)
// Address: 6801a940
// Size: 113 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getMemberValuePair(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = sprites_getMemberData(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = 0x25;
  }
  else {
    iVar1 = sprites_getMemberInfo(param_1,param_2);
    puVar2 = (undefined4 *)sprites_dispatchFontProperty(param_1,iVar1);
    if (puVar2 != (undefined4 *)0x0) {
      props_getValuePair(param_1,puVar2,param_3);
      return 0;
    }
    uVar3 = sprites_getMemberInfo(param_1,param_2);
    iVar1 = sprites_getMemberPurge(param_1,uVar3);
    if (iVar1 == 0) {
      iVar1 = 0x6f;
    }
    else {
      iVar1 = 3;
    }
  }
  props_setError(param_1,iVar1);
  *param_3 = 2;
  param_3[1] = 0;
  return 0;
}



// ============================================================
// Function: core_accessSpriteProperty (FUN_6801a9c0)
// Address: 6801a9c0
// Size: 264 bytes
// Params: undefined4 * param_1, uint param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessSpriteProperty(undefined4 *param_1,uint param_2,int param_3,int param_4,int param_5)
{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  uint *unaff_EBX;
  void *unaff_ESI;
  uint *puVar3;
  int iVar4;
  
  if (param_2 == 0) {
    puVar3 = &param_2;
    iVar1 = param_3;
    uVar2 = sprites_getMemberInfo((int)unaff_ESI,param_1);
    if (param_5 == 0) {
      sprites_getPropertyValue((int)unaff_ESI,uVar2,iVar1,puVar3);
    }
    else {
      sprites_dispatchPaletteProperty(unaff_ESI,uVar2,iVar1,(undefined1 *)puVar3);
    }
    if (in_EAX == 0x11) {
      if ((*(unsigned char *)((char *)&param_2 + 3)) != '\0') {
        events_manageCastMember((int)unaff_ESI,(undefined2 *)&param_2,0);
      }
      iVar1 = props_storeIntValue(unaff_ESI,param_2 & 0xff,unaff_EBX);
    }
    else {
      iVar1 = props_storeFloatValue((int)unaff_ESI,&param_2,unaff_EBX);
    }
    if (iVar1 != 0) {
      props_setErrorAndReturn((int)unaff_ESI,0x3d);
    }
    return 0;
  }
  if (in_EAX == 0x11) {
    iVar1 = props_coerceAndReturnBool((int)unaff_ESI,unaff_EBX,(undefined1 *)&param_2);
  }
  else {
    iVar1 = props_coerceAndStore((int)unaff_ESI,unaff_EBX,(int *)&param_2);
  }
  if (iVar1 == 0) {
    if (param_5 != 0) {
      puVar3 = &param_2;
      iVar1 = param_3;
      iVar4 = param_4;
      uVar2 = sprites_getMemberInfo((int)unaff_ESI,param_1);
      sprites_dispatchTransitionProperty((int)unaff_ESI,uVar2,(undefined2 *)puVar3,iVar1,iVar4);
      return 0;
    }
    puVar3 = &param_2;
    iVar1 = param_3;
    iVar4 = param_4;
    uVar2 = sprites_getMemberInfo((int)unaff_ESI,param_1);
    sprites_setPropertyValue((int)unaff_ESI,uVar2,puVar3,iVar1,iVar4);
    return 0;
  }
  props_setErrorAndReturn((int)unaff_ESI,(-(uint)(in_EAX != 0x11) & 0x62) + 7);
  return 0;
}



// ============================================================
// Function: core_accessProperty (FUN_6801aad0)
// Address: 6801aad0
// Size: 226 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_accessProperty(int *param_1,undefined4 *param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *unaff_EBX;
  int unaff_ESI;
  int local_3c;
  int local_38 [12];
  uint local_8;
  
  if (((param_3 != 10) && (param_3 != 0xc)) && (param_3 != 0x15)) {
    *unaff_EBX = 0;
    *param_1 = 0x7fff;
LAB_6801ab9c:
    return 0;
  }
  props_pushValue(unaff_ESI);
  iVar1 = stage_popChunkParams(unaff_ESI,(int)local_38);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
    iVar1 = **(int **)(unaff_ESI + 0x10);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0x18));
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x18));
    if (param_4 == 0) {
      puVar3 = (undefined4 *)0x0;
      iVar1 = sprites_getMemberInfo(unaff_ESI,param_2);
      puVar3 = (undefined4 *)sprites_dispatchCursorProperty(unaff_ESI,iVar1,puVar3);
    }
    else {
      uVar2 = sprites_getMemberInfo(unaff_ESI,param_2);
      puVar3 = (undefined4 *)sprites_setPropertyDirect(unaff_ESI,uVar2);
    }
    if (puVar3 != (undefined4 *)0x0) {
      *unaff_EBX = 0;
      local_3c = Ordinal_1116(puVar3);
      *param_1 = local_3c;
      score_registerAllHandlers(unaff_ESI,local_38,unaff_EBX,param_1,(byte *)*puVar3,&local_3c);
      goto LAB_6801ab9c;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberType (FUN_6801abc0)
// Address: 6801abc0
// Size: 98 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberType(int param_1)
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  uint *unaff_EDI;
  
  if (param_1 == 0) {
    uVar3 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    sVar1 = sprites_getMemberCenterCrop(unaff_ESI,uVar3);
    cast_convertTypeToString(unaff_ESI,sVar1,unaff_EDI);
    return 0;
  }
  iVar2 = cast_resolveIdentifierFlag(unaff_ESI,unaff_EDI,(ushort *)&param_1);
  if (iVar2 != 0) {
    uVar3 = props_translateError(iVar2);
    props_setErrorAndReturn(unaff_ESI,(int)(short)uVar3);
    return 0;
  }
  iVar2 = (int)(short)param_1;
  uVar3 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
  sprites_setMemberCenterCrop(unaff_ESI,uVar3,iVar2);
  return 0;
}



// ============================================================
// Function: core_accessMemberLoaded (FUN_6801ac30)
// Address: 6801ac30
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberLoaded(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (param_1 == 0) {
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberPurgeFlag(unaff_ESI,uVar2);
    unaff_EDI[1] = (uint)(iVar1 != 0);
  }
  else {
    iVar1 = props_requireInt(unaff_ESI,unaff_EDI,&param_1);
    if (iVar1 != 0) {
      uVar3 = (uint)(param_1 != 0);
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberPurge(unaff_ESI,uVar2,uVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberName (FUN_6801ac80)
// Address: 6801ac80
// Size: 158 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberName(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  byte *pbVar3;
  byte local_408 [1024];
  uint local_8;
  
  if (param_1 == 0) {
    pbVar3 = local_408;
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberNameById(unaff_ESI,uVar2,pbVar3);
    if (iVar1 != 0) {
      props_readPascalString(unaff_ESI,local_408,unaff_EDI);
      return 0;
    }
    unaff_EDI[1] = 0;
  }
  else {
    iVar1 = crt_getPlatformData(unaff_ESI,unaff_EDI,local_408);
    if (iVar1 != 0) {
      pbVar3 = local_408;
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberFrameIndex(unaff_ESI,uVar2,(int)pbVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberData (FUN_6801ad20)
// Address: 6801ad20
// Size: 109 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberData(undefined4 *param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *unaff_EBX;
  int unaff_ESI;
  undefined4 *puVar4;
  
  if (param_2 == 0) {
    core_getMemberValuePair(unaff_ESI,param_1,unaff_EBX);
  }
  else {
    iVar1 = props_validateString(unaff_ESI,unaff_EBX);
    if (iVar1 != 0) {
      iVar1 = sprites_getMemberData(unaff_ESI,param_1);
      if (iVar1 == 0) {
        props_setError(unaff_ESI,0x25);
      }
      else {
        puVar2 = props_detachString(unaff_ESI,unaff_EBX);
        puVar4 = puVar2;
        uVar3 = sprites_getMemberInfo(unaff_ESI,param_1);
        sprites_setMemberHilite(unaff_ESI,uVar3,(uint)puVar4);
        cast_freeHandle(puVar2);
      }
      if (*(int *)(unaff_ESI + 0x7c) == 0) {
        *unaff_EBX = 0;
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_getMemberFieldCount (FUN_6801ad90)
// Address: 6801ad90
// Size: 24 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getMemberFieldCount(void)
{
  undefined4 *in_EAX;
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = 8;
  uVar1 = sprites_getMemberInfo(unaff_EDI,in_EAX);
  uVar1 = sprites_dispatchExtPropertyByType(unaff_EDI,uVar1);
  unaff_ESI[1] = uVar1;
  return 0;
}



// ============================================================
// Function: core_accessMemberHandle (FUN_6801adb0)
// Address: 6801adb0
// Size: 109 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberHandle(uint param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  uint uVar3;
  int *piVar4;
  int local_8;
  
  if (param_1 == 0) {
    piVar4 = &local_8;
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    sprites_getMemberField(unaff_ESI,uVar2,piVar4);
    if (local_8 != 0) {
      stage_wrapHandle(unaff_ESI,local_8,unaff_EDI);
    }
    return 0;
  }
  iVar1 = stage_unwrapHandle(unaff_ESI,unaff_EDI,(int *)&param_1);
  if (iVar1 != 0) {
    uVar3 = param_1;
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    sprites_setMemberField(unaff_ESI,uVar2,uVar3);
    return 0;
  }
  props_setErrorAndReturn(unaff_ESI,0x12);
  return 0;
}



// ============================================================
// Function: core_accessMemberPurgeable (FUN_6801ae20)
// Address: 6801ae20
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberPurgeable(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (param_1 == 0) {
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberMoveable(unaff_ESI,uVar2);
    unaff_EDI[1] = (uint)(iVar1 != 0);
  }
  else {
    iVar1 = props_requireInt(unaff_ESI,unaff_EDI,&param_1);
    if (iVar1 != 0) {
      uVar3 = (uint)(param_1 != 0);
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberMoveable(unaff_ESI,uVar2,uVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberStreaming (FUN_6801ae70)
// Address: 6801ae70
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberStreaming(int param_1)
{
  int param_4;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (param_1 == 0) {
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberEditable(unaff_ESI,uVar2);
    unaff_EDI[1] = (uint)(iVar1 != 0);
  }
  else {
    iVar1 = props_requireInt(unaff_ESI,unaff_EDI,&param_1);
    if (iVar1 != 0) {
      uVar3 = (uint)(param_1 != 0);
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberEditable(unaff_ESI,uVar2,uVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberPreload (FUN_6801aec0)
// Address: 6801aec0
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberPreload(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (param_1 == 0) {
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberAutoTab(unaff_ESI,uVar2);
    unaff_EDI[1] = (uint)(iVar1 != 0);
  }
  else {
    iVar1 = props_requireInt(unaff_ESI,unaff_EDI,&param_1);
    if (iVar1 != 0) {
      uVar3 = (uint)(param_1 != 0);
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberAutoTab(unaff_ESI,uVar2,uVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberUnload (FUN_6801af10)
// Address: 6801af10
// Size: 78 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberUnload(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (param_1 == 0) {
    uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
    iVar1 = sprites_getMemberEditing(unaff_ESI,uVar2);
    unaff_EDI[1] = (uint)(iVar1 != 0);
  }
  else {
    iVar1 = props_requireInt(unaff_ESI,unaff_EDI,&param_1);
    if (iVar1 != 0) {
      uVar3 = (uint)(param_1 != 0);
      uVar2 = sprites_getMemberInfo(unaff_ESI,unaff_EBX);
      sprites_setMemberEditing(unaff_ESI,uVar2,uVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessMemberColor (FUN_6801af60)
// Address: 6801af60
// Size: 178 bytes
// Params: undefined4 * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMemberColor(undefined4 *param_1,uint param_2)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int unaff_ESI;
  uint *unaff_EDI;
  uint *puVar3;
  
  if (param_2 == 0) {
    puVar3 = &param_2;
    uVar2 = sprites_getMemberInfo(unaff_ESI,param_1);
    sprites_getMemberBlendValue(unaff_ESI,uVar2,puVar3);
    if (unaff_EBX == 0x12) {
      if ((*(unsigned char *)((char *)&param_2 + 3)) != '\0') {
        events_manageCastMember(unaff_ESI,(undefined2 *)&param_2,0);
      }
      iVar1 = props_storeIntValue(unaff_ESI,param_2 & 0xff,unaff_EDI);
    }
    else {
      iVar1 = props_storeFloatValue(unaff_ESI,&param_2,unaff_EDI);
    }
    if (iVar1 != 0) {
      props_setErrorAndReturn(unaff_ESI,0x3d);
    }
    return 0;
  }
  if (unaff_EBX == 0x12) {
    iVar1 = props_coerceAndReturnBool(unaff_ESI,unaff_EDI,(undefined1 *)&param_2);
  }
  else {
    iVar1 = props_coerceAndStore(unaff_ESI,unaff_EDI,(int *)&param_2);
  }
  if (iVar1 == 0) {
    puVar3 = &param_2;
    uVar2 = sprites_getMemberInfo(unaff_ESI,param_1);
    sprites_setMemberBlendValue(unaff_ESI,uVar2,puVar3);
    return 0;
  }
  props_setErrorAndReturn(unaff_ESI,7);
  return 0;
}



// ============================================================
// Function: core_dispatchMemberProperty (FUN_6801b020)
// Address: 6801b020
// Size: 120 bytes
// Params: undefined4 * param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchMemberProperty(undefined4 *param_1,int param_2,uint *param_3)
{
  undefined4 in_EAX;
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *unaff_ESI;
  
  switch(in_EAX) {
  case 3:
    puVar1 = (uint *)0x2f1;
    break;
  case 4:
    puVar1 = (uint *)0x2ef;
    break;
  case 5:
    puVar1 = (uint *)0x2b4;
    break;
  case 6:
    puVar1 = (uint *)0x2ee;
    break;
  case 7:
    puVar1 = (uint *)0x2f0;
    break;
  default:
    puVar1 = param_3;
    break;
  case 0x11:
    puVar1 = (uint *)0x168;
  }
  iVar2 = sprites_getMemberInfo((int)unaff_ESI,param_1);
  iVar2 = sprites_dispatchPropertyEx(unaff_ESI,iVar2,param_2,(uint)puVar1,param_3);
  if (iVar2 != 0) {
    uVar3 = props_translateError(iVar2);
    props_setError((int)unaff_ESI,(int)(short)uVar3);
  }
  return 0;
}



// ============================================================
// Function: core_dispatchPropertyHandler (FUN_6801b0d0)
// Address: 6801b0d0
// Size: 1608 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, int * param_4, int * param_5, int param_6, int param_7, uint param_8, uint * param_9
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
core_dispatchPropertyHandler(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,int *param_5,
            int param_6,int param_7,uint param_8,uint *param_9)
{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  uVar1 = cast_bridgeXtraCall(param_1,param_2,param_3,param_4);
  iVar2 = param_7;
  param_4 = (int *)CONCAT22((*(unsigned short *)((char *)&param_4 + 2)),uVar1);
  switch(param_6) {
  case 0xb:
  case 0xc:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_findMemberByScript,(short *)&param_4,0x23);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberData(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x25);
      return 0;
    }
    break;
  case 0xd:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x4f);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType1(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x50);
      return 0;
    }
    break;
  case 0xe:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x51);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType2(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x52);
      return 0;
    }
    break;
  case 0xf:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x53);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType6(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x54);
      return 0;
    }
    break;
  case 0x10:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x55);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType3(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x56);
      return 0;
    }
    break;
  case 0x11:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x57);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType7(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x58);
      return 0;
    }
    break;
  case 0x12:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x59);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType4(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x5a);
      return 0;
    }
    break;
  case 0x13:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x5b);
    if (iVar2 == 0) {
      return 0;
    }
    iVar4 = sprites_getMemberCastType5(param_3,&param_4);
    iVar2 = param_7;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_3,0x5c);
      return 0;
    }
    break;
  case 0x14:
  case 0x15:
    iVar2 = crt_executePlatformCmd(param_3,param_5,sprites_clearMemberRef,(short *)&param_4,0x23);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = sprites_dispatchBitmapColor(param_3,&param_4);
    if (iVar2 == 0) {
      props_setErrorAndReturn(param_3,0x5c);
      return 0;
    }
    local_10 = 1;
    iVar2 = param_7;
    break;
  default:
    if (param_7 == 10) {
      crt_executePlatformQuery(param_3,param_5,sprites_resetMember,(short *)&param_4);
      uVar3 = sprites_getPropertyId(param_3,param_4);
      param_9[1] = uVar3;
      return 0;
    }
    iVar4 = crt_executePlatformCmd(param_3,param_5,sprites_resetMember,(short *)&param_4,0x23);
    if (iVar4 == 0) {
      return 0;
    }
    if ((2 < iVar2) &&
       (((iVar2 < 8 || (iVar2 == 0x11)) && (iVar4 = sprites_getMemberData(param_3,&param_4), iVar4 == 0)))) {
      if (param_6 == 9) {
        core_dispatchMemberProperty(&param_4,param_8,param_9);
        return 0;
      }
      props_setErrorAndReturn(param_3,0x25);
      return 0;
    }
  }
  switch(iVar2) {
  case 1:
    core_accessMemberName(param_8);
    return 0;
  case 2:
    core_accessMemberData(&param_4,param_8);
    return 0;
  case 3:
    iVar2 = core_accessProperty(&local_c,&param_4,param_6,local_10);
    if (iVar2 != 0) {
      core_accessShortProperty(&param_4,param_8,local_c,local_10);
      return 0;
    }
    break;
  case 4:
    iVar2 = core_accessProperty(&local_c,&param_4,param_6,local_10);
    if (iVar2 != 0) {
      core_accessStringProperty(param_8,(int *)param_9,local_c,local_10);
      return 0;
    }
    break;
  case 5:
    iVar2 = core_accessProperty(&local_c,&param_4,param_6,local_10);
    if (iVar2 != 0) {
      core_accessFloatProperty(param_8,local_8);
      return 0;
    }
    break;
  case 6:
    core_accessMemberType(param_8);
    return 0;
  case 7:
    iVar2 = core_accessProperty(&local_c,&param_4,param_6,local_10);
    if (iVar2 != 0) {
      core_accessIntProperty(param_8,(int *)param_9,local_c,local_10);
      return 0;
    }
    break;
  case 8:
    core_accessMemberHandle(param_8);
    return 0;
  case 9:
    core_accessMemberLoaded(param_8);
    return 0;
  case 10:
    param_9[1] = (int)(*(unsigned short *)((char *)&param_4 + 2));
    return 0;
  case 0xb:
    uVar5 = sprites_getMemberInfo(param_3,&param_4);
    uVar3 = sprites_dispatchMemberOp(param_3,uVar5);
    param_9[1] = uVar3;
    return 0;
  case 0xc:
    core_accessMemberPurgeable(param_8);
    return 0;
  case 0xd:
    uVar5 = sprites_getMemberInfo(param_3,&param_4);
    uVar3 = sprites_getMemberLineHeight(param_3,uVar5);
    param_9[1] = uVar3;
    return 0;
  case 0xe:
    core_accessMemberPreload(param_8);
    return 0;
  case 0xf:
    core_accessMemberUnload(param_8);
    return 0;
  case 0x10:
    core_accessMemberStreaming(param_8);
    return 0;
  case 0x11:
    iVar2 = core_accessProperty(&local_c,&param_4,param_6,local_10);
    if (iVar2 != 0) {
      core_accessSpriteProperty(&param_4,param_8,local_8,local_c,local_10);
      return 0;
    }
    break;
  case 0x12:
    core_accessMemberColor(&param_4,param_8);
    return 0;
  case 0x13:
    core_getMemberFieldCount();
  }
  return 0;
}


