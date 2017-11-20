#include <stdio.h>
#include "lines.h"
#include "qsort.h"


char *lineptr[MAXLINES];

int main(void) {
    int nlines;

    char s[MAXLINES][MAXLEN];
    for (int i = 0; i < MAXLINES; i++)
        *(lineptr + i) = s[i];

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return -1;
    }

}
