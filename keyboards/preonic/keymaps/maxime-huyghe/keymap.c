/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"


// Layers
enum preonic_layers {
  QWERTY,
  CMPSE,
  GAME,
  LOWER,
  RAISE,
  BOTH,
  RGB_,
};


// Keycode aliases
#define LWR_SPC LT(LOWER,KC_SPC)
#define RSE_ENT LT(RAISE,KC_ENT)
#define xxxxxxx KC_NO
#define TERM_OF TERM_OFF

// C = capital
enum custom_keycodes {
  EA = SAFE_RANGE,
  EG,
  EC,
  AG,
  AC,
  IT,
  OC,
  UG,
  AE,
  OE,
  CC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_LCTL, MO(RGB_), KC_LALT, KC_LGUI, LWR_SPC, LWR_SPC, MO(CMPSE), RSE_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


[CMPSE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, EC,      EG,      EA,      _______, _______, _______, UG,      IT,      OC,      _______, _______,
  _______, AG,      AC,      _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, AE,      OE,      CC,      _______, _______, _______, _______, CC,      _______, _______, _______,
  _______, _______, _______, _______, _______, _______, xxxxxxx, _______, _______, _______, _______, _______
),


[GAME] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    TG(GAME),
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,      KC_M,    KC_COMM, KC_UP,   KC_SLSH, KC_RSFT,
  KC_LCTL, _______, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC, MO(RAISE), KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DOT
),


[LOWER] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,
  _______, _______, _______, KC_LT,   KC_GT,   _______, _______,  KC_LBRC,  KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, KC_CIRC,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______,  KC_MINS,  KC_UNDS, KC_EQL,  KC_PLUS, _______,
  _______, _______, _______, _______, _______, _______, MO(BOTH), MO(BOTH), _______, _______, _______, _______
),


[RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  _______, KC_PGDN, KC_PGUP, KC_END,  KC_HOME,  _______,  _______, KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, _______,
  _______, _______, _______, _______, MO(BOTH), MO(BOTH), _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______
),


[BOTH] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, TG(GAME),
  xxxxxxx, RESET,   DEBUG,   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, TERM_ON, TERM_OF, xxxxxxx, xxxxxxx, xxxxxxx,
  xxxxxxx, xxxxxxx, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  xxxxxxx, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_F12
),


[RGB_] = LAYOUT_preonic_grid(
  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
  xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx
),
};


// Macro to type accented characters with compose
#define COMPOSE_MACRO(KEYCODE, CHAR, DIACRITIC) \
    case KEYCODE: \
        if (record->event.pressed) { \
            uint8_t temp_mods = get_mods(); \
            clear_mods(); \
            if (temp_mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) { \
                SEND_STRING(SS_RALT(DIACRITIC SS_LSFT(CHAR))); \
            } else { \
                SEND_STRING(SS_RALT(DIACRITIC CHAR)); \
            } \
            set_mods(temp_mods); \
        } \
        break;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        COMPOSE_MACRO(EA, "e", "'");
        COMPOSE_MACRO(EG, "e", "`");
        COMPOSE_MACRO(EC, "e", "^");
        COMPOSE_MACRO(AG, "a", "`");
        COMPOSE_MACRO(AC, "a", "^");
        COMPOSE_MACRO(IT, "i", "\"");
        COMPOSE_MACRO(OC, "o", "^");
        COMPOSE_MACRO(UG, "u", "`");
        COMPOSE_MACRO(AE, "ae", "");
        COMPOSE_MACRO(OE, "oe", "");
        COMPOSE_MACRO(CC, "c", ",");
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0:
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
