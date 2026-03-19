/*
 * run_lingo.c
 *
 * Minimal example: load dirapi.dll, initialize a player, open a
 * Director movie, and execute Lingo scripts passed as arguments.
 *
 * Compile (x86 Native Tools Command Prompt for VS 2022):
 *   cl /nologo /W3 run_lingo.c user32.lib gdi32.lib
 *
 * Usage (with iml32.dll + dirapi.dll in the working directory):
 *   run_lingo.exe shockwave_Projector_Loader.dcr "put 1 + 2 + 3"
 *   run_lingo.exe movie.dir "put the number of castMembers"
 */

#include <windows.h>
#include <stdio.h>
#include <string.h>

/*
 * The original dirapi.dll and iml32.dll use __stdcall for exports.
 * Confirmed by ret N epilogues in the binaries.
 */
#define DRCALL __stdcall

/* dirapi ordinals */
typedef unsigned int (DRCALL *pfnInitPlayer)(unsigned int *, int, unsigned int *);
typedef int  (DRCALL *pfnDisposePlayer)(int);
typedef int  (DRCALL *pfnOpenFile)(int *, int *, int, unsigned int *,
             unsigned char *, short, int, void *);
typedef int  (DRCALL *pfnCloseMovie)(void);
typedef unsigned int (DRCALL *pfnEvalScript)(int, unsigned int *,
             unsigned char *, short);
typedef unsigned int (DRCALL *pfnGetAppInstance)(void);

/* iml32 ordinals (for MOA init) */
typedef int (DRCALL *pfnMoaInit)(int, int, int *, int);     /* @1010 */
typedef int (DRCALL *pfnMoaEnable1)(int);                    /* @2317 */
typedef int (DRCALL *pfnMoaEnable2)(int);                    /* @2301 */

static FARPROC MustResolve(HMODULE h, int ord, const char *name) {
    FARPROC p = GetProcAddress(h, MAKEINTRESOURCE(ord));
    if (!p) { fprintf(stderr, "Cannot resolve @%d (%s)\n", ord, name); ExitProcess(1); }
    return p;
}

/*
 * Callback[22] (player byte offset 0x74): called unconditionally by
 * FUN_68009c00 during movie open to get the runtime mode string.
 * If NULL → null function pointer crash.
 */
static void __cdecl CbGetAuthor(char *buf, int size)
{
    if (buf && size > 0) buf[0] = '\0';
}

/* VEH crash handler for diagnostics */
static HMODULE g_hIml32, g_hDirapi;
static LONG WINAPI CrashHandler(EXCEPTION_POINTERS *ep)
{
    if (ep->ExceptionRecord->ExceptionCode == 0xC0000005) {
        printf("\n!!! ACCESS VIOLATION at 0x%08X, %s 0x%08X !!!\n",
               (unsigned)ep->ExceptionRecord->ExceptionAddress,
               ep->ExceptionRecord->ExceptionInformation[0] ? "writing" : "reading",
               (unsigned)ep->ExceptionRecord->ExceptionInformation[1]);
        fflush(stdout);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: run_lingo <movie.dir> <lingo> [lingo] ...\n");
        return 1;
    }

    AddVectoredExceptionHandler(1, CrashHandler);

    /* 1. Load DLLs */
    g_hIml32  = LoadLibraryA("iml32.dll");
    g_hDirapi = LoadLibraryA("dirapi.dll");
    if (!g_hIml32 || !g_hDirapi) {
        fprintf(stderr, "Failed to load DLLs.\n");
        return 1;
    }

    /*
     * 2. Initialize iml32.dll's MOA framework.
     *
     * Reverse-engineered from Proj.dll (Director Projector host, RVA 0x3620):
     *   Ordinal_1010(0, 8, &{0, -1}, hInstance)  — create MOA context
     *   Ordinal_2317(1)                           — enable subsystem
     *   Ordinal_2301(1)                           — enable subsystem
     *
     * Without this, iml32's allocator has no context and crashes at NULL+0x20.
     */
    {
        pfnMoaInit   fn1010 = (pfnMoaInit)  GetProcAddress(g_hIml32, MAKEINTRESOURCE(1010));
        pfnMoaEnable1 fn2317 = (pfnMoaEnable1)GetProcAddress(g_hIml32, MAKEINTRESOURCE(2317));
        pfnMoaEnable2 fn2301 = (pfnMoaEnable2)GetProcAddress(g_hIml32, MAKEINTRESOURCE(2301));

        if (!fn1010) {
            fprintf(stderr, "Cannot resolve iml32 @1010\n");
            return 1;
        }

        /*
         * Ordinal_1010 signature (ret 16 = 4 params, __stdcall):
         *   int @1010(HMODULE hExe, int initType, int *initStruct, void *callbackTable)
         *
         * From Proj.dll (RVA 0x3620 → 0x4129):
         *   arg1 = GetModuleHandle(NULL)
         *   arg2 = 8
         *   arg3 = &{0, 0xFFFFFFFF}
         *   arg4 = 32-entry callback function pointer table (128 bytes)
         *          @1010 does rep movsd to copy all 32 entries internally,
         *          then calls through them for allocations etc.
         */
        int initStruct[2] = {0, (int)0xFFFFFFFF};
        HINSTANCE hInst = GetModuleHandleA(NULL);

        /* Callback table: 32 function pointers. Most can be NULL (checked
           before calling). Provide stubs for the ones called unconditionally. */
        static unsigned int moaCallbacks[32];
        memset(moaCallbacks, 0, sizeof(moaCallbacks));

        printf("Initializing MOA framework...\n"); fflush(stdout);
        int r = fn1010((int)hInst, 8, initStruct, (int)moaCallbacks);
        printf("  @1010 = %d\n", r); fflush(stdout);
        if (r && fn2317) fn2317(1);
        if (r && fn2301) fn2301(1);

        if (!r) {
            fprintf(stderr, "MOA init failed.\n");
            return 1;
        }
        printf("  MOA initialized.\n"); fflush(stdout);
    }

    /* 3. Resolve dirapi ordinals */
    pfnInitPlayer    InitPlayer = (pfnInitPlayer)   MustResolve(g_hDirapi, 80,  "InitPlayer");
    pfnDisposePlayer Dispose    = (pfnDisposePlayer)MustResolve(g_hDirapi, 81,  "Dispose");
    pfnOpenFile      OpenFile   = (pfnOpenFile)     MustResolve(g_hDirapi, 88,  "OpenFile");
    pfnCloseMovie    Close      = (pfnCloseMovie)   MustResolve(g_hDirapi, 83,  "CloseMovie");
    pfnEvalScript    Eval       = (pfnEvalScript)   MustResolve(g_hDirapi, 90,  "EvalScript");
    pfnGetAppInstance GetApp    = (pfnGetAppInstance)MustResolve(g_hDirapi, 109, "GetAppInstance");

    printf("dirapi.dll loaded (GetApp=0x%08X)\n", GetApp());
    fflush(stdout);

    /* 4. Init player */
    unsigned int player[0x1c8 / 4];
    unsigned int callbacks[0x6a];
    memset(player, 0, sizeof(player));
    memset(callbacks, 0, sizeof(callbacks));
    callbacks[22] = (unsigned int)CbGetAuthor;

    /*
     * Host context: player[2] gets dereferenced as a pointer at offset +0x10
     * by Ordinal_120. We provide a minimal struct with a zeroed resolver.
     */
    /*
     * Host context: player[2] is dereferenced at offset +0x10 to get a
     * "resolver" object pointer. The resolver is used by Ordinal_120 for
     * script evaluation and error formatting. Ordinal_120 reads resolver[0]
     * and resolver[0x84]. iml32's allocator validates resolver objects have
     * magic word 0xBEAD at offset +0x20.
     *
     * We pass NULL error params to OpenFile to skip the Ordinal_120 path
     * during movie open. But EvalScript always hits it.
     */
    static unsigned int hostCtx[32];
    static unsigned int resolver[0x100];
    memset(hostCtx, 0, sizeof(hostCtx));
    memset(resolver, 0, sizeof(resolver));
    hostCtx[4] = (unsigned int)resolver;  /* offset 0x10 = resolver ptr */
    /* Set magic at resolver byte offset 0x20 for iml32 validation */
    ((unsigned short *)resolver)[0x20 / 2] = 0xBEAD;

    printf("Calling InitPlayer...\n"); fflush(stdout);
    unsigned int initRc = InitPlayer(player, (int)hostCtx, callbacks);
    printf("InitPlayer = 0x%X\n", initRc); fflush(stdout);

    /* Dump score structure */
    if (initRc && player[5]) {
        unsigned int *score = (unsigned int *)player[5];
        printf("  Score dump (player[5]=0x%08X):\n", player[5]);
        for (int j = 0; j < 0x90/4; j += 4) {
            printf("    +0x%02X: %08X %08X %08X %08X\n",
                   j*4, score[j], score[j+1], score[j+2], score[j+3]);
        }
        fflush(stdout);
    }

    if (!initRc) {
        printf("InitPlayer failed.\n");
        return 1;
    }

    /*
     * player[3] (byte offset 0xC) = score/movie handle used by all ordinals.
     * player[5] (byte offset 0x14) = score context created by FUN_68096950.
     * Ordinal_88 reads player[3] but InitPlayer only sets player[5].
     * In the full Director runtime, FUN_68009c00 (Ordinal_82) sets player[3].
     * We need to set it before calling Ordinal_88 directly.
     */
    /*
     * Use Ordinal_82 (OpenMovie) instead of Ordinal_88 (OpenFile).
     *
     * Ordinal_88 crashes because FUN_68091eb0 has a dead code path when
     * no movie is loaded (the original DLL never calls it without one).
     *
     * Ordinal_82(player, movieCtx, flags):
     *   - EBX = param1 (player)
     *   - EDI = param2 (movie context) — stored in player[3]
     *   - param3 = flags passed to FUN_68009c00
     *
     * FUN_68009c00 accesses EDI (movieCtx) at:
     *   +0x10 (init flag), +0x40/+0x44 (callbacks), +0x74 (CbGetAuthor),
     *   +0xe0, +0x24, +0x18, etc.
     *
     * The movieCtx is where the host puts its callbacks. Our CbGetAuthor
     * must be at movieCtx offset 0x74 (not in the player's callback table).
     */
    typedef int (DRCALL *pfnOpenMovie)(unsigned int, unsigned int, unsigned int);
    pfnOpenMovie OpenMovie = (pfnOpenMovie)MustResolve(g_hDirapi, 82, "OpenMovie");

    static unsigned int movieCtx[256];
    memset(movieCtx, 0, sizeof(movieCtx));
    movieCtx[0x74 / 4] = (unsigned int)CbGetAuthor;  /* callback at EDI+0x74 */

    const char *path = argv[1];
    printf("Opening: %s\n", path); fflush(stdout);

    int rc = 0;
    __try {
        rc = (int)OpenMovie((unsigned int)player, (unsigned int)movieCtx, 0);
    } __except(
        printf("OpenMovie CRASH: code=0x%08X addr=0x%08X %s 0x%08X (dirapi+0x%08X)\n",
               GetExceptionInformation()->ExceptionRecord->ExceptionCode,
               (unsigned)GetExceptionInformation()->ExceptionRecord->ExceptionAddress,
               GetExceptionInformation()->ExceptionRecord->ExceptionInformation[0] ? "writing" : "reading",
               (unsigned)GetExceptionInformation()->ExceptionRecord->ExceptionInformation[1],
               (unsigned)GetExceptionInformation()->ExceptionRecord->ExceptionAddress - (unsigned)g_hDirapi),
        fflush(stdout),
        EXCEPTION_EXECUTE_HANDLER
    ) {
        printf("OpenMovie crashed.\n"); fflush(stdout);
        Dispose((int)player);
        return 1;
    }
    printf("OpenMovie = %d\n", rc); fflush(stdout);

    if (rc != 0) {
        printf("OpenFile failed.\n");
        Dispose((int)player);
        return 1;
    }

    /* 6. Execute each Lingo argument */
    for (int i = 2; i < argc; i++) {
        const char *script = argv[i];
        unsigned int result = 0;

        printf("\nlingo> %s\n", script); fflush(stdout);
        Eval((int)player, &result, (unsigned char *)script, (short)strlen(script));
        if (result != 0)
            printf("  => 0x%08X\n", result);
    }

    /* 7. Cleanup */
    printf("\nDone.\n");
    Close();
    Dispose((int)player);
    FreeLibrary(g_hDirapi);
    FreeLibrary(g_hIml32);
    return 0;
}
