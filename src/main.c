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

/**********************
 *  STATIC VARIABLES
 **********************/

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
      720, 480,
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
  gvStylesInit();
  gvHome_screen();
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
