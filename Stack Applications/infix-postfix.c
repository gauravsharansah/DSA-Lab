#include <stdio.h>
#include <string.h>

void postfix(char a[50]);
void push(char a[50], char b);
void pop(char a[50]);
char peek(char a[50]);
int precedence(char op);

char stack[50] = ""; 

int main() {
    char str[50];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]", str);
    printf("The equivalent postfix expression is:\n");
    postfix(str);
    return 0;
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void postfix(char a[50]) {
    char b[50], temp;
    int i, len = 0;

    for (i = 0; a[i] != '\0'; i++)  
    {
        if (a[i] == '(')
        {
            push(stack, '(');
        }
        else if (a[i] == ')')
        {
            temp = peek(stack);
            while (temp != '(' && temp != '\0') {
                b[len++] = temp;
                pop(stack);
                temp = peek(stack);
            }
            pop(stack); 
        }
        else if (a[i] == '+' || a[i] == '-' ||
                 a[i] == '*' || a[i] == '/' || a[i] == '^')
        {
            temp = peek(stack);
            while (stack[0] != '\0' && temp != '(' &&
                   precedence(temp) >= precedence(a[i]))
            {
                b[len++] = temp;
                pop(stack);
                temp = peek(stack);
            }
            push(stack, a[i]);
        }
        else 
        {
            b[len++] = a[i];
        }
    }

    while (stack[0] != '\0') {
        b[len++] = peek(stack);
        pop(stack);
    }

    b[len] = '\0';
    printf("%s\n", b);
}

void pop(char a[50]) {
    int top = -1, i = 0;
    while (a[i] != '\0') { top++; i++; }
    if (top != -1)
        a[top] = '\0';
}

void push(char a[50], char b) {
    int top = -1, i = 0;
    while (a[i] != '\0') { top++; i++; }
    a[top + 1] = b;
    a[top + 2] = '\0';
}

char peek(char a[50]) {
    int top = -1, i = 0;
    while (a[i] != '\0') { top++; i++; }
    if (top == -1) return '\0'; 
    return a[top];
}