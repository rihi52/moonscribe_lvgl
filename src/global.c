#include <stdlib.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "screens/creatures_screen.h"

/*********************
 *  Global Functions
 *********************/
/* Screen switch callbacks */
void gvActivateCreaturesScreen_eventcb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED){
        gvCreaturesScreenCreate();
    }
}
