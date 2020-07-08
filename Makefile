CC = gcc
flags = -w -lm -lSDL2 -lSDL2_image -lSDL2_mixer
objects = main.o window.o game.o screen.o general.o tiles.o camera.o controls.o audio.o character.o vector.o
targets = Syden

all: $(targets)
	make $(targets)

Syden: $(objects)
	$(CC) $(flags) -o $@ $(objects)

main.o: game.h window.h
window.o: window.h
game.o: game.h window.h config.h screen.h controls.h audio.h character.h
screen.o: screen.h config.h tiles.h controls.h general.h camera.h character.h
general.o: general.h
tiles.o: tiles.h general.h config.h
camera.o: camera.h controls.h general.h vector.h
controls.o: controls.h vector.h
audio.o: audio.h
character.o: character.h general.h vector.h controls.h
vector.o: vector.h

.PHONY: clean
clean:
	rm $(targets) $(objects)
