// Module: props
// Topic: Error handling, reporting, and translation
// Address range: 0x680307b0 - 0x68037c80
// Functions (9):
//   props_setHaltState (FUN_680307b0)
//   props_translateError (FUN_680307f0)
//   props_formatError (FUN_68030ab0)
//   props_setErrorAndReturn (FUN_68031d70)
//   props_setError (FUN_68031da0)
//   props_reportError (FUN_68031dc0)
//   props_validateString (FUN_68031de0)
//   props_setTypeError (FUN_68032ab0)
//   props_mapErrorCode (FUN_68037c80)



// ============================================================
// Function: props_setHaltState (FUN_680307b0)
// Address: 680307b0
// Size: 50 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Sets the halt/abort state on the VM context
// ============================================================

int props_setHaltState(int param_1,int param_2)
{
  if (param_2 == 3) {
    *(undefined4 *)(param_1 + 0x7c) = 2;
    *(undefined4 *)(param_1 + 0x74) = 8;
    return 0;
  }
  *(int *)(param_1 + 0x7c) = param_2;
  *(undefined4 *)(param_1 + 0x74) = 8;
  return 0;
}



// ============================================================
// Function: props_translateError (FUN_680307f0)
// Address: 680307f0
// Size: 533 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// Translates an HRESULT/COM error code to an internal error code
// ============================================================

undefined4 props_translateError(int param_1)

{
  if (param_1 < -0x7ffbf82c) {
    if (param_1 == -0x7ffbf82d) {
      return 0x7c;
    }
    if (param_1 != -0x7ffbffff) {
      if (param_1 == -0x7ffbfffa) {
        return 0x7a;
      }
      if (param_1 != -0x7ffbffed) {
        return 0x61;
      }
    }
    return 0x79;
  }
  if (param_1 < -0x7ffbf447) {
    if (param_1 == -0x7ffbf448) {
      return 0x10;
    }
    switch(param_1) {
    case -0x7ffbf82b:
      return 0x37;
    case -0x7ffbf82a:
      return 0x39;
    case -0x7ffbf829:
      return 3;
    case -0x7ffbf828:
      return 0x3d;
    case -0x7ffbf827:
      return 7;
    case -0x7ffbf826:
      return 0xb;
    case -0x7ffbf825:
      return 9;
    case -0x7ffbf824:
      return 10;
    case -0x7ffbf823:
      return 0xf;
    case -0x7ffbf822:
      return 0xe;
    case -0x7ffbf821:
      return 0x1c;
    case -0x7ffbf820:
      return 0x14;
    case -0x7ffbf81f:
      return 0x15;
    case -0x7ffbf81e:
      return 0x16;
    case -0x7ffbf81d:
      return 0x17;
    case -0x7ffbf81c:
      return 0x18;
    case -0x7ffbf81b:
      return 0x19;
    case -0x7ffbf811:
    case -0x7ffbf80c:
      return 0x13;
    case -0x7ffbf810:
      return 0x69;
    case -0x7ffbf80f:
      return 0x6c;
    case -0x7ffbf80e:
      return 0x6d;
    case -0x7ffbf80b:
      return 0x77;
    case -0x7ffbf80a:
      return 0x78;
    case -0x7ffbf808:
      return 0x7e;
    }
  }
  else if (param_1 < -0x7ffb9ffd) {
    if (param_1 == -0x7ffb9ffe) {
      return 0x74;
    }
    if (param_1 < -0x7ffbf42a) {
      if (param_1 == -0x7ffbf42b) {
        return 0x72;
      }
      if (param_1 == -0x7ffbf446) {
        return 0x12;
      }
      if (param_1 == -0x7ffbf43b) {
        return 0x23;
      }
    }
    else {
      if (param_1 == -0x7ffbf42a) {
        return 0x7b;
      }
      if (param_1 == -0x7ffbed20) {
        return 0x6f;
      }
    }
  }
  else if (param_1 < -0x7ffb8eff) {
    if (param_1 == -0x7ffb8f00) {
      return 0x7d;
    }
    switch(param_1) {
    case -0x7ffb9ffd:
      return 0xc;
    case -0x7ffb9ffc:
      return 0x3c;
    case -0x7ffb9ffa:
      return 0x73;
    case -0x7ffb9ff9:
      return 0x75;
    case -0x7ffb9ff8:
      return 0x76;
    }
  }
  else if (param_1 == 0) {
    return 0;
  }
  return 0x61;
}



// ============================================================
// Function: props_formatError (FUN_68030ab0)
// Address: 68030ab0
// Size: 172 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, undefined4 param_9
// Return: undefined
// Calling convention: __stdcall
// Formats and reports an error with string details
// ============================================================

int props_formatError(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9)
{
  undefined1 local_808 [1024];
  undefined1 local_408 [1024];
  uint local_8;
  
  cast_setErrorCallback(param_1,param_4);
  if (-1 < param_6) {
    cast_loadPascalString(local_808,0x960,7);
    Ordinal_1235(param_5,local_808,param_6 + 1);
  }
  cast_loadPascalString(local_408,param_3,param_4);
  sprites_getSystemInfo(param_1,param_2,local_408,param_5,param_7,param_8,param_4,param_9);
  return 0;
}



// ============================================================
// Function: props_setErrorAndReturn (FUN_68031d70)
// Address: 68031d70
// Size: 47 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setErrorAndReturn(int param_1,int param_2)
{
  int extraout_EDX;
  
  props_setHaltState(param_1,param_2);
  if (*(int *)(extraout_EDX + 0x7c) == 2) {
    rendering_updateDisplay();
    return 0;
  }
  props_setReturnValue(extraout_EDX,(uint *)&stack0x0000000c);
  return 0;
}



// ============================================================
// Function: props_setError (FUN_68031da0)
// Address: 68031da0
// Size: 26 bytes
// Params: int ctx, int errorCode
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_setError(int ctx,int errorCode)
{
  props_setErrorAndReturn(ctx,errorCode);
  return 0;
}



// ============================================================
// Function: props_reportError (FUN_68031dc0)
// Address: 68031dc0
// Size: 28 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_reportError(int param_1,int param_2)
{
  props_setErrorAndReturn(param_1,param_2);
  return 0;
}



// ============================================================
// Function: props_validateString (FUN_68031de0)
// Address: 68031de0
// Size: 51 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_validateString(int param_1,int *param_2)

{
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    props_setErrorAndReturn(param_1,10);
    return 0;
  }
  return 1;
}



// ============================================================
// Function: props_setTypeError (FUN_68032ab0)
// Address: 68032ab0
// Size: 141 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// Maps a value type tag to the appropriate error code
// ============================================================

int props_setTypeError(int param_1,undefined4 param_2)
{
  switch(param_2) {
  case 1:
  case 0x40:
  case 0x43:
    props_setErrorAndReturn(param_1,10);
    return 0;
  default:
    props_setErrorAndReturn(param_1,0x13);
    return 0;
  case 3:
    props_setErrorAndReturn(param_1,0xc);
    return 0;
  case 4:
    props_setErrorAndReturn(param_1,7);
    return 0;
  case 8:
    props_setErrorAndReturn(param_1,0xb);
    return 0;
  }
}



// ============================================================
// Function: props_mapErrorCode
// Address: 68037c80
// Size: 1010 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_mapErrorCode(int param_1,int param_2,undefined4 param_3)

{
  uint local_c;
  undefined4 local_8;
  
  local_c = 8;
  local_8 = param_3;
  if (param_2 < -0x7ffbf82e) {
    if (-0x7ffbf831 < param_2) {
      props_setErrorAndReturn(param_1,0x1a);
      return param_2;
    }
    switch(param_2) {
    case -0x7ffbffff:
      props_setErrorAndReturn(param_1,0x79);
      return param_2;
    case -0x7ffbfffe:
switchD_68037cbe_caseD_80040002:
      props_setError(param_1,2);
      return param_2;
    case -0x7ffbfffa:
      props_setErrorAndReturn(param_1,0x7a);
      return param_2;
    case -0x7ffbffec:
switchD_68037cbe_caseD_80040014:
      props_setErrorAndReturn(param_1,0x71);
      return param_2;
    }
  }
  else if (param_2 < -0x7ffbf447) {
    if (param_2 == -0x7ffbf448) {
      props_setErrorAndReturn(param_1,0x10);
      return -0x7ffbf448;
    }
    switch(param_2) {
    case -0x7ffbf82e:
      goto switchD_68037cbe_caseD_80040014;
    case -0x7ffbf82a:
      props_setErrorAndReturn(param_1,0x39);
      return param_2;
    case -0x7ffbf829:
      props_setErrorAndReturn(param_1,3);
      return param_2;
    case -0x7ffbf828:
      props_setErrorAndReturn(param_1,0x3d);
      return param_2;
    case -0x7ffbf827:
      props_setErrorAndReturn(param_1,7);
      return param_2;
    case -0x7ffbf826:
      props_setErrorAndReturn(param_1,0xb);
      return param_2;
    case -0x7ffbf825:
      props_setErrorAndReturn(param_1,9);
      return param_2;
    case -0x7ffbf824:
      props_setErrorAndReturn(param_1,10);
      return param_2;
    case -0x7ffbf823:
      props_setErrorAndReturn(param_1,0xf);
      return param_2;
    case -0x7ffbf822:
      props_setErrorAndReturn(param_1,0xe);
      return param_2;
    case -0x7ffbf821:
      props_setErrorAndReturn(param_1,4);
      return param_2;
    case -0x7ffbf820:
      props_setErrorAndReturn(param_1,0x14);
      return param_2;
    case -0x7ffbf81f:
      props_setErrorAndReturn(param_1,0x15);
      return param_2;
    case -0x7ffbf81e:
      props_setErrorAndReturn(param_1,0x16);
      return param_2;
    case -0x7ffbf81d:
      props_setErrorAndReturn(param_1,0x17);
      return param_2;
    case -0x7ffbf81c:
      props_setErrorAndReturn(param_1,0x18);
      return param_2;
    case -0x7ffbf81b:
      props_setErrorAndReturn(param_1,0x19);
      return param_2;
    case -0x7ffbf811:
    case -0x7ffbf80c:
      props_setErrorAndReturn(param_1,0x13);
      return param_2;
    case -0x7ffbf810:
      props_setErrorAndReturn(param_1,0x69);
      return param_2;
    case -0x7ffbf80f:
      props_setErrorAndReturn(param_1,0x6c);
      return param_2;
    case -0x7ffbf80e:
      props_setErrorAndReturn(param_1,0x6d);
      return param_2;
    case -0x7ffbf80d:
      props_setErrorAndReturn(param_1,0x66);
      return param_2;
    case -0x7ffbf80b:
      props_setErrorAndReturn(param_1,0x77);
      return param_2;
    case -0x7ffbf80a:
      props_setErrorAndReturn(param_1,0x78);
      return param_2;
    case -0x7ffbf808:
      props_setErrorAndReturn(param_1,0x7e);
      return param_2;
    }
  }
  else if (param_2 < -0x7ffb9ffd) {
    if (param_2 == -0x7ffb9ffe) {
      props_setError(param_1,0x74);
      return -0x7ffb9ffe;
    }
    if (param_2 == -0x7ffbf42a) {
      props_setErrorAndReturn(param_1,0x7b);
      return -0x7ffbf42a;
    }
  }
  else if (param_2 < -0x7ffb8eff) {
    if (param_2 == -0x7ffb8f00) {
      props_setErrorAndReturn(param_1,0x7d);
      return -0x7ffb8f00;
    }
    switch(param_2) {
    case -0x7ffb9ffc:
      props_setErrorAndReturn(param_1,0x3c);
      return param_2;
    case -0x7ffb9ffb:
    case -0x7ffb9ff6:
      goto switchD_68037cbe_caseD_80040014;
    case -0x7ffb9ffa:
      props_setErrorAndReturn(param_1,0x73);
      return param_2;
    case -0x7ffb9ff9:
      props_setErrorAndReturn(param_1,0x75);
      return param_2;
    case -0x7ffb9ff8:
      props_setErrorAndReturn(param_1,0x76);
      return param_2;
    case -0x7ffb9ff7:
      goto switchD_68037cbe_caseD_80040002;
    }
  }
  props_setReturnValue(param_1,&local_c);
  return param_2;
}


