// Given an array of integers nums, sort the array in non-decreasing order using the recursive Bubble Sort algorithm,
// and return the sorted array. [Day: 15]

#include <stdio.h>

void bubble(int arr[], int n)
{
    if (n == 1)
        return;
    int swapped = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int t = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = t;
            swapped = 1;
        }
    }
    if (swapped == 0)
        return;
    bubble(arr, n - 1);
}

int main()
{
    int n;
    printf("enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubble(arr, n);
    printf("value after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}