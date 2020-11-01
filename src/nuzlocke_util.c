#include "nuzlocke_util.h"
#include "main.h"
#include "save.h"

void GameOver(void)
{
    Save_EraseAllData();
    DoSoftReset();
}
