// Given an array and a sum k, we need to print the length of the longest subarray that sums to k. [Day: 33]

#include <stdio.h>

int main()
{
    int n, k;
    printf("Enter the array size: ");
    scanf("%d", &n);
    printf("Enter the sum: ");
    scanf("%d", &k);
    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nArray entered by you is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    int maxLen = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                int len = j - i + 1;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }
    printf("\nLength of longest subarray with sum %d is: %d\n", k, maxLen);

    return 0;
}