#include <stdio.h>
#include <stdlib.h>
#define max 5
int deque[max];
int front = -1;
int rear = -1;

void enquefront(){
    int ef;
    printf("\nEnter the value you want to enque from front: ");
    scanf("%d",&ef);
    if((front==0 && rear==max-1) || (front==rear+1)){
        printf("\nDEQueue is full");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        deque[front]=ef;
    }
    else if(front==0){
        front=max-1;
        deque[front]=ef;
    }
    else{
        front--;
        deque[front]=ef;
    }
}

void enquerear(){
    int er;
    printf("\nEnter the value you want to enque from rear: ");
    scanf("%d",&er);
    if((front==0 && rear==max-1) || (front==rear+1)){
        printf("\nDEQueue is full");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        deque[rear]=er;
    }
    else if(rear==max-1){
        rear=0;
        deque[rear]=er;
    }
    else{
        rear++;
        deque[rear]=er;
    }
}

void dequefront(){
    if(front==-1 && rear==-1){
        printf("\nDEQueue is empty");
    }
    else if(front==rear){
        printf("\nDeleted element is: %d",deque[front]);
        front=rear=-1;
    }
    else if(front==max-1){
        printf("\nDeleted element is: %d",deque[front]);
        front=0;
    }
    else{
        printf("\nDeleted element is: %d",deque[front]);
        front++;
    }
}

void dequerear(){
    if(front==-1 && rear==-1){
        printf("\nDEQueue is empty");
    }
    else if(front==rear){
        printf("\nDeleted element is: %d",deque[rear]);
        front=rear=-1;
    }
    else if(rear==0){
        printf("\nDeleted element is: %d",deque[rear]);
        rear=max-1;
    }
    else{
        printf("\nDeleted element is: %d",deque[rear]);
        rear--;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("\nDEQueue is empty");
    }
    else{
        printf("\nDEQueue elements: ");
        while(i!=rear){
            printf("%d ",deque[i]);
            i=(i+1)%max;
        }
        printf("%d",deque[rear]);
    }
}

int main(){
    int choice;
    while(1){
        printf("\n\n--- Double Ended Queue Menu ---");
        printf("\n1. Enqueue Front");
        printf("\n2. Enqueue Rear");
        printf("\n3. Dequeue Front");
        printf("\n4. Dequeue Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: enquefront(); break;
            case 2: enquerear(); break;
            case 3: dequefront(); break;
            case 4: dequerear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}