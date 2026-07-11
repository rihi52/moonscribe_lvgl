#include "lvgl/lvgl.h"
#include "../global.h"
#include "../styles.h"
#include "sidebar.h"
#include "buttons.h"

/*********************
 *  Global Functions
 *********************/
Sidebar *pCreateSidebar(lv_obj_t *pParent, lv_event_cb_t BrowseButtonCallback, lv_event_cb_t EditButtonCallback) {
    Sidebar *pCreatedSidebar = lv_malloc(sizeof(*pCreatedSidebar));

    pCreatedSidebar->pSidebarContainer = lv_obj_create(pParent);
    lv_obj_add_style(pCreatedSidebar->pSidebarContainer, &gGeneralStyle, 0);
    lv_obj_add_style(pCreatedSidebar->pSidebarContainer, &gSidebarStyle, 0);
    lv_obj_set_size(pCreatedSidebar->pSidebarContainer, lv_pct(20), lv_pct(100));

    pCreatedSidebar->pBrowseButton = gpSidebarButton(pCreatedSidebar->pSidebarContainer, "Browse");
    lv_obj_add_event_cb(pCreatedSidebar->pBrowseButton, BrowseButtonCallback, LV_EVENT_ALL, NULL);

    pCreatedSidebar->pEditButton = gpSidebarButton(pCreatedSidebar->pSidebarContainer, "Edit");
    lv_obj_add_event_cb(pCreatedSidebar->pEditButton, EditButtonCallback, LV_EVENT_ALL, NULL);

    return pCreatedSidebar;
}
