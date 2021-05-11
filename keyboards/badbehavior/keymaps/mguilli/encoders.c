// encoders.c

// Encoder modes
enum encoder_modes {
  FIRST,
  BROWSER,
  VIMSCR,
  MEDIA,
  MSWORD,
  LAST
};

uint8_t enc_mode = BROWSER;

// ---------- Encoder settings -------------

// Change encoder function
void increment_encoder(void) {
  if ((enc_mode + 1) < LAST) {
    enc_mode++;
  }
  return;
}

void decrement_encoder(void) {
  if ((enc_mode - 1) > FIRST) {
    enc_mode--;
  }
  return;
}

// Encoder button press
void top_encoder_pressed(void) {
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

void bot_encoder_pressed(void) {
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

// Top encoder rotate
void top_encoder_cw(void) {
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

void top_encoder_ccw(void) {
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

// Bottom encoder rotate
void bot_encoder_cw(void){
  if (get_highest_layer(layer_state) == _ADJUST) {
    increment_encoder();
    return;
  }

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

void bot_encoder_ccw(void) {
  if (get_highest_layer(layer_state) == _ADJUST) {
    decrement_encoder();
    return;
  }

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
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      top_encoder_cw();
    } else {
      top_encoder_ccw();
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      bot_encoder_cw();
    } else {
      bot_encoder_ccw();
    }
  }
}

