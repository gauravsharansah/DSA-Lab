#include <stdio.h>
#define MAX 5

int front = -1;
int rear  = -1;
int queue[MAX];

int isFull();
int isEmpty();
void enQueue(int b);
void deQueue();
void display();

int main() {
    int i;
    for (i = 0; i < 6; i++) {
        enQueue((i+1)*10);
    }
    display();

    deQueue();
    deQueue();

    display();
    
    enQueue(60);
    enQueue(70);

    display();
    return 0;
}

int isFull() {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full\n");
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
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
    rear = (rear + 1) % MAX;
    queue[rear] = b;
    printf("%d inserted at position %d\n", b, rear);
}

void deQueue() {
    int b;
    if (isEmpty())
        return;
    b = queue[front];
    printf("%d removed from queue\n", b);

    if (front == rear) {
        front = -1;
        rear  = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;
    if (isEmpty())
        return;
    printf("Queue: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}