# pragma once
# include QMK_KEYBOARD_H

// Custom Layers
enum custom_layers {
  _QWERTY = 0,
  _COLEMAK,
  _NAV,
  _NUMPAD,
  _NUMBER,
  _SYMBOL,
  _ADJUST
};

#define LFT_SPC LT(_SYMBOL, KC_BSPC)
#define RGHT_SPC LT(_NAV, KC_SPC)
#define ADJUST MO(_ADJUST)
#define NUMLOCK TG(_NUMPAD)
#define NUMBERS MO(_NUMBER)

#define ESC_CTL CTL_T(KC_ESC)
#define CTL_TAB C(KC_TAB)

#define W_LEFT SGUI(KC_LEFT)
#define W_UP SGUI(KC_UP)
#define W_DOWN SGUI(KC_DOWN)
#define W_RGHT SGUI(KC_RGHT)

#define U_REDO C(KC_Y)
#define U_PASTE C(KC_V)
#define U_COPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UNDO C(KC_Z)

// Qwerty Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Qwerty Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)

// Colemak Mod-dh Left-hand home row mods
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Colemak Mod-dh Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)

#ifdef ENCODER_ENABLE
// Encoder modes
enum encoder_modes {
  FIRST,
  BROWSER,
  VIMSCR,
  MEDIA,
  MSWORD,
  LAST
};
#endif

// Macros
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NUMWORD,
  CAPSWORD,
  ALT_TAB,

#ifdef ENCODER_ENABLE
  // Encoders
  MAJOR_ENC,
  MINOR_ENC,

  #ifndef OLED_DRIVER_ENABLE
  E_BROWSE,
  E_VIMSCR,
  E_MEDIA,
  E_MSWORD,
  #endif
#endif

  // secret keycodes
  SEC_0,
  SEC_1,
  SEC_2,
  SEC_3,
  SEC_4,
  SEC_5,
  SEC_6,
  SEC_7,
  SEC_8,
  SEC_9,
  SEC_LAST,

  // Surround Macros, where _ is the cursor
  DBL_BRC,  // [_]
  DBL_CBR,  // {_}
  DBL_PRN,  // (_)
  DBL_PIP,  // |_|
  DBL_ARR,  // <_>
  DBL_SQT,  // '_'
  DBL_DQT   // "_"
};

void process_combo_user(uint16_t combo_index, bool pressed);
