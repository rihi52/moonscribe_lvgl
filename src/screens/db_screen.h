#ifndef DB_SCREEN_H
#define DB_SCREEN_H

/*********************
 *  Global Variables
 *********************/
extern lv_obj_t * pDbScreen;

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
void gvDBScreenCreate(void);

#endif  /* PLAYERS_SCREEN_H */
