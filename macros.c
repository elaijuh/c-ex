#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define string(a, b) #a#b
#define concat(a, b) a ## b
#define ab 13

int main(void) {
	int a = 1, b = 2;
	printf("%d\n", max(a, b));
	printf("%s\n", string(a, b));
	printf("%d\n", concat(a, b));
}

