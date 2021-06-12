#include QMK_KEYBOARD_H
#include "mguilli.h"
#include "g/keymap_combo.h"

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
