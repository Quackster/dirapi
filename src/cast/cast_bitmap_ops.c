// Module: cast
// Topic: Bitmap operations - rendering, compositing, palette management
// Address range: 0x680200D0 - 0x68021B20
// Functions (22):
//   cast_checkInkEffect
//   cast_applyInkEffect
//   cast_resetInkEffect
//   cast_initBitmapState
//   cast_lookupBitmapEntry
//   cast_initBitmapOp
//   cast_processBitmap
//   cast_releaseBitmapRef
//   cast_getBitmapState
//   cast_processBitmapEx
//   cast_cachePalette
//   cast_getPaletteIndex
//   cast_convertBitmapDepth
//   cast_compositeBitmapInk
//   cast_mapInkToType
//   cast_mapTypeToInk
//   cast_renderBitmapTransition
//   cast_testPixelMatch
//   cast_floodFillBitmap
//   cast_processBitmapPalette
//   cast_renderBitmapEffect
//   cast_updateBitmapAlpha

// ============================================================
// Function: cast_checkInkEffect (FUN_680200d0)
// Address: 680200d0
// Size: 95 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_checkInkEffect(void *this,int param_1)
{
  int iVar1;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  if ((*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x654) == 0) &&
     (*(int **)((int)this + 0xc) != (int *)0x0)) {
    iVar1 = events_setMiawTitleVisible(param_1,*(int **)((int)this + 0xc),local_28,local_18);
    if (iVar1 != 0) {
      Ordinal_1071();
    }
  }
  return 0;
}



// ============================================================
// Function: cast_applyInkEffect (FUN_68020130)
// Address: 68020130
// Size: 118 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_applyInkEffect(void *this,int param_1)
{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  if ((*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x654) == 0) &&
     (*(int **)((int)this + 0xc) != (int *)0x0)) {
    iVar1 = events_setMiawTitleVisible(param_1,*(int **)((int)this + 0xc),local_28,local_18);
    if (iVar1 != 0) {
      local_30 = *unaff_ESI;
      local_2c = *unaff_EDI;
      Ordinal_1072(&local_30,local_28,local_18);
      *unaff_ESI = local_30;
      *unaff_EDI = local_2c;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_resetInkEffect (FUN_680201b0)
// Address: 680201b0
// Size: 95 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_resetInkEffect(void *this,int param_1)
{
  int iVar1;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  if ((*(int *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x654) == 0) &&
     (*(int **)((int)this + 0xc) != (int *)0x0)) {
    iVar1 = events_setMiawTitleVisible(param_1,*(int **)((int)this + 0xc),local_28,local_18);
    if (iVar1 != 0) {
      Ordinal_1091();
    }
  }
  return 0;
}



// ============================================================
// Function: cast_initBitmapState (FUN_68020210)
// Address: 68020210
// Size: 109 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_initBitmapState(void *this,int param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = props_createRect(param_1,(int *)(**(int **)(param_1 + 0x10) + -8 +
                                       ((int)this - *(int *)(param_1 + 0x20)) * 8 +
                                      *(int *)(param_1 + 0x18)));
  if (iVar2 == 0) {
    return 0;
  }
  *unaff_ESI = local_14;
  unaff_ESI[1] = local_18;
  unaff_ESI[3] = local_10;
  unaff_ESI[2] = local_c;
  return 0;
}



// ============================================================
// Function: cast_lookupBitmapEntry (FUN_68020280)
// Address: 68020280
// Size: 29 bytes
// Params: int param_1, undefined4 * param_2
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall cast_lookupBitmapEntry(int param_1,undefined4 *param_2)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = props_getPointsFromObject(in_EAX,(uint *)(**(int **)(in_EAX + 0x10) + -8 +
                                       (param_1 - *(int *)(in_EAX + 0x20)) * 8 +
                                      *(int *)(in_EAX + 0x18)),param_2);
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: cast_initBitmapOp (FUN_680202a0)
// Address: 680202a0
// Size: 55 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_initBitmapOp(undefined4 param_1,int param_2)
{
  int iVar1;
  int in_EAX;
  int *unaff_ESI;
  
  iVar1 = *(int *)(*(int *)(param_2 + 8) + 4);
  if (*(short *)(in_EAX + 10) != 0) {
    Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*(undefined4 *)(in_EAX + 8),10,
                (uint *)0x0);
    return 0;
  }
  if ((*(int **)(in_EAX + 0xc) != (int *)0x0) && (unaff_ESI != (int *)0x0)) {
    events_getMiawTitleVisible(param_2,*(int **)(in_EAX + 0xc),unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: cast_processBitmap (FUN_680202e0)
// Address: 680202e0
// Size: 157 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_processBitmap(void *this,int param_1)
{
  int iVar1;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)((int)this + 8) + 4);
  if (*(short *)(param_1 + 10) == 0) {
    if (*(int **)(param_1 + 0xc) != (int *)0x0) {
      events_getMiawWindowType((int)this,*(int **)(param_1 + 0xc));
      return 0;
    }
    Ordinal_1651(*(undefined4 *)(param_1 + 0x14));
    return 0;
  }
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*(undefined4 *)(param_1 + 8),
                      0x3b,local_20);
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: cast_releaseBitmapRef (FUN_68020380)
// Address: 68020380
// Size: 29 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_releaseBitmapRef(void)

{
  undefined4 local_8;
  
  local_8 = 0;
  Ordinal_1653(&local_8);
  return 1;
}



// ============================================================
// Function: cast_getBitmapState (FUN_680203a0)
// Address: 680203a0
// Size: 196 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getBitmapState(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_EBX;
  int unaff_ESI;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(short *)(unaff_ESI + 10) == 0) {
    if (*(int **)(unaff_ESI + 0xc) != (int *)0x0) {
      iVar2 = events_setMiawWindowType(param_1,*(int **)(unaff_ESI + 0xc));
      Ordinal_366(*(int *)(iVar1 + 0x20),iVar2,unaff_EBX);
      return 0;
    }
    if (*(int *)(unaff_ESI + 0x20) == 0) {
      if (*(int *)(unaff_ESI + 0x1c) == 0) {
        uVar3 = Ordinal_366(*(int *)(iVar1 + 0x20),*(int *)(unaff_ESI + 0x18),unaff_EBX);
        *(undefined4 *)(unaff_ESI + 0x1c) = uVar3;
      }
      Ordinal_1731(*(undefined4 *)(unaff_ESI + 0x1c));
      return 0;
    }
  }
  else {
    iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*(undefined4 *)(unaff_ESI + 8)
                        ,0x2e,local_20);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_processBitmapEx (FUN_68020470)
// Address: 68020470
// Size: 184 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_processBitmapEx(void *this,int param_1)
{
  int iVar1;
  int iVar2;
  double local_38 [3];
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)((int)this + 8) + 4);
  if (*(short *)(param_1 + 10) == 0) {
    if (*(int **)(param_1 + 0xc) != (int *)0x0) {
      events_setMiawWindowType((int)this,*(int **)(param_1 + 0xc));
      return 0;
    }
    return 0;
  }
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*(undefined4 *)(param_1 + 8),
                      0x40,local_20);
  if (iVar2 != 0) {
    return 0;
  }
  Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x11,local_38);
  Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)local_38);
  return 0;
}



// ============================================================
// Function: cast_cachePalette (FUN_68020530)
// Address: 68020530
// Size: 39 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_cachePalette(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_ESI + 0x28) != unaff_EDI) {
    Ordinal_1742(unaff_ESI + 0x24);
  }
  if (*(int *)(unaff_ESI + 0x24) == 0) {
    uVar1 = Ordinal_1740();
    *(undefined4 *)(unaff_ESI + 0x24) = uVar1;
    *(int *)(unaff_ESI + 0x28) = unaff_EDI;
    return uVar1;
  }
  return *(undefined4 *)(unaff_ESI + 0x24);
}



// ============================================================
// Function: cast_getPaletteIndex (FUN_68020560)
// Address: 68020560
// Size: 17 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getPaletteIndex(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(int *)(in_EAX + 0x20) != 0) {
    uVar1 = Ordinal_1683(*(int *)(in_EAX + 0x20));
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: cast_convertBitmapDepth (FUN_68020580)
// Address: 68020580
// Size: 301 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_convertBitmapDepth(void)
{
  int iVar1;
  int unaff_EDI;
  int local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [5];
  undefined1 local_18 [16];
  uint local_8;
  
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_58 = 0;
  local_60 = 0;
  local_5c = 0;
  iVar1 = Ordinal_1656();
  if (iVar1 != 0) {
    if (local_44 == 0x18) {
      local_44 = 0x20;
      iVar1 = Ordinal_1650(0x20,local_40,local_3c,local_54,local_58,0);
      if (iVar1 != 0) {
        local_5c = Ordinal_1600();
        local_60 = Ordinal_1600();
        if (((local_5c != 0) && (local_60 != 0)) && (unaff_EDI != 0)) {
          Ordinal_1604(local_5c);
          Ordinal_1604(local_60,iVar1);
          Ordinal_1060(local_18,0,0,local_54,local_58);
          local_2c[0] = 0;
          Ordinal_1616(local_60,local_18,local_5c,local_18,0,0,local_2c,0,0);
        }
      }
    }
    else {
      Ordinal_1652();
    }
  }
  Ordinal_1604(local_5c,0);
  Ordinal_1604(local_60,0);
  Ordinal_1601(&local_5c);
  Ordinal_1601(&local_60);
  return 0;
}



// ============================================================
// Function: cast_compositeBitmapInk (FUN_680206b0)
// Address: 680206b0
// Size: 393 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_compositeBitmapInk(void)
{
  int iVar1;
  int iVar2;
  void *unaff_EBX;
  int unaff_ESI;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c [4];
  undefined4 local_2c [5];
  undefined4 local_18 [4];
  uint local_8;
  
  local_84 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_7c = 0;
  local_80 = 0;
  local_84 = cast_processBitmap(unaff_EBX,unaff_ESI);
  if (local_84 != 0) {
    iVar1 = Ordinal_1656(local_84,&local_78);
    if ((iVar1 != 0) && (*(int *)(unaff_ESI + 0xc) != 0)) {
      Ordinal_1060(&local_4c,0,0,local_74,local_78);
      iVar1 = Ordinal_1650(local_64,local_60,local_5c,local_44 - local_4c,local_40 - local_48,0);
      if (iVar1 != 0) {
        Ordinal_1665(iVar1,0);
        iVar2 = events_setMiawTitleVisible((int)unaff_EBX,*(int **)(unaff_ESI + 0xc),local_3c,local_18);
        if (iVar2 == 0) {
          Ordinal_1060(local_18,0,0,local_44 - local_4c,local_40 - local_48);
        }
        local_80 = Ordinal_1600();
        local_7c = Ordinal_1600();
        if ((local_80 != 0) && (local_7c != 0)) {
          Ordinal_1604(local_80,local_84);
          Ordinal_1604(local_7c,iVar1);
          local_2c[0] = 0;
          Ordinal_1616(local_7c,&local_4c,local_80,local_18,0,0,local_2c,0,0);
        }
      }
    }
  }
  Ordinal_1604(local_80,0);
  Ordinal_1604(local_7c,0);
  Ordinal_1601(&local_80);
  Ordinal_1601(&local_7c);
  Ordinal_1653(&local_84);
  return 0;
}



// ============================================================
// Function: cast_mapInkToType (FUN_68020840)
// Address: 68020840
// Size: 149 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_mapInkToType(void)

{
  int in_EAX;
  
  if (in_EAX < 0x342) {
    if (in_EAX != 0x341) {
      if (in_EAX == 0xcb) {
        return 0xe;
      }
      if (in_EAX == 0x235) {
        return 10;
      }
    }
  }
  else {
    switch(in_EAX) {
    case 0x3a1:
      return 4;
    case 0x3a2:
      return 6;
    case 0x3a3:
      return 8;
    case 0x3a4:
      return 1;
    case 0x3a5:
      return 5;
    case 0x3a6:
      return 7;
    case 0x3a7:
      return 9;
    case 0x3aa:
      return 0x12;
    case 0x3ab:
      return 0x14;
    case 0x3ac:
      return 2;
    case 0x3ad:
      return 0x18;
    case 0x3ae:
      return 0x10;
    case 0x3af:
      return 0x16;
    case 0x3b0:
      return 0x1a;
    case 0x3b1:
      return 0x1c;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_mapTypeToInk (FUN_68020920)
// Address: 68020920
// Size: 124 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_mapTypeToInk(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  default:
    return 0;
  case 1:
    return 4;
  case 2:
    return 6;
  case 3:
    return 8;
  case 4:
    return 1;
  case 5:
    return 5;
  case 6:
    return 7;
  case 7:
    return 9;
  case 0x20:
    return 10;
  case 0x21:
    return 0x12;
  case 0x22:
    return 0xe;
  case 0x23:
    return 0x14;
  case 0x24:
    return 2;
  case 0x25:
    return 0x18;
  case 0x26:
    return 0x10;
  case 0x27:
    return 0x16;
  case 0x28:
    return 0x1a;
  case 0x29:
    return 0x1c;
  }
}



// ============================================================
// Function: cast_renderBitmapTransition (FUN_68020a20)
// Address: 68020a20
// Size: 1295 bytes
// Params: void * this, void * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_renderBitmapTransition(void *this,void *param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int extraout_EDX;
  uint local_bc;
  int *local_b8;
  int local_b4;
  int *local_b0;
  uint local_ac;
  int *local_a8;
  undefined4 local_a4;
  uint local_a0;
  int *local_9c;
  int local_98;
  int local_94;
  undefined4 local_90;
  void *local_8c;
  undefined4 local_88;
  int *local_84;
  void *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  uint local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_8c = param_1;
  local_84 = (int *)0x0;
  local_98 = 0;
  local_90 = 0;
  local_a4 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_94 = 0;
  local_88 = 0x1ffffff;
  local_80 = this;
  iVar3 = cast_initBitmapState((void *)0x2,(int)this);
  if (iVar3 == 0) {
    iVar3 = props_getRectField((int)this,
                         (int *)(**(int **)((int)this + 0x10) + *(int *)((int)this + 0x20) * -8 + 8
                                + *(int *)((int)this + 0x18)));
    if (iVar3 == 0) {
      iVar3 = props_getTypedValue((int)this,2,4,&local_18);
      piVar6 = local_84;
      if ((((iVar3 == 0) ||
           (iVar3 = props_getTypedValue((int)this,3,4,(uint *)&local_14), piVar6 = local_84, iVar3 == 0))
          || (iVar3 = props_getTypedValue((int)this,4,4,&local_10), piVar6 = local_84, iVar3 == 0)) ||
         (iVar3 = props_getTypedValue((int)this,5,4,(uint *)&local_c), piVar6 = local_84, iVar3 == 0))
      goto LAB_68020b37;
      iVar3 = 6;
    }
    else {
      local_18 = local_ac;
      local_14 = local_b0;
      iVar3 = props_getRectField((int)this,
                           (int *)(**(int **)((int)this + 0x10) +
                                   (2 - *(int *)((int)this + 0x20)) * 8 + *(int *)((int)this + 0x18)
                                  ));
      if (iVar3 == 0) {
        props_setErrorAndReturn((int)this,0xf);
        piVar6 = local_84;
        goto LAB_68020b37;
      }
      local_10 = local_ac;
      local_c = local_b0;
      iVar3 = 4;
    }
  }
  else {
    iVar3 = 3;
  }
  iVar4 = props_getInt((int)this);
  if ((iVar3 <= iVar4) &&
     (iVar4 = props_coerceAndStore((int)this,
                           (uint *)(**(int **)((int)this + 0x10) + -8 +
                                    (iVar3 - *(int *)((int)this + 0x20)) * 8 +
                                   *(int *)((int)this + 0x18)),&local_88), iVar4 == 0)) {
    iVar3 = iVar3 + 1;
  }
  iVar4 = props_getInt((int)this);
  if (iVar3 <= iVar4) {
    local_94 = score_resolveProplistEntry((int)this,iVar3,&local_a8);
  }
  local_98 = cast_processBitmap(this,(int)local_8c);
  piVar6 = local_84;
  if ((local_98 == 0) || (iVar3 = Ordinal_1656(local_98,&local_7c), piVar6 = local_84, iVar3 == 0))
  goto LAB_68020b37;
  cast_checkInkEffect(local_8c,(int)this);
  if ((local_68 < 9) || ((*(unsigned char *)((char *)&local_88 + 3)) == '\0')) {
    local_90 = cast_getBitmapState((int)this);
  }
  if (local_68 < 9) {
    local_a4 = cast_cachePalette();
    this = local_80;
  }
  piVar6 = local_14;
  uVar1 = local_18;
  if ((int)local_c < (int)local_14) {
    local_b8 = local_c;
    local_14 = local_c;
    local_c = piVar6;
    local_18 = local_10;
    local_10 = uVar1;
  }
  local_80 = (void *)0x0;
  local_84 = (int *)0x1;
  iVar3 = 3;
  Ordinal_1130(&local_2c,0x14);
  local_2c = 0;
  local_28 = 0x100;
  local_24 = 0xff;
  local_23 = 0xff;
  local_22 = 0xff;
  local_21 = 1;
  local_48 = 0xff;
  local_47 = 0xff;
  local_46 = 0xff;
  local_45 = 1;
  local_4c = 0x1000000;
  local_50 = 0;
  if (local_94 == 0) {
LAB_68020e86:
    if (local_14 == local_c) {
      if (local_10 != local_18) {
        local_c = (int *)((int)local_c + (int)local_84);
      }
    }
    else if (local_10 == local_18) {
      local_10 = local_10 + (int)local_84;
    }
  }
  else {
    local_b4 = cast_getMemberData(this,local_a8);
    iVar4 = 1;
    if (local_b4 < 1) goto LAB_68020e86;
    do {
      cast_getContextData(this,local_a8,iVar4,&local_bc,&local_a0);
      props_resolveValue((int)this,&local_bc);
      if (local_bc == 8) {
        if (local_b8 == (int *)0xbe) {
          iVar5 = props_coerceAndStore((int)this,&local_a0,&local_94);
          if (iVar5 == 0) {
            local_88 = local_94;
          }
        }
        else if (local_b8 == (int *)0x16a) {
          iVar5 = props_callBuiltinMethod(8,extraout_EDX,(int)this,(byte *)&local_a0);
          if (iVar5 == 0) {
            local_84 = local_9c;
          }
        }
        else if ((local_b8 == (int *)0x278) && (local_a0 == 8)) {
          if ((int)local_9c < 0x284) {
            if (local_9c == (int *)0x283) {
              iVar3 = 2;
            }
            else if (local_9c == (int *)0x23) {
              iVar3 = 3;
            }
            else if (local_9c == (int *)0xbc) {
              iVar3 = 0;
            }
          }
          else if (local_9c == (int *)0x284) {
            iVar3 = 1;
          }
        }
      }
      props_releaseValue(this,(byte)local_bc,local_b8);
      props_releaseValue(this,(byte)local_a0,local_9c);
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_b4);
    if (iVar3 == 3) goto LAB_68020e86;
  }
  local_4c = local_88;
  local_80 = (void *)Ordinal_1600();
  Ordinal_1604(local_80,local_98);
  Ordinal_1609(local_80,local_90);
  Ordinal_1611(local_80,local_a4);
  piVar6 = (int *)Ordinal_1623(local_80,iVar3,&local_18,0xc,local_84,&local_50,&local_2c);
  Ordinal_1611(local_80,0);
  Ordinal_1609(local_80,0);
  Ordinal_1604(local_80,0);
  Ordinal_1601(&local_80);
LAB_68020b37:
  Ordinal_1653(&local_98);
  Ordinal_1733(&local_90);
  uVar2 = local_10;
  uVar1 = local_18;
  if (piVar6 != (int *)0x0) {
    if ((int)local_10 < (int)local_18) {
      local_10 = local_18;
      local_18 = uVar2;
    }
    cast_initBitmapOp(uVar1,(int)this);
  }
  return 0;
}



// ============================================================
// Function: cast_testPixelMatch (FUN_68020f40)
// Address: 68020f40
// Size: 69 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, uint param_4, uint param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
cast_testPixelMatch(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1686(param_3,param_2,param_1,0,&local_8);
  if (((iVar1 != 0) && ((local_8 & 0xffffff) != param_4)) && ((local_8 & 0xffffff) == param_5)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_floodFillBitmap (FUN_68020f90)
// Address: 68020f90
// Size: 744 bytes
// Params: int param_1, undefined4 param_2, int param_3, uint param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_floodFillBitmap(int param_1,undefined4 param_2,int param_3,uint param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_44 = param_2;
  local_50 = Ordinal_1111(0x3e800,1);
  if (local_50 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)Ordinal_1114(local_50);
    local_38 = 0;
    local_4c = 0;
    Ordinal_1656(param_2,&local_34);
    Ordinal_1686(param_2,param_1,param_3,0,&local_3c);
    local_3c = local_3c & 0xffffff;
    Ordinal_1685(param_2,param_1,param_3,0,param_4);
    Ordinal_1686(param_2,param_1,param_3,0,&param_4);
    Ordinal_1685(param_2,param_1,param_3,0,local_3c);
    iVar3 = cast_testPixelMatch(param_3,param_1,param_2,param_4,local_3c);
    if (iVar3 != 0) {
      if ((-1 < param_3 + 1) && (param_3 + 1 < local_34)) {
        *piVar2 = param_3;
        piVar2[1] = param_1;
        piVar2[2] = param_1;
        piVar2[3] = 1;
        local_38 = 1;
        piVar2 = piVar2 + 4;
      }
      while ((0 < local_38 && (local_4c == 0))) {
        local_40 = piVar2[-1];
        iVar3 = piVar2[-3];
        local_38 = local_38 + -1;
        iVar1 = piVar2[-2];
        piVar6 = piVar2 + -4;
        iVar5 = piVar2[-4] + local_40;
        local_48 = iVar3;
        if (iVar3 < -1) goto joined_r0x68021212;
        do {
          iVar4 = cast_testPixelMatch(iVar5,iVar3,local_44,param_4,local_3c);
          if (iVar4 == 0) break;
          if (iVar4 == 1) {
            Ordinal_1685(local_44,iVar3,iVar5,0,param_4);
          }
          iVar3 = iVar3 + -1;
        } while (-2 < iVar3);
        if (local_48 <= iVar3) goto joined_r0x68021212;
        iVar4 = iVar3 + 1;
        if (iVar4 < local_48) {
          if (local_38 < 15999) {
            if ((-1 < iVar5 - local_40) && (iVar5 - local_40 < local_34)) {
              piVar2[-3] = iVar4;
              *piVar6 = iVar5;
              piVar2[-2] = local_48 + -1;
              piVar2[-1] = -local_40;
              local_38 = local_38 + 1;
              piVar6 = piVar2;
            }
          }
          else {
            local_4c = 1;
          }
        }
        iVar3 = local_48 + 1;
        local_48 = iVar4;
        do {
          if (iVar3 <= local_30) {
            do {
              iVar4 = cast_testPixelMatch(iVar5,iVar3,local_44,param_4,local_3c);
              if (iVar4 == 0) break;
              if (iVar4 == 1) {
                Ordinal_1685(local_44,iVar3,iVar5,0,param_4);
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 <= local_30);
          }
          if (local_38 < 15999) {
            if ((-1 < local_40 + iVar5) && (local_40 + iVar5 < local_34)) {
              piVar6[1] = local_48;
              *piVar6 = iVar5;
              piVar6[2] = iVar3 + -1;
              piVar6[3] = local_40;
              piVar6 = piVar6 + 4;
              local_38 = local_38 + 1;
            }
          }
          else {
            local_4c = 1;
          }
          if (iVar1 + 1 < iVar3) {
            if (local_38 < 15999) {
              if ((-1 < iVar5 - local_40) && (iVar5 - local_40 < local_34)) {
                *piVar6 = iVar5;
                piVar6[1] = iVar1 + 1;
                piVar6[2] = iVar3 + -1;
                piVar6[3] = -local_40;
                piVar6 = piVar6 + 4;
                local_38 = local_38 + 1;
              }
            }
            else {
              local_4c = 1;
            }
          }
joined_r0x68021212:
          do {
            iVar3 = iVar3 + 1;
            if (iVar1 < iVar3) break;
            iVar4 = cast_testPixelMatch(iVar5,iVar3,local_44,param_4,local_3c);
          } while (iVar4 == 0);
          piVar2 = piVar6;
          local_48 = iVar3;
        } while (iVar3 <= iVar1);
      }
    }
  }
  if (piVar2 != (int *)0x0) {
    Ordinal_1115(local_50);
  }
  if (local_50 != 0) {
    Ordinal_1113(&local_50);
  }
  return 0;
}



// ============================================================
// Function: cast_processBitmapPalette (FUN_68021280)
// Address: 68021280
// Size: 629 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_processBitmapPalette(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  uint uVar3;
  void *unaff_EDI;
  uint local_64;
  uint local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [4];
  undefined1 local_14 [2];
  ushort uStack_12;
  ushort local_10;
  ushort uStack_e;
  uint local_8;
  
  local_54 = 0;
  local_50 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_58 = 0;
  local_5c = param_1;
  local_50 = cast_processBitmap(unaff_EDI,param_1);
  if ((local_50 != 0) && (iVar1 = Ordinal_1656(local_50,&local_44), iVar1 != 0)) {
    iVar1 = props_getRectField((int)unaff_EDI,
                         (int *)(**(int **)((int)unaff_EDI + 0x10) +
                                 *(int *)((int)unaff_EDI + 0x20) * -8 + 8 +
                                *(int *)((int)unaff_EDI + 0x18)));
    if (iVar1 == 0) {
      iVar1 = props_getTypedValue((int)unaff_EDI,2,4,&local_60);
      if ((iVar1 == 0) || (iVar1 = props_getTypedValue((int)unaff_EDI,3,4,&local_64), iVar1 == 0))
      goto LAB_680214a8;
      iVar1 = 4;
    }
    else {
      iVar1 = 3;
    }
    iVar2 = props_coerceAndStore((int)unaff_EDI,
                         (uint *)(**(int **)((int)unaff_EDI + 0x10) + -8 +
                                  (iVar1 - *(int *)((int)unaff_EDI + 0x20)) * 8 +
                                 *(int *)((int)unaff_EDI + 0x18)),&local_48);
    if (iVar2 == 0) {
      if (local_30 < 9) {
        if ((*(unsigned char *)((char *)&local_48 + 3)) == '\x01') {
          local_58 = cast_getBitmapState((int)unaff_EDI);
          if (local_58 == 0) goto LAB_680214a8;
          uVar3 = local_48 >> 8 & 0xff;
          local_4c = Ordinal_1738(local_58,(local_48 & 0xff) << 8 | local_48 & 0xff,
                                  uVar3 << 8 | uVar3,CONCAT11((*(unsigned char *)((char *)&local_48 + 2)),(*(unsigned char *)((char *)&local_48 + 2))));
          local_4c = local_4c & 0xff;
        }
        else {
          local_4c = local_48 & 0xff;
        }
      }
      else if ((*(unsigned char *)((char *)&local_48 + 3)) == '\0') {
        local_58 = cast_getBitmapState((int)unaff_EDI);
        if ((local_58 == 0) ||
           (iVar1 = Ordinal_1736(local_58,local_48 & 0xff,local_14,1), iVar1 == 0))
        goto LAB_680214a8;
        if (local_30 == 0x10) {
          local_4c = (uint)(uStack_e >> 0xb) +
                     (((uStack_12 & 0xf800) >> 8) * 0x20 + ((local_10 & 0xf800) >> 8)) * 4;
        }
        else {
          local_4c = ((uStack_12 & 0xff00) + (uint)(local_10 >> 8)) * 0x100 + (uint)(uStack_e >> 8);
        }
      }
      else {
        local_4c = ((local_48 & 0xff) * 0x100 + (local_48 >> 8 & 0xff)) * 0x100 +
                   (local_48 >> 0x10 & 0xff);
      }
    }
    else {
      iVar1 = props_getTypedValue((int)unaff_EDI,iVar1,4,&local_4c);
      if (iVar1 == 0) goto LAB_680214a8;
    }
    local_54 = cast_floodFillBitmap(local_60,local_50,local_64,local_4c);
  }
LAB_680214a8:
  Ordinal_1653(&local_50);
  Ordinal_1733(&local_58);
  if (local_54 != 0) {
    Ordinal_1060(local_18,0,0,local_40,local_44);
    cast_initBitmapOp(extraout_ECX,(int)unaff_EDI);
  }
  return 0;
}



// ============================================================
// Function: cast_renderBitmapEffect (FUN_68021500)
// Address: 68021500
// Size: 1564 bytes
// Params: void * param_1, void * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_renderBitmapEffect(void *param_1,void *param_2)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_d0;
  int *local_cc;
  int *local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  int *local_b4;
  int local_b0;
  undefined4 local_ac;
  int local_a8;
  void *local_a4;
  int local_a0;
  undefined4 local_9c;
  int *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  undefined1 local_3c [16];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar7 = 0;
  local_a0 = 0;
  local_94 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_a8 = 0;
  local_98 = (int *)0x0;
  local_90 = 0x1ffffff;
  local_9c = 0x1ffffff;
  local_a4 = param_1;
  local_b0 = cast_processBitmap(param_2,(int)param_1);
  if ((local_b0 == 0) || (iVar1 = Ordinal_1656(local_b0,&local_8c), iVar1 == 0)) goto LAB_68021ad3;
  iVar1 = cast_initBitmapState((void *)0x2,(int)param_2);
  if (iVar1 == 0) {
    iVar1 = props_getRectField((int)param_2,
                         (int *)(**(int **)((int)param_2 + 0x10) +
                                 *(int *)((int)param_2 + 0x20) * -8 + 8 +
                                *(int *)((int)param_2 + 0x18)));
    if (iVar1 == 0) {
      iVar1 = props_getTypedValue((int)param_2,2,4,&local_18);
      if ((((iVar1 == 0) || (iVar1 = props_getTypedValue((int)param_2,3,4,&local_14), iVar1 == 0)) ||
          (iVar1 = props_getTypedValue((int)param_2,4,4,&local_10), iVar1 == 0)) ||
         (iVar1 = props_getTypedValue((int)param_2,5,4,&local_c), iVar1 == 0)) goto LAB_68021ad3;
      iVar1 = 6;
    }
    else {
      local_18 = local_c0;
      local_14 = local_c4;
      iVar1 = props_getRectField((int)param_2,
                           (int *)(**(int **)((int)param_2 + 0x10) +
                                   (2 - *(int *)((int)param_2 + 0x20)) * 8 +
                                  *(int *)((int)param_2 + 0x18)));
      if (iVar1 == 0) {
        local_a0 = cast_processBitmapPalette((int)local_a4);
        goto LAB_68021ad3;
      }
      local_10 = local_c0;
      local_c = local_c4;
      iVar1 = 4;
    }
  }
  else {
    iVar1 = 3;
  }
  iVar2 = props_getInt((int)param_2);
  if ((iVar1 <= iVar2) &&
     (iVar2 = props_coerceAndStore((int)param_2,
                           (uint *)(**(int **)((int)param_2 + 0x10) + -8 +
                                    (iVar1 - *(int *)((int)param_2 + 0x20)) * 8 +
                                   *(int *)((int)param_2 + 0x18)),&local_90), iVar2 == 0)) {
    iVar1 = iVar1 + 1;
  }
  iVar2 = props_getInt((int)param_2);
  if (iVar1 <= iVar2) {
    iVar7 = score_resolveProplistEntry((int)param_2,iVar1,&local_c8);
  }
  cast_checkInkEffect(local_a4,(int)param_2);
  Ordinal_1060(local_3c,0,0,local_88,local_8c);
  if (iVar7 == 0) {
LAB_680218a7:
    iVar7 = Ordinal_1066(&local_18,&local_18,local_3c);
    if (iVar7 == 0) goto LAB_68021ad3;
  }
  else {
    iVar7 = cast_getMemberData(param_2,local_c8);
    iVar1 = 1;
    if (iVar7 < 1) goto LAB_680218a7;
    do {
      cast_getContextData(param_2,local_c8,iVar1,&local_d0,&local_b8);
      props_resolveValue((int)param_2,&local_d0);
      if (local_d0 == 8) {
        if ((int)local_cc < 0x279) {
          if (local_cc == (int *)0x278) {
            if (local_b8 == 8) {
              if (local_b4 == (int *)0xbc) {
                local_a8 = 0;
              }
              else if (local_b4 == (int *)0x283) {
                local_a8 = 2;
              }
              else if (local_b4 == (int *)0x284) {
                local_a8 = 1;
              }
            }
          }
          else if (local_cc == (int *)0xbe) {
            iVar2 = props_coerceAndStore((int)param_2,&local_b8,(int *)&local_bc);
            if (iVar2 == 0) {
              local_90 = local_bc;
            }
          }
          else if ((local_cc == (int *)0x16a) &&
                  (iVar2 = props_callBuiltinMethod(8,(int)&local_b8,(int)param_2,(byte *)&local_b8), iVar2 == 0
                  )) {
            local_98 = local_b4;
          }
        }
        else if ((local_cc == (int *)0x359) &&
                (iVar2 = props_coerceAndStore((int)param_2,&local_b8,(int *)&local_bc), iVar2 == 0)) {
          local_9c = local_bc;
        }
      }
      props_releaseValue(param_2,(byte)local_d0,local_cc);
      props_releaseValue(param_2,(byte)local_b8,local_b4);
      iVar1 = iVar1 + 1;
    } while (iVar1 <= iVar7);
    if (local_a8 == 0) goto LAB_680218a7;
  }
  if (((local_78 < 9) || ((*(unsigned char *)((char *)&local_90 + 3)) == '\0')) || ((*(unsigned char *)((char *)&local_9c + 3)) == '\0')) {
    local_ac = cast_getBitmapState((int)param_2);
  }
  local_94 = Ordinal_1600();
  Ordinal_1604(local_94,local_b0);
  Ordinal_1609(local_94,local_ac);
  if (local_a8 == 0) {
    if (local_78 < 8) {
      uVar3 = local_90;
      if ((*(unsigned char *)((char *)&local_90 + 3)) == '\x01') {
        local_ac = cast_getBitmapState((int)param_2);
        uVar3 = Ordinal_1738(local_ac,CONCAT11((undefined1)local_90,(undefined1)local_90),
                             CONCAT11((*(unsigned char *)((char *)&local_90 + 1)),(*(unsigned char *)((char *)&local_90 + 1))),
                             CONCAT11((*(unsigned char *)((char *)&local_90 + 2)),(*(unsigned char *)((char *)&local_90 + 2))));
      }
      local_98 = (int *)(uVar3 & 0xff);
      uVar3 = local_10;
      uVar5 = local_18;
      uVar8 = local_14;
      if ((int)local_14 < (int)local_c) {
        do {
          uVar6 = uVar5;
          if ((int)uVar5 < (int)uVar3) {
            do {
              Ordinal_1685(local_b0,uVar5,uVar8,0,local_98);
              uVar5 = uVar5 + 1;
              uVar3 = local_10;
              uVar6 = local_18;
            } while ((int)uVar5 < (int)local_10);
          }
          uVar8 = uVar8 + 1;
          uVar5 = uVar6;
        } while ((int)uVar8 < (int)local_c);
      }
      local_a0 = 1;
    }
    else {
      if (local_98 != (int *)0x0) goto LAB_68021a17;
      local_a0 = Ordinal_1619(local_94,&local_18,&local_90);
    }
  }
  else {
LAB_68021a17:
    Ordinal_1130(&local_2c,0x14);
    local_2c = 0;
    local_28 = 0x100;
    local_24 = 0x1ffffff;
    local_60 = 0;
    local_58 = local_90;
    local_5c = local_90;
    if (local_78 < 9) {
      uVar4 = cast_cachePalette();
      Ordinal_1611(local_94,uVar4);
    }
    local_a0 = Ordinal_1622(local_94,local_a8,&local_18,0xc,local_98,&local_9c,&local_60,&local_2c);
  }
  Ordinal_1611(local_94,0);
  Ordinal_1609(local_94,0);
  Ordinal_1604(local_94,0);
  Ordinal_1601(&local_94);
LAB_68021ad3:
  Ordinal_1653(&local_b0);
  Ordinal_1733(&local_ac);
  if (local_a0 != 0) {
    cast_initBitmapOp(extraout_ECX,(int)param_2);
  }
  return 0;
}



// ============================================================
// Function: cast_updateBitmapAlpha (FUN_68021b20)
// Address: 68021b20
// Size: 249 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_updateBitmapAlpha(void *param_1)
{
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_68 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar1 = *(int *)(*(int *)((int)param_1 + 8) + 4);
  local_68 = cast_processBitmap(param_1,unaff_ESI);
  Ordinal_1656(local_68,&local_34);
  if (local_20 == 0x20) {
    local_1c = -(uint)(unaff_EBX != 0) & 8;
    Ordinal_1657(local_68,0x20,local_1c,local_18);
    if (*(short *)(unaff_ESI + 10) != 0) {
      Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*(undefined4 *)(unaff_ESI + 8),0x41,
                  &local_64);
      if (local_54 != unaff_EBX) {
        local_4c = local_64;
        local_48 = local_60;
        local_44 = local_5c;
        local_40 = local_58;
        Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*(undefined4 *)(unaff_ESI + 8),
                    0x41,&local_4c);
      }
    }
  }
  Ordinal_1653(&local_68);
  return 0;
}



