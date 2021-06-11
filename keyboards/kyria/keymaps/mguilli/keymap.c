#include QMK_KEYBOARD_H
#include "keymap.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
      KC_GRV,  KC_Q,  KC_W,  KC_E,     KC_R,    KC_T,                                       KC_Y,     KC_U,   KC_I,    KC_O,   KC_P,    KC_MINS,
      ESC_CTL, GUI_A, ALT_S, CTL_D,    SFT_F,   KC_G,                                       KC_H,     SFT_J,  CTL_K,   ALT_L,  KC_SCLN, KC_QUOT,
      ALT_TAB, KC_Z,  KC_X,  KC_C,     KC_V,    KC_B,    KC_LSFT, KC_DEL, NUMLOCK, KC_TAB,  KC_N,     KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_LEAD,
                             LEFT_ENC, KC_LGUI, NUMWORD, BSP_SYM, KC_ENT, KC_ENT,  SPC_NAV, CAPSWORD, ADJUST, RIGHT_ENC
      ),

  [_NORMAN] = LAYOUT(
      KC_GRV,  KC_Q,  KC_W,  KC_D,     KC_F,    KC_K,                                       KC_J,     KC_U,   KC_R,    KC_L,   KC_SCLN, KC_MINS,
      ESC_CTL, GUI_A, ALT_S, CTL_E,    SHFT_T,  KC_G,                                       KC_Y,     SFT_N,  CTL_I,   ALT_O,  KC_H,    KC_QUOT,
      ALT_TAB, KC_Z,  KC_X,  KC_C,     KC_V,    KC_B,    KC_LSFT, KC_DEL, NUMLOCK, KC_TAB,  KC_P,     KC_M,   KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
                             LEFT_ENC, KC_LGUI, NUMWORD, BSP_SYM, KC_ENT, KC_ENT,  SPC_NAV, CAPSWORD, ADJUST, RIGHT_ENC
      ),

  [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     SGUI(KC_LEFT), SGUI(KC_DOWN), SGUI(KC_UP), SGUI(KC_RGHT), _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT,       _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,       KC_PGDN,       KC_PGUP,     KC_END,        _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______,       _______,       _______
      ),

  [_NUMPAD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_7,   KC_8, KC_9, KC_MINS, KC_SLSH,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_4,   KC_5, KC_6, KC_PLUS, KC_ASTR,
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

// -------- Macros ------------
__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_leader_secrets(uint16_t keycode) {
  return true;
}

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void process_alt_tab(bool pressed) {
  if (pressed) {
    if (!is_alt_tab_active) {
      is_alt_tab_active = true;
      register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    register_code(KC_TAB);
  } else {
    unregister_code(KC_TAB);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_smartcase(keycode, record);

  switch(keycode) {
    // Case functions
    case NUMWORD:
      if (record->event.pressed) {
        if (numword_on) {
          num_word_disable();
          return false;
        } else {
          num_word_enable();
          return false;
        }
      }
      break;

    case CAPSWORD:
      // Toggle `capsword_on`
      if (record->event.pressed) {
        if (capsword_on) {
          caps_word_disable();
          return false;
        } else {
          caps_word_enable();
          return false;
        }
      }
      break;

    // Super AltTab
    case ALT_TAB:
      process_alt_tab(record->event.pressed);
      break;

    // Change default layer
    case QWERTY:
      if(record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case NORMAN:
      if(record->event.pressed) {
        set_single_persistent_default_layer(_NORMAN);
      }
      break;

    // Encoder button presses
    case LEFT_ENC:
      if (record->event.pressed) {
        left_encoder_pressed();
      }
      break;
    case RIGHT_ENC:
      if (record->event.pressed) {
        right_encoder_pressed();
      }
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
  return process_record_secrets(keycode, record);
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
    case SPC_NAV:
      return TAPPING_TERM + 20;
    case CTL_E:
      return TAPPING_TERM + 60;
    default:
      return TAPPING_TERM;
  }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // email
    SEQ_ONE_KEY(KC_E) {
      process_leader_secrets(SEC_0);
    }

    // password
    SEQ_ONE_KEY(KC_R) {
      process_leader_secrets(SEC_1);
    }

    // user name
    SEQ_ONE_KEY(KC_T) {
      process_leader_secrets(SEC_2);
    }

  }
}
