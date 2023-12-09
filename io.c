#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
	register int c;
	char s[MAXLINE];

	// getchar read  a char from stdin
	// putchar write a char to stdout
	printf("demo: getchar, putchar\n");
	while ((c = getchar()) != EOF) {
		if (c != '\n')
			putchar(c);
		else {
			putchar('\n');
			break;
		}
	}

	// fgetc read a char from STREAM
	// fputc write a char to STREAM
	printf("demo: fgetc, fputc\n");
	while ((c = fgetc(stdin)) != EOF) {
		if (c != '\n')
			fputc(c, stdout);
		else {
			fputc('\n', stdout);
			break;
		}
	}

	// getc read a char from STREAM, same as fgetc except that it might be implemented as a macro
	// putc write a char to STREAM, same as fputc except that it might be implemented as macro
	printf("demo: getc, putc\n");
	while ((c = getc(stdin)) != EOF) {
		if (c != '\n')
			putc(c, stdout);
		else {
			putc('\n', stdout);
			break;
		}
	}

	// gets read from stdin, puts write to stdout
	// gets removed in C11
	printf("demo: gets, puts\n");
	gets(s);
	puts(s);

	// fgets read from FILE, fputs write to FILE
	// fgets is implemented by getc
	printf("demo: fgets, fputs\n");
	fgets(s, 10, stdin);
	fputs(s, stdout);

	return 0;
}
