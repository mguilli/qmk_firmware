#include QMK_KEYBOARD_H
#include "keymap.h"
#include "encoders.c"
#include "tapdance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │  `   │   1  │   2  │   3  │   4  │   5  │CtlTab│      │  =   │   6  │   7  │   8  │   9  │   0  │  -   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * │ Tab  │   Q  │   W  │   E  │   R  │   T  │  (   │TopEnc│  )   │   Y  │   U  │   I  │   O  │   P  │  \   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │EscCtl│   A  │   S  │   D  │   F  │   G  ├──────┼──────┼──────┤   H  │   J  │   K  │   L  │   ;  │  '   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │ Shift│   Z  │   X  │   C  │   V  │   B  │[/Fun │BotEnc│  ]   │   N  │   M  │   ,  │   .  │   /  │ Shift│
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │ Ctl  │Adjust│ GUI  │ Alt  │   BSP_SYM   │DelNum│      │ Enter│   SpaceNav  │ Left │ Down │  Up  │ Right│
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    C(KC_TAB),   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
      KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_LPRN,     KC_RPRN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
      ESC_CTL, GUI_A,  ALT_S,   CTL_D,   SFT_F,   KC_G,    BOT_ENC,     TOP_ENC, KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_SC,  KC_QUOT, \
      KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    BRC_FUN,     KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      XXXXXXX, ADJUST, KC_LGUI, KC_LALT, XXXXXXX, BSP_SYM, TD(DEL_NUM), ENT_SYM, SPC_NAV, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
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
   * │  ~   │  !   │  @   │  {   │  }   │  {}  │  <   │      │  >   │  ||  │  _   │  |   │  `   │  &   │  ""  │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │  #   │  $   │  (   │  )   │  ()  ├──────┼──────┼──────┤  +   │  -   │  /   │  *   │  :   │  "   │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │  %   │  ^   │  [   │  ]   │  []  │  {   │      │  }   │  <>  │  =   │  <   │  >   │  ?   │  ''  │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │             │      │      │      │             │      │      │      │      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_SYMBOL] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NUMLOCK, \
      KC_TILD, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, DBL_CBR, KC_LT,   KC_GT,   DBL_PIP, KC_UNDS, KC_PIPE, KC_GRV,  KC_AMPR, DBL_DQT, \
      XXXXXXX, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, DBL_PRN, XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_COLN, KC_DQUO, \
      XXXXXXX, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, DBL_BRC, KC_LCBR, KC_RCBR, DBL_ARR, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, DBL_SQT, \
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
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_EQL,  KC_SLSH, KC_ASTR, KC_MINS, _______, \
      _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PLUS, XXXXXXX, \
      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX, \
      _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, KC_0,    XXXXXXX, KC_0,    KC_DOT,  KC_ENT,  XXXXXXX  \
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
   * │      │      │      │      │      │      ├──────┼──────┼──────┤browse│vimscr│media │msword│      │      │
   * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
   * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │             │      │      │      │             │      │      │      │      │
   * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
   */

  [_ADJUST] = LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, \
      XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, E_BROWS, E_VIMSCR, E_MEDIA, E_WORD,  XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
      )
};

// -------- Macros ------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    // Encoder button presses
    case TOP_ENC:
      if (record->event.pressed) {
        top_encoder_pressed();
      }
      break;
    case BOT_ENC:
      if (record->event.pressed) {
        bot_encoder_pressed();
      }
      break;

    // Change encoder functionality
    case E_BROWS:
      enc_mode = BROWSER;
      break;
    case E_MEDIA:
      enc_mode = MEDIA;
      break;
    case E_WORD:
      enc_mode = MSWORD;
      break;
    case E_VIMSCR:
      enc_mode = VIMSCR;
      break;

    // Surround Macros
    case DBL_PRN:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
      }
      break;
    case DBL_CBR:
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
      }
      break;
    case DBL_BRC:
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      break;
    case DBL_ARR:
      if (record->event.pressed) {
        SEND_STRING("<>" SS_TAP(X_LEFT));
      }
      break;
    case DBL_PIP:
      if (record->event.pressed) {
        SEND_STRING("||" SS_TAP(X_LEFT));
      }
      break;
    case DBL_SQT:
      if (record->event.pressed) {
        SEND_STRING("''" SS_TAP(X_LEFT));
      }
      break;
    case DBL_DQT:
      if (record->event.pressed) {
        SEND_STRING("\"\"" SS_TAP(X_LEFT));
      }
      break;
  }
  return true;
};

// ---------- Tapping Terms ------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEL_NUM:
      return TAPPING_TERM - 40;
    case GUI_A:
      return TAPPING_TERM + 60;
    case GUI_SC:
      return TAPPING_TERM + 60;
    case ALT_S:
      return TAPPING_TERM + 20;
    case ALT_L:
      return TAPPING_TERM + 20;
    case SPC_NAV:
      return TAPPING_TERM + 20;
    default:
      return TAPPING_TERM;
  }
}
