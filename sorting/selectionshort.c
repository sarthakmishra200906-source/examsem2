#include<stdio.h>
int selectionshort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
}
int main(){
    int n;
    printf("enter size of array ");
    scanf("%d",&n);
    if(n<=0){
        printf("invalid size\n");
        return 1;
    }
    int arr[n];
    printf("enter elements of array ");
    for(int i=0;i<n;i++){
        printf("enter element %d ",i+1);
        scanf("%d",&arr[i]);
    }
    selectionshort(arr,n);
    printf("sorted array is ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}