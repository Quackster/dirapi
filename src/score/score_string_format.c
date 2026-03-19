// Module: score
// Topic: String formatting and regex-like operations
// Address range: 0x68042150 - 0x68042700
// Functions (7):
//   score_extractSubstring (FUN_68042150)
//   score_formatStringEx
//   score_deleteMatchedRange (FUN_680423f0)
//   score_formatString
//   score_formatValue
//   score_findMatchIndex (FUN_68042680)
//   score_dispatchFormatLookup (FUN_68042700)

// ============================================================
// Function: score_extractSubstring (FUN_68042150)
// Address: 68042150
// Size: 142 bytes
// Params: int param_1, int * param_2, int * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_extractSubstring(int param_1,int *param_2,int *param_3,int *param_4)

{
  byte *pbVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  pbVar1 = (byte *)props_getStringData(param_3,&local_8);
  local_c = local_8;
  local_10 = 0;
  score_registerAllHandlers(param_1,param_2,&local_10,&local_c,pbVar1,&local_8);
  iVar2 = local_c - local_10;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  props_createStringFromData(param_1,pbVar1 + local_10,iVar2,param_4);
  props_unlockString(param_3);
  if ((*param_4 != 0x40) && (*param_4 != 0x43)) {
    props_setError(param_1,3);
    return 0;
  }
  return 1;
}


// ============================================================
// Function: score_formatStringEx (FUN_680421e0)
// Address: 680421e0
// Size: 519 bytes
// Params: int param_1, uint param_2, int * param_3, undefined4 * param_4, uint param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatStringEx(int param_1,uint param_2,int *param_3,undefined4 *param_4,uint param_5,
                 int *param_6)
{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int **ppiVar6;
  void *this;
  byte *pbVar7;
  uint uVar8;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar1 = param_4;
  this = (void *)(param_2 & 0xfffffff0);
  piVar3 = props_accessStringVar(this,param_2 & 0xf,(int)param_3,&param_5,&local_c);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  props_getStringLength(param_1,(int *)&param_5);
  param_2 = 0;
  local_8 = Ordinal_1116(piVar3);
  uVar2 = local_c;
  local_10 = (local_8 - (uint)(*(short *)((int)puVar1 + 2) < 0)) - local_c;
  uVar8 = local_10;
  if (param_3 != (int *)0x0) {
    pbVar7 = (byte *)(*piVar3 + local_c);
    local_c = local_10;
    score_registerAllHandlers(param_1,param_3,(int *)&param_2,(int *)&local_c,pbVar7,(int *)&local_10);
    props_padString(&param_5,param_1,0xd);
    props_padString(&param_5,param_1,*(undefined4 *)(**(int **)(param_1 + 8) + 0x500));
    props_padString(&param_5,param_1,0x20);
    uVar8 = local_c;
  }
  local_c = uVar8;
  uVar8 = local_c;
  uVar5 = local_c;
  if ((this != (void *)0x20) && (uVar5 = param_2, this == (void *)0x30)) {
    uVar8 = param_2;
  }
  param_2 = uVar5;
  if (*(short *)((int)param_4 + 2) < 1) {
    param_4 = (undefined4 *)(uVar8 - param_2);
    if (param_5 == 0x40) {
      param_3 = (int *)((uint)((*(unsigned char *)((char *)&param_6 + 2)) != '\0') + (uint)((char)((uint)param_6 >> 8) != '\0') +
                       (uint)((char)param_6 != '\0'));
    }
    else {
      iVar4 = Ordinal_1116(param_6);
      param_3 = (int *)(iVar4 + -9);
    }
    param_4 = (undefined4 *)((int)param_3 - (int)param_4);
    if (0 < (int)param_4) {
      uVar5 = cast_resizeHandle((uint)piVar3,(int)param_4 + local_8,0);
      if (uVar5 == 0) goto LAB_680423cd;
      Ordinal_1129((int)param_4 + uVar2 + uVar8 + *piVar3,*piVar3 + uVar8 + uVar2,
                   (local_8 - uVar8) - uVar2);
    }
    if (param_5 == 0x40) {
      ppiVar6 = &param_6;
    }
    else {
      ppiVar6 = (int **)(*param_6 + 8);
    }
    Ordinal_1129(*piVar3 + param_2 + uVar2,ppiVar6,param_3);
    if ((int)param_4 < 0) {
      Ordinal_1129((int)param_3 + uVar2 + param_2 + *piVar3,*piVar3 + uVar8 + uVar2,
                   (local_8 - uVar8) - uVar2);
      cast_resizeHandle((uint)piVar3,(int)param_4 + local_8,0);
    }
  }
  else {
    piVar3 = props_getStringData((int *)&param_5,(int *)&param_3);
    sprites_registerMemberAsset(param_1,param_4,param_2,uVar8,(int)piVar3);
    props_unlockString((int *)&param_5);
  }
LAB_680423cd:
  props_releaseValue(param_1,(byte)param_5,param_6);
  return 0;
}


// ============================================================
// Function: score_deleteMatchedRange (FUN_680423f0)
// Address: 680423f0
// Size: 281 bytes
// Params: int param_1, uint param_2, int * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_deleteMatchedRange(int param_1,uint param_2,int *param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  piVar1 = param_3;
  piVar3 = props_accessStringVar((void *)0xffffffff,param_2,(int)param_3,(uint *)0x0,&local_c);
  if (piVar3 != (int *)0x0) {
    param_2 = 0;
    iVar4 = Ordinal_1116(piVar3);
    iVar2 = local_c;
    local_8 = (iVar4 - (uint)(*(short *)((int)param_4 + 2) < 0)) - local_c;
    iVar7 = local_8;
    if (piVar1 != (int *)0x0) {
      pbVar6 = (byte *)(*piVar3 + local_c);
      local_c = local_8;
      score_registerAllHandlers(param_1,piVar1,(int *)&param_2,&local_8,pbVar6,&local_c);
      iVar7 = local_c;
    }
    local_c = iVar7;
    if ((int)param_2 <= local_8) {
      iVar7 = 0;
      do {
        iVar5 = props_skipDelimiter(local_c,param_3,param_1,(int *)&param_2,&local_8,*piVar3 + iVar2);
        if (iVar5 != 0) break;
        param_3 = param_3 + 3;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 4);
      if (0 < *(short *)((int)param_4 + 2)) {
        sprites_registerMemberAsset(param_1,param_4,param_2,local_8,0);
        return 0;
      }
      iVar4 = iVar4 - local_8;
      Ordinal_1129(*piVar3 + param_2 + iVar2,local_8 + *piVar3 + iVar2,iVar4 - iVar2);
      cast_resizeHandle((uint)piVar3,iVar4 + param_2,0);
    }
  }
  return 0;
}


// ============================================================
// Function: score_formatString (FUN_68042510)
// Address: 68042510
// Size: 190 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_formatString(undefined4 param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  pcVar1 = *(code **)(*param_2 + 0x24);
  iVar3 = 0;
  iVar5 = *(int *)(*param_2 + 0x10) + -1;
  local_8 = 0;
  iVar4 = -1;
  if (-1 < iVar5) {
    do {
      iVar4 = (iVar5 - iVar3 >> 1) + iVar3;
      iVar2 = (*pcVar1)(param_1,*param_3,param_3[1],*(undefined4 *)(*param_2 + 0x28 + iVar4 * 0x10),
                        *(undefined4 *)(*param_2 + 0x2c + iVar4 * 0x10));
      if (iVar2 == 0) {
        local_8 = 1;
        if (iVar4 < 1) goto LAB_68042575;
        iVar3 = iVar4 * 0x10;
        goto LAB_680425a0;
      }
      if (iVar2 < 1) {
        iVar5 = iVar4 + -1;
      }
      else {
        iVar3 = iVar4 + 1;
      }
    } while (iVar3 <= iVar5);
    if (iVar2 < 1) goto LAB_68042575;
  }
  iVar4 = iVar4 + 1;
  goto LAB_68042575;
  while( true ) {
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + -0x10;
    if (iVar4 < 1) break;
LAB_680425a0:
    iVar5 = (*pcVar1)(param_1,*param_3,param_3[1],*(undefined4 *)(*param_2 + 0x18 + iVar3),
                      *(undefined4 *)(*param_2 + 0x1c + iVar3));
    if (iVar5 != 0) break;
  }
LAB_68042575:
  if (param_4 != (int *)0x0) {
    *param_4 = iVar4;
  }
  return local_8;
}


// ============================================================
// Function: score_formatValue (FUN_680425d0)
// Address: 680425d0
// Size: 167 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_formatValue(undefined4 param_1,int *param_2,int *param_3)

{
  uint *puVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *unaff_EDI;
  int local_8;
  
  pcVar2 = *(code **)(*param_2 + 0x24);
  iVar3 = *(int *)(*param_2 + 0x10);
  uVar4 = *unaff_EDI;
  iVar6 = 0;
  if (0 < iVar3) {
    local_8 = 0;
    do {
      puVar1 = (uint *)(*param_2 + 0x28 + local_8);
      if (((~uVar4 & 1) == 0) || (*unaff_EDI != *puVar1)) {
        iVar5 = (*pcVar2)(param_1,*puVar1,puVar1[1],*unaff_EDI,unaff_EDI[1]);
        if (iVar5 == 0) {
          *param_3 = iVar6;
          return 1;
        }
      }
      else if (unaff_EDI[1] == *(uint *)(*param_2 + 0x2c + local_8)) {
        *param_3 = iVar6;
        return 1;
      }
      local_8 = local_8 + 0x10;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
  }
  *param_3 = iVar3;
  return 0;
}


// ============================================================
// Function: score_findMatchIndex (FUN_68042680)
// Address: 68042680
// Size: 114 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_findMatchIndex(undefined4 param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  pcVar1 = *(code **)(*param_2 + 0x24);
  iVar2 = *(int *)(*param_2 + 0x10);
  if (0 < iVar2) {
    iVar4 = 0x30;
    iVar5 = 0;
    do {
      iVar3 = (*pcVar1)(param_1,*(undefined4 *)(*param_2 + iVar4),
                        *(undefined4 *)(*param_2 + 4 + iVar4),*param_3,param_3[1]);
      if (iVar3 == 0) {
        *param_4 = iVar5;
        return 1;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar5 < iVar2);
  }
  *param_4 = -1;
  return 0;
}


// ============================================================
// Function: score_dispatchFormatLookup (FUN_68042700)
// Address: 68042700
// Size: 303 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_dispatchFormatLookup(int param_1,int *param_2)
{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_1c = param_2;
  iVar3 = props_getInt(param_1);
  if (iVar3 == 3) {
    puVar1 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                     *(int *)(param_1 + 0x18));
    local_14 = DAT_6819776c;
    local_18 = DAT_68197768;
    if (puVar1 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_14 = puVar1[1];
      local_18 = *puVar1;
    }
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                 *(int *)(param_1 + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_18 & 1) != 0) {
      props_retainValue(param_1,&local_18);
    }
    if ((local_10 & 1) != 0) {
      props_retainValue(param_1,&local_10);
    }
    piVar2 = local_1c;
    if (*(int *)(*local_1c + 0x20) == 0) {
      stage_lookupSymbolId(local_1c,&local_18);
    }
    else {
      score_formatString(param_1,local_1c,&local_18,(int *)&local_1c);
      stage_emitStoreProperty(piVar2,(int)local_1c,&local_18);
    }
    props_checkReentrant(param_1);
    return 0;
  }
  props_setError(param_1,0x17);
  return 0;
}


