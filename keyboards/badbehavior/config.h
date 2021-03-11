#pragma once

#define VENDOR_ID 0xC001
#define PRODUCT_ID 0xB00B
#define DEVICE_VER 0x0100
#define MANUFACTURER mguilli
#define PRODUCT The Bad Behavior

#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS {D3, D2, D1, B0, F4}
#define MATRIX_COL_PINS {F6, F5, F7, B1, B3, B2, B6, B5, B4, E6, D7, C6, D4, D0}
#define UNUSED_PINS {C7}

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define ENCODERS_PAD_A { F0, D5 }
#define ENCODERS_PAD_B { F1, B7 }

#define ENCODER_RESOLUTION 4
