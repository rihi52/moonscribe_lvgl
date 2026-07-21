#ifndef STATBLOCK_H
#define STATBLOCK_H
#include "lvgl/lvgl.h"

/*********************
 *  Global Prototypes
 *********************/
typedef struct
{
    lv_obj_t *pOverallContainer;

    /* Section for name, challenge rating, exp, type, and alignment */
    lv_obj_t *pNameChallengeTypeContainer;
    lv_obj_t *pNameChallengeRow;
    lv_obj_t *pNameLabel;
    lv_obj_t *pChallengeRatingLabel;
    lv_obj_t *pTypeAlignmentExpRow;
    lv_obj_t *pTypeLabel;
    lv_obj_t *pAlignmentLabel;
    lv_obj_t *pExpLabel;

    /* Section for Armor Class, Hit Points, Initiative, Proficiency Bonus, and Speed */
    lv_obj_t *AcHpInitPbSpeedContainer;
    lv_obj_t *pAcInitRow;
    lv_obj_t *pAcLabel;
    lv_obj_t *pHpLabel;
    lv_obj_t *pHpPbRow;
    lv_obj_t *pHpLabel;
    lv_obj_t *pPbLabel;
    lv_obj_t *pSpeedRow;
    lv_obj_t *pSpeedLabel;

    /* Section for Ability Scores and Saves */
    lv_obj_t *pAbilityScoresSavesContainer;
    /* Strength and Intelligence */
    lv_obj_t *StrIntColumn;
    lv_obj_t *StrIntScoreColumn;
    lv_obj_t *pStrScoreLabel;
    lv_obj_t *pIntScoreLabel;
    lv_obj_t *StrIntModColumn;
    lv_obj_t *pStrModLabel;
    lv_obj_t *pIntModLabel;
    lv_obj_t *StrIntSaveColumn;
    lv_obj_t *pStrSaveLabel;
    lv_obj_t *pIntSaveLabel;
    /* Dexterity and Wisdom */
    lv_obj_t *DexWisColumn;
    lv_obj_t *DexWisScoreColumn;
    lv_obj_t *pDexScoreLabel;
    lv_obj_t *pWisScoreLabel;
    lv_obj_t *DexWisModColumn;
    lv_obj_t *pDexModLabel;
    lv_obj_t *pWisModLabel;
    lv_obj_t *DexWisSaveColumn;
    lv_obj_t *pDexSaveLabel;
    lv_obj_t *pWisSaveLabel;
    /* Constitution and Charisma */
    lv_obj_t *ConChaColumn;
    lv_obj_t *ConChaScoreColumn;
    lv_obj_t *pConScoreLabel;
    lv_obj_t *pChaScoreLabel;
    lv_obj_t *ConChaModColumn;
    lv_obj_t *pConModLabel;
    lv_obj_t *pChaModLabel;
    lv_obj_t *ConChaSaveColumn;
    lv_obj_t *pConSaveLabel;
    lv_obj_t *pChaSaveLabel;

    /* Section for Damage Resistances and Immunities, Condition Immunities, Senses, Skills, and Languages */
    lv_obj_t *pResistImmuneSenseSkillLanguageContainer;
    lv_obj_t *pDmgResistRow;
    lv_obj_t *pDmgResistLabel;
    lv_obj_t *pDmgImmuneRow;
    lv_obj_t *pDmgImmuneLabel;
    lv_obj_t *pConditionImmuneRow;
    lv_obj_t *pConditionImmuneLabel;
    lv_obj_t *pSensesRow;
    lv_obj_t *pSensesLabel;
    lv_obj_t *pSkillsRow;
    lv_obj_t *pSkillsLabel;
    lv_obj_t *pLanguagesRow;
    lv_obj_t *pLanguageLabel;

    /* Section for Traits */
    lv_obj_t *pTraitsContainer;

    /* Section for Actions */
    lv_obj_t *pActionsContainer;

    /* Section for Bonus Actions */
    lv_obj_t *pBonusActionsContainer;

    /* Section for Reactions */
    lv_obj_t *pReactionsContainer;

    /* Section for Villain Actions */
    lv_obj_t *pVillainActionsContainer;

    /* Section for Legendary Actions */
    lv_obj_t *pLegendaryActionsContainer;

    /* Section for Lair Actions */
    lv_obj_t *pLairActionsContainer;

    /* Section for Regional Effects */
    lv_obj_t *pRegionalEffectsContainer;

} StatblockView;


#endif  /* STATBLOCK_H */
