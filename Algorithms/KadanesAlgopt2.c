//Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for int_min
void subs(int arr[], int n)
{
    int min = INT_MIN;
    int subsum = 0;
    int start=-1;
    int end=-1;
    for (int i = 0; i < n; i++)
    {
        if(subsum==0) start=i;
        subsum += arr[i];
        if (subsum > min)
            min = subsum;
            start=start;
            end=i;
        if (subsum < 0)
            subsum = 0;
    }
    printf("Largest sum is: %d",min);
    printf("Maximum subarray is: ");
    for (int i = start; i < end; i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
    int s;
    printf("enter size of array: ");
    scanf("%d", &s);
    int arr[s];
    printf("enter the array: ");
    for (int i = 0; i < s; i++)
        scanf("%d", &arr[i]);
    printf("array is: ");
    for (int i = 0; i < s; i++)
        printf("%d ", arr[i]);
    subs(arr, s);
}