#include "lvgl/lvgl.h"
#include "../global.h"
#include "players_screen.h"
#include "../styles.h"
#include "../components/buttons.h"
#include "../components/sidebar.h"

/*********************
 *  Local Variables
 *********************/
static Sidebar *pPlayersSidebar;
static lv_obj_t *pPlayersBrowseButton;
static lv_obj_t *pPlayersEditButton;
static lv_obj_t *pPlayersMain;
static void gvTestBrowse_eventcb(lv_event_t *e);
static void gvTestEdit_eventcb(lv_event_t *e);

/*********************
 *  Static Prototypes
 *********************/
static void vPlayersBrowsePage(lv_obj_t *pParent);
static void vPlayersEditPage(lv_obj_t *pParent);

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pPlayersScreen;

/*********************
 *  Global Functions
 *********************/
void gvPlayersScreenCreate(void)
{
    pPlayersScreen = lv_obj_create(NULL);
    lv_obj_add_style(pPlayersScreen, &gGeneralStyle, 0);
    lv_obj_add_style(pPlayersScreen, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_align(pPlayersScreen, LV_ALIGN_CENTER);
    lv_obj_set_style_pad_all(pPlayersScreen, 0, 0);

    if (lv_screen_active() != pPlayersScreen)
    {
        lv_screen_load(pPlayersScreen);
    }

    /* Header */
    lv_obj_t *pPlayersHeader = lv_obj_create(pPlayersScreen);
    lv_obj_add_style(pPlayersHeader, &gGeneralStyle, 0);
    lv_obj_add_style(pPlayersHeader, &gHeaderStyle, 0);
    lv_obj_set_size(pPlayersHeader, lv_pct(100), lv_pct(12));

    lv_obj_t *pPlayersBackIconContainer = lv_obj_create(pPlayersHeader);
    lv_obj_set_size(pPlayersBackIconContainer, 100, lv_pct(100));
    lv_obj_add_style(pPlayersBackIconContainer, &gGeneralStyle, 0);
    lv_obj_set_style_pad_all(pPlayersBackIconContainer, 0, 0);
    lv_obj_add_event_cb(pPlayersBackIconContainer, gvActivateHomeScreen_eventcb, LV_EVENT_ALL, NULL);

    lv_obj_t *pPlayersBackIconLabel = lv_label_create(pPlayersBackIconContainer);
    lv_label_set_text(pPlayersBackIconLabel, "Home");
    lv_obj_set_style_text_font(pPlayersBackIconLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pPlayersBackIconLabel, White, 0);
    lv_obj_center(pPlayersBackIconLabel);

    /* Lower portion*/
    lv_obj_t *pPlayersLowerContainer = lv_obj_create(pPlayersScreen);
    lv_obj_add_style(pPlayersLowerContainer, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_add_style(pPlayersLowerContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pPlayersLowerContainer, lv_pct(100), lv_pct(88));
    lv_obj_set_style_pad_all(pPlayersLowerContainer, 0, 0);

    /* Sidebar */
    // pPlayersSidebar = pSidebarBuild( pPlayersLowerContainer
    //                                   , gvTestBrowse_eventcb
    //                                   , gvTestEdit_eventcb );
    // lv_obj_set_state(pPlayersSidebar->pBrowseButton, LV_STATE_CHECKED, true);

    /* Main View */
    pPlayersMain = lv_obj_create(pPlayersLowerContainer);
    lv_obj_add_style(pPlayersMain, &gGeneralStyle, 0);
    lv_obj_set_size(pPlayersMain, lv_pct(80), lv_pct(100));

    if (lv_obj_has_state(pPlayersSidebar->pBrowseButton, LV_STATE_CHECKED))
    {
        vPlayersBrowsePage(pPlayersMain);
    }
    else if(lv_obj_has_state(pPlayersSidebar->pEditButton, LV_STATE_CHECKED))
    {
        vPlayersEditPage(pPlayersMain);
    }

}

/*********************
 *  Static Functions
 *********************/
static void vPlayersBrowsePage(lv_obj_t *pParent)
{
    lv_obj_clean(pParent);
    lv_obj_t *pBrowseLabel = lv_label_create(pParent);
    lv_label_set_text(pBrowseLabel, "Browse");
    lv_obj_set_style_text_font(pBrowseLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pBrowseLabel, White, 0);
    lv_obj_center(pBrowseLabel);
}

static void vPlayersEditPage(lv_obj_t *pParent)
{
    lv_obj_clean(pParent);
    lv_obj_t *pEditLabel = lv_label_create(pParent);
    lv_label_set_text(pEditLabel, "Edit");
    lv_obj_set_style_text_font(pEditLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pEditLabel, White, 0);
    lv_obj_center(pEditLabel);
}

/* Callbacks */
static void gvTestBrowse_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pPlayersSidebar->pBrowseButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pPlayersSidebar->pBrowseButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pPlayersSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pPlayersSidebar->pEditButton, LV_STATE_CHECKED, false);
        }
        if (!lv_obj_has_state(pPlayersSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pPlayersSidebar->pBrowseButton, LV_STATE_CHECKED, true);
            vPlayersBrowsePage(pPlayersMain);
        }
    }
}

static void gvTestEdit_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pPlayersSidebar->pEditButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pPlayersSidebar->pEditButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pPlayersSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pPlayersSidebar->pBrowseButton, LV_STATE_CHECKED, false);
        }

        if (!lv_obj_has_state(pPlayersSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pPlayersSidebar->pEditButton, LV_STATE_CHECKED, true);
            vPlayersEditPage(pPlayersMain);
        }
    }
}
