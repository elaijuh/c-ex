dirent.o: dirent.c
	gcc -std=c11 -Wall -c dirent.c -o dirent.o

main: clean main.c
	gcc -std=c11 -Wall -o main main.c

run: main
	./main

clean:
	@rm -f main dirent.o

