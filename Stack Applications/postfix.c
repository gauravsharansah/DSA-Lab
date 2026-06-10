#include <stdio.h>
#include <string.h>
#include <math.h>

/* ── float stack (replaces the broken char stack) ── */
float operandStack[50];
int stackTop = -1;

void eval(char a[50]);
void push(float val);
float pop(void);
float peek(void);

int main() {
    char str[50];
    printf("Enter a postfix mathematical expression: ");
    scanf("%49[^\n]", str);
    printf("The result is:\n");
    eval(str);
    return 0;
}

void eval(char a[50]) {
    float num1, num2, result;
    int i;

    for (i = 0; a[i] != '\0'; i++) {
        /* skip spaces between tokens */
        if (a[i] == ' ')
            continue;

        if (a[i] == '+' || a[i] == '-' ||
            a[i] == '*' || a[i] == '/' || a[i] == '^') {

            num2 = pop();   /* right operand is on top */
            num1 = pop();   /* left  operand is below  */

            if      (a[i] == '+') result = num1 + num2;
            else if (a[i] == '-') result = num1 - num2;
            else if (a[i] == '*') result = num1 * num2;
            else if (a[i] == '/') result = num1 / num2;
            else                  result = (float)pow(num1, num2);

            push(result);

        } else if (a[i] >= '0' && a[i] <= '9') {
            push((float)(a[i] - '0'));   /* single-digit operand */
        }
        /* non-digit, non-operator characters are ignored */
    }

    printf("%f\n", pop());
}

void push(float val) {
    if (stackTop < 49)
        operandStack[++stackTop] = val;
}

float pop(void) {
    if (stackTop == -1) return 0;
    return operandStack[stackTop--];
}

float peek(void) {
    if (stackTop == -1) return 0;
    return operandStack[stackTop];
}