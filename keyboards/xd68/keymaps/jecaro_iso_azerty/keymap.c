#include QMK_KEYBOARD_H

#include <keymap_french.h>

#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |²  |  &|  é|  "|  '|  (|  -|  è|  _|  ç|  à|  )|  =|Backsp |Home|
     * |----------------------------------------------------------------|
     * |Tab  |  A|  Z|  E|  R|  T|  Y|  U|  I|  O|  P|  ^|  $|     |PgUp|
     * |-------------------------------------------------------    -----|
     * |ESC    |  Q|  S|  D|  F|  G|  H|  J|  K|  L|  M| ù|  *|Entr|PgDn|
     * |----------------------------------------------------------------|
     * |Shift|   <|  W|  X|  C|  V|  B|  N|  ,|  ;|  :| !|Rshift|Up|End |
     * |----------------------------------------------------------------|
     * |Ctrl |Win  |Alt|          Space        |Agr|Ctrl|Fn|Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [_BL] = LAYOUT_65_iso(
        FR_SUP2, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    FR_CIRC, FR_DLR,           KC_PGUP,
        KC_ESC,  FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT,  KC_PGDN,
        KC_LSFT, FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FL1: Function Layer 1
     * ,----------------------------------------------------------------.
     * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Delete| Ins|
     * |----------------------------------------------------------------|
     * |RESET|   | ↑ |   |   |   |   |   |   |   |   |   |   |     |    |
     * |-------------------------------------------------------    -----|
     * |       | ← | ↓ | → |   |   |   |   |   |   |   |  |   |    |    |
     * |----------------------------------------------------------------|
     * |HUI |SAI|VAI |RGBMOD| L+|LED| L-|   |   |    |   |  |Play|V+|Mut|
     * |----------------------------------------------------------------|
     * |HUD |SAD |VAD |         RGB_Tog       |   |   |   | <M | V-| M> |
     * `----------------------------------------------------------------'
     */
    [_FL] = LAYOUT_65_iso(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
        RESET,   _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, KC_MUTE,
        RGB_HUD, RGB_SAD, RGB_VAD,                            RGB_TOG,                   _______, _______, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
    )
};

enum combo_events {
  SHIFT_BACKSPACE_SHIFT_INSERT,
};

const uint16_t PROGMEM shift_insert_combo[] = {KC_LSFT, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SHIFT_BACKSPACE_SHIFT_INSERT] = COMBO_ACTION(shift_insert_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SHIFT_BACKSPACE_SHIFT_INSERT:
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
  }
}
