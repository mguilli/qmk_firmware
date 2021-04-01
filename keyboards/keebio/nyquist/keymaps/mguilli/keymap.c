#include QMK_KEYBOARD_H
#include "tapdance.c"

enum custom_layers {
  _QWERTY,
  _NAV,
  _NUMPAD,
  _FUNCTION,
  _ADJUST };

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUMPAD,
  FUNCTION,
  ADJUST
};

#define ADJUST MO(_ADJUST)
#define SPC_NAV LT(_NAV, KC_SPC)
#define B_FUN LT(_FUNCTION, KC_B)
#define DEL_NUM LT(_NUMPAD, KC_DEL)

#define CTL_ESC LCTL_T(KC_ESC)
#define U_REDO C(KC_Y)
#define U_PASTE C(KC_V)
#define U_COPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UNDO C(KC_Z)

#define HSV_CUST 138, 200, 185

// Tap dance enums
enum {
  TD_COLON,
  TD_CTL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .-----------------------------------------. .-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  | B/Fun| |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |CtlSft|Adjust| GUI  | Alt  |DelNum| Bspc | |SpcNav| Enter| Left | Down |  Up  |Right |
 * '-----------------------------------------' '-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,         KC_MINS, \
  KC_TAB,     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,         KC_BSPC, \
  CTL_ESC,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    TD(TD_COLON), KC_QUOT, \
  KC_LSFT,    KC_Z,   KC_X,    KC_C,    KC_V,    B_FUN,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH,      KC_RSFT, \
  TD(TD_CTL), ADJUST, KC_LGUI, KC_LALT, DEL_NUM, KC_BSPC, SPC_NAV, KC_ENT, KC_LEFT, KC_DOWN, KC_UP,        KC_RGHT  \
),

/* Nav
 * ,-----------------------------------------. .-----------------------------------------.
 * |      |      |      |      |  {   |  <   | |  >   |  }   |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  ~   |  !   |  @   |  #   |  $   |  %   | | Redo |Paste | Copy | Cut  | Undo |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  =   |  +   |  _   |  -   |  (   | | Left | Down |  Up  |Right |  )   | Caps |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  ^   |  &   |  *   |  |   |  [   | | Home | PgDn | PgUp | End  |  ]   |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' '-----------------------------------------'
 */

[_NAV] =  LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_LT,   KC_GT,   KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, U_REDO,  U_PASTE, U_COPY,  U_CUT,   U_UNDO,  XXXXXXX, \
  _______, KC_EQL,  KC_PLUS, KC_UNDS, KC_MINS, KC_LPRN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LPRN, KC_CAPS, \
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_LBRC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RBRC, XXXXXXX, \
  _______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),

/* Numpad
 * ,-----------------------------------------. .-----------------------------------------.
 * |      |      |      |      |      |      | |      |  =   |  /   |   *  |   -  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      | |      |  7   |   8  |   9  |   +  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctl  |      |      | Prev | Next | Play | |      |  4   |   5  |   6  |   +  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      | Vol- | Vol+ | Mute | |      |  1   |   2  |   3  | Enter|      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |  0   |  0   |   0  |   .  | Enter|      |
 * `-----------------------------------------' '-----------------------------------------'
 */
[_NUMPAD] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, \
  _______, XXXXXXX, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_P0,   KC_PDOT, KC_PENT, XXXXXXX  \
),

/* Function
 * ,-----------------------------------------. .-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' '-----------------------------------------'
 */

[_FUNCTION] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PSCR, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX, KC_SLCK, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_PAUS, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),

/* Adjust
 * ,-----------------------------------------. .-----------------------------------------.
 * |      |      |      |      |RgbTog|RgbMod| |      |      |      |      |      |Sleep |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | Reset|      |      | Hue- | Hue+ | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      | Sat- | Sat+ | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |Brite-|Brite+| |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' '-----------------------------------------'
 */

[_ADJUST] =  LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, \
  XXXXXXX, RESET,   XXXXXXX, XXXXXXX, RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)

/* Empty
 * ,-----------------------------------------. .-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' '-----------------------------------------'
 */
};

// ------- RGB Configuration ---------
// RGB indicator layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_RED}  // Light all LEDs red
);

const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_GREEN}  // Light all LEDs green
);

const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_PURPLE}  // Light all LEDs purple
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_YELLOW}  // Light all LEDs yellow
);

/* const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*   {0, 12, HSV_BLUE}  // Light all LEDs BLUE */
/* ); */

// Define array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_numpad_layer,
  my_nav_layer,
  my_adjust_layer
);

//const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {40, 20, 10, 5};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_layers = my_rgb_layers;

  // Set default RGB
  // rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_CUST);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  // Enable and disable RGB layer
  rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
  rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));

  return state;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

// ---------------- Tap Dance Routines ---------------------

// Create instance of tap for storing tap count state
static uint8_t tap = 0;

// Tap Dance: Double tap to access colon
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_code16(KC_COLN);
    } else {
        register_code(KC_SCLN);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

// --------------- Ctrl/Shift Tap Dance ------------------------
// Single tap = One shot Ctrl, Double tap = One shot Ctrl+Shift

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap = cur_dance(state);
    switch (tap) {
        case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT)); break;
        case SINGLE_HOLD: register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT)); break;
    }
}

void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap == SINGLE_HOLD) {
        unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
    }
    tap = 0;
}

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // tap twice for colon
    [TD_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [TD_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
};

// Per key tapping term definitions
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DEL_NUM:
            return TAPPING_TERM - 80;
        case TD(TD_COLON):
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}
