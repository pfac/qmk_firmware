/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// Make TAPPING_TERM key specific.
// This allows overriding the TAPPING_TERM for the Ctrl/Esc key I use on
// Caps Lock position, which I want to make a lot lower than other keys.
#define TAPPING_TERM_PER_KEY

// Assume HOLD over tap if another key is pressed along with a dual-key
#define PERMISSIVE_HOLD

// Fix a issue with some keys (M and G mostly on my own keyboard) where the
// key would sometimes fail to send the code, and some other times would send
// it multiple times.
#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 300
