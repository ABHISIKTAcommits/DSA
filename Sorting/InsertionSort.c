// Program to perform insertion sort in C [Day: 13]
//time complexity - Best case [O(n)] - Worst case [O(n^2)]

#include<stdio.h>

void insertion(int arr[],int n){
for(int i=0;i<=n-1;i++){
    int j=i;
        while(j>0 && arr[j-1]>arr[j]) {
            int t=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=t;
            j--;
        }
    }
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