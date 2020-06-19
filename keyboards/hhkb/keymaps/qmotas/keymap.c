/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

enum layers
{
  OSX_BASE = 0,
  WIN_BASE,
  FN_MODS,
  FN_HHKB_OSX,
  FN_HHKB_WIN,
  ADJUSTIVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Default layer for mac OSX
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Backs |
     * |-----------------------------------------------------------------------------------------|
     * |   LCmd   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Shift  | Fn  |
     * `-----------------------------------------------------------------------------------------'
     *           |LCtl |英数/CMD|                Space               |かな/Mod|RAlt |
     *           `-----------------------------------------------------------------'
     */
    [OSX_BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCMD, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(FN_HHKB_OSX),
        KC_LCTL, LCMD_T(KC_LANG2), KC_SPC, LT(FN_MODS, KC_LANG1), KC_RALT),

    /* Base layer for Windows
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------|
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------|
     * |   Ctrl   |     |     |     |     |     |     |     |     |     |     |     |            |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |     |     |     |     |     |         | Fn  |
     * `-----------------------------------------------------------------------------------------'
     *           |     |無変換/Alt|                                   |変換/Mod|     |
     *           `-----------------------------------------------------------------'
     */
    [WIN_BASE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(FN_HHKB_WIN),
        _______, LALT_T(KC_MHEN), _______, LT(FN_MODS, KC_HENK), _______),

    /* Modifiers layer
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |     | Del |
     * |-----------------------------------------------------------------------------------------|
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------|
     * |          |Ctrl |Shift| Alt |     |     |     |     |     |     |     |     |            |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |     |     |     |     |     |         |     |
     * `-----------------------------------------------------------------------------------------'
     *           |     |        |                                    |       |     |
     *           `-----------------------------------------------------------------'
     */
    [FN_MODS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LCTL, KC_LSFT, KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______),

    /* Functions layer for mac OSX (based on HHKB Fn)
     * ,-----------------------------------------------------------------------------------------.
     * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
     * |-----------------------------------------------------------------------------------------|
     * |  Caps  |     |     |     |     |     |     |     | Psc | Slk | Pus | Up  |     |  BSp   |
     * |-----------------------------------------------------------------------------------------|
     * |          |     |     |     |     |     |     |     | Hom | PgU | Lef | Rig |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |     |     | End | PgD | Dow |  Fn_ADJ |     |
     * `-----------------------------------------------------------------------------------------'
     *           |     |        |                                    |       |     |
     *           `-----------------------------------------------------------------'
     */
    [FN_HHKB_OSX] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, _______, KC_BSPC,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_END, KC_PGDN, KC_DOWN, MO(ADJUSTIVE), _______,
        _______, _______, _______, _______, _______),

    /* Functions layer for Windows (based on HHKB Fn)
     * ,-----------------------------------------------------------------------------------------.
     * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
     * |-----------------------------------------------------------------------------------------|
     * |  Caps  |     |     |     |     |     |     |     | Psc | Slk | Pus | Up  | Win |  BSp   |
     * |-----------------------------------------------------------------------------------------|
     * |          |     |     |     |     |     |     |     | Hom | PgU | Lef | Rig |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |     |     | End | PgD | Dow |  Fn_ADJ |     |
     * `-----------------------------------------------------------------------------------------'
     *           |     |        |                                    |       |     |
     *           `-----------------------------------------------------------------'
     */
    [FN_HHKB_WIN] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_RWIN, KC_BSPC,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_END, KC_PGDN, KC_DOWN, MO(ADJUSTIVE), _______,
        _______, _______, _______, _______, _______),

    /* Adjustive control
     * ,-----------------------------------------------------------------------------------------.
     * |     | osx | win |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------|
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------|
     * |          |     |     |     |     |     |     |     |     |     |     |     |            |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |     |     |     |     |     |         |     |
     * `-----------------------------------------------------------------------------------------'
     *           |     |        |                                    |       |     |
     *           `-----------------------------------------------------------------'
     */
    [ADJUSTIVE] = LAYOUT(
        _______, DF(OSX_BASE), DF(WIN_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______)};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
  {
  case 0:
    if (record->event.pressed)
    {
      register_code(KC_RSFT);
    }
    else
    {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};