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

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

// Tab Navigation
#define TAB_P SGUI(KC_LBRC)
#define TAB_N SGUI(KC_RBRC)

#include QMK_KEYBOARD_H
#include <stdio.h>
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                 ,-----------------------------------------------------------.
             KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_MINS,       KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------|                 |---------+--------+--------+--------+--------+-------------|
      ALL_T(KC_ESC),  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                      KC_M, HOME_N,  HOME_E,  HOME_I,  HOME_O, ALL_T(KC_QUOT),
  //|--------------+--------+--------+--------+--------+--------|                 |---------+--------+--------+--------+--------+-------------|
            KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H, KC_COMM, KC_DOT, KC_SLSH,        KC_SCLN,
  //|--------------+--------+--------+--------+--------+--------+-------|  |------+---------+--------+--------+--------+--------+-------------|
                                       KC_LGUI,   MO(1), ALL_T(KC_SPC),         LT(2,KC_ENT),   MO(2), KC_RALT
                                  //`-----------------------------------'  `----------------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.              ,-----------------------------------------------------------.
       LGUI(KC_GRV), KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                 KC_CIRC,    KC_7,    KC_8,    KC_9, KC_PMNS,      KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------|              |---------+--------+--------+--------+--------+-------------|
      ALL_T(KC_ESC), KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,   KC_NO,                 KC_MINS,    KC_4,    KC_5,    KC_6, KC_PPLS,       KC_GRV,
  //|--------------+--------+--------+--------+--------+--------|              |---------+--------+--------+--------+--------+-------------|
            KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                 KC_PDOT,    KC_1,    KC_2,    KC_3, KC_SLSH,      KC_PEQL,
  //|--------------+--------+--------+--------+--------+--------+-----|  |-----+---------+--------+--------+--------+--------+-------------|
                                       KC_LGUI, KC_TRNS,  KC_SPC,            LT(3,KC_ENT), LT(3,KC_P0), RALT_T(KC_PDOT)
                                  //`---------------------------------'  `---------------------------------'
   ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.              ,---------------------------------------------------------.
             KC_TAB,   KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_LCBR,                KC_RCBR,     TAB_P,     KC_UP,     TAB_N,  KC_EQL, KC_BSPC,
  //|--------------+--------+--------+--------+--------+--------|              |--------+----------+----------+----------+--------+--------|
      ALL_T(KC_ESC), KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_LPRN,                KC_RPRN,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO, KC_BSLS,
  //|--------------+--------+--------+--------+--------+--------|              |--------+----------+----------+----------+--------+--------|
            KC_LSFT,   KC_NO,   KC_NO,   KC_F1,   KC_F2, KC_LBRC,                KC_RBRC, RCS(KC_D), RCS(KC_F), RCS(KC_G),   KC_NO, KC_RCTL,
  //|--------------+--------+--------+--------+--------+--------+-----|  |-----+--------+----------+----------+----------+--------+--------|
                                       KC_LGUI,   MO(3),  KC_SPC,                 KC_ENT,   KC_TRNS,   KC_RALT
                                  //`---------------------------------'  `------------------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------.              ,--------+--------------+-------------+-------------+----------+-----------|.
              RESET,  RGB_TOG, DT_PRNT, DT_DOWN,   DT_UP,   KC_NO,                  KC_NO,     LCA(KC_E),   LCA(KC_UP),    LCA(KC_T), LCA(KC_U),   LCA(KC_I),
  //|--------------+---------+--------+--------+--------+--------|              |--------+--------------+-------------+-------------+----------+------------|
      ALL_T(KC_ESC),  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,              LCA(KC_C),  LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_RGHT), LCA(KC_J),   LCA(KC_K),
  //|--------------+---------+--------+--------+--------+--------|              |--------+--------------+-------------+-------------+----------+------------|
              KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                  KC_NO,     LCA(KC_D),    LCA(KC_F),    LCA(KC_G),     KC_NO, LCA(KC_ENT),
  //|--------------+---------+--------+--------+--------+--------+-----|  |-----+--------+--------------+-------------+-------------+----------+------------|
                                        KC_LGUI, KC_TRNS,  KC_SPC,                 KC_ENT,  KC_TRNS, KC_RALT
                                  //`----------------------------------'  `-------------------------------------------'
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
