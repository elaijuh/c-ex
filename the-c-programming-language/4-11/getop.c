#include <stdio.h>
#include <ctype.h>
#include "calc.h"


int getop(char s[]) {
    static int bufc = 0;
    int i, c;

    if (bufc != 0 && bufc != ' ' && bufc != '\t') {
        s[0] = c = bufc;
        bufc = 0;
    }
    else
        while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF)
            bufc = c;
        return OPERATOR;
    }

    if ((c == '-' || c == '+') && !isdigit(s[++i] = c = getch())) {
        s[i] = '\0';
        if (c != EOF)
            bufc = c;
        return s[0];
    }

    if (c == '=') {
        while ((c = getch()) == ' ' || c == '\t');
        if (isalpha(c)) {
            s[0] = c;
            return VARIABLE;
        }
        if (c != EOF)
            bufc = c;
        return c;
    }


    if (!isdigit(c) && c != '.')
        return c; // not a number

    if (isdigit(c)) // get integer part
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') // get fraction part
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        bufc = c;
    return NUMBER;

}
