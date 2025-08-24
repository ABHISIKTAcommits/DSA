// Take an array input from the user, find the missing element in the array. [Day: 30]

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

void compare(int arr[], int n)
{
    sort(arr, n);
    printf("\nSorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    int last = arr[n - 1];
    int temp = 0;
    int newarr[last];
    for (int i = 0; i < last; i++)
    {
        temp++;
        newarr[i] = temp;
    }
    printf("\nMissing elements are: ");
    int j = 0;
    for (int k = 0; k < last; k++)
    {
        if (j < n && arr[j] == newarr[k])
        {
            j++;
        }
        else
        {
            printf("%d ", newarr[k]);
        }
    }
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
    printf("\narray entered by you is:");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    compare(arr, n);
    return 0;
}