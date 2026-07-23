#include <stdio.h>
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int i, a[50], n;
    printf("Enter the size of array:- ");
    scanf("%d", &n);
    printf("Enter the elements of array:-\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a, 0, n-1);
    printf("The sorted array is:-\t");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}

void quickSort(int a[], int low, int high){
    if(low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    int j, temp;
    for(j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return i+1;
}
