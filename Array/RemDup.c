// Program to remove duplicate elements from an array in C [Day: 24]

#include <stdio.h>

void bubble(int arr[],int n){
    int swapped=0;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
            swapped=1;
        }
    }
    if(swapped==0) break;
}
}

int removeDuplicates(int arr[], int n){
    if (n == 0)
        return 0;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
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
        bubble(arr, n);
    int k = removeDuplicates(arr, n);
    printf("The array after removing duplicate elements is:\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}