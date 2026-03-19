// Module: cast
// Topic: Xtra/plugin bridge, menu items, and external interface
// Address range: 0x68024F90 - 0x68025D20
// Functions (21):
//   cast_renderXtraBitmap
//   cast_acquireXtraBitmap
//   cast_releaseXtraBitmap
//   cast_getXtraBitmapInfo
//   cast_getXtraPalette
//   cast_getMenuItemProperty
//   cast_formatMenuItem
//   cast_createMenuItem
//   cast_resolveMenuItem
//   cast_resolveMenuItemAndPop
//   cast_dispatchMenuItemAction
//   cast_getMenuItemObjProperty
//   cast_formatMenu
//   cast_createMenu
//   cast_resolveMenu
//   cast_resolveMenuAndPop
//   cast_dispatchMenuAction
//   cast_getMenuObjProperty
//   cast_bridgeXtraCall
//   cast_evalBinaryOp
//   cast_evalUnaryOp

// ============================================================
// Function: cast_renderXtraBitmap (FUN_68024f90)
// Address: 68024f90
// Size: 514 bytes
// Params: void * param_1, void * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6802516d) */

int cast_renderXtraBitmap(void *param_1,void *param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_6c [4];
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_6c[0] = 0;
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
  local_6c[1] = 0x800407d2;
  iVar2 = cast_blendInk(param_2,param_1);
  if (iVar2 == 0) {
    local_6c[1] = 0x80040bd5;
  }
  else {
    iVar2 = Ordinal_1114(0);
    if (iVar2 != 0) {
      local_6c[0] = cast_processBitmap(param_1,iVar2);
      if (local_6c[0] == 0) {
        local_6c[1] = 0x80040bd5;
      }
      else {
        iVar3 = Ordinal_1656(local_6c[0],&local_34);
        if ((((iVar3 != 0) && (local_30 < 0x10000)) && (local_34 < 0x10000)) && (local_2c < 0x4000))
        {
          iVar3 = cast_releaseBitmapRef();
          if (iVar3 == 0) {
            local_6c[2] = cast_compositeBitmapInk();
          }
          else {
            local_6c[2] = cast_convertBitmapDepth();
          }
          if (local_6c[2] == 0) {
            local_6c[1] = 0x80040002;
          }
          else {
            iVar3 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x3b,
                                (uint *)(local_6c + 2));
            if (iVar3 == 0) {
              Ordinal_1653(local_6c + 2);
            }
            else {
              local_6c[2] = 0;
              Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x12,
                          (uint *)(local_6c + 2));
              local_6c[2] = cast_processBitmapEx(param_1,iVar2);
              iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x40,
                                  (uint *)(local_6c + 2));
              if (iVar2 != 0) {
                Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x41,&local_4c);
                local_6c[2] = local_4c;
                local_58 = local_40;
                local_6c[3] = local_48;
                local_54 = (uint)(local_1c != 0);
                local_5c = local_44;
                local_50 = local_38;
                Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x41,
                            (uint *)(local_6c + 2));
                local_6c[1] = 0;
              }
            }
          }
        }
      }
    }
  }
  Ordinal_1653(local_6c);
  return 0;
}



// ============================================================
// Function: cast_acquireXtraBitmap (FUN_680251a0)
// Address: 680251a0
// Size: 174 bytes
// Params: void * param_1, void * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6802523d) */

undefined4 cast_acquireXtraBitmap(void *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = cast_blendInk(param_2,param_1);
  if (iVar1 == 0) {
    return 0x80040bd5;
  }
  iVar1 = Ordinal_1114(0);
  if (iVar1 == 0) {
    return 0x800407d2;
  }
  iVar2 = *(int *)(iVar1 + 0x2c);
  *(int *)(iVar1 + 0x2c) = iVar2 + 1;
  if (iVar2 == 0) {
    iVar2 = cast_processBitmap(param_1,iVar1);
    *(int *)(iVar1 + 0x80) = iVar2;
    if (iVar2 == 0) {
      return 0x800407d2;
    }
    iVar2 = Ordinal_1600();
    *(int *)(iVar1 + 0x30) = iVar2;
    if (iVar2 == 0) {
      return 0x800407d2;
    }
    Ordinal_1604(iVar2,*(undefined4 *)(iVar1 + 0x80));
    Ordinal_1630(*(undefined4 *)(iVar1 + 0x30),iVar1 + 0x34);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(iVar1 + 0x44);
  }
  return 0;
}



// ============================================================
// Function: cast_releaseXtraBitmap (FUN_68025250)
// Address: 68025250
// Size: 153 bytes
// Params: undefined4 param_1, void * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x680252cd) */

undefined4 cast_releaseXtraBitmap(undefined4 param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = cast_blendInk(param_2,param_1);
  if (iVar2 == 0) {
    return 0x80040bd5;
  }
  iVar2 = Ordinal_1114(0);
  if (iVar2 == 0) {
    return 0x800407d2;
  }
  piVar1 = (int *)(iVar2 + 0x2c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    Ordinal_1632(iVar2 + 0x34,1);
    Ordinal_1130(iVar2 + 0x34,0x4c);
    Ordinal_1604(*(undefined4 *)(iVar2 + 0x30),0);
    Ordinal_1601(iVar2 + 0x30);
    Ordinal_1653(iVar2 + 0x80);
  }
  return 0;
}



// ============================================================
// Function: cast_getXtraBitmapInfo (FUN_680252f0)
// Address: 680252f0
// Size: 227 bytes
// Params: void * param_1, void * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getXtraBitmapInfo(void *param_1,void *param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0x800407d2;
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
  iVar2 = cast_blendInk(param_2,param_1);
  iVar1 = local_3c;
  if (iVar2 == 0) {
    local_38 = 0x80040bd5;
  }
  else {
    iVar2 = Ordinal_1114(local_3c);
    if (iVar2 != 0) {
      local_40 = cast_processBitmap(param_1,iVar2);
      if (local_40 != 0) {
        iVar2 = Ordinal_1656(local_40,&local_34);
        if (iVar2 != 0) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = local_30;
            param_3[1] = local_34;
            param_3[2] = local_2c;
            *(undefined1 *)(param_3 + 5) = (undefined1)local_28;
            param_3[3] = local_20;
            param_3[4] = local_1c;
          }
          local_38 = 0;
        }
      }
      if (iVar1 != 0) {
        Ordinal_1115(iVar1);
      }
    }
  }
  Ordinal_1653(&local_40);
  return 0;
}



// ============================================================
// Function: cast_getXtraPalette (FUN_680253e0)
// Address: 680253e0
// Size: 75 bytes
// Params: undefined4 param_1, void * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getXtraPalette(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = cast_blendInk(param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    if (iVar1 != 0) {
      if ((*(short *)(iVar1 + 10) == 0) && (*(int *)(iVar1 + 0xc) == 0)) {
        uVar2 = Ordinal_1651(*(undefined4 *)(iVar1 + 0x14));
      }
      Ordinal_1115(param_1);
    }
  }
  return uVar2;
}



// ============================================================
// Function: cast_getMenuItemProperty (FUN_68025440)
// Address: 68025440
// Size: 457 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMenuItemProperty(int param_1,int *param_2,int param_3,int param_4,int *param_5)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_410;
  int local_40c;
  byte local_408 [1024];
  uint local_8;
  
  iVar3 = *(int *)(*param_2 + 8);
  local_40c = *(int *)(*param_2 + 0xc);
  if (param_4 < 0x1a1) {
    if (param_4 != 0x1a0) {
      if (param_4 == 0x7b) {
        if (param_3 == 0) {
          puVar2 = (undefined4 *)sprites_setTextEditState(param_1,iVar3,local_40c);
          props_getValuePair(param_1,puVar2,param_5);
        }
        else {
          iVar1 = props_validateString(param_1,param_5);
          if (iVar1 != 0) {
            puVar2 = props_copyString(param_5);
            sprites_getTextScrollPos(param_1,iVar3,local_40c,(int)puVar2);
            props_freeStringCallback(param_5,puVar2);
          }
        }
      }
      else {
        if (param_4 != 0x103) goto LAB_68025597;
        if (param_3 == 0) {
          sprites_handleTextCut(param_1,iVar3,local_40c,(undefined2 *)local_408);
          props_readPascalString(param_1,local_408,param_5);
        }
        else {
          iVar1 = props_validateString(param_1,param_5);
          if (iVar1 != 0) {
            props_toPascalString(param_5,local_408);
            sprites_handleTextSelectAll(param_1,iVar3,local_40c,(int)local_408);
          }
        }
      }
      goto LAB_680255f1;
    }
    if (param_3 != 0) {
      iVar1 = props_requireInt(param_1,param_5,&local_410);
      if (iVar1 != 0) {
        sprites_handleTextDelete(param_1,iVar3,local_40c,(uint)(local_410 != 0));
      }
      goto LAB_680255f1;
    }
    *param_5 = 4;
    iVar3 = sprites_handleTextUndo(param_1,iVar3,local_40c);
  }
  else {
    if (param_4 != 0x1a1) {
LAB_68025597:
      return 0;
    }
    if (param_3 != 0) {
      iVar1 = props_requireInt(param_1,param_5,&local_410);
      if (iVar1 != 0) {
        sprites_getTextEditState(param_1,iVar3,local_40c,(uint)(local_410 != 0));
      }
      goto LAB_680255f1;
    }
    *param_5 = 4;
    iVar3 = sprites_handleTextClear(param_1,iVar3,local_40c);
  }
  param_5[1] = iVar3;
LAB_680255f1:
  return 0;
}



// ============================================================
// Function: cast_formatMenuItem (FUN_68025610)
// Address: 68025610
// Size: 50 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatMenuItem(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  props_formatString(param_1,param_3,param_4,(byte *)"<menuItem %d %d %ld %lx>");
  return 0;
}



// ============================================================
// Function: cast_createMenuItem (FUN_68025650)
// Address: 68025650
// Size: 76 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createMenuItem(undefined4 param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  piVar2 = (int *)Ordinal_1111(0x10,9);
  if (piVar2 == (int *)0x0) {
    *unaff_ESI = 2;
    unaff_ESI[1] = 0;
    return 0;
  }
  *(int *)(unaff_EDI + 0xfc) = *(int *)(unaff_EDI + 0xfc) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  *puVar1 = &PTR_LAB_6818b998;
  puVar1[3] = param_2;
  *unaff_ESI = 3;
  unaff_ESI[1] = piVar2;
  return 0;
}



// ============================================================
// Function: cast_resolveMenuItem (FUN_680256a0)
// Address: 680256a0
// Size: 188 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_resolveMenuItem(int param_1)
{
  int iVar1;
  int unaff_EBX;
  uint local_418;
  int local_414;
  uint local_410 [2];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = props_tryGetTypedValue(param_1,0,2,4,&local_418);
  if (iVar1 != 0) {
    iVar1 = sprites_handleTextCopy(param_1,unaff_EBX,local_414);
LAB_680256de:
    cast_createMenuItem(unaff_EBX,iVar1);
    return 0;
  }
  iVar1 = props_getValueDirect(param_1,2,1,local_410);
  if (iVar1 != 0) {
    props_toPascalString((int *)local_410,local_408);
    iVar1 = sprites_processTextCommand(param_1,unaff_EBX,(int)local_408);
    if (iVar1 != 0) goto LAB_680256de;
    props_setErrorAndReturn(param_1,0x28);
  }
  return 0;
}



// ============================================================
// Function: cast_resolveMenuItemAndPop (FUN_68025770)
// Address: 68025770
// Size: 34 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveMenuItemAndPop(void)
{
  int iVar1;
  int unaff_ESI;
  undefined4 local_c [2];

  iVar1 = cast_resolveMenuItem(unaff_ESI);
  if (iVar1 != 0) {
    props_popArgs(unaff_ESI,local_c);
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchMenuItemAction (FUN_680257a0)
// Address: 680257a0
// Size: 47 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_dispatchMenuItemAction(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0xd3) {
    return 0;
  }
  cast_resolveMenuItemAndPop();
  return 1;
}



// ============================================================
// Function: cast_getMenuItemObjProperty (FUN_680257d0)
// Address: 680257d0
// Size: 253 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMenuItemObjProperty(int param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = *(int *)(*param_2 + 8);
  if (param_4 == 0x22) {
    if (param_3 == 0) {
      *param_5 = 3;
      param_5[1] = param_2;
      *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
      goto LAB_680258b5;
    }
  }
  else if (param_4 == 0xdd) {
    if (param_3 == 0) {
      *param_5 = 4;
      uVar3 = sprites_handleTextKeyDown(param_1,iVar1);
      param_5[1] = uVar3;
      goto LAB_680258b5;
    }
  }
  else if (param_4 == 0x103) {
    if (param_3 == 0) {
      sprites_handleTextPaste(param_1,iVar1,(undefined2 *)local_408);
      props_readPascalString(param_1,local_408,param_5);
      goto LAB_680258b5;
    }
  }
  else if (param_3 == 0) {
    score_lookupSymbol(DAT_68196304,param_4,(int)local_408);
    iVar2 = sprites_processTextCommand(param_1,iVar1,(int)local_408);
    if (iVar2 == 0) {
      props_reportError(param_1,0x28);
    }
    else {
      cast_createMenuItem(iVar1,iVar2);
    }
    goto LAB_680258b5;
  }
  props_reportError(param_1,0x39);
LAB_680258b5:
  return 0;
}



// ============================================================
// Function: cast_formatMenu (FUN_680258d0)
// Address: 680258d0
// Size: 46 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatMenu(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  props_formatString(param_1,param_3,param_4,(byte *)"<menu %d %ld %lx>");
  return 0;
}



// ============================================================
// Function: cast_createMenu (FUN_68025900)
// Address: 68025900
// Size: 70 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createMenu(undefined4 param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 == (int *)0x0) {
    *unaff_ESI = 2;
    unaff_ESI[1] = 0;
    return 0;
  }
  *(int *)(unaff_EDI + 0xfc) = *(int *)(unaff_EDI + 0xfc) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[1] = 1;
  *puVar1 = &PTR_LAB_6818b9e8;
  puVar1[2] = param_1;
  *unaff_ESI = 3;
  unaff_ESI[1] = piVar2;
  return 0;
}



// ============================================================
// Function: cast_resolveMenu (FUN_68025950)
// Address: 68025950
// Size: 185 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_resolveMenu(int param_1)
{
  int iVar1;
  uint local_418;
  int local_414;
  uint local_410 [2];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = props_tryGetTypedValue(param_1,0,2,4,&local_418);
  if (iVar1 != 0) {
    iVar1 = sprites_handleTextDrag(param_1,local_414);
LAB_6802598d:
    cast_createMenu(iVar1);
    return 0;
  }
  iVar1 = props_getValueDirect(param_1,2,1,local_410);
  if (iVar1 != 0) {
    props_toPascalString((int *)local_410,local_408);
    iVar1 = sprites_handleTextInput(param_1,(int)local_408);
    if (iVar1 != 0) goto LAB_6802598d;
    props_setErrorAndReturn(param_1,0x37);
  }
  return 0;
}



// ============================================================
// Function: cast_resolveMenuAndPop (FUN_68025a10)
// Address: 68025a10
// Size: 34 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveMenuAndPop(void)
{
  int iVar1;
  int unaff_ESI;
  undefined4 local_c [2];

  iVar1 = cast_resolveMenu(unaff_ESI);
  if (iVar1 != 0) {
    props_popArgs(unaff_ESI,local_c);
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchMenuAction (FUN_68025a40)
// Address: 68025a40
// Size: 37 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_dispatchMenuAction(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0xd3) {
    return 0;
  }
  cast_resolveMenuAndPop();
  return 1;
}



// ============================================================
// Function: cast_getMenuObjProperty (FUN_68025a70)
// Address: 68025a70
// Size: 194 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getMenuObjProperty(int param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)
{
  int iVar1;
  undefined1 local_408 [1024];
  uint local_8;
  
  if (param_4 == 0xdd) {
    if (param_3 == 0) {
      *param_5 = 4;
      iVar1 = sprites_handleTextClick(param_1);
      param_5[1] = iVar1;
      goto LAB_68025b1a;
    }
  }
  else if (param_4 == 0x187) {
    if (param_3 == 0) {
      *param_5 = 3;
      param_5[1] = param_2;
      *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
      goto LAB_68025b1a;
    }
  }
  else if (param_3 == 0) {
    score_lookupSymbol(DAT_68196304,param_4,(int)local_408);
    iVar1 = sprites_handleTextInput(param_1,(int)local_408);
    if (iVar1 == 0) {
      props_reportError(param_1,0x37);
    }
    else {
      cast_createMenu(iVar1);
    }
    goto LAB_68025b1a;
  }
  props_reportError(param_1,0x39);
LAB_68025b1a:
  return 0;
}



// ============================================================
// Function: cast_bridgeXtraCall (FUN_68025b40)
// Address: 68025b40
// Size: 209 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, int * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_bridgeXtraCall(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4)
{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  undefined1 local_408 [1024];
  uint local_8;
  
  switch(*param_4) {
  case 1:
  case 0x40:
  case 0x43:
    props_toPascalString(param_4,local_408);
    uVar1 = sprites_getMemberByIndex(param_3,(int)local_408);
    sVar2 = (short)uVar1;
    break;
  default:
    sVar2 = 0;
    goto LAB_68025b9a;
  case 4:
    sVar2 = (short)param_4[1];
    break;
  case 9:
  case 0x20:
  case 0x23:
    if (*param_4 == 0x20) {
      uVar3 = strings_floatToUint64(0x20,param_2);
      sVar2 = (short)uVar3;
    }
    else {
      uVar3 = strings_floatToUint64(*(undefined4 *)param_4[1],param_2);
      sVar2 = (short)uVar3;
    }
  }
  if (-1 < sVar2) {
LAB_68025b9a:
    uVar1 = sprites_getMemberCount(param_3);
    if (sVar2 <= (short)uVar1) {
      return 0;
    }
  }
  if (*(int *)(param_3 + 0xe0) == 0) {
    props_setErrorAndReturn(param_3,0x48);
  }
  return 0;
}



// ============================================================
// Function: cast_evalBinaryOp (FUN_68025c70)
// Address: 68025c70
// Size: 171 bytes
// Params: undefined4 param_1, int param_2, uint param_3, uint * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_evalBinaryOp(undefined4 param_1,int param_2,uint param_3,uint *param_4,int param_5)
{
  int iVar1;
  uint unaff_ESI;
  undefined4 local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  if (param_5 == 0) {
    local_8 = *(int **)(unaff_ESI + 0x20);
    local_c = *(int *)(unaff_ESI + 0x1c);
    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
    iVar1 = **(int **)(unaff_ESI + 0x10);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0x18));
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x18));
  }
  else {
    local_c = 4;
    local_8 = (int *)0x0;
  }
  local_14 = *(undefined4 *)(unaff_ESI + 0x1c);
  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
  local_10 = *(int **)(unaff_ESI + 0x20);
  iVar1 = **(int **)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0x18));
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x18));
  core_dispatchPropertyHandler(param_1,&local_14,unaff_ESI,&local_c,&local_14,param_1,param_2,param_3,param_4);
  props_releaseValue(unaff_ESI,(byte)local_14,local_10);
  props_releaseValue(unaff_ESI,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: cast_evalUnaryOp (FUN_68025d20)
// Address: 68025d20
// Size: 49 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_evalUnaryOp(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int param_4)
{
  int unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *(undefined4 *)(unaff_ESI + 0x1c);
  local_8 = *(undefined4 *)(unaff_ESI + 0x20);
  core_convertAndReadValue(param_3,&local_c,unaff_ESI,&local_c,param_3,param_4,param_2);
  props_popValue(unaff_ESI);
  return 0;
}



