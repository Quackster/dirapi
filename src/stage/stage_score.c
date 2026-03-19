// Module: stage
// Topic: Score/cast member management
// Address range: 0x6805D7E0 - 0x6805DEE0
// Functions (17):
//   stage_registerScoreProperties (FUN_6805D7E0)
//   stage_updateScoreProperty (FUN_6805DAA0)
//   stage_getScoreData (FUN_6805DB20)
//   stage_setScoreChannel (FUN_6805DB40)
//   stage_loadScoreMember (FUN_6805DB80)
//   stage_selectScoreChannel (FUN_6805DC10)
//   stage_getScoreSelection (FUN_6805DC40)
//   stage_getScoreChannelCount (FUN_6805DC60)
//   stage_getScoreChannelType (FUN_6805DCA0)
//   stage_setScoreChannelType (FUN_6805DCD0)
//   stage_getScoreChannelName (FUN_6805DD00)
//   stage_getScoreChannelScript (FUN_6805DD20)
//   stage_setScoreChannelPosition (FUN_6805DD40)
//   stage_loadScoreString (FUN_6805DD70)
//   stage_enumerateScoreHandlers (FUN_6805DDC0)
//   stage_getScoreFileName (FUN_6805DE50)
//   stage_matchScoreHandler (FUN_6805DEE0)

// ============================================================
// Function: stage_registerScoreProperties (FUN_6805D7E0)
// Address: 6805d7e0
// Size: 704 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_registerScoreProperties(int param_1)
{
  stage_storeProperty(param_1,299,0x6818e33c);
  stage_storeProperty(param_1,0x128,0x6818e348);
  stage_storeProperty(param_1,0x129,0x6818e354);
  stage_storeProperty(param_1,0x12a,0x6818e360);
  stage_storeProperty(param_1,0x9d,0x6818e12c);
  stage_storeProperty(param_1,0x9e,0x6818e138);
  stage_storeProperty(param_1,0x9f,0x6818e144);
  stage_storeProperty(param_1,0xa0,0x6818e150);
  stage_storeProperty(param_1,0xa1,0x6818e15c);
  stage_storeProperty(param_1,0xa2,0x6818e168);
  stage_storeProperty(param_1,0xa3,0x6818e18c);
  stage_storeProperty(param_1,0xa4,0x6818e174);
  stage_storeProperty(param_1,0xa5,0x6818e1a4);
  stage_storeProperty(param_1,0xa6,0x6818e1a4);
  stage_storeProperty(param_1,0xa7,0x6818e1a4);
  stage_storeProperty(param_1,0x69,0x6818e1bc);
  stage_storeProperty(param_1,0x86,0x6818e1ec);
  stage_storeProperty(param_1,0x87,0x6818e1f8);
  stage_storeProperty(param_1,0x85,0x6818e204);
  stage_storeProperty(param_1,0x84,0x6818e210);
  stage_storeProperty(param_1,0x88,0x6818e21c);
  stage_storeProperty(param_1,0x99,0x6818e2e8);
  stage_storeProperty(param_1,0x9a,0x6818e2f4);
  stage_storeProperty(param_1,0x80,0x6818e30c);
  stage_storeProperty(param_1,0x7f,0x6818e318);
  stage_storeProperty(param_1,0x7e,0x6818e324);
  stage_storeProperty(param_1,0x89,0x6818e228);
  stage_storeProperty(param_1,0x8a,0x6818e234);
  stage_storeProperty(param_1,0x8b,0x6818e240);
  stage_storeProperty(param_1,0x8c,0x6818e24c);
  stage_storeProperty(param_1,0x8d,0x6818e258);
  stage_storeProperty(param_1,0x8e,0x6818e264);
  stage_storeProperty(param_1,0x8f,0x6818e270);
  stage_storeProperty(param_1,0x90,0x6818e27c);
  stage_storeProperty(param_1,0x92,0x6818e288);
  stage_storeProperty(param_1,0x93,0x6818e294);
  stage_storeProperty(param_1,0x94,0x6818e2a0);
  stage_storeProperty(param_1,0x41,0x6818e2ac);
  stage_storeProperty(param_1,0x95,0x6818e2b8);
  stage_storeProperty(param_1,0x96,0x6818e2c4);
  stage_storeProperty(param_1,0x97,0x6818e2d0);
  stage_storeProperty(param_1,0x98,0x6818e2dc);
  stage_storeProperty(param_1,0x9c,0x6818e330);
  stage_storeProperty(param_1,0x9b,0x6818e300);
  return 0;
}



// ============================================================
// Function: stage_updateScoreProperty (FUN_6805DAA0)
// Address: 6805daa0
// Size: 121 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateScoreProperty(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (iVar1 != 0) {
    local_14[0] = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_3);
    if (param_2 == 0) {
      scoreEngine_getPropertyData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),6,(byte *)local_14);
      return 0;
    }
    Ordinal_376(*(int *)(iVar1 + 0x20),local_14[0],param_2);
  }
  return 0;
}



// ============================================================
// Function: stage_getScoreData (FUN_6805db20)
// Address: 6805db20
// Size: 19 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_getScoreData(int *param_1)
{
  if ((*param_1 < 1) || (0x20 < *param_1)) {
    *param_1 = 1;
  }
  return 0;
}



// ============================================================
// Function: stage_setScoreChannel (FUN_6805DB40)
// Address: 6805db40
// Size: 58 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setScoreChannel(int param_1,int param_2,int param_3,int param_4)
{
  stage_getScoreData(&param_2);
  scoreEngine_setPropertyColor(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),param_2,param_3 * 0x11,
               param_4 * 0x101);
  return 0;
}



// ============================================================
// Function: stage_loadScoreMember (FUN_6805DB80)
// Address: 6805db80
// Size: 130 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_loadScoreMember(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  undefined1 local_420 [1048];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  stage_getScoreData(&param_2);
  Ordinal_1309(local_420,0x400,extraout_EDX + 1,2);
  iVar2 = scoreEngine_setPropertyEx(*(int *)(iVar1 + 0x20),local_420,4,0,0);
  if (iVar2 != 0) {
    scoreEngine_getPropertyList(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,local_420);
  }
  return 0;
}



// ============================================================
// Function: stage_selectScoreChannel (FUN_6805DC10)
// Address: 6805dc10
// Size: 41 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_selectScoreChannel(int param_1,int param_2)
{
  int extraout_EDX;
  
  if (*(int *)(*(int *)(param_1 + 8) + 4) != 0) {
    stage_getScoreData(&param_2);
    Ordinal_256(*(int *)(extraout_EDX + 0x20),param_2);
  }
  return 0;
}



// ============================================================
// Function: stage_getScoreSelection (FUN_6805DC40)
// Address: 6805dc40
// Size: 25 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getScoreSelection(undefined4 param_1,int param_2)
{
  stage_getScoreData(&param_2);
  Ordinal_1915(param_2 + -1);
  return 0;
}



// ============================================================
// Function: stage_getScoreChannelCount (FUN_6805DC60)
// Address: 6805dc60
// Size: 51 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_getScoreChannelCount(int param_1,int param_2)

{
  undefined4 uVar1;
  int extraout_EDX;
  
  if (*(int *)(*(int *)(param_1 + 8) + 4) == 0) {
    return 0;
  }
  stage_getScoreData(&param_2);
  uVar1 = Ordinal_257(*(int *)(extraout_EDX + 0x20),*(int *)(extraout_EDX + 0x28),param_2);
  return uVar1;
}



// ============================================================
// Function: stage_getScoreChannelType (FUN_6805DCA0)
// Address: 6805dca0
// Size: 40 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 stage_getScoreChannelType(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int extraout_EDX;
  
  stage_getScoreData(&param_2);
  uVar1 = scoreEngine_getPropertyColor(*(int *)(extraout_EDX + 0x20),param_2);
  return uVar1;
}



// ============================================================
// Function: stage_setScoreChannelType (FUN_6805DCD0)
// Address: 6805dcd0
// Size: 45 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setScoreChannelType(int param_1,int param_2,undefined4 param_3)
{
  int extraout_EDX;
  
  if (*(int *)(*(int *)(param_1 + 8) + 4) != 0) {
    stage_getScoreData(&param_2);
    scoreEngine_setPropertyPoint(*(int *)(extraout_EDX + 0x20),param_2,(ushort)param_3);
  }
  return 0;
}



// ============================================================
// Function: stage_getScoreChannelName (FUN_6805DD00)
// Address: 6805dd00
// Size: 29 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getScoreChannelName(undefined4 param_1,int param_2)
{
  stage_getScoreData(&param_2);
  Ordinal_1933(param_2 + -1,&param_2);
  return 0;
}



// ============================================================
// Function: stage_getScoreChannelScript (FUN_6805DD20)
// Address: 6805dd20
// Size: 25 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getScoreChannelScript(undefined4 param_1,int param_2)
{
  stage_getScoreData(&param_2);
  Ordinal_1932(param_2 + -1);
  return 0;
}



// ============================================================
// Function: stage_setScoreChannelPosition (FUN_6805DD40)
// Address: 6805dd40
// Size: 37 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setScoreChannelPosition(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  Ordinal_1470(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x28),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: stage_loadScoreString (FUN_6805DD70)
// Address: 6805dd70
// Size: 71 bytes
// Params: char * param_1, undefined4 param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_loadScoreString(char *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int local_c [2];
  
  iVar1 = props_loadStringValue(*param_3,param_1,local_c);
  if (iVar1 == 0) {
    iVar1 = props_dispatchMethod(*param_3,(uint *)param_3[1],local_c);
    props_releaseAndClear(*param_3,local_c);
  }
  return iVar1;
}



// ============================================================
// Function: stage_enumerateScoreHandlers (FUN_6805DDC0)
// Address: 6805ddc0
// Size: 134 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_enumerateScoreHandlers(int param_1)

{
  int iVar1;
  int local_18;
  int *local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  props_clearValue(param_1,&local_10);
  iVar1 = Ordinal_2200(0,&local_8);
  if (iVar1 != 0) {
    iVar1 = props_getContextRef(param_1,&local_10);
    if (iVar1 == 0) {
      local_14 = &local_10;
      local_18 = param_1;
      iVar1 = Ordinal_1166(local_8,&local_18,stage_loadScoreString,0xffffffff,0xfffffffe,0);
      if (iVar1 == 0) goto LAB_6805de2d;
    }
  }
  if (local_10 != 0) {
    props_releaseAndClear(param_1,&local_10);
  }
LAB_6805de2d:
  if (local_8 != 0) {
    Ordinal_1163(&local_8);
  }
  return local_c;
}



// ============================================================
// Function: stage_getScoreFileName (FUN_6805DE50)
// Address: 6805de50
// Size: 142 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getScoreFileName(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  int local_10c;
  undefined1 local_108 [256];
  uint local_8;
  
  local_10c = 0;
  iVar1 = Ordinal_2200(0,&local_10c);
  if (iVar1 != 0) {
    uVar2 = Ordinal_2202(0);
    iVar1 = Ordinal_1155(local_10c,uVar2,local_108);
    if (iVar1 != 0) {
      Ordinal_1233(param_2,local_108);
    }
  }
  if (local_10c != 0) {
    Ordinal_1163(&local_10c);
  }
  return 0;
}



// ============================================================
// Function: stage_matchScoreHandler (FUN_6805DEE0)
// Address: 6805dee0
// Size: 42 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_matchScoreHandler(undefined4 param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  
  sVar1 = Ordinal_1208(param_3,param_1);
  if (sVar1 == 0) {
    return param_2 + 1;
  }
  return 0;
}



