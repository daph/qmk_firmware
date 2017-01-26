// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0: mostly letters *
 *  Q  W  E     R     T         ||         Y    U  I O  P
 *  A  S  D     F     G         ||         H    J  K L  '
 *  Z  X  C     V     B         ||         N    M  , .  fn
 * tab esc super ctrl space enter|| bksp shift alt - ; /
 */

  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MO(1), \
         KC_TAB, KC_ESC, KC_LGUI, KC_LCTL, KC_SPC, KC_ENT, KC_BSPC,     \
         KC_LSFT, KC_LALT, KC_MINS, KC_SCLN, KC_SLSH),                     \

/*
 *  1  2   3     4    5          ||       6   7     8     9    0
 *  6  7   8     9    0          ||       l   d     u     r    
 *  -  ;   =     `    \          ||       pgup  [     ]     3    fn
 *  \  L2 super ctrl space enter || bksp shift  pgdn   .     0    \
 */
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, \
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, \
        KC_MINS, KC_SCLN, KC_EQUAL, KC_GRAVE, KC_BSLS, KC_PGUP, KC_LBRC, KC_RBRC, KC_3, KC_TRNS,    \
        KC_BSLS,MO(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_DOT, KC_0, KC_BSLS),

/*
 * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
 *       volup             reset      ||             F1    F2    F3   F12
 *             super ctrl space enter || back shift     prtsc scroll pause
 */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, \
                         KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
                         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, \
                         KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,          \
                         KC_NO, KC__VOLUP, KC_NO, KC_NO, RESET, \
                         KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,            \
                         KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCREEN, KC_SLCK, KC_PAUSE)

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
