// Module: certificates
// Topic: String prototype methods - replace, split, match, slice, concat, substring, HTML tag wrappers
// Address range: 0x681502b0 - 0x68151EF0
// Functions (22):
//   certificates_resolveBackref
//   certificates_applyReplace
//   certificates_executeReplace
//   certificates_splitString
//   certificates_searchString
//   certificates_sliceString
//   certificates_concatArgs
//   certificates_substringRange
//   certificates_wrapHtmlBold
//   certs_parseHtmlTag
//   certificates_wrapHtmlItalic
//   certificates_wrapHtmlFixed
//   certificates_wrapHtmlFontSize
//   certs_parseFontAttr
//   certificates_wrapHtmlFontColor
//   certificates_wrapHtmlAnchorHref
//   certificates_wrapHtmlAnchorName
//   certificates_wrapHtmlStrike
//   certificates_wrapHtmlSmall
//   certificates_wrapHtmlBig
//   certificates_wrapHtmlBlink
//   certificates_wrapHtmlSup

// ============================================================
// Function: certificates_resolveBackref (FUN_681502b0)
// Address: 681502b0
// Size: 1049 bytes
// Params: int param_1, ushort * param_2, int param_3, int * param_4
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * certificates_resolveBackref(int param_1,ushort *param_2,int param_3,int *param_4)

{
  uint uVar1;
  ushort uVar2;
  uint *puVar3;
  int iVar4;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  undefined4 *local_30;
  ushort *local_28;
  uint local_24;
  ushort *local_20;
  uint local_14;
  ushort *local_c;

  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0xc) < 0x8d)) {
    if ((**(uint **)(param_3 + 0x14) & 0x40000000) == 0) {
      local_28 = *(ushort **)(*(int *)(param_3 + 0x14) + 4);
    }
    else {
      if ((**(uint **)(*(int *)(param_3 + 0x14) + 4) & 0x40000000) == 0) {
        if ((**(uint **)(param_3 + 0x14) & 0x80000000) == 0) {
          local_24 = **(uint **)(param_3 + 0x14) >> 0xf & 0x7fff;
        }
        else {
          local_24 = 0;
        }
        local_20 = (ushort *)(*(int *)(*(int *)(*(int *)(param_3 + 0x14) + 4) + 4) + local_24 * 2);
      }
      else {
        local_20 = (ushort *)crypto_getStringLen(*(uint **)(param_3 + 0x14));
      }
      local_28 = local_20;
    }
    if ((local_28 < param_2) && (param_2[-1] == 0x5c)) {
      return (undefined4 *)0x0;
    }
  }
  uVar2 = param_2[1];
  if ((0x7f < uVar2) || (iVar4 = isdigit((uint)uVar2), iVar4 == 0)) {
    *param_4 = 2;
    switch(uVar2) {
    case 0x24:
      *(ushort **)(param_3 + 0x34) = param_2;
      *(undefined4 *)(param_3 + 0x30) = 1;
      return (undefined4 *)(param_3 + 0x30);
    default:
      return (undefined4 *)0x0;
    case 0x26:
      return (undefined4 *)(param_1 + 0x110);
    case 0x27:
      return (undefined4 *)(param_1 + 0x128);
    case 0x2b:
      return (undefined4 *)(param_1 + 0x118);
    case 0x60:
      goto switchD_68150560_caseD_60;
    }
  }
  if ((*(int *)(param_1 + 0xc) == 0) || (0x8c < *(int *)(param_1 + 0xc))) {
    local_14 = uVar2 - 0x30;
    if (*(uint *)(param_1 + 0xbc) < local_14) {
      return (undefined4 *)0x0;
    }
    local_c = param_2 + 2;
    uVar2 = *local_c;
    if ((((uVar2 != 0) && (uVar2 < 0x80)) && (iVar4 = isdigit((uint)uVar2), iVar4 != 0)) &&
       (uVar1 = local_14 * 10 + -0x30 + (uint)uVar2, uVar1 <= *(uint *)(param_1 + 0xbc))) {
      local_c = param_2 + 3;
      local_14 = uVar1;
    }
    if (local_14 == 0) {
      return (undefined4 *)0x0;
    }
  }
  else {
    if (uVar2 == 0x30) {
      return (undefined4 *)0x0;
    }
    local_14 = 0;
    local_c = param_2;
    uVar1 = local_14;
    while( true ) {
      local_14 = uVar1;
      local_c = local_c + 1;
      uVar2 = *local_c;
      if ((uVar2 == 0) || (0x7f < uVar2)) break;
      iVar4 = isdigit((uint)uVar2);
      if ((iVar4 == 0) || (uVar1 = local_14 * 10 + -0x30 + (uint)uVar2, uVar1 < local_14)) break;
    }
  }
  local_14 = local_14 - 1;
  *param_4 = (int)local_c - (int)param_2 >> 1;
  if (local_14 < *(uint *)(param_1 + 0xbc)) {
    if (local_14 < 9) {
      local_30 = (undefined4 *)(param_1 + 0xc4 + local_14 * 8);
    }
    else {
      local_30 = (undefined4 *)(*(int *)(param_1 + 0x10c) + -0x48 + local_14 * 8);
    }
  }
  else {
    local_30 = &DAT_681948f8;
  }
  return local_30;
switchD_68150560_caseD_60:
  if (*(int *)(param_1 + 0xc) == 0x78) {
    puVar3 = *(uint **)(param_3 + 8);
    if ((*puVar3 & 0x40000000) == 0) {
      local_40 = puVar3[1];
    }
    else {
      if ((*(uint *)puVar3[1] & 0x40000000) == 0) {
        if ((*puVar3 & 0x80000000) == 0) {
          local_3c = *puVar3 >> 0xf & 0x7fff;
        }
        else {
          local_3c = 0;
        }
        local_38 = *(int *)(puVar3[1] + 4) + local_3c * 2;
      }
      else {
        local_38 = crypto_getStringLen(puVar3);
      }
      local_40 = local_38;
    }
    *(uint *)(param_1 + 0x124) = local_40;
    if ((*puVar3 & 0x40000000) == 0) {
      local_4c = puVar3[1];
    }
    else {
      if ((*(uint *)puVar3[1] & 0x40000000) == 0) {
        if ((*puVar3 & 0x80000000) == 0) {
          local_48 = *puVar3 >> 0xf & 0x7fff;
        }
        else {
          local_48 = 0;
        }
        local_44 = *(int *)(puVar3[1] + 4) + local_48 * 2;
      }
      else {
        local_44 = crypto_getStringLen(puVar3);
      }
      local_4c = local_44;
    }
    *(int *)(param_1 + 0x120) = (int)(*(int *)(param_1 + 0x114) - local_4c) >> 1;
  }
  return (undefined4 *)(param_1 + 0x120);
}



// ============================================================
// Function: certificates_applyReplace (FUN_68150730)
// Address: 68150730
// Size: 450 bytes
// Params: int param_1, int param_2, void * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_applyReplace(int param_1,int param_2,void *param_3)
{
  uint *puVar1;
  short *psVar2;
  int *piVar3;
  int iVar4;
  uint local_34;
  ushort *local_30;
  uint local_2c;
  ushort *local_28;
  ushort *local_14;
  int local_10;
  ushort *local_c;
  ushort *local_8;

  puVar1 = *(uint **)(param_2 + 0x14);
  if ((*puVar1 & 0x40000000) == 0) {
    local_30 = (ushort *)puVar1[1];
  }
  else {
    if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
      if ((*puVar1 & 0x80000000) == 0) {
        local_2c = *puVar1 >> 0xf & 0x7fff;
      }
      else {
        local_2c = 0;
      }
      local_28 = (ushort *)(*(int *)(puVar1[1] + 4) + local_2c * 2);
    }
    else {
      local_28 = (ushort *)crypto_getStringLen(puVar1);
    }
    local_30 = local_28;
  }
  local_8 = local_30;
  local_c = local_30;
  psVar2 = *(short **)(param_2 + 0x1c);
  for (local_14 = *(ushort **)(param_2 + 0x18); local_14 != (ushort *)0x0;
      local_14 = (ushort *)certs_findCharInString((short *)local_14,0x24,psVar2)) {
    iVar4 = (int)local_14 - (int)local_8 >> 1;
    memcpy(param_3,local_8,iVar4 << 1);
    param_3 = (void *)((int)param_3 + iVar4 * 2);
    local_8 = local_14;
    piVar3 = certificates_resolveBackref(param_1,local_14,param_2,&local_10);
    if (piVar3 == (int *)0x0) {
      local_14 = local_14 + 1;
    }
    else {
      iVar4 = *piVar3;
      memcpy(param_3,(void *)piVar3[1],iVar4 << 1);
      param_3 = (void *)((int)param_3 + iVar4 * 2);
      local_8 = local_8 + local_10;
      local_14 = local_14 + local_10;
    }
  }
  if ((*puVar1 & 0x40000000) == 0) {
    local_34 = *puVar1;
  }
  else {
    local_34 = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
  }
  memcpy(param_3,local_8,(local_34 - ((int)local_8 - (int)local_c >> 1)) * 2);
  return 0;
}



// ============================================================
// Function: certificates_executeReplace (FUN_68150900)
// Address: 68150900
// Size: 590 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_executeReplace(uint param_1,undefined4 param_2,int param_3)

{
  void *_Src;
  void *_Dst;
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_8;

  puVar1 = *(uint **)(param_3 + 8);
  iVar2 = *(int *)(param_3 + 0x2c);
  if ((*puVar1 & 0x40000000) == 0) {
    local_30 = puVar1[1];
  }
  else {
    if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
      if ((*puVar1 & 0x80000000) == 0) {
        local_2c = *puVar1 >> 0xf & 0x7fff;
      }
      else {
        local_2c = 0;
      }
      local_28 = *(int *)(puVar1[1] + 4) + local_2c * 2;
    }
    else {
      local_28 = crypto_getStringLen(puVar1);
    }
    local_30 = local_28;
  }
  _Src = (void *)(local_30 + iVar2 * 2);
  iVar2 = *(int *)(param_1 + 0x114) - (int)_Src >> 1;
  if ((*puVar1 & 0x40000000) == 0) {
    local_3c = puVar1[1];
  }
  else {
    if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
      if ((*puVar1 & 0x80000000) == 0) {
        local_38 = *puVar1 >> 0xf & 0x7fff;
      }
      else {
        local_38 = 0;
      }
      local_34 = *(int *)(puVar1[1] + 4) + local_38 * 2;
    }
    else {
      local_34 = crypto_getStringLen(puVar1);
    }
    local_3c = local_34;
  }
  *(int *)(param_3 + 0x2c) = (int)(*(int *)(param_1 + 0x114) - local_3c) >> 1;
  *(int *)(param_3 + 0x2c) = *(int *)(param_3 + 0x2c) + *(int *)(param_1 + 0x110);
  uVar3 = crypto_evalReplacement(param_1,param_3,&local_8);
  if (uVar3 == 0) {
    uVar4 = 0;
  }
  else {
    iVar5 = iVar2 + local_8;
    if (*(int *)(param_3 + 0x20) == 0) {
      local_40 = xtra_getPropertyById(param_1,iVar5 * 2 + 2);
    }
    else {
      local_40 = xtra_allocJSString(param_1,*(int *)(param_3 + 0x20),
                              (*(int *)(param_3 + 0x24) + iVar5) * 2 + 2);
    }
    if (local_40 == 0) {
      xtra_checkAndFlush(param_1,*(int *)(param_3 + 0x20));
      *(undefined4 *)(param_3 + 0x20) = 0;
      uVar4 = 0;
    }
    else {
      *(int *)(param_3 + 0x20) = local_40;
      *(int *)(param_3 + 0x24) = *(int *)(param_3 + 0x24) + iVar5;
      _Dst = (void *)(local_40 + *(int *)(param_3 + 0x28) * 2);
      *(int *)(param_3 + 0x28) = *(int *)(param_3 + 0x28) + iVar5;
      memcpy(_Dst,_Src,iVar2 << 1);
      certificates_applyReplace(param_1,param_3,(void *)((int)_Dst + iVar2 * 2));
      uVar4 = 1;
    }
  }
  return uVar4;
}



// ============================================================
// Function: certificates_splitString (FUN_68150b50)
// Address: 68150b50
// Size: 1270 bytes
// Params: ushort * param_1, uint param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certificates_splitString(ushort *param_1,uint param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint local_7c;
  uint *local_78;
  uint *local_74;
  uint local_70;
  uint local_6c;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_50;
  double local_3c;
  uint local_30;
  uint *local_2c;
  uint local_28;
  uint *local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_c;
  uint local_8;

  puVar2 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (puVar2 == (uint *)0x0) {
    uVar3 = 0;
  }
  else {
    param_4[-1] = (uint)puVar2 | 4;
    local_20 = runtime_createPropertyFromName((uint)param_1,&PTR_s_Array_681939b8,(undefined4 *)0x0,0,0,0);
    if (local_20 == (int *)0x0) {
      uVar3 = 0;
    }
    else {
      *param_5 = local_20;
      if (param_3 == 0) {
        local_8 = (uint)puVar2 | 4;
        uVar3 = xtra_resolvePathDir(param_1,local_20,0,&local_8);
      }
      else {
        if ((((*param_4 & 7) == 0) && ((*param_4 & 0xfffffff8) != 0)) &&
           ((undefined **)(*(uint *)(*(int *)((*param_4 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
            &PTR_s_RegExp_68193210)) {
          local_28 = xtra_getObjectTag(param_1,*param_4 & 0xfffffff8);
          local_14 = 0;
        }
        else {
          puVar4 = (uint *)certs_hashLookup((int)param_1,*param_4);
          if (puVar4 == (uint *)0x0) {
            return 0;
          }
          *param_4 = (uint)puVar4 | 4;
          if ((*puVar4 & 0x40000000) == 0) {
            local_58 = *puVar4;
          }
          else {
            local_58 = (-(uint)((*puVar4 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar4;
          }
          local_18 = local_58;
          if ((*puVar4 & 0x40000000) == 0) {
            local_64 = puVar4[1];
          }
          else {
            if ((*(uint *)puVar4[1] & 0x40000000) == 0) {
              if ((*puVar4 & 0x80000000) == 0) {
                local_60 = *puVar4 >> 0xf & 0x7fff;
              }
              else {
                local_60 = 0;
              }
              local_5c = *(int *)(puVar4[1] + 4) + local_60 * 2;
            }
            else {
              local_5c = crypto_getStringLen(puVar4);
            }
            local_64 = local_5c;
          }
          local_14 = local_64;
          local_28 = 0;
        }
        local_24 = &local_18;
        if ((param_3 < 2) || (param_4[1] == 0x80000001)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        local_30 = 0;
        if (bVar1) {
          iVar5 = runtime_parseNumber(param_1,param_4[1],&local_3c);
          if (iVar5 == 0) {
            return 0;
          }
          iVar5 = runtime_addFloat(param_1,SUB84(local_3c,0),(int)((ulonglong)local_3c >> 0x20),
                               &local_30);
          if (iVar5 == 0) {
            return 0;
          }
          if ((*puVar2 & 0x40000000) == 0) {
            local_6c = *puVar2;
          }
          else {
            local_6c = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
          }
          if (local_6c < local_30) {
            if ((*puVar2 & 0x40000000) == 0) {
              local_70 = *puVar2;
            }
            else {
              local_70 = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
            }
            local_30 = local_70 + 1;
          }
        }
        local_c = 0;
        local_1c = 0;
        do {
          do {
            uVar3 = certificates_searchString(param_1,puVar2,local_28,&local_c,(int *)local_24);
            if (((int)uVar3 < 0) || ((bVar1 && (local_30 <= local_1c)))) goto LAB_68151031;
            local_2c = certs_concatStrings((int)param_1,puVar2,local_c,uVar3 - local_c,0);
            if (local_2c == (uint *)0x0) {
              return 0;
            }
            local_8 = (uint)local_2c | 4;
            iVar5 = xtra_resolvePathDir(param_1,local_20,local_1c,&local_8);
            if (iVar5 == 0) {
              return 0;
            }
            local_1c = local_1c + 1;
            if ((local_28 != 0) && (local_24[1] != 0)) {
              local_50 = 0;
              for (; (local_50 < *(uint *)(param_1 + 0x5e) && ((!bVar1 || (local_1c < local_30))));
                  local_1c = local_1c + 1) {
                if (local_50 < *(uint *)(param_1 + 0x5e)) {
                  if (local_50 < 9) {
                    local_74 = (uint *)(param_1 + local_50 * 4 + 0x62);
                  }
                  else {
                    local_74 = (uint *)(*(int *)(param_1 + 0x86) + -0x48 + local_50 * 8);
                  }
                  local_78 = local_74;
                }
                else {
                  local_78 = &DAT_681948f8;
                }
                local_2c = certs_allocFromPool((int)param_1,(void *)local_78[1],*local_78,0);
                if (local_2c == (uint *)0x0) {
                  return 0;
                }
                local_8 = (uint)local_2c | 4;
                iVar5 = xtra_resolvePathDir(param_1,local_20,local_1c,&local_8);
                if (iVar5 == 0) {
                  return 0;
                }
                local_50 = local_50 + 1;
              }
              local_24[1] = 0;
            }
            local_c = uVar3 + *local_24;
          } while (((*(int *)(param_1 + 6) == 0) || (0x81 < *(int *)(param_1 + 6))) || (bVar1));
          if ((*puVar2 & 0x40000000) == 0) {
            local_7c = *puVar2;
          }
          else {
            local_7c = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
          }
        } while (local_c != local_7c);
LAB_68151031:
        uVar3 = (uint)(uVar3 != 0xfffffffe);
      }
    }
  }
  return uVar3;
}



// ============================================================
// Function: certificates_searchString (FUN_68151050)
// Address: 68151050
// Size: 939 bytes
// Params: void * param_1, uint * param_2, int param_3, uint * param_4, int * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certificates_searchString(void *param_1,uint *param_2,int param_3,uint *param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_c;
  uint local_8;

  local_c = *param_4;
  if ((*param_2 & 0x40000000) == 0) {
    local_24 = *param_2;
  }
  else {
    local_24 = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
  }
  if (local_24 < local_c) {
    local_c = 0xffffffff;
  }
  else {
    if ((*param_2 & 0x40000000) == 0) {
      local_30 = param_2[1];
    }
    else {
      if ((*(uint *)param_2[1] & 0x40000000) == 0) {
        if ((*param_2 & 0x80000000) == 0) {
          local_2c = *param_2 >> 0xf & 0x7fff;
        }
        else {
          local_2c = 0;
        }
        local_28 = *(int *)(param_2[1] + 4) + local_2c * 2;
      }
      else {
        local_28 = crypto_getStringLen(param_2);
      }
      local_30 = local_28;
    }
    local_14 = local_30;
    if ((*param_2 & 0x40000000) == 0) {
      local_34 = *param_2;
    }
    else {
      local_34 = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
    }
    local_8 = local_34;
    if ((((*(int *)((int)param_1 + 0xc) == 0x78) && (param_3 == 0)) &&
        (*(short *)param_5[1] == 0x20)) && (*(short *)(param_5[1] + 2) == 0)) {
      if (local_c == 0) {
        while (uVar1 = crypto_allocString((uint)*(ushort *)(local_14 + local_c * 2)),
              (uVar1 & 0x70000) == 0x40000) {
          local_c = local_c + 1;
        }
        *param_4 = local_c;
      }
      if (local_c == local_8) {
        local_c = 0xffffffff;
      }
      else {
        while ((local_c < local_8 &&
               (uVar1 = crypto_allocString((uint)*(ushort *)(local_14 + local_c * 2)),
               (uVar1 & 0x70000) != 0x40000))) {
          local_c = local_c + 1;
        }
        local_18 = local_c;
        while ((local_18 < local_8 &&
               (uVar1 = crypto_allocString((uint)*(ushort *)(local_14 + local_18 * 2)),
               (uVar1 & 0x70000) == 0x40000))) {
          local_18 = local_18 + 1;
        }
        *param_5 = local_18 - local_c;
      }
    }
    else if (param_3 == 0) {
      if (((*(int *)((int)param_1 + 0xc) == 0) || (0x81 < *(int *)((int)param_1 + 0xc))) ||
         (local_34 != 0)) {
        if (*param_5 == 0) {
          if (*(int *)((int)param_1 + 0xc) == 0x78) {
            if (local_c == local_34) {
              *param_5 = 1;
            }
            else {
              local_c = local_c + 1;
            }
          }
          else if (local_c == local_34) {
            local_38 = 0xffffffff;
            local_c = local_38;
          }
          else {
            local_c = local_c + 1;
          }
        }
        else {
          local_18 = 0;
          do {
            while( true ) {
              uVar1 = local_c + local_18;
              if (local_34 <= uVar1) {
                return uVar1;
              }
              if (*(short *)(local_30 + uVar1 * 2) == *(short *)(param_5[1] + local_18 * 2)) break;
              local_c = local_c + 1;
              local_18 = 0;
            }
            local_18 = local_18 + 1;
          } while (local_18 != *param_5);
        }
      }
      else {
        local_c = 0xffffffff;
      }
    }
    else {
      while( true ) {
        local_20 = local_c;
        iVar2 = runtime_execRegex(param_1,param_3,param_2,&local_20,1,&local_1c);
        if (iVar2 == 0) break;
        if (local_1c != 0xe) {
          *param_5 = 1;
          return local_8;
        }
        iVar2 = *(int *)((int)param_1 + 0x114);
        *param_5 = *(int *)((int)param_1 + 0x110);
        param_5[1] = iVar2;
        if ((*param_5 != 0) || (local_20 != *param_4)) {
          return local_20 - *param_5;
        }
        if (local_20 == local_8) {
          if (*(int *)((int)param_1 + 0xc) == 0x78) {
            *param_5 = 1;
            return local_20;
          }
          return 0xffffffff;
        }
        local_c = local_20 + 1;
      }
      local_c = 0xfffffffe;
    }
  }
  return local_c;
}



// ============================================================
// Function: certificates_sliceString (FUN_68151400)
// Address: 68151400
// Size: 447 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_sliceString(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  float10 fVar2;
  uint local_54;
  uint local_44;
  uint local_2c;
  uint *local_28;
  double local_24;
  double local_1c;
  double local_14;
  double local_c;

  local_28 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (local_28 == (uint *)0x0) {
    return 0;
  }
  if (param_3 != 0) {
    iVar1 = runtime_parseNumber(param_1,*param_4,&local_24);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*local_28 & 0x40000000) == 0) {
      local_2c = *local_28;
    }
    else {
      local_2c = (-(uint)((*local_28 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_28;
    }
    local_14 = (double)local_2c;
    fVar2 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
    local_c = (double)fVar2;
    if (0.0 <= local_c) {
      if (local_14 < local_c) {
        local_c = local_14;
      }
    }
    else {
      local_c = local_c + local_14;
      if (local_c < 0.0) {
        local_c = 0.0;
      }
    }
    if (param_3 == 1) {
      local_1c = local_14;
    }
    else {
      iVar1 = runtime_parseNumber(param_1,param_4[1],&local_24);
      if (iVar1 == 0) {
        return 0;
      }
      fVar2 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
      local_1c = (double)fVar2;
      if (local_1c < 0.0) {
        local_1c = 0.0;
      }
      local_1c = local_1c + local_c;
      if (local_14 < local_1c) {
        local_1c = local_14;
      }
    }
    local_44 = (uint)(longlong)ROUND(local_1c - local_c);
    local_54 = (uint)(longlong)ROUND(local_c);
    local_28 = certs_concatStrings((int)param_1,local_28,local_54,local_44,0);
    if (local_28 == (uint *)0x0) {
      return 0;
    }
  }
  *param_5 = (uint)local_28 | 4;
  return 1;
}



// ============================================================
// Function: certificates_concatArgs (FUN_681515c0)
// Address: 681515c0
// Size: 174 bytes
// Params: int param_1, uint param_2, uint param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_concatArgs(int param_1,uint param_2,uint param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *local_10;
  uint local_8;

  local_10 = (uint *)certs_hashLookup(param_1,param_2);
  if (local_10 == (uint *)0x0) {
    uVar1 = 0;
  }
  else {
    *(uint *)(param_4 + -4) = (uint)local_10 | 4;
    for (local_8 = 0; local_8 < param_3; local_8 = local_8 + 1) {
      puVar2 = (uint *)certs_hashLookup(param_1,*(uint *)(param_4 + local_8 * 4));
      if (puVar2 == (uint *)0x0) {
        return 0;
      }
      *(uint *)(param_4 + local_8 * 4) = (uint)puVar2 | 4;
      local_10 = crypto_concatStrings(param_1,local_10,puVar2);
      if (local_10 == (uint *)0x0) {
        return 0;
      }
    }
    *param_5 = (uint)local_10 | 4;
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: certificates_substringRange (FUN_68151670)
// Address: 68151670
// Size: 494 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certificates_substringRange(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  float10 fVar2;
  uint local_54;
  uint local_44;
  uint local_2c;
  uint *local_28;
  double local_24;
  double local_1c;
  double local_14;
  double local_c;

  local_28 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (local_28 == (uint *)0x0) {
    return 0;
  }
  param_4[-1] = (uint)local_28 | 4;
  if (param_3 != 0) {
    iVar1 = runtime_parseNumber(param_1,*param_4,&local_24);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*local_28 & 0x40000000) == 0) {
      local_2c = *local_28;
    }
    else {
      local_2c = (-(uint)((*local_28 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_28;
    }
    local_14 = (double)local_2c;
    fVar2 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
    local_c = (double)fVar2;
    if (0.0 <= local_c) {
      if (local_14 < local_c) {
        local_c = local_14;
      }
    }
    else {
      local_c = local_c + local_14;
      if (local_c < 0.0) {
        local_c = 0.0;
      }
    }
    if (param_3 == 1) {
      local_1c = local_14;
    }
    else {
      iVar1 = runtime_parseNumber(param_1,param_4[1],&local_24);
      if (iVar1 == 0) {
        return 0;
      }
      fVar2 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
      local_1c = (double)fVar2;
      if (0.0 <= local_1c) {
        if (local_14 < local_1c) {
          local_1c = local_14;
        }
      }
      else {
        local_1c = local_1c + local_14;
        if (local_1c < 0.0) {
          local_1c = 0.0;
        }
      }
      if (local_1c < local_c) {
        local_1c = local_c;
      }
    }
    local_44 = (uint)(longlong)ROUND(local_1c - local_c);
    local_54 = (uint)(longlong)ROUND(local_c);
    local_28 = certs_concatStrings((int)param_1,local_28,local_54,local_44,0);
    if (local_28 == (uint *)0x0) {
      return 0;
    }
  }
  *param_5 = (uint)local_28 | 4;
  return 1;
}



// ============================================================
// Function: certificates_wrapHtmlBold (FUN_68151860)
// Address: 68151860
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlBold(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"b",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certs_parseHtmlTag (FUN_68151890)
// Address: 68151890
// Size: 939 bytes
// Params: int param_1, uint param_2, int param_3, char * param_4, short * param_5, char * param_6, uint * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certs_parseHtmlTag(int param_1,uint param_2,int param_3,char *param_4,short *param_5,char *param_6,
            uint *param_7)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  size_t sVar4;
  size_t sVar5;
  undefined2 *puVar6;
  uint local_3c;
  void *local_38;
  uint local_34;
  void *local_30;
  uint local_2c;
  uint local_28;
  int local_20;
  int local_1c;
  uint local_10;
  int local_8;

  puVar2 = (uint *)certs_hashLookup(param_1,param_2);
  if (puVar2 == (uint *)0x0) {
    uVar3 = 0;
  }
  else {
    *(uint *)(param_3 + -4) = (uint)puVar2 | 4;
    if (param_6 == (char *)0x0) {
      param_6 = param_4;
    }
    sVar4 = strlen(param_4);
    local_8 = sVar4 + 2;
    local_20 = 0;
    if (param_5 != (short *)0x0) {
      local_20 = certs_getStringLength(param_5);
      local_8 = sVar4 + 5 + local_20;
    }
    sVar5 = strlen(param_6);
    if ((*puVar2 & 0x40000000) == 0) {
      local_28 = *puVar2;
    }
    else {
      local_28 = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
    }
    uVar1 = local_8 + local_28 + 3 + sVar5;
    puVar6 = (undefined2 *)xtra_getPropertyById(param_1,uVar1 * 2 + 2);
    if (puVar6 == (undefined2 *)0x0) {
      uVar3 = 0;
    }
    else {
      *puVar6 = 0x3c;
      local_1c = 1;
      for (local_10 = 0; local_10 < sVar4; local_10 = local_10 + 1) {
        puVar6[local_1c] = (short)param_4[local_10];
        local_1c = local_1c + 1;
      }
      if (param_5 != (short *)0x0) {
        puVar6[local_1c] = 0x3d;
        puVar6[local_1c + 1] = 0x22;
        memcpy(puVar6 + local_1c + 2,param_5,local_20 << 1);
        local_20 = local_1c + 2 + local_20;
        puVar6[local_20] = 0x22;
        local_1c = local_20 + 1;
      }
      puVar6[local_1c] = 0x3e;
      if ((*puVar2 & 0x40000000) == 0) {
        local_2c = *puVar2;
      }
      else {
        local_2c = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
      }
      if ((*puVar2 & 0x40000000) == 0) {
        local_38 = (void *)puVar2[1];
      }
      else {
        if ((*(uint *)puVar2[1] & 0x40000000) == 0) {
          if ((*puVar2 & 0x80000000) == 0) {
            local_34 = *puVar2 >> 0xf & 0x7fff;
          }
          else {
            local_34 = 0;
          }
          local_30 = (void *)(*(int *)(puVar2[1] + 4) + local_34 * 2);
        }
        else {
          local_30 = (void *)crypto_getStringLen(puVar2);
        }
        local_38 = local_30;
      }
      memcpy(puVar6 + local_1c + 1,local_38,local_2c << 1);
      if ((*puVar2 & 0x40000000) == 0) {
        local_3c = *puVar2;
      }
      else {
        local_3c = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
      }
      local_1c = local_1c + 1 + local_3c;
      puVar6[local_1c] = 0x3c;
      puVar6[local_1c + 1] = 0x2f;
      local_1c = local_1c + 2;
      for (local_10 = 0; local_10 < sVar5; local_10 = local_10 + 1) {
        puVar6[local_1c] = (short)param_6[local_10];
        local_1c = local_1c + 1;
      }
      puVar6[local_1c] = 0x3e;
      puVar6[local_1c + 1] = 0;
      puVar2 = certs_allocHashEntry(param_1,(uint)puVar6,uVar1,0);
      if (puVar2 == (uint *)0x0) {
        js_freeHandle();
        uVar3 = 0;
      }
      else {
        *param_7 = (uint)puVar2 | 4;
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}



// ============================================================
// Function: certificates_wrapHtmlItalic (FUN_68151c40)
// Address: 68151c40
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlItalic(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"i",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlFixed (FUN_68151c70)
// Address: 68151c70
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlFixed(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"tt",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlFontSize (FUN_68151ca0)
// Address: 68151ca0
// Size: 38 bytes
// Params: int param_1, uint param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlFontSize(int param_1,uint param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  certs_parseFontAttr(param_1,param_2,param_4,"font size","font",param_5);
  return 0;
}



// ============================================================
// Function: certs_parseFontAttr (FUN_68151cd0)
// Address: 68151cd0
// Size: 201 bytes
// Params: int param_1, uint param_2, uint * param_3, char * param_4, char * param_5, uint * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certs_parseFontAttr(int param_1,uint param_2,uint *param_3,char *param_4,char *param_5,uint *param_6)

{
  uint *puVar1;
  undefined4 uVar2;
  short *local_14;
  uint local_10;
  short *local_c;

  puVar1 = (uint *)certs_hashLookup(param_1,*param_3);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    *param_3 = (uint)puVar1 | 4;
    if ((*puVar1 & 0x40000000) == 0) {
      local_14 = (short *)puVar1[1];
    }
    else {
      if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
        if ((*puVar1 & 0x80000000) == 0) {
          local_10 = *puVar1 >> 0xf & 0x7fff;
        }
        else {
          local_10 = 0;
        }
        local_c = (short *)(*(int *)(puVar1[1] + 4) + local_10 * 2);
      }
      else {
        local_c = (short *)crypto_getStringLen(puVar1);
      }
      local_14 = local_c;
    }
    uVar2 = certs_parseHtmlTag(param_1,param_2,(int)param_3,param_4,local_14,param_5,param_6);
  }
  return uVar2;
}



// ============================================================
// Function: certificates_wrapHtmlFontColor (FUN_68151da0)
// Address: 68151da0
// Size: 38 bytes
// Params: int param_1, uint param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlFontColor(int param_1,uint param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  certs_parseFontAttr(param_1,param_2,param_4,"font color","font",param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlAnchorHref (FUN_68151dd0)
// Address: 68151dd0
// Size: 38 bytes
// Params: int param_1, uint param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlAnchorHref(int param_1,uint param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  certs_parseFontAttr(param_1,param_2,param_4,"a href","a",param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlAnchorName (FUN_68151e00)
// Address: 68151e00
// Size: 38 bytes
// Params: int param_1, uint param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlAnchorName(int param_1,uint param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  certs_parseFontAttr(param_1,param_2,param_4,"a name","a",param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlStrike (FUN_68151e30)
// Address: 68151e30
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlStrike(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"strike",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlSmall (FUN_68151e60)
// Address: 68151e60
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlSmall(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"small",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlBig (FUN_68151e90)
// Address: 68151e90
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlBig(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"big",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlBlink (FUN_68151ec0)
// Address: 68151ec0
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlBlink(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"blink",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



// ============================================================
// Function: certificates_wrapHtmlSup (FUN_68151ef0)
// Address: 68151ef0
// Size: 37 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_wrapHtmlSup(int param_1,uint param_2,undefined4 param_3,int param_4,uint *param_5)
{
  certs_parseHtmlTag(param_1,param_2,param_4,"sup",(short *)0x0,(char *)0x0,param_5);
  return 0;
}



