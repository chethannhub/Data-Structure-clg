#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void swapData(node *a, node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sortList(node **head) {
    if(*head == NULL || (*head)->next == NULL) {
        return;
    }

    node *currNode;
    node *lastNode = NULL;
    int swapped;

    do {
        swapped = 0;
        currNode = *head;
        while(currNode->next != lastNode) {
            if(currNode->data > currNode->next->data) {
                swapData(currNode, currNode->next);
                swapped = 1;
            }
            currNode = currNode->next;
        }
        lastNode = currNode;
    } while(swapped);
}

void reverseList(node **head) {
    if(*head == NULL || (*head)->next == NULL) {
        return;
    }

    node *curr = *head;
    node *prev = NULL;
    node *ptr = NULL;

    while(curr != NULL) {
        ptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = ptr;
    }
    *head = prev;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
        {
            printf(" -> ");
        }
        head = head->next;
    }
    printf(" -> NULL\n");
}

void concatListsAtBeginning(node **head1, node *head2) {
    if (head1 == NULL || head2 == NULL) {
        return;
    }

    node *temp = *head1;
    *head1 = head2;
    
    node *current = *head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

int main()
{
    node *head1 = createNode(5);
    head1->next = createNode(25);

    node *head2 = createNode(10);
    head2->next = createNode(20);

    printf("List 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);

    concatListsAtBeginning(&head1, head2);

    printf("\nConcatenated List (List 2 at beginning of List 1): ");
    display(head1);

    sortList(&head1);
    printf("\nSorted Concatenated List: ");
    display(head1);

    reverseList(&head1);
    printf("\nReversed Concatenated List: ");
    display(head1);

    return 0;
}
