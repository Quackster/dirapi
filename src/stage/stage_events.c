// Module: stage
// Topic: Event queue and behavior dispatch
// Address range: 0x6805F1C0 - 0x6805F8B0
// Functions (13):
//   stage_enqueueEvent (FUN_6805F1C0)
//   stage_dispatchSpriteBehaviors (FUN_6805f270)
//   stage_handleEvent (FUN_6805F300)
//   stage_forEachEvent (FUN_6805F390)
//   stage_isEventQueueEmpty (FUN_6805F420)
//   stage_removeEventsByChannel (FUN_6805F450)
//   stage_releaseSpriteCastObjects (FUN_6805F4C0)
//   Ordinal_890 (FUN_6805F5D0)
//   stage_clearSpriteEventProps (FUN_6805F790)
//   stage_collectSpriteProperties (FUN_6805F830)
//   stage_collectPropertiesAtFrame (FUN_6805F850)
//   stage_processEventData (FUN_6805F890)
//   Ordinal_930 (FUN_6805F8B0)

// ============================================================
// Function: stage_enqueueEvent (FUN_6805f1c0)
// Address: 6805f1c0
// Size: 165 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_enqueueEvent(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar2 = param_1;
  iVar1 = *param_2;
  iVar4 = *param_1;
  uVar3 = 0;
  if ((((((iVar4 == 10) || (iVar4 == 0xb)) || (iVar4 == 2)) || ((iVar4 == 1 || (iVar4 == 0x18)))) ||
      ((iVar4 == 9 || ((iVar4 == 3 || (iVar4 == 0xd)))))) && (iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x6c) == 0) {
      uVar3 = Ordinal_1150(10,10,0x2c);
      *(undefined4 *)(iVar1 + 0x6c) = uVar3;
    }
    param_1 = (int *)Ordinal_1111(0x2c,0);
    iVar4 = Ordinal_1114(param_1);
    Ordinal_1128(iVar4,piVar2,0x28);
    Ordinal_1128(iVar4 + 0x28,&param_2,4);
    Ordinal_1152(*(undefined4 *)(iVar1 + 0x6c),iVar4);
    Ordinal_1115(param_1);
    Ordinal_1113(&param_1);
    uVar3 = 1;
  }
  return uVar3;
}



// ============================================================
// Function: stage_dispatchSpriteBehaviors (FUN_6805f270)
// Address: 6805f270
// Size: 141 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_dispatchSpriteBehaviors(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  bVar2 = false;
  if ((param_1 != 0) && (puVar1 = (undefined4 *)(param_1 + 0x6c), *(int *)(param_1 + 0x6c) != 0)) {
    param_1 = Ordinal_1111(0x2c,1);
    iVar3 = Ordinal_1114(param_1);
    iVar4 = Ordinal_1155(*puVar1,0,iVar3);
    if (iVar4 == 0) {
      Ordinal_1163(puVar1);
      *puVar1 = 0;
    }
    else {
      Ordinal_1128(param_2,iVar3,0x28);
      Ordinal_1128(param_3,iVar3 + 0x28,4);
      Ordinal_1160(*puVar1,0);
    }
    bVar2 = iVar4 != 0;
    Ordinal_1115(param_1);
    Ordinal_1113(&param_1);
  }
  return bVar2;
}



// ============================================================
// Function: stage_handleEvent (FUN_6805f300)
// Address: 6805f300
// Size: 133 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_handleEvent(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
    uVar1 = Ordinal_1157(*(int *)(param_1 + 0x6c));
    uVar2 = Ordinal_1154(*(undefined4 *)(param_1 + 0x6c));
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        piVar3 = (int *)Ordinal_1156(*(undefined4 *)(param_1 + 0x6c),uVar1,uVar4);
        if ((piVar3 != (int *)0x0) && ((param_2 == -1 || (*piVar3 == param_2)))) {
          Ordinal_1160(*(undefined4 *)(param_1 + 0x6c),uVar4);
          local_8 = 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    Ordinal_1158(*(undefined4 *)(param_1 + 0x6c),uVar1);
    return local_8;
  }
  return 0;
}



// ============================================================
// Function: stage_forEachEvent (FUN_6805f390)
// Address: 6805f390
// Size: 134 bytes
// Params: int param_1, int param_2, undefined * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_forEachEvent(int param_1,int param_2,undefined *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x6c) == 0)) {
    return 0;
  }
  uVar1 = Ordinal_1157(*(int *)(param_1 + 0x6c));
  uVar2 = Ordinal_1154(*(undefined4 *)(param_1 + 0x6c));
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      piVar3 = (int *)Ordinal_1156(*(undefined4 *)(param_1 + 0x6c),uVar1,uVar4);
      if ((piVar3 != (int *)0x0) && ((param_2 == -1 || (*piVar3 == param_2)))) {
        local_8 = (*(code *)param_3)(DAT_681956e0,piVar3);
        if (local_8 != 0) break;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  Ordinal_1158(*(undefined4 *)(param_1 + 0x6c),uVar1);
  return local_8;
}



// ============================================================
// Function: stage_isEventQueueEmpty (FUN_6805f420)
// Address: 6805f420
// Size: 37 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_isEventQueueEmpty(int param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = '\x01';
  if ((param_1 != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
    iVar2 = Ordinal_1154(*(int *)(param_1 + 0x6c));
    cVar1 = '\x01' - (iVar2 != 0);
  }
  return (bool)cVar1;
}



// ============================================================
// Function: stage_removeEventsByChannel (FUN_6805f450)
// Address: 6805f450
// Size: 100 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_removeEventsByChannel(int param_1,int param_2)
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
    uVar1 = Ordinal_1157(*(int *)(param_1 + 0x6c));
    uVar2 = Ordinal_1154(*(undefined4 *)(param_1 + 0x6c));
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        iVar3 = Ordinal_1156(*(undefined4 *)(param_1 + 0x6c),uVar1,uVar4);
        if (param_2 == *(int *)(iVar3 + 4)) {
          Ordinal_1160(*(undefined4 *)(param_1 + 0x6c),uVar4);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    Ordinal_1158(*(undefined4 *)(param_1 + 0x6c),uVar1);
  }
  return 0;
}



// ============================================================
// Function: stage_releaseSpriteCastObjects (FUN_6805f4c0)
// Address: 6805f4c0
// Size: 271 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_releaseSpriteCastObjects(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  short local_6c [4];
  undefined4 local_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int *local_50;
  int local_4c;
  int local_48 [16];
  uint local_8;
  
  local_58 = *(undefined4 *)(unaff_ESI + 0xc);
  iVar1 = Ordinal_165(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),&local_64);
  Ordinal_377(*(undefined4 *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),&local_5c,&local_54);
  local_50 = (int *)Ordinal_482(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28));
  local_4c = local_5c;
  if (local_5c <= local_54) {
    puVar3 = (undefined4 *)(local_5c * 0x34 + iVar1);
    do {
      Ordinal_374(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),local_4c,5,
                  (double *)local_48);
      if (local_48[0] != 0) {
        local_60 = Ordinal_430(local_50,local_48[0]);
        iVar1 = 0;
        if (0 < local_60) {
          do {
            Ordinal_431(local_50,local_48[0],iVar1,local_6c);
            uVar2 = Ordinal_362(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),
                                (undefined4 *)local_6c);
            if ((((short)param_1 == (short)uVar2) && ((*(unsigned short *)((char *)&param_1 + 2)) == (short)((uint)uVar2 >> 0x10))
                ) && ((int *)*puVar3 != (int *)0x0)) {
              cast_releaseObject(local_58,(int *)*puVar3);
              *puVar3 = 0;
              puVar3[3] = 0;
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 < local_60);
        }
      }
      local_4c = local_4c + 1;
      puVar3 = puVar3 + 0xd;
    } while (local_4c <= local_54);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_890
// Address: 6805f5d0
// Size: 448 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_890(int param_1,undefined4 param_2)
{
  void *pvVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  int *local_38 [6];
  int *local_20 [6];
  uint local_8;
  
                    /* 0x5f5d0  890   */
  pvVar1 = *(void **)(param_1 + 0xc);
  piVar6 = (int *)0x0;
  bVar2 = false;
  bVar7 = false;
  Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x25,(uint *)local_38);
  cast_teardownHandler((uint)pvVar1,local_38[0]);
  local_20[0] = (int *)0x0;
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x25,(uint *)local_20);
  Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x26,(uint *)local_38);
  piVar3 = local_38[0];
  if (local_38[0] != (int *)0x0) {
    iVar5 = Ordinal_1116(local_38[0]);
    if (0 < iVar5) {
      bVar2 = true;
      /* FIXUP(C2224: left of '._2_2_' must have struct/union type): local_38[0] = (int *)CONCAT22(local_38[0]._2_2_,(short)param_2); */
      Ordinal_294(*(int *)(param_1 + 0x20),0,param_2,0xc,(uint *)local_38);
      piVar4 = local_38[0];
      Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x21,(uint *)local_38);
      bVar7 = local_38[0] == (int *)0x1;
      piVar6 = local_38[0];
      if (local_38[0] == (int *)0x1) {
        piVar6 = (int *)0x4;
      }
      Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x22,(uint *)local_38);
      if (local_38[0] == (int *)0x1) {
        piVar6 = (int *)((uint)piVar6 | 0x200);
      }
      piVar6 = (int *)cast_invokeHandlerEx(pvVar1,(int)piVar4,piVar3,(uint)piVar6,
                                   (int)(short)param_2 << 0x10 | (int)(*(unsigned short *)((char *)&param_2 + 2)));
    }
  }
  local_20[0] = piVar6;
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x25,(uint *)local_20);
  local_20[0] = (int *)cast_getSlotCount(pvVar1,piVar6);
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x24,(uint *)local_20);
  if ((piVar6 != (int *)0x0) || (local_20[0] = (int *)0x1, !bVar2)) {
    local_20[0] = (int *)0x0;
  }
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x28,(uint *)local_20);
  if (piVar3 != (int *)0x0) {
    cast_freeHandle(piVar3);
  }
  if (bVar7) {
    stage_releaseSpriteCastObjects(param_2);
  }
  return 0;
}



// ============================================================
// Function: stage_clearSpriteEventProps (FUN_6805f790)
// Address: 6805f790
// Size: 155 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_clearSpriteEventProps(int param_1,undefined4 param_2)
{
  uint uVar1;
  int *local_38 [6];
  uint local_20 [6];
  uint local_8;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x25,(uint *)local_38);
  cast_teardownHandler(uVar1,local_38[0]);
  local_20[0] = 0;
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x25,local_20);
  local_20[0] = 0;
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x24,local_20);
  local_20[0] = 0;
  Ordinal_293(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x28),param_2,0x28,local_20);
  return 0;
}



// ============================================================
// Function: stage_collectSpriteProperties (FUN_6805f830)
// Address: 6805f830
// Size: 23 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_collectSpriteProperties(int param_1,undefined4 param_2)
{
  props_collectProperties(*(int *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: stage_collectPropertiesAtFrame (FUN_6805f850)
// Address: 6805f850
// Size: 58 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_collectPropertiesAtFrame(int param_1,undefined4 param_2,uint param_3)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x148);
  *(uint *)(param_1 + 0x148) = ((int)param_3 < 0) - 1 & param_3;
  props_collectProperties(*(int *)(param_1 + 0xc),param_2);
  *(undefined4 *)(param_1 + 0x148) = uVar1;
  return 0;
}



// ============================================================
// Function: stage_processEventData (FUN_6805f890)
// Address: 6805f890
// Size: 23 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_processEventData(int param_1,int *param_2)
{
  cast_extractProplistString(*(int *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_930
// Address: 6805f8b0
// Size: 29 bytes
// Params: int param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_930(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0x5f8b0  930   */
  bVar1 = cast_hasChildren(*(undefined4 *)(param_1 + 0xc),param_2);
  return CONCAT31(extraout_var,bVar1) != 0;
}



