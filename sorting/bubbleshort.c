#include<stdio.h>
void bubbleshort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    bubbleshort(arr,n);
    printf("sorted array is ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
