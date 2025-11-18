// Maximum subarray sum - Kadane's Algorithm

// brute force
// #include<stdio.h>
// #include<stdlib.h>
// #include<limits.h> //for int_min
// int subs(int arr[],int n){
//     int min=INT_MIN;
//     for(int i=0;i<n;i++){
//         int subsum=0;
//        for(int j=i;j<n;j++){
//         subsum+=arr[j];
//         if(subsum > min) {
//                 min = subsum;
//             }
//         }
//     }
//     return min;
// }
// int main(){
//     int s;
//     printf("enter size of array: ");
//     scanf("%d",&s);
// int arr[s];
// printf("enter the array: ");
// for (int i=0;i<s;i++) scanf("%d",&arr[i]);
// printf("array is: ");
// for (int i=0;i<s;i++) printf("%d ",arr[i]);
// int res = subs(arr,s);
// printf("Max subarray is: ");
// printf("%d",res);
// }

// Optimal
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for int_min
int subs(int arr[], int n)
{
    int min = INT_MIN;
    int subsum = 0;
    for (int i = 0; i < n; i++)
    {
        subsum += arr[i];
        if (subsum > min)
            min = subsum;
        if (subsum < 0)
            subsum = 0;
    }
    return min;
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
    int res = subs(arr, s);
    printf("Max subarray is: ");
    printf("%d", res);
}