#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#undef TAPPING_TERM
#define IGNORE_MOD_TAP_INTERRUPT

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
