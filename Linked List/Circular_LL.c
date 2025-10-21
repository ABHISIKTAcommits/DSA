#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void createCLL()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void insertbegCLL()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
}
void insertendCLL()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}
void insertPosCLL()
{
    struct node *newnode, *temp;
    int pos, i = 1;
    printf("\nEnter the position at which you want to enter: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("\nInvalid position!");
        return;
    }
    if (pos == 1)
    {
        insertbegCLL();
        return;
    }
    if (head == NULL)
    {
        printf("\nList is empty! Can only insert at position 1.");
        return;
    }
    temp = head;
    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }

    if (i < pos - 1)
    {
        printf("\nPosition %d is beyond list length (current length: %d)", pos, i + 1);
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}
void delbegCLL()
{
    struct node *temp, *last;
    if (head == NULL)
    {
        printf("\nCLL is empty");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("\nFirst node deleted successfully");
}
void delendCLL()
{
    struct node *temp, *last;
    if (head == NULL)
    {
        printf("\nCLL is empty");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = last = head;
        while (temp->next != head)
        {
            last = temp;
            temp = temp->next;
        }
        last->next = head;
        free(temp);
    }
}
void delPosCLL()
{
    struct node *temp, *toDelete;
    int pos, i = 1;
    printf("\nEnter the position at which you want to delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("\nInvalid position!");
        return;
    }
    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    if (pos == 1)
    {
        delbegCLL();
        return;
    }
    temp = head;
    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == head || i < pos - 1)
    {
        printf("\nPosition %d is beyond list length", pos);
        return;
    }
    toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("\nNode at position %d deleted successfully", pos);
}
void displayCLL()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nCIRCULAR LL IS EMPTY.");
        return;
    }
    printf("\nPrinting the CLL: ");
    temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- CLL Operations ---\n");
        printf("1. Create Node\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createCLL();
            break;
        case 2:
            insertbegCLL();
            break;
        case 3:
            insertendCLL();
            break;
        case 4:
            insertPosCLL();
            break;
        case 5:
            delbegCLL();
            break;
        case 6:
            delendCLL();
            break;
        case 7:
            delPosCLL();
            break;
        case 8:
            displayCLL();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}