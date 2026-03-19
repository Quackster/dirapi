// Module: core
// Topic: Data conversion, formatting, color/point value handling
// Address range: 0x6801B790 - 0x6801BF40
// Functions (8):
//   core_convertValueForStore (0x6801B790)
//   core_convertValueForLookup (0x6801B890)
//   core_convertAndReadValue (0x6801B990)
//   core_convertAndAccessValue (0x6801BA40)
//   core_accessScoreChannelType (0x6801BCF0)
//   core_accessChannelBounds (0x6801BD80)
//   core_packColorComponents (0x6801BE80)
//   core_parseColorValue (0x6801BF40)

// ============================================================
// Function: core_convertValueForStore (FUN_6801b790)
// Address: 6801b790
// Size: 168 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_convertValueForStore(undefined4 param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  ulonglong uVar3;
  undefined1 local_408 [1024];
  uint local_8;
  
  *unaff_ESI = 0;
  switch(*unaff_EDI) {
  case 1:
  case 0x40:
  case 0x43:
    props_toPascalString(unaff_EDI,local_408);
    iVar1 = sprites_processTextCommand(unaff_EBX,param_3,(int)local_408);
    break;
  default:
    goto switchD_6801b7ba_caseD_2;
  case 4:
    iVar1 = sprites_handleTextCopy(unaff_EBX,param_3,unaff_EDI[1]);
    break;
  case 9:
  case 0x20:
  case 0x23:
    if (*unaff_EDI == 0x20) {
      uVar2 = 0x20;
    }
    else {
      uVar2 = *(undefined4 *)unaff_EDI[1];
    }
    uVar3 = strings_floatToUint64(uVar2,param_2);
    iVar1 = sprites_handleTextCopy(unaff_EBX,param_3,(int)uVar3);
  }
  *unaff_ESI = iVar1;
  if (iVar1 == 0) {
switchD_6801b7ba_caseD_2:
    props_setErrorAndReturn(unaff_EBX,0x28);
  }
  return 0;
}



// ============================================================
// Function: core_convertValueForLookup (FUN_6801b890)
// Address: 6801b890
// Size: 166 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_convertValueForLookup(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  int unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  ulonglong uVar2;
  undefined1 local_408 [1024];
  uint local_8;
  
  *unaff_EDI = 0;
  iVar1 = *unaff_ESI;
  switch(iVar1) {
  case 1:
  case 0x40:
  case 0x43:
    props_toPascalString(unaff_ESI,local_408);
    iVar1 = sprites_handleTextInput(unaff_EBX,(int)local_408);
    break;
  default:
    goto switchD_6801b8ba_caseD_2;
  case 4:
    iVar1 = sprites_handleTextDrag(unaff_EBX,unaff_ESI[1]);
    break;
  case 9:
  case 0x20:
  case 0x23:
    if (iVar1 == 0x20) {
      uVar2 = strings_floatToUint64(0x20,param_2);
      iVar1 = sprites_handleTextDrag(unaff_EBX,(int)uVar2);
    }
    else {
      uVar2 = strings_floatToUint64(iVar1,unaff_ESI[1]);
      iVar1 = sprites_handleTextDrag(unaff_EBX,(int)uVar2);
    }
  }
  *unaff_EDI = iVar1;
  if (iVar1 == 0) {
switchD_6801b8ba_caseD_2:
    props_setErrorAndReturn(unaff_EBX,0x27);
  }
  return 0;
}



// ============================================================
// Function: core_convertAndReadValue (FUN_6801b990)
// Address: 6801b990
// Size: 174 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, undefined4 param_4, int param_5, int param_6, undefined4 * param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
core_convertAndReadValue(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,undefined4 *param_7)
{
  undefined4 uVar1;
  int local_410;
  byte local_408 [1024];
  uint local_8;
  
  core_convertValueForLookup(param_1,param_2);
  if (*(int *)(param_3 + 0x7c) == 0) {
    if (param_5 == 1) {
      if (param_6 == 0) {
        sprites_handleTextPaste(param_3,local_410,(undefined2 *)local_408);
        props_readPascalString(param_3,local_408,param_7);
      }
    }
    else if ((param_5 == 2) && (param_6 == 0)) {
      uVar1 = sprites_handleTextKeyDown(param_3,local_410);
      param_7[1] = uVar1;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_convertAndAccessValue (FUN_6801ba40)
// Address: 6801ba40
// Size: 670 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, int param_4, undefined4 param_5, undefined4 param_6, int param_7, int * param_8
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
core_convertAndAccessValue(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7,int *param_8)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  int *piVar3;
  int local_418;
  int *local_414;
  int local_410;
  int local_40c;
  byte local_408 [1024];
  
  local_40c = param_4;
  local_414 = param_8;
  core_convertValueForLookup(param_8,param_2);
  if ((*(int *)(param_3 + 0x7c) == 0) &&
     (core_convertValueForStore(extraout_ECX,local_410,local_410), piVar3 = local_414,
     *(int *)(param_3 + 0x7c) == 0)) {
    switch(param_6) {
    case 1:
      if (param_7 == 0) {
        sprites_handleTextCut(param_3,local_410,local_40c,(undefined2 *)local_408);
        props_readPascalString(param_3,local_408,local_414);
        return 0;
      }
      iVar1 = props_validateString(param_3,local_414);
      if (iVar1 != 0) {
        props_toPascalString(piVar3,local_408);
        sprites_handleTextSelectAll(param_3,local_410,local_40c,(int)local_408);
        return 0;
      }
      break;
    case 2:
      if (param_7 == 0) {
        iVar1 = sprites_handleTextUndo(param_3,local_410,local_40c);
        local_414[1] = iVar1;
        return 0;
      }
      iVar1 = props_requireInt(param_3,local_414,&local_418);
      if (iVar1 != 0) {
        sprites_handleTextDelete(param_3,local_410,local_40c,(uint)(local_418 != 0));
        return 0;
      }
      break;
    case 3:
      if (param_7 == 0) {
        iVar1 = sprites_handleTextClear(param_3,local_410,local_40c);
        local_414[1] = iVar1;
        return 0;
      }
      iVar1 = props_requireInt(param_3,local_414,&local_418);
      if (iVar1 != 0) {
        sprites_getTextEditState(param_3,local_410,local_40c,(uint)(local_418 != 0));
        return 0;
      }
      break;
    case 4:
      if (param_7 == 0) {
        puVar2 = (undefined4 *)sprites_setTextEditState(param_3,local_410,local_40c);
        props_getValuePair(param_3,puVar2,piVar3);
      }
      else {
        iVar1 = props_validateString(param_3,local_414);
        if (iVar1 != 0) {
          puVar2 = props_copyString(piVar3);
          sprites_getTextScrollPos(param_3,local_410,local_40c,(int)puVar2);
          props_freeStringCallback(piVar3,puVar2);
          return 0;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessScoreChannelType (FUN_6801bcf0)
// Address: 6801bcf0
// Size: 134 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessScoreChannelType(int param_1,int *param_2,int param_3,int param_4,int *param_5)
{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 extraout_var;
  
  iVar1 = param_1;
  iVar3 = props_requireInt(param_1,param_2,&param_1);
  if ((iVar3 != 0) && (param_3 == 1)) {
    if (param_4 == 0) {
      uVar2 = stage_getScoreChannelType(iVar1,param_1);
      param_5[1] = CONCAT22(extraout_var,uVar2);
    }
    else {
      iVar3 = props_requireInt(iVar1,param_5,(int *)&param_2);
      if (iVar3 != 0) {
        if (0xff < (int)param_2) {
          param_2 = (int *)0xff;
          stage_setScoreChannelType(iVar1,param_1,0xff);
          return 0;
        }
        if ((int)param_2 < 0) {
          param_2 = (int *)0x0;
        }
        stage_setScoreChannelType(iVar1,param_1,param_2);
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessChannelBounds (FUN_6801bd80)
// Address: 6801bd80
// Size: 206 bytes
// Params: int param_1, short param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessChannelBounds(int param_1,short param_2,int param_3,int param_4,int *param_5)
{
  float fVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 extraout_ST0;
  ulonglong uVar2;
  double local_c;
  
  if (param_4 != 0) {
    switch(*param_5) {
    case 4:
      fVar1 = (float)(size_t)param_5[1];
      break;
    default:
      props_setErrorAndReturn(param_1,7);
      return 0;
    case 9:
    case 0x20:
    case 0x23:
      if (*param_5 == 0x20) {
        fVar1 = (float)(size_t)param_5[1];
      }
      else {
        fVar1 = (float)*(double *)(*(int *)param_5[1] + 8);
      }
    }
    local_c = (double)fVar1;
    sprites_getChannelBounds(param_1,(int)param_2,1,param_3,(uint *)&local_c);
    return 0;
  }
  sprites_getChannelBounds(param_1,(int)param_2,0,param_3,(uint *)&local_c);
  uVar2 = strings_floatToUint64(extraout_ECX,extraout_EDX);
  param_5[1] = (int)uVar2;
  if (extraout_ST0 != (float10)(int)uVar2) {
    props_storeNumber(param_1,(double)extraout_ST0,param_5);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: core_packColorComponents (FUN_6801be80)
// Address: 6801be80
// Size: 178 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_packColorComponents(undefined4 *param_1)
{
  int iVar1;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  uint uVar2;
  
  if (*(short *)((int)unaff_EBX + 6) < 1) {
    *param_1 = 4;
    param_1[1] = *unaff_EBX;
    return 0;
  }
  uVar2 = 1;
  props_pushValue(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x1c) = 4;
  *(uint *)(unaff_ESI + 0x20) =
       CONCAT22(*(undefined2 *)(unaff_EBX + 1),*(undefined2 *)((int)unaff_EBX + 6));
  if (0 < *(short *)((int)unaff_EBX + 10)) {
    props_pushValue(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x1c) = 4;
    *(uint *)(unaff_ESI + 0x20) =
         CONCAT22(*(undefined2 *)(unaff_EBX + 2),*(undefined2 *)((int)unaff_EBX + 10));
    uVar2 = 2;
  }
  props_pushValue(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x1c) = 4;
  *(uint *)(unaff_ESI + 0x20) = uVar2 | 0x80000000;
  props_getRectOpsCount(unaff_ESI);
  *param_1 = *(undefined4 *)(unaff_ESI + 0x1c);
  param_1[1] = *(undefined4 *)(unaff_ESI + 0x20);
  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
  iVar1 = **(int **)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0x18));
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x18));
  return 0;
}



// ============================================================
// Function: core_parseColorValue (FUN_6801bf40)
// Address: 6801bf40
// Size: 303 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_parseColorValue(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_c [2];
  
  piVar1 = param_2;
  iVar2 = param_1;
  iVar4 = score_checkType(param_1,param_2);
  if (iVar4 == 0x58) {
    iVar4 = props_coerceToInt(iVar2,piVar1,(int *)&param_2);
    if (iVar4 != 0) {
      *(undefined2 *)((int)param_3 + 10) = 0;
      *param_3 = -1;
      *(short *)(param_3 + 1) = (short)((uint)param_2 >> 0x10);
      *(short *)((int)param_3 + 6) = (short)param_2;
      sprites_checkBounds(iVar2,(short *)(param_3 + 1));
      return 1;
    }
  }
  iVar4 = props_coerceToInt(iVar2,piVar1,&param_1);
  if (iVar4 != 0) {
    *param_3 = param_1;
    *(undefined2 *)((int)param_3 + 6) = 0;
    *(undefined2 *)((int)param_3 + 10) = 0;
    return 1;
  }
  iVar4 = props_setRectField(iVar2,piVar1);
  if (iVar4 == 0) {
    props_setError(iVar2,0x40);
    return 0;
  }
  piVar1 = (int *)piVar1[1];
  iVar4 = props_getListEntryAsInt(iVar2,piVar1,0,local_c,0);
  piVar3 = param_3;
  if (iVar4 == 0) {
    return 0;
  }
  *(undefined2 *)((int)param_3 + 10) = 0;
  *param_3 = -1;
  *(short *)(param_3 + 1) = (short)((uint)local_c[1] >> 0x10);
  *(short *)((int)param_3 + 6) = (short)local_c[1];
  sprites_checkBounds(iVar2,(short *)(param_3 + 1));
  iVar4 = props_getListEntryAsInt(iVar2,piVar1,1,local_c,1);
  if (iVar4 != 0) {
    piVar1 = piVar3 + 2;
    *(short *)piVar1 = (short)((uint)local_c[1] >> 0x10);
    *(short *)((int)piVar3 + 10) = (short)local_c[1];
    sprites_checkBounds(iVar2,(short *)piVar1);
  }
  return 1;
}


