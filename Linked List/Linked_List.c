// Write a program to implement Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;
void create();
void insert_at_beg();
void insert_at_end();
void insert_at_intermediate();
void deletion_at_beg();
void deletion_at_end();
void deletion_at_intermediate();
int search(struct Node*, int);
void display();

void create() {
    struct Node *temp, *p;
    int item;

    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &item);
    temp->data = item;
    temp->next = NULL;

    if (start == NULL)
        start = temp;
    else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void insert_at_beg() {
    struct Node* temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL)
        start = temp;
    else {
        temp->next = start;
        start = temp;
    }
}

void insert_at_end() {
    struct Node *temp, *p;
    temp = (struct Node*) malloc(sizeof(struct Node));

    printf("Enter the element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void insert_at_intermediate() {
    struct Node *temp, *p;
    int loc, i;

    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    printf("After which node you want to insert: ");
    scanf("%d", &loc);

    p = start;
    for (i = 1; i < loc; i++) {
        if (p == NULL) {
            printf("Invalid position!\n");
            free(temp);
            return;
        }
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;
}

void deletion_at_beg() {
    struct Node *p;

    if (start == NULL)
        printf("Linked list is empty\n");
    else {
        p = start;
        printf("Deleted element is %d\n", p->data);
        start = start->next;
        free(p);
    }
}

void deletion_at_end() {
    struct Node *p, *q;
    if (start == NULL)
        printf("Linked list is empty\n");
    else {
        q = NULL;
        p = start;
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        printf("Deleted element is %d\n", p->data);
        if (q != NULL)
            q->next = NULL;
        else
            start = NULL;
        free(p);
    }
}

void deletion_at_intermediate() {
    struct Node *p, *q;
    int loc, i;
    printf("Enter position to delete: ");
    scanf("%d", &loc);
    
    if (start == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    
    p = start;
    q = NULL;
    for (i = 1; i < loc; i++) {
        if (p == NULL) {
            printf("Invalid position!\n");
            return;
        }
        q = p;
        p = p->next;
    }
    
    if (p == NULL) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Deleted item is %d\n", p->data);
    if (q == NULL) {
        start = p->next;
    } else {
        q->next = p->next;
    }
    free(p);
}

int search(struct Node* head, int info) {
    while (head != NULL) {
        if (head->data == info)
            return 1;
        head = head->next;
    }
    return -1;
}

void display() {
    struct Node *ptr;
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        ptr = start;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, item, result;
    
    while(1) {
        printf("\n\n--- Linked List Operations ---\n");
        printf("1. Create Node\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Intermediate\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Intermediate\n");
        printf("8. Search\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                insert_at_beg();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                insert_at_intermediate();
                break;
            case 5:
                deletion_at_beg();
                break;
            case 6:
                deletion_at_end();
                break;
            case 7:
                deletion_at_intermediate();
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &item);
                result = search(start, item);
                if(result == 1)
                    printf("Element found in the list\n");
                else
                    printf("Element not found in the list\n");
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}