#include "lvgl/lvgl.h"

/*********************
 *  Static Variables
 *********************/
/* Fonts */


/* Colors */
lv_color_t Background;
lv_color_t Primary;
lv_color_t SelectedButton;
lv_color_t White;

/* Standard values for styling */
static uint16_t NoValue        = 0;
static uint16_t SmallValue     = 8;
static uint16_t MediumValue    = 16;
static uint16_t LargeValue     = 24;

/* Booleans */
static bool inited = false;

/*********************
 *  Global Variables
 *********************/
/* Styles */
lv_style_t gHeaderStyle;
lv_style_t gSidebarStyle;

/* Screens */
lv_style_t gBackgroundFlexColumnScreenStyle;
lv_style_t gBackgroundFlexRowScreenStyle;

/* Buttons */
lv_style_t gHomeScreenButtonStyle;
lv_style_t gSidebarDefaultButtonStyle;
lv_style_t gSidebarSelectedButtonStyle;

/* Common */
lv_style_t gGeneralStyle;

/*********************
 *  Global functions
 *********************/

void gvStylesInit(void){
    /* Colors */
    Background      = lv_color_make(36, 36, 36);
    Primary         = lv_color_make(68, 22, 148);
    SelectedButton  = lv_color_make(50, 50, 50);
    White           = lv_color_white();

    /* Styles */
    if (!inited) {
        /* Initialize styles */
        lv_style_init(&gHeaderStyle);
        lv_style_init(&gSidebarStyle);
        lv_style_init(&gBackgroundFlexColumnScreenStyle);
        lv_style_init(&gBackgroundFlexRowScreenStyle);
        lv_style_init(&gHomeScreenButtonStyle);
        lv_style_init(&gSidebarDefaultButtonStyle);
        lv_style_init(&gSidebarSelectedButtonStyle);
        lv_style_init(&gGeneralStyle);

        /* Define styles */
        lv_style_set_bg_color(&gGeneralStyle, Background);
        lv_style_set_radius(&gGeneralStyle, NoValue);
        lv_style_set_border_width(&gGeneralStyle, NoValue);

        /* Header Style */
        lv_style_set_border_color(&gHeaderStyle, White);
        lv_style_set_border_side(&gHeaderStyle, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_width(&gHeaderStyle, 1);
        lv_style_set_flex_flow(&gHeaderStyle, LV_FLEX_FLOW_ROW);
        lv_style_set_layout(&gHeaderStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gHeaderStyle, LV_FLEX_ALIGN_START);
        lv_style_set_flex_cross_place(&gHeaderStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gHeaderStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_all(&gHeaderStyle, 0);
        lv_style_set_pad_column(&gHeaderStyle, 0);

        /* Sidebar Style */
        lv_style_set_border_color(&gSidebarStyle, White);
        lv_style_set_border_side(&gSidebarStyle, LV_BORDER_SIDE_RIGHT);
        lv_style_set_border_width(&gSidebarStyle, 1);
        lv_style_set_flex_flow(&gSidebarStyle, LV_FLEX_FLOW_COLUMN);
        lv_style_set_layout(&gSidebarStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gSidebarStyle, LV_FLEX_ALIGN_START);
        lv_style_set_flex_cross_place(&gSidebarStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gSidebarStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_all(&gSidebarStyle, 0);
        lv_style_set_pad_row(&gSidebarStyle, 0);

        /* Common flex column style */
        lv_style_set_flex_flow(&gBackgroundFlexColumnScreenStyle, LV_FLEX_FLOW_COLUMN);
        lv_style_set_layout(&gBackgroundFlexColumnScreenStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gBackgroundFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&gBackgroundFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gBackgroundFlexColumnScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_row(&gBackgroundFlexColumnScreenStyle, 0);

        /* Common flex row style */
        lv_style_set_flex_flow(&gBackgroundFlexRowScreenStyle, LV_FLEX_FLOW_ROW);
        lv_style_set_layout(&gBackgroundFlexRowScreenStyle, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&gBackgroundFlexRowScreenStyle, LV_FLEX_ALIGN_START);
        lv_style_set_flex_cross_place(&gBackgroundFlexRowScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&gBackgroundFlexRowScreenStyle, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&gBackgroundFlexRowScreenStyle, 0);

        /* Button styles */
        lv_style_set_bg_color(&gHomeScreenButtonStyle, Primary);
        lv_style_set_radius(&gHomeScreenButtonStyle, MediumValue);
        lv_style_set_margin_ver(&gHomeScreenButtonStyle, SmallValue);

        /* Default sidebar button */
        lv_style_set_bg_color(&gSidebarDefaultButtonStyle, Background);
        lv_style_set_bg_opa(&gSidebarDefaultButtonStyle, LV_OPA_COVER);
        lv_style_set_radius(&gSidebarDefaultButtonStyle, NoValue);
        lv_style_set_margin_ver(&gSidebarDefaultButtonStyle, NoValue);

        /* Selected sidebar button*/
        lv_style_set_bg_color(&gSidebarSelectedButtonStyle, SelectedButton);
        lv_style_set_bg_opa(&gSidebarSelectedButtonStyle, LV_OPA_COVER);
        lv_style_set_radius(&gSidebarSelectedButtonStyle, NoValue);
        lv_style_set_margin_ver(&gSidebarSelectedButtonStyle, NoValue);

        inited = true;
    }
}
