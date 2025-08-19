// Program to check if an array is sorted (ascending order) in C [Day: 23]

#include<stdio.h>
int sort=1;
int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            sort=0;
            break;
        }
    }
    if(sort) printf("array is sorted");
    else printf("array is unsorted");
}