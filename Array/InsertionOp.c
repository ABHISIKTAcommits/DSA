// Program to insert an element into an array [Day: 33]
#include <stdio.h>
void display(int arr[], int n)
{
    printf("\nUpdated array-- ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ins(int arr[], int n, int ele, int pos)
{
    if (pos < 0)
    {
        printf("underflow");
        return;
    }
    if (pos > n)
    {
        printf("overflow");
        return;
    }
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = ele;
}
int main()
{
    int n, ele;
    int pos = 0;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the element to be inserted: ");
    scanf("%d", &ele);
    printf("Enter the position at which you want to insert the element: ");
    scanf("%d", &pos);

    printf("\nArray entered by you is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    ins(arr, n, ele, pos);
    display(arr, n);

    return 0;
}