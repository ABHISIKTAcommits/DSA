// Program to reverse an array and print in C [Day: 21]
//time complexity: O(n)

#include<stdio.h>

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
    printf("Array entered by you is:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\nMaximum element in the array: %d",max);
}