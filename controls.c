#include <stdbool.h>
#include <SDL2/SDL.h>

#include "controls.h"
#include "vector.h"

int CONTROLLER_STATUS = 0;
int PREVIOUS_CONTROLLER_STATUS = 0;

static bool CONTROLLER_STATUS_CHANGED = false;

/* This function accepts an integer, and updates the global variable
 * `CONTROLLER_STATUS` accordingly. */
void button_pressed(int button)
{
	PREVIOUS_CONTROLLER_STATUS = CONTROLLER_STATUS;
	CONTROLLER_STATUS |= button;
}

/* This function is analogous to `button_pressed()`. */
void button_released(int button)
{
	PREVIOUS_CONTROLLER_STATUS = CONTROLLER_STATUS;
	CONTROLLER_STATUS &= ~button;
}

bool is_button_pressed(int button)
{
	return CONTROLLER_STATUS & button;
}

/* This function returns true if the controller status changed. */
bool controller_status_changed()
{
	if (CONTROLLER_STATUS_CHANGED == false) {
		CONTROLLER_STATUS_CHANGED =
			(PREVIOUS_CONTROLLER_STATUS != CONTROLLER_STATUS);
	} else {
		CONTROLLER_STATUS_CHANGED = false;
		PREVIOUS_CONTROLLER_STATUS = CONTROLLER_STATUS;
	}
	return CONTROLLER_STATUS_CHANGED;
}

/* Determine if multiple directional buttons are pressed. */
bool multiple_directional_buttons_pressed()
{
	int u = (int) is_button_pressed(BUTTON_UP);
	int d = (int) is_button_pressed(BUTTON_DOWN);
	int l = (int) is_button_pressed(BUTTON_LEFT);
	int r = (int) is_button_pressed(BUTTON_RIGHT);

	int tmp[4] = {u, d, l, r};
	int s = 0;
	for (int i = 0; i < 4; i++) {
		if (tmp[i] != 0)
			s += tmp[i] / tmp[i];
	}

	return (s > 1);
}

/* This function generates a vector based on which directional buttons are
 * pressed. */
struct Vector generate_vector()
{
	struct Vector v = ZERO;
	if (is_button_pressed(BUTTON_UP))
		v = add(v, VEC_N);
	if (is_button_pressed(BUTTON_DOWN))
		v = add(v, VEC_S);
	if (is_button_pressed(BUTTON_LEFT))
		v = add(v, VEC_W);
	if (is_button_pressed(BUTTON_RIGHT))
		v = add(v, VEC_E);

	v = normalize(v);
	if (multiple_directional_buttons_pressed())
		v = scale(v, 1 / sqrt(2));

	return v;
}

void handle_input(SDL_KeyboardEvent event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.keysym.scancode)
		{
			case SDL_SCANCODE_W:
				button_pressed(BUTTON_UP);
				break;
			case SDL_SCANCODE_S:
				button_pressed(BUTTON_DOWN);
				break;
			case SDL_SCANCODE_A:
				button_pressed(BUTTON_LEFT);
				break;
			case SDL_SCANCODE_D:
				button_pressed(BUTTON_RIGHT);
				break;
			case SDL_SCANCODE_B:
				button_pressed(BUTTON_START);
				break;
			case SDL_SCANCODE_V:
				button_pressed(BUTTON_SELECT);
				break;
			case SDL_SCANCODE_L:
				button_pressed(BUTTON_A);
				break;
			case SDL_SCANCODE_K:
				button_pressed(BUTTON_B);
				break;
			case SDL_SCANCODE_I:
				button_pressed(BUTTON_X);
				break;
			case SDL_SCANCODE_J:
				button_pressed(BUTTON_Y);
				break;
			case SDL_SCANCODE_E:
				button_pressed(BUTTON_L);
				break;
			case SDL_SCANCODE_U:
				button_pressed(BUTTON_R);
				break;
			default:
				break;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.keysym.scancode)
		{
			case SDL_SCANCODE_W:
				button_released(BUTTON_UP);
				break;
			case SDL_SCANCODE_S:
				button_released(BUTTON_DOWN);
				break;
			case SDL_SCANCODE_A:
				button_released(BUTTON_LEFT);
				break;
			case SDL_SCANCODE_D:
				button_released(BUTTON_RIGHT);
				break;
			case SDL_SCANCODE_B:
				button_released(BUTTON_START);
				break;
			case SDL_SCANCODE_V:
				button_released(BUTTON_SELECT);
				break;
			case SDL_SCANCODE_L:
				button_released(BUTTON_A);
				break;
			case SDL_SCANCODE_K:
				button_released(BUTTON_B);
				break;
			case SDL_SCANCODE_I:
				button_released(BUTTON_X);
				break;
			case SDL_SCANCODE_J:
				button_released(BUTTON_Y);
				break;
			case SDL_SCANCODE_E:
				button_released(BUTTON_L);
				break;
			case SDL_SCANCODE_U:
				button_released(BUTTON_R);
				break;
			default:
				break;
		}
	}
}
