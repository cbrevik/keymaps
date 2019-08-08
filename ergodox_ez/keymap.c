#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_norwegian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  TOGGLE_LAYER_COLOR,
  EPRM,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
};

//Tap Dance Declarations
enum {
  TD_SEMICOLON_OE = 0,
  TD_F12_AA,
  TD_APOS_AE
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SEMICOLON_OE]  = ACTION_TAP_DANCE_DOUBLE(NO_SCLN, NO_OSLH),
  [TD_F12_AA]  = ACTION_TAP_DANCE_DOUBLE(KC_F12, NO_AA),
  [TD_APOS_AE]  = ACTION_TAP_DANCE_DOUBLE(NO_APOS, NO_AE),
};

#define BASE 0 // default layer
#define SYMBOLS 1 // numbers + function keys
#define MOUSE 2 // mouse
#define OVERWATCH 3 // specifically overwatch gaming

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: Base
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    |   |   !  |   @  |   #  |   $  |   %  |  [   |           |   ]  |   ^  |   &  |   *  |   +  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |  (   |           |   )  |   Y  |   U  |   I  |   O  |   P  |  F12/å |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;/ø |   '/æ  |
 * |--------+------+------+------+------+------|  {   |           |   }  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| Win  | LAlt | ~L1  | RCtrl|                                       | LEFT | DOWN |  UP  | RIGHT|  ~L2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |  L1  |  L2  |       |ShftF10|RighAlt|
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |  L3  |       | PgUp |       |      |
 *                                 | Space| Space|------|       |------| BckSpc|Enter |
 *                                 |      |      | End  |       | PgDwn|       |      |
 *                                 `--------------------'       `---------------------'
 */
  [BASE] = LAYOUT_ergodox(
    // left
    KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, NO_LBRC, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, NO_LPRN,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, 
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, NO_LCBR,
      KC_LCTRL, KC_LGUI, KC_LALT, MO(1), KC_RCTRL,

    // mid left
    TG(1), TG(2), TG(3), KC_SPACE, KC_SPACE, KC_END,
    
    // right
    NO_RBRC, KC_CIRC, KC_AMPR, KC_KP_ASTERISK, KC_PLUS, KC_MINUS, KC_EQUAL,
    NO_RPRN, KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_F12_AA),
    KC_H, KC_J, KC_K, KC_L, TD(TD_SEMICOLON_OE), TD(TD_APOS_AE),
    NO_RCBR, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, MO(2),
    
    // mid right
    LSFT(KC_F10), KC_RALT, KC_PGUP, KC_PGDOWN, KC_BSPACE, KC_ENTER
  ),

/* Layer 1: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  ~   |  7   |  8   |  9   |  *   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  `   |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  .   | Enter|  =   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

  [SYMBOLS] = LAYOUT_ergodox(
    // left
    KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    
    // left mid
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    
    // right
    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
    KC_TRANSPARENT, KC_TILD, KC_7, KC_8, KC_9, KC_ASTR, KC_F12, 
    KC_GRAVE, KC_4, KC_5, KC_6, KC_PLUS, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_BSLASH, 
      KC_TRANSPARENT, KC_0, KC_DOT, KC_KP_ENTER, KC_EQUAL, KC_TRANSPARENT, 
      
    // right mid
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ), 

/* Layer 2: Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | M UP |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | MLEFT| MDWN |MRIGHT|WHEELU|------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |M BTN1|      |M BTN2|WHEELD|      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [MOUSE] = LAYOUT_ergodox(
    // left
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_UP, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_TRANSPARENT, KC_MS_BTN2, KC_MS_WH_DOWN, KC_TRANSPARENT, 
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    
    // left mid
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    
    // right
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    
    // right mid
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ), 

/* Layer 3: Overwatch - nothing transparent, every key has a purpose or does not work at all
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Hero |   1  |   2  |      |      |  Esc |   P  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |      |   C  |   V  |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| LCtrl|      |   C  |   V  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |      |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |  L3  |       |      |       |      |
 *                                 | Space| Space|------|       |------|       |      |
 *                                 |      |      |      |       |      |       |      |
 *                                 `--------------------'       `---------------------'
 */
  [OVERWATCH] = LAYOUT_ergodox(
    // left
    KC_H, KC_1, KC_2, KC_NO, KC_NO, KC_ESCAPE, KC_P, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO,
    KC_NO, KC_A, KC_S, KC_D, KC_F, KC_NO, 
    KC_LSHIFT, KC_Z, KC_NO, KC_C, KC_V, KC_NO, KC_NO,
      KC_LCTRL, KC_LCTRL, KC_NO, KC_C, KC_V,

    // mid left
    KC_NO, KC_NO, TG(3), KC_SPACE, KC_SPACE, KC_NO,
    
    // right
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    
    // mid right
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;
bool disable_layer_color = 0;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [1] = { {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {218,255,255}, {218,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {218,255,255}, {218,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {218,255,255}, {31,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255}, {218,255,255} },

    [2] = { {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {15,166,195}, {15,166,195}, {15,166,195}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {0,183,238}, {103,255,255}, {103,255,255}, {0,183,238}, {0,183,238}, {0,183,238}, {0,183,238}, {103,255,255}, {0,183,238}, {0,183,238}, {103,255,255}, {0,183,238}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255}, {103,255,255} },

    [3] = { {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {85,203,158}, {10,225,255}, {10,225,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || disable_layer_color) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case RGB_TOG:
  if (record->event.pressed) {
    if (rgb_matrix_config.hsv.v) {
      rgb_matrix_sethsv(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 0);
    } else {
      rgb_matrix_sethsv(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 255);
    }
  }
  return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
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
