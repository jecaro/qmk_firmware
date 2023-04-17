#include QMK_KEYBOARD_H

#include <keymap_french.h>

#define _BL 0
#define _FL 1

enum tap_dance_key {
    TD_LGUI_FN,
};

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
     * |Ctrl |Win/Fn|Alt|         Space        |Agr|Ctrl|Win|Lef|Dow|Rig|
     * `----------------------------------------------------------------'
     */
    [_BL] = LAYOUT_65_iso(
        FR_SUP2, FR_AMPR,         FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  FR_A,            FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    FR_CIRC, FR_DLR,           KC_PGUP,
        KC_ESC,  FR_Q,            FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT,  KC_PGDN,
        KC_LSFT, FR_LABK,         FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, TD(TD_LGUI_FN),  KC_LALT,                            KC_SPC,                    KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FL1: Function Layer 1
     * ,----------------------------------------------------------------.
     * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Delete| Ins|
     * |----------------------------------------------------------------|
     * |RESET|   |   |   |   |   |   |   |   |   |   |   |   |     | NXT|
     * |-------------------------------------------------------    -----|
     * |       |   |   |   |   |   |   |   |   |   |   |  |   |    | PRV|
     * |----------------------------------------------------------------|
     * |HUI |SAI|VAI |RGBMOD| L+|LED| L-|   |   |    |   |  |Play|V+|Mut|
     * |----------------------------------------------------------------|
     * |HUD |SAD |VAD |         RGB_Tog       |   |   |   | << | V-| >> |
     * `----------------------------------------------------------------'
     */
    [_FL] = LAYOUT_65_iso(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MNXT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV,
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, KC_MUTE,
        RGB_HUD, RGB_SAD, RGB_VAD,                            RGB_TOG,                   _______, _______, KC_TRNS, KC_MRWD, KC_VOLD, KC_MFFD
    )
};

void td_lgui_fn_finished(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        register_code(KC_LGUI);
    } else {
        layer_on(_FL);
    }
}

void td_lgui_fn_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        unregister_code(KC_LGUI);
    } else {
        layer_off(_FL);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui_fn_finished, td_lgui_fn_reset),
};

enum combo_events {
  SHIFT_INSERT,
  ALT_F4,
  CTRL_ALT_SUPPR,
  CTRL_ALT_F1,
  CTRL_ALT_F2,
  CTRL_ALT_F3,
  CTRL_ALT_F4,
  CTRL_ALT_F5,
  CTRL_ALT_F6,
  CTRL_ALT_F7,
  CTRL_ALT_F8,
  CTRL_ALT_F9,
  CTRL_ALT_F10,
  CTRL_ALT_F11,
  CTRL_ALT_F12,
};

const uint16_t PROGMEM shift_insert[] = {KC_LSFT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM alt_f4[] = {KC_LALT, FR_QUOT, COMBO_END};
const uint16_t PROGMEM ctrl_alt_suppr[] = {KC_LCTL, KC_LALT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f1[] = {KC_LCTL, KC_LALT, FR_AMPR, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f2[] = {KC_LCTL, KC_LALT, FR_EACU, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f3[] = {KC_LCTL, KC_LALT, FR_DQUO, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f4[] = {KC_LCTL, KC_LALT, FR_QUOT, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f5[] = {KC_LCTL, KC_LALT, FR_LPRN, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f6[] = {KC_LCTL, KC_LALT, FR_MINS, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f7[] = {KC_LCTL, KC_LALT, FR_EGRV, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f8[] = {KC_LCTL, KC_LALT, FR_UNDS, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f9[] = {KC_LCTL, KC_LALT, FR_CCED, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f10[] = {KC_LCTL, KC_LALT, FR_AGRV, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f11[] = {KC_LCTL, KC_LALT, FR_RPRN, COMBO_END};
const uint16_t PROGMEM ctrl_alt_f12[] = {KC_LCTL, KC_LALT, FR_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SHIFT_INSERT] = COMBO_ACTION(shift_insert),
  [ALT_F4] = COMBO_ACTION(alt_f4),
  [CTRL_ALT_SUPPR] = COMBO_ACTION(ctrl_alt_suppr),
  [CTRL_ALT_F1] = COMBO_ACTION(ctrl_alt_f1),
  [CTRL_ALT_F2] = COMBO_ACTION(ctrl_alt_f2),
  [CTRL_ALT_F3] = COMBO_ACTION(ctrl_alt_f3),
  [CTRL_ALT_F4] = COMBO_ACTION(ctrl_alt_f4),
  [CTRL_ALT_F5] = COMBO_ACTION(ctrl_alt_f5),
  [CTRL_ALT_F6] = COMBO_ACTION(ctrl_alt_f6),
  [CTRL_ALT_F7] = COMBO_ACTION(ctrl_alt_f7),
  [CTRL_ALT_F8] = COMBO_ACTION(ctrl_alt_f8),
  [CTRL_ALT_F9] = COMBO_ACTION(ctrl_alt_f9),
  [CTRL_ALT_F10] = COMBO_ACTION(ctrl_alt_f10),
  [CTRL_ALT_F11] = COMBO_ACTION(ctrl_alt_f11),
  [CTRL_ALT_F12] = COMBO_ACTION(ctrl_alt_f12)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SHIFT_INSERT:
      if (pressed) {
        tap_code16(LSFT(KC_INS));
      }
      break;
    case ALT_F4:
      if (pressed) {
        tap_code16(LALT(KC_F4));
      }
      break;
    case CTRL_ALT_SUPPR:
      if (pressed) {
        tap_code16(LCA(KC_DEL));
      }
      break;
    case CTRL_ALT_F1:
      if (pressed) {
        tap_code16(LCA(KC_F1));
      }
      break;
    case CTRL_ALT_F2:
      if (pressed) {
        tap_code16(LCA(KC_F2));
      }
      break;
    case CTRL_ALT_F3:
      if (pressed) {
        tap_code16(LCA(KC_F3));
      }
      break;
    case CTRL_ALT_F4:
      if (pressed) {
        tap_code16(LCA(KC_F4));
      }
      break;
    case CTRL_ALT_F5:
      if (pressed) {
        tap_code16(LCA(KC_F5));
      }
      break;
    case CTRL_ALT_F6:
      if (pressed) {
        tap_code16(LCA(KC_F6));
      }
      break;
    case CTRL_ALT_F7:
      if (pressed) {
        tap_code16(LCA(KC_F7));
      }
      break;
    case CTRL_ALT_F8:
      if (pressed) {
        tap_code16(LCA(KC_F8));
      }
      break;
    case CTRL_ALT_F9:
      if (pressed) {
        tap_code16(LCA(KC_F9));
      }
      break;
    case CTRL_ALT_F10:
      if (pressed) {
        tap_code16(LCA(KC_F10));
      }
      break;
    case CTRL_ALT_F11:
      if (pressed) {
        tap_code16(LCA(KC_F11));
      }
      break;
    case CTRL_ALT_F12:
      if (pressed) {
        tap_code16(LCA(KC_F12));
      }
      break;
  }
}

