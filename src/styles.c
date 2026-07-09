#include "lvgl/lvgl.h"

/*********************
 *  Static Variables
 *********************/
/* Fonts */


/* Colors */
lv_color_t Background;
lv_color_t Primary;
// static lv_color_t

/* Radii */
static uint16_t NoRadius       = 0;
static uint16_t SmallRadius    = 8;
static uint16_t MediumRadius   = 16;
static uint16_t LargeRadius    = 24;

/* Booleans */
static bool inited = false;

/*********************
 *  Global Variables
 *********************/
/* Styles */
lv_style_t gBackgroundFlexColumnScreenStyle;
lv_style_t gBackgroundFlexRowScreenStyle;
lv_style_t gHomeScreenStyle;
lv_style_t gHomeScreenButtonStyle;
lv_style_t gTabViewStyle;
lv_style_t gGeneralStyle;

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
        lv_style_init(&gBackgroundFlexColumnScreenStyle);
        lv_style_init(&gBackgroundFlexRowScreenStyle);
        lv_style_init(&gGeneralStyle);

        /* Define styles */
        lv_style_set_bg_color(&gGeneralStyle, Background);
        lv_style_set_radius(&gGeneralStyle, NoRadius);
        lv_style_set_border_width(&gGeneralStyle, NoRadius);

        /* Common Flex Column Style */
        lv_style_set_flex_flow(&gBackgroundFlexColumnScreenStyle, LV_FLEX_FLOW_COLUMN);
        lv_style_set_layout(&gBackgroundFlexColumnScreenStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gBackgroundFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&gBackgroundFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gBackgroundFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_row(&gBackgroundFlexColumnScreenStyle, 0);

        /* Common Flex Row Style */
        lv_style_set_flex_flow(&gBackgroundFlexRowScreenStyle, LV_FLEX_FLOW_ROW);
        lv_style_set_layout(&gBackgroundFlexRowScreenStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gBackgroundFlexRowScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&gBackgroundFlexRowScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gBackgroundFlexRowScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&gBackgroundFlexRowScreenStyle, 0);

        /* Home Screen Specific Styles */
        lv_style_set_bg_color(&gHomeScreenStyle, Background);

        lv_style_set_bg_color(&gHomeScreenButtonStyle, Primary);
        lv_style_set_radius(&gHomeScreenButtonStyle, MediumRadius);
        lv_style_set_margin_ver(&gHomeScreenButtonStyle, SmallRadius);

        inited = true;
    }
}
