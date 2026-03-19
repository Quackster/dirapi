// Module: stage
// Topic: Object/proplist dispatch and management
// Address range: 0x680585A0 - 0x68058D50
// Functions (10):
//   stage_allocObject (FUN_680585A0)
//   stage_buildObjectProps (FUN_680585E0)
//   stage_getObjectRef (stage_getObjectRef)
//   stage_getObjectPropValue (FUN_68058670)
//   stage_setObjectPropValue (FUN_68058790)
//   stage_getObjectPropCount (FUN_68058980)
//   stage_getObjectProperty (FUN_680589F0)
//   stage_dispatchObjectProp (FUN_68058C30)
//   stage_resolveObjectProp (FUN_68058C50)
//   stage_processObjectProp (FUN_68058D50)

// ============================================================
// Function: stage_allocObject (FUN_680585A0)
// Address: 680585a0
// Size: 52 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_allocObject(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)stage_createBytecodeBlock(0x9c,0x98,0x400);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  stage_registerContextNode(param_1,piVar1);
  return piVar1;
}



// ============================================================
// Function: stage_buildObjectProps (FUN_680585E0)
// Address: 680585e0
// Size: 127 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_buildObjectProps(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *unaff_EBX;
  int iVar5;
  int local_8;
  
  iVar1 = *unaff_EBX;
  iVar2 = *(int *)(iVar1 + 0x20);
  iVar5 = *(int *)(iVar1 + 0x74);
  local_8 = *(int *)(iVar1 + 0x70);
  piVar3 = (int *)score_initTableCapacity(local_8);
  if (piVar3 != (int *)0x0) {
    if (0 < local_8) {
      do {
        uVar4 = props_getTableEntry(param_1,iVar2,*(int *)(*unaff_EBX + iVar5));
        score_lookupProperty(piVar3,uVar4,1,(uint *)0x0);
        iVar5 = iVar5 + 4;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
    stage_initDataNode(param_1,piVar3,(int)unaff_EBX);
    return piVar3;
  }
  props_setError(param_1,2);
  return (int *)0x0;
}



// ============================================================
// Function: stage_getObjectRef (FUN_68058660)
// Address: 68058660
// Size: 16 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_getObjectRef(int *param_1)
{
  int in_EAX;
  int *piVar1;
  
  piVar1 = stage_buildObjectProps(in_EAX);
  *(int **)(*param_1 + 0x34) = piVar1;
  return 0;
}



// ============================================================
// Function: stage_getObjectPropValue (FUN_68058670)
// Address: 68058670
// Size: 281 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall stage_getObjectPropValue(int *param_1)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int unaff_ESI;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if (((in_EAX != (int *)0x0) || (in_EAX = (int *)stage_getObjectRef(param_1), in_EAX != (int *)0x0)) &&
     (iVar1 = props_getInt(unaff_ESI), iVar1 == 2)) {
    _DAT_68197764 =
         (uint *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                 *(int *)(unaff_ESI + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_10 = ((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    iVar1 = props_coerceToInt(unaff_ESI,(int *)&local_14,&local_8);
    if (iVar1 == 0) {
      iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_c);
      if (iVar1 != 0) {
        puVar3 = score_lookupProperty(in_EAX,local_c,0,(uint *)0x0);
        if (puVar3 == (uint *)0x0) {
          props_normalizeType(unaff_ESI,2,0);
          return 1;
        }
        local_14 = *puVar3;
        local_10 = puVar3[1];
        goto LAB_68058754;
      }
    }
    else {
      piVar2 = score_findEntryByIndex(in_EAX,local_8 + -1,(int *)0x0);
      if (piVar2 != (int *)0x0) {
        local_14 = piVar2[2];
        local_10 = piVar2[3];
LAB_68058754:
        props_retainValue(unaff_ESI,&local_14);
        props_popArgs(unaff_ESI,&local_14);
        return 1;
      }
      props_reportError(unaff_ESI,0x3c);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_setObjectPropValue (FUN_68058790)
// Address: 68058790
// Size: 492 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall stage_setObjectPropValue(int *param_1)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int unaff_ESI;
  uint local_1c;
  int *local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  if (((in_EAX != (int *)0x0) || (in_EAX = (int *)stage_getObjectRef(param_1), in_EAX != (int *)0x0)) &&
     (iVar2 = props_getInt(unaff_ESI), iVar2 == 3)) {
    _DAT_68197764 =
         (uint *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                 *(int *)(unaff_ESI + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    iVar2 = props_coerceToInt(unaff_ESI,(int *)&local_14,(int *)&local_8);
    if (iVar2 == 0) {
      iVar2 = props_getTypedValue(unaff_ESI,2,8,&local_c);
      if (iVar2 != 0) {
        puVar4 = score_lookupProperty(in_EAX,local_c,1,&local_8);
        if (puVar4 == (uint *)0x0) {
          props_normalizeType(unaff_ESI,2,0);
          return 1;
        }
        props_releaseValue(unaff_ESI,(byte)*puVar4,(int *)puVar4[1]);
        _DAT_68197764 =
             (uint *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
                     *(int *)(unaff_ESI + 0x18));
        local_10 = DAT_6819776c;
        local_14 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = 0;
          local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
          local_14 = *(int *)(size_t)_DAT_68197764;
        }
        props_retainValue(unaff_ESI,&local_14);
        iVar2 = *in_EAX;
        *(uint *)(iVar2 + 0x2c + local_8 * 0x10) = local_14;
        *(int **)(iVar2 + 0x30 + local_8 * 0x10) = local_10;
        props_normalizeType(unaff_ESI,4,0);
        return 1;
      }
    }
    else {
      _DAT_68197764 =
           (uint *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
                   *(int *)(unaff_ESI + 0x18));
      local_18 = DAT_6819776c;
      local_1c = DAT_68197768;
      if (_DAT_68197764 != (uint *)0x0) {
        DAT_6819776c = (int *)0x0;
        DAT_68197768 = 0;
        local_18 = (int *)((int *)(size_t)_DAT_68197764)[1];
        local_1c = *(int *)(size_t)_DAT_68197764;
      }
      props_retainValue(unaff_ESI,&local_1c);
      piVar3 = score_findEntryByIndex(in_EAX,local_8 - 1,(int *)0x0);
      if (piVar3 != (int *)0x0) {
        piVar1 = (int *)piVar3[3];
        iVar2 = piVar3[2];
        piVar3[2] = local_1c;
        piVar3[3] = (int)local_18;
        props_releaseValue(unaff_ESI,(byte)iVar2,piVar1);
        props_normalizeType(unaff_ESI,4,0);
        return 1;
      }
      props_releaseValue(unaff_ESI,(byte)local_1c,local_18);
      props_reportError(unaff_ESI,0x3c);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_getObjectPropCount (FUN_68058980)
// Address: 68058980
// Size: 101 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall stage_getObjectPropCount(int *param_1)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  int *local_8;
  
  local_8 = param_1;
  if ((in_EAX == (int *)0x0) && (in_EAX = (int *)stage_getObjectRef(param_1), in_EAX == (int *)0x0)) {
    return 0;
  }
  iVar1 = props_getTypedValue(unaff_EDI,2,4,(uint *)&local_8);
  if (iVar1 != 0) {
    piVar2 = score_findEntryByIndex(in_EAX,(int)local_8 + -1,(int *)0x0);
    if (piVar2 != (int *)0x0) {
      props_normalizeType(unaff_EDI,8,*piVar2);
      return 1;
    }
    props_reportError(unaff_EDI,0x3c);
  }
  return 0;
}



// ============================================================
// Function: stage_getObjectProperty (FUN_680589f0)
// Address: 680589f0
// Size: 445 bytes
// Params: int * param_1, int param_2, int * param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall stage_getObjectProperty(int *param_1,int param_2,int *param_3,undefined4 param_4)

{
  int in_EAX;
  int *piVar1;
  uint *puVar2;
  int iVar3;
  
  if (-1 < in_EAX) {
    *(int **)(param_2 + 0x9c) = param_3;
    *(int *)(param_2 + 0xa0) = in_EAX;
    *(int **)(param_2 + 0xa8) = param_1;
    *(undefined4 *)(param_2 + 0x74) = 2;
    if (param_1 != (int *)0x0) {
      return 1;
    }
    if (*(int *)(*param_3 + 0x70) < 1) {
      return 1;
    }
    piVar1 = stage_buildObjectProps(param_2);
    *(int **)(param_2 + 0xa8) = piVar1;
    *(int **)(*param_3 + 0x34) = piVar1;
    return 1;
  }
  switch(param_4) {
  case 0xd5:
    iVar3 = stage_getObjectPropValue(param_3);
    if (iVar3 != 0) {
      return 1;
    }
    break;
  case 0xd6:
    iVar3 = stage_getObjectPropCount(param_3);
    if (iVar3 != 0) {
      return 1;
    }
    break;
  case 0xdc:
    iVar3 = stage_setObjectPropValue(param_3);
    if (iVar3 != 0) {
      return 1;
    }
    break;
  case 0xdd:
    iVar3 = props_getInt(param_2);
    if (iVar3 == 1) {
      if ((param_1 != (int *)0x0) || (param_1 = (int *)stage_getObjectRef(param_3), param_1 != (int *)0x0)
         ) {
        iVar3 = score_clearPropertyTable(param_1);
        props_normalizeType(param_2,4,iVar3);
        return 1;
      }
      goto code_r0x68058b6a;
    }
    break;
  case 0x119:
    stage_checkContextVar(param_3);
    return 1;
  case 0x11a:
    stage_collectContextRefs(param_3);
    return 1;
  }
  if ((((param_1 != (int *)0x0) &&
       (puVar2 = score_lookupProperty(param_1,0xfd,0,(uint *)0x0), puVar2 != (uint *)0x0)) && (*puVar2 == 3)
      ) && (((int *)puVar2[1] != param_1 &&
            (iVar3 = (**(code **)(**(int **)puVar2[1] + 4))(param_2,(undefined4 *)puVar2[1],param_4)
            , iVar3 != 0)))) {
    return 1;
  }
code_r0x68058b6a:
  switch(param_4) {
  case 0xd3:
  case 0xd4:
    iVar3 = stage_getObjectPropValue(param_3);
    if (iVar3 != 0) {
      return 1;
    }
    break;
  case 0xda:
  case 0xdb:
    iVar3 = stage_setObjectPropValue(param_3);
    if (iVar3 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchObjectProp (FUN_68058C30)
// Address: 68058c30
// Size: 29 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchObjectProp(int param_1,undefined4 param_2,undefined4 param_3)
{
  stage_getObjectProperty(*(int **)(param_1 + 0x60),param_1,*(int **)(param_1 + 0x50),param_3);
  return 0;
}



// ============================================================
// Function: stage_resolveObjectProp (FUN_68058C50)
// Address: 68058c50
// Size: 245 bytes
// Params: int param_1, int * param_2, int param_3, uint param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_resolveObjectProp(int param_1,int *param_2,int param_3,uint param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_4 == 0xfb) {
    if (param_3 != 0) {
      props_reportError(param_1,0x39);
      return 1;
    }
    puVar1 = (undefined4 *)sprites_getNetErrorCode(param_1,*(undefined4 *)(*param_2 + 0x5c));
    if (puVar1 != (undefined4 *)0x0) {
      props_getValuePair(param_1,puVar1,param_5);
      return 1;
    }
    iVar4 = *(int *)(*param_2 + 0x2c);
    if (iVar4 != 0) {
      uVar2 = Ordinal_1114(iVar4);
      iVar3 = Ordinal_1116(iVar4);
      props_createStringFromData(param_1,uVar2,iVar3,param_5);
      Ordinal_1115(iVar4);
      return 1;
    }
    *param_5 = 0;
    param_5[1] = 0;
  }
  else {
    iVar4 = core_accessScriptObjFlags(param_1,param_2,param_3,param_4,param_5);
    if (iVar4 == 0) {
      if (*(int *)(*param_2 + 0x34) == 0) {
        piVar5 = stage_buildObjectProps(param_1);
        *(int **)(*param_2 + 0x34) = piVar5;
      }
      uVar2 = stage_accessProperty(param_1,param_4);
      return uVar2;
    }
  }
  return 1;
}



// ============================================================
// Function: stage_processObjectProp (FUN_68058D50)
// Address: 68058d50
// Size: 73 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_processObjectProp(int param_1,int *param_2,uint param_3)
{
  int *piVar1;
  
  piVar1 = *(int **)(*param_2 + 0x10);
  if (piVar1 != (int *)0x0) {
    props_lookupVariable(param_1,piVar1,param_3);
    stage_getObjectProperty(param_2,param_1,piVar1,param_3);
    return 0;
  }
  stage_getObjectProperty(param_2,param_1,(int *)0x0,param_3);
  return 0;
}



