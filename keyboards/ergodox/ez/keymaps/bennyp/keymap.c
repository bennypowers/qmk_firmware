#include "ergodox.h"
#include "config.h"
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define _______ KC_TRNS
#define KC_ATM LGUI(LSFT(KC_P))
#define KC_ATP LGUI(LCTL(KC_P))

#define BASE 0
#define SYMB 3
#define VIMY 2
#define MOUS 1

#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VIM_END,
  VIM_WOR,
  VIM_BAK,
  VIM_YAN,
  VIM_PUT,
  VIM_OPN,
  VIM_UDO,
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap 0: Basic layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |    `   |   1  |   2  |   3  |   4  |   5  | ⇧⌘P  |           | PROJ |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |⇥ / SYMB|   Q  |   W  |   E  |   R  |   T  |MOUSE |           | SYMB |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | ⎋ / VIM|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  * |--------+------+------+------+------+------|   =  |           |   +  |------+------+------+------+------+--------|
  * |   L⇧   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   R⇧   |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |  ⌃  |   ⌥  |  (   |  [   |   {  |                                       |  }   |  ]   |   )  |   ⌥   |   ⌃  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |   ←  |   ↓  |       |   ↑  |   →  |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |SPACE |      | Home |       | PgUp |ENTER | BSPC |
  *                                 |      | DEL  |------|       |------|      |      |
  *                                 |   ⌘  |      | End  |       | PgDn |MOUSE |   ⌘  |
  *                                 `--------------------'       `--------------------'
  */

  [BASE] = KEYMAP(
    // Base Layer Left Hand
    KC_GRV,         KC_1,   KC_2,   KC_3,    KC_4,   KC_5, KC_ATM,
    LT(SYMB,KC_TAB),KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, TG(MOUS),
    LT(VIMY,KC_ESC),KC_A,   KC_S,   KC_D,    KC_F,   KC_G,
    KC_LSFT,        KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_EQL,
    KC_LCTL,        KC_LALT,KC_LPRN,KC_LBRC, KC_LCBR,

                                                                KC_LEFT,KC_DOWN,
                                                                        KC_HOME,
                                                GUI_T(KC_SPC),  KC_DEL, KC_END,

    // Base Layer Right Hand
                              KC_ATP,  KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS,
                              TG(SYMB),KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS,
                                       KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,LT(VIMY, KC_QUOT),
                              KC_PLUS, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_RSFT,
                                             KC_RCBR,KC_RBRC, KC_RPRN,KC_RALT,KC_RCTL,

    KC_UP,  KC_RGHT,
    KC_PGUP,
    KC_PGDN, LT(MOUS,KC_ENT), GUI_T(KC_BSPC)
  ),

  /* Keymap 1: Symbol and Calc layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * | Version|  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |      |   7  |   8  |   9  |   -  |   F12  |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |   #  |   $  |   [  |   ]  |   &  |------|           |------|      |   4  |   5  |   6  |   +  |   F13  |
  * |--------+------+------+------+------+------|      |           |  =   |------+------+------+------+------+--------|
  * |        |   %  |   ^  |   (  |   )  |   ~  |      |           |      |      |   1  |   2  |   3  |   *  |  F14   |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |      |  0   |   .  |   /  |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */

  [SYMB] = KEYMAP(
    // Layer 1 Left Hand
    M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
    _______,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,_______,
    _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_AMPR,
    _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,_______,
    _______,_______,_______,_______,_______,

                                                              _______,_______,_______,
                                                              _______,_______,_______,

    // Layer 1 Right Hand
                              _______,KC_F6,  KC_F7,  KC_F8,  KC_F9,KC_F10, KC_F11,
                              _______,_______,KC_7,   KC_8,   KC_9,   KC_MINS,KC_F12,
                                      _______,KC_4,   KC_5,   KC_6,   KC_PLUS,_______,
                              KC_EQL ,_______,KC_1,   KC_2,   KC_3,   KC_ASTR,_______,
                                              _______,KC_0,   KC_DOT, KC_SLSH,_______,

    _______,_______,_______,
    _______,_______,_______
  ),

  /* Keymap 2: Vim commands layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      | WORD |  END |      |      |      |           |      | YANK | UNDO |      | OPEN |  PUT |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |  DEL |      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |VISUAL| BACK |      |           |      |      |      |      |      |      |        |
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

  [VIMY] = KEYMAP(
    // Layer 2 Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,VIM_WOR,VIM_END,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,KC_DEL ,_______,_______,VIM_BAK,_______,
    _______,_______,_______,_______,_______,

                                                              _______,_______,_______,
                                                              _______,_______,_______,

    // Layer 2 Right Hand
                              _______,_______,_______,_______,_______,_______,_______,
                              _______,VIM_YAN,VIM_UDO,_______,VIM_OPN,VIM_PUT,_______,
                                      KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,_______,
    _______,_______,_______
  ),

  /* Keymap 2: Mouse, and Media layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        | ☀️↑  | ☀️↓  |      |      |      |      |           |      |  ⏪   |  ▶️  |  ⏩   | 🔇   |  🔈   |   🔊    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |  MB3 |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |------|           |------|      | MB1  |MOUSEU| MB2  |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |MOUSEL|MOUSED|MOUSER|      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      |      |      |                                       |WHEELU|      |WHEELD|      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |      |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */

  [MOUS] = KEYMAP(
    // Layer 3 Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                              _______,_______,_______,
                                                              _______,_______,_______,

    // Layer 2 Right Hand
                              _______,KC_MRWD,KC_MPLY,KC_MFFD,KC_MUTE,KC_VOLD,KC_VOLU,
                              _______,_______,_______,KC_BTN3,_______,_______,_______,
                                      _______,KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,
                              _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,KC_ACL1,_______,
                                              KC_WH_U,_______,KC_WH_D,KC_ACL0,_______,

    _______,_______,_______,
    _______,_______,_______
  )

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0:
        if (record->event.pressed) { SEND_STRING (VERSION_STRING); }
        break;
  }
return MACRO_NONE;
};

void TAP(uint16_t keycode) {
    PRESS(keycode);
    RELEASE(keycode);
}

/**
 * Vim-like `open` command.
 * Works by moving cursor to the end of the current line,
 * then opening a new line with `enter`.
 */
void VIM_COMMAND_O(void) {
  TAP(KC_END);
  TAP(KC_ENTER);
}

/**
 * Vim-like `word` command
 * Simulates vim's `w` command by moving the cursor first to the
 * end of the current word, then to the end of the next word,
 * then to the beginning of that word.
 */
void VIM_COMMAND_W(void) {
  PRESS(KC_LALT);
  TAP(KC_RIGHT);
  TAP(KC_RIGHT);
  TAP(KC_LEFT);
  RELEASE(KC_LALT);
}

/**
 * Vim-like `end` command
 * Simulates vim's `e` command by sending ⌥→
 */
void VIM_COMMAND_E(void) {
  PRESS(KC_LALT);
  TAP(KC_RGHT);
  RELEASE(KC_LALT);
}

/**
 * Vim-like `back` command
 * Simulates vim's `b` command by sending ⌥←
 */
void VIM_COMMAND_B(void) {
  PRESS(KC_LALT);
  TAP(KC_LEFT);
  RELEASE(KC_LALT);
}

/**
 * Vim-like `yank` command
 * Simulates vim's `y` command by sending ⌘C
 */
void VIM_COMMAND_Y(void) {
  PRESS(KC_LGUI);
  TAP(KC_C);
  RELEASE(KC_LGUI);
}

/**
 * Vim-like `put` command
 * Simulates vim's `p` command by sending ⌘V
 */
void VIM_COMMAND_P(void) {
  PRESS(KC_LGUI);
  TAP(KC_V);
  RELEASE(KC_LGUI);
}

/**
 * Vim-like `undo` command
 * Simulates vim's `u` command by sending ⌘Z
 */
void VIM_COMMAND_U(void) {
  PRESS(KC_LGUI);
  TAP(KC_Z);
  RELEASE(KC_LGUI);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false;

    case VRSN:
      if (record->event.pressed) { SEND_STRING(VERSION_STRING); }
      return false;

    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false;

    case VIM_OPN:
      if (record->event.pressed) { VIM_COMMAND_O(); }
      return false;

    case VIM_WOR:
      if (record->event.pressed) { VIM_COMMAND_W(); }
      return false;

    case VIM_END:
      if (record->event.pressed) { VIM_COMMAND_E(); }
      return false;

    case VIM_BAK:
      if (record->event.pressed) { VIM_COMMAND_B(); }
      return false;

    case VIM_YAN:
      if (record->event.pressed) { VIM_COMMAND_Y(); }
      return false;

    case VIM_PUT:
      if (record->event.pressed) { VIM_COMMAND_P(); }
      return false;

    case VIM_UDO:
      if (record->event.pressed) { VIM_COMMAND_U(); }
      return false;

  }
  return true;
};

void matrix_init_user(void) {
  debug_enable = true;
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
