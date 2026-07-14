#ifndef CREATURE_HEADER_H
#define CREATURE_HEADER_H
#include "lvgl/lvgl.h"

/*********************
 *  Global Variables
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
    lv_obj_t *pHeaderContainer;
    lv_obj_t *pNameLabel;
    lv_obj_t *pChallengeRatingLabel;
    lv_obj_t *pSizeLabel;
    lv_obj_t *pTypeLabel;
    lv_obj_t *pSourceBookLabel;

    const char *pName;
    uint16_t sChallengeRating;
    const char *pSize;
    const char *pType;
    const char *pSourceBook;
} CreatureHeader;

/*********************
 *  Global Prototypes
 *********************/
CreatureHeader *gpCreateCreatureHeader( const char *pName
                                      , uint16_t sChallengeRating
                                      , const char *pSize
                                      , const char *pType
                                      , const char *pSourceBook );

#endif  /* CREATURE_HEADER_H */
