// Module: core
// Topic: Object property dispatch - per-object-type property get/set routing
// Address range: 0x680102D0 - 0x68016750
// Functions (14):
//   core_accessScriptObjProp (0x680102D0)
//   core_dispatchScriptObjAction (0x68010BB0)
//   core_dispatchSpriteObjAction (0x680113E0)
//   core_accessWindowObjProp (0x68014800)
//   core_dispatchWindowObjAction (0x68015460)
//   core_accessScriptGlobalProp (0x68015B90)
//   core_accessSpriteObjProp (0x68015FE0)
//   core_access3dObjProp (0x68016180)
//   core_accessSoundObjProp (0x680163B0)
//   core_accessColorObjProp (0x680163E0)
//   core_accessDateObjProp (0x68016480)
//   core_accessPaletteObjProp (0x680164B0)
//   core_accessMenuObjProp (0x68016670)
//   core_accessScoreObjProp (0x68016750)

// ============================================================
// Function: core_accessScriptObjProp (FUN_680102d0)
// Address: 680102d0
// Size: 328 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessScriptObjProp(int param_1,int *param_2,int param_3,int param_4,uint *param_5)
{
  uint uVar1;
  int iVar2;
  byte local_408 [1024];
  uint local_8;
  
  uVar1 = *(uint *)(*param_2 + 8);
  if (param_4 < 0x104) {
    if (param_4 == 0x103) {
      if (param_3 == 0) {
        events_getPlaybackSpeed(param_1,uVar1,local_408);
        props_readPascalString(param_1,local_408,param_5);
        goto LAB_68010400;
      }
      iVar2 = props_validateString(param_1,(int *)param_5);
      if (iVar2 == 0) goto LAB_68010400;
      props_toPascalString((int *)param_5,local_408);
      iVar2 = events_setPlaybackSpeed(param_1,uVar1,local_408);
      if (iVar2 != 0) goto LAB_68010400;
    }
    else if (param_4 == 0x2e) {
      if (param_3 == 0) {
        crt_setScriptPropertyEx(param_1,(short)uVar1,param_5);
        goto LAB_68010400;
      }
    }
    else {
      if (param_4 == 0x58) {
        props_reportError(param_1,0x37);
        goto LAB_68010400;
      }
      if (param_4 != 0xaa) goto LAB_680103c0;
      if (param_3 == 0) {
        *param_5 = 4;
        param_5[1] = uVar1;
        goto LAB_68010400;
      }
    }
  }
  else {
    if (param_4 == 0x150) {
      events_resolveMiawPath(param_1,uVar1,param_3,param_5);
      goto LAB_68010400;
    }
    if (param_4 != 0x600) {
LAB_680103c0:
      return 0;
    }
    if (param_3 == 0) {
      *param_5 = 4;
      sprites_getChannelBounds(param_1,uVar1,0,0x12,param_5 + 1);
      goto LAB_68010400;
    }
  }
  props_reportError(param_1,0x39);
LAB_68010400:
  return 0;
}



// ============================================================
// Function: core_dispatchScriptObjAction (FUN_68010bb0)
// Address: 68010bb0
// Size: 844 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_dispatchScriptObjAction(uint param_1,int *param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  undefined1 *local_54;
  uint local_50 [2];
  undefined1 local_48 [64];
  uint local_8;
  
  local_50[1] = *(int *)(*param_2 + 8);
  if (0x3ba < param_3) goto switchD_68010bfd_caseD_4d;
  if (param_3 == 0x3ba) {
    iVar2 = events_getMiawExtendedProp(param_1,local_50[1]);
    props_normalizeType(param_1,4,iVar2);
    return 0;
  }
  switch(param_3) {
  case 0x4b:
    iVar2 = props_getTypedValue(param_1,2,4,local_50);
    if (iVar2 != 0) {
      iVar2 = events_getMiawTimerRef(param_1,local_50[1],local_50[0]);
      props_normalizeType(param_1,4,iVar2);
      return 0;
    }
    goto LAB_68010eea;
  case 0x4c:
    iVar2 = props_getTypedValue(param_1,2,4,local_50);
    if (iVar2 != 0) {
      iVar2 = events_setMiawTimerRef(param_1,local_50[1],local_50[0]);
      props_normalizeType(param_1,4,iVar2);
      return 0;
    }
    goto LAB_68010eea;
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x81:
  case 0xca:
  case 0xce:
  case 0xd4:
  case 0xdb:
  case 0xdd:
    if (param_3 == 0xca) {
      param_3 = 0x5c;
    }
    else if (param_3 == 0xce) {
      param_3 = 0x5d;
    }
    iVar2 = sprites_dispatchChannelProperty(param_1,local_50[1]);
    if (iVar2 != 0) {
      score_dispatchXtraCall(param_1,iVar2,param_3);
      return 0;
    }
    break;
  case 0xd3:
    if ((local_50[1] == -1) && (iVar2 = props_getInt(param_1), iVar2 == 2)) {
      _DAT_68197764 =
           (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                   *(int *)(param_1 + 0x18));
      uVar1 = DAT_68197768;
      if (_DAT_68197764 != (uint *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        uVar1 = *(int *)(size_t)_DAT_68197764;
      }
      core_resolveAndSetScript(uVar1);
      props_popArgs(param_1,&local_74);
      return 0;
    }
    break;
  case 0xe3:
    score_resolveType(param_1);
    return 0;
  }
switchD_68010bfd_caseD_4d:
  local_58 = props_getInt(param_1);
  if (local_58 < 9) {
    iVar2 = 1;
    local_54 = local_48;
    local_70 = 0;
    if (0 < local_58) {
      do {
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + -8 + (iVar2 - *(int *)(param_1 + 0x20)) * 8 +
                     *(int *)(param_1 + 0x18));
        uVar1 = DAT_6819776c;
        uVar3 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          uVar1 = ((int *)(size_t)_DAT_68197764)[1];
          uVar3 = *(int *)(size_t)_DAT_68197764;
        }
        local_50[iVar2 * 2] = uVar3;
        *(uint *)(local_48 + iVar2 * 8 + -4) = uVar1;
        iVar2 = iVar2 + 1;
      } while (iVar2 <= local_58);
      goto LAB_68010e8f;
    }
  }
  else {
    local_70 = cast_allocHandle(local_58 * 8,0);
    if (local_70 == 0) goto LAB_68010eea;
    local_54 = (undefined1 *)Ordinal_1114(local_70);
    iVar2 = 1;
    if (0 < local_58) {
      do {
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + -8 + (iVar2 - *(int *)(param_1 + 0x20)) * 8 +
                     *(int *)(param_1 + 0x18));
        uVar1 = DAT_6819776c;
        uVar3 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          uVar1 = ((int *)(size_t)_DAT_68197764)[1];
          uVar3 = *(int *)(size_t)_DAT_68197764;
        }
        *(uint *)(local_54 + iVar2 * 8 + -8) = uVar3;
        *(uint *)(local_54 + iVar2 * 8 + -4) = uVar1;
        iVar2 = iVar2 + 1;
      } while (iVar2 <= local_58);
    }
LAB_68010e8f:
    if (local_54 == (undefined1 *)0x0) goto LAB_68010eea;
  }
  local_6c = 0;
  local_68 = 0;
  local_60 = 2;
  local_5c = 0;
  local_64 = param_3;
  iVar2 = events_getMiawChannelData(param_1,local_50[1],(int)&local_6c);
  if (local_70 != 0) {
    cast_freeHandle(local_70);
  }
  if (iVar2 == 0) {
    props_popArgs(param_1,&local_60);
    return 0;
  }
LAB_68010eea:
  return 0;
}



// ============================================================
// Function: core_dispatchSpriteObjAction (FUN_680113e0)
// Address: 680113e0
// Size: 787 bytes
// Params: void * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_dispatchSpriteObjAction(void *param_1,int *param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_54 [2];
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar2 = *(int *)(*param_2 + 8);
  piVar1 = (int *)props_getInt((int)param_1);
  local_30 = piVar1;
  if (param_3 < 0x5ff) {
    if (param_3 == 0x5fe) {
      if (1 < (int)piVar1) {
        iVar3 = core_setFieldValue(param_1,(int *)(**(int **)((int)param_1 + 0x10) +
                                             *(int *)((int)param_1 + 0x20) * -8 + 8 +
                                            *(int *)((int)param_1 + 0x18)),&local_48);
        if (iVar3 == 0) {
          props_setError((int)param_1,0x10);
          goto LAB_680116db;
        }
        if (2 < (int)piVar1) {
          iVar3 = props_getRectField((int)param_1,
                               (int *)(**(int **)((int)param_1 + 0x10) +
                                       (2 - *(int *)((int)param_1 + 0x20)) * 8 +
                                      *(int *)((int)param_1 + 0x18)));
          if (iVar3 == 0) {
            props_setError((int)param_1,0xf);
            goto LAB_680116db;
          }
        }
      }
      crt_setScriptPropertyEx((int)param_1,(short)iVar2,local_54);
      crt_dispatchPlatformOp((int)param_1,iVar2,0x12);
      sprites_getChannelBounds((int)param_1,iVar2,1,0,&local_4c);
      if (local_4c == 0) {
        crt_dispatchPlatformOp((int)param_1,iVar2,1);
        crt_dispatchPlatformOp((int)param_1,iVar2,7);
      }
      if (1 < (int)piVar1) {
        local_44 = 1;
        local_2c = 0;
        iVar3 = sprites_getMemberInfo((int)param_1,&local_48);
        local_40 = sprites_dispatchExtPropertyByType((int)param_1,iVar3);
        core_accessChannelMember((uint)param_1,iVar2,1,
                     (int *)(**(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8 +
                             8 + *(int *)((int)param_1 + 0x18)));
        if ((int)local_30 < 3) {
LAB_680115ca:
          sprites_getEventInfo((int)param_1,&local_18);
          local_c = local_c - local_14;
          local_10 = local_10 - local_18;
          local_14 = 0;
          local_18 = 0;
          if (local_40 != 0x2c) {
            iVar3 = sprites_dispatchPropertyEx(param_1,iVar3,0,0xbc,&local_34);
            if (iVar3 == 0) {
              iVar3 = props_createRect(param_1,(int *)&local_34);
              if (iVar3 != 0) {
                if (local_24 < local_1c) {
                  if (local_28 < local_20) {
                    local_20 = local_20 - local_28;
                    local_1c = local_1c - local_24;
                    local_24 = (local_c - local_1c) / 2;
                    local_1c = local_1c + local_24;
                    local_28 = (local_10 - local_20) / 2;
                    local_20 = local_20 + local_28;
                    events_setWindowData((int)param_1,iVar2,&local_28);
                    if (local_2c == 0) {
                      local_44 = 0;
                    }
                  }
                }
              }
              props_releaseValue(param_1,(byte)local_34,local_30);
              if (local_44 == 0) goto LAB_680116a8;
            }
            if (local_2c == 0) {
              local_38 = local_c / 2;
              local_3c = local_10 / 2;
            }
          }
        }
        else if (local_40 == 0x1fb) {
          local_2c = 1;
          goto LAB_680115ca;
        }
        events_setMiawMediaRef((int)param_1,iVar2,&local_3c);
      }
LAB_680116a8:
      piVar1 = local_54;
    }
    else {
      if (param_3 != 0xd3) {
        if (param_3 == 0xe3) {
          score_resolveType((uint)param_1);
          goto LAB_680116db;
        }
LAB_680116b5:
        return 0;
      }
      if (iVar2 != -1) goto LAB_680116b5;
      iVar2 = props_getInt((int)param_1);
      if (iVar2 != 2) goto LAB_680116b5;
      _DAT_68197764 =
           (int *)(**(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8 + 8 +
                  *(int *)((int)param_1 + 0x18));
      if (_DAT_68197764 == (int *)0x0) {
        piVar1 = &local_3c;
        core_resolveAndCreateSpriteRef(DAT_68197768);
      }
      else {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        piVar1 = &local_3c;
        core_resolveAndCreateSpriteRef(*(int *)(size_t)_DAT_68197764);
      }
    }
  }
  else {
    if (param_3 != 0x5ff) goto LAB_680116b5;
    core_resetChannelEntry(iVar2);
    piVar1 = (int *)0x0;
  }
  props_popArgs((int)param_1,piVar1);
LAB_680116db:
  return 0;
}



// ============================================================
// Function: core_accessWindowObjProp (FUN_68014800)
// Address: 68014800
// Size: 2004 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessWindowObjProp(int param_1,int *param_2,int param_3,int param_4,uint *param_5)
{
  int *piVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar6;
  uint local_424;
  int *local_420;
  int local_41c;
  int local_418 [4];
  byte local_408 [1024];
  uint local_8;
  
  local_420 = param_2;
  iVar4 = *param_2;
  piVar5 = *(int **)(iVar4 + 8);
  if (param_4 < 0x13a) {
    if (param_4 == 0x139) {
      if (param_3 == 0) {
        piVar5 = events_getWindowMessageData(param_1,piVar5);
        param_5[1] = (uint)piVar5;
        *param_5 = 8;
      }
      else {
        iVar4 = props_requireSymbolId(param_1,(int *)param_5,&local_41c);
        if ((iVar4 != 0) && (iVar4 = events_getMiawRect(param_1,piVar5,local_41c), iVar4 == 0)) {
          props_setErrorAndReturn(param_1,0x13);
        }
      }
      goto LAB_68014fb6;
    }
    switch(param_4) {
    case 0xa9:
      if (param_3 == 0) {
        events_setMiawFileName(param_1,piVar5,0,param_5);
      }
      else {
        props_reportError(param_1,0x39);
      }
      break;
    default:
      goto switchD_68014855_caseD_aa;
    case 0xbc:
      if (param_3 == 0) {
        events_handleWindowDispatch(param_1,piVar5,local_418);
        props_computeRectOp(param_1,local_418,param_5);
      }
      else {
        iVar4 = props_createRect(param_1,(int *)param_5);
        if (iVar4 != 0) {
          events_resolveWindowPath(param_1,piVar5,local_418);
        }
      }
      break;
    case 0xfc:
      if (param_3 != 0) {
        iVar4 = props_validateString(param_1,(int *)param_5);
        if (iVar4 != 0) {
          props_toPascalString((int *)param_5,local_408);
          events_getMiawProperty(param_1,piVar5,local_408);
        }
        break;
      }
      events_getEventParam(param_1,piVar5,local_408);
      sprites_getCastRef(param_1,local_408);
      goto LAB_68014fb0;
    case 0x103:
      if (param_3 == 0) {
        if (*(int *)(iVar4 + 0x18) != 0) {
          *param_5 = *(uint *)(iVar4 + 0x14);
          param_5[1] = *(uint *)(iVar4 + 0x18);
          props_retainValue(param_1,param_5);
        }
      }
      else {
        iVar4 = props_validateString(param_1,(int *)param_5);
        piVar5 = local_420;
        if (iVar4 != 0) {
          props_releaseValue(param_1,(byte)*(undefined4 *)(*local_420 + 0x14),*(int **)(*local_420 + 0x18)
                      );
          local_424 = *param_5;
          local_420 = (int *)param_5[1];
          props_retainValue(param_1,&local_424);
          iVar4 = *piVar5;
          *(uint *)(iVar4 + 0x14) = local_424;
          *(int **)(iVar4 + 0x18) = local_420;
        }
      }
    }
    goto LAB_68014fb6;
  }
  if (0x291 < param_4) {
    if (param_4 < 0x61d) {
      if (param_4 == 0x61c) {
        if (param_3 == 0) {
          *param_5 = 4;
          bVar2 = events_checkPermission(param_1,piVar5,0x1000);
          param_5[1] = CONCAT31(extraout_var_01,bVar2);
        }
        else {
          iVar4 = props_requireInt(param_1,(int *)param_5,&local_41c);
          if (iVar4 != 0) {
            events_processWindowEvent(param_1,piVar5,0x1000,local_41c);
          }
        }
        goto LAB_68014fb6;
      }
      if (param_4 < 0x394) {
        if (param_4 == 0x393) {
          iVar4 = sprites_getStageRef(param_1);
          if (iVar4 == 0) {
            if (param_3 == 0) {
              iVar4 = events_requestWindowClose(param_1,(int)piVar5,0);
              core_findObjectById(iVar4,param_5);
            }
            else {
              props_reportError(param_1,0x39);
            }
          }
          else {
            props_reportError(param_1,0x66);
          }
        }
        else if (param_4 == 0x359) {
          if (param_3 == 0) {
            events_initScoreCallbacks(param_1,piVar5,(undefined1 *)&local_420);
            props_storeFloatValue(param_1,&local_420,param_5);
          }
          else {
            iVar4 = props_coerceAndStore(param_1,param_5,(int *)&local_420);
            if (iVar4 == 0) {
              events_notifyScoreChange(param_1,piVar5,(int *)&local_420);
            }
          }
        }
        else {
          if (param_4 != 0x392) goto switchD_68014855_caseD_aa;
          iVar4 = sprites_getStageRef(param_1);
          if (iVar4 == 0) {
            if (param_3 == 0) {
              iVar4 = events_requestWindowClose(param_1,(int)piVar5,1);
              core_findObjectById(iVar4,param_5);
            }
            else {
              props_reportError(param_1,0x39);
            }
          }
          else {
            props_reportError(param_1,0x66);
          }
        }
        goto LAB_68014fb6;
      }
      if (param_4 != 0x602) goto switchD_68014855_caseD_aa;
switchD_68014a33_caseD_15f:
      if (param_3 == 0) {
        core_wrapMember(param_1,param_2,*(int **)(**(int **)(param_1 + 8) + 0x5b0),param_5);
        goto LAB_68014fb6;
      }
    }
    else {
      if (param_4 == 0x61d) {
        if (param_3 != 0) {
          iVar4 = props_validateString(param_1,(int *)param_5);
          if (iVar4 != 0) {
            props_toPascalString((int *)param_5,local_408);
            events_getMiawTitle(param_1,piVar5,local_408);
          }
          goto LAB_68014fb6;
        }
        events_unregisterScoreHandler(param_1,piVar5,local_408);
        goto LAB_68014fb0;
      }
      if (param_4 == 0x61f) {
        uVar6 = events_getScoreProperty(param_1);
        if (uVar6 < 0x1000) {
          if (param_3 == 0) {
            param_5[1] = 0xffffffff;
            *param_5 = 4;
          }
          goto LAB_68014fb6;
        }
switchD_68014855_caseD_aa:
        return 0;
      }
      if (param_4 != 0x660) goto switchD_68014855_caseD_aa;
      if (param_3 == 0) {
        core_wrapMember(param_1,param_2,*(int **)(**(int **)(param_1 + 8) + 0x5d0),param_5);
        goto LAB_68014fb6;
      }
    }
    goto LAB_68014f06;
  }
  if (param_4 == 0x291) {
    if (param_3 == 0) {
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + 1;
      cast_createWithDimensions(param_1,param_2,piVar5);
    }
    else {
      props_reportError(param_1,0x39);
    }
    goto LAB_68014fb6;
  }
  switch(param_4) {
  case 0x150:
    if (param_3 == 0) {
      *param_5 = 4;
      uVar6 = events_dispatchHandler(param_1,piVar5);
      param_5[1] = uVar6;
    }
    else {
      iVar4 = props_requireInt(param_1,(int *)param_5,&local_41c);
      if (iVar4 != 0) {
        events_handleWindowEvent(param_1,piVar5,local_41c);
      }
    }
    break;
  default:
    goto switchD_68014855_caseD_aa;
  case 0x15f:
    goto switchD_68014a33_caseD_15f;
  case 0x20e:
    if (param_3 == 0) {
      events_setMiawSizeState(param_1,piVar5,local_418);
      props_computeRectOp(param_1,local_418,param_5);
    }
    else {
      iVar4 = props_createRect(param_1,(int *)param_5);
      if (iVar4 != 0) {
        events_getMiawPaletteRef(param_1,piVar5,local_418);
      }
    }
    break;
  case 0x20f:
    if (param_3 == 0) {
      events_setMiawModal(param_1,piVar5,local_418);
      props_computeRectOp(param_1,local_418,param_5);
      break;
    }
    goto LAB_68014f06;
  case 0x211:
    if (param_3 != 0) {
      iVar4 = props_validateString(param_1,(int *)param_5);
      if (iVar4 != 0) {
        props_toPascalString((int *)param_5,local_408);
        events_setMiawProperty(param_1,piVar5,(int)local_408);
      }
      break;
    }
    events_registerScoreHandler(param_1,piVar5,local_408);
LAB_68014fb0:
    props_readPascalString(param_1,local_408,param_5);
    break;
  case 0x212:
    if (param_3 == 0) {
      *param_5 = 4;
      bVar2 = events_checkPermission(param_1,piVar5,2);
      param_5[1] = CONCAT31(extraout_var,bVar2);
    }
    else {
      iVar4 = props_requireInt(param_1,(int *)param_5,&local_41c);
      if (iVar4 != 0) {
        events_processWindowEvent(param_1,piVar5,2,local_41c);
      }
    }
    break;
  case 0x213:
    if (param_3 == 0) {
      *param_5 = 4;
      bVar2 = events_checkPermission(param_1,piVar5,4);
      param_5[1] = CONCAT31(extraout_var_00,bVar2);
    }
    else {
      iVar4 = props_requireInt(param_1,(int *)param_5,&local_41c);
      if (iVar4 != 0) {
        events_processWindowEvent(param_1,piVar5,4,local_41c);
      }
    }
    break;
  case 0x214:
    if (param_3 == 0) {
      *param_5 = 8;
      uVar6 = events_handleWindowMessage(param_1,piVar5);
      param_5[1] = uVar6;
      break;
    }
LAB_68014f06:
    props_reportError(param_1,0x39);
    break;
  case 0x21b:
    if (param_3 == 0) {
      piVar1 = *(int **)(iVar4 + 0xc);
      piVar5 = (int *)(*piVar1 + 4);
      *piVar5 = *piVar5 + 1;
      *param_5 = 3;
      param_5[1] = (uint)piVar1;
      break;
    }
    iVar4 = core_isSpriteMember(param_1,(int *)param_5);
    if (iVar4 != 0) {
      props_releaseObject(param_1,*(int **)(*local_420 + 0xc));
      *(uint *)(*local_420 + 0xc) = param_5[1];
      piVar1 = (int *)(**(int **)(*local_420 + 0xc) + 4);
      *piVar1 = *piVar1 + 1;
      events_setMiawTitle(param_1,piVar5);
      break;
    }
    goto LAB_68014c9b;
  case 0x221:
    if (param_3 == 0) {
      piVar1 = *(int **)(iVar4 + 0x10);
      piVar5 = (int *)(*piVar1 + 4);
      *piVar5 = *piVar5 + 1;
      *param_5 = 3;
      param_5[1] = (uint)piVar1;
      break;
    }
    iVar4 = core_isSpriteMemberRef(param_1,(int *)param_5);
    if (iVar4 != 0) {
      props_releaseObject(param_1,*(int **)(*local_420 + 0x10));
      *(uint *)(*local_420 + 0x10) = param_5[1];
      piVar1 = (int *)(**(int **)(*local_420 + 0x10) + 4);
      *piVar1 = *piVar1 + 1;
      events_setMiawTitle(param_1,piVar5);
      break;
    }
LAB_68014c9b:
    props_setError(param_1,0x13);
    break;
  case 0x235:
    if (param_3 == 0) {
      sVar3 = events_setWindowTitle(param_1,piVar5);
      param_5[1] = (int)sVar3;
      *param_5 = 4;
    }
    else {
      iVar4 = props_requireInt(param_1,(int *)param_5,&local_41c);
      if ((iVar4 != 0) && (iVar4 = events_setMiawVisible(param_1,piVar5,(short)local_41c), iVar4 == 0)) {
        props_setErrorAndReturn(param_1,0x13);
      }
    }
  }
LAB_68014fb6:
  props_restoreScript(param_1);
  return 0;
}



// ============================================================
// Function: core_dispatchWindowObjAction (FUN_68015460)
// Address: 68015460
// Size: 582 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchWindowObjAction(uint param_1,int *param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  uint local_81c [2];
  uint local_814;
  uint local_810;
  uint local_80c;
  undefined1 local_808 [1024];
  undefined1 local_408 [1024];
  
  piVar1 = *(int **)(*param_2 + 8);
  if (param_3 < 0x225) {
    if (param_3 == 0x224) {
      core_dispatchHandlerList(param_2,'\x01');
    }
    else if (param_3 < 0x14f) {
      if (param_3 == 0x14e) {
        events_handleWindowEvent(param_1,piVar1,0);
      }
      else {
        if (param_3 == 0xe3) {
          score_resolveType(param_1);
          goto LAB_6801568f;
        }
        if (param_3 == 0x10c) {
          crt_removeBehavior(param_1,param_2);
        }
        else {
          if (param_3 != 0x14b) goto LAB_68015555;
          events_handleWindowEvent(param_1,piVar1,1);
        }
      }
    }
    else if (param_3 == 0x205) {
      events_getMiawModal(param_1,piVar1);
    }
    else {
      if (param_3 != 0x206) goto LAB_68015555;
      events_getWindowBounds(param_1,piVar1);
    }
  }
  else if (param_3 < 0x229) {
    if (param_3 == 0x228) {
      events_getProjectorMode(param_1,piVar1);
    }
    else if (param_3 == 0x226) {
      events_getProjectorRef(param_1,piVar1);
    }
    else {
      if (param_3 != 0x227) goto LAB_68015555;
      events_setProjectorRef(param_1,piVar1);
    }
  }
  else if (param_3 == 0x631) {
    iVar2 = props_getInt(param_1);
    if (iVar2 == 4) {
      iVar2 = props_getValueDirect(param_1,2,1,&local_814);
      if (iVar2 == 0) goto LAB_6801568f;
      iVar2 = props_getValueDirect(param_1,3,1,local_81c);
      if (iVar2 == 0) goto LAB_6801568f;
      iVar2 = props_getTypedValue(param_1,4,4,&local_80c);
      if (iVar2 == 0) goto LAB_6801568f;
      props_toPascalString((int *)&local_814,local_808);
      props_toPascalString((int *)local_81c,local_408);
      events_broadcastScoreEvent(param_1,piVar1,local_808,local_408,local_80c);
    }
    else {
LAB_68015679:
      props_setError(param_1,0x19);
    }
  }
  else {
    if (param_3 != 0x632) {
LAB_68015555:
      return 0;
    }
    iVar2 = props_getInt(param_1);
    if (iVar2 == 3) {
      iVar2 = props_getTypedValue(param_1,2,4,&local_80c);
      if (iVar2 == 0) goto LAB_6801568f;
      iVar2 = props_getTypedValue(param_1,3,4,&local_810);
      if (iVar2 == 0) goto LAB_6801568f;
      events_processScoreNotify(param_1,piVar1,1,local_80c,local_810);
    }
    else {
      iVar2 = props_getInt(param_1);
      if (iVar2 != 1) goto LAB_68015679;
      events_processScoreNotify(param_1,piVar1,0,0,0);
    }
  }
  props_popArgs(param_1,(undefined4 *)0x0);
  props_restoreScript(param_1);
LAB_6801568f:
  return 0;
}



// ============================================================
// Function: core_accessScriptGlobalProp (FUN_68015b90)
// Address: 68015b90
// Size: 28 bytes
// Params: uint param_1, undefined4 param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessScriptGlobalProp(uint param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)
{
  core_accessGlobalExtended(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_accessSpriteObjProp (FUN_68015fe0)
// Address: 68015fe0
// Size: 144 bytes
// Params: uint param_1, undefined4 param_2, int param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_accessSpriteObjProp(uint param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    if (param_4 < 0x69) {
      if (param_4 == 0x68) {
        core_createDefaultMemberRef(param_1,param_5);
        return 1;
      }
      if (param_4 == 0x2e) {
        crt_createDefaultChannelRef(param_1,param_5);
        return 1;
      }
      if (param_4 == 0x58) {
        core_createEmptyField(param_1,param_5);
        return 1;
      }
    }
    else if (param_4 == 0x5fd) {
      core_createDefaultSpriteRef(param_1,param_5);
      return 1;
    }
  }
  uVar1 = core_accessGlobalProperty(param_1,param_3,param_4,param_5);
  return uVar1;
}



// ============================================================
// Function: core_access3dObjProp (FUN_68016180)
// Address: 68016180
// Size: 92 bytes
// Params: uint param_1, undefined4 param_2, int param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_access3dObjProp(uint param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    if (param_4 == 0x662) {
      core_createDefaultColorRef(param_1,param_5,0);
      return 1;
    }
    if (param_4 == 0x663) {
      core_createDefaultColorRef(param_1,param_5,1);
      return 1;
    }
  }
  uVar1 = core_accessGlobalProperty(param_1,param_3,param_4,param_5);
  return uVar1;
}



// ============================================================
// Function: core_accessSoundObjProp (FUN_680163b0)
// Address: 680163b0
// Size: 28 bytes
// Params: uint param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessSoundObjProp(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  crt_dispatchAppCommand(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_accessColorObjProp (FUN_680163e0)
// Address: 680163e0
// Size: 28 bytes
// Params: uint param_1, undefined4 param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessColorObjProp(uint param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)
{
  crt_dispatchMovieProperty(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_accessDateObjProp (FUN_68016480)
// Address: 68016480
// Size: 28 bytes
// Params: uint param_1, undefined4 param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessDateObjProp(uint param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)
{
  crt_dispatchWindowProperty(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_accessPaletteObjProp (FUN_680164b0)
// Address: 680164b0
// Size: 28 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessPaletteObjProp(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)
{
  crt_getTimerProperty(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_accessMenuObjProp (FUN_68016670)
// Address: 68016670
// Size: 28 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessMenuObjProp(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  core_accessGlobalMisc(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_accessScoreObjProp (FUN_68016750)
// Address: 68016750
// Size: 57 bytes
// Params: uint param_1, undefined4 param_2, int param_3, uint param_4, uint * param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_accessScoreObjProp(uint param_1,undefined4 param_2,int param_3,uint param_4,uint *param_5)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = score_setPropertyAndDispatch(param_1,param_4,param_5);
    return iVar1 == 0;
  }
  iVar1 = score_getPropertyValue(param_1,param_4,param_5);
  return iVar1 == 0;
}


