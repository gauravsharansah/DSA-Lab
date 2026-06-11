#include <stdio.h>
int non_tailed(int a);
int tailed(int a, int b);
int main() {
    int num1,num2,fact1=1,fact2;
    printf("Enter any two integer numbers: ");
    scanf("%d %d",&num1, &num2);
    fact1=tailed(num1,fact1);
    fact2=non_tailed(num2);
    printf("\nThe factorial of %d is %d",num1, fact1);
    printf("\nThe factorial of %d is %d",num2, fact2);
    return 0;
}
int non_tailed(int a){
    if (a==1 || a==0)
        return 1;
    else 
        return a*non_tailed(a-1);
}
int tailed(int a,int b){
    if (a==1 || a==0)
        return b;
    else 
        return tailed(a-1,a*b);
}
