// Program to move zeroes present in a number to the end in C (order must be maintained) [Day: 27]

#include <stdio.h>
void movee(int arr[], int n)
{
    int j = 0;
    int newarr[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            newarr[j++] = arr[i];
        }
    }
    while (j < n)
    {
        newarr[j++] = 0;
    }
    printf("\nUpdated array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d", newarr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("array entered by you is:\n");
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    movee(arr, n);
    return 0;
}