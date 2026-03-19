// Module: core
// Topic: Stack manipulation, argument handling, and handler invocation
// Address range: 0x68015160 - 0x68016090
// Functions (10):
//   core_dispatchHandlerList (0x68015160)
//   core_invokeHandlers (0x680156B0)
//   core_formatCallError (0x680156F0)
//   core_removeStackArgs (0x68015780)
//   core_getStackState (0x68015810)
//   core_popAndDispatch (0x68015880)
//   core_validateHandlerType (0x68015900)
//   core_getHandlerCount (0x68015970)
//   core_returnTrue (0x68016080)
//   core_validateStackType (0x68016090)

// ============================================================
// Function: core_dispatchHandlerList (core_dispatchHandlerList)
// Address: 68015160
// Size: 754 bytes
// Params: int * param_1, char param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_dispatchHandlerList(int *param_1,char param_2)
{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  uint local_4c;
  int *local_48;
  uint local_44;
  int *local_40;
  uint local_3c;
  int *local_38;
  uint local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  if (param_2 == '\0') {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    iVar2 = 1;
  }
  else {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    iVar2 = 2;
  }
  local_8 = *(int **)(*param_1 + 0x10);
  local_c = *(int **)(*param_1 + 0xc);
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 != iVar2) {
    props_setError(unaff_ESI,0x15);
    return 0;
  }
  _DAT_68197764 =
       (uint *)(**(int **)(unaff_ESI + 0x10) + -8 + (iVar2 - *(int *)(unaff_ESI + 0x20)) * 8 +
               *(int *)(unaff_ESI + 0x18));
  local_20 = DAT_6819776c;
  local_24 = DAT_68197768;
  if (_DAT_68197764 != (uint *)0x0) {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    local_20 = (int *)((int *)(size_t)_DAT_68197764)[1];
    local_24 = *(int *)(size_t)_DAT_68197764;
  }
  iVar2 = score_getProplistValue(unaff_ESI,(int *)&local_24);
  if (iVar2 != 0) {
    iVar1 = 0;
    local_10 = 0;
    local_14 = local_20;
    iVar2 = props_getListLength(unaff_ESI,local_20);
    local_1c = iVar2;
    if (0 < iVar2) {
      do {
        score_setProplistValue(unaff_ESI,local_14,iVar1,&local_2c,&local_24);
        props_resolveValue(unaff_ESI,&local_2c);
        if (local_2c == 8) {
          if ((int)local_28 < 0x214) {
            if (0x210 < (int)local_28) goto LAB_680153ef;
            if ((int)local_28 < 0x13a) {
              if ((local_28 == (int *)0x139) ||
                 (((local_28 == (int *)0xbc || (local_28 == (int *)0xfc)) ||
                  (local_28 == (int *)0x103)))) goto LAB_680153ef;
            }
            else if ((local_28 == (int *)0x150) || (local_28 == (int *)0x20e)) goto LAB_680153ef;
          }
          else if ((int)local_28 < 0x35a) {
            if (local_28 == (int *)0x359) {
LAB_680153ef:
              if (param_2 == '\0') {
                core_getSetSpriteProp(unaff_ESI,param_1,1,(int)local_28,(int *)&local_24);
              }
              else {
                core_accessWindowObjProp(unaff_ESI,param_1,1,(int)local_28,&local_24);
              }
            }
            else if (local_28 == (int *)0x21b) {
              iVar2 = score_getProplistValue(unaff_ESI,(int *)&local_24);
              if (iVar2 != 0) {
                iVar1 = 0;
                local_18 = local_20;
                iVar2 = props_getListLength(unaff_ESI,local_20);
                if (0 < iVar2) {
                  do {
                    score_setProplistValue(unaff_ESI,local_18,iVar1,&local_3c,&local_4c);
                    props_resolveValue(unaff_ESI,&local_3c);
                    if (local_3c == 8) {
                      core_getSetMemberProp(unaff_ESI,local_c,1,local_38,(int *)&local_4c);
                    }
                    props_releaseValue(unaff_ESI,(byte)local_3c,local_38);
                    props_releaseValue(unaff_ESI,(byte)local_4c,local_48);
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < iVar2);
                }
              }
            }
            else if ((local_28 == (int *)0x221) &&
                    (iVar2 = score_getProplistValue(unaff_ESI,(int *)&local_24), iVar2 != 0)) {
              iVar1 = 0;
              local_18 = local_20;
              iVar2 = props_getListLength(unaff_ESI,local_20);
              if (0 < iVar2) {
                do {
                  score_setProplistValue(unaff_ESI,local_18,iVar1,&local_34,&local_44);
                  props_resolveValue(unaff_ESI,&local_34);
                  if (local_34 == 8) {
                    core_getSetMemberRefProp(unaff_ESI,local_8,1,(int)local_30,(int *)&local_44);
                  }
                  props_releaseValue(unaff_ESI,(byte)local_34,local_30);
                  props_releaseValue(unaff_ESI,(byte)local_44,local_40);
                  iVar1 = iVar1 + 1;
                } while (iVar1 < iVar2);
              }
            }
          }
          else if ((0x61b < (int)local_28) &&
                  (((int)local_28 < 0x61e || (local_28 == (int *)0x61f)))) goto LAB_680153ef;
          props_releaseValue(unaff_ESI,(byte)local_2c,local_28);
          props_releaseValue(unaff_ESI,(byte)local_24,local_20);
          iVar2 = local_1c;
          iVar1 = local_10;
        }
        iVar1 = iVar1 + 1;
        local_10 = iVar1;
      } while (iVar1 < iVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: core_invokeHandlers (core_invokeHandlers)
// Address: 680156b0
// Size: 55 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_invokeHandlers(int param_1)
{
  int *piVar1;
  
  if (*(int *)(*(int *)(param_1 + 8) + 0x14) == 0) {
    piVar1 = core_createSpriteProps(param_1);
    *(int **)(*(int *)(param_1 + 8) + 0x14) = piVar1;
  }
  core_dispatchHandlerList(*(int **)(*(int *)(param_1 + 8) + 0x14),'\0');
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: core_formatCallError (core_formatCallError)
// Address: 680156f0
// Size: 130 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatCallError(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = (*(code *)**(undefined4 **)*param_2)(param_1,param_2);
  score_lookupSymbol(DAT_68196304,iVar1,(int)local_408);
  cast_loadPascalString(&DAT_68197780,0x898,0x48);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: core_removeStackArgs (core_removeStackArgs)
// Address: 68015780
// Size: 135 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_removeStackArgs(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)
           (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  iVar1 = props_getInt(param_1);
  uVar2 = iVar1 - param_2;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_2 * -8;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0x80000000 | uVar2;
  puVar4 = puVar3;
  for (; 0 < param_2; param_2 = param_2 + -1) {
    props_releaseValue(param_1,(byte)*puVar4,(int *)puVar4[1]);
    puVar4 = puVar4 + 2;
  }
  if (0 < (int)uVar2) {
    Ordinal_1129(puVar3,puVar4,uVar2 * 8);
  }
  return 0;
}



// ============================================================
// Function: core_getStackState (FUN_68015810)
// Address: 68015810
// Size: 100 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getStackState(void)

{
  int in_EAX;
  uint *puVar1;
  int iVar2;
  int unaff_ESI;
  uint unaff_EDI;
  
  core_removeStackArgs(unaff_ESI,in_EAX);
  puVar1 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x4e8),unaff_EDI,0,(uint *)0x0);
  if (((puVar1 != (uint *)0x0) && (*puVar1 == 3)) &&
     (iVar2 = (**(code **)(**(int **)puVar1[1] + 4))(), iVar2 != 0)) {
    return 1;
  }
  puVar1 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x4ec),unaff_EDI,0,(uint *)0x0);
  if (puVar1 != (uint *)0x0) {
    props_callNative(unaff_ESI,puVar1[1]);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_popAndDispatch (core_popAndDispatch)
// Address: 68015880
// Size: 111 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_popAndDispatch(uint param_1)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)
           (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
           *(int *)(unaff_ESI + 0x18));
  iVar3 = props_getInt(unaff_ESI);
  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
  uVar4 = iVar3 - 1;
  *(uint *)(unaff_ESI + 0x20) = *(uint *)(unaff_ESI + 0x20) & 0x80000000 | uVar4;
  piVar1 = (int *)puVar5[1];
  uVar2 = *puVar5;
  if (0 < (int)uVar4) {
    Ordinal_1129(puVar5,puVar5 + 2,uVar4 * 8);
  }
  props_releaseValue(unaff_ESI,(byte)uVar2,piVar1);
  props_callHandler(unaff_ESI,param_1);
  return 0;
}



// ============================================================
// Function: core_validateHandlerType (core_validateHandlerType)
// Address: 68015900
// Size: 97 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_validateHandlerType(void)

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
      if ((local_8 != 0x54) && (((int)local_8 < 0x7c || (0x7d < (int)local_8)))) {
        return 0;
      }
      uVar2 = core_getStackState();
      return uVar2;
    }
  }
  return 1;
}



// ============================================================
// Function: core_getHandlerCount (core_getHandlerCount)
// Address: 68015970
// Size: 154 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getHandlerCount(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_8);
  if (iVar1 != 0) {
    local_10 = 4;
    if (local_8 != 0x54) {
      if (local_8 == 0x7c) {
        crt_setScriptProperty(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x510));
        piVar2 = *(int **)(**(int **)(unaff_ESI + 8) + 0x510);
      }
      else {
        if (local_8 != 0x7d) {
          return 0;
        }
        piVar2 = *(int **)(**(int **)(unaff_ESI + 8) + 0x514);
      }
      if (piVar2 != (int *)0x0) {
        local_c = props_getListLength(unaff_ESI,piVar2);
        props_popArgs(unaff_ESI,&local_10);
        return 1;
      }
    }
    local_c = 0;
    props_popArgs(unaff_ESI,&local_10);
  }
  return 1;
}



// ============================================================
// Function: core_returnTrue (FUN_68016080)

undefined4 core_returnTrue(void)

{
  return 1;
}



// ============================================================
// Function: core_validateStackType (core_validateStackType)
// Address: 68016090
// Size: 27 bytes
// Params: uint param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall core_validateStackType(uint param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = param_1;
  iVar1 = props_getTypedValue(param_1,2,8,&local_8);
  return (bool)('\x01' - (iVar1 != 0));
}


