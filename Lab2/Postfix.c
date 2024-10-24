#include<stdio.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int is_operator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int precedence(char symbol) {
    if (symbol == '+' || symbol == '-') 
        return 1;
    if (symbol == '*' || symbol == '/')
        return 2;
    return 0;
}

void convert_to_postfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char current, tmp;

    while ((current = infix[i++]) != '\0') {
        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(current);
        } else if (current == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (is_operator(current)) {
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
