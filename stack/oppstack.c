#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX], top = -1;
void push(){
    if(top == MAX - 1)
    {
        printf("stack is full");
    }
    else
    {
        int n;
        printf("enter data ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}
void pop(){
    if(top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("deleted element is %d", stack[top]);
        top--;
    }
}
void peek(){
    if(top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("top element is %d", stack[top]);
    }
}

void display(){
    if(top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        int i;
        printf("stack elements are: ");
        for(i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("enter your choice ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("invalid choice");
        }
    }
}
