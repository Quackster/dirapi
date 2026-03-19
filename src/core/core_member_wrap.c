// Module: core
// Topic: Member wrapper objects - creation, delegation, property forwarding
// Address range: 0x680161E0 - 0x68017100
// Functions (15):
//   core_delegateWrapCall (0x680161E0)
//   core_releaseWrap (0x68016200)
//   core_delegateWrapNotify (0x68016240)
//   core_delegateWrapAccess (0x68016270)
//   core_wrapMember (0x680162A0)
//   core_unwrapMember (0x68016310)
//   core_setMemberProperty (0x68016E00)
//   core_hasMemberContent (0x68016E60)
//   core_formatMemberError (0x68016E90)
//   core_createMemberRef (0x68016EE0)
//   core_createDefaultMemberRef (0x68016F50)
//   core_getMemberRefNumber (0x68016F90)
//   core_resolveMemberByNumber (0x68016FD0)
//   core_resetMemberField (0x680170A0)
//   core_applyMemberField (0x68017100)

// ============================================================
// Function: core_delegateWrapCall (FUN_680161e0)
// Address: 680161e0
// Size: 28 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_delegateWrapCall(undefined4 param_1,int *param_2)
{
  (*(code *)**(undefined4 **)**(undefined4 **)(*param_2 + 0xc))
            (param_1,*(undefined4 **)(*param_2 + 0xc));
  return 0;
}



// ============================================================
// Function: core_releaseWrap (FUN_68016200)
// Address: 68016200
// Size: 53 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_releaseWrap(int param_1,int *param_2)
{
  props_releaseObject(param_1,*(int **)(*param_2 + 8));
  props_releaseObject(param_1,*(int **)(*param_2 + 0xc));
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: core_delegateWrapNotify (FUN_68016240)
// Address: 68016240
// Size: 33 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_delegateWrapNotify(undefined4 param_1,int *param_2,undefined4 param_3)
{
  (**(code **)(*(int *)**(undefined4 **)(*param_2 + 0xc) + 0x48))
            (param_1,*(undefined4 **)(*param_2 + 0xc),param_3);
  return 0;
}



// ============================================================
// Function: core_delegateWrapAccess (FUN_68016270)
// Address: 68016270
// Size: 33 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_delegateWrapAccess(undefined4 param_1,int *param_2,undefined4 param_3)
{
  (**(code **)(*(int *)**(undefined4 **)(*param_2 + 0xc) + 0x14))
            (param_1,*(undefined4 **)(*param_2 + 0xc),param_3);
  return 0;
}



// ============================================================
// Function: core_wrapMember (FUN_680162a0)
// Address: 680162a0
// Size: 98 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_wrapMember(int param_1,int *param_2,int *param_3,undefined4 *param_4)
{
  undefined4 *puVar1;
  int *piVar2;
  
  *param_4 = 2;
  param_4[1] = 0;
  piVar2 = (int *)Ordinal_1111(0x10,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
    *(int *)(*param_3 + 4) = *(int *)(*param_3 + 4) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[3] = param_3;
    puVar1[1] = 1;
    *puVar1 = &PTR_FUN_6818b4e8;
    puVar1[2] = param_2;
    *param_4 = 3;
    param_4[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_unwrapMember (FUN_68016310)
// Address: 68016310
// Size: 59 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_unwrapMember(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_FUN_6818b4e8)) {
    *param_3 = 3;
    param_3[1] = *(undefined4 *)(*(int *)param_2[1] + 0xc);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_setMemberProperty (FUN_68016e00)
// Address: 68016e00
// Size: 83 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_setMemberProperty(undefined4 *param_1)
{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int unaff_ESI;
  
  puVar4 = (undefined4 *)
           (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
           *(int *)(unaff_ESI + 0x18));
  piVar1 = (int *)puVar4[1];
  uVar2 = *puVar4;
  puVar3 = (undefined4 *)param_1[1];
  *puVar4 = *param_1;
  puVar4[1] = param_1[1];
  props_releaseValue(unaff_ESI,(byte)uVar2,piVar1);
  (**(code **)(*(int *)*puVar3 + 4))();
  return 0;
}



// ============================================================
// Function: core_hasMemberContent (FUN_68016e60)
// Address: 68016e60
// Size: 36 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_hasMemberContent(undefined4 param_1,int *param_2,int param_3)

{
  if (param_3 < 0) {
    return 0 < *(short *)(*param_2 + 8);
  }
  return true;
}



// ============================================================
// Function: core_formatMemberError (FUN_68016e90)
// Address: 68016e90
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatMemberError(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x2f);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: core_createMemberRef (FUN_68016ee0)
// Address: 68016ee0
// Size: 100 bytes
// Params: int param_1, short param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createMemberRef(int param_1,short param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  
  if ((0 < param_2) && (uVar2 = sprites_getMemberCount(param_1), param_2 <= (short)uVar2)) {
    piVar3 = (int *)cast_allocHandle(0xc,0);
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar3;
    *(short *)(puVar1 + 2) = param_2;
    *puVar1 = &PTR_LAB_6818b7b8;
    puVar1[1] = 1;
    *param_3 = 3;
    param_3[1] = piVar3;
    return 0;
  }
  *param_3 = 0;
  return 0;
}



// ============================================================
// Function: core_createDefaultMemberRef (FUN_68016f50)
// Address: 68016f50
// Size: 64 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createDefaultMemberRef(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0xc,0);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *puVar1 = &PTR_LAB_6818b7b8;
    *(undefined2 *)(puVar1 + 2) = 0xffff;
    *param_2 = 3;
    param_2[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_getMemberRefNumber (FUN_68016f90)
// Address: 68016f90
// Size: 49 bytes
// Params: undefined4 param_1, int * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getMemberRefNumber(undefined4 param_1,int *param_2,undefined2 *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818b7b8)) {
    *param_3 = (short)(*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_resolveMemberByNumber (FUN_68016fd0)
// Address: 68016fd0
// Size: 205 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_resolveMemberByNumber(uint param_1)
{
  short sVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
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
  sVar1 = cast_bridgeXtraCall(local_c,*(int **)(param_1 + 0x10),param_1,&local_c);
  if ((0 < sVar1) && (uVar2 = sprites_getMemberCount(param_1), sVar1 <= (short)uVar2)) {
    core_createMemberRef(param_1,sVar1,&local_c);
    props_popArgs(param_1,&local_c);
    return 0;
  }
  if (*(int *)(param_1 + 0xe0) == 0) {
    props_setErrorAndReturn(param_1,0x48);
    return 0;
  }
  local_c = 2;
  local_8 = 0;
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: core_resetMemberField (FUN_680170a0)
// Address: 680170a0
// Size: 93 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall core_resetMemberField(int param_1)
{
  int in_EAX;
  short *unaff_ESI;
  int local_c;
  int local_8;
  
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + -8 + (in_EAX - *(int *)(param_1 + 0x20)) * 8 +
              *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  *unaff_ESI = 0;
  crt_executePlatformSet(param_1,&local_c,sprites_resetMember,unaff_ESI,0x23);
  return 0;
}



// ============================================================
// Function: core_applyMemberField (FUN_68017100)
// Address: 68017100
// Size: 93 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall core_applyMemberField(int param_1)
{
  int in_EAX;
  short *unaff_ESI;
  int local_c;
  int local_8;
  
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + -8 + (in_EAX - *(int *)(param_1 + 0x20)) * 8 +
              *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  *unaff_ESI = 0;
  crt_executePlatformSetEx(param_1,&local_c,sprites_getMemberByIndex,unaff_ESI,0x23);
  return 0;
}


