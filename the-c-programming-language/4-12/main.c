#include <stdio.h>
#include <string.h>

void itoa(char [], int);

int main(void) {
    char s[100] = "";
    int n = 123456;
    itoa(s, n);
    printf("%s\n", s); 
}


void itoa(char s[], int n) {
    static int l = 0;
    if (n / 10 != 0) {
        itoa(s, n / 10);
        s[l++] = n % 10 + '0';
    } else
        s[l++] =  n + '0';
}
