#include "lvgl/lvgl.h"
#include "creatures_screen.h"
#include "../styles.h"
#include "../components/buttons.h"

/*********************
 *  Local Variables
 *********************/
static lv_obj_t *pCreaturesScreenSideBar;
static lv_obj_t *pCreaturesBrowseButton;
static void gvTestBrowse_eventcb(lv_event_t *e);

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pCreaturesScreen;

/*********************
 *  Global Functions
 *********************/
void gvCreaturesScreenCreate(void) {
    pCreaturesScreen = lv_obj_create(NULL);
    lv_obj_add_style(pCreaturesScreen, &gGeneralStyle, 0);
    lv_obj_add_style(pCreaturesScreen, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_align(pCreaturesScreen, LV_ALIGN_CENTER);
    lv_obj_set_style_pad_all(pCreaturesScreen, 0, 0);

    if (lv_screen_active() != pCreaturesScreen){
        lv_screen_load(pCreaturesScreen);
    }

    lv_obj_t *pCreaturesHeader = lv_obj_create(pCreaturesScreen);
    lv_obj_add_style(pCreaturesHeader, &gGeneralStyle, 0);
    lv_obj_set_size(pCreaturesHeader, lv_pct(100), lv_pct(15));

    lv_obj_t *pCreaturesLowerContainer = lv_obj_create(pCreaturesScreen);
    lv_obj_add_style(pCreaturesLowerContainer, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_add_style(pCreaturesLowerContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pCreaturesLowerContainer, lv_pct(100), lv_pct(85));
    lv_obj_set_style_pad_all(pCreaturesLowerContainer, 0, 0);

    /* Sidebar */
    lv_obj_t *pCreaturesSidebar = lv_obj_create(pCreaturesLowerContainer);
    lv_obj_add_style(pCreaturesSidebar, &gGeneralStyle, 0);
    lv_obj_add_style(pCreaturesSidebar, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_style_pad_all(pCreaturesSidebar, 0, 0);
    lv_obj_set_style_bg_color(pCreaturesSidebar, lv_color_make(255, 0, 0), 0); // Test Property, to be removed
    lv_obj_set_size(pCreaturesSidebar, lv_pct(20), lv_pct(100));

    pCreaturesBrowseButton = gpSidebarButton(pCreaturesSidebar, "Browse");
    lv_obj_add_event_cb(pCreaturesBrowseButton, gvTestBrowse_eventcb, LV_EVENT_CLICKED, NULL);
    lv_obj_t *pCreaturesEditButton = gpSidebarButton(pCreaturesSidebar, "Edit");

    /* Main View */
    lv_obj_t *pCreaturesMain = lv_obj_create(pCreaturesLowerContainer);
    lv_obj_add_style(pCreaturesMain, &gGeneralStyle, 0);
    lv_obj_set_style_bg_color(pCreaturesMain, lv_color_make(0, 255, 0), 0); // Test Property, to be removed
    lv_obj_set_size(pCreaturesMain, lv_pct(80), lv_pct(100));

}

void gvTestBrowse_eventcb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED){
        LV_LOG_USER("checked: %d", lv_obj_has_state(pCreaturesBrowseButton, LV_STATE_CHECKED));
    }
}
