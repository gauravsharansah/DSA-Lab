#include <stdio.h>
#define MAX 10

int front = 0;  
int rear  = -1; 
int queue[MAX];

void enQueue(int item);
void deQueue();

int main() {
    int i;

    for (i = 0; i < 11; i++)
        enQueue(i);

    for (i = 0; i < 11; i++)
        deQueue();
    
    enQueue(i); // Linear Queue Problem

    return 0; 
}

void enQueue(int item) {
    if (rear >= MAX - 1)                     
        printf("Queue Overflow\n");  

    else
    {
        rear = rear + 1;                    
        queue[rear] = item;                     
        printf("%d inserted at position %d\n", item, rear);
    }
}

void deQueue() {
    int item;
    if (rear < front)                     
        printf("Queue is Empty\n");           
    
    else 
    {
        item = queue[front++];                   
        printf("%d as deleted element\n", item);  
    }
}
