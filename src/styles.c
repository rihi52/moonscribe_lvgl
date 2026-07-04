#include "lvgl/lvgl.h"

/*********************
 *  Static Variables
 *********************/
/* Colors */
static lv_color_t background;
static bool inited = false;

/*********************
 *  Global Variables
 *********************/
/* Styles */
lv_style_t gHomeScreenStyle;
lv_style_t gHomeScreenStyle;


void gvStylesInit(void){
    /* Colors */
    background = lv_color_make(36, 36, 36);

    /* Styles */
    if (!inited) {
        lv_style_init(&gHomeScreenStyle);
        lv_style_set_bg_color(&gHomeScreenStyle, background);

        lv_style_init(&gHomeScreenStyle);
        inited = true;
    }
}
