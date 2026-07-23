#include <stdio.h>
int linearSearch(int a[], int n, int key);

int main() {
    int i, a[50], n, key, pos;
    printf("Enter the size of array:- ");
    scanf("%d", &n);
    printf("Enter the elements of array:-\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the element to search:- ");
    scanf("%d", &key);

    pos = linearSearch(a, n, key);
    if(pos == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d\n", pos+1);

    return 0;
}

int linearSearch(int a[], int n, int key){
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}
