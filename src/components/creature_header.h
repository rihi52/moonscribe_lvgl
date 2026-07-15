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
    /* Containers */
    lv_obj_t *pHeaderContainer;
    lv_obj_t *pNameRowContainer;
    lv_obj_t *pChallengeRatingSizeRowContainer;
    lv_obj_t *pTypeSourceRowContainer;

    /* Labels */
    lv_obj_t *pNameLabel;
    lv_obj_t *pChallengeRatingLabel;
    lv_obj_t *pSizeLabel;
    lv_obj_t *pTypeLabel;
    lv_obj_t *pSourceBookLabel;

    /* Data */
    const char *pName;
    uint16_t sChallengeRating;
    const char *pSize;
    const char *pType;
    const char *pSourceBook;
} CreatureHeader;

/*********************
 *  Global Prototypes
 *********************/
CreatureHeader *gpCreateCreatureHeader( lv_obj_t *pParent 
                                      , const char *pName
                                      , uint16_t sChallengeRating
                                      , const char *pSize
                                      , const char *pType
                                      , const char *pSourceBook );

#endif  /* CREATURE_HEADER_H */
