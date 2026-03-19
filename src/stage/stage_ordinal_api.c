// Module: stage
// Topic: Ordinal export API wrappers
// Address range: 0x6805F8D0 - 0x6805FFE0
// Functions (40):
//   Ordinal_931 (FUN_6805F8D0)
//   Ordinal_902 (FUN_6805F900)
//   Ordinal_940 (FUN_6805F920)
//   Ordinal_943 (FUN_6805F950)
//   Ordinal_941 (FUN_6805F990)
//   Ordinal_942 (FUN_6805F9D0)
//   Ordinal_910 (FUN_6805FA20)
//   Ordinal_911 (FUN_6805FA80)
//   Ordinal_912 (FUN_6805FAB0)
//   Ordinal_233 (FUN_6805FAD0)
//   Ordinal_891 (FUN_6805FAF0)
//   Ordinal_892 (FUN_6805FB10)
//   Ordinal_905 (FUN_6805FB30)
//   Ordinal_894 (FUN_6805FB90)
//   Ordinal_948 (FUN_6805FBC0)
//   Ordinal_947 (FUN_6805FBF0)
//   Ordinal_893 (FUN_6805FC20)
//   Ordinal_895 (FUN_6805FC40)
//   Ordinal_896 (FUN_6805FC60)
//   Ordinal_897 (FUN_6805FC90)
//   Ordinal_900 (FUN_6805FCC0)
//   Ordinal_898 (FUN_6805FCF0)
//   Ordinal_906 (FUN_6805FD30)
//   Ordinal_899 (FUN_6805FD70)
//   Ordinal_4006 (FUN_6805FDB0)
//   Ordinal_4005 (FUN_6805FDC0)
//   Ordinal_4001 (FUN_6805FDD0)
//   Ordinal_4002 (FUN_6805FDF0)
//   stage_parseExpression (FUN_6805FE10)
//   Ordinal_4003 (FUN_6805FE30)
//   Ordinal_4007 (FUN_6805FE60)
//   Ordinal_4008 (FUN_6805FE90)
//   Ordinal_4010 (FUN_6805FEB0)
//   Ordinal_4011 (FUN_6805FEE0)
//   Ordinal_4004 (FUN_6805FF00)
//   Ordinal_4009 (FUN_6805FF30)
//   Ordinal_4100 (FUN_6805FF60)
//   Ordinal_901 (FUN_6805FF90)
//   Ordinal_904 (FUN_6805FFB0)
//   Ordinal_907 (FUN_6805FFE0)

// ============================================================
// Function: Ordinal_931
// Address: 6805f8d0
// Size: 33 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_931(int param_1,int *param_2,uint param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0x5f8d0  931   */
  bVar1 = cast_checkHandlerArgs(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  return CONCAT31(extraout_var,bVar1) != 0;
}



// ============================================================
// Function: Ordinal_902
// Address: 6805f900
// Size: 31 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_902(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)
{
                    /* 0x5f900  902   */
  crt_invokeHandlerCallback(*(int **)(param_1 + 0xc),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: Ordinal_940
// Address: 6805f920
// Size: 37 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_940(int param_1,undefined4 *param_2,int param_3)
{
                    /* 0x5f920  940   */
  *(undefined4 *)(param_1 + 0x148) = 0;
  cast_getHandlerString(*(int **)(param_1 + 0xc),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_943
// Address: 6805f950
// Size: 52 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_943(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x5f950  943   */
  uVar2 = 0;
  piVar1 = (int *)stage_collectSpriteProperties(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    uVar2 = stage_processEventData(param_1,piVar1);
    events_updateMovieNav(param_1,piVar1);
  }
  return uVar2;
}



// ============================================================
// Function: Ordinal_941
// Address: 6805f990
// Size: 58 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 Ordinal_941(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
                    /* 0x5f990  941   */
  uVar1 = *(undefined4 *)(param_1 + 0x148);
  *(uint *)(param_1 + 0x148) = ((int)param_3 < 0) - 1 & param_3;
  uVar2 = cast_handleGetProperty(*(undefined4 *)(param_1 + 0xc),param_2);
  *(undefined4 *)(param_1 + 0x148) = uVar1;
  return uVar2;
}



// ============================================================
// Function: Ordinal_942
// Address: 6805f9d0
// Size: 68 bytes
// Params: int param_1, undefined4 * param_2, uint param_3, int * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_942(int param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* 0x5f9d0  942   */
  uVar1 = *(undefined4 *)(param_1 + 0x148);
  *(uint *)(param_1 + 0x148) = ((int)param_3 < 0) - 1 & param_3;
  iVar2 = cast_handlePropertyAccess(*(int **)(param_1 + 0xc),param_2,param_4);
  *(undefined4 *)(param_1 + 0x148) = uVar1;
  return iVar2 != 0;
}



// ============================================================
// Function: Ordinal_910
// Address: 6805fa20
// Size: 91 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 Ordinal_910(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined8 local_c;
  
                    /* 0x5fa20  910   */
  pvVar1 = *(void **)(param_1 + 0xc);
  iVar2 = cast_invokeNamedHandler(pvVar1,*param_2);
  if (iVar2 != 0) {
    cast_storeReturnType(pvVar1,iVar2,(undefined4 *)&local_c);
    Ordinal_1113(param_2);
    return local_c;
  }
  props_clearValue(pvVar1,(undefined4 *)&local_c);
  Ordinal_1113(param_2);
  return local_c;
}



// ============================================================
// Function: Ordinal_911
// Address: 6805fa80
// Size: 48 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_911(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x5fa80  911   */
  piVar1 = (int *)cast_getProplistValue(*(undefined4 *)(param_1 + 0xc),param_2);
  if (piVar1 != (int *)0x0) {
    uVar2 = stage_processEventData(param_1,piVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_912
// Address: 6805fab0
// Size: 23 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_912(int param_1,int param_2)
{
                    /* 0x5fab0  912   */
  cast_lookupEventId(*(undefined4 *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_233
// Address: 6805fad0
// Size: 24 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_233(int param_1)

{
                    /* 0x5fad0  233   */
  return *(int *)(*(int *)(param_1 + 0xc) + 300) == 0;
}



// ============================================================
// Function: Ordinal_891
// Address: 6805faf0
// Size: 27 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_891(int param_1,undefined4 param_2,int *param_3)
{
                    /* 0x5faf0  891   */
  props_evalExpression(*(int **)(param_1 + 0xc),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_892
// Address: 6805fb10
// Size: 27 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_892(int param_1,undefined4 param_2,undefined4 param_3)
{
                    /* 0x5fb10  892   */
  cast_assignVariable(*(int **)(param_1 + 0xc),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_905
// Address: 6805fb30
// Size: 96 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_905(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x5fb30  905   */
  iVar1 = Ordinal_1201(param_2);
  iVar2 = Ordinal_1201(param_3);
  if (iVar1 != iVar2) {
    return 0;
  }
  iVar2 = props_lookupSymbol(*(undefined4 *)(param_1 + 0xc),param_2,iVar1);
  iVar1 = props_lookupSymbol(*(undefined4 *)(param_1 + 0xc),param_3,iVar1);
  if (iVar2 == iVar1) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_894
// Address: 6805fb90
// Size: 39 bytes
// Params: int param_1, int * param_2, int param_3, undefined2 * param_4, int * param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_894(int param_1,int *param_2,int param_3,undefined2 *param_4,int *param_5,int *param_6)
{
                    /* 0x5fb90  894   */
  cast_getSlotInfo(*(int *)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: Ordinal_948
// Address: 6805fbc0
// Size: 39 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, short param_5, undefined2 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_948(int param_1,int *param_2,int param_3,int param_4,short param_5,undefined2 *param_6)
{
                    /* 0x5fbc0  948   */
  cast_checkSlotBounds(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: Ordinal_947
// Address: 6805fbf0
// Size: 35 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_947(int param_1,int *param_2,int param_3,undefined4 *param_4,undefined4 *param_5)
{
                    /* 0x5fbf0  947   */
  cast_getSlotTypeAndValue(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: Ordinal_893
// Address: 6805fc20
// Size: 23 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_893(int param_1,int *param_2)
{
                    /* 0x5fc20  893   */
  cast_getPropertyCount(*(undefined4 *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_895
// Address: 6805fc40
// Size: 27 bytes
// Params: int param_1, int * param_2, void * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_895(int param_1,int *param_2,void *param_3)
{
                    /* 0x5fc40  895   */
  strings_debugStepOver(*(int *)(param_1 + 0xc),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_896
// Address: 6805fc60
// Size: 35 bytes
// Params: int param_1, int * param_2, int param_3, void * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_896(int param_1,int *param_2,int param_3,void *param_4,uint *param_5)
{
                    /* 0x5fc60  896   */
  strings_debugAccessBreakpoint(*(int *)(param_1 + 0xc),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: Ordinal_897
// Address: 6805fc90
// Size: 35 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_897(int param_1,int *param_2,int param_3,undefined4 param_4,int *param_5)
{
                    /* 0x5fc90  897   */
  cast_findSlotByPosition(*(int *)(param_1 + 0xc),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: Ordinal_900
// Address: 6805fcc0
// Size: 41 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_900(int param_1,int *param_2)
{
  int local_8;
  
                    /* 0x5fcc0  900   */
  local_8 = 0;
  strings_debugGetFrameCount(*(int *)(param_1 + 0xc),&local_8);
  *param_2 = local_8;
  return 0;
}



// ============================================================
// Function: Ordinal_898
// Address: 6805fcf0
// Size: 49 bytes
// Params: int param_1, void * param_2, undefined2 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_898(int param_1,void *param_2,undefined2 *param_3,int *param_4)
{
  int local_8;
  
                    /* 0x5fcf0  898   */
  local_8 = 0;
  strings_debugGetFrameEntry(*(int *)(param_1 + 0xc),param_2,param_3,&local_8);
  *param_4 = local_8;
  return 0;
}



// ============================================================
// Function: Ordinal_906
// Address: 6805fd30
// Size: 54 bytes
// Params: int param_1, short param_2, int * param_3, int * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_906(int param_1,short param_2,int *param_3,int *param_4,undefined4 *param_5)
{
  int local_8;
  
                    /* 0x5fd30  906   */
  local_8 = 0;
  strings_debugGetScopeInfo(*(int *)(param_1 + 0xc),(void *)(int)param_2,param_3,&local_8,param_5);
  *param_4 = local_8;
  return 0;
}



// ============================================================
// Function: Ordinal_899
// Address: 6805fd70
// Size: 55 bytes
// Params: int param_1, void * param_2, int param_3, undefined1 * param_4, undefined2 * param_5, undefined4 * param_6, undefined4 * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_899(int param_1,void *param_2,int param_3,undefined1 *param_4,undefined2 *param_5,
                undefined4 *param_6,undefined4 *param_7)
{
                    /* 0x5fd70  899   */
  strings_debugGetContextValue(*(undefined **)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6,
               (int *)&param_6);
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_6;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_4006
// Address: 6805fdb0
// Size: 9 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4006(undefined4 *param_1,undefined4 param_2)
{
                    /* 0x5fdb0  4006   */
  props_parseToken(param_1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_4005
// Address: 6805fdc0
// Size: 9 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4005(int *param_1,undefined4 param_2,int param_3)
{
                    /* 0x5fdc0  4005   */
  props_hashSymbol(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_4001
// Address: 6805fdd0
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4001(int param_1)
{
                    /* 0x5fdd0  4001   */
  Ordinal_132(param_1);
  props_peekNextOffset();
  return 0;
}



// ============================================================
// Function: Ordinal_4002
// Address: 6805fdf0
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4002(int param_1)
{
                    /* 0x5fdf0  4002   */
  Ordinal_132(param_1);
  props_getCurrentToken();
  return 0;
}



// ============================================================
// Function: stage_parseExpression (FUN_6805fe10)
// Address: 6805fe10
// Size: 29 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_parseExpression(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = Ordinal_132(param_1);
  props_parseExpression(*(int *)(iVar1 + 8),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_4003
// Address: 6805fe30
// Size: 37 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4003(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  
                    /* 0x5fe30  4003   */
  iVar1 = Ordinal_132(param_1);
  props_setParserState(*(undefined4 *)(iVar1 + 8),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_4007
// Address: 6805fe60
// Size: 37 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4007(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  
                    /* 0x5fe60  4007   */
  iVar1 = Ordinal_132(param_1);
  props_resolveTokenSafe(*(int *)(iVar1 + 8),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_4008
// Address: 6805fe90
// Size: 20 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4008(undefined4 param_1,int param_2,undefined4 *param_3)
{
                    /* 0x5fe90  4008   */
  props_pushTokenEntry(param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_4010
// Address: 6805feb0
// Size: 39 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_4010(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
                    /* 0x5feb0  4010   */
  iVar1 = Ordinal_132(param_1);
  iVar1 = props_dispatchExtMethod(*(undefined4 *)(iVar1 + 8),param_2,param_3);
  return iVar1 != 0;
}



// ============================================================
// Function: Ordinal_4011
// Address: 6805fee0
// Size: 22 bytes
// Params: undefined4 param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool Ordinal_4011(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0x5fee0  4011   */
  bVar1 = props_isParserReady(param_2);
  return CONCAT31(extraout_var,bVar1) != 0;
}



// ============================================================
// Function: Ordinal_4004
// Address: 6805ff00
// Size: 41 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4004(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)
{
  int iVar1;
  
                    /* 0x5ff00  4004   */
  iVar1 = Ordinal_132(param_1);
  props_parseBlock(*(undefined4 *)(iVar1 + 8),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: Ordinal_4009
// Address: 6805ff30
// Size: 33 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4009(int param_1,undefined4 param_2)
{
  int iVar1;
  
                    /* 0x5ff30  4009   */
  iVar1 = Ordinal_132(param_1);
  props_searchSymbolTable(*(undefined4 *)(iVar1 + 8),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_4100
// Address: 6805ff60
// Size: 33 bytes
// Params: int param_1, byte param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_4100(int param_1,byte param_2,int *param_3)
{
  int iVar1;
  
                    /* 0x5ff60  4100   */
  iVar1 = Ordinal_132(param_1);
  props_releaseValue(*(undefined4 *)(iVar1 + 8),param_2,param_3);
  return 0;
}



// ============================================================
// Function: Ordinal_901
// Address: 6805ff90
// Size: 23 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_901(int param_1,int param_2)
{
                    /* 0x5ff90  901   */
  strings_debugToggleStep(*(int *)(param_1 + 0xc),param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_904
// Address: 6805ffb0
// Size: 39 bytes
// Params: int param_1, int param_2, byte * param_3, undefined4 * param_4, int * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_904(int param_1,int param_2,byte *param_3,undefined4 *param_4,int *param_5,
                undefined4 *param_6)
{
                    /* 0x5ffb0  904   */
  cast_resolveHandlerByName(*(int *)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: Ordinal_907
// Address: 6805ffe0
// Size: 23 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_907(int param_1,int *param_2)
{
                    /* 0x5ffe0  907   */
  sprites_getDesktopRect(*(int *)(param_1 + 0xc),param_2);
  return 0;
}



