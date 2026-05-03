#include <stdio.h>
#include <stdlib.h>
# define max 32
int stack[max];
int top=-1;
void convertdectobin(int num){
    if(num==0){
        printf("0");
        return;
    }
    while(num>0){
        stack[++top]=num%2;
        num=num/2;
    }
    printf("binary equivalent : ");
    while(top>=0){
        if(top==-1){
            printf("stack is empty");
            return;
        }
        printf("%d",stack[top--]);
    }
    printf("\n");
   
}
int main(){
    int decimal;
    printf("enter a decimal number : ");
    scanf("%d",&decimal);
    convertdectobin(decimal);
    return 0;
}