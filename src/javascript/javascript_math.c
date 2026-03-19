// Module: javascript
// Topic: Math object - trigonometric, logarithmic, rounding, random functions
// Address range: 0x68131500 - 0x68132000
// Functions (26):

//   javascript_mathAcos
//   javascript_mathAsin
//   javascript_mathAtan
//   javascript_mathAtan2
//   javascript_mathCeil
//   javascript_mathCos
//   javascript_mathExp
//   javascript_mathFloor
//   javascript_mathLog
//   javascript_mathMax
//   javascript_mathMin
//   javascript_mathPow
//   javascript_seedRandom
//   javascript_initRandom
//   javascript_nextRandomBits
//   javascript_generateRandom
//   javascript_mathRandom
//   javascript_mathRound
//   javascript_mathSin
//   javascript_mathSqrt
//   javascript_mathTan
//   javascript_mathToSource
//   javascript_initMathObject
//   javascript_mathFmod
//   js_mathBuiltin
//   js_mathToUint32

// ============================================================
// Function: javascript_mathAcos (FUN_68131500)
// Address: 68131500
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathAcos(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIacos();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathAsin (FUN_68131550)
// Address: 68131550
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathAsin(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIasin();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathAtan (FUN_681315a0)
// Address: 681315a0
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathAtan(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIatan();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathAtan2 (FUN_681315f0)
// Address: 681315f0
// Size: 104 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_mathAtan2(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  float10 fVar3;
  double local_14;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_14);
  if (iVar1 != 0) {
    iVar1 = runtime_parseNumber(param_1,param_4[1],&local_c);
    if (iVar1 != 0) {
      fVar3 = (float10)crypto_computeAtan2(local_14,local_c);
      uVar2 = runtime_convertToNumber(param_5,extraout_EDX,(int)param_1,SUB84((double)fVar3,0),
                           (uint)((ulonglong)(double)fVar3 >> 0x20),(uint *)param_5);
      return uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_mathCeil (FUN_68131660)
// Address: 68131660
// Size: 78 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathCeil(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  double dVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  dVar2 = ceil(local_c);
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84(dVar2,0),
               (uint)((ulonglong)dVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathCos (FUN_681316b0)
// Address: 681316b0
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathCos(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIcos();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathExp (FUN_68131700)
// Address: 68131700
// Size: 186 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_mathExp(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  double *pdVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  float10 fVar4;
  int local_c;
  uint uStack_8;
  
  iVar2 = runtime_parseNumber(param_1,*param_4,(double *)&local_c);
  if (iVar2 == 0) {
    return 0;
  }
  if (((uStack_8 & 0x7ff00000) != 0x7ff00000) || ((local_c == 0 && ((uStack_8 & 0xfffff) == 0)))) {
    pdVar1 = *(double **)(*(int *)(param_1 + 10) + 0x1d8);
    if (*pdVar1 == (double)CONCAT44(uStack_8,local_c)) {
      *param_5 = (uint)pdVar1 | 2;
      return 1;
    }
    if (**(double **)(*(int *)(param_1 + 10) + 0x1d4) == (double)CONCAT44(uStack_8,local_c)) {
      *param_5 = 1;
      return 1;
    }
  }
  fVar4 = (float10)_CIexp();
  uVar3 = runtime_convertToNumber(extraout_ECX,param_5,(int)param_1,SUB84((double)fVar4,0),
                       (uint)((ulonglong)(double)fVar4 >> 0x20),param_5);
  return uVar3;
}



// ============================================================
// Function: javascript_mathFloor (FUN_681317c0)
// Address: 681317c0
// Size: 77 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathFloor(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  double dVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  dVar2 = floor(local_c);
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84(dVar2,0),
               (uint)((ulonglong)dVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathLog (FUN_68131810)
// Address: 68131810
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathLog(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIlog();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathMax (FUN_68131860)
// Address: 68131860
// Size: 304 bytes
// Params: undefined4 param_1, uint param_2, ushort * param_3, undefined4 param_4, uint param_5, int param_6, uint * param_7
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
javascript_mathMax(undefined4 param_1,uint param_2,ushort *param_3,undefined4 param_4,uint param_5,
            int param_6,uint *param_7)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  uint uVar5;
  float10 fVar6;
  double local_14;
  int local_c;
  uint uStack_8;
  
  local_14 = **(double **)(*(int *)(param_3 + 10) + 0x1d4);
  if (param_5 == 0) {
    *param_7 = (uint)*(double **)(*(int *)(param_3 + 10) + 0x1d4) | 2;
    return 1;
  }
  uVar5 = 0;
  if (param_5 != 0) {
    do {
      iVar3 = runtime_parseNumber(param_3,*(uint *)(param_6 + uVar5 * 4),(double *)&local_c);
      if (iVar3 == 0) {
        return 0;
      }
      param_2 = uStack_8 & 0x7ff00000;
      if ((param_2 == 0x7ff00000) && ((local_c != 0 || ((uStack_8 & 0xfffff) != 0)))) {
        *param_7 = *(uint *)(*(int *)(param_3 + 10) + 0x1d0) | 2;
        return 1;
      }
      dVar1 = (double)CONCAT44(uStack_8,local_c);
      param_1 = extraout_ECX;
      if ((dVar1 == 0.0) && (local_14 == dVar1)) {
        fVar6 = crypto_decompileFloat(1.0,local_14);
        dVar1 = (double)CONCAT44(uStack_8,local_c);
        param_1 = extraout_ECX_00;
        param_2 = extraout_EDX;
        dVar2 = dVar1;
        if ((float10)-1.0 != fVar6) goto LAB_68131932;
      }
      else {
LAB_68131932:
        dVar2 = local_14;
        if (local_14 < dVar1) {
          dVar2 = dVar1;
        }
      }
      local_14 = dVar2;
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_5);
  }
  uVar4 = runtime_convertToNumber(param_1,param_2,(int)param_3,SUB84(local_14,0),
                       (uint)((ulonglong)local_14 >> 0x20),param_7);
  return uVar4;
}



// ============================================================
// Function: javascript_mathMin (FUN_68131990)
// Address: 68131990
// Size: 298 bytes
// Params: undefined4 param_1, uint param_2, ushort * param_3, undefined4 param_4, uint param_5, int param_6, uint * param_7
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
javascript_mathMin(undefined4 param_1,uint param_2,ushort *param_3,undefined4 param_4,uint param_5,
            int param_6,uint *param_7)

{
  double dVar1;
  double dVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  uint uVar5;
  float10 fVar6;
  double local_14;
  int local_c;
  uint uStack_8;
  
  local_14 = **(double **)(*(int *)(param_3 + 10) + 0x1d8);
  if (param_5 == 0) {
    *param_7 = (uint)*(double **)(*(int *)(param_3 + 10) + 0x1d8) | 2;
    return 1;
  }
  uVar5 = 0;
  if (param_5 != 0) {
    do {
      iVar3 = runtime_parseNumber(param_3,*(uint *)(param_6 + uVar5 * 4),(double *)&local_c);
      if (iVar3 == 0) {
        return 0;
      }
      param_2 = uStack_8 & 0x7ff00000;
      if ((param_2 == 0x7ff00000) && ((local_c != 0 || ((uStack_8 & 0xfffff) != 0)))) {
        *param_7 = *(uint *)(*(int *)(param_3 + 10) + 0x1d0) | 2;
        return 1;
      }
      dVar1 = (double)CONCAT44(uStack_8,local_c);
      param_1 = extraout_ECX;
      if ((dVar1 == 0.0) && (local_14 == dVar1)) {
        fVar6 = crypto_decompileFloat(1.0,CONCAT44(uStack_8,local_c));
        dVar1 = (double)CONCAT44(uStack_8,local_c);
        param_1 = extraout_ECX_00;
        param_2 = extraout_EDX;
        dVar2 = dVar1;
        if ((float10)-1.0 != fVar6) goto LAB_68131a59;
      }
      else {
LAB_68131a59:
        dVar2 = local_14;
        if (dVar1 < local_14) {
          dVar2 = dVar1;
        }
      }
      local_14 = dVar2;
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_5);
  }
  uVar4 = runtime_convertToNumber(param_1,param_2,(int)param_3,SUB84(local_14,0),
                       (uint)((ulonglong)local_14 >> 0x20),param_7);
  return uVar4;
}



// ============================================================
// Function: javascript_mathPow (FUN_68131ac0)
// Address: 68131ac0
// Size: 104 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_mathPow(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  float10 fVar3;
  double local_14;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_14);
  if (iVar1 != 0) {
    iVar1 = runtime_parseNumber(param_1,param_4[1],&local_c);
    if (iVar1 != 0) {
      fVar3 = (float10)crypto_computePow(local_14,local_c);
      uVar2 = runtime_convertToNumber(param_5,extraout_EDX,(int)param_1,SUB84((double)fVar3,0),
                           (uint)((ulonglong)(double)fVar3 >> 0x20),(uint *)param_5);
      return uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_seedRandom (FUN_68131b30)
// Address: 68131b30
// Size: 63 bytes
// Params: uint param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_seedRandom(uint param_1,uint param_2)
{
  int unaff_ESI;
  undefined8 uVar1;
  
  uVar1 = __alldiv(param_1,param_2,1000,0);
  *(uint *)(unaff_ESI + 0x1c0) =
       ((uint)uVar1 ^ *(uint *)(unaff_ESI + 0x1a8)) & *(uint *)(unaff_ESI + 0x1b8);
  *(uint *)(unaff_ESI + 0x1c4) =
       ((uint)((ulonglong)uVar1 >> 0x20) ^ *(uint *)(unaff_ESI + 0x1ac)) &
       *(uint *)(unaff_ESI + 0x1bc);
  return 0;
}



// ============================================================
// Function: javascript_initRandom (FUN_68131b70)
// Address: 68131b70
// Size: 121 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_initRandom(void)
{
  int in_EAX;
  undefined8 uVar1;
  
  if (*(int *)(in_EAX + 0x1a4) == 0) {
    *(undefined4 *)(in_EAX + 0x1a4) = 1;
    *(undefined4 *)(in_EAX + 0x1a8) = 0xeece66d;
    *(undefined4 *)(in_EAX + 0x1ac) = 0x5d;
    *(undefined8 *)(in_EAX + 0x1c8) = 0x4350000000000000;
    *(undefined4 *)(in_EAX + 0x1b0) = 0xb;
    *(undefined4 *)(in_EAX + 0x1b4) = 0;
    *(undefined4 *)(in_EAX + 0x1b8) = 0xffffffff;
    *(undefined4 *)(in_EAX + 0x1bc) = 0xffff;
    uVar1 = js_gcMarkRoots();
    javascript_seedRandom((uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20));
  }
  return 0;
}



// ============================================================
// Function: javascript_nextRandomBits (FUN_68131bf0)
// Address: 68131bf0
// Size: 89 bytes
// Params: char param_1
// Return: ulonglong
// Calling convention: __stdcall
// ============================================================

ulonglong javascript_nextRandomBits(char param_1)

{
  uint uVar1;
  int unaff_ESI;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = __allmul(*(uint *)(unaff_ESI + 0x1a8),*(int *)(unaff_ESI + 0x1ac),
                   *(uint *)(unaff_ESI + 0x1c0),*(int *)(unaff_ESI + 0x1c4));
  uVar1 = (int)((ulonglong)lVar2 >> 0x20) + *(int *)(unaff_ESI + 0x1b4) +
          (uint)CARRY4((uint)lVar2,*(uint *)(unaff_ESI + 0x1b0)) & *(uint *)(unaff_ESI + 0x1bc);
  *(uint *)(unaff_ESI + 0x1c0) =
       (uint)lVar2 + *(uint *)(unaff_ESI + 0x1b0) & *(uint *)(unaff_ESI + 0x1b8);
  *(uint *)(unaff_ESI + 0x1c4) = uVar1;
  uVar3 = __aullshr(0x30 - param_1,uVar1);
  return uVar3;
}



// ============================================================
// Function: javascript_generateRandom (FUN_68131c50)
// Address: 68131c50
// Size: 64 bytes
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 javascript_generateRandom(void)

{
  int in_EAX;
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar2 = javascript_nextRandomBits('\x1b');
  uVar1 = (uint)uVar2 * 0x8000000;
  uVar3 = javascript_nextRandomBits('\x1b');
  return (float10)CONCAT44(((uint)uVar2 >> 5) + (uint)CARRY4((uint)uVar3,uVar1),(uint)uVar3 + uVar1)
         / (float10)*(double *)(in_EAX + 0x1c8);
}



// ============================================================
// Function: javascript_mathRandom (FUN_68131c90)
// Address: 68131c90
// Size: 47 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathRandom(int param_1)
{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar1;
  uint *in_stack_00000014;
  
  javascript_initRandom();
  fVar1 = javascript_generateRandom();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,param_1,SUB84((double)fVar1,0),
               (uint)((ulonglong)(double)fVar1 >> 0x20),in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_mathRound (FUN_68131cc0)
// Address: 68131cc0
// Size: 92 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathRound(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double dVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  uVar4 = SUB84(local_c,0);
  uVar5 = (undefined4)((ulonglong)local_c >> 0x20);
  dVar3 = floor(local_c + 0.5);
  fVar2 = crypto_decompileFloat(dVar3,CONCAT44(uVar5,uVar4));
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathSin (FUN_68131d20)
// Address: 68131d20
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathSin(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIsin();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathSqrt (FUN_68131d70)
// Address: 68131d70
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathSqrt(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CIsqrt();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathTan (FUN_68131dc0)
// Address: 68131dc0
// Size: 68 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathTan(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  fVar2 = (float10)_CItan();
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar2,0),
               (uint)((ulonglong)(double)fVar2 >> 0x20),param_5);
  return 0;
}



// ============================================================
// Function: javascript_mathToSource (FUN_68131e10)
// Address: 68131e10
// Size: 32 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_mathToSource(int param_1)

{
  undefined4 *in_stack_00000014;
  
  *in_stack_00000014 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 0xbc) + 8);
  return 1;
}



// ============================================================
// Function: javascript_initMathObject (FUN_68131e30)
// Address: 68131e30
// Size: 86 bytes
// Params: int param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_initMathObject(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  piVar1 = events_createScope(param_1,param_2,"Math",&PTR_DAT_68193330,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    iVar2 = events_attachVtable(param_1,piVar1,(int *)&PTR_s_toSource_68193378);
    if (iVar2 != 0) {
      iVar2 = xtraRuntime_resolveChainedProps(extraout_ECX,extraout_EDX,param_1,piVar1,0x681932a0);
      return -(uint)(iVar2 != 0) & (uint)piVar1;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_mathFmod (FUN_68131e90)
// Address: 68131e90
// Size: 38 bytes
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 javascript_mathFmod(void)

{
  float10 fVar1;
  
  fVar1 = (float10)_CIfmod();
  if (fVar1 < (float10)0) {
    fVar1 = fVar1 + (float10)_DAT_68193470;
  }
  return fVar1;
}



// ============================================================
// Function: js_mathBuiltin (FUN_68131ec0)
// Address: 68131ec0
// Size: 311 bytes
// Params: undefined4 param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint js_mathBuiltin(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  uint uVar3;
  undefined4 extraout_EDX;
  bool bVar4;
  ulonglong uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  floor((double)CONCAT44(param_2,param_1) / (_DAT_68193470 * 365.2425));
  uVar5 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar2 = (int)uVar5;
  uVar1 = iVar2 + 0x7b2;
  dVar6 = floor((double)(iVar2 + 1) * 0.25);
  dVar7 = floor((double)(iVar2 + 0x45) / 100.0);
  dVar8 = floor((double)(iVar2 + 0x171) / 400.0);
  dVar7 = (dVar8 + (((double)(iVar2 * 0x16d) + dVar6) - dVar7)) * _DAT_68193470;
  dVar6 = (double)CONCAT44(param_2,param_1);
  if (dVar6 < dVar7) {
    return iVar2 + 0x7b1;
  }
  uVar3 = uVar1 & 0x80000003;
  bVar4 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar4 = (uVar3 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if ((bVar4) && ((uVar1 != ((int)uVar1 / 100) * 100 || (uVar1 == ((int)uVar1 / 400) * 400)))) {
    param_2 = 0x16e;
  }
  else {
    param_2 = 0x16d;
  }
  uVar3 = iVar2 + 0x7b3;
  if (dVar6 < (double)param_2 * _DAT_68193470 + dVar7) {
    uVar3 = uVar1;
  }
  return uVar3;
}



// ============================================================
// Function: js_mathToUint32 (FUN_68132000)
// Address: 68132000
// Size: 443 bytes
// Params: undefined4 param_1, int param_2
// Return: ulonglong
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong js_mathToUint32(undefined4 param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint uVar5;
  ulonglong uVar6;
  
  uVar2 = js_mathBuiltin(param_1,param_2);
  floor((double)CONCAT44(param_2,param_1) / _DAT_68193470);
  floor((double)(int)(uVar2 - 0x7b1) * 0.25);
  floor((double)(int)(uVar2 - 0x76d) / 100.0);
  floor((double)(int)(uVar2 - 0x641) / 400.0);
  uVar6 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar3 = (int)uVar6;
  if (iVar3 < 0x1f) {
    return uVar6 & 0xffffffff00000000;
  }
  uVar5 = uVar2 & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  if ((uVar5 == 0) && (((int)uVar2 % 100 != 0 || ((int)uVar2 % 400 == 0)))) {
    iVar4 = 0x16e;
  }
  else {
    iVar4 = 0x16d;
  }
  uVar2 = (uint)(iVar4 == 0x16e);
  if (iVar3 < (int)(uVar2 + 0x3b)) {
    return CONCAT44(uVar2,1);
  }
  if (iVar3 < (int)(uVar2 + 0x5a)) {
    return CONCAT44(uVar2,2);
  }
  if (iVar3 < (int)(uVar2 + 0x78)) {
    return CONCAT44(uVar2,3);
  }
  if (iVar3 < (int)(uVar2 + 0x97)) {
    return CONCAT44(uVar2,4);
  }
  if (iVar3 < (int)(uVar2 + 0xb5)) {
    return CONCAT44(uVar2,5);
  }
  if (iVar3 < (int)(uVar2 + 0xd4)) {
    return CONCAT44(uVar2,6);
  }
  if (iVar3 < (int)(uVar2 + 0xf3)) {
    return CONCAT44(uVar2,7);
  }
  if (iVar3 < (int)(uVar2 + 0x111)) {
    return CONCAT44(uVar2,8);
  }
  if (iVar3 < (int)(uVar2 + 0x130)) {
    return CONCAT44(uVar2,9);
  }
  bVar1 = (int)(uVar2 + 0x14e) <= iVar3;
  return (ulonglong)CONCAT14(bVar1,bVar1 + 10);
}



