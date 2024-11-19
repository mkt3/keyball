/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layer_number {
  _DEFAULT = 0,
  _CTRL,
  _SYMBOL,
  _TILE,
  _MOUSE,
  _VSCL_FN,
  _HSCL_MNG
};

#define VSCL_COMM LT(_VSCL_FN,KC_COMM)
#define HSCL_DOT LT(_HSCL_MNG,KC_DOT)
#define SYM_SPC LT(_SYMBOL,KC_SPC)
#define TILE_MINS LT(_TILE,KC_MINS)
#define LCTL_MINS LT(_CTRL,KC_MINS)
#define RCTL_QUOT LT(_CTRL,KC_QUOT)
#define LSFT_GRV LSFT_T(KC_GRV)
#define RSFT_BSLS RSFT_T(KC_BSLS)
#define LGUI_SPC LGUI_T(KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    LCTL_MINS, KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , RCTL_QUOT  ,
    LSFT_GRV , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , VSCL_COMM, HSCL_DOT , KC_SLSH  , RSFT_BSLS,
               KC_LALT  ,KC_GRV    , TILE_MINS,LGUI_SPC,KC_LSFT,                                  KC_RSFT,SYM_SPC       , KC_NO,KC_NO                    , KC_ESC
  ),

  [_CTRL] = LAYOUT_universal(
    C(KC_TAB), C(KC_Q)  , C(KC_W)  , C(KC_E)  , C(KC_R)  , C(KC_T)  ,                                        C(KC_Y)  , C(KC_U)  , C(KC_I)  , C(KC_O)  , C(KC_P)  , C(KC_LBRC)  ,
    LCTL_MINS, C(KC_A)  , C(KC_S)  , C(KC_D)  , C(KC_F)  , C(KC_G)  ,                                        C(KC_H)  , C(KC_J)  , C(KC_K)  , C(KC_L)  , C(KC_SCLN), C(KC_QUOT) ,
    KC_LSFT ,  C(KC_Z)  , C(KC_X)  , C(KC_C)  , C(KC_V)  , C(KC_B)  ,                                        C(KC_N)  , C(KC_M)  , C(KC_COMM), C(KC_DOT) , C(KC_SLSH)  , C(KC_BSLS),
          _______ ,_______   , _______,_______,_______,                                  _______,C(KC_SPC)       , _______,_______                    , _______
  ),

  [_SYMBOL] = LAYOUT_universal(
    _______   , S(KC_1) , S(KC_2)  , S(KC_3)  , S(KC_4)  , S( KC_5) ,                                        S(KC_6)  , S(KC_7)  , S(KC_8)  ,S(KC_9)   , S(KC_0)     , KC_MINS  ,
    S(KC_MINS), KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                       KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_EQL  ,
    _______ , S(KC_GRV)   , KC_LBRC  , KC_RBRC  , S(KC_LBRC)     ,S(KC_RBRC)     ,                           S(KC_9)   , S(KC_0)    , S(KC_COMM), S(KC_DOT) , KC_SLSH  , _______,
          _______ ,_______   , _______,_______,_______,                                  _______,_______       , _______,_______                    , _______
  ),

  [_TILE] = LAYOUT_universal(
    KC_NO ,  G(KC_Q)   , KC_NO    , KC_NO   , KC_NO    , KC_NO    ,                                         KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   , KC_NO   ,
    A(KC_6) ,  A(KC_1), A(KC_2)  , A(KC_3)   , A(KC_4)   , A(KC_5)   ,                                      A(KC_H)  , A(KC_J)  , A(KC_K)    , A(KC_L)  , A(KC_6)  , KC_NO   ,
    KC_LSFT ,  KC_NO , KC_NO  , G(KC_C), A(KC_V)  , KC_NO  ,                                         KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_RSFT  ,
          KC_NO  , KC_NO , KC_NO  ,         KC_NO  , KC_NO  ,                            KC_NO  , A(KC_SPC)  , KC_NO       , KC_NO  , KC_NO
  ),

  [_MOUSE] = LAYOUT_universal(
    KC_NO ,  KC_NO   , KC_NO    , KC_NO   , KC_NO    , KC_NO    ,                                         KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   , KC_NO   ,
    KC_LCTL ,  KC_NO   , KC_NO    , KC_NO   , KC_NO    , KC_NO    ,                                         KC_NO    , KC_J    , KC_K    , KC_BTN1    , KC_BTN2   , KC_NO   ,
    KC_LSFT ,  KC_NO , KC_NO  , KC_C , KC_V  , KC_NO  ,                                                   KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
          KC_NO  , KC_NO , KC_NO  ,         KC_LGUI  , KC_NO  ,                            KC_NO  , KC_NO  , KC_NO       , KC_NO  , KC_NO
  ),

  [_VSCL_FN] = LAYOUT_universal(
    KC_NO ,  KC_BRID   , KC_BRIU , KC_NO   , KC_NO    , KC_NO    ,                                         KC_MPRV    , KC_MPLY    , KC_MNXT    , KC_MUTE    , KC_VOLD   , KC_VOLU   ,
    KC_NO ,  KC_F1 ,  KC_F2   , KC_F3    , KC_F4   , KC_F5    ,                                          KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_NO   ,
    KC_LSFT ,  KC_NO , KC_NO  , KC_NO , KC_NO  , KC_F11  ,                                         KC_F12  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_RSFT  ,
          KC_NO  , KC_NO , KC_NO  ,         KC_NO  , KC_NO  ,                            KC_NO  , KC_NO  , KC_NO       , KC_NO  , KC_NO
  ),

  [_HSCL_MNG] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _HSCL_MNG:
            // Auto enable horizontal scroll mode when the highest layer is _HSCL_MNG(-1)
            keyball_set_scroll_mode(true);
            keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_HORIZONTAL);
            break;
        case _VSCL_FN:
            // Auto enable vertical scroll mode when the highest layer is _VSCL_FN(-2)
            keyball_set_scroll_mode(true);
            keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_VERTICAL);
            break;
        default:
            keyball_set_scroll_mode(false);
            break;
    }
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_SPC:
            return true;
        case TILE_MINS:
            return true;
        case LCTL_MINS:
            return true;
        case RCTL_QUOT:
            return true;
        case LSFT_GRV:
            return true;
        case RSFT_BSLS:
            return true;
        case LGUI_SPC:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

/* bool process_control_key(uint16_t replacement, keyrecord_t *record) { */
/*     static uint8_t active_ctrl = 0; */
/*     static bool replacement_active = false; */
/*     uint8_t mod_state = get_mods(); */

/*     if (record->event.pressed) { */
/*         if ((mod_state & MOD_MASK_CTRL) && !(mod_state & ~(MOD_MASK_CTRL))) { */
/*             active_ctrl = mod_state & MOD_MASK_CTRL; */
/*             del_mods(MOD_MASK_CTRL); */
/*             send_keyboard_report(); */
/*             register_code(replacement); */
/*             replacement_active = true; */
/*             return false; */
/*         } */
/*     } else { */
/*         if (replacement_active) { */
/*             unregister_code(replacement); */
/*             replacement_active = false; */

/*             if (active_ctrl) { */
/*                 set_mods(active_ctrl); */
/*                 send_keyboard_report(); */
/*                 active_ctrl = 0; */
/*             } */
/*             return false; */
/*         } */
/*     } */
/*     return true; */
/* } */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case KC_H: */
/*             return process_control_key(KC_BSPC, record); */
/*         case KC_D: */
/*             return process_control_key(KC_DELETE, record); */
/*         case KC_M: */
/*             return process_control_key(KC_ENTER, record); */
/*         case KC_I: */
/*             return process_control_key(KC_TAB, record); */
/*     } */
/*     return true; */
/* } */
