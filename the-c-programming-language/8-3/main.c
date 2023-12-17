// 2023-12-17
#include "stdio.h"

int main(int argc, char *argv[])
{
	FILE *fa, *fb;
	fa = fopen("a.txt", "r");
	fb = fopen("b.txt", "w");
	char c;
	while ((c = getc(fa)) != EOF)
		putc(c, fb);
	fflush(fb);

	fseek(fa, 0L, 0);
	fseek(fb, 2L, 0);
	while ((c = getc(fa)) != EOF)
		putc(c, fb);
	fflush(fb);

	fclose(fa);
	fclose(fb);

	return 0;
}
