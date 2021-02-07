#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SYMBOL 5
#define _ADJUST 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  SYMBOL,
  ADJUST,
  RAISE,
};

#define LOWER TT(_LOWER)
#define RAISE MO(_RAISE)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SFT LCTL(KC_LSFT)
#define CTL_UP LCTL(KC_UP)
#define CTL_DOWN LCTL(KC_DOWN)
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGHT LCTL(KC_RGHT)
#define SPC_SYM LT(_SYMBOL, KC_SPC)

#define HSV_CUST 138, 200, 185

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Ent  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft(')|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlSft| Ctl  | Alt  | OS   |Lower |SpcSym|SpcSym| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,    KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,         \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,         \
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,          \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, LSFT_T(KC_QUOT), \
  CTL_SFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, SPC_SYM, SPC_SYM, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT          \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  =   |  /   |   *  |   -  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |      | Prev | Next | Play |  7   |   8  |   9  |   +  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | Vol- | Vol+ | Mute |  4   |   5  |   6  |   +  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  1   |   2  |   3  | Enter|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  0   |   0  |   .  | Enter|      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, XXXXXXX, XXXXXXX  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |CapLck|      |      |      |  <   |  >   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  +   |  {   |  }   | Home | PgDn | PgUp |  End |      |CtlBsp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  =   |  |   |  -   |  (   |  )   | Left | Down |  Up  | Right|      |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  \   |  *   |  _   |  [   |  ]   |CtlLft|CtlDn | CtlUp| CtlRt|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Prev | Play | Next |      |      |      |      |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] =  LAYOUT( \
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,       \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   XXXXXXX, LCTL(KC_BSPC), \
  XXXXXXX, KC_EQL,  KC_PIPE, KC_MINS, KC_LPRN, KC_RPRN, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  XXXXXXX, KC_DEL,        \
  XXXXXXX, KC_BSLS, KC_ASTR, KC_UNDS, KC_LBRC, KC_RBRC, CTL_LEFT, CTL_DOWN, CTL_UP,  CTL_RGHT, _______, XXXXXXX,       \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,  _______,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX        \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |CtlBsp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   _  |   -  |   +  |   =  |      |      |      |   |  |   \  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT( \
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,        \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LCTL(KC_BSPC), \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,        \
  XXXXXXX, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_BSLS, _______, XXXXXXX,       \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______        \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |RgbTog|RgbMod|      |      |      |      |      |Sleep |
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
  _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, KC_SLEP, \
  _______, RESET,   _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

// RGB indicator layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_RED}  // Light all LEDs red
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_GREEN}  // Light all LEDs green
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_PURPLE}  // Light all LEDs purple
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_YELLOW}  // Light all LEDs yellow
);

const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12, HSV_BLUE}  // Light all LEDs BLUE
);

// Define array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_lower_layer,
  my_raise_layer,
  my_adjust_layer,
  my_symbol_layer
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
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  // Enable and disable RGB layer
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
  rgblight_set_layer_state(4, layer_state_cmp(state, _SYMBOL));

  return state;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}
