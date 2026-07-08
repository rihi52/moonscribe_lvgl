#ifndef     STYLES_H
#define     STYLES_H
#include "lvgl/lvgl.h"

/*********************
 *  Global Variables
 *********************/
extern lv_style_t gCommonFlexColumnScreenStyle;
extern lv_style_t gHomeScreenStyle;
extern lv_style_t gHomeScreenButtonStyle;
extern lv_style_t gTabViewStyle;

/*********************
 *  Global Prototypes
 *********************/
void gvStylesInit(void);

#endif
