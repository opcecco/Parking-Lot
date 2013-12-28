#include <PA_BgStruct.h>

extern const char cloudsbg_Tiles[];
extern const char cloudsbg_Map[];
extern const char cloudsbg_Pal[];

const PA_BgStruct cloudsbg = {
	PA_BgNormal,
	256, 256,

	cloudsbg_Tiles,
	cloudsbg_Map,
	{cloudsbg_Pal},

	6272,
	{2048}
};
