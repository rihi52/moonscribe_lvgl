#ifndef     STYLES_H
#define     STYLES_H
#include "lvgl/lvgl.h"

/*********************
 *  Global Variables
 *********************/
/* Colors */
extern lv_color_t Background;
extern lv_color_t Primary;

/* Styles */
extern lv_style_t gBackgroundFlexColumnScreenStyle;
extern lv_style_t gBackgroundFlexRowScreenStyle;
extern lv_style_t gHomeScreenStyle;
extern lv_style_t gHomeScreenButtonStyle;
extern lv_style_t gTabViewStyle;
extern lv_style_t gGeneralStyle;

/*********************
 *  Global Prototypes
 *********************/
void gvStylesInit(void);

#endif
