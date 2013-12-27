#include <PA_BgStruct.h>

extern const char topscreenbg_Tiles[];
extern const char topscreenbg_Map[];
extern const char topscreenbg_Pal[];

const PA_BgStruct topscreenbg = {
	PA_BgNormal,
	256, 192,

	topscreenbg_Tiles,
	topscreenbg_Map,
	{topscreenbg_Pal},

	34624,
	{1536}
};
