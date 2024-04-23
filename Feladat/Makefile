all:
	gcc -Iinclude/ src/window.c src/main.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lopengl32 -lm -o game.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/window.c src/main.c -lobj -lSDL2 -lSDL2_image -lGL -lm -o game -Wall -Wextra -Wpedantic