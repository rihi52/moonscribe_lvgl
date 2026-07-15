#include "lvgl/lvgl.h"
#include "../global.h"
#include "db_screen.h"
#include "../styles.h"
#include "../components/buttons.h"
#include "../components/creature_header.h"

/*********************
 *  Local Variables
 *********************/
static Sidebar *pDbSidebar;
static lv_obj_t *pDbBrowseButton;
static lv_obj_t *pDbEditButton;
static lv_obj_t *pDbMain;

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
    pScreenInit->pHomeButton = NULL;
    pScreenInit->pHomeLabel = NULL;
    pScreenInit->pLowerContainer = NULL;
    pScreenInit->pSidebar = pSidebarInit;
    pScreenInit->pMainViewContainer = NULL;

}

void gvDbScreenBuild( DbScreen *pScreenToBuild
                    , lv_event_cb_t BrowseButtonCallback
                    , lv_event_cb_t EditButtonCallback
                    , lv_event_cb_t HomeButtonCallback
                    , const char *WindowLabel )
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

    pScreenToBuild->pHomeButton = lv_obj_create(pScreenToBuild->pHeader);
    lv_obj_set_size(pScreenToBuild->pHomeButton, 100, lv_pct(100));
    lv_obj_add_style(pScreenToBuild->pHomeButton, &gSidebarDefaultButtonStyle, 0);
    lv_obj_set_style_border_width(pScreenToBuild->pHomeButton, 0, 0);
    lv_obj_set_style_pad_all(pScreenToBuild->pHomeButton, 0, 0);
    lv_obj_add_event_cb(pScreenToBuild->pHomeButton, HomeButtonCallback, LV_EVENT_ALL, pScreenToBuild);

    pScreenToBuild->pHomeLabel = lv_label_create(pScreenToBuild->pHomeButton);
    lv_label_set_text(pScreenToBuild->pHomeLabel, "Home");
    lv_obj_set_style_text_font(pScreenToBuild->pHomeLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pScreenToBuild->pHomeLabel, White, 0);
    lv_obj_center(pScreenToBuild->pHomeLabel);

    /* Lower portion*/
    pScreenToBuild->pLowerContainer = lv_obj_create(pScreenToBuild->pOverallContainer);
    lv_obj_add_style(pScreenToBuild->pLowerContainer, &gBackgroundFlexRowScreenStyle, 0);
    lv_obj_add_style(pScreenToBuild->pLowerContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pScreenToBuild->pLowerContainer, lv_pct(100), lv_pct(88));
    lv_obj_set_style_pad_all(pScreenToBuild->pLowerContainer, 0, 0);

    /* Sidebar */
    pSidebarBuild( pScreenToBuild->pSidebar
                 , pScreenToBuild->pLowerContainer
                 , pScreenToBuild
                 , BrowseButtonCallback
                 , EditButtonCallback );
    lv_obj_set_state( pScreenToBuild->pSidebar->pBrowseButton, LV_STATE_CHECKED, true);

    /* Main View */
    pScreenToBuild->pMainViewContainer = lv_obj_create(pScreenToBuild->pLowerContainer);
    lv_obj_add_style(pScreenToBuild->pMainViewContainer, &gGeneralStyle, 0);
    lv_obj_set_style_pad_all(pScreenToBuild->pMainViewContainer, 0, 0);
    lv_obj_set_size(pScreenToBuild->pMainViewContainer, lv_pct(85), lv_pct(100));

    if (lv_obj_has_state(pScreenToBuild->pSidebar->pBrowseButton, LV_STATE_CHECKED))
    {
        vDbBrowsePage(pScreenToBuild->pMainViewContainer, WindowLabel);
    }
    else if(lv_obj_has_state(pScreenToBuild->pSidebar->pEditButton, LV_STATE_CHECKED))
    {
        vDbEditPage(pScreenToBuild->pMainViewContainer, WindowLabel);
    }

}

/* Sidebar */
void SidebarInit(Sidebar *pSidebarToInit)
{
    pSidebarToInit->pBrowseButton = NULL;
    pSidebarToInit->pEditButton = NULL;
    pSidebarToInit->pSidebarContainer = NULL;
}

void pSidebarBuild(Sidebar *pSidebarToBuild
                  , lv_obj_t *pParent
                  , DbScreen *pParentScreen
                  , lv_event_cb_t BrowseButtonCallback
                  , lv_event_cb_t EditButtonCallback )
{

    pSidebarToBuild->pSidebarContainer = lv_obj_create(pParent);
    lv_obj_add_style(pSidebarToBuild->pSidebarContainer, &gGeneralStyle, 0);
    lv_obj_add_style(pSidebarToBuild->pSidebarContainer, &gSidebarStyle, 0);
    lv_obj_set_size(pSidebarToBuild->pSidebarContainer, lv_pct(15), lv_pct(100));

    pSidebarToBuild->pBrowseButton = gpSidebarButton(pSidebarToBuild->pSidebarContainer, "Browse");
    lv_obj_add_event_cb(pSidebarToBuild->pBrowseButton, BrowseButtonCallback, LV_EVENT_ALL, pParentScreen);

    pSidebarToBuild->pEditButton = gpSidebarButton(pSidebarToBuild->pSidebarContainer, "Edit");
    lv_obj_add_event_cb(pSidebarToBuild->pEditButton, EditButtonCallback, LV_EVENT_ALL, pParentScreen);
}


/*********************
 *  Static Functions
 *********************/
void vDbBrowsePage(lv_obj_t *pParent, const char *WindowLabel)
{


    lv_obj_t *pBrowseContainer = lv_obj_create(pParent);
    lv_obj_add_style(pBrowseContainer, &gGeneralStyle, 0);
    lv_obj_set_style_pad_all(pBrowseContainer, 0, 0);
    lv_obj_set_size(pBrowseContainer, lv_pct(100), lv_pct(100));

    lv_obj_t *pHeadersContainer = lv_obj_create(pBrowseContainer);
    lv_obj_add_style(pHeadersContainer, &gBackgroundFlexColumnScreenStyle, 0);
    lv_obj_set_style_flex_main_place(pHeadersContainer, LV_FLEX_ALIGN_START, 0);
    lv_obj_set_style_pad_row(pHeadersContainer, SmallValue, 0);
    lv_obj_set_size(pHeadersContainer, lv_pct(20), lv_pct(100));

    CreatureHeader *pTestHeader = gpCreateCreatureHeader( pHeadersContainer
                                                        , "Fire Giant"
                                                        , 10
                                                        , "Huge"
                                                        , "Giant"
                                                        , "MM" );

    CreatureHeader *pTestHeader2 = gpCreateCreatureHeader( pHeadersContainer
                                                        , "Frost Giant"
                                                        , 9
                                                        , "Huge"
                                                        , "Giant"
                                                        , "MM" );

}

void vDbEditPage(lv_obj_t *pParent, const char *WindowLabel)
{
    lv_obj_t *pEditContainer = lv_obj_create(pParent);
    lv_obj_add_style(pEditContainer, &gGeneralStyle, 0);
    lv_obj_set_size(pEditContainer, lv_pct(100), lv_pct(100));

    lv_obj_t *pEditLabel = lv_label_create(pEditContainer);
    lv_label_set_text(pEditLabel, WindowLabel);
    lv_obj_set_style_text_font(pEditLabel, &Metamorphous_24, 0);
    lv_obj_set_style_text_color(pEditLabel, White, 0);
    lv_obj_center(pEditLabel);
}
