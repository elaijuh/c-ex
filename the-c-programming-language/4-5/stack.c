#include <stdio.h>

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top(void) {
    if (sp > 0) 
        printf("\t%.8g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

double get_top(void) {
    if (sp > 0) 
        return val[sp-1];
    else
        printf("error: stack empty\n");
    return 0.0;
}

void swap(void) {
    double op1, op2;
    if (sp > 1)  {
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
    }
    else 
        printf("error: stack has less than 2 elements\n");
}

void clean(void) {
    sp = 0;
}



