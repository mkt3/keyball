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
  _BASE = 0,
  _SYMBOL,
  _TILE,
  _MOUSE,
  _VSCL_FN,
  _HSCL_MNG
};


#define VSCL_COMM LT(_VSCL_FN,KC_COMM)
#define HSCL_DOT LT(_HSCL_MNG,KC_DOT)

#define SYM_SPC LT(_SYMBOL,KC_SPC)
#define TILE_GRV LT(_TILE,KC_GRV)

#define LCTL_QUOT LCTL_T(KC_QUOT)

#define LSFT_GRV LSFT_T(KC_GRV)
#define RSFT_BSLS RSFT_T(KC_BSLS)
#define RSFT_EQL RSFT_T(KC_EQL)

#define LGUI_UNDS LGUI_T(KC_UNDS)


enum {
    TD_QESC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_universal(
    KC_TAB   ,TD(TD_QESC), KC_W    , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    KC_LCTL, KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , LCTL_QUOT  ,
    LSFT_GRV , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , VSCL_COMM, HSCL_DOT , KC_SLSH  , RSFT_BSLS,
               KC_LALT  ,KC_GRV    , TILE_GRV,LGUI_UNDS,KC_LSFT,                               RSFT_EQL,SYM_SPC       , KC_NO,KC_NO                    , KC_ESC
  ),

  [_SYMBOL] = LAYOUT_universal(
    S(KC_GRV) , S(KC_1) , S(KC_2)  , S(KC_3)  , S(KC_4)  , S( KC_5) ,                                        S(KC_6)  , S(KC_7)  , S(KC_8)  ,S(KC_9)   , S(KC_0)     , KC_MINS  ,
    KC_LCTL , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                         KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_EQL  ,
    KC_LSFT ,KC_SLSH  , KC_LBRC  , KC_RBRC  , S(KC_LBRC),S(KC_RBRC),                                        KC_EQL   , S(KC_EQL),S(KC_COMM), S(KC_DOT) , S(KC_SLSH), KC_RSFT,
               _______ ,_______   , S(KC_GRV),S(KC_MINS),_______,                              S(KC_EQL),_______       , _______,_______                    , _______
  ),

  [_TILE] = LAYOUT_universal(
    KC_NO ,  G(KC_Q)   , KC_NO    , KC_NO   , KC_NO    , KC_NO    ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   , KC_NO   ,
    A(KC_6) , A(KC_1)  , A(KC_2)  , A(KC_3) , A(KC_4)  , A(KC_5)   ,                                      A(KC_H)  , A(KC_J)  , A(KC_K)  , A(KC_L)  , A(KC_6) , KC_NO   ,
    KC_LSFT , KC_NO    , KC_NO    , G(KC_C) , A(KC_V)  , KC_NO  ,                                                KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   , KC_RSFT ,
              KC_NO  , KC_NO     , KC_NO  , KC_NO  , KC_LSFT  ,                                KC_NO  , A(KC_SPC)  , KC_NO       , KC_NO  , KC_NO
  ),

  [_MOUSE] = LAYOUT_universal(
    KC_NO ,  KC_NO   , KC_NO    , KC_NO   , KC_NO    , KC_NO    ,                                         KC_NO    , KC_NO  , KC_NO  , KC_NO    , KC_NO   , KC_NO   ,
    KC_LCTL ,  KC_NO   , KC_NO    , KC_NO   , KC_NO    , KC_NO    ,                                       KC_NO    , KC_J   , KC_K   , KC_BTN1  , KC_BTN2 , KC_NO   ,
    KC_LSFT ,  KC_NO , KC_NO  , KC_C , KC_V  , KC_NO  ,                                                   KC_NO  , KC_NO    , KC_NO  , KC_NO    , KC_NO   , KC_NO  ,
               KC_NO  , KC_NO       , KC_NO , KC_LGUI ,KC_LSFT,                                KC_NO , KC_NO            , KC_NO  , KC_NO    , KC_NO
  ),

  [_VSCL_FN] = LAYOUT_universal(
    KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD , KC_VOLU ,                                           KC_NO  ,  KC_NO    , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
    KC_NO   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                                           KC_F6  , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_NO   ,
    KC_LSFT , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_F11  ,                                           KC_F12 , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_RSFT ,
             KC_BRID  , KC_BRIU , KC_NO  ,         KC_NO  , KC_NO  ,                           KC_NO  , KC_NO            , KC_NO  , KC_NO        , KC_NO
  ),

  [_HSCL_MNG] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
               QK_BOOT  , KBC_RST  , _______  , _______  , _______  ,                            _______  , KC_NO    , KC_NO , KBC_RST       , QK_BOOT
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
        case TILE_GRV:
            return true;
        case LCTL_QUOT:
            return true;
        case LSFT_GRV:
            return true;
        case RSFT_BSLS:
            return true;
        case RSFT_EQL:
            return true;
        case LGUI_UNDS:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


static bool left_ctrl_held = false;

bool process_control_key(uint16_t replacement, keyrecord_t *record) {
    static bool replacement_active = false;

    if (record->event.pressed) {
        if (left_ctrl_held && !replacement_active) {
            replacement_active = true;
            del_mods(MOD_MASK_CTRL);
            send_keyboard_report();
            register_code(replacement);
            return false;
        }
    } else {
        if (replacement_active) {
            unregister_code(replacement);
            replacement_active = false;
        }

        if (left_ctrl_held) {
            register_code(KC_LCTL);
            send_keyboard_report();
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode == KC_LCTL) {
            left_ctrl_held = true;
            return true;
        }
    } else {
        if (keycode == KC_LCTL) {
            left_ctrl_held = false;
            return true;
        }
    }

    switch (keycode) {
        case KC_H:
            return process_control_key(KC_BSPC, record);
        case KC_D:
            return process_control_key(KC_DELETE, record);
        case KC_M:
            return process_control_key(KC_ENTER, record);
        case KC_I:
            return process_control_key(KC_TAB, record);
        case KC_B:
            return process_control_key(KC_LEFT, record);
        case KC_F:
            return process_control_key(KC_RIGHT, record);
        case KC_P:
            return process_control_key(KC_UP, record);
        case KC_N:
            return process_control_key(KC_DOWN, record);
    }

    return true;
}
