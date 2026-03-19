// Module: core
// Topic: Action/command dispatch - switch-based action handlers for various object types
// Address range: 0x680104F0 - 0x68016700
// Functions (14):
//   core_handleScoreAction (0x680104F0)
//   core_dispatchScriptAction (0x68015A10)
//   core_getSpriteProperty (0x68015BC0)
//   core_validateSpriteAction (0x68015C50)
//   core_dispatchSpriteAction (0x68015CC0)
//   core_validate3dAction (0x680160B0)
//   core_dispatch3dAction (0x68016110)
//   core_dispatchTimeoutAction (0x68016360)
//   core_dispatchCursorAction (0x68016410)
//   core_dispatchTypeOnlyAction (0x680164E0)
//   core_dispatchNetworkAction (0x68016520)
//   core_dispatchMenuAction (0x680166A0)
//   core_getMenuObjProperty (0x680166E0)
//   core_dispatchWindowAction (0x68016700)

// ============================================================
// Function: core_handleScoreAction (FUN_680104f0)
// Address: 680104f0
// Size: 133 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_handleScoreAction(uint param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_c [2];
  
  iVar1 = *(int *)(*param_2 + 8);
  if (param_3 == 0x82) {
    core_removeStackArgs(param_1,1);
    if (iVar1 == 0x56) {
      score_resolveTimer(param_1,1,1,local_c);
    }
    else if (iVar1 == 0x7c) {
      crt_resolveBehaviorRef(param_1,1,local_c);
    }
    props_popArgs(param_1,local_c);
    return 1;
  }
  if (param_3 != 0xe3) {
    return 0;
  }
  score_resolveType(param_1);
  return 1;
}



// ============================================================
// Function: core_dispatchScriptAction (FUN_68015a10)
// Address: 68015a10
// Size: 202 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchScriptAction(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 < 0x1cd) {
    if (param_3 == 0x1cc) goto switchD_68015ac0_caseD_310;
    if (param_3 < 0xe4) {
      if (param_3 == 0xe3) {
        score_resolveType(param_1);
        return 1;
      }
      if ((param_3 != 0x81) && (param_3 != 0xd4)) {
        if (param_3 == 0xdd) {
          uVar1 = core_getHandlerCount();
          return uVar1;
        }
        return 0;
      }
      uVar1 = core_validateHandlerType();
      return uVar1;
    }
    if ((param_3 == 0x14b) || (param_3 == 0x166)) goto switchD_68015ac0_caseD_310;
    iVar2 = param_3 + -0x1c9;
  }
  else {
    if (0x2f7 < param_3) {
      switch(param_3) {
      case 0x310:
      case 0x311:
      case 0x312:
      case 0x382:
      case 0x3b9:
        goto switchD_68015ac0_caseD_310;
      default:
        return 0;
      }
    }
    if (((param_3 == 0x2f7) || (param_3 == 0x1d5)) || (param_3 == 0x1db))
    goto switchD_68015ac0_caseD_310;
    iVar2 = param_3 + -0x2d5;
  }
  if (iVar2 != 0) {
    return 0;
  }
switchD_68015ac0_caseD_310:
  uVar1 = core_getStackState();
  return uVar1;
}



// ============================================================
// Function: core_getSpriteProperty (FUN_68015bc0)
// Address: 68015bc0
// Size: 133 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getSpriteProperty(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_8);
  if (iVar1 == 0) {
    return 1;
  }
  local_10 = 4;
  if ((int)local_8 < 0x69) {
    if (local_8 == 0x68) {
      uVar2 = sprites_getMemberCount(unaff_ESI);
      local_c = (int)(short)uVar2;
      props_popArgs(unaff_ESI,&local_10);
      return 1;
    }
    if (local_8 != 0x2e) {
      if (local_8 != 0x58) {
        return 0;
      }
      local_c = sprites_getMemberByChannel(unaff_ESI,1);
      goto LAB_68015c2f;
    }
  }
  else if (local_8 != 0x5fd) {
    return 0;
  }
  local_c = events_getScoreProperty2(unaff_ESI);
LAB_68015c2f:
  props_popArgs(unaff_ESI,&local_10);
  return 1;
}



// ============================================================
// Function: core_validateSpriteAction (FUN_68015c50)
// Address: 68015c50
// Size: 112 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_validateSpriteAction(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  uint local_8;
  
  iVar1 = props_getInt(in_EAX);
  if (iVar1 < 3) {
    props_setError(in_EAX,0x19);
    return 1;
  }
  iVar1 = props_getTypedValue(in_EAX,2,8,&local_8);
  if (iVar1 == 0) {
    return 1;
  }
  if ((int)local_8 < 0x69) {
    if ((local_8 == 0x68) || (local_8 == 0x2e)) goto LAB_68015cb0;
    bVar3 = local_8 == 0x58;
  }
  else {
    if (local_8 == 0x7b) goto LAB_68015cb0;
    bVar3 = local_8 == 0x5fd;
  }
  if (!bVar3) {
    return 0;
  }
LAB_68015cb0:
  uVar2 = core_getStackState();
  return uVar2;
}



// ============================================================
// Function: core_dispatchSpriteAction (FUN_68015cc0)
// Address: 68015cc0
// Size: 248 bytes
// Params: uint param_1, undefined4 param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchSpriteAction(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((int)param_3 < 0x162) {
    if (param_3 != 0x161) {
      switch(param_3) {
      case 0x27:
      case 0x2f:
      case 0x8b:
      case 0x8f:
      case 0x91:
      case 0x93:
      case 0x94:
      case 0x98:
      case 0xaf:
      case 0xb0:
      case 0xb1:
      case 0xba:
switchD_68015ceb_caseD_27:
        return 0;
      default:
        goto switchD_68015ceb_caseD_28;
      case 0x81:
      case 0xd4:
        uVar1 = core_validateSpriteAction();
        return uVar1;
      case 0xad:
      case 0xae:
      case 0xc1:
      case 0xc2:
        break;
      case 0xdd:
        uVar1 = core_getSpriteProperty();
        return uVar1;
      case 0xe3:
        score_resolveType(param_1);
        return 1;
      }
    }
  }
  else if ((int)param_3 < 0x2e0) {
    if ((int)param_3 < 0x2de) {
      switch(param_3) {
      case 0x1c1:
      case 0x1c2:
      case 0x1c5:
      case 0x1c6:
      case 0x1c8:
      case 0x1cb:
      case 0x1ce:
      case 0x1d5:
      case 0x1d7:
      case 0x1d8:
      case 0x1d9:
      case 0x1da:
      case 0x1dc:
      case 0x1e0:
      case 0x1e7:
      case 0x20b:
      case 0x22c:
      case 0x23c:
      case 0x24c:
      case 0x24d:
      case 0x24e:
      case 0x24f:
      case 0x250:
      case 0x251:
      case 0x252:
      case 0x25f:
      case 0x260:
      case 0x261:
        break;
      default:
        goto switchD_68015ceb_caseD_28;
      case 0x20a:
        goto switchD_68015ceb_caseD_27;
      }
    }
  }
  else if ((int)param_3 < 0x336) {
    if (param_3 != 0x335) {
      switch(param_3) {
      case 0x2f3:
      case 0x2f4:
      case 0x313:
      case 0x331:
      case 0x332:
        break;
      default:
        goto switchD_68015ceb_caseD_28;
      }
    }
  }
  else {
    switch(param_3) {
    case 0x60f:
    case 0x610:
    case 0x611:
    case 0x655:
      break;
    default:
switchD_68015ceb_caseD_28:
      uVar1 = core_popAndDispatch(param_3);
      return uVar1;
    case 0x621:
      ; /* FIXUP */ }
  }
  uVar1 = core_getStackState();
  return uVar1;
}



// ============================================================
// Function: core_validate3dAction (FUN_680160b0)
// Address: 680160b0
// Size: 94 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_validate3dAction(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  uint local_8;
  
  iVar1 = props_getInt(in_EAX);
  if (iVar1 < 3) {
    props_setError(in_EAX,0x19);
  }
  else {
    iVar1 = props_getTypedValue(in_EAX,2,8,&local_8);
    if (iVar1 != 0) {
      if ((local_8 != 0x662) && (local_8 != 0x663)) {
        return 0;
      }
      uVar2 = core_getStackState();
      return uVar2;
    }
  }
  return 1;
}



// ============================================================
// Function: core_dispatch3dAction (FUN_68016110)
// Address: 68016110
// Size: 103 bytes
// Params: uint param_1, undefined4 param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint core_dispatch3dAction(uint param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  
  if ((int)param_3 < 0xe4) {
    if (param_3 == 0xe3) {
      score_resolveType(param_1);
      return 1;
    }
    if (param_3 == 0xd4) {
      uVar2 = core_validate3dAction();
      return uVar2;
    }
    if (param_3 == 0xdd) {
      bVar1 = core_validateStackType(param_1);
      return CONCAT31(extraout_var,bVar1);
    }
  }
  else if (param_3 == 0x667) {
    uVar2 = core_returnTrue();
    return uVar2;
  }
  uVar2 = core_popAndDispatch(param_3);
  return uVar2;
}




/* Restored functions that were incorrectly removed during thunk cleanup */



// ============================================================
// Function: core_dispatchTimeoutAction (FUN_68016360)
// Address: 68016360
// Size: 70 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchTimeoutAction(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0xe3) {
    score_resolveType(param_1);
    return 1;
  }
  if (param_3 != 0x2db) {
    return 0;
  }
  uVar1 = core_getStackState();
  return uVar1;
}



// ============================================================
// Function: core_dispatchCursorAction (FUN_68016410)
// Address: 68016410
// Size: 105 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchCursorAction(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 0x1a3) {
    if (param_3 != 0x1a2) {
      if (param_3 == 0xe3) {
        score_resolveType(param_1);
        return 1;
      }
      if (param_3 != 0x124) {
        return 0;
      }
    }
  }
  else if ((param_3 != 0x1c3) && (param_3 != 0x5fd)) {
    return 0;
  }
  uVar1 = core_getStackState();
  return uVar1;
}



// ============================================================
// Function: core_dispatchTypeOnlyAction (FUN_680164e0)
// Address: 680164e0
// Size: 36 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchTypeOnlyAction(uint param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0xe3) {
    return 0;
  }
  score_resolveType(param_1);
  return 1;
}



// ============================================================
// Function: core_dispatchNetworkAction (FUN_68016520)
// Address: 68016520
// Size: 150 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchNetworkAction(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 0x1d1) {
    if (param_3 < 0x1cf) {
      switch(param_3) {
      case 0x84:
      case 0x85:
      case 299:
        break;
      default:
        goto switchD_6801654c_caseD_86;
      case 0xe3:
        score_resolveType(param_1);
        return 1;
      }
    }
  }
  else {
    if (param_3 == 0x633) {
      core_destroyAsyncNetwork(param_1);
      props_popArgs(param_1,(undefined4 *)0x0);
      return 1;
    }
    if ((param_3 < 0x646) || (0x648 < param_3)) {
switchD_6801654c_caseD_86:
      return 0;
    }
  }
  uVar1 = core_getStackState();
  return uVar1;
}



// ============================================================
// Function: core_dispatchMenuAction (FUN_680166a0)
// Address: 680166a0
// Size: 49 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchMenuAction(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 != 0xe3) {
    uVar1 = cast_dispatchMenuAction(param_1,param_2,param_3);
    return uVar1;
  }
  score_resolveType(param_1);
  return 1;
}



// ============================================================
// Function: core_getMenuObjProperty (FUN_680166e0)
// Address: 680166e0
// Size: 9 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getMenuObjProperty(int param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)
{
  cast_getMenuObjProperty(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: core_dispatchWindowAction (FUN_68016700)
// Address: 68016700
// Size: 77 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchWindowAction(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0xe3) {
    score_resolveType(param_1);
    return 1;
  }
  if ((0x125 < param_3) && (param_3 < 0x128)) {
    uVar1 = core_getStackState();
    return uVar1;
  }
  return 0;
}


