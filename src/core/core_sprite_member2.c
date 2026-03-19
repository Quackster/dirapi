// Module: core
// Topic: Sprite member type 2 - additional cast member wrapper operations
// Address range: 0x6801E500 - 0x6801EAB0
// Functions (8):
//   core_getMemberRefPropByIndex (0x6801E500)
//   core_getMemberRefPropByKey (0x6801E620)
//   core_allocSpriteMemberRef (0x6801E710)
//   core_isSpriteMemberRef (0x6801E770)
//   core_syncSpritePropsData (0x6801E7A0)
//   core_destroySpriteProps (0x6801EA30)
//   core_formatSpritePropsString (0x6801EA80)
//   core_getSetSpriteProp (0x6801EAB0)

// ============================================================
// Function: core_getMemberRefPropByIndex (FUN_6801e500)
// Address: 6801e500
// Size: 283 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_getMemberRefPropByIndex(int *param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 local_20 [2];
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(*param_1 + 0xc);
  iVar2 = props_getInt(unaff_ESI);
  if (iVar2 != 3) {
    props_setError(unaff_ESI,0x17);
    return 0;
  }
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
  iVar2 = props_coerceToInt(unaff_ESI,&local_10,&local_8);
  if (iVar2 != 0) {
    iVar2 = props_getListLength(unaff_ESI,piVar1);
    if ((local_8 < 1) || (iVar2 < local_8)) {
      props_setError(unaff_ESI,0x3c);
      return 0;
    }
    _DAT_68197764 =
         (int *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
                *(int *)(unaff_ESI + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    local_8 = local_8 + -1;
    score_getProplistRaw(unaff_ESI,piVar1,local_8,&local_18,local_20);
    core_getSetMemberRefProp(unaff_ESI,param_1,1,local_14,&local_10);
  }
  return 1;
}



// ============================================================
// Function: core_getMemberRefPropByKey (FUN_6801e620)
// Address: 6801e620
// Size: 228 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_getMemberRefPropByKey(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 != 3) {
    props_setError(unaff_ESI,0x17);
    return 0;
  }
  iVar1 = **(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
          *(int *)(unaff_ESI + 0x18);
  iVar2 = DAT_6819776c;
  if (iVar1 != 0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    iVar2 = *(int *)(iVar1 + 4);
  }
  _DAT_68197764 =
       (int *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
              *(int *)(unaff_ESI + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  if (param_2 != 0xdb) {
    core_getSetMemberRefProp(unaff_ESI,param_1,1,iVar2,&local_c);
    return 1;
  }
  uVar3 = core_getSetMemberRefProp(unaff_ESI,param_1,1,iVar2,&local_c);
  return uVar3;
}



// ============================================================
// Function: core_allocSpriteMemberRef (FUN_6801e710)
// Address: 6801e710
// Size: 91 bytes
// Params: int param_1, undefined1 param_2, undefined4 param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * core_allocSpriteMemberRef(int param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)cast_allocHandle(0x18,1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  uVar3 = score_dispatchProplist(param_1);
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[3] = uVar3;
  puVar1[2] = param_3;
  *(undefined1 *)(puVar1 + 5) = param_2;
  *puVar1 = &PTR_LAB_6818b8a8;
  puVar1[1] = 1;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 0;
  return piVar2;
}



// ============================================================
// Function: core_isSpriteMemberRef (FUN_6801e770)
// Address: 6801e770
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_isSpriteMemberRef(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818b8a8)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_syncSpritePropsData (FUN_6801e7a0)
// Address: 6801e7a0
// Size: 651 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_syncSpritePropsData(int param_1,int *param_2)
{
  int iVar1;
  uint local_418 [4];
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = *(int *)(*param_2 + 8);
  local_418[0] = 8;
  if (iVar1 != 0) {
    events_getScoreMarkerName(param_1,local_408);
    props_readPascalString(param_1,local_408,local_418 + 2);
    local_418[1] = 0x211;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_418 + 2));
    local_418[2] = 8;
    local_418[3] = events_getScoreMarkerCount(param_1);
    local_418[1] = 0x139;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_418 + 2));
    local_418[2] = 4;
    local_418[3] = events_editChannel(param_1,2);
    local_418[1] = 0x212;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_418 + 2));
    local_418[2] = 4;
    local_418[3] = events_editChannel(param_1,4);
    local_418[1] = 0x213;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_418 + 2));
    local_418[2] = 4;
    local_418[3] = events_editChannel(param_1,0x1000);
    local_418[1] = 0x61c;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_418 + 2));
    events_getScoreMarkerLabel(param_1,local_408);
    props_readPascalString(param_1,local_408,local_418 + 2);
    local_418[1] = 0x61d;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_418 + 2));
    core_setSpriteMemberData(param_1,*(int **)(*param_2 + 0xc));
    local_418[2] = 3;
    local_418[3] = *(undefined4 *)(**(int **)(*param_2 + 0xc) + 0xc);
    local_418[1] = 0x21b;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
    core_getSpriteMemberData(param_1,*(int **)(*param_2 + 0x10));
    local_418[2] = 3;
    local_418[3] = *(undefined4 *)(**(int **)(*param_2 + 0x10) + 0xc);
    local_418[1] = 0x221;
    score_setPropertyValue(param_1,iVar1,local_418,local_418 + 2,1);
  }
  return 0;
}



// ============================================================
// Function: core_destroySpriteProps (FUN_6801ea30)
// Address: 6801ea30
// Size: 73 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_destroySpriteProps(int param_1,int *param_2)
{
  score_freeProplist(param_1,*(int **)(*param_2 + 8));
  if (*(int **)(*param_2 + 0xc) != (int *)0x0) {
    props_releaseObject(param_1,*(int **)(*param_2 + 0xc));
  }
  if (*(int **)(*param_2 + 0x10) != (int *)0x0) {
    props_releaseObject(param_1,*(int **)(*param_2 + 0x10));
  }
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: core_formatSpritePropsString (FUN_6801ea80)
// Address: 6801ea80
// Size: 44 bytes
// Params: int param_1, int * param_2, undefined * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatSpritePropsString(int param_1,int *param_2,undefined *param_3,undefined4 param_4)
{
  core_syncSpritePropsData(param_1,param_2);
  score_formatProplistString(param_1,*(int **)(*param_2 + 8),param_3,param_4);
  return 0;
}



// ============================================================
// Function: core_getSetSpriteProp (FUN_6801eab0)
// Address: 6801eab0
// Size: 722 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getSetSpriteProp(int param_1,int *param_2,int param_3,int param_4,int *param_5)
{
  int iVar1;
  int *piVar2;
  int local_40c;
  byte local_408 [1024];
  uint local_8;
  
  if (param_4 < 0x21c) {
    if (param_4 == 0x21b) {
      if (param_3 != 0) {
        iVar1 = core_isSpriteMember(param_1,param_5);
        if (iVar1 != 0) {
          props_releaseObject(param_1,*(int **)(*param_2 + 0xc));
          *(int *)(*param_2 + 0xc) = param_5[1];
          piVar2 = (int *)(**(int **)(*param_2 + 0xc) + 4);
          *piVar2 = *piVar2 + 1;
          goto LAB_6801ed6a;
        }
LAB_6801ec4e:
        props_setError(param_1,0x13);
        goto LAB_6801ed6a;
      }
      piVar2 = *(int **)(*param_2 + 0xc);
LAB_6801ed5c:
      *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
      *param_5 = 3;
    }
    else {
      switch(param_4) {
      case 0x139:
        if (param_3 != 0) {
          iVar1 = props_requireSymbolId(param_1,param_5,&local_40c);
          if (iVar1 != 0) {
            events_setScoreMarkerCount(param_1,local_40c);
          }
          goto LAB_6801ed6a;
        }
        piVar2 = (int *)events_getScoreMarkerCount(param_1);
        *param_5 = 8;
        break;
      default:
switchD_6801eafa_caseD_13a:
        return 0;
      case 0x211:
        if (param_3 == 0) {
          events_getScoreMarkerName(param_1,local_408);
          props_readPascalString(param_1,local_408,param_5);
        }
        else {
          iVar1 = props_validateString(param_1,param_5);
          if (iVar1 != 0) {
            props_toPascalString(param_5,local_408);
            events_setScoreMarkerIndex(param_1,(int)local_408);
          }
        }
        goto LAB_6801ed6a;
      case 0x212:
        if (param_3 != 0) {
          iVar1 = props_requireInt(param_1,param_5,&local_40c);
          if (iVar1 != 0) {
            events_editChannelData(param_1,2,local_40c);
          }
          goto LAB_6801ed6a;
        }
        piVar2 = (int *)events_editChannel(param_1,2);
        *param_5 = 4;
        break;
      case 0x213:
        if (param_3 != 0) {
          iVar1 = props_requireInt(param_1,param_5,&local_40c);
          if (iVar1 != 0) {
            events_editChannelData(param_1,4,local_40c);
          }
          goto LAB_6801ed6a;
        }
        piVar2 = (int *)events_editChannel(param_1,4);
        *param_5 = 4;
      }
    }
  }
  else {
    if (param_4 == 0x221) {
      if (param_3 != 0) {
        iVar1 = core_isSpriteMemberRef(param_1,param_5);
        if (iVar1 != 0) {
          props_releaseObject(param_1,*(int **)(*param_2 + 0x10));
          *(int *)(*param_2 + 0x10) = param_5[1];
          piVar2 = (int *)(**(int **)(*param_2 + 0x10) + 4);
          *piVar2 = *piVar2 + 1;
          goto LAB_6801ed6a;
        }
        goto LAB_6801ec4e;
      }
      piVar2 = *(int **)(*param_2 + 0x10);
      goto LAB_6801ed5c;
    }
    if (param_4 != 0x61c) {
      if (param_4 != 0x61d) goto switchD_6801eafa_caseD_13a;
      if (param_3 == 0) {
        events_getScoreMarkerLabel(param_1,local_408);
        props_readPascalString(param_1,local_408,param_5);
      }
      else {
        iVar1 = props_validateString(param_1,param_5);
        if (iVar1 != 0) {
          props_toPascalString(param_5,local_408);
          events_setScoreMarkerIndex(param_1,(int)local_408);
        }
      }
      goto LAB_6801ed6a;
    }
    if (param_3 != 0) {
      iVar1 = props_requireInt(param_1,param_5,&local_40c);
      if (iVar1 != 0) {
        events_editChannelData(param_1,0x1000,local_40c);
      }
      goto LAB_6801ed6a;
    }
    *param_5 = 4;
    piVar2 = (int *)events_editChannel(param_1,0x1000);
  }
  param_5[1] = (int)piVar2;
LAB_6801ed6a:
  return 0;
}


