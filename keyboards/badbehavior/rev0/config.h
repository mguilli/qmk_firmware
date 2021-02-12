#pragma once

#define VENDOR_ID 0xC001
#define PRODUCT_ID 0xB00B
#define DEVICE_VER 0x0001
#define MANUFACTURER mguilli
#define PRODUCT The Bad Behavior

#define MATRIX_ROWS 1
#define MATRIX_COLS 2

#define MATRIX_ROW_PINS {F5}
#define MATRIX_COL_PINS {F7, D5}

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define ENCODERS_PAD_A { F4, B1 }
#define ENCODERS_PAD_B { F6, B2 }

#define ENCODER_RESOLUTION 4
