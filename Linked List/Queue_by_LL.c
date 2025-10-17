// Queue using Linked List [17-10-2025]

#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void insert();
void delete();
void display();

void insert()
{
    struct queue *temp;
    temp = (struct queue *)malloc(sizeof(struct queue));
    printf("\nenter the element to insert: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (front == NULL && rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void delete()
{ // deletion in a queue is always from front (FIFO)
    struct queue *p;
    if (front == NULL && rear == NULL)
        printf("\nQUEUE IS EMPTY");
    else
    {
        printf("\ndeleted element is: %d", front->data);
        p = front;
        front = front->next;
        free(p);
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

void display()
{
    struct queue *p;
    if (front == NULL && rear == NULL)
        printf("\nQUEUE IS EMPTY");
    else
    {
        p = front;
        printf("\nQUEUE IS: ");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nenter the operation you want to perform: \n1. Insertion \n2. Deletion \n3. Display \n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("enter correct operation!");
        }
    }
    return 0;
}