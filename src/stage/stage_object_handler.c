// Module: stage
// Topic: Object handler registration and events
// Address range: 0x68058DA0 - 0x68059370
// Functions (12):
//   stage_resolveObjectVariable (FUN_68058DA0)
//   stage_initObjectAndRetain (FUN_68058DF0)
//   stage_assignObjectProp (FUN_68058E30)
//   stage_dispatchObjectEvent (FUN_68058EB0)
//   stage_createObjectWithProps (FUN_68059010)
//   stage_releaseObjectHandler (FUN_680590B0)
//   stage_allocObjectDispatch (FUN_68059130)
//   stage_freeObjectDispatch (FUN_68059150)
//   stage_findMatchingHandler (FUN_680591F0)
//   stage_registerHandler (FUN_68059280)
//   stage_stripComments (FUN_68059320)
//   stage_loadHandlerScript (FUN_68059370)

// ============================================================
// Function: stage_resolveObjectVariable (FUN_68058DA0)
// Address: 68058da0
// Size: 69 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolveObjectVariable(int param_1,int *param_2,uint param_3)
{
  uint uVar1;
  int *piVar2;

  uVar1 = props_lookupVariable(param_1,*(int **)(param_1 + 0x50),param_3);
  if (uVar1 == 0xffffffff) {
    piVar2 = *(int **)(*param_2 + 0x10);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
  }
  else {
    piVar2 = *(int **)(param_1 + 0x50);
    param_2 = *(int **)(param_1 + 0x60);
  }
  stage_getObjectProperty(param_2,param_1,piVar2,param_3);
  return 0;
}



// ============================================================
// Function: stage_initObjectAndRetain (FUN_68058DF0)
// Address: 68058df0
// Size: 57 bytes
// Params: int param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_initObjectAndRetain(int param_1,int *param_2)

{
  int *piVar1;

  piVar1 = stage_buildObjectProps(param_1);
  if (piVar1 == (int *)0x0) {
    props_setError(param_1,2);
    return (int *)0x0;
  }
  props_retainObject(param_1,param_2);
  return piVar1;
}



// ============================================================
// Function: stage_assignObjectProp (FUN_68058E30)
// Address: 68058e30
// Size: 120 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_assignObjectProp(uint param_1)
{
  int *in_EAX;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_ESI;
  undefined4 local_c;
  int *local_8;

  piVar1 = stage_initObjectAndRetain(unaff_ESI,in_EAX);
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)
             (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
             *(int *)(unaff_ESI + 0x18));
    local_c = *puVar2;
    local_8 = (int *)puVar2[1];
    *puVar2 = 3;
    puVar2[1] = piVar1;
    props_releaseValue(unaff_ESI,(byte)local_c,local_8);
    iVar3 = stage_processObjectProp(unaff_ESI,piVar1,param_1);
    if (iVar3 == 0) {
      local_c = 3;
      *(int *)(*piVar1 + 4) = *(int *)(*piVar1 + 4) + 1;
      local_8 = piVar1;
      props_popArgs(unaff_ESI,&local_c);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchObjectEvent (FUN_68058EB0)
// Address: 68058eb0
// Size: 175 bytes
// Params: uint param_1, int * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_dispatchObjectEvent(uint param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;

  switch(param_3) {
  case 0x82:
  case 0xfe:
    stage_assignObjectProp(param_3);
    return 1;
  case 0xe3:
    score_resolveType(param_1);
    return 1;
  case 0x11b:
    piVar1 = stage_initObjectAndRetain(param_1,param_2);
    if (piVar1 != (int *)0x0) {
      props_normalizeType(param_1,3,(int)piVar1);
    }
    return 1;
  }
  iVar2 = core_returnZeroStub();
  if (iVar2 != 0) {
    return 1;
  }
  props_lookupVariable(param_1,param_2,param_3);
  uVar3 = stage_getObjectProperty(*(int **)(*param_2 + 0x34),param_1,param_2,param_3);
  return uVar3;
}



// ============================================================
// Function: stage_createObjectWithProps (FUN_68059010)
// Address: 68059010
// Size: 156 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, int param_4, undefined4 * param_5
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_createObjectWithProps(int *param_1,int *param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;

  piVar1 = stage_initObjectAndRetain(*param_1,param_2);
  if (piVar1 != (int *)0x0) {
    *param_5 = 3;
    param_5[1] = piVar1;
    stage_createFactory((int)param_1,-1,param_5);
    iVar4 = param_4 / 2;
    piVar2 = param_1;
    while ((((0 < iVar4 && (piVar2 = (int *)stage_allocString(param_1,&local_14), piVar2 == (int *)0x0))
            && (piVar2 = (int *)stage_allocString(param_1,&local_c), piVar2 == (int *)0x0)) &&
           (puVar3 = score_lookupProperty(piVar1,local_10,1,(uint *)0x0), puVar3 != (uint *)0x0))) {
      *puVar3 = local_c;
      iVar4 = iVar4 + -1;
      puVar3[1] = local_8;
    }
    return piVar2;
  }
  return DAT_68195a8c;
}



// ============================================================
// Function: stage_releaseObjectHandler (FUN_680590B0)
// Address: 680590b0
// Size: 116 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_releaseObjectHandler(int param_1)
{
  int *this;

  props_releaseObject(param_1,*(int **)(**(int **)(param_1 + 8) + 0x510));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x510) = 0;
  props_releaseObject(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x514) = 0;
  score_freePropertyHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x4e8));
  this = *(int **)(param_1 + 8);
  *(undefined4 *)(*this + 0x4e8) = 0;
  stage_freeObjectDispatch(this,param_1);
  return 0;
}



// ============================================================
// Function: stage_allocObjectDispatch (FUN_68059130)
// Address: 68059130
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocObjectDispatch(int param_1)
{
  int *piVar1;

  piVar1 = stage_allocDispatchEntry(0x2c,0x20,0xc,10);
  *(int **)(param_1 + 0x50c) = piVar1;
  return 0;
}



// ============================================================
// Function: stage_freeObjectDispatch (FUN_68059150)
// Address: 68059150
// Size: 158 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall stage_freeObjectDispatch(void *this,int param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *local_8;

  iVar5 = param_1;
  if ((**(int **)(param_1 + 8) != 0) &&
     (piVar2 = *(int **)(**(int **)(param_1 + 8) + 0x50c), piVar2 != (int *)0x0)) {
    param_1 = *(int *)(*piVar2 + 0x10);
    local_8 = this;
    if (0 < param_1) {
      iVar6 = 0;
      do {
        iVar3 = **(int **)(**(int **)(iVar5 + 8) + 0x50c);
        uVar4 = *(undefined4 *)(iVar3 + 0x20 + iVar6);
        local_8 = *(void **)(iVar3 + 0x28 + iVar6);
        puVar1 = (undefined4 *)(iVar3 + 0x20 + iVar6);
        *puVar1 = 0;
        puVar1[2] = 0;
        props_releaseValue(iVar5,(byte)uVar4,(int *)puVar1[1]);
        Ordinal_1113(&local_8);
        iVar6 = iVar6 + 0xc;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    cast_freeHandle(*(undefined4 *)(**(int **)(iVar5 + 8) + 0x50c));
    *(undefined4 *)(**(int **)(iVar5 + 8) + 0x50c) = 0;
  }
  return 0;
}



// ============================================================
// Function: stage_findMatchingHandler (FUN_680591F0)
// Address: 680591f0
// Size: 142 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_findMatchingHandler(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  local_14 = *in_EAX;
  local_10 = in_EAX[1];
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x50c);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(*piVar1 + 0x10);
    iVar5 = 0;
    if (0 < iVar2) {
      iVar6 = 0;
      do {
        iVar3 = **(int **)(**(int **)(param_1 + 8) + 0x50c);
        piVar1 = (int *)(iVar3 + 0x20 + iVar6);
        if (*(int *)(iVar3 + 0x20 + iVar6) != 0) {
          local_c = *piVar1;
          local_8 = piVar1[1];
          uVar4 = props_compareStrings(param_1,&local_14,&local_c,0,0);
          if (uVar4 != 0) {
            return iVar5;
          }
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0xc;
      } while (iVar5 < iVar2);
    }
  }
  return -1;
}



// ============================================================
// Function: stage_registerHandler (FUN_68059280)
// Address: 68059280
// Size: 146 bytes
// Params: void * this, int param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall stage_registerHandler(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_EBX;
  int iVar3;
  int local_c;
  int local_8;

  props_getValuePair(unaff_EBX,this,&local_c);
  iVar3 = **(int **)(**(int **)(unaff_EBX + 8) + 0x50c);
  iVar1 = *(int *)(iVar3 + 0x10);
  piVar2 = (int *)(iVar3 + 0x20);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if (*piVar2 == 0) goto LAB_680592f7;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 3;
    } while (iVar3 < iVar1);
  }
  stage_emitStoreVar(*(int **)(**(int **)(unaff_EBX + 8) + 0x50c),iVar1);
  iVar3 = props_checkReentrant(unaff_EBX);
  if (iVar3 == 0) {
    return -1;
  }
  piVar2 = (int *)(**(int **)(**(int **)(unaff_EBX + 8) + 0x50c) + 0x20 + iVar1 * 0xc);
  iVar3 = iVar1;
LAB_680592f7:
  *piVar2 = local_c;
  piVar2[1] = local_8;
  piVar2[2] = param_1;
  return iVar3;
}



// ============================================================
// Function: stage_stripComments (FUN_68059320)
// Address: 68059320
// Size: 65 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_stripComments(void)
{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;

  bVar2 = false;
  pcVar3 = (char *)Ordinal_1114();
  cVar1 = *pcVar3;
  pcVar4 = pcVar3;
  do {
    if (cVar1 == '\0') {
      *pcVar4 = '\0';
      Ordinal_1115();
      return 0;
    }
    if (cVar1 == '\r') {
      if (pcVar3[1] == '/') {
        bVar2 = true;
      }
      else {
        bVar2 = false;
LAB_6805934b:
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
      }
    }
    else if (!bVar2) goto LAB_6805934b;
    cVar1 = pcVar3[1];
    pcVar3 = pcVar3 + 1;
  } while( true );
}



// ============================================================
// Function: stage_loadHandlerScript (FUN_68059370)
// Address: 68059370
// Size: 179 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_loadHandlerScript(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *unaff_EBX;
  int *unaff_ESI;
  undefined4 local_c;
  undefined4 *local_8;

  local_8 = (undefined4 *)0x0;
  iVar1 = (**(code **)(*unaff_ESI + 0x28))();
  if (iVar1 == 0) {
    local_8 = (undefined4 *)Ordinal_1111(local_c,0);
    if (local_8 == (undefined4 *)0x0) goto LAB_6805941a;
    Ordinal_1114(local_8);
    iVar2 = (**(code **)(*unaff_ESI + 0x14))();
    Ordinal_1115(local_8);
    iVar1 = 0;
    if (iVar2 != 0) {
      Ordinal_1113(&local_8);
      *unaff_EBX = local_8;
      return iVar2;
    }
  }
  iVar2 = Ordinal_1116(local_8);
  pcVar3 = (char *)*local_8;
  while (iVar2 = iVar2 + -1, 0 < iVar2) {
    if ((*pcVar3 == '\0') || (*pcVar3 == '\n')) {
      *pcVar3 = '\r';
    }
    pcVar3 = pcVar3 + 1;
  }
  *pcVar3 = '\0';
LAB_6805941a:
  *unaff_EBX = local_8;
  return iVar1;
}



