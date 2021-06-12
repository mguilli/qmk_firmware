#pragma once

#define SPC_NAV LT(_NAV, KC_SPC)
#define BSP_SYM LT(_SYMBOL, KC_BSPC)
#define ADJUST MO(_ADJUST)
#define NUMLOCK TG(_NUMPAD)

#define ESC_CTL CTL_T(KC_ESC)
#define CTL_TAB C(KC_TAB)

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

// NORMAN Left-hand home row mods
#define CTL_E RCTL_T(KC_E)
#define SHFT_T LSFT_T(KC_T)

// NORMAN Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define CTL_I LCTL_T(KC_I)
#define ALT_O LALT_T(KC_O)

// Macros
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NORMAN,
  NUMWORD,
  CAPSWORD,
  ALT_TAB,

  // Secrets keycodes
  SEC_0,
  SEC_1,
  SEC_2,
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

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_leader_secrets(uint16_t keycode);
