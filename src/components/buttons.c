#include "lvgl/lvgl.h"
#include "buttons.h"

/*********************
 *  Global Functions
 *********************/
lv_obj_t *gpMainButton(lv_obj_t *pParent, const char *pButtonLabel) {
    lv_obj_t *pCreatedButton = lv_button_create(pParent);
    lv_obj_set_size(pCreatedButton, 300, 50);
    lv_obj_center(pCreatedButton);

    lv_obj_t *pCreatedLabel = lv_label_create(pCreatedButton);
    lv_label_set_text(pCreatedLabel, pButtonLabel);
    lv_obj_center(pCreatedLabel);

    return pCreatedButton;
}
