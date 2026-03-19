// Module: crt
// Topic: Lingo script properties, sprite commands, behaviors, script objects, media handlers
// Address range: 0x6800D090 - 0x6800FB20
// Functions (45):
//   crt_applyScriptMode - crt_getTimerProperty (sprite method dispatch, linked list, property get/set)
//   crt_dispatchMovieProperty - crt_extractChannelRef (global/movie properties, format dispatch, channel ref)
//   crt_setScriptPropertyEx - crt_resolveSoundArg (channel object create, sound commands, member ref)
//   crt_releaseBehaviorRefs - crt_createBehavior (behavior release, script object delete, behavior find)
//   crt_findOrCreateBehavior - crt_buildEnvironmentInfo (behavior create, script list, property list, environment info)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800d550 - 0x6800d990
// Functions (9):
//   crt_getScriptPropertyEx
//   crt_getScriptProperty
//   crt_applyScriptMode
//   crt_getScriptObjectValue
//   crt_getScriptObjectType
//   crt_setScriptProperty
//   crt_ensurePropertyList
//   crt_dispatchAppCommand
//   crt_getTimerProperty

// ============================================================
// Function: crt_getScriptPropertyEx (FUN_6800d550)
// Address: 6800d550
// Size: 104 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getScriptPropertyEx(int param_1,int *param_2)
{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
    *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
    iVar1 = **(int **)(param_1 + 8);
    *(undefined4 *)(*param_2 + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x564) + 8);
    *(undefined4 *)(*param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x564);
    *(int **)(**(int **)(**(int **)(iVar1 + 0x564) + 8) + 0xc) = param_2;
    *(int **)(**(int **)(iVar1 + 0x564) + 8) = param_2;
  }
  return 0;
}



// ============================================================
// Function: crt_getScriptProperty (FUN_6800d5c0)
// Address: 6800d5c0
// Size: 104 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getScriptProperty(int param_1,int *param_2)
{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
    *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
    iVar1 = **(int **)(param_1 + 8);
    *(undefined4 *)(*param_2 + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x55c) + 8);
    *(undefined4 *)(*param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x55c);
    *(int **)(**(int **)(**(int **)(iVar1 + 0x55c) + 8) + 0xc) = param_2;
    *(int **)(**(int **)(iVar1 + 0x55c) + 8) = param_2;
  }
  return 0;
}



// ============================================================
// Function: crt_applyScriptMode (FUN_6800d630)
// Address: 6800d630
// Size: 73 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_applyScriptMode(void)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  int iVar2;
  
  events_setScriptMode(unaff_ESI,unaff_EDI);
  iVar1 = **(int **)(unaff_ESI + 0x2c);
  *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) | 1;
  if (unaff_EDI == 0) {
    *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xffffffbf;
    iVar2 = *(int *)(iVar1 + 0x28);
    if ((iVar2 != -1) && (*(int *)(iVar1 + 0x24) != 0)) {
      *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
      iVar1 = events_setEditProperty(unaff_ESI,*(int *)(iVar1 + 0x24));
      crt_mergeChunks(iVar1,iVar2);
      return 0;
    }
  }
  else {
    *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) | 0x40;
  }
  return 0;
}



// ============================================================
// Function: crt_getScriptObjectValue (FUN_6800d680)
// Address: 6800d680
// Size: 36 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crt_getScriptObjectValue(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) &&
      (piVar1 = *(int **)(*(int *)(param_1 + 8) + 4), piVar1 != (int *)0x0)) &&
     ((iVar2 = *piVar1, iVar2 != 0 &&
      (puVar3 = *(undefined4 **)(iVar2 + 4), puVar3 != (undefined4 *)0x0)))) {
    uVar4 = *puVar3;
  }
  return uVar4;
}



// ============================================================
// Function: crt_getScriptObjectType (FUN_6800d6b0)
// Address: 6800d6b0
// Size: 30 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crt_getScriptObjectType(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) &&
      (piVar1 = *(int **)(*(int *)(param_1 + 8) + 4), piVar1 != (int *)0x0)) &&
     (iVar2 = *piVar1, iVar2 != 0)) {
    uVar3 = *(undefined4 *)(iVar2 + 8);
  }
  return uVar3;
}



// ============================================================
// Function: crt_setScriptProperty (FUN_6800d6d0)
// Address: 6800d6d0
// Size: 98 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setScriptProperty(int param_1,int *param_2)
{
  int iVar1;
  uint local_c;
  undefined4 local_8;
  
  local_c = 3;
  local_8 = *(undefined4 *)(**(int **)(param_1 + 8) + 0x518);
  iVar1 = props_getListRange(param_1,param_2,(int *)&local_c);
  if (*(int *)(param_1 + 0xe0) == 0) {
    if (-1 < iVar1) {
      props_setListRange(param_1,param_2,iVar1);
    }
  }
  else if (iVar1 < 0) {
    props_setListEntry(param_1,param_2,&local_c);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: crt_ensurePropertyList (FUN_6800d740)
// Address: 6800d740
// Size: 97 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_ensurePropertyList(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(**(int **)(unaff_ESI + 8) + 0x510) == 0) {
    uVar1 = props_getRectCount(unaff_ESI);
    *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x510) = uVar1;
    crt_getScriptProperty(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x510));
    props_setListSortVtable(unaff_ESI,*(undefined4 **)(**(int **)(unaff_ESI + 8) + 0x510));
  }
  crt_setScriptProperty(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x510));
  return *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x510);
}



// ============================================================
// Function: crt_dispatchAppCommand (FUN_6800d7b0)
// Address: 6800d7b0
// Size: 415 bytes
// Params: uint param_1, int param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchAppCommand(uint param_1,int param_2,undefined4 param_3,uint *param_4)
{
  int iVar1;
  undefined4 uVar2;
  char local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  uint local_8;
  
  switch(param_3) {
  case 0x1a3:
    if (param_2 == 0) {
      iVar1 = sprites_restartApp();
      param_4[1] = (uint)(iVar1 != 0);
      return 0;
    }
    break;
  case 0x1a4:
    if (param_2 == 0) {
      iVar1 = sprites_haltApp();
      param_4[1] = (uint)(iVar1 != 0);
      return 0;
    }
    break;
  default:
    return 0;
  case 0x1a6:
    if (param_2 == 0) {
      iVar1 = sprites_quitApp();
      param_4[1] = (uint)(iVar1 != 0);
      return 0;
    }
    break;
  case 0x1a7:
    if (param_2 == 0) {
      iVar1 = sprites_shutdownApp();
      param_4[1] = (uint)(iVar1 != 0);
      return 0;
    }
    break;
  case 0x1a9:
    if (param_2 == 0) {
      uVar2 = crt_getMiawProperty(param_1,0xd);
      local_10 = (char)uVar2;
      local_d = (undefined1)((uint)uVar2 >> 0x18);
      local_f = (undefined1)((uint)uVar2 >> 8);
      local_e = (undefined1)((uint)uVar2 >> 0x10);
      local_c = 0;
      props_loadCString(param_1,&local_10,param_4);
      return 0;
    }
    break;
  case 0x1bc:
    if (param_2 == 0) {
      events_setWindowProperty(param_1,0x10,0,param_4);
      return 0;
    }
  }
  props_reportError(param_1,0x39);
  return 0;
}



// ============================================================
// Function: crt_getTimerProperty (FUN_6800d990)
// Address: 6800d990
// Size: 149 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getTimerProperty(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  double local_c;
  
  if ((param_3 == 0x3d2) || (param_3 == 0x3d3)) {
    if (param_2 != 0) {
LAB_6800d9dd:
      props_reportError(param_1,0x39);
      return 1;
    }
    sprites_clearEventContext();
  }
  else {
    if (param_3 != 0x3d4) {
      return 0;
    }
    if (param_2 != 0) goto LAB_6800d9dd;
    sprites_clearEventContext();
  }
  props_storeNumber(param_1,local_c,param_4);
  return 1;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800da30 - 0x6800e380
// Functions (8):
//   crt_dispatchMovieProperty
//   crt_dispatchWindowProperty
//   crt_formatChannelError
//   crt_accessChannelProperty
//   crt_saveChannelContext
//   crt_restoreChannelContext
//   crt_invokeHandler
//   crt_extractChannelRef

// ============================================================
// Function: crt_dispatchMovieProperty (FUN_6800da30)
// Address: 6800da30
// Size: 901 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_dispatchMovieProperty(uint param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_c;
  uint local_8;
  
  if (param_3 < 0x1b0) {
    if (param_3 == 0x1af) {
      if (param_2 == 0) {
        sprites_getEventData(param_1,&local_c);
        param_4[1] = local_8;
        return 1;
      }
    }
    else if (param_3 < 0x7a) {
      if (param_3 == 0x79) {
        if (param_2 == 0) {
          iVar1 = cast_waitForAlert();
          param_4[1] = (uint)(iVar1 == 0);
          return 1;
        }
      }
      else if (param_3 == 0x39) {
        if (param_2 == 0) {
          iVar1 = cast_waitForSync();
          param_4[1] = (uint)(iVar1 == 0);
          return 1;
        }
      }
      else if (param_3 == 0x3a) {
        if (param_2 == 0) {
          iVar1 = cast_waitForSync();
          param_4[1] = (uint)(iVar1 != 0);
          return 1;
        }
      }
      else {
        if (param_3 != 0x78) {
          return 0;
        }
        if (param_2 == 0) {
          iVar1 = cast_waitForAlert();
          param_4[1] = (uint)(iVar1 != 0);
          return 1;
        }
      }
    }
    else if (param_3 == 0x99) {
      if (param_2 == 0) {
        events_setMiawSoundRef(param_1,&local_c);
        goto LAB_6800dd9b;
      }
    }
    else if (param_3 == 0x1a5) {
      if (param_2 == 0) {
        iVar1 = cast_waitForSync();
        param_4[1] = (uint)(iVar1 != 0);
        return 1;
      }
    }
    else {
      if (param_3 != 0x1a8) {
        return 0;
      }
      if (param_2 == 0) {
        uVar2 = events_getMiawSoundRef(param_1);
        param_4[1] = uVar2;
        return 1;
      }
    }
  }
  else if (param_3 < 0x1b6) {
    if (param_3 == 0x1b5) {
      if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0xb4) = 3;
        uVar2 = core_invokeBuiltin(param_1);
        param_4[1] = uVar2;
        return 1;
      }
    }
    else {
      if (param_3 != 0x1b0) {
        return 0;
      }
      if (param_2 == 0) {
        sprites_getEventData(param_1,&local_c);
        param_4[1] = local_c;
        return 1;
      }
    }
  }
  else {
    if (0x338 < param_3) {
      if (param_3 == 0x35b) {
        local_c = 0;
        local_8 = 0;
        if (param_2 != 0) {
          props_getRectField(param_1,(int *)param_4);
          sprites_setEventData(param_1,&local_c);
          return 1;
        }
        sprites_getEventData(param_1,&local_c);
LAB_6800dd9b:
        props_transformRect(param_1,&local_c,param_4);
        return 1;
      }
switchD_6800dc43_caseD_1b9:
      return 0;
    }
    if (param_3 == 0x338) {
      if (param_2 == 0) {
        sprites_findMemberByName(param_1,&param_2,(int *)0x0);
        *param_4 = 2;
        if ((*(unsigned short *)((char *)&param_2 + 2)) == 0) {
          return 1;
        }
        core_getFieldValue(param_1,&param_2,param_4);
        return 1;
      }
    }
    else {
      switch(param_3) {
      case 0x1b6:
        if (param_2 == 0) {
          *(undefined4 *)(param_1 + 0xb4) = 2;
          uVar2 = core_invokeBuiltin(param_1);
          param_4[1] = uVar2;
          return 1;
        }
        break;
      case 0x1b7:
        if (param_2 == 0) {
          *(undefined4 *)(param_1 + 0xb4) = 1;
          uVar2 = core_invokeBuiltin(param_1);
          param_4[1] = uVar2;
          return 1;
        }
        break;
      case 0x1b8:
        if (param_2 == 0) {
          *(undefined4 *)(param_1 + 0xb4) = 0;
          uVar2 = core_invokeBuiltin(param_1);
          param_4[1] = uVar2;
          return 1;
        }
        break;
      default:
        goto switchD_6800dc43_caseD_1b9;
      case 0x1bb:
        if (param_2 == 0) {
          events_setMiawActiveFlag(param_1,0xc,param_4);
          return 1;
        }
      }
    }
  }
  props_reportError(param_1,0x39);
  return 1;
}



// ============================================================
// Function: crt_dispatchWindowProperty (FUN_6800ddd0)
// Address: 6800ddd0
// Size: 337 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_dispatchWindowProperty(uint param_1,int param_2,int param_3,uint *param_4)
{
  uint uVar1;
  int iVar2;
  byte local_808 [1024];
  undefined1 local_408 [1024];
  uint local_8;
  
  if (param_3 < 0x361) {
    if (param_3 == 0x360) {
      if (param_2 == 0) {
        uVar1 = stage_enumerateScoreHandlers(param_1);
        param_4[1] = uVar1;
        if (uVar1 != 0) {
          *param_4 = 3;
        }
      }
      else {
        props_reportError(param_1,0x39);
      }
    }
    else if (param_3 == 0x18b) {
      events_setWindowProperty(param_1,0x19,param_2,param_4);
    }
    else if (param_3 == 0x1ed) {
      events_setWindowProperty(param_1,0x1a,param_2,param_4);
    }
    else {
      if (param_3 != 0x33e) goto LAB_6800de86;
      events_setWindowProperty(param_1,0x27,param_2,param_4);
    }
  }
  else if (param_3 == 0x361) {
    if (param_2 == 0) {
      iVar2 = stage_getScoreFileName(param_1,local_808);
      if (iVar2 != 0) {
        props_readPascalString(param_1,local_808,param_4);
      }
    }
    else if ((*param_4 == 4) && (param_4[1] == 0)) {
      stage_setTitleString(param_1,0);
    }
    else {
      iVar2 = props_validateString(param_1,(int *)param_4);
      if (iVar2 != 0) {
        props_toPascalString((int *)param_4,local_408);
        stage_setTitleString(param_1,(int)local_408);
      }
    }
  }
  else {
    if (param_3 != 900) {
LAB_6800de86:
      return 0;
    }
    events_setWindowProperty(param_1,0x28,param_2,param_4);
  }
  return 0;
}



// ============================================================
// Function: crt_formatChannelError (FUN_6800df30)
// Address: 6800df30
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_formatChannelError(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x31);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: crt_accessChannelProperty (FUN_6800df70)
// Address: 6800df70
// Size: 922 bytes
// Params: double * param_1, int * param_2, uint param_3, uint param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_accessChannelProperty(double *param_1,int *param_2,uint param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(uint *)(*param_2 + 8);
  if ((int)param_4 < 0x1f6) {
    if (param_4 == 0x1f5) {
      core_accessChannelRect((int)param_1,uVar1,param_3,(int *)param_5);
      return 1;
    }
    if ((int)param_4 < 0x104) {
      if (param_4 == 0x103) {
        core_accessChannelName((int)param_1,uVar1,param_3,(int *)param_5);
        return 1;
      }
      if (param_4 == 0x58) {
        core_accessChannelMember((uint)param_1,uVar1,param_3,(int *)param_5);
        return 1;
      }
      if (param_4 == 0xbc) {
        core_accessChannelWindow((int)param_1,uVar1,param_3,(int *)param_5);
        return 1;
      }
    }
    else if (param_4 == 0x166) {
      core_accessChannelColor((int)param_1,uVar1,param_3,(int *)param_5);
      return 1;
    }
  }
  else if ((int)param_4 < 0x63c) {
    if (param_4 == 0x63b) {
      if (param_3 == 0) {
        core_getChannelBounds((int)param_1,uVar1,0,param_5);
        return 1;
      }
      goto LAB_6800e2da;
    }
    if (param_4 == 0x314) {
      core_accessChannelScript((int)param_1,uVar1,param_3,param_5);
      return 1;
    }
    if (param_4 == 0x319) {
      if (param_3 == 0) {
        param_5[1] = uVar1;
        return 1;
      }
      goto LAB_6800e2da;
    }
  }
  else if (param_4 == 0x63e) {
    if (param_3 == 0) {
      core_computeRectOp((int)param_1,uVar1,param_5);
      return 1;
    }
    goto LAB_6800e2da;
  }
  iVar2 = sprites_resolveChannelProperty(param_1,uVar1,param_3,param_4,param_5);
  if (iVar2 == 0) {
    return 1;
  }
  if (iVar2 == -0x7ffbf82b) {
    if ((int)param_4 < 0x1e9) {
      if (param_4 == 0x1e8) {
        iVar2 = events_getWindowProperty((int)param_1,uVar1);
        if (iVar2 == 0) {
          return 0;
        }
        core_accessChannelBounds((int)param_1,(short)uVar1,param_3,0xf,(int *)param_5);
        return 1;
      }
      if (param_4 != 0x15f) {
        return 0;
      }
    }
    else {
      if ((int)param_4 < 0x325) {
        if (param_4 == 0x324) {
          iVar2 = events_getWindowProperty((int)param_1,uVar1);
          if (iVar2 == 0) {
            return 0;
          }
          sprites_getChannelBounds((int)param_1,uVar1,param_3,0x28,param_5 + 1);
          return 1;
        }
        if (param_4 == 0x1e9) {
          iVar2 = events_getWindowProperty((int)param_1,uVar1);
          if (iVar2 == 0) {
            return 0;
          }
          sprites_getChannelBounds((int)param_1,uVar1,param_3,0x10,param_5 + 1);
          return 1;
        }
        if (param_4 == 0x1ea) {
          iVar2 = events_getWindowProperty((int)param_1,uVar1);
          if (iVar2 == 0) {
            return 0;
          }
          sprites_getChannelBounds((int)param_1,uVar1,param_3,0x14,param_5 + 1);
          return 1;
        }
        if (param_4 != 0x1eb) {
          return 0;
        }
        iVar2 = events_getWindowProperty((int)param_1,uVar1);
        if (iVar2 != 0) {
          sprites_getChannelBounds((int)param_1,uVar1,param_3,0x15,param_5 + 1);
          return 1;
        }
LAB_6800e259:
        iVar2 = events_getWindowProperty((int)param_1,uVar1);
        if (iVar2 == 0) {
          return 0;
        }
        sprites_getChannelBounds((int)param_1,uVar1,param_3,0x27,param_5 + 1);
        return 1;
      }
      if (param_4 == 0x325) goto LAB_6800e259;
      if (param_4 != 0x602) {
        return 0;
      }
    }
    if (param_3 == 0) {
      core_wrapMember((int)param_1,param_2,*(int **)(**(int **)(param_1 + 1) + 0x5b0),param_5);
      return 1;
    }
  }
  else if (iVar2 != -0x7ffbf82a) {
    uVar3 = props_translateError(iVar2);
    if ((short)uVar3 == 0x61) {
      props_reportError((int)param_1,0x61);
      return 1;
    }
    props_reportError((int)param_1,(int)(short)uVar3);
    return 1;
  }
LAB_6800e2da:
  props_reportError((int)param_1,0x39);
  return 1;
}



// ============================================================
// Function: crt_saveChannelContext (FUN_6800e310)
// Address: 6800e310
// Size: 25 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_saveChannelContext(int param_1,int *param_2)
{
  sprites_saveChannelContext(param_1,*(int *)(*param_2 + 8));
  return 0;
}



// ============================================================
// Function: crt_restoreChannelContext (FUN_6800e330)
// Address: 6800e330
// Size: 29 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_restoreChannelContext(int param_1,int *param_2,int *param_3)
{
  sprites_restoreChannelContext(param_1,*(undefined4 *)(*param_2 + 8),param_3);
  return 0;
}



// ============================================================
// Function: crt_invokeHandler (FUN_6800e350)
// Address: 6800e350
// Size: 20 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_invokeHandler(int param_1,undefined4 param_2,uint param_3)
{
  props_callHandler(param_1,param_3);
  return 0;
}



// ============================================================
// Function: crt_extractChannelRef (FUN_6800e380)
// Address: 6800e380
// Size: 49 bytes
// Params: undefined4 param_1, int * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_extractChannelRef(undefined4 param_1,int *param_2,undefined2 *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_68189560)) {
    *param_3 = (short)(*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800e3c0 - 0x6800eb60
// Functions (11):
//   crt_setScriptPropertyEx
//   crt_createDefaultChannelRef
//   crt_resolveChannelArg
//   crt_setScoreChannelRate
//   crt_dispatchScoreCommand
//   crt_formatSoundError
//   crt_getChannelIndex
//   crt_accessScoreProperty
//   crt_createSoundRef
//   crt_extractSoundRef
//   crt_resolveSoundArg

// ============================================================
// Function: crt_setScriptPropertyEx (FUN_6800e3c0)
// Address: 6800e3c0
// Size: 64 bytes
// Params: int param_1, short param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setScriptPropertyEx(int param_1,short param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *puVar1 = &PTR_LAB_68189560;
    puVar1[2] = (int)param_2;
    *param_3 = 3;
    param_3[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: crt_createDefaultChannelRef (FUN_6800e400)
// Address: 6800e400
// Size: 64 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_createDefaultChannelRef(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    *puVar1 = &PTR_LAB_68189560;
    puVar1[1] = 1;
    puVar1[2] = 0xffffffff;
    *param_2 = 3;
    param_2[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: crt_resolveChannelArg (FUN_6800e440)
// Address: 6800e440
// Size: 275 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_resolveChannelArg(int param_1)
{
  int iVar1;
  int local_414;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_40c = DAT_6819776c;
  local_410 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_40c = ((int *)(size_t)_DAT_68197764)[1];
    local_410 = *(int *)(size_t)_DAT_68197764;
  }
  if ((local_410 == 0x40) || (local_410 == 0x43)) {
    props_toPascalString(&local_410,local_408);
    local_414 = sprites_processEvent(param_1,(int)local_408,1);
    if (0 < local_414) goto LAB_6800e4cc;
    if (*(int *)(param_1 + 0xe0) == 0) {
      local_414 = 1;
      goto LAB_6800e4cc;
    }
    local_410 = 2;
    local_40c = 0;
  }
  else {
    iVar1 = props_requireInt(param_1,&local_410,&local_414);
    if (iVar1 == 0) goto LAB_6800e4e7;
LAB_6800e4cc:
    crt_setScriptPropertyEx(param_1,(short)local_414,&local_410);
  }
  props_popArgs(param_1,&local_410);
LAB_6800e4e7:
  return 0;
}



// ============================================================
// Function: crt_setScoreChannelRate (FUN_6800e560)
// Address: 6800e560
// Size: 98 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setScoreChannelRate(int param_1,int param_2,int param_3,int param_4)
{
  undefined2 uVar1;
  short extraout_var;
  int iVar2;
  int iVar3;
  
  uVar1 = stage_getScoreChannelType(param_1,param_2);
  iVar3 = CONCAT22(extraout_var,uVar1);
  if (iVar3 == 0 || extraout_var < 0) {
    iVar3 = 1;
  }
  iVar2 = param_3 / iVar3;
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  iVar3 = (iVar2 * iVar3) / param_3;
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  if (param_4 != 0) {
    iVar3 = -iVar3;
  }
  stage_setScoreChannel(param_1,param_2,iVar2,iVar3);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: crt_dispatchScoreCommand (FUN_6800e5d0)
// Address: 6800e5d0
// Size: 674 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_dispatchScoreCommand(uint param_1,int *param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420;
  int local_41c;
  int local_418;
  undefined4 local_414;
  uint local_410;
  undefined4 *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  sVar1 = *(short *)(*param_2 + 8);
  local_414 = 1;
  iVar2 = props_getInt(param_1);
  if (param_3 < 0x177) {
    if (param_3 == 0x176) {
      stage_selectScoreChannel(param_1,(int)sVar1);
      props_popArgs(param_1,(undefined4 *)0x0);
      goto LAB_6800e859;
    }
    switch(param_3) {
    case 0xe3:
      score_resolveType(param_1);
      return 0;
    default:
switchD_6800e630_caseD_e4:
      local_414 = 0;
      break;
    case 0x14e:
      stage_getScoreSelection(param_1,(int)sVar1);
      props_popArgs(param_1,(undefined4 *)0x0);
      break;
    case 0x174:
    case 0x175:
      if (iVar2 == 2) {
        iVar2 = props_getTypedValue(param_1,2,4,&local_410);
        if (iVar2 == 0) break;
      }
      else if (iVar2 == 1) {
        iVar2 = events_getTransitionRef(param_1);
        local_410 = iVar2 * 0xf;
      }
      else {
        props_setError(param_1,0x19);
      }
      if ((int)local_410 < 1) {
        local_410 = 1;
      }
      crt_setScoreChannelRate(param_1,(int)sVar1,local_410,(uint)(param_3 == 0x175));
    }
  }
  else {
    if (param_3 == 0x177) {
      if (iVar2 == 2) {
        iVar2 = props_getTypedValue(param_1,2,1,(uint *)&local_40c);
        if (iVar2 != 0) {
          props_cStringToPascal(local_40c,local_408);
          local_424 = 4;
          local_420 = stage_loadScoreMember(param_1,(int)sVar1);
          props_popArgs(param_1,&local_424);
        }
        goto LAB_6800e859;
      }
    }
    else {
      if (param_3 != 0x327) goto switchD_6800e630_caseD_e4;
      if (iVar2 == 2) {
        _DAT_68197764 =
             (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                    *(int *)(param_1 + 0x18));
        iVar2 = 0;
        local_418 = DAT_6819776c;
        local_41c = DAT_68197768;
        if (_DAT_68197764 != (int *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_418 = ((int *)(size_t)_DAT_68197764)[1];
          local_41c = *(int *)(size_t)_DAT_68197764;
        }
        if ((local_41c == 0x40) || (local_41c == 0x43)) {
          local_40c = props_copyString(&local_41c);
          iVar2 = 1;
        }
        else {
          iVar3 = props_requireInt(param_1,&local_41c,(int *)&local_40c);
          if (iVar3 == 0) goto LAB_6800e859;
        }
        local_428 = stage_setScoreChannelPosition(param_1,-(int)sVar1,local_40c,iVar2);
        local_42c = 4;
        if (iVar2 != 0) {
          props_freeStringCallback(&local_41c,local_40c);
        }
        props_popArgs(param_1,&local_42c);
        goto LAB_6800e859;
      }
    }
    props_setError(param_1,0x19);
  }
LAB_6800e859:
  return 0;
}



// ============================================================
// Function: crt_formatSoundError (FUN_6800e920)
// Address: 6800e920
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_formatSoundError(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x32);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: crt_getChannelIndex (FUN_6800e960)
// Address: 6800e960
// Size: 26 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getChannelIndex(undefined4 param_1,int *param_2,int *param_3)

{
  *param_3 = (int)*(short *)(*param_2 + 8);
  return 1;
}



// ============================================================
// Function: crt_accessScoreProperty (FUN_6800e980)
// Address: 6800e980
// Size: 318 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_accessScoreProperty(int param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_var;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  iVar3 = (int)*(short *)(*param_2 + 8);
  if (param_4 == 0x19f) {
    if (param_3 == 0) {
      *param_5 = 4;
      uVar1 = stage_getScoreChannelType(param_1,iVar3);
      param_5[1] = CONCAT22(extraout_var,uVar1);
    }
    else {
      iVar2 = props_requireInt(param_1,param_5,&local_8);
      if (iVar2 != 0) {
        if (local_8 < 0) {
          stage_setScoreChannelType(param_1,iVar3,0);
          return 1;
        }
        iVar2 = local_8;
        if (0xff < local_8) {
          iVar2 = 0xff;
        }
        stage_setScoreChannelType(param_1,iVar3,iVar2);
        return 1;
      }
    }
    return 1;
  }
  if (param_4 == 0x324) {
    if (param_3 != 0) {
      props_reportError(param_1,0x39);
      return 1;
    }
    *param_5 = 4;
    iVar3 = stage_getScoreChannelScript(param_1,iVar3);
    param_5[1] = iVar3;
    return 1;
  }
  if (param_4 != 0x325) {
    return 0;
  }
  if (param_3 != 0) {
    props_reportError(param_1,0x39);
    return 1;
  }
  *param_5 = 4;
  iVar3 = stage_getScoreChannelName(param_1,iVar3);
  param_5[1] = iVar3;
  return 1;
}



// ============================================================
// Function: crt_createSoundRef (FUN_6800ead0)
// Address: 6800ead0
// Size: 65 bytes
// Params: int param_1, undefined2 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_createSoundRef(int param_1,undefined2 param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0xc,0);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *puVar1 = &PTR_LAB_681895b0;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *param_3 = 3;
    param_3[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: crt_extractSoundRef (FUN_6800eb20)
// Address: 6800eb20
// Size: 49 bytes
// Params: undefined4 param_1, int * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_extractSoundRef(undefined4 param_1,int *param_2,undefined2 *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_681895b0)) {
    *param_3 = (short)(*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}



// ============================================================
// Function: crt_resolveSoundArg (FUN_6800eb60)
// Address: 6800eb60
// Size: 124 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_resolveSoundArg(int param_1)
{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  iVar1 = param_1;
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  iVar2 = props_requireInt(param_1,&local_c,&param_1);
  if (iVar2 != 0) {
    crt_createSoundRef(iVar1,(short)param_1,&local_c);
    props_popArgs(iVar1,&local_c);
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800ebe0 - 0x6800f1a0
// Functions (12):
//   crt_releaseBehaviorRefs
//   crt_releaseScriptObjects
//   crt_deleteBehaviorEntry
//   crt_removeBehavior
//   crt_destroyScriptObject
//   crt_formatBehaviorError
//   crt_findBehaviorIndex
//   crt_switchMovieContext
//   crt_restoreMovieContext
//   crt_isBehaviorObject
//   crt_findBehaviorByName
//   crt_createBehavior

// ============================================================
// Function: crt_releaseBehaviorRefs (FUN_6800ebe0)
// Address: 6800ebe0
// Size: 167 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_releaseBehaviorRefs(int param_1,int *param_2)
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint unaff_EDI;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_10 = 2;
  iVar6 = 0;
  local_c = 0;
  uVar1 = *(ushort *)(**(int **)(**(int **)(unaff_EDI + 8) + 0x4e4) + 0x14);
  local_8 = (uint)uVar1;
  if (0 < (short)uVar1) {
    do {
      iVar2 = **(int **)(**(int **)(unaff_EDI + 8) + 0x4e4);
      iVar3 = *(int *)(iVar2 + 0x24 + iVar6);
      iVar2 = iVar2 + 0x24 + iVar6;
      iVar4 = *(int *)(iVar2 + 8);
      piVar5 = *(int **)(iVar2 + 0xc);
      if ((((iVar3 != -1) && (iVar3 != 300)) && (iVar4 == param_1)) && (piVar5 == param_2)) {
        props_releaseValue(unaff_EDI,(byte)iVar4,piVar5);
        iVar2 = **(int **)(**(int **)(unaff_EDI + 8) + 0x4e4);
        *(uint *)(iVar2 + 0x2c + iVar6) = local_10;
        *(undefined4 *)(iVar2 + 0x30 + iVar6) = local_c;
        core_dispatchAsync(unaff_EDI,iVar3,&local_10);
      }
      iVar6 = iVar6 + 0x10;
      local_8 = local_8 - 1;
    } while (local_8 != 0);
  }
  return 0;
}



// ============================================================
// Function: crt_releaseScriptObjects (FUN_6800ec90)
// Address: 6800ec90
// Size: 95 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_releaseScriptObjects(int param_1)
{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar1 = *(int *)(**(int **)(in_EAX + 8) + 0x56c);
  iVar2 = *(int *)(iVar1 + 4);
  while (iVar2 != 0) {
    if ((*(int *)(iVar1 + 0xac) == 3) && (*(int *)(iVar1 + 0xb0) == param_1)) {
      props_releaseValue(iVar1,(byte)*(undefined4 *)(iVar1 + 0xac),*(int **)(iVar1 + 0xb0));
      *(undefined4 *)(iVar1 + 0xac) = 2;
      *(undefined4 *)(iVar1 + 0xb0) = 0;
    }
    iVar1 = *(int *)(iVar1 + 4);
    iVar2 = *(int *)(iVar1 + 4);
  }
  return 0;
}



// ============================================================
// Function: crt_deleteBehaviorEntry (FUN_6800ecf0)
// Address: 6800ecf0
// Size: 170 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_deleteBehaviorEntry(int *param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint in_EAX;
  int iVar5;
  uint local_c;
  int *local_8;
  
  iVar5 = *(int *)(*param_1 + 4);
  iVar2 = *(int *)(in_EAX + 0xb8);
  if (-1 < iVar2) {
    iVar3 = **(int **)(**(int **)(in_EAX + 8) + 0x4e4);
    piVar1 = (int *)(iVar3 + 0x24 + iVar2 * 0x10);
    iVar4 = *piVar1;
    if ((*(int *)(iVar3 + 0x2c + iVar2 * 0x10) == 3) && ((int *)piVar1[3] == param_1)) {
      local_c = piVar1[2];
      local_8 = (int *)piVar1[3];
      piVar1[2] = 4;
      piVar1[3] = 0;
      props_releaseValue(in_EAX,(byte)local_c,local_8);
      iVar5 = iVar5 + -1;
      local_c = 2;
      local_8 = (int *)0x0;
      core_dispatchAsync(in_EAX,iVar4,&local_c);
    }
  }
  if (0 < iVar5) {
    crt_releaseScriptObjects((int)param_1);
    crt_releaseBehaviorRefs(3,param_1);
  }
  core_pollAsyncNetwork(in_EAX);
  return 0;
}



// ============================================================
// Function: crt_removeBehavior (FUN_6800eda0)
// Address: 6800eda0
// Size: 129 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_removeBehavior(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int local_c;
  int *local_8;
  
  iVar2 = *(int *)(*param_2 + 4);
  iVar1 = **(int **)(param_1 + 8);
  if ((*(int *)(iVar1 + 0x510) != 0) && (param_2 != *(int **)(iVar1 + 0x518))) {
    *(undefined4 *)(iVar1 + 0x59c) = 1;
    local_c = 3;
    local_8 = param_2;
    iVar1 = props_getListRange(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),&local_c);
    if (-1 < iVar1) {
      props_setListRange(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),iVar1);
      iVar2 = iVar2 + -1;
    }
    if (0 < iVar2) {
      crt_deleteBehaviorEntry(param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: crt_destroyScriptObject (FUN_6800ee30)
// Address: 6800ee30
// Size: 89 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_destroyScriptObject(int param_1,int *param_2)
{
  events_handleMovieOpen(param_1,*(undefined4 **)(*param_2 + 8));
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x14),*(int **)(*param_2 + 0x18));
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
// Function: crt_formatBehaviorError (FUN_6800ee90)
// Address: 6800ee90
// Size: 140 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_formatBehaviorError(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = *param_2;
  if (*(int *)(iVar1 + 0x18) == 0) {
    iVar1 = 0x26;
  }
  else {
    local_410 = *(int *)(iVar1 + 0x14);
    local_40c = *(undefined4 *)(iVar1 + 0x18);
    props_toPascalString(&local_410,local_408);
    iVar1 = 0x27;
  }
  cast_loadPascalString(&DAT_68197780,0x898,iVar1);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: crt_findBehaviorIndex (FUN_6800ef20)
// Address: 6800ef20
// Size: 79 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_findBehaviorIndex(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (*(int *)(**(int **)(param_1 + 8) + 0x510) == 0) {
    return 0;
  }
  local_8 = param_2;
  local_c = 3;
  iVar1 = props_getListRange(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),&local_c);
  *param_3 = iVar1;
  return 1;
}



// ============================================================
// Function: crt_switchMovieContext (FUN_6800ef70)
// Address: 6800ef70
// Size: 55 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_switchMovieContext(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = events_getMiawFileName(param_1,*(int **)(*param_2 + 8));
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(param_1 + 8);
    *(int *)(param_1 + 8) = iVar1;
    uVar2 = events_getScoreProperty2(param_1);
    *(undefined4 *)(param_1 + 0xf4) = uVar2;
  }
  return uVar3;
}



// ============================================================
// Function: crt_restoreMovieContext (FUN_6800efb0)
// Address: 6800efb0
// Size: 50 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_restoreMovieContext(int param_1,int *param_2,int param_3)
{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    *(int *)(param_1 + 8) = param_3;
    events_getWindowAspect(param_1,*(int **)(*param_2 + 8),param_3);
    uVar1 = events_getScoreProperty2(param_1);
    *(undefined4 *)(param_1 + 0xf4) = uVar1;
  }
  return 0;
}



// ============================================================
// Function: crt_isBehaviorObject (FUN_6800f000)
// Address: 6800f000
// Size: 27 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_isBehaviorObject(void)

{
  int *in_EAX;
  
  if ((*in_EAX == 3) && ((undefined **)**(int **)in_EAX[1] == &PTR_LAB_68189600)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: crt_findBehaviorByName (FUN_6800f020)
// Address: 6800f020
// Size: 378 bytes
// Params: int param_1, byte * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_findBehaviorByName(int param_1,byte *param_2,uint *param_3)
{
  int *piVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined3 extraout_var;
  int iVar7;
  int local_424;
  undefined4 local_420;
  int local_41c;
  uint *local_418;
  byte *local_414;
  uint local_410;
  int *local_40c;
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_414 = param_2;
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x510);
  local_418 = param_3;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar5 = props_getListLength(param_1,piVar1);
  iVar7 = 0;
  local_41c = iVar5;
  if (0 < iVar5) {
    do {
      props_getListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),iVar7,&local_410);
      iVar6 = crt_isBehaviorObject();
      if (iVar6 != 0) {
        local_424 = *(int *)(*local_40c + 0x14);
        local_420 = *(undefined4 *)(*local_40c + 0x18);
        props_toPascalString(&local_424,&local_408);
        if (*local_414 == 0xff) {
          uVar3 = Ordinal_1201(local_414 + 1);
        }
        else {
          uVar3 = (ushort)*local_414;
        }
        if (local_408 == 0xff) {
          uVar4 = Ordinal_1201(local_407);
        }
        else {
          uVar4 = (ushort)local_408;
        }
        bVar2 = Ordinal_966(local_407,local_414 + 1,(int)(short)uVar4,(int)(short)uVar3);
        iVar5 = local_41c;
        if (CONCAT31(extraout_var,bVar2) == 0) {
          *local_418 = local_410;
          local_418[1] = (uint)local_40c;
          return 0;
        }
      }
      props_releaseValue(param_1,(byte)local_410,local_40c);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar5);
  }
  return 0;
}



// ============================================================
// Function: crt_createBehavior (FUN_6800f1a0)
// Address: 6800f1a0
// Size: 256 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_createBehavior(int param_1,byte *param_2,undefined4 param_3,uint *param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_c;
  int *local_8;
  
  iVar2 = events_setMiawBgColor();
  if (iVar2 != 0) {
    crt_ensurePropertyList();
    props_readPascalString(param_1,param_2,&local_c);
    if (local_8 != (int *)0x0) {
      piVar3 = (int *)cast_allocHandle(0x1c,0);
      if (piVar3 == (int *)0x0) {
        props_releaseValue(param_1,(byte)local_c,local_8);
        return 0;
      }
      iVar2 = events_findTopSpriteAtPoint(param_1,(int)param_2,param_3,(uint)piVar3);
      if (iVar2 == 0) {
        cast_freeHandle(piVar3);
        return 0;
      }
      *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
      piVar4 = core_allocSpriteMember(param_1,1,piVar3);
      piVar5 = core_allocSpriteMemberRef(param_1,1,piVar3);
      puVar1 = (undefined4 *)*piVar3;
      *puVar1 = &PTR_LAB_68189600;
      puVar1[1] = 1;
      puVar1[2] = iVar2;
      puVar1[5] = local_c;
      puVar1[6] = local_8;
      puVar1[3] = piVar4;
      puVar1[4] = piVar5;
      *param_4 = 3;
      param_4[1] = (uint)piVar3;
      core_setSpriteMemberData(param_1,piVar4);
      core_getSpriteMemberData(param_1,piVar5);
      props_setListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),param_4);
    }
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800f2a0 - 0x6800f9f0
// Functions (7):
//   crt_findOrCreateBehavior
//   crt_resolveBehaviorRef
//   crt_checkBehaviorExists
//   crt_removeCurrentBehavior
//   crt_getScriptInstance
//   crt_accessMemberField
//   crt_invokeMemberMethod

// ============================================================
// Function: crt_findOrCreateBehavior (FUN_6800f2a0)
// Address: 6800f2a0
// Size: 33 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_findOrCreateBehavior(int param_1)
{
  int iVar1;
  int unaff_EBX;
  uint *unaff_ESI;
  byte *unaff_EDI;
  
  iVar1 = crt_findBehaviorByName(unaff_EBX,unaff_EDI,unaff_ESI);
  if ((iVar1 == 0) && (param_1 != 0)) {
    crt_createBehavior(unaff_EBX,unaff_EDI,0,unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: crt_resolveBehaviorRef (FUN_6800f2d0)
// Address: 6800f2d0
// Size: 361 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_resolveBehaviorRef(int param_1,int param_2,uint *param_3)
{
  int iVar1;
  int iVar2;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  *param_3 = 2;
  param_3[1] = 0;
  iVar1 = props_getInt(param_1);
  if (iVar1 == 1) {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_40c = DAT_6819776c;
    local_410 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_40c = ((int *)(size_t)_DAT_68197764)[1];
      local_410 = *(int *)(size_t)_DAT_68197764;
    }
    crt_ensurePropertyList();
    switch(local_410) {
    case 1:
    case 0x40:
    case 0x43:
      props_toPascalString(&local_410,local_408);
      crt_findOrCreateBehavior(param_2);
      return 0;
    default:
      iVar1 = 10;
      break;
    case 4:
      iVar1 = local_40c + -1;
      if ((-1 < iVar1) &&
         (iVar2 = props_getListLength(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510)), iVar1 < iVar2))
      {
        props_getListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),iVar1,param_3);
        return 0;
      }
      iVar1 = 0x36;
    }
    props_setErrorAndReturn(param_1,iVar1);
  }
  else {
    props_setError(param_1,0x15);
  }
  return 0;
}



// ============================================================
// Function: crt_checkBehaviorExists (FUN_6800f490)
// Address: 6800f490
// Size: 344 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_checkBehaviorExists(int param_1)
{
  int iVar1;
  int iVar2;
  byte local_420 [4];
  int *local_41c;
  undefined4 local_418;
  undefined4 local_414;
  int local_410;
  int local_40c;
  byte local_408 [1024];
  uint local_8;
  
  local_418 = 4;
  local_414 = 0;
  if (*(int *)(**(int **)(param_1 + 8) + 0x510) != 0) {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_410 = DAT_68197768;
    local_40c = DAT_6819776c;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_410 = *(int *)(size_t)_DAT_68197764;
      local_40c = ((int *)(size_t)_DAT_68197764)[1];
    }
    switch(local_410) {
    case 1:
    case 0x40:
    case 0x43:
      props_toPascalString(&local_410,local_408);
      iVar2 = crt_findBehaviorByName(param_1,local_408,(uint *)local_420);
      if (iVar2 != 0) {
        local_414 = 1;
        props_releaseValue(param_1,local_420[0],local_41c);
      }
      break;
    default:
      iVar2 = 10;
LAB_6800f5d0:
      props_setErrorAndReturn(param_1,iVar2);
      return 0;
    case 4:
      iVar2 = local_40c + -1;
      if ((iVar2 < 0) ||
         (iVar1 = props_getListLength(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510)), iVar1 <= iVar2))
      {
        iVar2 = 0x36;
        goto LAB_6800f5d0;
      }
    }
  }
  props_popArgs(param_1,&local_418);
  return 0;
}



// ============================================================
// Function: crt_removeCurrentBehavior (FUN_6800f640)
// Address: 6800f640
// Size: 120 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_removeCurrentBehavior(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_c;
  int *local_8;
  
  piVar1 = *(int **)(param_1 + 8);
  if (*(int *)(*piVar1 + 0x518) != 0) {
    local_c = 3;
    local_8 = *(int **)(*piVar1 + 0x518);
    iVar2 = props_getListRange(param_1,*(int **)(*piVar1 + 0x510),&local_c);
    if (-1 < iVar2) {
      props_setListRange(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),iVar2);
    }
    props_releaseValue(param_1,(byte)local_c,local_8);
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x518) = 0;
  }
  return 0;
}



// ============================================================
// Function: crt_getScriptInstance (FUN_6800f6c0)
// Address: 6800f6c0
// Size: 555 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getScriptInstance(int param_1,uint *param_2)
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_11c;
  undefined4 local_118;
  int local_114;
  int local_110;
  uint *local_10c;
  undefined1 local_108 [256];
  uint local_8;
  
  local_10c = param_2;
  if (*(int *)(**(int **)(param_1 + 8) + 0x510) == 0) {
    uVar2 = props_getRectCount(param_1);
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x510) = uVar2;
    crt_getScriptProperty(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510));
    props_setListSortVtable(param_1,*(undefined4 **)(**(int **)(param_1 + 8) + 0x510));
  }
  iVar3 = 1;
  if (*(int *)(**(int **)(param_1 + 8) + 0x518) == 0) {
    local_110 = 0;
    props_getSymbolString(0x22d,(int)local_108,0x100);
    iVar3 = Ordinal_1201(local_108);
    puVar4 = (undefined4 *)Ordinal_1111(iVar3 + 1,0);
    if (puVar4 != (undefined4 *)0x0) {
      uVar2 = Ordinal_1114(puVar4);
      Ordinal_1202(uVar2,local_108);
      Ordinal_1115(puVar4);
    }
    props_getValuePair(param_1,puVar4,&local_11c);
    uVar2 = cast_allocHandle(0x1c,0);
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x518) = uVar2;
    uVar1 = *(uint *)(**(int **)(param_1 + 8) + 0x518);
    if (uVar1 == 0) goto LAB_6800f8d8;
    local_114 = events_findTopSpriteAtPoint(param_1,0,0,uVar1);
    if (local_114 == 0) {
      cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x518));
      *(undefined4 *)(**(int **)(param_1 + 8) + 0x518) = 0;
      return 0;
    }
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    piVar5 = core_allocSpriteMember(param_1,1,*(undefined4 *)(**(int **)(param_1 + 8) + 0x518));
    piVar6 = core_allocSpriteMemberRef(param_1,1,*(undefined4 *)(**(int **)(param_1 + 8) + 0x518));
    puVar4 = (undefined4 *)**(int **)(**(int **)(param_1 + 8) + 0x518);
    *puVar4 = &PTR_LAB_68189600;
    puVar4[1] = 1;
    puVar4[2] = local_114;
    puVar4[5] = local_11c;
    puVar4[6] = local_118;
    puVar4[3] = piVar5;
    puVar4[4] = piVar6;
    core_setSpriteMemberData(param_1,piVar5);
    core_getSpriteMemberData(param_1,piVar6);
    iVar3 = local_110;
    param_2 = local_10c;
  }
  *param_2 = 3;
  param_2[1] = *(uint *)(**(int **)(param_1 + 8) + 0x518);
  if (iVar3 == 0) {
    props_setListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510),param_2);
    return 0;
  }
  props_retainValue(param_1,param_2);
LAB_6800f8d8:
  return 0;
}



// ============================================================
// Function: crt_accessMemberField (FUN_6800f8f0)
// Address: 6800f8f0
// Size: 247 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_accessMemberField(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint local_c;
  int local_8;
  
  uVar1 = param_1;
  iVar2 = 0x43;
  if (*(int *)(param_1 + 0xe0) != 0) {
    iVar2 = 0;
  }
  iVar2 = core_accessFieldMember(param_1,(short *)&param_1,sprites_clearMemberRef,iVar2);
  if (iVar2 == 0) {
    return 0;
  }
  if (0 < (*(unsigned short *)((char *)&param_1 + 2))) {
    local_8 = sprites_getMemberRegPoint(uVar1,&param_1);
    if (local_8 != 0) {
      local_c = 3;
      props_retainValue(uVar1,&local_c);
      props_popArgs(uVar1,&local_c);
      return 0;
    }
    if (*(int *)(uVar1 + 0xe0) == 0) {
      _DAT_68197764 =
           **(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18);
      if (_DAT_68197764 == 0) {
        props_setErrorAndReturn(uVar1,0x43);
        return 0;
      }
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      props_setErrorAndReturn(uVar1,0x43);
      return 0;
    }
  }
  local_c = 2;
  local_8 = 0;
  props_popArgs(uVar1,&local_c);
  return 0;
}



// ============================================================
// Function: crt_invokeMemberMethod (FUN_6800f9f0)
// Address: 6800f9f0
// Size: 292 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int crt_invokeMemberMethod(uint param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint local_c;
  int *local_8;
  
  uVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if (iVar2 < 1) {
    props_setError(uVar1,0x15);
    return 0;
  }
  param_1 = param_1 & 0xffff0000;
  _DAT_68197764 =
       (uint *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (uint *)0x0) {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  crt_executePlatformQuery(uVar1,(int *)&local_c,sprites_resetMember,(short *)&param_1);
  sprites_checkBounds(uVar1,(short *)&param_1);
  puVar3 = (undefined4 *)sprites_getMemberRegPoint(uVar1,&param_1);
  if (puVar3 != (undefined4 *)0x0) {
    props_releaseValue(uVar1,(byte)local_c,local_8);
    local_c = 3;
    local_8 = puVar3;
    props_retainValue(uVar1,&local_c);
    iVar4 = **(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8;
    iVar2 = *(int *)(uVar1 + 0x18);
    *(uint *)(iVar4 + iVar2) = local_c;
    *(int **)(iVar4 + 4 + iVar2) = local_8;
    iVar2 = (**(code **)(*(int *)*puVar3 + 4))(uVar1,puVar3,0x82);
    if (iVar2 == 0) {
      props_reportError(uVar1,5);
    }
    return 0;
  }
  props_setErrorAndReturn(uVar1,0x43);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x6800fb20 - 0x6800fb20
// Functions (1):
//   crt_buildEnvironmentInfo

// ============================================================
// Function: crt_buildEnvironmentInfo (FUN_6800fb20)
// Address: 6800fb20
// Size: 1377 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_buildEnvironmentInfo(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint unaff_ESI;
  char *pcVar4;
  int iVar5;
  uint *puVar6;
  undefined4 *local_91c;
  uint local_918 [4];
  byte local_908 [1024];
  char local_508 [256];
  char local_408 [1024];
  uint local_8;
  
  local_91c = param_1;
  iVar1 = crt_getScriptObjectValue(unaff_ESI);
  local_918[0] = 8;
  iVar2 = score_dispatchProplist(unaff_ESI);
  if (iVar2 == 0) {
    *local_91c = 2;
    return 0;
  }
  *local_91c = 3;
  local_91c[1] = iVar2;
  if (iVar1 != 0) {
    props_storeIntValue(unaff_ESI,0,local_918 + 2);
    local_918[1] = 0x372;
    score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
    props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
    local_508[0] = '\0';
    props_loadStringValue(unaff_ESI,local_508,local_918 + 2);
    local_918[1] = 0x385;
    score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
    props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  }
  sprites_getSystemPath(unaff_ESI,local_408,(int)local_908);
  Ordinal_1232(local_408,local_408);
  props_loadStringValue(unaff_ESI,local_408,local_918 + 2);
  local_918[1] = 0x2dd;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  if ((iVar1 != 0) && (*(code **)(iVar1 + 0x74) != (code *)0x0)) {
    (**(code **)(iVar1 + 0x74))(local_408,0x400);
    props_loadStringValue(unaff_ESI,local_408,local_918 + 2);
    local_918[1] = 0x2e9;
    score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
    props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  }
  events_setMiawActiveFlag(unaff_ESI,6,local_918 + 2);
  local_918[1] = 0x18c;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  local_91c = (undefined4 *)0x0;
  crt_checkInternetState((int *)&local_91c);
  if (local_91c == (undefined4 *)0x0) {
    iVar5 = 0x37b;
  }
  else if (local_91c == (undefined4 *)0x1) {
    iVar5 = 0x379;
  }
  else {
    if (local_91c != (undefined4 *)0x2) goto LAB_6800fd6a;
    iVar5 = 0x37a;
  }
  props_storeObjectRef(unaff_ESI,iVar5,local_918 + 2);
LAB_6800fd6a:
  local_918[1] = 0x378;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  iVar5 = media_applyPixelOp(iVar1,8,local_408,0x400);
  if (iVar5 == 0) {
    puVar6 = local_918 + 2;
    pbVar3 = (byte *)Ordinal_1233(local_408,local_408);
    props_readPascalString(unaff_ESI,pbVar3,puVar6);
  }
  local_918[1] = 0x37d;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  iVar5 = media_applyPixelOp(iVar1,9,local_408,0x400);
  if (iVar5 == 0) {
    puVar6 = local_918 + 2;
    pbVar3 = (byte *)Ordinal_1233(local_408,local_408);
    props_readPascalString(unaff_ESI,pbVar3,puVar6);
  }
  local_918[1] = 0x3bc;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  iVar5 = media_applyPixelOp(iVar1,7,local_408,0x400);
  if (iVar5 == 0) {
    puVar6 = local_918 + 2;
    pbVar3 = (byte *)Ordinal_1233(local_408,local_408);
    props_readPascalString(unaff_ESI,pbVar3,puVar6);
  }
  local_918[1] = 0x37e;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  Ordinal_59(local_408);
  pcVar4 = local_408;
  pbVar3 = (byte *)Ordinal_1233(pcVar4,pcVar4,local_918 + 2);
  props_readPascalString(unaff_ESI,pbVar3,(undefined4 *)pcVar4);
  local_918[1] = 0x2ec;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  props_readPascalString(unaff_ESI,local_908,local_918 + 2);
  local_918[1] = 0x553;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  sprites_delay(unaff_ESI,local_408);
  props_loadStringValue(unaff_ESI,local_408,local_918 + 2);
  local_918[1] = 0x636;
  score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
  props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
  if (iVar1 != 0) {
    if (*(code **)(iVar1 + 0x194) != (code *)0x0) {
      (**(code **)(iVar1 + 0x194))(local_408,0x400);
      props_loadStringValue(unaff_ESI,local_408,local_918 + 2);
      local_918[1] = 0x637;
      score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
      props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
    }
    if (*(code **)(iVar1 + 0x198) != (code *)0x0) {
      local_91c = (undefined4 *)0x0;
      (**(code **)(iVar1 + 0x198))(&local_91c);
      props_storeIntValue(unaff_ESI,local_91c,local_918 + 2);
      local_918[1] = 0x638;
      score_setPropertyValue(unaff_ESI,iVar2,local_918,local_918 + 2,1);
      props_releaseAndClear(unaff_ESI,(int *)(local_918 + 2));
    }
  }
  return 0;
}



