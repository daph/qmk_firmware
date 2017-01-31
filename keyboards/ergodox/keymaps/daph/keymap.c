#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE  0 // default layer
#define ARROW 1 // Arrow keys and numpad
#define SYMB  2 // Symbols

#undef  TAPPING_TERM
#define TAPPING_TERM 5

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

#define TAP_UNI(hex)        \
    unicode_input_start();  \
    register_hex(hex);      \
    unicode_input_finish();

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  OSX,
  LINUX
};

enum tap_dance {
    TD_SCLN_CLN
};

enum macros {
    HELLO_M
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN)
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
 * |--------+------+------+------+------+------| |    |           | LEAD |------+------+------+------+------+--------|
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
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,  KC_QUOT,
             KC_LEAD,       KC_N,   KC_M,  KC_EQL, KC_COMM,KC_DOT,           KC_SLSH,
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
 * |  OSX    |HLO M |  UP  |      |      |      |      |           |      |   [  |   1  |   2  |   3  |   =  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LINUX  | LEFT | DOWN | RIGHT|      |      |------|           |------|   ]  |   4  |   5  |   6  |   -  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  λ   |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
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
       OSX,M(HELLO_M),KC_UP,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       LINUX,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,
       KC_TRNS,UC(0x03BB),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
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
    case OSX:
      if (record->event.pressed) {
          set_unicode_input_mode(UC_OSX);
      }
      return false;
      break;
    case LINUX:
      if (record->event.pressed) {
          set_unicode_input_mode(UC_LNX);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // Default to Linux unicode
    set_unicode_input_mode(UC_LNX);
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
}

LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Close window in i3
        SEQ_ONE_KEY(KC_Q) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_Q);
            unregister_code(KC_Q);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
        }

        // Shruggie
        SEQ_ONE_KEY(KC_S) {
            TAP_UNI(0xaf)
            TAP_ONCE(KC_BSLS);
            register_code(KC_RSFT); TAP_ONCE(KC_MINS); TAP_ONCE(KC_9); unregister_code(KC_RSFT);
            TAP_UNI(0x30c4);
            register_code(KC_RSFT); TAP_ONCE(KC_0); TAP_ONCE(KC_MINS); unregister_code(KC_RSFT);
            TAP_ONCE(KC_SLSH);
            TAP_UNI(0xaf);
        }

        // Table flip
        SEQ_ONE_KEY(KC_T) {
            register_code(KC_RSFT); TAP_ONCE(KC_9); unregister_code(KC_RSFT);
            TAP_UNI(0x256F);
            TAP_UNI(0x00B0);
            TAP_UNI(0x25A1);
            TAP_UNI(0x00B0);
            register_code(KC_RSFT); TAP_ONCE(KC_0); unregister_code(KC_RSFT);
            TAP_UNI(0x256F);
            TAP_UNI(0xFE35);
            TAP_UNI(0x253B);
            TAP_UNI(0x2501);
            TAP_UNI(0x253B);
        }
    }
};

