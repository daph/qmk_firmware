#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _ARROW 1
#define _SYMB 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CL/Tab|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LGui |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   =  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ~L1  |   \  | Alt  | Ctrl |Space |Enter | Bksp |Shift |  Alt | Down |  Up  | ~L2  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  MT(MOD_LCTL,KC_TAB),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, \
  MO(1),   KC_BSLS, KC_LALT, KC_LCTL, KC_SPC,  KC_ENT,  KC_BSPC, KC_LSFT, KC_LALT, KC_DOWN, KC_UP,   OSL(2) \
),

/* Arrow
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |   [  |   7  |   8  |   9  |   =  |RESET |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F7  |  F8  |  UP  |  F9  |  F10 |  F11 |   ]  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | LEFT | DOWN |RIGHT |      |  F12 |      |   1  |   2  |   3  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROW] = KEYMAP( \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_EQL,  RESET, \
  KC_F7,    KC_F8,    KC_UP,    KC_F9,   KC_F10,  KC_F11,  KC_RBRC, KC_4,    KC_4,    KC_6,    KC_MINS, KC_TRNS, \
  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_TRNS, KC_F12,  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_0,    KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),

/* Arrow
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  (   |   )  |   [  |   ]  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = KEYMAP( \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS,  S(KC_9),  S(KC_0),  KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
