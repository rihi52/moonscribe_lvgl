#ifndef DB_SCREEN_H
#define DB_SCREEN_H

/*********************
 *  Global Variables
 *********************/
extern lv_obj_t * pDbScreen;

typedef struct
{
    lv_obj_t *pSidebarContainer;
    lv_obj_t *pBrowseButton;
    lv_obj_t *pEditButton;
} Sidebar;

typedef struct
{
    lv_obj_t *pOverallContainer;
    lv_obj_t *pHeader;
    lv_obj_t *pHomeButton;
    lv_obj_t *pHomeLabel;
    lv_obj_t *pLowerContainer;
    Sidebar *pSidebar;
    lv_obj_t *pMainViewContainer;
} DbScreen;

/*********************
 *  Global Prototypes
 *********************/
void gvDbScreenInit(DbScreen *pScreenInit, Sidebar *pSidebarInit);
void gvDbScreenBuild( DbScreen *pScreen
                    , lv_event_cb_t BrowseButtonCallback
                    , lv_event_cb_t EditButtonCallback
                    , lv_event_cb_t HomeButtonCallback
                    , const char *WindowLabel );
void vDbBrowsePage(lv_obj_t *pParent, const char *WindowLabel);
void vDbEditPage(lv_obj_t *pParent, const char *WindowLabel);

void SidebarInit(Sidebar *pSidebarToInit);
void pSidebarBuild(Sidebar *pSidebarToBuild
                  , lv_obj_t *pParent
                  , DbScreen *pParentScreen
                  , lv_event_cb_t BrowseButtonCallback
                  , lv_event_cb_t EditButtonCallback );

#endif  /* PLAYERS_SCREEN_H */
