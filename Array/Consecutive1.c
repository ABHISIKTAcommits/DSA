// Take an array input from the user, return the maximum number of consecutive 1s in the array [Day: 31]

#include <stdio.h>

void consecutive(int arr[], int n)
{
    int cnt = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            if (cnt > maxi)
            {
                maxi = cnt;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    printf("\nMaximum number of consecutive 1s: %d\n", maxi);
}

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements (0s and 1s):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nArray entered by you is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    consecutive(arr, n);

    return 0;
}
