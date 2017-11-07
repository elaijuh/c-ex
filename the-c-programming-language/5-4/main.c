#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

int strend(char *, char *);
int getchars(char *s, int max);

int main(void) {

    char *s = (char *)malloc(MAXSIZE * sizeof(char));
    char *t = (char *)malloc(MAXSIZE * sizeof(char));

    printf("input string s: \n");
    while (getchars(s, MAXSIZE) == 0);
    printf("input string t: \n");
    while (getchars(t, MAXSIZE) == 0);

    printf("strend returns %d\n", strend(s, t));

    free(s);
    free(t);
    return 0;
}

int strend(char *s, char *t) {
    int ls = 0, lt = 0;
    while (*s) {
        ls++;
        s++;
    }
    while (*t) {
        lt++;
        t++;
    }
    while (ls-- && lt-- && (*--s == *--t));
    if (lt > 0 ) return 0;
    return 1;
}


int getchars(char *s, int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1) {
            *s++ = c;
            ++l;
        }
    *s = '\0';

    return l;
}
