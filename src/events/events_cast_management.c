// Module: events
// Topic: Cast member management, sprite slot operations, and ordinal thread control
// Address range: 0x68060000 - 0x680610f0
// Functions (37):
//   events_resolveCastScript
//   events_getScriptTarget
//   events_collectHandlerFlags
//   events_removeSpriteSlot
//   events_removeOutOfRangeSlots
//   events_removeAllSpriteSlots
//   Ordinal_69
//   events_releaseSpriteSlotObjects
//   events_setupSpriteSlot
//   events_forwardDispatch
//   events_getAndClearPendingFlag
//   events_checkSpriteHandlerFlags
//   events_checkScriptHandlerFlags
//   Ordinal_555
//   Ordinal_561
//   Ordinal_562
//   Ordinal_550
//   Ordinal_551
//   Ordinal_552
//   Ordinal_563
//   Ordinal_553
//   Ordinal_554
//   Ordinal_556
//   Ordinal_557
//   Ordinal_558
//   events_manageCastMember
//   Ordinal_168
//   Ordinal_4102
//   Ordinal_946
//   Ordinal_4103
//   Ordinal_4104
//   events_getXtraPalette
//   events_resetPuppetSprites
//   events_copyCastMember
//   events_setCastSlotData

// ============================================================
// Function: events_resolveCastScript (events_resolveCastScript)
// Address: 68060000
// Size: 231 bytes
// Params: void * this, undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall events_resolveCastScript(void *this,undefined4 param_1,int param_2)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  uint local_30;
  int *local_2c;
  uint local_28;
  int local_24;
  int *local_20 [6];
  uint local_8;
  
  piVar1 = *(int **)(unaff_ESI + 0xc);
  uVar2 = Ordinal_362(*(int *)(unaff_ESI + 0x20),(int)this,&param_1);
  iVar3 = Ordinal_294(*(int *)(unaff_ESI + 0x20),(int)this,uVar2,0x25,(uint *)local_20);
  if ((iVar3 != 0) && (local_20[0] != (int *)0x0)) {
    local_24 = *(int *)(unaff_ESI + 0x148);
    *(int *)(unaff_ESI + 0x148) = param_2;
    piVar4 = (int *)strings_dispatchLingoContext((int)piVar1,local_20[0]);
    *(int *)(unaff_ESI + 0x148) = local_24;
    if (piVar4 != (int *)0x0) {
      local_28 = 4;
      local_24 = param_2;
      if (param_2 == 0) {
        local_24 = -5;
      }
      cast_setPropertyValue(piVar1,piVar4,0x319,&local_28);
      if (0x5ff < *(uint *)(unaff_ESI + 500)) {
        local_30 = 3;
        local_2c = piVar4;
        cast_executeHandler(piVar1,piVar4,0x82,1,&local_30,(int *)0x0,&local_24);
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: events_getScriptTarget (events_getScriptTarget)
// Address: 680600f0
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getScriptTarget(void)
{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = stage_getDataNodeParam(unaff_ESI);
  if (iVar1 == 0) {
    strings_getLingoContextTarget(unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: events_collectHandlerFlags (events_collectHandlerFlags)
// Address: 68060110
// Size: 111 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint events_collectHandlerFlags(int *param_1)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_8;
  
  uVar1 = *(undefined4 *)(in_EAX + 0xc);
  local_8 = 0;
  iVar2 = cast_getMemberData(uVar1,param_1);
  iVar6 = 1;
  if (0 < iVar2) {
    do {
      piVar3 = cast_resolveContext(uVar1,param_1,iVar6);
      if (piVar3 != (int *)0x0) {
        piVar4 = (int *)events_getScriptTarget();
        cast_releaseObject(uVar1,piVar3);
        uVar5 = cast_getHandlerFlags(uVar1,piVar4);
        local_8 = local_8 | uVar5;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= iVar2);
    return local_8;
  }
  return 0;
}



// ============================================================
// Function: events_removeSpriteSlot (events_removeSpriteSlot)
// Address: 68060180
// Size: 353 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_removeSpriteSlot(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  undefined4 local_48 [16];
  uint local_8;
  
  local_58 = param_3;
  if (param_1 != 0) {
    local_50 = *(int *)(param_1 + 0xc);
    local_54 = 0;
    iVar3 = scoreEngine_getPropertyRange(*(int *)(param_1 + 0x20),param_2);
    if (iVar3 != 0) {
      local_68 = *(undefined4 *)(param_1 + 0x24);
      local_60 = *(undefined4 *)(param_1 + 0x28);
      local_54 = 1;
      *(int *)(param_1 + 0x24) = param_2;
      uVar4 = scoreEngine_accessProperty(*(int *)(param_1 + 0x20),param_2);
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      iVar3 = *(int *)(param_1 + 0xc);
      local_64 = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0xc);
    }
    iVar3 = Ordinal_165(*(int *)(param_1 + 0x20),param_2,&local_6c);
    if (param_3 <= local_6c) {
      local_4c = (int *)(iVar3 + param_3 * 0x34);
      piVar1 = (int *)*local_4c;
      if (piVar1 != (int *)0x0) {
        cast_retainObject(local_50,piVar1);
        if ((param_5 != 0) && (*(int *)(param_1 + 0x17c) != 0)) {
          local_5c = *(undefined4 *)(param_1 + 0x1c4);
          *(undefined4 *)(param_1 + 0x1c4) = 1;
          events_processDispatch(param_1,piVar1,0x1c,local_58);
          *(undefined4 *)(param_1 + 0x1c4) = local_5c;
        }
        piVar2 = (int *)*local_4c;
        *local_4c = 0;
        local_4c[3] = 0;
        local_4c = piVar2;
        crt_getScriptPropertyEx(local_50,piVar1);
        iVar3 = local_50;
        cast_releaseObject(local_50,piVar1);
        if (local_4c != (int *)0x0) {
          cast_releaseObject(iVar3,local_4c);
        }
        local_48[0] = 1;
        Ordinal_373(*(uint *)(param_1 + 0x20),param_2,local_58,0x27,(double *)local_48,0);
      }
    }
    if (local_54 != 0) {
      *(undefined4 *)(param_1 + 0x24) = local_68;
      *(undefined4 *)(param_1 + 0x28) = local_60;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = local_64;
    }
  }
  return 0;
}



// ============================================================
// Function: events_removeOutOfRangeSlots (events_removeOutOfRangeSlots)
// Address: 680602f0
// Size: 232 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_removeOutOfRangeSlots(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  iVar1 = param_2;
  if (param_1 != 0) {
    local_8 = 0;
    iVar2 = scoreEngine_getPropertyRange(*(int *)(param_1 + 0x20),param_2);
    if (iVar2 != 0) {
      local_c = *(undefined4 *)(param_1 + 0x24);
      local_10 = *(undefined4 *)(param_1 + 0x28);
      local_8 = 1;
      *(int *)(param_1 + 0x24) = iVar1;
      uVar3 = scoreEngine_accessProperty(*(int *)(param_1 + 0x20),iVar1);
      *(undefined4 *)(param_1 + 0x28) = uVar3;
      iVar2 = *(int *)(param_1 + 0xc);
      local_14 = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0xc);
    }
    iVar2 = Ordinal_165(*(int *)(param_1 + 0x20),iVar1,&local_18);
    Ordinal_377(*(undefined4 *)(param_1 + 0x20),iVar1,&local_1c,&param_2);
    if ((iVar2 != 0) && (iVar5 = 0, -1 < param_2)) {
      piVar4 = (int *)(iVar2 + 8);
      do {
        if ((piVar4[-2] != 0) && ((param_3 < piVar4[-1] || (*piVar4 < param_3)))) {
          events_removeSpriteSlot(param_1,iVar1,iVar5,0,1);
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0xd;
      } while (iVar5 <= param_2);
    }
    if (local_8 != 0) {
      *(undefined4 *)(param_1 + 0x24) = local_c;
      *(undefined4 *)(param_1 + 0x28) = local_10;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = local_14;
    }
  }
  return 0;
}



// ============================================================
// Function: events_removeAllSpriteSlots (events_removeAllSpriteSlots)
// Address: 680603e0
// Size: 46 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_removeAllSpriteSlots(int param_1,int param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = 0;
    do {
      events_removeSpriteSlot(param_1,param_2,iVar1,0,1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3e9);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_69
// Address: 68060410
// Size: 197 bytes
// Params: int param_1, short param_2, undefined4 * param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_69(int param_1,short param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int local_8;
  
                    /* 0x60410  69   */
  iVar2 = 0;
  local_8 = 0;
  local_8 = Ordinal_1111(0,0);
  if ((param_1 != 0) && (local_8 != 0)) {
    if (0 < param_2) {
      iVar3 = param_4 - (int)param_3;
      do {
        iVar1 = Ordinal_1201(*param_3);
        iVar1 = Ordinal_1121(&local_8,*param_3,iVar1 + 1);
        if (iVar1 == 0) goto LAB_680604af;
        puVar4 = *(undefined **)(iVar3 + (int)param_3);
        if (puVar4 == (undefined *)0x0) {
          puVar4 = "";
        }
        iVar1 = Ordinal_1201(puVar4);
        iVar1 = Ordinal_1121(&local_8,puVar4,iVar1 + 1);
        if (iVar1 == 0) {
          Ordinal_1113(&local_8);
          return local_8;
        }
        iVar2 = iVar2 + 1;
        param_3 = param_3 + 1;
      } while (iVar2 < param_2);
    }
    iVar2 = Ordinal_1121(&local_8,"",1);
    if (iVar2 == 0) {
LAB_680604af:
      Ordinal_1113(&local_8);
    }
  }
  return local_8;
}



// ============================================================
// Function: events_releaseSpriteSlotObjects (events_releaseSpriteSlotObjects)
// Address: 680604e0
// Size: 54 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_releaseSpriteSlotObjects(int param_1,undefined4 *param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  if ((param_2 != (undefined4 *)0x0) && (-1 < param_3)) {
    iVar2 = param_3 + 1;
    do {
      cast_releaseObject(uVar1,(int *)*param_2);
      param_2 = param_2 + 0xd;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}



// ============================================================
// Function: events_setupSpriteSlot (events_setupSpriteSlot)
// Address: 68060520
// Size: 255 bytes
// Params: int param_1, undefined4 * param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setupSpriteSlot(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)
{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  pvVar1 = *(void **)(param_1 + 0xc);
  local_8 = (int *)sprites_getMemberRegPoint((int)pvVar1,&param_4);
  events_removeSpriteSlot(param_1,(int)param_2,param_3,0,1);
  piVar3 = (int *)cast_resetAndCountRects((int)pvVar1);
  if (piVar3 != (int *)0x0) {
    piVar4 = (int *)events_resolveCastScript(param_2,param_4,param_3);
    if (piVar4 != (int *)0x0) {
      local_8 = (int *)props_collectProperties((int)pvVar1,local_8);
      local_c = Ordinal_165(*(int *)(param_1 + 0x20),(int)param_2,&local_10);
      if (local_8 != (int *)0x0) {
        param_2 = (undefined4 *)cast_extractProplistString((int)pvVar1,local_8);
        props_parseSymbolTable(pvVar1,piVar4,param_2);
        Ordinal_1113(&param_2);
      }
      cast_setContextEntry((int)pvVar1,piVar3,piVar4);
      cast_releaseObject(pvVar1,piVar4);
      crt_getScriptProperty((int)pvVar1,piVar3);
      puVar6 = (undefined4 *)(param_3 * 0x34 + local_c);
      *puVar6 = piVar3;
      uVar5 = events_collectHandlerFlags(piVar3);
      puVar6[3] = uVar5;
      uVar2 = *(undefined4 *)(param_1 + 0x1c4);
      *(undefined4 *)(param_1 + 0x1c4) = 1;
      events_processDispatch(param_1,(int *)*puVar6,0x1b,param_3);
      *(undefined4 *)(param_1 + 0x1c4) = uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: events_forwardDispatch (events_forwardDispatch)
// Address: 68060620
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_forwardDispatch(void)
{
  int in_stack_00000004;
  int *in_stack_00000008;
  int in_stack_0000000c;
  undefined4 in_stack_00000010;
  
  events_processDispatch(in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return 0;
}



// ============================================================
// Function: events_getAndClearPendingFlag (events_getAndClearPendingFlag)
// Address: 68060630
// Size: 26 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_getAndClearPendingFlag(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x728);
  *(undefined4 *)(param_1 + 0x728) = 0;
  return uVar1;
}




// ============================================================
// Function: events_checkSpriteHandlerFlags (events_checkSpriteHandlerFlags)
// Address: 68060650
// Size: 342 bytes
// Params: int param_1, int param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint events_checkSpriteHandlerFlags(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar6;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  local_8 = 0;
  iVar3 = Ordinal_165(*(int *)(param_1 + 0x20),param_2,&local_10);
  puVar6 = (undefined4 *)(param_3 * 0x34 + iVar3);
  if ((int *)*puVar6 != (int *)0x0) {
    if ((*(int *)(param_1 + 0x1e0) == 0) && (0x7ff < *(uint *)(param_1 + 500))) {
      if ((puVar6[3] & 0x1800003) != 0) {
        local_8 = 1;
      }
      if ((puVar6[3] & 0x380) != 0) {
        return local_8 | 2;
      }
    }
    else {
      local_c = cast_getMemberData(uVar1,(int *)*puVar6);
      if (local_c != 0) {
        local_c = local_c + 1;
        param_2 = 1;
        if (1 < local_c) {
          do {
            piVar4 = cast_resolveContext(uVar1,(int *)*puVar6,param_2);
            if (piVar4 != (int *)0x0) {
              piVar5 = (int *)events_getScriptTarget();
              cast_releaseObject(uVar1,piVar4);
              if (piVar5 != (int *)0x0) {
                if ((*(int *)(param_1 + 0x1e0) != 0) || (*(uint *)(param_1 + 500) < 0x600)) {
                  local_8 = local_8 | 1;
                }
                if ((*(uint *)(param_1 + 500) < 0x700) &&
                   (iVar3 = cast_isContextEmpty(uVar1,piVar5), iVar3 != 0)) {
                  local_8 = local_8 | 1;
                }
                bVar2 = cast_checkHandlerArgs(uVar1,piVar5,0x1800003);
                if (CONCAT31(extraout_var,bVar2) != 0) {
                  local_8 = local_8 | 1;
                }
                bVar2 = cast_checkHandlerArgs(uVar1,piVar5,0x380);
                if (CONCAT31(extraout_var_00,bVar2) != 0) {
                  local_8 = local_8 | 2;
                }
              }
              if (local_8 == 3) {
                return 3;
              }
            }
            param_2 = param_2 + 1;
          } while (param_2 < local_c);
        }
      }
    }
  }
  return local_8;
}



// ============================================================
// Function: events_checkScriptHandlerFlags (events_checkScriptHandlerFlags)
// Address: 680607b0
// Size: 119 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint events_checkScriptHandlerFlags(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  if (param_3 != (int *)0x0) {
    if ((*(int *)(param_1 + 0x1e0) != 0) || (*(uint *)(param_1 + 500) < 0x600)) {
      uVar4 = 1;
    }
    if (*(uint *)(param_1 + 500) < 0x700) {
      iVar3 = cast_isContextEmpty(uVar1,param_3);
      if (iVar3 != 0) {
        uVar4 = 1;
      }
    }
    bVar2 = cast_checkHandlerArgs(uVar1,param_3,0x1800003);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      uVar4 = 1;
    }
    bVar2 = cast_checkHandlerArgs(uVar1,param_3,0x380);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      uVar4 = uVar4 | 2;
    }
  }
  return uVar4;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: Ordinal_555
// Address: 68060840
// Size: 149 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_555(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x60840  555   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  lingo_getGlobalState(iVar1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_561
// Address: 680608e0
// Size: 149 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_561(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x608e0  561   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  lingo_getGlobalType(iVar1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_562
// Address: 68060980
// Size: 149 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_562(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x60980  562   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  lingo_getGlobalFlags(iVar1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_550
// Address: 68060a20
// Size: 9 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_550(int *param_1,undefined4 *param_2)
{
                    /* 0x60a20  550   */
  mediaPlayback_copyMovieStateData(param_1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_551
// Address: 68060a30
// Size: 56 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_551(int param_1,undefined4 *param_2)
{
  int *piVar1;
  
                    /* 0x60a30  551   */
  if (((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
     (piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0x20), piVar1 != (int *)0x0)) {
    lingo_dispatchVtableOp(*piVar1,param_2);
    return 0;
  }
  lingo_dispatchVtableOp(0,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_552
// Address: 68060a70
// Size: 60 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_552(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  
                    /* 0x60a70  552   */
  if ((param_2 == 0) || (*(undefined4 **)(param_2 + 0x20) == (undefined4 *)0x0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = **(undefined4 **)(param_2 + 0x20);
  }
  Ordinal_2330();
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[1] = DAT_68196374;
  DAT_68196374 = param_1;
  return 0;
}



// ============================================================
// Function: Ordinal_563
// Address: 68060ab0
// Size: 47 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_563(undefined4 *param_1)
{
                    /* 0x60ab0  563   */
  Ordinal_2330();
  *param_1 = 0;
  param_1[2] = 4;
  param_1[1] = DAT_68196374;
  DAT_68196374 = 0;
  return 0;
}



// ============================================================
// Function: Ordinal_553
// Address: 68060ae0
// Size: 24 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_553(int param_1)
{
                    /* 0x60ae0  553  
                       0x60ae0  564   */
  DAT_68196374 = *(undefined4 *)(param_1 + 4);
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_554
// Address: 68060b00
// Size: 27 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_554(int param_1,undefined4 param_2,int *param_3)
{
                    /* 0x60b00  554   */
  media_getScoreSlotRef(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_556
// Address: 68060b20
// Size: 144 bytes
// Params: int param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_556(int param_1,undefined4 param_2,uint *param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x60b20  556   */
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  media_queryXtraPropertyEx(piVar1[1],param_2,param_3);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}




// ============================================================
// Function: Ordinal_557
// Address: 68060bb0
// Size: 162 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_557(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x60bb0  557   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  piVar1 = (int *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    piVar1 = *(int **)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  lingo_resolveRefEx(piVar1,param_2,param_3);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_558
// Address: 68060c60
// Size: 187 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_558(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x60c60  558   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      if ((piVar3 == (int *)0x0) || (iVar2 = *piVar3, iVar2 == 0)) {
        iVar2 = *piVar3;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  uVar1 = Ordinal_1038(&DAT_68176518,&DAT_68176548,&local_18);
  iVar2 = Ordinal_2063(uVar1);
  if (iVar2 == 0) {
    (**(code **)(*local_18 + 0xc))(local_18);
    (**(code **)(*local_18 + 8))(local_18);
  }
  Ordinal_1039();
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: events_manageCastMember (FUN_68060d20)
// Address: 68060d20
// Size: 43 bytes
// Params: int param_1, undefined2 * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_manageCastMember(int param_1,undefined2 *param_2,uint param_3)

{
  if (*(byte *)((int)param_2 + 3) != param_3) {
    Ordinal_72(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_168
// Address: 68060d50
// Size: 187 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_168(int param_1,int param_2,int param_3)
{
  bool bVar1;
  bool bVar2;
  int local_20 [7];
  
                    /* 0x60d50  168   */
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[6] = 1;
  bVar2 = *(short *)(*(int *)(param_1 + 0x2c) + 0x10) == 1;
  if ((*(int *)(param_1 + 0x754) == 0) || (bVar1 = true, param_3 == 0)) {
    bVar1 = false;
  }
  *(int *)(param_1 + 0x754) = param_2;
  Ordinal_360(*(int **)(param_1 + 0x20),(undefined4 ***)0x0,0x31,(double *)local_20);
  if ((local_20[0] < 10) && (param_3 != 0)) {
    local_20[6] = 0;
  }
  if (param_2 == 0) {
    sprites_setCursorVisible(param_1,1);
    if ((bVar2) && (local_20[6] != 0)) {
      sprites_handleEditCommand(param_1,0x12);
      return 0;
    }
  }
  else if (((bVar2) && (!bVar1)) && (local_20[6] != 0)) {
    sprites_handleEditCommand(param_1,0x11);
  }
  return 0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: Ordinal_4102
// Address: 68060e20
// Size: 34 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_4102(int param_1)

{
  bool bVar1;
  
                    /* 0x60e20  4102   */
  bVar1 = *(int *)(param_1 + 0x734) != 0;
  if (bVar1) {
    sprites_finalizeSpriteOps(*(int *)(param_1 + 0xc));
  }
  return bVar1;
}



// ============================================================
// Function: Ordinal_946
// Address: 68060e50
// Size: 118 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_946(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
                    /* 0x60e50  946   */
  iVar4 = param_2;
  iVar1 = *param_1;
  iVar2 = **(int **)(iVar1 + 4);
  uVar3 = *(undefined4 *)(iVar2 + 0x20);
  *(undefined4 *)(iVar2 + 0x20) = 0;
  if (*(short *)(param_1[0xb] + 0x10) == 1) {
    events_dispatchSpriteHandlers(param_1,(byte *)0x0,0,0x380 - (param_2 != 0),0,(uint *)0x0,(int *)0x0,
                 (int *)&param_1);
  }
  events_dispatchGlobalEvent(iVar1,0x380 - (iVar4 != 0),0,(uint *)0x0,(int *)0x0,(int *)&param_1);
  *(undefined4 *)(iVar2 + 0x20) = uVar3;
  return 0;
}



// ============================================================
// Function: Ordinal_4103
// Address: 68060ed0
// Size: 261 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4103(int param_1,undefined4 param_2)
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0x60ed0  4103   */
  bVar2 = false;
  bVar1 = false;
  switch(param_2) {
  case 0:
    if (*(int *)(param_1 + 0x764) == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x764) = 0;
    break;
  case 1:
    if (*(int *)(param_1 + 0x764) != 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x764) = 1;
    iVar3 = Ordinal_1546();
    *(int *)(param_1 + 0x76c) = *(int *)(param_1 + 0x76c) + (*(int *)(param_1 + 0x770) - iVar3);
    iVar3 = Ordinal_1541();
    *(int *)(param_1 + 0x774) = *(int *)(param_1 + 0x774) + (*(int *)(param_1 + 0x778) - iVar3);
    break;
  case 0xfffffffe:
    if ((*(int *)(param_1 + 0x768) == 1) && (*(int *)(param_1 + 0x764) != 0)) {
      bVar2 = true;
    }
    *(undefined4 *)(param_1 + 0x768) = 2;
    goto LAB_68060f93;
  case 0xffffffff:
    if ((*(int *)(param_1 + 0x768) == 2) && (*(int *)(param_1 + 0x764) != 0)) {
      bVar2 = true;
      bVar1 = true;
    }
    *(undefined4 *)(param_1 + 0x768) = 1;
    if (bVar1) {
      iVar3 = Ordinal_1546();
      *(int *)(param_1 + 0x76c) =
           *(int *)(param_1 + 0x76c) + (iVar3 - *(int *)(param_1 + 0x770)) * 2;
      iVar3 = Ordinal_1541();
      *(int *)(param_1 + 0x774) =
           *(int *)(param_1 + 0x774) + (iVar3 - *(int *)(param_1 + 0x778)) * 2;
    }
LAB_68060f93:
    if (!bVar2) {
      return 0;
    }
    break;
  default:
    goto switchD_68060eeb_default;
  }
  uVar4 = Ordinal_1546();
  *(undefined4 *)(param_1 + 0x770) = uVar4;
  uVar4 = Ordinal_1541();
  *(undefined4 *)(param_1 + 0x778) = uVar4;
switchD_68060eeb_default:
  return 0;
}



// ============================================================
// Function: Ordinal_4104
// Address: 68060ff0
// Size: 26 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4104(int *param_1)
{
                    /* 0x60ff0  4104   */
  if (*param_1 != 0) {
    *(undefined4 *)(*param_1 + 0x664) = 1;
  }
  return 0;
}



// ============================================================
// Function: events_getXtraPalette (events_getXtraPalette)
// Address: 68061010
// Size: 23 bytes
// Params: int param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_getXtraPalette(int param_1,void *param_2)
{
  cast_getXtraPalette(*(undefined4 *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: events_resetPuppetSprites (events_resetPuppetSprites)
// Address: 68061030
// Size: 80 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_resetPuppetSprites(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = param_1;
  iVar2 = Ordinal_165(*(int *)(param_1 + 0x20),param_2,&param_1);
  iVar4 = 0;
  if (-1 < param_1) {
    puVar3 = (undefined4 *)(iVar2 + 0x24);
    do {
      if ((puVar3[-1] == 4) && ((int *)*puVar3 != (int *)0x0)) {
        media_dispatchDestroy(*(int *)(iVar1 + 0x20),(int *)*puVar3);
        *puVar3 = 0;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0xd;
    } while (iVar4 <= param_1);
  }
  return 0;
}



// ============================================================
// Function: events_copyCastMember (FUN_68061080)
// Address: 68061080
// Size: 97 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int events_copyCastMember(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = Ordinal_165(*(int *)(param_1 + 0x20),param_2,&param_2);
  if (param_3 <= param_2) {
    if (param_4 == 1) {
      return (int)*(char *)(param_3 * 0x34 + 0x30 + iVar1);
    }
    if (param_4 == 2) {
      return *(int *)(param_3 * 0x34 + 0x2c + iVar1);
    }
    if (param_4 == 3) {
      return (int)*(char *)(param_3 * 0x34 + 0x31 + iVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: events_setCastSlotData (events_setCastSlotData)
// Address: 680610f0
// Size: 91 bytes
// Params: int param_1, int param_2, int param_3, int param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_setCastSlotData(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)
{
  int iVar1;
  
  iVar1 = Ordinal_165(*(int *)(param_1 + 0x20),param_2,&param_2);
  if (param_3 <= param_2) {
    if (param_4 == 1) {
      *(undefined1 *)(param_3 * 0x34 + 0x30 + iVar1) = (undefined1)param_5;
      return 0;
    }
    if (param_4 == 2) {
      *(undefined4 *)(param_3 * 0x34 + 0x2c + iVar1) = param_5;
      return 0;
    }
    if (param_4 == 3) {
      *(undefined1 *)(param_3 * 0x34 + 0x31 + iVar1) = (undefined1)param_5;
    }
  }
  return 0;
}




