// Linked List in c [Day: 37]

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void create();
void insert_at_beg();
void insert_at_end();
void insert_at_intermediate();
void deletion_at_beg();
void deletion_at_end();
void deletion_at_intermediate();
int search(struct Node *head, int info);
void display();

void create() {
    struct Node *temp, *p;
    int item;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the item: ");
    scanf("%d", &item);
    temp->data = item;
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

void insert_at_beg() {
    struct Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
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
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void deletion_at_beg() {
    struct Node *p;
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        p = start;
        printf("Deleted element is %d\n", p->data);
        start = start->next;
        free(p);
    }
}

void deletion_at_end() {
    struct Node *p, *q;
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        p = start;
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        printf("Deleted element is %d\n", p->data);
        q->next = NULL;
        free(p);
    }
}

void deletion_at_intermediate() {
    struct Node *p, *q;
    int loc, i;
    printf("Enter location to delete: ");
    scanf("%d", &loc);

    p = start;
    for (i = 1; i < loc; i++) {
        q = p;
        p = p->next;
    }
    printf("Deleted item is %d\n", p->data);
    q->next = p->next;
    free(p);
}

int search(struct Node *head, int info) {
    while (head != NULL) {
        if (head->data == info) {
            return 1;
        }
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
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, val;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Intermediate\n");
        printf("5. Delete at Beginning\n6. Delete at End\n7. Delete at Intermediate\n");
        printf("8. Search\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: insert_at_beg(); break;
            case 3: insert_at_end(); break;
            case 4: insert_at_intermediate(); break;
            case 5: deletion_at_beg(); break;
            case 6: deletion_at_end(); break;
            case 7: deletion_at_intermediate(); break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &val);
                if (search(start, val) == 1)
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");
                break;
            case 9: display(); break;
            case 10: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
