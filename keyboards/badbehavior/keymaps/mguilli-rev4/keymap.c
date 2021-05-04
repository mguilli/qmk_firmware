#include QMK_KEYBOARD_H
#include "process_records.c"
#include "tapdance.c"

// Custom Layers
enum custom_layers {
  _QWERTY,
  _NAV,
  _NUMPAD,
  _SYMBOL,
  _FUNCTION,
  _ADJUST
};

#define SPC_NAV LT(_NAV, KC_SPC)
#define BRC_FUN LT(_FUNCTION, KC_LBRC)
#define BSP_SYM LT(_SYMBOL, KC_BSPC)
#define ENT_SYM LT(_SYMBOL, KC_ENT)
#define ADJUST MO(_ADJUST)
#define NUMLOCK TG(_NUMPAD)

#define ESC_CTL CTL_T(KC_ESC)

#define U_REDO C(KC_Y)
#define U_PASTE C(KC_V)
#define U_COPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UNDO C(KC_Z)

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SC LGUI_T(KC_SCLN)

// Tap dance enums
enum {
  DEL_NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │  `   │   1  │   2  │   3  │   4  │   5  │CtlTab│      │  =   │   6  │   7  │   8  │   9  │   0  │  -   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │ Tab  │   Q  │   W  │   E  │   R  │   T  │  (   │ Mute │  )   │   Y  │   U  │   I  │   O  │   P  │  \   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │EscCtl│   A  │   S  │   D  │   F  │   G  ├──────┼──────┼──────┤   H  │   J  │   K  │   L  │   ;  │  '   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │ Shift│   Z  │   X  │   C  │   V  │   B  │[/Fun │ Home │  ]   │   N  │   M  │   ,  │   .  │   /  │ Shift│
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │ Ctl  │Adjust│ GUI  │ Alt  │   BSP_SYM   │DelNum│      │ Enter│   SpaceNav  │ Left │ Down │  Up  │ Right│
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    C(KC_TAB),   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
      KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_LPRN,     KC_RPRN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
      ESC_CTL, GUI_A,  ALT_S,   CTL_D,   SFT_F,   KC_G,    KC_HOME,     KC_MUTE, KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_SC,  KC_QUOT, \
      KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    BRC_FUN,     KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      KC_LCTL, ADJUST, KC_LGUI, KC_LALT, XXXXXXX, BSP_SYM, TD(DEL_NUM), ENT_SYM, SPC_NAV, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
      ),

  /* Nav
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      │      │      │      │ Redo │Paste │ Copy │ Cut  │ Undo │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │ GUI  │ ALT  │ CTL  │ SFT  │      ├──────┼──────┼──────┤ Left │ Down │  Up  │ Rght │      │ Caps │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      │      │      │      │ Home │Pg-Dwn│Pg-Up │ End  │      │      │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │             │      │      │      │             │      │      │      │      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_NAV] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, U_REDO,  U_PASTE, U_COPY,  U_CUT,   U_UNDO,  XXXXXXX, \
      _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_CAPS, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
      _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

  /* Symbol
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │NUMLOK│
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │  !   │  @   │  {   │  }   │  |   │  <   │      │  >   │  ||  │  ()  │  []  │  {}  │  <>  │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │  #   │  $   │  (   │  )   │  `   ├──────┼──────┼──────┤  +   │  -   │  _   │  *   │  /   │  ''  │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │  %   │  ^   │  [   │  ]   │  ~   │  {   │      │  }   │  &   │  =   │  <   │  >   │  ?   │  ""  │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │             │      │      │      │             │      │      │      │      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_SYMBOL] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NUMLOCK, \
      XXXXXXX, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_LT,   KC_GT,   DBL_PIP, DBL_PRN, DBL_BRC, DBL_CBR, DBL_ARR, XXXXXXX, \
      XXXXXXX, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_UNDS, KC_ASTR, KC_SLSH, DBL_SQT, \
      XXXXXXX, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_LCBR, KC_RCBR, KC_AMPR, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, DBL_DQT, \
      XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

  /* Numpad
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      │      │CtlTab│      │  =   │      │  =   │  /   │  *   │  -   │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │ Tab  │      │  Up  │      │      │      │      │      │      │      │  7   │  8   │  9   │  +   │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │EscCtl│ Left │ Down │ Rght │      │      ├──────┼──────┼──────┤      │  4   │  5   │  6   │  +   │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │ Shift│      │      │      │      │      │      │      │      │      │  1   │  2   │  3   │ Enter│      │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │ Ctl  │      │ GUI  │ Alt  │             │      │      │ Entr │  0          │  0   │  .   │ Enter│      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_NUMPAD] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, _______, \
      _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, \
      _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, KC_P0,   XXXXXXX, KC_P0,   KC_PDOT, KC_PENT, XXXXXXX  \
      ),

  /* Function
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      │      │      │      │      │      │  F10 │  F11 │  F12 │      │PrnScr│
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      │      │      │      │      │  F7  │  F8  │  F9  │      │ScrLck│
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      ├──────┼──────┼──────┤      │  F4  │  F5  │  F6  │      │Pause │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      │      │      │      │      │  F1  │  F2  │  F3  │      │      │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │             │      │      │      │             │      │      │      │      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_FUNCTION] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PSCR, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX, KC_SLCK, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_PAUS, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

  /* Adjust
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │ Sleep│
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │ Reset│      │      │      │      │      │      │      │      │      │      │      │      │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      ├──────┼──────┼──────┤      │      │      │      │      │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │             │      │      │      │             │      │      │      │      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_ADJUST] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, \
      XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      )
};

// ---------- Encoder settings -------------
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
}

// ----------- Tap Dance routines ---------------------

// Tap Dance: Single = Bspc, Hold = Numpad
// Holding key while numpad locked should access QWERTY layer
static uint8_t tap = 0;

void del_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap = cur_dance(state);
    switch (tap) {
      case SINGLE_HOLD: layer_invert(_NUMPAD); break;
      case DOUBLE_HOLD: register_code(KC_DEL); break;
      default: tap_code(KC_DEL);
    }
}

void del_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap) {
      case SINGLE_HOLD: layer_invert(_NUMPAD); break;
      case DOUBLE_HOLD: unregister_code(KC_DEL); break;
    }
    tap = 0;
}

// Define tap dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    [DEL_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, del_num_finished, del_num_reset),
};

// ---------- Tapping Terms ------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GUI_A:
      return TAPPING_TERM + 60;
    case GUI_SC:
      return TAPPING_TERM + 60;
    default:
      return TAPPING_TERM;
  }
}
