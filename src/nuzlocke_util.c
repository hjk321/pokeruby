#include "nuzlocke_util.h"
#include "global.h"
#include "overworld.h"
#include "main.h"
#include "save.h"
#include "event_data.h"
#include "constants/nuzlocke_flags.h"
#include "pokemon.h"

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

u8 CountAlivePartyMons()
{
    u16 i;
    u16 count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon = gPlayerParty + i;
        if (GetMonData(pokemon, MON_DATA_SPECIES) != 0 && !GetMonData(pokemon, MON_DATA_IS_EGG) && GetMonData(pokemon, MON_DATA_HP) != 0)
            count++;
    }
    return count;
}

u8 CountDeadPartyMons()
{
    return gSaveBlock1.playerPartyCount - CountAlivePartyMons();
}
