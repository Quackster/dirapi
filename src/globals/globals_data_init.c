// Module: globals
// Topic: Object factory functions and global data initialization
// Address range: 0x68171B20 - 0x68172670
// Functions (11):
//   globals_createStringIoObject
//   globals_createByteIoObject
//   globals_createPropertyObject
//   globals_createPairObject
//   globals_createAccessorObject
//   globals_createReadWriteObject
//   globals_createMediaDispatchObject
//   globals_createVectorObject
//   globals_createExtPropertyObject
//   globals_initPropertyData
//   globals_packBitfield

// ============================================================
// Function: globals_createStringIoObject (FUN_68171b20)
// Address: 68171b20
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createStringIoObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initStringIoVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createByteIoObject (FUN_68171b80)
// Address: 68171b80
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createByteIoObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initByteIoVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createPropertyObject
// Address: 68171be0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createPropertyObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initPropertyVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createPairObject (FUN_68171c40)
// Address: 68171c40
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createPairObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initPairVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createAccessorObject (FUN_68171ca0)
// Address: 68171ca0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createAccessorObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initAccessorVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createReadWriteObject (FUN_68171d00)
// Address: 68171d00
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createReadWriteObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initReadWriteVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createMediaDispatchObject (FUN_68171d60)
// Address: 68171d60
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createMediaDispatchObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initMediaDispatchVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createVectorObject (FUN_68171dc0)
// Address: 68171dc0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createVectorObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initVectorVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_createExtPropertyObject (FUN_68171e20)
// Address: 68171e20
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createExtPropertyObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initExtPropertyVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: globals_initPropertyData (FUN_68171e80)
// Address: 68171e80
// Size: 2022 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int globals_initPropertyData(void)
{
  if (DAT_68197250 == 0) {
    DAT_68197250 = 1;
    _DAT_68196a68 = 1;
    _DAT_68196a6c = 0;
    _DAT_68196a70 = 0xffffffff;
    _DAT_68196a74 = 0;
    _DAT_68196a78 = 0xffffffff;
    _DAT_68196a7c = 0;
    _DAT_68196a80 = 0xffffffff;
    _DAT_68196a84 = 0;
    _DAT_68196a88 = 0xffffffff;
    _DAT_68196a8c = 0;
    _DAT_68196a90 = 0xffffffff;
    _DAT_68196a94 = 0;
    _DAT_68196a98 = 0;
    _DAT_68196a9c = 0;
    _DAT_68196aa0 = 0xffffffff;
    _DAT_68196aa4 = 0;
    _DAT_68196aa8 = 0xffffffff;
    _DAT_68196aac = 0;
    _DAT_68196ab0 = 0xffffffff;
    _DAT_68196ab4 = 0;
    _DAT_68196ab8 = 0xffffffff;
    _DAT_68196abc = 0;
    _DAT_68196ac0 = 0xffffffff;
    _DAT_68196ac4 = 0;
    _DAT_68196ac8 = 0xffffffff;
    _DAT_68196acc = 0;
    _DAT_68196ad0 = 0xffffffff;
    _DAT_68196ad4 = 0;
    _DAT_68196ad8 = 0xffffffff;
    _DAT_68196adc = 0;
    _DAT_68196ae0 = 0xffffffff;
    _DAT_68196ae4 = 0;
    _DAT_68196ae8 = 0xffffffff;
    _DAT_68196aec = 0;
    _DAT_68196af0 = 0;
    _DAT_68196af4 = 0;
    _DAT_68196af8 = 0xffffffff;
    _DAT_68196afc = 0;
    _DAT_68196b00 = 0xffffffff;
    _DAT_68196b04 = 0;
    _DAT_68196b08 = 0xfffffff8;
    _DAT_68196b0c = 0;
    _DAT_68196b10 = 0xfffffff6;
    _DAT_68196b14 = 0;
    _DAT_68196b18 = 0xffffffff;
    _DAT_68196b1c = 0;
    _DAT_68196b20 = 0xffffffff;
    _DAT_68196b24 = 0;
    _DAT_68196b28 = 0xffffffff;
    _DAT_68196b2c = 0;
    _DAT_68196b30 = 2;
    _DAT_68196b34 = 0;
    _DAT_68196b38 = 0xfffffffd;
    _DAT_68196b3c = 0;
    _DAT_68196b40 = 0;
    _DAT_68196b44 = 3;
    _DAT_68196b48 = 0;
    _DAT_68196b4c = 3;
    _DAT_68196b50 = 0;
    _DAT_68196b54 = 0;
    _DAT_68196b58 = 0;
    _DAT_68196b5c = 0;
    _DAT_68196b60 = 0xfffffff7;
    _DAT_68196b64 = 0;
    _DAT_68196b68 = 0;
    _DAT_68196b6c = 0;
    _DAT_68196c58 = 1;
    _DAT_68196c5c = 0;
    _DAT_68196e58 = 1;
    _DAT_68196e5c = 0;
    _DAT_68197058 = 1;
    _DAT_6819705c = 0;
    _DAT_68196c60 = 1;
    _DAT_68196c64 = 1;
    _DAT_68196e60 = 1;
    _DAT_68196e64 = 1;
    _DAT_68197060 = 1;
    _DAT_68197064 = 1;
    _DAT_68196c68 = 1;
    _DAT_68196c6c = 2;
    _DAT_68196e68 = 1;
    _DAT_68196e6c = 2;
    _DAT_68197068 = 1;
    _DAT_6819706c = 2;
    _DAT_68196c70 = 1;
    _DAT_68196c74 = 0;
    _DAT_68196e70 = 1;
    _DAT_68196e74 = 0;
    _DAT_68197070 = 1;
    _DAT_68197074 = 0;
    _DAT_68196c78 = 1;
    _DAT_68196c7c = 0;
    _DAT_68196e78 = 1;
    _DAT_68196e7c = 0;
    _DAT_68197078 = 1;
    _DAT_6819707c = 0;
    _DAT_68196c80 = 1;
    _DAT_68196c84 = 0;
    _DAT_68196e80 = 1;
    _DAT_68196e84 = 0;
    _DAT_68197080 = 1;
    _DAT_68197084 = 0;
    _DAT_68196c88 = 1;
    _DAT_68196c8c = 0;
    _DAT_68196e88 = 1;
    _DAT_68196e8c = 0;
    _DAT_68197088 = 1;
    _DAT_6819708c = 0;
    _DAT_68196c90 = 1;
    _DAT_68196c94 = 0;
    _DAT_68196e90 = 1;
    _DAT_68196e94 = 0;
    _DAT_68197090 = 1;
    _DAT_68197094 = 0;
    _DAT_68196c98 = 1;
    _DAT_68196c9c = 0;
    _DAT_68196e98 = 1;
    _DAT_68196e9c = 0;
    _DAT_68197098 = 1;
    _DAT_6819709c = 0;
    _DAT_68196ca0 = 1;
    _DAT_68196ca4 = 0;
    _DAT_68196ea0 = 1;
    _DAT_68196ea4 = 0;
    _DAT_681970a0 = 1;
    _DAT_681970a4 = 0;
    _DAT_68196ca8 = 1;
    _DAT_68196cac = 0;
    _DAT_68196ea8 = 1;
    _DAT_68196eac = 0;
    _DAT_681970a8 = 1;
    _DAT_681970ac = 0;
    _DAT_68196cb0 = 1;
    _DAT_68196cb4 = 0;
    _DAT_68196eb0 = 1;
    _DAT_68196eb4 = 0;
    _DAT_681970b0 = 1;
    _DAT_681970b4 = 0;
    _DAT_68196cb8 = 0xffffffff;
    _DAT_68196cbc = 0;
    _DAT_68196eb8 = 0xffffffff;
    _DAT_68196ebc = 0;
    _DAT_681970b8 = 0xffffffff;
    _DAT_681970bc = 0;
    _DAT_68196cc0 = 0xffffffff;
    _DAT_68196cc4 = 0;
    _DAT_68196ec0 = 0xffffffff;
    _DAT_68196ec4 = 0;
    _DAT_681970c0 = 0xffffffff;
    _DAT_681970c4 = 0;
    _DAT_68196cc8 = 0xffffffff;
    _DAT_68196ccc = 0;
    _DAT_68196ec8 = 0xffffffff;
    _DAT_68196d14 = 4;
    _DAT_68196f14 = 4;
    _DAT_68197114 = 4;
    _DAT_68196d1c = 5;
    _DAT_68196f1c = 5;
    _DAT_6819711c = 5;
    _DAT_68196d24 = 6;
    _DAT_68196f24 = 6;
    _DAT_68197124 = 6;
    _DAT_68196d2c = 7;
    _DAT_68196f2c = 7;
    _DAT_6819712c = 7;
    _DAT_68196ecc = 0;
    _DAT_681970c8 = 0xffffffff;
    _DAT_681970cc = 0;
    _DAT_68196cd0 = 0xffffffff;
    _DAT_68196cd4 = 0;
    _DAT_68196ed0 = 0xffffffff;
    _DAT_68196ed4 = 0;
    _DAT_681970d0 = 0xffffffff;
    _DAT_681970d4 = 0;
    _DAT_68196cd8 = 0xffffffff;
    _DAT_68196cdc = 0;
    _DAT_68196ed8 = 0xffffffff;
    _DAT_68196edc = 0;
    _DAT_681970d8 = 0xffffffff;
    _DAT_681970dc = 0;
    _DAT_68196ce0 = 0xffffffff;
    _DAT_68196ce4 = 0;
    _DAT_68196ee0 = 0xffffffff;
    _DAT_68196ee4 = 0;
    _DAT_681970e0 = 0xffffffff;
    _DAT_681970e4 = 0;
    _DAT_68196ce8 = 0;
    _DAT_68196cec = 0;
    _DAT_68196ee8 = 0;
    _DAT_68196eec = 0;
    _DAT_681970e8 = 0;
    _DAT_681970ec = 0;
    _DAT_68196cf0 = 0;
    _DAT_68196cf4 = 0;
    _DAT_68196ef0 = 0;
    _DAT_68196ef4 = 0;
    _DAT_681970f0 = 0;
    _DAT_681970f4 = 0;
    _DAT_68196cf8 = 0xffffffff;
    _DAT_68196cfc = 0;
    _DAT_68196ef8 = 0xffffffff;
    _DAT_68196efc = 0;
    _DAT_681970f8 = 0xffffffff;
    _DAT_681970fc = 0;
    _DAT_68196d00 = 0;
    _DAT_68196d04 = 3;
    _DAT_68196f00 = 0;
    _DAT_68196f04 = 3;
    _DAT_68197100 = 0;
    _DAT_68197104 = 3;
    _DAT_68196d08 = 0;
    _DAT_68196d0c = 3;
    _DAT_68196f08 = 0;
    _DAT_68196f0c = 3;
    _DAT_68197108 = 0;
    _DAT_6819710c = 3;
    _DAT_68196d10 = 0;
    _DAT_68196f10 = 0;
    _DAT_68197110 = 0;
    _DAT_68196d18 = 0;
    _DAT_68196f18 = 0;
    _DAT_68197118 = 0;
    _DAT_68196d20 = 0;
    _DAT_68196f20 = 0;
    _DAT_68197120 = 0;
    _DAT_68196d28 = 0;
    _DAT_68196f28 = 0;
    _DAT_68197128 = 0;
    _DAT_68196d30 = 0;
    _DAT_68196d34 = 8;
    _DAT_68196f34 = 8;
    _DAT_68197134 = 8;
    _DAT_68196d50 = 0xffffffff;
    _DAT_68196f50 = 0xffffffff;
    _DAT_68197150 = 0xffffffff;
    _DAT_68196d3c = 9;
    _DAT_68196f3c = 9;
    _DAT_6819713c = 9;
    _DAT_68196d60 = 0xfffffffe;
    _DAT_68196f60 = 0xfffffffe;
    _DAT_68197160 = 0xfffffffe;
    _DAT_68196d6c = 3;
    _DAT_68196f6c = 3;
    _DAT_6819716c = 3;
    _DAT_68196d84 = 3;
    _DAT_68196f84 = 3;
    _DAT_68197184 = 3;
    _DAT_68196d94 = 0xfffffffe;
    _DAT_68196f94 = 0xfffffffe;
    _DAT_68197194 = 0xfffffffe;
    _DAT_68196f30 = 0;
    _DAT_68197130 = 0;
    _DAT_68196d38 = 0;
    _DAT_68196f38 = 0;
    _DAT_68197138 = 0;
    _DAT_68196d48 = 1;
    _DAT_68196d4c = 0;
    _DAT_68196f48 = 1;
    _DAT_68196f4c = 0;
    _DAT_68197148 = 1;
    _DAT_6819714c = 0;
    _DAT_68196d54 = 0;
    _DAT_68196f54 = 0;
    _DAT_68197154 = 0;
    _DAT_68196d58 = 0;
    _DAT_68196d5c = 0;
    _DAT_68196f58 = 0;
    _DAT_68196f5c = 0;
    _DAT_68197158 = 0;
    _DAT_6819715c = 0;
    _DAT_68196d64 = 0;
    _DAT_68196f64 = 0;
    _DAT_68197164 = 0;
    _DAT_68196d68 = 0;
    _DAT_68196f68 = 0;
    _DAT_68197168 = 0;
    _DAT_68196d70 = 1;
    _DAT_68196d74 = 0;
    _DAT_68196f70 = 1;
    _DAT_68196f74 = 0;
    _DAT_68197170 = 1;
    _DAT_68197174 = 0;
    _DAT_68196d78 = 0;
    _DAT_68196d7c = 10;
    _DAT_68196f78 = 0;
    _DAT_68196f7c = 10;
    _DAT_68197178 = 0;
    _DAT_6819717c = 10;
    _DAT_68196d80 = 0;
    _DAT_68196f80 = 0;
    _DAT_68197180 = 0;
    _DAT_68196d88 = 0;
    _DAT_68196d8c = 0xd;
    _DAT_68196f88 = 0;
    _DAT_68196f8c = 0xd;
    _DAT_68197188 = 0;
    _DAT_6819718c = 0xd;
    _DAT_68196d90 = 0;
    _DAT_68196f90 = 0;
    _DAT_68197190 = 0;
    _DAT_68196d98 = 0;
    _DAT_68196d9c = 0xfffffff6;
    _DAT_68196f98 = 0;
    _DAT_68196f9c = 0xfffffff6;
    _DAT_68197198 = 0;
    _DAT_6819719c = 0xfffffff6;
    _DAT_68196da4 = 0xfffffff7;
    _DAT_68196fa4 = 0xfffffff7;
    _DAT_681971a4 = 0xfffffff7;
    _DAT_68196dac = 0xb;
    _DAT_68196fac = 0xb;
    _DAT_681971ac = 0xb;
    _DAT_68196da0 = 0;
    _DAT_68196fa0 = 0;
    _DAT_681971a0 = 0;
    _DAT_68196da8 = 0;
    _DAT_68196fa8 = 0;
    _DAT_681971a8 = 0;
    _DAT_68196db0 = 0;
    _DAT_68196db4 = 0xc;
    _DAT_68196fb0 = 0;
    _DAT_68196fb4 = 0xc;
    _DAT_681971b0 = 0;
    _DAT_681971b4 = 0xc;
    _DAT_68196db8 = 0;
    _DAT_68196dbc = 0;
    _DAT_68196fb8 = 0;
    _DAT_68196fbc = 0;
    _DAT_681971b8 = 0;
    _DAT_681971bc = 0;
    _DAT_68196dc0 = 1;
    _DAT_68196dc4 = 0;
    _DAT_68196fc0 = 1;
    _DAT_68196fc4 = 0;
    _DAT_681971c0 = 1;
    _DAT_681971c4 = 0;
    _DAT_68196dc8 = 1;
    _DAT_68196dcc = 0;
    _DAT_68196fc8 = 1;
    _DAT_68196fcc = 0;
    _DAT_681971c8 = 1;
    _DAT_681971cc = 0;
    _DAT_68196dd0 = 0;
    _DAT_68196dd4 = 0;
    _DAT_68196fd0 = 0;
    _DAT_68196fd4 = 0;
    _DAT_681971d0 = 0;
    _DAT_681971d4 = 0;
  }
  return 0;
}



// ============================================================
// Function: globals_packBitfield (FUN_68172670)
// Address: 68172670
// Size: 18 bytes
// Params: uint * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall globals_packBitfield(uint *param_1)
{
  *param_1 = (*param_1 & 0xfffffff0) << 5 | *param_1 & 0xf;
  return 0;
}


