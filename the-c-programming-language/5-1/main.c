#include <stdio.h>
#include <ctype.h>

#define SIZE 5

int getch(void);
void ungetch(int);

int main(void) {
    int getint(int *);
    int n, r, array[SIZE];
    for (n = 0; n < SIZE && (r = getint(&array[n])) != EOF; n++) {
        if (r) 
            printf("you input %d\n", array[n]);
        else
            printf("not a number, array[%d] is %d\n", n, array[n]);
    }
    return 0;
}

int getint(int *pn) {
    int c, sign, c2;
    *pn = 0;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        if (!isdigit(c2 = getch())) {
            ungetch(c2);
            ungetch(c);
            return 0;
        } else
            c = c2;
    }
    for (*pn = 0; isdigit(c); c = getch()) 
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

