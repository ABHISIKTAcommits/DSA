// Program to perform selection sort in C [Day: 11]
//Time Complexity O(n^2) for all best,avg and worst cases.
#include<stdio.h>

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
                int t=arr[min];
                arr[min]=arr[i];
                arr[i]=t;
    }
}

int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    selection(arr,n);
    printf("value after sorting: ");
    for(int i=0;i<n;i++) printf("%d",arr[i]);
}