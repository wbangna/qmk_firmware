#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define HYPER ALL_T(KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
    ,-------------------------------------------.       ,-------------------------------------------.
    |   ~   |  !  |  @  |  #  |  $  |  %  |     |       |     |  ^  |  &  |  *  |  (  |  )  |   _   |
    |   `   |  1  |  2  |  3  |  4  |  5  |[~L1]|       |[~L1]|  6  |  7  |  8  |  9  |  0  |   -   |
    |-------+-----+-----+-----+-----+-----+-----|       |-----+-----+-----+-----+-----+-----+-------|
    |       |     |     |     |     |     |     |       |     |     |     |     |     |     |   +   |
    |  ->|  |  Q  |  W  |  E  |  R  |  T  | |<- |       | |<- |  Y  |  U  |  I  |  O  |  P  |   =   |
    |-------+-----+-----+-----+-----+-----+     |       |     +-----+-----+-----+-----+-----+-------|
    |       |     |     |     |     |     +-----|       |-----+     |     |     |     |  :  |   "   |
    |  Esc  |  A  |  S  |  D  |  F  |  G  |     |       |     |  H  |  J  |  K  |  L  |  ;  |   '   |
    |-------+-----+-----+-----+-----+-----+ ENT |       | ENT +-----+-----+-----+-----+-----+-------|
    |       |     |     |     |     |     |  ER |       | ER  |     |     |  <  |  >  |  ?  |       |
    | LShft |  Z  |  X  |  C  |  V  |  B  |     |       |     |  N  |  M  |  ,  |  .  |  /  | RShft |
    `-+-----+-----+-----+-----+-----+-----+-----'       `-----+-----+-----+-----+-----+-----+-----+-'
      |     |     |Play |Media|     |                               |     |  {  |  }  |  |  |     |
      |LCtrl|Hyper|Pause|Sel  |LGui |  ,-----------. ,-----------.  |RGui |  [  |  ]  |  \  |RCtrl|
      `-----+-----+-----+-----+-----'  |     |     | |     |     |  `-----+-----+-----+-----+-----'
                                       |Home | End | |PgUp |PgDn |
                                 ,-----+-----+-----| |-----+-----+-----.
                                 |     |     |     | |     |     |     |
                                 |     |     |Next | |Vol+ |     |     |
                                 |Space|LAlt +-----| |-----+ RAlt|Space|
                                 |     |     |     | |     |     |     |
                                 |     |     |Prev | |Vol- |     |     |
                                 `-----------------' `-----------------'
*/
[0] = LAYOUT_ergodox(
    /* LEFT */
        KC_GRV        , KC_1  , KC_2    , KC_3    , KC_4    , KC_5 , KC_FN0    ,
        KC_TAB        , KC_Q  , KC_W    , KC_E    , KC_R    , KC_T , KC_BSPACE ,
        CTL_T(KC_ESC) , KC_A  , KC_S    , KC_D    , KC_F    , KC_G ,
        KC_LSFT       , KC_Z  , KC_X    , KC_C    , KC_V    , KC_B , KC_ENTER  ,
        KC_LCTRL      , HYPER , KC_MPLY , KC_MSEL , KC_LGUI ,

                                                                   KC_HOME , KC_END,
                                                                             KC_MNXT,
                                                        KC_SPC ,   KC_LALT , KC_MPRV,


                            /* RIGHT */
                            KC_FN0     , KC_6      , KC_7      , KC_8      , KC_9      , KC_0      , KC_MINS   ,
                            KC_BSPACE  , KC_Y      , KC_U      , KC_I      , KC_O      , KC_P      , KC_EQL    ,
                                         KC_H      , KC_J      , KC_K      , KC_L      , KC_SCOLON , KC_QUOT   ,
                            KC_ENTER   , KC_N      , KC_M      , KC_COMM   , KC_DOT    , KC_SLSH   , KC_RSFT   ,
                                         KC_RGUI   ,KC_LBRACKET,KC_RBRACKET, KC_BSLASH , KC_RCTRL  ,

                            KC_PGUP    , KC_PGDOWN ,
                            KC_VOLU    ,
                            KC_VOLD    , KC_RALT   , KC_SPC
    ),


/*
    ,-------+-----+-----+-----+-----+-----+-----.       ,-----+-----+-----+-----+-----+-----+-------.
    |       |     |     |     |     |     |     |       |     |     |     |     |     |     |       |
    |Version| F1  | F2  | F3  | F4  | F5  |     |       |     | F6  | F7  | F8  | F9  | F10 | F11   |
    |-------+-----+-----+-----+-----+-----+-----|       |-----+-----+-----+-----+-----+-----+-------|
    |       |     |     |     |     |Mouse|     |       |     |Mouse|Mouse|Mouse|Mouse|     |       |
    |  ->|  | F13 | F14 | F15 | F16 |Accl0| Del |       | Del | <-- |  v  |  ^  | --> |     | F12   |
    |-------+-----+-----+-----+-----+-----+     |       |     +-----+-----+-----+-----+-----+-------|
    |       |     |     |     |     |Mouse+-----|       |-----+     |  |  |  ^  |     |     |       |
    | Esc   | F17 | F18 | F19 | F20 |Accl1|     |       |     | <-- |  v  |  |  | --> |     |       |
    |-------+-----+-----+-----+-----+-----+ ENT |       | ENT +-----+-----+-----+-----+-----+-------|
    |       |     |     |     |     |Mouse|  ER |       | ER  |Num  |Sck  |Prt  |Caps |Sys  |       |
    | LShft | F21 | F22 |FN23 |FN24 |Accl2|     j       |     |Lock |Lock |Scr  |Lock |Req  | RShft |
    `-+-----+-----+-----+-----+-----+-----+-----'       `-----+-----+-----+-----+-----+-----+-----+-'
      |     |     |Play |Media|     |                               |     |     |     |     |     |
      |LCtrl|Hyper|Pause|Sel  |LGui |  ,-----------. ,-----------.  |RGui |     | Ins |     |RCtrl|
      `-----+-----+-----+-----+-----'  |Mouse|Mouse| |Mouse|Mouse|  `-----+-----+-----+-----+-----'
                                       |Left |Right| |ScUp |ScDn |
                                 ,-----+-----+-----| |-----+-----+-----.
                                 |     |     |     | |     |     |     |
                                 |     |     |Next | |Vol+ |     |     |
                                 |Space|LAlt +-----| |-----+ RAlt|Space|
                                 |     |     |     | |     |     |     |
                                 |     |     |Prev | |Vol- |     |     |
                                 `-----------------' `-----------------'
*/
[1] = LAYOUT_ergodox( /* LEFT */
       M(0)    ,     KC_F1 ,     KC_F2 ,     KC_F3 ,     KC_F4 ,     KC_F5 ,   _______ ,
       _______ ,    KC_F13 ,    KC_F14 ,    KC_F15 ,    KC_F16 ,   KC_MS_ACCEL0 ,   KC_DELETE,
       _______ ,    KC_F17 ,    KC_F18 ,    KC_F19 ,    KC_F20 ,   KC_MS_ACCEL1 ,
       _______ ,    KC_F21 ,    KC_F22 ,    KC_F23 ,     KC_F24,   KC_MS_ACCEL2 ,   _______ ,
       _______ ,   _______ ,   _______ ,   _______ ,   _______ ,

                                                                   KC_BTN1 ,    KC_BTN2,
                                                                                _______,
                                                       _______ ,   _______ ,    _______,


                            /* RIGHT */
                            _______    , KC_F6      , KC_F7     , KC_F8      , KC_F9       , KC_F10    , KC_F11    ,
                            KC_DELETE  , KC_MS_L    , KC_MS_D   , KC_MS_U    , KC_MS_R     , XXXXXXX   , KC_F12    ,
                                         KC_LEFT    , KC_DOWN   , KC_UP      , KC_RIGHT    , XXXXXXX   , XXXXXXX   ,
                            _______    , KC_NUMLOCK , KC_SLCK   , KC_PSCREEN , KC_CAPSLOCK ,KC_SYSREQ  , _______   ,
                                         _______    , XXXXXXX   , KC_INS     , XXXXXXX     , _______   ,

                           KC_MS_WH_UP , KC_MS_WH_DOWN,
                               _______ ,
                               _______ , _______   , _______
    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1) // FN0 - Momentary Layer 1
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};


// vim:et:ts=4:sw=4
