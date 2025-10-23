#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int sparse[MAX][3];
int rows, cols, count = 0;

void create() {
    int i, j, val;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of matrix (%d x %d):\n", rows, cols);
    count = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &val);
            if (val != 0) {
                sparse[count + 1][0] = i;
                sparse[count + 1][1] = j;
                sparse[count + 1][2] = val;
                count++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;

    printf("\nSparse matrix is created successfully!\n");
}

void display() {
    int i, j;
    if (count == 0) {
        printf("\nSparse matrix is empty!\n");
        return;
    }

    printf("\nSparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= count; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Sparse Matrix\n");
        printf("2. Display Sparse Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
