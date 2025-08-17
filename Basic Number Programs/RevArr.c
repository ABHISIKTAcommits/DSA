// Program to reverse an array and print in C [Day: 20]

#include <stdio.h>

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printReverse(int arr[], int size) {
    printf("Reversed array elements: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {7, 8, 9, 2, 7};

    printArray(arr, 5);
    printReverse(arr, 5);

    return 0;
}
