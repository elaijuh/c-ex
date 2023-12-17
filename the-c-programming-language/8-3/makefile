stdio.o: stdio.c
	gcc -std=c11 -Wall -c stdio.c -o stdio.o

main: stdio.o
	gcc -std=c11 -Wall -o main main.c stdio.o

run: main
	./main

clean:
	@rm -f main stdio.o b.txt

