// Module: strings
// Topic: XML cross-domain policy, character encoding, cast context management
// Address range: 0x681689f0 - 0x6816a240
// Functions (23):
//   strings_parseCrossDomainPolicy (FUN_681689f0)
//   strings_loadCrossDomainPolicy (FUN_68169340)
//   strings_clampPolicyRange (FUN_68169500)
//   strings_getDefaultCastType (FUN_68169530)
//   strings_convertEncoding
//   strings_multiToWide
//   strings_wideToMulti
//   strings_validateCodePage (FUN_68169720)
//   strings_loadCastContext (FUN_68169740)
//   strings_openCastMembers (FUN_681699f0)
//   strings_installCastHandlers (FUN_68169c00)
//   strings_saveScriptContext (FUN_68169c40)
//   strings_restoreScriptContext (FUN_68169c60)
//   strings_openCastContext (FUN_68169c80)
//   strings_serializeSymbols (FUN_68169d60)
//   strings_resetMemberBreakpoints (FUN_68169e80)
//   strings_saveCastMembers (FUN_68169ed0)
//   strings_saveCastContext (FUN_68169fc0)
//   strings_clearCastBreakpoints (FUN_6816a040)
//   strings_assignCastResources (FUN_6816a090)
//   strings_debugLineCallback (FUN_6816a1c0)
//   strings_debugErrorCallback (FUN_6816a240)

// ============================================================
// Function: strings_parseCrossDomainPolicy (FUN_681689f0)
// Address: 681689f0
// Size: 2373 bytes
// Params: char * param_1, uint * param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_parseCrossDomainPolicy(char *param_1,uint *param_2,int *param_3,int param_4)
{
  byte bVar1;
  LPCWSTR pWVar2;
  int iVar3;
  BSTR pOVar4;
  uint uVar5;
  byte *pbVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  char cVar14;
  byte *pbVar15;
  byte *pbVar16;
  code *pcVar17;
  bool bVar18;
  undefined1 local_6c [8];
  LPCWSTR local_64;
  LPCWSTR local_5c;
  int local_58;
  char *local_54;
  LPCWSTR local_50;
  uint *local_4c;
  int local_48;
  LPCWSTR local_44;
  int *local_40;
  uint local_3c;
  BSTR local_38;
  int *local_34;
  int *local_30;
  byte *local_2c;
  byte *local_28;
  byte *local_24;
  BSTR local_20;
  int local_1c;
  byte *local_18;
  int *local_14;
  byte local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 uStack_c;
  undefined1 local_b;
  uint local_8;
  
  *param_2 = 0;
  uStack_f = 0;
  uStack_e = 0;
  uStack_d = 0;
  uStack_c = 0;
  local_b = 0;
  local_40 = (int *)0x0;
  local_48 = 0;
  local_34 = (int *)0x0;
  local_14 = (int *)0x0;
  local_30 = (int *)0x0;
  local_38 = (BSTR)0x0;
  local_20 = (BSTR)0x0;
  local_5c = (LPCWSTR)0x0;
  local_28 = (byte *)0x0;
  local_50 = (LPCWSTR)0x0;
  local_18 = (byte *)0x0;
  local_44 = (LPCWSTR)0x0;
  local_2c = (byte *)0x0;
  local_10 = 0;
  local_54 = param_1;
  local_4c = param_2;
  iVar3 = (**(code **)(*param_3 + 0x30))(param_3,&local_40);
  pcVar17 = SysFreeString_exref;
  if ((-1 < iVar3) &&
     ((local_40 == (int *)0x0 ||
      (iVar3 = (**(code **)(*local_40 + 0x20))(local_40,&local_48), pcVar17 = SysFreeString_exref,
      -1 < iVar3)))) {
    pcVar8 = param_1 + 1;
    do {
      cVar14 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar14 != '\0');
    local_28 = operator_new((uint)(param_1 + (1 - (int)pcVar8)));
    local_58 = 0;
    pcVar17 = SysFreeString_exref;
    if (0 < local_48) {
      pOVar4 = (BSTR)0x0;
      do {
        iVar3 = local_58;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
        local_1c = (**(code **)(*local_40 + 0x1c))(local_40,iVar3,&local_34);
        if (local_1c < 0) break;
        if (local_38 != (BSTR)0x0) {
          SysFreeString(local_38);
        }
        local_1c = (**(code **)(*local_34 + 0x1c))(local_34,&local_38);
        if (local_1c < 0) goto LAB_68169317;
        iVar3 = lstrcmpW(local_38,L"allow-access-from");
        if (iVar3 != 0) goto LAB_681691a4;
        if (local_30 != (int *)0x0) {
          (**(code **)(*local_30 + 8))(local_30);
        }
        iVar3 = (**(code **)(*local_34 + 0x44))(local_34,&local_30);
        if (iVar3 < 0) break;
        if (pOVar4 != (BSTR)0x0) {
          SysFreeString(pOVar4);
        }
        pOVar4 = SysAllocString(L"domain");
        local_20 = pOVar4;
        if (local_14 != (int *)0x0) {
          (**(code **)(*local_14 + 8))(local_14);
        }
        local_1c = (**(code **)(*local_30 + 0x1c))(local_30,pOVar4,&local_14);
        if ((local_1c < 0) ||
           (local_1c = (**(code **)(*local_14 + 0x20))(local_14,local_6c), local_1c < 0)) break;
        if (local_50 != (BSTR)0x0) {
          SysFreeString(local_50);
        }
        pWVar2 = local_64;
        local_50 = local_64;
        uVar5 = WideCharToMultiByte(0xfde9,0,local_64,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
        local_3c = uVar5;
        if (0 < (int)uVar5) {
          if (local_18 != (byte *)0x0) {
            operator_delete(local_18);
          }
          local_18 = operator_new(uVar5);
          WideCharToMultiByte(0xfde9,0,pWVar2,-1,(LPSTR)local_18,uVar5,(LPCSTR)0x0,(LPBOOL)0x0);
        }
        pbVar6 = local_18;
        do {
          bVar1 = *pbVar6;
          pbVar6 = pbVar6 + 1;
        } while (bVar1 != 0);
        Ordinal_1217(local_18,(int)pbVar6 - (int)(local_18 + 1));
        pbVar6 = local_28;
        pcVar8 = local_54;
        pcVar7 = local_54;
        do {
          cVar14 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar14 != '\0');
        memset(local_28,0,(size_t)(pcVar7 + (1 - (int)(local_54 + 1))));
        iVar3 = (int)pbVar6 - (int)pcVar8;
        do {
          cVar14 = *pcVar8;
          pcVar8[iVar3] = cVar14;
          pcVar8 = pcVar8 + 1;
        } while (cVar14 != '\0');
        pcVar8 = strstr((char *)pbVar6,"://");
        pbVar11 = local_18;
        if (pcVar8 != (char *)0x0) {
          *pcVar8 = '\0';
          pbVar16 = &DAT_68182654;
          pbVar15 = pbVar6;
          do {
            bVar1 = *pbVar15;
            bVar18 = bVar1 < *pbVar16;
            if (bVar1 != *pbVar16) {
LAB_68168c90:
              iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
              goto LAB_68168c95;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar15[1];
            bVar18 = bVar1 < pbVar16[1];
            if (bVar1 != pbVar16[1]) goto LAB_68168c90;
            pbVar15 = pbVar15 + 2;
            pbVar16 = pbVar16 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_68168c95:
          if (iVar3 == 0) {
            local_10 = 0x38;
            uStack_f = 0x30;
            uStack_e = 0;
          }
          else {
            pbVar16 = &DAT_68182648;
            pbVar15 = pbVar6;
            do {
              bVar1 = *pbVar15;
              bVar18 = bVar1 < *pbVar16;
              if (bVar1 != *pbVar16) {
LAB_68168cd6:
                iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                goto LAB_68168cdb;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar15[1];
              bVar18 = bVar1 < pbVar16[1];
              if (bVar1 != pbVar16[1]) goto LAB_68168cd6;
              pbVar15 = pbVar15 + 2;
              pbVar16 = pbVar16 + 2;
            } while (bVar1 != 0);
            iVar3 = 0;
LAB_68168cdb:
            if (iVar3 == 0) {
              local_10 = 0x34;
              uStack_f = 0x34;
              uStack_e = 0x33;
              uStack_d = 0;
            }
            else {
              pbVar16 = &DAT_68182644;
              pbVar15 = pbVar6;
              do {
                bVar1 = *pbVar15;
                bVar18 = bVar1 < *pbVar16;
                if (bVar1 != *pbVar16) {
LAB_68168d10:
                  iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                  goto LAB_68168d15;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar15[1];
                bVar18 = bVar1 < pbVar16[1];
                if (bVar1 != pbVar16[1]) goto LAB_68168d10;
                pbVar15 = pbVar15 + 2;
                pbVar16 = pbVar16 + 2;
              } while (bVar1 != 0);
              iVar3 = 0;
LAB_68168d15:
              if (iVar3 == 0) {
                local_10 = 0x32;
                uStack_f = 0x31;
                uStack_e = 0;
              }
            }
          }
          pcVar8 = pcVar8 + 3;
          iVar3 = (int)pbVar6 - (int)pcVar8;
          do {
            cVar14 = *pcVar8;
            pcVar8[iVar3] = cVar14;
            pcVar8 = pcVar8 + 1;
          } while (cVar14 != '\0');
        }
        pbVar16 = &DAT_6817b910;
        pbVar15 = local_18;
        do {
          bVar1 = *pbVar15;
          bVar18 = bVar1 < *pbVar16;
          if (bVar1 != *pbVar16) {
LAB_68168d67:
            iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
            goto LAB_68168d6c;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar15[1];
          bVar18 = bVar1 < pbVar16[1];
          if (bVar1 != pbVar16[1]) goto LAB_68168d67;
          pbVar15 = pbVar15 + 2;
          pbVar16 = pbVar16 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_68168d6c:
        if (iVar3 == 0) {
          pcVar8 = strchr((char *)pbVar6,0x2f);
          if (pcVar8 != (char *)0x0) {
            *pcVar8 = '\0';
          }
          pcVar8 = strchr((char *)pbVar6,0x3a);
          if (pcVar8 != (char *)0x0) {
            *pcVar8 = '\0';
            local_24 = (byte *)(pcVar8 + 1);
            goto LAB_68168f5d;
          }
          local_24 = &local_10;
LAB_68168f67:
          if (*local_24 != 0) {
            if (local_20 != (BSTR)0x0) {
              SysFreeString(local_20);
            }
            pOVar4 = SysAllocString(L"to-ports");
            local_20 = pOVar4;
            if (local_14 != (int *)0x0) {
              (**(code **)(*local_14 + 8))(local_14);
            }
            local_1c = (**(code **)(*local_30 + 0x1c))(local_30,pOVar4,&local_14);
            if (local_1c < 0) break;
            if (local_14 != (int *)0x0) {
              local_1c = (**(code **)(*local_14 + 0x20))(local_14,local_6c);
              if (local_1c < 0) break;
              if (local_44 != (BSTR)0x0) {
                SysFreeString(local_44);
              }
              pWVar2 = local_64;
              local_44 = local_64;
              uVar5 = WideCharToMultiByte(0xfde9,0,local_64,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0)
              ;
              pbVar6 = local_2c;
              local_3c = uVar5;
              if (0 < (int)uVar5) {
                if (local_2c != (byte *)0x0) {
                  operator_delete(local_2c);
                }
                pbVar6 = operator_new(uVar5);
                local_2c = pbVar6;
                WideCharToMultiByte(0xfde9,0,pWVar2,-1,(LPSTR)pbVar6,uVar5,(LPCSTR)0x0,(LPBOOL)0x0);
              }
              pbVar11 = &DAT_6817b910;
              do {
                bVar1 = *pbVar6;
                bVar18 = bVar1 < *pbVar11;
                if (bVar1 != *pbVar11) {
LAB_681690b0:
                  iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                  goto LAB_681690b5;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar6[1];
                bVar18 = bVar1 < pbVar11[1];
                if (bVar1 != pbVar11[1]) goto LAB_681690b0;
                pbVar6 = pbVar6 + 2;
                pbVar11 = pbVar11 + 2;
              } while (bVar1 != 0);
              iVar3 = 0;
LAB_681690b5:
              pbVar6 = local_2c;
              if (iVar3 != 0) {
                do {
                  pcVar8 = strchr((char *)pbVar6,0x2c);
                  if (pcVar8 != (char *)0x0) {
                    *pcVar8 = '\0';
                  }
                  pbVar11 = local_24;
                  pbVar15 = pbVar6;
                  if ((*pbVar6 == 0x20) && (pbVar16 = pbVar6 + 1, pbVar16 <= local_2c + local_3c)) {
                    pbVar6 = pbVar16;
                    pbVar15 = pbVar16;
                  }
                  do {
                    bVar1 = *pbVar6;
                    bVar18 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_68169110:
                      iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                      goto LAB_68169115;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar6[1];
                    bVar18 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_68169110;
                    pbVar6 = pbVar6 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar3 = 0;
LAB_68169115:
                  if (iVar3 == 0) goto LAB_681691bc;
                  pbVar11 = &DAT_6817b910;
                  pbVar6 = pbVar15;
                  do {
                    bVar1 = *pbVar6;
                    bVar18 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_68169144:
                      iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                      goto LAB_68169149;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar6[1];
                    bVar18 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_68169144;
                    pbVar6 = pbVar6 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar3 = 0;
LAB_68169149:
                  if (iVar3 == 0) goto LAB_681691bc;
                  pcVar7 = strchr((char *)pbVar15,0x2d);
                  if (pcVar7 != (char *)0x0) {
                    *pcVar7 = '\0';
                    iVar3 = atoi((char *)pbVar15);
                    iVar12 = atoi(pcVar7 + 1);
                    iVar13 = atoi((char *)local_24);
                    if ((iVar3 <= iVar13) && (iVar13 <= iVar12)) goto LAB_681691bc;
                  }
                } while ((pcVar8 != (char *)0x0) &&
                        (pbVar6 = (byte *)(pcVar8 + 1), pbVar6 <= local_2c + local_3c));
                goto LAB_681691a4;
              }
            }
          }
LAB_681691bc:
          if ((param_4 == 0) || (iVar3 = _strnicmp(local_54,"https",5), iVar3 == 0)) {
            *local_4c = 1;
          }
          else {
            if (local_20 != (BSTR)0x0) {
              SysFreeString(local_20);
            }
            pOVar4 = SysAllocString(L"secure");
            local_20 = pOVar4;
            if (local_14 != (int *)0x0) {
              (**(code **)(*local_14 + 8))(local_14);
            }
            local_1c = (**(code **)(*local_30 + 0x1c))(local_30,pOVar4,&local_14);
            if (-1 < local_1c) {
              if (local_14 == (int *)0x0) {
                *local_4c = 0;
              }
              else {
                local_1c = (**(code **)(*local_14 + 0x20))(local_14,local_6c);
                if (-1 < local_1c) {
                  local_5c = local_64;
                  iVar3 = lstrcmpiW(local_64,L"false");
                  *local_4c = (uint)(iVar3 == 0);
                }
              }
            }
          }
          break;
        }
        pcVar8 = strstr((char *)local_18,"://");
        if (pcVar8 != (char *)0x0) {
          *pcVar8 = '\0';
          pbVar15 = (byte *)(pcVar8 + 3);
          if (pbVar15 <= pbVar11 + local_3c) {
            iVar3 = (int)pbVar11 - (int)pbVar15;
            do {
              bVar1 = *pbVar15;
              pbVar15[iVar3] = bVar1;
              pbVar15 = pbVar15 + 1;
            } while (bVar1 != 0);
          }
        }
        pcVar17 = strchr_exref;
        pcVar8 = strchr((char *)pbVar6,0x2f);
        pcVar7 = strchr((char *)local_18,0x2f);
        if (pcVar8 != (char *)0x0) {
          *pcVar8 = '\0';
          pcVar8 = pcVar8 + 1;
        }
        if (pcVar7 == (char *)0x0) {
LAB_68168e19:
          if (pcVar8 != (char *)0x0) {
LAB_68168e1d:
            *pcVar8 = '\0';
          }
          puVar10 = (undefined1 *)(*pcVar17)(pbVar6,0x3a);
          if (puVar10 == (undefined1 *)0x0) {
            local_24 = &local_10;
          }
          else {
            *puVar10 = 0;
            local_24 = puVar10 + 1;
          }
          pcVar17 = strrchr_exref;
          pbVar6 = (byte *)strrchr((char *)local_28,0x2e);
          pbVar11 = (byte *)strrchr((char *)local_18,0x2e);
          while ((pbVar11 != (byte *)0x0 && (pbVar6 != (byte *)0x0))) {
            pbVar16 = &DAT_6817b910;
            pbVar15 = pbVar11 + 1;
            do {
              bVar1 = *pbVar15;
              bVar18 = bVar1 < *pbVar16;
              if (bVar1 != *pbVar16) {
LAB_68168e90:
                iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                goto LAB_68168e95;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar15[1];
              bVar18 = bVar1 < pbVar16[1];
              if (bVar1 != pbVar16[1]) goto LAB_68168e90;
              pbVar15 = pbVar15 + 2;
              pbVar16 = pbVar16 + 2;
            } while (bVar1 != 0);
            iVar3 = 0;
LAB_68168e95:
            pbVar15 = pbVar11;
            pbVar16 = pbVar6;
            if (iVar3 != 0) {
              do {
                bVar1 = *pbVar15;
                bVar18 = bVar1 < *pbVar16;
                if (bVar1 != *pbVar16) {
LAB_68168ec0:
                  iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                  goto LAB_68168ec5;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar15[1];
                bVar18 = bVar1 < pbVar16[1];
                if (bVar1 != pbVar16[1]) goto LAB_68168ec0;
                pbVar15 = pbVar15 + 2;
                pbVar16 = pbVar16 + 2;
              } while (bVar1 != 0);
              iVar3 = 0;
LAB_68168ec5:
              pcVar17 = strrchr_exref;
              if (iVar3 != 0) goto LAB_681691a4;
            }
            *pbVar11 = 0;
            *pbVar6 = 0;
            pbVar6 = (byte *)(*pcVar17)(local_28,0x2e);
            pbVar11 = (byte *)(*pcVar17)(local_18,0x2e);
          }
          pbVar11 = &DAT_6817b910;
          pbVar6 = local_18;
          do {
            bVar1 = *pbVar6;
            bVar18 = bVar1 < *pbVar11;
            if (bVar1 != *pbVar11) {
LAB_68168f22:
              iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
              goto LAB_68168f27;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar18 = bVar1 < pbVar11[1];
            if (bVar1 != pbVar11[1]) goto LAB_68168f22;
            pbVar6 = pbVar6 + 2;
            pbVar11 = pbVar11 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_68168f27:
          pbVar6 = local_28;
          pbVar11 = local_18;
          if (iVar3 != 0) {
            do {
              bVar1 = *pbVar6;
              bVar18 = bVar1 < *pbVar11;
              if (bVar1 != *pbVar11) {
LAB_68168f50:
                iVar3 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
                goto LAB_68168f55;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar6[1];
              bVar18 = bVar1 < pbVar11[1];
              if (bVar1 != pbVar11[1]) goto LAB_68168f50;
              pbVar6 = pbVar6 + 2;
              pbVar11 = pbVar11 + 2;
            } while (bVar1 != 0);
            iVar3 = 0;
LAB_68168f55:
            if (iVar3 != 0) goto LAB_681691a4;
          }
LAB_68168f5d:
          if (local_24 != (byte *)0x0) goto LAB_68168f67;
          goto LAB_681691bc;
        }
        pcVar9 = pcVar7 + 1;
        *pcVar7 = '\0';
        if (pcVar9 == (char *)0x0) goto LAB_68168e19;
        if (pcVar8 != (char *)0x0) {
          cVar14 = *pcVar9;
          if (cVar14 == *pcVar8) {
            do {
              if (*pcVar8 == '\0') break;
              if (cVar14 == '\0') goto LAB_68168e00;
              cVar14 = pcVar9[1];
              pcVar9 = pcVar9 + 1;
              pcVar8 = pcVar8 + 1;
            } while (cVar14 == *pcVar8);
          }
          if ((*pcVar9 != '\0') && (*pcVar8 != *pcVar9)) goto LAB_681691a4;
LAB_68168e00:
          pcVar17 = strchr_exref;
          pbVar6 = local_28;
          if ((*pcVar8 != '\0') && (*pcVar8 != '/')) goto LAB_681691a4;
          goto LAB_68168e1d;
        }
LAB_681691a4:
        local_58 = local_58 + 1;
        pOVar4 = local_20;
      } while (local_58 < local_48);
      pcVar17 = SysFreeString_exref;
      if (local_50 != (BSTR)0x0) {
        SysFreeString(local_50);
      }
    }
  }
  if (local_38 != (BSTR)0x0) {
    (*pcVar17)(local_38);
  }
  if (local_5c != (LPCWSTR)0x0) {
    (*pcVar17)(local_5c);
  }
  if (local_20 != (BSTR)0x0) {
    (*pcVar17)(local_20);
  }
  if (local_18 != (byte *)0x0) {
    operator_delete(local_18);
  }
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  if (local_28 != (byte *)0x0) {
    operator_delete(local_28);
  }
  if (local_2c != (byte *)0x0) {
    operator_delete(local_2c);
  }
  if (local_44 != (LPCWSTR)0x0) {
    (*pcVar17)(local_44);
  }
LAB_68169317:
  return 0;
}



// ============================================================
// Function: strings_loadCrossDomainPolicy (FUN_68169340)
// Address: 68169340
// Size: 436 bytes
// Params: char * param_1, char * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_loadCrossDomainPolicy(char *param_1,char *param_2,uint *param_3)
{
  char *lpMultiByteStr;
  int iVar1;
  uint cchWideChar;
  BSTR bstrString;
  HRESULT HVar2;
  LPWSTR lpWideCharStr;
  _union_2683 local_24;
  int local_14;
  LPCWSTR local_10;
  int *local_c;
  int *local_8;
  
  lpMultiByteStr = param_1;
  lpWideCharStr = (OLECHAR *)0x0;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = (LPCWSTR)0x0;
  local_14 = 0;
  iVar1 = _strnicmp(param_1,"https",5);
  if (iVar1 == 0) {
    local_14 = 1;
  }
  *param_3 = 3;
  cchWideChar = MultiByteToWideChar(0xfde9,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (0 < (int)cchWideChar) {
    lpWideCharStr =
         operator_new(-(uint)((int)((ulonglong)cchWideChar * 2 >> 0x20) != 0) |
                      (uint)((ulonglong)cchWideChar * 2));
    MultiByteToWideChar(0xfde9,0,lpMultiByteStr,-1,lpWideCharStr,cchWideChar);
  }
  bstrString = SysAllocString(lpWideCharStr);
  VariantInit((VARIANTARG *)&(*((int *)&local_24 + 2)));
  /* FIXUP(C2224: left of '.vt' must have struct/union type): (*((int *)&local_24 + 2)).vt = 8; */
  (*(unsigned int *)((char *)&local_24 + 8)) = bstrString;
  HVar2 = CoCreateInstance((IID *)&DAT_68182754,(LPUNKNOWN)0x0,1,(IID *)&DAT_68182744,&local_8);
  if (-1 < HVar2) {
    (**(code **)(*local_8 + 0xfc))(local_8,0);
    (**(code **)(*local_8 + 0x110))(local_8,0);
    /* FIXUP(C2143-ctx): iVar1 = (**(code **)(*local_8 + 0xe8)) */
                      /* FIXUP(C2224: left of '.Hi32' must have struct/union type): (local_8,(*(unsigned int *)((char *)&local_24 + 0)),(*((int *)&local_24 + 0)).Hi32,(*(unsigned int *)((char *)&local_24 + 8)),(*(unsigned int *)((char *)&local_24 + 12)), */
                       /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: ')'): &param_1); */
    if ((-1 < iVar1) && ((short)param_1 == -1)) { /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */;
      iVar1 = (**(code **)(*local_8 + 0xb4))(local_8,&local_c);
      if (-1 < iVar1) {
        (**(code **)(*local_c + 0xac))(local_c,&local_10);
        iVar1 = lstrcmpW(local_10,L"cross-domain-policy");
        if (iVar1 == 0) {
          strings_parseCrossDomainPolicy(param_2,param_3,local_c,local_14);
        }
      }
    }
  }
  if (lpWideCharStr != (OLECHAR *)0x0) {
    operator_delete(lpWideCharStr);
  }
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  if (local_10 != (BSTR)0x0) {
    SysFreeString(local_10);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return 0;
}



// ============================================================
// Function: strings_clampPolicyRange (FUN_68169500)
// Address: 68169500
// Size: 45 bytes
// Params: uint * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_clampPolicyRange(uint *param_1)

{
  if (*param_1 < 8) {
    *param_1 = 8;
    return 0;
  }
  if (0x20 < *param_1) {
    *param_1 = 0x20;
  }
  return 1;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: strings_convertEncoding (FUN_68169540)
// Address: 68169540
// Size: 251 bytes
// Params: ushort param_1, ushort param_2, LPCSTR param_3, int param_4, LPSTR param_5, int * param_6, LPCSTR param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
strings_convertEncoding(ushort param_1,ushort param_2,LPCSTR param_3,int param_4,LPSTR param_5,int *param_6,
            LPCSTR param_7)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  LPCWSTR local_8;
  
  local_c = 0;
  local_8 = (LPCWSTR)0x0;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = MultiByteToWideChar((uint)param_1,0,param_3,param_4,(LPWSTR)0x0,0);
    if (0 < iVar1) {
      local_8 = (LPCWSTR)Ordinal_1124(iVar1 * 2);
      if (local_8 == (LPWSTR)0x0) {
        return 0x80040001;
      }
      memset(local_8,0,iVar1 * 2);
      iVar2 = MultiByteToWideChar((uint)param_1,0,param_3,param_4,local_8,iVar1);
      if (0 < iVar2) {
        iVar2 = WideCharToMultiByte((uint)param_2,0,local_8,iVar1,(LPSTR)0x0,0,param_7,(LPBOOL)0x0);
        if (0 < iVar2) {
          if (param_5 == (LPSTR)0x0) {
            *param_6 = iVar2;
            goto LAB_68169612;
          }
          iVar1 = WideCharToMultiByte((uint)param_2,0,local_8,iVar1,param_5,*param_6,param_7,
                                      (LPBOOL)0x0);
          if (0 < iVar1) goto LAB_68169612;
        }
      }
    }
  }
  local_c = 0x80040001;
LAB_68169612:
  if (local_8 != (LPCWSTR)0x0) {
    Ordinal_1125(&local_8);
  }
  return local_c;
}



// ============================================================
// Function: strings_multiToWide (FUN_68169640)
// Address: 68169640
// Size: 98 bytes
// Params: ushort param_1, LPCSTR param_2, int param_3, LPWSTR param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_multiToWide(ushort param_1,LPCSTR param_2,int param_3,LPWSTR param_4,int *param_5)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = MultiByteToWideChar((uint)param_1,0,param_2,param_3,(LPWSTR)0x0,0);
    if (0 < iVar1) {
      if (param_4 == (LPWSTR)0x0) {
        *param_5 = iVar1;
      }
      else {
        iVar1 = MultiByteToWideChar((uint)param_1,0,param_2,param_3,param_4,*param_5);
        if (iVar1 < 1) {
          return 0x80040001;
        }
      }
      return 0;
    }
  }
  return 0x80040001;
}



// ============================================================
// Function: strings_wideToMulti (FUN_681696b0)
// Address: 681696b0
// Size: 110 bytes
// Params: ushort param_1, LPCWSTR param_2, int param_3, LPSTR param_4, int * param_5, LPCSTR param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
strings_wideToMulti(ushort param_1,LPCWSTR param_2,int param_3,LPSTR param_4,int *param_5,LPCSTR param_6)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = WideCharToMultiByte((uint)param_1,0,param_2,param_3,(LPSTR)0x0,0,param_6,(LPBOOL)0x0);
    if (0 < iVar1) {
      if (param_4 == (LPSTR)0x0) {
        *param_5 = iVar1;
      }
      else {
        iVar1 = WideCharToMultiByte((uint)param_1,0,param_2,param_3,param_4,*param_5,param_6,
                                    (LPBOOL)0x0);
        if (iVar1 < 1) {
          return 0x80040001;
        }
      }
      return 0;
    }
  }
  return 0x80040001;
}



// ============================================================
// Function: strings_validateCodePage (FUN_68169720)
// Address: 68169720
// Size: 18 bytes
// Params: ushort param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_validateCodePage(ushort param_1)
{
  IsValidCodePage((uint)param_1);
  return 0;
}



// ============================================================
// Function: strings_loadCastContext (FUN_68169740)
// Address: 68169740
// Size: 670 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_loadCastContext(int *param_1,int param_2)
{
  char cVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int unaff_EBX;
  int iVar9;
  byte *pbVar10;
  uint local_81c;
  int local_818;
  int local_814;
  int local_810;
  int *local_80c;
  byte local_808;
  char local_807 [1023];
  byte local_408 [1024];
  uint local_8;
  
  local_810 = 0;
  local_80c = (int *)0x0;
  iVar4 = events_getScoreProperty(unaff_EBX);
  if (param_2 != -1) {
    local_80c = (int *)Ordinal_16(param_1,param_2);
    local_810 = Ordinal_15((int)param_1);
    if (local_810 == 0) {
      bVar3 = globals_readBytecodeBlock(local_80c,&local_80c);
      local_810 = CONCAT31(extraout_var,bVar3);
      if ((local_810 == 0) && (uVar5 = Ordinal_1116(local_80c), 0x23 < uVar5)) {
        piVar2 = *(int **)(unaff_EBX + 0x28);
        iVar9 = *(int *)(*local_80c + 0x1c);
        local_814 = iVar9;
        uVar5 = cast_resizeHandle((uint)piVar2,
                             *(short *)(*piVar2 + 0x1e) * iVar9 + (int)*(short *)(*piVar2 + 0x18),1)
        ;
        if (uVar5 != 0) {
          *(int *)(*piVar2 + 0x14) = iVar9;
        }
        iVar9 = 0;
        local_818 = 0;
        if (0 < local_814) {
          do {
            local_808 = 0;
            memset(local_807,0,0x3ff);
            Ordinal_1230(local_408,*local_80c + 0x20 + iVar9);
            if (iVar4 < 0x1100) {
              if (local_408[0] == 0xff) {
                uVar5 = Ordinal_1201(local_408 + 1);
              }
              else {
                uVar5 = (uint)local_408[0];
              }
              events_writeChannelProperty(unaff_EBX,local_408 + 1,uVar5,1);
            }
            if (local_408[0] == 0xff) {
              uVar5 = Ordinal_1201(local_408 + 1);
            }
            else {
              uVar5 = (uint)local_408[0];
            }
            iVar9 = iVar9 + 1 + uVar5;
            if (iVar4 < 0x1100) {
              iVar6 = Ordinal_1274(local_408 + 1,local_408[0] + 1,local_807,0x3fe);
              if (0 < iVar6) {
                pcVar8 = local_807;
                do {
                  pcVar7 = pcVar8;
                  pcVar8 = pcVar7 + 1;
                } while (*pcVar7 != '\0');
                *pcVar7 = '\0';
                pcVar8 = local_807;
                do {
                  cVar1 = *pcVar8;
                  pcVar8 = pcVar8 + 1;
                } while (cVar1 != '\0');
                local_808 = (byte)((int)pcVar8 - (int)(local_807 + 1));
                if (0xfe < (uint)((int)pcVar8 - (int)(local_807 + 1))) {
                  local_808 = 0xff;
                }
              }
              pbVar10 = &local_808;
              iVar6 = **(int **)(unaff_EBX + 8);
            }
            else {
              pbVar10 = local_408;
              iVar6 = **(int **)(unaff_EBX + 8);
            }
            uVar5 = score_resolveSymbolName(iVar6,DAT_68196304,pbVar10,&local_81c,0);
            iVar6 = props_resolveSymbol(unaff_EBX,uVar5);
            if (iVar6 != local_818) {
              local_408[local_408[0]] = 0;
              stage_logScriptError("lcontext_FileRead: symRef=%d index=%d nameStr=%s sym=%d");
              break;
            }
            local_818 = local_818 + 1;
          } while (local_818 < local_814);
        }
      }
    }
  }
  if (local_80c != (int *)0x0) {
    cast_freeHandle(local_80c);
  }
  return 0;
}



// ============================================================
// Function: strings_openCastMembers (FUN_681699f0)
// Address: 681699f0
// Size: 517 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 * param_4, void * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint strings_openCastMembers(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4,void *param_5)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  piVar3 = (int *)events_setEditProperty(param_1,in_EAX);
  globals_initPropertyData();
  local_8 = (int *)Ordinal_16(piVar3,param_2);
  param_2 = Ordinal_15((int)piVar3);
  if ((param_2 == 0) && (param_2 = globals_readCastDispatch(local_8,&local_8,(int)param_5), param_2 == 0)) {
    uVar4 = 0;
    if (local_8 == (int *)0x0) {
LAB_68169be8:
      param_2 = uVar4;
      *param_4 = local_8;
      return param_2;
    }
    iVar6 = *(int *)(*local_8 + 0x10);
    puVar5 = (undefined4 *)(*local_8 + 0xa8);
    if (0 < iVar6) {
      do {
        *puVar5 = 0;
        puVar5 = puVar5 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    *(int *)(*local_8 + 0x24) = in_EAX;
    *(undefined4 *)(*local_8 + 0x38) = 0xffffffff;
    iVar6 = *(int *)(*local_8 + 0x10);
    local_14 = 0;
    local_10 = 0;
    if (0 < iVar6) {
      iVar7 = 0;
      do {
        iVar1 = *(int *)(iVar7 + 0xac + *local_8);
        uVar4 = param_2;
        if (iVar1 < -1) goto LAB_68169be8;
        if (iVar1 == -1) {
LAB_68169b73:
          *(undefined4 *)(iVar7 + 0xb4 + *local_8) = *(undefined4 *)(*local_8 + 0x38);
          *(int *)(*local_8 + 0x38) = local_10;
        }
        else {
          local_c = (int *)Ordinal_16(piVar3,iVar1);
          param_2 = Ordinal_15((int)piVar3);
          if (((param_2 != 0) ||
              (param_2 = globals_readCastMember(param_1,local_c,&local_c,param_5), param_2 != 0)) ||
             (local_c == (int *)0x0)) goto LAB_68169bd5;
          uVar4 = Ordinal_1116(local_c);
          if ((uVar4 < 0x9a) || (iVar2 = *local_c, (*(byte *)(iVar2 + 0x54) & 1) != 0)) {
            *(undefined4 *)(iVar7 + 0xac + *local_8) = 0xffffffff;
            crt_mergeChunks((int)piVar3,iVar1);
            cast_freeHandle(local_c);
            goto LAB_68169b73;
          }
          *(undefined4 *)(iVar2 + 0x20) = param_3;
          *(undefined4 *)(iVar2 + 0x30) = 0;
          *(undefined4 *)(iVar2 + 0x34) = 0;
          *(undefined4 *)(iVar2 + 0x2c) = 0;
          local_14 = local_14 + 1;
          *(undefined4 *)(iVar2 + 4) = 1;
          *(int **)(iVar7 + 0xa8 + *local_8) = local_c;
          stage_registerContextNode(param_1,local_c);
        }
        local_10 = local_10 + 1;
        iVar7 = iVar7 + 0x10;
      } while (local_10 < iVar6);
    }
    *(int *)(*local_8 + 0x30) = local_14;
    *(undefined4 *)(*local_8 + 0x40) = 0xffffffff;
    *(undefined4 *)(*local_8 + 0x3c) = 0xffffffff;
    iVar6 = 0x44;
    do {
      *(undefined4 *)(iVar6 + *local_8) = 0xffffffff;
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0xa8);
  }
LAB_68169bd5:
  *param_4 = local_8;
  return param_2;
}




/* Restored functions that were incorrectly removed during thunk cleanup */

// ============================================================

undefined4 strings_getDefaultCastType(void)

{
  return 0xffffff9a;
}

// ============================================================
// Function: strings_installCastHandlers (FUN_68169c00)
// Address: 68169c00
// Size: 63 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_installCastHandlers(int param_1)

{
  int *piVar1;
  int *unaff_EBX;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*unaff_EBX + 0x10);
  if (0 < iVar3) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + 0xa8 + *unaff_EBX);
      if ((piVar1 != (int *)0x0) && ((*(byte *)(*piVar1 + 0x54) & 2) != 0)) {
        props_installHandlers(param_1,piVar1);
      }
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}



// ============================================================
// Function: strings_saveScriptContext (FUN_68169c40)
// Address: 68169c40
// Size: 30 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall strings_saveScriptContext(void *this,undefined4 *param_1)
{
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)this = *(undefined4 *)(unaff_ESI + 0x3c);
  props_selectScript(unaff_ESI,unaff_EDI);
  *param_1 = *(undefined4 *)(unaff_ESI + 0x58);
  *(int *)(unaff_ESI + 0x58) = unaff_EDI;
  return 0;
}



// ============================================================
// Function: strings_restoreScriptContext (FUN_68169c60)
// Address: 68169c60
// Size: 20 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_restoreScriptContext(undefined4 param_1)
{
  int in_EAX;
  int unaff_ESI;
  
  props_selectScript(unaff_ESI,in_EAX);
  *(undefined4 *)(unaff_ESI + 0x58) = param_1;
  return 0;
}



// ============================================================
// Function: strings_openCastContext (FUN_68169c80)
// Address: 68169c80
// Size: 220 bytes
// Params: int * param_1, uint param_2, uint param_3, int * param_4, void * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint strings_openCastContext(int *param_1,uint param_2,uint param_3,int *param_4,void *param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  piVar1 = param_1;
  local_c = (int *)events_setEditProperty((int)param_1,param_2);
  local_8 = piVar1[0xf];
  param_2 = 0;
  iVar3 = props_allocScriptEntry((int)piVar1,*(int **)(*(int *)piVar1[2] + 0x4f4));
  if (-1 < iVar3) {
    strings_saveScriptContext(&local_8,&local_10);
    param_2 = strings_openCastMembers((int)piVar1,param_3,iVar3,&param_1,param_5);
    piVar2 = param_1;
    if ((param_2 == 0) && (param_1 != (int *)0x0)) {
      iVar4 = Ordinal_1116(param_1);
      if (0 < iVar4) {
        param_2 = strings_loadCastContext(local_c,*(int *)(*piVar2 + 0x2c));
        if (param_2 == 0) {
          cast_freeHandle(piVar1[0xb]);
          *(int **)(**(int **)(*(int *)piVar1[2] + 0x4f4) + 0x2c + iVar3 * 0x18) = param_1;
          piVar1[0xb] = (int)param_1;
          strings_installCastHandlers((int)piVar1);
        }
      }
    }
  }
  *param_4 = iVar3;
  props_selectScript((int)piVar1,local_8);
  strings_restoreScriptContext(local_10);
  return param_2;
}



// ============================================================
// Function: strings_serializeSymbols (FUN_68169d60)
// Address: 68169d60
// Size: 276 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_serializeSymbols(int param_1,int *param_2,int param_3)
{
  short sVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *local_40c;
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar5 = *(int *)(*param_2 + 0x10);
  local_40c = param_2;
  piVar2 = (int *)stage_createBytecodeBlock(0x24,0x20,iVar5 << 4);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *(int *)(*piVar2 + 0x1c) = iVar5;
  if (0 < iVar5) {
    iVar4 = 0;
    do {
      score_lookupSymbol(DAT_68196304,*(int *)(*local_40c + 0x24 + iVar4),(int)&local_408);
      uVar3 = (uint)local_408;
      if (uVar3 == 0xff) {
        sVar1 = Ordinal_1201(local_407);
        uVar3 = (int)sVar1 + 1;
      }
      stage_emitBytecode(piVar2,&local_408,uVar3 + 1);
      iVar4 = iVar4 + 0x18;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  stage_getBytecodeSize(piVar2);
  uVar3 = globals_writeBytecodeBlock(piVar2,(int *)&local_40c);
  if (uVar3 == 0) {
    cast_freeHandle(piVar2);
    piVar2 = local_40c;
    Ordinal_20(param_1,param_3,local_40c);
  }
  if (piVar2 != (int *)0x0) {
    cast_freeHandle(piVar2);
  }
  return 0;
}



// ============================================================
// Function: strings_resetMemberBreakpoints (FUN_68169e80)
// Address: 68169e80
// Size: 77 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_resetMemberBreakpoints(undefined4 param_1,int param_2)
{
  int *in_EAX;
  uint *puVar1;
  int iVar2;
  int unaff_ESI;
  
  if ((param_2 != 0) || ((*(byte *)(*in_EAX + 0x34) & 4) != 0)) {
    if (unaff_ESI != 0) {
      *(undefined4 *)(*in_EAX + 0x2c) = 0xffffffff;
      *(undefined4 *)(*in_EAX + 0x28) = 0xffffffff;
    }
    *(uint *)(*in_EAX + 0x34) = *(uint *)(*in_EAX + 0x34) & 0xfffffffb;
  }
  iVar2 = *(int *)(*in_EAX + 0x10);
  if (0 < iVar2) {
    puVar1 = (uint *)(*in_EAX + 0xb0);
    do {
      if ((param_2 != 0) || ((*puVar1 & 4) != 0)) {
        if (unaff_ESI != 0) {
          puVar1[-1] = 0xffffffff;
        }
        *puVar1 = *puVar1 & 0xfffffffb;
      }
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}



// ============================================================
// Function: strings_saveCastMembers (FUN_68169ed0)
// Address: 68169ed0
// Size: 225 bytes
// Params: int param_1, int param_2, int * param_3, int param_4, int param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint strings_saveCastMembers(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_8;
  
  stage_emitPopVar(param_3);
  uVar5 = globals_writeCastDispatch(param_3,&local_8);
  iVar6 = 0;
  if (uVar5 == 0) {
    uVar5 = Ordinal_20(param_2,param_4,local_8);
  }
  cast_freeHandle(local_8);
  if (uVar5 == 0) {
    iVar1 = *(int *)(*param_3 + 0x10);
    local_8 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = *param_3;
        piVar3 = *(int **)(iVar2 + 0xa8 + iVar6);
        iVar4 = *(int *)(iVar2 + 0xac + iVar6);
        if ((((piVar3 != (int *)0x0) && ((*(byte *)(*piVar3 + 0x54) & 0x80) == 0)) &&
            ((param_5 != 0 || ((*(byte *)(iVar2 + iVar6 + 0xb0) & 4) != 0)))) && (iVar4 != -1)) {
          uVar5 = globals_writeCastMember(param_1,piVar3,&param_4);
          if (uVar5 == 0) {
            uVar5 = Ordinal_20(param_2,iVar4,param_4);
          }
          cast_freeHandle(param_4);
          if (uVar5 != 0) {
            return uVar5;
          }
        }
        local_8 = local_8 + 1;
        iVar6 = iVar6 + 0x10;
      } while (local_8 < iVar1);
    }
  }
  return uVar5;
}



// ============================================================
// Function: strings_saveCastContext (FUN_68169fc0)
// Address: 68169fc0
// Size: 119 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint strings_saveCastContext(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  uVar3 = 0;
  props_selectScript(param_1,param_2);
  piVar2 = *(int **)(param_1 + 0x2c);
  if (((param_5 != 1) != 0) || ((*(byte *)(*piVar2 + 0x34) & 0x41) != 0)) {
    uVar3 = strings_saveCastMembers(param_1,param_3,piVar2,param_4,(uint)(param_5 != 1));
    if (uVar3 == 0) {
      uVar3 = strings_serializeSymbols(param_3,*(int **)(param_1 + 0x28),*(int *)(*piVar2 + 0x2c));
    }
  }
  props_selectScript(param_1,iVar1);
  return uVar3;
}



// ============================================================
// Function: strings_clearCastBreakpoints (FUN_6816a040)
// Address: 6816a040
// Size: 71 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_clearCastBreakpoints(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  uint *puVar1;
  
  if (param_5 == 0) {
    puVar1 = (uint *)(**(int **)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x2c + param_2 * 0x18
                                ) + 0x34);
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  strings_resetMemberBreakpoints((uint)(param_5 != 0),(uint)(param_4 != 1));
  return 0;
}



// ============================================================
// Function: strings_assignCastResources (FUN_6816a090)
// Address: 6816a090
// Size: 293 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_assignCastResources(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  bVar8 = param_4 != 1;
  piVar2 = *(int **)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x2c + param_2 * 0x18);
  if ((bVar8) || (*(int *)(*piVar2 + 0x2c) == -1)) {
    iVar4 = Ordinal_19(param_3,FOURCC_Lnam);
    iVar5 = Ordinal_15(param_3);
    if (iVar5 != 0) {
      return iVar5;
    }
    *(int *)(*piVar2 + 0x2c) = iVar4;
    *(uint *)(*piVar2 + 0x34) = *(uint *)(*piVar2 + 0x34) | 4;
  }
  iVar4 = *(int *)(*piVar2 + 0x10);
  iVar5 = 0;
  param_1 = 0;
  if (0 < iVar4) {
    do {
      iVar6 = *(int *)(iVar5 + 0xac + *piVar2);
      piVar3 = *(int **)(iVar5 + 0xa8 + *piVar2);
      if (piVar3 != (int *)0x0) {
        if ((*(byte *)(*piVar3 + 0x54) & 0x81) == 0) {
          if ((bVar8) || (iVar6 == -1)) {
            iVar6 = Ordinal_19(param_3,FOURCC_Lscr);
            iVar7 = Ordinal_15(param_3);
            if (iVar7 != 0) {
              return iVar7;
            }
            iVar7 = *piVar2;
            puVar1 = (uint *)(iVar5 + 0xb0 + iVar7);
            *puVar1 = *puVar1 | 4;
            *(int *)(iVar5 + iVar7 + 0xac) = iVar6;
          }
        }
        else if ((bVar8) || (iVar6 != -1)) {
          crt_mergeChunks(param_3,iVar6);
          *(undefined4 *)(iVar5 + 0xac + *piVar2) = 0xffffffff;
        }
      }
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 0x10;
    } while (param_1 < iVar4);
  }
  return 0;
}



// ============================================================
// Function: strings_debugLineCallback (FUN_6816a1c0)
// Address: 6816a1c0
// Size: 113 bytes
// Params: int param_1, uint param_2, int param_3, undefined4 param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_debugLineCallback(int param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = xtra_getPlatformData(param_1);
  if ((iVar2 == param_5) && (*(int *)(iVar2 + 0x90) != 0)) {
    iVar3 = runtime_setBreakpoint(param_1,param_2,param_3);
    iVar1 = *(int *)(param_2 + 0x34);
    uVar4 = *(undefined4 *)(param_2 + 0x38);
    iVar3 = iVar3 + -1;
    if ((iVar1 != 0) && (iVar3 != *(int *)(iVar2 + 0x134))) {
      *(int *)(iVar2 + 0x134) = iVar3;
      uVar4 = (**(code **)(iVar2 + 0x90))(iVar2,0,iVar1,uVar4,iVar3);
      *(undefined4 *)(iVar2 + 0x130) = uVar4;
    }
    return 1;
  }
  return 1;
}



// ============================================================
// Function: strings_debugErrorCallback (FUN_6816a240)
// Address: 6816a240
// Size: 105 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_debugErrorCallback(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  iVar1 = xtra_getPlatformData(param_1);
  if (param_3 == 0) {
    if (param_5 == 1) {
      runtime_checkBreakpoint(*(int *)(param_1 + 0x14),strings_debugLineCallback,iVar1);
      *(undefined4 *)(iVar1 + 0x130) = 5;
    }
  }
  else if ((iVar1 == param_5) && (*(int *)(iVar1 + 0x130) == 5)) {
    runtime_checkBreakpoint(*(int *)(param_1 + 0x14),0,0);
    *(undefined4 *)(iVar1 + 0x130) = 0;
    return 1;
  }
  return 0;
}



