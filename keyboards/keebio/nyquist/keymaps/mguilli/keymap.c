#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _RAISE 1
#define _NUMPAD 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Sft/( |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Sft/) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Numpad| GUI  | Alt  |Lower |Enter |Space |Lower | Left | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT( \
  KC_GRV,          KC_1, KC_2,    KC_3,    KC_4,       KC_5,   KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB,          KC_Q, KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LCTL_T(KC_ESC),  KC_A, KC_S,    KC_D,    KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSPO,         KC_Z, KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_UP,   KC_RSPC, \
  KC_LCTL,  TT(_NUMPAD), KC_LGUI, KC_LALT, MO(_RAISE), KC_ENT, KC_SPC, MO(_RAISE), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |Reset |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |Sleep |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | F11  | F12  | Play | WBck | WFwd |  =   |   -  |   +  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Prev | Next | Vol- | Vol+ | Mute |      |  _   |  \   |  {   | PgUp |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SLEP, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F11,  KC_F12,  KC_MPLY, KC_WBAK, KC_WFWD,  KC_EQL, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, \
  _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_UNDS, KC_BSLS, KC_LCBR, KC_PGUP, KC_RCBR, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |RgbMod|RgbTog|NumLck|  /   |  *   |  -   |PScrn |Pause |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  Up  |      | Hue- | Hue+ |  7   |   8  |   9  |   +  |      | Bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right| Sat- | Sat+ |  4   |   5  |   6  |   +  |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | Brt- | Brt+ |   1  |   2  |   3  | Ent  | PgUp |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |Space |   .  | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT( \
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_TOG, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_PSCR, KC_PAUS, \
  _______, XXXXXXX, KC_UP,   XXXXXXX, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, KC_BSPC, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, KC_DEL, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PGUP, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, KC_P0,   KC_SPC,  KC_PDOT, KC_HOME, KC_PGDN, KC_END \
)

};
