#include <stdio.h>
#include <ctype.h>

#define SIZE 5

int getch(void);
void ungetch(int);

int main(void) {
    double getfloat(double *);
    int n, r;
    double array[SIZE];
    for (n = 0; n < SIZE && (r = getfloat(&array[n])) != EOF; n++) {
        if (r) 
            printf("you input %f\n", array[n]);
        else
            printf("not a number, array[%d] is %f\n", n, array[n]);
    }
    return 0;
}

double getfloat(double *pn) {
    int c, sign, fraction = 0;
    *pn = 0;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c) || c == '.'; c = getch()) 
        if (isdigit(c)) {
            *pn = 10 * *pn + (c - '0');
            fraction *= 10;
        }
        else
            fraction = 1;

    *pn *= sign;
    *pn /= fraction;
    if (c != EOF)
        ungetch(c);
    return c;
}

