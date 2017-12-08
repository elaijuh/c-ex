#include <stdio.h>
#include <ctype.h>
#include "calc.h"


extern int lp;

int getop(char s[], char l[]) {
    int i, c;
    while ((s[0] = c = l[lp++]) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = l[lp++]));
        s[i] = '\0';
        if (c != '\0') 
            lp--;
        return OPERATOR;
    }

    if ((c == '-' || c == '+') && !isdigit(s[++i] = c =l[lp++])) {
        s[i] = '\0';
        if (c != '\0')
            lp--;
        return s[0];
    }

    if (c == '=') {
        while ((c = l[lp++]) == ' ' || c == '\t');
        if (isalpha(c)) {
            s[0] = c;
            return VARIABLE;
        }
        if (c != '\0')
            lp--;
        return c;
    }


    if (!isdigit(c) && c != '.')
        return c; // not a number

    if (isdigit(c)) // get integer part
        while (isdigit(s[++i] = c = l[lp++]));
    if (c == '.') // get fraction part
        while (isdigit(s[++i] = c = l[lp++]));
    s[i] = '\0';
    if (c != '\0')
        lp--;
    return NUMBER;

}
