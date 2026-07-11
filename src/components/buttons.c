#include "lvgl/lvgl.h"
#include "../styles.h"
#include "buttons.h"

/*********************
 *  Global Functions
 *********************/
lv_obj_t *gpMainButton(lv_obj_t *pParent, const char *pButtonLabel) {
    lv_obj_t *pCreatedButton = lv_button_create(pParent);
    lv_obj_add_style(pCreatedButton, &gHomeScreenButtonStyle, 0);
    lv_obj_set_size(pCreatedButton, 300, 50);
    lv_obj_center(pCreatedButton);

    lv_obj_t *pCreatedLabel = lv_label_create(pCreatedButton);
    lv_label_set_text(pCreatedLabel, pButtonLabel);
    lv_obj_set_style_text_font(pCreatedLabel, &Metamorphous_24, 0);
    lv_obj_center(pCreatedLabel);

    return pCreatedButton;
}

lv_obj_t *gpSidebarButton(lv_obj_t *pParent, const char *pButtonLabel) {
    lv_obj_t *pCreatedButton = lv_button_create(pParent);
    lv_obj_remove_style_all(pCreatedButton);
    lv_obj_set_size(pCreatedButton, lv_pct(100), 75);
    lv_obj_center(pCreatedButton);
    lv_obj_add_style(pCreatedButton, &gSidebarDefaultButtonStyle, 0);
    lv_obj_add_style(pCreatedButton, &gSidebarSelectedButtonStyle, LV_STATE_CHECKED);

    lv_obj_t *pCreatedLabel = lv_label_create(pCreatedButton);
    lv_label_set_text(pCreatedLabel, pButtonLabel);
    lv_obj_set_style_text_font(pCreatedLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pCreatedLabel, White, 0);
    lv_obj_center(pCreatedLabel);

    return pCreatedButton;
}
