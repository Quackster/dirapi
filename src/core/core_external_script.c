// Module: core
// Topic: External script loading, serialization, and runtime binding
// Address range: 0x6801F580 - 0x6801FB00
// Functions (11):
//   core_emitAlignedBytecode (0x6801F580)
//   core_emitBytecodeWrapper (0x6801F640)
//   core_deserializeExternalScript (0x6801F660)
//   core_bindFunctionSlot (0x6801F6E0)
//   core_invokeExternalMethod (0x6801F730)
//   core_loadExternalResource (0x6801F750)
//   core_loadExternalScripts (0x6801F770)
//   core_setSlotValue (0x6801FA10)
//   core_deserializeExternalData (0x6801FA30)
//   core_emitMemberInfoOpcode (0x6801FAD0)
//   core_processExternalBindings (0x6801FB00)

// ============================================================
// Function: core_emitAlignedBytecode (FUN_6801f580)
// Address: 6801f580
// Size: 179 bytes
// Params: void * this, uint param_1, undefined1 * param_2
// Return: uint
// Calling convention: __thiscall
// ============================================================

uint __thiscall core_emitAlignedBytecode(void *this,uint param_1,undefined1 *param_2)

{
  int _local_8;
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = stage_getBytecodeRef(*(int **)(**(int **)((int)this + 8) + 0x43c));
  stage_emitBytecode(*(int **)(**(int **)((int)this + 8) + 0x43c),(undefined1 *)&param_1,4);
  iVar1 = stage_emitPushIfNeeded((int)this);
  if (iVar1 != 0) {
    stage_emitBytecode(*(int **)(**(int **)((int)this + 8) + 0x43c),param_2,param_1);
    iVar1 = stage_emitPushIfNeeded((int)this);
    if (iVar1 != 0) {
      if ((param_1 & 3) != 0) {
        stage_emitBytecode(*(int **)(**(int **)((int)this + 8) + 0x43c),(undefined1 *)&local_8,
                     4 - (param_1 & 3));
        iVar1 = stage_emitPushIfNeeded((int)this);
        if (iVar1 == 0) {
          return 0;
        }
      }
      uVar2 = core_lookupSpritePropSymbol(&local_10);
      return uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: core_emitBytecodeWrapper (FUN_6801f640)
// Address: 6801f640
// Size: 22 bytes
// Params: void * this, void * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall core_emitBytecodeWrapper(void *this,void *param_1)
{
  undefined1 *in_EAX;
  
  core_emitAlignedBytecode(param_1,(uint)this,in_EAX);
  return 0;
}



// ============================================================
// Function: core_deserializeExternalScript (FUN_6801f660)
// Address: 6801f660
// Size: 115 bytes
// Params: void * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_deserializeExternalScript(void *param_1)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int iVar3;
  void *local_c;
  int local_8;
  
  piVar1 = runtime_getSerializedEntry(in_EAX,0);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = runtime_resolvePrototype(piVar1,(int *)&stack0x00000008,&local_8);
  if (iVar2 != 0) {
    if (local_8 != 0) {
      iVar3 = runtime_validateStream((int)piVar1,&local_c);
      if (iVar3 != 0) {
        core_emitBytecodeWrapper(local_c,param_1);
        goto LAB_6801f6c3;
      }
    }
    runtime_beginSerialization((int)piVar1);
    return 0;
  }
LAB_6801f6c3:
  runtime_beginSerialization((int)piVar1);
  return iVar2;
}



// ============================================================
// Function: core_bindFunctionSlot (FUN_6801f6e0)
// Address: 6801f6e0
// Size: 77 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_bindFunctionSlot(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  
  if ((((in_EAX & 7) == 0) && ((in_EAX & 0xfffffff8) != 0)) &&
     ((undefined **)(*(uint *)(*(int *)((in_EAX & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
      &PTR_s_Function_681928b8)) {
    uVar2 = xtra_getObjectTag(param_1,in_EAX & 0xfffffff8);
    if (uVar2 != 0) {
      iVar1 = *(int *)(uVar2 + 0xc);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x34) = param_2;
        *(undefined4 *)(iVar1 + 0x38) = param_3;
        return iVar1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_invokeExternalMethod (FUN_6801f730)
// Address: 6801f730
// Size: 19 bytes
// Params: undefined4 param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_invokeExternalMethod(undefined4 param_1,uint param_2,uint param_3)
{
  undefined4 in_EAX;

  xtra_processExtension(param_3,param_2,param_1,in_EAX);
  return 0;
}



// ============================================================
// Function: core_loadExternalResource (FUN_6801f750)
// Address: 6801f750
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_loadExternalResource(int param_1)
{
  undefined4 *in_EAX;

  xtra_loadResource(param_1,(undefined **)0x0,in_EAX,(uint)in_EAX);
  return 0;
}



// ============================================================
// Function: core_loadExternalScripts (FUN_6801f770)
// Address: 6801f770
// Size: 657 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_loadExternalScripts(void *param_1)
{
  char cVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  uint uVar12;
  char *pcVar13;
  uint local_14;
  int *local_10;
  char *local_c;
  uint *local_8;
  
  pvVar3 = param_1;
  local_10 = *(int **)(**(int **)((int)param_1 + 8) + 0x428);
  uVar2 = *(uint *)(*local_10 + 0x54);
  puVar4 = (uint *)(*local_10 + 0x54);
  *puVar4 = *puVar4 & 0xffffbfff;
  puVar4 = (uint *)core_getAsyncState((int)param_1);
  if (puVar4 == (uint *)0x0) {
    return 0;
  }
  piVar5 = (int *)core_loadMovieResource((int)pvVar3,(uint)puVar4);
  piVar6 = (int *)core_loadExternalResource((int)puVar4);
  if (piVar6 != (int *)0x0) {
    xtra_getMethodById((uint)puVar4,(uint)piVar6);
    pcVar7 = (char *)Ordinal_1114(**(undefined4 **)(**(int **)((int)pvVar3 + 8) + 0x420));
    local_c = pcVar7 + 1;
    pcVar13 = pcVar7;
    do {
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    local_8 = (uint *)xtra_evalSubstring(puVar4,piVar6,pcVar7,(int)pcVar13 - (int)local_c,0,1);
    if (((local_8 == (uint *)0x0) ||
        (iVar8 = core_invokeExternalMethod(local_8,(uint)piVar6,(uint)puVar4), iVar8 == 0)) ||
       (iVar8 = core_deserializeExternalScript(pvVar3), iVar8 == 0)) {
      xtra_resolveMethodId((uint)puVar4,(uint)piVar6);
      Ordinal_1115(**(undefined4 **)(**(int **)((int)pvVar3 + 8) + 0x420));
      if (local_8 != (uint *)0x0) {
        xtra_getInterfacePtr((int)puVar4,(int)local_8);
        core_dispatchScript((int)pvVar3,(int)puVar4);
        return 0;
      }
    }
    else {
      xtra_getInterfacePtr((int)puVar4,(int)local_8);
      Ordinal_1115(**(undefined4 **)(**(int **)((int)pvVar3 + 8) + 0x420));
      uVar9 = core_resolveSpritePropDefault();
      piVar10 = xtra_resolvePath((uint)puVar4,piVar6);
      if (piVar10 != (int *)0x0) {
        local_c = (char *)0x0;
        if (0 < *piVar10) {
          local_8 = (uint *)(piVar10 + 1);
          do {
            iVar8 = xtra_getResourceDataEx(puVar4,*local_8,&local_14);
            if (((((iVar8 != 0) &&
                  (puVar11 = (uint *)xtra_lookupHash((int)puVar4,local_14), puVar11 != (uint *)0x0)) &&
                 ((pcVar13 = xtra_getStringValue(puVar11), pcVar13 != (char *)0x0 &&
                  ((iVar8 = xtra_parsePath((int)puVar4,piVar6,pcVar13,&param_1), iVar8 != 0 &&
                   (((uint)param_1 & 7) == 0)))))) && (((uint)param_1 & 0xfffffff8) != 0)) &&
               ((undefined **)
                (*(uint *)(*(int *)(((uint)param_1 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
                &PTR_s_Function_681928b8)) {
              if ((uVar2 >> 1 & 1) != 0) {
                xtra_parsePathEx((int)puVar4,piVar5,pcVar13,&param_1);
              }
              uVar12 = props_resolvePropertyId(pvVar3,pcVar13);
              stage_resetCodegenState((int)pvVar3,uVar12);
              stage_emitInstruction((int)pvVar3,0x44,uVar9,1);
              uVar12 = core_resolveSpritePropDefault();
              stage_emitInstruction((int)pvVar3,0x44,uVar12,1);
              stage_emitOpcode((int)pvVar3,0x26,-2);
              stage_finalizeCodegen((int)pvVar3);
              iVar8 = core_bindFunctionSlot(puVar4,local_10,uVar12 - 2);
              if (iVar8 != 0) {
                *(int *)(**(int **)(**(int **)((int)pvVar3 + 8) + 0x430) + 0x4c +
                        (uVar12 - 2) * 0x3c) = *(int *)(iVar8 + 0x1c) + -1;
              }
            }
            local_8 = local_8 + 1;
            local_c = local_c + 1;
          } while ((int)local_c < *piVar10);
        }
        xtra_flushAndCheck(puVar4,(int)piVar10);
        *(uint *)(*local_10 + 0x54) = *(uint *)(*local_10 + 0x54) | 0xc000;
      }
    }
  }
  core_dispatchScript((int)pvVar3,(int)puVar4);
  return 0;
}



// ============================================================
// Function: core_setSlotValue (FUN_6801fa10)
// Address: 6801fa10
// Size: 25 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_setSlotValue(undefined4 param_1,int param_2,undefined4 param_3)
{
  int *in_EAX;
  
  *(undefined4 *)(*(int *)(*in_EAX + 0x8c) + param_2 * 8 + 4 + *in_EAX) = param_3;
  return 0;
}



// ============================================================
// Function: core_deserializeExternalData (FUN_6801fa30)
// Address: 6801fa30
// Size: 148 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_deserializeExternalData(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  int local_c;
  int local_8;
  
  local_8 = 0;
  uVar1 = xtra_getPlatformFlags(unaff_EDI);
  xtraRuntime_setPlatformFlags(unaff_EDI,param_1);
  piVar2 = runtime_getSerializedEntry(unaff_EDI,1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  runtime_writeSerializedData((int)piVar2,param_2,param_3);
  iVar3 = runtime_resolvePrototype(piVar2,&local_8,&local_c);
  if ((iVar3 != 0) && (local_c == 0)) {
    if (local_8 != 0) {
      xtra_getInterfacePtr(unaff_EDI,local_8);
    }
    local_8 = 0;
  }
  runtime_writeSerializedData((int)piVar2,0,0);
  runtime_beginSerialization((int)piVar2);
  xtraRuntime_setPlatformFlags(unaff_EDI,uVar1);
  return local_8;
}



// ============================================================
// Function: core_emitMemberInfoOpcode (FUN_6801fad0)
// Address: 6801fad0
// Size: 45 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_emitMemberInfoOpcode(void)
{
  int *in_EAX;
  undefined4 uVar1;
  int unaff_ESI;
  int iVar2;
  undefined2 local_8;
  undefined2 local_6;
  int _local_8; /* FIXUP: undeclared identifier */

  iVar2 = 1;
  _local_8 = CONCAT22(*(undefined2 *)(*in_EAX + 0x5c),*(undefined2 *)(*in_EAX + 0x5e));
  uVar1 = sprites_getMemberInfo(unaff_ESI,(undefined4 *)&local_8);
  sprites_setMemberLocked(unaff_ESI,uVar1,iVar2);
  return 0;
}



// ============================================================
// Function: core_processExternalBindings (FUN_6801fb00)
// Address: 6801fb00
// Size: 635 bytes
// Params: void * this, int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall core_processExternalBindings(void *this,int param_1,int *param_2,int param_3)
{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  char *pcVar10;
  uint uVar11;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  uint local_18;
  int local_14;
  int *local_10;
  uint *local_c;
  uint local_8;
  
  uVar1 = *(uint *)(*param_2 + 0x54);
  core_setSlotValue(this,1,0);
  if (param_3 < 0x740) {
    core_emitMemberInfoOpcode();
    *(uint *)(*param_2 + 0x54) = *(uint *)(*param_2 + 0x54) & 0xffffbfff;
    return 0;
  }
  uVar2 = core_getAsyncState(param_1);
  if (uVar2 == 0) {
    return 0;
  }
  piVar3 = (int *)core_loadMovieResource(param_1,uVar2);
  piVar4 = (int *)core_loadExternalResource(uVar2);
  if (piVar4 != (int *)0x0) {
    xtra_getMethodById(uVar2,(uint)piVar4);
    iVar5 = Ordinal_1114(param_2);
    iVar6 = Ordinal_1116(param_2);
    iVar7 = *param_2;
    if ((((0 < *(int *)(iVar7 + 0x88)) && (*(int *)(iVar7 + 0x8c) < iVar6)) &&
        (uVar11 = *(int *)(*(int *)(iVar7 + 0x8c) + 4 + iVar7) + *(int *)(iVar7 + 0x94),
        uVar11 < iVar6 - 4U)) &&
       ((*(uint *)(iVar7 + uVar11) <= (iVar6 - uVar11) - 4 &&
        (iVar7 = core_deserializeExternalData(piVar4,uVar11 + 4 + iVar5,*(uint *)(iVar7 + uVar11)), iVar7 != 0)))) {
      iVar5 = core_invokeExternalMethod(iVar7,(uint)piVar4,uVar2);
      xtra_getInterfacePtr(uVar2,iVar7);
      if (iVar5 != 0) {
        Ordinal_1115(param_2);
        piVar8 = xtra_resolvePath(uVar2,piVar4);
        local_10 = piVar8;
        if (piVar8 != (int *)0x0) {
          core_setSlotValue(extraout_ECX,1,piVar4);
          local_14 = 0;
          if (0 < *piVar8) {
            local_c = (uint *)(piVar8 + 1);
            param_3 = 0;
            do {
              iVar7 = xtra_getResourceDataEx(uVar2,*local_c,&local_18);
              if (((iVar7 != 0) &&
                  (puVar9 = (uint *)xtra_lookupHash(uVar2,local_18), puVar9 != (uint *)0x0)) &&
                 ((pcVar10 = xtra_getStringValue(puVar9), piVar8 = local_10, pcVar10 != (char *)0x0 &&
                  ((((iVar7 = xtra_parsePath(uVar2,piVar4,pcVar10,&local_8), piVar8 = local_10,
                     iVar7 != 0 && ((local_8 & 7) == 0)) && ((local_8 & 0xfffffff8) != 0)) &&
                   (iVar7 = *(int *)((local_8 & 0xfffffff8) + 4),
                   (undefined **)(*(uint *)(iVar7 + 8) & 0xfffffffe) == &PTR_s_Function_681928b8))))
                 )) {
                if ((uVar1 >> 1 & 1) != 0) {
                  xtra_parsePathEx(uVar2,piVar3,pcVar10,&local_8);
                  iVar7 = extraout_ECX_00;
                }
                core_setSlotValue(iVar7,param_3 + 2,local_8);
                iVar7 = core_bindFunctionSlot(uVar2,param_2,param_3);
                if ((iVar7 != 0) && (iVar5 = props_getContextSlot(param_1,param_2,param_3), iVar5 != 0)) {
                  *(int *)(iVar5 + 0x2c) = *(int *)(iVar7 + 0x1c) + -1;
                }
                param_3 = param_3 + 1;
                piVar8 = local_10;
              }
              local_c = local_c + 1;
              local_14 = local_14 + 1;
            } while (local_14 < *piVar8);
          }
          xtra_flushAndCheck(uVar2,(int)piVar8);
          core_dispatchScript(param_1,uVar2);
          return 0;
        }
        goto LAB_6801fd68;
      }
    }
    Ordinal_1115(param_2);
    xtra_resolveMethodId(uVar2,(uint)piVar4);
    core_emitMemberInfoOpcode();
    *(uint *)(*param_2 + 0x54) = *(uint *)(*param_2 + 0x54) & 0xffffbfff;
  }
LAB_6801fd68:
  core_dispatchScript(param_1,uVar2);
  return 0;
}


