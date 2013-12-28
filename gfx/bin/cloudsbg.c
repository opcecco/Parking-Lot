#include <PA_BgStruct.h>

extern const char cloudsbg_Tiles[];
extern const char cloudsbg_Map[];
extern const char cloudsbg_Pal[];

const PA_BgStruct cloudsbg = {
	PA_BgNormal,
	256, 192,

	cloudsbg_Tiles,
	cloudsbg_Map,
	{cloudsbg_Pal},

	6208,
	{1536}
};
