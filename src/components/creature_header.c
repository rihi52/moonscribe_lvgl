#include "lvgl/lvgl.h"
#include "../global.h"
#include "../styles.h"
#include "creature_header.h"

CreatureHeader *gpCreateCreatureHeader( const char *pName
                                      , uint16_t sChallengeRating
                                      , const char *pSize
                                      , const char *pType
                                      , const char *pSourceBook )
{
    CreatureHeader *HeaderToCreate = lv_malloc(sizeof(CreatureHeader));
}
