all:
	gcc -Wall src/main.c src/point.c src/bounds.c -o bin/main -g -O0
