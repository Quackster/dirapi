// Module: media
// Topic: Pixel operations, color blending, image blitting, and palette handling
// Address range: 0x680a2370 - 0x680a34c0
// Functions (32):
//   media_readPaletteRgb24
//   media_readPaletteRgb16
//   media_skipSrcPixel
//   media_readDestPalettePixel
//   media_writeDestIndexedPixel
//   media_skipDestPixel
//   media_readDest4bitPixel
//   media_writeDest4bitPixel
//   media_skipDest4bitPixel
//   media_readDest1bitPixel
//   media_writeDest1bitPixel
//   media_skipDest1bitPixel
//   media_getSrcColor
//   media_getSrcColor16
//   media_blendRgb24
//   media_blendRgb15
//   media_quantizePixel
//   media_readCompressedPixel
//   media_advanceSrcScanline
//   media_scanCompressedLine
//   media_advanceScanlines
//   media_initPixelOps
//   media_clipBlitRect
//   media_pixelToRgb
//   media_initBlendTable
//   media_unlockBlendTable
//   media_freeBlendTable
//   media_blitCompressedLine
//   media_blitCompressedImage
//   media_performBlit
//   media_executeBlitOp
//   media_applyPixelOp

// ============================================================
// Function: media_readPaletteRgb24 (FUN_680a2370)
// Address: 680a2370
// Size: 51 bytes
// Params: int param_1
// Return: undefined3
// Calling convention: __stdcall
// ============================================================

undefined3 media_readPaletteRgb24(int param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = **(byte **)(param_1 + 0x50);
  *(byte **)(param_1 + 0x50) = *(byte **)(param_1 + 0x50) + 1;
  iVar1 = *(int *)(param_1 + 0x38) + 0xe + (uint)bVar2 * 8;
  (*(unsigned int *)((char *)&param_1 + 0)) =
       CONCAT12(*(undefined1 *)(iVar1 + 1),
                CONCAT11(*(undefined1 *)(iVar1 + 3),*(undefined1 *)(iVar1 + 5)));
  return (undefined3)param_1;
}



// ============================================================
// Function: media_readPaletteRgb16 (FUN_680a23b0)
// Address: 680a23b0
// Size: 68 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_readPaletteRgb16(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = **(byte **)(param_1 + 0x50);
  *(byte **)(param_1 + 0x50) = *(byte **)(param_1 + 0x50) + 1;
  iVar3 = (int)(short)(ushort)bVar2;
  iVar1 = *(int *)(param_1 + 0x38) + 0xe + iVar3 * 8;
  return ((*(byte *)(*(int *)(param_1 + 0x38) + 0xe + iVar3 * 8) & 0xf8) << 5 |
         *(byte *)(iVar1 + 2) & 0xf8) * 4 | (uint)(*(byte *)(iVar1 + 4) >> 3);
}



// ============================================================
// Function: media_skipSrcPixel (FUN_680a2400)
// Address: 680a2400
// Size: 13 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipSrcPixel(int param_1)
{
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  return 0;
}



// ============================================================
// Function: media_readDestPalettePixel (FUN_680a2410)
// Address: 680a2410
// Size: 55 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_readDestPalettePixel(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0x3c) + 0xe + (uint)**(byte **)(param_1 + 0x60) * 8;
  local_8 = (uint)CONCAT12(*(undefined1 *)(iVar1 + 1),
                           CONCAT11(*(undefined1 *)(iVar1 + 3),
                                    *(undefined1 *)
                                     (*(int *)(param_1 + 0x3c) + 0x13 +
                                     (uint)**(byte **)(param_1 + 0x60) * 8)));
  return local_8;
}



// ============================================================
// Function: media_writeDestIndexedPixel (FUN_680a2450)
// Address: 680a2450
// Size: 33 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeDestIndexedPixel(int param_1,undefined4 param_2)
{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(param_1 + 0x24))(param_2,*(undefined4 *)(param_1 + 0x40));
  **(undefined1 **)(param_1 + 0x60) = uVar1;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  return 0;
}



// ============================================================
// Function: media_skipDestPixel (FUN_680a2480)
// Address: 680a2480
// Size: 13 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipDestPixel(int param_1)
{
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  return 0;
}



// ============================================================
// Function: media_readDest4bitPixel (FUN_680a2490)
// Address: 680a2490
// Size: 80 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_readDest4bitPixel(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_8;
  
  uVar2 = (uint)(byte)(((&DAT_6818e478)[*(short *)(param_1 + 100)] & **(byte **)(param_1 + 0x60)) >>
                      ((&DAT_6818e47c)[*(short *)(param_1 + 100)] & 0x1f));
  iVar1 = *(int *)(param_1 + 0x3c) + 0xe + uVar2 * 8;
  local_8 = (uint)CONCAT12(*(undefined1 *)(iVar1 + 1),
                           CONCAT11(*(undefined1 *)(iVar1 + 3),
                                    *(undefined1 *)(*(int *)(param_1 + 0x3c) + 0x13 + uVar2 * 8)));
  return local_8;
}



// ============================================================
// Function: media_writeDest4bitPixel (FUN_680a24e0)
// Address: 680a24e0
// Size: 106 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeDest4bitPixel(int param_1,undefined4 param_2)
{
  byte bVar1;
  byte *pbVar2;
  char cVar3;
  
  cVar3 = (**(code **)(param_1 + 0x24))(param_2,*(undefined4 *)(param_1 + 0x40));
  pbVar2 = *(byte **)(param_1 + 0x60);
  bVar1 = (&DAT_6818e47c)[*(short *)(param_1 + 100)];
  *pbVar2 = *pbVar2 & (&DAT_6818e478)[*(short *)(param_1 + 100) == 0];
  *pbVar2 = (&DAT_6818e478)[*(short *)(param_1 + 100)] & cVar3 << (bVar1 & 0x1f) | *pbVar2;
  *(short *)(param_1 + 100) = *(short *)(param_1 + 100) + 1;
  if (*(short *)(param_1 + 100) == 2) {
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    *(undefined2 *)(param_1 + 100) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_skipDest4bitPixel (FUN_680a2550)
// Address: 680a2550
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipDest4bitPixel(int param_1)
{
  *(short *)(param_1 + 100) = *(short *)(param_1 + 100) + 1;
  if (*(short *)(param_1 + 100) == 2) {
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    *(undefined2 *)(param_1 + 100) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_readDest1bitPixel (FUN_680a2580)
// Address: 680a2580
// Size: 35 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_readDest1bitPixel(int param_1)

{
  return (((&DAT_6818e480)[*(short *)(param_1 + 100)] & **(byte **)(param_1 + 0x60)) != 0) - 1;
}



// ============================================================
// Function: media_writeDest1bitPixel (FUN_680a25b0)
// Address: 680a25b0
// Size: 78 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeDest1bitPixel(int param_1,uint param_2)
{
  short *psVar1;
  byte *pbVar2;
  int *piVar3;
  
  psVar1 = (short *)(param_1 + 100);
  piVar3 = (int *)(param_1 + 0x60);
  pbVar2 = (byte *)*piVar3;
  if ((param_2 >> 0x10 & 0xff) + (param_2 >> 8 & 0xff) + (param_2 & 0xff) < 0x181) {
    *pbVar2 = *pbVar2 | (&DAT_6818e480)[*psVar1];
  }
  else {
    *pbVar2 = *pbVar2 & ~(&DAT_6818e480)[*psVar1];
  }
  *psVar1 = *psVar1 + 1;
  if (*psVar1 == 8) {
    *piVar3 = *piVar3 + 1;
    *psVar1 = 0;
  }
  return 0;
}



// ============================================================
// Function: media_skipDest1bitPixel (FUN_680a2600)
// Address: 680a2600
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipDest1bitPixel(int param_1)
{
  *(short *)(param_1 + 100) = *(short *)(param_1 + 100) + 1;
  if (*(short *)(param_1 + 100) == 8) {
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    *(undefined2 *)(param_1 + 100) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_getSrcColor (FUN_680a2630)
// Address: 680a2630
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getSrcColor(int param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}



// ============================================================
// Function: media_getSrcColor16 (FUN_680a2640)
// Address: 680a2640
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getSrcColor16(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}



// ============================================================
// Function: media_blendRgb24 (FUN_680a2650)
// Address: 680a2650
// Size: 200 bytes
// Params: uint param_1, uint param_2, ushort param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_blendRgb24(uint param_1,uint param_2,ushort param_3)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  undefined4 local_8;
  
  uVar2 = (uint)param_3;
  if ((byte)param_1 < (byte)param_2) {
    uVar6 = param_1 & 0xff;
    cVar1 = *(char *)((((param_2 & 0xff) - uVar6) * 0x10 - uVar2) + 0xf + DAT_681963a4);
  }
  else {
    uVar6 = param_2 & 0xff;
    cVar1 = *(char *)(((param_1 & 0xff) - uVar6) * 0x10 + uVar2 + DAT_681963a4);
  }
  bVar5 = (byte)(param_2 >> 8);
  bVar4 = (byte)(param_1 >> 8);
  if (bVar4 < bVar5) {
    cVar3 = *(char *)((((uint)bVar5 - (uint)bVar4) * 0x10 - uVar2) + 0xf + DAT_681963a4) + bVar4;
  }
  else {
    cVar3 = *(char *)(((uint)bVar4 - (uint)bVar5) * 0x10 + uVar2 + DAT_681963a4) + bVar5;
  }
  (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11(cVar3,cVar1 + (char)uVar6);
  if ((*(unsigned char *)((char *)&param_2 + 2)) <= (*(unsigned char *)((char *)&param_1 + 2))) {
    (*(unsigned int *)((char *)&local_8 + 0)) =
         CONCAT12(*(char *)(((uint)(*(unsigned char *)((char *)&param_1 + 2)) - (uint)(*(unsigned char *)((char *)&param_2 + 2))) * 0x10 + uVar2 +
                           DAT_681963a4) + (*(unsigned char *)((char *)&param_2 + 2)),(undefined2)local_8);
    local_8 = (uint)(uint3)local_8;
    return local_8;
  }
  (*(unsigned int *)((char *)&local_8 + 0)) =
       CONCAT12(*(char *)((((uint)(*(unsigned char *)((char *)&param_2 + 2)) - (uint)(*(unsigned char *)((char *)&param_1 + 2))) * 0x10 - uVar2) + 0xf +
                         DAT_681963a4) + (*(unsigned char *)((char *)&param_1 + 2)),(undefined2)local_8);
  local_8 = (uint)(uint3)local_8;
  return local_8;
}



// ============================================================
// Function: media_blendRgb15 (FUN_680a2720)
// Address: 680a2720
// Size: 227 bytes
// Params: uint param_1, uint param_2, ushort param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_blendRgb15(uint param_1,uint param_2,ushort param_3)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = (uint)param_3;
  uVar3 = (ushort)(param_1 >> 10) & 0x1f;
  uVar5 = param_2 >> 10 & 0x1f;
  if (uVar3 < (ushort)uVar5) {
    uVar3 = *(byte *)(((uVar5 - uVar3) * 0x10 - uVar1) + 0xf + DAT_681963a4) + uVar3;
  }
  else {
    uVar3 = (ushort)*(byte *)((uVar3 - uVar5) * 0x10 + uVar1 + DAT_681963a4) + (ushort)uVar5;
  }
  uVar5 = param_1 >> 5 & 0x1f;
  uVar6 = param_2 >> 5 & 0x1f;
  if ((ushort)uVar5 < (ushort)uVar6) {
    uVar4 = (ushort)*(byte *)(((uVar6 - uVar5) * 0x10 - uVar1) + 0xf + DAT_681963a4) + (ushort)uVar5
    ;
  }
  else {
    uVar4 = (ushort)*(byte *)((uVar5 - uVar6) * 0x10 + uVar1 + DAT_681963a4) + (ushort)uVar6;
  }
  uVar6 = param_1 & 0x1f;
  uVar5 = param_2 & 0x1f;
  if ((ushort)uVar6 < (ushort)uVar5) {
    uVar2 = (ushort)*(byte *)(((uVar5 - uVar6) * 0x10 - uVar1) + 0xf + DAT_681963a4) + (ushort)uVar6
    ;
  }
  else {
    uVar2 = (ushort)*(byte *)((uVar6 - uVar5) * 0x10 + uVar1 + DAT_681963a4) + (ushort)uVar5;
  }
  return ((uint)uVar3 << 5 | (uint)uVar4) << 5 | (uint)uVar2;
}



// ============================================================
// Function: media_quantizePixel (FUN_680a2810)
// Address: 680a2810
// Size: 50 bytes
// Params: uint param_1, int param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 media_quantizePixel(uint param_1,int param_2)

{
  return *(undefined1 *)
          ((((param_1 >> 3 & 0x1f0000 | param_1 & 0xf800) >> 3 | param_1 & 0xf8) >> 3) + param_2);
}



// ============================================================
// Function: media_readCompressedPixel (FUN_680a2850)
// Address: 680a2850
// Size: 99 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_readCompressedPixel(int param_1)
{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  uint3 uVar5;
  uint uVar6;
  
  puVar4 = *(undefined1 **)(param_1 + 0x44);
  uVar1 = *puVar4;
  *(undefined1 **)(param_1 + 0x44) = puVar4 + 1;
  uVar2 = puVar4[1];
  *(undefined1 **)(param_1 + 0x44) = puVar4 + 2;
  uVar3 = puVar4[2];
  *(undefined1 **)(param_1 + 0x44) = puVar4 + 3;
  uVar5 = CONCAT21(CONCAT11(uVar1,uVar2),uVar3);
  uVar6 = (uint)uVar5;
  *(uint *)(param_1 + 0x30) = uVar6;
  *(uint *)(param_1 + 0x34) = ((uVar5 >> 3 & 0x1f0000 | uVar6 & 0xf800) >> 3 | uVar6 & 0xf8) >> 3;
  return 0;
}



// ============================================================
// Function: media_advanceSrcScanline (FUN_680a28c0)
// Address: 680a28c0
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_advanceSrcScanline(void)
{
  int in_EAX;
  
  if (*(short *)(in_EAX + 8) != 0) {
    *(int *)(in_EAX + 0x48) = *(int *)(in_EAX + 0x48) + (int)*(short *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x50) = *(undefined4 *)(in_EAX + 0x48);
    *(undefined2 *)(in_EAX + 0x54) = *(undefined2 *)(in_EAX + 0x4c);
  }
  return 0;
}



// ============================================================
// Function: media_scanCompressedLine (FUN_680a28e0)
// Address: 680a28e0
// Size: 71 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_scanCompressedLine(void *this,int param_1)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  void *extraout_ECX;
  
  do {
    pcVar3 = *(char **)((int)this + 0x44);
    do {
      while( true ) {
        cVar1 = *pcVar3;
        pcVar2 = pcVar3 + 1;
        if ((cVar1 != '\0') && (cVar1 != '\x0f')) break;
        pcVar3 = pcVar3 + 2;
        if ((cVar1 == '\0') && (*pcVar2 == '\0')) {
          *(char **)((int)this + 0x44) = pcVar3;
          if (param_1 != 0) {
            media_advanceSrcScanline();
          }
          return 0;
        }
      }
      pcVar3 = pcVar2;
    } while (cVar1 != '\x1f');
    *(char **)((int)this + 0x44) = pcVar2;
    media_readCompressedPixel((int)this);
    this = extraout_ECX;
  } while( true );
}



// ============================================================
// Function: media_advanceScanlines (FUN_680a2930)
// Address: 680a2930
// Size: 27 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_advanceScanlines(void)
{
  int iVar1;
  
  iVar1 = media_advanceSrcScanline();
  *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + (int)*(short *)(iVar1 + 0x2a);
  *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(iVar1 + 0x58);
  *(undefined2 *)(iVar1 + 100) = *(undefined2 *)(iVar1 + 0x5c);
  return 0;
}



// ============================================================
// Function: media_initPixelOps (FUN_680a2950)
// Address: 680a2950
// Size: 481 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_initPixelOps(int param_1)

{
  int iVar1;
  undefined4 *in_EAX;
  int unaff_ESI;
  int *unaff_EDI;
  
  if ((unaff_EDI == (int *)0x0) && (param_1 == 0)) {
    *(undefined2 *)(unaff_ESI + 8) = 0;
    if (*(short *)(unaff_ESI + 10) == 0x10) {
      *(code **)(unaff_ESI + 0xc) = media_getSrcColor16;
    }
    else {
      *(code **)(unaff_ESI + 0xc) = media_getSrcColor;
    }
    *(code **)(unaff_ESI + 0x14) = rendering_updateDisplay;
    *(undefined4 *)(unaff_ESI + 0x48) = 0;
    *(undefined2 *)(unaff_ESI + 0x4c) = 0;
    in_EAX[3] = 0;
    in_EAX[2] = 0;
    in_EAX[1] = 0;
    *in_EAX = 0;
    return 1;
  }
  Ordinal_1060();
  if (param_1 == 0) {
    *(short *)(unaff_ESI + 8) = (short)unaff_EDI[5] - (short)unaff_EDI[6];
    *(short *)(unaff_ESI + 0x28) = (short)unaff_EDI[2];
    *(int *)(unaff_ESI + 0x38) = unaff_EDI[0x10];
    *(int *)(unaff_ESI + 0x48) = unaff_EDI[4];
    *(undefined2 *)(unaff_ESI + 0x4c) = 0;
    if (*(short *)(unaff_ESI + 8) != 8) {
      return 0;
    }
    if (*(short *)(unaff_ESI + 10) == 0x10) {
      *(code **)(unaff_ESI + 0xc) = media_readPaletteRgb16;
      *(code **)(unaff_ESI + 0x14) = media_skipSrcPixel;
      return 1;
    }
    *(code **)(unaff_ESI + 0xc) = media_readPaletteRgb24;
    *(code **)(unaff_ESI + 0x14) = media_skipSrcPixel;
  }
  else {
    iVar1 = *unaff_EDI;
    *(short *)(unaff_ESI + 10) = (short)unaff_EDI[5] - (short)unaff_EDI[6];
    *(int *)(unaff_ESI + 0x3c) = unaff_EDI[0x10];
    *(undefined4 *)(unaff_ESI + 0x40) = 0;
    *(short *)(unaff_ESI + 0x2a) = (short)unaff_EDI[2];
    *(int *)(unaff_ESI + 0x58) = unaff_EDI[4];
    if (unaff_EDI[3] != 0) {
      *(int *)(unaff_ESI + 0x58) =
           *(int *)(unaff_ESI + 0x58) + (iVar1 + -1) * (int)*(short *)(unaff_ESI + 0x2a);
      *(short *)(unaff_ESI + 0x2a) = -*(short *)(unaff_ESI + 0x2a);
    }
    *(undefined2 *)(unaff_ESI + 0x5c) = 0;
    *(undefined4 *)(unaff_ESI + 0x24) = 0;
    switch(*(undefined2 *)(unaff_ESI + 10)) {
    case 1:
      *(code **)(unaff_ESI + 0x10) = media_readDest1bitPixel;
      *(code **)(unaff_ESI + 0x20) = media_writeDest1bitPixel;
      *(code **)(unaff_ESI + 0x18) = media_skipDest1bitPixel;
      return 1;
    default:
      return 0;
    case 4:
      *(code **)(unaff_ESI + 0x10) = media_readDest4bitPixel;
      *(code **)(unaff_ESI + 0x20) = media_writeDest4bitPixel;
      *(code **)(unaff_ESI + 0x18) = media_skipDest4bitPixel;
      break;
    case 8:
      *(code **)(unaff_ESI + 0x10) = media_readDestPalettePixel;
      *(code **)(unaff_ESI + 0x20) = media_writeDestIndexedPixel;
      *(code **)(unaff_ESI + 0x18) = media_skipDestPixel;
      break;
    case 0x10:
      *(code **)(unaff_ESI + 0x10) = media_readWord;
      *(code **)(unaff_ESI + 0x20) = media_writeWord;
      *(code **)(unaff_ESI + 0x18) = media_skipWord;
      return 1;
    case 0x18:
      *(code **)(unaff_ESI + 0x10) = media_readTriple;
      *(code **)(unaff_ESI + 0x20) = media_writeTriple;
      *(code **)(unaff_ESI + 0x18) = media_skipTriple;
      return 1;
    case 0x20:
      *(code **)(unaff_ESI + 0x10) = media_readDword;
      *(code **)(unaff_ESI + 0x20) = media_writeDword;
      *(code **)(unaff_ESI + 0x18) = media_skipDword;
      return 1;
    }
    if (unaff_EDI[0x11] != 0) {
      *(code **)(unaff_ESI + 0x24) = media_quantizePixel;
      *(int *)(unaff_ESI + 0x40) = unaff_EDI[0x11];
      return 1;
    }
  }
  return 1;
}



// ============================================================
// Function: media_clipBlitRect (FUN_680a2b70)
// Address: 680a2b70
// Size: 446 bytes
// Params: int param_1, int * param_2, int * param_3, int * param_4, int * param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_clipBlitRect(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *unaff_EDI;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = *param_3;
  local_14 = param_3[1];
  local_10 = param_3[2];
  local_c = param_3[3];
  local_24 = (int)*unaff_EDI;
  local_20 = (int)unaff_EDI[1];
  local_28 = (int)unaff_EDI[2];
  local_1c = (int)unaff_EDI[3];
  iVar2 = Ordinal_1062(&local_18);
  if (iVar2 != 0) {
    Ordinal_1060(&local_18,0,0,local_20,local_1c);
  }
  iVar2 = *(int *)(param_1 + 0x38);
  iVar3 = *(int *)(param_1 + 0x30);
  iVar6 = *(int *)(param_1 + 0x34);
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar5 = *param_2;
  iVar4 = local_18;
  if (iVar5 < iVar3) {
    *param_2 = iVar3;
    iVar4 = local_18 + (iVar3 - iVar5);
  }
  iVar3 = param_2[1];
  iVar5 = local_14;
  if (iVar3 < iVar6) {
    param_2[1] = iVar6;
    iVar5 = local_14 + (iVar6 - iVar3);
  }
  if (iVar2 < param_2[2]) {
    param_2[2] = iVar2;
  }
  if (iVar1 < param_2[3]) {
    param_2[3] = iVar1;
  }
  iVar2 = *param_4;
  if ((iVar4 != iVar2) && (local_24 = iVar2 - iVar4, local_24 < 0)) {
    local_24 = iVar4 - iVar2;
  }
  iVar2 = param_4[1];
  if ((iVar5 != iVar2) && (local_28 = iVar2 - iVar5, local_28 < 0)) {
    local_28 = iVar5 - iVar2;
  }
  iVar2 = *param_2;
  if ((iVar2 < *param_5) && (iVar3 = *param_5 - iVar2, local_24 <= iVar3)) {
    local_24 = iVar3;
  }
  iVar3 = (param_2[2] - iVar2) + local_24;
  if (iVar3 < local_20) {
    local_20 = iVar3;
  }
  if (param_5[2] < (iVar2 - local_24) + local_20) {
    local_20 = param_5[2] - iVar2;
  }
  iVar2 = param_2[1];
  iVar3 = param_5[1];
  if ((iVar2 < iVar3) && (local_28 <= iVar3 - iVar2)) {
    local_28 = iVar3 - iVar2;
  }
  iVar6 = (param_2[3] - iVar2) + local_28;
  if (iVar6 < local_1c) {
    local_1c = iVar6;
  }
  if (iVar3 < iVar2) {
    if ((iVar2 - local_28) + local_1c <= param_5[3]) goto LAB_680a2d01;
    iVar2 = param_5[3] - iVar2;
  }
  else {
    if ((iVar3 - local_28) + local_1c <= param_5[3]) goto LAB_680a2d01;
    iVar2 = param_5[3] - iVar3;
  }
  local_1c = iVar2 + local_28;
LAB_680a2d01:
  unaff_EDI[1] = (short)local_20;
  unaff_EDI[2] = (short)local_28;
  *unaff_EDI = (short)local_24;
  unaff_EDI[3] = (short)local_1c;
  return 0;
}



// ============================================================
// Function: media_pixelToRgb (FUN_680a2d30)
// Address: 680a2d30
// Size: 74 bytes
// Params: byte * param_1, int param_2
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall media_pixelToRgb(byte *param_1,int param_2)

{
  uint uVar1;
  
  if (param_1[3] == 1) {
    return (uint)CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]);
  }
  if (param_2 != 0) {
    uVar1 = (uint)*param_1;
    return *(ushort *)(param_2 + 0x10 + uVar1 * 8) & 0xffffff00 |
           (*(ushort *)(param_2 + 0xe + uVar1 * 8) & 0xffffff00) << 8 |
           (uint)*(byte *)(param_2 + 0x13 + uVar1 * 8);
  }
  return 0;
}



// ============================================================
// Function: media_initBlendTable (FUN_680a2d80)
// Address: 680a2d80
// Size: 131 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_initBlendTable(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_681963ac != 0) {
    DAT_681963a4 = Ordinal_1114(DAT_681963a8);
    return 1;
  }
  DAT_681963a8 = Ordinal_1111(0x1000,0);
  if (DAT_681963a8 != 0) {
    iVar1 = Ordinal_1114(DAT_681963a8);
    uVar4 = 0;
    DAT_681963a4 = iVar1;
    do {
      uVar2 = 0;
      uVar3 = 0;
      do {
        *(char *)(iVar1 + uVar2) = (char)(uVar3 / 0xf);
        uVar2 = uVar2 + 1;
        uVar3 = uVar3 + uVar4;
      } while (uVar2 < 0x10);
      uVar4 = uVar4 + 1;
      iVar1 = iVar1 + 0x10;
    } while (uVar4 < 0x100);
    DAT_681963ac = 1;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_unlockBlendTable (FUN_680a2e10)
// Address: 680a2e10
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_unlockBlendTable(void)
{
  DAT_681963a4 = Ordinal_1115(DAT_681963a8);
  return 0;
}



// ============================================================
// Function: media_freeBlendTable (FUN_680a2e30)
// Address: 680a2e30
// Size: 30 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_freeBlendTable(void)
{
  if (DAT_681963a8 != 0) {
    Ordinal_1113(&DAT_681963a8);
    DAT_681963ac = 0;
  }
  return 0;
}



// ============================================================
// Function: media_blitCompressedLine (FUN_680a2e50)
// Address: 680a2e50
// Size: 407 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_blitCompressedLine(void)
{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  code *pcVar10;
  bool bVar11;
  ushort uVar12;
  short sVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  byte *pbVar16;
  short *unaff_ESI;
  ushort uVar17;
  uint uVar18;
  int iVar19;
  byte *local_c;
  
  pcVar5 = *(code **)(unaff_ESI + 8);
  pcVar6 = *(code **)(unaff_ESI + 0xe);
  pcVar7 = *(code **)(unaff_ESI + 0x10);
  pcVar8 = *(code **)(unaff_ESI + 6);
  uVar2 = unaff_ESI[0x16];
  pcVar9 = *(code **)(unaff_ESI + 0xc);
  sVar3 = *unaff_ESI;
  sVar4 = unaff_ESI[1];
  pcVar10 = *(code **)(unaff_ESI + 10);
  local_c = *(byte **)(unaff_ESI + 0x22);
  bVar11 = false;
  sVar13 = 0;
  if (0 < sVar4) {
    do {
      bVar1 = *local_c;
      uVar18 = (uint)bVar1;
      pbVar16 = local_c + 1;
      if (uVar18 == 0x1f) {
        *(byte **)(unaff_ESI + 0x22) = pbVar16;
        media_readCompressedPixel((int)unaff_ESI);
        sVar13 = sVar13 + -1;
        local_c = *(byte **)(unaff_ESI + 0x22);
      }
      else {
        uVar17 = (ushort)bVar1;
        if ((bVar1 == 0) || (uVar18 == 0xf)) {
          bVar1 = *pbVar16;
          uVar12 = (ushort)bVar1;
          local_c = local_c + 2;
          if ((bVar1 == 0) && (uVar17 == 0)) {
            bVar11 = true;
            break;
          }
          if (uVar2 < uVar17) {
            iVar19 = uVar18 - uVar2;
          }
          else {
            iVar19 = 0;
          }
          sVar13 = sVar13 + -1;
          if (bVar1 != 0) {
            do {
              uVar12 = uVar12 - 1;
              sVar13 = sVar13 + 1;
              if (sVar13 < sVar3) {
                (*pcVar10)();
              }
              else {
                if (sVar4 <= sVar13) goto LAB_680a2fdb;
                if ((short)iVar19 == 0) {
                  (*pcVar10)();
                  (*pcVar9)();
                }
                else {
                  uVar14 = (*pcVar8)();
                  if ((short)iVar19 == 0xf) {
                    (*pcVar7)();
                  }
                  else {
                    uVar15 = (*pcVar5)();
                    (*pcVar6)(uVar14,uVar15,iVar19);
                    (*pcVar7)();
                  }
                }
              }
            } while (uVar12 != 0);
          }
        }
        else {
          local_c = pbVar16;
          if (sVar13 < sVar3) {
            (*pcVar10)();
          }
          else if (uVar2 < uVar17) {
            uVar14 = (*pcVar8)();
            uVar15 = (*pcVar5)();
            (*pcVar6)(uVar14,uVar15,uVar18 - uVar2);
            (*pcVar7)();
          }
          else {
            (*pcVar10)();
            (*pcVar9)();
          }
        }
      }
      sVar13 = sVar13 + 1;
    } while (sVar13 < sVar4);
  }
LAB_680a2fdb:
  *(byte **)(unaff_ESI + 0x22) = local_c;
  if (!bVar11) {
    media_scanCompressedLine(unaff_ESI,0);
  }
  return 0;
}



// ============================================================
// Function: media_blitCompressedImage (FUN_680a3000)
// Address: 680a3000
// Size: 88 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_blitCompressedImage(void)
{
  short sVar1;
  short sVar2;
  void *in_EAX;
  short sVar3;
  undefined4 local_8;
  
  sVar1 = *(short *)((int)in_EAX + 4);
  sVar2 = *(short *)((int)in_EAX + 6);
  sVar3 = 0;
  if (0 < sVar2) {
    local_8 = 0;
    do {
      if (sVar3 < sVar1) {
        media_scanCompressedLine(in_EAX,1);
      }
      else {
        media_blitCompressedLine();
        if (local_8 < sVar2 + -1) {
          media_advanceScanlines();
        }
      }
      local_8 = local_8 + 1;
      sVar3 = sVar3 + 1;
    } while (sVar3 < sVar2);
  }
  return 0;
}



// ============================================================
// Function: media_performBlit (FUN_680a3060)
// Address: 680a3060
// Size: 563 bytes
// Params: int param_1, int * param_2, undefined4 param_3, int * param_4, undefined1 * param_5, int * param_6, byte * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_performBlit(int param_1,int *param_2,undefined4 param_3,int *param_4,undefined1 *param_5,
                 int *param_6,byte *param_7)
{
  undefined1 *puVar1;
  int iVar2;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int *local_34;
  undefined1 *local_30;
  undefined4 local_2c;
  int local_28 [4];
  int local_18 [4];
  uint local_8;
  
  local_38 = param_3;
  local_34 = param_4;
  local_48 = *param_2;
  local_30 = param_5;
  local_44 = param_2[1];
  local_40 = param_2[2];
  local_3c = param_2[3];
  local_2c = 0;
  iVar2 = media_initBlendTable();
  if ((iVar2 != 0) && ((*param_6 == 4 || (*param_6 == 10)))) {
    media_pixelToRgb(param_7,*(int *)(param_1 + 0x40));
    iVar2 = media_initPixelOps(1);
    if ((iVar2 != 0) && (iVar2 = media_initPixelOps(0), puVar1 = local_30, iVar2 != 0)) {
      xtra_readBE16(local_30);
      xtra_readBE16(puVar1 + 2);
      media_clipBlitRect(param_1,&local_48,local_34,local_28,local_18);
      media_blitCompressedImage();
      local_2c = 1;
    }
  }
  media_unlockBlendTable();
  return 0;
}



// ============================================================
// Function: media_executeBlitOp (FUN_680a32a0)
// Address: 680a32a0
// Size: 543 bytes
// Params: undefined4 param_1, int * param_2, undefined1 * param_3, int * param_4, undefined4 param_5, int * param_6, undefined4 * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_executeBlitOp(undefined4 param_1,int *param_2,undefined1 *param_3,int *param_4,
                 undefined4 param_5,int *param_6,undefined4 *param_7)
{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 local_c4;
  int local_c0;
  undefined1 *local_bc;
  undefined4 local_b8;
  undefined1 local_b4 [16];
  int local_a4;
  undefined1 local_68 [16];
  int local_58;
  int local_3c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_bc = param_3;
  puVar3 = (undefined1 *)0x0;
  local_b8 = 0;
  local_c0 = 0;
  if (param_2 == (int *)0x0) {
LAB_680a34ac:
    return 0;
  }
  iVar1 = Ordinal_1062(param_2);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = Ordinal_1630(param_1,local_68);
  if (iVar1 == 0) goto LAB_680a34ac;
  uVar2 = local_b8;
  if (((local_58 == 0) || (param_4 == (int *)0x0)) ||
     (iVar1 = Ordinal_1062(param_4), uVar2 = local_b8, iVar1 != 0)) goto LAB_680a3474;
  if (local_bc != (undefined1 *)0x0) {
    iVar1 = Ordinal_1630(local_bc,local_b4);
    uVar2 = local_b8;
    if (iVar1 != 0) goto LAB_680a3474;
    local_c0 = 1;
    puVar3 = local_b4;
    if (local_a4 == 0) goto LAB_680a3474;
  }
  local_bc = (undefined1 *)Ordinal_1114(param_5);
  uVar2 = local_b8;
  if (local_bc != (undefined1 *)0x0) {
    if (param_6 != (int *)0x0) {
      local_1c = *param_6;
      local_18 = param_6[1];
      local_14 = param_6[2];
      local_10 = param_6[3];
      local_c = param_6[4];
      if ((*param_6 == 2) || (*param_6 == 0xc)) {
        Ordinal_1631(local_68,&local_14);
      }
      if (param_7 != (undefined4 *)0x0) {
        local_c4 = *param_7;
        Ordinal_1631(local_68,&local_c4);
        if ((local_3c == 0) && ((puVar3 == (undefined1 *)0x0 || (*(int *)(puVar3 + 0x2c) == 0)))) {
          media_performBlit((int)local_68,param_2,puVar3,param_4,local_bc,&local_1c,(byte *)&local_c4);
          Ordinal_1115(param_5);
          uVar2 = 1;
          goto LAB_680a3474;
        }
      }
    }
    uVar2 = local_b8;
    Ordinal_1115(param_5);
  }
LAB_680a3474:
  Ordinal_1632(local_68,uVar2);
  if (local_c0 != 0) {
    Ordinal_1632(local_b4,0);
  }
  return 0;
}



// ============================================================
// Function: media_applyPixelOp (FUN_680a34c0)
// Address: 680a34c0
// Size: 819 bytes
// Params: int param_1, undefined4 param_2, undefined1 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_applyPixelOp(int param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4)
{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_420 [24];
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  switch(param_2) {
  case 0:
    if (DAT_68196354 != (code *)0x0) {
      puVar5 = &local_408;
      puVar4 = (undefined1 *)0x0;
LAB_680a352f:
      puVar3 = (undefined1 *)0x0;
LAB_680a3530:
      iVar1 = ((code *)(size_t)DAT_68196354)(puVar3,puVar4,puVar5);
      if (iVar1 != 0) {
        Ordinal_1203(param_3,local_407,param_4);
        break;
      }
    }
    goto LAB_680a354c;
  case 1:
    if (*(int *)(param_1 + 0x74) != 0) {
      Ordinal_1130(param_3,param_4);
      (**(code **)(param_1 + 0x74))(param_3,param_4);
    }
    break;
  case 2:
    if (DAT_68196354 != (code *)0x0) {
      puVar5 = (undefined1 *)0x0;
      puVar4 = (undefined1 *)0x0;
      puVar3 = &local_408;
      goto LAB_680a3530;
    }
    goto LAB_680a354c;
  case 3:
    if (DAT_68196354 != (code *)0x0) {
      puVar5 = (undefined1 *)0x0;
      puVar4 = &local_408;
      goto LAB_680a352f;
    }
LAB_680a354c:
    *param_3 = 0;
    break;
  case 4:
    iVar1 = DAT_681956e0;
    if (*(int *)(param_1 + 8) != 0) {
      iVar1 = *(int *)(param_1 + 8);
    }
    Ordinal_1320(local_420,iVar1);
    Ordinal_1310(local_420,param_3,0x3ff);
    break;
  case 5:
    Ordinal_1203(param_3,"Director",param_4);
    break;
  case 6:
    Ordinal_59(param_3);
    break;
  case 7:
    if (((param_1 == 0) || (*(code **)(param_1 + 0x1b8) == (code *)0x0)) ||
       (iVar1 = (**(code **)(param_1 + 0x1b8))(param_3,param_4), iVar1 == 0)) {
      Ordinal_1203(param_3,&DAT_6817c828,param_4);
    }
    break;
  case 8:
    uVar2 = Ordinal_1261();
    switch(uVar2) {
    case 0:
switchD_680a36da_caseD_0:
      Ordinal_1203(param_3,"English",param_4);
      break;
    case 1:
      Ordinal_1203(param_3,"Japanese",param_4);
      break;
    case 2:
      Ordinal_1203(param_3,"French",param_4);
      break;
    case 3:
      Ordinal_1203(param_3,"German",param_4);
      break;
    default:
      Ordinal_1203(param_3,"Other",param_4);
      break;
    case 9:
      Ordinal_1203(param_3,"Korean",param_4);
    }
    break;
  case 9:
    uVar2 = Ordinal_1262();
    switch(uVar2) {
    case 0:
      goto switchD_680a36da_caseD_0;
    case 1:
      Ordinal_1203(param_3,"Japanese",param_4);
      break;
    case 2:
      Ordinal_1203(param_3,"French",param_4);
      break;
    case 3:
      Ordinal_1203(param_3,"German",param_4);
      break;
    case 4:
      Ordinal_1203(param_3,"Portuguese",param_4);
      break;
    case 5:
      Ordinal_1203(param_3,"Italian",param_4);
      break;
    case 6:
      Ordinal_1203(param_3,"Spanish",param_4);
      break;
    case 7:
      Ordinal_1203(param_3,"Swedish",param_4);
      break;
    case 8:
      Ordinal_1203(param_3,"Chinese",param_4);
      break;
    case 9:
      Ordinal_1203(param_3,"Korean",param_4);
      break;
    case 10:
      Ordinal_1203(param_3,"Arabic",param_4);
      break;
    case 0xb:
      Ordinal_1203(param_3,"Hebrew",param_4);
      break;
    default:
      Ordinal_1203(param_3,"Other",param_4);
    }
    break;
  default:
    break;
  case 0xb:
    iVar1 = Ordinal_1334(local_420,2);
    if (iVar1 != 0) {
      Ordinal_1310(local_420,param_3,0x3ff);
    }
  }
  return 0;
}
