#include <PA_BgStruct.h>

extern const char rainbg_Tiles[];
extern const char rainbg_Map[];
extern const char rainbg_Pal[];

const PA_BgStruct rainbg = {
	PA_BgNormal,
	256, 256,

	rainbg_Tiles,
	rainbg_Map,
	{rainbg_Pal},

	2496,
	{2048}
};
