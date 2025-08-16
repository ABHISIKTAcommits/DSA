/*Given an array of integers nums, sort the array in non-decreasing order using the recursive Insertion Sort algorithm,
and return the sorted array.[Day: 15]*/

#include<stdio.h>

void insertion(int arr[],int n){
    if (n <= 1) return;
        insertion(arr,n-1);
int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    insertion(arr,n);
    printf("value after sorting: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}