#include QMK_KEYBOARD_H
#include "tapdance.c"

enum custom_layers {
  _QWERTY,
  _NAV,
  _NUMPAD,
  _FUNCTION,
  _MOUSE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUMPAD,
  FUNCTION,
  MOUSE,
  ADJUST
};

#define ADJUST MO(_ADJUST)
#define SPC_NAV LT(_NAV, KC_SPC)
#define BRC_FUN LT(_FUNCTION, KC_LBRC)

#define SFT_ENT RSFT_T(KC_ENT)
#define ESC_CTL CTL_T(KC_ESC)
#define U_REDO C(KC_Y)
#define U_PASTE C(KC_V)
#define U_COPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UNDO C(KC_Z)

// Tap dance enums
enum {
  TD_COLON,
  DEL_NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  `   │   1  │   2  │   3  │   4  │   5  │NumLok│      │  =   │   6  │   7  │   8  │   9  │   0  │  -   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │  (   │ Mute │  )   │   Y  │   U  │   I  │   O  │   P  │  \   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │EscCtl│   A  │   S  │   D  │   F  │   G  ├──────┼──────┼──────┤   H  │   J  │   K  │   L  │   ;  │  '   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   C  │   V  │   B  │[/Fun │ Home │  ]   │   N  │   M  │   ,  │   .  │   /  │SftEnt│
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │ Ctl  │Adjust│ GUI  │ Alt  │     Bspc    │DelNum│      │ Enter│   SpaceNav  │ Left │ Down │  Up  │ Right│
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */

  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    TO(_NUMPAD), KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_MINS, \
      KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_LPRN,     KC_RPRN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_BSLS, \
      ESC_CTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,     KC_MUTE, KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_COLON), KC_QUOT, \
      KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    BRC_FUN,     KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      SFT_ENT, \
      XXXXXXX, ADJUST, KC_LGUI, KC_LALT, XXXXXXX, KC_BSPC, TD(DEL_NUM), KC_ENT,  SPC_NAV, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,        KC_RGHT  \
      ),

/* Nav
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  ~   │  !   │  @   │  #   │  $   │  %   │  <   │      │  >   │ Redo │Paste │ Copy │ Cut  │ Undo │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  =   │  +   │  _   │  -   │  (   ├──────┼──────┼──────┤ Left │ Down │  Up  │ Rght │      │ Caps │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  ^   │  &   │  *   │  |   │  [   │  {   │      │  }   │ Home │Pg-Dwn│Pg-Up │ End  │      │      │
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │             │      │      │      │             │      │      │      │      │
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */

  [_NAV] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LT,   KC_GT,   U_REDO,  U_PASTE, U_COPY,  U_CUT,   U_UNDO,  XXXXXXX, \
      _______, KC_EQL,  KC_PLUS, KC_UNDS, KC_MINS, KC_LPRN, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_CAPS, \
      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_LBRC, KC_LCBR, KC_RCBR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
      _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      ),

/* Numpad
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │NumLok│      │      │      │      │  /   │  *   │  -   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │      │  Up  │      │      │      │      │      │      │      │  7   │  8   │  9   │  +   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │EscCtl│ Left │ Down │ Rght │      │      ├──────┼──────┼──────┤      │  4   │  5   │  6   │  +   │ Del  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│      │      │      │      │      │      │      │      │      │  1   │  2   │  3   │ Enter│      │
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │ Ctl  │      │ GUI  │ Alt  │             │      │      │ Bspc │  0          │  0   │  .   │ Enter│      │
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */

  [_NUMPAD] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, \
      _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL,  \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, \
      _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______,     KC_BSPC, KC_P0,   XXXXXXX, KC_P0,   KC_PDOT, KC_PENT, XXXXXXX  \
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

/* Mouse
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├──────┼──────┼──────┤M_LEFT│M_DOWN│ M_UP │M_RGHT│      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │ MW_L │ MW_D │ MW_U │ MW_R │      │      │
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │             │      │      │      │    BTN_1    │ BTN_3│ BTN_2│      │      │
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */

  [_MOUSE] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX  \
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

// Tap Dance: Double tap to access colon.
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (cur_dance(state) == DOUBLE_TAP) {
        register_code16(KC_COLN);
    } else {
        register_code(KC_SCLN);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (cur_dance(state) == DOUBLE_TAP) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

// Tap Dance: Single = Bspc, Hold = Numpad, Double = Lock Numpad
// Holding key while numpad locked should access QWERTY layer
static uint8_t tap = 0;

void del_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap = cur_dance(state);
    switch (tap) {
        case SINGLE_HOLD: layer_invert(_NUMPAD); break;
        default: tap_code(KC_DEL); break;
    }
}

void del_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap == SINGLE_HOLD) {
        layer_invert(_NUMPAD);
    }
    tap = 0;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(DEL_NUM):
            return 120;
        case TD(TD_COLON):
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}

// Define tap dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap twice for colon
    [TD_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    // Tap twice to toggle Numpad layer
    [DEL_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, del_num_finished, del_num_reset),
};
