// Module: javascript
// Topic: Date object - parsing, formatting, component getters/setters, time conversion
// Address range: 0x681321c0 - 0x681355d0
// Functions (91):

//   js_dateFromTimestamp
//   js_dateGetMinute
//   js_dateToTimeValue
//   js_dateGetHour
//   js_dateGetYear
//   js_dateGetMonth
//   js_dateGetDay
//   js_dateGetSecond
//   js_dateGetMillis
//   javascript_matchDateString
//   javascript_computeDateValue
//   javascript_parseDateArgs
//   javascript_parseDateString
//   javascript_dateConstructorCall
//   javascript_dateConstructorNew
//   js_getDateField
//   javascript_dateToString
//   javascript_dateToGMTString
//   javascript_dateToLocaleDateString
//   javascript_dateToLocaleTimeString
//   javascript_dateToLocaleString
//   javascript_dateToTimeString
//   javascript_dateToDateString
//   javascript_dateToUTCString
//   javascript_dateToSource
//   javascript_dateValueOf
//   javascript_dateGetTime
//   javascript_dateGetFullYear
//   javascript_dateGetUTCFullYear
//   javascript_dateGetMonthProp
//   javascript_dateGetUTCMonth
//   javascript_dateGetDate
//   javascript_dateGetUTCDate
//   javascript_dateGetDayProp
//   javascript_dateGetUTCDay
//   javascript_dateGetHours
//   javascript_dateGetUTCHours
//   javascript_dateGetMinutes
//   javascript_dateGetUTCMinutes
//   javascript_dateGetSeconds
//   javascript_dateGetUTCSeconds
//   javascript_dateGetMilliseconds
//   javascript_dateGetUTCMilliseconds
//   javascript_dateGetYearProp
//   javascript_dateSetTime
//   javascript_dateSetYear
//   javascript_dateToJSON
//   javascript_dateToISOString
//   javascript_dateSetFieldImpl
//   js_dateSetComponent
//   javascript_dateSetMilliseconds
//   javascript_dateSetUTCMilliseconds
//   javascript_dateSetSeconds
//   javascript_dateSetUTCSeconds
//   javascript_dateSetMinutes
//   javascript_dateSetUTCMinutes
//   javascript_dateSetHours
//   javascript_dateSetUTCHours
//   js_dateCompute
//   javascript_dateSetDate
//   javascript_dateSetUTCDate
//   javascript_dateSetMonth
//   javascript_dateSetUTCMonth
//   javascript_dateSetFullYear
//   javascript_dateSetUTCFullYear
//   javascript_dateFormatString
//   javascript_dateFormatToSource
//   javascript_dateToStringImpl
//   js_dateSetField
//   javascript_dateParse
//   javascript_dateNow
//   javascript_dateUTC
//   javascript_dateToGMTStringAlias
//   javascript_dateMark
//   js_dateGetTimezone
//   javascript_initDateClass
//   javascript_createDateObject
//   javascript_dateGetTimezoneOffset
//   javascript_dateGetFieldGeneric
//   javascript_booleanToString
//   javascript_booleanToSource
//   javascript_booleanValueOf
//   javascript_booleanConstructor
//   javascript_initBooleanClass
//   javascript_createBooleanObject
//   javascript_numberGetDefaultValue
//   javascript_initNumberClass
//   js_getDateComponent
//   javascript_createNumberObject
//   javascript_numberToString
//   javascript_numberParseInt

// ============================================================
// Function: js_dateFromTimestamp (FUN_681321c0)
// Address: 681321c0
// Size: 376 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int js_dateFromTimestamp(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  uint uVar4;
  undefined4 extraout_EDX;
  ulonglong uVar5;
  
  uVar1 = js_mathBuiltin(param_1,param_2);
  floor((double)CONCAT44(param_2,param_1) / _DAT_68193470);
  floor((double)(int)(uVar1 - 0x7b1) * 0.25);
  floor((double)(int)(uVar1 - 0x76d) / 100.0);
  floor((double)(int)(uVar1 - 0x641) / 400.0);
  uVar5 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar2 = (int)uVar5;
  if (iVar2 < 0x1f) {
    return iVar2 + 1;
  }
  uVar4 = uVar1 & 0x80000003;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
  }
  if ((uVar4 == 0) && (((int)uVar1 % 100 != 0 || ((int)uVar1 % 400 == 0)))) {
    iVar3 = 0x16e;
  }
  else {
    iVar3 = 0x16d;
  }
  uVar1 = (uint)(iVar3 == 0x16e);
  if ((int)(uVar1 + 0x3a) < iVar2) {
    iVar3 = uVar1 + 0x3a;
    if (((((((int)(uVar1 + 0x59) < iVar2) && (iVar3 = uVar1 + 0x59, (int)(uVar1 + 0x77) < iVar2)) &&
          (iVar3 = uVar1 + 0x77, (int)(uVar1 + 0x96) < iVar2)) &&
         ((iVar3 = uVar1 + 0x96, (int)(uVar1 + 0xb4) < iVar2 &&
          (iVar3 = uVar1 + 0xb4, (int)(uVar1 + 0xd3) < iVar2)))) &&
        ((iVar3 = uVar1 + 0xd3, (int)(uVar1 + 0xf2) < iVar2 &&
         ((iVar3 = uVar1 + 0xf2, (int)(uVar1 + 0x110) < iVar2 &&
          (iVar3 = uVar1 + 0x110, (int)(uVar1 + 0x12f) < iVar2)))))) &&
       (iVar3 = uVar1 + 0x12f, (int)(uVar1 + 0x14d) < iVar2)) {
      return iVar2 - (uVar1 + 0x14d);
    }
    return iVar2 - iVar3;
  }
  return iVar2 + -0x1e;
}



// ============================================================
// Function: js_dateGetMinute (FUN_68132340)
// Address: 68132340
// Size: 75 bytes
// Params: double param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int js_dateGetMinute(double param_1)

{
  undefined4 extraout_ECX;
  int iVar1;
  undefined4 extraout_EDX;
  int iVar2;
  ulonglong uVar3;
  
  floor(param_1 / _DAT_68193470);
  uVar3 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar1 = (int)uVar3 + 4;
  iVar2 = (int)((ulonglong)((longlong)iVar1 * 0x6db6db6d) >> 0x20) - iVar1;
  iVar1 = iVar1 + ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 7;
  iVar2 = iVar1 + 7;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  return iVar2;
}



// ============================================================
// Function: js_dateToTimeValue (FUN_68132390)
// Address: 68132390
// Size: 122 bytes
// Params: double param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 js_dateToTimeValue(double param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if ((((*(unsigned int *)((char *)&param_1 + 4)) & 0x7ff00000) == 0x7ff00000) &&
     (((*(unsigned int *)((char *)&param_1 + 0)) != 0 || (((ulonglong)param_1 & 0xfffff00000000) != 0)))) {
    return (float10)param_1;
  }
  uVar1 = strings_roundToUint64();
  lVar2 = __allmul((uint)uVar1,(int)(uVar1 >> 0x20),1000,0);
  (*(unsigned int *)((char *)&param_1 + 4)) = (uint)((ulonglong)lVar2 >> 0x20);
  (*(unsigned int *)((char *)&param_1 + 0)) = (uint)lVar2;
  lVar2 = javascript_getTimezoneOffset((*(unsigned int *)((char *)&param_1 + 0)),(*(unsigned int *)((char *)&param_1 + 4)));
  lVar2 = __alldiv((uint)lVar2,(uint)((ulonglong)lVar2 >> 0x20),1000,0);
  return (float10)lVar2;
}



// ============================================================
// Function: js_dateGetHour (FUN_68132410)
// Address: 68132410
// Size: 47 bytes
// Params: double param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 js_dateGetHour(double param_1)

{
  float10 fVar1;
  
  js_dateToTimeValue(param_1 - _DAT_68196980);
  fVar1 = (float10)_CIfmod();
  return (float10)param_1 - fVar1;
}



// ============================================================
// Function: js_dateGetYear (FUN_68132440)
// Address: 68132440
// Size: 53 bytes
// Params: double param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int js_dateGetYear(double param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  
  floor(param_1 / _DAT_68193478);
  _CIfmod();
  uVar2 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x18;
  }
  return iVar1;
}



// ============================================================
// Function: js_dateGetMonth (FUN_68132480)
// Address: 68132480
// Size: 53 bytes
// Params: double param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int js_dateGetMonth(double param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  
  floor(param_1 / _DAT_68193480);
  _CIfmod();
  uVar2 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x3c;
  }
  return iVar1;
}



// ============================================================
// Function: js_dateGetDay (FUN_681324c0)
// Address: 681324c0
// Size: 53 bytes
// Params: double param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int js_dateGetDay(double param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  
  floor(param_1 / _DAT_68193468);
  _CIfmod();
  uVar2 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x3c;
  }
  return iVar1;
}



// ============================================================
// Function: js_dateGetSecond (FUN_68132500)
// Address: 68132500
// Size: 47 bytes
// Return: ulonglong
// Calling convention: __stdcall
// ============================================================

ulonglong js_dateGetSecond(void)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  ulonglong uVar1;
  ulonglong uVar2;
  
  _CIfmod();
  uVar1 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  if ((int)uVar1 < 0) {
    uVar2 = strings_floatToUint64(extraout_ECX_00,(int)(uVar1 >> 0x20));
    uVar1 = CONCAT44((int)(uVar2 >> 0x20),(int)uVar2 + (int)uVar1);
  }
  return uVar1;
}



// ============================================================
// Function: js_dateGetMillis (FUN_68132530)
// Address: 68132530
// Size: 311 bytes
// Params: double param_1, double param_2, double param_3
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 js_dateGetMillis(double param_1,double param_2,double param_3)

{
  uint uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar2;
  bool bVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  ulonglong uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  dVar5 = floor(param_2 / 12.0);
  dVar5 = dVar5 + param_1;
  _CIfmod();
  uVar4 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  uVar1 = (uint)uVar4 & 0x80000003;
  bVar3 = (uVar4 & 0x80000003) == 0;
  if ((int)uVar1 < 0) {
    bVar3 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if ((bVar3) &&
     ((uVar1 = (int)(uint)uVar4 >> 0x1f,
      (int)((longlong)((ulonglong)uVar1 << 0x20 | uVar4 & 0xffffffff) % 100) != 0 ||
      ((int)((longlong)((ulonglong)uVar1 << 0x20 | uVar4 & 0xffffffff) % 400) == 0)))) {
    iVar2 = 0x16e;
  }
  else {
    iVar2 = 0x16d;
  }
  dVar6 = floor((double)((extraout_ST0 - (float10)1969.0) * (float10)0.25));
  dVar7 = floor((dVar5 - 1901.0) / 100.0);
  dVar8 = floor((dVar5 - 1601.0) / 400.0);
  floor(((dVar8 + (((dVar5 - 1970.0) * 365.0 + dVar6) - dVar7)) * _DAT_68193470) / _DAT_68193470);
  uVar4 = strings_floatToUint64(extraout_ECX_00,extraout_EDX_00);
  return (extraout_ST0_00 +
          (float10)*(double *)(&DAT_68193488 + ((int)uVar4 + (uint)(iVar2 == 0x16e) * 0xc) * 8) +
         (float10)param_3) - (float10)1.0;
}



// ============================================================
// Function: javascript_matchDateString (FUN_68132670)
// Address: 68132670
// Size: 201 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall javascript_matchDateString(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  char *pcVar7;
  bool bVar8;
  
  if (0 < param_4) {
    puVar6 = (ushort *)(param_1 + in_EAX * 2);
    pcVar7 = (char *)(param_3 + param_2);
    do {
      cVar1 = *pcVar7;
      if ((cVar1 == '\0') || (*puVar6 == 0)) break;
      if (param_5 == 0) {
        bVar8 = (short)cVar1 == *puVar6;
      }
      else {
        uVar2 = crypto_allocString((uint)(ushort)(short)cVar1);
        if ((uVar2 & 0x200000) == 0) {
          uVar2 = (uint)(ushort)(short)*pcVar7;
        }
        else {
          iVar3 = crypto_allocString((uint)(ushort)(short)*pcVar7);
          uVar2 = (iVar3 >> 0x16) + (uint)(ushort)(short)*pcVar7;
        }
        uVar4 = crypto_allocString((uint)*puVar6);
        uVar5 = (uint)*puVar6;
        if ((uVar4 & 0x200000) != 0) {
          iVar3 = crypto_allocString(uVar5);
          uVar5 = (iVar3 >> 0x16) + (uint)*puVar6;
        }
        bVar8 = uVar2 == uVar5;
      }
      if (!bVar8) break;
      param_4 = param_4 + -1;
      pcVar7 = pcVar7 + 1;
      puVar6 = puVar6 + 1;
    } while (0 < param_4);
  }
  if (param_4 != 0) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: javascript_computeDateValue (FUN_68132740)
// Address: 68132740
// Size: 73 bytes
// Params: double param_1, double param_2, double param_3, double param_4, double param_5, double param_6, double param_7
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 javascript_computeDateValue(double param_1,double param_2,double param_3,double param_4,double param_5,
                    double param_6,double param_7)

{
  float10 fVar1;
  
  fVar1 = js_dateGetMillis(param_1,param_2,param_3);
  return (((float10)param_4 * (float10)60.0 + (float10)param_5) * (float10)60.0 + (float10)param_6)
         * (float10)_DAT_68193468 + (float10)param_7 + fVar1 * (float10)_DAT_68193470;
}



// ============================================================
// Function: javascript_parseDateArgs (FUN_68132790)
// Address: 68132790
// Size: 346 bytes
// Params: ushort * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_parseDateArgs(ushort *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  int iVar1;
  double *extraout_ECX;
  double *pdVar2;
  double *extraout_EDX;
  double *pdVar3;
  uint uVar4;
  float10 fVar5;
  double dVar6;
  undefined8 local_48;
  double local_40 [7];
  uint local_8;
  
  uVar4 = 0;
  do {
    if (uVar4 < param_3) {
      iVar1 = runtime_parseNumber(param_1,*(uint *)(param_4 + uVar4 * 4),(double *)&local_48);
      if (iVar1 == 0) {
        return 0;
      }
      fVar5 = (float10)local_48;
      pdVar2 = param_5;
      pdVar3 = extraout_EDX;
      if (((*(unsigned int *)((char *)&local_48 + 4)) & 0x7ff00000) == 0x7ff00000) goto LAB_681328cb;
      dVar6 = floor(local_48);
    }
    else {
      dVar6 = 0.0;
    }
    local_40[uVar4] = dVar6;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 7);
  if ((0.0 <= local_40[0]) && (local_40[0] <= 99.0)) {
    local_40[0] = local_40[0] + 1900.0;
  }
  if (local_40[2] < 1.0) {
    local_40[2] = 1.0;
  }
  fVar5 = javascript_computeDateValue(local_40[0],local_40[1],local_40[2],local_40[3],local_40[4],local_40[5],
                       local_40[6]);
  (*(unsigned int *)((char *)&local_48 + 4)) = (uint)((ulonglong)(double)fVar5 >> 0x20);
  if ((((*(unsigned int *)((char *)&local_48 + 4)) & 0x7ff00000) == 0x7ff00000) || ((float10)8.64e+15 < ABS(fVar5))) {
    pdVar2 = *(double **)(*(int *)(param_1 + 10) + 0x1d0);
    fVar5 = (float10)*pdVar2;
  }
  else {
    local_48 = (double)fVar5;
    fVar5 = runtime_powFloat(SUB84((double)(fVar5 + (float10)0.0),0),
                         (uint)((ulonglong)(double)(fVar5 + (float10)0.0) >> 0x20));
    pdVar2 = extraout_ECX;
  }
  local_48 = (double)fVar5;
  pdVar3 = param_5;
LAB_681328cb:
  runtime_convertToNumber(pdVar2,pdVar3,(int)param_1,SUB84((double)fVar5,0),
               (uint)((ulonglong)(double)fVar5 >> 0x20),(uint *)param_5);
  return 0;
}



// ============================================================
// Function: javascript_parseDateString (FUN_681328f0)
// Address: 681328f0
// Size: 1342 bytes
// Params: double * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 javascript_parseDateString(double *param_1)

{
  short sVar1;
  ushort uVar2;
  uint *puVar3;
  double dVar4;
  bool bVar5;
  uint *in_EAX;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  float10 fVar14;
  double local_34;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_8;
  
  uVar6 = *in_EAX;
  uVar13 = 0;
  if ((uVar6 & 0x40000000) == 0) {
    local_28 = in_EAX[1];
  }
  else {
    puVar3 = (uint *)in_EAX[1];
    if ((*puVar3 & 0x40000000) == 0) {
      if ((int)uVar6 < 0) {
        local_28 = puVar3[1];
      }
      else {
        local_28 = puVar3[1] + (uVar6 >> 0xf & 0x7fff) * 2;
      }
    }
    else {
      local_28 = crypto_getStringLen(in_EAX);
    }
  }
  uVar6 = *in_EAX;
  if ((uVar6 & 0x40000000) != 0) {
    uVar6 = (-(uint)((uVar6 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar6;
  }
  uVar11 = 0;
  local_34 = -1.0;
  local_20 = 0xffffffff;
  dVar4 = -1.0;
  local_1c = -1;
  local_18 = 0xffffffff;
  local_8 = 0xffffffff;
  local_10 = 0xffffffff;
  local_24 = 0xffffffff;
  bVar5 = false;
  if ((uVar6 != 0) && (uVar6 != 0)) {
LAB_681329a7:
    uVar7 = (uint)*(ushort *)(local_28 + uVar11 * 2);
    uVar12 = uVar11 + 1;
    if ((uVar7 < 0x21) || (uVar7 == 0x2c)) {
      if (uVar7 != 0x2d) goto LAB_68132ccc;
LAB_68132dc1:
      uVar2 = *(ushort *)(local_28 + uVar12 * 2);
      if ((0x2f < uVar2) && (uVar2 < 0x3a)) {
LAB_68132ddc:
        uVar13 = uVar7;
      }
    }
    else {
      if (uVar7 == 0x2d) goto LAB_68132dc1;
      if (uVar7 == 0x28) {
        iVar9 = 1;
        do {
          while( true ) {
            if (uVar6 <= uVar12) goto LAB_68132cd4;
            sVar1 = *(short *)(local_28 + uVar12 * 2);
            uVar12 = uVar12 + 1;
            if (sVar1 != 0x28) break;
            iVar9 = iVar9 + 1;
          }
        } while ((sVar1 != 0x29) || (iVar9 = iVar9 + -1, 0 < iVar9));
      }
      else {
        uVar10 = uVar7 - 0x30;
        if (9 < uVar10) {
          if (((uVar7 == 0x2f) || (uVar7 == 0x3a)) || (uVar7 == 0x2b)) goto LAB_68132ddc;
          while ((uVar12 < uVar6 &&
                 (((uVar13 = (uint)*(ushort *)(local_28 + uVar12 * 2), 0x40 < uVar13 &&
                   (uVar13 < 0x5b)) || (uVar13 - 0x61 < 0x1a))))) {
            uVar12 = uVar12 + 1;
          }
          if (uVar11 + 1 < uVar12) {
            iVar9 = 0x1f;
            while (iVar8 = javascript_matchDateString(local_28,0,(int)(&PTR_DAT_68193590)[iVar9],uVar12 - uVar11,1
                                       ), iVar8 == 0) {
              iVar9 = iVar9 + -1;
              if (iVar9 < 0) {
                *param_1 = 0.0;
                return 0;
              }
            }
            iVar8 = *(int *)(iVar9 * 4 + 0x68193610);
            if (iVar8 != 0) {
              if (iVar8 < 0) {
                if (0xc < local_8) goto LAB_68132e08;
                if (iVar8 == -1) {
                  if (local_8 == 0xc) {
                    local_8 = 0;
                  }
                }
                else if ((iVar8 == -2) && (local_8 != 0xc)) {
                  local_8 = local_8 + 0xc;
                }
              }
              else if (iVar8 < 0xe) {
                if (-1 < local_1c) goto LAB_68132e08;
                local_1c = iVar8 + -2;
              }
              else {
                local_34 = (double)(iVar8 + -10000);
              }
            }
            if (iVar9 < 0) {
LAB_68132e08:
              *param_1 = 0.0;
              return 0;
            }
            uVar13 = 0;
            dVar4 = local_34;
            goto LAB_68132ccc;
          }
          goto LAB_68132e1e;
        }
        while ((uVar12 < uVar6 &&
               (uVar7 = (uint)*(ushort *)(local_28 + uVar12 * 2), uVar7 - 0x30 < 10))) {
          uVar12 = uVar12 + 1;
          uVar10 = (uVar7 - 0x30) + uVar10 * 10;
        }
        if ((uVar13 != 0x2b) && (uVar13 != 0x2d)) {
          if ((int)uVar10 < 0x46) {
            if ((((uVar13 != 0x2f) || (local_1c < 0)) || ((int)local_18 < 0)) ||
               (-1 < (int)local_20)) {
              if (uVar7 == 0x3a) {
                if ((int)local_8 < 0) {
                  uVar13 = 0;
                  local_8 = uVar10;
                  goto LAB_68132ccc;
                }
                if (-1 < (int)local_10) goto LAB_68132e1e;
                uVar13 = 0;
                local_10 = uVar10;
              }
              else if (uVar7 == 0x2f) {
                if (local_1c < 0) {
                  local_1c = uVar10 - 1;
                  uVar13 = 0;
                }
                else {
LAB_68132b21:
                  if (-1 < (int)local_18) goto LAB_68132e1e;
                  uVar13 = 0;
                  local_18 = uVar10;
                }
              }
              else {
                if (((uVar12 < uVar6) && (uVar7 != 0x2c)) && ((0x20 < uVar7 && (uVar7 != 0x2d))))
                goto LAB_68132e1e;
                if ((bVar5) && ((int)uVar10 < 0x3c)) {
                  if (0.0 <= dVar4) {
                    local_34 = (double)(int)uVar10 + dVar4;
                    uVar13 = 0;
                    dVar4 = local_34;
                  }
                  else {
                    local_34 = dVar4 - (double)(int)uVar10;
                    uVar13 = 0;
                    dVar4 = local_34;
                  }
                }
                else {
                  if ((int)local_8 < 0) {
                    if ((int)local_10 < 0) goto LAB_68132b21;
                  }
                  else if ((int)local_10 < 0) {
                    uVar13 = 0;
                    local_10 = uVar10;
                    goto LAB_68132ccc;
                  }
                  if (-1 < (int)local_24) goto LAB_68132b21;
                  uVar13 = 0;
                  local_24 = uVar10;
                }
              }
              goto LAB_68132ccc;
            }
          }
          else if (-1 < (int)local_20) goto LAB_68132e1e;
          if ((((uVar7 < 0x21) || (uVar7 == 0x2c)) || (uVar7 == 0x2f)) || (uVar6 <= uVar12)) {
            if ((int)uVar10 < 100) {
              uVar10 = uVar10 + 0x76c;
            }
            uVar13 = 0;
            local_20 = uVar10;
            goto LAB_68132ccc;
          }
          goto LAB_68132e1e;
        }
        bVar5 = true;
        if ((int)uVar10 < 0x18) {
          local_14 = uVar10 * 0x3c;
        }
        else {
          local_14 = uVar10 + ((int)uVar10 / 100) * -0x28;
        }
        if (uVar13 == 0x2b) {
          local_14 = -local_14;
        }
        if (dVar4 == 0.0) {
          local_34 = (double)local_14;
          uVar13 = 0;
          dVar4 = local_34;
        }
        else {
          if (dVar4 != -1.0) goto LAB_68132e1e;
          local_34 = (double)local_14;
          uVar13 = 0;
          dVar4 = local_34;
        }
      }
    }
LAB_68132ccc:
    uVar11 = uVar12;
    if (uVar6 <= uVar12) goto LAB_68132cd4;
    goto LAB_681329a7;
  }
  goto LAB_68132e1e;
LAB_68132cd4:
  if (((-1 < (int)local_20) && (-1 < local_1c)) && (-1 < (int)local_18)) {
    if ((int)local_24 < 0) {
      local_24 = 0;
    }
    if ((int)local_10 < 0) {
      local_10 = 0;
    }
    if ((int)local_8 < 0) {
      local_8 = 0;
    }
    if (dVar4 == -1.0) {
      fVar14 = javascript_computeDateValue((double)(int)local_20,(double)local_1c,(double)(int)local_18,
                            (double)(int)local_8,(double)(int)local_10,(double)(int)local_24,0.0);
      fVar14 = js_dateGetHour((double)fVar14);
      *param_1 = (double)fVar14;
      return 1;
    }
    fVar14 = javascript_computeDateValue((double)(int)local_20,(double)local_1c,(double)(int)local_18,
                          (double)(int)local_8,(double)(int)local_10,(double)(int)local_24,0.0);
    *param_1 = (double)((float10)_DAT_68193480 * (float10)local_34 + fVar14);
    return 1;
  }
LAB_68132e1e:
  *param_1 = 0.0;
  return 0;
}



// ============================================================
// Function: javascript_dateConstructorCall (FUN_68132e30)
// Address: 68132e30
// Size: 165 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_dateConstructorCall(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  double *extraout_EDX;
  double *pdVar5;
  float10 fVar6;
  undefined4 local_c;
  uint uStack_8;
  
  uVar2 = certs_hashLookup(param_1,*param_4);
  if (uVar2 == 0) {
    return 0;
  }
  iVar3 = javascript_parseDateString((double *)&local_c);
  if (iVar3 != 0) {
    if (((uStack_8 & 0x7ff00000) == 0x7ff00000) ||
       (8.64e+15 < ABS((double)CONCAT44(uStack_8,local_c)))) {
      iVar3 = *(int *)(param_1 + 0x14);
      pdVar5 = *(double **)(iVar3 + 0x1d0);
      fVar6 = (float10)*pdVar5;
    }
    else {
      dVar1 = (double)CONCAT44(uStack_8,local_c) + 0.0;
      fVar6 = runtime_powFloat(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
      iVar3 = extraout_ECX;
      pdVar5 = extraout_EDX;
    }
    uVar4 = runtime_convertToNumber(iVar3,pdVar5,param_1,SUB84((double)fVar6,0),
                         (uint)((ulonglong)(double)fVar6 >> 0x20),param_5);
    return uVar4;
  }
  *param_5 = *(uint *)(*(int *)(param_1 + 0x14) + 0x1d0) | 2;
  return 1;
}



// ============================================================
// Function: javascript_dateConstructorNew (FUN_68132ee0)
// Address: 68132ee0
// Size: 59 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateConstructorNew(int param_1)
{
  undefined8 uVar1;
  longlong lVar2;
  uint *in_stack_00000014;
  
  uVar1 = js_gcMarkRoots();
  lVar2 = __alldiv((uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20),1000,0);
  runtime_formatNumber(param_1,(double)lVar2,in_stack_00000014);
  return 0;
}



// ============================================================
// Function: js_getDateField (FUN_68132f20)
// Address: 68132f20
// Size: 28 bytes
// Params: undefined4 param_1
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall js_getDateField(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  iVar1 = xtra_callMethod(param_1,unaff_ESI,&PTR_DAT_68193548,in_EAX);
  if (iVar1 == 0) {
    return 0;
  }
  return *(uint *)(*(int *)(unaff_ESI + 4) + 0xc) & 0xfffffff8;
}



// ============================================================
// Function: javascript_dateToString (FUN_68132f40)
// Address: 68132f40
// Size: 55 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToString(int param_1)
{
  undefined8 *puVar1;
  undefined4 extraout_EDX;
  undefined4 in_stack_00000014;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,(int)*puVar1,
               (uint)((ulonglong)*puVar1 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateToGMTString (FUN_68132f80)
// Address: 68132f80
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToGMTString(int param_1)
{
  double dVar1;
  int iVar2;
  double *pdVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar4;
  uint uStack00000010;
  undefined4 in_stack_00000014;
  uint uStack_8;
  
  pdVar3 = (double *)js_getDateField(param_1);
  if (pdVar3 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar3;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) != 0x7ff00000) {
    js_dateToTimeValue(dVar1);
    fVar4 = (float10)_CIfmod();
    uStack00000010 =
         js_mathBuiltin(SUB84((double)(fVar4 + (float10)dVar1),0),
                      (int)((ulonglong)(double)(fVar4 + (float10)dVar1) >> 0x20));
    iVar2 = *(int *)(param_1 + 0xc);
    dVar1 = (double)(int)uStack00000010;
    if (((iVar2 == 100) || (iVar2 == 0x6e)) || (iVar2 == 0x78)) {
      /* FIXUP(C2064: term does not evaluate to a function taking 0 arguments): if ((!NAN(dVar1) && 1900.0 < dVar1 != (dVar1 == 1900.0)) && (dVar1 < 2000.0)) { */
        dVar1 = dVar1 - 1900.0;
      }
    }
    else {
      dVar1 = dVar1 - 1900.0;
    }
    runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84(dVar1,0),
                 (uint)((ulonglong)dVar1 >> 0x20),(uint *)in_stack_00000014);
    return 0;
  }
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '('): runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8, */
               /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '('): (uint *)in_stack_00000014); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return 0; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: javascript_dateToLocaleDateString (FUN_68132fd0)
// Address: 68132fd0
// Size: 134 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToLocaleDateString(void)
{
  double dVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar4;
  
  js_dateToTimeValue((double)in_ST0);
  fVar4 = (float10)_CIfmod();
  dVar1 = (double)(fVar4 + (float10)*(double *)(unaff_EBP + -8));
  uVar3 = js_mathBuiltin(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  *(uint *)(unaff_EBP + 0x14) = uVar3;
  iVar2 = *(int *)(unaff_EDI + 0xc);
  dVar1 = (double)*(int *)(unaff_EBP + 0x14);
  if (((iVar2 == 100) || (iVar2 == 0x6e)) || (iVar2 == 0x78)) {
    /* FIXUP(C2064: term does not evaluate to a function taking 0 arguments): if ((!NAN(dVar1) && 1900.0 < dVar1 != (dVar1 == 1900.0)) && (dVar1 < 2000.0)) { */
      dVar1 = dVar1 - 1900.0;
    }
  }
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'else'): else { */
    /* FIXUP(C2099): dVar1 = dVar1 - 1900.0; */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '*'): runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,SUB84(dVar1,0), */
               /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '<parameter-list>'): (uint)((ulonglong)dVar1 >> 0x20),(uint *)*(undefined4 *)(unaff_EBP + 0x18)); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return 0; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: javascript_dateToLocaleTimeString (FUN_68133060)
// Address: 68133060
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToLocaleTimeString(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  uint uStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  uStack00000010 =
       js_mathBuiltin(SUB84((double)(fVar3 + (float10)dVar1),0),
                    (int)((ulonglong)(double)(fVar3 + (float10)dVar1) >> 0x20));
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)(int)uStack00000010,0),
               (uint)((ulonglong)(double)(int)uStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateToLocaleString (FUN_681330b0)
// Address: 681330b0
// Size: 72 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToLocaleString(void)
{
  double dVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar3;
  
  js_dateToTimeValue((double)in_ST0);
  fVar3 = (float10)_CIfmod();
  dVar1 = (double)(fVar3 + (float10)*(double *)(unaff_EBP + -8));
  uVar2 = js_mathBuiltin(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  *(uint *)(unaff_EBP + 0x14) = uVar2;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateToTimeString (FUN_68133100)
// Address: 68133100
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToTimeString(int param_1)
{
  undefined8 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint uStack00000010;
  undefined4 in_stack_00000014;
  int iVar2;
  undefined4 uStack_8;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  uStack_8 = (uint)((ulonglong)*puVar1 >> 0x20);
  iVar2 = (int)*puVar1;
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,iVar2,uStack_8,(uint *)in_stack_00000014);
    return 0;
  }
  uStack00000010 = js_mathBuiltin(iVar2,uStack_8);
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)(int)uStack00000010,0),
               (uint)((ulonglong)(double)(int)uStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateToDateString (FUN_68133150)
// Address: 68133150
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToDateString(void)
{
  uint uVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  
  uVar1 = js_mathBuiltin(SUB84((double)in_ST0,0),(int)((ulonglong)(double)in_ST0 >> 0x20));
  *(uint *)(unaff_EBP + 0x14) = uVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateToUTCString (FUN_68133180)
// Address: 68133180
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToUTCString(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  ulonglong uVar4;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  uVar4 = js_mathToUint32(SUB84((double)(fVar3 + (float10)dVar1),0),
                       (int)((ulonglong)(double)(fVar3 + (float10)dVar1) >> 0x20));
  iStack00000010 = (int)uVar4;
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateToSource (FUN_681331d0)
// Address: 681331d0
// Size: 72 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToSource(void)
{
  double dVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar2;
  ulonglong uVar3;
  
  js_dateToTimeValue((double)in_ST0);
  fVar2 = (float10)_CIfmod();
  dVar1 = (double)(fVar2 + (float10)*(double *)(unaff_EBP + -8));
  uVar3 = js_mathToUint32(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  *(int *)(unaff_EBP + 0x14) = (int)uVar3;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateValueOf (FUN_68133220)
// Address: 68133220
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateValueOf(int param_1)
{
  undefined8 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  int iStack00000010;
  undefined4 in_stack_00000014;
  int iVar3;
  undefined4 uStack_8;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  uStack_8 = (uint)((ulonglong)*puVar1 >> 0x20);
  iVar3 = (int)*puVar1;
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,iVar3,uStack_8,(uint *)in_stack_00000014);
    return 0;
  }
  uVar2 = js_mathToUint32(iVar3,uStack_8);
  iStack00000010 = (int)uVar2;
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetTime (FUN_68133270)
// Address: 68133270
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetTime(void)
{
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  ulonglong uVar1;
  
  uVar1 = js_mathToUint32(SUB84((double)in_ST0,0),(int)((ulonglong)(double)in_ST0 >> 0x20));
  *(int *)(unaff_EBP + 0x14) = (int)uVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetFullYear (FUN_681332a0)
// Address: 681332a0
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetFullYear(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  iStack00000010 =
       js_dateFromTimestamp(SUB84((double)(fVar3 + (float10)dVar1),0),
                    (int)((ulonglong)(double)(fVar3 + (float10)dVar1) >> 0x20));
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCFullYear (FUN_681332f0)
// Address: 681332f0
// Size: 72 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCFullYear(void)
{
  double dVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar3;
  
  js_dateToTimeValue((double)in_ST0);
  fVar3 = (float10)_CIfmod();
  dVar1 = (double)(fVar3 + (float10)*(double *)(unaff_EBP + -8));
  iVar2 = js_dateFromTimestamp(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  *(int *)(unaff_EBP + 0x14) = iVar2;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetMonthProp (FUN_68133340)
// Address: 68133340
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetMonthProp(int param_1)
{
  undefined8 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iStack00000010;
  undefined4 in_stack_00000014;
  int iVar2;
  undefined4 uStack_8;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  uStack_8 = (uint)((ulonglong)*puVar1 >> 0x20);
  iVar2 = (int)*puVar1;
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,iVar2,uStack_8,(uint *)in_stack_00000014);
    return 0;
  }
  iStack00000010 = js_dateFromTimestamp(iVar2,uStack_8);
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCMonth (FUN_68133390)
// Address: 68133390
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCMonth(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  
  iVar1 = js_dateFromTimestamp(SUB84((double)in_ST0,0),(int)((ulonglong)(double)in_ST0 >> 0x20));
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetDate (FUN_681333c0)
// Address: 681333c0
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetDate(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  iStack00000010 = js_dateGetMinute((double)(fVar3 + (float10)dVar1));
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCDate (FUN_68133410)
// Address: 68133410
// Size: 72 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCDate(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar2;
  
  js_dateToTimeValue((double)in_ST0);
  fVar2 = (float10)_CIfmod();
  iVar1 = js_dateGetMinute((double)(fVar2 + (float10)*(double *)(unaff_EBP + -8)));
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetDayProp (FUN_68133460)
// Address: 68133460
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetDayProp(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  iStack00000010 = js_dateGetMinute(dVar1);
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCDay (FUN_681334b0)
// Address: 681334b0
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCDay(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  
  iVar1 = js_dateGetMinute((double)in_ST0);
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetHours (FUN_681334e0)
// Address: 681334e0
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetHours(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  iStack00000010 = js_dateGetYear((double)(fVar3 + (float10)dVar1));
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCHours (FUN_68133530)
// Address: 68133530
// Size: 72 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCHours(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar2;
  
  js_dateToTimeValue((double)in_ST0);
  fVar2 = (float10)_CIfmod();
  iVar1 = js_dateGetYear((double)(fVar2 + (float10)*(double *)(unaff_EBP + -8)));
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetMinutes (FUN_68133580)
// Address: 68133580
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetMinutes(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  iStack00000010 = js_dateGetYear(dVar1);
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCMinutes (FUN_681335d0)
// Address: 681335d0
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCMinutes(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  
  iVar1 = js_dateGetYear((double)in_ST0);
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetSeconds (FUN_68133600)
// Address: 68133600
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetSeconds(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  iStack00000010 = js_dateGetMonth((double)(fVar3 + (float10)dVar1));
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCSeconds (FUN_68133650)
// Address: 68133650
// Size: 72 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCSeconds(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  float10 fVar2;
  
  js_dateToTimeValue((double)in_ST0);
  fVar2 = (float10)_CIfmod();
  iVar1 = js_dateGetMonth((double)(fVar2 + (float10)*(double *)(unaff_EBP + -8)));
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetMilliseconds (FUN_681336a0)
// Address: 681336a0
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetMilliseconds(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  iStack00000010 = js_dateGetMonth(dVar1);
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateGetUTCMilliseconds (FUN_681336f0)
// Address: 681336f0
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetUTCMilliseconds(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  
  iVar1 = js_dateGetMonth((double)in_ST0);
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateGetYearProp (FUN_68133720)
// Address: 68133720
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateGetYearProp(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,SUB84(dVar1,0),uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  iStack00000010 = js_dateGetDay(dVar1);
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateSetTime (FUN_68133770)
// Address: 68133770
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetTime(void)
{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  float10 in_ST0;
  
  iVar1 = js_dateGetDay((double)in_ST0);
  *(int *)(unaff_EBP + 0x14) = iVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateSetYear (FUN_681337a0)
// Address: 681337a0
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetYear(int param_1)
{
  undefined8 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  int iStack00000010;
  undefined4 in_stack_00000014;
  undefined4 uStack_8;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  uStack_8 = (uint)((ulonglong)*puVar1 >> 0x20);
  if ((uStack_8 & 0x7ff00000) == 0x7ff00000) {
    runtime_convertToNumber(in_stack_00000014,extraout_EDX,param_1,(int)*puVar1,uStack_8,
                 (uint *)in_stack_00000014);
    return 0;
  }
  uVar2 = js_dateGetSecond();
  iStack00000010 = (int)uVar2;
  runtime_convertToNumber(extraout_ECX,in_stack_00000014,param_1,SUB84((double)iStack00000010,0),
               (uint)((ulonglong)(double)iStack00000010 >> 0x20),(uint *)in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateToJSON (FUN_681337f0)
// Address: 681337f0
// Size: 41 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToJSON(void)
{
  undefined4 extraout_ECX;
  int unaff_EBP;
  int unaff_EDI;
  ulonglong uVar1;
  
  uVar1 = js_dateGetSecond();
  *(int *)(unaff_EBP + 0x14) = (int)uVar1;
  runtime_convertToNumber(extraout_ECX,*(undefined4 *)(unaff_EBP + 0x18),unaff_EDI,
               SUB84((double)*(int *)(unaff_EBP + 0x14),0),
               (uint)((ulonglong)(double)*(int *)(unaff_EBP + 0x14) >> 0x20),
               (uint *)*(undefined4 *)(unaff_EBP + 0x18));
  return 0;
}



// ============================================================
// Function: javascript_dateToISOString (FUN_68133820)
// Address: 68133820
// Size: 106 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int javascript_dateToISOString(int param_1)
{
  double dVar1;
  double *pdVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  float10 fVar4;
  uint *in_stack_00000014;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  js_dateToTimeValue(dVar1);
  fVar3 = (float10)_CIfmod();
  fVar4 = (float10)dVar1;
  dVar1 = (double)((fVar4 - (fVar3 + fVar4)) / (float10)_DAT_68193480);
  runtime_convertToNumber(extraout_ECX,extraout_EDX,param_1,SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20),
               in_stack_00000014);
  return 0;
}



// ============================================================
// Function: javascript_dateSetFieldImpl (FUN_68133890)
// Address: 68133890
// Size: 163 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_dateSetFieldImpl(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,undefined4 param_5)

{
  double *pdVar1;
  int iVar2;
  undefined4 uVar3;
  double *extraout_ECX;
  double *pdVar4;
  float10 fVar5;
  undefined8 local_c;
  
  pdVar1 = (double *)js_getDateField(param_1);
  if ((pdVar1 != (double *)0x0) &&
     (iVar2 = runtime_parseNumber(param_1,*param_4,(double *)&local_c), iVar2 != 0)) {
    if ((((*(unsigned int *)((char *)&local_c + 4)) & 0x7ff00000) == 0x7ff00000) || (8.64e+15 < ABS(local_c))) {
      pdVar4 = *(double **)(*(int *)(param_1 + 10) + 0x1d0);
      fVar5 = (float10)*pdVar4;
    }
    else {
      fVar5 = runtime_powFloat(SUB84(local_c + 0.0,0),(uint)((ulonglong)(local_c + 0.0) >> 0x20));
      pdVar4 = extraout_ECX;
    }
    local_c = (double)fVar5;
    *pdVar1 = (double)fVar5;
    uVar3 = runtime_convertToNumber(pdVar4,param_5,(int)param_1,SUB84(local_c,0),
                         (uint)((ulonglong)local_c >> 0x20),(uint *)param_5);
    return uVar3;
  }
  return 0;
}



// ============================================================
// Function: js_dateSetComponent (FUN_68133940)
// Address: 68133940
// Size: 657 bytes
// Params: void * this, uint param_1, int param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __thiscall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
js_dateSetComponent(void *this,uint param_1,int param_2,uint param_3,int param_4,double *param_5)
{
  double *pdVar1;
  double *pdVar2;
  int iVar3;
  double *pdVar4;
  uint uVar5;
  float10 fVar6;
  ulonglong uVar7;
  double dVar8;
  double local_5c;
  double local_54;
  double local_4c;
  undefined8 local_30;
  undefined8 local_28;
  double local_20 [3];
  uint local_8;
  
  pdVar2 = (double *)js_getDateField(this);
  if (pdVar2 != (double *)0x0) {
    dVar8 = *pdVar2;
    (*(unsigned int *)((char *)&local_30 + 4)) = (uint)((ulonglong)dVar8 >> 0x20);
    if (((*(unsigned int *)((char *)&local_30 + 4)) & 0x7ff00000) == 0x7ff00000) {
      pdVar4 = (double *)0x7ff00000;
      pdVar2 = param_5;
    }
    else {
      if (param_1 == 0) {
        param_1 = 1;
      }
      else if (param_3 < param_1) {
        param_1 = param_3;
      }
      uVar5 = 0;
      if (param_1 != 0) {
        pdVar4 = (double *)&local_28;
        do {
          iVar3 = runtime_parseNumber(this,*(uint *)(param_2 + uVar5 * 4),pdVar4);
          if (iVar3 == 0) goto LAB_68133971;
          if (((ulonglong)*pdVar4 & 0x7ff0000000000000) == 0x7ff0000000000000) {
            dVar8 = **(double **)(*(int *)((int)this + 0x14) + 0x1d0);
            *pdVar2 = dVar8;
            pdVar4 = pdVar2;
            pdVar2 = param_5;
            goto LAB_68133bb9;
          }
          fVar6 = runtime_powFloat(SUB84(*pdVar4,0),(uint)((ulonglong)*pdVar4 >> 0x20));
          *pdVar4 = (double)fVar6;
          uVar5 = uVar5 + 1;
          pdVar4 = pdVar4 + 1;
        } while (uVar5 < param_1);
      }
      fVar6 = (float10)dVar8;
      if (param_4 != 0) {
        js_dateToTimeValue(dVar8);
        fVar6 = (float10)_CIfmod();
        fVar6 = fVar6 + (float10)dVar8;
      }
      dVar8 = (double)fVar6;
      pdVar4 = (double *)&local_28;
      pdVar1 = local_20 + (param_1 - 1);
      if ((param_3 < 4) || (pdVar1 <= pdVar4)) {
        iVar3 = js_dateGetYear((double)fVar6);
        local_5c = (double)iVar3;
        fVar6 = (float10)dVar8;
      }
      else {
        pdVar4 = local_20;
        local_5c = local_28;
      }
      if ((param_3 < 3) || (pdVar1 <= pdVar4)) {
        iVar3 = js_dateGetMonth((double)fVar6);
        local_4c = (double)iVar3;
        fVar6 = (float10)dVar8;
      }
      else {
        local_4c = *pdVar4;
        pdVar4 = pdVar4 + 1;
      }
      if ((param_3 < 2) || (pdVar1 <= pdVar4)) {
        iVar3 = js_dateGetDay((double)fVar6);
        local_54 = (double)iVar3;
        fVar6 = (float10)dVar8;
      }
      else {
        local_54 = *pdVar4;
        pdVar4 = pdVar4 + 1;
      }
      if ((param_3 == 0) || (pdVar1 <= pdVar4)) {
        uVar7 = js_dateGetSecond();
        local_30 = (double)(int)uVar7;
        fVar6 = (float10)dVar8;
      }
      else {
        local_30 = *pdVar4;
      }
      dVar8 = floor((double)(fVar6 / (float10)_DAT_68193470));
      fVar6 = (((float10)local_5c * (float10)60.0 + (float10)local_4c) * (float10)60.0 +
              (float10)local_54) * (float10)_DAT_68193468 + (float10)local_30 +
              (float10)dVar8 * (float10)_DAT_68193470;
      if (param_4 != 0) {
        fVar6 = js_dateGetHour((double)fVar6);
      }
      local_30 = (double)fVar6;
      if ((((*(unsigned int *)((char *)&local_30 + 4)) & 0x7ff00000) == 0x7ff00000) || ((float10)8.64e+15 < ABS(fVar6))) {
        fVar6 = (float10)**(double **)(*(int *)((int)this + 0x14) + 0x1d0);
      }
      else {
        fVar6 = runtime_powFloat(SUB84((double)(fVar6 + (float10)0.0),0),
                             (uint)((ulonglong)(double)(fVar6 + (float10)0.0) >> 0x20));
      }
      *pdVar2 = (double)fVar6;
      dVar8 = (double)fVar6;
      pdVar4 = this;
    }
LAB_68133bb9:
    runtime_convertToNumber(pdVar4,pdVar2,(int)this,SUB84(dVar8,0),(uint)((ulonglong)dVar8 >> 0x20),
                 (uint *)param_5);
    return 0;
  }
LAB_68133971:
  return 0;
}



// ============================================================
// Function: javascript_dateSetMilliseconds (FUN_68133be0)
// Address: 68133be0
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetMilliseconds(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,1,1,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCMilliseconds (FUN_68133c10)
// Address: 68133c10
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCMilliseconds(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,1,0,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetSeconds (FUN_68133c40)
// Address: 68133c40
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetSeconds(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,2,1,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCSeconds (FUN_68133c70)
// Address: 68133c70
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCSeconds(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,2,0,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetMinutes (FUN_68133ca0)
// Address: 68133ca0
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetMinutes(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,3,1,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCMinutes (FUN_68133cd0)
// Address: 68133cd0
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCMinutes(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,3,0,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetHours (FUN_68133d00)
// Address: 68133d00
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetHours(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,4,1,param_5);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCHours (FUN_68133d30)
// Address: 68133d30
// Size: 34 bytes
// Params: void * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCHours(void *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateSetComponent(param_1,param_3,param_4,4,0,param_5);
  return 0;
}



// ============================================================
// Function: js_dateCompute (FUN_68133d60)
// Address: 68133d60
// Size: 621 bytes
// Params: double * param_1, double * param_2, undefined4 param_3, uint param_4, int param_5, uint param_6, int param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall
js_dateCompute(double *param_1,double *param_2,undefined4 param_3,uint param_4,int param_5,
            uint param_6,int param_7)
{
  double dVar1;
  double *pdVar2;
  int iVar3;
  double *pdVar4;
  double *pdVar5;
  uint uVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  ulonglong uVar10;
  double local_48;
  double local_40;
  undefined8 local_2c;
  undefined8 local_20;
  double local_18 [2];
  uint local_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 == (double *)0x0) {
    return 0;
  }
  dVar1 = *pdVar2;
  if (param_4 == 0) {
    param_4 = 1;
  }
  else if (param_6 < param_4) {
    param_4 = param_6;
  }
  uVar6 = 0;
  if (param_4 != 0) {
    pdVar4 = (double *)&local_20;
    do {
      iVar3 = runtime_parseNumber((ushort *)param_1,*(uint *)(param_5 + uVar6 * 4),pdVar4);
      if (iVar3 == 0) {
        return 0;
      }
      if (((ulonglong)*pdVar4 & 0x7ff0000000000000) == 0x7ff0000000000000) {
        dVar1 = **(double **)(*(int *)((int)param_1 + 0x14) + 0x1d0);
        *pdVar2 = dVar1;
        pdVar4 = pdVar2;
        pdVar5 = param_2;
        goto LAB_68133fb5;
      }
      fVar7 = runtime_powFloat(SUB84(*pdVar4,0),(uint)((ulonglong)*pdVar4 >> 0x20));
      *pdVar4 = (double)fVar7;
      uVar6 = uVar6 + 1;
      pdVar4 = pdVar4 + 1;
    } while (uVar6 < param_4);
  }
  fVar7 = (float10)dVar1;
  (*(unsigned int *)((char *)&local_2c + 4)) = (uint)((ulonglong)dVar1 >> 0x20);
  if (((*(unsigned int *)((char *)&local_2c + 4)) & 0x7ff00000) == 0x7ff00000) {
    pdVar4 = param_2;
    pdVar5 = param_1;
    if (param_4 < 3) goto LAB_68133fb5;
    fVar7 = (float10)0;
  }
  else if (param_7 != 0) {
    js_dateToTimeValue(dVar1);
    fVar7 = (float10)_CIfmod();
    fVar7 = fVar7 + (float10)dVar1;
  }
  dVar1 = (double)fVar7;
  pdVar4 = (double *)&local_20;
  pdVar5 = local_18 + (param_4 - 1);
  if ((param_6 < 3) || (pdVar5 <= pdVar4)) {
    uVar6 = js_mathBuiltin(SUB84((double)fVar7,0),(int)((ulonglong)(double)fVar7 >> 0x20));
    local_40 = (double)(int)uVar6;
    fVar7 = (float10)dVar1;
  }
  else {
    pdVar4 = local_18;
    local_40 = local_20;
  }
  if ((param_6 < 2) || (pdVar5 <= pdVar4)) {
    uVar10 = js_mathToUint32(SUB84((double)fVar7,0),(int)((ulonglong)(double)fVar7 >> 0x20));
    local_48 = (double)(int)uVar10;
    fVar7 = (float10)dVar1;
  }
  else {
    local_48 = *pdVar4;
    pdVar4 = pdVar4 + 1;
  }
  if ((param_6 == 0) || (pdVar5 <= pdVar4)) {
    iVar3 = js_dateFromTimestamp(SUB84((double)fVar7,0),(int)((ulonglong)(double)fVar7 >> 0x20));
    dVar1 = (double)iVar3;
  }
  else {
    dVar1 = *pdVar4;
  }
  fVar8 = js_dateGetMillis(local_40,local_48,dVar1);
  fVar7 = (float10)_DAT_68193470;
  fVar9 = javascript_mathFmod();
  fVar9 = fVar9 + (float10)(double)(fVar8 * fVar7);
  if (param_7 != 0) {
    fVar9 = js_dateGetHour((double)fVar9);
  }
  local_2c = (double)fVar9;
  if ((((*(unsigned int *)((char *)&local_2c + 4)) & 0x7ff00000) == 0x7ff00000) || ((float10)8.64e+15 < ABS(fVar9))) {
    fVar7 = (float10)**(double **)(*(int *)((int)param_1 + 0x14) + 0x1d0);
  }
  else {
    fVar7 = runtime_powFloat(SUB84((double)(fVar9 + (float10)0.0),0),
                         (uint)((ulonglong)(double)(fVar9 + (float10)0.0) >> 0x20));
  }
  *pdVar2 = (double)fVar7;
  dVar1 = (double)fVar7;
  pdVar4 = param_1;
  pdVar5 = pdVar2;
LAB_68133fb5:
  runtime_convertToNumber(pdVar4,pdVar5,(int)param_1,SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20),
               (uint *)param_2);
  return 0;
}



// ============================================================
// Function: javascript_dateSetDate (FUN_68133fd0)
// Address: 68133fd0
// Size: 34 bytes
// Params: double * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetDate(double *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  int local_18;
  js_dateCompute(param_1,param_5,param_2,param_3,param_4,1,1);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCDate (FUN_68134000)
// Address: 68134000
// Size: 34 bytes
// Params: double * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCDate(double *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateCompute(param_1,param_5,param_2,param_3,param_4,1,0);
  return 0;
}



// ============================================================
// Function: javascript_dateSetMonth (FUN_68134030)
// Address: 68134030
// Size: 34 bytes
// Params: double * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetMonth(double *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateCompute(param_1,param_5,param_2,param_3,param_4,2,1);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCMonth (FUN_68134060)
// Address: 68134060
// Size: 34 bytes
// Params: double * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCMonth(double *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateCompute(param_1,param_5,param_2,param_3,param_4,2,0);
  return 0;
}



// ============================================================
// Function: javascript_dateSetFullYear (FUN_68134090)
// Address: 68134090
// Size: 34 bytes
// Params: double * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetFullYear(double *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateCompute(param_1,param_5,param_2,param_3,param_4,3,1);
  return 0;
}



// ============================================================
// Function: javascript_dateSetUTCFullYear (FUN_681340c0)
// Address: 681340c0
// Size: 34 bytes
// Params: double * param_1, undefined4 param_2, uint param_3, int param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateSetUTCFullYear(double *param_1,undefined4 param_2,uint param_3,int param_4,double *param_5)
{
  js_dateCompute(param_1,param_5,param_2,param_3,param_4,3,0);
  return 0;
}



// ============================================================
// Function: javascript_dateFormatString (FUN_681340f0)
// Address: 681340f0
// Size: 419 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, double * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
javascript_dateFormatString(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,double *param_5)

{
  double *pdVar1;
  int iVar2;
  undefined4 uVar3;
  double *pdVar4;
  double *extraout_EDX;
  double *pdVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  ulonglong uVar9;
  double dVar10;
  undefined8 local_14;
  undefined8 local_c;
  
  pdVar1 = (double *)js_getDateField(param_1);
  if (pdVar1 != (double *)0x0) {
    dVar10 = *pdVar1;
    iVar2 = runtime_parseNumber(param_1,*param_4,(double *)&local_c);
    if (iVar2 != 0) {
      if (((*(unsigned int *)((char *)&local_c + 4)) & 0x7ff00000) == 0x7ff00000) {
        fVar6 = (float10)**(double **)(*(int *)(param_1 + 10) + 0x1d0);
        pdVar4 = *(double **)(*(int *)(param_1 + 10) + 0x1d0);
        pdVar5 = param_5;
      }
      else {
        fVar6 = runtime_powFloat(SUB84(local_c,0),(*(unsigned int *)((char *)&local_c + 4)));
        (*(unsigned int *)((char *)&local_14 + 4)) = (uint)((ulonglong)dVar10 >> 0x20);
        local_c = (double)fVar6;
        if (((*(unsigned int *)((char *)&local_14 + 4)) & 0x7ff00000) == 0x7ff00000) {
          fVar7 = (float10)0;
        }
        else {
          js_dateToTimeValue(dVar10);
          fVar7 = (float10)_CIfmod();
          fVar7 = fVar7 + (float10)dVar10;
          fVar6 = (float10)local_c;
        }
        local_14 = (double)fVar7;
        if (((float10)0 < fVar6 != ((float10)0 == fVar6)) && (fVar6 <= (float10)99.0)) {
          local_c = (double)(fVar6 + (float10)1900.0);
        }
        iVar2 = js_dateFromTimestamp(SUB84((double)fVar7,0),(int)((ulonglong)(double)fVar7 >> 0x20));
        dVar10 = (double)iVar2;
        uVar9 = js_mathToUint32(SUB84(local_14,0),(int)((ulonglong)local_14 >> 0x20));
        fVar7 = js_dateGetMillis(local_c,(double)(int)uVar9,dVar10);
        fVar6 = (float10)_DAT_68193470;
        fVar8 = javascript_mathFmod();
        fVar6 = js_dateGetHour((double)(fVar8 + (float10)(double)(fVar7 * fVar6)));
        (*(unsigned int *)((char *)&local_14 + 4)) = (uint)((ulonglong)(double)fVar6 >> 0x20);
        pdVar4 = param_5;
        if ((((*(unsigned int *)((char *)&local_14 + 4)) & 0x7ff00000) == 0x7ff00000) || ((float10)8.64e+15 < ABS(fVar6))) {
          pdVar5 = *(double **)(param_1 + 10);
          fVar6 = (float10)**(double **)(pdVar5 + 0x3a);
        }
        else {
          fVar6 = runtime_powFloat(SUB84((double)(fVar6 + (float10)0.0),0),
                               (uint)((ulonglong)(double)(fVar6 + (float10)0.0) >> 0x20));
          pdVar5 = extraout_EDX;
        }
      }
      *pdVar1 = (double)fVar6;
      uVar3 = runtime_convertToNumber(pdVar4,pdVar5,(int)param_1,SUB84((double)fVar6,0),
                           (uint)((ulonglong)(double)fVar6 >> 0x20),(uint *)param_5);
      return uVar3;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_dateFormatToSource (FUN_681342a0)
// Address: 681342a0
// Size: 291 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateFormatToSource(uint param_1)
{
  double dVar1;
  double *pdVar2;
  uint *puVar3;
  uint *in_stack_00000014;
  undefined4 uVar4;
  int iVar5;
  char local_6c [100];
  uint local_8;
  
  pdVar2 = (double *)js_getDateField(param_1);
  if (pdVar2 != (double *)0x0) {
    if (((ulonglong)*pdVar2 & 0x7ff0000000000000) == 0x7ff0000000000000) {
      runtime_snprintf(local_6c,100,"Invalid Date");
    }
    else {
      dVar1 = *pdVar2;
      js_dateGetDay(dVar1);
      js_dateGetMonth(dVar1);
      js_dateGetYear(dVar1);
      uVar4 = SUB84(dVar1,0);
      iVar5 = (int)((ulonglong)dVar1 >> 0x20);
      js_mathBuiltin(uVar4,iVar5);
      js_mathToUint32(uVar4,iVar5);
      js_dateFromTimestamp(uVar4,iVar5);
      js_dateGetMinute(dVar1);
      runtime_snprintf(local_6c,100,"%s, %.2d %s %.4d %.2d:%.2d:%.2d GMT");
    }
    puVar3 = xtra_findSymbolByName(param_1,local_6c);
    if (puVar3 != (uint *)0x0) {
      *in_stack_00000014 = (uint)puVar3 | 4;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_dateToStringImpl (FUN_681343d0)
// Address: 681343d0
// Size: 459 bytes
// Params: double param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int javascript_dateToStringImpl(double param_1,int param_2)
{
  double _X;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  short sVar4;
  int *unaff_EDI;
  float10 fVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  
  uVar7 = SUB84(param_1,0);
  iVar3 = (int)((ulonglong)param_1 >> 0x20);
  uVar1 = js_mathBuiltin(uVar7,iVar3);
  sVar4 = (short)uVar1;
  if (0xffff < uVar1 + 0x8000) {
    if (param_2 == 0) {
      sVar4 = ((int)uVar1 < 1) + 0x7fff;
    }
    else if ((int)uVar1 < 0) {
      sVar4 = sVar4 + ((short)((int)(uVar1 + 1) / 0xaf0) + -1) * -0xaf0;
    }
    else {
      sVar4 = sVar4 + (short)((int)uVar1 / 0xaf0) * -0xaf0;
    }
  }
  uVar6 = js_dateGetSecond();
  *unaff_EDI = (int)uVar6 * 1000;
  iVar2 = js_dateGetDay(param_1);
  *(char *)(unaff_EDI + 1) = (char)iVar2;
  iVar2 = js_dateGetMonth(param_1);
  *(char *)((int)unaff_EDI + 5) = (char)iVar2;
  iVar2 = js_dateGetYear(param_1);
  *(char *)((int)unaff_EDI + 6) = (char)iVar2;
  iVar2 = js_dateFromTimestamp(uVar7,iVar3);
  *(char *)((int)unaff_EDI + 7) = (char)iVar2;
  uVar6 = js_mathToUint32(uVar7,iVar3);
  *(char *)(unaff_EDI + 2) = (char)uVar6;
  iVar3 = js_dateGetMinute(param_1);
  _X = param_1 / _DAT_68193470;
  *(char *)((int)unaff_EDI + 9) = (char)iVar3;
  *(short *)((int)unaff_EDI + 10) = sVar4;
  floor(_X);
  floor((double)(int)(uVar1 - 0x7b1) * 0.25);
  floor((double)(int)(uVar1 - 0x76d) / 100.0);
  floor((double)(int)(uVar1 - 0x641) / 400.0);
  uVar6 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  *(short *)(unaff_EDI + 3) = (short)uVar6;
  fVar5 = js_dateToTimeValue(param_1);
  if ((float10)0 == fVar5) {
    *(undefined1 *)((int)unaff_EDI + 0xe) = 0;
    return 0;
  }
  *(undefined1 *)((int)unaff_EDI + 0xe) = 1;
  return 0;
}



// ============================================================
// Function: js_dateSetField (FUN_681345a0)
// Address: 681345a0
// Size: 935 bytes
// Params: void * this, uint param_1, undefined4 param_2, uint param_3, int param_4
// Return: undefined
// Calling convention: __thiscall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall js_dateSetField(void *this,uint param_1,undefined4 param_2,uint param_3,int param_4)
{
  double dVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint uVar7;
  uint _C;
  float10 fVar8;
  undefined4 uVar9;
  undefined1 local_e0 [16];
  char local_d0 [100];
  char local_6c [100];
  uint local_8;
  
  if ((param_3 & 0x7ff00000) == 0x7ff00000) {
    runtime_snprintf(local_d0,100,"Invalid Date");
  }
  else {
    js_dateToTimeValue((double)CONCAT44(param_3,param_2));
    fVar8 = (float10)_CIfmod();
    dVar1 = (double)(fVar8 + (float10)(double)CONCAT44(param_3,param_2));
    js_dateToTimeValue((double)CONCAT44(param_3,param_2));
    fVar8 = (float10)_CIfmod();
    floor((double)(fVar8 / (float10)_DAT_68193480));
    strings_floatToUint64(extraout_ECX,extraout_EDX);
    javascript_dateToStringImpl((double)CONCAT44(param_3,param_2),1);
    iVar3 = javascript_formatTimeStruct(local_6c,100,"(%Z)",(int)local_e0);
    if (iVar3 != 0) {
      pcVar4 = local_6c;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      uVar5 = (int)pcVar4 - (int)(local_6c + 1);
      if ((uVar5 < 0x65) && (pcVar4 != local_6c + 1)) {
        uVar7 = 0;
        do {
          _C = (uint)(ushort)(short)local_6c[uVar7];
          if ((_C < 0x80) && (iVar3 = isalpha(_C), iVar3 == 0)) {
            isdigit(_C);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar5);
      }
    }
    uVar9 = SUB84(dVar1,0);
    iVar3 = (int)((ulonglong)dVar1 >> 0x20);
    if (param_4 == 0) {
      js_dateGetDay(dVar1);
      js_dateGetMonth(dVar1);
      js_dateGetYear(dVar1);
      js_mathBuiltin(uVar9,iVar3);
      js_dateFromTimestamp(uVar9,iVar3);
      js_mathToUint32(uVar9,iVar3);
      js_dateGetMinute(dVar1);
      runtime_snprintf(local_d0,100,"%s %s %.2d %.4d %.2d:%.2d:%.2d GMT%+.4d%s%s");
    }
    else if (param_4 == 1) {
      js_mathBuiltin(uVar9,iVar3);
      js_dateFromTimestamp(uVar9,iVar3);
      js_mathToUint32(uVar9,iVar3);
      js_dateGetMinute(dVar1);
      runtime_snprintf(local_d0,100,"%s %s %.2d %.4d");
    }
    else if (param_4 == 2) {
      js_dateGetDay(dVar1);
      js_dateGetMonth(dVar1);
      js_dateGetYear(dVar1);
      runtime_snprintf(local_d0,100,"%.2d:%.2d:%.2d GMT%+.4d%s%s");
    }
  }
  puVar6 = xtra_findSymbolByName(param_1,local_d0);
  if (puVar6 == (uint *)0x0) {
    return 0;
  }
  *(uint *)this = (uint)puVar6 | 4;
  return 0;
}



// ============================================================
// Function: javascript_dateParse (FUN_68134950)
// Address: 68134950
// Size: 56 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateParse(uint param_1)
{
  undefined8 *puVar1;
  void *in_stack_00000014;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  js_dateSetField(in_stack_00000014,param_1,(int)*puVar1,(uint)((ulonglong)*puVar1 >> 0x20),2);
  return 0;
}



// ============================================================
// Function: javascript_dateNow (FUN_68134990)
// Address: 68134990
// Size: 56 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateNow(uint param_1)
{
  undefined8 *puVar1;
  void *in_stack_00000014;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  js_dateSetField(in_stack_00000014,param_1,(int)*puVar1,(uint)((ulonglong)*puVar1 >> 0x20),1);
  return 0;
}



// ============================================================
// Function: javascript_dateUTC (FUN_681349d0)
// Address: 681349d0
// Size: 205 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateUTC(uint param_1)
{
  char cVar1;
  undefined8 *puVar2;
  char *pcVar3;
  char *pcVar4;
  uint *puVar5;
  uint *in_stack_00000014;
  undefined1 local_24 [28];
  uint local_8;
  
  puVar2 = (undefined8 *)js_getDateField(param_1);
  if (puVar2 != (undefined8 *)0x0) {
    pcVar3 = javascript_numberToExponential((int)local_24,0x1a,(char *)0x0,(char *)0x0,(int)*puVar2,
                          (uint)((ulonglong)*puVar2 >> 0x20));
    if (pcVar3 != (char *)0x0) {
      pcVar3 = (char *)runtime_strlen("(new %s(%s))");
      if (pcVar3 != (char *)0x0) {
        pcVar4 = pcVar3;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        puVar5 = xtra_getScriptContextEx(param_1,(int)pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
        if (puVar5 == (uint *)0x0) {
          js_freeHandle();
          return 0;
        }
        *in_stack_00000014 = (uint)puVar5 | 4;
        return 0;
      }
    }
    xtra_reportError(param_1);
  }
  return 0;
}



// ============================================================
// Function: javascript_dateToGMTStringAlias (FUN_68134aa0)
// Address: 68134aa0
// Size: 56 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateToGMTStringAlias(uint param_1)
{
  undefined8 *puVar1;
  void *in_stack_00000014;
  
  puVar1 = (undefined8 *)js_getDateField(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  js_dateSetField(in_stack_00000014,param_1,(int)*puVar1,(uint)((ulonglong)*puVar1 >> 0x20),0);
  return 0;
}



// ============================================================
// Function: javascript_dateMark (FUN_68134ae0)
// Address: 68134ae0
// Size: 144 bytes
// Params: uint param_1, undefined4 param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_dateMark(uint param_1,undefined4 param_2,int param_3,uint *param_4)
{
  uint *puVar1;
  int iVar2;
  
  if (param_3 == 0) {
    javascript_dateToString(param_1);
    return 0;
  }
  if (param_3 == 1) {
    puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    iVar2 = certs_compareStrings(puVar1,(uint *)(*(uint *)(*(int *)(*(int *)(param_1 + 0x14) + 0x8c) + 8) &
                                        0xfffffff8));
    if (iVar2 == 0) {
      javascript_dateToString(param_1);
      return 0;
    }
  }
  javascript_dateToGMTStringAlias(param_1);
  return 0;
}



// ============================================================
// Function: js_dateGetTimezone (FUN_68134b70)
// Address: 68134b70
// Size: 43 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_dateGetTimezone(int param_1)
{
  int in_EAX;
  uint uVar1;
  
  uVar1 = runtime_storeFloat(in_EAX,0);
  if (uVar1 == 0) {
    return 0;
  }
  *(uint *)(*(int *)(param_1 + 4) + 0xc) = uVar1 | 2;
  return 0;
}



// ============================================================
// Function: javascript_initDateClass (FUN_68134ba0)
// Address: 68134ba0
// Size: 782 bytes
// Params: ushort * param_1, int param_2, uint param_3, uint * param_4, void * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int javascript_initDateClass(ushort *param_1,int param_2,uint param_3,uint *param_4,void *param_5)
{
  double dVar1;
  double *pdVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  float10 fVar6;
  undefined8 uVar7;
  int local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined8 local_48;
  double local_40 [7];
  uint local_8;
  
  local_48 = (double)CONCAT44(param_4,(undefined4)local_48);
  if ((*(byte *)(*(int *)(param_1 + 0x1a) + 0x4c) & 1) == 0) {
    uVar7 = js_gcMarkRoots();
    local_48 = (double)__alldiv((uint)uVar7,(uint)((ulonglong)uVar7 >> 0x20),1000,0);
    js_dateSetField(param_5,(uint)param_1,SUB84((double)(longlong)local_48,0),
                 (uint)((ulonglong)(double)(longlong)local_48 >> 0x20),0);
    return 0;
  }
  if (param_3 == 0) {
    pdVar2 = (double *)js_dateGetTimezone(param_2);
    if (pdVar2 == (double *)0x0) goto LAB_68134c1f;
    uVar7 = js_gcMarkRoots();
    local_48 = (double)__alldiv((uint)uVar7,(uint)((ulonglong)uVar7 >> 0x20),1000,0);
    *pdVar2 = (double)(longlong)local_48;
    goto LAB_68134e96;
  }
  if (param_3 == 1) {
    if (((byte)*param_4 & 7) == 4) {
      pdVar2 = (double *)js_dateGetTimezone(param_2);
      if (pdVar2 == (double *)0x0) {
LAB_68134c1f:
        return 0;
      }
      /* FIXUP(C2100): uVar4 = certs_hashLookup((int)param_1,*(*(unsigned int *)((char *)&local_48 + 4))); */
      if (uVar4 == 0) goto LAB_68134c1f;
      iVar3 = javascript_parseDateString(pdVar2);
      if (iVar3 == 0) {
        *pdVar2 = **(double **)(*(int *)(param_1 + 10) + 0x1d0);
      }
      if (((ulonglong)*pdVar2 & 0x7ff0000000000000) != 0x7ff0000000000000) {
        dVar1 = *pdVar2;
        if (*pdVar2 < 0.0) {
          dVar1 = -dVar1;
        }
        if (dVar1 <= 8.64e+15) {
          fVar6 = runtime_powFloat(SUB84(*pdVar2 + 0.0,0),(uint)((ulonglong)(*pdVar2 + 0.0) >> 0x20));
          goto LAB_68134e94;
        }
      }
      fVar6 = (float10)**(double **)(*(int *)(param_1 + 10) + 0x1d0);
    }
    else {
      iVar3 = runtime_parseNumber(param_1,*param_4,(double *)&local_50);
      if ((iVar3 == 0) || (pdVar2 = (double *)js_dateGetTimezone(param_2), pdVar2 == (double *)0x0))
      goto LAB_68134c1f;
      if (((uStack_4c & 0x7ff00000) != 0x7ff00000) &&
         (fVar6 = (float10)(double)CONCAT44(uStack_4c,local_50), ABS(fVar6) <= (float10)8.64e+15))
      goto LAB_68134e55;
      fVar6 = (float10)**(double **)(*(int *)(param_1 + 10) + 0x1d0);
    }
  }
  else {
    uVar4 = 0;
    do {
      if (uVar4 < param_3) {
        iVar3 = runtime_parseNumber(param_1,param_4[uVar4],(double *)&local_58);
        if (iVar3 == 0) goto LAB_68134c1f;
        if ((uStack_54 & 0x7ff00000) == 0x7ff00000) {
          puVar5 = (undefined8 *)js_dateGetTimezone(param_2);
          if (puVar5 == (undefined8 *)0x0) goto LAB_68134c1f;
          *puVar5 = **(undefined8 **)(*(int *)(param_1 + 10) + 0x1d0);
          goto LAB_68134e96;
        }
        fVar6 = runtime_powFloat(local_58,uStack_54);
        param_4 = (*(unsigned int *)((char *)&local_48 + 4));
LAB_68134da5:
        local_40[uVar4] = (double)fVar6;
      }
      else {
        if (uVar4 != 2) {
          fVar6 = (float10)0;
          goto LAB_68134da5;
        }
        local_40[2] = 1.0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 7);
    pdVar2 = (double *)js_dateGetTimezone(param_2);
    if (pdVar2 == (double *)0x0) goto LAB_68134c1f;
    if ((0.0 <= local_40[0]) && (local_40[0] <= 99.0)) {
      local_40[0] = local_40[0] + 1900.0;
    }
    fVar6 = js_dateGetMillis(local_40[0],local_40[1],local_40[2]);
    fVar6 = js_dateGetHour((double)((((float10)local_40[3] * (float10)60.0 + (float10)local_40[4]) *
                                   (float10)60.0 + (float10)local_40[5]) * (float10)_DAT_68193468 +
                                  (float10)local_40[6] + fVar6 * (float10)_DAT_68193470));
    dVar1 = (double)fVar6;
    (*(unsigned int *)((char *)&local_48 + 4)) = (uint *)((ulonglong)dVar1 >> 0x20);
    local_48 = dVar1;
    if ((((uint)(*(unsigned int *)((char *)&local_48 + 4)) & 0x7ff00000) == 0x7ff00000) || ((float10)8.64e+15 < ABS(fVar6))) {
      fVar6 = (float10)**(double **)(*(int *)(param_1 + 10) + 0x1d0);
    }
    else {
LAB_68134e55:
      fVar6 = runtime_powFloat(SUB84((double)(fVar6 + (float10)0.0),0),
                           (uint)((ulonglong)(double)(fVar6 + (float10)0.0) >> 0x20));
    }
  }
LAB_68134e94:
  *pdVar2 = (double)fVar6;
LAB_68134e96:
  return 0;
}



// ============================================================
// Function: javascript_createDateObject (FUN_68134eb0)
// Address: 68134eb0
// Size: 144 bytes
// Params: uint param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * javascript_createDateObject(uint param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined8 *puVar4;
  
  iVar2 = javascript_computeEpochOffset();
  _DAT_68196980 = -((double)iVar2 * _DAT_68193468);
  piVar3 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_DAT_68193548,0x68134ba0,7,(int *)0x0,
                        (int *)&PTR_s_getTime_68193720,(int *)0x0,(int *)&PTR_DAT_681936ec);
  if (piVar3 != (int *)0x0) {
    bVar1 = xtra_matchMethodName(param_1,piVar3,"toUTCString","toGMTString");
    if (CONCAT31(extraout_var,bVar1) != 0) {
      puVar4 = (undefined8 *)js_dateGetTimezone((int)piVar3);
      if (puVar4 != (undefined8 *)0x0) {
        *puVar4 = **(undefined8 **)(*(int *)(param_1 + 0x14) + 0x1d0);
        return piVar3;
      }
    }
  }
  return (int *)0x0;
}



// ============================================================
// Function: javascript_dateGetTimezoneOffset (FUN_68134f40)
// Address: 68134f40
// Size: 109 bytes
// Params: undefined4 param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_dateGetTimezoneOffset(undefined4 param_1)

{
  double *pdVar1;
  uint uVar2;
  float10 fVar3;
  
  pdVar1 = (double *)js_getDateField(param_1);
  if ((pdVar1 != (double *)0x0) &&
     ((((ulonglong)*pdVar1 & 0x7ff0000000000000) != 0x7ff0000000000000 ||
      ((*(int *)pdVar1 == 0 && (((ulonglong)*pdVar1 & 0xfffff00000000) == 0)))))) {
    js_dateToTimeValue(*pdVar1);
    fVar3 = (float10)_CIfmod();
    uVar2 = js_mathBuiltin(SUB84((double)(fVar3 + (float10)*pdVar1),0),
                         (int)((ulonglong)(double)(fVar3 + (float10)*pdVar1) >> 0x20));
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: javascript_dateGetFieldGeneric (FUN_68134fb0)
// Address: 68134fb0
// Size: 364 bytes
// Params: uint * param_1, char * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_dateGetFieldGeneric(uint *param_1,char *param_2)
{
  double *pdVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint unaff_EBX;
  float10 fVar5;
  undefined1 local_7c [13];
  char acStack_6f [103];
  uint local_8;
  
  pdVar1 = (double *)js_getDateField(unaff_EBX);
  if (pdVar1 == (double *)0x0) {
    return 0;
  }
  if (((ulonglong)*pdVar1 & 0x7ff0000000000000) == 0x7ff0000000000000) {
    runtime_snprintf(acStack_6f + 3,100,"Invalid Date");
  }
  else {
    js_dateToTimeValue(*pdVar1);
    fVar5 = (float10)_CIfmod();
    javascript_dateToStringImpl((double)(fVar5 + (float10)*pdVar1),0);
    iVar2 = javascript_formatTimeStruct(acStack_6f + 3,100,param_2,(int)local_7c);
    if (iVar2 == 0) {
      js_dateSetField(param_1,unaff_EBX,SUB84(*pdVar1,0),(uint)((ulonglong)*pdVar1 >> 0x20),0);
      return 0;
    }
    if (acStack_6f[iVar2] == '/') {
      iVar3 = isdigit((int)acStack_6f[iVar2 + 1]);
      if (iVar3 != 0) {
        iVar3 = isdigit((int)acStack_6f[iVar2 + 2]);
        if (iVar3 != 0) {
          javascript_dateGetTimezoneOffset(unaff_EBX);
          runtime_snprintf(acStack_6f + iVar2 + 1,0x66 - iVar2,"%d");
        }
      }
    }
  }
  puVar4 = xtra_findSymbolByName(unaff_EBX,acStack_6f + 3);
  if (puVar4 == (uint *)0x0) {
    return 0;
  }
  *param_1 = (uint)puVar4 | 4;
  return 0;
}



// ============================================================
// Function: javascript_booleanToString (FUN_68135120)
// Address: 68135120
// Size: 33 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_booleanToString(void)
{
  uint *in_stack_00000014;
  
  javascript_dateGetFieldGeneric(in_stack_00000014,"%#c");
  return 0;
}



// ============================================================
// Function: javascript_booleanToSource (FUN_68135150)
// Address: 68135150
// Size: 33 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_booleanToSource(void)
{
  uint *in_stack_00000014;
  
  javascript_dateGetFieldGeneric(in_stack_00000014,"%#x");
  return 0;
}



// ============================================================
// Function: javascript_booleanValueOf (FUN_68135180)
// Address: 68135180
// Size: 33 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_booleanValueOf(void)
{
  uint *in_stack_00000014;
  
  javascript_dateGetFieldGeneric(in_stack_00000014,"%X");
  return 0;
}



// ============================================================
// Function: javascript_booleanConstructor (FUN_681351b0)
// Address: 681351b0
// Size: 211 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_booleanConstructor(uint *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  uint *puVar2;
  char local_28 [32];
  uint local_8;
  
  iVar1 = xtra_callMethod(param_1,(int)param_2,&PTR_s_Boolean_68193940,(int)param_4);
  if (iVar1 != 0) {
    if (((byte)*(undefined4 *)(param_2[1] + 0xc) & 7) != 6) {
      runtime_setPropertyVtable(param_1,param_2,param_3,param_4,param_5);
      return 0;
    }
    runtime_snprintf(local_28,0x20,"(new %s(%s))");
    puVar2 = xtra_findSymbolByName((uint)param_1,local_28);
    if (puVar2 != (uint *)0x0) {
      *param_5 = (uint)puVar2 | 4;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_initBooleanClass (FUN_68135290)
// Address: 68135290
// Size: 127 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_initBooleanClass(uint *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = xtra_callMethod(param_1,(int)param_2,&PTR_s_Boolean_68193940,(int)param_4);
  if (iVar1 != 0) {
    if (((byte)*(uint *)(param_2[1] + 0xc) & 7) != 6) {
      iVar1 = runtime_setPropertyVtableEx(param_1,param_2,param_3,param_4,param_5);
      return iVar1;
    }
    uVar2 = *(uint *)(*(int *)(param_1[5] + 0x94 +
                              (uint)((*(uint *)(param_2[1] + 0xc) & 0xfffffff8) != 0) * 4) + 8) &
            0xfffffff8;
    if (uVar2 != 0) {
      *param_5 = uVar2 | 4;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_createBooleanObject (FUN_68135310)
// Address: 68135310
// Size: 56 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_createBooleanObject(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = xtra_callMethod(param_1,param_2,&PTR_s_Boolean_68193940,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  *param_5 = *(undefined4 *)(*(int *)(param_2 + 4) + 0xc);
  return 1;
}



// ============================================================
// Function: javascript_numberGetDefaultValue (FUN_68135350)
// Address: 68135350
// Size: 52 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_numberGetDefaultValue(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = runtime_setProperty(param_1,&PTR_s_Boolean_68193940,(undefined4 *)0x0,0);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  *(uint *)(piVar1[1] + 0xc) = param_2 * 8 | 6;
  return 0;
}



// ============================================================
// Function: javascript_initNumberClass (FUN_68135390)
// Address: 68135390
// Size: 34 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_initNumberClass(int param_1,int param_2)

{
  return *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + 0x94 + (uint)(param_2 != 0) * 4) + 8) &
         0xfffffff8;
}



// ============================================================
// Function: js_getDateComponent (FUN_681353c0)
// Address: 681353c0
// Size: 338 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_getDateComponent(int param_1,uint param_2,uint *param_3)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  int local_c;
  uint uStack_8;
  
  if ((param_2 == 0) || (param_2 == 0x80000001)) {
    *param_3 = 0;
    return 1;
  }
  uVar3 = param_2 & 7;
  if (uVar3 == 0) {
    if ((*(int *)(param_1 + 0xc) == 0) || (0x81 < *(int *)(param_1 + 0xc))) {
LAB_681354da:
      *param_3 = 1;
      return 1;
    }
    iVar2 = (**(code **)(*(int *)(*(int *)(param_2 & 0xfffffff8) + 4) + 0x24))
                      (param_1,(int *)(param_2 & 0xfffffff8),5,&param_2);
    if (iVar2 == 0) {
      return 0;
    }
    if (((byte)param_2 & 7) != 6) {
      param_2 = 0xe;
    }
  }
  else {
    if (uVar3 == 4) {
      uVar3 = *(uint *)(param_2 & 0xfffffff8);
      if ((uVar3 & 0x40000000) != 0) {
        uVar3 = (-(uint)((uVar3 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar3;
      }
      *param_3 = (uint)(uVar3 != 0);
      return 1;
    }
    if ((param_2 & 1) != 0) {
      *param_3 = (uint)((param_2 & 0xfffffffe) != 0);
      return 1;
    }
    if (uVar3 == 2) {
      dVar1 = *(double *)(param_2 & 0xfffffff8);
      uStack_8 = (uint)((ulonglong)dVar1 >> 0x20);
      if ((((uStack_8 & 0x7ff00000) == 0x7ff00000) &&
          ((local_c = SUB84(dVar1,0), local_c != 0 || (((ulonglong)dVar1 & 0xfffff00000000) != 0))))
         || (dVar1 == 0.0)) {
        *param_3 = 0;
        return 1;
      }
      goto LAB_681354da;
    }
  }
  *param_3 = (int)param_2 >> 3;
  return 1;
}



// ============================================================
// Function: javascript_createNumberObject (FUN_68135520)
// Address: 68135520
// Size: 100 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_createNumberObject(int param_1,int param_2,uint param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    uVar2 = 6;
  }
  else {
    iVar1 = js_getDateComponent(param_1,*param_4,&param_3);
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = param_3 * 8 | 6;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x34) + 0x4c) & 1) == 0) {
    *param_5 = uVar2;
    return 1;
  }
  *(uint *)(*(int *)(param_2 + 4) + 0xc) = uVar2;
  return 1;
}



// ============================================================
// Function: javascript_numberToString (FUN_68135590)
// Address: 68135590
// Size: 63 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_numberToString(int param_1,int *param_2)
{
  int *piVar1;
  
  piVar1 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_Boolean_68193940,0x68135520,1,
                        (int *)0x0,(int *)&PTR_s_toSource_68193988,(int *)0x0,(int *)0x0);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  *(undefined4 *)(piVar1[1] + 0xc) = 6;
  return 0;
}



// ============================================================
// Function: javascript_numberParseInt (FUN_681355d0)
// Address: 681355d0
// Size: 469 bytes
// Params: uint param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_numberParseInt(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint local_2c;
  ushort *local_28;
  uint local_24;
  ushort *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  ushort *local_8;
  
  if (((param_1 & 1) == 0) || (param_1 == 0x80000001)) {
    puVar3 = (uint *)(param_1 & 0xfffffff8);
    if ((*puVar3 & 0x40000000) == 0) {
      local_28 = (ushort *)puVar3[1];
    }
    else {
      if ((*(uint *)puVar3[1] & 0x40000000) == 0) {
        if ((*puVar3 & 0x80000000) == 0) {
          local_24 = *puVar3 >> 0xf & 0x7fff;
        }
        else {
          local_24 = 0;
        }
        local_20 = (ushort *)(*(int *)(puVar3[1] + 4) + local_24 * 2);
      }
      else {
        local_20 = (ushort *)crypto_getStringLen(puVar3);
      }
      local_28 = local_20;
    }
    if ((*local_28 < 0x80) && (iVar2 = isdigit((uint)*local_28), iVar2 != 0)) {
      if ((*puVar3 & 0x40000000) == 0) {
        local_2c = *puVar3;
      }
      else {
        local_2c = (-(uint)((*puVar3 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar3;
      }
      if (local_2c < 0xb) {
        local_14 = *local_28 - 0x30;
        local_8 = local_28 + 1;
        local_18 = 0;
        local_1c = 0;
        if (local_14 != 0) {
          while ((*local_8 < 0x80 && (iVar2 = isdigit((uint)*local_8), iVar2 != 0))) {
            local_18 = local_14;
            local_1c = *local_8 - 0x30;
            local_14 = local_14 * 10 + local_1c;
            local_8 = local_8 + 1;
          }
        }
        if ((*local_8 == 0) &&
           ((local_18 < 0x19999999 || ((local_18 == 0x19999999 && (local_1c < 5)))))) {
          *param_2 = local_14;
          return 1;
        }
      }
    }
    uVar1 = 0;
  }
  else if ((int)param_1 >> 1 < 0) {
    uVar1 = 0;
  }
  else {
    *param_2 = (int)param_1 >> 1;
    uVar1 = 1;
  }
  return uVar1;
}



