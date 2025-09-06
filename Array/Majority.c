// Given an array find the Majority Element that occurs more than N/2 times in c [Day: 39]

#include <stdio.h>

int main()
{
    int n;
    printf("enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Array entered by you is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    int max = -1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            max = arr[i];
            break;
        }
    }

    printf("\nMajority Element: %d\n", max);

    return 0;
}