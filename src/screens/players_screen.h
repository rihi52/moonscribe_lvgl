#ifndef PLAYERS_SCREEN_H
#define PLAYERS_SCREEN_H

/*********************
 *  Global Variables
 *********************/
extern lv_obj_t * pPlayersScreen;

typedef struct
{
    lv_obj_t *pScreen;
    lv_obj_t *pHeader;
    lv_obj_t *pHomeContainer;
    lv_obj_t *pHomeLabel;
    lv_obj_t *pLowerContainer;
    Sidebar *pSidebar;
    lv_obj_t *pMainViewContainer;
} DbScreen;

/*********************
 *  Global Prototypes
 *********************/
void gvPlayersScreenCreate(void);

#endif  /* PLAYERS_SCREEN_H */
