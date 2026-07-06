#include "lvgl/lvgl/h"
#include "button.h"

/*********************
 *  Global Functions
 *********************/
lv_obj_t *gpMainButton(lv_obj_t *pParent, const char *pButtonLabel) {
    lv_obj_t *pCreatedButton = lv_button_create(pParent);
    lv_obj_t *pCreatedLabel = lv_label_create(pCreatedButton);
    lv_label_set_text(pCreatedLable, pButtonLabel);

    return pCreatedButton;
}