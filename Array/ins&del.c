#include<stdio.h>
void ins(int s,int arr[],int ele,int pos){
    int i;
    for (i=s;i>=pos;i--)
        arr[i+1]=arr[i];
        arr[pos]=ele;
        s++;
printf("array ater insertion: ");
for (int i=0;i<s;i++) printf("%d",arr[i]);
}
void del(int s,int arr[],int pos){
for(int i=pos;i<s-1;i++){
    arr[i]=arr[i+1];
}
s--;
printf("array ater deel: ");
for (int i=0;i<s;i++) printf("%d",arr[i]);
}
int main(){
    int s;
    printf("enter size of array: ");
    scanf("%d",&s);
int arr[s];
printf("enter the array: ");
for (int i=0;i<s;i++) scanf("%d",&arr[i]);
printf("array is: ");
for (int i=0;i<s;i++) printf("%d",arr[i]);
int pos;
int ele;
printf("for insertion, enter position: ");
scanf("%d",&pos);
printf("enter ele: ");
scanf("%d",&ele);
ins(s,arr,ele,pos);
s++;
int pos1;
printf("for del, enter position: ");
scanf("%d",&pos1);
del(s,arr,pos1);
s--;
}
