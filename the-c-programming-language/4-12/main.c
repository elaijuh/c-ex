#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(char [], int);

int main(void) {
    char s[MAXLINE];
    int n;

    n = 1;
    itoa(s, n);
    printf("%d is converted to %s\n", n, s); 

    n = 123456;
    itoa(s, n);
    printf("%d is converted to %s\n", n, s); 

    n = -1234;
    itoa(s, n);
    printf("%d is converted to %s\n", n, s); 
}



void itoa(char s[], int n) {
    s[0] = '\0';
    int l;
    if (n / 10 != 0) {
        itoa(s, n / 10);
        l = strlen(s);
        s[l] = n > 0 ? (n % 10 + '0') : (-n % 10 + '0');
        s[l+1] = '\0';
    } else {
        if (n < 0) {
            s[0] = '-';
            s[1] = -n + '0';
            s[2] = '\0';
        } else {
            s[0] = n + '0';
            s[1] = '\0';
        }
    }
}

