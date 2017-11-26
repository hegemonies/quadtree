all:
	gcc -Wall src/main.c src/point.c src/bounds.c src/node.c -o bin/main -g -O0
	bin/main
