// Module: media_playback
// Topic: Asset registration, actor lookup, and cast member loading
// Address range: 0x680B4A50 - 0x680B6460
// Functions (34):
//   media_checkActorType
//   media_getDisplayName
//   media_getAssetGuid
//   media_loadCastWithContext
//   media_getAssetCaps
//   media_getModifiedTime
//   media_createAssetContainer
//   media_addCastEntry
//   media_compareScoreEntries
//   media_registerCastAsset
//   media_registerCastAssetSimple
//   media_initCastRegistry
//   media_getAssetRef
//   media_getAssetInfo
//   media_saveRestoreAssetRef
//   media_acquireLock
//   media_dispatchScoredEvent
//   media_dispatchChannelRender
//   media_dispatchAssetEvent
//   media_handleTextHitTest
//   media_registerAssetWithData
//   media_getAssetData
//   media_registerAsset
//   media_lookupAsset
//   media_resolveAsset
//   media_getAssetState
//   media_resolveAssetEx
//   media_notifyTextChange
//   media_allocAssetContainer
//   media_initAssetLoader
//   media_cloneAssetContainer
//   media_findAssetRef
//   media_findAssetEntry
//   media_loadAssetBlock

// ============================================================
// Function: media_checkActorType (FUN_680b4a50)
// Address: 680b4a50
// Size: 79 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_checkActorType(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = media_setVtableEntry(param_1,param_2);
  if ((((iVar2 != 0) && (piVar1 = *(int **)(iVar2 * 0x20 + 0x18 + *param_1), piVar1 != (int *)0x0))
      && (iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,3,&param_2,4,"actorType"), iVar2 == 0)) &&
     (param_2 == 2)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_getDisplayName (FUN_680b4aa0)
// Address: 680b4aa0
// Size: 117 bytes
// Params: int * param_1, int param_2, undefined1 * param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getDisplayName(int *param_1,int param_2,undefined1 *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = media_setVtableEntry(param_1,param_2);
  if (iVar2 == 0) {
    return -0x7ffbf82d;
  }
  piVar3 = (int *)(iVar2 * 0x20 + *param_1);
  piVar1 = (int *)piVar3[6];
  if (piVar1 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1,9,param_3,param_4,"displayNameString");
    iVar2 = 0;
    if (iVar4 != 0) {
      iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,9,param_3,param_4,"symbolString");
    }
    return iVar2;
  }
  iVar2 = media_getCastTypeName(*piVar3,param_3,param_4);
  return iVar2;
}



// ============================================================
// Function: media_getAssetGuid (FUN_680b4b20)
// Address: 680b4b20
// Size: 96 bytes
// Params: int * param_1, int param_2, undefined4 * param_3, uint param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getAssetGuid(int *param_1,int param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = media_setVtableEntry(param_1,param_2);
  if (iVar2 == 0) {
    return 0x800407d3;
  }
  if (0xf < param_4) {
    iVar1 = iVar2 * 0x20 + 4 + *param_1;
    *param_3 = *(undefined4 *)(iVar2 * 0x20 + 4 + *param_1);
    param_3[1] = *(undefined4 *)(iVar1 + 4);
    param_3[2] = *(undefined4 *)(iVar1 + 8);
    param_3[3] = *(undefined4 *)(iVar1 + 0xc);
    return 0;
  }
  return 0x80040001;
}



// ============================================================
// Function: media_loadCastWithContext (FUN_680b4b80)
// Address: 680b4b80
// Size: 342 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_loadCastWithContext(int param_1,int *param_2,int param_3,undefined4 *param_4,undefined4 *param_5)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_28;
  undefined4 *local_24;
  int local_20;
  int *local_1c;
  char local_15;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_5;
  local_28 = 0;
  if (param_1 == 0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = *(int **)(param_1 + 0x20);
  }
  piVar5 = local_1c;
  local_20 = 0;
  if ((local_1c != (int *)0x0) && (local_1c[1] != 0)) {
    if (param_1 == 0) {
      param_1 = *local_1c;
    }
    if (local_1c[2] == 0) {
      local_20 = 0;
    }
    else {
      local_20 = *(int *)(local_1c[2] + 0xc);
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_1;
  }
  iVar2 = media_setVtableEntry(param_2,param_3);
  if (((0 < iVar2) && (piVar1 = *(int **)(iVar2 * 0x20 + 0x18 + *param_2), piVar1 != (int *)0x0)) &&
     ((iVar2 = sprites_getStageRef(local_20), iVar2 == 0 ||
      ((iVar2 = media_applyPixelFilterEx(piVar1,&local_15), iVar2 == 0 && (local_15 != '\0')))))) {
    uVar3 = Ordinal_1038();
    piVar4 = (int *)Ordinal_2068(uVar3);
    piVar5 = local_1c;
    if (piVar4 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar4 + 0x24))(piVar4,piVar1,0,&local_28);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,8,local_24,4,"assetCaps");
        if (iVar2 != 0) {
          *local_24 = 0;
        }
        *param_4 = local_28;
      }
      (**(code **)(*piVar4 + 8))(piVar4);
      piVar5 = local_1c;
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getAssetCaps (FUN_680b4ce0)
// Address: 680b4ce0
// Size: 189 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getAssetCaps(int param_1,int *param_2,int param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_14 = param_1;
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
    }
  }
  iVar2 = media_setVtableEntry(param_2,param_3);
  if ((0 < iVar2) && (piVar1 = *(int **)(iVar2 * 0x20 + 0x18 + *param_2), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,8,param_4,4,"assetCaps");
    if (iVar2 != 0) {
      *param_4 = 0;
    }
  }
  if (iVar3 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getModifiedTime (FUN_680b4da0)
// Address: 680b4da0
// Size: 43 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getModifiedTime(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = media_setVtableEntry(param_1,param_2);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 * 0x20 + 0x1c + *param_1);
  }
  return 0xffffffff;
}



// ============================================================
// Function: media_createAssetContainer (FUN_680b4dd0)
// Address: 680b4dd0
// Size: 67 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createAssetContainer(undefined4 param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  uVar1 = Ordinal_1038(&DAT_68176498,&DAT_68175cd8,&local_8);
  iVar2 = Ordinal_2063(uVar1);
  if (iVar2 == 0) {
    mediaPlayback_setNotifyParam(local_8,param_1);
  }
  *param_2 = local_8;
  return 0;
}



// ============================================================
// Function: media_addCastEntry (FUN_680b4e20)
// Address: 680b4e20
// Size: 314 bytes
// Params: void * this, int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_addCastEntry(void *this,int param_1,int param_2,int *param_3)
{
  int iVar1;
  int *unaff_EBX;
  int *piVar2;
  int *unaff_EDI;
  undefined1 local_48 [64];
  uint local_8;
  
  iVar1 = media_setVtableEntry(unaff_EDI,param_1);
  if (iVar1 != 0) {
    if (DAT_6818e4c0 != 0) {
      iVar1 = media_applyPixelFilter((int)this);
      if (iVar1 != 0) {
        if (unaff_EBX != (int *)0x0) {
          iVar1 = (**(code **)(*unaff_EBX + 0x14))();
          if (iVar1 != 0) {
            media_getSymbolName(param_1,(int)local_48,0x40);
          }
        }
        media_readScoreEntry(2,(int)local_48,0);
      }
    }
    DAT_681963cc = 1;
    return 0;
  }
  iVar1 = *(int *)(*unaff_EDI + 0x10);
  stage_emitStoreVar(unaff_EDI,iVar1);
  if (DAT_68195a8c == 0) {
    piVar2 = (int *)((iVar1 + 1) * 0x20 + *unaff_EDI);
    piVar2[6] = (int)unaff_EBX;
    *piVar2 = param_1;
    if (param_3 != (int *)0x0) {
      piVar2[1] = *param_3;
      piVar2[2] = param_3[1];
      piVar2[3] = param_3[2];
      piVar2[4] = param_3[3];
      piVar2[5] = param_2;
      piVar2[7] = -1;
      return 0;
    }
    Ordinal_1130(piVar2 + 1,0x10);
    piVar2[5] = param_2;
    piVar2[7] = -1;
    return 0;
  }
  media_readScoreEntry(8,0,0);
  return 0;
}



// ============================================================
// Function: media_compareScoreEntries (FUN_680b4f60)
// Address: 680b4f60
// Size: 177 bytes
// Params: int param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_compareScoreEntries(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  short sVar3;
  undefined2 extraout_var;
  int iVar4;
  undefined1 local_30 [8];
  undefined4 local_28;
  uint local_24 [2];
  undefined4 local_1c;
  undefined1 *local_18;
  undefined1 local_14 [8];
  undefined4 local_c [2];
  
  iVar2 = param_2;
  iVar4 = param_1;
  if (*(int *)(param_2 + 0x5c) == *(int *)(param_3 + 0x5c)) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc);
    local_28 = props_resolvePropertyId(iVar1,"Compare");
    sVar3 = scoreEngine_getChannelCount(*(int *)(iVar4 + 0x20),(short)*(undefined4 *)(iVar2 + 4));
    param_2 = CONCAT22(extraout_var,sVar3);
    cast_getScoreXtraData(iVar1,(short *)&param_2);
    props_storeIntValue(iVar1,*(undefined4 *)(param_3 + 0x54),local_c);
    local_18 = local_14;
    local_1c = 2;
    iVar4 = media_initVtable(iVar4,*(int **)(iVar2 + 0x54),(int)local_30);
    if ((iVar4 == 0) && (iVar4 = props_coerceAndReturnInt(iVar1,local_24,&param_1), iVar4 == 0)) {
      return param_1 != 0;
    }
  }
  return false;
}




// ============================================================
// Function: media_registerCastAsset (FUN_680b5020)
// Address: 680b5020
// Size: 782 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_registerCastAsset(int *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)
{
  void *this;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int local_350;
  int local_34c;
  int local_348;
  undefined4 local_344;
  int local_340;
  char local_339;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328 [64];
  undefined1 local_228 [256];
  undefined1 local_128 [256];
  undefined1 local_28 [32];
  uint local_8;
  
  local_344 = param_3;
  this = (void *)param_4[2];
  piVar1 = (int *)*param_4;
  local_350 = 0;
  local_34c = 0;
  local_340 = media_applyPixelFilter((int)this);
  iVar2 = Ordinal_2066(local_344,&DAT_68176108);
  if (((iVar2 == 0) && (iVar2 = Ordinal_2066(local_344,&DAT_68175c58), iVar2 == 0)) ||
     ((iVar2 = sprites_getStageRef((int)this), iVar2 != 0 &&
      ((iVar2 = media_applyPixelFilterEx(param_1,&local_339), iVar2 != 0 || (local_339 == '\0'))))))
  goto LAB_680b531b;
  iVar2 = (**(code **)(*param_1 + 0x28))(param_1,0,&local_34c,"symbolString");
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1,9,local_28,0x20,"symbolString");
    if (((iVar2 == 0) && (local_34c - 3U < 0x1e)) &&
       (iVar2 = media_getScoreSlotRef(this,local_28,&local_348), iVar2 == 0)) {
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1,3,&local_350,4,"actorType");
      if ((iVar2 == 0) || (iVar2 = Ordinal_2066(local_344,&DAT_68175c58), iVar2 != 0)) {
        if (((local_350 == 1) || (local_350 == 2)) ||
           (iVar2 = Ordinal_2066(local_344,&DAT_68175c58), iVar2 != 0)) {
          local_334 = 0;
          local_330 = 0;
          local_338 = 0;
          local_32c = 0;
          iVar2 = media_addCastEntry(this,local_348,0,param_2);
          iVar3 = (**(code **)(*param_1 + 0x14))(param_1,9,local_128,0x100,&DAT_6817c8e8);
          iVar4 = (**(code **)(*param_1 + 0x14))(param_1,9,local_228,0x100,"FileExts");
          iVar5 = (**(code **)(*param_1 + 0x14))(param_1,9,local_328,0x100,"FileTypes");
          iVar6 = (**(code **)(*param_1 + 0x14))(param_1,8,&local_338,0x10,"UnderstoodReceptors");
          if (iVar6 != 0) {
            local_338 = 0;
            local_334 = 0;
            local_330 = 0;
            local_32c = 0;
          }
          if (((iVar2 == 0 && iVar3 == 0) && iVar4 == 0) && iVar5 == 0) {
            iVar2 = Ordinal_1201(local_328);
            *(undefined4 *)((int)local_328 + (iVar2 + 3U & 0xfffffffc)) = 0;
            iVar2 = media_setVtableEntry(piVar1,local_348);
            uVar7 = Ordinal_1383(0,local_128,local_328,local_228,&local_338,1,local_348);
            *(undefined4 *)((iVar2 + -1) * 0x20 + 0x3c + *piVar1) = uVar7;
          }
          goto LAB_680b531b;
        }
        if (local_340 == 0) goto LAB_680b531b;
        puVar8 = local_28;
        iVar2 = 7;
      }
      else {
        if (local_340 == 0) goto LAB_680b531b;
        puVar8 = local_28;
        iVar2 = 6;
      }
    }
    else {
      if (local_340 == 0) goto LAB_680b531b;
      puVar8 = local_28;
      iVar2 = 5;
    }
  }
  else {
    if (local_340 == 0) goto LAB_680b531b;
    puVar8 = (undefined1 *)0x0;
    iVar2 = 4;
  }
  media_readScoreEntry(iVar2,(int)puVar8,0);
LAB_680b531b:
  return 0;
}



// ============================================================
// Function: media_registerCastAssetSimple (FUN_680b5330)
// Address: 680b5330
// Size: 52 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_registerCastAssetSimple(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )
{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_4;
  local_8 = param_5;
  local_c = 0;
  media_registerCastAsset(param_1,param_2,param_3,&local_10);
  return 0;
}



// ============================================================
// Function: media_initCastRegistry (FUN_680b5370)
// Address: 680b5370
// Size: 222 bytes
// Params: void * param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_initCastRegistry(void *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_18 [2];
  void *local_10;
  int local_c;
  int local_8;
  
  piVar1 = param_2;
  DAT_681963cc = *param_3;
  uVar4 = 0;
  if (*param_2 != 0) {
    media_freeSpriteEntries(param_2);
  }
  piVar2 = stage_allocDispatchEntry(0x40,0x20,0x20,1);
  *param_2 = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    media_getCastTypeCount(&local_8);
    param_2 = (int *)0x1;
    if (0 < local_8) {
      do {
        iVar3 = media_getCastTypeById((int)param_2,&local_c);
        if (iVar3 == 0) {
          media_addCastEntry(param_1,local_c,0,(int *)0x0);
        }
        param_2 = (int *)((int)param_2 + 1);
      } while ((int)param_2 <= local_8);
    }
    uVar4 = Ordinal_1038();
    piVar2 = (int *)Ordinal_2068(uVar4);
    if (piVar2 == (int *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      local_18[0] = *piVar1;
      local_18[1] = 0;
      local_10 = param_1;
      uVar4 = (**(code **)(*piVar2 + 0x14))(piVar2,media_registerCastAsset,local_18);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  *param_3 = DAT_681963cc;
  DAT_6818e4c0 = 0;
  return uVar4;
}



// ============================================================
// Function: media_getAssetRef (FUN_680b5450)
// Address: 680b5450
// Size: 77 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3, undefined2 * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
media_getAssetRef(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined2 *param_4)
{
  int in_EAX;
  
  *param_2 = *(undefined4 *)(in_EAX + 0x51c);
  *param_3 = *(undefined4 *)(in_EAX + 0x520);
  *param_4 = *(undefined2 *)(in_EAX + 0x524);
  *(undefined4 *)(in_EAX + 0x51c) = *(undefined4 *)(in_EAX + 0x64c);
  *(undefined4 *)(in_EAX + 0x520) = *(undefined4 *)(in_EAX + 0x650);
  *(undefined2 *)(in_EAX + 0x524) = *(undefined2 *)(in_EAX + 0x654);
  return 0;
}



// ============================================================
// Function: media_getAssetInfo (FUN_680b54a0)
// Address: 680b54a0
// Size: 74 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined2 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getAssetInfo(undefined4 param_1,undefined4 param_2,undefined2 param_3)
{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x64c) = *(undefined4 *)(in_EAX + 0x51c);
  *(undefined4 *)(in_EAX + 0x650) = *(undefined4 *)(in_EAX + 0x520);
  *(undefined2 *)(in_EAX + 0x654) = *(undefined2 *)(in_EAX + 0x524);
  *(undefined4 *)(in_EAX + 0x51c) = param_1;
  *(undefined4 *)(in_EAX + 0x520) = param_2;
  *(undefined2 *)(in_EAX + 0x524) = param_3;
  return 0;
}



// ============================================================
// Function: media_saveRestoreAssetRef (FUN_680b54f0)
// Address: 680b54f0
// Size: 182 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_saveRestoreAssetRef(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18 [2];
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = param_2;
    if (param_2 == 0) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  media_getAssetRef(local_18,&local_20,&local_1c,local_18);
  Ordinal_603(param_1,param_2,param_3);
  media_getAssetInfo(local_20,local_1c,local_18[0]);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_acquireLock (FUN_680b55b0)
// Address: 680b55b0
// Size: 126 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_acquireLock(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
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
// Function: media_dispatchScoredEvent (FUN_680b5630)
// Address: 680b5630
// Size: 190 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchScoredEvent(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int *piVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18 [2];
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = param_2;
    if (param_2 == 0) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  media_getAssetRef(local_18,&local_20,&local_1c,local_18);
  Ordinal_606(param_1,param_2,param_3,param_4,param_5);
  media_getAssetInfo(local_20,local_1c,local_18[0]);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_dispatchChannelRender (FUN_680b56f0)
// Address: 680b56f0
// Size: 255 bytes
// Params: undefined4 * param_1, int * param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchChannelRender(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int *piVar2;
  int local_30 [2];
  int local_28;
  undefined2 local_24 [2];
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  int *local_14;
  int **local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_4;
  if (0 < param_3) {
    local_1c = (int *)param_1[8];
    piVar2 = (int *)0x0;
    if ((local_1c != (int *)0x0) && (local_1c[1] != 0)) {
      piVar2 = param_2;
      if (param_2 == (int *)0x0) {
        piVar2 = (int *)*local_1c;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = piVar2;
    }
    media_getAssetRef(&local_20,&local_18,&local_20,local_24);
    if (param_5 == 0) {
      Ordinal_607(param_1,param_2,param_3,param_3);
    }
    else {
      Ordinal_601((int)param_1,(int)param_2,(undefined2 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0);
      iVar1 = Ordinal_609(param_1,(int)param_2,param_3);
      Ordinal_608((int)param_1,(int)param_2,iVar1,local_28,param_5);
    }
    media_getAssetInfo(local_18,local_20,local_24[0]);
    local_30[0] = param_3;
    rendering_getChannelProperty((int)piVar2,0x23,local_30);
    if (local_1c != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}



// ============================================================
// Function: media_dispatchAssetEvent (FUN_680b57f0)
// Address: 680b57f0
// Size: 202 bytes
// Params: int param_1, int param_2, undefined2 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchAssetEvent(int param_1,int param_2,undefined2 *param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  int *piVar1;
  undefined4 local_28;
  undefined4 *local_24;
  undefined4 local_20;
  undefined2 local_1c [2];
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  local_18 = param_2;
  local_24 = param_5;
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
  media_getAssetRef(local_1c,&local_28,&local_20,local_1c);
  Ordinal_601(param_1,local_18,param_3,param_4,local_24);
  media_getAssetInfo(local_28,local_20,local_1c[0]);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}




// ============================================================
// Function: media_handleTextHitTest (FUN_680b58c0)
// Address: 680b58c0
// Size: 442 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4, int * param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_handleTextHitTest(int param_1,byte *param_2,int param_3,int param_4,int *param_5,int *param_6)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  int *piVar9;
  uint *puVar10;
  uint local_40;
  int local_3c;
  int *local_38;
  int local_34;
  undefined4 *local_30;
  byte *local_2c;
  int local_28;
  byte *local_24;
  byte **local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_8;
  
  puVar7 = *(undefined4 **)(param_1 + 0x20);
  local_38 = param_6;
  local_28 = -1;
  pbVar8 = (byte *)0x0;
  local_30 = puVar7;
  if ((puVar7 != (undefined4 *)0x0) && (puVar7[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar7;
    }
    Ordinal_2330();
    local_1c = 0;
    local_20 = DAT_68196374;
    pbVar8 = param_2;
    DAT_68196374 = &local_24;
    local_24 = param_2;
  }
  if (param_5 != (int *)0x0) {
    *(undefined2 *)((int)param_5 + 2) = 0xffff;
  }
  if ((*pbVar8 & 8) != 0) {
    local_2c = (byte *)0x0;
    iVar1 = playback_getChannelCountEx((int)pbVar8,param_3,param_4,(int *)&local_2c,&local_3c,0x80ff);
    if (iVar1 != 0) {
      if (local_2c == (byte *)0x0) {
        local_2c = pbVar8;
      }
      puVar6 = (undefined4 *)(local_3c * 400 + *(int *)(local_2c + 0x34));
      if ((((puVar6 != (undefined4 *)0x0) &&
           (piVar2 = (int *)playback_getSpriteData((int)pbVar8,puVar6), puVar7 = local_30,
           piVar2 != (int *)0x0)) && (piVar2[2] == 3)) &&
         (iVar1 = rendering_getMemberData(local_2c,piVar2), puVar7 = local_30, iVar1 != 0)) {
        local_34 = lingo_isValidObject(local_30[1]);
        iVar1 = puVar6[0x32];
        iVar3 = puVar6[0x33];
        bitmap_getTextFieldData((int)piVar2,&local_18);
        iVar5 = (param_4 - iVar3) - local_14;
        iVar3 = (param_3 - iVar1) - local_18;
        puVar10 = &local_40;
        piVar9 = &local_28;
        iVar4 = bitmap_updateTextField((int)piVar2,(int)pbVar8);
        iVar1 = local_34;
        iVar3 = xtra_layoutTextBlock(local_34,iVar4,iVar3,iVar5,piVar9,puVar10);
        *local_38 = iVar3;
        iVar3 = bitmap_updateTextField((int)piVar2,(int)pbVar8);
        iVar1 = xtra_setTextProperty(iVar1,iVar3,local_28);
        if ((int)local_40 < iVar1) {
          *local_38 = *local_38 + -1;
          xtra_measureBufferText(iVar3,local_28,(int)&local_34);
          local_28 = local_28 - local_34;
        }
        rendering_isStateValid((int)piVar2);
        puVar7 = local_30;
        if (param_5 != (int *)0x0) {
          *param_5 = piVar2[1];
        }
      }
    }
  }
  if (puVar7 != (undefined4 *)0x0) {
    DAT_68196374 = local_20;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_registerAssetWithData (FUN_680b5a80)
// Address: 680b5a80
// Size: 174 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, void * param_4, void * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_registerAssetWithData(int param_1,byte *param_2,undefined4 param_3,void *param_4,void *param_5)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar3 = 0;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    iVar3 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(iVar3,param_3);
  if ((piVar2 != (int *)0x0) && ((*pbVar4 & 8) != 0)) {
    bitmap_setTextSelection((int)pbVar4,piVar2,param_4,param_5);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getAssetData (FUN_680b5b30)
// Address: 680b5b30
// Size: 215 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getAssetData(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 *param_5
                 )
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((param_4 != (undefined4 *)0x0) && (param_5 != (undefined4 *)0x0)) {
    iVar2 = rendering_resolveState(iVar2,param_3);
    if ((iVar2 != 0) && ((*(int *)(iVar2 + 8) == 3 || (*(int *)(iVar2 + 8) == 7)))) {
      *param_4 = *(undefined4 *)(iVar2 + 0x84);
      *param_5 = *(undefined4 *)(iVar2 + 0x88);
    }
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_registerAsset (FUN_680b5c10)
// Address: 680b5c10
// Size: 171 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_registerAsset(int param_1,byte *param_2,undefined4 param_3,int param_4)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar3 = 0;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    iVar3 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(iVar3,param_3);
  if ((piVar2 != (int *)0x0) && ((*pbVar4 & 8) != 0)) {
    bitmap_setTextScrollPos(pbVar4,piVar2,param_4);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_lookupAsset (FUN_680b5cc0)
// Address: 680b5cc0
// Size: 170 bytes
// Params: int param_1, byte * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_lookupAsset(int param_1,byte *param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar3 = 0;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    iVar3 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(iVar3,param_3);
  if ((piVar2 != (int *)0x0) && ((*pbVar4 & 8) != 0)) {
    bitmap_getTextScrollPos(pbVar4,piVar2);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_resolveAsset (FUN_680b5d70)
// Address: 680b5d70
// Size: 340 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveAsset(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *local_58;
  undefined4 local_54 [16];
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  uVar5 = 0;
  if (param_1 == 0) {
    local_58 = (undefined4 *)0x0;
  }
  else {
    local_58 = *(undefined4 **)(param_1 + 0x20);
  }
  pbVar3 = (byte *)0x0;
  iVar4 = 0;
  if ((local_58 != (undefined4 *)0x0) && (local_58[1] != 0)) {
    iVar4 = *(int *)(local_58[1] + 8);
    if ((param_1 == 0) ||
       ((*(undefined4 **)(param_1 + 0x20) == (undefined4 *)0x0 ||
        (pbVar3 = (byte *)**(undefined4 **)(param_1 + 0x20), pbVar3 == (byte *)0x0)))) {
      pbVar3 = (byte *)*local_58;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar3;
  }
  iVar1 = Ordinal_374(param_1,param_2,param_3,2,(double *)local_54);
  if (((iVar1 != 0) && (iVar1 = param_3 + -1, -1 < iVar1)) && (iVar1 < *(int *)(pbVar3 + 0x2c))) {
    piVar2 = (int *)rendering_resolveState(iVar4,local_54[0]);
    if (piVar2 != (int *)0x0) {
      if ((*(int *)(*(int *)(pbVar3 + 0x20) + 0x63c) != 0) && (*(int *)(local_58[1] + 0x28) != 0)) {
        Ordinal_1839(*(int *)(local_58[1] + 0x28),0);
      }
      Ordinal_1130(*(int *)(pbVar3 + 0x20) + 0x638,0x10);
      *(undefined4 *)(*(int *)(pbVar3 + 0x20) + 0x638) = 1;
      *(int *)(*(int *)(pbVar3 + 0x20) + 0x63c) = param_5;
      if (param_5 != 0) {
        *(byte **)(*(int *)(pbVar3 + 0x20) + 0x640) = pbVar3;
        *(int *)(*(int *)(pbVar3 + 0x20) + 0x644) = iVar1;
        if ((*pbVar3 & 8) != 0) {
          uVar5 = bitmap_setTextScrollPos(pbVar3,piVar2,param_4);
        }
      }
    }
  }
  if (local_58 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_2,iVar4,uVar5);
  }
  return 0;
}



// ============================================================
// Function: media_getAssetState (FUN_680b5ed0)
// Address: 680b5ed0
// Size: 203 bytes
// Params: int param_1, byte * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getAssetState(int param_1,byte *param_2,undefined4 param_3)
{
  int *piVar1;
  int iVar2;
  void *local_20;
  byte *local_1c;
  void *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = 0;
  local_1c = param_2;
  local_18 = (void *)0x0;
  local_20 = (void *)0x0;
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x638) = 1;
  media_getAssetData(param_1,(int)local_1c,param_3,&local_18,&local_20);
  media_registerAssetWithData(param_1,local_1c,param_3,local_18,local_20);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}




// ============================================================
// Function: media_resolveAssetEx (FUN_680b5fa0)
// Address: 680b5fa0
// Size: 240 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveAssetEx(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_3c;
  byte **local_38;
  undefined4 local_34;
  int local_30;
  byte *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar3 = 0;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    iVar3 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_38 = DAT_68196374;
    local_34 = 0;
    pbVar4 = param_2;
    DAT_68196374 = &local_3c;
    local_3c = param_2;
  }
  if ((*pbVar4 & 8) != 0) {
    local_30 = 0;
    local_2c = (byte *)0x0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    iVar2 = rendering_resolveState(iVar3,param_3);
    if (iVar2 != 0) {
      local_24 = param_4;
      local_28 = 0x1b;
      local_20 = param_5;
      local_1c = param_6;
      local_30 = iVar2;
      local_2c = pbVar4;
      rendering_initState(&local_30);
      lingo_getMovieRef(iVar3);
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_38;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_notifyTextChange (FUN_680b6090)
// Address: 680b6090
// Size: 203 bytes
// Params: int param_1, undefined4 param_2, int param_3, uint param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_notifyTextChange(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)
{
  int *piVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  pbVar3 = (byte *)0x0;
  if (param_1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0x20);
  }
  iVar4 = 0;
  if ((puVar2 != (undefined4 *)0x0) && (puVar2[1] != 0)) {
    iVar4 = *(int *)(puVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(undefined4 **)(param_1 + 0x20) == (undefined4 *)0x0 ||
        (pbVar3 = (byte *)**(undefined4 **)(param_1 + 0x20), pbVar3 == (byte *)0x0)))) {
      pbVar3 = (byte *)*puVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar3;
  }
  piVar1 = (int *)rendering_resolveState(iVar4,param_2);
  if ((piVar1 != (int *)0x0) && ((*pbVar3 & 8) != 0)) {
    bitmap_notifyTextChange((int)pbVar3,piVar1,param_3,param_4,param_5);
  }
  if (puVar2 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_allocAssetContainer (FUN_680b6160)
// Address: 680b6160
// Size: 31 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_allocAssetContainer(undefined4 param_1)
{
  int in_EAX;
  int *piVar1;
  
  piVar1 = stage_allocDispatchEntry(0x28,0x24,4,in_EAX);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(*piVar1 + 0x20) = param_1;
  }
  return 0;
}



// ============================================================
// Function: media_initAssetLoader (FUN_680b6180)
// Address: 680b6180
// Size: 83 bytes
// Params: void * this, int * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_initAssetLoader(void *this,int *param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *local_8;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(*piVar1 + 0x10);
    local_8 = this;
    if (0 < iVar2) {
      iVar3 = 0x24;
      do {
        local_8 = *(void **)(iVar3 + *piVar1);
        if (local_8 != (void *)0x0) {
          Ordinal_36((int *)&local_8);
        }
        iVar3 = iVar3 + 4;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    cast_freeHandle(piVar1);
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: media_cloneAssetContainer (FUN_680b61e0)
// Address: 680b61e0
// Size: 147 bytes
// Params: int * param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_cloneAssetContainer(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int *local_8;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  local_8 = (int *)media_allocAssetContainer(*(undefined4 *)(*param_1 + 0x20));
  if (local_8 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar4 = 0;
  if (0 < iVar1) {
    iVar3 = 0x24;
    while (*(int *)(iVar3 + *param_1) == 0) {
LAB_680b6242:
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
      if (iVar1 <= iVar4) {
        return local_8;
      }
    }
    local_c = Ordinal_1120(*(int *)(iVar3 + *param_1),0);
    if (local_c != 0) {
      iVar2 = stage_lookupSymbolId(local_8,&local_c);
      if (iVar2 != -1) goto LAB_680b6242;
      Ordinal_36(&local_c);
    }
    media_initAssetLoader(&local_8,(int *)&local_8);
    local_8 = (int *)0x0;
  }
  return local_8;
}



// ============================================================
// Function: media_findAssetRef (FUN_680b6280)
// Address: 680b6280
// Size: 11 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_findAssetRef(void)

{
  int *in_EAX;
  
  if (in_EAX == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*in_EAX + 0x10);
}



// ============================================================
// Function: media_findAssetEntry (FUN_680b6290)
// Address: 680b6290
// Size: 458 bytes
// Params: int * param_1, int param_2, int * param_3, uint param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_findAssetEntry(int *param_1,int param_2,int *param_3,uint param_4,int param_5)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_ESI;
  int iVar5;
  undefined1 uVar6;
  char local_40c;
  char local_40b;
  uint local_8;
  
  *(undefined1 *)unaff_ESI = 0;
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  if (param_4 == 10) {
    uVar2 = media_findAssetRef();
    *unaff_ESI = uVar2;
    return 0;
  }
  if (param_4 == 0xc) {
    *unaff_ESI = *(undefined4 *)(*param_3 + 0x20);
    return 0;
  }
  if (((param_2 < 0) || (*(int *)(*param_3 + 0x10) <= param_2)) ||
     (piVar1 = *(int **)(*param_3 + 0x24 + param_2 * 4), piVar1 == (int *)0x0)) goto LAB_680b6447;
  if ((int)param_4 < 0x11) {
    if ((param_4 == 0x10) || (param_4 == 2)) goto LAB_680b643a;
    if (param_4 == 4) {
      Ordinal_1128();
      goto LAB_680b6447;
    }
    if (param_4 != 0xb) goto LAB_680b6399;
    if (param_5 == 2) {
      uVar6 = (undefined1)((uint)*(undefined4 *)(*piVar1 + 4) >> 0x10);
    }
    else {
      if (param_5 != 5) goto LAB_680b6447;
      uVar6 = (undefined1)((uint)*(undefined4 *)(*piVar1 + 4) >> 0x18);
    }
  }
  else {
    if (((param_4 != 0x20) && (param_4 != 0x100)) && (param_4 != 0x200)) {
LAB_680b6399:
      iVar3 = Ordinal_39(piVar1);
      if ((param_5 != 7) && (iVar5 = 0, 0 < iVar3)) {
        do {
          iVar4 = Ordinal_38((int)piVar1,(short)iVar5,&local_40c,0x402);
          if (((iVar4 != 0) && ((int)local_40c == param_4)) &&
             ((param_5 == 0 || (local_40b == param_5)))) {
            Ordinal_1230();
            if (param_1 != (int *)0x0) {
              *param_1 = (int)local_40b;
            }
            goto LAB_680b6447;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar3);
      }
      if (param_1 != (int *)0x0) {
        *param_1 = 7;
      }
      return 0;
    }
LAB_680b643a:
    uVar6 = (*(uint *)(*piVar1 + 4) & param_4) != 0;
  }
  *(undefined1 *)unaff_ESI = uVar6;
LAB_680b6447:
  return 0;
}



// ============================================================
// Function: media_loadAssetBlock (FUN_680b6460)
// Address: 680b6460
// Size: 617 bytes
// Params: int * param_1, byte * param_2, int param_3, uint param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_loadAssetBlock(int *param_1,byte *param_2,int param_3,uint param_4,int param_5)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int *local_410;
  char local_40c;
  char local_40b;
  undefined1 local_40a [1026];
  uint local_8;
  
  if (((param_3 < 0) || (*(int *)(*param_1 + 0x10) <= param_3)) ||
     (local_410 = *(int **)(*param_1 + 0x24 + param_3 * 4), local_410 == (int *)0x0)) {
    return 0;
  }
  if ((int)param_4 < 0x11) {
    if (param_4 != 0x10) {
      switch(param_4) {
      case 2:
        break;
      default:
        goto switchD_680b64d3_caseD_3;
      case 4:
        Ordinal_1128(*local_410 + 8,param_2,0x10);
        return 0;
      case 0xb:
        iVar2 = *local_410;
        if (param_5 == 2) {
          *(uint *)(iVar2 + 4) = (uint)*param_2 << 0x10 | *(uint *)(iVar2 + 4) & 0xff00ffff;
          return 0;
        }
        if (param_5 == 5) {
          *(uint *)(iVar2 + 4) = (uint)*param_2 << 0x18 | *(uint *)(iVar2 + 4) & 0xffffff;
          return 0;
        }
      case 10:
        return 0;
      }
    }
  }
  else if (((param_4 != 0x20) && (param_4 != 0x100)) && (param_4 != 0x200)) {
switchD_680b64d3_caseD_3:
    iVar2 = Ordinal_39(local_410);
    iVar6 = 0;
LAB_680b6596:
    do {
      iVar5 = 0;
      if (0 < iVar2) {
        do {
          iVar3 = Ordinal_38((int)local_410,(short)iVar5,&local_40c,0x402);
          if (iVar6 == 0) {
            if ((0 < iVar3) && ((int)local_40c == param_4)) {
              bVar7 = local_40b == param_5;
LAB_680b65e0:
              iVar3 = iVar5;
              if (bVar7) goto LAB_680b65f6;
            }
          }
          else if (iVar6 == 1) {
            bVar7 = iVar3 == 0;
            goto LAB_680b65e0;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
      }
      if (iVar6 != 0) goto code_r0x680b65ee;
      if (*param_2 == 0) {
        return 0;
      }
      iVar6 = 1;
    } while( true );
  }
  if (*param_2 != 0) {
    puVar1 = (uint *)(*local_410 + 4);
    *puVar1 = *puVar1 | param_4;
    return 0;
  }
  puVar1 = (uint *)(*local_410 + 4);
  *puVar1 = *puVar1 & ~param_4;
  return 0;
code_r0x680b65ee:
  iVar3 = iVar2;
  if ((iVar6 == 1) || (iVar3 = iVar5, iVar6 == 2)) {
LAB_680b65f6:
    Ordinal_1230(local_40a,param_2);
    local_40c = (char)param_4;
    local_40b = (undefined1)param_5;
    if (*param_2 == 0xff) {
      uVar4 = Ordinal_1201(param_2 + 1);
    }
    else {
      uVar4 = (uint)*param_2;
    }
    Ordinal_37(&local_410,(short)iVar3,&local_40c,uVar4 + 4);
    return 0;
  }
  goto LAB_680b6596;
}



