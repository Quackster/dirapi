// Module: globals
// Topic: Cast member data parsing, bytecode analysis, serialization, and utility functions
// Address range: 0x68172690 - 0x68174760
// Functions (41):
//   globals_readCastDispatch
//   globals_readBytecodeBlock
//   globals_getSerializationFlags
//   globals_serializeField
//   globals_serializeFieldPairs
//   globals_deserializeCastFields
//   globals_deserializeIndexFields
//   globals_deserializeField
//   globals_analyzeBytecode
//   globals_readMethodTable
//   globals_readCastMember
//   globals_writeCastDispatch
//   globals_writeBytecodeBlock
//   globals_resetSerializer
//   globals_serializeCast
//   globals_serializePropertyIndex
//   globals_getSerializerState
//   globals_writeMethodTable
//   globals_serializeFieldDescriptors
//   globals_writeCastFields
//   globals_writeCastMember
//   globals_getMciError
//   globals_sendMciCommand
//   operator_delete
//   operator_new
//   globals_reverseBytes10
//   globals_initSerializer
//   globals_floatFromExtended
//   globals_floatFromDouble
//   globals_floatToExtended
//   globals_readSerializedData

// ============================================================
// Function: globals_readCastDispatch (FUN_68172690)
// Address: 68172690
// Size: 533 bytes
// Params: undefined4 param_1, undefined4 * param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_readCastDispatch(undefined4 param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  int local_8;

  piVar10 = (int *)0x0;
  local_8 = 0;
  *param_2 = 0;
  iVar3 = Ordinal_1404(&local_8,param_1,1);
  uVar7 = (uint)(iVar3 == 0);
  if ((iVar3 == 0) == 0) {
    uVar4 = Ordinal_1415(local_8);
    uVar5 = Ordinal_1414(local_8);
    iVar3 = Ordinal_1414(local_8);
    Ordinal_1414(local_8);
    Ordinal_1412(local_8);
    Ordinal_1412(local_8);
    piVar10 = stage_allocDispatchEntry(0xb8,0xa8,0x10,iVar3);
    uVar7 = DAT_68195a8c;
    if (piVar10 != (int *)0x0) {
      Ordinal_1114(piVar10);
      puVar9 = (undefined4 *)*piVar10;
      *puVar9 = uVar4;
      puVar9[1] = uVar5;
      uVar4 = Ordinal_1414(local_8);
      puVar9[8] = uVar4;
      uVar4 = Ordinal_1414(local_8);
      puVar9[9] = uVar4;
      uVar4 = Ordinal_1414(local_8);
      puVar9[10] = uVar4;
      uVar4 = Ordinal_1414(local_8);
      puVar9[0xb] = uVar4;
      sVar2 = Ordinal_1412(local_8);
      puVar9[0xc] = (int)sVar2;
      sVar2 = Ordinal_1412(local_8);
      puVar9[0xd] = (int)sVar2;
      sVar2 = Ordinal_1412(local_8);
      puVar9[0xe] = (int)sVar2;
      sVar2 = Ordinal_1412(local_8);
      puVar9[0xf] = (int)sVar2;
      sVar2 = Ordinal_1412(local_8);
      puVar9[0x10] = (int)sVar2;
      piVar8 = puVar9 + 0x11;
      if (param_3 < 0x500) {
        param_3 = 0x12;
        do {
          sVar2 = Ordinal_1412(local_8);
          *piVar8 = (int)sVar2;
          piVar8 = piVar8 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      else {
        param_3 = 0x19;
        do {
          sVar2 = Ordinal_1412(local_8);
          *piVar8 = (int)sVar2;
          piVar8 = piVar8 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      Ordinal_1115(piVar10);
      iVar6 = stage_emitStoreVar(piVar10,iVar3 + -1);
      uVar1 = DAT_68195a8c;
      if (iVar6 == 0) {
        cast_freeHandle(piVar10);
        piVar10 = (int *)0x0;
        uVar7 = uVar1;
      }
      else {
        Ordinal_1114();
        puVar9 = (undefined4 *)(*piVar10 + 0xa8);
        for (; 0 < iVar3; iVar3 = iVar3 + -1) {
          uVar4 = Ordinal_1415(local_8);
          *puVar9 = uVar4;
          uVar4 = Ordinal_1414(local_8);
          puVar9[1] = uVar4;
          sVar2 = Ordinal_1412(local_8);
          puVar9[2] = (int)sVar2;
          sVar2 = Ordinal_1412(local_8);
          puVar9[3] = (int)sVar2;
          puVar9 = puVar9 + 4;
        }
        Ordinal_1115(piVar10);
        stage_emitPopVar(piVar10);
      }
    }
  }
  *param_2 = piVar10;
  cast_freeHandle(param_1);
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  return uVar7;
}



// ============================================================
// Function: globals_readBytecodeBlock (FUN_681728b0)
// Address: 681728b0
// Size: 189 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool globals_readBytecodeBlock(undefined4 param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int local_8;

  piVar4 = (int *)0x0;
  local_8 = 0;
  *param_2 = 0;
  iVar2 = Ordinal_1404(&local_8,param_1,3);
  bVar5 = iVar2 == 0;
  if (!bVar5) {
    iVar2 = Ordinal_1116(param_1);
    piVar4 = (int *)stage_createBytecodeBlock(0x24,0x20,iVar2 + -0x12);
    if (piVar4 == (int *)0x0) goto LAB_68172945;
    iVar3 = Ordinal_1432(local_8,0x12,0);
    bVar5 = iVar3 == 0;
    if (!bVar5) {
      sVar1 = Ordinal_1412(local_8);
      *(int *)(*piVar4 + 0x1c) = (int)sVar1;
      Ordinal_1114(piVar4);
      iVar2 = Ordinal_1409(local_8,*piVar4 + 0x20,iVar2 + -0x14);
      bVar5 = iVar2 == 0;
      if (!bVar5) goto LAB_68172945;
    }
  }
  cast_freeHandle(piVar4);
  piVar4 = (int *)0x0;
LAB_68172945:
  *param_2 = piVar4;
  cast_freeHandle(param_1);
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  return bVar5;
}



// ============================================================
// Function: globals_getSerializationFlags (FUN_68172970)
// Address: 68172970
// Size: 28 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_getSerializationFlags(void)

{
  uint uVar1;
  int *unaff_ESI;

  uVar1 = *(uint *)(*unaff_ESI + 0x10);
  if ((uVar1 & 3) != 0) {
    stage_emitPushVar(unaff_ESI,uVar1 + 3 & 0xfffffffc);
    uVar1 = *(uint *)(*unaff_ESI + 0x10);
  }
  return uVar1;
}



// ============================================================
// Function: globals_serializeField (FUN_68172990)
// Address: 68172990
// Size: 103 bytes
// Params: void * this, undefined4 param_1
// Return: uint
// Calling convention: __thiscall
// ============================================================

uint __thiscall globals_serializeField(void *this,undefined4 param_1)

{
  short sVar1;
  int in_EAX;
  uint uVar2;
  int *piVar3;

  uVar2 = globals_getSerializationFlags();
  if ((-1 < (int)uVar2) && (-1 < in_EAX)) {
    stage_emitPushVar(this,uVar2 + in_EAX * 4);
    Ordinal_1114(this);
    piVar3 = (int *)(*(int *)this + uVar2);
    for (; 0 < in_EAX; in_EAX = in_EAX + -1) {
      sVar1 = Ordinal_1412(param_1);
      *piVar3 = (int)sVar1;
      piVar3 = piVar3 + 1;
    }
    Ordinal_1115(this);
    return uVar2;
  }
  return 0xffffffff;
}



// ============================================================
// Function: globals_serializeFieldPairs (FUN_68172a00)
// Address: 68172a00
// Size: 134 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_serializeFieldPairs(int *param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  int *piVar4;

  uVar2 = globals_getSerializationFlags();
  if ((-1 < (int)uVar2) && (-1 < in_EAX)) {
    stage_emitPushVar(param_1,uVar2 + in_EAX * 8);
    Ordinal_1114(param_1);
    piVar4 = (int *)(*param_1 + uVar2);
    for (; 0 < in_EAX; in_EAX = in_EAX + -1) {
      if (param_3 < 0x500) {
        sVar1 = Ordinal_1412(param_2);
        iVar3 = (int)sVar1;
      }
      else {
        iVar3 = Ordinal_1414(param_2);
      }
      *piVar4 = iVar3;
      iVar3 = Ordinal_1414(param_2);
      piVar4[1] = iVar3;
      piVar4 = piVar4 + 2;
    }
    Ordinal_1115(param_1);
  }
  return uVar2;
}



// ============================================================
// Function: globals_deserializeCastFields (FUN_68172a90)
// Address: 68172a90
// Size: 598 bytes
// Params: int * param_1, undefined4 param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall globals_deserializeCastFields(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  double local_50;
  double local_48;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  byte *local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  uint local_8;

  local_3c = param_3;
  local_34 = (uint)(param_5 < 0x500);
  local_2c = *(int *)(*param_1 + 0x8c);
  local_24 = param_2;
  local_38 = Ordinal_1435(param_2);
  local_28 = globals_getSerializationFlags();
  iVar4 = *(int *)(*param_1 + 0x88);
  local_20 = 0;
  local_40 = iVar4;
  if (0 < iVar4) {
    do {
      local_30 = (byte *)(*param_1 + local_20 * 8 + local_2c);
      if ((*local_30 & 1) != 0) {
        Ordinal_1432(param_2,*(int *)(local_30 + 4) + param_4,0);
        uVar2 = Ordinal_1414(param_2);
        if (local_38 < uVar2) goto LAB_68172cd0;
        iVar4 = *(int *)(*param_1 + 0x10);
        if (*(int *)local_30 == 9) {
          if (local_34 == 0) {
            if (8 < uVar2) goto LAB_68172cd0;
            Ordinal_1409(local_24,&local_1c,uVar2);
            fVar5 = (float10)globals_floatFromDouble(local_1c,local_18);
            local_50 = (double)fVar5;
            stage_emitPushVar(param_1,iVar4 + 0xc);
            *(undefined4 *)(iVar4 + *param_1) = 8;
            globals_readSerializedData((undefined8 *)(*param_1 + 4 + iVar4),&local_50);
          }
          else {
            if (10 < uVar2) {
LAB_68172cd0:
              return 0;
            }
            Ordinal_1409(local_24,&local_14,uVar2);
            fVar5 = (float10)globals_floatFromExtended(local_14,local_10,local_c);
            local_48 = (double)fVar5;
            stage_emitPushVar(param_1,iVar4 + 0xc);
            *(undefined4 *)(iVar4 + *param_1) = 8;
            globals_readSerializedData((undefined8 *)(*param_1 + 4 + iVar4),&local_48);
          }
        }
        else {
          stage_emitPushVar(param_1,iVar4 + 4 + uVar2);
          Ordinal_1114(param_1);
          *(uint *)(iVar4 + *param_1) = uVar2;
          local_30 = (byte *)(*param_1 + 4 + iVar4);
          Ordinal_1409(local_24,local_30,uVar2);
          if ((*(int *)(*param_1 + local_20 * 8 + local_2c) == 1) && (param_5 < 0x1100)) {
            events_writeChannelProperty(local_3c,local_30,uVar2,1);
          }
          Ordinal_1115(param_1);
        }
        piVar3 = (int *)(*param_1 + local_20 * 8 + local_2c);
        iVar1 = *piVar3;
        if ((((iVar1 == 1) || (iVar1 == 0x40)) || (iVar1 == 0x43)) ||
           (((iVar1 == 9 || (iVar1 == 4)) || (iVar1 == 0xb)))) {
          piVar3[1] = iVar4 - local_28;
        }
        else {
          piVar3[1] = 0;
        }
        globals_getSerializationFlags();
        iVar4 = local_40;
        param_2 = local_24;
      }
      local_20 = local_20 + 1;
    } while (local_20 < iVar4);
  }
  *(uint *)(*param_1 + 0x90) = *(int *)(*param_1 + 0x10) - local_28;
  globals_getSerializationFlags();
  return 0;
}



// ============================================================
// Function: globals_deserializeIndexFields (FUN_68172cf0)
// Address: 68172cf0
// Size: 261 bytes
// Params: void * this, undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall globals_deserializeIndexFields(void *this,undefined4 param_1,int param_2)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  int iVar5;
  undefined4 *puVar6;
  int local_70 [5];
  int aiStack_5c [21];
  uint local_8;

  iVar3 = unaff_EBX;
  if ((param_2 < 0x500) && (4 < unaff_EBX)) {
    iVar3 = unaff_EBX + 5;
  }
  uVar2 = globals_getSerializationFlags();
  if ((-1 < (int)uVar2) && (-1 < unaff_EBX)) {
    stage_emitPushVar(this,uVar2 + iVar3 * 4);
    Ordinal_1114(this);
    if (param_2 < 0x500) {
      iVar5 = 0;
      if (0 < unaff_EBX) {
        do {
          sVar1 = Ordinal_1412(param_1);
          local_70[iVar5] = (int)sVar1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < unaff_EBX);
      }
      puVar4 = (undefined4 *)(*(int *)this + uVar2);
      puVar6 = puVar4;
      if (0 < iVar3) {
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = 0xffffffff;
          puVar6 = puVar6 + 1;
        }
      }
      iVar3 = 0;
      if (0 < unaff_EBX) {
        do {
          iVar5 = iVar3 * 4 - (int)local_70;
          if (iVar3 < 5) {
            *(int *)((int)puVar4 + (int)local_70 + iVar5) = local_70[iVar3];
          }
          else {
            *(int *)((int)puVar4 + (int)aiStack_5c + iVar5) = local_70[iVar3];
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < unaff_EBX);
      }
    }
    else {
      iVar3 = *(int *)this;
      iVar5 = 0;
      if (0 < unaff_EBX) {
        do {
          sVar1 = Ordinal_1412(param_1);
          *(int *)(iVar3 + uVar2 + iVar5 * 4) = (int)sVar1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < unaff_EBX);
      }
    }
    Ordinal_1115(this);
  }
  return 0;
}



// ============================================================
// Function: globals_deserializeField (FUN_68172e10)
// Address: 68172e10
// Size: 59 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_deserializeField(undefined4 param_1)
{
  int iVar1;
  int in_EAX;
  int *unaff_ESI;
  uint uVar2;

  iVar1 = *(int *)(*unaff_ESI + 0x10);
  uVar2 = in_EAX + 1U & 0xfffffffe;
  stage_emitPushVar(unaff_ESI,iVar1 + uVar2);
  Ordinal_1114();
  Ordinal_1409(param_1,*unaff_ESI + iVar1,uVar2);
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: globals_analyzeBytecode (FUN_68172e50)
// Address: 68172e50
// Size: 820 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4, int * param_5, int param_6
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
globals_analyzeBytecode(undefined4 param_1,int *param_2,int param_3,int param_4,int *param_5,int param_6)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  ushort uVar4;
  bool bVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int local_18;
  byte *local_10;
  uint local_8;

  iVar9 = 0;
  uVar11 = 0;
  local_10 = (byte *)0x0;
  local_8 = 0;
  bVar5 = false;
  local_18 = 0;
  uVar1 = (uint)(0x4ff < param_6) * 2 + 6;
  pbVar7 = (byte *)(*param_2 + param_3);
  for (; pbVar6 = pbVar7, 0 < param_4; param_4 = param_4 - (uVar12 + 1)) {
    uVar13 = (uint)*pbVar6;
    bVar3 = *pbVar6 >> 6;
    uVar12 = (uint)bVar3;
    iVar10 = 0;
    switch(*(undefined4 *)(&DAT_68196a54 + uVar13 * 8)) {
    case 1:
      uVar11 = (uint)pbVar6[1];
      iVar10 = 1;
      if (uVar12 != 1) {
        uVar4 = CONCAT11(pbVar6[1],pbVar6[2]);
        uVar11 = (uint)uVar4;
        if (uVar12 != 2) {
          uVar11 = CONCAT31(CONCAT21(uVar4,pbVar6[3]),pbVar6[4]);
        }
      }
      uVar11 = uVar11 + 1;
      local_8 = uVar11;
      break;
    case 2:
      uVar11 = (uint)pbVar6[1];
      iVar10 = 1;
      local_8 = uVar11;
      if (uVar12 != 1) {
        uVar4 = CONCAT11(pbVar6[1],pbVar6[2]);
        uVar11 = (uint)uVar4;
        local_8 = uVar11;
        if (uVar12 != 2) {
          uVar11 = CONCAT31(CONCAT21(uVar4,pbVar6[3]),pbVar6[4]);
          local_8 = uVar11;
        }
      }
      break;
    case 3:
      iVar10 = -uVar11;
      break;
    case 4:
      iVar10 = -1 - uVar11;
      break;
    case 5:
      bVar8 = pbVar6[1];
      iVar10 = -2;
      if ((uVar12 != 1) && (bVar8 = pbVar6[2], uVar11 = local_8, uVar12 != 2)) {
        bVar8 = pbVar6[4];
      }
      if ((bVar8 & 0xf) == 6) {
        iVar10 = -3;
      }
      break;
    case 6:
      bVar8 = pbVar6[1];
      iVar10 = -10;
      if ((uVar12 != 1) && (bVar8 = pbVar6[2], uVar11 = local_8, uVar12 != 2)) {
        bVar8 = pbVar6[4];
      }
      if ((bVar8 & 0xf) == 6) {
        iVar10 = -0xb;
      }
      break;
    case 7:
      bVar8 = pbVar6[1];
      iVar10 = -9;
      if ((uVar12 != 1) && (bVar8 = pbVar6[2], uVar11 = local_8, uVar12 != 2)) {
        bVar8 = pbVar6[4];
      }
      if ((bVar8 & 0xf) == 6) {
        iVar10 = -10;
      }
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
      bVar5 = true;
      break;
    default:
      iVar10 = *(int *)(&DAT_68196a50 + uVar13 * 8);
    }
    iVar9 = iVar9 + iVar10;
    if (local_18 < iVar9) {
      local_18 = iVar9;
    }
    if (uVar1 == 6) {
      switch(uVar13) {
      case 0x18:
        *pbVar6 = 0x22;
        break;
      case 0x1b:
        *pbVar6 = 0x23;
        break;
      case 0x59:
        *pbVar6 = 0x68;
        break;
      case 0x5a:
        *pbVar6 = 0x69;
        break;
      case 0x5b:
        *pbVar6 = 0x6a;
        break;
      case 0x5c:
        *pbVar6 = 0x6b;
        break;
      case 0x5d:
        *pbVar6 = 0x6c;
      }
    }
    if (bVar3 != 0) {
      switch(uVar13 & 0xffffff3f) {
      case 1:
        if (uVar12 == 2) {
          *pbVar6 = 0xae;
        }
        break;
      case 4:
      case 0xb:
      case 0xc:
      case 0x11:
      case 0x12:
        if (uVar12 == 1) {
          pbVar6[1] = (byte)((ulonglong)pbVar6[1] / (ulonglong)(longlong)(int)uVar1);
        }
        else if (uVar12 == 2) {
          uVar2 = (ulonglong)CONCAT11(pbVar6[1],pbVar6[2]) / (ulonglong)uVar1;
          pbVar6[1] = (byte)(uVar2 >> 8);
          pbVar6[2] = (byte)uVar2;
        }
        break;
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
        if ((local_10 != (byte *)0x0) && (((pbVar6[1] & 0xcf) == 4 || ((pbVar6[1] & 0xcf) == 5)))) {
          bVar8 = *local_10 & 0x3f;
          bVar3 = *local_10 >> 6;
          if ((bVar8 == 1) || (bVar8 == 0x2e)) {
            if (bVar3 == 1) {
              local_10[1] = (byte)((ulonglong)local_10[1] / (ulonglong)(longlong)(int)uVar1);
            }
            else if (bVar3 == 2) {
              uVar2 = (ulonglong)CONCAT11(local_10[1],local_10[2]) / (ulonglong)uVar1;
              local_10[1] = (byte)(uVar2 >> 8);
              local_10[2] = (byte)uVar2;
            }
          }
        }
      }
    }
    pbVar7 = pbVar6 + uVar12 + 1;
    local_10 = pbVar6;
  }
  *param_5 = local_18;
  if ((iVar9 != 0) && ((!bVar5 || (iVar9 < 1)))) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: globals_readMethodTable (FUN_68173250)
// Address: 68173250
// Size: 744 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, int param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

uint globals_readMethodTable(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_EBX;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int local_58 [6];
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;

  local_14 = (uint)(param_5 < 0x500);
  local_1c = (uint)(0x800 < param_5) * 4 + 0x2a;
  uVar4 = globals_getSerializationFlags();
  if ((-1 < (int)uVar4) && (-1 < param_3)) {
    local_10 = uVar4;
    local_18 = Ordinal_1435();
    stage_emitPushVar(param_2,uVar4 + param_3 * 0x3c);
    local_c = 0;
    if (0 < param_3) {
      local_8 = 0;
      do {
        local_58[0] = 0;
        memset(local_58 + 1,0,0x38);
        iVar5 = Ordinal_1432();
        if (iVar5 == 0) {
          props_formatValue(param_1,(byte *)"fileOffset + i *fileMethTabEntSize %d\n");
        }
        else {
          sVar1 = Ordinal_1412();
          local_58[0] = (int)sVar1;
          uVar2 = Ordinal_1412();
          if ((local_14 != 0) && (uVar2 < 0x13)) {
            uVar2 = *(short *)(&DAT_681956ae + (short)uVar2 * 2) - 1;
          }
          local_58[1] = (int)(short)uVar2;
          iVar5 = Ordinal_1414();
          local_58[2] = iVar5;
          local_58[3] = Ordinal_1414();
          if (((iVar5 < 0) || (local_18 < iVar5)) || (local_18 < local_58[3])) {
            local_58[2] = 0;
            local_58[3] = 0;
            local_58[1] = 0;
            local_58[0] = 0;
          }
          else {
            sVar1 = Ordinal_1412();
            local_58[4] = (int)sVar1;
            local_58[5] = Ordinal_1414();
            sVar3 = Ordinal_1412();
            local_40 = (int)sVar3;
            local_3c = Ordinal_1414();
            sVar3 = Ordinal_1412();
            local_38 = (int)sVar3;
            local_34 = Ordinal_1414();
            local_30 = Ordinal_1414();
            sVar3 = Ordinal_1412();
            local_2c = (int)sVar3;
            sVar3 = Ordinal_1412();
            local_28 = (int)sVar3;
            local_24 = Ordinal_1414();
            if (((sVar1 < 0) || (local_40 < 0)) ||
               ((local_38 < 0 || ((local_30 < 0 || (local_28 < 0)))))) {
              local_58[4] = 0;
              local_40 = 0;
              local_38 = 0;
              local_30 = 0;
              local_28 = 0;
            }
            else {
              if (0x800 < param_5) {
                local_20 = Ordinal_1414();
              }
              Ordinal_1432();
              local_58[3] = *(int *)(*param_2 + 0x10);
              globals_deserializeField(unaff_EBX);
              if ((param_5 < 0x801) &&
                 (iVar5 = globals_analyzeBytecode(local_58[3],param_2,local_58[3],local_58[2],&local_20,param_5
                                      ), iVar5 == 0)) {
                return 0xffffffff;
              }
              Ordinal_1432();
              local_58[5] = globals_serializeField(param_2,unaff_EBX);
              Ordinal_1432();
              local_3c = globals_serializeField(param_2,unaff_EBX);
              Ordinal_1432();
              local_34 = globals_serializeField(param_2,unaff_EBX);
              Ordinal_1432();
              local_24 = *(undefined4 *)(*param_2 + 0x10);
              globals_deserializeField(unaff_EBX);
            }
          }
        }
        iVar7 = *param_2 + local_8;
        local_8 = local_8 + 0x3c;
        local_c = local_c + 1;
        piVar6 = local_58;
        piVar8 = (int *)(iVar7 + local_10);
        for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar8 = piVar8 + 1;
        }
        uVar4 = local_10;
      } while (local_c < param_3);
    }
  }
  return uVar4;
}



// ============================================================
// Function: globals_readCastMember (FUN_68173540)
// Address: 68173540
// Size: 1237 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3, void * param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_readCastMember(int param_1,undefined4 param_2,undefined4 *param_3,void *param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *this;
  int local_8;

  this = (int *)0x0;
  local_8 = 0;
  *param_3 = 0;
  iVar2 = Ordinal_1404(&local_8,param_2,1);
  uVar6 = (uint)(iVar2 == 0);
  if ((iVar2 == 0) == 0) {
    iVar2 = Ordinal_1435(local_8);
    if (iVar2 < 0x4a) {
      uVar6 = 0xffffff82;
    }
    else {
      iVar2 = Ordinal_1116(param_2);
      this = (int *)stage_createBytecodeBlock(0x9c,0x98,iVar2);
      uVar6 = DAT_68195a8c;
      if (this != (int *)0x0) {
        iVar2 = Ordinal_1432(local_8,0x12,0);
        uVar6 = (uint)(iVar2 == 0);
        if (uVar6 == 0) {
          Ordinal_1114(this);
          iVar2 = *this;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x1c) = (int)sVar1;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x20) = (int)sVar1;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x24) = (int)sVar1;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x28) = (int)sVar1;
          uVar3 = Ordinal_1415(local_8);
          *(undefined4 *)(iVar2 + 0x2c) = uVar3;
          uVar3 = Ordinal_1415(local_8);
          *(undefined4 *)(iVar2 + 0x30) = uVar3;
          uVar3 = Ordinal_1415(local_8);
          *(undefined4 *)(iVar2 + 0x34) = uVar3;
          uVar6 = Ordinal_1414(local_8);
          *(uint *)(iVar2 + 0x54) = uVar6 & 0xffffffdf;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x58) = (int)sVar1;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x5c) = uVar3;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x60) = (int)sVar1;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 100) = (int)sVar1;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x68) = uVar3;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x6c) = uVar3;
          if ((int)param_4 < 0x500) {
            globals_packBitfield((uint *)(iVar2 + 0x6c));
          }
          uVar6 = Ordinal_1412(local_8);
          *(uint *)(iVar2 + 0x70) = uVar6 & 0xffff;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x74) = uVar3;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x78) = (int)sVar1;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x7c) = uVar3;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x80) = (int)sVar1;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x84) = uVar3;
          sVar1 = Ordinal_1412(local_8);
          *(int *)(iVar2 + 0x88) = (int)sVar1;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x8c) = uVar3;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x90) = uVar3;
          uVar3 = Ordinal_1414(local_8);
          *(undefined4 *)(iVar2 + 0x94) = uVar3;
          Ordinal_1115(this);
          if ((((-1 < *(int *)(iVar2 + 0x70)) && (-1 < *(int *)(iVar2 + 0x78))) &&
              (-1 < *(int *)(iVar2 + 0x80))) &&
             ((-1 < *(int *)(iVar2 + 0x88) && (-1 < *(int *)(iVar2 + 0x90))))) {
            iVar2 = Ordinal_1432(local_8,*(undefined4 *)(*this + 0x74),0);
            uVar6 = globals_serializeField(this,local_8);
            *(uint *)(*this + 0x74) = uVar6;
            iVar4 = Ordinal_1116(this);
            if (((uVar6 != 0xffffffff) && ((-1 < (int)uVar6 && ((int)uVar6 <= iVar4)))) &&
               (iVar2 != 0)) {
              iVar2 = Ordinal_1432(local_8,*(undefined4 *)(*this + 0x7c),0);
              uVar6 = globals_serializeField(this,local_8);
              *(uint *)(*this + 0x7c) = uVar6;
              iVar4 = Ordinal_1116(this);
              if ((((uVar6 != 0xffffffff) && (-1 < (int)uVar6)) && ((int)uVar6 <= iVar4)) &&
                 (iVar2 != 0)) {
                uVar3 = *(undefined4 *)(*this + 0x84);
                iVar2 = Ordinal_1432(local_8,uVar3,0);
                uVar6 = globals_readMethodTable(param_1,this,*(int *)(*this + 0x80),uVar3,(int)param_4);
                *(uint *)(*this + 0x84) = uVar6;
                iVar4 = Ordinal_1116(this);
                if (((uVar6 != 0xffffffff) && (-1 < (int)uVar6)) &&
                   (((int)uVar6 <= iVar4 && (iVar2 != 0)))) {
                  iVar2 = Ordinal_1432(local_8,*(undefined4 *)(*this + 0x8c),0);
                  uVar6 = globals_serializeFieldPairs(this,local_8,(int)param_4);
                  *(uint *)(*this + 0x8c) = uVar6;
                  iVar4 = Ordinal_1116(this);
                  if (((uVar6 != 0xffffffff) && (-1 < (int)uVar6)) &&
                     (((int)uVar6 <= iVar4 && (iVar2 != 0)))) {
                    iVar2 = *(int *)(*this + 0x94);
                    iVar4 = Ordinal_1432(local_8,iVar2,0);
                    iVar2 = globals_deserializeCastFields(this,local_8,param_1,iVar2,(int)param_4);
                    iVar5 = Ordinal_1116(this);
                    if ((((iVar2 != -1) && (-1 < iVar2)) && (iVar2 <= iVar5)) && (iVar4 != 0)) {
                      *(int *)(*this + 0x94) = iVar2;
                      iVar2 = events_getScoreProperty(param_1);
                      if (iVar2 < 0x1100) {
                        iVar2 = props_computeStringDelta(*this);
                        if (iVar2 < 0) {
                          iVar2 = 0;
                        }
                        stage_emitPushVar(this,*(int *)(*this + 0x10) + iVar2);
                        *(int *)(*this + 0x90) = *(int *)(*this + 0x90) + iVar2;
                      }
                      iVar2 = Ordinal_1432(local_8,*(undefined4 *)(*this + 0x68),0);
                      iVar4 = globals_deserializeIndexFields(this,local_8,(int)param_4);
                      iVar5 = Ordinal_1116(this);
                      if (((iVar4 != -1) && (-1 < iVar4)) && ((iVar4 <= iVar5 && (iVar2 != 0)))) {
                        *(int *)(*this + 0x68) = iVar4;
                        stage_getBytecodeSize(this);
                        uVar6 = 0;
                        if ((*(uint *)(*this + 0x54) & 0x4000) != 0) {
                          core_processExternalBindings(param_4,param_1,this,(int)param_4);
                        }
                        goto LAB_681739db;
                      }
                    }
                  }
                }
              }
            }
          }
          uVar6 = 0xffffff8b;
        }
      }
    }
  }
LAB_681739db:
  *param_3 = this;
  cast_freeHandle(param_2);
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  if (uVar6 == 0) {
    uVar6 = Ordinal_1042();
    return uVar6;
  }
  return uVar6;
}



// ============================================================
// Function: globals_writeCastDispatch (FUN_68173a20)
// Address: 68173a20
// Size: 472 bytes
// Params: int * param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_writeCastDispatch(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int local_c;
  int local_8;

  local_8 = 0;
  *param_2 = 0;
  iVar1 = Ordinal_1111(0,0);
  uVar3 = DAT_68195a8c;
  if ((DAT_68195a8c == 0) && (iVar1 != 0)) {
    iVar2 = Ordinal_1404(&local_8,iVar1,3);
    uVar3 = (uint)(iVar2 == 0);
    if (uVar3 == 0) {
      Ordinal_1114(param_1);
      iVar2 = *param_1;
      Ordinal_1426(local_8,0);
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 4));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x10));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x10));
      Ordinal_1423(local_8,0x60);
      Ordinal_1423(local_8,0xc);
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x20));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x24));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x28));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x2c));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x30));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x34));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x38));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x3c));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x40));
      puVar4 = (undefined2 *)(iVar2 + 0x44);
      local_c = 0x19;
      do {
        Ordinal_1423(local_8,*puVar4);
        puVar4 = puVar4 + 2;
        local_c = local_c + -1;
      } while (local_c != 0);
      puVar5 = (undefined4 *)(*param_1 + 0xa8);
      for (iVar2 = *(int *)(iVar2 + 0x10); 0 < iVar2; iVar2 = iVar2 + -1) {
        Ordinal_1426(local_8,*puVar5);
        Ordinal_1425(local_8,puVar5[1]);
        Ordinal_1423(local_8,*(undefined2 *)(puVar5 + 2));
        Ordinal_1423(local_8,*(undefined2 *)(puVar5 + 3));
        puVar5 = puVar5 + 4;
      }
      Ordinal_1115(param_1);
    }
  }
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  if (uVar3 == 0) {
    *param_2 = iVar1;
    return 0;
  }
  cast_freeHandle(iVar1);
  *param_2 = 0;
  return uVar3;
}



// ============================================================
// Function: globals_writeBytecodeBlock (FUN_68173c00)
// Address: 68173c00
// Size: 250 bytes
// Params: int * param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_writeBytecodeBlock(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_8;

  local_8 = 0;
  *param_2 = 0;
  iVar1 = Ordinal_1111(0,0);
  uVar3 = DAT_68195a8c;
  if ((DAT_68195a8c == 0) && (iVar1 != 0)) {
    iVar2 = Ordinal_1404(&local_8,iVar1,3);
    uVar3 = (uint)(iVar2 == 0);
    if (uVar3 == 0) {
      iVar2 = *(int *)(*param_1 + 0x10) - (int)*(short *)(*param_1 + 0x18);
      Ordinal_1426(local_8,0);
      Ordinal_1425(local_8,0);
      Ordinal_1425(local_8,iVar2);
      Ordinal_1425(local_8,iVar2);
      Ordinal_1423(local_8,0x14);
      Ordinal_1423(local_8,*(undefined2 *)(*param_1 + 0x1c));
      Ordinal_1114(param_1);
      Ordinal_1420(local_8,*param_1 + 0x20,iVar2);
      Ordinal_1115(param_1);
    }
  }
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  if (uVar3 != 0) {
    cast_freeHandle(iVar1);
    *param_2 = 0;
    return uVar3;
  }
  *param_2 = iVar1;
  return 0;
}



// ============================================================
// Function: globals_resetSerializer (FUN_68173d00)
// Address: 68173d00
// Size: 45 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_resetSerializer(void)
{
  Ordinal_1433();
  Ordinal_1432();
  Ordinal_1425();
  Ordinal_1432();
  return 0;
}



// ============================================================
// Function: globals_serializeCast (FUN_68173d30)
// Address: 68173d30
// Size: 57 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall globals_serializeCast(int param_1,undefined4 param_2,int param_3,int param_4)
{
  undefined2 *puVar1;

  globals_resetSerializer();
  puVar1 = (undefined2 *)(param_3 + param_4);
  for (; 0 < param_1; param_1 = param_1 + -1) {
    Ordinal_1423(param_2,*puVar1);
    puVar1 = puVar1 + 2;
  }
  return 0;
}



// ============================================================
// Function: globals_serializePropertyIndex (FUN_68173d70)
// Address: 68173d70
// Size: 54 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall globals_serializePropertyIndex(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined2 *puVar2;

  globals_resetSerializer();
  puVar2 = (undefined2 *)(*(int *)(param_1 + 0x68) + param_1);
  for (iVar1 = *(int *)(param_1 + 100); 0 < iVar1; iVar1 = iVar1 + -1) {
    Ordinal_1423(param_2,*puVar2);
    puVar2 = puVar2 + 2;
  }
  return 0;
}



// ============================================================
// Function: globals_getSerializerState (FUN_68173db0)
// Address: 68173db0
// Size: 53 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_getSerializerState(void)

{
  undefined4 uVar1;

  uVar1 = Ordinal_1433();
  globals_resetSerializer();
  Ordinal_1420();
  return uVar1;
}



// ============================================================
// Function: globals_writeMethodTable (FUN_68173df0)
// Address: 68173df0
// Size: 357 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_writeMethodTable(int param_1,int param_2,int param_3,int param_4)
{
  undefined4 in_EAX;
  int iVar1;

  Ordinal_1433();
  globals_resetSerializer();
  if (0 < param_3) {
    param_1 = param_3;
    do {
      Ordinal_1423();
      Ordinal_1423();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1423();
      Ordinal_1425();
      Ordinal_1423();
      Ordinal_1425();
      Ordinal_1423();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1423();
      Ordinal_1423();
      Ordinal_1425();
      Ordinal_1425();
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    if (0 < param_3) {
      iVar1 = param_2 + param_4 + 0xc;
      do {
        globals_getSerializerState();
        globals_serializeCast(*(int *)(iVar1 + 4),in_EAX,param_2,*(int *)(iVar1 + 8));
        globals_serializeCast(*(int *)(iVar1 + 0xc),in_EAX,param_2,*(int *)(iVar1 + 0x10));
        globals_serializeCast(*(int *)(iVar1 + 0x14),in_EAX,param_2,*(int *)(iVar1 + 0x18));
        globals_getSerializerState();
        iVar1 = iVar1 + 0x3c;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  return 0;
}



// ============================================================
// Function: globals_serializeFieldDescriptors (FUN_68173f60)
// Address: 68173f60
// Size: 118 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall globals_serializeFieldDescriptors(int param_1,undefined4 param_2)
{
  uint uVar1;
  int iVar2;
  uint *puVar3;

  globals_resetSerializer();
  puVar3 = (uint *)(*(int *)(param_1 + 0x8c) + param_1);
  for (iVar2 = *(int *)(param_1 + 0x88); 0 < iVar2; iVar2 = iVar2 + -1) {
    uVar1 = *puVar3;
    if ((uVar1 & 0x20) == 0) {
      if ((uVar1 & 0x40) == 0) {
        if (uVar1 == 0) {
          Ordinal_1425(param_2,0);
          uVar1 = 0;
        }
        else {
          Ordinal_1425(param_2,uVar1);
          uVar1 = puVar3[1];
        }
      }
      else {
        Ordinal_1425(param_2,1);
        uVar1 = (int)*puVar3 >> 8;
      }
    }
    else {
      Ordinal_1425(param_2,9);
      uVar1 = (int)*puVar3 >> 8;
    }
    Ordinal_1425(param_2,uVar1);
    puVar3 = puVar3 + 2;
  }
  return 0;
}



// ============================================================
// Function: globals_writeCastFields (FUN_68173fe0)
// Address: 68173fe0
// Size: 465 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall globals_writeCastFields(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  undefined8 local_10;
  uint local_8;

  local_1c = param_3;
  local_18 = param_2;
  local_24 = Ordinal_1433(param_1);
  globals_resetSerializer();
  iVar7 = *(int *)(param_2 + 0x88);
  local_20 = 0;
  local_2c = iVar7;
  if (0 < iVar7) {
    do {
      puVar2 = (uint *)(param_2 + local_20 * 8 + *(int *)(param_2 + 0x8c));
      uVar4 = *puVar2;
      uVar3 = puVar2[1];
      if ((uVar4 & 0x20) == 0) {
        if ((uVar4 & 0x40) != 0) {
          uVar6 = 1;
          goto LAB_68174058;
        }
      }
      else {
        uVar6 = 9;
LAB_68174058:
        uVar3 = (int)uVar4 >> 8;
        uVar4 = uVar6;
      }
      if ((uVar4 & 1) != 0) {
        iVar7 = *(int *)(param_2 + 0x94) + uVar3;
        local_14 = *(uint *)(local_18 + iVar7);
        local_28 = Ordinal_1433(param_1);
        if (uVar4 == 9) {
          globals_readSerializedData(&local_34,(undefined8 *)(local_18 + 4 + iVar7));
          uVar8 = globals_floatToExtended(local_34);
          local_10 = uVar8;
          Ordinal_1425(param_1);
          Ordinal_1420(param_1,&local_10,8);
        }
        else {
          Ordinal_1425(param_1);
          local_14 = local_14 + 1 & 0xfffffffe;
          if (uVar4 == 1) {
            uVar3 = events_getScoreProperty(local_1c);
            if (uVar3 < 0x1100) {
              events_writeChannelProperty(local_1c,local_18 + 4 + iVar7,local_14,0);
            }
          }
          iVar7 = local_18 + 4 + iVar7;
          Ordinal_1420(param_1,iVar7,local_14);
          iVar1 = local_1c;
          if (uVar4 == 1) {
            uVar4 = events_getScoreProperty(local_1c);
            if (uVar4 < 0x1100) {
              events_writeChannelProperty(iVar1,iVar7,local_14,1);
            }
          }
        }
        uVar5 = Ordinal_1433(param_1);
        Ordinal_1432(param_1,param_5 + 4 + local_20 * 8,0);
        Ordinal_1425(param_1,local_28 - local_24);
        Ordinal_1432(param_1,uVar5,0);
        iVar7 = local_2c;
        param_2 = local_18;
      }
      local_20 = local_20 + 1;
    } while (local_20 < iVar7);
  }
  iVar7 = Ordinal_1433(param_1);
  Ordinal_1432(param_1,param_4 + -4,0);
  Ordinal_1425(param_1,iVar7 - local_24);
  Ordinal_1432(param_1,iVar7,0);
  return 0;
}



// ============================================================
// Function: globals_writeCastMember (FUN_681741c0)
// Address: 681741c0
// Size: 784 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint globals_writeCastMember(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_8;

  local_8 = 0;
  *param_3 = 0;
  iVar1 = Ordinal_1111(0,0);
  uVar6 = DAT_68195a8c;
  if ((DAT_68195a8c == 0) && (iVar1 != 0)) {
    iVar2 = Ordinal_1404(&local_8,iVar1,3);
    uVar6 = (uint)(iVar2 == 0);
    if (uVar6 == 0) {
      Ordinal_1114(param_2);
      iVar2 = *param_2;
      Ordinal_1426(local_8,0);
      Ordinal_1425(local_8,0);
      Ordinal_1425(local_8,0);
      Ordinal_1425(local_8,0);
      Ordinal_1423(local_8,0x5c);
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x1c));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x20));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x24));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x28));
      Ordinal_1426(local_8,*(undefined4 *)(iVar2 + 0x2c));
      Ordinal_1426(local_8,*(undefined4 *)(iVar2 + 0x30));
      Ordinal_1426(local_8,*(undefined4 *)(iVar2 + 0x34));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x54));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x58));
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x5c));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x60));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 100));
      Ordinal_1433(local_8);
      Ordinal_1425(local_8,0xffffffff);
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x6c));
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x70));
      Ordinal_1433(local_8);
      Ordinal_1425(local_8,0xffffffff);
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x78));
      Ordinal_1433(local_8);
      Ordinal_1425(local_8,0xffffffff);
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x80));
      uVar3 = Ordinal_1433(local_8);
      Ordinal_1425(local_8,0xffffffff);
      Ordinal_1423(local_8,*(undefined2 *)(iVar2 + 0x88));
      Ordinal_1433(local_8);
      Ordinal_1425(local_8,0xffffffff);
      Ordinal_1425(local_8,*(undefined4 *)(iVar2 + 0x90));
      iVar4 = Ordinal_1433(local_8);
      Ordinal_1425(local_8,0xffffffff);
      globals_serializeCast(*(int *)(iVar2 + 0x70),local_8,iVar2,*(int *)(iVar2 + 0x74));
      globals_serializeCast(*(int *)(iVar2 + 0x78),local_8,iVar2,*(int *)(iVar2 + 0x7c));
      globals_writeMethodTable(uVar3,iVar2,*(int *)(iVar2 + 0x80),*(int *)(iVar2 + 0x84));
      iVar5 = Ordinal_1433(local_8);
      globals_serializeFieldDescriptors(iVar2,local_8);
      globals_writeCastFields(local_8,iVar2,param_1,iVar4,iVar5);
      globals_serializePropertyIndex(iVar2,local_8);
      uVar3 = Ordinal_1433(local_8);
      Ordinal_1432(local_8,8,0);
      Ordinal_1425(local_8,uVar3);
      Ordinal_1425(local_8,uVar3);
      Ordinal_1432(local_8,uVar3,0);
      Ordinal_1115(param_2);
    }
  }
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  if (uVar6 != 0) {
    cast_freeHandle(iVar1);
    *param_3 = 0;
    return uVar6;
  }
  *param_3 = iVar1;
  return 0;
}



// ============================================================
// Function: globals_getMciError (FUN_681744d0)
// Address: 681744d0
// Size: 55 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_getMciError(void)
{
  int in_EAX;
  int iVar1;
  BOOL BVar2;
  MCIERROR unaff_EBX;
  int unaff_EDI;

  Ordinal_1203();
  iVar1 = Ordinal_1201();
  BVar2 = mciGetErrorStringA(unaff_EBX,(LPSTR)(iVar1 + unaff_EDI),in_EAX - iVar1);
  if (BVar2 == 0) {
    Ordinal_1219();
  }
  return 0;
}



// ============================================================
// Function: globals_sendMciCommand (FUN_68174510)
// Address: 68174510
// Size: 232 bytes
// Params: undefined4 param_1, char * param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_sendMciCommand(undefined4 param_1,char *param_2,undefined1 *param_3)
{
  LPSTR lpstrReturnString;
  char cVar1;
  MCIERROR MVar2;
  int iVar3;
  char *pcVar4;
  int local_110;
  undefined1 *local_10c;
  CHAR local_108 [256];
  uint local_8;

  lpstrReturnString = param_3 + 1;
  local_10c = param_3;
  *lpstrReturnString = '\0';
  *param_3 = 0;
  do {
    cVar1 = *param_2;
    pcVar4 = param_2;
    while ((cVar1 != '\0' && (cVar1 != ';'))) {
      Ordinal_1252(pcVar4,&local_110);
      pcVar4 = pcVar4 + local_110;
      cVar1 = *pcVar4;
    }
    if ((uint)((int)pcVar4 - (int)param_2) < 0x100) {
      Ordinal_1203(local_108,param_2,((int)pcVar4 - (int)param_2) + 1);
      MVar2 = mciSendStringA(local_108,lpstrReturnString,0xff,(HWND)0x0);
      if ((MVar2 != 0) && (MVar2 != 0x10b)) goto LAB_681745a9;
    }
    else {
LAB_681745a9:
      globals_getMciError();
    }
    param_2 = pcVar4 + 1;
    if (*pcVar4 == '\0') {
      iVar3 = Ordinal_1201(lpstrReturnString);
      local_10c[iVar3 + 1] = 0;
      if (iVar3 < 0xff) {
        *local_10c = (char)iVar3;
        return 0;
      }
      *local_10c = 0xff;
      return 0;
    }
  } while( true );
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: operator_new
// Address: 68174602
// Size: 6 bytes
// THUNK -> operator_new
// Params: uint param_1
// Return: void *
// Calling convention: __cdecl
// ============================================================

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x68174602. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



// ============================================================
// Function: globals_reverseBytes10 (FUN_68174610)
// Address: 68174610
// Size: 64 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_reverseBytes10(void)
{
  undefined1 uVar1;
  undefined1 *in_EAX;

  uVar1 = *in_EAX;
  *in_EAX = in_EAX[9];
  in_EAX[9] = uVar1;
  uVar1 = in_EAX[1];
  in_EAX[1] = in_EAX[8];
  in_EAX[8] = uVar1;
  uVar1 = in_EAX[2];
  in_EAX[2] = in_EAX[7];
  in_EAX[7] = uVar1;
  uVar1 = in_EAX[3];
  in_EAX[3] = in_EAX[6];
  in_EAX[6] = uVar1;
  uVar1 = in_EAX[4];
  in_EAX[4] = in_EAX[5];
  in_EAX[5] = uVar1;
  return 0;
}



// ============================================================
// Function: globals_initSerializer (FUN_68174650)
// Address: 68174650
// Size: 51 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_initSerializer(void)
{
  undefined1 uVar1;
  undefined1 *in_EAX;

  uVar1 = *in_EAX;
  *in_EAX = in_EAX[7];
  in_EAX[7] = uVar1;
  uVar1 = in_EAX[1];
  in_EAX[1] = in_EAX[6];
  in_EAX[6] = uVar1;
  uVar1 = in_EAX[2];
  in_EAX[2] = in_EAX[5];
  in_EAX[5] = uVar1;
  uVar1 = in_EAX[3];
  in_EAX[3] = in_EAX[4];
  in_EAX[4] = uVar1;
  return 0;
}



// ============================================================
// Function: globals_floatFromExtended (FUN_68174690)
// Address: 68174690
// Size: 66 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined2 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_floatFromExtended(undefined4 param_1,undefined4 param_2,undefined2 param_3)
{
  uint uVar1;
  undefined4 uVar2;

  uVar2 = globals_reverseBytes10();
  Ordinal_1535(uVar2,param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: globals_floatFromDouble (FUN_681746e0)
// Address: 681746e0
// Size: 60 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_floatFromDouble(undefined4 param_1,undefined4 param_2)
{
  uint uVar1;
  undefined4 uVar2;

  uVar2 = globals_initSerializer();
  Ordinal_1537(uVar2,param_1,param_2);
  return 0;
}



// ============================================================
// Function: globals_floatToExtended (FUN_68174720)
// Address: 68174720
// Size: 64 bytes
// Params: undefined8 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_floatToExtended(undefined8 param_1)
{
  undefined1 local_10 [8];
  uint local_8;

  Ordinal_1538(param_1,local_10);
  globals_initSerializer();
  return 0;
}



// ============================================================
// Function: globals_readSerializedData (FUN_68174760)
// Address: 68174760
// Size: 17 bytes
// Params: undefined8 * param_1, undefined8 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_readSerializedData(undefined8 *param_1,undefined8 *param_2)
{
  *param_1 = *param_2;
  return 0;
}


