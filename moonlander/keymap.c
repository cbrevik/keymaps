#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_norwegian.h"

#define NO_PIPE KC_GRV        // |
#define NO_1 KC_1             // 1
#define NO_2 KC_2             // 2
#define NO_3 KC_3             // 3
#define NO_4 KC_4             // 4
#define NO_5 KC_5             // 5
#define NO_6 KC_6             // 6
#define NO_7 KC_7             // 7
#define NO_8 KC_8             // 8
#define NO_9 KC_9             // 9
#define NO_0 KC_0             // 0
#define NO_PLUS KC_MINS       // +
#define NO_BSLS KC_EQL        // (backslash)
#define NO_Q KC_Q             // Q
#define NO_W KC_W             // W
#define NO_E KC_E             // E
#define NO_R KC_R             // R
#define NO_T KC_T             // T
#define NO_Y KC_Y             // Y
#define NO_U KC_U             // U
#define NO_I KC_I             // I
#define NO_O KC_O             // O
#define NO_P KC_P             // P
#define NO_ARNG KC_LBRC       // Å
#define NO_DIAE KC_RBRC       // ¨ (dead)
#define NO_A KC_A             // A
#define NO_S KC_S             // S
#define NO_D KC_D             // D
#define NO_F KC_F             // F
#define NO_G KC_G             // G
#define NO_H KC_H             // H
#define NO_J KC_J             // J
#define NO_K KC_K             // K
#define NO_L KC_L             // L
#define NO_OSTR KC_SCLN       // Ø
#define NO_AE KC_QUOT         // Æ
#define NO_QUOT KC_NUHS       // '
#define NO_LABK KC_NUBS       // <
#define NO_Z KC_Z             // Z
#define NO_X KC_X             // X
#define NO_C KC_C             // C
#define NO_V KC_V             // V
#define NO_B KC_B             // B
#define NO_N KC_N             // N
#define NO_M KC_M             // M
#define NO_COMM KC_COMM       // ,
#define NO_DOT KC_DOT         // .
#define NO_MINS KC_SLSH       // -
#define NO_SECT S(NO_PIPE)    // §
#define NO_EXLM S(NO_1)       // !
#define NO_DQUO S(NO_2)       // "
#define NO_HASH S(NO_3)       // #
#define NO_CURR S(NO_4)       // ¤
#define NO_PERC S(NO_5)       // %
#define NO_AMPR S(NO_6)       // &
#define NO_SLSH S(NO_7)       // /
#define NO_LPRN S(NO_8)       // (
#define NO_RPRN S(NO_9)       // )
#define NO_EQL S(NO_0)        // =
#define NO_QUES S(NO_PLUS)    // ?
#define NO_GRV S(NO_BSLS)     // ` (dead)
#define NO_CIRC S(NO_DIAE)    // ^ (dead)
#define NO_ASTR S(NO_QUOT)    // *
#define NO_RABK S(NO_LABK)    // >
#define NO_SCLN S(NO_COMM)    // ;
#define NO_COLN S(NO_DOT)     // :
#define NO_UNDS S(NO_MINS)    // _
#define NO_AT ALGR(NO_2)      // @
#define NO_PND ALGR(NO_3)     // £
#define NO_DLR ALGR(NO_4)     // $
#define NO_EURO ALGR(NO_5)    // €
#define NO_LCBR ALGR(NO_7)    // {
#define NO_LBRC ALGR(NO_8)    // [
#define NO_RBRC ALGR(NO_9)    // ]
#define NO_RCBR ALGR(NO_0)    // }
#define NO_ACUT ALGR(NO_BSLS) // ´ (dead)
#define NO_TILD ALGR(NO_DIAE) // ~ (dead)
#define NO_MICR ALGR(NO_M)    // µ

// Norwegian unique MAC characters
#define NO_ACUT_MAC KC_EQL           // =
#define NO_APOS_MAC KC_NUBS          // '
#define NO_AT_MAC KC_BSLS            // @
#define NO_BSLS_MAC ALGR(LSFT(KC_7)) // '\'
#define NO_DLR_MAC LSFT(KC_4)        // $
#define NO_GRV_MAC ALGR(NO_BSLS)     // `
#define NO_GRTR_MAC LSFT(KC_GRV)     // >
#define NO_LCBR_MAC ALGR(LSFT(KC_8)) // }
#define NO_LESS_MAC KC_GRV           // >
#define NO_PIPE_MAC ALGR(KC_7)       // |
#define NO_RCBR_MAC ALGR(LSFT(KC_9)) // }
#define NO_LESS KC_NUBS

#define NO_DIAE KC_RBRC // ¨ (dead)
#define NO_AA KC_LBRC

enum custom_keycodes
{
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  VIM_DOWN_10,
  VIM_UP_10,
  VIM_LEFT_10,
  VIM_RIGHT_10
};

// Tap Dance Declarations
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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GRTR_GRTRCLOSE] = ACTION_TAP_DANCE_FN(grtr_tapdance),
};

#define BASE_MAC 0 // default layer
#define META 1     // function keys + dev symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer: BASE MAC
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
    [BASE_MAC] = LAYOUT_moonlander(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, NO_LBRC, NO_RBRC, KC_6, KC_7, KC_8, KC_9, KC_0, NO_PLUS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, NO_LCBR_MAC, NO_RCBR_MAC, KC_Y, KC_U, KC_I, KC_O, KC_P, NO_AA,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, NO_LPRN, NO_RPRN, KC_H, KC_J, KC_K, KC_L, NO_OSTR, NO_AE,
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
     * |        |      |      |      |      |      |  ^   |           |   ~  |LEFT10| UP 10|DOWN10|RGHT10|   ;  |    =   |
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
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, NO_ACUT_MAC, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        _______, _______, _______, _______, _______, _______, NO_DIAE, NO_AT_MAC, _______, _______, _______, _______, _______, KC_F12,
        _______, _______, _______, _______, _______, _______, NO_CIRC, NO_TILD, VIM_LEFT_10, VIM_DOWN_10, VIM_UP_10, VIM_RIGHT_10, NO_SCLN, NO_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, _______,
        RGB_VAD, RGB_VAI, _______, RGB_SLD, RGB_HUD, RGB_HUI),
};

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
  if (rawhid_state.rgb_control)
  {
    return;
  }
  if (keyboard_config.disable_layer_led)
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
  case VIM_LEFT_10:
    if (record->event.pressed)
    {
      tap_code(KC_1);
      tap_code(KC_0);
      tap_code(KC_H);
    }
    return false;
  case VIM_RIGHT_10:
    if (record->event.pressed)
    {
      tap_code(KC_1);
      tap_code(KC_0);
      tap_code(KC_L);
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
