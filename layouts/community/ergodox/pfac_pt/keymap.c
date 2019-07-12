#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_pt_pt.h"

#define CALT(kc) (QK_LCTL | QK_LALT | (kc))
#define KC_CALT CALT(KC_NO)
#define KC_NXTWRD LCTL(KC_RIGHT)
#define KC_PRVWRD LCTL(KC_LEFT)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Normal layer
 *
 * ,------------------------------------------------------.           ,--------------------------------------------------------.
 * |   =   |   1   |   2  |   3   |   4   |   5   |  L5   |           |  L5   |   6   |   7   |   8  |   9  |   0  |     -     |
 * |-------+-------+------+-------+-------+---------------|           |-------+-------+-------+------+------+------+-----------|
 * |  Esc  |   Q   |   W  |   E   |   R   |   T   | LGui  |           | RGui  |   Y   |   U   |   I  |   O  |   P  |     \     |
 * |-------+-------+------+-------+-------+-------|       |           |       |-------+-------+------+------+------+-----------|
 * | LCtrl |   A   |   S  |   D   |   F   |   G   |-------|           |-------|   H   |   J   |   K  |   L  |   ;  | ' [RCtrl] |
 * |-------+-------+------+-------+-------+-------| Hyper |           |  Meh  |-------+-------+------+------+------+-----------|
 * |  ~L1  |   Z   |   X  |   C   |   V   |   B   |       |           |       |   N   |   M   |   ,  |   .  |   /  |    ~L1    |
 * `-------+-------+------+-------+-------+---------------'           `---------------+-------+------+------+------+-----------'
 *   | ~L2 | VolDn | Mute | VolUp |  ~L4  |                                           |  ~L4  | Prev | Play | Next |  ~L2  |
 *   `------------------------------------'                                           `------------------------------------'
 *                                        ,---------------.           ,---------------.
 *                                        |  Ins  |       |           |       |  Ins  |
 *                                ,-------|-------|-------|           |-------+-------+-------.
 *                                |       |       |  Del  |           | PrtSc |       |       |
 *                                | Space |  Tab  |-------|           |-------| BckSp | Enter |
 *                                |       |       |  ~L3  |           |  ~L3  |       |       |
 *                                `-----------------------'           `-----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[0] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  PT_EQL,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,  TG(5),
  KC_TRNS,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  LGUI(0),
  LCTL_T(KC_ESC),     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  MO(1),       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_HYPR,
  MO(2),       KC_VOLD,  KC_MUTE,  KC_VOLU,  MO(4),

                                             KC_INS,   KC_TRNS,
                                                       KC_DEL,
                                    KC_SPC,   KC_TAB,  MO(3),

  // right hand
  TG(5),           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      PT_MINS,
  LGUI(0),         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      PT_BSLS,
                   KC_H,     KC_J,     KC_K,     KC_L,     PT_SCLN,   RCTL_T(PT_QUOT),
  KC_MEH,          KC_N,     KC_M,     PT_COMM,  PT_DOT,   PT_SLSH,   MO(1),
                             MO(4),    KC_MPRV,  KC_MPLY,  KC_MNXT,   MO(2),

  KC_TRNS,         KC_INS,
  KC_PSCR,
  MO(3),           KC_BSPC,   KC_ENT
),


/* Keymap 1: Shift layer
 *
 * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
 * |   +   |    !    |    @    |    #    |    $    |    %    |      |           |      |    ^    |    &    |    *    |    (    |    )    |   _   |
 * |-------+---------+---------+---------+---------+---------+------|           |------+---------+---------+---------+---------+---------+-------|
 * |       | Shift+Q | Shift+W | Shift+E | Shift+R | Shift+T |      |           |      | Shift+Y | Shift+U | Shift+I | Shift+O | Shift+P |   |   |
 * |-------+---------+---------+---------+---------+---------|      |           |      |---------+---------+---------+---------+---------+-------|
 * |       | Shift+A | Shift+S | Shift+D | Shift+F | Shift+G |------|           |------| Shift+H | Shift+J | Shift+K | Shift+L |    :    |   "   |
 * |-------+---------+---------+---------+---------+---------|      |           |      |---------+---------+---------+---------+---------+-------|
 * | (~L1) | Shift+Z | Shift+X | Shift+C | Shift+V | Shift+B |      |           |      | Shift+N | Shift+M |    <    |    >    |    ?    | (~L1) |
 * `-------+---------+---------+---------+---------+----------------'           `----------------+---------+---------+---------+---------+-------'
 *    |    |         |         |         |         |                                   |         |         |         |         |         |
 *    `--------------------------------------------'                                   `-------------------------------------------------'
 *                                                 ,----------------.           ,----------------.
 *                                                 |         |      |           |      |         |
 *                                       ,---------|---------|------|           |------+---------+---------.
 *                                       |         |         |      |           |      |         |         |
 *                                       |         |         |------|           |------|         |         |
 *                                       |         |         |      |           |      |         |         |
 *                                       `--------------------------'           `--------------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[1] = LAYOUT_ergodox(  // layer 1 : default
  // left hand
  PT_PLUS,  PT_EXLM,  PT_AT,    PT_HASH,  PT_DLR,   PT_PERC,  KC_TRNS,
  KC_TRNS,  LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T),  KC_TRNS,
  KC_TRNS,  LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G),
  KC_TRNS,  LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                 KC_TRNS,   KC_TRNS,
                                                           KC_TRNS,
                                       KC_TRNS,   KC_TRNS,  KC_TRNS,

  // right hand
  KC_TRNS,  PT_CIRC,     PT_AMPR,     PT_AST,      PT_LPRN,     PT_RPRN,     PT_UNDS,
  KC_TRNS,  RSFT(KC_Y),  RSFT(KC_U),  RSFT(KC_I),  RSFT(KC_O),  RSFT(KC_P),  PT_PIPE,
            RSFT(KC_H),  RSFT(KC_J),  RSFT(KC_K),  RSFT(KC_L),  PT_CLN,      PT_DQUT,
  KC_TRNS,  RSFT(KC_N),  RSFT(KC_M),  PT_LABK,     PT_RABK,     PT_QUES,     KC_TRNS,
            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

  KC_TRNS,  KC_TRNS,
  KC_TRNS,
  KC_TRNS,               KC_TRNS,     KC_TRNS
),


/* Keymap 2: Coder layer
 *
 * ,-------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10  |  F11  |
 * |-------+------+------+------+------+------+------|           |------+------+------+------+------+-------+-------|
 * |       |  !   |  @   |  {   |  }   |  |   |      |           |      |  =   |  {   |  }   |      |       |  F12  |
 * |-------+------+------+------+------+------|      |           |      |------+------+------+------+-------+-------|
 * |       |  #   |  $   |  [   |  ]   |  `   |------|           |------|  +   |  [   |  ]   |      |       |       |
 * |-------+------+------+------+------+------|      |           |      |------+------+------+------+-------+-------|
 * |       |  %   |  ^   |  (   |  )   |  ~   |      |           |      |  &   |  (   |  )   |      |       |       |
 * `-------+------+------+------+------+-------------'           `-------------+------+------+------+-------+-------'
 *   |(~L2)|      |      |      |      |                                       |      |      |      |       |(~L2)|
 *   `---------------------------------'                                       `----------------------------------'
 *                                     ,-------------.           ,-------------.
 *                                     |      |      |           |      |      |
 *                              ,------|------|------|           |------+------+------.
 *                              |      |      |      |           |      |      |      |
 *                              |      |      |------|           |------|      |      |
 *                              |      |      |      |           |      |      |      |
 *                              `--------------------'           `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[2] = LAYOUT_ergodox(  // layer 1 : default
  // left hand
  KC_ESC,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_TRNS,
  KC_TRNS,     PT_EXLM,     PT_AT,       PT_LCBR,     PT_RCBR,     PT_PIPE,     KC_TRNS,
  KC_TRNS,     PT_HASH,     PT_DLR,      PT_LBRC,     PT_RBRC,     PT_GRV,
  KC_TRNS,     PT_PERC,     PT_CIRC,     PT_LPRN,     PT_RPRN,     PT_TILD,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                                   KC_TRNS,     KC_TRNS,
                                                                                KC_TRNS,
                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,

  // right hand
  KC_TRNS,     KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,
  KC_TRNS,     PT_EQL,      PT_LCBR,     PT_RCBR,     KC_TRNS,     KC_TRNS,     KC_F12,
               PT_PLUS,     PT_LBRC,     PT_RBRC,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     PT_AMPR,     PT_LPRN,     PT_RPRN,     KC_TRNS,     KC_TRNS,     KC_TRNS,
               KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

  KC_TRNS,     KC_TRNS,
  KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS
),


/* Keymap 3: Vim-like layer
 *
 * ,-----------------------------------------------------.           ,--------------------------------------------------.
 * |      |      |        |      |      |        |       |           |       |      |      |      |       |      |      |
 * |------+------+--------+------+------+--------+-------|           |-------+------+------+------+-------+------+------|
 * |      |      | NxtWrd |      |      |        |       |           |       |      | PgDn | PgUp |       |      |      |
 * |------+------+--------+------+------+--------|       |           |       |------+------+------+-------+------+------|
 * |      |      |        |      |      |        |-------|           |-------| Left | Down |  Up  | Right |      |      |
 * |------+------+--------+------+------+--------|       |           |       |------+------+------+-------+------+------|
 * |      |      |        |      |      | PrvWrd |       |           |       |      | PgDn | PgUp |       |      |      |
 * `------+------+--------+------+------+----------------'           `--------------+------+------+-------+------+------'
 *   |    |      |        |      |      |                                           |      |      |       |      |    |
 *   `----------------------------------'                                           `---------------------------------'
 *                                      ,----------------.           ,-------------.
 *                                      |        |       |           |       |      |
 *                               ,------|--------|-------|           |-------+------+------.
 *                               |      |        |       |           |       |      |      |
 *                               |      |        |-------|           |-------|      |      |
 *                               |      |        | (~L3) |           | (~L3) |      |      |
 *                               `-----------------------'           `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[3] = LAYOUT_ergodox(  // layer 1 : default
  // left hand
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_NXTWRD,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_PRVWRD,  KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                                   KC_TRNS,     KC_TRNS,
                                                                                KC_TRNS,
                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,

  // right hand
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_PGDN,     KC_PGUP,     KC_TRNS,     KC_TRNS,     KC_TRNS,
               KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_PGDN,     KC_PGUP,     KC_TRNS,     KC_TRNS,     KC_TRNS,
               KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

  KC_TRNS,     KC_TRNS,
  KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS
),


/* Keymap 4: Specials layer
 *
 * ,-------------------------------------------------------.           ,-------------------------------------------------.
 * |          |       |       |      |       |      |      |           |      |      |       |      |      |      |      |
 * |----------+-------+-------+------+-------+------+------|           |------+------+-------+------+------+------+------|
 * | Alt+Tab  |       | Acute |      |       |      |      |           |      |      | Trema |  ^   |      |      |      |
 * |----------+-------+-------+------+-------+------|      |           |      |------+-------+------+------+------+------|
 * | Alt+Ctrl |       |       |      |       |      |------|           |------|      |       |      |      |      |      |
 * |----------+-------+-------+------+-------+------|      |           |      |------+-------+------+------+------+------|
 * |          | Grave |       |  Ç   |       |      |      |           |      |      |       |      |      |      |      |
 * `----------+-------+-------+------+-------+-------------'           `-------------+-------+------+------+------+------'
 *   |        |       |       |      | (~L4) |                                       | (~L4) |      |      |      |    |
 *   `---------------------------------------'                                       `---------------------------------'
 *                                           ,-------------.           ,-------------.
 *                                           |      |      |           |      |      |
 *                                   ,-------|------|------|           |------+------+-------.
 *                                   |       |      |      |           |      |      |       |
 *                                   |       |      |------|           |------|      |       |
 *                                   |       |      |      |           |      |      |       |
 *                                   `---------------------'           `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[4] = LAYOUT_ergodox(  // layer 1 : default
  // left hand
  KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,  KC_TRNS,     PT_ACUT,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_CALT,       KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,       PT_GRV,      KC_TRNS,     PT_CCDL,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                                     KC_TRNS,     KC_TRNS,
                                                                                  KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,

  // right hand
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     PT_TRMA,     PT_CIRC,     KC_TRNS,     KC_TRNS,     KC_TRNS,
               KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
               KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

  KC_TRNS,     KC_TRNS,
  KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS
),


/* Keymap 5: NumPad layer
 *
 * ,------------------------------------------------.           ,-------------------------------------------------.
 * |      |      |      |      |      |      | (L5) |           | (L5) |      |      |      |      |       |      |
 * |------+------+------+------+------+------+------|           |------+------+------+------+------+-------+------|
 * |      |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +   |      |
 * |------+------+------+------+------+------|      |           |      |------+------+------+------+-------+------|
 * |      |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   *   |      |
 * |------+------+------+------+------+------|      |           |      |------+------+------+------+-------+------|
 * |      |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   /   |      |
 * `------+------+------+------+------+-------------'           `-------------+------+------+------+-------+------'
 *   |    |      |      |      |      |                                       |   0  |   0  |   .  | Enter |    |
 *   `--------------------------------'                                       `---------------------------------'
 *                                    ,-------------.           ,-------------.
 *                                    |      |      |           |      |      |
 *                             ,------|------|------|           |------+------+-------.
 *                             |      |      |      |           |      |      |       |
 *                             |      |      |------|           |------|      |       |
 *                             |      |      |      |           |      |      |       |
 *                             `--------------------'           `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[5] = LAYOUT_ergodox(  // layer 1 : default
  // left hand
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                                   KC_TRNS,     KC_TRNS,
                                                                                KC_TRNS,
                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,

  // right hand
  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_P7,       KC_P8,       KC_P9,       KC_PPLS,     KC_TRNS,
               KC_TRNS,     KC_P4,       KC_P5,       KC_P6,       KC_PAST,     KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_P1,       KC_P2,       KC_P3,       KC_PSLS,     KC_TRNS,
               KC_TRNS,     KC_P0,       KC_P0,       KC_PDOT,     KC_PENT,

  KC_TRNS,     KC_TRNS,
  KC_TRNS,
  KC_TRNS,     KC_TRNS,     KC_TRNS
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
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
  return state;
};
