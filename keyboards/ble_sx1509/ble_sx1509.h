#ifndef BLE_SX1509_H
#define BLE_SX1509_H

#include "quantum.h"

#define KEYMAP(                        \
    /* left hand */                    \
         k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
                                  k07, \
                             k36, k17, \
                             k37, k27, \
    /* right hand */                   \
    k09, k0a, k0b, k0c, k0d, k0e,      \
    k19, k1a, k1b, k1c, k1d, k1e, k1f, \
    k29, k2a, k2b, k2c, k2d, k2e, k2f, \
         k3a, k3b, k3c, k3d, k3e, k3f, \
    k08,                               \
    k18, k39,                          \
    k28, k38) {                        \
  { KC_NO, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, KC_NO }, \
  {   k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, k1f }, \
  {   k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f }, \
  {   k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f }, \
}

#define KEYMAP_2x2(   \
    k01, k02,         \
    k03, k04          \
) {                   \
     { k01, k02 },    \
     { k03, k04 },    \
 }

 #define KEYMAP_6X16( \
    K00,      K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C,      K0D, K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K1E, K1F, K3F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F, K3E, K4F, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,                     \
    K40,      K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A,      K4C,           K4E,      \
    K50, K51, K52,                K55,                K59, K5A, K5B, K5C,      K5D, K5E, K5F  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   KC_NO, K2F   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   KC_NO, K3E,   K3F   }, \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48,   K49,   K4A,   KC_NO, K4C,   KC_NO, K4E,   K4F   }, \
    { K50,   K51,   K52,   KC_NO, KC_NO, K55,   KC_NO, KC_NO, KC_NO, K59,   K5A,   K5B,   K5C,   K5D,   K5E,   K5F   }  \
}

bool sx1509_init(void);
uint16_t sx1509_read(void);
bool sx1509_make_ready(void);

void feather_led_enable(bool on);
void feather_blink_led(int times);

#endif
