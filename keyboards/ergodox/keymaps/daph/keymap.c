#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE  0 // default layer
#define ARROW 1 // Arrow keys and numpad
#define SYMB  2 // Symbols

#define TAPPING_TERM 100

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN
};

enum tap_dance {
    TD_SCLN_CLN
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, S(KC_SCLN))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Del  |           | [    |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |'       |
 * |--------+------+------+------+------+------| |    |           | :    |------+------+------+------+------+--------|
 * |  LGui  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   =  |   ,  | .    |   /    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |~L1| `|  \  |   ,  | Ctrl  |                                        |  Alt |  Up  | Down | Right| ~L2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LEAD |Shift |       | Alt  | Alt  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|Bckspc  |Shift |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_DEL,
        KC_ESC,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_TAB,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LGUI, KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   S(KC_BSLS),
        MO(1),          KC_GRV,       KC_BSLS,     KC_COMM,   KC_LCTL,
                                                    KC_LEAD,  KC_LSFT,
                                                              KC_HOME,
                                               KC_SPC,KC_ENT ,KC_END,
        // right hand
             KC_LBRC,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSLS,
             KC_RBRC,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   KC_J,  KC_K,   KC_L,   TD(TD_SCLN_CLN),  KC_QUOT,
             S(KC_SCLN),  KC_N,   KC_M,  KC_EQL, KC_COMM,KC_DOT,           KC_SLSH,
                                  KC_LALT,KC_UP, KC_DOWN,KC_RIGHT,         MO(2),
             KC_LALT,        KC_LALT,
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_LSFT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  |  F12 | RESET  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  UP  |      |      |      |      |           |      |   [  |   1  |   2  |   3  |   =  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | LEFT | DOWN | RIGHT|      |      |------|           |------|   ]  |   4  |   5  |   6  |   -  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |   0  |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// ARROW
[ARROW] = KEYMAP(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  RESET,
       KC_TRNS, KC_LBRC, KC_1,   KC_2,    KC_3,    KC_EQL,  KC_TRNS,
                KC_RBRC, KC_4,   KC_5,    KC_6,    KC_MINS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_7,   KC_8,    KC_9,    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_0,    KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  <   |   >  |   9  |  0   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   [  |   ]  |   -  |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[SYMB] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, S(KC_COMM),S(KC_DOT),KC_9, KC_0, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LBRC, KC_LBRC, KC_MINUS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_Q) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_Q);
            unregister_code(KC_Q);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
        }
    }
};

