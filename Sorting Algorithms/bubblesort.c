#include <stdio.h>
void bubbleSort(int a[],int n);
int main() {
    int i,a[50],n;
    printf("Enter the size of array:- ");
    scanf("%d",&n);
    printf("Enter the elements of array:-\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubbleSort(a,n);
    printf("The sorted array is:-\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
void bubbleSort(int a[],int n){
    int i,j,temp,flag=0;
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<(n-1-i);j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}
