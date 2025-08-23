// Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays. [Day: 29]

#include <stdio.h>
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int remdup(int arr[], int n)
{
    sort(arr, n);
    if (n == 0)
        return 0;

    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];

    return j;
}
int main()
{
    int n1, n2;
    printf("Enter the 1st array size: ");
    scanf("%d", &n1);
    printf("Enter the 2nd array size: ");
    scanf("%d", &n2);

    int arr1[n1];
    int arr2[n2];
    printf("Enter the 1st array:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    printf("Enter the 2nd array:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    printf("1st Array entered by you is:\n");
    for (int i = 0; i < n1; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    printf("2nd Array entered by you is:\n");
    for (int i = 0; i < n2; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    int j = 0;
    int n3 = n1 + n2;
    int arr3[n3];
    for (int i = 0; i < n1; i++)
        arr3[j++] = arr1[i];
    for (int i = 0; i < n2; i++)
        arr3[j++] = arr2[i];
    int newSize = remdup(arr3, n3);

    printf("Union is:\n");
    for (int i = 0; i < newSize; i++)
        printf("%d ", arr3[i]);

    printf("\n");
}