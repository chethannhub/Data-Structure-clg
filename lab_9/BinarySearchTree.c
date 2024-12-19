#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

node* create(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data; 
    newNode->left = NULL;  
    newNode->right = NULL; 
    return newNode;
}

void insert(int data, node** head) {
    if (*head == NULL) {
        *head = create(data);
        return;
    }

    if (data < (*head)->data) {
        insert(data, &(*head)->left);
    } else {
        insert(data, &(*head)->right);
    }
}

void inOrder(node* head) {
    if(head != NULL) {
        inOrder(head->left);
        printf("%d -> ", head->data);
        inOrder(head->right);
    }
}

void preOrder(node* head) {
    if(head != NULL) {
        printf("%d -> ", head->data);
        preOrder(head->left);
        preOrder(head->right);
    }
}

void postOrder(node* head) {
    if(head != NULL) {
        postOrder(head->left);
        postOrder(head->right);
        printf("%d -> ", head->data);
    }
}

void display(node* head) {
    if (head != NULL) {
        display(head->left);
        printf("%d -> ", head->data);
        display(head->right);
    }
}

int main() {
    node* root = NULL;  

    insert(50, &root);
    insert(30, &root);
    insert(70, &root);
    insert(20, &root);
    insert(40, &root);


    printf("In-order: ");
    inOrder(root);
    printf("NULL\n");

    printf("preOrder: ");
    preOrder(root);
    printf("NULL\n");

    printf("PostOrder: ");
    postOrder(root);
    printf("NULL\n");

    return 0;
}
