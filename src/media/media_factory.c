// Module: media
// Topic: Factory and type registration functions
// Address range: 0x680a0040 - 0x680a15e0
// Functions (22):
//   media_createImageObject
//   media_createStringObject
//   media_createPropertyObject
//   media_createPixelSetObject
//   media_createDrawObject
//   media_createPropValueObject
//   media_createTextObject
//   media_createDialogObject
//   media_createByteIoObject
//   media_createTimerObject
//   media_createXtraApiObject
//   media_createScriptApiObject
//   media_createStreamApiObject
//   media_createInsertObject
//   media_createListApiObject
//   media_createCloneObject
//   media_createMergeObject
//   media_createStreamReadObject
//   media_getPixelOpState
//   media_registerPixelOpState
//   media_unregisterPixelOpState
//   media_allocPixelOpState

// ============================================================
// Function: media_createImageObject (media_createImageObject)
// Address: 680a0040
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createImageObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getImageVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createStringObject (media_createStringObject)
// Address: 680a00a0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createStringObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getStringVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createPropertyObject (media_createPropertyObject)
// Address: 680a0100
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createPropertyObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getPropertyVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createPixelSetObject (media_createPixelSetObject)
// Address: 680a0160
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createPixelSetObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getPixelSetVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createDrawObject (media_createDrawObject)
// Address: 680a01c0
// Size: 94 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createDrawObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getDrawVtable();
  piVar3 = lingo_createObject(param_1,0x440,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createPropValueObject (media_createPropValueObject)
// Address: 680a0220
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createPropValueObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getPropValueVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createTextObject (media_createTextObject)
// Address: 680a0280
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createTextObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getTextVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createDialogObject (media_createDialogObject)
// Address: 680a02e0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createDialogObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getDialogVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createByteIoObject (media_createByteIoObject)
// Address: 680a0340
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createByteIoObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getByteIoVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createTimerObject (media_createTimerObject)
// Address: 680a03a0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createTimerObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getTimerVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createXtraApiObject (media_createXtraApiObject)
// Address: 680a0400
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createXtraApiObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getXtraApiVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createScriptApiObject (media_createScriptApiObject)
// Address: 680a0460
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createScriptApiObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getScriptApiVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createStreamApiObject (media_createStreamApiObject)
// Address: 680a04c0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createStreamApiObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getStreamApiVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createInsertObject (media_createInsertObject)
// Address: 680a0520
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createInsertObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getInsertVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createListApiObject (media_createListApiObject)
// Address: 680a0580
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createListApiObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getListApiVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createCloneObject (media_createCloneObject)
// Address: 680a05e0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createCloneObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getCloneVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createMergeObject (media_createMergeObject)
// Address: 680a0640
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createMergeObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getMergeVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: media_createStreamReadObject (media_createStreamReadObject)
// Address: 680a06a0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createStreamReadObject(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_getStreamReadVtable();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



int lingo_createVtableObject(); /* FIXUP(C2065): missing forward declaration */
// ============================================================
// Function: media_getPixelOpState (FUN_680a0700)
// Address: 680a0700
// Size: 3636 bytes
// Params: int param_1, undefined * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getPixelOpState(int param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  code *unaff_EBX;
  
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176358), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176358,1,0x34,lingo_initPlaybackDefaults,lingo_destroyPlaybackRefs), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175b98,1,lingo_createSeekStreamObj);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176248,1,lingo_createGetPosObj);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175c78,1,media_createPropValueObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175da8,1,lingo_vtableDispatchE);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175d18,1,globals_createFullObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175d68,1,globals_createStreamObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175d78,1,globals_createMediaObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175d88,1,globals_createBuildInfoObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175d98,1,globals_createDialogObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175d28,1,globals_createAccessorObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176008,1,globals_createTimerObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681760a8,1,globals_createStringIoObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681760b8,1,globals_createHandlerObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681760c8,1,globals_createByteIoObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681760d8,1,globals_createPairObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681762f8,1,globals_createReadWriteObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176238,1,lingo_createOpenStreamObj);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176268,1,lingo_createWriteStreamObj);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68175ff8,1,lingo_vtableDispatchF);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176018,1,media_createTextObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176288,1,media_createDialogObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176298,1,media_createXtraApiObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176048,1,lingo_vtableDispatchD);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681762a8,1,media_createByteIoObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176088,1,media_createTimerObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176318,1,globals_createMediaDispatchObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176328,1,globals_createVectorObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176278,1,media_createImageObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176188,1,media_createStringObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681762b8,1,media_createPropertyObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176058,1,lingo_vtableDispatchC);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176068,1,lingo_vtableDispatchB);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176258,1,lingo_createCloseStreamObj);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681762c8,1,media_createPixelSetObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681762d8,1,media_createDrawObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_681760e8,1,globals_createPropertyObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176348,1,media_createScriptApiObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176078,1,lingo_vtableDispatchA);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176358,1,&DAT_68176338,1,globals_createExtPropertyObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176368), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176368,1,0x1c,mediaPlayback_clearInterfaceRef,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176368,1,&DAT_68175fc8,1,mediaPlayback_createXtraAssetObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176368,1,&DAT_68175fd8,1,mediaPlayback_createXtraAssetExObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176368,1,&DAT_68175fe8,1,mediaPlayback_createXtraCallbackObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176368,1,&DAT_68176378,1,mediaPlayback_createXtraValueReadObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176368,1,&DAT_68176098,1,lingo_createReadStreamObj);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_681763e8), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_681763e8,1,0x3c,mediaPlayback_resetInterfaceState,mediaPlayback_cleanupInterface), iVar1 != 0)) {
      return iVar1;
    }
    if ((unaff_EBX != (code *)0x0) &&
       (iVar1 = (*unaff_EBX)(&DAT_681763e8,1,&DAT_68175fb8,1,mediaPlayback_createXtraScoreObject), iVar1 != 0)) {
      return iVar1;
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176388), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176388,1,0x1c,mediaPlayback_clearInterfaceRef,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176388,1,&DAT_68175f88,1,mediaPlayback_createXtraHandlerObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176388,1,&DAT_68176398,1,mediaPlayback_createXtraValueReadAltObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_681763a8), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_681763a8,1,0x20,media_resetXtraFields,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_681763a8,1,&DAT_68175f98,1,mediaPlayback_createXtraStreamObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_681763a8,1,&DAT_681763b8,1,mediaPlayback_createXtraStreamReadObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_681763c8), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_681763c8,1,0x20,media_resetXtraFields,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_681763c8,1,&DAT_68175fa8,1,mediaPlayback_createXtraNotifyObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_681763c8,1,&DAT_681763d8,1,mediaPlayback_createXtraStreamReadAltObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_681763f8), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_681763f8,1,0x28,mediaPlayback_clearPlaybackRect,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_681763f8,1,&DAT_68175f78,1,mediaPlayback_createXtraChannelObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_681763f8,1,&DAT_68176408,1,mediaPlayback_createXtraRectObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176418), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176418,1,0x2c,mediaPlayback_clearPlaybackRectEx,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176418,1,&DAT_68175f68,1,mediaPlayback_createXtraScoreChannelObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176418,1,&DAT_68176428,1,mediaPlayback_createXtraTransformAltObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176438), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176438,1,0x34,lingo_initStreamState,lingo_flushStreamState), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176438,1,&DAT_68175c68,1,media_createStreamApiObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176438,1,&DAT_68176448,1,media_createInsertObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176458), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176458,1,0x34,lingo_noop,media_getXtraMovieState), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176458,1,&DAT_68175ca8,1,mediaPlayback_createXtraImageObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176458,1,&DAT_68175cb8,1,mediaPlayback_createXtraInterfaceObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176458,1,&DAT_68176468,1,mediaPlayback_createXtraMovieDataObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176478), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176478,1,0x20,media_resetXtraFields,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176478,1,&DAT_68175cc8,1,mediaPlayback_createXtraDirtyCheckObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176478,1,&DAT_68176488,1,mediaPlayback_createXtraValueObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_68176498), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_68176498,1,0x2c,lingo_noop,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_68176498,1,&DAT_68175cd8,1,mediaPlayback_createXtraPixelDataObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176498,1,&DAT_68175ce8,1,mediaPlayback_createXtraPixelFlushObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176498,1,&DAT_681764a8,1,mediaPlayback_createXtraTransformObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176498,1,&DAT_68176028,1,mediaPlayback_createXtraPixelBlockObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_68176498,1,&DAT_68175d58,1,mediaPlayback_createXtraPixelRegionObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  if ((param_1 == 0) || (iVar1 = Ordinal_2066(param_1,&DAT_681764b8), iVar1 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_681764b8,1,0x20,lingo_noop,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    if (unaff_EBX != (code *)0x0) {
      iVar1 = (*unaff_EBX)(&DAT_681764b8,1,&DAT_68175cf8,1,media_createListApiObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_681764b8,1,&DAT_681764c8,1,media_createStreamReadObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_681764b8,1,&DAT_68176038,1,media_createMergeObject);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*unaff_EBX)(&DAT_681764b8,1,&DAT_68175d08,1,media_createCloneObject);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  iVar1 = 0;
  if ((param_1 == 0) || (iVar2 = Ordinal_2066(param_1,&DAT_681764d8), iVar2 != 0)) {
    if ((param_2 != (undefined *)0x0) &&
       (iVar1 = (*(code *)param_2)(&DAT_681764d8,1,0x38,lingo_noop,rendering_updateDisplay), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = 0;
    if ((unaff_EBX != (code *)0x0) &&
       (iVar1 = (*unaff_EBX)(&DAT_681764d8,1,&DAT_68175c48,1,mediaPlayback_createXtraCallbackClearObject), iVar1 == 0)) {
      iVar1 = (*unaff_EBX)(&DAT_681764d8,1,&DAT_68175c38,1,mediaPlayback_createXtraCallbackSetObject);
    }
  }
  return iVar1;
}



// ============================================================
// Function: media_registerPixelOpState (FUN_680a1540)
// Address: 680a1540
// Size: 71 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_registerPixelOpState(int param_1)

{
  media_getPixelOpState(param_1,lingo_createVtableObject);
  return 0x80040005;
}



// ============================================================
// Function: media_unregisterPixelOpState (FUN_680a1590)
// Address: 680a1590
// Size: 76 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x680a15c1) */

undefined4 media_unregisterPixelOpState(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  media_getPixelOpState(param_2,(undefined *)0x0);
  return 0x80040004;
}



// ============================================================
// Function: media_allocPixelOpState (FUN_680a15e0)
// Address: 680a15e0
// Size: 207 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_allocPixelOpState(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  media_getPixelOpState(0,lingo_setVtableSlot);
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(param_1,0x28);
  *param_2 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80040002;
  }
  media_getPixelOpState(0,lingo_setVtableSlot);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  return 0;
}
