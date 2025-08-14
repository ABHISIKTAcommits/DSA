// Program to perform bubble sort in C [Day: 12]

#include<stdio.h>

void bubble(int arr[],int n){
    int swapped=0;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t;
            swapped=1;
        }
    }
    if(swapped==0) break;
}
}
int main(){
    int n;
    printf("enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    bubble(arr,n);
    printf("value after sorting: ");
    for(int i=0;i<n;i++) printf("%d",arr[i]);
}