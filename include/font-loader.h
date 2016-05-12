#pragma once

#include <pebble.h>

// Initialise the font loading library.
void fonts_init(void);

// Assign a string name to a font resource ID.
void fonts_assign(const char* name, const uint32_t res_id);

// Returns the font as specified by a resource ID.
// If the font has not been requested before, it will be loaded.
GFont fonts_get_font(const uint32_t res_id);

// Returns the font as specified by the name you assigned.
// If the font has not been requested before, it will be loaded.
GFont fonts_get_font_by_name(const char* name);

// Unload all the fonts from memory.
void fonts_cleanup(void);
