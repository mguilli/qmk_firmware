#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMPAD 1
#define _LOWER 2
#define _RAISE 5
#define _ADJUST 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  LOWER,
  ADJUST,
  RAISE,
};

#define NUMPAD TT(_NUMPAD)
#define RAISE MO(_RAISE)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_UP LCTL(KC_UP)
#define CTL_DOWN LCTL(KC_DOWN)
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGHT LCTL(KC_RGHT)
#define SPC_LOWER LT(_LOWER, KC_SPC)

#define HSV_CUST 138, 200, 185

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // SEND TWO SINGLE TAPS
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Tap dance enums
enum {
  TD_COLON,
  TD_CTL,
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlSft|Numpad| Alt  | OS   |Raise |SpcLwr|SpcLwr| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,     KC_1,   KC_2,    KC_3,    KC_4,  KC_5,      KC_6,      KC_7,  KC_8,    KC_9,    KC_0,         KC_MINS,   \
  KC_TAB,     KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,      KC_Y,      KC_U,  KC_I,    KC_O,    KC_P,         KC_BSPC,   \
  CTL_ESC,    KC_A,   KC_S,    KC_D,    KC_F,  KC_G,      KC_H,      KC_J,  KC_K,    KC_L,    TD(TD_COLON), KC_QUOT,   \
  KC_LSFT,    KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,      KC_N,      KC_M,  KC_COMM, KC_DOT,  KC_SLSH,      KC_SFTENT, \
  TD(TD_CTL), NUMPAD, KC_LALT, KC_LGUI, RAISE, SPC_LOWER, SPC_LOWER, RAISE, KC_LEFT, KC_DOWN, KC_UP,        KC_RGHT    \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  =   |  /   |   *  |   -  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |  7   |   8  |   9  |   +  |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctl  |      |      | Prev | Next | Play |  4   |   5  |   6  |   +  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | Vol- | Vol+ | Mute |  1   |   2  |   3  | Enter|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  0   |   0  |   .  | Enter|      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, KC_DEL, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, XXXXXXX, XXXXXXX  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |CapLck|      |      |      |  <   |  >   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  &   |  +   |  {   |  }   | Home | PgDn | PgUp |  End |      |CtlBsp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  =   |  |   |  -   |  (   |  )   | Left | Down |  Up  | Right|      |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  \   |  *   |  _   |  [   |  ]   |CtlLft|CtlDn | CtlUp| CtlRt|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] =  LAYOUT( \
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,       \
  XXXXXXX, XXXXXXX, KC_AMPR, KC_PLUS, KC_LCBR, KC_RCBR, KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   XXXXXXX, LCTL(KC_BSPC), \
  _______, KC_EQL,  KC_PIPE, KC_MINS, KC_LPRN, KC_RPRN, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  XXXXXXX, KC_DEL,        \
  _______, KC_BSLS, KC_ASTR, KC_UNDS, KC_LBRC, KC_RBRC, CTL_LEFT, CTL_DOWN, CTL_UP,  CTL_RGHT, _______, _______,       \
  _______, _______, _______, _______, _______, _______, _______,  _______,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX        \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |CtlBsp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,        \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LCTL(KC_BSPC), \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,        \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______        \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Wake |      |      |      |RgbTog|RgbMod|      |      |      |      |      |Sleep |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      | Hue- | Hue+ |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | Sat- | Sat+ |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |Brite-|Brite+|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_WAKE, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, KC_SLEP, \
  _______, RESET,   _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

// ------- RGB Configuration ---------
// RGB indicator layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_RED}  // Light all LEDs red
);

const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_GREEN}  // Light all LEDs green
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_PURPLE}  // Light all LEDs purple
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_YELLOW}  // Light all LEDs yellow
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_BLUE}  // Light all LEDs BLUE
);

// Define array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_numpad_layer,
  my_raise_layer,
  my_adjust_layer,
  my_lower_layer
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
  // Activate Adjust layer if both Lower and Raise layers are activated
  state = update_tri_layer_state(state, _NUMPAD, _RAISE, _ADJUST);

  // Enable and disable RGB layer
  rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
  rgblight_set_layer_state(4, layer_state_cmp(state, _LOWER));

  return state;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

// ----------- Tap Dance routines ---------------------

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

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

// Create an instance of 'tap' for the 'x' tap dance.
static tap ctl_tap_state = {
    .is_press_action = true,
    .state = 0
};

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctl_tap_state.state = cur_dance(state);
    switch (ctl_tap_state.state) {
        case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT)); break;
        case SINGLE_HOLD: register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT)); break;
    }
}

void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (ctl_tap_state.state == SINGLE_HOLD) {
        unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
    }
}

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // tap twice for colon
    [TD_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [TD_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
};
