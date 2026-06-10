#include <stdio.h>

int main() {
    char expr[100];
    int stack = 0;

    printf("Enter expression: ");
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            stack++;
        }
        else if (expr[i] == ')') {
            if (stack == 0) {
                printf("Not Balanced\n");
                return 0;
            }
            stack--;
        }
    }

    if (stack == 0)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
