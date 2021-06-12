VPATH += keyboards/gboards

# Turn off features if not specifically enable in keymap rules.mk
OLED_DRIVER_ENABLE ?= no   # Enables the use of OLED displays
ENCODER_ENABLE ?= no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE ?= no      # Enable keyboard RGB underglow
COMBO_ENABLE ?= no
LEADER_ENABLE ?= no

# Optimization for firmware size reduction
LTO_ENABLE ?= yes
MOUSEKEY_ENABLE ?= no
COMMAND_ENABLE ?= no
UNICODE_ENABLE ?= no
CONSOLE_ENABLE ?= no
SWAP_HANDS_ENABLE ?= no
BACKLIGHT_ENABLE ?= no
VERBOSE ?= no
DEBUG_MATRIX_SCAN_RATE ?= no
DEBUG_MATRIX ?= no
MAGIC_ENABLE ?= no
SPACE_CADET_ENABLE ?= no
GRAVE_ESC_ENABLE ?= no
AUTO_SHIFT_ENABLE ?= no
KEY_LOCK_ENABLE ?= no

# Source shared code
SRC += mguilli.c
