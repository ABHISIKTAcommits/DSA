// Program to perform merge sort in C [Day: 14]
// time complexity - O(n log n)

#include <stdio.h>

// Merge two sorted halves into sorted array
void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int k = 0;
    // Store elements in sorted order
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
            temp[k++] = arr[right++];
    }
    // for elements in left part
    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }
    // for elements in right part
    while (right <= high)
    {
        temp[k++] = arr[right++];
    }
    // all elements taken in sorted order in original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void Ms(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (high + low) / 2;
    Ms(arr, low, mid);      // left part sort
    Ms(arr, mid + 1, high); // right part sort
    merge(arr, low, mid, high);
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
    Ms(arr, 0, n - 1);
    printf("value after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}