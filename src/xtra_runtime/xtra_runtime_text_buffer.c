// Module: xtra_runtime
// Topic: Text buffer management, run operations, font styles, text editing
// Address range: 0x6811a320 - 0x6811b760
// Functions (26):
//   xtra_initBufferWriter
//   xtra_writeToBuffer
//   xtra_findBufferRun
//   xtra_getBufferFlags
//   xtra_getBufferRef
//   xtra_flushBuffer
//   xtra_getBufferState
//   xtra_moveBufferBackward
//   xtra_spliceBufferRange
//   xtra_removeBufferData
//   xtra_resetBuffer
//   xtra_getBufferRange
//   xtra_replaceBufferRange
//   xtra_insertIntoBuffer
//   xtra_deleteBufferRange
//   xtra_getBufferSize
//   xtra_extractBufferBytes
//   xtra_setBufferPos
//   xtra_readBufferRange
//   xtra_copyBufferRange
//   xtra_appendToBuffer
//   xtra_applyBufferStyle
//   xtra_writeBufferMetrics
//   xtra_readBufferValue
//   xtra_measureBufferText
//   xtra_calculateBufferSize

// ============================================================
// Function: xtra_initBufferWriter (FUN_6811a320)
// Address: 6811a320
// Size: 67 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_initBufferWriter(int param_1)
{
  uint uVar1;
  undefined4 local_c;
  
  Ordinal_1155(*(undefined4 *)(param_1 + 0x34));
  xtra_releaseFontRef(local_c);
  Ordinal_1160(*(undefined4 *)(param_1 + 0x34));
  return 0;
}



// ============================================================
// Function: xtra_writeToBuffer (FUN_6811a370)
// Address: 6811a370
// Size: 139 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_writeToBuffer(undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_8;
  
  local_1c = param_2;
  iVar1 = Ordinal_1154(param_1);
  iVar2 = Ordinal_1165(param_1,&local_18,&local_1c,xtra_comparePositions,0);
  if (((iVar2 == 0) && (local_18 != 0)) &&
     ((local_18 != iVar1 ||
      (Ordinal_1155(param_1,local_18 + -1,&local_14), param_2 <= local_10 + local_14)))) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_findBufferRun (xtra_findBufferRun)
// Address: 6811a400
// Size: 85 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_findBufferRun(int param_1)
{
  int iVar1;
  int unaff_ESI;
  undefined1 local_14 [12];
  uint local_8;
  
  iVar1 = xtra_writeToBuffer(*(undefined4 *)(unaff_ESI + 0x34),param_1);
  if (iVar1 == -1) {
    return 0;
  }
  Ordinal_1155(*(undefined4 *)(unaff_ESI + 0x34),iVar1,local_14);
  return 0;
}



// ============================================================
// Function: xtra_getBufferFlags (FUN_6811a460)
// Address: 6811a460
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_getBufferFlags(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) &&
     (iVar1 = xtra_findBufferRun(param_3), iVar1 != -1)) {
    xtra_lookupFontEntry(param_2,param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_getBufferRef (FUN_6811a490)
// Address: 6811a490
// Size: 72 bytes
// Params: int param_1, int param_2, undefined4 * param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_getBufferRef(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  
  iVar1 = xtra_writeToBuffer(*(undefined4 *)(param_1 + 0x34),param_2);
  if (((-1 < iVar1) && (param_4 != 0)) &&
     (Ordinal_1155(*(undefined4 *)(param_1 + 0x34),iVar1,param_4), param_3 != (undefined4 *)0x0)) {
    xtra_lookupFontEntry(param_3,param_1);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_flushBuffer (FUN_6811a4e0)
// Address: 6811a4e0
// Size: 189 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_flushBuffer(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBX;
  int local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  if ((0 < unaff_EBX) && (unaff_EBX < *(int *)(param_1 + 4))) {
    iVar1 = xtra_findBufferRun(unaff_EBX + -1);
    iVar2 = xtra_findBufferRun(unaff_EBX);
    if ((iVar1 == iVar2) &&
       ((iVar1 = xtra_writeToBuffer(*(undefined4 *)(param_1 + 0x34),unaff_EBX), -1 < iVar1 &&
        (Ordinal_1155(*(undefined4 *)(param_1 + 0x34),iVar1,&local_14), local_14 != unaff_EBX)))) {
      uVar3 = Ordinal_1157(*(undefined4 *)(param_1 + 0x34));
      piVar4 = (int *)Ordinal_1156(*(undefined4 *)(param_1 + 0x34),uVar3,iVar1);
      piVar4[1] = piVar4[1] - (unaff_EBX - local_14);
      *piVar4 = unaff_EBX;
      local_10 = unaff_EBX - local_14;
      Ordinal_1158(*(undefined4 *)(param_1 + 0x34),uVar3);
      Ordinal_1151(*(undefined4 *)(param_1 + 0x34),iVar1,&local_14);
      xtra_addFontRef(local_c);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_getBufferState (FUN_6811a5a0)
// Address: 6811a5a0
// Size: 154 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getBufferState(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  uint uVar4;
  undefined4 local_8;
  
  local_8 = Ordinal_1154(*(undefined4 *)(unaff_ESI + 0x34));
  uVar1 = Ordinal_1157(*(undefined4 *)(unaff_ESI + 0x34));
  uVar4 = 0;
  if (local_8 != 0) {
    do {
      iVar2 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x34),uVar1,uVar4);
      uVar4 = uVar4 + 1;
      if (local_8 <= uVar4) break;
      do {
        iVar3 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x34),uVar1,uVar4);
        if (*(int *)(iVar3 + 8) != *(int *)(iVar2 + 8)) break;
        *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar3 + 4);
        Ordinal_1158(*(undefined4 *)(unaff_ESI + 0x34),uVar1);
        xtra_initBufferWriter(unaff_ESI);
        local_8 = local_8 - 1;
        uVar1 = Ordinal_1157(*(undefined4 *)(unaff_ESI + 0x34));
      } while (uVar4 < local_8);
    } while (uVar4 < local_8);
  }
  Ordinal_1158(*(undefined4 *)(unaff_ESI + 0x34),uVar1);
  return 1;
}



// ============================================================
// Function: xtra_moveBufferBackward (xtra_moveBufferBackward)
// Address: 6811a640
// Size: 29 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_moveBufferBackward(int param_1,int param_2)
{
  int in_EAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(param_1 + -1 + in_EAX);
  puVar1 = (undefined1 *)(param_2 + -1 + in_EAX);
  for (; 0 < in_EAX; in_EAX = in_EAX + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + -1;
    puVar2 = puVar2 + -1;
  }
  return 0;
}



// ============================================================
// Function: xtra_spliceBufferRange (xtra_spliceBufferRange)
// Address: 6811a660
// Size: 638 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_spliceBufferRange(int *param_1,int param_2,int param_3,int param_4)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *unaff_EDI;
  int local_14 [2];
  int local_c;
  uint local_8;
  
  if ((((param_1 != (int *)0x0) && (unaff_EDI != (int *)0x0)) && (param_1 != unaff_EDI)) &&
     (*param_1 != 0)) {
    if (*unaff_EDI == 0) {
      iVar2 = Ordinal_1111(1,1);
      if (iVar2 == 0) goto LAB_6811a8c9;
      *unaff_EDI = iVar2;
      unaff_EDI[1] = 0;
    }
    if ((param_3 < 0) || (unaff_EDI[1] <= param_3)) {
      param_3 = unaff_EDI[1];
    }
    if (((-1 < param_2) && (0 < param_4)) && (iVar2 = param_1[1], param_2 < iVar2)) {
      if (iVar2 <= param_2 + param_4) {
        param_4 = iVar2 - param_2;
      }
      if (0 < param_4) {
        iVar2 = unaff_EDI[1];
        iVar3 = Ordinal_1117();
        if (iVar3 != 0) {
          iVar3 = Ordinal_1114(*unaff_EDI);
          xtra_moveBufferBackward(param_3 + iVar3,param_4 + param_3 + iVar3);
          *(undefined1 *)(iVar3 + iVar2 + param_4) = 0;
          Ordinal_1115(*unaff_EDI);
          unaff_EDI[1] = iVar2 + param_4;
          iVar2 = Ordinal_1114(*param_1);
          iVar3 = Ordinal_1114(*unaff_EDI);
          Ordinal_1129(param_3 + iVar3,param_2 + iVar2,param_4);
          Ordinal_1115(*param_1);
          Ordinal_1115(*unaff_EDI);
          xtra_flushBuffer((int)unaff_EDI);
          xtra_flushBuffer((int)param_1);
          xtra_flushBuffer((int)param_1);
          bVar1 = false;
          iVar2 = xtra_writeToBuffer(unaff_EDI[0xd],param_3);
          if (iVar2 == -1) {
            iVar2 = Ordinal_1154(unaff_EDI[0xd]);
          }
          uVar4 = Ordinal_1157(unaff_EDI[0xd]);
          piVar5 = (int *)Ordinal_1156(unaff_EDI[0xd],uVar4,iVar2);
          iVar3 = iVar2;
          while (piVar5 != (int *)0x0) {
            *piVar5 = *piVar5 + param_4;
            iVar3 = iVar3 + 1;
            piVar5 = (int *)Ordinal_1156(unaff_EDI[0xd],uVar4,iVar3);
          }
          Ordinal_1158(unaff_EDI[0xd],uVar4);
          iVar3 = xtra_writeToBuffer(param_1[0xd],param_2);
          iVar6 = xtra_writeToBuffer(param_1[0xd],param_2 + param_4 + -1);
          if (iVar3 <= iVar6) {
            iVar2 = iVar2 - iVar3;
            do {
              Ordinal_1155(param_1[0xd],iVar3,local_14);
              local_14[0] = local_14[0] + (param_3 - param_2);
              local_c = xtra_resolveFontData(local_c,(int)param_1);
              if (local_c == -1) {
                bVar1 = true;
              }
              Ordinal_1151(unaff_EDI[0xd],iVar2 + iVar3,local_14);
              iVar3 = iVar3 + 1;
            } while (iVar3 <= iVar6);
            if (bVar1) goto LAB_6811a8c9;
          }
          xtra_getBufferState();
          xtra_getBufferState();
        }
      }
    }
  }
LAB_6811a8c9:
  return 0;
}



// ============================================================
// Function: xtra_removeBufferData (xtra_removeBufferData)
// Address: 6811a8e0
// Size: 287 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_removeBufferData(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *in_EAX;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_8;
  
  if (((in_EAX != (undefined4 *)0x0) && (-1 < param_1)) && (iVar4 = in_EAX[1], param_1 < iVar4)) {
    if (iVar4 <= *param_2 + param_1) {
      *param_2 = iVar4 - param_1;
    }
    if (-1 < *param_2) {
      xtra_flushBuffer((int)in_EAX);
      xtra_flushBuffer((int)in_EAX);
      iVar1 = *param_2;
      local_8 = 0;
      uVar3 = Ordinal_1157(in_EAX[0xd]);
      iVar4 = Ordinal_1154(in_EAX[0xd]);
      do {
        while( true ) {
          if (iVar4 == 0) {
            Ordinal_1158(in_EAX[0xd],uVar3);
            iVar4 = Ordinal_1114(*in_EAX);
            Ordinal_1129(iVar4 + param_1,*param_2 + param_1 + iVar4,in_EAX[1] - (*param_2 + param_1)
                        );
            in_EAX[1] = in_EAX[1] - *param_2;
            Ordinal_1115(*in_EAX);
            xtra_getBufferState();
            return 0;
          }
          iVar4 = iVar4 + -1;
          piVar5 = (int *)Ordinal_1156(in_EAX[0xd],uVar3,local_8);
          iVar2 = *piVar5;
          if (param_1 <= iVar2) break;
          if (iVar1 + param_1 <= iVar2) goto LAB_6811a9aa;
LAB_6811a9b1:
          local_8 = local_8 + 1;
        }
        if (iVar1 + param_1 <= iVar2) {
LAB_6811a9aa:
          *piVar5 = iVar2 - *param_2;
          goto LAB_6811a9b1;
        }
        Ordinal_1158(in_EAX[0xd],uVar3);
        xtra_initBufferWriter((int)in_EAX);
        uVar3 = Ordinal_1157(in_EAX[0xd]);
      } while( true );
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_resetBuffer (FUN_6811aa00)
// Address: 6811aa00
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_resetBuffer(int param_1)
{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = (int *)Ordinal_1114(param_1);
    if (*piVar1 != 0) {
      Ordinal_1113(piVar1);
    }
    xtra_getTextRunCount((int)piVar1);
    if (piVar1[0xe] != 0) {
      Ordinal_1163(piVar1 + 0xe);
    }
    if (piVar1[0xd] != 0) {
      Ordinal_1163(piVar1 + 0xd);
    }
    Ordinal_1113(&param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_getBufferRange (FUN_6811aa50)
// Address: 6811aa50
// Size: 482 bytes
// Params: int param_1, uint param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_getBufferRange(int param_1,uint param_2,int *param_3,int *param_4)
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = param_2;
  bVar1 = false;
  if (param_1 == 0) {
    local_18 = 0;
  }
  else {
    if (param_2 == 0) {
      local_18 = Ordinal_1201(param_1);
    }
    if (param_3 == (int *)0x0) goto LAB_6811ac20;
  }
  if ((param_4 == (int *)0x0) || (iVar2 = Ordinal_1111(0xf0,1), iVar2 == 0)) {
LAB_6811ac20:
    return 0;
  }
  piVar3 = (int *)Ordinal_1114(iVar2);
  piVar6 = piVar3 + 2;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = *param_4;
    param_4 = param_4 + 1;
    piVar6 = piVar6 + 1;
  }
  if ((local_18 < 0x7fffffff) && (iVar5 = Ordinal_1111(local_18 + 1,1), iVar5 != 0)) {
    *piVar3 = iVar5;
    piVar3[1] = local_18;
    iVar4 = Ordinal_1114(iVar5);
    if (0 < (int)local_18) {
      Ordinal_1128(iVar4,param_1,local_18);
    }
    *(undefined1 *)(local_18 + iVar4) = 0;
    Ordinal_1115(iVar5);
    if (param_3 == (int *)0x0) {
      Ordinal_1203(piVar3 + 0x10,"_DEFAULT_",0x40);
      piVar3[0x20] = 0xc;
      *(undefined2 *)(piVar3 + 0x23) = 0;
      *(undefined1 *)((int)piVar3 + 0x8e) = 0;
      piVar3[0x24] = 0;
    }
    else {
      piVar6 = param_3;
      piVar7 = piVar3 + 0x10;
      for (iVar5 = 0x29; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
    }
    Ordinal_1702(piVar3 + 0x10);
    iVar5 = Ordinal_1150(10,10,0xc);
    piVar3[0xd] = iVar5;
    if (iVar5 != 0) {
      iVar5 = Ordinal_1150(10,10,0xa4);
      piVar3[0xe] = iVar5;
      if (iVar5 != 0) {
        if (0 < (int)local_18) {
          iVar5 = xtra_getTextData((int)piVar3,param_3);
          if (iVar5 == -1) goto LAB_6811abe0;
          local_10 = piVar3[1];
          local_14 = 0;
          local_c = iVar5;
          iVar5 = Ordinal_1152(piVar3[0xd],&local_14);
          if (iVar5 == 0) goto LAB_6811abe0;
        }
        piVar3[0x3b] = 0;
        bVar1 = true;
      }
    }
  }
LAB_6811abe0:
  Ordinal_1115(iVar2);
  if (bVar1) {
    return 0;
  }
  xtra_resetBuffer(iVar2);
  return 0;
}



// ============================================================
// Function: xtra_replaceBufferRange (FUN_6811ac40)
// Address: 6811ac40
// Size: 302 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_replaceBufferRange(int param_1,int param_2,int param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  uint uVar4;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (param_1 != 0) {
    piVar1 = (int *)Ordinal_1114(param_1);
    if ((param_2 != 0) && (param_4 != (undefined4 *)0x0)) {
      iVar2 = Ordinal_1201(param_2);
      if (iVar2 < param_3) {
        param_3 = Ordinal_1201(param_2);
      }
      if (param_3 != 0) {
        iVar2 = piVar1[1];
        uVar4 = iVar2 + param_3;
        if (uVar4 < 0x80000000) {
          if (*piVar1 == 0) {
            iVar3 = Ordinal_1111(uVar4 + 1);
            *piVar1 = iVar3;
          }
          else {
            iVar3 = Ordinal_1117(piVar1,uVar4 + 1,0);
          }
          if (iVar3 != 0) {
            iVar3 = Ordinal_1114(*piVar1);
            Ordinal_1129(iVar3 + iVar2,param_2,param_3);
            *(undefined1 *)(iVar3 + uVar4) = 0;
            Ordinal_1115(*piVar1);
            piVar1[1] = uVar4;
            iVar3 = xtra_getTextData((int)piVar1,param_4);
            if (-1 < iVar3) {
              local_10 = param_3;
              local_14 = iVar2;
              local_c = iVar3;
              Ordinal_1152(piVar1[0xd],&local_14);
              xtra_renderTextLine(extraout_ECX,param_3,0,0);
            }
          }
        }
      }
    }
    if (piVar1 != (int *)0x0) {
      Ordinal_1115(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_insertIntoBuffer (FUN_6811ad70)
// Address: 6811ad70
// Size: 170 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_insertIntoBuffer(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  iVar1 = 0;
  if (param_1 != 0) {
    piVar2 = (int *)Ordinal_1114(param_1);
    iVar1 = xtra_getBufferRange(0,0,(int *)0x0,piVar2 + 2);
    if (iVar1 != 0) {
      iVar5 = Ordinal_1114(iVar1);
      *(int *)(iVar5 + 0xec) = piVar2[0x3b];
      if (param_3 < 1) {
        piVar4 = piVar2 + 0x10;
        piVar6 = (int *)(iVar5 + 0x40);
        for (iVar3 = 0x29; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar6 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar6 = piVar6 + 1;
        }
        iVar5 = 1;
      }
      else {
        iVar5 = xtra_spliceBufferRange(piVar2,param_2,0,param_3);
      }
      Ordinal_1115(iVar1);
    }
    if (piVar2 != (int *)0x0) {
      Ordinal_1115(param_1);
    }
    if ((iVar5 == 0) && (iVar1 != 0)) {
      xtra_resetBuffer(iVar1);
      return 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_deleteBufferRange (FUN_6811ae20)
// Address: 6811ae20
// Size: 103 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_deleteBufferRange(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int iVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = Ordinal_1114(param_1);
  iVar2 = xtra_removeBufferData(param_2,&param_3);
  if (iVar2 == 0) {
    xtra_getTextRunCount(iVar1);
  }
  else {
    if (param_3 < 1) {
      if (-1 < param_3) goto LAB_6811ae71;
      iVar3 = param_2 - *(int *)(iVar1 + 4);
    }
    else {
      iVar3 = -param_3;
    }
    xtra_renderTextLine(extraout_ECX,iVar3,0,0);
  }
LAB_6811ae71:
  if (iVar1 != 0) {
    Ordinal_1115(param_1);
  }
  return iVar2;
}



// ============================================================
// Function: xtra_getBufferSize (FUN_6811ae90)
// Address: 6811ae90
// Size: 38 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getBufferSize(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    uVar1 = *(undefined4 *)(iVar2 + 4);
    Ordinal_1115(param_1);
  }
  return uVar1;
}



// ============================================================
// Function: xtra_extractBufferBytes (xtra_extractBufferBytes)
// Address: 6811aec0
// Size: 118 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_extractBufferBytes(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar2 = 0;
  if (param_1 != 0) {
    piVar1 = (int *)Ordinal_1114(param_1);
    if (*piVar1 != 0) {
      if (param_3 < param_5) {
        param_5 = param_3;
      }
      if (piVar1[1] - param_2 <= param_5) {
        param_5 = piVar1[1] - param_2;
      }
      if (0 < param_5) {
        iVar2 = Ordinal_1114(*piVar1);
        Ordinal_1129(param_4,iVar2 + param_2,param_5);
        Ordinal_1115(*piVar1);
        *(undefined1 *)(param_5 + param_4) = 0;
        local_8 = param_5;
      }
    }
    Ordinal_1115(param_1);
    iVar2 = local_8;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_setBufferPos (FUN_6811af40)
// Address: 6811af40
// Size: 127 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_setBufferPos(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar2 = 0;
  if (param_1 != 0) {
    piVar1 = (int *)Ordinal_1114(param_1);
    local_8 = *piVar1;
    if ((local_8 != 0) && (param_2 != 0)) {
      iVar2 = Ordinal_1117(&local_8,piVar1[1] + 1,0);
      if (iVar2 == 0) {
        local_8 = iVar2;
        Ordinal_1115(param_1);
        return local_8;
      }
      iVar2 = Ordinal_1114(local_8);
      if (iVar2 != 0) {
        *(undefined1 *)(iVar2 + piVar1[1]) = 0;
        Ordinal_1115(local_8);
      }
    }
    Ordinal_1115(param_1);
    iVar2 = local_8;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_readBufferRange (FUN_6811afc0)
// Address: 6811afc0
// Size: 82 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_readBufferRange(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    if ((*(int *)(iVar1 + 0x38) != 0) && (*(int *)(iVar1 + 0x34) != 0)) {
      if ((param_3 < 0) || (*(int *)(iVar1 + 4) <= param_3)) {
        param_3 = *(int *)(iVar1 + 4) + -1;
      }
      iVar1 = xtra_getBufferRef(iVar1,param_3,(undefined4 *)0x0,param_2);
      if (-1 < iVar1) {
        uVar2 = 1;
      }
    }
    Ordinal_1115(param_1);
  }
  return uVar2;
}



// ============================================================
// Function: xtra_copyBufferRange (FUN_6811b020)
// Address: 6811b020
// Size: 285 bytes
// Params: int param_1, undefined4 * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_copyBufferRange(int param_1,undefined4 *param_2,int param_3,int param_4)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_ECX;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    if ((((*(int *)(iVar2 + 0x38) != 0) && (*(int *)(iVar2 + 0x34) != 0)) && (-1 < param_3)) &&
       ((0 < param_4 && (iVar3 = *(int *)(iVar2 + 4), param_3 < iVar3)))) {
      bVar1 = iVar3 <= param_4 + param_3;
      if (bVar1) {
        param_4 = iVar3 - param_3;
      }
      local_18 = (uint)bVar1;
      xtra_flushBuffer(iVar2);
      xtra_flushBuffer(iVar2);
      iVar3 = xtra_writeToBuffer(*(undefined4 *)(iVar2 + 0x34),param_3);
      iVar4 = xtra_writeToBuffer(*(undefined4 *)(iVar2 + 0x34),param_3 + param_4);
      if (iVar3 < (int)(iVar4 + local_18)) {
        local_18 = (iVar4 + local_18) - iVar3;
        do {
          xtra_initBufferWriter(iVar2);
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
      local_c = xtra_getTextData(iVar2,param_2);
      local_14 = param_3;
      local_10 = param_4;
      Ordinal_1151(*(undefined4 *)(iVar2 + 0x34),iVar3,&local_14);
      xtra_renderTextLine(extraout_ECX,param_4,1,0);
    }
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_appendToBuffer (FUN_6811b140)
// Address: 6811b140
// Size: 114 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_appendToBuffer(int param_1,undefined4 *param_2,int param_3)

{
  int local_14;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = 0;
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    if ((*(int *)(iVar1 + 0x38) != 0) && (*(int *)(iVar1 + 0x34) != 0)) {
      if ((param_3 < 0) || (*(int *)(iVar1 + 4) <= param_3)) {
        param_3 = *(int *)(iVar1 + 4) + -1;
      }
      if (param_3 < 0) {
        puVar4 = (undefined4 *)(iVar1 + 0x40);
        for (iVar2 = 0x29; iVar2 != 0; iVar2 = iVar2 + -1) {
          *param_2 = *puVar4;
          puVar4 = puVar4 + 1;
          param_2 = param_2 + 1;
        }
        Ordinal_1115(param_1);
        return 1;
      }
      xtra_getBufferFlags(iVar1,param_2,param_3);
      uVar3 = 1;
    }
    Ordinal_1115(param_1);
  }
  return uVar3;
}



// ============================================================
// Function: xtra_applyBufferStyle (xtra_applyBufferStyle)
// Address: 6811b1c0
// Size: 1022 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_applyBufferStyle(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int *piVar1;
  undefined1 *puVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int extraout_ECX;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_c4;
  int local_c0;
  undefined4 local_b8 [16];
  int local_78;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  uint local_68;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  uint local_8;
  
  bVar3 = false;
  local_c0 = param_5;
  if (param_2 < 0) {
    param_3 = param_3 + param_2;
    param_2 = 0;
    if (param_3 < 0) {
      return 0;
    }
  }
  if (((param_4 != 0) && (param_5 != 0)) && (param_1 != 0)) {
    iVar4 = Ordinal_1114(param_1);
    if ((param_3 + param_2 <= *(int *)(iVar4 + 4)) ||
       (param_3 = *(int *)(iVar4 + 4) - param_2, -1 < param_3)) {
      piVar1 = (int *)(param_4 + 4);
      piVar5 = piVar1;
      do {
        iVar6 = piVar5[-1];
        local_c0 = local_c0 + -1;
        if (iVar6 < 0x80) {
          bVar3 = true;
        }
        else {
          iVar6 = iVar6 + -0x80;
          switch(iVar6) {
          case 0:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 8) = iVar6;
            break;
          case 1:
            iVar6 = CONCAT22((short)((uint)iVar6 >> 0x10),(short)*piVar5);
            *(short *)(iVar4 + 0xc) = (short)*piVar5;
            break;
          case 2:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 0x10) = iVar6;
            break;
          case 3:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 0x14) = iVar6;
            break;
          case 4:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 0x18) = iVar6;
            break;
          case 5:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 0x1c) = iVar6;
            break;
          case 6:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 0x20) = iVar6;
            break;
          case 7:
            iVar6 = *piVar5;
            *(int *)(iVar4 + 0x24) = iVar6;
            break;
          case 8:
            if (*piVar5 != 0) {
              *(undefined1 *)(iVar4 + 0x28) = *(undefined1 *)*piVar5;
              *(undefined1 *)(iVar4 + 0x29) = *(undefined1 *)(*piVar5 + 1);
              *(undefined1 *)(iVar4 + 0x2a) = *(undefined1 *)(*piVar5 + 2);
              iVar6 = iVar4;
            }
          }
        }
        piVar5 = piVar5 + 2;
      } while (local_c0 != 0);
      if (bVar3) {
        local_c0 = param_3;
        if (param_3 == 0) {
          local_c0 = 1;
        }
        local_c4 = param_2;
        xtra_flushBuffer(iVar4);
        xtra_flushBuffer(iVar4);
        iVar6 = param_1;
        if (local_c0 != 0) {
LAB_6811b393:
          iVar8 = param_5;
          piVar5 = piVar1;
          if (param_3 == 0) {
            puVar9 = (undefined4 *)(iVar4 + 0x40);
            puVar10 = local_b8;
            for (iVar7 = 0x29; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
          }
          else {
            iVar6 = xtra_getBufferRef(iVar4,local_c4,local_b8,(int)local_14);
          }
          do {
            iVar8 = iVar8 + -1;
            switch(piVar5[-1]) {
            case 0:
              if (*piVar5 != 0) {
                Ordinal_1129(local_b8,*piVar5,0x40);
              }
              break;
            case 1:
              local_78 = *piVar5;
              break;
            case 2:
              if (*piVar5 != 0) {
                puVar2 = (undefined1 *)*piVar5;
                local_6c = *puVar2;
                local_6b = puVar2[1];
                local_6a = puVar2[2];
              }
              break;
            case 3:
              if (*piVar5 != 0) {
                local_68 = 0;
              }
              break;
            case 4:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xfffffffe;
              }
              else {
                local_68 = local_68 | 1;
              }
              break;
            case 5:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xfffffffd;
              }
              else {
                local_68 = local_68 | 2;
              }
              break;
            case 6:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xfffffffb;
              }
              else {
                local_68 = local_68 | 4;
              }
              break;
            case 7:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xfffffff7;
              }
              else {
                local_68 = local_68 | 8;
              }
              break;
            case 8:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xffffffef;
              }
              else {
                local_68 = local_68 | 0x10;
              }
              break;
            case 9:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xffffffdf;
              }
              else {
                local_68 = local_68 | 0x20;
              }
              break;
            case 10:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xffffffbf;
              }
              else {
                local_68 = local_68 | 0x40;
              }
              break;
            case 0xb:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xffffff7f;
              }
              else {
                local_68 = local_68 | 0x80;
              }
              break;
            case 0xc:
              if (*piVar5 == 0) {
                local_68 = local_68 & 0xfffffeff;
              }
              else {
                local_68 = local_68 | 0x100;
              }
            }
            piVar5 = piVar5 + 2;
          } while (iVar8 != 0);
          if (param_3 != 0) goto code_r0x6811b511;
          puVar9 = local_b8;
          puVar10 = (undefined4 *)(iVar4 + 0x40);
          for (iVar6 = 0x29; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
        }
LAB_6811b57d:
        xtra_getBufferState();
        iVar6 = extraout_ECX;
      }
      xtra_renderTextLine(iVar6,param_3,1,0);
    }
    Ordinal_1115(param_1);
  }
  return 0;
code_r0x6811b511:
  xtra_initBufferWriter(iVar4);
  local_c = xtra_getTextData(iVar4,local_b8);
  Ordinal_1151(*(undefined4 *)(iVar4 + 0x34),iVar6,local_14);
  local_c4 = local_c4 + local_10;
  local_c0 = local_c0 - local_10;
  if (local_c0 == 0) goto LAB_6811b57d;
  goto LAB_6811b393;
}



// ============================================================
// Function: xtra_writeBufferMetrics (xtra_writeBufferMetrics)
// Address: 6811b620
// Size: 77 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_writeBufferMetrics(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    iVar2 = Ordinal_1114(param_1);
    puVar4 = (undefined4 *)(iVar2 + 8);
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    xtra_renderTextLine(0,0,0,1);
    Ordinal_1115(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_readBufferValue (FUN_6811b670)
// Address: 6811b670
// Size: 58 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_readBufferValue(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    iVar2 = Ordinal_1114(param_1);
    puVar4 = (undefined4 *)(iVar2 + 8);
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *param_2 = *puVar4;
      puVar4 = puVar4 + 1;
      param_2 = param_2 + 1;
    }
    Ordinal_1115(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_measureBufferText (xtra_measureBufferText)
// Address: 6811b6b0
// Size: 170 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_measureBufferText(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_8;
  
  local_8 = 0;
  uVar3 = 0;
  if (param_1 != 0) {
    piVar1 = (int *)Ordinal_1114(param_1);
    if (((*piVar1 != 0) && (param_2 <= piVar1[1])) && (iVar2 = Ordinal_1114(*piVar1), iVar2 != 0)) {
      uVar3 = Ordinal_1258();
      if (param_2 < piVar1[1]) {
        uVar4 = xtra_getTextLineHeight((int)piVar1,param_2);
        Ordinal_1259(uVar4);
        Ordinal_1252(iVar2 + param_2,&local_8);
      }
      if (param_3 != 0) {
        uVar4 = xtra_getTextLineHeight((int)piVar1,param_2 + -1);
        Ordinal_1259(uVar4);
        Ordinal_1251(iVar2,iVar2 + param_2,param_3);
      }
      Ordinal_1259(uVar3);
      Ordinal_1115(*piVar1);
    }
    Ordinal_1115(param_1);
    uVar3 = local_8;
  }
  return uVar3;
}



// ============================================================
// Function: xtra_calculateBufferSize (xtra_calculateBufferSize)
// Address: 6811b760
// Size: 142 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_calculateBufferSize(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0xf0;
  iVar1 = Ordinal_1114(param_1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0x2c);
    iVar4 = *(int *)(iVar1 + 4) + 0xf0;
    if (iVar3 != 0) {
      iVar2 = Ordinal_1154(iVar3);
      iVar3 = Ordinal_1153(iVar3);
      iVar4 = iVar4 + iVar2 * iVar3;
    }
    iVar3 = *(int *)(iVar1 + 0x34);
    if (iVar3 != 0) {
      iVar2 = Ordinal_1154(iVar3);
      iVar3 = Ordinal_1153(iVar3);
      iVar4 = iVar4 + iVar2 * iVar3;
    }
    iVar1 = *(int *)(iVar1 + 0x38);
    if (iVar1 != 0) {
      iVar3 = Ordinal_1154(iVar1);
      iVar1 = Ordinal_1153(iVar1);
      iVar4 = iVar4 + iVar3 * iVar1;
    }
    Ordinal_1115(param_1);
  }
  return iVar4;
}



