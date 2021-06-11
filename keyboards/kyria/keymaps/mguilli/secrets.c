#include "keymap.h"
#include "secrets.h"

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


