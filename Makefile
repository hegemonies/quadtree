all:
	mkdir bin -p
	gcc -std=c99 -Werror -Wall src/main.c src/point.c src/bounds.c src/node.c src/quadtree.c -o bin/main -g -O0
	bin/main
