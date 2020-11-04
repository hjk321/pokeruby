#ifndef GUARD_NUZLOCKEUTIL_H
#define GUARD_NUZLOCKEUTIL_H
#include "global.h"

void GameOver(void);
bool8 NuzEncGet(u8 location);
void NuzEncSet(u8 location);
void NuzEncClear(u8 location);
u8 NuzCurrentMapSec();
bool8 CurrNuzEncGet();
void CurrNuzEncSet();
void CurrNuzEncClear();

#endif // GUARD_NUZLOCKEUTIL_H
