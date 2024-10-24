#include <stdio.h>
#define SIZE 5

int circularQueue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        circularQueue[rear] = value;
        printf("%d enqueued to circular queue\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
    } else {
        printf("%d dequeued from circular queue\n", circularQueue[front]);
        if (front == rear) {
            front = rear = -1; // Reset the queue when it becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Function to display the circular queue
void displayQueue() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements are:\n");
        int i = front;
        while (i != rear) {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d ", circularQueue[rear]);
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    displayQueue();
    dequeue();
    enqueue(6); 
    displayQueue();
    return 0;
}
