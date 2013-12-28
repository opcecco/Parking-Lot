#include <PA_BgStruct.h>

extern const char parkinglotbg_Tiles[];
extern const char parkinglotbg_Map[];
extern const char parkinglotbg_Pal[];

const PA_BgStruct parkinglotbg = {
	PA_BgNormal,
	256, 192,

	parkinglotbg_Tiles,
	parkinglotbg_Map,
	{parkinglotbg_Pal},

	3072,
	{1536}
};
