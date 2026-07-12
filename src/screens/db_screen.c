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
// static void gvTestBrowse_eventcb(lv_event_t *e);
// static void gvTestEdit_eventcb(lv_event_t *e);

/*********************
 *  Static Prototypes
 *********************/

/*********************
 *  Global Variables
 *********************/
lv_obj_t * pDbScreen;

/*********************
 *  Global Functions
 *********************/
void gvDbScreenInit(DbScreen *pScreenInit, Sidebar *pSidebarInit)
{
    SidebarInit(pSidebarInit);

    pScreenInit->pOverallContainer = NULL;
    pScreenInit->pHeader = NULL;
    pScreenInit->pHomeContainer = NULL;
    pScreenInit->pHomeLabel = NULL;
    pScreenInit->pLowerContainer = NULL;
    pScreenInit->pSidebar = pSidebarInit;
    pScreenInit->pMainViewContainer = NULL;

}

void gvDbScreenBuild(DbScreen *pScreenToBuild, lv_event_cb_t BrowseButtonCallback, lv_event_cb_t EditButtonCallback)
{
    pScreenToBuild->pOverallContainer = lv_obj_create(NULL);
    lv_obj_add_style(pScreenToBuild->pOverallContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pScreenToBuild->pOverallContainer, lv_pct(100), lv_pct(100));
    lv_obj_add_style(pScreenToBuild->pOverallContainer, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_add_style(pScreenToBuild->pOverallContainer, &gGeneralStyle, 0);
    lv_obj_set_align(pScreenToBuild->pOverallContainer, LV_ALIGN_CENTER);
    lv_obj_set_style_pad_all(pScreenToBuild->pOverallContainer, 0, 0);

    if (lv_screen_active() != pScreenToBuild->pOverallContainer)
    {
        lv_screen_load(pScreenToBuild->pOverallContainer);
    }

    /* Header */
    pScreenToBuild->pHeader = lv_obj_create(pScreenToBuild->pOverallContainer);
    lv_obj_add_style(pScreenToBuild->pHeader, &gGeneralStyle, 0);
    lv_obj_add_style(pScreenToBuild->pHeader, &gHeaderStyle, 0);
    lv_obj_set_size(pScreenToBuild->pHeader, lv_pct(100), lv_pct(12));

    pScreenToBuild->pHomeContainer = lv_obj_create(pScreenToBuild->pHeader);
    lv_obj_set_size(pScreenToBuild->pHomeContainer, 100, lv_pct(100));
    lv_obj_add_style(pScreenToBuild->pHomeContainer, &gGeneralStyle, 0);
    lv_obj_set_style_pad_all(pScreenToBuild->pHomeContainer, 0, 0);
    lv_obj_add_event_cb(pScreenToBuild->pHomeContainer, gvActivateHomeScreen_eventcb, LV_EVENT_ALL, NULL);

    pScreenToBuild->pHomeLabel = lv_label_create(pScreenToBuild->pHomeContainer);
    lv_label_set_text(pScreenToBuild->pHomeLabel, "Home");
    lv_obj_set_style_text_font(pScreenToBuild->pHomeLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pScreenToBuild->pHomeLabel, White, 0);
    lv_obj_center(pScreenToBuild->pHomeLabel);

    /* Lower portion*/
    pScreenToBuild->pLowerContainer = lv_obj_create(pScreenToBuild->pOverallContainer);
    lv_obj_add_style(pScreenToBuild->pLowerContainer, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_add_style(pScreenToBuild->pLowerContainer, &gGeneralStyle, 0);
    lv_obj_set_style_bg_color(pScreenToBuild->pLowerContainer, lv_color_make(0, 255, 0), 0); // temp
    lv_obj_set_size(pScreenToBuild->pLowerContainer, lv_pct(100), lv_pct(88));
    lv_obj_set_style_pad_all(pScreenToBuild->pLowerContainer, 0, 0);

    /* Sidebar */
    pSidebarBuild( pScreenToBuild->pSidebar, pScreenToBuild->pLowerContainer
                                      , BrowseButtonCallback
                                      , EditButtonCallback );
    lv_obj_set_state( pScreenToBuild->pSidebar->pEditButton, LV_STATE_CHECKED, true);

    /* Main View */
    pScreenToBuild->pMainViewContainer = lv_obj_create(pScreenToBuild->pLowerContainer);
    lv_obj_add_style(pScreenToBuild->pMainViewContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pScreenToBuild->pMainViewContainer, lv_pct(80), lv_pct(100));

    if (lv_obj_has_state(pScreenToBuild->pSidebar->pBrowseButton, LV_STATE_CHECKED))
    {
        vDbBrowsePage(pScreenToBuild->pMainViewContainer);
    }
    else if(lv_obj_has_state(pScreenToBuild->pSidebar->pEditButton, LV_STATE_CHECKED))
    {
        vDbEditPage(pScreenToBuild->pMainViewContainer);
    }

}

/*********************
 *  Static Functions
 *********************/
void vDbBrowsePage(lv_obj_t *pParent)
{
    lv_obj_t *pBrowseContainer = lv_obj_create(pParent);
    lv_obj_add_style(pBrowseContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pBrowseContainer, lv_pct(100), lv_pct(100));

    lv_obj_t *pBrowseLabel = lv_label_create(pBrowseContainer);
    lv_label_set_text(pBrowseLabel, "Browse");
    lv_obj_set_style_text_font(pBrowseLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pBrowseLabel, White, 0);
    lv_obj_center(pBrowseLabel);
}

void vDbEditPage(lv_obj_t *pParent)
{
    lv_obj_t *pEditContainer = lv_obj_create(pParent);
    lv_obj_add_style(pEditContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pEditContainer, lv_pct(100), lv_pct(100));

    lv_obj_t *pEditLabel = lv_label_create(pEditContainer);
    lv_label_set_text(pEditLabel, "Edit");
    lv_obj_set_style_text_font(pEditLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pEditLabel, White, 0);
    lv_obj_center(pEditLabel);
}

/* Callbacks */
// static void gvTestBrowse_eventcb(lv_event_t *e)
// {
//     lv_event_code_t event = lv_event_get_code(e);
//     if(event == LV_EVENT_HOVER_OVER)
//     {
//         lv_obj_set_style_bg_color(pDbSidebar->pBrowseButton, SelectedButton, 0);
//     }
//     else if(event == LV_EVENT_HOVER_LEAVE)
//     {
//         lv_obj_set_style_bg_color(pDbSidebar->pBrowseButton, Background, 0);
//     }
//     else if(event == LV_EVENT_CLICKED)
//     {
//         if (lv_obj_has_state(pDbSidebar->pEditButton, LV_STATE_CHECKED))
//         {
//             lv_obj_set_state(pDbSidebar->pEditButton, LV_STATE_CHECKED, false);
//         }
//         if (!lv_obj_has_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED))
//         {
//             lv_obj_set_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED, true);
//             vDbBrowsePage(pScreenToBuild->pMainViewContainer);
//         }
//     }
// }

// void gvTestEdit_eventcb(lv_event_t *e)
// {
//     lv_event_code_t event = lv_event_get_code(e);
//     if(event == LV_EVENT_HOVER_OVER)
//     {
//         lv_obj_set_style_bg_color(pDbSidebar->pEditButton, SelectedButton, 0);
//     }
//     else if(event == LV_EVENT_HOVER_LEAVE)
//     {
//         lv_obj_set_style_bg_color(pDbSidebar->pEditButton, Background, 0);
//     }
//     else if(event == LV_EVENT_CLICKED)
//     {
//         if (lv_obj_has_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED))
//         {
//             lv_obj_set_state(pDbSidebar->pBrowseButton, LV_STATE_CHECKED, false);
//         }

//         if (!lv_obj_has_state(pDbSidebar->pEditButton, LV_STATE_CHECKED))
//         {
//             lv_obj_set_state(pDbSidebar->pEditButton, LV_STATE_CHECKED, true);
//             //vDbEditPage(pScreenToBuild->pMainViewContainer);
//         }
//     }
// }
