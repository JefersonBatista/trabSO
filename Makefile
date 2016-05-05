all: main

main: main.c
	gcc -Wall -o nsh main.c

clean:
	rm nsh
	
	
