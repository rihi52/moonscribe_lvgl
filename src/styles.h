#ifndef     STYLES_H
#define     STYLES_H
#include "lvgl/lvgl.h"

/*********************
 *  Global Variables
 *********************/
/* Colors */
extern lv_color_t Background;
extern lv_color_t Primary;
extern lv_color_t SelectedButton;
extern lv_color_t White;

/* Styles */
extern lv_style_t gHeaderStyle;
extern lv_style_t gSidebarStyle;
extern lv_style_t gHeaderRowStyle;
extern lv_style_t gBackgroundFlexColumnScreenStyle;
extern lv_style_t gBackgroundFlexRowScreenStyle;
extern lv_style_t gHomeScreenButtonStyle;
extern lv_style_t gSidebarDefaultButtonStyle;
extern lv_style_t gSidebarSelectedButtonStyle;
extern lv_style_t gGeneralStyle;

/*********************
 *  Global Prototypes
 *********************/
void gvStylesInit(void);

#endif /* STYLES_H */
