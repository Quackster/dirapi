# dirapi

Reconstructed source code for **dirapi.dll** — the core runtime engine of [Macromedia/Adobe Director](https://en.wikipedia.org/wiki/Adobe_Director). This project was created by reverse-engineering the original 32-bit Windows DLL using [Ghidra](https://ghidra-sre.org/), then transforming the decompiler output into compilable C source that can be built with Visual Studio.

**Author:** [Quackster](https://github.com/Quackster)

> **Status:** Work in progress — the source compiles but is still undergoing cleanup (replacing raw pointer arithmetic with struct field access, improving readability, etc.)

---

## What is dirapi.dll?

`dirapi.dll` is the **core Director runtime engine** — not a plugin (Xtra), but the central library that powers Director movie playback. It is loaded by the Director projector/player and provides:

- **RIFX/IFF file parser** — reads Director's chunked binary container format (FourCC-based: `RIFX`, `imap`, `mmap`, `CASt`, `Lscr`, etc.)
- **Lingo scripting engine** — Director's proprietary scripting language interpreter and runtime
- **JavaScript engine integration** — bridges to an embedded JS engine for Director MX+
- **Property dispatch system** — numeric ID-based property getter/setter routing via large switch tables
- **Xtra plugin infrastructure** — loads and manages Director Xtras (plugins)
- **Cast member management** — sprite resources, bitmaps, text, shapes, sounds, etc.
- **Score/timeline engine** — frame-based playback, score channel management, tempo control
- **Stage rendering** — window management, sprite compositing, rendering to device contexts
- **Sound playback** — audio channel management, volume, mixing
- **Cryptography/DRM** — content protection and certificate verification

The DLL exports **371 ordinal-based functions** and imports **585 functions** from its companion library `iml32.dll`. Internal function count totals approximately **8,395 functions** across the full binary.

---

## Original Binary

The `bin/` directory contains the original DLLs that this project was decompiled from.

### `dirapi_original.dll`

The original Director runtime DLL, extracted from a Macromedia/Adobe Director installation.

| Property | Value |
|----------|-------|
| **File size** | 1,782,784 bytes (1.70 MB) |
| **PE timestamp** | 2019-03-15 06:37:58 UTC |
| **Architecture** | x86 (32-bit), PE32 |
| **PE Machine** | 0x14C (IMAGE_FILE_MACHINE_I386) |
| **PE Sections** | 5 |
| **Exported ordinals** | 371 |
| **SHA-256** | `e7e2175435fcc851dddf60bb25d254852cfb12b50d541ee8f6fca0b3726de0a9` |
| **MD5** | `59b3ab077dbdc568bfcd9ef7694eff14` |

### `iml32_original.dll`

Companion library that `dirapi.dll` imports from. Provides ~585 utility functions used throughout the runtime (handle management, memory operations, string utilities, etc.). Also known as `iml32.dll` in Director installations.

| Property | Value |
|----------|-------|
| **File size** | 999,936 bytes (976 KB) |
| **Architecture** | x86 (32-bit), PE32 |
| **SHA-256** | `3a0c3ed74e5de587ef97247ee14901ecad5d5106c0ad257c5960742ca64eea63` |
| **MD5** | `a82921d2762b284a12b74d22fda41b9b` |

---

## Building

### Prerequisites

- **Visual Studio 2022** (Community, Professional, or Enterprise) with the **"Desktop development with C++"** workload
- **CMake 3.15+** (included with Visual Studio, or [install separately](https://cmake.org/download/))
- **Windows SDK** (included with the Visual Studio C++ workload)

### Quick Build

The simplest way to build — just run the included batch script:

```bat
git clone https://github.com/Quackster/dirapi.git
cd dirapi
build.bat
```

This will auto-detect your Visual Studio installation, configure CMake for x86, and build in Release mode. The output DLL will be at `build\Release\dirapi.dll`.

> **Note:** If `cl.exe` is not in your PATH, the script will attempt to locate and invoke `vcvarsall.bat` automatically. For best results, run from a **"x86 Native Tools Command Prompt for VS 2022"**.

### Manual Build (CMake)

```bat
REM Open "x86 Native Tools Command Prompt for VS 2022", then:
cd dirapi
mkdir build
cd build
cmake .. -A Win32
cmake --build . --config Release
```

<details>
<summary><strong>Build Details</strong></summary>

The CMake configuration:

1. Collects all `src/**/*.c` files (excluding import thunk stubs and `_header.c`)
2. Generates an **iml32 import library** (`iml32.lib`) from `src/iml32.def` using MSVC's `lib.exe`
3. Compiles all source as **C** (`/TC`) with the master header force-included (`/FI dirapi_pch.h`)
4. Links against `iml32.lib` and Windows system libraries (`kernel32`, `user32`, `gdi32`, `ole32`, `oleaut32`, `winmm`, `version`, `msvcrt`, `ntdll`)
5. Exports ordinals via `src/dirapi.def`
6. Targets **x86 (32-bit)** — the original DLL is a 32-bit PE

**Compiler flags:**
- `/W0` — all warnings suppressed (decompiled code generates thousands)
- `/Zc:wchar_t-` — `wchar_t` is not a built-in type (matches original binary)
- `/O2 /Ob2` — release optimization (in Release config)
- `/FORCE:MULTIPLE` — allows multiply-defined symbols (needed for decompiled globals)

</details>

---

## Repository Structure

```
dirapi/
├── README.md
├── CMakeLists.txt          # CMake build configuration
├── build.bat               # One-step build script (Windows)
├── TASK.md                 # Current refactoring task documentation
│
├── src/                    # Reconstructed C source (802 .c files)
│   ├── dirapi_pch.h        # Master precompiled header (force-included)
│   ├── dirapi_types.h      # Ghidra type aliases → C types
│   ├── dirapi_functions.h  # Forward declarations (~7,300 functions)
│   ├── dirapi_globals.h    # Global variable declarations (~1,900 vars)
│   ├── dirapi_globals.c    # Global variable definitions
│   ├── dirapi.def          # DLL export ordinal definitions (371 exports)
│   ├── iml32.def           # IML32 import library definitions (585 imports)
│   ├── iml32_imports.h     # IML32 import function declarations
│   ├── _header.c           # File header / comment
│   ├── _index.txt          # Source file index
│   └── <25 subdirectories> # Categorized decompiled functions
│
├── bin/                    # Original binary files
│   ├── dirapi_original.dll # Original Director runtime DLL
│   └── iml32_original.dll  # Companion import library DLL
│
├── analysis/               # Ghidra reverse engineering output
│   ├── ghidra/             # Analysis documents, exports, symbol tables
│   └── tools/              # Ghidra batch scripts (DecompileAll.java)
│
├── tools/                  # Python build/fixup utilities
│   ├── generate_headers.py
│   ├── fixup_compilation.py
│   ├── fixup_ghidra_patterns.py
│   ├── fixup_void_returns.py
│   ├── fixup_source_errors.py
│   ├── fixup_remaining.py
│   └── fixup_final.py
│
├── examples/               # Example / test programs
│   └── test_dirapi.c       # Smoke test against original DLL
│
└── build/                  # CMake build output (gitignored)
```

<details>
<summary><strong>Source File Categories (25 subdirectories, 802 files)</strong></summary>

| Directory | Files | Description |
|-----------|------:|-------------|
| `src/strings/` | 50 | String handling, Lingo symbol table operations |
| `src/lingo/` | 42 | Lingo scripting engine core (parser, compiler, VM) |
| `src/media_playback/` | 39 | Audio and media playback functions |
| `src/stage/` | 38 | Stage (window) rendering and display management |
| `src/javascript/` | 38 | JavaScript engine integration (SpiderMonkey bridge) |
| `src/cast/` | 38 | Cast member management (sprites, bitmaps, text, etc.) |
| `src/runtime/` | 37 | Lingo runtime execution and value operations |
| `src/playback/` | 37 | Movie playback control and tempo |
| `src/xtra_runtime/` | 36 | Xtra plugin runtime support and dispatch |
| `src/score/` | 36 | Score (timeline) data management |
| `src/media/` | 36 | Media file format handling and I/O |
| `src/crt/` | 36 | C runtime compatibility shims (MSVCR100 bridge) |
| `src/score_engine/` | 35 | Score/timeline playback engine |
| `src/rendering/` | 35 | Graphics rendering and compositing |
| `src/events/` | 35 | Event handling and message dispatch |
| `src/props/` | 34 | Property getter/setter dispatch tables |
| `src/sprites/` | 33 | Sprite object system and collision |
| `src/bitmap/` | 33 | Bitmap/image loading, conversion, and manipulation |
| `src/display/` | 32 | Display surface and device context management |
| `src/core/` | 30 | Core infrastructure (memory, initialization, COM) |
| `src/xtra/` | 28 | Xtra plugin interface and registration |
| `src/crypto/` | 22 | Cryptography, DRM, and content protection |
| `src/globals/` | 11 | Global variable declarations and data segments |
| `src/certificates/` | 10 | Certificate verification and trust chain |

Each `.c` file contains multiple decompiled functions named by their original memory address (e.g., `funcs_680e0150.c`). Functions preserve the full Ghidra decompiler output with original control flow.

</details>

<details>
<summary><strong>Analysis Files (analysis/)</strong></summary>

### `analysis/ghidra/`

Output from Ghidra reverse engineering sessions:

| File | Size | Description |
|------|------|-------------|
| `decompiled_functions.c` | 10.2 MB | Raw Ghidra decompilation of all ~8,395 functions |
| `exports.txt` | 32.9 KB | 371 exported ordinal function signatures |
| `imports.txt` | 25.6 KB | 585 imported ordinal signatures from iml32.dll |
| `lingo_symbol_table.h` | 51.6 KB | Reconstructed Lingo property/method ID mapping |
| `strings.txt` | 62.2 KB | Extracted string constants from the binary |
| `data_types.txt` | 24.9 KB | Recovered Windows API types and structures |
| `analysis_ordinal_groups.txt` | 25.7 KB | Ordinal grouping and subsystem architecture |
| `analysis_dispatch.txt` | 12.7 KB | Property dispatch system and method routing |
| `analysis_entry_points.txt` | 25.6 KB | Entry point and initialization function analysis |

### `analysis/tools/`

| File | Description |
|------|-------------|
| `DecompileAll.java` | Ghidra script for batch-decompiling all functions |

</details>

<details>
<summary><strong>Build Infrastructure Files</strong></summary>

### Headers (in `src/`)

| File | Lines | Purpose |
|------|------:|---------|
| `dirapi_pch.h` | 17 | Master precompiled header — force-included in all translation units via `/FI` |
| `dirapi_types.h` | 211 | Maps Ghidra types (`undefined4`, `code`, `float10`, etc.) to C types, defines `CONCAT`/`SUB` macros, suppresses MSVC warnings |
| `dirapi_functions.h` | 8,072 | Forward declarations for ~7,300 internal functions |
| `dirapi_globals.h` | 2,272 | `extern` declarations for ~1,900 global variables |
| `dirapi_globals.c` | 2,425 | Global variable definitions and CRT shims |
| `iml32_imports.h` | — | Declarations for 585 functions imported from iml32.dll |

### Module Definition Files (in `src/`)

| File | Lines | Purpose |
|------|------:|---------|
| `dirapi.def` | 373 | DLL export table — 371 ordinal exports (mostly `NONAME`) + `entry` |
| `iml32.def` | 587 | Import library definition — used to generate `iml32.lib` at build time |

### Python Tooling (in `tools/`)

| Script | Purpose |
|--------|---------|
| `generate_headers.py` | Generates `dirapi_functions.h` and `dirapi_globals.h` from source |
| `fixup_compilation.py` | Automated fixes for common Ghidra decompilation artifacts |
| `fixup_ghidra_patterns.py` | Pattern-based cleanup of Ghidra-specific idioms |
| `fixup_void_returns.py` | Fixes void-returning functions that Ghidra marked incorrectly |
| `fixup_source_errors.py` | Targeted fixes for specific compilation errors |
| `fixup_remaining.py` | Catches remaining edge-case compilation issues |
| `fixup_final.py` | Final pass cleanup |

</details>

---

## Background

Adobe Director (originally Macromedia Director) was a multimedia authoring tool widely used from the 1990s through the 2000s for creating interactive content, games, CD-ROM titles, and early web applications (via Shockwave). Adobe discontinued Director in 2017.

`dirapi.dll` (internally referenced as `iml32.dll` in some contexts) is the **core runtime** that powers Director movie playback. Unlike Xtras (plugins), this DLL *is* the engine — it implements everything from file parsing to script execution to rendering.

This project reconstructs compilable C source from the binary using Ghidra's decompiler, with the long-term goal of producing a fully readable and modifiable codebase that can serve as a reference implementation or foundation for preservation efforts.

---

## License

This repository contains decompiled proprietary code for **research and preservation purposes**. The original `dirapi.dll` is the property of Adobe Inc. This project is not affiliated with or endorsed by Adobe.
