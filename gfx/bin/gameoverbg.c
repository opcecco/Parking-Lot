#include <PA_BgStruct.h>

extern const char gameoverbg_Tiles[];
extern const char gameoverbg_Map[];
extern const char gameoverbg_Pal[];

const PA_BgStruct gameoverbg = {
	PA_BgNormal,
	256, 192,

	gameoverbg_Tiles,
	gameoverbg_Map,
	{gameoverbg_Pal},

	5440,
	{1536}
};
