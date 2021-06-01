# include QMK_KEYBOARD_H

// Custom Layers
enum custom_layers {
  _QWERTY = 0,
  _COLEMAK_DH,
  _NAV,
  _NUMPAD,
  _SYMBOL,
  _ADJUST
};

#define SPC_NAV LT(_NAV, KC_SPC)
#define BSP_SYM LT(_SYMBOL, KC_BSPC)
#define ADJUST MO(_ADJUST)
#define NUM_TAB LT(_NUMPAD, KC_TAB)

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
#define GUI_SC LGUI_T(KC_SCLN)

// Colemak Left-hand home row mods
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Colemak Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O)

// Encoder modes
enum encoder_modes {
  FIRST,
  BROWSER,
  VIMSCR,
  MEDIA,
  MSWORD,
  LAST
};

// Macros
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  // Encoders
  RIGHT_ENC,
  LEFT_ENC,
  // Encoder switching
  E_BROWS,
  E_WORD,
  E_MEDIA,
  E_VIMSCR,
  // Surround Macros, where _ is the cursor
  DBL_BRC,  // [_]
  DBL_CBR,  // {_}
  DBL_PRN,  // (_)
  DBL_PIP,  // |_|
  DBL_ARR,  // <_>
  DBL_SQT,  // '_'
  DBL_DQT   // "_"
};
