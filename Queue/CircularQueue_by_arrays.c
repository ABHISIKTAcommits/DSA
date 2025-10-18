//Circular Queue using Arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull()
{
    return ((rear + 1) % MAX) == front;
}

int isEmpty()
{
    return front == -1 && rear == -1;
}

void enqueue()
{
    int x;
    printf("Enter the data: ");
    scanf("%d", &x);

    if (isEmpty())
    {
        front = rear = 0;
        queue[rear] = x;
        printf("Element %d enqueued successfully\n", x);
    }
    else if (isFull())
    {
        printf("\nQueue is full! Cannot enqueue %d\n", x);
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
        printf("Element %d enqueued successfully\n", x);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue is empty! Cannot dequeue\n");
    }
    else if (front == rear)
    {
        printf("\nDeleted element is: %d", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDeleted element is: %d", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue elements: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d", queue[rear]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n--- Circular Queue Menu ---");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting program...\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}