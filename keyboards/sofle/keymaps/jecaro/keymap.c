#include QMK_KEYBOARD_H

#include <keymap_french.h>

#include "features/layer_lock.h"

enum sofle_layers {
    _AZERTY = 0,
    _NAVIGATION,
    _SYMBOLS,
    _NUMBERS,
};

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
};

#define NAV(_x_) LT(_NAVIGATION, _x_)
#define SYM(_x_) LT(_SYMBOLS, _x_)
#define NUM(_x_) LT(_NUMBERS, _x_)

// TODO: add combo
// ctrl + alt + del
// ctrl + alt + f1-f12
// show modifiers on oled

// layers: base, symbols, navigation, numbers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Mic mute ?
/*
 * AZERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | + =  |  1 & |  2 é |  3 " |  4 ' |  5 ( |                    |  6 - |  7 è |  8 _ |  9 ç |  0 à |  ° ) |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ^ " |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   M  |  ù % |
 * |------+------+------+------+------+------| MUTE  |    | PLAY  |------+------+------+------+------+------|
 * |LShift|   W  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |  , ? |  ; . |  : / |  ! § |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCtr | LGUI | LAlt |ESC   | /Space  /       \Enter \  |Bspc  | RAlt | RGUI | RCtr |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_AZERTY] = LAYOUT( \
  FR_EQL,  FR_AMPR,  FR_EACU,  FR_DQUO, FR_QUOT,     FR_LPRN,                       FR_MINS,     FR_EGRV, FR_UNDS,  FR_CCED, FR_AGRV, FR_RPRN, \
  KC_TAB,  FR_A,     FR_Z,     FR_E,    FR_R,        FR_T,                          FR_Y,        FR_U,    FR_I,     FR_O,    FR_P,    FR_CIRC, \
  KC_ESC,  FR_Q,     FR_S,     FR_D,    FR_F,        FR_G,                          FR_H,        FR_J,    FR_K,     FR_L,    FR_M,    FR_UGRV, \
  KC_LSFT, FR_W,     FR_X,     FR_C,    FR_V,        FR_B,        KC_MUTE, KC_MPLY, FR_N,        FR_COMM, FR_SCLN,  FR_COLN, FR_EXLM, KC_RSFT, \
           KC_LCTRL, KC_LGUI, KC_LALT,  NUM(KC_ESC), NAV(KC_SPC),                   SYM(KC_ENT), KC_BSPC, KC_RALT,  KC_RGUI, KC_RCTRL \
),

/*
 * Navigation
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Home |PgDown| PgUp | End  | Del  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAVIGATION] = LAYOUT( \
  LLOCK,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_DEL,  KC_F12, \
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
           _______, _______, _______, _______, _______,                   _______, _______, _______, _______,  _______ \
),

/*
 * Symbols hold enter
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |  ~   |  #   |  {   |  [   |                    |  |   |  `   |  \   |      |  @   |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  €   |      |  (   |                    |  )   |  ^   |  $   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  [   |-------.    ,-------|  ]   |  *   |  #   |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |  {   |-------|    |-------|  }   |  <   |  >   |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT( \
  LLOCK,   _______, FR_TILD, FR_HASH, FR_LCBR, FR_LBRC,                   FR_PIPE, FR_GRV,  FR_BSLS, _______, FR_AT,   FR_RBRC, \
  _______, _______, _______, FR_EURO, _______, FR_LPRN,                   FR_RPRN, FR_CIRC, FR_DLR,  _______, _______, _______, \
  _______, _______, _______, _______, _______, FR_LBRC,                   FR_RBRC, FR_ASTR, FR_HASH, _______, _______, _______, \
  _______, _______, _______, _______, _______, FR_LCBR, _______, _______, FR_RCBR, FR_LABK, FR_RABK, _______, _______, _______, \
           _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ \
),

/*
 * Numbers
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |  7   |  8   |  9   |  *   |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  4   |  5   |  6   |  +   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  1   |  2   |  3   |  (   |  )   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  0   |  ,   |  .   |  =   |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMBERS] = LAYOUT( \
  LLOCK,   _______, _______, _______, _______, _______,                   _______, FR_7,    FR_8,    FR_9,   FR_ASTR, FR_SLSH, \
  _______, _______, _______, _______, _______, _______,                   _______, FR_4,    FR_5,    FR_6,   FR_PLUS, FR_MINS, \
  _______, _______, _______, _______, _______, _______,                   _______, FR_1,    FR_2,    FR_3,   FR_LPRN, FR_RPRN, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, FR_0,    FR_COLN, FR_DOT, FR_EQL,  KC_ENT,  \
           _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK))
    {
        return false;
    }

  return true;
}

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(layer_state)) {
        case _AZERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _NAVIGATION:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    return true;
}

#endif
