/*#include <stdio.h>
#include <stdlib.h>

#define MAX 32 

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int isEmpty() {
    return top == -1;
}

void decimalToBinary(int num) {
    // Handle the 0 edge case
    if (num == 0) {
        printf("0");
        return;
    }

    // Divide by 2 and push remainders
    while (num > 0) {
        push(num % 2);
        num = num / 2;
    }

    // Pop from stack to print binary
    printf("Binary equivalent: ");
    while (!isEmpty()) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    decimalToBinary(decimal);
    
    return 0;
}*/
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