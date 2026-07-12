#include "lvgl/lvgl.h"
#include "../global.h"
#include "../styles.h"
#include "sidebar.h"
#include "buttons.h"

/*********************
 *  Global Functions
 *********************/
void SidebarInit(Sidebar *pSidebarToInit)
{
    pSidebarToInit->pBrowseButton = NULL;
    pSidebarToInit->pEditButton = NULL;
    pSidebarToInit->pSidebarContainer = NULL;
}

void pSidebarBuild(Sidebar *pSidebarToBuild, lv_obj_t *pParent, lv_event_cb_t BrowseButtonCallback, lv_event_cb_t EditButtonCallback)
{

    pSidebarToBuild->pSidebarContainer = lv_obj_create(pParent);
    lv_obj_add_style(pSidebarToBuild->pSidebarContainer, &gGeneralStyle, 0);
    lv_obj_add_style(pSidebarToBuild->pSidebarContainer, &gSidebarStyle, 0);
    lv_obj_set_size(pSidebarToBuild->pSidebarContainer, lv_pct(20), lv_pct(100));

    pSidebarToBuild->pBrowseButton = gpSidebarButton(pSidebarToBuild->pSidebarContainer, "Browse");
    lv_obj_add_event_cb(pSidebarToBuild->pBrowseButton, BrowseButtonCallback, LV_EVENT_ALL, NULL);

    pSidebarToBuild->pEditButton = gpSidebarButton(pSidebarToBuild->pSidebarContainer, "Edit");
    lv_obj_add_event_cb(pSidebarToBuild->pEditButton, EditButtonCallback, LV_EVENT_ALL, NULL);
}
