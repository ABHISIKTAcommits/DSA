// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
// Examples
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2] [Day: 35]


//type1

#include <stdio.h>
void count(int arr[],int n){
    int cz=0;
    int co=0;
    int ct=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0) cz++;
        else if(arr[i]==1) co++;
        else if(arr[i]==2) ct++;
    }
    for(int j=0;j<cz;j++){
arr[j]=0;
    }
    for (int j = cz; j < cz+co; j++) arr[j]=1;
    for (int j = cz+co; j < n; j++) arr[j]=2;
    printf("updated array is: ");
for(int i = 0; i < n; i++){
    printf("%d ",arr[i]);
}
}

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Array entered by you is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    count(arr, n);

    return 0;
}