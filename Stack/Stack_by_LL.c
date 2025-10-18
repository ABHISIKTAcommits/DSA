// Stack using LinkedList in C [18-10-25]
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int x;
    printf("Enter the value to be pushed into stack: ");
    scanf("%d", &x);

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("%d pushed onto stack successfully!\n", x);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty - cannot pop!\n");
    }
    else
    {
        struct node *temp = top;
        int popped_value = top->data;
        top = top->next;
        free(temp);
        printf("%d popped from stack successfully!\n", popped_value);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is: %d\n", top->data);
    }
}

void display()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements (top to bottom): ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch;

    printf("=== Stack Implementation using Linked List ===\n");

    while (1)
    {
        printf("\nChoose operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}