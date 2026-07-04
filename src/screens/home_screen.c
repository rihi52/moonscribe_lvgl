#include <stdlib.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "home_screen.h"
#include "../styles.h"

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

    lv_screen_load(pHomeScreen);

    lv_obj_t *pHomeScreenHeadLabel = lv_label_create(pHomeScreen);
    lv_label_set_text(pHomeScreenHeadLabel, "MOONSCRIBE");
    lv_obj_center(pHomeScreenHeadLabel);
}
