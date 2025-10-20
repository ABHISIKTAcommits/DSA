#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void create()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nENTER THE DATA YOU WANT TO ENTER: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
        head = tail = newnode;
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertbeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nENTER THE DATA YOU WANT TO ENTER AT BEGINNING: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertend()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nENTER THE DATA YOU WANT TO ENTER AT END: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (tail == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertatpos()
{
    int pos;
    int i = 1;
    printf("\nENTER THE POSITION YOU WANT TO INSERT THE NUMBER: ");
    scanf("%d", &pos);
    if (pos < 1)
        printf("\nINVALID POSITION");
    else if (pos == 1)
        insertbeg();
    else
    {
        struct node *newnode, *temp;
        temp = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nENTER THE ELEMENT YOU WANT TO INSERT: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        while (i < pos - 1)
        { // if insert after pos write i<pos (rest same)
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void delbeg()
{
    struct node *temp;
    if (head == NULL)
        printf("\n Doubly linkedlist is empty.");
    else
    {
        temp = head;
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        free(temp);
    }
}

void delend()
{
    struct node *temp;
    if (head == NULL)
        printf("\n Doubly linkedlist is empty.");
    else
    {
        temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        free(temp);
    }
}

void delfrompos()
{
    if (head == NULL)
    {
        printf("\nDoubly linked list is empty.");
        return;
    }
    struct node *temp;
    temp = head;
    int pos;
    int i = 1;
    printf("\nEnter the position from which you want to delete: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("\nInvalid position! Position must be >= 1.");
        return;
    }
    if (temp == NULL)
    {
        printf("\nPosition %d does not exist in the list.", pos);
        return;
    }
    if (temp == head && temp == tail)
    {
        head = tail = NULL;
    }
    else if (temp == head)
        delbeg();
    else if (temp == tail)
        delend();
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("\nNode deleted from position %d.", pos);
    }
}

void display()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, item, result;

    while (1)
    {
        printf("\n\n--- Doubly Linked List Operations ---\n");
        printf("1. Create Node\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Intermediate\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Intermediate\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertbeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            insertatpos();
            break;
        case 5:
            delbeg();
            break;
        case 6:
            delend();
            break;
        case 7:
            delfrompos();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}