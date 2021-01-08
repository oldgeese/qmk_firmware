#include QMK_KEYBOARD_H
#include "eeconfig.h"
#include "keymap_jis2us.h"
#include "action_pseudo_lut.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _PSEUDO_US 5
#define _PSEUDO_US_LOWER 6
#define _PSEUDO_US_RAISE 7
#define _VIM 11
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PSEUDO_US,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define CTL_ESC  CTL_T(KC_ESC)
#define SFT_ENT  MT(MOD_RSFT, KC_ENT)
#define VIM_F    LT(_VIM, KC_F)
#define LO_EISU  LT(_LOWER, KC_LANG2)
#define RA_KANA  LT(_RAISE, KC_LANG1)
#define P_LO_EI  LT(_PSEUDO_US_LOWER, KC_MHEN)
#define P_RA_KN  LT(_PSEUDO_US_RAISE, KC_HENK)
#define M_ALTPSC M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  Alt |  GUI |Lower |Space | GUI  |GUI   |Space |Raise |  GUI |  Alt |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_ESC, KC_A,    KC_S,    KC_D,    VIM_F,   KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
                 KC_LALT, KC_LGUI, LO_EISU,  KC_SPC, KC_LGUI,  KC_RGUI, KC_SPC,RA_KANA,   KC_RGUI, KC_RALT\
),

/* Qwerty(PSEUDO_US)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  Alt |  GUI |Lower |Space | GUI  |GUI   |Space |Raise |  GUI |  Alt |
 *               `---------------------------------------------------------------------'
 */
[_PSEUDO_US] = LAYOUT( \
  KC_FN1,KC_FN1,  KC_FN1,  KC_FN1,  KC_FN1,  KC_FN1,                   KC_FN1,  KC_FN1,  KC_FN1,  KC_FN1,  KC_FN1,  KC_FN1, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
  CTL_ESC, KC_A,    KC_S,    KC_D,    VIM_F,   KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_FN1,  KC_FN1, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_FN1, KC_FN1,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_FN1, SFT_ENT, \
                 KC_LALT, KC_LGUI, P_LO_EI,  KC_SPC, KC_LGUI, KC_RGUI, KC_SPC,P_RA_KN,   KC_RGUI, KC_RALT\
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F11 |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |   {  |   }  |  F12 |ISO ~ |ISO | |   [  |   ]  |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F11,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LCBR, KC_RCBR, KC_F12,S(KC_NUHS),S(KC_NUBS),KC_LBRC,KC_RBRC, _______,\
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F11 |   -  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |  F12 |ISO # |ISO / |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                      KC_F11, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_LCBR, KC_RCBR,   KC_F12, KC_NUHS, KC_NUBS, _______, _______, _______, \
                  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Lower(PSEUDO_US)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F11 |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |   {  |   }  |  F12 |ISO ~ |ISO | |   [  |   ]  |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_PSEUDO_US_LOWER] = LAYOUT( \
  KC_TILD, KC_FN2, KC_FN2,  KC_FN2,  KC_FN2,  KC_FN2,                   KC_FN2, KC_FN2, KC_FN2, KC_FN2, KC_FN2, _______,\
  KC_TILD, KC_FN2, KC_FN2,  KC_FN2,  KC_FN2,  KC_FN2,                   KC_FN2, KC_FN2, KC_FN2, KC_FN2, KC_FN2, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F11, KC_FN2, KC_FN2, KC_FN2, KC_FN2, KC_FN2, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_FN2, KC_FN2, KC_F12, KC_FN2, KC_FN2, KC_FN2, KC_FN2, _______,\
                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),

/* Raise(PSEUDO_US)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F11 |   -  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |  F12 |ISO # |ISO / |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_PSEUDO_US_RAISE] = LAYOUT( \
  KC_GRV,  KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3,                    KC_FN3,   KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3, _______, \
  KC_GRV,  KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3,                    KC_FN3,   KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3,  KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F11,   KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3,  KC_FN3, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_FN3, KC_FN3,   KC_F12,   KC_FN3,  KC_FN3, _______, _______, _______, \
                   _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

[_VIM] = LAYOUT( \
  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  KC_LCTL,  _______,  _______,                      KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_PGUP,  _______,  _______, \
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC, \
  _______, M_ALTPSC, KC_PSCR, _______,   _______,  AG_NORM,                   AG_SWAP, QWERTY, PSEUDO_US, _______, _______, _______, \
  _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)


};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _PSEUDO_US:
      return update_tri_layer_state(state, _PSEUDO_US_RAISE, _PSEUDO_US_LOWER, _ADJUST);
      break;
    case _PSEUDO_US_LOWER:
      return update_tri_layer_state(state, _PSEUDO_US_RAISE, _PSEUDO_US_LOWER, _ADJUST);
      break;
    case _PSEUDO_US_RAISE:
      return update_tri_layer_state(state, _PSEUDO_US_RAISE, _PSEUDO_US_LOWER, _ADJUST);
      break;
    default:
      return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PSEUDO_US:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PSEUDO_US);
      }
      return false;
      break;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case 0:
        return MACRO(D(LALT), T(PSCR), U(LALT), END);
    }
  }
  return MACRO_NONE;
}

/*
 * user defined action function
 */
enum function_id {
    PSEUDO_US_FUNCTION,
    PSEUDO_US_LOWER_FUNCTION,
    PSEUDO_US_RAISE_FUNCTION,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {

    switch (id) {
        case PSEUDO_US_FUNCTION:
            action_pseudo_lut(record, _QWERTY, keymap_jis2us);
            break;
        case PSEUDO_US_LOWER_FUNCTION:
            action_pseudo_lut(record, _LOWER, keymap_jis2us);
            break;
        case PSEUDO_US_RAISE_FUNCTION:
            action_pseudo_lut(record, _RAISE, keymap_jis2us);
            break;
    }
}

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_FUNCTION(PSEUDO_US_FUNCTION),
    [2] = ACTION_FUNCTION(PSEUDO_US_LOWER_FUNCTION),
    [3] = ACTION_FUNCTION(PSEUDO_US_RAISE_FUNCTION),
};
