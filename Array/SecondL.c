// Program to find the second largest element and print in C [Day: 22]
//time complexity: O(2n)

#include<stdio.h>
#include <limits.h>
int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int sl=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>sl && arr[i]!=max){
            sl=arr[i];
        }
    }
    printf("Array entered by you is:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\nSecond Largest element in the array: %d",sl);
}