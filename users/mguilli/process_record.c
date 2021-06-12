#include "mguilli.h"

// -------- Macros ------------
__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_leader_secrets(uint16_t keycode) {
  return true;
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
