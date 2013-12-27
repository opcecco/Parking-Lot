#include <PA_BgStruct.h>

extern const char congratsbg_Tiles[];
extern const char congratsbg_Map[];
extern const char congratsbg_Pal[];

const PA_BgStruct congratsbg = {
	PA_BgNormal,
	256, 192,

	congratsbg_Tiles,
	congratsbg_Map,
	{congratsbg_Pal},

	8384,
	{1536}
};
