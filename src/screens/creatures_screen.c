#include "lvgl/lvgl.h"
#include "../global.h"
#include "creatures_screen.h"
#include "../styles.h"
#include "../components/buttons.h"
#include "../components/sidebar.h"

/*********************
 *  Local Variables
 *********************/
static Sidebar *pCreaturesSidebar;
static lv_obj_t *pCreaturesBrowseButton;
static lv_obj_t *pCreaturesEditButton;
static lv_obj_t *pCreaturesMain;
static void gvTestBrowse_eventcb(lv_event_t *e);
static void gvTestEdit_eventcb(lv_event_t *e);

/*********************
 *  Static Prototypes
 *********************/
static void vCreaturesBrowsePage(lv_obj_t *pParent);
static void vCreaturesEditPage(lv_obj_t *pParent);

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pCreaturesScreen;

/*********************
 *  Global Functions
 *********************/
void gvCreaturesScreenCreate(void)
{
    pCreaturesScreen = lv_obj_create(NULL);
    lv_obj_add_style(pCreaturesScreen, &gGeneralStyle, 0);
    lv_obj_add_style(pCreaturesScreen, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_align(pCreaturesScreen, LV_ALIGN_CENTER);
    lv_obj_set_style_pad_all(pCreaturesScreen, 0, 0);

    if (lv_screen_active() != pCreaturesScreen)
    {
        lv_screen_load(pCreaturesScreen);
    }

    /* Header */
    lv_obj_t *pCreaturesHeader = lv_obj_create(pCreaturesScreen);
    lv_obj_add_style(pCreaturesHeader, &gGeneralStyle, 0);
    lv_obj_add_style(pCreaturesHeader, &gHeaderStyle, 0);
    lv_obj_set_size(pCreaturesHeader, lv_pct(100), lv_pct(12));

    lv_obj_t *pCreaturesBackIconContainer = lv_obj_create(pCreaturesHeader);
    lv_obj_set_size(pCreaturesBackIconContainer, 100, lv_pct(100));
    lv_obj_add_style(pCreaturesBackIconContainer, &gGeneralStyle, 0);
    lv_obj_set_style_pad_all(pCreaturesBackIconContainer, 0, 0);
    lv_obj_add_event_cb(pCreaturesBackIconContainer, gvActivateHomeScreen_eventcb, LV_EVENT_ALL, NULL);

    lv_obj_t *pCreaturesBackIconLabel = lv_label_create(pCreaturesBackIconContainer);
    lv_label_set_text(pCreaturesBackIconLabel, "Home");
    lv_obj_set_style_text_font(pCreaturesBackIconLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pCreaturesBackIconLabel, White, 0);
    lv_obj_center(pCreaturesBackIconLabel);

    /* Lower portion*/
    lv_obj_t *pCreaturesLowerContainer = lv_obj_create(pCreaturesScreen);
    lv_obj_add_style(pCreaturesLowerContainer, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_add_style(pCreaturesLowerContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pCreaturesLowerContainer, lv_pct(100), lv_pct(88));
    lv_obj_set_style_pad_all(pCreaturesLowerContainer, 0, 0);

    /* Sidebar */
    pCreaturesSidebar = pCreateSidebar( pCreaturesLowerContainer
                                      , gvTestBrowse_eventcb
                                      , gvTestEdit_eventcb );
    lv_obj_set_state(pCreaturesSidebar->pBrowseButton, LV_STATE_CHECKED, true);

    /* Main View */
    pCreaturesMain = lv_obj_create(pCreaturesLowerContainer);
    lv_obj_add_style(pCreaturesMain, &gGeneralStyle, 0);
    lv_obj_set_size(pCreaturesMain, lv_pct(80), lv_pct(100));

    if (lv_obj_has_state(pCreaturesSidebar->pBrowseButton, LV_STATE_CHECKED))
    {
        vCreaturesBrowsePage(pCreaturesMain);
    }
    else if(lv_obj_has_state(pCreaturesSidebar->pEditButton, LV_STATE_CHECKED))
    {
        vCreaturesEditPage(pCreaturesMain);
    }

}

/*********************
 *  Static Functions
 *********************/
static void vCreaturesBrowsePage(lv_obj_t *pParent)
{
    lv_obj_clean(pParent);
    lv_obj_t *pBrowseLabel = lv_label_create(pParent);
    lv_label_set_text(pBrowseLabel, "Browse");
    lv_obj_set_style_text_font(pBrowseLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pBrowseLabel, White, 0);
    lv_obj_center(pBrowseLabel);
}

static void vCreaturesEditPage(lv_obj_t *pParent)
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
        lv_obj_set_style_bg_color(pCreaturesSidebar->pBrowseButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pCreaturesSidebar->pBrowseButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pCreaturesSidebar->pEditButton, LV_STATE_CHECKED)) {
            lv_obj_set_state(pCreaturesSidebar->pEditButton, LV_STATE_CHECKED, false);
        }
        if (!lv_obj_has_state(pCreaturesSidebar->pBrowseButton, LV_STATE_CHECKED)) {
            lv_obj_set_state(pCreaturesSidebar->pBrowseButton, LV_STATE_CHECKED, true);
            vCreaturesBrowsePage(pCreaturesMain);
        }
    }
}

static void gvTestEdit_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pCreaturesSidebar->pEditButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pCreaturesSidebar->pEditButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pCreaturesSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pCreaturesSidebar->pBrowseButton, LV_STATE_CHECKED, false);
        }

        if (!lv_obj_has_state(pCreaturesSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pCreaturesSidebar->pEditButton, LV_STATE_CHECKED, true);
            vCreaturesEditPage(pCreaturesMain);
        }
    }
}
