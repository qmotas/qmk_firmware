/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define TAPPING_TERM 100
#define PERMISSIVE_HOLD

extern keymap_config_t keymap_config;

enum planck_layers { _OSX_BASE, _WINDOWS, _LOWER, _RAISE, _SWITCH, _FUNCTION, _ADJUST };

enum user_macro { UM_EMHL, UM_KHKR };

#define M_EMHL MACROTAP(UM_EMHL)  // 「Lower」キー用のキーコード
#define M_KHKR MACROTAP(UM_KHKR)  // 「Raise」キー用のキーコード

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Default layer for mac OSX
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | LCmd |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Fn   | GUI  | Ctrl | Alt  | Lower|    Space    | Raise| Alt  | Shift| GUI  |Fn    |
     * |      |      |      |      |(Eisu)|             |(Kana)|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_OSX_BASE] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        LCMD_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        MO(_FUNCTION), KC_LGUI, KC_LCTL, LM(_SWITCH, MOD_LALT), M_EMHL, KC_SPC, M_KHKR, KC_RALT, KC_LSFT, KC_RGUI, MO(_FUNCTION)),

    /* Windows
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Ctrl |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      | ---  |      |             |      | ---  |      |      |      |
     * |      |      |      |(MHEN)|      |             |      |(HENK)|      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_WINDOWS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RCTL_T(KC_TAB), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |    1 |    2 |    3 |    4 |    5 |    6 |    7 |    8 |    9 |    0 |   -  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |    4 |    5 |    6 |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |    1 |    2 |    3 |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |    0 |    . |    , |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT(
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_COMM, _______, _______),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   `  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Switch
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |  Tab |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_SWITCH] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Function
     * ,-----------------------------------------------------------------------------------.
     * |  Tab |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F11 |  F12 |      |      |      | PgUp |      |      |  Up  |PrtScr|ScrLck|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      | PgDn | Home | Left | Right| End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      | Down |Adjust|      |
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTION] = LAYOUT(
        KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,
        _______, KC_F11, KC_F12, _______, _______, _______, KC_PGUP, _______, _______, KC_UP, KC_PSCR, KC_SLCK,
        _______, _______, _______, _______, _______, _______, KC_PGDN, KC_HOME, KC_LEFT, KC_RGHT, KC_END, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_DOWN, MO(_ADJUST), _______),

    /* Adjust
     * ,-----------------------------------------------------------------------------------.
     * |      |  osx |  win |      |RESET | hue- | hue+ |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      | sat- | sat+ |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      | val- | val+ |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |on/off|plain |      |      |<-mode|             |mode->|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT(
        _______, DF(_OSX_BASE), DF(_WINDOWS), _______, RESET, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_M_P, _______, _______, RGB_RMOD, _______, RGB_MOD, _______, _______, _______, _______)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case UM_EMHL:  // タップで「英数」と「無変換」、ホールドで「Lower」
      return MACRO_TAP_HOLD_LAYER(record, MACRO(T(MHEN), T(LANG2), END), _LOWER);
    case UM_KHKR:  // タップで「かな」と「変換」、ホールドで「Raise」
      return MACRO_TAP_HOLD_LAYER(record, MACRO(T(HENK), T(LANG1), END), _RAISE);
  };
  return MACRO_NONE;
}