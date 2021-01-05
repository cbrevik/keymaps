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

enum custom_keycodes
{
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  VIM_DOWN_10,
  VIM_UP_10
};

//Tap Dance Declarations
enum
{
  TD_GRTR_GRTRCLOSE = 0,
};

void grtr_tapdance(qk_tap_dance_state_t *state, void *user_data)
{
  register_code(KC_LSFT);
  if (state->count >= 3)
  {
    tap_code(KC_7);
    tap_code(KC_NUBS);
  }
  else if (state->count == 2)
  {
    tap_code(KC_0);
    tap_code(KC_NUBS);
  }
  else
  {
    tap_code(KC_NUBS);
  }
  unregister_code(KC_LSFT);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GRTR_GRTRCLOSE] = ACTION_TAP_DANCE_FN(grtr_tapdance),
};

#define BASE 0 // default layer
#define META 1 // function keys + dev symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer: BASE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    '   |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |  {   |           |   }  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |  (   |           |   )  |   H  |   J  |   K  |   L  |   Ø  |   Æ    |
 * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |                         |   N  |   M  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
 *   | LCtrl| Cmd  | LAlt | RAlt |~META |  ,-------------.     ,--------------. | LEFT | DOWN |  UP  | RIGHT| ~META  |
 *   `----------------------------------'  |      <      |     |  >/=>//>     | `----------------------------------'                                                                                       
 *                                  ,------|------|------|     |------+-------+------.
 *                                  |      |      |      |     |      |       |      |
 *                                  | Space| Space|Delete|     |BckSpc| Enter |Enter |
 *                                  |      |      |      |     |      |       |      |
 *                                  `--------------------'     `---------------------'
 */
    [BASE] = LAYOUT_moonlander(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, NO_LBRC, NO_RBRC, KC_6, KC_7, KC_8, KC_9, KC_0, NO_PLUS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, NO_LCBR_MAC, NO_RCBR_MAC, KC_Y, KC_U, KC_I, KC_O, KC_P, NO_AA,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, NO_LPRN, NO_RPRN, KC_H, KC_J, KC_K, KC_L, NO_OSLH, NO_AE,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        KC_LCTRL, KC_LGUI, KC_LALT, KC_RALT, MO(META), NO_LESS, TD(TD_GRTR_GRTRCLOSE), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, MO(META),
        KC_SPACE, KC_SPACE, KC_DEL, KC_BSPACE, KC_ENTER, KC_ENTER),
    /* Layer: Dev meta
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |   ´  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  ¨   |           |   @  |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | UP 10|DOWN10|      |   ;  |    =   |
 * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
 *   |      |      |      |      |      |  ,-------------.     ,--------------. | HOME |PGDOWN| PGUP |  END |        |
 *   `----------------------------------'  |             |     |              | `----------------------------------'                                                                                       
 *                                  ,------|------|------|     |------+-------+------.
 *                                  |      |      |      |     |      |       |      |
 *                                  |      |      |      |     |      |       |      |
 *                                  |      |      |      |     |      |       |      |
 *                                  `--------------------'     `---------------------'
 */

    [META] = LAYOUT_moonlander(
        KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT, NO_ACUT_MAC, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, NO_QUOT, NO_AT_MAC, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, VIM_DOWN_10, VIM_UP_10, KC_TRANSPARENT, NO_SCLN, NO_EQL,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, KC_TRANSPARENT,
        RGB_VAD, RGB_VAI, KC_TRANSPARENT, RGB_SLD, RGB_HUD, RGB_HUI),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void)
{
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {{0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}, {0, 193, 140}},

    [1] = {{0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}, {0, 51, 232}},

    [2] = {{0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}, {0, 79, 100}},
};

void set_layer_color(int layer)
{
  for (int i = 0; i < DRIVER_LED_TOTAL; i++)
  {
    HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v)
    {
      rgb_matrix_set_color(i, 0, 0, 0);
    }
    else
    {
      RGB rgb = hsv_to_rgb(hsv);
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
  }
}

void rgb_matrix_indicators_user(void)
{
  if (g_suspend_state || keyboard_config.disable_layer_led)
  {
    return;
  }
  switch (biton32(layer_state))
  {
  case 0:
    set_layer_color(0);
    break;
  case 1:
    set_layer_color(1);
    break;
  case 2:
    set_layer_color(2);
    break;
  default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case VIM_DOWN_10:
    if (record->event.pressed)
    {
      tap_code(KC_1);
      tap_code(KC_0);
      tap_code(KC_J);
    }
    return false;
  case VIM_UP_10:
    if (record->event.pressed)
    {
      tap_code(KC_1);
      tap_code(KC_0);
      tap_code(KC_K);
    }
    return false;
  case RGB_SLD:
    if (record->event.pressed)
    {
      rgblight_mode(1);
    }
    return false;
  case HSV_0_255_255:
    if (record->event.pressed)
    {
      rgblight_mode(1);
      rgblight_sethsv(0, 255, 255);
    }
    return false;
  case HSV_86_255_128:
    if (record->event.pressed)
    {
      rgblight_mode(1);
      rgblight_sethsv(86, 255, 128);
    }
    return false;
  case HSV_172_255_255:
    if (record->event.pressed)
    {
      rgblight_mode(1);
      rgblight_sethsv(172, 255, 255);
    }
    return false;
  }
  return true;
}