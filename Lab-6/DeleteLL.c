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

void deleteAtFirst(node **head)
{
    node *temp = *head;
    if (temp != NULL)
    {
        *head = temp->next;
        free(temp);
        
    }
}

void deleteAtMid(node *head, int pos)
{
    if (head == NULL || pos < 0)
        return;
    node *temp = head;

    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL)
    {
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void deleteAtLast(node *head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        free(head);
        return;
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
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

int main()
{
    node *head = createNode(5);
    head->next = createNode(15);
    head->next->next = createNode(25);
    head->next->next->next = createNode(35);

    display(head);
    deleteAtFirst(&head);
    display(head);
    deleteAtMid(head, 2);
    display(head);
    deleteAtLast(head);
    display(head);

    return 0;
}
