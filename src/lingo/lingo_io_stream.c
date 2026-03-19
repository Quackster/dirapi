// Module: lingo
// Topic: Stream I/O operations (open, read, write, seek)
// Address range: 0x6809E5B0 - 0x6809EBF0
// Functions (21):
//   lingo_initStreamState
//   lingo_vtableCallHandler
//   lingo_getStreamState
//   lingo_vtableFlush
//   lingo_vtableGetValue
//   lingo_vtableSetValue
//   lingo_vtableGetCount2
//   lingo_vtableGetByIndex
//   lingo_vtableSetByIndex
//   lingo_vtableAppend
//   lingo_vtableGetNext
//   lingo_vtableDeleteByIndex
//   lingo_vtableInsert
//   lingo_vtableContains
//   lingo_vtableSort
//   lingo_vtableDelete
//   lingo_vtableClone
//   lingo_vtableMerge
//   lingo_vtableGetPropList
//   lingo_vtableToString
//   lingo_readStream


// ============================================================
// Function: lingo_initStreamState (FUN_6809e5b0)
// Address: 6809e5b0
// Size: 39 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_initStreamState(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return 0;
}



// ============================================================
// Function: lingo_vtableCallHandler (FUN_6809e5e0)
// Address: 6809e5e0
// Size: 180 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableCallHandler(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2;
  piVar3 = param_1;
  iVar1 = param_1[1];
  if (*(int *)(iVar1 + 0x24) != 0) {
    return -0x7ffbffaf;
  }
  piVar2 = *(int **)(iVar1 + 0x18);
  if (piVar2 != (int *)0x0) {
    if (param_2 == 0) {
      if ((*(int *)(iVar1 + 0x1c) != -1) &&
         (iVar4 = strings_seekToKeyEntry(piVar2,*(int *)(iVar1 + 0x1c)), iVar4 != 0)) {
        return -0x7ffbffad;
      }
      *(undefined4 *)(iVar1 + 0x24) = 1;
    }
    else {
      if (param_2 == 1) {
        return -0x7ffbffab;
      }
      if (param_2 == 2) {
        if ((*(int *)(iVar1 + 0x1c) != -1) &&
           (iVar4 = strings_beginWriteChunk(piVar2,*(int *)(iVar1 + 0x1c),*(int *)(iVar1 + 0x28)), iVar4 != 0))
        {
          return -0x7ffbffad;
        }
        *(undefined4 *)(iVar1 + 0x24) = 2;
      }
    }
    *(int *)(iVar1 + 0x20) = iVar5;
    *(undefined4 *)(iVar1 + 0x2c) = param_3;
    *(undefined4 *)(iVar1 + 0x30) = 0;
    iVar5 = (**(code **)(*piVar3 + 0x20))(piVar3,&param_1);
    if (iVar5 == 0) {
      *(int **)(iVar1 + 0x30) = param_1;
    }
    return iVar5;
  }
  return -0x7ffbffad;
}



// ============================================================
// Function: lingo_getStreamState (FUN_6809e6a0)
// Address: 6809e6a0
// Size: 97 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getStreamState(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 uVar3;
  
  piVar1 = *(int **)(unaff_ESI + 0x18);
  uVar3 = 0;
  if ((piVar1 == (int *)0x0) || (iVar2 = *(int *)(unaff_ESI + 0x24), iVar2 == 0)) {
    return 0x80040050;
  }
  if (iVar2 == 1) {
    if (*(int *)(unaff_ESI + 0x1c) == -1) goto LAB_6809e6ef;
    iVar2 = strings_getMediaStreamInfo(piVar1);
  }
  else {
    if ((iVar2 != 2) || (*(int *)(unaff_ESI + 0x1c) == -1)) goto LAB_6809e6ef;
    iVar2 = strings_endWriteChunk(piVar1);
    if (iVar2 == 0xd2) {
      *(undefined4 *)(unaff_ESI + 0x24) = 0;
      return 0x80040058;
    }
  }
  if (iVar2 != 0) {
    uVar3 = 0x80040053;
  }
LAB_6809e6ef:
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  return uVar3;
}



// ============================================================
// Function: lingo_vtableFlush (FUN_6809e710)
// Address: 6809e710
// Size: 20 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableFlush(void)
{
  lingo_getStreamState();
  return 0;
}



// ============================================================
// Function: lingo_vtableGetValue (FUN_6809e730)
// Address: 6809e730
// Size: 232 bytes
// Params: int * param_1, int param_2, uint param_3, uint * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableGetValue(int *param_1,int param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  piVar1 = param_1;
  iVar3 = param_1[1];
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  if ((*(int *)(iVar3 + 0x18) != 0) && (*(int *)(iVar3 + 0x24) != 0)) {
    iVar2 = (**(code **)(*param_1 + 0x20))(param_1,&local_8);
    if (iVar2 == 0) {
      if (*(int *)(iVar3 + 0x20) == 2) {
        return -0x7ffbffab;
      }
      iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,&param_1);
      if (iVar2 == 0) {
        if (((uint)((int)param_1 - (int)local_8) < param_3) &&
           ((param_4 == (uint *)0x0 || (param_3 = (int)param_1 - (int)local_8, param_1 <= local_8)))
           ) {
          return -0x7ffbffac;
        }
        iVar3 = strings_readMediaBytes(*(undefined4 **)(iVar3 + 0x18),param_2,(int *)&param_3);
        if (iVar3 == 0xce) {
          iVar2 = -0x7ffbffac;
          (**(code **)(*piVar1 + 0x24))(piVar1,param_1);
        }
        else if (iVar3 != 0) {
          iVar2 = -0x7ffbffad;
        }
        if (param_4 != (uint *)0x0) {
          *param_4 = param_3;
        }
      }
    }
    return iVar2;
  }
  return -0x7ffbffb0;
}



// ============================================================
// Function: lingo_vtableSetValue (FUN_6809e820)
// Address: 6809e820
// Size: 66 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableSetValue(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1;
  iVar2 = (**(code **)(*param_1 + 0x20))(param_1,&param_1);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_2,param_3,param_4);
    (**(code **)(*piVar1 + 0x24))(piVar1,param_1);
  }
  return iVar2;
}



// ============================================================
// Function: lingo_vtableGetCount2 (FUN_6809e870)
// Address: 6809e870
// Size: 139 bytes
// Params: int * param_1, undefined1 * param_2, uint param_3, uint * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableGetCount2(int *param_1,undefined1 *param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = param_1;
  iVar3 = param_1[1];
  if ((*(int *)(iVar3 + 0x18) != 0) && (*(int *)(iVar3 + 0x24) != 0)) {
    if (*(int *)(iVar3 + 0x20) != 0) {
      iVar3 = (**(code **)(*param_1 + 0x20))(param_1,&param_1);
      uVar2 = param_3;
      if (iVar3 == 0) {
        uVar4 = strings_writeMediaBytes(*(int **)(piVar1[1] + 0x18),param_2,param_3);
        if (uVar4 == 0xd2) {
          iVar3 = -0x7ffbffa8;
        }
        else if (uVar4 != 0) {
          iVar3 = -0x7ffbffad;
        }
        if (param_4 != (uint *)0x0) {
          *param_4 = ~-(uint)(iVar3 != 0) & uVar2;
        }
      }
      return iVar3;
    }
    return -0x7ffbffab;
  }
  return -0x7ffbffb0;
}



// ============================================================
// Function: lingo_vtableGetByIndex (FUN_6809e900)
// Address: 6809e900
// Size: 107 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableGetByIndex(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  piVar2 = *(int **)(iVar1 + 0x18);
  if ((piVar2 == (int *)0x0) || (iVar3 = *(int *)(iVar1 + 0x24), iVar3 == 0)) {
    return 0x80040050;
  }
  if (iVar3 == 1) {
    iVar3 = strings_getMediaInputPosition(piVar2);
    *param_2 = iVar3 - *(int *)(iVar1 + 0x30);
    return 0;
  }
  if (iVar3 == 2) {
    iVar3 = strings_getMediaPosition(piVar2);
    *param_2 = iVar3 - *(int *)(iVar1 + 0x30);
    return 0;
  }
  *param_2 = param_1 - *(int *)(iVar1 + 0x30);
  return 0;
}



// ============================================================
// Function: lingo_vtableSetByIndex (FUN_6809e970)
// Address: 6809e970
// Size: 89 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableSetByIndex(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((*(int *)(iVar3 + 0x18) == 0) || (iVar1 = *(int *)(iVar3 + 0x24), iVar1 == 0)) {
    return 0x80040050;
  }
  piVar2 = (int *)(*(int *)(iVar3 + 0x30) + param_2);
  if (iVar1 == 1) {
    iVar3 = strings_seekMediaInput(*(undefined4 **)(iVar3 + 0x18),piVar2);
  }
  else {
    if (iVar1 != 2) {
      return 0;
    }
    iVar3 = strings_seekMediaOutput(*(int **)(iVar3 + 0x18),(int)piVar2);
  }
  if (iVar3 == 0) {
    return 0;
  }
  return 0x80040053;
}



// ============================================================
// Function: lingo_vtableAppend (FUN_6809e9d0)
// Address: 6809e9d0
// Size: 101 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableAppend(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((*(int *)(iVar2 + 0x18) != 0) && (iVar1 = *(int *)(iVar2 + 0x24), iVar1 != 0)) {
    if (iVar1 == 1) {
      if (*(int *)(iVar2 + 0x1c) == -1) {
        *param_2 = *(int *)(iVar2 + 0x28);
        return 0;
      }
      iVar2 = strings_getMediaChunkSize(*(int **)(iVar2 + 0x18),*(int *)(iVar2 + 0x1c));
      *param_2 = iVar2;
      return 0;
    }
    if (iVar1 == 2) {
      *param_2 = *(int *)(iVar2 + 0x28);
      return 0;
    }
  }
  return 0x80040050;
}



// ============================================================
// Function: lingo_vtableGetNext (FUN_6809ea40)
// Address: 6809ea40
// Size: 69 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableGetNext(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = 0;
  if ((*(int *)(iVar1 + 0x18) != 0) && (*(int *)(iVar1 + 0x24) != 0)) {
    if (*(int *)(iVar1 + 0x20) == 0) {
      return 0;
    }
    iVar1 = strings_flushMediaOutput(*(int **)(iVar1 + 0x18));
    if (iVar1 != 0) {
      uVar2 = 0x80040053;
    }
    return uVar2;
  }
  return 0x80040050;
}



// ============================================================
// Function: lingo_vtableDeleteByIndex (FUN_6809ea90)
// Address: 6809ea90
// Size: 31 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableDeleteByIndex(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *param_2 = *(undefined4 *)(iVar1 + 0x20);
  *param_3 = *(undefined4 *)(iVar1 + 0x2c);
  return 0;
}



// ============================================================
// Function: lingo_vtableInsert (FUN_6809eab0)
// Address: 6809eab0
// Size: 61 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableInsert(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x18) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x30) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x1c) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x28) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x2c) = 0;
  return 0;
}



// ============================================================
// Function: lingo_vtableContains (FUN_6809eaf0)
// Address: 6809eaf0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableContains(int param_1)
{
  media_renderChannelSprite((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: lingo_vtableSort (FUN_6809eb10)
// Address: 6809eb10
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableSort(int param_1)
{
  media_invalidateChannelSprite((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: lingo_vtableDelete (FUN_6809eb30)
// Address: 6809eb30
// Size: 30 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDelete(int param_1,undefined4 param_2,undefined4 param_3)
{
  media_findSpriteAction((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_vtableClone (FUN_6809eb50)
// Address: 6809eb50
// Size: 40 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableClone(int param_1,int param_2,undefined4 param_3)

{
  media_setChannelLabel((int *)(*(int *)(param_1 + 4) + 0x18),*(short *)(*(int *)(param_1 + 4) + 0x1c),
               param_3,param_2 + 4);
  return 0;
}



// ============================================================
// Function: lingo_vtableMerge (FUN_6809eb80)
// Address: 6809eb80
// Size: 28 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableMerge(void)
{
  lingo_getVtableCount();
  return 0;
}



// ============================================================
// Function: lingo_vtableGetPropList (FUN_6809eba0)
// Address: 6809eba0
// Size: 23 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_vtableGetPropList(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x1c);
  return 0;
}



// ============================================================
// Function: lingo_vtableToString (FUN_6809ebc0)
// Address: 6809ebc0
// Size: 42 bytes
// Params: int param_1, uint param_2, uint param_3, uint * param_4, int * param_5, undefined1 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_vtableToString(int param_1,uint param_2,uint param_3,uint *param_4,int *param_5,
                 undefined1 *param_6)
{
  media_dispatchSpriteProperty((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: lingo_readStream (FUN_6809ebf0)
// Address: 6809ebf0
// Size: 29 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_readStream(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *param_2 = *(undefined4 *)(iVar1 + 0x18);
  param_2[1] = *(undefined4 *)(iVar1 + 0x1c);
  return 0;
}


