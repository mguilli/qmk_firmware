#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _ADJUST 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Esc  │   1  │   2  │   3  │   4  │   5  │  -   │      │  =   │   6  │   7  │   8  │   9  │   0  │  `   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │  [   │ Mute │  ]   │   Y  │   U  │   I  │   O  │   P  │  \   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctl  │   A  │   S  │   D  │   F  │   G  ├──────┼──────┼──────┤   H  │   J  │   K  │   L  │   ;  │  '   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   C  │   V  │   B  │  (   │ Home │  )   │   N  │   M  │   ,  │   .  │   /  │Shift │
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │ Lower│Adjust│ Alt  │ GUI  │    Space    │ Enter│      │Bkspc │    Space    │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */
    [_QWERTY] = LAYOUT( \
        KC_ESC,  KC_1,  KC_2,    KC_3,    KC_4,   KC_5,   KC_MINS, KC_EQL,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_GRV,  \
        KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,   KC_T,   KC_LBRC, KC_RBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS, \
        KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,   KC_G,   KC_MUTE, KC_HOME, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,   KC_B,   KC_LPRN, KC_RPRN, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
        MO(1),   MO(5), KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_ENT,  KC_BSPC, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
    ),

/* Lower
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ F11  │  F1  │  F2  │  F3  │  F4  │  F5  │      │      │      │  F6  │  F7  │  F8  │  F9  │  F10 │  F12 │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  ~   │   !  │   @  │   #  │   $  │   %  │      │      │      │   ^  │   &  │   *  │   (  │   )  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  `   │   1  │   2  │   3  │   4  │   5  ├──────┼──────┼──────┤   6  │   7  │   8  │   9  │   0  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │             │      │      │      │             │      │      │      │      │
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */
    [_LOWER] = LAYOUT( \
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______  \
    ),

/* Adjust
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐      ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Reset│      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C6*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ├──────┼──────┼──────┤      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤      │*R2C7*│      ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │             │      │      │      │             │      │      │      │      │
 * └──────┴──────┴──────┴──────┴─────────────┴──────┘      └──────┴─────────────┴──────┴──────┴──────┴──────┘
 */
    [_ADJUST] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}
