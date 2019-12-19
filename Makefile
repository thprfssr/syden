CC = gcc
flags = -w -lm -lSDL2 -lSDL2_image
objects = main.o window.o game.o screen.o
targets = Syden

all: $(targets)
	make $(targets)

Syden: $(objects)
	$(CC) $(flags) -o $@ $(objects)

main.o: game.h window.h
window.o: window.h
game.o: game.h window.h
screen.o: screen.h

.PHONY: clean
clean:
	rm $(targets) $(objects)
