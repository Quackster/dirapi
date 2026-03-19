// Module: media_playback
// Topic: Sprite rendering control and context-locked dispatch
// Address range: 0x680B2EF0 - 0x680B4A00
// Functions (40):
//   media_findSpriteEntry
//   media_dispatchRelease
//   media_dispatchSetValue
//   media_createNotifyObject
//   media_dispatchGetStatus
//   media_dispatchSetPosition
//   media_dispatchGetRect
//   media_dispatchInvalidate
//   media_dispatchSetBlend
//   media_dispatchSetRate
//   media_dispatchSetImage
//   media_dispatchSetImageXtra
//   media_dispatchSetSoundXtra
//   media_dispatchSetOverlayXtra
//   media_dispatchSetTransitionXtra
//   media_dispatchGetDuration
//   media_dispatchFinalize
//   media_initVtable
//   media_dispatchSetScale
//   media_composeSpriteMedia
//   media_queryDrawInterface
//   media_queryAudioInterface
//   media_dispatchUpdate
//   media_dispatchRender
//   media_dispatchDestroy
//   media_dispatchGetRectDirect
//   media_dispatchSetProperty
//   media_dispatchSetSound
//   media_dispatchSetImageRef
//   media_dispatchCheckHit
//   media_getVtableData
//   media_dispatchRenderAt
//   media_dispatchRenderByte
//   media_dispatchNotify
//   media_callSpriteMethod
//   media_callSpriteMethodEx
//   media_callSpriteAccessor
//   media_matchSpriteCallback
//   media_iterateSpriteCallbacks
//   media_freeSpriteEntries

// ============================================================
// Function: media_findSpriteEntry (FUN_680b2ef0)
// Address: 680b2ef0
// Size: 69 bytes
// Params: int * param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_findSpriteEntry(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0x10)) {
    iVar3 = 0;
    do {
      iVar1 = Ordinal_2066(iVar3 + 0x24 + iVar1,param_2);
      if (iVar1 != 0) {
        return iVar2 + 1;
      }
      iVar1 = *param_1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < *(int *)(iVar1 + 0x10));
  }
  return -1;
}



// ============================================================
// Function: media_dispatchRelease (FUN_680b2f40)
// Address: 680b2f40
// Size: 151 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchRelease(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 8))(param_2);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetValue (FUN_680b2fe0)
// Address: 680b2fe0
// Size: 157 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetValue(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x24))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_createNotifyObject (FUN_680b3080)
// Address: 680b3080
// Size: 113 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createNotifyObject(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  uVar1 = Ordinal_1038(&DAT_681764b8,&DAT_68175cf8);
  iVar2 = Ordinal_2063(uVar1);
  if (iVar2 == 0) {
    local_c = param_2;
    local_10 = param_1;
    iVar2 = (*(code *)**(undefined4 **)*in_EAX)((undefined4 *)*in_EAX,&DAT_681764c8,&local_8);
    if (iVar2 == 0) {
      (**(code **)(*local_8 + 0x10))(local_8,&local_10);
      (**(code **)(*local_8 + 8))(local_8);
    }
  }
  return iVar2;
}



// ============================================================
// Function: media_dispatchGetStatus (FUN_680b3100)
// Address: 680b3100
// Size: 179 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchGetStatus(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x50))(param_2,&local_18);
    *param_3 = local_18;
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetPosition (FUN_680b31c0)
// Address: 680b31c0
// Size: 163 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetPosition(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x18))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchGetRect (FUN_680b3270)
// Address: 680b3270
// Size: 194 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchGetRect(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x20);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    iVar1 = (**(code **)(*param_2 + 0x20))(param_2,param_3);
    if (iVar1 != 0) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[3] = 0x20;
      param_3[2] = 0x20;
    }
    if (iVar2 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchInvalidate (FUN_680b3340)
// Address: 680b3340
// Size: 153 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchInvalidate(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x30))(param_2);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetBlend (FUN_680b33e0)
// Address: 680b33e0
// Size: 163 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetBlend(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x34))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetRate (FUN_680b3490)
// Address: 680b3490
// Size: 163 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetRate(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x38))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}




// ============================================================
// Function: media_dispatchSetImage (FUN_680b3540)
// Address: 680b3540
// Size: 163 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetImage(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x2c))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetImageXtra (FUN_680b35f0)
// Address: 680b35f0
// Size: 213 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetImageXtra(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x20);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    iVar1 = media_queryXtraMethod(param_3,param_4,param_5,&local_18);
    if (iVar1 == 0) {
      (**(code **)(*param_2 + 0x2c))(param_2,local_18);
    }
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    if (iVar2 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetSoundXtra (FUN_680b36d0)
// Address: 680b36d0
// Size: 213 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetSoundXtra(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x20);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    iVar1 = media_queryXtraMethod(param_3,param_4,param_5,&local_18);
    if (iVar1 == 0) {
      (**(code **)(*param_2 + 0x28))(param_2,local_18);
    }
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    if (iVar2 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetOverlayXtra (FUN_680b37b0)
// Address: 680b37b0
// Size: 213 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetOverlayXtra(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x20);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    iVar1 = media_queryXtraMethod(param_3,param_4,param_5,&local_18);
    if (iVar1 == 0) {
      (**(code **)(*param_2 + 0x40))(param_2,local_18);
    }
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    if (iVar2 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetTransitionXtra (FUN_680b3890)
// Address: 680b3890
// Size: 213 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetTransitionXtra(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int iVar2;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x20);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    iVar1 = media_queryXtraMethod(param_3,param_4,param_5,&local_18);
    if (iVar1 == 0) {
      (**(code **)(*param_2 + 0x3c))(param_2,local_18);
    }
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    if (iVar2 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchGetDuration (FUN_680b3970)
// Address: 680b3970
// Size: 163 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchGetDuration(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x4c))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchFinalize (FUN_680b3a20)
// Address: 680b3a20
// Size: 153 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchFinalize(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x44))(param_2);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_initVtable (FUN_680b3ac0)
// Address: 680b3ac0
// Size: 177 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initVtable(int param_1,int *param_2,int param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x14))
              (param_2,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0x14),
               *(undefined4 *)(param_3 + 0x18),param_3 + 0xc);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetScale (FUN_680b3b80)
// Address: 680b3b80
// Size: 168 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetScale(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x1c))(param_2,*param_3,param_3[1]);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}




// ============================================================
// Function: media_composeSpriteMedia (FUN_680b3c30)
// Address: 680b3c30
// Size: 441 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_composeSpriteMedia(int param_1,int *param_2,int *param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_4c [10];
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_2;
  local_18 = 0;
  local_1c = 0;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_1 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = *(int *)(param_1 + 0x20);
    if ((local_24 != 0) && (*(int *)(local_24 + 4) != 0)) {
      Ordinal_2330();
      local_14 = param_1;
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
    }
  }
  iVar1 = media_dispatchGetDuration(param_1,param_3,&local_18);
  if ((iVar1 != 0) || (local_18 == -1)) {
    local_18 = 0;
  }
  if (param_5 == 0) {
    iVar1 = media_dispatchSetRate(param_1,param_3,&local_1c);
    if ((iVar1 != 0) || (local_1c == -1)) {
      local_1c = 0;
    }
  }
  piVar2 = (int *)stage_createBytecodeBlock(0x20,0x1c,local_1c + local_18);
  if (piVar2 == (int *)0x0) goto LAB_680b3da2;
  strings_createMediaStream(local_4c,piVar2,*(undefined4 *)(*piVar2 + 0x10));
  iVar1 = media_dispatchSetTransitionXtra(param_1,param_3,local_4c,0xffffffff,local_18);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      iVar1 = media_dispatchSetSoundXtra(param_1,param_3,local_4c,0xffffffff,local_1c);
      if (iVar1 != 0) goto LAB_680b3d9c;
    }
    stage_getBytecodeSize(piVar2);
    iVar1 = local_18;
    strings_writeMediaData(local_4c,piVar2,param_4,(int)*(short *)(*piVar2 + 0x18),local_18);
    iVar1 = media_dispatchSetOverlayXtra(param_1,local_20,local_4c,0xffffffff,iVar1);
    if ((iVar1 == 0) && (param_5 == 0)) {
      iVar1 = *(short *)(*piVar2 + 0x18) + local_18;
      iVar3 = *(int *)(*piVar2 + 0x10) - iVar1;
      strings_writeMediaData(local_4c,piVar2,param_4,iVar1,iVar3);
      media_dispatchSetImageXtra(param_1,local_20,local_4c,0xffffffff,iVar3);
    }
  }
LAB_680b3d9c:
  cast_freeHandle(piVar2);
LAB_680b3da2:
  if (local_24 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_queryDrawInterface (FUN_680b3df0)
// Address: 680b3df0
// Size: 172 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_queryDrawInterface(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    *param_3 = 0;
    (**(code **)*param_2)(param_2,&DAT_681762e8,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_queryAudioInterface (FUN_680b3ea0)
// Address: 680b3ea0
// Size: 172 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_queryAudioInterface(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    *param_3 = 0;
    (**(code **)*param_2)(param_2,&DAT_68176578,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchUpdate (FUN_680b3f50)
// Address: 680b3f50
// Size: 153 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchUpdate(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0xc))(param_2);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchRender (FUN_680b3ff0)
// Address: 680b3ff0
// Size: 153 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchRender(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x10))(param_2);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchDestroy (FUN_680b4090)
// Address: 680b4090
// Size: 151 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchDestroy(int param_1,int *param_2)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 8))(param_2);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchGetRectDirect (FUN_680b4130)
// Address: 680b4130
// Size: 176 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchGetRectDirect(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    (**(code **)(*param_2 + 0x20))(param_2,param_3);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetProperty (FUN_680b41e0)
// Address: 680b41e0
// Size: 225 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined1 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetProperty(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined1 *param_5
                 )
{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(param_1 + 0x20);
    }
    uVar3 = 0;
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      uVar3 = *(uint *)(piVar2[1] + 8);
      if (param_1 == 0) {
        local_18 = *piVar2;
      }
      else {
        local_18 = param_1;
      }
      Ordinal_2330();
      local_14 = local_18;
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
    }
    uVar1 = lingo_setGlobalProperty(uVar3,param_4);
    (**(code **)(*param_2 + 0x24))(param_2,param_3,uVar1);
    uVar3 = lingo_getGlobalProperty(uVar3);
    *param_5 = (char)uVar3;
    if (piVar2 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSetSound (FUN_680b42d0)
// Address: 680b42d0
// Size: 180 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetSound(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x28))(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}




// ============================================================
// Function: media_dispatchSetImageRef (FUN_680b4390)
// Address: 680b4390
// Size: 214 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSetImageRef(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(param_1 + 0x20);
    }
    iVar3 = 0;
    if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
      iVar3 = *(int *)(piVar4[1] + 8);
      if (param_1 == 0) {
        param_1 = *piVar4;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = param_1;
    }
    iVar1 = *param_2;
    uVar2 = lingo_setGlobalRef(iVar3,param_5);
    (**(code **)(iVar1 + 0x2c))(param_2,param_3,param_4,uVar2);
    if (piVar4 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchCheckHit (FUN_680b4470)
// Address: 680b4470
// Size: 205 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchCheckHit(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint *param_5)
{
  int iVar1;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x30))(param_2,param_4,param_3,&local_18);
    *param_5 = (uint)(local_18 != 0);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_getVtableData (FUN_680b4540)
// Address: 680b4540
// Size: 168 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getVtableData(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0xc))(param_2,param_3,param_4);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchRenderAt (FUN_680b45f0)
// Address: 680b45f0
// Size: 168 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchRenderAt(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    (**(code **)(*param_2 + 0x10))(param_2,param_3,param_4);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchRenderByte (FUN_680b46a0)
// Address: 680b46a0
// Size: 179 bytes
// Params: int param_1, int * param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchRenderByte(int param_1,int *param_2,byte param_3)
{
  int iVar1;
  undefined4 local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 != (int *)0x0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        Ordinal_2330();
        local_14 = param_1;
        local_c = 0;
        local_10 = DAT_68196374;
        DAT_68196374 = &local_14;
      }
    }
    local_18 = (uint)param_3;
    local_1c = 4;
    (**(code **)(*param_2 + 0x10))(param_2,0x150,&local_1c);
    if (iVar1 != 0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_dispatchNotify (FUN_680b4760)
// Address: 680b4760
// Size: 200 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x680b47cd) */

int media_dispatchNotify(int param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x20);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
      Ordinal_2330();
      local_14 = param_1;
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
    }
  }
  media_createNotifyObject(param_1,param_3);
  if (iVar1 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_callSpriteMethod (FUN_680b4830)
// Address: 680b4830
// Size: 71 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_callSpriteMethod(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
    uVar2 = lingo_setGlobalValue(param_1,param_4);
    uVar3 = lingo_setGlobalRef(param_1,param_3);
    uVar2 = (**(code **)(iVar1 + 0x10))(param_2,uVar3,uVar2,param_5,param_6);
    return uVar2;
  }
  return 0x800407d3;
}



// ============================================================
// Function: media_callSpriteMethodEx (FUN_680b4880)
// Address: 680b4880
// Size: 83 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_callSpriteMethodEx(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int **ppiVar7;
  
  piVar2 = param_2;
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
    ppiVar7 = &param_2;
    uVar5 = param_5;
    uVar6 = param_6;
    uVar3 = lingo_setGlobalValue(param_1,param_4);
    uVar4 = lingo_setGlobalRef(param_1,param_3);
    uVar5 = (**(code **)(iVar1 + 0x14))(piVar2,uVar4,uVar3,uVar5,uVar6,ppiVar7);
    *param_7 = param_2;
    return uVar5;
  }
  return 0x800407d3;
}



// ============================================================
// Function: media_callSpriteAccessor (FUN_680b48e0)
// Address: 680b48e0
// Size: 71 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_callSpriteAccessor(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
    uVar2 = lingo_setGlobalValue(param_1,param_4);
    uVar3 = lingo_setGlobalRef(param_1,param_3);
    uVar2 = (**(code **)(iVar1 + 0x18))(param_2,uVar3,uVar2,param_5,param_6);
    return uVar2;
  }
  return 0x800407d3;
}



// ============================================================
// Function: media_matchSpriteCallback (FUN_680b4930)
// Address: 680b4930
// Size: 49 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_matchSpriteCallback(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = Ordinal_2066(param_2,param_4 + 4);
  if (iVar1 != 0) {
    *(undefined4 *)(param_4 + 0x11c) = 1;
    return 0xffffffff;
  }
  return 0;
}



// ============================================================
// Function: media_iterateSpriteCallbacks (FUN_680b4970)
// Address: 680b4970
// Size: 133 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_iterateSpriteCallbacks(undefined4 *param_1)
{
  undefined4 uVar1;
  int *piVar2;
  undefined1 local_128 [4];
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_c;
  uint local_8;
  
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2068(uVar1);
  local_11c = param_1[2];
  local_120 = param_1[1];
  local_124 = *param_1;
  local_118 = param_1[3];
  local_c = 0;
  (**(code **)(*piVar2 + 0x14))(piVar2,media_matchSpriteCallback,local_128);
  (**(code **)(*piVar2 + 8))(piVar2);
  return 0;
}



// ============================================================
// Function: media_freeSpriteEntries (FUN_680b4a00)
// Address: 680b4a00
// Size: 68 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_freeSpriteEntries(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && ((int *)*param_1 != (int *)0x0)) {
    iVar1 = mediaPlayback_getEntryCount((int *)*param_1);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        mediaPlayback_releaseSlotEntry((int *)*param_1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    cast_freeHandle(*param_1);
    *param_1 = 0;
  }
  return 0;
}



