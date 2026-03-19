// Module: runtime
// Topic: String formatting (sprintf), buffer I/O, and GC traversal utilities
// Address range: 0x68125c30 - 0x68126a30
// Functions (14):
//   runtime_formatPrintf
//   runtime_appendToBuffer
//   runtime_sprintfAlloc
//   runtime_writeToFixedBuffer
//   runtime_formatToBuffer
//   runtime_strlen
//   runtime_snprintf
//   runtime_checkDebugFlag
//   runtime_getPropertyVtable
//   runtime_getObjectCount
//   runtime_getCharType
//   runtime_traverseGcRefs
//   runtime_beginGcTraversal
//   runtime_endGcTraversal

// ============================================================
// Function: runtime_formatPrintf (FUN_68125c30)
// Address: 68125c30
// Size: 1502 bytes
// Params: undefined4 * param_1, char * param_2, uint * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall runtime_formatPrintf(undefined4 *param_1,char *param_2,uint *param_3)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  code *pcVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  void *pvVar9;
  char *pcVar10;
  byte bVar11;
  size_t _Size;
  uint uVar12;
  bool bVar13;
  undefined8 uVar14;
  undefined *local_e8;
  char *local_e0;
  uint local_dc;
  uint local_d8;
  undefined8 local_d4;
  int local_cc;
  undefined4 *local_c8;
  uint local_c4;
  uint *local_c0;
  undefined1 local_bc [160];
  undefined1 local_1c;
  undefined1 local_1b [19];
  uint local_8;
  
  local_c0 = param_3;
  local_e0 = (char *)0x0;
  local_c8 = param_1;
  puVar3 = (undefined1 *)runtime_parseFormatArgs((int)param_3,&local_cc,(int)local_bc);
  if (-1 < local_cc) {
    cVar4 = *param_2;
    uVar14 = local_d4;
    puVar2 = local_c8;
    while (local_d4 = uVar14, local_c8 = puVar2, cVar4 != '\0') {
      pcVar10 = param_2 + 1;
      if (cVar4 != '%') {
        pcVar5 = (code *)*puVar2;
        uVar14 = CONCAT44(param_2,puVar2);
LAB_6812618f:
        local_cc = (*pcVar5)(uVar14,1);
        goto LAB_68126197;
      }
      cVar4 = *pcVar10;
      uVar8 = 0;
      pcVar10 = param_2 + 2;
      local_c4 = 0;
      if (cVar4 == '%') {
        pcVar5 = (code *)*puVar2;
        uVar14 = CONCAT44(param_2 + 1,puVar2);
        goto LAB_6812618f;
      }
      if (puVar3 == (undefined1 *)0x0) goto LAB_68125d30;
      iVar6 = 0;
      while ((cVar4 != '\0' && (cVar4 != '$'))) {
        iVar6 = cVar4 + -0x30 + iVar6 * 10;
        cVar4 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      }
      if (*(int *)(puVar3 + iVar6 * 8 + -8) == 0x14) {
        if (puVar3 != local_bc) {
          js_freeHandle();
        }
        return 0;
      }
      local_c0 = *(uint **)(puVar3 + iVar6 * 8 + -4);
      local_e0 = pcVar10;
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              cVar4 = *pcVar10;
              pcVar10 = pcVar10 + 1;
LAB_68125d30:
              if (cVar4 != '-') break;
              uVar8 = uVar8 | 1;
            }
            if (cVar4 != '+') break;
            uVar8 = uVar8 | 2;
          }
          if (cVar4 != ' ') break;
          uVar8 = uVar8 | 4;
        }
        if (cVar4 != '0') break;
        uVar8 = uVar8 | 8;
      }
      if ((uVar8 & 2) != 0) {
        uVar8 = uVar8 & 0xfffffffb;
      }
      local_c4 = uVar8;
      if ((uVar8 & 1) != 0) {
        local_c4 = uVar8 & 0xfffffff7;
      }
      if (cVar4 == '*') {
        cVar4 = *pcVar10;
        pvVar9 = (void *)*local_c0;
        pcVar10 = pcVar10 + 1;
        local_c0 = local_c0 + 1;
      }
      else {
        pvVar9 = (void *)0x0;
        while (('/' < cVar4 && (cVar4 < ':'))) {
          pvVar9 = (void *)(cVar4 + -0x30 + (int)pvVar9 * 10);
          cVar4 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        }
      }
      local_dc = 0xffffffff;
      if (cVar4 == '.') {
        cVar4 = *pcVar10;
        if (cVar4 == '*') {
          cVar4 = pcVar10[1];
          local_dc = *local_c0;
          pcVar10 = pcVar10 + 2;
          local_c0 = local_c0 + 1;
        }
        else {
          local_dc = 0;
          pcVar10 = pcVar10 + 1;
          while (('/' < cVar4 && (cVar4 < ':'))) {
            local_dc = cVar4 + -0x30 + local_dc * 10;
            cVar4 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          }
        }
      }
      bVar11 = 2;
      if (cVar4 == 'h') {
        bVar11 = 0;
LAB_68125e4d:
        cVar4 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      }
      else {
        if (cVar4 == 'L') {
LAB_68125e48:
          bVar11 = 6;
          goto LAB_68125e4d;
        }
        if (cVar4 == 'l') {
          cVar4 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          bVar11 = 4;
          if (cVar4 == 'l') goto LAB_68125e48;
        }
      }
      (*(unsigned int *)((char *)&local_d4 + 4)) = (undefined4)((ulonglong)uVar14 >> 0x20);
      local_e8 = PTR_s_0123456789abcdef_6819293c;
      switch(cVar4) {
      case 'E':
      case 'e':
      case 'f':
      case 'g':
        local_d4 = *(undefined8 *)local_c0;
        local_c0 = local_c0 + 2;
        if (puVar3 == (undefined1 *)0x0) {
          local_cc = runtime_formatFloat(param_2,local_d4,(int)pcVar10);
        }
        else {
          _Size = (int)pcVar10 - (int)local_e0;
          if ((int)_Size < 0x14) {
            local_1c = 0x25;
            memcpy(local_1b,local_e0,_Size);
            local_cc = runtime_formatFloat(&local_1c,local_d4,(int)(local_1b + _Size));
          }
        }
        goto LAB_68126197;
      default:
        iVar6 = (*(code *)*puVar2)(puVar2,&DAT_6817e884,1);
        if (-1 < iVar6) {
          pcVar5 = (code *)*puVar2;
          uVar14 = CONCAT44(pcVar10 + -1,puVar2);
          goto LAB_6812618f;
        }
        goto LAB_681261d5;
      case 'X':
        local_d8 = 0x10;
        local_e8 = PTR_s_0123456789ABCDEF_68192940;
        break;
      case 'c':
        uVar8 = *local_c0;
        local_c0 = local_c0 + 1;
        uVar12 = local_c4 & 1;
        local_d4 = CONCAT71((int7)((ulonglong)uVar14 >> 8),(char)uVar8);
        if (uVar12 == 0) {
          while (1 < (int)pvVar9) {
            pvVar9 = (void *)((int)pvVar9 + -1);
            iVar6 = (*(code *)*local_c8)(local_c8,&DAT_6817a910,1);
            if (iVar6 < 0) goto LAB_681261d5;
          }
          pvVar9 = (void *)((int)pvVar9 + -1);
        }
        local_cc = (*(code *)*local_c8)(local_c8,&local_d4,1);
        puVar2 = local_c8;
        if (-1 < local_cc) {
          uVar14 = local_d4;
          if (uVar12 != 0) {
            while (uVar14 = local_d4, 1 < (int)pvVar9) {
              pvVar9 = (void *)((int)pvVar9 + -1);
              local_cc = (*(code *)*puVar2)(puVar2,&DAT_6817a910,1);
              if (local_cc < 0) goto LAB_681261d5;
            }
          }
          goto LAB_6812619b;
        }
        goto LAB_681261d5;
      case 'd':
      case 'i':
        local_d8 = 10;
        goto LAB_68125e87;
      case 'n':
        puVar7 = local_c0 + 1;
        piVar1 = (int *)*local_c0;
        local_d4 = CONCAT44((*(unsigned int *)((char *)&local_d4 + 4)),piVar1);
        uVar14 = local_d4;
        local_c0 = puVar7;
        if (piVar1 != (int *)0x0) {
          *piVar1 = puVar2[2] - puVar2[1];
        }
        goto LAB_6812619b;
      case 'o':
        local_d8 = 8;
        break;
      case 'p':
        bVar11 = 5;
        local_d8 = 0x10;
        goto switchD_68125e96_switchD;
      case 's':
        uVar8 = *local_c0;
        local_c0 = local_c0 + 1;
        local_d4 = CONCAT44((*(unsigned int *)((char *)&local_d4 + 4)),uVar8);
        local_cc = runtime_formatString(local_c4,local_dc,puVar2,pvVar9,(byte)local_c4);
        goto LAB_68126197;
      case 'u':
        local_d8 = 10;
        break;
      case 'x':
        local_d8 = 0x10;
      }
      bVar11 = bVar11 | 1;
LAB_68125e87:
      if (7 < bVar11) goto LAB_6812619b;
switchD_68125e96_switchD:
      switch(bVar11) {
      case 0:
      case 2:
      case 4:
        uVar8 = *local_c0;
        local_d4 = CONCAT44((*(unsigned int *)((char *)&local_d4 + 4)),uVar8);
        if ((int)uVar8 < 0) {
          uVar8 = -uVar8;
          local_c4 = local_c4 | 0x10;
          break;
        }
        goto LAB_68126062;
      case 1:
        uVar8 = *local_c0 & 0xffff;
        break;
      default:
        uVar8 = *local_c0;
        break;
      case 6:
        uVar8 = *local_c0;
        uVar12 = local_c0[1];
        local_d4 = *(undefined8 *)local_c0;
        if (((int)uVar12 < 1) && ((int)uVar12 < 0)) {
          bVar13 = uVar8 != 0;
          uVar8 = -uVar8;
          uVar12 = -(uVar12 + bVar13);
          local_c4 = local_c4 | 0x10;
          goto LAB_681260e3;
        }
        goto LAB_681260e9;
      case 7:
        uVar8 = *local_c0;
        uVar12 = local_c0[1];
LAB_681260e3:
        local_d4 = CONCAT44(uVar12,uVar8);
LAB_681260e9:
        local_c0 = local_c0 + 2;
        local_cc = runtime_formatLongInt(puVar2,uVar8,uVar12,pvVar9,local_dc,local_d8,bVar11,(byte)local_c4,
                                (int)local_e8);
        goto LAB_68126197;
      }
      local_d4 = CONCAT44((*(unsigned int *)((char *)&local_d4 + 4)),uVar8);
LAB_68126062:
      local_c0 = local_c0 + 1;
      local_cc = runtime_formatInt(puVar2,(int)local_e8,uVar8,pvVar9,local_d8,bVar11,(byte)local_c4);
LAB_68126197:
      uVar14 = local_d4;
      if (local_cc < 0) goto LAB_681261d5;
LAB_6812619b:
      local_d4 = uVar14;
      param_1 = local_c8;
      param_2 = pcVar10;
      uVar14 = local_d4;
      puVar2 = local_c8;
      cVar4 = *pcVar10;
    }
    (*(code *)*param_1)(param_1,&DAT_6817a914,1);
    if ((puVar3 != (undefined1 *)0x0) && (puVar3 != local_bc)) {
      js_freeHandle();
    }
  }
LAB_681261d5:
  return 0;
}



// ============================================================
// Function: runtime_appendToBuffer (FUN_68126290)
// Address: 68126290
// Size: 137 bytes
// Params: int param_1, undefined1 * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_appendToBuffer(int param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8) - iVar1;
  if (*(uint *)(param_1 + 0xc) <= iVar3 + param_3) {
    uVar2 = param_3;
    if (param_3 < 0x21) {
      uVar2 = 0x20;
    }
    uVar2 = *(uint *)(param_1 + 0xc) + uVar2;
    if (iVar1 == 0) {
      iVar1 = js_runGC();
    }
    else {
      iVar1 = js_allocAtomBlock(iVar1,uVar2);
    }
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    *(int *)(param_1 + 4) = iVar1;
    *(uint *)(param_1 + 0xc) = uVar2;
    *(int *)(param_1 + 8) = iVar1 + iVar3;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    **(undefined1 **)(param_1 + 8) = *param_2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_sprintfAlloc (FUN_68126320)
// Address: 68126320
// Size: 74 bytes
// Params: char * param_1, uint * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_sprintfAlloc(char *param_1,uint *param_2)

{
  int iVar1;
  code *local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_1c = runtime_appendToBuffer;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  iVar1 = runtime_formatPrintf(&local_1c,param_1,param_2);
  if (iVar1 < 0) {
    if (local_18 != 0) {
      js_freeHandle();
    }
    local_18 = 0;
  }
  return local_18;
}



// ============================================================
// Function: runtime_writeToFixedBuffer (FUN_68126370)
// Address: 68126370
// Size: 55 bytes
// Params: int param_1, undefined1 * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_writeToFixedBuffer(int param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4)) - *(int *)(param_1 + 8);
  if (uVar1 < param_3) {
    param_3 = uVar1;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    **(undefined1 **)(param_1 + 8) = *param_2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_formatToBuffer (FUN_681263b0)
// Address: 681263b0
// Size: 93 bytes
// Params: undefined1 * param_1, int param_2, char * param_3, uint * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_formatToBuffer(undefined1 *param_1,int param_2,char *param_3,uint *param_4)

{
  code *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  int local_10;
  
  if (0 < param_2) {
    local_18 = param_1;
    local_14 = param_1;
    local_10 = param_2;
    local_1c = runtime_writeToFixedBuffer;
    runtime_formatPrintf(&local_1c,param_3,param_4);
    if ((local_14 != local_18) && (local_14[-1] != '\0')) {
      local_14[-1] = 0;
      local_14 = local_14 + -1;
    }
    if ((int)local_14 - (int)local_18 != 0) {
      return ((int)local_14 - (int)local_18) + -1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_strlen (FUN_68126410)
// Address: 68126410
// Size: 18 bytes
// Params: char * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl runtime_strlen(char *param_1)
{
  runtime_sprintfAlloc(param_1,(uint *)&stack0x00000008);
  return 0;
}



// ============================================================
// Function: runtime_snprintf (FUN_68126430)
// Address: 68126430
// Size: 34 bytes
// Params: undefined1 * param_1, int param_2, char * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl runtime_snprintf(undefined1 *param_1,int param_2,char *param_3)

{
  int iVar1;
  
  if (param_2 < 1) {
    return 0;
  }
  iVar1 = runtime_formatToBuffer(param_1,param_2,param_3,(uint *)&stack0x00000010);
  return iVar1;
}



// ============================================================
// Function: runtime_checkDebugFlag (FUN_68126460)
// Address: 68126460
// Size: 44 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall runtime_checkDebugFlag(undefined4 param_1)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (in_EAX == 0) {
    return 1;
  }
  uVar1 = xtra_invokeWithArgs(param_1,5,xtra_getErrorString,0,0x9e);
  return uVar1;
}



// ============================================================
// Function: runtime_getPropertyVtable (FUN_68126490)
// Address: 68126490
// Size: 136 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyVtable(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = param_3;
  iVar6 = param_1;
  param_3 = param_3 >> 1;
  if ((*(byte *)(param_1 + 0x164) & 1) != 0) {
    iVar4 = runtime_checkDebugFlag(param_1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  puVar3 = param_4;
  piVar1 = param_2;
  if (iVar2 != 1) {
    uVar5 = *(undefined4 *)(*(int *)(iVar6 + 0x14) + 0x110);
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(iVar6 + 0x14) + 0x114);
  }
  iVar6 = (**(code **)(*(int *)(*param_2 + 4) + 0x2c))
                    (iVar6,param_2,uVar5,iVar2 != 1,param_4,&param_1);
  if (iVar6 == 0) {
    return 0;
  }
  *puVar3 = *(undefined4 *)(piVar1[1] + param_3 * 4);
  return 1;
}



// ============================================================
// Function: runtime_getObjectCount (FUN_68126520)
// Address: 68126520
// Size: 143 bytes
// Params: int param_1, int * param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getObjectCount(int param_1,int *param_2,undefined4 param_3,uint *param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint local_8;
  
  iVar1 = param_1;
  if ((*(byte *)(param_1 + 0x164) & 1) != 0) {
    iVar3 = runtime_checkDebugFlag(param_1);
    if (iVar3 == 0) {
      return 0;
    }
  }
  piVar2 = param_2;
  param_1 = 0;
  iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 0x28))(iVar1,param_2,0,&param_1,&local_8);
  if (iVar3 != 0) {
    if (((local_8 & 1) == 0) || (local_8 == 0x80000001)) {
      *param_4 = 1;
    }
    else {
      *param_4 = local_8;
    }
  }
  if (param_1 != 0) {
    (**(code **)(*(int *)(*piVar2 + 4) + 0x28))(iVar1,piVar2,2,&param_1,0);
  }
  return 0;
}



// ============================================================
// Function: runtime_getCharType (FUN_681265b0)
// Address: 681265b0
// Size: 13 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_getCharType(uint param_1)

{
  return param_1 >> 3;
}



// ============================================================
// Function: runtime_traverseGcRefs (FUN_681265c0)
// Address: 681265c0
// Size: 506 bytes
// Params: uint param_1, int * param_2, undefined4 * param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * runtime_traverseGcRefs(uint param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **ppuVar2;
  code *pcVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  byte local_1c [4];
  uint local_18;
  int *local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  piVar5 = param_2;
  uVar4 = param_1;
  piVar11 = *(int **)(param_1 + 0x138);
  local_18 = runtime_getCharType((uint)param_2);
  piVar6 = crypto_findHashEntry(piVar11,local_18,piVar5);
  puVar7 = (undefined4 *)*piVar6;
  if (puVar7 != (undefined4 *)0x0) {
    if (puVar7[3] == 0) {
      iVar9 = *(int *)(uVar4 + 0x134) + 1;
      *(int *)(uVar4 + 0x134) = iVar9;
      puVar7[3] = iVar9 * 4;
    }
    piVar11 = (int *)0x0;
LAB_681267a6:
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = piVar11;
    }
    return puVar7;
  }
  puVar7 = crypto_decompileBlock(piVar11,piVar6,local_18,piVar5,0);
  if (puVar7 == (undefined4 *)0x0) {
    xtra_reportError(uVar4);
  }
  else {
    local_8 = xtra_resolvePath(uVar4,piVar5);
    if (local_8 != (int *)0x0) {
      iVar9 = *local_8;
      uVar10 = 1;
      local_18 = 0;
      if (0 < iVar9) {
        local_14 = local_8 + 1;
        do {
          iVar1 = *local_14;
          uVar10 = (**(code **)(*(int *)(*param_2 + 4) + 8))(uVar4,param_2,iVar1,&local_10,&local_c)
          ;
          if (uVar10 == 0) goto LAB_68126764;
          if (local_c != 0) {
            uVar10 = (**(code **)(*(int *)(*local_10 + 4) + 0x18))
                               (uVar4,local_10,iVar1,local_c,local_1c);
            if (uVar10 != 0) {
              ppuVar2 = *(undefined ***)(*local_10 + 4);
              if (((ppuVar2 == &PTR_FUN_68192948) ||
                  ((ppuVar2 != (undefined **)0x0 && (*ppuVar2 == PTR_FUN_68192948)))) &&
                 ((local_1c[0] & 0x30) != 0)) {
                param_1 = 0;
                if ((local_1c[0] & 0x10) != 0) {
                  param_1 = *(uint *)(local_c + 4);
                }
                if ((local_1c[0] & 0x20) != 0) {
                  if (param_1 != 0) {
                    puVar8 = runtime_traverseGcRefs(uVar4,(int *)(param_1 & 0xfffffff8),(undefined4 *)0x0);
                    uVar10 = (uint)(puVar8 != (undefined4 *)0x0);
                  }
                  param_1 = *(uint *)(local_c + 8);
                }
              }
              else {
                uVar10 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(uVar4,param_2,iVar1,&param_1);
              }
            }
            pcVar3 = *(code **)(*(int *)(*local_10 + 4) + 0x34);
            if (pcVar3 != (code *)0x0) {
              (*pcVar3)(uVar4,local_10,local_c);
            }
          }
          if (uVar10 == 0) goto LAB_68126764;
          if ((((param_1 & 7) == 0) && (param_1 != 0)) &&
             (puVar8 = runtime_traverseGcRefs(uVar4,(int *)(param_1 & 0xfffffff8),(undefined4 *)0x0),
             puVar8 == (undefined4 *)0x0)) {
            uVar10 = 0;
            goto LAB_68126764;
          }
          local_14 = local_14 + 1;
          local_18 = local_18 + 1;
        } while ((int)local_18 < iVar9);
      }
      piVar11 = local_8;
      if (param_3 == (undefined4 *)0x0) {
LAB_68126764:
        piVar11 = local_8;
        xtra_flushAndCheck(uVar4,(int)local_8);
      }
      if (uVar10 == 0) {
        return (undefined4 *)0x0;
      }
      goto LAB_681267a6;
    }
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: runtime_beginGcTraversal (FUN_681267c0)
// Address: 681267c0
// Size: 539 bytes
// Params: uint param_1, int * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_beginGcTraversal(uint param_1,int *param_2,undefined4 *param_3,int *param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  uint local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  int *local_24;
  int *local_20;
  undefined1 local_1c [20];
  uint local_8;
  
  local_28 = param_3;
  *param_4 = 0;
  piVar1 = *(int **)(param_1 + 0x138);
  local_24 = param_4;
  if (piVar1 == (int *)0x0) {
    piVar1 = crypto_insertHashEntry(8,runtime_getCharType,crypto_isDecompileReady,crypto_isDecompileReady,(undefined **)0x0,0);
    if (piVar1 == (int *)0x0) {
      xtra_reportError(param_1);
      return 0;
    }
    *(int **)(param_1 + 0x138) = piVar1;
  }
  local_20 = (int *)0x0;
  if (*(int *)(param_1 + 0x130) == 0) {
    puVar2 = runtime_traverseGcRefs(param_1,param_2,&local_20);
    if (puVar2 == (undefined4 *)0x0) goto LAB_6812690d;
    if (local_28 == (undefined4 *)0x0) {
      xtra_flushAndCheck(param_1,(int)local_20);
      local_20 = (int *)0x0;
    }
LAB_68126947:
    uVar6 = puVar2[3];
    if (uVar6 == 0) {
      *local_24 = 0;
    }
    else {
      iVar4 = runtime_snprintf(local_1c,0x14,"#%u%c");
      psVar5 = certs_createSubstring(param_1,local_1c,iVar4,&local_30);
      *local_24 = (int)psVar5;
      if (psVar5 == (short *)0x0) {
        if (local_20 != (int *)0x0) {
          xtra_flushAndCheck(param_1,(int)local_20);
        }
        goto LAB_6812690d;
      }
    }
  }
  else {
    local_30 = runtime_getCharType((uint)param_2);
    piVar3 = crypto_findHashEntry(piVar1,local_30,param_2);
    puVar2 = (undefined4 *)*piVar3;
    local_2c = puVar2;
    if (puVar2 != (undefined4 *)0x0) goto LAB_68126947;
    local_2c = crypto_decompileBlock(piVar1,piVar3,local_30,param_2,0);
    if (local_2c == (undefined4 *)0x0) {
      xtra_reportError(param_1);
      goto LAB_6812690d;
    }
    *local_24 = 0;
    uVar6 = 0;
  }
  puVar2 = local_28;
  if ((uVar6 & 1) == 0) {
    if (((local_28 != (undefined4 *)0x0) && (local_20 == (int *)0x0)) &&
       (local_20 = xtra_resolvePath(param_1,param_2), piVar1 = local_24, local_20 == (int *)0x0)) {
      if (*local_24 != 0) {
        xtra_checkAndFlush(param_1,*local_24);
        *piVar1 = 0;
      }
LAB_6812690d:
      if (*(int *)(param_1 + 0x130) == 0) {
        *(undefined4 *)(param_1 + 0x134) = 0;
        crypto_getHashTableSize(*(int **)(param_1 + 0x138));
        *(undefined4 *)(param_1 + 0x138) = 0;
      }
      return 0;
    }
    *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + 1;
  }
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = local_20;
  }
  return 0;
}



// ============================================================
// Function: runtime_endGcTraversal (FUN_681269e0)
// Address: 681269e0
// Size: 80 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_endGcTraversal(int param_1,int *param_2)
{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x130);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(undefined4 *)(param_1 + 0x134) = 0;
    crypto_getHashTableSize(*(int **)(param_1 + 0x138));
    *(undefined4 *)(param_1 + 0x138) = 0;
  }
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    xtra_flushAndCheck(param_1,*param_2);
    *param_2 = 0;
  }
  return 0;
}



