#include <stdio.h>
void bubbleSort(int a[], int n);
int binarySearch(int a[], int n, int key);

int main() {
    int i, a[50], n, key, pos;
    printf("Enter the size of array:- ");
    scanf("%d", &n);
    printf("Enter the elements of array:-\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubbleSort(a, n);

    printf("Enter the element to search:- ");
    scanf("%d", &key);

    pos = binarySearch(a, n, key);
    if(pos == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d\n", pos+1);

    return 0;
}

void bubbleSort(int a[], int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int key){
    int low = 0, high = n-1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
