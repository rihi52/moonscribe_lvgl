#include <stdlib.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "home_screen.h"
#include "../global.h"
#include "../styles.h"
#include "../components/buttons.h"

/*********************
 *  Local Variables
 *********************/

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pHomeScreen;

/*********************
 *  Global Functions
 *********************/

void gvHomeScreenCreate( lv_event_cb_t EncountersButtonCallback
                       , lv_event_cb_t CreaturesButtonCallback
                       , lv_event_cb_t PlayersButtonCallback )
{
    pHomeScreen = lv_obj_create(NULL);
    lv_obj_add_style(pHomeScreen, &gGeneralStyle, 0);
    lv_obj_add_style(pHomeScreen, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_size(pHomeScreen, lv_pct(100), lv_pct(100));
    lv_obj_set_align(pHomeScreen, LV_ALIGN_CENTER);

    if (lv_screen_active() != pHomeScreen)
    {
        lv_screen_load(pHomeScreen);
    }

    lv_obj_t *pHomeScreenHeadLabel = lv_label_create(pHomeScreen);
    lv_label_set_text(pHomeScreenHeadLabel, "MOONSCRIBE");
    lv_obj_set_style_text_font(pHomeScreenHeadLabel, &CinzelDecorativeBold_48, 0);
    lv_obj_set_style_text_color(pHomeScreenHeadLabel, Primary, 0);

    lv_obj_t *pCombatButton = gpMainButton(pHomeScreen, "Combat");
    lv_obj_add_event_cb(pCombatButton, EncountersButtonCallback, LV_EVENT_CLICKED, NULL);

    lv_obj_t *pCreaturesButton = gpMainButton(pHomeScreen, "Creatures");
    lv_obj_add_event_cb(pCreaturesButton, CreaturesButtonCallback, LV_EVENT_CLICKED, NULL);

    lv_obj_t *pPlayersButton = gpMainButton(pHomeScreen, "Players");
    lv_obj_add_event_cb(pPlayersButton, PlayersButtonCallback, LV_EVENT_CLICKED, NULL);
}

/*********************
 *  Static Functions
 *********************/
