// Program to perform quick sort in C [Day: 16]
//Time Complexity: Best & Avg = O(n log n), Worst = O(n^2)

#include<stdio.h>

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int t=arr[low];
    arr[low]=arr[j];
    arr[j]=t;
    return j;
}
void quick(int arr[],int low, int high){
    if(low<high){
        int partitionIdx=partition(arr,low,high);
        quick(arr,low,partitionIdx-1);
        quick(arr,partitionIdx+1,high);
    }
}

int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    quick(arr,0,n-1);
    printf("value after sorting: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}