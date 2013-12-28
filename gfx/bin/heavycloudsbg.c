#include <PA_BgStruct.h>

extern const char heavycloudsbg_Tiles[];
extern const char heavycloudsbg_Map[];
extern const char heavycloudsbg_Pal[];

const PA_BgStruct heavycloudsbg = {
	PA_BgNormal,
	256, 192,

	heavycloudsbg_Tiles,
	heavycloudsbg_Map,
	{heavycloudsbg_Pal},

	6016,
	{1536}
};
