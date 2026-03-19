// Module: sprites
// Topic: Property dispatch by type, method routing, and sprite type handlers
// Address range: 0x68075230 - 0x6807ACF0
// Functions (46):
//   sprites_dispatchSpriteProperty
//   sprites_dispatchMemberField
//   sprites_dispatchMemberSymbol
//   sprites_dispatchMemberStyle
//   sprites_dispatchMemberData
//   sprites_dispatchMemberRect
//   sprites_dispatchMemberMedia
//   sprites_dispatchMemberFlags
//   sprites_dispatchMemberAttribute
//   sprites_dispatchProperty
//   sprites_getPropertyId
//   sprites_dispatchColorOp
//   sprites_dispatchMemberType
//   sprites_dispatchPropertyRouter
//   sprites_dispatchPropertyByIndex
//   sprites_dispatchPropertyByName
//   sprites_dispatchBitmapProperty
//   sprites_dispatchFieldProperty
//   sprites_dispatchSoundProperty
//   sprites_dispatchShapeProperty
//   sprites_dispatchButtonProperty
//   sprites_dispatchMovieProperty
//   sprites_dispatchScriptProperty
//   sprites_dispatchTransitionProperty
//   sprites_dispatchPaletteProperty
//   sprites_dispatchTextProperty
//   sprites_dispatchVectorProperty
//   sprites_dispatchFlashProperty
//   sprites_dispatchCursorProperty
//   sprites_dispatchFontProperty
//   sprites_dispatchPropertyByType
//   sprites_dispatchExtPropertyByType
//   sprites_dispatchBitmapColor
//   sprites_dispatchBitmapRect
//   sprites_dispatchBitmapMedia
//   sprites_dispatchBitmapFlags
//   sprites_dispatchFieldRect
//   sprites_dispatchFieldFlags
//   sprites_dispatchSoundMedia
//   sprites_dispatchShapeColor
//   sprites_dispatchShapeRect
//   sprites_dispatchTextRect
//   sprites_dispatchTextFlags
//   sprites_dispatchVectorRect
//   sprites_dispatchFlashRect
//   sprites_dispatchPropertyEx


// ============================================================
// Function: sprites_dispatchSpriteProperty (FUN_68075230)
// Address: 68075230
// Size: 385 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchSpriteProperty(int param_1,int param_2,undefined4 param_3)

{
  uint *in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int local_8;
  
  if (*(int *)(*(int *)(unaff_ESI + 8) + 4) == 0) {
    return -0x7ffbf82e;
  }
  local_8 = param_1;
  if (param_1 < 0x17f) {
    if (param_1 == 0x17e) {
      if (param_2 == 0) {
        uVar2 = sprites_getMemberForeColor(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,in_EAX);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,in_EAX,&local_8);
      if (iVar1 == 0) {
        sprites_setMemberForeColor(unaff_ESI,param_3);
        return 0;
      }
    }
    else if (param_1 == 0x54) {
      if (param_2 == 0) {
        uVar2 = sprites_getMemberEditable(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,in_EAX);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,in_EAX,&local_8);
      if (iVar1 == 0) {
        sprites_setMemberEditable(unaff_ESI,param_3,(uint)(local_8 != 0));
        return 0;
      }
    }
    else {
      if (param_1 != 0x160) {
        return -0x7ffbf82b;
      }
      if (param_2 == 0) {
        uVar2 = sprites_getMemberMoveable(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,in_EAX);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,in_EAX,&local_8);
      if (iVar1 == 0) {
        sprites_setMemberMoveable(unaff_ESI,param_3,(uint)(local_8 != 0));
        return 0;
      }
    }
  }
  else {
    if (param_1 != 0x244) {
      return -0x7ffbf82b;
    }
    if (param_2 == 0) {
      uVar2 = sprites_getMemberBackColor(unaff_ESI,param_3);
      iVar1 = props_storeIntValue(unaff_ESI,uVar2,in_EAX);
    }
    else {
      iVar1 = props_coerceAndReturnInt(unaff_ESI,in_EAX,&local_8);
      if (iVar1 == 0) {
        sprites_setMemberBackColor(unaff_ESI,param_3);
        return 0;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: sprites_dispatchMemberField (FUN_680753c0)
// Address: 680753c0
// Size: 551 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchMemberField(int param_1,int param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int iVar2;
  uint *unaff_EBX;
  int unaff_ESI;
  uint uVar3;
  uint local_40;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20 [6];
  uint local_8;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  iVar2 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  local_3c = 0;
  if (iVar2 == 0) {
    return 0;
  }
  if (param_1 < 0x2ba) {
    if (param_1 != 0x2b9) {
      if (param_1 == 0xa9) {
        if (param_2 == 0) {
          sprites_getMemberField(unaff_ESI,param_3,&local_40);
          props_storeSymbolValue(unaff_ESI,local_40,unaff_EBX);
          return 0;
        }
        local_3c = props_coerceToShort(unaff_ESI,unaff_EBX,(int *)&local_40);
        if (local_3c == 0) {
          sprites_setMemberField(unaff_ESI,param_3,local_40);
          return 0;
        }
      }
      else {
        if (param_1 != 0xfb) goto LAB_68075552;
        if (param_2 == 0) {
          Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x31,&local_38);
          if (local_38 != 0) {
            puVar1 = (undefined4 *)sprites_convertToString(local_38);
            props_getExtPair(unaff_ESI,puVar1,unaff_EBX);
            return 0;
          }
          props_returnWithValue(unaff_ESI,0x800407d7,(uint *)0x0);
          return 0;
        }
      }
      goto LAB_680755d3;
    }
    if (param_2 != 0) {
      local_3c = props_returnSymbol(unaff_ESI,0x800407d6,0x2b9);
      return 0;
    }
    iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x33,&local_38);
  }
  else {
    if (param_1 != 0x2ba) {
LAB_68075552:
      return 0;
    }
    if (param_2 != 0) {
      local_3c = props_coerceAndReturnInt(unaff_ESI,unaff_EBX,(int *)local_20);
      if (local_3c == 0) {
        Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x32,local_20);
        return 0;
      }
      goto LAB_680755d3;
    }
    iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x32,&local_38);
  }
  uVar3 = local_38;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  props_storeIntValue(unaff_ESI,uVar3,unaff_EBX);
LAB_680755d3:
  return 0;
}



// ============================================================
// Function: sprites_dispatchMemberSymbol (FUN_680755f0)
// Address: 680755f0
// Size: 650 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMemberSymbol(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  int unaff_ESI;
  uint *unaff_EDI;
  uint local_140;
  int local_13c;
  uint local_138 [6];
  uint local_120 [6];
  undefined1 local_108 [256];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  local_13c = 0;
  if (iVar1 == 0) {
    return 0;
  }
  cast_getSymbolName(param_3,(int)local_108,0x100);
  if (param_3 == 0x27d) {
    if (param_2 == 0) {
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x21,local_120);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else if (local_120[0] == 1) {
        local_120[0] = 0x285;
        iVar1 = 0x285;
      }
      else if (local_120[0] == 3) {
        local_120[0] = 0x15f;
        iVar1 = 0x15f;
      }
      else {
        if (local_120[0] != 7) goto LAB_68075772;
        local_120[0] = 0x286;
        iVar1 = 0x286;
      }
      props_storeObjectRef(unaff_ESI,iVar1,unaff_EDI);
    }
    else {
      local_13c = props_coerceAndReturnFloat(unaff_ESI,unaff_EDI,&local_140);
      if (local_13c == 0) {
        if (local_140 == 0x15f) {
          local_138[0] = 3;
        }
        else if (local_140 == 0x285) {
          local_138[0] = 1;
        }
        else {
          if (local_140 != 0x286) {
LAB_68075772:
            local_13c = 0x80040014;
            return 0;
          }
          local_138[0] = 7;
        }
        iVar1 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x21,local_138);
        if (iVar1 == 0) {
          local_13c = 0x800407d6;
          return 0;
        }
      }
    }
  }
  else {
    if (param_3 != 0x3a0) {
      return 0;
    }
    if (param_2 == 0) {
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x3a,local_120);
      if (iVar1 != 0) {
        props_storeIntValue(unaff_ESI,local_120[0],unaff_EDI);
        return 0;
      }
      props_storeIntValue(unaff_ESI,0,unaff_EDI);
      return 0;
    }
    local_13c = props_coerceAndReturnInt(unaff_ESI,unaff_EDI,(int *)local_138);
    if (local_13c == 0) {
      iVar1 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_1,0x3a,local_138);
      if (iVar1 == 0) {
        local_13c = 0x800407d6;
        return 0;
      }
    }
  }
  return 0;
}




// ============================================================
// Function: sprites_dispatchMemberStyle (FUN_68075880)
// Address: 68075880
// Size: 1063 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchMemberStyle(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  int unaff_ESI;
  uint *unaff_EDI;
  int iVar2;
  undefined4 uVar3;
  uint local_44;
  int local_40;
  uint local_3c;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  local_40 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  if (local_40 == 0) goto LAB_68075bc2;
  if (param_1 < 0x279) {
    if (param_1 == 0x278) {
      if (param_2 == 0) {
        iVar1 = Ordinal_294(*(int *)(local_40 + 0x20),*(int *)(local_40 + 0x28),param_3,0x51,
                            local_20);
        if (iVar1 != 0) {
          switch(local_20[0]) {
          case 1:
            local_20[0] = 0xbc;
            props_storeObjectRef(unaff_ESI,0xbc,unaff_EDI);
            return 0;
          case 2:
            local_20[0] = 0x284;
            props_storeObjectRef(unaff_ESI,0x284,unaff_EDI);
            return 0;
          case 3:
            local_20[0] = 0x283;
            props_storeObjectRef(unaff_ESI,0x283,unaff_EDI);
            return 0;
          case 4:
            local_20[0] = 0x23;
          }
          props_storeObjectRef(unaff_ESI,local_20[0],unaff_EDI);
          return 0;
        }
        props_storeObjectRef(unaff_ESI,0,unaff_EDI);
        return 0;
      }
      iVar1 = props_coerceAndReturnFloat(unaff_ESI,unaff_EDI,&local_44);
      if (iVar1 != 0) goto LAB_68075c94;
      if ((int)local_44 < 0x284) {
        if (local_44 == 0x283) {
          local_38[0] = 3;
          uVar3 = 0x51;
        }
        else if (local_44 == 0x23) {
          local_38[0] = 4;
          uVar3 = 0x51;
        }
        else {
          if (local_44 != 0xbc) goto LAB_68075a2a;
          local_38[0] = 1;
          uVar3 = 0x51;
        }
      }
      else {
        if (local_44 == 0x284) {
          local_38[0] = 2;
        }
LAB_68075a2a:
        uVar3 = 0x51;
      }
LAB_68075c3a:
      iVar1 = *(int *)(local_40 + 0x28);
      iVar2 = *(int *)(local_40 + 0x20);
    }
    else if (param_1 == 0x16a) {
      if (param_2 == 0) {
        iVar1 = Ordinal_294(*(int *)(local_40 + 0x20),*(int *)(local_40 + 0x28),param_3,0x53,
                            local_20);
        if (iVar1 != 0) goto LAB_68075c8e;
        goto LAB_68075c8c;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,unaff_EDI,(int *)&local_3c);
      if (iVar1 != 0) goto LAB_68075c94;
      uVar3 = 0x53;
      local_38[0] = local_3c;
      iVar1 = *(int *)(local_40 + 0x28);
      iVar2 = *(int *)(local_40 + 0x20);
    }
    else {
      if (param_1 != 0x16d) {
        if (param_1 == 0x1f7) {
          return 0;
        }
        goto LAB_68075b22;
      }
      if (param_2 == 0) {
        iVar1 = Ordinal_294(*(int *)(local_40 + 0x20),*(int *)(local_40 + 0x28),param_3,0x54,
                            local_20);
        goto joined_r0x68075c84;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,unaff_EDI,(int *)&local_3c);
      if (iVar1 != 0) goto LAB_68075c94;
      uVar3 = 0x54;
      local_38[0] = local_3c;
      iVar1 = *(int *)(local_40 + 0x28);
      iVar2 = *(int *)(local_40 + 0x20);
    }
    iVar1 = Ordinal_293(iVar2,iVar1,param_3,uVar3,local_38);
    if (iVar1 == 0) {
LAB_68075c52:
      return 0;
    }
  }
  else {
    if (param_1 == 0x279) {
      if (param_2 != 0) {
        iVar1 = props_coerceAndReturnInt(unaff_ESI,unaff_EDI,(int *)&local_3c);
        if (iVar1 != 0) goto LAB_68075c94;
        local_38[0] = local_3c;
        uVar3 = 0x55;
        goto LAB_68075c3a;
      }
      iVar1 = Ordinal_294(*(int *)(local_40 + 0x20),*(int *)(local_40 + 0x28),param_3,0x55,local_20)
      ;
joined_r0x68075c84:
      if (iVar1 == 0) {
LAB_68075c8c:
        local_20[0] = 0;
      }
    }
    else {
      if (param_1 != 0x357) {
LAB_68075b22:
        return 0;
      }
      if (param_2 != 0) {
        iVar1 = Ordinal_294(*(int *)(local_40 + 0x20),*(int *)(local_40 + 0x28),param_3,0x52,
                            local_20);
        if (iVar1 == 0) {
LAB_68075bc2:
          return 0;
        }
        if (((int)local_20[0] < 5) || (6 < (int)local_20[0])) goto LAB_68075c52;
        iVar1 = props_coerceAndReturnInt(unaff_ESI,unaff_EDI,(int *)&local_3c);
        if (iVar1 != 0) goto LAB_68075bc2;
        if (local_3c == 0) {
          local_38[0] = 5;
          uVar3 = 0x52;
        }
        else if (local_3c == 1) {
          local_38[0] = 6;
          uVar3 = 0x52;
        }
        else {
          local_38[0] = local_20[0];
          uVar3 = 0x52;
        }
        goto LAB_68075c3a;
      }
      iVar1 = Ordinal_294(*(int *)(local_40 + 0x20),*(int *)(local_40 + 0x28),param_3,0x52,local_20)
      ;
      if ((iVar1 == 0) || (local_20[0] == 5)) goto LAB_68075c8c;
      if (local_20[0] != 6) {
        props_storeIntValue(unaff_ESI,0,unaff_EDI);
        return 0;
      }
      local_20[0] = 1;
    }
LAB_68075c8e:
    props_storeIntValue(unaff_ESI,local_20[0],unaff_EDI);
  }
LAB_68075c94:
  return 0;
}



// ============================================================
// Function: sprites_dispatchMemberData (FUN_68075cc0)
// Address: 68075cc0
// Size: 717 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_dispatchMemberData(void *this,undefined4 param_1)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 local_30;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_8;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  iVar2 = *(int *)((int)this + 8);
  if (0x62f < iVar2) {
switchD_68075d07_caseD_2b9:
    goto LAB_68075f79;
  }
  if (iVar2 == 0x62f) {
switchD_68075d07_caseD_2b4:
    iVar2 = props_coerceToType(unaff_ESI,(int)this,2,&local_24);
    if (iVar2 == 0) {
      puVar4 = (undefined4 *)((int)this + 0xc);
      uVar3 = sprites_getMemberLoopData(unaff_ESI,param_1,local_24 + -1);
      props_storeIntValue(unaff_ESI,uVar3,puVar4);
      return 0;
    }
  }
  else {
    switch(iVar2) {
    case 0x2b4:
      goto switchD_68075d07_caseD_2b4;
    case 0x2b5:
      iVar2 = props_coerceToType(unaff_ESI,(int)this,2,&local_24);
      if (iVar2 == 0) {
        local_10 = local_24;
        Ordinal_294(*(int *)(local_28 + 0x20),*(int *)(local_28 + 0x28),param_1,0x77,&local_20);
        props_storeIntValue(unaff_ESI,local_18,(undefined4 *)((int)this + 0xc));
        return 0;
      }
      break;
    case 0x2b6:
      iVar2 = props_coerceToType(unaff_ESI,(int)this,2,&local_24);
      if (iVar2 == 0) {
        local_18 = local_24;
        Ordinal_294(*(int *)(local_28 + 0x20),*(int *)(local_28 + 0x28),param_1,0x75,&local_20);
        props_storeIntValue(unaff_ESI,local_10,(undefined4 *)((int)this + 0xc));
        return 0;
      }
      break;
    case 0x2b7:
      iVar2 = props_coerceToType(unaff_ESI,(int)this,2,&local_24);
      if (iVar2 == 0) {
        local_14 = local_24;
        Ordinal_294(*(int *)(local_28 + 0x20),*(int *)(local_28 + 0x28),param_1,0x76,&local_20);
        local_2c = local_20;
        local_30 = local_1c;
        props_storeSymbolRef(unaff_ESI,&local_30,(undefined4 *)((int)this + 0xc));
        return 0;
      }
      break;
    case 0x2b8:
      iVar2 = props_coerceToContextState(unaff_ESI,(int)this,2);
      if (iVar2 == 0) {
        local_20 = local_2c;
        local_1c = local_30;
        Ordinal_294(*(int *)(local_28 + 0x20),*(int *)(local_28 + 0x28),param_1,0x74,&local_20);
        props_storeIntValue(unaff_ESI,local_14,(undefined4 *)((int)this + 0xc));
        return 0;
      }
      break;
    default:
      goto switchD_68075d07_caseD_2b9;
    case 699:
      iVar2 = props_coerceToType(unaff_ESI,(int)this,2,&local_24);
      if (iVar2 == 0) {
        bVar1 = local_24 < 1;
        if (bVar1) {
          local_24 = -local_24;
        }
        uVar6 = (uint)bVar1;
        uVar3 = 1;
        pbVar5 = *(byte **)(local_28 + 0x28);
        iVar2 = *(int *)(local_28 + 0x20);
LAB_68075ebc:
        media_resolveAssetEx(iVar2,pbVar5,param_1,uVar3,uVar6,local_24);
        return 0;
      }
      break;
    case 700:
      iVar2 = props_coerceToType(unaff_ESI,(int)this,2,&local_24);
      if (iVar2 == 0) {
        if (local_24 < 1) {
          media_resolveAssetEx(*(int *)(local_28 + 0x20),*(byte **)(local_28 + 0x28),param_1,0,1,-local_24);
          return 0;
        }
        pbVar5 = *(byte **)(local_28 + 0x28);
        iVar2 = *(int *)(local_28 + 0x20);
        uVar3 = 0;
        uVar6 = 0;
        goto LAB_68075ebc;
      }
    }
  }
LAB_68075f79:
  return 0;
}



// ============================================================
// Function: sprites_dispatchMemberRect (FUN_68075fc0)
// Address: 68075fc0
// Size: 222 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMemberRect(undefined4 param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  int local_8;
  
  switch(*(undefined4 *)(in_EAX + 8)) {
  case 0x2c7:
    puVar3 = (undefined4 *)(in_EAX + 0xc);
    uVar1 = sprites_getMemberWidth(unaff_ESI,param_1);
    iVar2 = props_storeIntValue(unaff_ESI,uVar1,puVar3);
    return iVar2;
  case 0x2c8:
    iVar2 = props_coerceToType(unaff_ESI,in_EAX,2,&local_8);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)(in_EAX + 0xc);
      iVar2 = sprites_getMemberCompression(unaff_ESI,param_1,local_8);
      iVar2 = props_storeObjectRef(unaff_ESI,iVar2,puVar3);
      return iVar2;
    }
    break;
  case 0x2c9:
    iVar2 = props_coerceToType(unaff_ESI,in_EAX,2,&local_8);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)(in_EAX + 0xc);
      uVar1 = sprites_getMemberSampleRate(unaff_ESI,param_1,local_8);
      iVar2 = props_storeIntValue(unaff_ESI,uVar1,puVar3);
      return iVar2;
    }
    break;
  case 0x2ca:
    iVar2 = props_coerceToType(unaff_ESI,in_EAX,2,&local_8);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)(in_EAX + 0xc);
      uVar1 = sprites_getMemberSampleSize(unaff_ESI,param_1,local_8);
      iVar2 = props_storeIntValue(unaff_ESI,uVar1,puVar3);
      return iVar2;
    }
    break;
  default:
    iVar2 = -0x7ffbf821;
  }
  return iVar2;
}




// ============================================================
// Function: sprites_dispatchMemberMedia (FUN_680760b0)
// Address: 680760b0
// Size: 1161 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall sprites_dispatchMemberMedia(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int local_b4;
  int local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  int local_a0;
  uint local_9c;
  uint local_98 [13];
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_50;
  int local_4c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_a4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_a0 = param_2;
  Ordinal_1130(local_98 + 0xc,0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar1 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x3b,local_98 + 0xc);
  if (iVar1 != 0) {
    local_a4 = local_98[0xc];
  }
  iVar1 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,5,local_98 + 0xc);
  if (iVar1 != 0) {
    local_18 = local_98[0xc];
    local_14 = local_64;
    local_10 = local_60;
    local_c = local_5c;
  }
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == 0x244) {
    local_98[0] = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_ac = 0;
    local_a8 = 0;
    iVar1 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x3c,local_98 + 0xc);
    if (iVar1 != 0) {
      local_ac = local_98[0xc];
      local_a8 = local_64;
    }
    iVar1 = props_coerceToRect(param_1,param_2,2);
    if (iVar1 != 0) goto LAB_68076518;
    local_98[2] = 0;
    local_98[3] = 0;
    local_98[4] = 0;
    local_98[5] = 0;
    local_98[6] = 0;
    local_98[7] = 0;
    local_98[8] = 0;
    local_98[9] = 0;
    local_98[10] = 0;
    local_98[0xb] = 0;
    local_34 = local_28;
    local_38 = local_24;
    local_30 = local_1c;
    local_2c = local_20;
    local_98[1] = 0;
    iVar1 = Ordinal_1066(&local_38,&local_38,&local_18);
    if (iVar1 == 0) {
      Ordinal_1061(&local_38);
    }
    Ordinal_1656(local_a4,local_98 + 1);
    local_98[0] = Ordinal_1650(local_98[6],local_98[7],local_98[8],local_30 - local_38,
                               local_2c - local_34,0);
    local_a0 = Ordinal_1600();
    local_9c = Ordinal_1600();
    if ((((local_a0 != 0) && (local_9c != 0)) && (local_a4 != 0)) && (local_98[0] != 0)) {
      local_b4 = -local_38;
      local_b0 = -local_34;
      Ordinal_1604(local_a0,local_a4);
      Ordinal_1604(local_9c,local_98[0]);
      Ordinal_1614(local_9c,&local_b4,local_a0,&local_18);
      local_50 = 0;
      Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,6,&local_50);
      local_50 = local_98[0];
      iVar1 = Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x3b,&local_50);
      if (iVar1 == 0) {
        Ordinal_1653(local_98);
      }
      local_50 = 0;
      Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x12,&local_50);
      Ordinal_1604(local_a0,0);
      Ordinal_1604(local_9c,0);
    }
    Ordinal_1601(&local_a0);
    Ordinal_1601(&local_9c);
    local_4c = local_a8 - local_34;
    local_50 = local_ac - local_38;
    Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x3c,&local_50);
    puVar4 = &local_50;
    uVar3 = 0x3d;
    local_50 = 0;
    iVar1 = *(int *)(iVar2 + 0x28);
    iVar2 = *(int *)(iVar2 + 0x20);
  }
  else {
    if (1 < iVar1 - 0x36fU) goto LAB_68076518;
    local_a8 = (uint)(iVar1 == 0x370);
    local_9c = 0xffffffff;
    iVar1 = props_coerceToType(param_1,param_2,2,(int *)local_98);
    if (((iVar1 != 0) || (iVar1 = props_coerceToType(param_1,local_a0,3,&local_b0), iVar1 != 0)) ||
       ((local_a8 != 0 && (iVar1 = props_coerceToType(param_1,local_a0,4,(int *)&local_9c), iVar1 != 0))))
    goto LAB_68076518;
    local_98[0] = local_98[0] - local_18;
    local_b0 = local_b0 - local_14;
    if (local_a8 == 0) {
      Ordinal_1686(local_a4,local_98[0],local_b0,0,&local_a8);
      local_9c = local_a8;
      props_storeIntValue(param_1,local_a8,(undefined4 *)(local_a0 + 0xc));
      goto LAB_68076518;
    }
    Ordinal_1685(local_a4,local_98[0],local_b0,0,local_9c);
    iVar1 = *(int *)(iVar2 + 0x28);
    iVar2 = *(int *)(iVar2 + 0x20);
    puVar4 = (uint *)0x0;
    uVar3 = 10;
  }
  Ordinal_293(iVar2,iVar1,param_3,uVar3,puVar4);
LAB_68076518:
  Ordinal_1653(&local_a4);
  return 0;
}



// ============================================================
// Function: sprites_dispatchMemberFlags (FUN_68076540)
// Address: 68076540
// Size: 148 bytes
// Params: int param_1, undefined4 * param_2, void * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMemberFlags(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = param_1;
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = Ordinal_362(*(int *)(iVar4 + 0x20),*(int *)(iVar4 + 0x28),param_2);
  uVar3 = sprites_setProperty(iVar1,uVar2);
  switch(uVar3) {
  case 1:
    iVar4 = sprites_dispatchMemberMedia(iVar1,(int)param_3,uVar2);
    return iVar4;
  case 3:
  case 7:
    iVar4 = sprites_dispatchMemberData(param_3,uVar2);
    return iVar4;
  case 10:
    iVar4 = sprites_dispatchMemberRect(uVar2);
    return iVar4;
  case 0xb:
  case 0xf:
    iVar4 = Ordinal_220(*(int *)(iVar4 + 0x20),uVar2,param_3,&param_1);
    if (iVar4 != 0) {
      return param_1;
    }
  }
  return -0x7ffbf821;
}



// ============================================================
// Function: sprites_dispatchMemberAttribute (FUN_68076600)
// Address: 68076600
// Size: 21 bytes
// Params: undefined4 param_1, short * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMemberAttribute(undefined4 param_1,short *param_2)
{
  if (*param_2 == 1) {
    *param_2 = 0;
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchProperty (FUN_68076620)
// Address: 68076620
// Size: 39 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_dispatchProperty(int param_1,undefined4 param_2)

{
  param_2 = CONCAT22((short)param_2,(short)((uint)param_2 >> 0x10));
  sprites_checkBounds(param_1,(short *)&param_2);
  return param_2;
}



// ============================================================
// Function: sprites_getPropertyId (FUN_68076650)
// Address: 68076650
// Size: 33 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_getPropertyId(undefined4 param_1,undefined4 param_2)

{
  sprites_dispatchMemberAttribute(param_1,(short *)&param_2);
  return (int)(short)param_2 << 0x10 | (int)(*(unsigned short *)((char *)&param_2 + 2));
}



// ============================================================
// Function: sprites_dispatchColorOp (FUN_68076680)
// Address: 68076680
// Size: 16 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchColorOp(undefined4 param_1,int param_2)
{
  scoreEngine_getPropertyCallback(param_2);
  return 0;
}



// ============================================================
// Function: sprites_dispatchMemberType (FUN_68076690)
// Address: 68076690
// Size: 8 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMemberType(void)
{
  thunk_FUN_680e4be0();
  return 0;
}



// ============================================================
// Function: sprites_dispatchPropertyRouter (FUN_680766a0)
// Address: 680766a0
// Size: 128 bytes
// Params: undefined4 param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchPropertyRouter(undefined4 param_1,undefined1 *param_2)
{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_420 [262];
  uint local_8;
  
  scoreEngine_setPropertyCallback(local_420);
  puVar1 = param_2 + 1;
  Ordinal_1310(local_420,puVar1,0x3fe);
  iVar3 = Ordinal_1201(puVar1);
  param_2[iVar3 + 1] = 0;
  iVar3 = Ordinal_1201(puVar1);
  if (iVar3 < 0xff) {
    uVar2 = Ordinal_1201(puVar1);
    *param_2 = uVar2;
    return 0;
  }
  *param_2 = 0xff;
  return 0;
}



// ============================================================
// Function: sprites_dispatchPropertyByIndex (FUN_68076720)
// Address: 68076720
// Size: 136 bytes
// Params: int param_1, char * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchPropertyByIndex(int param_1,char *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  local_424 = 0;
  iVar1 = sprites_getStageRef(param_1);
  if (iVar1 == 0) {
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = local_420;
      iVar1 = Ordinal_1309(puVar2,0x400,param_2 + 1,2);
      if (iVar1 == 0) goto LAB_6807678b;
      Ordinal_1307(puVar2,0,7,0);
    }
    scoreEngine_getPropertyHandler(puVar2);
  }
LAB_6807678b:
  Ordinal_1113(&local_424);
  return 0;
}



// ============================================================
// Function: sprites_dispatchPropertyByName (FUN_680767b0)
// Address: 680767b0
// Size: 82 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchPropertyByName(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14[0] = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  scoreEngine_getPropertyData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),2,(byte *)local_14);
  return 0;
}



// ============================================================
// Function: sprites_dispatchBitmapProperty (FUN_68076810)
// Address: 68076810
// Size: 73 bytes
// Params: void * this, undefined4 param_1, undefined2 * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_dispatchBitmapProperty(void *this,undefined4 param_1,undefined2 *param_2,undefined4 param_3)
{
  int *piVar1;
  undefined2 *unaff_EBX;
  undefined2 *unaff_EDI;
  
  piVar1 = (int *)sprites_getKeyframeData((int)this,param_1);
  if (piVar1 != (int *)0x0) {
    scoreEngine_readKeyframeProps(piVar1,param_3,param_2,unaff_EBX,unaff_EDI);
    cast_freeHandle(piVar1);
    return 0;
  }
  Ordinal_1130(param_2,0xc);
  *unaff_EBX = 0;
  *unaff_EDI = 0;
  return 0;
}



// ============================================================
// Function: sprites_dispatchFieldProperty (FUN_68076860)
// Address: 68076860
// Size: 66 bytes
// Params: void * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchFieldProperty(void *param_1,undefined4 param_2,undefined4 param_3)
{
  undefined2 local_14 [6];
  uint local_8;
  
  sprites_dispatchBitmapProperty(param_1,param_2,local_14,param_3);
  return 0;
}



// ============================================================
// Function: sprites_dispatchSoundProperty (FUN_680768b0)
// Address: 680768b0
// Size: 68 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined2 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchSoundProperty(undefined4 param_1,undefined4 param_2,undefined2 param_3,int param_4,int param_5)
{
  undefined1 local_14 [4];
  undefined2 local_10;
  uint local_8;
  
  local_10 = param_3;
  sprites_mergeKeyframeData(param_2,4,local_14,param_4,param_5);
  return 0;
}




// ============================================================
// Function: sprites_dispatchShapeProperty (FUN_68076900)
// Address: 68076900
// Size: 66 bytes
// Params: void * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchShapeProperty(void *param_1,undefined4 param_2,undefined4 param_3)
{
  int local_14;
  /* FIXUP(C2040: 'local_14': 'undefined2): undefined2 local_14 [6]; */
  uint local_8;
  
  sprites_dispatchBitmapProperty(param_1,param_2,local_14,param_3);
  return 0;
}



// ============================================================
// Function: sprites_dispatchButtonProperty (FUN_68076950)
// Address: 68076950
// Size: 66 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined1 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchButtonProperty(undefined4 param_1,undefined4 param_2,undefined1 param_3,int param_4,int param_5)
{
  undefined1 local_14 [2];
  undefined1 local_12;
  uint local_8;
  
  local_12 = param_3;
  sprites_mergeKeyframeData(param_2,2,local_14,param_4,param_5);
  return 0;
}



// ============================================================
// Function: sprites_dispatchMovieProperty (FUN_680769a0)
// Address: 680769a0
// Size: 136 bytes
// Params: void * param_1, undefined4 param_2, undefined1 * param_3, undefined4 param_4, short param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchMovieProperty(void *param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4,
                 short param_5)
{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  int local_18;
  undefined2 local_14 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)((int)param_1 + 8) + 4);
  sprites_dispatchBitmapProperty(param_1,param_2,local_14,param_4);
  iVar1 = *(int *)(iVar1 + 0x20);
  local_18 = 0;
  if ((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 0x20), piVar2 != (int *)0x0)) {
    local_18 = *piVar2;
  }
  media_getFontMapData(&local_18,local_14[0],param_3 + 1,0x3fe,param_5);
  uVar3 = Ordinal_1201(param_3 + 1);
  *param_3 = uVar3;
  return 0;
}



// ============================================================
// Function: sprites_dispatchScriptProperty (FUN_68076a30)
// Address: 68076a30
// Size: 118 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4, int param_5, short param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchScriptProperty(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,short param_6)
{
  int iVar1;
  int *piVar2;
  undefined2 local_1c [2];
  int local_18;
  undefined2 local_14 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20);
  local_18 = 0;
  if ((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 0x20), piVar2 != (int *)0x0)) {
    local_18 = *piVar2;
  }
  media_getChannelFontMap(&local_18,param_3 + 1,(int *)local_1c,param_6);
  local_14[0] = local_1c[0];
  sprites_mergeKeyframeData(param_2,1,local_14,param_4,param_5);
  return 0;
}



// ============================================================
// Function: sprites_dispatchTransitionProperty (FUN_68076ab0)
// Address: 68076ab0
// Size: 131 bytes
// Params: int param_1, undefined4 param_2, undefined2 * param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchTransitionProperty(int param_1,undefined4 param_2,undefined2 *param_3,int param_4,int param_5)
{
  int iVar1;
  undefined1 local_14 [6];
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  iVar1 = Ordinal_72(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),param_3,1);
  if (iVar1 != 0) {
    local_e = CONCAT11(*(undefined1 *)param_3,*(undefined1 *)param_3);
    local_c = CONCAT11(*(undefined1 *)((int)param_3 + 1),*(undefined1 *)((int)param_3 + 1));
    local_a = CONCAT11(*(undefined1 *)(param_3 + 1),*(undefined1 *)(param_3 + 1));
    sprites_mergeKeyframeData(param_2,8,local_14,param_4,param_5);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchPaletteProperty (FUN_68076b40)
// Address: 68076b40
// Size: 111 bytes
// Params: void * param_1, undefined4 param_2, undefined4 param_3, undefined1 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x68076b7e) */

int sprites_dispatchPaletteProperty(void *param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)
{
  undefined2 local_18 [8];
  uint local_8;
  
  sprites_dispatchBitmapProperty(param_1,param_2,local_18,param_3);
  return 0;
}



// ============================================================
// Function: sprites_dispatchTextProperty (FUN_68076bb0)
// Address: 68076bb0
// Size: 201 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchTextProperty(int param_1,undefined4 param_2)
{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint local_30 [2];
  byte *local_28;
  int *local_24;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_24 = (int *)props_getRectCount(param_1);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x79,local_20);
  if ((iVar1 != 0) && (local_20[0] != 0)) {
    pbVar2 = (byte *)Ordinal_1114(local_20[0]);
    uVar3 = 0;
    local_28 = pbVar2;
    if (*(int *)(pbVar2 + 0x1c) != 0) {
      do {
        pbVar2 = pbVar2 + 0x28;
        props_readPascalString(param_1,pbVar2,local_30);
        props_setListEntry(param_1,local_24,local_30);
        props_releaseAndClear(param_1,(int *)local_30);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(local_28 + 0x1c));
    }
    Ordinal_1115(local_20[0]);
    Ordinal_1113(local_20);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchVectorProperty (FUN_68076c80)
// Address: 68076c80
// Size: 202 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchVectorProperty(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  int *local_24;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_24 = (int *)props_getRectCount(param_1);
  iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x79,local_20);
  if ((iVar1 != 0) && (local_20[0] != 0)) {
    local_28 = Ordinal_1114(local_20[0]);
    uVar3 = 0;
    if (*(int *)(local_28 + 0x1c) != 0) {
      puVar2 = (undefined4 *)(local_28 + 0x24);
      do {
        local_30 = 4;
        local_2c = *puVar2;
        props_setListEntry(param_1,local_24,&local_30);
        props_releaseAndClear(param_1,(int *)&local_30);
        uVar3 = uVar3 + 1;
        puVar2 = puVar2 + 10;
      } while (uVar3 < *(uint *)(local_28 + 0x1c));
    }
    Ordinal_1115(local_20[0]);
    Ordinal_1113(local_20);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchFlashProperty (FUN_68076d50)
// Address: 68076d50
// Size: 146 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchFlashProperty(int param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar1 = Ordinal_362(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),param_2);
  iVar2 = sprites_setProperty(param_1,uVar1);
  if (iVar2 == 0xf) {
    iVar3 = Ordinal_294(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),uVar1,0x37,local_20);
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchCursorProperty (FUN_68076df0)
// Address: 68076df0
// Size: 209 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchCursorProperty(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 1;
  }
  iVar2 = sprites_setProperty(param_1,param_2);
  if ((iVar2 != 3) && (iVar2 != 7)) {
    if ((iVar2 != 0) || (31999 < (ushort)((*(unsigned short *)((char *)&param_2 + 2)) - 1U))) {
      Ordinal_1130(local_20,0x18);
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 0;
        return 0;
      }
      goto LAB_68076e83;
    }
    sprites_importMemberFromFile(param_1,param_2,0x2d);
  }
  local_20[0] = 0;
  local_20[2] = 0;
  Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x31,local_20);
LAB_68076e83:
  return 0;
}



// ============================================================
// Function: sprites_dispatchFontProperty (FUN_68076ed0)
// Address: 68076ed0
// Size: 28 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchFontProperty(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = sprites_dispatchCursorProperty(param_1,param_2,(undefined4 *)0x0);
  sprites_convertToString(iVar1);
  return 0;
}



// ============================================================
// Function: sprites_dispatchPropertyByType (FUN_68076ef0)
// Address: 68076ef0
// Size: 533 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchPropertyByType(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int iVar7;
  int *local_85c;
  uint local_850 [12];
  undefined1 local_820 [24];
  undefined1 local_808;
  undefined1 local_807 [1023];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_850[6] = 0;
  local_850[7] = 0;
  local_850[8] = 0;
  local_850[9] = 0;
  local_850[10] = 0;
  local_850[0xb] = 0;
  local_850[0] = 0;
  local_850[1] = 0;
  local_850[2] = 0;
  local_850[3] = 0;
  local_850[4] = 0;
  local_850[5] = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_85c = (int *)0x0;
  iVar2 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,6,local_850);
  if (iVar2 == 0) goto LAB_680770ec;
  iVar2 = sprites_getMemberNameById(param_1,param_2,local_408);
  piVar3 = (int *)sprites_setPropertyDirect(param_1,param_2);
  if (param_3 == 0) {
    if (local_850[0] != 0) {
      sprites_getMemberFileName(param_1,param_2,&local_808);
      pbVar6 = *(byte **)(iVar1 + 0x28);
      iVar4 = *(int *)(iVar1 + 0x20);
      iVar7 = 0;
      puVar5 = local_807;
      goto LAB_68077008;
    }
  }
  else {
    iVar4 = Ordinal_1309(local_820,0x400,param_3 + 1,2);
    if (iVar4 != 0) {
      local_85c = (int *)Ordinal_138(*(int *)(iVar1 + 0x20),local_820);
    }
    if (local_850[0] == 0) {
      pbVar6 = *(byte **)(iVar1 + 0x28);
      iVar4 = *(int *)(iVar1 + 0x20);
      iVar7 = 1;
      puVar5 = (undefined1 *)(param_3 + 1);
LAB_68077008:
      iVar4 = scoreEngine_getPropertyExData(iVar4,pbVar6,param_2,puVar5,iVar7,(int *)0x5);
      if (iVar4 == 0) goto LAB_680770ca;
    }
    if (iVar2 != 0) {
      sprites_setMemberFrameIndex(param_1,param_2,(int)local_408);
    }
    if (piVar3 != (int *)0x0) {
      sprites_updateMemberScriptDirect(param_1,param_2,piVar3);
    }
    if (param_3 != 0) {
      local_850[6] = param_3 + 1;
      local_850[7] = 2;
      iVar2 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,8,local_850 + 6);
      if (iVar2 == 0) goto LAB_680770ca;
    }
    Ordinal_104(*(int *)(iVar1 + 0x20),0x1000);
  }
LAB_680770ca:
  if (piVar3 != (int *)0x0) {
    cast_freeHandle(piVar3);
  }
  if (local_85c != (int *)0x0) {
    (**(code **)(*local_85c + 8))(local_85c);
  }
LAB_680770ec:
  return 0;
}




// ============================================================
// Function: sprites_dispatchExtPropertyByType (FUN_68077110)
// Address: 68077110
// Size: 443 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchExtPropertyByType(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_20 [6];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = sprites_setProperty(param_1,param_2);
  switch(uVar2) {
  case 1:
    return 0;
  case 2:
    return 0;
  case 3:
    return 0;
  case 4:
    return 0;
  case 5:
    return 0;
  case 6:
    return 0;
  case 7:
    return 0;
  case 8:
    return 0;
  case 9:
    return 0;
  case 10:
    return 0;
  case 0xb:
    return 0;
  case 0xc:
    return 0;
  case 0xd:
    return 0;
  case 0xe:
    iVar3 = scoreEngine_getPropertyRect(*(int *)(iVar1 + 0x20),(short)param_2);
    if (iVar3 != 0) {
      return 0;
    }
switchD_6807713e_caseD_f:
    Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x34,local_20);
    return 0;
  case 0xf:
    goto switchD_6807713e_caseD_f;
  default:
    return 0;
  }
}



// ============================================================
// Function: sprites_dispatchBitmapColor (FUN_68077310)
// Address: 68077310
// Size: 69 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_dispatchBitmapColor(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar1 = Ordinal_362(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2);
  iVar2 = sprites_setPropertyDirect(param_1,uVar1);
  if (iVar2 != 0) {
    cast_freeHandle(iVar2);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchBitmapRect (FUN_68077360)
// Address: 68077360
// Size: 140 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchBitmapRect(int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = param_1;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 == (int *)0x0) {
    Ordinal_279(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*param_3,(short)*param_4,0);
    return 0;
  }
  param_4 = (undefined4 *)cast_getMemberData(param_1,param_2);
  iVar5 = 1;
  if (0 < (int)param_4) {
    do {
      iVar3 = cast_getMemberRef(iVar2,param_2,iVar5,&param_1);
      if (iVar3 == 0) {
        return 0;
      }
      uVar4 = sprites_dispatchProperty(iVar2,param_1);
      Ordinal_279(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar4,(short)uVar4,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 <= (int)param_4);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchBitmapMedia (FUN_680773f0)
// Address: 680773f0
// Size: 164 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchBitmapMedia(int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,int param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = param_1;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_2 == (int *)0x0) {
    uVar4 = Ordinal_278(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),*param_3,(short)*param_4,
                        (uint)(param_6 != 0));
    *param_5 = uVar4;
    return 0;
  }
  param_4 = (undefined4 *)cast_getMemberData(param_1,param_2);
  iVar5 = 1;
  if (0 < (int)param_4) {
    do {
      iVar3 = cast_getMemberRef(iVar2,param_2,iVar5,&param_1);
      if (iVar3 == 0) {
        return 0;
      }
      uVar4 = sprites_dispatchProperty(iVar2,param_1);
      uVar4 = Ordinal_278(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),uVar4,(short)uVar4,
                          (uint)(param_6 != 0));
      iVar5 = iVar5 + 1;
      *param_5 = uVar4;
    } while (iVar5 <= (int)param_4);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchBitmapFlags (FUN_680774a0)
// Address: 680774a0
// Size: 2095 bytes
// Params: int param_1, int param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchBitmapFlags(int param_1,int param_2,undefined4 param_3,uint *param_4)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *unaff_EDI;
  uint *puVar5;
  uint local_44;
  uint *local_40;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  iVar2 = *(int *)(*(int *)((int)unaff_EDI + 8) + 4);
  local_40 = param_4;
  if (iVar2 == 0) {
    return 0;
  }
  if (param_1 < 0x349) {
    if (param_1 == 0x348) {
      if (param_2 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x42,&local_20);
        props_storeIntValue(unaff_EDI,local_20 & 0xff,local_40);
        return 0;
      }
      iVar4 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_3c);
      if (iVar4 == 0) {
        local_38 = CONCAT31((*(unsigned int *)((char *)&local_38 + 1)),(undefined1)local_3c);
        uVar1 = 0x42;
LAB_6807763a:
        Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,uVar1,&local_38);
        return 0;
      }
    }
    else if (param_1 < 0x292) {
      if (param_1 == 0x291) {
        if (param_2 != 0) {
          cast_renderXtraBitmap(unaff_EDI,param_4,param_3);
          return 0;
        }
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x7a,&local_20);
        if (local_20 == 0) {
          return 0;
        }
        iVar2 = cast_createFromStack();
        if (iVar2 == 0) {
          return 0;
        }
      }
      else if (param_1 == 0xa9) {
        if (param_2 == 0) {
          sprites_getMemberField((int)unaff_EDI,param_3,&local_44);
          props_storeSymbolValue((int)unaff_EDI,local_44,local_40);
          return 0;
        }
        iVar4 = props_coerceToShort((int)unaff_EDI,param_4,(int *)&local_44);
        if (iVar4 == 0) {
          Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x3e,&local_20);
          sprites_setMemberField((int)unaff_EDI,param_3,local_44);
          local_38 = local_20;
          local_34 = local_1c;
          uVar1 = 0x3e;
          goto LAB_6807763a;
        }
      }
      else {
        if (param_1 != 0x170) {
          if (param_1 == 0x209) {
            if (param_2 != 0) {
              props_reportError((int)unaff_EDI,0x39);
              return 0;
            }
            uVar1 = sprites_getMemberFrameRate((int)unaff_EDI,param_3);
            props_storeIntValue(unaff_EDI,uVar1,param_4);
            return 0;
          }
          goto switchD_680778d3_caseD_35d;
        }
        if (param_2 == 0) {
          sprites_getMemberMediaRef((int)unaff_EDI,param_3,&local_3c);
          puVar5 = local_40;
          uVar3 = sprites_getPropertyId(unaff_EDI,local_3c);
          props_storeIntValue(unaff_EDI,uVar3,puVar5);
          return 0;
        }
        iVar2 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_40);
        if (iVar2 == 0) {
          local_3c = sprites_dispatchProperty((int)unaff_EDI,local_40);
          sprites_setMemberMediaRef((int)unaff_EDI,param_3,&local_3c);
          return 0;
        }
      }
    }
    else if (param_1 == 0x2da) {
      if (param_2 == 0) {
        sprites_getMemberMediaRef((int)unaff_EDI,param_3,&local_3c);
        cast_getScoreXtraData((int)unaff_EDI,(short *)&local_3c);
        return 0;
      }
      iVar2 = cast_applyXtraFormatCode();
      if (iVar2 == 0) {
        sprites_setMemberMediaRef((int)unaff_EDI,param_3,&local_3c);
        return 0;
      }
    }
    else {
      if (param_1 != 0x347) goto switchD_680778d3_caseD_35d;
      if (param_2 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_20);
        props_storeIntValue(unaff_EDI,local_10,local_40);
        return 0;
      }
      iVar4 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_3c);
      if (iVar4 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_20);
        local_38 = local_20;
        local_2c = local_14;
        local_34 = local_1c;
        local_28 = (uint)(local_3c != 0);
        local_30 = local_18;
        local_24 = local_c;
        Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_38);
        return 0;
      }
    }
  }
  else {
    switch(param_1) {
    case 0x35c:
      if (param_2 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_20);
        props_storeIntValue(unaff_EDI,local_20,local_40);
        return 0;
      }
      iVar4 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_3c);
      if (iVar4 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_20);
        local_2c = local_14;
        local_34 = local_1c;
        local_38 = (uint)(local_3c != 0);
        local_30 = local_18;
        local_28 = local_10;
        local_24 = local_c;
        Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_38);
        return 0;
      }
      break;
    default:
switchD_680778d3_caseD_35d:
      return 0;
    case 0x373:
      if (param_2 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x3d,&local_20);
        props_storeIntValue(unaff_EDI,local_20,local_40);
      }
      else {
        iVar4 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_3c);
        if (iVar4 == 0) {
          local_38 = (uint)(local_3c != 0);
          uVar1 = 0x3d;
LAB_68077c58:
          Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,uVar1,&local_38);
          return 0;
        }
      }
      break;
    case 0x38a:
      if (param_2 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_20);
        props_storeIntValue(unaff_EDI,(uint)(local_c == 0),local_40);
        return 0;
      }
      iVar4 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_3c);
      if (iVar4 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_20);
        local_38 = local_20;
        local_2c = local_14;
        local_34 = local_1c;
        local_24 = (uint)(local_3c == 0);
        local_30 = local_18;
        local_28 = local_10;
        Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x41,&local_38);
        return 0;
      }
      break;
    case 0x398:
      if (param_2 == 0) {
        iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x1f,&local_20);
        if (iVar2 != 0) {
          if (local_20 == 0xfd) {
            props_storeObjectRef(unaff_EDI,0x39c,local_40);
            return 0;
          }
          if (local_20 != 0xfe) {
            props_storeObjectRef(unaff_EDI,0x39a,local_40);
            return 0;
          }
          props_storeObjectRef(unaff_EDI,0x39b,local_40);
          return 0;
        }
      }
      else {
        iVar4 = props_coerceAndReturnFloat((int)unaff_EDI,param_4,&local_3c);
        if (iVar4 == 0) {
          if (local_3c == 0x39a) {
            local_38 = 0xfb;
            uVar1 = 0x1f;
          }
          else if (local_3c == 0x39b) {
            local_38 = 0xfe;
            uVar1 = 0x1f;
          }
          else {
            if (local_3c != 0x39c) goto LAB_68077903;
            local_38 = 0xfd;
            uVar1 = 0x1f;
          }
          goto LAB_68077c58;
        }
      }
      break;
    case 0x399:
      if (param_2 == 0) {
        Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x20,&local_20);
        if ((-1 < (int)local_20) && ((int)local_20 < 0x65)) {
          props_storeIntValue(unaff_EDI,local_20,local_40);
          return 0;
        }
        props_storeObjectRef(unaff_EDI,0x7e,local_40);
        return 0;
      }
      iVar4 = props_coerceAndReturnInt((int)unaff_EDI,param_4,(int *)&local_3c);
      if (iVar4 == 0) {
        if (local_3c < 0x65) {
          local_38 = local_3c;
          Ordinal_293(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x20,&local_38);
          return 0;
        }
LAB_68077903:
        return 0;
      }
    }
  }
  return 0;
}




// ============================================================
// Function: sprites_dispatchFieldRect (FUN_68077d30)
// Address: 68077d30
// Size: 234 bytes
// Params: undefined4 param_1, int * param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchFieldRect(int *param_1,int *param_2,int *param_3,int *param_4)
{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  int local_40;
  int *local_3c;
  int local_38;
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
  
  iVar1 = *param_2;
  local_38 = *(int *)(iVar1 + 0x18);
  local_34 = *(undefined4 *)(iVar1 + 0x1c);
  local_30 = *(undefined4 *)(iVar1 + 0x20);
  local_2c = *(undefined4 *)(iVar1 + 0x24);
  local_28 = *(undefined4 *)(iVar1 + 0x28);
  local_24 = *(undefined4 *)(iVar1 + 0x2c);
  local_20 = *(undefined4 *)(iVar1 + 0x30);
  local_1c = *(undefined4 *)(iVar1 + 0x34);
  local_18 = *(undefined4 *)(iVar1 + 0x38);
  local_14 = *(undefined4 *)(iVar1 + 0x3c);
  local_10 = *(undefined4 *)(iVar1 + 0x40);
  local_c = *(undefined4 *)(iVar1 + 0x44);
  local_3c = param_1;
  iVar1 = sprites_getMemberInfo(unaff_EDI,(undefined4 *)(iVar1 + 0x10));
  *param_4 = iVar1;
  if (*(int *)(*param_2 + 0x14) == 6) {
    puVar2 = (undefined4 *)sprites_dispatchCursorProperty(unaff_EDI,iVar1,(undefined4 *)0x0);
    if (puVar2 != (undefined4 *)0x0) {
      *param_3 = 0;
      local_40 = Ordinal_1116(puVar2);
      *local_3c = local_40;
      score_registerAllHandlers(unaff_EDI,&local_38,param_3,local_3c,(byte *)*puVar2,&local_40);
      return 0;
    }
  }
  else {
    props_setError(unaff_EDI,0x13);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchFieldFlags (FUN_68077e20)
// Address: 68077e20
// Size: 906 bytes
// Params: int param_1, int * param_2, uint * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchFieldFlags(int param_1,int *param_2,uint *param_3)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  bool bVar5;
  uint local_42c;
  uint local_428;
  uint local_424;
  uint local_420;
  uint local_41c;
  undefined4 local_418;
  byte local_414 [3];
  char local_411;
  int local_410;
  int local_40c;
  byte local_408 [1024];
  uint local_8;
  
  bVar5 = param_3 != (uint *)0x0;
  iVar2 = sprites_dispatchFieldRect(&local_418,param_2,&local_410,&local_40c);
  if (iVar2 != 0) {
    iVar2 = props_getTypedValue(param_1,2,8,&local_420);
    if (iVar2 != 0) {
      if ((!bVar5) &&
         (puVar4 = (uint *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                           *(int *)(param_1 + 0x18)), param_3 = (uint *)0x0, puVar4 != (uint *)0x0))
      {
        local_42c = *puVar4;
        local_428 = puVar4[1];
        param_3 = &local_42c;
      }
      if ((int)local_420 < 0x2f0) {
        if (local_420 == 0x2ef) {
          if (bVar5) {
            sprites_getMemberString(param_1,local_40c,local_408,local_410);
            props_readPascalString(param_1,local_408,param_3);
            return 0;
          }
          iVar2 = crt_getPlatformData(param_1,(int *)param_3,local_408);
          if (iVar2 != 0) {
            sprites_setMemberString(param_1,local_40c,(int)local_408,local_410,local_418);
            return 0;
          }
          goto LAB_68078197;
        }
        if (local_420 == 0xbe) {
          if (bVar5) {
            sprites_getPropertyValue(param_1,local_40c,local_410,(undefined4 *)local_414);
            props_storeFloatValue(param_1,(undefined4 *)local_414,param_3);
            return 0;
          }
          iVar2 = props_coerceAndStore(param_1,param_3,(int *)local_414);
          if (iVar2 == 0) {
            sprites_setPropertyValue(param_1,local_40c,(uint *)local_414,local_410,local_418);
            return 0;
          }
          goto LAB_68078197;
        }
        if (local_420 != 0x168) goto LAB_6807808a;
        if (!bVar5) {
          iVar2 = props_coerceAndReturnBool(param_1,param_3,local_414);
          if (iVar2 == 0) {
            sprites_setPropertyValue(param_1,local_40c,(uint *)local_414,local_410,local_418);
            return 0;
          }
          goto LAB_68078197;
        }
        sprites_getPropertyValue(param_1,local_40c,local_410,(undefined4 *)local_414);
        if (local_411 != '\0') {
          events_manageCastMember(param_1,(undefined2 *)local_414,0);
        }
        uVar3 = (uint)local_414[0];
      }
      else {
        if (local_420 != 0x2f0) {
          if (local_420 != 0x2f1) {
LAB_6807808a:
            props_reportError(param_1,0x37);
            return 0;
          }
          if (bVar5) {
            uVar1 = sprites_getMemberFlags(param_1,local_40c,local_410);
            local_41c = (uint)uVar1;
            cast_buildFormatString(param_1,uVar1,param_3);
            return 0;
          }
          iVar2 = cast_parseFormatFlags(param_1,param_3,(short *)&local_41c);
          if (iVar2 == 0) {
            sprites_setMemberFlags(param_1,local_40c,(byte)local_41c,local_410,local_418);
            return 0;
          }
          goto LAB_68078197;
        }
        if (!bVar5) {
          iVar2 = props_coerceAndReturnInt(param_1,param_3,(int *)&local_424);
          if (iVar2 == 0) {
            sprites_setMemberMediaData(param_1,local_40c,local_424,local_410,local_418);
            return 0;
          }
          goto LAB_68078197;
        }
        uVar3 = sprites_getMemberMediaData(param_1,local_40c,local_410);
      }
      props_storeIntValue(param_1,uVar3,param_3);
    }
  }
LAB_68078197:
  return 0;
}



// ============================================================
// Function: sprites_dispatchSoundMedia (FUN_680781b0)
// Address: 680781b0
// Size: 22 bytes
// Params: int param_1, int * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchSoundMedia(int param_1,int *param_2,uint *param_3)
{
  sprites_dispatchFieldFlags(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: sprites_dispatchShapeColor (FUN_680781d0)
// Address: 680781d0
// Size: 20 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchShapeColor(int param_1,int *param_2)
{
  sprites_dispatchFieldFlags(param_1,param_2,(uint *)0x0);
  return 0;
}




// ============================================================
// Function: sprites_dispatchShapeRect (FUN_680781f0)
// Address: 680781f0
// Size: 3488 bytes
// Params: void * this, int param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_dispatchShapeRect(void *this,int param_1,int param_2,int param_3,uint *param_4)
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  short sVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint *puVar10;
  uint local_460;
  uint local_45c [2];
  uint local_454;
  void *local_450;
  void *local_44c;
  uint local_448;
  byte local_444 [3];
  char local_441;
  int local_440;
  int local_43c;
  uint local_438 [6];
  uint local_420 [6];
  byte local_408 [1024];
  uint local_8;
  
  local_43c = param_1;
  local_440 = *(int *)(*(int *)((int)this + 8) + 4);
  if (local_440 == 0) {
    return 0;
  }
  if (param_3 < 0x179) {
    if (param_3 == 0x178) {
switchD_680784b1_caseD_2f1:
      if (param_2 == 0) {
        uVar4 = sprites_getMemberFlags((int)this,param_1,0);
        local_44c = (void *)(uint)uVar4;
        iVar7 = cast_buildFormatString((int)this,uVar4,param_4);
      }
      else {
        iVar7 = cast_parseFormatFlags((int)this,param_4,(short *)&local_44c);
        if (iVar7 == 0) {
          sprites_setMemberFlags((int)this,local_43c,(byte)local_44c,0,0x7fff);
          goto LAB_6807873a;
        }
      }
    }
    else {
      switch(param_3) {
      case 0xbe:
        if (param_2 == 0) {
          sprites_getPropertyValue((int)this,param_1,0,(undefined4 *)local_444);
          iVar7 = props_storeFloatValue((int)this,(undefined4 *)local_444,param_4);
        }
        else {
          iVar7 = props_coerceAndStore((int)this,param_4,(int *)local_444);
          if (iVar7 == 0) {
            sprites_setPropertyValue((int)this,local_43c,(uint *)local_444,0,0xffff);
            goto LAB_6807873a;
          }
        }
        break;
      default:
        goto switchD_6807826c_caseD_bf;
      case 0xfb:
        if (param_2 == 0) {
          puVar6 = (undefined4 *)sprites_dispatchFontProperty((int)this,param_1);
          if (puVar6 == (undefined4 *)0x0) {
            props_returnWithValue((int)this,0x800407d7,(uint *)0x0);
          }
          else {
            props_getExtPair((int)this,puVar6,param_4);
          }
          goto LAB_6807873a;
        }
        iVar7 = props_coerceAndReturnSymbol((int)this,param_4,&local_44c);
        if (iVar7 == 0) {
          if (local_44c != (void *)0x0) {
            sprites_setMemberHilite((int)this,local_43c,(uint)local_44c);
            props_freeStringAndReturn(this,param_4,local_44c);
          }
          goto LAB_6807873a;
        }
        break;
      case 0x168:
        if (param_2 == 0) {
          sprites_getPropertyValue((int)this,param_1,0,(undefined4 *)local_444);
          if (local_441 != '\0') {
            events_manageCastMember((int)this,(undefined2 *)local_444,0);
          }
          iVar7 = props_storeIntValue(this,(uint)local_444[0],param_4);
        }
        else {
          iVar7 = props_coerceAndReturnBool((int)this,param_4,local_444);
          if (iVar7 == 0) {
            sprites_setPropertyValue((int)this,local_43c,(uint *)local_444,0,0xffff);
            goto LAB_6807873a;
          }
        }
        break;
      case 0x169:
        if (param_2 == 0) {
          sprites_getMemberBlendValue((int)this,param_1,(undefined4 *)local_444);
          if (local_441 != '\0') {
            events_manageCastMember((int)this,(undefined2 *)local_444,0);
          }
          iVar7 = props_storeIntValue(this,(uint)local_444[0],param_4);
        }
        else {
          iVar7 = props_coerceAndReturnBool((int)this,param_4,local_444);
          if (iVar7 == 0) {
            sprites_setMemberBlendValue((int)this,local_43c,(uint *)local_444);
            goto LAB_6807873a;
          }
        }
      }
    }
    goto LAB_68078664;
  }
  if (param_3 < 0x2b5) {
    if (param_3 != 0x2b4) {
      switch(param_3) {
      case 0x179:
        goto switchD_68078444_caseD_179;
      case 0x17a:
        break;
      case 0x17b:
        goto switchD_68078444_caseD_17b;
      case 0x17c:
        goto switchD_68078444_caseD_17c;
      default:
        goto switchD_6807826c_caseD_bf;
      }
    }
    if (param_2 == 0) {
      puVar10 = param_4;
      uVar8 = sprites_getMemberLoopData((int)this,param_1,0);
      iVar7 = props_storeIntValue(this,uVar8,puVar10);
    }
    else {
      iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
      if (iVar7 == 0) {
        sprites_setMemberLoopData((int)this,local_43c,local_448);
        goto LAB_6807873a;
      }
    }
    goto LAB_68078664;
  }
  switch(param_3) {
  case 0x2ee:
switchD_68078444_caseD_17b:
    if (param_2 == 0) {
      puVar10 = param_4;
      sVar5 = sprites_getMemberCenterCrop((int)this,param_1);
      iVar7 = cast_convertTypeToString((int)this,sVar5,puVar10);
    }
    else {
      iVar7 = cast_resolveIdentifierFlag((int)this,param_4,(ushort *)&local_450);
      if (iVar7 == 0) {
        sprites_setMemberCenterCrop((int)this,local_43c,(int)(short)local_450);
        goto LAB_6807873a;
      }
    }
    break;
  case 0x2ef:
switchD_68078444_caseD_179:
    if (param_2 == 0) {
      sprites_getMemberString((int)this,param_1,local_408,0);
      props_readPascalString((int)this,local_408,param_4);
    }
    else {
      iVar7 = crt_getPlatformData((int)this,(int *)param_4,local_408);
      if (iVar7 != 0) {
        sprites_setMemberString((int)this,local_43c,(int)local_408,0,0x7fff);
      }
    }
    goto LAB_6807873a;
  case 0x2f0:
switchD_68078444_caseD_17c:
    if (param_2 == 0) {
      puVar10 = param_4;
      uVar8 = sprites_getMemberMediaData((int)this,param_1,0);
      iVar7 = props_storeIntValue(this,uVar8,puVar10);
    }
    else {
      iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
      if (iVar7 == 0) {
        sprites_setMemberMediaData((int)this,local_43c,local_448,0,0x7fff);
        goto LAB_6807873a;
      }
    }
    break;
  case 0x2f1:
    goto switchD_680784b1_caseD_2f1;
  default:
    goto switchD_6807826c_caseD_bf;
  case 0x359:
    if (param_2 == 0) {
      sprites_getMemberBlendValue((int)this,param_1,(undefined4 *)local_444);
      iVar7 = props_storeFloatValue((int)this,(undefined4 *)local_444,param_4);
    }
    else {
      iVar7 = props_coerceAndStore((int)this,param_4,(int *)local_444);
      if (iVar7 == 0) {
        sprites_setMemberBlendValue((int)this,local_43c,(uint *)local_444);
        goto LAB_6807873a;
      }
    }
  }
LAB_68078664:
  if (iVar7 == -0x7ffbf82b) {
switchD_6807826c_caseD_bf:
    iVar7 = sprites_setProperty((int)this,local_43c);
    if (iVar7 == 7) {
      if (param_3 != 0x277) {
switchD_68078c05_caseD_26e:
        goto LAB_6807873a;
      }
      if (param_2 == 0) {
        iVar7 = Ordinal_294(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x66,
                            local_438);
        if (iVar7 != 0) {
          if (local_438[0] == 1) {
            local_438[0] = 0x280;
            props_storeObjectRef(this,0x280,param_4);
          }
          else if (local_438[0] == 2) {
            local_438[0] = 0x281;
            props_storeObjectRef(this,0x281,param_4);
          }
          else if (local_438[0] == 3) {
            local_438[0] = 0x282;
            props_storeObjectRef(this,0x282,param_4);
          }
          else {
            local_438[0] = 0;
            props_storeObjectRef(this,0,param_4);
          }
          goto LAB_6807873a;
        }
LAB_680787dc:
        props_storeObjectRef(this,0,param_4);
        goto LAB_6807873a;
      }
      iVar7 = props_coerceAndReturnFloat((int)this,param_4,&local_460);
      if (local_460 == 0x280) {
        local_420[0] = 1;
      }
      else if (local_460 == 0x281) {
        local_420[0] = 2;
      }
      else if (local_460 == 0x282) {
        local_420[0] = 3;
      }
      else {
        local_420[0] = 0;
      }
      uVar8 = 0x66;
LAB_680786fe:
      Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,uVar8,local_420);
      goto LAB_68078718;
    }
    if (0x26b < param_3) {
      switch(param_3) {
      case 0x26c:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,99,local_420
                       );
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 99;
        break;
      case 0x26d:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x6f,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 0x6f;
        break;
      default:
        goto switchD_68078c05_caseD_26e;
      case 0x26f:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x67,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 0x67;
        break;
      case 0x270:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,100,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 100;
        break;
      case 0x271:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x61,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 0x61;
        break;
      case 0x273:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x68,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 0x68;
        break;
      case 0x2b3:
        if (param_2 != 0) {
LAB_68078f55:
          props_reportError((int)this,0x39);
          return 0;
        }
        uVar9 = 0x6d;
        break;
      case 0x2b9:
        if (param_2 != 0) goto LAB_68078f55;
        uVar9 = 0x33;
        break;
      case 0x2ba:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x32,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 0x32;
        break;
      case 0x2f2:
        if (param_2 != 0) {
          iVar7 = props_coerceAndReturnInt((int)this,param_4,(int *)&local_448);
          if (iVar7 == 0) {
            local_420[0] = local_448;
            Ordinal_293(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x71,
                        local_420);
            goto LAB_6807873a;
          }
          goto LAB_6807871c;
        }
        uVar9 = 0x71;
      }
      iVar7 = Ordinal_294(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,uVar9,
                          local_438);
      if (iVar7 == 0) {
        props_storeIntValue(this,0,param_4);
      }
      else {
        props_storeIntValue(this,local_438[0],param_4);
      }
      goto LAB_6807873a;
    }
    if (param_3 == 0x26b) {
      if (param_2 == 0) {
        iVar7 = Ordinal_294(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x65,
                            local_438);
        if (iVar7 != 0) {
          switch(local_438[0]) {
          case 0:
            local_438[0] = 0x287;
            props_storeObjectRef(this,0x287,param_4);
            break;
          case 1:
            local_438[0] = 0x26e;
            props_storeObjectRef(this,0x26e,param_4);
            break;
          case 2:
            local_438[0] = 0x288;
            props_storeObjectRef(this,0x288,param_4);
            break;
          case 3:
            local_438[0] = 0x289;
            props_storeObjectRef(this,0x289,param_4);
            break;
          default:
            local_438[0] = 0;
            props_storeObjectRef(this,0,param_4);
          }
          goto LAB_6807873a;
        }
        goto LAB_680787dc;
      }
      iVar7 = props_coerceAndReturnFloat((int)this,param_4,&local_460);
      switch(local_460) {
      case 0x26e:
        local_420[0] = 1;
        uVar8 = 0x65;
        break;
      default:
        local_420[0] = 0;
        uVar8 = 0x65;
        break;
      case 0x288:
        local_420[0] = 2;
        uVar8 = 0x65;
        break;
      case 0x289:
        local_420[0] = 3;
        uVar8 = 0x65;
      }
      goto LAB_680786fe;
    }
    if (param_3 == 0xa9) {
      if (param_2 == 0) {
        sprites_getMemberField((int)this,local_43c,&local_454);
        props_storeSymbolValue((int)this,local_454,param_4);
        goto LAB_6807873a;
      }
      iVar7 = props_coerceToShort((int)this,param_4,(int *)&local_454);
      if (iVar7 == 0) {
        sprites_setMemberField((int)this,local_43c,local_454);
        goto LAB_6807873a;
      }
    }
    else {
      if (param_3 != 0x1b1) goto switchD_68078c05_caseD_26e;
      if (param_2 == 0) {
        media_getAssetData(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,&local_44c,
                     &local_450);
        if ((local_44c == (void *)0x0) && (local_450 == (void *)0x0)) {
          local_450 = (void *)media_lookupAsset(*(int *)(local_440 + 0x20),*(byte **)(local_440 + 0x28),
                                           local_43c);
          local_44c = local_450;
        }
        iVar7 = Ordinal_294(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x70,
                            local_438);
        if (iVar7 != 0) {
          local_44c = (void *)xtra_getTextBlockRef(local_438[0]);
          local_450 = (void *)xtra_getTextBlockRef(local_438[0]);
        }
        props_getContextRef((int)this,(int *)param_4);
        props_storeIntValue(this,local_44c,local_45c);
        props_dispatchMethod(this,param_4,local_45c);
        props_storeIntValue(this,local_450,local_45c);
        props_dispatchMethod(this,param_4,local_45c);
        goto LAB_6807873a;
      }
      iVar7 = props_resolveRef(this,param_4);
      if (iVar7 != 2) goto LAB_6807873a;
      iVar7 = props_callMethodDirect(this,param_4,1,(int *)local_45c);
      if ((((iVar7 == 0) &&
           (iVar7 = props_coerceAndReturnInt((int)this,local_45c,(int *)&local_44c), iVar7 == 0)) &&
          (iVar7 = props_callMethodDirect(this,param_4,2,(int *)local_45c), iVar7 == 0)) &&
         (iVar7 = props_coerceAndReturnInt((int)this,local_45c,(int *)&local_450), iVar3 = local_43c,
         iVar2 = local_440, pvVar1 = local_450, iVar7 == 0)) {
        if ((int)local_450 < (int)local_44c) {
          local_450 = local_44c;
          local_44c = pvVar1;
        }
        iVar7 = Ordinal_294(*(int *)(local_440 + 0x20),*(int *)(local_440 + 0x28),local_43c,0x70,
                            local_438);
        if (iVar7 != 0) {
          local_44c = (void *)xtra_getTextBlockSize(local_438[0],(int)local_44c);
          local_450 = (void *)xtra_getTextBlockSize(local_438[0],(int)local_450);
        }
        media_registerAsset(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28),iVar3,(int)local_450);
        media_registerAssetWithData(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28),iVar3,local_44c,local_450);
        goto LAB_6807873a;
      }
    }
  }
  else {
LAB_68078718:
    if (iVar7 == 0) goto LAB_6807873a;
  }
LAB_6807871c:
  if (iVar7 != -0x7ffbf82b) {
    sprites_getMemberPurge((int)this,local_43c);
  }
LAB_6807873a:
  return 0;
}




// ============================================================
// Function: sprites_dispatchTextRect (FUN_680791e0)
// Address: 680791e0
// Size: 598 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchTextRect(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  uint *unaff_EDI;
  int local_40;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20 [6];
  uint local_8;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  iVar1 = *(int *)(*(int *)(unaff_ESI + 8) + 4);
  local_3c = 0;
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 < 0x276) {
    if (param_1 == 0x275) {
      if (param_2 != 0) goto LAB_680792f8;
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x46,&local_38);
    }
    else if (param_1 == 0x160) {
      if (param_2 != 0) {
        local_3c = props_coerceAndReturnInt(unaff_ESI,unaff_EDI,&local_40);
        if (local_3c == 0) {
          local_20[0] = (uint)(local_40 != 0);
          iVar1 = Ordinal_293(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x2f,local_20);
          if (iVar1 == 0) goto LAB_680792f8;
        }
        goto LAB_68079422;
      }
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x2f,&local_38);
    }
    else if (param_1 == 0x1e3) {
      if (param_2 != 0) goto LAB_680792f8;
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x30,&local_38);
    }
    else {
      if (param_1 != 0x274) goto LAB_6807937c;
      if (param_2 != 0) goto LAB_680792f8;
      iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x47,&local_38);
    }
  }
  else {
    if (param_1 != 0x276) {
      if (param_1 == 0x321) {
        if (param_2 == 0) {
          uVar2 = sprites_dispatchTextProperty(unaff_ESI,param_3);
          unaff_EDI[1] = uVar2;
          *unaff_EDI = 3;
          return 0;
        }
      }
      else {
        if (param_1 != 0x322) {
LAB_6807937c:
          return 0;
        }
        if (param_2 == 0) {
          uVar2 = sprites_dispatchVectorProperty(unaff_ESI,param_3);
          unaff_EDI[1] = uVar2;
          *unaff_EDI = 3;
          return 0;
        }
      }
LAB_680792f8:
      local_3c = 0x800407d6;
      return 0;
    }
    if (param_2 != 0) goto LAB_680792f8;
    iVar1 = Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3,0x45,&local_38);
  }
  uVar2 = local_38;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  props_storeIntValue(unaff_ESI,uVar2,unaff_EDI);
LAB_68079422:
  return 0;
}



// ============================================================
// Function: sprites_dispatchTextFlags (FUN_68079440)
// Address: 68079440
// Size: 920 bytes
// Params: uint param_1, uint * param_2, undefined4 param_3
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchTextFlags(uint param_1,uint *param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_ESI;
  uint local_8;
  
  if (*(int *)(*(int *)(unaff_ESI + 8) + 4) == 0) {
    return -0x7ffbf82e;
  }
  local_8 = param_1;
  if ((int)param_1 < 0x322) {
    if (param_1 == 0x321) {
      if (in_EAX != 0) {
        return -0x7ffbf82a;
      }
      uVar3 = sprites_dispatchTextProperty(unaff_ESI,param_3);
      param_2[1] = uVar3;
      *param_2 = 3;
      return 0;
    }
    switch(param_1) {
    case 0x1dc:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberStretch(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,param_2,(int *)&local_8);
      if (iVar1 != 0) {
        return iVar1;
      }
      sprites_setMemberStretch(unaff_ESI,param_3,local_8);
      return 0;
    default:
      goto switchD_6807948a_caseD_1dd;
    case 0x1e3:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberLineHeight(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      break;
    case 0x1e4:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberAutoTab(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,param_2,(int *)&local_8);
      if (iVar1 != 0) {
        return iVar1;
      }
      sprites_setMemberAutoTab(unaff_ESI,param_3,local_8);
      return 0;
    case 0x1e5:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberEditing(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,param_2,(int *)&local_8);
      if (iVar1 != 0) {
        return iVar1;
      }
      sprites_setMemberEditing(unaff_ESI,param_3,local_8);
      return 0;
    case 0x1ea:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberSampleRate(unaff_ESI,param_3,1);
        props_storeIntValue(unaff_ESI,uVar2,param_2);
        return 0;
      }
      break;
    case 0x1eb:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberSampleSize(unaff_ESI,param_3,1);
        props_storeIntValue(unaff_ESI,uVar2,param_2);
        return 0;
      }
      break;
    case 0x231:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberInk(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,param_2,(int *)&local_8);
      if (iVar1 != 0) {
        return iVar1;
      }
      sprites_setMemberInk(unaff_ESI,param_3,local_8);
      return 0;
    case 0x233:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberImmovable(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,param_2,(int *)&local_8);
      if (iVar1 != 0) {
        return iVar1;
      }
      sprites_setMemberImmovable(unaff_ESI,param_3,local_8);
      return 0;
    case 0x234:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberAntiAlias(unaff_ESI,param_3);
        iVar1 = props_storeIntValue(unaff_ESI,uVar2,param_2);
        return iVar1;
      }
      iVar1 = props_coerceAndReturnInt(unaff_ESI,param_2,(int *)&local_8);
      if (iVar1 != 0) {
        return iVar1;
      }
      sprites_setMemberAntiAlias(unaff_ESI,param_3);
      return 0;
    case 0x27b:
      if (in_EAX == 0) {
        iVar1 = sprites_getMemberCompression(unaff_ESI,param_3,1);
        iVar1 = props_storeObjectRef(unaff_ESI,iVar1,param_2);
        return iVar1;
      }
      break;
    case 0x27c:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberWidth(unaff_ESI,param_3);
        props_storeIntValue(unaff_ESI,uVar2,param_2);
        return 0;
      }
      break;
    case 0x28e:
      if (in_EAX == 0) {
        iVar1 = sprites_getMemberDepth(unaff_ESI,param_3);
        iVar1 = props_storeObjectRef(unaff_ESI,iVar1,param_2);
        return iVar1;
      }
      break;
    case 0x28f:
      if (in_EAX == 0) {
        uVar2 = sprites_getMemberDuration(unaff_ESI,param_3);
        props_storeIntValue(unaff_ESI,uVar2,param_2);
        return 0;
      }
    }
    iVar1 = props_returnSymbol(unaff_ESI,0x800407d6,param_1);
    return iVar1;
  }
  if (param_1 == 0x322) {
    if (in_EAX != 0) {
      return -0x7ffbf82a;
    }
    uVar3 = sprites_dispatchVectorProperty(unaff_ESI,param_3);
    *param_2 = 3;
    param_2[1] = uVar3;
    return 0;
  }
switchD_6807948a_caseD_1dd:
  return -0x7ffbf82b;
}



// ============================================================
// Function: sprites_dispatchVectorRect (FUN_680798d0)
// Address: 680798d0
// Size: 287 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchVectorRect(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int *unaff_EDI;
  uint local_20 [6];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(unaff_EBX + 8) + 4);
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_3 == 0x291) && (param_2 == 0)) {
    iVar1 = sprites_dispatchExtPropertyByType(unaff_EBX,param_1);
    if ((((iVar1 != 0xfb) && (iVar1 != 0x131)) && (iVar1 != 0x36c)) &&
       ((iVar1 != 0x154 && (iVar1 != 0x156)))) {
      iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_1,0x3b,local_20);
      if (iVar2 == 0) {
        return 0;
      }
      Ordinal_1653(local_20);
    }
    cast_createFromStack();
    return 0;
  }
  iVar2 = Ordinal_214(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_1,param_2,param_3,
                      unaff_EDI);
  if ((iVar2 == 0) && ((param_2 == 0 && (*unaff_EDI == 5)))) {
    stage_wrapHandle(unaff_EBX,unaff_EDI[1],unaff_EDI);
  }
  return 0;
}



// ============================================================
// Function: sprites_dispatchFlashRect (FUN_680799f0)
// Address: 680799f0
// Size: 668 bytes
// Params: int param_1, uint * param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_dispatchFlashRect(int param_1,uint *param_2,undefined4 param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_3c;
  uint local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar2 == 0) {
    return 0;
  }
  switch(param_5) {
  case 0x1e3:
    if (param_4 == 0) {
      iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x30,local_38);
      if (iVar2 != 0) {
        props_storeIntValue(param_1,local_38[0],param_2);
        return 0;
      }
LAB_68079c22:
      props_storeIntValue(param_1,0,param_2);
      goto LAB_68079c2a;
    }
    iVar1 = props_coerceAndReturnInt(param_1,param_2,(int *)&local_3c);
    if (iVar1 != 0) goto LAB_68079c2a;
    uVar3 = 0x30;
    break;
  default:
    iVar2 = scoreEngine_getPropertyRect(*(int *)(iVar2 + 0x20),(short)param_3);
    if (iVar2 != 0) {
      return 0;
    }
    sprites_dispatchVectorRect(param_3,param_4,param_5);
    return 0;
  case 0x2b0:
    if (param_4 == 0) {
      iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x4d,local_38);
      if (iVar2 != 0) {
        props_storeIntValue(param_1,local_38[0],param_2);
        return 0;
      }
      goto LAB_68079c22;
    }
    iVar1 = props_coerceAndReturnInt(param_1,param_2,(int *)&local_3c);
    if (iVar1 != 0) goto LAB_68079c2a;
    local_20[0] = local_3c;
    iVar1 = *(int *)(iVar2 + 0x28);
    uVar3 = 0x4d;
    iVar2 = *(int *)(iVar2 + 0x20);
    goto LAB_68079bc4;
  case 0x2b1:
    if (param_4 == 0) {
      iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x4e,local_38);
      if (iVar2 != 0) {
        props_storeIntValue(param_1,local_38[0],param_2);
        return 0;
      }
      goto LAB_68079c22;
    }
    iVar1 = props_coerceAndReturnInt(param_1,param_2,(int *)&local_3c);
    if (iVar1 != 0) goto LAB_68079c2a;
    uVar3 = 0x4e;
    break;
  case 0x2b2:
    if (param_4 == 0) {
      iVar2 = Ordinal_294(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_3,0x4f,local_38);
      if (iVar2 != 0) {
        props_storeIntValue(param_1,local_38[0],param_2);
        return 0;
      }
      goto LAB_68079c22;
    }
    iVar1 = props_coerceAndReturnInt(param_1,param_2,(int *)&local_3c);
    if (iVar1 != 0) goto LAB_68079c2a;
    uVar3 = 0x4f;
  }
  local_20[0] = local_3c;
  iVar1 = *(int *)(iVar2 + 0x28);
  iVar2 = *(int *)(iVar2 + 0x20);
LAB_68079bc4:
  iVar2 = Ordinal_293(iVar2,iVar1,param_3,uVar3,local_20);
  if (iVar2 == 0) {
    return 0;
  }
LAB_68079c2a:
  return 0;
}




// ============================================================
// Function: sprites_dispatchPropertyEx (FUN_68079d70)
// Address: 68079d70
// Size: 3423 bytes
// Params: void * param_1, int param_2, int param_3, uint param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchPropertyEx(void *param_1,int param_2,int param_3,uint param_4,uint *param_5)
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  byte *pbVar8;
  undefined4 local_488;
  uint local_484;
  uint local_480;
  undefined4 local_47c;
  int local_478;
  int local_474;
  void *local_470;
  int local_46c;
  uint *local_468;
  int local_464;
  uint local_460 [6];
  undefined4 *local_448 [6];
  int local_430;
  int local_42c;
  int local_428;
  int local_424;
  uint local_420 [2];
  int *local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  byte local_408 [1024];
  uint local_8;
  
  local_46c = *(int *)(*(int *)((int)param_1 + 8) + 4);
  local_470 = param_1;
  local_464 = param_2;
  local_468 = param_5;
  if (local_46c == 0) {
    return 0;
  }
  uVar1 = sprites_setProperty((int)param_1,param_2);
  switch(uVar1) {
  case 1:
  case 0xd:
    iVar3 = sprites_dispatchBitmapFlags(param_4,param_3,local_464,param_5);
    break;
  case 2:
    iVar3 = sprites_dispatchSpriteProperty(param_4,param_3,local_464);
    break;
  case 3:
  case 7:
    iVar3 = sprites_dispatchShapeRect(param_1,local_464,param_3,param_4,param_5);
    break;
  default:
    goto switchD_68079dd9_caseD_4;
  case 5:
    iVar3 = sprites_exportMemberToFile(local_464,param_3,param_4);
    break;
  case 6:
    iVar3 = sprites_dispatchTextRect(param_4,param_3,local_464);
    break;
  case 8:
    iVar3 = sprites_dispatchMemberStyle(param_4,param_3,local_464);
    break;
  case 9:
    iVar3 = sprites_dispatchSpriteProperty(param_4,param_3,local_464);
    if (iVar3 != -0x7ffbf82b) goto switchD_6807aa79_default;
    iVar3 = sprites_deleteMemberFromCast(local_464,param_3,param_4);
    break;
  case 10:
    iVar3 = sprites_dispatchSpriteProperty(param_4,param_3,local_464);
    if (iVar3 != -0x7ffbf82b) goto switchD_6807aa79_default;
    iVar3 = sprites_dispatchTextFlags(param_4,param_5,local_464);
    break;
  case 0xb:
    iVar3 = sprites_dispatchMemberSymbol(local_464,param_3,param_4);
    break;
  case 0xc:
    iVar3 = sprites_dispatchMemberField(param_4,param_3,local_464);
    break;
  case 0xe:
    iVar3 = sprites_dispatchFlashRect((int)param_1,param_5,local_464,param_3,param_4);
    break;
  case 0xf:
    iVar3 = sprites_dispatchVectorRect(local_464,param_3,param_4);
    param_5 = local_468;
  }
  if (iVar3 != -0x7ffbf82b) goto switchD_6807aa79_default;
switchD_68079dd9_caseD_4:
  sVar7 = (short)local_464;
  if ((int)param_4 < 0x1f7) {
    if (param_4 != 0x1f6) {
      switch(param_4) {
      case 0x48:
        if (param_3 == 0) {
          sprites_getMemberRect((int)param_1,local_464,&local_430);
          props_storeIntValue(param_1,local_424 - local_42c,param_5);
        }
        break;
      case 0x49:
        if (param_3 == 0) {
          sprites_getMemberRect((int)param_1,local_464,&local_430);
          props_storeIntValue(param_1,local_428 - local_430,param_5);
        }
        break;
      default:
        /* FIXUP(C2094): goto switchD_68079f8a_caseD_4a; */
      case 0x58:
        if (param_3 == 0) {
          local_47c = Ordinal_363(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x24),sVar7);
          cast_getScoreXtraData((int)param_1,(short *)&local_47c);
        }
        break;
      case 0xaa:
        if (param_3 == 0) {
          local_47c = Ordinal_363(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x24),sVar7);
          uVar6 = sprites_getPropertyId(param_1,local_47c);
          props_storeIntValue(param_1,uVar6,param_5);
        }
        break;
      case 0xbc:
        if (param_3 == 0) {
          sprites_getMemberRect((int)param_1,local_464,&local_430);
          props_computeRectOp((int)param_1,&local_430,param_5);
        }
        else {
          props_createRect(param_1,(int *)param_5);
          sprites_setMemberRect((int)param_1,local_464,&local_430);
        }
        break;
      case 0xfc:
        if (param_3 == 0) {
          sprites_getMemberFileName((int)param_1,local_464,local_408);
          props_readPascalString((int)param_1,local_408,param_5);
        }
        else {
          local_468 = (uint *)0xffffffff;
          if ((*param_5 == 4) && (param_5[1] == 0)) {
            pbVar8 = (byte *)0x0;
          }
          else {
            piVar2 = props_getApiContext((int *)param_5);
            if (piVar2 == (int *)0x0) {
              cast_setReturnValue((int)param_1,4,local_468);
              break;
            }
            Ordinal_1233(local_408,piVar2);
            props_getApiState((int *)param_5);
            pbVar8 = local_408;
          }
          local_468 = (uint *)sprites_dispatchPropertyByType((int)param_1,local_464,(int)pbVar8);
          cast_setReturnValue((int)param_1,4,local_468);
        }
        break;
      case 0x100:
switchD_68079f8a_caseD_100:
        local_418 = (int *)0x0;
        local_414 = 0;
        local_410 = 0;
        local_40c = 0;
        local_420[0] = 0;
        local_420[1] = 0;
        if (param_3 == 0) {
          iVar3 = scoreEngine_setPropertyRect(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,
                               (int *)local_420,(uint)(param_4 == 0x53f));
          if (iVar3 == 0) {
            iVar3 = props_storeMediaRef((int)param_1,local_418,param_5);
          }
        }
        else {
          iVar3 = props_validateMediaRef((int)param_1,param_5,&local_418);
          if (iVar3 == 0) {
            iVar3 = scoreEngine_getPropertyFloat(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,
                                 (int *)local_420);
          }
        }
        switch(iVar3) {
        case 0:
          break;
        case 1:
switchD_6807aa79_caseD_1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        /* FIXUP(C2143-ctx): case 8: */
        } /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */;
        break;
      case 0x103:
        if (param_3 == 0) {
          iVar3 = sprites_getMemberNameById((int)param_1,local_464,local_408);
          if (iVar3 == 0) {
            local_408[0] = 0;
            local_408[1] = 0;
          }
          props_readPascalString((int)param_1,local_408,param_5);
        }
        else {
          iVar3 = crt_getPlatformData((int)param_1,(int *)param_5,local_408);
          if (iVar3 != 0) {
            sprites_setMemberFrameIndex((int)param_1,local_464,(int)local_408);
          }
        }
        break;
      case 0x118:
        if (param_3 == 0) {
          uVar1 = sprites_getMemberPurgeFlag((int)param_1,local_464);
          props_storeIntValue(param_1,uVar1,param_5);
        }
        else {
          iVar3 = props_coerceAndReturnInt((int)param_1,param_5,&local_474);
          if (iVar3 == 0) {
            sprites_setMemberPurge((int)param_1,local_464,(uint)(local_474 != 0));
          }
        }
        break;
      case 0x139:
switchD_68079f8a_caseD_139:
        if (param_3 == 0) {
          iVar3 = sprites_dispatchExtPropertyByType((int)param_1,local_464);
          if (param_4 == 0x1ff) {
            if (iVar3 == 0x2d) {
              props_storeObjectRef(param_1,0xfb,param_5);
              break;
            }
            if (iVar3 == 0xfb) {
              iVar3 = 0x269;
            }
          }
          props_storeObjectRef(param_1,iVar3,param_5);
        }
        break;
      case 0x142:
        if (param_3 == 0) {
          uVar1 = sprites_dispatchMemberOp((int)param_1,local_464);
          props_storeIntValue(param_1,uVar1,param_5);
        }
      }
      goto switchD_6807aa79_default;
    }
    if (param_3 != 0) {
      iVar3 = props_coerceAndReturnSymbol((int)param_1,param_5,&local_468);
      if ((iVar3 == 0) && (local_468 != (uint *)0x0)) {
        sprites_updateMemberScriptDirect(param_1,local_464,(int *)local_468);
        props_freeStringAndReturn(param_1,param_5,local_468);
      }
      goto switchD_6807aa79_default;
    }
    local_448[0] = (undefined4 *)sprites_setPropertyDirect((int)param_1,local_464);
    if (local_448[0] == (undefined4 *)0x0) {
      props_loadStringValue((int)param_1,"",param_5);
      goto switchD_6807aa79_default;
    }
LAB_6807a7c6:
    props_getExtPair((int)param_1,local_448[0],param_5);
    goto switchD_6807aa79_default;
  }
  if ((int)param_4 < 0x2da) {
    if (param_4 == 0x2d9) {
      if (param_3 == 0) {
        local_47c = Ordinal_363(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x24),sVar7);
        props_storeIntValue(param_1,(int)(short)local_47c,param_5);
      }
      goto switchD_6807aa79_default;
    }
    switch(param_4) {
    case 0x1f7:
      if (param_3 == 0) {
        sprites_getMemberRegPointPair((int)param_1,local_464,&local_488);
        props_transformRect((int)param_1,&local_488,param_5);
      }
      else {
        iVar3 = props_getRectField((int)param_1,(int *)param_5);
        if (iVar3 != 0) {
          sprites_setMemberRegPoint((int)param_1,local_464,local_488,local_484);
        }
      }
      break;
    default:
      /* FIXUP(C2094): goto switchD_68079f8a_caseD_4a; */
    case 0x1fd:
      if (param_3 == 0) {
        uVar1 = sprites_getInkEffect((int)param_1,local_464);
        props_storeIntValue(param_1,uVar1,param_5);
      }
      else {
        iVar3 = props_coerceAndReturnInt((int)param_1,param_5,&local_474);
        if ((iVar3 == 0) && (0 < local_474)) {
          Ordinal_293(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,10,(uint *)0x0
                     );
        }
      }
      break;
    case 0x1fe:
      if (param_3 == 0) {
        iVar3 = sprites_getMemberPalette((int)param_1,local_464);
        props_storeIntValue(param_1,(uint)(iVar3 == 0),param_5);
      }
      else {
        iVar3 = props_coerceAndReturnInt((int)param_1,param_5,&local_474);
        if (iVar3 == 0) {
          sprites_toggleMemberExport((int)param_1,(short)local_464,(uint)(local_474 == 0));
        }
      }
      break;
    case 0x1ff:
      goto switchD_68079f8a_caseD_139;
    case 0x230:
      if (param_3 == 0) {
        uVar1 = sprites_getMemberTrails((int)param_1,local_464);
        props_storeIntValue(param_1,uVar1,param_5);
      }
      else {
        iVar3 = props_coerceAndReturnInt((int)param_1,param_5,&local_474);
        if (iVar3 == 0) {
          sprites_setMemberTrails((int)param_1,local_464,local_474);
        }
      }
    }
    goto switchD_6807aa79_default;
  }
  if ((int)param_4 < 0x38f) {
    if (param_4 == 0x38e) {
      if (param_3 != 0) goto switchD_6807aa79_default;
      uVar4 = Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x1b,
                          (uint *)local_448);
      if (((int)uVar4 != 0) && (local_448[0] != (undefined4 *)0x0)) {
        props_convertTimestampToDate(local_448[0],(uint)((ulonglong)uVar4 >> 0x20),(int)param_1,(uint)local_448[0],0
                     ,param_5);
        goto switchD_6807aa79_default;
      }
      goto LAB_6807a6f4;
    }
    switch(param_4) {
    case 0x330:
      if (param_3 == 0) {
        iVar3 = Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x7a,
                            (uint *)local_448);
        if (iVar3 == 0) {
          props_storeIntValue(param_1,0,param_5);
        }
        else {
          props_storeIntValue(param_1,local_448[0],param_5);
        }
      }
      else {
        props_returnSymbol((int)param_1,0x800407d6,param_4);
      }
      break;
    case 0x345:
      if (param_3 == 0) {
        sprites_getMemberModified((int)param_1,local_464);
        props_storeSymbolValue((int)local_470,local_478,param_5);
        break;
      }
      iVar3 = props_coerceToShort((int)param_1,param_5,&local_478);
      if (iVar3 == 0) {
        sprites_setMemberModified((int)param_1,local_464);
        break;
      }
      iVar3 = props_coerceAndReturnInt((int)param_1,param_5,&local_474);
      if ((iVar3 == 0) && (local_474 == 0)) {
        sprites_setMemberModified((int)param_1,local_464);
        break;
      }
      goto switchD_6807aa79_caseD_1;
    case 0x35d:
      if (param_3 == 0) {
        Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x13,
                    (uint *)local_448);
        props_storeIntValue(param_1,local_448[0],param_5);
      }
      break;
    case 0x365:
      if (param_3 != 0) break;
      iVar3 = Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,9,
                          local_420);
      if (iVar3 != 0) {
        props_storeIntValue(param_1,local_420[0],param_5);
        break;
      }
    /* FIXUP(C2143-ctx): default: */
/* FIXUP(C2143-ctx): switchD_68079f8a_caseD_4a: */
    } /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */;
  }
  else {
    if (0x3a0 < (int)param_4) {
      if (param_4 == 0x53f) goto switchD_68079f8a_caseD_100;
      if (param_4 == 0x619) {
        if (param_3 == 0) {
          local_468 = (uint *)0x4a5;
          iVar3 = Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x22,
                              (uint *)local_448);
          if (iVar3 != 0) {
            if (local_448[0] == (undefined4 *)0x0) {
              local_468 = (uint *)0x61a;
            }
            else if (local_448[0] == (undefined4 *)0x1) {
              local_468 = (uint *)0x61b;
              props_storeObjectRef(param_1,0x61b,param_5);
              goto switchD_6807aa79_default;
            }
          }
          props_storeObjectRef(param_1,(int)local_468,param_5);
        }
        else {
          iVar3 = props_coerceAndReturnFloat((int)param_1,param_5,(uint *)&local_468);
          if (iVar3 == 0) {
            if (local_468 == (uint *)0x61a) {
              local_460[0] = 0;
            }
            else {
              if (local_468 != (uint *)0x61b) goto switchD_6807aa79_default;
              local_460[0] = 1;
            }
            Ordinal_293(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x22,
                        local_460);
          }
        }
        goto switchD_6807aa79_default;
      }
      /* FIXUP(C2094): goto switchD_68079f8a_caseD_4a; */
    }
    if (param_4 == 0x3a0) {
      if (param_3 == 0) {
        iVar3 = Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,6,
                            (uint *)local_448);
        if (iVar3 == 0) {
          props_storeIntValue(param_1,0,param_5);
        }
        else {
          props_storeIntValue(param_1,local_448[0],param_5);
        }
      }
      goto switchD_6807aa79_default;
    }
    if (param_4 != 0x38f) {
      if (param_4 == 0x390) {
        if (param_3 != 0) goto switchD_6807aa79_default;
        iVar3 = *(int *)(local_46c + 0x28);
        iVar5 = *(int *)(local_46c + 0x20);
        uVar6 = 0x1d;
      }
      else {
        /* FIXUP(C2094): if (param_4 != 0x391) goto switchD_68079f8a_caseD_4a; */
        if (param_3 != 0) {
          iVar3 = props_coerceAndReturnSymbol((int)param_1,param_5,&local_480);
          if (iVar3 == 0) {
            local_460[0] = local_480;
            Ordinal_293(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x1e,
                        local_460);
            props_freeStringAndReturn(param_1,param_5,local_480);
          }
          goto switchD_6807aa79_default;
        }
        iVar3 = *(int *)(local_46c + 0x28);
        uVar6 = 0x1e;
        iVar5 = *(int *)(local_46c + 0x20);
      }
      iVar3 = Ordinal_294(iVar5,iVar3,local_464,uVar6,(uint *)local_448);
      if (iVar3 == 0) goto switchD_6807aa79_default;
      if (local_448[0] == (undefined4 *)0x0) {
        props_loadStringValue((int)param_1,"",param_5);
        goto switchD_6807aa79_default;
      }
      goto LAB_6807a7c6;
    }
    if (param_3 != 0) goto switchD_6807aa79_default;
    uVar4 = Ordinal_294(*(int *)(local_46c + 0x20),*(int *)(local_46c + 0x28),local_464,0x1c,
                        (uint *)local_448);
    if (((int)uVar4 != 0) && (local_448[0] != (undefined4 *)0x0)) {
      props_convertTimestampToDate(local_448[0],(uint)((ulonglong)uVar4 >> 0x20),(int)param_1,(uint)local_448[0],0,
                   param_5);
      goto switchD_6807aa79_default;
    }
LAB_6807a6f4:
    props_clearValue(param_1,param_5);
  }
switchD_6807aa79_default:
  return 0;
}



