// Module: score
// Topic: Color object creation, access, properties
// Address range: 0x68046910 - 0x68046de0
// Functions (11):
//   score_serializeColor
//   score_isColorObject
//   score_getColorFromObject
//   score_createColorObject
//   score_getDaysInMonth
//   score_yearFromDayCount
//   score_getColorValue
//   score_dateFromDayCount
//   score_parseDateString
//   score_convertDateValue
//   score_handleColorCommand

// ============================================================
// Function: score_serializeColor (FUN_68046910)
// Address: 68046910
// Size: 156 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_serializeColor(undefined4 *param_1,int *param_2)
{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_c;
  uint local_8;
  
  uVar1 = *(uint *)(*param_2 + 8);
  if ((char)(uVar1 >> 0x18) == '\0') {
    uVar3 = stage_serializeData(param_1,param_2,0,0xf,1);
    if (uVar3 != 0) {
      return 0;
    }
  }
  else {
    uVar3 = stage_serializeData(param_1,param_2,0,0xf,3);
    if (uVar3 != 0) {
      return 0;
    }
    local_8 = uVar1 & 0xff;
    local_c = 4;
    bVar2 = stage_serializeFloat(param_1,&local_c);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      return 0;
    }
    local_8 = uVar1 >> 0x10 & 0xff;
    local_c = 4;
    bVar2 = stage_serializeFloat(param_1,&local_c);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      return 0;
    }
    uVar1 = uVar1 >> 8;
  }
  local_8 = uVar1 & 0xff;
  local_c = 4;
  stage_serializeFloat(param_1,&local_c);
  return 0;
}


// ============================================================
// Function: score_isColorObject (FUN_680469c0)
// Address: 680469c0
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_isColorObject(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d620)) {
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_getColorFromObject (FUN_680469f0)
// Address: 680469f0
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getColorFromObject(undefined4 param_1,int *param_2,int *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d620)) {
    *param_3 = (*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_createColorObject (FUN_68046a20)
// Address: 68046a20
// Size: 61 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_createColorObject(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0xc,1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_LAB_6818d620;
  puVar1[1] = 1;
  puVar1[2] = *param_2;
  return 0;
}


// ============================================================
// Function: score_getDaysInMonth (FUN_68046a60)
// Address: 68046a60
// Size: 91 bytes
// Params: uint param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall score_getDaysInMonth(uint param_1)

{
  int in_EAX;
  uint uVar1;
  bool bVar2;
  
  if (in_EAX == 1) {
    uVar1 = param_1 & 0x80000003;
    bVar2 = uVar1 == 0;
    if ((int)uVar1 < 0) {
      bVar2 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if ((bVar2) &&
       ((param_1 != ((int)param_1 / 100) * 100 || (param_1 == ((int)param_1 / 400) * 400)))) {
      return *(int *)(&DAT_6818d66c + in_EAX * 4) + 1;
    }
  }
  return *(int *)(&DAT_6818d66c + in_EAX * 4);
}


// ============================================================
// Function: score_yearFromDayCount (FUN_68046ac0)
// Address: 68046ac0
// Size: 186 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_yearFromDayCount(int *param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = in_EAX + 0xafaa7;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar3 != 0x16c && -1 < iVar3 + -0x16c) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + -0x16d;
    } while (0 < ((iVar1 / 100 - iVar1 / 400) - ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2)) + iVar2
                 + -0x16c + iVar3);
  }
  iVar2 = iVar1 + -1;
  *param_1 = ((iVar2 / 100 - iVar2 / 400) - ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2)) +
             iVar1 * -0x16d + iVar3;
  return iVar1;
}


// ============================================================
// Function: score_getColorValue (FUN_68046b80)
// Address: 68046b80
// Size: 211 bytes
// Params: void * this, int param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall score_getColorValue(void *this,int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (in_EAX < 1) {
    this = (void *)((int)this + in_EAX / 0xc + -1);
    in_EAX = in_EAX + (in_EAX / 0xc) * -0xc + 0xc;
  }
  else if (0xc < in_EAX) {
    this = (void *)((int)this + in_EAX / 0xc);
    in_EAX = in_EAX % 0xc;
  }
  iVar2 = (int)this + -1;
  uVar3 = in_EAX - 2;
  iVar2 = (iVar2 / 400 - iVar2 / 100) + ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) +
          (int)this * 0x16d;
  if (-1 < (int)uVar3) {
    do {
      iVar1 = score_getDaysInMonth((uint)this);
      uVar3 = uVar3 - 1;
      iVar2 = iVar2 + iVar1;
    } while (uVar3 < 0x80000000);
    return iVar2 + -0xafaa8 + param_1;
  }
  return iVar2 + -0xafaa8 + param_1;
}


// ============================================================
// Function: score_dateFromDayCount (FUN_68046c60)
// Address: 68046c60
// Size: 108 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dateFromDayCount(undefined4 param_1,uint *param_2,int *param_3,int *param_4)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  iVar3 = 0;
  local_8 = 0;
  uVar1 = score_yearFromDayCount(&local_8);
  iVar4 = local_8;
  do {
    iVar2 = score_getDaysInMonth(uVar1);
    iVar3 = iVar3 + 1;
    if (iVar4 < iVar2) {
      *param_2 = uVar1;
      *param_3 = iVar3;
      *param_4 = iVar4 + 1;
      return 0;
    }
    iVar4 = iVar4 - iVar2;
  } while (iVar3 < 0xc);
  *param_2 = uVar1 + 1;
  *param_3 = 1;
  *param_4 = iVar4 + 1;
  return 0;
}


// ============================================================
// Function: score_parseDateString (FUN_68046cd0)
// Address: 68046cd0
// Size: 176 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_parseDateString(int param_1,int *param_2)

{
  char *_Src;
  char *_Src_00;
  char cVar1;
  int iVar2;
  char *unaff_EBX;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  int local_c;
  char local_5;
  
  local_14 = (void *)0x0;
  local_10 = 1;
  local_c = 1;
  local_18 = 0;
  if (3 < param_1) {
    local_5 = unaff_EBX[4];
    _Src = unaff_EBX + 4;
    *_Src = '\0';
    sscanf(unaff_EBX,"%d",&local_14);
    local_18 = 1;
    if (5 < param_1) {
      cVar1 = unaff_EBX[6];
      _Src_00 = unaff_EBX + 6;
      *_Src = local_5;
      *_Src_00 = '\0';
      local_5 = cVar1;
      sscanf(_Src,"%d",&local_10);
      if (7 < param_1) {
        *_Src_00 = local_5;
        unaff_EBX[8] = '\0';
        sscanf(_Src_00,"%d",&local_c);
      }
    }
  }
  iVar2 = score_getColorValue(local_14,local_c);
  *param_2 = iVar2;
  return local_18;
}


// ============================================================
// Function: score_convertDateValue (FUN_68046d80)
// Address: 68046d80
// Size: 93 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_convertDateValue(undefined4 param_1)
{
  char cVar1;
  char *pcVar2;
  int *unaff_ESI;
  char local_108 [256];
  uint local_8;
  
  sprintf(local_108,"%ld",param_1);
  pcVar2 = local_108;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  score_parseDateString((int)pcVar2 - (int)(local_108 + 1),unaff_ESI);
  return 0;
}


// ============================================================
// Function: score_handleColorCommand (FUN_68046de0)
// Address: 68046de0
// Size: 101 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_handleColorCommand(uint param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c [2];
  
  puVar2 = (undefined4 *)0x0;
  if (param_3 == 0xe3) {
    score_resolveType(param_1);
    return true;
  }
  if (param_3 != 0xe4) {
    return false;
  }
  iVar1 = score_createXtraInstance(param_2);
  if (iVar1 == 0) {
    puVar2 = local_c;
  }
  props_popArgs(param_1,puVar2);
  return iVar1 == 0;
}


