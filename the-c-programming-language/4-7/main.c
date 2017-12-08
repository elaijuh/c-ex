#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

int getch(void);
void ungets(char []);

int main(void) {

    ungets("hello world");
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());
    putchar(getch());

    return 0;
}
