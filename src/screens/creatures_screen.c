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

    lv_obj_t *pCreatureWindow = lv_win_create(pCreaturesScreen);
    lv_obj_t *pCreatureMenu = lv_menu_create(pCreatureWindow);
    lv_obj_center(pCreatureMenu);
    lv_obj_set_size(pCreatureMenu,lv_pct(100), lv_pct(100));
    lv_menu_set_mode_root_back_button(pCreatureMenu, LV_MENU_ROOT_BACK_BUTTON_DISABLED);
    lv_obj_t * back_btn = lv_menu_get_main_header_back_button(pCreatureMenu);
    lv_obj_add_flag(back_btn, LV_OBJ_FLAG_HIDDEN);

}
