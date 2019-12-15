BLE_SX1509 keyboard firmware
======================

## Quantum MK Firmware

For the full Quantum feature list, see [the parent readme](/).

## Building

Download or clone the whole git and run `make BLE_SX1509:<keymap>` Once the hex is generated, use an uploaded to load the .hex file onto your microcontroller.

### Custom Keymaps

Several version of keymap are available in advance but you are recommended to define your favorite layout yourself. To define your own keymap create a folder with the name of your keymap in the keymaps folder, and see keymap documentation (you can find in top readme.md) and existant keymap files.

To build the firmware binary hex file with a keymap just do `make BLE_SX1509:<keymap>` with your custom keymap.
