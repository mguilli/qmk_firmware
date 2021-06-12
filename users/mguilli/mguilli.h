# include QMK_KEYBOARD_H
# include "oled_stuff.h"
# include "encoder_stuff.h"
# include "smartcase.h"
# include "process_record.h"

// Custom Layers
enum custom_layers {
  _QWERTY = 0,
  _NORMAN,
  _NAV,
  _NUMPAD,
  _NUMBER,
  _SYMBOL,
  _ADJUST
};

void process_alt_tab(bool pressed);
