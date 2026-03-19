// Module: props
// Topic: Handler install, remove, dispatch, call
// Address range: 0x68030dd0 - 0x680378a0
// Functions (26):
//   props_initHandlerEntry (FUN_68030dd0)
//   props_resolveHandler (FUN_68030e10)
//   props_invokeMethod (FUN_68031310)
//   props_invalidateHandler (FUN_68031550)
//   props_resetHandlerSlot (FUN_680315b0)
//   props_getHandlerValue (FUN_68031610)
//   props_installHandler (FUN_68031650)
//   props_installHandlers (FUN_680316f0)
//   props_refreshHandlers (FUN_68031750)
//   props_removeHandlers (FUN_680317b0)
//   props_invalidateTableEntry (FUN_680329a0)
//   props_setHandlerSlot (FUN_68032ba0)
//   props_callNative (FUN_68033820)
//   props_callNativeHandler (FUN_68033a70)
//   props_bindNativeHandler (FUN_68033ab0)
//   props_tryCallHandler (FUN_68033af0)
//   props_dispatchHandler (FUN_68033b80)
//   props_callHandler (FUN_68033c90)
//   props_defaultHandler (FUN_68033d00)
//   props_callMethod (FUN_68033d40)
//   props_invokeHandler (FUN_68033f10)
//   props_callPropertyHandler (FUN_680343e0)
//   props_getHandlerPropertyId (FUN_68034450)
//   props_enterHandler (FUN_680344a0)
//   props_dispatchMessage (FUN_68037830)
//   props_executeHandler (FUN_680378a0)



// ============================================================
// Function: props_initHandlerEntry
// Address: 68030dd0
// Size: 50 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_initHandlerEntry(int *param_1,int param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*param_1 + 0x20 + param_2 * 0x18);
  puVar1[1] = param_3;
  puVar1[2] = 0xffffffff;
  *puVar1 = props_defaultHandler;
  puVar1[3] = 0xffffffff;
  puVar1[4] = 0;
  return 0;
}



// ============================================================
// Function: props_resolveHandler
// Address: 68030e10
// Size: 115 bytes
// Params: int param_1, uint param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint props_resolveHandler(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    return param_2;
  }
  puVar3 = score_lookupProperty(*(int **)(param_1 + 0x24),param_2,param_3,&param_2);
  if (puVar3 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (*puVar3 == 4) {
    return puVar3[1];
  }
  uVar1 = *(uint *)(**(int **)(param_1 + 0x28) + 0x10);
  *puVar3 = 4;
  puVar3[1] = uVar1;
  stage_emitStoreVar(*(int **)(param_1 + 0x28),uVar1);
  props_initHandlerEntry(*(int **)(param_1 + 0x28),uVar1,uVar2);
  return uVar1;
}



// ============================================================
// Function: props_invokeMethod (FUN_68031310)
// Address: 68031310
// Size: 34 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_invokeMethod(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)
{
  (**(code **)(*(int *)*param_2 + 0x18))(param_1,param_2,0,param_3,param_4);
  return 0;
}



// ============================================================
// Function: props_invalidateHandler (FUN_68031550)
// Address: 68031550
// Size: 91 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_invalidateHandler(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = **(int **)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x2c +
                    *(int *)(*param_2 + 0x20) * 0x18);
  iVar2 = iVar1 + 0xa8 + *(int *)(*param_2 + 0x1c) * 0x10;
  iVar3 = *(int *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 4) = 0xffffffff;
  if ((iVar3 != -1) && (iVar2 = *(int *)(iVar1 + 0x24), iVar2 != 0)) {
    iVar2 = events_setEditProperty(param_1,iVar2);
    sprites_getNetUrl(param_1,iVar2,iVar3);
  }
  return 0;
}



// ============================================================
// Function: props_resetHandlerSlot (FUN_680315b0)
// Address: 680315b0
// Size: 90 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_resetHandlerSlot(undefined4 param_1,int param_2)
{
  undefined4 *puVar1;
  int *in_EAX;
  int iVar2;
  int unaff_EDI;
  int iVar3;
  
  iVar2 = *in_EAX;
  if ((-1 < param_2) && (param_2 < *(int *)(iVar2 + 0x14))) {
    puVar1 = (undefined4 *)(iVar2 + 0xa8 + param_2 * 0x10);
    iVar3 = puVar1[1];
    *puVar1 = 0;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0;
    puVar1[3] = *(undefined4 *)(iVar2 + 0x38);
    *(uint *)(iVar2 + 0x34) = *(uint *)(iVar2 + 0x34) | 1;
    *(int *)(iVar2 + 0x38) = param_2;
    if ((iVar3 != -1) && (*(int *)(iVar2 + 0x24) != 0)) {
      iVar2 = events_setEditProperty(unaff_EDI,*(int *)(iVar2 + 0x24));
      sprites_getNetUrl(unaff_EDI,iVar2,iVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: props_getHandlerValue (FUN_68031610)
// Address: 68031610
// Size: 42 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getHandlerValue(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(**(int **)(param_1 + 0x2c) + 0x14))) {
    return *(undefined4 *)(**(int **)(param_1 + 0x2c) + 0xa8 + param_2 * 0x10);
  }
  return 0;
}



// ============================================================
// Function: props_installHandler (FUN_68031650)
// Address: 68031650
// Size: 154 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_installHandler(int param_1,undefined4 param_2,int param_3)
{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *unaff_EBX;
  int unaff_EDI;
  
  if (-1 < unaff_EDI) {
    iVar3 = **(int **)(**(int **)(param_1 + 8) + 0x4f4);
    iVar4 = *(int *)(*unaff_EBX + 0x20);
    if ((iVar3 != 0) && (iVar4 < *(int *)(iVar3 + 0x14))) {
      iVar5 = *(int *)(*unaff_EBX + 0x5c);
      iVar3 = iVar3 + 0x24 + iVar4 * 0x18;
      piVar6 = *(int **)(iVar3 + 8);
      iVar3 = **(int **)(iVar3 + 4);
      if (((iVar3 != 0) && (unaff_EDI < *(int *)(iVar3 + 0x14))) &&
         ((puVar2 = (undefined4 *)(iVar3 + 0x20 + unaff_EDI * 0x18),
          *(code **)(iVar3 + 0x20 + unaff_EDI * 0x18) != props_getStackDepth ||
          (puVar1 = (uint *)(*piVar6 + 0x34), *puVar1 = *puVar1 | 8, iVar5 <= (int)puVar2[5])))) {
        *puVar2 = props_getStackDepth;
        puVar2[3] = *(undefined4 *)(*unaff_EBX + 0x1c);
        puVar2[4] = param_2;
        puVar2[5] = iVar5;
        if (-1 < param_3) {
          *(int *)(*piVar6 + 0x44 + param_3 * 4) = unaff_EDI;
        }
        core_notifyAsyncXtra(param_1,unaff_EBX,puVar2[1],1);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: props_installHandlers (FUN_680316f0)
// Address: 680316f0
// Size: 81 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_installHandlers(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_2;
  iVar1 = *(int *)(*param_2 + 0x80);
  iVar3 = 0;
  if (0 < iVar1) {
    param_2 = (int *)0x0;
    do {
      props_installHandler(param_1,iVar3,*(int *)((int)param_2 + *piVar2 + *(int *)(*piVar2 + 0x84) + 4));
      param_2 = param_2 + 0xf;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}



// ============================================================
// Function: props_refreshHandlers (FUN_68031750)
// Address: 68031750
// Size: 79 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_refreshHandlers(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  
  *(uint *)(*unaff_EDI + 0x34) = *(uint *)(*unaff_EDI + 0x34) & 0xfffffff7;
  iVar2 = *(int *)(*unaff_EDI + 0x10);
  if (0 < iVar2) {
    iVar3 = 0;
    do {
      piVar1 = *(int **)(iVar3 + 0xa8 + *unaff_EDI);
      if (((piVar1 != (int *)0x0) && ((*(uint *)(*piVar1 + 0x54) & 2) != 0)) &&
         ((*(uint *)(*piVar1 + 0x54) & 0x1000) == 0)) {
        props_installHandlers(param_1,piVar1);
      }
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}



// ============================================================
// Function: props_removeHandlers (FUN_680317b0)
// Address: 680317b0
// Size: 209 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_removeHandlers(int param_1,int *param_2,int param_3)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  int *piVar7;
  int iVar8;
  
  piVar7 = param_2;
  iVar3 = *param_2;
  iVar8 = *(int *)(iVar3 + 0x84);
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x24 + *(int *)(iVar3 + 0x20) * 0x18;
  piVar4 = *(int **)(iVar1 + 4);
  piVar5 = *(int **)(iVar1 + 8);
  param_2 = *(int **)(iVar3 + 0x80);
  iVar1 = *(int *)(iVar3 + 0x5c);
  bVar6 = false;
  if (0 < (int)param_2) {
    do {
      iVar3 = *piVar7;
      puVar2 = (undefined4 *)(*piVar4 + 0x20 + *(int *)(iVar3 + iVar8) * 0x18);
      if (puVar2[5] == iVar1) {
        *puVar2 = props_defaultHandler;
        puVar2[3] = 0xffffffff;
        puVar2[4] = 0;
        puVar2[5] = 0;
        iVar3 = *(int *)(iVar3 + 4 + iVar8);
        if (-1 < iVar3) {
          *(undefined4 *)(*piVar5 + 0x44 + iVar3 * 4) = 0xffffffff;
          bVar6 = true;
        }
      }
      core_notifyAsyncXtra(param_1,piVar7,puVar2[1],0);
      iVar8 = iVar8 + 0x3c;
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
  }
  if ((param_3 != 0) && (bVar6)) {
    props_refreshHandlers(param_1);
  }
  return 0;
}



// ============================================================
// Function: props_invalidateTableEntry (FUN_680329a0)
// Address: 680329a0
// Size: 265 bytes
// Params: uint param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// Invalidates a handler table entry, releasing child contexts
// ============================================================

int props_invalidateTableEntry(uint param_1,int *param_2,int param_3,int param_4)
{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  piVar2 = *(int **)(*param_2 + 0x2c + param_3 * 0x18);
  if (piVar2 != (int *)0x0) {
    *(uint *)(*piVar2 + 0x34) = *(uint *)(*piVar2 + 0x34) & 0xfffffffd;
    Ordinal_1130(**(undefined4 **)(*param_2 + 0x34 + param_3 * 0x18),0x14);
    if (param_4 == 0) {
      *(undefined4 *)(*piVar2 + 0x24) = 0;
    }
    else {
      iVar4 = events_setEditProperty(param_1,*(int *)(*piVar2 + 0x24));
      if (iVar4 != 0) {
        if (*(int *)(*piVar2 + 0x28) != -1) {
          sprites_getNetUrl(param_1,iVar4,*(int *)(*piVar2 + 0x28));
        }
        if (*(int *)(*piVar2 + 0x2c) != -1) {
          sprites_getNetUrl(param_1,iVar4,*(int *)(*piVar2 + 0x2c));
        }
      }
    }
    local_8 = *(int *)(*piVar2 + 0x10);
    if (0 < local_8) {
      iVar4 = 0;
      do {
        piVar3 = *(int **)(*piVar2 + 0xa8 + iVar4);
        if ((piVar3 != (int *)0x0) && ((*(byte *)(*piVar3 + 0x54) & 0x80) == 0)) {
          if (param_4 != 0) {
            props_invalidateHandler(param_1,piVar3);
          }
          iVar5 = props_releaseContext(param_1,piVar3);
          if (iVar5 != 0) {
            *(undefined4 *)(*piVar2 + 0xa8 + iVar4) = 0;
          }
        }
        iVar4 = iVar4 + 0x10;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
    if (*(int *)(*piVar2 + 0x30) < 1) {
      props_freeTableEntry(param_1,param_2,param_3);
      return 0;
    }
    puVar1 = (uint *)(*piVar2 + 0x34);
    *puVar1 = *puVar1 | 2;
  }
  return 0;
}



// ============================================================
// Function: props_setHandlerSlot (FUN_68032ba0)
// Address: 68032ba0
// Size: 275 bytes
// Params: void * param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// Sets a handler slot by creating a new context from a script reference
// ============================================================

int props_setHandlerSlot(void *param_1,int *param_2,int param_3,int *param_4)
{
  undefined4 *local_46c;
  int *local_468;
  undefined4 local_464 [279];
  uint local_8;
  
  if (param_4[1] == 0) {
    local_46c = (undefined4 *)0x0;
  }
  else {
    local_46c = props_detachString((int)param_1,param_4);
    *param_4 = 0;
  }
  local_468 = *(int **)(*param_2 + param_3 * 4);
  if (local_468 != (int *)0x0) {
    props_suspendContext((int)param_1,local_468);
    props_releaseContext((uint)param_1,local_468);
    *(undefined4 *)(*param_2 + param_3 * 4) = 0;
  }
  if (local_46c != (undefined4 *)0x0) {
    props_parseToken(local_464,local_46c);
    stage_compileHandlerScope(param_1,local_464,-1,5,0,0,&local_468);
    if (local_468 != (int *)0x0) {
      props_retainObject(param_1,local_468);
      *(int **)(*param_2 + param_3 * 4) = local_468;
      return 0;
    }
    *(undefined4 *)(*param_2 + param_3 * 4) = 0;
    return 0;
  }
  *(undefined4 *)(*param_2 + param_3 * 4) = 0;
  return 0;
}



// ============================================================
// Function: props_callNative (FUN_68033820)
// Address: 68033820
// Size: 569 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_callNative(int param_1,int param_2)
{
  int local_18;
  char cVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  ulonglong uVar8;
  char *local_34;
  int local_30;
  int local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  /* FIXUP(C2040: 'local_18': 'int): int local_18 [4]; */
  uint local_8;
  
  iVar3 = **(int **)(**(int **)(param_1 + 8) + 0x4f0);
  iVar5 = (param_2 + 2) * 0x10;
  pcVar2 = *(code **)(iVar3 + iVar5);
  iVar3 = iVar3 + iVar5;
  local_20 = *(undefined4 *)(iVar3 + 8);
  local_2c = (int)(char)local_20;
  local_1c = *(undefined4 *)(iVar3 + 0xc);
  local_30 = 0;
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(iVar3 + 4);
  if (local_2c == 0x2d) {
    local_2c = 0;
  }
  else if (local_2c == 0x2a) {
    local_2c = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0x20) & 0x80000000) == 0) {
      props_setError(param_1,0x1b);
      return 0;
    }
    if (local_2c == 100) {
      local_2c = 4;
    }
    else if (local_2c == 0x6f) {
      local_2c = 6;
    }
    else if (local_2c == 0x78) {
      local_2c = 0;
    }
  }
  iVar3 = (int)(char)((uint)local_20 >> 8);
  local_34 = (char *)((int)&local_20 + 2);
  iVar5 = iVar3 + -0x30;
  if ((-1 < iVar5) && (iVar4 = props_getInt(param_1), iVar4 != iVar5)) {
    props_setError(param_1,iVar3 + -0x1c);
    return 0;
  }
  if (local_2c == 0) {
    (*pcVar2)(param_1);
    return 0;
  }
  piVar7 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  iVar3 = 0;
  if (0 < iVar5) {
    do {
      cVar1 = *local_34;
      local_34 = local_34 + 1;
      if (cVar1 == 'd') {
        iVar4 = *piVar7;
        iVar6 = iVar5;
        if (iVar4 != 0x20) {
          if (iVar4 != 0x23) {
            if (iVar4 != 4) {
              props_setErrorAndReturn(param_1,7);
              return 0;
            }
            goto LAB_6803399c;
          }
          iVar6 = piVar7[1];
        }
        uVar8 = strings_floatToUint64(local_34,iVar6);
        ((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */iVar3] = (int)uVar8;
      }
      else {
        if ((cVar1 == 'o') && (*piVar7 != 6)) {
          props_setErrorAndReturn(param_1,0xc);
          return 0;
        }
LAB_6803399c:
        ((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */iVar3] = piVar7[1];
      }
      iVar3 = iVar3 + 1;
      piVar7 = piVar7 + 2;
    } while (iVar3 < iVar5);
  }
  switch(iVar5) {
  case 0:
    local_30 = (*pcVar2)(param_1);
    break;
  case 1:
    local_30 = (*pcVar2)(param_1,((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */0]);
    break;
  case 2:
    local_30 = (*pcVar2)(param_1,((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */0],((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */1]);
    break;
  case 3:
    local_30 = (*pcVar2)(param_1,((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */0],((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */1],((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */2]);
    break;
  case 4:
    local_30 = (*pcVar2)(param_1,((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */0],((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */1],((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */2],((int *)(size_t)local_18)[ /* FIXUP(C2109): cast to pointer for subscript */3]);
  }
  props_normalizeType(param_1,local_2c,local_30);
  return 0;
}



// ============================================================
// Function: props_callNativeHandler (FUN_68033a70)
// Address: 68033a70
// Size: 56 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_callNativeHandler(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xa4);
  if ((-1 < iVar1) && (iVar1 < *(int *)(**(int **)(param_1 + 0x28) + 0x14))) {
    props_callNative(param_1,*(int *)(**(int **)(param_1 + 0x28) + (iVar1 * 3 + 6) * 8));
    return 0;
  }
  props_setError(param_1,0x33);
  return 0;
}



// ============================================================
// Function: props_bindNativeHandler (FUN_68033ab0)
// Address: 68033ab0
// Size: 64 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall props_bindNativeHandler(void *this,undefined4 param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 0xa4);
  if ((-1 < iVar2) && (iVar2 < *(int *)(**(int **)((int)this + 0x28) + 0x14))) {
    puVar1 = (undefined4 *)(**(int **)((int)this + 0x28) + 0x20 + iVar2 * 0x18);
    *puVar1 = props_callNativeHandler;
    puVar1[4] = param_1;
    props_callNativeHandler((int)this);
    return 0;
  }
  props_setError((int)this,0x33);
  return 0;
}



// ============================================================
// Function: props_tryCallHandler (FUN_68033af0)
// Address: 68033af0
// Size: 131 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_tryCallHandler(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = score_lookupProperty(*(int **)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x24 +
                                 param_2 * 0x18),param_3,0,(uint *)0x0);
  if ((puVar1 != (uint *)0x0) &&
     (*(code **)(**(int **)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x28 + param_2 * 0x18) +
                 0x20 + puVar1[1] * 0x18) == props_getStackDepth)) {
    *(uint *)(param_1 + 0xa4) = puVar1[1];
    props_selectScript(param_1,param_2);
    props_getStackDepth(param_1);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_dispatchHandler (FUN_68033b80)
// Address: 68033b80
// Size: 228 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_dispatchHandler(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint unaff_EBX;
  void *unaff_ESI;
  int iVar5;
  
  iVar1 = events_navigateToFrameEx((int)unaff_ESI);
  iVar5 = 1;
  if (0 < iVar1) {
    do {
      uVar2 = events_navigateToFrame((int)unaff_ESI,(ushort)iVar5);
      iVar3 = uVar2 - 1;
      if (((-1 < iVar3) && (iVar3 != param_1)) &&
         (iVar3 = props_tryCallHandler((int)unaff_ESI,iVar3,unaff_EBX), iVar3 != 0)) {
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar1);
  }
  puVar4 = score_lookupProperty(*(int **)(**(int **)((int)unaff_ESI + 8) + 0x4e8),unaff_EBX,0,(uint *)0x0);
  if (((puVar4 == (uint *)0x0) || (*puVar4 != 3)) ||
     (iVar1 = (**(code **)(**(int **)puVar4[1] + 4))(), iVar1 == 0)) {
    puVar4 = score_lookupProperty(*(int **)(**(int **)((int)unaff_ESI + 8) + 0x4ec),unaff_EBX,0,(uint *)0x0)
    ;
    if (puVar4 != (uint *)0x0) {
      props_bindNativeHandler(unaff_ESI,puVar4[1]);
      return 0;
    }
    iVar1 = 4;
    switch(unaff_EBX) {
    case 0xcb:
    case 0xcc:
    case 0xce:
    case 0xcf:
    case 0xd0:
    case 0xd1:
    case 0xd2:
    case 0xd3:
    case 0xd5:
    case 0xd7:
    case 0xd8:
    case 0xd9:
    case 0xda:
    case 0xdc:
    case 0xdd:
    case 0xde:
    case 0xdf:
    case 0xe0:
    case 0xe1:
    case 0xe2:
    case 0xe3:
    case 0xe4:
      props_reportError((int)unaff_ESI,0x6a);
      return 0;
    case 0xcd:
    case 0xd4:
    case 0xd6:
    case 0xdb:
      iVar1 = 0x6b;
    }
    props_reportError((int)unaff_ESI,iVar1);
  }
  return 0;
}



// ============================================================
// Function: props_callHandler (FUN_68033c90)
// Address: 68033c90
// Size: 98 bytes
// Params: int param_1, uint param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool props_callHandler(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 < 0) {
    uVar2 = events_navigateToFrame(param_1,1);
    if ((int)uVar2 < 1) {
      iVar3 = 0;
    }
    else {
      uVar2 = events_navigateToFrame(param_1,1);
      iVar3 = (int)(short)((short)uVar2 + -1);
    }
    props_selectScript(param_1,iVar3);
  }
  uVar4 = props_resolveSymbol(param_1,param_2);
  *(undefined4 *)(param_1 + 0xa4) = uVar4;
  props_dispatchHandler(-1);
  if (-1 < iVar1) {
    props_selectScript(param_1,iVar1);
  }
  return *(int *)(param_1 + 0x7c) == 0;
}



// ============================================================
// Function: props_defaultHandler (FUN_68033d00)
// Address: 68033d00
// Size: 63 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_defaultHandler(int param_1)
{
  if ((-1 < *(int *)(param_1 + 0xa4)) &&
     (*(int *)(param_1 + 0xa4) < *(int *)(**(int **)(param_1 + 0x28) + 0x14))) {
    props_dispatchHandler(*(int *)(param_1 + 0x3c));
    return 0;
  }
  props_setError(param_1,0x33);
  return 0;
}



// ============================================================
// Function: props_callMethod (FUN_68033d40)
// Address: 68033d40
// Size: 451 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_callMethod(uint param_1,int param_2)
{
  uint uVar1;
  bool bVar2;
  uint *puVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_c;
  undefined4 *local_8;
  
  iVar7 = param_2;
  uVar1 = param_1;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar4 = **(int **)(param_1 + 0x10);
  uVar6 = *(uint *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar4 + 4 + *(int *)(param_1 + 0x18));
  puVar3 = props_dispatchVariable(param_1,param_2,uVar6,0);
  if (*(int *)(uVar1 + 0x7c) != 0) {
    return 0;
  }
  if ((puVar3 != (uint *)0x0) && (*puVar3 == 6)) {
    bVar2 = stage_checkCallbackOwner(uVar1,(undefined4 *)puVar3[1]);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return 0;
    }
    puVar3 = props_dispatchVariable(uVar1,iVar7,uVar6,0);
    if (*puVar3 != 6) {
      return 0;
    }
    if (puVar3[1] != *(uint *)(**(int **)(uVar1 + 8) + 0x508)) {
      return 0;
    }
    *puVar3 = 2;
    puVar3[1] = 0;
    return 0;
  }
  iVar4 = **(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8;
  if ((*(byte *)(**(int **)(uVar1 + 0x50) + 0x54) & 8) == 0) {
    puVar3 = score_lookupProperty(*(int **)(**(int **)(uVar1 + 8) + 0x4e4),
                          *(uint *)(iVar4 + *(int *)(uVar1 + 0x18) + 4),1,&param_1);
    *(uint *)(uVar1 + 0xb8) = param_1;
  }
  else {
    iVar4 = iVar4 + *(int *)(uVar1 + 0x18);
    if (iVar4 == 0) goto LAB_68033ef2;
    iVar9 = 0;
    iVar8 = 0;
    uVar5 = props_resolveSymbol(uVar1,*(uint *)(iVar4 + 4));
    puVar3 = props_resolveVariable(uVar1,uVar5,iVar8,iVar9);
  }
  if (puVar3 == (uint *)0x0) {
    props_reportError(uVar1,0x32);
    return 0;
  }
  local_c = *puVar3;
  local_8 = (undefined4 *)puVar3[1];
  props_retainValue(uVar1,&local_c);
  iVar8 = **(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8;
  iVar4 = *(int *)(uVar1 + 0x18);
  *(uint *)(iVar8 + iVar4) = local_c;
  *(undefined4 **)(iVar8 + 4 + iVar4) = local_8;
  uVar6 = props_varRefToSymRef(uVar1,iVar7,uVar6);
  *(uint *)(uVar1 + 0xa4) = uVar6;
  iVar4 = **(int **)(uVar1 + 0x28);
  if ((-1 < (int)uVar6) && ((int)uVar6 < *(int *)(iVar4 + 0x14))) {
    if ((local_c == 3) &&
       (iVar7 = (**(code **)(*(int *)*local_8 + 4))
                          (uVar1,local_8,*(undefined4 *)(iVar4 + 0x24 + uVar6 * 0x18)), iVar7 != 0))
    {
      return 0;
    }
    (**(code **)(iVar4 + 0x20 + *(int *)(uVar1 + 0xa4) * 0x18))(uVar1);
    return 0;
  }
LAB_68033ef2:
  props_setError(uVar1,0x33);
  return 0;
}



// ============================================================
// Function: props_invokeHandler (FUN_68033f10)
// Address: 68033f10
// Size: 153 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_invokeHandler(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  *(int *)(param_1 + 0xa4) = param_2;
  if ((*(int *)(**(int **)(param_1 + 0x28) + 0x10) <= param_2) || (param_2 < 0)) {
    props_setError(param_1,0x1b);
    return 0;
  }
  if ((*(int *)(param_1 + 0xdc) == 0) &&
     (((iVar2 = props_getInt(param_1), 0 < iVar2 &&
       (piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                        *(int *)(param_1 + 0x18)), *piVar3 == 3)) &&
      (puVar1 = (undefined4 *)piVar3[1],
      iVar2 = (**(code **)(*(int *)*puVar1 + 4))
                        (param_1,puVar1,
                         *(undefined4 *)
                          (**(int **)(param_1 + 0x28) + 0x24 + *(int *)(param_1 + 0xa4) * 0x18)),
      iVar2 != 0)))) {
    return 0;
  }
  (**(code **)(**(int **)(param_1 + 0x28) + 0x20 + *(int *)(param_1 + 0xa4) * 0x18))(param_1);
  return 0;
}



// ============================================================
// Function: props_callPropertyHandler (FUN_680343e0)
// Address: 680343e0
// Size: 112 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Looks up and calls a native handler by property id
// ============================================================

int props_callPropertyHandler(int param_1,int param_2)
{
  uint *puVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(**(int **)(param_1 + 0x28) + 0x14))) {
    *(int *)(param_1 + 0xa4) = param_2;
    puVar1 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4ec),
                          *(uint *)(**(int **)(param_1 + 0x28) + 0x24 + param_2 * 0x18),0,
                          (uint *)0x0);
    if (puVar1 != (uint *)0x0) {
      props_callNative(param_1,puVar1[1]);
      return 0;
    }
    props_reportError(param_1,4);
    return 0;
  }
  props_setError(param_1,0x33);
  return 0;
}



// ============================================================
// Function: props_getHandlerPropertyId (FUN_68034450)
// Address: 68034450
// Size: 72 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// Resolves a handler's property id from its slot index
// ============================================================

undefined4 __fastcall props_getHandlerPropertyId(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  
  if (in_EAX < *(int *)(**(int **)(param_2 + 0x50) + 0x80)) {
    iVar1 = *(int *)(*(int *)(**(int **)(param_2 + 0x50) + 0x84) + in_EAX * 0x3c +
                    **(int **)(param_2 + 0x50));
    if ((-1 < iVar1) && (iVar1 < *(int *)(**(int **)(param_2 + 0x28) + 0x14))) {
      return *(undefined4 *)(**(int **)(param_2 + 0x28) + 0x24 + iVar1 * 0x18);
    }
  }
  props_setError(param_2,0x33);
  return 0;
}



// ============================================================
// Function: props_enterHandler (FUN_680344a0)
// Address: 680344a0
// Size: 126 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// Enters a handler, setting up handler tracking and flow state
// ============================================================

int props_enterHandler(int param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  if ((*(int *)(param_1 + 0xdc) == 0) && (iVar2 = props_getInt(param_1), 0 < iVar2)) {
    piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                    *(int *)(param_1 + 0x18));
    if (*piVar3 == 3) {
      puVar1 = (undefined4 *)piVar3[1];
      iVar2 = *(int *)*puVar1;
      uVar4 = props_getHandlerPropertyId(*(int *)(param_1 + 0x20) * 8,param_1);
      iVar2 = (**(code **)(iVar2 + 4))(param_1,puVar1,uVar4);
      if (iVar2 != 0) {
        return 0;
      }
    }
  }
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x74) = 2;
  return 0;
}



// ============================================================
// Function: props_dispatchMessage
// Address: 68037830
// Size: 98 bytes
// Params: int param_1, uint param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool props_dispatchMessage(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = props_getInt(param_1);
  if (0 < iVar2) {
    piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                    *(int *)(param_1 + 0x18));
    if (piVar3 == (int *)0x0) {
      return false;
    }
    if (*piVar3 == 3) {
      iVar2 = (**(code **)(**(int **)piVar3[1] + 4))(param_1,(undefined4 *)piVar3[1],param_2);
      if (iVar2 != 0) {
        return true;
      }
    }
  }
  bVar1 = props_callHandler(param_1,param_2);
  return bVar1;
}



// ============================================================
// Function: props_executeHandler
// Address: 680378a0
// Size: 74 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, uint param_4, int * param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool props_executeHandler(int *param_1,int *param_2,undefined4 param_3,uint param_4,int *param_5)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  sprites_allocMemory((int)param_1);
  iVar1 = param_1[0x1d];
  if (param_1[0x4e] == 0) {
    bVar2 = props_dispatchOpcode(param_1,param_2,param_3,param_4);
  }
  sprites_freeMemory((int)param_1);
  *param_5 = param_1[0x1d];
  param_1[0x1d] = iVar1;
  return bVar2;
}


