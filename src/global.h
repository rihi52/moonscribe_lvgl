#ifndef GLOBAL_H
#define GLOBAL_H
#include "lvgl/lvgl.h"
#include "screens/db_screen.h"

/*********************
 *  Global Variables
 *********************/
#define SMALL_BUFFER    128

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
    DbScreen *pLastLoadedDbScreen;
    lv_obj_t *pActiveScreen;
} AppState;


/*********************
 *  Global Prototypes
 *********************/

#endif  /* GLOBAL_H */
