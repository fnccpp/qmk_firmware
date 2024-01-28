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

// https://docs.qmk.fm/#/keycodes_basic

#include QMK_KEYBOARD_H
#include "keymap_italian.h"
#define IT_TILD ALGR(IT_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
    [0] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|-----------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MT(MOD_LSFT, KC_CAPS),      KC_A, LT(1,KC_S),LT(2,KC_D),LT(3,KC_F), KC_G,                     KC_H,LT(3,KC_J),LT(2,KC_K),LT(1,KC_L), IT_MINS, KC_ENT,
  //|-----------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,   KC_COMM, KC_DOT, KC_LEFT, KC_RIGHT,
  //|-----------------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                        KC_LALT,   MO(1),  KC_SPC,     KC_SPC,   MO(2), KC_LGUI
                                                    //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3( //NUMERI
  //,--------------------------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,                KC_F1,   KC_F2,   KC_F3,   KC_F4,  XXXXXXX,                      KC_PAST,     KC_7,    KC_8,    KC_9,  IT_EQL, KC_BSPC,
  //|-----------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LSFT, KC_CAPS),        KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_PDOT,                      KC_PSLS,  KC_4,    KC_5,    KC_6,   IT_MINS, KC_ENT,
  //|-----------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,                KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_COMM,                      KC_PPLS,  KC_1,    KC_2,    KC_3,   KC_LEFT,  KC_RGHT,
  //|-----------------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                        KC_LALT, _______, KC_SPC,    KC_0, MO(3), KC_LGUI
                                                     //`--------------------------'  `--------------------------'

  ),

    [2] = LAYOUT_split_3x6_3( //SIMBOLI
  //,--------------------------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,                IT_BSLS,   KC_PERC,   IT_EGRV,   IT_EACU,  IT_AT,                KC_PAST, IT_UGRV,  IT_IGRV, IT_OGRV,   IT_EQL, KC_BSPC,
  //|-----------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LSFT, KC_CAPS),  IT_AGRV ,   IT_PIPE,   IT_AMPR,   IT_QUES,  IT_EXLM,             KC_PSLS,  IT_LBRC , IT_RBRC , IT_QUOT ,   IT_MINS, KC_ENT,
  //|-----------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,            IT_LABK,   IT_RABK,  IT_CIRC,  IT_HASH , KC_DLR,                      KC_PPLS,  IT_LPRN  , IT_RPRN  , IT_TILD,   KC_LEFT,  KC_RGHT,
  //|-----------------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                        KC_LALT, MO(3), KC_SPC,    KC_SPC, _______ , KC_LGUI
                                                     //`--------------------------'  `--------------------------'

  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN4, KC_BTN5,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LSFT, KC_CAPS), KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BRIU,              KC_VOLD, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID,                      KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_SPC, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  )
};

// GESTIONE SHIFT
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC: { // SHIFT + BACKSPACE = CANC
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }

    case KC_MINS: { // Shift ' -> "
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                //del_mods(MOD_MASK_SHIFT);
                register_code(KC_2); 
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { 
            if (delkey_registered) {
                unregister_code(KC_2);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }       
    
    case KC_LBRC: { // E maiuscola accentata
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                del_mods(MOD_MASK_SHIFT);
                // set_mods(MOD_MASK_ALT);
                // del_mods(MOD_MASK_CTRL);
                register_code(KC_LALT); 
                register_code(KC_P2); 
                unregister_code(KC_P2);
                register_code(KC_P1); 
                unregister_code(KC_P1);
                register_code(KC_P2); 
                unregister_code(KC_P2);
                unregister_code(KC_LALT);
                // del_mods(MOD_MASK_ALT);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { 
            if (delkey_registered) {
            //     unregister_code(KC_MINS);
                 delkey_registered = false;
                 return false;
            }
        }
        return true;
    }
    /*
    case KC_SLSH: { // - _ // Slash e' l'equivalente americano di -
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_MINS); 
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_MINS);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }
    case IT_LBRC: { // [{
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                del_mods(MOD_MASK_SHIFT);
                register_code(IT_LCBR);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            if (delkey_registered) {
                unregister_code(IT_LCBR);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }
    case IT_RBRC: { // ]}
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                del_mods(MOD_MASK_SHIFT);
                register_code(IT_RCBR);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            if (delkey_registered) {
                unregister_code(IT_RCBR);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }
    case IT_QUOT: { // ' "
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) { // Detect the activation of either shift keys
                del_mods(MOD_MASK_SHIFT);
                register_code(IT_DQUO);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            if (delkey_registered) {
                unregister_code(IT_DQUO);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }*/

    }
    return true;
};

// #ifdef OLED_ENABLE
// void oled_render_logo(void) {
//     static const char PROGMEM mb_logo[] = {
// 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f,
// 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff,
// 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83,
// 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0xff, 0xff, 0x82, 0x82, 0x82, 0x82,
// 0x82, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff,
// 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfc, 0xfc,
// 0x9c, 0x9c, 0xfc, 0xfc, 0xf8, 0xf8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0x7c, 0x3c,
// 0x9c, 0xfc, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0x3c, 0x3c,
// 0x9c, 0xbc, 0xfc, 0xb8, 0xb8, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41,
// 0x41, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff,
// 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f,
// 0x03, 0x07, 0x0f, 0x3f, 0x3f, 0x3e, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3c, 0x3e, 0x3f,
// 0x3f, 0x3f, 0x3b, 0x39, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3f, 0x3c, 0x38,
// 0x3b, 0x3b, 0x3f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0,
// 0xf0, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff,
// 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };
//     oled_write_raw_P(mb_logo, sizeof(mb_logo));
//     //oled_set_cursor(oled_max_chars()/2,oled_max_lines()/2);
//     //oled_write_P(PSTR("R2G"), false);
// }
// #endif
