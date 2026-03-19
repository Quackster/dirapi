// Module: strings
// Topic: Property hash table management - hash lookup, insertion, deletion, rehashing
// Address range: 0x681617a0 - 0x68163510
// Functions (23):
//   strings_searchTable
//   strings_getTableEntry
//   strings_insertTableEntry
//   strings_removeTableEntry
//   strings_freeTableEntry (FUN_68161c50)
//   strings_lookupInTable
//   strings_hashTableEntry (FUN_68161e50)
//   strings_compareTableEntry (FUN_68161f30)
//   strings_createTableEntry
//   strings_compactTable
//   strings_rehashTable (FUN_68162700)
//   strings_expandTable
//   strings_allocTableSlot (FUN_68162a80)
//   strings_mergeTable
//   strings_allocTableNode (FUN_68162ca0)
//   strings_reportReadOnly (FUN_68162cd0)
//   strings_addTableRange
//   strings_setTableValue
//   strings_clearTable (FUN_68163070)
//   strings_sweepTable (FUN_681630b0)
//   strings_unlinkTableEntry (FUN_68163300)
//   strings_initPropertyTable (FUN_681634b0)
//   strings_destroyPropertyTable (FUN_68163510)

// ============================================================
// Function: strings_searchTable (FUN_681617a0)
// Address: 681617a0
// Size: 903 bytes
// Params: uint param_1, int * param_2, uint param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_searchTable(uint param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  undefined **local_38;
  undefined **local_34;
  int local_30;
  uint *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int *local_c;
  undefined4 *local_8;
  
  if (param_3 == 0x80000001) {
    local_28 = xtra_resolvePath(param_1,param_2);
    if (local_28 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      local_18 = 1;
      if (*local_28 != 0) {
LAB_68161924:
        local_24 = *(int **)(*(int *)(param_1 + 0x34) + 8);
        local_10 = 0;
        do {
          if (local_28 == (int *)0x0) {
LAB_68161984:
            local_18 = (**(code **)(*(int *)(*param_2 + 4) + 0x2c))
                                 (param_1,param_2,param_3,2,&local_c,&local_1c);
            if (local_18 == 0) {
              local_18 = 0;
              break;
            }
            piVar1 = local_c;
            if (((((uint)local_c & 7) == 0) && (((uint)local_c & 0xfffffff8) != 0)) &&
               ((undefined **)
                (*(uint *)(*(int *)(((uint)local_c & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
                &PTR_s_Function_681928b8)) {
              local_8 = (undefined4 *)((uint)local_c & 0xfffffff8);
              local_20 = runtime_lookupFunction(param_1,local_8,(uint)param_2);
              piVar1 = local_20;
              if (local_20 == (int *)0x0) {
                local_18 = 0;
                break;
              }
            }
            local_c = piVar1;
            if ((undefined **)(*(uint *)(local_24[1] + 8) & 0xfffffffe) == &PTR_DAT_68192810) {
              local_18 = (**(code **)(*(int *)(*local_24 + 4) + 8))
                                   (param_1,local_24,param_3,&local_14,&local_30);
              if (local_18 == 0) {
                local_18 = 0;
                break;
              }
            }
            else {
              local_30 = 0;
            }
            if ((local_30 == 0) || (local_24 != local_14)) {
              local_18 = (**(code **)(*(int *)(*local_24 + 4) + 0xc))
                                   (param_1,local_24,param_3,local_c,0,0,local_1c & 0xfffffff7,0);
            }
            else {
              local_18 = (**(code **)(*(int *)(*local_24 + 4) + 0x14))
                                   (param_1,local_24,param_3,&local_c);
            }
            if ((local_30 != 0) && (*(int *)(*(int *)(*local_14 + 4) + 0x34) != 0)) {
              (**(code **)(*(int *)(*local_14 + 4) + 0x34))(param_1,local_14,local_30);
            }
            if (local_18 == 0) break;
          }
          else {
            param_3 = local_28[local_10 + 1];
            local_18 = (**(code **)(*(int *)(*param_2 + 4) + 0x18))
                                 (param_1,param_2,param_3,0,&local_1c);
            if (local_18 == 0) break;
            if ((local_1c & 8) != 0) goto LAB_68161984;
          }
          if ((local_28 == (int *)0x0) || (local_10 = local_10 + 1, *local_28 <= local_10)) break;
        } while( true );
      }
      if (local_28 != (int *)0x0) {
        xtra_flushAndCheck(param_1,(int)local_28);
      }
    }
  }
  else {
    local_28 = (int *)0x0;
    iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 8))(param_1,param_2,param_3,&local_14,&local_30);
    if (iVar2 == 0) {
      local_18 = 0;
    }
    else if (local_30 == 0) {
      if ((param_3 & 1) == 0) {
        local_34 = *(undefined ***)(param_3 + 8);
      }
      else {
        local_34 = (undefined **)param_3;
      }
      local_2c = crypto_decompileExpr(param_1,(int *)0x0,local_34,(uint *)0x0);
      if (local_2c != (uint *)0x0) {
        puVar3 = xtra_getStringValue(local_2c);
        runtime_addBreakpoint(param_1,puVar3);
      }
      local_18 = 0;
    }
    else {
      local_18 = (**(code **)(*(int *)(*param_2 + 4) + 0x18))
                           (param_1,param_2,param_3,local_30,&local_1c);
      if (*(int *)(*(int *)(*local_14 + 4) + 0x34) != 0) {
        (**(code **)(*(int *)(*local_14 + 4) + 0x34))(param_1,local_14,local_30);
      }
      if (local_18 == 0) {
        local_18 = 0;
      }
      else {
        if ((local_1c & 8) != 0) goto LAB_68161924;
        if ((param_3 & 1) == 0) {
          local_38 = *(undefined ***)(param_3 + 8);
        }
        else {
          local_38 = (undefined **)param_3;
        }
        local_2c = crypto_decompileExpr(param_1,(int *)0x0,local_38,(uint *)0x0);
        if (local_2c != (uint *)0x0) {
          xtra_getStringValue(local_2c);
          xtra_invokeMethod(param_1,xtra_getErrorString,0,0x19);
        }
        local_18 = 0;
      }
    }
  }
  return local_18;
}



// ============================================================
// Function: strings_getTableEntry (FUN_68161b30)
// Address: 68161b30
// Size: 125 bytes
// Params: int param_1, undefined4 * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * strings_getTableEntry(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_2;
  if ((undefined4 *)piVar3[4] != param_2) {
    piVar1 = strings_insertTableEntry(param_1,0,piVar3[1],*(uint *)(param_2[1] + 8) & 0xfffffffe,param_2);
    if (piVar1 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      uVar2 = runtime_freePropertyTable(param_1,piVar1);
      *param_2 = uVar2;
      runtime_resolvePropertyRef(param_1,piVar3,(int)param_2);
      piVar3 = piVar1;
    }
  }
  return piVar3;
}



// ============================================================
// Function: strings_insertTableEntry (FUN_68161bb0)
// Address: 68161bb0
// Size: 85 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
/* FIXUP(C2040: 'strings_insertTableEntry': 'undefined4 *(int,undefined4,undefined4,int,undefined4)' differs in levels of indirection from 'int ()'): strings_insertTableEntry(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5) */

/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '{'): { */
  /* FIXUP(missing brace - Ghidra artifact): undefined4 *puVar1; */
  
  /* FIXUP(C2040: 'puVar1': 'int' differs in levels of indirection from 'int *'): puVar1 = (undefined4 *)xtra_getPropertyById(param_1,0x28); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'if'): if (puVar1 == (undefined4 *)0x0) { */
    puVar1 = (undefined4 *)0x0;
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'else'): else { */
    runtime_initPropertyVtable(puVar1,param_2,param_3,param_4);
    /* FIXUP(C2372: 'puVar1': redefinition; different types of indirection): puVar1[4] = param_5; */
    /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '<parameter-list>'): *(undefined2 *)(puVar1 + 5) = 0; */
    /* FIXUP(missing paren - Ghidra artifact): strings_removeTableEntry((int)puVar1); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return puVar1; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: strings_removeTableEntry (FUN_68161c10)
// Address: 68161c10
// Size: 59 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_removeTableEntry(int param_1)
{
  *(undefined2 *)(param_1 + 0x16) = 0x1c;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return 0;
}



// ============================================================
// Function: strings_freeTableEntry (FUN_68161c50)
// Address: 68161c50
// Size: 45 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_freeTableEntry(undefined4 param_1,int param_2)
{
  if (*(int *)(param_2 + 0x20) != 0) {
    xtra_checkAndFlush(param_1,*(int *)(param_2 + 0x20));
  }
  xtra_checkAndFlush(param_1,param_2);
  return 0;
}



// ============================================================
// Function: strings_lookupInTable (FUN_68161c80)
// Address: 68161c80
// Size: 455 bytes
// Params: int param_1, uint param_2, int param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * strings_lookupInTable(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  byte bVar3;
  int local_30;
  uint local_20;
  uint *local_10;
  uint *local_8;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    local_8 = (uint *)(param_1 + 0x24);
    while ((puVar2 = (uint *)*local_8, puVar2 != (uint *)0x0 && (*puVar2 != param_2))) {
      local_8 = puVar2 + 5;
    }
  }
  else {
    if ((param_2 & 1) == 0) {
      local_30 = *(int *)(param_2 + 0x14);
    }
    else {
      local_30 = (int)param_2 >> 1;
    }
    bVar3 = (byte)*(undefined2 *)(param_1 + 0x16);
    local_20 = (uint)(local_30 * -0x61c88647) >> (bVar3 & 0x1f);
    local_8 = (uint *)(*(int *)(param_1 + 0x20) + local_20 * 4);
    uVar1 = *local_8;
    if ((uVar1 != 0) &&
       ((puVar2 = (uint *)(uVar1 & 0xfffffffe), puVar2 == (uint *)0x0 || (*puVar2 != param_2)))) {
      local_10 = local_8;
      if ((uVar1 != 1) && ((local_10 = (uint *)0x0, param_3 != 0 && ((uVar1 & 1) == 0)))) {
        *local_8 = (uint)puVar2 | 1;
      }
      while( true ) {
        local_20 = local_20 -
                   ((uint)(local_30 * -0x61c88647 << (0x20 - bVar3 & 0x1f)) >> (bVar3 & 0x1f) | 1) &
                   (1 << (0x20 - bVar3 & 0x1f)) - 1U;
        local_8 = (uint *)(*(int *)(param_1 + 0x20) + local_20 * 4);
        uVar1 = *local_8;
        if (uVar1 == 0) break;
        puVar2 = (uint *)(uVar1 & 0xfffffffe);
        if ((puVar2 != (uint *)0x0) && (*puVar2 == param_2)) {
          return local_8;
        }
        if (uVar1 == 1) {
          if (local_10 == (uint *)0x0) {
            local_10 = local_8;
          }
        }
        else if ((param_3 != 0) && ((uVar1 & 1) == 0)) {
          *local_8 = (uint)puVar2 | 1;
        }
      }
      if ((param_3 != 0) && (local_10 != (uint *)0x0)) {
        local_8 = local_10;
      }
    }
  }
  return local_8;
}



// ============================================================
// Function: strings_hashTableEntry (FUN_68161e50)
// Address: 68161e50
// Size: 224 bytes
// Params: undefined4 param_1, uint * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint strings_hashTableEntry(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint local_c;
  
  local_c = 0;
  if (param_2[1] != 0) {
    local_c = param_2[1];
  }
  if (param_2[2] != 0) {
    local_c = local_c >> 0x1c ^ local_c << 4 ^ param_2[2];
  }
  uVar1 = (local_c >> 0x1c ^ local_c << 4 ^ *(byte *)((int)param_2 + 0x11) & 0xfffffffc) << 4;
  uVar1 = uVar1 >> 0x1c ^ ((local_c << 4) >> 0x1c ^ uVar1 ^ (uint)(byte)param_2[4]) << 4 ^
          (int)*(short *)((int)param_2 + 0x12);
  uVar1 = uVar1 >> 0x1c ^ uVar1 << 4 ^ param_2[3];
  return uVar1 >> 0x1c ^ uVar1 << 4 ^ *param_2;
}



// ============================================================
// Function: strings_compareTableEntry (FUN_68161f30)
// Address: 68161f30
// Size: 163 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_compareTableEntry(undefined4 param_1,int param_2,int *param_3)

{
  int *piVar1;
  undefined4 local_14;
  
  piVar1 = *(int **)(param_2 + 4);
  if ((((*piVar1 == *param_3) && (piVar1[1] == param_3[1])) && (piVar1[2] == param_3[2])) &&
     (((piVar1[3] == param_3[3] && ((char)piVar1[4] == (char)param_3[4])) &&
      ((((*(byte *)((int)piVar1 + 0x11) ^ *(byte *)((int)param_3 + 0x11)) & 0xfc) == 0 &&
       (*(short *)((int)piVar1 + 0x12) == *(short *)((int)param_3 + 0x12))))))) {
    local_14 = 1;
  }
  else {
    local_14 = 0;
  }
  return local_14;
}




/* Restored from original Ghidra decompilation (was damaged by fixup passes) */
// ============================================================

undefined4 *
strings_insertTableEntry(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)xtra_getPropertyById(param_1,0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    runtime_initPropertyVtable(puVar1,param_2,param_3,param_4);
    puVar1[4] = param_5;
    *(undefined2 *)(puVar1 + 5) = 0;
    strings_removeTableEntry((int)puVar1);
  }
  return puVar1;
}
// ============================================================
// Function: strings_createTableEntry (FUN_68161fe0)
// Address: 68161fe0
// Size: 1625 bytes
// Params: uint param_1, int param_2, uint param_3, undefined * param_4, undefined * param_5, int param_6, uint param_7, uint param_8, int param_9
// Return: int *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x68162633) */

int * strings_createTableEntry(uint param_1,int param_2,uint param_3,undefined *param_4,undefined *param_5,
                  int param_6,uint param_7,uint param_8,int param_9)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  void *_Src;
  int *piVar5;
  bool bVar6;
  uint *local_48;
  int *local_44;
  uint *local_40;
  uint local_3c;
  uint local_30;
  undefined *local_2c;
  undefined *local_28;
  int local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  uint local_14;
  void *local_10;
  uint local_c;
  uint *local_8;
  
  if ((*(ushort *)(param_2 + 0x14) & 2) != 0) {
    strings_reportReadOnly(param_1,param_2);
    return (int *)0x0;
  }
  if ((code *)param_4 == xtra_getPlatformVersion) {
    param_4 = (undefined *)0x0;
  }
  if ((code *)param_5 == xtra_getPlatformVersion) {
    param_5 = (undefined *)0x0;
  }
  local_8 = strings_lookupInTable(param_2,param_3,1);
  local_44 = (int *)(*local_8 & 0xfffffffe);
  if (local_44 == (int *)0x0) {
    uVar1 = 1 << (0x20U - (char)*(undefined2 *)(param_2 + 0x16) & 0x1f);
    if (uVar1 - (uVar1 >> 2) <= (uint)(*(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x1c))) {
      bVar6 = *(uint *)(param_2 + 0x1c) < uVar1 >> 2;
      local_14 = (uint)bVar6;
      iVar2 = strings_rehashTable(param_1,param_2,(ushort)bVar6);
      if ((iVar2 == 0) && (*(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x1c) == uVar1 - 1)) {
        return (int *)0x0;
      }
      local_8 = strings_lookupInTable(param_2,param_3,1);
    }
  }
  else {
    if ((((param_7 & 0x40) == 0) && (param_6 == -1)) &&
       ((uint)local_44[3] < *(uint *)(param_2 + 0xc))) {
      param_6 = local_44[3];
    }
    if (((((undefined *)local_44[1] == param_4) && ((undefined *)local_44[2] == param_5)) &&
        ((local_44[3] == param_6 &&
         ((*(byte *)(local_44 + 4) == param_7 &&
          (((*(byte *)((int)local_44 + 0x11) ^ param_8) & 0xfffffffc) == 0)))))) &&
       (*(short *)((int)local_44 + 0x12) == param_9)) {
      return local_44;
    }
    if ((param_8 & 2) == 0) {
      if (local_44 == *(int **)(param_2 + 0x24)) {
        do {
          *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
          if (((*(ushort *)(param_2 + 0x14) & 1) == 0) ||
             (puVar4 = *(uint **)(param_2 + 0x24), puVar4 == (uint *)0x0)) break;
          puVar3 = strings_lookupInTable(param_2,*puVar4,0);
        } while ((uint *)(*puVar3 & 0xfffffffe) != puVar4);
      }
      else if ((*(ushort *)(param_2 + 0x14) & 1) == 0) {
        if (*(int *)(param_2 + 0x20) == 0) {
          iVar2 = strings_compactTable(param_2);
          if (iVar2 == 0) {
            xtra_reportError(param_1);
            return (int *)0x0;
          }
          local_8 = strings_lookupInTable(param_2,param_3,1);
          local_44 = (int *)(*local_8 & 0xfffffffe);
        }
        *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) | 1;
      }
    }
    else {
      *(byte *)((int)local_44 + 0x11) = *(byte *)((int)local_44 + 0x11) | 2;
    }
    if (*(int *)(param_2 + 0x20) != 0) {
      *local_8 = *local_8 & 1;
    }
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
  }
  if ((*(ushort *)(param_2 + 0x14) & 1) != 0) {
    local_3c = *(uint *)(param_2 + 0x18);
    if (local_3c != 0) {
      local_10 = (void *)xtra_getPropertyById(param_1,local_3c << 2);
      if (local_10 == (void *)0x0) goto LAB_68162589;
      local_40 = *(uint **)(param_2 + 0x24);
      local_c = local_3c;
      do {
        puVar4 = strings_lookupInTable(param_2,*local_40,0);
        if ((*puVar4 & 0xfffffffe) != 0) {
          if (local_c == 0) {
            local_48 = local_40;
            do {
              puVar4 = strings_lookupInTable(param_2,*local_48,0);
              if ((*puVar4 & 0xfffffffe) != 0) {
                local_c = local_c + 1;
              }
              local_48 = (uint *)local_48[5];
            } while (local_48 != (uint *)0x0);
            _Src = (void *)xtra_allocJSString(param_1,(int)local_10,(local_3c + local_c) * 4);
            if (_Src == (void *)0x0) {
              xtra_checkAndFlush(param_1,(int)local_10);
              goto LAB_68162589;
            }
            local_10 = _Src;
            memmove((void *)((int)_Src + local_c * 4),_Src,local_3c << 2);
            local_3c = local_3c + local_c;
          }
          local_c = local_c - 1;
          *(uint **)((int)local_10 + local_c * 4) = local_40;
        }
        local_40 = (uint *)local_40[5];
      } while (local_40 != (uint *)0x0);
      do {
        if (*(uint **)(*(int *)((int)local_10 + local_c * 4) + 0x14) == local_40) {
          local_40 = *(uint **)((int)local_10 + local_c * 4);
        }
        else {
          local_40 = (uint *)strings_expandTable(param_1,(int)local_40,
                                          *(int **)((int)local_10 + local_c * 4));
          if (local_40 == (uint *)0x0) {
            xtra_checkAndFlush(param_1,(int)local_10);
            goto LAB_68162589;
          }
          puVar4 = strings_lookupInTable(param_2,*local_40,0);
          *puVar4 = *puVar4 & 1 | (uint)local_40;
        }
        local_c = local_c + 1;
      } while (local_c < local_3c);
      xtra_checkAndFlush(param_1,(int)local_10);
      *(uint **)(param_2 + 0x24) = local_40;
    }
    *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) & 0xfffe;
  }
  if ((param_8 & 4) == 0) {
    if ((param_7 & 0x40) == 0) {
      if ((param_6 == -1) &&
         (iVar2 = runtime_growPropertyTable(param_1,*(int **)(param_2 + 0x10),&param_6), iVar2 == 0))
      goto LAB_68162589;
    }
    else {
      param_6 = -1;
    }
  }
  if (((*(int *)(*(int *)(param_1 + 0x14) + 0x240) == *(int *)(param_1 + 0x14) + 0x240) ||
      (iVar2 = runtime_getWatchProperty(*(int *)(param_1 + 0x14),param_2), iVar2 == 0)) ||
     (param_5 = runtime_createWatchCallback(param_1,param_3,(byte)param_7,(int)param_5),
     param_5 != (undefined *)0x0)) {
    local_30 = param_3;
    local_2c = param_4;
    local_28 = param_5;
    local_24 = param_6;
    local_20 = (undefined1)param_7;
    local_1f = (undefined1)param_8;
    local_1e = (undefined2)param_9;
    piVar5 = strings_expandTable(param_1,*(int *)(param_2 + 0x24),(int *)&local_30);
    if (piVar5 != (int *)0x0) {
      if (*(int *)(param_2 + 0x20) != 0) {
        *local_8 = *local_8 & 1 | (uint)piVar5;
      }
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
      *(int **)(param_2 + 0x24) = piVar5;
      if (*(int *)(param_2 + 0x20) == 0) {
        if (5 < *(uint *)(param_2 + 0x18)) {
          strings_compactTable(param_2);
          return piVar5;
        }
        return piVar5;
      }
      return piVar5;
    }
  }
LAB_68162589:
  if (local_44 != (int *)0x0) {
    for (local_40 = *(uint **)(param_2 + 0x24); local_40 != (uint *)0x0;
        local_40 = (uint *)local_40[5]) {
      if (local_40 == (uint *)local_44) goto LAB_68162603;
    }
    if (local_44[5] == *(int *)(param_2 + 0x24)) {
      *(int **)(param_2 + 0x24) = local_44;
    }
    else {
      local_44 = strings_expandTable(param_1,*(int *)(param_2 + 0x24),local_44);
      if (local_44 != (int *)0x0) {
        *(int **)(param_2 + 0x24) = local_44;
      }
    }
LAB_68162603:
    if (local_44 != (int *)0x0) {
      if (*(int *)(param_2 + 0x20) != 0) {
        *local_8 = *local_8 & 1 | (uint)local_44;
      }
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
    }
  }
  return (int *)0x0;
}



// ============================================================
// Function: strings_compactTable (FUN_68162640)
// Address: 68162640
// Size: 183 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_compactTable(int param_1)

{
  int param_4;
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *local_10;
  short local_c;
  
  if (*(uint *)(param_1 + 0x18) < 7) {
    local_c = 4;
  }
  else {
    uVar1 = crypto_decompileNode(*(int *)(param_1 + 0x18) << 1);
    local_c = (short)uVar1;
    *(short *)(param_1 + 0x16) = 0x20 - local_c;
  }
  uVar2 = javascript_callocWrapper(1 << ((byte)local_c & 0x1f),4);
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    *(short *)(param_1 + 0x16) = 0x20 - local_c;
    for (local_10 = *(uint **)(param_1 + 0x24); local_10 != (uint *)0x0;
        local_10 = (uint *)local_10[5]) {
      puVar3 = strings_lookupInTable(param_1,*local_10,1);
      *puVar3 = *puVar3 & 1 | (uint)local_10;
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: strings_rehashTable (FUN_68162700)
// Address: 68162700
// Size: 245 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_rehashTable(int param_1,int param_2,short param_3)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  short sVar6;
  uint *puVar7;
  int local_10;
  uint *local_8;
  
  sVar6 = 0x20 - *(short *)(param_2 + 0x16);
  sVar2 = sVar6 + param_3;
  local_10 = 1 << ((byte)sVar6 & 0x1f);
  iVar3 = javascript_callocWrapper((1 << ((byte)sVar2 & 0x1f)) * 0x1c,1);
  if (iVar3 == 0) {
    xtra_reportError(param_1);
    uVar4 = 0;
  }
  else {
    *(short *)(param_2 + 0x16) = 0x20 - sVar2;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    puVar1 = *(uint **)(param_2 + 0x20);
    *(int *)(param_2 + 0x20) = iVar3;
    local_8 = puVar1;
    for (; local_10 != 0; local_10 = local_10 + -1) {
      puVar7 = (uint *)(*local_8 & 0xfffffffe);
      if (puVar7 != (uint *)0x0) {
        puVar5 = strings_lookupInTable(param_2,*puVar7,1);
        *puVar5 = (uint)puVar7;
      }
      local_8 = local_8 + 1;
    }
    xtra_checkAndFlush(param_1,(int)puVar1);
    uVar4 = 1;
  }
  return uVar4;
}



// ============================================================
// Function: strings_expandTable (FUN_68162800)
// Address: 68162800
// Size: 631 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * strings_expandTable(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint *local_18;
  uint local_c;
  uint local_8;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (param_2 == 0) {
    local_18 = js_getPropertySlot((int *)(iVar2 + 0x225c),param_3,1);
    if (local_18 == (uint *)0x0) goto LAB_68162a66;
    if ((int *)local_18[1] != (int *)0x0) {
      return (int *)local_18[1];
    }
  }
  else {
    local_18 = (uint *)0x0;
    piVar1 = *(int **)(param_2 + 0x18);
    if (piVar1 != (int *)0x0) {
      if (((uint)piVar1 & 1) == 0) {
        if ((((*piVar1 == *param_3) && (piVar1[1] == param_3[1])) && (piVar1[2] == param_3[2])) &&
           (((piVar1[3] == param_3[3] && ((char)piVar1[4] == (char)param_3[4])) &&
            ((((*(byte *)((int)piVar1 + 0x11) ^ *(byte *)((int)param_3 + 0x11)) & 0xfc) == 0 &&
             (*(short *)((int)piVar1 + 0x12) == *(short *)((int)param_3 + 0x12))))))) {
          return piVar1;
        }
      }
      else {
        local_c = (uint)piVar1 & 0xfffffffe;
        do {
          for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
            piVar1 = *(int **)(local_c + local_8 * 4);
            if (piVar1 == (int *)0x0) goto LAB_681629ba;
            if ((((*piVar1 == *param_3) && (piVar1[1] == param_3[1])) &&
                ((piVar1[2] == param_3[2] &&
                 (((piVar1[3] == param_3[3] && ((char)piVar1[4] == (char)param_3[4])) &&
                  (((*(byte *)((int)piVar1 + 0x11) ^ *(byte *)((int)param_3 + 0x11)) & 0xfc) == 0)))
                 ))) && (*(short *)((int)piVar1 + 0x12) == *(short *)((int)param_3 + 0x12))) {
              return piVar1;
            }
          }
          local_c = *(uint *)(local_c + 0x28);
        } while (local_c != 0);
      }
    }
  }
LAB_681629ba:
  piVar1 = (int *)strings_allocTableSlot(iVar2);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *param_3;
    piVar1[1] = param_3[1];
    piVar1[2] = param_3[2];
    piVar1[3] = param_3[3];
    *(char *)(piVar1 + 4) = (char)param_3[4];
    *(undefined1 *)((int)piVar1 + 0x11) = *(undefined1 *)((int)param_3 + 0x11);
    *(undefined2 *)((int)piVar1 + 0x12) = *(undefined2 *)((int)param_3 + 0x12);
    piVar1[6] = 0;
    piVar1[5] = 0;
    if (param_2 == 0) {
      local_18[1] = (uint)piVar1;
      return piVar1;
    }
    iVar2 = strings_mergeTable(iVar2,param_2,(uint)piVar1);
    if (iVar2 != 0) {
      return piVar1;
    }
  }
LAB_68162a66:
  xtra_reportError(param_1);
  return (int *)0x0;
}



// ============================================================
// Function: strings_allocTableSlot (FUN_68162a80)
// Address: 68162a80
// Size: 198 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_allocTableSlot(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_10;
  
  local_10 = *(int *)(param_1 + 0x227c);
  if (local_10 == 0) {
    iVar1 = *(int *)(param_1 + 0x2290);
    uVar2 = *(int *)(param_1 + 0x2298) + 0x1cU & ~*(uint *)(param_1 + 0x2298);
    local_10 = *(int *)(iVar1 + 0xc);
    uVar3 = local_10 + uVar2;
    if (*(uint *)(iVar1 + 8) < uVar3) {
      local_10 = js_getSlotIndex(param_1 + 0x2280,uVar2);
    }
    else {
      *(uint *)(iVar1 + 0xc) = uVar3;
    }
    if (local_10 == 0) {
      local_10 = 0;
    }
  }
  else {
    **(undefined4 **)(local_10 + 8) = *(undefined4 *)(local_10 + 4);
    if (*(int *)(local_10 + 4) != 0) {
      *(undefined4 *)(*(int *)(local_10 + 4) + 8) = *(undefined4 *)(local_10 + 8);
    }
  }
  return local_10;
}



// ============================================================
// Function: strings_mergeTable (FUN_68162b50)
// Address: 68162b50
// Size: 329 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_mergeTable(int param_1,int param_2,uint param_3)

{
  int param_4;
  uint *puVar1;
  uint local_14;
  uint *local_c;
  uint local_8;
  
  if (param_2 == 0) {
    puVar1 = js_getPropertySlot((int *)(param_1 + 0x225c),param_3,1);
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    if (puVar1[1] == 0) {
      puVar1[1] = param_3;
    }
  }
  else {
    local_c = (uint *)(param_2 + 0x18);
    local_14 = *local_c;
    if (local_14 != 0) {
      if ((local_14 & 1) == 0) {
        local_c = (uint *)strings_allocTableNode();
        if (local_c == (uint *)0x0) {
          return 0;
        }
        *(uint *)(param_2 + 0x18) = (uint)local_c | 1;
        *local_c = local_14;
        local_c = local_c + 1;
      }
      else {
        local_14 = local_14 & 0xfffffffe;
        do {
          for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
            local_c = (uint *)(local_14 + local_8 * 4);
            if (*local_c == 0) goto LAB_68162c7d;
          }
          puVar1 = (uint *)(local_14 + 0x28);
          local_14 = *puVar1;
        } while (local_14 != 0);
        local_c = (uint *)strings_allocTableNode();
        if (local_c == (uint *)0x0) {
          return 0;
        }
        *puVar1 = (uint)local_c;
      }
    }
LAB_68162c7d:
    *local_c = param_3;
  }
  *(int *)(param_3 + 0x14) = param_2;
  return 1;
}



// ============================================================
// Function: strings_allocTableNode (FUN_68162ca0)
// Address: 68162ca0
// Size: 35 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_allocTableNode(void)

{
  int iVar1;
  
  iVar1 = javascript_callocWrapper(1,0x2c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: strings_reportReadOnly (FUN_68162cd0)
// Address: 68162cd0
// Size: 96 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_reportReadOnly(uint param_1,int param_2)
{
  uint *puVar1;
  
  puVar1 = (uint *)certs_hashLookup(param_1,*(uint *)(param_2 + 0x10));
  if (puVar1 != (uint *)0x0) {
    xtra_getStringValue(puVar1);
  }
  xtra_invokeMethod(param_1,xtra_getErrorString,0,0x13);
  return 0;
}



// ============================================================
// Function: strings_addTableRange (FUN_68162d30)
// Address: 68162d30
// Size: 358 bytes
// Params: uint param_1, int param_2, uint * param_3, uint param_4, uint param_5, undefined * param_6, undefined * param_7
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * strings_addTableRange(uint param_1,int param_2,uint *param_3,uint param_4,uint param_5,
                   undefined *param_6,undefined *param_7)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_24;
  undefined *local_20;
  undefined *local_1c;
  uint local_18;
  undefined1 local_14;
  byte local_13;
  short local_12;
  
  uVar1 = param_4;
  uVar5 = (byte)param_3[4] & param_5;
  uVar6 = uVar5 | param_4;
  if ((code *)param_6 == xtra_getPlatformVersion) {
    param_6 = (undefined *)0x0;
  }
  if ((code *)param_7 == xtra_getPlatformVersion) {
    param_7 = (undefined *)0x0;
  }
  if ((((byte)param_3[4] != uVar6) || ((undefined *)param_3[1] != param_6)) ||
     (puVar3 = param_3, (undefined *)param_3[2] != param_7)) {
    local_24 = *param_3;
    local_20 = param_6;
    local_1c = param_7;
    local_18 = param_3[3];
    (*(unsigned char *)((char *)&param_4 + 0)) = (undefined1)uVar6;
    local_14 = (undefined1)param_4;
    local_13 = *(byte *)((int)param_3 + 0x11);
    local_12 = *(short *)((int)param_3 + 0x12);
    if (*(uint **)(param_2 + 0x24) == param_3) {
      if ((((param_3[4] & 0x40) == 0) || ((uVar6 & 0x40) != 0)) ||
         (iVar2 = runtime_growPropertyTable(param_1,*(int **)(param_2 + 0x10),&local_18), iVar2 != 0)) {
        puVar3 = (uint *)strings_expandTable(param_1,param_3[5],(int *)&local_24);
        if (puVar3 != (uint *)0x0) {
          puVar4 = strings_lookupInTable(param_2,*param_3,0);
          if (*(int *)(param_2 + 0x20) != 0) {
            *puVar4 = *puVar4 & 1 | (uint)puVar3;
          }
          *(uint **)(param_2 + 0x24) = puVar3;
        }
      }
      else {
        puVar3 = (uint *)0x0;
      }
    }
    else {
      puVar3 = (uint *)strings_createTableEntry(param_1,param_2,local_24,param_6,param_7,local_18,
                                    uVar5 | uVar1 & 0xff,(uint)local_13,(int)local_12);
    }
  }
  return puVar3;
}



// ============================================================
// Function: strings_setTableValue (FUN_68162ea0)
// Address: 68162ea0
// Size: 456 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_setTableValue(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint local_14;
  uint local_c;
  uint *local_8;
  
  if ((*(ushort *)(param_2 + 0x14) & 2) == 0) {
    local_8 = strings_lookupInTable(param_2,param_3,0);
    local_c = *local_8;
    local_14 = local_c & 0xfffffffe;
    if (local_14 == 0) {
      uVar2 = 1;
    }
    else {
      if ((*(int *)(param_2 + 0x20) == 0) && (local_14 != *(uint *)(param_2 + 0x24))) {
        iVar3 = strings_compactTable(param_2);
        if (iVar3 == 0) {
          xtra_reportError(param_1);
          return 0;
        }
        local_8 = strings_lookupInTable(param_2,param_3,0);
        local_c = *local_8;
        local_14 = local_c & 0xfffffffe;
      }
      if (*(uint *)(local_14 + 0xc) < *(uint *)(param_2 + 0xc)) {
        runtime_shrinkPropertyTable(param_1,*(int **)(param_2 + 0x10),*(int *)(local_14 + 0xc));
      }
      if ((local_c & 1) == 0) {
        if (*(int *)(param_2 + 0x20) != 0) {
          *local_8 = 0;
        }
      }
      else {
        *local_8 = 1;
        *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;
      }
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
      if (local_14 == *(uint *)(param_2 + 0x24)) {
        do {
          *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
          if (((*(ushort *)(param_2 + 0x14) & 1) == 0) ||
             (puVar1 = *(uint **)(param_2 + 0x24), puVar1 == (uint *)0x0)) break;
          puVar4 = strings_lookupInTable(param_2,*puVar1,0);
        } while ((uint *)(*puVar4 & 0xfffffffe) != puVar1);
      }
      else if ((*(ushort *)(param_2 + 0x14) & 1) == 0) {
        *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) | 1;
      }
      uVar5 = 1 << (0x20U - (char)*(undefined2 *)(param_2 + 0x16) & 0x1f);
      if ((0x10 < uVar5) && (*(uint *)(param_2 + 0x18) <= uVar5 >> 2)) {
        strings_rehashTable(param_1,param_2,-1);
      }
      uVar2 = 1;
    }
  }
  else {
    strings_reportReadOnly(param_1,param_2);
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: strings_clearTable (FUN_68163070)
// Address: 68163070
// Size: 54 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_clearTable(undefined4 param_1,int param_2)
{
  if (*(int *)(param_2 + 0x20) != 0) {
    js_freeHandle();
  }
  *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) & 0xfffe;
  strings_removeTableEntry(param_2);
  return 0;
}



// ============================================================
// Function: strings_sweepTable (FUN_681630b0)
// Address: 681630b0
// Size: 585 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_sweepTable(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *local_30;
  int *local_28;
  uint local_1c;
  int local_14;
  uint local_10;
  
  runtime_markWatchesDirty(param_1);
  piVar1 = (int *)(param_1 + 0x2280);
  while (local_30 = piVar1, piVar1 = (int *)*local_30, piVar1 != (int *)0x0) {
    piVar2 = (int *)piVar1[3];
    local_14 = 0;
    for (local_28 = (int *)piVar1[1]; local_28 < piVar2; local_28 = local_28 + 7) {
      if (*local_28 != 0) {
        if ((*(byte *)((int)local_28 + 0x11) & 1) == 0) {
          strings_unlinkTableEntry(param_1,(uint)local_28);
          local_1c = local_28[6];
          if (local_1c != 0) {
            local_28[6] = 0;
            iVar3 = local_28[5];
            if ((local_1c & 1) == 0) {
              strings_mergeTable(param_1,iVar3,local_1c);
            }
            else {
              local_1c = local_1c & 0xfffffffe;
              do {
                for (local_10 = 0;
                    (local_10 < 10 && (uVar4 = *(uint *)(local_1c + local_10 * 4), uVar4 != 0));
                    local_10 = local_10 + 1) {
                  strings_mergeTable(param_1,iVar3,uVar4);
                }
                local_1c = *(uint *)(local_1c + 0x28);
                javascript_arenaPoolReserve();
              } while (local_1c != 0);
            }
          }
          *local_28 = 0;
          local_28[1] = *(int *)(param_1 + 0x227c);
          local_28[2] = param_1 + 0x227c;
          if (*(int *)(param_1 + 0x227c) != 0) {
            *(int **)(*(int *)(param_1 + 0x227c) + 8) = local_28 + 1;
          }
          *(int **)(param_1 + 0x227c) = local_28;
        }
        else {
          *(byte *)((int)local_28 + 0x11) = *(byte *)((int)local_28 + 0x11) & 0xfe;
          local_14 = local_14 + 1;
        }
      }
    }
    if (local_14 == 0) {
      for (local_28 = (int *)piVar1[1]; local_28 < piVar2; local_28 = local_28 + 7) {
        *(int *)local_28[2] = local_28[1];
        if (local_28[1] != 0) {
          *(int *)(local_28[1] + 8) = local_28[2];
        }
      }
      if ((int *)*(int *)(param_1 + 0x2290) == piVar1) {
        *(int *)(param_1 + 0x2290) = param_1 + 0x2280;
      }
      *local_30 = *piVar1;
      js_freeHandle();
      piVar1 = local_30;
    }
  }
  return 0;
}



// ============================================================
// Function: strings_unlinkTableEntry (FUN_68163300)
// Address: 68163300
// Size: 427 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_unlinkTableEntry(int param_1,uint param_2)
{
  uint *puVar1;
  uint local_2c;
  uint local_28;
  uint *local_20;
  uint local_1c;
  int local_18;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_18 = *(int *)(param_2 + 0x14);
  if (local_18 == 0) {
    puVar1 = js_getPropertySlot((int *)(param_1 + 0x225c),param_2,0);
    if (puVar1[1] == param_2) {
      js_enumerateProperties((int *)(param_1 + 0x225c),puVar1);
    }
  }
  else {
    local_c = *(uint *)(local_18 + 0x18);
    if ((local_c & 1) == 0) {
      if (local_c == param_2) {
        *(undefined4 *)(local_18 + 0x18) = 0;
      }
    }
    else {
      local_1c = local_c & 0xfffffffe;
      local_20 = &local_1c;
      local_10 = local_1c;
      do {
        for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
          if (*(uint *)(local_10 + local_8 * 4) == param_2) {
            local_28 = local_10;
            if (*(int *)(local_10 + 0x28) == 0) {
              local_2c = local_8 + 1;
            }
            else {
              local_2c = 0;
              do {
                local_20 = (uint *)(local_28 + 0x28);
                local_28 = *local_20;
              } while (*(int *)(local_28 + 0x28) != 0);
            }
            for (; (local_2c < 10 && (*(int *)(local_28 + local_2c * 4) != 0));
                local_2c = local_2c + 1) {
            }
            local_2c = local_2c - 1;
            if ((local_10 != local_28) || (local_8 < local_2c)) {
              *(undefined4 *)(local_10 + local_8 * 4) = *(undefined4 *)(local_28 + local_2c * 4);
            }
            *(undefined4 *)(local_28 + local_2c * 4) = 0;
            if (local_2c != 0) {
              return 0;
            }
            *local_20 = 0;
            if (local_1c == 0) {
              *(undefined4 *)(local_18 + 0x18) = 0;
            }
            javascript_arenaPoolReserve();
            return 0;
          }
        }
        local_20 = (uint *)(local_10 + 0x28);
        local_10 = *local_20;
      } while (local_10 != 0);
    }
  }
  return 0;
}



// ============================================================
// Function: strings_initPropertyTable (FUN_681634b0)
// Address: 681634b0
// Size: 85 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool strings_initPropertyTable(int param_1)

{
  int iVar1;
  
  iVar1 = javascript_initHashTable((undefined4 *)(param_1 + 0x225c),&PTR_FUN_68182510,0,8,0x10);
  if (iVar1 != 0) {
    js_setPropertyDirect((undefined4 *)(param_1 + 0x2280),"properties",0x1c00,4);
  }
  else {
    *(undefined4 *)(param_1 + 0x225c) = 0;
  }
  return iVar1 != 0;
}



// ============================================================
// Function: strings_destroyPropertyTable (FUN_68163510)
// Address: 68163510
// Size: 61 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_destroyPropertyTable(int param_1)
{
  if (*(int *)(param_1 + 0x225c) != 0) {
    javascript_freeHashTable((int *)(param_1 + 0x225c));
    *(undefined4 *)(param_1 + 0x225c) = 0;
  }
  js_getPrototypeChain(param_1 + 0x2280);
  return 0;
}



