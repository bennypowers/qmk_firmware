#include "keycodes.h"

#define BASE_LAYER KEYMAP(
    // Base Layer Left Hand
    KC_GRV,         KC_1,   KC_2,   KC_3,    KC_4,   KC_5, KC_ATM,
    LT(SYMB,KC_TAB),KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, TG(SYMB),
    LT(VIMY,KC_ESC),KC_A,   KC_S,   KC_D,    KC_F,   KC_G,
    KC_LSFT,        KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_EQL,
    KC_LCTL,        KC_LALT,KC_LPRN,KC_LBRC, KC_LCBR,

                                                                KC_LEFT,KC_DOWN,
                                                                        KC_HOME,
                                                GUI_T(KC_SPC),  KC_DEL, KC_END,

    // Base Layer Right Hand
                              KC_ATP,  KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS,
                              TG(MOUS),KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS,
                                       KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT,
                              KC_PLUS, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_LSFT,
                                             KC_RCBR,KC_RBRC, KC_RPRN,KC_RALT,KC_RCTL,

    KC_UP,  KC_RGHT,
    KC_PGUP,
    KC_PGDN, LT(MOUS,KC_ENT), GUI_T(KC_BSPC)
  ),
