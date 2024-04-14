build:
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 ./src/*.c -o Mazegame -lSDL2 -lm $(shell sdl2-config --cflags --libs)
run:
	./Mazegame
betty:
	betty ./src/*.c
export:
	 export XDG_RUNTIME_DIR=/run/user/$(id -u)
clean:
	rm Mazegame 

