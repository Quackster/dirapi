cmake_minimum_required(VERSION 3.15)
project(dirapi C)

# Target 32-bit x86 Windows
if(MSVC)
    # Force 32-bit compilation
    # Use: cmake -A Win32 ..
endif()

# Collect all source files
file(GLOB_RECURSE ALL_SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

# Exclude import thunk files (IAT stubs from Ghidra)
# These are replaced by proper import library linkage
set(EXCLUDED_THUNK_FILES
    "${CMAKE_SOURCE_DIR}/src/globals/funcs_68174772.c"
    "${CMAKE_SOURCE_DIR}/src/strings/strings_import_thunks.c"
)

list(REMOVE_ITEM ALL_SOURCES ${EXCLUDED_THUNK_FILES})

# Also exclude _header.c (just a comment file)
list(FILTER ALL_SOURCES EXCLUDE REGEX "_header\\.c$")

# Create the DLL
add_library(dirapi SHARED ${ALL_SOURCES}
    ${CMAKE_SOURCE_DIR}/src/dirapi_globals.c
)

# Use the .def file for exports
set_target_properties(dirapi PROPERTIES
    LINK_FLAGS "/DEF:\"${CMAKE_SOURCE_DIR}/src/dirapi.def\""
    OUTPUT_NAME "dirapi"
    SUFFIX ".dll"
    PREFIX ""
)

# Force-include the master header in all translation units
target_compile_options(dirapi PRIVATE
    /FI"${CMAKE_SOURCE_DIR}/src/dirapi_pch.h"
    /W0           # Suppress warnings for decompiled code
    /TC           # Compile as C
    /Zc:wchar_t-  # wchar_t is not built-in (match original)
)

target_include_directories(dirapi PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Generate IML32 import library from .def file
set(IML32_DEF "${CMAKE_SOURCE_DIR}/src/iml32.def")
set(IML32_LIB "${CMAKE_BINARY_DIR}/iml32.lib")

add_custom_command(
    OUTPUT ${IML32_LIB}
    COMMAND lib /def:${IML32_DEF} /out:${IML32_LIB} /machine:x86 /nologo
    DEPENDS ${IML32_DEF}
    COMMENT "Generating IML32 import library from .def file"
)

add_custom_target(iml32_importlib DEPENDS ${IML32_LIB})
add_dependencies(dirapi iml32_importlib)

# Link against IML32 import library and system libraries
target_link_libraries(dirapi PRIVATE
    ${IML32_LIB}
    kernel32
    user32
    gdi32
    ole32
    oleaut32
    winmm
    version
)

# Link against MSVC runtime
if(MSVC)
    target_link_options(dirapi PRIVATE
        /NODEFAULTLIB:libcmt
        /FORCE:MULTIPLE
    )
    target_link_libraries(dirapi PRIVATE msvcrt ntdll)
endif()
