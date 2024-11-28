#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFromLeft(node **head, int data)
{
    node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void deleteNode(node **head, int data)
{
    node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp == *head)
            {
                *head = temp->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
                free(temp);
                return;
            }
            if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
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
    node *head = NULL;

    display(head);
    insertFromLeft(&head, 5);
    display(head);
    insertFromLeft(&head, 10);
    display(head);
    deleteNode(&head, 10);
    display(head);
    // insertFromLeft(&head, 15);
    // display(head);
    // insertFromLeft(&head, 5);
    // display(head);
    // deleteNode(&head, 5);
    // display(head);

    return 0;
}
