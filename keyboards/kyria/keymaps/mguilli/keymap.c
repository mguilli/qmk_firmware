#include QMK_KEYBOARD_H
#include "mguilli.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
      KC_GRV,  KC_Q,  KC_W,  KC_E,      KC_R,    KC_T,                                        KC_Y,     KC_U,   KC_I,    KC_O,   KC_P,    KC_MINS,
      ESC_CTL, GUI_A, ALT_S, CTL_D,     SFT_F,   KC_G,                                        KC_H,     SFT_J,  CTL_K,   ALT_L,  KC_SCLN, KC_QUOT,
      ALT_TAB, KC_Z,  KC_X,  KC_C,      KC_V,    KC_B,    KC_TAB,  KC_DEL, CTL_TAB, KC_LEAD,  KC_N,     KC_M,   KC_COMM, KC_DOT, KC_SLSH, NUMLOCK,
                             MINOR_ENC, KC_LGUI, NUMWORD, LFT_SPC, KC_ENT, KC_ENT,  RGHT_SPC, CAPSWORD, ADJUST, MAJOR_ENC
      ),

  [_NORMAN] = LAYOUT(
      KC_GRV,  KC_Q,  KC_W,  KC_D,      KC_F,    KC_K,                                        KC_J,     KC_U,   KC_R,    KC_L,   KC_SCLN, KC_MINS,
      ESC_CTL, GUI_A, ALT_S, CTL_E,     SHFT_T,  KC_G,                                        KC_Y,     SFT_N,  CTL_I,   ALT_O,  KC_H,    KC_QUOT,
      ALT_TAB, KC_Z,  KC_X,  KC_C,      KC_V,    KC_B,    KC_TAB,  KC_DEL, CTL_TAB, KC_LEAD,  KC_P,     KC_M,   KC_COMM, KC_DOT, KC_SLSH, NUMLOCK,
                             MINOR_ENC, KC_LGUI, NUMWORD, LFT_SPC, KC_ENT, KC_ENT,  RGHT_SPC, CAPSWORD, ADJUST, MAJOR_ENC
      ),

  [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     W_LEFT,  W_DOWN,  W_UP,    W_RGHT,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_NUMPAD] = LAYOUT(
      _______, _______, _______, KC_UP,   _______, _______,                                     _______, KC_7,   KC_8, KC_9, KC_MINS, KC_SLSH,
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                                     _______, KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,   KC_2, KC_3, KC_DOT,  _______,
                                 _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT, _______
      ),

  [_NUMBER] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_6,    KC_4,    KC_0,    KC_2,    KC_PLUS,                                     KC_EQL,  KC_3,    KC_1,    KC_5,    KC_7,    _______,
      _______, _______, _______, _______, KC_8,    _______, _______, _______, _______, _______, _______, KC_9,    _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_SYMBOL] = LAYOUT(
      KC_TILD, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, DBL_CBR,                                     DBL_PIP, KC_UNDS, KC_PIPE, KC_GRV,  KC_BSLS, DBL_DQT,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, DBL_PRN,                                     KC_PLUS, KC_MINS, KC_AMPR, KC_ASTR, KC_COLN, KC_DQUO,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, DBL_BRC, _______, _______, _______, _______, DBL_ARR, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, DBL_SQT,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_ADJUST] = LAYOUT(
      CMB_TOG, _______, _______, _______, _______, _______,                                      _______, KC_F7,   KC_F8, KC_F9, KC_F12, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                      _______, KC_F4,   KC_F5, KC_F6, KC_F11, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______, _______, _______, _______, _______, KC_F1,   KC_F2, KC_F3, KC_F10, KC_SLEP,
                                 _______, NORMAN,  QWERTY,   _______, _______, _______, _______, _______, _______, _______
      )

/* Blank
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
};

// ---------- Tapping Terms ------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GUI_A:
      return TAPPING_TERM + 60;
    case ALT_S:
      return TAPPING_TERM + 20;
    case ALT_L:
      return TAPPING_TERM + 20;
    case RGHT_SPC:
      return TAPPING_TERM + 20;
    case CTL_E:
      return TAPPING_TERM + 60;
    default:
      return TAPPING_TERM;
  }
}
