// Given a non-empty array of integers arr, every element appears twice except for one. Find that single one. [Day: 32]

#include <stdio.h>
void single(int arr[], int n)
{
    int result;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                res++;
        }
        if (res == 1)
        {
            result = arr[i];
            break;
        }
    }
    printf("\nSingle occuring element is: %d", result);
}
int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nArray entered by you is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    single(arr, n);

    return 0;
}