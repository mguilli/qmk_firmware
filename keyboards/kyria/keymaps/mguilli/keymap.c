#include QMK_KEYBOARD_H
#include "keymap.h"
#include "g/keymap_combo.h"
#include "secrets.h"


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

#ifdef ENCODER_ENABLE
// ---------- Encoder settings -------------

uint8_t enc_mode = BROWSER;

// Change encoder function
void increment_encoder(void) {
  if ((enc_mode + 1) < LAST) {
    enc_mode++;
  } else if ((enc_mode + 1) == LAST) {
    enc_mode = FIRST + 1;
  }
  return;
}

void decrement_encoder(void) {
  if ((enc_mode - 1) > FIRST) {
    enc_mode--;
  } else if ((enc_mode - 1) == FIRST) {
    enc_mode = LAST - 1;
  }
  return;
}

// Encoder button press
void left_encoder_pressed(void) {
  switch (enc_mode) {
    case BROWSER:
      tap_code16(C(S(KC_N)));
      break;
    case MEDIA:
      tap_code(KC_MEDIA_PLAY_PAUSE);
      break;
    case VIMSCR:
      tap_code16(KC_CIRC);
      break;
    case MSWORD:
      tap_code16(U_COPY);
      break;
  }
}

void right_encoder_pressed(void) {
  switch (enc_mode) {
    case BROWSER:
      tap_code(KC_HOME);
      break;
    case MEDIA:
      tap_code(KC_AUDIO_MUTE);
      break;
    case VIMSCR:
      SEND_STRING(SS_TAP(X_ESC) "vip");
      break;
    case MSWORD:
      tap_code16(U_PASTE);
      break;
  }
}

// Left encoder rotate
void left_encoder_cw(void) {
  if (get_highest_layer(layer_state) == _ADJUST) {
    increment_encoder();
    return;
  }

  switch (enc_mode) {
    case BROWSER:
      tap_code16(C(KC_TAB));
      break;
    case MEDIA:
      tap_code(KC_MNXT);
      break;
    case VIMSCR:
      tap_code16(S(KC_W));
      break;
    case MSWORD:
      tap_code16(C(S(KC_RGHT)));
      break;
  }
}

void left_encoder_ccw(void) {
  if (get_highest_layer(layer_state) == _ADJUST) {
    decrement_encoder();
    return;
  }

  switch (enc_mode) {
    case BROWSER:
      tap_code16(C(S(KC_TAB)));
      break;
    case MEDIA:
      tap_code(KC_MPRV);
      break;
    case VIMSCR:
      tap_code16(S(KC_B));
      break;
    case MSWORD:
      tap_code16(C(S(KC_LEFT)));
      break;
  }
}

// Right encoder rotate
void right_encoder_cw(void){
  switch (enc_mode) {
    case BROWSER:
      tap_code(KC_PGDN);
      break;
    case MEDIA:
      tap_code(KC_VOLU);
      break;
    case VIMSCR:
      tap_code16(KC_RCBR);
      break;
    case MSWORD:
      tap_code16(C(KC_RGHT));
      break;
  }
}

void right_encoder_ccw(void) {
  switch (enc_mode) {
    case BROWSER:
      tap_code(KC_PGUP);
      break;
    case MEDIA:
      tap_code(KC_VOLD);
      break;
    case VIMSCR:
      tap_code16(KC_LCBR);
      break;
    case MSWORD:
      tap_code16(C(KC_LEFT));
      break;
  }
}

// Update encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      left_encoder_cw();
    } else {
      left_encoder_ccw();
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      right_encoder_cw();
    } else {
      right_encoder_ccw();
    }
  }
  return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE

// Turn off oleds when pc goes to sleep
void suspend_power_down_user(void) {
    oled_off();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

static void render_puppy_logo(void) {
  static const char PROGMEM puppy_logo[] = {
    0x00, 0x00, 0x00, 0xf0, 0xf8, 0x38, 0x18, 0x38, 0x38, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0x38, 0x18, 0x38, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1e, 0x3c, 0x78, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0x78, 0x3c, 0x1e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x71, 0x73, 0x3f, 0x3e, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3e, 0x3f,
    0x77, 0x71, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0x0f, 0x3e, 0x78, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x78, 0x3e, 0x0f, 0x07, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3c, 0x7e, 0x7f, 0x7e, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x7e, 0x7f, 0x7e, 0x3c, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7f, 0xfc, 0xe0, 0x80, 0x00, 0xe0, 0xf8, 0xff, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x3e, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x18, 0x7c, 0x78, 0xe0, 0xe3, 0xe7, 0x7f, 0x7f, 0x7f, 0xe7, 0xe3, 0xe0, 0x78, 0x7c,
    0x18, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf8, 0x3e, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x07, 0x03, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xc1, 0xff, 0xff, 0x3f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0e, 0x1c, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x1c, 0x0e, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(puppy_logo, sizeof(puppy_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();

    // Host Keyboard Layer Status
    oled_write_P(PSTR("\nLayer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _NORMAN:
            oled_write_P(PSTR("Norman\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard Encoder Status
    oled_write_P(PSTR("Encoder: "), false);
    switch (enc_mode) {
      case BROWSER:
        oled_write_P(PSTR("Browser\n"), false);
        break;
      case VIMSCR:
        oled_write_P(PSTR("Vim Scroll\n"), false);
        break;
      case MEDIA:
        oled_write_P(PSTR("Media\n"), false);
        break;
      case MSWORD:
        oled_write_P(PSTR("MS Word\n"), false);
        break;
      default:
        oled_write_P(PSTR("Undefined\n"), false);
    }

    oled_write_P(PSTR("Combos: "), false);
    if (is_combo_enabled()) {
      oled_write_P(PSTR("on\n"), false);
    } else {
      oled_write_P(PSTR("off\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_puppy_logo();
        oled_scroll_right();
    }
}
#endif

// -------- Macros ------------
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEC_0 ... SEC_LAST:
      if (record->event.pressed) {
        send_string(secrets[keycode - SEC_0]);
      }
      return false;
      break;
  }
  return true;
}

bool process_leader_secrets(uint16_t keycode) {
  switch (keycode) {
    case SEC_0 ... SEC_LAST:
      send_string(secrets[keycode - SEC_0]);
      return false;
      break;
  }
  return true;
}

static bool numword_on = false;
static bool capsword_on = false;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void num_word_enable(void) {
  numword_on = true;
  layer_on(_NUMBER);
}

void num_word_disable(void) {
  numword_on = false;
  layer_off(_NUMBER);
}

// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    capsword_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    capsword_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}
// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_smartcase(uint16_t keycode, keyrecord_t *record) {
  if (capsword_on) {
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        // Earlier return if this has not been considered tapped yet
        if (record->tap.count == 0) { return; }
        // Get the base tapping keycode of a mod- or layer-tap key
        keycode = GET_TAP_KC(keycode);
        break;
      default:
        break;
    }
  }

  switch (keycode) {
    // Keycodes to ignore (don't disable caps word)
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_PERC:
    case KC_COMM:
    case KC_DOT:
    case KC_SLSH:
    case KC_DLR:
    case KC_MINS:
    case KC_ASTR:
    case KC_PLUS:
    case KC_EQL:
    case KC_UNDS:
    case KC_BSPC:
    case NUMWORD:
    case BSP_SYM:
      break;
    default:
      if (record->event.pressed) {
        caps_word_disable();
        num_word_disable();
      }
  }
}

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
  return true;
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
