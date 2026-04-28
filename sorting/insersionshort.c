#include<stdio.h>
void insersionshort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0&&arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
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
    printf("enter array elements ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insersionshort(arr,n);
    printf("sorted array is ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}