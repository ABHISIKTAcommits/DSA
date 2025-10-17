// Circular Queue using LinkedList [17-10-25]

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the number you want to enqueue into the queue: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\nCircular Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nCircular Queue is empty\n");
    }
    else
    {
        printf("\nFront element is: %d\n", front->data);
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\nCircular Queue is empty\n");
    }
    else
    {
        printf("\nDisplaying the queue\n");
        while (temp->next != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data); // last data temp->next==front to be printed separately
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nenter the operation you want to perform: \n1. Enqueue \n2. Dequeue \n3. peek \n4. Display \n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("enter correct operation!");
        }
    }
    return 0;
}