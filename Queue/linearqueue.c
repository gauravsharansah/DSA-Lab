#include <stdio.h>
#define MAX 10

int front = -1;
int rear  = -1;
int queue[MAX];

int isFull();
int isEmpty();
void enQueue(int b);
void deQueue();

int main() {
    int i;
    for (i = 0; i < 11; i++) {
        enQueue(i);
    }

    for (i = 0; i < 11; i++) {
        deQueue();
    }

    return 0;
}

int isFull() {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return 1;
    }
    return 0;
}

void enQueue(int b) {
    if (isFull())
        return;
    if (front == -1)  
        front = 0;
    queue[++rear] = b;
    printf("%d inserted at position %d\n", b, rear);
}

void deQueue() {
    int b;
    if (isEmpty())
        return;
    b = queue[front++];
    printf("%d removed from queue\n", b);

    if (front > rear) {
        front = -1;
        rear  = -1;
    }
}
