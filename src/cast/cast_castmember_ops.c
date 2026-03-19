// Module: cast
// Topic: Cast member management - create, destroy, properties
// Address range: 0x68022430 - 0x68023200
// Functions (15):
//   cast_importBitmap (FUN_68022430)
//   cast_getPixelValue (FUN_680225f0)
//   cast_setPixelRegion (FUN_68022710)
//   cast_destroyCastMember (FUN_680229f0)
//   cast_formatCastMember (FUN_68022a70)
//   cast_getEmptyProperty (FUN_68022b20)
//   cast_getCastMemberProperty (FUN_68022b40)
//   cast_getCastMemberType (FUN_68022e20)
//   cast_getVtable (FUN_68022e40)
//   cast_setCastMemberData
//   cast_createBitmap (FUN_68022ec0)
//   cast_createFromStack (FUN_68023140)
//   cast_createWithDimensions (FUN_68023170)
//   cast_createFromPalette (FUN_680231a0)
//   cast_createFromFile (FUN_68023200)

// ============================================================
// Function: cast_importBitmap (FUN_68022430)
// Address: 68022430
// Size: 438 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_importBitmap(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *unaff_EDI;
  int local_64;
  int local_60;
  uint local_5c;
  undefined4 *local_58;
  byte *local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint *local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = (uint *)0x0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_58 = (undefined4 *)0x0;
  local_50 = (int *)0x0;
  iVar2 = props_getInt((int)unaff_EDI);
  if (iVar2 == 3) {
    piVar1 = (int *)(**(int **)((int)unaff_EDI + 0x10) + *(int *)((int)unaff_EDI + 0x20) * -8 + 8 +
                    *(int *)((int)unaff_EDI + 0x18));
    if (piVar1 != (int *)0x0) {
      local_64 = *piVar1;
      local_60 = piVar1[1];
      iVar2 = score_getMediaProperty(unaff_EDI,&local_64,(int *)&local_58);
      if (iVar2 != 0) {
        iVar2 = (**(code **)*local_58)(local_58,&DAT_681765f8,&local_50);
        if (-1 < iVar2) {
          iVar2 = props_getTypedValue((int)unaff_EDI,3,8,&local_5c);
          if (iVar2 != 0) {
            local_48 = cast_processBitmap(unaff_EDI,param_1);
            if (local_48 != 0) {
              iVar2 = Ordinal_1654(local_48,&local_44);
              if (iVar2 != 0) {
                if (local_30 == 0x20) {
                  iVar2 = local_40 * local_44;
                  local_4c = 0;
                  local_54 = (byte *)0x0;
                  Ordinal_1060(local_18,0,0,local_44,local_40);
                  (**(code **)(*local_50 + 0x18))(local_50,&local_4c);
                  if (0 < local_4c) {
                    local_54 = (byte *)Ordinal_1126(local_4c,0);
                    if (local_54 != (byte *)0x0) {
                      iVar3 = (**(code **)(*local_50 + 0x14))(local_50,0,local_4c,local_54,0);
                      if (-1 < iVar3) {
                        iVar2 = cast_convertPixelFormat(local_54,local_4c,local_34,iVar2 * 4);
                        if (iVar2 == 0) {
                          props_setError((int)unaff_EDI,0x79);
                        }
                      }
                      Ordinal_1127(&local_54);
                    }
                  }
                }
                Ordinal_1655(local_48);
              }
            }
          }
        }
      }
    }
  }
  else {
    props_setError((int)unaff_EDI,0x16);
  }
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))(local_50);
  }
  if (local_48 != 0) {
    Ordinal_1653(&local_48);
  }
  return 0;
}



// ============================================================
// Function: cast_getPixelValue (FUN_680225f0)
// Address: 680225f0
// Size: 281 bytes
// Params: void * param_1, void * param_2, undefined4 * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_getPixelValue(void *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  bVar3 = false;
  local_14 = 0;
  local_10 = 0;
  local_14 = cast_processBitmap(param_1,(int)param_2);
  if (local_14 != 0) {
    iVar1 = props_getRectField((int)param_1,
                         (int *)(**(int **)((int)param_1 + 0x10) +
                                 *(int *)((int)param_1 + 0x20) * -8 + 8 +
                                *(int *)((int)param_1 + 0x18)));
    if (iVar1 == 0) {
      iVar1 = props_getTypedValue((int)param_1,2,4,&local_c);
      if ((iVar1 == 0) || (iVar1 = props_getTypedValue((int)param_1,3,4,&local_8), iVar1 == 0))
      goto LAB_680226f6;
      iVar1 = 4;
    }
    else {
      local_c = local_20;
      local_8 = local_24;
      iVar1 = 3;
    }
    iVar2 = props_getInt((int)param_1);
    if ((iVar1 <= iVar2) && (iVar1 = props_getTypedValue((int)param_1,iVar1,8,&local_10), iVar1 == 0)) {
      local_10 = 0;
    }
    cast_applyInkEffect(param_2,(int)param_1);
    iVar1 = Ordinal_1686(local_14,local_c,local_8,&local_1c,&local_18);
    if (iVar1 != 0) {
      if (local_10 == 0x95) {
        iVar1 = props_storeIntValue(param_1,local_18,param_3);
      }
      else {
        iVar1 = props_storeFloatValue((int)param_1,&local_1c,param_3);
      }
      bVar3 = iVar1 == 0;
    }
  }
LAB_680226f6:
  Ordinal_1653(&local_14);
  return bVar3;
}



// ============================================================
// Function: cast_setPixelRegion (FUN_68022710)
// Address: 68022710
// Size: 727 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setPixelRegion(void *param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar4;
  uint uVar5;
  uint extraout_ECX_01;
  void *unaff_EDI;
  uint local_78;
  uint local_74;
  undefined1 local_70 [3];
  undefined1 uStack_6d;
  undefined2 uStack_6c;
  undefined2 local_6a;
  uint local_64 [3];
  void *local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  char local_45;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_58 = param_1;
  local_64[1] = 0;
  local_54 = 0;
  local_64[2] = 0;
  local_54 = cast_processBitmap(unaff_EDI,(int)param_1);
  if (local_54 != 0) {
    iVar1 = props_getRectField((int)unaff_EDI,
                         (int *)(**(int **)((int)unaff_EDI + 0x10) +
                                 *(int *)((int)unaff_EDI + 0x20) * -8 + 8 +
                                *(int *)((int)unaff_EDI + 0x18)));
    if (iVar1 == 0) {
      iVar1 = props_getTypedValue((int)unaff_EDI,2,4,&local_50);
      if ((iVar1 == 0) || (iVar1 = props_getTypedValue((int)unaff_EDI,3,4,&local_4c), iVar1 == 0))
      goto LAB_680229c1;
      iVar1 = 4;
    }
    else {
      local_50 = local_74;
      local_4c = local_78;
      iVar1 = 3;
    }
    Ordinal_1060(&local_18,local_50,local_4c,local_50 + 1,local_4c + 1);
    cast_checkInkEffect(local_58,(int)unaff_EDI);
    if (local_c <= (int)local_14) {
      local_c = local_14 + 1;
    }
    if ((int)local_10 <= (int)local_18) {
      local_10 = local_18 + 1;
    }
    uVar2 = props_coerceAndStore((int)unaff_EDI,
                         (uint *)(**(int **)((int)unaff_EDI + 0x10) + -8 +
                                  (iVar1 - *(int *)((int)unaff_EDI + 0x20)) * 8 +
                                 *(int *)((int)unaff_EDI + 0x18)),(int *)&local_48);
    if (uVar2 == 0) {
      local_44 = uVar2;
      local_40 = uVar2;
      local_3c = uVar2;
      local_38 = uVar2;
      local_34 = uVar2;
      local_30 = uVar2;
      local_2c = uVar2;
      local_28 = uVar2;
      local_24 = uVar2;
      local_20 = uVar2;
      local_1c = uVar2;
      iVar1 = Ordinal_1656(local_54,&local_44);
      if (iVar1 == 0) goto LAB_680229c1;
      uVar4 = extraout_ECX;
      if (local_30 < 9) {
        if (local_45 == '\x01') {
          local_64[2] = cast_getBitmapState((int)unaff_EDI);
          if (local_64[2] == 0) goto LAB_680229c1;
          local_45 = '\0';
          local_48 = Ordinal_1738(local_64[2],CONCAT11(local_48,local_48),
                                  CONCAT11(local_47,local_47),CONCAT11(local_46,local_46));
          uVar4 = extraout_ECX_00;
        }
      }
      else if (local_45 == '\0') {
        local_64[2] = cast_getBitmapState((int)unaff_EDI);
        if ((local_64[2] == 0) ||
           (iVar1 = Ordinal_1736(local_64[2],local_48,local_70,1), iVar1 == 0)) goto LAB_680229c1;
        uVar4 = CONCAT22(local_6a,uStack_6c) >> 8;
        local_45 = '\x01';
        local_47 = (undefined1)((ushort)uStack_6c >> 8);
        local_46 = (undefined1)((ushort)local_6a >> 8);
        local_48 = uStack_6d;
      }
      local_4c = local_14;
      uVar2 = local_18;
      uVar5 = local_10;
      if ((int)local_14 < local_c) {
        do {
          uVar3 = uVar2;
          uVar4 = uVar5;
          local_50 = uVar2;
          if ((int)uVar2 < (int)uVar5) {
            do {
              local_50 = uVar2;
              iVar1 = Ordinal_1685(local_54,uVar2,local_4c,&local_48,0);
              if (iVar1 == 0) goto LAB_680229c1;
              uVar2 = local_50 + 1;
              uVar3 = local_18;
              uVar4 = local_10;
              local_50 = uVar2;
            } while ((int)uVar2 < (int)local_10);
          }
          local_4c = local_4c + 1;
          uVar2 = uVar3;
          uVar5 = uVar4;
        } while ((int)local_4c < local_c);
      }
    }
    else {
      iVar1 = props_getTypedValue((int)unaff_EDI,iVar1,4,local_64);
      if (iVar1 == 0) goto LAB_680229c1;
      local_4c = local_14;
      uVar2 = local_18;
      uVar4 = extraout_ECX_01;
      uVar5 = local_10;
      if ((int)local_14 < local_c) {
        do {
          uVar3 = uVar2;
          uVar4 = uVar5;
          local_50 = uVar2;
          if ((int)uVar2 < (int)uVar5) {
            do {
              local_50 = uVar2;
              iVar1 = Ordinal_1685(local_54,uVar2,local_4c,0,local_64[0]);
              if (iVar1 == 0) goto LAB_680229c1;
              uVar2 = local_50 + 1;
              uVar3 = local_18;
              uVar4 = local_10;
              local_50 = uVar2;
            } while ((int)uVar2 < (int)local_10);
          }
          local_4c = local_4c + 1;
          uVar2 = uVar3;
          uVar5 = uVar4;
        } while ((int)local_4c < local_c);
      }
    }
    local_64[1] = 1;
    cast_initBitmapOp(uVar4,(int)unaff_EDI);
  }
LAB_680229c1:
  Ordinal_1653(&local_54);
  Ordinal_1733(local_64 + 2);
  return 0;
}



// ============================================================
// Function: cast_destroyCastMember (FUN_680229f0)
// Address: 680229f0
// Size: 123 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_destroyCastMember(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = Ordinal_1114(param_2);
  if (iVar1 != 0) {
    Ordinal_1653(iVar1 + 0x14);
    Ordinal_1733(iVar1 + 0x1c);
    Ordinal_1742(iVar1 + 0x24);
    Ordinal_1671(iVar1 + 0x20);
    if (*(int **)(iVar1 + 0x10) != (int *)0x0) {
      props_releaseValue(param_1,3,*(int **)(iVar1 + 0x10));
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    Ordinal_1115(param_2);
    Ordinal_1113(&param_2);
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  }
  return 0;
}



// ============================================================
// Function: cast_formatCastMember (FUN_68022a70)
// Address: 68022a70
// Size: 166 bytes
// Params: void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatCastMember(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = param_2;
  iVar3 = Ordinal_1114(param_2);
  pvVar1 = param_1;
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x20) != 0) {
      cast_loadPascalString(&DAT_68197780,0x898,0x40);
      props_formatString(param_1,param_3,param_4,&DAT_68197781);
      Ordinal_1115(uVar2);
      return 0;
    }
    param_1 = (void *)cast_processBitmap(param_1,iVar3);
    cast_loadPascalString(&DAT_68197780,0x898,0x41);
    props_formatString(pvVar1,param_3,param_4,&DAT_68197781);
    Ordinal_1653(&param_1);
    Ordinal_1115(uVar2);
  }
  return 0;
}



// ============================================================
// Function: cast_getEmptyProperty (FUN_68022b20)
// Address: 68022b20
// Size: 18 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getEmptyProperty(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = 0;
  return 0;
}



// ============================================================
// Function: cast_getCastMemberProperty (FUN_68022b40)
// Address: 68022b40
// Size: 728 bytes
// Params: void * param_1, int param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getCastMemberProperty(void *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_60;
  uint local_5c [2];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_60 = param_5;
  local_70 = 0;
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
  iVar3 = *(int *)(*(int *)((int)param_1 + 8) + 4);
  local_6c = param_2;
  local_64 = 1;
  iVar2 = Ordinal_1114(param_2);
  if (iVar2 == 0) {
    local_64 = 0;
    goto LAB_68022e02;
  }
  if (*(int *)(iVar2 + 0x20) == 0) {
    local_70 = cast_processBitmap(param_1,iVar2);
    if (local_70 == 0) {
      local_64 = 0;
    }
    else {
      Ordinal_1656(local_70,&local_44);
      Ordinal_1653(&local_70);
      Ordinal_1060(&local_18,0,0,local_40,local_44);
      if (param_4 < 0x20a) {
        if (param_4 == 0x209) {
          if (param_3 != 0) {
LAB_68022d6d:
            if (local_6c != 0) {
              Ordinal_1115(local_6c);
            }
            props_reportError((int)param_1,0x39);
            return 0;
          }
          props_storeIntValue(param_1,local_30,local_60);
        }
        else if (param_4 == 0x48) {
          if (param_3 != 0) goto LAB_68022d6d;
          props_storeIntValue(param_1,local_10 - local_18,local_60);
        }
        else if (param_4 == 0x49) {
          if (param_3 != 0) goto LAB_68022d6d;
          props_storeIntValue(param_1,local_c - local_14,local_60);
        }
        else {
          iVar3 = param_4 + -0xbc;
          if (iVar3 != 0) goto LAB_68022cbe;
          if (param_3 != 0) goto LAB_68022d6d;
          local_4c = local_c - local_14;
          local_48 = local_10 - local_18;
          local_54 = iVar3;
          local_50 = iVar3;
          props_storeRectOp((int)param_1,&local_54,local_60);
        }
      }
      else if (param_4 == 0x2da) {
        if (param_3 == 0) {
          sVar1 = cast_processBitmapEx(param_1,iVar2);
          local_68 = Ordinal_363(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),sVar1);
          cast_getScoreXtraData((int)param_1,(short *)&local_68);
        }
        else {
          iVar4 = cast_applyXtraFormatCode();
          if (iVar4 == 0) {
            uVar5 = Ordinal_362(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),&local_60);
            local_68 = uVar5;
            if (*(short *)(iVar2 + 10) == 0) {
              if (*(int *)(iVar2 + 0xc) != 0) goto LAB_68022d6d;
              if ((*(short *)(iVar2 + 0x18) != (short)uVar5) ||
                 ((*(unsigned short *)((char *)&local_68 + 2)) = (short)(uVar5 >> 0x10),
                 bVar6 = *(short *)(iVar2 + 0x1a) != (*(unsigned short *)((char *)&local_68 + 2)), bVar6)) {
                *(uint *)(iVar2 + 0x18) = uVar5;
                Ordinal_1733(iVar2 + 0x1c);
                Ordinal_1742(iVar2 + 0x24);
                *(undefined4 *)(iVar2 + 0x28) = 0;
              }
            }
            else {
              local_5c[0] = uVar5;
              Ordinal_293(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),*(undefined4 *)(iVar2 + 8),
                          0x40,local_5c);
            }
          }
        }
      }
      else if (param_4 == 0x347) {
        if (param_3 == 0) {
          props_storeIntValue(param_1,(uint)(local_2c != 0),local_60);
        }
        else {
          if (local_30 != 0x20) goto LAB_68022d6d;
          cast_updateBitmapAlpha(param_1);
        }
      }
      else {
LAB_68022cbe:
        local_64 = 0;
      }
    }
  }
  else {
    local_64 = 0;
  }
  if (local_6c != 0) {
    Ordinal_1115(local_6c);
  }
LAB_68022e02:
  return 0;
}



// ============================================================
// Function: cast_getCastMemberType (FUN_68022e20)
// Address: 68022e20
// Size: 29 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_getCastMemberType(undefined4 param_1,int *param_2)

{
  return (-(uint)(*(int *)(*param_2 + 0x20) != 0) & 0x118) + 0x291;
}



// ============================================================
// Function: cast_getVtable (FUN_68022e40)
// Address: 68022e40
// Size: 6 bytes
// Return: undefined * *
// Calling convention: __stdcall
// ============================================================

undefined ** cast_getVtable(void)

{
  return &PTR_FUN_6818b948;
}



// ============================================================
// Function: cast_setCastMemberData (FUN_68022e50)
// Address: 68022e50
// Size: 110 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
cast_setCastMemberData(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int *piVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  piVar2 = (int *)Ordinal_1111(0x84,1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_FUN_6818b948;
  puVar1[1] = 1;
  if (in_EAX != (undefined4 *)0x0) {
    puVar1[6] = *in_EAX;
  }
  if (param_3 != (undefined4 *)0x0) {
    puVar1[2] = *param_3;
  }
  puVar1[3] = param_5;
  puVar1[4] = param_4;
  puVar1[5] = param_1;
  puVar1[8] = param_2;
  unaff_ESI[1] = piVar2;
  *unaff_ESI = 3;
  *(int *)(unaff_EDI + 0xfc) = *(int *)(unaff_EDI + 0xfc) + 1;
  return 1;
}



// ============================================================
// Function: cast_createBitmap (FUN_68022ec0)
// Address: 68022ec0
// Size: 581 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createBitmap(int param_1)
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  double local_6c [3];
  undefined4 local_54 [2];
  undefined4 local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_54[0] = 2;
  iVar1 = props_getInt(param_1);
  if (iVar1 < 3) {
    iVar1 = props_getInt(param_1);
    if ((iVar1 == 1) &&
       (iVar1 = cast_setXtraPropertyEx(param_1,(uint *)(**(int **)(param_1 + 0x10) +
                                              *(int *)(param_1 + 0x20) * -8 +
                                             *(int *)(param_1 + 0x18)),(undefined2 *)&local_38),
       iVar1 == 0)) {
      iVar1 = 4;
    }
    else {
      iVar1 = 0x17;
    }
    props_setError(param_1,iVar1);
    return 0;
  }
  local_38 = 0;
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
  iVar1 = props_getTypedValue(param_1,1,4,&local_40);
  if ((((iVar1 == 0) || (iVar1 = props_getTypedValue(param_1,2,4,&local_3c), iVar1 == 0)) ||
      ((int)local_40 < 0)) ||
     (((int)local_3c < 0 || (iVar1 = props_getTypedValue(param_1,3,4,&local_20), iVar1 == 0))))
  goto switchD_68022f7b_caseD_3;
  switch(local_20) {
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x10:
  case 0x20:
    break;
  default:
    goto switchD_68022f7b_caseD_3;
  case 0x18:
    local_20 = 0x20;
  }
  iVar4 = 4;
  iVar1 = props_getInt(param_1);
  if (iVar1 < 4) {
LAB_6802300d:
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
    Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x11,local_6c);
    local_38 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),(undefined4 *)local_6c);
  }
  else {
    do {
      piVar2 = (int *)(**(int **)(param_1 + 0x10) + -8 + (iVar4 - *(int *)(param_1 + 0x20)) * 8 +
                      *(int *)(param_1 + 0x18));
      if (piVar2 == (int *)0x0) goto switchD_68022f7b_caseD_3;
      local_48 = *piVar2;
      local_44 = piVar2[1];
      iVar1 = cast_applyXtraFormatCode();
      if (iVar1 == 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
        local_38 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_4c);
      }
      else if (local_48 == 4) {
        local_1c = -(uint)(local_44 != 0) & 8;
      }
      iVar4 = iVar4 + 1;
      iVar1 = props_getInt(param_1);
    } while (iVar4 <= iVar1);
    if ((*(unsigned short *)((char *)&local_38 + 2)) == 0) goto LAB_6802300d;
  }
  if (((local_20 < 8) || ((int)local_40 < 0x80)) || ((int)local_3c < 0x80)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 4;
  }
  iVar1 = Ordinal_1650(local_20,local_1c,local_18,local_40,local_3c,uVar3);
  if (iVar1 != 0) {
    Ordinal_1665(iVar1,0);
    cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
  }
switchD_68022f7b_caseD_3:
  props_popArgs(param_1,local_54);
  return 0;
}



// ============================================================
// Function: cast_createFromStack (FUN_68023140)
// Address: 68023140
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createFromStack(void)
{
  cast_setCastMemberData(0,0,(undefined4 *)&stack0x00000008,0,0);
  return 0;
}



// ============================================================
// Function: cast_createWithDimensions (FUN_68023170)
// Address: 68023170
// Size: 38 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createWithDimensions(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  cast_setCastMemberData(0,0,(undefined4 *)0x0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: cast_createFromPalette (FUN_680231a0)
// Address: 680231a0
// Size: 86 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_createFromPalette(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Ordinal_1658(param_2,0,0,0,0,0,0,0,0,0,0);
  if (iVar1 != 0) {
    iVar1 = cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0x800407d2;
}



// ============================================================
// Function: cast_createFromFile (FUN_68023200)
// Address: 68023200
// Size: 132 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_createFromFile(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  uVar3 = 0x80040014;
  local_8 = 0;
  iVar1 = Ordinal_1402(&local_8,param_2,1);
  if (iVar1 != 0) {
    uVar2 = Ordinal_1330(param_2,0,0,0,0,0,0,0,0);
    uVar2 = Ordinal_1435(local_8,uVar2);
    iVar1 = Ordinal_1658(local_8,uVar2);
    if (iVar1 != 0) {
      iVar1 = cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
      if (iVar1 != 0) {
        uVar3 = 0;
      }
    }
  }
  Ordinal_1407(&local_8);
  return uVar3;
}



