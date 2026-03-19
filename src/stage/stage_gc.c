// Module: stage
// Topic: Garbage collection
// Address range: 0x6805AD70 - 0x6805B390
// Functions (7):
//   stage_collectGcStats (FUN_6805AD70)
//   stage_markStackFrames (FUN_6805AF40)
//   stage_sweepUnreachable (FUN_6805B050)
//   stage_migrateReferences (FUN_6805B180)
//   stage_buildGcReport (FUN_6805B210)
//   stage_handleGcCommand (FUN_6805B2A0)
//   stage_createGcObject (FUN_6805B390)

// ============================================================
// Function: stage_collectGcStats (FUN_6805ad70)
// Address: 6805ad70
// Size: 452 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_collectGcStats(int param_1)
{
  int local_2c;
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_ESI;
  int iVar4;
  int iVar5;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  iVar2 = **(int **)(**(int **)(unaff_EBX + 8) + 0x4f4);
  if (0 < *(int *)(iVar2 + 0x10)) {
    local_8 = 0;
    do {
      piVar1 = *(int **)(local_8 + 0x2c + iVar2);
      if (piVar1 != (int *)0x0) {
        *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + 1;
        *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + *(int *)(*piVar1 + 0x30);
        iVar2 = *piVar1;
        iVar3 = 0;
        if (0 < *(int *)(iVar2 + 0x10)) {
          iVar4 = 0;
          do {
            if (*(int *)(iVar4 + 0xa8 + iVar2) != 0) {
              *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x20) + 1;
            }
            iVar2 = *piVar1;
            iVar3 = iVar3 + 1;
            iVar4 = iVar4 + 0x10;
          } while (iVar3 < *(int *)(iVar2 + 0x10));
        }
      }
      local_8 = local_8 + 0x18;
      local_c = (int *)((int)local_c + 1);
      iVar2 = **(int **)(**(int **)(unaff_EBX + 8) + 0x4f4);
    } while ((int)local_c < *(int *)(iVar2 + 0x10));
  }
  iVar2 = *(int *)(**(int **)(unaff_EBX + 8) + 0x56c);
  if (*(int *)(iVar2 + 4) != 0) {
    iVar3 = *(int *)(unaff_ESI + 0x10);
    iVar4 = *(int *)(unaff_ESI + 4);
    iVar5 = *(int *)(unaff_ESI + 0x14);
    do {
      iVar3 = iVar3 + *(int *)(iVar2 + 0xfc);
      iVar5 = iVar5 + 1;
      *(int *)(unaff_ESI + 0x10) = iVar3;
      iVar4 = iVar4 + *(int *)(iVar2 + 0xf8);
      *(int *)(unaff_ESI + 0x14) = iVar5;
      *(int *)(unaff_ESI + 4) = iVar4;
      iVar2 = *(int *)(iVar2 + 4);
    } while (*(int *)(iVar2 + 4) != 0);
  }
  if (*(int *)(param_1 + 4) != 0) {
    props_formatValue(unaff_EBX,(byte *)"\n\nRoot Objects: \n");
  }
  piVar1 = *(int **)(**(int **)(**(int **)(unaff_EBX + 8) + 0x558) + 0xc);
  iVar2 = *(int *)(*piVar1 + 0xc);
  while (iVar2 != 0) {
    if (*(int *)(param_1 + 4) != 0) {
      local_10 = 3;
      local_c = piVar1;
      local_c = (int *)score_checkType(unaff_EBX,&local_10);
      local_10 = 8;
      Ordinal_1116(piVar1);
      props_formatValue(unaff_EBX,(byte *)"%lx type=%v refCount=%ld size=%ld\n");
    }
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
    piVar1 = *(int **)(*piVar1 + 0xc);
    iVar2 = *(int *)(*piVar1 + 0xc);
  }
  if (*(int *)(param_1 + 4) != 0) {
    props_formatValue(unaff_EBX,(byte *)"\nReference Objects: \n");
  }
  piVar1 = *(int **)(**(int **)(**(int **)(unaff_EBX + 8) + 0x560) + 0xc);
  iVar2 = *(int *)(*piVar1 + 0xc);
  while (iVar2 != 0) {
    if (*(int *)(param_1 + 4) != 0) {
      local_10 = 3;
      local_c = piVar1;
      local_c = (int *)score_checkType(unaff_EBX,&local_10);
      local_10 = 8;
      Ordinal_1116(piVar1);
      props_formatValue(unaff_EBX,(byte *)"%lx type=%v refCount=%ld size=%ld\n");
    }
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 1;
    piVar1 = *(int **)(*piVar1 + 0xc);
    iVar2 = *(int *)(*piVar1 + 0xc);
  }
  return 0;
}



// ============================================================
// Function: stage_markStackFrames (FUN_6805af40)
// Address: 6805af40
// Size: 264 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_markStackFrames(void)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EDI + 0x1c) == 3) &&
     ((((int *)**(int **)(unaff_EDI + 0x20))[1] & 0x80000000U) == 0)) {
    (**(code **)(*(int *)**(int **)(unaff_EDI + 0x20) + 0x34))();
  }
  piVar5 = (int *)(unaff_EDI + 0x40);
  iVar6 = *(int *)(unaff_EDI + 0x18) + -8;
  iVar1 = *(int *)(unaff_EDI + 0x40);
  while (-1 < iVar1) {
    iVar2 = piVar5[1];
    piVar3 = (int *)piVar5[8];
    if (((int *)piVar5[4] != (int *)0x0) &&
       (piVar5 = *(int **)piVar5[4], (piVar5[1] & 0x80000000U) == 0)) {
      (**(code **)(*piVar5 + 0x34))();
    }
    if ((piVar3 != (int *)0x0) && (piVar3 = (int *)*piVar3, (piVar3[1] & 0x80000000U) == 0)) {
      (**(code **)(*piVar3 + 0x34))();
    }
    for (; iVar4 = iVar1, iVar1 + 0x34 <= iVar6; iVar6 = iVar6 + -8) {
      if ((*(int *)(**(int **)(unaff_EDI + 0x10) + iVar6) == 3) &&
         (piVar5 = (int *)**(int **)(**(int **)(unaff_EDI + 0x10) + 4 + iVar6),
         (piVar5[1] & 0x80000000U) == 0)) {
        (**(code **)(*piVar5 + 0x34))();
      }
    }
    while (iVar6 = iVar4 + -8, iVar2 <= iVar6) {
      iVar4 = iVar6;
      if ((*(int *)(**(int **)(unaff_EDI + 0x10) + iVar6) == 3) &&
         (piVar5 = (int *)**(int **)(**(int **)(unaff_EDI + 0x10) + 4 + iVar6),
         (piVar5[1] & 0x80000000U) == 0)) {
        (**(code **)(*piVar5 + 0x34))();
      }
    }
    piVar5 = (int *)(**(int **)(unaff_EDI + 0x10) + iVar1);
    iVar1 = *piVar5;
  }
  return 0;
}



// ============================================================
// Function: stage_sweepUnreachable (FUN_6805b050)
// Address: 6805b050
// Size: 298 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_sweepUnreachable(int *param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  
  iVar1 = **(int **)(unaff_EBX + 8);
  piVar2 = *(int **)(**(int **)(iVar1 + 0x558) + 0xc);
  piVar3 = (int *)*piVar2;
  iVar4 = piVar3[3];
  while (iVar4 != 0) {
    if ((piVar3[1] & 0x80000000U) == 0) {
      (**(code **)(*piVar3 + 0x34))();
    }
    piVar2 = *(int **)(*piVar2 + 0xc);
    piVar3 = (int *)*piVar2;
    iVar4 = piVar3[3];
  }
  iVar4 = *(int *)(iVar1 + 0x56c);
  iVar5 = *(int *)(iVar4 + 4);
  while (iVar5 != 0) {
    stage_markStackFrames();
    iVar4 = *(int *)(iVar4 + 4);
    iVar5 = *(int *)(iVar4 + 4);
  }
  piVar2 = *(int **)(**(int **)(iVar1 + 0x560) + 0xc);
  piVar3 = (int *)*piVar2;
  iVar4 = piVar3[3];
  while (iVar4 != 0) {
    if ((piVar3[1] & 0x80000000U) == 0) {
      (**(code **)(*piVar3 + 0x38))();
    }
    piVar2 = *(int **)(*piVar2 + 0xc);
    piVar3 = (int *)*piVar2;
    iVar4 = piVar3[3];
  }
  piVar2 = *(int **)(**(int **)(iVar1 + 0x560) + 0xc);
  iVar4 = *(int *)(*piVar2 + 0xc);
  while (iVar4 != 0) {
    iVar4 = *piVar2;
    piVar3 = *(int **)(iVar4 + 0xc);
    if ((int)*(uint *)(iVar4 + 4) < 0) {
      *(uint *)(iVar4 + 4) = *(uint *)(iVar4 + 4) & 0x7fffffff;
    }
    else {
      *(int **)(**(int **)(iVar4 + 8) + 0xc) = piVar3;
      *(undefined4 *)(**(int **)(*piVar2 + 0xc) + 8) = *(undefined4 *)(*piVar2 + 8);
      cast_freeHandle(piVar2);
      *(int *)(unaff_EBX + 0xf8) = *(int *)(unaff_EBX + 0xf8) + -1;
      *param_1 = *param_1 + 1;
    }
    piVar2 = piVar3;
    iVar4 = *(int *)(*piVar3 + 0xc);
  }
  piVar2 = *(int **)(**(int **)(iVar1 + 0x558) + 0xc);
  iVar1 = *piVar2;
  iVar4 = *(int *)(iVar1 + 0xc);
  while (iVar4 != 0) {
    *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0x7fffffff;
    piVar2 = *(int **)(*piVar2 + 0xc);
    iVar1 = *piVar2;
    iVar4 = *(int *)(iVar1 + 0xc);
  }
  return 0;
}



// ============================================================
// Function: stage_migrateReferences (FUN_6805b180)
// Address: 6805b180
// Size: 130 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_migrateReferences(void)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(**(int **)(**(int **)(unaff_ESI + 8) + 0x560) + 0xc);
  iVar2 = *(int *)(*piVar1 + 0xc);
  while (iVar2 != 0) {
    piVar3 = *(int **)(*piVar1 + 0xc);
    *(int **)(**(int **)(*piVar1 + 8) + 0xc) = piVar3;
    *(undefined4 *)(**(int **)(*piVar1 + 0xc) + 8) = *(undefined4 *)(*piVar1 + 8);
    iVar2 = **(int **)(unaff_ESI + 8);
    *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(**(int **)(iVar2 + 0x55c) + 8);
    *(undefined4 *)(*piVar1 + 0xc) = *(undefined4 *)(iVar2 + 0x55c);
    *(int **)(**(int **)(**(int **)(iVar2 + 0x55c) + 8) + 0xc) = piVar1;
    *(int **)(**(int **)(iVar2 + 0x55c) + 8) = piVar1;
    piVar1 = piVar3;
    iVar2 = *(int *)(*piVar3 + 0xc);
  }
  return 0;
}



// ============================================================
// Function: stage_buildGcReport (FUN_6805b210)
// Address: 6805b210
// Size: 115 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_buildGcReport(undefined4 *param_1,undefined4 *param_2)
{
  int unaff_EBX;
  undefined **ppuVar1;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)score_deleteProplistEntry(unaff_EBX,9);
  ppuVar1 = &PTR_s_freed_6818e0b8;
  do {
    local_18 = 8;
    local_14 = props_resolvePropertyId(unaff_EBX,*ppuVar1);
    local_c = *param_1;
    local_10 = 4;
    score_updateProplistRange(unaff_EBX,local_8,&local_18,&local_10);
    ppuVar1 = ppuVar1 + 1;
    param_1 = param_1 + 1;
  } while ((int)ppuVar1 < 0x6818e0dc);
  *param_2 = 3;
  param_2[1] = local_8;
  return 0;
}



// ============================================================
// Function: stage_handleGcCommand (FUN_6805b2a0)
// Address: 6805b2a0
// Size: 225 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_handleGcCommand(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  uint local_30;
  int local_2c [10];
  
  local_2c[1] = 0;
  local_2c[2] = 0;
  local_2c[3] = 0;
  local_2c[4] = 0;
  local_2c[5] = 0;
  local_2c[6] = 0;
  local_2c[7] = 0;
  local_2c[8] = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c[0] = 0;
  if (param_3 == 0x135) {
    stage_migrateReferences();
    puVar2 = (undefined4 *)0x0;
  }
  else if (param_3 == 0x136) {
    local_34 = 1;
    iVar1 = props_getTypedProperty(param_1,2,4,&local_30);
    if (iVar1 == 0) goto LAB_6805b36a;
    stage_collectGcStats((int)&local_34);
    stage_buildGcReport(local_2c,&local_3c);
    puVar2 = &local_3c;
  }
  else {
    if (param_3 != 0x137) {
      return 0;
    }
    stage_sweepUnreachable(local_2c);
    puVar2 = &local_3c;
    local_3c = 4;
    local_38 = local_2c[0];
  }
  props_popArgs(param_1,puVar2);
LAB_6805b36a:
  return 0;
}



// ============================================================
// Function: stage_createGcObject (FUN_6805b390)
// Address: 6805b390
// Size: 74 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_createGcObject(int param_1)
{
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)cast_allocHandle(8,0);
  if (local_8 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    *(undefined ***)*local_8 = &PTR_LAB_6818e0e0;
    *(undefined4 *)(*local_8 + 4) = 1;
    local_c = 3;
    props_popArgs(param_1,&local_c);
  }
  return 0;
}



