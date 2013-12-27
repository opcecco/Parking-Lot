// Graphics converted using PAGfx by Mollusk.

#pragma once

#include <PA_BgStruct.h>

#ifdef __cplusplus
extern "C"{
#endif

// Sprites:
extern const unsigned char player_Sprite[512] _GFX_ALIGN; // Palette: player_Pal
extern const unsigned char enemy_Sprite[30720] _GFX_ALIGN; // Palette: enemy_Pal
extern const unsigned char button_Sprite[1920] _GFX_ALIGN; // Palette: button_Pal

// Backgrounds:
extern const PA_BgStruct cloudsbg;
extern const PA_BgStruct congratsbg;
extern const PA_BgStruct gameoverbg;
extern const PA_BgStruct heavycloudsbg;
extern const PA_BgStruct heavyrainbg;
extern const PA_BgStruct parkinglotbg;
extern const PA_BgStruct rainbg;
extern const PA_BgStruct topscreenbg;

// Palettes:
extern const unsigned short player_Pal[256] _GFX_ALIGN;
extern const unsigned short enemy_Pal[256] _GFX_ALIGN;
extern const unsigned short button_Pal[256] _GFX_ALIGN;

#ifdef __cplusplus
}
#endif
