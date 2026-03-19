// Module: javascript
// Topic: Array/Boolean objects, type coercion, array join/sort/concat/slice/splice/push/pop
// Address range: 0x681357b0 - 0x68138070
// Functions (38):

//   javascript_parseArrayLength
//   js_arrayToString
//   js_arrayGet
//   js_arraySlice
//   js_arrayPush
//   javascript_arrayGetVtable
//   javascript_arrayTruncate
//   javascript_arrayEnsureIndex
//   javascript_arrayDefaultValue
//   js_arraySortCompare
//   javascript_arrayToStringWrapped
//   javascript_arrayToLocaleString
//   javascript_arrayJoin
//   javascript_arrayJoinWithSep
//   javascript_arrayCopyElements
//   javascript_arrayInitFromArgs
//   javascript_arrayReverse
//   javascript_heapSiftDown
//   javascript_arraySortCompareFn
//   javascript_arraySortCompareStr
//   javascript_arrayPushElements
//   javascript_arrayPop
//   javascript_arrayShift
//   javascript_arrayUnshift
//   javascript_arrayConstructor
//   javascript_createArrayObject
//   js_arrayEnsureCapacity
//   javascript_heapSort
//   javascript_arraySort
//   javascript_arraySplice
//   javascript_arrayConcat
//   javascript_arraySliceRange
//   javascript_computeEpochOffset
//   javascript_getTimeMicroseconds
//   js_gcMarkRoots
//   javascript_formatTimeStruct
//   javascript_decomposeTimestamp
//   javascript_getTimezoneOffset

// ============================================================
// Function: javascript_parseArrayLength (FUN_681357b0)
// Address: 681357b0
// Size: 289 bytes
// Params: ushort * param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_parseArrayLength(ushort *param_1,uint param_2,uint *param_3)

{
  int local_18;
  undefined4 uVar1;
  int iVar2;
  int local_14;
  uint uStack_10;
  uint local_8;
  
  if (((param_2 & 1) == 0) || (param_2 == 0x80000001)) {
    iVar2 = runtime_parseNumber(param_1,param_2,(double *)&local_14);
    if (iVar2 == 0) {
      xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x98);
      uVar1 = 0;
    }
    else {
      iVar2 = runtime_addFloat(param_1,local_14,uStack_10,param_3);
      if (iVar2 == 0) {
        xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x98);
        uVar1 = 0;
      }
      else {
        if ((((uStack_10 & 0x7ff00000) != 0x7ff00000) ||
            ((local_14 == 0 && ((uStack_10 & 0xfffff) == 0)))) &&
           ((double)CONCAT44(uStack_10,local_14) == (double)*param_3)) {
          return 1;
        }
        xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x98);
        uVar1 = 0;
      }
    }
  }
  else {
    local_8 = (int)param_2 >> 1;
    if ((int)local_8 < 0) {
      xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x98);
      uVar1 = 0;
    }
    else {
      *param_3 = local_8;
      uVar1 = 1;
    }
  }
  return uVar1;
}



// ============================================================
// Function: js_arrayToString (FUN_681358e0)
// Address: 681358e0
// Size: 121 bytes
// Params: ushort * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_arrayToString(ushort *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(*(int *)(param_1 + 10) + 0x108);
  iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8,&local_c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
    uVar2 = runtime_parseFloat(param_1,local_c,param_3);
  }
  else {
    *param_3 = (int)local_c >> 1;
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: js_arrayGet (FUN_68135960)
// Address: 68135960
// Size: 76 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_arrayGet(int param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  
  if (param_2 < 0x40000000) {
    *param_3 = param_2 << 1 | 1;
    uVar1 = 1;
  }
  else {
    uVar1 = runtime_formatNumber(param_1,(double)param_2,param_3);
  }
  return uVar1;
}



// ============================================================
// Function: js_arraySlice (FUN_681359b0)
// Address: 681359b0
// Size: 121 bytes
// Params: void * this, uint param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall js_arraySlice(void *this,uint param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  if (param_2 < 0x40000000) {
    *param_3 = param_2 << 1 | 1;
  }
  else {
    puVar1 = (uint *)runtime_divideFloat(this,param_2,param_1,(double)param_2);
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    puVar2 = js_findOrCreateAtom(param_1,puVar1,0);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    *param_3 = (uint)puVar2;
  }
  return 1;
}



// ============================================================
// Function: js_arrayPush (FUN_68135a30)
// Address: 68135a30
// Size: 81 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_arrayPush(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = js_arrayGet(param_1,param_3,&local_c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    local_8 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x108);
    uVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_8,&local_c);
  }
  return uVar2;
}



// ============================================================
// Function: javascript_arrayGetVtable (FUN_68135a90)
// Address: 68135a90
// Size: 40 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arrayGetVtable(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  (**(code **)((*(uint *)(*(int *)(param_2 + 4) + 8) & 0xfffffffe) + 0x10))
            (param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: javascript_arrayTruncate (FUN_68135ac0)
// Address: 68135ac0
// Size: 173 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayTruncate(ushort *param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_18 [4];
  uint local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = javascript_parseArrayLength(param_1,*param_4,&local_10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = js_arrayToString(param_1,param_2,(int *)&local_8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      for (local_14 = local_10; local_14 < local_8; local_14 = local_14 + 1) {
        iVar1 = js_arraySlice(&local_c,(uint)param_1,local_14,&local_c);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x20))(param_1,param_2,local_c,local_18);
        if (iVar1 == 0) {
          return 0;
        }
      }
      uVar2 = js_arrayGet((int)param_1,local_10,param_4);
    }
  }
  return uVar2;
}



// ============================================================
// Function: javascript_arrayEnsureIndex (FUN_68135b70)
// Address: 68135b70
// Size: 102 bytes
// Params: ushort * param_1, int * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayEnsureIndex(ushort *param_1,int *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  uint local_8;
  
  iVar1 = javascript_numberParseInt(param_3,&local_c);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = js_arrayToString(param_1,param_2,(int *)&local_8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if (local_c < local_8) {
      uVar2 = 1;
    }
    else {
      local_8 = local_c + 1;
      uVar2 = js_arrayPush((int)param_1,param_2,local_8);
    }
  }
  return uVar2;
}



// ============================================================
// Function: javascript_arrayDefaultValue (FUN_68135be0)
// Address: 68135be0
// Size: 140 bytes
// Params: ushort * param_1, int * param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayDefaultValue(ushort *param_1,int *param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_8;
  
  if (*(int *)(param_1 + 6) == 0x78) {
    iVar1 = js_arrayToString(param_1,param_2,(int *)&local_8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if (param_3 == 4) {
      uVar2 = js_arrayGet((int)param_1,local_8,param_4);
    }
    else if (param_3 == 5) {
      *param_4 = (uint)(local_8 != 0) << 3 | 6;
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = runtime_definePropertyOnObject((uint)param_1,param_2,param_3,(int *)param_4);
  }
  return uVar2;
}



// ============================================================
// Function: js_arraySortCompare (FUN_68135c70)
// Address: 68135c70
// Size: 1468 bytes
// Params: ushort * param_1, int * param_2, uint * param_3, int param_4, uint * param_5, int param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_arraySortCompare(ushort *param_1,int *param_2,uint *param_3,int param_4,uint *param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  void *local_64;
  uint local_60;
  void *local_5c;
  uint local_58;
  void *local_54;
  uint local_50;
  void *local_4c;
  uint local_48;
  code *local_44;
  uint local_40;
  uint *local_3c;
  short *local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  short *local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  void *local_8;
  
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_10);
  if (iVar1 == 0) {
    return 0;
  }
  local_20 = 1;
  local_30 = runtime_beginGcTraversal((uint)param_1,param_2,(undefined4 *)0x0,(int *)&local_38);
  if (local_30 == 0) {
    return 0;
  }
  if (param_4 == 0) {
    if (local_38 != (short *)0x0) {
      xtra_checkAndFlush(param_1,(int)local_38);
    }
    local_38 = (short *)0x0;
    local_34 = 0;
    if (((*(uint *)(local_30 + 0xc) & 2) != 0) || (local_10 == 0)) {
      runtime_endGcTraversal((int)param_1,(int *)0x0);
      uVar2 = xtraRuntime_getCapabilitiesHi((int)param_1);
      *param_5 = uVar2;
      return local_20;
    }
    *(uint *)(local_30 + 0xc) = *(uint *)(local_30 + 0xc) | 2;
    goto LAB_68135ddb;
  }
  if ((*(uint *)(local_30 + 0xc) & 1) != 0) {
    local_34 = certs_getStringLength(local_38);
    goto LAB_681361ce;
  }
  local_24 = 10;
  if (local_38 == (short *)0x0) {
    local_34 = 0;
    local_38 = (short *)js_runGC();
    if (local_38 != (short *)0x0) {
LAB_68135d5f:
      local_38[local_34] = 0x5b;
      local_34 = local_34 + 1;
LAB_68135ddb:
      local_8 = (void *)0x0;
      if ((*param_3 & 0x40000000) == 0) {
        local_40 = *param_3;
      }
      else {
        local_40 = (-(uint)((*param_3 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_3;
      }
      local_18 = local_40;
      local_c = 0;
      local_28 = 0;
      do {
        if ((local_10 <= local_28) ||
           (local_20 = xtraRuntime_setPropertyByIndex(param_1,param_2,local_28,&local_c), local_20 == 0)) break;
        if ((local_c == 0x80000001) || (local_c == 0)) {
          local_3c = *(uint **)(*(int *)(param_1 + 10) + 0x1dc);
        }
        else {
          if (param_6 == 0) {
            if (param_4 == 0) {
              local_44 = certs_hashLookup;
            }
            else {
              local_44 = certs_resizeString;
            }
            local_3c = (uint *)(*local_44)(param_1,local_c);
          }
          else {
            iVar1 = runtime_deleteProperty((uint)param_1,local_c,(uint *)&local_14);
            if ((iVar1 == 0) ||
               (uVar2 = runtime_defineProperty((uint)param_1,local_14,
                                     *(undefined4 *)(*(int *)(param_1 + 10) + 0x120),0,0,
                                     (int *)&local_c), uVar2 == 0)) {
              local_3c = (uint *)0x0;
            }
            else {
              local_3c = (uint *)certs_hashLookup((int)param_1,local_c);
            }
          }
          if (local_3c == (uint *)0x0) {
            local_20 = 0;
            break;
          }
        }
        if ((*local_3c & 0x40000000) == 0) {
          local_48 = *local_3c;
        }
        else {
          local_48 = (-(uint)((*local_3c & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_3c;
        }
        local_24 = ((-(uint)(local_8 != (void *)0x0) & local_18) + local_34 + local_48) * 2 + 8;
        if (local_38 == (short *)0x0) {
          local_38 = (short *)js_runGC();
          if (local_38 == (short *)0x0) break;
        }
        else {
          local_1c = local_38;
          local_38 = (short *)js_allocAtomBlock((int)local_38,local_24);
          if (local_38 == (short *)0x0) {
            js_freeHandle();
            break;
          }
        }
        if (local_8 != (void *)0x0) {
          memcpy(local_38 + local_34,local_8,local_18 << 1);
          local_34 = local_34 + local_18;
        }
        if ((*param_3 & 0x40000000) == 0) {
          local_54 = (void *)param_3[1];
        }
        else {
          if ((*(uint *)param_3[1] & 0x40000000) == 0) {
            if ((*param_3 & 0x80000000) == 0) {
              local_50 = *param_3 >> 0xf & 0x7fff;
            }
            else {
              local_50 = 0;
            }
            local_4c = (void *)(*(int *)(param_3[1] + 4) + local_50 * 2);
          }
          else {
            local_4c = (void *)crypto_getStringLen(param_3);
          }
          local_54 = local_4c;
        }
        local_8 = local_54;
        if ((*local_3c & 0x40000000) == 0) {
          local_58 = *local_3c;
        }
        else {
          local_58 = (-(uint)((*local_3c & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_3c;
        }
        local_2c = local_58;
        if ((*local_3c & 0x40000000) == 0) {
          local_64 = (void *)local_3c[1];
        }
        else {
          if ((*(uint *)local_3c[1] & 0x40000000) == 0) {
            if ((*local_3c & 0x80000000) == 0) {
              local_60 = *local_3c >> 0xf & 0x7fff;
            }
            else {
              local_60 = 0;
            }
            local_5c = (void *)(*(int *)(local_3c[1] + 4) + local_60 * 2);
          }
          else {
            local_5c = (void *)crypto_getStringLen(local_3c);
          }
          local_64 = local_5c;
        }
        memcpy(local_38 + local_34,local_64,local_2c << 1);
        local_34 = local_34 + local_2c;
        local_28 = local_28 + 1;
      } while( true );
    }
  }
  else {
    *(uint *)(local_30 + 0xc) = *(uint *)(local_30 + 0xc) | 1;
    local_34 = certs_getStringLength(local_38);
    local_1c = local_38;
    local_38 = (short *)js_allocAtomBlock((int)local_38,local_24 + local_34 * 2);
    if (local_38 != (short *)0x0) goto LAB_68135d5f;
    js_freeHandle();
  }
  if (param_4 == 0) {
    *(uint *)(local_30 + 0xc) = *(uint *)(local_30 + 0xc) & 0xfffffffd;
  }
  else if (local_38 != (short *)0x0) {
    if (local_c == 0x80000001) {
      local_38[local_34] = 0x2c;
      local_38[local_34 + 1] = 0x20;
      local_34 = local_34 + 2;
    }
    local_38[local_34] = 0x5d;
    local_34 = local_34 + 1;
  }
  runtime_endGcTraversal((int)param_1,(int *)0x0);
  if (local_20 == 0) {
    if (local_38 == (short *)0x0) {
      return 0;
    }
    js_freeHandle();
    return local_20;
  }
LAB_681361ce:
  if (local_38 == (short *)0x0) {
    xtra_reportError((int)param_1);
    iVar1 = 0;
  }
  else {
    local_38[local_34] = 0;
    puVar3 = certs_allocHashEntry((int)param_1,(uint)local_38,local_34,0);
    if (puVar3 == (uint *)0x0) {
      js_freeHandle();
      iVar1 = 0;
    }
    else {
      *param_5 = (uint)puVar3 | 4;
      iVar1 = 1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: javascript_arrayToStringWrapped (FUN_68136230)
// Address: 68136230
// Size: 33 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arrayToStringWrapped(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint *param_5)
{
  js_arraySortCompare(param_1,param_2,(uint *)&DAT_68193a0c,1,param_5,0);
  return 0;
}



// ============================================================
// Function: javascript_arrayToLocaleString (FUN_68136260)
// Address: 68136260
// Size: 76 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arrayToLocaleString(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint *param_5)
{
  uint *local_c;
  
  if ((*(int *)(param_1 + 6) == 0x78) == 0) {
    local_c = (uint *)&DAT_68193a14;
  }
  else {
    local_c = (uint *)&DAT_68193a0c;
  }
  js_arraySortCompare(param_1,param_2,local_c,(uint)(*(int *)(param_1 + 6) == 0x78),param_5,0);
  return 0;
}



// ============================================================
// Function: javascript_arrayJoin (FUN_681362b0)
// Address: 681362b0
// Size: 33 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arrayJoin(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint *param_5)
{
  js_arraySortCompare(param_1,param_2,(uint *)&DAT_68193a14,0,param_5,1);
  return 0;
}



// ============================================================
// Function: javascript_arrayJoinWithSep (FUN_681362e0)
// Address: 681362e0
// Size: 113 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_arrayJoinWithSep(ushort *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint *puVar2;
  
  if (*param_4 == 0x80000001) {
    iVar1 = js_arraySortCompare(param_1,param_2,(uint *)&DAT_68193a14,0,param_5,0);
  }
  else {
    puVar2 = (uint *)certs_hashLookup((int)param_1,*param_4);
    if (puVar2 == (uint *)0x0) {
      iVar1 = 0;
    }
    else {
      *param_4 = (uint)puVar2 | 4;
      iVar1 = js_arraySortCompare(param_1,param_2,puVar2,0,param_5,0);
    }
  }
  return iVar1;
}



// ============================================================
// Function: javascript_arrayCopyElements (FUN_68136360)
// Address: 68136360
// Size: 113 bytes
// Params: void * param_1, int * param_2, uint param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayCopyElements(void *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  uint local_c;
  uint local_8;
  
  local_c = 0;
  while( true ) {
    if (param_3 <= local_c) {
      return 1;
    }
    iVar1 = js_arraySlice(param_1,(uint)param_1,local_c,&local_8);
    if (iVar1 == 0) break;
    iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))
                      (param_1,param_2,local_8,param_4 + local_c * 4);
    if (iVar1 == 0) {
      return 0;
    }
    local_c = local_c + 1;
  }
  return 0;
}



// ============================================================
// Function: javascript_arrayInitFromArgs (FUN_681363e0)
// Address: 681363e0
// Size: 137 bytes
// Params: void * param_1, int * param_2, uint param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayInitFromArgs(void *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = js_arrayGet((int)param_1,param_3,&local_c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    local_8 = *(undefined4 *)(*(int *)((int)param_1 + 0x14) + 0x108);
    iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0xc))
                      (param_1,param_2,local_8,local_c,javascript_arrayGetVtable,javascript_arrayTruncate,4,0);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if (param_4 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = javascript_arrayCopyElements(param_1,param_2,param_3,param_4);
    }
  }
  return uVar2;
}



// ============================================================
// Function: javascript_arrayReverse (FUN_68136470)
// Address: 68136470
// Size: 309 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_arrayReverse(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  void *this;
  uint local_20;
  uint local_1c;
  undefined1 local_18 [4];
  void *local_14;
  void *local_10;
  undefined1 local_c [4];
  uint local_8;
  
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_1c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    local_14 = (void *)(local_1c >> 1);
    for (local_10 = (void *)0x0; local_10 < local_14; local_10 = (void *)((int)local_10 + 1)) {
      iVar1 = js_arraySlice(local_10,(uint)param_1,(uint)local_10,&local_8);
      if (iVar1 == 0) {
        return 0;
      }
      this = (void *)((local_1c - (int)local_10) + -1);
      iVar1 = js_arraySlice(this,(uint)param_1,(uint)this,&local_20);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8,local_c);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_20,local_18);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_8,local_18);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_20,local_c);
      if (iVar1 == 0) {
        return 0;
      }
    }
    *param_5 = param_2;
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: javascript_heapSiftDown (FUN_681365b0)
// Address: 681365b0
// Size: 581 bytes
// Params: int param_1, int * param_2, uint param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_heapSiftDown(int param_1,int *param_2,uint param_3,uint param_4)
{
  undefined4 *_Dst;
  int iVar1;
  size_t _Size;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_2c;
  
  _Dst = (undefined4 *)param_2[2];
  iVar1 = *param_2;
  _Size = param_2[1];
  iVar7 = iVar1 + _Size * -2;
  pcVar2 = (code *)param_2[3];
  iVar3 = param_2[4];
  iVar4 = param_2[5];
  if (param_3 == 1) {
    local_2c = 2;
    if ((2 < param_4) && (iVar5 = (*pcVar2)(iVar1,iVar1 + _Size,iVar3), iVar5 < 0)) {
      local_2c = 3;
    }
    puVar8 = (undefined4 *)((param_4 - 1) * _Size + iVar1);
    puVar6 = (undefined4 *)(local_2c * _Size + iVar7);
    if (((param_1 != 0) || (param_4 == 2)) && (iVar5 = (*pcVar2)(puVar8,puVar6,iVar3), -1 < iVar5))
    {
      return 0;
    }
    if (iVar4 == 0) {
      memcpy(_Dst,puVar8,_Size);
      memcpy(puVar8,puVar6,_Size);
    }
    else {
      *_Dst = *puVar8;
      *puVar8 = *puVar6;
    }
    param_3 = local_2c;
  }
  else {
    puVar6 = (undefined4 *)(param_3 * _Size + iVar7);
    if (iVar4 == 0) {
      memcpy(_Dst,puVar6,_Size);
    }
    else {
      *_Dst = *puVar6;
    }
  }
  while (param_3 <= param_4 >> 1) {
    local_2c = param_3 * 2;
    if ((local_2c < param_4) &&
       (iVar5 = (*pcVar2)(local_2c * _Size + iVar7,(local_2c - 1) * _Size + iVar1,iVar3), iVar5 < 0)
       ) {
      local_2c = local_2c + 1;
    }
    puVar6 = (undefined4 *)(local_2c * _Size + iVar7);
    iVar5 = (*pcVar2)(_Dst,puVar6,iVar3);
    if (-1 < iVar5) break;
    puVar8 = (undefined4 *)(param_3 * _Size + iVar7);
    if (iVar4 == 0) {
      memcpy(puVar8,puVar6,_Size);
    }
    else {
      *puVar8 = *puVar6;
    }
    param_3 = local_2c;
  }
  puVar6 = (undefined4 *)(param_3 * _Size + iVar7);
  if (iVar4 == 0) {
    memcpy(puVar6,_Dst,_Size);
  }
  else {
    *puVar6 = *_Dst;
  }
  return 0;
}



// ============================================================
// Function: javascript_arraySortCompareFn (FUN_68136800)
// Address: 68136800
// Size: 401 bytes
// Params: uint * param_1, uint * param_2, uint * param_3
// Return: ulonglong
// Calling convention: __stdcall
// ============================================================

ulonglong javascript_arraySortCompareFn(uint *param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint *extraout_ECX;
  uint *extraout_ECX_00;
  uint *extraout_ECX_01;
  uint *extraout_ECX_02;
  uint *extraout_ECX_03;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  ulonglong uVar4;
  int local_48;
  undefined8 local_34;
  uint local_28;
  uint *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  ushort *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_20 = *param_1;
  local_28 = *param_2;
  local_24 = param_3;
  local_14 = (ushort *)*param_3;
  local_34 = -1.0;
  local_8 = param_3[1];
  if (local_8 == 0) {
    puVar1 = (uint *)0x0;
    if (local_20 == local_28) {
      local_34 = 0.0;
    }
    else if ((local_20 == 0x80000001) || (local_28 == 0x80000001)) {
      param_3 = (uint *)((uint)(local_20 == 0x80000001) * 2 - 1);
      local_34 = (double)(int)param_3;
    }
    else {
      puVar1 = (uint *)certs_hashLookup((int)local_14,local_20);
      param_3 = extraout_ECX;
      if ((puVar1 == (uint *)0x0) ||
         (puVar2 = (uint *)certs_hashLookup((int)local_14,local_28), param_3 = extraout_ECX_00,
         puVar2 == (uint *)0x0)) {
        local_24[2] = 0;
        puVar1 = local_24;
      }
      else {
        iVar3 = certs_compareStrings(puVar1,puVar2);
        local_34 = (double)iVar3;
        param_3 = extraout_ECX_01;
        puVar1 = extraout_EDX;
      }
    }
  }
  else {
    local_1c = local_20;
    local_18 = local_28;
    local_c = certs_validateExtension((uint)local_14,
                           *(uint *)(*(int *)((local_8 & 0xfffffff8) + 4) + 4) & 0xfffffff8,local_8,
                           0,2,(int)&local_1c,(int *)&local_10);
    if (local_c == 0) {
      local_24[2] = 0;
      local_c = 0;
      param_3 = extraout_ECX_02;
      puVar1 = local_24;
    }
    else {
      local_c = runtime_parseNumber(local_14,local_10,(double *)&local_34);
      param_3 = extraout_ECX_03;
      if ((((*(unsigned int *)((char *)&local_34 + 4)) & 0x7ff00000) == 0x7ff00000) &&
         (((int)local_34 != 0 ||
          (param_3 = (uint *)((*(unsigned int *)((char *)&local_34 + 4)) & 0xfffff),
          ((ulonglong)local_34 & 0xfffff00000000) != 0)))) {
        local_34 = 0.0;
        puVar1 = extraout_EDX_00;
      }
      else {
        puVar1 = extraout_EDX_00;
        if (local_34 != 0.0) {
          if (local_34 <= 0.0) {
            local_48 = -1;
          }
          else {
            local_48 = 1;
          }
          local_34 = (double)local_48;
          puVar1 = extraout_EDX_00;
        }
      }
    }
  }
  uVar4 = strings_floatToUint64(param_3,puVar1);
  return uVar4;
}



// ============================================================
// Function: javascript_arraySortCompareStr (FUN_681369a0)
// Address: 681369a0
// Size: 47 bytes
// Params: uint * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arraySortCompareStr(uint *param_1,uint *param_2)
{
  certs_compareStrings((uint *)(*param_1 & 0xfffffff8),(uint *)(*param_2 & 0xfffffff8));
  return 0;
}



// ============================================================
// Function: javascript_arrayPushElements (FUN_681369d0)
// Address: 681369d0
// Size: 240 bytes
// Params: ushort * param_1, int * param_2, uint param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayPushElements(ushort *param_1,int *param_2,uint param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
      iVar1 = js_arraySlice(param_1,(uint)param_1,local_c + local_10,&local_8);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))
                        (param_1,param_2,local_8,param_4 + local_10 * 4);
      if (iVar1 == 0) {
        return 0;
      }
    }
    local_c = local_c + param_3;
    if (*(int *)(param_1 + 6) == 0x78) {
      if (param_3 == 0) {
        local_14 = 0x80000001;
      }
      else {
        local_14 = *(uint *)(param_4 + -4 + param_3 * 4);
      }
      *param_5 = local_14;
    }
    else {
      iVar1 = js_arrayGet((int)param_1,local_c,param_5);
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = js_arrayPush((int)param_1,param_2,local_c);
  }
  return uVar2;
}



// ============================================================
// Function: javascript_arrayPop (FUN_68136ac0)
// Address: 68136ac0
// Size: 171 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_arrayPop(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  uint local_c;
  undefined4 local_8;
  
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_c != 0) {
    local_c = local_c - 1;
    iVar1 = js_arraySlice(&local_8,(uint)param_1,local_c,&local_8);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x20))(param_1,param_2,local_8,local_10);
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = js_arrayPush((int)param_1,param_2,local_c);
  return uVar2;
}



// ============================================================
// Function: javascript_arrayShift (FUN_68136b70)
// Address: 68136b70
// Size: 338 bytes
// Params: ushort * param_1, int * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_arrayShift(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  uint local_18;
  uint local_14;
  uint local_10;
  undefined1 local_c [4];
  uint local_8;
  
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_10);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_10 != 0) {
    local_10 = local_10 - 1;
    local_8 = 1;
    iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,1,param_5);
    if (iVar1 == 0) {
      return 0;
    }
    if (local_10 != 0) {
      for (local_14 = 1; local_14 <= local_10; local_14 = local_14 + 1) {
        iVar1 = js_arraySlice(param_1,(uint)param_1,local_14,&local_8);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = js_arraySlice(param_1,(uint)param_1,local_14 - 1,&local_18);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8,local_c);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_18,local_c);
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x20))(param_1,param_2,local_8,local_1c);
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = js_arrayPush((int)param_1,param_2,local_10);
  return uVar2;
}



// ============================================================
// Function: javascript_arrayUnshift (FUN_68136cd0)
// Address: 68136cd0
// Size: 377 bytes
// Params: ushort * param_1, int * param_2, void * param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayUnshift(ushort *param_1,int *param_2,void *param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  void *this;
  bool bVar3;
  uint local_1c;
  void *local_18;
  void *local_14;
  void *local_10;
  undefined1 local_c [4];
  uint local_8;
  
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_14);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_3 != (void *)0x0) {
    if (local_14 != (void *)0x0) {
      local_10 = local_14;
      while (this = (void *)((int)local_10 + -1), bVar3 = local_10 != (void *)0x0, local_10 = this,
            bVar3) {
        iVar1 = js_arraySlice(this,(uint)param_1,(uint)this,&local_8);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = js_arraySlice((void *)((int)local_10 + (int)param_3),(uint)param_1,
                             (uint)((int)local_10 + (int)param_3),&local_1c);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8,local_c);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_1c,local_c);
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    for (local_18 = (void *)0x0; local_18 < param_3; local_18 = (void *)((int)local_18 + 1)) {
      iVar1 = js_arraySlice(local_18,(uint)param_1,(uint)local_18,&local_8);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))
                        (param_1,param_2,local_8,param_4 + (int)local_18 * 4);
      if (iVar1 == 0) {
        return 0;
      }
    }
    local_14 = (void *)((int)local_14 + (int)param_3);
    iVar1 = js_arrayPush((int)param_1,param_2,(uint)local_14);
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = js_arrayGet((int)param_1,(uint)local_14,param_5);
  return uVar2;
}



// ============================================================
// Function: javascript_arrayConstructor (FUN_68136e50)
// Address: 68136e50
// Size: 242 bytes
// Params: ushort * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arrayConstructor(ushort *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint *local_c;
  uint local_8;
  
  if ((*(uint *)(*(int *)(param_1 + 0x1a) + 0x4c) & 1) == 0) {
    param_2 = runtime_setProperty((int)param_1,&PTR_s_Array_681939b8,(undefined4 *)0x0,0);
    if (param_2 == (int *)0x0) {
      return 0;
    }
    *param_5 = param_2;
  }
  if (param_3 == 0) {
    local_8 = 0;
    local_c = (uint *)0x0;
  }
  else if (*(int *)(param_1 + 6) == 0x78) {
    local_8 = param_3;
    local_c = param_4;
  }
  else if (param_3 < 2) {
    if ((((*param_4 & 1) == 0) || (*param_4 == 0x80000001)) && ((*param_4 & 7) != 2)) {
      local_8 = 1;
      local_c = param_4;
    }
    else {
      iVar1 = javascript_parseArrayLength(param_1,*param_4,&local_8);
      if (iVar1 == 0) {
        return 0;
      }
      local_c = (uint *)0x0;
    }
  }
  else {
    local_8 = param_3;
    local_c = param_4;
  }
  uVar2 = javascript_arrayInitFromArgs(param_1,param_2,local_8,(int)local_c);
  return uVar2;
}



// ============================================================
// Function: javascript_createArrayObject (FUN_68136f50)
// Address: 68136f50
// Size: 85 bytes
// Params: void * param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * javascript_createArrayObject(void *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = xtra_createScriptObject((int)param_1,param_2,(undefined4 *)0x0,&PTR_s_Array_681939b8,0x68136e50,1,
                        (int *)0x0,(int *)&PTR_s_toSource_68193a20,(int *)0x0,(int *)0x0);
  if ((piVar1 == (int *)0x0) || (iVar2 = javascript_arrayInitFromArgs(param_1,piVar1,0,0), iVar2 == 0)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



// ============================================================
// Function: js_arrayEnsureCapacity (FUN_68136fb0)
// Address: 68136fb0
// Size: 86 bytes
// Params: void * param_1, uint param_2, int param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * js_arrayEnsureCapacity(void *param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = runtime_setProperty((int)param_1,&PTR_s_Array_681939b8,(undefined4 *)0x0,0);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    iVar2 = javascript_arrayInitFromArgs(param_1,piVar1,param_2,param_3);
    if (iVar2 == 0) {
      *(undefined4 *)((int)param_1 + 0x90) = 0;
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}



// ============================================================
// Function: javascript_heapSort (FUN_68137010)
// Address: 68137010
// Size: 201 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined * param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_heapSort(int param_1,uint param_2,undefined4 param_3,undefined *param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_1c = js_runGC();
  if (local_1c == 0) {
    uVar1 = 0;
  }
  else {
    local_24 = param_1;
    local_20 = param_3;
    local_18 = param_4;
    local_14 = param_5;
    if (((code *)param_4 == javascript_arraySortCompareFn) || ((code *)param_4 == javascript_arraySortCompareStr)) {
      local_28 = 1;
    }
    else {
      local_28 = 0;
    }
    local_10 = local_28;
    local_c = local_1c;
    for (local_8 = param_2 >> 1; local_8 != 0; local_8 = local_8 - 1) {
      javascript_heapSiftDown(1,&local_24,local_8,param_2);
    }
    while (2 < param_2) {
      param_2 = param_2 - 1;
      javascript_heapSiftDown(0,&local_24,1,param_2);
    }
    js_freeHandle();
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: javascript_arraySort (FUN_681370e0)
// Address: 681370e0
// Size: 538 bytes
// Params: ushort * param_1, int * param_2, int param_3, uint * param_4, undefined4 * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_arraySort(ushort *param_1,int *param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  code *local_44;
  ushort *local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  if (param_3 == 0) {
    local_14 = 0;
    local_c = 1;
  }
  else {
    if (((*param_4 & 7) != 0) || (*param_4 == 0)) {
      xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xc);
      return 0;
    }
    local_14 = *param_4;
    local_c = 0;
  }
  iVar1 = js_arrayToString(param_1,param_2,(int *)&local_1c);
  if (iVar1 == 0) {
    local_24 = 0;
  }
  else if (local_1c == 0) {
    *param_5 = param_2;
    local_24 = 1;
  }
  else if ((double)local_1c * 4.0 == (double)(local_1c << 2)) {
    local_10 = xtra_getPropertyById((int)param_1,local_1c << 2);
    if (local_10 == 0) {
      local_24 = 0;
    }
    else {
      local_20 = local_1c;
      for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
        local_24 = js_arraySlice(param_1,(uint)param_1,local_18,&local_8);
        if (local_24 == 0) {
          local_24 = 0;
          goto LAB_681372de;
        }
        local_24 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))
                             (param_1,param_2,local_8,local_10 + local_18 * 4);
        if (local_24 == 0) {
          local_24 = 0;
          goto LAB_681372de;
        }
        local_c = (*(uint *)(local_10 + local_18 * 4) & 7) == 4 & local_c;
      }
      local_2c = param_1;
      local_28 = local_14;
      local_24 = 1;
      if (local_c == 0) {
        local_44 = javascript_arraySortCompareFn;
      }
      else {
        local_44 = javascript_arraySortCompareStr;
      }
      iVar1 = javascript_heapSort(local_10,local_1c,4,local_44,&local_2c);
      if (iVar1 == 0) {
        xtra_reportError((int)param_1);
        local_24 = 0;
      }
      if ((local_24 != 0) &&
         (local_24 = javascript_arrayCopyElements(param_1,param_2,local_20,local_10), local_24 != 0)) {
        *param_5 = param_2;
      }
LAB_681372de:
      if (local_10 != 0) {
        xtra_checkAndFlush(param_1,local_10);
      }
    }
  }
  else {
    xtra_reportError((int)param_1);
    local_24 = 0;
  }
  return local_24;
}



// ============================================================
// Function: javascript_arraySplice (FUN_68137300)
// Address: 68137300
// Size: 1309 bytes
// Params: ushort * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arraySplice(ushort *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  uint local_80;
  void *local_60;
  double local_34;
  void *local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  void *local_1c;
  void *local_18;
  void *local_14;
  uint local_10;
  undefined1 local_c [4];
  uint local_8;
  
  if (param_3 == 0) {
    uVar1 = 1;
  }
  else {
    iVar2 = js_arrayToString(param_1,param_2,(int *)&local_1c);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      iVar2 = runtime_parseNumber(param_1,*param_4,&local_34);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        fVar6 = runtime_powFloat(SUB84(local_34,0),(uint)((ulonglong)local_34 >> 0x20));
        local_34 = (double)fVar6;
        if (0.0 <= local_34) {
          if ((double)(size_t)local_1c /* FIXUP(C2440): double via size_t */ < local_34) {
            local_34 = (double)(size_t)local_1c /* FIXUP(C2440): double via size_t */;
          }
        }
        else {
          local_34 = (double)(size_t)local_1c /* FIXUP(C2440): double via size_t */ + local_34;
          if (local_34 < 0.0) {
            local_34 = 0.0;
          }
        }
        local_60 = (void *)(longlong)ROUND(local_34);
        local_18 = local_60;
        uVar5 = (int)local_1c - (int)local_60;
        if (param_3 == 1) {
          local_2c = local_1c;
          param_3 = 0;
          local_10 = uVar5;
        }
        else {
          iVar2 = runtime_parseNumber(param_1,param_4[1],&local_34);
          if (iVar2 == 0) {
            return 0;
          }
          fVar6 = runtime_powFloat(SUB84(local_34,0),(uint)((ulonglong)local_34 >> 0x20));
          local_34 = (double)fVar6;
          if (0.0 <= local_34) {
            if ((double)uVar5 < local_34) {
              local_34 = (double)uVar5;
            }
          }
          else {
            local_34 = 0.0;
          }
          local_80 = (uint)(longlong)ROUND(local_34);
          local_10 = local_80;
          local_2c = (void *)((int)local_18 + local_80);
          param_3 = param_3 - 2;
        }
        if ((local_10 == 1) && (*(int *)(param_1 + 6) == 0x78)) {
          iVar2 = js_arraySlice(local_18,(uint)param_1,(uint)local_18,&local_8);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8);
          if (iVar2 == 0) {
            return 0;
          }
        }
        else if ((*(int *)(param_1 + 6) != 0x78) || (local_10 != 0)) {
          local_20 = js_arrayEnsureCapacity(param_1,0,0);
          if (local_20 == (int *)0x0) {
            return 0;
          }
          *param_5 = local_20;
          if (local_10 != 0) {
            for (local_14 = local_18; local_14 < local_2c; local_14 = (void *)((int)local_14 + 1)) {
              iVar2 = js_arraySlice(local_14,(uint)param_1,(uint)local_14,&local_8);
              if (iVar2 == 0) {
                return 0;
              }
              iVar2 = js_arraySlice((void *)((int)local_14 - (int)local_18),(uint)param_1,
                                   (uint)((int)local_14 - (int)local_18),&local_28);
              if (iVar2 == 0) {
                return 0;
              }
              iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8);
              if (iVar2 == 0) {
                return 0;
              }
              iVar2 = (**(code **)(*(int *)(*local_20 + 4) + 0x14))
                                (param_1,local_20,local_28,local_c);
              if (iVar2 == 0) {
                return 0;
              }
            }
          }
        }
        if (local_10 < param_3) {
          iVar2 = param_3 - local_10;
          local_14 = local_1c;
          do {
            pvVar3 = (void *)((int)local_14 - 1);
            if (local_14 <= local_2c) {
              local_1c = (void *)((int)local_1c + iVar2);
              local_14 = pvVar3;
              goto LAB_681377a3;
            }
            local_14 = pvVar3;
            iVar4 = js_arraySlice(&local_8,(uint)param_1,(uint)pvVar3,&local_8);
            if (iVar4 == 0) {
              return 0;
            }
            iVar4 = js_arraySlice(&local_28,(uint)param_1,(int)local_14 + iVar2,&local_28);
            if (iVar4 == 0) {
              return 0;
            }
            iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8);
            if (iVar4 == 0) {
              return 0;
            }
            iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_28,local_c);
          } while (iVar4 != 0);
          uVar1 = 0;
        }
        else {
          if (param_3 < local_10) {
            iVar2 = local_10 - param_3;
            for (local_14 = local_2c; local_14 < local_1c; local_14 = (void *)((int)local_14 + 1)) {
              iVar4 = js_arraySlice(param_1,(uint)param_1,(uint)local_14,&local_8);
              if (iVar4 == 0) {
                return 0;
              }
              iVar4 = js_arraySlice(param_1,(uint)param_1,(int)local_14 - iVar2,&local_28);
              if (iVar4 == 0) {
                return 0;
              }
              iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8);
              if (iVar4 == 0) {
                return 0;
              }
              iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_28,local_c)
              ;
              if (iVar4 == 0) {
                return 0;
              }
            }
            local_1c = (void *)((int)local_1c - iVar2);
          }
LAB_681377a3:
          for (local_24 = 0; local_24 < param_3; local_24 = local_24 + 1) {
            iVar2 = js_arraySlice((void *)((int)local_18 + local_24),(uint)param_1,
                                 (int)local_18 + local_24,&local_8);
            if (iVar2 == 0) {
              return 0;
            }
            iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,local_8);
            if (iVar2 == 0) {
              return 0;
            }
          }
          uVar1 = js_arrayPush((int)param_1,param_2,(uint)local_1c);
        }
      }
    }
  }
  return uVar1;
}



// ============================================================
// Function: javascript_arrayConcat (FUN_68137820)
// Address: 68137820
// Size: 501 bytes
// Params: ushort * param_1, undefined4 param_2, uint param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_arrayConcat(ushort *param_1,undefined4 param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint local_28;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_10 = js_arrayEnsureCapacity(param_1,0,0);
  if (local_10 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    *param_5 = local_10;
    local_14 = 0;
    for (local_18 = 0; local_18 <= param_3; local_18 = local_18 + 1) {
      local_c = *(uint *)(param_4 + -4 + local_18 * 4);
      if ((((local_c & 7) == 0) && (piVar3 = (int *)(local_c & 0xfffffff8), piVar3 != (int *)0x0))
         && ((undefined **)(*(uint *)(piVar3[1] + 8) & 0xfffffffe) == &PTR_s_Array_681939b8)) {
        iVar2 = (**(code **)(*(int *)(*piVar3 + 4) + 0x10))
                          (param_1,piVar3,*(undefined4 *)(*(int *)(param_1 + 10) + 0x108),&local_c);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = javascript_parseArrayLength(param_1,local_c,&local_1c);
        if (iVar2 == 0) {
          return 0;
        }
        for (local_28 = 0; local_28 < local_1c; local_28 = local_28 + 1) {
          iVar2 = js_arraySlice(param_1,(uint)param_1,local_28,&local_8);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = js_arraySlice(param_1,(uint)param_1,local_14 + local_28,&local_20);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = (**(code **)(*(int *)(*piVar3 + 4) + 0x10))(param_1,piVar3,local_8,&local_c);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = (**(code **)(*(int *)(*local_10 + 4) + 0x14))(param_1,local_10,local_20,&local_c);
          if (iVar2 == 0) {
            return 0;
          }
        }
        local_14 = local_14 + local_1c;
      }
      else {
        iVar2 = js_arraySlice(&local_8,(uint)param_1,local_14,&local_8);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(*(int *)(*local_10 + 4) + 0x14))(param_1,local_10,local_8,&local_c);
        if (iVar2 == 0) {
          return 0;
        }
        local_14 = local_14 + 1;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: javascript_arraySliceRange (FUN_68137a20)
// Address: 68137a20
// Size: 633 bytes
// Params: ushort * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arraySliceRange(ushort *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  void *local_7c;
  void *local_54;
  double local_2c;
  void *local_24;
  void *local_20;
  uint local_1c;
  void *local_18;
  void *local_14;
  int *local_10;
  undefined1 local_c [4];
  uint local_8;
  
  local_10 = js_arrayEnsureCapacity(param_1,0,0);
  if (local_10 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar2 = js_arrayToString(param_1,param_2,(int *)&local_18);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      local_14 = (void *)0x0;
      local_20 = local_18;
      if (param_3 != 0) {
        iVar2 = runtime_parseNumber(param_1,*param_4,&local_2c);
        if (iVar2 == 0) {
          return 0;
        }
        fVar3 = runtime_powFloat(SUB84(local_2c,0),(uint)((ulonglong)local_2c >> 0x20));
        local_2c = (double)fVar3;
        if (0.0 <= local_2c) {
          if ((double)(size_t)local_18 /* FIXUP(C2440): double via size_t */ < local_2c) {
            local_2c = (double)(size_t)local_18 /* FIXUP(C2440): double via size_t */;
          }
        }
        else {
          local_2c = (double)(size_t)local_18 /* FIXUP(C2440): double via size_t */ + local_2c;
          if (local_2c < 0.0) {
            local_2c = 0.0;
          }
        }
        local_54 = (void *)(longlong)ROUND(local_2c);
        local_14 = local_54;
        if (1 < param_3) {
          iVar2 = runtime_parseNumber(param_1,param_4[1],&local_2c);
          if (iVar2 == 0) {
            return 0;
          }
          fVar3 = runtime_powFloat(SUB84(local_2c,0),(uint)((ulonglong)local_2c >> 0x20));
          local_2c = (double)fVar3;
          if (0.0 <= local_2c) {
            if ((double)(size_t)local_18 /* FIXUP(C2440): double via size_t */ < local_2c) {
              local_2c = (double)(size_t)local_18 /* FIXUP(C2440): double via size_t */;
            }
          }
          else {
            local_2c = (double)(size_t)local_18 /* FIXUP(C2440): double via size_t */ + local_2c;
            if (local_2c < 0.0) {
              local_2c = 0.0;
            }
          }
          local_7c = (void *)(longlong)ROUND(local_2c);
          local_20 = local_7c;
        }
      }
      for (local_24 = local_14; local_24 < local_20; local_24 = (void *)((int)local_24 + 1)) {
        iVar2 = js_arraySlice(local_24,(uint)param_1,(uint)local_24,&local_8);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = js_arraySlice((void *)((int)local_24 - (int)local_14),(uint)param_1,
                             (uint)((int)local_24 - (int)local_14),&local_1c);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,local_8);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(*(int *)(*local_10 + 4) + 0x14))(param_1,local_10,local_1c,local_c);
        if (iVar2 == 0) {
          return 0;
        }
      }
      *param_5 = local_10;
      uVar1 = 1;
    }
  }
  return uVar1;
}



// ============================================================
// Function: javascript_computeEpochOffset (FUN_68137ca0)
// Address: 68137ca0
// Size: 91 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_computeEpochOffset(void)
{
  struct tm local_2c;
  uint local_8;
  
  (*((int *)&local_2c + 0)) = 0;
  (*((int *)&local_2c + 1)) = 0;
  (*((int *)&local_2c + 2)) = 0;
  (*((int *)&local_2c + 4)) = 0;
  (*((int *)&local_2c + 6)) = 0;
  (*((int *)&local_2c + 7)) = 0;
  (*((int *)&local_2c + 8)) = 0;
  (*((int *)&local_2c + 3)) = 2;
  (*((int *)&local_2c + 5)) = 0x46;
  _mktime64(&local_2c);
  return 0;
}



// ============================================================
// Function: javascript_getTimeMicroseconds (FUN_68137d00)
// Address: 68137d00
// Size: 55 bytes
// Params: int param_1
// Return: longlong
// Calling convention: __stdcall
// ============================================================

longlong javascript_getTimeMicroseconds(int param_1)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = javascript_computeEpochOffset();
  lVar2 = __allmul(0x79732a80 - uVar1,(0xe - ((int)uVar1 >> 0x1f)) - (uint)(0x79732a80 < uVar1),
                   1000000,0);
  return lVar2 + param_1;
}



// ============================================================
// Function: js_gcMarkRoots (FUN_68137d40)
// Address: 68137d40
// Size: 74 bytes
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 js_gcMarkRoots(void)

{
  undefined8 uVar1;
  FILETIME local_14;
  FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  if ((*((unsigned int *)&local_c)) == 0) {
    GetSystemTimeAsFileTime(&local_14);
    (*((unsigned int *)&local_c + 1)) = (*((unsigned int *)&local_14 + 1));
  }
  uVar1 = __alldiv((*((unsigned int *)&local_c)) + 0x2ac18000,
                   ((*((unsigned int *)&local_c + 1)) + 0xfe624e22) -
                   (uint)((*((unsigned int *)&local_c)) < 0xd53e8000),10,0);
  return uVar1;
}



// ============================================================
// Function: javascript_formatTimeStruct (FUN_68137d90)
// Address: 68137d90
// Size: 160 bytes
// Params: char * param_1, size_t param_2, char * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_formatTimeStruct(char *param_1,size_t param_2,char *param_3,int param_4)
{
  struct tm local_2c;
  uint local_8;
  
  (*((int *)&local_2c + 0)) = (int)*(char *)(param_4 + 4);
  (*((int *)&local_2c + 1)) = (int)*(char *)(param_4 + 5);
  (*((int *)&local_2c + 2)) = (int)*(char *)(param_4 + 6);
  (*((int *)&local_2c + 3)) = (int)*(char *)(param_4 + 7);
  (*((int *)&local_2c + 4)) = (int)*(char *)(param_4 + 8);
  (*((int *)&local_2c + 6)) = (int)*(char *)(param_4 + 9);
  (*((int *)&local_2c + 5)) = *(short *)(param_4 + 10) + -0x76c;
  (*((int *)&local_2c + 7)) = (int)*(short *)(param_4 + 0xc);
  (*((int *)&local_2c + 8)) = (int)*(char *)(param_4 + 0xe);
  strftime(param_1,param_2,param_3,&local_2c);
  return 0;
}



// ============================================================
// Function: javascript_decomposeTimestamp (FUN_68137e30)
// Address: 68137e30
// Size: 565 bytes
// Params: undefined4 param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_decomposeTimestamp(undefined4 param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *unaff_ESI;
  uint uVar5;
  bool bVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint local_18;
  int local_14;
  int local_10;
  undefined1 local_c;
  int local_8;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  local_8 = 0;
  bVar2 = false;
  lVar7 = javascript_getTimeMicroseconds(0);
  lVar7 = __alldiv((uint)lVar7,(uint)((ulonglong)lVar7 >> 0x20),1000000,0);
  lVar7 = lVar7 + CONCAT44(param_2,param_1);
  do {
    uVar5 = (uint)((ulonglong)lVar7 >> 0x20);
    uVar4 = (uint)lVar7;
    if (bVar2) {
      if (lVar7 < 0) {
LAB_68137f4b:
        uVar8 = __alldiv(uVar4,uVar5,0x15180,0);
        param_2 = (uint)uVar8;
        while( true ) {
          if ((local_10 == 1) && (bVar2)) {
            iVar3 = DAT_68193acc + 1;
          }
          else {
            iVar3 = *(int *)(&DAT_68193ac8 + local_10 * 4);
          }
          if ((int)param_2 < iVar3) break;
          iVar3 = *(int *)(&DAT_68193ac8 + local_10 * 4);
          local_14 = local_14 + iVar3;
          local_8 = local_8 + iVar3;
          param_2 = param_2 - iVar3;
          if ((local_10 == 1) && (bVar2)) {
            local_14 = local_14 + 1;
            local_8 = local_8 + 1;
            param_2 = param_2 - 1;
          }
          local_10 = local_10 + 1;
        }
        lVar9 = __allmul((uint)uVar8,(int)((ulonglong)uVar8 >> 0x20),0xfffeae80,-1);
        lVar7 = lVar7 + lVar9;
        iVar1 = param_2 + 1;
        uVar8 = __alldiv((uint)lVar7,(uint)((ulonglong)lVar7 >> 0x20),0xe10,0);
        lVar9 = __allmul((uint)uVar8,(int)((ulonglong)uVar8 >> 0x20),0xfffff1f0,-1);
        lVar7 = lVar7 + lVar9;
        uVar10 = __alldiv((uint)lVar7,(uint)((ulonglong)lVar7 >> 0x20),0x3c,0);
        *(char *)((int)unaff_ESI + 5) = (char)uVar10;
        local_c = (undefined1)uVar8;
        *(undefined1 *)((int)unaff_ESI + 6) = local_c;
        iVar3 = local_8 + 6 + iVar1;
        *(undefined1 *)(unaff_ESI + 2) = (undefined1)local_10;
        *(char *)((int)unaff_ESI + 7) = (char)iVar1;
        *(char *)(unaff_ESI + 1) = (char)lVar7 + (char)uVar10 * -0x3c;
        *unaff_ESI = 0;
        *(short *)(unaff_ESI + 3) = (short)iVar1 + (short)local_14;
        *(char *)((int)unaff_ESI + 9) = (char)(iVar3 % 7);
        *(undefined2 *)((int)unaff_ESI + 10) = (undefined2)local_18;
        return iVar3 / 7;
      }
      if (uVar5 == 0) {
        bVar6 = uVar4 < 0x1e28500;
        goto LAB_68137e8e;
      }
    }
    else {
      if (lVar7 < 0) goto LAB_68137f4b;
      if (uVar5 == 0) {
        bVar6 = uVar4 < 0x1e13380;
LAB_68137e8e:
        if (bVar6) goto LAB_68137f4b;
      }
    }
    lVar7 = lVar7 + -0x1e13380;
    iVar3 = local_8 + 0x16d;
    if ((local_18 != 0) &&
       ((((local_18 & 3) == 0 && (local_18 != ((int)local_18 / 100) * 100)) ||
        (local_18 == ((int)local_18 / 400) * 400)))) {
      lVar7 = CONCAT44((int)((ulonglong)lVar7 >> 0x20) + -1 + (uint)(0x1517f < (uint)lVar7),
                       uVar4 + 0xfe1d7b00);
      iVar3 = local_8 + 0x16e;
    }
    local_8 = iVar3;
    local_18 = local_18 + 1;
    if ((local_18 == 0) ||
       ((((local_18 & 3) != 0 || (local_18 == ((int)local_18 / 100) * 100)) &&
        (local_18 != ((int)local_18 / 400) * 400)))) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  } while( true );
}



// ============================================================
// Function: javascript_getTimezoneOffset (FUN_68138070)
// Address: 68138070
// Size: 197 bytes
// Params: uint param_1, uint param_2
// Return: longlong
// Calling convention: __stdcall
// ============================================================

longlong javascript_getTimezoneOffset(uint param_1,uint param_2)

{
  uint uVar1;
  struct tm *ptVar2;
  int iVar3;
  int *piVar4;
  ulonglong uVar5;
  longlong lVar6;
  int local_38 [10];
  char local_f;
  char local_e;
  
  uVar5 = __alldiv(param_1,param_2,1000000,0);
  if ((longlong)uVar5 < 0) {
LAB_681380a8:
    uVar1 = 0x15180;
  }
  else {
    if (((int)(uVar5 >> 0x20) == 0) && ((uint)uVar5 < 0x7fe73681)) {
      if (-1 < (longlong)uVar5) goto LAB_681380af;
      goto LAB_681380a8;
    }
    uVar1 = 0x7fe73680;
  }
  uVar5 = (ulonglong)uVar1;
LAB_681380af:
  param_1 = (uint)uVar5;
  param_2 = 0;
  javascript_decomposeTimestamp(param_1,(uint)(uVar5 >> 0x20));
  ptVar2 = _localtime64((__time64_t *)&param_1);
  /* FIXUP(C2065: undeclared 'tm'): if (ptVar2 != (tm *)0x0) { */
    piVar4 = local_38;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = (*((int *)ptVar2 + 0));
      /* FIXUP(C2065: undeclared 'tm'): ptVar2 = (tm *)&(*((int *)ptVar2 + 1)); */
      piVar4 = piVar4 + 1;
    }
    uVar1 = (((local_38[2] - local_e) * 0x3c - (int)local_f) + local_38[1]) * 0x3c;
    if ((int)uVar1 < 0) {
      uVar1 = uVar1 + 0x15180;
    }
    lVar6 = __allmul(uVar1,(int)uVar1 >> 0x1f,1000000,0);
    return lVar6;
  }
  /* FIXUP(C2099): lVar6 = crypto_getStoredFloat(); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return lVar6; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



