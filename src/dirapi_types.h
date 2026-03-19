#ifndef DIRAPI_TYPES_H
#define DIRAPI_TYPES_H

/*
 * dirapi_types.h - Type definitions for Ghidra decompiler output
 *
 * Maps Ghidra-specific type names to standard C types for compilation.
 */

#ifdef _MSC_VER
#pragma warning(disable: 4013)  /* function undefined; assuming extern returning int */
#pragma warning(disable: 4024)  /* different types for formal and actual parameter */
#pragma warning(disable: 4047)  /* differs in levels of indirection */
#pragma warning(disable: 4133)  /* incompatible types */
#pragma warning(disable: 4146)  /* unary minus operator applied to unsigned type */
#pragma warning(disable: 4244)  /* conversion, possible loss of data */
#pragma warning(disable: 4305)  /* truncation */
#pragma warning(disable: 4311)  /* pointer truncation */
#pragma warning(disable: 4312)  /* conversion to greater size */
#pragma warning(disable: 4700)  /* uninitialized local variable used */
#pragma warning(disable: 4715)  /* not all control paths return a value */
#pragma warning(disable: 4716)  /* must return a value */
#pragma warning(disable: 4028)  /* formal parameter differs from declaration */
#pragma warning(disable: 4113)  /* function type differs from declaration */
#pragma warning(disable: 4098)  /* void function returning a value */
#pragma warning(disable: 4033)  /* function must return a value */
#pragma warning(disable: 4022)  /* pointer mismatch for actual parameter */
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <ole2.h>
#include <oleauto.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* __thiscall is C++-only in MSVC; replace with __cdecl in C mode */
#ifndef __cplusplus
#ifdef _MSC_VER
/* MSVC C mode doesn't support __thiscall - use __cdecl instead */
/* The 'this' pointer will be passed on the stack instead of ECX */
#pragma warning(disable: 4005)
#define __thiscall __cdecl
#pragma warning(default: 4005)
#endif
#endif

/* Ghidra decompiler type aliases */
typedef unsigned char       undefined;
typedef unsigned char       undefined1;
typedef unsigned short      undefined2;
typedef unsigned int        undefined3;
typedef unsigned int        undefined4;
typedef unsigned long long  undefined8;

/* Ghidra x87 FPU extended precision type (80-bit) */
/* MSVC long double == double (64-bit), closest approximation */
typedef double              float10;

/* Ghidra 3-byte unsigned integer */
typedef unsigned int        uint3;

/* Ghidra signed byte type */
typedef signed char         sbyte;

/* Ghidra primitive type aliases */
typedef unsigned char       byte;
typedef unsigned int        uint;
typedef unsigned short      ushort;
typedef unsigned char       uchar;
typedef long long           longlong;
typedef unsigned long long  ulonglong;
typedef unsigned long       ulong;

/* Ghidra 'code' type - used for function pointers */
typedef int code();

/* Ghidra 'bool' - C89 doesn't have bool */
#ifndef __cplusplus
#ifndef bool
typedef int bool;
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#endif

/* Stack cookie support */
extern unsigned int __security_cookie;
#ifndef __security_check_cookie
void __fastcall __security_check_cookie(unsigned int cookie);
#endif
#ifndef __security_init_cookie
void __security_init_cookie(void);
#endif
#ifndef __report_gsfailure
void __declspec(noreturn) __report_gsfailure(void);
#endif

/* StackBase - Ghidra reference to TEB stack base */
/* On x86 Windows, this is at fs:[0x04] */
#ifdef _MSC_VER
#define StackBase ((void *)__readfsdword(4))
#else
#define StackBase ((void *)0)
#endif

/* Ghidra internal types - function pointer types */
typedef void (*_func_4879)(void);

/* Ghidra internal types - VARIANT union body */
typedef union _union_2683 {
    unsigned char bytes[16];
    struct {
        unsigned short vt;
        unsigned short wReserved1;
        unsigned short wReserved2;
        unsigned short wReserved3;
        union {
            long long llVal;
            long lVal;
            unsigned char bVal;
            short iVal;
            float fltVal;
            double dblVal;
            int intVal;
            unsigned int uintVal;
            void *pvRecord;
            void *byref;
        } n3;
    } s;
} _union_2683;

/* Suppress warnings about Ghidra-generated patterns */
#ifdef _MSC_VER
#pragma warning(disable: 4102)  /* unreferenced label */
#pragma warning(disable: 4101)  /* unreferenced local variable */
#pragma warning(disable: 4060)  /* switch contains no case or default */
#pragma warning(disable: 4065)  /* switch contains default but no case */
#endif

/* Ghidra 3-byte integer type */
typedef unsigned int int3;

/* Ghidra CONCAT macros - concatenate two values into a wider type
 * CONCATXY(a, b) = (a << (Y*8)) | b, producing (X+Y) byte result
 * a is X bytes wide (high part), b is Y bytes wide (low part)
 */
#define CONCAT11(hi, lo) ((unsigned short)(((unsigned short)(unsigned char)(hi) << 8) | (unsigned char)(lo)))
#define CONCAT12(hi, lo) ((unsigned int)(((unsigned int)(unsigned char)(hi) << 16) | (unsigned short)(lo)))
#define CONCAT13(hi, lo) ((unsigned int)(((unsigned int)(unsigned char)(hi) << 24) | ((unsigned int)(lo) & 0xFFFFFF)))
#define CONCAT14(hi, lo) ((unsigned long long)(((unsigned long long)(unsigned char)(hi) << 32) | (unsigned int)(lo)))
#define CONCAT15(hi, lo) ((unsigned long long)(((unsigned long long)(unsigned char)(hi) << 40) | ((unsigned long long)(lo) & 0xFFFFFFFFFFULL)))
#define CONCAT21(hi, lo) ((unsigned int)(((unsigned int)(unsigned short)(hi) << 8) | (unsigned char)(lo)))
#define CONCAT22(hi, lo) ((unsigned int)(((unsigned int)(unsigned short)(hi) << 16) | (unsigned short)(lo)))
#define CONCAT24(hi, lo) ((unsigned long long)(((unsigned long long)(unsigned short)(hi) << 32) | (unsigned int)(lo)))
#define CONCAT26(hi, lo) ((unsigned long long)(((unsigned long long)(unsigned short)(hi) << 48) | ((unsigned long long)(lo) & 0xFFFFFFFFFFFFULL)))
#define CONCAT31(hi, lo) ((unsigned int)(((unsigned int)(hi) << 8) | (unsigned char)(lo)))
#define CONCAT44(hi, lo) ((unsigned long long)(((unsigned long long)(unsigned int)(hi) << 32) | (unsigned int)(lo)))
#define CONCAT71(hi, lo) ((unsigned long long)(((unsigned long long)(hi) << 8) | (unsigned char)(lo)))

/* Ghidra SUB macros - extract sub-piece from larger value
 * SUBXY(val) = extract lower Y bytes from X-byte value
 */
#define SUB43(val) ((unsigned int)(val) & 0xFFFFFF)
#define SUB82(val) ((unsigned short)(unsigned long long)(val))
#define SUB84(val) ((unsigned int)(unsigned long long)(val))

/* Ghidra ZEXT macros - zero-extend to wider type */
#define ZEXT48(val) ((unsigned long long)(unsigned int)(val))


/* Ghidra pcode helper intrinsics */
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define CARRY4(a, b) ((unsigned int)(a) > (unsigned int)(a) + (unsigned int)(b))
#define SBORROW4(a, b) (((int)(a) >= 0 && (int)(b) < 0 && (int)((a)-(b)) < 0) || ((int)(a) < 0 && (int)(b) >= 0 && (int)((a)-(b)) >= 0))
#define POPCOUNT(x) __popcnt(x)
#define ROUND(x) ((int)((x) + 0.5))

/* CRT aliases for Ghidra-decompiled names.
   The original binary linked against MSVCR100.DLL (VS2010).
   These map Ghidra's decompiled names to the current CRT equivalents. */
#define builtin_strncpy strncpy
#define ftime64 _ftime64
#define operator_delete(p) free(p)
#define operator_new(s) malloc(s)

/* CRT internal functions - declared here, implemented in dirapi_globals.c */
int encoded_null(void);
int except_handler4_common();
void __cdecl initterm(void **start, void **end);
int __cdecl initterm_e(void **start, void **end);
/* __aullshr is defined in strings/funcs_68166c6e.c with __fastcall calling convention */

typedef long long int7;
extern int piRam00000008;
#define ExceptionList 0
extern int IMAGE_DOS_HEADER_68000000;
/* Ghidra computed goto switch tables - define as zero */
static int switchD_6803a1a7 = 0;
static int switchD_6808fe50 = 0;
static int switchD_6813a9c3 = 0;

/* ================================================================
 * Struct definitions — recovered from decompiled pointer arithmetic.
 * Only fields confirmed by cross-referencing multiple functions are named.
 * Unknown fields use field_0xNN naming. Gaps use _pad_NN[N].
 * ================================================================ */

/* MoaBool — Macromedia Open Architecture boolean */
typedef int MoaBool;

/* Player Object (param_1 as int* in ordinals 78-98)
 * 12 int-sized fields, total 0x30 bytes */
typedef struct Player {
    MoaBool valid;              /* +0x00  1 = active, 0 = disposed */
    int _pad_04;                /* +0x04  unused/padding */
    void *hostContext;          /* +0x08  parent/host context pointer */
    int scoreHandle;            /* +0x0C  score/movie handle */
    int playerState;            /* +0x10  0xFFFF=playing, 1=paused, 2=error */
    int idleState;              /* +0x14  0/1/2 */
    int exitCode;               /* +0x18  exit/quit reason code */
    int flags;                  /* +0x1C */
    void *callback;             /* +0x20  callback/handler */
    int pausedFlag;             /* +0x24  0=normal, 1=suspended */
    void *userData;             /* +0x28 */
    int busyFlag;               /* +0x2C */
} Player;

/* Forward declarations for cross-referencing structs */
typedef struct MovieData MovieData;
typedef struct MovieScoreData MovieScoreData;
typedef struct ScoreContextData ScoreContextData;
typedef struct XtraScoreCtx XtraScoreCtx;
typedef struct CastMemberInfo CastMemberInfo;
typedef struct RifxFile RifxFile;

/* ================================================================
 * Score Context structs (from dirapi_backup/src/xtra/xtra_score_layout.h)
 *
 * Chain: XtraScoreCtx -> ScoreContextData -> MovieData -> MovieScoreData
 * ================================================================ */

/* Extra context reached via ScoreContextData::extraCtx */
typedef struct ScoreContextExtra {
    char _pad00[0x0C];
    int  castLibIndex;          /* +0x0C  cast library index for reference resolution */
} ScoreContextExtra;

/* Score context internal data — the block at XtraScoreCtx +0x20 */
typedef struct ScoreContextData {
    int  moviePtr;              /* +0x00  pointer to the active MovieData */
    int  scoreDataPtr;          /* +0x04  pointer to score data block (0 = not loaded) */
    ScoreContextExtra *extraCtx; /* +0x08  extra context (NULL when inactive) */
} ScoreContextData;

/* Top-level Xtra score context handle (param_1 to most ordinals) */
typedef struct XtraScoreCtx {
    char              _pad00[0x0C];
    int               castData;          /* +0x0C  cast subsystem reference */
    int              *castHostCtx;       /* +0x10  cast host context */
    char              _pad14[0x0C];
    ScoreContextData *data;              /* +0x20  internal movie/score pair */
    char              _pad24[0x4C];
    int               resetFieldA;       /* +0x70  cleared during property reset */
    int               resetFieldB;       /* +0x74  cleared during property reset */
} XtraScoreCtx;

/* ================================================================
 * MovieData — top-level runtime state for a loaded movie
 * (from dirapi_backup/src/include/drmovie_internal.h)
 * ================================================================ */

typedef struct MovieData {
    unsigned int flags;         /* +0x00  bit 0x08=loaded, 0x04=playing, 0x20=looping */
    char _pad04[0x18];          /* +0x04 - +0x1B */
    int  context;               /* +0x1C  movie context handle */
    int *scoreData;             /* +0x20  -> MovieScoreData */
    int  callbackParam;         /* +0x24  callback parameter */
    int *frameDataPtr;          /* +0x28  frame data block */
    int  channelCount;          /* +0x2C */
    int  channelTypeArray;      /* +0x30  per-channel type byte array */
    int  channelArrayBase;      /* +0x34  per-channel data (400 bytes each) */
    int  markerData;            /* +0x38  marker/label data */
    char _pad3C[0x08];          /* +0x3C - +0x43 */
    unsigned int boundsMinX;    /* +0x44  bounding rect min X */
    unsigned int boundsMinY;    /* +0x48  bounding rect min Y */
    char _pad4C[0x04];          /* +0x4C - +0x4F */
    unsigned int boundsExtent;  /* +0x50  bounding rect extent */
    int  pendingFrame;          /* +0x54  pending seek target frame */
    int  playbackState;         /* +0x58  playback state machine value */
    int  transitionState;       /* +0x5C  transition state */
    int  resourceActive;        /* +0x60  resource-active flag */
    char _pad64[0x04];          /* +0x64 - +0x67 */
    int  transitionParam;       /* +0x68  transition parameter */
    char _pad6C[0x04];          /* +0x6C - +0x6F */
    char stateBlock70[0x08];    /* +0x70  cleared during teardown */
    char _pad78[0x48];          /* +0x78 - +0xBF */
    char _padC0[0x24];          /* +0xC0 - +0xE3 */
    char renderState[0x08];     /* +0xE4  render state bytes */
    unsigned int lastRenderFrame; /* +0xEC  last rendered frame number */
    char _padF0[0x30];          /* +0xF0 - +0x11F */
    int  minFrame;              /* +0x120  first active channel index */
    int  maxFrame;              /* +0x124  last active channel index */
    int  paletteHandle;         /* +0x128  movie palette handle */
    unsigned int cacheState;    /* +0x12C  transition/cache active flag */
    unsigned int sourceRect[4]; /* +0x130  source rect (4 dwords) */
    unsigned int destRect[4];   /* +0x140  dest rect (4 dwords) */
    char _pad150[0x04];         /* +0x150 - +0x153 */
    unsigned short tempoValue;  /* +0x154  current tempo (ticks per frame) */
    char _pad156[0x1A];         /* +0x156 - +0x16F */
    unsigned int animFlags;     /* +0x170  animation state flags */
    char _pad174[0x04];         /* +0x174 - +0x177 */
    unsigned int layoutFlags;   /* +0x178  layout state flags */
    char _pad17C[0x04];         /* +0x17C - +0x17F */
    unsigned int dirtyFlag;     /* +0x180  dirty rect pending flag */
} MovieData;

/* ================================================================
 * MovieScoreData — persistent movie property block
 * Lives at MovieData::scoreData (offset +0x20 in MovieData)
 * (from dirapi_backup/src/include/drmovie_internal.h)
 * ================================================================ */

typedef struct MovieScoreData {
    char _pad00[0x08];
    int  hostHandle;            /* +0x08  cast system handle */
    char _pad0C[0x14];          /* +0x0C - +0x1F */
    char searchMonitorFlags;    /* +0x20  search monitor flags */
    char _pad21[0x07];          /* +0x21 - +0x27 */
    char propertiesBase[0x418]; /* +0x28  kMoviePropertyCount dwords */
    char _pad440[0x04];         /* +0x440 - +0x443 */
    unsigned int loadedFlag;    /* +0x444 */
    char _pad448[0x10];         /* +0x448 - +0x457 */
    unsigned int dirtyFlag;     /* +0x458 */
    char _pad45C[0x10];         /* +0x45C - +0x46B */
    unsigned int castDataHandle; /* +0x46C */
    char _pad470[0x1C];         /* +0x470 - +0x48B */
    char scoreVersionBase[0x04]; /* +0x48C */
    short stageLeft;            /* +0x490 */
    short stageTop;             /* +0x492 */
    short stageRight;           /* +0x494 */
    short stageBottom;          /* +0x496 */
    char _pad498[0x20];         /* +0x498 - +0x4B7 */
    unsigned int extPropB8;     /* +0x4B8 */
    unsigned int extPropBC;     /* +0x4BC */
    char _pad4C0[0x1B0];       /* +0x4C0 - +0x66F */
    unsigned int loopMode;      /* +0x670 */
    char _pad674[0x04];         /* +0x674 - +0x677 */
    unsigned int soundProperty; /* +0x678 */
} MovieScoreData;

/* ================================================================
 * CastMemberInfo — per-member runtime record returned by castLookup()
 * (from dirapi_backup/src/xtra/xtra_score_layout.h)
 * ================================================================ */

typedef struct CastMemberInfo {
    int  _pad00;                /* +0x00 */
    int  id;                    /* +0x04  CM_ID */
    int  type;                  /* +0x08  CM_TYPE */
    int  castLib;               /* +0x0C  CM_CAST_LIB */
    int  timestamp;             /* +0x10  CM_TIMESTAMP */
    char _pad14[0x14];          /* +0x14 - +0x27 */
    int  scriptRef;             /* +0x28  CM_SCRIPT_REF */
    int  flags;                 /* +0x2C  CM_FLAGS */
    char _pad30[0x08];          /* +0x30 - +0x37 */
    int  purgeFlags;            /* +0x38  CM_PURGE_FLAGS */
    int  comment;               /* +0x3C  CM_COMMENT */
    int  longComment;           /* +0x40  CM_LONG_COMMENT */
    int  userData;              /* +0x44  CM_USER_DATA */
    char _pad48[0x04];          /* +0x48 - +0x4B */
    int  mediaHandle;           /* +0x4C  CM_MEDIA_HANDLE */
    char _pad50[0x0C];          /* +0x50 - +0x5B */
    int  xtraData;              /* +0x5C  CM_XTRA_DATA */
} CastMemberInfo;

/* RIFX File Object (0xB4 bytes, created by Ordinal_10)
 * Discovered from crt_riff_chunk_core.c: Ordinal_10, Ordinal_11, Ordinal_13,
 * FUN_680030e0 (lock), FUN_68003110 (unlock), FUN_68003160 (initSlots) */
struct RifxFile {
    void *fileReference;       /* +0x00  FourCC / file type identifier */
    void *streamHandle;        /* +0x04  I/O stream handle */
    int errorStatus;           /* +0x08  last error code */
    char _pad_0c[0x04];       /* +0x0C */
    int field_0x10;            /* +0x10  dirty/modified flag */
    int field_0x14;            /* +0x14  needs-flush flag */
    char _pad_18[0x04];       /* +0x18 */
    void *mmapHandle;          /* +0x1C  memory map handle (lock/unlock target) */
    void *mmapData;            /* +0x20  locked pointer to mmap data */
    int slotCapacity;          /* +0x24  allocated slot count */
    int lockCount;             /* +0x28  lock reference count */
    void *callerContext;       /* +0x2C  parent/caller context pointer */
    char _pad_30[0x18];       /* +0x30 - +0x47 */
    int totalFileSize;         /* +0x48  total RIFX container size */
    char _pad_4c[0x08];       /* +0x4C - +0x53 */
    int field_0x54;            /* +0x54 */
    int field_0x58;            /* +0x58 */
    char _pad_5c[0x18];       /* +0x5C - +0x73 */
    int field_0x74;            /* +0x74 */
    char _pad_78[0x3C];       /* +0x78 - +0xB3 */
};

/* ================================================================
 * FourCC (Four-Character Code) constants
 *
 * Director file format uses FourCC codes to identify chunk types,
 * container formats, and media types.  These were raw hex literals
 * in the Ghidra output (e.g., 0x52494658).
 * ================================================================ */

#define FOURCC(a, b, c, d) \
    ((unsigned int)(a) << 24 | (unsigned int)(b) << 16 | (unsigned int)(c) << 8 | (unsigned int)(d))

/* Container types */
#define FOURCC_RIFX   FOURCC('R','I','F','X')   /* 0x52494658  Big-endian Director file */
#define FOURCC_RIFF   FOURCC('R','I','F','F')   /* 0x52494646  Little-endian (RIFF) */
#define FOURCC_MV93   FOURCC('M','V','9','3')   /* 0x4D563933  Movie Version 93 */
#define FOURCC_MV12   FOURCC('M','V','1','2')   /* 0x4D563132  Movie Version 12 */
#define FOURCC_FGDM   FOURCC('F','G','D','M')   /* 0x4647444D  Director movie (alt) */
#define FOURCC_FGDC   FOURCC('F','G','D','C')   /* 0x46474443  Director cast lib (alt) */
#define FOURCC_FGEI   FOURCC('F','G','E','I')   /* 0x46474549  Director EI container */
#define FOURCC_DC12   FOURCC('D','C','1','2')   /* 0x44433132  DC12 container */
#define FOURCC_MD08   FOURCC('M','D','0','8')   /* 0x4D443038  MD08 container */

/* Structural chunks */
#define FOURCC_imap   FOURCC('i','m','a','p')   /* 0x696D6170  Initial memory map */
#define FOURCC_mmap   FOURCC('m','m','a','p')   /* 0x6D6D6170  Memory map (chunk index) */
#define FOURCC_junk   FOURCC('j','u','n','k')   /* 0x6A756E6B  Padding/junk */
#define FOURCC_free   FOURCC('f','r','e','e')   /* 0x66726565  Free/deleted chunk */
#define FOURCC_KEYx   FOURCC('K','E','Y','*')   /* 0x4B45592A  Key table */
#define FOURCC_CASx   FOURCC('C','A','S','*')   /* 0x4341532A  Cast data */
#define FOURCC_CASt   FOURCC('C','A','S','t')   /* 0x43415374  Cast member data */
#define FOURCC_MCsL   FOURCC('M','C','s','L')   /* 0x4D43734C  Movie cast list */

/* Score and channel data */
#define FOURCC_SCVW   FOURCC('S','C','V','W')   /* 0x53435657  Score data (new) */
#define FOURCC_SCVX   FOURCC('S','C','V','X')   /* 0x53435658  Score data extended */
#define FOURCC_VWSC   FOURCC('V','W','S','C')   /* 0x56575343  Score data (legacy) */
#define FOURCC_VWSD   FOURCC('V','W','S','D')   /* 0x56575344  Score data (legacy D) */
#define FOURCC_VWCF   FOURCC('V','W','C','F')   /* 0x56574346  Config (legacy) */
#define FOURCC_DRCF   FOURCC('D','R','C','F')   /* 0x44524346  Director config */
#define FOURCC_VWFI   FOURCC('V','W','F','I')   /* 0x56574649  File info (legacy) */
#define FOURCC_VWFJ   FOURCC('V','W','F','J')   /* 0x5657464A  File info J (legacy) */
#define FOURCC_VWLB   FOURCC('V','W','L','B')   /* 0x56574C42  Label table (legacy) */
#define FOURCC_VWTC   FOURCC('V','W','T','C')   /* 0x56575443  Timecode (legacy) */
#define FOURCC_VWtc   FOURCC('V','W','t','c')   /* 0x56577463  Timecode (new) */
#define FOURCC_VWTL   FOURCC('V','W','T','L')   /* 0x5657544C  Tile table (legacy) */
#define FOURCC_Chan   FOURCC('C','h','a','n')   /* 0x4368616E  Channel data */
#define FOURCC_Chao   FOURCC('C','h','a','o')   /* 0x4368616F  Channel offset */

/* Lingo scripting */
#define FOURCC_Lnam   FOURCC('L','n','a','m')   /* 0x4C6E616D  Lingo name table */
#define FOURCC_Lscr   FOURCC('L','s','c','r')   /* 0x4C736372  Lingo script data */
#define FOURCC_LctX   FOURCC('L','c','t','X')   /* 0x4C637458  Lingo context (new) */
#define FOURCC_Lctx   FOURCC('L','c','t','x')   /* 0x4C637478  Lingo context (legacy) */

/* Bitmap/image data */
#define FOURCC_BITD   FOURCC('B','I','T','D')   /* 0x42495444  Bitmap data */
#define FOURCC_BITF   FOURCC('B','I','T','F')   /* 0x42495446  Bitmap footer */
#define FOURCC_PICT   FOURCC('P','I','C','T')   /* 0x50494354  PICT image */
#define FOURCC_PICH   FOURCC('P','I','C','H')   /* 0x50494348  PICT header */
#define FOURCC_ABMP   FOURCC('A','B','M','P')   /* 0x41424D50  Alpha bitmap */
#define FOURCC_ALFA   FOURCC('A','L','F','A')   /* 0x414C4641  Alpha channel */
#define FOURCC_CLUT   FOURCC('C','L','U','T')   /* 0x434C5554  Color lookup table */
#define FOURCC_OLED   FOURCC('O','L','E','D')   /* 0x4F4C4544  OLE data */
#define FOURCC_PCK2   FOURCC('P','C','K','2')   /* 0x50434B32  Packed data v2 */
#define FOURCC_Thum   FOURCC('T','h','u','m')   /* 0x5468756D  Thumbnail */

/* Sound data */
#define FOURCC_snd    FOURCC('s','n','d',' ')   /* 0x736E6420  Sound data */
#define FOURCC_sndE   FOURCC('s','n','d','!')   /* 0x736E6421  Sound data (alt) */
#define FOURCC_sndH   FOURCC('s','n','d','H')   /* 0x736E6448  Sound header */
#define FOURCC_sndS   FOURCC('s','n','d','S')   /* 0x736E6453  Sound samples */
#define FOURCC_raw    FOURCC('r','a','w',' ')   /* 0x72617720  Raw audio */
#define FOURCC_cupt   FOURCC('c','u','p','t')   /* 0x63757074  Cue point */

/* Text data */
#define FOURCC_STXT   FOURCC('S','T','X','T')   /* 0x53545854  Styled text */

/* Media and Xtra */
#define FOURCC_ediM   FOURCC('e','d','i','M')   /* 0x6564694D  Media editor data */
#define FOURCC_XMED   FOURCC('X','M','E','D')   /* 0x584D4544  Xtra media data */
#define FOURCC_XTRl   FOURCC('X','T','R','l')   /* 0x5854526C  Xtra list */
#define FOURCC_FXmp   FOURCC('F','X','m','p')   /* 0x46586D70  Font map */
#define FOURCC_Fmap   FOURCC('F','m','a','p')   /* 0x466D6170  Font map (alt) */
#define FOURCC_Cinf   FOURCC('C','i','n','f')   /* 0x43696E66  Cast info */
#define FOURCC_Fcdr   FOURCC('F','c','d','r')   /* 0x46636472  Cast directory */
#define FOURCC_Fver   FOURCC('F','v','e','r')   /* 0x46766572  File version */
#define FOURCC_Gmap   FOURCC('G','m','a','p')   /* 0x476D6170  Global map */
#define FOURCC_Sord   FOURCC('S','o','r','d')   /* 0x536F7264  Sort order */

/* Runtime/format */
#define FOURCC_RTE0   FOURCC('R','T','E','0')   /* 0x52544530  Runtime entry 0 */
#define FOURCC_RTE1   FOURCC('R','T','E','1')   /* 0x52544531  Runtime entry 1 */
#define FOURCC_RTE2   FOURCC('R','T','E','2')   /* 0x52544532  Runtime entry 2 */
#define FOURCC_ccl    FOURCC('c','c','l',' ')   /* 0x63636C20  Cast config list */

/* Security / signing */
#define FOURCC_SIGN   FOURCC('S','I','G','N')   /* 0x5349474E  Digital signature */
#define FOURCC_CERT   FOURCC('C','E','R','T')   /* 0x43455254  Certificate */
#define FOURCC_FLST   FOURCC('F','L','S','T')   /* 0x464C5354  File list */
#define FOURCC_INFO   FOURCC('I','N','F','O')   /* 0x494E464F  Info chunk */
#define FOURCC_FILE   FOURCC('F','I','L','E')   /* 0x46494C45  File reference */

/* Misc */
#define FOURCC_mmud   FOURCC('m','m','u','d')   /* 0x6D6D7564  Undo data */
#define FOURCC_ptth   FOURCC('p','t','t','h')   /* 0x70747468  HTTP (reversed) */
#define FOURCC_ralf   FOURCC('r','a','l','f')   /* 0x72616C66  Hash magic */

/* ================================================================
 * Lingo Object Type IDs
 *
 * Used both as type identifiers and as property accessor IDs.
 * Registered by cast_registerMovieTypes (FUN_6802cf20) and
 * cast_registerPlayerScope (FUN_6802d2c0) via events_registerProperty.
 *
 * Source: cast_scope_register.c — direct string evidence in code.
 * ================================================================ */

#define LTYPE_SPRITE    0x2E    ///< Lingo: "sprite"  — sprite object type
#define LTYPE_SOUND     0x54    ///< Lingo: "sound"   — sound channel type
#define LTYPE_MEMBER    0x58    ///< Lingo: "member"  — cast member type
#define LTYPE_CASTLIB   0x68    ///< Lingo: "castLib" — cast library type
#define LTYPE_SCRIPT    0x7B    ///< Lingo: "script"  — script object type
#define LTYPE_WINDOW    0x7C    ///< Lingo: "window"  — window (MIAW) type
#define LTYPE_XTRA      0x7D    ///< Lingo: "xtra"    — Xtra plugin type
#define LTYPE_CHANNEL   0x5FD   ///< Lingo: "channel" — score channel type

/* ================================================================
 * Cast Member Property IDs (CPROP_)
 *
 * Used by Ordinal_293 (set) and Ordinal_294 (get) for cast member
 * property dispatch.  These are the property indices passed as
 * the propertyId parameter to the large switch statements.
 *
 * Source: dirapi_backup/src/xtra/xtra_channel.cpp (verified names)
 * Cross-ref: analysis/ghidra/lingo_symbol_table.h sections 11-12
 * ================================================================ */

#define CPROP_TYPE              0x00    ///< Lingo: "type" — cast member type (read-only)
#define CPROP_NAME              0x01    ///< Lingo: "name" — cast member name
#define CPROP_MEDIA_TYPE        0x02    ///< Lingo: "castType" — media type code
#define CPROP_EMPTY             0x03    ///< Lingo: (empty check) — is empty (read-only)
#define CPROP_MODIFIED          0x04    ///< Lingo: "modified" — modified timestamp
#define CPROP_HAS_DATA          0x06    ///< Lingo: "loaded" — has media data loaded
#define CPROP_LINKED_FLAG       0x07    ///< Lingo: "linked" — is linked to external file (read-only)
#define CPROP_FILENAME          0x08    ///< Lingo: "fileName" — linked file name
#define CPROP_LOOP              0x09    ///< Lingo: "loop"/"hilite" — loop/repeat (bitmap: hilite toggle)
#define CPROP_SCRIPT            0x0A    ///< Lingo: "scriptText" — script presence flags
#define CPROP_PURGEABLE         0x0B    ///< Lingo: "purgePriority" — purgeable priority
#define CPROP_VERSION           0x0C    ///< Lingo: "version" — cast library version (read-only)
#define CPROP_COMMENT           0x0D    ///< Lingo: "comment" — user comment field
#define CPROP_LONG_COMMENT      0x0E    ///< Lingo: "comments" — extended comment (read-only)
#define CPROP_PALETTE           0x10    ///< Lingo: "palette"/"paletteRef" — palette reference
#define CPROP_EXT_INFO          0x11    ///< (internal) extended info A (read-only)
#define CPROP_EXT_INFO2         0x12    ///< (internal) extended info B / cast lib index (set)
#define CPROP_SCRIPT_TEXT       0x13    ///< Lingo: "scriptText" — script text content
#define CPROP_MEDIA_FORMAT      0x14    ///< Lingo: "mediaFormat" — media format code (read-only)
#define CPROP_CAST_LIB          0x15    ///< Lingo: "castLib"/"castLibNum" — cast library number (read-only)
#define CPROP_PROPERTY_STORE    0x16    ///< (internal) property store lookup
#define CPROP_USER_DATA         0x17    ///< Lingo: "userData" — user data field
#define CPROP_PRELOAD           0x19    ///< Lingo: "preloadMode" — preload state
#define CPROP_PRELOAD2          0x1A    ///< Lingo: "preloadMode" — extended preload state (read-only)
#define CPROP_MEDIA_SIZE_A      0x1B    ///< Lingo: "width" — media size dimension A (read-only)
#define CPROP_MEDIA_SIZE_B      0x1C    ///< Lingo: "height" — media size dimension B (read-only)
#define CPROP_MEDIA_DIM_H       0x1D    ///< Lingo: "width" — media dimension H
#define CPROP_MEDIA_DIM_V       0x1E    ///< Lingo: "height" — media dimension V
#define CPROP_COMPRESSION       0x21    ///< Lingo: "imageCompression" — compression type
#define CPROP_PURGEABLE_STATE   0x22    ///< Lingo: "purgePriority" — purgeable state toggle
#define CPROP_ANTI_ALIAS        0x23    ///< Lingo: "antialias" — anti-alias setting
#define CPROP_REG_POINT_X       0x24    ///< Lingo: "regPoint".locH — registration point X
#define CPROP_REG_POINT_Y       0x25    ///< Lingo: "regPoint".locV — registration point Y
#define CPROP_BOUNDS_LEFT       0x26    ///< Lingo: "rect".left — bounding rect left
#define CPROP_BOUNDS_TOP        0x27    ///< Lingo: "rect".top — bounding rect top
#define CPROP_HILITE            0x28    ///< Lingo: "hilite" — hilite flag
#define CPROP_AUTO_TAB          0x29    ///< Lingo: "autoTab" — auto-tab flag
#define CPROP_EDITABLE          0x2A    ///< Lingo: "editable" — editable flag
#define CPROP_FONT_MAP          0x2B    ///< Lingo: "fontMap" — font mapping property
#define CPROP_ALIGNMENT         0x2C    ///< Lingo: "alignment" — text alignment
#define CPROP_LINE_SPACING      0x2D    ///< Lingo: "lineHeight" — line spacing
#define CPROP_SKIP_TYPE         0x34    ///< Lingo: "scriptType" — skip/type code (read-only for set)
#define CPROP_NO_OP_A           0x3F    ///< (no-op property, not exposed to Lingo)
#define CPROP_SCORE_INDEX       0x7A    ///< Lingo: "scoreSelection" — score channel index (read-only)
#define CPROP_NO_OP_B           0x7D    ///< (no-op property, not exposed to Lingo)

/* ================================================================
 * Movie Property IDs (MPROP_)
 *
 * Used by Ordinal_360 (get) and Ordinal_361 (set) for movie-level
 * property dispatch.  These are sequential indices, not hashed.
 *
 * Source: dirapi_backup/src/xtra/xtra_internal.h (verified names)
 * ================================================================ */

#define MPROP_CAST_LIB_NAME     0x01    ///< Lingo: "name" — cast library name
#define MPROP_DIMENSION_A       0x02    ///< Lingo: "width" — cast lib dimension A
#define MPROP_CAST_DATA_199     0x03    ///< (internal) cast data field
#define MPROP_DIMENSION_B       0x04    ///< Lingo: "height" — cast lib dimension B
#define MPROP_LIBRARY_VERSION   0x05    ///< Lingo: "version" — cast library version
#define MPROP_CHANNEL_VERSION   0x06    ///< (internal) channel version
#define MPROP_CAST_DATA_2E6     0x07    ///< (internal) cast data field
#define MPROP_SCORE_CHANNEL_MAX 0x08    ///< Lingo: "lastChannel" — max score channel
#define MPROP_TYPE_BYTE         0x09    ///< Lingo: "castType" — type byte
#define MPROP_EXT_FLAG_A        0x0A    ///< (internal) extended flag A
#define MPROP_EXT_FLAG_B        0x0B    ///< (internal) extended flag B
#define MPROP_RESERVED_C        0x0C    ///< (reserved)
#define MPROP_DISPLAY_CAPABILITY 0x0D   ///< (internal) display capability
#define MPROP_CAST_DATA_116     0x0E    ///< (internal) cast data field
#define MPROP_LOAD_RESOURCE     0x0F    ///< Lingo: "preloadMode" — load resource
#define MPROP_MEDIA_CONVERSION  0x10    ///< Lingo: "mediaFormat" — media conversion
#define MPROP_FRAME_COUNT       0x11    ///< Lingo: "frameCount" — number of frames
#define MPROP_CAST_DATA_19B     0x12    ///< (internal) cast data field
#define MPROP_GOTO_FRAME_FIRST  0x13    ///< Lingo: "startFrame" — goto frame first
#define MPROP_GOTO_FRAME_SECOND 0x14    ///< Lingo: "endFrame" — goto frame second
#define MPROP_CAST_DATA_197     0x15    ///< (internal) cast data field
#define MPROP_CAST_DATA_196     0x16    ///< (internal) cast data field
#define MPROP_CAST_DATA_198     0x17    ///< (internal) cast data field
#define MPROP_MOVIE_STATUS_FLAGS 0x18   ///< Lingo: "loaded" — movie status flags
#define MPROP_EXT_COMPAT        0x19    ///< (internal) compatibility flag
#define MPROP_MEMBER_FLAG_BIT0  0x1A    ///< (internal) member flag bit 0
#define MPROP_PROPERTY_STORE    0x1B    ///< (internal) property store
#define MPROP_RESOLVE_CAST_REF  0x1C    ///< (internal) resolve cast reference
#define MPROP_CAST_SLOT_COUNT   0x1D    ///< Lingo: "memberCount" — cast slot count
#define MPROP_CAST_DATA_1A1     0x1E    ///< (internal) cast data field
#define MPROP_EXT_QUALITY       0x20    ///< Lingo: "imageQuality" — extended quality
#define MPROP_EXT_RATE          0x21    ///< Lingo: "imageCompression" — extended rate
#define MPROP_CAST_DATA_1A2     0x22    ///< (internal) cast data field
#define MPROP_CAST_DATA_1A3     0x23    ///< (internal) cast data field
#define MPROP_PALETTE_MODE      0x24    ///< Lingo: "defaultPalette" — palette mode
#define MPROP_ACTIVE_PALETTE    0x25    ///< Lingo: "palette" — active palette
#define MPROP_XTRA_INFO_STRINGS 0x26    ///< Lingo: "xtraList" — Xtra info strings
#define MPROP_STREAM_GUID_CHECK 0x27    ///< (internal) stream format GUID check
#define MPROP_LINKED_FILE_DATA  0x28    ///< Lingo: "fileName" — linked file data
#define MPROP_STRING_PROP_A     0x29    ///< Lingo: "copyrightInfo" — string property A
#define MPROP_STRING_PROP_B     0x2A    ///< Lingo: "aboutInfo" — string property B
#define MPROP_SOUND_FORMAT      0x2B    ///< Lingo: "sampleRate"/"sampleSize" — sound format
#define MPROP_CAST_DATA_139     0x2C    ///< (internal) cast data field
#define MPROP_CAST_DATA_13A     0x2D    ///< (internal) cast data field
#define MPROP_ENCODING_TYPE     0x2E    ///< Lingo: "characterSet" — encoding type
#define MPROP_CAST_DATA_13B     0x2F    ///< (internal) cast data field
#define MPROP_BITMASK_PROP      0x30    ///< (internal) bitmask property
#define MPROP_DISPLAY_MODE      0x31    ///< Lingo: "displayMode" — display mode
#define MPROP_CHANNEL_COUNT     0x32    ///< Lingo: "channelCount" — number of channels
#define MPROP_FILE_ENUM_BOUNDS  0x33    ///< (internal) file enum bounds
#define MPROP_FILE_ENUM_LIST    0x34    ///< Lingo: "castMemberList" — file enum list
#define MPROP_TEMPO_DOUBLE      0x35    ///< Lingo: "tempoScaleFactor" — tempo (double)
#define MPROP_TEMPO_FLOAT       0x37    ///< Lingo: "frameRate" — tempo (float)

/* ================================================================
 * Sprite Channel Property Indices
 *
 * Field indices used by Ordinal_374 (get) and Ordinal_375 (set)
 * for sprite channel data in the score.
 *
 * Source: dirapi_backup/src/xtra/xtra_sprite_props.cpp (verified)
 * ================================================================ */

#define SPROP_SCRIPT_NUM        1       ///< Lingo: "scriptNum" — attached script number
#define SPROP_CAST_NUM          2       ///< Lingo: "castNum" — cast member number (resolved)
#define SPROP_CAST_REF_RAW      3       ///< Lingo: "castNum" — raw cast reference (hi/lo words)
#define SPROP_TYPE_BYTE         4       ///< Lingo: "type" — sprite channel type byte
#define SPROP_POSITION          5       ///< Lingo: "locH"/"locV" — position (packed)
#define SPROP_INK               6       ///< Lingo: "ink" — ink effect
#define SPROP_CAST_RESOLVED     7       ///< Lingo: "castNum" — resolved cast member (alt path)
#define SPROP_BACK_COLOR        8       ///< Lingo: "backColor" — background color
#define SPROP_FORE_COLOR        9       ///< Lingo: "foreColor" — foreground color
#define SPROP_FLAGS             0x0B    ///< channel flags
#define SPROP_LINE_SIZE         0x0E    ///< Lingo: "lineSize" — line width
#define SPROP_BLEND             0x16    ///< Lingo: "blend" — blend amount (0-255)

/* ================================================================
 * Cast Dispatch Operation Codes
 *
 * Operation codes passed to castDispatchProperty() for cast member
 * property get/set/clear/refresh operations.
 *
 * Source: dirapi_backup/src/xtra/xtra_channel.cpp
 * ================================================================ */

#define DISPATCH_OP_REFRESH     0x05    ///< Refresh/reload via dispatch
#define DISPATCH_OP_CLEAR       0x0E    ///< Clear/reset via dispatch
#define DISPATCH_OP_EVENT       0x14    ///< Event dispatch
#define DISPATCH_OP_QUERY       0x15    ///< Query property via dispatch
#define DISPATCH_OP_GET         0x19    ///< Get property via dispatch
#define DISPATCH_OP_SET         0x1A    ///< Set property via dispatch
#define DISPATCH_OP_SWAP        0x1D    ///< Swap data between members

/* ================================================================
 * Cast Member Type Codes
 *
 * Used to identify the type of a cast member.  Appear in type
 * dispatch switches like display_cast_member_types.c and
 * display_cast_member_media.c.
 * ================================================================ */

#define CMTYPE_BITMAP       0x01    ///< bitmap image member
#define CMTYPE_FILM_LOOP    0x02    ///< film loop member
#define CMTYPE_TEXT_FIELD   0x03    ///< text field member (old-style)
#define CMTYPE_PALETTE      0x04    ///< palette member
#define CMTYPE_PICTURE      0x05    ///< picture (PICT) member
#define CMTYPE_SOUND        0x06    ///< sound member
#define CMTYPE_BUTTON       0x07    ///< button member
#define CMTYPE_SHAPE        0x08    ///< shape member
#define CMTYPE_MOVIE        0x09    ///< movie member
#define CMTYPE_DIGITAL_VIDEO 0x0A   ///< digital video member
#define CMTYPE_SCRIPT       0x0B    ///< script member
#define CMTYPE_TEXT_RICH    0x0C    ///< rich text member
#define CMTYPE_OLE          0x0E    ///< OLE object member
#define CMTYPE_TRANSITION   0x0F    ///< transition member
#define CMTYPE_XTRA         0x10    ///< Xtra member
#define CMTYPE_SWA          0x11    ///< Shockwave Audio member
#define CMTYPE_VECTOR       0x12    ///< vector shape member
#define CMTYPE_FLASH        0x13    ///< Flash member
#define CMTYPE_SHOCKWAVE3D  0x14    ///< Shockwave 3D member
#define CMTYPE_DVD          0x15    ///< DVD member
#define CMTYPE_CURSOR       0x16    ///< custom cursor member
#define CMTYPE_WINDOWS_MEDIA 0x17   ///< Windows Media member

#endif /* DIRAPI_TYPES_H */
