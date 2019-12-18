CC = gcc
flags = -w -lm -lSDL2 -lSDL2_image
objects = main.o window.o game.o
targets = Cythen

all: $(targets)
	make $(targets)

Cythen: $(objects)
	$(CC) $(flags) -o $@ $(objects)

main.o:
window.o:
game.o:

.PHONY: clean
clean:
	rm $(targets) $(objects)
