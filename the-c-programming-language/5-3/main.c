#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

void str_cat(char *, char *);
int getchars(char *s, int max);


int main(void) {

    char *s = (char *)malloc(MAXSIZE * sizeof(char));
    char *t = (char *)malloc(MAXSIZE * sizeof(char));

    printf("input string s: \n");
    while (getchars(s, MAXSIZE) == 0);
    printf("input string t: \n");
    while (getchars(t, MAXSIZE) == 0);

    str_cat(s, t);
    printf("cat: %s\n", s);
    free(s);
    free(t);
    return 0;

}

void str_cat(char *s, char *t) {
    while (*s++);
    s--;
    while((*s++ = *t++));
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
