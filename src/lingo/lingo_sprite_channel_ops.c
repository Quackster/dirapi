// Module: lingo
// Topic: Sprite channel manipulation ordinals
// Address range: 0x680997D0 - 0x6809A5B0
// Functions (66):
//   Ordinal_399
//   lingo_getSpriteOpRef
//   Ordinal_413
//   Ordinal_429
//   lingo_getSpriteOpData
//   lingo_getSpriteOpState
//   lingo_getSpriteOp
//   Ordinal_414
//   Ordinal_430
//   Ordinal_431
//   Ordinal_432
//   Ordinal_433
//   Ordinal_434
//   Ordinal_440
//   Ordinal_435
//   Ordinal_436
//   Ordinal_437
//   Ordinal_438
//   Ordinal_439
//   Ordinal_441
//   Ordinal_442
//   Ordinal_463
//   Ordinal_443
//   Ordinal_444
//   Ordinal_445
//   Ordinal_446
//   lingo_dispatchSpriteOp
//   Ordinal_447
//   Ordinal_448
//   Ordinal_415
//   Ordinal_449
//   Ordinal_450
//   Ordinal_451
//   Ordinal_452
//   Ordinal_453
//   Ordinal_454
//   Ordinal_455
//   Ordinal_456
//   Ordinal_457
//   Ordinal_458
//   Ordinal_459
//   Ordinal_460
//   Ordinal_462
//   lingo_resolveSpriteChannel
//   Ordinal_416
//   Ordinal_417
//   Ordinal_461
//   Ordinal_420
//   Ordinal_421
//   Ordinal_424
//   Ordinal_422
//   Ordinal_423
//   Ordinal_427
//   Ordinal_428
//   lingo_setSpriteProperty
//   Ordinal_488
//   lingo_writeSpriteBlock
//   lingo_readSpriteBlock
//   Ordinal_489
//   Ordinal_490
//   Ordinal_491
//   Ordinal_492
//   Ordinal_493
//   Ordinal_494
//   Ordinal_495
//   Ordinal_418


// ============================================================
// Function: Ordinal_399
// Address: 680997d0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_399(int param_1)
{
                    /* 0x997d0  399   */
  media_insertScoreFrameEx(param_1);
  return 0;
}



// ============================================================
// Function: lingo_getSpriteOpRef (FUN_680997e0)
// Address: 680997e0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getSpriteOpRef(int param_1)
{
  media_deleteScoreFrame(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_413
// Address: 680997f0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_413(int param_1)
{
                    /* 0x997f0  413   */
  media_resetScoreBlocks(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_429
// Address: 68099800
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_429(int param_1)
{
                    /* 0x99800  429   */
  media_refreshScoreFormat(param_1);
  return 0;
}



// ============================================================
// Function: lingo_getSpriteOpData (FUN_68099810)
// Address: 68099810
// Size: 82 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint lingo_getSpriteOpData(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  media_setScoreSlot(param_1,0xffff);
  iVar3 = 0;
  iVar1 = media_isScoreReady(param_1);
  if (0 < iVar1) {
    do {
      media_writeScoreBlockEx(param_1,iVar3,0);
      iVar3 = iVar3 + 1;
      iVar1 = media_isScoreReady(param_1);
    } while (iVar3 < iVar1);
  }
  uVar2 = lingo_getSpriteRect(param_1,0,-1,1);
  media_getScoreReadState(param_1,0xf);
  return uVar2;
}



// ============================================================
// Function: lingo_getSpriteOpState (FUN_68099870)
// Address: 68099870
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getSpriteOpState(int param_1)
{
  media_isScoreModified(param_1);
  return 0;
}



// ============================================================
// Function: lingo_getSpriteOp (FUN_68099880)
// Address: 68099880
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getSpriteOp(int param_1)
{
  media_isScoreWritable(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_414
// Address: 68099890
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_414(int param_1)
{
                    /* 0x99890  414   */
  media_releaseScoreData(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_430
// Address: 680998a0
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_430(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x998a0  430   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfField(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_431
// Address: 680998c0
// Size: 9 bytes
// Params: int * param_1, int param_2, int param_3, short * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_431(int *param_1,int param_2,int param_3,short *param_4)
{
                    /* 0x998c0  431   */
  bitmap_getRtfFieldPair(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: Ordinal_432
// Address: 680998d0
// Size: 30 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_432(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  
                    /* 0x998d0  432   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_resolveRtfField(piVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_433
// Address: 680998f0
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_433(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x998f0  433   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfHeader(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_434
// Address: 68099910
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_434(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x99910  434   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfValue(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_440
// Address: 68099930
// Size: 29 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_440(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x99930  440   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  iVar2 = bitmap_readRtfBlock(puVar1,param_2);
  return iVar2 + -5;
}



// ============================================================
// Function: Ordinal_435
// Address: 68099950
// Size: 22 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_435(int *param_1)
{
  undefined4 *puVar1;
  
                    /* 0x99950  435   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_getRtfData(puVar1);
  return 0;
}



// ============================================================
// Function: Ordinal_436
// Address: 68099970
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_436(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x99970  436   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfInt(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_437
// Address: 68099990
// Size: 43 bytes
// Params: int * param_1, int param_2, undefined4 * param_3, undefined4 * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_437(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = param_5;
                    /* 0x99990  437   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_getRtfNodeData(puVar1,param_2,param_3,param_4,piVar2);
  *param_5 = *param_5 + -5;
  return 0;
}



// ============================================================
// Function: Ordinal_438
// Address: 680999c0
// Size: 43 bytes
// Params: int * param_1, int param_2, undefined4 * param_3, undefined4 * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_438(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = param_5;
                    /* 0x999c0  438   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_getRtfEntryData(puVar1,param_2,param_3,param_4,piVar2);
  *param_5 = *param_5 + -5;
  return 0;
}



// ============================================================
// Function: Ordinal_439
// Address: 680999f0
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_439(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x999f0  439   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_findRtfEntry(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_441
// Address: 68099a10
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_441(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x99a10  441   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfTag(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_442
// Address: 68099a30
// Size: 30 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_442(int *param_1,int param_2,int param_3)
{
  undefined4 *puVar1;
  
                    /* 0x99a30  442   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_writeRtfTag(puVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_463
// Address: 68099a50
// Size: 30 bytes
// Params: int * param_1, int param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_463(int *param_1,int param_2,undefined1 *param_3)
{
  int *piVar1;
  
                    /* 0x99a50  463   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_readRtfName(piVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_443
// Address: 68099a70
// Size: 37 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_443(int *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x99a70  443   */
  iVar1 = param_4 + 5;
  puVar2 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_setRtfProperty(puVar2,param_2,param_3,iVar1);
  return 0;
}



// ============================================================
// Function: Ordinal_444
// Address: 68099aa0
// Size: 30 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_444(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  
                    /* 0x99aa0  444   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_isRtfValid(piVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_445
// Address: 68099ac0
// Size: 30 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_445(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  
                    /* 0x99ac0  445   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_validateRtfRange(piVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_446
// Address: 68099ae0
// Size: 34 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_446(int *param_1,int param_2,int param_3,undefined4 *param_4)
{
  undefined4 *puVar1;
  
                    /* 0x99ae0  446   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfPair(puVar1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: lingo_dispatchSpriteOp (FUN_68099b10)
// Address: 68099b10
// Size: 38 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_dispatchSpriteOp(int *param_1,int param_2,int param_3,int param_4,int *param_5)
{
  int *piVar1;
  
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_populateRtfFields(piVar1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: Ordinal_447
// Address: 68099b40
// Size: 41 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_447(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x99b40  447   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  uVar2 = bitmap_readRtfEntry(piVar1,param_2);
  lingo_markFieldDirty();
  return uVar2;
}



// ============================================================
// Function: Ordinal_448
// Address: 68099b70
// Size: 49 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_448(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x99b70  448   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_setRtfValue(puVar1,param_2,param_3,param_4);
  lingo_markFieldDirty();
  return uVar2;
}



// ============================================================
// Function: Ordinal_415
// Address: 68099bb0
// Size: 30 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_415(int *param_1,int param_2,int param_3)
{
  undefined4 *puVar1;
  
                    /* 0x99bb0  415   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_shiftRtfOffsets(puVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_449
// Address: 68099bd0
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_449(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x99bd0  449   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_getRtfBlockFlag(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_450
// Address: 68099bf0
// Size: 45 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_450(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x99bf0  450   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_setRtfBlockFlag(puVar1,param_2,param_3);
  lingo_markFieldDirty();
  return uVar2;
}



// ============================================================
// Function: Ordinal_451
// Address: 68099c20
// Size: 30 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_451(int *param_1,int param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  
                    /* 0x99c20  451   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_getRtfStyleAttrs(puVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_452
// Address: 68099c40
// Size: 45 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_452(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x99c40  452   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_setRtfStyleAttrs(puVar1,param_2,param_3);
  lingo_markFieldDirty();
  return uVar2;
}



// ============================================================
// Function: Ordinal_453
// Address: 68099c70
// Size: 30 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_453(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  
                    /* 0x99c70  453   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_writeRtfEntry(piVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_454
// Address: 68099c90
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_454(int *param_1,int param_2)
{
  int *piVar1;
  
                    /* 0x99c90  454   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_allocRtfNode(piVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_455
// Address: 68099cb0
// Size: 34 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_455(int *param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  
                    /* 0x99cb0  455   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_compactRtfData(piVar1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: Ordinal_456
// Address: 68099ce0
// Size: 49 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_456(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x99ce0  456   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  uVar2 = bitmap_swapRtfFields(piVar1,param_2,param_3,param_4);
  lingo_markFieldDirty();
  return uVar2;
}



// ============================================================
// Function: Ordinal_457
// Address: 68099d20
// Size: 157 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, int param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_457(int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x99d20  457   */
  piVar1 = *(int **)(param_4 + 0x20);
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_5 == 0) {
      param_5 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_5;
    DAT_68196374 = &local_14;
    local_14 = param_5;
  }
  uVar4 = *(uint *)(iVar3 + 0x20);
  piVar2 = (int *)media_getVtableFunc(param_1);
  bitmap_updateRtfFieldRef(piVar2,param_2,param_3,uVar4,param_6);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  lingo_markFieldDirty();
  return 0;
}



// ============================================================
// Function: Ordinal_458
// Address: 68099dc0
// Size: 49 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_458(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  int *piVar2;
  
                    /* 0x99dc0  458   */
  piVar2 = (int *)media_getVtableFunc(param_1);
  bVar1 = bitmap_writeRtfFieldHandle(piVar2,param_2,param_3,param_4);
  lingo_markFieldDirty();
  return bVar1;
}



// ============================================================
// Function: Ordinal_459
// Address: 68099e00
// Size: 53 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_459(int *param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x99e00  459   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  uVar2 = bitmap_expandRtfData(piVar1,param_2,param_3,param_4,param_5);
  lingo_markFieldDirty();
  return uVar2;
}



// ============================================================
// Function: Ordinal_460
// Address: 68099e40
// Size: 45 bytes
// Params: int * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_460(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  
                    /* 0x99e40  460   */
  piVar2 = (int *)media_getVtableFunc(param_1);
  bVar1 = bitmap_removeRtfField(piVar2,param_2,param_3);
  lingo_markFieldDirty();
  return bVar1;
}



// ============================================================
// Function: Ordinal_462
// Address: 68099e70
// Size: 45 bytes
// Params: int * param_1, int param_2, byte * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_462(int *param_1,int param_2,byte *param_3)

{
  bool bVar1;
  int *piVar2;
  
                    /* 0x99e70  462   */
  piVar2 = (int *)media_getVtableFunc(param_1);
  bVar1 = bitmap_writeRtfName(piVar2,param_2,param_3);
  lingo_markFieldDirty();
  return bVar1;
}



// ============================================================
// Function: lingo_resolveSpriteChannel (FUN_68099ea0)
// Address: 68099ea0
// Size: 58 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_resolveSpriteChannel(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined3 extraout_var;
  
  iVar2 = param_3 + 1;
  piVar3 = (int *)media_getVtableFunc(param_1);
  iVar4 = bitmap_searchRtfByName(piVar3,param_2,iVar2);
  iVar2 = iVar4;
  if (iVar4 < 1) {
    bVar1 = media_isScoreSizeValid((int)param_1);
    iVar2 = 1;
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar2 = iVar4;
    }
  }
  return iVar2;
}



// ============================================================
// Function: Ordinal_416
// Address: 68099ee0
// Size: 33 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_416(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  
                    /* 0x99ee0  416   */
  iVar2 = param_2 + 5;
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_writeRtfChunk(piVar1,iVar2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_417
// Address: 68099f10
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_417(int *param_1,int param_2)
{
  int *piVar1;
  
                    /* 0x99f10  417   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  bitmap_getRtfByte(piVar1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_461
// Address: 68099f30
// Size: 40 bytes
// Params: int * param_1, int param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_461(int *param_1,int param_2,int *param_3,int param_4)
{
  int *piVar1;
  int *piVar2;
  
                    /* 0x99f30  461   */
  piVar1 = (int *)media_getVtableFunc(param_3);
  piVar2 = (int *)media_getVtableFunc(param_1);
  bitmap_readRtfRange(piVar2,param_2,piVar1,param_4);
  return 0;
}



// ============================================================
// Function: Ordinal_420
// Address: 68099f70
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_420(int param_1)
{
                    /* 0x99f70  420   */
  media_isScoreBufferValid(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_421
// Address: 68099f80
// Size: 34 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_421(int *param_1)
{
                    /* 0x99f80  421   */
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    score_freePropertyHandle(*param_1);
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_424
// Address: 68099fb0
// Size: 87 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_424(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
                    /* 0x99fb0  424   */
  uVar1 = media_getVtableFunc(param_1);
  iVar2 = media_getScoreContext(param_1);
  if (iVar2 != 0) {
    score_freePropertyHandle(uVar1);
    iVar3 = media_getVtableFunc(*(int **)(iVar2 + 0x28));
    if (iVar3 == 0) {
      piVar4 = media_getScoreStatePtr();
    }
    else {
      piVar4 = (int *)Ordinal_1112(iVar3);
    }
    media_getPlaybackByte((int)param_1,(int)piVar4,*(int *)(*(int *)(iVar2 + 0x20) + 0x500),0);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_422
// Address: 6809a010
// Size: 9 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_422(int *param_1)
{
                    /* 0x9a010  422   */
  media_getVtableFunc(param_1);
  return 0;
}



// ============================================================
// Function: Ordinal_423
// Address: 6809a020
// Size: 134 bytes
// Params: int * param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_423(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
                    /* 0x9a020  423   */
  piVar1 = (int *)media_getVtableFunc(param_1);
  iVar2 = media_getScoreContext(param_1);
  score_freePropertyHandle(piVar1);
  if (iVar2 != 0) {
    uVar3 = media_getVtableFunc(*(int **)(iVar2 + 0x28));
    score_freePropertyHandle(uVar3);
  }
  if (param_2 == 0) {
    piVar4 = media_getScoreStatePtr();
  }
  else {
    piVar4 = (int *)Ordinal_1112(param_2);
  }
  media_getPlaybackByte((int)param_1,(int)piVar4,0,0);
  if (iVar2 != 0) {
    piVar4 = (int *)Ordinal_1112(piVar4);
    media_getPlaybackByte(*(int *)(iVar2 + 0x28),(int)piVar4,0,1);
  }
  lingo_markFieldDirty();
  return piVar4 != piVar1;
}



// ============================================================
// Function: Ordinal_427
// Address: 6809a0b0
// Size: 18 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_427(int *param_1)
{
                    /* 0x9a0b0  427   */
  media_getScoreReadRef(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: Ordinal_428
// Address: 6809a0d0
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_428(int param_1)
{
                    /* 0x9a0d0  428   */
  media_incrementEditCount(param_1);
  return 0;
}



// ============================================================
// Function: lingo_setSpriteProperty (FUN_6809a0e0)
// Address: 6809a0e0
// Size: 44 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setSpriteProperty(int param_1,uint param_2)
{
  int *in_EAX;
  int iVar1;
  
  iVar1 = media_getScoreContext(in_EAX);
  if (iVar1 != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x458) = 1;
    playback_dispatchSpriteCallback(iVar1,param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_488
// Address: 6809a110
// Size: 26 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_488(int *param_1,int param_2)
{
  undefined4 *puVar1;
  
                    /* 0x9a110  488   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  bitmap_readRtfChunk(puVar1,param_2);
  return 0;
}



// ============================================================
// Function: lingo_writeSpriteBlock (FUN_6809a130)
// Address: 6809a130
// Size: 86 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_writeSpriteBlock(int *param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_c;
  int local_8;
  
  piVar4 = &local_8;
  puVar3 = &local_c;
  local_8 = 0;
  local_c = 0;
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_writeRtfBlock(puVar1,param_2,param_3,param_5,param_4,puVar3,piVar4);
  if (local_8 != 0) {
    Ordinal_1113(&local_8);
  }
  return uVar2;
}



// ============================================================
// Function: lingo_readSpriteBlock (FUN_6809a190)
// Address: 6809a190
// Size: 143 bytes
// Params: int * param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_readSpriteBlock(int *param_1,int param_2,int param_3,int *param_4)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18 [4];
  uint local_8;
  
  piVar6 = &local_1c;
  piVar5 = &local_20;
  puVar4 = &local_24;
  puVar3 = local_18;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  iVar2 = bitmap_writeRtfBlock(puVar1,param_2,param_3,puVar3,puVar4,piVar5,piVar6);
  if (iVar2 != 0) {
    media_getXtraCallback(param_4,local_1c,local_20);
  }
  if (local_1c != 0) {
    Ordinal_1113(&local_1c);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_489
// Address: 6809a220
// Size: 259 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_489(int *param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
                undefined4 *param_6)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x9a220  489   */
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar1 = media_getScoreContext(param_1);
  if ((iVar1 != 0) && (iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x20) + 8) + 0xc), iVar1 != 0)) {
    piVar7 = &local_1c;
    piVar6 = &local_20;
    puVar5 = &local_24;
    puVar4 = &local_18;
    iVar3 = param_2;
    puVar2 = (undefined4 *)media_getVtableFunc(param_1);
    bitmap_writeRtfBlock(puVar2,iVar3,param_3,puVar4,puVar5,piVar6,piVar7);
    iVar1 = media_createXtraPluginEx(iVar1,local_18,local_14,local_10,local_c,param_6,&local_28,param_2);
    if (iVar1 == 0) {
      *param_4 = local_28;
      *param_5 = local_24;
      media_getXtraCallback((int *)*param_6,local_1c,local_20);
    }
    if (local_1c != 0) {
      Ordinal_1113(&local_1c);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_490
// Address: 6809a330
// Size: 144 bytes
// Params: int * param_1, int param_2, int param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_490(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  int local_c;
  int local_8;
  
                    /* 0x9a330  490   */
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  iVar1 = media_getXtraCallbackRef(param_4,(int)&local_8);
  if (iVar1 == 0) {
    if (0 < local_8) {
      local_c = Ordinal_1111(local_8,1);
      iVar1 = media_setXtraCallback(param_4,local_c,local_8);
      if (iVar1 != 0) goto LAB_6809a3a6;
      iVar1 = param_2;
      iVar3 = local_8;
      iVar4 = local_c;
      piVar2 = (int *)media_getVtableFunc(param_1);
      local_10 = bitmap_deserializeRtfNode(piVar2,iVar1,param_3,iVar3,iVar4);
    }
    lingo_setSpriteProperty(param_2,0x200000);
  }
LAB_6809a3a6:
  if (local_c != 0) {
    Ordinal_1113(&local_c);
  }
  return local_10;
}



// ============================================================
// Function: Ordinal_491
// Address: 6809a3c0
// Size: 239 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_491(int *param_1,int param_2,int param_3,undefined4 *param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x9a3c0  491   */
  local_20 = 0;
  local_1c = 0;
  iVar1 = media_getScoreContext(param_1);
  if ((iVar1 != 0) && (iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x20) + 8) + 0xc), iVar1 != 0)) {
    iVar1 = media_createXtraPlugin(iVar1,param_3,param_4,&local_18,param_2);
    if (iVar1 == 0) {
      iVar1 = media_getXtraCallbackRef((int *)*param_4,(int)&local_20);
      if (iVar1 == 0) {
        local_1c = Ordinal_1111(local_20,1);
        iVar1 = media_setXtraCallback((int *)*param_4,local_1c,local_20);
        if (iVar1 == 0) {
          iVar1 = param_2;
          iVar3 = local_20;
          iVar4 = local_1c;
          piVar2 = (int *)media_getVtableFunc(param_1);
          bitmap_pasteRtfFromBuffer(piVar2,iVar1,local_18,local_14,local_10,local_c,iVar3,iVar4);
          lingo_setSpriteProperty(param_2,0x200000);
        }
      }
    }
  }
  if (local_1c != 0) {
    Ordinal_1113(&local_1c);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_492
// Address: 6809a4b0
// Size: 57 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_492(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2;
                    /* 0x9a4b0  492   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_duplicateRtfNode(puVar1,iVar3,param_3,param_4);
  lingo_setSpriteProperty(param_2,0x200000);
  return uVar2;
}



// ============================================================
// Function: Ordinal_493
// Address: 6809a4f0
// Size: 53 bytes
// Params: int * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_493(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_2;
                    /* 0x9a4f0  493   */
  piVar2 = (int *)media_getVtableFunc(param_1);
  bVar1 = bitmap_deleteRtfRange(piVar2,iVar3,param_3);
  lingo_setSpriteProperty(param_2,0x200000);
  return bVar1;
}



// ============================================================
// Function: Ordinal_494
// Address: 6809a530
// Size: 49 bytes
// Params: int * param_1, int param_2
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte Ordinal_494(int *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_2;
                    /* 0x9a530  494   */
  piVar2 = (int *)media_getVtableFunc(param_1);
  bVar1 = bitmap_splitRtfNode(piVar2,iVar3);
  lingo_setSpriteProperty(param_2,0x200000);
  return bVar1;
}



// ============================================================
// Function: Ordinal_495
// Address: 6809a570
// Size: 57 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_495(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2;
                    /* 0x9a570  495   */
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_copyRtfToBuffer(puVar1,iVar3,param_3,param_4);
  lingo_setSpriteProperty(param_2,0x200000);
  return uVar2;
}



// ============================================================
// Function: Ordinal_418
// Address: 6809a5b0
// Size: 79 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * Ordinal_418(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int *local_8;
  
                    /* 0x9a5b0  418   */
  local_8 = (int *)0x0;
  local_8 = (int *)media_writePlaybackData(0,0,0);
  bVar1 = Ordinal_423(local_8,param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    media_lockScoreData(local_8,(undefined4 *)0x0,(undefined4 *)0x0);
    return local_8;
  }
  media_getScorePlayState((int *)&local_8);
  return local_8;
}


