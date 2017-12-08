#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

int getch(void);
void ungetch(int);

int main(void) {

    ungetch('a');
    ungetch('b');
    putchar(getch());

    return 0;
}
