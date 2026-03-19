// Source: decompiled_functions.c
// Module: crypto
// Address range: 0x681405d0 - 0x681405d0
// Functions (1):
//   crypto_bigEval (crypto_bigEval)

// ============================================================
// Function: crypto_bigEval (crypto_bigEval)
// Address: 681405d0
// Size: 11834 bytes
// Params: uint * param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_bigEval(uint *param_1,uint *param_2,int *param_3)
{
  double dVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  void *pvVar5;
  size_t sVar6;
  int *piVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  int iVar11;
  undefined1 uVar12;
  uint uVar13;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 uVar14;
  int iVar15;
  byte *pbVar16;
  undefined1 *puVar17;
  float10 fVar18;
  float10 extraout_ST0;
  ulonglong uVar19;
  uint *puVar20;
  undefined4 local_48c [6];
  undefined4 local_474;
  int local_46c;
  int local_468;
  uint *local_464;
  int local_460;
  undefined4 local_45c;
  void *local_458;
  void *local_454;
  uint *local_450;
  void *local_448;
  uint *local_444;
  undefined8 local_440;
  void *local_438;
  uint *local_434;
  int local_430;
  uint *local_42c;
  uint local_428;
  uint *local_424;
  undefined1 *local_420;
  int *local_41c;
  uint *local_418;
  uint *local_414;
  int *local_410;
  int *local_40c;
  undefined1 local_408 [1024];
  
  param_2[0x26] = param_2[0x26] + 1;
  local_430 = 1;
  local_42c = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
  param_3[4] = (int)local_42c;
  uVar4 = (uint)*(ushort *)((int)param_3 + 6);
  uVar13 = uVar4 - param_2[0x13];
  local_418 = param_1;
  local_424 = param_2;
  local_41c = param_3;
  local_440 = (double)CONCAT44(uVar13,(int)local_440);
  uVar14 = 0;
  if (uVar13 != 0) {
    param_2[0x13] = uVar4;
    if (uVar13 < (uint)(0x7f < uVar4) * 2 + 2) {
      do {
        uVar4 = js_allocObject((int)param_1,(int)param_2,0x16);
        if ((int)uVar4 < 0) goto LAB_6814065c;
        iVar11 = (*(unsigned int *)((char *)&local_440 + 4)) + -1;
        local_440 = (double)CONCAT44(iVar11,(int)local_440);
        uVar14 = extraout_ECX_00;
      } while (iVar11 != 0);
    }
    else {
      uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,0x17,uVar4);
      uVar14 = extraout_ECX;
      if ((int)uVar4 < 0) goto LAB_6814065c;
    }
  }
  switch(*param_3) {
  case 2:
    local_40c = (int *)param_3[6];
    if (local_40c != (int *)0x0) {
      iVar11 = *(int *)(param_1[0xd] + 0x10);
      if (((iVar11 == 0) || (*(int *)(iVar11 + 8) != 0)) ||
         ((*(byte *)(param_1[0xd] + 0x4c) & 0xc) != 0)) {
        iVar11 = 1;
      }
      else {
        iVar11 = 0;
      }
      local_46c = iVar11;
      if (iVar11 == 0) {
        uVar4 = js_enumerateKeys((uint)param_1,param_2,local_40c,&local_46c);
        if (uVar4 == 0) goto LAB_6814065c;
        if (local_46c == 0) {
          param_2[0x13] = (uint)*(ushort *)((int)local_40c + 6);
          uVar4 = strings_scanToken(param_1,0,(int)param_2,5,0xa3);
          goto joined_r0x68142f2f;
        }
      }
      iVar15 = crypto_bigEval(param_1,param_2,local_40c);
      if (iVar15 == 0) goto LAB_6814065c;
      puVar20 = (uint *)((-(uint)(iVar11 != 0) & 0xffffffb1) + 0x51);
      goto LAB_6814093a;
    }
    break;
  case 3:
    local_40c = (int *)param_3[6];
    local_428 = 0xffffffff;
    local_420 = (undefined1 *)0xffffffff;
    iVar11 = crypto_bigEval(param_1,param_2,local_40c);
    while (iVar11 != 0) {
      puVar17 = (undefined1 *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
      if ((-1 < (int)local_428) &&
         (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,(int)puVar17 - (int)local_420
                               ), iVar11 == 0)) goto LAB_6814065c;
      if (local_40c[10] == 0) goto switchD_6814069b_caseD_26;
      local_420 = puVar17;
      local_428 = crypto_evalExpression((uint)param_1,(int)param_2,7,0);
      if (((int)local_428 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x51), iVar11 < 0))
      goto LAB_6814065c;
      local_40c = (int *)local_40c[10];
      iVar11 = crypto_bigEval(param_1,param_2,local_40c);
    }
    goto LAB_6814081e;
  case 4:
    piVar7 = (int *)param_3[6];
    local_410 = (int *)0xffffffff;
    piVar8 = local_410;
    local_40c = piVar7;
    switch(*piVar7) {
    case 0x16:
      iVar11 = crypto_bigEval(param_1,param_2,(int *)piVar7[7]);
      if ((iVar11 == 0) ||
         (puVar9 = js_createAtom((int)param_1,local_40c[6],param_2 + 0x15),
         puVar9 == (undefined4 *)0x0)) goto LAB_6814065c;
      piVar8 = (int *)puVar9[3];
      break;
    case 0x17:
      iVar11 = crypto_bigEval(param_1,param_2,(int *)piVar7[6]);
      if (iVar11 == 0) goto LAB_6814065c;
      iVar11 = crypto_bigEval(param_1,param_2,(int *)local_40c[7]);
      goto joined_r0x681429a5;
    case 0x1b:
      iVar11 = crypto_bigEval(param_1,param_2,piVar7);
joined_r0x681429a5:
      piVar8 = local_410;
      if (iVar11 == 0) goto LAB_6814081e;
      break;
    case 0x1d:
      iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
      if (iVar11 == 0) goto LAB_6814065c;
      param_3 = local_41c;
      piVar8 = (int *)piVar7[8];
      if (piVar7[8] < 0) {
        puVar9 = js_createAtom((int)param_1,piVar7[6],param_2 + 0x15);
        if (puVar9 == (undefined4 *)0x0) goto LAB_6814065c;
        local_410 = (int *)puVar9[3];
        iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x6c,(char)((uint)local_410 >> 8),(char)local_410
                             );
        param_3 = local_41c;
        piVar8 = local_410;
        if (iVar11 < 0) goto LAB_6814081e;
      }
    }
    local_410 = piVar8;
    local_414 = (uint *)param_3[3];
    if (((local_414 == (uint *)0x7b) || (local_414 == (uint *)0x7c)) || (local_414 == (uint *)0x0))
    goto switchD_681428dc_caseD_18;
    switch(*local_40c) {
    case 0x16:
switchD_681428dc_caseD_16:
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0xc);
      if (iVar11 < 0) goto LAB_6814065c;
      iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x35,(char)((uint)local_410 >> 8),(char)local_410);
      goto joined_r0x681429d9;
    case 0x17:
    case 0x1b:
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0xd);
      if ((iVar11 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x37), iVar11 < 0))
      goto LAB_6814065c;
      break;
    case 0x1d:
      if (local_40c[3] == 0x6d) goto switchD_681428dc_caseD_16;
      iVar11 = js_setMultipleFlags(param_1,(int)param_2,(local_40c[3] != 0x55) * '\x02' + 'T',
                            (char)((uint)local_410 >> 8),(char)local_410);
joined_r0x681429d9:
      if (iVar11 < 0) goto LAB_6814081e;
    }
switchD_681428dc_caseD_18:
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[7]);
    puVar20 = local_414;
    if (((iVar11 == 0) ||
        ((local_414 != (uint *)0x0 &&
         ((uVar4 = js_allocObject((int)param_1,(int)param_2,8), (int)uVar4 < 0 ||
          (iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)puVar20), iVar11 < 0)))))) ||
       ((piVar7 = local_40c, *local_40c != 0x1d &&
        (uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,0xc,
                              (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) - (int)local_42c),
        (int)uVar4 < 0)))) {
LAB_6814065c:
      return 0;
    }
    switch(*piVar7) {
    case 0x16:
switchD_68142aa7_caseD_16:
LAB_68142ac2:
      iVar11 = piVar7[3];
      uVar12 = (undefined1)((uint)local_410 >> 8);
      piVar7 = local_410;
      goto LAB_6814080f;
    case 0x17:
    case 0x1b:
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x38);
      goto LAB_68140816;
    case 0x1d:
      if (piVar7[8] < 0) goto LAB_68142ac2;
      if ((*(byte *)(piVar7 + 9) & 2) == 0) goto switchD_68142aa7_caseD_16;
    }
    break;
  case 5:
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if ((((iVar11 == 0) ||
         (local_428 = js_allocObject((int)param_1,(int)param_2,9), (int)local_428 < 0)) ||
        (local_420 = (undefined1 *)js_defineProperty(param_2,param_1,7), (int)local_420 < 0)) ||
       ((iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[7]), iVar11 == 0 ||
        (local_414 = (uint *)js_defineProperty(param_2,param_1,6), (int)local_414 < 0))))
    goto LAB_6814065c;
    piVar7 = (int *)param_2[0x10];
    iVar11 = js_storeProperty((uint)param_1,(int)param_2,(int)(local_420 + *piVar7),
                          (piVar7[2] - *piVar7) - (int)local_420);
    if ((iVar11 == 0) ||
       (iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[8]), puVar20 = local_414, iVar11 == 0))
    goto LAB_6814065c;
    piVar7 = (int *)param_2[0x10];
    iVar11 = js_storeProperty((uint)param_1,(int)param_2,(int)(*piVar7 + (int)local_414),
                          (piVar7[2] - *piVar7) - (int)local_414);
    if ((iVar11 == 0) ||
       (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,(int)puVar20 - (int)local_420),
       iVar11 == 0)) goto LAB_6814065c;
    param_2[0x18] = param_2[0x18] - 1;
    break;
  case 6:
    local_434 = (uint *)param_3[6];
    puVar9 = js_createAtom((int)param_1,(int)local_434,param_2 + 0x15);
    if (puVar9 == (undefined4 *)0x0) goto LAB_6814065c;
    piVar7 = (int *)param_3[7];
    uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,(*piVar7 == 0x19) + 0xd,puVar9[3]);
    if (((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0), iVar11 < 0))
    goto LAB_6814065c;
    js_initPropertySlot((int)param_2,&local_468,1,((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    local_450 = local_434;
    iVar11 = crypto_bigEval(param_1,param_2,piVar7);
    if ((iVar11 == 0) || (iVar11 = js_deleteProperty((uint)param_1,(int)param_2), iVar11 == 0))
    goto LAB_6814065c;
    if (*piVar7 == 0x19) {
      uVar4 = js_allocObject((int)param_1,(int)param_2,0xf);
      if ((int)uVar4 < 0) goto LAB_6814081e;
      puVar20 = (uint *)0x0;
      goto LAB_6814093a;
    }
    break;
  case 7:
  case 8:
    local_410 = param_3;
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if ((iVar11 != 0) &&
       (local_42c = (uint *)js_defineProperty(param_2,param_1,0x96), -1 < (int)local_42c)) {
      local_414 = local_42c;
      for (local_40c = (int *)param_3[7]; (*local_40c == 7 || (*local_40c == 8));
          local_40c = (int *)local_40c[7]) {
        iVar11 = crypto_bigEval(param_1,param_2,(int *)local_40c[6]);
        if ((iVar11 == 0) ||
           ((puVar20 = (uint *)js_defineProperty(param_2,param_1,0x96), (int)puVar20 < 0 ||
            (iVar11 = javascript_objectSetSetter((uint)local_418), iVar11 == 0)))) goto LAB_6814065c;
        param_1 = local_418;
        param_2 = local_424;
        local_414 = puVar20;
      }
      iVar11 = crypto_bigEval(param_1,param_2,local_40c);
      if (iVar11 != 0) {
        local_420 = (undefined1 *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
        goto LAB_68142cc2;
      }
    }
    goto LAB_6814065c;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x2f:
  case 0x3b:
    piVar7 = (int *)param_3[6];
    if (param_3[5] != -2) {
      iVar11 = crypto_bigEval(param_1,param_2,piVar7);
      if ((iVar11 == 0) || (iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[7]), iVar11 == 0))
      goto LAB_6814065c;
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)param_3[3]);
      goto LAB_68140816;
    }
    local_40c = piVar7;
    iVar11 = crypto_bigEval(param_1,param_2,piVar7);
    if (iVar11 == 0) goto LAB_6814065c;
    local_414 = (uint *)param_3[3];
    for (piVar7 = (int *)local_40c[10]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[10]) {
      iVar11 = crypto_bigEval(param_1,param_2,piVar7);
      if ((iVar11 == 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)local_414), iVar11 < 0)
         ) goto LAB_6814065c;
    }
    break;
  case 0x13:
  case 0x3a:
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)param_3[3]);
    goto LAB_68140816;
  case 0x14:
  case 0x15:
    piVar8 = (int *)param_3[6];
    iVar11 = param_3[3];
    local_40c = piVar8;
    switch(*piVar8) {
    case 0x16:
LAB_68142e61:
      bVar3 = crypto_evalAssignment((uint)param_1,piVar8,iVar11);
      uVar4 = CONCAT31(extraout_var_03,bVar3);
      break;
    case 0x17:
      bVar3 = crypto_matchOperator((int)piVar8,iVar11);
      uVar4 = CONCAT31(extraout_var_04,bVar3);
      break;
    default:
      goto switchD_6814069b_caseD_26;
    case 0x1b:
      iVar15 = crypto_bigEval(param_1,param_2,piVar8);
      if ((iVar15 == 0) ||
         (uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,0xc,
                               (((int *)param_2[0x10])[2] - local_40c[4]) - *(int *)param_2[0x10]),
         (int)uVar4 < 0)) goto LAB_6814065c;
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)iVar11);
      goto LAB_68140816;
    case 0x1d:
      piVar8[3] = iVar11;
      iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
      if (iVar11 == 0) goto LAB_6814065c;
      piVar7 = (int *)piVar8[8];
      iVar11 = piVar8[3];
      if (-1 < (int)piVar7) {
        if ((*(byte *)(piVar8 + 9) & 2) != 0) {
          iVar11 = 0x56;
        }
        uVar12 = (undefined1)((uint)piVar7 >> 8);
        goto LAB_6814080f;
      }
      bVar3 = js_hasProperty(piVar8,(char)iVar11);
      uVar4 = CONCAT31(extraout_var_02,bVar3);
    }
joined_r0x68142f2f:
    if (uVar4 == 0) goto LAB_6814081e;
    break;
  case 0x16:
    bVar3 = crypto_evalAssignment((uint)param_1,param_3,param_3[3]);
    local_430 = CONCAT31(extraout_var_07,bVar3);
    goto LAB_68140be0;
  case 0x17:
    bVar3 = crypto_matchOperator((int)param_3,param_3[3]);
    local_430 = CONCAT31(extraout_var_08,bVar3);
    goto LAB_68140be0;
  case 0x18:
    puVar9 = js_createAtom((int)param_1,*(int *)(param_1[5] + 0xa4),param_2 + 0x15);
    if (((puVar9 == (undefined4 *)0x0) ||
        (iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x3b,(char)((uint)puVar9[3] >> 8),
                               *(undefined1 *)(puVar9 + 3)), iVar11 < 0)) ||
       ((iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x39), iVar11 < 0 ||
        (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x59), iVar11 < 0)))) goto LAB_6814065c;
    local_40c = (int *)param_3[6];
    if ((local_40c != (int *)0x0) && (*local_40c == 0x35)) {
      iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x5d,(char)((uint)local_40c[7] >> 8),
                            (char)local_40c[7]);
      if (iVar11 < 0) goto LAB_6814065c;
      local_40c = (int *)local_40c[10];
    }
    local_410 = (int *)0x0;
    for (; local_40c != (int *)0x0; local_40c = (int *)local_40c[10]) {
      if (local_410 == (int *)0x0) {
        iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x3e);
      }
      else if (local_410 == (int *)0x1) {
        iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x3f);
      }
      else {
        iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x58,(char)((uint)local_410 >> 8),(char)local_410
                             );
      }
      if (iVar11 < 0) goto LAB_6814065c;
      if (*local_40c == 3) {
        iVar11 = js_setPropertyFlag(param_1,(int)param_2,1);
        if (iVar11 < 0) goto LAB_6814065c;
      }
      else {
        iVar11 = crypto_bigEval(param_1,param_2,local_40c);
        if (iVar11 == 0) goto LAB_6814065c;
      }
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x5c);
      if (iVar11 < 0) goto LAB_6814065c;
      local_410 = (int *)((int)local_410 + 1);
    }
    if ((param_3[9] != 0) && (uVar4 = js_allocObject((int)param_1,(int)param_2,5), (int)uVar4 < 0))
    goto LAB_6814065c;
    goto LAB_68143183;
  case 0x19:
    js_initPropertySlot((int)param_2,&local_468,0,local_42c);
    for (piVar7 = (int *)param_3[6]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[10]) {
      iVar11 = crypto_bigEval(param_1,param_2,piVar7);
      if (iVar11 == 0) goto LAB_6814065c;
    }
    goto LAB_68140bdb;
  case 0x1a:
    local_444 = param_2 + 0x15;
    local_434 = js_createAtom((int)param_1,*(int *)(param_1[5] + 0xc4),local_444);
    if ((((local_434 == (uint *)0x0) ||
         (iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x3b,(char)(local_434[3] >> 8),
                                (char)local_434[3]), iVar11 < 0)) ||
        (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x39), iVar11 < 0)) ||
       (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x59), iVar11 < 0)) goto LAB_6814065c;
    piVar7 = (int *)param_3[6];
    local_40c = piVar7;
    if (piVar7 != (int *)0x0) {
      uVar14 = extraout_ECX_01;
      if (*piVar7 == 0x35) {
        iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x5d,(char)((uint)piVar7[7] >> 8),(char)piVar7[7]
                             );
        if (iVar11 < 0) goto LAB_6814065c;
        piVar7 = (int *)piVar7[10];
        uVar14 = extraout_ECX_02;
      }
      local_40c = piVar7;
      if (piVar7 != (int *)0x0) {
        do {
          local_410 = (int *)local_40c[6];
          iVar11 = *local_410;
          if (iVar11 == 0x1d) {
LAB_68143260:
            local_434 = js_createAtom((int)param_1,local_410[6],local_444);
            puVar20 = local_434;
joined_r0x681432f6:
            if (puVar20 == (uint *)0x0) goto LAB_6814065c;
          }
          else {
            if (iVar11 == 0x1e) {
              bVar3 = javascript_objectEnumerateSlots(uVar14,local_410,(int)*(undefined8 *)(local_410 + 6),
                                   (uint)((ulonglong)*(undefined8 *)(local_410 + 6) >> 0x20));
              param_2 = local_424;
              param_1 = local_418;
              puVar20 = (uint *)CONCAT31(extraout_var_09,bVar3);
              goto joined_r0x681432f6;
            }
            if (iVar11 == 0x1f) goto LAB_68143260;
          }
          piVar7 = local_40c;
          iVar11 = crypto_bigEval(param_1,param_2,(int *)local_40c[7]);
          if ((iVar11 == 0) ||
             (((iVar11 = piVar7[3], iVar11 == 0x7b || (iVar11 == 0x7c)) &&
              (iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)iVar11), iVar11 < 0))))
          goto LAB_6814065c;
          if (*local_410 == 0x1e) {
            uVar4 = js_allocObject((int)param_1,(int)param_2,0xd);
            if ((int)uVar4 < 0) goto LAB_6814065c;
            iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x5c);
            uVar14 = extraout_ECX_03;
          }
          else {
            iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x5b,(char)(local_434[3] >> 8),
                                  (char)local_434[3]);
            uVar14 = extraout_ECX_04;
          }
          if (iVar11 < 0) goto LAB_6814065c;
          local_40c = (int *)piVar7[10];
        } while (local_40c != (int *)0x0);
        iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x5a);
        goto LAB_68140816;
      }
    }
LAB_68143183:
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x5a);
    goto LAB_68140816;
  case 0x1b:
  case 0x33:
    local_40c = (int *)param_3[6];
    iVar11 = crypto_bigEval(param_1,param_2,local_40c);
    if (iVar11 == 0) goto LAB_6814065c;
    local_420 = (undefined1 *)local_40c[4];
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x39);
    if (iVar11 < 0) goto LAB_6814065c;
    for (local_40c = (int *)local_40c[10]; local_40c != (int *)0x0; local_40c = (int *)local_40c[10]
        ) {
      iVar11 = crypto_bigEval(param_1,param_2,local_40c);
      if (iVar11 == 0) goto LAB_6814065c;
    }
    uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,0xc,
                         (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) - (int)local_420);
    if ((int)uVar4 < 0) goto LAB_6814065c;
    iVar11 = param_3[3];
    uVar12 = (undefined1)(param_3[8] - 1U >> 8);
    piVar7 = (int *)(param_3[8] - 1U);
    goto LAB_6814080f;
  case 0x1c:
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x83);
    goto LAB_68140816;
  case 0x1d:
    iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
    if (iVar11 == 0) goto LAB_6814065c;
    iVar11 = param_3[3];
    if (iVar11 != 9) {
      piVar7 = (int *)param_3[8];
      if ((int)piVar7 < 0) goto switchD_6814069b_caseD_1f;
      uVar12 = (undefined1)((uint)piVar7 >> 8);
      goto LAB_6814080f;
    }
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,9);
    goto LAB_68140816;
  case 0x1e:
    bVar3 = javascript_objectEnumerateSlots(uVar14,param_3,(int)*(undefined8 *)(param_3 + 6),
                         (uint)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20));
    local_430 = CONCAT31(extraout_var_11,bVar3);
    goto LAB_68140be0;
  case 0x1f:
  case 0x20:
switchD_6814069b_caseD_1f:
    bVar3 = js_hasProperty(local_41c,(char)local_41c[3]);
    local_430 = CONCAT31(extraout_var_10,bVar3);
    goto LAB_68140be0;
  case 0x21:
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)param_3[3]);
    goto LAB_68140816;
  case 0x22:
    uVar4 = param_1[0x20];
    local_440 = (double)CONCAT44(*(undefined4 *)(uVar4 + 0xc),(int)local_440);
    uVar13 = param_1[0x22] + 0x9c & ~param_1[0x22];
    local_414 = *(uint **)(uVar4 + 0xc);
    pbVar16 = (byte *)((int)local_414 + uVar13);
    if (*(byte **)(uVar4 + 8) < pbVar16) {
      local_414 = (uint *)js_getSlotIndex((int)(param_1 + 0x1c),uVar13);
    }
    else {
      *(byte **)(uVar4 + 0xc) = pbVar16;
    }
    if (local_414 == (uint *)0x0) goto LAB_681406ef;
    iVar11 = javascript_hashTableInsert((int)param_1,local_414,param_2[0x11],(uint)*(ushort *)((int)param_3 + 6),
                          param_2[0x14]);
    if (iVar11 == 0) goto LAB_6814065c;
    *local_414 = param_3[8] | 2;
    local_414[1] = param_3[9];
    local_444 = (uint *)param_3[6];
    iVar11 = javascript_objectIsSealed((uint)param_1,(byte *)local_414,param_3[7],(int)local_444);
    if (iVar11 == 0) goto LAB_6814065c;
    if ((*local_414 & 0xc0) != 0) {
      *param_2 = *param_2 | 0x80;
    }
    javascript_hashTableLookup((int)param_1,(int)local_414);
    puVar20 = (uint *)param_1[0x20];
    if ((puVar20 == param_1 + 0x1c) || (puVar20[3] - puVar20[1] < (*(unsigned int *)((char *)&local_440 + 4)) - puVar20[1])) {
      js_getPrototype((int *)(param_1 + 0x1c),(*(unsigned int *)((char *)&local_440 + 4)));
    }
    else {
      *(uint *)(param_1[0x20] + 0xc) = param_1[0x22] + (*(unsigned int *)((char *)&local_440 + 4)) & ~param_1[0x22];
    }
    iVar11 = javascript_gcSweepObject((int)param_1,local_444[1],0);
    if ((iVar11 == 0) ||
       (puVar9 = js_createAtom((int)param_1,iVar11,param_2 + 0x15), puVar9 == (undefined4 *)0x0))
    goto LAB_6814065c;
    local_410 = (int *)puVar9[3];
    iVar11 = param_3[3];
    if (iVar11 != 0) {
      uVar12 = (undefined1)((uint)local_410 >> 8);
      piVar7 = local_410;
      goto LAB_6814080f;
    }
    uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,0x13,(uint)local_410);
    if (((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0), iVar11 < 0))
    goto LAB_6814065c;
    param_2[0x10] = (uint)(param_2 + 10);
    if ((*param_2 & 2) == 0) {
      iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x7d,(char)((uint)local_410 >> 8),(char)local_410);
      if (iVar11 < 0) goto LAB_6814065c;
      param_2[0x10] = (uint)(param_2 + 0xd);
    }
    else {
      iVar11 = runtime_getProperty((uint)param_1,
                            (int *)(*(uint *)(*(int *)(local_444[1] + 4) + 4) & 0xfffffff8),
                            local_444[6],&local_444,(uint *)&local_434);
      if (iVar11 == 0) goto LAB_6814065c;
      local_440 = (double)CONCAT44((int)*(short *)((int)local_434 + 0x12),(int)local_440);
      pcVar2 = *(code **)(*(int *)(*local_444 + 4) + 0x34);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(param_1,local_444,local_434);
      }
      iVar11 = javascript_hashTableCount(param_1,(int)param_2,0x8a,4);
      if (iVar11 < 0) goto LAB_6814065c;
      iVar11 = *(int *)param_2[0x10] + iVar11;
      *(char *)(iVar11 + 2) = (char)((ulonglong)local_440 >> 0x20);
      *(char *)(iVar11 + 1) = (char)((ulonglong)local_440 >> 0x28);
      *(char *)(iVar11 + 4) = (char)local_410;
      *(char *)(iVar11 + 3) = (char)((uint)local_410 >> 8);
      param_2[0x10] = (uint)(param_2 + 0xd);
    }
    break;
  case 0x23:
    piVar7 = (int *)param_3[6];
    if (*piVar7 == 0x11) {
      puVar20 = (uint *)0x4b;
      goto LAB_6814093a;
    }
    do {
      puVar9 = js_createAtom((int)param_1,piVar7[6],param_2 + 0x15);
      if ((puVar9 == (undefined4 *)0x0) ||
         (iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x4c,(char)((uint)puVar9[3] >> 8),
                                *(undefined1 *)(puVar9 + 3)), iVar11 < 0)) goto LAB_6814065c;
      piVar7 = (int *)piVar7[10];
    } while (piVar7 != (int *)0x0);
    break;
  case 0x24:
    for (piVar7 = (int *)param_3[6]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[10]) {
      iVar11 = crypto_bigEval(param_1,param_2,piVar7);
      if (iVar11 == 0) goto LAB_6814065c;
    }
    break;
  case 0x25:
    local_468 = 2;
    local_414 = (uint *)0xffffffff;
    local_420 = (undefined1 *)0xffffffff;
    local_428 = 0xffffffff;
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    puVar17 = local_420;
    puVar20 = local_418;
    while( true ) {
      local_418 = puVar20;
      if (iVar11 == 0) {
        return 0;
      }
      if (local_468 == 2) {
        js_initPropertySlot((int)param_2,&local_468,2,((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
        puVar20 = local_418;
      }
      else {
        local_468 = 2;
        iVar11 = js_allocObjectWithProto((uint)puVar20,(int)param_2,local_428,0,(int)local_414 - (int)puVar17);
        if (iVar11 == 0) goto LAB_6814065c;
      }
      local_410 = (int *)local_41c[8];
      local_428 = js_allocObject((int)puVar20,(int)param_2,(local_410 != (int *)0x0) + 1);
      if ((((int)local_428 < 0) ||
          (puVar17 = (undefined1 *)js_defineProperty(param_2,puVar20,7), (int)puVar17 < 0)) ||
         (iVar11 = crypto_bigEval(puVar20,param_2,(int *)local_41c[7]), iVar11 == 0))
      goto LAB_6814065c;
      if (local_410 == (int *)0x0) {
        piVar7 = (int *)param_2[0x10];
        iVar11 = js_storeProperty((uint)puVar20,(int)param_2,(int)(puVar17 + *piVar7),
                              (piVar7[2] - *piVar7) - (int)puVar17);
        param_1 = local_418;
        if (iVar11 == 0) goto LAB_6814065c;
        goto LAB_68140bdb;
      }
      local_468 = 3;
      puVar20 = (uint *)javascript_objectFreezeProperties(param_2,(uint)local_418,&local_460,0);
      local_414 = puVar20;
      if ((int)puVar20 < 0) goto LAB_6814065c;
      piVar7 = (int *)param_2[0x10];
      iVar11 = js_storeProperty((uint)local_418,(int)param_2,(int)(puVar17 + *piVar7),
                            (piVar7[2] - *piVar7) - (int)puVar17);
      if (iVar11 == 0) goto LAB_6814065c;
      if (*local_410 != 0x25) break;
      local_41c = local_410;
      iVar11 = crypto_bigEval(local_418,param_2,(int *)local_410[6]);
      puVar20 = local_418;
    }
    iVar11 = crypto_bigEval(local_418,param_2,local_410);
    if (iVar11 == 0) goto LAB_6814065c;
    iVar11 = js_allocObjectWithProto((uint)local_418,(int)param_2,local_428,0,(int)puVar20 - (int)puVar17);
    param_1 = local_418;
    if (iVar11 == 0) {
      return 0;
    }
    goto LAB_68140bdb;
  case 0x27:
    local_414 = (uint *)0x0;
    local_444 = (uint *)0x0;
    local_434 = (uint *)0xffffffff;
    local_41c = (int *)0x46;
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    local_42c = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    js_initPropertySlot((int)param_2,&local_468,4,local_42c);
    local_40c = (int *)param_3[7];
    local_424 = (uint *)local_40c[8];
    if ((local_424 == (uint *)0x0) ||
       ((local_424 == (uint *)0x1 &&
        (local_444 = (uint *)(uint)(*(int *)local_40c[6] == 0x29), local_444 != (uint *)0x0)))) {
      local_424 = (uint *)0x0;
      local_448 = (void *)0x0;
      local_438 = (void *)0xffffffff;
    }
    else {
      piVar7 = (int *)local_40c[6];
      local_420 = (undefined1 *)0x0;
      local_428 = 0;
      local_448 = (void *)0x3fffffff;
      local_438 = (void *)0xc0000001;
      local_410 = piVar7;
      if (piVar7 != (int *)0x0) {
        do {
          if (*piVar7 == 0x29) {
            local_424 = (uint *)((int)local_424 + -1);
            local_444 = (uint *)0x1;
          }
          else if (local_41c != (int *)0x76) {
            piVar8 = (int *)piVar7[6];
            iVar11 = *piVar8;
            local_410 = piVar7;
            if (iVar11 == 0x1e) {
              dVar1 = *(double *)(piVar8 + 6);
              fVar18 = (float10)dVar1;
              (*(unsigned int *)((char *)&local_440 + 4)) = (uint)((ulonglong)dVar1 >> 0x20);
              uVar4 = (*(unsigned int *)((char *)&local_440 + 4)) & 0x7ff00000;
              if ((uVar4 != 0x7ff00000) &&
                 (((*(unsigned int *)((char *)&local_440 + 4)) != 0x80000000 ||
                  ((*(unsigned int *)((char *)&local_440 + 0)) = SUB84(dVar1,0), (int)local_440 != 0)))) {
                local_440 = dVar1;
                uVar19 = strings_floatToUint64(piVar8,uVar4);
                iVar11 = (int)uVar19;
                local_440 = (double)CONCAT44(iVar11,(int)local_440);
                fVar18 = extraout_ST0;
                dVar1 = local_440;
                if ((extraout_ST0 == (float10)iVar11) && (iVar11 + 0x3fffffffU < 0x7fffffff)) {
                  piVar7[8] = iVar11 * 2 | 1;
                  goto LAB_68140df0;
                }
              }
              local_440 = dVar1;
              iVar11 = javascript_gcSweepFloat((int)param_1,(double)fVar18,0);
              if (iVar11 == 0) {
                local_430 = 0;
                break;
              }
              piVar7[8] = *(int *)(iVar11 + 8);
            }
            else if (iVar11 == 0x1f) {
              piVar7[8] = *(int *)(piVar8[6] + 8);
            }
            else {
              if (iVar11 != 0x21) {
LAB_68140d53:
                local_41c = (int *)0x76;
                goto LAB_68140e28;
              }
              if (piVar8[3] == 0x43) {
                piVar7[8] = 0xe;
              }
              else {
                if (piVar8[3] != 0x42) goto LAB_68140d53;
                piVar7[8] = 6;
              }
            }
LAB_68140df0:
            if (local_41c == (int *)0x46) {
              uVar4 = piVar7[8];
              if ((((uVar4 & 1) != 0) && (uVar4 != 0x80000001)) &&
                 (pvVar5 = (void *)((int)uVar4 >> 1), piVar7 = local_410,
                 (int)pvVar5 + 0x8000U < 0x10000)) {
                if ((int)pvVar5 < (int)local_448) {
                  local_448 = pvVar5;
                }
                if ((int)local_438 < (int)pvVar5) {
                  local_438 = pvVar5;
                }
                if ((int)pvVar5 < 0) {
                  pvVar5 = (void *)((int)pvVar5 + 0x10000);
                }
                if ((int)local_428 <= (int)pvVar5) {
                  if ((local_420 == (undefined1 *)0x0) && ((int)pvVar5 < 0x2000)) {
                    local_420 = local_408;
                    local_428 = 0x2000;
                  }
                  else {
                    local_428 = 0x10000;
                    local_420 = (undefined1 *)xtra_getPropertyById((int)param_1,0x2000);
                    if (local_420 == (undefined1 *)0x0) goto LAB_681406ef;
                  }
                  memset(local_420,0,(int)local_428 >> 3);
                }
                uVar4 = 1 << ((byte)pvVar5 & 0x1f);
                puVar20 = (uint *)(local_420 + ((int)pvVar5 >> 5) * 4);
                piVar7 = local_410;
                if ((*puVar20 & uVar4) == 0) {
                  *puVar20 = *puVar20 | uVar4;
                  goto LAB_68140e28;
                }
              }
              local_41c = (int *)0x47;
            }
          }
LAB_68140e28:
          piVar7 = (int *)piVar7[10];
          local_410 = piVar7;
        } while (piVar7 != (int *)0x0);
        if ((local_420 != (undefined1 *)0x0) && (local_420 != local_408)) {
          xtra_checkAndFlush(param_1,(int)local_420);
        }
        if (local_430 == 0) goto LAB_6814065c;
        if ((local_41c == (int *)0x76) || (local_41c != (int *)0x46)) goto LAB_68140f94;
      }
      local_414 = (uint *)((int)local_438 + (1 - (int)local_448));
      if (((uint *)0xffff < local_414) || ((uint *)((int)local_424 * 2) < local_414)) {
        local_41c = (int *)0x47;
      }
    }
LAB_68140f94:
    puVar20 = local_414;
    local_428 = crypto_allocObjectWithProtos((uint)param_1,(int)param_2,0x12,0,0);
    if ((int)local_428 < 0) goto LAB_6814065c;
    if (local_41c == (int *)0x76) {
      sVar6 = 0;
    }
    else if (local_41c == (int *)0x46) {
      sVar6 = (int)puVar20 * 2 + 6;
    }
    else {
      sVar6 = (int)local_424 * 4 + 4;
    }
    iVar11 = javascript_hashTableCount(param_1,(int)param_2,(char)local_41c,sVar6);
    if (iVar11 < 0) goto LAB_6814065c;
    puVar17 = (undefined1 *)0xffffffff;
    local_420 = (undefined1 *)0xffffffff;
    if (local_41c == (int *)0x76) {
      local_410 = (int *)local_40c[6];
      local_440 = (double)CONCAT44(0xffffffff,(int)local_440);
      for (; local_410 != (int *)0x0; local_410 = (int *)local_410[10]) {
        if ((((int *)local_410[6] != (int *)0x0) &&
            (iVar11 = crypto_bigEval(param_1,param_2,(int *)local_410[6]), iVar11 == 0)) ||
           ((-1 < (longlong)local_440 &&
            (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,(*(unsigned int *)((char *)&local_440 + 4)),0,
                                   (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) -
                                   (int)puVar17), iVar11 == 0)))) goto LAB_6814065c;
        if (*local_410 != 0x29) {
          uVar4 = crypto_evalExpression((uint)param_1,(int)param_2,7,0);
          local_440 = (double)CONCAT44(uVar4,(int)local_440);
          if ((((int)uVar4 < 0) ||
              (puVar17 = (undefined1 *)js_defineProperty(param_2,param_1,0x77), local_420 = puVar17,
              (int)puVar17 < 0)) ||
             ((local_410[4] = (int)puVar17, local_410 == (int *)local_40c[6] &&
              (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,1,
                                     (int)puVar17 - (int)local_42c), iVar11 == 0))))
          goto LAB_6814065c;
        }
      }
      local_434 = (uint *)js_defineProperty(param_2,param_1,0x78);
      if ((int)local_434 < 0) {
        return 0;
      }
    }
    else if (local_41c == (int *)0x46) {
      iVar11 = *(int *)param_2[0x10];
      *(byte *)((int)local_42c + iVar11 + 4) = (byte)local_448;
      *(byte *)((int)local_42c + iVar11 + 3) = (byte)((uint)local_448 >> 8);
      *(byte *)((int)local_42c + iVar11 + 5) = (byte)((uint)local_438 >> 8);
      *(byte *)((int)local_42c + iVar11 + 6) = (byte)local_438;
    }
    else {
      iVar11 = *(int *)param_2[0x10];
      *(byte *)((int)local_42c + iVar11 + 3) = (byte)((uint)local_424 >> 8);
      *(byte *)((int)local_42c + iVar11 + 4) = (byte)local_424;
    }
    for (piVar7 = (int *)local_40c[6]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[10]) {
      if ((local_41c == (int *)0x76) && (*piVar7 != 0x29)) {
        piVar7[8] = (piVar7[4] - (int)local_42c) * 2 | 1;
        piVar8 = (int *)param_2[0x10];
        iVar11 = js_storeProperty((uint)param_1,(int)param_2,*piVar8 + piVar7[4],
                              (piVar8[2] - piVar7[4]) - *piVar8);
        if (iVar11 == 0) goto LAB_6814065c;
      }
      local_440 = (double)CONCAT44((int *)piVar7[7],(int)local_440);
      iVar11 = crypto_bigEval(param_1,param_2,(int *)piVar7[7]);
      if (iVar11 == 0) goto LAB_6814065c;
      iVar11 = *(int *)((*(unsigned int *)((char *)&local_440 + 4)) + 0x10);
      piVar7[4] = iVar11;
      if (*piVar7 == 0x29) {
        local_420 = (undefined1 *)(iVar11 - (int)local_42c);
      }
    }
    if (local_444 == (uint *)0x0) {
      local_420 = (undefined1 *)
                  ((((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) - (int)local_42c);
    }
    pbVar16 = (byte *)0x0;
    if (local_41c == (int *)0x76) {
      iVar11 = js_storeProperty((uint)param_1,(int)param_2,*(int *)param_2[0x10] + (int)local_434,
                            (int)(((int)local_420 - (int)local_434) + (int)local_42c));
      if (iVar11 == 0) {
        return 0;
      }
    }
    else {
      pbVar16 = (byte *)(*(int *)param_2[0x10] + (int)local_42c);
      iVar11 = js_storeProperty((uint)param_1,(int)param_2,(int)pbVar16,(int)local_420);
      if (iVar11 == 0) goto LAB_6814065c;
      pbVar16 = pbVar16 + 2;
    }
    iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,
                          (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) - (int)local_42c);
    if (iVar11 == 0) goto LAB_6814065c;
    if (local_41c == (int *)0x46) {
      pbVar16 = pbVar16 + 4;
      if (local_414 != (uint *)0x0) {
        local_438 = (void *)xtra_getPropertyById((int)param_1,(int)local_414 * 4);
        if (local_438 == (void *)0x0) {
LAB_681406ef:
          xtra_reportError((int)param_1);
          return 0;
        }
        memset(local_438,0,(int)local_414 * 4);
        for (piVar7 = (int *)local_40c[6]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[10]) {
          if (*piVar7 != 0x29) {
            *(int **)((int)local_438 + ((piVar7[8] >> 1) - (int)local_448) * 4) = piVar7;
          }
        }
        iVar11 = 0;
        local_440 = (double)((ulonglong)local_440 & 0xffffffff);
        if (0 < (int)local_414) {
          do {
            iVar11 = *(int *)((int)local_438 + iVar11 * 4);
            if (iVar11 == 0) {
              iVar11 = 0;
            }
            else {
              iVar11 = *(int *)(iVar11 + 0x10) - (int)local_42c;
            }
            local_430 = js_storeProperty((uint)param_1,(int)param_2,(int)pbVar16,iVar11);
            if (local_430 == 0) break;
            iVar11 = (*(unsigned int *)((char *)&local_440 + 4)) + 1;
            pbVar16 = pbVar16 + 2;
            local_440 = (double)CONCAT44(iVar11,(int)local_440);
          } while (iVar11 < (int)local_414);
        }
        xtra_checkAndFlush(param_1,(int)local_438);
        if (local_430 == 0) {
          return 0;
        }
      }
    }
    else if (local_41c == (int *)0x47) {
      pbVar16 = pbVar16 + 2;
      for (local_410 = (int *)local_40c[6]; local_410 != (int *)0x0;
          local_410 = (int *)local_410[10]) {
        if (*local_410 != 0x29) {
          iVar11 = javascript_gcSweepValue((int)param_1,local_410[8],0);
          if ((iVar11 == 0) ||
             (puVar9 = js_createAtom((int)param_1,iVar11,param_2 + 0x15), puVar9 == (undefined4 *)0x0
             )) goto LAB_6814065c;
          pbVar16[1] = (byte)((uint)puVar9[3] >> 8);
          pbVar16[2] = *(byte *)(puVar9 + 3);
          iVar11 = js_storeProperty((uint)param_1,(int)param_2,(int)(pbVar16 + 2),
                                local_410[4] - (int)local_42c);
          if (iVar11 == 0) goto LAB_6814065c;
          pbVar16 = pbVar16 + 4;
        }
      }
    }
    goto LAB_68140bdb;
  case 0x2a:
    js_initPropertySlot((int)param_2,&local_468,0xd,local_42c);
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if ((((iVar11 == 0) ||
         (local_428 = js_allocObject((int)param_1,(int)param_2,3), (int)local_428 < 0)) ||
        (local_420 = (undefined1 *)js_defineProperty(param_2,param_1,7), (int)local_420 < 0)) ||
       ((iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[7]), iVar11 == 0 ||
        (iVar11 = js_defineProperty(param_2,param_1,6), iVar11 < 0)))) goto LAB_6814065c;
    piVar7 = (int *)param_2[0x10];
    iVar15 = js_storeProperty((uint)param_1,(int)param_2,(int)(local_420 + *piVar7),
                          (piVar7[2] - *piVar7) - (int)local_420);
    if (iVar15 == 0) goto LAB_6814065c;
    iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,iVar11 - (int)local_420);
    if (iVar11 == 0) {
      return 0;
    }
    goto LAB_68140bdb;
  case 0x2b:
    uVar4 = js_allocObject((int)param_1,(int)param_2,3);
    if (((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0), iVar11 < 0))
    goto LAB_6814065c;
    local_42c = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    js_initPropertySlot((int)param_2,&local_468,10,local_42c);
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    piVar7 = &local_468;
    do {
      piVar7[1] = ((int *)param_2[0x10])[2] - *(int *)param_2[0x10];
      piVar7 = (int *)piVar7[7];
      if (piVar7 == (int *)0x0) break;
    } while (*piVar7 == 1);
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[7]);
    if (iVar11 == 0) goto LAB_6814065c;
    iVar11 = js_defineProperty(param_2,param_1,8);
    if (iVar11 < 0) {
      return 0;
    }
    goto LAB_68140bdb;
  case 0x2c:
    piVar7 = (int *)param_3[6];
    local_420 = (undefined1 *)0x0;
    local_40c = piVar7;
    js_initPropertySlot((int)param_2,&local_468,0xb,local_42c);
    if (*piVar7 != 0x2f) {
      if ((int *)piVar7[6] == (int *)0x0) {
        uVar12 = 0;
      }
      else {
        iVar11 = crypto_bigEval(param_1,param_2,(int *)piVar7[6]);
        if (iVar11 == 0) goto LAB_6814065c;
        uVar12 = 0x51;
      }
      local_428 = js_allocObject((int)param_1,(int)param_2,4);
      if (((int)local_428 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,uVar12), iVar11 < 0))
      goto LAB_6814065c;
      puVar20 = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
      local_458 = (void *)0xffffffff;
      local_454 = (void *)0xffffffff;
      local_45c = 0xffffffff;
      local_460 = -1;
      local_464 = puVar20;
      local_42c = puVar20;
      if ((int *)local_40c[7] == (int *)0x0) {
        iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,0);
        if (iVar11 == 0) {
          return 0;
        }
      }
      else {
        iVar11 = crypto_bigEval(param_1,param_2,(int *)local_40c[7]);
        if (((iVar11 == 0) ||
            (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,
                                   (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) -
                                   (int)puVar20), iVar11 == 0)) ||
           (local_420 = (undefined1 *)js_defineProperty(param_2,param_1,7), (int)local_420 < 0))
        goto LAB_6814065c;
      }
      local_410 = (int *)local_40c[8];
      goto LAB_68141989;
    }
    piVar7 = (int *)piVar7[6];
    local_410 = piVar7;
    if ((*piVar7 == 0x30) && (*(int *)(piVar7[6] + 0x1c) != 0)) {
      iVar11 = crypto_bigEval(param_1,param_2,piVar7);
      if (iVar11 == 0) goto LAB_6814065c;
      local_410 = (int *)piVar7[6];
    }
    local_468 = 0xc;
    local_428 = 0xffffffff;
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,1);
    if (((iVar11 < 0) || (iVar11 = crypto_bigEval(param_1,param_2,(int *)local_40c[7]), iVar11 == 0))
       || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x67), iVar11 < 0)) goto LAB_6814065c;
    local_464 = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    local_458 = (void *)0xffffffff;
    local_454 = (void *)0xffffffff;
    local_45c = 0xffffffff;
    local_460 = -1;
    local_42c = local_464;
    switch(*local_410) {
    case 0x16:
      bVar3 = crypto_evalAssignment((uint)param_1,local_410,0x69);
      if (CONCAT31(extraout_var_00,bVar3) == 0) {
        return 0;
      }
      goto LAB_6814182c;
    case 0x17:
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x6a);
      if ((((iVar11 == 0) ||
           (local_428 = js_allocObject((int)param_1,(int)param_2,3), (int)local_428 < 0)) ||
          (local_420 = (undefined1 *)js_defineProperty(param_2,param_1,7), (int)local_420 < 0)) ||
         (bVar3 = crypto_matchOperator((int)local_410,0x7a), CONCAT31(extraout_var_01,bVar3) == 0))
      goto LAB_6814065c;
      break;
    case 0x1d:
      goto switchD_681416fb_caseD_1d;
    case 0x30:
      local_410 = (int *)local_410[6];
      uVar4 = js_allocObject((int)param_1,(int)param_2,6);
      if ((int)uVar4 < 0) goto LAB_6814065c;
switchD_681416fb_caseD_1d:
      piVar7 = local_410;
      local_410[3] = 0x68;
      iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
      if (iVar11 == 0) goto LAB_6814065c;
      iVar11 = piVar7[8];
      uVar12 = (undefined1)piVar7[3];
      if (iVar11 < 0) {
        bVar3 = js_hasProperty(local_410,uVar12);
        if (CONCAT31(extraout_var,bVar3) == 0) {
          return 0;
        }
      }
      else {
        if ((*(byte *)(piVar7 + 9) & 2) != 0) {
          uVar12 = 0x56;
        }
        iVar11 = js_setMultipleFlags(param_1,(int)param_2,uVar12,(char)((uint)iVar11 >> 8),(char)iVar11);
        if (iVar11 < 0) {
          return 0;
        }
      }
    }
LAB_6814182c:
    if (*local_410 != 0x17) {
      local_428 = js_allocObject((int)param_1,(int)param_2,3);
      if ((int)local_428 < 0) goto LAB_6814065c;
      local_420 = (undefined1 *)js_defineProperty(param_2,param_1,7);
      if ((int)local_420 < 0) {
        return 0;
      }
    }
LAB_68141989:
    piVar7 = local_41c;
    iVar11 = crypto_bigEval(param_1,param_2,(int *)local_41c[7]);
    if (iVar11 == 0) goto LAB_6814065c;
    if (*local_40c != 0x2f) {
      iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,1,
                            (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) - (int)local_42c);
      if (iVar11 == 0) goto LAB_6814065c;
      if (local_410 != (int *)0x0) {
        piVar8 = &local_468;
        do {
          piVar8[1] = ((int *)param_2[0x10])[2] - *(int *)param_2[0x10];
          piVar8 = (int *)piVar8[7];
          if (piVar8 == (int *)0x0) break;
        } while (*piVar8 == 1);
        iVar11 = crypto_bigEval(param_1,param_2,local_410);
        if ((iVar11 == 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x51), iVar11 < 0))
        goto LAB_6814065c;
        uVar4 = (uint)*(ushort *)((int)piVar7 + 10);
        if (param_2[0x13] != uVar4) {
          uVar13 = crypto_evalExpression((uint)param_1,(int)param_2,0x17,uVar4);
          if ((int)uVar13 < 0) goto LAB_6814065c;
          param_2[0x13] = uVar4;
        }
      }
      iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,2,
                            (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) - (int)local_42c);
      if (iVar11 == 0) goto LAB_6814065c;
    }
    iVar11 = js_defineProperty(param_2,param_1,6);
    if (iVar11 < 0) goto LAB_6814065c;
    if (0 < (int)local_420) {
      piVar7 = (int *)param_2[0x10];
      iVar15 = js_storeProperty((uint)param_1,(int)param_2,(int)(local_420 + *piVar7),
                            (piVar7[2] - *piVar7) - (int)local_420);
      if (iVar15 == 0) goto LAB_6814065c;
    }
    if (((*local_40c == 0x2f) &&
        (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,iVar11 - (int)local_420),
        iVar11 == 0)) ||
       (iVar11 = js_deleteProperty((uint)param_1,(int)param_2), puVar20 = local_418, iVar11 == 0))
    goto LAB_6814065c;
    if (*local_40c == 0x2f) {
      if (*local_410 == 0x17) {
        uVar4 = js_allocObject((int)local_418,(int)param_2,0xb);
        if ((int)uVar4 < 0) goto LAB_6814065c;
        iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x51);
        if (iVar11 < 0) {
          return 0;
        }
      }
      else {
        iVar11 = js_setPropertyFlag(local_418,(int)param_2,0x6b);
        if (iVar11 < 0) {
          return 0;
        }
      }
    }
    break;
  case 0x2d:
    uVar4 = param_3[6];
    local_424 = (uint *)param_2[2];
    if (uVar4 == 0) {
      puVar9 = (undefined4 *)0x0;
      uVar4 = *local_424;
      while (((int)uVar4 < 10 && (uVar4 != 4))) {
        local_424 = (uint *)local_424[7];
        uVar4 = *local_424;
      }
    }
    else {
      puVar9 = js_createAtom((int)param_1,uVar4,param_2 + 0x15);
      if (puVar9 == (undefined4 *)0x0) goto LAB_6814065c;
      for (; (*local_424 != 1 || (local_424[6] != uVar4)); local_424 = (uint *)local_424[7]) {
      }
    }
    puVar20 = local_424 + 2;
    goto LAB_68141be7;
  case 0x2e:
    uVar4 = param_3[6];
    local_424 = (uint *)param_2[2];
    if (uVar4 == 0) {
      uVar4 = *local_424;
      while ((int)uVar4 < 10) {
        local_424 = (uint *)local_424[7];
        uVar4 = *local_424;
      }
      puVar9 = (undefined4 *)0x0;
      puVar20 = local_424 + 3;
    }
    else {
      local_434 = (uint *)0x0;
      puVar9 = js_createAtom((int)param_1,uVar4,param_2 + 0x15);
      if (puVar9 == (undefined4 *)0x0) goto LAB_6814065c;
      for (; (*local_424 != 1 || (local_424[6] != uVar4)); local_424 = (uint *)local_424[7]) {
        if (9 < (int)*local_424) {
          local_434 = local_424;
        }
      }
      local_424 = local_434;
      puVar20 = local_434 + 3;
    }
LAB_68141be7:
    iVar11 = javascript_objectFreezeProperties(param_2,(uint)param_1,(int *)puVar20,(int)puVar9);
    if (iVar11 < 0) {
      return 0;
    }
    break;
  case 0x30:
    local_40c = (int *)param_3[6];
    local_428 = 0xffffffff;
    local_420 = (undefined1 *)0xffffffff;
    iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
    while (iVar11 != 0) {
      local_414 = (uint *)local_40c[3];
      piVar7 = local_410;
      if (local_414 != (uint *)0x9) {
        piVar7 = (int *)local_40c[8];
        piVar8 = piVar7;
        if ((int)piVar7 < 0) {
          puVar9 = js_createAtom((int)param_1,local_40c[6],param_2 + 0x15);
          if (puVar9 == (undefined4 *)0x0) goto LAB_6814065c;
          piVar7 = (int *)puVar9[3];
          if (((*param_2 & 2) == 0) || (piVar8 = piVar7, (char)*param_2 < '\0')) {
            param_2[0x10] = (uint)(param_2 + 10);
            local_410 = piVar7;
            iVar11 = js_setMultipleFlags(param_1,(int)param_2,(char)local_41c[3],(char)((uint)piVar7 >> 8),
                                  (char)piVar7);
            if (iVar11 < 0) goto LAB_6814065c;
            param_2[0x10] = (uint)(param_2 + 0xd);
            piVar8 = local_410;
          }
        }
        local_410 = piVar8;
        if ((local_40c[7] != 0) &&
           (((local_414 == (uint *)0x6d &&
             (iVar11 = js_setMultipleFlags(param_1,(int)param_2,0x6c,(char)((uint)piVar7 >> 8),(char)piVar7
                                   ), iVar11 < 0)) ||
            (iVar11 = crypto_bigEval(param_1,param_2,(int *)local_40c[7]), iVar11 == 0))))
        goto LAB_6814065c;
      }
      if ((local_40c == (int *)local_41c[6]) &&
         (uVar4 = js_allocObject((int)param_1,(int)param_2,
                               (-(uint)(local_41c[3] != 0x7e) & 0xfffffff1) + 0x15), (int)uVar4 < 0)
         ) goto LAB_6814065c;
      if (local_414 == (uint *)0x9) {
        iVar11 = js_setPropertyFlag(param_1,(int)param_2,9);
      }
      else {
        iVar11 = js_setMultipleFlags(param_1,(int)param_2,(char)local_414,(char)((uint)piVar7 >> 8),
                              (char)piVar7);
      }
      if ((iVar11 < 0) ||
         ((puVar17 = (undefined1 *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]),
          -1 < (int)local_428 &&
          (iVar11 = js_allocObjectWithProto((uint)param_1,(int)param_2,local_428,0,
                                 (int)puVar17 - (int)local_420), iVar11 == 0)))) goto LAB_6814065c;
      if (local_40c[10] == 0) {
        if (local_41c[9] == 0) goto switchD_6814069b_caseD_26;
        puVar20 = (uint *)0x51;
        goto LAB_6814093a;
      }
      local_420 = puVar17;
      local_428 = crypto_evalExpression((uint)param_1,(int)param_2,7,0);
      if (((int)local_428 < 0) || (iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x51), iVar11 < 0))
      goto LAB_6814065c;
      local_40c = (int *)local_40c[10];
      iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
    }
    goto LAB_6814081e;
  case 0x31:
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    js_initPropertySlot((int)param_2,&local_468,5,((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,3);
    if ((iVar11 < 0) || (iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[7]), iVar11 == 0))
    goto LAB_6814065c;
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,4);
    if (iVar11 < 0) goto LAB_6814081e;
LAB_68140bdb:
    local_430 = js_deleteProperty((uint)param_1,(int)param_2);
LAB_68140be0:
    if (local_430 == 0) goto LAB_68140c0e;
    break;
  case 0x32:
    if ((int *)param_3[6] == (int *)0x0) {
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,1);
      if (iVar11 < 0) goto LAB_6814065c;
    }
    else {
      iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
      if (iVar11 == 0) goto LAB_6814081e;
    }
    local_414 = (uint *)0x5;
    iVar11 = javascript_objectSealProperties((int *)0x0);
    puVar20 = local_414;
    if (iVar11 == 0) goto LAB_6814065c;
LAB_6814093a:
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,(char)puVar20);
    if (iVar11 < 0) {
      return 0;
    }
    break;
  case 0x34:
    piVar8 = (int *)param_3[6];
    iVar11 = *piVar8;
    if (iVar11 == 0x16) {
      iVar11 = 0x25;
      goto LAB_68142e61;
    }
    if (iVar11 == 0x17) {
      bVar3 = crypto_matchOperator((int)piVar8,0x26);
      uVar4 = CONCAT31(extraout_var_06,bVar3);
      goto joined_r0x68142f2f;
    }
    if (iVar11 == 0x1d) {
      piVar8[3] = 0x24;
      iVar11 = js_getPropertyDescriptor((uint)param_1,param_2);
      if (iVar11 == 0) goto LAB_6814065c;
      if (piVar8[3] != 0x42) {
        bVar3 = js_hasProperty(piVar8,(char)piVar8[3]);
        uVar4 = CONCAT31(extraout_var_05,bVar3);
        goto joined_r0x68142f2f;
      }
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x42);
    }
    else {
      iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x43);
    }
    goto LAB_68140816;
  case 0x35:
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    uVar12 = (undefined1)((uint)param_3[7] >> 8);
    iVar11 = 0x5d;
    piVar7 = (int *)(uint)*(byte *)(param_3 + 7);
    goto LAB_6814080f;
  case 0x36:
    uVar12 = (undefined1)((uint)param_3[7] >> 8);
    iVar11 = 0x5e;
    piVar7 = (int *)(uint)*(byte *)(param_3 + 7);
LAB_6814080f:
    iVar11 = js_setMultipleFlags(param_1,(int)param_2,(char)iVar11,uVar12,(char)piVar7);
    goto LAB_68140816;
  case 0x37:
    local_440 = (double)CONCAT44(0xffffffff,(int)local_440);
    local_448 = (void *)0xffffffff;
    local_434 = (uint *)0xffffffff;
    js_initPropertySlot((int)param_2,&local_468,-(uint)(param_3[8] != 0) & 8,
                 ((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    local_438 = (void *)param_2[0x18];
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x85);
    if (iVar11 < 0) goto LAB_6814065c;
    local_424 = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    iVar11 = crypto_bigEval(param_1,param_2,(int *)param_3[6]);
    if (iVar11 == 0) goto LAB_6814065c;
    if (param_3[8] != 0) {
      uVar4 = js_allocObject((int)param_1,(int)param_2,0xb);
      if ((int)uVar4 < 0) goto LAB_6814065c;
      local_458 = (void *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
      iVar11 = js_defineProperty(param_2,param_1,0x97);
      if (iVar11 < 0) goto LAB_6814065c;
    }
    uVar4 = js_allocObject((int)param_1,(int)param_2,0xb);
    if ((int)uVar4 < 0) goto LAB_6814065c;
    local_454 = (void *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    iVar11 = js_defineProperty(param_2,param_1,0x95);
    if (iVar11 < 0) goto LAB_6814065c;
    local_444 = (uint *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
    local_414 = (uint *)param_3[7];
    puVar20 = local_418;
    if (local_414 != (uint *)0x0) {
      local_434 = local_444;
      iVar11 = crypto_emitLineNumber();
      pvVar5 = local_438;
      puVar20 = local_418;
      while (local_438 = pvVar5, local_418 = puVar20, iVar11 != 0) {
        (*(unsigned int *)((char *)&local_440 + 4)) = (uint)((ulonglong)local_440 >> 0x20);
        if ((*(unsigned int *)((char *)&local_440 + 4)) == -1) {
          iVar11 = js_setMultipleFlags(puVar20,(int)param_2,0x75,(char)((uint)pvVar5 >> 8),(char)pvVar5);
          if (iVar11 < 0) goto LAB_6814065c;
          param_2[0x18] = (uint)pvVar5;
        }
        else {
          piVar7 = (int *)param_2[0x10];
          iVar15 = (piVar7[2] - *piVar7) - (*(unsigned int *)((char *)&local_440 + 4));
          iVar11 = *piVar7 + (*(unsigned int *)((char *)&local_440 + 4));
          iVar11 = js_storeProperty((uint)puVar20,(int)param_2,iVar11,iVar15);
          if (iVar11 == 0) goto LAB_6814065c;
          param_2[0x18] = param_2[0x18] + 1;
          uVar4 = js_allocObject((int)puVar20,(int)param_2,0xb);
          if (((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,4), iVar11 < 0))
          goto LAB_6814065c;
        }
        local_420 = (undefined1 *)crypto_evalExpression((uint)puVar20,(int)param_2,0x14,0);
        if ((((int)local_420 < 0) ||
            (((iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0), iVar11 < 0 ||
              (puVar9 = js_createAtom((int)puVar20,*(int *)(puVar20[5] + 0xc4),param_2 + 0x15),
              puVar9 == (undefined4 *)0x0)) ||
             (iVar11 = js_setMultipleFlags(puVar20,(int)param_2,0x3b,(char)((uint)puVar9[3] >> 8),
                                    *(undefined1 *)(puVar9 + 3)), iVar11 < 0)))) ||
           (((iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x39), iVar11 < 0 ||
             (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x59), iVar11 < 0)) ||
            (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x74), iVar11 < 0)))) goto LAB_6814065c;
        uVar4 = local_414[6];
        local_428 = uVar4;
        puVar9 = js_createAtom((int)puVar20,*(int *)(uVar4 + 0x18),param_2 + 0x15);
        if (((puVar9 == (undefined4 *)0x0) ||
            (iVar11 = js_setMultipleFlags(puVar20,(int)param_2,0x82,(char)((uint)puVar9[3] >> 8),
                                   *(undefined1 *)(puVar9 + 3)), iVar11 < 0)) ||
           ((uVar13 = js_allocObject((int)puVar20,(int)param_2,0xb), (int)uVar13 < 0 ||
            (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,3), iVar11 < 0)))) goto LAB_6814065c;
        if (*(int **)(uVar4 + 0x1c) != (int *)0x0) {
          iVar11 = ((int *)param_2[0x10])[2];
          iVar15 = *(int *)param_2[0x10];
          iVar10 = crypto_bigEval(puVar20,param_2,*(int **)(uVar4 + 0x1c));
          if ((iVar10 == 0) ||
             (iVar11 = js_allocObjectWithProto((uint)puVar20,(int)param_2,(int)local_420,0,
                                    (((int *)param_2[0x10])[2] - *(int *)param_2[0x10]) -
                                    (iVar11 - iVar15)), iVar11 == 0)) goto LAB_6814065c;
          iVar11 = js_defineProperty(param_2,puVar20,7);
          local_440 = (double)CONCAT44(iVar11,(int)local_440);
          uVar4 = local_428;
          if (iVar11 < 0) goto LAB_6814065c;
        }
        js_initPropertySlot((int)param_2,local_48c,7,((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
        local_474 = *(undefined4 *)(uVar4 + 0x18);
        iVar11 = crypto_bigEval(puVar20,param_2,(int *)local_414[8]);
        if (iVar11 == 0) goto LAB_6814065c;
        js_deleteProperty((uint)puVar20,(int)param_2);
        uVar4 = js_allocObject((int)puVar20,(int)param_2,0xb);
        if (((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,4), iVar11 < 0))
        goto LAB_6814065c;
        if (local_41c[8] != 0) {
          local_458 = (void *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
          iVar11 = js_defineProperty(param_2,puVar20,0x97);
          if (iVar11 < 0) goto LAB_6814065c;
        }
        uVar4 = js_allocObject((int)puVar20,(int)param_2,0xb);
        if ((int)uVar4 < 0) goto LAB_6814065c;
        local_454 = (void *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
        iVar11 = js_defineProperty(param_2,puVar20,0x95);
        if (iVar11 < 0) goto LAB_6814065c;
        if ((uint *)local_414[7] == (uint *)0x0) goto LAB_68142120;
        local_414 = (uint *)local_414[7];
        iVar11 = crypto_emitLineNumber();
        pvVar5 = local_438;
        puVar20 = local_418;
      }
      goto LAB_6814081e;
    }
LAB_68142120:
    iVar11 = (*(unsigned int *)((char *)&local_440 + 4));
    if ((local_41c[8] != 0) || (((*(unsigned int *)((char *)&local_440 + 4)) != -1 && (*(int *)(local_414[6] + 0x1c) != 0)))) {
      local_448 = (void *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
      iVar15 = js_setMultipleFlags(puVar20,(int)param_2,0x75,(char)((uint)local_438 >> 8),(char)local_438);
      if (iVar15 < 0) goto LAB_6814065c;
      param_2[0x18] = (uint)local_438;
      if ((iVar11 != -1) && (*(int *)(local_414[6] + 0x1c) != 0)) {
        piVar7 = (int *)param_2[0x10];
        iVar11 = js_storeProperty((uint)puVar20,(int)param_2,*piVar7 + iVar11,
                              (piVar7[2] - *piVar7) - iVar11);
        if (iVar11 == 0) goto LAB_6814065c;
        param_2[0x18] = param_2[0x18] + 1;
        uVar4 = js_allocObject((int)puVar20,(int)param_2,0xb);
        if (((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,4), iVar11 < 0))
        goto LAB_6814065c;
      }
      if (local_41c[8] != 0) {
        local_458 = (void *)(((int *)param_2[0x10])[2] - *(int *)param_2[0x10]);
        iVar11 = js_defineProperty(param_2,puVar20,0x97);
        if (iVar11 < 0) goto LAB_6814065c;
        param_2[0x18] = (uint)local_438;
      }
      uVar4 = js_allocObject((int)puVar20,(int)param_2,0xb);
      if (((((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x74), iVar11 < 0)) ||
          (uVar4 = js_allocObject((int)puVar20,(int)param_2,0xb), (int)uVar4 < 0)) ||
         (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x6e), iVar11 < 0)) goto LAB_6814065c;
    }
    if (local_41c[8] != 0) {
      iVar11 = js_setPropertyFlags(local_458,(uint)local_418,*(int *)(param_2[0x10] + 8),0x72);
      puVar20 = local_418;
      if (iVar11 == 0) goto LAB_6814065c;
      param_2[0x18] = param_2[0x18] + 1;
      if (param_2[0x19] < param_2[0x18]) {
        param_2[0x19] = param_2[0x18];
      }
      local_468 = 9;
      iVar11 = crypto_emitLineNumber();
      if (((iVar11 == 0) || (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x86), iVar11 < 0)) ||
         ((iVar11 = crypto_bigEval(puVar20,param_2,(int *)local_41c[8]), iVar11 == 0 ||
          (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0x73), iVar11 < 0)))) goto LAB_6814065c;
    }
    puVar20 = local_418;
    js_deleteProperty((uint)local_418,(int)param_2);
    uVar4 = js_allocObject((int)puVar20,(int)param_2,0xf);
    if ((((int)uVar4 < 0) || (iVar11 = js_setPropertyFlag(puVar20,(int)param_2,0), iVar11 < 0)) ||
       ((iVar11 = js_setPropertyFlags(local_454,(uint)puVar20,*(int *)(param_2[0x10] + 8),6),
        piVar7 = local_41c, iVar11 == 0 ||
        ((local_41c[7] != 0 &&
         (iVar11 = javascript_objectGetParent(puVar20,(int)param_2,(int)local_424,(int)local_444,(int)local_434),
         iVar11 == 0)))))) goto LAB_6814065c;
    if (piVar7[8] != 0) {
      uVar4 = javascript_objectGetParent(puVar20,(int)param_2,(int)local_424,(int)local_448,(int)local_448);
      goto joined_r0x68142f2f;
    }
    break;
  case 0x3c:
    iVar11 = js_setPropertyFlag(param_1,(int)param_2,0x71);
LAB_68140816:
    if (iVar11 < 0) {
LAB_6814081e:
      return 0;
    }
  }
switchD_6814069b_caseD_26:
  puVar20 = param_2 + 0x26;
  *puVar20 = *puVar20 - 1;
  if ((*puVar20 == 0) && (param_2[0x21] != 0)) {
    local_430 = javascript_objectCreateFromLiteral((uint)local_418,(int)param_2);
  }
LAB_68140c0e:
  return 0;
  while( true ) {
    local_42c = (uint *)((int)local_42c + (int)local_434);
    *pbVar16 = *(byte *)(local_410 + 3);
    local_410 = (int *)local_410[7];
    if (local_410 == local_40c) break;
LAB_68142cc2:
    pbVar16 = (byte *)(*(int *)param_2[0x10] + (int)local_42c);
    local_434 = (uint *)javascript_objectRemoveSlot((int)pbVar16,(int)param_2);
    iVar11 = js_storeProperty((uint)param_1,(int)param_2,(int)pbVar16,(int)local_420 - (int)local_42c);
    if (iVar11 == 0) goto LAB_6814065c;
  }
  goto switchD_6814069b_caseD_26;
}



