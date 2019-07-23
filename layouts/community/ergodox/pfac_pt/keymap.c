#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_pt_pt.h"

#define CALT(kc) (QK_LCTL | QK_LALT | (kc))
#define KC_CALT CALT(KC_NO)
#define KC_NXTWRD LCTL(KC_RIGHT)
#define KC_PRVWRD LCTL(KC_LEFT)

struct {
  unsigned int left_shift:1;
  unsigned int right_shift:1;
  unsigned int left_ctrl:1;
  unsigned int right_ctrl:1;
  unsigned int left_alt:1;
  unsigned int right_alt:1;
  unsigned int left_gui:1;
  unsigned int right_gui:1;
} current_mods;

enum custom_layers {
  LAYER_NORMAL,
  LAYER_SHIFT
};

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  ND_GRV,
  ND_TILD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Normal layer
 *
 * ,------------------------------------------------------.           ,--------------------------------------------------------.
 * |  Esc  |   1   |   2  |   3   |   4   |   5   |  L5   |           |  L5   |   6   |   7   |   8  |   9  |   0  |     -     |
 * |-------+-------+------+-------+-------+---------------|           |-------+-------+-------+------+------+------+-----------|
 * |   =   |   Q   |   W  |   E   |   R   |   T   | LGui  |           | RGui  |   Y   |   U   |   I  |   O  |   P  |     \     |
 * |-------+-------+------+-------+-------+-------|       |           |       |-------+-------+------+------+------+-----------|
 * | LCtrl |   A   |   S  |   D   |   F   |   G   |-------|           |-------|   H   |   J   |   K  |   L  |   ;  | ' [RCtrl] |
 * |-------+-------+------+-------+-------+-------| Hyper |           |  Meh  |-------+-------+------+------+------+-----------|
 * | LShift |   Z   |   X  |   C   |   V   |   B   |       |           |       |   N   |   M   |   ,  |   .  |   /  | RShift   |
 * `-------+-------+------+-------+-------+---------------'           `---------------+-------+------+------+------+-----------'
 *   | ~L2 | VolDn | Mute | VolUp |  LAlt  |                                           |  RAlt  | Prev | Play | Next |  ~L2  |
 *   `------------------------------------'                                           `------------------------------------'
 *                                        ,---------------.           ,---------------.
 *                                        |  Ins  |       |           |       |  Ins  |
 *                                ,-------|-------|-------|           |-------+-------+-------.
 *                                |       |       |  Del  |           | PrtSc |       |       |
 *                                | Space | BckSp |-------|           |-------|  Tab  | Enter |
 *                                |       |       |  ~L3  |           |  ~L3  |       |       |
 *                                `-----------------------'           `-----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[LAYER_NORMAL] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_ESC,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,  TG(5),
  PT_EQL,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  LGUI(0),
  KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_HYPR,
  MO(2),       KC_VOLD,  KC_MUTE,  KC_VOLU,  KC_LALT,

                                             KC_INS,   KC_TRNS,
                                                       KC_DEL,
                                    KC_SPC,   KC_BSPC,  MO(3),

  // right hand
  TG(5),           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      PT_MINS,
  LGUI(0),         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      PT_BSLS,
                   KC_H,     KC_J,     KC_K,     KC_L,     PT_SCLN,   PT_QUOT,
  KC_MEH,          KC_N,     KC_M,     PT_COMM,  PT_DOT,   PT_SLSH,   KC_RSFT,
                             KC_RALT,  KC_MPRV,  KC_MPLY,  KC_MNXT,   MO(2),

  KC_TRNS,         KC_INS,
  KC_PSCR,
  MO(3),           KC_TAB,   KC_ENT
),


/* Keymap 2: Coder layer
 *
 * ,-------------------------------------------------.           ,--------------------------------------------------.
 * |       |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10  |  F11  |
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
  KC_TRNS,     KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_TRNS,
  KC_TRNS,     PT_EXLM,     PT_AT,       PT_LCBR,     PT_RCBR,     PT_PIPE,     KC_TRNS,
  KC_TRNS,     PT_HASH,     PT_DLR,      PT_LBRC,     PT_RBRC,     ND_GRV,
  KC_TRNS,     PT_PERC,     PT_CIRC,     PT_LPRN,     PT_RPRN,     ND_TILD,     KC_TRNS,
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
 *                             | Debug |      |------|           |------|      |       |
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
                                                      DEBUG,     KC_TRNS,     KC_TRNS,

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

void save_mods(uint16_t keycode, keyevent_t *event) {
  unsigned int pressed = !!event->pressed;

  switch (keycode) {
    case KC_LSFT:
      current_mods.left_shift = pressed;
      break;
    case KC_RSFT:
      current_mods.right_shift = pressed;
      break;
    case KC_LCTL:
      current_mods.left_ctrl = pressed;
      break;
    case KC_RCTL:
      current_mods.right_ctrl = pressed;
      break;
    case KC_LALT:
      current_mods.left_alt = pressed;
      break;
    case KC_RALT:
      current_mods.right_alt = pressed;
      break;
    case KC_LGUI:
      current_mods.left_gui = pressed;
      break;
    case KC_RGUI:
      current_mods.right_gui = pressed;
      break;
  }
}

void restore_mods(void) {
  clear_mods();

  if (current_mods.left_shift)  register_code16(KC_LSFT);
  if (current_mods.right_shift) register_code16(KC_RSFT);
  if (current_mods.left_ctrl)   register_code16(KC_LCTL);
  if (current_mods.right_ctrl)  register_code16(KC_RCTL);
  if (current_mods.left_alt)    register_code16(KC_LALT);
  if (current_mods.right_alt)   register_code16(KC_RALT);
  if (current_mods.left_gui)    register_code16(KC_LGUI);
  if (current_mods.right_gui)   register_code16(KC_RGUI);
}

void override_with_keycode(uint16_t new_keycode, keyevent_t *event) {
  clear_mods();

  if (event->pressed) {
    register_code16(new_keycode);
  } else {
    unregister_code16(new_keycode);
  }
}

void override_with_dead_keycode(uint16_t keycode, keyevent_t *event) {
  clear_mods();

  if (event->pressed) {
    register_code16(keycode);
  } else {
    unregister_code16(keycode);
    register_code16(KC_SPC);
    unregister_code16(KC_SPC);
  }
}

bool is_shift_active(void) {
  return current_mods.left_shift || current_mods.right_shift;
}

/** Map regular keys with symbols under Shift to send the UK/US layout symbols.
 *
 * This allows me to keep the system keyboard pt_PT (for the special dead keys)
 * but have the symbols in a UK/US layout for easier coding.
 *
 * Every other key will not be remapped.
 */
bool override_shifted(uint16_t keycode, keyevent_t *event) {
  if (!is_shift_active())
    return false;

  switch (keycode) {
    case PT_EQL:
      override_with_keycode(PT_PLUS, event);
      return true;
    case KC_1:
      override_with_keycode(PT_EXLM, event);
      return true;
    // For some reason, sending PT_AT through register_code does not work and
    // produces some bad characters. I can't seem to fix this behaviour so
    // instead I'm rolling with default shift+2 for the pt_PT layout (which is
    // double-quotes) and using the symbol layer as the alternative, mimicking
    // Shift for the number keys.
    //
    case KC_2:
      override_with_keycode(PT_AT, event);
      return true;
    case KC_3:
      override_with_keycode(PT_HASH, event);
      return true;
    case KC_4:
      override_with_keycode(PT_DLR, event);
      return true;
    case KC_5:
      override_with_keycode(PT_PERC, event);
      return true;
    case KC_6:
      override_with_dead_keycode(PT_CIRC, event);
      return true;
    case KC_7:
      override_with_keycode(PT_AMPR, event);
      return true;
    case KC_8:
      override_with_keycode(PT_AST, event);
      return true;
    case KC_9:
      override_with_keycode(PT_LPRN, event);
      return true;
    case KC_0:
      override_with_keycode(PT_RPRN, event);
      return true;
    case PT_MINS:
      override_with_keycode(PT_UNDS, event);
      return true;
    case PT_BSLS:
      override_with_keycode(PT_PIPE, event);
      return true;
    case PT_SCLN:
      override_with_keycode(PT_CLN, event);
      return true;
    case PT_QUOT:
      override_with_keycode(PT_DQUT, event);
      return true;
    case PT_COMM:
      override_with_keycode(PT_LABK, event);
      return true;
    case PT_DOT:
      override_with_keycode(PT_RABK, event);
      return true;
    case PT_SLSH:
      override_with_keycode(PT_QUES, event);
      return true;
  }

  return false;
}


bool process_record_user_aux(uint16_t keycode, keyevent_t *event) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, event->key.col, event->key.row, event->pressed);
#endif 

  if (override_shifted(keycode, event))
    return false;

  switch (keycode) {
    case EPRM:
      if (event->pressed) {
        eeconfig_init();
      }
      return false;
    case ND_GRV:
      override_with_dead_keycode(PT_GRV, event);
      return false;
    case ND_TILD:
      override_with_dead_keycode(PT_TILD, event);
      return false;
  }

  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result;
  keyevent_t *event = &(record->event);

  save_mods(keycode, event);
  result = process_record_user_aux(keycode, event);
  restore_mods();

  return result;
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

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LCTL_T(KC_ESC):
      return 120;
    default:
      return TAPPING_TERM;
  }
}
