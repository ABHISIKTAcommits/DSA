// Queue using array in c [Day: 36]
#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max];
int front = -1;
int rear = -1;
void insertion()
{
    int ele;
    if (rear == max - 1)
    {
        printf("overflow");
        return;
    }
    if (front == -1)
        front = 0;
    printf("enter the element to insert: ");
    scanf("%d", &ele);
    rear += 1;
    arr[rear] = ele;
    printf("inserted element is: %d", ele);
}
void deletion()
{
    if (front == -1 || front > rear)
    {
        printf("underflow");
        return;
    }
    printf("deleted element is %d", arr[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("underflow");
        return;
    }
    printf("array is: ");
    for (int i = front; i <= rear; i++)
        printf("%d", arr[i]);
}
int main()
{
    int ch;
    printf("enter the operation you want to perform: \n1. Insertion \n2.Deletion \n3.Display");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        insertion();
        break;
    case 2:
        deletion();
        break;
    case 3:
        display();
        break;
    default:
        printf("enter correct operation!");
    }
    return 0;
}