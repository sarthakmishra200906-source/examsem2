#include<stdio.h>
#include<stdlib.h>
void enqueue(){

}
void dequeue(){

}

void peek(){

}
void display(){

}
int main()
{
    int choice;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
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