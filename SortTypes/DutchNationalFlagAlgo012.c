// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions in c [Day: 38]

#include <stdio.h>

void sortArr(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;

            low++;
            mid++;

        } else if (arr[mid] == 1) {
            mid++;

        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;

            high--;
        }
    }
}

int main() {
      int n;
    printf("enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\narray entered by you is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    sortArr(arr, n);

    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
