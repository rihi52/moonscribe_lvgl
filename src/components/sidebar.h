#ifndef     SIDEBAR_H
#define     SIDEBAR_H
#include "lvgl/lvgl.h"

/*********************
 *  Global Variables
 *********************/
typedef struct
{
    lv_obj_t *pSidebarContainer;
    lv_obj_t *pBrowseButton;
    lv_obj_t *pEditButton;
} Sidebar;

/*********************
 *  Global Prototypes
 *********************/
void SidebarInit(Sidebar *pSidebarToInit);
void pSidebarBuild(Sidebar *pSidebarToBuild
                  , lv_obj_t *pParent
                  , lv_event_cb_t BrowseButtonCallback
                  , lv_event_cb_t EditButtonCallback );

#endif /* SIDEBAR_H */
