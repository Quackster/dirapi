// Module: score_engine
// Topic: Playback control - score playback state machine, selection handling, text editing
// Address range: 0x68080450 - 0x680813d0
// Functions (4):
//   scoreEngine_dispatchTextEdit (scoreEngine_dispatchTextEdit)
//   scoreEngine_initPlayback
//   scoreEngine_handleTextSelection (scoreEngine_handleTextSelection)
//   scoreEngine_stepPlayback

// ============================================================
// Function: scoreEngine_dispatchTextEdit (scoreEngine_dispatchTextEdit)
// Address: 68080450
// Size: 75 bytes
// Params: void * param_1, int param_2, void * param_3, undefined4 param_4, void * param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
scoreEngine_dispatchTextEdit(void *param_1,int param_2,void *param_3,undefined4 param_4,void *param_5)

{
  int local_18;
  int *in_EAX;
  
  if (*in_EAX == 1) {
    sprites_setTextCaretPos(param_3,param_2,param_4,(int)param_1,param_5,(int)in_EAX);
    return 1;
  }
  if (*in_EAX != 2) {
    return 0;
  }
  sprites_getTextBoxSize(param_1,param_2);
  return 1;
}



// ============================================================
// Function: scoreEngine_initPlayback (FUN_680804a0)
// Address: 680804a0
// Size: 2875 bytes
// Params: void * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_initPlayback(void *param_1,int *param_2)
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  int *piVar7;
  int local_a0;
  void *local_9c;
  void *local_98;
  void *local_94;
  void *local_90;
  void *local_8c;
  uint local_88;
  int local_84;
  int *local_80;
  int *local_7c;
  void *local_78;
  void *local_74;
  void *local_70;
  int local_6c;
  void *local_58;
  int local_54;
  int local_18 [2];
  int local_10;
  uint local_8;
  
  local_7c = param_2;
  local_78 = param_1;
  local_80 = (int *)0x0;
  local_88 = 0;
  local_84 = 0;
  local_9c = (void *)0x0;
  local_a0 = 0;
  local_84 = Ordinal_1600();
  iVar2 = Ordinal_374(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                      *(int *)((int)param_1 + 0x7c),2,(double *)&local_58);
  pvVar1 = local_58;
  if (iVar2 == 0) goto LAB_68080fac;
  local_98 = local_58;
  iVar2 = Ordinal_294(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),local_58,0x70,
                      (uint *)&local_70);
  pvVar6 = local_70;
  if (iVar2 == 0) goto LAB_68080fac;
  local_80 = (int *)local_6c;
  iVar2 = xtra_getBufferSize(local_6c);
  local_80 = (int *)xtra_insertIntoBuffer((int)local_80,0,iVar2);
  iVar2 = Ordinal_294(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar1,0x65,
                      (uint *)&local_70);
  if (iVar2 == 0) goto switchD_680805ff_caseD_3;
  if (local_70 == (void *)0x1) {
    local_a0 = 1;
  }
  local_74 = (void *)media_lookupAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),
                                  pvVar1);
  media_getAssetData(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar1,&local_90,
               &local_8c);
  piVar7 = local_7c;
  if (local_8c == local_90) {
    sprites_updateTextCursor((int)local_8c);
    *(code **)((int)param_1 + 0x84) = scoreEngine_stepPlayback;
    scoreEngine_stepPlayback(param_1,piVar7);
    goto switchD_680805ff_caseD_3;
  }
  switch(*local_7c) {
  case 1:
  case 5:
    *(undefined4 *)((int)param_1 + 0x88) = 0;
    break;
  case 2:
  case 6:
    local_9c = (void *)0xffffffff;
    iVar2 = Ordinal_1770(0x38);
    if (iVar2 != 0) {
      *(undefined4 *)((int)param_1 + 0x88) = 1;
      Ordinal_374(*(int *)((int)param_1 + 0x20),(int)*(byte **)((int)param_1 + 0x80),
                  *(int *)((int)param_1 + 0x7c),0xd,(double *)&local_58);
      local_74 = (void *)xtra_layoutTextRun(local_84,(int)local_80,local_7c[2] - (int)local_58,
                                      local_7c[3] - local_54,(uint *)&local_9c,0,0);
      if (-1 < (int)local_74) {
        sprites_getTextProperty(pvVar1,(int)local_74);
        pvVar6 = local_78;
        pvVar1 = local_98;
        if ((int)local_74 < (int)local_90) {
          local_90 = local_74;
          media_registerAsset(*(int *)((int)local_78 + 0x20),*(byte **)((int)local_78 + 0x80),local_98,
                       (int)local_74);
        }
        else {
          local_8c = local_74;
        }
        media_registerAssetWithData(*(int *)((int)pvVar6 + 0x20),*(byte **)((int)pvVar6 + 0x80),pvVar1,local_90,
                     local_8c);
        sprites_getTextInfo(pvVar1);
        *(code **)((int)pvVar6 + 0x84) = scoreEngine_handleTextSelection;
      }
      break;
    }
    media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,(void *)0x0,
                 (void *)0x0);
    piVar7 = local_7c;
    sprites_updateTextCursor((int)local_90);
    goto LAB_68080f92;
  case 9:
    if (*(int *)((int)param_1 + 0x88) != 0) {
      *(code **)((int)param_1 + 0x84) = sprites_handleEditCommand;
      local_88 = sprites_handleEditCommand((int)param_1,local_7c);
    }
    break;
  case 10:
    local_94 = (void *)(local_7c[5] & 1);
    switch((char)local_7c[6]) {
    case '3':
    case 'u':
      local_a0 = (int)local_8c - (int)local_90;
      local_94 = local_90;
      if (local_a0 != 0) {
        local_74 = local_90;
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                     (int)local_90);
        xtra_deleteBufferRange((int)pvVar6,(int)local_94,local_a0);
        pvVar6 = local_94;
        xtra_deleteBufferRange((int)local_80,(int)local_94,local_a0);
        Ordinal_293(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar1,10,
                    (uint *)0x0);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,pvVar6,
                     pvVar6);
        *(code **)((int)param_1 + 0x84) = scoreEngine_stepPlayback;
        sprites_getTextProperty(pvVar1,(int)local_90);
        sprites_updateTextCursor((int)local_74);
        sprites_getTextInfo(local_98);
        local_88 = 1;
      }
      break;
    default:
      local_94 = (void *)((int)local_8c - (int)local_90);
      iVar2 = local_7c[7];
      local_98 = local_90;
      if ((((iVar2 != 0) && ((local_7c[5] & 0x10U) != 0)) && ((iVar2 == 99 || (iVar2 == 0x78)))) &&
         ((iVar2 = events_getScoreAnnotation(*(int *)((int)param_1 + 0xc)), iVar2 != 0 &&
          (iVar2 = Ordinal_2000(), iVar2 != 0)))) {
        local_a0 = 0;
        local_a0 = Ordinal_1126((int)local_94 + 1,0);
        if (local_a0 != 0) {
          xtra_extractBufferBytes((int)pvVar6,(int)local_98,(int)local_94,local_a0,(int)local_94 + 1);
          Ordinal_2013(local_a0,(int)local_94 + 1);
          Ordinal_1127(&local_a0);
        }
        local_88 = (uint)(local_7c[7] != 0x78);
        Ordinal_2001();
        if (local_88 != 0) break;
      }
      if ((local_7c[8] == 0) || (local_94 == (void *)0x0)) break;
      iVar2 = xtra_appendToBuffer((int)pvVar6,(undefined4 *)((int)param_1 + 0xa0),(int)local_98);
      *(uint *)((int)param_1 + 0x9c) = (uint)(iVar2 != 0);
      xtra_deleteBufferRange((int)pvVar6,(int)local_98,(int)local_94);
      xtra_deleteBufferRange((int)local_80,(int)local_98,(int)local_94);
      Ordinal_293(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar1,10,(uint *)0x0)
      ;
      media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_74,
                   local_74);
      pvVar6 = local_90;
      local_74 = local_90;
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                   (int)local_90);
      sprites_getTextProperty(pvVar1,(int)pvVar6);
      param_1 = local_78;
      goto LAB_68080f87;
    case 's':
      if (local_94 != (void *)0x0) {
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,0);
        local_90 = (void *)0x0;
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                     (void *)0x0,local_8c);
        pvVar5 = local_90;
        goto LAB_68080cfb;
      }
      goto LAB_68080b9a;
    case 't':
      local_9c = (void *)0x1;
    case 'y':
      if (local_94 == (void *)0x0) {
LAB_68080b9a:
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_74,
                     local_74);
LAB_68080f87:
        piVar7 = local_7c;
        sprites_updateTextCursor((int)local_74);
LAB_68080f92:
        *(code **)((int)param_1 + 0x84) = scoreEngine_stepPlayback;
        local_88 = scoreEngine_stepPlayback(param_1,piVar7);
      }
      else {
        xtra_processTextRun(local_84,local_80,(int)local_74,local_18);
        if (local_a0 != 0) {
          media_resolveAssetEx(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x28),pvVar1,1,
                       local_9c,1);
        }
        local_74 = (void *)xtra_layoutTextRun(local_84,(int)local_80,local_18[0],0,(uint *)0x0,0,0);
        if (-1 < (int)local_74) {
          sprites_getTextProperty(pvVar1,(int)local_74);
          pvVar6 = local_78;
          pvVar1 = local_98;
          sprites_getTextInfo(local_98);
          pvVar5 = local_74;
          if ((int)local_74 < (int)local_90) {
            local_90 = local_74;
            media_registerAsset(*(int *)((int)pvVar6 + 0x20),*(byte **)((int)pvVar6 + 0x80),pvVar1,
                         (int)local_74);
          }
          else {
            local_8c = local_74;
          }
          media_registerAssetWithData(*(int *)((int)pvVar6 + 0x20),*(byte **)((int)pvVar6 + 0x80),pvVar1,local_90,
                       local_8c);
          media_registerAsset(*(int *)((int)pvVar6 + 0x20),*(byte **)((int)pvVar6 + 0x80),pvVar1,
                       (int)pvVar5);
          sprites_getTextInfo(pvVar1);
          local_88 = 1;
        }
      }
      break;
    case 'w':
      local_9c = (void *)xtra_getBufferSize((int)pvVar6);
      iVar2 = xtra_setBufferPos((int)pvVar6,0);
      iVar3 = Ordinal_1114(iVar2);
      if (iVar3 != 0) {
        Ordinal_1115(iVar2);
      }
      if (local_94 == (void *)0x0) {
LAB_68080959:
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_74,
                     local_74);
        goto LAB_68080f87;
      }
      if ((-1 < (int)local_8c) || ((int)local_8c < (int)local_9c)) {
        local_8c = local_9c;
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                     (int)local_9c);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_90,
                     local_8c);
        pvVar6 = local_8c;
        goto LAB_68080dba;
      }
      break;
    case '{':
      if (local_94 == (void *)0x0) goto LAB_68080959;
      if (0 < (int)local_90) {
        local_90 = (void *)sprites_handleTextEvent((int)pvVar6,(int)local_90);
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                     (int)local_90);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_90,
                     local_8c);
        pvVar6 = local_90;
        goto LAB_68080dba;
      }
      break;
    case '|':
      local_a0 = xtra_getBufferSize((int)pvVar6);
      local_9c = (void *)xtra_setBufferPos((int)pvVar6,0);
      iVar2 = Ordinal_1114(local_9c);
      if (iVar2 != 0) {
        Ordinal_1115(local_9c);
      }
      if (local_94 == (void *)0x0) {
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_8c,
                     local_8c);
        local_74 = local_8c;
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                     (int)local_8c);
        sprites_getTextProperty(pvVar1,(int)local_8c);
        param_1 = local_78;
        goto LAB_68080f87;
      }
      if ((-1 < (int)local_8c) || ((int)local_8c < local_a0)) {
        local_8c = (void *)sprites_handleTextScroll((int)pvVar6,(int)local_8c);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_90,
                     local_8c);
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                     (int)local_8c);
        pvVar6 = local_8c;
        goto LAB_68080dba;
      }
      break;
    case '}':
      if (local_94 == (void *)0x0) goto LAB_68080959;
      xtra_processTextRun(local_84,local_80,(int)local_8c,local_18);
      iVar2 = xtra_setTextProperty(local_84,(int)local_80,local_8c);
      local_9c = (void *)(iVar2 + 1);
      local_74 = (void *)xtra_layoutTextRun(local_84,(int)local_80,local_10,0,(uint *)0x0,(uint)local_9c,1
                                     );
      pvVar5 = (void *)xtra_setTextProperty(local_84,(int)local_80,local_74);
      if (pvVar5 != local_9c) {
        local_74 = (void *)sprites_renderTextOverlay((int)pvVar6,(int)local_74);
      }
      if ((int)local_74 < 0) {
        local_9c = (void *)xtra_getBufferSize((int)pvVar6);
        iVar2 = xtra_setBufferPos((int)pvVar6,0);
        iVar3 = Ordinal_1114(iVar2);
        if (iVar3 == 0) break;
        local_74 = local_9c;
        Ordinal_1115(iVar2);
      }
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,
                   (int)local_74);
      pvVar6 = local_74;
      media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,local_90,
                   local_74);
LAB_68080dba:
      sprites_getTextProperty(pvVar1,(int)pvVar6);
      sprites_getTextInfo(local_98);
      local_88 = 1;
      break;
    case '~':
      if (local_94 == (void *)0x0) goto LAB_68080959;
      xtra_processTextRun(local_84,local_80,(int)local_90,local_18);
      iVar2 = xtra_setTextProperty(local_84,(int)local_80,local_90);
      local_9c = (void *)(iVar2 + -1);
      local_74 = (void *)xtra_layoutTextRun(local_84,(int)local_80,local_18[0],0,(uint *)0x0,
                                      (uint)local_9c,1);
      pvVar4 = (void *)xtra_setTextProperty(local_84,(int)local_80,local_74);
      pvVar5 = local_74;
      if (pvVar4 != local_9c) {
        pvVar5 = (void *)sprites_renderTextOverlay((int)pvVar6,(int)local_74);
      }
      if ((int)pvVar5 < 0) {
        local_74 = (void *)0x0;
        pvVar5 = (void *)0x0;
      }
      media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,pvVar5,
                   local_8c);
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar1,(int)pvVar5)
      ;
LAB_68080cfb:
      sprites_getTextProperty(pvVar1,(int)pvVar5);
      sprites_getTextInfo(local_98);
      local_88 = 1;
    }
    break;
  case 0x1e:
    if (local_7c[8] != 0) {
      local_88 = scoreEngine_dispatchTextEdit(pvVar6,local_84,param_1,pvVar1,local_80);
    }
  }
switchD_680805ff_caseD_3:
LAB_68080fac:
  if (local_84 != 0) {
    Ordinal_1601(&local_84);
  }
  xtra_resetBuffer((int)local_80);
  return 0;
}



// ============================================================
// Function: scoreEngine_handleTextSelection (scoreEngine_handleTextSelection)
// Address: 68081090
// Size: 831 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_handleTextSelection(int param_1,int *param_2)
{
  int local_18;
  int iVar1;
  int iVar2;
  void *pvVar3;
  void *local_94;
  void *local_90;
  void *local_8c;
  int local_88;
  int *local_84;
  void *local_80;
  int local_7c;
  void *local_78;
  int local_74;
  uint local_70;
  int local_6c;
  undefined8 local_58;
  int local_50;
  int local_4c;
  /* FIXUP(C2040: 'local_18': 'int): int local_18 [4]; */
  uint local_8;
  
  local_84 = (int *)0x0;
  local_7c = 0;
  local_78 = (void *)0xffffffff;
  local_88 = 0;
  local_7c = Ordinal_1600();
  iVar1 = Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),2,
                      (double *)&local_58);
  if (iVar1 == 0) goto LAB_680813a3;
  local_74 = (int)local_58;
  iVar1 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),(int)local_58,0x70,&local_70
                     );
  if (iVar1 == 0) goto LAB_680813a3;
  iVar1 = xtra_getBufferSize(local_6c);
  local_84 = (int *)xtra_insertIntoBuffer(local_6c,0,iVar1);
  iVar1 = local_74;
  iVar2 = Ordinal_294(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),local_74,0x65,&local_70);
  if (iVar2 == 0) goto LAB_680813a3;
  if (local_70 == 1) {
    local_88 = 1;
  }
  pvVar3 = (void *)media_lookupAsset(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),iVar1);
  iVar1 = *param_2;
  local_90 = pvVar3;
  local_78 = pvVar3;
  if ((iVar1 == 1) || (iVar1 == 5)) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    media_getAssetData(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),local_74,&local_80,&local_78);
    if (local_80 == (void *)0x0 && local_78 == (void *)0x0) {
      if (-1 < (int)pvVar3) {
        xtra_processTextRun(local_7c,local_84,(int)pvVar3,local_18);
        Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),0xd,
                    (double *)&local_58);
        Ordinal_1064(local_18,(int)local_58,(*(unsigned int *)((char *)&local_58 + 4)));
        iVar1 = Ordinal_1066(local_18,local_18,&local_58);
        if (iVar1 != 0) {
          Ordinal_1839(param_2[1],local_18);
          media_resolveAsset(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),
                       (int)pvVar3,1);
          *(code **)(param_1 + 0x84) = scoreEngine_stepPlayback;
          iVar1 = local_74;
          goto LAB_6808139d;
        }
        Ordinal_1839(param_2[1],0);
      }
      *(code **)(param_1 + 0x84) = scoreEngine_stepPlayback;
      iVar1 = local_74;
    }
    else {
      if ((int)local_78 < (int)pvVar3) {
        media_registerAsset(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),local_74,(int)local_78);
      }
      *(code **)(param_1 + 0x84) = scoreEngine_initPlayback;
      iVar1 = local_74;
    }
  }
  else {
    if (iVar1 != 9) goto LAB_680813a3;
    iVar1 = param_2[2];
    iVar2 = param_2[3];
    Ordinal_374(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),*(int *)(param_1 + 0x7c),0xd,
                (double *)&local_58);
    if (iVar1 < local_50) {
      if (iVar1 < (int)local_58) {
        iVar1 = (int)local_58 + 1;
      }
    }
    else {
      iVar1 = local_50 + -1;
    }
    if (iVar2 < local_4c) {
      if (iVar2 < (*(unsigned int *)((char *)&local_58 + 4))) {
        if (local_88 == 1) {
          media_resolveAssetEx(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x28),local_74,0,1,1);
        }
        iVar2 = (*(unsigned int *)((char *)&local_58 + 4)) + 1;
      }
    }
    else {
      if (local_88 == 1) {
        media_resolveAssetEx(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x28),local_74,0,0,1);
      }
      iVar2 = local_4c + -1;
    }
    pvVar3 = (void *)xtra_layoutTextRun(local_7c,(int)local_84,iVar1 - (int)local_58,
                                  iVar2 - (*(unsigned int *)((char *)&local_58 + 4)),(uint *)0x0,0,0);
    iVar1 = local_74;
    if ((int)pvVar3 < (int)local_90) {
      local_78 = local_90;
      local_80 = pvVar3;
    }
    else {
      local_80 = local_90;
      local_78 = pvVar3;
    }
    media_getAssetData(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x80),local_74,&local_8c,&local_94);
    if ((local_80 == local_8c) && (local_78 == local_94)) goto LAB_680813a3;
    media_registerAssetWithData(*(int *)(param_1 + 0x20),*(byte **)(param_1 + 0x80),iVar1,local_80,local_78);
  }
LAB_6808139d:
  sprites_getTextInfo(iVar1);
LAB_680813a3:
  if (local_7c != 0) {
    Ordinal_1601(&local_7c);
  }
  xtra_resetBuffer((int)local_84);
  return 0;
}



// ============================================================
// Function: scoreEngine_stepPlayback (FUN_680813d0)
// Address: 680813d0
// Size: 4241 bytes
// Params: void * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_stepPlayback(void *param_1,int *param_2)
{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  void *local_144;
  int local_140;
  uint local_13c;
  int *local_138;
  void *local_134;
  void *local_130;
  int local_12c;
  void *local_128;
  int *local_124;
  void *local_120;
  void *local_11c;
  int local_118;
  undefined4 local_104 [41];
  void *local_60;
  int local_5c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  
  local_138 = param_2;
  local_124 = (int *)0x0;
  uVar9 = 0;
  local_120 = (void *)0x0;
  local_12c = 0;
  local_144 = (void *)0x0;
  local_140 = 0;
  local_12c = Ordinal_1600();
  iVar2 = Ordinal_374(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                      *(int *)((int)param_1 + 0x7c),2,(double *)&local_60);
  pvVar4 = local_60;
  if (iVar2 == 0) goto LAB_68081a5a;
  local_130 = local_60;
  iVar2 = Ordinal_294(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),local_60,0x70,
                      (uint *)&local_11c);
  if (iVar2 == 0) goto switchD_6808157b_caseD_4;
  local_134 = local_11c;
  local_124 = (int *)local_118;
  iVar2 = xtra_getBufferSize(local_118);
  local_124 = (int *)xtra_insertIntoBuffer((int)local_124,0,iVar2);
  iVar2 = xtra_getBufferSize((int)local_134);
  if (iVar2 == 0) {
    local_120 = (void *)0x1;
  }
  iVar2 = Ordinal_294(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar4,0x65,
                      (uint *)&local_11c);
  if (iVar2 == 0) goto switchD_6808157b_caseD_4;
  if (local_11c == (void *)0x1) {
    local_140 = 1;
  }
  local_128 = (void *)media_lookupAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),
                                   pvVar4);
  iVar2 = media_getAssetData(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar4,&local_c,
                       &local_13c);
  pvVar1 = local_128;
  pvVar3 = local_134;
  if ((iVar2 != 0) && ((int)local_c < (int)local_13c)) {
    *(code **)((int)param_1 + 0x84) = scoreEngine_initPlayback;
    if (*param_2 == 0x1e) {
      *(undefined4 *)param_2[8] = 2;
      uVar9 = scoreEngine_initPlayback(param_1,param_2);
    }
    else {
      scoreEngine_initPlayback(param_1,param_2);
    }
    goto switchD_6808157b_caseD_4;
  }
  switch(*param_2) {
  case 1:
  case 5:
    if (local_120 == (void *)0x0) {
      *(undefined4 *)((int)param_1 + 0x88) = 0;
    }
    break;
  case 2:
  case 6:
    local_c = (void *)0xffffffff;
    local_144 = (void *)Ordinal_1770(0x38);
    *(int *)((int)param_1 + 0x94) = param_2[4];
    if (local_120 == (void *)0x0) {
      *(undefined4 *)((int)param_1 + 0x88) = 1;
      Ordinal_374(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                  *(int *)((int)param_1 + 0x7c),0xd,(double *)&local_60);
      local_120 = (void *)xtra_layoutTextRun(local_12c,(int)local_124,param_2[2] - (int)local_60,
                                       param_2[3] - local_5c,(uint *)&local_c,0,0);
      if (-1 < (int)local_120) {
        sprites_getTextProperty(pvVar4,(int)local_120);
        pvVar1 = local_120;
        xtra_processTextRun(local_12c,local_124,(int)local_120,&local_20);
        pvVar3 = local_128;
        pvVar4 = local_130;
        if (local_128 != pvVar1) {
          if (local_144 == (void *)0x0) {
            media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),local_130,
                         (void *)0x0,(void *)0x0);
            Ordinal_374(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                        *(int *)((int)param_1 + 0x7c),0xd,(double *)&local_60);
            Ordinal_1064(&local_20,local_60,local_5c);
            iVar2 = Ordinal_1066(&local_20,&local_20,&local_60);
            if (iVar2 == 0) {
              Ordinal_1839(local_138[1],0);
            }
            else {
              Ordinal_1839(local_138[1],&local_20);
              media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                           *(int *)((int)param_1 + 0x7c),(int)pvVar1,1);
              media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                           (int)pvVar1);
            }
          }
          else {
            if ((int)local_128 < (int)pvVar1) {
              media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),local_130,
                           local_128,pvVar1);
            }
            else {
              media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),local_130,
                           pvVar1,local_128);
              media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),local_130,
                           (int)pvVar3);
            }
            Ordinal_1839(local_138[1],0);
            media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                         *(int *)((int)param_1 + 0x7c),(int)pvVar1,0);
            sprites_getTextInfo(local_60);
            *(code **)((int)param_1 + 0x84) = scoreEngine_handleTextSelection;
          }
        }
        goto switchD_6808157b_caseD_b;
      }
    }
    break;
  case 3:
  case 7:
    if ((local_120 == (void *)0x0) &&
       (iVar2 = sprites_getTextPropertyEx(pvVar4,(int)local_134,(int)local_128,(int *)&local_c,(int *)&local_144)
       , pvVar3 = local_c, iVar2 != 0)) {
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,(int)local_c
                  );
      *(void **)((int)param_1 + 0x90) = local_144;
      *(void **)((int)param_1 + 0x8c) = pvVar3;
      *(undefined4 *)((int)param_1 + 0x88) = 1;
      media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,pvVar3,
                   local_144);
      Ordinal_1839(local_138[1],0);
      media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                   *(int *)((int)param_1 + 0x7c),(int)pvVar3,0);
      sprites_getTextInfo(pvVar4);
      *(code **)((int)param_1 + 0x84) = scoreEngine_initPlayback;
    }
    break;
  case 9:
    iVar2 = Ordinal_1541();
    if (((0xf9 < (uint)(iVar2 - *(int *)((int)param_1 + 0x94))) && (local_120 == (void *)0x0)) &&
       (*(int *)((int)param_1 + 0x88) != 0)) {
      Ordinal_1839(param_2[1],0);
      media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                   *(int *)((int)param_1 + 0x7c),0,0);
      *(code **)((int)param_1 + 0x84) = scoreEngine_handleTextSelection;
      uVar9 = scoreEngine_handleTextSelection((int)param_1,param_2);
    }
    break;
  case 10:
    local_13c = param_2[5] & 1;
    switch((char)param_2[6]) {
    case '0':
      goto switchD_6808191e_caseD_30;
    default:
      iVar2 = param_2[7];
      if (iVar2 != 0) {
        if ((param_2[5] & 0x10U) == 0) {
switchD_680822ad_caseD_62:
          if (local_120 == (void *)0x0) {
            Ordinal_1247(&local_10,iVar2);
            iVar2 = param_2[8];
            *(undefined1 *)((int)&local_10 + iVar2) = 0;
            sprites_processEditMenu((int)param_1,local_12c,pvVar4,(int)local_134,(int)local_124,(int)&local_10,
                         iVar2,(int)local_128,1);
            goto LAB_68081a2b;
          }
          xtra_appendToBuffer((int)local_134,local_104,0);
          Ordinal_1247(&local_10,local_138[7]);
          iVar2 = local_138[8];
          *(undefined1 *)((int)&local_10 + iVar2) = 0;
          xtra_replaceBufferRange((int)pvVar3,(int)&local_10,iVar2,local_104);
          xtra_replaceBufferRange((int)local_124,(int)&local_10,local_138[8],local_104);
          Ordinal_293(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),pvVar4,10,
                      (uint *)0x0);
          iVar2 = xtra_getBufferSize((int)pvVar3);
          media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,iVar2);
          media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                       *(int *)((int)param_1 + 0x7c),iVar2,1);
          sprites_getTextInfo(pvVar4);
        }
        else {
          switch(iVar2) {
          case 0x61:
          case 99:
          case 0x78:
          case 0x7a:
            break;
          default:
            goto switchD_680822ad_caseD_62;
          case 0x76:
            local_140 = 0;
            iVar2 = events_getScoreAnnotation(*(int *)((int)param_1 + 0xc));
            if ((iVar2 != 0) && (iVar2 = Ordinal_2000(), iVar2 != 0)) {
              iVar2 = Ordinal_2007(0,0);
              if ((iVar2 != 0) &&
                 ((local_140 = Ordinal_1126(iVar2,0), local_140 != 0 &&
                  (iVar2 = Ordinal_2007(local_140,iVar2), iVar2 != 0)))) {
                iVar2 = Ordinal_1201(local_140);
                sprites_processEditMenu((int)param_1,local_12c,pvVar4,(int)local_134,(int)local_124,local_140,
                             iVar2,(int)local_128,1);
              }
              Ordinal_1127(&local_140);
              Ordinal_2001();
            }
          }
        }
      }
      goto switchD_6808191e_caseD_30;
    case '3':
      if (0 < (int)local_128) {
        pvVar3 = (void *)sprites_handleTextEvent((int)local_134,(int)local_128);
        local_128 = pvVar3;
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),local_60,
                     (int)pvVar3);
        media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                     *(int *)((int)param_1 + 0x7c),(int)pvVar3,1);
        sprites_getTextInfo(pvVar4);
        goto switchD_6808191e_caseD_75;
      }
      goto switchD_6808191e_caseD_30;
    case 's':
      if (local_120 == (void *)0x0) {
        if (local_128 != (void *)0x0) {
          media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,0);
          if (local_140 != 0) {
            media_resolveAssetEx(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x28),pvVar4,2,1,0)
            ;
            sprites_getTextInfo(pvVar4);
          }
          if (local_13c == 0) {
            media_resolveAsset(*(int *)((int)param_1 + 0x20),(int)*(byte **)((int)param_1 + 0x80),
                         *(int *)((int)param_1 + 0x7c),0,1);
            sprites_getTextInfo(pvVar4);
            goto LAB_68081a2b;
          }
          media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                       (void *)0x0,local_128);
          Ordinal_1839(local_138[1],0);
          media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                       *(int *)((int)param_1 + 0x7c),0,0);
          sprites_getTextInfo(pvVar4);
          media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,0);
          *(code **)((int)param_1 + 0x84) = scoreEngine_initPlayback;
        }
        goto switchD_6808191e_caseD_30;
      }
      break;
    case 't':
      local_144 = (void *)0x1;
    case 'y':
      if (local_120 != (void *)0x0) break;
      xtra_processTextRun(local_12c,local_124,(int)local_128,&local_20);
      local_10 = local_18;
      if (local_140 != 0) {
        media_resolveAssetEx(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x28),pvVar4,1,
                     local_144,1);
      }
      pvVar3 = (void *)xtra_layoutTextRun(local_12c,(int)local_124,local_10,local_1c + local_14 >> 1,
                                    (uint *)0x0,0,0);
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,(int)pvVar3)
      ;
      if (local_13c != 0) {
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,pvVar3,
                     pvVar3);
        Ordinal_1839(local_138[1],0);
        media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                     *(int *)((int)param_1 + 0x7c),(int)pvVar3,0);
        sprites_getTextInfo(pvVar4);
        *(code **)((int)param_1 + 0x84) = scoreEngine_initPlayback;
        goto switchD_6808191e_caseD_30;
      }
      xtra_processTextRun(local_12c,local_124,(int)pvVar3,&local_20);
      media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                   *(int *)((int)param_1 + 0x7c),(int)pvVar3,1);
      sprites_getTextInfo(pvVar4);
      goto LAB_68081a2b;
    case 'u':
switchD_6808191e_caseD_75:
      if (local_120 == (void *)0x0) {
        iVar2 = xtra_measureBufferText((int)local_134,(int)local_128,0);
        pvVar3 = local_128;
        if (iVar2 != 0) {
          xtra_deleteBufferRange((int)local_134,(int)local_128,iVar2);
          xtra_deleteBufferRange((int)local_124,(int)pvVar3,iVar2);
          Ordinal_293(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),local_60,10,
                      (uint *)0x0);
          sprites_getTextProperty(local_60,(int)pvVar3);
          media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                       *(int *)((int)param_1 + 0x7c),(int)local_128,1);
          sprites_getTextInfo(local_130);
          pvVar4 = local_130;
        }
        goto switchD_6808191e_caseD_30;
      }
      break;
    case 'w':
      pvVar3 = (void *)xtra_getBufferSize((int)local_134);
      local_130 = pvVar3;
      if (local_120 == (void *)0x0) {
        local_144 = (void *)xtra_setBufferPos((int)local_134,0);
        local_c = (void *)Ordinal_1114(local_144);
        if (local_128 != pvVar3) {
          if (local_140 != 0) {
            media_resolveAssetEx(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x28),pvVar4,2,0,0)
            ;
            sprites_getTextInfo(pvVar4);
          }
          pvVar1 = local_128;
          pvVar3 = local_130;
          if (local_13c == 0) {
            media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                         (int)local_130);
            media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                         *(int *)((int)param_1 + 0x7c),(int)pvVar3,1);
            sprites_getTextInfo(pvVar4);
          }
          else {
            media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                         local_128,local_130);
            Ordinal_1839(local_138[1],0);
            media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                         *(int *)((int)param_1 + 0x7c),(int)pvVar1,0);
            sprites_getTextInfo(pvVar4);
            media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                         (int)local_130);
            *(code **)((int)param_1 + 0x84) = scoreEngine_initPlayback;
          }
        }
        if (local_c != (void *)0x0) {
          Ordinal_1115(local_144);
        }
        goto switchD_6808191e_caseD_30;
      }
      break;
    case '{':
      if (0 < (int)local_128) {
        pvVar4 = (void *)sprites_handleTextEvent((int)local_134,(int)local_128);
        local_128 = pvVar4;
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),local_60,
                     (int)pvVar4);
        iVar2 = sprites_getTextProperty(local_60,(int)pvVar4);
        pvVar4 = local_130;
        if (iVar2 != 0) {
          sprites_getTextInfo(local_130);
        }
        if (local_13c == 0) {
          media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                       *(int *)((int)param_1 + 0x7c),(int)local_128,1);
          sprites_getTextInfo(pvVar4);
          pvVar4 = local_130;
          goto LAB_68081a2b;
        }
LAB_68081b2b:
        pvVar8 = local_128;
        pvVar3 = (void *)sprites_handleTextScroll((int)local_134,(int)local_128);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,pvVar8,
                     pvVar3);
        Ordinal_1839(local_138[1],0);
        iVar2 = *(int *)((int)param_1 + 0x7c);
        iVar5 = *(int *)((int)param_1 + 0x80);
        iVar7 = *(int *)((int)param_1 + 0x20);
LAB_68081b74:
        media_resolveAsset(iVar7,iVar5,iVar2,(int)pvVar8,0);
        sprites_getTextInfo(pvVar4);
        *(code **)((int)param_1 + 0x84) = scoreEngine_initPlayback;
        pvVar4 = local_130;
      }
switchD_6808191e_caseD_30:
      if (local_13c == 0) {
LAB_68081a2b:
        pvVar3 = (void *)media_lookupAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),
                                      pvVar4);
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,pvVar3,
                     pvVar3);
      }
switchD_6808157b_caseD_b:
      uVar9 = 1;
      break;
    case '|':
      local_c = (void *)xtra_getBufferSize((int)local_134);
      if (local_120 == (void *)0x0) {
        iVar2 = xtra_setBufferPos((int)local_134,0);
        iVar5 = Ordinal_1114(iVar2);
        if (iVar5 != 0) {
          Ordinal_1115(iVar2);
        }
        if ((-1 < (int)local_128) && ((int)local_128 < (int)local_c)) {
          local_120 = (void *)sprites_handleTextScroll((int)local_134,(int)local_128);
          iVar2 = sprites_getTextProperty(pvVar4,(int)local_120);
          pvVar4 = local_130;
          if (iVar2 != 0) {
            sprites_getTextInfo(local_130);
          }
          pvVar3 = local_120;
          if (local_13c != 0) goto LAB_68081b2b;
          media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                       (int)local_120);
          media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                       *(int *)((int)param_1 + 0x7c),(int)pvVar3,1);
          sprites_getTextInfo(pvVar4);
          pvVar4 = local_130;
          goto LAB_68081a2b;
        }
        goto switchD_6808191e_caseD_30;
      }
      break;
    case '}':
      if (local_120 != (void *)0x0) break;
      xtra_processTextRun(local_12c,local_124,(int)local_128,&local_20);
      local_10 = local_18;
      iVar2 = xtra_setTextProperty(local_12c,(int)local_124,pvVar1);
      local_120 = (void *)xtra_layoutTextRun(local_12c,(int)local_124,local_10,0,(uint *)0x0,iVar2 + 1U,1)
      ;
      uVar6 = xtra_setTextProperty(local_12c,(int)local_124,local_120);
      pvVar3 = local_134;
      if (uVar6 != iVar2 + 1U) {
        local_120 = (void *)sprites_renderTextOverlay((int)local_134,(int)local_120);
      }
      if ((int)local_120 < 0) {
        local_c = (void *)xtra_getBufferSize((int)pvVar3);
        iVar2 = xtra_setBufferPos((int)pvVar3,0);
        iVar5 = Ordinal_1114(iVar2);
        if (iVar5 == 0) goto switchD_6808191e_caseD_30;
        local_120 = local_c;
        Ordinal_1115(iVar2);
      }
      iVar2 = sprites_getTextProperty(pvVar4,(int)local_120);
      pvVar4 = local_130;
      if (iVar2 != 0) {
        sprites_getTextInfo(local_130);
      }
      pvVar3 = local_120;
      xtra_processTextRun(local_12c,local_124,(int)local_120,&local_20);
      pvVar1 = local_128;
      pvVar8 = pvVar3;
joined_r0x68081f2a:
      if (local_13c != 0) {
        media_registerAssetWithData(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,pvVar1,
                     pvVar3);
        media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,
                     (int)pvVar8);
        Ordinal_1839(local_138[1],0);
        iVar2 = *(int *)((int)param_1 + 0x7c);
        iVar5 = *(int *)((int)param_1 + 0x80);
        iVar7 = *(int *)((int)param_1 + 0x20);
        goto LAB_68081b74;
      }
      media_resolveAsset(*(int *)((int)param_1 + 0x20),*(int *)((int)param_1 + 0x80),
                   *(int *)((int)param_1 + 0x7c),(int)pvVar8,1);
      media_registerAsset(*(int *)((int)param_1 + 0x20),*(byte **)((int)param_1 + 0x80),pvVar4,(int)pvVar8)
      ;
      sprites_getTextInfo(pvVar4);
      pvVar4 = local_130;
      goto LAB_68081a2b;
    case '~':
      if (local_120 == (void *)0x0) {
        xtra_processTextRun(local_12c,local_124,(int)local_128,&local_20);
        local_10 = local_18;
        iVar2 = xtra_setTextProperty(local_12c,(int)local_124,pvVar1);
        local_120 = (void *)xtra_layoutTextRun(local_12c,(int)local_124,local_10,0,(uint *)0x0,iVar2 - 1U,
                                         1);
        uVar6 = xtra_setTextProperty(local_12c,(int)local_124,local_120);
        if (uVar6 != iVar2 - 1U) {
          local_120 = (void *)sprites_renderTextOverlay((int)local_134,(int)local_120);
        }
        if ((int)local_120 < 0) {
          local_120 = (void *)0x0;
        }
        iVar2 = sprites_getTextProperty(pvVar4,(int)local_120);
        pvVar4 = local_130;
        if (iVar2 != 0) {
          sprites_getTextInfo(local_130);
        }
        pvVar1 = local_120;
        xtra_processTextRun(local_12c,local_124,(int)local_120,&local_20);
        pvVar3 = local_128;
        pvVar8 = pvVar1;
        goto joined_r0x68081f2a;
      }
    }
    break;
  case 0xb:
    goto switchD_6808157b_caseD_b;
  case 0x1e:
    if (param_2[8] != 0) {
      uVar9 = scoreEngine_dispatchTextEdit(local_134,local_12c,param_1,pvVar4,local_124);
    }
  }
switchD_6808157b_caseD_4:
LAB_68081a5a:
  if (local_12c != 0) {
    Ordinal_1601(&local_12c,uVar9);
  }
  xtra_resetBuffer((int)local_124);
  return 0;
}



