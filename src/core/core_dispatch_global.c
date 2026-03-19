// Module: core
// Topic: Global property dispatch - large switch-based property get/set handlers
// Address range: 0x68010930 - 0x680145B0
// Functions (4):
//   core_accessGlobalMisc (0x68010930)
//   core_accessGlobalExtended (0x68011900)
//   core_accessGlobalProperty (0x68012710)
//   core_accessGlobalAll (0x680145B0)

// ============================================================
// Function: core_accessGlobalMisc (FUN_68010930)
// Address: 68010930
// Size: 447 bytes
// Params: uint param_1, uint param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_accessGlobalMisc(uint param_1,uint param_2,int param_3,uint *param_4)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  
  if (param_3 < 299) {
    if (param_3 == 0x12a) {
      if (param_2 == 0) {
        param_2 = Ordinal_1107();
LAB_68010a50:
        param_4[1] = param_2;
        return 1;
      }
    }
    else {
      switch(param_3) {
      case 0x10e:
        if (param_2 == 0) {
          uVar2 = cast_getGlobalData();
          param_4[1] = uVar2;
          return 1;
        }
        iVar3 = props_requireInt(param_1,(int *)param_4,(int *)&param_2);
        if (iVar3 != 0) {
          cast_seedRandom(param_2);
          return 1;
        }
        return 1;
      default:
        return 0;
      case 0x111:
        if (param_2 == 0) {
          uVar2 = sprites_getMovieRef(param_1);
          param_4[1] = uVar2;
          return 1;
        }
        break;
      case 0x128:
        if (param_2 == 0) {
          param_2 = Ordinal_1106();
          if (param_2 == 0x7fffffff) {
            param_2 = 0x80000000;
          }
          else if (param_2 < 0x7fffffff) goto LAB_68010a50;
          dVar1 = (double)(int)param_2;
          if ((int)param_2 < 0) {
            dVar1 = dVar1 + 4294967296.0;
          }
          if (param_2 == 0xffffffff) {
            dVar1 = dVar1 + 1.0;
          }
          props_storeNumber(param_1,dVar1,param_4);
          return 1;
        }
        break;
      case 0x129:
        if (param_2 == 0) {
          uVar2 = Ordinal_1108();
          param_4[1] = uVar2;
          return 1;
        }
      }
    }
  }
  else {
    if (param_3 < 0x372) {
      if (param_3 != 0x371) {
        if (param_3 == 0x18c) {
          events_setWindowProperty(param_1,6,param_2,param_4);
          return 1;
        }
        if (param_3 != 0x2d6) {
          return 0;
        }
        if (param_2 == 0) {
          sprites_getDisplayRect(param_1,param_4);
          return 1;
        }
        goto LAB_68010ac1;
      }
    }
    else if (param_3 != 0x609) {
      return 0;
    }
    if (param_2 == 0) {
      crt_buildEnvironmentInfo(param_4);
      return 1;
    }
  }
LAB_68010ac1:
  props_reportError(param_1,0x39);
  return 1;
}



// ============================================================
// Function: core_accessGlobalExtended (FUN_68011900)
// Address: 68011900
// Size: 2882 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessGlobalExtended(uint param_1,int param_2,int param_3,uint *param_4)
{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined3 extraout_var;
  byte *pbVar6;
  undefined3 extraout_var_00;
  undefined4 extraout_EDX;
  float10 fVar7;
  byte *pbVar8;
  int local_414;
  byte local_410 [1024];
  uint local_10;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  uint local_8;
  
  if (param_3 < 0x2d4) {
    if (param_3 == 0x2d3) {
      if (param_2 == 0) {
        core_getObjectRefById(param_1,param_4);
        return 0;
      }
      goto LAB_6801239f;
    }
    if (param_3 < 0x191) {
      if (param_3 == 400) {
        events_setWindowProperty(param_1,0x1d,param_2,param_4);
        return 0;
      }
      if (param_3 == 0x10f) {
        if (param_2 == 0) {
          local_10 = 0;
          uStack_c = 0;
          uStack_b = 0;
          Ordinal_1246();
          props_readPascalString(param_1,(byte *)&local_10,param_4);
          return 0;
        }
        iVar3 = props_validateString(param_1,(int *)param_4);
        if (iVar3 != 0) {
          props_getStringData((int *)param_4,(int *)0x0);
          uVar4 = Ordinal_1252();
          *(undefined4 *)(**(int **)(param_1 + 8) + 0x500) = uVar4;
          props_unlockString((int *)param_4);
          return 0;
        }
        goto LAB_68012415;
      }
switchD_68011a20_caseD_1c1:
      return 0;
    }
    switch(param_3) {
    case 0x1bd:
      events_setWindowProperty(param_1,0xe,param_2,param_4);
      return 0;
    case 0x1be:
      events_setWindowProperty(param_1,0x11,param_2,param_4);
      return 0;
    case 0x1bf:
      events_setWindowProperty(param_1,0x12,param_2,param_4);
      return 0;
    case 0x1c0:
      events_setWindowProperty(param_1,0xf,param_2,param_4);
      return 0;
    default:
      goto switchD_68011a20_caseD_1c1;
    case 0x229:
      if (param_2 == 0) {
        crt_ensurePropertyList();
        if (*(int *)(**(int **)(param_1 + 8) + 0x510) != 0) {
          *param_4 = 3;
          param_4[1] = *(uint *)(**(int **)(param_1 + 8) + 0x510);
          props_retainValue(param_1,param_4);
          return 0;
        }
        break;
      }
      iVar3 = props_setRectField(param_1,(int *)param_4);
      if (iVar3 != 0) {
        piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x510);
        *(undefined4 *)(**(int **)(param_1 + 8) + 0x510) = 0;
        if (piVar1 != (int *)0x0) {
          crt_getScriptPropertyEx(param_1,piVar1);
        }
        props_releaseObject(param_1,piVar1);
        *(uint *)(**(int **)(param_1 + 8) + 0x510) = param_4[1];
        crt_getScriptProperty(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510));
        props_setListSortVtable(param_1,*(undefined4 **)(**(int **)(param_1 + 8) + 0x510));
        *param_4 = 0;
        if (*(int *)(param_1 + 0xe0) != 0) {
          local_10 = 3;
          uVar4 = *(undefined4 *)(**(int **)(param_1 + 8) + 0x518);
          uStack_c = (undefined1)uVar4;
          uStack_b = (undefined1)((uint)uVar4 >> 8);
          uStack_a = (undefined2)((uint)uVar4 >> 0x10);
          iVar3 = props_getListRange(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),(int *)&local_10);
          if (iVar3 < 0) {
            props_setListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),&local_10);
            return 0;
          }
        }
        break;
      }
      goto LAB_680122c2;
    case 0x238:
    case 0x247:
      goto switchD_68011a20_caseD_238;
    case 0x239:
      iVar3 = sprites_getStageRef(param_1);
      if (iVar3 != 0) {
        props_reportError(param_1,0x66);
        return 0;
      }
      if (param_2 == 0) {
        bVar2 = events_isTraceEnabled();
        param_4[1] = CONCAT31(extraout_var,bVar2);
        return 0;
      }
      iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar3 != 0) {
        events_setTraceEnabled(param_1,(uint)(local_414 != 0));
        return 0;
      }
      break;
    case 0x249:
      if (param_2 != 0) goto LAB_6801239f;
      if (*(int *)(**(int **)(param_1 + 8) + 0x514) != 0) {
        *param_4 = 2;
        props_cloneRectAndReturn(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514),param_4);
        props_retainValue(param_1,param_4);
        return 0;
      }
      uVar5 = props_getRectCount(param_1);
      param_4[1] = uVar5;
      if (uVar5 != 0) {
        *param_4 = 3;
        return 0;
      }
      break;
    case 0x28a:
      if (param_2 == 0) {
        uVar5 = Ordinal_1986();
        param_4[1] = uVar5;
        return 0;
      }
      iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar3 != 0) {
        Ordinal_1985(local_414);
        return 0;
      }
    }
    goto LAB_68012415;
  }
  if (0x552 < param_3) {
    switch(param_3) {
    case 0x60a:
switchD_68011a20_caseD_238:
      iVar3 = sprites_getStageRef(param_1);
      if (iVar3 != 0) {
        props_reportError(param_1,0x66);
        return 0;
      }
      if (param_2 != 0) {
        iVar3 = props_setRectField(param_1,(int *)param_4);
        if (iVar3 != 0) {
          events_setGlobalRef(param_1,(int *)param_4[1]);
          *param_4 = 0;
          return 0;
        }
LAB_680122c2:
        props_setErrorAndReturn(param_1,0xd);
        return 0;
      }
      uVar5 = events_getOrCreateGlobalRef(param_1);
      param_4[1] = uVar5;
      if (uVar5 != 0) {
        *param_4 = 3;
        props_retainValue(param_1,param_4);
        return 0;
      }
      goto LAB_68012415;
    default:
      goto switchD_68011a20_caseD_1c1;
    case 0x612:
      if (param_2 == 0) {
        bVar2 = cast_isContextValid(param_1);
        param_4[1] = CONCAT31(extraout_var_00,bVar2);
      }
      else {
        iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
        if (iVar3 != 0) {
          props_setTraceMode(param_1,local_414);
          events_handleProjectorExit(param_1,local_414);
          return 0;
        }
      }
      goto LAB_68012415;
    case 0x62b:
    case 0x62c:
    case 0x62d:
    case 0x62e:
      goto switchD_68011db2_caseD_36a;
    case 0x679:
      fVar7 = (float10)Ordinal_2038();
      if (param_2 == 0) {
        props_storeNumber(param_1,(double)fVar7,param_4);
        return 0;
      }
      goto LAB_6801239f;
    }
  }
  if (param_3 == 0x552) {
    core_accessToggleState((int *)param_4);
    return 0;
  }
  switch(param_3) {
  case 0x2d4:
    if (param_2 == 0) {
      core_getObjectRefByIdAlt(param_1);
      return 0;
    }
    goto LAB_6801239f;
  default:
    goto switchD_68011a20_caseD_1c1;
  case 0x2dc:
    if (param_2 == 0) {
      uVar5 = events_setMiawPaletteRef(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar3 != 0) {
      events_getMiawSourceRect(param_1,(uint)(local_414 != 0));
      return 0;
    }
    goto LAB_68012415;
  case 0x2e6:
    break;
  case 0x2e7:
    break;
  case 0x2e8:
    break;
  case 0x2e9:
    break;
  case 0x2eb:
    break;
  case 0x2ec:
    break;
  case 0x30f:
    if (param_2 == 0) {
      uVar5 = core_countRegisteredEntries(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    goto LAB_6801239f;
  case 0x317:
    if (param_2 != 0) {
      if (((*param_4 != 4) || (param_4[1] != 0)) && (*param_4 != 3)) {
        props_setErrorAndReturn(param_1,0xc);
        return 0;
      }
      sprites_setActiveHandler(param_1,(int *)param_4[1]);
      return 0;
    }
    uVar5 = sprites_getActiveHandler(param_1);
    if (uVar5 != 0) {
      *param_4 = 3;
      param_4[1] = uVar5;
      props_retainValue(param_1,param_4);
      return 0;
    }
    goto LAB_68012415;
  case 0x333:
    if (param_2 == 0) {
      uVar5 = events_setMiawVideoRef(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    goto LAB_6801239f;
  case 0x334:
    iVar3 = sprites_getStageRef(param_1);
    if (iVar3 != 0) {
      props_reportError(param_1,0x66);
      return 0;
    }
    if (param_2 == 0) {
      events_openMovieChannel(param_1,local_410);
      props_readPascalString(param_1,local_410,param_4);
      return 0;
    }
    goto LAB_6801239f;
  case 0x339:
    events_setWindowProperty(param_1,0x25,param_2,param_4);
    return 0;
  case 0x33b:
    events_setWindowProperty(param_1,0x26,param_2,param_4);
    return 0;
  case 0x33d:
    if (param_2 == 0) {
      uVar5 = sprites_getChannelBufferSize(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar3 != 0) {
      sprites_resizeChannelBuffer(param_1,local_414);
      return 0;
    }
    goto LAB_68012415;
  case 0x36a:
    goto switchD_68011db2_caseD_36a;
  case 0x37c:
    iVar3 = sprites_getStageRef(param_1);
    if (iVar3 != 0) {
      props_reportError(param_1,0x66);
      return 0;
    }
    if (param_2 == 0) {
      events_handleMovieTransition(param_1,local_410);
      props_readPascalString(param_1,local_410,param_4);
      return 0;
    }
    goto LAB_6801239f;
  case 0x3b7:
    if (param_2 == 0) {
      uVar5 = Ordinal_2300();
      param_4[1] = uVar5;
      return 0;
    }
    iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar3 == 0) {
      props_setErrorAndReturn(param_1,0x13);
      return 0;
    }
    Ordinal_2317(local_414 != 0);
    Ordinal_2301();
    return 0;
  case 0x3c7:
    if (param_2 == 0) {
      uVar5 = events_setMiawSourceRect(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar3 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar3 != 0) {
      events_getMiawName(param_1,(uint)(local_414 != 0));
      return 0;
    }
    goto LAB_68012415;
  }
  if (param_2 == 0) {
    iVar3 = crt_getScriptObjectValue(param_1);
    iVar3 = media_applyPixelOp(iVar3,extraout_EDX,local_410,0x400);
    if (iVar3 == 0) {
      pbVar8 = local_410;
      pbVar6 = (byte *)Ordinal_1233(pbVar8,pbVar8,param_4);
      props_readPascalString(param_1,pbVar6,(undefined4 *)pbVar8);
      return 0;
    }
LAB_68012415:
    return 0;
  }
LAB_6801239f:
  props_reportError(param_1,0x39);
  return 0;
switchD_68011db2_caseD_36a:
  if (param_2 == 0) {
    sprites_openFileDialog(param_1,param_3,param_4);
    return 0;
  }
  goto LAB_6801239f;
}



// ============================================================
// Function: core_accessGlobalProperty (FUN_68012710)
// Address: 68012710
// Size: 6879 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessGlobalProperty(uint param_1,int param_2,int param_3,uint *param_4)
{
  bool bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined3 extraout_var;
  int *piVar7;
  undefined3 extraout_var_00;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  undefined3 extraout_var_01;
  float10 fVar11;
  uint local_41c;
  undefined4 local_418;
  int local_414;
  byte local_410 [1024];
  undefined8 local_10;
  uint local_8;
  
  if (param_3 < 0x201) {
    if (param_3 == 0x200) {
      if (param_2 == 0) {
        uVar5 = events_invalidateScoreLine(param_1);
        param_4[1] = uVar5;
        return 0;
      }
    }
    else {
      if (0x103 < param_3) {
        switch(param_3) {
        case 0x120:
          if (param_2 != 0) {
            iVar8 = props_setRectField(param_1,(int *)param_4);
            if ((iVar8 != 0) || ((*param_4 == 4 && (param_4[1] == 0)))) {
              sprites_getNetLocalPath(param_1,(int *)param_4[1]);
              return 0;
            }
            goto LAB_68012b9f;
          }
          uVar5 = sprites_getNetMimeType(param_1);
          param_4[1] = uVar5;
          if (uVar5 != 0) {
            *param_4 = 3;
            props_retainValue(param_1,param_4);
            return 0;
          }
          break;
        default:
          goto switchD_680127c7_caseD_121;
        case 0x15c:
          if (param_2 == 0) {
            uVar5 = events_getScoreFrameRate(param_1);
            param_4[1] = uVar5;
            return 0;
          }
          iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
          if (iVar8 != 0) {
            events_setScoreFrameRate(param_1,local_414);
            return 0;
          }
          break;
        case 0x18d:
          events_setWindowProperty(param_1,8,param_2,param_4);
          return 0;
        case 0x18e:
          events_setWindowProperty(param_1,0x18,param_2,param_4);
          return 0;
        case 399:
          events_setWindowProperty(param_1,0x17,param_2,param_4);
          return 0;
        case 0x191:
          events_setWindowProperty(param_1,9,param_2,param_4);
          return 0;
        case 0x192:
          events_setWindowProperty(param_1,3,param_2,param_4);
          return 0;
        case 0x193:
          events_setWindowProperty(param_1,4,param_2,param_4);
          return 0;
        case 0x194:
          events_setWindowProperty(param_1,5,param_2,param_4);
          return 0;
        case 0x195:
          events_setWindowProperty(param_1,2,param_2,param_4);
          return 0;
        case 0x198:
          events_setWindowProperty(param_1,1,param_2,param_4);
          return 0;
        case 0x199:
          events_setWindowProperty(param_1,0x22,param_2,param_4);
          return 0;
        case 0x1b1:
          if (param_2 == 0) {
            (*(unsigned int *)((char *)&local_10 + 0)) = 4;
            (*(unsigned int *)((char *)&local_10 + 4)) = (int *)0x0;
            puVar6 = (undefined4 *)sprites_extractMemberData(param_1);
            if (puVar6 != (undefined4 *)0x0) {
              props_getValuePair(param_1,puVar6,(undefined4 *)&local_10);
              *param_4 = (uint)local_10;
              param_4[1] = (uint)(*(unsigned int *)((char *)&local_10 + 4));
              return 0;
            }
            props_readPascalString(param_1,&DAT_6817a914,(undefined4 *)&local_10);
            *param_4 = (uint)local_10;
            param_4[1] = (uint)(*(unsigned int *)((char *)&local_10 + 4));
            return 0;
          }
          goto LAB_68014193;
        case 0x1b4:
          events_setWindowProperty(param_1,0x15,param_2,param_4);
          return 0;
        }
        goto LAB_6801419e;
      }
      if (param_3 == 0x103) goto switchD_68012b19_caseD_22b;
      if (param_3 == 0x3c) {
        if (param_2 == 0) {
          uVar5 = sprites_getEventRef(param_1);
          param_4[1] = uVar5;
          return 0;
        }
      }
      else {
        if (param_3 != 0x7c) goto switchD_680127c7_caseD_121;
        if (param_2 == 0) {
          core_getObjectRefById(param_1,param_4);
          return 0;
        }
      }
    }
    goto LAB_68014193;
  }
  if (0x34d < param_3) {
    if (0x4d4 < param_3) {
      if (param_3 < 0x60c) {
        if (param_3 == 0x60b) goto switchD_680136ad_caseD_363;
        switch(param_3) {
        case 0x550:
          if (param_2 == 0) {
            uVar5 = events_getScoreSpacing(param_1);
            param_4[1] = uVar5;
            *param_4 = 8;
            return 0;
          }
          iVar8 = props_requireSymbolId(param_1,(int *)param_4,&local_414);
          if (iVar8 != 0) {
            events_setScoreSpacing(param_1,local_414);
            return 0;
          }
          break;
        case 0x551:
          if (param_2 == 0) {
            uVar5 = events_getScoreChannelCount(param_1);
            param_4[1] = uVar5;
            *param_4 = 8;
            return 0;
          }
          goto LAB_68014193;
        default:
          goto switchD_680127c7_caseD_121;
        case 0x556:
          if (param_2 == 0) {
            uVar5 = events_getChannelEditMode(param_1);
            param_4[1] = uVar5;
            return 0;
          }
          iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
          if (iVar8 != 0) {
            events_setChannelEditMode(param_1,(uint)(local_414 != 0));
            return 0;
          }
          break;
        case 0x570:
          goto switchD_680136ad_caseD_362;
        }
        goto LAB_6801419e;
      }
      switch(param_3) {
      case 0x60c:
        goto switchD_68012b19_caseD_23a;
      case 0x60d:
        goto switchD_680136ad_caseD_3b5;
      case 0x60e:
        goto switchD_68012b19_caseD_23b;
      default:
switchD_680127c7_caseD_121:
        return 0;
      case 0x612:
        goto switchD_68012b19_caseD_20a;
      case 0x656:
        if (param_2 == 0) {
          uVar5 = events_getChannelSelection(param_1);
          param_4[1] = uVar5;
          return 0;
        }
        iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
        if (iVar8 != 0) {
          events_setChannelSelection(param_1,(uint)(local_414 != 0));
          return 0;
        }
        break;
      case 0x676:
        if (param_2 == 0) {
          props_loadCString(param_1," ",param_4);
          goto LAB_680141c2;
        }
        goto LAB_68014193;
      case 0x677:
        if (param_2 == 0) {
          fVar11 = events_getScoreDuration(param_1);
          props_storeNumber(param_1,(double)fVar11,param_4);
          return 0;
        }
        iVar8 = props_requireFloat(param_1,(int *)param_4,(double *)&local_10);
        if (iVar8 != 0) {
          events_setScoreDuration(param_1,(double)CONCAT26((short)((uint)(*(unsigned int *)((char *)&local_10 + 4)) >> 0x10),
                                                CONCAT15((char)((uint)(*(unsigned int *)((char *)&local_10 + 4)) >> 8),
                                                         CONCAT14((char)(*(unsigned int *)((char *)&local_10 + 4)),
                                                                  (uint)local_10))));
          return 0;
        }
      }
      goto LAB_6801419e;
    }
    if (param_3 == 0x4d4) goto switchD_68012b19_caseD_22a;
    switch(param_3) {
    case 0x34e:
      if (param_2 == 0) {
        bVar2 = events_getScoreFlag(param_1);
        param_4[1] = (int)(char)~bVar2 & 1;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        bVar2 = events_getScoreFlag(param_1);
        if (local_414 != 0) {
          events_setScoreFlag(param_1,bVar2 & 0xfe);
          return 0;
        }
        events_setScoreFlag(param_1,bVar2 | 1);
        return 0;
      }
      break;
    case 0x34f:
      if (param_2 == 0) {
        bVar2 = events_getScoreFlag(param_1);
        param_4[1] = ((int)(char)~bVar2 & 2U) >> 1;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        bVar2 = events_getScoreFlag(param_1);
        if (local_414 != 0) {
          events_setScoreFlag(param_1,bVar2 & 0xfd);
          return 0;
        }
        events_setScoreFlag(param_1,bVar2 | 2);
        return 0;
      }
      break;
    case 0x350:
      if (param_2 == 0) {
        bVar2 = events_getScoreFlag(param_1);
        param_4[1] = ((int)(char)~bVar2 & 8U) >> 3;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        bVar2 = events_getScoreFlag(param_1);
        if (local_414 != 0) {
          events_setScoreFlag(param_1,bVar2 & 0xf7);
          return 0;
        }
        events_setScoreFlag(param_1,bVar2 | 8);
        return 0;
      }
      break;
    case 0x351:
      if (param_2 == 0) {
        bVar2 = events_getScoreFlag(param_1);
        param_4[1] = ((int)(char)~bVar2 & 4U) >> 2;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        bVar2 = events_getScoreFlag(param_1);
        if (local_414 != 0) {
          events_setScoreFlag(param_1,bVar2 & 0xfb);
          return 0;
        }
        events_setScoreFlag(param_1,bVar2 | 4);
        return 0;
      }
      break;
    case 0x352:
      if (param_2 == 0) {
        bVar2 = events_getScoreFlag(param_1);
        param_4[1] = ((int)(char)~bVar2 & 0x20U) >> 5;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        bVar2 = events_getScoreFlag(param_1);
        if (local_414 != 0) {
          events_setScoreFlag(param_1,bVar2 & 0xdf);
          return 0;
        }
        events_setScoreFlag(param_1,bVar2 | 0x20);
        return 0;
      }
      break;
    default:
      goto switchD_680127c7_caseD_121;
    case 0x354:
      if (param_2 == 0) {
        uVar5 = sprites_getChannelCursorState(param_1);
        param_4[1] = uVar5;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        sprites_writeChannelProperty(param_1,local_414);
        return 0;
      }
      break;
    case 0x362:
switchD_680136ad_caseD_362:
      local_41c = 0;
      if (param_2 == 0) {
        events_getChannelProp1B(param_1,7,&local_41c);
        if (local_41c != 0) {
          pbVar10 = (byte *)Ordinal_1114((char)local_41c);
          props_readPascalString(param_1,pbVar10,param_4);
          Ordinal_1115(local_41c);
          Ordinal_1113(&local_41c);
          return 0;
        }
        goto LAB_680141c2;
      }
      goto LAB_68014193;
    case 0x363:
switchD_680136ad_caseD_363:
      local_41c = 0;
      if (param_2 == 0) {
        events_getChannelProp1B(param_1,8,&local_41c);
        if (local_41c != 0) {
          pbVar10 = (byte *)Ordinal_1114((char)local_41c);
          props_readPascalString(param_1,pbVar10,param_4);
          Ordinal_1115(local_41c);
          Ordinal_1113(&local_41c);
          return 0;
        }
LAB_680141c2:
        return 0;
      }
      goto LAB_68014193;
    case 0x36a:
    case 0x36b:
      if (param_2 == 0) {
        sprites_showAlert(param_1,param_4);
        return 0;
      }
      goto LAB_68014193;
    case 0x375:
      if (param_2 == 0) {
        uVar5 = events_getScoreProperty2(param_1);
        param_4[1] = uVar5;
        return 0;
      }
      goto LAB_68014193;
    case 0x377:
      if (param_2 == 0) {
        uVar5 = events_getScoreBlendAmount(param_1);
        param_4[1] = uVar5;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        events_setScoreBlendAmount(param_1,(uint)(local_414 != 0));
        return 0;
      }
      break;
    case 0x398:
    case 0x39e:
      if (param_2 == 0) {
        cVar3 = events_getScoreTrailFlag(param_1);
        if (cVar3 == -2) {
          local_41c = 0x39b;
        }
        else {
          if (cVar3 != -3) goto LAB_68013b45;
          local_41c = 0x39c;
        }
        iVar8 = props_storeObjectRef(param_1,local_41c,param_4);
        if (iVar8 == 0) goto LAB_680141c2;
      }
      else {
        iVar8 = props_coerceAndReturnFloat(param_1,param_4,&local_41c);
        if (iVar8 == 0) {
          if (local_41c == 0x39b) {
            (*(unsigned int *)((char *)&local_10 + 4)) = (int *)CONCAT31((*(unsigned int *)((char *)&local_10 + 5)),0xfe);
            events_setScoreTrailFlag(param_1,0xfe);
            return 0;
          }
          if (local_41c == 0x39c) {
            (*(unsigned int *)((char *)&local_10 + 4)) = (int *)CONCAT31((*(unsigned int *)((char *)&local_10 + 5)),0xfd);
            events_setScoreTrailFlag(param_1,0xfd);
            return 0;
          }
        }
      }
LAB_68013b45:
      props_setErrorAndReturn(param_1,0x13);
      return 0;
    case 0x399:
    case 0x39f:
      if (param_2 == 0) {
        bVar2 = events_getScoreMovableFlag(param_1);
        local_41c = (uint)bVar2;
        if (local_41c != 0xfc) {
          if (local_41c < 0x65) {
            param_4[1] = local_41c;
            return 0;
          }
          goto LAB_68013bb7;
        }
        iVar8 = props_storeObjectRef(param_1,0x7e,param_4);
      }
      else {
        iVar8 = props_coerceAndReturnInt(param_1,param_4,(int *)&local_41c);
        if (iVar8 != 0) goto LAB_68013bb7;
        iVar9 = props_requireInt(param_1,(int *)param_4,(int *)&local_41c);
        iVar8 = 0;
        if (iVar9 == 0) {
          iVar8 = -0x7ffbf828;
        }
        if (100 < local_41c) goto LAB_68013bb7;
        events_setScoreMovableFlag(param_1,(char)local_41c);
      }
      if (iVar8 != 0) {
LAB_68013bb7:
        props_setErrorAndReturn(param_1,0x13);
        return 0;
      }
      goto LAB_680141c2;
    case 0x3b5:
switchD_680136ad_caseD_3b5:
      if (param_2 == 0) {
        events_formatScoreVersion(param_1,(undefined1 *)&local_10);
        props_loadStringValue(param_1,(char *)((int)&local_10 + 1),param_4);
        return 0;
      }
      goto LAB_68014193;
    case 0x3b6:
      if (param_2 == 0) {
        uVar5 = events_getScoreAnnotation(param_1);
        param_4[1] = uVar5;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        events_setScoreAnnotation(param_1,(uint)(local_414 != 0));
        return 0;
      }
      break;
    case 0x3c3:
      if (param_2 == 0) {
        events_syncChannelState(param_1,param_4,0);
        return 0;
      }
      goto LAB_68014193;
    case 0x3c4:
      if (param_2 == 0) {
        uVar5 = events_getScoreColorValue(param_1);
        param_4[1] = uVar5;
        return 0;
      }
      iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
      if (iVar8 != 0) {
        events_setScoreColorValue(param_1,(uint)(local_414 != 0));
        return 0;
      }
    }
    goto LAB_6801419e;
  }
  if (param_3 == 0x34d) {
    if (param_2 == 0) {
      bVar2 = events_getScoreFlag(param_1);
      param_4[1] = ((int)(char)~bVar2 & 0x10U) >> 4;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      bVar2 = events_getScoreFlag(param_1);
      if (local_414 != 0) {
        events_setScoreFlag(param_1,bVar2 & 0xef);
        return 0;
      }
      events_setScoreFlag(param_1,bVar2 | 0x10);
      return 0;
    }
    goto LAB_6801419e;
  }
  switch(param_3) {
  case 0x201:
    if (param_2 == 0) {
      iVar8 = events_getFrameLabel(param_1,local_410);
      if (iVar8 != 0) {
        props_readPascalString(param_1,local_410,param_4);
        return 0;
      }
      goto LAB_680141c2;
    }
    if ((*param_4 == 4) && (param_4[1] == 0)) {
      events_setFrameLabel(param_1,(byte *)0x0);
      return 0;
    }
    iVar8 = props_validateString(param_1,(int *)param_4);
    if (iVar8 == 0) goto LAB_6801419e;
    props_toPascalString((int *)param_4,local_410);
    iVar8 = events_setFrameLabel(param_1,local_410);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  case 0x202:
    if (param_2 == 0) {
      events_getScriptRef(param_1,&local_418);
      uVar5 = sprites_getPropertyId(param_1,local_418);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 == 0) goto LAB_6801419e;
    local_418 = sprites_dispatchProperty(param_1,local_414);
    iVar8 = events_setScriptRef(param_1,&local_418);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  case 0x203:
    if (param_2 == 0) {
      uVar5 = events_getTransitionRef(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 == 0) goto LAB_6801419e;
    iVar8 = events_setTransitionRef(param_1,(short)local_414);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  case 0x204:
    if (param_2 == 0) {
      events_getScoreChannelRef(param_1,&local_418);
      uVar5 = sprites_getPropertyId(param_1,local_418);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 == 0) goto LAB_6801419e;
    local_418 = sprites_dispatchProperty(param_1,local_414);
    iVar8 = events_setScoreChannelRef(param_1,&local_418);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  default:
    goto switchD_680127c7_caseD_121;
  case 0x20a:
switchD_68012b19_caseD_20a:
    if (param_2 == 0) {
      bVar1 = cast_isContextValid(param_1);
      param_4[1] = CONCAT31(extraout_var_01,bVar1);
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      props_setTraceMode(param_1,local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x20c:
    if (param_2 == 0) {
      uVar5 = events_enterScriptContext(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setScriptProperty(param_1,(uint)(local_414 != 0));
      return 0;
    }
    goto LAB_6801419e;
  case 0x20d:
    if (param_2 == 0) {
      uVar5 = events_resolveScriptRef(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      crt_applyScriptMode();
      return 0;
    }
    goto LAB_6801419e;
  case 0x210:
    if (param_2 == 0) {
      if (*(int *)(*(int *)(param_1 + 8) + 0x14) == 0) {
        piVar7 = core_createSpriteProps(param_1);
        *(int **)(*(int *)(param_1 + 8) + 0x14) = piVar7;
      }
      piVar7 = (int *)(**(int **)(*(int *)(param_1 + 8) + 0x14) + 4);
      *piVar7 = *piVar7 + 1;
      *param_4 = 3;
      param_4[1] = *(uint *)(*(int *)(param_1 + 8) + 0x14);
      return 0;
    }
    break;
  case 0x22a:
switchD_68012b19_caseD_22a:
    if (param_2 == 0) {
      events_initMoviePlayback(param_1,(undefined2 *)local_410);
      props_readPascalString(param_1,local_410,param_4);
      return 0;
    }
    break;
  case 0x22b:
switchD_68012b19_caseD_22b:
    if (param_2 == 0) {
      events_restoreMovieState(param_1,local_410);
      props_readPascalString(param_1,local_410,param_4);
      return 0;
    }
    break;
  case 0x22d:
    if (param_2 == 0) {
      crt_getScriptInstance(param_1,param_4);
      return 0;
    }
    break;
  case 0x22e:
    if (param_2 == 0) {
      uVar5 = sprites_dispatchMemberType();
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      sprites_dispatchColorOp(param_1,local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x22f:
    if (param_2 == 0) {
      sprites_dispatchPropertyRouter(param_1,local_410);
      props_readPascalString(param_1,local_410,param_4);
      return 0;
    }
    iVar8 = props_validateString(param_1,(int *)param_4);
    if (iVar8 != 0) {
      props_toPascalString((int *)param_4,local_410);
      sprites_dispatchPropertyByIndex(param_1,(char *)local_410);
      return 0;
    }
    goto LAB_6801419e;
  case 0x23a:
switchD_68012b19_caseD_23a:
    if (param_2 == 0) {
      uVar5 = events_getChannelBounds(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    break;
  case 0x23b:
switchD_68012b19_caseD_23b:
    if (param_2 == 0) {
      uVar5 = events_setChannelBounds(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    break;
  case 0x23d:
    if (param_2 != 0) {
      iVar8 = props_setRectField(param_1,(int *)param_4);
      if (iVar8 != 0) {
        events_setContextRef(param_1,(int *)param_4[1]);
        return 0;
      }
LAB_68012b9f:
      props_setErrorAndReturn(param_1,0xd);
      return 0;
    }
    uVar5 = events_getOrCreateContextRef(param_1);
    param_4[1] = uVar5;
    if (uVar5 != 0) {
      *param_4 = 3;
      props_retainValue(param_1,param_4);
      return 0;
    }
    goto LAB_680141c2;
  case 0x262:
    if (param_2 == 0) {
      uVar5 = events_getMediaStreamRef();
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setMediaStreamRef(param_1,local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x263:
    if (param_2 == 0) {
      uVar5 = events_getMediaStreamOffset();
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setMediaStreamOffset(param_1,local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x264:
    if (param_2 == 0) {
      uVar5 = events_getScorePropertyState();
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setScorePropertyState(param_1,(short)local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x265:
    if (param_2 == 0) {
      uVar5 = events_resetStageMonitor();
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setStageOverlay(param_1,local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x266:
    if (param_2 == 0) {
      uVar5 = events_getIdleTimeout(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setIdleTimeout(param_1,local_414);
      return 0;
    }
    goto LAB_6801419e;
  case 0x285:
    if (param_2 == 0) {
      piVar7 = (int *)events_getScoreSoundRef(param_1);
      param_4[1] = (uint)piVar7;
      if (piVar7 != (int *)0x0) {
        score_getMediaRef(param_1,piVar7);
        *param_4 = 3;
        return 0;
      }
      goto LAB_680141c2;
    }
    bVar1 = score_isMediaValid(param_1,(int *)param_4,(int *)((int)&local_10 + 4));
    if (CONCAT31(extraout_var,bVar1) != 0) {
      events_setScoreSoundRef(param_1,(*(unsigned int *)((char *)&local_10 + 4)));
      return 0;
    }
    break;
  case 0x291:
    if (param_2 == 0) {
      core_getObjectRefById(param_1,(uint *)&local_10);
      *(int *)(*(int *)(size_t)(*(unsigned int *)((char *)&local_10 + 4)) + 4) = *(int *)(*(int *)(size_t)(*(unsigned int *)((char *)&local_10 + 4)) + 4) + 1;
      cast_createWithDimensions(param_1,(*(unsigned int *)((char *)&local_10 + 4)),*(undefined4 *)(*(int *)(size_t)(*(unsigned int *)((char *)&local_10 + 4)) + 8));
      return 0;
    }
    break;
  case 0x29f:
    if (param_2 == 0) {
      uVar5 = events_getScoreInkType(param_1);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setScoreInkType(param_1,(uint)(local_414 != 0));
      return 0;
    }
    goto LAB_6801419e;
  case 0x2a0:
    if (param_2 == 0) {
      bVar1 = events_isChannelMutable(param_1);
      param_4[1] = CONCAT31(extraout_var_00,bVar1);
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 != 0) {
      events_setChannelMutability(param_1,(uint)(local_414 != 0));
      return 0;
    }
    goto LAB_6801419e;
  case 0x2a1:
    if (param_2 == 0) {
      events_getScoreMemberRef(param_1,&local_418);
      uVar5 = sprites_getPropertyId(param_1,local_418);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 == 0) goto LAB_6801419e;
    local_418 = sprites_dispatchProperty(param_1,local_414);
    iVar8 = events_setScoreMemberRef(param_1,&local_418);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  case 0x2a2:
    if (param_2 == 0) {
      events_getScoreColorRef(param_1,1,&local_418);
      uVar5 = sprites_getPropertyId(param_1,local_418);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 == 0) goto LAB_6801419e;
    local_418 = sprites_dispatchProperty(param_1,local_414);
    iVar8 = events_setScoreColorRef(param_1,1,&local_418);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  case 0x2a3:
    if (param_2 == 0) {
      events_getScoreColorRef(param_1,2,&local_418);
      uVar5 = sprites_getPropertyId(param_1,local_418);
      param_4[1] = uVar5;
      return 0;
    }
    iVar8 = props_requireInt(param_1,(int *)param_4,&local_414);
    if (iVar8 == 0) goto LAB_6801419e;
    local_418 = sprites_dispatchProperty(param_1,local_414);
    iVar8 = events_setScoreColorRef(param_1,2,&local_418);
    if (iVar8 != 0) {
      return 0;
    }
    break;
  case 0x2d7:
    if (param_2 != 0) {
      sprites_setLastError(param_1,param_4);
      return 0;
    }
    sprites_getLastError(param_1,param_4);
    return 0;
  case 0x2e4:
    if (param_2 == 0) {
      sVar4 = sprites_getMemberType(param_1);
      param_4[1] = (int)sVar4;
      return 0;
    }
  }
LAB_68014193:
  props_reportError(param_1,0x39);
LAB_6801419e:
  return 0;
}



// ============================================================
// Function: core_accessGlobalAll (FUN_680145b0)
// Address: 680145b0
// Size: 590 bytes
// Params: uint param_1, uint param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessGlobalAll(uint param_1,uint param_2,int param_3,uint *param_4)
{
  int iVar1;
  uint uVar2;
  int local_40c;
  byte local_408 [1024];
  
  iVar1 = core_accessGlobalExtended(param_1,param_2,param_3,param_4);
  if (((((iVar1 != 0) || (iVar1 = core_accessGlobalProperty(param_1,param_2,param_3,param_4), iVar1 != 0)) ||
       (iVar1 = crt_dispatchAppCommand(param_1,param_2,param_3,param_4), iVar1 != 0)) ||
      ((iVar1 = crt_dispatchMovieProperty(param_1,param_2,param_3,param_4), iVar1 != 0 ||
       (iVar1 = crt_dispatchWindowProperty(param_1,param_2,param_3,param_4), iVar1 != 0)))) ||
     ((iVar1 = core_accessGlobalMisc(param_1,param_2,param_3,param_4), iVar1 != 0 ||
      ((iVar1 = crt_getTimerProperty(param_1,param_2,param_3,param_4), iVar1 != 0 ||
       (iVar1 = crt_getTimerProperty(param_1,param_2,param_3,param_4), iVar1 != 0)))))) goto LAB_680147e9;
  if (param_3 < 0x2de) {
    if (param_3 == 0x2dd) {
      if (param_2 == 0) {
        sprites_getSystemPath(param_1,local_408,0);
        props_readPascalString(param_1,local_408,param_4);
        goto LAB_680147e9;
      }
    }
    else {
      if (param_3 == 0x232) {
        if (param_2 == 0) {
          uVar2 = Ordinal_1969();
          param_4[1] = uVar2;
        }
        else {
          iVar1 = props_requireInt(param_1,(int *)param_4,&local_40c);
          if (iVar1 != 0) {
            Ordinal_1968(local_40c);
          }
        }
        goto LAB_680147e9;
      }
      if (param_3 == 0x245) {
        if (param_2 == 0) {
          uVar2 = sprites_getMediaPlayerVersion();
          param_4[1] = uVar2;
        }
        else {
          iVar1 = props_requireInt(param_1,(int *)param_4,&local_40c);
          if (iVar1 != 0) {
            sprites_getQuickTimeVersion(param_1,local_40c);
          }
        }
        goto LAB_680147e9;
      }
      if (param_3 != 0x2db) goto LAB_68014796;
      if (param_2 == 0) {
        sprites_getTextMemberRef(param_1,local_408);
        props_readPascalString(param_1,local_408,param_4);
        goto LAB_680147e9;
      }
    }
  }
  else {
    if (param_3 == 0x35a) {
      if (param_2 == 0) {
        iVar1 = events_setMiawXtraRef(param_1,param_4);
      }
      else {
        iVar1 = events_getMiawXtraRef(param_1,param_4);
      }
      if (iVar1 != 0) {
        props_setErrorAndReturn(param_1,0x69);
      }
      goto LAB_680147e9;
    }
    if (param_3 != 0x381) {
LAB_68014796:
      props_reportError(param_1,0x37);
      goto LAB_680147e9;
    }
    if (param_2 == 0) {
      core_getExtPairOrEmpty();
      goto LAB_680147e9;
    }
  }
  props_reportError(param_1,0x39);
LAB_680147e9:
  return 0;
}


