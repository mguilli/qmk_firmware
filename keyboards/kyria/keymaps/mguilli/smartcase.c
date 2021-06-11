#include "keymap.h"

bool numword_on = false;
bool capsword_on = false;

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

