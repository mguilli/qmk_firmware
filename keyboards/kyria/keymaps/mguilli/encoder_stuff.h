#pragma once

// Encoder modes
enum encoder_modes {
  FIRST,
  BROWSER,
  VIMSCR,
  MEDIA,
  MSWORD,
  LAST
};

uint8_t enc_mode;

enum encoder_codes {
  // Encoders
  RIGHT_ENC,
  LEFT_ENC
};

void left_encoder_pressed(void);
void right_encoder_pressed(void);
