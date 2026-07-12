#ifndef DB_SCREEN_H
#define DB_SCREEN_H
#include "../components/sidebar.h"

/*********************
 *  Global Variables
 *********************/
extern lv_obj_t * pDbScreen;

typedef struct
{
    lv_obj_t *pOverallContainer;
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
void gvDbScreenInit(DbScreen *pScreenInit, Sidebar *pSidebarInit);
void gvDbScreenBuild(DbScreen *pScreen, lv_event_cb_t BrowseButtonCallback, lv_event_cb_t EditButtonCallback);
void vDbBrowsePage(lv_obj_t *pParent);
void vDbEditPage(lv_obj_t *pParent);

#endif  /* PLAYERS_SCREEN_H */
