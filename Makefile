all: clear bin/main makedir run

clear:
	rm bin/main

makedir:
	mkdir bin -p

bin/main:
	gcc -Werror -Wall src/main.c src/point.c src/bounds.c src/node.c src/quadtree.c -o bin/main -g -O0

run: bin/main
	bin/main
