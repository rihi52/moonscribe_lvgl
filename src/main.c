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
#include "screens/home_screen.h"
#include "screens/db_screen.h"
#include "components/sidebar.h"
#include "styles.h"
// #include "lvgl/examples/lv_examples.h"
// #include "lvgl/demos/lv_demos.h"
#include <SDL.h>

#include "hal/hal.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void gvActivateCreaturesScreen_eventcb(lv_event_t *e);
static void gvTestBrowse_eventcb(lv_event_t *e);
static void gvTestEdit_eventcb(lv_event_t *e);

/**********************
 *  STATIC VARIABLES
 **********************/
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
      800, 560,
      zoom_level, allow_dpi_override, simulator_mode);
  if (!display) return -1;
  lv_lock();
  lv_indev_t* pointer_device = lv_windows_acquire_pointer_indev(display);
  if (!pointer_device) return -1;
  lv_indev_t* keypad_device = lv_windows_acquire_keypad_indev(display);
  if (!keypad_device) return -1;
  lv_indev_t* encoder_device = lv_windows_acquire_encoder_indev(display);
  if (!encoder_device)  return -1;
  // lv_demo_widgets();
  // lv_obj_t *pMainScreen = lv_obj_create(NULL);
  // lv_screen_load(pMainScreen);
  gvStylesInit();
  gvDbScreenInit(&CreaturesScreen, &CreaturesScreenSidebar);
  gvDbScreenBuild(&CreaturesScreen, gvTestBrowse_eventcb, gvTestEdit_eventcb);
  lv_obj_move_background(CreaturesScreen.pOverallContainer);
  // lv_obj_clean(pMainScreen);

  //lv_obj_add_flag(CreaturesScreen.pOverallContainer, LV_OBJ_FLAG_HIDDEN);
  gvHomeScreenCreate(gvActivateCreaturesScreen_eventcb);
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

static void gvActivateCreaturesScreen_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED)
    {
      lv_screen_load(CreaturesScreen.pOverallContainer);
    }
}

static void gvTestBrowse_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(CreaturesScreenSidebar.pBrowseButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(CreaturesScreenSidebar.pBrowseButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(CreaturesScreenSidebar.pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(CreaturesScreenSidebar.pEditButton, LV_STATE_CHECKED, false);
        }
        if (!lv_obj_has_state(CreaturesScreenSidebar.pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(CreaturesScreenSidebar.pBrowseButton, LV_STATE_CHECKED, true);
            vDbBrowsePage(CreaturesScreen.pMainViewContainer);
        }
    }
}

static void gvTestEdit_eventcb(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_HOVER_OVER)
    {
        lv_obj_set_style_bg_color(CreaturesScreenSidebar.pEditButton, SelectedButton, 0);
    }
    else if(event == LV_EVENT_HOVER_LEAVE)
    {
        lv_obj_set_style_bg_color(CreaturesScreenSidebar.pEditButton, Background, 0);
    }
    else if(event == LV_EVENT_CLICKED)
    {
        if (lv_obj_has_state(CreaturesScreenSidebar.pBrowseButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(CreaturesScreenSidebar.pBrowseButton, LV_STATE_CHECKED, false);
        }

        if (!lv_obj_has_state(CreaturesScreenSidebar.pEditButton, LV_STATE_CHECKED))
        {
            lv_obj_set_state(CreaturesScreenSidebar.pEditButton, LV_STATE_CHECKED, true);
            vDbEditPage(CreaturesScreen.pMainViewContainer);
        }
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
