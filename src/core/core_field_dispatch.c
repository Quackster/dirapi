// Module: core
// Topic: Field/cursor action and property dispatch
// Address range: 0x68018050 - 0x68018AC0
// Functions (2):
//   core_dispatchFieldPropertyAction (0x68018050)
//   core_registerFieldHandlers (0x68018AC0)

// ============================================================
// Function: core_dispatchFieldPropertyAction (FUN_68018050)
// Address: 68018050
// Size: 2219 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_dispatchFieldPropertyAction(uint param_1,int *param_2,int param_3)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  int extraout_EDX;
  int *piVar6;
  undefined8 uVar7;
  uint local_47c [2];
  undefined4 local_474;
  uint local_470;
  int local_46c;
  int local_468;
  int *local_464;
  uint local_460;
  int *local_45c;
  uint local_458;
  int *local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined1 local_448 [1024];
  undefined1 local_48 [64];
  uint local_8;
  
  uVar5 = *(undefined4 *)(*param_2 + 8);
  local_458 = 4;
  local_454 = (int *)0x0;
  local_44c = uVar5;
  if (param_3 < 0x1da) {
    if (param_3 == 0x1d9) {
      iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
      if (iVar4 == 0) goto LAB_680181f0;
      iVar4 = sprites_lookupMemberCastData(param_1,&local_44c);
      if (iVar4 == 0) {
        props_setError(param_1,0x5d);
        goto LAB_680188e3;
      }
      sprites_dispatchPropertyByName(param_1,&local_44c);
    }
    else {
      switch(param_3) {
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
        iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
        if (iVar4 != 0) {
          iVar4 = sprites_getMemberData(param_1,&local_44c);
          if (iVar4 == 0) {
            iVar4 = sprites_dispatchFlashProperty(param_1,&local_44c);
            if (iVar4 != 0) {
              score_dispatchXtraCall(param_1,iVar4,param_3);
              return 0;
            }
          }
          else {
            iVar4 = score_getXtraProperty(param_1,(undefined4 *)0x0,6,&local_44c,&local_458);
            if (iVar4 != 0) {
              core_setMemberProperty(&local_458);
              return 0;
            }
          }
          goto LAB_680187bb;
        }
        if ((param_3 != 0xdd) || (iVar4 = props_getInt(param_1), iVar4 != 1)) goto LAB_680181f0;
        local_458 = 4;
        local_454 = (int *)sprites_getMemberByChannel(param_1,(short)local_44c);
        break;
      default:
switchD_680180b6_caseD_5e:
        local_44c = uVar5;
        iVar4 = core_collectFieldEntries(local_44c,param_3,&local_458);
        if (iVar4 == 0) {
LAB_680187bb:
          return 0;
        }
        break;
      case 0xd3:
        iVar4 = props_getInt(param_1);
        uVar5 = local_44c;
        if ((iVar4 != 2) || (0 < (short)(*(unsigned short *)((char *)&local_44c + 2)))) goto switchD_680180b6_caseD_5e;
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                     *(int *)(param_1 + 0x18));
        local_454 = DAT_6819776c;
        local_458 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = 0;
          local_454 = (int *)((int *)(size_t)_DAT_68197764)[1];
          local_458 = *(int *)(size_t)_DAT_68197764;
        }
        crt_executePlatformQuery(param_1,(int *)&local_458,sprites_resetMember,(short *)&local_44c);
        sprites_checkBounds(param_1,(short *)&local_44c);
        local_458 = 2;
        if ((*(unsigned short *)((char *)&local_44c + 2)) < 0x8000) {
          core_getFieldValue(param_1,&local_44c,&local_458);
        }
        else {
          local_454 = (int *)0x0;
        }
        break;
      case 0xe3:
        score_resolveType(param_1);
        goto LAB_680188e3;
      case 0xe4:
        iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
        if (iVar4 == 0) goto LAB_680188e3;
        local_450 = CONCAT22(0xffff,(short)local_44c);
        iVar4 = props_getInt(param_1);
        if (((1 < iVar4) && (iVar4 = core_resetMemberField(param_1), iVar4 == 0)) ||
           ((iVar4 = props_getInt(param_1), 2 < iVar4 && (iVar4 = core_applyMemberField(param_1), iVar4 == 0)
            ))) goto LAB_680188e3;
        local_454 = (int *)sprites_copyMemberToCast(param_1,&local_44c,&local_450);
      }
    }
  }
  else if (param_3 < 0x1f1) {
    if (param_3 == 0x1f0) {
      iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
      if (iVar4 == 0) goto LAB_680181f0;
      bVar1 = sprites_isMemberLoaded(param_1,&local_44c);
      local_454 = (int *)CONCAT31(extraout_var,bVar1);
    }
    else if (param_3 == 0x1dc) {
      iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
      if (iVar4 == 0) goto LAB_680188e3;
      local_450 = local_44c;
      iVar4 = props_getInt(param_1);
      if ((1 < iVar4) && (iVar4 = core_resetMemberField(param_1), iVar4 == 0)) goto LAB_680188e3;
      iVar4 = events_getScorePropertyState();
      sprites_dispatchBitmapMedia(param_1,(int *)0x0,&local_44c,&local_450,&local_474,iVar4);
    }
    else {
      if (param_3 != 0x1e0) goto switchD_680180b6_caseD_5e;
      iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
      if (iVar4 == 0) goto LAB_680188e3;
      local_450 = local_44c;
      iVar4 = props_getInt(param_1);
      if ((1 < iVar4) && (iVar4 = core_resetMemberField(param_1), iVar4 == 0)) goto LAB_680188e3;
      sprites_dispatchBitmapRect(param_1,(int *)0x0,&local_44c,&local_450);
    }
  }
  else if (param_3 < 0x209) {
    if (param_3 == 0x208) {
      iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
      if (iVar4 == 0) goto LAB_680188e3;
      local_454 = (int *)sprites_checkMemberExists(param_1,&local_44c);
    }
    else {
      (*(unsigned short *)((char *)&local_44c + 2)) = (ushort)((uint)uVar5 >> 0x10);
      switch(param_3) {
      case 0x1f1:
        bVar1 = (*(unsigned short *)((char *)&local_44c + 2)) == -1;
        if (bVar1) {
LAB_680181f0:
          props_setError(param_1,0x23);
          goto LAB_680188e3;
        }
        local_454 = (int *)sprites_deleteMember(param_1,&local_44c);
        break;
      case 0x1f2:
        iVar4 = crt_getPlatformValue(param_1,(short *)&local_44c);
        if (iVar4 == 0) goto LAB_680188e3;
        local_450 = CONCAT22(0xffff,(short)local_44c);
        iVar4 = props_getInt(param_1);
        if (((1 < iVar4) && (iVar4 = core_resetMemberField(param_1), iVar4 == 0)) ||
           ((iVar4 = props_getInt(param_1), 2 < iVar4 && (iVar4 = core_applyMemberField(param_1), iVar4 == 0)
            ))) goto LAB_680188e3;
        local_454 = (int *)sprites_moveMemberToCast(param_1,&local_44c,&local_450);
        break;
      case 499:
        bVar1 = (*(unsigned short *)((char *)&local_44c + 2)) == -1;
        piVar6 = (int *)0x5;
        if (bVar1) goto LAB_680181f0;
        iVar4 = props_getValueDirect(param_1,2,1,local_47c);
        if (iVar4 == 0) goto LAB_680188e3;
        props_toPascalString((int *)local_47c,local_448);
        iVar4 = props_getInt(param_1);
        if (2 < iVar4) {
          _DAT_68197764 =
               (uint *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                       *(int *)(param_1 + 0x18));
          local_45c = DAT_6819776c;
          local_460 = DAT_68197768;
          if (_DAT_68197764 != (uint *)0x0) {
            DAT_6819776c = (int *)0x0;
            DAT_68197768 = 0;
            local_45c = (int *)((int *)(size_t)_DAT_68197764)[1];
            local_460 = *(int *)(size_t)_DAT_68197764;
          }
          iVar4 = score_getProplistValue(param_1,(int *)&local_460);
          if (iVar4 == 0) goto LAB_680188e3;
          local_464 = local_45c;
          local_468 = cast_getMemberData(param_1,local_45c);
          iVar4 = 1;
          if (0 < local_468) {
            do {
              cast_getContextData(param_1,local_464,iVar4,&local_470,&local_460);
              props_resolveValue(param_1,&local_470);
              if (local_470 == 8) {
                if (local_46c < 0x3a1) {
                  if (local_46c == 0x3a0) {
                    uVar7 = props_callBuiltinMethod(extraout_ECX,(int)&local_460,param_1,(byte *)&local_460);
                    iVar2 = (int)((ulonglong)uVar7 >> 0x20);
                    uVar5 = extraout_ECX_00;
                    if ((int)uVar7 == 0) {
                      if (local_45c == (int *)0x0) {
                        piVar6 = (int *)((uint)piVar6 & 0xfffffff7);
                      }
                      else {
                        piVar6 = (int *)((uint)piVar6 | 8);
                      }
                    }
LAB_680186f9:
                    iVar2 = props_callBuiltinMethod(uVar5,iVar2,param_1,(byte *)&local_460);
                    if (iVar2 == 0) {
                      if (local_45c == (int *)0x0) {
                        piVar6 = (int *)((uint)piVar6 & 0xfffffffe);
                      }
                      else {
                        piVar6 = (int *)((uint)piVar6 | 1);
                      }
                    }
                  }
                  else if (local_46c == 0x35c) {
                    iVar2 = props_callBuiltinMethod(&local_460,extraout_EDX,param_1,(byte *)&local_460);
                    if (iVar2 == 0) {
                      if (local_45c == (int *)0x0) {
                        piVar6 = (int *)((uint)piVar6 & 0xfffffffd);
                      }
                      else {
                        piVar6 = (int *)((uint)piVar6 | 2);
                      }
                    }
                  }
                  else if ((local_46c == 0x38a) &&
                          (iVar2 = props_callBuiltinMethod(extraout_ECX,extraout_EDX,param_1,(byte *)&local_460
                                               ), iVar2 == 0)) {
                    if (local_45c == (int *)0x0) {
                      piVar6 = (int *)((uint)piVar6 & 0xfffffffb);
                    }
                    else {
                      piVar6 = (int *)((uint)piVar6 | 4);
                    }
                  }
                }
                else {
                  uVar5 = extraout_ECX;
                  iVar2 = extraout_EDX;
                  if (local_46c == 0x639) goto LAB_680186f9;
                }
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 <= local_468);
          }
        }
        local_454 = (int *)sprites_getMemberPropertyEx(param_1,&local_44c,(int)local_448,piVar6);
        break;
      case 500:
        local_458 = 4;
        uVar3 = sprites_getMemberCastIndex(param_1,&local_44c);
        local_454 = (int *)(int)(short)uVar3;
        break;
      default:
        goto switchD_680180b6_caseD_5e;
      }
    }
  }
  else {
    if (param_3 != 0x657) goto switchD_680180b6_caseD_5e;
    iVar4 = props_getInt(param_1);
    if (iVar4 < 3) {
      props_setError(param_1,0x3a);
      goto LAB_680188e3;
    }
    bVar1 = (*(unsigned short *)((char *)&local_44c + 2)) == -1;
    if (bVar1) goto LAB_680181f0;
    iVar4 = score_getMediaProperty(param_1,(int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8
                                         + 8 + *(int *)(param_1 + 0x18)),(int *)&local_464);
    if (iVar4 != 0) {
      local_468 = 0;
      iVar4 = (**(code **)(*local_464 + 0x44))(local_464,&local_468);
      if ((iVar4 == 0) && (local_468 == 0x64c)) {
        local_45c = (int *)0x0;
        iVar4 = props_getValueDirect(param_1,3,1,&local_470);
        if (iVar4 == 0) goto LAB_680188e3;
        props_coerceAndReturnString(param_1,&local_470,local_48,0x40);
        iVar4 = (**(code **)*local_464)(local_464,&DAT_681760f8,&local_45c);
        if (iVar4 == 0) {
          local_454 = (int *)sprites_importMemberFile(param_1,local_46c,local_48,&local_44c,local_45c);
          (**(code **)(*local_45c + 8))(local_45c);
        }
      }
    }
  }
  props_popArgs(param_1,&local_458);
LAB_680188e3:
  return 0;
}



// ============================================================
// Function: core_registerFieldHandlers (FUN_68018ac0)
// Address: 68018ac0
// Size: 98 bytes
// Params: void * param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_registerFieldHandlers(void *param_1,int *param_2,undefined4 *param_3)
{
  int local_18;
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *local_8;
  
  puVar2 = param_3;
  pvVar1 = param_1;
  puVar3 = (undefined4 *)crt_getMemberCursor((int)param_1,param_3);
  if (puVar3 != (undefined4 *)0x0) {
    param_1 = (void *)0x0;
    param_3 = (undefined4 *)Ordinal_1116(puVar3);
    local_8 = param_3;
    if (param_2 != (int *)0x0) {
      score_registerAllHandlers((int)pvVar1,param_2,(int *)&param_1,(int *)&param_3,(byte *)*puVar3,
                   (int *)&local_8);
    }
    sprites_registerMemberMedia((int)pvVar1,puVar2,param_1,param_3);
  }
  return 0;
}


