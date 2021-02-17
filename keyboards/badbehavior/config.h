#pragma once

#define VENDOR_ID 0xC001
#define PRODUCT_ID 0xB00B
#define DEVICE_VER 0x0100
#define MANUFACTURER mguilli
#define PRODUCT The Bad Behavior

#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS {D3, D2, D1, B0, F4}
#define MATRIX_COL_PINS {D0, D4, C6, D7, E6, B4, B5, F5, F6, F7, B1, B3, B2, B6}
#define UNUSED_PINS {C7}

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define ENCODERS_PAD_A { B7, D5 }
#define ENCODERS_PAD_B { F1, F0 }

#define ENCODER_RESOLUTION 4
