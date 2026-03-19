// Module: score
// Topic: API dispatch, script member operations
// Address range: 0x6804b2e0 - 0x6804b560
// Functions (12):
//   score_setPropertyTriple (FUN_6804b2e0)
//   score_getPropertyConditional (FUN_6804b350)
//   score_getScriptMember (FUN_6804b3c0)
//   score_setScriptMember (FUN_6804b400)
//   score_getMediaMember (FUN_6804b430)
//   score_setMediaMember (FUN_6804b470)
//   score_dispatchMediaValue (FUN_6804b4a0)
//   score_lookupPropertyValue (FUN_6804b4b0)
//   score_attachSprite (FUN_6804b4f0)
//   score_getFrameSprite (FUN_6804b510)
//   score_initFrameSprite (FUN_6804b530)
//   score_dispatchScriptCall (FUN_6804b560)

// ============================================================
// Function: score_setPropertyTriple (FUN_6804b2e0)
// Address: 6804b2e0
// Size: 101 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setPropertyTriple(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)
{
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = *param_3;
  local_14 = param_3[1];
  local_10 = *param_4;
  local_c = param_4[1];
  score_getPropertyByIndex(0xdb,3,&local_20,(int *)0x0,0);
  return 0;
}


// ============================================================
// Function: score_getPropertyConditional (FUN_6804b350)
// Address: 6804b350
// Size: 102 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getPropertyConditional(undefined4 param_1,uint *param_2,undefined4 param_3,int *param_4)
{
  int iVar1;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = 4;
  local_14 = param_3;
  iVar1 = score_validateBounds(param_1);
  if (iVar1 == 0) {
    score_getPropertyByIndex(0xd6,2,&local_20,param_4,0);
  }
  return 0;
}


// ============================================================
// Function: score_getScriptMember (FUN_6804b3c0)
// Address: 6804b3c0
// Size: 62 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getScriptMember(undefined4 param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  *param_3 = 0;
  iVar2 = score_extractXtraObject(param_1,param_2,param_3);
  if (iVar2 != 0) {
    piVar1 = (int *)*param_3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    return 0;
  }
  return 0x800407f2;
}


// ============================================================
// Function: score_setScriptMember (FUN_6804b400)
// Address: 6804b400
// Size: 36 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_setScriptMember(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  (**(code **)(*param_2 + 4))(param_2);
  score_createXtraRef(param_1,param_2,param_3);
  return 0;
}


// ============================================================
// Function: score_getMediaMember (FUN_6804b430)
// Address: 6804b430
// Size: 62 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getMediaMember(undefined4 param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  *param_3 = 0;
  iVar2 = score_getMediaProperty(param_1,param_2,param_3);
  if (iVar2 != 0) {
    piVar1 = (int *)*param_3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    return 0;
  }
  return 0x800407f4;
}


// ============================================================
// Function: score_setMediaMember (FUN_6804b470)
// Address: 6804b470
// Size: 36 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_setMediaMember(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  (**(code **)(*param_2 + 4))(param_2);
  score_setMediaProperty(param_1,param_2,param_3);
  return 0;
}


// ============================================================
// Function: score_dispatchMediaValue (FUN_6804b4a0)
// Address: 6804b4a0
// Size: 9 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchMediaValue(undefined4 param_1,int *param_2)
{
  score_getMediaValue(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_lookupPropertyValue (FUN_6804b4b0)
// Address: 6804b4b0
// Size: 52 bytes
// Params: undefined4 param_1, int param_2, uint param_3
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall score_lookupPropertyValue(undefined4 param_1,int param_2,uint param_3)

{
  int *in_EAX;
  uint *puVar1;
  
  if (*(int **)(*in_EAX + 0x24) == (int *)0x0) {
    props_setError(param_2,0x60);
  }
  else {
    puVar1 = score_lookupProperty(*(int **)(*in_EAX + 0x24),param_3,0,(uint *)0x0);
    if (puVar1 != (uint *)0x0) {
      return puVar1[1];
    }
  }
  return 0xffffffff;
}


// ============================================================
// Function: score_attachSprite (FUN_6804b4f0)
// Address: 6804b4f0
// Size: 21 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_attachSprite(int param_1)
{
  int *in_EAX;
  
  if (in_EAX != (int *)0x0) {
    sprites_getNetStatus(param_1,in_EAX);
  }
  return 0;
}


// ============================================================
// Function: score_getFrameSprite (FUN_6804b510)
// Address: 6804b510
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getFrameSprite(int param_1)
{
  int *in_EAX;
  
  sprites_readNetData(param_1,*(int **)(*in_EAX + 0x30));
  return 0;
}


// ============================================================
// Function: score_initFrameSprite (FUN_6804b530)
// Address: 6804b530
// Size: 34 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall score_initFrameSprite(undefined4 param_1,int param_2)
{
  int *in_EAX;
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  
  if (in_EAX == (int *)0x0) {
    iVar1 = *(int *)(*unaff_ESI + 0x34);
  }
  else {
    iVar1 = *(int *)(*in_EAX + 0x14);
  }
  if (iVar1 == 0) {
    uVar2 = score_getFrameSprite(param_2);
    *(undefined4 *)(*unaff_ESI + 0x34) = uVar2;
  }
  return 0;
}


// ============================================================
// Function: score_dispatchScriptCall (FUN_6804b560)
// Address: 6804b560
// Size: 733 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall score_dispatchScriptCall(int param_1,int *param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  int local_70 [3];
  int local_64;
  int local_60;
  uint local_5c;
  undefined1 *local_58;
  uint local_54;
  int local_50;
  undefined4 *local_4c;
  undefined1 local_48 [64];
  
  local_50 = param_3;
  if (param_1 < 0) goto LAB_6804b58a;
  local_54 = props_getInt(unaff_EBX);
  iVar2 = (int)(short)((uint)param_1 >> 0x10);
  uVar1 = *(uint *)(**(int **)(*param_2 + 0x2c) + 0x20 + iVar2 * 4);
  uVar7 = uVar1 & 0xffff3fff;
  if ((local_50 == 0) && ((uVar1 & 0xc000) == 0)) {
    iVar2 = 0x4a;
  }
  else {
    iVar6 = 1;
    if (0 < (int)uVar7) {
      local_4c = (undefined4 *)(**(int **)(*param_2 + 0x2c) + 0x24 + iVar2 * 4);
      do {
        switch(*local_4c) {
        case 0xe:
          goto switchD_6804b604_caseD_e;
        default:
          iVar2 = -1;
          break;
        case 0x8b:
          iVar2 = 1;
          break;
        case 0x8c:
          iVar2 = 8;
          break;
        case 0x95:
          iVar2 = 4;
          break;
        case 0x97:
          iVar2 = 9;
          break;
        case 0xa8:
          iVar2 = 3;
        }
        if ((int)local_54 < iVar6) goto LAB_6804b6dd;
        if ((iVar2 != -1) &&
           (iVar5 = *(int *)(**(int **)(unaff_EBX + 0x10) + -8 +
                             (iVar6 - *(int *)(unaff_EBX + 0x20)) * 8 + *(int *)(unaff_EBX + 0x18)),
           iVar5 != iVar2)) {
          if (iVar2 == 9) {
            if (iVar5 != 0x20) {
              bVar9 = iVar5 == 0x23;
LAB_6804b672:
              if (!bVar9) goto LAB_6804b6e4;
            }
          }
          else {
            if (iVar2 != 1) {
LAB_6804b6e4:
              props_setTypeError(unaff_EBX,iVar2);
              goto LAB_6804b826;
            }
            if (iVar5 != 0x40) {
              bVar9 = iVar5 == 0x43;
              goto LAB_6804b672;
            }
          }
        }
        local_4c = local_4c + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 <= (int)uVar7);
    }
    if (uVar7 == local_54) {
switchD_6804b604_caseD_e:
      local_5c = props_getInt(unaff_EBX);
      if ((int)local_5c < 9) {
        iVar2 = 1;
        puVar8 = (undefined4 *)0x0;
        local_58 = local_48;
        if (0 < (int)local_5c) {
          do {
            _DAT_68197764 =
                 (int *)(**(int **)(unaff_EBX + 0x10) + -8 +
                         (iVar2 - *(int *)(unaff_EBX + 0x20)) * 8 + *(int *)(unaff_EBX + 0x18));
            iVar6 = DAT_6819776c;
            iVar5 = DAT_68197768;
            if (_DAT_68197764 != (int *)0x0) {
              DAT_6819776c = 0;
              DAT_68197768 = 0;
              iVar6 = ((int *)(size_t)_DAT_68197764)[1];
              iVar5 = *(int *)(size_t)_DAT_68197764;
            }
            (&local_50)[iVar2 * 2] = iVar5;
            *(int *)(local_48 + iVar2 * 8 + -4) = iVar6;
            iVar2 = iVar2 + 1;
          } while (iVar2 <= (int)local_5c);
          puVar8 = (undefined4 *)0x0;
          goto LAB_6804b79f;
        }
      }
      else {
        puVar8 = (undefined4 *)cast_allocHandle(local_5c * 8,0);
        local_4c = puVar8;
        if (puVar8 == (undefined4 *)0x0) goto LAB_6804b58a;
        local_58 = (undefined1 *)Ordinal_1114(puVar8);
        iVar2 = 1;
        if (0 < (int)local_5c) {
          do {
            _DAT_68197764 =
                 (int *)(**(int **)(unaff_EBX + 0x10) + -8 +
                         (iVar2 - *(int *)(unaff_EBX + 0x20)) * 8 + *(int *)(unaff_EBX + 0x18));
            iVar6 = DAT_6819776c;
            iVar5 = DAT_68197768;
            if (_DAT_68197764 != (int *)0x0) {
              DAT_6819776c = 0;
              DAT_68197768 = 0;
              iVar6 = ((int *)(size_t)_DAT_68197764)[1];
              iVar5 = *(int *)(size_t)_DAT_68197764;
            }
            *(int *)(local_58 + iVar2 * 8 + -8) = iVar5;
            *(int *)(local_58 + iVar2 * 8 + -4) = iVar6;
            iVar2 = iVar2 + 1;
            puVar8 = local_4c;
          } while (iVar2 <= (int)local_5c);
        }
LAB_6804b79f:
        if (local_58 == (undefined1 *)0x0) {
LAB_6804b58a:
          return 0;
        }
      }
      local_70[1] = 0;
      local_5c = local_54;
      local_60 = 0;
      local_70[0] = local_50;
      local_64 = 2;
      local_70[2] = (int)(short)param_1;
      piVar3 = (int *)score_initFrameSprite((int)(short)param_1,unaff_EBX);
      if ((((piVar3 == (int *)0x0) || (unaff_EBX == 0)) || (*(int *)(unaff_EBX + 8) == 0)) ||
         (*(int *)(*(int *)(unaff_EBX + 8) + 4) == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = sprites_sendNetMessage(unaff_EBX,piVar3,local_70);
      }
      if (puVar8 != (undefined4 *)0x0) {
        cast_freeHandle(puVar8);
      }
      if (iVar2 == 0) {
        props_normalizeType(unaff_EBX,local_64,local_60);
        goto LAB_6804b826;
      }
      uVar4 = props_translateError(iVar2);
      iVar2 = (int)(short)uVar4;
    }
    else {
LAB_6804b6dd:
      iVar2 = 0x19;
    }
  }
  props_setError(unaff_EBX,iVar2);
LAB_6804b826:
  return 0;
}


