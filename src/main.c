/**
 * @file main.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#ifndef _DEFAULT_SOURCE
  #define _DEFAULT_SOURCE /* needed for usleep() */
#endif

#include <stdlib.h>
#include <stdio.h>
#ifdef _MSC_VER
  #include <Windows.h>
#else
  #include <unistd.h>
  #include <pthread.h>
#endif

#include "lvgl/lvgl.h"
#include "global.h"
#include "screens/home_screen.h"
#include "screens/db_screen.h"
#include "styles.h"
// #include "lvgl/examples/lv_examples.h"
// #include "lvgl/demos/lv_demos.h"
#include <SDL.h>

#include "hal/hal.h"

/*********************
 *      DEFINES
 *********************/
#define MIN_WINDOW_WIDTH    800
#define MAIN_WINDOW_HEIGHT   1400

/**********************
 *      TYPEDEFS
 **********************/
AppState gAppState;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void gvActivateEncountersScreen_eventcb(lv_event_t *e);
static void gvActivateCreaturesScreen_eventcb(lv_event_t *e);
static void gvActivatePlayersScreen_eventcb(lv_event_t *e);
static void gvActivateHomeScreen_eventcb(lv_event_t *e);
static void gvTestBrowse_eventcb(lv_event_t *e);
static void gvTestEdit_eventcb(lv_event_t *e);

/**********************
 *  STATIC VARIABLES
 **********************/
  static DbScreen EncountersScreen;
  static Sidebar EncountersScreenSidebar;

  static DbScreen CreaturesScreen;
  static Sidebar CreaturesScreenSidebar;

  static DbScreen PlayersScreen;
  static Sidebar PlayersScreenSidebar;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    lv_init();
    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = false;
    lv_display_t* display = lv_windows_create_display(
        L"LVGL Display Window",
        MIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT,
        zoom_level, allow_dpi_override, simulator_mode);
    if (!display) return -1;
    lv_lock();
    lv_indev_t* pointer_device = lv_windows_acquire_pointer_indev(display);
    if (!pointer_device) return -1;
    lv_indev_t* keypad_device = lv_windows_acquire_keypad_indev(display);
    if (!keypad_device) return -1;
    lv_indev_t* encoder_device = lv_windows_acquire_encoder_indev(display);
    if (!encoder_device)  return -1;

    gAppState.pLastLoadedDbScreen = NULL;
    gAppState.pActiveScreen = NULL;

    gvStylesInit();

    gvDbScreenInit(&EncountersScreen, &EncountersScreenSidebar);
    gvDbScreenBuild(&EncountersScreen, gvTestBrowse_eventcb, gvTestEdit_eventcb, gvActivateHomeScreen_eventcb, "Encounters");

    gvDbScreenInit(&CreaturesScreen, &CreaturesScreenSidebar);
    gvDbScreenBuild(&CreaturesScreen, gvTestBrowse_eventcb, gvTestEdit_eventcb, gvActivateHomeScreen_eventcb, "Creatures");

    gvDbScreenInit(&PlayersScreen, &PlayersScreenSidebar);
    gvDbScreenBuild(&PlayersScreen, gvTestBrowse_eventcb, gvTestEdit_eventcb, gvActivateHomeScreen_eventcb, "Players");

    lv_obj_move_background(EncountersScreen.pOverallContainer);
    lv_obj_move_background(CreaturesScreen.pOverallContainer);
    lv_obj_move_background(PlayersScreen.pOverallContainer);

    gvHomeScreenCreate(gvActivateEncountersScreen_eventcb, gvActivateCreaturesScreen_eventcb, gvActivatePlayersScreen_eventcb);

    lv_unlock();
    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        // handle LV_NO_TIMER_READY. Another option is to always sleep a few milliseconds
        if(time_till_next == LV_NO_TIMER_READY) time_till_next = LV_DEF_REFR_PERIOD;
        lv_sleep_ms(time_till_next);
    }
    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void gvActivateEncountersScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED)
    {
      lv_screen_load(EncountersScreen.pOverallContainer);
      gAppState.pLastLoadedDbScreen = &EncountersScreen;
      gAppState.pActiveScreen = EncountersScreen.pOverallContainer;
    }
}

static void gvActivateCreaturesScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED)
    {
      lv_screen_load(CreaturesScreen.pOverallContainer);
      gAppState.pLastLoadedDbScreen = &CreaturesScreen;
      gAppState.pActiveScreen = CreaturesScreen.pOverallContainer;
    }
}

static void gvActivatePlayersScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED)
    {
      lv_screen_load(PlayersScreen.pOverallContainer);
      gAppState.pLastLoadedDbScreen = &PlayersScreen;
      gAppState.pActiveScreen = PlayersScreen.pOverallContainer;
    }
}

static void gvActivateHomeScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    DbScreen *pEventScreen;
    pEventScreen = lv_event_get_user_data(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pEventScreen->pHomeButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pEventScreen->pHomeButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
      lv_screen_load(pHomeScreen);
      gAppState.pActiveScreen = pHomeScreen;
    }
}

static void gvTestBrowse_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    DbScreen *pEventScreen;
    pEventScreen = lv_event_get_user_data(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pEventScreen->pSidebar->pBrowseButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pEventScreen->pSidebar->pBrowseButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pEventScreen->pSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pEventScreen->pSidebar->pEditButton, LV_STATE_CHECKED, false);
        }
        else
        {
            /* Do nothing */
        }

        if (!lv_obj_has_state(pEventScreen->pSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pEventScreen->pSidebar->pBrowseButton, LV_STATE_CHECKED, true);
            vDbBrowsePage(pEventScreen->pMainViewContainer, "New");
        }
        else
        {
            /* Do nothing */
        }
    }
}

static void gvTestEdit_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);

    DbScreen *pEventScreen;
    pEventScreen = lv_event_get_user_data(e);

    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(pEventScreen->pSidebar->pEditButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(pEventScreen->pSidebar->pEditButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(pEventScreen->pSidebar->pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pEventScreen->pSidebar->pBrowseButton, LV_STATE_CHECKED, false);
        }

        if (!lv_obj_has_state(pEventScreen->pSidebar->pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(pEventScreen->pSidebar->pEditButton, LV_STATE_CHECKED, true);
            vDbEditPage(pEventScreen->pMainViewContainer, "New again");
        }
    }
}
