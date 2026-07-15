#include "lvgl/lvgl.h"
#include "../global.h"
#include "../styles.h"
#include "creature_header.h"

CreatureHeader *gpCreateCreatureHeader( lv_obj_t *pParent
                                      , const char *pName
                                      , uint16_t sChallengeRating
                                      , const char *pSize
                                      , const char *pType
                                      , const char *pSourceBook )
{
    /* Malloc a new struct because how many are needed could change every time */
    CreatureHeader *HeaderToCreate = lv_malloc(sizeof(CreatureHeader));
    /* Buffer used to convert ints to chars */
    char xBuffer[128];

    HeaderToCreate->pName = pName;
    HeaderToCreate->sChallengeRating = sChallengeRating;
    HeaderToCreate->pSize = pSize;
    HeaderToCreate->pType = pType;
    HeaderToCreate->pSourceBook = pSourceBook;

    /* Overall container for header data */
    HeaderToCreate->pHeaderContainer = lv_obj_create(pParent);
    lv_obj_add_style(HeaderToCreate->pHeaderContainer, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_size(HeaderToCreate->pHeaderContainer, 300, 200);

    /* Row to contain the creature name */
    HeaderToCreate->pNameRowContainer = lv_obj_create(HeaderToCreate->pHeaderContainer);
    lv_obj_add_style(HeaderToCreate->pNameRowContainer, &gHeaderRowStyle, 0);
    lv_obj_set_size(HeaderToCreate->pNameRowContainer, lv_pct(100), lv_pct(33));

    /* Label for creature name */
    HeaderToCreate->pNameLabel = lv_label_create(HeaderToCreate->pNameRowContainer);
    lv_label_set_text(HeaderToCreate->pNameLabel, HeaderToCreate->pName);
    lv_obj_set_style_text_font(HeaderToCreate->pNameLabel, &Metamorphous_12, 0);
    lv_obj_set_style_text_color(HeaderToCreate->pNameLabel, White, 0);

    /* Row for the challenge rating and the size of the creature */
    HeaderToCreate->pChallengeRatingSizeRowContainer = lv_obj_create(HeaderToCreate->pHeaderContainer);
    lv_obj_add_style(HeaderToCreate->pChallengeRatingSizeRowContainer, &gHeaderRowStyle, 0);
    lv_obj_set_size(HeaderToCreate->pChallengeRatingSizeRowContainer, lv_pct(100), lv_pct(33));

    /* Label for the challenge rating of the creature */
    HeaderToCreate->pChallengeRatingLabel = lv_label_create(HeaderToCreate->pChallengeRatingSizeRowContainer);
    lv_snprintf(xBuffer,sizeof(xBuffer), "%d", HeaderToCreate->sChallengeRating);
    lv_label_set_text(HeaderToCreate->pChallengeRatingLabel, xBuffer);
    lv_obj_set_style_text_font(HeaderToCreate->pChallengeRatingLabel, &Metamorphous_12, 0);
    lv_obj_set_style_text_color(HeaderToCreate->pChallengeRatingLabel, White, 0);

    /* Label for the size of the creature */
    HeaderToCreate->pSizeLabel = lv_label_create(HeaderToCreate->pChallengeRatingSizeRowContainer);
    lv_label_set_text(HeaderToCreate->pSizeLabel, HeaderToCreate->pSize);
    lv_obj_set_style_text_font(HeaderToCreate->pSizeLabel, &Metamorphous_12, 0);
    lv_obj_set_style_text_color(HeaderToCreate->pSizeLabel, White, 0);

    /* Row for the type of creature and the source book */
    HeaderToCreate->pTypeSourceRowContainer = lv_obj_create(HeaderToCreate->pHeaderContainer);
    lv_obj_add_style(HeaderToCreate->pTypeSourceRowContainer, &gHeaderRowStyle, 0);
    lv_obj_set_size(HeaderToCreate->pTypeSourceRowContainer, lv_pct(100), lv_pct(33));

    /* Lable for the type of the creature */
    HeaderToCreate->pTypeLabel = lv_label_create(HeaderToCreate->pTypeSourceRowContainer);
    lv_label_set_text(HeaderToCreate->pTypeLabel, HeaderToCreate->pType);
    lv_obj_set_style_text_font(HeaderToCreate->pTypeLabel, &Metamorphous_12, 0);
    lv_obj_set_style_text_color(HeaderToCreate->pTypeLabel, White, 0);

    /* Label for the source book of the creature*/
    HeaderToCreate->pSourceBookLabel = lv_label_create(HeaderToCreate->pTypeSourceRowContainer);
    lv_label_set_text(HeaderToCreate->pSourceBookLabel, HeaderToCreate->pSourceBook);
    lv_obj_set_style_text_font(HeaderToCreate->pSourceBookLabel, &Metamorphous_12, 0);
    lv_obj_set_style_text_color(HeaderToCreate->pSourceBookLabel, White, 0);

    return HeaderToCreate;
}
