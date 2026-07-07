#include "lvgl/lvgl.h"
#include "creatures_screen.h"

/*********************
 *  Local Variables
 *********************/

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pCreaturesScreen;

/*********************
 *  Global Functions
 *********************/
void gvCreaturesScreenCreate(void) {
    pCreaturesScreen = lv_obj_create(NULL);

    if (lv_screen_active() != pCreaturesScreen){
        lv_screen_load(pCreaturesScreen);
    }
    
}