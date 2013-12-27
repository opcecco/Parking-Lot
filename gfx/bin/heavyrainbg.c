#include <PA_BgStruct.h>

extern const char heavyrainbg_Tiles[];
extern const char heavyrainbg_Map[];
extern const char heavyrainbg_Pal[];

const PA_BgStruct heavyrainbg = {
	PA_BgNormal,
	256, 256,

	heavyrainbg_Tiles,
	heavyrainbg_Map,
	{heavyrainbg_Pal},

	3200,
	{2048}
};
