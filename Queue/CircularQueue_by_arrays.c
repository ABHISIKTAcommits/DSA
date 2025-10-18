#include <stdio.h>
#include <stdlib.h>
#define max 5
int queue[max];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    printf("enter the data: ");
    scanf("%d", &x);
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if (((rear + 1) % max) == front)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = x;
    }
}

void dequeue(){
    if (front == -1 && rear == -1)
    {
         printf("\nQueue is empty\n");
    }
    else if(front==rear){
        printf("\nDeleted element is: %d",queue[front]);
        front=rear=-1;
    }
    else{
        printf("\nDeleted element is: %d",queue[front]);
        front=(front+1)%max;
    }
}

void display(){
    int i=front;
    if (front == -1 && rear == -1)
    {
         printf("\nQueue is empty\n");
    }
    else{
        printf("\ndisplaying the queue: \n");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%max;
        }
        printf("%d",queue[rear]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\n--- Circular Queue Menu ---");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}