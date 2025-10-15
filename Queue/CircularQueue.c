// CIRCULAR QUEUE [15-10-2025]
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("\nQueue is Full!");
    } 
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } 
    else {
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
    printf("\n%d enqueued successfully.", value);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is Empty!");
    } 
    else if (front == rear) {
        printf("\nDequeued element: %d", queue[front]);
        front = rear = -1;
    } 
    else {
        printf("\nDequeued element: %d", queue[front]);
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is Empty!");
        return;
    }
    printf("\nQueue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n\n--- Circular Queue Menu ---");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
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
