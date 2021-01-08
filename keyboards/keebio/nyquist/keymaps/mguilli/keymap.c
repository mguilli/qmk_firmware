#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 5
#define _NAV 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |^Shft | GUI  | Alt  |Lower |SpcNav|SpcNav|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,         KC_1,          KC_2,    KC_3,    KC_4,  KC_5,         KC_6,         KC_7,  KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB,         KC_Q,          KC_W,    KC_E,    KC_R,  KC_T,         KC_Y,         KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LCTL_T(KC_ESC), KC_A,          KC_S,    KC_D,    KC_F,  KC_G,         KC_H,         KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,        KC_Z,          KC_X,    KC_C,    KC_V,  KC_B,         KC_N,         KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
  KC_LCTL,        LCTL(KC_LSFT), KC_LGUI, KC_LALT, TT(1), LT(6,KC_SPC), LT(6,KC_SPC), TT(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | Home | CtlUp| PgUp |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | End  |  Up  | PgDn |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right|  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |CtlLft| CtlDn| CtlRt|  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  XXXXXXX, KC_HOME,       LCTL(KC_UP),   KC_PGUP,       XXXXXXX, XXXXXXX, XXXXXXX, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, \
  _______, KC_END,        KC_UP,         KC_PGDN,       XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, \
  _______, KC_LEFT,       KC_DOWN,       KC_RGHT,       XXXXXXX, XXXXXXX, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_DEL, \
  _______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT), XXXXXXX, XXXXXXX, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, \
  _______, _______,       _______,       _______,       _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, XXXXXXX \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_ASTR, KC_DOT,  KC_SLSH, KC_PLUS, KC_PIPE, KC_UNDS, KC_MINS, KC_EQL,  KC_PLUS, KC_COLN, _______, \
  _______, KC_BSLS, KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT,   KC_QUES, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, \
  _______, RESET,   _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] =  LAYOUT( \
  KC_CAPS, _______,    _______,    _______,    _______,    _______, _______,       _______,       _______,     _______,       _______, KC_SLEP, \
  _______, LCTL(KC_Q), LCTL(KC_W), _______,    _______,    _______, KC_HOME,       KC_PGDN,       KC_PGUP,     KC_END,        _______, LCTL(KC_BSPC), \
  _______, LCTL(KC_A), _______,    LCTL(KC_D), KC_WBAK,    KC_WFWD, KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT,       _______, KC_DEL, \
  _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), _______, _______, \
  KC_MPRV, KC_MPLY,    KC_MNXT,    _______,    _______,    _______, _______,       _______,       _______,     KC_VOLD,       KC_VOLU, KC_MUTE \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
