# Syden

## About the Project

This project is my best attempt at writing the very bare basics of a game
engine. This is third iteration of the original code, which came about when my
best friend and I decided that we wanted to make a videogame back in
high school.

The current demo features Link in a custom-made map. You can move around the
map using the WASD keys.

## Getting Started

### Prerequisites

* ```SDL2```
* ```SDL2_image```
* ```SDL2_mixer```
* ```SDL2_ttf```

### Compiling

1. Install the ```SDL2``` libraries specified above.
2. Clone the repo:
	```git clone https://github.com/thprfssr/syden.git```
3. Change to the project directory:
	```cd syden```
4. Build the project:
	```make```

## Usage

Simply run the newly created executable to play around with the demo:
	```./Syden```

### Editing the Tile Map

Under the ```resources``` directory you will find the following files:
* ```resources/tile_atlas.tsx```
* ```resources/test_map.tmx```
These files can be edited with the [Tiled](https://www.mapeditor.org/) editor.
After you do all the editing you want, you need to export ```tile_atlas.tsx```
as a CSV file ```tile_atlas.csv```.

### Editing the Sprites

The sprite files are contained under the ```resources``` directory:
* ```resources/link_idle_east.png```
* ```resources/link_idle_north.png```
* ```resources/link_idle_south.png```
* ```resources/link_idle_west.png```
* ```resources/link_walking_east.png```
* ```resources/link_walking_north.png```
* ```resources/link_walking_south.png```
* ```resources/link_walking_west.png```
You can edit these files using the [Aseprite](https://www.aseprite.org/)
editor.

## To Do

* Add collision detection.
* Enable _A Link to the Past_ style transitions to adjacent regions.
* Make the camera movement feel more natural.
* Improve sprite animations.
* Obtain free/original sprite and tile art.
* Work on a pause menu.

## License

This project is distributed under the MIT License. See the ```LICENSE``` file
for more information.

## Contact

Javier Castro - [@thprfssr](https://twitter.com/thprfssr) - <jc@javiercastro.xyz>
Project Link: [https://github.com/thprfssr/syden.git]
