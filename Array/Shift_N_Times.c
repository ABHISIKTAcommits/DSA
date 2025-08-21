// Program to left rotate an array by N places in C [Day: 26]

#include <stdio.h>

void solve(int arr[], int n, int k, char dir)
{
    printf("updated array is: ");
    if (dir == 'l')
    {
        for (int i = k; i < n; i++)
            printf("%d", arr[i]);
        for (int j = 0; j < k; j++)
            printf("%d", arr[j]);
    }
    if (dir == 'r')
    {
        for (int i = k + 1; i < n; i++)
            printf("%d", arr[i]);
        for (int j = 0; j <= k; j++)
            printf("%d", arr[j]);
    }
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
    int k;
    char dir;
    printf("enter the number of times you want to shift the array: ");
    scanf("%d", &k);
    printf("enter the direction you want to shift the array (l for left/r for right): ");
    scanf(" %c", &dir);
    solve(arr, n, k, dir);
    return 0;
}