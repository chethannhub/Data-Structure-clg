#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push() {
    int val;
    if(top == SIZE - 1) {
        printf("Stack Overflow! Stack is full.\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        stack[++top] = val;  
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    } else {
        printf("%d is removed\n", stack[top]);
        return stack[top--]; 
    }
}

void display() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);  
        }
    }
}

int main() {
    int choice;

    printf("Let's create a stack\n");
    while (1) {
        printf("\n1. Push \n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("INVALID INPUT!\n");
        }
    }

    return 0;  
}
