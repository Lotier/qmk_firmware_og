#include "flutterby.h"
#include "action_layer.h"
#include "pincontrol.h"
#include <print.h>
#include <stdio.h>
#include "adafruit_ble.h"
#include "outputselect.h"
#ifdef MOUSEKEY_ENABLE
#include "mousekey.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum layer_id {
  BASE = 0,
  RAISE,
  LOWER,
};

// Macro ids for use with M(n)
enum macro_id {
  MCOPY = 1,
  MCUT,
  MPASTE,
};

// Function ids for use with F(n)
enum function_id {
  FNCOPYCUT,
  FNOSTOGGLE,
};

static bool is_mac = false;

#define ____ KC_TRNS
#define CTL(k)  ACTION_MODS_KEY(MOD_LCTL, k)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP_2x2(
  KC_W, KC_A,
  KC_S, KC_D
),

[RAISE] = KEYMAP_2x2(
  CTL(KC_W), CTL(KC_A),
  CTL(KC_S), CTL(KC_D)
  ),

[LOWER] = KEYMAP_2x2(
   KC_LEFT, KC_DOWN,
   KC_UP, KC_RIGHT
),

};

void matrix_init_user(void) {
}

static const macro_t mac_cut[] PROGMEM = { D(LGUI), T(X), U(LGUI), END };
static const macro_t win_cut[] PROGMEM = { D(LSFT), T(DELT), U(LSFT), END };

static const macro_t mac_copy[] PROGMEM = { D(LGUI), T(C), U(LGUI), END };
static const macro_t win_copy[] PROGMEM = { D(LCTL), T(INS), U(LCTL), END };

static const macro_t mac_paste[] PROGMEM = { D(LGUI), T(V), U(LGUI), END };
static const macro_t win_paste[] PROGMEM = { D(LSFT), T(INS), U(LSFT), END };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (!record->event.pressed) {
    return MACRO_NONE;
  }

  switch (id) {
  case MCUT:
    return is_mac ? mac_cut : win_cut;
  case MCOPY:
    return is_mac ? mac_copy : win_copy;
  case MPASTE:
    return is_mac ? mac_paste : win_paste;
  default:
    return MACRO_NONE;
  }
}

// Using F(n) causes the firmware to lookup what to do from this table
const uint16_t PROGMEM fn_actions[] = {
  [FNCOPYCUT] = ACTION_FUNCTION(FNCOPYCUT),
  [FNOSTOGGLE] = ACTION_FUNCTION(FNOSTOGGLE)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    // The OS-Toggle function toggles our concept of mac or windows
    case FNOSTOGGLE:
      if (IS_RELEASED(record->event)) {
        is_mac = !is_mac;
        flutterby_blink_led(is_mac ? 3 : 1);
      }
      return;

    // The copy-cut function sends the copy key sequence for mac or windows
    // when it is pressed.  If shift is held down, it will send the cut key
    // sequence instead, and cancels the shift modifier.
    case FNCOPYCUT:
      if (IS_RELEASED(record->event)) {
        int8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));

        // Implicitly release the shift key so that it doesn't
        // mess with the macro that we play back
        unregister_mods(shifted);

        if (shifted) {
          action_macro_play(is_mac ? mac_cut : win_cut);
        } else {
          action_macro_play(is_mac ? mac_copy : win_copy);
        }
      }
      return;
  }
}

void matrix_scan_user(void) {
  printf("scanning for keys.");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
