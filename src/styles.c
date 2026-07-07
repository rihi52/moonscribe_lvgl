#include "lvgl/lvgl.h"

/*********************
 *  Static Variables
 *********************/
/* Fonts */


/* Colors */
static lv_color_t Background;
static lv_color_t Primary;

/* Radii */
static uint16_t SmallRadius    = 8;
static uint16_t MediumRadius   = 16;
static uint16_t LargeRadius    = 24;

/* Booleans */
static bool inited = false;

/*********************
 *  Global Variables
 *********************/
/* Styles */
lv_style_t gHomeScreenStyle;
lv_style_t gHomeScreenButtonStyle;


void gvStylesInit(void){
    /* Colors */
    Background  = lv_color_make(36, 36, 36);
    Primary     = lv_color_make(68, 22, 148);

    /* Styles */
    if (!inited) {
        /* Initialize styles */
        lv_style_init(&gHomeScreenStyle);
        lv_style_init(&gHomeScreenButtonStyle);

        /* Define styles */
        lv_style_set_bg_color(&gHomeScreenStyle, Background);

        lv_style_set_bg_color(&gHomeScreenButtonStyle, Primary);
        lv_style_set_radius(&gHomeScreenButtonStyle, MediumRadius);
        lv_style_set_margin_ver(&gHomeScreenButtonStyle, SmallRadius);

        inited = true;
    }
}
