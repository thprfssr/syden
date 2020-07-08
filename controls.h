#ifndef CONTROLS_H
#define CONTROLS_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "vector.h"


#define BUTTON_UP	(1 << 0)
#define BUTTON_DOWN	(1 << 1)
#define BUTTON_LEFT	(1 << 2)
#define BUTTON_RIGHT	(1 << 3)
#define BUTTON_START	(1 << 4)
#define BUTTON_SELECT	(1 << 5)
#define BUTTON_A	(1 << 6)
#define BUTTON_B	(1 << 7)
#define BUTTON_X	(1 << 8)
#define BUTTON_Y	(1 << 9)
#define BUTTON_L	(1 << 10)
#define BUTTON_R	(1 << 11)

extern int CONTROLLER_STATUS;
extern int PREVIOUS_CONTROLLER_STATUS;

void button_pressed(int button);
void button_released(int button);
bool is_button_pressed(int button);
bool controller_status_changed();
void handle_input(SDL_KeyboardEvent event);
bool multiple_directional_buttons_pressed();
struct Vector generate_vector();

#endif
