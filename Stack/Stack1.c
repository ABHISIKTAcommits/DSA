// Stack using array in C [Day: 36]
#include <stdio.h>
#include <stdlib.h>
#define max 6

int stack[max];
int top = -1;

void push() {
    if (top == max - 1) {
        printf("Overflow\n");
        return;
    }
    top++;
    printf("Enter the element to be inserted: ");
    scanf("%d", &stack[top]);
    printf("%d is inserted\n", stack[top]);
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]); 
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter the operation you want to perform:\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: exit(0); 
            default: printf("Enter correct operation!\n");
        }
    }
    return 0;
}
