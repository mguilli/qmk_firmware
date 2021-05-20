#pragma once

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define TAP_CODE_DELAY 10

// Prevent normal rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents short hold periods to be interpretedas individual taps when typing quickly
#define PERMISSIVE_HOLD
