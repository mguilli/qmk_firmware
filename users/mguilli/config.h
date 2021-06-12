#pragma once

#define EE_HANDS

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 50
// Prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT
// This prevents short hold periods to be interpretedas individual taps when typing quickly
#define PERMISSIVE_HOLD

#define LEADER_TIMEOUT 300

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 20000
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SLEEP
  #undef RGBLIGHT_ANIMATIONS

  #define RBGLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL

  #define RGBLIGHT_EFFECT_TWINKLE_LIFE  250
  #define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 1/80

  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 35
//#define COMBO_COUNT 3

// Disabling to reduce firmware size
#define NO_ACTION_ONESHOT

// disable if not debugging
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
