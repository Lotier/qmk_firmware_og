#include "ble_sx1509.h"
#include "pincontrol.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}

// Controls the Red LED attached to arduino pin 13
void feather_led_enable(bool on) {
  digitalWrite(C7, on ? PinLevelHigh : PinLevelLow);
}

void feather_blink_led(int times) {
  while (times--) {
    _delay_ms(50);
    feather_led_enable(true);
    _delay_ms(150);
    feather_led_enable(false);
  }
}
