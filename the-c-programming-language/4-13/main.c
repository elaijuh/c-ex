#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getchars(char [], int);
void reverse(char [], int);

int main(void) {
    char s[MAXLINE];

    while (getchars(s, MAXLINE)) {
        reverse(s, 0);
        printf("%s\n", s); 
    }

    return 0;
}

void reverse(char s[], int i) {
    int temp;
    int l = strlen(s);
    if (i < l / 2) {
        temp = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = temp;
        reverse(s, i + 1);
    }
}

int getchars(char s[], int max) {
    int c, i = 0;

    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}
