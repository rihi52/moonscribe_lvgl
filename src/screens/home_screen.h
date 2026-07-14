#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include "lvgl/lvgl.h"

/*********************
 *  Global Variables
 *********************/
extern lv_obj_t * pHomeScreen;

/*********************
 *  Global Prototypes
 *********************/
void gvHomeScreenCreate( lv_event_cb_t EncountersButtonCallback
                       , lv_event_cb_t PlayersButtonCallback
                       , lv_event_cb_t CreaturesButtonCallback );

#endif /* HOME_SCREEN_H */
