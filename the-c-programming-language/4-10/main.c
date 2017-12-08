#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

#define MAXOP 100
#define MAXLINE 1000

int lp;

int main(void) {
    int type;
    double op2;
    char l[MAXLINE];
    char s[MAXOP];

    int v;
    double vars[26];
    double last;


    while (get_line(l, MAXLINE) > 1) {
        lp = 0;

        while ((type = getop(s, l)) != '\0') {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case OPERATOR:
                    if (strcmp(s, "sin") == 0)
                        push(sin(pop()));
                    else if (strcmp(s, "exp") == 0)
                        push(exp(pop()));
                    else if (strcmp(s, "pow") == 0) {
                        op2 = pop();
                        push(pow(pop(), op2));
                    }
                    else
                        printf("error: unknow command %s\n", s);
                    break;
                case VARIABLE:
                    v = tolower(s[0]);
                    last = vars[v - 'a'] = get_top();
                    printf("%c = %.8g\n", v, vars[v - 'a']);
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0) 
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    op2 = pop();
                    if (op2 != 0.0) 
                        push(fmod(pop(), op2));
                    else
                        printf("error: zero divisor\n");
                    break;
                case '\n':
                    print_top();
                    clean();
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }

    return 0;
}
