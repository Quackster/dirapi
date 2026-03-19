// Module: strings
// Topic: Lingo symbol registration, compiler parsing, event context management
// Address range: 0x6816dd80 - 0x6816f070
// Functions (31):
//   strings_compileHandler
//   strings_registerProperties
//   strings_registerCodeBlocks
//   strings_invokeLingoHandler
//   strings_releaseLingoContext
//   strings_accessLingoProperty
//   strings_markLingoContextDirty
//   strings_disposeLingoContext
//   strings_createLingoContext
//   strings_getLingoContextTarget
//   strings_dispatchLingoContext
//   strings_wrapGetPropertyPair
//   strings_wrapGetPropertyValue
//   strings_wrapSetPropertyValue
//   strings_wrapFormatValue1
//   strings_wrapFormatValue2
//   strings_wrapFormatValue3
//   strings_wrapFormatValue4
//   strings_wrapFormatValue5
//   strings_wrapResolveSymbol
//   strings_wrapGetSymbolNext
//   strings_wrapGetSymbolString
//   strings_wrapGetValueType
//   strings_wrapRetainValue
//   strings_wrapReleaseValue
//   strings_wrapCoerceToInt
//   strings_wrapCoerceToFloat
//   strings_wrapCoerceToDouble
//   strings_wrapGetComponentCount
//   strings_wrapCoerceToStringNext
//   strings_wrapCoerceToString

// ============================================================
// Function: strings_compileHandler (FUN_6816dd80)
// Address: 6816dd80
// Size: 113 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_compileHandler(void *param_1)
{
  int local_c;
  int local_8;
  
  stage_compileHandler(param_1,strings_compileHandlerArgs);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_pushCurrentScope((int)param_1);
    if (((local_c == 8) && (local_8 == 0x45)) &&
       (stage_compileHandler(param_1,lingo_noop), *(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0)) {
      return 0;
    }
    stage_emitReturn();
  }
  return 0;
}



// ============================================================
// Function: strings_registerProperties (FUN_6816de00)
// Address: 6816de00
// Size: 1967 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_registerProperties(int param_1)
{
  stage_storeProperty(param_1,0x164,0x68194f30);
  stage_storeProperty(param_1,0x165,0x68194f3c);
  stage_storeProperty(param_1,0x173,0x68194f54);
  stage_storeProperty(param_1,0x166,0x68194f48);
  stage_storeProperty(param_1,0x167,0x68194f60);
  stage_storeProperty(param_1,0x52,0x68194f6c);
  stage_storeProperty(param_1,0x53,0x68194f78);
  stage_storeProperty(param_1,0x47,0x68194f84);
  stage_storeProperty(param_1,0x50,0x68194f90);
  stage_storeProperty(param_1,0x46,0x68194f9c);
  stage_storeProperty(param_1,0x51,0x68194fa8);
  stage_storeProperty(param_1,0x168,0x6819508c);
  stage_storeProperty(param_1,0x169,0x681950c8);
  stage_storeProperty(param_1,0x16a,0x68194fb4);
  stage_storeProperty(param_1,0x16b,0x68194fc0);
  stage_storeProperty(param_1,0x16c,0x68194fcc);
  stage_storeProperty(param_1,0x16d,0x68194fd8);
  stage_storeProperty(param_1,0x1e2,0x68194fe4);
  stage_storeProperty(param_1,0x1f5,0x68195014);
  stage_storeProperty(param_1,0x336,0x68195020);
  stage_storeProperty(param_1,0x2d8,0x6819502c);
  stage_storeProperty(param_1,0x2d9,0x68195038);
  stage_storeProperty(param_1,0x58,0x68195044);
  stage_storeProperty(param_1,0x314,0x68195050);
  stage_storeProperty(param_1,0x139,0x6819505c);
  stage_storeProperty(param_1,0x49,0x68195080);
  stage_storeProperty(param_1,0x48,0x68195074);
  stage_storeProperty(param_1,0xbc,0x68195068);
  stage_storeProperty(param_1,0x18b,0x681950ec);
  stage_storeProperty(param_1,0x33e,0x681950f8);
  stage_storeProperty(param_1,900,0x68195104);
  stage_storeProperty(param_1,0x18c,0x68195110);
  stage_storeProperty(param_1,0x18d,0x6819511c);
  stage_storeProperty(param_1,0x18e,0x68195128);
  stage_storeProperty(param_1,399,0x68195134);
  stage_storeProperty(param_1,400,0x68195140);
  stage_storeProperty(param_1,0x191,0x6819514c);
  stage_storeProperty(param_1,0x192,0x68195158);
  stage_storeProperty(param_1,0x193,0x68195170);
  stage_storeProperty(param_1,0x194,0x68195164);
  stage_storeProperty(param_1,0x195,0x6819517c);
  stage_storeProperty(param_1,0x197,0x68195188);
  stage_storeProperty(param_1,0x198,0x68195194);
  stage_storeProperty(param_1,0x199,0x681951a0);
  stage_storeProperty(param_1,0x19a,0x681951ac);
  stage_storeProperty(param_1,0x19b,0x681951b8);
  stage_storeProperty(param_1,0x19c,0x681951c4);
  stage_storeProperty(param_1,0x19d,0x681951d0);
  stage_storeProperty(param_1,0x19e,0x681951dc);
  stage_storeProperty(param_1,0x1df,0x6819520c);
  stage_storeProperty(param_1,0x1ed,0x681951e8);
  stage_storeProperty(param_1,0x339,0x681951f4);
  stage_storeProperty(param_1,0x33b,0x68195200);
  stage_storeProperty(param_1,0xaa,0x68195218);
  stage_storeProperty(param_1,0x103,0x681952b4);
  stage_storeProperty(param_1,0xfb,0x681952e4);
  stage_storeProperty(param_1,0x118,0x681952f0);
  stage_storeProperty(param_1,0x178,0x681952fc);
  stage_storeProperty(param_1,0x2f1,0x681952fc);
  stage_storeProperty(param_1,0x179,0x6819532c);
  stage_storeProperty(param_1,0x2ef,0x6819532c);
  stage_storeProperty(param_1,0x17a,0x6819535c);
  stage_storeProperty(param_1,0x2b4,0x6819535c);
  stage_storeProperty(param_1,0x17b,0x68195380);
  stage_storeProperty(param_1,0x2ee,0x68195380);
  stage_storeProperty(param_1,0x17c,0x681953a4);
  stage_storeProperty(param_1,0x2f0,0x681953a4);
  stage_storeProperty(param_1,0x19f,0x681953d4);
  stage_storeProperty(param_1,0x1a0,0x681953e0);
  stage_storeProperty(param_1,0x1a1,0x681953f8);
  stage_storeProperty(param_1,0x7b,0x68195410);
  stage_storeProperty(param_1,0x1a3,0x68195428);
  stage_storeProperty(param_1,0x1a4,0x68195434);
  stage_storeProperty(param_1,0x1a5,0x68195440);
  stage_storeProperty(param_1,0x1a6,0x6819544c);
  stage_storeProperty(param_1,0x1a7,0x68195458);
  stage_storeProperty(param_1,0x39,0x68195464);
  stage_storeProperty(param_1,0x3a,0x68195470);
  stage_storeProperty(param_1,0x79,0x6819547c);
  stage_storeProperty(param_1,0x78,0x68195488);
  stage_storeProperty(param_1,0x1a8,0x68195494);
  stage_storeProperty(param_1,0x3c,0x681954a0);
  stage_storeProperty(param_1,0x1a9,0x681954ac);
  stage_storeProperty(param_1,0x1aa,0x681954b8);
  stage_storeProperty(param_1,0x1ab,0x681954c4);
  stage_storeProperty(param_1,0x1ac,0x681954d0);
  stage_storeProperty(param_1,0x1ad,0x681954dc);
  stage_storeProperty(param_1,0x1ae,0x681954e8);
  stage_storeProperty(param_1,0x1af,0x681954f4);
  stage_storeProperty(param_1,0x1b0,0x68195500);
  stage_storeProperty(param_1,0x1b1,0x6819550c);
  stage_storeProperty(param_1,0x15f,0x68195518);
  stage_storeProperty(param_1,0x1b2,0x68195524);
  stage_storeProperty(param_1,0x1b3,0x68195530);
  stage_storeProperty(param_1,0x3c3,0x6819553c);
  stage_storeProperty(param_1,0x1b4,0x68195548);
  stage_storeProperty(param_1,0x1b5,0x68195554);
  stage_storeProperty(param_1,0x1b6,0x68195560);
  stage_storeProperty(param_1,0x1b7,0x6819556c);
  stage_storeProperty(param_1,0x1b8,0x68195578);
  stage_storeProperty(param_1,0x1b9,0x68195584);
  stage_storeProperty(param_1,0x338,0x68195590);
  stage_storeProperty(param_1,0x1ba,0x6819559c);
  stage_storeProperty(param_1,0x1bb,0x681955a8);
  stage_storeProperty(param_1,0x1bc,0x681955b4);
  stage_storeProperty(param_1,0x1bd,0x681955c0);
  stage_storeProperty(param_1,0x1be,0x681955cc);
  stage_storeProperty(param_1,0x1bf,0x681955d8);
  stage_storeProperty(param_1,0x1c0,0x681955e4);
  stage_storeProperty(param_1,0x196,0x681955f0);
  stage_storeProperty(param_1,0x1c1,0x68195608);
  stage_storeProperty(param_1,0x163,0x68195608);
  stage_storeProperty(param_1,0x1c2,0x68195614);
  stage_storeProperty(param_1,0x1c3,0x68195620);
  stage_storeProperty(param_1,0x1c4,0x6819562c);
  stage_storeProperty(param_1,0x1ec,0x681955fc);
  stage_storeProperty(param_1,0x23a,0x68195638);
  stage_storeProperty(param_1,0x23b,0x68195644);
  stage_storeProperty(param_1,0x235,0x68194ff0);
  stage_storeProperty(param_1,0x16e,0x68194ffc);
  stage_storeProperty(param_1,0x16f,0x68195008);
  stage_storeProperty(param_1,0x273,0x68195008);
  stage_storeProperty(param_1,0x237,0x681950d4);
  stage_storeProperty(param_1,0x236,0x681950e0);
  stage_storeProperty(param_1,0x248,0x68195650);
  return 0;
}



// ============================================================
// Function: strings_registerCodeBlocks (FUN_6816e5b0)
// Address: 6816e5b0
// Size: 105 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_registerCodeBlocks(int param_1)
{
  stage_emitCodeBlock(param_1,0x161,0x6816d800);
  stage_emitCodeBlock(param_1,0x162,0x6816d980);
  stage_emitCodeBlock(param_1,0x118,0x6816dac0);
  stage_emitCodeBlock(param_1,0x1a2,0x6816dcd0);
  stage_emitCodeBlock(param_1,0x54,0x6816dd40);
  stage_emitCodeBlock(param_1,0x14b,0x6816dd80);
  return 0;
}



// ============================================================
// Function: strings_invokeLingoHandler (FUN_6816e620)
// Address: 6816e620
// Size: 425 bytes
// Params: uint param_1, int * param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_invokeLingoHandler(uint param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint *local_8;
  
  iVar6 = 0;
  local_c = 0x80000001;
  if (param_3 == (uint *)0xe3) {
    score_resolveType(param_1);
    return 1;
  }
  uVar3 = core_getAsyncState(param_1);
  if (uVar3 == 0) {
    return 0;
  }
  local_14 = *(int *)(*param_2 + 0x14);
  piVar1 = *(int **)(*param_2 + 0x10);
  if (param_3 == (uint *)0x82) {
    param_3 = (uint *)0xfe;
  }
  uVar4 = props_lookupVariable(param_1,piVar1,(uint)param_3);
  if (-1 < (int)uVar4) {
    local_10 = core_getHandlerArgAt(param_1,piVar1,uVar4);
    uVar4 = props_getInt(param_1);
    if ((int)uVar4 < 1) {
      uVar4 = 0;
      param_3 = (uint *)0x0;
    }
    else {
      param_3 = (uint *)xtra_getPropertyById(uVar3,uVar4 * 4);
      iVar6 = 0;
      if (param_3 == (uint *)0x0) goto LAB_6816e7b7;
    }
    param_2 = (int *)0x0;
    if (0 < (int)uVar4) {
      local_8 = param_3;
      do {
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + ((int)param_2 - *(int *)(param_1 + 0x20)) * 8 +
                     *(int *)(param_1 + 0x18));
        local_18 = DAT_6819776c;
        local_1c = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_18 = ((int *)(size_t)_DAT_68197764)[1];
          local_1c = *(int *)(size_t)_DAT_68197764;
        }
        iVar5 = cast_readScoreXtraData(param_1,uVar3,&local_1c,local_8);
        iVar6 = 0;
        if (iVar5 == 0) goto LAB_6816e78a;
        local_8 = local_8 + 1;
        param_2 = (int *)((int)param_2 + 1);
      } while ((int)param_2 < (int)uVar4);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x74);
    iVar6 = xtra_validateExtension(uVar3,local_14,local_10,uVar4,(int)param_3,(int *)&local_c);
    if ((iVar6 == 0) && (*(int *)(param_1 + 0x74) == 9)) {
      iVar6 = 1;
    }
    *(undefined4 *)(param_1 + 0x74) = uVar2;
LAB_6816e78a:
    xtra_checkAndFlush(uVar3,(int)param_3);
    if (iVar6 != 0) {
      cast_dispatchScoreXtra(param_1,uVar3,local_c,&local_1c);
      props_popArgs(param_1,&local_1c);
    }
  }
LAB_6816e7b7:
  core_dispatchScript(param_1,uVar3);
  return iVar6;
}



// ============================================================
// Function: strings_releaseLingoContext (FUN_6816e7d0)
// Address: 6816e7d0
// Size: 124 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_releaseLingoContext(uint param_1,int *param_2)
{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)(**(int **)(param_1 + 8) + 0x580) != 0) {
    if (*(int **)(*param_2 + 0x10) != (int *)0x0) {
      props_releaseContext(param_1,*(int **)(*param_2 + 0x10));
    }
    *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
    *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
    uVar1 = *(uint *)(*param_2 + 0x14);
    uVar2 = core_getAsyncState(param_1);
    if (uVar2 != 0) {
      xtra_resolveMethodId(uVar2,uVar1);
      core_dispatchScript(param_1,uVar2);
    }
    cast_freeHandle(param_2);
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  }
  return 0;
}



// ============================================================
// Function: strings_accessLingoProperty (FUN_6816e850)
// Address: 6816e850
// Size: 359 bytes
// Params: uint param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_accessLingoProperty(uint param_1,int *param_2,int param_3,int param_4,uint *param_5)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 local_41c [4];
  uint *local_418;
  uint local_414;
  uint local_410;
  int local_40c;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;
  
  local_410 = param_1;
  local_418 = param_5;
  local_40c = 0;
  iVar2 = core_getAsyncState(param_1);
  if (iVar2 != 0) {
    piVar1 = *(int **)(*param_2 + 0x14);
    score_lookupSymbol(DAT_68196304,param_4,(int)&local_408);
    if (param_3 == 0) {
      xtraRuntime_getPropertyByName(iVar2,piVar1,local_407,local_41c,&local_40c);
      if (((local_40c != 0) && (iVar3 = xtraRuntime_getPropertyValue(iVar2,piVar1,local_407,&local_414), iVar3 != 0)
          ) && (local_414 != 0x80000001)) {
        cast_dispatchScoreXtra(local_410,iVar2,local_414,local_418);
      }
    }
    else if (((param_3 == 2) ||
             (xtraRuntime_getPropertyByName(iVar2,piVar1,local_407,local_41c,&local_40c), param_1 = local_410,
             local_40c != 0)) &&
            (iVar3 = cast_readScoreXtraData(param_1,iVar2,local_418,&local_414), iVar3 != 0)) {
      xtra_parsePathEx(iVar2,piVar1,local_407,&local_414);
    }
    core_dispatchScript(local_410,iVar2);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: strings_markLingoContextDirty (FUN_6816e9d0)
// Address: 6816e9d0
// Size: 57 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_markLingoContextDirty(undefined4 param_1,int *param_2)
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = *(int **)(*param_2 + 0x10);
  puVar1 = (uint *)(*param_2 + 4);
  *puVar1 = *puVar1 | 0x80000000;
  if (piVar2 != (int *)0x0) {
    uVar3 = *(uint *)(*piVar2 + 4);
    if (-1 < (int)uVar3) {
      *(uint *)(*piVar2 + 4) = uVar3 | 0x80000000;
      (**(code **)(*(int *)*piVar2 + 0x34))(param_1,piVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: strings_disposeLingoContext (FUN_6816ea10)
// Address: 6816ea10
// Size: 33 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_disposeLingoContext(undefined4 param_1,int *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*param_2 + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
  }
  return 0;
}



// ============================================================
// Function: strings_createLingoContext (FUN_6816ea40)
// Address: 6816ea40
// Size: 235 bytes
// Params: int param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * strings_createLingoContext(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  piVar3 = (int *)cast_allocHandle(0x18,0);
  if (piVar3 != (int *)0x0) {
    uVar4 = core_getAsyncState(param_1);
    if (uVar4 != 0) {
      uVar5 = core_getHandlerIndex(param_1,param_2);
      uVar5 = xtra_loadResource(uVar4,(undefined **)0x0,(undefined4 *)(uVar5 & 0xfffffff8),
                           uVar5 & 0xfffffff8);
      if (uVar5 == 0) {
        cast_freeHandle(piVar3);
        core_dispatchScript(param_1,uVar4);
        return (int *)0x0;
      }
      xtra_getMethodById(uVar4,uVar5);
      puVar1 = (undefined4 *)*piVar3;
      *puVar1 = &PTR_LAB_68195660;
      puVar1[1] = 1;
      puVar1[4] = param_2;
      puVar1[5] = uVar5;
      iVar2 = **(int **)(param_1 + 8);
      *(undefined4 *)(*piVar3 + 8) = *(undefined4 *)(**(int **)(iVar2 + 0x564) + 8);
      *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar2 + 0x564);
      *(int **)(**(int **)(**(int **)(iVar2 + 0x564) + 8) + 0xc) = piVar3;
      *(int **)(**(int **)(iVar2 + 0x564) + 8) = piVar3;
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
      props_retainObject(param_1,param_2);
      core_dispatchScript(param_1,uVar4);
      return piVar3;
    }
    cast_freeHandle(piVar3);
  }
  return (int *)0x0;
}



// ============================================================
// Function: strings_getLingoContextTarget (FUN_6816eb30)
// Address: 6816eb30
// Size: 33 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_getLingoContextTarget(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*(undefined ***)*param_1 == &PTR_LAB_68195660)) {
    return ((int *)*param_1)[4];
  }
  return 0;
}



// ============================================================
// Function: strings_dispatchLingoContext (FUN_6816eb60)
// Address: 6816eb60
// Size: 44 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_dispatchLingoContext(int param_1,int *param_2)
{
  if ((*(uint *)(*param_2 + 0x54) & 0x4000) != 0) {
    strings_createLingoContext(param_1,param_2);
    return 0;
  }
  cast_dispatchContext(param_1,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapGetPropertyPair (FUN_6816eb90)
// Address: 6816eb90
// Size: 63 bytes
// Params: undefined4 param_1, uint param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetPropertyPair(undefined4 param_1,uint param_2,uint param_3,uint *param_4,int *param_5)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getPropertyPair(local_8,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: strings_wrapGetPropertyValue (FUN_6816ebd0)
// Address: 6816ebd0
// Size: 57 bytes
// Params: undefined4 param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetPropertyValue(undefined4 param_1,uint param_2,uint *param_3)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getPropertyValue(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapSetPropertyValue (FUN_6816ec10)
// Address: 6816ec10
// Size: 57 bytes
// Params: undefined4 param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapSetPropertyValue(undefined4 param_1,uint param_2,uint *param_3)

{
  uint local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_setPropertyAndDispatch(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapFormatValue1 (FUN_6816ec50)
// Address: 6816ec50
// Size: 53 bytes
// Params: undefined4 param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapFormatValue1(undefined4 param_1,byte *param_2)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_wrapFormatValue1(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapFormatValue2 (FUN_6816ec90)
// Address: 6816ec90
// Size: 57 bytes
// Params: undefined4 param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapFormatValue2(undefined4 param_1,byte *param_2)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_wrapFormatValue2(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapFormatValue3 (FUN_6816ecd0)
// Address: 6816ecd0
// Size: 61 bytes
// Params: undefined4 param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapFormatValue3(undefined4 param_1,byte *param_2)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_wrapFormatValue3(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapFormatValue4 (FUN_6816ed10)
// Address: 6816ed10
// Size: 65 bytes
// Params: undefined4 param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapFormatValue4(undefined4 param_1,byte *param_2)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_wrapFormatValue4(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapFormatValue5 (FUN_6816ed60)
// Address: 6816ed60
// Size: 69 bytes
// Params: undefined4 param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapFormatValue5(undefined4 param_1,byte *param_2)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_wrapFormatValue5(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapResolveSymbol (FUN_6816edb0)
// Address: 6816edb0
// Size: 55 bytes
// Params: undefined4 param_1, char * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapResolveSymbol(undefined4 param_1,char *param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_resolveSymbolByName(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapGetSymbolNext (FUN_6816edf0)
// Address: 6816edf0
// Size: 61 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetSymbolNext(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getSymbolStringNext(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapGetSymbolString (FUN_6816ee30)
// Address: 6816ee30
// Size: 61 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetSymbolString(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getSymbolString(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapGetValueType (FUN_6816ee70)
// Address: 6816ee70
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetValueType(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getValueType(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapRetainValue (FUN_6816eeb0)
// Address: 6816eeb0
// Size: 51 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapRetainValue(undefined4 param_1,uint *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_retainValueWithCallback(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapReleaseValue (FUN_6816eef0)
// Address: 6816eef0
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapReleaseValue(undefined4 param_1,int *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_releaseValue(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapCoerceToInt (FUN_6816ef30)
// Address: 6816ef30
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCoerceToInt(undefined4 param_1,uint *param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_coerceToInt(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapCoerceToFloat (FUN_6816ef70)
// Address: 6816ef70
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCoerceToFloat(undefined4 param_1,uint *param_2,uint *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_coerceToFloat(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapCoerceToDouble (FUN_6816efb0)
// Address: 6816efb0
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, double * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCoerceToDouble(undefined4 param_1,uint *param_2,double *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_coerceToDouble(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapGetComponentCount (FUN_6816eff0)
// Address: 6816eff0
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetComponentCount(undefined4 param_1,uint *param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getComponentCount(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapCoerceToStringNext (FUN_6816f030)
// Address: 6816f030
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined1 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCoerceToStringNext(undefined4 param_1,uint *param_2,undefined1 *param_3,int param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_coerceToStringNext(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapCoerceToString (FUN_6816f070)
// Address: 6816f070
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined1 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCoerceToString(undefined4 param_1,uint *param_2,undefined1 *param_3,int param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_coerceToString(local_8,param_2,param_3,param_4);
  return 0;
}



