#include<stdio.h>
#include<stdlib.h>
# define max 5
int arr[max],top=-1;
int n ;
void push (){
if(top== max -1){
    printf("array is full : ");
}
else{
    printf("enter your data : ");
    scanf("%d",&n);
    top++;
    arr[top]=n;
}
}
void pop(){
    if(top == -1 ){
        printf("stack s empty nothing to pop");
    } else{
        printf("the poped element is %d",arr[top]);
        top--;

    }
}
void peek (){
    if(top ==-1){
        printf("statack is empty nothing to display ");
    }else{
        printf("the element is %d",arr[top]);
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
        for(i = 0; i <=top; i++)
        {
            printf("%d ", arr[i]);
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
