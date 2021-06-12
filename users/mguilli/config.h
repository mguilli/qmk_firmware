#pragma once

#ifndef TAPPING_TERM
  #define TAPPING_TERM 200
#endif

// Allows media codes to properly register in macros and rotary encoder code
#ifndef TAP_CODE_DELAY
  #define TAP_CODE_DELAY 10
#endif
// Prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT
// This prevents short hold periods to be interpretedas individual taps when typing quickly
#define PERMISSIVE_HOLD

#ifdef LEADER_ENABLE
  #define LEADER_TIMEOUT 300
#endif

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 20000
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SLEEP
  #undef RGBLIGHT_ANIMATIONS

  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_KNIGHT
  //#define RGBLIGHT_EFFECT_SNAKE
  //#define RGBLIGHT_EFFECT_TWINKLE
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD

  #ifdef RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_EFFECT_TWINKLE_LIFE  250
    #define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 1/80
  #endif

  #define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19}

  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

#ifdef COMBO_ENABLE
  #define COMBO_VARIABLE_LEN
  #define COMBO_TERM 35
  //#define COMBO_COUNT 3
#endif
