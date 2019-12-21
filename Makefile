CC = gcc
flags = -w -lm -lSDL2 -lSDL2_image
objects = main.o window.o game.o screen.o general.o tiles.o camera.o controls.o
targets = Syden

all: $(targets)
	make $(targets)

Syden: $(objects)
	$(CC) $(flags) -o $@ $(objects)

main.o: game.h window.h
window.o: window.h
game.o: game.h window.h config.h screen.h controls.h
screen.o: screen.h config.h tiles.h controls.h general.h camera.h
general.o: general.h
tiles.o: tiles.h general.h config.h
camera.o: camera.h
controls.o: controls.h

.PHONY: clean
clean:
	rm $(targets) $(objects)
