#include "lvgl/lvgl.h"

/*********************
 *  Static Variables
 *********************/
/* Fonts */


/* Colors */
static lv_color_t Background;
static lv_color_t Primary;
// static lv_color_t

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
lv_style_t gCommonFlexColumnScreenStyle;
lv_style_t gHomeScreenStyle;
lv_style_t gHomeScreenButtonStyle;
lv_style_t gTabViewStyle;

/*********************
 *  Global functions
 *********************/

void gvStylesInit(void){
    /* Colors */
    Background  = lv_color_make(36, 36, 36);
    Primary     = lv_color_make(68, 22, 148);

    /* Styles */
    if (!inited) {
        /* Initialize styles */
        lv_style_init(&gHomeScreenStyle);
        lv_style_init(&gHomeScreenButtonStyle);
        lv_style_init(&gCommonFlexColumnScreenStyle);

        /* Define styles */
        /* Common Screen Style */
        lv_style_set_flex_flow(&gCommonFlexColumnScreenStyle, LV_FLEX_FLOW_COLUMN_WRAP);
        lv_style_set_layout(&gCommonFlexColumnScreenStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gCommonFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&gCommonFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gCommonFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);

        /* Home Screen Specific Styles */
        lv_style_set_bg_color(&gHomeScreenStyle, Background);

        lv_style_set_bg_color(&gHomeScreenButtonStyle, Primary);
        lv_style_set_radius(&gHomeScreenButtonStyle, MediumRadius);
        lv_style_set_margin_ver(&gHomeScreenButtonStyle, SmallRadius);

        inited = true;
    }
}
