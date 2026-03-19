// Module: lingo
// Topic: Text field and chunk expression operations
// Address range: 0x68097B00 - 0x68098460
// Functions (16):
//   Ordinal_601
//   Ordinal_602
//   Ordinal_610
//   lingo_setTextField
//   Ordinal_611
//   Ordinal_612
//   Ordinal_604
//   Ordinal_605
//   Ordinal_606
//   lingo_getTextFieldData
//   Ordinal_608
//   Ordinal_609
//   Ordinal_603
//   Ordinal_607
//   lingo_getTextFieldState
//   lingo_markFieldDirty


// ============================================================
// Function: Ordinal_601
// Address: 68097b00
// Size: 216 bytes
// Params: int param_1, int param_2, undefined2 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_601(int param_1,int param_2,undefined2 *param_3,undefined4 *param_4,undefined4 *param_5
                )
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97b00  601   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (*(int *)(*(int *)(iVar3 + 0x20) + 0x51c) == 0) {
    bitmap_initStyleRunBuffers(*(int *)(iVar3 + 0x20));
  }
  uVar2 = *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x51c);
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar2;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x520);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(*(int *)(iVar3 + 0x20) + 0x524);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_5,uVar2);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_602
// Address: 68097be0
// Size: 190 bytes
// Params: int param_1, int param_2, short param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_602(int param_1,int param_2,short param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97be0  602   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (param_3 == 0) {
    bitmap_getTextFieldRef(*(int *)(iVar2 + 0x20));
  }
  else {
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x51c) = param_4;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x520) = param_5;
    *(short *)(*(int *)(iVar2 + 0x20) + 0x524) = param_3;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x458) = 1;
  rendering_getChannelProperty(iVar2,0x10,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_610
// Address: 68097ca0
// Size: 126 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_610(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x97ca0  610   */
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_setTextField (FUN_68097d20)
// Address: 68097d20
// Size: 23 bytes
// Params: undefined4 param_1, short param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall lingo_setTextField(undefined4 param_1,short param_2,int param_3,int param_4)
{
  undefined4 in_EAX;
  
  Ordinal_602(param_3,param_4,param_2,param_1,in_EAX);
  return 0;
}



// ============================================================
// Function: Ordinal_611
// Address: 68097d40
// Size: 91 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_611(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
                    /* 0x97d40  611   */
  local_8 = 0;
  Ordinal_601(param_1,param_2,(undefined2 *)&local_8,&param_2,&param_1);
  iVar3 = param_3;
  iVar2 = param_2;
  if ((0 < param_3) && (param_3 <= (short)local_8)) {
    iVar4 = Ordinal_1114(param_2);
    sVar1 = *(short *)(iVar4 + -4 + iVar3 * 4);
    Ordinal_1115(iVar2);
    return (int)sVar1;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_612
// Address: 68097da0
// Size: 85 bytes
// Params: int param_1, int param_2, int param_3, undefined2 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_612(int param_1,int param_2,int param_3,undefined2 param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
                    /* 0x97da0  612   */
  local_8 = 0;
  Ordinal_601(param_1,param_2,(undefined2 *)&local_8,&param_2,&param_1);
  iVar2 = param_3;
  iVar1 = param_2;
  if ((0 < param_3) && (param_3 <= (short)local_8)) {
    iVar3 = Ordinal_1114(param_2);
    *(undefined2 *)(iVar3 + -4 + iVar2 * 4) = param_4;
    Ordinal_1115(iVar1);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_604
// Address: 68097e00
// Size: 174 bytes
// Params: int param_1, int param_2, int param_3, undefined1 * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_604(int param_1,int param_2,int param_3,undefined1 *param_4,int param_5)
{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
                    /* 0x97e00  604   */
  Ordinal_601(param_1,param_2,(undefined2 *)&param_2,&param_1,&local_8);
  iVar4 = param_3;
  iVar3 = param_1;
  if ((0 < param_3) && (param_3 <= (short)param_2)) {
    iVar2 = Ordinal_1114(param_1);
    iVar5 = (int)*(short *)(iVar2 + -2 + iVar4 * 4);
    iVar4 = *(short *)(iVar2 + 2 + iVar4 * 4) - iVar5;
    Ordinal_1115(iVar3);
    if (param_5 + -1 < iVar4) {
      iVar4 = param_5 + -1;
    }
    if ((-1 < iVar5) && (-1 < iVar4)) {
      iVar3 = Ordinal_1116(local_8);
      if (iVar4 + iVar5 <= iVar3) {
        iVar3 = Ordinal_1114(local_8);
        puVar1 = param_4;
        Ordinal_1128(param_4,iVar3 + iVar5,iVar4);
        Ordinal_1115(local_8);
        puVar1[iVar4] = 0;
        return 0;
      }
    }
    *param_4 = 0;
    return 0;
  }
  *param_4 = 0;
  return 0;
}



// ============================================================
// Function: Ordinal_605
// Address: 68097eb0
// Size: 75 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_605(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 local_8;
  
                    /* 0x97eb0  605   */
  Ordinal_601((int)param_1,param_2,(undefined2 *)&param_2,&param_1,&local_8);
  iVar3 = (int)(short)param_2;
  iVar1 = 0;
  if (0 < iVar3) {
    psVar2 = (short *)*param_1;
    do {
      iVar1 = iVar1 + 1;
      if (param_3 <= *psVar2) {
        return iVar1;
      }
      psVar2 = psVar2 + 2;
    } while (iVar1 < iVar3);
  }
  return iVar3 + 1;
}



// ============================================================
// Function: Ordinal_606
// Address: 68097f00
// Size: 168 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_606(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_8;
  
                    /* 0x97f00  606   */
  iVar6 = -1;
  Ordinal_601(param_1,param_2,(undefined2 *)&param_2,&local_8,&param_1);
  sVar1 = (short)param_2;
  if ((short)param_2 != 0) {
    iVar3 = Ordinal_1114(local_8);
    param_2 = Ordinal_1114(param_1);
    iVar2 = param_4;
    iVar4 = sVar1 + -1;
    if (-1 < iVar4) {
      while (iVar5 = (int)*(short *)(iVar3 + iVar4 * 4), iVar5 != param_3) {
        if ((iVar5 < param_3) || (iVar4 = iVar4 + -1, iVar4 < 0)) goto LAB_68097f8b;
      }
      iVar5 = (int)*(short *)(iVar3 + 2 + iVar4 * 4);
      iVar6 = *(short *)(iVar3 + 6 + iVar4 * 4) - iVar5;
      if (param_4 != 0) {
        if (param_5 + -1 < iVar6) {
          iVar6 = param_5 + -1;
        }
        Ordinal_1128(param_4,iVar5 + param_2,iVar6);
        *(undefined1 *)(iVar6 + iVar2) = 0;
      }
    }
LAB_68097f8b:
    Ordinal_1115(param_1);
    Ordinal_1115(local_8);
  }
  return iVar6;
}



// ============================================================
// Function: lingo_getTextFieldData (FUN_68097fb0)
// Address: 68097fb0
// Size: 119 bytes
// Params: int param_1, int param_2, int param_3, short param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getTextFieldData(int param_1,int param_2,int param_3,short param_4)
{
  short *psVar1;
  int iVar2;
  undefined4 local_10;
  int *local_c;
  short local_8 [2];
  
  Ordinal_601(param_1,param_2,local_8,&local_c,&local_10);
  iVar2 = 0;
  if (0 < local_8[0]) {
    do {
      psVar1 = (short *)(*local_c + iVar2 * 4);
      if (param_3 <= *(short *)(*local_c + iVar2 * 4)) {
        *psVar1 = *psVar1 + param_4;
        if (*(short *)(*local_c + iVar2 * 4) < param_3) {
          *(short *)(*local_c + iVar2 * 4) = (short)param_3;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_8[0]);
  }
  lingo_setTextField(local_c,local_8[0],param_1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_608
// Address: 68098030
// Size: 246 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_608(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  short *psVar1;
  short sVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  short local_10 [2];
  int *local_c;
  int local_8;
  
                    /* 0x98030  608   */
  Ordinal_601(param_1,param_2,local_10,&local_c,&local_8);
  piVar4 = local_c;
  if ((((local_c != (int *)0x0) && (local_8 != 0)) && (0 < param_3)) &&
     ((param_3 <= local_10[0] && (iVar5 = Ordinal_1116(local_8), iVar5 < 0x7d01)))) {
    sVar2 = *(short *)(*piVar4 + 2 + param_3 * 4);
    sVar3 = *(short *)(*piVar4 + param_3 * 4 + -2);
    if (0xff < param_5) {
      iVar5 = Ordinal_1285(param_4,0x100);
      if (iVar5 - param_4 <= param_5) {
        param_5 = iVar5 - param_4;
      }
    }
    Ordinal_1123(&local_8,(int)sVar3,0,(int)sVar2 - (int)sVar3,param_4,param_5);
    if (DAT_68195a8c == 0) {
      while (param_3 = param_3 + 1, param_3 <= local_10[0] + 1) {
        psVar1 = (short *)(*local_c + -2 + param_3 * 4);
        *psVar1 = *psVar1 + (sVar3 - sVar2) + (short)param_5;
      }
      lingo_setTextField(local_c,local_10[0],param_1,param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: Ordinal_609
// Address: 68098130
// Size: 226 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_609(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short local_10 [2];
  int *local_c;
  int local_8;
  
                    /* 0x98130  609   */
  Ordinal_601((int)param_1,param_2,local_10,&local_c,&local_8);
  if ((local_c != (int *)0x0) && (local_8 != 0)) {
    iVar2 = Ordinal_605(param_1,param_2,param_3);
    if ((local_10[0] < iVar2) || (*(short *)(*local_c + -4 + iVar2 * 4) != param_3)) {
      sVar4 = local_10[0] + 1;
      cast_resizeHandle((uint)local_c,sVar4 * 4 + 4,0);
      if (DAT_68195a8c != 0) {
        return -1;
      }
      DAT_68195a8c = 0;
      for (iVar3 = (int)sVar4; iVar2 <= iVar3; iVar3 = iVar3 + -1) {
        puVar1 = (undefined4 *)(*local_c + iVar3 * 4);
        *puVar1 = puVar1[-1];
      }
      *(undefined2 *)(*local_c + -4 + iVar2 * 4) = (undefined2)param_3;
      *(undefined2 *)(*local_c + iVar2 * 4 + -2) = *(undefined2 *)(*local_c + 2 + iVar2 * 4);
      lingo_setTextField(local_c,sVar4,(int)param_1,param_2);
    }
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_603
// Address: 68098220
// Size: 237 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_603(int param_1,int param_2,int param_3)
{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_418;
  int local_414;
  undefined4 local_410;
  short local_40c [2];
  undefined1 local_408 [1024];
  uint local_8;
  
                    /* 0x98220  603   */
  local_414 = param_3;
  if (param_3 != 0) {
    Ordinal_601(param_1,param_2,local_40c,&local_410,&local_418);
    iVar3 = 1;
    if (0 < local_40c[0]) {
      do {
        Ordinal_604(param_1,param_2,iVar3,local_408,0x3fe);
        puVar1 = (undefined1 *)Ordinal_1205(local_408,0xd);
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = 0;
        }
        iVar2 = Ordinal_1255(local_408,local_414);
        if (iVar2 == 0) {
          Ordinal_1114(local_410);
          Ordinal_1115(local_410);
          return 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= local_40c[0]);
    }
  }
  return 0;
}



// ============================================================
// Function: Ordinal_607
// Address: 68098310
// Size: 270 bytes
// Params: undefined4 * param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_607(undefined4 *param_1,int *param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int local_10;
  undefined4 ***local_c;
  undefined4 local_8;
  
                    /* 0x98310  607   */
  piVar1 = param_2;
  Ordinal_601((int)param_1,(int)param_2,(undefined2 *)&local_8,&param_2,&local_10);
  if (((param_2 != (int *)0x0) && (local_10 != 0)) && (param_3 <= param_4)) {
    iVar2 = Ordinal_605(param_1,(int)piVar1,param_3);
    if (iVar2 <= (short)local_8) {
      iVar3 = Ordinal_605(param_1,(int)piVar1,param_4);
      if (((short)local_8 < iVar3) || (*(short *)(*param_2 + -4 + iVar3 * 4) != param_4)) {
        iVar3 = iVar3 + -1;
      }
      param_4 = (iVar3 - iVar2) + 1;
      if (param_4 != 0) {
        local_c = &local_c;
        for (; iVar2 <= iVar3; iVar2 = iVar2 + 1) {
          Ordinal_608((int)param_1,(int)piVar1,iVar2,(int)local_c,0);
        }
        iVar3 = iVar3 + 1;
        if (iVar3 <= (short)local_8 + 1) {
          iVar2 = (iVar3 - param_4) * 4;
          do {
            *(undefined4 *)(iVar2 + -4 + *param_2) = *(undefined4 *)(*param_2 + -4 + iVar3 * 4);
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 4;
          } while (iVar3 <= (short)local_8 + 1);
        }
        sVar4 = (short)local_8 - (short)param_4;
        cast_resizeHandle((uint)param_2,sVar4 * 4 + 4,0);
        lingo_setTextField(param_2,sVar4,(int)param_1,(int)piVar1);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_getTextFieldState (FUN_68098420)
// Address: 68098420
// Size: 53 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getTextFieldState(void)
{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = media_getScoreState(unaff_ESI);
  if ((unaff_EDI < iVar1) || (unaff_EDI == 0)) {
    media_getPlaybackPosition((int)unaff_ESI);
    media_getScoreHandle(unaff_ESI);
  }
  iVar1 = media_getScoreState(unaff_ESI);
  while (iVar1 < unaff_EDI) {
    media_stepPlaybackLocked((int)unaff_ESI);
    iVar1 = media_getScoreState(unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: lingo_markFieldDirty (FUN_68098460)
// Address: 68098460
// Size: 24 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_markFieldDirty(void)
{
  int *in_EAX;
  int iVar1;
  
  iVar1 = media_getScoreContext(in_EAX);
  if (iVar1 != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x458) = 1;
  }
  return 0;
}


