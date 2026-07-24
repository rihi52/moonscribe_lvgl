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
    bool isSpeedAdded = false;

    /* Array of the types of speed - 1 because walk is not used in statblocks */
    char *SpeedNames[SPEED_TYPES-1] = {
        "burrow",
        "climb",
        "fly",
        "swim"
    };

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
    pView->pNameChallengeRow = lv_obj_create(pView->pNameChallengeTypeContainer);
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

    pView->pSizeTypeAlignmentLabel = lv_label_create(pView->pSizeTypeAlignmentExpRow);
    lv_label_set_text_fmt(pView->pSizeTypeAlignmentLabel, "%d", pData->sExp);

    // TODO: Add some kind of divider here in the UI

    /* Second container */
    pView->AcHpInitPbSpeedContainer = lv_obj_create(pView->pOverallContainer);
    lv_obj_add_style(pView->AcHpInitPbSpeedContainer, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_style_radius(pView->AcHpInitPbSpeedContainer, SmallValue, 0);

     pView->pAcInitRow = lv_obj_create(pView->AcHpInitPbSpeedContainer);
    lv_obj_add_style(pView->pAcInitRow, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_set_style_radius(pView->pAcInitRow, SmallValue, 0);

    pView->pAcLabel = lv_label_create(pView->pAcInitRow);
    lv_label_set_text_fmt(pView->pNameLabel, "%d", pData->sAc);

    pView->pInitLabel = lv_label_create(pView->pAcInitRow);
    lv_label_set_text_fmt(pView->pChallengeRatingLabel, "%d", pData->sInit);

    /* Second row in second section */
    pView->pHpPbRow = lv_obj_create(pView->AcHpInitPbSpeedContainer);
    lv_obj_add_style(pView->pHpPbRow, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_set_style_radius(pView->pHpPbRow, SmallValue, 0);

    pView->pHpLabel = lv_label_create(pView->pHpPbRow);
    lv_label_set_text_fmt(pView->pHpLabel, "%d", pData->sHp);

    pView->pPbLabel = lv_label_create(pView->pHpPbRow);
    lv_label_set_text_fmt(pView->pPbLabel, "%d", pData->sPb);

    /* Third row in second section */
    pView->pSpeedRow = lv_obj_create(pView->AcHpInitPbSpeedContainer);
    lv_obj_add_style(pView->pSpeedRow, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_set_style_radius(pView->pSpeedRow, SmallValue, 0);

    pView->pSpeedLabel = lv_label_create(pView->pSpeedRow);
    lv_label_set_text(pView->pSpeedLabel, "Speed: ");

    for (int i = 0; i < SPEED_TYPES; i++)
    {
        /* Speed is not used, continue through without using it */
        if (0 == pData->sSpeedTypes[i]) continue;

        if (WALK_SPEED == i)
        {   /* Write the formatted speed to the buffer (repeated in each condition) */
            lv_snprintf(xBuffer, sizeof(xBuffer), "%d ft.", pData->sSpeedTypes[i]);
        }
        else if (isSpeedAdded)
        {   /* The -1 here is to account for the offset in SpeedNames compared to pData->sSpeedTypes */
            lv_snprintf(xBuffer, sizeof(xBuffer), ", %s %d ft.", SpeedNames[i - 1], pData->sSpeedTypes[i]);
        }
        else
        {   /* The -1 here is to account for the offset in SpeedNames compared to pData->sSpeedTypes */
            lv_snprintf(xBuffer, sizeof(xBuffer), "%s %d ft.", SpeedNames[i - 1], pData->sSpeedTypes[i]);
        }

        /* Insert the buffer to the end of the label */
        lv_label_ins_text(pView->pSpeedLabel, LV_LABEL_POS_LAST, xBuffer);
        /* If this has been reached then a speed has been added, so switch the boolean to true */
        isSpeedAdded = true;
        /* Clear the buffer just to make sure no garbage makes it through */
        lv_memset(xBuffer, 0, sizeof(xBuffer));
    }

}

void gvAttachStatBlockView(lv_obj_t *pParent, StatblockView *pView)
{

}

/*********************
 *  Static functions
 *********************/
