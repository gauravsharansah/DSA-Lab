#include<stdio.h>
void move(int n,char s, char a, char d);
int main()
{
    int rings;
    printf("Enter no of rings in source: ");
    scanf("%d",&rings);
    move(rings,'A','B','C');
    return 0;
}
void move(int n,char s, char a, char d)
{
    if(n==1)
    {
        printf("\nMove Disk1 from rod %c to rod %c",s,d);
        return;
    }
    if(n==0)
        return;
    move(n-1,s,d,a);
    printf("\nMove Disk%d from rod %c to rod %c",n,s,d);
    move(n-1,a,s,d);
}
