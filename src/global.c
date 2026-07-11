#include <stdlib.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "styles.h"
#include "screens/creatures_screen.h"
#include "screens/players_screen.h"
#include "screens/home_screen.h"

/*********************
 *  Global Functions
 *********************/
/* Screen switch callbacks */
void gvActivateCreaturesScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED)
    {
        gvCreaturesScreenCreate();
        lv_obj_delete(pHomeScreen);
    }
}

void gvActivatePlayersScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED)
    {
        gvPlayersScreenCreate();
        lv_obj_delete(pHomeScreen);
    }
}

void gvActivateHomeScreen_eventcb(lv_event_t *e)
{
    lv_obj_t *object = lv_event_get_target(e);
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(object, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(object, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        gvHomeScreenCreate();
        lv_obj_delete(pCreaturesScreen);
    }
}
