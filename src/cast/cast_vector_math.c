// Module: cast
// Topic: Vector math, 3D operations, and comparisons
// Address range: 0x68026150 - 0x68027400
// Functions (30):
//   cast_execBridgeAndSet
//   cast_dotProduct
//   cast_computeSqrt
//   cast_normalizeVector
//   cast_computeDotProduct
//   cast_computeSqrtFloat
//   cast_crossProduct
//   cast_copyFloats
//   cast_compareFloats
//   cast_randomSpherePoint
//   cast_getVectorComponent
//   cast_setVectorComponent
//   cast_formatVector
//   cast_accessVectorProperty
//   cast_getVectorRef
//   cast_getVectorData
//   cast_extractVectorData
//   cast_storeVectorValue
//   cast_getVectorPointer
//   cast_releaseVector
//   cast_resolveMediaVector
//   cast_destroyMediaVector
//   cast_setMediaVectorProp
//   cast_registerVectorMedia
//   cast_computeAngle
//   cast_setVectorProperty
//   cast_getVectorProperty
//   cast_dispatchVectorOp
//   cast_binaryVectorOp
//   cast_scalarVectorOp

// ============================================================
// Function: cast_execBridgeAndSet (FUN_68026150)
// Address: 68026150
// Size: 94 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, int param_4, int * param_5, int param_6, int * param_7, short * param_8
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
cast_execBridgeAndSet(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,int param_6
            ,int *param_7,short *param_8)

{
  short *psVar1;
  short sVar2;
  undefined4 uVar3;
  
  sVar2 = cast_bridgeXtraCall(param_1,param_2,param_3,&param_4);
  psVar1 = param_8;
  *param_8 = sVar2;
  if (*(int *)(param_3 + 0x7c) != 0) {
    return 0;
  }
  props_releaseValue(param_3,(byte)param_4,param_5);
  uVar3 = crt_executePlatformSet(param_3,&param_6,sprites_findMemberByScript,psVar1,0x23);
  props_releaseValue(param_3,(byte)param_6,param_7);
  return uVar3;
}



// ============================================================
// Function: cast_dotProduct (FUN_680261b0)
// Address: 680261b0
// Size: 169 bytes
// Params: float * param_1, float * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_dotProduct(float *param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = *param_2 - *param_1;
  if ((((fVar1 - 0.0 < 0.0001) && (0.0 - fVar1 < 0.0001)) &&
      (fVar1 = param_2[1] - param_1[1], fVar1 - 0.0 < 0.0001)) && (0.0 - fVar1 < 0.0001)) {
    fVar1 = param_2[2] - param_1[2];
  }
  if ((fVar1 - 0.0 < 0.0001) && (0.0 - fVar1 < 0.0001)) {
    return 0;
  }
  if (0.0 <= fVar1) {
    return 1;
  }
  return 0xffffffff;
}



// ============================================================
// Function: cast_computeSqrt (FUN_68026260)
// Address: 68026260
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_computeSqrt(void)
{
  _CIsqrt();
  return 0;
}



// ============================================================
// Function: cast_normalizeVector (FUN_68026280)
// Address: 68026280
// Size: 70 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_normalizeVector(void)
{
  float *unaff_ESI;
  float10 fVar1;
  
  fVar1 = (float10)_CIsqrt();
  if ((float10)0 != fVar1) {
    fVar1 = (float10)1 / fVar1;
    *unaff_ESI = (float)((float10)*unaff_ESI * fVar1);
    unaff_ESI[1] = (float)((float10)unaff_ESI[1] * fVar1);
    unaff_ESI[2] = (float)(size_t)(fVar1 * (float10)unaff_ESI[2]);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: cast_computeDotProduct (FUN_680262d0)
// Address: 680262d0
// Size: 39 bytes
// Params: float * param_1, float * param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 cast_computeDotProduct(float *param_1,float *param_2)

{
  return (float10)(param_1[2] * param_2[2] + *param_1 * *param_2 + param_1[1] * param_2[1]);
}



// ============================================================
// Function: cast_computeSqrtFloat (FUN_68026300)
// Address: 68026300
// Size: 51 bytes
// Params: undefined4 param_1
// Return: float10
// Calling convention: __fastcall
// ============================================================

float10 __fastcall cast_computeSqrtFloat(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)_CIsqrt(param_1);
  return (float10)(float)fVar1;
}



// ============================================================
// Function: cast_crossProduct (FUN_68026340)
// Address: 68026340
// Size: 152 bytes
// Params: float * param_1, float * param_2, float * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_crossProduct(float *param_1,float *param_2,float *param_3)
{
  float *pfVar1;
  float local_14 [3];
  uint local_8;
  
  if ((param_3 == param_1) || (pfVar1 = param_3, param_3 == param_2)) {
    pfVar1 = local_14;
  }
  *pfVar1 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  pfVar1[1] = param_1[2] * *param_2 - param_2[2] * *param_1;
  pfVar1[2] = param_2[1] * *param_1 - param_1[1] * *param_2;
  pfVar1[3] = 1.0;
  if (pfVar1 == local_14) {
    *param_3 = *pfVar1;
    param_3[1] = pfVar1[1];
    param_3[2] = pfVar1[2];
    param_3[3] = 1.0;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: cast_copyFloats (FUN_680263e0)
// Address: 680263e0
// Size: 71 bytes
// Params: undefined4 * param_1, int param_2, float param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_copyFloats(undefined4 *param_1,int param_2,float param_3)
{
  undefined4 *puVar1;
  
  if (param_3 <= 0.0) {
    return 0;
  }
  puVar1 = param_1;
  do {
    *puVar1 = *(undefined4 *)((param_2 - (int)param_1) + (int)puVar1);
    param_3 = param_3 - 1.0;
    puVar1 = puVar1 + 1;
  } while (0.0 < param_3);
  return 0;
}



// ============================================================
// Function: cast_compareFloats (FUN_68026430)
// Address: 68026430
// Size: 306 bytes
// Params: float * param_1, int param_2
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall cast_compareFloats(float *param_1,int param_2)

{
  bool bVar1;
  float fVar2;
  float *in_EAX;
  int iVar3;
  
  bVar1 = true;
  while( true ) {
    if (param_2 < 4) {
      if (0 < param_2) {
        iVar3 = (int)in_EAX - (int)param_1;
        do {
          if (!bVar1) {
            return bVar1;
          }
          fVar2 = *(float *)(iVar3 + (int)param_1) - *param_1;
          if (fVar2 < 0.0) {
            fVar2 = -fVar2;
          }
          bVar1 = fVar2 < 0.0001;
          param_2 = param_2 + -1;
          param_1 = param_1 + 1;
        } while (0 < param_2);
      }
      return bVar1;
    }
    if (!bVar1) {
      return bVar1;
    }
    fVar2 = *in_EAX - *param_1;
    if (fVar2 < 0.0) {
      fVar2 = -fVar2;
    }
    if (0.0001 <= fVar2) {
      return false;
    }
    fVar2 = in_EAX[1] - param_1[1];
    if (fVar2 < 0.0) {
      fVar2 = -fVar2;
    }
    if (0.0001 <= fVar2) {
      return false;
    }
    fVar2 = in_EAX[2] - param_1[2];
    if (fVar2 < 0.0) {
      fVar2 = -fVar2;
    }
    if (0.0001 <= fVar2) break;
    fVar2 = in_EAX[3] - param_1[3];
    if (fVar2 < 0.0) {
      fVar2 = -fVar2;
    }
    bVar1 = fVar2 < 0.0001;
    param_2 = param_2 + -4;
    in_EAX = in_EAX + 4;
    param_1 = param_1 + 4;
  }
  return false;
}



// ============================================================
// Function: cast_randomSpherePoint (FUN_68026570)
// Address: 68026570
// Size: 229 bytes
// Params: float param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_randomSpherePoint(float param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  float *unaff_ESI;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar1 = *(float *)(in_EAX + 8);
  fVar4 = (float10)_CIsqrt();
  fVar5 = (float10)_CIsin();
  fVar2 = (float)fVar5 * (float)fVar4;
  fVar5 = (float10)_CIcos();
  fVar3 = (float)fVar5 * (float)fVar4;
  fVar4 = (float10)_CIsqrt();
  fVar5 = (float10)_CIsin();
  fVar6 = (float10)_CIcos();
  *unaff_ESI = param_1 * (float)fVar4 * (fVar2 * (float)fVar6 - fVar3 * (float)fVar5);
  unaff_ESI[1] = param_1 * ((float)fVar6 * fVar3 + (float)fVar5 * fVar2) * (float)fVar4;
  unaff_ESI[2] = (1.0 - (fVar1 + fVar1)) * param_1;
  unaff_ESI[3] = 1.0;
  return 0;
}



// ============================================================
// Function: cast_getVectorComponent (FUN_68026660)
// Address: 68026660
// Size: 135 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getVectorComponent(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  uint local_8;
  
  piVar1 = (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                  *(int *)(unaff_ESI + 0x18));
  iVar2 = props_getInt(unaff_ESI);
  if ((iVar2 == 2) && (*piVar1 == 4)) {
    local_8 = piVar1[1];
  }
  else {
    iVar2 = props_getTypedValue(unaff_ESI,2,4,&local_8);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (2 < local_8 - 1) {
    props_setError(unaff_ESI,0x3c);
    return 0;
  }
  props_storeNumber(unaff_ESI,(double)*(float *)(*param_1 + 4 + local_8 * 4),param_2);
  return 1;
}



// ============================================================
// Function: cast_setVectorComponent (FUN_680266f0)
// Address: 680266f0
// Size: 164 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_setVectorComponent(int *param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  uint local_14;
  int *local_10;
  uint local_8;
  
  piVar1 = (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                  *(int *)(unaff_ESI + 0x18));
  iVar2 = props_getInt(unaff_ESI);
  if ((iVar2 == 2) && (*piVar1 == 4)) {
    local_8 = piVar1[1];
  }
  else {
    iVar2 = props_getTypedValue(unaff_ESI,2,4,&local_8);
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar2 = props_getValueDirect(unaff_ESI,3,9,&local_14);
  if (iVar2 != 0) {
    if (local_8 - 1 < 3) {
      if (local_14 != 0x20) {
        local_10 = (int *)(size_t)(float)*(double *)(*local_10 + 8);
      }
      *(int **)(*param_1 + 4 + local_8 * 4) = local_10;
      return 1;
    }
    props_setError(unaff_ESI,0x3c);
  }
  return 0;
}



// ============================================================
// Function: cast_formatVector (FUN_680267a0)
// Address: 680267a0
// Size: 177 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatVector(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  cast_loadPascalString(&DAT_68197780,0x898,0x43);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  iVar2 = 0;
  do {
    props_formatFloat(param_1,*(float *)(iVar1 + 8 + iVar2 * 4),&DAT_68197780);
    props_formatString(param_1,param_3,param_4,&DAT_68197781);
    if (iVar2 != 2) {
      props_formatString(param_1,param_3,param_4,&DAT_6817c130);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  cast_loadPascalString(&DAT_68197780,0x898,0x46);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: cast_accessVectorProperty (FUN_68026860)
// Address: 68026860
// Size: 232 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_accessVectorProperty(int param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  float10 fVar5;
  double local_c;
  
  iVar1 = *param_2;
  iVar2 = 0;
  if (param_3 == 0) {
    if (param_4 < 0x3d5) {
      if (0x3d1 < param_4) {
        props_storeNumber(param_1,(double)*(float *)(iVar1 + -0xf40 + param_4 * 4),param_5);
        return 1;
      }
      bVar4 = param_4 == 0x8a;
    }
    else {
      bVar4 = param_4 == 0x53d;
    }
    if (!bVar4) {
      return 0;
    }
    fVar5 = (float10)_CIsqrt();
    props_storeNumber(param_1,(double)fVar5,param_5);
    iVar2 = 1;
  }
  else if ((0x3d1 < param_4) && (param_4 < 0x3d5)) {
    iVar3 = props_requireFloat(param_1,param_5,&local_c);
    iVar2 = 0;
    if (iVar3 != 0) {
      *(float *)(iVar1 + -0xf40 + param_4 * 4) = (float)(size_t)local_c;
      return iVar3;
    }
  }
  return iVar2;
}



// ============================================================
// Function: cast_getVectorRef (FUN_68026960)
// Address: 68026960
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getVectorRef(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818ba38)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_getVectorData (FUN_68026990)
// Address: 68026990
// Size: 103 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getVectorData(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0x18,1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_LAB_6818ba38;
  puVar1[1] = 1;
  if (param_2 != (undefined4 *)0x0) {
    puVar1[2] = *param_2;
    puVar1[3] = param_2[1];
    puVar1[4] = param_2[2];
    puVar1[5] = param_2[3];
    return 0;
  }
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0x3f800000;
  return 0;
}



// ============================================================
// Function: cast_extractVectorData (FUN_68026a00)
// Address: 68026a00
// Size: 80 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_extractVectorData(undefined4 param_1,int *param_2,int *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818ba38)) {
    *param_3 = (*(int **)param_2[1])[2];
    param_3[1] = *(int *)(*(int *)param_2[1] + 0xc);
    param_3[2] = *(int *)(*(int *)param_2[1] + 0x10);
    param_3[3] = *(int *)(*(int *)param_2[1] + 0x14);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_storeVectorValue (FUN_68026a50)
// Address: 68026a50
// Size: 34 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_storeVectorValue(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  
  *param_3 = 3;
  uVar1 = cast_getVectorData(param_1,param_2);
  param_3[1] = uVar1;
  return 0;
}



// ============================================================
// Function: cast_getVectorPointer (FUN_68026a80)
// Address: 68026a80
// Size: 53 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getVectorPointer(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818ba38)) {
    iVar1 = Ordinal_1114((undefined4 *)param_2[1]);
    *param_3 = iVar1 + 8;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_releaseVector (FUN_68026ac0)
// Address: 68026ac0
// Size: 54 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_releaseVector(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818ba38)) {
    Ordinal_1115((undefined4 *)param_2[1]);
    *param_3 = 0;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_resolveMediaVector (FUN_68026b00)
// Address: 68026b00
// Size: 69 bytes
// Params: int * param_1, undefined4 param_2
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_resolveMediaVector(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_EDI;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  *unaff_EDI = 0;
  iVar1 = score_getMediaProperty(param_2,param_1,(int *)&local_8);
  if ((iVar1 != 0) && (iVar2 = (**(code **)*local_8)(local_8,&DAT_681765e8), iVar2 != 0)) {
    return 0;
  }
  return iVar1;
}



// ============================================================
// Function: cast_destroyMediaVector (FUN_68026b50)
// Address: 68026b50
// Size: 54 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_destroyMediaVector(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = cast_resolveMediaVector(param_2,param_1);
  if (iVar1 != 0) {
    (**(code **)(iRam00000000 + 8))(0);
  }
  return iVar1;
}



// ============================================================
// Function: cast_setMediaVectorProp (FUN_68026b90)
// Address: 68026b90
// Size: 69 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_setMediaVectorProp(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = cast_resolveMediaVector(param_2,param_1);
  if (iVar1 != 0) {
    (**(code **)(iRam00000000 + 0x1c))(0,param_3);
    (**(code **)(iRam00000000 + 8))(0);
  }
  return iVar1;
}



// ============================================================
// Function: cast_registerVectorMedia (FUN_68026be0)
// Address: 68026be0
// Size: 145 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerVectorMedia(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  int *piVar2;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2075(uVar1);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,&DAT_681765d8,&DAT_681765e8,&local_8);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 0xc))(local_8,param_2);
      (**(code **)*local_8)(local_8,&DAT_68176308,&local_c);
      if (local_c != 0) {
        score_setMediaProperty(param_1,local_c,param_3);
      }
      (**(code **)(*local_8 + 8))(local_8);
    }
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return 0;
}



// ============================================================
// Function: cast_computeAngle (FUN_68026c80)
// Address: 68026c80
// Size: 306 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_computeAngle(undefined4 param_1,int param_2,int param_3)
{
  float fVar1;
  float10 fVar2;
  float local_28;
  float local_24;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  uint local_8;
  
  cast_copyFloats(&local_28,param_2,4.0);
  cast_copyFloats(&local_18,param_3,4.0);
  fVar2 = (float10)_CIsqrt();
  if ((float10)0 != fVar2) {
    fVar2 = (float10)1 / fVar2;
    local_28 = (float)((float10)local_28 * fVar2);
    local_24 = (float)((float10)local_24 * fVar2);
    local_20 = (float)(size_t)(fVar2 * (float10)local_20);
  }
  fVar2 = (float10)_CIsqrt();
  if ((float10)0 != fVar2) {
    fVar2 = (float10)1 / fVar2;
    local_18 = (float)((float10)local_18 * fVar2);
    local_14 = (float)((float10)local_14 * fVar2);
    local_10 = (float)(size_t)(fVar2 * (float10)local_10);
  }
  fVar1 = local_10 * local_20 + local_14 * local_24 + local_18 * local_28;
  if ((fVar1 < 1.0) && (-1.0 < fVar1)) {
    _CIacos();
  }
  return 0;
}



// ============================================================
// Function: cast_setVectorProperty (FUN_68026dc0)
// Address: 68026dc0
// Size: 91 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_setVectorProperty(int *param_1)

{
  int iVar1;
  int unaff_ESI;
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 == 3) {
    iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_8);
    if (iVar1 != 0) {
      iVar1 = cast_accessVectorProperty(unaff_ESI,param_1,1,local_8,
                           (int *)(**(int **)(unaff_ESI + 0x10) +
                                   (2 - *(int *)(unaff_ESI + 0x20)) * 8 + *(int *)(unaff_ESI + 0x18)
                                  ));
      return iVar1;
    }
  }
  else {
    props_setError(unaff_ESI,0x17);
  }
  return 0;
}



// ============================================================
// Function: cast_getVectorProperty (FUN_68026e20)
// Address: 68026e20
// Size: 75 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_getVectorProperty(int *param_1,int *param_2)

{
  int iVar1;
  int unaff_ESI;
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 == 2) {
    iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_8);
    if (iVar1 != 0) {
      iVar1 = cast_accessVectorProperty(unaff_ESI,param_1,0,local_8,param_2);
      return iVar1;
    }
  }
  else {
    props_setError(unaff_ESI,0x16);
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchVectorOp (FUN_68026e70)
// Address: 68026e70
// Size: 769 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchVectorOp(uint param_1,int *param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  float10 fVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  float local_18 [3];
  undefined4 local_c;
  uint local_8;
  
  local_20 = 4;
  local_1c = 0;
  if (param_3 < 0xe4) {
    if (param_3 == 0xe3) {
      score_resolveType(param_1);
      return 0;
    }
    switch(param_3) {
    case 0x8a:
      iVar2 = props_getInt(param_1);
      if (iVar2 != 1) goto switchD_68026eba_caseD_8b;
      piVar4 = &local_20;
      fVar3 = (float10)cast_computeSqrt();
      goto LAB_68026f2d;
    default:
      goto switchD_68026eba_caseD_8b;
    case 0xd3:
      uVar1 = cast_getVectorComponent(param_2,&local_20);
      break;
    case 0xd4:
      uVar1 = cast_getVectorProperty(param_2,&local_20);
      break;
    case 0xda:
      uVar1 = cast_setVectorComponent(param_2);
      break;
    case 0xdb:
      uVar1 = cast_setVectorProperty(param_2);
    }
LAB_68026ecf:
    if (uVar1 == 0) goto switchD_68026eba_caseD_8b;
    goto LAB_68026ed3;
  }
  if (param_3 < 0x3c9) {
    if (param_3 != 0x3c8) {
      if (param_3 != 0xe4) goto switchD_68026eba_caseD_8b;
      local_20 = 3;
      local_1c = cast_getVectorData(param_1,(undefined4 *)(*param_2 + 8));
      uVar1 = (uint)(local_1c != 0);
      goto LAB_68026ecf;
    }
    iVar2 = props_getInt(param_1);
    if ((iVar2 != 2) ||
       (iVar2 = cast_getVectorRef(param_1,(int *)(**(int **)(param_1 + 0x10) +
                                             *(int *)(param_1 + 0x20) * -8 +
                                             *(int *)(param_1 + 0x18) + 8)), iVar2 == 0))
    goto switchD_68026eba_caseD_8b;
    piVar4 = &local_20;
    fVar3 = (float10)cast_computeAngle(*(int **)(extraout_EDX + 0xc),*param_2 + 8,
                                  **(int **)(extraout_EDX + 0xc) + 8);
    goto LAB_68026f2d;
  }
  switch(param_3) {
  case 0x3c9:
  case 0x3ca:
    iVar2 = props_getInt(param_1);
    if ((iVar2 != 2) ||
       (iVar2 = cast_getVectorRef(param_1,(int *)(*(int *)(param_1 + 0x18) +
                                             **(int **)(param_1 + 0x10) +
                                             *(int *)(param_1 + 0x20) * -8 + 8)), iVar2 == 0))
    goto switchD_68026eba_caseD_8b;
    piVar4 = &local_20;
    fVar3 = cast_computeDotProduct((float *)(*param_2 + 8),(float *)(**(int **)(extraout_EDX_01 + 0xc) + 8));
    goto LAB_68026f2d;
  case 0x3cb:
  case 0x3cc:
  case 0x3cd:
    iVar2 = props_getInt(param_1);
    if ((iVar2 != 2) ||
       (iVar2 = cast_getVectorRef(param_1,(int *)(**(int **)(param_1 + 0x10) +
                                             *(int *)(param_1 + 0x20) * -8 +
                                             *(int *)(param_1 + 0x18) + 8)), iVar2 == 0))
    goto switchD_68026eba_caseD_8b;
    cast_crossProduct((float *)(*param_2 + 8),(float *)(**(int **)(extraout_EDX_00 + 0xc) + 8),local_18);
    local_c = 0;
    local_20 = 3;
    local_1c = cast_getVectorData(param_1,local_18);
    break;
  case 0x3ce:
    cast_normalizeVector();
    break;
  case 0x3cf:
    iVar2 = props_getInt(param_1);
    if (iVar2 != 1) goto switchD_68026eba_caseD_8b;
    cast_copyFloats(local_18,*param_2 + 8,4.0);
    cast_normalizeVector();
    local_20 = 3;
    local_1c = cast_getVectorData(param_1,local_18);
    break;
  case 0x3d0:
    iVar2 = props_getInt(param_1);
    if ((iVar2 != 2) ||
       (iVar2 = cast_getVectorRef(param_1,(int *)(*(int *)(param_1 + 0x18) +
                                             **(int **)(param_1 + 0x10) +
                                             *(int *)(param_1 + 0x20) * -8 + 8)), iVar2 == 0))
    goto switchD_68026eba_caseD_8b;
    piVar4 = &local_20;
    fVar3 = cast_computeSqrtFloat(*param_2 + 8);
LAB_68026f2d:
    props_storeNumber(param_1,(double)fVar3,piVar4);
    break;
  default:
    goto switchD_68026eba_caseD_8b;
  }
LAB_68026ed3:
  props_popArgs(param_1,&local_20);
switchD_68026eba_caseD_8b:
  return 0;
}



// ============================================================
// Function: cast_binaryVectorOp (FUN_68027200)
// Address: 68027200
// Size: 425 bytes
// Params: float * param_1, float * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_binaryVectorOp(float *param_1,float *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  switch(param_3) {
  case 4:
    props_storeNumber(unaff_EDI,
                 (double)(param_2[2] * param_1[2] + *param_2 * *param_1 + param_2[1] * param_1[1]),
                 unaff_ESI);
    return 1;
  case 5:
    local_14 = *param_2 + *param_1;
    local_10 = param_2[1] + param_1[1];
    local_c = param_2[2] + param_1[2];
    *unaff_ESI = 3;
    local_8 = 0x3f800000;
    uVar3 = cast_getVectorData(unaff_EDI,&local_14);
    unaff_ESI[1] = uVar3;
    return 1;
  case 6:
    local_14 = *param_2 - *param_1;
    local_10 = param_2[1] - param_1[1];
    local_c = param_2[2] - param_1[2];
    *unaff_ESI = 3;
    local_8 = 0x3f800000;
    uVar3 = cast_getVectorData(unaff_EDI,&local_14);
    unaff_ESI[1] = uVar3;
    return 1;
  default:
    return 0;
  case 0xc:
    *unaff_ESI = 4;
    iVar2 = cast_dotProduct(param_1,param_2);
    unaff_ESI[1] = (uint)(iVar2 == -1);
    return 1;
  case 0xd:
    *unaff_ESI = 4;
    iVar2 = cast_dotProduct(param_1,param_2);
    unaff_ESI[1] = (uint)(iVar2 != 1);
    return 1;
  case 0xe:
    *unaff_ESI = 4;
    bVar1 = cast_compareFloats(param_1,3);
    unaff_ESI[1] = (uint)(CONCAT31(extraout_var_00,bVar1) == 0);
    return 1;
  case 0xf:
    *unaff_ESI = 4;
    bVar1 = cast_compareFloats(param_1,3);
    unaff_ESI[1] = CONCAT31(extraout_var,bVar1);
    return 1;
  case 0x10:
    *unaff_ESI = 4;
    iVar2 = cast_dotProduct(param_1,param_2);
    unaff_ESI[1] = (uint)(iVar2 == 1);
    return 1;
  case 0x11:
    *unaff_ESI = 4;
    iVar2 = cast_dotProduct(param_1,param_2);
    unaff_ESI[1] = (uint)(iVar2 != -1);
    return 1;
  case 0x24:
  case 0x25:
    *unaff_ESI = 4;
    uVar3 = cast_dotProduct(param_1,param_2);
    unaff_ESI[1] = uVar3;
    return 1;
  }
}



// ============================================================
// Function: cast_scalarVectorOp (FUN_68027400)
// Address: 68027400
// Size: 234 bytes
// Params: float * param_1, int param_2, undefined4 param_3, float param_4
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_scalarVectorOp(float *param_1,int param_2,undefined4 param_3,float param_4)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_8 = param_1[3];
  switch(param_3) {
  case 4:
    local_14 = param_4 * *param_1;
    local_10 = param_1[1] * param_4;
    local_c = param_4 * param_1[2];
    break;
  case 5:
    local_14 = param_4 + *param_1;
    local_10 = param_1[1] + param_4;
    local_c = param_4 + param_1[2];
    break;
  case 6:
    if (param_2 == 0) {
      local_14 = *param_1 - param_4;
      local_10 = param_1[1] - param_4;
      local_c = param_1[2] - param_4;
    }
    else {
      local_14 = param_4 - *param_1;
      local_10 = param_4 - param_1[1];
      local_c = param_4 - param_1[2];
    }
    break;
  case 7:
    if ((param_2 != 0) || (param_4 == 0.0)) {
      props_setError(unaff_EDI,6);
      return 0;
    }
    local_14 = *param_1 / param_4;
    local_10 = param_1[1] / param_4;
    local_c = param_1[2] / param_4;
    break;
  default:
    return 0;
  }
  *unaff_ESI = 3;
  uVar1 = cast_getVectorData(unaff_EDI,&local_14);
  unaff_ESI[1] = uVar1;
  return 1;
}



