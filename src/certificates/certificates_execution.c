// Module: certificates
// Topic: Execution engine - memory arena, property handling, function dispatch, scope resolution, script execution
// Address range: 0x68153AE0 - 0x68154E90
// Functions (19):
//   certificates_initArena
//   certificates_enableGc
//   certificates_disableGc
//   certificates_markAtom
//   certs_checkConstraint
//   certificates_resetStack
//   certs_findExtension
//   certs_checkValidity
//   certs_executeVerify
//   certs_verifyExtension
//   certificates_resolveProperty
//   certs_initVerifier
//   certs_validatePath
//   certs_verifyChain
//   certificates_initScope
//   certs_validateExtension
//   certs_processKeyUsage
//   certs_processExtension
//   certs_verifySignature

// ============================================================
// Function: certificates_initArena (FUN_68153ae0)
// Address: 68153ae0
// Size: 71 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_initArena(int param_1)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar1 + 0x2248) == 0) {
    memset((void *)(iVar1 + 0x248),0,0x2000);
    *(undefined4 *)(iVar1 + 0x2248) = 1;
  }
  return 0;
}



// ============================================================
// Function: certificates_enableGc (FUN_68153b30)
// Address: 68153b30
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_enableGc(int param_1)
{
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x224c) = 1;
  return 0;
}



// ============================================================
// Function: certificates_disableGc (FUN_68153b50)
// Address: 68153b50
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_disableGc(int param_1)
{
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x224c) = 0;
  return 0;
}



// ============================================================
// Function: certificates_markAtom (FUN_68153b70)
// Address: 68153b70
// Size: 134 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_markAtom(int param_1,int param_2)
{
  int local_c;
  uint local_8;

  local_c = *(int *)(*(int *)(param_2 + 4) + 0xc);
  local_8 = *(uint *)(*(int *)(param_2 + 4) + 4);
  if (((local_c != 0) && ((local_8 & 7) == 0)) && (local_8 != 0)) {
    (**(code **)(*(int *)(*(int *)(local_8 & 0xfffffff8) + 4) + 0x28))
              (param_1,local_8 & 0xfffffff8,2,&local_c,0);
  }
  js_markAtom(*(int *)(param_1 + 0x14),*(int *)(param_2 + 4) + 4);
  *(int *)(*(int *)(param_1 + 0x14) + 0x58) = *(int *)(*(int *)(param_1 + 0x14) + 0x58) + 1;
  return 0;
}



// ============================================================
// Function: certs_checkConstraint (FUN_68153c00)
// Address: 68153c00
// Size: 217 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int certs_checkConstraint(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_10;

  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0xc);
  }
  iVar1 = *(int *)(param_1 + 0x28);
  uVar2 = *(int *)(param_1 + 0x30) + param_2 * 4 & ~*(uint *)(param_1 + 0x30);
  local_10 = *(int *)(iVar1 + 0xc);
  uVar3 = local_10 + uVar2;
  if (*(uint *)(iVar1 + 8) < uVar3) {
    local_10 = js_getSlotIndex(param_1 + 0x18,uVar2);
  }
  else {
    *(uint *)(iVar1 + 0xc) = uVar3;
  }
  if (local_10 == 0) {
    if ((*(int *)(param_1 + 0x34) != 0) && (*(int *)(*(int *)(param_1 + 0x34) + 0x10) != 0)) {
      xtra_setScriptPropertyEx(*(int *)(*(int *)(param_1 + 0x34) + 0x10));
    }
    xtra_invokeMethod(param_1,xtra_getErrorString,0,0x18);
  }
  return local_10;
}



// ============================================================
// Function: certificates_resetStack (FUN_68153ce0)
// Address: 68153ce0
// Size: 110 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_resetStack(int param_1,int param_2)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == param_1 + 0x18) ||
     ((uint)(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 4)) < (uint)(param_2 - *(int *)(iVar1 + 4))))
  {
    js_getPrototype((int *)(param_1 + 0x18),param_2);
  }
  else {
    *(uint *)(iVar1 + 0xc) = param_2 + *(int *)(param_1 + 0x30) & ~*(uint *)(param_1 + 0x30);
  }
  return 0;
}



// ============================================================
// Function: certs_findExtension (FUN_68153d50)
// Address: 68153d50
// Size: 300 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * certs_findExtension(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *local_1c;

  if (param_2 == 0) {
    *param_3 = 0;
    piVar5 = *(int **)(*(int *)(param_1 + 0x28) + 0xc);
  }
  else {
    piVar5 = (int *)certs_checkConstraint(param_1,param_2 + 2,param_3);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x28);
      piVar2 = *(int **)(param_1 + 0x174);
      if ((piVar2 == (int *)0x0) || (piVar2 + *piVar2 + 2 != piVar5)) {
        iVar1 = *(int *)(param_1 + 0x34);
        if ((iVar1 != 0) && ((*(int *)(iVar1 + 0xc) != 0 && (*(int *)(iVar1 + 0x40) != 0)))) {
          iVar3 = *(int *)(*(int *)(iVar1 + 0xc) + 0x20);
          iVar4 = *(int *)(iVar1 + 0x40);
          for (local_1c = *(undefined4 **)(iVar1 + 0x3c);
              local_1c < (undefined4 *)(iVar4 + iVar3 * 4); local_1c = local_1c + 1) {
            *local_1c = 0x80000001;
          }
        }
        *piVar5 = param_2;
        piVar5[1] = *(int *)(param_1 + 0x174);
        *(int **)(param_1 + 0x174) = piVar5;
        piVar5 = piVar5 + 2;
      }
      else {
        *piVar2 = *piVar2 + param_2;
        *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -8;
      }
    }
  }
  return piVar5;
}



// ============================================================
// Function: certs_checkValidity (FUN_68153e80)
// Address: 68153e80
// Size: 185 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certs_checkValidity(int param_1,int param_2)
{
  uint *puVar1;
  int iVar2;
  uint uVar3;

  if (param_2 != 0) {
    puVar1 = *(uint **)(param_1 + 0x174);
    uVar3 = (uint)(param_2 - (int)(puVar1 + 2)) >> 2;
    if (uVar3 < *puVar1) {
      *puVar1 = uVar3;
    }
    else {
      *(uint *)(param_1 + 0x174) = puVar1[1];
    }
    iVar2 = *(int *)(param_1 + 0x28);
    if ((iVar2 == param_1 + 0x18) ||
       ((uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 4)) < (uint)(param_2 - *(int *)(iVar2 + 4)))
       ) {
      js_getPrototype((int *)(param_1 + 0x18),param_2);
    }
    else {
      *(uint *)(iVar2 + 0xc) = param_2 + *(int *)(param_1 + 0x30) & ~*(uint *)(param_1 + 0x30);
    }
  }
  return 0;
}



// ============================================================
// Function: certs_executeVerify (FUN_68153f40)
// Address: 68153f40
// Size: 12 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certs_executeVerify(void)

{
  return 1;
}



// ============================================================
// Function: certs_verifyExtension (FUN_68153f50)
// Address: 68153f50
// Size: 35 bytes
// Params: uint param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certs_verifyExtension(uint param_1,int *param_2,int param_3,undefined4 *param_4)
{
  certificates_resolveProperty(param_1,param_2,certs_verifyExtension,param_3,*param_4);
  return 0;
}



// ============================================================
// Function: certificates_resolveProperty (FUN_68153f80)
// Address: 68153f80
// Size: 574 bytes
// Params: uint param_1, int * param_2, undefined * param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_resolveProperty(uint param_1,int *param_2,undefined *param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  short *local_2c;
  uint local_28;
  short *local_24;
  uint local_20;
  uint *local_14;

  piVar1 = param_2;
  iVar2 = xtra_callMethod(param_1,(int)param_2,&PTR_s_Function_681928b8,0);
  if (iVar2 == 0) {
    do {
      param_2 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
      if (param_2 == (int *)0x0) {
        return 1;
      }
      iVar2 = xtra_callMethod(param_1,(int)param_2,&PTR_s_Function_681928b8,0);
    } while (iVar2 == 0);
    for (local_14 = *(uint **)(*param_2 + 0x24); local_14 != (uint *)0x0;
        local_14 = (uint *)local_14[5]) {
      if (((undefined *)local_14[2] == param_3) &&
         ((int)*(short *)((int)local_14 + 0x12) == param_4 >> 1)) {
        puVar3 = (uint *)(*(uint *)(*local_14 + 8) & 0xfffffff8);
        if ((*puVar3 & 0x40000000) == 0) {
          local_20 = *puVar3;
        }
        else {
          local_20 = (-(uint)((*puVar3 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar3;
        }
        if ((*puVar3 & 0x40000000) == 0) {
          local_2c = (short *)puVar3[1];
        }
        else {
          if ((*(uint *)puVar3[1] & 0x40000000) == 0) {
            if ((*puVar3 & 0x80000000) == 0) {
              local_28 = *puVar3 >> 0xf & 0x7fff;
            }
            else {
              local_28 = 0;
            }
            local_24 = (short *)(*(int *)(puVar3[1] + 4) + local_28 * 2);
          }
          else {
            local_24 = (short *)crypto_getStringLen(puVar3);
          }
          local_2c = local_24;
        }
        uVar4 = xtraRuntime_callMethodInline(param_1,piVar1,local_2c,local_20,param_5,0,0);
        return uVar4;
      }
    }
  }
  else {
    for (local_14 = *(uint **)(*param_2 + 0x24); local_14 != (uint *)0x0;
        local_14 = (uint *)local_14[5]) {
      if (((undefined *)local_14[2] == param_3) &&
         ((int)*(short *)((int)local_14 + 0x12) == param_4 >> 1)) {
        if ((local_14[4] & 0x40) == 0) {
          return 1;
        }
        puVar3 = strings_addTableRange(param_1,*param_2,local_14,0,0xffffffbf,(undefined *)local_14[1],
                              param_3);
        if (puVar3 != (uint *)0x0) {
          *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x60) = 1;
          *(undefined4 *)(param_2[1] + puVar3[3] * 4) = param_5;
          return 1;
        }
        return 0;
      }
    }
  }
  return 1;
}



// ============================================================
// Function: certs_initVerifier (FUN_681541c0)
// Address: 681541c0
// Size: 42 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certs_initVerifier(void)

{
  return 1;
}



// ============================================================
// Function: certs_validatePath (FUN_681541f0)
// Address: 681541f0
// Size: 69 bytes
// Params: uint param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6815422d) */

undefined4 certs_validatePath(uint param_1,int *param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;

  uVar1 = certificates_resolveProperty(param_1,param_2,certs_validatePath,param_3,*param_4);
  return uVar1;
}



// ============================================================
// Function: certs_verifyChain (FUN_68154240)
// Address: 68154240
// Size: 1847 bytes
// Params: uint param_1, uint param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certs_verifyChain(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_d0;
  code *local_cc;
  undefined *local_c8;
  uint local_bc;
  int local_b4;
  int local_b0;
  undefined4 local_ac;
  int local_a8;
  uint local_a4;
  undefined4 local_a0;
  uint local_9c;
  uint *local_98;
  uint local_94;
  uint local_90;
  uint *local_8c;
  int local_88;
  undefined4 local_84;
  int *local_80;
  undefined4 local_7c;
  uint *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint *local_58;
  uint *local_54;
  uint *local_50;
  code *local_4c;
  uint *local_48;
  int local_44;
  uint local_40;
  int *local_3c;
  code *local_38;
  undefined **local_34;
  undefined **local_30;
  int local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  uint *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int *local_8;

  local_28 = *(int *)(param_1 + 0x34);
  local_1c = *(uint **)(local_28 + 0x3c);
  local_50 = (uint *)((int)local_1c - (param_2 * 4 + 8));
  local_10 = *local_50;
  local_94 = 0x80000001;
  local_68 = param_3 & 1;
  if (((local_10 & 7) != 0) || (local_10 == 0)) {
LAB_6815494e:
    runtime_callObjectMethod(param_1,local_50,(uint)((param_3 & 1) != 0));
    local_18 = 0;
    goto LAB_6815490a;
  }
  local_8 = (int *)(local_10 & 0xfffffff8);
  local_3c = (int *)(*(uint *)(local_8[1] + 4) & 0xfffffff8);
  local_24 = (int *)(local_50[1] & 0xfffffff8);
  local_34 = (undefined **)(*(uint *)(local_8[1] + 8) & 0xfffffffe);
  if (local_34 == &PTR_s_Function_681928b8) {
    local_c = xtra_getObjectTag(param_1,(int)local_8);
LAB_681543fb:
    local_4c = *(code **)(local_c + 8);
    local_44 = *(int *)(local_c + 0xc);
    local_40 = (uint)*(ushort *)(local_c + 0x10) + (uint)*(ushort *)(local_c + 0x12);
    local_20 = (uint)*(ushort *)(local_c + 0x14);
    if ((*(byte *)(local_c + 0x16) & 0x40) != 0) {
      local_24 = local_3c;
    }
  }
  else {
    local_30 = *(undefined ***)(*local_8 + 4);
    if (*(int *)(param_1 + 0xc) == 0x78) {
LAB_6815431b:
      local_18 = (*(code *)local_34[8])(param_1,local_8,2,&local_10);
      if (local_18 == 0) {
        local_18 = 0;
        goto LAB_6815490a;
      }
      if ((((local_10 & 7) == 0) && ((local_10 & 0xfffffff8) != 0)) &&
         ((undefined **)(*(uint *)(*(int *)((local_10 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
          &PTR_s_Function_681928b8)) {
        local_8 = (int *)(local_10 & 0xfffffff8);
        local_3c = (int *)(*(uint *)(local_8[1] + 4) & 0xfffffff8);
        local_c = xtra_getObjectTag(param_1,(int)local_8);
        *local_50 = local_10;
        goto LAB_681543fb;
      }
    }
    else {
      if (local_30 == &PTR_FUN_68192948) {
        local_c8 = local_34[0xc];
      }
      else {
        local_c8 = local_30[0xe];
      }
      if (local_c8 != (undefined *)0x0) goto LAB_6815431b;
    }
    local_c = 0;
    local_44 = 0;
    local_20 = 0;
    local_40 = 0;
    if ((param_3 & 1) == 0) {
      local_cc = (code *)local_30[0xe];
    }
    else {
      local_cc = (code *)local_30[0xf];
    }
    local_4c = local_cc;
    if (local_cc == (code *)0x0) goto LAB_6815494e;
  }
  local_ac = 0;
  local_b0 = 0;
  local_b4 = 0;
  local_a8 = local_44;
  local_a4 = local_c;
  local_9c = param_2;
  local_98 = local_1c + -param_2;
  local_90 = local_20;
  local_8c = local_1c;
  local_88 = local_28;
  local_84 = 0;
  local_80 = (int *)0x0;
  local_7c = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_64 = 0;
  local_60 = 0;
  local_18 = certificates_initScope(param_1,local_24,(int)&local_b4);
  if (local_18 == 0) {
    local_18 = 0;
    goto LAB_6815490a;
  }
  *(int **)(param_1 + 0x34) = &local_b4;
  local_54 = *(uint **)(*(int *)(param_1 + 0x28) + 0xc);
  local_38 = *(code **)(*(int *)(param_1 + 0x14) + 0x218);
  local_14 = 0;
  if (param_2 < local_40) {
    local_d0 = local_40 - param_2;
  }
  else {
    local_d0 = 0;
  }
  local_bc = local_d0;
  if (local_d0 == 0) {
LAB_6815468c:
    local_bc = local_90;
    if (local_90 != 0) {
      if (*(int *)(*(int *)(param_1 + 0x28) + 0xc) - (int)local_8c >> 2 < (int)local_90) {
        local_48 = (uint *)certs_checkConstraint(param_1,local_90,(undefined4 *)0x0);
        if (local_48 == (uint *)0x0) {
          local_18 = 0;
          goto LAB_68154810;
        }
        if (local_48 != local_1c) {
          local_8c = local_48;
          local_1c = local_48;
        }
      }
      while (local_bc = local_bc - 1, -1 < (int)local_bc) {
        *local_1c = 0x80000001;
        local_1c = local_1c + 1;
      }
    }
    local_78 = local_1c;
    if ((local_38 != (code *)0x0) && ((local_4c != (code *)0x0 || (local_44 != 0)))) {
      local_14 = (*local_38)(param_1,&local_b4,1,0,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x21c)
                            );
    }
    if (local_4c == (code *)0x0) {
      if (local_44 == 0) {
        local_80 = (int *)0x0;
        local_18 = 1;
      }
      else {
        local_80 = local_3c;
        if (((*(byte *)(local_c + 0x16) & 0x80) == 0) ||
           (piVar2 = runtime_createPrototypeChain(param_1,&local_b4,(uint)local_3c), piVar2 != (int *)0x0)) {
          local_18 = certificates_executeByteCode(param_1,&local_10);
        }
        else {
          local_18 = 0;
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x158) = 0;
      local_ac = *(undefined4 *)(local_28 + 8);
      local_80 = *(int **)(local_28 + 0x34);
      local_18 = (*local_4c)(param_1,local_a0,param_2,local_98,&local_94);
    }
  }
  else {
    local_58 = *(uint **)(*(int *)(param_1 + 0x28) + 8);
    if (local_58 < local_1c + local_d0) {
      local_2c = local_d0 + 2 + param_2;
    }
    else {
      local_2c = local_d0 - ((int)local_54 - (int)local_1c >> 2);
    }
    if (local_2c < 1) {
LAB_68154652:
      local_8c = local_8c + local_d0;
      while (local_bc = local_bc + -1, -1 < (int)local_bc) {
        *local_1c = 0x80000001;
        local_1c = local_1c + 1;
      }
      goto LAB_6815468c;
    }
    local_48 = (uint *)certs_checkConstraint(param_1,local_2c,(undefined4 *)0x0);
    if (local_48 != (uint *)0x0) {
      if (local_48 != local_54) {
        *local_48 = *local_50;
        local_48[1] = local_50[1];
        local_48 = local_48 + 2;
        if (param_2 != 0) {
          memcpy(local_48,local_98,param_2 << 2);
        }
        local_98 = local_48;
        local_8c = local_48 + param_2;
        local_1c = local_8c;
      }
      goto LAB_68154652;
    }
    local_18 = 0;
  }
LAB_68154810:
  if ((local_14 != 0) &&
     (local_38 = *(code **)(*(int *)(param_1 + 0x14) + 0x218), local_38 != (code *)0x0)) {
    (*local_38)(param_1,&local_b4,0,&local_18,local_14);
  }
  if (local_b4 != 0) {
    uVar3 = runtime_initObjectInstance(param_1,&local_b4);
    local_18 = uVar3 & local_18;
  }
  if (local_b0 != 0) {
    uVar3 = runtime_initObjectProperties(param_1,(int)&local_b4);
    local_18 = uVar3 & local_18;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == param_1 + 0x18) ||
     ((uint)(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 4)) <
      (uint)((int)local_54 - *(int *)(iVar1 + 4)))) {
    js_getPrototype((int *)(param_1 + 0x18),(int)local_54);
  }
  else {
    *(uint *)(iVar1 + 0xc) = (int)local_54 + *(int *)(param_1 + 0x30) & ~*(uint *)(param_1 + 0x30);
  }
  *(int *)(param_1 + 0x34) = local_28;
LAB_6815490a:
  *local_50 = local_94;
  *(uint **)(local_28 + 0x3c) = local_50 + 1;
  if ((*(int *)(local_28 + 0xc) != 0) && ((param_3 & 2) == 0)) {
    local_50[-*(int *)(*(int *)(local_28 + 0xc) + 0x20)] = *(uint *)(local_28 + 0x38);
  }
  return local_18;
}



// ============================================================
// Function: certificates_initScope (FUN_68154980)
// Address: 68154980
// Size: 219 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_initScope(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *local_c;

  if ((param_2 == (int *)0x0) ||
     ((undefined **)(*(uint *)(param_2[1] + 8) & 0xfffffffe) == &PTR_DAT_68192810)) {
    piVar1 = (int *)(*(uint *)(*(int *)((*(uint *)(*(int *)(param_3 + 0x1c) + -8) & 0xfffffff8) + 4)
                              + 4) & 0xfffffff8);
    if (piVar1 == (int *)0x0) {
      param_2 = *(int **)(param_1 + 0x8c);
    }
    else {
      do {
        param_2 = piVar1;
        piVar1 = (int *)(*(uint *)(param_2[1] + 4) & 0xfffffff8);
      } while (piVar1 != (int *)0x0);
    }
  }
  else {
    if (*(int *)(*(int *)(*param_2 + 4) + 0x30) == 0) {
      local_c = param_2;
    }
    else {
      local_c = (int *)(**(code **)(*(int *)(*param_2 + 4) + 0x30))(param_1,param_2);
    }
    param_2 = local_c;
    if (local_c == (int *)0x0) {
      return 0;
    }
    if ((*(uint *)(param_3 + 0x4c) & 1) != 0) {
      *(int **)(param_3 + 0x20) = local_c;
    }
  }
  *(int **)(param_3 + 0x14) = param_2;
  *(int **)(*(int *)(param_3 + 0x1c) + -4) = param_2;
  return 1;
}



// ============================================================
// Function: certs_validateExtension (FUN_68154a60)
// Address: 68154a60
// Size: 307 bytes
// Params: uint param_1, int param_2, int param_3, uint param_4, uint param_5, int param_6, int * param_7
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certs_validateExtension(uint param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6,
                 int *param_7)

{
  undefined1 local_7c [92];
  undefined4 local_20;
  int local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  int *local_10;
  uint local_c;
  uint local_8;

  local_18 = *(undefined1 **)(param_1 + 0x34);
  local_14 = local_18;
  if (local_18 == (undefined1 *)0x0) {
    memset(local_7c,0,0x58);
    local_14 = local_7c;
    *(undefined1 **)(param_1 + 0x34) = local_14;
  }
  local_20 = *(undefined4 *)(local_14 + 0x3c);
  local_10 = certs_findExtension(param_1,param_5 + 2,&local_1c);
  if (local_10 == (int *)0x0) {
    local_8 = 0;
  }
  else {
    *local_10 = param_3;
    local_10[1] = param_2;
    local_10 = local_10 + 2;
    for (local_c = 0; local_c < param_5; local_c = local_c + 1) {
      *local_10 = *(int *)(param_6 + local_c * 4);
      local_10 = local_10 + 1;
    }
    *(int **)(local_14 + 0x3c) = local_10;
    local_8 = certs_verifyChain(param_1,param_5,param_4 | 2);
    if (local_8 != 0) {
      local_10 = (int *)(*(int *)(local_14 + 0x3c) + -4);
      *param_7 = *local_10;
    }
    certs_checkValidity(param_1,local_1c);
  }
  *(undefined4 *)(local_14 + 0x3c) = local_20;
  if (local_18 != local_14) {
    *(undefined1 **)(param_1 + 0x34) = local_18;
  }
  return local_8;
}



// ============================================================
// Function: certs_processKeyUsage (FUN_68154ba0)
// Address: 68154ba0
// Size: 183 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

uint certs_processKeyUsage(int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6,
                 int param_7,int *param_8)

{
  uint uVar1;
  int iVar2;
  uint local_8;

  if ((((*(int *)(*(int *)(param_1 + 0x14) + 0x2254) != 0) && ((param_4 & 7) == 0)) &&
      ((param_4 & 0xfffffff8) != 0)) &&
     (((undefined **)(*(uint *)(*(int *)((param_4 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
       &PTR_s_Function_681928b8 &&
      (uVar1 = xtra_getObjectTag(param_1,param_4 & 0xfffffff8), *(int *)(uVar1 + 0xc) != 0)))) {
    if ((param_3 & 1) == 0) {
      local_8 = *(uint *)(param_3 + 8);
    }
    else {
      local_8 = param_3;
    }
    iVar2 = (**(code **)(*(int *)(param_1 + 0x14) + 0x2254))
                      (param_1,param_2,local_8,param_5,&param_4);
    if (iVar2 == 0) {
      return 0;
    }
  }
  uVar1 = certs_validateExtension(param_1,param_2,param_4,0,param_6,param_7,param_8);
  return uVar1;
}



// ============================================================
// Function: certs_processExtension (FUN_68154c60)
// Address: 68154c60
// Size: 547 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, undefined4 param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certs_processExtension(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  code *local_14;
  uint local_10;
  undefined4 local_c;
  int local_8;

  local_14 = *(code **)(*(int *)(param_1 + 0x14) + 0x210);
  local_8 = 0;
  local_18 = *(int *)(param_1 + 0x34);
  local_70 = 0;
  local_74 = 0;
  local_68 = param_3;
  if (param_4 == 0) {
    uVar2 = param_2;
    local_6c = param_2;
    uVar3 = *(uint *)(param_1 + 0x164) & 4;
    while (uVar1 = uVar2, uVar3 != 0) {
      local_10 = *(uint *)(*(int *)(uVar1 + 4) + 4) & 0xfffffff8;
      uVar2 = local_10;
      local_6c = uVar1;
      uVar3 = local_10;
    }
    local_64 = 0;
    local_60 = param_2;
    local_50 = 0;
    local_5c = 0;
    local_4c = 0;
    local_58 = 0;
    local_44 = 0;
    local_2c = 0;
    local_1c = local_6c;
  }
  else {
    local_6c = *(uint *)(param_4 + 8);
    local_64 = *(undefined4 *)(param_4 + 0x10);
    local_60 = *(uint *)(param_4 + 0x14);
    local_5c = *(undefined4 *)(param_4 + 0x18);
    local_58 = *(undefined4 *)(param_4 + 0x1c);
    local_50 = *(undefined4 *)(param_4 + 0x24);
    local_4c = *(undefined4 *)(param_4 + 0x28);
    local_44 = *(undefined4 *)(param_4 + 0x30);
    local_2c = *(undefined4 *)(param_4 + 0x48);
  }
  local_54 = 0x80000001;
  local_48 = param_4;
  local_40 = param_2;
  local_3c = 0;
  if (local_18 == 0) {
    local_78 = 0;
  }
  else {
    local_78 = *(undefined4 *)(local_18 + 0x3c);
  }
  local_38 = local_78;
  local_34 = 0;
  local_30 = 0;
  local_28 = param_5;
  local_24 = 0;
  local_20 = 0;
  if ((local_18 != 0) && (local_18 != param_4)) {
    *(undefined4 *)(local_18 + 0x50) = *(undefined4 *)(param_1 + 0x150);
    *(int *)(param_1 + 0x150) = local_18;
  }
  *(undefined4 **)(param_1 + 0x34) = &local_74;
  if (local_14 != (code *)0x0) {
    local_8 = (*local_14)(param_1,&local_74,1,0,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x214));
  }
  local_c = certificates_executeByteCode(param_1,param_6);
  if ((local_8 != 0) &&
     (local_14 = *(code **)(*(int *)(param_1 + 0x14) + 0x210), local_14 != (code *)0x0)) {
    (*local_14)(param_1,&local_74,0,&local_c,local_8);
  }
  *(int *)(param_1 + 0x34) = local_18;
  if ((local_18 != 0) && (local_18 != param_4)) {
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(local_18 + 0x50);
    *(undefined4 *)(local_18 + 0x50) = 0;
  }
  return local_c;
}



// ============================================================
// Function: certs_verifySignature (FUN_68154e90)
// Address: 68154e90
// Size: 475 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certs_verifySignature(undefined4 param_1,int *param_2,int param_3,uint param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  int local_10;
  int local_c;
  uint local_8;

  iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 8))(param_1,param_2,param_3,&local_14,&local_20);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *param_5 = (uint)(local_20 != 0);
    if (local_20 == 0) {
      uVar2 = 1;
    }
    else {
      local_10 = (**(code **)(*(int *)(*local_14 + 4) + 0x18))
                           (param_1,local_14,param_3,local_20,&local_18);
      if (*(int *)(*(int *)(*local_14 + 4) + 0x34) != 0) {
        (**(code **)(*(int *)(*local_14 + 4) + 0x34))(param_1,local_14,local_20);
      }
      if (local_10 == 0) {
        uVar2 = 0;
      }
      else {
        local_c = (-(uint)(((local_18 | param_4) & 2) != 0) & 0xfffffffb) + 5;
        if (local_c != 0) {
          if ((param_4 & 0x30) == 0) {
            return 1;
          }
          if ((~(local_18 ^ param_4) & 0x30) == 0) {
            return 1;
          }
          if ((local_18 & 4) == 0) {
            return 1;
          }
          local_c = 0;
        }
        local_1c = (uint)((local_18 & 0x30) != 0);
        if (local_1c == 0) {
          iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,param_3,&local_8);
          if (iVar1 == 0) {
            return 0;
          }
          if ((((local_8 & 7) == 0) && ((local_8 & 0xfffffff8) != 0)) &&
             ((undefined **)(*(uint *)(*(int *)((local_8 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
              &PTR_s_Function_681928b8)) {
            local_24 = 1;
          }
          else {
            local_24 = 0;
          }
          local_1c = local_24;
        }
        xtra_getStringValue((uint *)(*(uint *)(param_3 + 8) & 0xfffffff8));
        uVar2 = xtra_invokeWithArgs(param_1,local_c,xtra_getErrorString,0,0x9b);
      }
    }
  }
  return uVar2;
}



