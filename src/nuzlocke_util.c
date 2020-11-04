#include "nuzlocke_util.h"
#include "global.h"
#include "overworld.h"
#include "main.h"
#include "save.h"
#include "event_data.h"
#include "constants/nuzlocke_flags.h"

void GameOver(void)
{
    Save_EraseAllData();
    DoSoftReset();
}

bool8 NuzEncGet(u8 location)
{
    return FlagGet(NUZENC_FLAGS_START + location);
}

void NuzEncSet(u8 location)
{
    FlagSet(NUZENC_FLAGS_START + location);
}

void NuzEncClear(u8 location)
{
    FlagClear(NUZENC_FLAGS_START + location);
}

u8 NuzCurrentMapSec()
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum)
        ->regionMapSectionId;
}

bool8 CurrNuzEncGet()
{
    return NuzEncGet(NuzCurrentMapSec());
}

void CurrNuzEncSet()
{
    NuzEncSet(NuzCurrentMapSec());
}

void CurrNuzEncClear()
{
    NuzEncClear(NuzCurrentMapSec());
}
