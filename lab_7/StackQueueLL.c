#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Node** top, int data) {
    struct Node* node = newNode(data);
    node->next = *top;
    *top = node;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* node = newNode(data);
    if (*rear == NULL) {
        *front = *rear = node;
        return;
    }
    (*rear)->next = node;
    *rear = node;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        return -1;
    }
    struct Node* temp = *front;
    int dequeued = temp->data;
    *front = temp->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeued;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;

    printf("Stack Operations:\n");
    push(&stack, 10);
    push(&stack, 20);
    printf("Popped from Stack: %d\n", pop(&stack));
    push(&stack, 40);
    printf("Popped from Stack: %d\n", pop(&stack));
    printList(stack);

    printf("\nQueue Operations:\n");
    enqueue(&queueFront, &queueRear, 100);
    enqueue(&queueFront, &queueRear, 200);
    printf("Dequeued from Queue: %d\n", dequeue(&queueFront, &queueRear));
    enqueue(&queueFront, &queueRear, 400);
    printf("Dequeued from Queue: %d\n", dequeue(&queueFront, &queueRear));
    printList(queueFront);

    return 0;
}
