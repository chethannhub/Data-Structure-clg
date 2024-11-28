#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtMid(node** head, int data, int pos) {
    node* newNode = createNode(data);
    node* temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position %d is out of range\n", pos);
        free(newNode);
    }
}

void insertAtLast(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;

    insertAtFirst(&head, 57);
    insertAtFirst(&head, 55);
    insertAtMid(&head, 56, 2);
    insertAtLast(&head, 58);

    display(head);
    return 0;
}
