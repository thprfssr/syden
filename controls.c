#include <stdbool.h>
#include <SDL2/SDL.h>

#include "controls.h"

/* This function accepts an integer, and updates the global variable
 * `CONTROLLER_STATUS` accordingly. */
void button_pressed(int button)
{
	CONTROLLER_STATUS |= button;
}

/* This function is analogous to `button_pressed()`. */
void button_released(int button)
{
	CONTROLLER_STATUS &= ~button;
}

bool is_buton_pressed(int button)
{
	return CONTROLLER_STATUS & button;
}
