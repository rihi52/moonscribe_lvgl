#ifndef CREATURE_DATA_H
#define CREATURE_DATA_H
#include "lvgl/lvgl.h"

#define LONG_TEXT   1024
#define MEDIUM_TEXT 256
#define SHORT_TEXT  64
#define MAX_ACTIONS 15

/*********************
 *  Typedefs
 *********************/
typedef struct {
    char Name[SHORT_TEXT];
    char Desc[LONG_TEXT];
} Action;

typedef struct
{
    char Name[SHORT_TEXT];
    char ChallengeRating[SHORT_TEXT];
    char Size[SHORT_TEXT];
    char Type[SHORT_TEXT];
    char Alignment[SHORT_TEXT];
    uint16_t sExp;
    uint16_t sAc;
    uint16_t sInit;
    uint16_t sHp;
    uint16_t sPb;
    uint16_t sWalkSpeed;
    uint16_t sFlySpeed;
    uint16_t sSwimSpeed;
    uint16_t sClimbSpeed;
    uint16_t sBurrowSpeed;

    uint16_t sStrScore;
    uint16_t sIntScore;
    uint16_t sDexScore;
    uint16_t sWisScore;
    uint16_t sConScore;
    uint16_t sChaScore;

    char DmgResist[MEDIUM_TEXT];
    char DmgImmune[MEDIUM_TEXT];
    char ConditionImmune[MEDIUM_TEXT];
    char Senses[MEDIUM_TEXT];
    char Skills[MEDIUM_TEXT];
    char Languages[MEDIUM_TEXT];

    Action Actions[MAX_ACTIONS];
    Action BonusActions[MAX_ACTIONS];
    Action Reactions[MAX_ACTIONS];
    Action Villain[MAX_ACTIONS];
    Action Legendary[MAX_ACTIONS];
    Action Lair[MAX_ACTIONS];
    Action RegionalEffect[MAX_ACTIONS];

} CreatureData;

/*********************
 *  Global Prototypes
 *********************/

#endif  /* CREATURE_DATA_H */
