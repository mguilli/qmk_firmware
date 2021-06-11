#pragma once

bool numword_on;
bool capsword_on;

void num_word_enable(void);
void num_word_disable(void);
void caps_word_enable(void);
void caps_word_disable(void);

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_smartcase(uint16_t keycode, keyrecord_t *record);

