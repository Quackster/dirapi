// Module: cast
// Topic: API wrapper functions and final dispatch
// Address range: 0x6802FD60 - 0x6803DCDF
// Functions (11):
//   cast_resetProplist
//   cast_storeReturnType
//   cast_getProplistValue
//   cast_extractProplistString
//   cast_invokeNamedHandler
//   cast_fireTimerEvents
//   cast_wrapApiCall
//   cast_removeInactiveTimers
//   cast_dispatchDebugEvent
//   thunk_FUN_680285c0
//   cast_getGlobalData

// ============================================================
// Function: cast_resetProplist (FUN_6802fd60)
// Address: 6802fd60
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resetProplist(int param_1)
{
  *(undefined4 *)(param_1 + 0x7c) = 0;
  score_dispatchProplist(param_1);
  return 0;
}



// ============================================================
// Function: cast_storeReturnType (FUN_6802fd80)
// Address: 6802fd80
// Size: 26 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_storeReturnType(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 3;
    param_3[1] = param_2;
  }
  return 0;
}



// ============================================================
// Function: cast_getProplistValue (FUN_6802fda0)
// Address: 6802fda0
// Size: 36 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_getProplistValue(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = score_getProplistValue(param_1,param_2);
  if (iVar1 != 0) {
    return param_2[1];
  }
  return 0;
}



// ============================================================
// Function: cast_extractProplistString (FUN_6802fdd0)
// Address: 6802fdd0
// Size: 9 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_extractProplistString(int param_1,int *param_2)
{
  score_extractProplistString(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_invokeNamedHandler (FUN_6802fde0)
// Address: 6802fde0
// Size: 293 bytes
// Params: void * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_invokeNamedHandler(void *param_1,undefined4 param_2)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int local_478;
  int local_474;
  int local_470;
  int local_46c;
  int *local_468;
  int local_464 [279];
  uint local_8;
  
  local_470 = *(int *)((int)param_1 + 0x3c);
  uVar2 = events_navigateToFrame((int)param_1,1);
  if ((int)uVar2 < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = (int)(short)((short)uVar2 + -1);
  }
  props_selectScript((int)param_1,iVar4);
  pcVar3 = (char *)Ordinal_1114(param_2);
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  props_hashSymbol(local_464,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  stage_compileHandlerScope(param_1,local_464,-1,0x8c4,0,0,&local_474);
  if (local_474 != 0) {
    props_executeHandler(param_1,*(int **)((int)param_1 + 0xe8),local_474,0,&local_478);
    local_46c = *(int *)((int)param_1 + 0xac);
    local_468 = *(int **)((int)param_1 + 0xb0);
    *(undefined4 *)((int)param_1 + 0xac) = 2;
    iVar4 = score_getProplistValue(param_1,&local_46c);
    if (iVar4 != 0) goto LAB_6802fed9;
    props_releaseValue(param_1,(byte)local_46c,local_468);
  }
  local_468 = (int *)0x0;
LAB_6802fed9:
  Ordinal_1115(param_2);
  if (-1 < local_470) {
    props_selectScript((int)param_1,local_470);
  }
  return 0;
}



// ============================================================
// Function: cast_fireTimerEvents (FUN_6802ff10)
// Address: 6802ff10
// Size: 9 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_fireTimerEvents(int param_1,int *param_2)
{
  score_fireTimerEvents(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_wrapApiCall (FUN_6802ff20)
// Address: 6802ff20
// Size: 9 bytes
// Params: undefined4 param_1, int * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_wrapApiCall(undefined4 param_1,int *param_2,uint param_3)
{
  score_processTimerProperties(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: cast_removeInactiveTimers (FUN_6802ff30)
// Address: 6802ff30
// Size: 9 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_removeInactiveTimers(undefined4 param_1,int *param_2)
{
  score_removeInactiveTimers(param_1,param_2);
  return 0;
}



// ============================================================
// Function: cast_dispatchDebugEvent (FUN_6802ff40)
// Address: 6802ff40
// Size: 746 bytes
// Params: int param_1, int param_2, int * param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchDebugEvent(int param_1,int param_2,int *param_3,int param_4,int param_5)
{
  int *piVar1;
  bool bVar2;
  ushort uVar3;
  undefined3 extraout_var;
  int iVar4;
  int *piVar5;
  undefined4 local_824;
  int local_820;
  int local_81c;
  int local_818;
  int local_814;
  int local_810;
  int local_80c;
  byte local_808;
  undefined1 local_807 [1023];
  undefined1 local_408 [1024];
  
  piVar1 = param_3;
  local_80c = 0;
  local_820 = 0;
  local_814 = param_4;
  if ((((param_5 < 0) || (7 < param_2)) || ((*(uint *)(*param_3 + 0x54) & 0x800) != 0)) ||
     (crt_executePlatformOp(param_1,param_3,(short)param_4,param_5,&local_80c,&local_820,&local_824,
                   &local_808), local_80c == 0)) goto LAB_68030218;
  bVar2 = cast_isContextValid(param_1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    if (local_808 == 0xff) {
      uVar3 = Ordinal_1201(local_807);
    }
    else {
      uVar3 = (ushort)local_808;
    }
    if (uVar3 == 0) goto LAB_68030218;
    events_shutdownMovie(param_1,local_408);
    local_810 = sprites_getEventRef(param_1);
    local_81c = *(int *)(*piVar1 + 0x20);
    local_818 = *(int *)(*piVar1 + 0x1c);
    iVar4 = Ordinal_1236(local_408,&DAT_68195a98);
    bVar2 = iVar4 == 0;
    if (bVar2) {
      props_formatValue(param_1,&DAT_6817c334);
      props_formatValue(param_1,(byte *)"Movie: %p ");
      Ordinal_1230(&DAT_68195a98,local_408);
    }
    if (local_810 != DAT_68195e98) {
      if (!bVar2) {
        props_formatValue(param_1,&DAT_6817c334);
      }
      bVar2 = true;
      props_formatValue(param_1,(byte *)"Frame: %d ");
      DAT_68195e98 = local_810;
    }
    if (((local_81c == DAT_68195e9c) && (local_818 == DAT_68195ea0)) && (local_814 == DAT_68195ea4))
    {
      if (bVar2) goto LAB_6803017e;
    }
    else {
      if (!bVar2) {
        props_formatValue(param_1,&DAT_6817c334);
      }
      events_getWindowFlags(param_1,piVar1,local_408);
      props_formatValue(param_1,(byte *)"Script: %p ");
      piVar5 = (int *)props_getContextSlot(param_1,piVar1,local_814);
      iVar4 = local_81c;
      props_storeTableEntry(param_1,local_81c,*piVar5,(int)local_408);
      props_formatValue(param_1,(byte *)"Handler: %p ");
      DAT_68195e9c = iVar4;
      DAT_68195ea0 = local_818;
      DAT_68195ea4 = local_814;
LAB_6803017e:
      props_formatValue(param_1,&DAT_6817c158);
    }
    if (*(int *)(param_1 + 0xe8) != 0) {
      iVar4 = Ordinal_1236(&local_808,&DAT_68195ea8);
      if (iVar4 == 0) {
        props_formatValue(param_1,(byte *)"--> %p\n");
        Ordinal_1230(&DAT_68195ea8,&local_808);
      }
      else {
        props_formatValue(param_1,&DAT_6817b944);
      }
    }
  }
  if (*(int *)(param_1 + 0xec) != 0) {
    sprites_getMovieRefByPath(param_1,piVar1,param_5,local_824,&param_2);
  }
  if (local_820 != 0) {
    cast_freeHandle(local_80c);
  }
LAB_68030218:
  return 0;
}



// ============================================================

int __fastcall thunk_FUN_680285c0(short *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined4 *unaff_ESI;
  
  if (*param_1 == -1) {
    iVar1 = cast_getFormatId(param_1[1]);
    props_storeObjectRef(extraout_EDX,iVar1,unaff_ESI);
    return 0;
  }
  cast_getFieldValue((undefined4 *)param_1,param_2);
  return 0;
}


// ============================================================

undefined4 cast_getGlobalData(void)

{
  return DAT_68195a80;
}


