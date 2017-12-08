#include <stdio.h>
#include <string.h>

#define BUFSIZE 1
static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        buf[bufp - 1] = c;
    else
        buf[bufp++] = c;
}
