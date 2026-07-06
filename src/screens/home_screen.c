#include <stdlib.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "home_screen.h"
#include "../styles.h"
#include "../components/button.h"

/*********************
 *  Local Variables
 *********************/
static lv_color_t background;

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pHomeScreen;

/*********************
 *  Global Functions
 *********************/

void gvHome_screen(void) {
    pHomeScreen = lv_obj_create(NULL);
    lv_obj_add_style(pHomeScreen, &gHomeScreenStyle, 0);
    lv_obj_set_align(pHomeScreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(pHomeScreen, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_style_flex_main_place(pHomeScreen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(pHomeScreen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(pHomeScreen, LV_FLEX_ALIGN_CENTER, 0);

    lv_screen_load(pHomeScreen);

    lv_obj_t *pHomeScreenHeadLabel = lv_label_create(pHomeScreen);
    lv_label_set_text(pHomeScreenHeadLabel, "MOONSCRIBE");
    lv_obj_center(pHomeScreenHeadLabel);

    lv_obj_t *pCombatButton = lv_button_create(pHomeScreen);
    lv_obj_t *pCombatButtonLabel = lv_label_create(pCombatButton);
    lv_obj_center(pCombatButtonLabel);
    lv_label_set_text(pCombatButtonLabel, "Combat");
}
