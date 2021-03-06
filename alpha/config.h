
#pragma once
// alpha 
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    PyroL
#define PRODUCT         alpha

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, B4, B5 }
#define MATRIX_COL_PINS { D7, E6, C6, B6, B2, B3, B1, F7, F6, F5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

#define COMBO_COUNT 5
#define COMBO_TERM 30

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN F4
#ifdef RGB_DI_PIN
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 28
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif


#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 230
#define TAPPING_TERM_PER_KEY

