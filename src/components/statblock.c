#include "lvgl/lvgl.h"
#include "../global.h"
#include "../styles.h"
#include "buttons.h"
#include "statblock.h"
#include "../data/creature_data.h"

/*********************
 *  Static prototypes
 *********************/


/*********************
 *  Global functions
 *********************/

void gvCreateStatblockView(StatblockView *pView, CreatureData *pData)
{
    /* Variables needed to concatenate strings */
    char xBuffer[MEDIUM_TEXT];

    /* Overall container */
    pView->pOverallContainer = lv_obj_create(lv_screen_active);
    lv_obj_set_size(pView->pOverallContainer, lv_pct(100), lv_pct(100));
    lv_obj_add_style(pView->pOverallContainer, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_style_radius(pView->pOverallContainer, SmallValue, 0);

    /* Top Section */
    pView->pNameChallengeTypeContainer = lv_obj_create(pView->pOverallContainer);
    lv_obj_add_style(pView->pNameChallengeTypeContainer, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_style_radius(pView->pNameChallengeTypeContainer, SmallValue, 0);

    /* First row in top section */
    pView->pNameChallengeRow = lv_obj_create(pView->pOverallContainer);
    lv_obj_add_style(pView->pNameChallengeRow, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_set_style_radius(pView->pNameChallengeRow, SmallValue, 0);

    pView->pNameLabel = lv_label_create(pView->pNameChallengeRow);
    lv_label_set_text(pView->pNameLabel, pData->Name);

    pView->pChallengeRatingLabel = lv_label_create(pView->pNameChallengeRow);
    lv_label_set_text(pView->pChallengeRatingLabel, pData->ChallengeRating);

    /* Second row in top section */
    pView->pSizeTypeAlignmentExpRow = lv_obj_create(pView->pNameChallengeRow);
    lv_obj_add_style(pView->pSizeTypeAlignmentExpRow, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_set_style_radius(pView->pSizeTypeAlignmentExpRow, SmallValue, 0);

    pView->pSizeTypeAlignmentLabel = lv_label_create(pView->pSizeTypeAlignmentExpRow);
    lv_label_set_text_fmt(pView->pSizeTypeAlignmentLabel, "%s %s, %s", pData->Size, pData->Type, pData->Alignment);

}

void gvAttachStatBlockView(lv_obj_t *pParent, StatblockView *pView)
{

}

/*********************
 *  Static functions
 *********************/
