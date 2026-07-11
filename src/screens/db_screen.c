#include "lvgl/lvgl.h"
#include "../global.h"
#include "db_screen.h"
#include "../styles.h"
#include "../components/buttons.h"
#include "../components/sidebar.h"

/*********************
 *  Local Variables
 *********************/
static Sidebar *pDbSidebar;
static lv_obj_t *pDbBrowseButton;
static lv_obj_t *pDbEditButton;
static lv_obj_t *pDbMain;
static void gvTestBrowse_eventcb(lv_event_t *e);
static void gvTestEdit_eventcb(lv_event_t *e);

/*********************
 *  Static Prototypes
 *********************/
static void vDbBrowsePage(lv_obj_t *pParent);
static void vDbEditPage(lv_obj_t *pParent);

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pDbScreen;

/*********************
 *  Global Functions
 *********************/
void gvDbScreenCreate(void)
{
    pDbScreen = lv_obj_create(NULL);
    lv_obj_add_style(pDbScreen, &gGeneralStyle, 0);
    lv_obj_add_style(pDbScreen, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_align(pDbScreen, LV_ALIGN_CENTER);
    lv_obj_set_style_pad_all(pDbScreen, 0, 0);

    if (lv_screen_active() != pDbScreen)
    {
        lv_screen_load(pDbScreen);
    }

    /* Header */
    lv_obj_t *pDbHeader = lv_obj_create(pDbScreen);
    lv_obj_add_style(pDbHeader, &gGeneralStyle, 0);
    lv_obj_add_style(pDbHeader, &gHeaderStyle, 0);
    lv_obj_set_size(pDbHeader, lv_pct(100), lv_pct(12));

    lv_obj_t *pDbBackIconContainer = lv_obj_create(pDbHeader);
    lv_obj_set_size(pDbBackIconContainer, 100, lv_pct(100));
    lv_obj_add_style(pDbBackIconContainer, &gGeneralStyle, 0);
    lv_obj_set_style_pad_all(pDbBackIconContainer, 0, 0);
    lv_obj_add_event_cb(pDbBackIconContainer, gvActivateHomeScreen_eventcb, LV_EVENT_ALL, NULL);

    lv_obj_t *pDbBackIconLabel = lv_label_create(pDbBackIconContainer);
    lv_label_set_text(pDbBackIconLabel, "Home");
    lv_obj_set_style_text_font(pDbBackIconLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pDbBackIconLabel, White, 0);
    lv_obj_center(pDbBackIconLabel);

    /* Lower portion*/
    lv_obj_t *pDbLowerContainer = lv_obj_create(pDbScreen);
    lv_obj_add_style(pDbLowerContainer, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_add_style(pDbLowerContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pDbLowerContainer, lv_pct(100), lv_pct(88));
    lv_obj_set_style_pad_all(pDbLowerContainer, 0, 0);

    /* Sidebar */
    pDbSidebar = pCreateSidebar( pDbLowerContainer
                                      , gvTestBrowse_eventcb
                                      , gvTestEdit_eventcb );
    lv_obj_set_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED, true);

    /* Main View */
    pDbMain = lv_obj_create(pDbLowerContainer);
    lv_obj_add_style(pDbMain, &gGeneralStyle, 0);
    lv_obj_set_size(pDbMain, lv_pct(80), lv_pct(100));

    if (lv_obj_has_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED))
    {
        vDbBrowsePage(pDbMain);
    }
    else if(lv_obj_has_state(pDbSidebar->pEditButton, LV_STATE_CHECKED))
    {
        vDbEditPage(pDbMain);
    }

}

/*********************
 *  Static Functions
 *********************/
static void vDbBrowsePage(lv_obj_t *pParent)
{
    lv_obj_clean(pParent);
    lv_obj_t *pBrowseLabel = lv_label_create(pParent);
    lv_label_set_text(pBrowseLabel, "Browse");
    lv_obj_set_style_text_font(pBrowseLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pBrowseLabel, White, 0);
    lv_obj_center(pBrowseLabel);
}

static void vDbEditPage(lv_obj_t *pParent)
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
        lv_obj_set_style_bg_color(pDbSidebar->pBrowseButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pDbSidebar->pBrowseButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pDbSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pDbSidebar->pEditButton, LV_STATE_CHECKED, false);
        }
        if (!lv_obj_has_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED, true);
            vDbBrowsePage(pDbMain);
        }
    }
}

static void gvTestEdit_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pDbSidebar->pEditButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pDbSidebar->pEditButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED, false);
        }

        if (!lv_obj_has_state(pDbSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pDbSidebar->pEditButton, LV_STATE_CHECKED, true);
            vDbEditPage(pDbMain);
        }
    }
}
