# Syden

**SUMMARY**

This project is intended to be a rewrite of Cythen, my very bare basic game
engine. I'm doing this because I'm bored this December afternoon. We'll see how
far this rewrite goes.

**What's different?**

This time around, I want to rethink the way the program handles different
regions within the game, and the characters that are located within those
regions. I also want to have an easier way of modifying these regions, perhaps
by having them on PNG files, which are then translated by a script into a text
resource file that can be accessed by the main program. And finally, I want to
have better documentation.

**How to edit regions**

I've just recently discovered Tiled Map Editor, a program which allows one to
edit tile maps. I strongly recommend to use it in this project. When we're done
creating the region's tile map, we save it in Tiled's preferred file format so
that it may be edited later, but then we also export it into a CSV file. This
CSV file will simply be a table of numbers, which can then be fed into the main
program. It is the task of the main program to determine the dimensions of the
region and to draw it.
