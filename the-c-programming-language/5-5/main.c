#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

char *strncpy(char *, char *, int);
char *strncat(char *, char *, int);
int strncmp(char *, char *, int);
int getchars(char *s, int max);

int main(void) {

    char *s = (char *)malloc(MAXSIZE * sizeof(char));
    char *t = (char *)malloc(MAXSIZE * sizeof(char));
    int n;

    /* printf("input string t: \n"); */
    /* while (getchars(t, MAXSIZE) == 0); */
    /* printf("input n: \n"); */
    /* scanf("%d", &n); */
    /* printf("strncpy(s, t, n) returns %s\n", strncpy(s, t, n)); */

    /* printf("input string s: \n"); */
    /* while (getchars(s, MAXSIZE) == 0); */
    /* printf("input string t: \n"); */
    /* while (getchars(t, MAXSIZE) == 0); */
    /* printf("input n: \n"); */
    /* scanf("%d", &n); */
    /* printf("strncat(s, t, n) returns %s\n", strncat(s, t, n)); */

    printf("input string s: \n");
    while (getchars(s, MAXSIZE) == 0);
    printf("input string t: \n");
    while (getchars(t, MAXSIZE) == 0);
    printf("input n: \n");
    scanf("%d", &n);
    printf("strncmp(s, t, n) returns %d\n", strncmp(s, t, n));

    free(s);
    free(t);
    return 0;
}


char *strncpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n && (*(s + i++) = *t++));
    return s;
}


char *strncat(char *s, char *t, int n) {
    int ls = 0, lt = 0;
    while (*(s + ls++));
    ls--;
    while (lt < n && (*(s + ls + lt++) = *t++));  
    if (lt == n) *(s + ls + lt) = '\0';
    return s;
}

int strncmp(char *s, char *t, int n) {
    for (int i = 0; i < n; i++) {
        if (*(s + i) && *(t + i) && *(s + i) == *(t + i)) continue;
        else if (*(s + i) < *(t + i)) return -1;
        else return 1; 
    }
    return 0;
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
