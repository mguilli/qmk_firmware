#include QMK_KEYBOARD_H
#include "mguilli.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#include "secrets.h"

#ifdef ENCODER_ENABLE
// ---------- Encoder settings -------------

uint8_t enc_mode = BROWSER;

// Change encoder function
void increment_encoder(void) {
  if ((enc_mode + 1) < LAST) {
    enc_mode++;
#ifdef OLED_DRIVER_ENABLE
  } else if ((enc_mode + 1) == LAST) {
    enc_mode = FIRST + 1;
#endif
  }
  return;
}

void decrement_encoder(void) {
  if ((enc_mode - 1) > FIRST) {
    enc_mode--;
#ifdef OLED_DRIVER_ENABLE
  } else if ((enc_mode - 1) == FIRST) {
    enc_mode = LAST - 1;
#endif
  }
  return;
}

// Encoder button press
void minor_encoder_pressed(void) {
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

void major_encoder_pressed(void) {
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
void minor_encoder_cw(void) {
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

void minor_encoder_ccw(void) {
  if (get_highest_layer(layer_state) == _ADJUST) {
    decrement_encoder();
    return;
  }

  switch (enc_mode) {
    case BROWSER:
      tap_code16(S(C(KC_TAB)));
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
void major_encoder_cw(void){
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

void major_encoder_ccw(void) {
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
      minor_encoder_cw();
    } else {
      minor_encoder_ccw();
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      major_encoder_cw();
    } else {
      major_encoder_ccw();
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
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
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

#ifdef ENCODER_ENABLE
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
#endif

    // Host Keyboard LED Status
    oled_write_P(host_keyboard_led_state().num_lock ? PSTR("NUML ") : PSTR("     "), false);
    oled_write_P(host_keyboard_led_state().caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(host_keyboard_led_state().scroll_lock ? PSTR("SCRL ") : PSTR("     "), false);

#ifdef COMBO_ENABLE
    // Combos on off
    oled_write_P(is_combo_enabled() ? PSTR("COMBO ") : PSTR("      "), false);
#endif
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

// -------- Secrets ------------
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

#ifdef LEADER_ENABLE
bool process_leader_secrets(uint16_t keycode) {
  switch (keycode) {
    case SEC_0 ... SEC_LAST:
      send_string(secrets[keycode - SEC_0]);
      return false;
      break;
  }
  return true;
}
#endif

// -------- Smartcase ------------
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
    // Keycodes to ignore (don't disable caps or num word)
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
    case LFT_SPC:
      break;
    case KC_A ... KC_Z:
      if (record->event.pressed) {
        num_word_disable();
      }
      break;
    default:
      if (record->event.pressed) {
        caps_word_disable();
        num_word_disable();
      }
  }
}

// -------- Macros ------------
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
    case COLEMAK:
      if(record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;

#ifdef ENCODER_ENABLE
    // Encoder button presses
    case MINOR_ENC:
      if (record->event.pressed) {
        minor_encoder_pressed();
      }
      break;
    case MAJOR_ENC:
      if (record->event.pressed) {
        major_encoder_pressed();
      }
      break;

  #ifndef OLED_DRIVER_ENABLE
    case E_BROWSE:
      enc_mode = BROWSER;
      break;
    case E_VIMSCR:
      enc_mode = VIMSCR;
      break;
    case E_MEDIA:
      enc_mode = MEDIA;
      break;
    case E_MSWORD:
      enc_mode = MSWORD;
      break;
  #endif
#endif

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

#ifdef LEADER_ENABLE
LEADER_EXTERNS();
#endif

void matrix_scan_user(void) {

  // Alt-Tab timer
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 850) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

#ifdef LEADER_ENABLE
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
#endif
}

#ifdef COMBO_ENABLE
void process_combo_user(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case weAltTab:
      process_alt_tab(pressed);
      break;
    case wdAltTab:
      process_alt_tab(pressed);
      break;
  }
}
#endif
