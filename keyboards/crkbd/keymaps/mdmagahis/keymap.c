/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_Z LSFT_T(KC_Z)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_SL RSFT_T(KC_SLSH)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

// Tab Navigation
#define TAB_P SGUI(KC_LBRC)
#define TAB_N SGUI(KC_RBRC)

// Edit Funs
#define U_UND LGUI(KC_Z)
#define U_CUT LGUI(KC_X)
#define U_CPY LGUI(KC_C)
#define U_PST LGUI(KC_V)
#define U_RDO SGUI(KC_Z)

#define U_HSTB LGUI(KC_LBRC)
#define U_HSTF RGUI(KC_RBRC)

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
    PARENS = SAFE_RANGE,
    BRCKTS,
    CBRCKTS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PARENS:
        if (record->event.pressed) {
            // when keycode PARENS is pressed
            SEND_STRING("()"SS_TAP(X_LEFT));
        }
        return false;
    case BRCKTS:
        if (record->event.pressed) {
            // when keycode BRCKTS is pressed
            SEND_STRING("[]"SS_TAP(X_LEFT));
        }
        return false;
    case CBRCKTS:
        if (record->event.pressed) {
            // when keycode CBRCKTS is pressed
            SEND_STRING("{}"SS_TAP(X_LEFT));
        }
        return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                 ,-----------------------------------------------------------.
             KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,   KC_L,    KC_U,    KC_Y, KC_MINS,        KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------|                 |--------+-------+--------+--------+--------+---------------|
      ALL_T(KC_ESC),  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                      KC_M, HOME_N,  HOME_E,  HOME_I,  HOME_O, ALL_T(KC_QUOT),
  //|--------------+--------+--------+--------+--------+--------|                 |--------+-------+--------+--------+--------+---------------|
            KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,   KC_H, KC_COMM, KC_DOT,  KC_SLSH,        KC_SCLN,
  //|--------------+--------+--------+--------+--------+--------+-------|  |------+--------+-------+--------+--------+--------+---------------|
                            LT(3,KC_TAB), LT(2,KC_ESC), LT(1,KC_SPC),          LT(4,KC_BSPC), LT(5,KC_QUOT), KC_ENT
                                  //`-----------------------------------'  `----------------------------------'

  ),

// L: Keyboard Maestro Macros | R: Magnet Macros
  [1] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------.                ,---------------------------------------------------------------------|.
              KC_NO, HYPR(KC_TAB), HYPR(KC_Z), HYPR(KC_A), HYPR(KC_Q), HYPR(KC_B),                LCA(KC_U),    LCA(KC_E),   LCA(KC_UP),    LCA(KC_T),   LCA(KC_I), KC_NO,
  //|--------------+-------------+-----------+-----------+-----------+-----------|                |--------+-------------+-------------+-------------+------------+------|
      ALL_T(KC_ESC),   HYPR(KC_M), HYPR(KC_R), HYPR(KC_S), HYPR(KC_T), HYPR(KC_G),                LCA(KC_C), LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_RGHT), LCA(KC_ENT), KC_NO,
  //|--------------+-------------+-----------+-----------+-----------+-----------|                |--------+-------------+-------------+-------------+------------+------|
              KC_NO,   HYPR(KC_N), HYPR(KC_Y), HYPR(KC_C), HYPR(KC_D), HYPR(KC_V),                LCA(KC_J),    LCA(KC_D),    LCA(KC_F),    LCA(KC_G),   LCA(KC_K), KC_NO,
  //|--------------+-------------+-----------+-----------+-----------+-----------|------/  /------|--------+-------------+-------------+-------------+------------+------|
                                                  HYPR(KC_5), HYPR(KC_4), KC_TRNS,                RCS(KC_D), RCS(KC_F), RCS(KC_G)
                                                 //`------------------------------------'  `----------------------------------'
  ),

// Numpad
  [2] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------.              ,-------------------------------------------------------.
       LGUI(KC_GRV), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,      KC_PERC,                 KC_CIRC,    KC_7,    KC_8,    KC_9, KC_MINS,  KC_BSPC,
  //|--------------+--------+--------+--------+--------+-------------|              |---------+--------+--------+--------+--------+---------|
      ALL_T(KC_ESC), KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, LGUI(KC_GRV),                 KC_PEQL,    KC_4,    KC_5,    KC_6, KC_PPLS,   KC_GRV,
  //|--------------+--------+--------+--------+--------+-------------|              |---------+--------+--------+--------+--------+---------|
            KC_LSFT,   U_UND,   U_CUT,   U_CPY,   U_PST,        U_RDO,                 KC_COLN,    KC_1,    KC_2,    KC_3, KC_SLSH,  KC_PEQL,
  //|--------------+--------+--------+--------+--------+-------------+-----|  |-----+---------+--------+--------+--------+--------+---------|
                                        KC_TAB, KC_TRNS,       KC_SPC,                 KC_BSPC,   KC_P0, KC_PDOT
                                  //`--------------------------------------'  `------------------------------------'
   ),

// Keyboard settings, functions
  [3] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------.              ,-----------------------------------------------|.
             QK_RBT,  RGB_TOG, DT_PRNT, DT_DOWN,   DT_UP,   KC_NO,                 KC_NO,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_NO,
  //|--------------+---------+--------+--------+--------+--------|              |-------+-------+-------+-------+--------+-------|
      ALL_T(KC_ESC),  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                 KC_NO,  KC_F4,  KC_F5,  KC_F6,  KC_F11,  KC_NO,
  //|--------------+---------+--------+--------+--------+--------|              |-------+-------+-------+-------+--------+-------|
              KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                 KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F12,  KC_NO,
  //|--------------+---------+--------+--------+--------+--------+-----|  |-----+-------+-------+-------+-------+--------+-------|
                                        KC_TRNS,  KC_ESC,  KC_SPC,                KC_BSPC,  KC_QUOT, KC_ENT
                                  //`----------------------------------'  `----------------------------------'
  ),

// Nav
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.         ,------------------------------------------------------------.
             KC_TAB,   KC_F1,   KC_F2, KC_VOLD, KC_VOLU, KC_MUTE,            KC_HOME,     TAB_P,     KC_UP,     TAB_N, KC_PGUP, KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------|         |---------+----------+----------+----------+--------+--------|
      ALL_T(KC_ESC), KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,   KC_NO,             U_HSTB,   KC_LEFT,   KC_DOWN,   KC_RGHT,  U_HSTF, KC_BSLS,
  //|--------------+--------+--------+--------+--------+--------|         |---------+----------+----------+----------+--------+--------|
            KC_LSFT,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,             KC_END, RCS(KC_D), RCS(KC_F), RCS(KC_G), KC_PGDN, KC_RCTL,
  //|--------------+--------+--------+--------+--------+--------+-----|  |----------+----------+----------+----------+--------+--------|
                                        KC_TAB,  KC_ESC,  KC_SPC,            KC_TRNS,   KC_QUOT,    KC_ENT
                                  //`---------------------------------'  `------------------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------.              ,-------------------------------------------------|.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,               CBRCKTS, KC_LCBR, KC_RCBR,  KC_GRV, KC_BSLS, KC_NO,
  //|------+--------+--------+--------+--------+------|              |-------+--------+--------+--------+--------+------|
      KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                PARENS, KC_LPRN, KC_RPRN, KC_SCLN, KC_QUOT, KC_NO,
  //|------+--------+--------+--------+--------+------|              |-------+--------+--------+--------+--------+------|
    KC_LSFT,   U_UND,   U_CUT,   U_CPY,   U_PST, U_RDO,                BRCKTS, KC_LBRC, KC_RBRC, KC_PEQL, KC_SCLN, KC_NO,
  //|------+--------+--------+--------+--------+------+-----|  |-----+-------+--------+--------+--------+--------+------|
                                 KC_TAB, KC_ESC, KC_SPC,             KC_BSPC, KC_TRNS, KC_ENT
                        //`----------------------------------'  `----------------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
        default:
            return TAPPING_TERM;
    }
}
