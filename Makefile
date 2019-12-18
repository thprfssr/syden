CC = gcc
flags = -w -lm -lSDL2 -lSDL2_image
objects = main.o window.o game.o
targets = Syden

all: $(targets)
	make $(targets)

Syden: $(objects)
	$(CC) $(flags) -o $@ $(objects)

main.o:
window.o:
game.o:

.PHONY: clean
clean:
	rm $(targets) $(objects)
