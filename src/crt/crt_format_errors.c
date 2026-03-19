// Module: crt
// Topic: Format negotiation, error mapping, sorted arrays, vtable init, stream objects
// Address range: 0x680081C0 - 0x680098A0
// Functions (51):
//   crt_extractCodecItem - crt_truncateHandle (format selection, codec release, sorted array, alloc)
//   crt_selectFormat - crt_closeStreamState (byte-swap, chunk table lookup/insert/remove, stream state)
//   crt_streamReadNext - crt_createReadStream (stream read/seek/position, vtable init, stream create)
//   crt_initWriteStreamVtable - FUN_680098a0 (write stream vtable, Ordinal_109, movie close, Ordinals 86-92/1110)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x680081c0 - 0x68008840
// Functions (8):
//   crt_extractCodecItem
//   crt_releaseCodecArray
//   crt_validateCodecSlots
//   crt_buildFormatTable
//   crt_findInSortedArray
//   crt_negotiateFormat
//   crt_allocSortedArray
//   crt_truncateHandle

// ============================================================
// Function: crt_extractCodecItem (FUN_680081c0)
// Address: 680081c0
// Size: 258 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crt_extractCodecItem(int *param_1,int param_2,int param_3,int param_4)
{
  short *psVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined1 local_6c [100];
  uint local_8;
  
  if (param_2 == 0) {
    puVar6 = (undefined *)Ordinal_1114(*(undefined4 *)(param_3 + 0x1c));
    if (puVar6 == (undefined *)0x0) {
      puVar6 = "";
    }
    Ordinal_1517(DAT_681956e0,0xffffffa6,local_6c,100);
    Ordinal_1780(puVar6,local_6c,3,1,0,1,0);
    lingo_formatDebugMsg(param_1,-0x50);
    if (puVar6 == (undefined *)0x0) goto LAB_6800825b;
    param_2 = *(int *)(param_3 + 0x1c);
  }
  else {
    psVar2 = (short *)Ordinal_1114(param_2);
    if (psVar2 == (short *)0x0) goto LAB_6800825b;
    psVar1 = psVar2 + *psVar2 * 8 + 1;
    iVar3 = Ordinal_1116(param_2);
    for (; 0 < param_4; param_4 = param_4 + -1) {
      if ((short *)((int)psVar2 + iVar3) <= psVar1) goto LAB_68008256;
      iVar4 = Ordinal_1201(psVar1);
      psVar1 = (short *)((int)psVar1 + iVar4 + 1);
    }
    iVar3 = Ordinal_1201(psVar1);
    uVar5 = cast_allocHandle(iVar3 + 1,0);
    *(undefined4 *)(param_3 + 0x1c) = uVar5;
    iVar3 = Ordinal_1114(uVar5);
    if (iVar3 != 0) {
      Ordinal_1202(iVar3,psVar1);
      Ordinal_1115(*(undefined4 *)(param_3 + 0x1c));
    }
  }
LAB_68008256:
  Ordinal_1115(param_2);
LAB_6800825b:
  return 0;
}



// ============================================================
// Function: crt_releaseCodecArray (FUN_680082d0)
// Address: 680082d0
// Size: 121 bytes
// Params: short * param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_releaseCodecArray(short *param_1,int *param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*param_1 != 0) {
    Ordinal_1114(*param_2);
    iVar2 = (int)*param_1;
    piVar3 = *(int **)*param_2;
    while (0 < iVar2) {
      piVar1 = (int *)*piVar3;
      iVar2 = iVar2 + -1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar3 = piVar3 + 8;
    }
    Ordinal_1115(*param_2);
    *param_1 = 0;
  }
  if (*param_2 != 0) {
    cast_freeHandle(*param_2);
    *param_2 = 0;
  }
  if (*param_3 != 0) {
    cast_freeHandle(*param_3);
    *param_3 = 0;
  }
  return 0;
}



// ============================================================
// Function: crt_validateCodecSlots (FUN_68008350)
// Address: 68008350
// Size: 171 bytes
// Params: int param_1, short param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_validateCodecSlots(int param_1,short param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0xb0);
  local_8 = 0;
  local_14 = DAT_68195a58;
  local_10 = param_4;
  local_c = param_3;
  piVar2 = (int *)Ordinal_2068(DAT_68195a58);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar2 + 0x14))(piVar2,crt_matchCodecFormat,&local_14);
  (**(code **)(*piVar2 + 8))(piVar2);
  iVar3 = 0;
  piVar2 = (int *)Ordinal_1114(param_3);
  if (0 < param_2) {
    do {
      if (*piVar2 == 0) {
        crt_extractCodecItem(piVar1,0,(int)piVar2,iVar3);
        if (param_4 == 0) {
          local_8 = 0xffffffb0;
        }
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 8;
    } while (iVar3 < param_2);
  }
  Ordinal_1115(param_3);
  return local_8;
}



// ============================================================
// Function: crt_buildFormatTable (FUN_68008400)
// Address: 68008400
// Size: 798 bytes
// Params: undefined4 param_1, undefined4 * param_2, short * param_3, undefined2 * param_4, undefined4 * param_5, undefined4 * param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_buildFormatTable(undefined4 param_1,undefined4 *param_2,short *param_3,undefined2 *param_4,
                undefined4 *param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  short *psVar5;
  int *piVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 local_2c;
  undefined4 *local_28;
  short *local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  puVar1 = param_2;
  *param_4 = 0;
  local_c = (int *)0x0;
  local_8 = (int *)0x0;
  local_14 = 0;
  local_18 = 0;
  *param_5 = 0;
  puVar3 = param_2;
  iVar2 = Ordinal_1116(param_2,1);
  puVar3 = (undefined4 *)cast_allocHandle(iVar2 * 2,puVar3);
  if (puVar3 == (undefined4 *)0x0) {
    return -0x7ffbfffe;
  }
  param_2 = puVar3;
  iVar2 = Ordinal_1446(puVar1,0xffffffff,1,&local_c);
  if (iVar2 == 0) {
    iVar2 = -0x7ffbffec;
  }
  else {
    iVar2 = (**(code **)(*local_c + 0xc))(local_c,0,0);
    if (iVar2 == 0) {
      local_14 = 1;
      iVar2 = Ordinal_1446(puVar3,0xffffffff,3,&local_8);
      if (iVar2 == 0) {
        iVar2 = -0x7ffbffec;
      }
      else {
        iVar2 = (**(code **)(*local_8 + 0xc))(local_8,2,0);
        if (iVar2 == 0) {
          local_18 = 1;
          iVar2 = (**(code **)(*(int *)(size_t)DAT_68195a60 + 0xc))(DAT_68195a60,local_c,&DAT_68175df8,local_8);
          if (iVar2 == 0) {
            do {
              iVar2 = (**(code **)(*(int *)(size_t)DAT_68195a60 + 0x10))(DAT_68195a60,local_c,local_8);
            } while (iVar2 == 0);
            if (iVar2 == -0x7ffbfbb4) {
              iVar2 = (**(code **)(*(int *)(size_t)DAT_68195a60 + 0x14))(DAT_68195a60,local_c,local_8);
            }
            else {
              (**(code **)(*(int *)(size_t)DAT_68195a60 + 0x18))(DAT_68195a60);
            }
            if ((iVar2 == 0) &&
               (iVar2 = (**(code **)(*local_8 + 0x20))(local_8,&local_1c), iVar2 == 0)) {
              iVar2 = (**(code **)(*local_c + 0x10))(local_c);
              local_14 = 0;
              if (iVar2 == 0) {
                iVar2 = (**(code **)(*local_8 + 0x10))(local_8);
                local_18 = 0;
                if (iVar2 == 0) {
                  (**(code **)(*local_c + 8))(local_c);
                  local_c = (int *)0x0;
                  (**(code **)(*local_8 + 8))(local_8);
                  psVar5 = param_3;
                  local_8 = (int *)0x0;
                  local_10 = (uint)*(ushort *)*puVar3;
                  if (param_3 != (short *)0x0) {
                    uVar4 = cast_allocSmallBlock((uint3)*(ushort *)*puVar3);
                    local_10 = uVar4 & 0xffff;
                    *(short *)*puVar3 = (short)uVar4;
                  }
                  local_20 = (int)(short)local_10;
                  if (local_1c < (local_20 + -1) * 0x10 + 0x12U) {
                    iVar2 = -0x50;
                  }
                  else {
                    if (psVar5 != (short *)0x0) {
                      param_3 = (short *)Ordinal_1114(puVar3);
                      iVar8 = 0;
                      puVar7 = (ushort *)(param_3 + 1);
                      if (0 < *param_3) {
                        do {
                          cast_copyPascalString(puVar7,"422",8,8);
                          iVar8 = iVar8 + 1;
                          puVar7 = puVar7 + 8;
                        } while (iVar8 < *param_3);
                      }
                      Ordinal_1115(param_2);
                      puVar3 = param_2;
                    }
                    psVar5 = (short *)cast_allocHandle(local_20 << 5,1);
                    param_3 = psVar5;
                    if (psVar5 == (short *)0x0) {
                      iVar2 = -0x7ffbfffe;
                    }
                    else {
                      local_2c = DAT_68195a58;
                      local_28 = puVar3;
                      local_24 = psVar5;
                      piVar6 = (int *)Ordinal_2068(DAT_68195a58);
                      if (piVar6 != (int *)0x0) {
                        iVar2 = (**(code **)(*piVar6 + 0x14))(piVar6,crt_matchCodecFormat,&local_2c);
                        if (iVar2 == 0) {
                          *param_4 = (undefined2)local_10;
                          *param_5 = psVar5;
                          psVar5 = (short *)0x0;
                          param_3 = (short *)0x0;
                          *param_6 = param_2;
                          param_2 = (undefined4 *)0x0;
                        }
                        (**(code **)(*piVar6 + 8))(piVar6);
                        if (iVar2 != 0) {
                          puVar3 = param_2;
                          if (psVar5 == (short *)0x0) goto LAB_680086bf;
                          crt_releaseCodecArray((short *)&local_10,(int *)&param_3,(int *)&param_2);
                          psVar5 = param_3;
                        }
                      }
                      puVar3 = param_2;
                      if (psVar5 != (short *)0x0) {
                        cast_freeHandle(psVar5);
                        puVar3 = param_2;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_680086bf:
  if (puVar3 != (undefined4 *)0x0) {
    cast_freeHandle(puVar3);
  }
  iVar8 = 0;
  if (local_c != (int *)0x0) {
    if (local_14 != 0) {
      iVar8 = (**(code **)(*local_c + 0x10))(local_c);
    }
    (**(code **)(*local_c + 8))(local_c);
    if (iVar2 == 0) {
      iVar2 = iVar8;
    }
  }
  if (local_8 != (int *)0x0) {
    if (local_18 != 0) {
      iVar8 = (**(code **)(*local_8 + 0x10))(local_8);
    }
    (**(code **)(*local_8 + 8))(local_8);
    if (iVar2 == 0) {
      iVar2 = iVar8;
    }
  }
  return iVar2;
}



// ============================================================
// Function: crt_findInSortedArray (FUN_68008730)
// Address: 68008730
// Size: 61 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_findInSortedArray(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = 0;
  if ((param_1 != (undefined4 *)0x0) && (iVar2 = 0, 0 < param_2)) {
    piVar3 = (int *)*param_1;
    while (*piVar3 != param_3) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      if (param_2 <= iVar2) {
        return uVar1;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: crt_negotiateFormat (FUN_68008770)
// Address: 68008770
// Size: 119 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_negotiateFormat(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    iVar1 = Ordinal_1111(0x20,0);
    *param_1 = iVar1;
    param_2 = 0;
  }
  iVar1 = crt_findInSortedArray((undefined4 *)*param_1,param_2,param_3);
  if (iVar1 != 0) {
    return param_2;
  }
  iVar1 = (param_2 + 8U & 0xfffffff8) * 4;
  iVar2 = Ordinal_1116(*param_1);
  if ((iVar2 < iVar1) && (iVar1 = Ordinal_1117(param_1,iVar1,0), iVar1 == 0)) {
    return 0;
  }
  *(int *)(*(int *)*param_1 + param_2 * 4) = param_3;
  return param_2 + 1;
}



// ============================================================
// Function: crt_allocSortedArray (FUN_680087f0)
// Address: 680087f0
// Size: 71 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_allocSortedArray(int param_1)
{
  undefined2 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 < 1) {
    param_1 = 1;
  }
  puVar2 = (undefined4 *)Ordinal_1111((param_1 * 3 + 3) * 4,1);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1 = (undefined2 *)*puVar2;
  *(int *)(puVar1 + 2) = param_1;
  *puVar1 = 0xc;
  puVar1[1] = 0xc;
  *(undefined4 *)(puVar1 + 4) = 0;
  return 0;
}



// ============================================================
// Function: crt_truncateHandle (FUN_68008840)
// Address: 68008840
// Size: 18 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_truncateHandle(undefined4 param_1)
{
  Ordinal_1120(param_1,0);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68008860 - 0x68008e20
// Functions (13):
//   crt_selectFormat
//   crt_loadChunkFormat
//   crt_copySortedArray
//   crt_writeChunkFormatted
//   crt_readChunkFormatted
//   crt_resolveFormat
//   crt_getFormatState
//   crt_insertSortedEntry
//   crt_getFormatCount
//   crt_formatError
//   crt_addStreamRef
//   crt_openStreamForWrite
//   crt_closeStreamState

// ============================================================
// Function: crt_selectFormat (FUN_68008860)
// Address: 68008860
// Size: 373 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_selectFormat(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *unaff_ESI;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    Ordinal_1114();
    iVar3 = *unaff_ESI + 0xc;
    iVar4 = iVar3;
    for (iVar1 = *(int *)(*unaff_ESI + 4); 0 < iVar1; iVar1 = iVar1 + -1) {
      Ordinal_1129(iVar4,iVar3,0xc);
      iVar3 = iVar3 + 0xc;
      iVar4 = iVar4 + 0xc;
    }
    Ordinal_1115();
    uVar2 = cast_resizeHandle((uint)unaff_ESI,(*(int *)(*unaff_ESI + 4) * 3 + 3) * 4,1);
    if (uVar2 == 0) {
      return 0;
    }
    if (param_1 == 0) {
      return 1;
    }
    Ordinal_1114();
    iVar1 = Ordinal_1116();
    iVar3 = *(int *)(*unaff_ESI + 4) * 0xc;
    if ((0 < iVar3) && (iVar3 <= iVar1)) {
      cast_copyPascalString((ushort *)(*unaff_ESI + 0xc),"444",0xc,iVar3);
    }
    cast_copyPascalString((ushort *)*unaff_ESI,"2244",0xc,0xc);
  }
  else {
    if (param_1 != 0) {
      Ordinal_1114();
      iVar1 = Ordinal_1116();
      cast_copyPascalString((ushort *)*unaff_ESI,"2244",0xc,0xc);
      iVar3 = *(int *)(*unaff_ESI + 4) * 0xc;
      if ((0 < iVar3) && (iVar3 <= iVar1 + -0xc)) {
        cast_copyPascalString((ushort *)(*unaff_ESI + 0xc),"444",0xc,iVar3);
      }
      Ordinal_1115();
    }
    uVar2 = cast_resizeHandle((uint)unaff_ESI,(*(int *)(*unaff_ESI + 4) * 3 + 3) * 4,1);
    if (uVar2 == 0) {
      return 0;
    }
    Ordinal_1114();
    iVar1 = *(int *)(*unaff_ESI + 4);
    iVar3 = *unaff_ESI + iVar1 * 0xc;
    param_1 = iVar3;
    if (0 < iVar1) {
      do {
        Ordinal_1129(param_1,iVar3,0xc);
        param_1 = param_1 + -0xc;
        iVar1 = iVar1 + -1;
        iVar3 = iVar3 + -0xc;
      } while (0 < iVar1);
      Ordinal_1115();
      return 1;
    }
  }
  Ordinal_1115();
  return 1;
}



// ============================================================
// Function: crt_loadChunkFormat (FUN_680089e0)
// Address: 680089e0
// Size: 179 bytes
// Params: int * param_1, int param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crt_loadChunkFormat(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = (undefined4 *)Ordinal_16(param_1,param_2);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = Ordinal_1116(puVar2);
    if (4 < iVar3) {
      iVar3 = js_initAtomTable((int)param_1);
      uVar4 = crt_searchChunkByType((int)param_1,param_2);
      if (iVar3 != 0) {
        cast_copyPascalString((ushort *)*puVar2,"2244",0xc,0xc);
      }
      iVar1 = *(int *)((ushort *)*puVar2 + 2);
      if (((iVar1 == 0) || (uVar5 = iVar1 - 1, 0x15555554 < uVar5)) ||
         (uVar5 = uVar5 * 0xc, 0xfffffff2 < uVar5)) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = uVar5 + 0xc;
      }
      if (uVar5 <= uVar4) {
        if (iVar3 != 0) {
          cast_copyPascalString((ushort *)*puVar2,"2244",0xc,0xc);
        }
        iVar3 = crt_selectFormat(iVar3,1);
        if (iVar3 != 0) {
          return puVar2;
        }
        cast_freeHandle(puVar2);
      }
    }
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: crt_copySortedArray (FUN_68008aa0)
// Address: 68008aa0
// Size: 37 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_copySortedArray(int *param_1,int param_2,int param_3)
{
  crt_resizeSlotAlloc(param_2,param_3,(*(int *)(*param_1 + 4) * 3 + 3) * 4);
  return 0;
}



// ============================================================
// Function: crt_writeChunkFormatted (FUN_68008ad0)
// Address: 68008ad0
// Size: 125 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_writeChunkFormatted(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = js_initAtomTable(param_2);
  iVar2 = crt_selectFormat(iVar1,0);
  if (iVar2 != 0) {
    Ordinal_1114(param_1);
    iVar2 = Ordinal_1116(param_1);
    iVar3 = crt_writeChunkHeader(param_2,param_3);
    if (iVar3 == 0) {
      iVar2 = crt_writeChunkBlock(param_2,*param_1,iVar2);
      if (iVar2 == 0) {
        crt_resetChunkState(param_2);
      }
    }
    Ordinal_1115(param_1);
    iVar1 = crt_selectFormat(iVar1,1);
    if (iVar1 != 0) {
      uVar4 = Ordinal_15(param_2);
      return uVar4;
    }
  }
  return 0xffffffff;
}



// ============================================================
// Function: crt_readChunkFormatted (FUN_68008b50)
// Address: 68008b50
// Size: 108 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 param_4, int * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readChunkFormatted(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Ordinal_1116(param_1);
  if (param_3 < iVar1) {
    return -1;
  }
  iVar2 = crt_selectFormat(param_2,0);
  if (iVar2 == 0) {
    return -1;
  }
  Ordinal_1114(param_1);
  Ordinal_1129(param_4,*param_1,iVar1);
  Ordinal_1115(param_1);
  *param_5 = iVar1;
  iVar1 = crt_selectFormat(param_2,1);
  return (iVar1 != 0) - 1;
}



// ============================================================
// Function: crt_resolveFormat (FUN_68008bc0)
// Address: 68008bc0
// Size: 145 bytes
// Params: int * param_1, int param_2, int param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_resolveFormat(int *param_1,int param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  iVar2 = *param_1;
  iVar6 = *(int *)(iVar2 + 8);
  if ((iVar6 < 0) || (*(int *)(iVar2 + 4) < iVar6)) {
    return 0xffffffff;
  }
  iVar6 = iVar6 + -1;
  iVar5 = 0;
  iVar3 = -1;
  if (-1 < iVar6) {
    do {
      iVar3 = (iVar6 - iVar5 >> 1) + iVar5;
      puVar1 = (undefined4 *)(iVar2 + (iVar3 * 3 + 3) * 4);
      iVar4 = param_2 - puVar1[1];
      if ((iVar4 == 0) && (iVar4 = param_3 - puVar1[2], iVar4 == 0)) {
        if (param_4 != (int *)0x0) {
          *param_4 = iVar3;
        }
        return *puVar1;
      }
      if (iVar4 < 1) {
        iVar6 = iVar3 + -1;
      }
      else {
        iVar5 = iVar3 + 1;
      }
    } while (iVar5 <= iVar6);
    if (iVar4 < 1) goto LAB_68008c24;
  }
  iVar3 = iVar3 + 1;
LAB_68008c24:
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
  }
  return 0xffffffff;
}



// ============================================================
// Function: crt_getFormatState (FUN_68008c60)
// Address: 68008c60
// Size: 63 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getFormatState(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = (*(int *)(iVar1 + 8) - param_2) + -1;
  if (0 < iVar2) {
    Ordinal_1129(iVar1 + (param_2 * 3 + 3) * 4,iVar1 + (param_2 * 3 + 6) * 4,iVar2 * 0xc);
  }
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + -1;
  return 0;
}



// ============================================================
// Function: crt_insertSortedEntry (FUN_68008ca0)
// Address: 68008ca0
// Size: 144 bytes
// Params: int * param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crt_insertSortedEntry(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = *(int *)(*param_1 + 4);
  if (iVar2 <= *(int *)(*param_1 + 8)) {
    iVar4 = iVar2 >> 1;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    uVar3 = cast_resizeHandle((uint)param_1,((iVar4 + iVar2) * 3 + 3) * 4,1);
    if (uVar3 == 0) {
      return DAT_68195a8c;
    }
    *(int *)(*param_1 + 4) = iVar4 + iVar2;
  }
  iVar2 = *param_1;
  iVar4 = *(int *)(iVar2 + 8) - param_2;
  puVar1 = (undefined4 *)(iVar2 + (param_2 * 3 + 3) * 4);
  if (0 < iVar4) {
    Ordinal_1129(iVar2 + (param_2 * 3 + 6) * 4,puVar1,iVar4 * 0xc);
  }
  puVar1[1] = param_4;
  puVar1[2] = param_5;
  *puVar1 = param_3;
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + 1;
  return 0;
}



// ============================================================
// Function: crt_getFormatCount (FUN_68008d30)
// Address: 68008d30
// Size: 15 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getFormatCount(int *param_1)

{
  return *(undefined4 *)(*param_1 + 8);
}



// ============================================================
// Function: crt_formatError (FUN_68008d40)
// Address: 68008d40
// Size: 46 bytes
// Params: int * param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_formatError(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 * 3 + 3;
  iVar1 = *param_1 + iVar2 * 4;
  *param_3 = *(undefined4 *)(*param_1 + iVar2 * 4);
  *param_4 = *(undefined4 *)(iVar1 + 4);
  *param_5 = *(undefined4 *)(iVar1 + 8);
  return 0;
}



// ============================================================
// Function: crt_addStreamRef (FUN_68008d80)
// Address: 68008d80
// Size: 17 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_addStreamRef(int param_1)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return 0;
}



// ============================================================
// Function: crt_openStreamForWrite (FUN_68008da0)
// Address: 68008da0
// Size: 117 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_openStreamForWrite(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    return -0x7ffbffaf;
  }
  if (param_2 != 0) {
    return -0x7ffbffab;
  }
  crt_lockRifx(*(int *)(param_1 + 8));
  iVar1 = crt_validateSlot(*(int *)(param_1 + 8),*(int *)(param_1 + 0xc),4);
  iVar1 = crt_allocCodecBlock(iVar1);
  if (iVar1 == 0) {
    crt_seekToChunkEnd(*(int *)(param_1 + 8),8);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  crt_unlockRifx(*(int *)(param_1 + 8));
  return iVar1;
}



// ============================================================
// Function: crt_closeStreamState (FUN_68008e20)
// Address: 68008e20
// Size: 41 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_closeStreamState(int param_1)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0x80040050;
  }
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68008e50 - 0x680092b0
// Functions (17):
//   crt_streamReadNext
//   crt_streamReadNextEx
//   crt_getStreamStatus
//   crt_getStreamPosition
//   crt_setStreamPosition
//   crt_getStreamLength
//   crt_getStreamBounds
//   crt_releaseStreamRef
//   crt_initWriteStream
//   crt_closeWriteStream
//   crt_getWriteStreamStatus
//   crt_readWriteStreamData
//   crt_getWriteStreamSeekStatus
//   crt_getWriteStreamPosition
//   crt_getWriteStreamBounds
//   crt_initReadStreamVtable
//   crt_createReadStream

// ============================================================
// Function: crt_streamReadNext (FUN_68008e50)
// Address: 68008e50
// Size: 97 bytes
// Params: int param_1, undefined4 param_2, int param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamReadNext(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_4;
  if (*(int *)(param_1 + 0x14) == 0) {
    return -0x7ffbffb0;
  }
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 == 0) {
    iVar2 = crt_readSlotData(*(int **)(param_1 + 8),*(int *)(param_1 + 0xc),(int *)(param_1 + 0x10),
                         param_2,&param_3,(uint)(param_4 != (int *)0x0));
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_3;
    }
    iVar2 = crt_allocCodecBlock(iVar2);
    *(int *)(param_1 + 0x18) = iVar2;
  }
  return iVar2;
}



// ============================================================
// Function: crt_streamReadNextEx (FUN_68008ec0)
// Address: 68008ec0
// Size: 123 bytes
// Params: int param_1, undefined4 param_2, int param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamReadNextEx(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = param_4;
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x14) == 0) {
    return -0x7ffbffb0;
  }
  iVar5 = *(int *)(param_1 + 0x18);
  if (iVar5 == 0) {
    piVar1 = (int *)(param_1 + 0xc);
    puVar2 = (undefined4 *)(param_1 + 8);
    param_1 = *(int *)(param_1 + 0x10);
    iVar5 = crt_readSlotData((int *)*puVar2,*piVar1,&param_1,param_2,&param_3,
                         (uint)(param_4 != (int *)0x0));
    if (piVar4 != (int *)0x0) {
      *piVar4 = param_3;
    }
    if ((iVar5 != 0) && (iVar5 != 0xce)) {
      *(int *)(iVar3 + 0x18) = iVar5;
      return iVar5;
    }
    *(undefined4 *)(iVar3 + 0x18) = 0;
    iVar5 = *(int *)(iVar3 + 0x18);
  }
  return iVar5;
}



// ============================================================
// Function: crt_getStreamStatus (FUN_68008f40)
// Address: 68008f40
// Size: 27 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getStreamStatus(int param_1)

{
  return (-(uint)(*(int *)(param_1 + 0x14) != 0) & 0xfffc3fb1) + 0x80040050;
}



// ============================================================
// Function: crt_getStreamPosition (FUN_68008f60)
// Address: 68008f60
// Size: 46 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getStreamPosition(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return -0x7ffbffb0;
  }
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x10);
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: crt_setStreamPosition (FUN_68008f90)
// Address: 68008f90
// Size: 40 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_setStreamPosition(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0x80040050;
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return 0;
}



// ============================================================
// Function: crt_getStreamLength (FUN_68008fc0)
// Address: 68008fc0
// Size: 51 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getStreamLength(int param_1,int *param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0x80040050;
  }
  if (param_2 != (int *)0x0) {
    iVar1 = crt_getChunkSizeEx(*(int **)(param_1 + 8),*(int *)(param_1 + 0xc));
    *param_2 = iVar1;
  }
  return 0;
}



// ============================================================
// Function: crt_getStreamBounds (FUN_68009000)
// Address: 68009000
// Size: 53 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getStreamBounds(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0x80040050;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}



// ============================================================
// Function: crt_releaseStreamRef (FUN_68009040)
// Address: 68009040
// Size: 38 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_releaseStreamRef(int param_1)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  uVar1 = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == 0) {
    Ordinal_1125(&param_1);
  }
  return uVar1;
}



// ============================================================
// Function: crt_initWriteStream (FUN_68009070)
// Address: 68009070
// Size: 76 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_initWriteStream(int param_1,int param_2,int param_3)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    return 0x80040051;
  }
  if (param_2 != 2) {
    return 0x80040055;
  }
  if (param_3 != 0) {
    return 0x80040056;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 1;
  return 0;
}



// ============================================================
// Function: crt_closeWriteStream (FUN_680090c0)
// Address: 680090c0
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_closeWriteStream(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0x80040050;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return 0;
}



// ============================================================
// Function: crt_getWriteStreamStatus (FUN_680090f0)
// Address: 680090f0
// Size: 27 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getWriteStreamStatus(int param_1)

{
  return (-(uint)(*(int *)(param_1 + 0x18) != 0) & 0xfffc3fb1) + 0x80040050;
}



// ============================================================
// Function: crt_readWriteStreamData (FUN_68009110)
// Address: 68009110
// Size: 111 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_readWriteStreamData(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0x80040050;
  }
  if (uVar1 < param_3) {
    if (param_4 == (uint *)0x0) {
      return 0x80040058;
    }
    param_3 = uVar1;
    if (uVar1 == 0) {
      *param_4 = 0;
      return 0;
    }
  }
  Ordinal_1129(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc),param_2,param_3);
  if (param_4 != (uint *)0x0) {
    *param_4 = param_3;
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_3;
  return 0;
}



// ============================================================
// Function: crt_getWriteStreamSeekStatus (FUN_68009180)
// Address: 68009180
// Size: 27 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getWriteStreamSeekStatus(int param_1)

{
  return (-(uint)(*(int *)(param_1 + 0x18) != 0) & 0xfffc3fb1) + 0x80040050;
}



// ============================================================
// Function: crt_getWriteStreamPosition (FUN_680091a0)
// Address: 680091a0
// Size: 39 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getWriteStreamPosition(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0x80040050;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x14);
  }
  return 0;
}



// ============================================================
// Function: crt_getWriteStreamBounds (FUN_680091d0)
// Address: 680091d0
// Size: 53 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getWriteStreamBounds(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0x80040050;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 2;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}



// ============================================================
// Function: crt_initReadStreamVtable (FUN_68009210)
// Address: 68009210
// Size: 156 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * crt_initReadStreamVtable(void)

{
  if (DAT_68195a68 == '\0') {
    DAT_68195a68 = '\x01';
    _DAT_681972c0 = &LAB_68008d70;
    _DAT_681972c4 = crt_addStreamRef;
    _DAT_681972c8 = crt_releaseStreamRef;
    _DAT_681972cc = crt_openStreamForWrite;
    _DAT_681972d0 = crt_closeStreamState;
    _DAT_681972d4 = crt_streamReadNext;
    _DAT_681972d8 = crt_streamReadNextEx;
    _DAT_681972dc = crt_getStreamStatus;
    _DAT_681972e0 = crt_getStreamPosition;
    _DAT_681972e4 = crt_setStreamPosition;
    _DAT_681972e8 = crt_getStreamLength;
    _DAT_681972ec = lingo_noop;
    _DAT_681972f0 = crt_getStreamBounds;
  }
  return &DAT_681972c0;
}



// ============================================================
// Function: crt_createReadStream (FUN_680092b0)
// Address: 680092b0
// Size: 84 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_createReadStream(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 extraout_ECX;
  
  puVar1 = (undefined4 *)Ordinal_1124(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    *param_3 = 0;
    return 0x80040002;
  }
  puVar2 = crt_initReadStreamVtable();
  puVar1[2] = param_1;
  *puVar1 = puVar2;
  puVar1[3] = param_2;
  puVar1[4] = 0xffffffff;
  puVar1[5] = extraout_ECX;
  puVar1[6] = extraout_ECX;
  (**(code **)(puVar2 + 4))(puVar1);
  *param_3 = (int)puVar1;
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68009310 - 0x680098a0
// Functions (17):
//   crt_initWriteStreamVtable
//   crt_createWriteStream
//   crt_getMovieFrameCount
//   crt_getMovieState
//   crt_writeFormatData
//   crt_writeFormatError
//   crt_resetPlaybackTimer
//   crt_getGlobalState
//   Ordinal_109
//   core_closeMovie
//   Ordinal_283
//   Ordinal_86
//   Ordinal_87
//   Ordinal_89
//   Ordinal_90
//   Ordinal_92
//   Ordinal_1110

// ============================================================
// Function: crt_initWriteStreamVtable (FUN_68009310)
// Address: 68009310
// Size: 156 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * crt_initWriteStreamVtable(void)

{
  if (DAT_68195a69 == '\0') {
    DAT_68195a69 = '\x01';
    _DAT_68197280 = &LAB_6809de10;
    _DAT_68197284 = crt_addStreamRef;
    _DAT_68197288 = crt_releaseStreamRef;
    _DAT_6819728c = crt_initWriteStream;
    _DAT_68197290 = crt_closeWriteStream;
    _DAT_68197294 = crt_getWriteStreamStatus;
    _DAT_68197298 = crt_getWriteStreamStatus;
    _DAT_6819729c = crt_readWriteStreamData;
    _DAT_681972a0 = crt_getWriteStreamPosition;
    _DAT_681972a4 = crt_getWriteStreamSeekStatus;
    _DAT_681972a8 = crt_getWriteStreamPosition;
    _DAT_681972ac = lingo_noop;
    _DAT_681972b0 = crt_getWriteStreamBounds;
  }
  return &DAT_68197280;
}



// ============================================================
// Function: crt_createWriteStream (FUN_680093b0)
// Address: 680093b0
// Size: 88 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_createWriteStream(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 extraout_ECX;
  
  puVar1 = (undefined4 *)Ordinal_1124(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    *param_1 = 0;
    *param_2 = 0;
    return 0x80040002;
  }
  puVar2 = crt_initWriteStreamVtable();
  *puVar1 = puVar2;
  puVar1[2] = extraout_ECX;
  puVar1[4] = extraout_ECX;
  puVar1[3] = extraout_ECX;
  puVar1[5] = extraout_ECX;
  puVar1[6] = extraout_ECX;
  (**(code **)(puVar2 + 4))(puVar1);
  *param_1 = (int)puVar1;
  *param_2 = (int)(puVar1 + 2);
  return 0;
}



// ============================================================
// Function: crt_getMovieFrameCount (FUN_68009410)
// Address: 68009410
// Size: 39 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crt_getMovieFrameCount(int param_1)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  local_8 = 0;
  uVar1 = 0;
  if (param_1 != 0) {
    Ordinal_54(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x18) + 0xc),&local_8);
    uVar1 = local_8;
  }
  return uVar1;
}



// ============================================================
// Function: crt_getMovieState (FUN_68009440)
// Address: 68009440
// Size: 42 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getMovieState(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  
  uVar1 = 0;
  if (unaff_ESI != 0) {
    if ((*(int *)(unaff_ESI + 0x24) == 0) && (*(int *)(unaff_ESI + 0xc) != 0)) {
      iVar2 = Ordinal_118(*(int *)(unaff_ESI + 0xc));
      uVar1 = stage_getSpriteConstraint(iVar2);
    }
    if (*(int *)(unaff_ESI + 0x20) != 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



// ============================================================
// Function: crt_writeFormatData (FUN_68009470)
// Address: 68009470
// Size: 227 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeFormatData(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  if (*(code **)(param_1 + 0x40) != (code *)0x0) {
    (**(code **)(param_1 + 0x40))(param_3,param_2);
    return 0;
  }
  if ((param_3 == 0) || (param_3 == 1)) {
    local_408 = 0;
    memset(local_407,0,0x3fe);
    iVar1 = Ordinal_1320(param_2,DAT_681956e0);
    if (iVar1 != 0) {
      iVar1 = Ordinal_1316(param_2);
      if (iVar1 != 0) {
        if (param_3 == 1) {
          iVar1 = Ordinal_1517(DAT_681956e0,0xfa1,&local_408,0x3ff);
          if (iVar1 == 0) goto LAB_6800953e;
          Ordinal_1317(param_2,&local_408);
        }
        return 0;
      }
    }
  }
LAB_6800953e:
  return 0;
}



// ============================================================
// Function: crt_writeFormatError (FUN_68009560)
// Address: 68009560
// Size: 133 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeFormatError(int param_1,undefined4 param_2)
{
  int iVar1;
  undefined1 local_408 [1024];
  uint local_8;
  
  if (*(code **)(param_1 + 0x44) != (code *)0x0) {
    (**(code **)(param_1 + 0x44))(param_2);
    return 0;
  }
  iVar1 = crt_writeFormatData(param_1,param_2,0);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1517(DAT_681956e0,0xfa2,local_408,0x3ff);
    if (iVar1 != 0) {
      Ordinal_1317(param_2,local_408);
    }
  }
  return 0;
}



// ============================================================
// Function: crt_resetPlaybackTimer (FUN_680095f0)
// Address: 680095f0
// Size: 40 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_resetPlaybackTimer(void)
{
  int in_EAX;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0x2c) != 0)) {
    *(undefined4 *)(in_EAX + 0x2c) = 0;
    Ordinal_1764(0);
    Ordinal_1763(in_EAX + 0x30,0);
  }
  return 0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: core_closeMovie (FUN_68009640)
// Address: 68009640
// Size: 117 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_closeMovie(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    Ordinal_2330();
    uVar1 = DAT_68196374;
    DAT_68196374 = &stack0xffffffec;
    lingo_cleanupDisplayEx(*(int *)(unaff_ESI + 0x10));
    DAT_68196374 = (undefined1 *)uVar1;
    Ordinal_2331();
    stage_destroyContext((int *)(unaff_ESI + 0x14));
    Ordinal_113(unaff_ESI,param_1);
    Ordinal_1130();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_283
// Address: 680096c0
// Size: 19 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_283(int param_1)
{
                    /* 0x96c0  283   */
  stage_suspendContext((int *)(param_1 + 0x14));
  return 0;
}



// ============================================================
// Function: Ordinal_86
// Address: 680096e0
// Size: 50 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Sets a score property on the player and updates the stage accordingly.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Property identifier to set.
 * @param param_3  Property value.
 * @return Always returns 0.
 */
int Ordinal_86(int param_1,undefined4 param_2,undefined4 param_3)
{
  Player *player = (Player *)param_1;
  int iVar1;

                    /* 0x96e0  86   */
  if (player == NULL) return 0;

  score_setProperty(player->scoreHandle,param_2);
  iVar1 = Ordinal_118(player->scoreHandle);
  stage_updateProperty(iVar1,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_87
// Address: 68009720
// Size: 25 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Sets the player's user data pointer if the player is active.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  User data value to store.
 * @return Always returns 0.
 */
int Ordinal_87(int *param_1,int param_2)
{
  Player *player = (Player *)param_1;

                    /* 0x9720  87   */
  if (player != NULL && player->valid) {
    player->userData = (void *)param_2;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_89
// Address: 68009740
// Size: 221 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Runs one full playback cycle: renders sprites, processes score frames, and draws the stage.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Frame advance mode passed to score update.
 * @return 1 if playback proceeded, 0 if the player is inactive or in error state.
 */
undefined4 Ordinal_89(int param_1,int param_2)

{
  Player *player = (Player *)param_1;
  code *pcVar1;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int temp;

                    /* 0x9740  89   */
  if (player == NULL) return 0;
  if (*(short *)&player->playerState == 2) return 0;

  Ordinal_152(player->scoreHandle,0x400,param_2);
  piVar4 = (int *)Ordinal_118(player->scoreHandle);
  stage_renderSprites(piVar4);
  Ordinal_136(player->scoreHandle,1);
  uVar3 = Ordinal_58(player->scoreHandle,(byte *)NULL);
  Ordinal_75(player->scoreHandle,(byte *)NULL,uVar3);
  Ordinal_143(player->scoreHandle,(byte *)NULL);
  temp = 0;
  Ordinal_54(player->scoreHandle,&temp);
  if (temp != 0) {
    Ordinal_1821(temp,0);
  }
  do {
    iVar5 = Ordinal_145(player->scoreHandle,0,0);
    lingo_checkMovieLoaded(*(int **)(*(int *)player->hostContext + 0x10));
    pcVar1 = *(code **)(*(int *)(*(int *)player->hostContext + 0xc) + 0x20);
    if (pcVar1 != (code *)NULL) {
      (*pcVar1)();
    }
  } while (iVar5 == 1);
  if (player->pausedFlag == 0) {
    lingo_drawScoreView(player->scoreHandle);
  }
  return 1;
}



// ============================================================
// Function: Ordinal_90
// Address: 68009820
// Size: 90 bytes
// Params: int param_1, undefined4 * param_2, undefined1 * param_3, short param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Enters script mode on the player and optionally retrieves an error description.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Receives error code on failure, or NULL.
 * @param param_3  Error message buffer, or NULL.
 * @param param_4  Error message buffer length.
 * @return Always returns 1.
 */
undefined4 Ordinal_90(int param_1,undefined4 *param_2,undefined1 *param_3,short param_4)

{
  Player *player = (Player *)param_1;
  undefined4 uVar1;

                    /* 0x9820  90   */
  if (player != NULL && *(short *)&player->playerState != 2) {
    lingo_enterScriptMode(player->scoreHandle,1);
    if (param_3 != NULL && param_2 != NULL && param_4 != 0) {
      uVar1 = Ordinal_120(*(undefined4 **)(*(int *)player->hostContext + 0x10),param_3,(int)param_4);
      *param_2 = uVar1;
    }
  }
  crt_resetPlaybackTimer();
  return 1;
}



// ============================================================
// Function: Ordinal_92
// Address: 68009880
// Size: 25 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/**
 * @brief Sets the player's callback handler pointer if the player is active.
 *
 * @param param_1  Pointer to the Player object.
 * @param param_2  Callback handler to assign.
 * @return Always returns 0.
 */
int Ordinal_92(int *param_1,int param_2)
{
  Player *player = (Player *)param_1;

                    /* 0x9880  92   */
  if (player != NULL && player->valid) {
    player->callback = (void *)param_2;
  }
  return 0;
}



// ============================================================
// Function: dirapi_Ordinal_1110 (exported as Ordinal_1110)
// Address: 680098a0
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 dirapi_Ordinal_1110(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x98a0  1110   */
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = crt_getMovieState();
  }
  return uVar1;
}




/* Restored functions that were incorrectly removed during thunk cleanup */

// ============================================================

undefined4 crt_getGlobalState(void)

{
  return DAT_68195a6c;
}

