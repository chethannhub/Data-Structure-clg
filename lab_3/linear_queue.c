#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == SIZE - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1; 
    }
}


void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    displayQueue();
    dequeue();
    displayQueue();
    enqueue(4);
    displayQueue();
    return 0;
}
