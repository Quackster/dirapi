// Module: core
// Topic: Event handler management - external call dispatch, property accessors
// Address range: 0x6801FD80 - 0x6801FF70
// Functions (4):
//   core_dispatchExternalCall (0x6801FD80)
//   core_getHandlerIndex (0x6801FF30)
//   core_getHandlerArgAt (0x6801FF50)
//   core_inheritMethods (0x6801FF70)

// ============================================================
// Function: core_dispatchExternalCall (core_dispatchExternalCall)
// Address: 6801fd80
// Size: 421 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchExternalCall(uint param_1)
{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint *local_10;
  int local_c;
  uint *local_8;
  
  uVar2 = core_getAsyncState(param_1);
  if (uVar2 == 0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x20);
  local_20 = iVar4;
  props_popValue(param_1);
  if ((iVar4 != 0) && (uVar7 = *(uint *)(param_1 + 0x20), local_1c = uVar7, uVar7 != 0)) {
    uVar5 = *(uint *)(param_1 + 0x5c);
    if ((int)uVar5 < 1) {
      uVar5 = 0;
      local_14 = 0;
      local_8 = (uint *)0x0;
    }
    else {
      local_14 = uVar5;
      local_8 = (uint *)xtra_getPropertyById(uVar2,uVar5 * 4);
      if (local_8 == (uint *)0x0) goto LAB_6801fecd;
    }
    local_c = 0;
    if (0 < (int)uVar5) {
      uVar6 = 0;
      local_10 = local_8;
      do {
        puVar1 = local_10;
        if ((int)uVar6 < 0) {
LAB_6801fee7:
          xtra_checkAndFlush(uVar2,(int)local_8);
          goto LAB_6801fecd;
        }
        local_18 = (int)uVar6 >> 0x1f;
        uVar7 = *(uint *)(param_1 + 0x44);
        uVar5 = local_18 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar6,uVar7);
        if (((((int)uVar5 < -1) ||
             (((0x7fffffff < uVar5 && (uVar6 + uVar7 < 0x80000001)) || (0 < (int)uVar5)))) ||
            (((-1 < (int)uVar5 && (0x7fffffff < uVar6 + uVar7)) ||
             (*(int *)(param_1 + 0x40) <= (int)(uVar6 + *(int *)(param_1 + 0x44)))))) ||
           (puVar3 = (uint *)(**(int **)(param_1 + 0x10) + uVar6 + *(int *)(param_1 + 0x44)),
           puVar3 == (uint *)0x0)) goto LAB_6801fee7;
        local_2c = *puVar3;
        local_28 = puVar3[1];
        cast_readScoreXtraData(param_1,uVar2,&local_2c,local_10);
        local_10 = puVar1 + 1;
        local_c = local_c + 1;
        uVar6 = uVar6 + 8;
        uVar5 = local_14;
        uVar7 = local_1c;
      } while (local_c < (int)local_14);
    }
    iVar4 = xtra_validateExtension(uVar2,uVar7 & 0xfffffff8,local_20,uVar5,(int)local_8,(int *)&local_24);
    xtra_checkAndFlush(uVar2,(int)local_8);
    if (iVar4 != 0) {
      cast_dispatchScoreXtra(param_1,uVar2,local_24,(uint *)(param_1 + 0x1c));
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(undefined4 *)(param_1 + 0x74) = 1;
      core_dispatchScript(param_1,uVar2);
      return 0;
    }
  }
LAB_6801fecd:
  *(undefined4 *)(param_1 + 0x74) = 9;
  core_dispatchScript(param_1,uVar2);
  return 0;
}



// ============================================================
// Function: core_getHandlerIndex (core_getHandlerIndex)
// Address: 6801ff30
// Size: 22 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getHandlerIndex(undefined4 param_1,int *param_2)

{
  return *(undefined4 *)(*(int *)(*param_2 + 0x8c) + 0xc + *param_2);
}



// ============================================================
// Function: core_getHandlerArgAt (core_getHandlerArgAt)
// Address: 6801ff50
// Size: 28 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getHandlerArgAt(undefined4 param_1,int *param_2,int param_3)

{
  return *(undefined4 *)(*(int *)(*param_2 + 0x8c) + param_3 * 8 + 0x14 + *param_2);
}



// ============================================================
// Function: core_inheritMethods (core_inheritMethods)
// Address: 6801ff70
// Size: 337 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_inheritMethods(int param_1,int *param_2)
{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar7;
  uint local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  uint *local_8;
  
  uVar1 = *(uint *)(*param_2 + 0x54);
  uVar2 = core_getHandlerIndex(param_1,param_2);
  if (uVar2 == 0) {
    return 0;
  }
  local_c = (int *)(uVar2 & 0xfffffff8);
  uVar2 = core_getAsyncState(param_1);
  uVar7 = extraout_ECX;
  if (uVar2 != 0) {
    if (((uVar1 >> 1 & 1) != 0) &&
       (local_14 = (int *)core_loadMovieResource(param_1,uVar2), local_14 != (int *)0x0)) {
      piVar3 = xtra_resolvePath(uVar2,local_c);
      uVar7 = extraout_ECX_00;
      if (piVar3 == (int *)0x0) goto LAB_680200a9;
      local_18 = 0;
      if (0 < *piVar3) {
        local_8 = (uint *)(piVar3 + 1);
        do {
          iVar4 = xtra_getResourceDataEx(uVar2,*local_8,&local_1c);
          if ((((((iVar4 != 0) &&
                 (puVar5 = (uint *)xtra_lookupHash(uVar2,local_1c), puVar5 != (uint *)0x0)) &&
                (pcVar6 = xtra_getStringValue(puVar5), pcVar6 != (char *)0x0)) &&
               ((iVar4 = xtra_parsePath(uVar2,local_c,pcVar6,&local_10), iVar4 != 0 &&
                ((local_10 & 7) == 0)))) &&
              (((local_10 & 0xfffffff8) != 0 &&
               (((undefined **)(*(uint *)(*(int *)((local_10 & 0xfffffff8) + 4) + 8) & 0xfffffffe)
                 == &PTR_s_Function_681928b8 &&
                (iVar4 = xtra_parsePath(uVar2,local_14,pcVar6,&local_20), iVar4 != 0)))))) &&
             (local_20 == local_10)) {
            xtra_registerNamedMethod(uVar2,local_14,pcVar6);
          }
          local_8 = local_8 + 1;
          local_18 = local_18 + 1;
        } while (local_18 < *piVar3);
      }
      xtra_flushAndCheck(uVar2,(int)piVar3);
    }
    xtra_resolveMethodId(uVar2,(uint)local_c);
    core_dispatchScript(param_1,uVar2);
    uVar7 = extraout_ECX_01;
  }
LAB_680200a9:
  core_setSlotValue(uVar7,1,0);
  return 0;
}


