/**
 * @file lingo_symbol_table.h
 * @brief Reconstructed Lingo symbol registration table from dirapi.dll.
 *
 * This is a REFERENCE FILE derived from Ghidra analysis of dirapi.dll.
 * It maps Lingo property/method names to their internal symbol IDs and
 * documents how the runtime property dispatch system works.
 *
 * ARCHITECTURE:
 *   Director's Lingo engine does NOT dispatch properties by string name
 *   at runtime.  Instead it uses a two-phase numeric system:
 *
 *   Phase 1 - String to ID (startup):
 *     FUN_68038D10 hashes a property name string into an integer symbol ID
 *     via FUN_68031CA0 -> FUN_68039820 (hash) -> FUN_680533F0 (lookup).
 *
 *   Phase 2 - Numeric dispatch (runtime):
 *     Large switch statements dispatch on the integer property ID.
 *     Pattern: if (param_2 == 0) -> GET, else -> SET.
 *
 *   Bulk registration tables in .rdata (PTR_s_* at 0x6818xxxx) register
 *   arrays of {name, handler_function, flags} structs at startup via
 *   FUN_6811e130 (properties) and FUN_6811f610 (methods).
 *
 * SOURCES:
 *   - analysis/ghidra/strings.txt (property name strings at 0x6817xxxx)
 *   - analysis/ghidra/decompiled_functions.c (dispatch switch statements)
 *   - analysis/ghidra/analysis_dispatch.txt (architecture overview)
 */

#pragma once

/* ================================================================
 * SECTION 1: Lingo Object Type IDs
 *
 * Registered by FUN_6802CF20 (_movie scope) and FUN_6802D2C0 (_player
 * scope) via FUN_6811E190.  These appear as the first argument to
 * FUN_6802D3F0 during object type creation.
 * ================================================================ */

#define kLingoType_Sprite       0x2E    /* "sprite"  */
#define kLingoType_Sound        0x54    /* "sound"   */
#define kLingoType_Member       0x58    /* "member"  */
#define kLingoType_CastLib      0x68    /* "castLib" */
#define kLingoType_Script       0x7B    /* "script"  */
#define kLingoType_Window       0x7C    /* "window"  */
#define kLingoType_Xtra         0x7D    /* "xtra"    */
#define kLingoType_Channel      0x5FD   /* "channel" */

/* ================================================================
 * SECTION 2: Lingo Property IDs (from dispatch switch statements)
 *
 * These IDs are assigned by the symbol hash at startup.  The mapping
 * below is reconstructed from:
 *   - FUN_68019F60 (property registration table, 84 entries)
 *   - FUN_6800D7B0, FUN_6800DA30, FUN_6800D990 (dispatch switches)
 *   - FUN_6802CF20, FUN_6802D2C0 (object type registration)
 *
 * Where the Lingo name is not definitively known, the ID is listed
 * with its handler function or dispatch context as a comment.
 * ================================================================ */

/* --- Boolean / flag properties (0x39-0x79 range) --- */
#define kPropID_0x39            0x39    /* boolean property (handler LAB_68018bc0) */
#define kPropID_0x3a            0x3a    /* boolean property (handler LAB_68018bb0) */
#define kPropID_0x3c            0x3c    /* boolean property (handler FUN_68018c00) */
#define kPropID_0x78            0x78    /* boolean property (handler LAB_68018be0) */
#define kPropID_0x79            0x79    /* boolean property (handler LAB_68018bd0) */

/* --- Object accessor properties --- */
#define kPropID_Sprite          0x2E    /* "sprite"  (FUN_6800e440) */
#define kPropID_Member          0x58    /* "member"  (FUN_68017890) */
#define kPropID_MemberAlt       0x59    /* alternate member accessor (FUN_68017890) */
#define kPropID_CastLib         0x68    /* "castLib" (FUN_68016fd0) */
#define kPropID_Script          0x7B    /* "script"  (FUN_6800f8f0) */
#define kPropID_SoundWindow     0x7C    /* "sound"/"window" (FUN_680111d0) */
#define kPropID_WindowXtra      0x7D    /* "window"/"xtra" (FUN_6804c4e0) */
#define kPropID_0x82            0x82    /* property (FUN_68017900) */
#define kPropID_Point           0x99    /* point property (FUN_680197c0) */
#define kPropID_Rect            0xBC    /* "rect" rectangle property (FUN_6806eea0) */
#define kPropID_0xFF            0xFF    /* property (FUN_6800cee0) */
#define kPropID_Channel         0x5FD   /* "channel" (FUN_68018f20) */

/* --- Sprite/member capability properties (0x1A3-0x1C6 range) --- */
#define kPropID_0x1A3           0x1A3   /* boolean (FUN_68018b30) - possibly "visible" or similar */
#define kPropID_0x1A4           0x1A4   /* boolean (FUN_68018b50) */
#define kPropID_0x1A5           0x1A5   /* boolean (reuses LAB_68018bb0) */
#define kPropID_0x1A6           0x1A6   /* boolean (FUN_68018b70) */
#define kPropID_0x1A7           0x1A7   /* boolean (FUN_68018b90) */
#define kPropID_0x1A8           0x1A8   /* boolean (FUN_68018bf0) */
#define kPropID_0x1A9           0x1A9   /* color/RGBA (FUN_68018c10, extracts 4 bytes at +0xd) */
#define kPropID_0x1AA           0x1AA   /* boolean (FUN_68018cb0) */
#define kPropID_0x1AB           0x1AB   /* boolean (FUN_68018cb0) */
#define kPropID_0x1AC           0x1AC   /* boolean (FUN_68018ce0) */
#define kPropID_0x1AD           0x1AD   /* boolean (FUN_68018d10) */
#define kPropID_0x1AE           0x1AE   /* boolean (FUN_68018d40) */
#define kPropID_0x1AF           0x1AF   /* boolean (FUN_68018d50) */
#define kPropID_0x1B0           0x1B0   /* boolean (FUN_68018d70) */
#define kPropID_0x1B1           0x1B1   /* complex (FUN_68018d90) */
#define kPropID_0x1B2           0x1B2   /* complex (FUN_68018e50) */
#define kPropID_0x1B3           0x1B3   /* complex (FUN_68018eb0) */
#define kPropID_0x1B4           0x1B4   /* indexed param=0x15 (FUN_68019170) */
#define kPropID_0x1B5           0x1B5   /* indexed param=3  (FUN_68019020) */
#define kPropID_0x1B6           0x1B6   /* indexed param=2  (FUN_68019020) */
#define kPropID_0x1B7           0x1B7   /* indexed param=1  (FUN_68019020) */
#define kPropID_0x1B8           0x1B8   /* indexed param=0  (FUN_68019020) */
#define kPropID_0x1B9           0x1B9   /* boolean (FUN_680190f0) */
#define kPropID_0x1BA           0x1BA   /* indexed param=7  (FUN_68019170) */
#define kPropID_0x1BB           0x1BB   /* indexed param=0xc (FUN_68019170) */
#define kPropID_0x1BC           0x1BC   /* indexed param=0x10 (FUN_68019170) */
#define kPropID_0x1BD           0x1BD   /* indexed param=0xe  (FUN_68019170) */
#define kPropID_0x1BE           0x1BE   /* indexed param=0x11 (FUN_68019170) */
#define kPropID_0x1BF           0x1BF   /* indexed param=0x12 (FUN_68019170) */
#define kPropID_0x1C0           0x1C0   /* indexed param=0xf  (FUN_68019170) */
#define kPropID_0x1C1           0x1C1   /* complex (FUN_68019190) */
#define kPropID_0x1C2           0x1C2   /* complex (FUN_68019270) */
#define kPropID_0x1C3           0x1C3   /* returns d1d (FUN_68019350) */
#define kPropID_0x1C4           0x1C4   /* complex (FUN_68019bb0) */
#define kPropID_0x1C5           0x1C5   /* returns d2dd (FUN_68019360) */
#define kPropID_0x1C6           0x1C6   /* returns d2dd (FUN_680193d0) */

/* --- Flag / byte-sized properties --- */
#define kPropID_0x139           0x139   /* byte-sized property */
#define kPropID_0x15F           0x15F   /* flag (FUN_68018df0) */
#define kPropID_0x163           0x163   /* flag (reuses FUN_68019190) */

/* --- Extended properties (0x196-0x248 range) --- */
#define kPropID_0x196           0x196   /* indexed param=0x14 (FUN_68019170) */
#define kPropID_0x1E7           0x1E7   /* complex x2 (FUN_680195f0) */
#define kPropID_0x1EC           0x1EC   /* indexed param=0x16 (FUN_68019170) */
#define kPropID_0x1EE           0x1EE   /* complex x4 (FUN_68019440) */
#define kPropID_0x1EF           0x1EF   /* complex x4 (FUN_68019510) */
#define kPropID_0x23A           0x23A   /* boolean (FUN_680196d0) */
#define kPropID_0x23B           0x23B   /* boolean (FUN_680196e0) */
#define kPropID_0x23C           0x23C   /* complex x2 (FUN_680196f0) */
#define kPropID_0x248           0x248   /* indexed param=0x24 (FUN_68019170) */

/* --- Score/cast properties (0x290-0x311 range) --- */
#define kPropID_0x291           0x291   /* complex (FUN_68022ec0) */
#define kPropID_0x2D5           0x2D5   /* complex (FUN_6800f490) */
#define kPropID_0x2DB           0x2DB   /* complex (FUN_68019ab0) */
#define kPropID_0x30F           0x30F   /* boolean (FUN_68019830) */
#define kPropID_0x310           0x310   /* complex (FUN_680199c0) */
#define kPropID_0x311           0x311   /* complex (FUN_68019a30) */

/* --- Named / special properties (0x335-0x3D4 range) --- */
#define kPropID_0x335           0x335   /* complex (FUN_68019300) */
#define kPropID_Named           0x338   /* named property lookup (FUN_68019120) */
#define kPropID_0x3B9           0x3B9   /* pointer (FUN_68019800) */
#define kPropID_0x3C3           0x3C3   /* complex (FUN_68018ef0) */
#define kPropID_0x3D1           0x3D1   /* complex (FUN_680276c0) */

/* --- Float properties (0x3D2-0x3D4 range) --- */
#define kPropID_Float_A         0x3D2   /* float property */
#define kPropID_Float_B         0x3D3   /* float property */
#define kPropID_Float_C         0x3D4   /* float property */

/* --- Extended object properties (0x63A-0x663 range) --- */
#define kPropID_0x63A           0x63A   /* complex (FUN_680280a0) */
#define kPropID_0x646           0x646   /* complex (FUN_68019ca0) */
#define kPropID_0x647           0x647   /* complex (FUN_68019d40) */
#define kPropID_0x648           0x648   /* complex (FUN_68019da0) */
#define kPropID_0x655           0x655   /* special return -1 (FUN_68019e60) */
#define kPropID_0x662           0x662   /* complex (FUN_68010810) */
#define kPropID_0x663           0x663   /* complex (FUN_680106f0) */

/* ================================================================
 * SECTION 3: Lingo Scope Registration
 *
 * Master initialization: FUN_6802A1F0 (line 40684)
 *   Registers _global, then cascades into sub-registrations:
 *
 *   FUN_6802c170 -> _system  (PTR_s_version_6818bdf8, PTR_s_colorDepth_6818bec8)
 *   FUN_6802c2c0 -> _sound   (PTR_DAT_6818bfe8, PTR_s_soundDevice_6818c030)
 *   FUN_6802c380 -> _mouse   (PTR_DAT_6818c120, PTR_s_clickLoc_6818c138)
 *   FUN_6802c470 -> _key     (PTR_DAT_6818c318, PTR_s_commandDown_6818c340)
 *   FUN_6802cf20 -> _movie   (PTR_DAT_6818c430, PTR_s_aboutInfo_6818c668)
 *   FUN_6802d2c0 -> _player  (PTR_DAT_6818cd58, PTR_s_activeWindow_6818ce00)
 *   FUN_6802b3e0 -> _symbol  (PTR_s__symbol_6818bd08)
 *   FUN_6802bde0 -> _generic (PTR_s__generic_6818bdb0)
 *   FUN_6802d400 -> access   (PTR_s_access_6818d1a8)
 *
 * Each scope has a methods table (FUN_6811f610) and a properties
 * table (FUN_6811e130).  The table entries are in .rdata and contain
 * the actual property name strings from strings.txt.
 * ================================================================ */

/* ================================================================
 * SECTION 4: _system properties
 *
 * Registered by FUN_6802c170.
 * Methods table: PTR_s_version_6818bdf8
 * Properties table: PTR_s_colorDepth_6818bec8
 *
 * Property names (from strings.txt address ordering):
 * ================================================================ */

/*  "version"               -- Director version string              */
/*  "ticks"                 -- System tick count                    */
/*  "seconds"               -- System time in seconds               */
/*  "freeBytes"             -- Available memory bytes               */
/*  "freeBlock"             -- Largest free memory block             */
/*  "memorysize"            -- Total memory size                    */
/*  "clearGlobals"          -- Clear all global variables            */
/*  "showGlobals"           -- Display globals in message window     */
/*  "showLocals"            -- Display locals in message window      */
/*  "colorDepth"            -- Current color depth                  */
/*  "soundEnabled"          -- Sound playback enabled               */
/*  "exitLock"              -- Prevent movie exit                   */
/*  "selStart"              -- Text selection start                 */
/*  "selEnd"                -- Text selection end                   */
/*  "switchColorDepth"      -- Auto-switch color depth              */
/*  "fixStageSize"          -- Lock stage dimensions                */
/*  "centerStage"           -- Center stage on screen               */
/*  "machineType"           -- Machine type identifier              */
/*  "platform"              -- Platform name string                 */
/*  "runMode"               -- Authoring/runtime/projector mode     */
/*  "productVersion"        -- Product version string               */
/*  "productName"           -- Product name string                  */
/*  "applicationPath"       -- Application file path                */
/*  "environmentPropList"   -- Environment property list            */
/*  "osVersion"             -- Operating system version             */
/*  "osLanguage"            -- Operating system language             */

/* ================================================================
 * SECTION 5: _sound properties
 *
 * Registered by FUN_6802c2c0.
 * Methods table: PTR_DAT_6818bfe8
 * Properties table: PTR_s_soundDevice_6818c030
 * ================================================================ */

/*  "soundDevice"           -- Active sound output device           */
/*  "soundDeviceList"       -- Available sound devices              */
/*  "soundLevel"            -- Master volume level (1-7)            */
/*  "soundEnabled"          -- Sound enabled flag                   */
/*  "volume"                -- Volume (0-255)                       */
/*  "soundBusy"             -- Sound channel busy flag              */
/*  "puppetSound"           -- Puppet sound control                 */
/*  "sound1"-"sound8"       -- Sound channels 1-8                   */
/*  "sound9"-"sound16"      -- Sound channels 9-16 (extended)       */

/* ================================================================
 * SECTION 6: _mouse properties
 *
 * Registered by FUN_6802c380.
 * Methods table: PTR_DAT_6818c120
 * Properties table: PTR_s_clickLoc_6818c138
 * ================================================================ */

/*  "clickLoc"              -- Last click location (point)          */
/*  "clickOn"               -- Sprite clicked on                    */
/*  "mouseH"                -- Mouse horizontal position            */
/*  "mouseV"                -- Mouse vertical position              */
/*  "mouseLoc"              -- Mouse location (point)               */
/*  "mouseDown"             -- Mouse button is down                 */
/*  "mouseUp"               -- Mouse button is up                   */
/*  "stillDown"             -- Mouse still held down                */
/*  "doubleClick"           -- Double-click detected                */
/*  "rightMouseDown"        -- Right mouse button down              */
/*  "rightMouseUp"          -- Right mouse button up                */
/*  "mouseCast"             -- Cast member under mouse              */
/*  "mouseChar"             -- Character under mouse                */
/*  "mouseWord"             -- Word under mouse                     */
/*  "mouseItem"             -- Item under mouse                     */
/*  "mouseLine"             -- Line under mouse                     */
/*  "mouseMember"           -- Member under mouse                   */
/*  "mouseSprite"           -- Sprite under mouse                   */
/*  "rollover"              -- Sprite being rolled over             */

/* ================================================================
 * SECTION 7: _key properties
 *
 * Registered by FUN_6802c470.
 * Methods table: PTR_DAT_6818c318
 * Properties table: PTR_s_commandDown_6818c340
 * ================================================================ */

/*  "commandDown"           -- Command/Ctrl key is down             */
/*  "optionDown"            -- Option/Alt key is down               */
/*  "shiftDown"             -- Shift key is down                    */
/*  "controlDown"           -- Control key is down                  */
/*  "keyCode"               -- Key code of last keypress            */
/*  "keyPressed"            -- Specific key is down                 */
/*  "lastKey"               -- Last key pressed                     */

/* ================================================================
 * SECTION 8: _movie properties and methods
 *
 * Registered by FUN_6802CF20.
 * Methods table: PTR_DAT_6818c430
 * Properties table: PTR_s_aboutInfo_6818c668
 *
 * Object types registered:
 *   "member"  (0x58), "castLib" (0x68), "script" (0x7B),
 *   "sprite"  (0x2E), "channel" (0x5FD)
 * ================================================================ */

/*  --- Movie info --- */
/*  "aboutInfo"             -- Movie about text                     */
/*  "movieName"             -- Movie file name                      */
/*  "moviePath"             -- Movie file path                      */
/*  "movieFileSize"         -- Movie file size in bytes             */
/*  "movieFileFreeSize"     -- Free space in movie file             */
/*  "movieFileVersion"      -- Movie file format version            */
/*  "fileVersion"           -- Shorthand for file version           */
/*  "fileSize"              -- Shorthand for file size              */
/*  "fileFreeSize"          -- Shorthand for free size              */
/*  "movieCopyrightInfo"    -- Copyright string                     */
/*  "movieAboutInfo"        -- About string                         */
/*  "copyrightInfo"         -- Shorthand copyright                  */
/*  "comments"              -- User comments                        */
/*  "modifiedBy"            -- Last modifier name                   */
/*  "modifiedDate"          -- Last modified date                   */
/*  "creationDate"          -- Creation date                        */

/*  --- Playback control --- */
/*  "playing"               -- Is movie playing                     */
/*  "frameRate"             -- Desired frame rate                   */
/*  "stage"                 -- Stage window reference               */
/*  "score"                 -- Score reference                      */
/*  "castLibs"              -- Cast library list                    */
/*  "members"               -- Member list                          */
/*  "xtras"                 -- Loaded Xtras list                    */
/*  "windowList"            -- Open window list                     */
/*  "actorList"             -- Active actor list                    */
/*  "scriptList"            -- Active script list                   */

/*  --- Frame control --- */
/*  "lastFrame"             -- Last frame number                    */
/*  "frameLabel"            -- Current frame label                  */
/*  "framePalette"          -- Current frame palette                */
/*  "frameTempo"            -- Current frame tempo                  */
/*  "frameScript"           -- Current frame script                 */
/*  "frameSound1"           -- Frame sound channel 1                */
/*  "frameSound2"           -- Frame sound channel 2                */
/*  "frameTransition"       -- Frame transition effect              */
/*  "lastChannel"           -- Last active channel number           */

/*  --- Score recording --- */
/*  "beginRecording"        -- Start score recording                */
/*  "endRecording"          -- End score recording                  */
/*  "clearFrame"            -- Clear current frame                  */
/*  "updateFrame"           -- Update current frame                 */
/*  "duplicateFrame"        -- Duplicate current frame              */
/*  "deleteFrame"           -- Delete current frame                 */
/*  "insertFrame"           -- Insert new frame                     */

/*  --- Stage/display --- */
/*  "stageLeft"             -- Stage rect left                      */
/*  "stageTop"              -- Stage rect top                       */
/*  "stageRight"            -- Stage rect right                     */
/*  "stageBottom"           -- Stage rect bottom                    */
/*  "stageColor"            -- Stage background color               */
/*  "bgColor"               -- Alias for stage background           */
/*  "bgStageColor"          -- Alias for stage bg color             */
/*  "colorDepth"            -- Movie color depth                    */
/*  "updateLock"            -- Suppress stage updates               */
/*  "updateStage"           -- Force stage redraw                   */

/*  --- Palette --- */
/*  "palette"               -- Active palette                       */
/*  "puppetPalette"         -- Script-controlled palette            */
/*  "paletteMapping"        -- Palette mapping mode                 */
/*  "defaultPalette"        -- Default palette setting              */
/*  "remapPalettes"         -- Palette remapping flag               */

/*  --- Transitions --- */
/*  "transition"            -- Active transition                    */
/*  "puppetTransition"      -- Script-controlled transition         */
/*  "transitionType"        -- Transition type code                 */
/*  "fadeToBlack"           -- Fade to black transition             */
/*  "fadeToWhite"           -- Fade to white transition             */

/*  --- Tempo --- */
/*  "tempo"                 -- Active tempo setting                 */
/*  "puppetTempo"           -- Script-controlled tempo              */
/*  "waitSeconds"           -- Wait N seconds                       */
/*  "waitClick"             -- Wait for mouse click                 */
/*  "waitSound"             -- Wait for sound to finish             */
/*  "waitDigitalVideo"      -- Wait for video to finish             */
/*  "waitCuePoint"          -- Wait for cue point                   */

/*  --- Sprite operations --- */
/*  "puppetSprite"          -- Script-controlled sprite             */
/*  "immediateSprite"       -- Immediate sprite update              */
/*  "moveableSprite"        -- User-moveable sprite                 */
/*  "spriteBox"             -- Set sprite bounding box              */
/*  "sendSprite"            -- Send message to sprite               */
/*  "sendAllSprites"        -- Broadcast to all sprites             */
/*  "currentSpriteNum"      -- Current sprite number                */
/*  "keyboardFocusSprite"   -- Sprite with keyboard focus           */

/*  --- Cast operations --- */
/*  "castCount"             -- Number of cast libraries             */
/*  "memberCount"           -- Members in cast library              */
/*  "minMember"             -- Minimum member number                */
/*  "maxMember"             -- Maximum member number                */
/*  "activeCastLib"         -- Active cast library                  */
/*  "activeCast"            -- Active cast member                   */
/*  "preloadCast"           -- Preload cast member                  */
/*  "unloadCast"            -- Unload cast member                   */
/*  "preloadMember"         -- Preload specific member              */
/*  "unloadMember"          -- Unload specific member               */
/*  "importFileInto"        -- Import file into cast                */
/*  "findEmpty"             -- Find empty cast slot                 */
/*  "copyToClipboard"       -- Copy member to clipboard             */
/*  "pasteClipboardInto"    -- Paste clipboard to member            */

/*  --- Navigation --- */
/*  "goNext"                -- Go to next marker                    */
/*  "goPrevious"            -- Go to previous marker                */
/*  "goLoop"                -- Loop at current marker               */
/*  "label"                 -- Frame label at position              */
/*  "labelList"             -- List of all labels                   */
/*  "marker"                -- Marker reference                     */
/*  "searchPath"            -- Movie search paths                   */
/*  "searchPathList"        -- Search path list                     */
/*  "searchPaths"           -- All search paths                     */

/*  --- Timing --- */
/*  "timer"                 -- Timer value (ticks)                  */
/*  "startTimer"            -- Reset timer to 0                     */
/*  "timeoutLength"         -- Idle timeout (ticks)                 */
/*  "timeoutLapsed"         -- Time since last event                */
/*  "timeoutKeydown"        -- Key resets timeout                   */
/*  "timeoutMouse"          -- Mouse resets timeout                 */
/*  "timeoutPlay"           -- Timeout triggers play                */
/*  "timeoutScript"         -- Timeout handler script               */
/*  "timeoutList"           -- Timeout object list                  */

/*  --- Idle loading --- */
/*  "idleLoadDone"          -- Idle load complete flag              */
/*  "idleLoadTag"           -- Idle load progress tag               */
/*  "idleLoadPeriod"        -- Idle load time slice                 */
/*  "idleLoadMode"          -- Idle load mode                       */
/*  "idleReadChunkSize"     -- Idle load chunk size                 */
/*  "idleHandlerPeriod"     -- Idle handler interval                */
/*  "cancelIdleLoad"        -- Cancel idle loading                  */
/*  "finishIdleLoad"        -- Complete idle loading                */

/*  --- Digital video --- */
/*  "digitalVideo"          -- DV member reference                  */
/*  "digitalVideoType"      -- DV type (QT/AVI)                    */
/*  "digitalVideoTimeScale" -- DV time scale                        */
/*  "quickTime"             -- QuickTime reference                  */
/*  "videoForWindows"       -- Video for Windows reference          */
/*  "quickTimePresent"      -- QuickTime installed                  */
/*  "videoForWindowsPresent"-- VfW installed                        */
/*  "directToStage"         -- DV renders direct to stage           */
/*  "controller"            -- DV controller visible                */
/*  "duration"              -- DV duration                          */
/*  "movieTime"             -- DV current time                      */
/*  "movieRate"             -- DV playback rate                     */
/*  "startTime"             -- DV start time                        */
/*  "stopTime"              -- DV stop time                         */

/*  --- Image operations --- */
/*  "image"                 -- Image object reference               */
/*  "copyPixels"            -- Copy pixel data                      */
/*  "createMatte"           -- Create matte from image              */
/*  "trimWhiteSpace"        -- Trim whitespace                      */
/*  "extractAlpha"          -- Extract alpha channel                */
/*  "setAlpha"              -- Set alpha channel                    */
/*  "createMask"            -- Create mask image                    */
/*  "maskImage"             -- Mask image reference                 */
/*  "maskOffset"            -- Mask offset position                 */

/*  --- Imaging Lingo --- */
/*  "setPixel"              -- Set pixel at location                */
/*  "getPixel"              -- Get pixel at location                */
/*  "setPixels"             -- Bulk pixel set                       */
/*  "getPixels"             -- Bulk pixel get                       */
/*  "importByteArrayInto"   -- Import raw bytes into image          */

/*  --- Network --- */
/*  "getNetText"            -- HTTP GET text                        */
/*  "postNetText"           -- HTTP POST text                       */
/*  "netTextResult"         -- Last net text result                 */
/*  "netStatus"             -- Network status code                  */
/*  "netDone"               -- Network op complete                  */
/*  "netError"              -- Network error code                   */
/*  "netLastModDate"        -- Last modified date                   */
/*  "netMIME"               -- MIME type                            */
/*  "netAbort"              -- Abort network operation              */
/*  "netPresent"            -- Network available                    */
/*  "gotoNetMovie"          -- Navigate to net movie                */
/*  "gotoNetPage"           -- Navigate to URL                      */
/*  "downloadNetThing"      -- Download resource                    */
/*  "preloadNetThing"       -- Preload resource                     */
/*  "getLatestNetID"        -- Last network transaction ID          */
/*  "getStreamStatus"       -- Stream download status               */
/*  "streamStatus"          -- Stream status string                 */
/*  "tellStreamStatus"      -- Callback for stream status           */
/*  "internetConnected"     -- Internet connectivity state          */
/*  "browserName"           -- Browser name string                  */
/*  "proxyServer"           -- Proxy server address                 */
/*  "cacheSize"             -- Network cache size                   */
/*  "clearCache"            -- Clear network cache                  */

/*  --- Misc movie properties --- */
/*  "traceLogFile"          -- Trace log file path                  */
/*  "traceLoad"             -- Trace loading operations             */
/*  "trace"                 -- Enable script trace                  */
/*  "debugPlaybackEnabled"  -- Debug playback mode                  */
/*  "saveMovie"             -- Save current movie                   */
/*  "prepareMovie"          -- Prepare movie for playback           */
/*  "preloadEventAbort"     -- Abort preload on event               */
/*  "updateMovieEnabled"    -- Enable movie updates                 */
/*  "cpuHogTicks"           -- Yield time to OS                     */

/* ================================================================
 * SECTION 9: _player properties and methods
 *
 * Registered by FUN_6802D2C0.
 * Methods table: PTR_DAT_6818cd58
 * Properties table: PTR_s_activeWindow_6818ce00
 *
 * Object types registered:
 *   "sound" (0x54), "window" (0x7C), "xtra" (0x7D)
 * ================================================================ */

/*  "activeWindow"          -- Currently active window              */
/*  "frontWindow"           -- Frontmost window                     */
/*  "windowPresent"         -- Window system available              */
/*  "desktopRectList"       -- Monitor rectangle list               */
/*  "scoreSelection"        -- Score selection range                */
/*  "memberNum"             -- Current member number                */
/*  "castLibNum"            -- Current cast lib number              */
/*  "authorMode"            -- In authoring mode                    */
/*  "safePlayer"            -- Safe player mode                     */
/*  "productVersion"        -- Player version string                */
/*  "productBuildVersion"   -- Player build version                 */
/*  "applicationName"       -- Application name                     */
/*  "uiLanguage"            -- UI language setting                  */
/*  "commandLine"           -- Command line arguments               */

/* ================================================================
 * SECTION 10: Sprite properties
 *
 * These are the per-sprite properties accessed via numeric IDs
 * in the score channel data.  Property names from strings.txt.
 * ================================================================ */

/*  "castNum"               -- Cast member number                   */
/*  "locH"                  -- Horizontal position                  */
/*  "locV"                  -- Vertical position                    */
/*  "width"                 -- Sprite width                         */
/*  "height"                -- Sprite height                        */
/*  "rect"                  -- Bounding rectangle                   */
/*  "blend"                 -- Blend percentage (0-100)             */
/*  "ink"                   -- Ink effect                           */
/*  "puppet"                -- Puppet mode                          */
/*  "immediate"             -- Immediate update                     */
/*  "cursor"                -- Cursor shape                         */
/*  "foreColor"             -- Foreground color                     */
/*  "backColor"             -- Background color                     */
/*  "lineSize"              -- Line width                           */
/*  "stretch"               -- Stretch mode                         */
/*  "pattern"               -- Fill pattern                         */
/*  "editableText"          -- Text is editable                     */
/*  "constraint"            -- Movement constraint                  */
/*  "trails"                -- Leave trails                         */
/*  "visible"               -- Sprite visibility                    */
/*  "enabled"               -- Sprite enabled                       */
/*  "rotation"              -- Rotation angle                       */
/*  "flipH"                 -- Horizontal flip                      */
/*  "flipV"                 -- Vertical flip                        */
/*  "blendLevel"            -- Blend level (0-255)                  */
/*  "alphaThreshold"        -- Alpha threshold                      */
/*  "useAlpha"              -- Use alpha channel                    */
/*  "scoreColor"            -- Score display color                  */
/*  "scriptNum"             -- Attached script number               */
/*  "tweened"               -- Is tweened                           */

/* ================================================================
 * SECTION 11: Cast member properties
 *
 * Access via member(...).propertyName.
 * ================================================================ */

/*  "name"                  -- Member name                          */
/*  "type"                  -- Member type (bitmap, text, etc.)     */
/*  "loaded"                -- Member is loaded                     */
/*  "modified"              -- Member has been modified             */
/*  "castType"              -- Cast type code                       */
/*  "regPoint"              -- Registration point                   */
/*  "scriptText"            -- Member script source                 */
/*  "bitmap"                -- Bitmap reference                     */
/*  "filmLoop"              -- Film loop data                       */
/*  "shape"                 -- Shape type                           */
/*  "button"                -- Button type                          */
/*  "richText"              -- Rich text content                    */
/*  "preloadMode"           -- Preload strategy                     */
/*  "purgePriority"         -- Purge priority                       */
/*  "mediaReady"            -- Media loaded flag                    */
/*  "frameReady"            -- Frame ready flag                     */

/* ================================================================
 * SECTION 12: Text member properties
 * ================================================================ */

/*  "textFont"              -- Font name                            */
/*  "textSize"              -- Font size                            */
/*  "textStyle"             -- Font style                           */
/*  "textHeight"            -- Text block height                    */
/*  "textAlign"             -- Text alignment                       */
/*  "fontStyle"             -- Font style flags                     */
/*  "fontSize"              -- Font size value                      */
/*  "alignment"             -- Paragraph alignment                  */
/*  "wordWrap"              -- Word wrap enabled                    */
/*  "scroll"                -- Scroll position                      */
/*  "margin"                -- Text margin                          */
/*  "border"                -- Text border width                    */
/*  "boxType"               -- Text box type                        */
/*  "dropShadow"            -- Drop shadow offset                   */
/*  "boxDropShadow"         -- Box drop shadow                      */
/*  "autoTab"               -- Auto-tab to next field               */
/*  "editable"              -- Text is editable                     */
/*  "lineCount"             -- Number of lines                      */
/*  "lineHeight"            -- Height of text line                  */
/*  "charPosToLoc"          -- Character to screen position         */
/*  "locToCharPos"          -- Screen to character position         */
/*  "linePosToLocV"         -- Line to vertical position            */
/*  "locVToLinePos"         -- Vertical position to line            */
/*  "scrollByPage"          -- Scroll one page                      */
/*  "scrollByLine"          -- Scroll one line                      */
/*  "scrollTop"             -- Top of visible area                  */
/*  "pageHeight"            -- Visible page height                  */
/*  "selectedText"          -- Selected text content                */
/*  "pointToChar"           -- Point to character index             */
/*  "pointToWord"           -- Point to word index                  */
/*  "pointToLine"           -- Point to line index                  */
/*  "pointToItem"           -- Point to item index                  */
/*  "pointToParagraph"      -- Point to paragraph index             */
/*  "hyperlink"             -- Hyperlink data                       */
/*  "hyperlinkClicked"      -- Clicked hyperlink                    */
/*  "hyperlinkRange"        -- Hyperlink character range            */
/*  "hyperlinks"            -- All hyperlinks list                  */
/*  "hyperlinkState"        -- Hyperlink hover state                */
/*  "kerning"               -- Kerning enabled                      */
/*  "kerningThreshold"      -- Kerning threshold                    */
/*  "antiAliasThreshold"    -- Anti-alias size threshold            */

/* ================================================================
 * SECTION 13: Window properties
 * ================================================================ */

/*  "title"                 -- Window title                         */
/*  "resizable"             -- Window is resizable                  */
/*  "closebox"              -- Has close button                     */
/*  "maximizebox"           -- Has maximize button                  */
/*  "minimizebox"           -- Has minimize button                  */
/*  "sizeState"             -- minimized/maximized/normal           */
/*  "fullscreen"            -- Fullscreen mode                      */
/*  "document"              -- Document window style                */
/*  "dialog"                -- Dialog window style                  */
/*  "displayTemplate"       -- Display template name                */
/*  "sourceRect"            -- Source rectangle                     */
/*  "drawRect"              -- Drawing rectangle                    */
/*  "windowList"            -- List of windows                      */
/*  "frontWindow"           -- Frontmost window                     */

/* ================================================================
 * SECTION 14: Ink effect names (for ink property values)
 *
 * Used as string constants in ink property dispatch.
 * ================================================================ */

/*  "transparent"           -- Transparent ink                      */
/*  "reverse"               -- Reverse ink                          */
/*  "ghost"                 -- Ghost ink                            */
/*  "notCopy"               -- Not copy ink                         */
/*  "notTransparent"        -- Not transparent ink                  */
/*  "notReverse"            -- Not reverse ink                      */
/*  "notGhost"              -- Not ghost ink                        */
/*  "matte"                 -- Matte ink                            */
/*  "addPin"                -- Add pin ink                          */
/*  "subtractPin"           -- Subtract pin ink                     */
/*  "backgroundTransparent" -- Background transparent ink           */
/*  "lightest"              -- Lightest ink                         */
/*  "subtract"              -- Subtract ink                         */
/*  "darkest"               -- Darkest ink                          */
/*  "lighten"               -- Lighten ink                          */
/*  "darken"                -- Darken ink                           */

/* ================================================================
 * SECTION 15: Palette names (for palette property values)
 * ================================================================ */

/*  "systemMac"             -- Mac system palette                   */
/*  "systemWin"             -- Windows system palette               */
/*  "web216"                -- Web-safe 216 colors                  */
/*  "rainbow"               -- Rainbow palette                     */
/*  "grayscale"             -- Grayscale palette                    */
/*  "pastels"               -- Pastels palette                      */
/*  "vivid"                 -- Vivid palette                        */
/*  "metallic"              -- Metallic palette                     */

/* ================================================================
 * SECTION 16: Lingo event handler names
 *
 * These are registered as message/event names in the Lingo runtime.
 * ================================================================ */

/*  "startMovie"            -- Movie started                        */
/*  "stopMovie"             -- Movie stopped                        */
/*  "stepMovie"             -- Movie step (idle)                    */
/*  "prepareMovie"          -- Movie about to start                 */
/*  "enterFrame"            -- Entering frame                       */
/*  "exitFrame"             -- Exiting frame                        */
/*  "prepareFrame"          -- Frame about to render                */
/*  "mouseDown"             -- Mouse button pressed                 */
/*  "mouseUp"               -- Mouse button released                */
/*  "mouseUpOutSide"        -- Mouse released outside sprite        */
/*  "mouseEnter"            -- Mouse entered sprite                 */
/*  "mouseLeave"            -- Mouse left sprite                    */
/*  "mouseWithin"           -- Mouse inside sprite                  */
/*  "mouseStillDown"        -- Mouse held down                      */
/*  "rightMouseDown"        -- Right button pressed                 */
/*  "rightMouseUp"          -- Right button released                */
/*  "keyDown"               -- Key pressed                          */
/*  "keyUp"                 -- Key released                         */
/*  "beginSprite"           -- Sprite created                       */
/*  "endSprite"             -- Sprite destroyed                     */
/*  "openWindow"            -- Window opened                        */
/*  "closeWindow"           -- Window closed                        */
/*  "moveWindow"            -- Window moved                         */
/*  "zoomWindow"            -- Window zoomed                        */
/*  "resizeWindow"          -- Window resized                       */
/*  "activateWindow"        -- Window activated                     */
/*  "deactivateWindow"      -- Window deactivated                   */
/*  "activateApplication"   -- App gained focus                     */
/*  "deactivateApplication" -- App lost focus                       */
/*  "closeRequest"          -- Window close requested               */
/*  "collapseWindow"        -- Window collapsed                     */
/*  "revealWindow"          -- Window revealed                      */

/* ================================================================
 * SECTION 17: Lingo built-in functions and commands
 *
 * Registered in the global scope via method tables.
 * ================================================================ */

/*  "alert"                 -- Show alert dialog                    */
/*  "delay"                 -- Pause execution                      */
/*  "continue"              -- Resume from pause                    */
/*  "restart"               -- Restart application                  */
/*  "shutDown"              -- Shut down application                */
/*  "dontPassEvent"         -- Stop event propagation               */
/*  "updateStage"           -- Force stage redraw                   */
/*  "printFrom"             -- Print frames                         */
/*  "installMenu"           -- Install menu bar                     */
/*  "constrainH"            -- Constrain horizontal                 */
/*  "constrainV"            -- Constrain vertical                   */
/*  "zoomBox"               -- Animate zoom box                     */
/*  "openResFile"           -- Open resource file                   */
/*  "closeResFile"          -- Close resource file                  */
/*  "showResFile"           -- Show resource file                   */
/*  "openXLib"              -- Open XLibrary                        */
/*  "closeXLib"             -- Close XLibrary                       */
/*  "showXLib"              -- Show XLibrary                        */

/* ================================================================
 * SECTION 18: Shockwave 3D properties
 *
 * Registered by Shockwave3dAsset Xtra via PTR_s_ tables.
 * These are the property names found at addresses 0x68177740-0x681789fc
 * in strings.txt.
 * ================================================================ */

/*  "preferred3dRenderer"   -- Preferred 3D renderer                */
/*  "active3dRenderer"      -- Active 3D renderer                   */
/*  "software"              -- Software renderer                    */
/*  "directX5_2"            -- DirectX 5.2 renderer                 */
/*  "directX7_0"            -- DirectX 7.0 renderer                 */
/*  "directX9"              -- DirectX 9 renderer                   */
/*  "openGL"                -- OpenGL renderer                      */
/*  "model"                 -- 3D model reference                   */
/*  "modelResource"         -- 3D model resource                    */
/*  "shader"                -- 3D shader                            */
/*  "texture"               -- 3D texture                           */
/*  "light"                 -- 3D light                             */
/*  "camera"                -- 3D camera                            */
/*  "group"                 -- 3D group node                        */
/*  "motion"                -- 3D motion/animation                  */
/*  "particle"              -- 3D particle system                   */
/*  "collision"             -- 3D collision detection               */
/*  "rootNode"              -- Scene graph root                     */
/*  "fieldOfView"           -- Camera field of view                 */
/*  "projectionAngle"       -- Camera projection angle              */
/*  "hither"                -- Camera near plane                    */
/*  "worldPosition"         -- World-space position                 */
/*  "worldTransform"        -- World-space transform                */
/*  "boundingSphere"        -- Bounding sphere                      */
/*  "userData"              -- User-attached data                   */
/*  "addToWorld"            -- Add node to world                    */
/*  "removeFromWorld"       -- Remove node from world               */
/*  "clone"                 -- Clone node                           */
/*  "cloneDeep"             -- Deep-clone node                      */
/*  "resetWorld"            -- Reset 3D world                       */

/* ================================================================
 * SECTION 19: Xtra registration metadata keys
 *
 * String constants used when querying Xtra capabilities via vtable.
 * Pattern: (*vtbl->+0x14)(obj, type, buf, size, "key")
 * ================================================================ */

/*  "Speed"                 -- Processing speed capability          */
/*  "Formats"               -- Supported media formats              */
/*  "DirTypes"              -- Director type support                */
/*  "@ClassID"              -- COM class identifier                 */
/*  "FileExts"              -- Supported file extensions            */
/*  "FileTypes"             -- Supported file type codes            */
/*  "UnderstoodReceptors"   -- Supported message types              */
/*  "actorType"             -- Actor type identifier                */
/*  "displayNameString"     -- Human-readable Xtra name             */
/*  "symbolString"          -- Symbol identifier string             */
/*  "assetCaps"             -- Asset capability flags               */
/*  "safeForShockwave"      -- Shockwave security flag              */
/*  "Compare"               -- Comparison handler                   */

/* ================================================================
 * SECTION 20: Xtra invocation method names
 *
 * Called via FUN_68083BB0 (Xtra method wrapper).
 * ================================================================ */

/*  "Pause"                 -- Pause Xtra playback                  */
/*  "Resume"                -- Resume Xtra playback                 */
/*  "Suspend"               -- Suspend Xtra                         */
/*  "IsPaused"              -- Query paused state                   */
/*  "IsBusy"                -- Query busy state                     */
/*  "BreakLoop"             -- Break playback loop                  */
/*  "IsPastCuePoint"        -- Check cue point passed               */

/* ================================================================
 * SECTION 21: Runtime string-to-symbol lookups (FUN_68038D10 calls)
 *
 * These are the property names resolved at runtime (not bulk-registered).
 * Found as inline string literals in decompiled function bodies.
 * ================================================================ */

/*  Line 70765:  "is3dCastMember"    -- FUN_68045c20: 3D member check      */
/*  Line 70875:  "is3dCastMember"    -- FUN_68046180: 3D member check (alt) */
/*  Line 187771: "Compare"           -- FUN_680b4f80: Object comparison      */
/*  Line 219700: "width"             -- FUN_680d3640: Sprite/rect width      */
/*  Line 219701: "height"            -- FUN_680d3640: Sprite/rect height     */
/*  Line 221193: "antiAliasThreshold"-- FUN_680d3dc0: Text AA threshold     */
/*  Line 233373: "directToStage"     -- FUN_680e1790: DV stage rendering    */
