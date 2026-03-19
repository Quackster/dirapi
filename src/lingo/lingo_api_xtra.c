// Module: lingo
// Topic: Xtra interface callbacks and dispatch
// Address range: 0x6809D210 - 0x6809E570
// Functions (57):
//   lingo_cmdCount
//   lingo_cmdGetAt
//   lingo_cmdSetAt
//   lingo_cmdDeleteAt
//   lingo_cmdAddProp
//   lingo_cmdFindPos
//   lingo_cmdWriteString
//   lingo_cmdReadString
//   lingo_cmdGetProp
//   lingo_cmdSetProp
//   lingo_cmdGetPixel
//   lingo_cmdSetPixel
//   lingo_cmdGetRect
//   lingo_cmdSetRect
//   lingo_cmdDuplicate
//   lingo_cmdCopyPixels
//   lingo_cmdDraw
//   lingo_cmdFill
//   lingo_cmdSetAlpha
//   lingo_cmdGetAlpha
//   lingo_cmdCreateMask
//   lingo_cmdCreateMatte
//   lingo_cmdTrimWhitespace
//   lingo_cmdExtract
//   lingo_cmdFilter
//   lingo_cmdRotate
//   lingo_cmdMap
//   lingo_cmdCrop
//   lingo_cmdSetSize
//   lingo_cmdMediaReady
//   lingo_cmdGetImage
//   lingo_cmdSetImage
//   lingo_cmdGetUseAlpha
//   lingo_cmdGetBits
//   lingo_cmdPurge
//   lingo_cmdGetMovieRef
//   lingo_cmdSetMovieRef
//   lingo_getVtablePtr
//   lingo_setVtableRef
//   lingo_getVtableList
//   lingo_callVtableMethodEx
//   lingo_callVtableMethod
//   lingo_getVtableRef
//   lingo_setVtableFlag
//   lingo_getVtableValue
//   lingo_setVtableValue
//   lingo_getVtableCount
//   lingo_dispatchVtableOp
//   lingo_cmdGetProperty2
//   lingo_cmdSetProperty2
//   lingo_cmdCallMethod2
//   lingo_cmdGetCount2
//   lingo_cmdGetByIndex2
//   lingo_cmdSetByIndex2
//   lingo_vtableGetProp
//   lingo_vtableSetProp
//   lingo_vtableSetPropStr


// ============================================================
// Function: lingo_cmdCount (FUN_6809d210)
// Address: 6809d210
// Size: 56 bytes
// Params: undefined4 param_1, int * param_2, int * param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdCount(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5
                 )
{
  void *local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0);
  media_registerXtraEventEx(local_8,param_3,param_2,param_4,param_5);
  return 0;
}



// ============================================================
// Function: lingo_cmdGetAt (FUN_6809d250)
// Address: 6809d250
// Size: 52 bytes
// Params: undefined4 param_1, int * param_2, int * param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdGetAt(undefined4 param_1,int *param_2,int *param_3,uint *param_4)
{
  int *local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0);
  media_unregisterXtraEventEx(local_8,param_3,param_2,param_4);
  return 0;
}



// ============================================================
// Function: lingo_cmdSetAt (FUN_6809d290)
// Address: 6809d290
// Size: 67 bytes
// Params: undefined4 param_1, undefined4 param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdSetAt(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  lingo_resolveContext(&local_20,&local_1c,&local_18,&local_14,&local_10,&local_c,&local_8);
  media_queryXtraPropertyEx(*(undefined4 *)(local_8 + 4),param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdDeleteAt (FUN_6809d2e0)
// Address: 6809d2e0
// Size: 18 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdDeleteAt(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0xb;
  return 0;
}



// ============================================================
// Function: lingo_cmdAddProp (FUN_6809d300)
// Address: 6809d300
// Size: 20 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdAddProp(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  media_getClipboardFormatId(param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdFindPos (FUN_6809d320)
// Address: 6809d320
// Size: 48 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdFindPos(undefined4 param_1,undefined4 param_2,int *param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_createPalette(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdWriteString (FUN_6809d350)
// Address: 6809d350
// Size: 197 bytes
// Params: int param_1, char * param_2, size_t param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdWriteString(int param_1,char *param_2,size_t param_3)
{
  int *piVar1;
  size_t _Count;
  int local_10c;
  byte local_108 [256];
  uint local_8;
  
  local_10c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_10c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  if (*(int *)(*(int *)(param_1 + 4) + 0x24) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x24);
    (**(code **)(*piVar1 + 0xc))(piVar1,param_2,param_3);
    return 0;
  }
  for (; param_3 != 0; param_3 = param_3 - _Count) {
    _Count = 0xff;
    if ((int)param_3 < 0x100) {
      _Count = param_3;
    }
    strncpy((char *)local_108,param_2,_Count);
    local_108[_Count] = 0;
    props_formatValue(local_10c,local_108);
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdReadString (FUN_6809d420)
// Address: 6809d420
// Size: 197 bytes
// Params: int param_1, char * param_2, size_t param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdReadString(int param_1,char *param_2,size_t param_3)
{
  int *piVar1;
  size_t _Count;
  int local_10c;
  byte local_108 [256];
  uint local_8;
  
  local_10c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_10c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  if (*(int *)(*(int *)(param_1 + 4) + 0x24) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x24);
    (**(code **)(*piVar1 + 0x10))(piVar1,param_2,param_3);
    return 0;
  }
  for (; param_3 != 0; param_3 = param_3 - _Count) {
    _Count = 0xff;
    if ((int)param_3 < 0x100) {
      _Count = param_3;
    }
    strncpy((char *)local_108,param_2,_Count);
    local_108[_Count] = 0;
    props_formatValue(local_10c,local_108);
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdGetProp (FUN_6809d4f0)
// Address: 6809d4f0
// Size: 71 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3, int param_4, int param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_cmdGetProp(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,int param_5,int *param_6
            )

{
  int iVar1;
  
  iVar1 = Ordinal_1405(&param_2,param_2,1,0);
  if (iVar1 != 0) {
    iVar1 = display_writeEncryptedStream(param_2,param_3,param_4,param_5);
    *param_6 = iVar1;
    return 0;
  }
  *param_6 = 0x67;
  return 0;
}



// ============================================================
// Function: lingo_cmdSetProp (FUN_6809d540)
// Address: 6809d540
// Size: 31 bytes
// Params: undefined4 param_1, int param_2, int param_3, uint * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdSetProp(undefined4 param_1,int param_2,int param_3,uint *param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = display_readStreamRange(param_2,param_3,param_4);
  *param_5 = iVar1;
  return 0;
}



// ============================================================
// Function: lingo_cmdGetPixel (FUN_6809d560)
// Address: 6809d560
// Size: 27 bytes
// Params: undefined4 param_1, uint param_2, int * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdGetPixel(undefined4 param_1,uint param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = display_createStreamConnection(param_2,param_3);
  *param_4 = iVar1;
  return 0;
}



// ============================================================
// Function: lingo_cmdSetPixel (FUN_6809d580)
// Address: 6809d580
// Size: 53 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdSetPixel(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = media_validateCastMember(&local_8,param_2);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0x80040001;
  }
  return uVar2;
}



// ============================================================
// Function: lingo_cmdGetRect (FUN_6809d5c0)
// Address: 6809d5c0
// Size: 32 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdGetRect(int *param_1)
{
  if (param_1[0x10f] != 0) {
    (**(code **)(*param_1 + 0x18))(param_1,0x80040014);
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdSetRect (FUN_6809d5f0)
// Address: 6809d5f0
// Size: 165 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdSetRect(int *param_1)
{
  undefined1 uVar1;
  undefined3 extraout_var;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  undefined1 local_408 [1024];
  uint local_8;
  
  Ordinal_1130();
  uVar1 = lingo_resolveRef(unaff_EBX,0,unaff_ESI + 3);
  if (CONCAT31(extraout_var,uVar1) != 0) {
    local_408[0] = 0;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x4c))(param_1,local_408,0x400);
    }
    Ordinal_1309(unaff_ESI + 6,0x400,local_408,2);
    (**(code **)(*unaff_EDI + 4))();
    unaff_ESI[5] = unaff_EDI;
    unaff_ESI[1] = 1;
    *unaff_ESI = 1;
  }
  *(undefined4 *)(unaff_EBX + 900) = 0;
  return 0;
}



// ============================================================
// Function: lingo_cmdDuplicate (FUN_6809d6a0)
// Address: 6809d6a0
// Size: 94 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_cmdDuplicate(void)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (*unaff_ESI == 0) {
    return 0;
  }
  if (unaff_ESI[1] == 0) goto LAB_6809d6fa;
  iVar2 = lingo_callMethod((int)unaff_EDI,unaff_ESI + 3,unaff_ESI + 6,unaff_ESI[5],(int)(unaff_ESI + 2),
                       0);
  unaff_ESI[1] = iVar2;
  if (iVar2 == 0) goto LAB_6809d6fa;
  if (unaff_EDI[0xe1] == 0) {
    bVar1 = lingo_isMovieLoaded(unaff_EDI);
    iVar2 = 0;
    if (CONCAT31(extraout_var,bVar1) != 0) goto LAB_6809d6e0;
  }
  else {
LAB_6809d6e0:
    iVar2 = 1;
  }
  unaff_ESI[4] = iVar2;
  if (iVar2 != 0) {
    unaff_ESI[3] = -0x7ffbadf8;
    unaff_ESI[1] = 0;
  }
LAB_6809d6fa:
  return unaff_ESI[1];
}



// ============================================================
// Function: lingo_cmdCopyPixels (FUN_6809d700)
// Address: 6809d700
// Size: 94 bytes
// Params: void * this, int param_1
// Return: int *
// Calling convention: __thiscall
// ============================================================

int * __thiscall lingo_cmdCopyPixels(void *this,int param_1)

{
  int *in_EAX;
  int *local_8;
  
  if (in_EAX == (int *)0x0) {
    in_EAX = *(int **)((int)this + 0xc);
  }
  local_8 = this;
  if (*(int *)this != 0) {
    local_8 = (int *)0x0;
    lingo_callMethod(param_1,&local_8,(int)this + 0x18,0,(int)this + 8,0);
    if ((in_EAX == (int *)0x0) && (local_8 != (int *)0x0)) {
      in_EAX = local_8;
    }
  }
  if (*(int *)((int)this + 0x14) != 0) {
    (**(code **)(**(int **)((int)this + 0x14) + 8))(*(int **)((int)this + 0x14));
  }
  return in_EAX;
}



// ============================================================
// Function: lingo_cmdDraw (FUN_6809d760)
// Address: 6809d760
// Size: 86 bytes
// Params: int * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdDraw(int *param_1,undefined4 param_2,int *param_3)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  if (param_1[0x10f] != 0) {
    (**(code **)(*param_1 + 0x18))(param_1,0x80040014);
  }
  param_1[0x10f] = local_8;
  lingo_cmdSetRect(param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdFill (FUN_6809d7c0)
// Address: 6809d7c0
// Size: 28 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdFill(void)
{
  lingo_cmdDuplicate();
  return 0;
}



// ============================================================
// Function: lingo_cmdSetAlpha (FUN_6809d7e0)
// Address: 6809d7e0
// Size: 40 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdSetAlpha(int param_1)
{
  lingo_cmdCopyPixels((void *)(param_1 + 0xc),*(int *)(param_1 + 0x43c));
  *(undefined4 *)(param_1 + 0x43c) = 0;
  return 0;
}



// ============================================================
// Function: lingo_cmdGetAlpha (FUN_6809d810)
// Address: 6809d810
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdGetAlpha(undefined4 param_1,undefined4 param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_setPlaybackMode(&local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_cmdCreateMask (FUN_6809d840)
// Address: 6809d840
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdCreateMask(undefined4 param_1,undefined4 param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_setPlaybackTempo(&local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_cmdCreateMatte (FUN_6809d870)
// Address: 6809d870
// Size: 22 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdCreateMatte(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  Ordinal_4006(param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdTrimWhitespace (FUN_6809d890)
// Address: 6809d890
// Size: 26 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdTrimWhitespace(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  Ordinal_4005(param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: lingo_cmdExtract (FUN_6809d8b0)
// Address: 6809d8b0
// Size: 159 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdExtract(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_3;
  iVar1 = lingo_invokeVtable(&local_1c);
  if (iVar1 == 0) {
    if (local_1c == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(local_1c + 0x20);
    }
    iVar1 = 0;
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      iVar2 = local_1c;
      if (local_1c == 0) {
        iVar2 = *piVar3;
      }
      iVar1 = piVar3[2];
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
    Ordinal_4002(*(int *)(iVar1 + 0x20));
    if (piVar3 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdFilter (FUN_6809d950)
// Address: 6809d950
// Size: 173 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdFilter(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = param_3;
  local_18 = param_5;
  iVar1 = lingo_invokeVtable(&local_20);
  if (iVar1 == 0) {
    if (local_20 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(local_20 + 0x20);
    }
    iVar1 = 0;
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      iVar2 = local_20;
      if (local_20 == 0) {
        iVar2 = *piVar3;
      }
      iVar1 = piVar3[2];
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
    Ordinal_4003(*(int *)(iVar1 + 0x20),local_1c,param_4);
    if (piVar3 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdRotate (FUN_6809da00)
// Address: 6809da00
// Size: 159 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdRotate(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_3;
  iVar1 = lingo_invokeVtable(&local_1c);
  if (iVar1 == 0) {
    if (local_1c == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(local_1c + 0x20);
    }
    iVar1 = 0;
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      iVar2 = local_1c;
      if (local_1c == 0) {
        iVar2 = *piVar3;
      }
      iVar1 = piVar3[2];
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
    stage_parseExpression(*(int *)(iVar1 + 0x20),local_18);
    if (piVar3 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdMap (FUN_6809daa0)
// Address: 6809daa0
// Size: 182 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdMap(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_3;
  iVar1 = lingo_invokeVtable(&local_1c);
  if (iVar1 == 0) {
    if (local_1c == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(local_1c + 0x20);
    }
    iVar1 = 0;
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      iVar2 = local_1c;
      if (local_1c == 0) {
        iVar2 = *piVar3;
      }
      iVar1 = piVar3[2];
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
    Ordinal_4001(*(int *)(iVar1 + 0x20));
    if (piVar3 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdCrop (FUN_6809db60)
// Address: 6809db60
// Size: 182 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdCrop(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_3;
  iVar1 = lingo_invokeVtable(&local_1c);
  if (iVar1 == 0) {
    if (local_1c == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(local_1c + 0x20);
    }
    iVar1 = 0;
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      iVar2 = local_1c;
      if (local_1c == 0) {
        iVar2 = *piVar3;
      }
      iVar1 = piVar3[2];
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
    Ordinal_4011(*(undefined4 *)(iVar1 + 0x20),local_18);
    if (piVar3 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdSetSize (FUN_6809dc20)
// Address: 6809dc20
// Size: 71 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdSetSize(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x13c) != (code *)0x0) {
    (**(code **)(iVar1 + 0x13c))(param_2);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdMediaReady (FUN_6809dc70)
// Address: 6809dc70
// Size: 71 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdMediaReady(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x130) != (code *)0x0) {
    (**(code **)(iVar1 + 0x130))(param_2);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdGetImage (FUN_6809dcc0)
// Address: 6809dcc0
// Size: 75 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdGetImage(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x134) != (code *)0x0) {
    (**(code **)(iVar1 + 0x134))(param_2,param_3);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdSetImage (FUN_6809dd10)
// Address: 6809dd10
// Size: 79 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdSetImage(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x140) != (code *)0x0) {
    (**(code **)(iVar1 + 0x140))(param_2,param_3,param_4);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdGetUseAlpha (FUN_6809dd60)
// Address: 6809dd60
// Size: 83 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_cmdGetUseAlpha(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x138) != (code *)0x0) {
    (**(code **)(iVar1 + 0x138))(param_2,param_3,param_4,param_5);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdGetBits (FUN_6809ddc0)
// Address: 6809ddc0
// Size: 75 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdGetBits(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 300) != (code *)0x0) {
    (**(code **)(iVar1 + 300))(param_2,param_3);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdPurge (FUN_6809de20)
// Address: 6809de20
// Size: 71 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdPurge(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x144) != (code *)0x0) {
    (**(code **)(iVar1 + 0x144))(param_2);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdGetMovieRef (FUN_6809de70)
// Address: 6809de70
// Size: 71 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdGetMovieRef(undefined4 param_1,undefined4 param_2)

{
  int param_4;
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x148) != (code *)0x0) {
    (**(code **)(iVar1 + 0x148))(param_2);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_cmdSetMovieRef (FUN_6809dec0)
// Address: 6809dec0
// Size: 71 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_cmdSetMovieRef(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getDataPtr(*(int **)(local_8 + 4));
  if (*(code **)(iVar1 + 0x14c) != (code *)0x0) {
    (**(code **)(iVar1 + 0x14c))(param_2);
    return 0;
  }
  return 0x80004001;
}



// ============================================================
// Function: lingo_getVtablePtr (FUN_6809df10)
// Address: 6809df10
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getVtablePtr(undefined4 param_1,undefined4 *param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_getChannelCount(&local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_setVtableRef (FUN_6809df40)
// Address: 6809df40
// Size: 44 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setVtableRef(undefined4 param_1,int param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_removeChannel(&local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_getVtableList (FUN_6809df70)
// Address: 6809df70
// Size: 44 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getVtableList(undefined4 param_1,int *param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_findAvailableChannel(&local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_callVtableMethodEx (FUN_6809dfa0)
// Address: 6809dfa0
// Size: 286 bytes
// Params: undefined4 param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_callVtableMethodEx(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 uint *param_5,undefined4 *param_6)
{
  int iVar1;
  int local_20;
  int *local_1c;
  uint *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_5;
  local_1c = (int *)0x0;
  if (param_6 == (undefined4 *)0x0) {
    lingo_resolveContext((int *)&local_18,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0)
    ;
    media_getScorePropertyRef((int *)&local_18,param_2,param_3,param_4,param_5);
  }
  else {
    (**(code **)*param_6)(param_6,&DAT_68176378,&local_1c);
    if (local_1c == (int *)0x0) {
      return 0;
    }
    (**(code **)(*local_1c + 0xc))(local_1c,&local_20);
    if (local_20 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(local_20 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = local_20;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    media_getScorePropertyRef(&local_20,param_2,param_3,param_4,local_18);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return 0;
}



// ============================================================
// Function: lingo_callVtableMethod (FUN_6809e0c0)
// Address: 6809e0c0
// Size: 307 bytes
// Params: undefined4 param_1, uint param_2, undefined4 param_3, int * param_4, undefined4 * param_5, int param_6, uint * param_7, undefined4 * param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_callVtableMethod(undefined4 param_1,uint param_2,undefined4 param_3,int *param_4,
                 undefined4 *param_5,int param_6,uint *param_7,undefined4 *param_8)
{
  int iVar1;
  int local_24;
  uint *local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_7;
  local_1c = param_5;
  local_18 = (int *)0x0;
  if (param_8 == (undefined4 *)0x0) {
    lingo_resolveContext((int *)&local_1c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0)
    ;
    media_getScorePropertyData((int *)&local_1c,param_2,param_3,param_4,param_5,param_6,local_20);
  }
  else {
    (**(code **)*param_8)(param_8,&DAT_68176378,&local_18);
    if (local_18 == (int *)0x0) {
      return 0;
    }
    (**(code **)(*local_18 + 0xc))(local_18,&local_24);
    if (local_24 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(local_24 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = local_24;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    media_getScorePropertyData(&local_24,param_2,param_3,param_4,local_1c,param_6,local_20);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return 0;
}



// ============================================================
// Function: lingo_getVtableRef (FUN_6809e200)
// Address: 6809e200
// Size: 48 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getVtableRef(undefined4 param_1,uint param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_resetChannel(&local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_setVtableFlag (FUN_6809e230)
// Address: 6809e230
// Size: 48 bytes
// Params: undefined4 param_1, uint param_2, ushort param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setVtableFlag(undefined4 param_1,uint param_2,ushort param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_setChannelVolume(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_getVtableValue (FUN_6809e260)
// Address: 6809e260
// Size: 48 bytes
// Params: undefined4 param_1, uint param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getVtableValue(undefined4 param_1,uint param_2,undefined4 *param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_getChannelInfo(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_setVtableValue (FUN_6809e290)
// Address: 6809e290
// Size: 48 bytes
// Params: undefined4 param_1, uint param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setVtableValue(undefined4 param_1,uint param_2,int param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_commitChannel(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_getVtableCount (FUN_6809e2c0)
// Address: 6809e2c0
// Size: 167 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_getVtableCount(void)

{
  undefined4 uVar1;
  int iVar2;
  int *unaff_EBX;
  int *piVar3;
  int *unaff_EDI;
  int *local_c;
  int local_8;
  
  piVar3 = (int *)(*unaff_EBX + 0x184);
  local_c = (int *)0x0;
  *unaff_EDI = 0;
  local_8 = 0;
  if (*piVar3 == 0) {
    uVar1 = Ordinal_1038(&DAT_68176368,&DAT_68175fc8,piVar3);
    iVar2 = Ordinal_2063(uVar1);
    if (iVar2 == 0) {
      iVar2 = (*(code *)**(undefined4 **)*piVar3)((undefined4 *)*piVar3,&DAT_68176378,&local_c);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*local_c + 0x10))(local_c);
        if (iVar2 == 0) goto LAB_6809e336;
      }
    }
    piVar3 = (int *)*unaff_EDI;
    local_8 = iVar2;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      *unaff_EDI = 0;
    }
  }
  else {
LAB_6809e336:
    *unaff_EDI = *piVar3;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 4))((int *)*piVar3);
    }
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return local_8;
}



// ============================================================
// Function: lingo_dispatchVtableOp (FUN_6809e370)
// Address: 6809e370
// Size: 44 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_dispatchVtableOp(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_2 = 0;
  if (param_1 != 0) {
    iVar1 = lingo_getVtableCount();
    return iVar1;
  }
  return -0x7ffbf436;
}



// ============================================================
// Function: lingo_cmdGetProperty2 (FUN_6809e3a0)
// Address: 6809e3a0
// Size: 57 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdGetProperty2(undefined4 param_1,int param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_processScoreCallback(local_8,0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdSetProperty2 (FUN_6809e3e0)
// Address: 6809e3e0
// Size: 57 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdSetProperty2(undefined4 param_1,int param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_processScoreCallback(local_8,1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_cmdCallMethod2 (FUN_6809e420)
// Address: 6809e420
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdCallMethod2(undefined4 param_1,undefined4 *param_2)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  lingo_dispatchVtableOp(local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_cmdGetCount2 (FUN_6809e450)
// Address: 6809e450
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdGetCount2(undefined4 param_1,undefined4 *param_2)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  media_getCastCount(local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_cmdGetByIndex2 (FUN_6809e480)
// Address: 6809e480
// Size: 69 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdGetByIndex2(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 local_c;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = media_getCastMemberType(local_8,param_2,&local_c);
  if (iVar1 == 0) {
    lingo_getVtableCount();
  }
  return 0;
}



// ============================================================
// Function: lingo_cmdSetByIndex2 (FUN_6809e4d0)
// Address: 6809e4d0
// Size: 54 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_cmdSetByIndex2(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_getPixelFilterRef(&local_8,1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: lingo_vtableGetProp (FUN_6809e510)
// Address: 6809e510
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableGetProp(undefined4 param_1,undefined4 *param_2)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  media_getCastGlobalCount(local_8,param_2);
  return 0;
}



// ============================================================
// Function: lingo_vtableSetProp (FUN_6809e540)
// Address: 6809e540
// Size: 48 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableSetProp(undefined4 param_1,int param_2,undefined4 *param_3)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  media_getCastGlobalEntry(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_vtableSetPropStr (FUN_6809e570)
// Address: 6809e570
// Size: 52 bytes
// Params: undefined4 param_1, int param_2, undefined1 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableSetPropStr(undefined4 param_1,int param_2,undefined1 *param_3,undefined4 param_4)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  media_getCastGlobalData(local_8,param_2,param_3,param_4);
  return 0;
}


